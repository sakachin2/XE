//*CID://+vbBuR~:                             update#=  456;       //~vbBuR~
//*************************************************************
//*xefile14.c*                                                     //~v54dR~
//* fileload ,filefindopen/filegetline                             //~v54dR~
//*************************************************************
//vbBu:241119 Edit/Browse /Mz option for ebc file to accept 0x0d15 as EOL//~vbBuI~
//vbya:230420 (ARM)open doc optionally. limit to load/save now.    //~vbyaI~
//vby8:230415 (ARM)open document file                              //~vby8I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb2e:160122 (LNX)convert filename according IOCHARSET mount option//~vb2eI~
//vazt:150114 (BUG)"UCHAR UFHpathlen" is invalid when _MAX_PATH>256//~vaztI~
//vazr:150114 for also bin file after 1st read,use seek after header line read//~vazrI~
//vazd:150111 confirm large file open                              //~vazdI~
//vaz1:150106 use fseek to positioning of start offset for local binfile to performance up//~vaz1I~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vav3:140402 (BUG)fstat was not initialized when findfile rc=16/(dir) or 20(wild card), then used at filesetfstat.//~vav3I~
//            So,UNC case display invalid timestamp when wildcard root(\\server\share\*).//~vav3I~
//vane:131208 clear crypt pswd for inserted line to avoid copy line(But,effective only for update)//~vaneI~
//vanc:131203 (BUG)Vfmt=mfh header cont line ignored by /Mnn parm  //~vancI~
//vanb:131202 (BUG)Vfmt=mfh read err after update(not mfrecord type(System, record) was not set)//~vanbI~
//van7:131130 (BUG)record mode lineno default should not be hex offset but lineno.//~van7I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|F|H})         //~vaj0I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va6N:100721 add eol whe /mET                                     //~va6NI~
//va6M:100721 no eol msg for optbin binchk                         //~va6MI~
//va6L:100721 (BUG)No need of msg "UNIX file" when /mu was specified//~va6LI~
//va6K:100721 (BUG)No eol changed msg for max file                 //~va6KI~
//va6D:100719 EBC eol 0x15 support                                 //~va6DR~
//va6A:100719 ebc bin determination err                            //~va6AI~//~va6DR~
//va6k:100622 COPY cmd considers priofile RECORD mode              //~va6kI~//~va6DR~
//va5S:100526 Force Tabctr=1 at load time for record mode to avoid expanded by tab over lrecl//~va5SI~
//va5e:100510 drop eol by /mpr                                     //~va5eI~
//va51:100415 Record mode file option                              //~va51I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va1N:091122 (UTF8)CPU8 trans err reloading is option by UTF8 cmd //~va1NI~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1q:091107 compchkm                                             //~va1qI~
//va1e:091101_(UTF8) retry by lc for f2l err at load if no CPU8 option specified//~va1eI~
//va0C:090721_set wxp work CPxx to the same as source file         //~va0CI~
//va0v:090915!binfile chk for CPU8                                 //~va0vR~
//va0k:090809 (BUG)hdr line timestamp is 80-00-00 for wildcard     //~va0kI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//          consider utf8 char boundary for long line split        //~va00I~
//          set encoding id on header line                         //~va00I~
//          save CPxx to profile                                   //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00I~
//          ignore translation err for utility result file(parm to edit_file2)//~va00I~
//v79v:080909 ASCII mode display on "this is binary file" msg      //~v79vI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v78o:080322 (SYN:BUG)reverse is not able to distingush on browse screen//~v78oI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v731:061226 filesize>4GB support                                 //~v731I~
//v72z:061203 3270:missing free pfh when dsname error              //~v72zI~
//v72b:061121 3270:reject new dataset edit                         //~v72bI~
//v720:061116 3270:listds fail by 'sys1.*' because sys1.duplex has no dsorg recfm//~v720I~
//            trate as special file for SYS1.VMASTCAT(VSAM) etc    //~v720I~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl                       //~v71HI~
//v71k:061017 (BUG)xehosts file finename chk miss("::\xehosts" is not detected as ::xehosts)//~v71kI~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v59x:041114 (BUG)remote file default eol should be 0a(UNIX mode) //~v59xI~
//v594:041103 display ascii option for eh cmd                      //~v594I~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v55P:040318 (UNX)update permission warning                       //~v55PI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54cI~
//v54d:040103 split xefile.c to xefile.c xefile14.c                //~v54dI~
//v54c:040102 support tail option for edit numrange (nnt-mmt)      //~v54cI~
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
#include <uedit2.h>                                                //~vbi3I~
#include <ustring.h>                                               //~v53UI~
#ifdef FTPSUPP                                                     //~v540I~
	#include <uftp.h>                                              //~v540R~
	#include <u3270.h>                                             //~v72bI~
#endif                                                             //~v540I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <ucvext.h>                                            //~va00R~
	#include <utf.h>                                               //~va00I~
#endif                                                             //~va00I~
#include <utrace.h>                                                //~va51I~
#include <ufemsg.h>                                                //~vazdI~
#ifdef ARMXXE                                                      //~vby8I~
	#include <ufiledoc.h>                                          //~vby8I~
#endif                                                             //~vby8I~
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
#include "xefile7.h"                                               //~v0imI~
#include "xefile12.h"                                              //~v0baR~
#include "xefile13.h"                                              //~v0d5I~
#include "xefunc.h"                                             //~5118I~
#include "xefunc2.h"                                               //~vbi3I~
#include "xeundo.h"
#include "xepan.h"                                              //~5318I~
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
#include "xefcmd.h"                                                //~vaj0I~
#include "xefcmd2.h"                                               //~v43hI~
#include "xefcmd23.h"                                              //~v74EI~
#ifdef FTPSUPP                                                     //~v53UI~
	#include "xeftp.h"                                             //~v53UI~
	#include "xetso.h"                                           //~v70zI~
#endif                                                             //~v53UI~
#include "xesyn.h"                                                 //~v780I~
#ifdef UTF8SUPPH                                                   //~v914I~//~va00R~
#include "xefile6.h"                                               //~va00I~
#include "xeopt.h"                                                 //~v914I~//~va00I~
#include "xeutf.h"                                                 //~va1EI~
#endif                                                             //~v914I~//~va00I~
#include "xeebc.h"                                                 //~va51I~
#ifdef W32UNICODE                                                  //~vbi3I~
	#include "xefsubw.h"                                           //~vbi3I~
#endif                                                             //~vbi3I~
//*******************************************************
//#define MAXLINEDATA2 (MAXLINEDATA-99)	//split line cut size      //~v0e2R~
#define MAXLINEDATA2 MAXLINEDATA	//same as max                  //~v0e2I~
//*******************************************************          //~v0bdI~
//**********************************
//int fileload(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,UCHAR Ppopt,PUFILEH *Pppfh);//~v54dR~
//int filegetadirmember(PUFILEH Ppfh,char *Pfullpath);             //~v40uR~
void filesplitmsg(long Plineno);                                   //~v41qR~
int filetailposproc(PUCLIENTWE Ppcw,PUFILEH Ppfh);                 //~v54cI~
void fileopeninit(void);                                           //~v54cI~
int seektostartpos(int Popt,PUFILEH Ppfh,FILESZT Pxranges);        //~vaz1I~
#define STSPO_READBIN    0x01                                      //~vazrI~
int chklargefile(PUFILEH Ppfh);                                    //~vazdR~
//**********************************
static int Ssplitsw=0;			//fileget line overflow            //~v42yR~
static int Ssplitswb;			//for OPTBIN case,1st line overflowed sw//~v108I~
//static int Scmdopt=0;           //by /mx option to chk bin and text open//~v54dR~
static char Ssplit1stsw=0;		//first time split sw for msg      //~v42yR~
static char Seolid=0;         	//to chk pc/unix flat file         //~v42yR~
//static char Sdireditsw;         //for fileload,from edit or browse//~v54dR~
//static char Seditsosw;          //parm to fileregist             //~v54dR~
//static char Sfkinisw;           //parm to fileload(func key file)//~v54dR~
//static char Sbinsw;             //force binary mode              //~v54dR~
//static UINT Slinewidth;         //file display width             //~vaz1R~
static int Slinewidth;         //file display width                //~vaz1R~
//static ULONG Slineoffs;         //line offset for binary file    //~vaz0R~
static FILESZT Slineoffs;         //line offset for binary file    //~vaz0I~
//static ULONG Sgetchkoffs;       //parm to filegetline            //~vaz0R~
static FILESZT Sgetchkoffs;       //parm to filegetline            //~vaz0I~
//static char Samembfullpath[_MAX_PATH];                           //~v40uR~
static int Scopysrclrecl;                                          //~va6kI~
//**************************************************************** //~vaj0I~
int setufgetsoptVparm(PUFILEH Ppfh)                                //~vaj0R~
{                                                                  //~vaj0I~
	int binopt=0;                                                  //~vaj0I~
//********************                                             //~vaj0I~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                        //~vaj0I~
    {                                                              //~vaj0I~
    	binopt|=UFGETS_RV;	//record mode,split by LRECL           //~vaj0I~
	    binopt|=(Ppfh->UFHvfmt<<UFGETS_VFMTSHIFT);                 //~vaj0R~
    	binopt|=UFGETS_RVTYPE;	//output record type to eolid      //~vanbI~
    }                                                              //~vaj0I~
    UTRACEP("setufgetsoptVparm rc=%x\n",binopt);                   //~vaj0I~
    return binopt;                                                 //~vaj0I~
}//setufgetsoptVparm                                               //~vaj0I~
//**************************************************************** //~vaj0I~
int setufgetsoptVparm2(int Pvfmt)                                  //~vaj0I~
{                                                                  //~vaj0I~
	int binopt=0;                                                  //~vaj0I~
//********************                                             //~vaj0I~
    binopt|=UFGETS_RV;	//record mode,split by LRECL               //~vaj0I~
	binopt|=(Pvfmt<<UFGETS_VFMTSHIFT);                             //~vaj0I~
    UTRACEP("setufgetsoptVparm2 rc=%x\n",binopt);                  //~vaj0I~
    return binopt;                                                 //~vaj0I~
}//setufgetsoptVparm                                               //~vaj0I~
//****************************************************************
// fileload
//*read file and create file hdr(enq line data)
//*parm1:pcw                                                    //~v020R~
//*parm2:file name                                              //~v020I~
//*parm3:fullpath file name                                     //~v020R~
//*parm4:open option                                            //~v020R~
//*parm5:ptr to file hdr                                        //~v020R~
//*rc   :0-ok 4:file load err or UALLOC_FAILED                  //~v04dR~
//****************************************************************
//int fileload(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,UCHAR Ppopt,PUFILEH *Pppfh)//~v54dR~
int fileload(PUCLIENTWE Ppcw,UCHAR *Ppfile,UCHAR *Pfullpath,UCHAR Ppopt,PUFILEH *Pppfh,//~v54dI~
//  		char Pbinsw,char Peditsosw,char Pfkinisw)              //~v75HR~
//  		int  Pbinsw,char Peditsosw,char Pfkinisw)              //~v76mR~
    		int  Pbinsw,char Peditsosw,int Pfkinisw)               //~v76mI~
{
	int  	rc;                                                 //~v03yR~
	LONG 	lineno;
	PUFILEH pfh;
	ULINEH 	*plh;
	PULINEH *pplh;                                                 //~v08lI~
	UCHAR 	*pc;                                                //~v03yR~
	FILEFINDBUF3 fstat3;     				//output from DosFindxxxx
	FILE *hfile;
//static char Sfhdrline[]="********** TOP OF FILE *******";        //~v08lR~
static char Sfhdrline[]=  "********** TOP OF FILE ";               //~v08lI~
//static char Sftrlline[]="********** END OF FILE *******";	       //~v08lR~
static char Sftrlline[]=  "********** END OF FILE ";               //~v08lI~
static char Stlineno []="*******|";
	char rangeedit[32];                                            //~v08lI~
    long sline,eline;                                              //~v08lI~
    int readbinsw;                                                 //~v09YI~
    int openmode=0;                                                //~v70zI~
    int lnosuffix;                                                 //~v0adI~
    int spfpos=0;                                                  //~v0clR~
    int spfvermax=0;                                               //~v0clR~
    int spferr=0;                                                  //~v0clR~
    int splitmsgsw=0;                                              //~v41qR~
    int binopt;                                                    //~v107R~
    int optbinwidth;                                               //~v10NI~
    int xrangesw;                                                  //~v10YR~
//  ULONG xranges,xrangee,xrangelast;                              //~vaz0R~
    FILESZT xranges,xrangee,xrangelast;                            //~vaz0I~
    int eolchng;                                                   //~v47LI~
#ifdef UNX                                                         //~v48cI~
    UCHAR  mdosalias[UFHALIASSZ];                                  //~v48cR~
#endif                                                             //~v48cI~
#ifdef FTPSUPP                                                     //~v53UI~
	char fpathhosts[_MAX_PATH];                                    //~v53UI~
	char ftplocalfnm[_MAX_PATH];//local name of remote file        //~v576I~
    int hostsfsw;                                                  //~v53UI~
  #ifndef UNX                                                      //~v59xI~
    int remotesw;                                                  //~v59xI~
  #endif                                                           //~v59xI~
#endif                                                             //~v53UI~
    int opt2;                                                      //~v76mI~
#ifdef UTF8SUPPH                                                   //~va00I~
    int opt3=0;                                                    //~va0vR~
#endif                                                             //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va51I~
    int swebcfile;                                                 //~va51I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va51I~
    int sweolchngmsg=0;                                            //~va6DI~
    int opt4;                                                      //~vaa0I~
    int rc_seek=0;                                                 //~vaz1I~
    int rc2;                                                       //~vb7eI~
//****************************
    UTRACEP("%s:entry Ppfile=%s\n",UTT,Ppfile);                    //~vbi3I~
    opt2=Pfkinisw & FLO2_OPT2;                                     //~v76mI~
    Pfkinisw &= FLO2_FKINI;                                        //~v76mI~
	*Pppfh=pfh=UALLOCC(1,UFILEHSZ);                             //~v04dR~
    UALLOCCHK(pfh,UALLOC_FAILED);                               //~v04dI~
	memcpy(pfh->UFHcbid,UFHCBID,4);		//acronym               //~5105I~
	pfh->UFHopenctr=1;		//open ctr
	UCBITON(pfh->UFHflag,UFHFUPCTRREQ|UFHFUNDOCTRREQ);//next time updatectr up
#ifdef LNX                                                         //~vb2eI~
	if (opt2 & FEBFIO_MOUNTU8)	//ignore utf8 trans err            //~vb2eI~
    {                                                              //~vb2eI~
    	UCBITON(pfh->UFHflag14,UFHF14MOUNTU8);   //if UFHF12FNCMD,FEBFIO_MOUNTU8 is off at filesrchpfh2//~vb2eI~
    	UCBITON(pfh->UFHflag12,UFHF12FNU8);                        //~vb2eI~
    	UCBITOFF(pfh->UFHflag12,UFHF12FNLC);                       //~vb2eI~
        if (opt2 & FEBFIO_MOUNTU8CV)                               //~vb2eI~
    		UCBITON(pfh->UFHflag14,UFHF14MOUNTU8CV);               //~vb2eR~
    }                                                              //~vb2eI~
#endif                                                             //~vb2eI~
  rc2=                                                             //~vb7eI~
    ufilesetfhfilename(pfh,Pfullpath);                             //~v542R~
    if (rc2)                                                       //~vb7eI~
        return 4;                                                  //~vb7eI~
    if (!LFNM_STRCMP(Ppfile,CUTCMD_2NDCBFNM))                      //~vaj0R~
		fileadjustfh4cut(FACO_OPEN,Ppcw,pfh,0/*saveopt*/);         //~vaj0R~
#define FACO_OPEN    0x01	//from f14                             //~vaj0I~
//  if (rc=fileoptionchk(Ppcw,pfh),rc) //lineno opd etc            //~v10DR~
//  if (rc=fileoptionchk(Ppcw,pfh,Ppopt,Sbinsw),rc) //lineno opd etc,pass UFCFBROWSE//~v54dR~
#ifdef UTF8SUPPH                                                   //~va0vR~
    if (Peditsosw)                                                 //~va0vI~
    	opt3=BESOPT_LOCALE;			//assume force CPAS            //~va0vI~
    if (Pfkinisw)                   //filefk (=0.x panel)          //~va0vI~
    	opt3=BESOPT_CPLC;  			//force CPLC                   //~va0vI~
	if (opt2 & FEBFIO_UTF8IE)	//ignore utf8 trans err            //~va0vI~
    	opt3|=BESOPT_IE;			//force IE                         //~va0vI~//~va0CR~
	if (opt2 & FEBFIO_CPU8)	//force CPU8                           //~va0CI~
    	opt3|=BESOPT_CPU8;   	//force CPU8                       //~va0CR~
	if (opt2 & FEBFIO_CPLC)	//force CPLC                           //~va0CI~
    	opt3|=BESOPT_CPLC;   	//force CPLC                       //~va0CR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (opt2 & FEBFIO_CPEB)	//force CPLC                           //~va50I~
    	opt3|=BESOPT_CPEB;   	//force CPLC                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (rc=fileoptionchk(Ppcw,pfh,Ppopt,Pbinsw|opt3),rc) //lineno opd etc,pass UFCFBROWSE//~va0vR~
#else                                                              //~va00I~
    if (rc=fileoptionchk(Ppcw,pfh,Ppopt,Pbinsw),rc) //lineno opd etc,pass UFCFBROWSE//~v54dI~
#endif                                                             //~va00I~
    {                                                              //~v09YI~
//  	fileclosefree2(pfh);	//close and free pfh               //~v54cR~
		ufree(pfh);                                                //~v54cI~
        return rc;                                                 //~v09YI~
    }                                                              //~v09YI~
#ifdef FTPSUPP                                                     //~v59xI~
  #ifndef UNX                                                      //~v59xI~
    remotesw=FILEISREMOTE(pfh);                                    //~v59xI~
  #endif                                                           //~v59xI~
#endif                                                             //~v59xI~
    readbinsw=(UCBITCHK(pfh->UFHflag3,UFHF3RBIN)!=0)*FILE_OPEN_BIN;//~v0abR~
    openmode=((UCBITCHK(pfh->UFHflag4,UFHF4BIN)|UCBITCHK(pfh->UFHflag5,UFHF5HEX))!=0)*FILE_BINHEXFILE;//~v70zR~
    memset(&fstat3,0,sizeof(fstat3));                              //~vav3R~
//  rc=filefindopen(Pfullpath,&fstat3,Ppopt,&hfile,FFMSG|FFNODIRMSG);//~v09YR~
//if (Sfkinisw)     //option key file                              //~v54dR~
//if (Pfkinisw)     //option key file                              //~v76mR~
  if (Pfkinisw      //option key file                              //~v76mI~
  ||  (opt2 & FEBFIO_TEMP2))	//temp file(should be NEW)         //~v76mI~
  {                                                                //~v0imI~
    rc=3;                                                          //~v0imI~
    hfile=0;                                                       //~v0imI~
  }	                                                               //~v0imI~
  else                                                             //~v0imI~
  {                                                                //~v576I~
#ifdef UNX                                                         //~v48cI~
//  rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw,&hfile,FFMSG|FFNODIRMSG,mdosalias);//~v576R~
    strcpy(ftplocalfnm,pfh->UFHftpwdfnm);	//input to filefindopen for remotefile//~v576I~
//  rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw,&hfile,FFMSG|FFNODIRMSG,mdosalias,ftplocalfnm);//~v70zR~
    rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw+openmode,&hfile,FFMSG|FFNODIRMSG,mdosalias,ftplocalfnm);//~v70zI~
#else                                                              //~v48cI~
  #ifdef FTPSUPP                                                   //~v576I~
    strcpy(ftplocalfnm,pfh->UFHftpwdfnm);	//input to filefindopen for remotefile//~v576I~
//  rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw,&hfile,FFMSG|FFNODIRMSG,ftplocalfnm);//~v70zR~
    rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw+openmode,&hfile,FFMSG|FFNODIRMSG,ftplocalfnm);//~v70zI~
  #else                                                            //~v576I~
