//*CID://+vb7jR~:                             update#=  797;       //~vb7jR~
//*************************************************************
//*xedir.c                                                         //~v09bR~
//* draw
//*************************************************************
//vb7k:170115 dir list;gree attr overflow to "=Rep" when dirname is too long//~vb7jI~
//vb7j:170115 (Win)_MAX_PATH is ucsctr,mbcs len is more over       //~vb7jI~
//vb5d:160917 (Bug)find word rebverse was clear by vb3f when dirlist long name was hidden by attr fld.//~vb5dI~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb44:160718 (W32)rename fld green overflow to timestamp fld by number of UD chardcters//~vb44I~
//vb41:160717 by repeated S+F11,slink remains on filename fld      //~vb41I~
//vb40:160717 when LFN=OFF,invalid find position on dirlist        //~vb40I~
//vb3f:160607 set attr=00 to UHattrflag as delm to avoid shlink/expand filename fld by uviom ligature print//~vb3fI~
//vb3a:160604 dirlist rename fld dbcs change to invalid by S+F1    //~vb3aI~
//vb38:160531 for vb37,set same attr for rename fld not to draw char by ConsoleOutW one by one.//~vb38I~
//vb2w:160211 rename fld utf8 f2l err show "?"                     //~vb2wI~
//vb2r:160205 (Win:BUG)when 8.3 filename display mode slink was not displayed//~vb2rI~
//            currently display slink name if space available      //~vb2rI~
//vb2p:160203 LNX compiler warning                                 //~vb2pI~
//vb2o:160203 try to malloc UDHname for performance(#ifndef MMM)   //~vb2oI~
//vb15:150613 invalid display just when rename overflow for LC newnanme//~vb15I~
//vb14:150613 0x00 is set for rename field display for U8-LC mixed string, set '.' for visibility//~vb14I~
//vawG:140621 compiler warning,set but unused                      //~vawGI~
//vawB:140612 (BUG)too long renamesv was displayed by LC because getmixedstr returns LC when output area ovf.//~vawBI~
//vawA:140612 (BUG)renamesave utf8 attr was white,UDHrenme_codetype was cleared by dirsetfld,it need to reset asyt setflddataDDFMT called when UDHrebanesv!=0//~vawAI~
//vawq:140608 expand renamefld fo also expand mask                 //~vawqI~
//vawp:140607 (BUG)ddfmt display err for expand1 wildcard          //~vawpI~
//vawn:140605 (BUG)ddfmt display err for renamesv at cmd comp(getmixedstr fail to recover utf8 and display dbcs)//~vawnI~
//vawm:140605 (BUG)ddfmt display err at just renameovf occured     //~vawmI~
//vawk:140605 (BUG:LNX)additional to vawj;lc len shrink but colpos remainsby setflddata;use dd2l like as other paste such as to cmdline//~vawkI~
//vawj:140605 (BUG:LNX)paste to rename fld;when l2f to katakana ct is 3 byte CTUTF8,it should be chked at l2fbyct//~vawjI~
//vawa:140531 (W32UNICODE:BUG)F11(paste on dirlist) fail to display UD str on rename fld//~vawaI~
//vaw9:140531 (W32UNICODE)recover UTF8 code on also rename fld     //~vaw9I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavT:140413 (Bug)dirlist;when ddfmt lfn(no attr/ts print) was set even when "a" dlcmd//~vavTI~
//vavS:140413 (Bug)UDBCSCHK_DBCS1STOVF of UDBCSCHK_DBCS1STUCS_CASE() requires UDBCSCHK_TEMPDBCSID() preprocess//~vavSI~
//vavg:140422 (Win)Win local is utf8 only for subchar,so back att of subchar utf8 to green//~vavgI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav6:140405 (BUG)no dd fmt for shortname(was set intermediate space)//~vav6I~
//vauN:140320 (BUG)on Deutsche,UTF8 Japanese DBCS splitchk was not done//~vauNI~
//vauK:140318 (BUG)dirlist u8 green pos err when ascii->u8 slink   //~vauKI~
//vauH:140316 (BUG)dirlist u8 pathname coloumn is not adjusted for U-umrout//~vauHI~
//vauG:140316 (BUG)rfind(f5) misses utf8 code when searchword on cmdline.//~vauGI~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~
//vauB:140315 (Win)Alt+W/Ctl+W on dirlist;u8 membername on dir list by fnu8 option,but string is treated by lc by env:lc on windows//~vauBI~
//vaup:140314 (BUG)dirlist filename cut by rename fld if overflow to rename but not to timestamp//~vaupI~
//vaun:140313 C+W(copy word to cmdline) support for dir list       //~vaunI~
//vauj:140311 (BUG)dirlist finename length over flow to rename filed is cut(ovf to date is ok)//~vaujI~
//vaui:140311 find on dirlist by ddstrsrch                         //~vauhI~
//vauh:140311 (BUG)findword reverse up to Attr field when LNX no space between base and extension//~vauhI~
//vauf:140311 (BUG)dirlsit:mebername overflow chk fail when ddfmt contains 0x00 such as dbcs space(0x3000)//~vaufI~
//vaud:140310 Alt+W(Copy to cb)select utf8 code if dirlist member codetype:utf8 none the less kbd mode//~vaudI~
//vau3:140227 copy to clipboard from dirlist;consider utf8name     //~vau3I~
//vau1:140225 (LNX)all by ddfmt on psd(same as old for ascii only) //~vau1I~
//            that is simple for the case dbcs membername was renamed to utf8 name(need to back to cv to utf8 for membername)//~vau1I~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//vajs:130818 find highlight sring length on dir list is short(if FAT ok,but NG for LFN=)//~vajsI~
//vaiz:130624 set slink target not found id to dir list            //~vaizI~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vac1:120204 (SMB)smb node support                                //~vac1I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va8g:101003 display EBC codepage for also directory              //~va8gI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va2p:100114 (BUG)dirlist dbcs split replace err on dirlist       //~va2pI~
//va1F:091117 (BUG:LNX)on console avoid dbcs settin                //~va1FI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va0F:090725!(BUG)rename fld dbcs displayed as "."                //~va0FI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//            conv filename/renamesv/descname to locale if utf8    //~va00R~
//            rename/move.. by filename of the codepage            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          set encoding id on header line                         //~va00I~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v77H:080204 (BUG)dirlist protected fld width dose not expand by resize//~v77HI~
//v77G:080204 keep unprotected if dlcmd err                        //~v77GI~
//v77k:080105*(BUG)dbcs tbl of hdr line was shared                 //~v77kI~
//v777:071204*EUC hankana chk(2byte but 1 column) hankana input not avail on rh9 but on fc5//~v777I~
//v774:071123*(FTP)tiny FTP root filename convention is "/C:/"     //~v774I~
//v770:071114*(BUG)invalid dbcs tbl for header line INS/REP position//~v770I~
//v76S:071016 (BUG)overflow to nextline USDdata for dirlist when no indentation mode//~v76SI~
//v76Q:071001 compchchk !UTF8SUPP compile                          //~v76QI~
//v75R:070512 (WXEXXE:BUG of v62B)if verticaly resized attr fld cleared by setflddata//~v75RI~
//            because UFLD is re-initialized to normal width but expandlen is not added//~v75RI~
//v743:070209*(BUG)rename DBCS 2nd byte is lost when input at boundary to date fled//~v743I~
//v731:061226 filesize>4GB support                                 //~v731I~
//v72v:061202 3270:no gid to be diaplay on dirlist                 //~v72vI~
//v72r:061129 3270:initialy lineno display for TSO SPF             //~v72rI~
//v72o:061127 3270:display vv.mm on attr field                     //~v72oI~
//v719:061004 dirlist DSN list support                             //~v719I~
//v717:060926 3270:dirlist support                                 //~v717I~
//v693:060423 (BUG)when scr resized,remains previous image         //~v693I~
//v692:060418 display expand file-description field(from attr field)//~v692I~
//v690:060418 display file-description support on dir-list panel   //~v690R~
//v64i:050619 (LNX)xxe support;scr width                           //~v64iR~
//v62B:050402 (WXE:BUG of v621)rename fld input is nt avali        //~v62BI~
//            because  dir fld resize dupicated call. UFLD start pos over beyond rename fld.//~v62BI~
//v62c:050312 multireverse option by single foundctr(continuous chk is no problem)//~v62cI~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v62aI~
//v621:050308 (WXE:BUG)scr-resize dose not reset dirlist expanded for not current displayed page//~v621I~
//v61s:050306 for multiple found reverse support;change structure of mfwtbl(offs,len,next entry offset ushort count)//~v61sI~
//v61c:050221 set open parm to filename list to reopen by same option//~v51cI~
//v59Y:041211 (LNX:BUG)dbcs err char(HKDBCSERR) cause screen corruption.it should be repled by '.'.//~v59YI~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v59f:041107 (BUG)attr change not availe for remotefile           //~v59fI~
//v58j:040912 (BUG)dirlist W cmd input,but V(Viwe) is displayed for dir entry//~v58jI~
//v56r:040410 (BUG)column field "(",")" is cleared by wakeup       //~v56rI~
//v56p:040406 UCWFWAKEUP flag is cleared after filewakeup is called by scrpopup,//~v56pI~
//            so dirdraw cannot chk wakeup/resize flag when called //~v56pI~
//v56m:040404 (BUG)scroll field is not displayed when dirlist is vsplited.//~v55mI~
//v55s:040229 remain old value on dirlist attr fld when "a" dlcmd enterd//~v55sI~
//v55h:040214 (FTP)uid/gid display for remote file                 //~v55hI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54k:040105 (UNX,FTP)dirlist:display slink attr when expanded bt f11//~v54kI~
//v54e:040104 (UNX,FTP)dirlist:display slink size/ts when expanded bt f11//~v54eI~
//v54a:040102 dirlist; use ts/size field for for long filename     //~v54aI~
//v541:031223 (WIN,UNX)ftp support;display ipaddr to dir root line //~v541I~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v53W:031222 (WIN,UNX)ftp support;no remote disk space info avail //~v53WI~
//v53P:031101 dir list file size display overflow when GB          //~v53PI~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v51V:030808 v51A is for UNX;for WXE abend when scr size is shorten.//~v51VI~
//            (us Gscrbuffwidth for other than WXE)                //~v51VI~
//v50H:030126 (DOS)no XBC cmd support for memory                   //~v50HI~
//v50b:021207 (BUG)disk freesize se on dirlist memory override at end//~v50bI~
//v49h:020803 for disk size over 2GB,display by unit K(1024)       //~v49hI~
//v481:020420 (BUG)dir list search required ddsetup.(not found for not displayed line)//~v481I~
//v47C:020323 disket support;mkdir,rmdir,attrib                    //~v47CI~
//v47a:020223 (BUG)S+f1(refresh) issue err file not found          //~v47aI~
//             when dirname is expanded by S+f11(long filename display)//~v47aI~
//v45L:020103 (UNX)allow s for S(attr setuid+setgid)               //~v45LI~
//v44j:011204 display timestamp/size until rename fld filled       //~v44jI~
//v43g:011030 save each find word len for multiple word search case//~v43gI~
//            (spanded or *& case)                                 //~v43gI~
//v42q:011008 attrib changed s-->u(setuid)                         //~v42qI~
//v41z:010917 (BUG of v41u)uname/gname cutted                      //~v41zI~
//v41u:010908 (UNX:BUG)groupe name overflow on size fld            //~v41uI~
//v40A:010707 LINUX:mdir support                                   //~v40AI~
//v40t:010616 LNX:slink name display                               //~v40tI~
//v40d:010421 (BUG)long filename is cut by *printed or renamesave  //~v40dI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v21k:010113 LINUX support:dbcs ctl should be under kon even if euc//~v21kI~
//v21i:010113 LINUX support:euc code dbcs support                  //~v21iI~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yI~
//v20h:001003 LINUX support(F6:size,S+F6:uid and username toggle)  //~v20hI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v20fI~
//v205:000930 LINUX support(DDATTRSZ expanded to 5 from 4)         //~v205I~
//v203:000930 LINUX support(new attr specification)                //~v203I~
//v19w:000923 LINUX support(ugetdiskfree parm changed)             //~v19wI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v183:001209 long filename display on dirlist;expand to rename fld//~v183I~
//v182:001209 long filename display on dirlist(over attr fld)      //~v182I~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0k2:980920 use ueditfattr for dirattrstr                        //~v0k2I~
//v0fj:971021 (BUG)no highlight when found on attr                 //~v0fjI~
//v0fg:971019 deleted name may long on renamesv                    //~v0fgI~
//v0fe:971019 (w95/GCC)deney v0fd;copy etc need keep long filename.//~v0feI~
//                     long name and short name is kept.           //~v0feI~
//v0fc:971018 vfat flag should be on ufh not but ufc because uddname created by it//~v0fcI~
//v0fa:971017 fatname from udhalias for w95/gcc under no LFN mode  //~v0faI~
//v0f9:971017 UFCFLFN flag for lfn(common to os2/w95/gcc/dos)      //~v0f9I~
//v0f7:971014 long filename support                                //~v0f7I~
//            search on dir list,it may be hiddlen if too long     //~v0f7I~
//v0f6:971012 (BUG)reverse pos err for find dirlist when indent opt=0//~v0f6I~
//v0f5:971012 reverse full line cmd entered                        //~v0f5I~
//v0f4:971012 (BUG)USDcell clear len overflow for dirlist          //~v0f4I~
//v0f3:971012 long filename support                                //~v0f3I~
//            input long rename field                              //~v0f3I~
//v0f0:971010 long filename support                                //~v0f0I~
//            dir2.c    ;member name display setup                 //~v0f0I~
//            win95 alias dir list option(OPT FAT cmd)             //~v0f0I~
//v09e:970517:update  line search by *u (identify by offset==-1)   //~v09eI~
//v09b:970510:disk free space display                              //~v09bI~
//            -display current free space value on root line(dir2.c)//~v09bR~
//v08b:961103:(BUG)when first split popupped,UCWpsd point 1st half of USD//~v08bI~
//                 but USDpfld etc is of 2nd half which disppeared.//~v08bI~
//                 for win95 it may be page freed cause c0000005.  //~v08bI~
//v085:961024:W95 VC                                               //~v085I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v07lI~
//            bug when "‰\a.*" cause mask display only "a.*"       //~v07lI~
//v07g:960707:printed msg on dir list                              //~v07gI~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//            rensmasv for also copy                               //~v07eI~
//            setflddata clear up to string end                    //~v07eR~
//v06w:960406:(BUG)use panel client color for the line after the bottom//~v06wI~
//v06v:960406:assign pallette no to dir,cmd                           //~v06vI~
//v069:960224:linenosz changeable for edit/browse(set UCWlinenosz)    //~v069I~
//v05K:960107:path id(:) for also edit/bowse dir                //~v05KI~
//v05J:960107:(BUG) of v05h(reverse selected) for NO indent option//~v05JI~
//v05I:960107:dir list indentation space -->'|'(lineno attr)    //~v05IR~
//v05F:960105:rename save field realloc each time(undeleted file may//~v05FI~
//            re-moved to long path name)                       //~v05FI~
//v05E:960105:save move to name on rename fld                   //~v05EI~
//v05y:951223:(BUG)csr set bug of v05w                          //~v05yI~
//v05w:951203:find cmd for dir list                             //~v05wI~
//v05h:951112:dir list,reverse selected entry                   //~v05hI~
//v05e:951111:dir list cmd line colour(yellow)                  //~v05eI~
//v04j:951007:update id for edit saved file on dir list         //~v04jI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v046:950923:view dir lcmd                                     //~v046I~
//v042:950916:xcopy  cmd,copy line cmd                          //~v042I~
//*v03z:950903:attrib cmd                                       //~v03zI~
//*v030:950903:save rename fld for "-"(expand) and " "(cancel)  //~5903R~
//*v030:950903:deleted lineno,updateid                          //~5903I~
//*v030:950709:dir2                                             //~5903I~
//*v020:950610:dir support
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v203I~
	#include <sys/stat.h>                                          //~v203I~
#else  //!UNX                                                      //~v203I~
#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
    	#include <dos.h>                                           //~v085I~
//  	#include <windows.h>                                       //~v085I~
    	#include <windows.h>                                       //~vb4fR~
	#else                                                          //~v085I~
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
	#endif                                                         //~v085I~
#endif
#endif //!UNX                                                      //~v203I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ufemsg.h>                                                //~v731I~
#include <ufile4.h>                                                //~v09bI~
#include <ualloc.h>
#include <uedit.h>
#include <uedit2.h>                                                //~v0k2I~
#include <ustring.h>                                               //~v07lI~
#include <ucalc2.h>                                                //~v49hI~
#include <udbcschk.h>                                              //~v59YI~
#include <utrace.h>                                                //~v692I~
#define UVIOMDEFONLY	//for uviom.h                              //~vb4fI~
#include <uviom.h>                                                 //~vb4fR~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <utf.h>                                                   //~v903I~//~va00I~
#endif                                                             //~va00I~
                                                                   //~v20fI~
#ifdef UNX                                                         //~v20fI~
	#include <uunxsub.h>                                           //~v20fI~
#endif //UNX                                                       //~v20fI~
#ifdef FTPSUPP                                                     //~v541I~
	#include <uftp.h>                                              //~v541I~
	#include <u3270.h>                                             //~v717I~
#endif                                                             //~v541I~
#include <ufilew.h>                                                //~vavaR~

#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefunc.h"
#include "xefile.h"
#include "xefile2.h"
#include "xefile3.h"                                            //~5819I~
#include "xedir.h"
#include "xedir2.h"
#include "xedir3.h"                                                //~v182I~
#include "xedir4.h"                                                //~v690I~
#include "xepan.h"
#include "xepan22.h"                                               //~v20yI~
#include "xesub.h"
#include "xesub2.h"                                                //~va1cR~
#include "xegbl.h"                                                 //~v21iI~
#include "xeerr.h"                                                 //~v53cI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeutf.h"                                                 //~v903I~//~va00I~
	#include "xeutf2.h"                                            //~vau0I~
	#include "xeopt.h"                                             //~v91gI~//~va00I~
#endif                                                             //~va00I~
#include "xefsubw.h"                                               //~vavgI~
//*******************************************************
#define FILENAMEPOS   8
#define UPDATEID      '*'    //update file/line id
#define NOTUPDATEDID  '|'    //update file/line id
#define DIRL_SLINKID  '@'	//slink entry                          //~v40tR~
#define DIRL_SLINKIDERR  "?"	                                   //~vaizI~
//*************************                                        //~v56pR~
//#ifdef WXE                                                       //~v621R~
//    static int Sresizesw=0;                                      //~v621R~
//#endif                                                           //~v621R~
//*************************
static UCHAR Scolor_lineno,Scolor_client,Scolor_client_r,       //~v05eR~
             Scolor_dlcmd,Scolor_dlcmd_r;                       //~v05eI~
//#ifdef W32UNICODE                                                  //~vavaR~//~vavgR~
//    static UCHAR Scolor_subch;                                     //~vavaR~//~vavgR~
//#endif                                                             //~vavaR~//~vavgR~
//*************************
void dirddsetup(PUCLIENTWE Ppcw,PULINEH Pplh,PUPANELL Pppl);       //~v481R~
//void dirddsetup2(PUCLIENTWE Ppcw,PULINEH Pplh);                  //~v692R~
void dirlineattr(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd);
//int dirsetdbcssplit(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar);//~vauNR~
int dirsetdbcssplit(PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar);//~vauNR~
//int dirresize(PUCLIENTWE Ppcw);                                  //~v621R~
int dirresize(PUCLIENTWE Ppcw,int Popt);                           //~v621I~
void dirvsplitshift(PUCLIENTWE Ppcw);                              //~v55mR~
int dirsetdescdata(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLD Ppdh,PUDIRLD Ppdhexpand,UCHAR *Pdata);//~v692I~
                                                                   //~v20fI~
//#ifdef UNX                                                       //~v55hR~
#ifdef FTPSUPP                                                     //~v55hI~
//void dirugidedit(PUDIRLH Ppdh,PUDIRLD Ppdd);                     //~v55hR~
//void dirugidedit(PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLD Ppdd);        //~v59TR~
void dirugidedit(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLD Ppdd);//~v59TI~
#endif //UNX                                                       //~v20fI~
#ifdef UTF8SUPPH                                                   //~v918I~//~va00I~
	int dirlineattrrenamefld(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd,PUDIRLH Ppdh);//~va00R~
	int dirlineattrdescfld(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd);//~v91gI~//~va00I~
	int dirsetdbcstbl(int Popt,char *Pdata,char *Pdbcs,int Plen);  //~va1cR~
	#define DSDTO_FULLLINE           0x01 //line is split by null  //~va1cR~
#endif                                                             //~v918I~//~va00I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
	int dirsetdbcstblDDFMT(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,char *Pdata,char *Pdbcs,int Plen);//~vau0I~
	int dirsetflddataDDFMT(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,int Pfldno,char *Pdata,int *Ppoffs);//~vau0R~
	void drawrenameDDFMT(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,char *Psddata,char *Psddbcs,int Plen);//~vau0R~//~vau1R~
void drawrenameDDFMT2(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,char *Ppsddata,char *Ppsddbcs,int Plen);//~vawaI~
#ifdef LNX                                                         //~vauEI~
#else                                                              //~vauBI~//~vauER~
#ifdef CCC                                                         //~vauER~
	void xedir_savelcctforerrmsg(int Popt,PUCLIENTWE Ppcw,PUDIRLH Ppdh,char *Pfnm,int Plen);//~vauBR~
	#define XEDSFEO_SLINK        0x01                              //~vauBI~
	#define XEDSFEO_FNM          0x02                              //~vauBI~
#endif                                                             //~vauEI~
#endif                                                             //~vau0I~
int dirgetfldoffs(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno);        //~vawaI~
int dirsavename_byu8lc(int Popt,PULINEH Pplh,UCHAR *Putf8,int Pu8len,UCHAR *Pplc,int Pbuffsz,int *Ppplclen);//~vawnR~
int dirgetmixstropt(int Popt,PULINEH Pplh,char *Pdata);            //~vawpI~
//****************************************************************
//!dirregist                                                    //~v04dR~
//*file clientwe and set field def
//*parm1:browse/edit/file option
//*parm2:pfh
//*rc   :pcw or 0 if storage shortage                           //~v04dR~
//****************************************************************
//PUCLIENTWE dirregist(int Popt,PUFILEH Ppfh)                      //~v690R~
PUCLIENTWE dirregist(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)        //~v690I~
{
	PUFILEC pfc;
	PUCLIENTWE pcw;
	PUPANELC ppc;
//  UCHAR *pc;                                                     //~v51VR~
#ifdef UTF8SUPPH                                                   //~v91gI~//~va00I~
	UCHAR opt2;                                                    //~v91gI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	UCHAR optebc;                                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~v91gI~//~va00I~
//*******************
//*UFILEC init
#ifdef UTF8SUPPH                                                   //~v91gI~//~va00I~
	opt2=(UCHAR)(Popt>>8);	//CPU8 option                          //~v91gI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	optebc=(UCHAR)(Popt>>16);	//FHflag10                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	Popt&=0xff;                                                    //~v91gI~//~va00I~
#endif                                                             //~v91gI~//~va00I~
	pfc=UALLOCC(1,UFILECSZ);                                    //~v04dR~
    UALLOCCHK(pfc,0);   //return 0 if storage shortage          //~v04dI~
    memcpy(pfc->UFCcbid,UFCCBID,4);     //set acronym
    pfc->UFCtype=UFCTDIRL;     			//type
    pfc->UFCflag=(UCHAR)Popt;					//browse
	pfc->UFCpfh=Ppfh;
	pfc->UFCcurtop=UGETQTOP(&Ppfh->UFHlineque);
	if (!(ppc=pangetpc(PANDIR)))                                //~v04dR~
    {                                                           //~v04dI~
    	ufree(pfc);                                             //~v04dI~
        return 0;                                               //~v04dI~
    }                                                           //~v04dI~
	pcw=scrregist(UCWTDIR,ppc);//display width;
	if (!pcw)                                                   //~v04dI~
    {                                                           //~v04dI~
        panfreepc(ppc);                                         //~v04dI~
    	ufree(pfc);                                             //~v04dI~
        return 0;                                               //~v04dI~
    }                                                           //~v04dI~
	pcw->UCWpfc=pfc;
    pcw->UCWlinenosz=UDHLINENOSZ;                                     //~v069I~
	pfc->UFCpcw=pcw;                                            //~v046I~
#ifdef UTF8SUPPH                                                   //~v91gI~//~va00I~
    if (XEUTF8MODE())   //use pfc for lang mode of dirlist         //~v91gI~//~va00I~
    {                                                              //~v91gI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (optebc & UFHF10EBC)                //CPEB                //~va50I~
      {                                                            //~va50I~
        UCBITON(pfc->UFCflag3,UFCF3EBC);                           //~va50I~
        if (optebc & UFHF10EBCP)               //CPU8 cmd parameter//~va50I~
        	UCBITON(pfc->UFCflag3,UFCF3EBCP);                      //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      {                                                            //~va50I~
//      if (opt2 & UFCF2UTF8)                //CPU8 cmd parameter  //~v922R~//~va00I~
        if (opt2 & UFHF8UTF8)                //CPU8 cmd parameter  //~v922I~//~va00I~
        	UCBITON(pfc->UFCflag2,UFCF2UTF8);                      //~v91gR~//~va00I~
        if (opt2 & UFHF8UTF8P)               //CPU8 cmd parameter  //~v922R~//~va00I~
        	UCBITON(pfc->UFCflag2,UFCF2UTF8P);                     //~v922I~//~va00I~
//      UCBITON(Ppfh->UFHflag8,UFHF8UTF8);  //dir list is utf8 mode//~v91gR~//~va00R~
      }                                                            //~va50I~
    }                                                              //~v91gI~//~va00I~
#endif                                                             //~v91gI~//~va00I~
//  filewakeup(pcw);			//init USCRD                       //~v56pR~
    dirwakeup(pcw);			//init USCRD                           //~v56pR~
//hdr line EDIT/BROWSE/FILE id                                  //~5820I~
//    pc=ppc->UPCline[0].UPLbuff;                                  //~v51VR~
//    if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                        //~v51VR~
//        memcpy(pc,"EDIT",4);                                     //~v51VR~
//    else                                                         //~v51VR~
//        if (UCBITCHK(pfc->UFCflag,UFCFDFILE))                    //~v51VR~
//            memcpy(pc,"FILE",4);                                 //~v51VR~
//        else                                                     //~v51VR~
//            memcpy(pc,"BROWSE",6);                               //~v51VR~
//  dirresize(pcw);                                                //~v621R~
    dirresize(pcw,1);	//init call                                //~v621I~
	csrhomepos(0);			//move csr to 1st fld of current active
	ppc->UPCscroll=Ginitscroll[GSCROLLDIR];	//default page scroll//~5819R~
	filesetscrollsz(pcw,filegetscrollid(Ginitscroll[GSCROLLDIR]));	//default half//~5819I~
                                                                   //~v20yI~
//  pan300stack(pcw,Ppfh); //stack filename for filelist on menu 1/2//~v51cR~
//  pan300stack(pcw,Ppfh,0); //stack filename for filelist on menu 1/2//~v690R~
    pan300stack(pcw,Ppfh,Ppcw); //stack filename for filelist on menu 1/2//~v690I~
                                                                   //~v20yI~
	return pcw;
}//dirregist

//**************************************************************** //~v51VI~
//!dirresize                                                       //~v51VI~
//*wakeup for dir special                                          //~v51VI~
//*rc   :pcw or 0 if storage shortage                              //~v51VI~
//**************************************************************** //~v51VI~
//int dirresize(PUCLIENTWE Ppcw)                                   //~v621R~
int dirresize(PUCLIENTWE Ppcw,int Popt)                            //~v621I~
{                                                                  //~v51VI~
    UCHAR *pc;                                                     //~v51VI~
	PUFILEC  pfc;                                                  //~v51VI~
	PUPANELC ppc;                                                  //~v51VI~
    int expandlen;                                                 //~v59TI~
#ifdef WXEXXE                                                      //~vaa7I~
#else                                                              //~vaa7I~
    int oldexplen;                                                 //~v62BI~
#endif                                                             //~vaa7I~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    int resetsw;                                                   //~v621I~
#endif                                                             //~v621I~
//*******************                                              //~v51VI~
	pfc=Ppcw->UCWpfc;                                              //~v51VI~
	ppc=Ppcw->UCWppc;                                              //~v51VI~
#ifdef WXEXXE                                                      //~vaa7I~
#else                                                              //~vaa7I~
    oldexplen=pfc->UFCexpandlen;                                   //~v62BI~
#endif                                                             //~vaa7I~
    expandlen=min(Gscrwidth,MAXCOLUMN)-(UDHLINENOSZ+UDIRLDSZ+1);    //expand filename fld when scr is wide//~v59TR~
    if (expandlen<0)                                               //~v59TI~
    	expandlen=0;                                               //~v59TI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    resetsw=!(Popt & 0x01) && (pfc->UFCexpandlen!=expandlen);//not init and resized//~v621I~
#endif                                                             //~v621I~
    pfc->UFCexpandlen=expandlen;                                   //~v59TI~
//  if (expandlen)                                                 //~v62BR~
#ifdef WXEXXE                                                      //~v75RI~
    if (!(Popt & 0x01))	//from direakeup if UFHF6RESIZE is on which means ppdinit_resize is done at filewakeup by UCWRESIZE//~v75RI~
#else                                                              //~v75RI~
    if (expandlen!=oldexplen)                                      //~v62BI~
#endif                                                             //~v75RI~
	    pandirfldresize(Ppcw,expandlen);                           //~v59TR~
//hdr line EDIT/BROWSE/FILE id                                     //~v51VI~
    pc=ppc->UPCline[0].UPLbuff;                                    //~v51VI~
    if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                          //~v51VI~
        memcpy(pc,"EDIT",4);                                       //~v51VI~
    else                                                           //~v51VI~
        if (UCBITCHK(pfc->UFCflag,UFCFDFILE))                      //~v51VI~
            memcpy(pc,"FILE",4);                                   //~v51VI~
        else                                                       //~v51VI~
            memcpy(pc,"BROWSE",6);                                 //~v51VI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    if (resetsw)	//re-execute ddsetup                           //~v621I~
//      dirddresetallsub(Ppcw,pfc->UFCpfh);	//clear ddsetup flag   //~v693R~
        dirddresetallsub(DDRESET_RESIZE,Ppcw,pfc->UFCpfh);	//clear ddsetup flag//~v693I~
#endif                                                             //~v621I~
    return 0;                                                      //~v51VI~
}//dirresize                                                       //~v51VI~
//**************************************************************** //~v56pR~
// dirwakeup                                                       //~v56pR~
//*called fro scrpopup                                             //~v56pR~
//*rc   :0                                                         //~v56pR~
//**************************************************************** //~v56pR~
int dirwakeup(PUCLIENTWE Ppcw)                                     //~v56pR~
{                                                                  //~v56pR~
    int rc;                                                        //~v621I~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    PUFILEH pfh;                                                   //~v621I~
#endif                                                             //~v621I~
//*******************                                              //~v56pR~
//#ifdef WXE                                                       //~v621R~
//    Sresizesw=UCBITCHK(Ppcw->UCWflag,UCWFRESIZE);   //cleared after filewakeup//~v621R~
//#endif                                                           //~v621R~
//  return filewakeup(Ppcw);                                       //~v621R~
    rc=filewakeup(Ppcw);                                           //~v621I~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v621I~
    if (UCBITCHK(pfh->UFHflag6,UFHF6RESIZE))	//filewakeup set?  //~v621R~
    {                                                              //~v621I~
        dirresize(Ppcw,0);  //not 1st call of dir regist           //~v621I~
        pandirprot(0,-1);	//reset static value                   //~v77HI~
    	UCBITOFF(pfh->UFHflag6,UFHF6RESIZE);   //done              //~v621I~
    }                                                              //~v621I~
#endif                                                             //~v621I~
    return rc;                                                     //~v621I~
}//dirwakeup                                                       //~v56pR~
//****************************************************************
//!func_draw_dir
//*setup screen line data
//*parm1:file client work element
//*rc   :0
//****************************************************************
int func_draw_dir(PUCLIENTWE Ppcw)
{
	UCHAR  *pc,*pcd;
	UCHAR  *pcd2;                                                  //~v59YI~
	int     len,len2,maxline,line,drawline;
	int     csrfldtopline=0,fulldrawsw;                         //~5807R~
    int     revctr;		//findctr                               //~v05wI~
    int     expandlen;	//filename field width expand              //~v59TI~
	PUSCRD  psd,psdline;
	PUPANELC  ppc;
	PUFILEH pfh;
	PULINEH plh;
	PUDIRLH pdh;                                                //~5812I~
	UFILEC *pfc;
	PUPANELL ppl;
//  PUPANELD ppd;                                                  //~v77HR~
//#ifdef WXE                                                       //~v621R~
//    int resizesw=0;                                              //~v621R~
//#endif                                                           //~v621R~
#ifdef FTPSUPP                                                     //~v717I~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v717I~
#endif                                                             //~v717I~
	int swxkbd;                                                    //~va3KR~
//****************************
	if (UCBITCHK(Ppcw->UCWflag,UCWFWAKEUP))
//  {                                                              //~v08bR~
    {                                                              //~v51VI~
//  	UCBITOFF(Ppcw->UCWflag,UCWFWAKEUP);                        //~v08bR~
//#ifdef WXE                                                       //~v621R~
//        resizesw=UCBITCHK(Ppcw->UCWflag,UCWFRESIZE);    //cleared at filewakeup->ppdinit_resize//~v621R~
//#endif                                                           //~v621R~
//  	filewakeup(Ppcw);			//init USCRD                   //~v56pR~
    	dirwakeup(Ppcw);			//init USCRD                   //~v56pI~
//#ifdef WXE                                                       //~v621R~
//        if (resizesw)   //wakeup by resize                       //~v621R~
//            dirresize(Ppcw);                                     //~v621R~
//#endif                                                           //~v621R~
//  }                                                              //~v08bR~
    }                                                              //~v51VI~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	plh=pfc->UFCcurtop;						//top line to be display
	maxline=Ppcw->UCWheight-FILEHDRLINENO;		//except hdr and cmd
    expandlen=pfc->UFCexpandlen;	//expand if scr is wide        //~v59TI~
	psd=Ppcw->UCWpsd;
	ppc=Ppcw->UCWppc;
//  ppd=ppc->UPCppd;                                               //~v77HR~
	len=Ppcw->UCWwidth;
	Scolor_client=Gattrtbl[COLOR_DCLIENT];	//dirlist lient           //~v06vR~
	Scolor_client_r=Gattrtbl[COLOR_DCLIENT_R];                        //~v06vR~
	Scolor_lineno=Gattrtbl[COLOR_DLINENO];	//browse fg               //~v06vR~
//  Scolor_lineno_r=Gattrtbl[COLOR_BLINENO_R];	//browse fg     //~v05eR~
	Scolor_dlcmd=Gattrtbl[COLOR_DLINCMD];	//browse fg               //~v06vR~
	Scolor_dlcmd_r=Gattrtbl[COLOR_DLINCMD_R];	//browse fg           //~v06vR~
//#ifdef W32UNICODE                                                  //~vavaR~//~vavgR~
//    Scolor_subch=Gattrtbl[COLOR_ECLIENT];   //edit fg              //~vavaR~//~vavgR~
//#endif                                                             //~vavaR~//~vavgR~
	fulldrawsw=UCBITCHK(Ppcw->UCWflag,UCWFDRAW);                //~5807I~
    if (fulldrawsw)                                                //~v55mI~
        dirvsplitshift(Ppcw);                                      //~v55mR~
//**hdr line
	pc=psd->USDdata;                                            //~5820I~
	psd->USDlen=len;                                            //~5820I~
	psd->USDoff=0;		//write to from leftmost column         //~5820I~
    swxkbd=0;                                                      //~va3KR~
    if (Ghexctl[HEXCTL_MODE]                                       //~va3KR~
    &&  Ppcw->UCWsplitid==Gscrcurclient)	//active pcw           //~va3KR~
    {                                                              //~va3KR~
		UCBITON(psd->USDflag2,USDF2DRAW);                          //~va3KR~
        swxkbd=1;                                                  //~va3KR~
    }                                                              //~va3KR~
	if (fulldrawsw                                              //~5807R~
	||  UCBITCHK(psd->USDflag2,USDF2DRAW))
    {                                                              //~v770I~
		memcpy(pc,psd->USDbuffc,(UINT)len); //hdr line data     //~5820R~
//  	memcpy(psd->USDdbcs,ppd->UPDdbcs,(UINT)len);	//dbcs id tbl//~v77kR~
    	memcpy(psd->USDdbcs,ppc->UPCline[0].UPLdbcs,(UINT)len);	//dbcs id tbl//~v77kI~
    }                                                              //~v770I~
	if (pfh->UFHupctr	//updated                               //~5820R~
	&&  pfh->UFHupctr!=pfh->UFHupctrsave)	//same as saved     //~5820R~
		*(pc+FILENAMEPOS-1)=UPDATEID;                           //~5820R~
	else                                                        //~5820R~
		*(pc+FILENAMEPOS-1)=NOTUPDATEDID;                       //~5820R~
        if (swxkbd)                                                //~va3KR~
        	pandrawxkbd(0,Ppcw,psd);                               //~va3KR~
//**cmd line
	psd++;
	filecmdlinedisp(Ppcw,psd);                                  //~5731I~
	psd++;
//*determine plh on psd
	psdline=psd;	//save top
	for (line=0;line<maxline;line++,psd++,plh=UGETQNEXT(plh))
	{
		if (!plh)
			break;
		if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))	//excluded  //~5812I~
		{                                                       //~5812I~
			line--;                                             //~5812I~
			psd--;                                              //~5812I~
			continue;                                           //~5812I~
		}                                                       //~5812I~
		psd->USDbuffc=plh;
