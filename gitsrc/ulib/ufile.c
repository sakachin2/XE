//*CID://+v783R~:                             update#=  646;       //~v783R~
//*************************************************************
//*ufile.c                                                         //~v5d1R~
//*************************************************************    //~v053R~
//v783:230721 (Bug) v781 not fix it. ignore "." entry              //~v783I~
//v781:230720 (Bug)del dir fail by errmsg of "no entry but other attr exist" when dir contains only one dir//~v781I~
//            ==>del is not to delete dir, xdd do it. so this is not used//~v781I~
//v77A:230602 ARM;share storage readdir returns no entry of "." or ".." and issue "no entry", the dirlist was not show. set rc=0 to show list by xedir:loaddir//~v77AI~
//v77j:230428 ARM;udirlist by opendir optionally                   //~v77jI~
//v77a:230415 split ufile1l to ufiledoc                            //~v77aI~
//v779:230414 update v777,set uri at ulib fro shortpath            //~v779I~
//v777:230403 ARM;udirlistFD                                       //~v777I~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6H7:170108 FTP crush by long name                               //~v6H7I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6H4:170105 wildexp return toolong rc=8                          //~v6H4I~
//v6H2:170103 (BUG)uparsefname cut last 1 byte for len=259(_MAX_MATH-1)//~v6H2I~
//v6Ex:160819 (FTP)-l option was ignore for "e xxx*" patern. smb "dir x2*" losses "x2*",vsftp dose not lose "x2*"//~v6ExI~
//            Bypass chk by ufstat_wild() for ftp, it means always -l even x2* exists.//~v6ExI~
//v6B9:160121 (LNX)new ufullpathCP function to chk optionally filesystem iocharset  convert to utf8 from locale code//~v6B9I~
//v6yg:150314 avoid \\.\ is displayed on errmsg                    //~v6ygI~
//v6yb:150313 new func "ugetcwdW" to retun dropped \\.\ prefix     //~v6ybI~
//v6y0:150221 (BUG) chdrive crash for "::"                         //~v6y0I~
//v6uZ:140618 (Win)for GetLastError=x15(21),issue errmsg device not ready//~v6uZI~
//v6uJ:140602 for UAC;permission errmsg for dosfindfirst           //~v6uJI~
//v6uH:140530 (BUG:W32)symlink targer err msg when relative depending CWD,symlink relative path base is slink path//~v6uHI~
//v6uG:140530 (BUG:W32)loop  ufstat-->getslink-->ufstat            //~v6uGI~
//v6uD:140524 set pslinkW=0 if pslinkctrW=0 for performance        //~v6uDI~
//v6uC:140524 (BUG of v6u0)duplicate ufree pslinkW(dirwalk free member,then walk into subdir,the free it)//~v6uCI~
//v6uk:140501 (Win:UNICODE)UNC name should be ucs2 for root        //~v6ukI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW          //~v6uaI~
//v6u6:140401 (Win)FindFileFirst fail for UNC root(\\server\share) and//~v6u6R~
//             LastErr=123(InvalidName) for \\server but 53(BAD_NETPATH) for \\server\share//~v6u6R~
//v6u3:140401 (Win:slink)ufstat for wildcard should use found name to get slink name for it(fail if used widlcard name)//~v6u3I~
//v6u1:140331 (Win:BUG) of v6d8; rootsw set err                    //~v6u1I~
//v6qb:131205 chk max filectr to avoid malloc size over uerrexit when 32bit mode(see v6q9)//~v6qbI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6q0:131126 (WIN)fails to delete wildcard entry;use shortname    //~v6q0I~
//v6km:130704 notfound msg --> dir exist but no file exist;for xcopy wildcard parm sepcified//~v6kmI~
//v6kg:130629 errno=5(ioerr) when symlink created by mklink /D(dir) to a file//~v6kgI~
//v6kc:130625 slink err flag by ufstat(0x0200)                     //~v6kcI~
//v6ka:130624 identify slink err by ftime=fdate=0                  //~v6kaI~
//v6k8:130623 junction is link to dir,so issue errmsg for junction to file//~v6k8I~
//v6k7:130622 udosfindfirstnomsg is not effectiv for udosfindnext  //~v6k7I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//v6hL:120917 chk and errmsg when too long fullpath                //~v6hLI~
//v6hv:120808 (WIN)FileTimeToDosDateTime round up to next 2sec;it display different timestamp with dir cmd on cmd prompt//~v6hvI~
//v6ht:120729 (LNX)display odd number file time stamp              //~v6htI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hd:120616 for VC6:/W4 warning(C4189)                           //~v6hdI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6d8:120211 "invalid name" err msg when UNC path is share root such as \\192.168.8.44\p//~v6d8I~
//v6d3:120205 (BUG of v6d1)LNX 0c4 when wildcard for ftp           //~v6d3I~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v62Y:091113 (UTF8:WIN)_fullpath may drop UTF8 char,              //~v62YI~
//                      for ex, e38182-e3818a-e38184(JapaneseHiragana a-o-i)-->e38182-e3818a-e38100//~v62YI~
//                              e38182(JapaneHiragana a)-->e38100  //~v62YI~
//            ==>modified by original name, but created file is dropped name as aresult//~v62YI~
//v5nB:081208 avoid network search twice for invalid network path  //~v5nBI~
//v5nu:081107 (Win)\\x\y remote filename support(support also driveid \: for CDRIVE/CDIR)//~v5nuI~
//v5kd:070518 (LNX:BUG)intermediate ../ is not resolved(linux understand but xe display ../ as it is)//~v5kdI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5jc:061002 3270 support:dsn wildcard support                    //~v5jcI~
//v5j4:060915 ftp:3270 support (xehost TSO=portno operand)         //~v5j4I~
//v5fv:050323 delete UTRACE(it is before trace init by xe)         //~v5fvI~
//v5ft:050321 (WIN:BUG)win95/win95 return normal for driveid assigned remote shared dir//~v5fsI~
//            so open err issued.                                  //~v5fsI~
//v5fs:050321 (WIN-FTP:BUG)xcopy download replace fail by target is special file//~v5fsI~
//v5f6:041127 append mode redirect support                         //~v5f6I~
//v5dh:040610 (AIX:BUG)dir sort by timestamp should consider AIX FTIME/FDATE in int//~v5dhI~
//v5d1:040526 new func to get parent pathname                      //~v5d1I~
//v5cy:040521 add dirlist sort option by T(Date&Time+Name),Z(Size+Name)//~v5cyI~
//v5ct:040509 (FTP:BUG)missing remote file logic for wildcard expansion for only one member//~v5ctI~
//v5ce:040503 malloc +1 dirlist entry for safety end of list chk   //~v5ceI~
//v5ai:040108 clear not used slink area clear on ufstat            //~v5aiI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v5aa:040104 integrate PATHLEN,FTP_PATHLEN-->PATHLEN              //~v5aaI~
//v5a6:040104 (UNX,FTP)save slink uid,gid,uname,gname on dirlist for xe dirlist//~v5a6I~
//v5a5:040103 (BUG:UNX)dirlist missing slink size/ts               //~v5a5I~
//v59z:040102 fdateedit:4 digit year support                       //~v59zI~
//v59x:040101 (UNX,FTP)save slink timestamp and size for dirlist for xe//~v59xI~
//v59v:031223 (WIN)ROOTDIR support both ftp remote and local       //~v59vI~
//v59n:031109 ftp support:ufstat,udirlist                          //~v59nI~
//v59i:031108 ftp support:add username etc to windows udirlist/ffb3//~v59iI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v57n:030112 (WIN:BUG)dosfindfirst return rc=66(invalid dev) for net drive root//~v57nI~
//v578:021207 (UNX)udirlist performance tuning(stat call on the current dir)//~v578R~
//v576:021201 (BUG)ufullpathwildexp fail when dir is SYSTEM or HIDDEN//~v576I~
//v56p:020711 (UNX) udirwalk;chk permission before udirlist to avoid double err msg.//~v56pI~
//v56n:020711 (UNX:BUG) xff loop by FIFO file.it is slink,so not chked.//~v55nI~
//v55j:020501 (UNX)dirlist sort by case insensitive for mdos disk  //~v55jI~
//v547:020330 (WIN/OS2)keep ctime(creatio time)/atime(last access time) for xff cmd//~v547R~
//v545:020328 (BUG)atime/mtime/ctime set missing                   //~v545R~
//v539:020324 rc for wildexp;2:multiple last path,3:multiple intermediate path//~v539I~
//v50F:010618 add function of fullpath expand wild card            //~v50FI~
//v50E:010616 LNX:return symbolic link attr/name for dir list      //~v50EI~
//v393:001103 LINUX support:dirlist sort by case sensitive         //~v393I~
//            (DOS return by uppercase;win is LFN;so memicmp for os2 only)//~v393I~
//v372:000928 LINUX support(keep uid/gid/fsid in dirlist)          //~v372I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v352:000926 LINUX support(permission err msg)                    //~v352I~
//v328 000826:LINUX:gcc detected warning:uninitialized var         //~v328I~
//v327 000820:LINUX support;move followings to ufilel.c            //~v327I~
//            ufstat,ufullpath,ugetdrive,ugetcwd,uchdrive,uchdir   //~v327I~
//            udosfindfirst,udosfindnext                           //~v327I~
//v295:991106 No trouble,but it should be closed for findfirst of ufstat//~v295I~
//v251:990626 (BUG):stderr handle not saved when req=3(stdout and stderr)//~v251I~
//v249:990626 (BUG):close for redirect cause 0c4 because buff is freeed.//~v249I~
//                  for protect line mixed,use flush before redirect save and restore//~v249R~
//v245:990619 fclose required for redirected to also win           //~v245I~
//v233:990410 (BUG)/-->\ conversion required for filename under dos/gcc//~v233I~
//v231:990320 (BUG)dirlist seq err when $(0x24) etc used;(<'.'(0x2e)=curr dir)//~v231I~
//v197:980923 (BUG:WIN)V079 say "Win FindFirstFile ignore attr parm,so retry by findnext"//~v197I~
//            but udosfindnext return rc=4 when nomore file and it cause errmsg//~v197I~
//            DosFindFirst failed msg.;                            //~v197I~
//            so rc set ERR_FIEL_NOT_FOUND for rc=4                //~v197I~
//v183:980613 (BUG) of v179 if/else position                       //~v179I~
//v179:980505 no msg (not found msg) vaersion of udosfindfirst/udirlist//~v132I~
//v132:971220 (BUG)file date edit year                             //~v132I~
//v124:971130 (BUG:W95)need once register before call findnext     //~v124I~
//                     when findfirst gotten attr unmatch.         //~v124I~
//                     (if req attr has not dir bit bug occur)     //~v124I~
//v123:971125 udosfindfirst/udosfindnext should return rc=errno for DOS//~v123I~
//v117:971109 new function uparsefname(drop quatation);use for also v116//~v117I~
//v116:971109 accept filename enclosed by quatation like as a\"b c".//~v116I~
//v115:971109 new dirlist sort option('L');simple longname compare(OS/2,W95,GCC)//~v115I~
//v113:971103 release dir filename compare func udircomp for dirlist sort/merge//~v113I~
//v109:971103 (GCC:BUG)truepath need . for get cur dir of other drive//~v109I~
//                     "k:" faile,"k:." is ok.(under DOS only)     //~v109I~
//v105:971026 (GCC)lfn support                                     //~v105I~
//           -drop CRT0_NO_LFN                                     //~v105I~
//           -use _truename to get cur dirname by lfn(alternative of int21 47h)//~v105I~
//           -use modified findfirst/findnext(both name return)    //~v105I~
//           -dislist sort by alias(same as W95)                   //~v105I~
//v104:971025 _MAX_PATH is contain NULL term;change _MAX_PATH+1-->_MAX_PATH//~v104I~
//v101:971009 long filename                                        //~v101I~
//            ufile.c :udircompare;sort file name by base and ext(after last .)//~v101I~
//                     return long file name for udirlist          //~v101I~
//                     dirlist sort is case insensitive for os2    //~v101I~
//                     dirlist sort is by alias for w95            //~v101I~
//v087:970621 (BUG:W95 only)findfirst handle overflow(it was not cleared)//~v087I~
//            And also need to save when not required returning handle.//~v087I~
//v079:970501 difference between W95 FindFirstFile/FindNextFile and//~v079I~
//            DOS _dos_find_first/_dos?find_next about attribute selection//~v079I~
//            DOS select exact match if S,H,SH,D specified.W95 return all file.//~v079I~
//            So dos selection under W95.                          //~v079I~
//v078:970529 support filename including space(see also v020,chck th case at caller)//~v078I~
//            os/2 _fullpath drop trailing space,but dos dose not  //~v078I~
//v068:970222:ufstat change ffbf3 to optional parm,use as file_exist func//~v068I~
//v067:970215:(BUG)dir sort compare('E' type sort)                 //~v067I~
//            add 'S' type                                         //~v067I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -dup2 return new handle (not 0)(msc return 0 if ok)  //~v053I~
//            -dosfindfirst/dosfindnext may return 38(ENMFILE)     //~v053I~
//            -getcwd return / for \ like unix,so use intdos       //~v053I~
//            -REGS/SREG for intdos/int86 is DWORD long and parm is flat addr//~v053I~
//            -getcwd,chdir,dup,dup2,rmdir is on unistd.h          //~v053I~
//            -errno value is not same as DOS                      //~v053I~
//            -external synbole value for fine name case etc       //~v053I~
//v049:961201:(W95)fullpath function return with last \ for dir same as dos//~v036I~
//            and findfirst faile so drop it like as os/2.         //~v036I~
//v036:961016:new member for errmsg of ufile_.c                    //~v036I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v020:960721:BUG of OS/2 _fullpath,"fnm /y"-->"fnm\y"             //~v019R~
//v019:960714:BUG of OS/2 _fullpath,rc=60 if last is dbcs 2nd byte \ like as 噂//~v327R~
//v018:960714:other case need to chk DBCS 2nd byte '\'             //~v018I~
//v016:960211:(BUG)PATHLEN need chk dbcs 2nd byte '\',ex 噂        //~v327R~
//v003:960519:v001 is spec not bug for DOS 6.3.                    //~v003I~
//v002:960519:(DOS)findfirst may return dir flag depending on file seq in dir//~v002I~
//            reset dir flag for ufstat                            //~v002I~
//v001:960519:ufullpath:add .* for x*                              //~v001R~
//           (under DOS6.3 x* is not same as x*.*,OS/2 and DOS5.0 is same)//~v001R~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950826:ufstat:clear findbuf3 when err for present no attr    //~5826R~
//*950817:bug,dont strupr for DBCS filename,it cause (デ-->ェ)  //~5817I~
//*950708:uchdrive,uchdir support                               //~5708I~
//*950701:ufullpath same output as os2(no \\ at last,\\ for root)//~5701I~
//*950628:uerrexit->uerrmsg for dos current dir                 //~5628I~
//*950625:ufdateedit/uftimeedit                                 //~5625I~
//*      :uerrexit->uerrmsg                                     //~5625I~
//*950616:file search option set bug,not || but |               //~5617R~
//*950617:free dirlist when dosfindfirst err                    //~5618I~
//************************************************************* //~5617I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                                 //~v327M~
#ifdef UNX  //!!!!!!!!!!!!!!!!!!                                   //~v327M~
    #include <unistd.h>                                            //~v327I~
	#include <dirent.h>                                            //~v6b1I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~v327M~
//*******************************************************          //~v327M~
#include <direct.h>                                             //~5708I~
#include <io.h>                                                 //~5A14I~
                                                                   //~v327I~
#ifdef DOS
    #include <dos.h>
    #ifdef DPMI                 //DPMI version                     //~v053I~
        #include <unistd.h>                                        //~v053I~
        #include <crt0.h>                                          //~v053R~
        #include <sys/stat.h>   //_truename                        //~v105I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#else
    #ifdef W32                                                     //~v022I~
        #include <dos.h>                                           //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034M~
            #include <direct.h>     //_getdrive                    //~v034M~
            #include <windows.h>                                   //~v034I~
            #include <wchar.h>                                     //~v6H9I~
        #endif                                                     //~v034M~
    #else                                                          //~v022I~
    #define INCL_BASE
    #include <os2.h>
    #endif                                                         //~v022I~
#endif
#endif //!!!!!!!!!!!!!!!!!!                                        //~v327I~

//*******************************************************
//for ufile.h ,generate gbl                                     //~5826I~
#define UFILE_SELF                                              //~5826I~
#include <ulib.h>
#include <ufile.h>
#include <uque.h>                                                  //~v779I~
#ifdef UNX                                                         //~v6b1I~
	#include <ufile1l.h>                                           //~v6b1R~
#endif                                                             //~v6b1R~
#ifdef ARMXXE                                                      //~v77aI~
	#include <ufiledoc.h>                                          //~v77aI~
#endif                                                             //~v77aI~
#include <ufile2.h>                                             //~5A14I~
#include <ufile3.h>                                                //~v6hvI~
#include <ufile4.h>                                                //~v105I~
#include <ufile5.h>                                                //~v5nuI~
#include <ufemsg.h>                                                //~v036I~
#include <uerr.h>
#include <ualloc.h>
#include <ustring.h>                                               //~v016R~
#include <utrace.h>                                                //~v036I~
#include <uparse.h>         //uparsefname                          //~v117I~
//#include <uque.h>                                                  //~v59nI~//~v779R~
#include <udos.h>                                                  //~v5fsI~
#include <ucvext.h>                                                //~v6uaI~
#ifdef DPMI                 //DPMI version                         //~v053I~
    #include <udpmisub.h>                                          //~v053I~
    #include <udpmilb3.h>   //udpmifindfirst/next                  //~v105I~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
#ifdef UNX  //!!!!!!!!!!!!!!!!!!                                   //~v327I~
    #include <ugcclib.h>                                           //~v327I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#endif      //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#ifdef FTPSUPP                                                     //~v59nI~
    #include <uftp.h>                                              //~v59nI~
    #include <ufile1f.h>                                           //~v59nR~
    #include <u3270.h>                                             //~v5jcI~
#endif                                                             //~v59nI~
#include <uwinsub.h>                                               //~v6k4I~
                                                                   //~v6uaI~
#define REDIRECT_FINDFILE                                          //~v6uaR~
#include <ufilew.h>                                                //~v6uaR~
                                                                   //~v6uaI~
//*******************************************************
#ifdef UNX  //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#ifdef DOS
    #ifdef DPMI                 //DPMI version                     //~v053R~
        int _crt0_startup_flags = _CRT0_FLAG_USE_DOS_SLASHES       //~v053R~
//                               | _CRT0_FLAG_NO_LFN               //~v105R~
                                 | _CRT0_FLAG_PRESERVE_FILENAME_CASE;//~v053R~
    #else                       //not DPMI                         //~v053R~
    #endif                      //DPMI or not                      //~v053R~
#else
static  HDIR Shdirfirst;
#endif
static char Snomsgff;   //no err msg version                       //~v327I~
#endif      //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#ifdef W32                                                         //~v6k8I~
static char Snomsgffnext;//no err msg version                      //~v6k7I~
#endif                                                             //~v6k8I~
                                                                   //~v327I~
static int Ssorttype;   //implicit parm to udircompare
static char *Sstd[3]={"stdin","stdout","stderr"};               //~5A14M~
static char  Snomsgdl;  //no err msg version                       //~v327R~
static char  Sovfbreaksw;  //break when filectr exceeded for dirlist//~v50FI~
static int   Ssavehandle[3];                                    //~5A14R~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
	static int  Swinremotecdsw;      //on if current direve is "\:"//~v5nuI~
	static char ScurrentdirUNC[_MAX_PATH];                         //~v5nuI~
#endif                                                             //~v5nuI~
	static int Soddsec=0;                                          //~v6htI~
#ifdef W32                                                         //~v6uGI~
	static int Sswgetslink;                                        //~v6uGI~
#endif                                                             //~v6uGI~
#ifndef UNX                                                        //+v783I~
	static int SswFFopt=0;                                                //~v781I~//~v783R~
#endif                                                             //+v783I~
//*******************************************************
#if (_MSC_VER >= 800)                                      //+v034I~//~v034R~
    #define MAXHDIR 100                                            //~v034I~
    static HDIR Shdirtbl[MAXHDIR];                                 //~v034I~
    static UINT Shdirtattr[MAXHDIR];                               //~v034I~
//  static WIN32_FIND_DATA Shdirtfd[MAXHDIR];                      //~v034R~
//  void ufilew32copyfstat(FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd);//~v034R~//~v6k4R~
//    void ufilew32copyfstat(char *Ppath,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd);//~v6k4R~
    void ufilew32copyfstat(int Popt,char *Ppath,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd);//~v6k4I~
    #define UFCFSO_DIRLIST   0x01  //findfirst/findnext            //~v6k4I~//~v6uaR~
    #define UFCFSO_NOMSG     0x02  //no target not found msg       //~v6k4I~//~v6uaR~
    #define UFCFSO_NEXT      0x04  //findnext                      //~v6k7I~//~v6uaR~
//    void ufilew32copyfstatW(int Popt,char *Ppath,UWCH *PpathW,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATAW Pw32fd);//~v6H9R~
    int ufilew32savehdir(HDIR Phdir,ULONG Pattr);                  //~v034R~
    int ufilew32srchhdir(HDIR Phdir,ULONG *Ppattr);                //~v034R~
    int ufilew32closehdir(HDIR Phdir);                             //~v034I~
    static int SdirlistOtherAttrCtr;                               //~v6kmR~
    static int SdirlistOtherAttrCtr_Dir;                           //~v781I~
#else                                                      //+v034I~//~v034I~
#endif                                                     //+v034I~//~v034I~
                                                                   //~v034I~
unsigned udirlistsub(int *Pmax,
                char *Ppdirname,unsigned Pattr,PUDIRLIST *Pppudirlist);
//#ifdef W32                                                       //~v6H9R~
//unsigned udirlistsubW(int Popt,int *Pmax,char *Ppdirname,UWCH *PpdirnameW,unsigned Pattr,PUDIRLIST *Pppudirlist);//~v6H9R~
//#endif                                                           //~v6H9R~
int udircompare(const void *ent1,const void *ent2);
int udircompsub(char *Ppc1,char *Ppc2);                            //~v231I~
//void udirlistsort(int Psorttype,PUDIRLIST Ppudirlist,int Pentno);//~v6J0R~
//*******************************************************
//*dummy for lib(same name as file)                     *
//*******************************************************
void ufile(void)
{
    return;
}
                                                               //~4C18I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