//  rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw,&hfile,FFMSG|FFNODIRMSG);//~v70zR~
    rc=filefindopen(Pfullpath,&fstat3,Ppopt+readbinsw+openmode,&hfile,FFMSG|FFNODIRMSG);//~v70zI~
  #endif                                                           //~v576I~
#endif                                                             //~v48cI~
  }//! menu                                                        //~v576I~
	switch(rc)
	{
	case 0:
//#ifdef LFSSUPP                                                   //~v731R~
//        if (fstat3.cbFile>>32)  //over 4GB                       //~v731R~
//        {                                                        //~v731R~
//            uerrmsg("File is too large(>4GB)",                   //~v731R~
//                    "ファイルが大きすぎます(>4GB)");             //~v731R~
//            ufree(pfh);                                          //~v731R~
//            return 4;                                            //~v731R~
//        }                                                        //~v731R~
//#endif                                                           //~v731R~
		break;
	case 3:	//option key file                                      //~v0imI~
	case 1:	//new file(not found at edit mode)                  //~5128R~
#ifdef FTPSUPP                                                     //~v72bI~
		if (rc==1                                                  //~v72bI~
		&&  MEMBOFDSN(Pfullpath)==0                                //~v72bR~
		&&  u3270fullpathistso(Pfullpath)                          //~v72bI~
        )                                                          //~v72bI~
        {                                                          //~v72zI~
			ufree(pfh);                                            //~v72zI~
        	return 4;                                              //~v72bI~
        }                                                          //~v72zI~
#endif                                                             //~v72bI~
        if (rc==1                                                  //~vaj0I~
        &&  UCBITCHK(pfh->UFHflag13,UFHF13RV)                      //~vaj0I~
        &&  pfh->UFHvfmt==UFGETS_VFMT_MFH)                         //~vaj0I~
        {                                                          //~vaj0I~
            uerrmsg("New file could not be open with -F%s option", //~vaj0I~
                    "新規ファイルは -F%s オプションでは開けません",//~vaj0I~
                    VFMT_MFH);                                     //~vaj0I~
            ufree(pfh);                                            //~vaj0I~
        	return 4;                                              //~vaj0I~
        }                                                          //~vaj0I~
//    if (!Sfkinisw)     //option key file                         //~v54dR~
      if (!Pfkinisw)     //option key file                         //~v54dI~
      if  (!(opt2 & FEBFIO_TEMP2))                                 //~v76mI~
		uerrmsg("New File",                                     //~5128I~
					"新ファイル");                                 //~v10HR~
		UCBITON(pfh->UFHflag,UFHFNEW);
    	pfh->UFHsline=0;                                           //~v09YR~
    	pfh->UFHeline=0;                                           //~v09YR~
    	pfh->UFHslinepos=0;                                        //~v10YI~
    	pfh->UFHelinepos=0;                                        //~v10YI~
    	UCBITOFF(pfh->UFHflag4,UFHF4XRANGE);                       //~v10YI~
		break;
	case 2:	//directory                                         //~v020I~
        pfh->UFHtype=UFHTDIR;   //dir type pfh                  //~v020I~
//      if (!strpbrk(Pfullpath,"*?"))//not wild card            //~v030R~
//      	if (*(Pfullpath+strlen(Pfullpath)-1)=='\\')         //~v030R~
//          	strcat(Pfullpath,"*.*");                        //~v030R~
//          else                                                //~v030R~
//          	strcat(Pfullpath,"\\*.*");                      //~v030R~
		break;                                                  //~v020I~
	default:	//not found/open err
		ufree(pfh);
		return rc;
	}
//  strcpy(pfh->UFHfilename,Pfullpath);		//file name            //~v0fmR~
//  ufilesetfhfilename(pfh,Pfullpath);                             //~v542R~
//  strcpy(pfh->UFHfilename,strupr(pfh->UFHfilename));	//file name//~v03lR~
#ifdef UNX                                                         //~v20DI~
//  #ifdef LNX                                                     //~v48cR~
    	if (MDOSDISKOK(pfh->UFHfilename))                          //~v40AI~
        {                                                          //~v48cI~
			UCBITON(pfh->UFHflag5,UFHF5MDOS);//work dir file       //~v40AI~
			strncpy(pfh->UFHalias,mdosalias,UFHALIASSZ);           //~v48cR~
        }                                                          //~v48cI~