//*csr set req
		if (plh==pfc->UFCcsrplh)	//csr set requested
			csrfldtopline=line+2;	//later csrfldtop
    }
	drawline=line;
	psd=psdline;	//restore
	plh=pfc->UFCcurtop;		//restore top line to be display
	pfc->UFCcsrplh=0;	//csr set request processed

    pfc->UFCmaxline=line;			    //displayed scr plh no
    Ppcw->UCWmaxline=min(line+FILEHDRLINENO,Ppcw->UCWheight);//scr lineno
	revctr=pfh->UFHfindctr;		//for display/clear linenosz    //~v05wI~
//  if (revctr==pfh->UFHfindctrme)	//multi reverse continueing    //~v62cR~
//  	if (pfh->UFHfindctrms>0 && pfh->UFHfindctrms<=pfh->UFHfindctrme)	//reverse from multi reverse start//~v62cR~
//      	revctr=pfh->UFHfindctrms;	//reverse from multi reverse start//~v62cR~
//*draw file line
	for (line=0;line<drawline;line++,psd++)
	{
		plh=psd->USDbuffc;
		if (UCBITCHK(plh->ULHflag,ULHFCURFOUND)	//cur found line//~v05wI~
		&&  plh->ULHrevctr < revctr)		//but new find occured//~v05wI~
		{                                                       //~v05wI~
			UCBITON(plh->ULHflag,ULHFDRAW);		//redraw for clear found//~v05wI~
			UCBITOFF(plh->ULHflag,ULHFCURFOUND);//cleared       //~v05wI~
		}                                                       //~v05wI~
		if (!fulldrawsw                                         //~5807I~
		&&  !UCBITCHK(plh->ULHflag,ULHFDRAW))//char input       //~5807R~
			continue;
	    UCBITON(psd->USDflag2,USDF2DRAW);		//req dispaly
//*lineno edit
        ppl=&ppc->UPCline[line+FILEHDRLINENO];
        pdh=UGETPDH(plh);                                          //~v183I~
		if (plh->ULHtype==ULHTDATA)	//file data
		{
//          pdh=UGETPDH(plh);                                      //~v183R~
    		if (pdh->UDHtype==UDHTDIREXPMASK)	//initialy mask specified//~5812R~
    		{                                                   //~5812R~
//       		pc=strrchr(pfh->UFHfilename,'\\');	//search last  //~v07lR~
//       		pc=ustrrchr2(pfh->UFHfilename,'\\');	//search last//~v19aR~
//       		pc=ustrrchr2(pfh->UFHfilename,DIR_SEPC);	//search last//~v540R~
#ifdef FTPSUPP                                                     //~v717I~
              if (FILEISTSO(pfh))                                  //~v717R~
              {                                                    //~v717I~
    			if (u3270getlastname(0,pfh->UFHfilename,membname))//0:no dummy set//~v719R~
                	pc=membname-1;  //                             //~v717R~
                else                                               //~v717I~
                	pc=0;                                          //~v717I~
              }                                                    //~v717I~
              else                                                 //~v717I~
#endif                                                             //~v717I~
         		pc=ustrrchr2(pfh->UFHfilename,pfh->UFHdirsepc);	//search last//~v540I~
#ifdef FTPSUPP                                                     //~v774I~
	        	if (FILEISREMOTE(pfh)                              //~v774I~
                &&  !FILEISTSO(pfh)                                //~v774I~
        	    &&  pc                                             //~v774I~
                &&  !WILDCARD(pc)                                  //~v774I~
                   )                                               //~v774I~
                	pc=0;	//avoid rename save(not wild but no "." for "/"(root=home such as /P:/ for tiny FTP daemon)//~v774I~
#endif                                                             //~v774I~
        		if (pc)                                         //~5812M~
                {                                               //~5903I~
    				dirsetflddata(Ppcw,plh,PANL310RENAME,pc+1); //~5812M~
    				dirsavename(plh,pc+1);                      //~5903I~
				}                                               //~5903I~
//    			pdh->UDHtype=UDHTDIREXP;	//initialy mask specified//~v05KR~
     			pdh->UDHtype=UDHTPARENT;	//change to path dir//~v05KI~
        	  if (pc)                                              //~v774I~
              {                                                    //~v774I~
    			UCBITON(pdh->UDHflag,UDHFMASK);                 //~5812M~
    			UCBITON(pdh->UDHflag2,UDHF2MASKNAME);              //~v47aI~
              }                                                    //~v774I~
    		}                                                   //~5812R~
            dirddsetup(Ppcw,plh,ppl);     //dir data line setup    //~v07eR~
    		if (plh->ULHupctr)                                  //~5903R~
    			*(plh->ULHlineno+UDHLINENOSZ-1)=UPDATEID;       //~5903R~
			len=max(0,min(Ppcw->UCWwidth-UDHLINENOSZ,plh->ULHlen));
			len2=Ppcw->UCWwidth-UDHLINENOSZ-len;//len after data
		}
		else
		{
			len=max(0,Ppcw->UCWwidth-UDHLINENOSZ);
			len2=0;							//after data len
		}
		memset(pcd=psd->USDdbcs,0,UDHLINENOSZ);//dbcsid
		memcpy(pc=psd->USDdata,plh->ULHlineno,UDHLINENOSZ);	//lineno
		if (UCBITCHK(plh->ULHflag,ULHFLINECMD))//line cmd input
			if (*plh->ULHlinecmd && *plh->ULHlinecmd!=' ')
				*pc=*plh->ULHlinecmd;
		pc+=UDHLINENOSZ;
		pcd+=UDHLINENOSZ;
//*data edit
		if (len)
		{
            if (plh->ULHtype!=ULHTDATA) //hdr line                 //~va8gI~
                dirsetlocaleid(0,pfc,UTCDATA(pc));                 //~va8gI~
			memcpy(pc,plh->ULHdata,(UINT)len);//data
			memcpy(pcd,plh->ULHdbcs,(UINT)len);	//dbcs id tbl
//#ifdef LNX                                                         //~vau0I~//~vauER~
#ifdef GGG                                                         //~vawaR~
        	if (UCBITCHK(pdh->UDHflag5,UDHF5SETRENAMEDD))   //call drawrenamedd//~vawaM~
            {                                                      //~vawaM~
             	drawrenameDDFMT2(Ppcw,plh,pdh,pc,pcd,len);//draw by ddfmt if required//~vawaI~
		 		UCBITOFF(pdh->UDHflag5,UDHF5SETRENAMEDD);   //call drawrenamedd//~vawaM~
            }                                                      //~vawaM~
            else                                                   //~vawaI~
#endif                                                             //~vawaR~
//    		if (UCBITCHK(pdh->UDHflag4,UDHF4NOTSETDD))	//FDDSETUP is already on//~vawmR~
//				if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))	//rename cmd input//~vawmR~
			if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))	//rename cmd input//~vawmI~
            {                                                      //~vawmI~
                UTRACEP("drawdir CMDIN2 UDHflag4=%x\n",(int)pdh->UDHflag4);//~vb14I~
            	if (UCBITCHK(pdh->UDHflag5,UDHF5PASTERENAME))//pasted//~vawqI~
                {                                                  //~vawqI~
	            	UCBITOFF(pdh->UDHflag5,UDHF5PASTERENAME);//drawn//~vawqI~
                	drawrenameDDFMT(Ppcw,plh,pdh,pc,pcd,len);//draw by ddfmt if required//~vawqI~
                }                                                  //~vawqI~
//#ifdef KKK                                                       //~vb15R~
                else                                               //~vawqI~
            	if (UCBITCHK(pdh->UDHflag5,UDHF5CHNGRNOVF))  //char input occuered just overflow//~vawmR~
                {                                                  //~vawmI~
	            	UCBITOFF(pdh->UDHflag5,UDHF5CHNGRNOVF);  //char input occuered just overflow//~vawmR~
                	drawrenameDDFMT(Ppcw,plh,pdh,pc,pcd,len);//draw by ddfmt if required//~vawmI~
                }                                                  //~vawmI~
//#endif                                                           //~vb15R~
                else                                               //~vawmI~
	    		if (UCBITCHK(pdh->UDHflag4,UDHF4NOTSETDD))	//FDDSETUP is already on//~vawmI~
                	drawrenameDDFMT(Ppcw,plh,pdh,pc,pcd,len);//draw by ddfmt if required//~vau0R~//~vau1R~
                else                                               //~vb3aI~
				if (UCBITCHK(pdh->UDHflag4,(UDHF4RENAMEU8|UDHF4RENAMELC)))//~vb3aI~
                	drawrenameDDFMT(Ppcw,plh,pdh,pc,pcd,len);//draw by ddfmt if required//~vb3aI~
            }                                                      //~vawmI~
//#endif                                                             //~vau0I~//~vauER~
//#ifdef UTF8SUPPH                                                   //~v918M~//~va00R~//~va8gR~
//            if (plh->ULHtype!=ULHTDATA) //hdr line                 //~v91gI~//~va00I~//~va8gR~
//                dirsetlocaleid(0,pfc,UTCDATA(pc));                 //~v91gR~//~va00I~//~va8gR~
//#endif                                                             //~v918M~//~va00I~//~va8gR~
//UTRACED("dir2 SDdata",pc,len);                                   //~v693R~
//  		setdbcssplit(pc,pcd,len,'.');                          //~v183R~
//    		dirsetdbcssplit(pc,pcd,len,'.');                       //~vauNR~
      		dirsetdbcssplit(plh,pc,pcd,len,'.');                   //~vauNI~
			if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN1))	//attr cmd input//~v183I~
            {                                                      //~v59TI~
  				pc+=expandlen; 	//ajust by expand len              //~v59TR~
  				pcd+=expandlen;                                    //~v59TI~
//              if (*(pcd+offsetof(UDIRLD,UDDattrflag)-1)==DBCS1STCHAR)//~v59YR~
                pcd2=pcd+offsetof(UDIRLD,UDDattrflag)-1;           //~v59YI~
//** dirsetdbcstbl already resolved dbcs split; HKDBCSERR is set for split dbcs***//~va1cR~
                if (*pcd2==DBCS1STCHAR                             //~v59YI~
                ||  *pcd2==UDBCSCHK_HKDBCSERR 	//dbcs conbination err//~v59YI~
//#ifdef LNX                                                         //~vau0I~//~vauER~
#ifdef UTF8UCS416                                                  //~vaw1I~
                ||  UDBCSCHK_DBCS1STUCS2NWPO(*pcd2) 	//ddfmt ucs 1st of 2//~vaw1I~
#else                                                              //~vaw1I~
                ||  UDBCSCHK_DBCS1STUCS2NWP(*pcd2) 	//ddfmt ucs 1st of 2//~vau0I~
#endif                                                             //~vaw1I~
//#endif                                                             //~vau0I~//~vauER~
                ||  *(pcd2+1)==DBCS2NDCHAR) 	//dbcs conbination match by input//~v59YI~
                {//attr input conbined with filename dbcs          //~v183R~
//                  *(pcd+offsetof(UDIRLD,UDDattrflag)-1)=0;       //~v59YR~
                    *pcd2=0;                                       //~v59YI~
                    *(pc+offsetof(UDIRLD,UDDattrflag)-1)='.';      //~v183R~
//                  *(pcd+offsetof(UDIRLD,UDDattrflag))=0;         //~v59YR~
                    *(pcd2+1)=0;                                   //~v59YI~
                }                                                  //~v183R~
  				pc-=expandlen; 	//ajust by expand len              //~v59TR~
  				pcd-=expandlen;                                    //~v59TI~
            }                                                      //~v59TI~
  			pc+=len;
  			pcd+=len;
		}//data exist
		if (len2>0)
		{
			memset(pcd,0,(UINT)len2);
			memset(pc,' ',(UINT)len2);
		}
		psd->USDlen=Ppcw->UCWwidth;
//*setup color
		dirlineattr(Ppcw,plh,psd);
#ifdef UTF8SUPPH                                                   //~v918I~//~va00I~
		if (UCBITCHK(pdh->UDHflag2,UDHF2SETRENAME))	//attr,rename,timestamp is not drawed//~va00I~
            dirlineattrrenamefld(Ppcw,plh,psd,pdh);                //~va00I~
#ifdef W32                                                         //~vb3fM~
    	pc=psd->USDcell+(UDHLINENOSZ+(int)offsetof(UDIRLD,UDDrsv3)+expandlen)*2;   //UDDattrflag//~vb3fI~
    	if (*pc==0)                                      //attr was set//~vb3fI~
        	*(pc+1)=0;	//delm to uviom ligature                   //~vb3fM~
#endif                                                             //~vb3fM~
        if (UCBITCHK(pdh->UDHflag3,(UDHF3SETDESC|UDHF3DESCATTR))==(UDHF3SETDESC|UDHF3DESCATTR))     //no desc//~v91gR~//~va00I~
            dirlineattrdescfld(Ppcw,plh,psd);                      //~v91gI~//~va00I~
#endif                                                             //~v918I~//~va00I~
		UCBITOFF(plh->ULHflag,ULHFDRAW);		//already displayed//~5807M~
	}//while ULINEH exist
//after bottom of data
	if (fulldrawsw)                                             //~5807I~
		for (;line<maxline;line++,psd++)
		{
			psd->USDbuffc=0;				//no corresponding plh
			psd->USDflag = USDFNCELL;
			psd->USDuvioo=0;	//noligature                       //~vb4fR~
			psd->USDnattr0len=0;			//write once
			psd->USDcell0len=0;				//no linenofld data
			psd->USDlen=Ppcw->UCWwidth;
			*psd->USDcell=' ';
			*(psd->USDcell+1)=Gattrtbl[COLOR_FRAME];                  //~v06wI~
		}
//*determine csr line
	if (csrfldtopline)
    {                                                           //~v05yI~
    	if (pfc->UFCcsrfldno==FROMLEFT)                         //~v05yI~
        	len=UDHLINENOSZ;                                    //~v05yI~
        else                                                    //~v05yI~
        	len=0;                                              //~v05yI~
		csronthefld(Ppcw,csrfldtopline,pfc->UFCcsrfldno,        //~v05wR~
                    pfc->UFCcsroffs+len); //move csr            //~v05yR~
	}                                                           //~v05yI~
//#ifdef WXE                                                       //~v621R~
////  Sresizesw=0;    //set once at wakeup                         //~v621R~
//    UCBITOFF(pfh->UFHflag6,UFHF6RESIZE);   //if resized setup all//~v621R~
//#endif                                                           //~v621R~
	return 0;
}//func_draw_dir

//**************************************************************** //~v481I~
//!dirddset2                                                       //~v481I~
//*setup line dir data line for find cmd                           //~v481I~
//*parm1:pcw                                                       //~v481I~
//*parm2:plh                                                       //~v481I~
//*rc   :none                                                      //~v481I~
//**************************************************************** //~v481I~
void dirddsetup2(PUCLIENTWE Ppcw,PULINEH Pplh)                     //~v481I~
{                                                                  //~v481I~
	PUPANELC  ppc;                                                 //~v481I~
	PUPANELL ppl;                                                  //~v481I~
//****************************                                     //~v481I~
	ppc=Ppcw->UCWppc;                                              //~v481I~
    ppl=&ppc->UPCline[FILEHDRLINENO];                              //~v481I~
	dirddsetup(Ppcw,Pplh,ppl);                                     //~v481I~
    return;                                                        //~v481I~
}//dirddsetup2                                                     //~v481I~
//****************************************************************
//!dirddset
//*setup line dir data line
//*parm1:pcw                                                       //~v07eR~
//*parm2:plh                                                       //~v07eI~
//*parm3:ppl                                                       //~v07eI~
//*rc   :none
//****************************************************************
void dirddsetup(PUCLIENTWE Ppcw,PULINEH Pplh,PUPANELL Pppl)        //~v07eR~
{
	PUDIRLH pdh;
	PUFILEC pfc;                                                //~v046I~
	PUFILEC pfc0;                                                  //~v690I~
	PUFILEH pfh;                                                   //~v0fcI~
	PUDIRLD pdd;
	PUDIRLD pddexpand;	//for point field after UDDname            //~v59TI~
	PUFLD   pfld;                                               //~5813I~
	UCHAR   *pc;                                                //~5731R~
	UCHAR   *pc0;                                                  //~v0f0I~
    int level,fldid=0,tseditsw;                                   //~5903R~//~vaf9R~
    int lfnsw=0,len;                                               //~v183R~
    int     expandlen;	//filename field width expand              //~v59TI~
//  UCHAR   fnm[8+1+3];                                            //~v0f0R~
    UCHAR   fnm[MAXFILENAMEZ];                                     //~v0f0I~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
//  UCHAR   fnmslink[MAXFILENAMEZ*2+5];                            //~vb7jR~
    UCHAR   fnmslink[MAXFILENAMEZ+5+MAXSLINKNMSZ];                 //~vb7jI~
#endif                                                             //~v40tI~
	UDISKINFO udiskinfo;                                           //~v09bR~
//  long clustersz,diskfreesz,disktotsz;                           //~v49hR~
#ifdef DOSDOS                                                      //~v50HI~
    long clustersz,diskfreesz,disktotsz;                           //~v50HI~
#else                                                              //~v50HI~
//  ULONG clustersz,diskfreesz[3],disktotsz[3];                    //~v56rR~
    long  clustersz,diskfreesz[3],disktotsz[3];                    //~v56rI~
#endif                                                             //~v50HI~
    UCHAR dweditnumwk[16];                                         //~v49hI~
    UCHAR edittime[8];                                             //~v53PI~
    int  efaopt;                                                   //~v40AI~
//  UCHAR   wc;                                                 //~v05IR~
#ifdef FTPSUPP                                                     //~v541I~
	char ipaddr[FTP_IPADNAMELEN+1];                                //~v541I~
    PUFTPHOST puftph;                                              //~v541I~
    FDATE fdate0;                                                  //~v717I~
    FTIME ftime0;                                                  //~v717I~
#endif                                                             //~v541I~
    char *pdesc;	//file description                             //~v690I~
    int resizesw=0;                                                //~v693I~
    int displc;                                                    //~v72rR~
#ifndef UNX                                                        //~v7abI~
    UINT rcgdf;                                                    //~v7abR~
#endif                                                             //~v7abI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int splitctr;                                                  //~va1cR~
#endif                                                             //~va1cR~
	int offsslink=0,offsname,fnmwidth;                             //~vaunR~
//#ifdef LNX                                                         //~vau0I~//~vauER~
	int ddlen=0,offsrename=0,swddfmt=0;                            //~vaunR~
    int swsetrename=1,fnmddlen=0;                                  //~vaufR~
    UCHAR wkddfmtname[MAXFILENAMEZ];                               //~vau0R~
//#endif                                                             //~vau0I~//~vauER~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
    UCHAR wkudhname[UDHNAME_MAXSZ];                                //~vb2oI~
#endif                                                             //~vb2oI~
//******************
    pdh=UGETPDH(Pplh);
    pfc=Ppcw->UCWpfc;                                              //~v59TI~
    pfh=UGETPFH(Pplh);                                             //~v0fcI~
    pfld=Pppl->UPLpfld;                                         //~5813I~
    pdd=UGETPDD(Pplh);                                             //~v44jI~
    expandlen=pfc->UFCexpandlen;                                   //~v59TI~
//  pddexpand=(PUDIRLD)((ULONG)pdd+expandlen);//for pont fld after UDDname//~v59TI~//~vafkR~
//  pddexpand=(PUDIRLD)((ULPTR)pdd+expandlen);//for pont fld after UDDname//~vafkI~//~vb2pR~
    pddexpand=(PUDIRLD)((ULPTR)pdd+(ULPTR)expandlen);//for pont fld after UDDname//~vb2pI~
//#ifdef LNX                                                         //~vau0I~//~vauER~
    UCBITOFF(pdh->UDHflag4,UDHF4NOTSETDD);	//return flag          //~vau0I~
	UTRACEP("dirddsetup UDHF4NOTSETDD off,lineno=%s\n",Pplh->ULHlineno);//~vb14R~
//#endif                                                             //~vau0I~//~vauER~
//#ifdef WXE                                                       //~v621R~
////  if (Sresizesw)   //if resized setup all                      //~v621R~
//    if (UCBITCHK(pfh->UFHflag6,UFHF6RESIZE))   //if resized setup all//~v621R~
//    {                                                            //~v621R~
//        len=UDIRLDSZ+expandlen;                                  //~v621R~
//        memset(pdd->UDDlvl,0,(UINT)len);//clear to chk filename override other fld//~v621R~
//    }                                                            //~v621R~
//#endif                                                           //~v621R~
#ifdef WXEXXE                                                      //~v693I~
	if (UCBITCHK(pdh->UDHflag3,UDHF3RESIZE))	//re-setup by resize//~v693R~
    {                                                              //~v693I~
		UCBITOFF(pdh->UDHflag3,UDHF3RESIZE);	//re-setup by resize//~v693I~
        resizesw=1;                                                //~v693I~
    }                                                              //~v693I~
#endif                                                             //~v693I~
	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN1))	//attr cmd input
    {                                                           //~5813I~
        fldid=PANL310ATTR;                                      //~5807R~
        pandirprot(pfld,PANDPINP1);	//fld protect set           //~5813I~
	}                                                           //~5813I~
	else
		if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))	//rename cmd input//~5807R~
        {                                                       //~5813I~
	        fldid=PANL310RENAME;                                //~5807R~
//		    if (UCBITCHK(pdh->UDHflag,UDHFMASK)) //file mask    //~5813I~//~vawqR~
//    			pandirprot(pfld,PANDPINP3);	//fld protect set   //~5813I~//~vawqR~
//          else                                                //~5813I~//~vawqR~
				pandirprot(pfld,PANDPINP2);	//fld protect set   //~5813I~
    	  if (resizesw)                                            //~v693I~
          {                                                        //~v693I~
	    	dirsetflddata(Ppcw,Pplh,PANL310RENAME,"");   //clear on old position//~v693I~
            UCBITOFF(pdh->UDHflag2,UDHF2RENAMEOVF);  //reset ovf   //~v693I~
		  }                                                        //~v693I~
          else                                                     //~v693I~
          {                                                        //~v693I~
//          if (*pdd->UDDrsv3)	//long name                        //~v59TR~
            if (*pddexpand->UDDrsv3)	//long name                //~v59TI~
            {                                                      //~v44jI~
            	if (!UCBITCHK(pdh->UDHflag2,UDHF2RENAMEOVF))  //not previously ovf//~v44jR~
                {                                                  //~v44jI~
					UCBITOFF(pdh->UDHflag,UDHFDDSETUP);	//re-setup req//~v44jR~
            		UCBITON(pdh->UDHflag2,UDHF2RENAMEOVF);  //ovf detected//~v44jI~
//#ifdef KKK                                                       //~vb15R~
            		UCBITON(pdh->UDHflag5,UDHF5CHNGRNOVF);  //renameovf status changed//~vawmI~
//#endif                                                           //~vb15R~
//                  memset(pdd->UDDdate,0,UDDTSSZ);//once clear ts/sz//~v59TR~
#ifdef UTF8SUPPH                                                   //~va1cR~
                    splitctr=XESUB_DBCSSPLITCTR(Pplh->ULHdbcs+expandlen+UDDOFFS_RSV3+1,MAX_MBCSLENLC/*len,enough to EOL*/,0/*pos**/);//~va1cR~
//                  memset(pddexpand->UDDdate+splitctr,0,UDDTSSZ-splitctr);//once clear ts/sz//~va1cR~//~vb2pR~
                    memset(pddexpand->UDDdate+splitctr,0,(size_t)(UDDTSSZ-splitctr));//once clear ts/sz//~vb2pI~
#else                                                              //~va1cR~
                  if (*(Pplh->ULHdbcs+expandlen+UDDOFFS_RSV3)==DBCS1STCHAR)//~v743I~
                    memset(pddexpand->UDDdate+1,0,UDDTSSZ-1);//once clear ts/sz//~v743I~
                  else                                             //~v743I~
                    memset(pddexpand->UDDdate,0,UDDTSSZ);//once clear ts/sz//~v59TI~
#endif                                                             //~va1cR~
                }                                                  //~v44jI~
            }                                                      //~v44jI~
//#ifdef KKK                                                       //~vb15R~
            else                //in the fld len                   //~v44jI~
            {                                                      //~v44jI~
            	if (UCBITCHK(pdh->UDHflag2,UDHF2RENAMEOVF))  //already detected ovf//~v44jR~
                {                                                  //~v44jI~
					UCBITOFF(pdh->UDHflag,UDHFDDSETUP);	//re-setup req//~v44jI~
            		UCBITOFF(pdh->UDHflag2,UDHF2RENAMEOVF);  //reset ovf//~v44jI~
            		UCBITON(pdh->UDHflag5,UDHF5CHNGRNOVF);  //renameovf status changed//~vawmI~
                }                                                  //~v44jI~
            }                                                      //~v44jI~
//#endif                                                           //~vb15R~
          }                                                        //~v693I~
		}                                                       //~5813I~
		else
        {                                                       //~5813I~
	      if (!UCBITCHK(Pplh->ULHflag,ULHFLCMDERR))                //~v77GI~
          {                                                        //~v77GI~
	        fldid=PANL310LINENO;   		//=0,clear              //~5807R~
			pandirprot(pfld,PANDPPROT);	//fld protect set       //~5813I~
          }                                                        //~v77GI~
		}                                                       //~5813I~

    if (UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))             //~5903R~
    {                                                           //~5903I~
		if (UCBITCHK(pdh->UDHupdatetype,UDHUTDELETED))          //~5903R~
    		strcpy(Pplh->ULHlineno,"**D**");                    //~v046R~
		else                                                    //~5903I~
	    	if (UCBITCHK(pdh->UDHupdatetype,UDHUTRENAMEO))      //~5903R~
    			strcpy(Pplh->ULHlineno,"**R**");                //~v046R~
			else                                                //~5903I~
    			strcpy(Pplh->ULHlineno,"**M**");                //~v046R~
    }                                                           //~5903I~
    else                                                        //~5903I~
		if (Pplh->ULHlinenor>9999)                              //~v046R~
    		sprintf(Pplh->ULHlineno,"_%04ld|",Pplh->ULHlinenor%10000);//~v046R~
    	else                                                    //~5903R~
    		sprintf(Pplh->ULHlineno,"_%04ld|",Pplh->ULHlinenor);//~v046R~
    pfc0=pfc;	//save original                                    //~v690I~
    if (pfc=UGETQTOP(&pdh->UDHviewqh),pfc)                      //~v046I~
    	if (!UCBITCHK(pfc->UFCflag,UFCFENQEDIT))	//view cmd  //~v04jR~
        {                                                          //~v53PI~
    	if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                      //~v58jI~
	    	*Pplh->ULHlineno='W';                                  //~v58jI~
        else                                                       //~v58jI~
    	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                  //~v046R~
	    	*Pplh->ULHlineno='V';                               //~v046R~
		else                                                    //~v046I~
	    	*Pplh->ULHlineno='W';                               //~v046R~
        }//view cmd                                                //~v53PI~
    pfc=pfc0;	//restore original                                 //~v690I~
//  pdd=UGETPDD(Pplh);                                             //~v44jR~
//dir level and type                                            //~5812R~
    if ((level=pdh->UDHlevel)>UDDMAXLEVEL)	//over max          //~5812R~
		level=UDDMAXLEVEL;                                      //~5812I~
	*(pdd->UDDlvl+level)=pdh->UDHtype;                          //~5812R~
//*                                                             //~v05II~
//  switch(wc=pdh->UDHtype,wc)                                  //~v05IR~
//  {                                                           //~v05IR~
//  case UDHTDIR:    	//'+'  		//sub dir                   //~v05IR~
//  	wc='';                                                 //~v05IR~
//  	break;                                                  //~v05IR~
//  case UDHTDIREXP:    // '-'  		//expanded dir          //~v05IR~
//  	wc='';                                                 //~v05IR~
//  	break;                                                  //~v05IR~
//  case UDHTPARENT:    // ':'  		//parent dir(..)        //~v05IR~
//  	wc='';                                                 //~v05IR~
//  	break;                                                  //~v05IR~
//  case UDHTFILE:   	//'|'  		//not dir                   //~v05IR~
//  	wc='.';                                                 //~v05IR~
//  	break;                                                  //~v05IR~
//  }                                                           //~v05IR~
//  *(pdd->UDDlvl+level)=wc;                                    //~v05IR~
    if (level)                                                  //~v05II~
//  	memset(pdd->UDDlvl,'',(UINT)level);                    //~v05IR~
    	memset(pdd->UDDlvl,'|',(UINT)level);                    //~v05IR~
//*                                                             //~v05II~
//#ifdef WXE                                                       //~v621R~
//  if (!Sresizesw)   //if resized setup all;UDHFDDSETUP is resetted at dirresize//~v621R~
//#endif                                                           //~v621R~
	if (UCBITCHK(pdh->UDHflag,UDHFDDSETUP))	//already setup     //~5819I~
    {                                                              //~vau0I~
	    UTRACEP("dirddsetup UDHF4NOTSETDD on,lineno=%s\n",Pplh->ULHlineno);//~vb14R~
//#ifdef LNX                                                         //~vau0I~//~vauER~
        UCBITON(pdh->UDHflag4,UDHF4NOTSETDD);                      //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
    	return;                                                 //~5819M~
    }                                                              //~vau0I~
	UCBITON(pdh->UDHflag,UDHFDDSETUP);	//already setup         //~5819M~
//  UCBITON(pdh->UDHflag2,UDHF2SETATTR|UDHF2SETRENAME);	//default  //~v54aR~
    UCBITON(pdh->UDHflag2,UDHF2SETATTR|UDHF2SETRENAME|UDHF2SETTSSZ);	//default//~v54aI~
	UCBITOFF(pdh->UDHflag3,UDHF3SETDESC);                          //~v692I~
    if (UCBITCHK(pfh->UFHflag7,UFHF7DESC))//display description mode//~v690R~
    {                                                              //~v692M~
        pdesc=dirgetdesc(Ppcw,pfh,Pplh,pdh);                       //~v690R~
	    if (fldid==PANL310ATTR || fldid==PANL310RENAME)	//attr or rename cmd process//~v692I~
    		pdesc=0;	//no display description                   //~v692I~
    }                                                              //~v692I~
    else                                                           //~v690I~
    	pdesc=0;                                                   //~v690I~
	pddexpand->UDDattrflag=0;	//clear for resizing shift position;name overflow to attr fld?//~v693I~
    pddexpand->UDDrsv2=0;	//clear for resizing shift position;name overflow to rename fld?//~v693R~
//*******************************************                      //~v903I~//~va00I~
//file name
//*******************************************                      //~v903I~//~va00I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
    UCBITOFF(pdh->UDHflag4,UDHF4DDFMT);                            //~vau0I~
    if (!(pdh->UDHflag3 & UDHF3U8SET)) //not yet utf8name was setup//~vauHI~
    	dirsetlocalenameforpath(pfh,pdh);                          //~vauHI~
