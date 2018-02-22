//*CID://+vbi3R~:                             update#=  356;       //~vbi3R~
//*************************************************************
//*xefile.c*                                                       //~v06zR~
//**load/save/edit/browse/end/cancel                            //~v020R~
//*************************************************************
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb5b:160913 additional to vb54, DBCS space altch is changable by TAB cmd//~vb5bI~
//vb54:160903 TAB cmd new option to set altch; TAB {on|off} [altch1 [altch2]]//~vb4BI~
//vb4B:160819 (BUG) missing clear Gsubgblopt:XESUB_GBLOPT_WILDPATH flag before return//~vb4BI~
//vb3b:160606 (BUG)edit cmd fnm was pasted by C+w on dirlist cause "new file"//~vb3bI~
//vb2n:160201 (W32)use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode(like as (LNX)b2j)//~vb2nI~
//vb2j:160129 (LNX)use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode//~vb2jI~
//vb2e:160122 (LNX)convert filename according IOCHARSET mount option//~vb2eI~
//vaze:150112 expand MAXLINEDATA 9999 to 32760                     //~vazeI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//va6z:000706 (BUG)sometimes,err msg invalid name format when edit parameter err//~v6azI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va36:100203 (BUG)can not save to itself if file update was whole undoed after once saved//~va36I~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1B:091112 (UTF8)hdrline codetype ftrom cmd buff if avail       //~va1BI~
//va1e:091101_(UTF8) retry by lc for f2l err at load if no CPU8 option specified//~va1eI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          files encoded by utf8                                  //~va00I~
//          reject edit already browsing file with CPU8 conversion error at load//~va00I~
//          chk same CPxx status for dup open                      //~va00I~
//          assume IE if copy target is IE                         //~va00I~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH)//~va03I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78T:080615 (BUG)3270 remote err is not chked                    //~v78TI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v92j:080506 (UTF:BUG)coption of path profile is not reflect on dirlist hdr//~v92jI~//~va00I~
//v78j:080312 (WXE)ABEND by push x on right top of window          //~v78jI~
//v78c:080306 (SYN:BUG)SYNOK should be reset when tab ctr changed  //~v78cI~
//v780:080212 syntaxhighlight support                              //~v780I~
//v77L:080206 (BUG)EXE cmd ABEND when "END" cmd closed all panel   //~v77LI~
//v922:080107 (UTF)explicitly display locale file id on hdr line even when not uytf8 env//~v922I~//~va00I~
//v90r:071113 (UTF8) display filename by utf8                      //~v90rI~//~va00I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v70c:060731 (WXEXXE:BUG)cb is not written by the reason of file updated from read time by the other process. and alloc area not freed at termination.//~v70cI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v675:051226 (BUG of v66j)abend by dup enq CB pcw when split scr,"e ::cb" at 2nd , paste in 1st,"e ::cb" at 1st;//~v675I~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//~v62bI~
//v61s:050306 for multiple found reverse support;change structure of mfwtbl(offs,len,next entry offset ushort count)//~v61sI~
//v60z:050204 (BUG)eb after eh cmd rejected by mixmode             //~v60zI~
//v60s:050130 support display width change without close current opened//~v60sI~
//v60j:050129 (BUG)csr pos is invalid for pair/same search after tabctr changed//~v60jI~
//            same thing is for all filechktabdbcs user;so reset at tabctr change time//~v60jI~
//v555:040202 (FTP)hosts init is required at save only             //~v555I~
//v54d:040103 split xefile.c to xefile.c xefile14.c                //~v54dI~
//v544:040101 (UNX,FTP)timestamp is by slink source if slink       //~v544I~
//v542:031223 (WIN,UNX)remote file edit/save                       //~v542I~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v53UI~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v50QI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v50c:021214 alloc re-call file by edit cmd without option for previously bin mode opend//~v50cI~
//v50a:021207 (BUG)1st line cut when open bin file(optbin) with /Mnn(width) option//~v50aI~
//v49i:020806 (UNX:BUG)special file err when new file save         //~v49iI~
//v49g:020713 (UNX)list special file also to dir list(fifo.socket,char/blk device)//~v49gI~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v480:020416 (BUG)eol chng msg for eol=0a only                    //~v480I~
//v47X:020413 mac file support(eol=0x0d) /Mm                       //~v47XI~
//v47M:020330 (UNX)change to UNIX file for mixed eol for unix version//~v47MI~
//v47L:020330 do save of not updated file if eol-id chnge specified//~v47LI~
//v472:020202 (BUG)ufcleft not set for col6 when newfile for ek cmd//~v472I~
//v458:011209 (BUG)bh after eh is rejected                         //~v458I~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v440:011125 browse hex                                           //~v440I~
//v43h:011030 (BUG)no highlight pair when on the same line         //~v43hI~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v41qI~
//v41q:010830 no split msg when out of line range for partial file edit//~v414I~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v40A:010707 LINUX:mdir support                                   //~v40AI~
//v40y:010625 issue warning:already browse open because /m option in-effentive//~v40yI~
//v40u:010617 wild-card support for path name if dir contain only one member.//~v40uI~
//            (replace v143)                                       //~v40uI~
//v20D:001103 LINUX support:filename compare is case sensitive     //~v20DI~
//v202:000929 LINUX support(ufileisvfat is for DPMI and WIN only)  //~v202I~
//v19X:000928 LINUX support(save uid/gid on UFILEH/UDIRH)          //~v19XI~
//v19W:000928 LINUX support(4 bye attr for also UFILEH)            //~v19WI~
//v19v:000923 LINUX support(set UNIX file when file len=0)         //~v19vI~
//v19r:000917 LINUX support(set New file attt to UNIX)             //~v19rI~
//v19n:000915 LINUX support(msg PC file,but not UNIX file)         //~v19nI~
//v185:010128 browse/edit file when only one menmber of dir is optional by /l option(dir list)//~v185I~
//v154:000314 csr wait mark for end_file,cancel_file               //~v154I~
//v143:000210:enter edit/browse mode for wild card edit/browse/select if only one member//~v143I~
//v13r:991108 (BUG)width parm ignored without b option like as /M16//~v13rI~
//v13n:991031 warning to doubled display for dir                   //~v13nI~
//v13d:991023 *\ support for filecmd(save/repl/create/append/copy/move/ini)//~v13dI~
//            fcmd.c file.c                                        //~v13dI~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v11i:990718 edit cmd help                                        //~v11iI~
//v10Y:990606 support input range by hex offset value(/NXxxx-Xxxx) for edit/browsw cmd//~v10YI~
//v10X:990605 hex digit lineno display for binary file             //~v10XI~
//v10N:990502 support record width of binary by optbin             //~v10NI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10H:990417 (BUG)uerrmsg parm count chk by xuerpck               //~v10HI~
//v10G:990417 EB/BB/SB for "e /mx","b /mx","s /mb"                 //~v10GI~
//v10F:990417 force width= for CLIPBOAD file etc                   //~v10FI~
//v10D:990417 limit screen width function to browse only           //~v10DI~
//v10B:990411 cid for margin file when line width specified.(issue warning).//~v10BI~
//            if in-margin case give up to set cid,else search cid from last//~v10BI~
//v10y:990410 (BUG)at load time,eol dropped when split last line is 1 byte(+eol) and//~v10yI~
//            net line is also splitted.                           //~v10yI~
//v10u:990406 read mode default is PC and UNIX(write mode is PC if 0d0a found)//~v10uI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v10k:990322 (BUG)after select cmd for new file on dirlist,end with no update//~v10kI~
//            or cancel update file cause deletion of parent dir plh.//~v10kI~
//            So locate cmd faile and move csr to last entry.      //~v10kI~
//v10h:990117 (BUG)of10e;copy file into edit screen at first.      //~v10hI~
//            Slinewidth is not yet initialized if not through edit cmd//~v10hI~
//v10e:981218 e/b cmd display width parm for bin file              //~v10eI~
//v10c:981218 if explicitly text mode specified,request no optbin  //~v10cI~
//v10a:981213 (BUG)if last line ended remaining 1 byte,last byte is dropped.//~v10aI~
//v109:981213 (BUG of v106)not yet enqed to pfh,UGETPFH failed.    //~v109I~
//v108:981213 binary mode edit(no crlf/no split process)           //~v108I~
//v107:981213 use new opt of ufgetsinit for binary chk(del filechkbin)//~v107I~
//v103:981212 (BUG)for binaly file edit,last 0d0a is added         //~v103I~
//            0d0a is added at end of file eveif input has no 0d0a //~v103I~
//            skip add only when thatline is at end of file,if moved to other//~v103I~
//            position,\d0a is added.                              //~v103I~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0ia:980530 add APPend cmd                                       //~v0iaI~
//v0hK:980418 binary file chk.(reject tab clear)                   //~v0fKI~
//v0fs:971109 (BUG)fullpath fail when select cmd with quatation    //~v0fsI~
//				   for space containing filename(a\"b c" cause err)//~v0fsI~
//v0fq:971109 new file by select cmd has alias but it is temporary name//~v0fqI~
//            it may duplicated alias name.                        //~v0fqI~
//            dont created new pdh if new,isrt at end file if new file.//~v0fqI~
//v0fm:971103 new function to set filename and alias to ufh        //~v0fmI~
//v0f9:971017 UFCFLFN flag for lfn(common to os2/w95/gcc/dos)      //~v0f9I~
//v0e8:970915 (BUG)need expand before valid spf line chk           //~v0e8I~
//v0e2:970914 deny of v0bd;isrt updated line is splitted after re-load.//~v0e2I~
//                         it is confusing because not same line imsge.//~v0e2I~
//v0d5:970831 split xefile13 from xefile,fileregist etc.           //~v0d5I~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cn:970813 RENUM undo support(move filerenum from xefile to xefile12)//~v0cnI~
//v0cl:970811 spf NUM field support                                //~v0clI~
//v0bd:970726 split line size redundancy for split line update     //~v0bdI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0ba:970726 split xefile,xefile12(save)                          //~v0baI~
//v0b9:970725 (BUG)cid for long line(multiline record) has to set at last line//~v0b9I~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -filetoplinecid/filegetcid return rc                  //~v0avI~
//v0al:970713 split msg for first record not last                  //~v0alI~
//v0ai:970712 renum for split line(same lineno)                    //~v0aiI~
//v0ae:970712 do not long line cut at save                         //~v0aeI~
//v0ad:970712 assign same lineno to split line                     //~v0adI~
//v0ab:970712:write by binaly mode                                 //~v0abI~
//v0aa:970707:default write mode set from read mode                //~v0aaI~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//v09Z:970702:(BUG)drop boundary 1 byte when over max-len*>2       //~v09ZI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            bynaly read using ufgets                             //~v09YI~
//            optionchk need before open for binaly mode open      //~v09YI~
//            open by "rb"                                         //~v09YI~
//v09X:970629:.ini tab display char parm                           //~v09XI~
//v09U:970628:display unprintable char by 0x0e(J) or 0x16(E)       //~v09FI~
//v09F:970614:CID postfix support                                  //~v09FI~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//            isrt pdh if no entry at open by select               //~v09wI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//            -filegetcid parm 0:always chk first line,2 chk if sline==0//~v09rI~
//v09g:970517:shift linenosz by line number of file.               //~v09gI~
//v09a:970503:space imbedding filename support(last space is not supported)//~v09aI~
//            -cmd Edit/Brows:enclosed file name                   //~v09aI~
//v095:970405:DPMI version                                         //~v095I~
//            -errno need errno.h(c6 has it in stdlib.h)           //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v08q:961123:edit partial file(continued from v08l)               //~v08lI~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v08c:961104:(BUG)capreset must be executed before plh free       //~v08cI~
//                 must be call not from deqcw but from end/cancel //~v08cI~
//v085:961024:W95 VC                                               //~v085I~
//v081:960906:(BUG)free err when storage shortage at dirload       //~v081I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v074:960602:num reset cmd(renumber line number)                  //~v074I~
//v06z:960407:stdout work last used seqno save to xe!SAVE!            //~v06zI~
//            xe.h ini3.c dcmd2.c file.c dcmd2.h                      //~v06zI~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06yI~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v06s:960330:(BUG)eof is dropped when edit after load by browse      //~v06sI~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v05v:951203:(BUG)find all offset table shared,it must be for each pfh//~v05vI~
//v04k:951007:(BUG)v03o close after load when browse.edit for same file//~v04kI~
//            can not reopen to save because hfile is null(errno=12//~v04kI~
//            ENULLFCB).drop v03o.leave ini cmd err when browsing.//~v04kI~
//            xefile.c                                          //~v04kI~
//v04j:951007:update id for edit saved file on dir list         //~v04jR~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03y:950903:pfh path name length for dir entry matching       //~v03yI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v03o:950820:xe.ini open err rc=9 when ini cmd under xe.ini browsing//~v03oI~
//*v03l:950817:bug,dont strupr for DBCS filename,it cause (デ-->ェ)//~v03lI~
//*v037:950723:pcw enq to target option to display FIFO seq for dir//~v037I~
//*v030:950709:dir proc avail flag on by 2nd line version id    //~v030I~
//*v020:950628:release(protect dir display)                     //~v020I~
//*           :csr home when steal                              //~v020I~
//*v020:950624:dir support(move End/Cancel from xefcmd.c)       //~v020M~
//*v020:950611:dir support(find err if dir)                     //~v020I~
//************************************************************* //~v020I~
//*v014:950624:bug:when save not displayed line after copy file //~v020I~
//*v012:950611:fixed CID                                        //~5611I~
//************************************************************* //~5611I~
//*950527 endof line lineno 2 up bug                            //~5527I~
//*950424 always save cap data                                  //~5424I~
//*950118 popup previous edit/browse scr                        //~5118R~
//*950102 tab display by space for screen print                 //~5118I~
//*941214 first open at write when new file                     //~5102I~
//*941204 cancel cmd
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v49gI~
#else                                                              //~v49gI~
#ifdef DOS
    #ifdef DPMI					//DPMI version                     //~v095I~
        #include <errno.h>                                         //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
#endif //UNX                                                       //~v49gI~
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318I~
#include <ufile2.h>                                                //~v08qI~
#include <ufile4.h>  //ufgetpos                                    //~v08qI~
#include <ufile5.h>  //ufgets                                      //~v09YI~
#include <ufemsg.h>  //ufgetpos                                    //~v09aI~
#include <uparse.h>                                                //~v0b2R~
#include <uedit.h>                                                 //~v0clI~
#include <ustring.h>                                               //~v53UI~
#include <utf22.h>                                                 //~vb54I~
#include <utrace.h>                                                //~vb2eI~
#ifdef FTPSUPP                                                     //~v540I~
	#include <uftp.h>                                              //~v540R~
#endif                                                             //~v540I~
	#include <utf.h>                                               //~vb2jI~