//  #endif                                                         //~v48cR~
	if (!strcmp(Ppfile,CLIPBOARDID)                                //~v20DI~
#else  //!UNX                                                      //~v20DI~
	if (!stricmp(Ppfile,CLIPBOARDID)                                  //~v06yR~
#endif //!UNX                                                      //~v20DI~
//  ||  Sfkinisw                                                   //~v54dR~
    ||  Pfkinisw                                                   //~v54dI~
//  ||	Seditsosw)                                                 //~v54dR~
    ||	Peditsosw)                                                 //~v54dI~
    {                                                           //~5224I~
		UCBITON(pfh->UFHflag,UFHFWORKDIRFILE);//work dir file   //~5224R~
//  	if (Seditsosw)                                             //~v54dR~
    	if (Peditsosw)                                             //~v54dI~
			pfh->UFHtype=UFHTSTDOUT;//clip board file                 //~v06yI~
        else                                                          //~v06yI~
//  	if (Sfkinisw)                                              //~v54dR~
		if (Pfkinisw)                                              //~v54dI~
			pfh->UFHtype=UFHTKFI;//clip board file                 //~v0ifI~
        else                                                       //~v0ifI~
		pfh->UFHtype=UFHTCLIPBOARD;//clip board file                  //~v06yR~
        strncpy(pfh->UFHalias,Ppfile,sizeof(pfh->UFHalias)-1);  //~5224I~
		pfh->UFHwidth=0;    //force line width=999                 //~v10FI~
    }                                                           //~5224I~
    else                                                           //~v76mI~
    if  (opt2 & FEBFIO_TEMP2)                                      //~v76mI~
    {                                                              //~v76mI~
		pfh->UFHtype=UFHTTEMPWK2;                                  //~v76mI~
		pfh->UFHwidth=0;    //force line width=999                 //~v76mI~
    }                                                              //~v76mI~
#ifdef FTPSUPP                                                     //~v53UI~
    else                                                           //~v53UI~
//  if (ustrstri(Ppfile,FTPHOSTS+2))                               //~v53UR~//~vaneR~
    {                                                              //~v53UI~
		hostsfsw=0;                                                //~v53UI~
#ifdef UNX                                                         //~v53UI~
		if (!strcmp(Ppfile,FTPHOSTS))                              //~v53UI~
#else  //!UNX                                                      //~v53UI~
		if (!stricmp(Ppfile,FTPHOSTS))                             //~v53UI~
#endif //!UNX                                                      //~v53UI~
			hostsfsw=1;                                            //~v53UI~
        else                                                       //~v53UI~
        {                                                          //~v53UI~
        	filefullpath(fpathhosts,FTPHOSTS,sizeof(fpathhosts));  //~v53UI~
#ifdef UNX                                                         //~v53UI~
//  		if (!strcmp(Ppfile,fpathhosts))                        //~v71kR~
    		if (!strcmp(Pfullpath,fpathhosts))                     //~v71kI~
#else  //!UNX                                                      //~v53UI~
//  		if (!stricmp(Ppfile,fpathhosts))                       //~v71kR~
    		if (!stricmp(Pfullpath,fpathhosts))                    //~v71kI~
#endif //!UNX                                                      //~v53UI~
				hostsfsw=1;                                        //~v53UI~
        }                                                          //~v53UI~
        if (hostsfsw)                                              //~v53UI~
        {                                                          //~v53UI~
			UCBITON(pfh->UFHflag,UFHFWORKDIRFILE);//work dir file  //~v53UI~
			pfh->UFHtype=UFHTHOSTS;//ftp hosts                     //~v53UI~
        	strncpy(pfh->UFHalias,FTPHOSTS,sizeof(pfh->UFHalias)-1);//~v53UI~
			pfh->UFHwidth=0;    //force line width=999             //~v53UI~
        }                                                          //~v53UI~
        else                                                       //~vaneI~
        {                                                          //~vaneI~
        	UTRACEP("%s:fullpath=%s,Gxehostsfnm=%s\n",UTT,Pfullpath,Gxehostsfnm);//~vaneI~//~vbi3R~
#ifdef UNX                                                         //~vaneM~
 			if (!strcmp(Pfullpath,Gxehostsfnm))                    //~vaneI~
#else  //!UNX                                                      //~vaneM~
    		if (!stricmp(Pfullpath,Gxehostsfnm))                   //~vaneI~
#endif //!UNX                                                      //~vaneM~
			{                                                      //~vaneI~
				pfh->UFHtype=UFHTHOSTS;//ftp hosts                 //~vaneI~
				pfh->UFHwidth=0;    //force line width=999         //~vaneI~
        	}                                                      //~vaneI~
        }                                                          //~vaneI~
    }                                                              //~v53UI~
#endif //FTPSUPP                                                   //~v53UI~
//path length and dir level                                     //~v03yI~
//  pfh->UFHpathlen=(UCHAR)getpathlen(pfh->UFHfilename,    //get path len//~vaa0R~
//								&pfh->UFHlevel,		//dir level    //~vaa0R~
//                            	(pfh->UFHtype==UFHTDIR));//dir sw  //~vaa0R~
	opt4=(pfh->UFHtype==UFHTDIR);//dir sw                          //~vaa0M~
#ifdef UNX                                                         //~vaa0M~
	if (!FILEISTSO(pfh))                                           //~vaa0M~
    	if (fstat3.attrFile & FILE_WILDNAME)                       //~vaa0I~
			opt4|=GPL_WILDNAME;                                    //~vaa0M~
#endif                                                             //~vaa0M~
//  pfh->UFHpathlen=(UCHAR)getpathlen(pfh->UFHfilename,    //get path len//~vaztR~
    pfh->UFHpathlen=getpathlen(pfh->UFHfilename,    //get path len //~vaztI~
  								&pfh->UFHlevel,		//dir level    //~vaa0I~
                              	opt4);//dir sw                     //~vaa0I~
//file attr                                                     //~v030R~
	if (!UCBITCHK(pfh->UFHflag,UFHFNEW))
	{
//        pfh->UFHsize    =fstat3.cbFile;         //file size      //~v542R~
//        pfh->UFHfiledate=fstat3.fdateLastWrite;//file date       //~v542R~
//        pfh->UFHfiletime=fstat3.ftimeLastWrite;//file time       //~v542R~
//#ifdef UNX                                                       //~v542R~
//        pfh->UFHattr    =      fstat3.attrFile;//file attr       //~v542R~
//        pfh->UFHfsid    =      fstat3.fsid;//file system id      //~v542R~
//        pfh->UFHuid     =      fstat3.uid ;//userid              //~v542R~
//        pfh->UFHgid     =      fstat3.gid ;//groupid             //~v542R~
//#else  //!UNX                                                    //~v542R~
////      pfh->UFHattr    =(char)fstat3.attrFile;//file time       //~v542R~
//        pfh->UFHattr    =(ULONG)fstat3.attrFile;//file time      //~v542R~
//#endif //!UNX                                                    //~v542R~
#ifdef FTPSUPP                                                     //~v716I~
        if (UCBITCHK(pfh->UFHflag7,UFHF7TSO))	//tso bin mode is explicitly by cmd operand to save same mode//~v716I~
        {                                                          //~v71HI~
			xetsolocalfstat(pfh,&fstat3);	//gett localfile fstat //~v716I~
			xetsodefaultlrecl(pfh,&fstat3);	//set default lrecl/margin etc//~v71HR~
        }                                                          //~v71HI~
#endif                                                             //~v716I~
		filesetfstat(pfh,&fstat3);                                 //~v542I~
	}
#ifdef FTPSUPP                                                     //~v71HI~
    else                                                           //~v71HI~
    {                                                              //~v71HI~
        if (UCBITCHK(pfh->UFHflag7,UFHF7TSO))	//tso bin mode is explicitly by cmd operand to save same mode//~v71HI~
			xetsodefaultlrecl(pfh,&fstat3);	//set default lrecl/margin etc//~v71HI~
    }                                                              //~v71HI~
#endif                                                             //~v71HI~
    if (pfh->UFHtype==UFHTDIR)   //dir type pfh                 //~v020M~
    {                                                           //~v030I~
        if (rc=dirload(Ppcw,pfh),rc)                            //~v030R~
//			ufree(pfh);                                         //~v04dR~
    		fileclosefree2(pfh);	//close and free pfh        //~v04dI~
        return rc;                                              //~v030I~
    }                                                           //~v030I~
	pfh->UFHhfile=hfile;
	UTRACEP("%s:fileload UFHhfile=%p\n",UTT,hfile);                //~vby8I~
                                                                   //~v08lI~
//  if (rc=fileoptionchk(Ppcw,pfh),rc) //lineno opd etc            //~v09YR~
//  {                                                              //~v09YR~
//  	fileclosefree2(pfh);	//close and free pfh               //~v09YR~
//      return rc;                                                 //~v09YR~
//  }                                                              //~v09YR~
    if (filetailposproc(Ppcw,pfh))                                 //~v54cR~
    {                                                              //~v54cI~
        fileclosefree2(pfh);    //close and free pfh               //~v54cI~
        return 16;                                                 //~v54cI~
    }                                                              //~v54cI~
    sline=pfh->UFHsline;                                           //~v08lR~
    eline=pfh->UFHeline;                                           //~v08lI~
    if (UCBITCHK(pfh->UFHflag4,UFHF4XRANGE))                       //~v10YI~
    {                                                              //~v10YI~
//      xranges=(ULONG)pfh->UFHslinepos;   //cmd line parm value   //~vaz0R~
        xranges=pfh->UFHslinepos;   //cmd line parm value          //~vaz0I~
//      xrangee=(ULONG)pfh->UFHelinepos;   //one of them is not 0  //~vaz0R~
        xrangee=pfh->UFHelinepos;   //one of them is not 0         //~vaz0I~
        xrangelast=0;				//to chk eof pos               //~v10YR~
    	xrangesw=1;					//sline and eline is both 0    //~v10YI~
	}                                                              //~v10YI~
    else                                                           //~v10YI~
    {                                                              //~v10YI~
    	xrangesw=0;                                                //~v10YR~
    	xranges=xrangee=0;                                         //~v10YI~
    }                                                              //~v10YI~
    if (chklargefile(pfh)>1)	//issue confirmation               //~vazdR~
    {                                                              //~vazdR~
        fileclosefree2(pfh);    //close and free pfh               //~vazdR~
        return 4;                                                  //~vazdR~
    }                                                              //~vazdR~
//  filegetcid(pfh,1);	//v012get changeid at open,set also to pfh//~5611R~
//top line
	lineno=0;
	lnosuffix=0;		//for split line                           //~v0adI~
	plh=filealloclh(ULHTHDR,MAXCOLUMN);
    UALLOCCHK(plh,fileplhfail(pfh));//return when storage shortage//~v04dI~
	pc=plh->ULHdata;
	memset(pc,'*',MAXCOLUMN);		//clear by '*'
	memcpy(pc,Sfhdrline,strlen(Sfhdrline));	//except last null     //~v08lR~
	memcpy(plh->ULHlineno,Stlineno,ULHLINENOSZ);
	UENQ(UQUE_END,&pfh->UFHlineque,plh);
	
   swebcfile=PFH_ISEBC(pfh);                                       //~va51I~
  if (pfh->UFHtype!=UFHTKFI)		//not kfc dummy file           //~v0ifI~
  { //not UFHTKFI                                                  //~v53UI~
	if (!UCBITCHK(pfh->UFHflag,UFHFNEW))
	{
//enq file data
        if (readbinsw)                                             //~v09YI~
        {                                                          //~v107I~
        	optbinwidth=0;                                         //~v10NI~
        	if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))	// /mb specified//~v107I~
            	binopt=UFGETS_BIN;                                 //~v107I~
            else                                                   //~v107I~
//            if (UCBITCHK(pfh->UFHflag4,UFHF4TEXT))               //~v70zR~
              if (UCBITCHK(pfh->UFHflag4,UFHF4TEXT)                //~v70zI~
    	      ||  UCBITCHK(pfh->UFHflag7,UFHF7TSO))	//tso bin mode is explicitly by cmd operand to save same mode//~v70zR~
                binopt=0;                                          //~v10cM~
              else                                                 //~v10cM~
              {                                                    //~v10NI~
                binopt=UFGETS_OPTBIN;   //binary msg only when no /mb//~v107R~
#ifdef UTF8SUPPH                                                   //~va0vR~
        		if (UCBITCHK(pfh->UFHflag8,UFHF8UTF8))             //~va0vR~
	            	binopt|=UFGETS_UTF8;   //utf8 encoding         //~va0vR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//                else                                               //~va50I~//~va6AR~
//                if (swebcfile)                                //~va50I~//~va51R~//~va6AR~
//                    binopt|=UFGETS_EBC;   //ebcdic encoding binchk //~va50I~//~va6AR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va0vR~
    			optbinwidth=pfh->UFHwidth;                         //~v50aR~
               if (!optbinwidth)                                   //~v49iI~
	        	optbinwidth=(int)Gfhwidth;	//default display width for binary mode//~v10NI~
              }                                                    //~v10NI~
        	  if (swebcfile)                                       //~va6AI~
              {                                                    //~va6DR~
	            binopt|=UFGETS_EBC;   //ebcdic encoding binchk     //~va6AI~
              }                                                    //~va6NI~
        		if (UCBITCHK(pfh->UFHflag11,UFHF11RTEXTEBC))       //~va6DR~
	            	binopt|=UFGETS_EBCEOL;   //eolid is 0x15       //~va6DR~
        		if (UCBITCHK(pfh->UFHflag11,UFHF11RTEXTEBCZ))      //~vbBuI~
	            	binopt|=UFGETS_EBCEOLZ;   //allow eolid is 0x0d15//~vbBuI~
//            }   //allow x15 for not ebc file                     //~va6DR~//~va6NR~
              if (UCBITCHK(pfh->UFHflag10,UFHF10RECORD))           //~va51I~
            	binopt|=UFGETS_RECORD;	//record mode,split by LRECL//~va51I~
			binopt|=setufgetsoptVparm(pfh);                        //~vaj0I~
            ufgetsinit(UFGETS_PC*(UCBITCHK(pfh->UFHflag3,UFHF3RTEXTPC)!=0)//~v09YR~
                       +binopt                                     //~v107I~
                       +UFGETS_MAC *(UCBITCHK(pfh->UFHflag6,UFHF6RTEXTMAC)!=0)//~v47XI~
                       +UFGETS_UNIX*(UCBITCHK(pfh->UFHflag3,UFHF3RTEXTUNIX)!=0),//~v09YR~
//                     0,0);//	default buffsize default rate      //~v10NR~
                       0,0,optbinwidth);//	default buffsize default rate,width when binary//~v10NI~
//            if (!(Slinewidth=pfh->UFHwidth))                     //~v10hR~
//                Slinewidth=MAXLINEDATA2;                         //~v10hR~
		}                                                          //~v107I~
        if (UCBITCHK(pfh->UFHflag10,UFHF10RECORD))                 //~va5SI~
            pfh->UFHtabskip=1;  //force 1 to avaoid overflow record sz//~va5SI~
        else                                                       //~vaj0I~
        if (UCBITCHK(pfh->UFHflag13,UFHF13RV)) //recfm=V           //~vaj0I~
            pfh->UFHtabskip=1;  //force 1 to avaoid overflow record sz//~vaj0I~
        plh=0;                                                     //~v10YI~
        if (xranges>0)		//offset base                          //~vaz1I~
        {                                                          //~vaz1I~
        	rc_seek=seektostartpos(0,pfh,xranges);                 //~vaz1R~
        	if (rc_seek>=4)                                        //~vaz1I~
  				fileclosefree2(pfh);	//close and free pfh       //~vaz1I~
        }                                                          //~vaz1I~
		for (;;)	//until eof/err
		{
          if (Ssplitsw)	//previous is splitted                     //~v0adI~
          	++lnosuffix;                                           //~v0adI~
          else          //previous has eol                         //~v0adI~
          {                                                        //~v0adI~
          	lnosuffix=0;                                           //~v0adI~
			++lineno;
		  }	                                                       //~v0adI~
            Sgetchkoffs=0;	//parm to filegetline,no start offset chk;//~v10YI~
            if (lineno<sline && lineno!=1)                         //~v08lI~
            	pplh=0;                                            //~v08lI~
            else                                                   //~v08lI~
            {                                                      //~v08qI~
            	pplh=&plh;                                         //~v08lI~
              if (xrangesw)		//offset base                      //~v10YI~
              {                                                    //~vazrI~
              	if (!rc_seek)	//not initially seeked             //~vazrI~
                {                                                  //~vaz1I~
		        	if (seektostartpos(STSPO_READBIN,pfh,xranges)==1) //seek if bin file after 1st read//~vaz1R~
                    {                                              //~vaz1I~
                    	rc_seek=2;	//deq 1st line                 //~vaz1I~
  	    				pfh->UFHslinepos=xranges;//start boundary line offset//~vaz1I~
                    }                                              //~vaz1I~
                }                                                  //~vaz1I~
              	Sgetchkoffs=xranges;	//parm to filegetline;start offset chk//~v10YR~
              }                                                    //~vazrI~
              else                                                 //~v10YI~
                if (lineno==sline)  //pos before first line        //~v08qI~
                  if (!lnosuffix)   //previous has eol             //~v0adI~
                  {                                                //~v50QI~
			        if (readbinsw)                                 //~v0abR~
                    {                                              //~v10YI~
    			    	Slineoffs=ufgetscurpos();                  //~v10YR~
//  			    	pfh->UFHslinepos=(long)Slineoffs;          //~vaz0R~
    			    	pfh->UFHslinepos=Slineoffs;                //~vaz0I~
                    }                                              //~v10YI~
        	        else                                           //~v0abR~
                    {                                              //~v10YI~
//                      Slineoffs=(ULONG)ufgetpos(pfh->UFHhfile);  //~vaz0R~
                        Slineoffs=ufgetpos(pfh->UFHhfile);         //~vaz0I~
//      		    	pfh->UFHslinepos=(long)Slineoffs;          //~vaz0R~
        		    	pfh->UFHslinepos=Slineoffs;                //~vaz0I~
                    }                                              //~v10YI~
                  }//lnosuffix                                     //~v50QI~
            }                                                      //~v08qI~
//  		if(rc=filegetline(Ppfile,hfile,lineno,pplh,readbinsw),rc)//~v107R~
//  		if(rc=filegetline(Ppfile,hfile,lineno,pplh,readbinsw,pfh),rc)//~v41qR~
    		if(rc=filegetline(Ppfile,hfile,lineno,pplh,            //~v41qR~
	    						readbinsw|FILE_NOSPLITMSG,pfh),rc) //~v41qR~
				break;
            if (!pplh)//skipline                                   //~v109I~
                continue;                                          //~v109I~
            if (!plh)	//skip by xrange start offset chk          //~v10YR~
                continue;                                          //~v10YI~
          	if (Ssplitsw)	//previous is splitted                 //~v41qR~
            	if (!splitmsgsw)                                   //~v41qR~
                {                                                  //~v41qR~
                	splitmsgsw=1;                                  //~v41qR~
                    filesplitmsg(lineno);                          //~v41qR~
                }                                                  //~v41qR~
            if (xranges)                                           //~v10YI~
            	if (Sgetchkoffs!=xranges) //xranges is in the middle of line//~v10YI~
                {                                                  //~v10YI~
//	    			pfh->UFHslinepos=(long)Sgetchkoffs;//start boundary line offset//~vaz0R~
  	    			pfh->UFHslinepos=Sgetchkoffs;//start boundary line offset//~vaz0I~
	    			xranges=Sgetchkoffs;//start boundary line offset//~v10YI~
                }                                                  //~v10YI~
                	                                               //~v10YI~
			plh->ULHsuffix=lnosuffix;	//split suffix             //~v109I~
			UENQ(UQUE_END,&pfh->UFHlineque,plh);                   //~v109I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va51I~
            if (swebcfile)                                         //~va51I~
            {                                                      //~va51I~
                rc=xeebc_linechk(0,plh);	//setup dbcstbl        //~va51R~
                if (rc==UALLOC_FAILED)                             //~va51I~
                {                                                  //~va51I~
  				  	fileclosefree2(pfh);	//close and free pfh   //~va51I~
                    return rc;                                     //~va51I~
                }                                                  //~va51I~
            }                                                      //~va51I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va51I~
            if (spfpos>0)                                          //~v0clI~
            {                                                      //~v0e8I~
                rc=filespfchk(plh,spfpos,&spfvermax);              //~v0e8R~
                if (rc==UALLOC_FAILED)                             //~v0e8I~
                {                                                  //~v54cI~
  				  	fileclosefree2(pfh);	//close and free pfh   //~v54cI~
                    return rc;                                     //~v0e8I~
                }                                                  //~v54cI~
                spferr|=rc;                                        //~v0e8I~
            }                                                      //~v0e8I~
//            if (!pplh)//skipline                                 //~v109R~
//                continue;                                        //~v109R~
//            plh->ULHsuffix=lnosuffix;   //split suffix           //~v109R~
//            UENQ(UQUE_END,&pfh->UFHlineque,plh);                 //~v109R~
            if (lineno==1)  //first line                           //~v0clM~
            {                //chk after enq for filegetcid        //~v0clI~
    			filegetcid(pfh,0,0,0);	//chk cid hdr line         //~v0clM~
                spfpos=pfh->UFHspfpos;	//spf num fld exist?       //~v0clM~
                if (spfpos)                                        //~v0clI~
                {                                                  //~v0clI~
                    if (sline || eline || xrangesw)                //~v10YR~
                    {                                              //~v0clI~
                        filespfpfeerr();                           //~v0clI~
                        fileclosefree2(pfh);    //close and free pfh//~v0clI~
                        return 4;                                  //~v0clI~
                    }                                              //~v0clI~
					UCBITON(pfh->UFHflag2,UFHF2SPFNUMERR);//clear when set SPFNUMOK//~v0ctR~
                    rc=filespfchk(plh,spfpos,&spfvermax);          //~v0e8R~
                    if (rc==UALLOC_FAILED)                         //~v0e8I~
	                {                                              //~v54cI~
  					  	fileclosefree2(pfh);	//close and free pfh//~v54cI~
                        return rc;                                 //~v0e8I~
                    }                                              //~v54cI~
                    spferr|=rc;                                    //~v0e8I~
                }                                                  //~v0clI~
            }                                                      //~v0clM~
            if (eline && lineno>=eline && !Ssplitsw)               //~v08qR~
            	break;                                             //~v08lM~
            xrangelast=plh->ULHoffs+plh->ULHlen+(int)plh->ULHeolid;//~v50tR~
            if (xrangee)	//end offset specified                 //~v10YI~
            {                                                      //~vaz1I~
            	if (xrangelast>=xrangee)                           //~v10YR~
                {                                                  //~v10YI~
//          		if (rc_seek==1)                                //~vaz1R~
            		if (rc_seek)  //1 or 2                         //~vaz1I~
                    {                                              //~vaz1I~
			            plh->ULHlen=(int)(xrangee-plh->ULHoffs);	//cut by end offset//~vaz1R~
			            xrangelast=xrangee;                        //~vaz1I~
                    }                                              //~vaz1I~
	    			xrangee=xrangelast;	//last line offset         //~v10YR~
//      			pfh->UFHelinepos=(long)xrangee;	//last line offset//~vaz0R~
        			pfh->UFHelinepos=xrangee;	//last line offset //~vaz0I~
                    break;                                         //~v10YI~
				}                                                  //~v10YI~
            }                                                      //~vaz1I~
		}//until eof                                               //~v10YR~
		if (rc>0)	//i/o err
		{
//  		uqfree(&pfh->UFHlineque);                           //~v04dR~
//  		ufree(pfh);                                         //~v04dR~
    		fileclosefree2(pfh);	//close and free pfh        //~v04dI~
			return rc;
		}
      if (xrangesw)                                                //~v10YI~
      {                                                            //~v10YI~
//    	xrangelast=pfh->UFHsize;                                   //~v731R~
//    	xrangelast=(ULONG)pfh->UFHsize;                            //~vaz0R~
      	xrangelast=pfh->UFHsize;                                   //~vaz0I~
        if (rc)   //eof detected before start tine                 //~v10YI~
        	if (xrangelast<=xranges)                               //~v10YR~
        	{                                                      //~v10YI~
//  			uerrmsg("%s has only x%x(<=x%x) byte",             //~vaz0R~
//  					"%s は サイズが x%x(<=x%x)です",           //~vaz0R~
    			uerrmsg("%s has only x%" FILESZ_EDIT "x(<=x%" FILESZ_EDIT "x) byte",//~vaz0R~
    					"%s は サイズが x%" FILESZ_EDIT "x(<=x%" FILESZ_EDIT "x)です",//~vaz0R~
						pfh->UFHfilename,xrangelast,xranges);      //~v10YR~
    			fileclosefree2(pfh);	//close and free pfh       //~v10YI~
				return 4;                                          //~v10YI~
        	}                                                      //~v10YI~
        if (xrangee) 		//end specified                        //~v10YI~
    		if (rc)       //eof detected                           //~v10YI~
            {                                                      //~v10YI~
    			xrangee=0;	//treate full file                     //~v10YR~
    			pfh->UFHelinepos=0;	//treate full file             //~v10YI~
//  			uerrmsg("filesize is %08x",                        //~vaz0R~
//  					"ファイルサイズは %x です",                //~vaz0R~
    			uerrmsg("filesize is %" FILESZ_EDIT "x",           //~vaz0R~
    					"ファイルサイズは %" FILESZ_EDIT "x です", //~vaz0R~
						xrangelast);                               //~v10YR~
            }                                                      //~v10YI~
        if (xranges || xrangee)                                    //~v10YR~
            if (xrangee)                                           //~v10YI~
//              sprintf(rangeedit,"(x%lx-x%lx)",xranges,xrangee);  //~vaz0R~
                sprintf(rangeedit,"(x%" FILESZ_EDIT "x-x%" FILESZ_EDIT "x)",xranges,xrangee);//~vaz0R~
            else                                                   //~v10YI~
//              sprintf(rangeedit,"(x%lx-EOF)",xranges);           //~vaz0R~
                sprintf(rangeedit,"(x%" FILESZ_EDIT "x-EOF)",xranges);//~vaz0R~
        else                                                       //~v10YI~
        {                                                          //~v10YR~
            xrangesw=0;                                            //~v10YR~
            UCBITOFF(pfh->UFHflag4,UFHF4XRANGE);                   //~v10YR~
        }                                                          //~v10YR~
      }                                                            //~v10YI~
      else                                                         //~v10YI~
      {                                                            //~v10YI~
        if (rc && lineno<=sline)   //eof detected before start tine//~v08qR~
        {                                                          //~v08qI~
			uerrmsg("%s has only %ld line",                        //~v08qI~
					"%s は %ld 行しかありません",                  //~v08qR~
					pfh->UFHfilename,lineno-1);                    //~v08qI~
    		fileclosefree2(pfh);	//close and free pfh           //~v08qI~
			return 4;                                              //~v08qR~
        }                                                          //~v08qI~
        if (eline)                                                 //~v08qI~
        {                                                          //~v50QI~
    		if (rc)       //eof detected                           //~v08qI~
            {                                                      //~v08qI~
    			pfh->UFHeline=eline=0;	//treate full file         //~v08qI~
				uerrmsg("last is line %ld",                        //~v08qI~
						"%ld が最後の行です",                      //~v08qI~
						lineno-1);                                 //~v08qR~
            }                                                      //~v08qI~
    		else                                                   //~v08qI~
		      	if (readbinsw)                                     //~v0abR~
//  	    		pfh->UFHelinepos=(long)ufgetscurpos();         //~vaz0R~
    	    		pfh->UFHelinepos=ufgetscurpos();               //~vaz0I~
              	else                                               //~v0abR~
            		pfh->UFHelinepos=ufgetpos(pfh->UFHhfile);      //~v0abR~
        }//eline                                                   //~v50QI~
        if (sline || eline) //line range specified                 //~v08qI~
        {                                                          //~v08qI~
        	if (sline)                                             //~v08qI~
            	if (eline)                                         //~v08qI~
    				sprintf(rangeedit,"(%ld-%ld)",sline,eline);    //~v08qI~
    			else                                               //~v08qI~
    				sprintf(rangeedit,"(%ld-Last)",sline);         //~v08qI~
    		else                                                   //~v08qI~
    			sprintf(rangeedit,"(1st-%ld)",eline);              //~v08qI~
        }                                                          //~v08qI~
      }//not xrange                                                //~v10YI~
	}
    else    //new file                                             //~v472I~
    {                                                              //~v472I~
		if (UCBITCHK(pfh->UFHflag4,UFHF4SPFCMD))	//by e_ cmd or /M_ parm//~v472I~
    		UCBITON(pfh->UFHflag2,UFHF2SPFNUMOK);                  //~v472R~
    }//new file                                                    //~v472I~
  } //not UFHTKFI                                                  //~v53UI~