#ifdef W32                                                         //~vav6I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn               //~vav6I~
#endif                                                             //~vav6I~
  {                                                                //~vav6I~
	if (UCBITCHK(pdh->UDHflag3,(UDHF3U8UTF|UDHF3U8LC)))  //member name is dbcs or utf8                      //~vau0I~//~vau1R~
    	swddfmt=1;                                                 //~vau0I~
  }                                                                //~vav6I~
	if (UCBITCHK(pdh->UDHflag3,(UDHF3U8UTFSL|UDHF3U8LCSL))) //slink name is dbcs or utf8                     //~vau0I~//~vau1R~
    {                                                              //~vau0I~
    	if (UCBITCHK(Gdir3status,GDIR3SLFN))	//display long     //~vau0I~
	    	swddfmt=1;      //display slink                        //~vau0I~
    }                                                              //~vau0I~
	if (UCBITCHK(pdh->UDHflag4,(UDHF4RENAMEU8|UDHF4RENAMELC)))                     //~vau0I~//~vau1R~
    {                                                              //~vau0I~
    	if (!pdesc)                                                //~vau0I~
	    	swddfmt=1;      //display slink                        //~vau0I~
    }                                                              //~vau0I~
//#endif                                                             //~vau0R~//~vauER~
  if (UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn               //~v0fcR~
  {                                                                //~v0f0I~
#ifdef UTF8SUPPH                                                   //~v90dI~//~va00I~
//  if (!(pdh->UDHflag3 & UDHF3U8SET)) //not yet utf8name was setup//~v918I~//~vauHR~
//		dirsetlocalenameforpath(pdh);                                //~v918I~//~va00R~//~vagER~
//  	dirsetlocalenameforpath(pfh,pdh);                          //~vauHR~
//  #ifdef LNX                                                       //~vau0I~//~vauER~
   if (swddfmt)                                                    //~vau0R~
   {                                                               //~vau0I~
    memset(wkddfmtname,0,sizeof(wkddfmtname));                     //~vau0I~
   	if (pdh->UDHnameddfmt)                                         //~vau0R~
   	{                                                              //~vau0R~
    	ddlen=pdh->UDHnameddfmtlen;                                //~vau0R~
//  	memcpy(wkddfmtname,pdh->UDHnameddfmt,ddlen);               //~vau0R~//~vb2pR~
    	memcpy(wkddfmtname,pdh->UDHnameddfmt,(size_t)ddlen);       //~vb2pI~
    }                                                              //~vau0I~
    else                                                           //~vau0I~
   	{                                                              //~vau0I~
//  	ddlen=strlen(pdh->UDHname);                                //~vau0I~//~vb2pR~
    	ddlen=(int)strlen(pdh->UDHname);                           //~vb2pI~
//  	memcpy(wkddfmtname,pdh->UDHname,ddlen);                    //~vau0I~//~vb2pR~
    	memcpy(wkddfmtname,pdh->UDHname,(size_t)ddlen);            //~vb2pI~
    }                                                              //~vau0I~
    pc0=wkddfmtname;                                               //~vau0R~
    fnmddlen=ddlen;                                                //~vaufI~
   }                                                               //~vau0R~
   else                                                            //~vau0R~
//  #endif                                                           //~vau0M~//~vauER~
   {                                                               //~vaunI~
  	pc0=PDH_UDHname(pdh);	//by locale code                       //~va00R~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
    UstrncpyZ(wkudhname,pc0,sizeof(wkudhname));                    //~vb2oI~
    pc0=wkudhname;                                                 //~vb2oI~
#endif                                                             //~vb2oI~
   }                                                               //~vaunI~
#else                                                              //~va00I~
  	pc0=pdh->UDHname;                                              //~v0fcR~
#endif                                                             //~v918I~//~va00M~
    if (UCBITCHK(Gdir3status,GDIR3SLFN))	//display long         //~v182I~
    {                                                              //~v183I~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
		if (pdh->UDHslink)		//slink defined                    //~v40tR~
    	{                                                          //~v40tR~
//  #ifdef LNX                                                       //~vau0I~//~vauER~
          memset(fnmslink,0,sizeof(fnmslink));    //later, use not strncpy but memcmp//~vau0R~
   		  if (swddfmt)                                             //~vau0R~
    		len=ddlen;                                             //~vau0I~
          else                                                     //~vau0I~
//  #endif                                                           //~vau0I~//~vauER~
//  		len=strlen(pc0);                                       //~v40tR~//~vb2pR~
    		len=(int)strlen(pc0);                                  //~vb2pI~
    		memcpy(fnmslink,pc0,(UINT)len);                        //~v40tR~
          if (XEDIR_PDHSLINKERR(pdh))                              //~vaizI~
    		memcpy(fnmslink+len," ->" DIRL_SLINKIDERR,4);          //~vaizI~
          else                                                     //~vaizI~
    		memcpy(fnmslink+len," -> ",4);                         //~v40tR~
            offsslink=len+4;   //offset in UDHname                 //~vau0I~
//  #ifdef LNX                                                       //~vaunM~//~vauER~
          if (swddfmt)                                             //~vau0R~
          {                                                        //~vau0R~
            int ddlenslink;                                        //~vau0M~
          	if (pdh->UDHslinkddfmt)                                //~vau0I~
            {                                                      //~vau0I~
            	ddlenslink=pdh->UDHslinkddfmtlen;                  //~vau0R~
            	ddlenslink=min(ddlenslink,(int)sizeof(fnmslink)-len-4); //~vau0R~//~vauER~
    	        memcpy(fnmslink+offsslink,pdh->UDHslinkddfmt,(UINT)ddlenslink);//~vau0I~
            }                                                      //~vau0I~
            else                                                   //~vau0I~
            {                                                      //~vau0I~
//          	ddlenslink=strlen(pdh->UDHslink);                  //~vau0I~//~vb2pR~
            	ddlenslink=(int)strlen(pdh->UDHslink);             //~vb2pR~
            	ddlenslink=min(ddlenslink,(int)sizeof(fnmslink)-len-4); //~vau0I~//~vauER~
	            memcpy(fnmslink+offsslink,pdh->UDHslink,(UINT)ddlenslink);//~vau0I~
            }                                                      //~vau0I~
    		fnmddlen=offsslink+ddlenslink;                         //~vaufI~
          }                                                        //~vau0R~
          else                                                     //~vau0I~
//  #endif                                                           //~vau0I~//~vauER~
//  		strncpy(fnmslink+len+4,pdh->UDHslink,(UINT)(sizeof(fnmslink)-len-4));//~v40tR~//~vb2pR~
    		strncpy(fnmslink+len+4,pdh->UDHslink,(size_t)((int)sizeof(fnmslink)-len-4));//~vb2pI~
        	pc0=fnmslink;                                          //~v40tR~
    	}                                                          //~v40tR~
#endif                                                             //~v40tM~
        if (fldid==PANL310ATTR)                                    //~v183I~
	    	len=sizeof(pdd->UDDname);                              //~v183I~
        else                                                       //~v183I~
	    if (fldid==PANL310RENAME                                   //~v183R~
//      ||	pdh->UDHrenamesv                                       //~v40dR~
//  	||  UCBITCHK(pdh->UDHflag,UDHFPRINTED))	//data on rename fld//~v40dR~
        )                                                          //~v40dI~
        {                                                          //~v690I~
        	len=UDDLFNSZ;                                          //~v183I~
//          pdesc=0;	//no edscpriction display                  //~v692R~
        }                                                          //~v690I~
        else                                                       //~v183I~
        if (pdesc)	//description display                          //~v690I~
//      	len=UDDLFNSZ;		//set description from rename field//~v692R~
	    	len=sizeof(pdd->UDDname); //do not overflow filename area//~v692I~
        else                                                       //~v690I~
//      	len=UDDLFNSZ2;                                         //~v54aR~
        	len=UDDLFNSZ3;                                         //~v54aI~
        len+=expandlen;                                            //~v59TI~
        if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                    //~v182I~
        {                                                          //~v40tI~
//  		offsname=offsetof(UDIRLD,UDDlvl)+level+2;              //~vau0I~//~vb2pR~
    		offsname=(int)offsetof(UDIRLD,UDDlvl)+level+2;         //~vb2pI~
//          fnmwidth=sizeof(pdd->UDDlvl)-level-2+len;              //~vaunR~
//          memcpy(pdd->UDDlvl+level+2,pc0,                        //~v76QR~
//                  (UINT)(sizeof(pdd->UDDlvl)-level-2+len));      //~v76QR~
//          memcpy(pdd->UDDlvl+level+2,pc0,(UINT)(sizeof(pdd->UDDlvl)-level-2+len));//~v76QI~//~vb2pR~
            memcpy(pdd->UDDlvl+level+2,pc0,(size_t)((int)sizeof(pdd->UDDlvl)-level-2+len));//~vb2pI~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
			if (pdh->UDHslink)		//slink defined                //~v40tI~
            	*(pdd->UDDlvl+level+2-1)=DIRL_SLINKID;             //~v40tI~
#endif                                                             //~v40tI~
        }                                                          //~v40tI~
        else                                                       //~v182I~
        {                                                          //~v40tI~
			offsname=offsetof(UDIRLD,UDDname);                     //~vau0I~
//          fnmwidth=len;                                          //~vaunR~
            memcpy(pdd->UDDname,pc0,(UINT)len);                    //~v40bR~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
			if (pdh->UDHslink)		//slink defined                //~v40tI~
	            *(pdd->UDDname-1)=DIRL_SLINKID;                    //~v40tI~
#endif                                                             //~v40tI~
        }                                                          //~v40tI~
        if (pdesc)	//description display                          //~v690I~
	        pddexpand->UDDattrflag=0;	//clear long filename,to display attr field//~v690R~
//#ifdef LNX                                                         //~vaufI~//~vauER~
      if (swddfmt)                                                 //~vaujR~
      {                                                            //~vaufI~
      	UTRACEP("ddfmt chk range  pdesc=%p,expandlen=%d,attrflag offs=%d,offsname=%d,fnmddlen=%d\n",pdesc,expandlen,offsetof(UDIRLD,UDDattrflag),offsname,fnmddlen);//~vaunR~
        if (!pdesc)	//description display;ts display depends rename fld length//~vaufI~
        {                                                          //~vaufI~
        	int fnmlen;                                            //~vaufI~
//          fnmlen=min(fnmddlen,fnmwidth);                         //~vaunR~
            fnmlen=fnmddlen;                                       //~vaunI~
          if (fldid!=PANL310ATTR)                                  //~vavTI~
        	if ((expandlen+(int)offsetof(UDIRLD,UDDattrflag))<(offsname+fnmlen))//~vauER~
        		lfnsw=1;	//skip attr edit                       //~vaufI~
          if (fldid!=PANL310ATTR && fldid!=PANL310RENAME)          //~vavTI~
          {                                                        //~vavTI~
        	if ((expandlen+(int)offsetof(UDIRLD,UDDrsv2))<(offsname+fnmlen))  //rename fld//~vauER~
        		swsetrename=0;	//skip attr edit                   //~vaufI~
        	if ((expandlen+(int)offsetof(UDIRLD,UDDrsv3[0]))<(offsname+fnmlen))//~vauER~
	    		UCBITOFF(pdh->UDHflag2,UDHF2SETTSSZ);//skip date edit//~vaufI~
            else                                                   //~vaufI~
        		len=UDDLFNSZ2+expandlen;      // up to ddname fld  //~vaufI~
          }                                                        //~vavTI~
        }                                                          //~vaufI~
        else                                                       //~vaufI~
        	swsetrename=0;                                         //~vaufI~
      }                                                            //~vaufI~
      else                                                         //~vaufI~
//#endif                                                             //~vaufI~//~vauER~
      {                                                            //~vaufI~
//      if (pdd->UDDattrflag)                                      //~v59TR~
        if (pddexpand->UDDattrflag)                                //~v59TI~
        	lfnsw=1;	//skip attr edit                           //~v183I~
//#ifdef LNX                                                         //~vaunI~//~vauER~
        if (pddexpand->UDDrsv2) //filename is overflow to rename fld//~vaupI~
        	swsetrename=0;                                         //~vaupI~
//#endif                                                             //~vaunI~//~vauER~
//      if (pdd->UDDrsv3[0]) //filename is expanded date field     //~v59TR~
        if (pddexpand->UDDrsv3[0]) //filename is expanded date field//~v59TI~
    		UCBITOFF(pdh->UDHflag2,UDHF2SETTSSZ);//skip date edit  //~v54aI~
        else                                                       //~v54aR~
//      	len=UDDLFNSZ2;      // fill in rename field            //~v59TR~
        	len=UDDLFNSZ2+expandlen;      // fill in rename field  //~v59TI~
      }//!ddfmt                                                    //~vaufI~
    }                                                              //~v183I~
    else                                                           //~v182I~
//**!(UCBITCHK(Gdir3status,GDIR3SLFN))	//display long *************//~vaunI~
    if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                        //~v0f0I~
    {                                                              //~v40tI~
//      memcpy(pdd->UDDlvl+level+2,pc0,                            //~v76QR~
//  			(UINT)(sizeof(pdd->UDDlvl)-level-2+sizeof(pdd->UDDname)));//~v59TR~
//  			(UINT)(sizeof(pdd->UDDlvl)-level-2+sizeof(pdd->UDDname)+expandlen));//~v76QR~
//		offsname=offsetof(UDIRLD,UDDlvl)+level+2;                  //~vau0I~//~vb2pR~
  		offsname=(int)offsetof(UDIRLD,UDDlvl)+level+2;             //~vb2pI~
//      fnmwidth=sizeof(pdd->UDDlvl)-level-2+sizeof(pdd->UDDname)+expandlen;//~vaunR~
//      memcpy(pdd->UDDlvl+level+2,pc0,(UINT)(sizeof(pdd->UDDlvl)-level-2+sizeof(pdd->UDDname)+expandlen));//~v76QI~//~vb2pR~
        memcpy(pdd->UDDlvl+level+2,pc0,(size_t)((int)sizeof(pdd->UDDlvl)-level-2+(int)sizeof(pdd->UDDname)+expandlen));//~vb2pI~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
		if (pdh->UDHslink)		//slink defined                    //~v40tI~
		    *(pdd->UDDlvl+level+2-1)=DIRL_SLINKID;                 //~v40tI~
#endif                                                             //~v40tI~
	}                                                              //~v40tI~
    else                                                           //~v0f0I~
    {                                                              //~v40tI~
		offsname=offsetof(UDIRLD,UDDname);                         //~vau0I~
//      fnmwidth=sizeof(pdd->UDDname)+expandlen;                   //~vaunR~
//      memcpy(pdd->UDDname,pc0,sizeof(pdd->UDDname));             //~v59TR~
//      memcpy(pdd->UDDname,pc0,(UINT)(sizeof(pdd->UDDname)+expandlen));//~v59YR~//~vb2pR~
        memcpy(pdd->UDDname,pc0,(size_t)((int)sizeof(pdd->UDDname)+expandlen));//~vb2pI~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
		if (pdh->UDHslink)		//slink defined                    //~v40tI~
	    	*(pdd->UDDname-1)=DIRL_SLINKID;                        //~v40tI~
#endif                                                             //~v40tI~
    }                                                              //~v40tI~
  }                                                                //~v0f0I~
  else                                                             //~v0f0I~
//**!(UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn **********************//~vaunI~
  {                                                                //~v0f0I~
  	pc0=pdh->UDHALIAS;                                             //~v0feR~
//*8.3 filename edit                                               //~v0f0I~
//  if (!(pc=strchr(pdh->UDHname,'.')))	//no extention             //~v0f0R~
    if (!(pc=strchr(pc0,'.')))	//no extention                     //~v0f0I~
    {                                                              //~vb2rI~
//      memcpy(fnm,pdh->UDHname,sizeof(fnm));                      //~v0f0R~
	    memcpy(fnm,pc0,MAXFILENAMEZ_FAT);                          //~v0f0R~
    }                                                              //~vb2rI~
    else
    {
		memset(fnm,0,sizeof(fnm));                              //~5819I~
//      memcpy(fnm,pdh->UDHname,(UINT)((ULONG)pc-(ULONG)pdh->UDHname));//~v0f0R~
//      memcpy(fnm,pc0,(UINT)((ULONG)pc-(ULONG)pc0));              //~v0f0R~//~vafkR~
        memcpy(fnm,pc0,(UINT)((ULPTR)pc-(ULPTR)pc0));              //~vafkI~
	    memcpy(fnm+9,pc+1,3);                                   //~5819R~
    }
    if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                     //~5819R~
    {                                                              //~vaunI~
        memset(pdd->UDDlvl+level+2,0,sizeof(pdd->UDDlvl)+sizeof(pdd->UDDname)+(size_t)(expandlen-level-2));//~vb40I~//~vb41R~
//      memcpy(pdd->UDDlvl+level+2,fnm,sizeof(fnm));               //~v0f0R~
        memcpy(pdd->UDDlvl+level+2,fnm,MAXFILENAMEZ_FAT-1);        //~v0f0I~
//  	offsname=offsetof(UDIRLD,UDDlvl)+level+2;                  //~vaunI~//~vb2pR~
    	offsname=(int)offsetof(UDIRLD,UDDlvl)+level+2;             //~vb2pI~
//      fnmwidth=sizeof(pdd->UDDlvl)-level-2+sizeof(pdd->UDDname)+expandlen;//~vaunR~
		if (pdh->UDHslink)		//slink defined                    //~vb2rI~
            *(pdd->UDDlvl+level+2-1)=DIRL_SLINKID;                 //~vb2rI~
    }                                                              //~vaunI~
    else                                                        //~5819I~
    {                                                              //~vaunI~
        memset(pdd->UDDname,0,sizeof(pdd->UDDname)+(size_t)expandlen);//~vb41R~
//      memcpy(pdd->UDDname,fnm,sizeof(fnm));                      //~v0f0R~
        memcpy(pdd->UDDname,fnm,MAXFILENAMEZ_FAT-1);               //~v0f0I~
        offsname=offsetof(UDIRLD,UDDname);                         //~vaunR~
//      fnmwidth=sizeof(pdd->UDDname)+expandlen;                   //~vaunR~
		if (pdh->UDHslink)		//slink defined                    //~vb2rI~
	        *(pdd->UDDname-1)=DIRL_SLINKID;                        //~vb2rI~
    }                                                              //~vaunI~
#ifdef W32                                                         //~vb2rI~
    if (UCBITCHK(Gdir3status,GDIR3SLFN))	//display long         //~v182I~//~vb2rI~
    {                                                              //~v183I~//~vb2rI~
		if (pdh->UDHslink)		//slink defined                    //~v40tR~//~vb2rI~
    	{                                                          //~v40tR~//~vb2rI~
        	memset(fnmslink,0,sizeof(fnmslink));    //later, use not strncpy but memcmp//~vau0R~//~vb2rI~
        	if (XEDIR_PDHSLINKERR(pdh))                              //~vaizI~//~vb2rI~
    			memcpy(fnmslink," ->" DIRL_SLINKIDERR,4);          //~vaizI~//~vb2rI~
        	else                                                     //~vaizI~//~vb2rI~
    			memcpy(fnmslink," -> ",4);                         //~v40tR~//~vb2rI~
            if (fldid==PANL310ATTR)                                    //~v183I~//~vb2rI~
                len=sizeof(pdd->UDDname);                              //~v183I~//~vb2rI~
            else                                                       //~v183I~//~vb2rI~
            if (fldid==PANL310RENAME                                   //~v183R~//~vb2rI~
            )                                                          //~v40dI~//~vb2rI~
            {                                                          //~v690I~//~vb2rI~
                len=UDDLFNSZ;                                          //~v183I~//~vb2rI~
            }                                                          //~v690I~//~vb2rI~
            else                                                       //~v183I~//~vb2rI~
            if (pdesc)  //description display                          //~v690I~//~vb2rI~
                len=sizeof(pdd->UDDname); //do not overflow filename area//~v692I~//~vb2rI~
            else                                                       //~v690I~//~vb2rI~
                len=UDDLFNSZ3;                                         //~v54aI~//~vb2rI~
            len+=expandlen;                                            //~v59TI~//~vb2rI~
                                                                   //~vb2rI~
        	offsslink=offsname+MAXFILENAMEZ_FAT-1+4;   //offset in UDHname                 //~vau0I~//~vb2rI~
//          UTRACED("slink for 8.3 name",pdd->UDDlvl+offsname,offsslink-offsname);//~vb40R~
//  		offsslink-=umemrspnc(pdd->UDDlvl+offsname,0,MAXFILENAMEZ_FAT-1); //space after 83 name//~vb40R~//~vb3fR~
//          UTRACEP("slink for 8.3 name offs=%d\n",offsslink);     //~vb40R~
            if (swddfmt)                                             //~vau0R~//~vb2rI~
            {                                                        //~vau0R~//~vb2rI~
                int ddlenslink;                                        //~vau0M~//~vb2rI~
                if (pdh->UDHslinkddfmt)                                //~vau0I~//~vb2rI~
                {                                                      //~vau0I~//~vb2rI~
                    ddlenslink=pdh->UDHslinkddfmtlen;                  //~vau0R~//~vb2rI~
                    ddlenslink=min(ddlenslink,(int)sizeof(fnmslink)-4); //~vau0R~//~vauER~//~vb2rI~
                    memcpy(fnmslink+4,pdh->UDHslinkddfmt,(size_t)ddlenslink);//~vau0I~//~vb2rI~
                }                                                      //~vau0I~//~vb2rI~
                else                                                   //~vau0I~//~vb2rI~
                {                                                      //~vau0I~//~vb2rI~
                    ddlenslink=(int)strlen(pdh->UDHslink);             //~vb2pR~//~vb2rI~
                    ddlenslink=min(ddlenslink,(int)sizeof(fnmslink)-4); //~vau0I~//~vauER~//~vb2rI~
                    memcpy(fnmslink+4,pdh->UDHslink,(size_t)ddlenslink);//~vau0I~//~vb2rI~
                }                                                      //~vau0I~//~vb2rI~
	    		fnmddlen=offsslink+ddlenslink;                     //~vb2rI~
            }                                                        //~vau0R~//~vb2rI~
            else                                                     //~vau0I~//~vb2rI~
    			strncpy(fnmslink+4,pdh->UDHslink,(size_t)((int)sizeof(fnmslink)-4));//~vb2pI~//~vb2rI~
    		strncpy(pdd->UDDlvl+offsslink-4,fnmslink,(size_t)(len-(MAXFILENAMEZ_FAT-1)));//~vb2pI~//~vb2rR~
            offsslink-=offsname;  //for find reverse position,pos in filename//~vb40R~
        	if (pdesc)	//description display                          //~v690I~//~vb2rI~
	        	pddexpand->UDDattrflag=0;	//clear long filename,to display attr field//~v690R~//~vb2rI~
      		if (swddfmt)                                                 //~vaujR~//~vb2rI~
      		{                                                            //~vaufI~//~vb2rI~
      			UTRACEP("ddfmt chk range  pdesc=%p,expandlen=%d,attrflag offs=%d,offsname=%d,fnmddlen=%d\n",pdesc,expandlen,offsetof(UDIRLD,UDDattrflag),offsname,fnmddlen);//~vaunR~//~vb2rI~
        		if (!pdesc)	//description display;ts display depends rename fld length//~vaufI~//~vb2rI~
        		{                                                          //~vaufI~//~vb2rI~
        			int fnmlen;                                            //~vaufI~//~vb2rI~
            		fnmlen=fnmddlen;                                       //~vaunI~//~vb2rI~
          			if (fldid!=PANL310ATTR)                                  //~vavTI~//~vb2rI~
        				if ((expandlen+(int)offsetof(UDIRLD,UDDattrflag))<(offsname+fnmlen))//~vauER~//~vb2rI~
        					lfnsw=1;	//skip attr edit                       //~vaufI~//~vb2rI~
          			if (fldid!=PANL310ATTR && fldid!=PANL310RENAME)          //~vavTI~//~vb2rI~
          			{                                                        //~vavTI~//~vb2rI~
        				if ((expandlen+(int)offsetof(UDIRLD,UDDrsv2))<(offsname+fnmlen))  //rename fld//~vauER~//~vb2rI~
        					swsetrename=0;	//skip attr edit                   //~vaufI~//~vb2rI~
        				if ((expandlen+(int)offsetof(UDIRLD,UDDrsv3[0]))<(offsname+fnmlen))//~vauER~//~vb2rI~
	    					UCBITOFF(pdh->UDHflag2,UDHF2SETTSSZ);//skip date edit//~vaufI~//~vb2rI~
            			else                                                   //~vaufI~//~vb2rI~
        					len=UDDLFNSZ2+expandlen;      // up to ddname fld  //~vaufI~//~vb2rI~
          			}                                                        //~vavTI~//~vb2rI~
        		}                                                          //~vaufI~//~vb2rI~
        		else                                                       //~vaufI~//~vb2rI~
        			swsetrename=0;                                         //~vaufI~//~vb2rI~
      		}                                                            //~vaufI~//~vb2rI~
      		else                                                         //~vaufI~//~vb2rI~
      		{                                                            //~vaufI~//~vb2rI~
        		if (pddexpand->UDDattrflag)                                //~v59TI~//~vb2rI~
        			lfnsw=1;	//skip attr edit                           //~v183I~//~vb2rI~
        		if (pddexpand->UDDrsv2) //filename is overflow to rename fld//~vaupI~//~vb2rI~
        			swsetrename=0;                                         //~vaupI~//~vb2rI~
        		if (pddexpand->UDDrsv3[0]) //filename is expanded date field//~v59TI~//~vb2rI~
    				UCBITOFF(pdh->UDHflag2,UDHF2SETTSSZ);//skip date edit  //~v54aI~//~vb2rI~
        		else                                                       //~v54aR~//~vb2rI~
        			len=UDDLFNSZ2+expandlen;      // fill in rename field  //~v59TI~//~vb2rI~
      		}//!ddfmt                                                    //~vaufI~//~vb2rI~
    	}//slink                                                          //~v40tR~//~vb2rI~
    }//display long                                                //~vb2rI~
#endif                                                             //~vb2rM~
  }//lfn or not                                                    //~v0f9R~
//file attr ************************************                   //~v690R~
//  if (fldid!=PANL310ATTR                                         //~v55sR~
//  && pdh->UDHlevel)                                              //~v55sR~
    if (pdh->UDHlevel)                                             //~v55sI~
    {                                                           //~v03zI~
  	  if (lfnsw)                                                   //~v183R~
      {                                                            //~v183I~
//#ifdef LNX                                                         //~vaufI~//~vauER~
        if (swsetrename)	//filename dose not overflow to rename fld//~vaufI~
//#else                                                              //~vaufI~//~vauER~
////      if (!pdd->UDDrsv2)                                         //~v59TR~//~vauER~
//        if (!pddexpand->UDDrsv2)                                   //~v59TI~//~vauER~
//#endif                                                             //~vaufI~//~vauER~
        	lfnsw=0;		//rename fld avail                     //~v183I~
		UCBITOFF(pdh->UDHflag2,UDHF2SETATTR);	//attr is overrided by filename//~v183I~
      }                                                            //~v183I~
      else                                                         //~v183R~
      {                                                            //~v182I~
       if (pdesc)	//description display	                       //~v692I~
       {                                                           //~v692I~
	    dirsetdescdata(Ppcw,Pplh,pdd,pddexpand,pdesc);   //clear old string//~v692R~
		UCBITOFF(pdh->UDHflag2,(UDHF2SETATTR|UDHF2SETRENAME|UDHF2SETTSSZ));	//attr,rename,timestamp is not drawed//~v692I~
		UCBITON(pdh->UDHflag3,UDHF3SETDESC);                       //~v692I~
//#ifdef LNX                                                         //~vaunI~//~vauER~
		if (UCBITCHK(pdh->UDHflag4,(UDHF4DESCU8|UDHF4DESCLC)))     //~vau1I~
	    	swddfmt=1;      //display slink                        //~vau1I~
//#endif                                                             //~vaunI~//~vauER~
       }                                                           //~v692I~
       else  //no description display                              //~v692I~
       {                                                           //~v692I~
#ifdef UNX                                                         //~v205I~
//    	pdd->UDDattrflag=0;                                        //~v59TR~
      	pddexpand->UDDattrflag=0;                                  //~v59TI~
        efaopt=(UCBITCHK(pfh->UFHflag5,UFHF5MDOS) ? UEFA_MDOS : 0);//~v40AI~
#else  //!UNX                                                      //~v205I~
//      pdd->UDDattrflag=pdd->UDDattrflag2=0;                      //~v59TR~
        pddexpand->UDDattrflag=pddexpand->UDDattrflag2=0;          //~v59TR~
        efaopt=0;                                                  //~v40AI~
#endif //!UNX                                                      //~v205I~
		if (pfh->UFHflag12 & UFHF12RWIN)                           //~vac1R~
	        efaopt|=UEFA_RWIN;                                     //~vac1I~
//    	pdd->UDDrsv2=0;                                            //~v59TR~
      	pddexpand->UDDrsv2=0;                                      //~v59TI~
                                                                   //~v205I~
//  	ueditfattr(pdh->UDHattr,pdd->UDDattr,0);                   //~v40AR~
#ifdef FTPSUPP                                                     //~v54kI~
       if (FILEISTSO(pfh))                                         //~v717I~
//      u3270getattrstr(pdh->UDHattr,pddexpand->UDDattr);          //~v72oR~
        u3270getattrstr(pdh->UDHattr,pdh->UDHgname,pddexpand->UDDattr);//~v72oI~
       else                                                        //~v717I~
	   if (pdh->UDHslink && UCBITCHK(Gdir3status,GDIR3SLFN))	//display long//~v54kI~
//  	ueditfattr(pdh->UDHslinkattr,pdd->UDDattr,efaopt);         //~v59TR~
    	ueditfattr(pdh->UDHslinkattr,pddexpand->UDDattr,efaopt);   //~v59TI~
       else                                                        //~v54kI~
#endif                                                             //~v54kI~
//  	ueditfattr(pdh->UDHattr,pdd->UDDattr,efaopt);              //~v59TR~
    	ueditfattr(pdh->UDHattr,pddexpand->UDDattr,efaopt);        //~v59TI~
       }//no description display                                   //~v692I~
      }//8.3 name or not long display                              //~v182I~
	}                                                           //~v03zI~
  if (UCBITCHK(pdh->UDHflag2,UDHF2SETTSSZ))	//default              //~v54aI~
    tseditsw=1;                                                 //~5903I~
  else                                                             //~v54aI~
    tseditsw=0;          //date/time/size                          //~v54aI~
//rename field ***********************************************     //~v690I~
  if (!pdesc)	//no description display                           //~v692I~
  {                                                                //~v692I~
	if (fldid==PANL310RENAME)       //now editting mask or rename//~5903I~
    {                                                           //~5903I~
//    	pdd->UDDrsv2=0;                                            //~v59TR~
      	pddexpand->UDDrsv2=0;                                      //~v59TI~
//  	if (!UCBITCHK(pdh->UDHflag,UDHFMASK)) //full name editting//~5903I~//~vawqR~
//        if (*pdd->UDDrsv3)	//long name                        //~v59TR~
          if (*pddexpand->UDDrsv3)	//long name                    //~v59TI~
		    tseditsw=0;                                         //~5903I~
#ifdef GGG                                                         //~vawaI~
#ifdef W32UNICODE                                                  //~vawaI~
        if (pdh->UDHrenameddfmt)	//dirsetddfmtname was done     //~vawaI~
        {                                                          //~vawaI~
        	int fldoffs;                                           //~vawaI~
			fldoffs=dirgetfldoffs(Ppcw,Pplh,PANL310RENAME);        //~vawaR~
            if (fldoffs>0)                                         //~vawaI~
				offsrename=fldoffs;                                //~vawaI~
        }                                                          //~vawaI~
#endif                                                             //~vawaI~
#endif                                                             //~vawaI~
	}                                                           //~5903I~
    else							//not now editting          //~5903I~
    {                                                           //~5903I~
  	  if (lfnsw)                                                   //~v183R~
		UCBITOFF(pdh->UDHflag2,UDHF2SETRENAME);	//rename fld overrided by long filename//~v183I~
      else                                                         //~v183I~
      {                                                            //~v183I~
//      memset(pdd->UDDrname,0,                                    //~v07eR~
//  			(UINT)(Pplh->ULHlen-offsetof(UDIRLD,UDDrname[0])));//~v07eR~
    	dirsetflddata(Ppcw,Pplh,PANL310RENAME,"");   //clear old string//~v07eR~
//     if (pdesc)	//description display                          //~v692R~
//     {                                                           //~v692R~
//  	    tseditsw=0;                                 //no timestamp edit//~v692R~
//      	dirsetflddata(Ppcw,Pplh,PANL310RENAME,pdesc);   //clear old string//~v692R~
//  		UCBITOFF(pdh->UDHflag2,UDHF2SETTSSZ);	//tell to find cmd//~v692R~
//     }                                                           //~v692R~
//     else                                                        //~v692R~
//     {                                                           //~v692R~
		if (pdh->UDHrenamesv)                                   //~5903R~
        {                                                          //~vau0I~
//  		strcpy(pdd->UDDrname,pdh->UDHrenamesv); //display saved mask//~v07eR~
#ifdef UTF8SUPPH                                                   //~va0GI~
#ifdef W32                                                         //~vb2wI~
			if (!swddfmt)                                          //~vb2wI~
            	swddfmt=strchr(pdh->UDHrenamesvbyutf8,UD_NOTLC)!=0;//~vb2wI~
#endif                                                             //~vb2wI~
//    #ifdef LNX                                                     //~vau0I~//~vauER~
    	  if (swddfmt)                                             //~vau0R~
	    	dirsetflddataDDFMT(Ppcw,Pplh,pdh,PANL310RENAME,pdh->UDHrenamesvbyutf8,&offsrename);   //clear old string//~vau0R~
          else                                                     //~vau0I~
//    #endif                                                         //~vau0I~//~vauER~
	    	dirsetflddata(Ppcw,Pplh,PANL310RENAME,pdh->UDHrenamesvbyutf8);   //clear old string//~va0GI~
#else                                                              //~va0GI~
	    	dirsetflddata(Ppcw,Pplh,PANL310RENAME,pdh->UDHrenamesv);   //clear old string//~v07eR~
#endif                                                             //~va0GI~
		}                                                          //~vau0I~
		else                                                       //~v07gI~
			if (UCBITCHK(pdh->UDHflag,UDHFPRINTED))	//undel confirm//~v07gI~
		    	dirsetflddata(Ppcw,Pplh,PANL310RENAME,"*Printed");   //clear old string//~v07gI~
                                                                   //~v07gI~
//  	if (UCBITCHK(pdh->UDHupdatetype,UDHUTMOVEO|UDHUTCOPYO)     //~v0f3R~
//  	if (UCBITCHK(pdh->UDHupdatetype,UDHUTMOVEO|UDHUTCOPYO|UDHUTRENAMEO)//~v0fgR~
//  	||  UCBITCHK(pdh->UDHflag,UDHFMASK2))	//undel confirm    //~v0fgR~
//          if (strlen(pdd->UDDrname)>sizeof(pdd->UDDrname))       //~v59TR~
            if (strlen(pdd->UDDrname+expandlen)>sizeof(pdd->UDDrname))//~v59TI~
		    tseditsw=0;                                         //~5903I~
//     }//not description display mode                             //~v692R~
      }//8.3 name or not long display                              //~v183I~
	}                                                           //~5903I~
  }//no description display                                        //~v692I~
//timestamp/size field ***********************************************//~v690I~
    if (tseditsw)                                               //~5903I~
    {                                                              //~v183I~
//    	pdd->UDDrsv3[0]=0;                                         //~v59TR~
      	pddexpand->UDDrsv3[0]=0;                                   //~v59TI~
		if (pdh->UDHlevel)                                      //~5903I~
        {                                                       //~5903I~
        	displc=0;                                              //~v72rR~
		  	if (UCBITCHK(pdh->UDHflag2,UDHF2DISPLC))    //display line count//~v72rR~
            {                                                      //~v72rR~
#ifdef FTPSUPP                                                     //~v72oI~
				if (FILEISTSO(pfh))                                //~v72vR~
                {                                                  //~v72vI~
                	if (pdh->UDHattr & FILE_SPF||Pplh->ULHlinenow) //~v72vR~
						displc=1;                                  //~v72vI~
                }                                                  //~v72vI~
                else                                               //~v72vI~
#endif                                                             //~v72rR~
					displc=1;                                      //~v72rR~
			}                                                      //~v72rR~
//size                                                          //~5903I~
                                                                   //~v20fI~
#ifdef FTPSUPP                                                     //~v55hI~
#ifdef UNX                                                         //~v20fI~
		if (UCBITCHK(Gscrstatus,GSCRSDIRUGNAME))	//UNX uid edit mode//~v20hR~
//      	dirugidedit(pdh,pdd);                                  //~v55hR~
//      	dirugidedit(pfh,pdh,pdd);                              //~v59TR~
        	dirugidedit(Ppcw,pfh,pdh,pdd);                         //~v59TI~
        else                                                       //~v20fI~
#else                                                              //~v55hI~
		if (UCBITCHK(Gscrstatus,GSCRSDIRUGNAME)	//UNX uid edit mode//~v55hI~
        &&  FILEISREMOTE(pfh))                                     //~v55hI~
//      	dirugidedit(pfh,pdh,pdd);                              //~v59TR~
        	dirugidedit(Ppcw,pfh,pdh,pdd);                         //~v59TI~
        else                                                       //~v55hI~
#endif //UNX                                                       //~v20fI~
#endif //FTPSUPP                                                   //~v55hI~
                                                                   //~v20fI~
//  	  if (UCBITCHK(pdh->UDHflag2,UDHF2DISPLC))  //display line count//~v72rR~
    	  if (displc)                               //display line count//~v72rR~
          {                                                        //~v10rI~
//      	unumedit((ULONG)Pplh->ULHlinenow,"z,zzz,zzz,zz9",pdd->UDDsize);//~v59TR~
        	unumedit((ULONG)Pplh->ULHlinenow,"z,zzz,zzz,zz9",pddexpand->UDDsize);//~v59TI~
//          *(pdd->UDDsize+1)='#';                                 //~v59TR~
            *(pddexpand->UDDsize+1)='#';                           //~v59TI~
		  }	                                                       //~v10rI~
          else                                                     //~v10rI~
#ifdef FTPSUPP                                                     //~v54eR~
		   if (pdh->UDHslink && UCBITCHK(Gdir3status,GDIR3SLFN))	//display long//~v54eR~
//          unumedit(pdh->UDHslinksize,"z,zzz,zzz,zz9",pdd->UDDsize);//~v59TR~
//          unumedit(pdh->UDHslinksize,"z,zzz,zzz,zz9",pddexpand->UDDsize);//~v731R~
            ufileeditsz(0,pdh->UDHslinksize,pddexpand->UDDsize);   //~v731R~
           else                                                    //~v54eR~
#endif                                                             //~v54eR~
//      	unumedit(pdh->UDHsize,"z,zzz,zzz,zz9",pdd->UDDsize);   //~v59TR~
//      	unumedit(pdh->UDHsize,"z,zzz,zzz,zz9",pddexpand->UDDsize);//~v731R~
        	ufileeditsz(0,pdh->UDHsize,pddexpand->UDDsize);        //~v731I~
//date/time                                                     //~5903I~
#ifdef FTPSUPP                                                     //~v54eR~
	       if (pdh->UDHslink && UCBITCHK(Gdir3status,GDIR3SLFN))	//display long//~v54eR~
           {                                                       //~v54eR~
//     	 	ufdateedit(pdh->UDHslinkdate,"YY-MM-DD",pdd->UDDdate); //~v59TR~
       	 	ufdateedit(pdh->UDHslinkdate,"YY-MM-DD",pddexpand->UDDdate);//~v59TI~
        	uftimeedit(pdh->UDHslinktime,"HH:MM",edittime);        //~v54eR~
           }                                                       //~v54eR~
           else                                                    //~v54eR~
           {                                                       //~v54eR~
#endif                                                             //~v54eR~
//     	 	ufdateedit(pdh->UDHdate,"YY-MM-DD",pdd->UDDdate);      //~v59TR~
#ifdef W32                                                         //~v7abI~
//         if (0==*(USHORT*)(ULONG)(&pdh->UDHdate))                //~v7abR~//~vafkR~
           if (0==*(USHORT*)(ULPTR)(&pdh->UDHdate))                //~vafkI~
       	 	memset(pddexpand->UDDdate,0,sizeof(pddexpand->UDDdate)+1);//~v7abR~
           else                                                    //~v7abI~
#endif                                                             //~v7abI~
       	 	ufdateedit(pdh->UDHdate,"YY-MM-DD",pddexpand->UDDdate);//~v59TI~
//      	uftimeedit(pdh->UDHtime,"HH:MM",pdd->UDDtime);         //~v53PR~
#ifdef W32                                                         //~v7abI~
//         if (0==*(USHORT*)(ULONG)(&(pdh->UDHtime)))              //~v7abR~//~vafkR~
           if (0==*(USHORT*)(ULPTR)(&(pdh->UDHtime)))              //~vafkI~
       	 	memset(edittime,0,sizeof(edittime));                   //~v7abR~
           else                                                    //~v7abI~
#endif                                                             //~v7abI~
        	uftimeedit(pdh->UDHtime,"HH:MM",edittime);             //~v53PI~
#ifdef FTPSUPP                                                     //~v54eR~
           }                                                       //~v54eR~
		   if (FILEISTSO(pfh))                                     //~v717I~
           {                                                       //~v717I~
            if (!(pdh->UDHattr & (FILE_PDSMEMB|FILE_DSNPATH)))	//not MEBMER nor DSN APTH//~v719M~
            {                                                      //~v719M~
        		sprintf(pddexpand->UDDdate,"% 7d/",(int)(pdh->UDHslinkattr>>16));//~v719R~
        		sprintf(edittime,"% 6d",(int)(pdh->UDHslinkattr &0xffff));//~v719R~
        		memcpy(edittime,edittime+1,sizeof(edittime)-1);    //~v719R~
            }                                                      //~v719M~
            else                                                   //~v719M~
            {                                                      //~v719M~
            memset(&fdate0,0,sizeof(fdate0));                      //~v717R~
            memset(&ftime0,0,sizeof(ftime0));                      //~v717R~
           	if (!memcmp(&(pdh->UDHdate),&fdate0,sizeof(fdate0)))   //~v717R~
        		memset(pddexpand->UDDdate,' ',sizeof(pdd->UDDdate));//~v719R~
           	if (!memcmp(&(pdh->UDHtime),&ftime0,sizeof(ftime0)))   //~v717R~
        		memset(edittime,' ',sizeof(edittime));             //~v717I~
            }                                                      //~v719I~
           }                                                       //~v717I~
#endif                                                             //~v54eR~
//      	memcpy(pdd->UDDtime,edittime,sizeof(pdd->UDDtime)); //dont copy last null//~v59TR~
        	memcpy(pddexpand->UDDtime,edittime,sizeof(pdd->UDDtime)); //dont copy last null//~v59TI~
        }                                                       //~5903I~
        else                    //root dir                         //~v09bI~
        {                                                          //~v7abI~
#ifdef FTPSUPP                                                     //~v541I~
          if (UCBITCHK(pfh->UFHflag6,UFHF6REMOTE))//remote file    //~v53WI~
          {                                                        //~v53WI~
//          memset(pdd->UDDdate,' ',sizeof(pdd->UDDdate));         //~v59TR~
            memset(pddexpand->UDDdate,' ',sizeof(pdd->UDDdate));   //~v59TI~
//          memset(pdd->UDDsize,' ',sizeof(pdd->UDDsize));         //~v59TR~
            memset(pddexpand->UDDsize,' ',sizeof(pdd->UDDsize));   //~v59TI~
          	uftpisremote(pdh->UDHname,&puftph);                    //~v54pR~
            if (puftph)                                            //~v541I~
            {                                                      //~v541I~
                strncpy(ipaddr,puftph->UFTPHipad,sizeof(ipaddr));  //~v541I~
//              memcpy(pdd->UDDdate,ipaddr,FTP_IPADNAMELEN);       //~v59TR~
                memcpy(pddexpand->UDDdate,ipaddr,FTP_IPADNAMELEN); //~v59TI~
            }                                                      //~v541I~
            else                                                   //~v541I~
            {                                                      //~v541I~
//              strcpy(pdd->UDDdate,"----- N/A ----");             //~v59TR~
                strcpy(pddexpand->UDDdate,"----- N/A ----");       //~v59TI~
//          	strcpy(pdd->UDDsize," ---- N/A ---");              //~v59TR~
            	strcpy(pddexpand->UDDsize," ---- N/A ---");        //~v59TI~
            }                                                      //~v541I~
          }                                                        //~v53WI~
          else                                                     //~v53WI~
          {                                                        //~v53WI~
#endif                                                             //~v541I~
#ifdef UNX                                                         //~v19wI~
            if (!ugetdiskfree(pdh->UDHname,&udiskinfo))            //~v19wI~
#else                                                              //~v19wI~
//  		if (!ugetdiskfree(*pdh->UDHname,&udiskinfo))           //~v7abI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
          if (WIN_ISREMOTEPATH(pdh->UDHname))                      //~v7abR~
			rcgdf=ugetdiskfree(pfh->UFHfilename,&udiskinfo);       //~v7abI~
          else                                                     //~v7abI~
#endif                                                             //~v7abI~
			rcgdf=ugetdiskfree(pdh->UDHname,&udiskinfo);           //~v7abR~
            if (!rcgdf)                                            //~v7abI~
#endif                                                             //~v19wI~
            {                                                      //~v09bI~
    		    clustersz=(long)((ULONG)udiskinfo.bytes_per_sector*(ULONG)udiskinfo.sectors_per_cluster);//~v58jR~
//  		    diskfreesz=clustersz*(long)udiskinfo.avail_clusters;//~v49hR~
#ifdef DOSDOS                                                      //~v50HI~
    		    diskfreesz=clustersz*(long)udiskinfo.avail_clusters;//~v50HI~
#else                                                              //~v50HI~
                diskfreesz[0]=0;                                   //~v49hI~
                diskfreesz[1]=(long)udiskinfo.avail_clusters;      //~v58jR~
                ucalc_dwmult(diskfreesz,clustersz);                //~v49hI~
#endif                                                             //~v50HI~
//  		    disktotsz=clustersz*(long)udiskinfo.total_clusters;//~v49hR~
#ifdef DOSDOS                                                      //~v50HI~
    		    disktotsz=clustersz*(long)udiskinfo.total_clusters;//~v50HI~
#else                                                              //~v50HI~
    		    disktotsz[0]=0;                                    //~v49hI~
    		    disktotsz[1]=(long)udiskinfo.total_clusters;       //~v58jR~
                ucalc_dwmult(disktotsz,clustersz);                 //~v49hI~
#endif                                                             //~v50HI~
//  	    	sprintf(pdd->UDDattr,"x%X",(UINT)clustersz);       //~v59TR~
    	    	sprintf(pddexpand->UDDattr,"x%X",(UINT)clustersz); //~v59TI~
//          	unumedit((ULONG)diskfreesz,"z,zzz,zzz,zz9/",pdd->UDDdate);//~v49hI~
//          	unumedit((ULONG)disktotsz,"z,zzz,zzz,zz9",pdd->UDDsize);//~v49hI~
#ifdef DOSDOS                                                      //~v50HI~
//          	unumedit((ULONG)diskfreesz,"z,zzz,zzz,zz9/",pdd->UDDdate);//~v59TR~
            	unumedit((ULONG)diskfreesz,"z,zzz,zzz,zz9/",pddexpand->UDDdate);//~v59TI~
//          	unumedit((ULONG)disktotsz,"z,zzz,zzz,zz9",pdd->UDDsize);//~v59TR~
            	unumedit((ULONG)disktotsz,"z,zzz,zzz,zz9",pddexpand->UDDsize);//~v59TI~
#else                                                              //~v50HI~
                if (disktotsz[0]) //dword size                     //~v49hI~
                {                                                  //~v49hI~
	                ucalc_dwdiv(diskfreesz,1024);                  //~v49hI~
                    diskfreesz[2]=diskfreesz[1];                   //~v49hI~
                    diskfreesz[1]=0;        //3 word data for bc_dweditnum//~v49hI~
    				bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,(long*)(void*)diskfreesz,dweditnumwk);//~v50HR~
//                  sprintf(pdd->UDDdate,"%12sK/",dweditnumwk);    //~v59TR~
                    sprintf(pddexpand->UDDdate,"%12sK/",dweditnumwk);//~v59TI~
	                ucalc_dwdiv(disktotsz,1024);                   //~v49hI~
                    disktotsz[2]=disktotsz[1];                     //~v49hI~
                    disktotsz[1]=0;        //3 word data for bc_dweditnum//~v49hI~
    				bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,(long*)(void*)disktotsz,dweditnumwk);//~v50HR~
//                  sprintf(pdd->UDDsize,"%12sK",dweditnumwk);     //~v50bR~
//                  sprintf(pdd->UDDsize,"%12s",dweditnumwk);      //~v59TR~
                    sprintf(pddexpand->UDDsize,"%12s",dweditnumwk);//~v59TI~
//                  *(pdd->UDDsize+12)='K';                        //~v59TR~
                    *(pddexpand->UDDsize+12)='K';                  //~v59TI~
                    *(pddexpand->UDDsize+13)=0;		//cear rightmost screen pos//~v693I~
                }                                                  //~v49hI~
                else                                               //~v49hI~
                {                                                  //~v49hI~
//                  unumedit((ULONG)diskfreesz[1],"z,zzz,zzz,zz9/",pdd->UDDdate);//~v59TR~
                    unumedit((ULONG)diskfreesz[1],"z,zzz,zzz,zz9/",pddexpand->UDDdate);//~v59TI~
//                  unumedit((ULONG)disktotsz[1],"z,zzz,zzz,zz9",pdd->UDDsize);//~v59TR~
                    unumedit((ULONG)disktotsz[1],"z,zzz,zzz,zz9",pddexpand->UDDsize);//~v59TI~
                }                                                  //~v49hI~
#endif                                                             //~v50HI~
            }                                                      //~v09bI~
#ifdef FTPSUPP                                                     //~v541I~
          }//local file                                            //~v53WI~
#endif                                                             //~v541I~
        }//rootdir                                                 //~v7abI~
    }                                                              //~v183I~
