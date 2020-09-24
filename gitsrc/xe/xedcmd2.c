//*CID://+vbrdR~:                             update#=  649;       //~vbrdR~
//************************************************************* //~v051I~
//*xedcmd2.c                                                       //~v58JR~
//* xprint,system,submit,spawn                                     //~v51XR~
//************************************************************* //~v051I~
//vbrd:200801 (ARM)del wxp cmd because print dialog not supported  //~vbrdI~
//vba5:170716 (Bug)did not chk spawn rc                            //~vba5I~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb72:161212 (Win10) missing error.h , use winerror.h             //~vb72I~
//vb4u:160812 lineopt should be cleared when back to menu from file panel//~vb4uI~
//vb3A:160625 for compiler warning,-Wformat-security(not literal printf format)//~vb3yI~
//vb3y:160623 (Bug)wxp command;add /tabon option                   //~vb3yI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vazw:150115 pid on Win64 is intptr_t                             //~vazwR~
//vazq:150113 use ulib ufseek/uftell for common to 32/64 bit       //~vazqI~
//vavQ:140405 set parsed cmdlc(for xprint dcmd u8filename)         //~vavQI~
//vavM:140405 (W32UNICODE)xfc/xdc by spawn(because cmd propt translate filename to bestfit)//~vavMI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vaug:140311 (BUG)wxp cmd,display utf8 filename on dialog(mojibake if dbcs)//~vaugI~
//vamE:131119 (BUG)"xpr *" fails by "TAB parm is invalid for recfm=R/V//~vamEI~
//vajd:130806 scr print tabslip=1 for bin file                     //~vajdI~
//vajc:130806 specify FFXxx(rep 0x0c by Xxx) for scrprint          //~vajcI~
//vaj9:130724 (BUG)-Rnn parm required for record mode file         //~vaj9I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafg:120616 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafgI~
//vafe:120612 BUG found by chk uninitialized variable warning by gcc 4.1.1 on FC5//~vafeI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vafe:120612 BUG found by chk uninitialized variable warning by gcc 4.1.1 on FC5//~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va87:100924 (WXE)wxp cmd;**/*** vhex print corespondency of upper and lower line//~va87I~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va7T:100909 cpeb converter parm support:for xprint               //~va7TI~
//va5K:100522 (WXE:BUG)wxp cmd abend if filename is not */**/***   //~va5KI~
//va57:100429 dlcmd "p" support utf8 file using profile            //~va57I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va2k:100104 (BUG)wxp **(original filename is utf8,but printed as lc)//~va2kI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            dcmd2.c :xprint utf8 parameter                       //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va0K:090930_set xprint temp file timestamp if not updated        //~va0KI~
//va0C:090721_set wxp work CPxx to the same as source file         //~va0CI~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH;define MAXPARMSZ)//~va03I~
//v79P:081020 SO lock by fopen is not effective, use lock file     //~v79PI~
//v79N:081020 expand max SO file. 10->36                           //~v79NI~
//v79u:080908 xfg ^*\ fail whe dirname embedding space             //~v79uI~
//v9@5:080717 3270:TSO FS mode;draw update line only for performance//~v9@5R~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v781:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v781I~
//v77y:080118 *\/^* support for dos cmd                            //~v77yR~
//v76t:070707 (Wine)try cmd /c for pause to create new session under wine for wxe//~v76tI~
//v76s:070706 (Wine)redirect ">>&1" is syntax err; ">&1" is valid  //~v76sI~
//            last digit of "filename>redirect" treated as fileno  //~v76sI~
//v765:070531 (LNX:BUG)support "Konsole" as one of X-terminal      //~v765I~
//v764:070531 (LNX:BUG)"Hit any key" is printed always 2nd line    //~v764I~
//            printf now effective by the reason why ?(not by v20K i tryed).//~v764I~
//            But refresh is required(this is reason of print is not effective?)//~v764I~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v70r:060826 sub cmd;set stdin redirect to protect hung by wait kbd input//~v70rI~
//v65a:050727 msg change;redirect file full by orphaned lock file for redirect//~v65aI~
//v656:050726 (XXE)xxe support;WXP cmd                             //~v656I~
//v64z:050709 (LNX)support DOS cmd sh operand(>sh,DOS sh) to create child terminal(no col/row option support)//~v64zI~
//v64x:050709 (LNX)xxe support;spawn rc is pid;change display msg  //~v64xI~
//v64r:050630 (XXE)xxe support;child shell                         //~v64rI~
//v64q:050624 (WXE)child shell dose not stop when cmd is .bat or .cmd;use cmd && @pause for call and @pause//~v64qI~
//v64f:050619 (LNX)xxe support;sub shell dose not override current x scr//~v64fI~
//v648:050617 system cmd call rc=1 is needed for grep to chk notfound condition//~v648I~
//v63c:050429 change dcmd stdout file(::so) to use pid for contension inter user//~v63cI~
//v638:050428 change xprint temp file to use pid for contension inter user//~v638I~
//v636:050428 new workdir filename naming ::#((pid).xxx) for grep work filename//~v636I~
//v626:050309 (WXE)for wxp **/***(set space lineno for cont line)  //~v626I~
//v625:050309 vhex mode support for wxp **/***(line split no consideration)//~v625I~
//v624:050309 vhex mode support for xpr **/***(line split consideration)//~v624I~
//v622:050309 (BUG)xpr **/*** lineno size should be refrect current size//~v622I~
//v61y:050308 (WXE:BUG of V595)force text mode because work save line contain lineo fld//~v61yI~//~va81R~
//v61w:050308 xprint on vhex mode                                  //~v61wI~
//v61i:050226 csrsetwait is not require for syscmd(func_cmd already issued)//~v61iI~
//v60u:050201 xpr cmd;add -tabon option to write tab display char(default istaboff)//~v60uI~
//            (tab display char may not be printed and line is shorten)//~v60uI~
//v59R:041128 (BUG)redirect ignored when no space before/after ">" //~v59RI~
//v59Q:041127 (BUG)append mode redirect require fseek not only fopen("a")//~v59QI~
//v59J:041121 (BUG)of v59m;abend by "DOS" enter                    //~v59JI~
//v59F:041121 chng cmd name,exp/xen-->set/env and issue dos cmd when no opd under cmd panel//~v59FI~
//v59m:041113 (BUG of v58P)cmd fail if no operand                  //~v59mR~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v596:041103 (WXE)wxp cmd:err chk optional parameter(/px etc is not effective for wxp)//~v596I~
//v595:041103 (WXE:BUG)wxp cmd:xp work file is opend as binary even if original is text mode//~v595I~
//v593:041102 split xedcmd2-->xedcmd3(submit,rsh)                  //~v593I~
//v592:041031 rsh cmd support                                      //~v592I~
//v58P:041017 dcmd:redirect stderr to stdout when only stdout is redirected//~v58PI~
//v58M:041017 (BUG)xprint redirect parm is treated as outfilename,the open err//~v58MI~
//            so reject rediect parm                               //~v58MI~
//v58J:041011 append mode redirect support                         //~v58JI~
//v58H:041011 redirect stderr to stdout when only stdout is specified//~v58HI~
//v58G:041011 cmd log write to mocmd panel only(not on redirect file)//~v58GI~
//v58F:041011 display on cmd panel not redirected stdout or stderr only//~v58FI~
//v58D:041011 (BUG) input cmd is not displayed on cmd panel        //~v58DI~
//v58C:041011 (WXE:BUG) cmd with redirect output on cmd panel pass cmd to syscmd process//~v58CI~
//            "cmd >redirect >>::so";then redirect is ignored.     //~v58CI~
//v58B:041009 redirec should be ">>" to padd output to cmd text(bug of v58q)//~v58BI~
//v58q:040923 (BUG)submit child shell dose not wait key enter      //~v58qI~
//            (as v142,Enter key genarate 0a1c after 0d1c)         //~v58qI~
//v58f:040828 (WXE:BUG)call stmt required for activate @pause after shell cdm//~v58fI~
//v58e:040828 (WXE:BUG)submit cmd loop because using same tmp filename to execute//~v58eI~
//v57B:040605 xpr dir support                                      //~v57BI~
//v57t:040531 xprint err when filename is embedding space and parm is enclosed by quote//~v57tI~
//v57s:040530 (FTP)xpr dcmd support                                //~v57sI~
//v56y:040415 (WIN:BUG)"dir" cmd without operand open child shell  //~v56yI~
//v55p:040222 (WXE)use comman server to avoid dos prompt screen appear//~v55pI~
//v55f:040211 (FTP:BUG)submit abend when filename opd is remote(no editmode)//~v55fI~
//v552:040202 identify wxp ** by prefix filename like as xprint    //~v552I~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v53Z:031223 (WIN,UNX)ftp support;no vfat alias(always long)      //~v53ZI~
//v53V:031115 (WIN,UNX)ftp support;submit to own system from remote file//~v53VI~
//v52a:030823 submit:no ext chk(ex dir cmd has no ext)             //~v52aI~
//v528:030823 (BUG of v51v) too many opd err msg                   //~v528I~
//v521:030817 (BUG)spawn cmd abend when no operand specified       //~v521I~
//v51X:030810 submit cmd redirect file parm support                //~v51XI~
//v51v:030615 add SPAwn cmd(ASYNC DOS cmd) for explorer kick       //~v51vI~
//v50M:030208 dos cmd;save/restore buffsz parm to ini file         //~v50MI~
//v50L:030208 dos cmd help                                         //~v50LI~
//v50D:030125 DOS CMD; buffsz parm support                         //~v50DI~
//v50C:030125 chng DOS SUB-->DOS CMD                               //~v50CI~
//v50w:030118 (WIN)DOS cmd "sub"  option support;create new process and leave it.//~v50wR~
//v500:030103 (WXE)dos cmd(<cmd) support                           //~v500I~
//v500:021027 (WXE)stdout/stderr redirect fail                     //~v500I~
//v499:020622 (BUG)xprint * faile when dir name has intermediate space//~v499I~
//v445:011201 binary file support for xprint **/***                //~v40ZI~
//v40Z:010728 UNX:skip env COMSPEC chk                             //~v40ZI~
//v40n:010603 XPR */** label support                               //~v40nI~
//v40m:010603 LINUX support:command flag                           //~v40nI~
//v40k:010526 screen current print("***")                          //~v40kR~
//v40j:010526 (BUG)prtscr for partial loaded file.                 //~v40jI~
//                 (start plh required to skip partial prosess at filesave)//~v40jI~
//v40i:010526 different spawn spec;unix is same as gcc             //~v40iI~
//v40h:010526 xprint **;like as print screen                       //~v40hR~
//v40g:010526 LINUX support:/W-->-W missed at v20A                 //~v40gI~
//v40c:010407 issue errmsg when no filename for xprint             //~v40cI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v21f:010107 LINUX support:so file lock is not avail by open for linux//~v21fI~
//v21d:010106 LINUX support:small letter filename                  //~v21dI~
//v219:001209 LINUX support:screen clear by white space under mono color mode//~v219I~
//v20M:001105 (BUG)avoid submit under func-key screen              //~v20MI~
//v20L:001105 LINUX support:/K parm is invalid when linux          //~v20LI~
//v20K:001104 LINUX support:set and restore echo/raw before/after shell mode//~v20KI~
//v20J:001104 LINUX support:CMD-->shell name "sh"(temporary)       //~v20JI~
//v20H:001104 LINUX support:printf ignored in ncurses mode(dos cmd:"hit any key" msg)//~v20HI~
//v20A:001029 LINUX support:(BUG)too may operand msg;by flag chk("/") process//~v20AI~
//v20h:001015 LINUX support("*"(all member) confirmation           //~v20hI~
//v19E:000904 LINUX support(like XE!UNDEL-->XE_UNDEL; ! has mean to bash)//~v19EI~
//v197:000902 LINUX support(uextchk dropped:submit cmd filename chk)//~v197I~
//v193:000902 LINUX support(skip hdr include)                      //~v193I~
//v13k:991029 (BUGof v11M)xprint * may miss update version.        //~v11kI~
//v11M:990828 dcmd xprint;filename=* should be current status(updated).//~v11MI~
//v11C:990821 required *\ process for valid errmsg of v11r         //~v11CI~
//v11r:990730 xprint dcmd:curr file print by * for filename  *\ for cur dir//~v11rI~
//v0k4:981128 SUBmit cmd                                           //~v0k4I~
//v0hj:980214 (BUG:DOS under WinNT)WinNT version DOS shell dose not support//~v0hjI~
//            /K (command execute and do not exit).                //~v0hjI~
//            so ignore init cmd parm(default "propmt $p$l")       //~v0hjI~
//v0hi:980201 over v0hh,csr set is requierd for DOS                //~v0hiI~
//v0g3:971210 os/dos spwanvp concatibnate parm and re-evaluate     //~v0g3I~
//            so use spaunlp for dosd/os2/win,use spawnvp for gcc  //~v0g3I~
//v0g2:971210 use uparsecmd for dos cmd                            //~v0g2I~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0fy:971130 (BUG)%n parm on xprint cmd text is not effective.    //~v0fyI~
//                 %2,%3 etc is deleted if requested one by one to ucmdparmedit//~v0fyI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0a7:970706:csr wait for cmd crom result edit last line          //~v0a7I~
//v0a5:970705:(BUG)abend when space only on cmd result area cmd    //~v0a5I~
//v0a4:970705:ignore null cmd(len=0) to avoid "" ended msg         //~v0a4I~
//v09u:970524:(BUG)-path and comspec mismatch case,">" cmd return  //~v09uR~
//                  with DOS version mismatch                      //~v09uI~
//                 -W95 only,csr type inherit to chile shell,      //~v09uI~
//                  so need reset before system call.              //~v09uI~
//                  but,if box csr(it may be ins or rep mode by .ini)//~v09uI~
//                  before call system,ins key dose not chage csr type by//~v09uI~
//                  ins key.so need set underline csr before system call.//~v09uI~
//                  That is for DOS/GCC under windows95.           //~v09uI~
//v09t:970523:(OS/2 BUG)need re-init kbd binary mode after child shell//~v09tR~
//                      first kbdinput may be shift report if bynaly mode//~v09tI~
//v09s:970523:(BUG)force csr write after child shell               //~v09sI~
//            (csrwrite bypass write if position not changed)      //~v09sI~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//            drop pcw parm not used on scrcsrtyperestore          //~v09lI~
//            ,no need to type restore because it is done at func_cmd//~v09lI~
//v095:970405:DPMI version                                         //~v095I~
//            -spawnlp-->spawnlv                                   //~v095I~
//             DOS accept "a b" as "a" "b",but gcc is not;cause xprint parm err//~v095I~
//             dcmd2.c(type chk char * and UCHAR *)                //~v095I~
//v08g:961106:split uvio to uvio and uvio2                         //~v08gI~
//v085:961024:W95 VC                                               //~v085I~
//v07d:960624:long cmd input at cmd result screen last line        //~v07dI~
//v073:960602:csr on the cmd line for menu opt 6 both normal/error case//~v073I~
//           :cmd result time stamp edit.no preceding space time(upper char for hhmm)//~v073I~
//v072:960602:(BUG)reset cursor type changed by cmd shell          //~v072I~
//v071:960602:(BUG)menu opt 6 screen first line is of OS/2 screen, //~v072I~
//            redraw first split part                              //~v072I~
//v06F:960420:work ::SO start from ::SO not from ::SO!             //~v06FI~
//v06D:960407:accept not found cmd as DOS cmd when menu 6 screen   //~v06DI~
//v06B:960407:set so filename on last msg                             //~v06BI~
//v06A:960407:allow rc=255 for usystem                                //~v06AI~
//v06z:960407:stdout work last used seqno save to xe!SAVE!            //~v06zI~
//            xe.h ini3.c dcmd2.c                                     //~v06zI~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06yI~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//v06x:960406:save so file(no delete at term)                         //~v06xI~
//v06u:960406:cmd so screen:lineno color for input cmd echo line      //~v06uI~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v066:960217:cursor move to top when call shell(need when splitted)//~v066I~
//v063:960217:sub shell prompt                                  //~v063I~
//v061:960211:SHELL cmd(CMD,COM,>>)                             //~v061I~
//v05M:960113:(BUG)xprint /Yb option must precede to all(ex. /? etc)//~v05MI~
//v05C:960104:(BUG)xprint cmd cause abend when no operand       //~v05CI~
//v05x:951216:redirected work dir file(>::xxx <::yyy etc) for dos cmd//~v05aI~
//            xprint workdir file                               //~v05aI~
//v05a:951104:xprint cmd string by ini file                     //~v05aI~
//v059:951028:xprint background option,/Wdir                    //~v059R~
//v056:951015:general DOS command                               //~v056I~
//v051:951014:print dlcmd                                       //~v051I~
//************************************************************* //~v051I~
#include <time.h>                                               //~v051I~
#include <stdio.h>                                              //~v051I~
#include <stddef.h>                                             //~v051I~
#include <stdlib.h>                                             //~v051I~
#include <ctype.h>                                              //~v051I~
#include <string.h>                                             //~v051I~
#include <errno.h>                                              //~v051I~
#ifdef UNX                                                         //~v197R~
	#include <termios.h>                                           //~v40bI~
#else                                                              //~v197I~
#include <process.h>                                            //~v051I~
  #ifdef W32                                                       //~v55fI~
	#include <io.h>    		//for _A_SUBDIR etc                    //~v55fI~
  #endif                                                           //~v55fI~
#endif                                                             //~v193I~
                                                                //~v051I~
#ifdef DOS                                                      //~v051I~
#else                                                           //~v051I~
    #ifdef W32                                                     //~v085I~
//      #include <windows.h>                                       //~v085I~
      #ifdef WIN10                                                   //+v6BkI//~vb72I~
	    #include <winerror.h>                                      //~vb72I~
      #else                                                        //~vb72I~
        #include <error.h>                                         //~v71gI~
      #endif                                                       //~vb72I~
    #else                                                          //~v085I~
    #define INCL_BASE                                           //~v051I~
    #include <os2.h>                                            //~v051I~
    #endif                                                         //~v085I~
#endif                                                          //~v051I~
//*******************************************************       //~v051I~
#include <ulib.h>                                               //~v051I~
#include <uerr.h>                                               //~v051I~
#include <uque.h>                                               //~v051I~
#include <ualloc.h>                                             //~v051I~
#include <ufile.h>                                              //~v051I~
#include <ufile2.h>                                             //~v06nI~
#include <ufile3.h>                                                //~v53VI~
#ifdef UNX                                                         //~v197I~
    #include <ufile2l.h>                                           //~v197I~
    #include <uviol.h>                                             //~v20HI~
    #include <ukbdl.h>                                             //~v20KI~
	#include <uunxsub.h>                                           //~v21fI~
#endif                                                             //~v197I~
#include <ufile4.h>     //ugetvfatalias                            //~v79PI~
#include <ufile5.h>     //ugetvfatalias                            //~v0g1I~
#include <ufemsg.h>                                                //~v095I~
#include <uproc.h>                                              //~v051I~
#include <uproc2.h>                                                //~v58CI~
#include <uedit.h>                                              //~v051I~
#include <ukbd.h>                                               //~v061I~
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <uvio.h>                                               //~v063I~
#include <uvio2.h>                                                 //~v08gI~
#include <utrace.h>                                                //~v09tI~
#include <udos.h>                                                  //~v0hjI~
#include <ucvebc.h>                                                //~va7TI~
#include <ucvext.h>                                                //~va7TI~
#include <ucvebc4.h>                                               //~va7TI~
#ifdef FTPSUPP                                                     //~v53VI~
    #include <uftp.h>                                              //~v53ZR~
    #include <ufile1f.h>                                           //~v55fI~
    #include <u3270.h>                                             //~v8@sR~
#endif                                                             //~v53VI~
#include <ufilew.h>                                                //~vavQI~
                                                                //~v051I~
#include "xe.h"                                                 //~v051I~
#include "xescr.h"                                              //~v051I~
#include "xescr2.h"                                                //~v072I~
#include "xefunc.h"                                             //~v051I~
#include "xeerr.h"                                              //~v051I~
#include "xefile.h"                                             //~v06nI~
#include "xefile12.h"                                              //~v0k4I~
#include "xefile2.h"                                                  //~v06tI~
#include "xesub.h"                                                 //~v74xM~
#include "xepan.h"                                                    //~v06nI~
#include "xelcmd.h"                                                   //~v06tI~
#include "xecap.h"                                                    //~v06tI~
#include "xecsr.h"                                                 //~v07dI~
#include "xekbd.h"                                                 //~v09tI~
#include "xedir.h"                                                 //~v11MI~
#include "xedcmd.h"                                                //~v11MI~
#define  XEDCMD2_GLOBAL                                            //~v50MI~
#include "xedcmd2.h"                                               //~v11MM~
#include "xedcmd4.h"                                               //~v636I~
#include "xefcmd22.h"                                              //~v40nI~
#include "xefcmd3.h"                                               //~v40nI~
#include "xefcmd6.h"                                               //~v8@2I~
#ifdef WXE                                                         //~v54yI~
	#include "wxexei.h"                                            //~v54yI~
#endif                                                             //~v54yI~
#ifdef XXE                                                         //~v656I~
	#include "xxexei.h"                                            //~v656I~
#endif                                                             //~v656I~
#include "xeftp.h"                                                 //~v57sI~
#include "xedlcmd.h"                                               //~v57BI~
#include "xedlcmd3.h"                                              //~v57BI~
#include "xetso.h"                                                 //~v8@sR~
#include "xeebc.h"                                                 //~va57I~
#include "xeopt.h"                                                 //~va7TI~
#include "xeutf.h"                                                 //~vaugI~
#include "xeutf2.h"                                                //~vaugI~
#include "xefsubw.h"                                               //~vavQI~
//****************************************************************//~v051I~
//#define MAXSONO      10                                          //~v79NR~
#define MAXSONO        36                                          //~v79NI~
//#define MAXTEMP      6                                           //~v63cR~
//#define TEMPIDPOS    4                                           //~v63cR~
                                                                   //~v21dI~
#ifdef UNX                                                         //~v21dI~
//	#define TEMPID       '_'                                       //~v63cR~
	#define STDOUTERRF   "so"                                      //~v21dI~
#else  //!UNX                                                      //~v21dI~
//#define TEMPID       '!'                                         //~v63cR~
#define STDOUTERRF   "SO"                                       //~v051R~
#endif //!UNX                                                      //~v21dI~
                                                                   //~v21dI~