//end of line
	plh=filealloclh(ULHTHDR,MAXCOLUMN);
    UALLOCCHK(plh,fileplhfail(pfh));//return when storage shortage//~v04dI~
	plh->ULHlinenor=lineno;                                     //~5527R~
	pc=plh->ULHdata;
	memset(pc,'*',MAXCOLUMN);		//clear by '*'
	memcpy(pc,Sftrlline,strlen(Sftrlline));	//except last null     //~v08lR~
	memcpy(plh->ULHlineno,Stlineno,ULHLINENOSZ);
    if (sline || eline || xrangesw) //line range specified         //~v10YR~
		memcpy(pc+strlen(Sftrlline),rangeedit,strlen(rangeedit));	//except last null//~v08qI~
	UENQ(UQUE_END,&pfh->UFHlineque,plh);
#ifdef UTF8SUPPH                                                   //~va00I~
    if (filechkutf8encoding(0,Ppcw,Ppopt,pfh)>4)	//chk each line utf8 code//~va0vR~
    {                                                              //~va00I~
//      if (!UCBITCHK(Goptopt2,GOPT2_NORETRYCPU8ERR)               //~va1eI~//~va1ER~
//      if (!(Gutfmode2 & GUM2_NORETRYCPU8ERR) //no retry when cpu8 err at fileload//~va1ER~//~va1NR~
        if (!UCBITCHK(Goptopt2,GOPT2_NORETRYCPLC)                  //~va1NI~
        &&  UCBITCHK(pfh->UFHflag10,UFHF10UTF8LOADERR)             //~va1eR~
		&&  !UCBITCHK(pfh->UFHflag8,UFHF8UTF8P)    //no CPU8 parm  //~va1eR~
        )                                                          //~va1eI~
            rc=FLRC_RETRYCPU8ERR;	//retry by CPLC                //~va1eI~
        else                                                       //~va1eI~
        	rc=8;                                                  //~va1eI~
    	fileclosefree2(pfh);	//close and free pfh               //~va00I~
//      return 8;                                                  //~va00I~//~va1eR~
        return rc;                                                 //~va1eR~
    }                                                              //~va00I~
    filesetlocaleid(pfh);                                          //~va00R~
#endif                                                             //~va00I~
//  filegetcid(pfh,0,0);	//v012 get changeid at open,chk first line//~v0avR~
    filegetcid(pfh,0,0,0);	//get changeid at open,chk first line,no need out//~v0avI~
	plh=UGETQTOP(&pfh->UFHlineque);                                //~v08qI~
	pc=plh->ULHdata;                                               //~v08qI~
    if (sline || eline || xrangesw) //line range specified         //~v10YR~
		memcpy(pc+strlen(Sftrlline),rangeedit,strlen(rangeedit));	//except last null//~v08qI~
    if (sline || xranges)	//patial file read                     //~v10YR~
    {                                                              //~v08lI~
      if (rc_seek!=1)	//local binfile,xranges!=0                 //~vaz1I~
      {                                                            //~vaz1I~
		plh=UGETQNEXT(plh);                                        //~v08qR~
		UDEQ(UQUE_ENT,&pfh->UFHlineque,plh);                       //~v08qR~
		filefreeplh(plh,1);	//free first line after filegetcid     //~v08qR~
      }                                                            //~vaz1I~
    }                                                              //~v08lI~
    fileeofchk(pfh);	//chk eof ^z exist for later edit             //~v06sI~
//  if (Ppopt & UFCFBROWSE)	//browse mode                       //~v04kR~
//  {                                                           //~v04kR~
//  	fileclose(pfh->UFHfilename,pfh->UFHhfile);              //~v04kR~
//  	pfh->UFHhfile=0;	//avoid close at end/cancel         //~v04kR~
//  }                                                           //~v04kR~
//    if (spferr & SPFERRLEN)                                      //~v0ctR~
//        filespflenerr(spfpos+SPFNUMFLDLEN);                      //~v0ctR~
//    else                                                         //~v0ctR~
//    if (spferr & SPFERRNUM)                                      //~v0ctR~
//        filespfnumerr();                                         //~v0ctR~
//    else                                                         //~v0ctR~
    if (spfpos)                                                    //~v0clI~
    	filespfloadnum(pfh,spfvermax,spferr);                      //~v0ctR~
//    else    //not spf file                                       //~v107R~
//        filechkbin(pfh);    //chk binary file                    //~v107R~
	eolchng=0;				//eol may changed at write             //~v47LI~
    UTRACEP("%s:Seolid=%02x,flag3=%02x,flag11=%02x,flag6=%02x,flag10=%02x,flag13=%02x,flag4=%02x\n",UTT,Seolid,pfh->UFHflag3,pfh->UFHflag11,pfh->UFHflag6,pfh->UFHflag10,pfh->UFHflag13,pfh->UFHflag4);//+vbBuR~
   	if (UCBITCHK(pfh->UFHflag11,UFHF11RTEXTEBCZ))            //not write mode specified//~vbBuR~
    {                                                              //~vbBuI~
	    if (Seolid==(UFGETS_EOLID_EBC|UFGETS_EOLID_EBCZ))//0x18  //eol is 0x15//+vbBuM~
        if (!UCBITCHK(pfh->UFHflag10,UFHF10RECORD)) //record mode  //~vbBuI~
        if (!UCBITCHK(pfh->UFHflag13,UFHF13RV)) //recfm=V at read  //~vbBuI~
    	if (!UCBITCHK(pfh->UFHflag4,UFHF4BIN))                     //~vbBuI~
        {                                                          //~vbBuI~
	    	uerrmsgcat(" :Mixed EndOfLine ID of EBCDIC file(Mz option), 0x0d will be ignored at file save.",//~vbBuI~
						"EBCDIC ファイルの改行コードが混在（Mz オプション)、更新時には 0x0d は無視されます");//~vbBuI~
        }                                                          //~vbBuI~
    }                                                              //~vbBuI~
// 	if (!UCBITCHK(pfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX))//not write mode specified//~v47XR~
   	if (!UCBITCHK(pfh->UFHflag3,UFHF3WTEXTPC|UFHF3WTEXTUNIX) //not write mode specified//~v47XI~
   	&&  !UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC)              //not write mode specified//~va6DI~
   	&&  !UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))              //not write mode specified//~v47XI~
    {                                                              //~v47LI~
        if (UCBITCHK(pfh->UFHflag10,UFHF10RECORD)) //record mode   //~va51I~
        {                                                          //~va6NI~
//          uerrmsgcat(" :Recotd mode,NO EOL will be written.",    //~va51R~
//  					" レコードモード,EOL文字出力無し");        //~va51R~
            ;                                                      //~va51I~
            if (!UCBITCHK(pfh->UFHflag11,UFHF11WRECORD))           //~va6NR~
            {                                                      //~va6NI~
        		sweolchngmsg=1; //issue warning                    //~va6NI~
            	eolchng=2;		//eol may chnaged at save          //~va6NR~
            }                                                      //~va6NI~
        }                                                          //~va6NI~
        else                                                       //~va51I~
        if (UCBITCHK(pfh->UFHflag13,UFHF13RV)) //recfm=V at read   //~vaj0I~
        {                                                          //~vaj0I~
            if (!UCBITCHK(pfh->UFHflag13,UFHF13WV)) //write recfm=V//~vaj0I~
            {                                                      //~vaj0I~
        		sweolchngmsg=1; //issue warning                    //~vaj0I~
            	eolchng=2;		//eol may chnaged at save          //~vaj0I~
            }                                                      //~vaj0I~
        }                                                          //~vaj0I~
        else                                                       //~vaj0I~
    	if (!UCBITCHK(pfh->UFHflag4,UFHF4BIN))                     //~v10uI~
        {                                                          //~v53UI~
    	    UTRACEP("%s:Seolid=%d\n",UTT,Seolid);                  //~vbBuI~
            if (Seolid && UCBITCHK(pfh->UFHflag13,UFHF13WV))       //~vaj0I~
            {                                                      //~vaj0I~
            	eolchng=1;		//eol may chnaged at save          //~vaj0I~
	            uerrmsgcat(" :EndOfLine ID will be dropped by VariableLengthRecord mode option at save",//~vaj0I~
							"改行コードは可変長レコードモード指定により保存時には失われます");//~vaj0I~
            }                                                      //~vaj0I~
            else                                                   //~vaj0I~
            if (Seolid && UCBITCHK(pfh->UFHflag11,UFHF11WRECORD))  //~va5eI~
            {                                                      //~va5eI~
            	eolchng=1;		//eol may chnaged at save          //~va5eI~
	            uerrmsgcat(" :EndOfLine ID will be dropped by Record mode option at save",//~va5eI~
							"改行コードはレコードモード指定により保存時には失われます");//~va5eI~
            }                                                      //~va5eI~
            else                                                   //~va5eI~
	    	if (Seolid==1)   //x0a 	only(at read unix/both mode)   //~v10uI~
            {                                                      //~v10uI~
        	    UCBITON(pfh->UFHflag3,UFHF3WTEXTUNIX);             //~v10uR~
#ifndef UNX                                                        //~v19nI~
               if (UCBITCHK(pfh->UFHflag3,UFHF3RTEXTPC))  //pc(+unix) option specified//~va6LI~
                uerrmsgcat(" :UNIX file",0);                       //~v10uR~
#endif                                                             //~v19nI~
			}                                                      //~v10uI~
			else                                                   //~v10uI~
            {                                                      //~v10uI~
        	    UCBITON(pfh->UFHflag3,UFHF3WTEXTPC);               //~v59xR~
		    	if (Seolid==3)   //x0a 	only(at read unix/both mode)//~v10uI~
                {                                                  //~v59xI~
//                  uerrmsgcat(" :Mixed EndOfLine ID(0ah,0d0ah)",0);//~v47MR~
#ifdef UNX                                                         //~v47MI~
                    UCBITOFF(pfh->UFHflag3,UFHF3WTEXTPC);          //~v59xI~
		      	    UCBITON(pfh->UFHflag3,UFHF3WTEXTUNIX);         //~v59xI~
	                uerrmsgcat(" :Mixed EndOfLine ID,will be unified to Unix form at save",//~v47MR~
								"改行コードが混在、更新後の保存時にはUnix形式(0x0a)に統一されます");//~v47MI~
#else                                                              //~v47MI~
	#ifdef FTPSUPP                                                 //~v59xI~
    			  if (remotesw)                                    //~v59xI~
                  {                                                //~v59xI~
                    UCBITOFF(pfh->UFHflag3,UFHF3WTEXTPC);          //~v59xI~
		      	    UCBITON(pfh->UFHflag3,UFHF3WTEXTUNIX);         //~v59xI~
	                uerrmsgcat(" :RemoteFile:Mixed EndOfLine ID,will be unified to Unix form at save",//~v59xI~
								"RemoteFile:改行コードが混在、更新後の保存時にはUnix形式(0x0a)に統一されます");//~v59xI~
				  }                                                //~v59xI~
                  else                                             //~v59xI~
                  {                                                //~v59xI~
    #endif                                                         //~v59xM~
	                uerrmsgcat(" :Mixed EndOfLine ID,will be unified to PC form at save",//~v47MR~
								"改行コードが混在、更新後保存時にはPC形式(0x0d0a)に統一されます");//~v47MI~
	#ifdef FTPSUPP                                                 //~v59xI~
                  }                                                //~v59xI~
    #endif                                                         //~v59xI~
#endif                                                             //~v47MI~
                }                                                  //~v59xI~
#ifdef UNX                                                         //~v19nI~
//              else                                               //~v47MR~
//      	      if (UCBITCHK(pfh->UFHflag,UFHFNEW))//new file    //~v19vR~
        	      if (Seolid!=2)                                   //~v19vI~
                  {                                                //~v19rI~
	        	  		UCBITOFF(pfh->UFHflag3,UFHF3WTEXTPC);      //~v19rI~
		        	    UCBITON(pfh->UFHflag3,UFHF3WTEXTUNIX);     //~v19rI~
                  }                                                //~v19rI~
                  else                                             //~v19rI~
                	uerrmsgcat(" :PC file",0);                     //~v19nI~
#else                                                              //~v59xI~
	#ifdef FTPSUPP                                                 //~v59xI~
    			  if (remotesw)                                    //~v59xI~
                  {                                                //~v59xI~
	        	      if (Seolid!=2)	//mixed or new	           //~v59xI~
    	              {                                            //~v59xI~
	    	    	  	UCBITOFF(pfh->UFHflag3,UFHF3WTEXTPC);      //~v59xI~
		    	    	UCBITON(pfh->UFHflag3,UFHF3WTEXTUNIX);     //~v59xI~
                	  }                                            //~v59xI~
                  	  else	//0d0a                                 //~v59xR~
                		uerrmsgcat(" :PC file",0);                 //~v59xI~
                  }                                                //~v59xI~
    #endif                                                         //~v59xI~
#endif                                                             //~v19nI~
			}                                                      //~v10uI~
        }//!4bin                                                   //~v53UI~
    }//no eol write parm                                           //~v47LI~
    else	//write eol specified                                  //~v47LI~
    {                                                              //~v47LI~
        sweolchngmsg=1; //issue warning                            //~va6DI~
    	if (!UCBITCHK(pfh->UFHflag4,UFHF4BIN))                     //~v47LI~
        {                                                          //~v53UI~
            if (Seolid && UCBITCHK(pfh->UFHflag11,UFHF11WRECORD))  //~va5eM~
            {                                                      //~va5eI~
            	eolchng=1;		//eol may chnaged at save          //~va5eM~
            }                                                      //~va5eI~
            else                                                   //~va5eI~
	    	if (Seolid==1)   //x0a 	only at read                   //~v47LI~
            {                                                      //~v47LI~
		   		if (UCBITCHK(pfh->UFHflag3,UFHF3WTEXTPC))//write mode specified//~v480I~
                	eolchng=1;		//eol may chnaged at save      //~v47LI~
		   		if (UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))//not write mode specified//~v47XR~
                	eolchng=1;		//eol may chnaged at save      //~v47XI~
		   		if (UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC))//ebc eol write//~va6DR~
                	eolchng=1;		//eol may chnaged at save      //~va6DI~
            }                                                      //~v47LI~
            else                                                   //~v47LI~
	    	if (Seolid==2)   //x0d0a 	only at read               //~v47LI~
            {                                                      //~v47LI~
		   		if (UCBITCHK(pfh->UFHflag3,UFHF3WTEXTUNIX))//not write mode specified//~v47LI~
                	eolchng=1;		//eol may chnaged at save      //~v47LI~
		   		if (UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))//not write mode specified//~v47XR~
                	eolchng=1;		//eol may chnaged at save      //~v47XI~
		   		if (UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC))//ebc eol write//~va6DR~
                	eolchng=1;		//eol may chnaged at save      //~va6DI~
            }                                                      //~v47LI~
            else             //mixed                               //~v47LI~
	    	if (Seolid==3)   //x0a and x0d0a mixed                 //~v47LI~
            {                                                      //~v47LI~
                eolchng=1;		//eol may chnaged at save          //~v47LI~
            }                                                      //~v47LI~
            else             //mixed                               //~v47XI~
	    	if (Seolid==4)   //x0d                                 //~v47XI~
            {                                                      //~v47XI~
//                if (UCBITCHK(pfh->UFHflag3,(UFHF3WTEXTPC|UFHF3WTEXTUNIX)))//not write mode specified//~v47XI~//~va6KR~
//                    eolchng=1;      //eol may chnaged at save      //~v47XI~//~va6KR~
//                if (UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC))//ebc eol write//~va6DR~//~va6KR~
		   		if (!UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))//not write mode specified//~va6KI~
                	eolchng=1;		//eol may chnaged at save      //~va6DI~
            }                                                      //~v47XI~
            else    //no eol (1line file)                          //~v47XI~
	    	if (Seolid==UFGETS_EOLID_EBC)   //RTEXTEBC(x15)        //~va6DR~
            {                                                      //~va6DI~
		   		if (UCBITCHK(pfh->UFHflag3,(UFHF3WTEXTPC|UFHF3WTEXTUNIX)))//not write mode specified//~va6DI~
                	eolchng=1;		//eol may chnaged at save      //~va6DI~
		   		if (UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC))//not write mode specified//~va6DI~
                	eolchng=1;		//eol may chnaged at save      //~va6DI~
		   		if (UCBITCHK(pfh->UFHflag11,UFHF11WTEXT))// /MxT   //~va6NR~
                	eolchng=2;		//eol may chnaged at save      //~va6NR~
            }                                                      //~va6DI~
            else    //no eol (1line file)                          //~va6DI~
            {                                                      //~v47XI~
		   		if (UCBITCHK(pfh->UFHflag11,UFHF11WTEXT))// /MxT   //~va6NI~
                	eolchng=2;		//eol may chnaged at save      //~va6NI~
                else                                               //~va6NI~
		   		if ( (UCBITCHK(pfh->UFHflag3,UFHF3RTEXTPC)         //~v47XI~
                      && !UCBITCHK(pfh->UFHflag3,UFHF3WTEXTPC))    //~v47XI~
		   		||   (UCBITCHK(pfh->UFHflag3,UFHF3RTEXTUNIX)       //~v47XI~
                      && !UCBITCHK(pfh->UFHflag3,UFHF3WTEXTUNIX))  //~v47XI~
		   		||   (!UCBITCHK(pfh->UFHflag11,UFHF11RTEXTEBC)     //~va6LR~
                      && UCBITCHK(pfh->UFHflag11,UFHF11WTEXTEBC))  //~va6LR~
		   		||   (UCBITCHK(pfh->UFHflag6,UFHF6RTEXTMAC)        //~v47XI~
                      && !UCBITCHK(pfh->UFHflag6,UFHF6WTEXTMAC)) ) //~v47XI~
                	eolchng=1;		//eol may chnaged at save      //~v47XI~
            }                                                      //~v47XI~
        }//!4bin                                                   //~v53UI~
    }                                                              //~v47LI~
    if (eolchng)                                                   //~v47LI~