//*******************************************************          //~v6d8I~
//*chk root dir of UNC fmt                                         //~v6d8I~
//*rc:1:servername only;2:up to sharename                          //~v6d8I~
//*******************************************************          //~v6d8I~
int isRootUNC(int Popt,char *Ppfile)                               //~v6d8I~
{                                                                  //~v6d8I~
    char *pc;                                                      //~v6d8I~
    int rootsw=0;                                                  //~v6d8I~
//*********************                                            //~v6d8I~
	pc=Ppfile;                                                     //~v6d8I~
    if (*pc++==DIR_SEPC)                                            //~v6d8I~
    {                                                              //~v6d8I~
    	if (*pc++==DIR_SEPC)                                        //~v6d8I~
        {                                                          //~v6d8I~
	        pc=ustrchr2(pc,DIR_SEPC);                              //~v6d8I~
        	if (!pc)             //"\\server"                      //~v6d8I~
            	rootsw=1;                                          //~v6d8I~
            else                 //"\\server\"                     //~v6d8I~
            {                                                      //~v6d8I~
            	if (!*pc++)      //"\\server\"                     //~v6d8I~
                	rootsw=1;                                      //~v6d8I~
                else             //"\\server\share"                //~v6d8I~
                {                                                  //~v6d8I~
	        		pc=ustrchr2(pc,DIR_SEPC);                      //~v6d8I~
		        	if (!pc)             //"\\server\share"        //~v6d8I~
        		    	rootsw=2;                                  //~v6d8I~
                    else                                           //~v6d8I~
                    	if (!*(pc+1))   //"\\server\share\"        //~v6d8R~
	        		    	rootsw=2;                              //~v6d8I~
                }                                                  //~v6d8I~
            }                                                      //~v6d8I~
        }                                                          //~v6d8I~
    }                                                              //~v6d8I~
    return rootsw;                                                 //~v6d8I~
}//isRootUNC                                                       //~v6d8I~
//*******************************************************          //~v5nuI~
//*retry fstat when faied for UNC filename \\server\share[\]       //~v6u6R~
//*******************************************************          //~v5nuI~
UINT ufstatUNCroot(int Popt,char *Ppfile,FILEFINDBUF3 *Ppffb3,int Prootsw)//~v6u6R~
{                                                                  //~v5nuI~
	WIN32_FIND_DATA w32fd;                                         //~v5nuI~
	WIN32_FILE_ATTRIBUTE_DATA w32ad;                               //~v6u6R~
#ifdef W32UNICODE                                                  //~v6ukM~
    UWCH fpathW[_MAX_PATHWC];                                      //~v6ukM~
    int ucsctr,rc;                                                 //~v6ukI~
#else                                                              //~v6ukI~
    char fpath[_MAX_PATH];                                         //~v6u6R~
    int len,rc;                                                    //~v6u6R~
#endif                                                             //~v6ukI~
//*********************                                            //~v5nuI~
	if (Prootsw==1)	//server name only(\\server fmt)               //~v6u6R~
    {                                                              //~v6u6I~
    	uerrmsg("Missing share resource name for %s\n",0,          //~v6u6I~
        			Ppfile);                                       //~v6u6I~
    	return ERROR_INVALID_NAME;//for err case of top folder     //~v6u6I~
    }                                                              //~v6u6I~
#ifdef W32UNICODE                                                  //~v6ukI~
    rc=uGetFileAttributesExW(Ppfile,GetFileExInfoStandard,&w32ad,0,fpathW,sizeof(fpathW),&ucsctr);//~v6ukI~
#else                                                              //~v6ukI~
    rc=GetFileAttributesEx(Ppfile,GetFileExInfoStandard,&w32ad);   //~v6u6R~//~v6ukR~
#endif                                                             //~v6ukI~
    if (!rc)    //bool:false                                       //~v6u6R~
    	return GetLastError();                                     //~v6u6R~
    memset(&w32fd,0,sizeof(w32fd));                                //~v6u6R~
    w32fd.dwFileAttributes=w32ad.dwFileAttributes;                 //~v6u6R~
    w32fd.ftCreationTime=w32ad.ftCreationTime;                     //~v6u6I~
    w32fd.ftLastAccessTime=w32ad.ftLastAccessTime;                 //~v6u6I~
    w32fd.ftLastWriteTime=w32ad.ftLastWriteTime;                   //~v6u6I~
    w32fd.nFileSizeHigh=w32ad.nFileSizeHigh;                       //~v6u6I~
    w32fd.nFileSizeLow=w32ad.nFileSizeLow;                         //~v6u6I~
#ifdef W32UNICODE                                                  //~v6ukI~
    if(*(fpathW+ucsctr-1)==DIR_SEPC)                               //~v6ukI~
    	*(fpathW+(--ucsctr))=0;                                    //~v6ukI~
    strcpyW(w32fd.cFileName,fpathW);                               //~v6ukI~
#else                                                              //~v6ukI~
    len=strlen(Ppfile);                                            //~v6u6I~
    UmemcpyZ(fpath,Ppfile,len);                                    //~v6u6I~
    if(*(fpath+len-1)==DIR_SEPC)                                   //~v6u6I~
    	*(fpath+(--len))=0;                                        //~v6u6R~
    UmemcpyZ(w32fd.cFileName,fpath,len);                           //~v6u6I~//~v6ukR~
#endif                                                             //~v6ukI~
    ufilew32copyfstat(0/*popt*/,Ppfile,Ppffb3,&w32fd);             //~v6u6R~
    return 0;                                                      //~v6u6R~
}//ufstatUNCroot                                                   //~v6u6R~
//*******************************************************          //~v5nuI~
//*retry fstat when faied for UNC filename                         //~v5nuI~
//*******************************************************          //~v5nuI~
UINT ufstatUNC(int Popt,char *Ppfile,FILEFINDBUF3 *Ppffb3,int *Pprootsw)//~v5nuR~
{                                                                  //~v5nuI~
	WIN32_FIND_DATA w32fd;                                         //~v5nuI~
	UINT apiret=0;                                                 //~v5nuI~
    HDIR hdir;                                                     //~v5nuI~
//  int rootsw=0,wildsw=0,len,shortpathlen;                        //~v5nuR~//~v6h7R~
    int rootsw=0,wildsw=0,len=0,shortpathlen;                      //~v6h7I~
    char fpath[_MAX_PATH],*pcf;                                    //~v5nuI~
//  char shortpath[_MAX_PATH],*pshortname=0;                       //~v5nuI~//~v6hdR~
    char shortpath[_MAX_PATH];                                     //~v6hdI~
//*********************                                            //~v5nuI~
    rootsw=isRootUNC(0,Ppfile); //FindFirstFile faile for root(\\server or \\server\share)//~v6u6R~
    if (rootsw) //FindFirstFile faile for root(\\server or \\server\share)//~v6u6R~
    {                                                            //~v6u6R~
        *Pprootsw=rootsw;                                        //~v6u6R~
        return ufstatUNCroot(Popt,Ppfile,Ppffb3,rootsw);           //~v6u6R~
    }                                                            //~v6u6R~
    hdir=FindFirstFile(Ppfile,&w32fd);                             //~v5nuI~
    if (hdir==INVALID_HANDLE_VALUE)                                //~v5nuI~
    {                                                              //~v5nuI~
    	apiret=GetLastError();                                     //~v5nuI~
//    if(apiret==ERROR_BAD_NETPATH)//for err case of top folder    //~v6d8R~
//    {                                                            //~v6d8R~
//        pcf=ustrchr2(Ppfile+2,DIR_SEPC);                         //~v6u6R~
//        if (pcf && *(pcf+1))    //not servername only            //~v6u6R~
//        {                                                        //~v6u6R~
//          if(apiret==ERROR_INVALID_NAME)//for err case of top folder//~v6u6R~
//          {                                                      //~v6u6R~
//            if (!WILDCARD(pcf))                                  //~v6u6R~
//            {                                                    //~v6u6R~
//                len=strlen(Ppfile);                              //~v6u6R~
//                memcpy(fpath,Ppfile,(UINT)len);                  //~v6u6R~
//                if (*(fpath+len-1)!=DIR_SEPC)   //last is not "\"//~v6u6R~
//                    *(fpath+len++)=DIR_SEPC;                     //~v6u6R~
//                wildsw=1;               //retry case of by wildcard//~v6u6R~
//                *(fpath+len++)='*';     //try \\server\folder\*  //~v6u6R~
//                *(fpath+len)=0;                                  //~v6u6R~
//                hdir=FindFirstFile(fpath,&w32fd);                //~v6u6R~
//                if (hdir==INVALID_HANDLE_VALUE)                  //~v6u6R~
//                    apiret=GetLastError();                       //~v6u6R~
//            }                                                    //~v6u6R~
//          }//invalid_name                                        //~v6u6R~
//        }                                                        //~v6u6R~
//      else                                                       //~v6d8R~
//          rootsw=1;                                              //~v6d8R~
//  	if (hdir==INVALID_HANDLE_VALUE)                            //~v6d8R~
//    		apiret=ERROR_PATH_NOT_FOUND; //errmsg path err         //~v6d8R~
//    }  //NETPATH                                                 //~v6d8R~
    }                                                              //~v5nuI~
    if (hdir!=INVALID_HANDLE_VALUE)                                //~v5nuR~
    {                                                              //~v5nuI~
        apiret=0;                                                  //~v5nuI~
    	if (Ppffb3)                                                //~v5nuI~
        {                                                          //~v5nuI~
            if (wildsw)	                                           //~v5nuI~
            {                                                      //~v5nuI~
            	memset(Ppffb3,0,sizeof(FILEFINDBUF3));             //~v5nuI~
    			Ppffb3->attrFile=FILE_ATTRIBUTE_DIRECTORY;         //~v5nuI~
                *(fpath+len-2)=0;	//drop last "\*"               //~v5nuI~
                pcf=ustrrchr2(fpath,DIR_SEPC);                     //~v5nuI~
                if (pcf)      //                                   //~v5nuI~
                {                                                  //~v5nuI~
                	pcf++;                                         //~v5nuI~
    				UstrncpyZ(Ppffb3->cFileName,pcf,sizeof(Ppffb3->cFileName));//~v5nuI~
    				shortpathlen=GetShortPathName(fpath,shortpath,sizeof(shortpath));//~v5nuR~
    				if (shortpathlen)	//shortname gotten         //~v5nuI~
    				{                                              //~v5nuI~
    					len=PATHLEN(shortpath);                    //~v5nuI~
        				if (len>0 && len!=shortpathlen)            //~v5nuI~
        					UstrncpyZ(Ppffb3->achName,shortpath+len,sizeof(Ppffb3->achName));//~v5nuI~
    				}                                              //~v5nuI~
                }                                                  //~v5nuI~
            }                                                      //~v5nuI~
            else                                                   //~v5nuI~
//  	    	ufilew32copyfstat(Ppffb3,&w32fd);                  //~v5nuR~//~v6k4R~
//    	    	ufilew32copyfstat(Ppfile,Ppffb3,&w32fd);           //~v6k4R~
    	    	ufilew32copyfstat(0/*popt*/,Ppfile,Ppffb3,&w32fd); //~v6k4I~
        }                                                          //~v5nuI~
        ufilew32closehdir(hdir);//free handle                      //~v5nuI~
    }                                                              //~v5nuI~
//    if (isRootUNC(0,Ppfile)==2)                                  //~v6u6R~
//  	rootsw;                                                    //~v6u1R~
//        rootsw=2;                                                //~v6u6R~
    rootsw=isRootUNC(0,Ppfile);                                    //~v6u6I~
    *Pprootsw=rootsw;                                              //~v5nuI~
    return apiret;                                                 //~v5nuI~
}//ufstatUNC                                                       //~v5nuI~
#endif //WINREMOTESUPP                                             //~v5nuI~
#ifdef UNX  //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~v327I~
//static int SufstatWopt,SufstatWbuffsz;                           //~v6H9R~
////*******************************************************        //~v6H9R~
////*support longname                                              //~v6H9R~
////*******************************************************        //~v6H9R~
//unsigned int ufstatWLong(int Popt,char *Ppfile,size_t Pbuffsz,FILEFINDBUF3 *Ppffb3)//~v6H9R~
//{                                                                //~v6H9R~
//    unsigned rc;                                                 //~v6H9R~
////*********************                                          //~v6H9R~
//    SufstatWopt=Popt;                                            //~v6H9R~
//    SufstatWbuffsz=Pbuffsz?Pbuffsz:_MAX_PATH_LONG;               //~v6H9R~
//    rc=ufstat(Ppfile,Ppffb3);                                    //~v6H9R~
//    SufstatWopt=0;                                               //~v6H9R~
//    SufstatWbuffsz=0;                                            //~v6H9R~
//    UTRACEP("%s:rc=%d,filename=%s\n",UTT,rc,Ppfile);             //~v6H9R~
//    return rc;                                                   //~v6H9R~
//}//ufstatWLong                                                   //~v6H9R~
//*******************************************************
//*get file status(size,time stmp)
//*parm 1:file name
//*parm 2:output file info addr(optional)                          //~v068R~
//*******************************************************
unsigned int ufstat(char *Ppfile,FILEFINDBUF3 *Ppffb3)
{
#ifdef DOS
    unsigned int apiret;
  #if DPMI                                                         //~v105I~
    HDIR hdir;                                                     //~v105I~
    FILEFINDBUF3 ft;                                               //~v105I~
    FILEFINDBUF3 *pft;                                             //~v105I~
  #else                                                            //~v105I~
    struct find_t ft;   //output file information                  //~v068I~
    struct find_t *pft; //output file information                  //~v068I~
  #endif                                                           //~v105I~
#else
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            HDIR hdir;                                             //~v034I~
            WIN32_FIND_DATA w32fd;                                 //~v034I~
            FILEFINDBUF3 ffb3;                                     //~v068I~
            FILEFINDBUF3 *pffb3;                                   //~v068I~
        #else                                                      //~v034I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        static  HDIR hdir;                                         //~v022I~
        static  ULONG  cfilename=1;                                //~v022I~
        APIRET rc;                                                 //~v295I~
        FILEFINDBUF3 ffb3;                                         //~v068I~
        FILEFINDBUF3 *pffb3;                                       //~v068I~
    #endif                                                         //~v022M~
    APIRET apiret;
#endif
    unsigned int option;
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
    int rootsw=0;                                                  //~v5nuR~
#endif                                                             //~v5nuI~
#ifdef W32                                                         //~v6H9I~
	char fpath[_MAX_PATH_LONG];                                    //~v6H9I~
#endif                                                             //~v6H9I~
    int rc2;                                                       //~v6H9I~
//*********************************
 	UTRACEP("%s:Ppfile=%s\n",UTT,Ppfile);                          //~v777I~
//    if (SufstatWbuffsz)                                          //~v6H9R~
//        UMAXPATHCHK(Ppfile,SufstatWbuffsz,ENAMETOOLONG,1/*errmsgsw*/);  //return if too long name//~v6H9R~
//    else                                                         //~v6H9R~
//        UMAXPATHCHK(Ppfile,_MAX_PATH,ENAMETOOLONG,1/*errmsgsw*/);  //return if too long name//~v6H1R~//~v6H9R~
#ifdef W32                                                         //~v6H9I~
	if (!ufullpath(fpath,Ppfile,sizeof(fpath)))                    //~v6H9R~
    {                                                              //~v6H9I~
    	rc2=errno;                                                 //~v6H9R~
        if (rc2==ENAMETOOLONG)	//msg issued                       //~v6H9R~
        	return rc2;                                            //~v6H9R~
    	return ufileErrInvalidName(EINVAL,Ppfile);                 //~v6H9I~
    }                                                              //~v6H9I~
    Ppfile=fpath;                                                  //~v6H9I~
#endif                                                             //~v6H9I~
#ifdef DOS
//*** dos
  #ifdef DPMI                   //DPMI version                     //~v105I~
    if (!(pft=Ppffb3))  //optional parm                            //~v105I~
  #else                       //not DPMI                           //~v105I~
    if (!(pft=(struct find_t*)Ppffb3))  //optional parm            //~v068I~
  #endif                      //DPMI or not                        //~v105I~
        pft=&ft;                        //use internal work        //~v068I~
    option=
           FILE_NORMAL                                          //~5617R~
         | FILE_READONLY                                        //~5617R~
         | FILE_HIDDEN                                          //~5617R~
         | FILE_SYSTEM                                          //~5617R~
//       | FILE_VOLID               //dos only                     //~v002R~
         | FILE_DIRECTORY                                       //~5617R~
         | FILE_ARCHIVED;                                       //~5617R~
  #ifdef DPMI                   //DPMI version                     //~v105I~
    apiret=udpmifindfirst(Ppfile,           //path,filename        //~v105I~
                          &hdir,                                   //~v105I~
                          option,           //search file attr     //~v105I~
                          pft);//output file information,optional  //~v105I~
  #else                       //not DPMI                           //~v105I~
    apiret=_dos_findfirst(Ppfile,           //path,filename
                          option,           //search file attr
                          pft);//output file information,optional  //~v068R~
  #endif                      //DPMI or not                        //~v105I~
    if(apiret)
    {
        memset(pft,0,sizeof(FILEFINDBUF3)); //new find first       //~v068I~
      #ifdef DPMI                   //DPMI version                 //~v053I~
        if(errno!=ENOENT && errno!=ENMFILE) //not found or no more file//~v053I~
            ufileapierr("udpmifindfirst",Ppfile,errno);            //~v105I~
      #else                       //not DPMI                       //~v053I~
        if(errno!=ENOENT)
//    #endif                      //DPMI or not                    //~v105R~
            ufileapierr("_dos_findfirst",Ppfile,errno);         //~5905I~
      #endif                      //DPMI or not                    //~v105I~
    }
    if (WILDCARD(Ppfile))                                          //~v002R~
        UCBITOFF(((FILEFINDBUF3*)pft)->attrFile,FILE_DIRECTORY);   //~v068R~
#else 
//** os/2
    option=
           FILE_NORMAL                                          //~5617R~
         | FILE_READONLY                                        //~5617R~
         | FILE_HIDDEN                                          //~5617R~
         | FILE_SYSTEM                                          //~5617R~
         | FILE_DIRECTORY                                       //~5617R~
         | FILE_ARCHIVED;                                       //~5617R~
    #ifdef W32                                                     //~v022I~
#ifdef FTPSUPP                                                     //~v59nM~
          	if (uftpisremote(Ppfile,&puftph))	//ftp filename     //~v5afR~
           		return uftpfstat(puftph,Ppfile,Ppffb3);            //~v5afR~
#endif                                                             //~v59nM~
        if (!(pffb3=Ppffb3))    //optional parm                    //~v068I~
            pffb3=&ffb3;                        //use internal work//~v068I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            pffb3->attrFile=option;                                //~v068R~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuM~
          if (WIN_ISREMOTEPATH(Ppfile))                            //~v5nuI~
			apiret=ufstatUNC(0,Ppfile,pffb3,&rootsw);              //~v5nuI~
          else                                                     //~v5nuI~
          {                                                        //~v5nuI~
#endif                                                             //~v5kdI~//~v5nuM~
            hdir=FindFirstFile(Ppfile,&w32fd);                     //~v034R~
            if (hdir==INVALID_HANDLE_VALUE)                        //~v034R~
                apiret=GetLastError();                             //~v034R~
            else                                                   //~v034I~
            {                                                      //~v034I~
              if (!udosiswinnt() //win95/98                        //~v5fsI~
			  &&   ROOTDIR_LOCAL(Ppfile))	//success for root when 95/98//~v5fsI~
              	apiret=2;                                          //~v5fsI~
              else                                                 //~v5fsI~
              {                                                    //~v5fsI~
//              ufilew32copyfstat(pffb3,&w32fd);                   //~v068R~//~v6k4R~
//              ufilew32copyfstat(Ppfile,pffb3,&w32fd);            //~v6k4R~
                ufilew32copyfstat(0/*opt*/,Ppfile,pffb3,&w32fd);   //~v6k4I~
                apiret=0;                                          //~v034I~
              }                                                    //~v5fsI~
                ufilew32closehdir(hdir);//free handle              //~v295I~
            }                                                      //~v034I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
          }	//!UNC                                                 //~v5nuI~
#endif                                                             //~v5nuI~
        #else                                                      //~v034I~
        apiret=findfirst(Ppfile,(struct ffblk*)(PVOID)pffb3,option);//~v068R~
        if (apiret)                                                //~v022I~
            apiret=doserrno;                                       //~v022I~
        #endif                                                     //~v034M~
    #else                                                          //~v022I~
    if (!(pffb3=Ppffb3))    //optional parm                        //~v068I~
        pffb3=&ffb3;                        //use internal work    //~v068I~
    hdir=(ULONG)HDIR_CREATE;  //dir handle create req
    apiret=DosFindFirst(Ppfile,       //file name
                        &hdir,          //search handle
                        option,        //search file attr
                        pffb3,       //output file information     //~v068R~
                        sizeof(FILEFINDBUF3),//output area size
                        &cfilename,     //request file count
                        FIL_STANDARD);  //file information level
    if (!apiret)                                                   //~v295I~
    {                                                              //~v295I~
        rc=DosFindClose(hdir);        //relese  handle             //~v295I~
        if (rc)                                                    //~v295I~
            uerrmsg("ufstat:FindClose failed,rc=%d",               //~v295I~
                        "ufstat:FindClose の失敗,リターンコード=%d",//~v295I~
                        rc);                                       //~v295I~
    }                                                              //~v295I~
                                                                   //~v295I~
    #endif                                                         //~v022I~
    if(apiret)
    {
        memset(pffb3,0,sizeof(FILEFINDBUF3));   //new find first   //~v068R~
//#ifdef WINREMOTESUPP     //\\xxx\yy support                      //~v6u6R~
//      if (!rootsw)    //issue errmsg                             //~v6u6R~
        if (rootsw!=1)    //already issued in UNCroot              //~v6u6I~
//#endif                                                           //~v6u6R~
      if (!(apiret==ERROR_BAD_DEV_TYPE     //network resource type is not correct//~v57nI~
            && ROOTDIR(Ppfile)))     //no msg for rootdir          //~v57nI~
        if(apiret!=ERROR_NO_MORE_FILES
        && apiret!=ERROR_FILE_NOT_FOUND
        && apiret!=ERROR_PATH_NOT_FOUND)
        {                                                          //~v5nBI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nBI~
          if (apiret==ERROR_INVALID_NAME)                          //~v5nBI~
          {                                                        //~v5nBI~
			if (!(Gufile_opt & GFILEOPT_IGN_UNCPATHERR)) //ignore UNC fmt path err msg//~v5nBI~
            	uerrmsg("Invalid Name Format(%s)",0,               //~v5nBR~
            		Ppfile);                                       //~v5nBR~
          }                                                        //~v5nBI~
          else                                                     //~v5nBI~
          if(apiret==ERROR_LOGON_FAILURE)//password protected      //~v5nBI~
            uerrmsg("Logon required(%s)",0,                        //~v5nBR~
            	Ppfile);                                           //~v5nBI~
          else                                                     //~v5nBI~
          if(apiret==ERROR_BAD_NETPATH)//password protected        //~v6d8I~
            uerrmsg("Network Search failed(%s)",0,                 //~v6d8I~
            	Ppfile);                                           //~v6d8I~
          else                                                     //~v6d8I~
#endif                                                             //~v5nBI~
#ifdef W32                                                         //~v6uZI~
          if(apiret==ERROR_NOT_READY)                              //~v6uZI~
            uerrmsg("DeviceNotReady(%s)",0,                        //~v6uZR~
            	Ppfile);                                           //~v6uZR~
          else                                                     //~v6uZI~
#endif                                                             //~v6uZI~
            ufileapierr("DosFindFirst",Ppfile,(int)apiret);     //~5905R~
        }                                                          //~v5nBI~
    }//apiret
#endif
    UTRACED("ffb3",Ppffb3,sizeof(FILEFINDBUF3));                   //~v777R~
    if (Ppffb3)                                                    //~v77aI~
    UTRACEP("%s:exit apiret=%d,attr=0x%x,fnm=%s\n",UTT,apiret,pffb3->attrFile,pffb3->cFileName);//~v77aR~
    return apiret;
}//ufstat
#endif      //!!!!!!!!!!!!!!!!!!                                   //~v327I~
                                                                   //~v327I~
#if (_MSC_VER >= 800)                                              //~v034I~
//*******************************************************          //~v6k4I~
//*set symlink/junction attr target name                           //~v6k4I~
//*******************************************************          //~v6k4I~
//int ufilew32getslink(char *Ppath,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd)//~v6k4R~
int ufilew32getslink(int Popt,char *Ppath,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd)//~v6k4I~
{                                                                  //~v6k4I~
    ULONG attr,outattr,newattr;                                    //~v6k4I~
    int len,pathlen,tag,rc,pathlen2;                                        //~v6k4R~//~v6k7R~
    char *fnm;                                                     //~v6k4I~
    char target[_MAX_PATH];                                        //~v6k4I~
    char fpath[_MAX_PATH];                                         //~v6k4R~
	FILEFINDBUF3 ffb3target;                                       //~v6k4R~
    int swwildcard;                                                //~v6k7I~
    int swslinkerr;                                                //~v6kcI~
#ifdef W32UNICODE                                                  //~v6uaI~
    UWCH targetW[_MAX_PATHWC];                                     //~v6uaI~
    int targetWctr,udrc;                                           //~v6uaR~
#endif                                                             //~v6uaI~
//*************                                                    //~v6k4I~
    if (Sswgetslink)    //loop                                     //~v6uGI~
    {                                                              //~v6uGI~
        uerrmsg("slink loop detected for %s\n",0,                  //~v6uGI~
                Ppath);                                            //~v6uGI~
    	Ppffb3->attrFile|=FILE_SLINKERR;                           //~v6uGI~
        return 4;                                                  //~v6uGI~
    }                                                              //~v6uGI~
    attr=Pw32fd->dwFileAttributes;                                 //~v6k4I~
    newattr=Ppffb3->attrFile|FILE_SLINK;                           //~v6k4I~
#ifdef W32UNICODE                                                  //~v6uaI~
    fnm=Ppffb3->cFileName;                                         //~v6uaR~
#else                                                              //~v6uaI~
    fnm=Pw32fd->cFileName;                                         //~v6k4I~
#endif                                                             //~v6uaI~
    if (Popt & UFCFSO_DIRLIST)	//findfirst/findnext               //~v6k4I~
    {                                                              //~v6k4I~
    	pathlen=PATHLEN(Ppath);                                    //~v6k4R~
        pathlen2=pathlen;                                          //~v6k7I~
    	if (pathlen>0 && WILDCARD(Ppath+pathlen))               //~v6k4R~//~v6k7R~
            swwildcard=1;                                          //~v6k7M~
        else                                                       //~v6k7I~
        {                                                          //~v6k7I~
        	pathlen=strlen(Ppath);                                 //~v6k4I~
    		swwildcard=0;                                          //~v6k7I~
        }                                                          //~v6k7I~
	    memcpy(fpath,Ppath,pathlen);                               //~v6k4I~
    	if (pathlen>0 && *(fpath+pathlen-1)!=DIR_SEPC)             //~v6k4R~
    		*(fpath+pathlen++)=DIR_SEPC;                           //~v6k4R~
        if (swwildcard || Popt & UFCFSO_NEXT)                      //~v6k7I~
		    UstrncpyZ(fpath+pathlen,fnm,sizeof(fpath)-pathlen);        //~v6k4I~//~v6k7R~
        else	//findfirst for dir? or file?                      //~v6k7I~
        {                                                          //~v6k7I~
        	if (!(Ppffb3->attrFile & FILE_DIRECTORY))              //~v6k7I~
			    strcpy(fpath,Ppath);                               //~v6k7I~
            else                                                   //~v6k7I~
            {                                                      //~v6k7I~
    			if (pathlen2>0 && LFNM_STRCMP(Ppath+pathlen2,fnm)) //~v6k7I~
				    UstrncpyZ(fpath+pathlen,fnm,sizeof(fpath)-pathlen);//findfirst member!=parm fnm-->dir(if not wildcard 1st member is "." usualy)//~v6k7I~
                else                                               //~v6k7I~
		    		strcpy(fpath,Ppath);                           //~v6k7I~
            }                                                      //~v6k7I~
        }                                                          //~v6k7I~
    }                                                              //~v6k4I~
    else	//ufstat,ufstatUNC                                     //~v6k4R~
    {                                                              //~v6k4I~
    	strcpy(fpath,Ppath);                                       //~v6k4R~
    	pathlen=PATHLEN(Ppath);                                    //~v6u3I~
    	if (pathlen>0 && WILDCARD(Ppath+pathlen))                  //~v6u3I~
		    UstrncpyZ(fpath+pathlen,fnm,sizeof(fpath)-pathlen);    //~v6u3I~
    }                                                              //~v6k4I~
 	UTRACEP("ufilew32getslink Ppath=%s,srcfpath=%s,winattr=%x\n",Ppath,fpath,attr);//~v6k4R~
#ifdef W32UNICODE                                                  //~v6uaI~
	rc=uwinlnk_gettargetW(UWINGTO_W32ATTR,attr,fpath,target,sizeof(target),//~v6uaR~
						&len,&outattr,&tag,NULL/*prepasebuff*/,targetW,sizeof(targetW),&targetWctr,&udrc);//~v6uaR~
#else                                                              //~v6uaI~
	rc=uwinlnk_gettarget(UWINGTO_W32ATTR,attr,fpath,target,sizeof(target),//~v6k4R~
						&len,&outattr,&tag,NULL/*prepasebuff*/);   //~v6k4I~
#endif                                                             //~v6uaI~
    if (rc)                                                        //~v6k4I~
    	newattr|=FILE_NTFS_OTHER_REPARSE;                          //~v6k4I~
    else                                                           //~v6k4I~
    if (tag==IO_REPARSE_TAG_MOUNT_POINT)	//MOUNT POINT or JUNCTION//~v6k4R~
    {                                                              //~v6k4I~
        if(strchr(target,':'))                                     //~v6k4R~
    		newattr|=FILE_NTFS_JUNCTION;                           //~v6k4R~
        else                                                       //~v6k4I~
    		newattr|=FILE_NTFS_MOUNTVOL;                           //~v6k4I~
    }                                                              //~v6k4I~
    else                                                           //~v6k4R~
    	newattr|=FILE_NTFS_SLINK;                                  //~v6k4M~
    swslinkerr=1;                                                  //~v6kcI~
    if (!rc)                                                       //~v6k4I~
    {                                                              //~v6k4I~
    	UstrncpyZ(Ppffb3->slink,target,sizeof(Ppffb3->slink));     //~v6k4R~
#ifdef W32UNICODE                                                  //~v6uaI~
    	UstrncpyZW(Ppffb3->slinkW,targetW,sizeof(Ppffb3->slinkW)); //~v6uaI~
    	Ppffb3->slinkWctr=targetWctr;                              //~v6uaI~
    	if (udrc==UCVEXTRC_SUBCH && targetWctr)                    //~v6uaI~
    		Ppffb3->otherflag|=FFB3OF_SUBCHSLINK;                  //~v6uaI~
#endif                                                             //~v6uaI~
        if (newattr & FILE_NTFS_MOUNTVOL)   //rc=87 for Volume{xxxx}; invalidname format//~v6k4I~
        {                                                          //~v6k4I~
        	Ppffb3->srcattr=FILE_DIRECTORY;                        //~v6k4R~
            swslinkerr=0;	//mount volume                         //~v6kcI~
        }                                                          //~v6k4I~
        else                                                       //~v6k4I~
        {                                                          //~v6k4I~
            Sswgetslink=1;                                         //~v6uGI~
//          rc=ufstat(target,&ffb3target);                         //~v6uHR~
		    rc=ufilechkslinkpath(fpath,Ppffb3->slink,target,NULL/*fpath target*/,&ffb3target);//~v6uHI~
            Sswgetslink=0;                                         //~v6uGI~
            if (!rc)                                               //~v6k4R~
            {                                                      //~v6k4R~
                Ppffb3->srcattr=ffb3target.attrFile;               //~v6k4R~
                Ppffb3->slinkftime=ffb3target.ftimeLastWrite;      //~v6k4R~
                Ppffb3->slinkfdate=ffb3target.fdateLastWrite;      //~v6k4R~
                Ppffb3->slinksize=ffb3target.cbFile;               //~v6k4R~
                if (!(Ppffb3->srcattr & FILE_DIRECTORY)) //junction to file has dir attr//~v6k4R~
                {                                                  //~v6k8I~
		    	  if (newattr & FILE_NTFS_JUNCTION)	//junction target error,slink set dir or file at mklink cmd//~v6kcI~
                  {                                                //~v6kcI~
    				if (!(Popt & UFCFSO_NOMSG))                    //~v6k8I~
						rc=ufileslinkj2ferr(UWINLNKERR_JUNCTIONTOFILE,fpath,target);//~v6k8I~
                    newattr&=~FILE_DIRECTORY;                      //~v6kgI~
                  }                                                //~v6kcI~
                  else                                             //~v6kcI~
		    	  if (newattr & FILE_NTFS_SLINK                    //~v6kgI~
                  && attr & FILE_DIRECTORY)	//mkslink /D           //~v6kgI~
                  {                                                //~v6kgI~
    				if (!(Popt & UFCFSO_NOMSG))                    //~v6kgI~
						rc=ufileslinkd2ferr(UWINLNKERR_SLINKDTOFILE,fpath,target);//~v6kgI~
                  }                                                //~v6kgI~
                  else                                             //~v6kgI~
                  {                                                //~v6kgI~
		            swslinkerr=0;                                  //~v6kcI~
                    newattr&=~FILE_DIRECTORY;                      //~v6k4R~
                  }                                                //~v6kgI~
                }                                                  //~v6k8I~
                else                                               //~v6kcI~
		            swslinkerr=0;                                  //~v6kcI~
            }                                                      //~v6k4R~
            else                                                   //~v6k4I~
            if (rc!=UWFRC_LONGNAME)                                //~v6H4I~
            {                                                      //~v6k7I~
	    		if (newattr & FILE_NTFS_JUNCTION)	//junction target error,slink set dir or file at mklink cmd//~v6k7I~
                    newattr&=~FILE_DIRECTORY;                      //~v6k7I~
    			if (!(Popt & UFCFSO_NOMSG))                        //~v6k4I~
					rc=ufileslinktargeterr(UWINLNKERR_NOTARGET,fpath,target);//~v6k4I~//~v6k8R~
            }                                                      //~v6k7I~
        }                                                          //~v6k4I~
	}                                                              //~v6k4I~
    if (swslinkerr)                                                //~v6kcI~
    	newattr|=FILE_SLINKERR;                                    //~v6kcI~
    Ppffb3->attrFile=newattr;                                      //~v6k4M~
    UTRACEP("ufilew32getslink rc=%d,winattr=%x,newattr=%x,srcattr=%x,target=%s for fnm=%s\n",rc,attr,newattr,Ppffb3->srcattr,target,fnm);//~v6k4R~
    return rc;                                                     //~v6k4I~
}//ufilew32getslink                                                //~v6qbR~
//*******************************************************          //~v034I~
//*set up FILEFINDBUF3 from Win32_FIND_DATA                        //~v034I~
//*parm 1:FILEFINDBUF3                                             //~v034I~
//*parm 2:WIN32_FIND_DATA                                          //~v034I~
//*return:none                                                     //~v034I~
//*******************************************************          //~v034I~
//void ufilew32copyfstat(FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd)//~v034R~//~v6k4R~
//void ufilew32copyfstat(char *Ppath,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd)//~v6k4R~
void ufilew32copyfstat(int Popt,char *Ppath,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATA Pw32fd)//~v6k4I~
{                                                                  //~v034I~
    FILETIME lft;                                                  //~v034I~
    int opt;                                                       //~v6k4I~
#ifdef AAA                                                         //~v6q0I~
    char wkshortname[_MAX_PATH];                                   //~v6q0R~
    char wkfpath[_MAX_PATH];                                       //~v6q0R~
#endif                                                             //~v6q0I~
//*************                                                    //~v034I~
    memset(Ppffb3,0,sizeof(FILEFINDBUF3));                         //~v5aiI~
//  Ppffb3->attrFile=Pw32fd->dwFileAttributes;                     //~v5fsR~
    Ppffb3->attrFile=(Pw32fd->dwFileAttributes &                   //~v5fsI~
    				   (FILE_ATTRIBUTE_READONLY |                  //~v5fsI~
    					FILE_ATTRIBUTE_HIDDEN   |                  //~v5fsI~
    					FILE_ATTRIBUTE_SYSTEM   |                  //~v5fsI~
    					FILE_ATTRIBUTE_DIRECTORY|                  //~v5fsI~
    					FILE_ATTRIBUTE_ARCHIVE  ));                //~v5fsI~
                                                                   //~v547I~
    Ppffb3->ftCreationTime  =Pw32fd->ftCreationTime;               //~v547I~
    Ppffb3->ftLastAccessTime=Pw32fd->ftLastAccessTime;             //~v547I~
    Ppffb3->ftLastWriteTime =Pw32fd->ftLastWriteTime;              //~v547I~
                                                                   //~v547I~
    FileTimeToLocalFileTime(&Pw32fd->ftLastWriteTime,&lft);        //~v034R~
//  FileTimeToDosDateTime(&lft,                                    //~v034I~//~v6hvR~
    filetime2dosdatetime(&lft,                                     //~v6hvI~
                            (USHORT*)(void*)&Ppffb3->fdateLastWrite,//~v034I~
//                          (USHORT*)(void*)&Ppffb3->ftimeLastWrite);//~v034I~//~v6hvR~
                            (USHORT*)(void*)&Ppffb3->ftimeLastWrite,0/*Ppoddsec*/);//~v6hvI~
#ifdef LFSSUPP                                                     //~v5k0I~
    Ppffb3->cbFile=((FILESZT)(Pw32fd->nFileSizeHigh)<<32)|((FILESZT)(Pw32fd->nFileSizeLow));//~v5k0R~
#else                                                              //~v5k0I~
    Ppffb3->cbFile=Pw32fd->nFileSizeLow;                           //~v034R~
#endif                                                             //~v5k0I~
  #ifdef W32UNICODE                                                //~v6uaI~
  	ufilew_copyfstat_name(UFCVO_2UD,Pw32fd,Ppffb3);	//set locale code and UWCH name/altname//~v6uaR~
  #else                                                            //~v6uaI~
    memcpy(Ppffb3->cFileName,Pw32fd->cFileName,sizeof(Ppffb3->cFileName));//~v034R~
    UTRACEP("ufilew32copyfstat for %s altname=%s\n",Ppffb3->cFileName,Pw32fd->cAlternateFileName);//~v6q0I~
  #endif                                                           //~v6uaI~
#ifdef AAA  //not for ANSI version                                 //~v6q0I~
    {                                                              //~v6q0I~
        int len;                                                   //~v6q0I~
        len=PATHLEN(Ppath);                                        //~v6q0I~
    	if (WILDCARD(Ppffb3->cFileName))                           //~v6q0I~
        {                                                          //~v6q0I~
        	strcpy(wkfpath,"\\\\?\\"); //avail only for unicode version//~v6q0R~
   			memcpy(wkfpath+4,Ppath,len);                           //~v6q0I~
            len+=4;                                                //~v6q0I~
        }                                                          //~v6q0I~
        else                                                       //~v6q0I~
   			memcpy(wkfpath,Ppath,len);                             //~v6q0R~
    	strcpy(wkfpath+len,Ppffb3->cFileName);                     //~v6q0R~
    	GetShortPathName(wkfpath,wkshortname,sizeof(wkshortname)); //~v6q0R~
    	UTRACEP("ufilew32copyfstat for %s shortname=%s\n",wkfpath,wkshortname);//~v6q0R~
    }                                                              //~v6q0I~
#endif                                                             //~v6q0I~
 	if (WILDCARD(Ppffb3->cFileName))                               //~v6q0I~
    {                                                              //~v6q0I~
	    if (*Pw32fd->cAlternateFileName)                           //~v6q0I~
    		Ppffb3->attrFile|=FILE_WILDNAME;	//alias exist for wildname//~v6q0M~
        else                                                       //~v6q0I~
    		Ppffb3->attrFile|=FILE_WILDNAMEER;	//noalias exist for wildname//~v6q0I~
    }                                                              //~v6q0I~
  #ifdef W32UNICODE                                                //~v6uaI~
  #else                                                            //~v6uaI~
    if (*Pw32fd->cAlternateFileName)                               //~v034I~
    {                                                              //~v6q0I~
        memcpy(Ppffb3->achName,Pw32fd->cAlternateFileName,sizeof(Ppffb3->achName));//~v034I~
    }                                                              //~v6q0I~
    else                                                           //~v034I~
        strncpy(Ppffb3->achName,Pw32fd->cFileName,sizeof(Ppffb3->achName));//~v034I~
  #endif                                                           //~v6uaI~
#ifdef FTPSUPP                                                     //~v59nI~
    Ppffb3->srcattr=0;      //slink source attr is ftp only        //~v59nR~
#endif                                                             //~v59nI~
#ifdef FTPSUPP                                                     //~v59nM~
    *Ppffb3->uname=0;       //username                             //~v59iI~
    *Ppffb3->gname=0;       //groupname                            //~v59iI~
    *Ppffb3->slink=0;       //slink source file name               //~v59nR~
#endif                                                             //~v59nI~
    if (Pw32fd->dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)   //~v6k4R~
    {                                                              //~v6k4I~
    	opt=Popt;                                                  //~v6k4I~
//      if (Snomsgff)                                              //~v6k4I~//~v6k7R~
		if (Gufile_opt & GFILEOPT_NOSLINKERRMSG)                   //~v6k7I~
	    	opt|=UFCFSO_NOMSG;//    0x02  //no target not found msg//~v6k4I~
    	ufilew32getslink(opt,Ppath,Ppffb3,Pw32fd);                 //~v6uaI~
    }                                                              //~v6k4I~
    return;                                                        //~v034I~
}//ufilew32copyfstat                                               //~v034I~
////****************************************************************************************//~v6H9R~
////*set up FILEFINDBUF3 from Win32_FIND_DATA after findfirst/findnext by Unicode api//~v6H9R~
////****************************************************************************************//~v6H9R~
//void ufilew32copyfstatW(int Popt,char *Ppath,UWCH *PpathW,FILEFINDBUF3 *Ppffb3,LPWIN32_FIND_DATAW Pw32fd)//~v6H9R~
//{                                                                //~v6H9R~
//    FILETIME lft;                                                //~v6H9R~
////  int opt;                                                     //~v6H9R~
////*************                                                  //~v6H9R~
//    memset(Ppffb3,0,sizeof(FILEFINDBUF3));                       //~v6H9R~
//    Ppffb3->attrFile=(Pw32fd->dwFileAttributes &                 //~v6H9R~
//                       (FILE_ATTRIBUTE_READONLY |                //~v6H9R~
//                        FILE_ATTRIBUTE_HIDDEN   |                //~v6H9R~
//                        FILE_ATTRIBUTE_SYSTEM   |                //~v6H9R~
//                        FILE_ATTRIBUTE_DIRECTORY|                //~v6H9R~
//                        FILE_ATTRIBUTE_ARCHIVE  ));              //~v6H9R~
//                                                                 //~v6H9R~
//    Ppffb3->ftCreationTime  =Pw32fd->ftCreationTime;             //~v6H9R~
//    Ppffb3->ftLastAccessTime=Pw32fd->ftLastAccessTime;           //~v6H9R~
//    Ppffb3->ftLastWriteTime =Pw32fd->ftLastWriteTime;            //~v6H9R~
//                                                                 //~v6H9R~
//    FileTimeToLocalFileTime(&Pw32fd->ftLastWriteTime,&lft);      //~v6H9R~
//    filetime2dosdatetime(&lft,                                   //~v6H9R~
//                            (USHORT*)(void*)&Ppffb3->fdateLastWrite,//~v6H9R~
//                            (USHORT*)(void*)&Ppffb3->ftimeLastWrite,0/*Ppoddsec*/);//~v6H9R~
//    Ppffb3->cbFile=((FILESZT)(Pw32fd->nFileSizeHigh)<<32)|((FILESZT)(Pw32fd->nFileSizeLow));//~v6H9R~
//    ufilew_copyfstat_name(UFCVO_2UD,Pw32fd,Ppffb3); //set locale code and UWCH name/altname//~v6H9R~
//    if (WILDCARD(Ppffb3->cFileName))                             //~v6H9R~
//    {                                                            //~v6H9R~
//        if (*Pw32fd->cAlternateFileName)                         //~v6H9R~
//            Ppffb3->attrFile|=FILE_WILDNAME;    //alias exist for wildname//~v6H9R~
//        else                                                     //~v6H9R~
//            Ppffb3->attrFile|=FILE_WILDNAMEER;  //noalias exist for wildname//~v6H9R~
//    }                                                            //~v6H9R~
//    Ppffb3->srcattr=0;      //slink source attr is ftp only      //~v6H9R~
//    *Ppffb3->uname=0;       //username                           //~v6H9R~
//    *Ppffb3->gname=0;       //groupname                          //~v6H9R~
//    *Ppffb3->slink=0;       //slink source file name             //~v6H9R~
////*no need to get slink for remove and rmdir                     //~v6H9R~
////  if (Pw32fd->dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) //~v6H9R~
////  {                                                            //~v6H9R~
////      opt=Popt;                                                //~v6H9R~
////      if (Gufile_opt & GFILEOPT_NOSLINKERRMSG)                 //~v6H9R~
////          opt|=UFCFSO_NOMSG;//    0x02  //no target not found msg//~v6H9R~
////      ufilew32getslink(opt,Ppath,Ppathw,Ppffb3,Pw32fd);        //~v6H9R~
////  }                                                            //~v6H9R~
//    return;                                                      //~v6H9R~
//}//ufilew32copyfstatW                                            //~v6H9R~
//*******************************************************          //~v034I~
//*save hdir and requested attrib for findnext                     //~v034I~
//*parm 1:HDIR                                                     //~v034I~
//*parm 2:attr                                                     //~v034I~
//*return:0 or ERROR_TOO_MANY_OPEN_FILES                           //~v034I~
//*******************************************************          //~v034I~
int ufilew32savehdir(HDIR Phdir,ULONG Pattr)                       //~v034R~
{                                                                  //~v034I~
    int ii;                                                        //~v034I~
//*************                                                    //~v034I~
    for (ii=0;ii<MAXHDIR;ii++)                                     //~v034I~
        if (Phdir==Shdirtbl[ii] || !Shdirtbl[ii])                  //~v034I~
        {                                                          //~v034I~
            Shdirtbl[ii]=Phdir;                                    //~v034R~
            Shdirtattr[ii]=Pattr;                                  //~v034I~
//          memcpy(&Shdirtfd[ii],Ppw32fd,sizeof(WIN32_FIND_DATA)); //~v034R~
            break;                                                 //~v034I~
        }                                                          //~v034I~
    if (ii==MAXHDIR)                                               //~v034I~
    {                                                              //~v034I~
        uerrmsg("Pending FindFirst HANDLE overflow(max %d)",                 //+v034M~//~v034I~
                "仕掛かり中の FindFirst の制限超(最大 %d)",  //+v034M~//~v034I~
                    MAXHDIR);                                   //+v034M~//~v034I~
        return ERROR_TOO_MANY_OPEN_FILES;                          //~v034I~
    }                                                              //~v034I~
    return 0;                                                      //~v034I~
}//ufilew32savedir                                                 //~v034I~
//*******************************************************          //~v034I~
//*search hdir table when findnext                                 //~v034I~
//*parm 1:HDIR                                                     //~v034I~
//*parm 2:attr                                                     //~v034I~
//*return:0 or 4(not found)                                        //~v034I~
//*******************************************************          //~v034I~
int ufilew32srchhdir(HDIR Phdir,ULONG *Ppattr)                     //~v034R~
{                                                                  //~v034I~
    int ii;                                                        //~v034I~
//*************                                                    //~v034I~
    if (!Phdir)                                                    //~v034I~
        return ERROR_INVALID_HANDLE;                               //~v034I~
    for (ii=0;ii<MAXHDIR;ii++)                                     //~v034I~
        if (Phdir==Shdirtbl[ii])                                   //~v034I~
            break;                                                 //~v034I~
    if (ii==MAXHDIR)                                               //~v034I~
        return ERROR_INVALID_HANDLE;                               //~v034I~
    *Ppattr=Shdirtattr[ii];                                        //~v034I~
//  memcpy(Ppw32fd,&Shdirtfd[ii],sizeof(WIN32_FIND_DATA));         //~v034R~
    return 0;                                                      //~v034I~
}//ufilew32srchhdir                                                //~v034I~
//*******************************************************          //~v034I~
//*clear hdir table when findclose                                 //~v034I~
//*parm 1:HDIR                                                     //~v034I~
//*return:0 or 4(not found)                                        //~v034I~
//*******************************************************          //~v034I~
int ufilew32closehdir(HDIR Phdir)                                  //~v034I~
{                                                                  //~v034I~
    int ii,rc;                                                     //~v034R~
//*************                                                    //~v034I~
    if (!Phdir)                                                    //~v034M~
        return ERROR_INVALID_HANDLE;                               //~v034M~
    rc=FindClose(Phdir);        //relese  handle            //+v034I~//~v034R~
    if (rc==FALSE)                                         //+v034M~//~v034R~
    {                                                      //+v034M~//~v034R~
        rc=GetLastError();                                 //+v034M~//~v034R~
        uerrexit("FindClose failed,rc=%d",                 //+v034M~//~v034R~
                    "FindClose の失敗,リターンコード=%d",  //+v034M~//~v034R~
                    rc);                                   //+v034M~//~v034R~
    }                                                      //+v034M~//~v034R~
    for (ii=0;ii<MAXHDIR;ii++)                                     //~v034I~
        if (Phdir==Shdirtbl[ii])                                   //~v034I~
            break;                                                 //~v034I~
    if (ii==MAXHDIR)                                               //~v034I~
        return ERROR_INVALID_HANDLE;                               //~v034I~
    Shdirtattr[ii]=0;                                              //~v034I~
    Shdirtbl[ii]=0;                                                //~v087R~
    return 0;                                                      //~v034I~
}//ufilew32closehdir                                               //~v034R~
#endif                                                             //~v034I~
                                                                   //~v327I~