//dbcs tbl
#ifdef UTF8SUPPH                                                   //~va1cR~
	pdh->UDHnameoffs=offsname;                                     //~vau0R~
	pdh->UDHslinkoffs=offsslink;                                   //~vau0R~
	if (UCBITCHK(pdh->UDHflag2,UDHF2SETATTR))	//attr is overrided by filename//~vaunI~
    	fnmwidth=offsetof(UDIRLD,UDDattr)-1;                       //~vaunR~
    else                                                           //~vaunI~
	if (UCBITCHK(pdh->UDHflag2,UDHF2SETRENAME))	//rename fld overrided by long filename//~vaunI~
		fnmwidth=offsetof(UDIRLD,UDDrname[0])-1;                   //~vaunR~
    else                                                           //~vaunI~
    if (tseditsw)                                                  //~vaunI~
		fnmwidth=offsetof(UDIRLD,UDDdate)-1;                       //~vaunR~
    else                                                           //~vaunI~
		fnmwidth=UDIRLDSZ;                                         //~vaunR~
    pdh->UDHfnmwidth=fnmwidth-offsname+expandlen;                  //~vaunR~
    UTRACEP("dirddsetup fnmwidth=%d\n",pdh->UDHfnmwidth);          //~vaunR~
//#ifdef LNX                                                         //~vaunR~//~vauER~
	pdh->UDHrenameoffs=offsrename;                                 //~vau0I~
  if (swddfmt)                                                     //~vaunI~
//  pdh->UDHfnmlen=min(fnmddlen,fnmwidth);	//name (and +slink) len//~vauKR~
    pdh->UDHfnmlen=min(fnmddlen,pdh->UDHfnmwidth);	//name (and +slink) len//~vauKI~
  else                                                             //~vaunI~
//#endif                                                             //~vaunI~//~vauER~
//  pdh->UDHfnmlen=strlen(pdd->UDDlvl+offsname);                   //~vaunR~//~vb2pR~
    pdh->UDHfnmlen=(int)strlen(pdd->UDDlvl+offsname);              //~vb2pI~
  UTRACEP("dirddsetup offsname=%d,fnmlen=%d,name=%s\n",offsname,pdh->UDHfnmlen,pdh->UDHname);//~vaunR~
//  #ifdef LNX                                                       //~vaunI~//~vauER~
   if (swddfmt)                                                    //~vau0I~
   {                                                               //~vau0I~
    UCBITON(pdh->UDHflag4,UDHF4DDFMT);                             //~vau0I~
	dirsetdbcstblDDFMT(0,Ppcw,Pplh,pdh,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~vau0I~
   }                                                               //~vau0I~
   else                                                            //~vau0I~
//  #endif                                                           //~vau0I~//~vauER~
	dirsetdbcstbl(DSDTO_FULLLINE,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va1cR~
#else                                                              //~va1cR~
	setdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);
#endif                                                             //~va1cR~
    return;
}//dirddsetup