//  	if (UCBITCHK(pfh->UFHflag3,UFHF3WBIN))//wb mode            //~v47LI~//~va6NR~
    	if (UCBITCHK(pfh->UFHflag3,UFHF3WBIN) //wb mode            //~va6NI~
        ||  eolchng==2    //recordmode -->text mode                //~va6NR~
        )                                                          //~va6NI~
        {                                                          //~va6DI~
			UCBITON(pfh->UFHflag6,UFHF6EOLCHNG);//allow file save evenif not updated//~v47LR~
        	if (sweolchngmsg) //issue warning                      //~va6DI~
            	uerrmsgcat(":Warning:EOL-ID will be changed when saved even if no line was updated.",//~va6DI~
                			":注意:保存すると更新がなくてもEOL-IDが変更されます");//~va6DI~
        }                                                          //~va6DI~
    if (Ssplit1stsw  		//split occured                        //~v10BI~
    &&  pfh->UFHwidth       //width specified                      //~v10BI~
    &&  UCBITCHK(pfh->UFHflag2,UFHF2MERGIN))                       //~v10BR~
		uerrmsg("Warning:Margined file have split line",           //~v10BI~
				"警告:マージン指定ファイルに分割行あり");          //~v10BI~
    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))	//binary file          //~v10XM~
    	if (UCBITCHK(Gopt4,GOPT4XLINENO))	//lineno by hex        //~v10XM~
    	   	if (!UCBITCHK(pfh->UFHflag4,UFHF4NLINENO))//not requested normal//~v10XM~
              if (!UCBITCHK(pfh->UFHflag10,UFHF10RECORD))	//record mode default is lineno//~van7I~
    			UCBITON(pfh->UFHflag4,UFHF4XLINENO);//display by hex digit lineno//~v10XM~
#ifdef UTF8UCS2                                                    //~va1NI~
    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                          //~va1NI~
#else                                                              //~va1NI~
    if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))	//hex display mode     //~v594I~
#endif                                                             //~va1NI~
    {                                                              //~v594I~
    	if (UCBITCHK(Gopt4,GOPT47BIT))	//if alias on              //~v594I~
#ifdef UTF8UCS2                                                    //~va1NI~
        	pc="On(display ASCII only)";                           //~va1NR~
#else                                                              //~va1NI~
        	pc="On";                                               //~v594I~
#endif                                                             //~va1NI~
        else                                                       //~v594I~
        	pc="Off";                                              //~v594I~
		uerrmsg2("ASCII %s.",0,	//display if no pending errmsg     //~v594I~
				pc);                                               //~v594I~
    }                                                              //~v594I~
    fcmdbndsset(pfh);                                              //~v74EI~
//  IFDEF_SYNSUPP(xesynchkopen(0,Ppcw,pfh));		//check syntax option at open//~v78oR~
    IFDEF_SYNSUPP(xesynchkopen(Ppopt,Ppcw,pfh));	//opt:browse mode//~v78oI~
#ifdef UTF8SUPPH                                                   //~va00I~
    fileupdateprofile(0,Ppcw,pfh);                                 //~va00R~
#endif                                                             //~va00I~
	UTRACEP("fileload return fnm=%s\n",pfh->UFHfilename);          //~va51R~
	return 0;
}//fileload
                                                                //~5318I~
//**************************************************************** //~v54cI~
// filetailposproc                                                 //~v54cI~
//*change tail pos value to nomal pos value                        //~v54cI~
//*  for num range specification nnt-mmt (line count/hex offset from tail)//~va0vR~
//*parm1:pcw                                                       //~v54cI~
//*parm5:ptr to file hdr                                           //~v54cI~
//*rc   :0-ok 4:file load err or UALLOC_FAILED                     //~v54cI~
//**************************************************************** //~v54cI~
int filetailposproc(PUCLIENTWE Ppcw,PUFILEH Ppfh)                  //~v54cI~
{                                                                  //~v54cI~
//  long xranges,xrangee,xrangelast;                               //~vaz0R~
    FILESZT xranges,xrangee,xrangelast;                            //~vaz0I~
    long sline,eline;                                              //~v54cI~
    int readbinsw;                                                 //~v54cI~
	int  	rc=0;                                                  //~v54cI~
	LONG 	lineno=0;                                              //~v54cR~
	PULINEH *pplh=0;                                               //~v54cI~
	UCHAR 	*pfnm;                                                 //~v54cR~
	FILE *hfile;                                                   //~v54cI~
    int binopt;                                                    //~v54cI~
    int optbinwidth;                                               //~v54cI~
//****************************                                     //~v54cI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4XRANGE))                      //~v54cI~
    {                                                              //~v54cI~
        if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                    //~vaj0R~
        {                                                          //~vaj0I~
        	uerrmsg("Hex range not supported for Variable Record Length file",//~vaj0R~
            		"ファイルオフセットによる範囲指定は可変長レコードファイルでは使えません");//~vaj0I~
            return 4;                                              //~vaj0I~
        }                                                          //~vaj0I~
	    xranges=Ppfh->UFHslinepos;   //cmd line parm value         //~v54cI~
	    xrangee=Ppfh->UFHelinepos;   //one of them is not 0        //~v54cI~
//      xrangelast=(long)Ppfh->UFHsize;                            //~vaz0R~
      	xrangelast=Ppfh->UFHsize;                                  //~vaz0I~
        if (xranges<0)                                             //~v54cI~
        {                                                          //~v54cI~
        	xranges+=xrangelast;                                   //~v54cI~
            if (xranges<0)                                         //~v54cI~
            	xranges=0;                                         //~v54cI~
		    Ppfh->UFHslinepos=xranges;   //cmd line parm value     //~v54cI~
        }                                                          //~v54cI~
        if (xrangee<0)                                             //~v54cI~
        {                                                          //~v54cI~
        	xrangee+=xrangelast;                                   //~v54cI~
            if (xrangee<0)                                         //~v54cI~
            	xrangee=0;                                         //~v54cI~
		    Ppfh->UFHelinepos=xrangee;   //cmd line parm value     //~v54cI~
        }                                                          //~v54cI~
        if (xranges>0 && xranges>=xrangelast)                      //~vaz1R~
        {                                                          //~vaz1I~
    		uerrmsg("%s size is x%" FILESZ_EDIT "x(<=start offset parm:x%" FILESZ_EDIT "x)",//~vaz1R~
    				"%s は サイズが x%" FILESZ_EDIT "x(<=オフセットパラメータ:x%" FILESZ_EDIT "x)です",//~vaz1R~
						Ppfh->UFHfilename,xrangelast,xranges);     //~vaz1R~
            return 4;                                              //~vaz1I~
        }                                                          //~vaz1I~
        return 0;                                                  //~v54cI~
    }                                                              //~v54cI~
//linepos                                                          //~v54cI~
    sline=Ppfh->UFHsline;                                          //~v54cR~
    eline=Ppfh->UFHeline;                                          //~v54cR~
    if (sline>=0 && eline>=0)                                      //~v54cI~
    	return 0;                                                  //~v54cI~
//tail line proc                                                   //~v54cI~
	pfnm=FILELOCALCOPYNAME(Ppfh);                                  //~v54cI~
	hfile=Ppfh->UFHhfile;                                          //~v54cR~
    readbinsw=(UCBITCHK(Ppfh->UFHflag3,UFHF3RBIN)!=0)*FILE_OPEN_BIN;//~v54cR~
    if (readbinsw)                                                 //~v54cI~
    {                                                              //~v54cI~
        optbinwidth=0;                                             //~v54cI~
        if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))   // /mb specified  //~v54cR~
            binopt=UFGETS_BIN;                                     //~v54cI~
        else                                                       //~v54cI~
          	if (UCBITCHK(Ppfh->UFHflag4,UFHF4TEXT))                //~v54cR~
            	binopt=0;                                          //~v54cI~
          	else                                                   //~v54cI~
          	{                                                      //~v54cI~
            	binopt=UFGETS_OPTBIN;   //binary msg only when no /mb//~v54cI~
#ifdef UTF8SUPPH                                                   //~va0vR~
        		if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))            //~va0vR~
	            	binopt|=UFGETS_UTF8;   //utf8 encoding         //~va0vR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//                else                                               //~va50I~//~va6AR~
//                if (PFH_ISEBC(Ppfh))                               //~va50I~//~va6AR~
//                    binopt|=UFGETS_EBC;   //ebcdic encoding binchk //~va50I~//~va6AR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va0vR~
            	optbinwidth=Ppfh->UFHwidth;                        //~v54cR~
           		if (!optbinwidth)                                  //~v54cI~
            		optbinwidth=(int)Gfhwidth;  //default display width for binary mode//~v54cI~
          	}                                                      //~v54cI~
        	if (PFH_ISEBC(Ppfh))                                   //~va6AI~
            {                                                      //~va6DR~
	        	binopt|=UFGETS_EBC;   //ebcdic encoding binchk     //~va6AI~
            }                                                      //~va6NI~
        		if (UCBITCHK(Ppfh->UFHflag11,UFHF11RTEXTEBC))      //~va6DR~
	            	binopt|=UFGETS_EBCEOL;   //eolid is 0x15       //~va6DR~
        		if (UCBITCHK(Ppfh->UFHflag11,UFHF11RTEXTEBCZ))     //~vbBuI~
	            	binopt|=UFGETS_EBCEOLZ;   //eolid is 0x15      //~vbBuI~
//          }//allow 0x15 for not ebc file                        //~va6DR~//~va6NR~
            if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))            //~va51I~
            	binopt|=UFGETS_RECORD;	//record mode,split by LRECL//~va51I~
			binopt|=setufgetsoptVparm(Ppfh);                       //~vaj0I~
        ufgetsinit(UFGETS_PC*(UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTPC)!=0)//~v54cR~
                   +binopt                                         //~v54cI~
                   +UFGETS_MAC *(UCBITCHK(Ppfh->UFHflag6,UFHF6RTEXTMAC)!=0)//~v54cR~
                   +UFGETS_UNIX*(UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTUNIX)!=0),//~v54cR~
                   0,0,optbinwidth);//  default buffsize default rate,width when binary//~v54cI~
    }                                                              //~v54cI~
//count total line                                                 //~v54cI~
    Ssplit1stsw=1;	//avoid split msg                              //~v54cI~
    for (;;)    //until eof/err                                    //~v54cI~
    {                                                              //~v54cI~
      	if (!Ssplitsw) //previous is splitted                      //~v54cI~
        	++lineno;                                              //~v54cI~
        if(rc=filegetline(pfnm,hfile,lineno,pplh,                  //~v54cR~
                            readbinsw|FILE_NOSPLITMSG,Ppfh),rc)    //~v54cR~
            break;                                                 //~v54cI~
    }//until eof                                                   //~v54cI~
    if (sline<0)                                                   //~v54cI~
    {                                                              //~v54cI~
	    sline+=lineno;                                             //~v54cI~
        if (sline<0)                                               //~v54cI~
        	sline=0;                                               //~v54cI~
        Ppfh->UFHsline=sline;                                      //~v54cI~
    }                                                              //~v54cI~
    if (eline<0)                                                   //~v54cI~
    {                                                              //~v54cI~
	    eline+=lineno;                                             //~v54cI~
        if (eline<0)                                               //~v54cI~
        	eline=0;                                               //~v54cI~
        Ppfh->UFHeline=eline;                                      //~v54cI~
    }                                                              //~v54cI~
	fileopeninit();		//static re-init                           //~v54cI~
    if (rc<0)  			//eof                                      //~v54cR~
    	rc=fileseek(Ppfh,0,SEEK_SET);                              //~v54cR~
    return rc;                                                     //~v54cI~
}//fileltailposproc                                                //~v54cI~
//**************************************************************** //~v542I~
//*save fstat info to ufileh                                       //~v542I~
//**************************************************************** //~v542I~
void filesetfstat(PUFILEH Ppfh,FILEFINDBUF3 *Ppfstat3)             //~v542I~
{                                                                  //~v542I~
	FILEFINDBUF3 fstat3;                                           //~va0kI~
    char fpath[_MAX_PATH];                                         //~va0kI~
//*************************                                        //~va0kI~
#ifdef FTPSUPP	//unix or win ftp                                  //~v544R~
  if (*Ppfstat3->slink)                                            //~v544I~
  {                                                                //~v544I~
    Ppfh->UFHsize    =Ppfstat3->slinksize;         //file size     //~v544I~
    Ppfh->UFHfiledate=Ppfstat3->slinkfdate;//file date             //~v544I~
    Ppfh->UFHfiletime=Ppfstat3->slinkftime;//file time             //~v544I~
    Ppfh->UFHsrcattr =Ppfstat3->srcattr   ;//file time             //~v55PI~
  }                                                                //~v544I~
  else                                                             //~v544I~
  {                                                                //~v544I~
#endif                                                             //~v544I~
#ifdef UTF8SUPPH                                                   //~va1qI~
	if (Ppfh->UFHlevel && WILDCARD(Ppfh->UFHfilename+Ppfh->UFHpathlen))  //not root and wildcard//~va0kR~
    {                                                              //~va0kI~
#ifdef UNX                                                         //~vaa0I~
      if (!(Ppfstat3->attrFile & FILE_WILDNAME))                   //~vaa0R~
#endif                                                             //~vaa0I~
      {                                                            //~vaa0I~
//    	UmemcpyZ(fpath,Ppfh->UFHfilename,Ppfh->UFHpathlen);        //~va0kR~//~vb2eR~
      	UmemcpyZ(fpath,Ppfh->UFHfilename,(size_t)Ppfh->UFHpathlen);//~vb2eI~
        if (!ufstat(fpath,&fstat3))                                //~va0kI~
        {                                                          //~va0kI~
		    Ppfstat3->fdateLastWrite=fstat3.fdateLastWrite;//file date//~va0kR~
		    Ppfstat3->ftimeLastWrite=fstat3.ftimeLastWrite;//file date//~va0kR~
        }                                                          //~va0kI~
      }                                                            //~vaa0I~
    }                                                              //~va0kI~
#endif                                                             //~va1qI~
    Ppfh->UFHsize    =Ppfstat3->cbFile;         //file size        //~v542R~
    Ppfh->UFHfiledate=Ppfstat3->fdateLastWrite;//file date         //~v542R~
    Ppfh->UFHfiletime=Ppfstat3->ftimeLastWrite;//file time         //~v542R~
#ifdef FTPSUPP	//unix or win ftp                                  //~v544R~
  }//not slink target                                              //~v544I~
#endif                                                             //~v544I~
#ifdef UNX                                                         //~v542I~
    Ppfh->UFHattr    =Ppfstat3->attrFile;//file attr               //~v542R~
    Ppfh->UFHfsid    =Ppfstat3->fsid;//file system id              //~v542R~
    Ppfh->UFHinode   =Ppfstat3->inode;                             //~vaa0I~
    Ppfh->UFHuid     =Ppfstat3->uid ;//userid                      //~v542R~
    Ppfh->UFHgid     =Ppfstat3->gid ;//groupid                     //~v542R~
#else  //!UNX                                                      //~v542I~
    Ppfh->UFHattr    =(ULONG)Ppfstat3->attrFile;//file time        //~v542R~
#endif //!UNX                                                      //~v542I~
	return;                                                        //~v542I~
}//filesetfstat                                                    //~v542I~
//****************************************************************
// filefindopen
//* fstat and open
//*  for remote file,assing local file then open                   //~v542I~
//*parm1:file name for err msg
//*parm2:file status area ptr
//*parm3:open opt(UFCFBROWSE(1),0(edit),x7f(new open)              //~v0abI~
//*      0x0100 (binnary mode) 0x0200(append mode)                 //~v0iaR~
//*parm4:output FILE * ptr
//*parm5:filefind msg option                                    //~v020I~
//*parm6:(UNX)output alias for mdos disk                           //~v48cI~
//*parm7:temp file name for remote file edit                       //~v576I~
//*           (if not null string,output tempname requested)       //~v576I~
//*retrn:rc 0:ok ,1:new file,2:dir,4:not found(read open) 8:path err//~v020R~
//*         12:full path err 16:open err                        //~5128I~
//****************************************************************
#ifdef UNX                                                         //~v48cI~
int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt,    //~v48cI~
//  			FILE** Pphfile,int Pmsgopt,UCHAR *Ptempalias)      //~v576R~
    			FILE** Pphfile,int Pmsgopt,UCHAR *Ptempalias,UCHAR *Pftplocalfnm)//~v576I~