#ifdef W32                                                         //~vb2nI~
	#include <ufilew.h>                                            //~vb2nI~
#endif                                                             //~vb2nI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                             //~v020I~
#include "xefile.h"
#include "xefile14.h"                                              //~v54dI~
#include "xefile2.h"
#include "xefile3.h"                                                  //~v06yI~
#include "xefile4.h"                                            //~4C23R~
#include "xefile5.h"                                               //~v08qI~
#include "xefile6.h"                                               //~v60jI~
#include "xefile7.h"                                               //~v0imI~
#include "xefile12.h"                                              //~v0baR~
#include "xefile13.h"                                              //~v0d5I~
#include "xefcmd6.h"                                               //~v8@2I~
#include "xefunc.h"                                             //~5118I~
#include "xefunc2.h"                                               //~v77LI~
#include "xeundo.h"
#include "xepan.h"                                              //~5318I~
#include "xepan22.h"                                               //~v78jI~
#include "xefsub.h"                                             //~5318I~
#include "xesub.h"                                              //~5318I~
#include "xedir.h"                                              //~v020I~
#include "xedir2.h"                                             //~v030I~
#include "xecsr.h"                                              //~v020I~
#include "xedcmd.h"                                                //~v13dI~
#include "xedcmd2.h"                                            //~v06nI~
#include "xedlcmd.h"                                               //~v09wR~
#include "xedlcmd2.h"                                              //~v143I~
#include "xedlcmd5.h"   //dlcmdeditenq3                            //~v0fqI~
#include "xecap.h"                                                 //~v08cI~
#include "xeerr.h"                                                 //~v08lI~
#include "xeini3.h"                                                //~v11zI~
#include "xefcmd2.h"                                               //~v43hI~
#ifdef FTPSUPP                                                     //~v53UI~
	#include "xeftp.h"                                             //~v53UI~
#endif                                                             //~v53UI~
#include "xesyn.h"                                                 //~v78cI~
#include "xegbl.h"                                                 //~v79zI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeopt.h"                                             //~va00I~
	#include "xeutf.h"                                             //~va00I~
#endif                                                             //~va00I~
#include "xefsubw.h"                                               //~vavaI~
//*******************************************************
//#define MAXLINEDATA2 (MAXLINEDATA-99)	//split line cut size      //~v0e2R~
//#define MAXLINEDATA2 MAXLINEDATA	//same as max not used         //~vazeR~
//*******************************************************          //~v0bdI~
static 	UQUEH  	Sfileq;		//q of UFILEH
static 	UFILEH  Scmdparmufh;	//cmd parm result for reopen chk   //~v60sI~
//**********************************
//int filegetadirmember(PUFILEH Ppfh,char *Pfullpath);             //~v40uR~
int fileerrmixmode(char *Pfnm);                                    //~v440R~
int filemixmodechk(int Pbesw,PUFILEH Ppfh);                        //~v440I~
//**********************************
//static int Ssplitsw=0;          //fileget line overflow          //~v54dR~
//static int Ssplitswb;           //for OPTBIN case,1st line overflowed sw//~v54dR~
static int Scmdopt=0;			//by /mx option to chk bin and text open//~v440I~
//static char Ssplit1stsw=0;      //first time split sw for msg    //~v54dR~
//static char Seolid=0;           //to chk pc/unix flat file       //~v54dR~
static char Sdireditsw;			//for fileload,from edit or browse//~v06nR~
static char Seditsosw;			//parm to fileregist                  //~v06yI~
static char Sfkinisw;			//parm to fileload(func key file)  //~v0imI~
//static char Sbinsw;         	//force binary mode                //~v75HR~
static int Sbinsw;           	//edit subcmd option               //~v75HI~
//static UINT Slinewidth;         //file display width             //~v54dR~
//static ULONG Slineoffs;         //line offset for binary file    //~v54dR~
//static ULONG Sgetchkoffs;       //parm to filegetline            //~v54dR~
//static char Samembfullpath[_MAX_PATH];                           //~v40uR~
static int Sfebfiopt=0;  	//internal edit/brwse call option      //~v76mI~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
	static int SchkmountCP=0;  	//from filesrchpfhCP               //~vb2eR~
#ifdef LNX                                                         //~vb2nI~
	static int SmountCPU8;  	//to filesrchpfhCP                 //~vb2eR~
	static int SmountCPU8cv;  	//to filesrchpfhCP                 //~vb2eI~
#endif                                                             //~vb2nI~
	static int Ssrchcpopt;      	//from filesrchpfhCP           //~vb2eI~
//#endif                                                             //~vb2eR~//~vb2nR~
//****************************************************************
// fileinit
//*initialize about file
//*parm:none
//*rc   :none
//****************************************************************
void fileinit(void)
{
	Gunpdispchar3_after_inigetopt=Gunpdispchar[3];  //to restore by tab on 000//~vb5bI~
//  if (UCBITCHK(Gscrstatus,GSCRSDBCS))	//dbcs                     //~v79zR~
    if (XE_ISDBCSJ())	//Japanese(SJIS,EUC,UTF8J)                 //~v79zR~
	{
//  	Gfiletabdisp1=0x1c;       	//upper allow                  //~v09XR~
//  	Gfiletabdisp2=0x1e;			//right allow                  //~v09XR~
    	Gfiletabdisp1=Gtabdispchar[2];//jpn1                       //~v09XI~
    	Gfiletabdisp2=Gtabdispchar[3];//jpn2                       //~v09XI~
	    Gunpdispchar[0]=Gunpdispchar[2];//english mode             //~v09FI~
	}
	else
	{
//  	Gfiletabdisp1=0x18;       	//upper allow                  //~v09XR~
//  	Gfiletabdisp2=0x1a;			//right allow                  //~v09XR~
    	Gfiletabdisp1=Gtabdispchar[0];//eng1                       //~v09XI~
    	Gfiletabdisp2=Gtabdispchar[1];//eng2                       //~v09XI~
	    Gunpdispchar[0]=Gunpdispchar[1];//english mode             //~v09FI~
	}
    if (Gopttabaltch[0])                                           //~vb54R~
    {                                                              //~vb54R~
    	if (Gopttabaltch[0]>=0x100)                                //~vb54I~
        {                                                          //~vb54I~
			Gfiletabdisp1=DEFAULT_ALTCH;//0xff                     //~vb54I~
			utfsetvisiblealtch(UTFGVACO_TAB,Gopttabaltch[0]);      //~vb54I~
        }                                                          //~vb54I~
        else                                                       //~vb54I~
    		Gfiletabdisp1=(UCHAR)Gopttabaltch[0];                  //~vb54R~
	    if (Gopttabaltch[1])                                       //~vb54R~
        {                                                          //~vb54I~
	    	if (Gopttabaltch[1]>=0x100)                            //~vb54I~
        	{                                                      //~vb54I~
				Gfiletabdisp2=DEFAULT_ALTCH;//0xff                 //~vb54I~
				utfsetvisiblealtch(UTFGVACO_TABPAD,Gopttabaltch[1]);//~vb54I~
            }                                                      //~vb54I~
        	else                                                   //~vb54I~
	    		Gfiletabdisp2=(UCHAR)Gopttabaltch[1];              //~vb54R~
        }                                                          //~vb54I~
    }                                                              //~vb54R~
    if (Gopttabaltch[2])     //dbcs space                          //~vb5bI~
    {                                                              //~vb5bI~
        if (Gopttabaltch[2]>=0x100)                                //~vb5bI~
        {                                                          //~vb5bI~
            Gunpdispchar[3]=DEFAULT_ALTCH;//0xff                   //~vb5bI~
            utfsetvisiblealtch(UTFGVACO_DBCSSPACE,Gopttabaltch[2]);//~vb5bI~
        }                                                          //~vb5bI~
        else                                                       //~vb5bI~
            Gunpdispchar[3]=(UCHAR)Gopttabaltch[2];                //~vb5bI~
    }                                                              //~vb5bI~
//  Gfilebuff=UALLOCM(MAXLINEDATA*8);                              //~v0bbR~
//  Gfilebuff2=Gfilebuff+MAXLINEDATA*4;                            //~v0bbR~
    Gfilebuff=UALLOCM(GFILEBUFFSZ*2);                              //~v0bbI~
    Gfilebuff2=Gfilebuff+GFILEBUFFSZ;                              //~v0bbI~
                                                                   //~v202I~
#ifdef UNX                                                         //~v202I~
#else  //!UNX                                                      //~v202I~
#ifdef OS2                                                         //~v0f9I~
#else                                                              //~v0f9I~
	if (ufileisvfat(0))//no msg,not vfat support	               //~v0f9I~
        UCBITON(Gopt4,GOPT4W95VFAT);   //vfat support              //~v0f9R~
#endif                                                             //~v0f9I~
#endif //!UNX                                                      //~v202I~
//  Gfilemfwtbl=UALLOCM((MAXMFWTENTRY*2+2)*sizeof(USHORT));        //~v61sR~
//  Gfilemfwtbl=UALLOCM((MFWTBLSZ+MFWTENTSZ+MFWTENTSZ)*sizeof(USHORT)); //3 ushort and +1 allowance//~v62bR~
}//fileinit
//****************************************************************
// fileterm
//*free buff for file
//*parm:none
//*rc   :none
//****************************************************************
void fileterm(void)
{
    PUFILEH pfh;                                                   //~v70cI~
//*************************                                        //~v70cI~
	if (Gcapcbpcw)                                              //~5224I~
    {                                                           //~5224I~
    	screnqcw(0,Gcapcbpcw,UQUE_TOP,0);//re-enq to top        //~v037R~
//  	if (UCBITCHK(Gprocstatus,GPROCSCANTERM))//last op is CANCEL//~5424R~
//      {                                                       //~5424R~
//setup to avoid confirm chk                                    //~5228I~
//  		((PUCLIENTWE)Gcapcbpcw)->UCWpfunct=functblsrch(FUNCID_QUIT);//avoid confirm//~5424R~
//      	func_cancel_file(Gcapcbpcw);                        //~5424R~
//  	}                                                       //~5424R~
//      else                                                    //~5424R~
		pfh=UGETPFHFROMPCW(((PUCLIENTWE)(Gcapcbpcw)));  		   //~v70cR~
        UCBITON(pfh->UFHflag8,UFHF8NOUPDCHK);                      //~v70cI~
	    	func_end_file(Gcapcbpcw);                           //~5228R~
        Gcapcbpcw=0;                                            //~5224I~
    }                                                           //~5224I~
    panfnlfreepfh();	//before free Gfilebuff                    //~v78jI~
	if (Gfilebuff)
		ufree(Gfilebuff);
//  if (Gfilemfwtbl)                                               //~v62bR~
//  	ufree(Gfilemfwtbl);                                        //~v62bR~
    filecidterm();		//free cid extention tbl                //~5528I~
//    ufgetsinit(UFGETS_TERM,0);	//free iobuff                  //~v107R~
//    ufgetsinit(UFGETS_TERM,0,0);	//free iobuff                  //~v10NR~
    ufgetsinit(UFGETS_TERM,0,0,0);	//free iobuff                  //~v10NI~
}//fileterm
                                                                //~v06nI~
//****************************************************************//~v06nI~
//* stdout(tmp file) edit                                       //~v06nI~
//* parm1 :pcw                                                  //~v06nI~
//* retrn:rc                                                    //~v06nI~
//****************************************************************//~v06nI~
int fileeditso(PUCLIENTWE Ppcw)                                       //~v06tR~
{                                                               //~v06nI~
	char sofname[MAXFILENAME+1];                                //~v06nI~
    int rc;                                                     //~v06nI~
//*****************                                             //~v06nI~
//  if (Psofname)                                                     //~v06tR~
//  	Ppcw->UCWparm=Psofname;                                       //~v06tR~
//  else                                                              //~v06tR~
//  {                                                                 //~v06tR~
	    if (dcmdgetsofname(sofname,0))//no need fullpath              //~v06zR~
    		return 4;                                                 //~v06nR~
		Ppcw->UCWparm=sofname;                                        //~v06nR~
//  }                                                                 //~v06tR~
    Seditsosw=1;	//parm to fileregist                              //~v06yR~
#ifdef UTF8SUPPH                                                   //~va00I~
    rc=func_edit_file2(Ppcw,FEBFIO_UTF8IE); //internal edit call;ignor utf8 trans err//~va00I~
#else                                                              //~va00I~
    rc=func_edit_file2(Ppcw,0);	//file name only                   //~v08lR~
#endif                                                             //~va00I~
    Seditsosw=0;	//parm to fileregist                              //~v06yI~
    return rc;                                                  //~v06nR~
}//fileeditso                                                   //~v06nI~
                                                                //~v06nI~
//**************************************************************** //~v0imI~
// func_edit_file3                                                 //~v0imI~
//*for option menu key assign change                               //~v0imI~
//*parm1:uclient work element                                      //~v0imI~
//*parm2:option 2:key cmd(0.2) 3:func key(0.3)                     //~v0imR~
//*rc   :of func_edit_file                                         //~v0imI~
//**************************************************************** //~v0imI~
int func_edit_file3(PUCLIENTWE Ppcw,int Popt)                      //~v0imI~
{                                                                  //~v0imI~
	int rc;                                                        //~v0imI~
//*********************************                                //~v0imI~
    Sfkinisw=1;				//parm to fileload                     //~v0imI~
    if (Popt==FILEFK_OPTKLIST)                                     //~v0jaR~
		rc=func_browse_file2(Ppcw,0);	//parm is file name only   //~v0imI~
    else                                                           //~v0imI~
		rc=func_edit_file2(Ppcw,0);	//parm is file name only       //~v0imR~
    Sfkinisw=0;				//parm to fileload                     //~v0imI~
    return rc;                                                     //~v0imI~
}//func_edit_file3                                                 //~v0imI~
                                                                   //~v0imI~