//#define TEMPCMDFNM   "XE!TEMP"                                   //~v19ER~
//#define TEMPCMDFNM   "XE_TEMP"                                   //~v638R~
#define WXETEMPCMDFNM   "wxe_tmp"                                  //~v58eI~
#define XXETEMPCMDFNM   "xxe_tmp"                                  //~v64fI~
//#define XPTEMPWK     "::XE!XPWK!"                                //~v19ER~
//#define XPTEMPWK     "::XE_XPWK_"                                //~v638R~
                                                                   //~v20JI~
#ifdef UNX                                                         //~v20JI~
    #define SHELLNAME "sh"                                         //~v20JI~
#else  //!UNX                                                      //~v20JI~
#if defined(DOS) || defined(W32)                                   //~v085R~
    #define SHELLNAME "COMMAND"                                 //~v061M~
#else                                                           //~v061M~
    #define SHELLNAME "CMD"                                     //~v061M~
#endif                                                          //~v061M~
#endif //!UNX                                                      //~v20JI~
//#ifdef WXE                                                       //~v58HR~
//  #define STR_REDIRECT  " >> "                                   //~v58qR~
//  #define STR_REDIRECT  " > "                                    //~v58JR~
//  #define STR_REDIRECT2  " 2>&1"                                 //~v58FR~
//#endif                                                           //~v58HR~
#define CHAR_REDIRECT  '>'                                         //~v58JI~
#define STR_REDIRECT2  "2>"                                        //~v58FI~
#define STR_REDIRECT21  "&1"                                       //~v58FI~
//#ifdef UTF8UCS2                                                    //~va20I~//~va57R~
//    #define XPUTF8OPT   "Mu"                                       //~va20I~//~va57R~
//#endif                                                             //~va20I~//~va57R~
//****************************************************************//~v051I~
static UCHAR Sstdoef[]=WORKDIRPATHID STDOUTERRF "%d";              //~v54yR~
static UCHAR Sshellname[]=SHELLNAME;                            //~v061R~
//static UCHAR Sshellinitcmd[]=" /K echo ";                     //~v061R~
//static UCHAR Scurfilesave[]=XPTEMPWK;                            //~v638R~
static UCHAR Scurfilesave[]=DCMDXPRINTTEMPFNM;                     //~v638I~
//static char *Sredirectfnm=0;	//parm to dcmdsystemcall from submit//~v58FR~
                                                                   //~v21fI~
//#ifdef UNX                                                       //~v79PR~
	static char Slockfnm[_MAX_PATH];                               //~v21fI~
#ifdef UNX                                                         //~v79PI~
	static char Slockfnm2[_MAX_PATH];                              //~v21fI~
#endif                                                             //~v21fI~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
//  static char Swxpfnm[_MAX_PATH+3];                              //~v595R~
//  static char Swxpfnm[_MAX_PATH+8]; //"*----" /mh\0              //~v595I~//~va81R~
    static char Swxpfnm[_MAX_PATH+MAX_CSNAMESZ+32]; //"*----" /mh\0//~va81R~
	static int  Swxpsw=0;                                          //~v54yI~
	static int  Swxptabctr;                                        //~v8@2I~
#endif                                                             //~v54yI~
#ifdef FTPSUPP                                                     //~v57BI~
	static int Sremotegetsw=0;                                     //~v57BI~
#endif                                                             //~v57BI~
int	Scmdbyspawn;                                                   //~vavMI~
//****************************************************************//~v051I~
//int dcmdsystemcall(PUCLIENTWE Ppcw,char *Pcmd);                  //~v58FR~
//int dcmdsystemcall(PUCLIENTWE Ppcw,char *Pcmd,int Pflag,char *Pstdofnm,char *Pstdefnm);//~v593R~
//int dcmdsystemcall_intf(PUCLIENTWE Ppcw,UCHAR *Pcmd);            //~v59FR~
int dcmdwkdiredit(UCHAR *Pcmd,char  **Ppout);                      //~v095R~
int dcmdxpfnmchk(PUCLIENTWE Ppcw,UCHAR *Pcmd,UCHAR  **Ppout);      //~v11MR~
int dcmderrcurfile(void);                                          //~v11rI~
//int dcmdsolast(UCHAR *Psofname,UCHAR *Pfname,int Prc);           //~v593R~
//int dcmdappendso(PUCLIENTWE Ppcw,UCHAR *Psofname,UCHAR *Pcmd);   //~v593R~
int dcmdgetsofname2(UCHAR *Psofname,UCHAR *Pfullpath,FILE **Ppfileh,UCHAR *Pcmd);//~v06zI~
int dcmdnowork(void);                                                 //~v06zI~
//int dcmdextnmerr(void);                                          //~v51XR~
int dcmdextnmerr(char *Pfnm);                                      //~v51XI~
int dcmdxprlblerr(void);                                           //~v57sR~
//int dcmdputcmdlog(FILE *Pfh,char *Pcmd);                         //~v58GR~
//int dcmdputcmdlog(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt,char *Pcmd);//~v59gR~
#ifdef UNX                                                         //~v21fI~
	void dcmdfresetlock2(void);                                    //~v21fI~
#endif                                                             //~v21fI~
	int dcmdparseredirect(PUCLIENTWE Ppcw,char *Pcmd,char *Pfpathstdo,char *Pfpathstde,int *Ppflag,int *Ppcmdlen);//~v58DR~
//  int dcmdeditredirect(int Popt,UCHAR **Ppcmd,char *Pfnm,char *Pstdefnm);//~v593R~
#ifdef WXE                                                         //~v58DM~
//  int dcmdeditredirect(UCHAR **Ppcmd,char *Pfnm);                //~v58CR~
	int dcmdwxe1cmd(char *repcmd);                                 //~v500R~
#endif                                                             //~v500I~
#ifdef XXE                                                         //~v64fI~
	int dcmdxxe1cmd(char *Pcmd);                                   //~v64fI~
#endif                                                             //~v64fI~
#ifdef FTPSUPP                                                     //~v57BI~
//	int dcmdcpgetremotecopy(char *Prfnm,PUFTPHOST Ppuftph,char *Pltemp);//~v57BI~//~vb7eR~
  	int dcmdcpgetremotecopy(char *Prfnm,PUFTPHOST Ppuftph,char *Pltemp,size_t Pbuffsz);//~vb7eI~
#endif                                                             //~v57BI~
//int dcmdredirectparmerr(void);                                   //~v593R~
int dcmd_fpathredirect(PUCLIENTWE Ppcw,char *Pfnmstdo,char *Pfnmstde);//~v592I~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
//**************************************************************** //~v54yI~
//!print by wxe                                                    //~v54yI~
//*ret  :rc                                                        //~v54yI~
//**************************************************************** //~v54yI~
int dcmd_wxp(PUCLIENTWE Ppcw)                                      //~v54yI~
{                                                                  //~v54yI~
#ifdef ARM                                                         //~vbrdI~
	return errnotsupported("wxp","Axe");                           //+vbrdR~
#else                                                              //~vbrdI~
	PUCLIENTWE pcw;                                                //~v54yI~
	PUFILEH pfh;                                                   //~v54yI~
	PUFILEC pfc;                                                   //~va87R~
	int rc,ftype,len;                                              //~v54yR~
    int opt=0;                                                     //~v552I~
    int editopt=0;                                                 //~v595I~
	UCHAR *cmdstr0,*cmdstr,*orgfnm=0;                              //~v656R~
	char *pc;                                                      //~v596I~
    int ii;                                                        //~v596I~
    UCHAR  wkedithandle[MAX_CSNAMESZ+32];                          //~va81R~
#ifdef LNX                                                         //~vaugI~
//  UCHAR  wkfnmu8[_MAX_PATH*UTF8_MAXCHARSZ];                      //~vaugR~//~vav9R~
    UCHAR  wkfnmu8[_MAX_PATHU8];                                   //~vav9I~
#endif                                                             //~vaugI~
#ifdef W32UNICODE                                                  //~vav9I~
	PUFILEH pfhorg=NULL;                                           //~vav9I~
#endif                                                             //~vav9I~
    char wkcmdstr[64];                                             //~vb3yI~
    int swtabon=0;                                                 //~vb3yR~
//*******************                                              //~v54yI~
    if (!(cmdstr0=Ppcw->UCWparm))                                  //~v54yI~
    {                                                              //~v54yI~
//      uerrmsg("wxp { {filename | * | **} [ .lab1 .lab2] } | ***",0);//~v54yI~//~vb3yR~
        uerrmsg("wxp { {filename | * | **} [ .lab1 .lab2] } | *** [-tabon]",0);//~vb3yI~
        return 4;                                                  //~v54yI~
    }                                                              //~v54yI~
    for (pc=Ppcw->UCWopdpot,ii=Ppcw->UCWopdno;ii;pc+=strlen(pc)+1,ii--)//~v596R~
    {                                                              //~v596I~
        if (*pc=='/' || *pc=='-')                                  //~v596I~
        {                                                          //~vb3yI~
            if (!strcmp(pc+1,"tabon"))                             //~vb3yI~
            	swtabon=1;                                         //~vb3yI~
            else                                                   //~vb3yI~
			return errinvalid(pc);                                 //~v596I~
        }                                                          //~vb3yI~
    }                                                              //~v596I~
    if (swtabon)                                                   //~vb3yI~
    {                                                              //~vb3yI~
        if (!strcmp(cmdstr0,"**")||strcmp(cmdstr0,"***"))          //~vb3yR~
        {                                                          //~vb3yR~
        	sprintf(wkcmdstr,"%s -tabon",cmdstr0);                 //~vb3yR~
            cmdstr0=wkcmdstr;                                      //~vb3yR~
        }                                                          //~vb3yR~
        else                                                       //~vb3yI~
        {                                                          //~vb3yI~
            uerrmsg("tabon option is for \"**\"/\"***\" only",     //~vb3yI~
                    "tabon オプションは \"**\"/\"***\"のときのみです");//~vb3yI~
            return 4;                                              //~vb3yI~
        }                                                          //~vb3yI~
    }                                                              //~vb3yI~
	*Swxpfnm=0;	//saved temp filename                              //~v54yI~
    Swxpsw=1;                                                      //~v54yI~
    rc=dcmdxpfnmchk(Ppcw,cmdstr0,&cmdstr);   //process *\,::,* for input file//~v54yR~
    Swxpsw=0;                                                      //~v54yI~
    if (rc)                                                        //~v54yI~
        return rc;                                                 //~v54yM~
    if (cmdstr!=cmdstr0)        //malloced                         //~v54yI~
        ufree(cmdstr);                                             //~v54yI~
    ftype=*Swxpfnm;                                                //~v54yI~
    editopt=0;                                                     //~v595I~
    pfh=0;                                                         //~va5KI~
    pfc=Ppcw->UCWpfc;   //may be null                              //~va87I~
    if (ftype)	//external file or **/*** print work file          //~v54yR~
    {                                                              //~v54yI~
        if (ftype=='*')	//print through print work                 //~v54yI~
        {                                                          //~v54yM~
            pfh=UGETPFHFROMPCW(Ppcw);                              //~v54yI~
#ifdef W32UNICODE                                                  //~vavQI~
            pfhorg=pfh;	//contains org filename                    //~vav9I~
#endif                                                             //~vavQI~
            orgfnm=pfh->UFHfilename;                               //~v54yI~
#ifdef LNX                                                         //~vaugR~
            if (pfh->UFHfilenamedddata)                            //~vaugR~
            {                                                      //~vaugI~
            	UCHAR *pu8;                                        //~vaugR~
                int u8len,rc3;                                     //~vaugI~
                //******************                               //~vaugI~
            	rc3=xeutfcvdd2f(0,pfh->UFHfilenamedddata,pfh->UFHfilenamedddbcs,pfh->UFHfilenameddlen,&pu8,&u8len,NULL/*outdbcs*/);//~vaugI~
                if (rc3<4)                                         //~vaugI~
                {                                                  //~vaugI~
//                	UmemcpyZ(wkfnmu8,pu8,u8len);                   //~vaugI~//~vb30R~
                  	UmemcpyZ(wkfnmu8,pu8,(size_t)u8len);           //~vb30I~
                	orgfnm=wkfnmu8;                                //~vaugI~
                }                                                  //~vaugI~
            }                                                      //~vaugI~
#else                                                              //~vaugI~
            if (pfh->UFHfilenamebylc)                              //~va2kI~
                orgfnm=pfh->UFHfilenamebylc;	//print headerline filename//~va2kI~
#endif                                                             //~vamEI~
            editopt=1;	//append /Mx option                        //~v595I~
        }                                                          //~v54yM~
        *Swxpfnm='"';                                              //~v54yI~
        if (*(Swxpfnm+1)=='*')  //wxp ** option                    //~v552I~
        {                                                          //~v552I~
            strcpy(Swxpfnm+1,Swxpfnm+2);                           //~v552I~
//          opt=WXP_PRTSCR;                                        //~v552R~//~va87R~
            opt|=WXP_PRTSCR;                                       //~va87I~
        }                                                          //~v552I~
//      len=strlen(Swxpfnm);                                       //~v54yI~//~vb30R~
        len=(int)strlen(Swxpfnm);                                  //~vb30I~
        *(Swxpfnm+len++)='"';                                      //~v54yI~
        *(Swxpfnm+len)=0;                                          //~v54yI~
        if (editopt)                                               //~v595I~
        {                                                          //~v595I~
//          if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))   //hex display mode//~v61yR~
//              strcat(Swxpfnm," /MH");   //force hex  bode        //~v61yR~
//          else                                                   //~v61yR~
//          if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))   //binary file  //~v61yR~
//              strcat(Swxpfnm," /MB");   //force binary bode      //~v61yR~
//          else                                                   //~v61yR~
            if (!PFH_ISEBC(pfh))                                   //~va81I~
                strcat(Swxpfnm," /MT");   //force text   bode      //~v595R~
            opt|=(Ppcw->UCWlinenosz<<8);                           //~v626I~
        }                                                          //~v595I~
#ifdef UTF8SUPPH                                                   //~va1qI~
      if (pfh)                                                     //~va5KI~
      {                                                            //~va5KI~
//*for ebcd file;translated to lc at filesave by tabdisplayforxpr  //~va50I~
        if (UCBITCHK(pfh->UFHflag8,UFHF8UTF8))                     //~va0CI~
        	editopt|=(FEBFIO_CPU8|FEBFIO_UTF8IE);                  //~va0CR~
        else                                                       //~va0CI~
        if (PFH_ISEBC(pfh))                                        //~va81R~
        {                                                          //~va81R~
        	if (pfh->UFHhandle)                                    //~va81R~
            	sprintf(wkedithandle," %s:%s -Me",MODE_EBC,ucvebc4_getcvname(0,pfh->UFHhandle));//~va81R~
            else                                                   //~va81R~
            	sprintf(wkedithandle," %s: -Me",MODE_EBC);         //~va81R~
            strcat(Swxpfnm,wkedithandle);   //force text   bode    //~va81R~
        }                                                          //~va81R~
        else                                                       //~va81R~
        	editopt|=FEBFIO_CPLC;                                  //~va0CR~
        if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                     //~va87I~
            opt|=WXP_VHEX;                                         //~va87R~
      }                                                            //~va5KI~
#endif                                                             //~va1qI~
    	Ppcw->UCWparm=Swxpfnm;                                     //~v54yR~
//  	if (rc=func_edit_file2(Ppcw,0),rc)                         //~v595R~
    	if (rc=func_edit_file2(Ppcw,editopt),rc)                   //~v595I~
	    	return rc;                                             //~v54yI~
        pcw=scrgetcw(0);                                           //~v54yR~
        pfh=UGETPFHFROMPCW(pcw);                                   //~v54yI~
        if (ftype=='*')	//print through print work                 //~v54yI~
        {                                                          //~v8@2I~
        	pfh->UFHtype=UFHTWXPWK;                                //~v54yR~
			pfh->UFHtabskip=(UCHAR)Swxptabctr;	//printwork tabctr from original file//~v8@2I~//~vazwR~
        }                                                          //~v8@2I~
    }                                                              //~v54yI~
//  rc=wxe_wxpreq(orgfnm);                                         //~v552R~
//  rc=wxe_wxpreq(opt,orgfnm);                                     //~v552I~//~va87R~
#ifdef W32UNICODE                                                  //~vav9I~
    rc=wxe_wxpreq(opt,orgfnm,pfh,pfhorg);                          //~vav9I~
#else                                                              //~vav9I~
    rc=wxe_wxpreq(opt,orgfnm,pfh);                                 //~va87I~
#endif                                                             //~vav9I~
    return rc;                                                     //~v54yI~
#endif                                                             //~vbrdI~
}//dcmd_wxp                                                        //~v54yI~
#endif //!ARM                                                             //~v54yI~//~vbrdR~
//****************************************************************//~v051I~
//!xprint command                                               //~v051R~
//*ret  :rc                                                     //~v051I~
//****************************************************************//~v051I~
int dcmd_xprint(PUCLIENTWE Ppcw)                                //~v051I~
{                                                                  //~v57BI~
	int dcmd_xprintsub(PUCLIENTWE);                                //~v57BR~
	int rc;                                                        //~v57BI~
//*********************                                            //~v57BI~
#ifdef FTPSUPP                                                     //~v57BI~
	Sremotegetsw=0;                                                //~v57BI~
#endif                                                             //~v57BI~
	rc=dcmd_xprintsub(Ppcw);                                       //~v57BR~
#ifdef FTPSUPP                                                     //~v57BI~
    if (Sremotegetsw)                                              //~v57BR~
    	rc+=dlcxpdelremotetemp();                                  //~v57BR~
#endif                                                             //~v57BI~
    return rc;                                                     //~v57BI~
}//dcmd_xprint                                                     //~v57BI~
int dcmd_xprintsub(PUCLIENTWE Ppcw)                                //~v57BI~
{                                                               //~v051I~
#ifdef UNX                                                         //~v20AI~
static char Sxpopt[]=" -Yb" ;       //additional xprint option     //~v20AI~
#else  //!UNX                                                      //~v20AI~
static char Sxpopt[]=" /Yb" ;       //additional xprint option     //~v0fyI~
#endif //!UNX                                                      //~v20AI~
    UCHAR fpath[_MAX_PATH];                                        //~v57tR~
    UCHAR fpathstde[_MAX_PATH];                                    //~v58MI~
    UCHAR sofname[2+MAXFILENAME+1];                                   //~v06BR~
    UCHAR wkdir[2+_MAX_PATH+1+sizeof(Sxpopt)];                     //~v0fyR~
//  UCHAR  *parm,*pgm;                                             //~v095R~
    char   *parm,*pgm;                                             //~v095R~
#ifdef WXE                                                         //~v500I~
    char   *pgm2;                                                  //~v500I~
#endif                                                             //~v500I~
    UCHAR  *cmdstr0,*cmdstr;                                       //~v11rI~
    int rc,actsw=0,crc;                                         //~v056R~
    int redirectsw,netcmdlen;                                      //~v58MI~
//#ifdef DPMI                                                      //~v40iR~
#if defined(DPMI) || defined(UNX)                                  //~v40iI~
    int opdno=0;    //init for comiler warning                     //~v0g3R~
    char   **argv=0;                 //spawnvp parm                //~v0g3I~
#endif                                                             //~v0g3I~
    FILE *fh;                                                   //~v051R~
//static char *Sxpopt="/Yb" ;       //additional xprint option     //~v0fyR~
//    char *parmv[3];                                              //~v0g2R~
//*******************                                           //~v051I~
//  if (!Ppcw->UCWparm)                                            //~v11rR~
    if (!(cmdstr0=Ppcw->UCWparm))                                  //~v11rI~
    {                                                              //~v40nI~
//      return errmissing();                                       //~v40nR~
//      uerrmsg("xpr { { {filename | * | **} [ .lab1 .lab2] } | ***} [xprint-parms]",0);//~v60uR~
        uerrmsg("xpr { filespec | * | ** | *** } [-tabon] [.lab1 .lab2] [xprint-parms]",0);//~v60uR~
        return 4;                                                  //~v40nI~
    }                                                              //~v40nI~
//  if (uprocparseredirect(Ppcw->UCWparm,fpath,fpathstde,&redirectsw,&netcmdlen))//~v70rR~
    if (uprocparseredirect(Ppcw->UCWparm,0,fpath,fpathstde,&redirectsw,&netcmdlen))//~v70rI~
		return dcmdredirectparmerr();                              //~v58MI~
    if (*fpath||*fpathstde)                                        //~v58MI~
    {                                                              //~v58MI~
//      uerrmsg("redirection is not supported for xprint cmd.",    //~v61wR~
//      		"xprintコマンドでリダイレクト指定はできません。"); //~v61wR~
        uerrmsg("redirection is not supported for xprint cmd,specify output-filename-parm.",//~v61wI~
        		"xprintコマンドでリダイレクト指定はできません、出力ファイル名パラメータを指定してください。");//~v61wI~
        return 4;                                                  //~v58MI~
    }                                                              //~v58MI~
//    if (rc=ucmdparmedit(Gxprintcmd,Sxpopt,&parm),rc)//concat     //~v0fyR~
//        return rc;                                               //~v0fyR~
//    rc=ucmdparmedit(parm,Ppcw->UCWparm,&pgm);                    //~v0fyR~
//    ufree(parm);                                                 //~v0fyR~
//    if (rc)                                                      //~v0fyR~
//        return rc;                                               //~v0fyR~
#ifdef UNX                                                         //~v20AI~
    strcpy(wkdir,"-W");                                            //~v20AI~
#else  //!UNX                                                      //~v20AI~
    strcpy(wkdir,"/W");                                         //~v059I~
#endif //!UNX                                                      //~v20AI~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
  #if defined(W32)                                                 //~v53ZI~
    if (uftpisremote(Gworkdir,0))	//remote filename              //~v53ZI~
      strcat(wkdir,Gworkdir);                                      //~v53ZI~
    else                                                           //~v53ZI~
  #endif                                                           //~v53ZI~
    if (UCBITCHK(Gopt4,GOPT4W95ALIASP))//use short filename parm   //~v0g1I~
        ugetvfatalias(0,Gworkdir,wkdir+2,_MAX_PATH);               //~v0g1R~
    else                                                           //~v0g1I~
#endif                                                             //~v0g1I~
    strcat(wkdir,Gworkdir);                                     //~v059I~
    strcat(wkdir,Sxpopt);                                          //~v0fyR~
//  rc=ucmdparmedit(pgm,wkdir,&parm);//concat                      //~v0fyR~
//  ufree(pgm);                                                    //~v0fyR~
//  if (rc)                                                        //~v0fyR~
//      return rc;                                                 //~v0fyR~
//  rc=ucmdparmedit(Gxprintcmd,pgm,&parm);//edit into cmd text     //~v0fyR~
//  ufree(pgm);                                                    //~v0fyR~
//    parmv[0]=Ppcw->UCWparm;     //file name or "/Yi filename"    //~v0g2R~
//    parmv[1]=wkdir;             // /W and /Yb                    //~v0g2R~
//    parmv[2]=0;                 //terminator                     //~v0g2R~
//    rc=ucmdparmedit(Gxprintcmd,0,parmv,&parm);//edit into cmd text//~v0g2R~
//  rc=ucmdparmedit(1,Gxprintcmd,Ppcw->UCWparm,0,&pgm);//padd when not used//~v11rR~
    if (rc=dcmdxpfnmchk(Ppcw,cmdstr0,&cmdstr),rc)   //process *\,::,* for input file//~v11MR~
        return rc;                                                 //~v11rI~
    rc=ucmdparmedit(1,Gxprintcmd,cmdstr,0,&pgm);//padd when not used//~v11rI~
    if (cmdstr!=cmdstr0)        //* replaced                       //~v11rI~
        ufree(cmdstr);                                             //~v11rR~
    if (rc)                                                        //~v0fyI~
        return rc;                                                 //~v0fyI~
    rc=ucmdparmedit(1,pgm,wkdir,0,&parm);//add forced parm         //~v0g2R~
    ufree(pgm);                                                    //~v0g2R~
    if (rc)                                                        //~v0g2R~
        return rc;                                                 //~v0g2R~
//    if (dcmdgetsofname2(sofname,fullpath,&fh,parm)) //get stdout work//~v0g2R~
//    {                                                            //~v0g2R~
//        ufree(parm);                                             //~v0g2R~
//        return 4;                                                //~v0g2R~
//    }                                                            //~v0g2R~
    if (rc=dcmdwkdiredit(parm,&pgm),rc)  //replace ::           //~v05xR~
    {                                                           //~v05xR~
        ufree(parm);                                            //~v05xR~
        return 4;       //malloc failed                         //~v05xR~
    }                                                           //~v05xR~
    if (pgm!=parm)  //replaced :: to new buff                   //~v05xR~
        ufree(parm);                                            //~v05xR~
//  if (parm=strchr(pgm,' '),parm)  //space found                  //~v095R~
//      *parm++=0;                                                 //~v095R~
    if (dcmdgetsofname2(sofname,fpath,&fh,pgm))  //get stdout work,and write cmd text to it//~v57tR~
    {                                                              //~v0g2R~
        ufree(pgm);                                                //~v0g2R~
        return 4;                                                  //~v0g2R~
    }                                                              //~v0g2R~
#ifdef WXE                                                         //~v500I~
//  fclose(fh);                                                    //~v58JR~
    pgm2=pgm;                                                      //~v500I~
//  rc=dcmdeditredirect(&pgm2,fpath);                              //~v58CR~
    rc=dcmdeditredirect(0,&pgm2,fpath,STR_REDIRECT21); //no append mode,no stderr//~v58MR~
    ufree(pgm);                                                    //~v500I~
    if (rc)                                                        //~v500I~
    	return 4;                                                  //~v500I~
    pgm=pgm2;                                                      //~v500I~
//  crc=rc=usystem(pgm);                                           //~v55pR~
    crc=rc=usystem2(0,pgm); //use cmd server if setup ok           //~v55pI~
#else                                                              //~v500I~
//  rc=uparsev(pgm,(UCHAR***)(&argv),&opdno,0,0);   //create argv format//~v0g2R~
//    parm=0;             //req malloc to parm                     //~v0g3R~
//#ifdef DPMI                                                      //~v0g3R~
//    rc=uparsecmd(UPCMD_DROPQ,pgm,&opdno,&parm,&argv,0);//no delmt//~v0g3R~
//#else                                                            //~v0g3R~
//    rc=uparsecmd(UPCMD_ASIS,pgm,&opdno,&parm,&argv,0);//no delmt //~v0g3R~
//#endif                                                           //~v0g3R~
//    ufree(pgm);                                                  //~v0g3R~
//    if (rc) //uparsev err                                        //~v0g3R~
//        return 4;                                                //~v0g3R~
//#ifdef DPMI                                                      //~v40iR~
#if defined(DPMI) || defined(UNX)                                  //~v40iI~
    parm=0;             //malloc req                               //~v0g3I~
    rc=uparsecmd(UPCMD_DROPQ,pgm,&opdno,&parm,&argv,0);//no delmt  //~v0g3I~
    ufree(pgm);                                                    //~v0g3I~
    if (rc) //uparsev err                                          //~v0g3I~
        return 4;                                                  //~v0g3I~
    pgm=parm;                                                      //~v0g3I~
#endif                                                             //~v0g3I~
    if (!(fh=uredirect(3,fpath,fh))) //append stdin/stderr to so file//~v57tR~
    {                                                           //~v051I~
//      ufree(pgm);                                                //~v095R~
//      ufree(argv);                                               //~v0g2R~
//      ufree(parm);                                               //~v0g3R~
        ufree(pgm);                                                //~v0g3I~
        return 4;                                               //~v051I~
    }                                                           //~v051I~
//#ifdef DPMI                                                      //~v40iR~
#if defined(DPMI) || defined(UNX)                                  //~v40iI~
    crc=rc=uspawnvp(P_WAIT,argv[0],argv);                          //~v0g3I~
#else                                                              //~v0g3I~
    parm=strchr(pgm,' ');                                          //~v0g3I~
    if (parm)                                                      //~v0g3I~
        *parm++=0;                                                 //~v0g3R~
//  crc=rc=uspawnlp(P_WAIT,pgm,pgm,parm,NULL);                     //~v095R~
//    crc=rc=uspawnvp(P_WAIT,argv[0],argv);                        //~v0g3R~
//  crc=rc=uspawnlp(P_WAIT,pgm,pgm,parm,NULL);                     //~vazwR~
    crc=rc=(int)uspawnlp(P_WAIT,pgm,pgm,parm,NULL);//WAIT dose not return pid(intptr_t)//~vazwR~
//    ufree(pgm);                                                  //~v095R~
//    ufree(argv);                                                 //~v0g2R~
//    ufree(parm);                                                 //~v0g3R~
#endif                                                             //~v0g3M~
#endif   //!WXE                                                    //~v500I~
    if (rc!=-1)                                                 //~v051I~
        actsw=1;                                                //~v051R~
    else                                                        //~v056I~
        rc=8;   //-1 mean quit                                  //~v056I~
#ifdef WXE                                                         //~v500I~
#else                                                              //~v500I~
    if (uredirectrestore(3))                                    //~v051I~
        rc=4;                                                   //~v051I~
#endif                                                             //~v500I~
    ufree(pgm);                                                    //~v0g3M~
#ifdef WXE                                                         //~v500I~
#else                                                              //~v500I~
    fclose(fh);                                                 //~v051I~
#endif                                                             //~v500I~
    if (actsw)                                                  //~v051R~
        rc+=dcmdsolast(sofname,fpath,crc);                         //~v57tR~
#ifdef UNX                                                         //~v21fI~
	dcmdfresetlock2();                                             //~v21fR~
#endif                                                             //~v21fI~
    return rc;                                                  //~v051I~
}//dcmd_xprint                                                  //~v051I~
                                                                //~v051I~