#else                                                              //~v48cI~
  #ifdef FTPSUPP                                                   //~v576I~
int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt,    //~v576I~
				FILE** Pphfile,int Pmsgopt,UCHAR *Pftplocalfnm)    //~v576I~
  #else                                                            //~v576I~
int filefindopen(UCHAR *Ppfile,FILEFINDBUF3 *Ppfstat3,int Popt, //~v020R~
				FILE** Pphfile,int Pmsgopt)                     //~v020I~
  #endif                                                           //~v576I~
#endif                                                             //~v48cI~
{
	int rc;
	char *openopt="r";
    int rbsw;                                                      //~v09YI~
    int appsw;                                                     //~v0iaI~
#ifdef FTPSUPP                                                     //~v70zI~
    int binsw;                                                     //~v70zI~
#endif                                                             //~v70zI~
//#ifdef UNX                                                       //~v542R~
#ifdef FTPSUPP                                                     //~v542R~
	int newsw=0;                                                   //~v48cI~
	char ftpwdfile[_MAX_PATH];                                     //~v542R~
    PUFTPHOST puftph;                                              //~v54cR~
    UTSOFTPPARM tsop;                                              //~v8@sR~
//    int tsosw;                                                     //~v70zI~
#endif                                                             //~v48cI~
	int optFileOpen=0;                                             //~vbyaI~
//****************
	UTRACEP("%s:fnm=%s,opt=0x%x\n",UTT,Ppfile,Popt);               //~vbyaI~
#ifdef UNX                                                         //~v48cI~
	*Ptempalias=0;	//init output                                  //~v48cI~
#endif                                                             //~v48cI~
//    Ssplitsw=0;         //for filegetline                        //~v54cR~
//    Ssplitswb=0;            //for filegetline                    //~v54cR~
//    Ssplit1stsw=0;      //for filegetline split msg              //~v54cR~
//    Seolid=0;           //chk unix flat file                     //~v54cR~
//    Slineoffs=0;    //clear for call filegetline from copy cmd   //~v54cR~
//    Sgetchkoffs=0;  //parm to filegetline,no start offset chk;   //~v54cR~
	fileopeninit();                                                //~v54cI~
	*Pphfile=0;			//clear for intermediate return
    rbsw=0;                                                        //~v09YI~
#ifdef ARMXXE                                                      //~vbyaI~
    optFileOpen=FOWOO_ALLOWDOC;	//option to fileopenAllowDoc   //~vbyaI~
#endif                                                             //~vbyaI~
//  if (Popt!=-1)                                                  //~v0abR~
    	if (Popt & FILE_OPEN_BIN)                                  //~v0abR~
        {                                                          //~v09YI~
        	rbsw=1;                                                //~v09YI~
        	Popt=(Popt & ~FILE_OPEN_BIN);                          //~v0abR~
		}                                                          //~v09YI~
    if (Popt & FILE_OPEN_APPEND)                                   //~v0iaI~
    {                                                              //~v0iaI~
        appsw=1;                                                   //~v0iaI~
        Popt=(Popt & ~FILE_OPEN_APPEND);                           //~v0iaI~
    }                                                              //~v0iaI~
    else                                                           //~v0iaI~
        appsw=0;                                                   //~v0iaI~
//  if (rc=filefind(Ppfile,0,Ppfstat3,Pmsgopt),rc)	//no need fullpath name//~v70zR~
#ifdef FTPSUPP                                                     //~v70zI~
    if (Popt & FILE_BINHEXFILE)		//no conversion for ftp 3270   //~v70zM~
    {                                                              //~v70zM~
        binsw=XEFTPO_BIN;                                          //~v70zM~
        Popt=(Popt & ~FILE_BINHEXFILE);                            //~v70zM~
    }                                                              //~v70zM~
    else                                                           //~v70zM~
         binsw=0;                                                   //~v70zM~
      uftpisremote(Ppfile,&puftph); //remote hostname prefix exist //~v70zR~
//    tsosw=UFTPHISTSO(puftph);                                    //~v716R~
//    if (tsosw)                                                   //~v716R~
//    {                                                            //~v716R~
//        if (Pftplocalfnm && *Pftplocalfnm)  //already tempname defined//~v716R~
//            strcpy(ftpwdfile,Pftplocalfnm);   //use defined name //~v716R~
//        else                                                     //~v716R~
//        {                                                        //~v716R~
//            xeftpgetwdfname(puftph,Ppfile,ftpwdfile);            //~v716R~
//            if (Pftplocalfnm)                                    //~v716R~
//                strcpy(Pftplocalfnm,ftpwdfile); //output         //~v716R~
//        }                                                        //~v716R~
//        rc=xetsofilefindcopy(Pmsgopt|binsw,puftph,Ppfile,ftpwdfile,Ppfstat3);   //no need fullpath name//~v716R~
//    }                                                            //~v716R~
//    else                                                         //~v716R~
#endif                                                             //~v70zI~
    	rc=filefind(Ppfile,0,Ppfstat3,Pmsgopt);	//no need fullpath name//~v70zI~
    if (rc)                                                        //~v70zI~
	{
    	if (rc==16 || rc==20)	//dir,wild card                 //~v020R~
        	return 2;                                           //~v020I~
		if (rc>4)                                               //~5128R~
			return rc;                                          //~5128R~
		switch(Popt)
		{
		case UFCFBROWSE:
			uerrmsg("%s is not found",
					"%s が見つかりません",Ppfile);
			return 4;                                           //~5128R~
//  	case -1:	//output open                                  //~v0abR~
    	case FILE_OPEN_OUT:	//output open                          //~v0abI~
          if (rbsw)                                                //~v0abI~
           	openopt="wb";                                          //~v0abR~
          else                                                     //~v0abI~
			openopt="w";
			break;
		default:		//edit
			return 1;	//bypass open(new file)                 //~5128R~
		}
#ifdef UNX                                                         //~v48cI~
		newsw=1;			//open output new file                 //~v48cI~
#endif                                                             //~v48cI~
	}
	else				//file found                            //~5128I~
    {                                                           //~v020I~
//		if (Popt==-1)	//output open  req                         //~v0abR~
  		if (Popt==FILE_OPEN_OUT)	//output open  req             //~v0abI~
         if (appsw)                                                //~v0iaI~
          if (rbsw)                                                //~v0iaI~
           	openopt="ab";                                          //~v0iaI~
          else                                                     //~v0iaI~
			openopt="a";                                           //~v0iaI~
         else                                                      //~v0iaI~
          if (rbsw)                                                //~v0abI~
           	openopt="wb";                                          //~v0abR~
          else                                                     //~v0abI~
			openopt="w";                                        //~5128I~
        else                                                       //~v09YI~
        	if (rbsw)                                              //~v09YR~
				openopt="rb";                                      //~v09YI~
	}                                                           //~v020I~
#ifdef UNX                                                         //~v48cI~
	if (MDOSDISKOK(Ppfile))	//mdos disk open	                   //~v48cI~
    {                                                              //~v48cI~
		if (!(*Pphfile=fileopen_mdostemp(Ppfile,openopt,newsw,Ptempalias)))      	//open//~v48cR~
			return 16;                                             //~v48cI~
    }                                                              //~v48cI~
    else                                                           //~v48cI~
//  if (Ppfstat3->attrFile & FILE_SPECIAL)//not reguler file       //~v49iR~
    if (!rc && (Ppfstat3->attrFile & FILE_SPECIAL))//not reguler file//~v49iI~
		return ufileerrspecialfile(Ppfile,16);                     //~v49gI~
    else                                                           //~v49gI~
#else                                                              //~v720R~
  #ifdef FTPSUPP                                                   //~v720R~
    if (!rc && (Ppfstat3->attrFile & FILE_SPECIAL))//not reguler file//~v720R~
	    return ufileerrspecialfile(Ppfile,16);                     //~v720R~
    else                                                           //~v720R~
  #endif                                                           //~v720R~
#endif                                                             //~v48cI~
#ifdef FTPSUPP                                                     //~v542I~
//  if (uftpisremote(Ppfile,&puftph)) //remote hostname prefix exist//~v70zR~
    if (puftph) //remote hostname prefix exist                     //~v70zI~
    {                                                              //~v542I~
//   if (!tsosw)                                                   //~v716R~
//   {                                                             //~v716R~
      if (Pftplocalfnm && *Pftplocalfnm)	//already tempname defined//~v576I~
        strcpy(ftpwdfile,Pftplocalfnm);   //use defined name       //~v576I~
      else                                                         //~v576I~
      {                                                            //~v576I~
//      xeftpgetwdfname(Ppfile,ftpwdfile);                         //~v70zR~
//      xeftpgetwdfname(puftph,Ppfile,ftpwdfile);                  //~v70zI~//~vb7eR~
        if (xeftpgetwdfname(puftph,Ppfile,ftpwdfile,sizeof(ftpwdfile))<0)//~vb7eR~
        	return 16;                                             //~vb7eI~
        if (Pftplocalfnm)                                          //~v576I~
        	strcpy(Pftplocalfnm,ftpwdfile);	//output               //~v576I~
      }                                                            //~v576I~
        if (!newsw)                                                //~v542I~
        {                                                          //~v8@sI~
            binsw|=XEFTPO_2TEMPF;             //get to local temp file directory//~vb7eI~
            xetsosetftpparm(XETSOFTPO_DBCSCONV|XETSOFTPO_FFB3,puftph,&tsop,Ppfstat3); //set tso parm to puftph//~v8@sR~
//  		if (xeftpget(puftph,Ppfile))                           //~v576R~
//  		if (xeftpget(puftph,Ppfile,ftpwdfile))                 //~v70zR~
//  		if (xeftpget(binsw,puftph,Ppfile,ftpwdfile))           //~v8@sR~
    		if (xeftpget(binsw,puftph,Ppfile,ftpwdfile,&tsop))     //~v8@sI~
	            return 16;                                         //~v542R~
        }                                                          //~v8@sI~
//   }//!tsosw                                                     //~v716R~
		if (!(*Pphfile=fileopen(ftpwdfile,openopt)))      	//open //~v542I~
			return 16;                                             //~v542I~
    }                                                              //~v542I~
    else                                                           //~v542I~
#endif                                                             //~v542I~
//*!remote                                                         //~vbyaI~
//	if (!(*Pphfile=fileopen(Ppfile,openopt)))      	//open         //~vbyaR~
  	if (!(*Pphfile=fileopenWithOption(optFileOpen,Ppfile,openopt)))      	//open//~vbyaI~
		return 16;
	return 0;
}//filefindopen
//**************************************************************** //~v54cI~
// fileopeninit                                                    //~v54cI~
//  init static value when open                                    //~v54cI~
//**************************************************************** //~v54cI~
void fileopeninit(void)                                            //~v54cR~
{                                                                  //~v54cI~
    Ssplitsw=0;			//for filegetline                          //~v54cI~
    Ssplitswb=0;			//for filegetline                      //~v54cI~
    Ssplit1stsw=0;		//for filegetline split msg                //~v54cI~
    Seolid=0;           //chk unix flat file                       //~v54cI~
   	Slineoffs=0;	//clear for call filegetline from copy cmd     //~v54cI~
    Sgetchkoffs=0;	//parm to filegetline,no start offset chk;     //~v54cI~
}//fileopeninit                                                    //~v54cI~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
// filembsplitchk                                                  //~va00I~
//* eol boundary char split chk                                    //~va00I~
//*retrn:EOL split multibyte char len,0 for no splitchk            //~va00I~
//**************************************************************** //~va00I~
int filembsplitchk(int Popt,PUFILEH Ppfh,UCHAR *Pdata,int Pdatalen,int Plinewidth)//~va00R~
{                                                                  //~va00I~
	int mbsplitlen=0,opt,ovflen,utf8len;                           //~va00R~
//****************************                                     //~va00I~
	ovflen=Pdatalen-Plinewidth;                                    //~va00R~
	if (ovflen<=0)                                                 //~va00I~
    	return 0;                                                  //~va00I~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))   // /mb specified      //~va00I~
    	return 0;	//no split chk                                 //~va00I~
	if (Popt & FILE_READUTF8    //reading utf8 file                //~va00I~
    ||  FILEUTF8MODE(Ppfh))         //input is utf8                //~va00R~
    {                                                              //~va00I~
    	if (UTF8ISASCII(*(Pdata+Plinewidth-1)))                    //~va00I~
        	return ovflen;                                         //~va00I~
    	opt=0;                                                     //~va00I~
		utfsplitchk(opt,Pdata,Plinewidth,&utf8len,0/*errctr*/);    //~va00I~
        mbsplitlen=Pdatalen-utf8len;                               //~va00I~
    }                                                              //~va00I~
	return mbsplitlen;                                             //~va00I~
}//filembsplitchk                                                  //~va00I~
#endif                                                             //~va00I~
//**************************************************************** //~va6kI~
//get line from COPY cmd source file                               //~va6kI~
//**************************************************************** //~va6kI~
int filegetline_copysrc(int Popt,UCHAR *Pfilename,FILE *Phfile,long Pline,PULINEH *Ppplh,//~va6kI~
				int Prbmode,PUFILEH Ppfh,int Pcopyopt,int Pcopylrecl)//~va6kI~
{                                                                  //~va6kI~
    int rc;                                                        //~va6kI~
//***************                                                  //~va6kI~
	Scopysrclrecl=0;                                               //~va6kR~
	if (Pcopyopt & FSOC_EOL_RECORD)                                //~va6kR~
    {                                                              //~va6kI~
    	Scopysrclrecl=Pcopylrecl;                                  //~va6kI~
    }                                                              //~va6kI~
    rc=filegetline(Pfilename,Phfile,Pline,Ppplh,Prbmode,Ppfh);     //~va6kI~
	Scopysrclrecl=0;                                               //~va6kR~
    return rc;                                                     //~va6kI~
}//filegetline_copysrc                                             //~va6kI~
//****************************************************************
// filegetline
//* 1 line get
//*parm1:file name for err msg
//*parm2:file handle for i/o
//*parm3:lineno 
//*parm4:output plh addr or 0 if not plh alloc requied             //~v08lR~
//*parm5:file read binary mode option                              //~v09YI~
//*parm6:pfh                                                       //~v107R~
//*retrn:rc 0:ok ,8:i/o err, -1:eof, UALLOC_FAILED              //~v04dR~
//****************************************************************
int filegetline(UCHAR *Pfilename,FILE *Phfile,long Pline,PULINEH *Ppplh,//~v09YR~
				int Prbmode,PUFILEH Ppfh)                          //~v107R~
{
static UCHAR Slastchar=0;         //char on split                  //~v42yR~
static UCHAR Slasteol=0;         //latest line eol                 //~v42yR~
	int  	len,prevsplit;                                      //~5107R~
	PULINEH plh;
    int rc=0;                                                      //~v19nR~
    int eolid,noeolsw;                                             //~v103I~
    UINT ulen;                                                     //~v09YI~
    UINT ureqlen;                                                  //~v108I~
    int  prevsplitb;                                               //~v108I~
    int nosplitmsgsw;                                              //~v41qR~
//  ULONG lineendoffs,lineoffs;                                    //~vaz0R~
    FILESZT lineendoffs,lineoffs;                                  //~vaz0I~
//  char *pc,*pc0;                                                 //~v0a1R~
#ifdef UTF8SUPPH                                                   //~va00I~
	static UCHAR Slastmbstr[MAX_MBCSLEN];                          //~va00I~
    int mbsplitlen,copyutf8sw;                                     //~va00R~
#endif                                                             //~va00I~
    int mflinetype=0;                                              //~vaj0I~
//****************************
	UTRACEP("%s:entry rbmode=0x%x,FHfilename=%s\n",UTT,Prbmode,Ppfh->UFHfilename);//~vbyaI~
	nosplitmsgsw=Prbmode & FILE_NOSPLITMSG;                        //~v41qR~
    Prbmode &=~FILE_NOSPLITMSG;                                    //~v41qR~
#ifdef UTF8SUPPH                                                   //~va00I~
	copyutf8sw=Prbmode & FILE_READUTF8;                            //~va00I~
    Prbmode &=~FILE_READUTF8;                                      //~va00I~
#endif                                                             //~va00I~
	if (Scopysrclrecl)                                             //~va6kI~
    	Slinewidth=Scopysrclrecl;                                  //~va6kI~
    else                                                           //~va6kI~
    if (!(Slinewidth=Ppfh->UFHwidth))                              //~v10hR~
        Slinewidth=MAXLINEDATA2;                                   //~v10hI~
    if (prevsplit=Ssplitsw,Ssplitsw)                               //~v108R~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
      if (Ssplitsw>1)	//split multi byte char                    //~va00I~
		memcpy(Gfilebuff,Slastmbstr,(UINT)Ssplitsw);	//boundary multibyte char//~va00R~
      else                                                         //~va00I~
#endif                                                             //~va00I~
		*Gfilebuff=Slastchar;                                   //~5107I~
    }                                                              //~va00I~
	noeolsw=0;                                                     //~v103I~
  if (Prbmode)                                                     //~v09YI~
  {                                                                //~v09YI~
//  rc=ufgets(Gfilebuff+Ssplitsw,(UINT)(MAXLINEDATA2+1-Ssplitsw),Phfile,&ulen,0);//~v103R~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~v108I~
//  	ureqlen=MAXLINEDATA2;                                      //~v10eR~
//  	ureqlen=Slinewidth;                                        //~v10eI~//~vb2eR~
    	ureqlen=(UINT)Slinewidth;                                  //~vb2eI~
    else                                                           //~v108I~
//  if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                    //~va51I~//~va6kR~
    if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD)||Scopysrclrecl)     //~va6kI~