//**************************************************************** //~v10GI~
// func_editbin_file                                               //~v10GI~
//*same as EDIt /Mb                                                //~v10GI~
//*parm1:uclient work element                                      //~v10GI~
//*rc   :of func_edit_file                                         //~v10GI~
//**************************************************************** //~v10GI~
int func_editbin_file(PUCLIENTWE Ppcw)                             //~v10GI~
{                                                                  //~v10GI~
	int rc;                                                        //~v10GI~
//*********************************                                //~v10GI~
    Sbinsw=1;				//parm to fileload,force /mb           //~v10GI~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v10GI~
    Sbinsw=0;				//parm to fileload                     //~v10GI~
    return rc;                                                     //~v10GI~
}//func_editbin_file                                               //~v10GI~
//**************************************************************** //~v50GI~
// func_edittext_file                                              //~v50GI~
//*same as EDIt /Mt                                                //~v50GI~
//*parm1:uclient work element                                      //~v50GI~
//*rc   :of func_edit_file                                         //~v50GI~
//**************************************************************** //~v50GI~
int func_edittext_file(PUCLIENTWE Ppcw)                            //~v50GI~
{                                                                  //~v50GI~
	int rc;                                                        //~v50GI~
//*********************************                                //~v50GI~
    Sbinsw=BESOPT_TEXT;  		//parm to fileload,force /mn       //~v50GI~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v50GI~
    Sbinsw=0;				//parm to fileload                     //~v50GI~
    return rc;                                                     //~v50GI~
}//func_edittext_file                                              //~v50GI~
//**************************************************************** //~v10LI~
// func_editspf_file                                               //~v10LI~
//*same as EDIt /Mn                                                //~v10LI~
//*parm1:uclient work element                                      //~v10LI~
//*rc   :of func_edit_file                                         //~v10LI~
//**************************************************************** //~v10LI~
int func_editspf_file(PUCLIENTWE Ppcw)                             //~v10LI~
{                                                                  //~v10LI~
	int rc;                                                        //~v10LI~
//*********************************                                //~v10LI~
    Sbinsw=BESOPT_SPF;  		//parm to fileload,force /mn       //~v10LR~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v10LI~
    Sbinsw=0;				//parm to fileload                     //~v10LI~
    return rc;                                                     //~v10LI~
}//func_editspf_file                                               //~v10LI~
//**************************************************************** //~v414I~
// func_editspfcob_file                                            //~v414I~
//*same as EDIt /Mc                                                //~v414I~
//*parm1:uclient work element                                      //~v414I~
//*rc   :of func_edit_file                                         //~v414I~
//**************************************************************** //~v414I~
int func_editspfcob_file(PUCLIENTWE Ppcw)                          //~v414I~
{                                                                  //~v414I~
	int rc;                                                        //~v414I~
//*********************************                                //~v414I~
    Sbinsw=BESOPT_SPFCOB;  		//parm to fileload,force /mn       //~v414I~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v414I~
    Sbinsw=0;				//parm to fileload                     //~v414I~
    return rc;                                                     //~v414I~
}//func_editspfcob_file                                            //~v414I~
//**************************************************************** //~v414I~
// func_editspfcobnum_file                                         //~v414I~
//*same as EDIt /Mnc                                               //~v414I~
//*parm1:uclient work element                                      //~v414I~
//*rc   :of func_edit_file                                         //~v414I~
//**************************************************************** //~v414I~
int func_editspfcobnum_file(PUCLIENTWE Ppcw)                       //~v414I~
{                                                                  //~v414I~
	int rc;                                                        //~v414I~
//*********************************                                //~v414I~
    Sbinsw=BESOPT_SPFCOBNUM;  		//parm to fileload,force /mn   //~v414I~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v414I~
    Sbinsw=0;				//parm to fileload                     //~v414I~
    return rc;                                                     //~v414I~
}//func_editspfcobnum_file                                         //~v414I~
//**************************************************************** //~v42yI~
// func_editspfcob2_file                                           //~v42yI~
//*same as EDIt /Mk                                                //~v42yI~
//*parm1:uclient work element                                      //~v42yI~
//*rc   :of func_edit_file                                         //~v42yI~
//**************************************************************** //~v42yI~
int func_editspfcob2_file(PUCLIENTWE Ppcw)                         //~v42yI~
{                                                                  //~v42yI~
	int rc;                                                        //~v42yI~
//*********************************                                //~v42yI~
    Sbinsw=BESOPT_SPFCOB2;  		//parm to fileload,force /mn   //~v42yI~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v42yI~
    Sbinsw=0;				//parm to fileload                     //~v42yI~
    return rc;                                                     //~v42yI~
}//func_editspfcob2_file                                           //~v42yI~
//**************************************************************** //~v42yI~
// func_editspfcob2num_file                                        //~v42yI~
//*same as EDIt /Mkn                                               //~v42yI~
//*parm1:uclient work element                                      //~v42yI~
//*rc   :of func_edit_file                                         //~v42yI~
//**************************************************************** //~v42yI~
int func_editspfcob2num_file(PUCLIENTWE Ppcw)                      //~v42yI~
{                                                                  //~v42yI~
	int rc;                                                        //~v42yI~
//*********************************                                //~v42yI~
    Sbinsw=BESOPT_SPFCOB2NUM;  		//parm to fileload,force /mkn  //~v42yI~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v42yI~
    Sbinsw=0;				//parm to fileload                     //~v42yI~
    return rc;                                                     //~v42yI~
}//func_editspfcob2num_file                                        //~v42yI~
//**************************************************************** //~v75HI~
// func_editf80_file                                               //~v75HI~
//*same as EDIt f80                                                //~v75HI~
//**************************************************************** //~v75HI~
int func_editf80_file(PUCLIENTWE Ppcw)                             //~v75HI~
{                                                                  //~v75HI~
	int rc;                                                        //~v75HI~
//*********************************                                //~v75HI~
    Sbinsw=BESOPT_F80;  		//parm to fileload,force /mkn      //~v75HI~
	rc=func_edit_file(Ppcw);	//parm is file name only           //~v75HI~
    Sbinsw=0;				//parm to fileload                     //~v75HI~
    return rc;                                                     //~v75HI~
}//func_editf80_file                                               //~v75HI~
//**************************************************************** //~v440I~
// func_edithex_file                                               //~v440I~
//*same as EDIt /Mx                                                //~v440I~
//*parm1:uclient work element                                      //~v440I~
//*rc   :of func_edit_file                                         //~v440I~
//**************************************************************** //~v440I~
int func_edithex_file(PUCLIENTWE Ppcw)                             //~v440I~
{                                                                  //~v440I~
	int rc;                                                        //~v440I~
//*********************************                                //~v440I~
    Sbinsw=BESOPT_HEX;  		//parm to fileload,force /mn       //~v440I~
	rc=func_edit_file(Ppcw);                                       //~v440I~
    Sbinsw=0;				//parm to fileload                     //~v440I~
    return rc;                                                     //~v440I~
}//func_edithex_file                                               //~v440I~
//**************************************************************** //~v08lI~
// func_edit_file2                                                 //~v08lI~
//*internal call interface,setup parseout tbl                      //~v08lI~
//*parm1:uclient work element                                      //~v08lI~
//*parm2:1:optional operand may exist,0:no optional opd            //~v08lI~
//*rc   :of func_edit_file                                         //~v08lI~
//**************************************************************** //~v08lI~
int func_edit_file2(PUCLIENTWE Ppcw,int Poptopd)                   //~v08lI~
{                                                                  //~v08lI~
//  UCHAR wkpot[MAXCOLUMN+1];                                      //~v08lI~//~va03R~
    UCHAR wkpot[MAXPARMSZ+1];                                      //~va03R~
    PUPODELMTBL pupod;                                             //~v08lI~
	int rc;                                                        //~v08lI~
//*********************************                                //~v08lI~
    filefnquate(Ppcw->UCWparm);     //quatation change             //~v0fsR~
//  if (Poptopd)                                                   //~v76mR~
    if (Poptopd & FEBFIO_OPD)   //exist parm other than filename   //~v76mI~
    {                                                              //~v08lI~
	    pupod=Ppcw->UCWopddelmt=Gpodelmt;                          //~v08lR~
		Ppcw->UCWopdpot=wkpot;                                     //~v08lI~
	    if ((rc=uparse2(Ppcw->UCWparm,&pupod,                      //~v08lR~
				&Ppcw->UCWopdpot,&Ppcw->UCWopdno,UPARSE2USEAREAPARM,","))>=4)//~v08lR~
	    	return rc;			//umalloc failed                   //~v08lI~
    }                                                              //~v08lI~
    else                                                           //~v09aI~
    {                                                              //~v09aI~
		Ppcw->UCWopdpot=Ppcw->UCWparm;  //same as before parse out //~v09aI~
		Ppcw->UCWopdno=1;                                          //~v09aI~
    }                                                              //~v09aI~
	Sfebfiopt=Poptopd & FLO2_OPT2;  	//internal edit/brwse call option//~v76mR~
//  return func_edit_file(Ppcw);                                   //~v76mR~
    rc=func_edit_file(Ppcw);                                       //~v76mI~
	Sfebfiopt=0;        	//internal edit/brwse call option      //~v76mI~
    return rc;                                                     //~v76mI~
}//func_edit_file2                                                 //~v08lI~
                                                                   //~v08lI~