//****************************************************************
//!dirlineattr
//*setup line attr(color) for scrdisp
//*parm1:pcw
//*parm2:plh
//*parm3:psd
//*rc   :none
//****************************************************************
void dirlineattr(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd)
{
	PUFILEC pfc,pfcw;                                           //~v05wR~
	PUFILEH pfh;                                                //~v05wI~
	PUDIRLH pdh;                                                //~5819I~
	int ii,jj,width,offs,len,wordlen=0,level;                      //~v19wR~
    int width2;                                                    //~v76SI~
    int viewsw;                                                 //~v046I~
	int fnmlimit;                                                  //~v182R~
	int expandlen;                                                 //~v59TI~
    int   multifindsw;  //multiple find word on the line           //~v43gI~
	USHORT *pusoffs=0;                                             //~v19wR~
	UCHAR  uc;
	UCHAR  *pcc,*pc;
#ifdef UTF8SUPPH                                                    //~v903I~//~va00R~
	int fnmcvsw=0,fnmutf8lenc;                                     //~v90nI~//~va00R~
    char fg;                                                       //~v918I~//~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
    char bg;                                                       //~va00I~
#endif                                                             //~v903I~//~va00I~
#endif                                                             //~v903I~//~va00I~
//#ifdef LNX                                                         //~vau1R~//~vauER~
	char *pdddbcs,*pdddbcs0;                                       //~vau1R~
//#else                                                              //~vaunI~//~vauER~
//    UCHAR  *dispname;                                              //~vaunM~//~vauER~
//    int dirindentsw;                                               //~vaunM~//~vauER~
//#endif                                                             //~vau1R~//~vauER~
//#ifdef W32UNICODE                                                  //~vavaR~//~vavgR~
//    char fgsubch,bgsubch;                                          //~vavaR~//~vavgR~
//    int swsubch;                                                   //~vavaR~//~vavgR~
//#endif                                                             //~vavaR~//~vavgR~
//******************
	pfc=Ppcw->UCWpfc;
    pfh=pfc->UFCpfh;                                               //~v0feI~
	pdh=UGETPDH(Pplh);                                          //~5826I~
    pfcw=UGETQTOP(&pdh->UDHviewqh);                             //~v05wR~
    viewsw=(pfcw && !UCBITCHK(pfcw->UFCflag,UFCFENQEDIT));	//view cmd//~v05wR~
	Ppsd->USDflag=USDFCHARSTRATT;
	Ppsd->USDuvioo=0;		//no ligature/combine for all at once  //~vb4fR~
	Ppsd->USDoff=0;			//write to from leftmost column
	Ppsd->USDcell0len=0;		//no special cell data
	Ppsd->USDnattr0len=0;	//no additional attr
	Ppsd->USDnattr0off=0;
    expandlen=pfc->UFCexpandlen;                                   //~v59TI~
//*hdr/exclude line
	if (Pplh->ULHtype!=ULHTDATA)	//only lineno input avail
	{
		Ppsd->USDnattr=Scolor_lineno;
		return;
	}
//*data line
	Ppsd->USDnattr=Scolor_client;
//  if (!UCBITCHK(Pplh->ULHflag,                                //~v05eR~
//  		ULHFLCMDERR|ULHFCURFOUND|ULHFHLDIRTYPE|ULHFDIRLFLDERR)//~v05eR~
//  &&  !viewsw)	                                            //~v05eR~
//  {			//change color of only lineno fld               //~v05eR~
//  	Ppsd->USDnattr0=Scolor_lineno;                          //~v05eR~
//  	Ppsd->USDoff=Ppsd->USDnattr0len=UDHLINENOSZ;		//additional lineno color//~v05eR~
//  	return;                                                 //~v05eR~
//  }                                                           //~v05eR~
//*additional attr for dataline
//*setup cell for lineno
	if ((level=pdh->UDHlevel)>UDDMAXLEVEL)	//over max          //~v05IM~
		level=UDDMAXLEVEL;                                      //~v05IM~
                                                                //~v05IM~
	pc=Ppsd->USDdata;
	pcc=Ppsd->USDcell;

	if (UCBITCHK(Pplh->ULHflag,ULHFLCMDERR)                     //~v046R~
	||  viewsw)                                                 //~v046I~
		uc=Scolor_dlcmd_r;//reverse                             //~v05eR~
	else
		uc=Scolor_dlcmd;//normal dlcmd                          //~v05eR~
    len=UDHLINENOSZ+level;  //header len                        //~v05IR~
//  for (ii=0;ii<UDHLINENOSZ;ii++)                              //~v05IR~
    for (ii=0;ii<len;ii++)                                      //~v05II~
	{
		*pcc++=*pc++;			//copy data
		*pcc++=uc;				//normal color
		uc=Scolor_lineno;	//normal lineno                     //~5820I~
	}
//	*(pcc-1)=Scolor_lineno;	//normal color                      //~5820R~
//*data part
#ifdef UTF8SUPPH                                                   //~v90dM~//~va00I~
  if (!XEUTF8MODE()) //always strattstr(SDcell0len is not supported at xescr)//~v90dR~//~va00I~
#endif                                                             //~v90dM~//~va00I~
	if (!UCBITCHK(Pplh->ULHflag,                                //~5826R~
    		ULHFCURFOUND|ULHFHLDIRTYPE|ULHFDIRLFLDERR|ULHFLINECMD))//~v05hR~
	{
//  	Ppsd->USDcell0len=UDHLINENOSZ*2;//write data offset     //~v05IR~
// 		Ppsd->USDoff=UDHLINENOSZ;		//write data offset     //~v05IR~
		Ppsd->USDcell0len=len*2;//cell write data len           //~v05II~
     	Ppsd->USDoff=len; //cell write len and also wrtcharstratt offset//~v05IR~
		return;				//lineno by cell,data by stratt
	}
//*all by cell
    width=Ppsd->USDlen-UDHLINENOSZ-level; //befor *2 and shift back level//~v0f4R~
	Ppsd->USDlen+=Ppsd->USDlen;	//double len
//  width=Ppsd->USDlen-UDHLINENOSZ;                                //~v0f4R~
	Ppsd->USDflag=USDFCELLSTR;	//by cell data
//  Ppsd->USDuvioo=UVIOO_FORCELIGATURE|UVIOO_COMBINE;		//no ligature allow combine//~vb4fR~
    Ppsd->USDuvioo=UVIOO_COMBINE;		//dirlist entry;no ligature allow combine//~vb4fR~
    UTRACED("dirlineattr data",pc,width);                          //~vau0I~
	for (ii=0;ii<width;ii++)
	{
		*pcc++=*pc++;			//copy data
		*pcc++=Scolor_client;				//normal color
	}
//*dir type highlight                                           //~5819I~
	if (UCBITCHK(Pplh->ULHflag,ULHFHLDIRTYPE))                  //~5819I~
		*(Ppsd->USDcell+(UDHLINENOSZ+level)*2+1)=Scolor_client_r;//~5819I~
                                                                //~v05wI~
	if (UCBITCHK(Pplh->ULHflag,ULHFLINECMD)                     //~v05hR~
	&&  *Pplh->ULHlinecmd && *Pplh->ULHlinecmd!=' ')            //~v05hR~
	{                                                           //~v05hR~
	    if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                 //~v05JI~
        {                                                          //~v76SI~
			pc=Ppsd->USDcell+(UDHLINENOSZ+level+2)*2;           //~v05JI~
            width2=width-2;                                        //~v76SR~
        }                                                          //~v76SI~
    	else                                                    //~v05JI~
        {                                                          //~v76SI~
			pc=Ppsd->USDcell+(UDHLINENOSZ+UDDMAXLEVEL+2)*2;     //~v05JI~
            width2=width-2-(UDDMAXLEVEL-level);                    //~v76SR~
        }                                                          //~v76SI~
		pcc=pc+1;                                               //~v05hR~
//  	for (ii=0;ii<MAXFILENAME;ii++,pcc++)                       //~v0f5R~
//  	for (ii=0;ii<width;ii++,pcc++)                             //~v76SR~
    	for (ii=0;ii<width2;ii++,pcc++)                            //~v76SI~
		{                                                       //~v05hR~
			*pcc++=Scolor_client_r;				//normal color  //~v05hR~
		}                                                       //~v05hR~
	}                                                           //~v05hR~
//*find word
    multifindsw=0;                                                 //~v43gI~
	if (UCBITCHK(Pplh->ULHflag,ULHFCURFOUND))
	{
		if (UCBITCHK(Pplh->ULHflag2,ULHF2MFOUND))	//multiple found word//~v05wI~
		{                                                       //~v05wI~
			if (pfh->UFHmfwtbl)			//find all tbl,umalloc success//~v05wI~
            {                                                   //~v05wI~
				jj=(int)Pplh->ULHrevlen;		//word count    //~v05wI~
//  			wordlen=(int)*pfh->UFHmfwtbl;	 //word length     //~v43gR~
				multifindsw=1;                                     //~v43gI~
				pusoffs=pfh->UFHmfwtbl+Pplh->ULHrevoffs; //offset tbl start//~v05wI~
            }                                                   //~v05wI~
            else                                                //~v05wI~
            	jj=0;		//bypass reverse                    //~v05wI~
		}                                                       //~v05wI~
		else                                                    //~v05wI~
		{                                                       //~v05wI~
			jj=1;							//word count        //~v05wI~
			wordlen=(int)Pplh->ULHrevlen; 		 //word length  //~v05wI~
			pusoffs=&Pplh->ULHrevoffs; 		//offset tbl start  //~v05wI~
		}                                                       //~v05wI~
//#ifdef LNX                                                         //~vaunI~//~vauER~
//#else                                                              //~vaunI~//~vauER~
//        dirindentsw=UCBITCHK(Gopt3,GOPT3DIRLISTINDENT);            //~v0f6I~//~vauER~
//#endif                                                             //~vaunI~//~vauER~
//calc filename display end pos                                    //~v59TR~
        fnmlimit=(int)offsetof(UDIRLD,UDDattr[0]);  //file name display fldsz//~v182R~
        if (UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn         //~v0feI~
        {                                                          //~v182I~
//#ifdef LNX                                                         //~vaunI~//~vauER~
//#else                                                              //~vaunI~//~vauER~
//#ifdef UTF8SUPPH                                                   //~va00I~//~vauER~
//            dispname=PDH_UDHname(pdh);                             //~va00R~//~vauER~
//#else                                                              //~va00I~//~vauER~
//            dispname=pdh->UDHname;                                 //~v0feI~//~vauER~
//#endif                                                             //~va00I~//~vauER~
//#endif                                                             //~vaunI~//~vauER~
      		if (UCBITCHK(Gdir3status,GDIR3SLFN))	//display long //~v182I~
            {                                                      //~v54pI~
//          	fnmlimit=(int)offsetof(UDIRLD,UDDrname);	//expand file name fld//~v183R~
		      if (UCBITCHK(pdh->UDHflag2,UDHF2SETTSSZ))	//tsedit   //~v54aI~
            	fnmlimit=(int)offsetof(UDIRLD,UDDdate);	//expand file name fld//~v183I~
              else                                                 //~v54aI~
            	fnmlimit=sizeof(UDIRLD);	//expand file name to until eol//~v54aI~
            }                                                      //~v54pI~
        }                                                          //~v182I~
//#ifdef LNX                                                         //~vaunI~//~vauER~
//#else                                                              //~vaunI~//~vauER~
//        else                                                       //~v0feI~//~vauER~
//            dispname=pdh->UDHALIAS;                                //~v0feR~//~vauER~
//#endif                                                             //~vaunI~//~vauER~
        fnmlimit+=expandlen;                                       //~v59TI~
//  	for (;jj;jj--,pusoffs++)                                   //~v61sR~
    	for (;jj;jj--,pusoffs+=*(pusoffs+1)-1)	//add offset to next entry//~v61sR~
		{                                                       //~v05wI~
			if (multifindsw)                                       //~v43gI~
  				wordlen=(int)*(pusoffs+1);	//pair of offset,len   //~v43gI~
			offs=(int)*pusoffs;                                 //~v05wI~
			if (offs>=0 && offs<width)                          //~v05wI~
			{                                                   //~v05wI~
//          	if (offs<(int)offsetof(UDIRLD,UDDrname[0]))	//file name fld//~v0fjR~
//          	if (offs<(int)offsetof(UDIRLD,UDDattr[0]))	//file name fld//~v182R~
                if (offs<fnmlimit)                                 //~v182I~
                {                                               //~v05wI~
//#ifdef LNX    //always LFN, no space between base and extension    //~vauhI~//~vauER~
//#else                                                              //~vauhI~//~vauER~
//                  if (dirindentsw)                                 //~v0f6I~//~vauER~
////                  pc=pdh->UDHname+offs-level-2;                  //~v0feR~//~vauER~
//                    pc=dispname+offs-level-2;                      //~v0feI~//~vauER~
//                  else                                             //~v0f6I~//~vauER~
////                  pc=pdh->UDHname+offs-sizeof(((PUDIRLD)0)->UDDlvl);//~v0feR~//~vauER~
//                    pc=dispname+offs-sizeof(((PUDIRLD)0)->UDDlvl); //~v0feI~//~vauER~
//#endif                                                             //~vauhM~//~vauER~
					pcc=Ppsd->USDcell+(UDHLINENOSZ+offs)*2+1;   //~v05wM~
//#ifdef LNX    //always LFN, no space between base and extension    //~vauhI~//~vauER~
					for (ii=0;ii<wordlen;ii++)                     //~vauhI~
//#else                                                              //~vauhI~//~vauER~
//                    for (ii=0;ii<wordlen;pc++,ii++)             //~v05wR~//~vauER~
//#endif                                                             //~vauhI~//~vauER~
                    {                                           //~v05wI~
//                      if (offs+ii>(int)(offsetof(UDIRLD,UDDname[0])//~v182R~
//  									+sizeof(((PUDIRLD)0)->UDDname)))//hidden//~v182R~
                        if (offs+ii>=fnmlimit)                     //~v182R~
                        	break;                                 //~v0f7I~
//#ifdef LNX    //always LFN, no space between base and extension    //~vauhI~//~vauER~
//#else                                                              //~vauhI~//~vauER~
//                        if (*pc=='.')                           //~v05wR~//~vauER~
//                        if (*(pcc-1)!='.')  //not LFN=no           //~vajsI~//~vauER~
//                        {                                       //~v05wI~//~vauER~
////vajs:130818 find highlight sring length on dir list is short(if FAT ok,but NG for LFN=)//~vajsI~//~vauER~
//                            while (!*(pcc-1))   //intermediate space//~v05wR~//~vauER~
//                            {                                   //~v05wI~//~vauER~
//                                *pcc=Scolor_client_r;       //reverse color//~v05wI~//~vauER~
//                                pcc+=2;                         //~v05wI~//~vauER~
//                            }                                   //~v05wI~//~vauER~
//                            continue;                           //~v05wI~//~vauER~
//                        }                                       //~v05wI~//~vauER~
//#endif                                                             //~vauhI~//~vauER~
						*pcc=Scolor_client_r;		//reverse color//~v05wI~
						pcc+=2;                                 //~v05wI~
					}                                           //~v05wI~
                }                                               //~v05wI~
                else	//rename field                          //~v05wI~
                {                                               //~v05wI~
					pcc=Ppsd->USDcell+(UDHLINENOSZ+offs)*2+1;   //~v05wI~
					for (ii=0;ii<wordlen;ii++,pcc++)            //~v05wI~
						*pcc++=Scolor_client_r;		//reverse color//~v05wI~
				}                                               //~v05wI~
			}                                                   //~v05wI~
            else    //out of column range                          //~v09eI~
				if (*pusoffs==ULHULFOUND)                          //~v09eI~
					*(Ppsd->USDcell+UDHLINENOSZ*2-1)=Scolor_client_r;	//find id//~v09eI~
                                                                   //~v09eI~
			if (multifindsw)                                       //~v43gI~
  				pusoffs++;	//skip len;pair of offset,len          //~v43gI~
		}//multiple word                                        //~v05wI~
	}//found word
//*field err                                                    //~5826I~
	if (UCBITCHK(Pplh->ULHflag,ULHFDIRLFLDERR))                 //~5826I~
	{                                                           //~5826I~
		wordlen=dirgetfldpos(Ppcw,Pplh,pdh->UDHerrfldno,&pcc,0);//~5826I~
//  	pusoffs=&Pplh->ULHrevoffs; 	//offset tbl start,no meanengfull redundant//~v61sR~
//  	offs=(int)((ULONG)pcc-(ULONG)Pplh->ULHdata);            //~5826I~//~vafkR~
    	offs=(int)((ULPTR)pcc-(ULPTR)Pplh->ULHdata);               //~vafkI~
		if (offs>=0 && offs<width)                              //~5826I~
		{                                                       //~5826I~
			pcc=Ppsd->USDcell+(UDHLINENOSZ+offs)*2+1;           //~5826I~
			len=min(width-offs,wordlen);                        //~5826I~
			for (ii=0;ii<len;ii++,pcc++)                        //~5826I~
				*pcc++=Scolor_client_r;		//reverse color     //~5826I~
		}                                                       //~5826I~
	}//field err                                                //~5826I~
#ifdef UTF8SUPPH                                                   //~v903I~//~va00I~
	if (XEUTF8MODE())                                              //~v903I~//~va00I~
    {                                                              //~v903I~//~va00I~
//        if (Gulibutfmode & GULIBUTFENV) //env is utf8(linux locale=utf8)//~v90nR~//~va00R~
//        {                                                              //~v90nI~//~va00R~
//    //      if (pdh->UDHnamebyutf8)     //conv locale to utf8          //~v918R~//~va00R~
//            if (pdh->UDHflag3 & UDHF3U8LC)  //conv locale to utf8      //~v918I~//~va00R~
//                fnmcvsw=1;                                             //~v90nI~//~va00R~
//        }                                                              //~v90nI~//~va00R~
//        else //env is not utf8(linux locale!=utf8 or windows)          //~v90nI~//~va00R~
//        {                                                              //~v90nI~//~va00R~
//          if (UCBITCHK(pdh->UDHflag3,UDHF3U8UTF)) //originaly utf8   //~v90nI~//~va00R~
//              fnmcvsw=1;                                             //~v90nI~//~va00I~
//        }                                                              //~v90nI~//~va00R~
#ifdef W32                                                         //~vav6I~
      if (!UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn          //~vav6I~
        fnmcvsw=UCBITCHK(pdh->UDHflag3,(UDHF3U8UTFSL)); //originaly utf8//~vav6I~
      else                                                         //~vav6I~
#endif                                                             //~vav6I~
        fnmcvsw=UCBITCHK(pdh->UDHflag3,(UDHF3U8UTF|UDHF3U8UTFSL)); //originaly utf8//~va00I~
#ifdef W32UNICODE                                                  //~vavaR~
        if (fnmcvsw    //display color of converted filename       //~vavaR~
        ||  UCBITCHK(pdh->UDHflag5,(UDHF5SUBCHFNAME|UDHF5SUBCHSLINK))) //originaly utf8//~vavaR~
#else                                                              //~vavaR~
        if (fnmcvsw)    //display color of converted filename          //~v90nI~//~va00I~
#endif                                                             //~vavaR~
        {                                                              //~v90dI~//~va00I~
            if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                    //~v90dI~//~va00I~
                offs=level+2;                                          //~v90dR~//~va00I~
            else                                                       //~v90dI~//~va00I~
                offs=UDDMAXLEVEL+2;                                    //~v90dR~//~va00I~
            pc=Ppsd->USDcell+(UDHLINENOSZ+offs)*2+1;                   //~v90dR~//~va00I~
#ifdef AAA                                                         //~vauKI~
            fnmlimit=(int)offsetof(UDIRLD,UDDattr[0]);  //file name display fldsz//~v90dI~//~va00I~
            if (UCBITCHK(pfh->UFHflag4,UFHF4LFN) //display lfn         //~v90dI~//~va00I~
            &&  UCBITCHK(Gdir3status,GDIR3SLFN)  //display long        //~v90dI~//~va00I~
            &&  !UCBITCHK(pdh->UDHflag3,UDHF3SETDESC)     //no desc    //~v90dI~//~va00I~
            &&  !UCBITCHK(pdh->UDHflag2,UDHF2SETATTR))    //no attr    //~v90dR~//~va00I~
            {                                                          //~v90dI~//~va00I~
                if (UCBITCHK(pdh->UDHflag2,UDHF2SETRENAME)) //attr,rename,timestamp is not drawed//~v90dI~//~va00I~
                    fnmlimit=(int)offsetof(UDIRLD,UDDrname);    //expand file name fld//~v90dI~//~va00I~
                else                                                   //~v90dI~//~va00I~
                    if (UCBITCHK(pdh->UDHflag2,UDHF2SETTSSZ))   //tsedit//~v90dI~//~va00I~
                        fnmlimit=(int)offsetof(UDIRLD,UDDdate); //expand file name fld//~v90dI~//~va00I~
                    else                                               //~v90dI~//~va00I~
                        fnmlimit=sizeof(UDIRLD);    //expand file name to until eol//~v90dI~//~va00I~
            }                                                          //~v90dI~//~va00I~
            fnmlimit+=expandlen;                                       //~v90dI~//~va00I~
            fnmlimit-=offs;                                            //~v90dI~//~va00I~
#else                                                              //~vauKI~
			fnmlimit=pdh->UDHfnmlen;                               //~vauKI~
#endif                                                             //~vauKI~
			fg=Scolor_lineno&0x0f;                                 //~v918I~//~va00I~
//  		bg=fg<<4;                                              //~va00I~//~vb2pR~
    		bg=(char)(fg<<4);                                      //~vb2pI~
//#ifdef W32UNICODE                                                  //~vavaR~//~vavgR~
//            fgsubch=Scolor_subch&0x0f;                             //~vavaR~//~vavgR~
//            bgsubch=fgsubch<<4;                                    //~vavaR~//~vavgR~
//            swsubch=0;                                             //~vavaR~//~vavgR~
//#endif                                                             //~vavaR~//~vavgR~
//#ifdef LNX                                                         //~vau1R~//~vauER~
            fnmutf8lenc=pdh->UDHnameddfmtlen;                      //~vau1R~
            if (!fnmutf8lenc)                                      //~vauKR~
//          	fnmutf8lenc=strlen(pdh->UDHname);                  //~vauKR~//~vb2pR~
            	fnmutf8lenc=(int)strlen(pdh->UDHname);             //~vb2pI~
            pdddbcs0=pdh->UDHnameddfmt;                            //~vau1R~
            pdddbcs=pdddbcs0+fnmutf8lenc;                          //~vau1I~
            UTRACED("dirlineattr dddata",pdddbcs0,fnmutf8lenc*2);  //~vau1I~
            UTRACEP("dirlineattr fnmlimit=%d,fnmutf8lenc=%d\n",fnmlimit,fnmutf8lenc);//~vau1I~
	        UTRACED("dirlineattr sdcell",pc-1,fnmlimit*2);         //~vau1R~
//#else                                                              //~vau1R~//~vauER~
//            fnmutf8lenc=strlen(PDH_UDHname(pdh));                  //~va00R~//~vauER~
//#endif                                                             //~vau1R~//~vauER~
            for (ii=0;ii<fnmlimit;ii++,pc+=2)                      //~v918R~//~va00I~
            {                                                          //~v90dI~//~va00I~
//#ifdef LNX                                                         //~vau1R~//~vauER~
				if (pdddbcs0)                                      //~vau1I~
                {                                                  //~vau1I~
                	if (!*(pc-1) && !pdddbcs)                      //~vau1R~
                    	break;                                     //~vau1I~
	                pdddbcs++;                                     //~vau1I~
                }                                                  //~vau1I~
                else                                               //~vau1I~
//#endif                                                             //~vau1M~//~vauER~
                if (!*(pc-1))                                          //~v90dR~//~va00I~
                    break;                                             //~v90dI~//~va00I~
                if (ii<fnmutf8lenc) //before slinkname             //~va00I~
                {                                                  //~va00I~
#ifdef W32UNICODE                                                  //~vavaR~
//  			  if (!(swsubch=UCBITCHK(pdh->UDHflag5,UDHF5SUBCHFNAME))) //originaly utf8//~vavaR~//~vavgR~
				  if (!(UCBITCHK(pdh->UDHflag5,UDHF5SUBCHFNAME))) //originaly utf8//~vavgI~
#endif                                                             //~vavaR~
                    if (!(fnmcvsw & UDHF3U8UTF))                   //~va00I~
                    	continue;                                  //~va00I~
                                                                   //~vav6I~
                }                                                  //~va00I~
                else                                               //~va00I~
                if (ii>=fnmutf8lenc+4) //before slinkname          //~va00R~
                {                                                  //~va00I~
#ifdef W32UNICODE                                                  //~vavaR~
//  			  if (!(swsubch=UCBITCHK(pdh->UDHflag5,UDHF5SUBCHSLINK))) //originaly utf8//~vavaR~//~vavgR~
    			  if (!(UCBITCHK(pdh->UDHflag5,UDHF5SUBCHSLINK))) //originaly utf8//~vavgI~
#endif                                                             //~vavaR~
                    if (!(fnmcvsw & UDHF3U8UTFSL))                 //~va00I~
                    	continue;                                  //~va00I~
//#ifdef LNX                                                         //~vau1I~//~vauER~
	                if (ii==fnmutf8lenc+4)	//slink start          //~vau1I~
                    {                                              //~vau1I~
            			pdddbcs0=pdh->UDHslinkddfmt;               //~vau1I~
            			pdddbcs=pdddbcs0+pdh->UDHslinkddfmtlen;    //~vau1I~
            			UTRACED("dirlineattr slink dddata",pdddbcs0,pdh->UDHslinkddfmtlen*2);//~vau1I~
                    }                                              //~vau1I~
//#endif                                                             //~vau1I~//~vauER~
                }                                                  //~va00I~
                else   //" -> " :seperator of filename and slink name//~va00I~
                    continue;                                      //~va00I~
//#ifdef W32UNICODE                                                  //~vavaR~//~vavgR~
//             if (swsubch)                                          //~vavaR~//~vavgR~
//             {                                                     //~vavaR~//~vavgR~
//              if (*pc==Scolor_client_r)     //reverse color        //~vavaR~//~vavgR~
//                *pc=(*pc & 0x0f)|bgsubch;                //normal color//~vavaR~//~vavgR~
//              else                                                 //~vavaR~//~vavgR~
//                *pc=(*pc & 0xf0)|fgsubch;                //normal color//~vavaR~//~vavgR~
//             }                                                     //~vavaR~//~vavgR~
//             else                                                  //~vavaR~//~vavgR~
//#endif                                                             //~vavaR~//~vavgR~
             {                                                     //~vavaR~
#ifdef UTF8SUPPH //difference                                      //~va00I~
              if (*pc==Scolor_client_r)		//reverse color        //~va00I~
//  	        *pc=(*pc & 0x0f)|bg;                //normal color //~v918I~//~va00I~//~vb2pR~
    	        *pc=(UCHAR)((*pc & 0x0f)|bg);                //normal color//~vb2pI~
              else                                                 //~va00I~
#endif                                                             //~va00I~
//  	        *pc=(*pc & 0xf0)|fg;                //normal color //~v918I~//~va00I~//~vb2pR~
    	        *pc=(UCHAR)((*pc & 0xf0)|fg);                //normal color//~vb2pI~
             }                                                     //~vavaR~
            }                                                          //~v90dI~//~va00I~
            UTRACED("dirlineattr cell",Ppsd->USDcell+(UDHLINENOSZ+offs)*2,fnmlimit*2);//~vau1I~
        }                                                              //~v90dI~//~va00I~
//  	Ppsd->USDflag=USDFUTF8ATTSTR;	//by attr strong on cell data//~v903R~//~va00R~
    }                                                              //~v903I~//~va00I~
#endif                                                             //~v903I~//~va00I~
#ifdef W32                                                         //~vb3fI~
//#ifndef WXE                                                      //~vb3fR~
    pc=Ppsd->USDcell+(UDHLINENOSZ+(int)offsetof(UDIRLD,UDDattrflag)+expandlen)*2;   //UDDattrflag//~vb3fI~
    if (*pc==0)                                      //attr was set//~vb3fI~
    {                                                              //~vb3fI~
//  	if (UCBITCHK(pdh->UDHflag3,UDHF3U8LC|UDHF3U8UTF|UDHF3U8LCSL|UDHF3U8UTFSL))  //ascii may cause ligature//~vb3fR~
        if (!(*(pc+1) & 0xf0))	//! find word highlight(bg!=0)     //~vb5dI~
        	*(pc+1)=0;	//delm to uviom ligature                   //~vb3fI~
    	pc=Ppsd->USDcell+(UDHLINENOSZ+(int)offsetof(UDIRLD,UDDrsv2)+expandlen)*2;   //before rename fld//~vb3fI~
        *(pc+1)=0;	//attr fld,delm to uviom ligature              //~vb3fI~
    }                                                              //~vb3fI~
//#endif                                                           //~vb3fR~
#endif                                                             //~vb3fI~
	UTRACED("out USDCELL",Ppsd->USDcell,Ppsd->USDlen);             //~vawqI~
	return;
}//dirlineattr
#ifdef UTF8SUPPH                                                    //~v918I~//~va00R~
//**************************************************************** //~v918I~//~va00I~
//!dirlineattr                                                     //~v918I~//~va00I~
//*display rename fld byutf8                                       //~v918I~//~va00I~
//*rc   :none                                                      //~v918I~//~va00I~
//**************************************************************** //~v918I~//~va00I~
int dirlineattrrenamefld(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd,PUDIRLH Ppdh)//~va00I~
{                                                                  //~v918I~//~va00I~
	PUFILEC pfc;                                                   //~v918I~//~va00I~
	PUDIRLD pdd;                                                   //~va00I~
	PUDIRLH pdh;                                                   //~va0FI~
	int ii,pos,len;                                                //~v918R~//~va00R~
#ifdef AAA                                                         //~va0FI~
	UCHAR  *pc,*pdbcs,fg,*pcren;                                       //~v918R~//~va00R~
#else                                                              //~va0FI~
	UCHAR  *pc,*pct,bg,fg,*pcren;                                  //~va0FR~
#endif                                                             //~va0FI~
//******************                                               //~v918I~//~va00I~
    pfc=Ppcw->UCWpfc;                                              //~v918R~//~va00I~
	pdh=UGETPDH(Pplh);                                             //~va0FM~
//  pos=UDHLINENOSZ+offsetof(UDIRLD,UDDrname)+pfc->UFCexpandlen;	//expand if scr is wide//~v918I~//~va00I~//~vb2pR~
    pos=UDHLINENOSZ+(int)offsetof(UDIRLD,UDDrname)+pfc->UFCexpandlen;	//expand if scr is wide//~vb2pI~
	pcren=Ppdh->UDHrenamesv;                                       //~va00I~
	if (pcren && *pcren)	//display by rename saved              //~va00R~
    {                                                              //~va00I~
//  	if (!UCBITCHK(Ppdh->UDHflag4,UDHF4RENAMEU8))		//renamesv by utf8//~va00R~//~va0GR~
//  		return 0;                                              //~va00R~//~va0GR~
//      len=strlen(pcren);                                         //~va00I~//~vb2pR~
        len=(int)strlen(pcren);                                    //~vb2pI~
#ifdef W32                                                         //~vb44I~
        len=ufilestrlenUDstrip(0,pcren,len);	//lc rename len widthout UD char//~vb44I~
#endif                                                             //~vb44I~
    }                                                              //~va00I~
#ifdef GGG                                                         //~vawaI~
#ifdef W32UNICODE                                                  //~vawaI~
    else                                                           //~vawaI~
    if (Ppdh->UDHrenameddfmt)                                      //~vawaI~
    {                                                              //~vawaI~
	    len=Ppdh->UDHrenameddfmtlen;                               //~vawaI~
    }                                                              //~vawaI~
#endif                                                             //~vawaI~
#endif  //GGG                                                      //~vawaI~
    else	//no saved data to be printed                          //~va00I~
    {                                                              //~va00I~
    	pdd=UGETPDD(Pplh);                                         //~va00I~
        pcren=pdd->UDDrname+pfc->UFCexpandlen; //renaem fld typed data//~va00R~
//      len=strlen(pcren);                                         //~va00I~//~vb2pR~
        len=(int)strlen(pcren);                                    //~vb2pI~
#ifdef AAA                                                         //~va0FM~
		if (xeutf_islocalestr(XEUTFCVO_ENVCHK/*kbdinput conversion chk*/,pcren,len,0/*out area ptr*/,0/*utflen*/)!=XEUTFILRC_UTF8)	//no locale data under utf8env//~va00R~
    		return 0;                                              //~va00I~
#endif                                                             //~va0FM~
    }                                                              //~va00I~
	pc=Ppsd->USDcell+pos*2+1;                                      //~v918I~//~va00I~
#ifdef AAA                                                         //~va0FI~
    pdbcs=Pplh->ULHdbcs+pos-UDHLINENOSZ;                           //~va00I~
#else                                                              //~va0FI~
    pct=pdh->UDHrename_codetype;                                   //~va0FI~
#endif                                                             //~va0FI~
	UTRACED("pct",pct,len);                                        //~vawqI~
	fg=Scolor_lineno&0x0f;                                         //~v918I~//~va00I~
//  bg=fg<<4;                                                      //~va00I~//~vb2pR~
    bg=(UCHAR)(fg<<4);                                             //~vb2pI~
  if (memchr(pct,XEUTFCT_UTF8,(size_t)len))                        //~vb38I~
  {                                                                //~vb38I~
	UTRACEP("%s:codetbl indicate havving utf8\n",UTT);             //~vb38I~
#ifdef AAA                                                         //~va0FI~
    for (ii=0;ii<len;ii++,pc+=2,pdbcs++)                //~v918R~  //~va00R~
#else                                                              //~va0FI~
    for (ii=0;ii<len;ii++,pc+=2,pct++)                             //~va0FI~
#endif                                                             //~va0FI~
    {                                                              //~v918I~//~va00I~
//      if (!*(pc-1))     //unicode may have 0x00                       //~va00I~//~vb38R~
//      	break;                                                 //~va00I~//~vb38R~
//#ifdef AAA                                                         //~va0FI~//~vb38R~
//        if (*pdbcs!=DBCS2NDCHAR && UTF8ISASCII(*(pc-1)))           //~va00I~//~vb38R~
//#else                                                              //~va0FI~//~vb38R~
//        if (*pct!=XEUTFCT_UTF8)                                    //~va0FI~//~vb38R~
//#endif                                                             //~va0FI~//~vb38R~
//            continue;                                              //~va00I~//~vb38R~
          if (*pc==Scolor_client_r)		//reverse color            //~va00I~
//  	    *pc=(*pc & 0x0f)|bg;                //normal color //~v918I~//~va00I~//~vb2pR~
    	    *pc=(UCHAR)((*pc & 0x0f)|bg);                //normal color//~vb2pI~
          else                                                     //~va00I~
//          *pc=(*pc & 0xf0)|fg;                //normal color     //~v918R~//~va00I~//~vb2pR~
            *pc=(UCHAR)((*pc & 0xf0)|fg);                //normal color//~vb2pI~
    }                                                              //~v918I~//~va00I~
  }//codetbl indicate having utf8                                  //~vb38I~
	UTRACED("out USDCELL",Ppsd->USDcell,Ppsd->USDlen);             //~vawqI~
    return 1;                                                      //~v918I~//~va00I~
}//dirlineattrrenamefld                                            //~v918I~//~va00I~
//**************************************************************** //~v91gI~//~va00I~
//!dirlineattr                                                     //~v91gI~//~va00I~
//*display rename fld byutf8                                       //~v91gI~//~va00I~
//*rc   :none                                                      //~v91gI~//~va00I~
//**************************************************************** //~v91gI~//~va00I~
int dirlineattrdescfld(PUCLIENTWE Ppcw,PULINEH Pplh,PUSCRD Ppsd)   //~v91gI~//~va00I~
{                                                                  //~v91gI~//~va00I~
	PUFILEC pfc;                                                   //~v91gI~//~va00I~
	int ii,pos;                                                    //~v91gI~//~va00I~
	UCHAR  *pc,fg;                                                 //~v91gI~//~va00I~
	UCHAR *pdbcs;                                                  //~va00R~
//#ifdef LNX                                                         //~vau1I~//~vauER~
	PUDIRLH pdh;                                                   //~vau1I~
//#endif                                                             //~vau1I~//~vauER~
//******************                                               //~v91gI~//~va00I~
//#ifdef LNX                                                         //~vau1I~//~vauER~
	pdh=UGETPDH(Pplh);                                             //~vau1I~
//#endif                                                             //~vau1I~//~vauER~
    pfc=Ppcw->UCWpfc;                                              //~v91gI~//~va00I~
//  pos=UDHLINENOSZ+offsetof(UDIRLD,UDDattr)+pfc->UFCexpandlen;	//expand if scr is wide//~v91gI~//~va00I~//~vb2pR~
    pos=UDHLINENOSZ+(int)offsetof(UDIRLD,UDDattr)+pfc->UFCexpandlen;	//expand if scr is wide//~vb2pI~
	pc=Ppsd->USDcell+pos*2+1;                                      //~v91gI~//~va00I~
    pdbcs=Pplh->ULHdbcs+pos-UDHLINENOSZ;                           //~va00R~
	fg=Scolor_lineno&0x0f;                                         //~v91gI~//~va00I~
    for (ii=UDDDESCSZ;ii>0;ii--,pc+=2,pdbcs++)                             //~v91gR~//~va00R~
    {                                                              //~v91gI~//~va00I~
#ifdef UTF8SUPPH                                                   //~va1cR~
//    #ifdef LNX                                                     //~vau1I~//~vauER~
		if (UCBITCHK(pdh->UDHflag4,UDHF4DESCU8))                   //~vau1R~
        {                                                          //~vau1I~
        	if (*pdbcs)//ascii                                     //~vau1R~
//  			*pc=(*pc & 0xf0)|fg;                               //~vau1I~//~vb2pR~
    			*pc=(UCHAR)((*pc & 0xf0)|fg);                      //~vb2pI~
            else                                                   //~vau1I~
                                                                   //~vau1I~
	        	continue;                                          //~vau1R~
        }                                                          //~vau1I~
        else                                                       //~vau1I~
//    #endif                                                         //~vau1I~//~vauER~
        if (UTF8ISASCII(*(pc-1)) //ascii                           //~va1cR~
        &&  !UDBCSCHK_DBCSNOT1ST(*pdbcs)) //not part of dbcs       //~va1cR~
#else                                                              //~va1cR~
        if (*pdbcs!=DBCS2NDCHAR && UTF8ISASCII(*(pc-1)))           //~va00R~
#endif                                                             //~va1cR~
        	continue;                                              //~va00I~
//  	*pc=(*pc & 0xf0)|fg;                                       //~v91gI~//~va00I~//~vb2pR~
    	*pc=(UCHAR)((*pc & 0xf0)|fg);                              //~vb2pI~
    }                                                              //~v91gI~//~va00I~
	return 0;                                                      //~v91gI~//~va00I~
}//dirlineattrdescfld                                              //~v91gI~//~va00I~
#endif                                                             //~v918I~//~va00I~
                                                                //~5731I~
//*******************************************************       //~5731I~
//*dir get field position                                       //~5731I~
//* parm1: client work                                          //~5731I~
//* parm2: plh                                                  //~5731I~
//* parm3: fieldno in row	(start from 0)                      //~5731I~
//* parm4: out area addr                                        //~5731I~
//* parm5: out dbcs tbl area addr(option)                       //~5731I~
//* return:field len                                            //~5731I~
//*******************************************************       //~5731I~
int dirgetfldpos(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR **Pout,UCHAR **Pdbcs)//~5731I~
{                                                               //~5731I~
	UFLD    *pfl;                                               //~5731I~
//	PUDIRLH  pdh;                                                  //~vawGR~
	int len,pos;                                                //~5731I~
//************************                                      //~5731I~
	pfl=((PUPANELC)Ppcw->UCWppc)->UPCline[2].UPLpfld;//topline  //~5826R~
	if (Pfldno>=pfl->UFLctr)			//fieldno parm err      //~5731I~
		return 0;                                               //~5731I~
	len=pfl->UFLentry[Pfldno].UFLend                            //~5731I~
			-(pos=pfl->UFLentry[Pfldno].UFLstart);              //~5731I~
    if (Pfldno==PANL310RENAME)                                  //~5826R~
    {                                                           //~5826I~
//      pdh=UGETPDH(Pplh);                                         //~vawGR~
//		if (UCBITCHK(pdh->UDHflag,UDHFMASK)) //file mask        //~5826I~//~vawqR~
//			len=PANL310MASKLEN;                                 //~5826I~//~vawqR~
    }                                                           //~5826I~
	*Pout=Pplh->ULHdata+pos-UDHLINENOSZ;                        //~5806R~
    if (Pdbcs)                                                  //~5731I~
    {                                                              //~v53PI~
		if (Pplh->ULHdbcs)                                      //~5731I~
	    	*Pdbcs=Pplh->ULHdbcs+pos-UDHLINENOSZ;               //~5806R~
		else                                                    //~5731I~
	    	*Pdbcs=0;                                           //~5731I~
    }//pdbcs                                                       //~v53PI~
	return len;                                                 //~5731I~
}//dirgetfldpos                                                 //~5807R~
//*******************************************************       //~5807I~
//*dir get field data                                           //~5826R~
//* parm1: client work                                          //~5807I~
//* parm2: plh                                                  //~5807I~
//* parm3: fieldno in row	(start from 0)                      //~5807I~
//* parm4: data area  addr                                      //~5807I~
//* return:set data len(-1 iff err)                             //~5807I~
//*******************************************************       //~5807I~
int dirgetflddata(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pout)//~5807R~
{                                                               //~5807I~
    UCHAR   *pc;                                                //~v03zR~
	int len;                                                    //~v03zR~
//************************                                      //~5807I~
	if (!(dirgetfldpos(Ppcw,Pplh,Pfldno,&pc,0)))                //~v03zR~
    	return -1;				//fld no err                    //~5807I~
	pc+=strspn(pc," ");			//search non space              //~5807R~
    len=(int)strlen(pc);                                        //~v03zR~
	memcpy(Pout,pc,(UINT)len);                                  //~5807I~
	*(Pout+len)=0;                                              //~5807I~
	return len;                                                 //~5807I~
}//dirgetflddata                                                //~5807R~
                                                                //~5826I~
//*******************************************************       //~5807I~
//*dir set field data                                           //~5807I~
//* parm1: client work                                          //~5807I~
//* parm2: plh                                                  //~5807I~
//* parm3: fieldno in row	(start from 0)                      //~5807I~
//* parm4: data area  addr                                      //~5807I~
//* return:set data len(-1 if err)                              //~v05FR~
//*******************************************************       //~5807I~
int dirsetflddata(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pdata)//~5807I~
{                                                               //~5807I~
    UCHAR   *pc,*pcd;                                           //~5807I~
	int len,len2;                                               //~5807I~
#ifdef UTF8SUPPH                                                   //~va0GI~
//  char wklc[UDIRLDSZ];                                           //~va1cR~
    char wklc[UDIRLDSZ*UTF8_F2LMAXRATE];                           //~va1cR~
#endif                                                             //~va0GI~
//************************                                      //~5807I~
    if (!Pdata)   //for safety                                     //~vawnI~
        return -1;                                                 //~vawnI~
#ifdef UTF8SUPPH                                                   //~va0GI~
  	if (Pfldno==PANL310RENAME)                                     //~va0GI~
    {                                                              //~va0GI~
		dirsetflddata_f2l(0,Ppcw,Pplh,Pfldno,Pdata,wklc);          //~va0GI~
        Pdata=wklc;                                                //~va0GI~
    }                                                              //~va0GI~
#endif                                                             //~va0GI~
	if (!(len=dirgetfldpos(Ppcw,Pplh,Pfldno,&pc,&pcd)))         //~5807I~
    	return -1;				//fld no err                    //~5807I~
    if (!*Pdata)		//crear req                                //~v07eI~
    {                                                              //~v07eI~
		len2=(int)strlen(pc);    //old data                        //~v07eR~
        len=max(len,len2);                                         //~v07eR~
        memset(pc,0,(UINT)len);                                    //~v07eI~
    	memset(pcd,0,(UINT)len);			//all clear            //~v07eM~
    }                                                              //~v07eI~
    else                                                           //~v07eI~
    {                                                              //~v07eI~
		strncpy(pc,Pdata,(UINT)len);                               //~v07eR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	dirsetdbcstbl(0,pc,pcd,len);				//reset dbcstbl//~va1cR~
#else                                                              //~va1cR~
    	setdbcstbl(pc,pcd,len);				//reset dbcstbl     //~5807I~
#endif                                                             //~va1cR~
    }                                                              //~v07eI~
	UCBITON(Pplh->ULHflag,ULHFDRAW);                            //~5807I~
	len2=(int)strlen(Pdata);                                    //~5807I~
	return min(len,len2);                                       //~5807I~
}//dirsetflddata                                                //~5807I~
//*******************************************************          //~vawaI~
//*get remae fld offset                                            //~vawaI~
//*******************************************************          //~vawaI~
int dirgetfldoffs(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno)         //~vawaI~
{                                                                  //~vawaI~
    UCHAR   *pc,*pcd;                                              //~vawaI~
    int len,offs;                                                  //~vawaI~
//************************                                         //~vawaI~
	if (!(len=dirgetfldpos(Ppcw,Pplh,Pfldno,&pc,&pcd)))            //~vawaI~
    	return -1;				//fld no err                       //~vawaI~
    offs=PTRDIFF(pc,Pplh->ULHdata);                                //~vawaI~
    return offs;                                                   //~vawaI~
}//dirgetrenamefldoffs                                             //~vawaI~
//#ifdef LNX                                                                //~5826I~//~vau0R~//~vauER~
//*******************************************************          //~vau0I~
//*dir set field data by ddfmt for rename fld                                     //~vau0R~//~vavgR~
//*******************************************************          //~vau0I~
int dirsetflddataDDFMT(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,int Pfldno,char *Pdata,int *Ppoffs)//~vau0R~
{                                                                  //~vau0I~
    UCHAR   *pc,*pcd,*pdddata;                                     //~vawaR~
#ifdef GGG                                                         //~vawaI~
    UCHAR   *pdddbcs;                                              //~vawaI~
	int ddlen;                                                     //~vawaI~
#endif                                                             //~vawaI~
	int len,offs;                                            //~vau0R~//~vawaR~
    char wklc[UDIRLDSZ*UTF8_F2LMAXRATE];                           //~vau0I~
    int opt;                                                       //~vb14I~
//************************                                         //~vau0I~
    if (!Pdata)   //for safety                                     //~vawnI~
        return -1;                                                 //~vawnI~
#ifdef AAA  //always call dirsetflddata_f2l                        //~vawAR~
//#ifndef HHH                                                      //~vawnR~
#ifdef LNX                                                         //~vawnI~
  if (UCBITCHK(Ppdh->UDHflag5,UDHF5SETRENAMEDD))	//dirsavename set UDHrenam_codetype//~vawnR~
	strcpy(wklc,Ppdh->UDHrenamesv);                                //~vawnR~
  else                                                             //~vawnI~
#endif                                                             //~vawnI~
//#endif                                                           //~vawnR~
#endif //AAA                                                       //~vawAR~
//  dirsetflddata_f2l(0,Ppcw,Pplh,Pfldno,Pdata,wklc);              //~vb14R~
	opt=DSFDF2LO_ERRREP; // 0x01	//set '.' for F2L err          //~vb14I~
    dirsetflddata_f2l(opt,Ppcw,Pplh,Pfldno,Pdata,wklc);            //~vb14I~
	UTRACEP("dirsetflddataDDFMT fldno=%d\n",Pfldno);               //~vau0I~
	if (!(len=dirgetfldpos(Ppcw,Pplh,Pfldno,&pc,&pcd)))            //~vau0I~
    	return -1;				//fld no err                       //~vau0I~
    offs=PTRDIFF(pc,Pplh->ULHdata);                                //~vau0M~
    UTRACEP("dirsetflddataDDFMT offs=%d,len=%d\n",offs,len);       //~vau0I~
    pdddata=Ppdh->UDHrenameddfmt;                                  //~vau0I~
	if (UCBITCHK(Ppdh->UDHflag4,(UDHF4RENAMEU8|UDHF4RENAMELC))	//rename field is dbcs or utf8//~vau1R~
    &&  pdddata)                                                   //~vau0I~//~vau1I~
    {                                                              //~vau0I~
		memset(pc,0,(UINT)len);                                    //~vau0I~
		memset(pcd,0,(UINT)len);                                   //~vau0I~
#ifdef GGG                                                         //~vawaI~
    	ddlen=Ppdh->UDHrenameddfmtlen;                             //~vau0R~
        pdddbcs=pdddata+ddlen;                                     //~vau0I~
        len=min(ddlen,len);                                        //~vau0I~
		memcpy(pc,pdddata,len);                                    //~vau0I~
    	memcpy(pcd,pdddbcs,len);                                   //~vau0I~
#else                                                              //~vawaI~
        len=min((int)strlen(wklc),len);                            //~vawaR~
//  	memcpy(pc,wklc,len);                                       //~vawaI~//~vb2pR~
    	memcpy(pc,wklc,(size_t)len);                               //~vb2pI~
    	setdbcstbl(wklc,pcd,len);                                  //~vawaI~
#endif                                                             //~vawaI~
    }                                                              //~vau0I~
    else                                                           //~vau0I~
    {                                                              //~vau0I~
		strncpy(pc,Pdata,(UINT)len);                               //~vau0I~
//  	memset(pcd,0,len);                                         //~vau0R~//~vb2pR~
    	memset(pcd,0,(size_t)len);                                 //~vb2pI~
	}                                                              //~vau0I~
	UTRACED("dirsetflddataDDFMT dddata",pc,len);                   //~vau0R~
	UTRACED("dirsetflddataDDFMT dddbcs",pcd,len);                  //~vau0R~
	UCBITON(Pplh->ULHflag,ULHFDRAW);                               //~vau0I~
    *Ppoffs=offs;                                                  //~vau0I~
	return len;                                                    //~vau0R~
}//dirsetflddataDDFMT                                              //~vau0I~
//*******************************************************          //~vawpI~
//*dir set field data by ddfmt for rename fld for expand1          //~vawpI~
//*******************************************************          //~vawpI~
int dirsetflddataDDFMT2(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,char *Pdata)//~vawpI~
{                                                                  //~vawpI~
	PUDIRLH pdh;                                                   //~vawpI~
    UCHAR   *pc,*pcd,*pu8,*pu82,*pct;                              //~vawpR~
	int len,offs,datalen,u8len,swerr,opt,rc2,lclen;                //~vawpR~
    char wklc[UDIRLDSZ*UTF8_F2LMAXRATE];                           //~vawpI~
//************************                                         //~vawpI~
    pdh=UGETPDH(Pplh);                                             //~vawpI~
	swerr=1;                                                       //~vawpI~
    for (;;)                                                       //~vawpI~
    {                                                              //~vawpI~
	    if (!Pdata)   //for safety                                 //~vawpI~
        	break;                                                 //~vawpI~
//  	datalen=strlen(Pdata);                                     //~vawpI~//~vb2pR~
    	datalen=(int)strlen(Pdata);                                //~vb2pI~
		pu8=pdh->UDHrename_utf8;                                   //~vawpI~
    	if (!pu8||!*pu8)                                           //~vawpI~
    		break;                                                 //~vawpI~
//  	u8len=strlen(pu8);                                         //~vawpI~//~vb2pR~
    	u8len=(int)strlen(pu8);                                    //~vb2pI~
//  	if (!(pu82=umemmem(pu8,Pdata,u8len,datalen)))	//not remained//~vawpI~//~vb2pR~
    	if (!(pu82=umemmem(pu8,Pdata,(UINT)u8len,(UINT)datalen)))	//not remained//~vb2pI~
    		break;                                                 //~vawpI~
	    offs=PTRDIFF(pu82,pu8);                                    //~vawpI~
		pct=pdh->UDHrename_codetype+offs;                          //~vawpI~
    	opt=0;                                                     //~vawpI~
    	rc2=xeutf_cvlf2lbyct(opt,pu82,datalen,pct,datalen/*ctlen*/,wklc,sizeof(wklc),&lclen);//~vawpI~
	    if (rc2>=4)                                                //~vawpI~
    		break;                                                 //~vawpI~
		if (!(len=dirgetfldpos(Ppcw,Pplh,Pfldno,&pc,&pcd)))        //~vawpI~
    		break;                                                 //~vawpI~
//  	strncpy(pc,wklc,lclen);                                    //~vawpI~//~vb2pR~
    	strncpy(pc,wklc,(size_t)lclen);                            //~vb2pI~
    	dirsetdbcstbl(0,pc,pcd,lclen);				//reset dbcstbl//~vawpI~
        swerr=0;                                                   //~vawpI~
        break;                                                     //~vawpI~
    }                                                              //~vawpI~
    if (swerr)                                                     //~vawpI~
    	return dirsetflddata(Ppcw,Pplh,Pfldno,Pdata);              //~vawpI~
	UCBITON(Pplh->ULHflag,ULHFDRAW);                               //~vawpI~
    UCBITON(pdh->UDHflag,UDHFDDSETUP);  //noneed to setup, then call drawrename//~vawpI~
    return 0;                                                      //~vawpI~
}//dirsetflddataDDFMT                                              //~vawpI~
//#endif                                                             //~vau0I~//~vauER~
//*******************************************************          //~v692I~
//*set file description                                            //~v692I~
//*******************************************************          //~v692I~
int dirsetdescdata(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLD Ppdh,PUDIRLD Ppdhexpand,UCHAR *Pdata)//~v692I~
{                                                                  //~v692I~
    UCHAR   *pc;                                                   //~v692R~
//#ifdef LNX                                                         //~vau1I~//~vauER~
    PUDIRLH pdh;                                                   //~vau1I~
//#endif                                                             //~vau1I~//~vauER~
//************************                                         //~v692I~
	pc=Ppdhexpand->UDDattr;                                        //~v692R~
//#ifdef LNX                                                         //~vau1I~//~vauER~
    pdh=UGETPDH(Pplh);                                             //~vau1I~
  if (UCBITCHK(pdh->UDHflag4,UDHF4DESCU8|UDHF4DESCLC))             //~vau1R~
	memcpy(pc,Pdata,UDDDESCSZ);                                    //~vau1I~
  else                                                             //~vau1I~
//#endif                                                             //~vau1I~//~vauER~
	strncpy(pc,Pdata,UDDDESCSZ);                                   //~v692R~
    *(pc+UDDDESCSZ)=0;                                             //~v693I~
	UCBITON(Pplh->ULHflag,ULHFDRAW);                               //~v692I~
    return 0;                                                      //~v692I~
}//dirsetdescdata                                                  //~v692I~
//*******************************************************       //~5903I~
//*dir save name                                                //~5903I~
//* parm1: pdh                                                  //~5903I~
//* parm2: name                                                 //~5903I~
//* return:0 or UALLOC_FAILED                                   //~v05FR~
//*******************************************************       //~5903I~
int  dirsavename(PULINEH Pplh,UCHAR *Pname)                     //~v05FR~
{                                                               //~5903I~
	int len;                                                    //~5903I~
    PUDIRLH pdh;                                                //~5903I~
#ifdef UTF8SUPPH                                                   //~va0GI~
//  char wklc[UDIRLDSZ];                                           //~va1cR~
    char wklc[UDIRLDSZ*UTF8_F2LMAXRATE];                           //~va1cR~
#endif                                                             //~va0GI~
//************************                                      //~5903I~
    len=(int)strlen(Pname)+1;                                   //~v05FR~
    pdh=UGETPDH(Pplh);                                          //~5903R~
//#ifndef HHH                                                      //~vawnR~
    UCBITOFF(pdh->UDHflag5,UDHF5SETRENAMEDD);                      //~vawnR~
//#endif                                                           //~vawnR~
	if (pdh->UDHrenamesv)                                       //~v05FR~
    {                                                           //~v05FI~
    	ufree(pdh->UDHrenamesv);                                //~v05FI~
		pdh->UDHrenamesv=0;                                     //~v05FI~
    }                                                           //~v05FI~
#ifdef UTF8SUPPH                                                   //~va00I~
//  UCBITOFF(pdh->UDHflag4,(UDHF4RENAMEU8));                       //~va00M~//~va0GR~
    UFREECLEARIFNZ(pdh->UDHrenamesvbyutf8);                        //~va00M~
#endif                                                             //~va00I~
	if (len==1)	//clear req                                     //~v05FI~
    	return 0;                                               //~v05FR~
#ifdef UTF8SUPPH                                                   //~va0GI~
	dirsavename_byutf8(0,Pplh,Pname,wklc,sizeof(wklc),&len);       //~va0GI~
    len++;                                                         //~va0GI~
    Pname=wklc;                                                    //~va0GI~
#endif                                                             //~va0GI~
    if (!(pdh->UDHrenamesv=UALLOCM((UINT)len)))                 //~v05FR~
        return UALLOC_FAILED;                                   //~v05FR~
	memcpy(pdh->UDHrenamesv,Pname,(UINT)len);                   //~v05FR~
    UTRACED("UDHrenamesv",Pname,len);                              //~vawaI~
	return 0;                                                   //~v05FR~
}//dirsavename                                                  //~5903R~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~va00I~
//*get fldinput then translate locale string to utf8               //~va00R~
//*return input len                                                //~va00I~
//*******************************************************          //~va00I~
int dirgetflddata_l2f(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pout,int *Ppswl2f)//~va00R~
{                                                                  //~va00I~
    UCHAR *putf8,wkutf8[MAXCOLUMN*UTF8_MAXCHARSZMAX];               //~va00R~//~va50R~
	int utf8len,rclen,swl2f=0;                                     //~va00R~
    int skiplen;                                                   //~va0GI~
    char *pct;                                                //~va0FI~//~va0GR~
    PUDIRLH pdh;                                                   //~va0FI~
//************************                                         //~va00I~
	rclen=dirgetflddata(Ppcw,Pplh,Pfldno,Pout);                    //~va00R~
    if (rclen<=0)                                                  //~va00R~
    	return rclen;                                              //~va00R~
  if (Pfldno==PANL310RENAME)                                       //~va0FI~
  {                                                                //~va0FI~
    pdh=UGETPDH(Pplh);                                             //~va0FI~
    putf8=pdh->UDHrename_utf8;                                     //~va0FI~//~va0GR~
//  skiplen=strspn(putf8," ");                                     //~va0FI~//~vb2pR~
    skiplen=(int)strspn(putf8," ");                                //~vb2pR~
    putf8+=skiplen;                                                //~va0FI~
    pct=pdh->UDHrename_codetype+skiplen;                           //~va0FI~
//  swl2f=memchr(pct,XEUTFCT_UTF8,rclen-skiplen)!=0;                  //~va0FI~//~va0GR~//~vb2pR~
    swl2f=memchr(pct,XEUTFCT_UTF8,(size_t)(rclen-skiplen))!=0;     //~vb2pI~
#ifdef W32UNICODE                                                  //~vaw9M~
   if (swl2f && Popt & DGFDL2FO_UD)  //utf8 code found,output by UD str//~vaw9R~
   {                                                               //~vaw9I~
    	char wkud[_MAX_PATH];                                      //~vaw9M~
        int udlen;                                                 //~vaw9M~
        //*****************                                        //~vaw9M~
  	    if (ufilecvU8CT2UD(UFCVO_ENCUTF8WC,putf8,pct,rclen,wkud,sizeof(wkud),&udlen)==1)//enclosed by UD//~vaw9I~
        {                                                          //~vaw9M~
        	rclen=udlen;                                           //~vaw9M~
		    UmemcpyZ(Pout,wkud,udlen);                             //~vaw9M~
        }                                                          //~vaw9M~
        else                                                       //~vaw9M~
        {                                                          //~vaw9I~
		    rclen=strlen(putf8);                                   //~vaw9I~
		  	UmemcpyZ(Pout,putf8,rclen);                            //~vaw9I~
        }                                                          //~vaw9I~
   }                                                               //~vaw9I~
   else                                                            //~vaw9I~
#endif                                                             //~vaw9M~
   {                                                               //~vaw9I~
//  rclen=strlen(putf8);                                           //~va0GI~//~vb2pR~
    rclen=(int)strlen(putf8);                                      //~vb2pI~
//  UmemcpyZ(Pout,putf8,rclen);                                    //~va0GR~//~vb2pR~
    UmemcpyZ(Pout,putf8,(size_t)rclen);                            //~vb2pI~
   }                                                               //~vaw9I~
  }                                                                //~va0FI~
  else                                                             //~va0FI~
  {                                                                //~va0FI~
	putf8=wkutf8;                                                  //~va00R~
    if (xeutf_islocalestr(XEUTFCVO_ENVCHK|XEUTFCVO_OUTPARM/*cv if env is UTF8*,output to parm area*/,//~va00I~
//  						Pout,strlen(Pout),&putf8,&utf8len)==XEUTFILRC_UTF8)    //no locale data under utf8env//~va00R~//~vb2pR~
    						Pout,(int)strlen(Pout),&putf8,&utf8len)==XEUTFILRC_UTF8)    //no locale data under utf8env//~vb2pI~
    {                                                              //~va00I~
//      UmemcpyZ(Pout,wkutf8,utf8len);                             //~va00R~//~vb2pR~
        UmemcpyZ(Pout,wkutf8,(size_t)utf8len);                     //~vb2pI~
        swl2f=1;                                                   //~va00I~
        rclen=utf8len;                                             //~va00I~
    }                                                              //~va00I~
  }                                                                //~va0FI~
    if (Ppswl2f)                                                   //~va00I~
        *Ppswl2f=swl2f;                                            //~va00I~
	return rclen;                                                  //~va00R~
}//dirgetflddata_l2f                                               //~va00R~
//*******************************************************          //~va00I~
//*dir set field data (convert utf8 to locale code) for rename fld //~va00I~//~vawaR~
//*rc:of dirsetflddata                                             //~va00I~
//*******************************************************          //~va00I~
//int dirsetflddata_f2l(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pdata)//~va00R~//~va0GR~
int dirsetflddata_f2l(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno,UCHAR *Pdata,UCHAR *Pdatalc)//~va0GR~
{                                                                  //~va00I~
    PUDIRLH pdh;                                                   //~va0GI~
//  char *plc,wklc[MAXCOLUMN];                                     //~va00I~//~va0GR~
//  int lclen,rc;                                                  //~va00R~//~va0GR~
    char *putf8,*pct;                                              //~va0GR~
    int opt,outlen,utf8len;                                        //~va0GI~
//#ifdef LNX                                                         //~vau1R~//~vauER~
	int rc2;                                                       //~vau0R~
//#endif                                                             //~vau0I~//~vauER~
#ifdef W32UNICODE                                                  //~vawaI~
	int swudfmt;                                                   //~vawaI~
#endif                                                             //~vawaI~
//************************                                         //~va00I~
    if (!Pdata)                                                    //~vawnI~
        return -1;                                                 //~vawnI~
//  plc=wklc;                                                      //~va00I~//~va0GR~
//if (Pfldno==PANL310RENAME)                                       //~va0GR~
//{                                                                //~va0GR~
  	pdh=UGETPDH(Pplh);                                             //~va0GI~
    opt=XEUTFGLSMO_STRZ|XEUTFGLSMO_KEEPLC;  //output lc to utf8 string//~va0GR~
    putf8=pdh->UDHrename_utf8;                                     //~va0GI~
    pct=pdh->UDHrename_codetype;                                   //~va0GI~
//#ifdef HHH                                                       //~vawnR~
//#ifdef LNX                                                       //~vawnR~
//   if (!UCBITCHK(pdh->UDHflag5,UDHF5SETRENAMEDD))   //dirsavename set UDHrenam_codetype//~vawnR~
//#endif                                                           //~vawnR~
//#endif                                                           //~vawnR~
   {                                                               //~vawnI~
    memset(pct,0,UDHRENAME_CODETYPESZ);                            //~va0GI~
    memset(putf8,0,UDHRENAME_UTF8SZ);                              //~va0GI~
   }                                                               //~vawnI~
//#ifdef LNX                                                         //~vau1R~//~vauER~
//#ifndef HHH                                                      //~vawnR~
#ifdef LNX                                                         //~vawnI~
   if (!UCBITCHK(pdh->UDHflag5,UDHF5SETRENAMEDD))	//dirsavename set UDHrenam_codetype//~vawnI~
#endif                                                             //~vawnI~
//#endif                                                           //~vawnR~
    UCBITOFF(pdh->UDHflag4,UDHF4RENAMEU8|UDHF4RENAMELC);                         //~vau0I~//~vau1R~
//#endif                                                             //~vau0I~//~vauER~
    if (*Pdata)                                                    //~va0GI~
    {                                                              //~vau0I~
//#ifdef LNX                                                       //~vawnR~
//#ifdef HHH                                                       //~vawnR~
//      if (UCBITCHK(pdh->UDHflag5,UDHF5SETRENAMEDD)) //dirsavename set UDHrenam_codetype//~vawnR~
//      {                                                          //~vawnR~
//        utf8len=strlen(putf8);                                   //~vawnR~
//        rc2=dirsetddfmtname_renamesv(0,Pplh,putf8,utf8len,pct,Pdatalc);//~vawnR~
//      }                                                          //~vawnR~
//      else                                                       //~vawnR~
//#endif                                                           //~vawnR~
//#endif                                                           //~vawnR~
      {                                                            //~vawnI~
      	opt|=dirgetmixstropt(0,Pplh,Pdata);                        //~vawpI~
      	opt|=XEUTFGLSMO_ALLOWF2LOUTOVF;		//not f2lerr when output overflow//~vawBI~
//#ifdef LNX                                                         //~vau1R~//~vauER~
      rc2=	                                                       //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
//		xeutf_getmixedstr(opt,Pdata,strlen(Pdata),Pdatalc,0/*dbcs*/,pct,UDHRENAME_CODETYPESZ,&outlen,//~va0GR~//~vb2pR~
  		xeutf_getmixedstr(opt,Pdata,(int)strlen(Pdata),Pdatalc,0/*dbcs*/,pct,UDHRENAME_CODETYPESZ,&outlen,//~vb2pI~
                        putf8,UDHRENAME_UTF8SZ,&utf8len);          //~va0GR~
        UTRACED("dirsetflddata_f2l xeutf_getmixedstr utf8",putf8,utf8len);//~vau0I~
//#ifdef LNX                                                         //~vau1R~//~vauER~
        UTRACEP("dirsetflddata_f2l xeutf_getmixedstr rc=%d\n",rc2);//~vaunM~
        opt=0;                                                     //~vau0I~
        if (rc2 & XEUTFGU8MRC_UTF8)  //not all ascii               //~vau0I~
        {                                                          //~vau0I~
//FIXME test on linux utf8 in rename fld  FIXED                         //~vavgI~//~vawaR~
#ifdef W32UNICODE                                                  //~vavgI~
            swudfmt=0;                                             //~vawaR~
			if (memchr(Pdatalc,UD_NOTLC,outlen))	//drop space from ct of UD str//~vavgI~
            {                                                      //~vawaI~
            	fsubw_stripUDCT(0,Pdatalc,outlen,Pdatalc,outlen,pct,outlen,&outlen);//~vavgI~
                swudfmt=1;                                         //~vawaI~
            }                                                      //~vawaI~
#endif                                                             //~vavgI~
            UCBITON(pdh->UDHflag4,UDHF4RENAMEU8);   //draw by ddfmt//~vau0I~
            opt=DSDFO_RENAME;                                      //~vau0I~
            dirsetddfmtname(opt,pdh,putf8,utf8len);	//set UDHrenameddfmt//~vau0I~
#ifdef W32UNICODE                                                  //~vawaI~
			if (swudfmt)                //strip from rename_utf8   //~vawaR~
            {                                                      //~vawaI~
            	int u8len=strlen(putf8);                           //~vawaI~
            	fsubw_stripUDCT(0,putf8,u8len,putf8,u8len,NULL/*outct*/,0/*outctsz*/,&u8len);//~vawaR~
            }                                                      //~vawaI~
            UTRACED("UDHrename_utf8",putf8,utf8len);               //~vawaI~
            UTRACED("UDHrename_codetype",pct,outlen);              //~vawaI~
#endif                                                             //~vawaI~
        }                                                          //~vau0I~
        else                                                       //~vau0I~
        if (rc2 & XEUTFGU8MRC_LC)    //not all ascii               //~vau0I~
        {                                                          //~vau0I~
            UCBITON(pdh->UDHflag4,UDHF4RENAMELC);   //draw by ddfmt//~vau1I~
            opt=DSDFO_RENAME|DSDFO_L2DD;                           //~vau0M~
    		if (Popt & DSFDF2LO_ERRREP)	// 0x01	//set '.' for F2L err//~vb14I~
	            opt|=DSDFO_ERRREP;	//             0x40   //rep by '.' when l2f err//~vb14I~
            dirsetddfmtname(opt,pdh,Pdatalc,outlen);	//set UDHrenameddfmt//~vau0I~
        }                                                          //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
      }//NOT SETRENAMEDD                                           //~vawnI~
    }                                                              //~vau0I~
    else                                                           //~va0GI~
    {                                                              //~va0GI~
        *Pdatalc=0;                                                //~va0GI~
        utf8len=0;                                                 //~va0GI~
#ifdef LNX                                                         //~vawnI~
//#ifdef HHH                                                       //~vawnR~
//        pdh->UDHrenameddfmtlen=0;                                //~vawnR~
//#endif                                                           //~vawnR~
#else                                                              //~vawnI~
        pdh->UDHrenameddfmtlen=0;                                  //~vawaI~
#endif                                                             //~vawnI~
    }                                                              //~va0GI~
//}                                                                //~va0GR~
//  else                                                           //~va0GR~
//  {                                                              //~va0GR~
//    rc=xeutf_cvdata(XEUTFCVO_CPLC|XEUTFCVO_RETALLASCII|XEUTFCVO_OUTPARM,//~va00I~//~va0GR~
//                        Pdata,strlen(Pdata),&plc,&lclen);          //~va00I~//~va0GR~
//    if (rc==XEUTFCVRC_ALLASCII)                                    //~va00I~//~va0GR~
//        plc=Pdata;                                                 //~va00I~//~va0GR~
//    else                                                           //~va00I~//~va0GR~
//        *(plc+lclen)=0;                                            //~va00I~//~va0GR~
//  }                                                              //~va0GR~
//    return dirsetflddata(Ppcw,Pplh,Pfldno,plc);                    //~va00I~//~va0GR~
    return utf8len;                                                //~va0GI~
}//dirsetflddata_f2l                                               //~va00R~
//*******************************************************          //~va00I~
//*save utf8 string input on rename fld                            //~va00I~
//* return:0:no conv to utf8,1:conv to utf8,UALLOC_FAILED          //~va00R~
//*******************************************************          //~va00I~
//int dirsavename_byutf8(int Popt,PULINEH Pplh,UCHAR *Pplc/*0*/,UCHAR *Pputf8)//~va00R~//~va0GR~
int dirsavename_byutf8(int Popt,PULINEH Pplh,UCHAR *Pputf8,UCHAR *Pplc,int Pplcbuffsz,int *Ppplclen)//~va0GI~
{                                                                  //~va00I~
    PUDIRLH pdh;                                                   //~va00I~
    char *putf8/*,*plc*/;                                              //~va00R~//~vaa7R~
	int lclen,utf8len;                                          //~va00R~//~va0GR~
    int opt;                                                       //~va0FI~
//************************                                         //~va00I~
//  plc=Pplc;                                                      //~va00I~//~vaa7R~
    pdh=UGETPDH(Pplh);                                             //~va00M~
    putf8=Pputf8;                                                  //~va00M~
//  if (putf8)                                                     //~va00M~//~va0GR~
//  	utf8len=strlen(putf8);                                     //~va00M~//~vb2pR~
    	utf8len=(int)strlen(putf8);                                //~vb2pI~
  if (dirsavename_byu8lc(0,Pplh,Pputf8,utf8len,Pplc,Pplcbuffsz,&lclen))//~vawnR~
  {                                                                //~vawnI~
//  if (Popt & DSN2O_F2L)	//save locale by Pputf8 parm           //~va00I~//~va0GR~
//  {                                                              //~va00I~//~va0GR~
//  		opt=XEUTFCVO_CPLC|XEUTFCVO_RETALLASCII|XEUTFCVO_NOERRREP;//~va0FM~//~va0GR~
    		opt=XEUTFGLSMO_STRZ|XEUTFGLSMO_KEEPLC;                 //~va0GR~
			opt|=dirgetmixstropt(0,Pplh,putf8);                    //~vawpI~
//      if (utf8len)                                               //~va00I~//~va0GR~
//  		rc=xeutf_cvdata(XEUTFCVO_CPLC|XEUTFCVO_RETALLASCII,    //~va00R~//~va0FR~
//  		rc=xeutf_cvdata(opt,                                   //~va0FI~//~va0GR~
//  						putf8,utf8len,&plc,&lclen);            //~va00R~//~va0GR~
			xeutf_getmixedstr(opt,putf8,utf8len,Pplc,0/*Pdbcs*/,0/*Pcodetype*/,Pplcbuffsz,&lclen,//~va0GR~
                        		0/*Poututf8*/,0/*Poututf8sz*/,0/*Ppoututf8len*/);//~va0GR~
//      else                                                       //~va00I~//~va0GR~
//          rc=XEUTFCVRC_ALLASCII;                                 //~va00R~//~va0GR~
//      if (rc==UALLOC_FAILED)                                     //~va00I~//~va0GR~
//      	return rc;                                             //~va00I~//~va0GR~
//      if (rc==XEUTFCVRC_ALLASCII)                                //~va00I~//~va0FR~
//      if (rc)  //allascii or CPLC failed                         //~va0FR~//~va0GR~
//      {                                                          //~va00I~//~va0GR~
//          plc=putf8;                                             //~va00I~//~va0GR~
//          putf8=0;                                               //~va00I~//~va0GR~
//      }                                                          //~va00I~//~va0GR~
//      else                                                       //~va00I~//~va0GR~
//      	*(plc+lclen)=0;                                        //~va00R~//~va0GR~
//  }                                                              //~va00I~//~va0GR~
//  if (rc=dirsavename(Pplh,plc),rc)                               //~va00I~//~va0GR~
//  	return rc;                                                 //~va00I~//~va0GR~
  }                                                                //~vawnI~
//  if (putf8)                                                     //~va00R~//~va0GR~
//  {                                                              //~va00I~//~va0GR~
        if (!(pdh->UDHrenamesvbyutf8=UALLOCM((UINT)(utf8len+1))))  //~va00R~
            return UALLOC_FAILED;                                  //~va00R~
        UmemcpyZ(pdh->UDHrenamesvbyutf8,putf8,(UINT)utf8len);      //~va00R~
    	UTRACED("UDHrenamesvbyutf8",putf8,utf8len);                //~vawaI~
//      UCBITON(pdh->UDHflag4,(UDHF4RENAMEU8));                    //~va00R~//~va0GR~
//  }                                                              //~va00I~//~va0GR~
    *Ppplclen=lclen;                                               //~va0GI~
    return 0;                                                      //~va00R~
}//dirsavename_byutf8                                              //~va00R~
#endif                                                             //~va00I~
//*******************************************************          //~vawnI~
//*save utf8 string input on rename fld  referencing UDHrename_codetype//~vawnI~
//* return:0:utf8 string reamined on UDHrename_utf8                //~vawnI~
//*******************************************************          //~vawnI~
int dirsavename_byu8lc(int Popt,PULINEH Pplh,UCHAR *Putf8,int Pu8len,UCHAR *Pplc,int Pbuffsz,int *Ppplclen)//~vawnR~
{                                                                  //~vawnI~
    PUDIRLH pdh;                                                   //~vawnI~
    char *pu8,*pu82,*pct;                                          //~vawnI~
	int u8len,lclen,offs,rc2,opt,rc=4;                             //~vawnR~
//************************                                         //~vawnI~
	UTRACED("inp",Putf8,Pu8len);                                   //~vawnI~
    pdh=UGETPDH(Pplh);                                             //~vawnI~
	pu8=pdh->UDHrename_utf8;                                       //~vawnR~
    if (!pu8||!*pu8)                                               //~vawnR~
    	return rc;                                                 //~vawnI~
//  u8len=strlen(pu8);                                             //~vawnR~//~vb2pR~
    u8len=(int)strlen(pu8);                                        //~vb2pI~
//  if (!(pu82=umemmem(pu8,Putf8,u8len,Pu8len)))	//not remained //~vawnI~//~vb2pR~
    if (!(pu82=umemmem(pu8,Putf8,(UINT)u8len,(UINT)Pu8len)))	//not remained//~vb2pI~
    	return rc;                                                 //~vawnI~
    offs=PTRDIFF(pu82,pu8);                                        //~vawnR~
	pct=pdh->UDHrename_codetype+offs;                              //~vawnR~
    opt=0;                                                         //~vawnI~
    rc2=xeutf_cvlf2lbyct(opt,pu82,Pu8len,pct,Pu8len/*ctlen*/,Pplc,Pbuffsz,&lclen);//~vawnI~
    *Ppplclen=lclen;                                               //~vawnI~
    if (rc2>=4)                                                    //~vawnI~
    	return rc;                                                 //~vawnI~
#ifdef LNX                                                         //~vawnI~
//#ifndef HHH                                                      //~vawnR~
	opt=0;                                                         //~vawnI~
    rc2=dirsetddfmtname_renamesv(opt,Pplh,pu82,Pu8len,pct,lclen);  //~vawnR~
    if (rc2==XEUTFGU8MRC_UTF8)                                     //~vawnR~
		UCBITON(pdh->UDHflag4,UDHF4RENAMEU8);                      //~vawnI~
    else                                                           //~vawnI~
    if (rc2==XEUTFGU8MRC_LC)                                       //~vawnR~
		UCBITON(pdh->UDHflag4,UDHF4RENAMELC);                      //~vawnI~
//#else                                                            //~vawnR~
//    if (offs)                                                    //~vawnR~
//    {                                                            //~vawnR~
//        memcpy(pu8+offs,pu82,Pu8len+1);                          //~vawnR~
//        memcpy(pdh->UDHrename_codetype,pct,lclen);               //~vawnR~
//    }                                                            //~vawnR~
//#endif                                                           //~vawnR~
    UCBITON(pdh->UDHflag5,UDHF5SETRENAMEDD);   //call drawrenamedd //~vawnM~
#endif                                                             //~vawnI~
	UTRACED("out lc",Pplc,lclen);                                  //~vawnI~
    return 0;                                                      //~vawnI~
}//dirsavename_byu8lc;                                             //~vawnI~
//*******************************************************          //~vawpI~
//*save utf8 string input on rename fld  referencing UDHrename_codetype//~vawpI~
//* return:0:utf8 string reamined on UDHrename_utf8                //~vawpI~
//*******************************************************          //~vawpI~
int dirsavenameDDFMT2(int Popt,PULINEH Pplh,UCHAR *Putf8)          //~vawpI~
{                                                                  //~vawpI~
    return dirsavename(Pplh,Putf8);                                //~vawpI~
#ifdef AAA                                                         //~vawpI~
    PUDIRLH pdh;                                                   //~vawpI~
    char *pu8,*pct;                                                //~vawpR~
	int u8len,rc2,opt;                                             //~vawpR~
//************************                                         //~vawpI~
    pdh=UGETPDH(Pplh);                                             //~vawpI~
	pu8=pdh->UDHrename_utf8;                                       //~vawpI~
	pct=pdh->UDHrename_codetype;                                   //~vawpI~
    if (!pu8||!*pu8)                                               //~vawpI~
    	return dirsavename(Pplh,Putf8);                            //~vawpI~
    u8len=strlen(pu8);                                             //~vawpM~
	UTRACED("inp",Putf8,u8len);                                    //~vawpI~
	opt=0;                                                         //~vawpI~
    rc2=dirsetddfmtname_renamesv(opt,Pplh,pu8,u8len,pct,u8len/*lclen*/);//~vawpI~
    if (rc2==XEUTFGU8MRC_UTF8)                                     //~vawpI~
		UCBITON(pdh->UDHflag4,UDHF4RENAMEU8);                      //~vawpI~
    else                                                           //~vawpI~
    if (rc2==XEUTFGU8MRC_LC)                                       //~vawpI~
		UCBITON(pdh->UDHflag4,UDHF4RENAMELC);                      //~vawpI~
    return 0;                                                      //~vawpI~
#endif                                                             //~vawpI~
}//dirsavenameDDFMT2                                               //~vawpR~
//*******************************************************       //~5826I~
//*dir set err field(reverse req)                               //~5826R~
//* parm1: client work                                          //~5826I~
//* parm2: plh                                                  //~5826I~
//* parm3: fieldno in row	(start from 0)                      //~5826I~
//* return:none                                                 //~5826R~
//*******************************************************       //~5826I~
void dirsetflderr(PUCLIENTWE Ppcw,PULINEH Pplh,int Pfldno)      //~5826R~
{                                                               //~5826I~
//************************                                      //~5826I~
	UGETPDH(Pplh)->UDHerrfldno=(UCHAR)Pfldno;                   //~5826R~
    UCBITON(Pplh->ULHflag,ULHFDIRLFLDERR);                      //~5826R~
	filesetcsr(Ppcw,Pplh,Pfldno,0);//set csr                    //~5826I~
}//dirsetflderr                                                 //~5826R~
                                                                //~v03zI~
////*******************************************************        //~v0k2R~
////*file attr conv to char                                        //~v0k2R~
////* parm1: attribute                                             //~v0k2R~
////* parm2: output area                                           //~v0k2R~
////* return:none                                                  //~v0k2R~
////*******************************************************        //~v0k2R~
//void dirattrstring(UCHAR Pattr,UCHAR *Pout)                      //~v0k2R~
//{                                                                //~v0k2R~
////************************                                       //~v0k2R~
//    if (UCBITCHK(Pattr,FILE_ARCHIVED))                           //~v0k2R~
//        Pout[0]='A';                                             //~v0k2R~
//    else                                                         //~v0k2R~
//        Pout[0]='-';                                             //~v0k2R~
//    if (UCBITCHK(Pattr,FILE_SYSTEM))                             //~v0k2R~
//        Pout[1]='S';                                             //~v0k2R~
//    else                                                         //~v0k2R~
//        Pout[1]='-';                                             //~v0k2R~
//    if (UCBITCHK(Pattr,FILE_HIDDEN))                             //~v0k2R~
//        Pout[2]='H';                                             //~v0k2R~
//    else                                                         //~v0k2R~
//        Pout[2]='-';                                             //~v0k2R~
//    if (UCBITCHK(Pattr,FILE_READONLY))                           //~v0k2R~
//        Pout[3]='R';                                             //~v0k2R~
//    else                                                         //~v0k2R~
//        Pout[3]='-';                                             //~v0k2R~
//    return;                                                      //~v0k2R~
//}//dirattrstring                                                 //~v0k2R~
//                                                                 //~v0k2R~
                                                                   //~v203I~
//#ifdef UNX                                                       //~v59fR~
#ifdef FTPSUPP                                                     //~v59fI~
                                                                   //~v203I~
//*******************************************************          //~v203I~
//*chk and return attribute bit                                    //~v203I~
//* parm1: attribute char                                          //~v203I~
//* return:attribute bit(0 if err)                                 //~v203R~
//*******************************************************          //~v203I~
#ifdef UNX                                                         //~v59fI~
ULONG dirattrbit(UCHAR **Ppattr)                                   //~v203R~
#else                                                              //~v59fI~
ULONG dirattrbitremote(UCHAR **Ppattr)                             //~v59fI~
#endif                                                             //~v59fI~
{                                                                  //~v203I~
	int attr,ii;                                                   //~v203R~
	ULONG mode=0;                                                  //~v203R~
	char *pc;                                                      //~v203I~
//************************                                         //~v203I~
	pc=*Ppattr;                                                    //~v203I~
	attr=*pc;                                                      //~v203I~
	if (attr>='0' && attr<='7')                                    //~v203R~
    {                                                              //~v203I~
    	for (ii=0;ii<4;ii++,pc++)                                  //~v203R~
        {                                                          //~v203I~
            attr=*pc;                                              //~v203I~
			if (attr>='0' && attr<='7')                            //~v203I~
//        		mode=(mode<<3)+attr-'0';                           //~v203R~//~vb2pR~
        		mode=(mode<<3)+(ULONG)attr-'0';                    //~vb2pI~
            else                                                   //~v203I~
            	break;                                             //~v203I~
        }                                                          //~v203I~
        *Ppattr=pc;   //to last char pos                           //~v205R~
    }                                                              //~v203I~
    else                                                           //~v203I~
        switch(attr)                                               //~v203R~
        {                                                          //~v203R~
        case 's':                                                  //~v45LI~
        case 'S':                                                  //~v203R~
            mode=S_ISUID+S_ISGID;                                  //~v203R~
            break;                                                 //~v203I~
//      case 's':                                                  //~v42qR~
        case 'U':                                                  //~v42qI~
        case 'u':                                                  //~v42qI~
            mode=S_ISUID;                                          //~v203R~
            break;                                                 //~v203I~
        case 'G':                                                  //~v203R~
        case 'g':                                                  //~v203R~
            mode=S_ISGID;                                          //~v203R~
            break;                                                 //~v203I~
        case 'T':                                                  //~v203R~
        case 't':                                                  //~v203R~
            mode=S_ISVTX;                                          //~v203R~
            break;                                                 //~v203I~
        default:                                                   //~v203I~
			return	0; //err                                       //~v203M~
        }                                                          //~v203R~
	return	FILE_SETMODEATTR(mode,0);                              //~v203R~
}//dirattrbit                                                      //~v203I~
                                                                   //~v203I~
//#else  //!UNX                                                    //~v47CR~
#endif                                                             //~v47CI~
                                                                   //~v203I~
//*******************************************************       //~v03zI~
//*chk and return attribute bit                                 //~v03zI~
//* parm1: attribute char                                       //~v03zI~
//* return:attribute bit(0 if err)                              //~v03zI~
//*******************************************************       //~v03zI~
#ifdef UNX                                                         //~v47CI~
ULONG dirattrbit_mdos(UCHAR Pattrchar)                             //~v47CI~
#else                                                              //~v47CI~
UCHAR dirattrbit(UCHAR Pattrchar)                               //~v03zI~
#endif //!UNX                                                      //~v47CI~
{                                                               //~v03zI~
//************************                                      //~v03zI~
	switch(Pattrchar)                                           //~v03zI~
    {                                                           //~v03zI~
    case 'A':                                                   //~v03zI~
    case 'a':                                                   //~v03zI~
 		return FILE_ARCHIVED;                                   //~v03zI~
    case 'S':                                                   //~v03zI~
    case 's':                                                   //~v03zI~
    	return FILE_SYSTEM;                                     //~v03zI~
    case 'H':                                                   //~v03zI~
    case 'h':                                                   //~v03zI~
    	return FILE_HIDDEN;                                     //~v03zI~
    case 'R':                                                   //~v03zI~
    case 'r':                                                   //~v03zI~
    	return FILE_READONLY;                                   //~v03zI~
	}                                                           //~v03zI~
	return	0;                                                  //~v03zI~
}//dirattrbit                                                   //~v03zI~
//#endif //!UNX                                                    //~v47CR~
                                                                   //~v20fI~
//#ifdef UNX                                                       //~v55hR~
#ifdef FTPSUPP                                                     //~v55hI~
//*******************************************************          //~v20fI~
//*set usid/gid                                                    //~v20fI~
//* return:none                                                    //~v20fI~
//*******************************************************          //~v20fI~
//void dirugidedit(PUDIRLH Ppdh,PUDIRLD Ppdd)                      //~v55hR~
//void dirugidedit(PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLD Ppdd)         //~v59TR~
void dirugidedit(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLD Ppdd)//~v59TI~
{                                                                  //~v20fI~
	PUFILEC pfc;                                                   //~v59TI~
    char *uname,*gname;                                            //~v20fR~
//  char wk[sizeof(Ppdd->UDDname)*2];                              //~v182R~
    char wk[64];                                                   //~v182I~
    int len,pos;                                                   //~v20fI~
    int remotesw;                                                  //~v55hI~
    int expandlen;                                                 //~v59TI~
//*********************                                            //~v20fI~
	pfc=Ppcw->UCWpfc;                                              //~v59TI~
    expandlen=pfc->UFCexpandlen;                                   //~v59TI~
    len=sizeof(Ppdd->UDDsize);                                     //~v20hR~
//  memset(Ppdd->UDDsize,' ',len);                                 //~v59TR~
//  memset(Ppdd->UDDsize+expandlen,' ',len);                       //~v59TI~//~vb2pR~
    memset(Ppdd->UDDsize+expandlen,' ',(size_t)len);               //~vb2pI~
  	remotesw=FILEISREMOTE(Ppfh);                                   //~v55hI~
  if (FILE_ISSMB(Ppfh))                                            //~vac1I~
  {                                                                //~vac1I~
#ifdef W32                                                         //~vac1I~
    pos=sprintf(wk," %6d/%5d",0,0);        //SMB is not aval for windows version//~vac1I~
#else                                                              //~vac1I~
    pos=sprintf(wk," %6d/%5d",Ppdh->UDHuid,Ppdh->UDHgid);          //~vac1I~
#endif                                                             //~vac1I~
    if (pos>len)                                                   //~vac1I~
        pos=len;                                                   //~vac1I~
  }                                                                //~vac1I~
  else                                                             //~vac1I~
  {                                                                //~vac1I~
#ifdef UNX                                                         //~v55hI~
    if (!UCBITCHK(Gscrstatus,GSCRSDIRUGID) 	//UNX uid edit mode    //~v55hI~
    ||   remotesw)                                                 //~v55hR~
    {                                                              //~v20fI~
#endif                                                             //~v55hI~
//#ifdef FTPSUPP                                                   //~v55hR~
	  if (Ppdh->UDHslink && UCBITCHK(Gdir3status,GDIR3SLFN))	//display long//~v54eI~
        	uname=Ppdh->UDHslinkuname;                             //~v54eI~
      else                                                         //~v54eI~
//#endif                                                           //~v55hR~
#ifdef W32                                                         //~v55hI~
        uname=Ppdh->UDHuname;                                      //~v55hR~
#else                                                              //~v55hI~
//      if (!(uname=Ppdh->UDHuname))    //not yet set              //~v55hR~
//          Ppdh->UDHuname=uname=ugetusername(Ppdh->UDHuid);       //~v55hR~
	   	if (remotesw)                                              //~v55hI~
        	uname=Ppdh->UDHuname;                                  //~v55hR~
       	else                                                       //~v55hI~
			if (!*(uname=Ppdh->UDHuname))    //not yet set         //~v55hI~
            {                                                      //~v55hI~
				uname=ugetusername(Ppdh->UDHuid);                  //~v55hI~
				strncpy(Ppdh->UDHuname,uname,MAXUNAMESZ);          //~v55hI~
            }                                                      //~v55hI~
#endif                                                             //~v55hI~
//#ifdef FTPSUPP                                                   //~v55hR~
	  if (Ppdh->UDHslink && UCBITCHK(Gdir3status,GDIR3SLFN))	//display long//~v54eI~
        	gname=Ppdh->UDHslinkgname;                             //~v54eI~
      else                                                         //~v54eI~
//#endif                                                           //~v55hR~
#ifdef W32                                                         //~v55hI~
        gname=Ppdh->UDHgname;                                      //~v55hR~
#else                                                              //~v55hI~
//      if (!(gname=Ppdh->UDHgname))    //not yet set              //~v55hR~
//          Ppdh->UDHgname=gname=ugetgroupname(Ppdh->UDHgid);      //~v55hR~
	   	if (remotesw)                                              //~v55hI~
        	gname=Ppdh->UDHgname;                                  //~v55hR~
       	else                                                       //~v55hI~
			if (!*(gname=Ppdh->UDHgname))    //not yet set         //~v55hI~
            {                                                      //~v55hI~
            	gname=ugetgroupname(Ppdh->UDHgid);                 //~v55hI~
				strncpy(Ppdh->UDHgname,gname,MAXGNAMESZ);          //~v55hI~
            }                                                      //~v55hI~
#endif                                                             //~v55hI~
        pos=sprintf(wk," %.*s",len,uname);                         //~v20fR~
        len-=pos;                                                  //~v20hR~
      if (!FILEISTSO(Ppfh))                                        //~v72vR~
      {                                                            //~v72vI~
        len--;        //for "/" between uname and gname            //~v41zI~
        if (len>0)                                                 //~v20fR~
            pos+=sprintf(wk+pos,"/%.*s",len,gname);                //~v20fR~
      }                                                            //~v72vI~
#ifdef UNX                                                         //~v55hI~
    }                                                              //~v20fI~
    else                                                           //~v20fI~
    {                                                              //~v41zR~
    	pos=sprintf(wk," %6d/%5d",Ppdh->UDHuid,Ppdh->UDHgid);      //~v20hR~
        if (pos>len)                                               //~v20hR~
        	pos=len;                                               //~v20hR~
    }                                                              //~v41zR~
#endif                                                             //~v55hI~
  }//SMB                                                           //~vac1I~
                                                                   //~v20fI~
//  memcpy(Ppdd->UDDsize,wk,pos);                                  //~v59TR~
//  memcpy(Ppdd->UDDsize+expandlen,wk,pos);                        //~v59TI~//~vb2pR~
    memcpy(Ppdd->UDDsize+expandlen,wk,(size_t)pos);                //~vb2pI~
    return;                                                        //~v20fI~
}//dirugidedit                                                     //~v55hR~
                                                                   //~v20fI~
#endif //UNX                                                       //~v20fI~
//**************************************************               //~v183I~
//*dirsetdbcssplit                                                 //~v183I~
//*ajust DBCS half cut data(inner left/right boundary data)        //~v183I~
//*parm 1:data                                                     //~v183I~
//*parm 2:dbcstbl                                                  //~v183I~
//*parm 3:len                                                      //~v183I~
//*parm 4:repl data when split detected,if ' ' reple dbcs tbl also //~v183I~
//*return:0:no dbcs change,1:cut at top,2:cut at end,3 both        //~v183I~
//*       4:dbcserr replaced                                       //~v777I~
//**************************************************               //~v183I~
//int dirsetdbcssplit(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar)//~vauNR~
int dirsetdbcssplit(PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar)//~vauNI~
{                                                                  //~v183I~
	int rc=0,startsw=1,ii;                                         //~v183R~
    UCHAR *pc,*pcd;                                                //~v183I~
    int dbcssz;                                                    //~vauNR~
    PUDIRLH pdh;                                                   //~vauNI~
//*************                                                    //~v183I~
	pdh=UGETPDH(Pplh);                                             //~vauNR~
//#ifdef LNX                                                       //~v79zR~
////  if (!UCBITCHK(Gunxflag,GUNX_EUC))   //dbcs                   //~v79zR~
//    if ((Gunxflag & (GUNX_EUC|GUNX_KON))!=(GUNX_EUC|GUNX_KON))   //~v79zR~
//#else                                                            //~v79zR~
//    if (!UCBITCHK(Gscrstatus,GSCRSDBCS))    //dbcs               //~v79zR~
//#endif                                                           //~v79zR~
//  if (!XE_ISDBCS())	//no dbcs lang                             //~v79zI~//~va1FR~
    if (!XE_ISDBCSKON())	//no dbcs lang                         //~va1FI~
      if (!UCBITCHK(pdh->UDHflag4,UDHF4DDFMT))                     //~vauNI~
    	return 0;                                                  //~v183I~
//UTRACED("dirsetdbcssplit input data",Pdata,Plen);                  //~va1cR~//~vajsR~
//UTRACED("dirsetdbcssplit input dbcs",Pdbcs,Plen);                  //~va1cR~//~vajsR~
	for (pc=Pdata,pcd=Pdbcs,ii=0;ii<Plen;ii++,pc++,pcd++)          //~v183R~
    {                                                              //~v183I~
//  	switch(*pcd)                                               //~v183I~//~vavSR~
        switch(UDBCSCHK_TEMPDBCSID(*pcd))                          //~vavSI~
        {                                                          //~v183I~
//** dirsetdbcstbl set hkdbcserr for split dbcs ***                //~va1cR~
        case DBCS1STCHAR:	//end with first byte                  //~v183I~
//      case UDBCSCHK_HKDBCSERR:	//dbcs conbination err         //~v777R~
//      	if (ii+1>=Plen || !*(pc+1))	//last byte or next is null//~v183I~//~va2pR~
			dbcssz=XESUB_DBCSSPLITCTR(pcd,Plen-ii,0/*pos*/);       //~va2pR~
        	if (*(pcd+dbcssz-1)!=UDBCSCHK_DBCS2ND)	//inmatured dbcs//~va2pI~
            {                                                      //~v183I~
            	*pcd=0;                                            //~v183I~
            	*pc=Prepchar;                                      //~v183I~
                rc|=2;                                             //~v183I~
                startsw=1;	//replace following split              //~va2pI~
            }                                                      //~v183I~
            else                                                   //~va2pI~
            startsw=0;                                             //~v183I~
        	break;                                                 //~v183I~
//** dirsetdbcstbl set hkdbcserr for split dbcs ***                //~va1cR~
  		case DBCS2NDCHAR:	//start with second byte               //~v183I~
  		case UDBCSCHK_DBCSPAD:	//after null char                  //~va2pI~
        	if (startsw)	//1st byte                             //~v183I~
            {                                                      //~v183I~
            	*pcd=0;                                            //~v183I~
            	*pc=Prepchar;                                      //~v183I~
                rc|=1;                                             //~v183I~
            }                                                      //~v183I~
        	break;                                                 //~v183I~
        case UDBCSCHK_HKDBCSERR:	//dbcs conbination err         //~v777I~
            *pc=Prepchar;                                          //~v777I~
            rc|=4;                                                 //~v777I~
        	break;                                                 //~v777I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
        case UDBCSCHK_DBCS1STUCS_CASE():                           //~vau0I~
//      	switch (*(pcd+1))	//inmatured dbcs                   //~vau0R~//~vavSR~
        	switch (UDBCSCHK_TEMPDBCSID(*(pcd+1)))	//inmatured dbcs//~vavSI~
            {                                                      //~vau0I~
        	case UDBCSCHK_DBCS2NDUCS_CASE():                       //~vau0I~
                break;                                             //~vau0M~
            default:                                               //~vau0M~
            	*pcd=0;                                            //~vau0I~
            	*pc=Prepchar;                                      //~vau0I~
                rc|=2;                                             //~vau0I~
            }                                                      //~vau0I~
        	break;                                                 //~vau0I~
        case UDBCSCHK_DBCS2NDUCS_CASE():                           //~vau0I~
        	break;                                                 //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
        }                                                          //~v183I~
        if (!*pc)                                                  //~v183I~
        	startsw=1;                                             //~v183I~
    }                                                              //~v183I~
//UTRACED("dirsetdbcssplit outpt data",Pdata,Plen);                  //~va1cR~//~vajsR~
//UTRACED("dirsetdbcssplit putpt dbcs",Pdbcs,Plen);                  //~va1cR~//~vajsR~
  	return rc;                                                     //~v183I~
}//dirsetdbcssplit                                                 //~v183I~
#ifdef UTF8SUPPH                                                   //~va1cR~
//**************************************************************** //~va1cR~
//!dirsetdbcstbl                                                   //~va1cR~
//*evaluate each fld split by null                                 //~va1cR~
//**************************************************************** //~va1cR~
int dirsetdbcstbl(int Popt,char *Pdata,char *Pdbcs,int Plen)       //~va1cR~
{                                                                  //~va1cR~
	char *pc,*pcd,*pcn;                                            //~va1cR~
    int reslen,chklen,opt,nulllen;                                 //~va1cR~
//***************************                                      //~va1cR~
	opt=USDTMO_SPLITERR|USDTMO_CHK2ND|USDTMO_SETERRFULL;	//set err to all byte split//~va1cR~
	pc=Pdata;pcd=Pdbcs;reslen=Plen;                                //~va1cR~
	if (!(Popt & DSDTO_FULLLINE))                                  //~va1cR~
		usetdbcstblmb(opt,pc,pcd,reslen);                          //~va1cR~
    else                                                           //~va1cR~
	for (;reslen>0;pc+=chklen,pcd+=chklen,reslen-=chklen)          //~va1cR~
    {                                                              //~va1cR~
//      pcn=memchr(pc,0,reslen);                                   //~va1cR~//~vb2pR~
        pcn=memchr(pc,0,(size_t)reslen);                           //~vb2pI~
        if (pcn)                                                   //~va1cR~
        {                                                          //~va1cR~
//          chklen=(int)((ULONG)pcn-(ULONG)pc);                    //~va1cR~//~vafkR~
            chklen=(int)((ULPTR)pcn-(ULPTR)pc);                    //~vafkI~
        	*(pcd+chklen)=0;                                       //~va1cR~
        }                                                          //~va1cR~
        else                                                       //~va1cR~
            chklen=reslen;                                         //~va1cR~
		usetdbcstblmb(opt,pc,pcd,chklen);                          //~va1cR~
        if (pcn)                                                   //~va1cR~
        {                                                          //~va1cR~
//        	nulllen=umemspnc(pcn,0,reslen-chklen);                 //~va1cR~//~vb2pR~
          	nulllen=(int)umemspnc(pcn,0,(UINT)(reslen-chklen));    //~vb2pI~
            memset(pcd+chklen,0,(UINT)nulllen);                    //~va1cR~
        	chklen+=nulllen;                                       //~va1cR~
        }                                                          //~va1cR~
    }                                                              //~va1cR~
UTRACED("dirsetdbcstbl in  data",Pdata,Plen);                      //~va1cR~
UTRACED("dirsetdbcstbl out dbcs",Pdbcs,Plen);                      //~va1cR~
    return 0;                                                      //~va1cR~
}//dirsetdbcstbl                                                   //~va1cR~
//#ifdef LNX                                                         //~vau0I~//~vauER~
//**************************************************************** //~vau0I~
//ddfmt dbcs                                                       //~vau0I~
//**************************************************************** //~vau0I~
int dirsetdbcstblDDFMT(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,char *Pdata,char *Pdbcs,int Plen)//~vau0I~
{                                                                  //~vau0I~
	char *pc,*pc0,*pcd,*pcd0,*pdddata,*pdddbcs;                    //~vau0R~
    int offs,partsno=0,ulhlen,len=0,ii,fnmwidth;                   //~vau0R~
#define DIRDD_MAXPART 4	//name,slink,rename,desc                                            //~vau0I~//~vau1R~
    int parts[DIRDD_MAXPART][2];//offs+len for each part:top,member,slink,rename//~vau0R~
    UCHAR *pddstr[DIRDD_MAXPART];                                  //~vau0R~
    UCHAR *pddstrd[DIRDD_MAXPART];                                 //~vau0R~
    PUFILEC pfc;                                                   //~vau1I~
#ifdef W32                                                         //~vav6I~
    PUFILEH pfh;                                                   //~vav6I~
#endif                                                             //~vav6I~
//***************************                                      //~vau0I~
    UTRACEP("dirsetdbcstblDDFMT\n");                               //~vau0I~
	ulhlen=Pplh->ULHlen;                                           //~vau0I~
	pdddata=Ppdh->UDHnameddfmt;                                    //~vau0I~
    fnmwidth=Ppdh->UDHfnmwidth;	//filename field width             //~vau0I~
	pfc=Ppcw->UCWpfc;                                              //~vav6I~
#ifdef W32                                                         //~vav6I~
    pfh=pfc->UFCpfh;                                               //~vav6I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn               //~vav6I~
#endif                                                             //~vav6I~
    if (pdddata)    //lc or u8(not all ascii)                      //~vau0I~
    {                                                              //~vau0I~
        len=Ppdh->UDHnameddfmtlen;                                 //~vau0M~
    	UTRACED("UDHnameddfmt",pdddata,len);                       //~vb14I~
        pddstr[partsno]=pdddata;                                   //~vau0M~
        pddstrd[partsno]=pdddata+len;                              //~vau0R~
        offs=Ppdh->UDHnameoffs;                                    //~vau0R~
        len=min(fnmwidth,len);                                     //~vau0I~
        parts[partsno][0]=offs;                                    //~vau0R~
        parts[partsno][1]=len;                                     //~vau0R~
        partsno++;                                                 //~vau0R~
    }                                                              //~vau0I~
//*slinkname                                                       //~vau0I~
    pdddata=Ppdh->UDHslinkddfmt;                                   //~vau0I~
	offs=Ppdh->UDHslinkoffs;  //relative to membername             //~vau0I~
	if (pdddata && offs)  //display slinkname relative to membername//~vau0R~
    {                                                              //~vau0I~
	    len=Ppdh->UDHslinkddfmtlen;                                //~vau0M~
    	pddstr[partsno]=pdddata;                                   //~vau0I~
    	pddstrd[partsno]=pdddata+len;                              //~vau0R~
        len=min(fnmwidth,offs+len)-offs;                           //~vau0I~
        if (len>0)                                                 //~vau0I~
        {                                                          //~vau0I~
	    	offs+=Ppdh->UDHnameoffs;                               //~vau0R~
    		parts[partsno][0]=offs;                                //~vau0R~
    		parts[partsno][1]=len;                                 //~vau0R~
        	partsno++;                                             //~vau0R~
        }                                                          //~vau0I~
    }                                                              //~vau0I~
    pdddata=Ppdh->UDHrenameddfmt;                                  //~vau0I~
	offs=Ppdh->UDHrenameoffs;                                      //~vau0I~
    len=Ppdh->UDHrenameddfmtlen;                                   //~vawaI~
	UTRACEP("UDHrenameddfmtlen=%d\n",len);                         //~vb14I~
//  if (pdddata && offs)                                           //~vau0R~//~vawaR~
    if (len && pdddata && offs)                                    //~vawaI~
    {                                                              //~vau0I~
//      len=Ppdh->UDHrenameddfmtlen;                               //~vau0M~//~vawaR~
    	pddstr[partsno]=pdddata;                                   //~vau0I~
    	pddstrd[partsno]=pdddata+len;                              //~vau0R~
    	parts[partsno][0]=offs;                                    //~vau0I~
    	parts[partsno][1]=len;                                     //~vau0I~
        partsno++;                                                 //~vau0R~
//#ifdef HHH                                                       //~vawnR~
//        UCBITON(Ppdh->UDHflag5,UDHF5SETRENAMEDD);   //call drawrenamedd//~vawnR~
//#endif                                                           //~vawnR~
	    UTRACED("UDHrenameddfmt",pdddata,len*2);                   //~vawaI~
    }                                                              //~vau0I~
	if (UCBITCHK(Ppdh->UDHflag3,UDHF3SETDESC)                      //~vau1I~
	&&  UCBITCHK(Ppdh->UDHflag4,(UDHF4DESCU8|UDHF4DESCLC)))        //~vau1R~
    {                                                              //~vau1I~
//  	pfc=Ppcw->UCWpfc;                                          //~vau1I~//~vav6R~
//  	offs=offsetof(UDIRLD,UDDattr)+pfc->UFCexpandlen;	//expand if scr is wide//~vau1I~//~vb2pR~
    	offs=(int)offsetof(UDIRLD,UDDattr)+pfc->UFCexpandlen;	//expand if scr is wide//~vb2pI~
    	pdddata=Ppdh->UDHpdesc;                                    //~vau1I~
	    len=UDDDESCSZ;                                             //~vau1I~
    	pddstr[partsno]=pdddata;                                   //~vau1I~
    	pddstrd[partsno]=pdddata+len;                              //~vau1I~
    	parts[partsno][0]=offs;                                    //~vau1I~
    	parts[partsno][1]=len;                                     //~vau1I~
        partsno++;                                                 //~vau1I~
    }                                                              //~vau1I~
    UTRACED("dirsetdbcstblDDFMT parts",parts,(int)sizeof(parts[0])*partsno);//~vau0R~//~vb2pR~
    pc0=Pplh->ULHdata;                                             //~vau0I~
    pcd0=Pplh->ULHdbcs;                                            //~vau0I~
    for (ii=0,pc=pc0,pcd=pcd0;ii<partsno;ii++,pc+=len,pcd+=len)    //~vau0I~
    {                                                              //~vau0I~
    	if (ii==0)                                                 //~vau0I~
        {                                                          //~vau0I~
        	offs=0;                                                //~vau0I~
            len=parts[0][0];                                       //~vau0R~
        }                                                          //~vau0I~
        else                                                       //~vau0I~
        {                                                          //~vau0I~
        	offs=parts[ii-1][0]+parts[ii-1][1];                    //~vau0I~
            len=parts[ii][0]-offs;                                 //~vau0I~
        }                                                          //~vau0I~
		dirsetdbcstbl(0,pc,pcd,len);                               //~vau0I~
	    UTRACED("dirsetdbcstblDDFMT setdbcstbl ascii data",pc,len);//~vau0I~
	    UTRACED("dirsetdbcstblDDFMT setdbcstbl ascii dbcs",pcd,len);//~vau0I~
        pc+=len;                                                   //~vau0I~
        pcd+=len;                                                  //~vau0R~
        offs=parts[ii][0];                                         //~vau0I~
        len=parts[ii][1];                                          //~vau0I~
        len=min(len,ulhlen-offs);                                  //~vau0I~
        if (len>0)                                                 //~vau0R~
        {                                                          //~vau0I~
        	pdddata=pddstr[ii];                                    //~vau0R~
        	pdddbcs=pddstrd[ii];                                   //~vau0R~
//      	memcpy(pc,pdddata,len);                                //~vawaI~//~vb2pR~
        	memcpy(pc,pdddata,(size_t)len);                        //~vb2pI~
//      	memcpy(pcd,pdddbcs,len);                               //~vau0R~//~vb2pR~
        	memcpy(pcd,pdddbcs,(size_t)len);                       //~vb2pI~
	    	UTRACED("dirsetdbcstblDDFMT setdbcstbl ddfmt data",pc,len);//~vau0R~
	    	UTRACED("dirsetdbcstblDDFMT setdbcstbl ddfmt dbcs",pcd,len);//~vau0R~
        }                                                          //~vau0I~
    }                                                              //~vau0I~
    len=ulhlen-PTRDIFF(pc,pc0);                                    //~vau0R~
    if (len>0)                                                     //~vau0I~
    {                                                              //~vau0I~
		dirsetdbcstbl(0,pc,pcd,len);                               //~vau0I~
	    UTRACED("dirsetdbcstblDDFMT setdbcstbl last ascii data",pc,len);//~vau0I~
	    UTRACED("dirsetdbcstblDDFMT setdbcstbl last ascii dbcs",pcd,len);//~vau0I~
    }                                                              //~vau0I~
UTRACED("dirsetdbcstblDDFMT out data",pc0,ulhlen);                 //~vb14R~
UTRACED("dirsetdbcstblDDFMT out dbcs",pcd0,ulhlen);                //~vau0I~
    return 0;                                                      //~vau0I~
}//dirsetdbcstblDDFMT                                              //~vaufR~
//#endif  //LNX                                                      //~vau0I~//~vauER~
#endif                                                             //~va1cR~
//*****************************************************************//~vau3I~
//*dhname or dhslink by cusrsor psosition                          //~vaunR~
//*rc:1:gotten slink,2:fnm gotten, 4:too long                      //~vaunR~
//*****************************************************************//~vau3I~
//int getwowdslink(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,int Pcpos,char *Pword,int Plen/*outbuffsz*/,int *Pplen,int *Ppstrtype)//~vaudR~//~vauGR~
int dirgetnameslink(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,int Pcpos,char *Pword,int Plen/*outbuffsz*/,int *Pplen,int *Ppstrtype,char **Ppdddata,char **Ppdddbcs,int *Ppddlen)//~vauGR~
{                                                                  //~vau3I~
    int rc,len;                                                    //~vaunR~
    int offsname,offsslink,posslink,posfnmend,fnmfldwidth;         //~vaunR~
	UCHAR   *fnm;                                                  //~vau3R~
//#ifdef LNX                                                         //~vauBR~//~vauER~
	int idx,ddlen;                                                 //~vaudR~
    char *pdddata,*pdddbcs,*pddcode;                               //~vaudR~
    char wkddcode[_MAX_PATH];                                      //~vaudI~
//#endif                                                             //~vauBR~//~vauER~
//**************************************                           //~vau3I~
	rc=0;                                                          //~vau3I~
    *Pplen=0;                                                      //~vau3I~
    *Ppstrtype=0;                                                  //~vau3I~
    *Ppdddata=NULL;                                                //~vauGI~
    *Ppdddbcs=NULL;                                                //~vauGI~
//#ifdef AAA                                                         //~vaunI~//~vav6R~
//    if (UCBITCHK(Gdir3status,GDIR3SLFN) //display long             //~vau3M~//~vav6R~
//    &&  UCBITCHK(Ppfh->UFHflag4,UFHF4LFN)//display lfn             //~vau3I~//~vav6R~
//    &&  Ppdh->UDHslink      //slink defined                        //~vau3I~//~vav6R~
//    )                                                              //~vau3M~//~vav6R~
//    {                                                              //~vau3M~//~vav6R~
//        slinklen=strlen(Ppdh->UDHslink);                           //~vau3I~//~vav6R~
//        posslinks=Ppdh->UDHnameoffs+Ppdh->UDHslinkoffs;            //~vau3I~//~vav6R~
////#ifdef LNX                                                         //~vau3M~//~vauER~//~vav6R~
//      if (Ppdh->UDHslinkddfmtlen)                                  //~vau3I~//~vav6R~
//        posslinke=posslinks+Ppdh->UDHslinkddfmtlen;                //~vau3I~//~vav6R~
//      else                                                         //~vau3M~//~vav6R~
////#endif                                                             //~vau3M~//~vauER~//~vav6R~
//        posslinke=posslinks+slinklen;                              //~vau3M~//~vav6R~
//        if (Pcpos>=posslinks && Pcpos<posslinke)                   //~vau3R~//~vav6R~
//            rc=1;                                                  //~vau3I~//~vav6R~
//    }                                                              //~vau3M~//~vav6R~
//    if (rc)                                                        //~vau3I~//~vav6R~
//#else   //AAA                                                      //~vaunI~//~vav6R~
    offsname=Ppdh->UDHnameoffs;                                    //~vaunI~
    offsslink=Ppdh->UDHslinkoffs;                                  //~vaunI~
    fnmfldwidth=Ppdh->UDHfnmwidth; //name+slink                    //~vaunR~
    posfnmend=offsname+fnmfldwidth;  //boundary2                   //~vaunR~
    UTRACEP("dirgetnameslink offsname=%d,offsslink=%d,fnmfldwidth=%d,posfnmend=%d\n",offsname,offsslink,fnmfldwidth,posfnmend);//~vaupI~//~vauGR~
    if (offsslink)                                                 //~vaunR~
//#endif //!AAA                                                      //~vaunR~//~vav6R~
    {                                                              //~vau3M~
	    posslink=offsname+offsslink;                               //~vaunI~
      if (Pcpos>=posslink && Pcpos<posfnmend)	//slink displayed  //~vaunI~
      {                                                            //~vaunI~
        rc=1;                                                      //~vaunI~
//#ifdef LNX                                                         //~vauBI~//~vauER~
        fnm=Ppdh->UDHslink;	//original name                        //~vau3I~
//      len=strlen(fnm);                                           //~vaunR~//~vb2pR~
        len=(int)strlen(fnm);                                      //~vb2pI~
//#else                                                              //~vauBI~//~vauER~
//        len=Ppdh->UDHslinknameu8len;                               //~vauBI~//~vauER~
//        if (len)    //slink original is u8                         //~vauBI~//~vauER~
//            fnm=Ppdh->UDHslinknameu8;   //original name            //~vauBI~//~vauER~
//        else                                                       //~vauBI~//~vauER~
//        {                                                          //~vauBI~//~vauER~
//            fnm=Ppdh->UDHslink; //original name                    //~vauBI~//~vauER~
//            len=strlen(fnm);                                       //~vauBI~//~vauER~
//        }                                                          //~vauBI~//~vauER~
//#endif                                                             //~vauBI~//~vauER~
        if (len>Plen)                                              //~vaunR~
        {                                                          //~vau3M~
            errtoolong();                                          //~vau3M~
            return 4;                                              //~vau3I~
        }                                                          //~vau3M~
	    memcpy(Pword,fnm,(UINT)len);                               //~vaunR~
        *Pplen=len;                                                //~vau3I~
#ifdef W32UNICODE                                                  //~vavaR~
        if (UCBITCHK(Ppdh->UDHflag3,UDHF3U8UTFSL)                  //~vavaR~
        ||  UCBITCHK(Ppdh->UDHflag5,UDHF5SUBCHSLINK))    //slinkname  contains subchar//~vavaR~
#else                                                              //~vavaR~
        if (UCBITCHK(Ppdh->UDHflag3,UDHF3U8UTFSL))                 //~vau3R~
#endif                                                             //~vavaR~
        {                                                          //~vaunI~
        	*Ppstrtype=XEUTFCT_UTF8;                               //~vau3I~
//#ifdef LNX                                                         //~vauBR~//~vauER~
			idx=Ppcw->UCWsplitid;                                  //~vaudI~
            ddlen=Ppdh->UDHslinkddfmtlen;                          //~vaudR~
            pdddata=Ppdh->UDHslinkddfmt;                           //~vaudR~
            pdddbcs=pdddata+ddlen;                                 //~vaudI~
            *Ppdddata=pdddata;                                     //~vauGI~
            *Ppdddbcs=pdddbcs;                                     //~vauGI~
            *Ppddlen=ddlen;                                        //~vauGI~
            pddcode=wkddcode;                                      //~vaudR~
//          memset(pddcode,XEUTFCT_UTF8,ddlen);                    //~vaudR~//~vb2pR~
            memset(pddcode,XEUTFCT_UTF8,(size_t)ddlen);            //~vb2pI~
            if (pdddata)                                           //~vaudI~
            {                                                      //~vaudI~
			  	int opt=idx|XEUTFSLCFEO_FILENAME|XEUTFSLCFEO_DDFMT;//~vaudR~
//  		  	xeutf_savelcctforerrmsg(opt,fnm,strlen(fnm),pdddata,pdddbcs,pddcode,ddlen);//~vaudI~//~vb2pR~
    		  	xeutf_savelcctforerrmsg(opt,fnm,(int)strlen(fnm),pdddata,pdddbcs,pddcode,ddlen);//~vb2pI~
            }                                                      //~vaudI~
//#ifdef LNX                                                         //~vauEI~//~vav6R~
//#else                                                              //~vauBR~//~vav6R~
//    #ifdef CCC                                                     //~vauEI~//~vav6R~
//            xedir_savelcctforerrmsg(XEDSFEO_SLINK,Ppcw,Ppdh,fnm,len);//~vauBR~//~vav6R~
//    #endif                                                         //~vauEI~//~vav6R~
//#endif                                                             //~vauBR~//~vav6R~
        }                                                          //~vaudI~
        else                                                       //~vauDI~
        if (UCBITCHK(Ppdh->UDHflag3,UDHF3U8LCSL))                  //~vauDI~
        	*Ppstrtype=XEUTFCT_LC;                                 //~vauDI~
      }//slink range                                               //~vaunI~
	    posfnmend=posslink-4;  //boundary2                         //~vaunI~
    }//slink displayed                                             //~vaunR~
    if (Pcpos>=0 && Pcpos<posfnmend)	//slink displayed          //~vaunR~
    {                                                              //~vaunI~
        rc=2;      	//from filenqame                               //~vaunI~
        fnm=Ppdh->UDHname;	//original name                        //~vaunI~
//      len=strlen(fnm);                                           //~vaunR~//~vb2pR~
        len=(int)strlen(fnm);                                      //~vb2pI~
        if (len>Plen)                                              //~vaunI~
        {                                                          //~vaunI~
            errtoolong();                                          //~vaunI~
            return 4;                                              //~vaunI~
        }                                                          //~vaunI~
	    memcpy(Pword,fnm,(UINT)len);                               //~vaunR~
        *Pplen=len;                                                //~vaunI~
#ifdef W32UNICODE                                                  //~vavaR~
        if (UCBITCHK(Ppdh->UDHflag3,UDHF3U8UTF)                    //~vavaR~
        ||  UCBITCHK(Ppdh->UDHflag5,UDHF5SUBCHFNAME))              //~vavaR~
#else                                                              //~vavaR~
        if (UCBITCHK(Ppdh->UDHflag3,UDHF3U8UTF))                   //~vaunI~
#endif                                                             //~vavaR~
        {                                                          //~vaunI~
        	*Ppstrtype=XEUTFCT_UTF8;                               //~vaunI~
//#ifdef LNX                                                         //~vauBR~//~vauER~
			idx=Ppcw->UCWsplitid;                                  //~vaunI~
            ddlen=Ppdh->UDHnameddfmtlen;                           //~vaunI~
            pdddata=Ppdh->UDHnameddfmt;                            //~vaunI~
            pdddbcs=pdddata+ddlen;                                 //~vaunI~
            *Ppdddata=pdddata;                                     //~vauGI~
            *Ppdddbcs=pdddbcs;                                     //~vauGI~
            *Ppddlen=ddlen;                                        //~vauGI~
            pddcode=wkddcode;                                      //~vaunI~
//          memset(pddcode,XEUTFCT_UTF8,ddlen);                    //~vaunI~//~vb2pR~
            memset(pddcode,XEUTFCT_UTF8,(size_t)ddlen);            //~vb2pI~
            if (pdddata)                                           //~vaunI~
            {                                                      //~vaunI~
			  	int opt=idx|XEUTFSLCFEO_FILENAME|XEUTFSLCFEO_DDFMT;//~vaunI~
//  		  	xeutf_savelcctforerrmsg(opt,fnm,strlen(fnm),pdddata,pdddbcs,pddcode,ddlen);//~vaunI~//~vb2pR~
    		  	xeutf_savelcctforerrmsg(opt,fnm,(int)strlen(fnm),pdddata,pdddbcs,pddcode,ddlen);//~vb2pI~
            }                                                      //~vaunI~
//#ifdef LNX                                                         //~vauEI~//~vav6R~
//#else                                                              //~vauBI~//~vav6R~
//    #ifdef CCC                                                     //~vauEI~//~vav6R~
//            xedir_savelcctforerrmsg(XEDSFEO_FNM,Ppcw,Ppdh,fnm,len);//~vauBR~//~vav6R~
//    #endif                                                         //~vauEI~//~vav6R~
//#endif                                                             //~vauBR~//~vav6R~
        }                                                          //~vaunI~
        else                                                       //~vauDI~
        if (UCBITCHK(Ppdh->UDHflag3,UDHF3U8LC))                    //~vauDI~
        	*Ppstrtype=XEUTFCT_LC;                                 //~vauDI~
    }                                                              //~vaunI~
    UTRACEP("dirgetnameslink rc=%d,cursor=%d,fnmend=%d,type=%d,len=%d,word=%s\n",rc,Pcpos,posfnmend,*Ppstrtype,*Pplen,Pword);//~vaupR~//~vauGR~
    return rc;                                                     //~vau3I~
}//dirgetnameslink                                                 //~vauGR~
//**************************************************************** //~v53cI~
//!dirgetword                                                      //~v53cI~
//*get filename on csr                                             //~v53cI~
//*rc   :wordlen or 0 if err                                       //~v53cI~
//*strtype:01:all utf8(+ascii) str                                 //~vau3I~
//*       :02:contains LC                                          //~vauDI~
//*ddfmt outpu is only when utf8                                   //~vauGI~
//**************************************************************** //~v53cI~
//int dirgetword(PUCLIENTWE Ppcw,char *Pword,int Plen)               //~v53cR~//~vau3R~
//int dirgetword(PUCLIENTWE Ppcw,char *Pword,int Plen,int *Ppstrtype)//~vau3R~//~vauGR~
int dirgetword(PUCLIENTWE Ppcw,char *Pword,int Plen,int *Ppstrtype,char **Ppdddata,char **Ppdddbcs,int *Ppddlen)//~vauGR~
{                                                                  //~v53cI~
	PUSCRD  psd;                                                   //~v53cI~
	PUFILEC pfc;                                                   //~v53cI~
	PUFILEH pfh;                                                   //~v53cI~
	PULINEH plh;                                                   //~v53cI~
    PUDIRLH pdh;                                                   //~v53cI~
	PUDIRLD pdd;                                                   //~v53cI~
	PUDIRLD pddexpand;                                             //~v59TI~
	UCHAR   *pc;                                                   //~vaunR~
    int len,len2,cpos,ii;                                          //~v53cR~
    int expandlen;                                                 //~v59TI~
//#ifdef AAA                                                         //~vaunI~//~vav6R~
//#ifdef LNX                                                         //~vaudI~//~vav6R~
//    int idx,ddlen;                                                 //~vaudR~//~vav6R~
//    char *pdddata,*pdddbcs,*pddcode;                               //~vaudR~//~vav6R~
//    char wkddcode[_MAX_PATH];                                      //~vaudI~//~vav6R~
//#endif //LNX                                                         //~vaudI~//~vauHR~//~vav6R~
//#endif //AAA                                                         //~vaunI~//~vauHR~//~vav6R~
//******************                                               //~v53cI~
    if (!CSRONFILELINE(Ppcw))               //out of screen        //~v53cR~
    {                                                              //~v53cI~
  		errcsrpos();                                               //~v53cI~
        return 0;                                                  //~v53cI~
    }                                                              //~v53cI~
    *Ppstrtype=0;                                                  //~vau3I~
	pfc=Ppcw->UCWpfc;                                              //~v53cI~
    pfh=pfc->UFCpfh;                                               //~v53cI~
    psd=Ppcw->UCWpsd;                                              //~v53cI~
    psd+=Ppcw->UCWrcsry;                                           //~v53cI~
    cpos=Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;    //csr pos            //~v53cR~
    plh=psd->USDbuffc;                                             //~v53cI~
    pdh=UGETPDH(plh);                                              //~v53cR~
    pdd=UGETPDD(plh);                                              //~v53cI~
    expandlen=pfc->UFCexpandlen;                                   //~v59TI~
//  pddexpand=(PUDIRLD)((ULONG)pdd+expandlen);                     //~v59TI~//~vafkR~
//  pddexpand=(PUDIRLD)((ULPTR)pdd+expandlen);                     //~vafkI~//~vb2pR~
    pddexpand=(PUDIRLD)((ULPTR)pdd+(ULPTR)expandlen);              //~vb2pI~
//    if ((level=pdh->UDHlevel)>UDDMAXLEVEL)  //over max           //~v53cR~
//        level=UDDMAXLEVEL;                                       //~v53cR~
//    if (UCBITCHK(Gopt3,GOPT3DIRLISTINDENT))                      //~v53cR~
//        pos1=pdd->UDDlvl+level+2;                                //~v53cR~
//    else                                                         //~v53cR~
//        pos1=pdd->UDDname;                                       //~v53cR~
//    pos2=pdd->UDDattr;                                           //~v53cR~
//    cpos=pdd->UDDlvl+Ppcw->UCWrcsrx;    //csr pos                //~v53cR~
//    if (cpos<pos1||cpos>=pos2)                                   //~v53cR~
//    {                                                            //~v53cR~
//        errcsrpos();                                             //~v53cR~
//        return 0;                                                //~v53cR~
//    }                                                            //~v53cR~
//  if (cpos>=(int)offsetof(UDIRLD,UDDsize))                       //~v59TR~
	len=0;                                                         //~vau3I~
  	if (cpos>=(int)UDIRLDSZ+expandlen)                             //~vaunR~
        errcsrpos();                                               //~vaunI~
    else                                                           //~vaunI~
    if (cpos>=(int)offsetof(UDIRLD,UDDsize)+expandlen)             //~vaunR~
    {                                                              //~v53cI~
//    if (!getwowdslink(Ppcw,pfh,pdh,cpos,Pword,Plen,&len,Ppstrtype))//~vaudR~//~vauGR~
      if (!dirgetnameslink(Ppcw,pfh,pdh,cpos,Pword,Plen,&len,Ppstrtype,Ppdddata,Ppdddbcs,Ppddlen))//~vauGR~
      {                                                            //~vau3I~
        len=sizeof(pdd->UDDsize);                                  //~v53cI~
//      memcpy(Pword,pdd->UDDsize,(UINT)len);                      //~v59TR~
        memcpy(Pword,pddexpand->UDDsize,(UINT)len);                //~v59TI~
        for (ii=0,pc=Pword;ii<len;ii++,pc++)                       //~v53cI~
        	if (!*pc)                                              //~v53cI~
            	*pc=' ';                                           //~v53cI~
      }                                                            //~vau3I~
    }                                                              //~v53cI~
    else                                                           //~v53cI~
//  if (cpos>=(int)offsetof(UDIRLD,UDDdate))                       //~v59TR~
    if (cpos>=(int)offsetof(UDIRLD,UDDdate)+expandlen)             //~v59TI~
    {                                                              //~v53cI~
//    if (!getwowdslink(Ppcw,pfh,pdh,cpos,Pword,Plen,&len,Ppstrtype))//~vaudR~//~vauGR~
      if (!dirgetnameslink(Ppcw,pfh,pdh,cpos,Pword,Plen,&len,Ppstrtype,Ppdddata,Ppdddbcs,Ppddlen))//~vauGR~
      {                                                            //~vau3I~
        len=sizeof(pdd->UDDdate);                                  //~v53cI~
//      memcpy(Pword,pdd->UDDdate,(UINT)len);                      //~v59TR~
        memcpy(Pword,pddexpand->UDDdate,(UINT)len);                //~v59TI~
        *(Pword+len++)=' ';                                        //~v53cI~
        len2=sizeof(pdd->UDDtime);                                 //~v53cI~
//      memcpy(Pword+len,pdd->UDDtime,(UINT)len2);                 //~v59TR~
        memcpy(Pword+len,pddexpand->UDDtime,(UINT)len2);           //~v59TI~
        len+=len2;                                                 //~v53cI~
      }                                                            //~vau3I~
    }                                                              //~v53cI~
    else                                                           //~v53cI~
    {                                                              //~v53cI~
//    if (!getwowdslink(Ppcw,pfh,pdh,cpos,Pword,Plen,&len,Ppstrtype))//~vaudR~//~vauGR~
      if (!dirgetnameslink(Ppcw,pfh,pdh,cpos,Pword,Plen,&len,Ppstrtype,Ppdddata,Ppdddbcs,Ppddlen))//~vauGR~
      {                                                            //~vau3I~
//#ifdef AAA                                                         //~vaunI~//~vav6R~
//        if (UCBITCHK(pfh->UFHflag4,UFHF4LFN))//display lfn         //~v53cR~//~vav6R~
//#ifdef LNX                                                         //~vau3I~//~vav6R~
//          if (UCBITCHK(pdh->UDHflag3,UDHF3U8UTF))                  //~vau3R~//~vav6R~
//          {                                                        //~vau3I~//~vav6R~
//            fnm=pdh->UDHname;   //original name                    //~vau3I~//~vav6R~
//            *Ppstrtype=XEUTFCT_UTF8;                               //~vau3I~//~vav6R~
//            idx=Ppcw->UCWsplitid;                                  //~vaudI~//~vav6R~
//            ddlen=pdh->UDHnameddfmtlen;                            //~vaudR~//~vav6R~
//            pdddata=pdh->UDHnameddfmt;                             //~vaudI~//~vav6R~
//            pdddbcs=pdddata+ddlen;                                 //~vaudI~//~vav6R~
//            pddcode=wkddcode;                                      //~vaudR~//~vav6R~
//            memset(pddcode,XEUTFCT_UTF8,ddlen);                    //~vaudI~//~vav6R~
//            if (pdddata)                                           //~vaudI~//~vav6R~
//            {                                                      //~vaudI~//~vav6R~
//                int opt=idx|XEUTFSLCFEO_FILENAME|XEUTFSLCFEO_DDFMT;//~vaudR~//~vav6R~
//                xeutf_savelcctforerrmsg(opt,fnm,strlen(fnm),pdddata,pdddbcs,pddcode,ddlen);//~vaudR~//~vav6R~
//            }                                                      //~vaudI~//~vav6R~
//          }                                                        //~vau3I~//~vav6R~
//          else                                                     //~vau3I~//~vav6R~
//#endif                                                             //~vau3I~//~vav6R~
//#ifdef UTF8SUPPH                                                   //~va00I~//~vav6R~
//            fnm=PDH_UDHname(pdh);                                      //~v53cR~//~va00R~//~vav6R~
//#else                                                              //~va00I~//~vav6R~
//            fnm=pdh->UDHname;                                      //~v53cR~//~vav6R~
//#endif                                                             //~va00I~//~vav6R~
//        else                                                       //~v53cR~//~vav6R~
//            fnm=pdh->UDHALIAS;                                     //~v53cR~//~vav6R~
//        len=(int)strlen(fnm);                                      //~v58jR~//~vav6R~
//        if (len>Plen)                                              //~v53cR~//~vav6R~
//        {                                                          //~v53cR~//~vav6R~
//            errtoolong();                                          //~v53cR~//~vav6R~
//            return 0;                                              //~v53cR~//~vav6R~
//        }                                                          //~v53cR~//~vav6R~
//        memcpy(Pword,fnm,(UINT)len);                               //~v53cR~//~vav6R~
//#else                                                              //~vaunI~//~vav6R~
        errcsrpos();                                               //~vaunI~
//#endif                                                             //~vaunI~//~vav6R~
      }                                                            //~vau3I~
    }                                                              //~v53cI~
    UTRACED("Pword",Pword,len);                                    //~vaujI~
    return len;                                                    //~v53cI~
}//dirgetword                                                      //~v53cI~
//**************************************************************** //~v55mI~
// dirvsplitshift                                                  //~v55mI~
//*setup for file screen vsplit(cmd line scroll size)              //~v55mI~
//*parm1:PUCLIENTWE                                                //~v55mI~
//*rc   :none                                                      //~v55mI~
//**************************************************************** //~v55mI~
void dirvsplitshift(PUCLIENTWE Ppcw)                               //~v55mR~
{                                                                  //~v55mI~
static int Scmdpos=0,Scmdend;                                      //~v55mI~
static int Sscrolltlen,Sscrollhlen,Sscrolldlen;                    //~v55mI~
    UFLDE *pflescrol,*pflecmd;	//scroll,cmd field                 //~v55mI~
	int width,prevwidth,cmdend,prevcmdend;                         //~v55mI~
    int lenw;                                                      //~v55mI~
	PUSCRD psd;                                                    //~v55mI~
	UCHAR  *pc;                                                    //~v55mI~
	PUPANELC  ppc;                                                 //~v55mI~
	PUFILEC  pfc;                                                  //~v55mI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    int resizesw=0;                                                //~v55mI~
    int pfcresizesw;                                               //~v621I~
#endif                                                             //~v55mI~
	int resetsw;                                                   //~v56rI~
    int fnmendpos;                                                 //~vb7jI~
//******************                                               //~v55mI~
	pfc=Ppcw->UCWpfc;		//for csrpos disp                      //~v55mI~
	psd=Ppcw->UCWpsd;		//hdr line                             //~v55mI~
    if ((resetsw=UCBITCHK(pfc->UFCflag2,UFCF2PPCRESET))!=0)  //usdbuff reset done//~v56rI~
	    UCBITOFF(pfc->UFCflag2,UFCF2PPCRESET);  //usdbuff reset done//~v56rI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	pfcresizesw=UCBITCHK(pfc->UFCflag2,UFCF2RESIZE);               //~v621I~
	UCBITOFF(pfc->UFCflag2,UFCF2RESIZE);                           //~v621I~
//  if (!Scmdpos || Sresizesw)                                     //~v621R~
    if (!Scmdpos || pfcresizesw)                                   //~v621I~
    {                                                              //~v56pR~
//      resizesw=Sresizesw;                                        //~v621R~
        resizesw=pfcresizesw;                                      //~v621I~
//  	Sresizesw=0;	//set once at wakeup                       //~v59TR~
#else                                                              //~v56pR~
	if (!Scmdpos)		//first time any way                       //~v56pR~
    {                                                              //~v56pR~
#endif                                                             //~v56pR~
		pflecmd=getuflde(Ppcw,CMDLINENO,0);	//cmd fld.             //~v55mI~
		pflescrol=getuflde(Ppcw,CMDLINENO,1);	//scroll fld       //~v55mI~
		Scmdpos=pflecmd->UFLstart;                                 //~v55mI~
		Scmdend=pflecmd->UFLend;                                   //~v55mI~
		Sscrolltlen=Gscrwidth-Scmdend;//scroll hdr/data field len  //~v55mI~
		Sscrollhlen=pflescrol->UFLstart-Scmdend;                   //~v55mI~
		Sscrolldlen=pflescrol->UFLend-pflescrol->UFLstart;         //~v55mI~
    }                                                              //~v55mI~
	width=Ppcw->UCWwidth;                                          //~v55mI~
	prevwidth=pfc->UFCprevwidth;                                   //~v55mI~
    fnmendpos=pfc->UFCcsrposdisp;                                  //~vb7jM~
    if (!fnmendpos)                                                //~vb7jM~
    	fnmendpos=width-COLUMNDISPPOSDIR; //=4       //" Rep"      //~vb7jM~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
  if (!resizesw)                                                   //~v56pI~
#endif                                                             //~v56pI~
   if (!resetsw) //usdbuff reset done                              //~v56rI~
    if (width==prevwidth)             //vsplit width not changed   //~v55mI~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
//  	fileutf8vsplithdrattr(0,Ppcw,psd,pfc->UFCpfh,width);       //~va00I~//~vb7jR~
    	fileutf8vsplithdrattr(0,Ppcw,psd,pfc->UFCpfh,fnmendpos);   //+vb7jR~
#endif                                                             //~va00I~
		return;                      //if act reset uflde          //~v55mI~
    }                                                              //~va00I~
	pfc->UFCprevwidth=width;                                       //~v55mI~
#ifdef UTF8SUPPH                                                   //~va00I~
//  fileutf8vsplithdrattr(FUVSHAO_CHNGWIDTH,Ppcw,psd,pfc->UFCpfh,width);//~va00I~//~vb7jR~
    fileutf8vsplithdrattr(FUVSHAO_CHNGWIDTH,Ppcw,psd,pfc->UFCpfh,fnmendpos);//~vb7jI~
#endif                                                             //~va00I~
//*cmd line scroll display                                         //~v55mI~
	if ((cmdend=width-Sscrolltlen)>Scmdpos)	//scroll can display   //~v55mI~
	{                                                              //~v55mI~
        pflecmd=getuflde(Ppcw,CMDLINENO,0); //cmd fld.             //~v55mI~
        pflescrol=getuflde(Ppcw,CMDLINENO,1);   //scroll fld       //~v55mI~
        pflecmd->UFLend=cmdend;             //save for next        //~v55mI~
        pflescrol->UFLstart=cmdend+Sscrollhlen;                    //~v55mI~
        pflescrol->UFLend=pflescrol->UFLstart+Sscrolldlen;         //~v55mI~
	}                                                              //~v55mI~
	else                                                           //~v55mI~
	{                                                              //~v55mI~
		pflecmd=getuflde(Ppcw,CMDLINENO,0);	//cmd fld.             //~v55mI~
		pflescrol=getuflde(Ppcw,CMDLINENO,1);	//scroll fld       //~v55mI~
		if (width<=Scmdpos)		//no input fld                     //~v55mI~
		{                                                          //~v55mI~
			cmdend=Scmdpos;                                        //~v55mI~
            pflecmd->UFLend=pflecmd->UFLstart;  //force len=0      //~v55mI~
		}                                                          //~v55mI~
		else	//cmd input only                                   //~v55mI~
		{                                                          //~v55mI~
			cmdend=width;                                          //~v55mI~
            pflecmd->UFLend=width;                                 //~v55mI~
		}                                                          //~v55mI~
        pflescrol->UFLstart=cmdend+Sscrollhlen;                    //~v55mI~
        pflescrol->UFLend=pflescrol->UFLstart+Sscrolldlen;         //~v55mI~
	}                                                              //~v55mI~
	prevcmdend=pfc->UFCscrolldisp;                                 //~v55mI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
  if (!resizesw)                                                   //~v56pI~
#endif                                                             //~v56pI~
	if (cmdend==prevcmdend)		//scroll disp pos not changed      //~v55mI~
		return;                                                    //~v55mI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
	if (!prevcmdend||resizesw)//when resize,ppd_init is done       //~v56pI~
#else                                                              //~v56pI~
	if (!prevcmdend)                                               //~v55mI~
#endif                                                             //~v56pI~
		prevcmdend=Scmdend;                                        //~v55mI~
	pfc->UFCscrolldisp=cmdend;                                     //~v55mI~
	if (cmdend==Scmdpos)		//scroll cannot display            //~v55mI~
		return;                                                    //~v55mI~
//#ifdef WXE                                                       //~v64iR~
#ifdef WXEXXE                                                      //~v64iR~
    if (resizesw)                                                  //~v55mR~
      	if (width==Gscrwidth)    //resize rtn already set,but cotinue process required for vsplit//~v55mI~
        	return;         //pan_resize rest scroll field         //~v55mI~
#endif                                                             //~v55mI~
	psd++;                                                         //~v55mI~
	pc=psd->USDbuffc;                                              //~v55mI~
	if (cmdend>prevcmdend)			//expanded                     //~v55mI~
	{                                                              //~v55mI~
		memmove(pc+cmdend,pc+prevcmdend,(UINT)Sscrolltlen);        //~v55mI~
		memset(pc+prevcmdend,0,(UINT)(cmdend-prevcmdend));         //~v55mI~
	}                                                              //~v55mI~
	else                                                           //~v55mI~
	{							//forward copy                     //~v55mI~
		memcpy(pc+cmdend,pc+prevcmdend,(UINT)Sscrolltlen);         //~v55mI~
    	lenw=Gscrwidth-(cmdend+Sscrolltlen);                       //~v55mI~
        if (lenw<0)                                                //~v55mI~
        	lenw=0;                                                //~v55mI~
    	memset(pc+cmdend+Sscrolltlen,0,(UINT)lenw);                //~v55mI~
	}                                                              //~v55mI~
	ppc=Ppcw->UCWppc;                                              //~v55mI~
	memset(ppc->UPCline[CMDLINENO].UPLdbcs+cmdend,0,               //~v55mI~
			(UINT)(Gscrwidth-cmdend));                             //~v55mI~
	return;                                                        //~v55mI~
}//dirvsplitshift                                                  //~v55mI~
//#ifdef LNX                                                         //~vau0I~//~vauER~
//**************************************************************** //~vau0I~
//*draw rename field on psd at not renamesave status               //~vau0I~
//**************************************************************** //~vau0I~
void drawrenameDDFMT(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,char *Ppsddata,char *Ppsddbcs,int Plen)//~vau0R~//~vau1R~
{                                                                  //~vau0I~
    UCHAR   *pc,*pcd,*pu8,*pct,*pdddata,*pdddbcs;                  //~vau0R~
	int lenu8,ct,lenlc,opt,lendd,offs;                          //~vau0R~//~vawaR~
    int lenlcdata;                                                 //~vawqI~
//************************                                         //~vau0I~
	pu8=Ppdh->UDHrename_utf8;                                      //~vau0I~
    pct=Ppdh->UDHrename_codetype;                                  //~vau0I~
//  lenu8=strlen(pu8);                                             //~vau0I~//~vb2pR~
    lenu8=(int)strlen(pu8);                                        //~vb2pI~
	UTRACED("drawrenameDDFMT utf8",pu8,lenu8);                     //~vau0I~
	UTRACED("drawrenameDDFMT pct",pct,lenu8);                      //~vau0I~
    if (!(lenlc=dirgetfldpos(Ppcw,Pplh,PANL310RENAME,&pc,&pcd)))   //~vawqI~
        return;             //fld no err                           //~vawqI~
//  lenlcdata=strlen(pc);                                          //~vawqI~//~vb2pR~
    lenlcdata=(int)strlen(pc);                                     //~vb2pI~
    ct=0;                                                          //~vau0I~
//  if (memchr(pct,XEUTFCT_UTF8,lenu8))                            //~vau0I~//~vawqR~
//  if (memchr(pct,XEUTFCT_UTF8,lenlcdata))                        //~vawqI~//~vb2pR~
    if (memchr(pct,XEUTFCT_UTF8,(size_t)lenlcdata))                //~vb2pI~
    	ct|=XEUTFCT_UTF8;                                          //~vau0I~
//  if (memchr(pct,XEUTFCT_LC,lenu8))                              //~vau0I~//~vawqR~
//  if (memchr(pct,XEUTFCT_LC,lenlcdata))                          //~vawqI~//~vb2pR~
    if (memchr(pct,XEUTFCT_LC,(size_t)lenlcdata))                  //~vb2pI~
    	ct|=XEUTFCT_LC;                                            //~vau0I~
    if (!ct)                                                       //~vau0I~
    	return;	//all ascii                                        //~vau0I~
//    if (!UCBITCHK(Ppdh->UDHflag4,UDHF4DDFMT))   //once by dirsetupdd//~vau0I~//~vau1R~
//        if (!(ct & XEUTFCT_UTF8))   //not utf8 code                //~vau0I~//~vau1R~
//            return; //no need to display by ddfmt                  //~vau0I~//~vau1R~
//*set ddfmt                                                       //~vau0I~
//  if (!(lenlc=dirgetfldpos(Ppcw,Pplh,PANL310RENAME,&pc,&pcd)))   //~vau0I~//~vawqR~
//      return;             //fld no err                           //~vau0I~//~vawqR~
    UTRACED("drawrenameDDFMT getflddata data",pc,lenlc);           //~vau0I~
    UTRACED("drawrenameDDFMT getflddata dbcs",pcd,lenlc);          //~vau0I~
    opt=0;                                                         //~vau0I~
#ifdef AAA                                                         //~vawaI~
    if (ct & XEUTFCT_LC)	//not utf8 code                        //~vau0I~
    {                                                              //~vau0I~
		rc=xeutfcvl2dd(opt,pc,lenlc,&pdddata,&pdddbcs,&lendd);     //~vau0I~
    	if (rc>(UTFCVFDRC_UTF8|UTFCVRC_DBCS))                      //~vau0I~
    		return;                                                //~vau0I~
    }                                                              //~vau0I~
    else                                                           //~vau0I~
    {                                                              //~vau0I~
		rc=xeutf_cvf2dd(opt,pu8,lenu8,&pdddata,&pdddbcs,&lendd);   //~vau0I~
    	if (rc>(UTFCVFDRC_UTF8|UTFCVRC_DBCS))                      //~vau0I~
    		return;                                                //~vau0R~
    }                                                              //~vau0I~
#else                                                              //~vawaI~
//  opt=XEUTFLF2DO_CHKLCLENBYF2L;   //advance ct by the length of F2L outlen;//pct was adjusted for ddstr//~vawkR~
//	xeutfcvlf2dd(0,pu8,lenu8,pcd,pct,strlen(pc),                   //~vawjR~
//	xeutfcvlf2dd(opt,pu8,lenu8,pcd,pct,strlen(pc),                 //~vawjI~//~vawqR~
  	xeutfcvlf2dd(opt,pu8,lenu8,pcd,pct,lenlcdata,                  //~vawqI~
					&pdddata,&pdddbcs,Plen,&lendd);                //~vawaI~
#endif                                                             //~vawaI~
    offs=PTRDIFF(pc,Pplh->ULHdata);                                //~vau0I~
    lendd=min(lendd,Plen);                                         //~vau1I~
//  lenlc=strlen(Ppsddata+offs);  //actual lc strlen               //~vawjI~//~vb2pR~
    lenlc=(int)strlen(Ppsddata+offs);  //actual lc strlen          //~vb2pI~
//  memcpy(Ppsddata+offs,pdddata,lendd);                           //~vau0R~//~vb2pR~
    memcpy(Ppsddata+offs,pdddata,(size_t)lendd);                   //~vb2pI~
//  memcpy(Ppsddbcs+offs,pdddbcs,lendd);                           //~vau0R~//~vb2pR~
    memcpy(Ppsddbcs+offs,pdddbcs,(size_t)lendd);                   //~vb2pI~
    if (lenlc>lendd)    //clear lcdata                             //~vawjI~
    {                                                              //~vawjI~
    	lenlc-=lendd;                                              //~vawjI~
//  	memset(Ppsddata+offs+lendd,0,lenlc);                       //~vawjI~//~vb2pR~
    	memset(Ppsddata+offs+lendd,0,(size_t)lenlc);               //~vb2pI~
//  	memset(Ppsddbcs+offs+lendd,0,lenlc);                       //~vawjI~//~vb2pR~
    	memset(Ppsddbcs+offs+lendd,0,(size_t)lenlc);               //~vb2pI~
    }                                                              //~vawjI~
	UTRACED("drawrenameDDFMT dddata",Ppsddata+offs,lendd);         //~vau0R~
	UTRACED("drawrenameDDFMT dddbcs",Ppsddbcs+offs,lendd);         //~vau0R~
}//drawrenameDDFMT                                                 //~vau0I~
//**************************************************************** //~vawaI~
//*draw rename field on psd at not renamesave status from UDhrenameddfmt//~vawaI~
//**************************************************************** //~vawaI~
void drawrenameDDFMT2(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,char *Ppsddata,char *Ppsddbcs,int Plen)//~vawaI~
{                                                                  //~vawaI~
    UCHAR  *pdddata,*pdddbcs;                                      //~vawaI~
	int len,lendd,offs;                                            //~vawaI~
//************************                                         //~vawaI~
	offs=dirgetfldoffs(Ppcw,Pplh,PANL310RENAME);                   //~vawaI~
    if (offs<=0)                                                   //~vawaR~
    	return;                                                    //~vawaI~
    lendd=Ppdh->UDHrenameddfmtlen;                                 //~vawaI~
    pdddata=Ppdh->UDHrenameddfmt;                                  //~vawaI~
    if (!pdddata)                                                  //~vawaI~
    	return;                                                    //~vawaI~
    if (!lendd)                                                    //~vawaI~
    	return;                                                    //~vawaI~
    pdddbcs=pdddata+lendd;                                         //~vawaI~
    len=min(lendd,Plen-offs);                                      //~vawaI~
//  memcpy(Ppsddata+offs,pdddata,len);                             //~vawaI~//~vb2pR~
    memcpy(Ppsddata+offs,pdddata,(size_t)len);                     //~vb2pI~
//  memcpy(Ppsddbcs+offs,pdddbcs,len);                             //~vawaI~//~vb2pR~
    memcpy(Ppsddbcs+offs,pdddbcs,(size_t)len);                     //~vb2pI~
	UTRACED("out dddata",Ppsddata+offs,len);                       //~vawaI~
	UTRACED("out dddbcs",Ppsddbcs+offs,len);                       //~vawaI~
}//drawrenameDDFMT2                                                //~vawaI~
//#endif LNX                                                             //~vau0I~//~vauER~
#ifdef LNX                                                         //~vauBI~
#else                                                              //~vauBI~
#ifdef CCC                                                         //~vauEI~
//*****************************************************************//~vauBI~
//*Win:utf8 membername save for errmsg                             //~vauBI~
//*****************************************************************//~vauBI~
void xedir_savelcctforerrmsg(int Popt,PUCLIENTWE Ppcw,PUDIRLH Ppdh,char *Pfnm,int Plen)//~vauBR~
{                                                                  //~vauBI~
	UCHAR   *pu8,*plc;                                             //~vauBI~
    char wkcodetb[_MAX_PATH];                                      //~vauBI~
    int lclen,opt,idx;                                             //~vauBR~
//**************************************                           //~vauBI~
	pu8=Pfnm;                                                      //~vauBI~
	if (Popt & XEDSFEO_FNM)                                        //~vauBI~
    {                                                              //~vauBI~
    	plc=Ppdh->UDHnamef2l;                                      //~vauBI~
    	lclen=strlen(plc);                                         //~vauBR~
    }                                                              //~vauBI~
    else                                                           //~vauBI~
    {                                                              //~vauBI~
    	plc=Ppdh->UDHslink;	//f2l when slink original is utf8      //~vauBR~
    	lclen=strlen(plc);                                         //~vauBI~
    }                                                              //~vauBI~
	UTRACEP("xedir_savelcctforerrmsg u8=%s,lc=%s\n",pu8,plc);      //~vauBI~
    memset(wkcodetb,XEUTFCT_UTF8,lclen);                           //~vauBI~
	idx=Ppcw->UCWsplitid;                                          //~vauBI~
	opt=idx|XEUTFSLCFEO_FILENAME;                                  //~vauBI~
	xeutf_savelcctforerrmsg(opt,pu8,Plen,plc,NULL/*dddbcs*/,wkcodetb,lclen);//~vauBI~
}//xedir_savelcctforerrmsg                                         //~vauBI~
#endif	//CCC                                                      //~vauEI~
#endif	//!LNX                                                     //~vauBI~
//*****************************************************************//~vawpI~
//*getmixedstring betercodetype                                    //~vawpI~
//*****************************************************************//~vawpI~
int dirgetmixstropt(int Popt,PULINEH Pplh,char *Pdata)             //~vawpI~
{                                                                  //~vawpI~
	PUFILEH pfh;                                                   //~vawpI~
    int rc;                                                        //~vawpI~
//******************	                                           //~vawpI~
	pfh=UGETPFH(Pplh);                                             //~vawpI~
    rc=xeutfgetmixstrctopt(Popt,pfh);                              //~vawpI~
    UTRACEP("%s:rc=%x,u8=%s\n",UTT,rc,Pdata);                      //~vawpR~
    return rc;                                                     //~vawpI~
}//dirgetmixstropt                                                 //~vawpI~