//  	ureqlen=Slinewidth;                                        //~va51I~//~vb2eR~
    	ureqlen=(UINT)Slinewidth;                                  //~vb2eI~
    else                                                           //~va51I~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))  //recfm=V             //~vaj0I~
//  	ureqlen=Slinewidth;                                        //~vaj0I~//~vb2eR~
    	ureqlen=(UINT)Slinewidth;                                  //~vb2eI~
    else                                                           //~vaj0I~
//  	ureqlen=MAXLINEDATA2+1;	//split deny later when optbin     //~v10eR~
//  	ureqlen=Slinewidth+1;	//split deny later when optbin     //~v10eI~//~vb2eR~
    	ureqlen=(UINT)(Slinewidth+1);	//split deny later when optbin//~vb2eI~
  if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))  //recfm=V               //~vaj0I~
    prevsplitb=0;   //no remaining from prev line                  //~vaj0I~
  else                                                             //~vaj0I~
    prevsplitb=Ssplitsw+Ssplitswb;                                 //~v108I~
    if (Ssplitswb)                                                 //~v108M~
    {                                                              //~v108I~
		*Gfilebuff=Slastchar;                                      //~v108M~
        Ssplitswb=0;                                               //~v108I~
	}                                                              //~v108I~
    if (prevsplitb && Slasteol)	//prev line ended with 1 byte+eol  //~v10yI~
    {                                                              //~v10yI~
    	ulen=0;                                                    //~v10yI~
    	eolid=Slasteol;                                            //~v10yI~
    }                                                              //~v10yI~
    else                                                           //~v10yI~
//  rc=ufgets(Gfilebuff+prevsplitb,(UINT)(ureqlen-prevsplitb),Phfile,&ulen,&eolid);//~v108R~//~vb2eR~
    rc=ufgets(Gfilebuff+prevsplitb,(UINT)(ureqlen-(UINT)prevsplitb),Phfile,&ulen,&eolid);//~vb2eI~
//  if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                        //~vaj0I~//~vanbR~
//      eolid=0;                                                   //~vaj0I~//~vanbR~
    Slasteol=0;         //latest line eol                          //~v10yI~
//  len=(int)ulen+Ssplitsw;                                        //~v108R~
    len=(int)ulen+prevsplitb;                                      //~v108R~
    switch (rc)		//0 or 4 is ok                                 //~v09YI~
    {                                                              //~v09YI~
    case UFGETS_ERR:                                               //~v09YI~
        ufileapierr("read by fgets",Pfilename,errno);              //~v09YI~
		return 8;                                                  //~v09YI~
    case UFGETS_ERRV:   //recfm=V length err                       //~vaj0I~
        uerrmsgcat (";vfmt(%s) err at lineNo %ld",0,               //~vaj0R~
        			ufile5getVfmtstr(0,Ppfh->UFHvfmt),             //~vaj0R~
        			Pline);                                        //~vaj0I~
		return 8;                                                  //~vaj0I~
    case UFGETS_EOF:                                               //~v09YI~
      if (!len)                                                    //~v10aI~
		return -1;		//eof                                      //~v09YI~
        rc=0;                                                      //~v10aI~
        break;                                                     //~v10aI~
	default:	//normal                                           //~v103R~
//  	if (rc==UFGETS_RCBIN)	//bin data rate over 50% at first 100 byte//~v107I~//~va6MR~
    	if (rc==UFGETS_RCBIN||rc==UFGETS_RCBIN_NOEOL)	//bin data rate over 50% at first 100 byte//~va6MI~
        {                                                          //~v107I~
		    UCBITON(Ppfh->UFHflag4,UFHF4BIN);                      //~v107R~
    	  if (rc==UFGETS_RCBIN_NOEOL)	//bin data rate over 50% at first 100 byte//~va6MI~
    		uerrmsg("This is binary file(No EOL found in 1st %d byte), Use ET cmd if you want.",//~va6MR~
            			"バイナリーファイルです(最初の%dバイトにEOLがない), ET コマンドでテキストモード。",//~va6MR~
                        	UFGETS_MAX1ST);                        //~va6MI~
          else                                                     //~va6MI~
  //		uerrmsg("This is binary file",                         //~v107R~//~va6MR~
  //        			"バイナリーファイルです");                 //~v107I~//~va6MR~
    		uerrmsg("This is binary file(too high control char rate), Use ET cmd if you want.",//~va6MR~
            			"バイナリーファイルです(高制御文字率), ET コマンドでテキストモード。");//~va6MR~
    		if (UCBITCHK(Gopt4,GOPT47BIT))	//if alias on          //~v79vI~
	    		uerrmsgcat("(current display mode is ASCII(7bit) ON)",//~v79vI~
            			"(現在の\x95\\示モードはASCII(７ビット文字) ON)");//~v79vR~
            rc=0;                                                  //~v107I~
    	  if (!Ppfh->UFHwidth)                                     //~v13rI~
	      	if (Gfhwidth)			//default display width for binary mode//~v10NI~
          	{                                                      //~v10NI~
    			Slinewidth=(UINT)Gfhwidth;                         //~v10NI~
    			Ppfh->UFHwidth=Gfhwidth;                           //~v10NR~
          	}                                                      //~v10NI~
//  		if (len>MAXLINEDATA2)                                  //~v10eR~
//    		if ((UINT)len>Slinewidth)                              //~vaz1R~
      		if (len>Slinewidth)                                    //~vaz1I~
    		{                                                      //~v108I~
//  			len=MAXLINEDATA2;                                  //~v10eR~
    			len=(int)Slinewidth;                               //~v10eR~
//      		Slastchar=*(Gfilebuff+MAXLINEDATA2);	//save for next read//~v10eR~
        		Slastchar=*(Gfilebuff+Slinewidth);	//save for next read//~v10eI~
                Ssplitswb=1;	                                   //~v108I~
            }                                                      //~v108I~
		}                                                          //~v107I~
        else						//text mode                    //~v10yI~
        {                                                          //~vaj0I~
		    Slasteol=(UCHAR)eolid;         //latest line eol       //~v10yR~
    	 	if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))  //recfm=V     //~vaj0I~
            {                                                      //~vaj0I~
//          	Slasteol=0;                                        //~vaj0I~//~vanbR~
                mflinetype=eolid;                                  //~vaj0R~
                if (rc==UFGETS_RCMFH2)                             //~vaj0I~
                {                                                  //~vaj0I~
                    Ppfh->UFHvfmt=UFGETS_VFMT_MFH2;                //~vaj0R~
                    rc=0;                                          //~vaj0I~
                }                                                  //~vaj0I~
                else                                               //~vaj0I~
                if (rc==UFGETS_RCMFH4)                             //~vaj0I~
                {                                                  //~vaj0I~
                    Ppfh->UFHvfmt=UFGETS_VFMT_MFH4;                //~vaj0R~
                    rc=0;                                          //~vaj0I~
                }                                                  //~vaj0I~
                else                                               //~vancI~
                if (rc==UFGETS_RCMFH2MORE)                         //~vancI~
                {                                                  //~vancI~
                    Ppfh->UFHvfmt=UFGETS_VFMT_MFH2;                //~vancI~
                    rc=UFGETS_MORE;                                //~vancI~
                }                                                  //~vancI~
                else                                               //~vancI~
                if (rc==UFGETS_RCMFH4MORE)                         //~vancI~
                {                                                  //~vancI~
                    Ppfh->UFHvfmt=UFGETS_VFMT_MFH4;                //~vancI~
                    rc=UFGETS_MORE;                                //~vancI~
                }                                                  //~vancI~
//          	Slasteol=eolid=0;                                  //~vaz1R~
            	Slasteol=(UCHAR)(eolid=0);                         //~vaz1I~
            }                                                      //~vaj0I~
        }                                                          //~vaj0I~
    	if (!eolid)	//no end of line(at end of file)               //~v103I~
        	noeolsw=1;                                             //~v103I~
        else                                                       //~v10uI~
            Seolid=(char)((int)Seolid|eolid);   //chk unix or pc or mix//~v10uI~
        UTRACEP("%s:Seolid=%d,eolid=%d\n",UTT,Seolid,eolid);       //~vbBuI~
    }                                                              //~v09YI~
  }                                                                //~v09YI~
  else  //text mode read                                           //~v10YR~
  {                                                                //~v09YI~
//  if (!fgets(Gfilebuff+Ssplitsw,MAXLINEDATA+2,Phfile))//null if error/ eof//~v09ZR~
//  if (!fgets(Gfilebuff+Ssplitsw,MAXLINEDATA2+2-Ssplitsw,Phfile))//null if error/ eof//~v10eR~
//#ifdef ARMXXE                                                    //~vby8R~
//    if (PFH_ISDOCUMENT(Ppfh))                                    //~vby8R~
//    {                                                            //~vby8R~
//        if (!ufile_fgetsDoc(Gfilebuff+Ssplitsw,(int)(Slinewidth+2-Ssplitsw),Phfile))//~vby8R~
//        {                                                        //~vby8R~
//            UTRACEP("%s:after ufile_fgetsDoc rc=%d\n",UTT,rc);   //~vby8R~
//            return -1;      //eof                                //~vby8R~
//        }                                                        //~vby8R~
//        return 0;                                                //~vby8R~
//    }//                                                          //~vby8R~
//#endif                                                           //~vby8R~
    if (!fgets(Gfilebuff+Ssplitsw,(int)(Slinewidth+2-Ssplitsw),Phfile))//null if error/ eof//~v10eR~
    {                                                              //~v50QI~
    	if (ferror(Phfile))                                        //~v09YI~
		{
//  		uerrmsg("%s read error",0,Pfilename);                  //~v08qR~
            ufileapierr("read by fgets",Pfilename,errno);          //~v08qR~
			return 8;
		}
		else
			return -1;		//eof
    }//                                                            //~v50QI~
	len=(int)strlen(Gfilebuff);			//read len
	if (*(Gfilebuff+len-1)=='\n')
    {                                                              //~v10YI~
		len--;						//drop 0a
        if (UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTPC))                 //~v10YI~
            eolid=2;                                               //~v10YI~
        else                                                       //~v10YI~
        	eolid=1;                                               //~v10YI~
    }                                                              //~v10YI~
    else                                                           //~v10YI~
        eolid=0;                                                   //~v10YI~
  }                                                                //~v09YI~
//  if (len>MAXLINEDATA2)                                          //~v10eR~
//  if ((UINT)len>Slinewidth)                                      //~vaz1R~
    if (len>Slinewidth)                                            //~vaz1I~
    {                                                           //~5103I~
      if (!Ssplit1stsw)	                                           //~v0alI~
      {                                                            //~v0alI~
      	Ssplit1stsw=1;                                             //~v0alI~
//  	uerrmsg("From record-no %d,too long(max %d) record exist", //~v10yR~
//  			"第 %d レコード以降,制限長(%dバイト)を越えるレコードがあります",//~v10yR~
//  	uerrmsgcat(";Line split at %d,(width=%d)",                 //~v41qR~
//  				";%d 行目,行分割(行幅=%d)",                    //~v41qR~
//  					Pline,MAXLINEDATA2);                       //~v10eR~
//  					Pline,Slinewidth);                         //~v41qR~
       if (!nosplitmsgsw)                                          //~v41qR~
        filesplitmsg(Pline);                                       //~v41qR~
	  }	                                                           //~v0alI~
#ifdef UTF8SUPPH                                                   //~va00I~
	  mbsplitlen=filembsplitchk(copyutf8sw,Ppfh,Gfilebuff,len,Slinewidth);//~va00R~
      if (mbsplitlen>1)	//multibyte split                          //~va00I~
      {                                                            //~va00I~
		memcpy(Slastmbstr,Gfilebuff+len-mbsplitlen,(UINT)mbsplitlen);//~va00I~
        len-=mbsplitlen;                                           //~va00I~
        Ssplitsw=mbsplitlen;                                       //~va00I~
      }                                                            //~va00I~
      else                                                         //~va00I~
#endif                                                             //~va00I~
      {                                                            //~va00I~
//  	len=MAXLINEDATA2;                                          //~v10eR~
    	len=(int)Slinewidth;                                       //~v10eR~
        Ssplitsw=1;                                             //~5107I~
//      Slastchar=*(Gfilebuff+MAXLINEDATA2);	//save for next read//~v10eR~
        Slastchar=*(Gfilebuff+Slinewidth);	//save for next read   //~v10eI~
      }                                                            //~va00I~
    }                                                           //~5103I~
	else                                                        //~5107I~
    {                                                              //~vaj0I~
        Ssplitsw=0;                                             //~5107I~
    	if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))  //recfm=V         //~vaj0I~
        {                                                          //~vaj0I~
            if (rc==UFGETS_MORE)                                   //~vaj0I~
                Ssplitsw=1;                                        //~vaj0I~
        }                                                          //~vaj0I~
    }                                                              //~vaj0I~
	lineoffs=Slineoffs;                                            //~v10YI~
//  lineendoffs=Slineoffs+len+eolid;                               //~v50tR~
    lineendoffs=Slineoffs+len+EOLID2LEN(eolid);                    //~v50tR~
    Slineoffs=lineendoffs;             //next line top             //~v10YM~
	if (!Ppplh)		//plh alloc not required                       //~v08lR~
        return 0;                                                  //~v08lI~
    if (Sgetchkoffs)    //xrange start chk                         //~v10YI~
    {                                                              //~v10YI~
        if (Sgetchkoffs>=lineendoffs)                              //~v10YI~
        {                                                          //~v10YI~
        	if (Pline!=1)                                          //~v10YI~
            {                                                      //~v10YI~
	        	*Ppplh=0;		//sign of skip                     //~v10YR~
    	        return 0;                                          //~v10YR~
			}                                                      //~v10YI~
        }                                                          //~v10YI~
        else                                                       //~v10YI~
			if (Sgetchkoffs>=lineoffs)	//boundary record          //~v10YR~
        		Sgetchkoffs=lineoffs;	//notify to caller         //~v10YR~
    }                                                              //~v10YI~
	plh=filealloclh(ULHTDATA,len);
    if (!plh)                                                      //~v08qI~
//  	uerrmsg("Storage shortage at line %ld",                    //~v09YR~
//  			"%ld 行目で記憶域不足",                            //~v09YR~
//  			Pline);                                            //~v09YR~
		filelinemallocerr(Pline);                                  //~v09YI~
    UALLOCCHK(plh,UALLOC_FAILED);//return when storage shortage //~v04dI~
	plh->ULHlinenor=Pline;
	plh->ULHoffs=lineoffs;                                         //~v10YR~