//****************************************************************
// func_edit_file 
//*search file on fileq(load and enq if not exist)
//*parm1:uclient work element
//*rc   :0-ok 4:file load err
//****************************************************************
int func_edit_file(PUCLIENTWE Ppcw)                             //~5118R~
{
	int rc;
//	int rc2;                                                       //~v40uR~
  	int rc2;                                                       //~v716I~
    int opt2;                                                      //~v76mI~
	UFILEH *pfh;
    PUCLIENTWE pcw;                                             //~5118R~
	UCHAR  *fname;                                              //~5130R~
	UCHAR  fpath[_MAX_PATH];                                       //~v60sR~
#ifdef UTF8SUPPH                                                   //~va00I~
	PFUNCTBL pft;                                                  //~va00I~
#endif                                                             //~va00I~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
	int cprc=0,optcp;                                              //~vb2eI~
//#endif                                                             //~vb2eI~//~vb2nR~
//*********************************
//  if (!(fname=Ppcw->UCWparm))//no parm                           //~v09aR~
    if (!(fname=Ppcw->UCWopdpot))//pparseout 1st parm              //~v09aR~
    {                                                           //~5123I~
//  	uerrmsg("Specify filename",                                //~v09rR~
//  			"ファイル名を指定して下さい");                     //~v09rR~
//      errmissing();                                              //~v11iR~
        fileedithelp('E');   //edit id                             //~v11iR~
    	return 8;                                               //~5123I~
    }                                                           //~5123I~
//  *Samembfullpath=0;		//id of second call                    //~v40uR~
//for (;;)                                                         //~v40uR~
//{                                                                //~v40uR~
//  if (rc=filesrchpfh2(Ppcw,fname,fullpath,&pfh),rc>4)//before filedirchk//~v60sR~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
	optcp=FSPFHCPO_PFH2;                                           //~vb2eI~
    if (rc=filesrchpfhCP(optcp,Ppcw,fname,fpath,&pfh,0,&cprc),rc>4)//before filedirchk,0:edit//~vb2eI~
    	return 16;                                                 //~vb2eI~
//#else                                                              //~vb2eI~//~vb2nR~
//    if (rc=filesrchpfh2(Ppcw,fname,fpath,&pfh,0),rc>4)//before filedirchk,0:edit//~v60sR~//~vb2nR~
//        return 16;                                                 //~v13dI~//~vb2nR~
//#endif                                                             //~vb2eI~//~vb2nR~
//for dir use browse logic for 2 split display                  //~v020I~
//  if (filedirchk(fname)>0)	//dir or dir+wildcard              //~v13dR~
//  if (filedirchk(fpath)>0)	//dir or dir+wildcard              //~v716R~
    if ((rc2=filedirchk(fpath))>0)	//dir or dir+wildcard          //~v716I~
	{                                                           //~v020I~
    	Sdireditsw=1;		//edit mode	                        //~v020R~
		rc=func_browse_file(Ppcw);	//2 split                   //~v020R~
//      rc2=Sdireditsw;                                            //~v40uR~
    	Sdireditsw=0;	                                        //~v020I~
//  	if (rc2==2)	//contain only a member                        //~v40uR~
//      {                                                          //~v40uR~
//      	fname=Samembfullpath;                                  //~v40uR~
//      	continue;                                              //~v40uR~
//  	}                                                          //~v40uR~
		return rc;                                              //~v020I~
    }                                                           //~v020I~
    if (rc2==-2)//remote err                                       //~v78TI~
        return rc2;                                                //~v78TI~
//  break;                                                         //~v40uR~
//}//chk wildcard and only one member                              //~v40uR~
//  if (Ppcw->UCWopdno>1)                                          //~v08lR~
//  	return errtoomany();                                       //~v08lR~
//  if (rc=filesrchpfh(fname,fullpath,&pfh),rc>4)                  //~v13dR~
//  	return 16;                                                 //~v13dI~
	if (!rc)//found                                             //~5125R~
	{
    	if (filemixmodechk(0,pfh))                                 //~v60sI~
        	return 4;                                              //~v60sI~
        if ((pcw=pfh->UFHeditpcw)==Ppcw)                        //~5118R~
    	{                                                       //~5118I~
    		uerrmsg("%s is now Editting",                       //~5118I~
    				"%s は現編集中です",fpath);                    //~v60sR~
    		return 8;                                           //~5118I~
    	}                                                       //~5118I~
//  	if (filemixmodechk(0,pfh))                                 //~v60sR~
//      	return 4;                                              //~v60sR~
		if (pcw)	//editting on any split                     //~5118R~
		{                                                       //~5118I~
            if (pcw->UCWmenuopt==PANMOCMD)                            //~v06yI~
	    	{                                                         //~v06yI~
    			uerrmsg("%s is now used",                             //~v06yI~
    					"%s は使用中です",pfh->UFHalias);             //~v06yI~
	    		return 8;                                             //~v06yI~
    		}                                                         //~v06yI~
        	if (pcw==Gcapcbpcw)	//req clip board already opened //~5224I~
            {                                                      //~v675I~
            	screnqcw(Ppcw->UCWsplitid,pcw,UQUE_TOP,0);//re-enq to top//~v037R~
        		Gcapcbpcw=0;	//clear floating pcw ptr to avoid double enq//~v675I~
            }                                                      //~v675I~
            else                                                //~5224I~
    			uerrmsg("Re-display of EDIT %s",                //~5224R~
//  					"%s の編集 再表示",fullpath);              //~v095R~
    					"%s の編集 再\x95\\示",fpath);             //~v60sR~
         	scrpopup(pcw,0);	//no deq save ptr               //~5228R~
            csrhomepos(0);//home of current scr                 //~v020I~
            return 0;                                           //~5118I~
	    } 	                                                    //~5118I~
        else        //browse open exist                            //~v40yI~
        {                                                          //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
          if (UCBITCHK(pfh->UFHflag10,UFHF10UTF8LOADERR))	//err utf8 code is replaced to "?" at open//~va00I~
          {                                                        //~va00I~
      		if (UCBITCHK(Scmdparmufh.UFHflag10,UFHF10UTF8IE))	//ignore err parm specified//~va00R~
//          	uerrmsgcat("Already opened by browse mode WITH UTF8 TRANSLATION ERR. Those are replaced by '%c' if saved",//~va1ER~
//                         "別途 \x95\\示(UTF8変換エラーあり)でオープン済み。保存すると '%c' に置換されます。",//~va1ER~
//                              XEUTF_ERRREPCH_F2LFILE);           //~va1EI~
            	uerrmsgcat("Already opened by browse mode WITH UTF8 TRANSLATION ERR.",//~va1EI~
                           "別途 \x95\\示(UTF8変換エラーあり)でオープン済み。");//~va1EI~
		    else                                                   //~va00I~
            {                                                      //~va00I~
                                                                   //~va00I~
				if (UCBITCHK(Ppcw->UCWflag2,UCWF2SELECTCMD)	//parm to fileoptionchk//~va00I~
                &&  (pft=Ppcw->UCWpfunct,pft!=0)                   //~va00R~
				&&  (pft->FTfuncid!=FUNCID_SELECT)                 //~va00I~
                )                                                  //~va00I~
	            	uerrmsgcat("Already opened by browse mode WITH UTF8 TRANSLATION ERR. use %s option by Open line cmd",//~va00I~
    	            	       "別途 \x95\\示(UTF8変換エラーあり)でオープン済み。開くには Open 行コマンドで %s オプションを指定する。",//~va00I~
                        	    MODE_IE);                          //~va00I~
                else                                               //~va00I~
	            	uerrmsgcat("Already opened by browse mode WITH UTF8 TRANSLATION ERR. use %s option to Edit open",//~va00R~
    	            	       "別途 \x95\\示(UTF8変換エラーあり)でオープン済み。開くには %s オプションを指定する。",//~va00R~
                        	    MODE_IE);                          //~va00R~
                return 4;                                          //~va00I~
            }                                                      //~va00I~
          }                                                        //~va00I~
          else                                                     //~va00I~
#endif                                                             //~va00I~
    		uerrmsg("Browse mode already opened.",                 //~v40yI~
    				"別途 \x95\\示窓あり");                        //~v40yR~
        }                                                          //~va00I~
		pfh->UFHopenctr++;                                      //~5118I~
	}//already opened
    else                                                        //~5118R~
    {                                                           //~5118I~
//  	if (rc2==-2)//remote err                                   //~v78TR~
//      	return rc2;                                            //~v78TR~
//  	if (rc=fileload(Ppcw,fname,fullpath,0,&pfh),rc)            //~v54dR~
//  	if (rc=fileload(Ppcw,fname,fpath,0,&pfh,Sbinsw,Seditsosw,Sfkinisw),rc)//~v76mR~
		opt2=Sfkinisw|Sfebfiopt;  	//internal edit/brwse call option//~v76mI~
#ifdef LNX                                                         //~vb2eI~
        if (cprc & FSPFHCPRC_MOUNTU8)           		//device iocharset is utf8//~vb2eI~
			opt2|=FEBFIO_MOUNTU8;  	//internal edit/brwse call option//~vb2eR~
        if (cprc & FSPFHCPRC_MOUNTU8CV)                            //~vb2eI~
			opt2|=FEBFIO_MOUNTU8CV;  	//internal edit/brwse call option//~vb2eI~
#endif                                                             //~vb2eI~
    	if (rc=fileload(Ppcw,fname,fpath,0,&pfh,Sbinsw,Seditsosw,opt2),rc)//~v76mR~
        {                                                          //~va1eI~
#ifdef UTF8SUPPH                                                   //~va1eI~
          if (rc==FLRC_RETRYCPU8ERR)                               //~va1eR~
          {                                                        //~va1eI~
            ugeterrmsg();//clear prev err msg                      //~va1eR~
	    	if (rc=fileload(Ppcw,fname,fpath,0,&pfh,Sbinsw,Seditsosw,opt2|(FEBFIO_CPLC|FEBFIO_RETRY)),rc)//~va1eR~
            	return rc;                                         //~va1eI~
            else                                                   //~va1eI~
            	uerrmsgcat("Contains Invalid UTF8 code, Reloaded by CPLC. Specify \"CPLC\" to fast load or \"CPU8 IE\" to force loading by CPU8",//~va1eR~
            	           "UTF8 code 変換エラー, CPLC で再ロード。リトライ時間を省くには \"CPLC\", CPU8 を強制するには \"CPU8 IE\" を指定する。");//~va1eI~
          }                                                        //~va1eI~
          else                                                     //~va1eI~
#endif                                                             //~va1eI~
			return rc;                                          //~5118R~
        }                                                          //~va1eI~
//      fileeofchk(pfh);	//chk eof ^z exist,moved to fileload      //~v06sR~
		UENQ(UQUE_TOP,&Sfileq,pfh);                             //~5118R~
    }                                                           //~5118I~
	pcw=fileregist(Ppcw,PANFEDIT,pfh,Seditsosw);                   //~v0d5R~
    if (!pcw)       //storage shortage                          //~v04dI~
    {                                                           //~v04dI~
    	fileclosefree2(pfh);	//close and free pfh            //~v04dR~
        return UALLOC_FAILED;                                   //~v04dI~
    }                                                           //~v04dI~
	pfh->UFHeditpcw=pcw;                                        //~5118R~
//#ifdef FTPSUPP                                                   //~v555R~
//    if (pfh->UFHtype==UFHTHOSTS)//ftp hosts                      //~v555R~
//        xeftphostsget(pcw,pfh); //setup hosts table              //~v555R~
//#endif                                                           //~v555R~
	return 0;
}//func_edit_file
//**************************************************************** //~v50GI~
// func_browsetext_file                                            //~v50GI~
//*same as BROwse /Mb                                              //~v50GI~
//*parm1:uclient work element                                      //~v50GI~
//*rc   :of func_browse_file                                       //~v50GI~
//**************************************************************** //~v50GI~
int func_browsetext_file(PUCLIENTWE Ppcw)                          //~v50GI~
{                                                                  //~v50GI~
	int rc;                                                        //~v50GI~
//*********************************                                //~v50GI~
    Sbinsw=BESOPT_TEXT;  		//parm to fileload,force /mn       //~v50GI~
	rc=func_browse_file(Ppcw);                                     //~v50GI~
    Sbinsw=0;				//parm to fileload                     //~v50GI~
    return rc;                                                     //~v50GI~
}//func_browsetext_file                                            //~v50GI~
//**************************************************************** //~v10GI~
// func_browsebin_file                                             //~v10GI~
//*same as BROwse /Mb                                              //~v10GI~
//*parm1:uclient work element                                      //~v10GI~
//*rc   :of func_browse_file                                       //~v10GI~
//**************************************************************** //~v10GI~
int func_browsebin_file(PUCLIENTWE Ppcw)                           //~v10GR~
{                                                                  //~v10GI~
	int rc;                                                        //~v10GI~
//*********************************                                //~v10GI~
    Sbinsw=1;				//parm to fileload,force /mb           //~v10GI~
	rc=func_browse_file(Ppcw);                                     //~v10GI~
    Sbinsw=0;				//parm to fileload                     //~v10GI~
    return rc;                                                     //~v10GI~
}//func_browsebin_file                                             //~v10GI~
//**************************************************************** //~v10LI~
// func_browsespf_file                                             //~v10LI~
//*same as BROwse /Mn                                              //~v10LI~
//*parm1:uclient work element                                      //~v10LI~
//*rc   :of func_browse_file                                       //~v10LI~
//**************************************************************** //~v10LI~
int func_browsespf_file(PUCLIENTWE Ppcw)                           //~v10LI~
{                                                                  //~v10LI~
	int rc;                                                        //~v10LI~
//*********************************                                //~v10LI~
    Sbinsw=BESOPT_SPF;  		//parm to fileload,force /mn       //~v10LR~
	rc=func_browse_file(Ppcw);                                     //~v10LI~
    Sbinsw=0;				//parm to fileload                     //~v10LI~
    return rc;                                                     //~v10LI~
}//func_browsespf_file                                             //~v10LI~
//**************************************************************** //~v414I~
// func_browsespfcob_file                                          //~v414I~
//*same as BROwse /Mc                                              //~v414I~
//*parm1:uclient work element                                      //~v414I~
//*rc   :of func_browse_file                                       //~v414I~
//**************************************************************** //~v414I~
int func_browsespfcob_file(PUCLIENTWE Ppcw)                        //~v414I~
{                                                                  //~v414I~
	int rc;                                                        //~v414I~
//*********************************                                //~v414I~
    Sbinsw=BESOPT_SPFCOB;  		//parm to fileload,force /mn       //~v414I~
	rc=func_browse_file(Ppcw);                                     //~v414I~
    Sbinsw=0;				//parm to fileload                     //~v414I~
    return rc;                                                     //~v414I~
}//func_browsespfcob_file                                          //~v414I~
//**************************************************************** //~v414I~
// func_browsespfcobnum_file                                       //~v414I~
//*same as BROwse /Mnc                                             //~v414I~
//*parm1:uclient work element                                      //~v414I~
//*rc   :of func_browse_file                                       //~v414I~
//**************************************************************** //~v414I~
int func_browsespfcobnum_file(PUCLIENTWE Ppcw)                     //~v414I~
{                                                                  //~v414I~
	int rc;                                                        //~v414I~
//*********************************                                //~v414I~
    Sbinsw=BESOPT_SPFCOBNUM;  		//parm to fileload,force /mn   //~v414I~
	rc=func_browse_file(Ppcw);                                     //~v414I~
    Sbinsw=0;				//parm to fileload                     //~v414I~
    return rc;                                                     //~v414I~
}//func_browsespfcobnum_file                                       //~v414I~
//**************************************************************** //~v42yI~
// func_browsespfcob2_file                                         //~v42yI~
//*same as BROwse /Mc                                              //~v42yI~
//*parm1:uclient work element                                      //~v42yI~
//*rc   :of func_browse_file                                       //~v42yI~
//**************************************************************** //~v42yI~
int func_browsespfcob2_file(PUCLIENTWE Ppcw)                       //~v42yI~
{                                                                  //~v42yI~
	int rc;                                                        //~v42yI~
//*********************************                                //~v42yI~
    Sbinsw=BESOPT_SPFCOB2;  		//parm to fileload,force /mn   //~v42yI~
	rc=func_browse_file(Ppcw);                                     //~v42yI~
    Sbinsw=0;				//parm to fileload                     //~v42yI~
    return rc;                                                     //~v42yI~
}//func_browsespf2cob_file                                         //~v42yI~
//**************************************************************** //~v42yI~
// func_browsespfcob2num_file                                      //~v42yI~
//*same as BROwse /Mkn                                             //~v42yI~
//*parm1:uclient work element                                      //~v42yI~
//*rc   :of func_browse_file                                       //~v42yI~
//**************************************************************** //~v42yI~
int func_browsespfcob2num_file(PUCLIENTWE Ppcw)                    //~v42yI~
{                                                                  //~v42yI~
	int rc;                                                        //~v42yI~
//*********************************                                //~v42yI~
    Sbinsw=BESOPT_SPFCOB2NUM;  		//parm to fileload,force /mn   //~v42yI~
	rc=func_browse_file(Ppcw);                                     //~v42yI~
    Sbinsw=0;				//parm to fileload                     //~v42yI~
    return rc;                                                     //~v42yI~
}//func_browsespfcob2num_file                                      //~v42yI~
//**************************************************************** //~v75HI~
// func_browsef80_file                                             //~v75HI~
//*same as BROwse f80                                              //~v75HI~
//**************************************************************** //~v75HI~
int func_browsef80_file(PUCLIENTWE Ppcw)                           //~v75HI~
{                                                                  //~v75HI~
	int rc;                                                        //~v75HI~
//*********************************                                //~v75HI~
    Sbinsw=BESOPT_F80;  		//parm to fileload,force /mn       //~v75HI~
	rc=func_browse_file(Ppcw);                                     //~v75HI~
    Sbinsw=0;				//parm to fileload                     //~v75HI~
    return rc;                                                     //~v75HI~
}//func_browsef80_file                                             //~v75HI~
//**************************************************************** //~v440I~
// func_browsehex_file                                             //~v440I~
//*same as BROwse /Mx                                              //~v440I~
//*parm1:uclient work element                                      //~v440I~
//*rc   :of func_browse_file                                       //~v440I~
//**************************************************************** //~v440I~
int func_browsehex_file(PUCLIENTWE Ppcw)                           //~v440I~
{                                                                  //~v440I~
	int rc;                                                        //~v440I~
//*********************************                                //~v440I~
    Sbinsw=BESOPT_HEX;  		//parm to fileload,force /mn       //~v440I~
	rc=func_browse_file(Ppcw);                                     //~v440I~
    Sbinsw=0;				//parm to fileload                     //~v440I~
    return rc;                                                     //~v440I~
}//func_browsehex_file                                             //~v440I~
//**************************************************************** //~v08lI~
// func_browse_file2                                               //~v08lI~
//*internal call interface,setup parseout tbl                      //~v08lI~
//*parm1:uclient work element                                      //~v08lI~
//*parm2:1:optional operand may exist,0:no optional opd            //~v08lI~
//*rc   :of func_browse_file                                       //~v08lI~
//**************************************************************** //~v08lI~
int func_browse_file2(PUCLIENTWE Ppcw,int Poptopd)                 //~v08lI~
{                                                                  //~v08lI~
//  UCHAR wkpot[MAXCOLUMN+1];                                      //~v08lI~//~va03R~
    UCHAR wkpot[MAXPARMSZ+1];                                      //~va03I~
    PUPODELMTBL pupod;                                             //~v08lI~
	int rc;                                                        //~v08lI~
//*********************************                                //~v08lI~
    filefnquate(Ppcw->UCWparm);     //quatation change             //~v0fsI~
	if (Poptopd)                                                   //~v08lI~
    {                                                              //~v08lI~
	    pupod=Ppcw->UCWopddelmt=Gpodelmt;                          //~v08lR~
		Ppcw->UCWopdpot=wkpot;                                     //~v08lI~
	    if ((rc=uparse2(Ppcw->UCWparm,&pupod,                      //~v08lR~
				&Ppcw->UCWopdpot,&Ppcw->UCWopdno,UPARSE2USEAREAPARM,","))>=4)//~v08lI~
	    	return rc;			//umalloc failed                   //~v08lI~
    }                                                              //~v08lI~
    else                                                           //~v09aI~
    {                                                              //~v09aI~
		Ppcw->UCWopdpot=Ppcw->UCWparm;  //same as before parse out //~v09aI~
		Ppcw->UCWopdno=1;                                          //~v09aI~
    }                                                              //~v09aI~
    return func_browse_file(Ppcw);                                 //~v08lI~
}//func_browse_file2                                               //~v08lI~
                                                                   //~v08lI~