//*******************************************************          //~v50FI~
//*get file fullpath name(expand wildcard path)                    //~v50FI~
//*parm 1:output full pth mame                                     //~v50FI~
//*parm 2:input partial filename                                   //~v50FI~
//*parm 3:output buff len                                          //~v50FI~
//*return:0:no wildcard,1:wildcard changed,                        //~v539R~
//*       2:last path wild card but not changed                    //~v539I~
//*       3:intermediate path wild card but not changed            //~v539I~
//*       4:err                                                    //~v539I~
//*       8:toolongname                                            //~v6H4I~
//*******************************************************          //~v50FI~
int ufullpathwildexp(int Popt,char *Pfullpath,char *Pfilename,size_t Plen)//~v50FR~
{                                                                  //~v50FI~
//  char *pc0,*pco,*pcn,wk[_MAX_PATH+1],outfp[_MAX_PATH+1];        //~v50FR~//~v6H9R~
    char *pc0,*pco,*pcn,wk[_MAX_PATH2_LONG],outfp[_MAX_PATH2_LONG];//~v6H9I~
    PUDIRLIST pudirlist,pudirlist0,pudirlistm=NULL;                     //~v50FR~//~v6h7R~
    int ii,jj,filectr,rc=0,membctr,repsw=0,reppos,attr;            //~v50FR~
    char dirsepc;                                                  //~v5ctR~
#ifdef FTPSUPP                                                     //~v5ctI~
    PUFTPHOST puftph;                                              //~v5ctI~
  #ifdef W32                                                       //~v5ctI~
    int remotesw=0;                                                //~v5ctR~
  #endif                                                           //~v5ctI~
#endif                                                             //~v5ctI~
//*********************************                                //~v50FI~
    pco=pcn=pc0=Pfilename;                                         //~v50FI~
    dirsepc=DIR_SEPC;                                              //~v5ctI~
#ifdef FTPSUPP                                                     //~v5ctI~
	if (uftpisremote(Pfilename,&puftph))	//ftp filename         //~v5ctI~
    {                                                              //~v5ctI~
        if (UFTPHISTSO(puftph))                                    //~v5j4I~
            return u3270fullpathwildexp(Popt,puftph,Pfullpath,Pfilename,Plen);//~v5jcR~
  #ifdef W32                                                       //~v5ctI~
        remotesw=1;                                                //~v5ctI~
  #endif                                                           //~v5ctI~
    	pcn+=puftph->UFTPHhostnmlen+1;                             //~v5ctR~
        dirsepc=FTP_DIR_SEPC;                                      //~v5ctI~
    }                                                              //~v5ctI~
#endif                                                             //~v5ctI~
#ifdef UNX                                                         //~v50FI~
//  if (*pcn==DIR_SEPC)  //from root                               //~v5ctR~
    if (*pcn==dirsepc)  //from root                                //~v5ctI~
        pcn++;      //search from next                             //~v50FI~
#else                                                              //~v50FI~
  #ifdef FTPSUPP                                                   //~v5ctI~
    if (remotesw)                                                  //~v5ctI~
    {                                                              //~v5ctI~
    	if (*pcn==dirsepc)  //from root                            //~v5ctI~
        	pcn++;      //search from next                         //~v5ctI~
    }                                                              //~v5ctI~
    else                                                           //~v5ctI~
    {                                                              //~v5ctI~
  #endif                                                           //~v5ctI~
    if (*(pcn+1)==':')  //drive used                               //~v50FI~
        pcn+=2;                                                    //~v50FI~
//  if (*pcn==DIR_SEPC)  //from root                               //~v5ctR~
    if (*pcn==dirsepc)  //from root                                //~v5ctI~
        pcn++;      //search from next                             //~v50FI~
  #ifdef FTPSUPP                                                   //~v5ctI~
    }                                                              //~v5ctI~
  #endif                                                           //~v5ctI~
#endif                                                             //~v50FI~
//  reppos=(int)((ULONG)pcn-(ULONG)pc0); //member name replace position//~v50FI~//~v6hhR~
    reppos=(int)((ULPTR)pcn-(ULPTR)pc0); //member name replace position//~v6hhI~
//  pcn=ustrchr2(pcn,DIR_SEPC);                                    //~v5ctR~
    pcn=ustrchr2(pcn,dirsepc);                                     //~v5ctI~
    *outfp=0;		//for strcat                                   //~v50FI~
    for (jj=0;;jj++)                                               //~v50FR~
    {                                                              //~v50FI~
    	if (pcn)                                                   //~v50FI~
        {                                                          //~v50FI~
//			memcpy(wk,pco,(UINT)((ULONG)pcn-(ULONG)pco));          //~v50FR~//~v6hhR~
			memcpy(wk,pco,(UINT)((ULPTR)pcn-(ULPTR)pco));          //~v6hhI~
//          *(wk+(ULONG)pcn-(ULONG)pco)=0;                         //~v50FI~//~v6hhR~
            *(wk+(ULPTR)pcn-(ULPTR)pco)=0;                         //~v6hhI~
        }                                                          //~v50FI~
        else                                                       //~v50FI~
			strcpy(wk,pco);                                        //~v50FI~
        if (jj)			//not top path                             //~v50FI~
        	reppos=(int)strlen(outfp)+1;	//after \\   ;         //~v50FI~
//      if (strlen(outfp)+strlen(wk)>=_MAX_PATH)                   //~v6hLI~//~v6H9R~
        if (strlen(outfp)+strlen(wk)>=sizeof(outfp))               //~v6H9I~
//  		return ufileTooLongFullpathName(4/*rc*/);              //~v6H4R~
    		return ufileTooLongFullpathName(8/*rc*/);              //~v6H4I~
        strcat(outfp,wk);                                          //~v50FR~
    	if (!pcn)		//last memb pos                            //~v50FI~
        	if (!(Popt & FPOPT_MEMBEXP))	//not requested last memb expand//~v50FI~
            	break;                                             //~v50FI~
//expand path                                                      //~v50FI~
        if (WILDCARD(wk))                                          //~v50FI~
        {	                                                       //~v50FI~
#ifdef UNX                                                         //~v6b1I~
//  	  if (ufstat_wild(outfp,NULL))	//wildfilename exist really//~v6b1I~//~v6d3R~
//    	  if (!puftph && ufstat_wild(outfp,NULL))	//wildfilename exist really//~v6ExR~
      	  if (puftph || ufstat_wild(outfp,NULL))	//ftp or wildname member did not exist//~v6ExI~
#endif                                                             //~v6b1I~
          {                                                        //~v6b1I~
          	UTRACEP("%s:wildcard:%s,puftph=%p,ufstat_wild out=%s\n",UTT,wk,puftph,outfp);//~v6ExI~
		    filectr=4;	//. and .. and morte 2                     //~v50FR~
    		Snomsgdl=1;			//no notfound msg                  //~v50FI~
    		Sovfbreaksw=1;			//not required more than filectr//~v50FI~
//          if (pcn)	//path                                     //~v576R~
//          	attr=FILE_DIRECTORY;                               //~v576R~
//          else                                                   //~v576R~
            	attr=FILE_ALL;                                     //~v50FR~
    		rc=(int)udirlistsub(&filectr,outfp,(UINT)attr,&pudirlist0);//~v50FR~
    		Snomsgdl=0;                                            //~v50FI~
    		Sovfbreaksw=0;			//no notfound msg              //~v50FI~
            if (rc)                                                //~v50FI~
            {                                                      //~v50FI~
            	rc=4;                                              //~v50FI~
            	break;                                             //~v50FI~
            }                                                      //~v50FI~
            for (ii=0,membctr=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)//~v50FI~
                if (strcmp(pudirlist->name,".")                    //~v50FR~
                &&  strcmp(pudirlist->name,".."))                  //~v50FR~
                {                                                  //~v50FI~
                  if (!pcn || (pudirlist->attr & FILE_DIRECTORY))//not path or dir//~v576I~
                  {                                                //~v576I~
                	pudirlistm=pudirlist;	//save member          //~v50FI~
                    membctr++;                                     //~v50FI~
                  }                                                //~v576I~
                }                                                  //~v50FI~
            if (membctr==1)                                        //~v50FI~
            {                                                      //~v50FI~
            	repsw=1;                                           //~v50FI~
//  	        if (reppos+strlen(pudirlistm->name)>=_MAX_PATH)    //~v6ybR~
//  	        if (reppos+(int)strlen(pudirlistm->name)>=_MAX_PATH)//~v6ybI~//~v6H9R~
    	        if (reppos+(int)strlen(pudirlistm->name)>=sizeof(outfp))//~v6H9R~
//  				return ufileTooLongFullpathName(4/*rc*/);      //~v6H4R~
    				return ufileTooLongFullpathName(8/*rc*/);      //~v6H4I~
	        	strcpy(outfp+reppos,pudirlistm->name);             //~v50FI~
            }                                                      //~v50FI~
//          ufree(pudirlist0);                                     //~v50FI~//~v6qaR~
            UDIRLIST_FREE(pudirlist0);                             //~v6qaI~
            if (membctr!=1)                                        //~v50FR~
            {                                                      //~v50FI~
              if (pcn)  //not last                                 //~v539I~
                rc=3;                                              //~v539I~
              else                                                 //~v539I~
            	rc=2;                                              //~v50FI~
            	break;                                             //~v50FI~
            }                                                      //~v50FI~
          }                                                        //~v6b1I~
        }	//wildcard                                             //~v50FI~
//*                                                                //~v50FI~
        if (!pcn) 		//processed last                           //~v50FI~
        	break;                                                 //~v50FI~
        pco=pcn;                                                   //~v50FI~
//      pcn=ustrchr2(pco+1,DIR_SEPC);	//next path                //~v5ctR~
        pcn=ustrchr2(pco+1,dirsepc);	//next path                //~v5ctI~
    }//path loop                                                   //~v50FI~
    if (rc)                                                        //~v50FI~
    {                                                              //~v50FI~
    	if (pcn)                                                   //~v50FI~
        {                                                          //~v6hLI~
//      	if (strlen(outfp)+strlen(pcn)>=_MAX_PATH)              //~v6hLI~//~v6H9R~
        	if (strlen(outfp)+strlen(pcn)>=sizeof(outfp))          //~v6H9I~
//  			return ufileTooLongFullpathName(4/*rc*/);          //~v6H4R~
    			return ufileTooLongFullpathName(8/*rc*/);          //~v6H4I~
    		strcat(outfp,pcn);                                     //~v50FI~
        }                                                          //~v6hLI~
    }                                                              //~v50FI~
    else                                                           //~v50FI~
    	if (repsw)                                                 //~v50FI~
        	rc=1;                                                  //~v50FI~
                                                                   //~v50FI~
//  strncpy(Pfullpath,outfp,Plen);                                 //~v50FI~//~v6H9R~
    UstrncpyZ(Pfullpath,outfp,Plen);                               //~v6H9I~
	return rc;                                                     //~v50FI~
}//ufullpathwildexp                                                //~v50FI~
                                                                   //~v50FI~
