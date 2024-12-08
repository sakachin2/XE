//*CID://+vbz2R~:                             update#=  393;       //+vbz2R~
//*************************************************************
//*xedcmd.c                                                     //~v041R~
//* drive,cd,xdelete,rmdir,mkdir,rename,attrib,xcopy,xmove      //~v05oR~
//*************************************************************
//vbz2:230827 del cmd issue warning "it may be remain dir entry" whel delctr=0//+vbz2I~
//vbz1:230817 ARM:correct errmsg for attrib.(DOS is out of consern)//~vbz1I~
//vbyg:230508 correct errmsg;distinguish for dlcmd and dcmd        //~vbygI~
//vbyf:230502 (ARM) "//" option required to delete sortpath root(such as //Axe)//~vbyfI~
//vby6:230402 (ARM)adjust by4; go around by shortname and change to uri at ulib(ufile1l)//~vby6I~
//vby4:230402 (ARM)shared resource support by //shareName defined by SP(ShortPath) cmd.//~vby4I~
//vbri:200831 (Bug)editfattr overflow work when UFEA_DIR option from dcmdattrchange//~vbriI~
//vb7n:170117 move filename position to last on errmsg for longname//~vb7nI~
//vb7g:170114 (Win)longname support(expand buffsz)                 //~vb7gI~
//vb76:170103 add "use force option" to readonly/toolongname err msg//~vb76I~
//vb74:161220 Gtk3 warning                                         //~vb74I~
//vb71:161212 Win10 compiler warning                               //~vb71I~
//vb0a:150315 (BUG)others for \\.\(driveid)                        //~vb0aI~
//vb09:150315 (BUG)wildfunc attrchange was treated as FTP          //~vb09I~//~vb0aR~
//vb08:150314 avoid \\.\ is displayed on errmsg                    //~vb08I~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vb05:150313 (BUG)others for \\.\(inisave cur dir)                //~vb05I~
//vawv:140610 (W32UNICODE)for ftp,enclose utf8 membname on UDHname //~vawvI~
//vaw6:140531 (W32UNICODE) by vavQ, enable to specify unicode for other language filename of dcmd's//~vaw6I~
//vavK:140403 copy /c with rename(wildcard rename,curentry member was renamed in the same target dirname)//~vavKI~
//van5:131129 (LNX)dlcmd delete;not reject but confirm             //~van5I~
//van2:131127 support deletion of invalid(wildcard) name entry on dir list//~van2I~
//vaiA:130625 copy/move warning by Gufile_opt                      //~vaiAI~
//vaiy:130623 XCO -Lt(L{-|[t]M-} option to copy slink target if target is file(go forward if taget is slink)//~vaiyI~
//vaiv:130610 (LNX)slink copy like as W32                          //~vaivI~
//vait:130610 Junction/symlink support                             //~vaitI~
//            dcmd.c:xcopy bypass slink option to avaoid privilege err /L-(skip) /L(do copy,default)//~vaitI~
//                   -Lm- (bypass slink err chk)                   //~vaivI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120608 (VC6)Bug found by C4701                              //~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vac8:120323 (Axe)attr set partially msg                          //~vac8I~
//vac2:120204 (SMB)target:windows consideration                    //~vac2I~
//vaa4:110520 ANDROID Send command/dlcmd                           //~vaa4I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va0f:090723 no propagation to target dir for slink,so no need to del confirmation//~va0fI~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v781:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v781I~
//v77c:071220 update current dir on utility panel when CD changed  //~v77cI~
//v72J:061209 allow local fmd input by preceding : when remote rsh mode cmd panel//~v72JI~
//v728:061119 3270:Attr dcmd/lcmd is not supported for tso         //~v728I~
//v71y:061024 3270:support also "cd *"                             //~v71yI~
//v71m:061019 add copy/move command bin option                     //~v71mI~
//v71i:061017 utilize CurrentDir to specify membername only        //~v71iI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71e:061011 3270:Rename/delete support                           //~v71eI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v70q:060823 SUB cmd;support * as 2nd operand (pass current file to the 1st operand cmd verb)//~v70qI~
//v663:050816 change sbreviation of AT cmd,assign & to SPAWN       //~v663I~
//v656:050726 (XXE)xxe support;WXP cmd                             //~v656I~
//v646:050617 copy/move d(l)cmd wild path support                  //~v646I~
//v63f:050429 (BUG)XAPP reject /S as xej.doc;so change help        //~v63fI~
//v630:050426 grep support  as dos cmd(for edit screen flag line and search by rfind for *L)//~v630I~
//v60g:050124 skip override option to xcopy/xmove; /r- or /y-      //~v60gI~
//v608:050110 (FTP)ronly chk is not avail because userid of remote is unknown//~v608I~
//            so bypass ronlychk for performance by setting skipronly//~v608I~
//v607:050110 delcmd ronly chk is duplicated(correct for ftp del performance)//~v607I~
//v59L:041121 (BUG) ENV var may large for PATH etc                 //~v59LI~
//v59F:041121 chng cmd name,exp/xen-->set/env and issue dos cmd when no opd under cmd panel//~v59FI~
//v59E:041120 (WXE)pass env to sub process xesyscmd.exe            //~v59EI~
//v59C:041120 xen command. xenv {< file| var[=[value]]}            //~v59CI~
//v59w:041114 xmove/xcopy cmd:textmode option                      //~v59gI~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v59f:041107 (BUG)attr change not availe for remotefile           //~v59fI~
//v58n:040920 xcopy/xmove /d option(replace old filetime only)     //~v58nI~
//v58g:040905 cd cmd:support wildcard                              //~v58gI~
//v57q:040530 reject /c for append                                 //~v57qI~
//v57p:040530 AP is alias of append cmd                            //~v57pI~
//v57n:040529 (BUG)XMOve helpmsg;replace option is supported       //~v57nI~
//v579:040516 (WXE:BUG)cmd svr should set CD effect for cmd grep etc//~v579I~
//v575:040511 /r option is no meaningfull for xappend cmd,reject it//~v575I~
//v572:040425 xcopy;-c option:create srcdir name in target dir     //~v572I~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v54t:040112 DEL cmd, issue help msg when no opd                  //~v54iI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54j:040105 (FTP)use ROOTDIR3(remote root support) for ROOTDIR2  //~v54iI~
//v54i:040105 (FTP)cd cmd support                                  //~v54iI~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v53R:031103 (UNX:BUG)disket delete skipped when root dir         //~v53RI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v53QI~
//v51v:030615 add SPAwn cmd(ASYNC DOS cmd) for explorer kick       //~v51vI~
//v509:021207 uchdir interface changed by udirwalk performance tuning//~v509I~
//v49j:020807 (BUG)ufileeditname dbcs support                      //~v49jI~
//v49g:020713 (UNX)list special file also to dir list(fifo.socket,char/blk device)//~v49gI~
//v48m:020516 (AIX)mdos disk not supported rmdir                   //~v48mI~
//v48b:020429 (UNX)rootdir chk for also mdos disk                  //~v48bI~
//v48a:020429 (UNX)a: support(cd to the drive),but meaning is cd to root//~v48aI~
//v489:020429 (UNX)cd(mcd) support for mdosdisk                    //~v489I~
//v488:020427 (UNX:BUG)dlcmd .(cd) fail for mdos disk              //~v488I~
//v487:020427 (BUG)for xdd root,msg is not found;send root is not processed//~v487I~
//v486:020427 (BUG)append msg(english) err                         //~v486I~
//v484:020427 (BUG)missing last null for attr chng msg             //~v484I~
//v47F:020323 display curr attr when opdno=1 of attr cmd           //~v47FI~
//v47E:020323 (UNX:BUG) ugs bit cleared by 3 octal digit attr chmod//~v47EI~
//v47D:020323 (UNX) msg issue that chmod is not effective for mounted dos fat//~v47DI~
//v47C:020323 disket support;mkdir,rmdir,attrib                    //~v47CI~
//v45J:011228 (UNX)add -n(not -p:preserve file attr) for xcopy     //~v45JI~
//v45H:011228 allow move on existing file                          //~v45HI~
//v42q:011008 attrib changed s-->u(setuid)                         //~v42qI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v21p:010204 LINUX support:no driveid on fullpath                 //~v21pI~
//v212:001126 LINUX support:chng attr cmd help sSGt -->sSgt.       //~v212I~
//v20h:001015 LINUX support("*"(all member) confirmation           //~v20hI~
//            for rename,xcopy,xmove,attribute,xprint(not edit screen only)//~v20hI~
//v209:000930 LINUX support(same format mkdir mode parm as attr cmd)//~v209I~
//v208:000930 add chmod cmd(also for other platform)               //~v208R~
//v207:000930 attrib cmd help                                      //~v207I~
//v206:000930 attrib cmd parm pos chng;attr is first and then follow files)//~v206R~
//v204:000930 LINUX support(for 4byte attr,UCBITxx is invalid)     //~v203I~
//v203:000930 LINUX support(new attr specification)                //~v203I~
//v201:000929 LINUX support(mkdir -mmode parm)                     //~v201I~
//v19Q:000927 copy/move "/" flag is from 3rd opd                   //~v19HI~
//v19H:000925 LINUX support(for attr cmd filename is not first opd;"/" of 1st is flag)//~v19HI~
//v19D:000925 LINUX support(command flag prefix is mainly '-')     //~v19DI~
//v19t:000923 LINUX support(cmd PWD support)                       //~v19tI~
//v19c:000904 LINUX support(attr size,1-->4)                       //~v19cI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v196:000902 LINUX support(drop drive func;uchdrive/ugetdrive)    //~v196I~
//v13i:991029 inhibit /s for append because OS/2 rc=5(access_denied) when//~v135I~
//            append to dir.                                       //~v135I~
//v13e:991023 copy/append/move target file change from wild card to specific//~v13eI~
//v135:990911 allow a: b: as a:*.* b:*.* for xdd/del               //~v135I~
//v134:990911 for new xddsub(Selcet option support);deney /S for xe to avoid//~v134I~
//            key input.                                           //~v134I~
//v11P:990904 (BUG of 11J)dlcmd copy fail if dirlist is by wild card//~v11PI~
//v11M:990828 dcmd xprint;filename=* should be current status(updated).//~v11MI~
//v11L:990828 protect source=* for rename/attr/xcopy/xmove,warning to use *.*//~v11LI~
//v11K:990828 *\ support for sorce file of mkdir/rmdir/cd          //~v11KI~
//v11J:990822 dcmd copy/move target wild card support by ulib      //~v11JI~
//            for the case of source wild card.del v11G.           //~v11JI~
//v11H:990822 *\ support for sorce file of xcopy/xmove/append/rename/attr/del/xdd//~v11HI~
//v11G:990822 wild card target support for lcmd/dcmd copy/move(append)//~v11GI~
//v11F:990822 real name is not returned when rename wild card source//~v11FI~
//v11y:990821 support /R option to restore previous default drv/directory//~v11yI~
//v11x:990821 support "CD *";set to current file directory         //~v11xI~
//v11t:990813 rename target wild card support                      //~v11tI~
//v0k2:980920 use ueditfattr for dirattrstr                        //~v0k2I~
//v0ia:980530 add APPend cmd(avail by also CAP Alt+h)              //~v0iaI~
//            avail for also file(dcmd)                            //~v0iaI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v09a:970503:space imbedding filename support(last space is not supported)//~v09aI~
//            -dlcmd "a":ignore " " attr specification(dcmd.c)     //~v09aI~
//            -dlcmd "."/cmd chdir:chk parseout parm(dcmd.c,dlcmd2.c)//~v09aI~
//v095:970405:DPMI version                                         //~v095I~
//            -structure init type chk(0 for char arry is err)     //~v095I~
//v08m:961123:cmd len chk for dos                                  //~v08mI~
//v085:961024:W95 VC                                               //~v085I~
//v07l:960713:(BUG)also for other than PATHLEn(strpbrk,strchr etc) //~v07lI~
//v06G:960421:(BUG of v06D)operand dropped                         //~v06GI~
//v06D:960407:accept not found cmd as DOS cmd when menu 6 screen   //~v06DI~
//v06n:960320:menu option 6(cmd) support                              //~v06nI~
//v062:960217:get togeter > and >> to >(display child shell)    //~v062I~
//v061:960211:SHELL cmd(CMD,COM,>>)                             //~v061I~
//v060:960204:add dir lcmd "z","0"(undeletable delete)          //~v060I~
//v05Y:960203:add /s option as default to dlcmd copy            //~v05YI~
//v05W:960203:attrib cmd "/" option support(set attr)           //~v05WI~
//v05R:960121:rmdir/file del by all xdd for read only chk       //~v05RI~
//v05Q:960121:xdd force option for move inter-drive,delete undel save at term//~v05QI~
//            dcmd.c dlcmd4 dcmd.h                              //~v05RR~
//v05O:960120:copy/move cmd *\(same as source) / **\(parent of source) support//~v05RR~
//v05u:951202:undelete dlcmd(rename when delete)                //~v05uI~
//v05o:951125:dlcmd dir delete woth confirmation support        //~v05oI~
//v05n:951125:use native command when ">"                       //~v05nI~
//v05m:951123:xdd command(del dir)                              //~v05lI~
//v05l:951123:dos command verb change                           //~v05lI~
//v05k:951119:del dir confirm                                   //~v05kI~
//v05i:951114:xmove cmd                                         //~v05iI~
//v05g:951112:original name for original DOS command            //~v05iI~
//v05g:951112:original name for original DOS command            //~v05gI~
//v05b:951104:xcopy override option,accept also /Y              //~v05bI~
//v056:951015:general DOS command                               //~v056I~
//v051:951014:print dlcmd                                       //~v051I~
//v04i:951007:add DOS "copy"(same as xcopy)                     //~v04iI~
//v042:950916:xcopy  cmd                                        //~v041I~
//v041:950916:attrib cmd wild card support                      //~v041I~
//v03z:950916:attrib cmd wild card                              //~v03zR~
//v03z:950903:attrib cmd                                        //~v03zI~
//v03p:950820:dos command delete/rename                         //~v03pI~
//*950708 v020 new,dos cmd support                              //~v03pI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~v03pI~
#ifdef UNX                                                         //~v47EI~
	#include <sys/stat.h>                                          //~v47EI~
	#include <dirent.h>                                            //~van5I~
#endif                                                             //~v47EI~

#ifdef DOS
#else
    #ifdef W32                                                     //~v085I~
        #include <windows.h>                                       //~v781R~
        #include <dos.h>                                           //~v085I~
    #else                                                          //~v085I~
    #define INCL_BASE
    #define INCL_DOSFILEMGR                                     //~v041I~
    #include <os2.h>
    #endif                                                         //~v085I~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <uftp.h>                                                  //~v54iM~
#include <ufile1f.h>                                               //~v54iI~
#include <ufile2.h>                                             //~v05bR~
#include <ufile3.h>                                             //~v05bI~
#include <ufile5.h>                                                //~v11JR~
#include <uparse.h>                                                //~v0b2R~
#include <uedit2.h>                                                //~v0k2I~
#include <ustring.h>                                               //~v11HI~
#include <ucalc.h>                                                 //~v201I~
#include <ufemsg.h>                                                //~v487I~
#include <uproc.h>                                                 //~v579I~
#include <u3270.h>                                                 //~v717I~
#include <utrace.h>                                                //~v781I~
//#include <ufilew.h>                                                //~vb05I~//~vb06R~
#include <ufilew.h>                                                //~vb06I~
#ifdef WINCON                                                      //~v781I~
	#include <ukbd.h>                                              //~v781R~
	#include <ukbdw.h>                                             //~v781I~
#endif                                                             //~v781I~
                                                                   //~v201I~
#ifdef UNX                                                         //~v201I~
	#include <ufile1l.h>                                           //~van5I~
	#include <ufile2l.h>                                           //~v201I~
#endif //UNX                                                       //~v201I~

#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                             //~v05kI~
//#include "xecsr.h"                                            //~v05kR~
#include "xefunc.h"
#include "xefile.h"                                             //~v05oM~
#include "xedir.h"                                              //~v05oM~
#include "xedir2.h"                                             //~v05oM~
#include "xedcmd.h"
#include "xedcmd2.h"                                            //~v051I~
#include "xedcmd3.h"                                               //~v59CI~
#include "xepan.h"
#include "xesub.h"                                              //~v020I~
#include "xeerr.h"                                              //~v03pI~
#include "xedlcmd.h"                                            //~v05oM~
#include "xedlcmd2.h"                                           //~v05oI~
#include "xedlcmd4.h"                                           //~v05uI~
#include "xeini3.h"                                                //~v11yI~
#ifdef WXE                                                         //~v579I~
	#include "xesyscmd.h"                                          //~v579I~
#endif                                                             //~v579I~
#include "xefsubw.h"                                               //~vaw6I~
//****************************************************************
#define TEMP_ROOTFLAG  0x01   //temporary set for deny '/' as not flag start byte//~v19DI~
                                                                   //~v203I~
#ifdef UNX                                                         //~v204R~
    #define UFATTRCHK(attr,mask) ULBITCHK(attr,mask)               //~v204R~
    #define UFATTRON(attr,mask)  ULBITON(attr,mask)                //~v204R~
    #define UFATTROFF(attr,mask) ULBITOFF(attr,mask)               //~v204R~
#else  //!UNX                                                      //~v204R~
    #define UFATTRCHK(attr,mask) UCBITCHK(attr,mask)               //~v204R~
    #define UFATTRON(attr,mask)  UCBITON(attr,mask)                //~v204R~
    #define UFATTROFF(attr,mask) UCBITOFF(attr,mask)               //~v204R~
#endif //!UNX                                                      //~v204R~
#ifdef FTPSUPP                                                     //~v59fI~
    #define UFATTRCHK_REMOTE(attr,mask) ULBITCHK(attr,mask)        //~v59fI~
    #define UFATTRON_REMOTE(attr,mask)  ULBITON(attr,mask)         //~v59fI~
    #define UFATTROFF_REMOTE(attr,mask) ULBITOFF(attr,mask)        //~v59fI~
#endif                                                             //~v59fI~
                                                                   //~v203I~
#define LOCALCMDID ':'                                             //~v72JR~
//****************************************************************//~v05QI~
//#define SHELL_ID   '>'                                        //~v062R~
//#ifndef  UNX                                                     //~v48aR~
static UDCMDTBL  Sdcmddrive=
    {"A:"     ,""   ,dcmd_drive     ,UDCLINECMD,""};//special entry
//#endif //!UNX                                                    //~v48aR~
//static UDCMDTBL  Sdcmdsystem=                                 //~v062R~
//  {"SYS"     ,""  ,dcmd_system    ,UDCLINECMD};//special entry//~v062R~
static UDCMDTBL  Sdcmdtbl[]=
{
#define  SHELLENTRY 0       //entry no for system2 call         //~v061I~
    {"CMD"    ,"COM",dcmd_system    ,UDCLINECMD,""},//child shell        //~v06nR~
    {"CHD"    ,"CD" ,dcmd_cd        ,UDCLINECMD,""},               //~v03pR~
    {"PWD"    ,""   ,dcmd_pwd       ,UDCLINECMD,""},                  //~v19tI~
    {"DEL"    ,"DL" ,dcmd_xdelete   ,UDCLINECMD,""},               //~v05nR~
    {"XDD"    ,"DT" ,dcmd_xdd       ,UDCLINECMD,""},               //~v05mR~
    {"RMD"    ,"RD" ,dcmd_rmdir     ,UDCLINECMD,""},               //~v03zI~
    {"MKD"    ,"MD" ,dcmd_mkdir     ,UDCLINECMD,""},               //~v03zI~
    {"REN"    ,""   ,dcmd_rename    ,UDCLINECMD,""},               //~v03pR~
    {"ATT"    ,""   ,dcmd_attribute ,UDCLINECMD,""},               //~v03pI~
    {"CHM"    ,""   ,dcmd_chmod     ,UDCLINECMD,""},                  //~v208I~
//  {"XAP"    ,""   ,dcmd_append    ,UDCLINECMD,""},               //~v57pR~
    {"XAP"    ,"AP" ,dcmd_append    ,UDCLINECMD,""},               //~v57pI~
    {"XCO"    ,"CP" ,dcmd_xcopy     ,UDCLINECMD,""},               //~v05nR~
    {"XMO"    ,"MV" ,dcmd_xmove     ,UDCLINECMD,""},               //~v05nR~
    {"XPR"    ,"PR" ,dcmd_xprint    ,UDCLINECMD,""},               //~v05nR~
    {"SET"    ,"EXP",dcmd_xenv      ,UDCLINECMD,""},               //~v59FR~
    {"GRE"    ,""   ,dcmd_grep      ,UDCLINECMD,""},               //~v630I~
//  {"PRI"    ,"P"  ,dcmd_print     ,UDCLINECMD,""},               //~v05lR~
//#ifdef WXE                                                       //~v656R~
#ifdef WXEXXE                                                      //~v656I~
    {"WXP"    ,""   ,dcmd_wxp       ,UDCLINECMD,""},               //~v54yI~
#endif                                                             //~v54yI~
//  {"SPA"    ,""   ,dcmd_spawn     ,UDCLINECMD,""},               //~v663R~
#ifndef DOS                                                        //~v663I~
    {"SPA"    ,"&"  ,dcmd_spawn     ,UDCLINECMD,""},               //~v663I~
#endif                                                             //~v663I~
#ifdef ARM                                                         //~vaa4R~
    {"ASE"    ,"@"  ,dcmd_androsend ,UDCLINECMD,""},               //~vaa4I~
#endif                                                             //~vaa4R~
//  0       //stopper                                              //~v095R~
    {"","",0,0,""}//stopper full specification                        //~v095R~
};
#ifdef FTPSUPP                                                     //~v59gI~
	static UDCMDTBL  Sdcmdtbl_rlogin={"RSH"    ,""   ,dcmd_rlogin    ,UDCLINECMD,""};//~v59gR~
#endif                                                             //~v59gI~
static UCHAR Sappendsw=0;                                          //~v48mR~
static UCHAR Spwdsw;                                               //~v19tI~
#ifdef WINCON                                                      //~v781I~
	static UINT Ssvmodestdi,Ssvmodestdo;  //for restore after system() call//~v781R~
#endif                                                             //~v781I~
//****************************************************************
typedef struct _WCPARMATTR                                      //~v041I~
//#ifdef   UNX                                                     //~v53QR~
//               {ULONG wcattron;ULONG wcattroff;ULONG wcattr;} WCPARMATTR;//~v59fR~
                 {                                                 //~v59fI~
					ULONG wcattron;ULONG wcattroff;ULONG wcattr;   //~v59fI~
                    void *wcpuftph;                                //~v59fI~
				 } WCPARMATTR;                                     //~v59fI~
//#else //!UNX                                                     //~v53QR~
//                 {UCHAR wcattron;UCHAR wcattroff;UCHAR wcattr;} WCPARMATTR;//~v53QR~
//#endif//!UNX                                                     //~v53QR~
//****************************************************************//~v041I~
#ifdef UNX                                                         //~v201I~
int dcmdmkdir(PUCLIENTWE Ppcw,UCHAR *Pfullpath,ULONG Pmode);       //~v201I~
#else  //!UNX                                                      //~v201I~
int dcmdmkdir(PUCLIENTWE Ppcw,UCHAR *Pfullpath);                   //~v11KM~
#endif //!UNX                                                      //~v201I~
int dcmdrmdir(PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh);      //~v11KM~
void dcmddrawcdir(PUCLIENTWE Ppcw);
int dcmdxdelete(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UINT Pattrmask,//~v05RI~
            int Pxdelopt,int Pxddid,PUDIRLH Ppdh);              //~v05RI~
//int dcmdxdconf(PUCLIENTWE Ppcw,UCHAR *Pfullpath);                //~vaa0R~
int dcmdxdconf(int Popt,PUCLIENTWE Ppcw,UCHAR *Pfullpath);         //~vaa0I~
int dcmdxcopy(PUCLIENTWE Ppcw,UCHAR *Psource,UCHAR *Ptarget,int Popt,UINT Pattrmask);//~v041I~
int dcmddeleted(UCHAR *Pname);                                  //~v05QI~
int dcmdhelpcopy(void);                                            //~v13eR~
int dcmdhelpmove(void);                                            //~v13eR~
int dcmdhelpappend(void);                                          //~v13eI~
int dcmdattribhelp(char *Pcmdid);                                  //~v208I~
WILDAPPLYFUNC dcmdwildattr;                                     //~v041R~
//#ifdef WXE                                                       //~v59ER~
//    int dcmdsyscmdnotify(int Pcmdid,char *Pcmdstrid,char *Pcmdopd);//~v59ER~
//#endif                                                           //~v59ER~
                                                                   //~v781I~
