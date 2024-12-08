//*CID://+vbzRR~:                             update#=  344;       //~vbzRR~
//*************************************************************
//*xefunct.c                                                       //~v663R~
//* func definition tbl                                         //~5216R~
//************************************************************* //~v020I~
//vbzR:240414 C+h is backspace but use as hcopy                    //~vbzRI~
//vbzP:240412 (LNXCON)support hardcopy function(also change key C+h-->A+z)//~vbzPI~
//vbzJ:240403 appendmode screen print to ::hp by Ctrl+h (hardcopy) //~vbvJI~
//vbvt:221202 =0.2/=0.3 display code itself for default box char for japanese//~vbvtI~
//vbvc:221125 functbl search miss to search english linechar because same funcid//~vbvcI~
//vbs6:201026 profile COL cmd for dir
//vbra:200730 (ARM)ARM input is always utf8, delete A_u and UTF SWKBD//~vbraI~
//vbi6:180219 R-Retrieve-OfTheScr was not assigned key, use S+A+F12//~vbi6I~
//vbi5:180219 correct word of functbl, Regin-->Region,accept both for ini read//~vbi5I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vbi1:180210 it is used on ini file,abondon vbi0                  //~vbi1I~
//vbi0:180210 correct word of functbl, Regin-->Region              //~vbi0I~
//vbe0:171231 add function to search xml tag pair by A+/           //~vbe0I~
//vbds:171203 (BUG)FTFDUPACMDFUNC=FTFCMDONLY=0x40-->ini file error msg//~vbdsI~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//vb96:170305 regist cmd for A+";"=LIG, A+":"=CMB(that key combination is not effective on Axe usb kbd)//~vb96I~
//vb53:160903 add A+PGDN/A+PGUP to end_of_file and top_of_file     //~vb53R~
//vb51:160827 (Bug)funct description have not to be space embedding(ini file proc err)//~vb51I~
//vbCC:160825 (Bug)F5 with operand is missing chk INX cmd verb     //~vbCCI~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaun:140313 C+W(copy word to cmdline) support for dir list       //~vaunI~
//vagk:120825 Redo:C+F1 is not avail on Linux(reported as gnome-terminal BUG), so change to C+F2//~vagkI~
//vag2:120811 REDo suupport                                        //~vag2I~
//vac2:120204 (SMB)target:windows consideration                    //~vac2I~
//vac0:120131 (SMB)node cmd to set volatile password to UFTPHOST   //~vac0I~
//va7K:100904 add RESET option to cv cmd B2B(change UFHhandle) and CP option to EBC cmd.//~va7KI~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va30:100126 combine mode of diacritical marks by A+/             //~va30I~
//va1J:091119 (BUG)AIX122 comilation err                           //~va1JI~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v9@1:080716 3270:cmd assing to 3270hotkey                        //~v9@1I~
//v8@S:080710 3270:change hotkey A+F1 to A+z for linux             //~v8@SR~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v78G:080503*add aloas 'FLIp' to XX cmd                           //~v78GI~
//v78r:080326 profile function                                     //~v78rI~
//v785:080229 (LNX:BUG)on curses version, Ctrl+[ is trated as 011b,//~v785I~
//            and Alt+{|} (A+S+[|]) is same as A+[|] 1b00/2b00.    //~v785I~
//            so chk Shift bit at function of A+[|]                //~v785I~
//v783:080227 CUT/PASTE cmd to use another clipboard(save/restore each time)//~v783I~
//v780:080212 syntaxhighlight support                              //~v780I~
//v77F:080204 C+W copy to cmdline(No cmd verb)                     //~v77FI~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support(word means simple space delm)//~v77EI~
//v77C:080129*english spell chk                                    //~v77CI~
//v776:071130*change key assignment foor jump hex from Ctrl+Tab to A+g because Linux do'nt detect C+Tab//~v776I~
//v773:070627 find support on =1/=2 filename list panel            //~v773R~
//v76i:070622 more(key by key) allowance for duplicated function key assignment//~v76iI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75S:070520 Linux compiler warning                               //~v75SI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v75D:070503 (BUG)more about v75A:missing FTCTLC definition for C+vFTCTLC,//~v75DI~
//            so opt ccfunc OFF is ineffective but inirfunc set FTCTLC flag when read inifile.//~v75DI~
//            If no ini file,C_v is always std-paste.              //~v75DI~
//v755:070418 add TFLOW cmd                                        //~v755I~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v742:070207 assign A/C+F10 to display description on dirlist(S+F10 is intercepted by Linux)//~v742I~
//v72Q:061214 allow to asign func-key to submit                    //~v72QI~
//v72P:061214 add ic cmd(case insensitive change)                  //~v72PI~
//v72c:061122 (BUG)S+F6 dup assigned err msg for GCC version under windows//~v72cI~
//v71Q:061107 functbl search faile when key change save if line-draw char string defined//~v71QI~
//v71P:061107 enable cmd verb change on =0.2 panel                 //~v71PI~
//v70z:060904 3270 ftp support(hostfile,TSO command)               //~v70zI~
//v705:060727 graphic char setup by external file(2 string for opt linech on/off)//~v705I~
//v69J:060712 cap(CAPS LOCK On) support                            //~v69JI~
//v69A:060609 (LNX:BUG)keyname euc conversion process should be done before before functable init//~v69AI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v67M:060206 os/2 compile err by v679                             //~v67MI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v679:051227 (BUG)MSG:ini file err issued for not supported OS(ex. xxe support AT cmd but lnx not)//~v679I~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v66e:051020 support standard mode cut & paste;                   //~v66eI~
//            A+F6/A+v:range specification, A+F9:copy, A+Ins:paste Ins, A+F8:paste Rep, C+v:paste Del then Ins//~v66eI~
//            Del/BackSpace:delete range, A+Del:del+copy to clipboard//~v66eI~
//v663:050816 change sbreviation of AT cmd,assign & to SPAWN       //~v663I~
//v651:050712 (XXE)xxe support;AT cmd,sleep cmd                    //~v64vR~
//v64v:050708 (LNX)openwith support(! lcmd & ASS cmd)              //~v64vI~
//v64u:050706 (BUG)0x18 input by Ctl+x is not avail even if "OPT CCFUNC OFF"//~v64uI~
//v61t:050306 (LNX:BUG by v61j)funcname sjis->sbc change beyond name field by dup conv(hankaku expand),//~v61tR~
//v61d:050222 support pgtop/pglast for filename list               //~v61dI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v592:041031 rsh cmd support                                      //~v592I~
//v57j:040522 sort cmd for dirlist                                 //~v57jI~
//v564:040328 (WIN)ASSociate command same as ! lcmd                //~v564I~
//v562:040325 (WIN)AT cmd support                                  //~v562I~
//v55Y:040324 (WIN)Sleep cmd for multicmd                          //~v55YI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55N:040318 linetop & lineend for dirlist                        //~v55NI~
//v55n:040218 EXE cmd(execute xe command file)                     //~v55nI~
//v55k:040215 (LNX)uerrmsg parm of functbl err should be sjis funcname//~v55kI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~v55jI~
//v55i:040214 add cmd string "LFN" to S_F11                        //~v55iI~
//v55h:040214 (FTP)uid/gid display for remote file                 //~v55hI~
//v558:040204 new func:path up/down by A+left/right                //~v558I~
//v557:040203 filename list multi-page support                     //~v557I~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v527:030819 allow both Alt+ and Ctrl+ for cut paste because dtterm dosenot refrect to Ctrl+Ins//~v527I~
//v51E:030721 key assign chng;Alt+fn-->Ctl+Fn for compatibility for LNX//~v51EI~
//v511:030302 new rotate cmd                                       //~v511I~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v50m:030102 accept tab cmd on any screen                         //~v50mI~
//v504:021006 accept ren cmd as "num reset" on edit scr            //~v504I~
//v503:021006 accept del cmd as drop on edit scr                   //~v503I~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~v48fI~
//v47W:020413 ueucchk interface changed(len chnage consideration by hankaku^katakana)//~v47WI~
//v47U:020407 cv cmd(euc<-->sjis)                                  //~v47UI~
//v47n:020310 exchange key a-f12 and a-f11;a-f12=repeat cmd,a-f11=hex input//~v47nI~
//v47k:020309 support cmd repeat key(alt+F11)                      //~v47kI~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v45s:011215 (AIX)display hex digit of linechar on 0.2            //~v45sI~
//v45p:011212 assign C+P0(=ins) and C+.(=Del) keisen char "-" and "|"//~v45pI~
//v45o:011212 (BUG)UNIX English mode,invalid graphic char;DOS use same as EUC//~v45oI~
//                 (NO single byte graphic char under kon)         //~v45oI~
//v44u:011206 (UNX) func japanesename conv to euc for ini file     //~v44uI~
//v44s:011206 cobol id back to "C",allow "L" as alias(see v44h)    //~v44sI~
//v44r:011206 back english funcid to old to avoid ini file err,    //~v44rI~
//            because it is key of ini file                        //~v44rI~
//v44h:011204 cobol naming chng                                    //~v44hI~
//v44e:011203 use not x but h for hex display                      //~v44eI~
//v440:011125 browse hex                                           //~v440I~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v42yI~
//v42w:010929 pair-parenthesis search  by alt+, except excluded line//~v42wI~
//v42h:010929 pair-parenthesis search  by alt+.                    //~v42hI~
//v41k:010820 add XR command(reverse excluded line)                //~v41kI~
//v415:010728 change BC --> XBC(basic calc)                        //~v415I~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v21j:010113 LINUX support:english keisen code change for curses acs//~v21jI~
//v21b:010203 LINUX support:key assign chnage S+F11:guage(edit),longfilename(dir)//~v21bI~
//v215:001126 LINUX support:back to use A+Fn etc excep A+F2;       //~v215I~
//            Because C+Ins is same as C+0                         //~v215I~
//v20h:001003 LINUX support(F6:size,S+F6:uid and username toggle)  //~v20hI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v20fI~
//v20e:001001 LINUX support(BUG of v20c:C+End is same value as Pad1;it's cause duplication//~v20eI~
//            Home,Pgup,Pgdn is also same as Pad key)              //~v20eI~
//v20d:001001 LINUX support(more after v20c;for Enter,A+Enter catched by Win95//~v20dI~
//            for fullscreen<-->windows change)                    //~v20dI~
//v20c:001001 LINUX support(more after v20b;for Ins,Del,End)       //~v20cI~
//v20b:001001 LINUX support(default change A+Fn-->Ctl+Fn)          //~v20bI~
//v182:001209 long filename display on dirlist(over attr fld)      //~v182I~
//v17f:000501 change TCN to TC and NX option.                      //~v17fI~
//v155:000318 numeric calc func                                    //~v155I~
//v152:000311 dir-list REFresh cmd                                 //~v152I~
//v13b:991023 (BUG)abend by concat cmd "can ; dir *.c".pcw is freed bu can.//~v13bI~
//            func_cmd access the pcw by setflddata.               //~v13bI~
//v11S:990904 Alt+F2 to COLS                                       //~v11NI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v10M:990424 support cap to cmdline                               //~v10LI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10I:990417 sort cmd                                             //~v10II~
//v10G:990417 EB/BB/SB for "e /mx","b /mx","s /mb"                 //~v10GI~
//v10n:990324 Find/Ifind NX (FNX/INX) cmd;search not excluded line only//~v10nI~
//v101:981205 hex input                                            //~v101I~
//v0k4:981128 SUBmit cmd                                           //~v0k4I~
//v0jp:980723 cmd verb for enter;"ENT"                             //~v0jpI~
//v0jn:980723 KEY cmd                                              //~v0jnI~
//v0jm:980723 INS cmd(operand=ON/OFF)                              //~v0jmI~
//v0jk:980723 add HOMe cmd                                         //~v0jkI~
//v0jd:980722 fix ctrl+2(null char),drop from ini and assign chng screen//~v0jdI~
//v0j6:980720 GCC warning                                          //~v0j2I~
//v0j2:980720 POS cmd for fn-cmd key                               //~v0j2I~
//v0iy:980718 fix assign Home key                                  //~v0iyI~
//v0is:980705 change max key number assign to func 8 to 4          //~v0isI~
//v0ir:980702 (BUG)func name "Reset" contain space "Reset   "(search err)//~v0irI~
//v0in:980625 (BUG)func name spell err                             //~v0inI~
//v0ie:980607 Locate cmd for disrlist                              //~v0ieI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v0hP:980428 I changed mind,abondon DEL x all,use DRo  only.      //~v0hPI~
//v0hz:980412 EXCLUDE/IEXCLUDE cmd support                         //~v0hzI~
//v0hu:980410 DEL cmd on edit screen(same as DROP)                 //~v0huI~
//v0hq:980316 add LDL cmd(del line XON/XOFF)                       //~v0hqI~
//v0hm:980215 pend/err lcmd reset by double Esc or typed RESET     //~v0hmI~
//v0he:980130 cap save operation for paste after end/cancel(Alt+f9)//~v0heI~
//v0cr:970814 NUM VER subcmd --> VER cmd                           //~v0crI~
//v0a2:970705:allow 00 input                                       //~v0a2I~
//            ext_key NULL(ctrl+2) definition                      //~v0a2I~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v08w:961208:key default assign change for f7=pgup f8=pgdn like spf//~v08wI~
//v085:961024:W95 VC                                               //~v085I~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//v07a:960615:color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//v06O:960427:drop Shift+F7 from line mark                         //~v06OR~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -add alt+e to block clear                          //~v06lI~
//           -alt+i/j/k to line insert mode copy/move/null move //~v06lI~
//           -change alt+l --> alt+h for line mark              //~v06lI~
//           -change copy/move/null move is insert mode only,   //~v06lI~
//			  so join alt+c	to alt+Ins                          //~v06lI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//v06g:960310:Alt+c for copy ins/rep by Ins mode                //~v06gI~
//v06f:960309:change paste key Alt+o-->Alt+p,add Alt+o as override//~v06fI~
//v06e:960309:for num off case,add line mark(Alt+l) and posision mark(Alt+a)//~v06eI~
//v069:960224:linenosz changeable for edit/browse(register func_number)//~v069I~
//v05B:960104:Option commnad                                    //~v05BI~
//v05w:951203:find cmd for dir list                             //~v05wI~
//v05p:951126:COPY/MOVE command under except edit/browse screen //~v05pI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v033:950715:SCROLL cmd for dir list scroll                   //~v033I~
//*v030:950709:dir pgup/pgdn/filetop/fileend/lineup/linedown share with file//~v030I~
//*v020:950611:dir support                                      //~v020I~
//************************************************************* //~5216I~
//*950527 no cdm assign to prev/next cmd retrieve(cancatinated cmd)//~5528I~
//*950429 ini process                                           //~5429I~
//*950215 tbl module                                            //~5216R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//**************************************************************
#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v085I~
#endif
//*******************************************************
#include <uque.h>                                               //~5216I~
#include <ulib.h>                                               //~5216I~
#include <uerr.h>                                               //~5424I~
#include <ualloc.h>                                             //~v04dI~
#include <ufile.h>                                              //~v05pI~
#include <udbcschk.h>                                              //~v44uI~
#include <ustring.h>                                               //~v61tI~
#include <uftp.h>                                                  //~vac2I~
#include <utrace.h>                                                //~vbvcI~
                                                                //~v05pI~
#include "xe.h"                                                 //~5216R~
#include "xescr.h"                                              //~5216I~
#include "xefunc.h"                                             //~5216I~
                                                                   //~v705I~
#define GLOBAL_FUNCT                                               //~v705I~
#include "xefunct.h"                                            //~5216I~
                                                                   //~v705I~
#include "xekbd.h"                                              //~5216I~
#include "xefile.h"                                             //~v05pR~
#include "xedir.h"                                              //~v05pI~
#include "xedcmd.h"                                             //~v05pI~
#include "xedcmd2.h"                                               //~vbvJI~
//**************************************************
//#define USE_ALT                                                  //~v51ER~
#define USE_CTL                                                    //~v51EI~
#ifdef  USE_ALT              //default use alt+Fn                  //~v20bI~
	#define ALT_CTL(fn)  KEY_A_##fn                                //~v20bI~
#else                        //default use ctl+Fn                  //~v20bI~
	#define ALT_CTL(fn)  KEY_C_##fn                                //~v20bI~
#endif                                                             //~v20bI~
#define NULL_FTKEY   		{0,0,0,0}                              //~v55nI~
#define NULL_FTKFLAG  		{0,0,0,0}                              //~v55nI~
//#define NULL_LAST           0,0                                  //~v71PR~
//#define NULL_LAST           0,0,0,{0}      //dupnext,dupprev,flag2,rsv//~v76gR~
//#define NULL_LAST               0,{0}      //dupnext,dupprev,flag2,rsv//~v76iI~//~vbvtR~
#define NULL_LAST               0,0,{0}      //flag2,flag3,rsv     //~vbvtI~
#define NULL_CMDONLY        NULL_FTKEY,NULL_FTKFLAG,NULL_LAST      //~v55nI~
//#define NULL_CMDONLY2(flag) NULL_FTKEY,NULL_FTKFLAG,0,0,(flag),{0}//~v76gR~
//#define NULL_CMDONLY2(flag) NULL_FTKEY,NULL_FTKFLAG,    (flag),{0} //~v76iI~//~vbvtR~
#define NULL_CMDONLY2(flag) NULL_FTKEY,NULL_FTKFLAG,    (flag),0,{0} //flag2,glag3,rsv[2]//~vbvtI~
#define NULL_NOFLAG                    NULL_FTKFLAG,NULL_LAST      //~v55nI~
//#define NULL_NOFLAG2(flag)            NULL_FTKFLAG,     (flag),{0} //FTkflag[],FTflag2,FTrsv[3]//~vbCBI~//~vbvtR~
#define NULL_NOFLAG2(flag)            NULL_FTKFLAG,     (flag),0,{0} //FTkflag[],FTflag2,flag3,FTrsv[2]//~vbvtI~
#define NULL_FLAG2(flag2)             (flag2),0,{0} //FTflag2,flag3,FTrsv[2]//~vbvtI~
#define CAPRGN_OLD "Regin-Start/End"                               //~vbi5I~
#define CAPRGN_NEW "Region-Start/End"                              //~vbi5I~
//*********************************************************        //~v679I~
	FTFUNC func_nosupport;                                         //~v679I~