//*******************************************************          //~v5kdI~
//*replace ./ and ../ of fullpath name                             //~v5kdI~
//rc 4:../ reached to root(continue process)                       //~v5kdI~
//*******************************************************          //~v5kdI~
int ufullpathresolvespecialdirid(char *Pfpath,int Pdirsepc)        //~v5kdI~
{                                                                  //~v5kdI~
    char *pc,*pc2=0;                                               //~v5kdR~
    UINT ulen;                                                     //~v5kdI~
    int rc=0;                                                      //~v5kdI~
//*********************************                                //~v5kdI~
    pc=Pfpath;                                                     //~v5kdI~
    for (pc=Pfpath;;pc=pc2)                                        //~v5kdR~
    {                                                              //~v5kdI~
    	pc2=ustrchr2(pc,(char)Pdirsepc);	//dir-sepc not part of dbcs//~v5kdR~
        if (!pc2)                                                  //~v5kdI~
        	break;                                                 //~v5kdI~
        pc2++;                                                     //~v5kdI~
        if (*pc2!='.')	//! "/."                                   //~v5kdI~
        	continue;                                              //~v5kdI~
        pc2++;           // /.?                                    //~v5kdI~
        if (!*pc2)		//  "/."                                   //~v5kdI~
        {                                                          //~v5kdI~
        	*(pc2-2)=0;                                            //~v5kdI~
            break;		//drop "/."                                //~v5kdI~
        }                                                          //~v5kdI~
        if (*pc2==Pdirsepc)		//  "/./"                          //~v5kdI~
        {                                                          //~v5kdI~
        	strcpy(pc2-2,pc2);                                     //~v5kdI~
            pc2-=2;                                                //~v5kdI~
            continue;                                              //~v5kdI~
        }                                                          //~v5kdI~
        if (*pc2!='.')		//!  "/.."                             //~v5kdI~
            continue;                                              //~v5kdI~
        pc2++;				//"/..?"                               //~v5kdI~
        if (*pc2 && *pc2!=Pdirsepc)		//!  "/.."  && ! "/../"    //~v5kdI~
            continue;                                              //~v5kdI~
//      ulen=(ULONG)pc2-3-(ULONG)Pfpath;	//parent path len      //~v5kdI~//~v6hhR~
//      ulen=(ULPTR)pc2-3-(ULPTR)Pfpath;	//parent path len      //~v6hhI~//~v6ybR~
        ulen=(UINT)((ULPTR)pc2-3-(ULPTR)Pfpath);	//parent path len//~v6ybR~
        pc=umemrchr2(Pfpath,(char)Pdirsepc,ulen);                  //~v5kdR~
        if (!pc)                                                   //~v5kdI~
        {                                                          //~v5kdI~
        	pc=Pfpath;                                             //~v5kdI~
            rc=4;                                                  //~v5kdI~
        }                                                          //~v5kdI~
        strcpy(pc,pc2);                                            //~v5kdI~
        pc2=pc;                                                    //~v5kdI~
	}//loop process parent                                         //~v5kdI~
	return rc;                                                     //~v5kdI~
}//ufullpathresolvespecialdirid                                    //~v5kdI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
//*******************************************************          //~v5nuI~
//*get file fullpath name for \:xxxx fmt                           //~v5nuI~
//*return:output buff addr or NULL if err                          //~v5nuI~
//*******************************************************          //~v5nuI~
char *ufullpathUNC(int Popt,char *Pfullpath,char *Pfilename,size_t Plen)//~v5nuI~
{                                                                  //~v5nuI~
	char fpath[_MAX_PATH],*pcd,*pc,*psrc;                          //~v5nuR~
    int pathlen,rootsw=0;                                          //~v5nuR~
//*********************************                                //~v5nuI~
    if (*(Pfilename+1)==':')      //"\:" fmt                       //~v5nuI~
    {                                                              //~v5nuI~
    	psrc=Pfilename+2;                                          //~v5nuI~
    	if (*(Pfilename+2)==DIR_SEPC)   //"\:\xx" fmt,use 1st level(servername) only//~v5nuI~
        	rootsw=1;                                              //~v5nuI~
    }                                                              //~v5nuI~
    else            //current drive is set to remote               //~v5nuI~
    {                                                              //~v5nuI~
    	psrc=Pfilename;                                            //~v5nuI~
    	if (*Pfilename==DIR_SEPC)   //"\xx" fmt,use 1st level(servername) only//~v5nuI~
    		if (*(Pfilename+1)==DIR_SEPC)   //"\xx" fmt,use 1st level(servername) only//~v5nuI~
        		rootsw=2;                                          //~v5nuR~
            else                                                   //~v5nuI~
        		rootsw=1;                                          //~v5nuI~
    }                                                              //~v5nuI~
    if (rootsw)                                                    //~v5nuI~
        psrc+=rootsw;   //copy from after "\"                      //~v5nuR~
    pcd=ScurrentdirUNC;			//current dir                      //~v5nuR~
    if (rootsw!=2 && *pcd)   //not set current dir                 //~v5nuR~
    {                                                              //~v5nuI~
    	if (rootsw)      //edit 1st level only                     //~v5nuR~
        {                                                          //~v5nuI~
        	pc=ustrchr2(pcd+2,DIR_SEPC);                           //~v5nuR~
            if (pc)                                                //~v5nuI~
            {                                                      //~v5nuI~
//            	pathlen=(ULONG)pc-(ULONG)pcd+1;                    //~v5nuI~//~v6hhR~
//           	pathlen=(ULPTR)pc-(ULPTR)pcd+1;                    //~v6hhI~//~v6ybR~
             	pathlen=(int)((ULPTR)pc-(ULPTR)pcd+1);             //~v6ybI~
                memcpy(fpath,pcd,(UINT)pathlen);                   //~v5nuI~
            }                                                      //~v5nuI~
            else                                                   //~v5nuI~
            {                                                      //~v5nuI~
            	pathlen=strlen(pcd);                               //~v5nuI~
                memcpy(fpath,pcd,(UINT)pathlen);                   //~v5nuI~
                *(fpath+pathlen++)=DIR_SEPC;                       //~v5nuI~
            }                                                      //~v5nuI~
            strcpy(fpath+pathlen,psrc);                            //~v5nuR~
        }                                                          //~v5nuI~
        else							//\:xx fmt                 //~v5nuI~
        {                                                          //~v5nuI~
            pathlen=strlen(pcd);                                   //~v5nuI~
            memcpy(fpath,pcd,(UINT)pathlen);                       //~v5nuI~
            if (*(fpath+pathlen-1)!=DIR_SEPC)                      //~v5nuR~
            	*(fpath+pathlen++)=DIR_SEPC;                       //~v5nuI~
            strcpy(fpath+pathlen,psrc);                            //~v5nuR~
        }                                                          //~v5nuI~
    }//curdir is already set                                       //~v5nuI~
    else                                                           //~v5nuI~
    {                                                              //~v5nuI~
    	strcpy(fpath,DIR_WINREMOTE);                               //~v5nuI~
    	strcpy(fpath+2,psrc);                                      //~v5nuR~
    }                                                              //~v5nuI~
    pc=_fullpath(Pfullpath,fpath,Plen);                            //~v5nuI~
    return pc;                                                     //~v5nuR~
}//ufullpathUNC                                                    //~v5nuI~
#endif	//WINREMOTESUPP                                            //~v5nuI~
#ifdef UNX  //!!!!!!!!!!!!!!!!!!                                   //~v327I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~v327I~
//*******************************************************      //~4C18I~
//*get file fullpath name                                      //~4C18I~
//*parm 1:output full pth mame                                 //~4C18I~
//*parm 2:input partial filename                               //~4C18I~
//*parm 3:output buff len                                      //~4C18I~
//*return:output buff addr or NULL if err                      //~4C18I~
//*******************************************************      //~4C18I~
char *ufullpath(char *Pfullpath,char *Pfilename,size_t Plen)   //~4C18I~
{                                                              //~4C18I~
#ifdef DOS                                                     //~4C18I~
static char Scurdirid[]=".\\";
static char Sparentdirid[]="..\\";
    union   REGS    reg;                                       //~4C18I~
  #ifdef DPMI                   //DPMI version                     //~v053I~
    char *tname;                //truename                         //~v105I~
  #else                       //not DPMI                           //~v053I~
    struct  SREGS   segreg;                                    //~4C18I~
  #endif                      //DPMI or not                        //~v109R~
    char wk[_MAX_PATH],*pwk;                                       //~v104R~
    int  rootsw;                                                   //~v053R~
    UINT len;                                                   //~5701I~
#else                                                          //~4C18I~
    char wk[_MAX_PATH];                                            //~v104R~
    char wk2[_MAX_PATH];                                           //~v104R~
    char *pc2;                                                     //~v018I~
//  char *pc3;                                                     //~v078R~
    int len,len2,len3;                                             //~v018R~
    int rc;                                                        //~v018I~
#endif                                                         //~4C18I~
//  char wkdropq[_MAX_PATH];    //drop quataition work             //~v6H2R~//~v6H9R~
    char wkdropq[_MAX_PATH_LONG];    //drop quataition work        //~v6H9I~
    char *pc;                                                  //~4C18I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
#ifdef UTF8SUPPH                                                   //~v62YI~
#ifdef AAA  //no effect  as a result                               //~v62YI~
    char *pu8,*pu8o;                                               //~v62YR~
#endif                                                             //~v62YI~
#endif                                                             //~v62YI~
    int rc2;                                                       //~v6H2I~
//*********************************                            //~4C18I~
#ifdef FTPSUPP                                                     //~v59nI~
	if (uftpisremote(Pfilename,&puftph))	//ftp filename         //~v5afR~
    	return uftpfullpath(puftph,Pfullpath,Pfilename,Plen);//0:host name is with filename//~v5afR~
#endif                                                             //~v59nI~
//    pc=Pfilename;               //search first char              //~v117R~
//    pc+=strspn(pc," "); //search first char                      //~v117R~
//    for (pcq=wkdropq,ii=0;*pc;pc++)                              //~v117R~
//    {                                                            //~v117R~
//        if (*pc!='"')                                            //~v117R~
//        {                                                        //~v117R~
//            if (++ii>=(int)(sizeof(wkdropq)-1))                  //~v117R~
//                break;                                           //~v117R~
//            *pcq++=*pc;                                          //~v117R~
//        }                                                        //~v117R~
//    }                                                            //~v117R~
//    *pcq=0;                                                      //~v117R~
//    uparsefname(0,Pfilename,wkdropq,0,0);//no opd,no need delmpos,outlen//~v6H2R~
    rc2=uparsefname(0,Pfilename,wkdropq,0,(int)sizeof(wkdropq),0);//no opd,no need delmpos,outlen//~v6H2I~
    if (rc2==8) //too long name                                    //~v6H2I~
        return 0;                                                  //~v6H2I~
    pc=wkdropq;                                                    //~v116R~
#ifdef DOS                                                     //~4C18I~
//*** dos                                                      //~4C18I~
//*conv "/" to "\"                                                 //~v233I~
    for (;*pc;pc++)                                                //~v233I~
        if (*pc=='/')       //slash = unix form                    //~v233I~
            *pc='\\';       //backslash = pc form                  //~v233I~
    pc=wkdropq;                                                    //~v233I~
//*drive letter                                                //~4C18I~
    memset(wk,0,sizeof(wk));                                    //~5701I~
//  if (!(pwk=strchr(pc,' '))) //no trailing space                 //~v078R~
//      len=strlen(pc);                                            //~v078R~
//  else                                                           //~v078R~
//      len=(UINT)((ULONG)pwk-(ULONG)pc);                          //~v078R~
    len=ustrrspn(pc," ")+1;    //last space offset                 //~v078R~
    if (len && *(pc+1)==':')            //device specified      //~5701R~
    {                                                          //~4C18I~
        memcpy(wk,pc,2);    //get drive letter             //~4C18I~
        pc+=2;                  //advance source addr          //~4C18I~
        len-=2;                                                 //~5701I~
    }                                                          //~4C18I~
    else                                                       //~4C18I~
    {                                                          //~4C18I~
        reg.h.ah=0x19;                  //get curr disk        //~4C18I~
        intdos(&reg,&reg);              //set cursor pos       //~4C18I~
        *wk=(char)('A'+reg.h.al);           //0:A,1:B,...          //~4C18I~
        *(wk+1)=':';                                           //~4C18I~
    }                                                          //~4C18I~
//*dir path                                                    //~4C18I~
    if ((*pc)=='\\')                    //from root            //~4C18I~
        memcpy(wk+2,pc,len);        //add file name             //~5701R~
    else                        //from cur dir                 //~4C18I~
    {                                                          //~4C18I~
    #ifdef DPMI                 //DPMI version                     //~v105I~
//      *(wk+2)=0;              //string                           //~v109R~
        *(wk+2)='.';            //need under DOS(not need under W95)//~v109I~
        *(wk+3)=0;              //string                           //~v109I~
        tname=_truename(wk,wk); //int21 7160(cx=2:get lfn)         //~v105I~
        if (!tname)                     //err                      //~v105I~
        {                                                          //~v105I~
            uerrmsg("get current dir(_truename) %s failed,rc=%d",  //~v105I~
                    "%s の現行ディレクトリー取得(_truename)の失敗,rc=%d",//~v105I~
                    Pfilename,errno);                              //~v105I~
            return 0;                                              //~v105I~
        }                                                          //~v105I~
        pwk=wk+3;                           //may over 3 byte      //~v105I~
    #else                       //not DPMI                         //~v109R~
        *(wk+2)='\\';                                          //~4C18I~
        reg.h.ah=0x47;                  //get curr dir         //~4C18I~
        reg.h.dl=toupper(*wk)-'A'+1;    //driveno 0:cur,1:A,2:B,...//~4C18I~
        pwk=wk+3;                           //for FP_SEG macro
//  #ifdef DPMI                 //DPMI version                     //~v105R~
//      reg.d.esi=(int)pwk;     //output dir name ptr              //~v105R~
//      udpmiintdos(&reg,&reg); //get cur dir to max _MAX_PATH     //~v105R~
//  #else                       //not DPMI                         //~v105R~
        segreg.ds=FP_SEG(pwk);          //output dir name ptr  //~4C18I~
        reg.x.si=FP_OFF(pwk);           //output dir name ptr  //~4C18I~
        intdosx(&reg,&reg,&segreg);     //get cur dir          //~4C18I~
//  #endif                      //DPMI or not                      //~v105R~
        if (reg.x.cflag)                //carry                //~4C18I~
        {                                                      //~4C18I~
            uerrmsg("intdosx-0x47(get current dir) for %s failed,rc=%d",//~5628R~
                    "%s の現行ディレクトリー取得の失敗,rc=%d",     //~v105R~
                    Pfilename,(int)reg.x.ax);                   //~5701R~
            return 0;                                           //~5628I~
        }                                                      //~4C18I~
    #endif                      //DPMI or not                      //~v105I~
        while (len>=2 && !memcmp(pc,Sparentdirid,2))//..xxx     //~5701R~
        {                                                       //~5701R~
            pc+=2;                                              //~5701R~
            len-=2;                                             //~5701R~
            if (len)                                            //~5701R~
            {                                                   //~5701R~
                if (*pc!='\\')          //"..xxx"               //~5701R~
                    return 0;                                   //~5701R~
                pc++;                                           //~5701R~
                   len--;                                       //~5701R~
            }                                                   //~5701R~
//          pwk=strrchr(wk,'\\');                                  //~v018R~
            pwk=wk+PATHLEN(wk)-1;                                  //~v018I~
            memset(pwk+1,0,strlen(pwk+1));                      //~5701I~
            if (*(pwk-1)!=':')                                  //~5701I~
                *pwk=0;    //drop parent dir                    //~5701I~
        }//loop process parent                                  //~5701R~
//*                                                             //~5701I~
        if (len)//filename on input                             //~5701M~
        {                                                       //~5701M~
            rootsw=(strlen(wk)==3);                             //~5701I~
            if (*pc==*Scurdirid)    //. curr id                 //~5701R~
            {                                                   //~5701R~
                pc++;                                           //~5701R~
                len--;                                          //~5701R~
                if (len)                                        //~5701R~
                {                                               //~5701R~
                    if (*pc!='\\')          //"..xxx"           //~5701R~
                        return 0;                               //~5701R~
                    pc++;                                       //~5701R~
                    len--;                                      //~5701R~
                }                                               //~5701R~
                if (len)                                        //~5701R~
                {                                               //~5701R~
                    pwk=wk+strlen(wk);                          //~5701R~
                    if (!rootsw)    //curr is not to root       //~5701R~
                        *pwk++='\\';                            //~5701R~
                    memcpy(pwk,pc,len);                         //~5701R~
                }                                               //~5701R~
            }//.                                                //~5701R~
            else    //not special .                             //~5701R~
            {                                                   //~5701R~
                pwk+=strlen(pwk);                               //~5701R~
                if (!rootsw)    //curr is not root              //~5701R~
                    *pwk++='\\';    //add intermediate          //~5701R~
                memcpy(pwk,pc,len);                             //~5701R~
            }                                                   //~5701R~
        }//not all space                                        //~5701R~
    }//not root dir specified                                                          //~4C18I~
//  if ((len=strlen(wk))>3 && *(wk+len-1)=='\\')                   //~v018R~
    if ((len=strlen(wk))>3                                         //~v018I~
    &&  PATHLEN(wk)==len)   //last is '\'                          //~v018I~
    {                                                           //~5701I~
        *(wk+len-1)=0;                                          //~5701I~
        len--;                                                  //~5701I~
    }                                                           //~5701I~
//  if (*(pc=wk+len-1)=='*')    //last is *                        //~v003R~
//      for (ii=len-1,pc--;ii;ii--,pc--)                           //~v003R~
//      {                                                          //~v003R~
//          if (*pc=='.')                                          //~v003R~
//              break;                                             //~v003R~
//          if (*pc=='\\')     //xx* fmt not but xx*.*             //~v003R~
//          {                                                      //~v003R~
//              strcpy(wk+len,".*");      //set xx*.* for DOS6.3   //~v003R~
//              len+=2;                                            //~v003R~
//              break;                                             //~v003R~
//          }                                                      //~v003R~
//      }                                                          //~v003R~
    if (Plen<=len)                                              //~5701I~
        return 0;                                               //~5701I~
    strcpy(Pfullpath,wk);                                       //~5701R~
//  UTRACEP("fullpath=%s\n",wk);                                   //~v5fvR~
    return Pfullpath;                                           //~5701R~
#else                                                          //~4C18I~
//** os/2                                                      //~4C18I~
    pc2=pc;         //save start pos                               //~v018I~
//  if (pc3=strchr(pc,' '),pc3) //trailing space pos               //~v078R~
//      *pc3=0;                 //once terminate                   //~v078R~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
  if (WIN_ISREMOTEDRIVE(pc)     //"\:" fmt                         //~v5nuR~
  ||  (Swinremotecdsw  &&  *(pc+1)!=':')    //on if current direve is "\:"//~v5nuR~
  )                                                                //~v5nuI~
    pc=ufullpathUNC(0,Pfullpath,pc,Plen);                          //~v5nuI~
  else                                                             //~v5nuI~
#endif                                                             //~v5nuI~
    pc=_fullpath(Pfullpath,pc,Plen);                           //~4C18R~
    UTRACEP("%s:_fullpath errno=%d,pc=%s\n",UTT,errno,pc);   //~v036R~//+v036I~              //~v5fvR~//~v6H9R~
//  if (pc3)                                                       //~v078R~
//      *pc3=' ';                                                  //~v078R~
    if(!pc)                                                    //~4C18I~
    {                                                              //~v018I~
//      if (pc3)                                                   //~v078R~
//          len=(int)((ULONG)pc3-(ULONG)pc2);                      //~v078R~
//      else                                                       //~v078R~
        len=(int)strlen(pc2);                                      //~v018R~
        if (len && *(pc2+len-1)=='\\')  //last is '\'              //~v018I~
            if ((len2=PATHLEN(pc2))!=len)       //last is dbcs 2nd byte '\'//~v018R~
            {                                                      //~v018I~
                if (len2<0)                                        //~v018I~
                    len2=0;                                        //~v018I~
                else                                               //~v018I~
                    memcpy(wk,pc2,(UINT)len2);  //copy up to parent with '\'//~v018R~
                *(wk+len2)='x';     //temporary filename without last '\'//~v018I~
                *(wk+len2+1)=0;     //null term                    //~v018I~
                pc=_fullpath(wk2,wk,_MAX_PATH);                    //~v018R~
                if (pc) //success                                  //~v018I~
                    if ((int)Plen>((len3=(int)strlen(wk2)-1)+(len-len2)))//~v034R~
                    {                                              //~v018I~
//                      strcpy(wk2+len3,pc2+len2);                 //~v020R~
                        memcpy(wk2+len3,pc2+len2,(UINT)(len-len2));//~v020I~
                        *(wk2+len3+len-len2)=0;                    //~v020I~
                        strcpy(Pfullpath,wk2);                     //~v018R~
                        pc=Pfullpath;                              //~v020I~
                        return pc;                                 //~v018I~
                    }                                              //~v018I~
            }                                                      //~v018I~
    #ifdef W32                                                     //~v022I~
        rc=errno;                                                  //~v022I~
        if (rc==ENAMETOOLONG)   //38                               //~v6H9I~
			ufileTooLongFullpathName2(0,Pfilename,0);              //~v6H9I~
        else                                                       //~v6H9I~
        if (rc==ERANGE)   //34:if over _MAX_PATH                   //~v6H7R~
            uerrmsg("_fullpath failed(errno=%d), path is too long for %s.",//~v6H7R~
                        "_fullpath失敗(errno=%d), %s のパスが長すぎる",//~v6H7I~
                        rc,Pfilename);                             //~v6H7I~
        else                                                       //~v6H7I~
    #else                                                          //~v022I~
        if ((rc=errno)==EOS2ERR)                                   //~v018R~
            ufileapierr("_fullpath OS/2 err",Pfilename,_doserrno); //~v018I~
        else                                                       //~v018I~
    #endif                                                         //~v022I~
            ufileapierr("_fullpath",Pfilename,rc);                 //~v018R~
    }                                                              //~v018I~
#ifdef W32                                                         //~v049R~
    else //_fullpath success                                       //~v049R~
    {                                                              //~v049R~
        if ((len=strlen(Pfullpath))>3                              //~v049R~
        &&  PATHLEN(Pfullpath)==len)    //last is '\'              //~v049R~
            *(Pfullpath+len-1)=0;                                  //~v049R~
#ifdef UTF8SUPPH                                                   //~v62YI~
//      UTRACED("fullpath in",wkdropq,strlen(wkdropq));            //~v62YR~
//      UTRACED("fullpath out",pc,strlen(pc));    //issued befor trace init, and open utrace.out//~v62YR~
#ifdef AAA  //no effect  as a result                               //~v62YI~
        pu8=ustrrchr2(wkdropq,'\\');                               //~v62YI~
        if (!pu8                                                   //~v62YR~
		&&  *wkdropq!='.')	//no path specified and not cdir       //~v62YI~
        {                                                          //~v62YI~
	        pu8o=ustrrchr2(pc,'\\');                               //~v62YI~
            if (pu8o)                                              //~v62YI~
            {                                                      //~v62YI~
        		pu8=wkdropq;                                       //~v62YR~
                pu8o++;                                            //~v62YI~
            	if (strcmp(pu8,pu8o))	//unmatch last entry       //~v62YR~
            		strcpy(pu8o,pu8);	//try;set original if windows modified//~v62YR~
            }                                                      //~v62YI~
        }                                                          //~v62YI~
#endif                                                             //~v62YI~
#endif                                                             //~v62YI~
    }                                                              //~v049R~
#endif                                                             //~v049R~
    return pc;                                                 //~4C18I~
#endif                                                         //~4C18I~
}//ufullpath                                                    //~4C31R~
//*******************************************************          //~v016I~
//*get file path name length(length containing last '\' from top)  //~v016I~
//*parm 1:filename                                                 //~v016I~
//*return:length, <0 if err                                        //~v016I~
//*******************************************************          //~v016I~
int upathlen(char *Pfilename)                                      //~v016I~
{                                                                  //~v016I~
    char *pc;                                                      //~v016R~
//*********************************                                //~v016I~
#ifdef W32                                                         //~v5aaI~
  if (pc=strrchr(Pfilename,FTP_DIR_SEPC),!pc)	//allow "/" as dir sep//~v5aaR~
  {                                                                //~v5aaI~
#endif                                                             //~v5aaI~
    if (pc=ustrrchr2(Pfilename,'\\'),!pc)                          //~v022R~
        return -16;     //avoid -1                                 //~v016I~
#ifdef W32                                                         //~v5aaI~
  }                                                                //~v5aaI~
#endif                                                             //~v5aaI~
//  return (int)((ULONG)pc-(ULONG)Pfilename)+1;                    //~v016R~//~v6hhR~
    return (int)((ULPTR)pc-(ULPTR)Pfilename)+1;                    //~v6hhI~
}//upathlen                                                        //~v016I~
//*******************************************************       //~5708I~
//*get current drive                                            //~5708I~
//*parm  :none                                                  //~5708I~
//*return:drive letter                                          //~5708I~
//*******************************************************       //~5708I~
unsigned char ugetdrive(void)                                   //~5708I~
{                                                               //~5708I~
#ifdef DOS                                                      //~5708I~
    UINT driveno;                                               //~5708I~
#else                                                           //~5708I~
    int  driveno;                                               //~5708I~
#endif                                                          //~5708I~
//*********************************                             //~5708I~
#ifdef DOS                                                      //~5708I~
//*** dos                                                       //~5708I~
    _dos_getdrive(&driveno);                    //current0:A,1:B,..//~5708I~
                                                                //~5708I~
#else                                                           //~5708I~
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
	      #ifdef WINREMOTESUPP     //\\xxx\yy support              //~v5nuI~
	       if (Swinremotecdsw)      //on if current direve is "\:" //~v5nuI~
            driveno=WIN_UNCID-'A'+1;                               //~v5nuR~
           else                                                    //~v5nuI~
          #endif                                                   //~v5nuI~
            driveno=_getdrive();                                   //~v034R~
        #else                                                      //~v034I~
        driveno=getdisk();                                         //~v022I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
//** os/2                                                       //~5708I~
    driveno=_getdrive();                                        //~5708R~
    #endif                                                         //~v022I~
#endif                                                          //~5708I~
    return (unsigned char)('A'+driveno-1);                         //~v022M~
}//ugetdrive                                                    //~5708I~
                                                                //~5708I~
//*******************************************************       //~5708I~
//*get current dir fullpath                                     //~5708I~
//*parm  :output buff                                           //~5708I~
//*return:ptr to buff                                           //~5708I~
//*******************************************************       //~5708I~
char *ugetcwd(unsigned char *Pbuff)                             //~5708R~
{                                                               //~5708I~
//*********************************                             //~5708I~
#ifdef DOS                                                      //~5708I~
//*** dos                                                       //~5708I~
    #ifdef DPMI                 //DPMI version                     //~v053I~
        return ufullpath(Pbuff,".",_MAX_PATH);                     //~v053I~
    #else                       //not DPMI                         //~v053I~
    return getcwd(Pbuff,_MAX_PATH);                             //~5708R~
    #endif                      //DPMI or not                      //~v053I~
                                                                //~5708I~
#else                                                           //~5708I~
    #ifdef W32                                                     //~v022I~
	  #ifdef WINREMOTESUPP     //\\xxx\yy support                  //~v5nuI~
	    if (Swinremotecdsw)      //on if current direve is "\:"    //~v5nuI~
        {                                                          //~v5nuI~
		  if (*ScurrentdirUNC)                                     //~v5nuI~
        	strcpy(Pbuff,ScurrentdirUNC);                          //~v5nuR~
          else                                                     //~v5nuI~
        	strcpy(Pbuff,DIR_WINREMOTE);                           //~v5nuR~
          return Pbuff;                                            //~v5nuI~
        }                                                          //~v5nuI~
      #endif                                                       //~v5nuI~
        return getcwd(Pbuff,_MAX_PATH);                            //~v022I~
    #else                                                          //~v022I~
//** os/2                                                       //~5708I~
    return _getcwd(Pbuff,_MAX_PATH);                            //~5708R~
    #endif                                                         //~v022I~
                                                                //~5708I~
#endif                                                          //~5708I~
}//ugetcwd                                                      //~5708I~
//*******************************************************          //~v6ybI~
//*rc=0:ok,1:reserved name,4:err                                   //~v6ybI~
//*******************************************************          //~v6ybI~
#ifdef W32                                                         //~v6ybI~
int ugetcwdW(int Popt,unsigned char *Pbuff)                        //~v6ybI~
{                                                                  //~v6ybI~
	char *pc;                                                      //~v6ybI~
    int rc=0;                                                      //~v6ybI~
//**************	                                               //~v6ybI~
	pc=ugetcwd(Pbuff);                                             //~v6ybI~
    if (!pc)                                                       //~v6ybI~
    	return 4;                                                  //~v6ybI~
    if (IS_RESERVED_NAME(Pbuff))                                   //~v6ybI~
    {                                                              //~v6ybI~
    	rc=1;                                                      //~v6ybI~
		if (Popt & UGCWDWO_DROPPREFIX) //drop reserved name prefix and set rc=1//~v6ybI~
        	strcpy(Pbuff,Pbuff+RESERVED_NAMEID_CTR);               //~v6ybI~
	}                                                              //~v6ybI~
    return rc;                                                     //~v6ybI~
}//ugetcwdW                                                        //~v6ybI~
#endif                                                          //~5708I~//~v6ybR~
//*******************************************************       //~5708I~
//*change current drive                                         //~5708I~
//*parm 1:drive letter                                          //~5708I~
//*return:0:ok else err                                         //~5708I~
//*******************************************************       //~5708I~
int uchdrive(char Pdriveletter)                                 //~5708R~
{                                                               //~5708I~
#ifdef DOS                                                      //~5708I~
    UINT drivenoo,drivenon,maxdrive;                            //~5708I~
#else                                                           //~5708I~
#endif                                                          //~5708I~
    int rc;                                                     //~5708I~
//*********************************                             //~5708I~
#ifdef DOS                                                      //~5708I~
//*** dos                                                       //~5708I~
    drivenon=toupper((int)Pdriveletter)-'A'+1;  //driveno 0:A,1:B,...//~5708R~
    _dos_setdrive(drivenon,&maxdrive);                          //~5708I~
    _dos_getdrive(&drivenoo);                   //current0:A,1:B,..//~5708I~
    rc=(drivenon!=drivenoo);                                    //~5708I~
                                                                //~5708I~
#else                                                           //~5708I~
//** os/2                                                       //~5708I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
  if (Pdriveletter==WIN_UNCID)                                     //~v5nuR~
  {                                                                //~v5nuI~
	Swinremotecdsw=1;      //on if current direve is "\:"          //~v5nuI~
    rc=0;                                                          //~v5nuI~
  }                                                                //~v5nuI~
  else                                                             //~v5nuI~
  {                                                                //~v5nuI~
	Swinremotecdsw=0;      //on if current direve is "\:"          //~v5nuI~
#endif                                                             //~v5nuI~
//  rc=_chdrive(toupper((int)Pdriveletter)-'A'+1);              //~5708I~//~v6y0R~
    rc=toupper((int)Pdriveletter)-'A'+1;                           //~v6y0I~
    if (rc<1||rc>26)                                               //~v6y0I~
        rc=4;                                                      //~v6y0I~
    else                                                           //~v6y0I~
        rc=_chdrive(rc);                                           //~v6y0I~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nuI~
  }                                                                //~v5nuI~
#endif                                                             //~v5nuI~
                                                                //~5708I~
#endif                                                          //~5708I~
    if (rc)                                                     //~5708I~
        uerrmsg("Set drive failed for %c:",                     //~5708I~
                "省略時ドライブ設定の失敗(%c:)",                //~5708I~
                Pdriveletter);                                  //~5708I~
    return rc;                                                  //~5708R~
}//uchdrive                                                     //~5708I~
                                                                //~5708I~