//**************************************************************** //~v781I~
//!dcmdinit                                                        //~v781I~
//*retrn:rc                                                        //~v781I~
//**************************************************************** //~v781I~
int dcmdinit(int Popt)                                             //~v781I~
{                                                                  //~v781I~
#ifdef WINCON                                                      //~v781I~
	HANDLE  hstdi;                                                 //~v781R~
//**********************                                           //~v781I~
	hstdi=GetStdHandle(STD_INPUT_HANDLE);                          //~v781I~
    Ssvmodestdi=ugetconsolemode(0);                                //~v781R~
UTRACEP("dcmdconsolemode init 0(%x)=%x\n",hstdi,Ssvmodestdi);      //~v781R~
#endif                                                             //~v781I~
    return 0;                                                      //~v781I~
}//dcmdinit                                                        //~v781I~
//**************************************************************** //~v781I~
//!dcmdinit                                                        //~v781I~
//*retrn:rc                                                        //~v781I~
//**************************************************************** //~v781I~
int dcmdrestoreconsolemode(int Popt)                               //~v781I~
{                                                                  //~v781I~
	int rc=0;                                                      //~v781I~
#ifdef WINCON                                                      //~v781M~
	HANDLE  hstdi;                                                 //~v781R~
//******                                                           //~v781I~
	hstdi=GetStdHandle(STD_INPUT_HANDLE);                          //~v781R~
	rc=usetconsolemode2(0/*opt*/,0/*stdin*/,Ssvmodestdi,0/*out prev mode*/);//~v781R~
UTRACEP("setconsolemode rc=%d,lasterr=%d,setto=%x,after=%x\n",rc,GetLastError(),Ssvmodestdi,ugetconsolemode(0));//~v781R~
#endif                                                             //~v781M~
    return rc;                                                     //~v781R~
}//dcmdinit                                                        //~v781I~
//****************************************************************
//!func_dos
//* dos command
//*parm1:pcw(UCWparm:operand)
//*retrn:rc
//****************************************************************
int func_dos(PUCLIENTWE Ppcw)
{
//********************
#ifdef FTPSUPP                                                     //~v59gI~
    PUFILEC  pfc;                                                  //~v59gI~
    PUFILEH  pfh=NULL;                                                  //~v59gI~//~vaf9R~
#endif                                                             //~v59gI~
    UCHAR *popd,*pcmd,*pdelm=0;                                 //~v056R~
    UDCMDTBL *pdc;
    int cmdlen;                                                 //~v062R~
//************************************
#ifdef FTPSUPP                                                     //~v59gI~
	if (Ppcw->UCWmenuopt==PANMOCMD)                                //~v59gI~
    {                                                              //~v59gI~
		pfc=Ppcw->UCWpfc;                                          //~v59gI~
		pfh=pfc->UFCpfh;                                           //~v59gI~
    }                                                              //~v59gI~
#endif                                                             //~v59gI~
        pcmd=Ppcw->UCWparm;                                     //~v061R~
    if (!UCBITCHK(Ppcw->UCWflag,UCWFNODOSCMD))  //DOS cmd       //~v061I~
    {                                                           //~v061I~
//      if (!pcmd                                               //~v062R~
//      || (pos=(int)strspn(pcmd," "))==(int)strlen(pcmd))  //no char//~v062R~
//      {                                                       //~v062R~
//          uerrmsg("missing DOS command",                      //~v062R~
//                  "DOS コマンドの指定がありません");          //~v062R~
//          return funccmderr(Ppcw,4);                          //~v062R~
//      }                                                       //~v062R~
//      pcmd+=pos;                                              //~v062R~
//      if (*pcmd!=SHELL_ID)    //not shell call                //~v062R~
//      {                                                       //~v062R~
//          pdc=&Sdcmdsystem;                                   //~v062R~
//          popd=pcmd;                                          //~v062R~
//      }                                                       //~v062R~
//      else                                                    //~v062R~
//      {                                                       //~v062R~
#ifdef FTPSUPP                                                     //~v59gI~
          if (Ppcw->UCWmenuopt==PANMOCMD                           //~v59gI~
          &&  UCBITCHK(pfh->UFHflag6,UFHF6RLOGIN))                 //~v59gI~
			pdc=&Sdcmdtbl_rlogin;                                  //~v59gI~
          else                                                     //~v59gI~
#endif                                                             //~v59gI~
            pdc=Sdcmdtbl+SHELLENTRY;                            //~v061I~
            popd=pcmd;                                          //~v062I~
//          popd=pcmd+1;                                        //~v062R~
//      }                                                       //~v062R~
        if (popd)                                               //~v062I~
        popd+=strspn(popd," ");                                 //~v061I~
    }//dos cmd                                                  //~v061I~
    else                                                        //~v061I~
    {                                                           //~v061I~
        if (popd=strpbrk(pcmd," ,"),popd)       //search delm   //~v061R~
        {                                                       //~v061R~
//          cmdlen=(int)((ULONG)popd-(ULONG)pcmd);  //verb len  //~v061R~//~vafkR~
            cmdlen=(int)((ULPTR)popd-(ULPTR)pcmd);  //verb len     //~vafkI~
            pdelm=popd;                                         //~v061R~
            *popd++=0;                          //cut out cmd verb//~v061R~
            popd+=strspn(popd," ");             //search non space//~v061R~
        }                                                       //~v061R~
        else                                                    //~v061R~
            cmdlen=(int)strlen(pcmd);                           //~v061R~

        if (!cmdlen)                                               //~v08mI~
            return 4;                                              //~v08mI~
//*special drive command
        pdc=0;                                                     //~v48aI~
//#ifndef  UNX                                                     //~v48aR~
        if (cmdlen==2 && *(pcmd+1)==':')                        //~v061R~
        {                                                       //~v061R~
            pdc=&Sdcmddrive;                                    //~v061R~
            *pdc->UDCcmd=*pcmd;                                 //~v061R~
            popd=pcmd;  //parm to dcmd_drive                    //~v061R~
#ifdef  UNX                                                        //~v48aI~
            if (!MDOSDISKOK(pcmd))	//no mdosdik                   //~v48aI~
            	pdc=0;              //search cmd tbl               //~v48aI~
#endif  //UNX                                                      //~v48aI~
        }                                                       //~v061R~
//        else                                                     //~v48aR~
//#endif  //!UNX                                                   //~v48aR~
        if (!pdc)                                                  //~v48aI~
//*search func table by cmd string ***
            for (pdc=Sdcmdtbl;*pdc->UDCcmd;pdc++)   //all dcnd entry//~v061R~
            {                                                   //~v061R~
                if (!memicmp(pcmd,pdc->UDCcmd,3))               //~v061R~
                    break;                                      //~v061R~
                if (!stricmp(pcmd,pdc->UDCcmda))                //~v061R~
                    break;                                      //~v061R~
            }//all dcmd entry                                   //~v061R~

        if (!*pdc->UDCcmd)      //not found                     //~v061R~
        {                                                       //~v061R~
            if (Ppcw->UCWmenuopt==PANMOCMD)                        //~v06DI~
            {                                                      //~v06DI~
#ifdef FTPSUPP                                                     //~v59gI~
              if (UCBITCHK(pfh->UFHflag6,UFHF6RLOGIN))             //~v59gI~
               if (*pcmd==LOCALCMDID)                              //~v72JI~
                pdc=Sdcmdtbl+SHELLENTRY;                           //~v72JI~
               else                                                //~v72JI~
				pdc=&Sdcmdtbl_rlogin;                              //~v59gI~
              else                                                 //~v59gI~
#endif                                                             //~v59gI~
                pdc=Sdcmdtbl+SHELLENTRY;                           //~v06DI~
               	if (*pcmd==LOCALCMDID)                             //~v72JI~
                	pcmd++;                                        //~v72JI~
                popd=pcmd;                                         //~v06DI~
                popd+=strspn(popd," ");             //search non space//~v06DI~
//              pdelm=0;    //use fully                  //+v06DI~*//~v06GR~
            }                                                      //~v06DI~
            else                                                   //~v06DI~
            {                                                      //~v06DI~
            uerrmsg("\"%s\" is not a command verb",             //~v056R~
                    "\"%s\" は コマンドとして認識できません",   //~v056R~
                    pcmd);                                      //~v056R~
            return 4;                                           //~v056R~
            }                                                      //~v06DI~
        }                                                       //~v056I~
        if (pdelm)                                              //~v061I~
            *pdelm=' ';                                         //~v061I~
                                                                //~v061I~
    }//dos cmd or other                                         //~v061I~

    Ppcw->UCWparm=popd; //reset command parm                    //~v061R~
    return pdc->UDCfunc(Ppcw);
}//func_dos                                                     //~v056R~

//#ifndef UNX                                                      //~v48aR~
                                                                   //~v196I~
//****************************************************************
//!dcmd_drive
//* cur drive change
//*parm1:pcw(UCWparm:operand)
//*retrn:rc
//****************************************************************
int dcmd_drive(PUCLIENTWE Ppcw)
{
#ifdef UNX                                                         //~v48aM~
    Ppcw->UCWopdpot=Ppcw->UCWparm;	//parm to dcmd_cd              //~v48aI~
	return dcmd_cd(Ppcw);                                          //~v48aR~
#else                                                              //~v48aM~
    int rc;
    char wk[_MAX_PATH];                                         //~v03zI~
    char *pc;                                                      //~v7abI~
//********************
    if (!(rc=uchdrive(*(UCHAR*)Ppcw->UCWparm)))
    {
        dcmddrawcdir(Ppcw);
        if (!filefullpath(wk,Ppcw->UCWparm,sizeof(wk)))//drive err//~v03zI~
                return 4;                                       //~v03zI~
#ifdef W32                                                         //~vb0aI~
    	if (IS_RESERVED_NAME(wk))   //uchdir requires prefix,change for msg//~vb0aI~
        	strcpy(wk,wk+RESERVED_NAMEID_CTR);                     //~vb0aI~
#endif                                                             //~vb0aI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    	if (WIN_ISREMOTEPATH(wk))                                  //~v7abI~
        	pc=wk;                                                 //~v7abI~
        else                                                       //~v7abI~
#endif                                                             //~v7abI~
        	pc=wk+2;                                               //~v7abI~
        uerrmsg("Set default drive to %c(curr dir is %s)",      //~v03zR~
                "省略値ドライブを %c に設定(現行ディレクトリーは %s)",//~v03zR~
//              *wk,wk+2);                                         //~v7abR~
                *wk,pc);                                           //~v7abI~
        inisavecd(wk);     //save for later session with /R option //~v11yI~
#ifdef WXE                                                         //~v579I~
        dcmdsyscmdnotify(XECMDSVR_DRIVECMD,"DRIVEID",wk);          //~v579I~
#endif                                                             //~v579I~
    }
    else
        rc=4;   //-1 meen quit
    return rc;
#endif                                                             //~v48aM~
}//dcmd_drive
                                                                   //~v196I~
//#endif //!UNX                                                    //~v48aR~

//**************************************************************** //~v19tI~
//!dcmd_pwd                                                        //~v19tI~
//* change directoey                                               //~v19tI~
//*parm1:pcw(UCWparm:operand)                                      //~v19tI~
//*retrn:rc 0,4                                                    //~v19tI~
//**************************************************************** //~v19tI~
int dcmd_pwd(PUCLIENTWE Ppcw)                                      //~v19tI~
{                                                                  //~v19tI~
	int rc;                                                        //~v19tI~
//********************                                             //~v19tI~
	Spwdsw=1;                                                      //~v19tI~
	rc=dcmd_cd(Ppcw);                                              //~v19tR~
	Spwdsw=0;                                                      //~v19tI~
    return rc;                                                     //~v19tI~
}//dcmd_pwd                                                        //~v19tI~
//****************************************************************
//!dcmd_cd
//* change directoey
//*parm1:pcw(UCWparm:operand)
//*retrn:rc 0,4                                                 //~v020R~
//****************************************************************
int dcmd_cd(PUCLIENTWE Ppcw)
{
    char wk[_MAX_PATH];
    UCHAR *pc;                                                  //~v020R~
    int stype,pathlen;                                             //~v196R~
    int rc;                                                        //~v58gI~
#ifndef UNX                                                        //~v196I~
    int cdrv,tdrv,drvchng=0;                                       //~v196I~
    UCHAR *pcroot;                                                 //~v7abI~
#endif //!UNX                                                      //~v196I~
#ifdef FTPSUPP                                                     //~v54iI~
    int hostnmlen=0;                                               //~v54iR~
    PUFTPHOST puftph=NULL;                                              //~v54pR~//~vafcR~
//    PUFILEH pfh;                                                 //~v71yR~
#endif                                                             //~v54iI~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt2;                                                      //~vaw6I~
    char wkud[_MAX_PATH];                                          //~vaw6I~
#endif                                                             //~vaw6I~
//********************
//  if (!(pc=Ppcw->UCWparm)                                        //~v09aI~
//  if (!(pc=Ppcw->UCWopdpot)                                      //~v19tR~
    pc=Ppcw->UCWopdpot;                                            //~v19tI~
#ifdef UNX                                                         //~v19tI~
    if (!pc)                                                       //~v19tI~
        pc="~";                                                    //~v19tR~
#endif //UNX                                                       //~v19tI~
    if (Spwdsw)     //PWD cmd                                      //~v19tI~
        pc=0;       //display curr dir                             //~v19tI~
    if (!pc                                                        //~v19tI~
#ifdef UNX                                                         //~v196I~
    ||  ((hostnmlen=uftpisremote(pc,&puftph))!=0 && hostnmlen==(int)strlen(pc)-1)//~v54iR~
        )                                                          //~v196I~
#else  //!UNX                                                      //~v196I~
  #ifdef W32                                                       //~v54iI~
    ||  ((hostnmlen=uftpisremote(pc,&puftph))!=0 && hostnmlen==(int)strlen(pc)-1)//~v54iR~
  #endif                                                           //~v54iI~
    || (strlen(pc)==2                                              //~v45HR~
        && *(pc+1)==':'                                         //~v020I~
        && memcmp(pc,WORKDIRPATHID,WORKDIRPATHIDLEN)))//not workdir id//~v45HR~