//  plh->ULHeolid=(UCHAR)eolid;                                    //~v50tR~
    plh->ULHeolidid=(UCHAR)eolid;                                  //~v50tI~
    plh->ULHeolid=(UCHAR)EOLID2LEN(eolid);                         //~v50tR~
//  plh->ULHmflinetype=mflinetype;                                 //~vaz1R~
    plh->ULHmflinetype=(UCHAR)mflinetype;                          //~vaz1I~
    UTRACEP("%s:lineno=%d,len=%d,eolid=%d,eolidid=0x%02x,mflinetype=%02x\n",UTT,Pline,len,plh->ULHeolid,plh->ULHeolidid,mflinetype);//~vbBuR~
	memcpy(plh->ULHdata,Gfilebuff,(UINT)len);
	if (Ssplitsw)                                               //~5107I~
		UCBITON(plh->ULHflag2,ULHF2SPLIT1);                     //~5107I~
	if (prevsplit)                                              //~5107I~
		UCBITON(plh->ULHflag2,ULHF2SPLIT2);                     //~5107I~
	if (noeolsw)                                                   //~v103I~
		UCBITON(plh->ULHflag4,ULHF4NOEOL);//skip eol set at eof    //~v103I~
	*Ppplh=plh;
//  if (Prbmode)                                                   //~v0a1R~
//  {                                                              //~v0a1R~
//      if (memchr(plh->ULHdata,0,(UINT)plh->ULHlen))              //~v0a1R~
//  		if (filechktabdbcs(plh)==UALLOC_FAILED)                //~v0a1R~
//  			return filelinemallocerr(Pline);                   //~v0a1R~
//  }                                                              //~v0a1R~
	return 0;
}//filegetline
//*******************************************************          //~v41qR~
//*split warning msg                                               //~v41qR~
//*parm  :lineno                                                   //~v41qR~
//*return:none                                                     //~v41qR~
//*******************************************************          //~v41qR~
void filesplitmsg(long Pline)                                      //~v41qR~
{                                                                  //~v41qR~
//***************************                                      //~v41qR~
    uerrmsgcat(";Line split at %d,(width=%d)",                     //~v41qR~
    			";%d 行目,行分割(行幅=%d)",                        //~v41qR~
    				Pline,Slinewidth);                             //~v41qR~
}//filesplitmsg                                                    //~v41qR~
//*******************************************************          //~vaz1I~
//*rc:1 fseek done,4:err,0 not seek done                           //~vaz1I~
//*******************************************************          //~vaz1I~
int seektostartpos(int Popt,PUFILEH Ppfh,FILESZT Pxranges)         //~vaz1I~
{                                                                  //~vaz1I~
	int rc;                                                        //~vaz1I~
//*************************                                        //~vaz1I~
	if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                        //~vaz1R~
    	return 0;                                                  //~vaz1R~
	if (Popt & STSPO_READBIN)     //chk optbin file                //~vazrI~
    	if (!(Slineoffs && Slineoffs<Pxranges))	//not initially seeked and after 1st read//~vazrI~
	    	return 0;                                              //~vazrI~
    if (FILEISREMOTE(Ppfh))                                        //~vaz1I~
#ifdef W32                                                         //~vaz1I~
      if(!UCBITCHK(Ppfh->UFHflag13,UFHF13REMOTEUNC))               //~vaz1I~
#endif                                                             //~vaz1I~
    	return 0;                                                  //~vaz1R~
	rc=fileseek(Ppfh,Pxranges,SEEK_SET);                           //~vaz1I~
    if (rc)                                                        //~vaz1I~
    	return 4;                                                  //~vaz1I~
    UTRACEP("seektostartpos pos=%s\n",ueditFILESZ(0,0/*buff*/,0/*buffsz*/,"0x%$x",Pxranges));//~vaz1R~
    ufgets_setcurpos(0,Pxranges);                                  //~vaz1R~
    Slineoffs=Pxranges;	//reffered at filegetline                  //~vaz1R~
    return 1;                                                      //~vaz1I~
}//seektostartpos                                                  //~vaz1I~
//*******************************************************          //~vazdR~
//*rc:4 issued confirmation,1:confirmed,0:not large                //~vazdR~
//*******************************************************          //~vazdR~
int chklargefile(PUFILEH Ppfh)                                     //~vazdR~
{                                                                  //~vazdR~
	FILESZT opensz,xranges,xrangee;                                //~vazdR~
    int rc=0,opt;                                                  //~vazdR~
    char fszwk1[32],fszwk2[32],fszwk3[32],*pwksz;                  //~vazdR~
//*************************                                        //~vazdR~
//#ifdef W32                                                       //~vazdI~
//    if (FILEISREMOTE(Ppfh) && !UCBITCHK(Ppfh->UFHflag13,UFHF13REMOTEUNC))//remote output by rep/cre/save//~vazdR~
//#else                                                            //~vazdI~
//    if (FILEISREMOTE(Ppfh))                                      //~vazdI~
//#endif                                                           //~vazdI~
//        return 0;                                                //~vazdR~
    if (!Glargefilesz)	//no chk if 0                              //~vazdI~
    	return 0;                                                  //~vazdI~
	opensz=Ppfh->UFHsize;                                          //~vazdR~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4XRANGE))   //after adjusted by tail proc//~vazdR~
    {                                                              //~vazdR~
        xranges=Ppfh->UFHslinepos;   //cmd line parm value         //~vazdR~
        xrangee=Ppfh->UFHelinepos;   //one of them is not 0        //~vazdR~
        if (!xrangee)                                              //~vazdI~
        	xrangee=opensz;                                        //~vazdI~
        opensz=xrangee-xranges;                                    //~vazdR~
	}                                                              //~vazdR~
    if (opensz>Glargefilesz)                                       //~vazdR~
    {                                                              //~vazdR~
    	if (!scrconfirmchk(GSCRCONFLARGEFILE))   //not yet confirmed//~vazdR~
        {                                                          //~vazdR~
			pwksz=ufileeditsz(0,opensz,fszwk1),//decimal KB/MB if over 4GB//~vazdI~
            pwksz+=strspn(pwksz," ");                              //~vazdR~
            opt=UEFS_KMGT;     //shrink to KB,MB,GB,TB             //~vazdR~
           	uerrmsg("Too large open size(%s>%s=warning threshold by ini file(default=%s)), hit \"Enter\" to continue, \"Esc\" to cancel.",//~vazdR~
                	   	"ファイルオープンサイズ(%s)がini ファイルの警告サイズ(%s(省略値=%s))以上です。続行する場合は \"Enter\", 取り消しは\"Esc\"。",//~vazdR~
						pwksz,                                     //~vazdR~
						ueditFILESZ(opt,fszwk2,sizeof(fszwk2),"0x%$x",Glargefilesz),//~vazdR~
						ueditFILESZ(opt,fszwk3,sizeof(fszwk3),"0x%$x",LARGEFILESZ));//~vazdR~
        	rc=4;                                                  //~vazdR~
        }                                                          //~vazdR~
        else                                                       //~vazdR~
        	rc=1;                                                  //~vazdR~
    }                                                              //~vazdR~
	UTRACEP("chklargefile rc=%d,filesz=%s,limit=0x%s\n",rc,ufileeditsz(0,opensz,0),ueditFILESZ(0/*opt*/,0/*outbuff*/,0/*buffsz*/,"%$x",Glargefilesz));//~vazdR~
    return rc;                                                     //~vazdR~
}//chklargefile                                                    //~vazdR~
//**************************************************************** //~vbi3I~
//*allocate plh by cpu8                                            //~vbi3I~
//**************************************************************** //~vbi3I~
PUSCMD filegetcmdstack(int Popt,PUFILEH Ppfh,int Pline,PULINEH *Ppplh,PUSCMD Ppsc)//~vbi3R~
{                                                                  //~vbi3I~
	PUSCMD psc;			//stack cmd                                //~vbi3I~
	PULINEH plh;                                                   //~vbi3I~
    int opt;                                                       //~vbi3R~
    int fmt,len,lenu8;                                             //~vbi3I~
#ifdef W32UNICODE                                                  //~vbi3I~
    char wkstripu8[_MAX_PATHU8];                                   //~vbi3I~
#endif                                                             //~vbi3I~
	char *pc;                                                      //~vbi3R~
	UCHAR *pu8;                                                    //~vbi3I~
    int swcmdu8=0;                                                 //~vbi3R~
//****************************                                     //~vbi3I~
    if(psc=funcgetcmdstack(Popt,Ppsc,&pc,&len,&fmt),!psc)          //~vbi3R~
    	return 0;                                                  //~vbi3I~
#ifdef W32UNICODE                                                  //~vbi3I~
    if (fmt==2)   //ud fmt                                         //~vbi3I~
    {                                                              //~vbi3I~
		fsubw_stripUDCT(0,pc,len,wkstripu8,sizeof(wkstripu8),NULL/*wkfpathct2*/,0/*sizeof(wkfpathct2)*/,&lenu8);//~vbi3I~
        pc=wkstripu8;                                              //~vbi3I~
		len=lenu8;                                                 //~vbi3I~
        swcmdu8=1;                                                 //~vbi3I~
    }                                                              //~vbi3I~
    else                                                           //~vbi3I~
#endif                                                             //~vbi3I~
	if (fmt==1)	//lc only                                          //~vbi3I~
	{                                                              //~vbi3I~
        opt=XEUTFCVO_ERRREPQM|XEUTFCVO_CPU8;                       //~vbi3R~
    	xeutf_cvdata(opt,pc,len,&pu8,&lenu8);                      //~vbi3R~
        pc=(char*)pu8;                                             //~vbi3R~
		len=lenu8;                                                 //~vbi3R~
    }                                                              //~vbi3I~
    else //fmt==0:  lc and u8,returned u8                          //~vbi3I~
    {                                                              //~vbi3I~
		swcmdu8=1;                                                 //~vbi3I~
    }                                                              //~vbi3I~
	plh=filealloclh(ULHTDATA,len);                                 //~vbi3R~
    if (!plh)                                                      //~vbi3I~
    {                                                              //~vbi3I~
		filelinemallocerr(Pline);                                  //~vbi3I~
    	return 0;                                                  //~vbi3R~
    }                                                              //~vbi3I~
	plh->ULHlinenor=Pline;                                         //~vbi3I~
	plh->ULHuscentryno=psc->USCentryno;	//searchkey at s/x cmd     //~vbi3I~
	memcpy(plh->ULHdata,pc,(UINT)len);                             //~vbi3R~
	UCBITON(plh->ULHflag4,ULHF4NOEOL);                             //~vbi3I~
    if (swcmdu8)                                                   //~vbi3R~
		UCBITON(plh->ULHflag6,ULHF6CHLCPU8CMD);                    //~vbi3R~
	*Ppplh=plh;                                                    //~vbi3I~
    return psc;                                                    //~vbi3I~
}                                                                  //~vbi3I~
//**************************************************************** //~vbi3I~
// fileloadchl                                                     //~vbi3I~
//*rc   :0-ok 4:file load err or UALLOC_FAILED                     //~vbi3I~
//**************************************************************** //~vbi3I~
int fileloadchl(int Popt,PUCLIENTWE Ppcw,char *Ppfile,char *Pfullpath,PUFILEH *Pppfh)//~vbi3I~
{                                                                  //~vbi3I~
#define CHL_HDR	    "********** Top of Cmd History "               //~vbi3R~
#define CHL_TRAILER "********** End of Cmd History "               //~vbi3R~
#define CHL_LINENO "*******|"                                      //~vbi3R~
#define CHL_CMDPREFIX " cmdKey:"                                   //~vbi3I~
	int 	lineno;                                                //~vbi3R~
	PUFILEH pfh;                                                   //~vbi3I~
	ULINEH 	*plh;                                                  //~vbi3I~
	PULINEH *pplh,plhprev;                                         //~vbi3R~
	PUSCMD psc;			//stack cmd                                //~vbi3I~
	UCHAR 	*pc,*pc2;                                              //~vbi3R~
    int lnosuffix;                                                 //~vbi3I~
    int binopt=UFCFBROWSE;                                         //~vbi3I~
    int rc2;                                                       //~vbi3I~
//****************************                                     //~vbi3I~
    *Pppfh=pfh=UALLOCC(1,UFILEHSZ);                                //~vbi3R~
    UALLOCCHK(pfh,UALLOC_FAILED);                                  //~vbi3R~
    memcpy(pfh->UFHcbid,UFHCBID,4);     //acronym                  //~vbi3R~
    pfh->UFHopenctr=1;      //open ctr                             //~vbi3R~
    UCBITON(pfh->UFHflag,UFHFUPCTRREQ|UFHFUNDOCTRREQ);//next time updatectr up//~vbi3R~
    rc2=ufilesetfhfilename(pfh,Pfullpath);                         //~vbi3R~
    if (rc2)                                                       //~vbi3R~
        return 4;                                                  //~vbi3R~
    pfh->UFHopenctr=1;                                             //~vbi3R~
    UCBITON(pfh->UFHflag,UFHFWORKDIRFILE);//work dir file          //~vbi3R~
    pfh->UFHtype=UFHTCMDHIST;                                      //~vbi3R~
    strncpy(pfh->UFHalias,Ppfile,sizeof(pfh->UFHalias)-1);         //~vbi3R~
    pfh->UFHpathlen=getpathlen(pfh->UFHfilename,    //get path len //~vbi3R~
                                &pfh->UFHlevel,     //dir level    //~vbi3R~
                                0);//dir sw                        //~vbi3R~
    pfh->UFHmergin=MAXLINEDATA;                                    //~vbi3R~
    ueditNowFileTime(0,&pfh->UFHfiledate,&pfh->UFHfiletime);       //~vbi3I~
    if (Popt & CHLO_UTF8)                                          //~vbi3I~
    {                                                              //~vbi3I~
        UCBITON(pfh->UFHflag8,UFHF8UTF8);                          //~vbi3I~
        UCBITON(pfh->UFHflag10,UFHF10UTF8IE);                      //~vbi3I~
    }                                                              //~vbi3I~
    else                                                           //~vbi3I~
    {                                                              //~vbi3I~
        UCBITOFF(pfh->UFHflag8,UFHF8UTF8);                         //~vbi3I~
        UCBITOFF(pfh->UFHflag10,UFHF10UTF8IE);                     //~vbi3I~
    }                                                              //~vbi3I~
//top line                                                         //~vbi3I~
	lineno=0;                                                      //~vbi3I~
	lnosuffix=0;		//for split line                           //~vbi3I~
    plh=filealloclh(ULHTHDR,MAXCOLUMN);                            //~vbi3R~
    UALLOCCHK(plh,fileplhfail(pfh));//return when storage shortage //~vbi3R~
    pc=plh->ULHdata;                                               //~vbi3R~
    memset(pc,'*',MAXCOLUMN);       //clear by '*'                 //~vbi3R~
    memcpy(pc,CHL_HDR,sizeof(CHL_HDR)-1);   //except last null     //~vbi3R~
    pc2=CHL_CMDPREFIX CHL_CMDLIST " ";                             //~vbi3I~
    memcpy(pc+CHL_CMDLIST_POS,pc2,strlen(pc2));                    //~vbi3I~
    memcpy(plh->ULHlineno,CHL_LINENO,ULHLINENOSZ);                 //~vbi3R~
    UENQ(UQUE_END,&pfh->UFHlineque,plh);                           //~vbi3R~
//enq file data                                                    //~vbi3I~
    psc=0;                                                         //~vbi3R~
	for (plhprev=plh;;plhprev=plh)	//until eof/err                //~vbi3R~
	{                                                              //~vbi3I~
		++lineno;                                                  //~vbi3I~
        pplh=&plh;                                                 //~vbi3I~
    	if(psc=filegetcmdstack(Popt,pfh,lineno,pplh,psc),!psc)     //~vbi3R~
			break;                                                 //~vbi3I~
        UTRACEP("%s:ENQ plh=%p\n",UTT,plh);                        //~vbi3I~
		plh->ULHsuffix=lnosuffix;	//split suffix                 //~vbi3I~
		UENQENT(UQUE_AFT,plhprev,plh);                     //~5819I~//~vbi3I~
	}//until eof                                                   //~vbi3I~
//end of line                                                      //~vbi3I~
    plh=filealloclh(ULHTHDR,MAXCOLUMN);                            //~vbi3R~
    UALLOCCHK(plh,fileplhfail(pfh));//return when storage shortage //~vbi3R~
    plh->ULHlinenor=lineno;                                        //~vbi3R~
    pc=plh->ULHdata;                                               //~vbi3R~
    memset(pc,'*',MAXCOLUMN);       //clear by '*'                 //~vbi3R~
    memcpy(pc,CHL_TRAILER,sizeof(CHL_TRAILER)-1);   //except last null//~vbi3R~
    memcpy(plh->ULHlineno,CHL_LINENO,ULHLINENOSZ);                 //~vbi3R~
    UENQ(UQUE_END,&pfh->UFHlineque,plh);                           //~vbi3R~
    filechkutf8encoding(0,Ppcw,binopt,pfh);	//chk each line utf8 code(IE mode)//~vbi3I~
    filesetlocaleid(pfh);    //set locale id on hdr line           //~vbi3I~
	return 0;                                                      //~vbi3I~
}//fileloadch                                                      //~vbi3I~