//*******************************************************       //~5708I~
//*change current directory                                     //~5708R~
//*parm 1:path name                                             //~5708I~
//*return:0:ok else err                                         //~5708I~
//*******************************************************       //~5708I~
//int uchdir(unsigned char *Ppath)                                 //~v578R~
int uchdir(int Popt,unsigned char *Ppath)                          //~v578I~
{                                                               //~5708I~
    int rc;                                                     //~5708I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//*********************************                             //~5708I~
#ifdef DOS                                                      //~5708I~
//*** dos                                                       //~5708I~
    rc=chdir(Ppath);                                            //~5708I~
                                                                //~5708I~
#else                                                           //~5708I~
    #ifdef W32                                                     //~v022I~
#ifdef FTPSUPP                                                     //~v59nI~
	  	if (uftpisremote(Ppath,&puftph))	//ftp filename         //~v5afR~
        	return uftpchdir(puftph,Popt,Ppath);                   //~v5afR~
#endif                                                             //~v59nI~
	#ifdef WINREMOTESUPP     //\\xxx\yy support                    //~v5nuI~
  	  if (WIN_ISREMOTEPATH(Ppath))                                 //~v5nuR~
      {                                                            //~v5nuI~
		UstrncpyZ(ScurrentdirUNC,Ppath,sizeof(ScurrentdirUNC));    //~v5nuR~
        rc=0;                                                      //~v5nuI~
      }                                                            //~v5nuI~
  	  else                                                         //~v5nuR~
	#endif                                                         //~v5nuR~
        rc=chdir(Ppath);                                           //~v022I~
    #else                                                          //~v022I~
//** os/2                                                       //~5708I~
    rc=_chdir(Ppath);                                           //~5708I~
    #endif                                                         //~v022I~
                                                                //~5708I~
#endif                                                          //~5708I~
    if (rc)                                                     //~5708I~
    {                                                           //~5708I~
      if (!(Popt & UCHD_NOMSG))		//not no errmsg option         //~v578I~
        uerrmsg("Set current directory failed for %s",          //~5708R~
                "現行ディレクトリー設定の失敗(%s)",             //~5708R~
//              Ppath);                                         //~5708R~//~v6ygR~
                STD_FNM(Ppath));                                   //~v6ygI~
        rc=errno;                                               //~5708I~
    }                                                           //~5708I~
    return rc;                                                  //~5708R~
}//uchdir                                                       //~5708I~
//**********************************************************************//~v781I~
unsigned udosfindfirstOpt(int Popt,char *Ppfname,HDIR *Pphdir,unsigned int Pattr,FILEFINDBUF3 *Ppfstat3)//~v781I~
{                                                                  //~v781I~
	unsigned int rc;                                               //~v781I~
//************************                                         //~v781I~
	UTRACEP("%s:opt=0x%x,attr=0x%x,fnm=%s\n",UTT,Popt,Pattr,Ppfname);//~v781I~
	SswFFopt=Popt & ~UDFFOO_NOMSG;                                 //~v781I~
	if (Popt & UDFFOO_NOMSG)		//no errmsg option             //~v781I~
		rc=udosfindfirstnomsg(Ppfname,Pphdir,Pattr,Ppfstat3);      //~v781I~
    else                                                           //~v781I~
		rc=udosfindfirst(Ppfname,Pphdir,Pattr,Ppfstat3);           //~v781I~
	SswFFopt=0;                                                    //~v781I~
	UTRACEP("%s:rc=%d,hdir=%p,fnm=%s\n",UTT,rc,*Pphdir,Ppfname);   //~v781I~
    return rc;                                                     //~v781I~
}                                                                  //~v781I~
//**********************************************************************//~v132I~
// udosfindfirstnomsg(no notfound err msg)                         //~v179R~
// parm1  :file name                                               //~v179R~
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0//~v179R~
// parm3  :search file attribute                                   //~v179R~
// parm4  :found file info                                         //~v179R~
// return :r.c                                                     //~v179R~
//**********************************************************************//~v132I~
unsigned udosfindfirstnomsg(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,//~v179R~
                        FILEFINDBUF3 *Ppfstat3)                    //~v179R~
{                                                                  //~v179R~
    unsigned rc;                                                   //~v179R~
//*********************************                                //~v179R~
    Snomsgff=1;                                                    //~v179R~
    rc=udosfindfirst(Ppfname,Pphdir,Pattr,Ppfstat3);               //~v179R~
    Snomsgff=0;                                                    //~v179R~
    Snomsgffnext=1;                                                //~v6k7I~
    return rc;                                                     //~v179R~
}//udosfindfirstnomsg                                              //~v179R~
//**********************************************************************
// find first
// parm1  :file name
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0
// parm3  :search file attribute
// parm4  :found file info
// return :r.c
//**********************************************************************
unsigned udosfindfirst(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,
                        FILEFINDBUF3 *Ppfstat3)
{
#ifdef DOS
#else
    #ifdef W32                                                     //~v022M~
        #if (_MSC_VER >= 800)                                      //~v034I~
            HDIR   *phdir;                                         //~v034I~
            WIN32_FIND_DATA w32fd;                                 //~v034I~
            unsigned int wattrf,wattrp;                            //~v079R~
#ifdef FTPSUPP                                                     //~v59nI~
            int ftpopt;                                            //~v59nR~
#endif                                                             //~v59nI~
        #else                                                      //~v034I~
        #endif                                                     //~v034I~
    #else                                                          //~v022M~
    ULONG  cfilename=1;     //file name count
    HDIR   *phdir;
    #endif                                                         //~v022M~
#endif
    unsigned rc;
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//*********************************
    Snomsgffnext=0;                                                //~v6k7I~
    SdirlistOtherAttrCtr=0;                                        //~v6kmR~
    SdirlistOtherAttrCtr_Dir=0;                                    //~v781I~
#ifdef DOS

  #ifdef DPMI                   //DPMI version                     //~v105I~
    rc=udpmifindfirst(Ppfname,          //path,filename            //~v105I~
                        Pphdir,                                    //~v105R~
                        Pattr,          //search file attr         //~v105I~
                        Ppfstat3);//output file info               //~v105I~
  #else                       //not DPMI                           //~v105I~
    rc=(int)_dos_findfirst(Ppfname,          //global name
                            Pattr,          //search file attr
                           (struct find_t*)Ppfstat3);//output file info
  #endif                      //not DPMI                           //~v105I~
    if(rc) //v4.0d
    {
        rc=errno;       //return value                             //~v123I~
      #ifdef DPMI                   //DPMI version                 //~v053I~
        if(errno==ENOENT || errno==ENMFILE) //not found or no more file//~v053R~
      #else                       //not DPMI                       //~v053I~
        if(errno==ENOENT)
      #endif                      //not DPMI                       //~v053I~
         {                                                         //~v183I~
          if (!Snomsgff)                                           //~v179R~
            ufilenotfound(Ppfname,rc);                          //~5909I~
         }                                                         //~v183I~
        else
      #ifdef DPMI                   //DPMI version                 //~v105I~
            ufileapierr("udpmifindfirst",Ppfname,errno);           //~v105I~
      #else                       //not DPMI                       //~v105I~
            ufileapierr("_dos_findfirst",Ppfname,errno);        //~5905I~
      #endif                      //not DPMI                       //~v105I~
    }//first time

#else   //os/2
    #ifdef W32                                                     //~v022M~
        #if (_MSC_VER >= 800)                                      //~v034M~
            if (!(phdir=Pphdir))                                   //~v034M~
                phdir=&Shdirfirst;                                 //~v034M~
#ifdef FTPSUPP                                                     //~v59nI~
			if (uftpisremote(Ppfname,&puftph))                     //~v5afR~
          	{                                                      //~v59nI~
            	ftpopt=UFTPFF_NOMSG*(Snomsgff!=0);	//no delete ok msg sw//~v59nR~
		   		return uftpfindfirst(puftph,ftpopt,Ppfname,(ULONG*)Pphdir,Pattr,Ppfstat3);//~v5afR~
            }                                                      //~v59nI~
#endif                                                             //~v59nI~
            *phdir=FindFirstFile(Ppfname,&w32fd);                  //~v034M~
            if (*phdir==INVALID_HANDLE_VALUE)                      //~v034M~
                rc=GetLastError();                                 //~v034M~
            else                                                   //~v034M~
            {                                                      //~v034M~
                if (!udosiswinnt() //win95/98                      //~v5fsI~
                &&   ROOTDIR_LOCAL(Ppfname))   //success for root when 95/98//~v5fsR~
                {                                                  //~v5fsI~
                    ufilew32closehdir(*phdir);//free handle        //~v5fsI~
                    rc=2;                                          //~v5fsI~
                    return rc;                                     //~v5fsI~
                }                                                  //~v5fsI~
//              if (rc=ufilew32savehdir(*phdir,Pattr),rc)          //~v087R~
//                  return rc;                                     //~v087R~
                if (rc=ufilew32savehdir(*phdir,Pattr),rc)          //~v124I~
                    return rc;                                     //~v124I~
//              ufilew32copyfstat(Ppfstat3,&w32fd);                //~v034M~//~v6k4R~
//              ufilew32copyfstat(Ppfname,Ppfstat3,&w32fd);        //~v6k4R~
                ufilew32copyfstat(UFCFSO_DIRLIST,Ppfname,Ppfstat3,&w32fd);//~v6k4I~
//              if (Ppfstat3->attrFile & Pattr)                    //~v079R~
                wattrf=(Ppfstat3->attrFile & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v079I~
                wattrp=(Pattr & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v079I~
                if (!wattrf     //select A,R attr file unconditionaly//~v079I~
                ||  (wattrp & wattrf)==wattrf)  //file bit included in parm attr//~v079I~
                    rc=0;                                          //~v034I~
                else                                               //~v034I~
                {                                                  //~v197I~
                	SdirlistOtherAttrCtr++;                        //~v6kmR~
                    if ((wattrf & FILE_DIRECTORY)                  //~v781I~
	                &&  !(wattrp & FILE_DIRECTORY))                //~v781I~
                    {                                              //~v783I~
                      if (!strcmp(Ppfstat3->cFileName,".") || !strcmp(Ppfstat3->cFileName,".."))//~v783R~
	                	SdirlistOtherAttrCtr--;                    //~v783I~
                      else                                         //~v783I~
	                	SdirlistOtherAttrCtr_Dir++;                //~v781I~
                    }                                              //~v783I~
                    UTRACEP("%s:member=%s,wattrf=0x%x,wattrp=0x%x,otherAttr=%d,otherAttr_dir=%d\n",UTT,Ppfstat3->cFileName,wattrf,wattrp,SdirlistOtherAttrCtr,SdirlistOtherAttrCtr_Dir);//~v781R~
//                  rc=udosfindnext(*phdir,Ppfstat3);              //~v034R~//~v6k4R~
                    rc=udosfindnext(Ppfname,*phdir,Ppfstat3);      //~v6k4I~
                    if (rc)                                        //~v197I~
                        rc=ERROR_FILE_NOT_FOUND;                   //~v197I~
                }                                                  //~v197I~
                if (!rc)                                           //~v087I~
//                  if (Pphdir)     //handle return required for find next//~v124R~
//                      if (rc=ufilew32savehdir(*phdir,Pattr),rc)  //~v124R~
                    if (!Pphdir)     //handle return not required for find next//~v124I~
                        if (rc=ufilew32closehdir(*phdir),rc)//free handle//~v124R~
                            return rc;                             //~v087R~
            }                                                      //~v034M~
        #else                                                      //~v034M~
        if (!Pphdir)                //for compiler warning         //~v022I~
            *Pphdir=Shdirfirst;                                    //~v022I~
        rc=findfirst(Ppfname,(struct ffblk *)(PVOID)Ppfstat3,Pattr);//~v022M~
        if (rc)                                                    //~v022M~
            rc=doserrno;                                           //~v022M~
        #endif                                                     //~v034M~
    #else                                                          //~v022M~
    if (!(phdir=Pphdir))
        phdir=&Shdirfirst;
    *phdir=(ULONG)HDIR_CREATE;  //dir handle create req
    rc=DosFindFirst(Ppfname,          //global name
                    phdir,          //search handle
                    Pattr,          //search file attr
                    Ppfstat3,       //output file information
                    sizeof(FILEFINDBUF3),//output area size
                    &cfilename,     //request file count
                    FIL_STANDARD);  //file information level
    #endif                                                         //~v022I~
    if(rc)
    {
       UTRACEP("%s:rc=%d,otherAttr=%d,otherAttr_dir=%d\n",UTT,rc,SdirlistOtherAttrCtr,SdirlistOtherAttrCtr_Dir);//~v783R~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nBM~
      	if(rc==ERROR_BAD_NETPATH)                                  //~v5nBR~
      		rc=ERROR_PATH_NOT_FOUND;                               //~v5nBR~
#endif                                                             //~v5nBM~
        if(rc==ERROR_NO_MORE_FILES
        || rc==ERROR_FILE_NOT_FOUND
        || rc==ERROR_PATH_NOT_FOUND)
        {                                                          //~v179R~
          if (!Snomsgff)                                           //~v179R~
           if (rc==ERROR_PATH_NOT_FOUND)                           //~v5nBI~
            ufilepatherr(Ppfname,(int)rc);                         //~v5nBI~
           else                                                    //~v5nBI~
           {                                                       //~v6kmR~
           if (SdirlistOtherAttrCtr)                               //~v6kmR~
           {                                                       //~v781I~
            if ((SswFFopt & UDFFOO_ALLOWDIR)		//no errmsg option//~v781R~
            && SdirlistOtherAttrCtr_Dir==SdirlistOtherAttrCtr)     //~v781I~
            {                                                      //~v781I~
            	UTRACEP("%s:skip err of other attr by dirctr=%d,otherall=%d\n",UTT,SdirlistOtherAttrCtr_Dir,SdirlistOtherAttrCtr);//~v781I~
                rc=0;                                              //~v781I~
            }                                                      //~v781I~
            else                                                   //~v781I~
            ufilenotfoundotherexist(Ppfname,(int)rc);              //~v6kmR~
           }                                                       //~v781I~
           else                                                    //~v6kmR~
            ufilenotfound(Ppfname,(int)rc);                     //~5909R~
           }                                                       //~v6kgI~
        }                                                          //~v179R~
        else
        {                                                          //~v5nBI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v5nBI~
          if (rc==ERROR_INVALID_NAME)                              //~v5nBI~
            uerrmsg("Invalid Name Format(%s)",0,                   //~v5nBI~
            	Ppfname);                                          //~v5nBI~
          else                                                     //~v5nBI~
          if(rc==ERROR_LOGON_FAILURE)//password protected          //~v5nBI~
            uerrmsg("Logon required(%s)",0,                        //~v5nBI~
            	Ppfname);                                          //~v5nBI~
          else                                                     //~v5nBI~
          if(rc==ERROR_ACCESS_DENIED)//:=5 may be by UAC           //~v6uJI~
			ufilenopermission("DosFindFirst",Ppfname,(int)rc);     //~v6uJI~
          else                                                     //~v6uJI~
#endif                                                             //~v5nBI~
            ufileapierr("DosFindFirst",Ppfname,(int)rc);        //~5905R~
        }                                                          //~v5nBI~
    }

#endif

  return rc;
}//udosfindfirst

//#ifdef W32                                                       //~v6H9R~
////**********************************************************************//~v6H9R~
//unsigned udosfindfirstW(int Popt,char *Ppfname,UWCH *PpfnameW,HDIR *Pphdir,unsigned int Pattr,//~v6H9R~
//                        FILEFINDBUF3 *Ppfstat3)                  //~v6H9R~
//{                                                                //~v6H9R~
//            HDIR   *phdir;                                       //~v6H9R~
//            WIN32_FIND_DATAW w32fd;                              //~v6H9R~
//            unsigned int wattrf,wattrp;                          //~v6H9R~
////          int ftpopt;                                          //~v6H9R~
//    unsigned rc;                                                 //~v6H9R~
////  PUFTPHOST puftph;                                            //~v6H9R~
////*********************************                              //~v6H9R~
////  Snomsgffnext=0;                                              //~v6H9R~
//    SdirlistOtherAttrCtr=0;                                      //~v6H9R~
//            if (!(phdir=Pphdir))                                 //~v6H9R~
//                phdir=&Shdirfirst;                               //~v6H9R~
////            if (uftpisremote(Ppfname,&puftph))                 //~v6H9R~
////            {                                                  //~v6H9R~
////                ftpopt=UFTPFF_NOMSG*(Snomsgff!=0);  //no delete ok msg sw//~v6H9R~
////                return uftpfindfirst(puftph,ftpopt,Ppfname,(ULONG*)Pphdir,Pattr,Ppfstat3);//~v6H9R~
////            }                                                  //~v6H9R~
////          *phdir=FindFirstFile(Ppfname,&w32fd);                //~v6H9R~
//            *phdir=uFindFirstFileWLong(0,Ppfname,PpfnameW,&w32fd);    //longname support//~v6H9R~
//            if (*phdir==INVALID_HANDLE_VALUE)                    //~v6H9R~
//                rc=GetLastError();                               //~v6H9R~
//            else                                                 //~v6H9R~
//            {                                                    //~v6H9R~
//                if (!udosiswinnt() //win95/98                    //~v6H9R~
//                &&   ROOTDIR_LOCAL(Ppfname))   //success for root when 95/98//~v6H9R~
//                {                                                //~v6H9R~
//                    ufilew32closehdir(*phdir);//free handle      //~v6H9R~
//                    rc=2;                                        //~v6H9R~
//                    return rc;                                   //~v6H9R~
//                }                                                //~v6H9R~
//                if (rc=ufilew32savehdir(*phdir,Pattr),rc)        //~v6H9R~
//                    return rc;                                   //~v6H9R~
////              ufilew32copyfstat(UFCFSO_DIRLIST,Ppfname,Ppfstat3,&w32fd);//~v6H9R~
//                ufilew32copyfstatW(UFCFSO_DIRLIST,Ppfname,PpfnameW,Ppfstat3,&w32fd);//~v6H9R~
//                wattrf=(Ppfstat3->attrFile & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v6H9R~
//                wattrp=(Pattr & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v6H9R~
//                if (!wattrf     //select A,R attr file unconditionaly//~v6H9R~
//                ||  (wattrp & wattrf)==wattrf)  //file bit included in parm attr//~v6H9R~
//                    rc=0;                                        //~v6H9R~
//                else                                             //~v6H9R~
//                {                                                //~v6H9R~
//                    SdirlistOtherAttrCtr++;                      //~v6H9R~
////                  rc=udosfindnext(Ppfname,*phdir,Ppfstat3);    //~v6H9R~
//                    rc=udosfindnextW(Popt,Ppfname,PpfnameW,*phdir,Ppfstat3);//~v6H9R~
//                    if (rc)                                      //~v6H9R~
//                        rc=ERROR_FILE_NOT_FOUND;                 //~v6H9R~
//                }                                                //~v6H9R~
//                if (!rc)                                         //~v6H9R~
//                    if (!Pphdir)     //handle return not required for find next//~v6H9R~
//                        if (rc=ufilew32closehdir(*phdir),rc)//free handle//~v6H9R~
//                            return rc;                           //~v6H9R~
//            }                                                    //~v6H9R~
//    if(rc)                                                       //~v6H9R~
//    {                                                            //~v6H9R~
//        if(rc==ERROR_BAD_NETPATH)                                //~v6H9R~
//            rc=ERROR_PATH_NOT_FOUND;                             //~v6H9R~
//        if(rc==ERROR_NO_MORE_FILES                               //~v6H9R~
//        || rc==ERROR_FILE_NOT_FOUND                              //~v6H9R~
//        || rc==ERROR_PATH_NOT_FOUND)                             //~v6H9R~
//        {                                                        //~v6H9R~
////        if (!Snomsgff)                                         //~v6H9R~
//          if (!(Popt & UDFFWO_NOMSG))                            //~v6H9R~
//           if (rc==ERROR_PATH_NOT_FOUND)                         //~v6H9R~
//            ufilepatherr(Ppfname,(int)rc);                       //~v6H9R~
//           else                                                  //~v6H9R~
//           {                                                     //~v6H9R~
//           if (SdirlistOtherAttrCtr)                             //~v6H9R~
//            ufilenotfoundotherexist(Ppfname,(int)rc);            //~v6H9R~
//           else                                                  //~v6H9R~
//            ufilenotfound(Ppfname,(int)rc);                      //~v6H9R~
//           }                                                     //~v6H9R~
//        }                                                        //~v6H9R~
//        else                                                     //~v6H9R~
//        {                                                        //~v6H9R~
//          if (rc==ERROR_INVALID_NAME)                            //~v6H9R~
//            uerrmsg("Invalid Name Format(%s)",0,                 //~v6H9R~
//                Ppfname);                                        //~v6H9R~
//          else                                                   //~v6H9R~
//          if(rc==ERROR_LOGON_FAILURE)//password protected        //~v6H9R~
//            uerrmsg("Logon required(%s)",0,                      //~v6H9R~
//                Ppfname);                                        //~v6H9R~
//          else                                                   //~v6H9R~
//          if(rc==ERROR_ACCESS_DENIED)//:=5 may be by UAC         //~v6H9R~
//            ufilenopermission("DosFindFirst",Ppfname,(int)rc);   //~v6H9R~
//          else                                                   //~v6H9R~
//            ufileapierr("DosFindFirst",Ppfname,(int)rc);         //~v6H9R~
//        }                                                        //~v6H9R~
//    }                                                            //~v6H9R~
//  return rc;                                                     //~v6H9R~
//}//udosfindfirst                                                 //~v6H9R~
//#endif                                                           //~v6H9R~
//**********************************************************************
// find next
// parm1  :HDIR specified at findfirst. for dos specify always 0
// parm2  :found file info
// return :r.c  0:found 4:no more file
//**********************************************************************
//unsigned udosfindnext(HDIR Phdir,FILEFINDBUF3 *Ppfstat3)         //~v6k4R~
unsigned udosfindnext(char *Ppath,HDIR Phdir,FILEFINDBUF3 *Ppfstat3)//~v6k4I~
{                                                                  //~v6k7I~
	int nomsg;                                                     //~v6k7I~
    unsigned rc;                                                   //~v6k7I~
unsigned udosfindnextmsg(char *Ppath,HDIR Phdir,FILEFINDBUF3 *Ppfstat3);//~v6k7R~
//************************                                         //~v6k7I~
	nomsg=Snomsgff;                                                //~v6k7I~
    Snomsgff=Snomsgffnext;                                         //~v6k7I~
	rc=udosfindnextmsg(Ppath,Phdir,Ppfstat3);                      //~v6k7I~
//  Snomsgff=nomsg;                                                //~v6k7I~//~v6y0R~
    Snomsgff=(char)nomsg;                                          //~v6y0I~
    return rc;                                                     //~v6k7I~
}                                                                  //~v6k7I~
//**********************************************                   //~v6k7I~
unsigned udosfindnextmsg(char *Ppath,HDIR Phdir,FILEFINDBUF3 *Ppfstat3)//~v6k7I~
{
#ifdef DOS
#else
    #ifdef W32                                                     //~v022M~
        #if (_MSC_VER >= 800)                                      //~v034I~
            HDIR   hdir;                                           //~v034I~
            WIN32_FIND_DATA w32fd;                                 //~v034R~
            ULONG attr;                                            //~v034I~
            unsigned int wattrf,wattrp;                            //~v079R~
        #else                                                      //~v034I~
        #endif                                                     //~v034I~
    #else                                                          //~v022M~
    ULONG  cfilename=1;     //file name count
    HDIR   hdir;
    #endif                                                         //~v022R~
#endif
    unsigned rc;
//*********************************

#ifdef DOS
        
  #ifdef DPMI                   //DPMI version                     //~v105I~
    rc=udpmifindnext(Phdir,Ppfstat3);//output file info            //~v105I~
  #else                       //not DPMI                           //~v105I~
    rc=_dos_findnext((struct find_t*)Ppfstat3);
  #endif                      //not DPMI                           //~v105I~
    if (rc)
    {
      #ifdef DPMI                   //DPMI version                 //~v053I~
        if(errno==ENOENT || errno==ENMFILE) //not found or no more file//~v053R~
      #else                       //not DPMI                       //~v053I~
        if (errno==ENOENT)
      #endif                       //not DPMI                      //~v053I~
            return 4;  //no more file
      #ifdef DPMI                   //DPMI version                 //~v105I~
        uerrapi0x("udpmifindnextext",errno);                       //~v105I~
      #else                       //not DPMI                       //~v105I~
//      uerrexit("FindNext failed,rc=%d",                          //~v105R~
//                  "FindNext の失敗,リターンコード=%d",           //~v105R~
//                  errno);                                        //~v105R~
        uerrapi0x("_dos_findnext",errno);                          //~v105I~
      #endif                       //not DPMI                      //~v105I~
    }

#else //os/2
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034M~
#ifdef FTPSUPP                                                     //~v59nI~
//        	if (((ULONG)Phdir & FTP_HDIRMASK)==FTP_HDIRID)	//special hdir for FTP//~v59nR~//~v6hhR~
          	if (((ULONG)(ULPTR)Phdir & FTP_HDIRMASK)==FTP_HDIRID)	//special hdir for FTP//~v6hhI~
//		   		return uftpfindnext((int)Phdir,Ppfstat3);          //~v59nR~//~v6hhR~
		   		return uftpfindnext((int)(ULPTR)Phdir,Ppfstat3);   //~v6hhI~
#endif                                                             //~v59nI~
            if (!(hdir=Phdir))                                     //~v034M~
                hdir=Shdirfirst;                                   //~v034M~
            if (rc=ufilew32srchhdir(hdir,&attr),rc)                //~v034M~
                return rc;                                         //~v034M~
            for (;;)                                               //~v034M~
            {                                                      //~v034M~
                rc=FindNextFile(hdir,&w32fd);                      //~v034M~
                if (rc==FALSE)                                     //~v034M~
                {                                                  //~v034M~
                    rc=GetLastError();                             //~v034M~
                    break;                                         //~v034M~
                }                                                  //~v034M~
                rc=0;                                              //~v034R~//~v034M~
//              if (w32fd.dwFileAttributes &attr)                  //~v079R~
                wattrf=(w32fd.dwFileAttributes & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v079I~
                wattrp=(attr & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v079I~
                if (!wattrf     //select A,R attr file unconditionaly//~v079I~
                ||  (wattrp & wattrf)==wattrf)  //file bit included in parm attr//~v079I~
                {                                                  //~v034M~
//                  ufilew32copyfstat(Ppfstat3,&w32fd);            //~v034M~//~v6k4R~
//                  ufilew32copyfstat(Ppath,Ppfstat3,&w32fd);      //~v6k4R~
                    ufilew32copyfstat(UFCFSO_DIRLIST|UFCFSO_NEXT,Ppath,Ppfstat3,&w32fd);//~v6k4I~//~v6k7R~
                    break;                                         //~v034M~
                }                                                  //~v034M~
                SdirlistOtherAttrCtr++;                            //~v6kmR~
                if ((wattrf & FILE_DIRECTORY)                      //~v783I~
	            &&  !(wattrp & FILE_DIRECTORY))                    //~v783I~
                {                                                  //~v783I~
                    if (!strcmp(Ppfstat3->cFileName,".") || !strcmp(Ppfstat3->cFileName,".."))//~v783I~
	                	SdirlistOtherAttrCtr--;                    //~v783I~
                    else                                           //~v783I~
	                	SdirlistOtherAttrCtr_Dir++;                //~v783I~
                }                                                  //~v783I~
                UTRACEP("%s:member=%s,wattrf=0x%x,wattrp=0x%x,otherAttr=%d,otherAttr_dir=%d\n",UTT,Ppfstat3->cFileName,wattrf,wattrp,SdirlistOtherAttrCtr,SdirlistOtherAttrCtr_Dir);//~v783I~
            }                                                      //~v034M~
        #else                                                      //~v034M~
        Shdirfirst=Phdir;       //for compiler warning             //~v022R~
        rc=findnext((struct ffblk *)(PVOID)Ppfstat3);              //~v022R~
        if (rc)                                                    //~v022I~
            rc=doserrno;                                           //~v022I~
        #endif                                                     //~v034M~
    #else                                                          //~v022I~
    if (!(hdir=Phdir))
        hdir=Shdirfirst;
    rc=DosFindNext(hdir,           //search handle
                   Ppfstat3,       //output file information
                   sizeof(FILEFINDBUF3),//output area size
                   &cfilename);    //request file count
    #endif                                                         //~v022I~
                                                                   //~v022I~
    if (rc==ERROR_NO_MORE_FILES)
    {
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            ufilew32closehdir(hdir);                               //~v034I~
        #else                                                      //~v034I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        rc=DosFindClose(hdir);        //relese  handle
        if (rc)
        {
            uerrexit("FindClose failed,rc=%d",
                        "FindClose の失敗,リターンコード=%d",
                        rc);
        }
    #endif                                                         //~v022I~
        return 4;  //no more file
    }
    else
        if (rc)
            uerrexit("FindNext failed,rc=%d",
                        "FindNext の失敗,リターンコード=%d",
                        rc);
#endif                    
    return 0;
}//udosfindnext
#endif      //!!!!!!!!!!!!!!!!!!                                   //~v327I~
//#ifdef W32                                                       //~v6H9R~
////**********************************************                 //~v6H9R~
//unsigned udosfindnextW(int Popt,char *Ppath,UWCH *PpathW,HDIR Phdir,FILEFINDBUF3 *Ppfstat3)//~v6H9R~
//{                                                                //~v6H9R~
//            HDIR   hdir;                                         //~v6H9R~
//            WIN32_FIND_DATAW w32fd;                              //~v6H9R~
//            ULONG attr;                                          //~v6H9R~
//            unsigned int wattrf,wattrp;                          //~v6H9R~
//    unsigned rc;                                                 //~v6H9R~
////*********************************                              //~v6H9R~
//                                                                 //~v6H9R~
////          if (((ULONG)(ULPTR)Phdir & FTP_HDIRMASK)==FTP_HDIRID)   //special hdir for FTP//~v6H9R~
////              return uftpfindnext((int)(ULPTR)Phdir,Ppfstat3); //~v6H9R~
//            if (!(hdir=Phdir))                                   //~v6H9R~
//                hdir=Shdirfirst;                                 //~v6H9R~
//            if (rc=ufilew32srchhdir(hdir,&attr),rc)              //~v6H9R~
//                return rc;                                       //~v6H9R~
//            for (;;)                                             //~v6H9R~
//            {                                                    //~v6H9R~
////              rc=FindNextFile(hdir,&w32fd);                    //~v6H9R~
//                rc=FindNextFileW(hdir,&w32fd);                   //~v6H9R~
//                if (rc==FALSE)                                   //~v6H9R~
//                {                                                //~v6H9R~
//                    rc=GetLastError();                           //~v6H9R~
//                    break;                                       //~v6H9R~
//                }                                                //~v6H9R~
//                rc=0;                                            //~v6H9R~
//                wattrf=(w32fd.dwFileAttributes & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v6H9R~
//                wattrp=(attr & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));//~v6H9R~
//                if (!wattrf     //select A,R attr file unconditionaly//~v6H9R~
//                ||  (wattrp & wattrf)==wattrf)  //file bit included in parm attr//~v6H9R~
//                {                                                //~v6H9R~
////                  ufilew32copyfstat(UFCFSO_DIRLIST|UFCFSO_NEXT,Ppath,Ppfstat3,&w32fd);//~v6H9R~
//                    ufilew32copyfstatW(UFCFSO_DIRLIST|UFCFSO_NEXT,Ppath,PpathW,Ppfstat3,&w32fd);//~v6H9R~
//                    break;                                       //~v6H9R~
//                }                                                //~v6H9R~
//                SdirlistOtherAttrCtr++;                          //~v6H9R~
//            }                                                    //~v6H9R~
//                                                                 //~v6H9R~
//    if (rc==ERROR_NO_MORE_FILES)                                 //~v6H9R~
//    {                                                            //~v6H9R~
//            ufilew32closehdir(hdir);                             //~v6H9R~
//        return 4;  //no more file                                //~v6H9R~
//    }                                                            //~v6H9R~
//    else                                                         //~v6H9R~
//        if (rc)                                                  //~v6H9R~
//            uerrexit("FindNext failed,rc=%d",                    //~v6H9R~
//                        "FindNext の失敗,リターンコード=%d",     //~v6H9R~
//                        rc);                                     //~v6H9R~
//    return 0;                                                    //~v6H9R~
//}//udosfindnext                                                  //~v6H9R~
//#endif      //!!!!!!!!!!!!!!!!!!                                 //~v6H9R~
                                                                   //~v327I~
//*******************************************************          //~v5d1M~
//*get file fullpath parentdir                                     //~v5d1M~
//*parm 1:input fullpathname                                       //~v5d1M~
//*parm 2:output parentdir                                         //~v5d1M~
//*return:rc 0:not root,1:root,4:err                               //~v5d1M~
//*******************************************************          //~v5d1M~
int ufilegetpathdir(char *Pfullpath,char *Pdirname)                //~v5d1M~
{                                                                  //~v5d1M~
//  char wk[_MAX_PATH];                                            //~v5d1M~//~v6H7R~
    char wk[FTP_MAXPATH];                                          //~v6H7R~
    int pathlen,rc;                                                //~v5d1R~
//*********************************                                //~v5d1M~
    pathlen=PATHLEN(Pfullpath);                                    //~v5d1R~
    if (pathlen<=0)                                                //~v5d1M~
    	return 4;                                                  //~v5d1M~
	memcpy(wk,Pfullpath,(UINT)pathlen);                            //~v5d1M~
    *(wk+pathlen)=0;                                               //~v5d1M~
    if (ROOTDIR3(wk))                                              //~v5d1M~
    	rc=1;                                                      //~v5d1M~
    else                                                           //~v5d1M~
    {                                                              //~v5d1M~
    	pathlen--;                                                 //~v5d1M~
    	*(wk+pathlen)=0;                                           //~v5d1M~
    	rc=0;                                                      //~v5d1M~
    }                                                              //~v5d1M~
	strcpy(Pdirname,wk);                                           //~v5d1M~
    return rc;                                                     //~v5d1M~
}//ufilegetpathdir                                                 //~v5d1M~
//**********************************************************************//~v179R~
// create sorted file list of specified dir(no notfound err msg version)//~v179R~
// parm1  :dir name+wildcard (ex "\*.*", ".\*.c", "subdir\*.*"     //~v179R~
// parm2  :select file attribute                                   //~v179R~
// parm3  :output sorted file list                                 //~v179R~
// parm4  :sort option  'D':date 'E':exrtension+name 'N':name+extention//~v179R~
//         'S':size.for reverse -'D',-'E',-'N',-'S'; other else no sort//~v179R~
//         'L':longname compare(period is compared in that pos)    //~v179R~
// return :file count(-1 if dir not found)                         //~v179R~
//**********************************************************************//~v179R~
int udirlistnomsg(char *Ppdirname,unsigned Pattr,PUDIRLIST *Pppudirlist,//~v179R~
                    int Psorttype)                                 //~v179R~
{                                                                  //~v179R~
    int rc;                                                        //~v179R~
//***********************                                          //~v179R~
    Snomsgdl=1;                                                    //~v179R~
    rc=udirlist(Ppdirname,Pattr,Pppudirlist,Psorttype);            //~v179R~
    Snomsgdl=0;                                                    //~v179R~
    return rc;                                                     //~v179R~
}//udirlistnomsg                                                   //~v179R~

//**********************************************************************
// create sorted file list of specified dir
// parm1  :dir name+wildcard (ex "\*.*", ".\*.c", "subdir\*.*"
// parm2  :select file attribute
// parm3  :output sorted file list
// parm4  :sort option  'D':date 'E':exrtension+name 'N':name+extention
//         'S':size.for reverse -'D',-'E',-'N',-'S'; other else no sort//~v067R~
//         'L':longname compare(period is compared in that pos)    //~v115I~
// return :file count(-1 if dir not found)
//**********************************************************************
int udirlist(char *Ppdirname,unsigned Pattr,PUDIRLIST *Pppudirlist,
                    int Psorttype)
{
#define INITMAX 100     //at first malloc max entry
    int rc;
    int filectr;
    PUDIRLIST pudirlist;
//***********************
#ifdef ARMXXE                                                      //~v777I~
    if (IS_NOOPENDIRDL())       // not use native opendir          //~v77jI~
    if (IS_DOCPATH(Ppdirname))    // name start by "//"            //~v777R~
    {                                                              //~v777I~
    	int opt=0;                                                 //~v777I~
		if (Snomsgdl)                                              //~v777I~
			opt|=UDL_NOMSG;                                        //~v777I~
    	filectr=udirlistDoc(opt,Ppdirname/*//alias:content...*/,Pattr,Pppudirlist,Psorttype);//~v777R~
        return filectr;                                            //~v777I~
    }                                                              //~v777I~
#endif                                                             //~v777I~
    filectr=INITMAX;
//  if (rc=(int)udirlistsub(&filectr,Ppdirname,Pattr,&pudirlist),rc)//~v56pR~
    if (errno=rc=(int)udirlistsub(&filectr,Ppdirname,Pattr,&pudirlist),rc)//~v56pI~
        return -1;
#ifdef FTPSUPP                                                     //~v59nI~
  if (!uftpisremote(Ppdirname,0))//not ftp                         //~v59nI~
#endif                                                             //~v59nI~
    if (filectr>INITMAX)    //over default max entry no
    {
//      ufree(pudirlist);                                          //~v6qaR~
        UDIRLIST_FREE(pudirlist);                                  //~v6qaI~
        if (rc=(int)udirlistsub(&filectr,Ppdirname,Pattr,&pudirlist),rc)//~5930R~
            return -1;                                          //~5930R~
    }
    Ssorttype=toupper(max(Psorttype,-Psorttype));   //parm to udircompare
    switch(Ssorttype)
    {
    case 'E':
    case 'L':           //long name                                //~v115I~
    case 'D':
    case 'N':
    case 'S':       //size                                         //~v067I~
    case 'T':       //time+Name                                    //~v5cyI~
    case 'Z':       //size+Name                                    //~v5cyI~
        if (Psorttype<0)
            Ssorttype=-Ssorttype;
//      qsort(pudirlist,(UINT)filectr,UDIRLISTSZ,udircompare);     //~v6J0R~
      if (filectr>0)                                               //~v77AI~
        udirlistsort(Ssorttype,pudirlist,filectr);                 //~v6J0R~
    }
    UTRACED("dirlistsort",pudirlist,filectr*(int)sizeof(UDIRLIST));//~v6ybR~
    *Pppudirlist=pudirlist;
    return filectr;
}//udirlist

//#ifdef W32                                                       //~v6H9R~
////**********************************************************************//~v6H9R~
//int udirlistW(int Popt,char *Ppdirname,UWCH *PpdirnameW/*out fpathW*/,unsigned Pattr,PUDIRLIST *Pppudirlist,//~v6H9R~
//                    int Psorttype)                               //~v6H9R~
//{                                                                //~v6H9R~
////#define INITMAX 100     //at first malloc max entry            //~v6H9R~
//    int rc;                                                      //~v6H9R~
//    int filectr;                                                 //~v6H9R~
//    PUDIRLIST pudirlist;                                         //~v6H9R~
////***********************                                        //~v6H9R~
//    filectr=INITMAX;                                             //~v6H9R~
////  if (errno=rc=(int)udirlistsub(&filectr,Ppdirname,Pattr,&pudirlist),rc)//~v6H9R~
//    if (errno=rc=(int)udirlistsubW(Popt,&filectr,Ppdirname,PpdirnameW,Pattr,&pudirlist),rc)//~v6H9R~
//        return -1;                                               //~v6H9R~
////if (!uftpisremote(Ppdirname,0))//not ftp                       //~v6H9R~
//    if (filectr>INITMAX)    //over default max entry no          //~v6H9R~
//    {                                                            //~v6H9R~
//        UDIRLIST_FREE(pudirlist);                                //~v6H9R~
//        if (rc=(int)udirlistsub(&filectr,Ppdirname,Pattr,&pudirlist),rc)//~v6H9R~
//            return -1;                                           //~v6H9R~
//    }                                                            //~v6H9R~
//    Ssorttype=toupper(max(Psorttype,-Psorttype));   //parm to udircompare//~v6H9R~
//    switch(Ssorttype)                                            //~v6H9R~
//    {                                                            //~v6H9R~
//    case 'E':                                                    //~v6H9R~
//    case 'L':           //long name                              //~v6H9R~
//    case 'D':                                                    //~v6H9R~
//    case 'N':                                                    //~v6H9R~
//    case 'S':       //size                                       //~v6H9R~
//    case 'T':       //time+Name                                  //~v6H9R~
//    case 'Z':       //size+Name                                  //~v6H9R~
//        if (Psorttype<0)                                         //~v6H9R~
//            Ssorttype=-Ssorttype;                                //~v6H9R~
//        qsort(pudirlist,(UINT)filectr,UDIRLISTSZ,udircompare);   //~v6H9R~
//    }                                                            //~v6H9R~
//    UTRACED("dirlistsort",pudirlist,filectr*(int)sizeof(UDIRLIST));//~v6H9R~
//    *Pppudirlist=pudirlist;                                      //~v6H9R~
//    return filectr;                                              //~v6H9R~
//}//udirlist                                                      //~v6H9R~
//#endif //W32                                                     //~v6H9R~
                                                                   //~v6H9I~
//**********************************************************************
// create sorted file list of specified dir
// rc: rc of ufindfirst                                            //~v56pI~
//**********************************************************************
unsigned udirlistsub(int *Pmax,
                char *Ppdirname,unsigned Pattr,PUDIRLIST *Pppudirlist)
{
    FILEFINDBUF3 fstat3;
    PUDIRLIST pudirlist;
    int filectr;
    UINT uirc;                                                  //~5930R~
    HDIR hdir;
#ifdef FTPSUPP                                                     //~v59nM~
	int ftpopt;                                                    //~v59nM~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v59nM~
//#define MAXUDIRLISTALLOCSZ      (UDIRLISTSZ*110)                 //~v6qbR~
#ifdef W32UNICODE                                                  //~v6uaI~
    int szw;                                                       //~v6uaI~
#endif                                                             //~v6uaI~
#ifdef W32                                                         //~v6H9I~
    char fpath[_MAX_PATH_LONG];                                    //~v6H9I~
#endif                                                             //~v6H9I~
//***********************
//  if (!(pudirlist=UALLOCC(1,len=(UINT)(UDIRLISTSZ * *Pmax)))) //~5930I~
//      uerrexit("udirlist:dir list malloc(fileno=%d,size=%d) failed",//~5930R~
//                  "udirlist:記憶域不足(ファイル数=%d,サイズ=%d)",//~5930R~
//                  *Pmax,len);                                 //~5930R~
    if (udirlist_chk_max_entry(*Pmax))                             //~v6qbI~
        return 4;                                                  //~v6qbI~
#ifdef FTPSUPP                                                     //~v59nI~
  	if (uftpisremote(Ppdirname,&puftph))//not ftp                  //~v5afR~
    {                                                              //~v59nI~
    	ftpopt=(Snomsgdl!=0)*FTP_DLSNONFMSG;                       //~v59nR~
//		return uftpdirlistsub(puftph,ftpopt,Pmax,Ppdirname,Pattr,Pppudirlist);//~v6ybR~
  		return (unsigned)uftpdirlistsub(puftph,ftpopt,Pmax,Ppdirname,(ULONG)Pattr,Pppudirlist);//~v6ybR~
    }                                                              //~v59nI~
#endif                                                             //~v59nI~
#ifdef W32                                                         //~v6H9I~
    if (!ufullpath(fpath,Ppdirname,sizeof(fpath)))                 //~v6H9R~
    	return 4;                                                  //~v6H9I~
    Ppdirname=fpath;                                               //~v6H9R~
#endif                                                             //~v6H9I~
//    UMAXPATHCHK(Ppdirname,_MAX_PATH,ENAMETOOLONG/*rc*/,1/*errmsgsw*/);  //return if too long name//~v6H1I~//~v6H9R~
//  pudirlist=UALLOCC(1,(UINT)(UDIRLISTSZ * *Pmax));               //~v5ceR~
//  pudirlist=UALLOCC(1,(UINT)(UDIRLISTSZ * (*Pmax+1)));           //~v6ybR~
    pudirlist=UALLOCC(1,(UINT)(UDIRLISTSZ * (UINT)(*Pmax+1)));     //~v6ybR~
    UALLOCCHK(pudirlist,(unsigned)UALLOC_FAILED);               //~5930R~
    *Pppudirlist=pudirlist; //return addr

//  if (uirc=udosfindfirst(Ppdirname,&hdir,Pattr,&fstat3),uirc)    //~v179R~
    if (Snomsgdl)                                                  //~v179R~
        uirc=udosfindfirstnomsg(Ppdirname,&hdir,Pattr,&fstat3);    //~v179R~
    else                                                           //~v179R~
        uirc=udosfindfirst(Ppdirname,&hdir,Pattr,&fstat3);         //~v179R~
    UTRACEP("%s:udosfindfirst returned uirc=%d\n",UTT,uirc);       //~v77AI~
#ifdef ARMXXE                                                      //~v77AI~
  if (uirc!=ERROR_NO_MORE_FILES)    //accept filectr=0             //~v77AR~
#endif                                                             //~v77AI~
    if (uirc)                                                      //~v179R~
    {                                                           //~5618I~
//      ufree(pudirlist);                                       //~5618I~//~v6qaR~
        UDIRLIST_FREE(pudirlist);                                  //~v6qaI~
        return uirc;
    }                                                           //~5618I~
#ifdef ARMXXE                                                      //~v77AI~
  if (uirc==ERROR_NO_MORE_FILES)    //accept filectr=0             //~v77AR~
  	filectr=0;                                                     //~v77AI~
  else                                                             //~v77AI~
#endif                                                             //~v77AI~
    for (filectr=0;!uirc;filectr++)
    {
        if (filectr<*Pmax)
        {
//#ifdef W32                                                       //~v105R~
#if defined(W32) || defined(DPMI)                                  //~v105I~
            strncpy(pudirlist->alias,fstat3.achName,sizeof(pudirlist->alias));//~v101R~
//          strncpy(pudirlist->name,fstat3.cFileName,sizeof(pudirlist->name));//~v101R~//~v6J0R~
            udirlist_setname(0,pudirlist,fstat3.cFileName,sizeof(fstat3.cFileName));//~v6J0R~
            UTRACEP("%s:alias=%s,name=%s\n",UTT,pudirlist->alias,pudirlist->name);//~v6B9I~
#else                                                              //~v101I~
//          strcpy(pudirlist->name,fstat3.achName);                //~v6J0R~
            udirlist_setname(0,pudirlist,fstat3.achName,sizeof(fstat3.achName));//~v6J0I~
#endif                                                             //~v101I~
//          strupr(pudirlist->name);                            //~5817R~
                                                                   //~v372I~
#ifdef UNX                                                         //~v372I~
//          strcpy(pudirlist->slink,fstat3.slink);                 //~v50EI~//~v6qaR~
            UDIRLIST_SET_SLINKNAME(pudirlist,fstat3.slink);        //~v6qaR~
            pudirlist->srcattr=fstat3.srcattr; //slink source file attr//~v55nI~
            pudirlist->attr=fstat3.attrFile;                       //~v372I~
            pudirlist->fsid=fstat3.fsid;                           //~v372I~
            pudirlist->inode=fstat3.inode;                         //~v6b1I~
            pudirlist->uid =fstat3.uid;                            //~v372I~
            pudirlist->gid =fstat3.gid;                            //~v372I~
            pudirlist->atime=fstat3.atime;                         //~v545R~
            pudirlist->mtime=fstat3.mtime;                         //~v545R~
            pudirlist->ctime=fstat3.ctime;                         //~v545R~
            pudirlist->slinkmtime=fstat3.slinkmtime;               //~v5a5I~
            pudirlist->slinkftime=fstat3.slinkftime;               //~v5a5I~
            pudirlist->slinkfdate=fstat3.slinkfdate;               //~v5a5I~
            pudirlist->slinksize =fstat3.slinksize ;               //~v5a5I~
            pudirlist->slinkuid  =fstat3.slinkuid;                 //~v5a6I~
            pudirlist->slinkgid  =fstat3.slinkgid;                 //~v5a6I~
            memcpy(pudirlist->slinkuname,fstat3.slinkuname,sizeof(pudirlist->slinkuname));//~v5a6I~
            memcpy(pudirlist->slinkgname,fstat3.slinkgname,sizeof(pudirlist->slinkgname));//~v5a6I~
#else  //!UNX                                                      //~v372I~
//          pudirlist->attr=(char)fstat3.attrFile;                 //~v59eR~
            pudirlist->attr=(ULONG)fstat3.attrFile;                //~v59eI~
	#ifdef W32                                                     //~v547I~
    	pudirlist->ftCreationTime  =fstat3.ftCreationTime;         //~v547R~
    	pudirlist->ftLastAccessTime=fstat3.ftLastAccessTime;       //~v547I~
    	pudirlist->ftLastWriteTime =fstat3.ftLastWriteTime;        //~v547I~
        //*for slink or junction                                   //~v6k4I~
//      strcpy(pudirlist->slink,fstat3.slink);                     //~v6k4I~//~v6qaR~
        UDIRLIST_SET_SLINKNAME(pudirlist,fstat3.slink);            //~v6qaI~
        pudirlist->srcattr=fstat3.srcattr; //slink source file attr//~v6k4I~
        pudirlist->slinkftime=fstat3.slinkftime;                   //~v6k4I~
        pudirlist->slinkfdate=fstat3.slinkfdate;                   //~v6k4I~
        pudirlist->slinksize =fstat3.slinksize ;                   //~v6k4I~
    #endif                                                         //~v547I~
    #ifdef OS2                                                     //~v547I~
    	pudirlist->ctime =fstat3.ftimeCreation;                    //~v547I~
    	pudirlist->cdate =fstat3.fdateCreation;                    //~v547I~
    	pudirlist->atime =fstat3.ftimeLastAccess;                  //~v547I~
    	pudirlist->adate =fstat3.fdateLastAccess;                  //~v547I~
    #endif                                                         //~v547I~
#endif //!UNX                                                      //~v372I~
                                                                   //~v372I~
            pudirlist->time=fstat3.ftimeLastWrite;
            pudirlist->date=fstat3.fdateLastWrite;
            pudirlist->size=fstat3.cbFile;
#ifdef W32UNICODE                                                  //~v6uaI~
            pudirlist->ffb3otherflag=fstat3.otherflag;             //~v6uaI~
            pudirlist->nameWctr=fstat3.cFileNameWctr;              //~v6uaI~
            pudirlist->aliasWctr=fstat3.achNameWctr;               //~v6uaI~
//          memcpyWctr(pudirlist->nameW,fstat3.cFileNameW,pudirlist->nameWctr);//~v6uaR~//~v6J0R~
            udirlist_setnameW(0,pudirlist,fstat3.cFileNameW,pudirlist->nameWctr);//~v6J0I~
            memcpyWctr(pudirlist->aliasW,fstat3.achNameW,pudirlist->aliasWctr);//~v6uaI~
          if (fstat3.slinkWctr)                                    //~v6uDR~
          {                                                        //~v6uDI~
            szw=ctr2szW(fstat3.slinkWctr+1);                       //~v6uaI~
            pudirlist->pslinkW=umalloc(szw);                       //~v6uaI~
		    UALLOCCHK(pudirlist->pslinkW,(unsigned)UALLOC_FAILED); //~v6uaI~
            memcpy(pudirlist->pslinkW,fstat3.slinkW,szw);          //~v6uaI~
//          UTRACEP("%s:alloc dirname=%s,pudl=%p,slink name=%s,slinkW=%p,sz=%d\n",UTT,Ppdirname,pudirlist,pudirlist->name,pudirlist->pslinkW,szw);//~v6ukR~//~v6uDR~
          }                                                        //~v6uDI~
          else                                                     //~v6uDI~
            pudirlist->pslinkW=NULL;                               //~v6uDI~
            pudirlist->pslinkWctr=fstat3.slinkWctr;                //~v6uaI~
#endif //W32UNICODE                                                //~v6uaI~
            pudirlist++;
        }
        else                                                       //~v50FI~
        	if (Sovfbreaksw)	//break when full                  //~v50FI~
            	break;                                             //~v50FI~
//      uirc=udosfindnext(hdir,&fstat3);                           //~v6k4R~
        uirc=udosfindnext(Ppdirname,hdir,&fstat3);                 //~v6k4I~
    }//all file
    UTRACEP("%s:filectr=%d,dirname=%s\n",UTT,filectr,Ppdirname);   //~v77jI~
    *Pmax=filectr;
    return 0;
}//udirlistsub
////**********************************************************************//~v6H9R~
//// create sorted file list of specified dir                      //~v6H9R~
//// rc: rc of ufindfirst                                          //~v6H9R~
////**********************************************************************//~v6H9R~
//unsigned udirlistsubW(int Popt,int *Pmax,char *Ppdirname,UWCH *PpdirnameW,unsigned Pattr,PUDIRLIST *Pppudirlist)//~v6H9R~
//{                                                                //~v6H9R~
//    FILEFINDBUF3 fstat3;                                         //~v6H9R~
//    PUDIRLIST pudirlist;                                         //~v6H9R~
//    int filectr;                                                 //~v6H9R~
//    UINT uirc;                                                   //~v6H9R~
//    HDIR hdir;                                                   //~v6H9R~
////  int ftpopt;                                                  //~v6H9R~
////  PUFTPHOST puftph;                                            //~v6H9R~
//    int szw;                                                     //~v6H9R~
//    int opt;                                                     //~v6H9R~
////***********************                                        //~v6H9R~
//    if (udirlist_chk_max_entry(*Pmax))                           //~v6H9R~
//        return 4;                                                //~v6H9R~
////  if (uftpisremote(Ppdirname,&puftph))//not ftp                //~v6H9R~
////  {                                                            //~v6H9R~
////      ftpopt=(Snomsgdl!=0)*FTP_DLSNONFMSG;                     //~v6H9R~
////      return (unsigned)uftpdirlistsub(puftph,ftpopt,Pmax,Ppdirname,(ULONG)Pattr,Pppudirlist);//~v6H9R~
////  }                                                            //~v6H9R~
////  UMAXPATHCHK(Ppdirname,_MAX_PATH,ENAMETOOLONG/*rc*/,1/*errmsgsw*/);  //return if too long name//~v6H9R~
//    pudirlist=UALLOCC(1,(UINT)(UDIRLISTSZ * (UINT)(*Pmax+1)));   //~v6H9R~
//    UALLOCCHK(pudirlist,(unsigned)UALLOC_FAILED);                //~v6H9R~
//    *Pppudirlist=pudirlist; //return addr                        //~v6H9R~
//                                                                 //~v6H9R~
////  if (Snomsgdl)                                                //~v6H9R~
////      uirc=udosfindfirstnomsg(Ppdirname,&hdir,Pattr,&fstat3);  //~v6H9R~
////  else                                                         //~v6H9R~
////      uirc=udosfindfirst(Ppdirname,&hdir,Pattr,&fstat3);       //~v6H9R~
//    opt=UDFFWO_NOMSG*((Popt & UDLWO_NOMSG)!=0);                  //~v6H9R~
//    uirc=udosfindfirstW(opt,Ppdirname,PpdirnameW,&hdir,Pattr,&fstat3);//~v6H9R~
//    if (uirc)                                                    //~v6H9R~
//    {                                                            //~v6H9R~
//        UDIRLIST_FREE(pudirlist);                                //~v6H9R~
//        return uirc;                                             //~v6H9R~
//    }                                                            //~v6H9R~
//    for (filectr=0;!uirc;filectr++)                              //~v6H9R~
//    {                                                            //~v6H9R~
//        if (filectr<*Pmax)                                       //~v6H9R~
//        {                                                        //~v6H9R~
////#if defined(W32) || defined(DPMI)                              //~v6H9R~
//            strncpy(pudirlist->alias,fstat3.achName,sizeof(pudirlist->alias));//~v6H9R~
//            strncpy(pudirlist->name,fstat3.cFileName,sizeof(pudirlist->name));//~v6H9R~
//            UTRACEP("%s:alias=%s,name=%s\n",UTT,pudirlist->alias,pudirlist->name);//~v6H9R~
////#else                                                          //~v6H9R~
////            strcpy(pudirlist->name,fstat3.achName);            //~v6H9R~
////#endif                                                         //~v6H9R~
//                                                                 //~v6H9R~
////#ifdef UNX                                                     //~v6H9R~
////            UDIRLIST_SET_SLINKNAME(pudirlist,fstat3.slink);    //~v6H9R~
////            pudirlist->srcattr=fstat3.srcattr; //slink source file attr//~v6H9R~
////            pudirlist->attr=fstat3.attrFile;                   //~v6H9R~
////            pudirlist->fsid=fstat3.fsid;                       //~v6H9R~
////            pudirlist->inode=fstat3.inode;                     //~v6H9R~
////            pudirlist->uid =fstat3.uid;                        //~v6H9R~
////            pudirlist->gid =fstat3.gid;                        //~v6H9R~
////            pudirlist->atime=fstat3.atime;                     //~v6H9R~
////            pudirlist->mtime=fstat3.mtime;                     //~v6H9R~
////            pudirlist->ctime=fstat3.ctime;                     //~v6H9R~
////            pudirlist->slinkmtime=fstat3.slinkmtime;           //~v6H9R~
////            pudirlist->slinkftime=fstat3.slinkftime;           //~v6H9R~
////            pudirlist->slinkfdate=fstat3.slinkfdate;           //~v6H9R~
////            pudirlist->slinksize =fstat3.slinksize ;           //~v6H9R~
////            pudirlist->slinkuid  =fstat3.slinkuid;             //~v6H9R~
////            pudirlist->slinkgid  =fstat3.slinkgid;             //~v6H9R~
////            memcpy(pudirlist->slinkuname,fstat3.slinkuname,sizeof(pudirlist->slinkuname));//~v6H9R~
////            memcpy(pudirlist->slinkgname,fstat3.slinkgname,sizeof(pudirlist->slinkgname));//~v6H9R~
////#else  //!UNX                                                  //~v6H9R~
//            pudirlist->attr=(ULONG)fstat3.attrFile;              //~v6H9R~
////    #ifdef W32                                                 //~v6H9R~
//        pudirlist->ftCreationTime  =fstat3.ftCreationTime;       //~v6H9R~
//        pudirlist->ftLastAccessTime=fstat3.ftLastAccessTime;     //~v6H9R~
//        pudirlist->ftLastWriteTime =fstat3.ftLastWriteTime;      //~v6H9R~
//        //*for slink or junction                                 //~v6H9R~
//        UDIRLIST_SET_SLINKNAME(pudirlist,fstat3.slink);          //~v6H9R~
//        pudirlist->srcattr=fstat3.srcattr; //slink source file attr//~v6H9R~
//        pudirlist->slinkftime=fstat3.slinkftime;                 //~v6H9R~
//        pudirlist->slinkfdate=fstat3.slinkfdate;                 //~v6H9R~
//        pudirlist->slinksize =fstat3.slinksize ;                 //~v6H9R~
////    #endif                                                     //~v6H9R~
////    #ifdef OS2                                                 //~v6H9R~
////        pudirlist->ctime =fstat3.ftimeCreation;                //~v6H9R~
////        pudirlist->cdate =fstat3.fdateCreation;                //~v6H9R~
////        pudirlist->atime =fstat3.ftimeLastAccess;              //~v6H9R~
////        pudirlist->adate =fstat3.fdateLastAccess;              //~v6H9R~
////    #endif                                                     //~v6H9R~
////#endif //!UNX                                                  //~v6H9R~
//                                                                 //~v6H9R~
//            pudirlist->time=fstat3.ftimeLastWrite;               //~v6H9R~
//            pudirlist->date=fstat3.fdateLastWrite;               //~v6H9R~
//            pudirlist->size=fstat3.cbFile;                       //~v6H9R~
//            pudirlist->ffb3otherflag=fstat3.otherflag;           //~v6H9R~
//            pudirlist->nameWctr=fstat3.cFileNameWctr;            //~v6H9R~
//            pudirlist->aliasWctr=fstat3.achNameWctr;             //~v6H9R~
//            memcpyWctr(pudirlist->nameW,fstat3.cFileNameW,pudirlist->nameWctr);//~v6H9R~
//            memcpyWctr(pudirlist->aliasW,fstat3.achNameW,pudirlist->aliasWctr);//~v6H9R~
//          if (fstat3.slinkWctr)                                  //~v6H9R~
//          {                                                      //~v6H9R~
//            szw=ctr2szW(fstat3.slinkWctr+1);                     //~v6H9R~
//            pudirlist->pslinkW=umalloc(szw);                     //~v6H9R~
//            UALLOCCHK(pudirlist->pslinkW,(unsigned)UALLOC_FAILED);//~v6H9R~
//            memcpy(pudirlist->pslinkW,fstat3.slinkW,szw);        //~v6H9R~
//          }                                                      //~v6H9R~
//          else                                                   //~v6H9R~
//            pudirlist->pslinkW=NULL;                             //~v6H9R~
//            pudirlist->pslinkWctr=fstat3.slinkWctr;              //~v6H9R~
//            pudirlist++;                                         //~v6H9R~
//        }                                                        //~v6H9R~
//        else                                                     //~v6H9R~
//            if (Sovfbreaksw)    //break when full                //~v6H9R~
//                break;                                           //~v6H9R~
////      uirc=udosfindnext(Ppdirname,hdir,&fstat3);               //~v6H9R~
//        uirc=udosfindnextW(opt,Ppdirname,PpdirnameW,hdir,&fstat3);//~v6H9R~
//    }//all file                                                  //~v6H9R~
//    *Pmax=filectr;                                               //~v6H9R~
//    return 0;                                                    //~v6H9R~
//}//udirlistsubW                                                  //~v6H9R~
//**********************************************************************//~v6qaI~
// setup pslink of udirlist                                        //~v6qaI~
// if no slinkname,point dummy area to avoid many malloc           //~v6qaI~
//**********************************************************************//~v6qaI~
void udirlist_set_slinkname(PUDIRLIST Ppudl,char *Pslinkname)      //~v6qaI~
{                                                                  //~v6qaI~
	char *pslink;                                                  //~v6qaI~
    int len;                                                       //~v6qaI~
//****************                                                 //~v6qaI~
    if (Ppudl->otherflag & UDLOF_SLINK_ALLOC)                      //~v6qaI~
        ufree(Ppudl->pslink);                                      //~v6qaR~
	if (Pslinkname && *Pslinkname)                                 //~v6qaR~
    {                                                              //~v6qaI~
      if (Ppudl->otherflag & UDLOF_WKENTRY)  //udirlist is work variable//~v6qbI~
      	UstrncpyZ(Ppudl->pslink,Pslinkname,MAXSLINKNMSZ);          //~v6qbR~
      else                                                         //~v6qbI~
      {                                                            //~v6qbI~
//  	len=strlen(Pslinkname);                                    //~v6ybR~
    	len=(int)strlen(Pslinkname);                               //~v6ybI~
//  	pslink=umalloc(len+1);                                     //~v6ybR~
    	pslink=umalloc((size_t)len+1);                             //~v6ybI~
//      UmemcpyZ(pslink,Pslinkname,len);                           //~v6ybR~
        UmemcpyZ(pslink,Pslinkname,(size_t)len);                   //~v6ybI~
        Ppudl->otherflag|=UDLOF_SLINK_ALLOC;                       //~v6qaI~
    	Ppudl->pslink=pslink;                                          //~v6qaI~//~v6qbI~
      }                                                            //~v6qbI~
    }                                                              //~v6qaI~
    else                                                           //~v6qaI~
    {                                                              //~v6qaI~
    	pslink=Ppudl->slinkdummy;                                  //~v6qaI~
        *pslink=0;                                                 //~v6qaI~
        Ppudl->otherflag&=~UDLOF_SLINK_ALLOC;                      //~v6qaI~
    	Ppudl->pslink=pslink;                                      //~v6qbI~
    }                                                              //~v6qaI~
    UTRACEP("%s:pudl=%p,pslink=%s\n",UTT,Ppudl,Ppudl->pslink);     //~v6J0I~
}//udirlist_set_slinkname                                          //~v6qaI~
//**********************************************************************//~v6qaI~
// copy udirlist entry                                             //~v6qaI~
// if slink is dummy,point to itself                               //~v6qaI~
//**********************************************************************//~v6qaI~
void ufile_udirlist_copy(int Popt,PUDIRLIST Ppudlto,PUDIRLIST Ppudlfrom)//~v6qaI~
{                                                                  //~v6qaI~
    int len;                                                       //~v6qbI~
    int namesz;                                                    //~v6J0I~
    char *name;                                                    //~v6J0I~
    int otherflag;                                                 //~v6J0I~
    int allocflags=UDLOF_ALLOC_FLAGS;                              //~v6J0R~
    char *pslink;                                                  //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    int nameWsz;                                                   //~v6J0I~
    UWCH *nameW;                                                   //~v6J0R~
    UWCH *pslinkW;                                                 //~v6J0I~
#endif                                                             //~v6J0I~
//****************                                                 //~v6qaI~
    UTRACEP("%s:old From:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudlfrom->otherflag,Ppudlfrom->namesz,Ppudlfrom->name,Ppudlfrom->nameShortbuff);//~v6J0I~
    UTRACEP("%s:pslink=%s\n",UTT,Ppudlfrom->pslink);               //~v6J0I~
    UTRACEP("%s:old To:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudlto->otherflag,Ppudlto->namesz,Ppudlto->name,Ppudlto->nameShortbuff);//~v6J0I~
    UTRACEP("%s:pslink=%s\n",UTT,Ppudlfrom->pslink);               //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    UTRACED("old From:nameW",Ppudlfrom->nameW,strszW(Ppudlfrom->nameW));//~v6J0I~
    UTRACED("nameWshort",Ppudlfrom->nameWShortbuff,strszW(Ppudlfrom->nameWShortbuff));//~v6J0I~
    UTRACED("pslinkW",Ppudlfrom->pslinkW,strszW(Ppudlfrom->nameWShortbuff));//~v6J0I~
    UTRACED("old To:nameW",Ppudlto->nameW,strszW(Ppudlto->nameW)); //~v6J0I~
    UTRACED("nameWshort",Ppudlto->nameWShortbuff,strszW(Ppudlto->nameWShortbuff));//~v6J0I~
    UTRACED("pslinkW",Ppudlto->pslinkW,strszW(Ppudlto->nameWShortbuff));//~v6J0I~
#endif                                                             //~v6J0I~
	otherflag=Ppudlto->otherflag;                                  //~v6J0R~
    namesz=Ppudlto->namesz;                                        //~v6J0R~
    name=Ppudlto->name;                                            //~v6J0R~
    pslink=Ppudlto->pslink;                                        //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    nameWsz=Ppudlto->nameWsz;                                      //~v6J0R~
    nameW=Ppudlto->nameW;                                          //~v6J0R~
    pslinkW=Ppudlto->pslinkW;                                      //~v6J0I~
#endif                                                             //~v6J0I~
	*Ppudlto=*Ppudlfrom;                                           //~v6qaI~
                                                                   //~v6J0I~
	Ppudlto->otherflag &= ~allocflags;                             //~v6J0I~
	Ppudlto->otherflag |= (otherflag & allocflags);	//recover name alloc and dirwk flag//~v6J0M~
    Ppudlto->pslink=pslink;                                        //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    Ppudlto->pslinkW=pslinkW;                                      //~v6J0I~
#endif                                                             //~v6J0I~
#ifdef AAA                                                         //~v6J0I~
    if (!(Ppudlto->otherflag & UDLOF_SLINK_ALLOC))                 //~v6qaI~
    {                                                              //~v6uCI~
    	Ppudlto->pslink=Ppudlto->slinkdummy;                       //~v6qaI~
#ifdef W32UNICODE                                                  //~v6uCI~
	    Ppudlfrom->pslinkW=NULL;                                   //~v6uCI~
#endif                                                             //~v6uCI~
    }                                                              //~v6uCI~
    else                                                           //~v6qbI~
    if (Popt & UFDLCO_NEWSLINKNAME)	//copy to new allocate         //~v6qbI~
    {                                                              //~v6qbI~
//  	len=strlen(Ppudlto->pslink);                               //~v6ybR~
    	len=(int)strlen(Ppudlto->pslink);                          //~v6ybI~
//      Ppudlto->pslink=umalloc(len+1);                            //~v6ybR~
        Ppudlto->pslink=umalloc((size_t)len+1);                    //~v6ybI~
        strcpy(Ppudlto->pslink,Ppudlfrom->pslink);                 //~v6qbI~
#ifdef W32UNICODE                                                  //~v6u0I~//~v6uaI~
        if (Ppudlto->pslinkW)                                      //~v6u0I~//~v6uaI~
        {                                                          //~v6u0I~//~v6uaI~
	        len=strszW(Ppudlto->pslinkW)+UWCHSZ;                   //~v6u0R~//~v6uaI~
	        Ppudlto->pslinkW=umalloc(len);                         //~v6u0I~//~v6uaI~
        	memcpy(Ppudlto->pslink,Ppudlfrom->pslink,len);         //~v6u0I~//~v6uaI~
        }                                                          //~v6u0I~//~v6uaI~
#endif                                                             //~v6u0I~//~v6uaI~
    }                                                              //~v6qbI~
    else                                                           //~v6qbI~
    {                                                              //~v6qbI~
    	Ppudlfrom->pslink=Ppudlfrom->slinkdummy;                   //~v6qbI~
	    Ppudlfrom->otherflag&=~UDLOF_SLINK_ALLOC;	//copyed dont free//~v6qbI~
#ifdef W32UNICODE                                                  //~v6uaI~
	    Ppudlfrom->pslinkW=NULL;                                   //~v6u0I~//~v6uaI~
#endif                                                             //~v6u0I~//~v6uaI~
    }                                                              //~v6qbI~
#else	//AAA                                                      //~v6J0I~
//************                                                     //~v6J0I~
    if (otherflag & UDLOF_WKENTRY)	//target is work               //~v6J0I~
    {                                                              //~v6J0I~
        if (Ppudlfrom->pslink)                                     //~v6J0I~
	    	UstrcpyZ(pslink,Ppudlfrom->pslink,MAXSLINKNMSZ);       //~v6J0R~
#ifdef W32UNICODE                                                  //~v6J0I~
        if (Ppudlfrom->pslinkW)                                    //~v6J0R~
        	UstrcpyZWctr(pslinkW,Ppudlfrom->pslinkW,MAXSLINKNMSZWC);//~v6J0R~
#endif                                                             //~v6J0I~
    }                                                              //~v6J0I~
    else    //tgt not wk                                           //~v6J0I~
    {                                                              //~v6J0I~
        Ppudlto->pslink=Ppudlto->slinkdummy;                       //~v6J0I~
        Ppudlto->otherflag&=~UDLOF_SLINK_ALLOC;	                   //~v6J0I~
        *(Ppudlto->pslink)=0;                                      //~v6J0I~
#ifdef W32UNICODE                                                  //~v6J0I~
        Ppudlto->pslinkW=0;                                        //~v6J0I~
#endif                                                             //~v6J0I~
        if (otherflag & UDLOF_SLINK_ALLOC)  //target had malloc pslink//~v6J0I~
        {                                                          //~v6J0I~
            if (pslink)                                            //~v6J0R~
                ufree (pslink);                                    //~v6J0I~
#ifdef W32UNICODE                                                  //~v6J0I~
            if (pslinkW)                                           //~v6J0I~
                ufree (pslinkW);                                   //~v6J0I~
#endif                                                             //~v6J0I~
        }                                                          //~v6J0I~
        if (Ppudlfrom->pslink)                                     //~v6J0R~
        {                                                          //~v6J0R~
            len=(int)strlen(Ppudlfrom->pslink);                    //~v6J0R~
            if (len)                                               //~v6J0I~
            {                                                      //~v6J0I~
            	Ppudlto->pslink=umalloc((size_t)len+1);            //~v6J0R~
            	strcpy(Ppudlto->pslink,Ppudlfrom->pslink);         //~v6J0R~
        		Ppudlto->otherflag|=UDLOF_SLINK_ALLOC;             //~v6J0I~
            }                                                      //~v6J0I~
        }                                                          //~v6J0R~
#ifdef W32UNICODE                                                  //~v6J0I~
        if (Ppudlto->pslinkW)                                      //~v6J0R~
        {                                                          //~v6J0R~
            len=strszW(Ppudlto->pslinkW);                          //~v6J0R~
            if (len)                                               //~v6J0I~
            {                                                      //~v6J0I~
	            Ppudlto->pslinkW=umalloc(len+UWCHSZ);              //~v6J0I~
	            strcpyW(Ppudlto->pslink,Ppudlfrom->pslink);        //~v6J0I~
            }                                                      //~v6J0I~
        }                                                          //~v6J0R~
#endif                                                             //~v6J0I~
    }                                                              //~v6J0I~
#endif	//AAA                                                      //~v6J0I~
//copy name and nameW(if short ,change addr of old to short of new //~v6J0I~
	Ppudlto->name=name;               //resore lage wkbuff         //~v6J0I~
	Ppudlto->namesz=namesz;           //resore lage wkbuff size    //~v6J0I~
	udirlist_setname(0,Ppudlto,Ppudlfrom->name,0); //old allocated will be freed//~v6J0I~
#ifdef W32                                                         //~v6J0I~
    UTRACEP("%s:From:szW=%d,nameW=%s,Wshortbuff=%s\n",UTT,Ppudlfrom->nameWsz,Ppudlfrom->nameW,Ppudlfrom->nameWShortbuff);//~v6J0I~
	Ppudlto->nameW=nameW;               //resore lage wkbuff       //~v6J0I~
	Ppudlto->nameWsz=nameWsz;           //resore lage wkbuff size  //~v6J0I~
	udirlist_setnameW(0,Ppudlto,Ppudlfrom->nameW,0); //old allocated will be freed//~v6J0I~
#endif                                                             //~v6J0I~
    UTRACEP("%s:new From:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudlfrom->otherflag,Ppudlfrom->namesz,Ppudlfrom->name,Ppudlfrom->nameShortbuff);//~v6J0I~
    UTRACEP("%s:pslink=%s\n",UTT,Ppudlfrom->pslink);               //~v6J0I~
    UTRACEP("%s:new To:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudlto->otherflag,Ppudlto->namesz,Ppudlto->name,Ppudlto->nameShortbuff);//~v6J0I~
    UTRACEP("%s:pslink=%s\n",UTT,Ppudlto->pslink);                 //~v6J0R~
#ifdef W32                                                         //~v6J0I~
    UTRACED("new From:nameW",Ppudlfrom->nameW,strszW(Ppudlfrom->nameW));//~v6J0I~
    UTRACED("nameWshort",Ppudlfrom->nameWShortbuff,strszW(Ppudlfrom->nameWShortbuff));//~v6J0I~
    UTRACED("pslinkW",Ppudlfrom->pslinkW,strszW(Ppudlfrom->nameWShortbuff));//~v6J0I~
    UTRACED("new To:nameW",Ppudlto->nameW,strszW(Ppudlto->nameW)); //~v6J0I~
    UTRACED("nameWshort",Ppudlto->nameWShortbuff,strszW(Ppudlto->nameWShortbuff));//~v6J0I~
    UTRACED("pslinkW",Ppudlto->pslinkW,strszW(Ppudlto->nameWShortbuff));//~v6J0I~
#endif                                                             //~v6J0I~
}//ufile_udirlist_copy                                             //~v6qaI~
//**********************************************************************//~v6J0I~
// copy udirlist entry                                             //~v6J0I~
// if slink is dummy,point to itself                               //~v6J0I~
//**********************************************************************//~v6J0I~
void ufile_udirlist_swap(int Popt,PUDIRLIST Ppudl1,PUDIRLIST Ppudl2)//~v6J0R~
{                                                                  //~v6J0I~
	PUDIRLIST pudlwk1,pudlwk2;                                     //~v6J0R~
    UDIRLIST_WK(udlwk1,namewk1,namewkW1,slnwk1);                   //~v6J0R~
    UDIRLIST_WK(udlwk2,namewk2,namewkW2,slnwk2);                   //~v6J0I~
//****************                                                 //~v6J0I~
	pudlwk1=&udlwk1;                                               //~v6J0R~
	pudlwk2=&udlwk2;                                               //~v6J0I~
    UDIRLIST_WK_INIT(udlwk1,namewk1,namewkW1,slnwk1);              //~v6J0R~
    UDIRLIST_WK_INIT(udlwk2,namewk2,namewkW2,slnwk2);              //~v6J0I~
    UTRACEP("%s:old pudl1:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudl1->otherflag,Ppudl1->namesz,Ppudl1->name,Ppudl1->nameShortbuff);//~v6J0I~
    UTRACEP("%s:old pudl2:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudl2->otherflag,Ppudl2->namesz,Ppudl2->name,Ppudl2->nameShortbuff);//~v6J0I~
#ifdef W32                                                         //~v6J0I~
    UTRACEP("%s:old pudl1:szW=%d,nameW=%s,Wshortbuff=%s\n",UTT,Ppudl1->nameWsz,Ppudl1->nameW,Ppudl1->nameWShortbuff);//~v6J0I~
    UTRACEP("%s:old pudl2:szW=%d,nameW=%s,Wshortbuff=%s\n",UTT,Ppudl2->nameWsz,Ppudl2->nameW,Ppudl2->nameWShortbuff);//~v6J0I~
#endif                                                             //~v6J0I~
    ufile_udirlist_copy(0,pudlwk1,Ppudl1);                         //~v6J0R~
    ufile_udirlist_copy(0,pudlwk2,Ppudl2);                         //~v6J0I~
    ufile_udirlist_copy(0,Ppudl1,pudlwk2);                         //~v6J0R~
    ufile_udirlist_copy(0,Ppudl2,pudlwk1);                         //~v6J0R~
    UTRACEP("%s:new pudl1:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudl1->otherflag,Ppudl1->namesz,Ppudl1->name,Ppudl1->nameShortbuff);//~v6J0I~
    UTRACEP("%s:new pudl2:flag=%x,sz=%d,name=%s,shortbuff=%s\n",UTT,Ppudl2->otherflag,Ppudl2->namesz,Ppudl2->name,Ppudl2->nameShortbuff);//~v6J0I~
#ifdef W32                                                         //~v6J0I~
    UTRACEP("%s:pudl1:szW=%d,nameW=%s,Wshortbuff=%s\n",UTT,Ppudl1->nameWsz,Ppudl1->nameW,Ppudl1->nameWShortbuff);//~v6J0I~
    UTRACEP("%s:pudl2:szW=%d,nameW=%s,Wshortbuff=%s\n",UTT,Ppudl2->nameWsz,Ppudl2->nameW,Ppudl2->nameWShortbuff);//~v6J0I~
#endif                                                             //~v6J0I~
}//ufile_udirlist_swap                                             //~v6J0R~
//**********************************************************************//~v6qaI~
// allocate 1 entry udirlist(addtinally 1 dummy entry as stopper to free)//~v6qaI~
//**********************************************************************//~v6qaI~
PUDIRLIST ufile_udirlist_alloc1(int Popt)                          //~v6qaI~
{                                                                  //~v6qaI~
	PUDIRLIST pudl;                                                //~v6qaI~
//****************                                                 //~v6qaI~
	pudl=ucalloc(2,UDIRLISTSZ);                                    //~v6qaI~
    if (Popt & UDA1O_ALLOC_SLINKNAME)                              //~v6qaR~
    {                                                              //~v6qaI~
    	pudl->pslink=ucalloc(1,MAXSLINKNMSZ);                      //~v6qaI~
		pudl->otherflag=UDLOF_ALLOC1|UDLOF_SLINK_ALLOC;    //name may be null but slink allocated//~v6qaI~
    }                                                              //~v6qaI~
    else                                                           //~v6qaI~
    	pudl->pslink=pudl->slinkdummy;                             //~v6qaI~
    pudl->name=pudl->nameShortbuff;                                //~v6J0I~
    pudl->namesz=sizeof(pudl->nameShortbuff);                      //~v6J0I~
#ifdef W32                                                         //~v6J0I~
    pudl->nameW=pudl->nameWShortbuff;                              //~v6J0I~
    pudl->namesz=sizeof(pudl->nameWShortbuff);                     //~v6J0I~
#endif                                                             //~v6J0R~
	UTRACEP("%s:pudl=%p,pslink=%s\n",UTT,pudl,pudl->pslink);       //~v6J0R~
    return pudl;                                                   //~v6qaI~
}//ufile_udirlist_alloc1                                           //~v6qaI~
//**********************************************************************//~v6qaI~
// create sorted file list of specified dir                        //~v6qaI~
// rc: rc of ufindfirst                                            //~v6qaI~
//**********************************************************************//~v6qaI~
void ufile_udirlist_free(int Popt,PUDIRLIST Ppudl)                 //~v6qaR~
{                                                                  //~v6qaI~
    PUDIRLIST pudl;                                                //~v6qaI~
//***********************                                          //~v6qaI~
	if (!Ppudl)                                                    //~v6qaI~
    	return;                                                    //~v6qaI~
	if (Popt & 1)   //free entry,if 0 dont free, all entry was copyed//~v6qaI~
        for (pudl=Ppudl;;pudl++)                                   //~v6qaR~
        {                                                          //~v6qaR~
//          if (!*pudl->name)   //additional last entry            //~v6qaR~//~v6J0R~
//  		  if (!(pudl->otherflag & UDLOF_ALLOC1))    //ALLOC1:name may be null but slink allocated//~v6qaI~//~v6J0R~
//              break;                                             //~v6qaR~//~v6J0R~
            if (!pudl->name)   //lastentry                         //~v6J0I~
            	break;                                             //~v6J0I~
		    if (pudl->otherflag & UDLOF_SLINK_ALLOC)               //~v6qaR~
                ufree (pudl->pslink);                              //~v6qaR~
                                                                   //~v6ukI~
		    if (pudl->otherflag & UDLOF_ALLOCNAME)                 //~v6J0I~
            {                                                      //~v6J0M~
	            UFREEIFNZ(pudl->name);                             //~v6J0I~
			    pudl->otherflag &=~UDLOF_ALLOCNAME;                //~v6J0I~
	            pudl->name=pudl->nameShortbuff;                    //~v6J0I~
	            pudl->namesz=0;                                    //~v6J0I~
            }                                                      //~v6J0M~
//          UTRACEP("%s:free pudl=%p,dirname=%s,pudl=%p,slink name=%s,slinkW=%p\n",UTT,pudl,pudl->name,pudl,pudl->name,pudl->pslinkW);//~v6ukR~//~v6uDR~//~v6J0R~
#ifdef W32UNICODE                                                  //~v6u0I~//~v6uaI~
            UFREEIFNZ(pudl->pslinkW);                              //~v6u0R~//~v6uaI~
		    if (pudl->nameW && pudl->otherflag & UDLOF_ALLOCNAMEW) //~v6J0R~
            {                                                      //~v6J0I~
	            UFREEIFNZ(pudl->nameW);                            //~v6J0I~
			    pudl->otherflag &=~UDLOF_ALLOCNAMEW;               //~v6J0R~
	            pudl->nameW=pudl->nameWShortbuff;                  //~v6J0I~
	            pudl->nameWsz=0;                                   //~v6J0I~
            }                                                      //~v6J0I~
#endif                                                             //~v6u0I~//~v6uaI~
        }                                                          //~v6qaR~
	ufree(Ppudl);                                                  //~v6qaI~
}//ufile_udirlist_free                                             //~v6qaI~
//**********************************************************************//~v6J0I~
int udircompare_pointer(const void *ent1,const void *ent2)         //~v6J0I~
{                                                                  //~v6J0I~
	PUDIRLIST pudl1,pudl2;                                         //~v6J0I~
//****************************************                         //~v6J0I~
    pudl1=*(PUDIRLIST*)(ULPTR)ent1;                                //~v6J0I~
    pudl2=*(PUDIRLIST*)(ULPTR)ent2;                                //~v6J0I~
  if (Ssorttype==FTP_SORTTYPE_SLINK)  	                           //~v6J0I~
	return uftpslinkcomp(pudl1,pudl2);  //sort by slinkname        //~v6J0I~
  else                                                             //~v6J0I~
	return udircompare(pudl1,pudl2);                               //~v6J0R~
}//udircompare_pointer                                             //~v6J0R~
//**********************************************************************//~v59vI~
//!udirlistsort                                                    //~v59vI~
// sort dir list                                                   //~v59vI~
// To keep pointer address,                                        //~v6J0I~
//   generate pointer list,sort it,copyback to udirlist            //~v6J0I~
//**********************************************************************//~v59vI~
void udirlistsort(int Psorttype,PUDIRLIST Ppudirlist,int Pentno)   //~v59vI~
{                                                                  //~v59vI~
	PUDIRLIST *ppudl,*ppudl0,pudl,pudlwk0,pudlwk;                  //~v6J0I~
    int ii;                                                        //~v6J0I~
//*********************************************                    //~v6J0I~
    Ssorttype=Psorttype;                                           //~v59vI~
//  qsort(Ppudirlist,(UINT)Pentno,UDIRLISTSZ,udircompare);         //~v59vI~//~v6J0R~
	ppudl0=umalloc(((size_t)Pentno)*sizeof(PUDIRLIST));            //~v6J0I~
	pudlwk0=umalloc((size_t)Pentno*sizeof(UDIRLIST));              //~v6J0I~
    memcpy(pudlwk0,Ppudirlist,(size_t)Pentno*UDIRLISTSZ);	//copy original//~v6J0I~
    for (ii=0,ppudl=ppudl0,pudl=pudlwk0;ii<Pentno;ii++)  //ptrlist to wk//~v6J0I~
    {                                                              //~v6J0I~
   		*ppudl++=pudl++;                                           //~v6J0I~
    }                                                              //~v6J0I~
	qsort(ppudl0,(UINT)Pentno,sizeof(PUDIRLIST),udircompare_pointer);//~v6J0R~
    for (ii=0,ppudl=ppudl0,pudl=Ppudirlist;ii<Pentno;ii++,pudl++)  //~v6J0R~
    {                                                              //~v6J0I~
    	pudlwk=*ppudl++;                                           //~v6J0I~
   		*pudl=*pudlwk;                                             //~v6J0R~
        if (!(pudl->otherflag & UDLOF_SLINK_ALLOC)) //using nameShortbuff//~v6J0I~
        	pudl->pslink=pudl->slinkdummy;                         //~v6J0I~
        if (!(pudl->otherflag & UDLOF_ALLOCNAME)) //using nameShortbuff//~v6J0I~
        	pudl->name=pudl->nameShortbuff;                        //~v6J0I~
#ifdef W32                                                         //~v6J0I~
        if (!(pudl->otherflag & UDLOF_ALLOCNAMEW)) //using nameShortbuff//~v6J0I~
        	pudl->nameW=pudl->nameWShortbuff;                      //~v6J0I~
#endif                                                             //~v6J0I~
        UTRACEP("%s:pudl=%p,otherflag=%x,name=%s,nameShort=%s,pslink=%s\n",UTT,pudl,(unsigned)(pudl->otherflag),pudl->name,pudl->nameShortbuff,pudl->pslink);//~v6J0R~
    }                                                              //~v6J0I~
    ufree(ppudl0);           //free ptr list                       //~v6J0I~
    ufree(pudlwk0);          //free work pudirllist                //~v6J0I~
    return;                                                        //~v59vI~
}//udirlistsort                                                    //~v59vI~
//**********************************************************************//~v113I~
//!udircomp                                                        //~v113I~
//* file name compare for sort                                     //~v113I~
//*parm1:dirlist1                                                  //~v113I~
//*parm2:dirlist2                                                  //~v113I~
//*parm3:sort type  (-)'N'/'E'/'D'/'S'                             //~v113I~
//*  return code: -1: ent1<ent2                                    //~v113I~
//*                0: ent1=ent2                                    //~v113I~
//*                1: ent1>ent2                                    //~v113I~
//**********************************************************************//~v113I~
int udircomp(PUDIRLIST Ppudirlist1,PUDIRLIST Ppudirlist2,int Psorttype)//~v113I~
{                                                                  //~v113I~
                                                                   //~v113I~
//*****************                                                //~v113I~
    Ssorttype=Psorttype;                                           //~v113I~
    return udircompare(Ppudirlist1,Ppudirlist2);                   //~v113I~
}//udircomp                                                        //~v113I~
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int udircompare(const void *ent1,const void *ent2)
{
    int type;
    int rc;
#ifdef LFSSUPP                                                     //~v5k0I~
    FILESZT szdiff;                                                //~v5k0I~
#endif                                                             //~v5k0I~
    int orgsorttype;                                               //~v5cyI~
    PUDIRLIST flist1,flist2;
    char *pc,*pos1,*pos2,*pc1;                                     //~v59nR~
    char *pc2;                                                     //~v231I~
//  char fnwk1[13],fnwk2[13];                                      //~v101R~
//#ifdef W32                                                       //~v105R~
//#if defined(W32) || defined(DPMI)                                //~v59nR~
//    #define FNMCOMPSZ MAXFILENAMEZ_FAT  //by alias name          //~v59nR~
//#else                                                            //~v59nR~
//    #define FNMCOMPSZ MAXFILENAMEZ  //14 for dos                 //~v59nR~
//#endif                                                           //~v59nR~
//    char fnwk1[FNMCOMPSZ*2],fnwk2[FNMCOMPSZ*2];                  //~v59nR~
//*****************
//  flist1=(PUDIRLIST)(ULONG)ent1;                                 //~v59nR~//~v6hhR~
    flist1=(PUDIRLIST)(ULPTR)ent1;                                 //~v6hhI~
//  flist2=(PUDIRLIST)(ULONG)ent2;                                 //~v59nR~//~v6hhR~
    flist2=(PUDIRLIST)(ULPTR)ent2;                                 //~v6hhI~

    if ((type=Ssorttype)<0)
        type=-type;         //plus value

//UTRACEP("dircomp type=%c\n",type);                                 //~v62YI~//~v77AR~
//UTRACED("ent1",flist1,sizeof(UDIRLIST));                           //~v62YR~//~v77AR~
//UTRACED("ent2",flist2,sizeof(UDIRLIST));                           //~v62YR~//~v77AR~
    switch (type)
    {
    case 'L':         //ext and name                               //~v115I~
//      rc=stricmp(flist1->name,flist2->name);                     //~v231R~
        pc =flist1->name;                                          //~v231R~
        pc2=flist2->name;                                          //~v231I~
        if (*pc=='.'|| *pc2=='.')   //curr or pairent              //~v231R~
        {                                                          //~v231I~
            rc=udircompsub(pc,pc2);                                //~v231R~
    UTRACEP("comp.rc=%d,for %s & %s\n",rc,pc,pc2);                 //~v62YM~
            if (rc!=9)                                             //~v231I~
                return rc;                                         //~v231I~
        }                                                          //~v231I~
#ifdef UNX                                                         //~v393I~
      if (flist1->attr & FILE_TSO)//remote file                    //~v5jcI~
      {                                                            //~v62YI~
	    rc=stricmp(pc,pc2);                                        //~v5jcI~
    UTRACEP("icomp rc=%d,for %s & %s\n",rc,pc,pc2);                //~v62YI~
      }                                                            //~v62YI~
      else                                                         //~v5jcI~
      {                                                            //~v62YI~
        rc=strcmp(pc,pc2);                                         //~v393I~
    UTRACEP("comp rc=%d,for %s & %s\n",rc,pc,pc2);                 //~v62YM~
      }                                                            //~v62YI~
#else  //!UNX                                                      //~v393I~
#ifdef FTPSUPP                                                     //~v59nM~
        if (flist1->attr & FILE_REMOTE)//remote file               //~v59nR~
          if (flist1->attr & FILE_TSO)//remote file                //~v5jcI~
	        rc=stricmp(pc,pc2);                                    //~v5jcI~
          else                                                     //~v5jcI~
	        rc=strcmp(pc,pc2);                                     //~v59nI~
        else                                                       //~v59nI~
#endif //FTPSUPP                                                   //~v59nM~
#ifdef W32UNICODE                                                  //~v6uaM~
        rc=ufilew_dircompW('L',flist1,flist2);                     //~v6uaI~
#else                                                              //~v6uaI~
        rc=stricmp(pc,pc2);                                        //~v231R~
#endif                                                             //~v6uaM~
#endif //!UNX                                                      //~v393I~
        break;                                                     //~v115I~
//***************************                                      //~v6uaI~
    case 'E':         //ext and name
//      memset(fnwk1,0,sizeof(fnwk1));                             //~v59nR~
//      if (pos=strpbrk(pc=flist1->name,"."),!pos)                 //~v101R~
//#ifdef W32                                                       //~v105R~
#if defined(W32) || defined(DPMI)                                  //~v105I~
        pc=flist1->alias;                                          //~v101I~
#else                                                              //~v101I~
        pc=flist1->name;                                           //~v101R~
#endif                                                             //~v101I~
		pc1=pc;                                                    //~v59nM~
//      if (pos=strrchr(pc,'.'),!pos)                              //~v59nR~
//          strcpy(fnwk1,pc);                                      //~v067R~
//          strcpy(fnwk1+3,pc);                                    //~v101R~
//          strcpy(fnwk1+FNMCOMPSZ,pc);                            //~v59nR~
//      else                                                       //~v59nR~
//      {                                                          //~v59nR~
//          strcpy(fnwk1,pos+1);                                   //~v59nR~
//          memcpy(fnwk1+3,pc,(UINT)((ULONG)pos-(ULONG)pc));       //~v101R~
//          memcpy(fnwk1+FNMCOMPSZ,pc,(UINT)((ULONG)pos-(ULONG)pc));//~v59nR~
//      }                                                          //~v59nR~
//      memset(fnwk2,0,sizeof(fnwk2));                             //~v59nR~
//      if (pos=strpbrk(pc=flist2->name,"."),!pos)                 //~v101R~
//#ifdef W32                                                       //~v105R~
#if defined(W32) || defined(DPMI)                                  //~v105I~
        pc=flist2->alias;                                          //~v101I~
#else                                                              //~v101I~
        pc=flist2->name;                                           //~v101R~
#endif                                                             //~v101I~
		pc2=pc;                                                    //~v59nM~
//      if (pos=strrchr(pc,'.'),!pos)                              //~v59nR~
//          strcpy(fnwk2,pc);                                      //~v067R~
//          strcpy(fnwk2+3,pc);                                    //~v101R~
//          strcpy(fnwk2+FNMCOMPSZ,pc);                            //~v59nR~
//      else                                                       //~v59nR~
//      {                                                          //~v59nR~
//          strcpy(fnwk2,pos+1);                                   //~v59nR~
//          memcpy(fnwk2+3,pc,(UINT)((ULONG)pos-(ULONG)pc));       //~v101R~
//          memcpy(fnwk2+FNMCOMPSZ,pc,(UINT)((ULONG)pos-(ULONG)pc));//~v59nR~
//      }                                                          //~v59nR~
        if (*pc1=='.'|| *pc2=='.')   //curr or pairent             //~v59nR~
        {                                                          //~v59nI~
            rc=udircompsub(pc1,pc2);                               //~v59nR~
            if (rc!=9)                                             //~v59nI~
                return rc;                                         //~v59nI~
        }                                                          //~v59nI~
        pos1=strrchr(pc1,'.');                                     //~v59nM~
        pos2=strrchr(pc2,'.');                                     //~v59nI~
        if (!pos1 &&  pos2)                                        //~v59nI~
        	return -1;                                             //~v59nI~
        if ( pos1 && !pos2)                                        //~v59nI~
        	return  1;                                             //~v59nI~
        if (pos1 && pos2)                                          //~v59nR~
        {                                                          //~v59nI~
#ifdef UNX                                                         //~v59nR~
	      if (flist1->attr & FILE_TSO)//remote file                //~v5jcI~
	   		rc=stricmp(pos1,pos2);                                 //~v5jcI~
          else                                                     //~v5jcI~
	   		rc=strcmp(pos1,pos2);                                  //~v59nR~
#else                                                              //~v59nR~
	#ifdef FTPSUPP                                                 //~v59nR~
        	if (flist1->attr & FILE_REMOTE)//remote file           //~v59nR~
	          if (flist1->attr & FILE_TSO)//remote file            //~v5jcI~
	   			rc=stricmp(pos1,pos2);                             //~v5jcI~
               else                                                //~v5jcI~
	        	rc=strcmp(pos1,pos2);                              //~v59nR~
        	else                                                   //~v59nR~
	#endif                                                         //~v59nR~
	#ifdef W32UNICODE                                              //~v6uaI~
        		rc=ufilew_dircompW('E',flist1,flist2);	           //~v6uaI~
	#else                                                          //~v6uaI~
	   			rc=stricmp(pos1,pos2);                             //~v59nR~
	#endif                                                         //~v6uaI~
#endif                                                             //~v59pI~
			if (rc)                                                //~v59nR~
        		return rc;	//by ext                               //~v59nR~
        }//both ext exist                                          //~v59nI~
//#ifdef OS2                                                       //~v59nR~
//      rc=memicmp(fnwk1,fnwk2,sizeof(fnwk1));                     //~v59nR~
//#else                                                            //~v59nR~
//      rc=memcmp(fnwk1,fnwk2,sizeof(fnwk1));                      //~v59nR~
//#endif                                                           //~v59nR~
#ifdef UNX                                                         //~v59nI~
	  if (flist1->attr & FILE_TSO)//remote file                    //~v5jcI~
	   	rc=stricmp(pc1,pc2);                                       //~v5jcI~
      else                                                         //~v5jcI~
	   	rc=strcmp(pc1,pc2);                                        //~v59nI~
#else                                                              //~v59nI~
	#ifdef FTPSUPP                                                 //~v59nI~
        if (flist1->attr & FILE_REMOTE)//remote file               //~v59nM~
	      if (flist1->attr & FILE_TSO)//remote file                //~v5jcI~
		   	rc=stricmp(pc1,pc2);                                   //~v5jcI~
          else                                                     //~v5jcI~
	        rc=strcmp(pc1,pc2);                                    //~v59nI~
        else                                                       //~v59nM~
	#endif                                                         //~v59nI~
	#ifdef W32UNICODE                                              //~v6uaI~
        rc=ufilew_dircompW('N',flist1,flist2);	//name only        //~v6uaI~
	#else                                                          //~v6uaI~
	   	rc=stricmp(pc1,pc2);                                       //~v59nI~
    #endif                                                         //~v6uaI~
#endif                                                             //~v59nI~
        break;
//***************************                                      //~v6uaI~
    case 'N':         //by name
//      memset(fnwk1,0,sizeof(fnwk1));                             //~v59nR~
//      if (pos=strpbrk(pc=flist1->name,"."),!pos)                 //~v101R~
//#ifdef W32                                                       //~v105R~
#if defined(W32) || defined(DPMI)                                  //~v105I~
        pc=flist1->alias;                                          //~v101I~
        pc2=flist2->alias;                                         //~v231I~
#else                                                              //~v101I~
        pc=flist1->name;                                           //~v101R~
        pc2=flist2->name;                                          //~v231I~
#endif                                                             //~v101I~
        pc1=pc;         //1st opd                                  //~v59nI~
        if (*pc1=='.'|| *pc2=='.')   //curr or pairent             //~v59nR~
        {                                                          //~v231I~
            rc=udircompsub(pc1,pc2);                               //~v59nR~
            if (rc!=9)                                             //~v231R~
                return rc;                                         //~v231I~
        }                                                          //~v231I~
//      if (pos=strrchr(pc,'.'),!pos)                              //~v59nR~
//          strcpy(fnwk1,pc);                                      //~v59nR~
//      else                                                       //~v59nR~
//      {                                                          //~v59nR~
//          memcpy(fnwk1,pc,(UINT)((ULONG)pos-(ULONG)pc));         //~v59nR~
//          strcpy(fnwk1+8,pos+1);                                 //~v101R~
//          strcpy(fnwk1+FNMCOMPSZ,pos+1);                         //~v59nR~
//      }                                                          //~v59nR~
//      memset(fnwk2,0,sizeof(fnwk2));                             //~v59nR~
//      if (pos=strpbrk(pc=flist2->name,"."),!pos)                 //~v101R~
//#ifdef W32                                                       //~v105R~
//#if defined(W32) || defined(DPMI)                                //~v231R~
//        pc=flist2->alias;                                        //~v231R~
//#else                                                            //~v231R~
//        pc=flist2->name;                                         //~v231R~
//#endif                                                           //~v231R~
//      pc=pc2;                                                    //~v59nR~
//      if (pos=strrchr(pc,'.'),!pos)                              //~v59nR~
//          strcpy(fnwk2,pc);                                      //~v59nR~
//      else                                                       //~v59nR~
//      {                                                          //~v59nR~
//          memcpy(fnwk2,pc,(UINT)((ULONG)pos-(ULONG)pc));         //~v59nR~
//          strcpy(fnwk2+8,pos+1);                                 //~v101R~
//          strcpy(fnwk2+FNMCOMPSZ,pos+1);                         //~v59nR~
//      }                                                          //~v59nR~
        pos1=strrchr(pc1,'.');                                     //~v59nI~
        if (pos1)                                                  //~v59nI~
        	*pos1=0;		//for strcmp                           //~v59nI~
        pos2=strrchr(pc2,'.');                                     //~v59nI~
        if (pos2)                                                  //~v59nI~
        	*pos2=0;		//for strcmp                           //~v59nI~
//#ifdef OS2                                                       //~v59nR~
//        rc=memicmp(fnwk1,fnwk2,sizeof(fnwk1));                   //~v59nR~
//#else                                                            //~v59nR~
//    #ifdef UNX                                                   //~v59nR~
//        rc=memicmp(fnwk1,fnwk2,sizeof(fnwk1));//unit mdos disk 8.3name//~v59nR~
//    #else                                                        //~v59nR~
//        rc=memcmp(fnwk1,fnwk2,sizeof(fnwk1));                    //~v59nR~
//    #endif                                                       //~v59nR~
//#endif                                                           //~v59nR~
#ifdef UNX                                                         //~v59nI~
	if (flist1->attr & FILE_TSO)//remote file                      //~v5jcI~
	  rc=stricmp(pc1,pc2);                                         //~v5jcI~
    else                                                           //~v5jcI~
	  rc=strcmp(pc1,pc2);                                          //~v59nI~
#else                                                              //~v59nI~
	#ifdef FTPSUPP                                                 //~v59nI~
        if (flist1->attr & FILE_REMOTE)//remote file               //~v59nI~
	      if (flist1->attr & FILE_TSO)//remote file                //~v5jcI~
	  		rc=stricmp(pc1,pc2);                                   //~v5jcI~
          else                                                     //~v5jcI~
	  		rc=strcmp(pc1,pc2);                                    //~v59nI~
        else                                                       //~v59nI~
    #endif                                                         //~v59nI~
	#ifdef W32UNICODE                                              //~v6uaI~
        	rc=ufilew_dircompW('N',flist1,flist2);//name then ext  //~v6uaI~
	#else                                                          //~v6uaI~
	  		rc=stricmp(pc1,pc2);                                   //~v59nI~
    #endif                                                         //~v6uaI~
#endif                                                             //~v59nM~
        if (pos1)                                                  //~v59nI~
        	*pos1='.';		//restore                              //~v59nI~
        if (pos2)                                                  //~v59nI~
        	*pos2='.';                                             //~v59nI~
		if (rc)       //base name compare                          //~v59nI~
        	return rc;                                             //~v59nI~
        if (!pos1 &&  pos2)                                        //~v59nI~
        	return -1;                                             //~v59nI~
        if ( pos1 && !pos2)                                        //~v59nI~
        	return  1;                                             //~v59nI~
        if ( !pos1 && !pos2)                                       //~v59nR~
        	return 0;                                              //~v59nR~
#ifdef UNX                                                         //~v59nI~
	   if (flist1->attr & FILE_TSO)//remote file                   //~v5jcI~
	 	 rc=stricmp(pos1,pos2);                                    //~v5jcI~
       else                                                        //~v5jcI~
	 	 rc=strcmp(pos1,pos2);                                     //~v59nR~
#else                                                              //~v59nI~
	#ifdef FTPSUPP                                                 //~v59nI~
        if (flist1->attr & FILE_REMOTE)//remote file               //~v59nI~
	      if (flist1->attr & FILE_TSO)//remote file                //~v5jcI~
	  		rc=stricmp(pos1,pos2);                                 //~v5jcI~
          else                                                     //~v5jcI~
	  		rc=strcmp(pos1,pos2);                                  //~v59nI~
        else                                                       //~v59nI~
    #endif                                                         //~v59nI~
	#ifdef W32UNICODE                                              //~v6uaI~
        	rc=ufilew_dircompW('E',flist1,flist2);//extention      //~v6uaI~
	#else                                                          //~v6uaI~
	  		rc=stricmp(pos1,pos2);                                 //~v59nI~
    #endif                                                         //~v6uaI~
#endif                                                             //~v59nI~
        break;
//***************************                                      //~v6uaI~
    case 'D':         //by date
#ifdef AIX                                                         //~v5dhI~
        if (!(rc=(INT)(*(UINT*)(void*)&flist1->date                //~v5dhI~
                    -*(UINT*)(void*)&flist2->date)))  //same date  //~v5dhI~
            rc=(INT)(*(UINT*)(void*)&flist1->time                  //~v5dhI~
                        -*(UINT*)(void*)&flist2->time);   //by time//~v5dhI~
#else                                                              //~v5dhI~
//        if (!(rc=(INT)(*(USHORT*)(void*)&flist1->date            //~v6q0R~
//                    -*(USHORT*)(void*)&flist2->date)))  //same date//~v6q0R~
//            rc=(INT)(*(USHORT*)(void*)&flist1->time              //~v6q0R~
//                        -*(USHORT*)(void*)&flist2->time);   //by time//~v6q0R~
        if (!(rc=(INT)(FDATE2USHORT(flist1->date)                  //~v6q0I~
                    -FDATE2USHORT(flist2->date))))//same date      //~v6q0I~
            rc=(INT)(FTIME2USHORT(flist1->time)                    //~v6q0I~
                        -FTIME2USHORT(flist2->time));  //by time   //~v6q0I~
#endif                                                             //~v5dhI~
        if (!rc)        //same seq
//          rc=(int)((ULONG)flist1-(ULONG)flist2);//input spec sequence//~v6hhR~
            rc=(int)((ULPTR)flist1-(ULPTR)flist2);//input spec sequence//~v6hhI~
        break;
    case 'T':         //DateTime+Name                              //~v5cyI~
        pc =flist1->name;                                          //~v5cyI~
        pc2=flist2->name;                                          //~v5cyI~
        if (*pc=='.'|| *pc2=='.')   //curr or pairent              //~v5cyI~
        {                                                          //~v5cyI~
            rc=udircompsub(pc,pc2); //keep top is ".." and 2nd is "."//~v5cyI~
            if (rc!=9)                                             //~v5cyI~
                return rc;                                         //~v5cyI~
        }                                                          //~v5cyI~
#ifdef AIX                                                         //~v5dhI~
        if (!(rc=(INT)(*(UINT*)(void*)&flist1->date                //~v5dhI~
                    -*(UINT*)(void*)&flist2->date)))  //same date  //~v5dhI~
            rc=(INT)(*(UINT*)(void*)&flist1->time                  //~v5dhI~
                        -*(UINT*)(void*)&flist2->time);   //by time//~v5dhI~
#else                                                              //~v5dhI~
//        if (!(rc=(INT)(*(USHORT*)(void*)&flist1->date              //~v5cyI~//~v6q0R~
//                    -*(USHORT*)(void*)&flist2->date)))  //same date//~v5cyI~//~v6q0R~
//            rc=(INT)(*(USHORT*)(void*)&flist1->time                //~v5cyI~//~v6q0R~
//                        -*(USHORT*)(void*)&flist2->time);   //by time//~v5cyI~//~v6q0R~
        if (!(rc=(INT)(FDATE2USHORT(flist1->date)                  //~v6q0I~
                    -FDATE2USHORT(flist2->date)))) //same date     //~v6q0I~
            rc=(INT)(FTIME2USHORT(flist1->time)                    //~v6q0I~
                        -FTIME2USHORT(flist2->time));   //by time  //~v6q0I~
#endif                                                             //~v5dhI~
        if (!rc)        //same seq                                 //~v5cyI~
        {                                                          //~v5cyI~
	    	orgsorttype=Ssorttype;                                 //~v5cyI~
	    	Ssorttype='L';                                         //~v5cyI~
	    	if (orgsorttype<0)                                     //~v5cyI~
            	Ssorttype=-Ssorttype;	//keep ascending by name   //~v5cyI~
            rc=udircompare(ent1,ent2);                             //~v5cyI~
	    	Ssorttype=orgsorttype;                                 //~v5cyI~
        }                                                          //~v5cyI~
        break;                                                     //~v5cyI~
//***************************                                      //~v6uaI~
    case 'S':         //by size                                    //~v067I~
#ifdef LFSSUPP                                                     //~v5k0I~
        szdiff=flist1->size-flist2->size;                          //~v5k0M~
        if (szdiff<0)                                              //~v5k0M~
        	rc=-1;                                                 //~v5k0M~
        else                                                       //~v5k0M~
        if (szdiff>0)                                              //~v5k0M~
        	rc=1;                                                  //~v5k0M~
        else                                                       //~v5k0M~
        	rc=0;                                                  //~v5k0M~
#else                                                              //~v5k0I~
        rc=(INT)(flist1->size-flist2->size);                       //~v5k0R~
#endif                                                             //~v5k0I~
        if (!rc)        //same seq                                 //~v067I~
//          rc=(int)((ULONG)flist1-(ULONG)flist2);//input spec sequence//~v067I~//~v6hhR~
            rc=(int)((ULPTR)flist1-(ULPTR)flist2);//input spec sequence//~v6hhI~
        break;                                                     //~v067I~
    case 'Z':         //by size+name                               //~v5cyI~
        pc =flist1->name;                                          //~v5cyI~
        pc2=flist2->name;                                          //~v5cyI~
        if (*pc=='.'|| *pc2=='.')   //curr or pairent              //~v5cyI~
        {                                                          //~v5cyI~
            rc=udircompsub(pc,pc2); //keep top is ".." and 2nd is "."//~v5cyI~
            if (rc!=9)                                             //~v5cyI~
                return rc;                                         //~v5cyI~
        }                                                          //~v5cyI~
#ifdef LFSSUPP                                                     //~v5k0I~
        szdiff=flist1->size-flist2->size;                          //~v5k0M~
        if (szdiff<0)                                              //~v5k0M~
        	rc=-1;                                                 //~v5k0M~
        else                                                       //~v5k0M~
        if (szdiff>0)                                              //~v5k0M~
        	rc=1;                                                  //~v5k0M~
        else                                                       //~v5k0M~
        	rc=0;                                                  //~v5k0M~
#else                                                              //~v5k0I~
        rc=(INT)(flist1->size-flist2->size);                       //~v5k0R~
#endif                                                             //~v5k0I~
        if (!rc)        //same seq                                 //~v5cyI~
        {                                                          //~v5cyI~
	    	orgsorttype=Ssorttype;                                 //~v5cyI~
	    	Ssorttype='L';                                         //~v5cyI~
	    	if (orgsorttype<0)                                     //~v5cyI~
            	Ssorttype=-Ssorttype;	//keep ascending by name   //~v5cyI~
            rc=udircompare(ent1,ent2);                             //~v5cyI~
	    	Ssorttype=orgsorttype;                                 //~v5cyI~
        }                                                          //~v5cyI~
        break;                                                     //~v5cyI~
//***************************                                      //~v6uaI~
    default:                                                       //~v328R~
        rc=0;                                                      //~v328R~
    }//switch by type
    if (Ssorttype<0)
        rc=-rc;             //reverse
UTRACEP("ret rc=%d\n",rc);                                         //~v62YI~
    return rc;
}//dircompare
//**********************************************************************//~v231I~
//* seq for .(cur dir) and ..(parent dir)                          //~v231I~
//*parm1:ent1 fnm                                                  //~v231I~
//*parm2:ent2 fnm    one of parm1/parm2 top is '.'                 //~v231I~
//*  return code: -1: ent1<ent2                                    //~v231I~
//*                0: ent1=ent2                                    //~v231I~
//*                1: ent1>ent2                                    //~v231I~
//*                2: continue compare                             //~v231I~
//**********************************************************************//~v231I~
int udircompsub(char *Ppc1,char *Ppc2)                             //~v231I~
{                                                                  //~v231R~
    int sw1=0,sw2=0;                                               //~v231I~
//*****************                                                //~v231I~
    if (*Ppc1=='.')                                                //~v231I~
    {                                                              //~v231I~
        Ppc1++;                                                    //~v231R~
        if (!*Ppc1)                                                //~v231I~
            sw1=-1;     //cur dir                                  //~v231R~
        else                                                       //~v231I~
            if (*Ppc1=='.' && !*(Ppc1+1))                          //~v231R~
                sw1=-2;     //parent dir                           //~v231R~
    }                                                              //~v231I~
    if (*Ppc2=='.')                                                //~v231I~
    {                                                              //~v231I~
        Ppc2++;                                                    //~v231R~
        if (!*Ppc2)                                                //~v231I~
            sw2=1;      //cur dir                                  //~v231R~
        else                                                       //~v231I~
            if (*Ppc2=='.' && !*(Ppc2+1))                          //~v231R~
                sw2=2;  //parent dir                               //~v231R~
    }                                                              //~v231I~
    if (!sw1 && !sw2)           //both file                        //~v231R~
        return 9;                                                  //~v231R~
    return sw1+sw2;         //both is cur/parent dir               //~v231I~
}//udircompsub                                                     //~v231I~
//****************************************************************//~5A14M~
//*uredirect                                                    //~5A14M~
//* redirect stdin/stdout/stderr                                //~5A14M~
//*parm1 :0:redirect file to stdin                              //~5A14M~
//*      :1:redirect stdout to file                             //~5A14M~
//*      :2:redirect stderr to file                             //~5A14M~
//*      :3:redirect stdout and stderr to file                  //~5A14I~
//*parm2 :filename                                              //~5A14M~
//*parm3 :already opened file handle                               //~v5f6R~
//*       or 0:open requred                                        //~v5f6I~
//*       or 1:open by append mode                                 //~v5f6I~
//*retrn:FILE * (fclose required befire redirect restore)          //~v249R~
//****************************************************************//~5A14M~
FILE *uredirect(int Phandle,char *Pfile,FILE *Pfh)              //~5A15R~
{                                                               //~5A14M~
    FILE *fh;                                                   //~5A14I~
    int   fno,tfno;                                                //~v053R~
    int appendmode;                                                //~v5f6I~
//*********************                                         //~5A14M~
//  if ((ULONG)Pfh==1)                                             //~v5f6I~//~v6hhR~
    if ((ULONG)(ULPTR)Pfh==1)                                      //~v6hhI~
    {                                                              //~v5f6I~
    	appendmode=1;                                              //~v5f6I~
        Pfh=0;                                                     //~v5f6I~
    }                                                              //~v5f6I~
    else                                                           //~v5f6I~
    	appendmode=0;                                              //~v5f6I~
    switch(Phandle)                                             //~5A14M~
    {                                                           //~5A14M~
    case 0:     //stdin                                         //~5A14R~
        if (fh=Pfh,!fh)                                            //~v022R~
           fh=fopen(Pfile,"r");                                 //~5A15R~
        break;                                                  //~5A14M~
    case 1:     //stdout                                        //~5A14R~
        fflush(stdout);                                            //~v249R~
        if (fh=Pfh,!fh)                                            //~v249R~
        {                                                          //~v5f6I~
          if (appendmode)                                          //~v5f6I~
          {                                                        //~v5f6I~
            fh=fopen(Pfile,"a");                                   //~v5f6I~
            if (fh)                                                //~v5f6I~
                fseek(fh,0,SEEK_END);                              //~v5f6I~
          }                                                        //~v5f6I~
          else                                                     //~v5f6I~
            fh=fopen(Pfile,"w");                                   //~v249R~
        }                                                          //~v5f6I~
        break;                                                     //~v249R~
    case 2:     //stderr                                        //~5A14R~
        fflush(stderr);                                            //~v249R~
        if (fh=Pfh,!fh)                                            //~v249R~
        {                                                          //~v5f6I~
          if (appendmode)                                          //~v5f6I~
          {                                                        //~v5f6I~
            fh=fopen(Pfile,"a");                                   //~v5f6I~
            if (fh)                                                //~v5f6I~
                fseek(fh,0,SEEK_END);                              //~v5f6I~
          }                                                        //~v5f6I~
          else                                                     //~v5f6I~
            fh=fopen(Pfile,"w");                                   //~v249R~
        }                                                          //~v5f6I~
        break;                                                     //~v249R~
    case 3:     //stdout and stderr                             //~5A14I~
        fflush(stdout);                                            //~v249R~
        fflush(stderr);                                            //~v249R~
        if (fh=Pfh,!fh)                                            //~v022R~
        {                                                          //~v5f6I~
          if (appendmode)                                          //~v5f6I~
          {                                                        //~v5f6I~
            fh=fopen(Pfile,"a");                                   //~v5f6I~
            if (fh)                                                //~v5f6I~
                fseek(fh,0,SEEK_END);                              //~v5f6I~
          }                                                        //~v5f6I~
          else                                                     //~v5f6I~
            fh=fopen(Pfile,"w");                                //~5A15R~
        }                                                          //~v5f6I~
        break;                                                  //~5A14I~
    default:                                                    //~5A14M~
        return 0;                                               //~5A14R~
    }                                                           //~5A14M~
    if (!fh)                                                    //~5A14R~
    {                                                           //~5A14I~
#ifdef UNX                                                         //~v352I~
      if (errno==EACCES)                                           //~v352R~
        ufilenopermission("fopen(redirect)",Pfile,errno);          //~v366R~
      else                                                         //~v352I~
#endif //UNX                                                       //~v352I~
        ufileapierr("fopen",Pfile,errno);                       //~5A14I~
        return 0;                                               //~5A14I~
    }                                                           //~5A14I~
                                                                //~5A14I~
    fno=fileno(fh);                                             //~5A14R~
                                                                //~5A14I~
    if ((tfno=Phandle)==3)  //stderr and stdout                 //~5A14I~
        tfno=1;             //stdout at first                   //~5A14I~
    if ((Ssavehandle[tfno]=dup(tfno))==-1)                      //~5A14I~
    {                                                           //~5A14I~
        ufileapierr("dup for save",Pfile,errno);                //~5A14I~
        fclose(fh);                                             //~5A14I~
        return 0;                                               //~5A14I~
    }                                                           //~5A14I~
//  if (rc=dup2(fno,tfno),rc)                                      //~v053R~
    if (dup2(fno,tfno)==-1)                                        //~v053I~
    {                                                           //~5A14I~
        ufileapierr2("dup2",Pfile,Sstd[tfno],errno);            //~5A14I~
        fclose(fh);                                             //~5A14R~
        return 0;                                               //~5A14I~
    }                                                           //~5A14I~
    if (Phandle==3) //stderr and stdout                         //~5A14I~
    {                                                              //~v251I~
        if ((Ssavehandle[2]=dup(2))==-1)                           //~v251I~
        {                                                          //~v251I~
            ufileapierr("dup for stderr save",Pfile,errno);        //~v251I~
            Ssavehandle[2]=Ssavehandle[1];                         //~v251I~
        }                                                          //~v251I~
//      if (rc=dup2(fno,2),rc)                                     //~v053R~
        if (dup2(fno,2)==-1)                                       //~v053I~
        {                                                       //~5A14I~
            ufileapierr2("dup2",Pfile,Sstd[2],errno);           //~5A14I~
            dup2(Ssavehandle[1],1);                             //~5A14I~
            fclose(fh);                                         //~5A14R~
            return 0;                                           //~5A14I~
        }                                                       //~5A14I~
    }//stdout and stderr                                           //~v251I~
    return fh;                                                  //~5A14M~
}//uredirect                                                    //~5A14M~
                                                                //~5A14M~
//****************************************************************//~5A14I~
//*uredirectrestore                                             //~5A14I~
//* back to before redirect                                     //~5A14I~
//*parm1 :specify previous redirect fileno                      //~5A14I~
//*retrn:rc                                                     //~5A14I~
//****************************************************************//~5A14I~
int uredirectrestore(int Phandle)                               //~5A14R~
{                                                               //~5A14I~
    int   rc;                                                   //~5A14R~
//*********************                                         //~5A14I~
    switch(Phandle)                                             //~5A14R~
    {                                                           //~5A14I~
    case 0:     //stdin                                         //~5A14I~
#ifdef DOS                                                      //~5A14I~
        if (rc=fclose(stdin),rc)                                //~5A14R~
            return ufileapierr("fclose",Sstd[0],rc);            //~5A14I~
        if (!fdopen(0,"r"))                                     //~5A14I~
            return ufileapierr("fdopen",Sstd[0],errno);         //~5A14I~
#else                                                           //~5A14I~
//        if (rc=fclose(stdin),rc)                                 //~v249R~
//            return ufileapierr("fclose",Sstd[0],rc);             //~v249R~
          fflush(stdin);                                           //~v249I~
#endif                                                          //~5A14I~
        break;                                                  //~5A14I~
    case 1:     //stdout                                        //~5A14I~
#ifdef DOS                                                      //~5A14I~
        if (rc=fclose(stdout),rc)                               //~5A14I~
            return ufileapierr("fclose",Sstd[1],rc);            //~5A14I~
        if (!fdopen(1,"w"))                                     //~5A15R~
            return ufileapierr("fdopen",Sstd[1],errno);         //~5A14I~
#else                                                           //~5A14I~
//        if (rc=fclose(stdout),rc)                                //~v249R~
//            return ufileapierr("fclose",Sstd[1],rc);             //~v249R~
          fflush(stdout);                                          //~v249I~
#endif                                                          //~5A14I~
        break;                                                  //~5A14I~
    case 2:     //stderr                                        //~5A14I~
#ifdef DOS                                                      //~5A14I~
        if (rc=fclose(stderr),rc)                               //~5A14I~
            return ufileapierr("fclose",Sstd[2],rc);            //~5A14I~
        if (!fdopen(2,"w"))                                     //~5A15R~
            return ufileapierr("fdopen",Sstd[2],errno);         //~5A14I~
#else                                                           //~5A14I~
//        if (rc=fclose(stderr),rc)                                //~v249R~
//            return ufileapierr("fclose",Sstd[2],rc);             //~v249R~
          fflush(stderr);                                          //~v249I~
#endif                                                          //~5A14I~
        break;                                                  //~5A14I~
    case 3:     //stdout and stderr                             //~5A14I~
        rc=uredirectrestore(1);                                 //~5A14I~
        rc+=uredirectrestore(2);                                //~5A14I~
        return rc;                                              //~5A14I~
    default:                                                    //~5A14I~
        return -1;                                              //~5A14I~
    }                                                           //~5A14I~
//  if (rc=dup2(Ssavehandle[Phandle],Phandle),rc)                  //~v053R~
    if (dup2(Ssavehandle[Phandle],Phandle)==-1)                    //~v053I~
        return ufileapierr("dup2 for restore",Sstd[Phandle],errno);//~5A14R~
    return 0;                                                   //~5A14I~
}//uredirectrestore                                             //~5A14I~
                                                                //~5A14I~
//*******************************************************       //~5625M~
//*ufdateedit                                                   //~5625I~
//* file date edit                                              //~5625I~
//* parm1 :FDATE                                                //~5625M~
//* parm2 :edit patern(YY:MM:DD,mm/dd/yy etc,lower case mean 0 suppress)//~5625I~
//* parm3 :output area addr                                     //~5625M~
//* return:output area addr                                     //~5625I~
//******************************************************        //~5625M~
UCHAR *ufdateedit(FDATE Pdate,UCHAR *Ppatern,UCHAR *Pout)       //~5625I~
{                                                               //~5625M~
    UCHAR editwk1[7],editwk2[7],*pc;                            //~5625I~
    UCHAR editwkc[8];                                              //~v59zI~
    int yy;                                                        //~v132I~
//******************                                            //~5625M~
#ifdef AIX                                                         //~v6kaI~
  if (!*(int*)(&Pdate))                                            //~v6kaR~
#else                                                              //~v6kaI~
//if (!*(USHORT*)(&Pdate))                                         //~v6kaI~//~v6q0R~
  if (!FDATE2USHORT(Pdate))                                        //~v6q0I~
#endif                                                             //~v6kaI~
  	yy=0;                                                          //~v6kaI~
  else                                                             //~v6kaI~
    yy=(Pdate.year+1980)%100;                                      //~v132R~
    sprintf(editwkc,"%04d",(Pdate.year+1980)%10000);               //~v59zR~
    sprintf(editwk1,"%02d%02d%02d",                             //~5625I~
//              Pdate.year+80,                                     //~v132R~
                yy,                                                //~v132I~
                Pdate.month,                                    //~5625I~
                Pdate.day);                                     //~5625I~
    sprintf(editwk2,"%2d%2d%2d",                                //~5625I~
//              Pdate.year+80,                                     //~v132R~
                yy,                                                //~v132I~
                Pdate.month,                                    //~5625I~
                Pdate.day);                                     //~5625I~
//printf("ufdateedit %s,%s,yy=%d\n",editwk1,editwk2,yy);//@@@@     //~v132R~
    strcpy(Pout,Ppatern);                                       //~5625M~
//year                                                          //~5625I~
  if (pc=ustrstri(Pout,"YYYY"),pc)                                 //~v59zI~
        memcpy(pc,editwkc,4);                                      //~v59zI~
  else                                                             //~v59zI~
  {                                                                //~v59zI~
    if (pc=strstr(Pout,"YY"),pc)                                //~5625R~
        memcpy(pc,editwk1,2);                                   //~5625I~
    if (pc=strstr(Pout,"yy"),pc)                                //~5625R~
        memcpy(pc,editwk2,2);                                   //~5625I~
  }                                                                //~v59zI~
//month                                                         //~5625I~
    if (pc=strstr(Pout,"MM"),pc)                                //~5625R~
        memcpy(pc,editwk1+2,2);                                 //~5625I~
    if (pc=strstr(Pout,"mm"),pc)                                //~5625R~
        memcpy(pc,editwk2+2,2);                                 //~5625I~
//day                                                           //~5625I~
    if (pc=strstr(Pout,"DD"),pc)                                //~5625R~
        memcpy(pc,editwk1+4,2);                                 //~5625I~
    if (pc=strstr(Pout,"dd"),pc)                                //~5625R~
        memcpy(pc,editwk2+4,2);                                 //~5625I~
    return Pout;                                                //~5625I~
}//ufdateedit                                                   //~5625I~
                                                                //~5625M~
//*******************************************************       //~5625I~
//*uftimeedit                                                   //~5625I~
//* file date edit                                              //~5625I~
//* parm1 :FTIME                                                //~5625I~
//* parm2 :edit patern(HH:MM:SS,hh/mm/ss etc,lower case mean 0 suppress)//~5625I~
//* parm3 :output area addr                                     //~5625I~
//* return:output area addr                                     //~5625I~
//******************************************************        //~5625I~
UCHAR *uftimeedit(FTIME Ptime,UCHAR *Ppatern,UCHAR *Pout)       //~5625R~
{                                                               //~5625I~
    UCHAR editwk1[7],editwk2[7],*pc;                            //~5625I~
//******************                                            //~5625I~
    sprintf(editwk1,"%02d%02d%02d",                             //~5625I~
                Ptime.hours,                                    //~5625I~
                Ptime.minutes,                                  //~5625I~
//              Ptime.twosecs*2);                                  //~v6htR~
                Ptime.twosecs*2+Soddsec);                          //~v6htI~
    sprintf(editwk2,"%2d%2d%2d",                                //~5625I~
                Ptime.hours,                                    //~5625I~
                Ptime.minutes,                                  //~5625I~
//              Ptime.twosecs*2);                                  //~v6htR~
                Ptime.twosecs*2+Soddsec);                          //~v6htI~
    strcpy(Pout,Ppatern);                                       //~5625I~
//hour                                                          //~5625I~
    if (pc=strstr(Pout,"HH"),pc)                                //~5625R~
        memcpy(pc,editwk1,2);                                   //~5625I~
    if (pc=strstr(Pout,"hh"),pc)                                //~5625R~
        memcpy(pc,editwk2,2);                                   //~5625I~
//minutes                                                       //~5625I~
    if (pc=strstr(Pout,"MM"),pc)                                //~5625R~
        memcpy(pc,editwk1+2,2);                                 //~5625I~
    if (pc=strstr(Pout,"mm"),pc)                                //~5625R~
        memcpy(pc,editwk2+2,2);                                 //~5625I~
//seconds                                                       //~5625I~
    if (pc=strstr(Pout,"SS"),pc)                                //~5625R~
        memcpy(pc,editwk1+4,2);                                 //~5625I~
    if (pc=strstr(Pout,"ss"),pc)                                //~5625R~
        memcpy(pc,editwk2+4,2);                                 //~5625I~
    return Pout;                                                //~5625I~
}//uftimeedit                                                   //~5625I~
//*******************************************************          //~v6htI~
//*uftimeedit_unix                                                 //~v6htI~
//*second not by 2sec but by 1sec                                  //~v6htI~
//******************************************************           //~v6htI~
UCHAR *uftimeedit_1sec(FTIME Ptime,UCHAR *Ppatern,UCHAR *Pout,int Poddsec)//~v6htR~
{                                                                  //~v6htI~
	UCHAR *pout;                                                   //~v6htI~
//******************                                               //~v6htI~
	Soddsec=Poddsec;                                               //~v6htI~
	pout=uftimeedit(Ptime,Ppatern,Pout);                           //~v6htI~
    Soddsec=0;                                                     //~v6htI~
    return pout;                                                   //~v6htI~
}//uftimeedit_1sec                                                 //~v6htR~
#ifdef W32                                                         //~v59vR~
//*******************************************************          //~v59vI~
//*ufileisroot ,called by ROOTDIR macro                            //~v59vI~
//* chk rootdir or not(support remote file)                        //~v59vI~
//* parm1 :filename                                                //~v59vI~
//* returnm 1:local,2:remote,0:not root dir                        //~v59vI~
//******************************************************           //~v59vI~
int ufileisroot(char *Pfname)                                      //~v59vR~
{                                                                  //~v59vI~
	int  hostnmlen;                                                //~v59vR~
    char *pfnm;                                                    //~v59vI~
//******************                                               //~v59vI~
	if (ROOTDIR_LOCAL(Pfname))                                     //~v59vR~
    	return 1;		//win local root                           //~v59vI~
	if (!(hostnmlen=uftpisremote(Pfname,0)))	//not remote file patern//~v59vR~
    	return 0;		//win local not root                       //~v59vI~
    pfnm=Pfname+hostnmlen+1;                                       //~v59vI~
    if (FTP_ROOTDIR(pfnm))                                         //~v59vR~
    	return 2;		//remote root                              //~v59vI~
    return 0;		//remote but not root                          //~v59vI~
}//ufileisroot                                                     //~v59vI~
#endif                                                             //~v59vI~
//******************************************************           //~v6qbI~
int udirlist_chk_max_entry(int Pctr)                               //~v6qbI~
{                                                                  //~v6qbI~
#if !defined(ULIB64) && !defined(ULIB64X)                          //~v6qbM~
//  if (UDIRLISTSZ*(Pctr+1)>MAXUDIRLISTALLOCSZ)                    //~v6ybR~
    if (UDIRLISTSZ*(unsigned)(Pctr+1)>MAXUDIRLISTALLOCSZ)          //~v6ybI~
    {                                                              //~v6qbM~
    	uerrmsg("too many(%d) entry in the dir,max is %d. Use wildcard.",0,//~v6qbI~
        		Pctr,MAXUDIRLISTALLOCSZ/UDIRLISTSZ-1);             //~v6qbI~
        return 4;                                                  //~v6qbM~
    }                                                              //~v6qbM~
#endif                                                             //~v6qbM~
	return 0;                                                      //~v6qbI~
}                                                                  //~v6qbI~
#ifdef UNX  //!!!!!!!!!!!!!!!!!!                                   //~v6B9I~
#else       //!!!!!!!!!!!!!!!!!!                                   //~v6B9I~
//*******************************************************          //~v6B9I~
//*On windows,prototype only                                       //~v6B9I~
//******************************************************           //~v6B9I~
char *ufullpathCP(int Popt,char *Pfullpath,char *Pfilename,size_t Plen,int *Prc)//~v6B9I~
{                                                                  //~v6B9I~
	return ufullpath(Pfullpath,Pfilename,Plen);                    //~v6B9I~
}                                                                  //~v6B9I~
#endif                                                             //~v6B9I~
//**************************************************************** //~v6J0I~
//*set udirlist->name                                              //~v6J0I~
//*rc=4:ovf,rc=1:new shortbuff                                     //~v6J0I~
//**************************************************************** //~v6J0I~
int udirlist_setname(int Popt,PUDIRLIST Ppudl,char *Psrc,size_t Psrcsz)//~v6J0I~
{                                                                  //~v6J0I~
	size_t sz;                                                     //~v6J0I~
    char *pc,*pco;                                                 //~v6J0I~
    int rc=0,swallocold,szold,swshortnew=0;                        //~v6J0R~
//****************                                                 //~v6J0I~
    pco=Ppudl->name;                                               //~v6J0I~
    UTRACEP("%s:pudl=%p,old=%p=%s,short=%s\n",UTT,Ppudl,pco,pco,Ppudl->nameShortbuff);//~v6J0I~
    swallocold=Ppudl->otherflag & UDLOF_ALLOCNAME;                 //~v6J0I~
    szold=Ppudl->namesz;                                           //~v6J0I~
	if (Psrcsz)	//source field max size specified                  //~v6J0I~
    	sz=ustrnlen(Psrc,(unsigned)Psrcsz);                        //~v6J0R~
    else                                                           //~v6J0I~
    	sz=strlen(Psrc);                                           //~v6J0R~
    if (Popt & UDLSNO_UDIRLISTNAMESZ)//       0x01   //allocate max size//~v6J0R~
        sz=UDIRLISTNAMESZ-1;                                       //~v6J0I~
    else                                                           //~v6J0I~
    if (sz>=UDIRLISTNAMESZ)                                        //~v6J0I~
    {                                                              //~v6J0I~
        sz=UDIRLISTNAMESZ-1;                                       //~v6J0I~
        rc=4;                                                      //~v6J0I~
    }                                                              //~v6J0I~
    if ((int)sz<szold)  //UDIRLISTWK has lagest buff               //~v6J0R~
    {                                                              //~v6J0I~
    	swshortnew=1;                                              //~v6J0I~
    	pc=Ppudl->name;                                            //~v6J0I~
        if (!swallocold)                                           //~v6J0I~
        	rc=1;                                                  //~v6J0R~
    }                                                              //~v6J0I~
    else                                                           //~v6J0I~
    {                                                              //~v6J0I~
        if (sz>=sizeof(Ppudl->nameShortbuff))                      //~v6J0R~
        {                                                          //~v6J0R~
            pc=umalloc(sz+1);                                      //~v6J0R~
            Ppudl->otherflag|=UDLOF_ALLOCNAME;                     //~v6J0R~
		    Ppudl->namesz=(int)sz+1;                               //~v6J0R~
        }                                                          //~v6J0R~
        else                                                       //~v6J0R~
        {                                                          //~v6J0R~
            pc=Ppudl->nameShortbuff;                               //~v6J0R~
            Ppudl->otherflag&=~UDLOF_ALLOCNAME;                    //~v6J0R~
		    Ppudl->namesz=(int)sizeof(Ppudl->nameShortbuff);       //~v6J0I~
            rc=1;                                                  //~v6J0R~
        }                                                          //~v6J0R~
    }                                                              //~v6J0I~
    UmemcpyZ(pc,Psrc,sz);	//add null after sz                    //~v6J0I~
    Ppudl->name=pc;                                                //~v6J0I~
    if (pco && swallocold && !swshortnew)	//old is allocated     //~v6J0R~
    {                                                              //~v6J0I~
    	UTRACEP("%s:old=%s\n",UTT,pco);                            //~v6J0I~
    	ufree(pco);                                                //~v6J0I~
    }                                                              //~v6J0I~
    UTRACEP("%s:return new=%p=%s,short=%s\n",UTT,Ppudl,pc,pc,Ppudl->nameShortbuff);//~v6J0I~
    return rc;                                                     //~v6J0R~
}//udirlist_setname                                                //~v6J0I~
//**************************************************************** //~v6J0I~
//*set udirlist->name                                              //~v6J0I~
//*rc=4:ovf,rc=1:new shortbuff                                     //~v6J0I~
//**************************************************************** //~v6J0I~
int udirlist_setname_cat(int Popt,PUDIRLIST Ppudl,char *Psrc)      //~v6J0I~
{                                                                  //~v6J0I~
	int rc;                                                        //~v6J0I~
//****************                                                 //~v6J0I~
	{                                                              //~v6J0I~
		UDIRLIST_NAMECOPY2WK(Ppudl,wkudlname);                     //~v6J0R~
        strcat(wkudlname,Psrc);                                    //~v6J0I~
        rc=udirlist_setname(0,Ppudl,wkudlname,0);	//@@@@FIXME test//~v6J0I~
    }                                                              //~v6J0I~
    return rc;                                                     //~v6J0I~
}//udirlist_setname_cat                                            //~v6J0I~
#ifdef W32                                                         //~v6J0I~
//**************************************************************** //~v6J0I~
//*set udirlist->nameW                                             //~v6J0I~
//*rc=4:ovf,rc=1:new shortbuff                                     //~v6J0I~
//**************************************************************** //~v6J0I~
int udirlist_setnameW(int Popt,PUDIRLIST Ppudl,UWCH *PsrcW,int Pucsctr/*src ucsctr*/)//~v6J0R~
{                                                                  //~v6J0I~
	size_t sz;                                                     //~v6J0I~
    UWCH *pw,*pwo;                                                 //~v6J0I~
    int rc=0,swallocold,szold,swshortnew=0;                        //~v6J0R~
//****************                                                 //~v6J0I~
    pwo=Ppudl->nameW;                                              //~v6J0I~
    swallocold=Ppudl->otherflag & UDLOF_ALLOCNAMEW;                //~v6J0I~
    szold=Ppudl->nameWsz;                                          //~v6J0I~
	if (Pucsctr)	//source field max size specified              //~v6J0R~
    	sz=ctr2szW(Pucsctr);                                       //~v6J0I~
    else                                                           //~v6J0I~
    	sz=strszW(PsrcW);                                          //~v6J0R~
    sz+=sizeof(UWCH);    	//required sz for last '0'             //~v6J0R~
    if (Popt & UDLSWNO_UDIRLISTNAMEWSZ)//      0x01   //allocate max size//~v6J0R~
        sz=UDIRLISTNAMEWSZ;                                        //~v6J0I~
    else                                                           //~v6J0I~
    if (sz>UDIRLISTNAMEWSZ)                                        //~v6J0R~
    {                                                              //~v6J0I~
        sz=UDIRLISTNAMEWSZ;                                        //~v6J0I~
        rc=4;                                                      //~v6J0I~
    }                                                              //~v6J0I~
    if ((int)sz<=szold)	//no need to expand                        //~v6J0R~
    {                                                              //~v6J0I~
    	swshortnew=1;                                              //~v6J0I~
    	pw=Ppudl->nameW;                                           //~v6J0I~
        if (!swallocold)                                           //~v6J0I~
        	rc=1;                                                  //~v6J0I~
    }                                                              //~v6J0I~
    else                                                           //~v6J0I~
    {                                                              //~v6J0I~
        if (sz>sizeof(Ppudl->nameWShortbuff))                      //~v6J0R~
        {                                                          //~v6J0R~
            pw=umalloc(sz);                                        //~v6J0R~
            Ppudl->otherflag|=UDLOF_ALLOCNAMEW;                    //~v6J0R~
            Ppudl->nameWsz=sz;                                     //~v6J0I~
        }                                                          //~v6J0R~
        else                                                       //~v6J0R~
        {                                                          //~v6J0R~
            pw=Ppudl->nameWShortbuff;                              //~v6J0R~
            Ppudl->otherflag&=~UDLOF_ALLOCNAMEW;                   //~v6J0R~
            Ppudl->nameWsz=sizeof(Ppudl->nameWShortbuff);          //~v6J0I~
            rc=1;   //new is shortbuff                             //~v6J0R~
        }                                                          //~v6J0R~
    }                                                              //~v6J0I~
	UmemcpyZWctr(pw,PsrcW,sz2ctrW(sz)-1);	//set last L'0'        //~v6J0R~
    Ppudl->nameW=pw;                                               //~v6J0I~
    UTRACED("new nameW",Ppudl->nameW,(int)sz);                     //~v6J0R~
    if (pwo && swallocold && !swshortnew)                          //~v6J0R~
    {                                                              //~v6J0I~
    	UTRACED("old nameW",Ppudl->nameW,strszW(Ppudl->nameW));    //~v6J0I~
    	ufree(pwo);                                                //~v6J0I~
    }                                                              //~v6J0I~
    return rc;                                                     //~v6J0I~
}//udirlist_setnameW                                               //~v6J0I~
#endif //W32                                                       //~v6J0I~