//****************************************************************//~v051I~
//!print command                                                //~v051I~
//*ret  :rc                                                     //~v051I~
//****************************************************************//~v051I~
int dcmd_print(PUCLIENTWE Ppcw)                                 //~v051I~
{                                                               //~v051I~
//  UCHAR  *cmd;                                                   //~v095R~
    char   *cmd;                                                   //~v095I~
    int rc;                                                     //~v056R~
//*******************                                           //~v051I~
    if (!Gprintcmd) //no ini specification                         //~v07dR~
        return dcmd_xprint(Ppcw);                               //~v051I~
//  if (rc=ucmdparmedit(Gprintcmd,Ppcw->UCWparm,&cmd),rc)//edit %n //~v0fyR~
//  if (rc=ucmdparmedit(Gprintcmd,Ppcw->UCWparm,0,&cmd),rc)//edit %n//~v0g2R~
    if (rc=ucmdparmedit(1,Gprintcmd,Ppcw->UCWparm,0,&cmd),rc)//edit %n,add not used//~v0g2R~
        return rc;                                              //~v051I~
//  rc=dcmdsystemcall(Ppcw,cmd);                                   //~v58FR~
    rc=dcmdsystemcall_intf(Ppcw,cmd);                              //~v58MR~
    ufree(cmd);                                                 //~v051I~
    return rc;                                                  //~v051I~
}//dcmd_print                                                   //~v051I~
                                                                //~v051I~
//**************************************************************** //~v07dI~
//!detect last line cmd on cmd result screen                       //~v07dI~
//   called from func_exec_pan(xepan2.c)                           //~v07dI~
//*parm :pcw                                                       //~v07dI~
//*ret  :rc                                                        //~v07dI~
//**************************************************************** //~v07dI~
int dcmdlongcmd(PUCLIENTWE Ppcw)                                   //~v07dI~
{                                                                  //~v07dI~
    PULINEH plh;               //last line of cmd edit             //~v07dR~
    PUFILEH pfh;                                                   //~v07dI~
    int     rc,len;                                                //~v07dI~
    UCHAR   *pc,*pcdata;                                           //~v07dR~
//*******************                                              //~v07dI~
    pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v07dI~
    plh=UGETQPREV(UGETQEND(&pfh->UFHlineque));                     //~v07dR~
    if (!plh->ULHlen            //no cmd                           //~v07dR~
    ||  !UCBITCHK(plh->ULHflag3,ULHF3CMDECHO))  //no cmd input line//~v07dR~
        return 0;                                                  //~v07dI~
    pcdata=plh->ULHdata;                                           //~v07dI~
//  len=(int)strspn(pcdata," ");                                   //~v0a5R~
    len=(int)ustrnspn(pcdata," ",(UINT)plh->ULHlen);               //~v0a5R~
    pcdata+=len;                                                   //~v07dI~
    len=plh->ULHlen-len;                                           //~v07dI~
    if (!ustrnlen(pcdata,(UINT)len))                               //~v0a4I~
        return 0;                                                  //~v0a4M~
    pc=UALLOCM((UINT)(1+len));                                     //~v07dI~
    UALLOCCHK(pc,UALLOC_FAILED);                                   //~v07dI~
    memcpy(pc,pcdata,(UINT)len);                                   //~v07dR~
    *(pc+len)=0;        //string                                   //~v07dI~
    Ppcw->UCWparm=pc;                                              //~v07dR~
    csrsetwait(1);      //set wait mode csr if now not wait        //~v0a7I~
    rc=dcmd_system(Ppcw);                                          //~v07dR~
    csrsetwait(0);      //set wait mode csr if now not wait        //~v0a7I~
    ufree(pc);                                                     //~v07dI~
    if (rc)                                                        //~v07dI~
        filesetcsr(Ppcw,plh,1,0);   //set csr to top of line data  //~v07dI~
    else                                                           //~v07dI~
        csrhomepos(0);  //move csr to 1st fld of current active    //~v07dI~
    return rc;                                                     //~v07dI~
}//dcmdlongcmd                                                     //~v07dI~
//**************************************************************** //~v58MI~
//!setup parse block and call dcmdsystemcall                       //~v58MR~
//*parm :pcw                                                       //~v58MI~
//*ret  :rc                                                        //~v58MI~
//**************************************************************** //~v58MI~
int dcmdsystemcall_intf(PUCLIENTWE Ppcw,UCHAR *Pcmd)               //~v58MR~
{                                                                  //~v58MI~
    UCHAR stdofnm[_MAX_PATH],stdefnm[_MAX_PATH],*pstdo,*pstde;     //~v58MR~
    int     rc,redirectflag,netcmdlen;                             //~v58MR~
//*******************                                              //~v58MI~
//  if (uprocparseredirect(Pcmd,stdofnm,stdefnm,&redirectflag,&netcmdlen))//~v70rR~
    if (uprocparseredirect(Pcmd,0,stdofnm,stdefnm,&redirectflag,&netcmdlen))//0:no stdin//~v70rI~
		return dcmdredirectparmerr();                              //~v58MI~
    *(Pcmd+netcmdlen)=0;                                           //~v58MI~
//  csrsetwait(1);      //set wait mode csr if now not wait        //~v61iR~
    pstdo=stdofnm;                                                 //~v58MI~
//  if (*stdefnm)                                                  //~v58PR~
    	pstde=stdefnm;                                             //~v58MI~
//  else                                                           //~v58PR~
//  	pstde=0;	//no redirection to ::SO(print to scr)         //~v58PR~
	rc=dcmdsystemcall(Ppcw,Pcmd,redirectflag,pstdo,pstde);         //~v58MR~
//  csrsetwait(0);      //set wait mode csr if now not wait        //~v61iR~
    return rc;                                                     //~v58MI~
}//dcmdsystemcall_intf                                             //~v58MR~
//**************************************************************** //~v51vI~
//*not throu dos prompt for win-app                                //~v51vI~
//*ret  :rc                                                        //~v51vI~
//**************************************************************** //~v51vI~
int dcmd_spawn(PUCLIENTWE Ppcw)                                    //~v51vI~
{                                                                  //~v51vI~
    char *pc,*parm,**argv;                                         //~v51vI~
    int rc,opdno;                                                  //~v51vI~
    LONGHANDLE ph;                                                 //~vazwR~
    ULONG pid;                                                     //~vazwI~
//*******************                                              //~v51vI~
    pc=Ppcw->UCWparm;                                              //~v51vI~
//  if (pc && !stricmp(pc,"?"))                                    //~v521R~
    if (!pc || !stricmp(pc,"?"))                                   //~v521I~
    {                                                              //~v51vI~
        uerrmsg("SPA cmd-name [cmd-args]",0);                      //~v51vI~
		return 0;                                                  //~v51vI~
    }                                                              //~v51vI~
    parm=0;             //malloc req                               //~v51vI~
    rc=uparsecmd(UPCMD_DROPQ,pc,&opdno,&parm,&argv,0);//no delmt   //~v51vI~
    if (rc) //uparsev err                                          //~v51vI~
        return 4;                                                  //~v51vI~
//  rc=uspawnvp(P_NOWAIT|UPROC_NOMSG,argv[0],argv);                //~v781R~
//  rc=uspawnvp(P_NOWAIT|UPROC_NOMSG|UPROC_NULLSI,argv[0],argv);   //~vazwR~
    ph=uspawnvp(P_NOWAIT|UPROC_NOMSG|UPROC_NULLSI,argv[0],argv);   //~vazwR~
    pid=(ULONG)UGETPROCESSID(UGPIO_ERRMSG,ph);                     //~vazwR~
    rc=(int)pid;                                                   //~vazwR~
    IFDEF_WINCON(dcmdrestoreconsolemode(0));                       //~v781R~
    ufree(parm);                                                   //~v51vI~
//  uerrmsg("\"%s\" started,pid=%d",                               //~vazwR~
//  		"\"%s\" 起動,pid=%d",                                  //~vazwR~
//          pc,rc);                                                //~vazwR~
  if (rc>=0)                                                       //~vba5I~
    uerrmsg("\"%s\" started,pid=%d(0x%x)",                         //~vazwR~
    		"\"%s\" 起動,pid=%d(0x%x)",                            //~vazwR~
            pc,pid,pid);                                           //~vazwR~
    if (rc==-1)                                                    //~v51vR~
    	rc=4;                                                      //~v51vI~
    else                                                           //~v51vI~
    	rc=0;                                                      //~v51vI~
    return rc;                                                     //~v51vI~
}//dcmd_spawn                                                      //~v51vI~
#ifdef W32UNICODE                                                  //~vavMI~
//**************************************************************** //~vavMI~
//*from dcmdsystemcall_spawn                                       //~vavMI~
//*ret  :rc                                                        //~vavMI~
//**************************************************************** //~vavMI~
int dcmd_spawn_redirected(int Popt,char *Pcmd)                     //~vavMR~
{                                                                  //~vavMI~
    char *parm,**argv;                                             //~vavMR~
    int rc,opdno;                                                  //~vavMI~
//*******************                                              //~vavMI~
    parm=0;             //malloc req                               //~vavMI~
    rc=uparsecmd(UPCMD_DROPQ,Pcmd,&opdno,&parm,&argv,0);//no delmt //~vavMR~
    if (rc) //uparsev err                                          //~vavMI~
        return 4;                                                  //~vavMI~
//    {int ii;    //FIXME test stmt  :FIXED                          //~vavMR~//~vavQR~
//        for (ii=0;ii<opdno;ii++)                                   //~vavMR~//~vavQR~
//            UTRACED("parmv",argv[ii],strlen(argv[ii]));            //~vavMI~//~vavQR~
//    }                                                              //~vavMI~//~vavQR~
//  rc=uspawnvp(UPROC_NOMSG,argv[0],argv);                         //~vazwR~
    rc=(int)uspawnvp(UPROC_NOMSG,argv[0],argv);	//WAIT returns int status//~vazwR~
    ufree(parm);                                                   //~vavMI~
    return rc;                                                     //~vavMI~
}//dcmd_spawn_redirected                                           //~vavMI~
#endif                                                             //~vavMI~
//****************************************************************//~v056I~
//!other dos command                                            //~v056I~
//*ret  :rc                                                     //~v056I~
//****************************************************************//~v056I~
int dcmd_system(PUCLIENTWE Ppcw)                                //~v056I~
{                                                               //~v056I~
    UINT len;                                                      //~v06DR~
    char *pc;                                                      //~v06DR~
    UCHAR fpathstde[_MAX_PATH];                                    //~v58DI~
    UCHAR fpath[_MAX_PATH];                                        //~v58DI~
    UCHAR *pstde,*pstdo;                                           //~v58FI~
    int rc,netcmdlen,redirsw;                                      //~v58DR~
#ifdef W32                                                         //~v50DI~
	int scrcol=0,scrrow=0,opdno;                                   //~v50DI~
    ULONG buffsz;                                                  //~v50DI~
    char *pc2;                                                     //~v56yI~
#endif                                                             //~v50DI~
#ifdef LNX                                                         //~v64zI~
    char *pc2;                                                     //~v64zI~
#endif                                                             //~v64zI~
//*******************                                           //~v056I~
    pc=Ppcw->UCWparm;                                              //~v06DI~
    if (pc && !stricmp(pc,"?"))                                    //~v50LI~
    {                                                              //~v50LI~
#ifdef W32                                                         //~v50LI~
        uerrmsg("{DOS|>} [ ? | cmd-strings | CMD [ row [ col ] ] ]",0);//~v50LI~
#else                                                              //~v50LI~
  #ifdef LNX                                                       //~v64zI~
        uerrmsg("{DOS|>} [ ? | cmd-strings | sh [ termnal-options ] ]",0);//~v64zI~
  #else                                                            //~v64zI~
        uerrmsg("{DOS|>} [ ? | cmd-strings ]",0);                  //~v50LI~
  #endif                                                           //~v64zI~
#endif                                                             //~v50LI~
		return 0;                                                  //~v50LI~
    }                                                              //~v50LI~
#ifdef W32                                                         //~v50wI~
    pc2=pc;      //save pc                                         //~v56yI~
    pc=Ppcw->UCWopdpot;                                            //~v50DI~
    if (pc && !stricmp(pc,"CMD"))                                  //~v50CR~
    {                                                              //~v50DI~
//  	if (udosiswinnt())                                         //~v50MR~
//  	{                                                          //~v50MR~
            opdno=Ppcw->UCWopdno;   //no operand                   //~v50DI~
            scrrow=Gcmdbuffsz_row;  //old value                    //~v50MI~
            scrcol=Gcmdbuffsz_col;  //old value                    //~v50MI~
            if (opdno>=2)                                          //~v50DI~
            {                                                      //~v50DI~
                pc+=strlen(pc)+1;   //2nd parm                     //~v50DI~
                scrrow=atoi(pc);                                   //~v50DI~
                if (scrrow>255)                                    //~v50MI~
                	scrrow=255;                                    //~v50MI~
                if (scrrow)                                        //~v50DI~
                {                                                  //~v50DI~
            		Gcmdbuffsz_row=scrrow;  //old value            //~v50MI~
                    if (opdno>=3)                                  //~v50DI~
                    {                                              //~v50DI~
                        pc+=strlen(pc)+1;   //2nd parm             //~v50DI~
                        scrcol=atoi(pc);                           //~v50DI~
		                if (scrcol>255)                            //~v50MI~
        		        	scrcol=255;                            //~v50MI~
		            	Gcmdbuffsz_col=scrcol;  //old value        //~v50MI~
                    }                                              //~v50DI~
                }                                                  //~v50DI~
            }//buffsz parm exist                                   //~v50DI~
            if (scrrow && !scrcol)                                 //~v50MI~
            	scrcol=80;                                         //~v50MI~
            if (!scrrow)                                           //~v50MI~
            	scrcol=0;                                          //~v50MI~
//      }//NT                                                      //~v50MR~
      if (udosiswinnt())                                           //~v50MI~
        buffsz=((ULONG)scrcol<<16)|(ULONG)scrrow;                  //~v50DI~
      else                                                         //~v50MI~
        buffsz=0;                                                  //~v50MI~
    	return usystemcsh(0,buffsz);		//create child shell,no option//~v50DR~
    }                                                              //~v50DI~
    pc=pc2;      //save pc                                         //~v56yI~
#endif                                                             //~v50wI~
#ifdef LNX                                                         //~v64zI~
    pc2=Ppcw->UCWopdpot;                                           //~v64zI~
    if (pc2 && !stricmp(pc2,"sh"))                                 //~v64zR~
    	return (usystemlnxterm(pc)==-1)*4;		//kick term-sim options//~v64zR~
#endif                                                             //~v64zI~
//if (Ppcw->UCWopdpot)                                             //~v59RR~
  if (pc)                                                          //~v59RI~
  {                                                                //~v58PI~
//  if (uprocparseredirect(Ppcw->UCWparm,fpath,fpathstde,&redirsw,&netcmdlen))//~v70rR~
    if (uprocparseredirect(Ppcw->UCWparm,0,fpath,fpathstde,&redirsw,&netcmdlen))//0:no stdin//~v70rI~
		return dcmdredirectparmerr();                              //~v58HI~
  }                                                                //~v58PI~
  else                                                             //~v58PI~
  {                                                                //~v58PI~
//  *fpath=0;*fpathstde=0;redirsw=0;netcmdlen=0;                   //~v59mR~
    *fpath=0;*fpathstde=0;redirsw=0;                               //~v59mR~
//  netcmdlen=strlen(Ppcw->UCWparm);                               //~v59JR~
//  if (pc)                                                        //~v59RR~
//      netcmdlen=(int)strlen(Ppcw->UCWparm);                      //~v59RR~
//  else                                                           //~v59RR~
    	netcmdlen=0;                                               //~v59JI~
  }                                                                //~v58PI~
    if (!pc || Ppcw->UCWmenuopt!=PANMOCMD)  //not cmd pannel       //~v06DR~
    {                                                              //~v58DI~
//    	if (!udosiswinnt())		//win95/win98                      //~v58JR~
//      {                                                          //~v58JR~
            if (*fpath||*fpathstde)	//stdout redirec spcification  //~v58FR~
            {                                                      //~v58DI~
                pstdo=fpath;                                       //~v58MI~
//          	if (*fpathstde)                                    //~v58PR~
	                pstde=fpathstde;                               //~v58HR~
//              else                                               //~v58PR~
//              	pstde=0;  //no use ::SOn                       //~v58PR~
                *(Ppcw->UCWparm+netcmdlen)=0;                      //~v58DI~
	    		rc=dcmdsystemcall(Ppcw,Ppcw->UCWparm,redirsw,pstdo,pstde);//~v58FR~
                return rc;                                         //~v58DI~
            }                                                      //~v58DI~
//      }//win95/win98                                             //~v58JR~
        return dcmd_system2(Ppcw);                                    //~v06nI~
    }                                                              //~v58DI~
//  len=strlen(Sshellname);                                        //~v06DR~//~vb2ER~
    len=(UINT)strlen(Sshellname);                                  //~vb2EI~
    if (!memicmp(pc,Sshellname,len)                                //~v06DR~
    && (!*(pc+len) || *(pc+len)==' '))                             //~v06DR~
    {                                                              //~v06DR~
        pc+=len;                                                   //~v06DR~
        pc+=strspn(pc," ");                                        //~v06DR~
        Ppcw->UCWparm=pc;                                          //~v06DR~
        return dcmd_system2(Ppcw);                                 //~v06DR~
    }                                                              //~v06DR~
    *(Ppcw->UCWparm+netcmdlen)=0;                                  //~v58GR~
//  return dcmdsystemcall(Ppcw,Ppcw->UCWparm);                     //~v58FR~
    return dcmdsystemcall(Ppcw,Ppcw->UCWparm,redirsw,fpath,fpathstde);//cmd panel redirection//~v58HR~
}//dcmd_system                                                  //~v056I~
                                                                //~v056I~