//****************************************************************
// func_browse_file 
//*search file on fileq(load and enq if not exist)
//*parm1:file name
//*rc   :0-ok 4:file load err
//****************************************************************
int func_browse_file(PUCLIENTWE Ppcw)                           //~5118R~
{
	int rc;
	UFILEH *pfh;
    PUCLIENTWE pcw;                                             //~5118R~
	UCHAR  fpath[_MAX_PATH];                                       //~v60sR~
	UCHAR  *fname;                                              //~5118I~
#ifdef UTF8SUPPH                                                   //~v90rI~//~va00R~
	int opt;                                                       //~v90rI~//~va00I~
#endif                                                             //~v90rI~//~va00I~
	int opt2;                                                      //~vb2eI~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
	int cprc=0,optcp;                                              //~vb2eR~
//#endif                                                             //~vb2eI~//~vb2nR~
//*********************************
//	if (!(fname=Ppcw->UCWparm))//no parm                           //~v09aR~
    if (!(fname=Ppcw->UCWopdpot))//pparseout 1st parm              //~v09aR~
    {                                                           //~5123I~
//  	uerrmsg("Specify filename",                                //~v09rR~
//  			"ファイル名を指定して下さい");                     //~v09rR~
//      errmissing();                                              //~v11iR~
        fileedithelp('B');	//browse id                            //~v11iR~
    	return 8;                                               //~5123I~
    }                                                           //~5123I~
//  if (Sdireditsw				//from edit cmd                    //~v40uR~
//  &&  *Samembfullpath)                                           //~v40uR~
//  	fname=Samembfullpath;                                      //~v40uR~
//for v020 protect dir edit/browse @@@@                         //~v020I~
//  if (!UCBITCHK(Gopt3,GOPT3DIRPROCAVAIL))                     //~v030R~
//  	if (filedirchk(fname)>0)	//dir or dir+wildcard       //~v020R~
//  	{                                                       //~v020R~
//  		uerrmsg("%s is direcory,wait next release",         //~v020R~
//  				"%s はディレクトリーです（次版予定)",fname);//~v020R~
//  		return 8;                                           //~v020R~
//  	}                                                       //~v020R~
                                                                   //~v08lI~
//  if (Ppcw->UCWopdno>1)                                          //~v08lR~
//  	return errtoomany();                                       //~v08lR~
                                                                   //~v08lI~
//for (;;)                                                         //~v40uR~
//{                                                                //~v40uR~
//  if (rc=filesrchpfh(fname,fullpath,&pfh),rc>4)                  //~v13dR~
//  if (rc=filesrchpfh2(Ppcw,fname,fullpath,&pfh),rc>4)            //~v60sR~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
	optcp=FSPFHCPO_PFH2;                                           //~vb2eI~
    if (rc=filesrchpfhCP(optcp,Ppcw,fname,fpath,&pfh,UFCFBROWSE,&cprc),rc>4)//~vb2eR~
    	return 16;                                                 //~vb2eI~
//#else                                                              //~vb2eI~//~vb2nR~
//    if (rc=filesrchpfh2(Ppcw,fname,fpath,&pfh,UFCFBROWSE),rc>4)    //~v60sR~//~vb2nR~
//        return 16;                                              //~5125I~//~vb2nR~
//#endif                                                             //~vb2eI~//~vb2nR~
	if (!rc)	//found                                         //~5125R~
	{                                                           //~5118I~
    	if (filemixmodechk(0,pfh))                                 //~v440I~
        	return 4;                                              //~v440I~
        if ((pcw=pfh->UFHbrowsepcw[Ppcw->UCWsplitid])==Ppcw)    //~5118R~
    	{                                                       //~5118I~
    		uerrmsg("%s is now Browsing",                       //~5118I~
//  				"%s は現表示中です",fullpath);                 //~v095R~
    				"%s は現\x95\\示中です",fpath);                //~v60sR~
    		return 8;                                           //~5118I~
    	}                                                       //~5118I~
		if (pcw)	//browse pushed on same splitid             //~5118R~
		{                                                       //~5118I~
    		uerrmsg("Re-display of BROWSE %s",                  //~5118R~
//    				"%s の表示 再表示",fullpath);                  //~v095R~
      				"%s の\x95\\示 再\x95\\示",fpath);             //~v60sR~
         	scrpopup(pcw,0);	//no deq save ptr parm          //~5228R~
            csrhomepos(0);//home of current scr                 //~v020I~
            return 0;                                           //~5118I~
	    } 	                                                    //~5118I~
        if ((pcw=pfh->UFHbrowsepcw[!Ppcw->UCWsplitid])!=0)	//another screen//~v13nR~
            if (pcw==scrgetcw(-1))	//not on other client surface  //~v13nI~
    			uerrmsg("2'nd screen",                             //~v13nI~
    					"第二\x95\\示");                           //~v13nR~
			else                                                   //~v13nI~
    			uerrmsg("Warning:%s is already under the base",    //~v13nI~
    					"注意:%s は別途潜伏中です",                //~v13nI~
						fpath);                                    //~v60sR~
        else                                                       //~v40yI~
    		uerrmsg("Edit mode already opened.",                   //~v40yI~
    				"別途編集窓あり");                             //~v40yI~
		pfh->UFHopenctr++;                                      //~5118I~
#ifdef UTF8SUPPH                                                   //~v90rI~//~va00R~
//      if (FILEUTF8MODE(&Scmdparmufh))	//CPU8 parm specified      //~v922R~//~va00M~
//      	opt=(UFCF2UTF8<<8);                                    //~v922R~//~va00M~
      if (UCBITCHK(Scmdparmufh.UFHflag8,UFHF8UTF8P))	//parm specified//~v92jI~//~va00M~
        opt=((UCHAR)(Scmdparmufh.UFHflag8)<<8);                //~v922I~//~v922R~//~va00M~
      else                                                         //~v92jI~//~va00M~
       	opt=((UCHAR)(pfh->UFHflag8)<<8); //result of fileload(dirload)//~v92jI~//~va00M~
#endif                                                             //~v90rI~//~va00M~
	}//already browse/edit                                      //~5118I~
	else                                                        //~5118I~
	{                                                           //~5118I~
//  	if (rc=fileload(Ppcw,fname,fullpath,UFCFBROWSE,&pfh),rc)   //~v54dR~
//  	if (rc=fileload(Ppcw,fname,fpath,UFCFBROWSE,&pfh,Sbinsw,Seditsosw,Sfkinisw),rc)//~v60sR~//~vb2eR~
        opt2=Sfkinisw;                                             //~vb2eI~
#ifdef LNX                                                         //~vb2eI~
        if (cprc & FSPFHCPRC_MOUNTU8)           		//device iocharset is utf8//~vb2eI~
			opt2|=FEBFIO_MOUNTU8;  	//internal edit/brwse call option//~vb2eR~
        if (cprc & FSPFHCPRC_MOUNTU8CV)           		//device iocharset is utf8//~vb2eI~
			opt2|=FEBFIO_MOUNTU8CV;  	//internal edit/brwse call option//~vb2eI~
#endif                                                             //~vb2eI~
    	if (rc=fileload(Ppcw,fname,fpath,UFCFBROWSE,&pfh,Sbinsw,Seditsosw,opt2),rc)//~vb2eI~
			return rc;                                          //~5118R~
                                                                   //~v185I~
//    if (!UCBITCHK(pfh->UFHflag5,UFHF5LISTDIR))	//no /l option //~v40uR~
//      if (pfh->UFHtype==UFHTDIR	//dir or wild card             //~v40uR~
//  	&&  strpbrk(fullpath,"*?")	//wild card                    //~v40uR~
//  	&& filegetadirmember(pfh,fullpath))	//only a member,reset fullpath//~v40uR~
//      {                                                          //~v40uR~
//      	fileclosefree2(pfh);                                   //~v40uR~
//          strcpy(Samembfullpath,fullpath);                       //~v40uR~
//      	if (Sdireditsw)				//not from edit cmd        //~v40uR~
//          {                                                      //~v40uR~
//          	Sdireditsw=2;			//tell to file_edit;dir    //~v40uR~
//          	return 0;			//retry                        //~v40uR~
//  		}                                                      //~v40uR~
//          fname=Samembfullpath;                                  //~v40uR~
//      	continue;                   //retry by filename        //~v40uR~
//      }                                                          //~v40uR~
		UENQ(UQUE_TOP,&Sfileq,pfh);                             //~5118R~
#ifdef UTF8SUPPH                                                   //~v90rI~//~va00R~
//      if (FILEUTF8MODE(pfh))	//CPU8 parm specified              //~v90rI~//~v922R~//~va00I~
//      	opt=(UFCF2UTF8<<8);                                    //~v90rI~//~v922R~//~va00I~
//     	opt=((UCHAR)(Scmdparmufh.UFHflag8)<<8);                    //~v92jR~//~va00I~
       	opt=((UCHAR)(pfh->UFHflag8)<<8); //result of fileload(dirload)//~v92jR~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
       	opt|=((UCHAR)(pfh->UFHflag10)<<16); //ebcopt               //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~v90rI~//~va00I~
	}                                                           //~5118I~
//  break;      //not a member of wild card                        //~v40uR~
//}//for only a member                                             //~v40uR~
    if (pfh->UFHtype!=UFHTDIR)                                  //~v020I~
		pcw=fileregist(Ppcw,PANFBROWSE,pfh,Seditsosw);             //~v0d5R~
    else                                                        //~v030I~
//  	pcw=dirregist(UFCFBROWSE+UFCFDEDIT*Sdireditsw,pfh);        //~v690R~
#ifdef UTF8SUPPH                                                   //~v90rI~//~va00R~
    	pcw=dirregist(opt|(UFCFBROWSE+UFCFDEDIT*Sdireditsw),Ppcw,pfh);	//pass pcw to get cmd parm for pan300stack//~v90rI~//~va00I~
#else                                                              //~v90rI~//~va00I~
    	pcw=dirregist(UFCFBROWSE+UFCFDEDIT*Sdireditsw,Ppcw,pfh);	//pass pcw to get cmd parm for pan300stack//~v690R~
#endif                                                             //~v90rI~//~va00I~
    if (!pcw)       //storage shortage                          //~v04dI~
    {                                                           //~v04dI~
    	fileclosefree2(pfh);	//close and free pfh            //~v04dI~
        return UALLOC_FAILED;                                   //~v04dI~
    }                                                           //~v04dI~
	pfh->UFHbrowsepcw[Ppcw->UCWsplitid]=pcw;                    //~5118R~
//#ifdef FTPSUPP                                                   //~v555R~
//    if (pfh->UFHtype==UFHTHOSTS)//ftp hosts                      //~v555R~
//        xeftphostsget(pcw,pfh); //setup hosts table              //~v555R~
//#endif                                                           //~v555R~
	return 0;
}//func_browse_file
                                                                //~5125I~
//**************************************************************** //~v440I~
// mixmode open chk                                                //~v440I~
//*create fullpath of only one member in the dir                   //~v440I~
//*parm1:0:browse,1:edit                                           //~v440I~
//*parm2:pfh                                                       //~v440I~
//*rc   :4: mixed open req                                         //~v440I~
//**************************************************************** //~v440I~
int filemixmodechk(int Pbesw,PUFILEH Ppfh)                         //~v440I~
{                                                                  //~v440I~
//******************************                                   //~v440I~
//  if (Sbinsw==BESOPT_BIN||(Scmdopt & BECMDOPT_BIN))//binary mode //~v60zR~
    if (Sbinsw==BESOPT_BIN                                         //~v60zI~
    ||  (Scmdopt & (BECMDOPT_BIN|BECMDOPT_HEX))==BECMDOPT_BIN)//binary mode//~v60zI~
    {                                                              //~v440I~
        if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)   //not opend by bin//~v458R~
        ||   UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))  //not opend by bin//~v458I~
            return fileerrmixmode(Ppfh->UFHfilename);              //~v440R~
    }                                                              //~v440I~
    else 		//text mode                                        //~v440I~
//      if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //opend by bin     //~v458R~
//          return fileerrmixmode(Ppfh->UFHfilename);              //~v458R~
    if (Sbinsw==BESOPT_HEX||(Scmdopt & BECMDOPT_HEX))//hex mode    //~v440I~
    {                                                              //~v440I~
        if (!UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))  //not opend by bin//~v440R~
            return fileerrmixmode(Ppfh->UFHfilename);              //~v440R~
    }                                                              //~v440I~
//  else 		//text mode                                        //~v50cR~
//      if (UCBITCHK(Ppfh->UFHflag5,UFHF5HEX))  //not opend by bin //~v458R~
//          return fileerrmixmode(Ppfh->UFHfilename);              //~v458R~
//  if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //opend by bin         //~v50cR~
//      return fileerrmixmode(Ppfh->UFHfilename);                  //~v50cR~
#ifdef UTF8SUPPH                                                   //~va00I~
    if (UCBITCHK(Scmdparmufh.UFHflag8,UFHF8UTF8P))	//cpu8/cplc parm specified//~va00R~