//*********************************************************
//* key function declare
//*********************************************************
//key function
//*func key   process function
static int Smallocsw;                                           //~5429R~
static FUNCTBL  Sfunctbldefault[]=                              //~5429I~
{
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //~5506I~
//!! KEY_ENTER must be fixed to  /Yr can move it to nextline    //~5506I~
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //~5506I~
	{"Execute+Next-Line","���s+���s",                              //~v0inR~
        FUNCID_EXECNL,                                          //~5205R~
        0,0,          //flag,char,                              //~v06eR~
		{func_exec_pan,func_exec_pan,func_exec_pan},               //~v44uR~
		"ENT","",                                                  //~v0jpR~
		{KEY_PENTR 	,KEY_ENTER,0,0},                               //~v0isR~
//  	{FTFIX,FTFIX,0,0},0,0},                                    //~v71PR~
    	{FTFIX,FTFIX,0,0},                                         //~v71PI~
//         0,0,                                                    //~v76gR~
         FTF2FIXEDVERB,                                            //~v71PI~
//       {0}},                                                     //~v71PR~//~vbvtR~
         0,{0}},                                                   //~vbvtI~
	{"Next-Line"    ,"���s"          ,                          //~5429R~
        FUNCID_NEXTLINE,                                        //~5205M~
        0,0,          //flag,char,                              //~v06eR~
		{func_nextline,func_nextline,func_nextline},              //~v020R~
		"","",                                                  //~5205M~
//  	KEY_A_ENTER},                                              //~v20dR~
//  	ALT_CTL(ENTER)},                                           //~v51ER~
    	{KEY_C_PENTR,0,0,0      },NULL_NOFLAG},                    //~v55nR~
	{"Reset","���"     ,                                          //~v0irR~
        FUNCID_RESET,                                           //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_reset,func_reset,func_reset},                        //~v75SR~
//  	"","",                                                     //~v0hmR~
    	"RES","",                                                  //~v0hmI~
		{KEY_ESC    	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Insert-Toggle","�}��/�u��"     ,                          //~5429R~
        FUNCID_INS,                                             //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_ins,func_ins,func_ins},                              //~v75SR~
		"INS","",                                                  //~v0jmR~
		{KEY_INS    	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Cursor-Right/Down","����/�c��"     ,                      //~5503R~
        FUNCID_CSRSTEP,                                         //~5225I~
        0,0,          //flag,char,                              //~v06eR~
		{func_csrstep,func_csrstep,func_csrstep},                  //~v75SR~
		"CSD","",                                               //~5225R~
		{KEY_A_BS   	,0,0,0},                                   //~v0isR~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v76gR~
	{"HEX-input-on/off","HEX���̓I��/�I�t"     ,                   //~v101I~
        FUNCID_HEXINPUT,                                           //~v101I~
        0,0,          //flag,char,                                 //~v101I~
//  	{0,func_hexinput,0},                                       //~va3KR~
    	{func_hexinput,func_hexinput,func_hexinput},               //~va3KI~
//  	"HEX","",                                                  //~v60vR~
    	"XIN","",                                                  //~v60vR~
//		{KEY_A_F12  	,0,0,0},                                   //~v20bR~
//		{ALT_CTL(F12)  	,0,0,0},                                   //~v47nR~
  		{ALT_CTL(F11)  	,0,0,0},                                   //~v527R~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v76gR~
	{"Up"           ,"��"            ,
        FUNCID_UP,                                              //~5204R~
        FTFCSRKEY,0,          //flag,char,                      //~v06eR~
		{func_up,func_up,func_up},                                 //~v75SR~
		"","",
		{KEY_UP     	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Down"         ,"��"            ,
        FUNCID_DOWN,                                            //~5204R~
        FTFCSRKEY,0,          //flag,char,                      //~v06eR~
		{func_down,func_down,func_down},                           //~v75SR~
		"","",
		{KEY_DOWN   	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Left"         ,"��"            ,
        FUNCID_LEFT,                                            //~5204R~
        FTFCSRKEY,0,          //flag,char,                      //~v06eR~
		{func_left,func_left,func_left},                           //~v75SR~
		"","",
		{KEY_LEFT   	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Right"        ,"�E"            ,
        FUNCID_RIGHT,                                           //~5204R~
        FTFCSRKEY,0,          //flag,char,                      //~v06eR~
		{func_right,func_right,func_right},                        //~v75SR~
		"","",
		{KEY_RIGHT  	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Next-Tab"     ,"�^�u(�O�i)"    ,                          //~5429R~
        FUNCID_TAB,                                             //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_nexttab_pan,func_nexttab_file,func_nexttab_pan},     //~v75SR~
		"","",
		{KEY_TAB		,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST},                                  //~v76gR~
	{"Prev-Tab"     ,"�^�u(���)"    ,                          //~5429R~
        FUNCID_BKTAB,                                           //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_prevtab_pan,func_prevtab_file,func_prevtab_pan},     //~v75SR~
		"","",
//		{KEY_S_TAB	,0,0,0},                                       //~v55jR~
  		{KEY_S_TAB	,KEY_C_t,0,0},                                 //~v55jI~
		{FTFIX,FTCTLC,0,0},NULL_LAST},                             //~v76gR~
	{"Jump:Char<-->Hex"     ,"���(����<-->Hex��)"    ,            //~v773M~
        FUNCID_SWCHARHEX,                                          //~v773M~
        0,0,          //flag,char,                                 //~v773M~
		{0,func_jumpcharhex_file,0},                               //~v773M~
		"","",                                                     //~v773M~
//  	{KEY_C_TAB		,0,0,0},                                   //~v776R~
    	{KEY_A_g		,0,0,0},                                   //~v776I~
		{0,0,0,0},NULL_LAST},                                      //~v773M~
	{"Top-of-Line"  ,"�s��"          ,                          //~5429R~
        FUNCID_LINETOP,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	func_linetop_pan,func_linetop_file,func_linetop_pan,       //~v55NR~
    	{func_linetop_pan,func_linetop_file,func_linetop_dir},     //~v75SR~
		"","",
//		{KEY_S_LEFT,0,0,0},                                        //~v55jR~
  		{KEY_S_LEFT,KEY_C_l,0,0},                                  //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"End-of-Line"  ,"�s��"          ,                          //~5429R~
        FUNCID_LINEEND,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	func_lineend_pan,func_lineend_file,func_lineend_pan,       //~v55NR~
    	{func_lineend_pan,func_lineend_file,func_lineend_dir},     //~v75SR~
		"","",
//		{KEY_S_RIGHT,0,0,0},                                       //~v55jR~
		{KEY_S_RIGHT,KEY_C_r,0,0},                                 //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"Parenthesis"  ,"���ʒT��"          ,                         //~v42hI~
        FUNCID_PPSRCH,                                             //~v42hI~
        0,0,          //flag,char,                                 //~v42hI~
		{0               ,func_ppsrch      ,0},                    //~v75SR~
		"","",                                                     //~v42hI~
		{KEY_A_PERIOD,0,0,0},                                      //~v42hI~
		NULL_NOFLAG},                                              //~v55nR~
	{"Parenthesis-NX"  ,"���ʒT��-NX"          ,                   //~v42wI~
        FUNCID_PPSRCHNX,                                           //~v42wI~
        0,0,          //flag,char,                                 //~v42wI~
		{0               ,func_ppsrchnx      ,0},                  //~v75SR~
		"","",                                                     //~v42wI~
		{KEY_A_COMMA,0,0,0},                                       //~v42wI~
		NULL_NOFLAG},                                              //~v55nR~
	{"XML-Tag"         ,"XML�^�O�T��"          ,                   //~vbe0I~
        FUNCID_XMLSRCH,                                            //~vbe0I~
        0,0,          //flag,char,                                 //~vbe0I~
		{0               ,func_xmlsrch       ,0},                  //~vbe0I~
		"","",                                                     //~vbe0I~
		{KEY_A_SLASH,0,0,0},                                       //~vbe0I~
		NULL_NOFLAG},                                              //~vbe0I~
//  {"Scroll-Up-Line"  ,"1�s��\��" ,                              //~v095R~
    {"Scroll-Up-Line"  ,"1�s��\x95\\��" ,                          //~v095I~
        FUNCID_LINEUP,                                          //~5204R~
        0,0,          //flag,char,                                 //~v0isR~
		{0,func_lineup_file,func_lineup_file},                     //~v75SR~
		"","",                                                  //~5111I~
//		{KEY_S_UP,0,0,0},                                          //~v55jR~
  		{KEY_S_UP,KEY_C_u,0,0},                                    //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
//  {"Scroll-Down-Line"  ,"1�s���\��" ,                            //~v095R~
    {"Scroll-Down-Line"  ,"1�s��\x95\\��" ,                        //~v095I~
        FUNCID_LINEDOWN,                                        //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0,func_linedown_file,func_linedown_file},                 //~v75SR~
		"","",                                                  //~5111I~
//		{KEY_S_DOWN,0,0,0},                                        //~v55jR~
		{KEY_S_DOWN,KEY_C_f,0,0},                                  //~v55jR~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"Next-Value"    ,"���̒l"    ,                                //~v07aM~
        FUNCID_NEXTVALUE,                                          //~v07aM~
        0,0,          //flag,char,                                 //~v07aM~
		{func_nextvalue_pan,0,0},                                  //~v75SR~
		"","",                                                     //~v07aM~
//  	{KEY_S_DOWN,0,0,0},                                        //~v55jR~
  		{KEY_S_DOWN,KEY_C_f,0,0},                                  //~v55jR~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"Prev-Value"    ,"�O�̒l"    ,                                //~v07aM~
        FUNCID_PREVVALUE,                                          //~v07aM~
        0,0,          //flag,char,                                 //~v07aM~
		{func_prevvalue_pan,0,0},                                  //~v75SR~
		"","",                                                     //~v07aM~
//		{KEY_S_UP,0,0,0},                                          //~v55jR~
		{KEY_S_UP,KEY_C_u,0,0},                                    //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"Top-of-Screen","��ʂ̐擪�s"  ,                          //~5429R~
        FUNCID_HOME,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_home	,func_home,func_home},                         //~v75SR~
		"HOM","",                                                  //~v0jkR~
		{KEY_HOME,0,0,0},                                          //~v0iyR~
		{FTFIX,0,0,0},NULL_LAST  	},                             //~v76gR~
	{"Page-Up"      ,"�O�y�[�W"      ,                          //~5429R~
        FUNCID_PGUP,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	0	,func_pgup_file	,func_pgup_file,                       //~v557R~
    	{func_pgup_pan,func_pgup_file	,func_pgup_file},          //~v75SR~
		"UP","",                                                //~5105R~
		{KEY_PGUP   ,KEY_F7,0,0},                                  //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Page-Down"     ,"���y�[�W"      ,                         //~5429R~
        FUNCID_PGDN,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	0	,func_pgdown_file,func_pgdown_file,                    //~v557R~
    	{func_pgdown_pan,func_pgdown_file,func_pgdown_file},       //~v75SR~
		"DOW","",                                               //~5105R~
		{KEY_PGDN   ,KEY_F8,0,0},                                  //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Scroll-Left"  ,"���y�[�W"      ,                          //~5429R~
        FUNCID_PGLEFT,                                          //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_pgleft_file,0},                                  //~v75SR~
		"LEF","",
		{KEY_F10,0,0,0},NULL_NOFLAG	},                             //~v55nR~
	{"Scroll-Right" ,"�E�y�[�W"      ,                          //~5429R~
        FUNCID_PGRIGHT,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_pgright_file,0},                                 //~v75SR~
		"RIG","",
		{KEY_F11,0,0,0}	,NULL_NOFLAG},                             //~v55nR~
	{"Set-Scroll-Size"   ,"�X�N���[���ʐݒ�" ,                  //~v033M~
        FUNCID_SCROLL,                                          //~v033M~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_setscroll,func_setscroll},                       //~v75SR~
		"SCR","",NULL_CMDONLY},                                    //~v55nR~
	{"Top-of-File"  ,"�t�@�C���擪�s",                          //~5429R~
        FUNCID_TOP,                                             //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	0	,func_filetop_file,func_filetop_file,                  //~v61dR~
    	{func_pgtop_pan,func_filetop_file,func_filetop_file},      //~v75SR~
		"TOP","",
//		{KEY_S_PGUP,0,0,0},                                        //~v55jR~
//		{KEY_S_PGUP,KEY_C_p,0,0},                                  //~vb53R~
  		{KEY_S_PGUP,KEY_C_p,KEY_A_PGUP,0},                         //~vb53R~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"End-of-File"  ,"�t�@�C���I�[�s",                          //~5429R~
        FUNCID_BOTTOM,                                          //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	0	,func_fileend_file,func_fileend_file,                  //~v61dR~
    	{func_pgend_pan,func_fileend_file,func_fileend_file},      //~v75SR~
		"BOT","",
//		{KEY_S_PGDN,0,0,0},                                        //~v55jR~
//  	{KEY_S_PGDN,KEY_C_n,0,0},                                  //~vb53R~
    	{KEY_S_PGDN,KEY_C_n,KEY_A_PGDN,0},                         //~vb53R~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST	},                         //~v76gR~
	{"Backspace"    ,"���"          ,
        FUNCID_BS,                                              //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_bs_pan,func_bs_file,func_bs_pan},                    //~v75SR~
		"","",
		{KEY_BS     	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST},                                  //~v76gR~
	{"Delete-Char"  ,"�����폜"      ,                          //~5429R~
        FUNCID_DEL,                                             //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_del_pan,func_del_file,func_del_pan},                 //~v75SR~
		"","",
		{KEY_DEL    	,0,0,0},                                   //~v0isR~
		{FTFIX,0,0,0},NULL_LAST	},                                 //~v76gR~
	{"Delete-Line"  ,"�s�폜"        ,                          //~5429R~
        FUNCID_LINEDEL,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_delline_file,0},                                 //~v75SR~
		"","",
//		{KEY_S_DEL,0,0,0},                                         //~v55jR~
		{KEY_S_DEL,KEY_C_d,0,0},                                   //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST},                           //~v76gR~
	{"Erase-End-of-Line","�s���폜"      ,                      //~5429R~
        FUNCID_EEOL,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_eraseeol_pan,func_eraseeol_file,func_eraseeol_pan},  //~v75SR~
		"","",
		{KEY_END,KEY_A_t,0,0},NULL_NOFLAG	},                     //~v55nR~
	{"Erase-Top-of-Line","�s���폜"      ,                      //~5429R~
        FUNCID_ETOL,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_erasetol_pan,func_erasetol_file,func_erasetol_pan},  //~v75SR~
		"","",
//		{KEY_S_BS,0,0,0},                                          //~v55jR~
  		{KEY_S_BS,KEY_C_b,0,0},                                    //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST},                           //~v76gR~
	{"Clear-Top-of-Line","�s���N���A�[" ,                       //~5429R~
        FUNCID_CTOL,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_cleartol_pan,func_cleartol_file,func_cleartol_pan},  //~v75SR~
		"","",                                                  //~5111I~
//		{KEY_S_END,0,0,0},                                         //~v55jR~
  		{KEY_S_END,KEY_C_e,0,0},                                   //~v55jI~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST},                           //~v76gR~
	{"Split-Line"  ,"�s����"      ,                             //~5429R~
        FUNCID_LINESPLIT,                                       //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_splitline_file,0},                               //~v75SR~
		"SPL","",                                                  //~v45xR~
//  	{KEY_S_ENTER,KEY_S_PENTR,KEY_A_s,0},                       //~v55jR~
    	{KEY_S_ENTER,KEY_S_PENTR,KEY_A_s,KEY_C_x},                 //~v55jI~
//  	{FTSHIFT,FTSHIFT,FTCTLC,0},NULL_LAST},                     //~v76gR~
    	{FTSHIFT,FTSHIFT,0,FTCTLC},NULL_LAST},                     //~v76gR~
	{"Join-Line"  ,"�s�A��"      ,                                 //~v47iI~
        FUNCID_JOIN,                                               //~v47iI~
        FTFCMDONLY,0,          //flag,char,                        //~v47iI~
		{0	,func_join_file,0},                                    //~v75SR~
		"JOI","",NULL_CMDONLY},                                    //~v55nR~
	{"TextFlow"   ,"�p���O���t���`"      ,                         //~v755R~
        FUNCID_TFLOW,                                              //~v755I~
        0,0,          //flag,char,                                 //~v755I~
		{0	,func_tflow,0},                                        //~v75SR~
		"TFL","TF",NULL_CMDONLY},                                  //~v755I~
	{"Insert-Line"  ,"�s�}��"        ,                          //~5429R~
        FUNCID_LINEINS,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
    	{0	,func_insline_file,0},   
		"","",
//		{KEY_S_INS,0,0,0},                                         //~v55jR~
  		{KEY_S_INS,KEY_C_a,0,0},                                   //~v55jR~
		{FTSHIFT,FTCTLC,0,0},NULL_LAST},                           //~v76gR~
	{"Repeat-Line"  ,"�s�J�Ԃ�"      ,                          //~5429R~
        FUNCID_LINEREP,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_repline_file,0},                                 //~v75SR~
		"","",                                                  //~5223R~
		{KEY_S_F10,KEY_A_r,0,0},NULL_NOFLAG},                      //~v55nR~
//  {"Line-Insert-Copy",    "�s�}������",                       //~v06lR~
//      FUNCID_LINECOPY,                                        //~v06lR~
//      0,0,          //flag,char,                              //~v06lR~
//  	0	,func_blockins_file,0,  //differ by function id     //~v06lR~
//  	"","",                                                  //~v06lR~
//  	KEY_A_a},                                               //~v06lR~
//  {"Regin-Start/End","�̈�n�_/�I�_",                            //~v66eR~//~vbi0R~
//  {"Region-Start/End","�̈�n�_/�I�_",                           //~vbi0I~//~vbi1R~
//  {"Regin-Start/End","�̈�n�_/�I�_",                            //~vbi1I~//~vbi5R~
    {CAPRGN_NEW,"�̈�n�_/�I�_",                                   //~vbi5I~
        FUNCID_STDCPREGION,                                        //~v66eI~
        0,0,          //flag,char,                                 //~v66eI~
		{0	,func_stdcpregion_file,0},                             //~v75SR~
		"","",                                                     //~v66eI~
    	{KEY_C_F6,KEY_A_F6,KEY_A_v,0},NULL_NOFLAG},                //~v66eI~
	{"Block-Start/End","�u���b�N�n�_/�I�_",                     //~5429R~
        FUNCID_BLOCK,                                           //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_block_file,0},                                   //~v75SR~
		"","",                                                  //~5122I~
//  	KEY_A_F7,KEY_A_b},                                         //~v20bR~
//  	ALT_CTL(F7),KEY_A_b},                                      //~v527R~
    	{KEY_C_F7,KEY_A_F7,KEY_A_b,0},NULL_NOFLAG},                //~v55nR~
	{"Block-copy-to-CB","�u���b�N��CB����",                        //~v0heI~
        FUNCID_COPYTOCB,                                           //~v0heI~
        0,0,          //flag,char,                                 //~v0heI~
		{0	,func_copytocb_file,0},                                //~v75SR~
		"","",                                                     //~v0heI~
//  	KEY_A_F9},                                                 //~v20bR~
//  	ALT_CTL(F9)},                                              //~v527R~
    	{KEY_C_F9,KEY_A_F9,0,0},NULL_NOFLAG},                      //~v55nR~
	{"Word-Copy-To-CB","���[�h��CB�ɕ���",                         //~v53cR~
        FUNCID_COPYWORD,                                           //~v53cI~
        0,0,          //flag,char,                                 //~v53cI~
		{func_copyword,func_copyword,func_copyword},	//fnamelist,edit,dirlist//~v75SR~
		"","",                                                     //~v53cI~
    	{KEY_A_w,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"Word->CmdLine","���[�h->�R�}���h�s",                         //~v77FR~
        FUNCID_COPYWORDCMD,                                        //~v77FR~
        0,0,          //flag,char,                                 //~v77FR~
//		{0,func_copywordcmd_file,0},	//fnamelist,edit,dirlist   //~vaunR~
  		{0,func_copywordcmd_file,func_copywordcmd_file},	//fnamelist,edit,dirlist//~vaunR~
		"","",                                                     //~v77FR~
    	{KEY_C_w,0,0,0},                                           //~v77ER~
		{FTCTLC,0,0},NULL_LAST},                                   //~v77EI~
	{"Standard-Paste", "�W��\x93\\�t",                             //~v66fR~
        FUNCID_STDCPPASTE,                                         //~v66fI~
        0,0,          //flag,char,                                 //~v66fI~
		{func_stdcppaste_pan,func_stdcppaste_file,func_stdcppaste_pan},//~v75SR~
		"","",                                                     //~v66fI~
//  	{KEY_C_v,0,0,0},NULL_NOFLAG},                              //~v75DR~
    	{KEY_C_v,0,0,0},                                           //~v75DR~
		{FTCTLC,0,0,0},NULL_LAST},                                 //~v76gR~
	{"Block-Insert", "�u���b�N�}������",                           //~v06lM~
        FUNCID_BLOCKINS,                                           //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{func_blockins_pan,func_blockins_file,func_blockins_pan},  //~v75SR~
		"","",                                                     //~v06lM~
//  	ALT_CTL(KEY_A_INS,KEY_A_c,KEY_A_z},                        //~v20cR~
//  	ALT_CTL(INS),KEY_A_c,KEY_A_z},                             //~v527R~
//    	{KEY_C_INS,KEY_A_INS,KEY_A_c,KEY_A_z},NULL_NOFLAG},        //~v8@SR~
      	{KEY_C_INS,KEY_A_INS,KEY_A_c,0      },NULL_NOFLAG},        //~v8@SI~
//	{"Block-Copy-Override","�u���b�N�㏑�\�t",                     //~v095R~
	{"Block-Copy-Override","�u���b�N�㏑\x93\\�t",                 //~v095I~
        FUNCID_BLOCKREP,                                        //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_blockrep_pan,func_blockrep_file,func_blockrep_pan},  //~v75SR~
		"","",                                                  //~5122I~
//  	KEY_A_F8,KEY_A_p},                                         //~v20bR~
//  	ALT_CTL(F8),KEY_A_p},                                      //~v527R~
    	{KEY_C_F8,KEY_A_F8,KEY_A_p,0},NULL_NOFLAG},                //~v55nR~
	{"Block-Over-Space","�u���b�N�󔒏㏑",                     //~v06fI~
        FUNCID_BLOCKREPSPACE,                                   //~v06fR~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_blockrep_file,0},	//differ only funcid           //~v75SR~
		"","",                                                  //~v06fI~
		{KEY_A_o,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"Block-Cut", "�u���b�N�ؔ�",                               //~5429R~
        FUNCID_BLOCKDEL,                                        //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_blockdel_file,0},                                //~v75SR~
		"","",                                                  //~5122I~
//		KEY_A_DEL,KEY_A_d},                                        //~v20cR~
//  	ALT_CTL(DEL),KEY_A_d},                                     //~v527R~
    	{KEY_C_DEL,KEY_A_DEL,KEY_A_d,0},NULL_NOFLAG},              //~v55nR~
	{"Block-Clear", "�u���b�N�N���A�[",                            //~v07aM~
        FUNCID_BLOCKCLEAR,                                         //~v07aM~
        0,0,          //flag,char,                                 //~v07aM~
		{0	,func_blockclear_file,0},                              //~v75SR~
		"","",                                                     //~v07aM~
//  	KEY_A_END,KEY_A_e},                                        //~v20cR~
//  	ALT_CTL(END),KEY_A_e},                                     //~v20eR~
    	{KEY_A_END,KEY_A_e,0,0},NULL_NOFLAG},                      //~v55nR~
//  {"Block-Copy", "�u���b�N����",                              //~v06lR~
//      FUNCID_BLOCKCOPY,                                       //~v06lR~
//      0,0,          //flag,char,                              //~v06lR~
//  	0	,func_blockcopy_file,0,                             //~v06lR~
//  	"","",                                                  //~v06lR~
//  	KEY_A_c},                                               //~v06lR~
	{"Block-Move(cut)", "�u���b�N�폜�ړ�",                        //~v06lR~
        FUNCID_BLOCKCUTMOVE,                                    //~5521R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_blockcutmove_file,0},                            //~v75SR~
		"","",                                                  //~5502I~
		{KEY_A_m,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"Block-Move(clear)", "�u���b�N�󉻈ړ�",                   //~v06lR~
        FUNCID_BLOCKCLRMOVE,                                    //~5521R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_blockclearmove_file,0},                          //~v75SR~
		"","",                                                  //~5521I~
		{KEY_A_n,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"LineMark-Start/End","�s�}�[�N�J�n/�I��",                     //~v06lM~
        FUNCID_LINEMARK,                                           //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_lmark_file,0},                                   //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_h,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"LineIns-Copy", "�s�}������",                                 //~v06lR~
        FUNCID_LIBLOCKINS,                                         //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_blockins_file,0},  //dup use func                //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_i,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"LineIns-Move(cut)", "�s�}���폜�ړ�",                        //~v06lR~
        FUNCID_LIBLOCKCUTMOVE,                                     //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_blockcutmove_file,0},                            //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_j,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"LineIns-Move(clear)","�s�}���󉻈ړ�",                       //~v06lR~
        FUNCID_LIBLOCKCLRMOVE,                                     //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_blockclearmove_file,0},                          //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_k,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"CUT/COPY-2ndCB","CUT/COPY(��QCB)",                          //~v783R~
        FUNCID_CUT,                                                //~v783R~
        0,0,          //flag,char,                                 //~v783R~
		{0	,func_cut_file,0},                                     //~v783R~
		"CUT","",                                                  //~v783R~
		{0,0,0,0},NULL_NOFLAG},                                    //~v783R~
	{"PASTE-2ndCB","\x93\\��t��(��QCB)",                         //~v783R~
        FUNCID_PASTE,                                              //~v783R~
        0,0,          //flag,char,                                 //~v783R~
		{0	,func_paste_file,0},                                   //~v783R~
		"PAS","",                                                  //~v783R~
		{0,0,0,0},NULL_NOFLAG},                                    //~v783R~
//	{"Line-Exclude",      "�s��\��",                              //~v095R~
	{"Line-Exclude",      "�s��\x95\\��",                          //~v095I~
        FUNCID_LINEEXCLUDE,                                        //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_lineexclude_file,0},                             //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_x,0,0,0},NULL_NOFLAG},                              //~v55nR~
//	{"Line-Include",      "�s�ĕ\��",                              //~v095R~
	{"Line-Include",      "�s��\x95\\��",                          //~v095I~
        FUNCID_LINEINCLUDE,                                        //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_lineinclude_file,0},                             //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_y,0,0,0},NULL_NOFLAG},                              //~v55nR~
//	{"Line-Include-Fisrt",     "�擪1�s�ĕ\��",                    //~v095R~
	{"Line-Include-Fisrt",     "�擪1�s��\x95\\��",                //~v095I~
        FUNCID_LINEINCF,                                           //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_lineinclude_file,0},                             //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_f,0,0,0},NULL_NOFLAG},                              //~v55nR~
//	{"Line-Include-Last",      "����1�s�ĕ\��",                    //~v095R~
	{"Line-Include-Last",      "����1�s��\x95\\��",                //~v095I~
        FUNCID_LINEINCL,                                           //~v06lM~
        0,0,          //flag,char,                                 //~v06lM~
		{0	,func_lineinclude_file,0},                             //~v75SR~
		"","",                                                     //~v06lM~
		{KEY_A_l,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"Drop-Set-Of-Lines"  ,"�ꊇ�s�폜",                           //~v0hPR~
        FUNCID_DROP,                                               //~v0hqI~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_drop_file,0},                                    //~v75SR~
		"DRO","",NULL_CMDONLY},                                    //~v55nR~
//    {"DelFile/DropLine","�t�@�C��/�ꊇ�s�폜",                   //~v0hPR~
//        FUNCID_DELX,                                             //~v0hPR~
//        0,0,          //flag,char,                               //~v0hPR~
//        dcmd_xdelete,func_drop_file,dcmd_xdelete,                //~v0hPR~
//        "DEL",""},                                               //~v0hPR~
    {"Drop-Lines/Del-file","�ꊇ�s�폜/File�폜",                  //~v504R~
        FUNCID_DELX,                                               //~v503I~
        FTFCMDONLY,0,          //flag,char,                        //~v503I~
        {dcmd_xdelete,func_drop_file,dcmd_xdelete},                //~v75SR~
        "DEL","",NULL_CMDONLY},                                    //~v55nR~
	{"Linecnt-On/Off",    "�s��<->�T�C�Y\x95\\��",                 //~v10nI~
        FUNCID_DLCCHNGSZ,                                          //~v10nI~
        0,0,          //flag,char,                                 //~v10nI~
		{0	,0,func_dlcmdchngsz_dir},                              //~v75SR~
		"","",                                                     //~v10nI~
		{KEY_F6,0,0,0},NULL_NOFLAG},                               //~v55nR~
//#ifdef UNX                                                       //~v55hR~
//#ifdef FTPSUPP                                                   //~v679R~
	{"User-Name/Id",    "���[�U�[��/Id\x95\\��",                   //~v55hR~
        FUNCID_DLCUIDORSZ,                                         //~v20fI~
        0,0,          //flag,char,                                 //~v20fI~
#ifdef FTPSUPP                                                     //~v679I~
		{0	,0,func_dlcmduidorsz_dir},	//dir list only            //~v75SR~
#else                                                              //~v679I~
//  	func_nosupport,func_nosupport,func_nosupport,              //~v72cR~
    	{0             ,0             ,func_nosupport},            //~v75SR~
#endif //UNX                                                       //~v679I~
		"UG","",                                                   //~v55hR~
#ifdef FTPSUPP                                                     //~v67MR~
		{KEY_S_F6,0,0,0},NULL_NOFLAG},                             //~v55nR~
#else                                                              //~v67MR~
		{0       ,0,0,0},NULL_NOFLAG},                             //~v67CI~
#endif //UNX                                                       //~v67MR~
//#endif //UNX                                                     //~v679R~
	{"LongFileName",    "�����t�@�C����\x95\\��",                  //~v182I~
        FUNCID_DLCLFN,                                             //~v182I~
        0,0,          //flag,char,                                 //~v182I~
		{0	,0,func_dlcmdlfn_dir},	//long filename display switch //~v75SR~
		"LFN","",                                                  //~v55iR~
//  	KEY_C_F6},                                                 //~v21bR~
    	{KEY_S_F11,0,0,0},NULL_NOFLAG},                            //~v55nR~
	{"FileDescription",    "�t�@�C���̐���\x95\\��",               //~v690I~
        FUNCID_FILEDESC,                                           //~v690I~
        0,0,          //flag,char,                                 //~v690I~
		{0	,0,func_desc_dir},	//diplay file description on dir list//~v75SR~
//  	"","",                                                     //~v742R~
    	"DFD","",                                                  //~v742I~
//  	{KEY_S_F10,0,0,0},NULL_NOFLAG},                            //~v742R~
		{KEY_S_F10,ALT_CTL(F10),0,0},NULL_NOFLAG},                 //~v742R~
//  {"Dir-Linecmd-Cut",    "DIR �s�R�}���h�ؔ�",                   //~v558R~
    {"Dir-Linecmd-Cut",   "DIR �s�R�}���h����",                    //~v558R~
        FUNCID_DLCMDCUT,                                           //~v07eR~
        0,0,          //flag,char,                                 //~v07eI~
		{0	,0,func_dlcmdcut_dir},                                 //~v75SR~
		"","",                                                     //~v07eI~
		{KEY_F10,0,0,0},NULL_NOFLAG},                              //~v55nR~
//  {"Dir-Linecmd-Paste",  "DIR �s�R�}���h����",                   //~v558R~
    {"Dir-Linecmd-Paste",  "DIR �s�R�}���h\x93\\�t",               //~v558R~
        FUNCID_DLCMDPASTE,                                         //~v07eR~
        0,0,          //flag,char,                                 //~v07eI~
		{0	,0,func_dlcmdpaste_dir},                               //~v75SR~
		"","",                                                     //~v07eI~
		{KEY_F11,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"HSplit"       ,"������ʕ���"  ,
        FUNCID_HSPLIT,                                          //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_splith,func_splith,func_splith},                     //~v75SR~
		"HSP","",
		{KEY_F2,0,0,0},NULL_NOFLAG},                               //~v55nR~
	{"VSplit"       ,"������ʕ���"  ,
        FUNCID_VSPLIT,                                          //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_splitv,func_splitv,func_splitv},                     //~v75SR~
		"VSP","",
		{KEY_S_F2,0,0,0},NULL_NOFLAG},                             //~v55nR~
	{"Swap"        ,"������ʌ���"  ,
        FUNCID_SWAP,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_swap,func_swap,func_swap},                           //~v75SR~
		"SWA","W",
		{KEY_F9,0,0,0},                                            //~v0isR~
		{FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
	{"Next-Panel"    ,"�����"    ,                             //~5429R~
        FUNCID_NEXTSCR,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_nextpan,func_nextpan,func_nextpan},                  //~v75SR~
		"NEX","+",                                              //~5504R~
		{KEY_S_F8,0,0,0},NULL_NOFLAG	},                         //~v55nR~
	{"Prev-Panel"    ,"�O���"    ,                             //~5429R~
        FUNCID_PREVSCR,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_prevpan,func_prevpan,func_prevpan},                  //~v75SR~
		"PRE","-",                                              //~5504R~
		{KEY_S_F7,0,0,0},NULL_NOFLAG		},                     //~v55nR~
	{"DirPath-Up"    ,"�o�H��"    ,                                //~v558I~
        FUNCID_PATHUP,                                             //~v558I~
        0,0,          //flag,char,                                 //~v558I~
		{0,func_pathup,func_pathup},                               //~v75SR~
		"DPU","",                                                  //~v558I~
		{KEY_A_LEFT,0,0,0},NULL_NOFLAG  },                         //~v55nR~
	{"DirPath-Down"    ,"�o�H�~"      ,                            //~v558I~
        FUNCID_PATHDOWN,                                           //~v558I~
        0,0,          //flag,char,                                 //~v558I~
		{0,func_pathdown,func_pathdown},                           //~v75SR~
		"DPD","",                                                  //~v558I~
		{KEY_A_RIGHT,0,0,0},NULL_NOFLAG 	},                     //~v55nR~
	{"Exit"         ,"���ۑ��I��"          ,                  //~5224R~
        FUNCID_EXIT,                                            //~5204R~
        FTFFREECW,0,          //flag,char,                      //~v06eR~
		{func_exit	,func_exit,func_exit},                         //~v75SR~
		"EXI","",                                               //~5224R~
		{KEY_S_F9,0,0,0},NULL_NOFLAG},                             //~v55nR~
	{"Return"         ,"�ۑ��I��"          ,                    //~5503R~
        FUNCID_TERM,                                            //~5224I~
        FTFFREECW,0,          //flag,char,                      //~v06eR~
		{func_term	,func_term,func_term},                         //~v75SR~
		"RET","",                                               //~5503R~
		{KEY_F4,0,0,0},NULL_NOFLAG},                               //~v55nR~
	{"Quit"         ,"�j���I��"          ,                      //~4C25R~
        FUNCID_QUIT,                                            //~5204R~
        FTFFREECW,0,          //flag,char,                      //~v06eR~
		{func_quit	,func_quit,func_quit},                         //~v75SR~
		"QUI","",                                               //~5224R~
		{KEY_S_F4,0,0,0},NULL_NOFLAG	},                         //~v55nR~
	{"End"          ,"�߂�"          ,
        FUNCID_END,                                             //~5204R~
        FTFFREECW,0,          //flag,char,                         //~v13bR~
		{func_end_pan,func_end_file,func_end_dir},                 //~v75SR~
		"END","",
		{KEY_F3,0,0,0},NULL_NOFLAG},                               //~v55nR~
	{"Save"         ,"�ۑ�"          ,                           //~4C18I~
        FUNCID_SAVE,                                            //~5204R~
//      FTFDUPACMD,0,          //flag(alias duplicated),char,      //~v09wR~//~vbd7R~
//      FTFDUPACMD|FTFDUPACMDFUNC,0,          //flag(alias duplicated,handle dup by func),char,//~vbd7R~//~vbdsR~
        FTFDUPACMD               ,0,          //flag(alias duplicated,handle dup by func),char,//~vbdsI~
		{0	,func_save_file,0},                                    //~v75SR~
		"SAV","S",                                                  //~4C18I~
//  	{KEY_S_F3,0,0,0},NULL_NOFLAG},                             //~v55nR~//~vbdsR~
    	{KEY_S_F3,0,0,0},NULL_NOFLAG2(FTF2DUPACMDFUNC)},           //~vbdsI~
	{"Cancel"       ,"�j��"          ,
        FUNCID_CANCEL,                                          //~5204R~
        FTFFREECW,0,          //flag,char,                         //~v13bR~
		{func_cancel_pan	,func_cancel_file,func_cancel_dir},    //~v75SR~
		"CAN","",
		{KEY_F1,0,0,0},NULL_NOFLAG},                               //~v55nR~
	{"Edit"         ,"�ҏW"          ,
        FUNCID_EDIT,                                            //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{func_edit_file	,func_edit_file,func_edit_file},           //~v75SR~
//  	"EDI","E",NULL_CMDONLY},                                   //~v71PR~
    	"EDI","E",                                                 //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
	{"Edit-Text"      ,"�ҏW-�e�L�X�g"          ,                  //~v50GI~
        FUNCID_EDITTEXT,                                           //~v50GI~
        FTFCMDONLY,0,          //flag,char,                        //~v50GI~
		{func_edittext_file	,func_edittext_file,func_edittext_file},//~v75SR~
//  	"ET","",NULL_CMDONLY},                                     //~v71PR~
    	"ET","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
	{"Edit-Bin"      ,"�ҏW-�o�C�i���|"          ,                 //~v42yR~
        FUNCID_EDITBIN,                                            //~v10GI~
        FTFCMDONLY,0,          //flag,char,                        //~v10GI~
		{func_editbin_file	,func_editbin_file,func_editbin_file}, //~v75SR~
//  	"EB","",NULL_CMDONLY},                                     //~v71PR~
    	"EB","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
    {"Edit-Hex"      ,"�ҏW-Hex"          ,                        //~v44hM~
        FUNCID_EDITHEX,                                            //~v44hM~
        FTFCMDONLY,0,          //flag,char,                        //~v44hM~
    	{func_edithex_file	,func_edithex_file,func_edithex_file}, //~v75SR~
//  	"EH","",NULL_CMDONLY},                                     //~v71PR~
    	"EH","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
	{"Edit-SPF"      ,"�ҏW-SPF"          ,                        //~v42yR~
        FUNCID_EDITSPF,                                            //~v10LI~
        FTFCMDONLY,0,          //flag,char,                        //~v10LI~
		{func_editspf_file	,func_editspf_file,func_editspf_file}, //~v75SR~
//  	"EN","",NULL_CMDONLY},                                     //~v71PR~
    	"EN","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
    {"Edit-COB"          ,"�ҏW-�s�ԕtCOBOL"          ,            //~v44rR~
        FUNCID_EDITSPFCOB,                                         //~v414R~
        FTFCMDONLY,0,          //flag,char,                        //~v414R~
    	{func_editspfcob_file	,func_editspfcob_file,func_editspfcob_file},//~v75SR~
//  	"EC","EL",NULL_CMDONLY},                                   //~v71PR~
    	"EC","EL",                                                 //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
    {"Edit-COBK"         ,"�ҏW-�s�Ԗ�COBOL"          ,            //~v44rM~
        FUNCID_EDITSPFCOB2,                                        //~v44rM~
        FTFCMDONLY,0,          //flag,char,                        //~v44rM~
    	{func_editspfcob2_file	,func_editspfcob2_file,func_editspfcob2_file},//~v75SR~
//  	"EK","",NULL_CMDONLY},                                     //~v71PR~
    	"EK","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
    {"Edit-SPFCOB"        ,"�ҏW-�s�ԕtSPFCOB"          ,          //~v44rR~
        FUNCID_EDITSPFCOBNUM,                                      //~v414R~
        FTFCMDONLY,0,          //flag,char,                        //~v414R~
    	{func_editspfcobnum_file	,func_editspfcobnum_file,func_editspfcobnum_file},//~v75SR~
//  	"ECN","EI",NULL_CMDONLY},                                  //~v71PR~
    	"ECN","EI",                                                //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
    {"Edit-SPFCOBK"       ,"�ҏW-�s�Ԗ�SPFCOB"          ,          //~v44rM~
        FUNCID_EDITSPFCOB2NUM,                                     //~v44rM~
        FTFCMDONLY,0,          //flag,char,                        //~v44rM~
    	{func_editspfcob2num_file	,func_editspfcob2num_file,func_editspfcob2num_file},//~v75SR~
//  	"EKN","EJ",NULL_CMDONLY   },                               //~v71PR~
    	"EKN","EJ",                                                //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
    {"Edit-Fixed80"       ,"�ҏW-�s�Ԗ�80���Œ�"          ,        //~v75HI~
        FUNCID_EDITF80,                                            //~v75HI~
        FTFCMDONLY,0,          //flag,char,                        //~v75HI~
    	{func_editf80_file	,func_editf80_file,func_editf80_file}, //~v75SR~
    	"E8","",                                                   //~v75HI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v75HI~
//	{"Browse"       ,"�\��"          ,                             //~v095R~
  	{"Browse"       ,"\x95\\��"          ,                         //~v095I~
        FUNCID_BROWSE,                                          //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{func_browse_file,func_browse_file,func_browse_file},      //~v75SR~
//  	"BRO","B",NULL_CMDONLY},                                   //~v71PR~
    	"BRO","B",                                                 //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-Text"       ,"\x95\\��-�e�L�X�g"          ,           //~v50GI~
        FUNCID_BROWSETEXT,                                         //~v50GI~
        FTFCMDONLY,0,          //flag,char,                        //~v50GI~
		{func_browsetext_file,func_browsetext_file,func_browsetext_file},//~v75SR~
//  	"BT","",NULL_CMDONLY},                                     //~v71PR~
    	"BT","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-Bin"       ,"\x95\\��-�o�C�i���|"          ,          //~v42yR~
        FUNCID_BROWSEBIN,                                          //~v10GI~
        FTFCMDONLY,0,          //flag,char,                        //~v10GI~
		{func_browsebin_file,func_browsebin_file,func_browsebin_file},//~v75SR~
//  	"BB","",NULL_CMDONLY},                                     //~v71PR~
		"BB","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-Hex"       ,"\x95\\��-Hex"          ,                 //~v44hM~
        FUNCID_BROWSEHEX,                                          //~v44hM~
        FTFCMDONLY,0,          //flag,char,                        //~v44hM~
	    {func_browsehex_file,func_browsehex_file,func_browsehex_file},//~v75SR~
//      "BH","",NULL_CMDONLY},                                     //~v71PR~
        "BH","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-SPF"       ,"\x95\\��-SPF"          ,                 //~v42yR~
        FUNCID_BROWSESPF,                                          //~v10LI~
        FTFCMDONLY,0,          //flag,char,                        //~v10LI~
		{func_browsespf_file,func_browsespf_file,func_browsespf_file},//~v75SR~
//  	"BN","",NULL_CMDONLY},                                     //~v71PR~
    	"BN","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-COB"       ,"\x95\\��-�s�ԕtCOBOL"          ,         //~v44rR~
        FUNCID_BROWSESPFCOB,                                       //~v414R~
        FTFCMDONLY,0,          //flag,char,                        //~v414R~
	    {func_browsespfcob_file,func_browsespfcob_file,func_browsespfcob_file},//~v75SR~
//      "BC","BL",NULL_CMDONLY},                                   //~v71PR~
        "BC","BL",                                                 //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-COBK"       ,"\x95\\��-�s�Ԗ�COBOL"          ,        //~v44rM~
        FUNCID_BROWSESPFCOB2,                                      //~v44rM~
        FTFCMDONLY,0,          //flag,char,                        //~v44rM~
	    {func_browsespfcob2_file,func_browsespfcob2_file,func_browsespfcob2_file},//~v75SR~
//      "BK","",NULL_CMDONLY},                                     //~v71PR~
        "BK","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-SPFCOB"       ,"\x95\\��-�s�ԕtSPFCOB"          ,     //~v44rR~
        FUNCID_BROWSESPFCOBNUM,                                    //~v414R~
        FTFCMDONLY,0,          //flag,char,                        //~v414R~
	    {func_browsespfcobnum_file,func_browsespfcobnum_file,func_browsespfcobnum_file},//~v75SR~
//      "BCN","BI",NULL_CMDONLY},                                  //~v71PR~
        "BCN","BI",                                                //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-SPFCOBK"       ,"\x95\\��-�s�Ԗ�SPFCOB"          ,    //~v44rM~
        FUNCID_BROWSESPFCOB2NUM,                                   //~v44rM~
        FTFCMDONLY,0,          //flag,char,                        //~v44rM~
	    {func_browsespfcob2num_file,func_browsespfcob2num_file,func_browsespfcob2num_file},//~v75SR~
//      "BKN","BJ",NULL_CMDONLY},                                  //~v71PR~
        "BKN","BJ",                                                //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Browse-Fixed80"       ,"\x95\\��-�s�Ԗ�80���Œ�"          ,  //~v75HI~
        FUNCID_BROWSEF80,                                          //~v75HI~
        FTFCMDONLY,0,          //flag,char,                        //~v75HI~
	    {func_browsef80_file,func_browsef80_file,func_browsef80_file},//~v75SR~
        "B8","",                                                   //~v75HI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v75HI~
  	{"Select"       ,"�I��"          ,                             //~v414R~
        FUNCID_SELECT,                                             //~v09wI~
//      FTFDUPACMD|FTFCMDONLY,0,          //flag(alias duplicated),char,//~v0isR~//~vbd7R~
//      FTFDUPACMD|FTFDUPACMDFUNC|FTFCMDONLY,0,          //flag(alias duplicated,handle dup acmd by a func),char,//~vbd7R~//~vbdsR~
        FTFDUPACMD|               FTFCMDONLY,0,          //flag(alias duplicated,handle dup acmd by a func),char,//~vbdsI~
//  	{0               ,0               ,func_select},           //~v75SR~//~vbd7R~
    	{0               ,func_select     ,func_select},           //~vbd7I~
//  	"SEL","S",NULL_CMDONLY},                                   //~v71PR~
    	"SEL","S",                                                 //~v71PI~
//      NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~//~vbdsR~
        NULL_CMDONLY2(FTF2FIXEDVERB|FTF2DUPACMDFUNC)},             //~vbdsI~
  	{"Select-Text"       ,"�I��-�e�L�X�g"          ,               //~v50GI~
        FUNCID_SELECTTEXT,                                         //~v50GI~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v50GI~
		{0               ,0               ,func_selecttext},       //~v75SR~
//  	"ST","",NULL_CMDONLY},                                     //~v71PR~
    	"ST","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-Bin"       ,"�I��-�o�C�i���|"          ,              //~v42yR~
        FUNCID_SELECTBIN,                                          //~v10GI~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v10GI~
		{0               ,0               ,func_selectbin},        //~v75SR~
//  	"SB","",NULL_CMDONLY},                                     //~v71PR~
		"SB","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-Hex"       ,"�I��-Hex"          ,                     //~v44hM~
        FUNCID_SELECTHEX,                                          //~v44hM~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v44hM~
	    {0               ,0               ,func_selecthex_file},   //~v75SR~
//      "SH","",NULL_CMDONLY},                                     //~v71PR~
        "SH","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-SPF"       ,"�I��-SPF"          ,                     //~v42yR~
        FUNCID_SELECTSPF,                                          //~v10LI~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v10LI~
		{0               ,0               ,func_selectspf},        //~v75SR~
//  	"SN","",NULL_CMDONLY},                                     //~v71PR~
		"SN","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-COB"       ,"�I��-�s�ԕtCOBOL"          ,             //~v44rR~
        FUNCID_SELECTSPFCOB,                                       //~v414R~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v414R~
    	{0               ,0               ,func_selectspfcob},     //~v75SR~
//  	"SC","SL",NULL_CMDONLY},                                   //~v71PR~
    	"SC","SL",                                                 //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-COBK"       ,"�I��-�s�Ԗ�COBOL"          ,            //~v44rM~
        FUNCID_SELECTSPFCOB2,                                      //~v44rM~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v44rM~
    	{0               ,0               ,func_selectspfcob2},    //~v75SR~
//  	"SK","",NULL_CMDONLY},                                     //~v71PR~
    	"SK","",                                                   //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-SPFCOB"       ,"�I��-�s�ԕtSPFCOB"          ,         //~v44rR~
        FUNCID_SELECTSPFCOBNUM,                                    //~v414R~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v414R~
	    {0               ,0               ,func_selectspfcobnum},  //~v75SR~
//      "SCN","SI",NULL_CMDONLY},                                  //~v71PR~
        "SCN","SI",                                                //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-SPFCOBK"       ,"�I��-�s�Ԗ�SPFCOB"          ,        //~v44rM~
        FUNCID_SELECTSPFCOB2NUM,                                   //~v44rM~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v44rM~
	    {0               ,0               ,func_selectspfcob2num}, //~v75SR~
//      "SKN","SJ",NULL_CMDONLY},                                  //~v71PR~
        "SKN","SJ",                                                //~v71PI~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v71PI~
  	{"Select-Fixed80"       ,"�I��-�s�Ԗ�80���Œ�"          ,      //~v75HI~
        FUNCID_SELECTF80,                                          //~v75HI~
        FTFCMDONLY,0,          //flag(alias duplicated),char,      //~v75HI~
	    {0               ,0               ,func_selectf80},        //~v75SR~
        "S8","",                                                   //~v75HR~
        NULL_CMDONLY2(FTF2FIXEDVERB)},                             //~v75HI~
	{"Create"       ,"�쐬"          ,
        FUNCID_CREATE,                                          //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_create_file,0},                                  //~v75SR~
		"CRE","",NULL_CMDONLY},                                    //~v55nR~
	{"Replace"      ,"�u��"          ,                          //~5106I~
        FUNCID_REPL,                                            //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_repl_file,0},                                    //~v75SR~
		"REP","",NULL_CMDONLY},                                    //~v55nR~
	{"Copy"         ,"�t�@�C������"  ,
        FUNCID_COPY,                                            //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{dcmd_xcopy,func_copy_file,dcmd_xcopy},                    //~v75SR~
		"COP","",NULL_CMDONLY},                                    //~v55nR~
	{"Move"         ,"�t�@�C���ړ�����",
        FUNCID_MOVE,                                            //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{dcmd_xmove,func_copy_file,dcmd_xmove}, //differ by funcid //~v75SR~
		"MOV","",NULL_CMDONLY},                                    //~v55nR~
	{"Append"       ,"�t�@�C���ǉ�����",                           //~v0iaR~
        FUNCID_APPEND,                                             //~v0iaI~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{dcmd_append,func_append_file,dcmd_append}, //differ by funcid//~v75SR~
		"APP","",NULL_CMDONLY},                                    //~v55nR~
	{"Send-Filename-Ins"  ,"�t�@�C��������-�}��"          ,        //~v76gI~
        FUNCID_SENDINS,                                            //~v76gI~
        0,0,          //flag,char,                                 //~v76gI~
		{func_sendins_pan,0,func_sendins_dir},                     //~v76gR~
		"SDI","",                                                  //~v76gR~
		{KEY_A_i,0,0,0},NULL_NOFLAG	},                             //~v76gI~
	{"Send-Filename-Rep"  ,"�t�@�C��������-�u��"          ,        //~v76gI~
        FUNCID_SENDREP,                                            //~v76gI~
        0,0,          //flag,char,                                 //~v76gI~
		{func_sendrep_pan,0,func_sendrep_dir},                     //~v76gR~
		"SDR","",                                                  //~v76gR~
		{KEY_A_r,0,0,0},NULL_NOFLAG	},                             //~v76gI~
	{"Send-Filename-Del"  ,"�t�@�C��������-�폜"          ,        //~v76gR~
        FUNCID_SENDDEL,                                            //~v76gR~
        0,0,          //flag,char,                                 //~v76gR~
		{0               ,0,func_senddel_dir},                     //~v76gR~
		"SDD","",                                                  //~v76gR~
		{KEY_A_d,0,0,0},NULL_NOFLAG	},                             //~v76gR~
	{"Send-Filename-Up"  ,"�t�@�C��������-��"          ,           //~v76gI~
        FUNCID_SENDUP ,                                            //~v76gI~
        0,0,          //flag,char,                                 //~v76gI~
		{0              ,0,func_sendup_dir},                       //~v76gI~
		"","",                                                     //~v76gI~
		{KEY_A_UP,0,0,0},NULL_NOFLAG	},                         //~v76gI~
	{"Send-Filename-Down"  ,"�t�@�C��������-��"          ,         //~v76gI~
        FUNCID_SENDDOWN ,                                          //~v76gI~
        0,0,          //flag,char,                                 //~v76gI~
		{0              ,0,func_senddown_dir},                     //~v76gI~
		"","",                                                     //~v76gI~
		{KEY_A_DOWN,0,0,0},NULL_NOFLAG	},                         //~v76gI~
	{"Undo"         ,"�C���߂�"      ,
        FUNCID_UNDO,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_undo_file,0},                                    //~v75SR~
		"UND","U",
		{KEY_S_F1 ,0,0,0},                                         //~v0isR~
		NULL_NOFLAG },                                             //~v55nR~
	{"Redo"         ,"�C���߂��̎��",
        FUNCID_REDO,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_redo_file,0},                                    //~v75SR~
//  	"RED","",NULL_CMDONLY},                                    //~v55nR~//~vag2R~
		"RED","",                                                  //~vag2I~
//  	{KEY_C_F1 ,0,0,0},                                         //~vagkR~
  	 	{KEY_C_F2 ,0,0,0},                                         //~vagkI~
		NULL_NOFLAG },                                             //~vag2I~
	{"Locate"       ,"�s�ʒu�t��"      ,                        //~5111R~
        FUNCID_LOCATE,                                          //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_locate_file,func_locate_dir},                    //~v75SR~
		"LOC","L",NULL_CMDONLY},                                   //~v55nR~
	{"Position"     ,"�s�ʒu�t��"      ,                           //~v0j2R~
        FUNCID_POS,                                                //~v0j2I~
        FTFCMDONLY,0,          //flag,char,                        //~v0j2I~
		{func_pos_pan,func_pos_pan,func_pos_pan},                  //~v75SR~
		"POS","",NULL_CMDONLY},                                    //~v55nR~
	{"Find(Case-sense)","�T��(�召��ʗL)",
        FUNCID_FIND,                                            //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
//  	{0	,func_find_file,func_find_file},                       //~v76mR~
    	{func_find_pan	,func_find_file,func_find_file},           //~v76mI~
//  	"FIN","F",NULL_CMDONLY},                                   //~vbCBR~
    	"FIN","F",                                                 //~vbCBI~
//		NULL_CMDONLY2(FTF2FIND_PSSUPP)},                           //~vbCCR~
  		NULL_CMDONLY2(FTF2FIND_PSSUPP|FTF2FINDCMD)},               //~vbCCI~
	{"Find(Case-insense)","�T��(�召��ʖ�)",
        FUNCID_IFIND,                                           //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
//  	{0	,func_ifind_file,func_ifind_file},                     //~v76mR~
    	{func_ifind_pan	,func_ifind_file,func_ifind_file},         //~v76mI~
//  	"IFI","I",NULL_CMDONLY},                                   //~vbCBR~
    	"IFI","I",                                                 //~vbCBR~
//  	NULL_CMDONLY2(FTF2FIND_PSSUPP)},                           //~vbCCR~
    	NULL_CMDONLY2(FTF2FIND_PSSUPP|FTF2FINDCMD)},               //~vbCCI~
	{"FindPSP"      ,"�T��(�������)"     ,                        //~vbCBI~
        FUNCID_FINDPSP,                                            //~vbCBI~
        0,0,          //flag,char,                                 //~vbCBI~
    	{0	,func_findPSP,0},                                      //~vbCBR~
		"","",                                                     //~vbCBR~
		{KEY_C_F5,0,0,0},                                          //~vbCBR~
    	NULL_NOFLAG2(FTF2FIND_PSSUPP)},                            //~vbCBR~
	{"FindPSP(reverse)"  ,"���]�T��(�������)",                    //~vb51I~
        FUNCID_REVRFINDPSP,                                        //~vb51M~
        0,0,          //flag,char,                                 //~vb51M~
    	{0	,func_revfindPSP,0},                                   //~vb51M~
		"","",                                                     //~vb51M~
    	{KEY_C_F5,0,0,0},                                          //~vb51M~
//     	/*FTkflag*/{FTSHIFT,0,0,0},/*FTflag2*/FTF2FIND_PSSUPP,{0}},//~vb51M~//~vbvtR~
       	/*FTkflag*/{FTSHIFT,0,0,0},NULL_FLAG2(FTF2FIND_PSSUPP)},   //~vbvtR~
	{"FindPSF"      ,"�T��(���̃t�@�C��)"     ,                    //~vbCBM~
        FUNCID_FINDPSF,                                            //~vbCBM~
        0,0,          //flag,char,                                 //~vbCBM~
    	{0	,func_findPSF,0},                                      //~vbCBM~
		"","",                                                     //~vbCBM~
		{KEY_A_F5,0,0,0},                                          //~vbCBI~
    	NULL_NOFLAG2(FTF2FIND_PSSUPP)},                            //~vbCBM~
	{"FindPSF(reverse)"  ,"���]�T��(�t�@�C��)",                    //~vb51I~
        FUNCID_REVRFINDPSF,                                        //~vb51M~
        0,0,          //flag,char,                                 //~vb51M~
    	{0	,func_revfindPSF,0},                                   //~vb51M~
		"","",                                                     //~vb51M~
    	{KEY_A_F5,0,0,0},                                          //~vb51M~
//  	/*FTkflag*/{FTSHIFT,0,0,0},/*FTflag2*/FTF2FIND_PSSUPP,{0}},//~vb51M~//~vbvtR~
    	/*FTkflag*/{FTSHIFT,0,0,0},NULL_FLAG2(FTF2FIND_PSSUPP)},   //~vbvtR~
	{"Display-PSx-Find"      ,"PSx�R�}���h\x95\\��"     ,          //~vb51R~
        FUNCID_DISPLAYPS,                                          //~vbCBI~
#ifdef KKK                                                         //~vb51I~
        FTFCMDONLY,0,          //flag,char,                        //~vbCBI~
#else                     //@@@@test                               //~vb51I~
        0,0,          //flag,char,                                 //~vb51I~
#endif                                                             //~vb51I~
		{func_displayPS,func_displayPS,func_displayPS},            //~vbCBI~
		"PSD","",NULL_CMDONLY},                                    //~vbCBI~
	{"FindWordFwd(Case)","���[�h���T��-�召�L",                    //~v77ER~
        FUNCID_FINDWORDF,                                          //~v77ER~
        0,0,          //flag,char,                                 //~v77ER~
    	{0,func_findwordF_file,0},                                 //~v77ER~
		"FWF","",                                                  //~v77ER~
      	{KEY_C_RMP,0,0,0},                                         //~v785R~
      	{FTCTLC,0,0},NULL_LAST},                                   //~v785R~
//    	{KEY_C_RMP,KEY_A_RBRACE,0,0},                              //~v785R~
//  	{FTCTLC,FTSHIFT,0},NULL_LAST},   A+S+ is err on inifile    //~v785R~
	{"FindWordBwd(Case)","���[�h�O�T��-�召�L",                    //~v77ER~
        FUNCID_FINDWORDB,                                          //~v77ER~
        0,0,          //flag,char,                                 //~v77ER~
    	{0,func_findwordB_file,0},                                 //~v77ER~
		"FWB","",                                                  //~v77ER~
    	{KEY_C_LMP,0,0,0},                                         //~v785R~
    	{FTCTLC,0,0},NULL_LAST},                                   //~v785R~
//  	{KEY_C_LMP,KEY_A_LBRACE,0,0},                              //~v785R~
//  	{FTCTLC,FTSHIFT,0},NULL_LAST},                             //~v785R~
	{"FindWordFwd(NoCase)","���[�h���T��-�召��",                  //~v77ER~
        FUNCID_IFINDWORDF,                                         //~v77ER~
        0,0,          //flag,char,                                 //~v77ER~
    	{0,func_ifindwordF_file,0},                                //~v77ER~
		"IWF","",                                                  //~v77ER~
		{KEY_A_RMP,0,0,0},                                         //~v77ER~
        NULL_NOFLAG	},                                             //~v77ER~
	{"FindWordBwd(NoCase)","���[�h�O�T��-�召��",                  //~v77ER~
        FUNCID_IFINDWORDB,                                         //~v77ER~
        0,0,          //flag,char,                                 //~v77ER~
    	{0,func_ifindwordB_file,0},                                //~v77ER~
		"IWB","",                                                  //~v77ER~
		{KEY_A_LMP,0,0,0},                                         //~v77ER~
        NULL_NOFLAG	},                                             //~v77ER~
//  {"Exclude-CaseSense","��\��(�召��ʗL)",                     //~v0hzI~
	{"Exclude-CaseSense","��\x95\\��(�召��ʗL)",                 //~v0hzI~
        FUNCID_EXCLUDE,                                            //~v0hzI~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_exclude_file,0},                                 //~v75SR~
//  	"EXC","X",NULL_CMDONLY},                                   //~vbCCR~
    	"EXC","X",                                                 //~vbCCI~
    	NULL_CMDONLY2(FTF2FIND_PSSUPP|FTF2FINDCMD)},               //~vbCCI~
//  {"Exclude-CaseInsense","��\��(�召��ʖ�)",                   //~v0hzI~
	{"Exclude-CaseInsense","��\x95\\��(�召��ʖ�)",               //~v0hzI~
        FUNCID_IEXCLUDE,                                           //~v0hzI~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_iexclude_file,0},                                //~v75SR~
//  	"IX","",NULL_CMDONLY},                                     //~vbCCR~
    	"IX","",                                                   //~vbCCI~
    	NULL_CMDONLY2(FTF2FIND_PSSUPP|FTF2FINDCMD)},               //~vbCCI~
	{"Exclude-Exchange","\x95\\���s����",                          //~v41kI~
        FUNCID_XEXCHANGE,                                          //~v41kI~
        FTFCMDONLY,0,          //flag,char,                        //~v41kI~
		{0	,func_xx_file,0},                                      //~v75SR~
//  	"XX","",NULL_CMDONLY},                                     //~v78GR~
  		"FLI","XX",NULL_CMDONLY},                                  //~v78GI~
	{"Find-NXonly-CaseS" ,"\x95\\���s�T��-�召�ʗL",               //~v10nR~
        FUNCID_FINDNX,                                             //~v10nI~
        FTFCMDONLY,0,          //flag,char,                        //~v10nI~
		{0	,func_findnx_file,0},                                  //~v75SR~
//  	"FNX","",NULL_CMDONLY},                                    //~vbCBR~
    	"FNX","",                                                  //~vbCBI~
//  	NULL_CMDONLY2(FTF2FIND_PSSUPP)},                           //~vbCCR~
    	NULL_CMDONLY2(FTF2FIND_PSSUPP|FTF2FINDCMD)},               //~vbCCI~
	{"Find-NXonly-CaseIS","\x95\\���s�T��-�召�ʖ�",               //~v10nR~
        FUNCID_IFINDNX,                                            //~v10nI~
        FTFCMDONLY,0,          //flag,char,                        //~v10nI~
		{0	,func_ifindnx_file,0},                                 //~v75SR~
//  	"INX","",NULL_CMDONLY},                                    //~vbCBR~
    	"INX","",                                                  //~vbCBI~
//  	NULL_CMDONLY2(FTF2FIND_PSSUPP)},                           //~vbCCR~
    	NULL_CMDONLY2(FTF2FIND_PSSUPP|FTF2FINDCMD)},               //~vbCCI~
	{"Re-Find"      ,"�ĒT��"     ,                             //~5311R~
        FUNCID_RFIND,                                           //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	{0	,func_rfind_file,func_rfind_file},                     //~v76iR~
    	{func_rfind_pan	,func_rfind_file,func_rfind_file},         //~v76gR~
		"","",
//  	{KEY_F5,0,0,0},NULL_NOFLAG	},                             //~vbCBR~
    	{KEY_F5,0,0,0},                                            //~vbCBI~
    	NULL_NOFLAG2(FTF2FIND_PSSUPP)},                            //~vbCBR~
	{"Re-Find(reverse)"    ,"���]�ĒT��",                       //~5311R~
        FUNCID_REVRFIND,                                        //~5204R~
        0,0,          //flag,char,                              //~v06eR~
//  	{0	,func_revrfind_file,func_revrfind_file},               //~v76mR~
    	{func_revrfind_pan	,func_revrfind_file,func_revrfind_file},//~v76mI~
		"","",
//  	{KEY_S_F5,0,0,0},NULL_NOFLAG	},                         //~vbCBR~
    	{KEY_S_F5,0,0,0},                                          //~vbCBI~
    	NULL_NOFLAG2(FTF2FIND_PSSUPP)},                            //~vbCBR~
//  {"Change"       ,"�u��"          ,                             //~v72PR~
	{"Change"       ,"�u��(�召��ʗL)"          ,                 //~v72PR~
        FUNCID_CHANGE,                                          //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_change_file,0},                                  //~v75SR~
//  	"CHA","C",NULL_CMDONLY},                                   //~vbCCR~
    	"CHA","C",                                                 //~vbCCI~
    	NULL_CMDONLY2(FTF2CHANGECMD)},                             //~vbCCR~
	{"Change(CaseInsense)"       ,"�u��(�召��ʖ�)"          ,    //~v72PI~
        FUNCID_ICHANGE,                                            //~v72PI~
        FTFCMDONLY,0,          //flag,char,                        //~v72PI~
		{0	,func_ichange_file,0},                                 //~v75SR~
//  	"IC","",NULL_CMDONLY},                                     //~vbCCR~
    	"IC","",                                                   //~vbCCI~
    	NULL_CMDONLY2(FTF2CHANGECMD)},                             //~vbCCR~
//  {"Change-NXonly","\x95\\���u��"          ,                     //~v72PR~
    {"Change-NXonly","\x95\\���u��-�召�ʗL"          ,            //~v72PR~
        FUNCID_CHANGENX,                                           //~v10nI~
        FTFCMDONLY,0,          //flag,char,                        //~v10nI~
		{0	,func_changenx_file,0},                                //~v75SR~
//  	"CNX","",NULL_CMDONLY},                                    //~vbCCR~
    	"CNX","",                                                  //~vbCCI~
    	NULL_CMDONLY2(FTF2CHANGECMD)},                             //~vbCCR~
	{"Change-NX-CaseIS","\x95\\���s�u��-�召�ʖ�",                 //~v72PI~
        FUNCID_ICHANGENX,                                          //~v72PI~
        FTFCMDONLY,0,          //flag,char,                        //~v72PI~
		{0	,func_ichangenx_file,0},                               //~v75SR~
//  	"ICN","",NULL_CMDONLY},                                    //~vbCCR~
    	"ICN","",                                                  //~vbCCI~
    	NULL_CMDONLY2(FTF2CHANGECMD)},                             //~vbCCR~
	{"Re-Change"      ,"�ĒT���u��",                            //~5311R~
        FUNCID_RCHANGE,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_rchange_file,0},                                 //~v75SR~
		"","",
		{KEY_F6,0,0,0},NULL_NOFLAG	},                             //~v55nR~
	{"Re-Change(reverse)" ,"���]�ĒT���u��",                    //~5311R~
        FUNCID_REVRCHANGE,                                      //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{0	,func_revrchange_file,0},                              //~v75SR~
		"","",
		{KEY_S_F6,0,0,0},NULL_NOFLAG},                             //~v55nR~
	{"Retrieve"     ,"�O�R�}���h"    ,
        FUNCID_PREVCMD,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_retrieveprev,func_retrieveprev,func_retrieveprev},   //~v75SR~
		"","",                                                  //~5528R~
		{KEY_F12,0,0,0},NULL_NOFLAG},                              //~v55nR~
	{"R-Retrieve"    ,"���R�}���h"    ,                         //~5429R~
        FUNCID_NEXTCMD,                                         //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_retrievenext,func_retrievenext,func_retrievenext},   //~v75SR~
		"","",                                                  //~5528R~
		{KEY_S_F12,0,0,0},NULL_NOFLAG},                            //~v55nR~
	{"Cmd_Repeat"    ,"�R�}���h����"    ,                          //~v47nR~
        FUNCID_CMDREPEAT,                                          //~v47kI~
        0,0,          //flag,char,                                 //~v47kI~
		{func_cmdrepeat,func_cmdrepeat,func_cmdrepeat},            //~v75SR~
		"","",                                                     //~v47kI~
//  	KEY_A_F11},                                                //~v47nR~
//		{ALT_CTL(F12)  	,0,0,0},                                   //~v670R~
  		{KEY_C_F12  	,0,0,0},                                   //~v670I~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v76gR~
	{"Retrieve-OfTheScr"     ,"�O�R�}���h-��ʖ�"    ,             //~v670I~
        FUNCID_PREVCMDSCR,                                         //~v670I~
        0,0,          //flag,char,                                 //~v670I~
		{func_retrieveprevscr,func_retrieveprevscr,func_retrieveprevscr},//~v75SR~
		"","",                                                     //~v670I~
		{KEY_A_F12,0,0,0},NULL_NOFLAG},                            //~v670I~
//  {"R-Retrieve-OfTheScr"     ,"�O�R�}���h-��ʖ�"    ,           //~v670I~//~vbi6R~
    {"R-Retrieve-OfTheScr"     ,"���R�}���h-��ʖ�"    ,           //~vbi6I~
        FUNCID_NEXTCMDSCR,                                         //~v670I~
        0,0,          //flag,char,                                 //~v670I~
		{func_retrievenextscr,func_retrievenextscr,func_retrievenextscr},//~v75SR~
		"","",                                                     //~v670I~
//  	{0        ,0,0,0},NULL_NOFLAG},                            //~v670I~//~vbi6R~
    	{KEY_A_F12,0,0,0},                                         //~vbi6I~
//  	/*FTkflag*/{FTSHIFT,0,0,0},/*FTflag2*/0,{0}},              //~vbi6I~//~vbvtR~
    	/*FTkflag*/{FTSHIFT,0,0,0},NULL_LAST},                     //~vbvtI~
	{"CmdHistoryList"        ,"�R�}���h����"    ,                  //~vbi3R~//~vbi6R~
        FUNCID_CMDHISTU8,                                          //~vbi3R~
        0,0,          //flag,char,                                 //~vbi3I~
		{func_cmdhistu8,func_cmdhistu8,func_cmdhistu8},            //~vbi3R~
		"CHL","",                                                  //~vbi3R~//~vbi6R~
		{KEY_C_F12,0,0,0},                                         //~vbi3I~
//    	/*FTkflag*/{FTSHIFT,0,0,0},/*FTflag2*/0,{0}},              //~vbi3I~//~vbvtR~
      	/*FTkflag*/{FTSHIFT,0,0,0},NULL_LAST},                     //~vbvtI~
	{"ScreenHardCopy"     ,"��ʃn�[�h�R�s�["    ,                 //~vbzJR~
        FUNCID_SCRHCOPY,                                           //~vbzJR~
        0,0,          //flag,char,                                 //~vbzJR~
		{func_scrHcopy,func_scrHcopy,func_scrHcopy},               //~vbzJR~
		"","",                                                     //~vbzJR~
//  	{KEY_C_h,0,0,0},                                           //~vbzPR~
//    	{KEY_A_z,0,0,0},                                           //~vbzRR~
#ifdef LNXCON                                                      //+vbzRI~
    	{KEY_A_z,0,0,0},                                           //+vbzRI~
#else                                                              //+vbzRI~
    	{KEY_C_h,KEY_A_z,0,0},                                     //~vbzRR~
#endif                                                             //+vbzRI~
		{FTCTLC,0,0,0},NULL_LAST	},                             //~vbzJR~
	{"Short-Cut-Input"    ,"�Z�k�L�[����"    ,                     //~v48fI~
        FUNCID_SHORTCUT,                                           //~v48fI~
        0,0,          //flag,char,                                 //~v48fI~
		{func_shortcut,func_shortcut,func_shortcut},               //~v75SR~
		"","",                                                     //~v48fI~
  		{KEY_A_a  	,0,0,0},                                       //~v48fR~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v76gR~
	{"Short-Cut-Query"    ,"�Z�k�L�[\x95\\��"    ,                 //~v48fI~
        FUNCID_SHORTCUTQUERY,                                      //~v48fI~
        0,0,          //flag,char,                                 //~v48fI~
		{func_shortcutquery,func_shortcutquery,func_shortcutquery},//~v75SR~
		"","",                                                     //~v48fI~
  		{KEY_A_q  	,0,0,0},                                       //~v48fI~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v76gR~
	{"Short-Path"    ,"�Z�k�p�X��"    ,                            //~vba2I~
        FUNCID_SHORTPATH,                                          //~vba2I~
        FTFCMDONLY,0,          //flag,char,                        //~vba2I~
		{func_shortpath,func_shortpath,func_shortpath},            //~vba2I~
		"SP","",NULL_CMDONLY},                                     //~vba2I~
#ifdef AAA                                                         //~vbzRI~
#ifdef FTPSUPP                                                     //~v78ZI~
	{"3270-Hotkey"    ,"3270�z�b�g�L�["    ,                       //~v78ZR~
        FUNCID_TSOHOTKEY,                                          //~v78ZI~
        0,0,          //flag,char,                                 //~v78ZI~
		{0                 ,func_tsohotkey,0},                     //~v78ZI~
		"TN3","",                                                  //~v9@1R~
   		{KEY_A_z	,0,0,0},                                       //~v8@SR~//~vbzRR~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v78ZI~
#endif                                                             //~v78ZI~
#endif                                                             //~vbzRI~
	{"Hex-Vertical","HEX�Q�i\x95\\��"     ,                        //~v77CR~
        FUNCID_HEX,                                                //~v60vR~
        0,0,          //flag,char,                                 //~v60vR~
		{0,func_hex_file,0},                                       //~v75SR~
		"HEX","",                                                  //~v60vR~
  		{ALT_CTL(F10)  	,0,0,0},                                   //~v60vR~
		{FTDMYF,0,0,0},NULL_LAST	},                             //~v76gR~
	{"Line-Number","�s�ԍ��R�}���h"      ,                      //~v069I~
        FUNCID_NUM,                                             //~v069I~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0           ,func_number	,0}              ,             //~v75SR~
		"NUM","",NULL_CMDONLY},                                    //~v55nR~
	{"Renumber","�s�ԍ��U�蒼��"      ,                            //~v504I~
        FUNCID_RENUM,                                              //~v504I~
        FTFCMDONLY,0,          //flag,char,                        //~v504I~
		{dcmd_rename ,func_renum	,dcmd_rename  }  ,             //~v75SR~
		"REN","",NULL_CMDONLY},                                    //~v55nR~
//  {"Sort"       ,"�\�[�g"              ,                         //~v10LR~
	{"Sort"       ,"\x83\\�[�g"              ,                     //~v10LI~
        FUNCID_SORT,                                               //~v10II~
        FTFCMDONLY,0,          //flag,char,                        //~v10II~
//  	0           ,func_sort  	,0              ,              //~v57jR~
    	{0           ,func_sort  	,func_sort_dir}  ,             //~v75SR~
		"SOR","",NULL_CMDONLY},                                    //~v55nR~
	{"Rotate"       ,"��]"              ,                         //~v511I~
        FUNCID_ROTATE,                                             //~v511I~
        FTFCMDONLY,0,          //flag,char,                        //~v511I~
		{0           ,func_rotate  	,0}              ,             //~v75SR~
		"ROT","",NULL_CMDONLY},                                    //~v55nR~
	{"DBCS-Conv"       ,"���{��ϊ�"              ,                //~v47UI~
        FUNCID_DBCSCONV,                                           //~v47UI~
        FTFCMDONLY,0,          //flag,char,                        //~v47UI~
		{0           ,func_dbcsconv  ,0 }             ,            //~v75SR~
		"CV","",NULL_CMDONLY},                                     //~v55nR~
	{"Refresh"       ,"���t���b�V��"              ,                //~v152I~
        FUNCID_REFRESH,                                            //~v152I~
        0,0,          //flag,char,                                 //~v152R~
		{0           ,0  	,func_dlcmdrefresh},                   //~v75SR~
		"REF","",                                                  //~v152R~
		{KEY_S_F1,0,0,0},NULL_NOFLAG},                             //~v55nR~
	{"Basic-Calc"      ,"�ȈՌv�Z"              ,                  //~v155R~
        FUNCID_BC  ,                                               //~v155R~
        FTFCMDONLY,0,          //flag,char,                        //~v155R~
		{func_bc     ,func_bc  ,func_bc}  ,                        //~v75SR~
		"XBC","",NULL_CMDONLY},                                    //~v55nR~
	{"Table-Calc"      ,"�Ȉ�\x95\\�v�Z"              ,            //~v155I~
        FUNCID_TC  ,                                               //~v155I~
        FTFCMDONLY,0,          //flag,char,                        //~v155R~
		{0           ,func_tc  ,0  }      ,                        //~v75SR~
		"TC","",                                                   //~v155I~
		NULL_CMDONLY},                                             //~v55nR~
//    {"Table-Calc-NXonly"    ,"�Ȉ�\x95\\�v�Z(\x95\\���s)"              ,//~v17fR~
//        FUNCID_TCNX   ,                                          //~v17fR~
//        FTFCMDONLY,0,          //flag,char,                      //~v17fR~
//        0           ,func_tcnx,0        ,                        //~v17fR~
//        "TCN","",                                                //~v17fR~
//        0},                                                      //~v17fR~
	{"File-Version"       ,"�t�@�C���o�[�W����",                   //~v0crI~
        FUNCID_VERSION,                                            //~v0crI~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0           ,func_version   ,0  }            ,            //~v75SR~
		"VER","",NULL_CMDONLY},                                    //~v55nR~
	{"Tab-column"   ,"�^�u����"		 ,                          //~5429R~
        FUNCID_TABCMD,                                          //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
//  	0	,func_tabctr_file,0,                                   //~v50mR~
    	{func_tabctr_file,func_tabctr_file,func_tabctr_file},      //~v75SR~
		"TAB","",NULL_CMDONLY},                                    //~v55nR~
	{"Column-gauge"      ,"����K" ,                               //~v11NI~
        FUNCID_COL,                                                //~v11NI~
        0,0,          //flag,char,                                 //~v11NI~
    	{0	,func_col,0},                                          //~v75SR~
		"COL","",                                                  //~v11NR~
//  	KEY_A_F2},                                                 //~v20bR~
//  	ALT_CTL(F2)},                                              //~v215R~
//  	KEY_C_F2},                                                 //~v21bR~
//  	{KEY_S_F11,0,0,0},NULL_NOFLAG},                            //~vbs6R~
    	{KEY_S_F11,0,0,0},NULL_NOFLAG2(FTF2DIRCMD)},               //~vbs6I~
	{"Set-Boundary"            ,"���E�ݒ�" ,                       //~v74EI~
        FUNCID_BNDS,                                               //~v74EI~
        0,0,          //flag,char,                                 //~v74EI~
		{0	,func_bnds,func_bnds},                                 //~v75SR~
		"BOU","BND",                                               //~v74EI~
    	{0,0,0,0},NULL_NOFLAG},                                    //~v74EI~
	{"Line-Change-tag"   ,"�s�ύX�^�O" ,                        //~5429R~
        FUNCID_CID,                                             //~5225I~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{0	,func_cid,0},                                          //~v75SR~
		"CID","",NULL_CMDONLY},                                    //~v55nR~
	{"Option-set"        ,"�I�v�V�����ݒ�" ,                    //~v05BI~
        FUNCID_OPT,                                             //~v05BI~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{func_opt,func_opt,func_opt},                              //~v75SR~
		"OPT","",NULL_CMDONLY},                                    //~v55nR~
	{"EBCDIC-setting"       ,"EBCDIC�ݒ�" ,                        //~va7KI~
        FUNCID_EBC,                                                //~va7KI~
        FTFCMDONLY,0,          //flag,char,                        //~va7KR~
		{func_ebc,func_ebc,func_ebc},                              //~va7KI~
		"EBC","",NULL_CMDONLY},                                    //~va7KI~
#ifdef UTF8SUPPH                                                   //~va0xR~
	{"UTF8-Mode-Switch"       ,"UTF8���[�hSW" ,                    //~va0xI~
        FUNCID_MODE,                                               //~va0xI~
        0,0,          //flag,char,                                 //~va0xI~
		{func_mode,func_mode,func_mode},                           //~va0xI~
		"UTF","",                                                  //~va0xI~
//#ifdef ARM                                                       //~vbraR~
//        NULL_CMDONLY},                                           //~vbraR~
//#else                                                            //~vbraR~
    	{KEY_A_u,0,0,0},NULL_NOFLAG},                              //~va0xI~
//#endif                                                           //~vbraR~
#endif                                                             //~va0xI~
#ifdef UTF8UCS2                                                    //~va30I~
	{"Combine-W0-UniChar"       ,"0��-UniChar-����" ,              //~va30I~
        FUNCID_COMBINE,                                            //~va30I~
        0,0,          //flag,char,                                 //~va30I~
		{func_optcombine,func_optcombine,func_optcombine},         //~va30I~
//  	"","",                                                     //~va30I~//~vb96R~
    	"CMB","",                                                  //~vb96I~
//  	{KEY_A_SLASH,0,0,0},NULL_NOFLAG},                          //~va3dR~
    	{KEY_A_COLON,0,0,0},NULL_NOFLAG},                          //~va3dI~
	{"Temp-Ligature-Opt"       ,"Ligature-�ꎞ�I�ύX",             //~va3dR~
        FUNCID_LIGATURE,                                           //~va3dI~
        0,0,          //flag,char,                                 //~va3dI~
		{func_optligature,func_optligature,func_optligature},      //~va3dR~
//  	"","",                                                     //~va3dI~//~vb96R~
    	"LIG","",                                                  //~vb96I~
    	{KEY_A_SEMICOLON,0,0,0},NULL_NOFLAG},                      //~va3dI~
#endif                                                             //~va30I~
	{"CapsLock"          ,"�啶���Œ�" ,                           //~v69JI~
        FUNCID_CAPSLOCK,                                           //~v69JI~
        FTFCMDONLY,0,          //flag,char,                        //~v69JI~
		{func_capslock,func_capslock,func_capslock},               //~v69JI~
		"CAP","",NULL_CMDONLY},                                    //~v69JI~
	{"INI-write"   ,"INI�o��" ,                                 //~5429R~
        FUNCID_INI,                                             //~5429I~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{func_ini,func_ini,func_ini},                              //~v75SR~
		"INI","",NULL_CMDONLY},                                    //~v55nR~
	{"SyntaxHighLight"   ,"\x8d\\���J���[\x5c\\��" ,               //~v780R~
        FUNCID_SYNTAX,                                             //~v780I~
        0,0,          //flag,char,                                 //~v780I~
		{func_syntax,func_syntax,func_syntax},                     //~v780I~
		"SYN","",                                                  //~v780R~
    	{KEY_C_s,0,0,0},                                           //~v77ER~
		{FTCTLC,0,0},NULL_LAST},                                   //~v77EI~
	{"FileProfile"   ,"�v���t�@�C��" ,                             //~v78rI~
        FUNCID_PROFILE,                                            //~v78rI~
        0,0,          //flag,char,                                 //~v78rI~
		{func_profile,func_profile,func_profile},                  //~v78rI~
		"PRO","",                                                  //~v78rI~
    	{0,0,0,0},                                                 //~v78rI~
		{0,0,0},NULL_LAST},                                        //~v78rI~
	{"DOS-command","DOS�R�}���h"           ,                    //~v020R~
        FUNCID_DOS,                                             //~5204R~
        FTFCMDONLY,0,          //flag,char,                        //~v0isR~
		{func_dos	,func_dos   	,func_dos}       ,             //~v75SR~
		"DOS",">",NULL_CMDONLY},                                   //~v55nR~
	{"Submit-script-file","�X�N���v�g���s",                        //~v0k4I~
        FUNCID_SUBMIT,                                             //~v0k4I~
//      FTFCMDONLY,0,          //flag,char,                        //~v72QR~
        0,0,          //flag,char,                                 //~v72QI~
		{func_submit,func_submit,func_submit},                     //~v75SR~
		"SUB","",NULL_CMDONLY},                                    //~v55nR~
//#ifdef FTPSUPP                                                   //~v679R~
	{"remote-shell","�����[�g�V�F��",                              //~v592I~
        FUNCID_RSH,                                                //~v592I~
        FTFCMDONLY,0,          //flag,char,                        //~v592I~
#ifdef FTPSUPP                                                     //~v679I~
		{func_rsh,func_rsh,func_rsh},                              //~v75SR~
#else                                                              //~v679I~
		{func_nosupport,func_nosupport,func_nosupport},            //~v75SR~
#endif                                                             //~v679I~
		"RSH","",NULL_CMDONLY},                                    //~v592I~
//#endif                                                           //~v679R~
                                                                   //~v70zI~
	{"Node","Node",                                                //~vac0I~
        FUNCID_NODE,                                               //~vac0I~
        FTFCMDONLY,0,          //flag,char,                        //~vac0I~
		{func_node,func_node,func_node},                           //~vac0I~
		"NOD","",NULL_CMDONLY},                                    //~vac0I~
                                                                   //~vac0I~
	{"TSO","TSO",                                                  //~v70zI~
        FUNCID_TSO,                                                //~v70zI~
        FTFCMDONLY,0,          //flag,char,                        //~v70zI~
#ifdef FTPSUPP                                                     //~v70zI~
		{func_tso,func_tso,func_tso},                              //~v75SR~
#else                                                              //~v70zI~
		{func_nosupport,func_nosupport,func_nosupport},            //~v75SR~
#endif                                                             //~v70zI~
		"TSO","",NULL_CMDONLY},                                    //~v70zI~
                                                                   //~v70zI~
	{"Execute-xecmd-file","�t�@�C�������s",                        //~v55nI~
        FUNCID_EXECMDFILE,                                         //~v55nI~
        FTFCMDONLY,0,          //flag,char,                        //~v55nI~
		{func_execmdfile,func_execmdfile,func_execmdfile},         //~v75SR~
		"EXE","",NULL_CMDONLY},                                    //~v55nR~
//#ifdef W32                                                       //~v64vR~
//#if defined(W32)||defined(LNX)                                   //~v679R~
	{"OpenByAssociation" ,"�֘A�t�������s",                        //~v564I~
        FUNCID_ASSOCIATE,                                          //~v564I~
        FTFCMDONLY,0,          //flag,char,                        //~v564I~
#if defined(W32)||defined(LNX)                                     //~v679I~
		{func_openwith  ,func_openwith  ,func_openwith}  ,         //~v75SR~
#else                                                              //~v679I~
		{func_nosupport,func_nosupport,func_nosupport},            //~v75SR~
#endif                                                             //~v679I~
		"ASS","!",NULL_CMDONLY},                                   //~v564R~
//#endif                                                           //~v679R~
//#if defined(W32)||defined(XXE)                                   //~v679R~
	{"Command-by-Timer"  ,"�^�C�}�[���s",                          //~v55WI~
        FUNCID_ATCMD,                                              //~v55WI~
        FTFCMDONLY,0,          //flag,char,                        //~v55WI~
#if defined(W32)||defined(XXE)                                     //~v679I~
		{func_at,func_at,func_at},                                 //~v75SR~
#else                                                              //~v679I~
		{func_nosupport,func_nosupport,func_nosupport},            //~v75SR~
#endif                                                             //~v679I~
//  	"AT","&",NULL_CMDONLY},                                    //~v663R~
    	"AT","",NULL_CMDONLY},                                     //~v663I~
//#endif                                                           //~v679R~
//#ifdef W32                                                       //~v651R~
//#if defined(W32)||defined(XXE)                                   //~v679R~
	{"Sleep"             ,"�^�C�}�[�x��",                          //~v55YI~
        FUNCID_SLEEP,                                              //~v55YI~
        FTFCMDONLY,0,          //flag,char,                        //~v55YI~
#if defined(W32)||defined(XXE)                                     //~v679I~
		{func_sleep,func_sleep,func_sleep},                        //~v75SR~
#else                                                              //~v679I~
		{func_nosupport,func_nosupport,func_nosupport},            //~v75SR~
#endif                                                             //~v679I~
		"SLE","",NULL_CMDONLY},                                    //~v55YI~
//#endif                                                           //~v679R~
	{"Help"         ,"����"          ,
        FUNCID_HELP,                                            //~5204R~
        0,0,          //flag,char,                              //~v06eR~
		{func_help	,func_help,func_help},                         //~v75SR~
		"HEL","?",NULL_CMDONLY},                                   //~v55nR~
	{"Key"         ,"�L�[����"          ,                          //~v0jnR~
        FUNCID_KEY,                                                //~v0jnR~
        FTFCMDONLY,0,          //flag,char,                        //~v0jnR~
		{func_key	,func_key,func_key},                           //~v75SR~
		"KEY","K",NULL_CMDONLY},                                   //~v55nR~
////*for japanese                                                  //~v705R~
////  {"(J)Graphic-Char-\x01","(��)�r������-\x01"     , //upper left corner//~v705R~
//    {"(J)LineChr-TL-x01-\x01","(��)�r������-\x01"     , //upper left corner//~v705R~
//        FUNCID_GRAPHCHAR_ULC,                                    //~v705R~
//        FTFJONLY,0x01,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_7,KEY_C_P7,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x02" ,"(��)�r������-\x02"     , //upper right corner//~v705R~
//    {"(J)LineChr-TR-x02-\x02" ,"(��)�r������-\x02"     , //upper right corner//~v705R~
//        FUNCID_GRAPHCHAR_URC,                                    //~v705R~
//        FTFJONLY,0x02,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_9,KEY_C_P9,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x03" ,"(��)�r������-\x03"     ,  //lower left corner//~v705R~
//    {"(J)LineChr-BL-x03-\x03" ,"(��)�r������-\x03"     ,  //lower left corner//~v705R~
//        FUNCID_GRAPHCHAR_LLC,                                    //~v705R~
//        FTFJONLY,0x03,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_1,KEY_C_P1,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x04" ,"(��)�r������-\x04"     ,  //lower right corner//~v705R~
//    {"(J)LineChr-BR-x04-\x04" ,"(��)�r������-\x04"     ,  //lower right corner//~v705R~
//        FUNCID_GRAPHCHAR_LRC,                                    //~v705R~
//        FTFJONLY,0x04,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_3,KEY_C_P3,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x05" ,"(��)�r������-\x05"     ,  //virtical line//~v705R~
//    {"(J)LineChr-VL-x05-\x05" ,"(��)�r������-\x05"     ,  //virtical line//~v705R~
//        FUNCID_GRAPHCHAR_VL,                                     //~v705R~
//        FTFJONLY,0x05,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
////      {KEY_A_HAT,KEY_C_PPLUS,KEY_C_PPERIOD,0},                 //~v705R~
//        {KEY_A_HAT,KEY_C_PPLUS,0            ,0},                 //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x06" ,"(��)�r������-\x06"     ,   //horizontal line//~v705R~
//    {"(J)LineChr-HL-x06-\x06" ,"(��)�r������-\x06"     ,   //horizontal line//~v705R~
//        FUNCID_GRAPHCHAR_HL,                                     //~v705R~
//        FTFJONLY,0x06,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
////      {KEY_A_MINUS,KEY_C_PMINUS,KEY_C_P0,0},                   //~v705R~
//        {KEY_A_MINUS,KEY_C_PMINUS,0       ,0},                   //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x10" , "(��)�r������-\x10"     ,  //center cross//~v705R~
//    {"(J)LineChr-CX-x10-\x10" , "(��)�r������-\x10"     ,  //center cross//~v705R~
//        FUNCID_GRAPHCHAR_CX,                                     //~v705R~
//        FTFJONLY,0x10,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_5,KEY_C_P5,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x15" , "(��)�r������-\x15"     ,  //lower middle stopper//~v705R~
//    {"(J)LineChr-BT-x15-\x15" , "(��)�r������-\x15"     ,  //lower middle stopper//~v705R~
//        FUNCID_GRAPHCHAR_LHS,                                    //~v705R~
//        FTFJONLY,0x15,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_2,KEY_C_P2,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x16" , "(��)�r������-\x16"     ,  //upper middle stopper//~v705R~
//    {"(J)LineChr-TT-x16-\x16" , "(��)�r������-\x16"     ,  //upper middle stopper//~v705R~
//        FUNCID_GRAPHCHAR_UHS,                                    //~v705R~
//        FTFJONLY,0x16,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_8,KEY_C_P8,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x17" , "(��)�r������-\x17"     ,  //right middle stopper//~v705R~
//    {"(J)LineChr-RT-x17-\x17" , "(��)�r������-\x17"     ,  //right middle stopper//~v705R~
//        FUNCID_GRAPHCHAR_RVS,                                    //~v705R~
//        FTFJONLY,0x17,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_6,KEY_C_P6,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////  {"(J)Graphic-Char-\x19" , "(��)�r������-\x19"     ,  //left middle stopper//~v705R~
//    {"(J)LineChr-LT-x19-\x19" , "(��)�r������-\x19"     ,  //left middle stopper//~v705R~
//        FUNCID_GRAPHCHAR_LVS,                                    //~v705R~
//        FTFJONLY,0x19,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_4,KEY_C_P4,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////*for english                                                   //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xda" , "(�p)�r������-\xda"     ,//upper left corner//~v705R~
//    {"(E)LineChr-TL-xDA-\xda" , "(�p)�r������-\xda"     ,//upper left corner//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xc9" , "(�p)�r������-\xc9"     ,//upper left corner//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_ULC,                                    //~v705R~
////      FTFEONLY,0xc9,          //flag,char,                     //~v705R~
//        FTFEONLY,0xda,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_7,KEY_C_P7,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xbf" , "(�p)�r������-\xbf"     ,  //upper right corner//~v705R~
//    {"(E)LineChr-TR-xBF-\xbf" , "(�p)�r������-\xbf"     ,  //upper right corner//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xbb" , "(�p)�r������-\xbb"     ,  //upper right corner//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_URC,                                    //~v705R~
////      FTFEONLY,0xbb,          //flag,char,                     //~v705R~
//        FTFEONLY,0xbf,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_9,KEY_C_P9,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xc0" , "(�p)�r������-\xc0"     ,  //lower left corner//~v705R~
//    {"(E)LineChr-BL-xC0-\xc0" , "(�p)�r������-\xc0"     ,  //lower left corner//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xc8" , "(�p)�r������-\xc8"     ,  //lower left corner//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_LLC,                                    //~v705R~
////      FTFEONLY,0xc8,          //flag,char,                     //~v705R~
//        FTFEONLY,0xc0,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_1,KEY_C_P1,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xd9" , "(�p)�r������-\xd9"     ,  //lower right corner//~v705R~
//    {"(E)LineChr-BR-xD9-\xd9" , "(�p)�r������-\xd9"     ,  //lower right corner//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xbc" , "(�p)�r������-\xbc"     ,  //lower right corner//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_LRC,                                    //~v705R~
////      FTFEONLY,0xbc,          //flag,char,                     //~v705R~
//        FTFEONLY,0xd9,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_3,KEY_C_P3,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xb3" , "(�p)�r������-\xb3"     ,  //virtical line//~v705R~
//    {"(E)LineChr-VL-xB3-\xb3" , "(�p)�r������-\xb3"     ,  //virtical line//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xba" , "(�p)�r������-\xba"     ,  //virtical line//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_VL,                                     //~v705R~
////      FTFEONLY,0xba,          //flag,char,                     //~v705R~
//        FTFEONLY,0xb3,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
////      {KEY_A_HAT,KEY_C_PPLUS,0,0},                             //~v705R~
////      {KEY_A_HAT,KEY_C_PPLUS,KEY_C_PPERIOD,0},                 //~v705R~
//        {KEY_A_HAT,KEY_C_PPLUS,0            ,0},                 //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xc4" , "(�p)�r������-\xc4"     ,  //horizontal line//~v705R~
//    {"(E)LineChr-HL-xC4-\xc4" , "(�p)�r������-\xc4"     ,  //horizontal line//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xcd" , "(�p)�r������-\xcd"     ,  //horizontal line//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_HL,                                     //~v705R~
////      FTFEONLY,0xcd,          //flag,char,                     //~v705R~
//        FTFEONLY,0xc4,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
////      {KEY_A_MINUS,KEY_C_PMINUS,0,0},                          //~v705R~
////      {KEY_A_MINUS,KEY_C_PMINUS,KEY_C_P0,0},                   //~v705R~
//        {KEY_A_MINUS,KEY_C_PMINUS,0       ,0},                   //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xc5" , "(�p)�r������-\xc5"     ,  //center cross//~v705R~
//    {"(E)LineChr-CX-xC5-\xc5" , "(�p)�r������-\xc5"     ,  //center cross//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xce" , "(�p)�r������-\xce"     ,  //center cross//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_CX,                                     //~v705R~
////      FTFEONLY,0xce,          //flag,char,                     //~v705R~
//        FTFEONLY,0xc5,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_5,KEY_C_P5,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xc1" , "(�p)�r������-\xc1"     ,  //lower middle stopper//~v705R~
//    {"(E)LineChr-BT-xC1-\xc1" , "(�p)�r������-\xc1"     ,  //lower middle stopper//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xca" , "(�p)�r������-\xca"     ,  //lower middle stopper//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_LHS,                                    //~v705R~
////      FTFEONLY,0xca,          //flag,char,                     //~v705R~
//        FTFEONLY,0xc1,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_2,KEY_C_P2,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xc2" , "(�p)�r������-\xc2"     ,  //upper middle stopper//~v705R~
//    {"(E)LineChr-TT-xC2-\xc2" , "(�p)�r������-\xc2"     ,  //upper middle stopper//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xcb" , "(�p)�r������-\xcb"     ,  //upper middle stopper//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_UHS,                                    //~v705R~
////      FTFEONLY,0xcb,          //flag,char,                     //~v705R~
//        FTFEONLY,0xc2,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_8,KEY_C_P8,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xb4" , "(�p)�r������-\xb4"     ,  //right middle stopper//~v705R~
//    {"(E)LineChr-RT-xB4-\xb4" , "(�p)�r������-\xb4"     ,  //right middle stopper//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xb9" , "(�p)�r������-\xb9"     ,  //right middle stopper//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_RVS,                                    //~v705R~
////      FTFEONLY,0xb9,          //flag,char,                     //~v705R~
//        FTFEONLY,0xb4,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_6,KEY_C_P6,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
////#ifdef UNX                                                     //~v705R~
////  {"(E)Graphic-Char-\xc3" , "(�p)�r������-\xc3"     ,  //left middle stopper//~v705R~
//    {"(E)LineChr-LT-xC3-\xc3" , "(�p)�r������-\xc3"     ,  //left middle stopper//~v705R~
////#else  //!UNX                                                  //~v705R~
////    {"(E)Graphic-Char-\xcc" , "(�p)�r������-\xcc"     ,  //left middle stopper//~v705R~
////#endif //!UNX                                                  //~v705R~
//        FUNCID_GRAPHCHAR_LVS,                                    //~v705R~
////      FTFEONLY,0xcc,          //flag,char,                     //~v705R~
//        FTFEONLY,0xc3,          //flag,char,                     //~v705R~
//        func_char   ,func_char      ,func_char      ,            //~v705R~
//        "","",                                                   //~v705R~
//        {KEY_A_4,KEY_C_P4,0,0},                                  //~v705R~
//        {FTDMYF,0,0,0},0,0},                                     //~v705R~
//sequence changed as follow Alt+n                                 //~v705I~
//*for japanese                                                    //~v705I~
    {"(J)LineChr-BL-x03-\x03" ,"(��)�r������-\x03"     ,  //lower left corner//~v705I~
        FUNCID_GRAPHCHAR_LLC,                                      //~v705I~
        FTFJONLY,0x03,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char    }  ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_1,KEY_C_P1,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-BT-x15-\x15" , "(��)�r������-\x15"     ,  //lower middle stopper//~v705I~
        FUNCID_GRAPHCHAR_LHS,                                      //~v705I~
        FTFJONLY,0x15,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char     } ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_2,KEY_C_P2,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-BR-x04-\x04" ,"(��)�r������-\x04"     ,  //lower right corner//~v705I~
        FUNCID_GRAPHCHAR_LRC,                                      //~v705I~
        FTFJONLY,0x04,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char     } ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_3,KEY_C_P3,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-LT-x19-\x19" , "(��)�r������-\x19"     ,  //left middle stopper//~v705I~
        FUNCID_GRAPHCHAR_LVS,                                      //~v705I~
        FTFJONLY,0x19,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char     } ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_4,KEY_C_P4,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-CX-x10-\x10" , "(��)�r������-\x10"     ,  //center cross//~v705I~
        FUNCID_GRAPHCHAR_CX,                                       //~v705I~
        FTFJONLY,0x10,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char   }   ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_5,KEY_C_P5,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-RT-x17-\x17" , "(��)�r������-\x17"     ,  //right middle stopper//~v705I~
        FUNCID_GRAPHCHAR_RVS,                                      //~v705I~
        FTFJONLY,0x17,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char }     ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_6,KEY_C_P6,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-TL-x01-\x01","(��)�r������-\x01"     , //upper left corner//~v705I~
        FUNCID_GRAPHCHAR_ULC,                                      //~v705I~
        FTFJONLY,0x01,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char }     ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_7,KEY_C_P7,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-TT-x16-\x16" , "(��)�r������-\x16"     ,  //upper middle stopper//~v705I~
        FUNCID_GRAPHCHAR_UHS,                                      //~v705I~
        FTFJONLY,0x16,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char }     ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_8,KEY_C_P8,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-TR-x02-\x02" ,"(��)�r������-\x02"     , //upper right corner//~v705I~
        FUNCID_GRAPHCHAR_URC,                                      //~v705I~
        FTFJONLY,0x02,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_9,KEY_C_P9,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-HL-x06-\x06" ,"(��)�r������-\x06"     ,   //horizontal line//~v705I~
        FUNCID_GRAPHCHAR_HL,                                       //~v705I~
        FTFJONLY,0x06,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_MINUS,KEY_C_PMINUS,0       ,0},                     //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(J)LineChr-VL-x05-\x05" ,"(��)�r������-\x05"     ,  //virtical line//~v705I~
        FUNCID_GRAPHCHAR_VL,                                       //~v705I~
        FTFJONLY,0x05,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_HAT,KEY_C_PPLUS,0            ,0},                   //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
//*for english                                                     //~v705I~
    {"(E)LineChr-BL-xC0-\xc0" , "(�p)�r������-\xc0"     ,  //lower left corner//~v705I~
        FUNCID_GRAPHCHAR_LLC,                                      //~v705I~
        FTFEONLY,0xc0,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_1,KEY_C_P1,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-BT-xC1-\xc1" , "(�p)�r������-\xc1"     ,  //lower middle stopper//~v705I~
        FUNCID_GRAPHCHAR_LHS,                                      //~v705I~
        FTFEONLY,0xc1,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_2,KEY_C_P2,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-BR-xD9-\xd9" , "(�p)�r������-\xd9"     ,  //lower right corner//~v705I~
        FUNCID_GRAPHCHAR_LRC,                                      //~v705I~
        FTFEONLY,0xd9,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_3,KEY_C_P3,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-LT-xC3-\xc3" , "(�p)�r������-\xc3"     ,  //left middle stopper//~v705I~
        FUNCID_GRAPHCHAR_LVS,                                      //~v705I~
        FTFEONLY,0xc3,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_4,KEY_C_P4,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-CX-xC5-\xc5" , "(�p)�r������-\xc5"     ,  //center cross//~v705I~
        FUNCID_GRAPHCHAR_CX,                                       //~v705I~
        FTFEONLY,0xc5,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char   }   ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_5,KEY_C_P5,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-RT-xB4-\xb4" , "(�p)�r������-\xb4"     ,  //right middle stopper//~v705I~
        FUNCID_GRAPHCHAR_RVS,                                      //~v705I~
        FTFEONLY,0xb4,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char }     ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_6,KEY_C_P6,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-TL-xDA-\xda" , "(�p)�r������-\xda"     ,//upper left corner//~v705I~
        FUNCID_GRAPHCHAR_ULC,                                      //~v705I~
        FTFEONLY,0xda,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char }     ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_7,KEY_C_P7,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-TT-xC2-\xc2" , "(�p)�r������-\xc2"     ,  //upper middle stopper//~v705I~
        FUNCID_GRAPHCHAR_UHS,                                      //~v705I~
        FTFEONLY,0xc2,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_8,KEY_C_P8,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-TR-xBF-\xbf" , "(�p)�r������-\xbf"     ,  //upper right corner//~v705I~
        FUNCID_GRAPHCHAR_URC,                                      //~v705I~
        FTFEONLY,0xbf,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char  }    ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_9,KEY_C_P9,0,0},                                    //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-HL-xC4-\xc4" , "(�p)�r������-\xc4"     ,  //horizontal line//~v705I~
        FUNCID_GRAPHCHAR_HL,                                       //~v705I~
        FTFEONLY,0xc4,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char   }   ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_MINUS,KEY_C_PMINUS,0       ,0},                     //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
    {"(E)LineChr-VL-xB3-\xb3" , "(�p)�r������-\xb3"     ,  //virtical line//~v705I~
        FUNCID_GRAPHCHAR_VL,                                       //~v705I~
        FTFEONLY,0xb3,          //flag,char,                       //~v705I~
        {func_char   ,func_char      ,func_char }     ,            //~v75SR~
        "","",                                                     //~v705I~
        {KEY_A_HAT,KEY_C_PPLUS,0            ,0},                   //~v705I~
        {FTDMYF,0,0,0},NULL_LAST},                                 //~v76gR~
	{"Null-Char(0x00)"      , "�k������(0x00)"     ,//0x00 input   //~v0a2R~
        FUNCID_NULLCHAR,                                           //~v0a2I~
		0,0x00,                    //flag,char(0x00),              //~v0a2I~
		{func_char   ,func_char  	,func_char  }    ,             //~v75SR~
		"","",                                                     //~v0a2I~
		{KEY_C_2,0,0,0},                                           //~v0isR~
//  	FTDMYF},                                                   //~v0jdR~
//		{FTFIX,0,0,0},NULL_LAST},                                  //~v76mR~
  		{FTDMYF,0,0,0},NULL_LAST},                                 //~v76mI~
	{"","", 0, 0,0,{ 0,0,0}, "","", NULL_CMDONLY}                  //~v75SR~
};
static FUNCTBL *Sfunctbl=(void*)Sfunctbldefault;                //~5430R~
//************************************
int func_nosupport(PUCLIENTWE Ppcw)                                //~v679I~
{                                                                  //~v679I~
	PFUNCTBL pft;                                                  //~v679I~
    pft=Ppcw->UCWpfunct;                                           //~v679I~
	uerrmsg("function \"%s\" is not supported",0,                  //~v679I~
    			pft->FTnamee);                                     //~v679I~
    return 4;                                                      //~v679I~
}                                                                  //~v679I~
//**************************************************            //~4C30I~
//*init                                                         //~5429R~
//*parm: none                                                   //~5216R~
//*return:none                                                  //~5429R~
//**************************************************            //~4C30I~
//void functinit(void)                                             //~v705R~
void functinit(char *Postype)                                      //~v705I~
{                                                               //~4C30I~
//#ifdef UNX                                                       //~v55kR~
//    FUNCTBL *pft;                                                //~v55kR~
//    char *pc;                                                    //~v55kR~
//    int len;                                                     //~v55kR~
//#endif                                                           //~v55kR~
//************************************                          //~4C30I~
//	if (UCBITCHK(Gopt2,GOPT2F7F8))//F7,F8 for Page up/dn        //~5429R~
//  {                                                           //~5429R~
//		if (!(pft=functblsrch(FUNCID_PGUP)))                    //~5429R~
//			uerrexit("function:Page-Up is not defined",         //~5429R~
//				     	"�@�\:�O�� ����`����Ă��܂���");      //~5429R~
//      pft->FTkey[1]=KEY_F7;                                   //~5429R~
//		if (!(pft=functblsrch(FUNCID_PGDN)))                    //~5429R~
//			uerrexit("function:Page-Doen is not defined",       //~5429R~
//				     	"�@�\:���� ����`����Ă��܂���");      //~5429R~
//      pft->FTkey[1]=KEY_F8;                                   //~5429R~
//		if (!(pft=functblsrch(FUNCID_PREVSCR)))                 //~5429R~
//			uerrexit("function:Prev-Panel is not defined",      //~5429R~
//				     	"�@�\:�O��� ����`����Ă��܂���");    //~5429R~
//      pft->FTkey[0]=0;	//f8 used by pgdn                   //~5429R~
//		if (!(pft=functblsrch(FUNCID_BLOCK)))                   //~5429R~
//			uerrexit("function:Block-Start/End is not defined", //~5429R~
//				     	"�@�\:�u���b�N�n�_/�I�_ ����`����Ă��܂���");//~5429R~
//      pft->FTkey[0]=KEY_S_F7;	//f8 used by pgdn               //~5429R~
//                                                              //~5429R~
//	}                                                           //~5429R~
    Gfunctbl=Sfunctbl;                                          //~5429I~
    funct2init(0,Postype);                                         //~v705R~
//#ifdef UNX                                                       //~v55kR~
//    if (Gudbcschk_flag & UDBCSCHK_EUC)                           //~v55kR~
//        for (pft=Sfunctbl;*(pft->FTnamee);pft++)    //all ft entry//~v55kR~
//        {                                                        //~v55kR~
//            pc=pft->FTnamej;                                     //~v55kR~
//            len=(int)strlen(pc);                                 //~v55kR~
//            if (len)                                             //~v55kR~
////              ushift2euc(pc,len,pc,0,0);  //no dbcstbl,no hankana//~v55kR~
//                ushift2euc(pc,0,len,pc,0,0,0);  //no dbcstbl,no hankana//~v55kR~
//        }                                                        //~v55kR~
//#endif                                                           //~v55kR~
}//functinit                                                    //~5429R~
#ifdef UNX                                                         //~v55kI~
void functsjis2euc(void)                                           //~v55kR~
{                                                                  //~v55kI~
#ifdef LNX                                                         //~va1JI~
  	FUNCTBL *pft;                                                  //~v55kI~
    char *pc;                                                      //~v55kI~
    int len;                                                       //~v55kI~
    char eucfuncname[64];   //avoid unpredictable override         //~v61tI~
//************************************                             //~v55kI~
    kbdcvkeyname2euc();    //kbd table japanese conversion         //~v69AI~
//  if (Gudbcschk_flag & UDBCSCHK_EUC)                             //~v79zR~
    if (XE_ISDBCSJ())      //euc,euc-utf8                          //~v79zI~
        for (pft=Sfunctbl;*(pft->FTnamee);pft++)    //all ft entry //~v55kI~
        {                                                          //~v55kI~
            if (UCBITCHK(pft->FTflag, FTFEUC))                     //~v61tR~
                continue;                                          //~v61tI~
            pc=pft->FTnamej;                                       //~v55kI~
//          len=(int)strlen(pc);                                   //~v61tR~
            len=(int)ustrnlen(pc,sizeof(pft->FTnamej));            //~v61tI~
            if (len)                                               //~v55kI~
            {                                                      //~v61tI~
//              ushift2euc(pc,0,len,pc,0,0,0);  //no dbcstbl,no hankana//~v61tR~
                ushift2euc(pc,0,len,eucfuncname,0,&len,0);  //no dbcstbl,no hankana//~v61tR~
//              len=min(len,sizeof(pft->FTnamej));                 //~v61tI~//~vb2DR~
                len=min(len,(int)sizeof(pft->FTnamej));            //~vb2DI~
                strncpy(pc,eucfuncname,(UINT)len);                 //~v61tI~
            	UCBITON(pft->FTflag,FTFEUC);                       //~v61tI~
            }                                                      //~v61tI~
        }                                                          //~v55kI~
#endif                                                             //~va1JI~
}//functeucconv                                                    //~v55kI~
#endif                                                             //~v55kI~
                                                                //~5424I~
//**************************************************            //~5429I~
//*get copyed functbl addr                                      //~5429I~
//*parm: none                                                   //~5429I~
//*return:malloc copyed functbl                                 //~5429I~
//**************************************************            //~5429I~
FUNCTBL *functgetcopy(void)                                     //~5501R~
{                                                               //~5429I~
  	FUNCTBL *pft;                                               //~5429I~
//************************************                          //~5429I~
	pft=UALLOCM(sizeof(Sfunctbldefault));                       //~v04dR~
    memcpy(pft,Sfunctbl,sizeof(Sfunctbldefault));//copy of current//~5501R~
    functreset();                                               //~5501M~
    Smallocsw=1;                                                //~5429I~
	Sfunctbl=pft;                                               //~5429I~
	return Sfunctbl;                                            //~5429I~
}//functgetcopy                                                 //~5501R~
                                                                //~5429I~
//**************************************************            //~5429I~
//*termination                                                  //~5429I~
//*parm: functbl addr                                           //~5429I~
//*return:none                                                  //~5429I~
//**************************************************            //~5429I~
void functterm(void)                                            //~5429I~
{                                                               //~5429I~
//************************************                          //~5429I~
	functreset();                                               //~5501R~
	return;                                                     //~5429I~
}//functterm                                                    //~5429I~
                                                                //~5429I~
//**************************************************            //~5501I~
//*reset copyed functbl                                         //~5501I~
//*parm: none                                                   //~5501I~
//*return:none                                                  //~5501I~
//**************************************************            //~5501I~
void functreset(void)                                           //~5501I~
{                                                               //~5501I~
//************************************                          //~5501I~
	if (Smallocsw)                                              //~5501I~
    	ufree(Sfunctbl);                                        //~v04dR~
	Sfunctbl=(void*)Sfunctbldefault;                            //~5501I~
    Smallocsw=0;                                                //~5501I~
	return;                                                     //~5501I~
}//functreset                                                   //~5501I~
                                                                //~5501I~
//**************************************************            //~5424M~
//*functbl search by funcid                                     //~5424M~
//*parm1: funcid                                                //~5424M~
//*rc   : FUNCTBL ptr or null if not found                      //~5424M~
//**************************************************            //~5424M~
FUNCTBL *functblsrch(int Pfuncid)                               //~5424M~
{                                                               //~5424M~
	FUNCTBL *pft;                                               //~5424M~
//************************************                          //~5424M~
	for (pft=Sfunctbl;*(pft->FTnamee);pft++)	//all ft entry  //~5424M~
	{                                                           //~5424M~
		if (pft->FTfuncid==Pfuncid)                             //~5424M~
        {                                                       //~5424M~
			if (!UCBITCHK(pft->FTflag,FTFEONLY|FTFJONLY))	//common//~5424M~
				return pft;                                     //~5424M~
//  		if (UCBITCHK(Gscrstatus,GSCRSDBCS))	//sbcs   mode      //~v705R~
//  		if (UCBITCHK(Gscrstatus,GSCRSDBCS) 	//dbcs   mode      //~v79zR~
    		if (XE_ISDBCSJ()  	//dbcs   mode                      //~v79zR~
			&&  !(Guerropt & GBL_UERR_FORCEENG))     //not english mode test//~v705I~
			{                                                   //~5424M~
				if (UCBITCHK(pft->FTflag,FTFJONLY))	//japanese  //~5424M~
					return pft;                                 //~5424M~
			}                                                   //~5424M~
            else		//english mode                          //~5424M~
				if (UCBITCHK(pft->FTflag,FTFEONLY))	//english   //~5424M~
					return pft;                                 //~5424M~
        }                                                       //~5424M~
	}                                                           //~5424M~
	return 0;                                                   //~5424M~
}//functblsrch                                                  //~5424M~
//**************************************************               //~vbvcI~
//*functbl 2nd entry search by funcid                              //~vbvcI~
//*parm1: funcid                                                   //~vbvcI~
//*rc   : FUNCTBL ptr or null if not found                         //~vbvcI~
//**************************************************               //~vbvcI~
FUNCTBL *functblsrch2nd(int Pfuncid,FUNCTBL *Ppft1st)              //~vbvcR~
{                                                                  //~vbvcI~
	FUNCTBL *pft=0;                                                //~vbvcI~
//************************************                             //~vbvcI~
	for (pft=Sfunctbl;*(pft->FTnamee);pft++)	//all ft entry     //~vbvcI~
	{                                                              //~vbvcI~
    	if (pft==Ppft1st)                                          //~vbvcI~
        	continue;                                              //~vbvcI~
		if (pft->FTfuncid==Pfuncid)                                //~vbvcI~
			break;                                                 //~vbvcI~
	}                                                              //~vbvcI~
    UTRACEP("%s:exit pft=%p\n",UTT,pft);                           //~vbvcR~
	return pft;                                                    //~vbvcI~
}//functblsrch2nd                                                  //~vbvcI~
                                                                //~5429I~
//**************************************************            //~5429I~
//*functbl search by funcname                                   //~5429I~
//*parm1: funcname                                              //~5429I~
//*ret  : FUNCTBL ptr or null if not found                      //~5430R~
//**************************************************            //~5429I~
FUNCTBL *functblsrchbyname(UCHAR *Pfuncname)                    //~5429I~
{                                                               //~5429I~
	FUNCTBL *pft;                                               //~5429I~
//************************************                          //~5429I~
    if (!strcmp(Pfuncname,CAPRGN_OLD))                             //~vbi5I~
    	Pfuncname=CAPRGN_NEW;                                      //~vbi5I~
	for (pft=Sfunctbl;*(pft->FTnamee);pft++)	//all ft entry  //~5429I~
	{                                                           //~5429I~
      if (pft->FTfuncid>FUNCID_GRAPHCHAR                           //~v71QR~
      &&  !memicmp(Pfuncname,pft->FTnamee,GRAPHCHAR_FUNCIDLEN))    //~v71QR~
		return pft;                                                //~v71QI~
      else                                                         //~v71QI~
      {                                                            //~v71QI~
		if (!stricmp(Pfuncname,pft->FTnamee)                    //~5501R~
		||  !stricmp(Pfuncname,pft->FTnamej))                   //~5501R~
			return pft;                                         //~5429I~
      }                                                            //~v71QI~
	}                                                           //~5429I~
	return 0;                                                   //~5429I~
}//functblsrchbyname                                            //~5429I~
//**************************************************               //~v67CI~
//*functbl search by cmd verb                                      //~v67CI~
//*parm1: cmd verb                                                 //~v67CI~
//*ret  : FUNCTBL ptr or null if not found                         //~v67CI~
//**************************************************               //~v67CI~
FUNCTBL *functblsrchbycmd(UCHAR *Pcmd)                             //~v67CI~
{                                                                  //~v67CI~
	FUNCTBL *pft;                                                  //~v67CI~
//************************************                             //~v67CI~
    for (pft=Sfunctbl;*pft->FTnamee;pft++)  //all ft entry         //~v67CI~
    {                                                              //~v67CI~
        if (*pft->FTcmd                                            //~v67CI~
            && !stricmp(Pcmd,pft->FTcmd))                          //~v67CI~
            return pft;                                            //~v67CI~
        if (*pft->FTcmda    //same len as alias                    //~v67CI~
            && !stricmp(Pcmd,pft->FTcmda))                         //~v67CI~
            return pft;                                            //~v67CI~
    }//all ft entry                                                //~v67CI~
    return 0;                                                      //~v67CI~
}//functblsrchbycmd                                                //~v67CI~