#endif //!UNX                                                      //~v196I~
    {                   //display req                           //~v020R~
#ifdef FTPSUPP                                                     //~v54iI~
      if (hostnmlen)                                               //~v54iR~
      {                                                            //~v54iI~
//      if (UFTPHISTSO(puftph))                                    //~v71iR~
//          errnotsupported("CD","remote TSO");                    //~v71iR~
//      else                                                       //~v71iR~
//      {                                                          //~v71iR~
	        uftpgetcwd(puftph->UFTPHhost,wk);                      //~v54iR~
          if (*wk)                                                 //~v71iI~
        	uerrmsg("For %s:,Current directory is %s",             //~v54iR~
                "%s: の現行ディレクトリーは %s",                   //~v54iR~
                puftph->UFTPHhost,wk);                             //~v54iR~
          else                                                     //~v71iI~
        	uerrmsg("For %s:,Current directory is not set",        //~v71iI~
                "%s: の現行ディレクトリーは設定されていません",    //~v71iI~
                puftph->UFTPHhost);                                //~v71iI~
//      }                                                          //~v71iR~
      }                                                            //~v54iI~
      else                                                         //~v54iI~
      {                                                            //~v54iI~
#endif                                                             //~v54iI~
        if (!pc)                                                //~v020I~
        {                                                          //~vb06I~
#ifdef W32                                                         //~vb06I~
            ugetcwdW(UGCWDWO_DROPPREFIX,wk);                       //~vb06I~
#else                                                              //~vb06I~
            ugetcwd(wk);                                        //~v020R~
#endif                                                             //~vb06I~
        }                                                          //~vb06I~
        else                                                    //~v020I~
        {                                                          //~vb05I~
            if (!filefullpath(wk,pc,sizeof(wk)))//drive err     //~v020R~
                return 4;                                       //~v020R~
//#ifdef W32                                                         //~vb05I~//~vb06R~
//            if (IS_RESERVED_NAME(wk))                              //~vb05I~//~vb06R~
//            {                                                      //~vb05I~//~vb06R~
//                strcpy(wk,wk+RESERVED_NAMEID_CTR);                 //~vb05I~//~vb06R~
//            }                                                      //~vb05I~//~vb06R~
//#endif                                                             //~vb05I~//~vb06R~
        }                                                          //~vb05I~
#ifdef UNX                                                         //~v196I~
        uerrmsg("Current directory is %s",                         //~v196I~
                "現行ディレクトリーは %s",                         //~v196I~
                wk);                                               //~v196I~
#else  //!UNX                                                      //~v196I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    	if (WIN_ISREMOTEPATH(wk))                                  //~v7abI~
        	pcroot=wk;                                             //~v7abI~
        else                                                       //~v7abI~
#endif                                                             //~v7abI~
//#ifdef W32                                                         //~vb05I~//~vb06R~
//        if (IS_RESERVED_NAME(wk))                                  //~vb05I~//~vb06R~
//        {                                                          //~vb05I~//~vb06R~
//            strcpy(wk,wk+RESERVED_NAMEID_CTR);                     //~vb05I~//~vb06R~
//            pcroot=wk+2;                                           //~vb05I~//~vb06R~
//        }                                                          //~vb05I~//~vb06R~
//        else                                                       //~vb05I~//~vb06R~
//#endif                                                             //~vb05I~//~vb06R~
        	pcroot=wk+2;                                           //~v7abI~
        uerrmsg("For %c:,Current directory is %s",              //~v020R~
                "%c: の現行ディレクトリーは %s",                //~v020R~
//              toupper(*wk),wk+2);                                //~v7abR~
                toupper(*wk),pcroot);                              //~v7abI~
#endif //!UNX                                                      //~v196I~
#ifdef WXE                                                         //~v579I~
		dcmdsyscmdnotify(XECMDSVR_PWDCMD,"PWD","");                //~v579I~
#endif                                                             //~v579I~
#ifdef FTPSUPP                                                     //~v54iI~
      }//not remote root                                           //~v54iI~
#endif                                                             //~v54iI~
    }                                                           //~v020I~
    else    //dir operand                                       //~v020R~
    {                                                           //~v020I~
#ifndef UNX                                                        //~v196I~
        cdrv=ugetdrive();       //current drive letter(upper case) //~v11xI~
#endif //!UNX                                                      //~v196I~
        if (*pc=='*' && !*(pc+1))   //"*"                          //~v11xI~
        {                                                          //~v11xI~
            stype=Ppcw->UCWtype;                                   //~v11xI~
            if (stype!=UCWTFILE && stype!=UCWTDIR)                 //~v11xR~
            {                                                      //~v11xI~
                uerrmsg("Invalid option on this panel",            //~v11xI~
                        "この画面では無効なオプションです");       //~v11xI~
                return 4;                                          //~v11xI~
            }                                                      //~v11xI~
//#ifdef FTPSUPP                                                   //~v71yR~
//            pfh=UGETPFHFROMPCW(Ppcw);                            //~v71yR~
//            if (FILEISTSO(pfh))                                  //~v71yR~
//                return errnotsupported("CD","remote TSO");       //~v71yR~
//#endif                                                           //~v71yR~
            strcpy(wk,UGETPFHFROMPCW(Ppcw)->UFHfilename);          //~v11xI~
            if (stype==UCWTFILE || WILDCARD(wk))                   //~v11PR~
            {                                                      //~v11xI~
                pathlen=PATHLEN(wk);                               //~v11xR~
//              if (pathlen!=3)                                    //~v489R~
//              if (!ROOTDIR2(wk))                                 //~v54iR~
                if (!ROOTDIR3(wk))                                 //~v54iI~
                    pathlen--;                                     //~v11xI~
                *(wk+pathlen)=0;                                   //~v11xR~
            }                                                      //~v11xI~
#ifdef FTPSUPP                                                     //~v54iI~
      	  	hostnmlen=uftpisremote(wk,&puftph);                    //~v54pR~
#endif                                                             //~v54iI~
#ifndef UNX                                                        //~v196I~
#ifdef FTPSUPP                                                     //~v54iI~
          if (!hostnmlen)                                          //~v54iI~
          {//local fnm                                             //~v54iI~
#endif                                                             //~v54iI~
            if (cdrv!=toupper(*wk))                                //~v11xI~
            {                                                      //~v11xI~
                if (uchdrive(*wk))  //chng also cur drive          //~v11xR~
                    return 4;                                      //~v11xI~
                drvchng=1;          //also current drive changed   //~v11xI~
#ifdef WXE                                                         //~v579I~
        		dcmdsyscmdnotify(XECMDSVR_DRIVECMD,"DRIVEID",wk);  //~v579I~
#endif                                                             //~v579I~
            }                                                      //~v11xI~
#ifdef FTPSUPP                                                     //~v54iI~
          }//local fnm                                             //~v54iI~
#endif                                                             //~v54iI~
#endif //!UNX                                                      //~v196I~
        }                                                          //~v11xI~
        else                                                       //~v11xI~
//not *                                                            //~v54iI~
        {                                                          //~v11PI~
//      if (!filefullpath(wk,pc,sizeof(wk)))                       //~v11KR~
		Gsubgblopt|=XESUB_GBLOPT_WILDPATH|XESUB_GBLOPT_WILDMEMB;//chk also mwmb dir//~v58gI~
//      if (!dcmdfullpath(Ppcw,wk,pc))   //consider *\ ::          //~v58gR~
//          return 4;       //-1 mean quit                         //~v58gR~
#ifdef W32UNICODE                                                  //~vaw6I~
		opt2=0; //enclose when f2l err only                        //~vaw6I~
  	  if (fsubw_cmdopdU8CT2UD(opt2,Ppcw,0/*opd1*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
        rc=(dcmdfullpath(Ppcw,wk,wkud)==0);   //consider *\ ::     //~vaw6I~
  	  else                                                         //~vaw6I~
#endif                                                             //~vaw6I~
        rc=(dcmdfullpath(Ppcw,wk,pc)==0);   //consider *\ ::       //~v58gR~
		Gsubgblopt&=~(XESUB_GBLOPT_WILDPATH|XESUB_GBLOPT_WILDMEMB);//clear for later req//~v58gI~
        if (rc)                                                    //~v58gR~
            return 4;       //-1 mean quit                         //~v58gI~
#ifdef W32                                                         //~vb06M~
    	if (IS_RESERVED_NAME(wk))   //uchdir requires prefix,change for msg//~vb06I~
        	strcpy(wk,wk+RESERVED_NAMEID_CTR);                     //~vb06I~
#endif                                                             //~vb06M~
//#ifdef UNX                                                       //~v489R~
//          if ((pathlen=(int)strlen(wk))!=1)   //not root         //~v488R~
#ifdef FTPSUPP                                                     //~v54iI~
      	  	hostnmlen=uftpisremote(wk,&puftph);                    //~v54pR~
//      	if (UFTPHISTSO(puftph))                                //~v71iR~
//          	return errnotsupported("CD","remote TSO");         //~v71iR~
        	if (UFTPHISTSO(puftph)                                 //~v71yI~
            &&  *(pc+puftph->UFTPHhostnmlen+1)!=DSN_QUOTE)         //~v71yI~
            {                                                      //~v71yI~
                uerrmsg("for TSO,specify fullapth DataSet name(enclosed by quotation)",0);//~v71yI~
            	return 4;                                          //~v71yI~
            }                                                      //~v71yI~
#endif                                                             //~v54iI~
            pathlen=(int)strlen(wk);                               //~v488I~
//          if (!ROOTDIR2(wk))                                     //~v54iR~
            if (!ROOTDIR3(wk))                                     //~v54iI~
//#else                                                            //~v489R~
//            if ((pathlen=(int)strlen(wk))!=3)   //dcmdfullpath remain last \ when *\ !//~v489R~
//#endif                                                           //~v489R~
//              if (*(wk+pathlen-1)=='\\')                         //~v19aR~
#ifdef W32                                                         //~v540I~
                if (*(wk+pathlen-1)==DIR_SEPC                      //~v540I~
                ||  *(wk+pathlen-1)==FTP_DIR_SEPC)                 //~v540I~
#else                                                              //~v540I~
                if (*(wk+pathlen-1)==DIR_SEPC)                     //~v19aI~
#endif                                                             //~v540I~
                    *(wk+pathlen-1)=0;                             //~v11PI~
        }                                                          //~v11PI~
//      if (uchdir(wk))                                            //~v509R~
        if (uchdir(0,wk))                                          //~v509I~
            return 4;       //-1 mean quit                      //~v020I~
#ifdef WXE                                                         //~v579I~
      if (!hostnmlen)                                              //~v71iI~
        dcmdsyscmdnotify(XECMDSVR_CDCMD,"CD",wk);                  //~v579I~
#endif                                                             //~v579I~
//#ifdef W32                                                         //~vb05M~//~vb06R~
//    if (IS_RESERVED_NAME(wk))   //uchdir requires prefix,change for msg//~vb05I~//~vb06R~
//    {                                                              //~vb05I~//~vb06R~
//        strcpy(wk,wk+RESERVED_NAMEID_CTR);                         //~vb05I~//~vb06R~
//    }                                                              //~vb05I~//~vb06R~
//#endif                                                             //~vb05M~//~vb06R~
                                                                   //~v11xI~
#ifndef UNX                                                        //~v196I~
        tdrv=toupper(*wk);                                         //~v11xI~
#endif //!UNX                                                      //~v196I~
#ifdef UNX                                                         //~v489I~
	if (!MDOSDISKOK(wk))                                           //~v489I~
#endif                                                             //~v489I~
        dcmddrawcdir(Ppcw);                                     //~v020R~
#ifdef FTPSUPP                                                     //~v54iI~
  if (hostnmlen)                                                   //~v54iI~
        uerrmsg("For %s:,set current directory to %s",             //~v54pR~
                "%s: の現行ディレクトリーを %s に設定",            //~v54pR~
                    puftph->UFTPHhost,wk+hostnmlen+1);             //~v54pR~
  else  //local file                                               //~v54iI~
  {                                                                //~v54iI~
#endif                                                             //~v54iI~
//      if (toupper(*wk)!=toupper(ugetdrive()))                    //~v11xR~
#ifdef UNX                                                         //~v196R~
	if (MDOSDISKOK(wk))                                            //~v489I~
        uerrmsg("Set current directory of mdos-disk to %s",        //~v489I~
                    "ディスケットの現行ディレクトリーを %s に設定",//~v489I~
                    wk);                                           //~v489I~
    else                                                           //~v489I~
        uerrmsg("Set current directory to %s",                     //~v196I~
                    "現行ディレクトリーを %s に設定",              //~v196I~
                    wk);                                           //~v196R~
#else  //!UNX                                                      //~v196I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    	if (WIN_ISREMOTEPATH(wk))                                  //~v7abI~
        	pcroot=wk;                                             //~v7abI~
        else                                                       //~v7abI~
#endif                                                             //~v7abI~
			pcroot=wk+2;                                           //~v7abI~
        if (tdrv!=cdrv)                                            //~v11xI~
          if (drvchng)                                             //~v11xI~
            uerrmsg("current drive,directory is now %c%s",         //~v11xR~
                    "省略値ドライブ,現行ディレクトリーを %c%s に設定",//~v11xR~
                    tdrv,wk+1);                                    //~v11xI~
          else                                                     //~v11xI~
            uerrmsg("For %c:,set current directory to %s",      //~v020R~
                    "%c: の現行ディレクトリーを %s に設定",     //~v020R~
//                  tdrv,wk+2);                                    //~v7abR~
                    tdrv,pcroot);                                  //~v7abI~
        else                                                    //~v020R~
            uerrmsg("Set current directory to %s(%c:)",         //~v020R~
                    "現行ディレクトリーを %s に設定(%c:)",      //~v020R~
//                  wk+2,tdrv);                                    //~v7abR~
                    pcroot,tdrv);                                  //~v7abI~
#endif //!UNX                                                      //~v196M~
        inisavecd(wk);     //save for later session with /R option //~v11yI~
#ifdef FTPSUPP                                                     //~v54iI~
  } //local file                                                   //~v54iI~
#endif                                                             //~v54iI~
    }                                                           //~v020I~
    return 0;                                                   //~v020R~
}//dcmd_cd
                                                                   //~v196I~
//****************************************************************
//!dcmddrawcdir
//*req to pandraw300 to set cur dir
//*parm1:pcw
//*retrn:none
//****************************************************************
void dcmddrawcdir(PUCLIENTWE Ppcw)
{
    PUCLIENTWE pcw;
//********************
    if (((PUPANELC)Ppcw->UCWppc)->UPCid==PANFNAME)
        UCBITON((Ppcw->UCWpsd+PANL300CURRENT)->USDflag2,USDF2DRAW);
    else                                                           //~v77cI~
    if (((PUPANELC)Ppcw->UCWppc)->UPCid & PANUTIL)                 //~v77cI~
        UCBITON((Ppcw->UCWpsd+PANLUCCDIR)->USDflag2,USDF2DRAW);    //~v77cI~
    if ((pcw=scrgetcw(-1),pcw)  //another client
//  &&  ((PUPANELC)pcw->UCWppc)->UPCid==PANFNAME)                  //~v77cR~
    )                                                              //~v77cI~
    {                                                              //~v77cI~
      if (((PUPANELC)pcw->UCWppc)->UPCid==PANFNAME)                //~v77cR~
        UCBITON((pcw->UCWpsd+PANL300CURRENT)->USDflag2,USDF2DRAW);
      else                                                         //~v77cI~
      if (((PUPANELC)pcw->UCWppc)->UPCid & PANUTIL)                //~v77cI~
        UCBITON((pcw->UCWpsd+PANLUCCDIR)->USDflag2,USDF2DRAW);     //~v77cI~
    }                                                              //~v77cI~
    return;
}//dcmddrawcdir
                                                                //~v03pI~
//****************************************************************//~v05lI~
//!dcmd_xdd                                                     //~v05oR~
//* delete directory                                            //~v05lI~
//*parm1:pcw(UCWparm:operand)                                   //~v05lI~
//*retrn:rc                                                     //~v05lI~
//****************************************************************//~v05lI~
int dcmd_xdd(PUCLIENTWE Ppcw)                                   //~v05lI~
{                                                               //~v05lI~
    UCHAR *pc;                                                  //~v05QR~
    int opdno,ii;                                               //~v05QR~
    int xdelopt;                                                //~v05QR~
    int xddopt;                                                 //~v05QR~
//********************                                          //~v05QI~
    if (!(pc=Ppcw->UCWparm))                                    //~v05QI~
    {                                                              //~v54tI~
//      return errmissing();                                       //~v54tR~
		uerrmsg("XDD file-spec [...] /r[-|L] /y",0);               //~v54tI~
        return 4;                                                  //~v54tI~
    }                                                              //~v54tI~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v05QI~
//parm chk                                                      //~v05QR~
    pc=uxddpchk(0,opdno,pc,&xdelopt,&xddopt,&ii);               //~v05QR~
    if (pc)                     //err operand ptr               //~v05QI~
        return errinvalid(pc);                                  //~v05QI~
    xdelopt &=~UXDELCONFEACH;   //avoud fonfirmation               //~v134I~
//  return dcmddelxdd(Ppcw,opdno,UXDELDIR,xdelopt,xddopt,1,0);  //~v05RR~//~vbygR~
    return dcmddelxdd(Ppcw,opdno,UXDELDIR,xdelopt,xddopt,DCMDXDDIDXDD|DCMDXDDID_DCMD,0);//~vbygR~
}//dcmd_xdd                                                     //~v05RR~
                                                                //~v05QI~
//****************************************************************//~v03pI~
//!dcmd_xdelete                                                 //~v05iR~
//* delete cmd                                                  //~v03pI~
//*parm1:pcw(UCWparm:operand)                                   //~v03pI~
//*retrn:rc                                                     //~v03pI~
//****************************************************************//~v03pI~
int dcmd_xdelete(PUCLIENTWE Ppcw)                               //~v05iR~
{                                                               //~v03pI~
    UCHAR *pc,*pc2;                                             //~v05iR~
    int opdno,ii;                                               //~v05QR~
    UINT attrmask=FILE_ALL-FILE_HIDDEN-FILE_SYSTEM-FILE_DIRECTORY;//~v05iI~
#ifdef UNX                                                         //~v54yR~
    int firstparmsw=0;                                             //~v19DI~
#endif //!UNX                                                      //~v54yR~
	int xdelOpt=0;                                                 //~vbyfI~
//********************                                          //~v03pI~
    if (!(pc=Ppcw->UCWparm))                                    //~v03pI~
    {                                                              //~v54tR~
//        return errmissing();                                     //~v54tR~
#ifdef UNX                                                         //~v54tR~
		uerrmsg("DEL file-spec [...] /s /h /d /a",0);              //~v54tR~
#else                                                              //~v54tR~
		uerrmsg("DEL file-spec [...] /h /d /a",0);                 //~v54tR~
#endif                                                             //~v54tR~
		return 4;                                                  //~v54tR~
    }                                                              //~v54tR~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v041R~
//mask get                                                      //~v05iI~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)                   //~v05iR~
    {                                                           //~v05iI~
#ifdef ARMXXE                                                      //~vbyfI~
		if (!strcmp(pc,PREFIX_ARM_SHARE))                           //~vbyfI~
        {                                                          //~vbyfI~
        	xdelOpt=UXDELSPROOT;                                   //~vbyfI~
            continue;                                              //~vbyfI~
        }                                                          //~vbyfI~
#endif                                                             //~vbyfI~
//      if (*pc!='/')                                              //~v19DR~
        if (!CMDFLAGCHK(*pc,firstparmsw)) // '-' or 2nd '/'        //~v19DI~
        {                                                          //~v19DI~
#ifdef UNX                                                         //~v40bI~
        	firstparmsw=1;                                         //~v19DI~
#endif //!UNX                                                      //~v40bI~
            continue;                                           //~v05iI~
        }                                                          //~v19DI~
        for (pc2=pc+1;*pc2;++pc2)                               //~v05iI~
        {                                                       //~v05iI~
            switch (toupper(*pc2))                              //~v05QR~
            {                                                   //~v05iI~
            case 'S':                                           //~v05iI~
                attrmask|=FILE_SYSTEM;                          //~v05iI~
                break;                                          //~v05iI~
            case 'H':                                           //~v05iI~
                attrmask|=FILE_HIDDEN;                          //~v05iI~
                break;                                          //~v05iI~
            case 'D':                                           //~v05iI~
                attrmask|=FILE_DIRECTORY;   //sub dir           //~v05iR~
                break;                                          //~v05iI~
            case 'A':                                           //~v05iI~
                attrmask=UXDELDIR;  //del dir                   //~v05oR~
                break;                                          //~v05iI~
            default:                                            //~v05iI~
                return errinvalid(pc);                          //~v05iI~
            }                                                   //~v05iI~
        }//all char                                             //~v05iI~
    }                                                           //~v05iI~
//  return dcmddelxdd(Ppcw,opdno,attrmask,UXDELNOMSG,0,0,0);    //~v05RR~//~vbyfR~
    return dcmddelxdd(Ppcw,opdno,attrmask,UXDELNOMSG|xdelOpt,0,0,0);//~vbyfI~
                //xddopt=xddid=pdh=0                            //~v05RI~
}//dcmd_xdelete                                                 //~v05QI~
#ifdef ARMXXE                                                   //~v05QI~//~vbyfR~
//**************************************************************** //~vbyfI~
int delsproot(char *Pfpath,int Prc)                               //~vbyfI~
{                                                                  //~vbyfI~
	UTRACEP("%s:no option to delete shared storage root,fnm=%s\n",UTT,Pfpath);//~vbyfI~
    uerrmsg("specify %s option to delete shared-storage top(\"%s %s\")",//~vbyfR~
    		"共有ストレージのトップフォルダーの削除には%sオプションを指定してください(\"%s %s\")",//~vbyfR~
            PREFIX_ARM_SHARE,Pfpath,PREFIX_ARM_SHARE);             //~vbyfR~
	return Prc;                                                    //~vbyfI~
}                                                                  //~vbyfI~
#endif                                                             //~vbyfI~
//****************************************************************//~v05QI~
//!dcmddelxdd                                                   //~v05QI~
//*common for delete and xdd cmd                                //~v05QI~
//*parm1:pcw(UCWparm:operand)                                   //~v05QI~
//*parm2:operand no                                             //~v05QI~
//*parm3:attr amsk                                              //~v05QI~
//*parm4:uxdelete option                                        //~v05QR~
//*parm5:xdd option(x01:no confirm)                             //~v05QR~
//*parm6:delete or xdd(0x01) cmd id,undeletable or not undeletable(0x02)x//~v060R~
//*parm7:pdh from dlcmd                                         //~v05RI~
//*retrn:rc                                                     //~v05QI~
//****************************************************************//~v05QI~
int dcmddelxdd(PUCLIENTWE Ppcw,int Popdno,UINT Pmask,int Pxdelopt,//~v05RR~
                int Pxddopt,int Pxddid,PUDIRLH Ppdh)            //~v05RI~
{                                                               //~v05QI~
    UCHAR fpath[_MAX_PATH];                                        //~v58gR~
    FILEFINDBUF3 fstat3={0};                                        //~v05QI~//~vafdR~
    UCHAR *pc;                                                  //~v05QR~
    int ii,prevconfirmed;                                       //~v05QR~
    int abrootsw;                                                  //~v135I~
#ifdef UNX                                                         //~v40bI~
    int firstparmsw=0;                                             //~v19DI~
#endif //!UNX                                                      //~v40bI~
#ifdef FTPSUPP                                                     //~v608I~
	int ftpxdelopt;                                                //~v608I~
    int tsosw;                                                     //~v71eI~
#endif                                                             //~v608I~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt2,swdcmd;                                               //~vaw6R~
    char wkud[_MAX_PATH];                                          //~vaw6I~
    PFUNCTBL pft;                                                  //~vaw6I~
#endif                                                             //~vaw6I~
//********************                                          //~v05QI~
	UTRACEP("%s:delopt=0x%x,xddopt=0x%x,mask=0x%x\n",UTT,Pxdelopt,Pxddopt,Pmask); //~vbygI~//~vbz1R~
#ifdef W32UNICODE                                                  //~vaw6I~
	pft=(PFUNCTBL)Ppcw->UCWpfunct;                                 //~vaw6I~
  	swdcmd=pft && (pft->FTfuncid==FUNCID_DELX||pft->FTfuncid==FUNCID_DOS);	//not dlcmd//~vaw6R~
#endif                                                             //~vaw6I~
//confirmation                                                  //~v05kI~
    if (!(Pxddopt & UXDDNOCONF)     //no confirm option         //~v05QR~
    &&  !(Pxdelopt & UXDELRONLYCHK))    //not ronly list        //~v05QI~
    {                                                           //~v05QI~
        pc=Ppcw->UCWparm;                                       //~v05kI~
        prevconfirmed=Gxdconfindex;                             //~v05kI~
        for (ii=0;ii<Popdno;ii++,pc+=strlen(pc)+1)              //~v05QR~
        {                                                       //~v05kI~
//          if (*pc=='/')                                          //~v19DR~
        	if (CMDFLAGCHK(*pc,firstparmsw)) // '-' or 2nd '/'     //~v19DI~
                continue;                                       //~v05kI~
#ifdef UNX                                                         //~v40bI~
        	firstparmsw=1;                                         //~v19DI~
#endif //!UNX                                                      //~v40bI~
            if (ii<prevconfirmed)                               //~v05kI~
                continue;                                       //~v05kI~
//            if (!filefullpath(fullpath,pc,_MAX_PATH))   //consider :://~v11HR~
#ifdef W32UNICODE                                                  //~vaw6I~
			opt2=0; //enclose when f2l err only                    //~vaw6I~
  	   	  if (swdcmd && fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opdno*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
          {                                                        //~vaw6I~
    	    if (!dcmdfullpath(Ppcw,fpath,wkud)) //consider ::      //~vaw6I~
            return 4;                                              //~vaw6I~
  	      }                                                        //~vaw6I~
  	      else                                                     //~vaw6I~
#endif                                                             //~vaw6I~
            if (!dcmdfullpath(Ppcw,fpath,pc))   //consider ::      //~v58gR~
                return 4;                                       //~v05kI~
            abrootsw=0;                                            //~v135I~
                                                                   //~v21pI~
#ifdef UNX                                                         //~v21pI~
//          if (ROOTDIR2(fullpath))                                //~v54jR~
            if (ROOTDIR3(fpath))                                   //~v58gR~
            {                                                      //~v487I~
//          	if (ROOTDIR(fullpath))                             //~v54jR~
            	if (!MDOSROOTDIR(fpath))	//not disket drive     //~v58gR~
					return ufileroot(fpath,4);                     //~v58gR~
                abrootsw=1;                                        //~v487I~
            }                                                      //~v487I~
#ifdef ARMXXE                                                      //~vbyfI~
            if (Pmask==UXDELDIR)    //xdd or del /a                //~vbyfI~
    	        if (IS_DOCROOT(fpath))                             //~vbyfR~
        	    	if (!(Pxdelopt & UXDELSPROOT))                 //~vbyfR~
            	    	return delsproot(fpath,4);                 //~vbyfR~
#endif                                                             //~vbyfI~
#else  //!UNX                                                      //~v21pI~
    #ifdef FTPSUPP                                                 //~v54iI~
    	  if (uftpisrootdir(fpath))//remote root	               //~v58gR~
				return ufileroot(fpath,4);                         //~v58gR~
          else                                                     //~v54iI~
    #endif                                                         //~v54iI~
            if (ROOTDIR(fpath))                                    //~v58gR~
                if (*fpath=='A' || *fpath=='a'                     //~v58gR~
                ||  *fpath=='B' || *fpath=='b')                    //~v58gR~
                    abrootsw=1;                                    //~v135I~
                else                                               //~v487I~
					return ufileroot(fpath,4);                     //~v58gR~
#endif //!UNX                                                      //~v21pI~
          if (!abrootsw)                                           //~v135I~
          {                                                        //~v53RI~
#ifdef FTPSUPP                                                     //~v71eI~
            tsosw=u3270fullpathistso(fpath);                       //~v71eI~
            if (tsosw==1)                                          //~v71eI~
            	return errnotsupported("Delete","TSO DataSet without MEMBER");//~v71eR~
          if (tsosw)	//tsosw=2:PDS member                       //~v71eI~
            memset(&fstat3,0,sizeof(fstat3));	//clear directory flag//~v71eI~
          else                                                     //~v71eI~
          {                                                        //~v71eI~
#endif                                                             //~v71eI~
#ifdef UNX                                                         //~v49gI~
//          if (udosfindfirst(fpath,0,FILE_ALLSP,&fstat3))         //~v58gR~//~va0fR~
//              return 4;                                          //~v49gI~//~va0fR~
            if (ufstat(fpath,&fstat3))                             //~va0fM~
                return ufilenotfound(fpath,4);                     //~va0fM~
            else                                                   //~v49gI~
    		if (fstat3.attrFile & FILE_SPECIAL)//not reguler file  //~v49gR~
				return ufileerrspecialfile(fpath,4);               //~v58gR~
//          else                                                   //~v53RR~
#else                                                              //~v49gI~
            if (udosfindfirst(fpath,0,FILE_ALL,&fstat3))           //~v58gR~
                return 4;                                       //~v05kI~
  #ifdef FTPSUPP                                                   //~v71yI~
            else                                                   //~v71yI~
    		if (fstat3.attrFile & FILE_SPECIAL)//not reguler file  //~v71yI~
				return ufileerrspecialfile(fpath,4);               //~v71yI~
  #endif                                                           //~v71yI~
#endif                                                             //~v49gI~
          }//abrootsw                                              //~v53RI~
#ifdef FTPSUPP                                                     //~v71eI~
        }//!tso PDS member                                         //~v71eI~
#endif                                                             //~v71eI~
            if (UCBITCHK(fstat3.attrFile,FILE_DIRECTORY)        //~v05QR~
            ||  abrootsw            //a:\ or b:\ asume *.*         //~v135I~
            ||  WILDCARD(fpath))//dir                              //~v58gR~
            {                                                   //~v05oI~
    #ifdef FTPSUPP                                                 //~va0fR~
              if (fstat3.srcattr==0)    //not slink                //~va0fI~
    #endif                                                         //~va0fI~
              if (!(Ppdh && FILE_IS_WILDNAME(Ppdh->UDHattr)))      //~van2R~
//              if (dcmdxdconf(Ppcw,fpath))  //confirmation chk    //~vaa0R~
                if (dcmdxdconf(Pxdelopt,Ppcw,fpath))  //confirmation chk//~vaa0I~
                    return 4;                                   //~v05kR~
                if (Ppdh)                                       //~v05RR~
                    dlcmdlvlclear(Ppcw,Ppdh,1,2);//all child,drop view//~v05RR~
            }                                                   //~v05oI~
            Gxdconfindex=ii+1;  //next confirm index            //~v05kR~
                                                                //~v05kI~
        }                                                       //~v05kI~
    }                                                           //~v05QI~
    Gxdconfindex=0;                                             //~v05kI~
//process al files                                              //~v05iI~
    pc=Ppcw->UCWparm;                                           //~v05iI~
#ifdef UNX                                                         //~v40bI~
    firstparmsw=0;                                                 //~v19DR~
#endif //!UNX                                                      //~v40bI~
    for (ii=0;ii<Popdno;ii++,pc+=strlen(pc)+1)                  //~v05QR~
    {                                                           //~v03pI~
//      if (*pc=='/')                                              //~v19DR~
        if (CMDFLAGCHK(*pc,firstparmsw)) // '-' or 2nd '/'         //~v19DI~
            continue;                                           //~v05iI~
#ifdef UNX                                                         //~v40bI~
        firstparmsw=1;                                             //~v19DI~
#endif //!UNX                                                      //~v40bI~
//        if (!filefullpath(fullpath,pc,_MAX_PATH))   //consider :://~v11HR~
#ifdef W32UNICODE                                                  //~vaw6I~
		opt2=0; //enclose when f2l err only                        //~vaw6R~
  	  if (swdcmd && fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opd1*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6R~
      {                                                            //~vaw6I~
    	if (!dcmdfullpath(Ppcw,fpath,wkud)) //consider ::          //~vaw6I~
        return 4;                                                  //~vaw6I~
  	  }                                                            //~vaw6I~
  	  else                                                         //~vaw6I~
#endif                                                             //~vaw6I~
        if (!dcmdfullpath(Ppcw,fpath,pc))   //consider ::          //~v58gR~
            return 4;                                           //~v03pR~
#ifdef FTPSUPP                                                     //~v608I~
		if (uftpisremote(fpath,0))                                 //~v608R~
 	       ftpxdelopt=UXDELSKIPRONLY;	//ronly chk not avail,so set bypass ronlychk//~v608I~
        else                                                       //~v608I~
 	       ftpxdelopt=0;                                           //~v608I~
        if (dcmdxdelete(Ppcw,fpath,Pmask,Pxdelopt|ftpxdelopt,Pxddid,Ppdh))//~v608I~
#else                                                              //~v608I~
        if (dcmdxdelete(Ppcw,fpath,Pmask,Pxdelopt,Pxddid,Ppdh))    //~v58gR~
#endif                                                             //~v608I~
            return 4;                                           //~v03pR~
    }                                                           //~v03pI~
    return 0;                                                   //~v03pR~
}//dcmddelxdd                                                   //~v05QR~
                                                                //~v03pI~
//****************************************************************//~v05kI~
//!dcmdxdconf                                                   //~v05kI~
//* confirm dir delete                                          //~v05kI~
//*parm1:pcw(UCWparm:operand)                                   //~v05kI~
//*parm2:fullpath name                                          //~v05kR~
//*retrn:rc                                                     //~v05kI~
//****************************************************************//~v05kI~
//int dcmdxdconf(PUCLIENTWE Ppcw,UCHAR *Pfullpath)                 //~vaa0R~
int dcmdxdconf(int Pxdelopt,PUCLIENTWE Ppcw,UCHAR *Pfullpath)      //~vaa0I~
{                                                               //~v05kI~
//********************                                          //~v05kI~
    if (!scrconfirmchk(GSCRCONFDELDIR)) //not yet confirmed     //~v05kR~
    {                                                           //~v05kI~
//      uerrmsg("Delete %s,Enter to execute,Esc to cancel",     //~v05QR~//~vb7nR~
//              "%s の削除確認,続行する時は実行キー,取消はEsc", //~v05QR~//~vb7nR~
        uerrmsg("Delete? %s,Enter to execute,Esc to cancel",       //~vb7nI~
                "削除確認 %s,続行する時は実行キー,取消はEsc",      //~vb7nI~
//              Pfullpath);                                     //~v05kI~//~vb08R~
                STD_FNM(Pfullpath));                               //~vb08I~
#ifdef UNX                                                         //~vaa0I~
	  	if (Pxdelopt & UXDELWILDMULTIPLE)                          //~vaa0I~
        	uerrmsgcat(". Those may be created at Another system.(Multiple Entry could not be Identified)",//~vaa0I~
            	       ". 他システムで作成されたファイルと思われます.複数あり区別できません");//~vaa0R~
      	else                                                       //~vaa0I~
	  	if (Pxdelopt & UXDELWILDNAME)                              //~vaa0I~
        	uerrmsgcat(". It may be created at Another system.(Only one entry)",//~vaa0I~
            	       ". 他システムで作成されたファイルと思われます.同名のものは一つだけです");//~vaa0R~
#endif                                                             //~vaa0I~
//      csronthefld(Ppcw,CMDLINENO,0,0);    //set cursor to fld top//~v05kR~
        return 4;                                               //~v05kR~
    }                                                           //~v05kI~
    return 0;                                                   //~v05kI~
}//dcmdxdconf                                                   //~v05kI~
                                                                //~v05kI~
//****************************************************************//~v03pI~
//!dcmdxdelete                                                  //~v05iR~
//* delete cmd                                                  //~v03pI~
//*parm1:pcw(UCWparm:operand)                                   //~v03pI~
//*parm2:fullpath name                                          //~v03pI~
//*parm3:attr mask                                              //~v05iI~
//*parm4:uxdelete option                                        //~v05QI~
//*parm5:pdh from dlcmd3                                        //~v05RI~
//*retrn:rc                                                     //~v03pI~
//****************************************************************//~v03pI~
int dcmdxdelete(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UINT Pattrmask,//~v05RR~
            int Pxdelopt,int Pxddid,PUDIRLH Ppdh)               //~v05RI~
{                                                               //~v03pI~
    int rc;                                                     //~v05uI~
    int total,ronly;                                            //~v05QR~
    int deleted;                                                //~v05QI~
//********************                                          //~v03pI~
	UTRACEP("%s:fpath=%s,xdelOpt=0x%x,xddidopt=0x%x,attrmask=0x%x\n",UTT,Pfullpath,Pxdelopt,Pxddid,Pattrmask);//~vbygI~//~vbz1R~
    if ((Pxdelopt & UXDELRONLYCHK)  //read only chk             //~v05QR~
    ||  !(Pxdelopt & (UXDELFORCE|UXDELSKIPRONLY)))  //err when ronly//~v05QR~
    {                                                              //~vaa0R~
#ifdef UNX                                                         //~vaa0I~
      if (!(Pxddid & DCMDXDDIDNOUNDEL)                             //~vaa0I~
      &&  Ppdh                                                     //~vaa0I~
      &&  UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE))	//save undel case//~vaa0I~
      {                                                            //~vaa0I~
        if (FILE_IS_WILDNAME(Ppdh->UDHattr))                       //~van5I~
        	if (dcmdwildconf(1/*delete*/,Ppcw,Pfullpath,Ppdh))  //confirmation chk//~van5I~
                return 4;                                          //~van5I~
        rc=uxddsub(Pfullpath,UXDELNOMSG|UXDELFORCE|UXDELRONLYCHK|UXDELUNDELCOPY,//~vaa0I~
                    UXDDNOCONF,Pfullpath);                         //~vaa0I~
        if (rc==FILE_WILDNAME)                                     //~vaa0I~
        {                                                          //~van5I~
//      	uerrmsgcat(". Use not undo-able Delete cmd, or Move cmd",//~vaa0R~//~van2R~
//                      ". Undo保存しない削除コマンド、またはMoveコマンドを使用してください");//~vaa0R~//~van2I~
//            uerrmsgcat(". Use not undo-able Delete cmd, or Move/Rename cmd",//~van2I~//~van5R~
//                        ". Undo保存しない削除コマンド、またはMove/Renameコマンドを使用してください");//~van2I~//~van5R~
            rc=0;   //confirmed                                    //~van5I~
        }                                                          //~van5I~
      }                                                            //~vaa0I~
      else                                                         //~vaa0I~
#endif                                                             //~vaa0I~
#ifdef W32                                                         //~van2R~
      if (!(Pxddid & DCMDXDDIDNOUNDEL)                             //~van2R~
      &&  Ppdh                                                     //~van2R~
      &&  UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE))   //save undel case//~van2R~
      {                                                            //~van2R~
        	if (FILE_IS_WILDNAME(Ppdh->UDHattr))                   //~van2R~
        	{                                                      //~van2R~
            	if (dcmdwildconf(1/*delete*/,Ppcw,Pfullpath,Ppdh))  //confirmation chk//~van2R~//~van5R~
                	return 4;                                      //~van2R~
        	}                                                      //~van2R~
            rc=uxddsub(Pfullpath,UXDELNOMSG|UXDELFORCE|UXDELRONLYCHK,//~van2R~
                    UXDDNOCONF,Pfullpath);                         //~van2R~
      }                                                            //~van2R~
      else                                                         //~van2R~
#endif                                                             //~van2R~
        rc=uxddsub(Pfullpath,UXDELNOMSG|UXDELFORCE|UXDELRONLYCHK,//~v05QR~
                    UXDDNOCONF,Pfullpath);                      //~v05QR~
        if (rc)         //err or read only exist                //~v05QR~
        {                                                          //~vb76I~
            if (rc==2)  //ronly or longname                        //~vb76I~
            {                                                      //~vb76I~
                if (Pxddid & DCMDXDDIDXDD)  //form dlcmd           //~vb76I~
                {                                                  //~vbygR~
                  if (Pxddid & DCMDXDDID_DCMD)  //form dlcmd       //~vbygR~
                    uerrmsgcat("; Use \"/r\" option to force delete",//~vbygR~
                    			"; 強制削除するには\"/r\" オプションを使用してください");//~vbygR~
                  else                                             //~vbyfI~
                    uerrmsgcat("; Use \"/\" line cmd to force delete",//~vb76R~//~vbyfR~
                    			"; 強制削除するには\"/\" 行コマンドを使用してください");//~vb76R~
                }                                                  //~vbyfI~
                else                                               //~vbygI~
                {                                                  //~vbygI~
                    uerrmsgcat("; Use xdd command with \"/r\" option to force delete",//~vbygI~
                    			"; 強制削除するには \"/r\" オプション指定のxddコマンドを使用してください");//~vbygI~
                }                                                  //~vbygI~
            }                                                      //~vb76I~
            return rc;                                          //~v05QI~
        }                                                          //~vb76I~
        if (Pxdelopt & UXDELRONLYCHK)                           //~v05QR~
            return 0;   //read only chk but no read only file   //~v05QR~
        Pxdelopt|=UXDELRONLYCHKOK;  //avoid duplicated ronlychk in xddsub//~v607I~
    }                                                           //~v05QI~
    if (Pxddid & DCMDXDDIDNOUNDEL)                              //~v060I~
        rc=1;   //del execute                                   //~v060I~
    else                                                        //~v060I~
    if (Ppdh                                                    //~v05RR~
    && UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE))          //~v05uR~
    {                                                           //~v05uI~
        rc=dlcmdundelprep(Ppcw,Pfullpath,Ppdh);                 //~v05RR~
        if (rc>1)   //err(1 for del on save dir)                //~v05uR~
            return rc;                                          //~v05uI~
    }                                                           //~v05uI~
    else                                                        //~v05uI~
        rc=1;                                                   //~v05uR~
    if (rc) //del execute                                       //~v05QR~
    {                                                           //~v05QI~
#ifdef AIX                                                         //~v48mI~
		if (MDOSDISK(Pfullpath))                                   //~v48mI~
			Pxdelopt&=~UXDELDIR;  //del dir not supported for aix mdos disk//~v48mI~
#endif                                                             //~v48mI~
        if (Pxddid & DCMDXDDIDXDD)                              //~v060R~
            rc=uxddsub(Pfullpath,Pxdelopt,UXDDNOCONF,Pfullpath);//~v05QR~
        else                                                    //~v05QI~
        {                                                          //+vbz2I~
            rc=uxdelete(Pfullpath,Pattrmask,Pxdelopt,&total,&ronly,&deleted);//~v05QR~
            if (rc && !deleted)                                    //+vbz2I~
            	if (!(Pattrmask & FILE_DIRECTORY))                 //+vbz2I~
    				uerrmsgcat("; addtional option is required to delete Directory.",//+vbz2I~
            					"; ディレクトリーを削除するには追加のオプション指定が必要です");//+vbz2I~
        }                                                          //+vbz2I~
        if (rc)                                                 //~v05QI~
            return 4;                                           //~v05QR~
        rc=1;   //id of deleted(not undo)                       //~v05QI~
    }                                                           //~v05QR~
    if (!rc || !Pxddid) //undoprep or uxdelete(not xddsub)      //~v05QR~
        dcmddeleted(Pfullpath);                                 //~v05QI~
    return 0;                                                   //~v03pR~
}//dcmdxdelete                                                  //~v05iR~
                                                                //~v03pI~
//****************************************************************//~v05iI~
//!dcmddelete                                                   //~v05iI~
//* delete cmd                                                  //~v05iI~
//*parm1:pcw(UCWparm:operand)                                   //~v05iI~
//*parm2:fullpath name                                          //~v05iI~
//*parm3:pdh (id of cmd/lcmd)                                   //~v05uI~
//*retrn:rc                                                     //~v05iI~
//****************************************************************//~v05iI~
//int dcmddelete(PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh) //~v05RR~
//{                                                             //~v05RR~
//  int rc;                                                     //~v05RR~
//********************                                          //~v05iI~
//  if (Ppdh                                                    //~v05RR~
//    && UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE))        //~v05RR~
//    {                                                         //~v05RR~
//      rc=dlcmdundelprep(Ppcw,Pfullpath,Ppdh); //move to save dir//~v05RR~
//      if (rc>1)   //err(1 for del on save dir)                //~v05RR~
//          return rc;                                          //~v05RR~
//    }                                                         //~v05RR~
//    else                                                      //~v05RR~
//        rc=1;                                                 //~v05RR~
//  if (rc) //del execute                                       //~v05RR~
//    if (uremove(Pfullpath))//                                 //~v05RR~
//      return 4;                                               //~v05RR~
//    dcmddeleted(Pfullpath);                                   //~v05RR~
//  return 0;                                                   //~v05RR~
//}//dcmddelete                                                 //~v05RR~
                                                                //~v05iI~
//****************************************************************//~v03zI~
//!dcmd_rmdir                                                   //~v03zI~
//* delete directory                                            //~v03zI~
//*parm1:pcw(UCWparm:operand)                                   //~v03zI~
//*retrn:rc                                                     //~v03zI~
//****************************************************************//~v03zI~
int dcmd_rmdir(PUCLIENTWE Ppcw)                                 //~v03zI~
{                                                               //~v03zI~
    UCHAR fpath[_MAX_PATH];                                        //~v58gR~
    UCHAR *pc;                                                  //~v03zI~
    int opdno,ii;                                               //~v03zI~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt;	//filename opdno                                   //~vaw6I~
    char wkud[_MAX_PATH];                                          //~vaw6I~
#endif                                                             //~vaw6I~
//********************                                          //~v03zI~
    if (!(pc=Ppcw->UCWparm))                                    //~v03zI~
        return errmissing();                                    //~v03zI~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v041R~
    for (ii=0;ii<opdno;ii++)                                    //~v03zI~
    {                                                           //~v03zI~
//      if (!filefullpath(fullpath,pc,_MAX_PATH))   //consider ::  //~v11KR~
#ifdef W32UNICODE                                                  //~vaw6I~
		opt=0; //enclose when f2l err only                         //~vaw6I~
  	  if (fsubw_cmdopdU8CT2UD(opt,Ppcw,ii/*opd1*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
      {                                                            //~vaw6I~
    	if (!dcmdfullpath(Ppcw,fpath,wkud)) //consider ::          //~vaw6I~
        return 4;                                                  //~vaw6I~
  	  }                                                            //~vaw6I~
  	  else                                                         //~vaw6I~
#endif                                                             //~vaw6I~
        if (!dcmdfullpath(Ppcw,fpath,pc))    //consider *\ ::      //~v58gR~
            return 4;                                           //~v03zI~
        if (dcmdrmdir(Ppcw,fpath,0)) //cmd                         //~v58gR~
            return 4;                                           //~v03zI~
        pc+=strlen(pc)+1;   //next operand addr                 //~v03zI~
    }                                                           //~v03zI~
    return 0;                                                   //~v03zI~
}//dcmd_rmdir                                                   //~v03zI~
                                                                //~v03zI~
//****************************************************************//~v03zI~
//!dcmdrmdir                                                    //~v03zI~
//* delete directory cmd                                        //~v03zI~
//*parm1:pcw(UCWparm:operand)                                   //~v03zI~
//*parm2:fullpath name                                          //~v03zI~
//*parm3:pdh (id of cmd/lcmd)                                   //~v05uI~
//*retrn:rc 0:ok, 2:not empty 4:other err                       //~v05oR~
//****************************************************************//~v03zI~
int dcmdrmdir(PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh)    //~v05uR~
{                                                               //~v03zI~
    int rc;                                                     //~v05oI~
//********************                                          //~v03zI~
    if (Ppdh                                                    //~v05uI~
    && UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE))          //~v05uR~
    {                                                           //~v05uI~
        rc=dlcmdundelprep(Ppcw,Pfullpath,Ppdh); //move to save dir//~v05uR~
        if (rc>1)   //err(1 for del on save dir)                //~v05uI~
            return rc;                                          //~v05uI~
    }                                                           //~v05uI~
    else                                                        //~v05uI~
        rc=1;                                                   //~v05uR~
  if (rc) //del execute                                         //~v05uI~
    if (rc=urmdir(Pfullpath),rc)                                //~v05oR~
    {                                                           //~v05oI~
//#ifdef DOS                                                       //~v085R~
        if (rc==EACCES)     //root/current/not empty            //~v05oI~
//#else                                                            //~v085R~
//      if (rc==EACCESS)    //root/current/not empty               //~v085R~
//#endif                                                           //~v085R~
            return 2;       //may not empty                     //~v05oR~
        else                                                    //~v05oI~
            return 4;       //not found etc                     //~v05oI~
    }                                                           //~v05oI~
//  uerrmsg("directory %s was deleted",                          //~v03zI~//~vawKR~//~vb7nR~
//          "ディレクトリー %s を削除",                         //~v03zI~//~vb7nR~
    uerrmsg("Deleted:%s",                                          //~vb7nI~
            "削除済:%s",                                           //~vb7nI~
//          Pfullpath);                                         //~v03zI~//~vb08R~
            STD_FNM(Pfullpath));                                   //~vb08I~
    return 0;                                                   //~v03zI~
}//dcmdrmdir                                                    //~v03zI~
                                                                //~v03zI~
//****************************************************************//~v03zI~
//!dcmd_mkdir                                                   //~v03zI~
//* create directory                                            //~v03zI~
//*parm1:pcw(UCWparm:operand)                                   //~v03zI~
//*retrn:rc                                                     //~v03zI~
//****************************************************************//~v03zI~
int dcmd_mkdir(PUCLIENTWE Ppcw)                                 //~v03zI~
{                                                               //~v03zI~
    UCHAR fpath[_MAX_PATH];                                        //~v58gR~
    UCHAR *pc;                                                  //~v03zI~
    int opdno,ii;                                               //~v03zI~
#ifdef UNX                                                         //~v201I~
    UCHAR   *pflag;                                                //~v209R~
    ULONG   mode,attron,attroff;                                   //~v209R~
#endif //UNX                                                       //~v201I~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt;	//filename opdno                                   //~vaw6I~
    char wkud[_MAX_PATH];                                          //~vaw6I~
#endif                                                             //~vaw6I~
//********************                                          //~v03zI~
    if (!(pc=Ppcw->UCWparm))                                    //~v03zI~
        return errmissing();                                    //~v03zI~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v041R~
                                                                   //~v201I~
#ifdef UNX                                                         //~v201I~
//   if (uparsegetopt(UPGO_NOCASE|UPGO_ERRMSG,pc,&opdno,"m",(char **)&pc,(char **)&pflag))//~vaa0R~
     if (uparsegetopt(UPGO_NOCASE|UPGO_ERRMSG,pc,&opdno,"m",(char **)(ULONG)(&pc),(char **)(ULONG)(&pflag)))//~vaa0I~
    	return 4;                                                  //~v201I~
    mode=0;                                                        //~v201I~
    if (pflag)                                                     //~v201I~
    {                                                              //~v53QI~
//  	if (ucalc_o2l(pflag,&mode,0))	//get octal value          //~v209R~
//      if (dcmdattrchk(pflag,&attron,&attroff))//accum flag       //~v47CR~
        if (dcmdattrchk(pflag,&attron,&attroff,0))//accum flag,not mdos disk attr//~v47CI~
        {                                                          //~v201I~
//            uerrmsg("mode parm octal value err(%s)",0,           //~v209R~
//                    pflag);                                      //~v209R~
        	return 4;                                              //~v201I~
        }                                                          //~v201I~
        else                                                       //~v209I~
        	mode=FILE_GETMODE(attron);                             //~v209R~
    }//pflag                                                       //~v53QI~
#endif //UNX                                                       //~v201I~
                                                                   //~v201I~
    for (ii=0;ii<opdno;ii++)                                    //~v03zI~
    {                                                           //~v03zI~
//      if (!filefullpath(fullpath,pc,_MAX_PATH))   //consider ::  //~v11KR~
#ifdef W32UNICODE                                                  //~vaw6I~
		opt=0; //enclose when f2l err only                         //~vaw6I~
  	  if (fsubw_cmdopdU8CT2UD(opt,Ppcw,ii/*opd1*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
      {                                                            //~vaw6I~
    	if (!dcmdfullpath(Ppcw,fpath,wkud)) //consider ::          //~vaw6I~
        return 4;                                                  //~vaw6I~
  	  }                                                            //~vaw6I~
  	  else                                                         //~vaw6I~
#endif                                                             //~vaw6I~
        if (!dcmdfullpath(Ppcw,fpath,pc))    //consider *\ ::      //~v58gR~
            return 4;                                           //~v03zI~
#ifdef UNX                                                         //~v201I~
        if (dcmdmkdir(Ppcw,fpath,mode))                            //~v58gR~
#else  //!UNX                                                      //~v201I~
        if (dcmdmkdir(Ppcw,fpath))                                 //~v58gR~
#endif //!UNX                                                      //~v201I~
            return 4;                                           //~v03zI~
        pc+=strlen(pc)+1;   //next operand addr                 //~v03zI~
    }                                                           //~v03zI~
    return 0;                                                   //~v03zI~
}//dcmd_mkdir                                                   //~v03zI~
                                                                //~v03zI~
//****************************************************************//~v03zI~
//!dcmdmkdir                                                    //~v03zI~
//* make   directory cmd                                           //~v11KR~
//*parm1:pcw(UCWparm:operand)                                   //~v03zI~
//*parm2:fullpath name                                          //~v03zI~
//*retrn:rc                                                     //~v03zI~
//****************************************************************//~v03zI~
#ifdef UNX                                                         //~v201I~
int dcmdmkdir(PUCLIENTWE Ppcw,UCHAR *Pfullpath,ULONG Pmode)        //~v201I~
#else  //!UNX                                                      //~v201I~
int dcmdmkdir(PUCLIENTWE Ppcw,UCHAR *Pfullpath)                 //~v03zI~
#endif //!UNX                                                      //~v201I~
{                                                               //~v03zI~
#ifdef UNX                                                         //~v201I~
    ULONG rmode;                                                   //~v201I~
#else  //!UNX                                                      //~v201I~
#endif //!UNX                                                      //~v201I~
//********************                                          //~v03zI~
#ifdef UNX                                                         //~v201I~
    if (MDOSDISKOK(Pfullpath))                                     //~v47CI~
        if (Pmode)                                                 //~v47CI~
        {                                                          //~v47CI~
	   		uerrmsg("mode option is invalid for MDOS disk(%s)",0,  //~v47CR~
            		Pfullpath);                                    //~v47CI~
            return 4;                                              //~v47CI~
        }                                                          //~v47CI~
	if (Pmode)                                                     //~v201R~
    {                                                              //~v201I~
		if (umkdirmode(Pfullpath,Pmode,&rmode))                    //~v201I~
        	return 4;                                              //~v201I~
	   	uerrmsg("%s was created(mode=%o)",                          //~v201R~//~vawKR~
            "%s を作成(モード=%o)",                                //~v201R~
            Pfullpath,rmode);                                      //~v201I~
        if (Pmode!=rmode)                                          //~v201I~
		   	uerrmsgcat("!=%o,chk umask setting",                   //~v201R~
            "!=%o,umaskをチェック",                                //~v201R~
            Pmode);                                                //~v201R~
	    return 0;                                                  //~v201I~
    }                                                              //~v201I~
#endif //!UNX                                                      //~v201I~
    if (umkdir(Pfullpath))                                      //~v03zI~
        return 4;                                               //~v03zI~
//  uerrmsg("directory %s was created",                          //~v03zI~//~vawKR~//~vb7nR~
//          "ディレクトリー %s を作成",                         //~v03zI~//~vb7nR~
    uerrmsg("Created:%s",                                          //~vb7nI~
            "作成済:%s",                                           //~vb7nI~
//          Pfullpath);                                         //~v03zI~//~vb08R~
            STD_FNM(Pfullpath));                                   //~vb08I~
    return 0;                                                   //~v03zI~
}//dcmdmkdir                                                    //~v03zI~
                                                                //~v03zI~
//****************************************************************//~v03pI~
//!dcmd_rename                                                  //~v03pI~
//* rename cmd                                                  //~v03pI~
//*parm1:pcw(UCWparm:operand)                                   //~v03pI~
//*retrn:rc                                                     //~v03pI~
//****************************************************************//~v03pI~
int dcmd_rename(PUCLIENTWE Ppcw)                                //~v03pI~
{                                                               //~v03pI~
//  UCHAR fullpathold[_MAX_PATH];                               //~v03pR~//~vb7gR~
//  UCHAR realnew[_MAX_PATH];                                      //~v11tI~//~vb7gR~
    UCHAR fullpathold[_MAX_PATH_LONG];                             //~vb7gI~
    UCHAR realnew[_MAX_PATH_LONG];                                 //~vb7gI~
    UCHAR *pc;                                                  //~v03pI~
    int  opdno;                                                 //~v03pI~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt;	//filename opdno                                   //~vaw6I~
    char wkudold[_MAX_PATH],wkudnew[_MAX_PATH];                    //~vaw6R~
#endif                                                             //~vaw6I~
//********************                                          //~v03pI~
    if (!(pc=Ppcw->UCWparm))                                    //~v03pI~
        return errmissing();                                    //~v03pI~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v041R~
    if (opdno<2)                                                //~v03pI~
        return errmissing();                                    //~v03pI~
    if (opdno>2)                                                //~v03pI~
        return errtoomany();                                    //~v03pI~
    if (*pc=='*' && !*(pc+1))                                      //~v11LI~
                                                                   //~v20hI~
#ifdef UNX                                                         //~v20hI~
	{                                                              //~v20hI~
		if (dcmdconfallmemb("rename",fullpathold))                 //~v20hI~
			 return 4;                                             //~v20hR~
    }                                                              //~v20hI~
    else                                                           //~v20hI~
#else  //!UNX                                                      //~v20hI~
        return dcmdaster();                                        //~v20hR~
#endif //!UNX                                                      //~v20hI~
                                                                   //~v20hI~
#ifdef W32UNICODE                                                  //~vaw6I~//~vawvR~
    opt=0; //enclose when f2l err only                             //~vaw6I~//~vawvR~
  if (fsubw_cmdopdU8CT2UD(opt,Ppcw,0/*opd1*/,pc,wkudold,sizeof(wkudold),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~//~vawvR~
  {                                                                //~vaw6I~//~vawvR~
    if (!dcmdfullpath(Ppcw,fullpathold,wkudold)) //consider ::     //~vaw6I~//~vawvR~
        return 4;                                                  //~vaw6I~//~vawvR~
  }                                                                //~vaw6I~//~vawvR~
  else                                                             //~vaw6I~//~vawvR~
#endif                                                             //~vaw6I~//~vawvR~
//  if (!filefullpath(fullpathold,pc,_MAX_PATH))    //consider ::  //~v11HR~
    if (!dcmdfullpath(Ppcw,fullpathold,pc)) //consider ::          //~v11HI~
        return 4;                                               //~v03pI~
//#ifdef W32UNICODE                                                //~vawvR~
//    opt=FSWCOU8CT2UDO_PARTIAL;     //opd is partial of fpath     //~vawvR~
//    strcpy(wkudold,fullpathold);    //input when PARTIAL         //~vawvR~
//    if (!fsubw_cmdopdU8CT2UD(opt,Ppcw,0/*opd1*/,pc,wkudold,sizeof(wkudold),NULL/*outlen*/)==1)//enclosed by UD//~vawvR~
//        strcpy(fullpathold,wkudold);                             //~vawvR~
//#endif                                                           //~vawvR~
    pc+=strlen(pc)+1;   //next operand addr                     //~v03pI~
#ifdef W32UNICODE                                                  //~vaw6I~
	opt=0; //enclose when f2l err only                             //~vaw6I~
  if (fsubw_cmdopdU8CT2UD(opt,Ppcw,1/*opd2*/,pc,wkudnew,sizeof(wkudnew),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
    return dcmdrename(Ppcw,fullpathold,wkudnew,realnew);           //~vaw6I~
  else                                                             //~vaw6I~
#endif                                                             //~vaw6I~
    return dcmdrename(Ppcw,fullpathold,pc,realnew);                //~v11tR~
}//dcmd_rename                                                  //~v03pI~
//****************************************************************//~v03pI~
//!dcmdrename                                                   //~v03pI~
//* rename cmd                                                  //~v03pI~
//*parm1:pcw(UCWparm:operand)                                   //~v03pI~
//*parm2:fullpath old name                                      //~v03pI~
//*parm3:fullpath new name                                      //~v03pI~
//*retrn:rc                                                     //~v03pI~
//****************************************************************//~v03pI~
int dcmdrename(PUCLIENTWE Ppcw,UCHAR *Pfullpathold,UCHAR *Pnewname,UCHAR *Prealnew)//~v11tR~
{                                                               //~v03pI~
//  UCHAR fullpathnew[_MAX_PATH];                               //~v03pI~//~vb7gR~
//  UCHAR realfullpath[_MAX_PATH];                                 //~v11tI~//~vb7gR~
    UCHAR fullpathnew[_MAX_PATH_LONG];                             //~vb7gI~
    UCHAR realfullpath[_MAX_PATH_LONG];                            //~vb7gI~
    int pathlen;                                                   //~v07lI~
#ifdef FTPSUPP                                                     //~v717I~
    PUFTPHOST puftph;                                              //~v71eR~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v717I~
#endif                                                             //~v717I~
//********************                                          //~v03pI~
#ifdef FTPSUPP                                                     //~v71eM~
    uftpisremote(Pfullpathold,&puftph);                            //~v71eM~
  if (UFTPHISTSO(puftph))                                          //~v71eI~
  {                                                                //~v71eI~
    	u3270getmembname(0,Pfullpathold,membname);	//src is PDS member//~v71eI~
		pathlen=u3270pathlen(U3PL_PARENTORDROPMEMBER,Pnewname);    //~v71eI~
  }                                                                //~v71eI~
  else                                                             //~v71eI~
#endif                                                             //~v71eM~
		pathlen=PATHLEN(Pnewname);                                 //~v717I~
//  if (strpbrk(Pnewname,":*?")                                    //~v11tR~
    if (strpbrk(Pnewname,":")                                      //~v11tI~
//  ||  PATHLEN(Pnewname)>0)    //contain '\'                      //~v717R~
    ||  pathlen>0)    //contain '\'                                //~v717I~
    {                                                           //~v03pI~
//        uerrmsg("%s contain path or wild-card info",             //~v11tR~
//                "%s に経路またはワイルドカードの指定があります", //~v11tR~
        uerrmsg("%s contain path info",                            //~v11tI~
                "%s に経路の指定があります",                       //~v11tI~
                Pnewname);                                      //~v03pR~
        return 4;                                               //~v03pR~
    }                                                           //~v03pI~
#ifdef FTPSUPP                                                     //~v717I~
  if (UFTPHISTSO(puftph))                                          //~v717I~
  {                                                                //~v717I~
  	if (*membname)	//source is pds member                         //~v717I~
    	u3270concatfilename(U3CF_REPMEMBER,Pfullpathold,Pnewname,fullpathnew);//~v717R~
    else                                                           //~v717I~
    	u3270concatfilename(U3CF_REPLAST,Pfullpathold,Pnewname,fullpathnew);//~v71eI~
  }                                                                //~v717I~
  else                                                             //~v717I~
  {                                                                //~v717I~
#endif                                                             //~v717I~
    strcpy(fullpathnew,Pfullpathold);                           //~v03pI~
//  if (!(pc=strrchr(fullpathnew,'\\')))                           //~v07lR~
    if ((pathlen=PATHLEN(fullpathnew))<=0)    //no '\'             //~v07lI~
        return 4;                                               //~v03pI~
//  strcpy(pc+1,Pnewname);                                         //~v07lR~
    strcpy(fullpathnew+pathlen,Pnewname);                          //~v07lI~
#ifdef FTPSUPP                                                     //~v717I~
  }                                                                //~v717I~
#endif                                                             //~v717I~
//#ifdef AAA                                                       //~v717R~
    if (urename(Pfullpathold,fullpathnew,realfullpath))            //~v11tR~
        return 4;                                               //~v03pI~
    if (Prealnew)                                                  //~v11tR~
    {                                                              //~v11tI~
        *Prealnew=0;                                               //~v11tI~
        if (*realfullpath)                                         //~v11tI~
        {                                                          //~v11tI~
#ifdef FTPSUPP                                                     //~v71eI~
  		  if (UFTPHISTSO(puftph))                                  //~v71eI~
            u3270getlastname(0,realfullpath,Prealnew);             //~v71eI~
          else                                                     //~v71eI~
#endif                                                             //~v71eI~
            strcpy(Prealnew,realfullpath+PATHLEN(realfullpath));   //~v11tI~
            Pnewname=Prealnew;                                     //~v11tI~
        }                                                          //~v11tI~
    }                                                              //~v11tI~
//#endif                                                           //~v717R~
  if (!WILDCARD(Pfullpathold))                                     //~v11FI~
//  uerrmsg("%s was renamed to %s",                              //~v03pR~//~vawKR~//~vb7nR~
//          "%s を %s に変更",                                  //~v03pR~//~vb7nR~
    uerrmsg("Renamed %s to %s",                                    //~vb7nI~
            "改名済:%s を %s に",                                  //~vb7nI~
//          Pfullpathold,Pnewname);                                //~v11tR~//~vb08R~
            STD_FNM(Pfullpathold),Pnewname);                       //~vb08I~
    return 0;                                                   //~v03pR~
}//dcmdrename                                                   //~v03zR~
                                                                //~v03pI~
//****************************************************************//~v041I~
//!dcmd_xcopy                                                   //~v041I~
//* xcopy  cmd                                                  //~v041I~
//*parm1:pcw(UCWparm:operand)                                   //~v041I~
//*retrn:rc                                                     //~v041I~
//****************************************************************//~v041I~
int dcmd_xcopy(PUCLIENTWE Ppcw)                                 //~v041I~
{                                                               //~v041I~
    UCHAR fpath[2][_MAX_PATH];                                     //~v58gR~
    UCHAR *pc;                                                  //~v041I~
    int  opdno,ii,filectr=0;                                    //~v041R~
    int opt=DCPY_FAILEAS;  //meaningfull for os2                //~v041R~
    UINT attrmask=FILE_ALL-FILE_DIRECTORY;                      //~v041R~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt2,swdcmd;	//filename opdno                           //~vaw6I~
    char wkud[_MAX_PATH];                                          //~vaw6I~
    PFUNCTBL pft;                                                  //~vaw6I~
#endif                                                             //~vaw6I~
//********************                                          //~v041I~
    if (!(pc=Ppcw->UCWparm))                                    //~v041I~
//      return errmissing();                                       //~v13eR~
        return dcmdhelpcopy();                                     //~v13eR~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v041R~
    if (Sappendsw)                                                 //~v0iaI~
        opt|=DCPY_APPEND;                                          //~v0iaI~
#ifdef W32UNICODE                                                  //~vaw6I~
	pft=(PFUNCTBL)Ppcw->UCWpfunct;                                 //~vaw6R~
  	swdcmd=pft && (pft->FTfuncid==FUNCID_COPY||pft->FTfuncid==FUNCID_DOS);	//not dlcmd//~vaw6R~
#endif                                                             //~vaw6I~
#if defined(W32)||defined(UNX)                                     //~vaivI~
    opt|=DCPY_CHKSLINKTGT;  //default chk slink target             //~vaivI~
#endif                                                             //~vaivI~
    for (ii=0;ii<opdno;ii++)                                    //~v041I~
    {                                                           //~v041I~
//      switch (*pc)                                               //~v19DR~
        switch (CMDFLAGCHK(*pc,(filectr>1))) // '-' or 3rd '/'     //~v19QR~
        {                                                       //~v041I~
//      case '/':                                                  //~v19DR~
        case 1:                                                    //~v19DI~
            switch (*(pc+1))                                    //~v041I~
            {                                                   //~v041I~
            case 'R':                                           //~v042R~
            case 'r':                                           //~v042I~
            case 'Y':                                           //~v05bI~
            case 'y':                                           //~v05bI~
    		    if (Sappendsw)    //append cmd                     //~v575I~
	                return errinvalid(pc);                         //~v575I~
              if (*(pc+2)=='-')                                    //~v60gI~
                opt|=DCPY_SKIPEXIST; //skip override               //~v60gI~
              else                                                 //~v60gI~
              if (!*(pc+2))                                        //~v60gI~
                opt|=DCPY_EXISTING; //replace                   //~v041R~
              else                                                 //~v60gI~
	            return errinvalid(pc);                             //~v60gI~
                break;                                          //~v041I~
#ifdef FTPSUPP                                                     //~v71mI~
            case 'B':                                              //~v71mI~
            case 'b':                                              //~v71mI~
                opt|=DCPY_BIN;    //create source dir in target dir//~v71mI~
                break;                                             //~v71mI~
#endif                                                             //~v71mI~
            case 'C':                                              //~v572I~
            case 'c':                                              //~v572I~
    			if (Sappendsw)                                     //~v57qI~
	                return errinvalid(pc);                         //~v57qI~
                opt|=DCPY_CREATE;    //create source dir in target dir//~v572I~
                break;                                             //~v572I~
#ifndef OS2                                                        //~v58nI~
            case 'D':                                              //~v58nR~
            case 'd':                                              //~v58nR~
    			if (Sappendsw)                                     //~v58nR~
	                return errinvalid(pc);                         //~v58nR~
                opt|=DCPY_REPOLD|DCPY_EXISTING;    //replace old filetime only//~v58nR~
                break;                                             //~v58nR~
#endif                                                             //~v58nI~
//#ifdef W32                                                       //~vaivR~
#if defined(W32)||defined(UNX)                                     //~vaivI~
            case 'L':                                              //~vaitI~
            case 'l':                                              //~vaitI~
    			if (Sappendsw)                                     //~vaitI~
	                return errinvalid(pc);                         //~vaitI~
                else                                               //~vaivI~
                if (*(pc+2)=='-')                                  //~vaitI~
                    opt|= DCPY_SKIPSLINK; //reset sub dir copy     //~vaitI~
                else                                               //~vaitI~
                {                                                  //~vaivI~
                    opt&=~DCPY_SKIPSLINK; //reset sub dir copy     //~vaitI~
    	            if (toupper(*(pc+2))=='T')                     //~vaiyI~
                    {                                              //~vaiyI~
	                    opt|=DCPY_SLINKTGTF; //copy target if not dir//~vaiyR~
                        pc++;                                      //~vaiyI~
                    }                                              //~vaiyI~
    	            if (toupper(*(pc+2))=='M')                     //~vaivR~
        	        {                                              //~vaivI~
	    	            if (*(pc+3)=='-')                          //~vaivR~
    						opt&=~DCPY_CHKSLINKTGT;                //~vaivI~
                        else                                       //~vaivI~
    						opt|=DCPY_CHKSLINKTGT;                 //~vaivI~
            	    }                                              //~vaivI~
                }                                                  //~vaivI~
                break;                                             //~vaitI~
#endif                                                             //~vaitI~
#ifdef UNX                                                         //~v45JI~
            case 'N':                                              //~v45JI~
            case 'n':                                              //~v45JI~
                opt|=DCPY_NOCOPYINFO; //bypass setpathinfo         //~v45JI~
                break;                                             //~v45JI~
#endif                                                             //~v45JI~
            case '+':                                           //~v041I~
                opt|=DCPY_APPEND;       //append                //~v041R~
                break;                                          //~v041I~
            case ':':                                           //~v041I~
                opt|=DCPY_ROOT;     //target root support       //~v041R~
                break;                                          //~v041I~
            case 'S':                                           //~v041I~
            case 's':                                           //~v041I~
                if (Sappendsw)                                     //~v135I~
                    return errinvalid(pc);                         //~v135I~
                if (*(pc+2)=='-')                               //~v05YI~
//                  attrmask&=~FILE_DIRECTORY;  //reset sub dir copy//~vb06R~
                    attrmask&=(UINT)(~FILE_DIRECTORY);  //reset sub dir copy//~vb06I~
                else                                            //~v05YI~
                    attrmask|=FILE_DIRECTORY;   //sub dir copy  //~v05YR~
                break;                                          //~v041I~
#ifdef FTPSUPP                                                     //~v59gI~
            case 'T':                                              //~v59gI~
            case 't':                                              //~v59gI~
                opt|=DCPY_FTPTEXTMODE;  //textmode                 //~v59gI~
                break;                                             //~v59gI~
#endif                                                             //~v59gI~
#ifdef UNX                                                         //~vaa0I~
            case 'W':                                              //~vaa0I~
            case 'w':                                              //~vaa0I~
                opt|=DCPY_REPWILDNAME;  //wildcard rename copy     //~vaa0I~
                break;                                             //~vaa0I~
#endif                                                             //~vaa0I~
            default:                                            //~v041I~
                return errinvalid(pc);                          //~v041I~
            }                                                   //~v041I~
            break;                                              //~v041I~
        default:                                                //~v041I~
            if (filectr>1)                                      //~v041I~
                return errtoomany();                            //~v041I~
            if (filectr)                                        //~v05OI~
            {                                                   //~v05OI~
//              if (!filefullpath2(fullpath[1],pc,_MAX_PATH,fullpath[0]))//~v11JR~
//              if (!dcmdfullpath(Ppcw,fpath[1],pc)) //consider :: *\ etc//~v646R~
#ifdef W32UNICODE                                                  //~vaw6I~
				opt2=0; //enclose when f2l err only                //~vaw6I~
  			  if (swdcmd && fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opdno*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
              {                                                    //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[1],wkud)) //consider :: *\ etc,expand wildpath//~vaw6I~
                    return 4;   //chk *\/-\ etc                    //~vaw6I~
              }                                                    //~vaw6I~
  			  else                                                 //~vaw6I~
#endif                                                             //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[1],pc)) //consider :: *\ etc,expand wildpath//~v646R~
                    return 4;   //chk *\/-\ etc                 //~v05OI~
//                if (WILDCARD(fullpath[1]))   //contain * yet after *\ process//~v11JR~
//                    ufileeditname(fullpath[0],fullpath[1],fullpath[1]);    //determin target//~v11JR~
            }                                                   //~v05OI~
            else                                                //~v05OI~
            {                                                      //~v11LI~
                if (*pc=='*' && !*(pc+1))                          //~v11LI~
#ifdef UNX                                                         //~v20hI~
				{                                                  //~v20hI~
					if (dcmdconfallmemb("xcopy",fpath[0]))         //~v58gR~
			 			return 4;                                  //~v20hR~
    			}                                                  //~v20hI~
    			else                                               //~v20hI~
#else  //!UNX                                                      //~v20hI~
                    return dcmdaster();                            //~v20hR~
#endif //!UNX                                                      //~v20hI~
//              if (!filefullpath(fullpath[0],pc,_MAX_PATH))    //consider :://~v11HR~
//              if (!dcmdfullpath(Ppcw,fpath[0],pc)) //consider :: *\ etc//~v646R~
#ifdef W32UNICODE                                                  //~vaw6I~
				opt2=0; //enclose when f2l err only                //~vaw6I~
  			  if (swdcmd && fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opdno*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
              {                                                    //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[0],wkud)) //consider :: *\ etc,expand wildpath//~vaw6I~
                    return 4;   //chk *\/-\ etc                    //~vaw6I~
              }                                                    //~vaw6I~
  			  else                                                 //~vaw6I~
#endif                                                             //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[0],pc)) //consider :: *\ etc//~v646R~
                    return 4;                                   //~v05OR~
            }                                                      //~v11LI~
            filectr++;                                          //~v041R~
            break;                                              //~v041I~
        }                                                       //~v041I~
        pc+=strlen(pc)+1;   //next operand addr                 //~v041I~
    }                                                           //~v041I~
    if (filectr<2)                                              //~v041I~
        return errmissing();                                    //~v041I~
    if (opt & DCPY_APPEND)       //append                          //~v575I~
    	opt&=~DCPY_EXISTING; 		//ignore replace option        //~v575I~
    if (opt & DCPY_CREATE)    //create source dir in target dir    //~vavKI~
    {                                                              //~vavKI~
    	if (WILDCARD(fpath[1]))                                    //~vawKR~
        {                                                          //~vavKI~
	    	char fpathwildrename[_MAX_PATH];                       //~vavKI~
//          int opt2=DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE;           //~vavKI~//~vb71R~
            int opt3=DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE;          //~vb71I~
        //**************                                           //~vawKI~
    		if (WILDCARD(fpath[0]))                                //~vawKM~
            {                                                      //~vawKM~
			    uerrmsg("wild card source(%s) is invalid with Create(-c) option for xcopy to wildcard target(%s)",//~vawKM~
                "ワイルドカード\x83\\ース(%s)はワイルドカード宛先(%s)に -C オプションで xcopy できません",//~vawKM~
                fpath[0],fpath[1]);                                //~vawKM~
                return 4;                                          //~vawKM~
            }                                                      //~vawKM~
//  		ufileeditname(opt2,fpath[0],fpath[1],fpathwildrename);  //~vavKR~//~vb71R~
    		ufileeditname(opt3,fpath[0],fpath[1],fpathwildrename); //~vb71I~
            opt|=DCPY_CREATERENAME;    //create renamed target dir if not exist//~vawKI~
		    return dcmdxcopy(Ppcw,fpath[0],fpathwildrename,opt,attrmask);//~vavKI~
        }                                                          //~vavKI~
    }                                                              //~vavKI~
    return dcmdxcopy(Ppcw,fpath[0],fpath[1],opt,attrmask);         //~v58gR~
}//dcmd_xcopy                                                   //~v041I~
                                                                //~v041I~
//**************************************************************** //~v0iaI~
//!dcmd_append                                                     //~v0iaI~
//* xcopy  cmd                                                     //~v0iaI~
//*parm1:pcw(UCWparm:operand)                                      //~v0iaI~
//*retrn:rc                                                        //~v0iaI~
//**************************************************************** //~v0iaI~
int dcmd_append(PUCLIENTWE Ppcw)                                   //~v0iaI~
{                                                                  //~v0iaI~
    int rc;                                                        //~v0iaI~
//*********************                                            //~v0iaI~
    if (!Ppcw->UCWparm)                                            //~v13eI~
        return dcmdhelpappend();                                   //~v13eR~
    Sappendsw=1;    //parm to dcmd_xcopy                           //~v0iaI~
    rc=dcmd_xcopy(Ppcw);                                           //~v0iaI~
    Sappendsw=0;                                                   //~v0iaI~
    return rc;                                                     //~v0iaI~
}//dcmd_append                                                     //~v0iaI~
                                                                   //~v0iaI~
//****************************************************************//~v041I~
//!dcmdxcopy                                                    //~v041I~
//* rename cmd                                                  //~v041I~
//*parm1:pcw(UCWparm:operand)                                   //~v041I~
//*parm2:fullpath source name                                   //~v041I~
//*parm3:fullpath target name                                   //~v041I~
//*parm4:option(replace)                                        //~v041I~
//*parm5:file selection attr mask                               //~v041I~
//*retrn:rc                                                     //~v041I~
//****************************************************************//~v041I~
int dcmdxcopy(PUCLIENTWE Ppcw,UCHAR *Psource,UCHAR *Ptarget,int Popt,UINT Pattrmask)//~v041R~
{                                                               //~v041I~
    UCHAR fpth[_MAX_PATH];                                         //~v13eI~
    FILEFINDBUF3 fstat3;                                           //~v13eI~
#ifdef FTPSUPP                                                     //~v71eI~
    PUFTPHOST puftph;                                              //~v71eI~
#endif                                                             //~v71eI~
	int opt;                                                       //~vaivI~
	int rc;                                                        //~vaivI~
//********************                                          //~v041I~
#ifdef FTPSUPP                                                     //~v71eI~
    uftpisremote(Psource,&puftph);                                 //~v71eI~
  if (!UFTPHISTSO(puftph))                                         //~v71eI~
  {                                                                //~v71eI~
    uftpisremote(Ptarget,&puftph);                                 //~v71eI~
   if (!UFTPHISTSO(puftph))                                        //~v71eI~
   {                                                               //~v71eI~
#endif                                                             //~v71eI~
//  if (!ROOTDIR(Psource) && !WILDCARD(Psource) && WILDCARD(Ptarget))  //contain * yet after *\ process//~v48bR~
//  if (!ROOTDIR2(Psource) && !WILDCARD(Psource) && WILDCARD(Ptarget))  //contain * yet after *\ process//~v54jR~
    if (!ROOTDIR3(Psource) && !WILDCARD(Psource) && WILDCARD(Ptarget))  //contain * yet after *\ process//~v54jR~
        if (ufstat(Psource,&fstat3) //not found                    //~v13eR~
        ||  !UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))//not dir    //~v13eI~
        {                                                          //~v13eI~
//          ufileeditname(Psource,Ptarget,fpth);    //determin target//~v49jR~
            ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,Psource,Ptarget,fpth);    //determin target//~v49jI~
            Ptarget=fpth;                                          //~v13eR~
        }                                                          //~v13eR~
#ifdef FTPSUPP                                                     //~v71eI~
   }                                                               //~v71eI~
  }                                                                //~v71eI~
#endif                                                             //~v71eI~
//  if (uxcopy(Psource,Ptarget,Popt,Pattrmask))                    //~vaivR~
	opt=Popt;                                                      //~vaivI~
//  if (uxcopy(Psource,Ptarget,opt,Pattrmask))                     //~vaivR~
    rc=uxcopy(Psource,Ptarget,opt,Pattrmask);                      //~vaivI~
//  if (rc==DCPY_RC_WARNING)                                       //~vaivI~//~vaiAR~
//  	return 0;                                                  //~vaivI~//~vaiAR~
//  else                                                           //~vaivI~//~vaiAR~
    if (rc)                                                        //~vaivI~
        return 4;                                               //~v041I~
	if (Gufile_opt & GFILEOPT_RC_WARNING)	                              //~v6kdI~//~vaiAI~
    {                                                              //~vaiAI~
        if (Popt & DCPY_APPEND)                                    //~vaiAI~
            uerrmsgcat("; %s was appended to %s",                   //~vaiAI~//~vawKR~
                    "; %s を %s に連結",                           //~vaiAI~
//                  Psource,Ptarget);                              //~vaiAI~//~vb08R~
                    STD_FNM(Psource),STD_FNM(Ptarget));            //~vb08I~
        else                                                       //~vaiAI~
          if (Popt & DCPY_CREATE)    //create source dir in target dir//~vaiAI~
            uerrmsgcat("; %s was copyed to %s with /c option.",     //~vaiAR~//~vawKR~
                    "; %s を %s に複写(/cオプション)。",           //~vaiAI~
//                  Psource,Ptarget);                              //~vaiAI~//~vb08R~
                    STD_FNM(Psource),STD_FNM(Ptarget));            //~vb08I~
          else                                                     //~vaiAI~
            uerrmsgcat("; %s was copyed to %s",                     //~vaiAR~//~vawKR~
                    "; %s を %s に複写",                           //~vaiAI~
//                  Psource,Ptarget);                              //~vaiAI~//~vb08R~
                    STD_FNM(Psource),STD_FNM(Ptarget));            //~vb08I~
    	return 0;                           //left slink err warning//~vaiAI~
    }                                                              //~vaiAI~
    if (Popt & DCPY_APPEND)                                     //~v041I~
//      uerrmsg("%s is copied to %s",                              //~v486R~
        uerrmsg("%s was appended to %s",                            //~v486I~//~vawKR~
                "%s を %s に連結",                              //~v041I~
//              Psource,Ptarget);                               //~v041I~//~vb08R~
                STD_FNM(Psource),STD_FNM(Ptarget));                //~vb08I~
    else                                                        //~v041I~
      if (Popt & DCPY_CREATE)    //create source dir in target dir //~v572I~
      {                                                            //~vawKI~
       if (Popt & DCPY_CREATERENAME)    //create source dir in target dir//~vawKI~
        uerrmsg("%s was rename-copyed to %s with /c option.",      //~vawKR~
                "%s を %s に改名複写(/cオプション)。",             //~vawKI~
//              Psource,Ptarget);                                  //~vawKI~//~vb08R~
                STD_FNM(Psource),STD_FNM(Ptarget));                //~vb08I~
       else                                                        //~vawKI~
        uerrmsg("%s was copyed to %s with /c option.",              //~v572I~//~vawKR~
                "%s を %s に複写(/cオプション)。",                 //~v572I~
//              Psource,Ptarget);                                  //~v572I~//~vb08R~
                STD_FNM(Psource),STD_FNM(Ptarget));                //~vb08I~
      }                                                            //~vawKI~
      else                                                         //~v572I~
        uerrmsg("%s was copyed to %s",                              //~v486R~//~vawKR~
                "%s を %s に複写",                              //~v041R~
//              Psource,Ptarget);                               //~v041R~//~vb08R~
                STD_FNM(Psource),STD_FNM(Ptarget));                //~vb08I~
    return 0;                                                   //~v041I~
}//dcmdxcopy                                                       //~v07lR~
                                                                //~v041I~
//****************************************************************//~v05iI~
//!dcmd_xmove                                                   //~v05iI~
//* xmove  cmd                                                  //~v05iI~
//*parm1:pcw(UCWparm:operand)                                   //~v05iI~
//*retrn:rc                                                     //~v05iI~
//****************************************************************//~v05iI~
int dcmd_xmove(PUCLIENTWE Ppcw)                                 //~v05iI~
{                                                               //~v05iI~
    UCHAR fpath[2][_MAX_PATH];                                     //~v58gR~
    UCHAR *pc;                                                  //~v05iI~
    int  opdno,ii,filectr=0,rc;                                 //~v05iR~
    UINT attrmask=FILE_ALL-FILE_DIRECTORY;                      //~v05iI~
    FILEFINDBUF3 fstat3;                                           //~v13eI~
    int opt=0;                                                     //~v45HI~
#ifdef FTPSUPP                                                     //~v717I~
    PUFTPHOST puftph;                                              //~v717I~
#endif                                                             //~v717I~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt2,swdcmd;	//filename opdno                           //~vaw6I~
    char wkud[_MAX_PATH];                                          //~vaw6I~
    PFUNCTBL pft;                                                  //~vaw6I~
#endif                                                             //~vaw6I~
//********************                                          //~v05iI~
    if (!(pc=Ppcw->UCWparm))                                    //~v05iI~
//      return errmissing();                                       //~v13eR~
        return dcmdhelpmove();                                     //~v13eR~
#ifdef W32UNICODE                                                  //~vaw6I~
	pft=(PFUNCTBL)Ppcw->UCWpfunct;                                 //~vaw6I~
  	swdcmd=pft && (pft->FTfuncid==FUNCID_MOVE||pft->FTfuncid==FUNCID_DOS);	//not dlcmd//~vaw6R~
#endif                                                             //~vaw6I~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v05iI~
#if defined(W32)||defined(UNX)                                     //~vaivI~
    opt|=DCPY_CHKSLINKTGT;  //default chk slink target             //~vaivI~
#endif                                                             //~vaivI~
    for (ii=0;ii<opdno;ii++)                                    //~v05iI~
    {                                                           //~v05iI~
//      switch (*pc)                                               //~v19DR~
        switch (CMDFLAGCHK(*pc,(filectr>1))) // '-' or 3rd '/'     //~v19QR~
        {                                                       //~v05iI~
//      case '/':                                                  //~v19DR~
        case 1:                                                    //~v19DI~
            switch (*(pc+1))                                    //~v05iI~
            {                                                   //~v05iI~
#ifdef FTPSUPP                                                     //~v71mI~
            case 'B':                                              //~v71mI~
            case 'b':                                              //~v71mI~
                opt|=DCPY_BIN;    //create source dir in target dir//~v71mI~
                break;                                             //~v71mI~
#endif                                                             //~v71mI~
            case 'S':                                           //~v05iI~
            case 's':                                           //~v05iI~
                attrmask|=FILE_DIRECTORY;   //sub dir copy      //~v05iI~
                break;                                          //~v05iI~
            case 'R':                                              //~v45HI~
            case 'r':                                              //~v45HI~
            case 'Y':                                              //~v45HI~
            case 'y':                                              //~v45HI~
              if (*(pc+2)=='-')                                    //~v60gI~
                opt|=DCPY_SKIPEXIST; //skip override               //~v60gI~
              else                                                 //~v60gI~
              if (!*(pc+2))                                        //~v60gI~
                opt|=DCPY_EXISTING; //replace                      //~v45HI~
              else                                                 //~v60gI~
                return errinvalid(pc);                             //~v60gI~
                break;                                             //~v45HI~
#ifndef OS2                                                        //~v58nI~
            case 'D':                                              //~v58nR~
            case 'd':                                              //~v58nR~
                opt|=DCPY_REPOLD|DCPY_EXISTING;    //replace old filetime only//~v58nI~
                break;                                             //~v58nR~
#endif                                                             //~v58nI~
#if defined(W32)||defined(UNX)                                     //~vaivI~
            case 'L':                                              //~vaivI~
            case 'l':                                              //~vaivI~
                if (*(pc+2)=='-')                                  //~vaivI~
                    opt|= DCPY_SKIPSLINK; //reset sub dir copy     //~vaivI~
                else                                               //~vaivI~
                {                                                  //~vaivI~
                    opt&=~DCPY_SKIPSLINK; //reset sub dir copy     //~vaivI~
    	            if (toupper(*(pc+2))=='M')                     //~vaivR~
        	        {                                              //~vaivI~
	    	            if (*(pc+3)=='-')                          //~vaivR~
    						opt&=~DCPY_CHKSLINKTGT;                //~vaivI~
                        else                                       //~vaivI~
    						opt|=DCPY_CHKSLINKTGT;                 //~vaivI~
            	    }                                              //~vaivI~
                }                                                  //~vaivI~
                break;                                             //~vaivI~
#endif                                                             //~vaivI~
#ifdef FTPSUPP                                                     //~v59gI~
            case 'T':                                              //~v59gI~
            case 't':                                              //~v59gI~
                opt|=DCPY_FTPTEXTMODE;  //textmode                 //~v59gI~
                break;                                             //~v59gI~
#endif                                                             //~v59gI~
#ifdef UNX                                                         //~vaa0I~
            case 'W':                                              //~vaa0I~
            case 'w':                                              //~vaa0I~
                opt|=DCPY_REPWILDNAME;  //wildcard rename copy for the case different file system(rename allow invalidname but)//~vaa0I~
                break;                                             //~vaa0I~
#endif                                                             //~vaa0I~
            default:                                            //~v05iI~
                return errinvalid(pc);                          //~v05iI~
            }                                                   //~v05iI~
            break;                                              //~v05iI~
        default:                                                //~v05iI~
            if (filectr>1)                                      //~v05iI~
                return errtoomany();                            //~v05iI~
            if (filectr)                                        //~v05OI~
            {                                                   //~v05OI~
//              if (!filefullpath2(fullpath[1],pc,_MAX_PATH,fullpath[0]))//~v11JR~
//              if (!dcmdfullpath(Ppcw,fpath[1],pc)) //consider :: *\ etc//~v646R~
#ifdef W32UNICODE                                                  //~vaw6I~
				opt2=0; //enclose when f2l err only                //~vaw6I~
  			  if (swdcmd && fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opdno*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
              {                                                    //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[1],wkud)) //consider :: *\ etc,expand wildpath//~vaw6I~
                    return 4;   //chk *\/-\ etc                    //~vaw6I~
              }                                                    //~vaw6I~
  			  else                                                 //~vaw6I~
#endif                                                             //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[1],pc)) //consider :: *\ etc//~v646R~
                    return 4;   //chk *\/-\ etc                 //~v05OI~
//                if (WILDCARD(fullpath[1]))   //contain * yet after *\ process//~v11JR~
//                    ufileeditname(fullpath[0],fullpath[1],fullpath[1]);    //determin target//~v11JR~
            }                                                   //~v05OI~
            else                                                //~v05OI~
            {                                                      //~v11LI~
                if (*pc=='*' && !*(pc+1))                          //~v11LI~
#ifdef UNX                                                         //~v20hI~
				{                                                  //~v20hI~
					if (dcmdconfallmemb("xmove",fpath[0]))         //~v58gR~
			 			return 4;                                  //~v20hR~
    			}                                                  //~v20hI~
    			else                                               //~v20hI~
#else  //!UNX                                                      //~v20hI~
                    return dcmdaster();                            //~v20hR~
#endif //!UNX                                                      //~v20hI~
//              if (!filefullpath(fullpath[0],pc,_MAX_PATH))    //consider :://~v11HR~
//              if (!dcmdfullpath(Ppcw,fpath[0],pc)) //consider :: *\ etc//~v646R~
#ifdef W32UNICODE                                                  //~vaw6I~
				opt2=0; //enclose when f2l err only                //~vaw6I~
  			  if (swdcmd && fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opdno*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
              {                                                    //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[0],wkud)) //consider :: *\ etc,expand wildpath//~vaw6I~
                    return 4;   //chk *\/-\ etc                    //~vaw6I~
              }                                                    //~vaw6I~
  			  else                                                 //~vaw6I~
#endif                                                             //~vaw6I~
                if (!dcmdfullpathwild(XESUB_GBLOPT_WILDPATH,Ppcw,fpath[0],pc)) //consider :: *\ etc//~v646R~
                    return 4;                                   //~v05OR~
            }                                                      //~v11LI~
            filectr++;                                          //~v05iI~
            break;                                              //~v05iI~
        }                                                       //~v05iI~
        pc+=strlen(pc)+1;   //next operand addr                 //~v05iI~
    }                                                           //~v05iI~
    if (filectr<2)                                              //~v05iI~
        return errmissing();                                    //~v05iI~
#ifdef FTPSUPP                                                     //~v71gI~
    uftpisremote(fpath[0],&puftph);                                //~v71gR~
  if (!UFTPHISTSO(puftph))                                         //~v71gI~
  {                                                                //~v71gI~
    uftpisremote(fpath[1],&puftph);                                //~v71gR~
   if (!UFTPHISTSO(puftph))                                        //~v71gI~
   {                                                               //~v71gI~
#endif                                                             //~v71gI~
//  if (!ROOTDIR(fullpath[0]) && !WILDCARD(fullpath[0]) && WILDCARD(fullpath[1]))  //contain * yet after *\ process//~v48bR~
//  if (!ROOTDIR2(fullpath[0]) && !WILDCARD(fullpath[0]) && WILDCARD(fullpath[1]))  //contain * yet after *\ process//~v54jR~
    if (!ROOTDIR3(fpath[0]) && !WILDCARD(fpath[0]) && WILDCARD(fpath[1]))  //contain * yet after *\ process//~v58gR~
        if (ufstat(fpath[0],&fstat3) //not found                   //~v58gR~
        ||  !UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))//not dir    //~v13eI~
//          ufileeditname(fullpath[0],fullpath[1],fullpath[1]);    //determin target//~v49jR~
            ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,fpath[0],fpath[1],fpath[1]);    //determin target//~v58gR~
#ifdef FTPSUPP                                                     //~v71gI~
   }                                                               //~v71gI~
  }                                                                //~v71gI~
#endif                                                             //~v71gI~
    pc=fpath[1];                                                   //~v58gR~
//  if (rc=uxmove(fullpath[0],pc,attrmask),rc)                     //~v45HR~
#ifdef AIX                                                         //~v48mI~
    if (MDOSDISKOK(fpath[0]))	//delete aix mdos disk             //~v58gR~
      	opt|=DCPY_NODELDIRMOVE;                                    //~v48mI~
#endif                                                             //~v48mI~
    if (rc=uxmove(fpath[0],pc,attrmask,opt),rc)                    //~v58gR~
    {                                                              //~vaivI~
//    if (rc!=DCPY_RC_WARNING)                                     //~vaivI~//~vaiAR~
        return 4;                                               //~v05iI~
    }                                                              //~vaivI~
//  if (*(pc+strlen(pc)-1)=='\\')   //uxmove set last '\' if target is dir//~v07lR~
#ifdef FTPSUPP                                                     //~v717I~
    uftpisremote(pc,&puftph);                                      //~v717I~
  if (UFTPHISTSO(puftph))   //target is TSO                        //~v71gR~
  {                                                                //~v717I~
    if (MEMBOFDSN(pc)==0)  //no membername specified(upload allowed to PDS only)//~v71gR~
        Ppcw->UCWreason=1;  //target is dir                        //~v717I~
    else                                                           //~v717I~
        Ppcw->UCWreason=0;  //clear id of target is dir            //~v717I~
  }                                                                //~v717I~
  else                                                             //~v717I~
  {                                                                //~v717I~
#endif                                                             //~v717I~
    if (PATHLEN(pc)==(int)strlen(pc))    //uxmove set last '\' if target is dir//~v085R~
        Ppcw->UCWreason=1;  //target is dir                     //~v05OI~
    else                                                        //~v05OI~
        Ppcw->UCWreason=0;  //clear id of target is dir         //~v05OI~
#ifdef FTPSUPP                                                     //~v717I~
  } //!TSO                                                         //~v717I~
#endif                                                             //~v717I~
//if (rc==DCPY_RC_WARNING)                                         //~vaivR~//~vaiAR~
//  rc=0;                                                          //~vaivI~//~vaiAR~
//else                                                             //~vaivI~//~vaiAR~
  if ((Gufile_opt & GFILEOPT_RC_WARNING))                          //~vaiAR~
    uerrmsgcat("; %s was moved to %s",                              //~vaiAI~//~vawKR~
            "; %s を %s に移動",                                   //~vaiAI~
//          fpath[0],fpath[1]);                                    //~vaiAI~//~vb08R~
            STD_FNM(fpath[0]),STD_FNM(fpath[1]));                  //~vb08I~
  else                                                             //~vaiAI~
    uerrmsg("%s was moved to %s",                                //~v05iR~//~vawKR~
            "%s を %s に移動",                                  //~v05iR~
//          fpath[0],fpath[1]);                                    //~v58gR~//~vb08R~
            STD_FNM(fpath[0]),STD_FNM(fpath[1]));                  //~vb08I~
    return 0;                                                   //~v05iR~
}//dcmd_xmove                                                   //~v05iI~
                                                                //~v05iI~
//**************************************************************** //~v208I~
//!dcmd_chmod                                                      //~v208I~
//* attribute display/change                                       //~v208I~
//*parm1:pcw(UCWparm:operand)                                      //~v208I~
//*retrn:rc                                                        //~v208I~
//**************************************************************** //~v208I~
int dcmd_chmod(PUCLIENTWE Ppcw)                                    //~v208I~
{                                                                  //~v208I~
    if (!Ppcw->UCWparm)                                            //~v208I~
    {                                                              //~v208I~
		return dcmdattribhelp("CHM");                              //~v208I~
    }                                                              //~v208I~
	return dcmd_attribute(Ppcw);                                   //~v208I~
}//dcmd_chmod                                                      //~v208I~
//****************************************************************//~v03pI~
//!dcmd_attribute                                               //~v03pI~
//* attribute display/change                                    //~v03zR~
//*parm1:pcw(UCWparm:operand)                                   //~v03pI~
//*retrn:rc                                                     //~v03pI~
//****************************************************************//~v03pI~
int dcmd_attribute(PUCLIENTWE Ppcw)                             //~v03zR~
{                                                               //~v03pI~
    UCHAR *pc;                                                  //~v03zR~
//#ifdef  UNX                                                      //~v59fR~
#ifdef  FTPSUPP                                                    //~v59LI~
    UCHAR *fnm1st;                                                 //~v47FI~
#endif                                                             //~v59LR~
    int   opdno,ii,filectr=0;                                   //~v041R~
#ifdef  UNX                                                        //~v19cR~
    ULONG attron=0,attroff=0,attr;                                 //~v19cI~
//  int mdossw;                                                    //~v47CI~//~vac2R~
    int mdossw=0;                                                  //~vac2I~
#else //!UNX                                                       //~v19cI~
//    UCHAR attron=0,attroff=0,attr;                               //~v53QR~
    ULONG attron=0,attroff=0,attr;                                 //~v53QI~
#endif//!UNX                                                       //~v19cI~
    UCHAR fpath[_MAX_PATH];                                        //~v58gR~
    WCPARMATTR wcattr;                                          //~v041I~
#ifdef FTPSUPP                                                     //~v59gI~
//#ifndef UNX                                                      //~v59gI~//~vac2R~
    int hostnmlen;                                                 //~v59gR~
    int hostnmlen2;                                                //~v59gM~
    PUFTPHOST  puftph=0;                                           //~v59gR~
//#endif                                                           //~v59gI~//~vac2R~
    PUFTPHOST  puftph2=0;                                          //~v59gI~
#endif                                                             //~v59fI~
#ifdef W32UNICODE                                                  //~vaw6I~
    int opt2;                                                      //~vaw6I~
    char wkud[_MAX_PATH];                                          //~vaw6I~
#endif                                                             //~vaw6I~
//********************                                          //~v03pI~
    if (!(pc=Ppcw->UCWparm))                                    //~v03zI~
    {                                                              //~v207I~
//      return errmissing();                                       //~v207R~
		return dcmdattribhelp("ATT");                              //~v208I~
    }                                                              //~v207I~
    UPARSERC(pc,pc,&opdno,0,",");   //parse out string(accept cr/lf)//~v041R~
//  if (opdno<2)                                                   //~v47FR~
    if (!opdno)                                                    //~v47FI~
        return errmissing();                                       //~v47CI~
    if (opdno==1)                                                  //~v47FI~
    {                                                              //~v47FI~
        filectr=1;                                                 //~v47FI~
//#ifdef  UNX                                                      //~v59fR~
#ifdef  FTPSUPP                                                    //~v59LI~
    	fnm1st=pc;                                                 //~v47FI~
#endif                                                             //~v59LR~
    }                                                              //~v47FI~
    else                                                           //~v47FI~
    {                                                              //~v47FI~
		filectr=opdno-1;                                           //~v47FI~
//#ifdef  UNX                                                      //~v59fR~
#ifdef  FTPSUPP                                                    //~v59LI~
    	fnm1st=pc+strlen(pc)+1;	//fnm is from 2nd opd              //~v47FI~
#endif                                                             //~v59LR~
    }                                                              //~v47FI~
#ifdef UNX                                                         //~v47CI~
//  mdossw=MDOSDISKOK(pc+strlen(pc)+1);	//mdos attr fmt            //~v47FR~
    mdossw=MDOSDISKOK(fnm1st);	//mdos attr fmt                    //~v47FI~
#endif                                                             //~v47CI~
#ifdef FTPSUPP                                                     //~v59fI~
	if (!dcmdfullpath(Ppcw,fpath,fnm1st)) //consider :: *\ etc     //~v59fI~
    	return 4;                                                  //~v59fI~
	if (u3270fullpathistso(fnm1st))                                //~v728I~
    	return errnotsupported("Attrib","TSO DataSet");            //~v728I~
//#ifndef UNX                                                      //~v59gI~//~vac2R~
    hostnmlen=uftpisremote(fpath,&puftph);	//allow not-x for remote file//~v59fI~
//#endif                                                           //~v59gI~//~vac2R~
#endif                                                             //~v59fI~
//    for (ii=0;ii<opdno;ii++)                                     //~v206R~
//    {                                                            //~v206R~
//        switch (*pc)                                             //~v206R~
//        {                                                        //~v206R~
//        case '+':                                                //~v206R~
//        case '-':                                                //~v206R~
//        case '/':                                                //~v206R~
	if (opdno==1)                                                  //~v47FI~
    	attron=attroff=0;		//display cur attr                 //~v47FI~
    else                                                           //~v47FI~
    {                                                              //~v47FI~
#ifdef UNX                                                         //~v47CI~
    	if (puftph && puftph->UFTPHflag & UFTPHFRWIN) //remote target is windows//~vac2I~
        {                                                          //~vac2I~
            if (dcmdattrchk(pc,&attron,&attroff,mdossw|DCACO_RWIN))//accum flag//~vac2I~
                return 4;                                          //~vac2I~
        }                                                          //~vac2I~
        else                                                       //~vac2I~
            if (dcmdattrchk(pc,&attron,&attroff,mdossw))//accum flag//~v47CI~
#else                                                              //~v47CI~
    #ifdef FTPSUPP                                                 //~v59fI~
        if (hostnmlen)                                             //~v59fI~
        {                                                          //~v59fI~
            if (puftph->UFTPHflag & UFTPHFRWIN) //remote target is windows//~vac2I~
            {                                                      //~vac2I~
              if (dcmdattrchk(pc,&attron,&attroff))//accum flag    //~vac2I~
                return 4;                                          //~vac2I~
            }                                                      //~vac2I~
            else                                                   //~vac2I~
            if (dcmdattrchkunix(pc,&attron,&attroff))//remotefile attr chk//~v59fR~
                return 4;                                          //~v59fI~
        }                                                          //~v59fI~
        else                                                       //~v59fI~
    #endif                                                         //~v59fI~
            if (dcmdattrchk(pc,&attron,&attroff))//accum flag   //~v03zR~
#endif                                                             //~v47CI~
                return 4;                                       //~v03zI~
	}                                                              //~v47FI~
//            break;                                               //~v206R~
//        default:                                                 //~v206R~
//            filectr++;                                           //~v206R~
//            break;                                               //~v206R~
//        }                                                        //~v206R~
//        pc+=strlen(pc)+1;   //next operand addr                  //~v206R~
//    }                                                            //~v206R~
//  filectr=opdno-1;                                               //~v47FR~
//  if (!filectr)                                                  //~v47CR~
//      return errmissing();                                       //~v47CR~
    pc=Ppcw->UCWparm;                                           //~v03zI~
    for (ii=0;ii<opdno;ii++)                                    //~v03zI~
    {                                                           //~v03zI~
//        switch (*pc)                                             //~v206R~
//        {                                                        //~v206R~
//        case '+':                                                //~v206R~
//        case '-':                                                //~v206R~
//        case '/':                                                //~v206R~
//            break;                                               //~v206R~
//        default:                                                 //~v206R~
//          if (!filefullpath(fullpath,pc,_MAX_PATH))   //consider :://~v11HR~
//      if (ii) //not 1st                                          //~v47FR~
        if (ii||opdno==1) //not 1st or display case                //~v47FI~
        {                                                          //~v206I~
            if (*pc=='*' && !*(pc+1))                              //~v11LI~
#ifdef UNX                                                         //~v20hI~
            {                                                      //~v20hI~
                if (dcmdconfallmemb("attr",fpath))                 //~v58gR~
                    return 4;                                      //~v20hR~
            }                                                      //~v20hI~
            else                                                   //~v20hI~
#else  //!UNX                                                      //~v20hI~
                return dcmdaster();                                //~v20hR~
#endif //!UNX                                                      //~v20hI~
#ifdef W32UNICODE                                                  //~vaw6M~
    		opt2=0; //enclose when f2l err only                    //~vaw6I~
  		  if (fsubw_cmdopdU8CT2UD(opt2,Ppcw,ii/*opdno*/,pc,wkud,sizeof(wkud),NULL/*outlen*/)==1)//enclosed by UD//~vaw6I~
  		  {                                                        //~vaw6I~
            if (!dcmdfullpath(Ppcw,fpath,wkud)) //consider :: *\ etc//~vaw6I~
                return 4;                                          //~vaw6I~
  		  }                                                        //~vaw6I~
  		  else                                                     //~vaw6I~
#endif                                                             //~vaw6M~
            if (!dcmdfullpath(Ppcw,fpath,pc)) //consider :: *\ etc //~v58gR~
                return 4;                                       //~v03zI~
#ifdef UNX                                                         //~v47CI~
    		if (mdossw!=MDOSDISKOK(fpath))	//mdos attr fmt        //~v58gR~
            {                                                      //~v47CI~
                uerrmsg("unix and mdos file is mixed",0);          //~v47CI~
                return 4;                                          //~v47CI~
            }                                                      //~v47CI~
#endif                                                             //~v47CI~
#ifdef FTPSUPP                                                     //~v59fI~
	if (u3270fullpathistso(fpath))                                 //~v728I~
    	return errnotsupported("Attrib","TSO DataSet");            //~v728I~
//  #ifdef UNX                                                     //~v59gI~//~vac2R~
//  	    uftpisremote(fpath,&puftph2);	//each specification   //~v59gR~//~vac2R~
//  #else                                                          //~v59gR~//~vac2R~
		    hostnmlen2=uftpisremote(fpath,&puftph2);	//each specification//~v59gI~
            if (( hostnmlen && !hostnmlen2)                        //~v59fR~
            ||  (!hostnmlen &&  hostnmlen2))                       //~v59fR~
            {                                                      //~v59fI~
            	uerrmsg("Mixed local and remote",0);               //~v59fI~
                return 4;                                          //~v59fI~
            }                                                      //~v59fI~
//  #endif                                                         //~v59fI~//~vac2R~
#endif                                                             //~v59fI~
            if (WILDCARD(fpath))                                   //~v58gR~
            {                                                   //~v041I~
                wcattr.wcattron=attron;                         //~v041I~
                wcattr.wcattroff=attroff;                       //~v041R~
                wcattr.wcpuftph=0;	//puftph                       //~v59fI~
#ifdef FTPSUPP                                                     //~v59fI~
                wcattr.wcpuftph=(void*)puftph2;	//puftph           //~v59fR~
#endif                                                             //~v59fI~
//              if (uwildfunc(0,fullpath,FILE_ALL-FILE_DIRECTORY,  //~v47FR~
                if (uwildfunc(0,fpath,FILE_ALL,                    //~v58gR~
                                dcmdwildattr,&wcattr,&filectr)) //~v041I~
                    return 4;                                   //~v041I~
                if (opdno==1)                                      //~v47FI~
                {                                                  //~v47FI~
                    if (filectr>1)                                 //~v47FI~
						return errmissing();                       //~v47FI~
                }                                                  //~v47FI~
                else                                               //~v47FI~
                uerrmsg("%s, %d file attr was changed",         //~v041R~
                        "%s の %d ファイルの属性を変更",        //~v041R~
                        fpath,filectr);                            //~v58gR~
            }                                                   //~v041I~
            else                                                //~v041I~
            {//not wildcard                                        //~v59fR~
//#ifndef UNX                                                        //~v59fI~//~vac2R~
#ifdef FTPSUPP                                                     //~v59fI~
            if (hostnmlen2)                                        //~v59fI~
            {                                                      //~v59fI~
//          	if (dcmdattrchngunix(fpath,attron,attroff,&attr))  //~v59fR~//~vac2R~
            	if (dcmdattrchng_ftp(0,puftph2,fpath,attron,attroff,&attr))//~vac2I~
                	return 4;                                      //~v59fI~
            }                                                      //~v59fI~
            else                                                   //~v59fI~
            {                                                      //~v59fI~
#endif                                                             //~v59fI~
//#endif	//!unx                                                     //~v59fI~//~vac2R~
            if (dcmdattrchng(fpath,attron,attroff,&attr))          //~v58gR~
                return 4;                                       //~v03zI~
//#ifndef UNX                                                        //~v59gI~//~vac2R~
#ifdef FTPSUPP                                                     //~v59fI~
            }//hostnmlen2=0                                        //~v59fR~
#endif                                                             //~v59fI~
//#endif	//!unx                                                     //~v59gI~//~vac2R~
            }//not wildcard                                        //~v59fI~
//        }//switch                                                //~v206R~
        }//not 1st opd                                             //~v206I~
        pc+=strlen(pc)+1;   //next operand addr                 //~v03zI~
    }                                                           //~v03zI~
    return 0;                                                   //~v03zR~
}//dcmd_attribute                                               //~v03zR~
                                                                //~v03pI~
//****************************************************************//~v03zI~
//!dcmdattrchk                                                  //~v03zI~
//* attribute char chk                                          //~v03zI~
//*parm1:attr string                                            //~v03zI~
//*parm2:attr on requested result,you must init before call     //~v03zI~
//*parm3:attr off requested result,you must init before call    //~v03zI~
//*parm4:(UNIX)mdos disk sw                                        //~v47CI~
//*retrn:rc                                                     //~v03zI~
//****************************************************************//~v03zI~
#ifdef UNX                                                         //~v19cI~
//int dcmdattrchk(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff)    //~v47CR~
int dcmdattrchk(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff,int Popt)//~v47CI~
#else                                                              //~v19cI~
//int dcmdattrchk(UCHAR *Pattrs,UCHAR *Pattron,UCHAR *Pattroff)    //~v53QR~
int dcmdattrchk(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff)      //~v53QI~
#endif                                                             //~v19cI~
{                                                               //~v03zI~
    int   ii,attrlen,attronsw=0;                                   //~v19cR~
    UCHAR *pc;                                                     //~v203R~
#ifdef UNX                                                         //~v203I~
    ULONG attrbit;                                                 //~v203I~
    UCHAR *pc2;                                                    //~v203I~
    int   numlen;                                                  //~v203I~
    int   resetsw=0;                                               //~v47ER~
    ULONG ugsbit;                                                  //~v47EI~
#else  //!UNX                                                      //~v203I~
    UCHAR attrbit;                                                 //~v203I~
#endif //!UNX                                                      //~v203I~
//********************                                          //~v03zI~
    attrlen=(int)strlen(pc=Pattrs);                             //~v03zR~
    if (*pc!='+' && *pc!='-')                                   //~v03zR~
    {                                                              //~v206I~
        attronsw=1;                                             //~v03zI~
        *Pattron=0;     //clear previous value                     //~v206I~
#ifdef UNX                                                         //~v40bI~
        *Pattroff=0xffffffff; //uattrib process reset then set on  //~v206I~
        resetsw=1;                                                 //~v47EI~
#else                                                              //~v40bI~
        *Pattroff=0xff;       //uattrib process reset then set on  //~v40bI~
#endif                                                             //~v40bI~
    }                                                              //~v206I~
    for (ii=0;ii<attrlen;ii++,pc++)                             //~v03zR~
    {                                                           //~v03zI~
        switch (*pc)                                            //~v03zR~
        {                                                       //~v03zI~
        case '+':                                               //~v03zI~
            attronsw=1;                                         //~v03zI~
#ifdef UNX                                                         //~v47EM~
        	resetsw=0;                                             //~v47EI~
#endif                                                             //~v47EM~
            continue;                                           //~v03zI~
        case '-':                                               //~v03zI~
            attronsw=0;                                         //~v03zI~
#ifdef UNX                                                         //~v47EI~
        	resetsw=0;                                             //~v47EI~
#endif                                                             //~v47EI~
            continue;                                           //~v03zI~
#ifdef UNX                                                         //~v203I~
        case '=':                                                  //~v203I~
            resetsw=1;                                             //~v47EI~
#else  //!UNX                                                      //~v203I~
        case '/':                                               //~v05WM~
#endif //!UNX                                                      //~v203I~
            attronsw=1;                                         //~v05WI~
            *Pattron=0;     //clear previous value              //~v05WR~
//          *Pattroff=0xff; //uattrib process reset then set on    //~v19cR~
//#ifdef UNX                                                       //~v53QR~
            *Pattroff=0xffffffff; //uattrib process reset then set on//~v19cI~
//#else                                                            //~v53QR~
//            *Pattroff=0xff; //uattrib process reset then set on  //~v53QR~
//#endif                                                           //~v53QR~
            continue;                                           //~v05WI~
        }                                                       //~v03zI~
      if (*pc!=' ')         //ignore space                         //~v09aI~
      {                                                            //~v09aI~
#ifdef UNX                                                         //~v203I~
        pc2=pc;                                                    //~v203I~
      if (Popt)	//mdosdisk                                         //~v47CI~
      {                                                            //~v47CI~
        if (!(attrbit=dirattrbit_mdos(*pc))) //advance if octal value//~v47CI~
            return errinvalid(Pattrs);                             //~v47CI~
       if (Popt & DCACO_MDOS)	//not remote Windows case          //~vac2I~
        attrbit|=FILE_MDOSDISK;                                    //~v47CI~
      }                                                            //~v47CI~
      else                                                         //~v47CI~
      {                                                            //~v47CI~
        if (!(attrbit=dirattrbit(&pc2))) //advance if octal value  //~v203R~
            return errinvalid(Pattrs);                             //~v203I~
        if (pc2!=pc)	//octal number                             //~v203I~
        {                                                          //~v203I~
//        	numlen=(ULONG)pc2-(ULONG)pc-1;                         //~vb06R~
          	numlen=(int)((ULONG)pc2-(ULONG)pc-1);                  //~vb06I~
            ii+=numlen;	//later +1                                 //~v203I~
            pc+=numlen;                                            //~v203I~
            if (resetsw && numlen==2)   //3 digit octal            //~v47EI~
            {                                                      //~v47EI~
//            	ugsbit=S_ISUID|S_ISGID|S_ISVTX,0;                  //~vb74R~
              	ugsbit=S_ISUID|S_ISGID|S_ISVTX;                    //~vb74I~
            	ugsbit=FILE_SETMODEATTR(ugsbit,0);                 //~v47EI~
            	UFATTROFF(*Pattroff,ugsbit);                       //~v47EI~
            }                                                      //~v47EI~
        }                                                          //~v203I~
      }//unix file                                                 //~v47CI~
#else  //!UNX                                                      //~v203I~
        if (!(attrbit=dirattrbit(*pc)))                         //~v03zR~
            return errinvalid(Pattrs);                          //~v03zR~
#endif //!UNX                                                      //~v203M~
        if (attronsw)                                           //~v03zI~
        {                                                       //~v03zI~
//          UCBITON(*Pattron,attrbit);                             //~v204R~
            UFATTRON(*Pattron,attrbit);                            //~v204R~
//          UCBITOFF(*Pattroff,attrbit);                           //~v204R~
            UFATTROFF(*Pattroff,attrbit);                          //~v204R~
        }                                                       //~v03zI~
        else                                                    //~v03zI~
        {                                                       //~v03zI~
//          UCBITON(*Pattroff,attrbit);                            //~v204R~
            UFATTRON(*Pattroff,attrbit);                           //~v204R~
//          UCBITOFF(*Pattron,attrbit);                            //~v204R~
            UFATTROFF(*Pattron,attrbit);                           //~v204R~
        }                                                       //~v03zI~
      }//ignore space                                              //~v09aI~
    }                                                           //~v03zI~
    return 0;                                                   //~v03zI~
}//dcmdattrchk                                                  //~v03zI~
                                                                //~v03zI~
#ifndef UNX                                                        //~v59fR~
#ifdef FTPSUPP                                                     //~v59fI~
//**************************************************************** //~v59fI~
//!dcmdattrchkunix                                                 //~v59fR~
//* attribute char chk for remote file(UNIX mode)                  //~v59fI~
//*retrn:rc                                                        //~v59fI~
//**************************************************************** //~v59fI~
int dcmdattrchkunix(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff)  //~v59fR~
{                                                                  //~v59fI~
    int   ii,attrlen,attronsw=0;                                   //~v59fI~
    UCHAR *pc;                                                     //~v59fI~
    ULONG attrbit;                                                 //~v59fI~
    UCHAR *pc2;                                                    //~v59fI~
    int   numlen;                                                  //~v59fI~
    int   resetsw=0;                                               //~v59fI~
    ULONG ugsbit;                                                  //~v59fI~
//********************                                             //~v59fI~
    attrlen=(int)strlen(pc=Pattrs);                                //~v59fI~
    if (*pc!='+' && *pc!='-')                                      //~v59fI~
    {                                                              //~v59fI~
        attronsw=1;                                                //~v59fI~
        *Pattron=0;     //clear previous value                     //~v59fI~
        *Pattroff=0xffffffff; //uattrib process reset then set on  //~v59fI~
        resetsw=1;                                                 //~v59fI~
    }                                                              //~v59fI~
    for (ii=0;ii<attrlen;ii++,pc++)                                //~v59fI~
    {                                                              //~v59fI~
        switch (*pc)                                               //~v59fI~
        {                                                          //~v59fI~
        case '+':                                                  //~v59fI~
            attronsw=1;                                            //~v59fI~
        	resetsw=0;                                             //~v59fI~
            continue;                                              //~v59fI~
        case '-':                                                  //~v59fI~
            attronsw=0;                                            //~v59fI~
        	resetsw=0;                                             //~v59fI~
            continue;                                              //~v59fI~
        case '=':                                                  //~v59fI~
            resetsw=1;                                             //~v59fI~
            attronsw=1;                                            //~v59fI~
            *Pattron=0;     //clear previous value                 //~v59fI~
            *Pattroff=0xffffffff; //uattrib process reset then set on//~v59fI~
            continue;                                              //~v59fI~
        }                                                          //~v59fI~
      	if (*pc!=' ')         //ignore space                       //~v59fI~
      	{                                                          //~v59fI~
        	pc2=pc;                                                //~v59fI~
            if (!(attrbit=dirattrbitremote(&pc2))) //advance if octal value//~v59fR~
                return errinvalid(Pattrs);                         //~v59fI~
            if (pc2!=pc)    //octal number                         //~v59fI~
            {                                                      //~v59fI~
//              numlen=(ULONG)pc2-(ULONG)pc-1;                     //~v59fI~//~vafkR~
//              numlen=(ULPTR)pc2-(ULPTR)pc-1;                     //~vafkI~//~vb06R~
                numlen=(int)((ULPTR)pc2-(ULPTR)pc-1);              //~vb06I~
                ii+=numlen; //later +1                             //~v59fI~
                pc+=numlen;                                        //~v59fI~
                if (resetsw && numlen==2)   //3 digit octal        //~v59fI~
                {                                                  //~v59fI~
                    ugsbit=S_ISUID|S_ISGID|S_ISVTX,0;              //~v59fI~
                    ugsbit=FILE_SETMODEATTR(ugsbit,0);             //~v59fI~
                    UFATTROFF_REMOTE(*Pattroff,ugsbit);            //~v59fI~
                }                                                  //~v59fI~
            }                                                      //~v59fI~
        	if (attronsw)                                          //~v59fI~
        	{                                                      //~v59fI~
            	UFATTRON_REMOTE(*Pattron,attrbit);                 //~v59fI~
            	UFATTROFF_REMOTE(*Pattroff,attrbit);               //~v59fI~
        	}                                                      //~v59fI~
       	 	else                                                   //~v59fI~
        	{                                                      //~v59fI~
            	UFATTRON_REMOTE(*Pattroff,attrbit);                //~v59fI~
            	UFATTROFF_REMOTE(*Pattron,attrbit);                //~v59fI~
        	}                                                      //~v59fI~
      	}//ignore space                                            //~v59fI~
    }                                                              //~v59fI~
    return 0;                                                      //~v59fI~
}//dcmdattrchkunix                                                 //~v59fR~
#endif                                                             //~v59fI~
#endif	//!unx                                                     //~v59fI~
//****************************************************************//~v041I~
//!dcmdwildattr                                                 //~v041I~
//* attribute change wild card process called thry uwildfunc    //~v041I~
//*parm1:filename thru wildfunc                                 //~v041I~
//*parm2:dirlist ptr thru wildfunc                              //~v041I~
//*parm3:parm thru uwildfunc(dcmdattrchng parameter structure)  //~v041R~
//*retrn:rc                                                     //~v041I~
//****************************************************************//~v041I~
int dcmdwildattr(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v041R~
{                                                               //~v041I~
    WCPARMATTR *pwcattr;                                        //~v041I~
//#ifndef UNX                                                        //~v59gI~//~vac2R~
#ifdef FTPSUPP                                                     //~v59fI~
	PUFTPHOST puftph;                                              //~v59fI~
#endif                                                             //~v59fI~
//#endif                                                             //~v59gI~//~vac2R~
//********************                                          //~v041I~
    pwcattr=Pparm;                                              //~v041I~
//#ifndef UNX                                                        //~v59fI~//~vac2R~
#ifdef FTPSUPP                                                     //~v59fI~
//  puftph=(PUFTPHOST)pwcattr;                                     //~v59fI~//~vb09R~
    puftph=(PUFTPHOST)pwcattr->wcpuftph; //puftph                  //~vb09R~
  if (puftph)                                                      //~v59fI~
//      return dcmdattrchngunix(Pfullpath,pwcattr->wcattron,pwcattr->wcattroff,//~v59fR~//~vac2R~
      return dcmdattrchng_ftp(0,puftph,Pfullpath,pwcattr->wcattron,pwcattr->wcattroff,//~vac2I~
                    &pwcattr->wcattr);                             //~v59fI~
  else                                                             //~v59fI~
#endif                                                             //~v59fI~
//#endif                                                             //~v59fI~//~vac2R~
    return dcmdattrchng(Pfullpath,pwcattr->wcattron,pwcattr->wcattroff,//~v041I~
                    &pwcattr->wcattr);                          //~v041R~
}//dcmdwildattr                                                 //~v041I~
                                                                //~v041I~
//****************************************************************//~v03zI~
//!dcmdattrchng                                                 //~v03zI~
//* attribute change                                            //~v03zI~
//*parm1:filename                                               //~v03zR~
//*parm2:attr on bit                                            //~v03zI~
//*parm3:attr off bit                                           //~v03zI~
//*parm4:attr result addr                                       //~v03zI~
//*retrn:rc                                                     //~v03zI~
//****************************************************************//~v03zI~
//#ifdef UNX                                                       //~v53QR~
int dcmdattrchng(UCHAR *Pfullpath,ULONG Pattron,ULONG Pattroff,ULONG *Pattrout)//~v19cI~
//#else //!UNX                                                     //~v53QR~
//int dcmdattrchng(UCHAR *Pfullpath,UCHAR Pattron,UCHAR Pattroff,UCHAR *Pattrout)//~v53QR~
//#endif                                                           //~v53QR~
{                                                               //~v03zI~
//  UCHAR attrstring[UDDATTRSZ+1],attrstring2[UDDATTRSZ+1];        //~v53QR~
//  UCHAR attrstring[UDDATTRSZMAX+1],attrstring2[UDDATTRSZMAX+1];     //unix:5,else 4://~v53QR~//~vbriR~
    UCHAR attrstring[UDDATTRSZMAX+4],attrstring2[UDDATTRSZMAX+4];     //unix:5,else 4://~vbriI~
    int efaopt=0;                                                  //~v47CR~
#ifdef LNX                                                         //~v47DI~
    ULONG oldattr,newattr,reqattr;                                 //~v47DI~
#endif                                                             //~v47DI~
	PUFTPHOST puftph;                                              //~vac2I~
    int ftpwin;                                                    //~vac2I~
//********************                                          //~v03zI~
	UTRACEP("%s:attrOn=0x%lx,attrOff=0x%lx,fpath=%s\n",UTT,Pattron,Pattroff,Pfullpath);//~vbz1R~
	uftpisremote(Pfullpath,&puftph);	//each specification       //~vac2I~
    ftpwin=(puftph && (puftph->UFTPHflag & UFTPHFRWIN))? UEFA_RWIN:0;//~vac2R~
    if (uattrib(Pfullpath,0,0,Pattrout))            //query attr//~v03zR~
        return 4;                                               //~v03zI~
//  attrstring[UDDATTRSZ]=attrstring2[UDDATTRSZ]=0;                //~v53QR~
    memset(attrstring,0,sizeof(attrstring));                       //~v53QI~
    memset(attrstring2,0,sizeof(attrstring2));                     //~v53QR~
#ifdef UNX                                                         //~v47CI~
    if (MDOSDISKOK(Pfullpath))                                     //~v47CI~
	    efaopt=UEFA_MDOS;          //mdos attr string edit         //~v47CI~
#endif                                                             //~v47CI~
//  ueditfattr(*Pattrout,attrstring,0);                            //~v47CR~
    efaopt|=UEFA_SZ;                                               //~v484I~
//  ueditfattr(*Pattrout,attrstring,efaopt);                       //~v59fR~
//  ueditfattr(*Pattrout,attrstring,efaopt|UEFA_DIR);              //~v59fI~//~vac2R~
    ueditfattr(*Pattrout,attrstring,efaopt|UEFA_DIR|ftpwin);       //~vac2I~
    if (!Pattron && !Pattroff)          //attr query            //~v03zI~
    {                                                           //~v03zI~
        uerrmsg("attr of %s is %s",                             //~v03zI~
                "%s の 属性は %s",                              //~v03zI~
//              Pfullpath,attrstring);                          //~v03zR~//~vb0aR~
                STD_FNM(Pfullpath),attrstring);                    //~vb0aI~
    }                                                           //~v03zI~
    else                                                        //~v03zI~
    {                                                           //~v03zI~
#ifdef LNX                                                         //~v47DI~
      if (ftpwin)                                                  //~vac2I~
    	oldattr=(*Pattrout & FILE_CHMODMASK);		//old value rsha//~vac2I~
      else                                                         //~vac2I~
    	oldattr=(*Pattrout & FILE_CHMODMASK_MODE);	//old value    //~v47CR~
#endif                                                             //~v47DI~
        if (uattrib(Pfullpath,Pattron,Pattroff,Pattrout))//set attr//~v03zR~
            return 4;                                           //~v03zI~
#ifdef LNX                                                         //~v47DI~
      if (ftpwin)                                                  //~vac2I~
    	newattr=(*Pattrout & FILE_CHMODMASK);		//old value rsha//~vac2I~
      else                                                         //~vac2I~
    	newattr=(*Pattrout & FILE_CHMODMASK_MODE);	//old value    //~v47CR~
        reqattr=(oldattr&~Pattroff)|Pattron;;                      //~v47DI~
      if (ftpwin)                                                  //~vac2I~
    	reqattr&=FILE_CHMODMASK;		//old value rsha           //~vac2I~
      else                                                         //~vac2I~
    	reqattr&=FILE_CHMODMASK_MODE;	//old value                //~v47CR~
#endif                                                             //~v47DI~
//      ueditfattr(*Pattrout,attrstring2,0);                       //~v47CR~
//      ueditfattr(*Pattrout,attrstring2,efaopt);                  //~v47CI~//~vac2R~
//      ueditfattr(*Pattrout,attrstring2,efaopt|ftpwin);           //~vac2I~//~vac8R~
        ueditfattr(*Pattrout,attrstring2,efaopt|UEFA_DIR|ftpwin);//display also DIR flag//~vac8I~
#ifdef LNX                                                         //~v47DI~
//      if (!efaopt && newattr==oldattr && reqattr!=newattr)//not mdos disk//~v47CR~//~vac8R~
        if (!(efaopt & UEFA_MDOS) && newattr==oldattr && reqattr!=newattr)//not mdos disk//~vac8I~
        {                                                          //~vac8I~
          if (ftpwin)	                                           //~vac8I~
          {                                                        //~vac8I~
        	uerrmsg("attr of %s was changed PARTIALLY %s==>%s",0,   //~vac8R~//~vawKR~
            	Pfullpath,attrstring,attrstring2);                 //~vac8I~
          }                                                        //~vac8I~
          else                                                     //~vac8I~
#ifdef ARM                                                         //~vbz1I~
	        uerrmsg("%s attr(%s) was not changed;",                //~vbz1I~
    	        	"%s の 属性(%s)は変更できませんでした。",      //~vbz1I~
        	    		Pfullpath,attrstring);                     //~vbz1I~
#else                                                              //~vbz1I~
	        uerrmsg("%s attr(%s) was not changed;(DOS file system is not supported)",//~v47DI~//~vawKR~
    	        	"%s の 属性(%s)は変更できませんでした(DOSファイルシステムは適用外)",//~v47DI~
        	    		Pfullpath,attrstring);                     //~v47DI~
#endif                                                             //~vbz1I~
        }                                                          //~vac8I~
        else                                                       //~v47DI~
#endif                                                             //~v47DI~
        uerrmsg("attr of %s was changed %s==>%s",                //~v03zI~//~vawKR~
            "%s の 属性を変更 %s==>%s",                         //~v03zI~
//          Pfullpath,attrstring,attrstring2);                  //~v03zR~//~vb0aR~
            STD_FNM(Pfullpath),attrstring,attrstring2);            //~vb0aI~
    }                                                           //~v03zI~
    return 0;                                                   //~v03zI~
}//dcmdattrchng                                                 //~v03zI~
//#ifndef UNX                                                        //~v59fR~//~vac2R~
#ifdef FTPSUPP                                                     //~v59fI~
//**************************************************************** //~vac2I~
//!dcmdattrchng_ftp                                                //~vac2I~
//* attribute change for remote file(remote may be windows)        //~vac2I~
//*retrn:rc                                                        //~vac2I~
//**************************************************************** //~vac2I~
int dcmdattrchng_ftp(int Popt,PUFTPHOST Ppuftph,UCHAR *Pfullpath,ULONG Pattron,ULONG Pattroff,ULONG *Pattrout)//~vac2I~
{                                                                  //~vac2I~
	int rc;                                                        //~vac2I~
//********************                                             //~vac2I~
#ifdef UNX                                                         //~vac2I~
	rc=dcmdattrchng(Pfullpath,Pattron,Pattroff,Pattrout);          //~vac2I~
#else                                                              //~vac2I~
	if (Ppuftph->UFTPHflag & UFTPHFRWIN)                           //~vac2R~
		rc=dcmdattrchng(Pfullpath,Pattron,Pattroff,Pattrout);      //~vac2I~
    else                                                           //~vac2I~
		rc=dcmdattrchngunix(Pfullpath,Pattron,Pattroff,Pattrout);  //~vac2I~
#endif                                                             //~vac2I~
    return rc;                                                     //~vac2I~
}//dcmdattrchng_ftp                                                //~vac2I~
//**************************************************************** //~v59fI~
//!dcmdattrchngunix                                                //~v59fR~
//* attribute change for remote file                               //~v59fI~
//* (remote in unix)                                               //~vac2I~
//*retrn:rc                                                        //~v59fI~
//**************************************************************** //~v59fI~
int dcmdattrchngunix(UCHAR *Pfullpath,ULONG Pattron,ULONG Pattroff,ULONG *Pattrout)//~v59fR~
{                                                                  //~v59fI~
//  UCHAR attrstring[UDDATTRSZMAX+1],attrstring2[UDDATTRSZMAX+1];     //unix:5,else 4://~v59fI~//~vbriR~
    UCHAR attrstring[UDDATTRSZMAX+4],attrstring2[UDDATTRSZMAX+4];     //unix:5,else 4://~vbriI~
    int efaopt=0;                                                  //~v59fI~
    ULONG oldattr,newattr,reqattr;                                 //~v59fI~
//********************                                             //~v59fI~
    if (uattrib(Pfullpath,0,0,Pattrout))            //query attr   //~v59fI~
        return 4;                                                  //~v59fI~
    memset(attrstring,0,sizeof(attrstring));                       //~v59fI~
    memset(attrstring2,0,sizeof(attrstring2));                     //~v59fI~
    efaopt|=UEFA_SZ;		//set stringZ,skip set dir attr        //~v59fI~
    ueditfattr(*Pattrout,attrstring,efaopt|UEFA_DIR);              //~v59fR~
    if (!Pattron && !Pattroff)          //attr query               //~v59fI~
    {                                                              //~v59fI~
        uerrmsg("attr of %s is %s",                                //~v59fI~
                "%s の 属性は %s",                                 //~v59fI~
                Pfullpath,attrstring);                             //~v59fI~
    }                                                              //~v59fI~
    else                                                           //~v59fI~
    {                                                              //~v59fI~
    	oldattr=(*Pattrout & FILE_CHMODMASK_MODE);	//old value    //~v59fI~
        if (uattrib(Pfullpath,Pattron,Pattroff,Pattrout))//set attr//~v59fI~
            return 4;                                              //~v59fI~
    	newattr=(*Pattrout & FILE_CHMODMASK_MODE);	//old value    //~v59fI~
        reqattr=(oldattr&~Pattroff)|Pattron;;                      //~v59fI~
    	reqattr&=FILE_CHMODMASK_MODE;	//old value                //~v59fI~
        ueditfattr(*Pattrout,attrstring2,efaopt);                  //~v59fR~
        if (!efaopt && newattr==oldattr && reqattr!=newattr)//not mdos disk//~v59fI~
	        uerrmsg("%s attr(%s) was not changed;(DOS file system is not supported)",//~v59fI~//~vawKR~
    	        	"%s の 属性(%s)は変更できませんでした(DOSファイルシステムは適用外)",//~v59fI~
        	    		Pfullpath,attrstring);                     //~v59fI~
        else                                                       //~v59fI~
	        uerrmsg("attr of %s was changed %s==>%s",               //~v59fI~//~vawKR~
    	        "%s の 属性を変更 %s==>%s",                        //~v59fI~
        	    Pfullpath,attrstring,attrstring2);                 //~v59fI~
    }                                                              //~v59fI~
    return 0;                                                      //~v59fI~
}//dcmdattrchngunix                                                //~v59fR~
#endif                                                             //~v59fI~
//#endif	//!unx                                                     //~v59fI~//~vac2R~
//**************************************************************** //~v646I~
//!dcmdfullpathwild                                                //~v646I~
//* wildcard resolve dcmdfullpath                                  //~v646I~
//*Parm1: Gsubgblopt value                                         //~v646I~
//**************************************************************** //~v646I~
UCHAR *dcmdfullpathwild(int Popt,PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm)//~v646I~
{                                                                  //~v646I~
	UCHAR *pc;                                                     //~v646I~
//********************                                             //~v646I~
	if (Popt & XESUB_GBLOPT_WILDPATH)                              //~v646I~
		Gsubgblopt|=XESUB_GBLOPT_WILDPATH;                         //~v646I~
	if (Popt & XESUB_GBLOPT_WILDMEMB)                              //~v646I~
		Gsubgblopt|=XESUB_GBLOPT_WILDMEMB;                         //~v646I~
	pc=dcmdfullpath(Ppcw,Pfullpath,Pfnm);                          //~v646R~
	if (Popt & XESUB_GBLOPT_WILDPATH)                              //~v646I~
		Gsubgblopt&=~XESUB_GBLOPT_WILDPATH;                        //~v646I~
	if (Popt & XESUB_GBLOPT_WILDMEMB)                              //~v646I~
		Gsubgblopt&=~XESUB_GBLOPT_WILDMEMB;                        //~v646I~
    return pc;                                                     //~v646I~
}//dcmdfullpathwild                                                //~v646I~
//**************************************************************** //~v11HI~
//!dcmdfullpath                                                    //~v11HI~
//* rsolv *\/:: on dir list screen                                 //~v11HI~
//* rsolv *\/:: on dir list screen                                 //~v11PI~
//*parm1:pcw                                                       //~v11HI~
//*parm2:fullpath output area                                      //~v11HI~
//*parm3:source filename                                           //~v11HI~
//*return:outarea addr                                              //~v11PI~//~va0fR~
//**************************************************************** //~v11HI~
UCHAR *dcmdfullpath(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm)  //~v11HR~
{                                                                  //~v11HI~
    UCHAR  *fnm,tempfnm[_MAX_PATH];                                //~v11JR~
    PUFILEH pfh;                                                   //~v540I~
    int pos;                                                       //~v540I~
//********************                                             //~v11HI~
	UTRACEP("%s:Pfnm=%s\n",UTT,Pfnm);                              //~vbriI~
    if (Ppcw->UCWtype!=UCWTDIR                                     //~v11JR~
    &&  Ppcw->UCWtype!=UCWTFILE)                                   //~v11JR~
        return filefullpath(Pfullpath,Pfnm,_MAX_PATH);             //~v11HR~
                                                                   //~v11HI~
//  fnm=UGETPFHFROMPCW(Ppcw)->UFHfilename;                         //~v540R~
    pfh=UGETPFHFROMPCW(Ppcw);                                      //~v540I~
//#ifdef ARMXXE                                                      //~vby4I~//~vby6R~
//  if (PFH_ISDOCUMENT(pfh))                                          //~vby4I~//~vby6R~
//    fnm=pfh->UFHshortpath;                                         //~vby4I~//~vby6R~
//  else                                                             //~vby4I~//~vby6R~
//#endif                                                             //~vby4I~//~vby6R~
    fnm=pfh->UFHfilename;                                          //~v540I~
    if (!strcmp(Pfnm,"*"))                                         //~v11PI~
    {                                                              //~v11PI~
        strcpy(Pfullpath,fnm);                                     //~v11PI~
        return Pfullpath;                                          //~v11PI~
    }                                                              //~v11PI~
#ifdef FTPSUPP                                                     //~v717I~
  if (FILEISTSO(pfh)==0)                                           //~v717I~
  {                                                                //~v717I~
#endif                                                             //~v717I~
    if (Ppcw->UCWtype==UCWTDIR)                                    //~v11JI~
    {                                                              //~v11JI~
        ustrncpyz(tempfnm,fnm,_MAX_PATH-2);                        //~v11JR~
#ifdef UNX                                                         //~vaa0I~
      if (pfh->UFHattr & FILE_WILDNAME                             //~vaa0I~
      ||  !WILDCARD(fnm))                                          //~vaa0I~
#else                                                              //~vaa0I~
      if (!WILDCARD(fnm))                                          //~v11PI~
#endif                                                             //~vaa0I~
      {                                                            //~v53QI~
//     if (ROOTDIR(fnm))                                           //~v48bR~
//     if (ROOTDIR2(fnm))                                          //~v54jR~
       if (ROOTDIR3(fnm))                                          //~v54jR~
        strcat(tempfnm,"x");        //add filename                 //~v11PI~
       else                                                        //~v11PI~
       {
//      strcat(tempfnm,"\\x");      //add filename                 //~v19aR~
//      strcat(tempfnm,DIR_SEPS "x");      //add filename          //~v540R~
        pos=(int)strlen(tempfnm);               //add filename          //~v540I~
        *(tempfnm+pos++)=pfh->UFHdirsepc;                          //~v540I~
        *(tempfnm+pos++)='x';                                      //~v540I~
        *(tempfnm+pos)=0;                                          //~v540I~
       }
      }                                                           //~v53QI~
        fnm=tempfnm;                                               //~v11JI~
    }                                                              //~v11JI~
#ifdef FTPSUPP                                                     //~v717I~
  }//!TSO file                                                     //~v717I~
#endif                                                             //~v717I~
    return filefullpath2(Pfullpath,Pfnm,_MAX_PATH,fnm);            //~v11JR~
}//dcmdfullpath                                                    //~v11HI~
//**************************************************************** //~v70qI~
//!dcmdexefullpath: create full path if path is specified,else return itself//~v70qI~
//*return:0:no path set,1:fullpath set,4:err                       //~v70qI~
//**************************************************************** //~v70qI~
int dcmdexefullpath(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm)  //~v70qI~
{                                                                  //~v70qI~
//********************                                             //~v70qI~
    if (!memcmp(Pfnm,WORKDIRPATHID,WORKDIRPATHIDLEN)               //~v70qI~
    ||  strpbrk(Pfnm,":/\\"))	                                   //~v70qI~
    {                                                              //~v70qI~
		if (dcmdfullpath(Ppcw,Pfullpath,Pfnm))                     //~v70qI~
        	return 1;                                              //~v70qI~
        else                                                       //~v70qI~
        	return 4;                                              //~v70qI~
    }                                                              //~v70qI~
    strcpy(Pfullpath,Pfnm);                                        //~v70qI~
    return 0;                                                      //~v70qI~
}//dcmdexefullpath                                                 //~v70qI~
//****************************************************************//~v05QI~
//!dcmddeleted                                                  //~v05QI~
//* delete msg                                                  //~v05QI~
//*parm1:filename                                               //~v05QI~
//****************************************************************//~v05QI~
int dcmddeleted(UCHAR *Pname)                                   //~v05QI~
{                                                               //~v05QI~
//********************                                          //~v05QI~
//  uerrmsg("%s was deleted",                                    //~v05QM~//~vawKR~//~vb7nR~
//          "%s を削除",                                        //~v05QM~//~vb7nR~
    uerrmsg("Deleted:%s",                                          //~vb7nI~
            "削除済:%s",                                           //~vb7nI~
//          Pname);                                             //~v05QR~//~vb0aR~
            STD_FNM(Pname));                                       //~vb0aI~
    return 0;                                                   //~v05QI~
}//dcmddeleted                                                  //~v05QI~
#ifdef UNX                                                         //~v20hI~
//**************************************************************** //~v20hI~
//!confirm * for allmember                                         //~v20hI~
//*ret  :0 confirmed,4:not yet confirmed                           //~v20hI~
//**************************************************************** //~v20hI~
int dcmdconfallmemb(char *Poperation,char *Pfullpath)              //~v20hR~
{                                                                  //~v20hI~
//********************                                             //~v20hI~
	ugetcwd(Pfullpath);                                            //~v20hI~
    strcat(Pfullpath,DIR_SEPS DIR_ALLMEMB);                        //~v20hI~
    if (!scrconfirmchk(GSCRCONFALLMEMB)) //not yet confirmed       //~v20hI~
    {                                                              //~v20hI~
        uerrmsg("%s for %s,Enter to execute,Esc to cancel",        //~v20hR~
                " %s %s の確認,続行は実行キー,取消はEsc",          //~v20hR~
                Poperation,Pfullpath);                             //~v20hR~
        return 4;                                                  //~v20hI~
    }                                                              //~v20hI~
    return 0;                                                      //~v20hI~
}//dcmdconfallmemb                                                 //~v20hI~
#else  //!UNX                                                      //~v20hI~
//**************************************************************** //~v11LI~
//!protect *;ambiguous for current screen                          //~v20hR~
//* use *.* for all member                                         //~v20hR~
//**************************************************************** //~v11LI~
int dcmdaster(void)                                                //~v11LI~
{                                                                  //~v11LI~
//********************                                             //~v11LI~
    uerrmsg("Use *.* for all of current dir",                      //~v11LI~
            "*.* を使用してください(現行ディレクトリー全メンバー)");//~v11LI~
    return 4;                                                      //~v11LI~
}//dcmdaster                                                       //~v11LI~
#endif //!UNX                                                      //~v20hI~
//**************************************************************** //~v13eI~
//!dcmdhelpcopy                                                    //~v13eI~
//**************************************************************** //~v13eI~
int dcmdhelpcopy(void)                                             //~v13eI~
{                                                                  //~v13eI~
//********************                                             //~v13eI~
//  uerrmsg("XCO source target [/y] [/r] [/+] [/:] [/s] [/s-]",0); //~v572R~
//  uerrmsg("XCO source target [/c] [/{r|y}] [/s[-]] [/+] [/:]",0);//~v58nR~
#ifdef FTPSUPP                                                     //~v59gI~
//  uerrmsg("XCO source target [/c] [/{r|y|d}] [/s[-]] [/t] [/+] [/:]",0);//~v71gR~
//  uerrmsg("XCO source target [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/+] [/:]",0);//~v71mR~
  #ifdef UNX                                                       //~vaa0I~
//  uerrmsg("XCO source target [/b] [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/w] [/+] [/:]",0);//~vaivR~
//  uerrmsg("XCO source target [/b] [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/w] [/+] [/:] [/L{-|M-}]",0);//~vaivI~//~vaiyR~
    uerrmsg("XCO source target [/b] [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/w] [/+] [/:] [/L{-|[T]M-}]",0);//~vaiyI~
  #else                                                            //~vaa0I~
//  uerrmsg("XCO source target [/b] [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/+] [/:]",0);//~vaivR~
//  uerrmsg("XCO source target [/b] [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/+] [/:] [/L{-|M-}]",0);//~vaivI~//~vaiyR~
    uerrmsg("XCO source target [/b] [/c] [/{r[-]|y[-]|d}] [/s[-]] [/t] [/+] [/:] [/L{-|[T]M-}]",0);//~vaiyI~
  #endif                                                           //~vaa0I~
#else                                                              //~v59gI~
#ifdef OS2                                                         //~v58nI~
    uerrmsg("XCO source target [/c] [/{r|y}] [/s[-]] [/+] [/:]",0);//~v58nI~
#else                                                              //~v58nI~
    uerrmsg("XCO source target [/c] [/{r|y|d}] [/s[-]] [/+] [/:]",0);//~v58nI~
#endif                                                             //~v58nI~
#endif                                                             //~v59gI~
    return 4;                                                      //~v13eI~
}//dcmdhelpcopy                                                    //~v13eI~
//**************************************************************** //~v13eI~
//!dcmdhelpmove                                                    //~v13eI~
//**************************************************************** //~v13eI~
int dcmdhelpmove(void)                                             //~v13eI~
{                                                                  //~v13eI~
//********************                                             //~v13eI~
//  uerrmsg("XMO source target [/s]",0);                           //~v57nR~
//  uerrmsg("XMO source target [/{r|y}] [/s]",0);                  //~v58nR~
#ifdef FTPSUPP                                                     //~v59gI~
//  uerrmsg("XMO source target [/{r|y|d}] [/s] [/t]",0);           //~v71gR~
//  uerrmsg("XMO source target [/{r[-]|y[-]|d}] [/s] [/t]",0);     //~v71mR~
//  uerrmsg("XMO source target [/b] [/{r[-]|y[-]|d}] [/s] [/t]",0);//~vaivR~
    uerrmsg("XMO source target [/b] [/{r[-]|y[-]|d}] [/s] [/t] [/L{-|M-}",0);//~vaivI~
#else                                                              //~v59gI~
#ifdef OS2                                                         //~v58nI~
    uerrmsg("XMO source target [/{r|y}] [/s]",0);                  //~v58nI~
#else                                                              //~v58nI~
    uerrmsg("XMO source target [/{r|y|d}] [/s]",0);                //~v58nI~
#endif                                                             //~v58nI~
#endif                                                             //~v59gI~
    return 4;                                                      //~v13eI~
}//dcmdhelpmove                                                    //~v13eI~
//**************************************************************** //~v13eI~
//!dcmdhelpappend                                                  //~v13eI~
//**************************************************************** //~v13eI~
int dcmdhelpappend(void)                                           //~v13eI~
{                                                                  //~v13eI~
//********************                                             //~v13eI~
//  uerrmsg("XAP source target [/y] [/r] [/:] [/s] [/s-]",0);      //~v575R~
//  uerrmsg("XAP source target [/:] [/s] [/s-]",0);                //~v63fR~
#ifdef FTPSUPP                                                     //~v63fI~
//  uerrmsg("XAP source target [/:] [/t]",0);                      //~v71mR~
    uerrmsg("XAP source target [/b] [/:] [/t]",0);                 //~v71mI~
#else                                                              //~v63fI~
    uerrmsg("XAP source target [/:]",0);                           //~v63fI~
#endif                                                             //~v63fI~
    return 4;                                                      //~v13eI~
}//dcmdhelpappend                                                  //~v13eI~
//**************************************************************** //~v208I~
//!dcmdattribhelp                                                  //~v208I~
//**************************************************************** //~v208I~
int dcmdattribhelp(char *Pcmdid)                                   //~v208I~
{                                                                  //~v208I~
#ifdef UNX                                                         //~v208I~
// 		uerrmsg("%s [{+|-|=}][oooo|oooxx] name [name...]; (x=sSgt)",0,//~v42qR~
   		uerrmsg("%s [{+|-|=}][oooo|oooxx] name [name...]; (x=uSgt)",0,//~v42qI~
				Pcmdid);                                           //~v47CI~
//		uerrmsgcat(" ;or; %s [{+|-|=}]{a|s|h|r}...] a:name [b:name...]",0,//~v47CR~//~vac2R~
  		uerrmsgcat(" ;or; %s [{+|-|=}]{a|s|h|r}] name [name...] for Dos file",0,//~vac2R~
#else  //!UNX                                                      //~v208I~
   		uerrmsg("%s [{+|-|/}]{a|s|h|r}...] name [name...]",0,      //~v208I~
				Pcmdid);                                           //~vac2I~
   		uerrmsgcat(" ; or %s [{+|-|=}][oooo] name [name...] ; for remote",0,//~vac2I~
#endif //!UNX                                                      //~v208I~
				Pcmdid);                                           //~v208R~
    return 0;                                                      //~v208I~
}//dcmdattribhelp(char *Pcmdid)                                    //~v208I~
#ifdef WXE                                                         //~v579I~
//**************************************************************** //~v579I~
//!dcmsyscmdnotify                                                 //~v579I~
//**************************************************************** //~v579I~
int dcmdsyscmdnotify(int Pcmdid,char *Pcmdstrid,char *Pcmdopd)     //~v579I~
{	                                                               //~v579I~
//  char cmdstr[_MAX_PATH+32];                                     //~v59LR~
    char cmdstr[UPROC_MAX_CMDSVRCMD2];                             //~v59LR~
    int rc;                                                        //~v579I~
    int len;                                                       //~v59LI~
//**************************                                       //~v579I~
    len=strlen(Pcmdopd);                                           //~v59LI~
	if (len>UPROC_MAX_CMDSVRCMD)                                   //~v59LR~
    {                                                              //~v59LI~
		sprintf(cmdstr,XECMDSVR_CMDSTR,Pcmdid,Pcmdstrid,"");       //~v59LI~
    	uerrmsg("too large(len=%d) cmd request(%s)",0,             //~v59LR~
        		len,cmdstr);                                       //~v59LI~
    	return 8;                                                  //~v59LR~
    }                                                              //~v59LI~
	sprintf(cmdstr,XECMDSVR_CMDSTR,Pcmdid,Pcmdstrid,Pcmdopd);      //~v579I~
    rc=usystem_cmdtocmdserver(0,cmdstr);                           //~v579I~
    return rc;                                                     //~v579I~
}//dcmdsyscmdnotify                                                //~v579I~
#endif                                                             //~v579I~
//**************************************************************** //~van2I~
//* confirm delete wildname                                        //~van2I~
//**************************************************************** //~van2I~
int dcmdwildconf(int Popt,PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh)//~van2R~
{                                                                  //~van2I~
#ifdef LNX                                                         //~van5I~
	char newname[_MAX_PATH];                                       //~van5I~
#endif                                                             //~van5I~
//********************                                             //~van2I~
    if (!scrconfirmchk(GSCRCONFWILDNAME))                          //~van2I~
    {                                                              //~van2I~
#ifdef LNX                                                         //~van5I~
		strcpy(newname,Ppdh->UDHname);                             //~van5R~
//		ufilerepwildname(0,newname,Ppdh->UDHinode);                //~vb06R~
  		ufilerepwildname(0,newname,(ULONG)Ppdh->UDHinode);         //~vb06I~
        uerrmsg("%s will be renamed to %s at Undo. Enter to execute,Esc to cancel",//~van5R~
                "%s は Undo では改名(%s) されます, 続行する時は実行キー,取消はEsc",//~van5I~
                Ppdh->UDHname,newname);                            //~van5I~
#else                                                              //~van5I~
        uerrmsg("%s may be renamed to %s at Undo. Enter to execute,Esc to cancel",//~van2R~
                "%s は Undo で改名(%s) される事があります, 続行する時は実行キー,取消はEsc",//~van2R~
                Ppdh->UDHname,Ppdh->UDHalias);                     //~van2I~
#endif                                                             //~van5I~
        return 4;                                                  //~van2I~
    }                                                              //~van2I~
    return 0;                                                      //~van2I~
}//dcmdwildconf                                                    //~van2I~