//  if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //not opend by bin    //~va00R~
    {                                                              //~va00I~
        if ((   UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8)                 //~va00R~
             &&!UCBITCHK(Scmdparmufh.UFHflag8,UFHF8UTF8))          //~va00R~
        ||                                                         //~va00I~
            (  !UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8)                 //~va00R~
             && UCBITCHK(Scmdparmufh.UFHflag8,UFHF8UTF8))          //~va00R~
        )                                                          //~va00I~
        {                                                          //~va00I~
            if (Ppfh->UFHtype!=UFHTDIR)                            //~va00I~
            {                                                      //~va00I~
	            uerrmsg("For duplicated open, %s/%s option conflict with the first specification",//~va00R~
    	                "２重オープンですが %s/%s オプションが最初と異なります。",//~va00R~
						MODE_UTF8,MODE_LOCALE);                    //~va00R~
            	        return 4;                                  //~va00R~
            }                                                      //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
#endif                                                             //~va00I~
    return 0;                                                      //~v440I~
}//filemixmodechk                                                  //~v440I~
////****************************************************************//~v40uR~
//// filegetadirmember                                             //~v40uR~
////*create fullpath of only one member in the dir                 //~v40uR~
////*parm1:pfh                                                     //~v40uR~
////*parm2:output fullpath file name                               //~v40uR~
////*rc   :1-only a member;0:not a member                          //~v40uR~
////****************************************************************//~v40uR~
//int filegetadirmember(PUFILEH Ppfh,char *Pfullpath)              //~v40uR~
//{                                                                //~v40uR~
//    PULINEH plh;                                                 //~v40uR~
//    PUDIRLH pdh=0;                                               //~v40uR~
//    int     membctr=0;                                           //~v40uR~
////*****************                                              //~v40uR~
//    plh=UGETQTOP(&Ppfh->UFHlineque);                             //~v40uR~
//    for (;plh;plh=UGETQNEXT(plh))    //all entry                 //~v40uR~
//    {                                                            //~v40uR~
//        if (plh->ULHtype!=ULHTDATA)                              //~v40uR~
//            continue;                                            //~v40uR~
//        pdh=UGETPDH(plh);                                        //~v40uR~
//        if (pdh->UDHtype==UDHTPARENT                             //~v40uR~
//        ||  pdh->UDHtype==UDHTDIREXPMASK)                        //~v40uR~
//            continue;                                            //~v40uR~
//        if (membctr)    //2nd entry                              //~v40uR~
//            return 0;   //not single member                      //~v40uR~
//        membctr++;                                               //~v40uR~
//    }                                                            //~v40uR~
//    if (!membctr)                                                //~v40uR~
//        return 0;   //not single member                          //~v40uR~
//    if (dlcgetfullname(pdh,Pfullpath))                           //~v40uR~
//        return 0;                                                //~v40uR~
//    return 1;                                                    //~v40uR~
//}//filesrchpfh                                                   //~v40uR~
//****************************************************************//~5125I~
// filesrchpfh                                                  //~5125I~
//*search pfh already opened                                    //~5125I~
//*parm1:file name                                              //~5125I~
//*parm2:output fullpath file name                              //~5125I~
//*parm3:output pfh ptr,option                                  //~5507R~
//*rc   :0-found 4-not found 16-filename err                    //~5125I~
//****************************************************************//~5125I~
int filesrchpfh(UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh)  //~5125I~
{                                                               //~5125I~
	UCHAR *filename;                                            //~5128I~
	PUFILEH pfh;                                                //~5128I~
//*****************                                             //~5125I~
	if (Pfullpath)                                              //~5128I~
	{                                                           //~5128I~
		if (!filefullpath(Pfullpath,Ppfile,_MAX_PATH))//fullpath name//~5128R~
    		return 16;                                          //~5128R~
		filename=Pfullpath;                                     //~5128I~
#ifdef LNX                                                         //~vb2eI~
		if (SchkmountCP)	//from filesrchpfhCP                   //~vb2eI~
        {                                                          //~vb2eI~
    		if (Gsubgblopt & XESUB_GBLOPT_DONE_CHKMOUNT_FFP)   //done at filefullpath//~vb2eI~
            {                                                      //~vb2eI~
	    		SmountCPU8=(Gsubgblopt & XESUB_GBLOPT_RC_MOUNTU8_FFP);  //mount chk result:iocharset=utf8//~vb2eR~
	    		SmountCPU8cv=(Gsubgblopt & XESUB_GBLOPT_DONE_L2F);  //mount chk result:iocharset=utf8//~vb2eI~
            }                                                      //~vb2eI~
        }                                                          //~vb2eI~
#endif                                                             //~vb2eI~
    }                                                           //~5128I~
	else                                                        //~5128I~
		filename=Ppfile;                                        //~5128I~
	if (!(pfh=uqscan(UQUE_TOP,&Sfileq,fncomp,filename)))//not found//~5128R~
		return 4;                                               //~5125I~
	if (Pppfh)	//pfh requested                                 //~5128I~
		*Pppfh=pfh;                                             //~5128I~
	return 0;                                                   //~5125I~
}//filesrchpfh                                                  //~5125I~
//#ifdef LNX                                                         //~vb2jI~//~vb2nR~
//********************************************************************************//~vb2jR~
//*filename translation by FN{LC|U8} option                        //~vb2jI~
//*called when filesrchpfhCP                                       //~vb2jI~
//rc :1:do mountchk                                                //~vb2jI~
//outfntype :1:utf8,2:locale code,0:not translated,4:cv error      //~vb2jR~
//           -1:FNU8 option and input is utf8 ,-2:FNLC option and input is lc//~vb2jI~
//********************************************************************************//~vb2jR~
 int filefntransbyfnopt(int Popt,PUFILEH Ppfh,UCHAR *Ppfile,UCHAR *Ppoutfnm,int Pbuffsz)//~vb2jI~
 {                                                                 //~vb2jI~
 	int rc2,outfntype=0,opt,lenu8,ucsctr,len,chklen,wrtlen;        //~vb2jR~
    char *pfnm;                                                    //~vb2nI~
#ifdef W32                                                         //~vb2nI~
	char wkud[_MAX_PATH];                                          //~vb2nI~
    int  lenud;                                                    //~vb2nI~
#endif                                                             //~vb2nI~
//******************************                                   //~vb2jI~
	for (;;)                                                       //~vb2jI~
    {                                                              //~vb2jI~
		if (Gotheropt & GOTHERO_NOFNTRANSOPT)                      //~vb2jI~
        	break;                                                 //~vb2jI~
		UTRACEP("%s:flag12=%x\n",UTT,Ppfh->UFHflag12);             //~vb2jI~
        if (!UCBITCHK(Ppfh->UFHflag12,UFHF12FNCMD)              //no FN{LC|U8|AS} option//~vb2jI~
	    ||  !UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC|UFHF12FNU8)	//for select dlcmd//~vb2jI~
        )                                                          //~vb2jI~
        	break;                                                 //~vb2jI~
        opt=0;                                                     //~vb2jI~
        len=(int)strlen(Ppfile);                                   //~vb2jI~
		UTRACED("inp",Ppfile,len);                                 //~vb2jI~
        lenu8=utfgetutf8strlen(opt,Ppfile,len,&ucsctr);            //~vb2jI~
        if (lenu8==len) //all utf8/ascii                           //~vb2jR~
        {                                                          //~vb2jI~
    	    if (lenu8==ucsctr)  //all ascii                        //~vb2jI~
        		break;                                             //~vb2jI~
    		if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))	           //~vb2jR~
            {                                                      //~vb2jI~
                outfntype=-1;	//no conv,utf8                   //~vb2jI~//~vb2nR~
            	break;                                             //~vb2jI~
            }                                                      //~vb2jI~
            else	//need u8-->lc                                 //~vb2jI~
            {                                                      //~vb2jI~
                pfnm=Ppfile;                                       //~vb2nI~
#ifdef W32                                                         //~vb2nI~
			  	if (fsubw_stripUDCT(0,Ppfile,lenu8,wkud,sizeof(wkud),0/*ct*/,0/*sizeof(wkfpathct)*/,&lenud))//strip done//~vb2nI~
                {                                                  //~vb2nI~
                	pfnm=wkud;                                     //~vb2nI~
                    lenu8=lenud;                                   //~vb2nI~
                }                                                  //~vb2nI~
#endif                                                             //~vb2nI~
                opt=UTFCVO_ERRRET;                                 //~vb2jI~
//              rc2=utfcvf2l(opt,Ppoutfnm,Ppfile,lenu8,&chklen,&wrtlen,0/*Ppcharwidth*/);//~vb2jI~//~vb2nR~
                rc2=utfcvf2l(opt,Ppoutfnm,pfnm,lenu8,&chklen,&wrtlen,0/*Ppcharwidth*/);//~vb2nI~
                if (!rc2)    //no err                              //~vb2jI~
                {                                                  //~vb2jI~
                	outfntype=2;	//cv to lc done                //~vb2jI~//~vb2nR~
                    *(Ppoutfnm+wrtlen)=0;                          //~vb2jR~
                }                                                  //~vb2jI~
                else                                               //~vb2jI~
                {                                                  //~vb2jI~
					UCBITOFF(Ppfh->UFHflag12,UFHF12FNCMD|UFHF12FNLC);//~vb2jR~
                    uerrmsg("\"FNLC\" option was ignored by translation error.",//~vb2jR~
                            "\"FNLC\" オプションは変換エラーにより無視されました");//~vb2jI~
                }                                                  //~vb2jI~
                UTRACED("cv u8 to lc",Ppoutfnm,wrtlen);            //~vb2jI~
            }                                                      //~vb2jI~
        }                                                          //~vb2jI~
        else 	//contains lc                                      //~vb2jI~
        {                                                          //~vb2jI~
    		if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))              //~vb2jR~
            {                                                      //~vb2jI~
                outfntype=-2;	//no conv,lc                       //~vb2nR~
            	break;                                             //~vb2jI~
            }                                                      //~vb2jI~
            else	//need lc-->u8                                 //~vb2jI~
            {                                                      //~vb2jI~
                opt=UTFCVO_BUFFSZPARM|UTFCVO_ERRRET; //outbuff size parm specified//~vb2jI~
                lenu8=Pbuffsz;   //buff size limit                 //~vb2jI~
//              rc2=utfcvl2fany(opt,0/*locale*/,Ppoutfnm,Ppfile,0/*init offs*/,len,0/*out choftbl*/,0/*outdbvcs*/,&chklen,&lenu8,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~vb2jI~//~vb2nR~
                rc2=utfcvl2f(opt,Ppoutfnm,Ppfile,0/*init offs*/,len,0/*out choftbl*/,0/*outdbvcs*/,&chklen,&lenu8,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~vb2nI~
#ifdef W32                                                         //~vb2nI~
                if (!rc2)    //no err                              //~vb2nI~
                {                                                  //~vb2nI~
                    *(Ppoutfnm+lenu8)=0;                           //~vb2nI~
					rc2=ufilecvU82UD(0,Ppoutfnm,wkud,sizeof(wkud)-1,&lenu8);//~v6uaR~//~vb2nR~
                    if (!rc2)                                      //~vb2nI~
                    	memcpy(Ppoutfnm,wkud,(size_t)lenu8);       //~vb2nR~
                }                                                  //~vb2nI~
#endif                                                             //~vb2nI~
                if (!rc2)    //no err                              //~vb2jI~
                {                                                  //~vb2jI~
                	outfntype=1;	//cv to utf8 done	           //~vb2jI~
                    *(Ppoutfnm+lenu8)=0;                           //~vb2jR~
                }                                                  //~vb2jI~
                else                                               //~vb2jI~
                {                                                  //~vb2jI~
					UCBITOFF(Ppfh->UFHflag12,UFHF12FNCMD|UFHF12FNU8);//~vb2jR~
                    uerrmsg("\"FNU8\" option was ignored by translation error.",//~vb2jI~
                            "\"FNU8\" オプションは変換エラーにより無視されました");//~vb2jI~
                }                                                  //~vb2jI~
                UTRACED("cv lc to u8",Ppoutfnm,lenu8);             //~vb2jI~
            }                                                      //~vb2jI~
        }                                                          //~vb2jI~
        break;                                                     //~vb2jI~
    }//for                                                         //~vb2jI~
	UTRACEP("%s:return outfntype=%d\n",UTT,outfntype);             //~vb2jI~
    return outfntype;                                              //~vb2jI~
}//filefntransbyfnopt                                              //~vb2jI~
//#endif                                                             //~vb2jI~//~vb2nR~
//**************************************************************** //~v13dI~
// filesrchpfh2                                                    //~v13dI~
//*search pfh already opened(allow fullpathname with *\)           //~v13dI~
//*parm1:file name                                                 //~v13dI~
//*parm2:output fullpath file name                                 //~v13dI~
//*parm3:output pfh ptr,option                                     //~v13dI~
//*rc   :0-found 4-not found 16-filename err                       //~v13dI~
//**************************************************************** //~v13dI~
//int filesrchpfh2(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh)//~v60sR~
int filesrchpfh2(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh,UCHAR Popt)//~v60sR~
{                                                                  //~v13dI~
	UFILEH ufh;	//for option parm result set                       //~v60sI~
	UCHAR  fpath[_MAX_PATH];                                       //~v60sR~
    char *pc;                                                      //~v40uI~
    int  opt;                                                      //~v40uI~
    int  rc;                                                       //~v60sI~
#ifdef W32UNICODE                                                  //~vavaI~
	UCHAR  udfnm[_MAX_PATH];                                       //~vavaI~
    int udlen;                                                     //~vavaI~
    UCHAR *pudfnm;                                                 //~vb2nI~
#endif                                                             //~vavaI~
//#ifdef LNX                                                         //~vb2jI~//~vb2nR~
//  int cvfntype;                                                  //~vb2jR~//~vb2nR~
    int cvfntype=0;                                                //~vb2nI~
	UCHAR  wkfntrans[_MAX_PATH];                                   //~vb2jI~
//#endif                                                             //~vb2jI~//~vb2nR~
//*****************                                                //~v13dI~
//  if (!dcmdfullpath(Ppcw,fullpath,Ppfile))                       //~v40uR~
	Gsubgblopt|=XESUB_GBLOPT_WILDPATH;	//expand wildcard path     //~v40uI~
//  opt=fileoptionprechk(Ppcw); //force dir list req chk           //~v60sR~
    if (rc=fileoptionprechk(Ppcw,&ufh,Popt,Sbinsw,&opt),rc) //force dir list req chk//~v60sR~
    {                                                              //~v6azI~
        if (rc==4)                                                 //~v6azI~
            rc=8; //for edit_file fpathname is not setup           //~v6azI~
		Gsubgblopt&=~XESUB_GBLOPT_WILDPATH;//clear for later req   //~vb4BI~
    	return rc;                                                 //~v60sI~
    }                                                              //~v6azI~
#ifdef W32UNICODE                                                  //~vavaI~
  if (!SchkmountCP)	//from filesrchpfhCP                           //~vb2nI~
    fsubw_U82UD(0,Ppcw,&ufh,Ppfile,0,udfnm,sizeof(udfnm),&udlen);//enclose utf8 string//~vavaR~
#endif                                                             //~vavaI~
    Scmdopt=opt;//return value to edit/browse                      //~v440I~
    Scmdparmufh=ufh;//parm to reopenchk                            //~v60sI~
    if (!(opt & BECMDOPT_LISTDIR))	//not dirlist brwose forsed    //~v40uR~
		Gsubgblopt|=XESUB_GBLOPT_WILDMEMB;	//expand wildcard memb //~v40uI~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
#ifdef W32                                                         //~vb2nI~
  	pudfnm=Ppfile;                                                 //~vb2nI~
#endif                                                             //~vb2nI~
	if (SchkmountCP)	//from filesrchpfhCP                       //~vb2eI~
    {                                                              //~vb2eI~
		cvfntype=filefntransbyfnopt(0,&ufh,Ppfile,wkfntrans,sizeof(wkfntrans));//~vb2jR~
#ifdef LNX                                                         //~vb2nI~
        if (UCBITCHK(ufh.UFHflag12,UFHF12FNCMD)              //specified FNLC or FNU8 cmd option//~vb2eR~
	    ||  UCBITCHK(ufh.UFHflag13,UFHF13SELECTFNU8|UFHF13SELECTFNLC)	//for select dlcmd//~vb2eR~
	    ||  (Ssrchcpopt & FSPFHCPO_NOCHKMOUNT))                    //~vb2eI~
        {                                                          //~vb2eI~
            Gsubgblopt |= XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP;     //no mountchk at filefullpath//~vb2eI~
    		UTRACEP("%s:NOCHKMOUNT UFHflag12=%x,UFHflag13=%x,Ssrchcpopt=%x\n",UTT,ufh.UFHflag12,ufh.UFHflag13,Ssrchcpopt);//~vb2eI~//~vb2jR~
        }                                                          //~vb2eI~
        else                                                       //~vb2eI~
            Gsubgblopt &= ~XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP;   //mountchk at filefullpath//~vb2eI~
#else                                                              //~vb2nI~
//  	pudfnm=Ppfile;                                             //~vb2nR~
        if (cvfntype==1||cvfntype==2)	//translation done         //~vb2nI~
        	pudfnm=wkfntrans;           //ud fmt if cvfntype==1    //~vb2nI~
        if (cvfntype==0||cvfntype==-1)	//no trans or org u8       //~vb2nI~
        {                                                          //~vb2nI~
//    		if (!fsubw_U82UD(0,Ppcw,&ufh,Ppfile,0,udfnm,sizeof(udfnm),&udlen))//enclose utf8 string//~vb2nI~//~vb3bR~
      		if (fsubw_U82UD(0,Ppcw,&ufh,Ppfile,0,udfnm,sizeof(udfnm),&udlen)<4)//enclose utf8 string//~vb3bI~
            	pudfnm=udfnm;                                      //~vb2nI~
        }                                                          //~vb2nI~
#endif                                                             //~vb2nI~
    }                                                              //~vb2eI~
//#endif                                                             //~vb2eI~//~vb2nR~
#ifdef W32UNICODE                                                  //~vavaI~
//  pc=dcmdfullpath(Ppcw,fpath,udfnm);	//expand wild card if exist//~vavaI~//~vb2nR~
    pc=dcmdfullpath(Ppcw,fpath,pudfnm);	//expand wild card if exist//~vb2nI~
#else                                                              //~vavaI~
  if (cvfntype>0)                                                  //~vb2jI~
    pc=dcmdfullpath(Ppcw,fpath,wkfntrans);//expand wild card if exist//~vb2jI~
  else                                                             //~vb2jI~
    pc=dcmdfullpath(Ppcw,fpath,Ppfile);	//expand wild card if exist//~v60sR~
#endif                                                             //~vavaI~
#ifdef LNX                                                         //~vb2eI~
	if (SchkmountCP)	//from filesrchpfhCP                       //~vb2eI~
    {                                                              //~vb2eI~
        if (Gsubgblopt & XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP)     //no mountchk at filefullpath//~vb2eI~
		    SmountCPU8=SmountCPU8cv=0;	                           //~vb2eR~
        else                                                       //~vb2eI~
    	{                                                          //~vb2eM~
	    	if (Gsubgblopt & XESUB_GBLOPT_DONE_CHKMOUNT_FFP)   //done at filefullpath//~vb2eI~
            {                                                      //~vb2eI~
		    	SmountCPU8=(Gsubgblopt & XESUB_GBLOPT_RC_MOUNTU8_FFP);  //request to filesrchpfh/filesrchpfh2 to check mount option//~vb2eR~
	    		SmountCPU8cv=(Gsubgblopt & XESUB_GBLOPT_DONE_L2F);  //mount chk result:iocharset=utf8//~vb2eI~
            }                                                      //~vb2eI~
    	}                                                          //~vb2eM~
    }                                                              //~vb2eI~
#endif                                                             //~vb2eI~
	Gsubgblopt&=~(XESUB_GBLOPT_WILDPATH|XESUB_GBLOPT_WILDMEMB);//clear for later req//~v40uI~
    if (!pc)                                                       //~v40uI~
    	return 16;                                                 //~v13dI~
	if (Pfullpath)                                                 //~v13dI~
		strcpy(Pfullpath,fpath);                                   //~v60sR~
    return filesrchpfh(fpath,0,Pppfh);                             //~v60sR~
}//filesrchpfh2                                                    //~v13dI~
//#ifdef LNX                                                         //~vb2eI~//~vb2nR~
//**************************************************************** //~vb2eI~
// filesrchpfhCP                                                   //~vb2eI~
// serch by u8name if device IOCHARSET is utf8                     //~vb2eI~
//*cprc :0x01:device iocharset=utf8, 0x02:lc dbcs was translated to utf8//~vb2eI~
//**************************************************************** //~vb2eI~
int filesrchpfhCP(int Poptopt,PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,PUFILEH *Pppfh,UCHAR Popt,int *Ppcprc)//~vb2eI~
{                                                                  //~vb2eI~
	int rc;                                                        //~vb2nI~
#ifdef LNX                                                         //~vb2nI~
	int cprc=0,cvrc=0,opt;                                      //~vb2eR~//~vb2nR~
    char wkfpathu8[_MAX_PATH],*pc;                                 //~vb2eR~
#endif                                                             //~vb2nI~
//*****************                                                //~vb2eI~
    UTRACEP("%s:opt=%x,fnm=%s\n",UTT,Poptopt,Ppfile);              //~vb2eR~
	SchkmountCP=1;	//parm to filesrchpfh(2)                       //~vb2eI~
#ifdef LNX                                                         //~vb2nI~
	SmountCPU8=-1;	//parm to filesrchpfh(2)                       //~vb2eI~
#endif                                                             //~vb2nI~
    Ssrchcpopt=Poptopt;                                            //~vb2eI~
    if (Ssrchcpopt & FSPFHCPO_PFH2)            //call filesrchpfh2 //~vb2eR~
	    rc=filesrchpfh2(Ppcw,Ppfile,Pfullpath,Pppfh,Popt);         //~vb2eR~
    else                                                           //~vb2eI~
	    rc=filesrchpfh(Ppfile,Pfullpath,Pppfh);                    //~vb2eI~
#ifdef LNX                                                         //~vb2nI~
	if (!rc)  //pfh found                                          //~vb2eI~
    {                                                              //~vb2eI~
    	cprc=UCBITCHK((*Pppfh)->UFHflag14,UFHF14MOUNTU8);          //~vb2eR~
    	cvrc=UCBITCHK((*Pppfh)->UFHflag14,UFHF14MOUNTU8CV);        //~vb2eI~
    }                                                              //~vb2eI~
    else                                                           //~vb2eI~
    if (rc==4) //pfh not found                                     //~vb2eI~
    {                                                              //~vb2eI~
	    if ((Ssrchcpopt & FSPFHCPO_NOCHKMOUNT))                    //~vb2eR~
        	;                                                      //~vb2eI~
        else                                                       //~vb2eI~
		if (SmountCPU8!=-1)	//ufullpathCP called                   //~vb2eI~
        {                                                          //~vb2eI~
        	cprc=SmountCPU8;                                       //~vb2eR~
        	cvrc=SmountCPU8cv;                                     //~vb2eI~
        }                                                          //~vb2eI~
        else                                                       //~vb2eI~
        {                                                          //~vb2eI~
        	opt=0;                                                 //~vb2eI~
	        pc=ufullpathCP(opt,wkfpathu8,Pfullpath,(int)sizeof(wkfpathu8),&cvrc);//~vb2eI~
            if (pc)                                                //~vb2eI~
            {                                                      //~vb2eI~
                if (cvrc & (UFPCPRC_IOCS_U8|UFPCPRC_IOCS_UNKNOWN)) //~vb2eI~
                    cprc=1;                                        //~vb2eM~
                cvrc=(cvrc & UFPCPRC_CONVU8);   //converted        //~vb2eR~
                if (cvrc)                                          //~vb2eI~
                    strcpy(Pfullpath,wkfpathu8);                   //~vb2eR~
            }                                                      //~vb2eI~
        }                                                          //~vb2eI~
    }                                                              //~vb2eI~
    *Ppcprc=(cprc ? FSPFHCPRC_MOUNTU8 : 0)|(cvrc ? FSPFHCPRC_MOUNTU8CV : 0);//~vb2eR~
#else                                                              //~vb2nI~
    *Ppcprc=0;                                                     //~vb2nI~
#endif                                                             //~vb2nI~
	SchkmountCP=0;                                                 //~vb2eI~
	Ssrchcpopt=0;                                                  //~vb2eI~
    UTRACEP("%s:rc=%d,cprc=%x,fpath=%s,pfh=%p\n",UTT,rc,*Ppcprc,Pfullpath,*Pppfh);//~vb2eR~
    return rc;                                                     //~vb2eI~
}//filesrchpfhCP                                                   //~vb2eR~
//#endif  //LNX                                                      //~vb2eI~//~vb2nR~
//****************************************************************//~v03uI~
//* deq and free pfh                                            //~v03uI~
//* parm:pfh                                                    //~v03uI~
//* ret :none                                                   //~v03uI~
//****************************************************************//~v03uI~
void filefreepfh(PUFILEH Ppfh)                                  //~v03uI~
{                                                               //~v03uI~
//***************                                               //~v03uI~
    if (UGETQHDR(Ppfh)) //confirm enqed for i/o err etc         //~v04dI~
		UDEQ(UQUE_ENT,0,Ppfh);                                     //~v78cR~
	if (Ppfh->UFHpvlcmd)                                        //~v03uI~
		ufree(Ppfh->UFHpvlcmd);	//ULCMD copy area               //~v03uI~
	if (Ppfh->UFHmfwtbl)                                        //~v05vI~
		ufree(Ppfh->UFHmfwtbl);	//find all tbl                  //~v05vI~
#ifdef UTF8SUPPH                                                   //~va00I~
		UFREEIFNZ(Ppfh->UFHhdrnameattr);	//codetbl for hdr line //~va00I~
		UFREEIFNZ(Ppfh->UFHfilenamecodetype);	//codetbl for hdr line//~va1BI~
//#ifdef LNX                                                       //~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaR~
		UFREEIFNZ(Ppfh->UFHfilenamedddata);	//codetbl for hdr line //~vau7I~
#endif                                                             //~vau7I~
#endif                                                             //~va00I~
	ufree(Ppfh);                                                   //~v78cR~
    return;                                                     //~v03uI~
}//filefreepfh	                                                //~v03uI~
//****************************************************************//~v020M~
//* end command                                                 //~v020M~
//****************************************************************//~v037M~
int func_end_file(PUCLIENTWE Ppcw)                              //~v020M~
{                                                               //~v020M~
	int rc;                                                     //~v020M~
	PUFILEC pfc;                                                //~v020M~
	PUFILEH pfh;                                                //~v020M~
//***************                                               //~v020M~
	if (UCBITCHK(Ppcw->UCWflag3,UCWF3EXECMD))	//execmd owner     //~v77LI~
    	return funcerrexecmdinprog();                              //~v77LI~
    csrsetwait(1);                                                 //~v154I~
	rc=0;                                                       //~v020M~
	pfc=Ppcw->UCWpfc;                                           //~v020M~
	pfh=pfc->UFCpfh;                                            //~v020M~
    UTRACEP("%s:pfhname=%s\n",UTT,pfh->UFHfilename);               //~vbi3R~
	if (!UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//not browse mode   //~v020M~
    {                                                           //~v020M~
		if (rc=filesave(Ppcw,1,pfh,0,0,0),rc)//end cmd,plh1=plh2=0,save to same file//~v445R~
        {                                                          //~v154I~
		    csrsetwait(0);                                         //~v154I~
			return rc;                                          //~v020M~
        }                                                          //~v154I~
        if (pfh->UFHupctr)                                      //~v04jR~
        {                                                          //~v0fqI~
		  	if (UCBITCHK(pfc->UFCflag,UFCFENQSELNEW))	//new file by select cmd//~v0fqI~
				dlcmdeditenq3(pfc);	//enq pdh                      //~v0fqR~
            UCBITON(pfc->UFCflag,UFCFENDSAVE);  //tell todlcmddeqpfc//~v04jR~
            dlcmdseteditlc(pfc);    //set lineno to dirlist line   //~v10rI~
        }                                                          //~v0fqI~
//        else                                                     //~v10kR~
//            if (UCBITCHK(pfh->UFHflag,UFHFNEW))                  //~v10kR~
//                UCBITON(pfc->UFCflag,UFCFCANNEWF);  //tell to dcmddeqpfc//~v10kR~
    }                                                           //~v020M~
	inisavelastfile(pfc);                                          //~v11zI~
	fileclosefree(pfc);                                         //~v020M~
    csrsetwait(0);                                                 //~v154I~
	if (!filepopup(Ppcw))	//no stacked client                 //~v020M~
		return -1;			//quit                              //~v020M~
	return rc;                                                  //~v020M~
}//func_end_file                                                //~v020M~
                                                                //~v020M~
//****************************************************************//~v020M~
// func_cancel_file                                             //~v020M~
//*cancel command                                               //~v020M~
//*rc   :0                                                      //~v020M~
//****************************************************************//~v020M~
int func_cancel_file(PUCLIENTWE Ppcw)                           //~v020M~
{                                                               //~v020M~
	PUFILEC pfc;                                                //~v020M~
	PUFILEH pfh;                                                //~v020M~
//***************                                               //~v020M~
	if (UCBITCHK(Ppcw->UCWflag3,UCWF3EXECMD))	//execmd owner     //~v77LI~
    	return funcerrexecmdinprog();                              //~v77LI~
	pfc=Ppcw->UCWpfc;                                           //~v020M~
	pfh=pfc->UFCpfh;                                            //~v020M~
	if (!UCBITCHK(pfc->UFCflag,UFCFBROWSE)	//not browse mode   //~v020M~
	&&  pfh->UFHupctr!=pfh->UFHupctrsave)	//update after saved//~v020M~
	{                                                           //~v020M~
//*confirm pfk-cancel,no confirm "CANCEL" cmd line input or quit//~v020M~
		if (Ppcw->UCWkeytype!=UCWKTCMD	//func key not cmdline input//~v020M~
		&&  ((FUNCTBL*)Ppcw->UCWpfunct)->FTfuncid==FUNCID_CANCEL)//not QUIT//~v020M~
			if (!scrconfirmchk(GSCRCONFCANCEL))	//not yet confirmed//~v020M~
			{                                                   //~v020M~
				uerrmsg("Update discard confirmation,Same Key to discard,Esc to reset",//~v020M~
					"変更破棄の確認,破棄する時は再入力,Escで取消");//~v020M~
			  	if (!pfh->UFHupctr)   //back to the status at first load time//~va36I~
					uerrmsgcat(" (Wholly Undone, but Once Saved)", //~va36I~
								" (全変更が戻されたが一度保存が実行されている)");//~va36I~
				return 1;                                       //~v020M~
			}                                                   //~v020M~
		if (!UCBITCHK(Gprocstatus,GPROCSTERM))//not CB at termination//~v020M~
			uerrmsg("%s,Update was discarded",                  //~v020M~
					"%s の変更は破棄されました",pfh->UFHfilename);//~v020M~
	}//edit und updated                                         //~v020M~
//    if (UCBITCHK(pfh->UFHflag,UFHFNEW))                          //~v10kR~
//        UCBITON(pfc->UFCflag,UFCFCANNEWF);  //tell to dcmddeqpfc //~v10kR~
	if (UCBITCHK(pfc->UFCflag,UFCFENQSELNEW))//new file by select cmd//~v10kR~
    	if (!UCBITCHK(pfh->UFHflag,UFHFNEW)) //not new now(once saved)//~v10kR~
        {                                                          //~v10kI~
			dlcmdeditenq3(pfc);	//enq pdh                          //~v10kI~
            UCBITON(pfc->UFCflag,UFCFENDSAVE);  //tell to dlcmddeqpfc,reset data//~v10kI~
            dlcmdseteditlc(pfc);    //set lineno to dirlist line   //~v10rI~
        }                                                          //~v10kI~
	inisavelastfile(pfc);                                          //~v11zI~
    csrsetwait(1);                                                 //~v154I~
	fileclosefree(pfc);			//free lineh/undoh              //~v020M~
    csrsetwait(0);                                                 //~v154I~
	if (!filepopup(Ppcw))	//no stacked client                 //~v020M~
		return -1;			//quit                              //~v020M~
	return 0;                                                   //~v020M~
}//func_cancel_file                                             //~v020M~
                                                                //~v020M~
//****************************************************************
// srchlinenow
//*search line data by lineno at write(to merge compile err msg)
//*parm1 :file hdr ptr
//*parm2 :line no
//*return:line hdr ptr
//****************************************************************
//ULINEH *srchlinenow(UFILEH *Ppfh,LONG Plineno)                   //~v074R~
//{                                                                //~v074R~
//	LONG  lineno;                                                  //~v074R~
//	PUQUEH qh;                                                     //~v074R~
//	PULINEH plh;                                                   //~v074R~
//*********************************
//	qh=&(Ppfh->UFHlineque);                                        //~v074R~
//	if (UGETQCTR(qh)<Plineno)                                      //~v074R~
//		return 0;                                                  //~v074R~
//	plh=(PULINEH)UGETQCUR(qh);                                     //~v074R~
//	while(plh)                                                     //~v074R~
//	{                                                              //~v074R~
//		if ((lineno=plh->ULHlinenow)==Plineno)                     //~v074R~
//			return plh;                                            //~v074R~
//		if (lineno<Plineno)                                        //~v074R~
//			plh=UGETQNEXT(plh);                                    //~v074R~
//		else                                                       //~v074R~
//			plh=UGETQPREV(plh);                                    //~v074R~
//	}                                                              //~v074R~
//	return 0;                                                      //~v074R~
//}//srchlinenow                                                   //~v074R~
                                                                   //~v074I~
//***********************************************************
// filealloclh
//*allocate ULINEH and data buff
//*parm1:line type
//*parm2:data length
//*retrn:ULINEH addr or 0 if storage shortage                   //~v04dR~
//***********************************************************
PULINEH filealloclh(UCHAR Ptype,int Pdatalen)
{
	PULINEH plh;
	int bufflen;
//***************	
	plh=UALLOCC(1,ULINEHSZ);                                    //~v04dR~
	UALLOCCHK(plh,0);                                           //~v04dI~
	memcpy(plh->ULHcbid,ULHCBID,4);                             //~5105I~
	plh->ULHtype=Ptype;				//line type
	plh->ULHlen=Pdatalen;
	if (!Pdatalen)
		Pdatalen=16;		//minimum line width                //~5103R~
	bufflen=plh->ULHbufflen=uallocsz((UINT)Pdatalen);           //~5103R~
	plh->ULHdata=UALLOCM((UINT)bufflen);                        //~v04dR~
	if (!plh->ULHdata)	//storage shortage                      //~v04dI~
    {                                                           //~v04dI~
    	ufree(plh);                                             //~v04dI~
        return 0;	                                            //~v04dI~
    }                                                           //~v04dI~
	return plh;
}//filealloclh                                                  //~v04dR~
//*******************************************************
//*file line buff expand and copy data
//* parm1: PULINEH
//* parm2: new bufflen
//* return:0:no expand 1:expanded UALLOC_FAILED:storage shortage//~v04dR~
//*******************************************************
int  fileexpandbuff(PULINEH Pplh,int Plen)                      //~v04dR~
{
	int bufflen;
	UCHAR *pc;
//**************
	bufflen=uallocsz((UINT)Plen);
	if (Pplh->ULHbufflen>=bufflen)
		return 0;						//no need to reduce len //~v04dR~
#if defined(DOS) || defined(W32)                                   //~v085R~
    if (!UCBITCHK(Gopt3,GOPT3DOSPRECIZEMA))//safe mode for dos	//~5507I~
	    if (bufflen<80)                                         //~5507R~
   	    	bufflen=80;                                         //~5507R~
	    else                                                    //~5507R~
    	    bufflen=(((bufflen>>5)+1)<<5);	//next 32 byte boundary//~5507R~
#else                                                           //~5507I~
#endif                                                          //~5507I~
	pc=UALLOCM((UINT)bufflen);				//new buff          //~v04dR~
    UALLOCCHK(pc,UALLOC_FAILED);                                //~v04dI~
	if (Pplh->ULHdata)
	{
		memcpy(pc,Pplh->ULHdata,(UINT)Pplh->ULHlen);
		ufree(Pplh->ULHdata);
	}
	Pplh->ULHdata=pc;				//new buff
	if (Pplh->ULHdbcs)				//dbcs data
	{
		pc=UALLOCC(1,(UINT)bufflen);	//new dbcs tbl buff     //~v04dR~
	    UALLOCCHK(pc,UALLOC_FAILED);                            //~v04dI~
		memcpy(pc,Pplh->ULHdbcs,(UINT)Pplh->ULHlen);
		ufree(Pplh->ULHdbcs);
		Pplh->ULHdbcs=pc;				//new addr
	}	
	Pplh->ULHbufflen=bufflen;                                   //~v04dM~
	return 1;                                                   //~v04dR~
}//fileexpandbuff
                                                                //~5118I~
//****************************************************************
// filefreeplh
//*free line entry
//*parm1:PULINEH
//*parm2:option to free entry   1:free entry 0,free data only
//*void
//****************************************************************
void filefreeplh(PULINEH Pplh,int Popt)
{
	if (Pplh->ULHdbcs)
	{
		ufree(Pplh->ULHdbcs);
		Pplh->ULHdbcs=0;
	}
	if (Pplh->ULHdata)
	{
		ufree(Pplh->ULHdata);
		Pplh->ULHdata=0;
	}
    UFREECLEARIFNZ(Pplh->ULHci);                                   //~v780R~
	if (Popt)
    {                                                              //~vbi3I~
    	UTRACEP("%s:FREEplh=%p\n",UTT,Pplh);                       //~vbi3R~
		ufree(Pplh);
    }                                                              //~vbi3I~
}//filefreeplh

//*******************************************************       //~5223I~
//*reset find ctr of all file(by tab ctr change)                //~5223I~
//*parm  :none                                                  //~5223I~
//*return:none                                                  //~5223I~
//*******************************************************       //~5223I~
void fileresetfindctr(void)                                     //~5223I~
{                                                               //~5223I~
	PUFILEH pfh;                                                //~5223I~
//***************************                                   //~5223I~
	pfh=UGETQTOP(&Sfileq);                                      //~5223R~
	while(pfh)                                                  //~5223I~
    {                                                           //~5223I~
    	pfh->UFHfindctr++;                                      //~5223R~
        pfh=UGETQNEXT(pfh);                                     //~5223I~
	}                                                           //~5223I~
	return;                                                     //~5223I~
}//fileresetfindctr                                             //~5223I~
//*******************************************************          //~v60jI~
//*reset tabexpansion by tabctr change                             //~v60jI~
//*******************************************************          //~v60jI~
//int fileresettabctr(void)                                        //~v8@2R~
int fileresettabctr(int Popt,PUFILEH Ppfh,int Ptabctr)             //~v8@2I~
{                                                                  //~v60jI~
	PUFILEH pfh;                                                   //~v60jI~
	PULINEH plh;                                                   //~v60jI~
    int rc;                                                        //~v78cI~
    int tabskip,changesw;                                          //~v8@2I~
//***************************                                      //~v60jI~
  if (Ppfh)                                                        //~v8@2I~
  	pfh=Ppfh;                                                      //~v8@2I~
  else       //default change                                      //~v8@2I~
	pfh=UGETQTOP(&Sfileq);                                         //~v60jI~
	while(pfh)                                                     //~v60jI~
    {                                                              //~v60jI~
    	if (Ppfh) //this file changed                              //~v8@2I~
        {                                                          //~v8@2I~
        	if (Ptabctr)	//new ctr specified                    //~v8@2R~
            {                                                      //~v8@2I~
            	pfh->UFHprofile|=FPURO_TABCTR;                     //~v8@2I~
            	changesw=(pfh->UFHtabskip!=Ptabctr);               //~v8@2I~
            	tabskip=Ptabctr;                                   //~v78TR~
            	pfh->UFHtabskip=(UCHAR)tabskip;                    //~v78TI~
            }                                                      //~v8@2I~
            else                                                   //~v8@2I~
            {                                                      //~v8@2I~
//          	pfh->UFHprofile&=~FPURO_TABCTR; //default use      //~v8@2I~//~vb2eR~
            	pfh->UFHprofile&=(ULONG)(~FPURO_TABCTR); //default use//~vb2eI~
            	tabskip=max(Gfiletabskip,1); //default value       //~v8@2I~
            	changesw=(pfh->UFHtabskip!=tabskip);               //~v8@2I~
            	pfh->UFHtabskip=(UCHAR)tabskip;                    //~v78TR~
            }                                                      //~v8@2I~
        }                                                          //~v8@2I~
        else                                                       //~v8@2I~
        {                                                          //~v8@2I~
            if (pfh->UFHprofile & FPURO_TABCTR) //profile specified//~v8@2I~
            	changesw=-1;	//no effect of default             //~v8@2I~
            else                                                   //~v8@2I~
            {                                                      //~v8@2I~
            	tabskip=max(Gfiletabskip,1); //default value       //~v8@2I~
            	changesw=(pfh->UFHtabskip!=tabskip);               //~v8@2I~
            	pfh->UFHtabskip=(UCHAR)tabskip;                    //~v78TR~
            }                                                      //~v8@2I~
        }                                                          //~v8@2I~
      if (changesw>0) //tabctr changed  	                       //~v8@2I~
        for (plh=UGETQTOP(&pfh->UFHlineque);plh;plh=UGETQNEXT(plh))//~v60jI~
        {                                                          //~v60jI~
            if (plh->ULHtype!=ULHTDATA) //not file data            //~v60jI~
                continue;                                          //~v60jI~
            if (!plh->ULHdbcs) //not yet expanded                  //~v60jI~
                continue;                                          //~v60jI~
//          if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v78cR~
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len//~v78cI~
    	        return UALLOC_FAILED;                              //~v60jI~
            if (!rc)	//tab expanded                             //~v78cI~
            {                                                      //~v78cI~
        		SYN_INVALIDATE_PLH(plh);                           //~v78cI~
			    SYN_INVALIDATE_PFH(pfh);                           //~v78cI~
            }                                                      //~v78cI~
        }//all plh                                                 //~v60jI~
  		if (Ppfh) //this file change                               //~v8@2I~
        	break;                                                 //~v8@2I~
        pfh=UGETQNEXT(pfh);                                        //~v60jI~
	}                                                              //~v60jI~
	return 0;                                                      //~v60jR~
}//fileresettabctr                                                 //~v60jI~
//*******************************************************          //~v440I~
//*hexmode but already opened by textmode                          //~v440I~
//*parm  :lineno                                                   //~v440I~
//*return:none                                                     //~v440I~
//*******************************************************          //~v440I~
int fileerrmixmode(char *Pfnm)                                     //~v440R~
{                                                                  //~v440I~
//***************************                                      //~v440I~
	uerrmsg("%s is already opened by another text/bin/hex mode",   //~v440R~
    		"%s は別のテキスト/バイナりー/Hex モードでオープン中",Pfnm);//~v440R~
    return 4;                                                      //~v440I~
}//fileerrmixmode                                                  //~v440R~
//**************************************************************** //~vbi3I~
// filebrowsefilechl                                               //~vbi3I~
//*cmd history list                                                //~vbi3I~
//*parm1:file name                                                 //~vbi3I~
//*rc   :0-ok 4:file load err                                      //~vbi3I~
//**************************************************************** //~vbi3I~
int filebrowsechl(int Popt,PUCLIENTWE Ppcw)                        //~vbi3R~
{                                                                  //~vbi3I~
	int rc;                                                        //~vbi3I~
	UFILEH *pfh;                                                   //+vbi3R~
    PUCLIENTWE pcw,pcwold=0;                                       //~vbi3R~
	UCHAR  fpath[_MAX_PATH];                                       //~vbi3I~
	UCHAR  *pfname=CHL_FNM;                                        //~vbi3R~
    int optchl;                                                    //~vbi3I~
    int splitid;                                                   //~vbi3I~
//*********************************                                //~vbi3I~
	splitid=Ppcw->UCWsplitid;                                      //~vbi3I~
    if (splitid)                                                   //~vbi3I~
        pfname=CHL_FNM "2";                                        //~vbi3R~
    else                                                           //~vbi3I~
        pfname=CHL_FNM "1";                                        //~vbi3R~
    filefullpath(fpath,pfname,sizeof(fpath));                      //~vbi3R~
	pcwold=scrsrchcwchl(0,splitid);                                //~vbi3R~
    optchl=Popt;                                                   //~vbi3I~
    rc=fileloadchl(optchl,Ppcw,pfname,fpath,&pfh);                 //~vbi3R~
	if (rc)                                                        //~vbi3I~
		return 4;                                                  //~vbi3I~
    pcw=fileregist(Ppcw,PANFBROWSE,pfh,0/*editsw*/);               //~vbi3R~
    if (!pcw)       //storage shortage                             //~vbi3R~
    {                                                              //~vbi3R~
    	fileclosefree2(pfh);    //close and free pfh               //~vbi3R~
        return UALLOC_FAILED;                                      //~vbi3R~
    }                                                              //~vbi3M~
	pcw->UCWlinenosz=1;   //splitter only                          //~vbi3R~
    if (pcwold)                                                    //~vbi3I~
    {                                                              //~vbi3I~
    	scrpopup(pcwold,0);	//move to top to free top              //~vbi3I~
        func_cancel_file(pcwold);                                  //~vbi3I~
    }                                                              //~vbi3I~
	return 0;                                                      //~vbi3I~
}//func_browse_file                                                //~vbi3I~
//**************************************************************** //~vbi3M~
//* cmdhistory CPLC                                                //~vbi3M~
//**************************************************************** //~vbi3M~
int func_cmdhistlc(PUCLIENTWE Ppcw)                                //~vbi3M~
{                                                                  //~vbi3M~
	return filebrowsechl(0,Ppcw);                                  //~vbi3M~
}//func_cmdhistlc                                                  //~vbi3M~
//**************************************************************** //~vbi3M~
//* cmdhistory CPU8                                                //~vbi3M~
//**************************************************************** //~vbi3M~
int func_cmdhistu8(PUCLIENTWE Ppcw)                                //~vbi3M~
{                                                                  //~vbi3M~
	return filebrowsechl(CHLO_UTF8,Ppcw);                          //~vbi3M~
}//func_cmdhistu8                                                  //~vbi3M~