//**************************************************************** //~vavMI~
//!dcmdsystemcall_spawn                                            //~vavMI~
//  redirect and spawn call                                        //~vavMI~
//**************************************************************** //~vavMI~
int dcmdsystemcall_spawn(int Popt,PUCLIENTWE Ppcw,char *Pcmd,int Pflag,char *Pstdofnm,char *Pstdefnm)//~vavMI~
{                                                                  //~vavMI~
    int rc;                                                        //~vavMI~
//**********************                                           //~vavMI~
#ifdef W32UNICODE                                                  //~vavMI~
	Scmdbyspawn=1;                                                 //~vavMI~
#endif                                                             //~vavMI~
	rc=dcmdsystemcall(Ppcw,Pcmd,Pflag,Pstdofnm,Pstdefnm);          //~vavMI~
	Scmdbyspawn=0;                                                 //~vavMI~
    return rc;                                                     //~vavMI~
}//dcmdsystemcall_spawn                                            //~vavMI~
//****************************************************************//~v056I~
//!dcmdsystemcall                                               //~v056I~
//  redirect and usystem() call                                 //~v056I~
//*parm1:pcw                                                    //~v056I~
//*parm2:cmd string                                             //~v056I~
//*parm3:append mode flag                                          //~v58HI~
//*parm4:stdout filename,if "" use ::SOn                           //~v58HI~
//*parm5:stderr filename,if "" use ::SOn                           //~v58HI~
//*ret  :rc                                                     //~v056I~
//****************************************************************//~v056I~
//int dcmdsystemcall(PUCLIENTWE Ppcw,char *Pcmd)                   //~v58FR~
int dcmdsystemcall(PUCLIENTWE Ppcw,char *Pcmd,int Pflag,char *Pstdofnm,char *Pstdefnm)//~v58FI~
{                                                               //~v056I~
    UCHAR fpath[_MAX_PATH];                                        //~v57tR~
    UCHAR fpathstde[_MAX_PATH];                                    //~v58FM~
//  UCHAR sofname[2+MAXFILENAME+1];                                //~v51XR~
    UCHAR sofname[2+_MAX_PATH+1];                                  //~v51XI~
//  UCHAR *repcmd;                                                 //~v095R~
    char  *repcmd;                                                 //~v095I~
    UCHAR *logcmd;                                                 //~v58PR~
#ifdef WXE                                                         //~v500I~
    char  *repcmd2;                                                //~v500I~
#endif                                                             //~v500I~
    int rc,actsw=0,crc;                                         //~v056R~
    int redirectallsw;                                             //~v58FR~
    FILE *fh;                                                   //~v056I~
    FILE *fh2;    //stderr                                         //~v58FI~
//  PUFILEH pfh;                                                      //~v06tR~
//*******************                                           //~v056I~
//  *sofname=0;     //need new so alloc                               //~v06tR~
//  if (Ppcw->UCWmenuopt==PANMOCMD) //not cmd pannel                  //~v06tR~
//  {                                                                 //~v06tR~
//      pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                        //~v06tR~
//      if (UGETQCTR(&pfh->UFHlineque)==2)                            //~v06tR~
//      {                                                             //~v06tR~
//          strcpy(sofname,pfh->UFHalias);                            //~v06tR~
//          strcpy(fullpath,pfh->UFHfilename);                        //~v06tR~
//      }                                                             //~v06tR~
//  }                                                                 //~v06tR~
//  if (!*sofname)  //need new so number                              //~v06tR~
//    if (Sredirectfnm)                                            //~v58HR~
//    {                                                            //~v58HR~
//#ifdef WXE                                                       //~v58HR~
//        netcmdlen=strlen(Pcmd);                                  //~v58HR~
//        *fpathstde=0;                                            //~v58HR~
//#endif                                                           //~v58HR~
//        if (*Sredirectfnm)  //parm to dcmd_system from submit    //~v58HR~
//        {                                                        //~v58HR~
//            if (!dcmdfullpath(Ppcw,fpath,Sredirectfnm))   //consider :://~v58HR~
//                return 4;                                        //~v58HR~
//            strcpy(sofname,Sredirectfnm);                        //~v58HR~
//            if (!(fh=fopen(fpath,"w")))                          //~v58HR~
//            {                                                    //~v58HR~
//                uerrmsg(" %s open failed,rc=%d",0,               //~v58HR~
//                        sofname,errno);                          //~v58HR~
//                return 4;                                        //~v58HR~
//            }                                                    //~v58HR~
//            dcmdputcmdlog(fh,Pcmd);                              //~v58HR~
//        }                                                        //~v58HR~
//        else                                                     //~v58HR~
//        {                                                        //~v58HR~
//            if (dcmdgetsofname2(sofname,fpath,&fh,Pcmd)) //get stdout work//~v58HR~
//                return 4;                                        //~v58HR~
//            strcpy(Sredirectfnm,sofname);   //return selected so filename//~v58HR~
//        }                                                        //~v58HR~
//    }                                                            //~v58HR~
//    else                                                         //~v58HR~
//    {                                                            //~v58HR~
//#ifdef WXE                                                       //~v58HR~
//        if (optredirect=dcmdparseredirect(Ppcw,Pcmd,fpath,fpathstde,&optredirect,&netcmdlen)) //get stdout,leave stde to cmd line//~v58HR~
//            return 4;                                            //~v58HR~
//      if (*fpath)              //stdo specified                  //~v58HR~
//      {                                                          //~v58HR~
//            if (!(fh=fopen(fpath,"w")))                          //~v58HR~
//            {                                                    //~v58HR~
//                uerrmsg(" %s open failed,rc=%d",0,               //~v58HR~
//                        fpath,errno);                            //~v58HR~
//                return 4;                                        //~v58HR~
//            }                                                    //~v58HR~
//            dcmdputcmdlog(fh,Pcmd);                              //~v58HR~
//            strcpy(sofname,fpath);                               //~v58HR~
//      }                                                          //~v58HR~
//      else                                                       //~v58HR~
//#endif                                                           //~v58HR~
//        if (dcmdgetsofname2(sofname,fpath,&fh,Pcmd)) //get stdout work//~v58HR~
//            return 4;                                            //~v58HR~
//    }                                                            //~v58HR~
	*sofname=0;                                                    //~v58FI~
	*fpath=0;                                                      //~v58FI~
	*fpathstde=0;                                                  //~v58FI~
    fh=0;                                                          //~v58FM~
    fh2=0;                                                         //~v58FM~
    redirectallsw=0;                                               //~v58FI~
    if (Pstdofnm && *Pstdofnm)                                     //~v58FI~
    {                                                              //~v58FI~
    	if (!dcmdfullpath(Ppcw,fpath,Pstdofnm))   //consider ::    //~v58FI~
        	return 4;                                              //~v58FI~
#ifndef WXE		//xesyscmd process redirect                        //~v58JI~
        if (Pflag & PRERC_STDOAPPEND)                              //~v58JI~
        {                                                          //~v59QI~
        	fh=fopen(fpath,"a");                                   //~v58JI~
          if (fh)                                                  //~v75JI~
//          fseek(fh,0,SEEK_END);//move ptr to EOF                 //~vazqR~
            ufseek(fh,0,SEEK_END);//move ptr to EOF                //~vazqI~
        }                                                          //~v59QI~
        else                                                       //~v58JI~
        	fh=fopen(fpath,"w");                                   //~v58JI~
        if (!fh)                                                   //~v58JI~
        {                                                          //~v58FI~
            uerrmsg(" %s open failed,rc=%d",0,                     //~v58FI~
                    fpath,errno);                                  //~v58FI~
            return 4;                                              //~v58FI~
        }                                                          //~v58FI~
#endif                                                             //~v58JI~
    }                                                              //~v58FI~
    if (Pstdefnm && *Pstdefnm)                                     //~v58FI~
    {                                                              //~v58FI~
        if (*Pstdefnm=='&')                                        //~v58FI~
        {                                                          //~v58FI~
        	redirectallsw=2;    //redirect all to parm file        //~v58FR~
			strcpy(fpathstde,STR_REDIRECT21);                      //~v58FI~
        }                                                          //~v58FI~
        else                                                       //~v58FI~
        {                                                          //~v58FI~
	    	if (!dcmdfullpath(Ppcw,fpathstde,Pstdefnm))   //consider :://~v58FR~
	        	return 4;                                          //~v58FR~
#ifndef WXE                                                        //~v58JI~
        	if (Pflag & PRERC_STDEAPPEND)                          //~v58JI~
            {                                                      //~v59QI~
            	fh2=fopen(fpathstde,"a");                          //~v58JR~
              if (fh2)                                             //~v75JI~
//          	fseek(fh2,0,SEEK_END);//move ptr to EOF            //~vazqR~
            	ufseek(fh2,0,SEEK_END);//move ptr to EOF           //~vazqI~
            }                                                      //~v59QI~
            else                                                   //~v58JI~
            	fh2=fopen(fpathstde,"w");                          //~v58JR~
            if (!fh2)                                              //~v58JR~
            {                                                      //~v58FI~
                uerrmsg(" %s open failed,rc=%d",0,                 //~v58FI~
                        fpathstde,errno);                          //~v58FR~
                return 4;                                          //~v58FI~
            }                                                      //~v58FI~
#endif                                                             //~v58JI~
        }                                                          //~v58FI~
    }                                                              //~v58FI~
    if (Pstdofnm && !*Pstdofnm) //stdout to ::SOn                  //~v58FR~
    {                                                              //~v58FI~
        if (dcmdgetsofname2(sofname,fpath,&fh,Pcmd)) //get stdout work//~v58FI~
            return 4;                                              //~v58FI~
    }                                                              //~v58FI~
    if ((Pstdefnm && !*Pstdefnm)) //stde to ::SOn                  //~v58HR~
    {                                                              //~v58FI~
//      if (Pstdofnm && !*Pstdofnm) //stdout to ::SOn              //~v58PR~
        if (Pstdofnm)               //stdout redirected            //~v58PI~
        {                                                          //~v58JI~
			strcpy(fpathstde,STR_REDIRECT21);                      //~v58JI~
        	redirectallsw=1;    //redirect all to ::SO             //~v58JI~
        }                                                          //~v58JI~
        else                                                       //~v58JI~
        {                                                          //~v58MI~
	        if (dcmdgetsofname2(sofname,fpathstde,&fh2,Pcmd)) //get stdout work//~v58MR~
	            return 4;                                          //~v58MR~
        }                                                          //~v58MI~
    }                                                              //~v58FI~
#ifdef WXE                                                         //~v500I~
//  if (fh)                                                        //~v58JR~
//    fclose(fh);                                                  //~v58JR~
//  if (fh2)                                                       //~v58JR~
//    fclose(fh2);                                                 //~v58JR~
#else                                                              //~v500I~
  if (redirectallsw)                                               //~v58FI~
  {                                                                //~v58FI~
    if (!(fh=uredirect(3,fpath,fh))) //append mode redirect        //~v57tR~
        return 4;                                               //~v056I~
  }                                                                //~v58FI~
  else                                                             //~v58FI~
  {                                                                //~v58FI~
  	if (*fpath)                                                    //~v58FI~
    {                                                              //~v58FI~
	    if (!(fh=uredirect(1,fpath,fh)))                           //~v58FI~
	        return 4;                                              //~v58FI~
    }                                                              //~v58FI~
  	if (*fpathstde)                                                //~v58FI~
    {                                                              //~v58FI~
	    if (!(fh2=uredirect(2,fpathstde,fh2)))                     //~v58PR~
	        return 4;                                              //~v58FI~
    }                                                              //~v58FI~
  }                                                                //~v58FI~
#endif                                                             //~v500I~
    if (rc=dcmdwkdiredit(Pcmd,&repcmd),rc)                      //~v05xR~
        return 4;                                               //~v05xR~
	if (rc=dcmdscrfnmedit(DCSDE_FREEINPUT*(Pcmd!=repcmd),Ppcw,repcmd,&repcmd),rc)//~v77yR~
    	return rc;                                                 //~v77yR~
#ifdef WXE                                                         //~v500I~
    repcmd2=repcmd;                                                //~v500I~
//  rc=dcmdeditredirect(&repcmd2,fpath);                           //~v58CR~
    rc=dcmdeditredirect(Pflag,&repcmd2,fpath,fpathstde);           //~v58HR~
    if (repcmd!=Pcmd)   //replaced                                 //~v500I~
        ufree(repcmd);                                             //~v500I~
    if (rc)                                                        //~v500I~
    	return 4;                                                  //~v500I~
    repcmd=repcmd2;                                                //~v500I~
#endif                                                             //~v500I~
#ifdef W32UNICODE                                                  //~vavMI~
  if (Scmdbyspawn)                                                 //~vavMR~
  {                                                                //~vavMI~
    crc=rc=dcmd_spawn_redirected(0,repcmd);//spawn under redirected//~vavMI~
  }                                                                //~vavMI~
  else                                                             //~vavMI~
#endif                                                             //~vavMI~
  {                                                                //~vavMM~
#ifdef WXE	                                                       //~v55pI~
    crc=rc=usystem2(0,repcmd);//use cmd server if avail            //~v55pI~
#else                                                              //~v55pI~
    crc=rc=usystem(repcmd);                                     //~v05aR~
#endif                                                             //~v55pI~
  }                                                                //~vavMI~
#ifdef DOS                                                         //~v09tI~
#else                                                              //~v09tI~
    #ifdef W32                                                     //~v09tI~
    #else       //os/2                                             //~v09tI~
        kbdreinit();                                               //~v09tR~
    #endif                                                         //~v09tI~
#endif                                                             //~v09tI~
    if (repcmd!=Pcmd)   //replaced                              //~v05aI~
        ufree(repcmd);                                          //~v05aI~
    if (rc!=-1)                                                 //~v056I~
    {                                                           //~v056I~
        if (rc==255)                                                  //~v06AR~
            rc=0;                                                     //~v06AR~
        actsw=1;                                                //~v05xR~
    }                                                           //~v056I~
    else                                                        //~v056I~
        rc=8;   //-1 mean quit                                  //~v056I~
#ifdef WXE                                                         //~v500I~
#else                                                              //~v500I~
  if (redirectallsw)                                               //~v58FI~
  {                                                                //~v58FI~
    if (uredirectrestore(3))                                    //~v056I~
        rc=4;                                                   //~v056I~
  }                                                                //~v58FI~
  else                                                             //~v58FI~
  {                                                                //~v58FI~
  	if (*fpath)                                                    //~v58FI~
    	if (uredirectrestore(1))                                   //~v58FI~
	        return 4;                                              //~v58FI~
  	if (*fpathstde)                                                //~v58FI~
    	if (uredirectrestore(2))                                   //~v58FI~
	        return 4;                                              //~v58FI~
  }                                                                //~v58FI~
//  if (actsw)                                                     //~v58GR~
//      if (Ppcw->UCWmenuopt==PANMOCMD) //cmd pannel               //~v58GR~
//          fputs("\n",fh);                                        //~v58GR~
  if (fh)                                                          //~v58FI~
    fclose(fh);                                                 //~v056I~
  if (fh2)                                                         //~v58FI~
    fclose(fh2);                                                   //~v58FI~
#endif                                                             //~v500I~
    if (actsw)                                                  //~v056I~
    {                                                              //~v53VI~
        if (Ppcw->UCWmenuopt==PANMOCMD) //not cmd pannel              //~v06nI~
        {                                                          //~v071I~
        	logcmd=Pcmd;                                           //~v58HI~
			dcmdeditredirect(Pflag,&logcmd,Pstdofnm,Pstdefnm);     //~v58HI~
//          rc+=dcmdappendso(Ppcw,sofname,Pcmd);                   //~v58HR~
            rc+=dcmdappendso(Ppcw,sofname,logcmd);                 //~v58HI~
            if (Ppcw->UCWsplitid)   //0:first,1:second screen      //~v071I~
                UCBITON(((PUSCRD)scrgetcw(1)->UCWpsd)->USDflag2,USDF2DRAW);//draw hdr//~v071I~
            ufree(logcmd);                                         //~v58HI~
        }                                                          //~v071I~
        else                                                          //~v06nI~
            rc+=dcmdsolast(sofname,fpath,crc);//from stdout        //~v58MR~
    }                                                              //~v53VI~
	IFDEF_WINCON(dcmdrestoreconsolemode(0));                       //~v781I~
    scrcsrtyperestore();                                           //~v09lR~
//  if (rc==1)                                                     //~v648R~
//      rc=4;   //bell req                                         //~v648R~
#ifdef UNX                                                         //~v21fI~
	dcmdfresetlock2();                                             //~v21fR~
#endif                                                             //~v21fI~
    return rc;                                                  //~v056I~
}//dcmdsystemcall                                               //~v056I~
//***************************************************** ********** //~v77yR~
//!dcmdscrfnmedit                                                  //~v77yR~
//*replace *\,^*\ by screen filenme                                //~v77yR~
//*parm1:cmd string                                                //~v77yR~
//*parm2:replaced string,same as input if no workdir               //~v77yR~
//*ret  :0 or UALLOC_FAILED                                        //~v77yR~
//************************************************************ *** //~v77yR~
int dcmdscrfnmedit(int Popt,PUCLIENTWE Ppcw,UCHAR *Pcmd,char  **Ppout)//~v77yR~
{                                                                  //~v77yR~
    char  *parm,**argv,**argv0,*pc,*pco,*pc3,*pc2;                 //~v77yR~
    char  fpath[_MAX_PATH];                                        //~v77yR~
    char  fpath2[_MAX_PATH];                                       //~v79uI~
    int ii,opdno,len,lent,repcnt,rc,redirectid;                    //~v77yR~
//*******************                                              //~v77yR~
	*Ppout=Pcmd;	//no updated                                   //~v77yR~
	parm=0;	//req malloc outarea                                   //~v77yR~
    if (!strchr(Pcmd,SAMEDIR))  //no *\ nor ^*\ exist              //~v77yR~
    	return 0;                                                  //~v77yR~
    rc=uparsecmd(UPCMD_ASIS/* keep quotation,\\ */,Pcmd,&opdno,&parm,&argv0,0/*out delmtb*/);//no delmt//~v77yR~
    if (rc==UALLOC_FAILED)                                         //~v77yR~
    	return rc;                                                 //~v77yR~
//count *\ and ^*\ length                                          //~v77yR~
    for (ii=0,argv=argv0,lent=0,repcnt=0;ii<opdno;argv++,ii++)     //~v77yR~
    {                                                              //~v77yR~
    	pc=*argv;                                                  //~v77yR~
        redirectid=0;                                              //~v77yR~
        if (*pc=='<')                                              //~v77yR~
        	redirectid++;                                          //~v77yR~
        else                                                       //~v77yR~
        if (*pc=='>')                                              //~v77yR~
        {                                                          //~v77yR~
        	redirectid++;                                          //~v77yR~
	        if (*(pc+1)=='>')                                      //~v77yR~
	        	redirectid++;                                      //~v77yR~
        }                                                          //~v77yR~
        pc2=pc+redirectid;                                         //~v77yR~
        if ((*pc2==SAMEDIR||!memcmp(pc2,FNMOF2NDSCR,sizeof(FNMOF2NDSCR)-1))//~v77yR~
		&&  subeditscrfnm(0,Ppcw,pc2,fpath))                       //~v77yR~
        {                                                          //~v77yR~
            if (strchr(fpath,' '))                                 //~v79uI~
            {                                                      //~v79uI~
    	    	uparseindir(0,fpath,fpath2,_MAX_PATH);             //~v79uI~
                strcpy(fpath,fpath2);                              //~v79uI~
            }                                                      //~v79uI~
        	len=(int)strlen(fpath)+redirectid;                     //~v781R~
            repcnt++;                                              //~v77yR~
        }                                                          //~v77yR~
        else                                                       //~v77yR~
        	len=(int)strlen(pc);                                   //~v781R~
        lent+=len+1;                                               //~v77yR~
    }                                                              //~v77yR~
    if (!repcnt)                                                   //~v77yR~
    {                                                              //~v77yR~
    	ufree(parm);                                               //~v77yR~
        return 0;                                                  //~v77yR~
    }                                                              //~v77yR~
    pc3=UALLOCM((UINT)lent);                                       //~v77yR~
    UALLOCCHK(pc3,UALLOC_FAILED);                                  //~v77yR~
    *Ppout=pc3;                                                    //~v77yR~
//replace *\ and ^*\ length                                        //~v77yR~
    for (ii=0,argv=argv0,pco=pc3;ii<opdno;argv++,ii++)             //~v77yR~
    {                                                              //~v77yR~
    	pc=*argv;                                                  //~v77yR~
        redirectid=0;                                              //~v77yR~
        if (*pc=='<')                                              //~v77yR~
        	redirectid++;                                          //~v77yR~
        else                                                       //~v77yR~
        if (*pc=='>')                                              //~v77yR~
        {                                                          //~v77yR~
        	redirectid++;                                          //~v77yR~
	        if (*(pc+1)=='>')                                      //~v77yR~
	        	redirectid++;                                      //~v77yR~
        }                                                          //~v77yR~
        pc2=pc+redirectid;                                         //~v77yR~
        if ((*pc2==SAMEDIR||!memcmp(pc2,FNMOF2NDSCR,sizeof(FNMOF2NDSCR)-1))//~v77yR~
		&&  subeditscrfnm(0,Ppcw,pc2,fpath))                       //~v77yR~
        {                                                          //~v77yR~
            if (redirectid)                                        //~v77yR~
            {                                                      //~v77yR~
            	memcpy(pco,pc,(UINT)redirectid);                   //~v781R~
                pco+=redirectid;                                   //~v77yR~
            }                                                      //~v77yR~
            if (strchr(fpath,' '))                                 //~v79uI~
            {                                                      //~v79uI~
    	    	uparseindir(0,fpath,fpath2,_MAX_PATH);             //~v79uI~
                strcpy(fpath,fpath2);                              //~v79uI~
            }                                                      //~v79uI~
        	len=(int)strlen(fpath);                                //~v781R~
            memcpy(pco,fpath,(UINT)len);                           //~v77yR~
        }                                                          //~v77yR~
        else                                                       //~v77yR~
        {                                                          //~v77yR~
        	len=(int)strlen(pc);                                   //~v781R~
            memcpy(pco,pc,(UINT)len);                              //~v77yR~
        }                                                          //~v77yR~
        pco+=len;                                                  //~v77yR~
        *pco++=' ';                                                //~v77yR~
    }                                                              //~v77yR~
    pco--;                                                         //~v77yR~
    *pco=0;                                                        //~v77yR~
    ufree(parm);                                                   //~v77yR~
	if (Popt & DCSDE_FREEINPUT)    //free old input if newly alloced//~v77yR~
    	ufree(Pcmd);                                               //~v77yR~
    return 0;                                                      //~v77yR~
}//dcmdscrfnmedit                                                  //~v77yR~
//***************************************************** **********//~v05xR~
//!dcmdwkdiredit                                                //~v05xR~
//*replace :: by workdirname                                    //~v05xR~
//*parm1:cmd string                                             //~v05xR~
//*parm2:replaced string,same as input if no workdir            //~v05xR~
//*ret  :0 or UALLOC_FAILED                                     //~v05xR~
//************************************************************ ***//~v05xR~
int dcmdwkdiredit(UCHAR *Pcmd,char  **Ppout)                       //~v095R~
{                                                               //~v05xR~
    UCHAR *pc1,*pc2,*pc3;                                       //~v05xR~
    int ii,ctr=0;                                               //~v05xR~
    UINT ulen1,ulen2;                                           //~v05xR~
//*******************                                           //~v05xR~
//count ::                                                      //~v05xR~
    for (pc1=Pcmd;pc2=strstr(pc1,WORKDIRPATHID),pc2;pc1=pc2+WORKDIRPATHIDLEN)//~v05xR~
        ctr++;                                                  //~v05xR~
    if (!ctr)                                                   //~v05xR~
    {                                                           //~v05xR~
        *Ppout=Pcmd;                                            //~v05xR~
        return 0;                                               //~v05xR~
    }                                                           //~v05xR~
//  ulen1=strlen(Gworkdir);                                     //~v05xR~//~vb2ER~
    ulen1=(UINT)strlen(Gworkdir);                                  //~vb2EI~
//  *Ppout=pc3=UALLOCM((UINT)(1+strlen(Pcmd)+ctr*(ulen1-WORKDIRPATHIDLEN)));//~v05xR~//~vb2DR~
    *Ppout=pc3=UALLOCM((UINT)(1+(int)strlen(Pcmd)+ctr*((int)ulen1-WORKDIRPATHIDLEN)));//~vb2DR~
    UALLOCCHK(pc3,UALLOC_FAILED);                               //~v05xR~
//replace :: by workdir name                                    //~v05xR~
    for (ii=0,pc1=Pcmd;ii<ctr;ii++)                             //~v05xR~
    {                                                           //~v05xR~
        pc2=strstr(pc1,WORKDIRPATHID);                          //~v05xR~
//      ulen2=(UINT)((ULONG)pc2-(ULONG)pc1);                    //~v05CR~//~vafkR~
        ulen2=(UINT)((ULPTR)pc2-(ULPTR)pc1);                       //~vafkI~
        memcpy(pc3,pc1,ulen2);                                  //~v05xR~
        pc3+=ulen2;                                             //~v05xR~
        memcpy(pc3,Gworkdir,ulen1);                             //~v05xR~
        pc1=pc2+WORKDIRPATHIDLEN;                               //~v05xR~
        pc3+=ulen1;                                             //~v05xR~
    }                                                           //~v05xR~
    strcpy(pc3,pc1);    //residual and last null                //~v05xR~
    return 0;                                                   //~v05xR~
}//dcmdwkdiredit                                                //~v05xR~
//***************************************************** ********** //~v58CI~
//!dcmdparseredirect                                               //~v58CI~
//  drop redirect stdo/stde specification from cmd string          //~v58CI~
//  rc:0,1:stdout is append mode,2:stderr is appendmode,3:both append mode,4 err//~v58CR~
//************************************************************ *** //~v58CI~
int dcmdparseredirect(PUCLIENTWE Ppcw,char *Pcmd,char *Pfpathstdo,char *Pfpathstde,int *Ppredirectsw,int *Ppcmdlen)//~v58DR~
{                                                                  //~v58CI~
	char stdofnm[_MAX_PATH];                                       //~v58CR~
	char stdefnm[_MAX_PATH];                                       //~v58CI~
    int rc=0,cmdlen;                                               //~v58CR~
//***********************                                          //~v58CI~
	*Pfpathstdo=0;                                                 //~v58CI~
	*Pfpathstde=0;                                                 //~v58CI~
//  if (uprocparseredirect(Pcmd,stdofnm,stdefnm,Ppredirectsw,&cmdlen))//~v70rR~
    if (uprocparseredirect(Pcmd,0,stdofnm,stdefnm,Ppredirectsw,&cmdlen))//0:no stdin//~v70rI~
		return dcmdredirectparmerr();                              //~v58HI~
    if (*stdofnm)                                                  //~v58CI~
    {                                                              //~v58CI~
        if (!dcmdfullpath(Ppcw,Pfpathstdo,stdofnm))   //consider :://~v58CI~
        	return 4;                                              //~v58CI~
    }                                                              //~v58CI~
    if (*stdefnm)                                                  //~v58CI~
    {                                                              //~v58CI~
        if (*stdefnm=='&')                                         //~v58DI~
        	strcpy(Pfpathstde,stdefnm);                            //~v58DI~
        else                                                       //~v58DI~
        {                                                          //~v58DI~
	        if (!dcmdfullpath(Ppcw,Pfpathstde,stdefnm))   //consider :://~v58DR~
	        	return 4;                                          //~v58DR~
        }                                                          //~v58DI~
    }                                                              //~v58CI~
    *Ppcmdlen=cmdlen;                                              //~v58DI~
    return rc;                                                     //~v58CI~
}//dcmdparseredirect                                               //~v58CI~
//#ifdef WXE                                                       //~v58HR~
//***************************************************** ********** //~v500I~
//!dcmdeditredirect                                                //~v500I~
//  padding redirect phrase                                        //~v500I~
//************************************************************ *** //~v500I~
//int dcmdeditredirect(UCHAR **Ppcmd,char *Pfnm)                   //~v58CR~
int dcmdeditredirect(int Popt,UCHAR **Ppcmd,char *Pfnm,char *Pstdefnm)//~v58HR~
{                                                                  //~v500I~
    UINT ulen;                                                     //~v500R~
    int cmdlen;                                                    //~v58JR~
    char *pcmd,*pcmd0;                                             //~v500I~
//*******************                                              //~v500I~
	pcmd0=*Ppcmd;                                                  //~v500I~
    cmdlen=(int)strlen(*Ppcmd);                                    //~v59QR~
//  ulen=strlen(pcmd0)+strlen(Pfnm)+strlen(STR_REDIRECT)+1;        //~v58JR~
//  ulen=cmdlen+strlen(Pfnm)+strlen(Pstdefnm)+32;                  //~v58JR~//~vb2DR~
//  ulen=(size_t)cmdlen+strlen(Pfnm)+strlen(Pstdefnm)+32;          //~vb2DI~//~vb2ER~
    ulen=(UINT)((size_t)cmdlen+strlen(Pfnm)+strlen(Pstdefnm)+32);  //~vb2EI~
    pcmd=UALLOCM(ulen);                                            //~v500I~
    UALLOCCHK(pcmd,UALLOC_FAILED);                                 //~v500I~
//  strcpy(pcmd,pcmd0);                                            //~v58CR~
    memcpy(pcmd,pcmd0,(UINT)cmdlen);                               //~v59QR~
    *(pcmd+cmdlen)=0;                                              //~v58HR~
//  strcat(pcmd,STR_REDIRECT);                                     //~v58JR~
//  strcat(pcmd,Pfnm);                                             //~v58JR~
    if (Pfnm && *Pfnm)                                             //~v58JI~
    {                                                              //~v58JI~
        if (Popt & PRERC_STDOAPPEND)                               //~v58JI~
//          cmdlen+=sprintf(pcmd+cmdlen,"%c%c%s",CHAR_REDIRECT,CHAR_REDIRECT,Pfnm);//~v76sR~
            cmdlen+=sprintf(pcmd+cmdlen," %c%c%s",CHAR_REDIRECT,CHAR_REDIRECT,Pfnm);//~v76sR~
        else                                                       //~v58JI~
//      	cmdlen+=sprintf(pcmd+cmdlen,"%c%s",CHAR_REDIRECT,Pfnm);//~v76sR~
        	cmdlen+=sprintf(pcmd+cmdlen," %c%s",CHAR_REDIRECT,Pfnm);//~v76sR~
    }                                                              //~v58JI~
//  if (udosiswinnt())                                             //~v58DR~
//  {                                                              //~v58DR~
//    if (stdesw)                                                  //~v58JR~
    if (Pstdefnm && *Pstdefnm)                                     //~v58JI~
    {                                                              //~v58JI~
//      if (Popt & PRERC_STDEAPPEND)                               //~v76sR~
        if ((Popt & PRERC_STDEAPPEND)                              //~v76sI~
        &&   strcmp(Pstdefnm,STR_REDIRECT21))    //not  "&1"       //~v76sI~
	      	sprintf(pcmd+cmdlen," 2%c%c%s",CHAR_REDIRECT,CHAR_REDIRECT,Pstdefnm);//~v58JI~
        else                                                       //~v58JI~
	      	sprintf(pcmd+cmdlen," 2%c%s",CHAR_REDIRECT,Pstdefnm);  //~v58JR~
    }                                                              //~v58JI~
//    else                                                         //~v58FR~
//  	strcat(pcmd,STR_REDIRECT2);                                //~v58FR~
//  }                                                              //~v58DR~
    *Ppcmd=pcmd;                                                   //~v500I~
    return 0;                                                      //~v500I~
}//dcmdeditredirect                                                //~v500I~
//#endif                                                           //~v58HR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va57I~
//***************************************************** ********** //~va57I~
//!dcmdxpsetebcparm                                                //~va57I~
//ret strlen                                                       //~va57I~
//***************************************************** ********** //~va57I~
int dcmdxpsetebcparm(int Popt,PUFILEH Ppfh,char *Poutstr)          //~va57I~
{                                                                  //~va57I~
	UCHAR  wkrecsz[16];                                            //~va57I~
    int len;                                                       //~va57I~
    char *pcfgfnm;                                                 //~va7TI~
//***********************************                              //~va57I~
	if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                    //~va57I~
    	sprintf(wkrecsz,"%cR%d",CMDFLAG_PREFIX,Ppfh->UFHlrecl);    //~va57I~
    else                                                           //~vaj0I~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV) && Ppfh->UFHvfmt)       //~vaj0I~
    	sprintf(wkrecsz,"%cV%s",CMDFLAG_PREFIX,ufile5getVfmtstr(0,Ppfh->UFHvfmt));//~vaj0I~
    else                                                           //~va57I~
    	wkrecsz[0]=0;                                              //~va57I~
    if (Gebcstat & GES_CFGOPENERR)                                 //~va7TI~
    	pcfgfnm=0;                                                 //~va7TR~
    else                                                           //~va7TI~
		pcfgfnm=Gebccfgfnm;                                        //~va7TI~
  if (pcfgfnm)                                                     //~va7TI~
    len=sprintf(Poutstr," %c%s %c%s%s %s",                         //~va57I~
    			CMDFLAG_PREFIX,XPEBCOPT,CMDFLAG_PREFIX,XEEBCOPTCFG,Gebccfgfnm
,wkrecsz);//~va57I~
  else                                                             //~va7TI~
    len=sprintf(Poutstr," %c%s %s",                                //~va7TI~
    			CMDFLAG_PREFIX,XPEBCOPT,wkrecsz);                  //~va7TR~
    if (Ppfh->UFHhandle)                                           //~va7TI~
    	len+=sprintf(Poutstr+len," %c%s%s",                        //~va7TI~
				CMDFLAG_PREFIX,XPEBCOPTCPEB,ucvebc4_getcvname(0,Ppfh->UFHhandle));//~va7TI~
    if (!(Popt & FSENDSW_PRTSCR))					//0x15 when print screen//~va81I~
    if (!UCBITCHK(Ppfh->UFHflag11,UFHF11RTEXTEBC))	//not EBC EOL  //~va7TI~
    if (UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTPC|UFHF3RTEXTUNIX))      //~va7TI~
	if (!UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                   //~vaj9I~
	if (!UCBITCHK(Ppfh->UFHflag13,UFHF13RV))       //recfm=V       //~vaj0R~
    	len+=sprintf(Poutstr+len," %c%s",                          //~va7TI~
				CMDFLAG_PREFIX,XPEBCOPTASCEOL);                    //~va7TI~
    return len;                                                    //~va57I~
}//dcmdxpsetebcparm                                                //~va57I~
#endif //UTF8EBCD raw ebcdic file support                          //~va57I~
//***************************************************** ********** //~v11rI~
//!dcmdxpfnmchk                                                    //~v11MR~
//*replace *  by current file name                                 //~v11rI~
//*parm1:pcw                                                       //~v11rI~
//*parm2:cmd string                                                //~v11rI~
//*parm3:replaced string,same as input if no workdir               //~v11rI~
//*ret  :0 or UALLOC_FAILED                                        //~v11rI~
//************************************************************ *** //~v11rI~
int dcmdxpfnmchk(PUCLIENTWE Ppcw,UCHAR *Pcmd,UCHAR  **Ppout)       //~v11MR~
{                                                                  //~v11rI~
    PUFILEH pfh=NULL;                                                   //~v11rR~//~vafcR~
	PUFILEC pfc;                                                   //~v40kI~
    PULINEH plh=0,plhe=0;                                          //~v40kR~
    UCHAR *pc,*pout,*pos,*fnm,*fnm0,*fnm2;                         //~v40nR~
    int ii,len,len0,len1,len2,addlen;                              //~v11MR~
    int  endsw=0;                                                  //~v40hR~
    char fpath[_MAX_PATH];                                         //~v57tR~
    char fnm0x[_MAX_PATH+2],fnmx[_MAX_PATH+2];                     //~v499R~
    char *pfnm;                                                    //~v40nM~
    int lblcnt=0,rc;                                               //~v40nR~
    UCHAR labelt[2][ULHLINENOSZ+1];                                //~v40nR~
    PULINEH plht[2];			//output of lcmdgetabplh           //~v40nI~
	UPODELMTBL *podt;                                              //~v57tR~
    int quatesw=0;                                                 //~v57tI~
//#ifdef WXE                                                       //~v57sR~
	int skipsavesw=0;                                              //~v54yI~
//#endif                                                           //~v57sR~
#ifdef FTPSUPP                                                     //~v57sR~
    PUFTPHOST puftph;                                              //~v57sR~
    char remotetemp[_MAX_PATH];                                    //~v57sR~
    char fnmremote[2+_MAX_PATH+1+_MAX_PATH+2];                     //~v57BI~
    int remotesw=0;                                                //~v57BI~
#endif                                                             //~v57sR~
    int linenosz;                                                  //~v624I~
    char vhexid;                                                   //~v624I~
    int tabctr=0,tabctrparmlen;                                    //~v8@2I~
    UFILEH wkfh;                                                   //~v8@2I~
    PUFILEH pwkfh=NULL;                                            //~va7TI~//~vafdR~
    long  profileflag;                                             //~v8@2I~
    char tabctrparm[8];                                            //~v8@2I~
#ifdef UTF8UCS2                                                    //~va20I~
    int utf8mode=0,cmdstrlen;                                      //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile=0;                                               //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef  W32UNICODE                                                 //~vavQI~
    int opdnofnm,opt;	//filename opdno                           //~vavQR~
    char wkud[_MAX_PATH],*pfnmu8=NULL;                             //~vavQR~
    char *pcmdx;                                                   //~vavQR~
#endif                                                             //~vavQI~
//*******************                                              //~v11rI~
	pfc=Ppcw->UCWpfc;                                              //~v624I~
    *Ppout=Pcmd;        //init by no repl                          //~v11MM~
                                                                   //~v11MI~
    if (!(pc=Ppcw->UCWopdpot))                                     //~v11MI~
        return 0;           //from dlcmd print,it may be already fullpath//~v11MI~
    if (!(ii=Ppcw->UCWopdno))   //no operand                       //~v11MM~
        return 4;                                                  //~v11MM~
    podt=Ppcw->UCWopddelmt;                                        //~v57tR~
    for (;ii;pc+=strlen(pc)+1,ii--)                                //~v11MR~
    {                                                              //~v11MI~
		quatesw=podt->upoquate;		//not in quatation             //~v57tR~
        podt++;                                                    //~v57tR~
#ifdef UNX                                                         //~v40nI~
        if (*pc!='-')                                              //~v40nI~
#else                                                              //~v40nI~
        if (*pc!='/' && *pc!='-')                                  //~v11MI~
#endif                                                             //~v40nI~
            break;                                                 //~v11MI~
    }                                                              //~v11MI~
    if (!ii)            //no filename                              //~v11MI~
    {                                                              //~v40cI~
        uerrmsg("Specify filename",                                //~v40cI~
                "ファイル名を指定してください");                   //~v40cR~
        return 4;                                                  //~v11MI~
    }                                                              //~v40cI~
#ifdef  W32UNICODE                                                 //~vavQI~
	opdnofnm=Ppcw->UCWopdno-ii;                                    //~vavQR~
#endif                                                             //~vavQI~
//  if (*pc!='*')                                                  //~v57sR~
//  {                                                              //~v57sR~
//#ifdef WXE                                                       //~v57sR~
//  	*(Swxpfnm)='e';	//external file id                         //~v57sR~
//      if (!dcmdfullpath(Ppcw,Swxpfnm+1,pc))   //consider *\ ::   //~v57sR~
//          return 4;                                              //~v57sR~
//#endif                                                           //~v57sR~
//      return 0;       //no *\ or *                               //~v57sR~
//  }                                                              //~v57sR~
    len1=(int)strlen(pc);                                          //~v11MR~
//*label operand process for "*"/"**"                              //~v40nM~
    pfnm=pc;			//save filename ptr                        //~v40nI~
    for (;pc+=strlen(pc)+1,--ii;)                                  //~v40nI~
    {                                                              //~v40nI~
        if (*pc==ULCCMDLABEL)    //start by '.'                    //~v40nI~
        {                                                          //~v40nI~
            if (lblcnt>=2)                                         //~v40nI~
                return fcmdlabelerr(pc);                           //~v40nI~
            strncpy(labelt[lblcnt],pc,ULHLINENOSZ);                //~v40nI~
            labelt[lblcnt][ULHLINENOSZ]=0;                         //~v40nI~
            lblcnt++;                                              //~v40nI~
        }                                                          //~v40nI~
    }//label search                                                //~v40nI~
#ifdef  W32UNICODE                                                 //~vavQI~
	opt=FSWCOU8CT2UDO_UTF8WC;  //all utf8(not f2l err only)        //~vavQI~
  	if (fsubw_cmdopdU8CT2UD(opt,Ppcw,opdnofnm,pfnm,wkud,sizeof(wkud),NULL/*outlen*/)==1)//unprintable utf8 was enclosed by UDX//~vavQR~
    {                                                              //~vavQI~
    	pfnmu8=pfnm;	//save org value                           //~vavQI~
  		pfnm=wkud;                                                 //~vavQR~
    }                                                              //~vavQI~
#endif                                                             //~vavQI~
    pc=pfnm;			//restore filename ptr                     //~v40nI~
                                                                   //~v11MI~
    addlen=0;                                                      //~v11MI~
//  if (!*(pc+1))                                                  //~v57sR~
    if (*pc=='*' && !*(pc+1))	//"*"                              //~v57sI~
    {                                                              //~v11MI~
        if (Ppcw->UCWtype!=UCWTFILE)                               //~v11MI~
#ifdef UNX                                                         //~v20hI~
		{                                                          //~v20hI~
			if (dcmdconfallmemb("xprint",fpath))                   //~v57tR~
				return 4;                                          //~v20hI~
          fnm0=                                                    //~vafeI~
        	fnm=fpath;                                             //~v57tR~
        }                                                          //~v20hI~
        else                                                       //~v20hI~
        {                                                          //~v20hI~
#else                                                              //~v20hI~
            return dcmdaster();                                    //~v20hR~
#endif //!UNX                                                      //~v20hI~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~v11MI~
        tabctr=pfh->UFHtabskip;                                    //~v8@2I~
#ifdef UTF8UCS2                                                    //~va20R~
        utf8mode|=FILEUTF8MODE(pfh);                               //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        swebcfile=PFH_ISEBC(pfh);                                  //~va50I~
        pwkfh=pfh;                                                 //~va7TI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        fnm0=fnm=pfh->UFHfilename;                                 //~v11MI~
//      if (pfh->UFHupctr)                                         //~v40nR~
        if (pfh->UFHupctr || lblcnt)    //updated or label range   //~v40nI~
        {                                                          //~v11MI~
            filefullpath(fpath,Scurfilesave,_MAX_PATH);//return fullpath//~v57tR~
        	Gdcmdtempf|=GDCMDTEMPF_XPRINT; //del at term           //~v638I~
            fnm=fpath;                                             //~v57tR~
//          addlen+=(int)strlen(fnm0+4); //original file name by /N//~v11kR~
            addlen+=(int)strlen(fnm0)+4; //original file name by /N,4 is for " /W="//~v499R~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
		  	if (lblcnt)	//no temp file required when update only   //~v54yI~
            {                                                      //~v54yI~
				*Swxpfnm='*';       //Scufilesave id               //~v54yI~
				strcpy(Swxpfnm+1,fpath);                           //~v57tR~
            }                                                      //~v54yI~
            else                                                   //~v54yI~
            	if (Swxpsw)                                        //~v54yI~
                	skipsavesw=1;                                  //~v54yI~
#endif                                                             //~v54yI~
        }                                                          //~v11MI~
#ifdef FTPSUPP                                                     //~v57sR~
        else    //not updated nor range specified                  //~v57sI~
        {                                                          //~v57sI~
        	skipsavesw=1;	//xprint file direct                   //~v57sI~
            if (FILEISREMOTE(pfh))                                 //~v57sR~
            {                                                      //~v57sR~
                fnm=pfh->UFHftpwdfnm;   //downloaded file          //~v57sR~
//              addlen+=(int)strlen(fnm0)+4; //original file name by /N,4 is for " /W="//~v57BR~
			    remotesw=1;                                        //~v57BI~
            }//remote file edit scr                                //~v57sR~
        }                                                          //~v57sI~
#endif                                                             //~v57sR~
#ifdef UNX                                                         //~v20hI~
        }	//not edit scr                                         //~v20hI~
#else                                                              //~v20hM~
#endif //!UNX                                                      //~v20hI~
    }                                                              //~v11MI~
    else        //not "*"                                          //~v40hI~
//  if (*(pc+1)=='*' &&                                            //~v57sR~
    if (*pc=='*' && *(pc+1)=='*' &&         //"**" or "***"        //~v57sR~
        (!*(pc+2) || (*(pc+2)=='*' && !*(pc+3))) )       //"**"    //~v40kR~
    {                                                              //~v40hI~
        if (Ppcw->UCWtype!=UCWTFILE)                               //~v40hI~
        {                                                          //~v40hI~
//          uerrmsg("Not file screen for **",                      //~v54yR~
//                  "** はファイル画面でのみ有効");                //~v54yR~
            uerrmsg("Not file screen for **/***",                  //~v54yI~
                    "**/*** はファイル画面でのみ有効");            //~v54yI~
            return 4;                                              //~v40hR~
        }                                                          //~v40hI~
    	endsw|=FSENDSW_PRTSCR;					//print screen     //~v40hR~
		if (*(pc+2)=='*')       //"*."                             //~v40kR~
        {                                                          //~v54yI~
        	if (lblcnt)    //updated or label range                //~v54yI~
            {                                                      //~v54yI~
//          	uerrmsg("label is not supported for ***(PRTSCR)",  //~v57sR~
//                  "***(画面印刷)で行ラベルは指定不可。");        //~v57sR~
//          	return 4;                                          //~v57sR~
	        	return dcmdxprlblerr();                            //~v57sI~
            }                                                      //~v54yI~
    		endsw|=FSENDSW_PRTPAGE;       //print current page only//~v40kI~
        }                                                          //~v54yI~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~v40hI~
        swebcfile=PFH_ISEBC(pfh);                                  //~va81I~
        pwkfh=pfh;                                                 //~va7TI~
      if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                            //~v106I~//~vajdI~
        tabctr=1;                                                  //~vajdI~
      else                                                         //~vajdI~
        tabctr=pfh->UFHtabskip;                                    //~v8@2I~
#ifdef UTF8UCS2                                                    //~va20R~
        utf8mode|=FILEUTF8MODE(pfh);                               //~va20I~
#endif                                                             //~va20I~
        plh=UGETQTOP(&pfh->UFHlineque); //to avoid partial save determination//~v40jI~
        fnm0=fnm=pfh->UFHfilename;                                 //~v40hI~
        filefullpath(fpath,Scurfilesave,_MAX_PATH);//return fullpath//~v57tR~
        Gdcmdtempf|=GDCMDTEMPF_XPRINT; //del at term               //~v638I~
        fnm=fpath;                                                 //~v57tR~
        addlen+=(int)strlen(fnm0)+32; //original file name by "/Nn /WN=8 /WS="//~v40hR~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
		*Swxpfnm='*';       //Scufilesave id                       //~v54yI~
//  	strcpy(Swxpfnm+1,fullpath);                                //~v552R~
		*(Swxpfnm+1)='*';       //Scufilesave id                   //~v552I~
    	strcpy(Swxpfnm+2,fpath);                                   //~v57tR~
#endif                                                             //~v54yI~
    }                                                              //~v40hI~
    else        //not "*"                                          //~v11MR~
    {                                                              //~v11MI~
        if (lblcnt)    //updated or label range                    //~v57sI~
        	return dcmdxprlblerr();                                //~v57sI~
        if (!dcmdfullpath(Ppcw,fpath,pc))   //consider *\ ::       //~v57tR~
            return 4;                                              //~v11MI~
        fnm0=                                                      //~v499I~
        fnm=fpath;                                                 //~v57tR~
        memset(&wkfh,0,sizeof(wkfh));	//clear handle             //~va7TR~
		strcpy(wkfh.UFHfilename,fpath);                        //~v8@2R~
        pwkfh=&wkfh;                                               //~va7TI~
		if (!fcmdprofgetprofile(0,&wkfh,&profileflag))         //~v8@2I~
        {                                                          //~va50I~
        	if (profileflag & FPURO_TABCTR)                        //~v8@2I~
        		tabctr=wkfh.UFHtabskip;                            //~v8@2I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			if (UCBITCHK(wkfh.UFHflag10,UFHF10EBC))                //~va50I~
            	swebcfile=1;	//not current file print           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        }                                                          //~va50I~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
        if (Swxpsw) //wxp cmd                                      //~v57sI~
        {                                                          //~v57sI~
    		*(Swxpfnm)='e';	//external file id                     //~v57sI~
        	strcpy(Swxpfnm+1,fnm);   //consider *\ ::              //~v57sI~
            return 0;				//edit fnm                     //~v57sI~
        }                                                          //~v57sI~
#endif                                                             //~v57sI~
#ifdef FTPSUPP                                                     //~v57sR~
        if (uftpisremote(fnm0,&puftph))	//ftp filename             //~v57sR~
        {                                                          //~v57sR~
//          filefullpath(remotetemp,Scurfilesave,_MAX_PATH);//return fullpath//~v57BR~
//      	if (rc=xeftpgetremotecopy(XEFTP_GRC_PARMFILE,fnm0,puftph,remotetemp),rc)//~v57BR~
//      	if (rc=dcmdcpgetremotecopy(fnm0,puftph,remotetemp),rc) //~v57BI~//~vb7eR~
        	if (rc=dcmdcpgetremotecopy(fnm0,puftph,remotetemp,sizeof(remotetemp)),rc)//~vb7eI~
            	return rc;                                         //~v57sR~
            fnm=remotetemp;                                        //~v57sR~
//          addlen+=(int)strlen(fnm0)+4; //original file name by /N,4 is for " /W="//~v57BR~
            remotesw=1;                                            //~v57BI~
        }                                                          //~v57sR~
		skipsavesw=1;	//xprint file directly                     //~v57sI~
#endif                                                             //~v57sR~
    }                                                              //~v11MI~
    if (addlen && lblcnt)                                          //~v40nR~
    {                                                              //~v40nI~
        if (lblcnt&1)   //odd number                               //~v40nM~
            return fcmdlabelerr("Need From/To");                   //~v40nM~
        if (rc=fcmdgetlabelrange(pfh,lblcnt,labelt,plht,0),rc)     //~v40nR~
            return rc;                                             //~v40nM~
    }                                                              //~v40nI~
#ifdef FTPSUPP                                                     //~v57BI~
 if (remotesw)                                                     //~v57BI~
 {                                                                 //~v57BI~
  	if (quatesw!='\"')  	//parm fnm is not enclosed quote       //~v57BR~
    	sprintf(fnmremote,"\"<%s>%s\"",fnm0,fnm);                  //~v57BI~
    else                                                           //~v57BI~
    	sprintf(fnmremote,"<%s>%s",fnm0,fnm);                      //~v57BI~
    fnm=fnmremote;                                                 //~v57BI~
 }                                                                 //~v57BI~
 else//local file                                                  //~v57BI~
 {                                                                 //~v57BI~
#endif                                                             //~v57BI~
  if (quatesw!='\"')		//parm fnm is not enclosed quote       //~v57tR~
	if (strchr(fnm,' '))                                           //~v499R~
    {                                                              //~v499I~
    	sprintf(fnmx,"\"%s\"",fnm);                                //~v499R~
        fnm=fnmx;                                                  //~v499R~
    }                                                              //~v499I~
	if (strchr(fnm0,' '))                                          //~v499I~
    {                                                              //~v499I~
    	sprintf(fnm0x,"\"%s\"",fnm0);                              //~v499I~
        fnm0=fnm0x;                                                //~v499I~
    }                                                              //~v499I~
#ifdef FTPSUPP                                                     //~v57BI~
 }//local file                                                     //~v57BI~
#endif                                                             //~v57BI~
    if (UCBITCHK(pwkfh->UFHflag10,UFHF10RECORD)                    //~vamEI~
    ||  UCBITCHK(pwkfh->UFHflag13,UFHF13RV))                       //~vamEI~
    	tabctrparmlen=0;                                           //~vamEI~
    else                                                           //~vamEI~
    if (swebcfile)                                                 //~va81I~
    	tabctrparmlen=0;                                           //~va81I~
    else                                                           //~va81I~
	if (tabctr)                                                    //~v8@2I~
    	tabctrparmlen=sprintf(tabctrparm,"%cT%d ",CMDFLAG_PREFIX,tabctr);//~v8@2I~
    else                                                           //~v8@2I~
    	tabctrparmlen=0;                                           //~v8@2I~
    len2=(int)strlen(fnm);                                         //~v11MM~
//*                                                                //~v11rI~
    len0=(int)strlen(Pcmd);                                        //~v11MR~
    len0+=tabctrparmlen;                                           //~v8@2I~
//  *Ppout=pout=UALLOCM((UINT)(len0-len1+len2+addlen+10+1));       //~v499R~
#ifdef UTF8UCS2                                                    //~va20R~
    cmdstrlen=len0-len1+len2+addlen+4+10+1; //2*2:" "              //~va20I~
    if (utf8mode)                                                  //~va20I~
//  	cmdstrlen+=sizeof(XPUTF8OPT);                              //~va20I~//~vb2DR~
    	cmdstrlen+=(int)sizeof(XPUTF8OPT);                         //~vb2DI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (swebcfile)                                                 //~va50I~
//  	cmdstrlen+=sizeof(XPEBCOPT)+sizeof(XEEBCOPTCFG)+_MAX_PATH+32;                               //~va50I~//~va57R~//~va7TR~
//  	cmdstrlen+=sizeof(XPEBCOPT)+sizeof(XEEBCOPTCFG)+_MAX_PATH+32+sizeof(XPEBCOPTCPEB)+MAX_CSNAMESZ;//~va7TI~//~vb2DR~
    	cmdstrlen+=(int)sizeof(XPEBCOPT)+(int)sizeof(XEEBCOPTCFG)+_MAX_PATH+32+(int)sizeof(XPEBCOPTCPEB)+MAX_CSNAMESZ;//~vb2DI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    *Ppout=pout=UALLOCM((UINT)cmdstrlen); //2*2:" "                //~va20I~
#else                                                              //~va20I~
    *Ppout=pout=UALLOCM((UINT)(len0-len1+len2+addlen+4+10+1)); //2*2:" "//~v499R~
#endif                                                             //~va20I~
    UALLOCCHK(pout,UALLOC_FAILED);                                 //~v11rI~
    len0-=tabctrparmlen;                                           //~v8@2I~
//replace */*\ by filename                                         //~v11rI~
#ifdef W32UNICODE                                                  //~vavQI~
	if (pfnmu8)	//enclosed by UD                                   //~vavQI~
		pos=strstr(Pcmd,pfnmu8);                                   //~vavQI~
    else                                                           //~vavQI~
		pos=strstr(Pcmd,pc);                                       //~vavQI~
    if (!pos)                                                      //~vavQI~
#else                                                              //~vavQI~
    if (!(pos=strstr(Pcmd,pc)))                                    //~v11MI~
#endif                                                             //~vavQI~
    {                                                              //~v54yI~
        ufree(pout);                                               //~v54yI~
        return 4;                                                  //~v11MI~
    }                                                              //~v54yI~
    if (tabctrparmlen)                                             //~v8@2I~
    {                                                              //~v8@2I~
    	strcpy(pout,tabctrparm);                                   //~v8@2R~
        pout+=tabctrparmlen;                                       //~v8@2I~
    }                                                              //~v8@2I~
#ifdef UTF8UCS2                                                    //~va20R~
    if (utf8mode)                                                  //~va20I~
    {                                                              //~va20I~
    	pout+=sprintf(pout,"%c%s",CMDFLAG_PREFIX,XPUTF8OPT);       //~va20I~
        *pout++=' ';                                               //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (swebcfile)	//not prtscr case                              //~va50I~
    {                                                              //~va50I~
//  	pout+=dcmdxpsetebcparm(0,&wkfh,pout);                      //~va57I~//~va7TR~
    	pout+=dcmdxpsetebcparm(endsw,pwkfh,pout);                      //~va7TI~
        *pout++=' ';                                               //~va50I~
    }                                                              //~va50I~
    else                                                           //~vaj9I~
    {                                                              //~vaj9I~
    	if (UCBITCHK(pwkfh->UFHflag10,UFHF10RECORD) && pwkfh->UFHlrecl)//~vaj9I~
	    	pout+=sprintf(pout," %cR%d ",CMDFLAG_PREFIX,pwkfh->UFHlrecl);//~vaj9R~
        else                                                       //~vaj0I~
    	if (UCBITCHK(pwkfh->UFHflag13,UFHF13RV) && pwkfh->UFHvfmt) //~vaj0I~
	    	pout+=sprintf(pout," %cV%s ",CMDFLAG_PREFIX,ufile5getVfmtstr(0,pwkfh->UFHvfmt));//~vaj0I~
    }                                                              //~vaj9I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//  len=(int)((ULONG)pos-(ULONG)Pcmd);                             //~v11MI~//~vafkR~
    len=(int)((ULPTR)pos-(ULPTR)Pcmd);                             //~vafkI~
    memcpy(pout,Pcmd,(UINT)len);    //before part                  //~v11MI~
    pout+=len;                                                     //~v11MR~
    memcpy(pout,fnm,(UINT)len2);    //replace                      //~v11MR~
    pout+=len2;                                                    //~v11rI~
    len2=len0-len-len1;             //after part                   //~v11MR~
	fnm2=pout;              //for safety when len2=0               //~v60uI~
    if (len2)                                                      //~v11rI~
    {                                                              //~v11MI~
        memcpy(pout,Pcmd+len+len1,(UINT)len2);                     //~v11MR~
    	fnm2=pout;		//save for label clear                     //~v40nI~
        pout+=len2;                                                //~v11MI~
    }                                                              //~v11MI~
    *pout=0;    //null term                                        //~v11MI~
    pos=ustrstri(fnm2,"-tabon");	//search label operand         //~v60uI~
#ifdef UNX                                                         //~v60uM~
#else                                                              //~v60uM~
    if (!pos)                                                      //~v60uI~
    	pos=ustrstri(fnm2,"/tabon");                               //~v60uI~
#endif                                                             //~v60uM~
	if (pos)                                                       //~v60uI~
    {                                                              //~v60uI~
      	if (endsw & FSENDSW_PRTSCR)	//print screen                 //~v60uI~
        {                                                          //~v60uI~
	      	endsw|=FSENDSW_PRTTAB;	//write tab display char;      //~v60uI~
            memset(pos,' ',6);                                     //~v60uI~
        }                                                          //~v60uI~
        else                                                       //~v60uI~
        {                                                          //~v60uI~
            uerrmsg("tabon option is for \"**\"/\"***\" only",     //~v60uR~
                    "tabon オプションは \"**\"/\"***\"のときのみです");//~v60uR~
            ufree(*Ppout);                                         //~v60uI~
            return 4;                                              //~v60uI~
        }                                                          //~v60uI~
    }                                                              //~v60uI~
    if (addlen)             //name changed                         //~v11MR~
    {                                                              //~v11MI~
      if (endsw & FSENDSW_PRTSCR)	//print screen                 //~v40hI~
      {                                                            //~v624I~
    	linenosz=Ppcw->UCWlinenosz;                                //~v624I~
        if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                     //~v624I~
        {                                                          //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
          if (utf8mode)                                            //~va20I~
            vhexid='U';       //vhexline by unicode                //~va20I~
          else                                                     //~va20I~
#endif                                                             //~va20I~
            vhexid='X';                                            //~v624I~
        }                                                          //~va20I~
        else                                                       //~v624I~
            vhexid=' ';                                            //~v624I~
//      sprintf(pout," %cNn %cWN=%d %cWS=%s",                      //~v624R~
//  			CMDFLAG_PREFIX,CMDFLAG_PREFIX,ULHLINENOSZ,CMDFLAG_PREFIX,//~v622R~
//  			CMDFLAG_PREFIX,CMDFLAG_PREFIX,Ppcw->UCWlinenosz,CMDFLAG_PREFIX,//~v624R~
//      sprintf(pout," %cNn %cWN=%d%c %cWS=%s",                    //~v624I~//~vajcR~
        sprintf(pout," %cNn %cWN=%d%c %cFFX%x %cWS=%s",            //~vajcI~
    			CMDFLAG_PREFIX,CMDFLAG_PREFIX,linenosz,vhexid,CMDFLAG_PREFIX,//~v624I~
    			'.'/*FFX*/,CMDFLAG_PREFIX,                         //~vajcI~
				fnm0);                                             //~v40hI~
      }                                                            //~v624I~
      else                                                         //~v40hI~
        sprintf(pout," %cW=%s",CMDFLAG_PREFIX,                     //~v499R~
				fnm0);                                             //~v40hI~
    	if (endsw & FSENDSW_PRTPAGE)       //print current page only//~v40kI~
        {                                                          //~v40kI~
//  		pfc=Ppcw->UCWpfc;                                      //~v624R~
        	plh=pfc->UFCcurtop;                                    //~v40kI~
//          plhe=(PULINEH)(ULONG)Ppcw;//to pass maxline            //~v445R~
            plhe=0;                                                //~v445I~
        }                                                          //~v40kI~
        else	//update cur file(*) or screen image print(**)     //~v40nI~
        	if (lblcnt)                                            //~v40nI~
            {                                                      //~v40nI~
		        plh=plht[0];                                       //~v40nR~
		        plhe=plht[1];                                      //~v40nR~
    			if (pos=strstr(fnm2,labelt[0]),pos)	//search label operand//~v40nI~
                	memset(pos,' ',strlen(labelt[0]));             //~v40nR~
    			if (pos=strstr(fnm2,labelt[1]),pos)	//search label operand//~v40nI~
                	memset(pos,' ',strlen(labelt[1]));             //~v40nR~
            }                                                      //~v40nI~
//      if (filesave(0,pfh,0,0,fullpath))                          //~v40hR~
//      if (filesave(endsw,pfh,plh,plhe,fullpath))                 //~v445R~
//#ifdef WXE                                                       //~v57sR~
	  if (!skipsavesw)	                                           //~v54yI~
      {                                                            //~v54yI~
//#endif                                                           //~v57sR~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
        if (Swxpsw) //wxp cmd                                      //~v625I~
			endsw|=FSENDSW_WXP;                                    //~v625R~
		Swxptabctr=tabctr;	//to set printwork tabctr              //~v8@2I~
#endif                                                             //~v625I~
#ifdef UTF8UCS2                                                    //~va20I~
		endsw|=FSENDSW_IGNCVER;                                    //~va20I~
        rc=filesave(Ppcw,endsw,pfh,plh,plhe,fpath);                //~va20I~
        if (rc)                                                    //~va20I~
#else                                                              //~va20I~
        if (filesave(Ppcw,endsw,pfh,plh,plhe,fpath))               //~v57tR~
#endif                                                             //~va20I~
        {                                                          //~v11MI~
#ifdef UTF8UCS2                                                    //~va20I~
            uerrmsg("Temp file creation failed(no space for %s(rc=%d))",//~va20I~
                    "一時ファイル(%s)が作成出来ません(スペース不足?(rc=%d))",//~va20I~
                        fpath,rc);                                 //~va20I~
#else                                                              //~va20R~
            uerrmsg("Temp file creation failed(no space for %s)",  //~v11kI~
                    "一時ファイル(%s)が作成出来ません(スペース不足?)",//~v11kI~
                        fpath);                                    //~v57tR~
#endif                                                             //~va20I~
            ufree(*Ppout);                                         //~v11MI~
            return 4;                                              //~v11MI~
        }                                                          //~v11MI~
        if (!pfh->UFHupctr)    //not updated                       //~va0KI~
			usetftime(fpath,pfh->UFHfiledate,pfh->UFHfiletime);    //~va0KI~
//#ifdef WXE                                                       //~v57sR~
      }                                                            //~v54yI~
//#endif                                                           //~v57sR~
    }                                                              //~v11MI~
#ifdef W32UNICODE                                                  //~vavQI~
	pcmdx=*Ppout;                                                  //~vavQI~
    len=strlen(pcmdx);                                             //~vavQI~
    if (memchr(pcmdx,UD_NOTLC,len))                                //~vavQR~
    {                                                              //~vavQI~
        char *pcmdx2;                                              //~vavQI~
    	pcmdx2=umalloc(len*2+1);                                   //~vavQR~
    	if (ufilecvUD2UDX(UFCVO_STRZ,pcmdx,len,pcmdx2,len*2+1,NULL/*cmdlenx*/)==1)//~vavQR~
			*Ppout=pcmdx2;                                         //~vavQI~
    	if (pcmdx!=Pcmd)                                           //~vavQI~
        	ufree(pcmdx);                                          //~vavQI~
    }                                                              //~vavQI~
#endif                                                             //~vavQI~
    return 0;                                                      //~v11rI~
}//dcmdxpfnmchk                                                    //~v11MR~
#ifdef FTPSUPP                                                     //~v58qI~
//**************************************************************** //~v57BI~
//!dcmdgetremotecopy                                               //~v57BI~
// copy remote file/dir to local xp tmpdir                         //~v57BI~
//**************************************************************** //~v57BI~
//int dcmdcpgetremotecopy(char *Prfnm,PUFTPHOST Ppuftph,char *Pltemp)//~v57BI~//~vb7eR~
int dcmdcpgetremotecopy(char *Prfnm,PUFTPHOST Ppuftph,char *Pltemp,size_t Pbuffsz)//~vb7eI~
{                                                                  //~v57BI~
	FILEFINDBUF3 ffb3;                                             //~v57BI~
    int wildcardsw,dirsw=0,rc,opt;                                 //~v57BR~
    char *pc;                                                      //~v57BI~
//*********************                                            //~v57BI~
	wildcardsw=WILDCARD(Prfnm)!=0;                                 //~v57BR~
    if (!wildcardsw)                                               //~v57BI~
    {                                                              //~v57BI~
        pc=Prfnm+Ppuftph->UFTPHhostnmlen+1;                        //~v57BI~
        if (FTP_ROOTDIR(pc))   // "/"                              //~v57BR~
            return ufileroot(Prfnm,8);                             //~v57BR~
//  	if (uftpfstat(Ppuftph,Prfnm,&ffb3))//chk remote file type  //~v71gR~
//  	if (rc=uftpfstat(Ppuftph,Prfnm,&ffb3),rc)//chk remote file type//~v71gI~//~vb2DR~
    	if (rc=(int)uftpfstat(Ppuftph,Prfnm,&ffb3),rc)//chk remote file type//~vb2DI~
        {                                                          //~v71gI~
            if (rc==ERROR_FILE_NOT_FOUND)                          //~v71gR~
                ufilenotfound(Prfnm,rc);                           //~v71gI~
            if (rc==ERROR_PATH_NOT_FOUND)                          //~v71gR~
                ufilepatherr(Prfnm,rc);                            //~v71gI~
        	return 8;                                              //~v57BI~
        }                                                          //~v71gI~
        dirsw=ffb3.attrFile & FILE_DIRECTORY;                      //~v57BI~
    }                                                              //~v57BI~
    if (!wildcardsw && !dirsw)                                     //~v57BI~
    {                                                              //~v57BI~
		filefullpath(Pltemp,Scurfilesave,_MAX_PATH);//return fullpath//~v57BI~
        Gdcmdtempf|=GDCMDTEMPF_XPRINT; //del at term               //~v638I~
//  	rc=xeftpgetremotecopy(XEFTP_GRC_PARMFILE,Prfnm,Ppuftph,Pltemp);//~v8@sR~
//  	rc=xeftpgetremotecopy(XEFTP_GRC_PARMFILE|XEFTP_GRC_FFB3,Prfnm,Ppuftph,Pltemp,&ffb3);//~v8@sR~//~vb7eR~
    	rc=xeftpgetremotecopy(XEFTP_GRC_PARMFILE|XEFTP_GRC_FFB3,Prfnm,Ppuftph,Pltemp,Pbuffsz,&ffb3);//~vb7eI~
    }                                                              //~v57BI~
    else                                                           //~v57BI~
    {                                                              //~v57BI~
		if (rc=dlcxpgettmpdir(Pltemp),!rc)                         //~v57BR~
        {                                                          //~v57BI~
		  	opt=XEFTP_GRC_PARMDIR;                                 //~v57BI~
            Sremotegetsw=1;                                        //~v57BR~
//  		rc=xeftpgetremotecopy(opt,Prfnm,Ppuftph,Pltemp);       //~v8@sR~
//			rc=xeftpgetremotecopy(opt,Prfnm,Ppuftph,Pltemp,0/*not yet now required for dir*/);//~v8@sR~//~vb7eR~
  			rc=xeftpgetremotecopy(opt,Prfnm,Ppuftph,Pltemp,Pbuffsz,0/*not yet now required for dir*/);//~vb7eI~
            if (UFTPHISTSO(Ppuftph) && rc==DCPY_RC_NOTCOPY)//invalid membername//~v71gR~
                rc=0;                                              //~v71gR~
            if (!rc)                                               //~v57BI~
            {                                                      //~v57BI~
                strcat(Pltemp,DIR_SEPS DIR_ALLMEMB);//for memb name padding at xprint//~v57BI~
	        	if (!wildcardsw)                                   //~v57BR~
                	strcat(Prfnm,FTP_DIR_SEPS FTP_DIR_ALLMEMB);//for memb name padding at xprint//~v57BI~
            }                                                      //~v57BI~
        }                                                          //~v57BI~
    }                                                              //~v57BI~
    return rc;                                                     //~v57BI~
}//dcmdcpgetremotecopy                                             //~v57BI~
#endif                                                             //~v58qI~
//**************************************************************** //~v11rI~
//!dcmderrcurfile                                                  //~v11rI~
//**************************************************************** //~v11rI~
int dcmderrcurfile(void)                                           //~v11rI~
{                                                                  //~v11rI~
    uerrmsg("'*' is invalid in this situation",                    //~v11rI~
            "'*' は ここでは無効です");                            //~v11rI~
    return 4;                                                      //~v11rI~
}//dcmderrcurfile                                                  //~v11rI~
//****************************************************************//~v051I~
//!dcmdsolast                                                   //~v051I~
//*msg from last record of redirect file                        //~v051I~
//*parm1:workdir so filename                                          //~v06BI~
//*parm2:file name                                                    //~v06BR~
//*parm3:child proc rc                                                //~v06BR~
//*ret  :rc                                                     //~v056I~
//****************************************************************//~v051I~
int dcmdsolast(UCHAR *Psofname,UCHAR *Pfname,int Pcrc)                //~v06BR~
{                                                               //~v051I~
    UCHAR rec1[256],rec2[256];                                  //~v051I~
    FILE *fh;                                                   //~v051I~
    UCHAR *pc;                                                  //~v056I~
    int len,rc;                                                 //~v051I~
//*******************                                           //~v051I~
    if (!(fh=fileopen(Pfname,"r")))                             //~v051I~
        return 4;                                               //~v051I~
    *rec2=0;                                                    //~v051I~
    while(fgets(rec1,sizeof(rec1),fh))//null if error/ eof      //~v051I~
    {                                                           //~v051I~
        len=(int)strlen(rec1);          //read len              //~v051I~
        if (*(rec1+len-1)=='\n')                                //~v051I~
        {                                                       //~v051I~
            len--;                      //drop 0a               //~v051I~
            *(rec1+len)=0;                                      //~v051I~
        }                                                       //~v051I~
        if (len)                                                //~v051R~
            memcpy(rec2,rec1,(UINT)(len+1));                    //~v051R~
    }                                                           //~v051I~
    if (rc=ferror(fh),rc)                                       //~v051I~
        ufileapierr("fgets",Pfname,rc);                         //~v051R~
    fileclose(Pfname,fh);                                       //~v051R~
    if (*rec2)                                                  //~v051I~
    {                                                           //~v056I~
        for (pc=rec2;pc=strchr(pc,'%'),pc;pc++) //replace % by _//~v056I~
            *pc='_';                                            //~v056I~
//      uerrmsg("rc=%d,%s,\"%s\"",0,                               //~v51XR~
//              Pcrc,Psofname,rec2);                               //~v51XR~
        uerrmsg("%s:rc=%d, \"%s\"",0,                              //~v51XI~
                Psofname,Pcrc,rec2);                               //~v51XI~
    }                                                           //~v056I~
    return 0;                                                   //~v051I~
}//dcmdsolast                                                   //~v051I~
                                                                //~v051I~
//****************************************************************//~v061I~
//!other dos command display child shel                         //~v061I~
//*ret  :rc                                                     //~v061I~
//****************************************************************//~v061I~
int dcmd_system2(PUCLIENTWE Ppcw)                               //~v061I~
{                                                               //~v061I~
    char  *repcmd,*cmd;                                            //~v095I~
//#ifndef WXE                                                      //~v58qR~
//    KBDKEYINFO ki;                                               //~v58qR~
//#endif //!WXE                                                    //~v58qR~
    int rc;                                                     //~v061I~
#ifndef XXE                                                        //~vaa7I~
    char  cell[2];                                              //~v061I~
#endif                                                             //~vaa7I~
//  char *initcmd;                                                 //~v09uR~
    char initcmd[256];                                             //~v09uR~
#ifdef UNX                                                         //~v20HI~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
    char *pmsg;                                                    //~v20HI~
  #endif //!XXE                                                    //~v64fI~
#else  //!UNX                                                      //~v20HI~
    char *pc,*pc2;                                                 //~v40ZM~
    int len;                                                       //~v40ZM~
#endif //!UNX                                                      //~v20HI~
//*******************                                           //~v061I~
#ifndef XXE                                                        //~vaa7I~
    cell[0]=' ';    //space clear by scrcls                     //~v061I~
    cell[1]=0x07;   //backg=0=black,forg=7=white                //~v061R~
#endif                                                             //~vaa7I~
                                                                   //~v20KI~
                                                                   //~v20KI~
    if (cmd=Ppcw->UCWparm,                                      //~v061R~
        cmd && *cmd)    //operand exist                         //~v061I~
    {                                                           //~v061I~
        if (rc=dcmdwkdiredit(cmd,&repcmd),rc)   //chk wkdir ::  //~v061R~
            return 4;                                           //~v061R~
		if (rc=dcmdscrfnmedit(DCSDE_FREEINPUT*(cmd!=repcmd),Ppcw,repcmd,&repcmd),rc)//~v77yR~
        	return rc;                                             //~v77yR~
#ifdef XXE                                                         //~v64rI~
        rc=dcmdxxe1cmd(repcmd);                                    //~v64rI~
#else                                                              //~v64rI~
#ifdef WXE                                                         //~v500R~
        rc=dcmdwxe1cmd(repcmd);                                    //~v500I~
#else   //!WXE                                                     //~v500I~
        scrcls(cell);                                           //~v061R~
//      uviosetcurpos(0,0); //top left                             //~v0hiR~
#ifdef UNX                                                         //~v20KM~
    	ukbdl_shellmode(0);   //nl mode                            //~v20KI~
#endif //!UNX                                                      //~v20KM~
        rc=usystem(repcmd);                                     //~v061R~
#endif  //!WXE                                                     //~v500I~
#endif  //!XXE                                                     //~v64rI~
        if (repcmd!=cmd)    //replaced                          //~v061R~
            ufree(repcmd);                                      //~v061R~
                                                                   //~v20HI~
#ifdef UNX                                                         //~v20HI~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
      #ifdef AIX   //EUC code                                      //~v55fI~
        if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //dbcs                 //~v20HI~
            pmsg="\n何かキーを押して下さい!\n";                    //~v20HI~
        else                                                       //~v20HI~
      #endif                                                       //~v55fM~
            pmsg="\nHit any key!\n";                               //~v20HI~
#ifdef AIX                                                         //~v764R~
        uviowrttty(pmsg,strlen(pmsg));                             //~v20HI~
#else                                                              //~v764M~
//      printf(pmsg);                                              //~vb3yR~
        printf("%s",pmsg);                                         //~vb3yI~
#endif                                                             //~v764M~
        uviol_refresh();                                           //~v20HI~
  #endif //!XXE                                                    //~v64fI~
#else  //!UNX                                                      //~v20HI~
#ifndef WXE                                                        //~v500I~
        if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //dbcs              //~v061I~
            printf("\n何かキーを押して下さい!\n");              //~v061R~
        else                                                    //~v061I~
            printf("\nHit any key!\n");                         //~v061I~
#endif  //!WXE                                                     //~v500I~
#endif //!UNX                                                      //~v20HI~
#ifndef WXE                                                        //~v500I~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
//    do                                                           //~v58qR~
//    {                                                            //~v58qR~
//      ukbdcharin(&ki,0);                                         //~v58qR~
//    } while(!ki.chChar && !ki.chScan);                           //~v58qR~
      kbdwaitkey(0); 	                                           //~v58qR~
#ifdef W32                                                         //~v0k4M~
    if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //not englist mode         //~v0k4I~
//    if (!udosiswinnt())                                          //~v70rR~
//          uviowrtncell(cell,40,Gscrheight,0);//crear ime line(hit any key)//~vb4uR~
            uviowrtncell(0/*lineopt*/,cell,40,Gscrheight,0);//crear ime line(hit any key)//~vb4uI~
#endif                                                             //~v0k4M~
  #endif //!XXE                                                    //~v64fI~
#endif  //!WXE                                                     //~v500I~
//  UTRACED("dcmd2 charin",&ki,sizeof(ki));                        //~v09uR~
#ifdef UNX                                                         //~v20HI~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
        scrcls(cell);                                              //~v219I~
    	ukbdl_shellmode(1);   //nonl mode                          //~v20KI~
//unix rc is exitcode+signalcode                                   //~v20HI~
  #endif //!XXE                                                    //~v64fI~
#else  //!UNX                                                      //~v20HI~
        if (rc==255)                                                  //~v06AI~
            rc=0;                                                     //~v06AI~
        else                                                          //~v06AI~
        if (rc==-1)                                             //~v061I~
            rc=255;                                             //~v061I~
#endif //!UNX                                                      //~v20HI~
    }                                                           //~v061I~
    else                                                        //~v061I~
//**widthout cmd string parm **************************            //~v64rR~
    {                                                           //~v061I~
//      initcmd=UALLOCM(strlen(Sshellname)+4+strlen(Gshellicmd)+1);             //new buff//~v09uR~
//      UALLOCCHK(initcmd,UALLOC_FAILED);                          //~v09uR~
#ifdef UNX                                                         //~v40ZI~
#else                                                              //~v40ZI~
        pc=getenv("COMSPEC");                                      //~v09uI~
      if (pc)                                                      //~v09uI~
      {                                                            //~v09uI~
        if (*pc==' ')                                              //~v09uI~
            pc+=strspn(pc," ");                                    //~v09uI~
        pc2=strchr(pc,' ');                                        //~v09uI~
        if (pc2)                                                   //~v09uI~
//          len=(int)((long)pc2-(long)pc);                         //~v09uI~//~vafkR~
            len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~vafkI~
        else                                                       //~v09uI~
            len=(int)strlen(pc);                                   //~v09uI~
        len=min(len,(int)(sizeof(initcmd)-4-strlen(Gshellicmd)-1));//~v09uR~
        memcpy(initcmd,pc,(UINT)len);                              //~v09uR~
        *(initcmd+len)=0;                                          //~v09uR~
      }                                                            //~v09uI~
      else                                                         //~v09uI~
#endif                                                             //~v40ZI~
        strcpy(initcmd,Sshellname);                             //~v063M~
//      strcat (initcmd," /K ");    //term my exit cmd             //~v0hjR~
//      strcat (initcmd,Gshellicmd);                               //~v0hjR~
#ifndef WXE                                                        //~v500I~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
        scrcls(cell);                                           //~v061I~
  #endif //!XXE                                                    //~v64fI~
#endif  //!WXE                                                     //~v500I~
#ifdef DOS                                                         //~v0hjI~
        if (udosiswinnt())                                         //~v0hjI~
            uerrmsg("WinNT DOS shell dose not support /K switch,\n\
So type \"%s\" manualy if you want\n",                             //~v0hjI~
                    "WinNT の DOS SHELL は /K スィッチをサポートしません\n\
必用なら %s は自分でタイプしてください",                           //~v0hjI~
            Gshellicmd);                                           //~v0hjI~
        else                                                       //~v0hjI~
        {                                                          //~v0hjI~
#endif                                                             //~v0hjI~
#ifdef UNX                                                         //~v20LI~
	#ifdef XXE	                                                   //~v64rI~
//   	strcpy(initcmd,XXE_CHILDSH);                               //~v765R~
    	ulnxxgettermpgmopt(0,0,initcmd);	//0:opt,0:no operand   //~v765R~
    #endif                                                         //~v64rI~
#else  //!UNX                                                      //~v20LI~
            strcat (initcmd," /K ");    //term my exit cmd         //~v0hjI~
            strcat (initcmd,Gshellicmd);                           //~v0hjI~
#endif //!UNX                                                      //~v20LI~
#ifdef DOS                                                         //~v0hjI~
        }                                                          //~v0hjI~
#endif                                                             //~v0hjI~
//      uviosetcurpos(0,0); //top left                             //~v0hiR~
#ifndef WXE                                                        //~v500I~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
#ifdef DOS                                                         //~v09uI~
        if (UCBITCHK(Gopt2,GOPT2BOXREPCSR))  //box csr for rep mode//~v09uI~
            csrchangetype(CSRTYPINS);        //set under line csr  //~v09uI~
        else                                                       //~v09uI~
            csrchangetype(CSRTYPNOR);       //set underline csr    //~v09uI~
#else                                                              //~v09uI~
    #ifdef W32                                                     //~v09uI~
        if (UCBITCHK(Gopt2,GOPT2BOXREPCSR))  //box csr for rep mode//~v09uI~
            csrchangetype(CSRTYPINS);        //set under line csr  //~v09uI~
        else                                                       //~v09uI~
            csrchangetype(CSRTYPNOR);       //set underline csr    //~v09uI~
    #else       //os/2                                             //~v09uI~
    #endif                                                         //~v09uI~
#endif                                                             //~v09uI~
  #endif //!XXE                                                    //~v64fI~
#endif  //!WXE                                                     //~v500I~
#ifdef UNX                                                         //~v20KI~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
    #ifdef LNX                                                     //~v765I~
        ulnxlgetshellpgm(0,initcmd); 	//sh/bash etc              //~v765R~
    #endif                                                         //~v765I~
    	ukbdl_shellmode(2);   //nl,echo mode                       //~v20KI~
  #endif //!XXE                                                    //~v64fI~
#endif //!UNX                                                      //~v20KI~
        rc=usystem(initcmd);                                    //~v063R~
#ifdef UNX                                                         //~v20KI~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
        scrcls(cell);                                              //~v20KI~
        uviol_refresh();                                           //~v20KM~
    	ukbdl_shellmode(3);   //nonl,noecho mode                   //~v20KI~
  #endif //!XXE                                                    //~v64fI~
#endif //!UNX                                                      //~v20KI~
//      ufree(initcmd);                                            //~v09uR~
#ifdef UNX                                                         //~v20JI~
//      uerrmsg("Child schell ended rc=%d(x%04x)",                 //~v764R~
        uerrmsg("Child shell ended rc=%d(x%04x)",                  //~v764I~
                "子シェルの終了 rc=%d(x%04x)",                     //~v20JI~
                rc,rc);                                            //~v20JI~
#else  //!UNX                                                      //~v20JI~
//      uerrmsg("Child schell ended rc=%d",                        //~v764R~
        uerrmsg("Child shell ended rc=%d",                         //~v764I~
                "子シェルの終了 rc=%d",                         //~v063I~
                rc);                                            //~v063I~
        if (rc==255)                                            //~v061R~
            rc=0;                                               //~v061I~
        else                                                    //~v061I~
            if (rc==-1)                                         //~v061R~
                rc=255;                                         //~v061R~
#endif //!UNX                                                      //~v20JI~
    }                                                           //~v061I~
#ifndef WXE                                                        //~v500I~
  #ifndef XXE	//wait by "read" shellcmd                          //~v64fI~
    scrfulldraw(Ppcw);  //redraw full scr                       //~v061I~
//  scrcsrtyperestore();                                           //~v09lR~
    csrforcewritereq(); //force csr write on previous position     //~v09sI~
#ifdef DOS                                                         //~v09tM~
#else                                                              //~v09tM~
    #ifdef W32                                                     //~v09tM~
    	IFDEF_WINCON(dcmdrestoreconsolemode(0));                   //~v781I~
    #else       //os/2                                             //~v09tM~
        kbdreinit();                                               //~v09tM~
    #endif                                                         //~v09tM~
#endif                                                             //~v09tM~
  #endif //!XXE                                                    //~v64fI~
#endif  //!WXE                                                     //~v500I~
    return rc;                                                  //~v061I~
}//dcmd_system2                                                 //~v061I~
                                                                //~v061I~
//****************************************************************//~v06nI~
//!get stdout file for menu option 6                                  //~v06zR~
//*parm1:output filename (::SOxxx format)                       //~v06nI~
//*parm2:output fullpathname(option)                            //~v06nI~
//*ret  :rc                                                     //~v06nI~
//****************************************************************//~v06nI~
int dcmdgetsofname(UCHAR *Psofname,UCHAR *Pfullpath)                  //~v06zR~
{                                                               //~v06nI~
    char fpath[_MAX_PATH];                                         //~v57tR~
    PUFILEH pfh;                                                      //~v06yI~
    int rc,sono,ii;                                                   //~v06zR~
    FILE *fh;                                                         //~v06zR~
//*******************                                           //~v06nI~
    for (ii=0,sono=(int)Glastsono;ii<MAXSONO;ii++,sono++)             //~v06zR~
    {                                                           //~v06nR~
        if (sono>=MAXSONO)                                            //~v06zI~
            sono-=MAXSONO;                                            //~v06zI~
        sprintf(Psofname,Sstdoef,sono);                               //~v06zR~
        Glastsono=(UCHAR)(sono+1);  //next session start              //~v06zR~
        if (!filesrchpfh(Psofname,fpath,&pfh))   //already editing //~v57tR~
            continue;                                                 //~v06yI~
        rc=filefind(Psofname,fpath,0,FFNONFMSG|FFNODIRMSG);//no need fstat//~v57tR~
        if (rc!=4)      //other than not found                        //~v06zI~
            if (rc)     //err                                         //~v06zR~
                continue;                                             //~v06zR~
//#ifdef UNX                                                       //~v79PR~
        if (!*Slockfnm)      //not yet SOn lock                    //~v21fI~
        {                                                          //~v21fI~
#ifdef UNX                                                         //~v79PI~
            sprintf(Slockfnm,"%s.lock",fpath);                     //~v57tR~
#else                                                              //~v79PI~
            sprintf(Slockfnm,"%s.lck",fpath); //8.3 name for DOS,OS/2//~v79PI~
#endif                                                             //~v79PI~
//          if (unx_fsetlock(Slockfnm))  //lock failed             //~v79PR~
			if (ufsetlock(UFSLO_LOCK,Slockfnm))	                   //~v79PR~
            {                                                      //~v21fI~
                *Slockfnm=0;   //id of free                        //~v21fI~
                continue;                                          //~v21fI~
            }                                                      //~v21fI~
        }                                                          //~v21fI~
//#endif                                                           //~v79PR~
        if (!(fh=fopen(fpath,"w")))  //lock chk                    //~v57tR~
            continue;                                                 //~v06zR~
        fputs("\n",fh);                                            //~v07dI~
        fclose(fh);//clear                                            //~v06zR~
        if (Pfullpath)                                                //~v06zR~
            strcpy(Pfullpath,fpath);                               //~v57tR~
        return 0;                                                     //~v06zR~
    }//for wrap                                                 //~v06nR~
    return dcmdnowork();                                              //~v06zI~
}//dcmdgetsofname                                               //~v06nI~
                                                                //~v06nI~
//**************************************************************** //~v58DR~
//!put 1line cmdlog for cmd panel                                  //~v58DR~
//*parm1:fh                                                        //~v58DR~
//*parm2:cmd string                                                //~v58DR~
//*ret  :rc                                                        //~v58DR~
//**************************************************************** //~v58DR~
//int dcmdputcmdlog(FILE *Pfh,char *Pcmd)                          //~v58GR~
int dcmdputcmdlog(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt,char *Pcmd)//~v58GI~
{                                                                  //~v58DR~
	int len,rc;                                                    //~v58GI~
	char *pc;                                                      //~v58GI~
    char wk[MAXCOLUMN*2];                                          //~v9@5I~
#ifdef FTPSUPP                                                     //~v9@5I~
    PUFILEH pfh;                                                   //~v9@5I~
#endif                                                             //~v9@5I~
//***************                                                  //~v58DR~
//  fprintf(Pfh,"%s ===>> %s\n",(char *)utimeedit("HH:MM:SS",0),Pcmd);//~v58GR~
//  fflush(Pfh);                                                   //~v58GR~
//  pc=malloc(strlen(Pcmd)+32);                                    //~v9@5R~
    len=(int)strlen(Pcmd)+32;                                      //~v79uR~
    if (len>sizeof(wk))                                            //~v9@5I~
    	pc=umalloc((UINT)len);                                     //~v79uR~
    else                                                           //~v9@5I~
    	pc=wk;                                                     //~v9@5I~
    if (Popt)                                                      //~v58GI~
	    len=sprintf(pc,"%s ===>> %s",(char *)utimeedit("HH:MM:SS",0),Pcmd);//~v58GR~
    else                                                           //~v58GI~
	    len=sprintf(pc,"         ===>> %s",Pcmd);                  //~v58GR~
#ifdef FTPSUPP                                                     //~v9@5M~
    pfh=UGETPFH(Pplh);                                             //~v9@5R~
  if (UCBITCHK(pfh->UFHflag8,UFHF8TSOFSMODE))                      //~v9@5I~
	rc=xetsoupdateplh(XETSOUL_CMDLOG,Ppcw,Pplh,pc,len);            //~v9@5R~
  else                                                             //~v9@5I~
#endif                                                             //~v9@5I~
	rc=fcmdisrtline(Ppcw,Pplh,pc,len);                             //~v58GR~
    if (pc!=wk)                                                    //~v9@5I~
    	ufree(pc);                                                 //~v9@5I~
    return rc;                                                     //~v58GR~
}//dcmdputcmdlog                                                   //~v58DR~
//****************************************************************    //~v06zI~
//!get new temp file nme for cmd stdout                               //~v06zI~
//*parm1:output filename (::SO!xxx format)                            //~v06zI~
//*parm2:output fullpathname(option)                                  //~v06zI~
//*parm3:output opend fileh set area(option,if null file is closed)   //~v06zI~
//*parm4:input  cmd string to be write(option)                        //~v06zI~
//*ret  :rc                                                           //~v06zI~
//****************************************************************    //~v06zI~
int dcmdgetsofname2(UCHAR *Psofname,UCHAR *Pfullpath,FILE **Ppfileh,UCHAR *Pcmd)//~v06zI~
{                                                                     //~v06zI~
    char fpath[_MAX_PATH];                                         //~v57tR~
//  int  rc,ii;                                                    //~v63cR~
#ifndef WXE                                                        //~vafgI~
    FILE *fh=0;                                                       //~v06zI~
#endif                                                             //~vafgI~
//*******************                                                 //~v06zI~
//#ifdef UNX                                                       //~v63cR~
//	dcmdfresetlock2();	//for the case previous err                //~v63cR~
//#endif                                                           //~v63cR~
//    strcpy(Psofname,Sstdoef);                                    //~v63cR~
    strcpy(Psofname,DCMDDCMDSO);                                   //~v63cI~
//  for (ii=0;ii<MAXTEMP;ii++)                                     //~v63cR~
    for (;;)                                                       //~v63cI~
    {                                                                 //~v06zI~
	    if (!filefullpath(fpath,Psofname,_MAX_PATH))   //::(pid)so //~v63cI~
        	break;                                                 //~v63cI~
//      if (ii)                                                    //~v63cR~
//          *(Psofname+TEMPIDPOS+ii-1)=TEMPID;                     //~v63cR~
//      *(Psofname+TEMPIDPOS+ii)=0;                                //~v63cR~
//      rc=filefind(Psofname,fpath,0,FFNONFMSG|FFNODIRMSG);//no need fstat//~v63cR~
//      if (rc && rc!=4)        //err other than not found         //~v63cR~
//          continue;                                              //~v63cR~
//#ifdef UNX                                                       //~v63cR~
//      sprintf(Slockfnm2,"%s.lock",fpath);                        //~v63cR~
//      if (unx_fsetlock(Slockfnm2))  //lock failed                //~v63cR~
//      {                                                          //~v63cR~
//          *Slockfnm2=0;   //id of free                           //~v63cR~
//          continue;                                              //~v63cR~
//      }                                                          //~v63cR~
//#endif                                                           //~v63cR~
#ifndef WXE		//xesyscmd process redirect                        //~v58JI~
        if (!(fh=fopen(fpath,"w")))  //protect other session       //~v57tR~
//          continue;                                              //~v63cR~
            break;                                                 //~v63cI~
        Gdcmdtempf|=GDCMDTEMPF_DCMDSO; //del at term               //~v63cI~
//      if (Pcmd)                   //output req                   //~v58JR~
//      {                                                          //~v58JR~
//          fprintf(fh,"%s ===>> %s\n",(char *)utimeedit("HH:MM",0),Pcmd);//~v58CR~
//          fflush(fh);                                            //~v58CR~
//  		dcmdputcmdlog(fh,Pcmd);                                //~v58GR~
//      }                                                          //~v58JR~
        if (Ppfileh)    //requested opend fileh                       //~v06zI~
            *Ppfileh=fh;    //return it,closed after cmd output       //~v06zI~
        else                                                          //~v06zI~
            if (fclose(fh)) //for edit open                           //~v06zR~
//              continue;                                          //~v63cR~
                break;                                             //~v63cI~
#else  //WXE                                                       //~v58JI~
        if (Ppfileh)    //requested opend fileh                    //~v58JI~
            *Ppfileh=0;     //return it,closed after cmd output    //~v58JI~
#endif                                                             //~v58JI~
        if (Pfullpath)                                                //~v06zI~
            strcpy(Pfullpath,fpath);                               //~v57tR~
        return 0;                                                     //~v06zI~
    }//for wrap                                                       //~v06zI~
    return dcmdnowork();                                              //~v06zI~
}//dcmdgetsofname2                                                    //~v06zI~
//****************************************************************//~v06nI~
//!delete allocated stdout redirect file                        //~v06nI~
//*parm:none                                                    //~v06nI~
//*ret :rc                                                      //~v06nI~
//****************************************************************//~v06nI~
int dcmdterm(void)                                              //~v06nI~
{                                                               //~v06nI~
    int rc=0;                                                         //~v06xI~
#ifdef xxxxxxxxxx                                                     //~v06xI~
    char fullpath[_MAX_PATH];                                   //~v06nI~
    char sofname[2+MAXFILENAME+1];                                    //~v06BR~
    UCHAR bitmask;                                              //~v06nI~
    int bytepos,ii;                                                   //~v06xR~
//*******************                                           //~v06nI~
    for (ii=0;ii<sizeof(Ssoallocsw)*8;ii++)                     //~v06nI~
    {                                                           //~v06nI~
        bytepos=ii/8;                                           //~v06nI~
        bitmask=(UCHAR)(0x80>>(ii%8));                          //~v06nI~
        if (UCBITCHK(Ssoallocsw[bytepos],bitmask))              //~v06nI~
        {                                                       //~v06nI~
            sprintf(sofname,Sstdoef,ii+1);                      //~v06nI~
            if (filefullpath(fullpath,sofname,_MAX_PATH))//return fullpath//~v06nR~
            {                                                   //~v06nI~
                if (uremove(fullpath))                          //~v06nI~
                    rc=4;                                       //~v06nI~
            }                                                   //~v06nI~
            else                                                //~v06nI~
                rc=4;                                           //~v06nI~
        }                                                       //~v06nI~
    }//for wrap                                                 //~v06nI~
#endif                                                                //~v06xI~
#ifdef UNX                                                         //~v21fM~
	dcmdfresetlock2();                                             //~v21fR~
#endif                                                             //~v79PI~
    if (*Slockfnm) //I'v gotten lock SOn lock                      //~v21fI~
//  	unx_fresetlock(Slockfnm);	//free                         //~v79PR~
		ufsetlock(UFSLO_UNLOCK,Slockfnm);                          //~v79PR~
//#endif                                                           //~v79PR~
    dcmdwdclear();  //for grepwork etc                             //~v636I~
    return rc;                                                  //~v06nI~
}//dcmdterm                                                     //~v06nI~
//****************************************************************    //~v06tI~
//!append so to current edit screen                                   //~v06tI~
//*parm1:pcw                                                          //~v06tI~
//*parm2:sofile name                                                  //~v06tI~
//*ret :rc                                                            //~v06tI~
//****************************************************************    //~v06tI~
int dcmdappendso(PUCLIENTWE Ppcw,UCHAR *Psofname,UCHAR *Pcmd)         //~v06tI~
{                                                                     //~v06tI~
    PUFILEH pfh;                                                      //~v06tI~
    PUFILEC pfc;                                                      //~v06tI~
    PULINEH plh;                                                      //~v06uR~
    int rc;                                                           //~v06tI~
    char errtext[_MAX_PATH+64];                                    //~v58GI~
//*******************                                                 //~v06tI~
    pfc=Ppcw->UCWpfc;                                                 //~v06tI~
    pfh=pfc->UFCpfh;                                                  //~v06tI~
    plh=UGETQPREV(UGETQEND(&pfh->UFHlineque));                        //~v06tI~
	if (dcmdputcmdlog(Ppcw,plh,1,Pcmd))//cmdline log               //~v58GI~
    	return 4;                                                  //~v58GI~
    plh=UGETQNEXT(plh);		//plh after isrt                       //~v58GR~
    pfc->UFCcurtop=plh;                                            //~v58GI~
    UCBITON(plh->ULHflag3,ULHF3CMDECHO);                           //~v58GI~
//  filesetcsr(Ppcw,0,0,0); //data field,fldtop,reset csr setting  //~v58JR~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);                               //~v58GI~
//COPY AFTER                                                          //~v06tI~
	if (!*Psofname)		                                           //~v58GI~
		return dcmdputcmdlog(Ppcw,plh,0,"All lines are redirected.");//~v58JR~
    Ppcw->UCWparm=Psofname;                                           //~v06tI~
    capfcmdi(Ppcw,plh,0);           //parm is operand(filename) only  //~v06tI~
    *plh->ULHlinecmd=ULCCMDAFTER;                                     //~v06tI~
    rc=func_copy_file(Ppcw);    //file cmd call                       //~v06tI~
    UCBITOFF(plh->ULHflag3,ULHF3TEMPLCMD);//not saved at savependlcmd //~v06tI~
//page scroll                                                         //~v06tI~
//  if (!rc)                                                       //~v58GR~
//  {                                                              //~v58GR~
//      plh=UGETQNEXT(plh);                                        //~v58GR~
//      pfc->UFCcurtop=plh;                                        //~v58GR~
//      UCBITON(plh->ULHflag3,ULHF3CMDECHO);                       //~v58GR~
//      filesetcsr(Ppcw,0,0,0); //data field,fldtop,reset csr setting//~v58GR~
//      UCBITON(Ppcw->UCWflag,UCWFDRAW);                           //~v58GR~
//  }                                                              //~v58GR~
//  else                                                           //~v58GR~
    if (rc)                                                        //~v58GI~
    {                                                              //~v58GI~
    	sprintf(errtext,"No output line is on %s.",Psofname);      //~v58JR~
		dcmdputcmdlog(Ppcw,plh,0,errtext);                         //~v58GI~
    }                                                              //~v58GI~
    filesetcsr(Ppcw,0,0,0); //data field,fldtop,reset csr setting  //~v58JI~
    return rc;                                                        //~v06tI~
}//dcmdappendso                                                       //~v06tI~
#ifdef WXE                                                         //~v500I~
//**************************************************************** //~v500I~
//to insert pause;write bat file and execute                       //~v500I~
//*ret :rc                                                         //~v500I~
//**************************************************************** //~v500I~
int dcmdwxe1cmd(char *Pcmd)                                        //~v500R~
{                                                                  //~v500I~
#ifdef AAA                                                         //~v76tM~
	FILE *fh;                                                      //~v500I~
    char cmdfnm[_MAX_PATH];                                        //~v500I~
    char tempcmdfnm[16];                                           //~v500R~
#else                                                              //~v76tI~
//  char cmdfnm[MAXCOLUMN],*peditcmd;                              //~v76tR~//~va03R~
    char cmdfnm[MAXPARMSZ],*peditcmd;                              //~va03I~
#endif                                                             //~v76tI~
    int rc;                                                        //~v500I~
#ifdef AAA                                                         //~v76tI~
    int len;                                                       //~v58fI~
#endif                                                             //~v76tI~
//***************************                                      //~v500I~
#ifdef AAA                                                         //~v76tI~
//  strcpy(tempcmdfnm,WORKDIRPATHID TEMPCMDFNM);                   //~v58eR~
    strcpy(tempcmdfnm,WORKDIRPATHID WXETEMPCMDFNM);                //~v58eI~
    strcat(tempcmdfnm,".BAT");                                     //~v500I~
    if (!filefullpath(cmdfnm,tempcmdfnm,_MAX_PATH))                //~v500I~
        return 4;                                                  //~v500I~
    fh=fopen(cmdfnm,"w");                                          //~v500R~
    if (!fh)                                                       //~v500I~
    {	                                                           //~v500I~
    	ufileapierr("fopen",tempcmdfnm,errno);	                   //~v500I~
        return 8;                                                  //~v500I~
    }                                                              //~v500I~
    len=(int)strlen(Pcmd);                                         //~v58fI~
//  if (len>4                                                      //~v64qR~
//  &&  (!stricmp(Pcmd+len-4,".BAT")||!stricmp(Pcmd+len-4,".CMD")))//~v64qR~
//    fprintf(fh,"call %s\n",Pcmd);                                //~v64qR~
//  else                                                           //~v64qR~
//    fprintf(fh,"%s\n",Pcmd);                                     //~v64qR~
//    fprintf(fh,"@pause\n");                                      //~v64qR~
    fprintf(fh,"(%s && @pause) || @pause\n",Pcmd); //1st pause if cmd ok,2nd pause if cmd fail//~v64qR~
    fclose(fh);                                                    //~v500I~
#else                                                              //~v76tI~
    if (Gdcmd2wxeshellcmd && *Gdcmd2wxeshellcmd)                   //~v76tI~
    {                                                              //~v76tI~
        ucmdparmedit(1,Gdcmd2wxeshellcmd,Pcmd,0,&peditcmd);//1:concat if no %,0:no vfmt parm//~v76tR~
        strcpy(cmdfnm,peditcmd);                                   //~v76tI~
    }                                                              //~v76tI~
    else                                                           //~v76tI~
	    sprintf(cmdfnm,"((%s) && @pause) || @pause",Pcmd); //1st pause if cmd ok,2nd pause if cmd fail//~v76tR~
#endif                                                             //~v76tI~
	rc=usystem(cmdfnm);                                            //~v500R~
    if (!rc)  	//override cmdfnm ended msg by original cmd name   //~v500I~
    	uerrmsg("%s ended,rc=%d(x%02x)",                           //~v500I~
        	    "%s が終了,rc=%d(x%02x)",                          //~v500I~
            	Pcmd,rc,rc);                                       //~v500I~
    return rc;                                                     //~v500I~
}//dcmdwxe1cmd                                                     //~v500I~
#endif //WXE                                                       //~v500I~
#ifdef XXE                                                         //~v64fI~
//**************************************************************** //~v64fI~
//to insert read;write .sh file and execute                        //~v64fI~
//*ret :rc                                                         //~v64fI~
//**************************************************************** //~v64fI~
int dcmdxxe1cmd(char *Pcmd)                                        //~v64fI~
{                                                                  //~v64fI~
	FILE *fh;                                                      //~v64fI~
    char cmdfnm[_MAX_PATH];                                        //~v64fI~
    char cmdstr[_MAX_PATH+256];                                    //~v64rI~
    char tempcmdfnm[32];                                           //~v64rR~
    int rc;                                                        //~v64fI~
//***************************                                      //~v64fI~
    sprintf(tempcmdfnm,DCMDSYSCMDTEMPF);                           //~v64rR~
    if (!filefullpath(cmdfnm,tempcmdfnm,_MAX_PATH))                //~v64fI~
        return 4;                                                  //~v64fI~
    fh=fopen(cmdfnm,"w");                                          //~v64fI~
    if (!fh)                                                       //~v64fI~
    {                                                              //~v64fI~
    	ufileapierr("fopen",tempcmdfnm,errno);                     //~v64fI~
        return 8;                                                  //~v64fI~
    }                                                              //~v64fI~
	Gdcmdtempf|=GDCMDTEMPF_SYSCMDF;                                //~v64rI~
    fprintf(fh,"%s\n",Pcmd);                                       //~v64fI~
//	fprintf(fh,"echo \"\n!Hit Any Key!\"\n");                      //~v765R~
//	fprintf(fh,"echo \"\n!Hit Enter Key!\"\n");                    //~v765R~
  	fprintf(fh,"echo \" \"\n");                                    //~v765I~
  	fprintf(fh,"echo \"! Hit Enter Key !\"\n");                    //~v765I~
//  fprintf(fh,"read\n");                                          //~v765R~
    fprintf(fh,"read x1\n"); //syntax err when operand missing on Kubuntu//~v765I~
    fclose(fh);                                                    //~v64fI~
    uattrxon(cmdfnm);    //user x bit on                           //~v64rI~
//  sprintf(cmdstr,"%s -x %s",XXE_CHILDSH,cmdfnm);                 //~v764R~
    ulnxxgettermpgmopt(0,cmdfnm,cmdstr);	//0:opt                //~v765I~
	rc=usystem(cmdstr);                                            //~v64rR~
    if (!rc)  	//override cmdfnm ended msg by original cmd name   //~v64fI~
    	uerrmsg("%s ended,rc=%d(x%02x)",                           //~v64fI~
        	    "%s が終了,rc=%d(x%02x)",                          //~v64fI~
            	Pcmd,rc,rc);                                       //~v64fI~
    return rc;                                                     //~v64fI~
}//dcmdxxe1cmd                                                     //~v64fI~
#endif //XXE                                                       //~v64fI~
#ifdef UNX                                                         //~v21fI~
//**************************************************************** //~v21fI~
//free temp stdout lock                                            //~v21fI~
//*ret :rc 8                                                       //~v21fI~
//**************************************************************** //~v21fI~
void dcmdfresetlock2(void)                                         //~v21fI~
{                                                                  //~v21fI~
    if (*Slockfnm2) //I'v gotten lock                              //~v21fI~
    {                                                              //~v21fI~
    	unx_fresetlock(Slockfnm2);	//free                         //~v21fI~
    	*Slockfnm2=0;                                              //~v21fI~
    }                                                              //~v21fI~
    return;                                                        //~v21fI~
}//dcmdfresetlock2                                                 //~v21fR~
#endif                                                             //~v21fI~
//**************************************************************** //~v0k4I~
//!err msg                                                         //~v0k4I~
//*ret :rc 8                                                       //~v0k4I~
//**************************************************************** //~v0k4I~
//int dcmdextnmerr(void)                                           //~v51XR~
int dcmdextnmerr(char *Pfnm)                                       //~v51XI~
{                                                                  //~v0k4I~
//*******************                                              //~v0k4I~
//  uerrmsg("Ext name err",                                        //~v51XR~
//          "拡張子名エラー");                                     //~v51XR~
    uerrmsg("Ext name err(%s)",                                    //~v51XI~
            "拡張子名エラー(%s)",                                  //~v51XI~
				Pfnm);                                             //~v51XI~
    return 8;                                                      //~v0k4I~
}//dcmdextnmerr                                                    //~v656R~
//****************************************************************    //~v06zI~
//!err msg                                                            //~v06zI~
//*ret :rc 8                                                          //~v06zI~
//****************************************************************    //~v06zI~
int dcmdnowork(void)                                                  //~v06zI~
{                                                                     //~v06zI~
//*******************                                                 //~v06zI~
//    uerrmsg("No work file for redirect is available",            //~v65aR~
//            "使用できるリダイレクト用のファイルがありません");   //~v65aR~
    uerrmsg("No work file for redirect is available,retry after delete orphaned ::so_.lock file",//~v65aR~
            "使用できるリダイレクト用のファイルがありません,削除もれの::so_.lockファイルを削除して再試行してください。");//~v65aR~
    return 8;                                                         //~v06zM~
}//dcmdnowork                                                         //~v06zI~
//**************************************************************** //~v57sI~
//!err msg                                                         //~v57sI~
//*ret :rc 4                                                       //~v57sI~
//**************************************************************** //~v57sI~
int dcmdxprlblerr(void)                                            //~v57sR~
{                                                                  //~v57sI~
   	uerrmsg("label is supported only for * and **",                //~v57sI~
            "行ラベルは \"*\" か \"**\"のときに使用。");           //~v57sI~
   	return 4;                                                      //~v57sI~
}//dcmdxprlblerr                                                   //~v57sR~
//**************************************************************** //~v58HI~
//!err msg                                                         //~v58HI~
//*ret :rc 4                                                       //~v58HI~
//**************************************************************** //~v58HI~
int dcmdredirectparmerr(void)                                      //~v58HI~
{                                                                  //~v58HI~
   	uerrmsg("redirect parm err.",                                  //~v58HI~
            "リダイレクト指定エラー。");                           //~v58HI~
   	return 4;                                                      //~v58HI~
}//dcmdxprlblerr                                                   //~v58HI~
