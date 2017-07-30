//*CID://+vba2R:                              update#=  624;       //~vba4R//+vba2R
//************************************************************* //~5102I~
//* xesub.c                                                      //~5102R~
//************************************************************* //~5102I~
//vba4:170715 msvs2017 warning;                                    //~vba4I
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I
//vb89:170217 create if not found. ::xehosts ::xesync_.cfg         //~vb89I
//vb7q:170123 (Bug)Longname trated as Not found (New File)         //~vb7qI
//vb7n:170117 move filename position to last on errmsg for longname//~vb7nI
//vb7j:170115 (Win)_MAX_PATH is ucsctr,mbcs len is more over       //~vb7jI
//vb7e:170108 FTP crash by longname                                //~vb7eI
//vb7a:170104 msg errtoolong for filename is errtoolongpath        //~vb7aI
//vb75:170103 rc=4(err) of ufilewildexp was not chked for too long filename//~vb75I
//vb4h:160804 fnm list reverse len is short because strlen stop by 00 of dbcs unicode//~vb4hI
//vb2O:160320 (Bug:Win)permission err msg when filenot found for xesynw.cfg//~vb2OI
//vb2e:160122 convert filename according IOCHARSET mount option    //~vb2eI
//vb2d:160121 proper errmsg when fopen error by errno=22(Invalid argument)//~vb2cI
//vb2c:160120 (BUG)errno was changed by next fstat                 //~vb2cI
//vb28:160116 (BUG)display spilit utf8 by lineattr                 //~vb28I
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R
//vb04:150313 (BUG)dirlist path level is +3 by \\.\ ptrfix for reserved name when it is adir//~vb04I
//vaze:150112 expand MAXLINEDATA 9999 to 32760                     //~vazeI
//vawG:140621 compiler warning,set but unused                      //~vawGI
//vawD:140613 (W32:BUG)errmsg "GetShortPath failed" when device is not ready,it is not valid.//~vawDI
//vawd:140602 del reopen bkup when permission err(may be UAC protected)//~vawdI
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I
//vavD:140410 (W32UNICODE)setdbcstbl should chk UD                 //~vavDI
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI
//vak5:130816 compiler warning;set but not used                    //~vak5I
//vagv:120915 delete unused function; filesetdbcstblu              //+vagvI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vac5:120211 avoid dup find for network path err for UNC format   //~vac5I~
//vac4:120211 errmsg issued for dirlist path of UNC fmt            //~vac4I~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va7LI~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5t:100515 display filenamelist by dd fmt                       //~va5tI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            sub.c   :setdbcstbl for utf8file                     //~va20I~
//                    :restore tab for ddfmt                       //~va20I~
//va1F:091117 (BUG:LNX)on console avoid dbcs settin                //~va1FI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0i:090804 (BUG)split dbcstbl should be cleared even wgen repch="."//~va0iI~
//va0g:090724 on dirlist panel,DBCS input cause cursor jump by v78g(dirlocate)//~va0gI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//va04:090606 expand cmdbuff to include edit cmd for the file with _max_path//~va04I~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH;define MAXPARMSZ)//~va03I~
//v7as:090329 S390 support                                         //~v7asI~
//            sub.c(not KON but DBCS:euc case)                     //~v7asI~
//v7ak:081208 cause newfile if UNC name is netaddr only (missing share folder)//~v7akI~
//v7ac:081108 Japanese bit is to be reset by -C option             //~v7acI~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v7a8:081106 (LNX)dbcschk by eucchk for also EUC+UTF8             //~v7a8I~
//v7a1:081030 (W32:BUG)dbcs err on cmdline is not displayed        //~v7a1I~
//v79K:081020 (BUG:v77y)*\ miss last path when on dir list         //~v79KI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v77y:080118 *\/^* support for dos cmd                            //~v77yI~
//v775:071123*(FTP:BUG) dir open failed by permission -->new file  //~v775I~
//v76q:070703 (BUG*OS2/GCC)redirect filename is invalid(a.b.c fmt for ::#a.b)//~v76qI~
//v76p:070628 compare remote file support                          //~v76pI~
//v750:070416 split cmd;setdbcs when dbcs split by SBCS option     //~v750I~
//v74W:070407 split cmd bnds/margin support                        //~v74WI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v73z:070131 it would be better to sjis 2nd byte for also win/dos/os2 for the case disr list description display etc//~v73zI~
//v73x:070127 (AIX)coding only(not tested):englishmode should ignore sjis//~v73xI~
//v73v:070127 (BUG)tab dose not back to part of dbcs 2nd byte after prev byte is changed to dbcs 1st byte by (v)hex mode//~v73vI~
//v73q:070121*(BUG)for the line oom contain tab,after del omm contains imm data by shiftback//~v73qI~
//v73h:070114 (BUG)tab rep by hex mode dosen not delete expanded char//~v73hI~
//v731:061226*filesize>4GB support                                 //~v731I~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730R~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v711:060916 (BUG)invalid displey dirlist when ::\  (\ is not require)//~v711I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v70u:060902 (BUG)^*\.. stat at the directory(do not up to parent)//~v70uI~
//v70s:060826 gcc:submit cmd abend because ::#bat is not expand to .bat(getpid is supported by gcc)//~v70sI~
//v68m:060410 (BUG)^* fullpath generation is not valid for wildcard dir(ex path\*.c\fnm)//~v68mI~
//v636:050428 new workdir filename naming ::#((pid).xxx) for grep work filename//~v636I~
//v615:050212 keep root for over back for ^*\..\..\..\.....        //~v615I~
//v610:050207 change other pcw mode specification "*2"-->"!*"      //~v610I~
//v60y:050202 exe cmd *2 option(use other split screen file)       //~v60yI~
//v60d:050123 (LNX:BUG)mdos file tempfile copy fail by the reason of already exist//~v60dI~
//v57E:040610 (FTP)support filename of "*:xxxx" fmt                //~v57EI~
//v57D:040610 (FTP:UNX:BUG)root dirlist display dummy at 2nd line  //~v57DI~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v53X:031222 (WIN,UNX)ftp support;ROOTDIR determination           //~v53XI~
//v53h:030927 (LNX:BUG)sjis chk done for EUC under                 //~v53hI~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find","change"//~v49bI~
//v495:020617 dbcs chk over x208 for except unix                   //~v495I~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v47W:020413 ueucchk interface changed(len chnage consideration by hankaku^katakana)//~v47WI~
//v47H:020324 issue not "not found" but "not resolved " for  wild card path.//~v47HI~
//v47o:020313 change errmsg for wildcard invalid                   //~v47oR~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v45j:011211 (AIX)chk dbcs combination for hex display drop char bug//~v45jI~
//v456:011208 (BUG)next tab replaced by space when prev byte is changed to dbcs 1st char//~v456I~
//v44a:011202 (BUG)hex input replace another tab char to space     //~v44aI~
//v411:010728 AIX:allow display hankaku katakana                   //~v411I~
//v40B:010707 (BUG)rc to be chked(sigsegv)                         //~v40BI~
//v40A:010707 LINUX:mdir support                                   //~v40AI~
//v40w:010618 display unprintable for dbcs split by line width parm//~v40wI~
//v40u:010617 wild-card support for path name if dir contain only one member.//~v40uI~
//            (replace v143)                                       //~v40uI~
//v40s:010616 (BUG)LNX:not found msg when stat fail by slink loop  //~v40sI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v30f:010122 AIX support:rigid SJIS chk(jis X 208)                //~v30fI~
//v21o:010114 LINUX support:unprintable when sbcs>=80 for kon screen stability//~v21oI~
//v21n:010114 LINUX support:wordrep may dsetroy dbcs conbination   //~v21nI~
//v21m:010114 LINUX support:rigid euc chk to avoid screen destroy  //~v21mI~
//v19R:000927 LINUX support(func name on permission errmsg)        //~v19RI~
//v19L:000925 LINUX support(permission err msg for fopen)          //~v19LI~
//v19a:000903 LINUX support(dir path seperator)                    //~v194I~
//v194:000902 LINUX support(EISOPEN not defined)                   //~v194I~
//v13d:991023 *\ support for filecmd(save/repl/create/append/copy/move/ini)//~v13dI~
//v11I:990822 (BUG) fullpath err when file name is wild card with start *//~v11II~
//v10H:990417 (BUG)uerrmsg parm count chk by xuerpck               //~v10HI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//            for ex. find cmd,cid search.                         //~v0a1I~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//v09p:970519:already opened msg for os2                           //~v09pI~
//v095:970405:DPMI version                                         //~v095I~
//            -errno need errno.h(c6 has it in stdlib.h)           //~v095I~
//v08q:961201:edit partial file(continued from v08l)               //~v08qI~
//v085:961024:W95 VC                                               //~v085I~
//v07p:960714:(BUG)if workdir is root,"e ::" cause err "g: not found"//~v07pI~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v07lI~
//v07k:960713:(BUG)PATHLEN need chk dbcs 1st byte + '\' ex 噂(x895c)//~v07kI~
//v07h:960713:(BUG)"dbcs tbl 2nd byte flag set" destroy next malloc free chain//~v07hI~
//            when last byte is dbcs 1st byte if binary file read. //~v07hI~
//            It cause hung up by malloc chain fail.               //~v07hI~
//v076:960608:getfldpos abend(chl pfl exist)                       //~v076I~
//v05O:960120:copy/move cmd *\(same as source) / **\(parent of source) support//~v05OR~
//v047:950924:file output err(disk full)->close err/reopen err  //~v047I~
//v040:950916:fullpath for :: only(drop last \)                 //~v040I~
//v03i:950813:bug,wild card become new file when no file exist  //~v03iI~
//v03b:950730:zenkaku err msg for lineno,scroll fld etc         //~v03bI~
//v039:950728:bug,setflddata need set dbcstbl also              //~v039I~
//v036:950722:bug when dir proc \(root)                         //~v036I~
//            DosFindFirst return no more file for \(root)      //~v036I~
//            and need accept \. ..\ etc(dir chk after fullpath,//~v036I~
//            fullpath set g:-->g:\  g:.-->g:\    //               //~v540R~
//*v032:950712:UFLD for each ppc                                //~v032I~
//*v020:950611:dir support(prot fld flag)                       //~5611I~
//*    :950616:dir support(return UFLD ptr)                     //~v020I~
//************************************************************* //~5611I~
//*950423 dbcs 2nd byte no prot chk for file line area scroll   //~5423R~
//*950102 tab display by space for screen print                 //~5423I~
//************************************************************* //~5102I~
#include <time.h>
#include <stdio.h>
#ifdef UTF8UCS2                                                    //~va20I~
#include <stddef.h>                                                //~va20I~
#endif                                                             //~va20I~
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
    #ifdef DPMI                 //DPMI version                     //~v095I~
        #include <errno.h>                                         //~v095I~
    #else                       //not DPMI                         //~v095I~
    #endif                      //DPMI or not                      //~v095I~
#else
    #ifdef W32                                                     //~v085I~
        #include <dos.h>                                           //~v085I~
//      #include <error.h>                                         //~v085I~//~v7akR~
        #include <winerror.h>                                      //~v7akI~
        #include <windows.h>                                       //~v085I~//~v7akR~//~vaw1R
    #else                                                          //~v085I~
//      #include <errno.h>                                         //~v717R~
    #define INCL_BASE
    #include <os2.h>
    #endif                                                         //~v085I~
#endif
#include <errno.h>                                                 //~v716I~
#ifdef UNX                                                         //~vaa0I~
	#include <dirent.h>                                            //~vaa0I~
#endif                                                             //~vaa0I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <udbcschk.h>
#include <ustring.h>                                            //~5224I~
#include <ufile.h>                                              //~5318I~
#ifdef UNX                                                         //~vaa0I~
	#include <ufile1l.h>                                           //~vaa0I~
#endif                                                             //~vaa0I~
#include <ufile2.h>                                                //~v48cI~
#include <ufile3.h>                                                //~v48cI~
#include <ufile4.h>                                                //~v48cI~
#include <ufile5.h>     //filetouch                                //~v48cI~//~vb89I
#include <ufemsg.h>                                                //~v19LI~
#include <ualloc.h>                                                //~v76pI~
#include <ucvebc.h>                                                //~va7LI~
#ifdef FTPSUPP                                                     //~v70zI~
	#include <uftp.h>                                              //~v70zR~
	#include <u3270.h>                                             //~v70zI~
#endif                                                             //~v70zI~
#include <uproc2.h>                                                //~v636I~
#include <utrace.h>                                                //~v711I~
#include <ufilew.h>                                                //~v711I~//~vavDI
#include <ustring.h>                                                //~v711I~//~vb4hI
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"                                              //~5118R~
#include "xepan.h"                                              //~5318R~
                                                                   //~v40uI~
                                                                   //~v40uI~
#include "xeerr.h"                                              //~v03bI~
#include "xegbl.h"                                                 //~v21mI~
#include "xefile.h"                                                //~v60yI~
#include "xedir.h"                                                 //~v717I~
#ifdef FTPSUPP                                                     //~v70zI~
	#include "xeftp.h"                                             //~v76pI~
	#include "xetso.h"                                           //~v70zI~
#endif                                                             //~v70zI~
#define XESUB_GBL                                                  //~v74xM~
#include "xesub.h"                                                 //~v74xM~
#include "xesub2.h"                                                //~va1cR~
#include "xefunc.h"                                                //~v76pI~
#include "xedcmd.h"                                                //~v76pI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeutf.h"                                             //~v76pI~//~va00I~
	#include "xepan22.h"                                           //~va00I~
	#include "xechar12.h"                                          //~va00I~
#endif                                                             //~v70zI~//~va00I~
#include "xeebc.h"                                                 //~va50I~
#include "xefcmd7.h"                                               //~va50I~//~vba2I
//*******************************************************
#ifndef AIX                                                        //~v45jR~
static UCHAR Sdbcsid[2]={DBCS1STCHAR,DBCS2NDCHAR};                 //~v09YI~
#endif                                                             //~v456I~
static UQUEH Ssubtempfnq;           //temp filename que to be deleted at end of session//~v76pR~
//*******************************************************          //~v60yI~
//*******************************************************          //~va1cR~
int filefullpath2ndedit(char *Pfullpath,PUFILEH Ppfh,char *Pmodifier);//~v60yI~
//*******************************************************       //~5318M~
//*file find                                                    //~5318M~
//* parm1:filename                                              //~5318M~
//* parm2:output fullpath area(option,if null filename must fullpath)//~v036R~
//* parm3:output fstat3 area(option)                            //~5318M~
//* parm4:option to output errmsg 0:err msg 1:bypass not found msg//~5513I~
//* retrn:rc 0:found, 4:not found, 8:path not found, 12:fullpath err//~5318M~
//*          16:it is dir 20:wildcard                           //~5625I~
//*          32:remote err                                         //~v716I~
//*          64:wildname multiple                                  //~vaa0I~
//*******************************************************       //~5318M~
int filefind(UCHAR *Ppfile,UCHAR *Pfullpath,FILEFINDBUF3 *Ppfstat3,//~5513R~
             int Pmsgopt)                                       //~5513I~
{                                                               //~5318M~
    FILEFINDBUF3 fstat3;                                        //~5318M~
    FILEFINDBUF3 *pfstat3;                                      //~5318M~
    UCHAR *filename;                                            //~5318M~
    int rc,rootsw=0;                                            //~v036R~
#ifdef FTPSUPP                                                     //~v53XI~
    int hostnmlen;                                                 //~v53XI~
    PUFTPHOST puftph;                                              //~v716I~
#endif                                                             //~v53XR~
#ifdef UNX                                                         //~vaa0I~
	int swwildname;                                                //~vaa0I~
#endif                                                             //~vaa0I~
//****************************                                  //~5318M~
    if (Pfullpath)      //fullpath required                     //~5318M~
    {                                                           //~5318M~
        if (!filefullpath(Pfullpath,Ppfile,_MAX_PATH))//fullpath name//~5318M~
            return 12;                                          //~5318M~
        filename=Pfullpath;                                     //~5318M~
    }                                                           //~5318M~
    else                                                        //~5318M~
        filename=Ppfile;                                        //~5318M~
#ifdef FTPSUPP                                                     //~v53XI~
//  if (hostnmlen=uftpisremote(filename,0),hostnmlen)              //~v716R~
    if (hostnmlen=uftpisremote(filename,&puftph),hostnmlen)        //~v716I~
    {                                                              //~v53XI~
    	if (FTP_ROOTDIR(filename+hostnmlen+1))                     //~v53XI~
	        rootsw=1;                                              //~v53XI~
    }                                                              //~v53XI~
    else                                                           //~v53XI~
#endif                                                             //~v53XI~
//  if (!strcmp(filename+1,":\\"))  //root                         //~v194R~
//  if (ROOTDIR(filename+1))  //root                               //~v40bR~
    if (ROOTDIR2(filename))  //root                                //~v40AR~
        rootsw=1;                                               //~v036I~
    if (!(pfstat3=Ppfstat3))                                    //~5318M~
        pfstat3=&fstat3;                                        //~5318M~
#ifdef UNX                                                         //~vaa0I~
    swwildname=0;                                                  //~vaa0I~
#endif                                                             //~vaa0I~
    if (strpbrk(filename,"*?")) //wild card                     //~v03iM~
    {                                                           //~v03iM~
#ifdef UNX                                                         //~vaa0I~
	  if (!hostnmlen && !ufstat_wild(filename,pfstat3)) //exist the local wildcard filename//~vaa0R~
      {                                                            //~vaa0I~
      	if (pfstat3->attrFile & FILE_WILDNAME_MULTIPLE)            //~vaa0I~
        	swwildname=2;	//err                                  //~vaa0I~
        else                                                       //~vaa0I~
	      	swwildname=1;	//allow access                         //~vaa0R~
      }                                                            //~vaa0I~
      else                                                         //~vaa0I~
#endif                                                             //~vaa0I~
      {                                                            //~vaa0I~
        if (!(Pmsgopt & FFNODIRMSG))                            //~v03iM~
//          uerrmsg("wild card is invalid",                        //~v47oR~
//                  "ワイルドカードは無効です");                   //~v47oR~
            uerrmsg("wild card is not resolved",                   //~v47oR~
                    "ワイルドカードが解決できません");             //~v47oR~
        return 20;              //wild card                     //~v03iM~
      }                                                            //~vaa0I~
    }                                                           //~v03iM~
//  if (rc=(int)ufstat(filename,pfstat3),rc)        //not found //~5318M~//~v7akR~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7akI~
    if (Pmsgopt & FFNORPATHER)                                     //~v7akI~
        Gufile_opt|=GFILEOPT_IGN_UNCPATHERR; //ignore UNC fmt path err msg//~v7akI~
#endif                                                             //~v7akI~
#ifdef UNX                                                         //~vaa0I~
  if (swwildname) //exist the wildcard filename                    //~vaa0R~
  {                                                                //~vaa0I~
  	if (swwildname==2)                                             //~vaa0I~
    {                                                              //~vaa0I~
		errwildnamemultiple(0,filename);                           //~vaa0R~
    	return 64;                                                 //~vaa0R~
    }                                                              //~vaa0I~
  	rc=0;                                                          //~vaa0R~
  }                                                                //~vaa0I~
  else                                                             //~vaa0I~
#endif                                                             //~vaa0I~
    rc=(int)ufstat(filename,pfstat3);       //not found            //~v7akI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7akI~
    Gufile_opt&=~GFILEOPT_IGN_UNCPATHERR; //ignore UNC fmt path err msg//~v7akI~
#endif                                                             //~v7akI~
    if (rc)        //not found                                     //~v7akI~
    {                                                           //~5318M~
        if (rc==ERROR_PATH_NOT_FOUND)                           //~5318M~
        {                                                       //~5318M~
//          uerrmsg("%s,invalid path",                          //~5318M~//~vb7nR
//                  "%s のパスが見つかりません",filename);      //~5318M~//~vb7nR
			ufilepatherr(filename,8);                              //~vb7nR
            return 8;                                           //~5318M~
        }                                                       //~5318M~
#ifdef W32                                                         //~vawDI
        if (rc==ERROR_NOT_READY)                                   //~vawDI
        {                                                          //~vawDI
        	return 8;	//errmsg is issued at ufstat               //~vawDR
        }                                                          //~vawDI
#endif                                                             //~vawDI
//#ifdef WINREMOTESUPP     //\\xxx\yy support                      //~vac5R~
//        if (isRootUNC(0,filename))                               //~vac5R~
//            pfstat3->attrFile |=FILE_DIRECTORY;  //directory     //~vac5R~
//        else                                                     //~vac5R~
//#endif                                                           //~vac5R~
        if (rootsw)                                             //~v036M~
            pfstat3->attrFile |=FILE_DIRECTORY;  //directory    //~v036M~
        else                                                    //~v036M~
        {                                                       //~v036I~
#ifdef FTPSUPP                                                     //~v716M~
		if (UFTPHISTSO(puftph))                                    //~v716M~
        {                                                          //~v775I~
	        if (rc!=ENOENT)                                        //~v716M~
    	        return 32;     //dirplay response msg from xe3270  //~v716M~
        }                                                          //~v775I~
        else                                                       //~v775I~
		if (hostnmlen) //remote file                               //~v775I~
        {                                                          //~v775I~
        	if (rc!=ENOENT&&rc!=ENOTDIR)                           //~v775I~
    	        return 32;     //dirplay response msg from ftfstat //~v775I~
        }                                                          //~v775I~
#endif                                                             //~v716M~
#ifdef UNX                                                         //~v40sI~
        if (rc!=ENOENT&&rc!=ENOTDIR)                               //~v40sR~
            return rc;                                             //~v40sI~
#endif                                                             //~v40sM~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7akI~
        if (rc==ERROR_INVALID_NAME   //no folder name for UNC fmt  //~v7akR~
        ||  rc==ERROR_BAD_NETPATH    //servername err              //~vac5I~
        ||  rc==ERROR_LOGON_FAILURE) //password protected          //~v7akI~
    	    return 32;     //dirplay response msg from ftfstat     //~v7akI~
#endif                                                             //~v7akI~
		rc=errno;                                                  //~vb7qR
        if (rc==ENAMETOOLONG)                                      //~vb7qI
    	    return 32;     //not not found                         //~vb7qR
        if (!(Pmsgopt & FFNONFMSG))                             //~5625R~
//          uerrmsg("%s is not found",                          //~5513R~//~vb7nR
//                  "%s が見つかりません",filename);            //~5513R~//~vb7nR
			ufilenotfound(filename,4);                             //~vb7nI
            return 4;                                           //~v036R~
        }                                                       //~v036I~
    }                                                           //~5318M~
    if (pfstat3->attrFile & FILE_DIRECTORY)  //directory        //~5625I~
    {                                                           //~5625I~
        if (!(Pmsgopt & FFNODIRMSG))                            //~5625I~
            uerrmsg("%s is directory",                          //~5625R~
                    "%s はディレクトリーです",filename);        //~5625R~
        return 16;                                              //~5625I~
    }                                                           //~5625I~
                                                                //~5625I~
    return 0;                                                   //~5318M~
}//filefind                                                     //~5318M~
                                                                //~5318M~
//*******************************************************       //~5625I~
//*filedirchk                                                   //~5625I~
//* chk dirname and wild card                                   //~5625I~
//* parm1:filename(fullpath name)                                  //~v13dR~
//* retrn:rc 0:not dir,1:dir,2:dir+wildcard,-1:err              //~5625I~
//*******************************************************       //~5625I~
int filedirchk(UCHAR *Pfilename)                                //~5625I~
{                                                               //~5625I~
//  UCHAR  fullpath[_MAX_PATH];                                    //~v13dR~
    int rc;                                                     //~v036I~
//****************************                                  //~5625I~
//  rc=filefind(Pfilename,fullpath,0,FFNONFMSG|FFNODIRMSG);//no fstat//~v13dR~
    rc=filefind(Pfilename,0,0,FFNONFMSG|FFNODIRMSG);//no fullpath,no fstat//~v13dR~
    switch(rc)                                                  //~v036I~
    {                                                           //~v036I~
    case  0:                                                    //~v036I~
        break;                                                  //~v036I~
    case 16:    //dir                                           //~v036I~
        rc=1;                                                   //~v036I~
        break;                                                  //~v036I~
    case 20:    //wild card                                     //~v036I~
        rc=2;                                                   //~v036I~
        break;                                                  //~v036I~
    case 32:    //remote err                                       //~v716I~
        rc=-2;	//not dir                                          //~v716I~
        break;                                                     //~v716I~
    case 8:    //path not found,device not ready                                 //~v716I~//~vawDR
        rc=-2;	//error                                            //~vawDI
        break;                                                     //~v716I~//~vawDI
    default:                                                    //~v036I~
        rc=-1;                                                  //~v036I~
    }                                                           //~v036I~
    return rc;                                                  //~v036R~
}//filedirchk                                                   //~5625I~
                                                                //~5625I~
//*******************************************************
//*file open
//*******************************************************
FILE *fileopen(UCHAR *Ppfile,UCHAR *Ppopt)
{
    FILE *fh;
    FILEFINDBUF3 fstat3;                                           //~v08qI~
    char *pc;                                                      //~v08qI~
    int rc;                                                        //~vawdI
//****************************
UTRACEP("fileopen:%s\n",Ppfile);                                   //~v711I~
    if (!(fh=fopen(Ppfile,Ppopt)))
    {                                                              //~v08qI~
        rc=errno;                                                  //~vawdI
      if (rc==EINVAL) //invalid argumen                            //~vb2dR
      {                                                            //~vb2dR
		ufileopenerrInvalidargument(0,rc/*return code*/,Ppfile);   //~vb2dI
      }                                                            //~vb2dR
      else                                                         //~vb2dR
      {                                                            //~vb2dR
#ifdef UNX                                                         //~v19LI~
//    if (errno==EACCES)                                           //~v19LI~//~vawGR
      if (rc==EACCES)                                           //~v19LI~//~vawGI
        ufilenopermission("fopen",Ppfile,errno);	               //~v19RR~
      else                                                         //~v731I~
      if (errno==EFBIG)                                            //~v731I~
        uerrmsg("%s Open fail(errno=%d:too big)",                  //~v731R~
                "%s Open fail(errno=%d:ファイルが大きすぎます)",   //~v731R~
                Ppfile,errno);                                     //~v731I~
      else                                                         //~v19LI~
      {                                                            //~v19LI~
#else  //!UNX                                                      //~v19LI~
#endif //!UNX                                                      //~v19LI~
        if (!ufstat(Ppfile,&fstat3)                                //~v08qI~
        && fstat3.attrFile & FILE_READONLY)                        //~v08qI~
            pc=",ReadOnly";                                        //~v08qI~
        else                                                       //~v08qI~
    #ifdef W32                                                     //~v09pI~//~vawdI
//      if (rc=EACCES)                                           //~v19LI~//~vawdI//~vb2OR
        if (rc==EACCES)                                           //~v19LI~//~vb2OI
            pc=",Permission";                                        //~v08qI~//~vawdI
        else                                                       //~vawdI
    #endif                                                         //~vawdI
            pc="";                                                 //~v08qI~
#ifdef UNX                                                         //~v194I~
#else                                                              //~v194I~
#ifdef DOS                                                         //~v09pI~
#else                                                              //~v09pI~
    #ifdef W32                                                     //~v09pI~
    #else                                                          //~v09pI~
        if (errno==EISOPEN) //open by other                        //~v09pI~
            uerrmsg("%s(\"%s\") is already opened on other session",//~v09pI~
                    "%s(\"%s\") は他でオープン中",Ppfile,Ppopt);   //~v09pI~
        else                                                       //~v09pI~
    #endif                                                         //~v09pI~
#endif                                                             //~v09pI~
#endif                                                             //~v194I~
//      uerrmsg("%s(\"%s\") Open failed(errno=%d)%s",              //~v08qR~//~vb2cR
        uerrmsg("%s(\"%s\") Open failed(errno=%d:%s)%s",           //~v08qR~//~vb2cI
//              "%s(\"%s\") オープンエラー(errno=%d)%s",Ppfile,Ppopt,errno,pc);//~v08qR~//~vb2cR
                "%s(\"%s\") オープンエラー(errno=%d:%s)%s",Ppfile,Ppopt,rc,strerror(rc),pc);//~v08qR~//~vb2cR
#ifdef UNX                                                         //~v19LI~
      }//EACCES                                                    //~v19LI~
#else  //!UNX                                                      //~v19LI~
#endif //!UNX                                                      //~v19LI~
      }//!EINVAL                                                   //~vb2dR
    }                                                              //~v08qI~
    return fh;
}//fileopen
//*******************************************************          //~vb89I
//*file open,if not found create is                                //~vb89I
//*******************************************************          //~vb89I
FILE *fileopencreate(int Popt,UCHAR *Ppfile,UCHAR *Ppopt,UCHAR *Pdummyrecord)//~vb89R
{                                                                  //~vb89I
    FILE *fh;                                                      //~vb89I
    int rc;                                                        //~vb89I
//****************************                                     //~vb89I
    fh=fopen(Ppfile,Ppopt);                                        //~vb89I
    rc=errno;                                                      //~vb89I
	UTRACEP("%s:fh=%p,errno=%d,%s\n",UTT,fh,rc,Ppfile);                                   //~v711I~//~vb89I
    if (!fh)                                                       //~vb89R
    {                                                              //~v08qI~//~vb89I
      	if (rc==ENOENT)                                            //~vb89I
        {                                                          //~vb89I
        	rc=filetouch(0,Ppfile,Pdummyrecord);                   //~vb89I
            if (!rc)                                               //~vb89I
            {                                                      //~vb89I
		    	fh=fopen(Ppfile,Ppopt);                            //~vb89I
			    rc=errno;                                          //~vb89I
                if (fh)                                            //~vb89I
		        	uerrmsgcat(";%s:Dummy file was created",           //~v08qR~//~vb89R
        		    	    ";%s:ダミーファイルを作成しました",    //~vb89R
							Ppfile);//~v08qR~                      //~vb89I
                else                                               //~vb89I
		        	uerrmsgcat(";%s:(Dummy file) Open failed(errno=%d:%s)",           //~v08qR~//~vb89R
        		    	    ";%s:作成したダミーファイルのオープンエラー(errno=%d:%s)",//~vb89R
							Ppfile,rc,strerror(rc));//~v08qR~      //~vb89I
            }                                                      //~vb89I
            else                                                   //~vb89I
		    	uerrmsgcat(";%s: Dummy file Open failed(errno=%d:%s)",           //~v08qR~//~vb89R
        		    	    ";%s:ダミーファイルを作成に失敗(errno=%d:%s)",//~vb89R
							Ppfile,rc,strerror(rc));//~v08qR~      //~vb89I
        }                                                          //~vb89I
        else                                                       //~vb89I
        	uerrmsgcat(";%s(\"%s\") Open failed(errno=%d:%s)",           //~v08qR~//~vb89R
            	    ";%s(\"%s\") オープンエラー(errno=%d:%s)",Ppfile,Ppopt,rc,strerror(rc));//~v08qR~//~vb89R
    }                                                              //~v08qI~//~vb89I
    if (Popt & FOCO_CLOSE)                                         //~vb89I
    {                                                              //~vb89I
        if (fh)                                                    //~vb89I
        {                                                          //~vb89I
	    	fclose(fh);                                            //~vb89R
        	fh=0;                                                  //~vb89R
        }                                                          //~vb89I
    }                                                              //~vb89I
    return fh;                                                     //~vb89I
}//fileopencreate                                                  //~vb89I

#ifdef UNX                                                         //~v48cI~
//*******************************************************          //~v48cI~
//*file open for mdos disk(open temp file and copy mdos file)      //~v48cI~
//*parm1:mdos filename                                             //~v48cI~
//*parm2:open option                                               //~v48cI~
//*parm3:new file sw(no copy mdos disk)                            //~v48cI~
//*parm4:output tempfname                                          //~v48cI~
//*ret  :temp file fh                                              //~v48cI~
//*******************************************************          //~v48cI~
FILE *fileopen_mdostemp(UCHAR *Ppfile,UCHAR *Ppopt,int Pnewsw,UCHAR *Pmdostempfnm)//~v48cR~
{                                                                  //~v48cI~
    FILE *fh;                                                      //~v48cI~
//****************************                                     //~v48cI~
    utempnam("/tmp","xemd_",Pmdostempfnm);                         //~v48cR~
    if (!Pnewsw)                                                   //~v48cI~
#ifdef LNX                                                         //~v60dI~
	    if (uxcopy(Ppfile,Pmdostempfnm,DCPY_EXISTING,FILE_ALL))//tempnam create temp file//~v60dI~
#else                                                              //~v60dI~
	    if (uxcopy(Ppfile,Pmdostempfnm,0,FILE_ALL))                //~v48cR~
#endif                                                             //~v60dI~
    	    return 0;                                              //~v48cR~
    if (!(fh=fopen(Pmdostempfnm,Ppopt)))                           //~v48cR~
        uerrmsg("%s(temp of %s) Open(\"%s\") failed.(errno=%d)",   //~v48cI~
                "%s(temp of %s)オープン(\"%s\")エラー(errno=%d)",  //~v48cI~
				Pmdostempfnm,Ppfile,Ppopt,errno);                  //~v48cR~
    return fh;                                                     //~v48cI~
}//fileopen_mdostemp                                               //~v48cI~
#endif                                                             //~v48cI~
//*******************************************************
//*file close
//*parm1:filename
//*parm2:FILE*
//*return:rc                                                    //~v047R~
//*******************************************************
int fileclose(UCHAR *Pfile,FILE* Pfh)                           //~v047R~
{
//****************************
    if (fclose(Pfh))
    {                                                           //~v047I~
        uerrmsg("%s Close failed,rc=%d",                           //~v08qR~
                    "%s クローズ エラー,rc=%d",                    //~v08qR~
                    Pfile,errno);                                  //~v08qR~
        return 4;                                               //~v047I~
    }                                                           //~v047I~
    return 0;                                                   //~v047R~
}//fileclose
#ifdef UNX                                                         //~v48cI~
//*******************************************************          //~v48cI~
//*file copy back to mdos dis after close                          //~v48cI~
//*parm1:mdos filename                                             //~v48cI~
//*parm2:temp file                                                 //~v48cI~
//*return:rc                                                       //~v48cI~
//*******************************************************          //~v48cI~
int fileclose_mdos(UCHAR *Pmdosfile,UCHAR *Ptempfile)              //~v48cI~
{                                                                  //~v48cI~
    int procctr,rc;                                                //~v48cI~
//****************************                                     //~v48cI~
	if (rc=uxcopy(Ptempfile,Pmdosfile,DCPY_EXISTING,FILE_ALL),rc)  //~v48cR~
    {                                                              //~v48cI~
        uerrmsg("mdos file %s copy back failed(saved in %s),rc=%d",//~v48cR~
                "disket ファイル %s の書き戻し失敗、(%sで保存)、rc=%d",//~v48cI~
                    Pmdosfile,Ptempfile,rc);                       //~v48cR~
        return 4;                                                  //~v48cI~
    }                                                              //~v48cI~
	rc=uxdelete(Ptempfile,FILE_NORMAL,UXDELNOMSG,                  //~v48cI~
						&procctr,&procctr,&procctr);//source file  //~v48cI~
    return rc;                                                     //~v48cI~
}//fileclose_mdos                                                  //~v48cI~
#endif                                                             //~v48cI~
//*******************************************************          //~v10rI~
//*count lineno of file                                            //~v10rI~
//*parm1:option                                                    //~v10rI~
//*parm2:filename                                                  //~v10rI~
//*parm3:output lineno fld                                         //~v10rI~
//*ret  :rc:4:fullpath err,8:open er                               //~v10rI~
//*******************************************************          //~v10rI~
int subgetfilelc(int Popt,UCHAR *Ppfnm,ULONG *Pplinecnt)           //~v10rI~
{                                                                  //~v10rI~
    FILE *fh;                                                      //~v10rI~
    char *fn,fpath[_MAX_PATH];                                     //~v57DR~
    ULONG lc=0,*pul,chkval=0xf10e87d3;                             //~v10rR~
    int rc;                                                        //~v10rI~
//****************************                                     //~v10rI~
    fn=Ppfnm;                                                      //~v10rI~
    if (!(Popt & GETLC_FPATHINP))                                  //~v10rI~
        if (!(fn=filefullpath(fpath,fn,sizeof(fpath))))            //~v57DR~
            return 4;                                              //~v10rI~
    if (!(fh=fileopen(fn,"r")))                                    //~v10rR~
        return 8;                                                  //~v10rI~
//  pul=(ULONG*)(void*)(Gfilebuff+MAXLINEDATA-5);                  //~v10rR~//~vazeR
    pul=(ULONG*)(void*)(Gfilebuff+MAXLINEDATA-sizeof(ULONG)-1);                  //~v10rR~//~vazeI
    *pul=chkval;                                                   //~v10rR~
    while (fgets(Gfilebuff,MAXLINEDATA,fh))                        //~v10rI~
    {                                                              //~v10rI~
        if (*pul==chkval)   //not overrided,crlf may detected      //~v10rR~
            lc++;                                                  //~v10rM~
        else                //long rec                             //~v10rI~
            *pul=chkval;                                           //~v10rR~
    }                                                              //~v10rI~
    if (ferror(fh))                                                //~v10rI~
    {                                                              //~v10rI~
        uerrapi1("fgets",fn,errno);                                //~v10rI~
        rc=12;                                                     //~v10rI~
    }                                                              //~v10rI~
    else                                                           //~v10rI~
        rc=0;                                                      //~v10rI~
    fileclose(fn,fh);                                              //~v10rI~
    *Pplinecnt=lc;                                                 //~v10rI~
    return rc;                                                     //~v10rI~
}//subgetfilelc                                                    //~v10rI~
//*******************************************************          //~v76pI~
//*all fullpath function                                           //~v76pI~
//* .resolve wild path                                             //~v76pI~
//* .resolve *\,**\,^*\,::                                         //~v76pI~
//* .copy remote file to local                                     //~v76pI~
//* pcw:optional parm to resolve "*\" , "**\"                      //~v76pR~
//* fullpath    :optional output fullpath                          //~v76pI~
//* fullpathtemp:optional;input tempfile patern,output:local copy of remote file//~v76pI~
//*return:rc,1:remote is dir for localcopy req                     //~v76pR~
//*******************************************************          //~v76pI~
int filefullpatha(int Popt,PUCLIENTWE Ppcw,char* Pfnm,char *Plocalfnm,char *Pfpath,char *Pfpathlocal)//~v76pI~
{                                                                  //~v76pI~
	char fpathwk[_MAX_PATH],*pc;                                   //~v76pI~
	char fpathwk2[_MAX_PATH],*pfnm;                                //~v76pI~
    int opt=0,len;                                              //~v76pR~
#ifdef FTPSUPP                                                     //~v76pI~
    int hostnmlen,optrcp=0,dirsw,rc;                                  //~v76pR~
    PUFTPHOST puftph;                                              //~v76pI~
	char fpathlocal[_MAX_PATH];                                    //~v76pI~
#endif                                                             //~v76pI~
//***************************                                      //~v76pI~
    if (Popt & FFPA_WILDPATH)                                      //~v76pI~
		opt|=XESUB_GBLOPT_WILDPATH;                                //~v76pI~
    if (Popt & FFPA_WILDMEMB)                                      //~v76pI~
		opt|=XESUB_GBLOPT_WILDMEMB;                                //~v76pI~
    pfnm=Pfnm;                                                     //~v76pI~
    if (*pfnm=='"')                                                //~v76pI~
    {                                                              //~v76pI~
    	len=(int)strlen(pfnm+1);                                        //~v76pI~
        len--;                                                     //~v76pI~
    	memcpy(fpathwk2,pfnm+1,(UINT)len);                         //~v76pI~
        *(fpathwk2+len)=0;                                         //~v76pI~
        pfnm=fpathwk2;                                             //~v76pI~
    }                                                              //~v76pI~
	Gsubgblopt|=opt;                                               //~v76pI~
    if (Ppcw)	//*\,**\ is resolvable                             //~v76pI~
		pc=dcmdfullpath(Ppcw,fpathwk,pfnm);	    //call filefullpath2 after "*" process//~v76pR~
    else                                                           //~v76pI~
		pc=filefullpath(fpathwk,pfnm,_MAX_PATH); //resolve ^*\ and :://~v76pR~
	Gsubgblopt&=~opt;                                              //~v76pI~
    if (!pc)                                                       //~v76pI~
    	return 4;                                                  //~v76pI~
    if (Pfpath)                                                    //~v76pI~
        strncpy(Pfpath,fpathwk,_MAX_PATH);                         //~v76pI~
    if (Pfpathlocal)                                               //~v76pI~
        strncpy(Pfpathlocal,fpathwk,_MAX_PATH); //if local,set also//~v76pI~
#ifdef FTPSUPP                                                     //~v76pI~
    if (Popt & FFPA_LOCALCOPYIFREMOTEFILE)	//remote attr chk required//~v76pR~
    {                                                              //~v76pI~
        if (hostnmlen=uftpisremote(pc,&puftph),hostnmlen)//remote  //~v76pR~
        {                                                          //~v76pI~
        	if (Popt & FFPA_REMOTEDIR)                             //~v76pI~
            	dirsw=1;                                           //~v76pI~
            else                                                   //~v76pI~
        	if (Popt & FFPA_REMOTEFILE)                            //~v76pI~
            	dirsw=0;                                           //~v76pI~
            else                                                   //~v76pI~
            {                                                      //~v76pI~
            	dirsw=0;                                           //~v76pI~
                optrcp|=XEFTP_GRC_CHKNORMAL;	//chk remote file is normal file//~v76pI~
            }                                                      //~v76pI~
        	if (dirsw)                                             //~v76pI~
            	return 1;                                          //~v76pI~
            if (Plocalfnm)                                         //~v76pI~
                filefullpatha(Popt,Ppcw,Plocalfnm,0,fpathlocal,0); //~v76pI~
            else                                                   //~v76pI~
            {                                                      //~v76pI~
			    if (Popt & FFPA_FULLPATHTEMP)                      //~v76pI~
    	            optrcp|=XEFTP_GRC_DEFDIR2;                     //~v76pI~
                else                                               //~v76pI~
    	            optrcp|=XEFTP_GRC_DEFDIR;                      //~v76pI~
            }                                                      //~v76pI~
//          rc=xeftpgetremotecopy(optrcp,pc,puftph,fpathlocal);    //~v8@sR~
//          rc=xeftpgetremotecopy(optrcp|XEFTP_GRC_FPATH,pc,puftph,fpathlocal,pc);//~v8@sR~//~vb7eR
            rc=xeftpgetremotecopy(optrcp|XEFTP_GRC_FPATH,pc,puftph,fpathlocal,sizeof(fpathlocal),pc);//~v8@sR~//~vb7eI
            if (rc)                                                //~v76pI~
                return 4;                                          //~v76pR~
			subsavetempfnm(fpathlocal,0);//save file name to be deleted at end of session//~v76pI~
            if (Pfpathlocal)                                       //~v76pI~
                strncpy(Pfpathlocal,fpathlocal,_MAX_PATH);         //~v76pI~
        }                                                          //~v76pI~
    }                                                              //~v76pI~
#endif                                                             //~v76pI~
    return 0;                                                      //~v76pI~
}//filefullpatha                                                   //~v76pI~
//*******************************************************       //~5318M~//~vba2I
//*chek shortpath prefix                                           //~vba2I
//*******************************************************       //~5318M~//~vba2I
int isShortpath(int Popt,char *Ppfnm,char *Ppfpath,size_t Pbuffsz) //~vba2I
{                                                                  //~vba2I
	char *ppath,*pc;                                               //~vba2R
	int namelen,pathlen;                                           //~vba2R
	int namelen2;                                                  //~vba2I
    char fpath[_MAX_PATH];                                         //+vba2R
    char name[_MAX_PATH];                                          //+vba2R
//**********************                                           //~vba2I
    pc=strchr(Ppfnm,DIR_SEPC);                                     //~vba2R
    if (pc)                                                        //~vba2I
    	namelen=PTRDIFF(pc,Ppfnm);                                 //~vba2I
    else                                                           //~vba2I
    	namelen=(int)strlen(Ppfnm);                                //+vba2R
#ifdef W32                                                         //~vba2I
    pc=strchr(Ppfnm,FTP_DIR_SEPC);                                 //~vba2R
    if (pc)                                                        //~vba2I
    	namelen2=PTRDIFF(pc,Ppfnm);                                //~vba2I
    else                                                           //~vba2I
    	namelen2=strlen(Ppfnm);                                    //~vba2I
    if (namelen2<namelen)                                          //~vba2I
    	namelen=namelen2;                                          //~vba2I
#endif                                                             //~vba2I
	if (namelen>=(int)sizeof(fpath))                               //~vba2I
    	return 4;                                                  //~vba2I
    UmemcpyZ(name,Ppfnm,(size_t)namelen);                          //~vba2R
    ppath=funcsp_search(0,name);                                   //~vba2R
    if (!ppath)                                                    //~vba2R
    	return 4;                                                  //~vba2I
    pathlen=(int)strlen(ppath);                                    //~vba2I
    namelen2=(int)strlen(Ppfnm)-namelen;                           //~vba2I
//  if (pathlen+namelen2+1>Pbuffsz)                                //~vba2R//~vba4R
    if (pathlen+namelen2+1>(int)Pbuffsz)                           //~vba4I
    	return 8;                                                  //~vba2I
    strcpy(Ppfpath,ppath);                                         //~vba2R
    strcat(Ppfpath,Ppfnm+namelen);                                 //~vba2I
    return 0;                                                      //~vba2I
}//isShortpath                                                     //~vba2I
////*******************************************************       //~5318M~//~vba2R
////*chek curent pcw                                               //~vba2R
////*******************************************************       //~5318M~//~vba2R
//PUFILEH getCurrentPfh(int Popt)                                  //~vba2R
//{                                                                //~vba2R
//    PUCLIENTWE pcw;                                              //~vba2R
////**********************                                         //~vba2R
//    pcw=scrgetcw(0);    //curent pcw                             //~vba2R
//    if (pcw && (pcw->UCWtype==UCWTFILE || pcw->UCWtype==UCWTDIR))//~v60yI~//~vba2R
//    {                                                            //~vba2R
//        return (PUFILEH)UGETPFHFROMPCW(pcw);                          //~v60yI~//~vba2R
//    }                                                            //~vba2R
//    return 0;                                                    //~vba2R
//}//getCurrentPfh                                                 //~vba2R
//*******************************************************       //~5318M~//~vba2R
char *filefullpathsp(int Popt,char *Pfullpath,char *Pfilename,size_t Plen) //~5318M~//~vba2R
{                                                               //~5318M~//~vba2I
//    PUFILEH pfh;                                                 //~vba2R
//    char *pfnm,*pc;                                              //~vba2R
    char *pc;                                                      //~vba2I
//***************************                                   //~5318M~//~vba2I
//    pfh=getCurrentPfh(0);                                        //~vba2R
//    if (pfh)                                                     //~vba2R
//    {                                                            //~vba2R
//        pfnm=pfh->UFHfilename;                                   //~vba2R
//        pc=filefullpath2(Pfullpath,Pfilename,Plen,pfnm);//~v05OI~//~vba2R
//    }                                                            //~vba2R
//    else                                                         //~vba2R
    	pc=filefullpath(Pfullpath,Pfilename,Plen);//~v05OI~        //~vba2R
    return pc;                                                     //~vba2I
}//filefullpathsp                                                  //~vba2I
//*******************************************************       //~5318M~
//*get file fullpath name                                       //~5318M~
//* prefix ^*\, :: ,sp:                                            //~vba2R
//*parm 1:output full pth mame                                  //~5318M~
//*parm 2:input partial filename                                //~5318M~
//*parm 3:output buff len                                       //~5318M~
//*return:output buff addr or NULL if err                       //~5318M~
//*******************************************************       //~5318M~
char *filefullpath(char *Pfullpath,char *Pfilename,size_t Plen) //~5318M~
{                                                               //~5318M~
    PUCLIENTWE pcw2;                                               //~v60yI~
    PUFILEH    pfh;                                                //~v60yI~
    UCHAR *pc;                                                  //~5318M~
	char fpathwk[_MAX_PATH];                                       //~v60yI~
	char fpathsp[_MAX_PATH];                                       //~v60yI~//~vba2I
    int rc;                                                        //~v47HI~
    int len;                                                       //~v07pI~
    char sepc,*modifier;                                           //~v60yI~
    int optcp=0,cprc=0;                                            //~vb2eR
//***************************                                   //~5318M~
	if (USTRHEADIS_IC(Pfilename,FTP_SHORTPATH_PREFIX))             //~vba2R
    {                                                              //~vba2I
    	if (!isShortpath(0,Pfilename+sizeof(FTP_SHORTPATH_PREFIX)-1,fpathsp,sizeof(fpathsp)))//~vba2R
        	return filefullpathsp(0,Pfullpath,fpathsp,Plen);//~v05OI~//~vba2R
    }                                                              //~vba2I
#ifdef LNX                                                         //~vb2eI
	Gsubgblopt&=~(                                                 //~vb2eR
			XESUB_GBLOPT_RC_MOUNTU8_FFP  //(Linux)ufullpath set mount option:iocharset is utf8 or not specified(default utf8)//~vb2eR
		  | XESUB_GBLOPT_DONE_CHKMOUNT_FFP   //filefullpath did check mount option//~vb2eI
          );                                                       //~vb2eI
#endif                                                             //~vb2eI
	if (!memcmp(Pfilename,FNMOF2NDSCR,sizeof(FNMOF2NDSCR)-1))	//other screen filename spec//~v60yR~
    {                                                              //~v60yI~
    	modifier=Pfilename+sizeof(FNMOF2NDSCR)-1;                  //~v60yR~
    	sepc=*modifier;                                            //~v60yI~
    	if (!sepc                                                  //~v60yI~
#ifdef FTPSUPP                                                     //~v70zI~
        ||   sepc==DSN_SEPC    // "^*."                            //~v70zI~
        ||   sepc==DSN_SEPCMEMB    // "^*("                        //~v70zI~
#endif                                                             //~v70zI~
#ifdef W32                                                         //~v60yI~
        ||   sepc==DIR_SEPC    // *\       ,                       //~v60yI~
        ||   sepc==FTP_DIR_SEPC)    // or                          //~v60yI~
#else                                                              //~v60yI~
        ||   sepc==DIR_SEPC)   // *\ or */                         //~v60yI~
#endif                                                             //~v60yI~
		{                                                          //~v60yI~
			pcw2=scrgetcw(-1);	//another screen                   //~v60yI~
        	if (pcw2                                               //~v60yI~
    		&&  (pcw2->UCWtype==UCWTFILE || pcw2->UCWtype==UCWTDIR))//~v60yI~
            {                                                      //~v60yI~
        		pfh=UGETPFHFROMPCW(pcw2);                          //~v60yI~
#ifdef FTPSUPP                                                     //~v70zI~
				if (UCBITCHK(pfh->UFHflag7,UFHF7TSO)	//another is tso//~v70zI~
//              &&  (!sepc||sepc==DSN_SEPC||sepc==DSN_SEPCMEMB))   //~v71gR~
                )     //accept also "^*\"                          //~v71gR~
                	return xetsofilefullpath2ndedit(Pfullpath,pfh,modifier);//~v70zR~
//            if (!(sepc==DSN_SEPC||sepc==DSN_SEPCMEMB))           //~v71gR~
//            {                                                    //~v71gR~
#endif                                                             //~v70zI~
                rc=filefullpath2ndedit(fpathwk,pfh,modifier);//ok  //~v60yR~
                if (!rc)                                           //~v60yI~
                {                                                  //~v60yI~
                	strcpy(Pfullpath,fpathwk);                     //~v60yI~
                	return Pfullpath;                              //~v60yI~
                }                                                  //~v60yI~
                if (rc==1)	//*2\... fmt (may contain wildcard)    //~v60yI~
                	return filefullpath(Pfullpath,fpathwk,Plen);   //~v60yR~
                //if rc=4 treate *2 as it                          //~v60yI~
//#ifdef FTPSUPP                                                   //~v71gR~
//            } //not DSN sepc                                     //~v71gR~
//#endif                                                           //~v71gR~
            }//other screen is dir/file                            //~v60yR~
        }//"*2" / "*2\"                                            //~v60yR~
    }// "*2"                                                       //~v60yR~
    if (!memcmp(Pfilename,WORKDIRPATHID,WORKDIRPATHIDLEN))      //~5318M~
    {                                                           //~5318M~
        strcpy(Pfullpath,Gworkdir);                             //~5318M~
        if (*(Pfilename+2))                                     //~v040I~
        {                                                          //~v636I~
//#ifndef DOS                                                      //~v70sR~
            if (*(Pfilename+2)==XESUB_PIDFILEID)     //::# is translated to ::pid.//~v636I~
//              sprintf(Pfullpath,"%s%lu.%s",Gworkdir,ugetpid(),Pfilename+3);//~v76qR~
                sprintf(Pfullpath,"%s%lu%s",Gworkdir,ugetpid(),Pfilename+3);//~v76qI~
            else                                                   //~v636I~
//#endif                                                           //~v70sR~
            strcat(Pfullpath,Pfilename+2);                      //~v040R~
        }                                                          //~v636I~
        else                                                    //~v040I~
        {                                                          //~v07pI~
            if (len=(int)strlen(Pfullpath),len>3)   //not root     //~v07pI~
            *(Pfullpath+len-1)=0;                                  //~v07pR~
        }                                                          //~v07pI~
        strcpy(fpathwk,Pfullpath);                                 //~v711I~
//      pc=ufullpath(Pfullpath,fpathwk,Plen);                      //~v711I~//~vb2eR
		optcp=0;                                                   //~vb2eI
#ifdef LNX                                                         //~vb2eI
		if (Gsubgblopt & XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP)   //filefullpath dose not check mount option//~vb2eR
        	optcp|=UFPCPO_NOCONV;   //no chk iocharset             //~vb2eR
#endif                                                             //~vb2eI
        pc=ufullpathCP(optcp,Pfullpath,fpathwk,Plen,&cprc);                      //~v711I~//~vb2eR
        if (!pc)                                                   //~v711I~
            return 0;                                              //~v711I~
#ifdef LNX                                                         //~vb2eI
		if (!(Gsubgblopt & XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP))   //filefullpath check mount option and conv to u8 if required//~vb2eR
        {                                                          //~vb2eI
		    Gsubgblopt|=XESUB_GBLOPT_DONE_CHKMOUNT_FFP;   //filefullpath did check mount option//~vb2eR
			if (cprc  & (UFPCPRC_IOCS_U8|UFPCPRC_IOCS_UNKNOWN))    //~vb2eR
				Gsubgblopt|=XESUB_GBLOPT_RC_MOUNTU8_FFP;  //(Linux)ufullpath set mount option:iocharset is utf8 or not specified(default utf8)//~vb2eR
            if (cprc & UFPCPRC_CONVU8)                             //~vb2eI
				Gsubgblopt|=XESUB_GBLOPT_DONE_L2F;  		//conversion to utf8 done//~vb2eR
        }                                                          //~vb2eI
#endif                                                             //~vb2eI
        pc=Pfullpath;                                           //~5318M~
    }                                                           //~5318M~
    else                                                        //~5318M~
    {                                                              //~v40BI~
//      pc=ufullpath(Pfullpath,Pfilename,Plen);                 //~5318M~//~vb2eR
		optcp=0;                                                   //~vb2eI
#ifdef LNX                                                         //~vb2eI
		if (Gsubgblopt & XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP)   //filefullpath dose not check mount option//~vb2eR
        	optcp|=UFPCPO_NOCONV;   //no chk iocharset             //~vb2eR
#endif                                                             //~vb2eI
        pc=ufullpathCP(optcp,Pfullpath,Pfilename,Plen,&cprc);                 //~5318M~//~vb2eR
        if (!pc)                                                   //~v40BI~
            return 0;                                              //~v40BI~
#ifdef LNX                                                         //~vb2eI
		if (!(Gsubgblopt & XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP))   //filefullpath check mount option and conv to u8 if required//~vb2eR
        {                                                          //~vb2eI
		    Gsubgblopt|=XESUB_GBLOPT_DONE_CHKMOUNT_FFP;   //filefullpath did check mount option//~vb2eR
			if (cprc  & (UFPCPRC_IOCS_U8|UFPCPRC_IOCS_UNKNOWN))    //~vb2eR
                Gsubgblopt|=XESUB_GBLOPT_RC_MOUNTU8_FFP;  //(Linux)ufullpath set mount option:iocharset is utf8 or not specified(default utf8)//~vb2eR
            if (cprc & UFPCPRC_CONVU8)                             //~vb2eR
				Gsubgblopt|=XESUB_GBLOPT_DONE_L2F;  		//conversion to utf8 done//~vb2eR
        }                                                          //~vb2eI
#endif                                                             //~vb2eI
    }                                                              //~v40BI~
    if (WILDCARD(pc))                                              //~v40uI~
    	if (Gsubgblopt & (XESUB_GBLOPT_WILDPATH|XESUB_GBLOPT_WILDMEMB))//~v40uI~
        {                                                          //~v47HI~
            rc=                                                    //~v47HI~
        	ufullpathwildexp( ((Gsubgblopt & XESUB_GBLOPT_WILDMEMB)!=0)*FPOPT_MEMBEXP,//~v40uR~
//  							Pfullpath,Pfullpath,_MAX_PATH);	//replace wildcard//~v40uR~//~vb7jR
    							Pfullpath,Pfullpath,Plen);	//replace wildcard//~v40uR~//~vb7jI
            if (rc==3)      //multiple intermediate path           //~v47HR~
            {                                                      //~v47HI~
                uerrmsg("wild card filename(%s) is not unique",    //~v47HI~
                		"ワイルドカード(%s)でファイル名が決まりません",//~v47HI~
                        	Pfullpath);                            //~v47HI~
                pc=0;                                              //~v47HI~
            }                                                      //~v47HI~
            if (rc==8)      //too long filename                    //~vb7aR
            {                                                      //~v47HI~//~vb75I
                pc=0;                                              //~v47HI~//~vb75I
            }                                                      //~v47HI~//~vb75I
        }                                                          //~v47HI~
    return pc;                                                  //~5318M~
}//filefullpath                                                 //~5318M~
//*******************************************************          //~v60yI~
//*modify pfh filename of other screen by modifier specification   //~v60yI~
//*  *2\..\abc etc                                                 //~v60yI~
//*return:rc                                                       //~v60yI~
//*******************************************************          //~v60yI~
int filefullpath2ndedit(char *Pfullpath,PUFILEH Ppfh,char *Pmodifier)//~v60yI~
{                                                                  //~v60yI~
	char *fnm,*modf,*pc,*pc2,*pc3,fpathwk[_MAX_PATH];              //~v60yR~
    int  pathlen,sepc;                                             //~v60yR~
//************************                                         //~v60yI~
	fnm=Ppfh->UFHfilename;                                         //~v60yI~
	modf=Pmodifier;                                                //~v60yI~
// "*2"                                                            //~v60yI~
    if (!*modf)		//no modification                              //~v60yI~
    {                                                              //~v60yI~
        strcpy(Pfullpath,fnm);                                     //~v60yI~
        return 0;                                                  //~v60yR~
    }                                                              //~v60yI~
// "*2\"                                                           //~v60yI~
    sepc=*modf++;                                                  //~v60yI~
    strcpy(Pfullpath,fnm);  //pfhfilename                          //~v60yR~
//  if (Ppfh->UFHtype!=UFHTDIR)                                    //~v68mR~
//  {                                                              //~v68mR~
        pathlen=PATHLEN(fnm);                                      //~v60yI~
        if (pathlen<0)                                             //~v60yI~
            return 4;                                              //~v60yI~
    if (Ppfh->UFHtype!=UFHTDIR                                     //~v68mI~
    ||  WILDCARD(fnm+pathlen))  //wildcard dir list                //~v68mI~
    {                                                              //~v68mI~
        *(Pfullpath+pathlen)=0;                                    //~v60yI~
    	if (!ROOTDIR3(Pfullpath))                                  //~v60yI~
	        *(Pfullpath+pathlen-1)=0;                              //~v60yI~
    }                                                              //~v60yI~
    if (ROOTDIR3(Pfullpath))                                       //~v60yI~
    {                                                              //~v60yI~
    	if (!*modf)	//"*2\" fmt                                    //~v60yI~
    		return 0;	//no concatination required                //~v60yI~
        pathlen=(int)strlen(Pfullpath);	//path len                 //~v60yI~
		strcat(Pfullpath,modf);	//concat after "\"                 //~v60yR~
    }                                                              //~v60yI~
    else                                                           //~v60yI~
    {                                                              //~v60yI~
        pathlen=(int)strlen(Pfullpath);	//path len                 //~v60yI~
        if (*(Pfullpath+pathlen-1)==sepc)                          //~v60yR~
        {                                                          //~v60yI~
        	pathlen--;                                             //~v60yI~
	        *(Pfullpath+pathlen)=0;                                //~v60yI~
        }                                                          //~v60yI~
	    if (!*modf)	//"*2\" fmt                                    //~v60yR~
        	return 0;                                              //~v60yR~
		strcpy(Pfullpath+pathlen,modf-1);                          //~v60yR~
    }                                                              //~v60yI~
//parentdir process(..\) after "*2\"                               //~v60yR~
	strcpy(fpathwk,Pfullpath);                                     //~v60yI~
	pc=fpathwk+pathlen;                                            //~v60yR~
    for (;;)                                                       //~v60yI~
    {                                                              //~v60yI~
    	pc2=strchr(pc,'.');                                        //~v60yI~
        pc3=pc2;	//"../" start point                            //~v60yI~
        if (!pc2)                                                  //~v60yI~
        	break;                                                 //~v60yI~
        pc=pc2+1;      //after .                                   //~v60yI~
        if (*pc!='.')                                              //~v60yI~
        	continue;                                              //~v60yI~
        pc++;	      //after ..                                   //~v60yI~
        if (*pc && *pc!=sepc)                                      //~v60yR~
        	continue;                                              //~v60yI~
      if(*pc)   //avoid loop                                       //~v615I~
        pc++;          //after "..\"                               //~v60yR~
        *pc3=0;                                                    //~v60yI~
        if (ROOTDIR3(fpathwk)) //no more back                      //~v60yI~
      {                                                            //~v615I~
//          return 4;                                              //~v615R~
            pathlen=(int)strlen(fpathwk);                          //~v615R~
      }                                                            //~v615I~
      else                                                         //~v615I~
      {                                                            //~v615I~
        *(pc3-1)=0;                                                //~v60yI~
        pathlen=PATHLEN(fpathwk);                                  //~v60yR~
        if (pathlen<0)                                             //~v60yI~
        	break;                                                 //~v60yI~
      }                                                            //~v615I~
        if (!*pc)                                                  //~v615I~
        {                                                          //~v70uI~
        	*(fpathwk+pathlen)=0;                                  //~v70uI~
            break;                                                 //~v615I~
        }                                                          //~v70uI~
        strcpy(fpathwk+pathlen,pc);                                //~v60yR~
        pc=fpathwk+pathlen;                                        //~v60yR~
    }//loop process parent                                         //~v60yI~
    pathlen=(int)strlen(fpathwk);                                  //~v615R~
    if (!ROOTDIR3(fpathwk)) //no more back                         //~v60yI~
    	if (*(fpathwk+pathlen-1)==sepc)                            //~v60yR~
        	*(fpathwk+pathlen-1)=0;	//drop last "\"                //~v60yR~
    strcpy(Pfullpath,fpathwk);                                     //~v60yI~
	return 1;	//continue by modified filename                    //~v60yI~
}//filefullpath2ndedit                                             //~v60yI~
//*******************************************************       //~v05OI~
//*get file fullpath name from source (chk *\/**\)               //~v05OI~//~vb89R//~vba2R
//*parm 1:output full pth mame                                  //~v05OI~
//*parm 2:input partial target filename                         //~v05OI~
//*parm 3:output buff len                                       //~v05OI~
//*parm 4:source fullpath filename                              //~v05OI~
//*return:output buff addr or NULL if err                       //~v05OI~
//*******************************************************       //~v05OI~
char *filefullpath2(char *Pfullpath,char *Ptarget,size_t Plen,char *Psource)//~v05OI~
{                                                               //~v05OI~
    UCHAR *pc,*fname;                                           //~v05OI~
    char  chsave;                                                  //~v07lI~
    int pathlen=0,len,level,samedirsw,ii;                          //~vaf9R~
    char  fpath[_MAX_PATH];                                        //~v13dI~
#ifdef FTPSUPP                                                     //~v70zI~
    PUFTPHOST puftph;                                              //~v70zI~
#endif                                                             //~v70zI~
//***************************                                   //~v05OI~
    if (*Ptarget!=SAMEDIR)                                      //~v05OR~
        return filefullpath(Pfullpath,Ptarget,Plen);            //~v05OM~
#ifdef FTPSUPP                                                     //~v70zI~
    uftpisremote(Psource,&puftph);                                 //~v70zR~
    if (UFTPHISTSO(puftph))                                        //~v70zR~
		return xetsofilefullpath2(Pfullpath,Ptarget,Plen,Psource);//~v70zI~
#endif                                                             //~v70zI~
//  if (memcmp(Ptarget,FNMOF2NDSCR,sizeof(FNMOF2NDSCR)-1))	//other screen filename spec//~v610R~
//      return filefullpath(Pfullpath,Ptarget,Plen);               //~v610R~
                                                                //~v05OI~
//  if (*(Ptarget+1)=='\\')                                        //~v194R~
#ifdef W32                                                         //~v540I~
    if (*(Ptarget+1)==DIR_SEPC    // *\       ,                    //~v540R~
    ||  *(Ptarget+1)==FTP_DIR_SEPC)    // or                       //~v540R~
#else                                                              //~v540I~
    if (*(Ptarget+1)==DIR_SEPC)   // *\ or */                      //~v194I~
#endif                                                             //~v540I~
        samedirsw=1;                                            //~v05OI~
    else                                                        //~v05OI~
//      if (*(Ptarget+1)==SAMEDIR && *(Ptarget+2)=='\\')           //~v194R~
#ifdef W32                                                         //~v540I~
        if (*(Ptarget+1)==SAMEDIR                                  //~v540I~
        &&  (*(Ptarget+2)==DIR_SEPC||*(Ptarget+2)==FTP_DIR_SEPC)) //**\,**///~v540I~
#else                                                              //~v540I~
        if (*(Ptarget+1)==SAMEDIR && *(Ptarget+2)==DIR_SEPC) //**\,**///~v194I~
#endif                                                             //~v540I~
            samedirsw=0;                                        //~v05OI~
        else                                                    //~v05OI~
        {                                                       //~v05OI~
//            ufilepatherr(Ptarget,0);                             //~v11IR~
//            return 0;                                            //~v11IR~
            samedirsw=0;    //id of copy only driveid or ftp path  //~v57EI~
          	if (*(Ptarget+1)==':')   //"*:" fmt                    //~v57EI~
          	{                                                      //~v57EI~
          		if (pc=strchr(Psource,':'),pc)                     //~v57ER~
            	{                                                  //~v57EI~
          			samedirsw=2;	//id of copy only driveid or ftp path//~v57EI~
//                  pathlen=(int)((ULONG)pc-(ULONG)Psource)+1;     //~v57EI~//~vafkR~
                    pathlen=(int)((ULPTR)pc-(ULPTR)Psource)+1;     //~vafkI~
                }                                                  //~v57EI~
                                                                   //~v57EI~
          	}                                                      //~v57EI~
          if (!samedirsw)//not valid "*:"                          //~v57EI~
            return filefullpath(Pfullpath,Ptarget,Plen);           //~v11II~
        }                                                       //~v05OI~
                                                                //~v05OI~
  if (samedirsw!=2)	//not id of copy only driveid or ftp path      //~v57EI~
    if ((pathlen=PATHLEN(Psource))<0)       //pos of last fname //~v05OR~
    {                                                           //~v05OI~
        ufilepatherr(Ptarget,0);                                //~v05OR~
        return 0;                                               //~v05OI~
    }                                                           //~v05OI~
                                                                //~v05OI~
    if (samedirsw)  //samedir                                   //~v05OR~
        fname=Ptarget+2;                                        //~v05OI~
    else    //upper dir                                         //~v05OI~
    {                                                           //~v05OI~
        for (level=1,pc=Ptarget+3;;level++,pc+=3)   //count UPPERDIR//~v05OR~
//          if (*pc!=SAMEDIR || *(pc+1)!=SAMEDIR || *(pc+2)!='\\') //~v194R~
#ifdef W32                                                         //~v540I~
            if (*pc!=SAMEDIR || *(pc+1)!=SAMEDIR || (*(pc+2)!=DIR_SEPC&&*(pc+2)!=FTP_DIR_SEPC))//~v540I~
#else                                                              //~v540I~
            if (*pc!=SAMEDIR || *(pc+1)!=SAMEDIR || *(pc+2)!=DIR_SEPC)//~v194I~
#endif                                                             //~v540I~
                break;                                          //~v05OI~
        fname=pc;                                               //~v05OR~
                                                                //~v05OI~
//      for (len=pathlen-2,pc=Psource+len;len;len--,pc--)          //~v07lR~
//          if (*pc=='\\')  //level up                             //~v07lR~
//              if (!(--level))                                    //~v07lR~
//                  break;                                         //~v07lR~
//          if (!len)                                              //~v07lI~
        for (ii=0;ii<level;ii++)                                   //~v07lR~
        {                                                          //~v07lI~
            pc=Psource+pathlen-1;                                  //~v07lI~
            chsave=*pc;                                            //~v07lI~
            *pc=0;                  //null term                    //~v07lI~
            pathlen=PATHLEN(Psource);                              //~v07lI~
            *pc=chsave;                                            //~v07lI~
            if (pathlen<=0) //level up                             //~v07lR~
            {                                                      //~v07lI~
                ufilepatherr(Ptarget,0);                           //~v07lR~
                return 0;                                          //~v07lR~
            }                                                      //~v07lI~
        }                                                          //~v07lI~
//      pathlen=++len;                                             //~v07lR~
    }//upper dir                                                   //~v07lR~
    len=(int)strlen(fname); //len after same path               //~v05OR~
//  if (pathlen+len>=(int)Plen) //buff shortage                    //~v13dR~
    if (pathlen+len>=_MAX_PATH) //buff shortage                    //~v13dI~
    {                                                           //~v05OI~
//      errtoolong();   //                                      //~v05OI~//~vb7aR
        ufileTooLongFullpathName(0/*rc*/);                         //~vb7aI
        return 0;   //err                                       //~v05OI~
    }                                                           //~v05OI~
//  memcpy(Pfullpath,Psource,(UINT)pathlen);                       //~v13dR~
//  strcpy(Pfullpath+pathlen,fname);                               //~v13dR~
//  return Pfullpath;                                              //~v13dR~
    memcpy(fpath,Psource,(UINT)pathlen);                           //~v13dR~
    strcpy(fpath+pathlen,fname);                                   //~v13dR~
    return filefullpath(Pfullpath,fpath,Plen);                     //~v13dR~
}//filefullpath2                                                //~v05OI~
//*******************************************************          //~v77yI~
//*replace *\,**\,^*\ by screen filename                           //~v77yI~
//*        No TSO support,**\ is only once                         //~v77yI~
//*return:1:replaced,0:not replaced                                //~v77yI~
//*******************************************************          //~v77yI~
int subeditscrfnm(int Popt,PUCLIENTWE Ppcw,char *Pinp,char *Pout)  //~v77yI~
{                                                                  //~v77yI~
	PUCLIENTWE pcw2;                                               //~v77yI~
	PUFILEH pfh;                                                   //~v77yI~
    UCHAR *pc,*fname,*fhfname,*modifier;                           //~v77yI~
    char  chsave,sepc;                                             //~v77yR~
    int pathlen,/*len,*/level,samedirsw,ii,rc;                     //~v77yR~
    char  fpathwk[_MAX_PATH];                                      //~v77yI~
//***************************                                      //~v77yI~
    for (;;)                                                       //~v77yI~
    {                                                              //~v77yI~
        if (*Pinp!=SAMEDIR)                                        //~v77yI~
            break;             //chk ^*\ more                      //~v77yI~
        if (Ppcw->UCWtype!=UCWTDIR                                 //~v77yI~
        &&  Ppcw->UCWtype!=UCWTFILE)                               //~v77yI~
            return 0;                                              //~v77yI~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~v77yI~
        fhfname=pfh->UFHfilename;                                  //~v77yI~
    #ifdef W32                                                     //~v77yI~
        if (*(Pinp+1)==DIR_SEPC    // *\       ,                   //~v77yI~
        ||  *(Pinp+1)==FTP_DIR_SEPC)    // or                      //~v77yI~
    #else                                                          //~v77yI~
        if (*(Pinp+1)==DIR_SEPC)   // *\ or */                     //~v77yI~
    #endif                                                         //~v77yI~
            samedirsw=1;                                           //~v77yI~
        else                                                       //~v77yI~
    #ifdef W32                                                     //~v77yI~
            if (*(Pinp+1)==SAMEDIR                                 //~v77yI~
            &&  (*(Pinp+2)==DIR_SEPC||*(Pinp+2)==FTP_DIR_SEPC)) //**\,**///~v77yI~
    #else                                                          //~v77yI~
            if (*(Pinp+1)==SAMEDIR && *(Pinp+2)==DIR_SEPC) //**\,**///~v77yI~
    #endif                                                         //~v77yI~
                samedirsw=0;                                       //~v77yI~
            else                                                   //~v77yI~
                return 0;                                          //~v77yI~
        if ((pathlen=PATHLEN(fhfname))<0)       //pos of last fname//~v77yI~
            return 0;                                              //~v77yI~
        if (Ppcw->UCWtype==UCWTDIR)                                //~v79KM~
        {                                                          //~v79KI~
	    	sepc=*(fhfname+pathlen-1);                             //~v79KI~
            pathlen=(int)strlen(fhfname);                          //~v7abR~
            memcpy(fpathwk,fhfname,(UINT)pathlen);                 //~v7abR~
            if (*(fpathwk+pathlen-1)!=sepc)	//not root             //~v79KI~
	            *(fpathwk+pathlen++)=sepc;                         //~v79KR~
            *(fpathwk+pathlen)=0;                                  //~v79KI~
            fhfname=fpathwk;                                       //~v79KI~
        }                                                          //~v79KI~
        if (samedirsw)  //samedir                                  //~v77yI~
            fname=Pinp+2;                                          //~v77yI~
        else    //upper dir                                        //~v77yI~
        {                                                          //~v77yI~
            for (level=1,pc=Pinp+3;;level++,pc+=3)   //count UPPERDIR//~v77yI~
    #ifdef W32                                                     //~v77yI~
                if (*pc!=SAMEDIR || *(pc+1)!=SAMEDIR || (*(pc+2)!=DIR_SEPC&&*(pc+2)!=FTP_DIR_SEPC))//~v77yI~
    #else                                                          //~v77yI~
                if (*pc!=SAMEDIR || *(pc+1)!=SAMEDIR || *(pc+2)!=DIR_SEPC)//~v77yI~
    #endif                                                         //~v77yI~
                    break;                                         //~v77yI~
            fname=pc;                                              //~v77yI~
            for (ii=0;ii<level;ii++)                               //~v77yI~
            {                                                      //~v77yI~
                pc=fhfname+pathlen-1;                              //~v77yI~
                chsave=*pc;                                        //~v77yI~
                *pc=0;                  //null term                //~v77yI~
                pathlen=PATHLEN(fhfname);                          //~v77yI~
                *pc=chsave;                                        //~v77yI~
                if (pathlen<=0) //level up                         //~v77yI~
                    return 0;                                      //~v77yI~
            }                                                      //~v77yI~
        }//upper dir                                               //~v77yI~
//      len=(int)strlen(fname); //len after same path              //~v77yR~
        memcpy(Pout,fhfname,(UINT)pathlen);                        //~v77yI~
	    strcpy(Pout+pathlen,fname);                                //~v77yR~
        if (!*fname)                                               //~v77yI~
        	if (!ROOTDIR3(Pout))                                   //~v77yR~
            	*(Pout+pathlen-1)=0;                               //~v77yI~
        return 1;                                                  //~v77yI~
    }// *\ chk                                                     //~v77yI~
	if (!memcmp(Pinp,FNMOF2NDSCR,sizeof(FNMOF2NDSCR)-1))	//other screen filename spec//~v77yR~
    {                                                              //~v77yI~
    	modifier=Pinp+sizeof(FNMOF2NDSCR)-1;                       //~v77yR~
    	sepc=*modifier;                                            //~v77yI~
    	if (!sepc                                                  //~v77yI~
#ifdef W32                                                         //~v77yI~
        ||   sepc==DIR_SEPC    // *\       ,                       //~v77yI~
        ||   sepc==FTP_DIR_SEPC)    // or                          //~v77yI~
#else                                                              //~v77yI~
        ||   sepc==DIR_SEPC)   // *\ or */                         //~v77yI~
#endif                                                             //~v77yI~
		{                                                          //~v77yI~
			pcw2=scrgetcw(-1);	//another screen                   //~v77yI~
        	if (pcw2                                               //~v77yI~
    		&&  (pcw2->UCWtype==UCWTFILE || pcw2->UCWtype==UCWTDIR))//~v77yI~
            {                                                      //~v77yI~
        		pfh=UGETPFHFROMPCW(pcw2);                          //~v77yI~
                rc=filefullpath2ndedit(fpathwk,pfh,modifier);//ok  //~v77yI~
                if (rc>1)                                          //~v77yI~
                	return 0;                                      //~v77yI~
                strcpy(Pout,fpathwk);                              //~v77yI~
                return 1;                                          //~v77yI~
            }//other screen is dir/file                            //~v77yI~
        }//"^*" / "^*\"                                            //~v77yI~
    }// "^*"                                                       //~v77yI~
    return 0;                                                      //~v77yI~
}//subeditscrfnm                                                   //~v77yI~
#ifdef W32UNICODE                                                  //~vavDI
//*******************************************************          //~vavDI
//*dbcs tbl output ,no dbcs between UID                            //~vavDI
//*******************************************************          //~vavDI
void setdbcstblW(UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)             //~vavDR
{                                                                  //~vavDI
    int reslen,len,lenud;                                          //~vavDR
    char *pc,*pc2,*pc3,*pcd;                                       //~vavDI
//***************                                                  //~vavDI
	for (pc=Ppdata,pcd=Ppdbcs,reslen=Plen;reslen;)                 //~vavDI
    {                                                              //~vavDI
    	lenud=0;                                                   //~vavDI
        pc2=memchr(pc,UD_NOTLC,reslen);                            //~vavDI
        if (pc2)                                                   //~vavDI
        {                                                          //~vavDI
            len=PTRDIFF(pc2,pc);                                   //~vavDI
	        pc3=memchr(pc2+1,UD_NOTLC,reslen-1);                   //~vavDI
            if (pc3)                                               //~vavDI
	            lenud=PTRDIFF(pc3,pc2)+1;                          //~vavDI
            else   //pair err                                      //~vavDI
            {                                                      //~vavDI
                pc++;   //avoid loop                               //~vavDI
                *pcd++=0;                                          //~vavDI
            	len=--reslen;                                      //~vavDI
            }                                                      //~vavDI
        }                                                          //~vavDI
        else                                                       //~vavDI
            len=reslen;                                            //~vavDI
        if (len)                                                   //~vavDI
        {                                                          //~vavDI
        	setdbcstbl(pc,pcd,len);                                //~vavDR
            pc+=len;                                               //~vavDI
            pcd+=len;                                              //~vavDI
            reslen-=len;                                           //~vavDI
        }                                                          //~vavDI
        if (lenud)                                                 //~vavDI
        {                                                          //~vavDI
        	memset(pcd,0,lenud);                                   //~vavDI
            pc+=lenud;                                             //~vavDI
            pcd+=lenud;                                            //~vavDI
            reslen-=lenud;                                         //~vavDI
        }                                                          //~vavDI
    }                                                              //~vavDI
    return;                                                        //~vavDR
}//setdbcstblW                                                     //~vavDI
#endif	//W32UNICODE                                               //~vavDI
//*******************************************************
//*dbcs tbl output
//*******************************************************
void setdbcstbl(UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)
{
#ifdef AIX                                                         //~v30fI~
//  usjischk(Ppdata,Plen,Ppdbcs,UDBCSCHK_ASCIISBCS);               //~v411R~
//  usjischk(Ppdata,Plen,Ppdbcs,0);                                //~v47WR~
  if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //dbcs mode                  //~v73xI~
    usjischk(Ppdata,Plen,Ppdbcs,0,0);                              //~v47WI~
  else                    //english mode                           //~v73xI~
    memset(Ppdbcs,0,Plen);                                         //~v73xI~
#else                                                              //~v30fI~
//static UCHAR Sdbcsid[2]="\x01\x02";                              //~v09pR~
//static UCHAR Sdbcsid[2]={DBCS1STCHAR,DBCS2NDCHAR};               //~v09YR~
    int i;
	int dbcstype;                                                  //~va1cR~
//***************
#ifdef LNX                                                         //~v21oR~
    if (!(Gunxflag & GUNX_KON)) //CONSOLE                          //~v79zI~
    {                                                              //~v79zI~
	    memset(Ppdbcs,0,(UINT)Plen);                               //~v79zI~
    	return;                                                    //~v79zI~
    }                                                              //~v79zI~
#ifdef UTF8SUPPH //use external converter                          //~va1cR~
//  if (XE_ISDBCS())	//CJK(+UTF8)                               //~va1cR~//~va1FR~
    if (XE_ISDBCSKON())	//CJK(+UTF8) not on console                //~va1FI~
    {                                                              //~va1cR~
    	usetdbcstblmb(USDTMO_CHK2ND|USDTMO_SPLITERR,Ppdata,Ppdbcs,Plen);//external converter(iconv)//~va1cR~
    	return;                                                    //~va1cR~
    }                                                              //~va1cR~
#endif                                                             //~va1cR~
UTRACED("eucchk before",Ppdata,Plen);                              //~va00I~
UTRACED("eucchk before",Ppdbcs,Plen);                              //~va00I~
//  if ((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON)) //under kon//~v21mI~//~v7a8R~
//  if (XE_ISDBCSKONJ()) //EUC(+UTF8) not on CONSOLE               //~v7a8I~//~v7acR~
    if (XE_ISKONEUCJ())  //EUC(+UTF8) or /CEUC-JP not on CONSOLE   //~v7acR~
    {                                                              //~v21mI~
//  	ueucchk(Ppdata,Plen,Ppdbcs,                                //~v47WR~
    	ueucchk(Ppdata,Plen,Ppdbcs,0,     //no outlen              //~v47WR~
//				((Gunxflag & GUNX_KON)?(UDBCSCHK_ASCIISBCS|UDBCSCHK_EUCHKERR):0));//~v79zR~
				((Gunxflag & GUNX_KON)?(UDBCSCHK_ASCIISBCS|UDBCSCHK_HKDBCS):0)); //display hankana as DBCS//~v79zI~
UTRACED("eucchk after ",Ppdata,Plen);                              //~va00I~
UTRACED("eucchk after ",Ppdbcs,Plen);                              //~va00I~
    	return;                                                    //~v21mI~
    }                                                              //~v21mI~
    if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //no dbcs mode             //~v73zI~
    {                                                              //~v73zI~
	    usjischk(Ppdata,Plen,Ppdbcs,0,0);                          //~v73zI~
        return;                                                    //~v73zI~
    }                                                              //~v73zI~
#endif                                                             //~v21mI~
#ifdef W32 //windows;use external converter                        //~va1cR~
#ifdef W32UNICODE                                                  //~vavDI
    if (memchr(Ppdata,UD_NOTLC,Plen))                              //~vavDI
    {                                                              //~vavDI
        setdbcstblW(Ppdata,Ppdbcs,Plen);                           //~vavDI
        return;                                                    //~vavDI
    }                                                              //~vavDI
#endif                                                             //~vavDI
#ifdef UTF8SUPPH //use external converter                          //~va1cR~
//  if (XE_ISDBCS())	//CJK(+UTF8)                               //~va1cR~//~va1FR~
    if (XE_ISDBCSKON())	//CJK(+UTF8) not on console; no need to windows but unified//~va1FI~
    {                                                              //~va1cR~
    	usetdbcstblmb(USDTMO_CHK2ND|USDTMO_SPLITERR,Ppdata,Ppdbcs,Plen);//external converter(iconv)//~va1cR~
    	return;                                                    //~va1cR~
    }                                                              //~va1cR~
#endif                                                             //~va1cR~
#endif //W32                                                       //~va1cR~
    for (i=0;i<Plen;i++,Ppdata++,Ppdbcs++)
    {
//      if(*Ppdata==Gfiletab2)                                  //~5102R~
//          *Ppdbcs=3;          //dummy by tab                  //~5102R~
//      else                                                    //~5102R~
            if (udbcschk(*Ppdata)                                  //~v07hR~
            )                                                      //~v7a1I~
          {                                                        //~v7a1I~
//          && i<(Plen-1))                                         //~v73zR~
//          && i<(Plen-1)                                          //~v73zI~//~v7a1R~
            if(i<(Plen-1)                                          //~v7a1I~
//          && SJIS2(*(Ppdata+1))                                  //~v79zR~
//          && WCMB2ND(0,(Ppdata+1))	//valid dbcs 2nd           //~va1cR~
            && (dbcstype=WCMB2ND(0,(Ppdata+1)))	//valid dbcs 2nd   //~va1cR~
            )                                                      //~v73zI~
            {
                UMOVSW(Ppdbcs,Sdbcsid);
                Ppdbcs++;
                Ppdata++;
                i++;
            }
            else                                                   //~v7a1I~
                *Ppdbcs=UDBCSCHK_HKDBCSERR; //like as ueucchk/usjischk//~v7a1I~
          }                                                        //~v7a1I~
            else
                *Ppdbcs=0;
    }   
#endif //!AIX                                                      //~v30fI~
    return;
}//setdbcstbl                                                      //~v09YR~
                                                                   //~v09YI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*******************************************************          //~va50I~
//*dbcs tbl output for file client area only                       //~va50I~
//*pfh is option                                                   //~va50I~
//*  dispatch to ebc or locale file setdbcstbl                     //~va50R~
//*******************************************************          //~va50I~
int filesetdbcstblplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Plen)//~va50R~
{                                                                  //~va50I~
	int len,rc=0,opt;                                              //~va50R~
    PUFILEH pfh;                                                   //~va50I~
    int handle;                                                    //~va79I~
//*********************                                            //~va50I~
	if ((len=Plen)<0)                                              //~va50I~
    	len=Pplh->ULHlen;                                          //~va50I~
    if (!(pfh=Ppfh))                                               //~va50I~
    	pfh=UGETPFH(Pplh);                                         //~va50I~
    if (PFH_ISEBC(pfh))                                            //~va50R~
    {                                                              //~va50I~
        handle=pfh->UFHhandle;                                     //~va79I~
    	if (Popt & FSDT_EBC)	//ignore request for ebc file      //~va50I~
        {                                                          //~va50I~
        	opt=0;                                                 //~va50I~
            if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                  //~va50R~
            	opt|=XEEBCO_BIN;                                   //~va50I~
    		if (Popt & FSDT_CALLOC)	//reset for sbcs codepage      //~va7xR~
            	opt|=XEEBCO_CALLOC;                                //~va7xR~
//  		rc=xeebc_setdbcstbl(opt,Pplh->ULHdata+Ppos,Pplh->ULHdbcs+Ppos,len);//~va50R~//~va79R~
    		rc=xeebc_setdbcstbl(opt,handle,Pplh->ULHdata+Ppos,Pplh->ULHdbcs+Ppos,len);//~va79I~
            rc &=~1;	//dbcs found flag                          //~va50I~
        }                                                          //~va50I~
    }                                                              //~va50I~
    else                                                           //~va50M~
    {                                                              //~va50I~
    	if (!(Popt & FSDT_EBCONLY))	//ignore request for locale file//~va50R~
			rc=filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,len,Popt);//~va50I~
    }                                                              //~va50I~
	UTRACEP("filesetdbcstblplh opt=%x,rc=%d\n",Popt,rc);           //~va50I~
    return rc;                                                     //~va50R~
}//filesetdbcstblplh                                               //~va50I~
//*******************************************************          //~va7LI~
//*for ebcdic file with new handle                                 //~va7LI~
//*******************************************************          //~va7LI~
int filesetdbcstblplh_handle(int Popt,int Phandle,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Plen)//~va7LI~
{                                                                  //~va7LI~
	int rc,opt,swtgtdbcs,swsrcdbcs;                                //~va7LR~
    int /*oldhandle,*/newhandle;                                       //~va7LR~//~vaa7R~
//*********************                                            //~va7LI~
	UTRACEP("filesetdbcstblplh_handle opt=%x\n",Popt);             //~va7LI~
    if (!(Popt & FSDT_B2B))                                        //~va7LI~
		return filesetdbcstblplh(Popt,Ppfh,Pplh,Ppos,Plen);        //~va7LI~
//b2b case                                                         //~va7LI~
//  oldhandle=Ppfh->UFHhandle;                                     //~va7LR~//~vaa7R~
    newhandle=Phandle;                                             //~va7LR~
	swsrcdbcs=(Popt & FSDT_SRCDBCS)!=0;                            //~va7LI~
	swtgtdbcs=(Popt & FSDT_TGTDBCS)!=0;                            //~va7LI~
    if (!swsrcdbcs && !swtgtdbcs)  //both sbcs                     //~va7LI~
    	return 0;	//no need setdbcstbl(always null)              //~va7LI~
    opt=0;                                                         //~va7LI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~va7LR~
    	opt|=XEEBCO_BIN;                                           //~va7LI~
    rc=xeebc_setdbcstbl(opt,newhandle,Pplh->ULHdata+Ppos,Pplh->ULHdbcs+Ppos,Plen);//~va7LR~
    rc &=~1;    //dbcs found flag                                  //~va7LI~
	UTRACEP("filesetdbcstblplh_handle rc=%d\n",rc);                //~va7LR~
    return rc;                                                     //~va7LI~
}//filesetdbcstblplh_handle                                        //~va7LI~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
//*******************************************************          //~v09YI~
//*dbcs tbl output for file client area only                       //~v09YI~
//*diff to setdbcstbl                                              //~va1cR~
//*  consideration to tab(keep previously set tabid for sbcs,      //~va1cR~
//*  change tab to space with setting tabid on dbcstbl             //~va1cR~
//*******************************************************          //~v09YI~
int filesetdbcstbl(UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int Popt)  //~v44aR~
{                                                                  //~v09YI~
#ifdef AIX                                                         //~v30fI~
    int tabkeepsw;                                                 //~v456I~
//***************                                                  //~v456I~
	if (Popt & FSDT_TABSAVE)                                       //~v456I~
		tabkeepsw=UDBCSCHK_NOCLEAR;                                //~v456I~
    else                                                           //~v456I~
		tabkeepsw=0;                                               //~v456I~
                                                                   //~v45jI~
    tabkeepsw+=UDBCSCHK_ERRDBCSCHK;  //dbcs combination chk and set errid//~v45jR~
//  usjischk(Ppdata,Plen,Ppdbcs,UDBCSCHK_ASCIISBCS);               //~v411R~
//  usjischk(Ppdata,Plen,Ppdbcs,0);                                //~v456R~
//  usjischk(Ppdata,Plen,Ppdbcs,tabkeepsw);                        //~v47WR~
  if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //dbcs mode                  //~v73xI~
    usjischk(Ppdata,Plen,Ppdbcs,0,tabkeepsw);                      //~v47WI~
  else                                                             //~v73xI~
  {                                                                //~v73xI~
  	if (!tabkeepsw)                                                //~v73xI~
    	memset(Ppdbcs,0,Plen);                                     //~v73xI~
  }                                                                //~v73xI~
#else                                                              //~v30fI~
//  int i,tabkeepsw;                                               //~v456R~
    int tabkeepsw;                                                 //~v456I~
#ifndef UTF8SUPPH                                                  //~vafhI~
    int dbcssw;                                                    //~v73vI~
#endif                                                             //~vafhI~
#ifndef UTF8SUPPH //use external converter                         //~vak5I
    UCHAR *pc0,*pcd0;                                              //~v74xI~
#endif                                                             //~vak5I
//#ifndef UNX                                                      //~v53hR~
#ifndef UTF8SUPPH                                                  //~vafhI~
    int i;                                                         //~v495I~
#endif                                                             //~vafhI~
//#endif                                                           //~v53hR~
#ifndef UTF8SUPPH                                                  //~vafhI~
	int dbcstype;                                                  //~va1cR~
#endif                                                             //~vafhI~
#ifdef UTF8SUPPH //use external converter                          //~va1cR~
	int opt;                                                       //~va1cR~
#endif                                                             //~va1cR~
//***************                                                  //~v09YI~
#ifndef UTF8SUPPH //use external converter                         //~vak5I
    pc0=Ppdata;                                                    //~v74xI~
    pcd0=Ppdbcs;                                                   //~v74xI~
#endif                                                             //~vak5I
	if (Popt & FSDT_TABSAVE)                                       //~v44aR~
		tabkeepsw=UDBCSCHK_NOCLEAR;                                //~v44aI~
    else                                                           //~v44aI~
		tabkeepsw=0;                                               //~v44aI~
#ifdef UTF8SUPPH //use external converter                          //~va1cR~
//  if (XE_ISDBCS())	//CJK(+UTF8)                               //~va1cR~//~va1FR~
    if (XE_ISDBCSKON())	//CJK(+UTF8) not on console                //~va1FI~
    {                                                              //~va1cR~
    	opt=USDTMO_CHK2ND|USDTMO_SPLITERR;                         //~va1cR~
	#ifdef LNX                                                     //~va1cR~
    	if (!(Gunxflag & GUNX_KON)) //CONSOLE                      //~va1cR~
        	opt|=USDTMO_CONSOLE;                                   //~va1cR~
	#endif            	                                           //~va1cR~
    	if (tabkeepsw) 	//not clear dbcstbl tab id if for SBCS(tab expanded case)//~va1cR~
        	opt|=USDTMO_TABKEEP;                                   //~va1cR~
    	usetdbcstblmb(opt,Ppdata,Ppdbcs,Plen);//external converter(iconv)//~va1cR~
		if (Popt & FSDT_TABSET)                                    //~va1cR~
        	setdbcstbltabid(0,0,Ppdata,Ppdbcs,Plen);               //~va1cR~
    	return 0;                                                  //~va1cR~
    }                                                              //~va1cR~
    else                                                           //~va1rI~
    {                                                              //~va1rI~
    	if (!tabkeepsw)                                            //~va1rI~
    		memset(Ppdbcs,0,(UINT)Plen);                           //~va1rI~
		if (Popt & FSDT_TABSET)                                    //~va1rI~
        	setdbcstbltabid(0,0,Ppdata,Ppdbcs,Plen);               //~va1rI~
    	return 0;                                                  //~va1rI~
    }                                                              //~va1rI~
//#endif                                                             //~va1cR~//~vafhR~
#else     //!UTF8SUPPH                                             //~vafhI~
//now followings are for DOS and OS2 ***********************************//~va1rI~
#ifdef LNX                                                         //~v21oR~
//  if ((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON)) //under kon//~v21mI~//~v7a8R~
//  if (XE_ISDBCSKONJ()) //EUC(+UTF8) not on CONSOLE               //~v7a8I~//~v7acR~
    if (XE_ISKONEUCJ())  //EUC(+UTF8) or /CEUC-JP not on CONSOLE   //~v7acI~
    {                                                              //~v21mI~
//  	ueucchk(Ppdata,Plen,Ppdbcs,	//o:no hk conv                 //~v44aR~
//  	ueucchk(Ppdata,Plen,Ppdbcs,tabkeepsw+	//o:no hk conv     //~v47WR~
    	ueucchk(Ppdata,Plen,Ppdbcs,0,tabkeepsw+	//o:no hk conv     //~v47WR~
//				((Gunxflag & GUNX_KON)?(UDBCSCHK_ASCIISBCS|UDBCSCHK_EUCHKERR):0));//~v79zR~
				((Gunxflag & GUNX_KON)?(UDBCSCHK_ASCIISBCS|UDBCSCHK_HKDBCS):0));//~v79zI~
		if (Popt & FSDT_TABSET)                                    //~v74xI~
        	setdbcstbltabid(0,0,Ppdata,Ppdbcs,Plen);	           //~v74xR~
UTRACED("data   ",Ppdata,Plen);                                    //~v79KI~
UTRACED("dbcstbl",Ppdbcs,Plen);                                    //~v79KI~
    	return 0;                                                  //~v44aR~
    }                                                              //~v21mI~
#endif                                                             //~v21mI~
//    for (i=0;i<Plen;i++,Ppdata++,Ppdbcs++)                       //~v456R~
//    {                                                            //~v456R~
////      if(!*Ppdata)                                             //~v456R~
////      {                                                        //~v456R~
////          *Ppdata=NULLCHARIDDATA;         //for strchr etc     //~v456R~
////          *Ppdbcs=NULLCHARIDDBCS;         //null indicator     //~v456R~
////      }                                                        //~v456R~
////      else                                                     //~v456R~
//            if (udbcschk(*Ppdata)                                //~v456R~
//            && i<(Plen-1)                                        //~v456R~
//            && !((tabkeepsw && *(Ppdbcs+1)==TABCHAR)))//2nd byte is not tab//~v456R~
//            {                                                    //~v456R~
//                UMOVSW(Ppdbcs,Sdbcsid);                          //~v456R~
//                Ppdbcs++;                                        //~v456R~
//                Ppdata++;                                        //~v456R~
//                i++;                                             //~v456R~
//            }                                                    //~v456R~
//            else                                                 //~v456R~
//            {                                                    //~v456R~
//              if (tabkeepsw)                                     //~v456R~
//              {                                                  //~v456R~
//                if (*Ppdbcs==DBCS1STCHAR||*Ppdbcs==DBCS2NDCHAR)  //~v456R~
//                    *Ppdbcs=0;                                   //~v456R~
//              }                                                  //~v456R~
//              else                                               //~v456R~
//                *Ppdbcs=0;                                       //~v456R~
//            }                                                    //~v456R~
//    }                                                            //~v456R~
//#ifndef UNX   //dos,win,os2                                      //~v53hR~
  #ifdef LNX   //lnx                                               //~v53hI~
// if (!UCBITCHK(Gscrstatus,GSCRSDBCS)) //no dbcs mode             //~v53hI~//~v7asR~
   if (!UCBITCHK(Gscrstatus,GSCRSDBCS) //no dbcs mode              //~v7asI~
   ||  !(Gunxflag & GUNX_KON)                                      //~v7asI~
   )                                                               //~v7asI~
  #endif                                                           //~v53hI~
    for (i=0;i<Plen;i++,Ppdata++,Ppdbcs++)                         //~v495I~
    {                                                              //~v495I~
//          if (udbcschk(*Ppdata)                                  //~v73vR~
  #ifdef LNX   //lnx                                               //~v79zI~
    	if (!(Gunxflag & GUNX_KON)) //CONSOLE                      //~v79zI~
            dbcssw=0;                                              //~v79zI~
        else                                                       //~v79zI~
  #endif                                                           //~v79zI~
            dbcssw=udbcschk(*Ppdata);                              //~v73vI~
            if (dbcssw                                             //~v73vI~
            && i<(Plen-1)                                          //~v495I~
//*never called for ebc file                                       //~va50I~
            && !((tabkeepsw && *(Ppdbcs+1)==TABCHAR)))//2nd byte is not tab//~v495I~
            {                                                      //~v495I~
              if (!tabkeepsw && *(Ppdata+1)==TABCHAR)              //~v73vI~
                *Ppdbcs=UDBCSCHK_HKDBCSERR;                        //~v73vI~
              else                                                 //~v73vI~
//            if (!WCMB2ND(0,(Ppdata+1)))   //invalid dbcs 2nd     //~va1cR~
              if (!(dbcstype=WCMB2ND(0,(Ppdata+1))))   //invalid dbcs 2nd//~va1cR~
                *Ppdbcs=UDBCSCHK_HKDBCSERR;                        //~v79zI~
              else                                                 //~v79zI~
              {                                                    //~v73vI~
                UMOVSW(Ppdbcs,Sdbcsid);                            //~v495I~
                Ppdbcs++;                                          //~v495I~
                Ppdata++;                                          //~v495I~
                i++;                                               //~v495I~
              }                                                    //~v73vI~
            }                                                      //~v495I~
            else                                                   //~v495I~
            {                                                      //~v495I~
              if (dbcssw)                                          //~v73vI~
                *Ppdbcs=UDBCSCHK_HKDBCSERR;                        //~v73vI~
              else                                                 //~v73vI~
              if (tabkeepsw)                                       //~v495I~
              {                                                    //~v495I~
//dos,os2 case                                                     //~va1cR~
                if (*Ppdbcs==DBCS1STCHAR||*Ppdbcs==DBCS2NDCHAR)    //~v495I~
                    *Ppdbcs=0;                                     //~v495I~
              }                                                    //~v495I~
              else                                                 //~v495I~
                *Ppdbcs=0;                                         //~v495I~
            }                                                      //~v495I~
    }                                                              //~v495I~
//#else   //UNX   //dos,win,os2                                    //~v53hR~
  #ifdef LNX   //lnx sjis                                          //~v53hI~
   else                                                            //~v53hI~
//  usjischk(Ppdata,Plen,Ppdbcs,tabkeepsw);                        //~v47WR~
    usjischk(Ppdata,Plen,Ppdbcs,0,tabkeepsw);                      //~v47WI~
  #endif //UNX                                                     //~v495I~
    Ppdata=pc0;                                                    //~v74xI~
    Ppdbcs=pcd0;                                                   //~v74xI~
#endif   //!UTF8SUPPH                                              //~vafhI~
#endif //!AIX                                                      //~v30fI~
#ifndef UTF8SUPPH //use external converter                         //~vafhI~
	if (Popt & FSDT_TABSET)                                        //~v74xI~
        setdbcstbltabid(0,0,Ppdata,Ppdbcs,Plen);                   //~v74xR~
UTRACED("filesetdbcstbl out data   ",Ppdata,Plen);                 //~va1cR~
UTRACED("filesetdbcstbl out dbcstbl",Ppdbcs,Plen);                 //~va1cR~
    return 0;                                                      //~v44aR~
#endif   //!UTF8SUPPH                                              //~vafhI~
}//filesetedbcstbl                                                 //~v09YI~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef AAA                                                         //+vagvI~
//*******************************************************          //~va20I~
//*filesetdbcstbl consideration for utf8 file                      //~va20I~
//*rc UALLOC_FAILED; xeutf_cvf2lsetdbcs rc                         //~va20I~
//*******************************************************          //~va20I~
int filesetdbcstblu(int Popt,PULINEH Pplh,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Ppnewlen)//~va20R~
{                                                                  //~va20I~
	PUFILEH pfh;                                                   //~va20I~
    int rc,newlen,opt=0,lenlc;                                     //~va20I~
    UCHAR *plc,*pcd;                                                //~va20I~//~va5tR~
//***************                                                  //~va20I~
	pfh=UGETPFH(Pplh);                                             //~va20I~
    newlen=Plen;                                                   //~va20I~
    if (!FILEUTF8MODE(pfh))	//for also bin file                    //~va20I~
    {                                                              //~va20I~
		rc=filesetdbcstbl(Ppdata,Ppdbcs,Plen,Popt);                //~va20I~
    }                                                              //~va20I~
    else	//utf8 file                                            //~va20I~
    {                                                              //~va20I~
        opt=XEUTFF2LO_SAVECVERRCH|XEUTFF2LO_DDFMT;  		//maintenance by DD fmt//~va20R~
															//keep org value for trans err char//~va20I~
        rc=xeutf_cvf2lsetdbcs(opt,Ppdata,Plen,&plc,&pcd,&lenlc);   //~va20R~
        if (rc!=UALLOC_FAILED)                                     //~va20I~
        {                                                          //~va20I~
	        memcpy(Ppdbcs,pcd,(UINT)lenlc);                        //~va20I~
        	newlen=lenlc;                                          //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    if (Ppnewlen)                                                  //~va20I~
    	*Ppnewlen=newlen;                                          //~va20I~
UTRACED("filesetdbcstblu inp data   ",Ppdata,Plen);                //~va20I~
UTRACED("filesetdbcstblu out dbcstbl",Ppdbcs,Plen);                //~va20I~
    return rc;                                                     //~va20I~
}//filesetedbcstblu                                                //~va20I~
#endif //AAA                                                       //+vagvI~
#endif                                                             //~va20I~
//*******************************************************          //~v74xI~
//*set tabid to dbcstbl                                            //~v74xI~
//*return 1 if tab found                                           //~v74xI~
//*******************************************************          //~v74xI~
int setdbcstbltabid(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~v74xR~
{                                                                  //~v74xI~
    UCHAR *pct,*pcdt;                                              //~v74xI~
    int ii,rc=0;                                                   //~v74xI~
//************************************                             //~v74xI~
	for (ii=0,pct=Pdata,pcdt=Pdbcs;ii<Plen;ii++,pct++,pcdt++)      //~v74xI~
//*never called for ebcfile(caller is filesetdbcstbl)              //~va50I~
        if (*pct==TABCHAR)                                         //~v74xI~
        {                                                          //~v74xI~
        	if (Popt & SDTTI_INIT                                  //~v74xI~
            ||  *pcdt!=UDBCSCHK_HKDBCSERR)	//previously detected as err//~v74xI~
            {                                                      //~v74xI~
            	*pct=' ';                                          //~v74xI~
            	*pcdt=TABCHAR;                                     //~v74xI~
            	rc=1;                                              //~v74xI~
            }                                                      //~v74xI~
        }                                                          //~v74xI~
    if (rc && Pplh && (Popt & SDTTI_SETTABFOUND))                  //~v74xI~
		UCBITON(Pplh->ULHflag2,ULHF2TABFOUND);                     //~v74xI~
    return rc;                                                     //~v74xI~
}//setdbcstbltabid                                                 //~v74xI~
//*******************************************************
//*get next commnad parse
//*******************************************************
void getnextcmd(UCHAR *Pcin,UCHAR *Pcout)
{
    UCHAR *pc;
//************************************
    if (!(pc=strpbrk(Pcin,";")))
        *Pcout=0;
    else    
        strcpy(Pcout,pc+1+strspn(pc+1," "));//drop preceding space
}//getnextcmd

//*******************************************************       //~5224I~
//*get current cmd string(drop pre/post space)                  //~5224I~
//*parm 1:input string                                          //~5224I~
//*parm 2:output string                                         //~5224I~
//*return:string len                                            //~5224I~
//*******************************************************       //~5224I~
int getcmdstr(UCHAR *Pcin,UCHAR *Pcout)                         //~5224I~
{                                                               //~5224I~
    UCHAR *pc;                                                  //~5224I~
    int offs;                                                   //~5224I~
//************************************                          //~5224I~
    *Pcout=0;                                                   //~5224R~
    offs=(int)strspn(Pcin," ");//search non space(start pos)    //~5224I~
    if (offs==(int)strlen(Pcin))                                //~5224I~
        return 0;                                               //~5224I~
    Pcin+=offs;                                                 //~5224I~
    if (!(pc=strpbrk(Pcin,";")))                                //~5224I~
        strcpy(Pcout,Pcin);                                     //~5224I~
    else                                                        //~5224I~
    {                                                           //~5224I~
//      memcpy(Pcout,Pcin,(UINT)(offs=(int)((ULONG)pc-(ULONG)Pcin)));//~5224I~//~vafkR~
        memcpy(Pcout,Pcin,(UINT)(offs=(int)((ULPTR)pc-(ULPTR)Pcin)));//~vafkI~
        *(Pcout+offs)=0;                                        //~5224I~
    }                                                           //~5224I~
    if ((offs=(int)ustrrspn(Pcout," "))>=0)                     //~5224I~
        *(Pcout+offs+1)=0;  //drop space                        //~5224R~
    return (int)strlen(Pcout);                                  //~5224R~
}//getnextcmd                                                   //~5224I~
#ifdef UTF8SUPPH                                                   //~va0gR~
//*******************************************************          //~va0gI~
//*get field input by utf8 code                                    //~va0gI~
//*******************************************************          //~va0gI~
int getfldinput_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pout)//~va0gI~
{                                                                  //~va0gI~
	int rc;                                                        //~va0gI~
//************************                                         //~va0gI~
    UCBITON(Ppcw->UCWflag2,UCWF2CMDGETU8);	//by utf8 code	//parm to getfldpos//~va0gI~
	rc=getfldinput(Ppcw,Prow,Pfldno,Pout);                         //~va0gI~
    UCBITOFF(Ppcw->UCWflag2,UCWF2CMDGETU8);	//reset by utf8 code   //~va0gI~
    return rc;                                                     //~va0gI~
}//getfldinput_utf8                                                //~va0gI~
#endif                                                             //~va0gI~
//*******************************************************
//*get field input(drop preceding space char)
//* parm1: client work
//* parm2: client relative row
//* parm3: fieldno in row
//* parm4: data set to area addr
//* parm5: data len
//*******************************************************
int getfldinput(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pout)
{
    UCHAR *pc,*pc2;                                             //~5129R~
    int len,i;                                                  //~5129R~
//************************
    len=getfldpos(Ppcw,Prow,Pfldno,&pc,0);  //no need dbcstbl   //~v039R~
    if (!len)                           //lineno/fldno err
        return 0;
  	if (Prow==CMDLINENO && Pfldno==0)	//cmdline cmd input fld    //~v730R~
    	len=(int)strlen(pc);			//UPCcmdbuff may longer than fld width//~v730R~
#ifdef UTF8SUPPH                                                   //~va00I~
    else                                                           //~va00I~
    	if (UCBITCHK(Ppcw->UCWflag2,UCWF2CMDGETU8))	//by utf8 code	//parm to getfldpos//~va00I~
	    	len=(int)strlen(pc);			//UPCcmdbuff may longer than fld width//~va00I~
#endif                                                             //~va00I~
    for (i=0;i<len;i++,pc++)
        if (*pc!=' ')
            break;
    for (len-=i,pc2=pc+len-1;len;len--,pc2--)                   //~5129R~
        if (*pc2 && *pc2!=' ')                                  //~5129R~
            break;
    memcpy(Pout,pc,(UINT)len);                                  //~5129R~
    *(Pout+len)=0;                                              //~5129R~
    return len;                                                 //~5129R~
}//getfldinput
                                                                //~v020I~
//*******************************************************
//*set field output(drop preceding space char)
//* parm1: client work
//* parm2: client relative row
//* parm3: fieldno in row(0 start)                              //~5611R~
//* parm4: data set from addr
//* return:data len
//*******************************************************
int setflddata(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)
{
    UCHAR *pc,*pcd;                                             //~v039R~
    int len;
//************************
  	if (Prow==CMDLINENO && Pfldno==0)	//cmdline cmd input fld    //~v730I~
#ifdef UTF8SUPPH                                                   //~va00R~
#ifdef EEE                                                         //~va00I~
    	return BYUTF8_setflddatacmd(0,Ppcw,Pdata);                 //~va0gR~//~va00R~
#else                                                              //~va00I~
//		return setflddatadbcscmd_byutf8(SFDDCUO_FULLREP,Ppcw,0/*pos*/,Pdata,0/*Pdbcs*/,strlen(Pdata));//~va00R~//~vb06R
  		return setflddatadbcscmd_byutf8(SFDDCUO_FULLREP,Ppcw,0/*pos*/,Pdata,0/*Pdbcs*/,(int)strlen(Pdata));//~va00R~//~vb06I
#endif                                                             //~va00I~
#else                                                              //~va00R~
    	return setflddatacmd(Ppcw,Pdata);                          //~v730I~
#endif                                                             //~va00R~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef CCC                                                         //~va00M~
    if (!UCBITCHK(Ppcw->UCWflag2,UCWF2SETFLD))	//not recursive call//~va00I~
    {                                                              //~va00I~
        switch(((PUPANELC)Ppcw->UCWppc)->UPCid)                    //~va00R~
        {                                                          //~va00R~
        case PANFNAME  :        //filename                         //~va00R~
            return pan300setflddata_utf8(Ppcw,Prow,Pfldno,Pdata);  //~va00R~
        case PANUCOMP  :        //compare utility                  //~va00R~
            return pancompsetflddata_utf8(Ppcw,Prow,Pfldno,Pdata); //~va00R~
        case PANUGREP  :        //grep utility panel               //~va00R~
            return pangrepsetflddata_utf8(Ppcw,Prow,Pfldno,Pdata); //~va00R~
        }                                                          //~va00R~
    }                                                              //~va00I~
#endif                                                             //~va00M~
#endif                                                             //~va00I~
    len=getfldpos(Ppcw,Prow,Pfldno,&pc,&pcd);                   //~v039R~
    if (!len)                           //lineno/fldno err
        return 0;
    strncpy(pc,Pdata,(UINT)len);
    if (*Pdata)     //data exist                                //~v039I~
        setdbcstbl(pc,pcd,len);             //reset dbcstbl     //~v039R~
    else                                                        //~v039I~
        memset(pcd,0,(UINT)len);            //all clear         //~v039I~
    UTRACED("data",pc,len);                                        //~vak5I
    UTRACED("ddbcs",pcd,len);                                      //~vak5R
    UCBITON(((PUSCRD)(Ppcw->UCWpsd)+Prow)->USDflag2,USDF2DRAW);
    return min(len,(int)strlen(Pdata));                            //~v085R~
}//setflddata
                                                                //~v020I~
                                                                   //~va5tI~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~va5tI~
//*set field by dd fmt data(except cmdline)                        //~va5tI~
//*******************************************************          //~va5tI~
int setflddatadd(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~va5tR~
{                                                                  //~va5tI~
    UCHAR *pc,*pcd;                                                //~va5tI~
    int len,ddlen,reslen;                                          //~va5tI~
//************************                                         //~va5tI~
    len=getfldpos(Ppcw,Prow,Pfldno,&pc,&pcd);                      //~va5tI~
    if (!len)                           //lineno/fldno err         //~va5tI~
        return 0;                                                  //~va5tI~
    ddlen=min(len-1,Plen);                                         //~va5tR~
    memcpy(pc,Pdata,(UINT)ddlen);                                  //~va5tI~
    memcpy(pcd,Pdbcs,(UINT)ddlen);                                 //~va5tI~
    reslen=len-ddlen;                                              //~va5tI~
    memset(pc+ddlen,0,(UINT)reslen);                               //~va5tR~
    memset(pcd+ddlen,0,(UINT)reslen);                              //~va5tR~
    UCBITON(((PUSCRD)(Ppcw->UCWpsd)+Prow)->USDflag2,USDF2DRAW);    //~va5tI~
    return ddlen;                                                  //~va5tI~
}//setflddatadd                                                    //~va5tI~
//**************************************************               //~va00I~
//manipulate fld data width dbcs                                   //~va00I~
//called from pan23 for 3.12 opt line(no utf8 buff prepared case)  //~va50I~
//len:input,if <0,get by strlen                                    //~va00I~
//*dbcstbl:input                                                   //~va00I~
//rc:UALLOC_FAILED,4:pos out of range                              //~va00I~
//**************************************************               //~va00I~
int setflddatadbcs(int Popt,char *Ptgt,char *Ptgtdbcs,int Ptgtlen,int *Pptgtlen,//~va00R~
					int Ptgtpos,int Ptgtwidth,char *Psrc,char *Psrcdbcs,int Psrclen)//~va00R~
{                                                                  //~va00I~
    int srclen,tgtlen,overwraplen;                                 //~va00R~
    int pos,len,width,strzsw,cutlen;                               //~va00R~
    char *tgt,*tgtdbcs;                                            //~va00I~
//****************************                                     //~va00I~
	width=Ptgtwidth;                                               //~va00I~
    if (Popt & SFDDO_STRZ)                                         //~va00I~
    	width--;                                                   //~va00I~
    if (Ptgtpos>=width)                                            //~va00I~
    	return 4;		//out of field width                       //~va00I~
	if (tgtlen=Ptgtlen,tgtlen<0)                                   //~va00I~
		tgtlen=(int)strlen(Ptgt);                                  //~va00I~
	if (srclen=Psrclen,srclen<0)                                   //~va00I~
		srclen=(int)strlen(Psrc);                                  //~va00I~
UTRACEP("setflddatadbcs in tgtlen=%d,srclen=%d,pos=%d,fldwidth=%d\n",tgtlen,srclen,Ptgtpos,Ptgtwidth);//~va00I~
UTRACED("tgt",Ptgt,tgtlen);                                        //~va00I~
UTRACED("tgtDBCS",Ptgtdbcs,tgtlen);                                //~va00I~
UTRACED("src",Psrc,srclen);                                        //~va00I~
UTRACED("srcDBCS",Psrcdbcs,srclen);                                //~va00I~
    tgt=Ptgt+Ptgtpos;                                              //~va00R~
    tgtdbcs=Ptgtdbcs+Ptgtpos;                                      //~va00I~
    overwraplen=tgtlen-Ptgtpos;                                    //~va00R~
    strzsw=1;                                                      //~va00I~
    if (overwraplen<=0)	//append case                              //~va00I~
    {                                                              //~va00I~
    	overwraplen=-overwraplen;                                  //~va00I~
        if (overwraplen)                                           //~va00I~
        {                                                          //~va00I~
            memset(tgt-overwraplen,' ',(UINT)overwraplen);         //~va00I~
            memset(tgtdbcs-overwraplen,0,(UINT)overwraplen);       //~va00I~
        }                                                          //~va00I~
        tgtlen+=overwraplen+srclen;                                //~va00R~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
    	if (Ptgtpos)                                               //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5tI~
	    	xesub_setdbcssplit(0,0/*plh*/,Ptgt,Ptgtdbcs,Ptgtpos,' ');//~va5tR~
#else                                                              //~va5tI~
	    	setdbcssplit(Ptgt,Ptgtdbcs,Ptgtpos,' ');               //~va00R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5tI~
    	if (Popt & SFDDO_INS)                                      //~va00I~
        {                                                          //~va00I~
        	cutlen=0;                                              //~va00I~
        	if (Ptgtpos+srclen<width) 	//remains to be shift      //~va00I~
            {                                                      //~va00I~
                len=tgtlen-Ptgtpos;   //right half                 //~va00I~
                if (tgtlen+srclen>width)	//overflow by shift    //~va00I~
                {                                                  //~va00I~
                	cutlen=tgtlen+srclen-width;                    //~va00I~
                	len-=cutlen;                                   //~va00I~
                }                                                  //~va00I~
                memmove(tgt+srclen,tgt,(UINT)len);                 //~va00I~
    			if (Popt & XEUTFMSUO_STRZ)                         //~va00I~
	                *(tgt+srclen+len)=0;                           //~va00I~
                memmove(tgtdbcs+srclen,tgtdbcs,(UINT)len);         //~va00I~
                strzsw=0;                                          //~va00I~
            }                                                      //~va00I~
            tgtlen+=srclen;                                        //~va00R~
            tgtlen-=cutlen;                                        //~va00I~
        }                                                          //~va00I~
        else	//override                                         //~va00I~
        {                                                          //~va00I~
        	pos=Ptgtpos+srclen; //right end                        //~va00I~
            if (pos<tgtlen)	//in the fld width                     //~va00I~
            {                                                      //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				setobtabdbcs(0,0/*plh*/,Ptgt,Ptgtdbcs,tgtlen,0/*no left boundary*/,pos/*right boundary*/);//~va50I~
#else                                                              //~va50I~
				setobtabdbcs(Ptgt,Ptgtdbcs,tgtlen,0/*no left boundary*/,pos/*right boundary*/);//~va00R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                strzsw=0;                                          //~va00I~
            }                                                      //~va00I~
            else  //overwrite tgt end of line                      //~va00I~
            {                                                      //~va00I~
		        tgtlen=Ptgtpos+srclen;                             //~va00I~
            }                                                      //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
    if (srclen>width-Ptgtpos)     //overflow                       //~va00I~
    {                                                              //~va00I~
        len=width-Ptgtpos;                                         //~va00I~
        tgtlen-=srclen-len;                                        //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
        len=srclen;                                                //~va00R~
    }                                                              //~va00I~
    if (len>0)                                                     //~va00I~
    {                                                              //~va00I~
    	memcpy(tgt,Psrc,(UINT)len);                                //~va00I~
    	memcpy(tgtdbcs,Psrcdbcs,(UINT)len);                        //~va00I~
		chartabclear(tgtdbcs,len);                                 //~va00R~
    }                                                              //~va00I~
    if (Pptgtlen)                                                  //~va00I~
	    *Pptgtlen=tgtlen;                                          //~va00R~
    if (strzsw && Popt & XEUTFMSUO_STRZ)                           //~va00I~
    {                                                              //~va00I~
       *(Ptgt+tgtlen)=0;                                           //~va00I~
    }                                                              //~va00I~
UTRACEP("setflddatadbcs out len=%d\n",tgtlen);                     //~va00I~
UTRACED("LC",Ptgt,tgtlen);                                         //~va00I~
UTRACED("DBCS",Ptgtdbcs,tgtlen);                                   //~va00R~
	return 0;                                                      //~va00I~
}//setflddatadbcs                                                  //~va00I~
#endif                                                             //~va00I~
                                                                   //~va00I~
//*******************************************************
//*get field position
//* parm1: client work
//* parm2: client relative row(start from 0)
//* parm3: fieldno in row   (start from 0)
//* parm4: out area addr
//* parm5: out dbcs tbl area addr                               //~v039I~
//* return:field len
//*******************************************************
int getfldpos(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR **Pout,UCHAR **Pdbcs)//~v039R~
{
    PUPANELC ppc;
    UFLD    *pfl;
    UCHAR *pc;
    int len;
#ifdef UTF8SUPPH                                                   //~va0gI~
    PUPANELL pupl;                                                 //~va00I~
    UCHAR *pu8=0;                                                  //~va00R~
#endif                                                             //~va0gR~
//************************
    ppc=Ppcw->UCWppc;
  if (Prow==CMDLINENO && Pfldno==0)	//cmdline cmd input fld        //~v730R~
  {                                                                //~va00I~
#ifdef UTF8SUPPH                                                   //~va00R~
#ifdef FFF                                                         //~va00I~
   if (UCBITCHK(Ppcw->UCWflag2,UCWF2CMDGETU8) && UCBITCHK(ppc->UPCflag,UPCFCMDUTF8))//cmd by utf8//~va00R~
    pc=pu8=ppc->UPCcmddatabyutf8;                                  //~va00R~
#else                                                              //~va00I~
    pu8=ppc->UPCcmddatabyutf8;                                     //~va00I~
   if (UCBITCHK(Ppcw->UCWflag2,UCWF2CMDGETU8) && pu8)//cmd by utf8 //~va00I~
    pc=pu8;                                                        //~va00I~
#endif                                                             //~va00I~
   else                                                            //~va00R~
#endif                                                             //~va00I~
    pc=ppc->UPCcmddata;                                            //~v730R~
  }                                                                //~va00I~
  else                                                             //~v730R~
  {                                                                //~va00I~
    pc=ppc->UPCline[Prow].UPLbuff;      //cmd buff;
#ifdef UTF8SUPPH                                                   //~va00I~
  #ifdef AAA                                                       //~va0gI~
    switch(((PUPANELC)Ppcw->UCWppc)->UPCid)                        //~va00R~
    {                                                              //~va00R~
    case PANFNAME  :        //filename                             //~va00R~
        pc=pan300getfldpos_utf8(Ppcw,Prow,-1/*topaddr*/,pc);//update pc for utf8 code//~va0gR~
        break;                                                     //~va00I~
    case PANUCOMP  :        //compare utility                      //~va00R~
        pc=pancompgetfldpos_utf8(Ppcw,Prow,-1/*top addr*/,pc);     //~va0gR~
        break;                                                     //~va00I~
    case PANUGREP  :        //grep utility panel                   //~va00R~
        pc=pangrepgetfldpos_utf8(Ppcw,Prow,-1/*top addr*/,pc);     //~va0gR~
        break;                                                     //~va00I~
    }                                                              //~va00R~
  #else                                                            //~va00M~
    if (UCBITCHK(Ppcw->UCWflag2,UCWF2CMDGETU8))	//by utf8 code     //~va00M~
    {                                                              //~va00M~
    	pupl=ppc->UPCline+Prow;                                    //~va00I~
    	if (pupl->UPLflags & UPLFUTF8)	//utf8 code                //~va00I~
	    	pc=pu8=pupl->UPLbuffbyutf8;      //cmd buff;           //~va00I~
    }                                                              //~va00M~
  #endif                                                           //~va00M~
#endif                                                             //~va00M~
  }                                                                //~va00I~
    pfl=ppc->UPCline[Prow].UPLpfld;     //UFLD ptr              //~v032I~
    if (!pc || !pfl)                            //line protected   //~v076R~
        return 0;
    if (Pfldno>=pfl->UFLctr)            //fieldno parm err
        return 0;
    len=pfl->UFLentry[Pfldno].UFLend-pfl->UFLentry[Pfldno].UFLstart;
#ifdef UTF8SUPPH                                                   //~va00I~
  if (pc!=pu8)	//pu8 is fld top                                   //~va00I~
#endif                                                             //~va00I~
    pc+=pfl->UFLentry[Pfldno].UFLstart; //field addr
    *Pout=pc;
    if (Pdbcs)                                                  //~v039I~
    {                                                              //~v730I~
     if (Prow==CMDLINENO && Pfldno==0)	//cmdline cmd input fld    //~v730R~
        *Pdbcs=ppc->UPCcmddbcs+pfl->UFLentry[Pfldno].UFLstart;     //~v730I~
     else                                                          //~v730R~
        *Pdbcs=ppc->UPCline[Prow].UPLdbcs+pfl->UFLentry[Pfldno].UFLstart;//~v039I~
    }                                                              //~v730I~
    return len;
}//getfldpos                                                    //~v020R~
                                                                //~v020I~
//**************************************************************** //+vb4hI~//~vb4hM
int getfldstrlen(int Popt,char *Pdata,char *Pdbcs,int Pfldsz)   //+vb4hI~//~vb4hI
{                                                                  //+vb4hI~//~vb4hM
	char *pc;                                                  //+vb4hI~//~vb4hR
    int len=0,ll,reslen;                                           //+vb4hI~//~vb4hM
//********************                                             //+vb4hI~//~vb4hM
    UTRACED("Pdata",Pdata,Pfldsz);                                 //~vb4hM
    UTRACED("Pdbcs",Pdbcs,Pfldsz);                                 //~vb4hM
	for (pc=Pdata,reslen=Pfldsz;reslen>0;)               //+vb4hI~ //~vb4hI
    {                                                              //+vb4hI~//~vb4hM
	    ll=(int)ustrnlen(pc,(unsigned int)reslen);                                //+vb4hI~//~vb4hR
        len+=ll;                                                   //+vb4hI~//~vb4hM
        if (!Pdbcs)                                                //~vb4hI
        	break;                                                 //~vb4hI
        if (!*(Pdbcs+len))                                            //+vb4hI~//~vb4hI
        	break;                                                 //+vb4hI~//~vb4hM
        len++;                                                     //~vb4hI
        ll++;                                                      //~vb4hI
        reslen-=ll;                                                //~vb4hR
        pc+=ll;                                                    //~vb4hI
    }                                                              //+vb4hI~//~vb4hM
    UTRACEP("%s:fldsz=%d,len=%d\n",UTT,Pfldsz,len);                //~vb4hI
    return len;                                                    //~vb4hI
}//pangetfldstrlen                                                 //+vb4hI~//~vb4hM
//**************************************************            //~5423I~
//*input fld protect chk                                        //~5423I~
//*parm 1:client work element                                   //~5423I~
//*parm 2:dbcs 2nd byte chk option                              //~5423I~
//*parm 3:UFLD output addr                                      //~v020I~
//*return:ufld index ,if protected return -1                    //~5423I~
//**************************************************            //~5423I~
int fldprotchk(PUCLIENTWE Ppcw,int Popt,PVOID Pppfld)           //~v020R~
{                                                               //~4C23I~
    int i,loop;                                                 //~4C23I~
    int x,inputlen;                                             //~4C23I~
    PUFLD pfld;                                                 //~4C23I~
    PUSCRD psd;                                                 //~4C23I~
    PUFLD *ppfld;                                               //~v020I~
//*************                                                 //~4C23I~
    Ppcw->UCWfleno=-1;      //clear not found                   //~4C29I~
    if (Ppcw->UCWrcsry>=Ppcw->UCWmaxline)                       //~5111R~
        return -1;                                              //~5111I~
    psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                            //~5111I~
    if (UCBITCHK(psd->USDflag2,USDF2PROT|USDF2PROTONLY))//v020  //~5611R~
        return -1;                                              //~4C23I~
    x=Ppcw->UCWrcsrx;                                           //~4C23I~
    pfld=psd->USDpfld;                                          //~v032I~
    loop=pfld->UFLctr;                                          //~4C23I~
    inputlen=Ppcw->UCWkeytype;      //sbcs or dbcs              //~4C23I~
    for (i=0;i<loop;i++)                                        //~4C23I~
    {                                                           //~4C23I~
        if (x<pfld->UFLentry[i].UFLstart)                       //~4C23I~
            return -1;                                          //~4C23I~
        if (x<pfld->UFLentry[i].UFLend)                         //~4C23I~
        {                                                       //~4C23I~
            if (UCBITCHK(pfld->UFLentry[i].UFLflag,UFLEFPROT))//v020//~5611I~
                return -1;                                    //v020//~5611I~
            if (inputlen==2)    //dbcs                          //~4C23I~
                if (Popt==FPC_DBCSCHK)                          //~5423I~
                    if ((x+1)==pfld->UFLentry[i].UFLend)        //~5423R~
                    {                                           //~v03bI~
                        if (x==pfld->UFLentry[i].UFLstart)  //1 byte fld//~v03bI~
#ifdef UTF8SUPPH                                                   //~va0gI~
                        {                                          //~va0gI~
#endif                                                             //~va0gI~
                            errdbcsinput();                     //~v03bI~
#ifdef UTF8SUPPH                                                   //~va0gI~
                            return -2;                             //~va0gR~
                        }                                          //~va0gI~
#endif                                                             //~va0gI~
                        return -1;                              //~5423R~
                    }                                           //~v03bI~
            Ppcw->UCWfleno=i;                                   //~4C29I~
            if (Pppfld)                                         //~v020I~
            {                                                   //~v020I~
                ppfld=Pppfld;   //data conv                     //~v020I~
                *ppfld=pfld;   //return pfld addr               //~v020R~
            }                                                   //~v020I~
            return i;   //in the fld                            //~4C23I~
        }                                                       //~4C23I~
    }                                                           //~4C23I~
    return -1;          //out of any fld                        //~4C23I~
}//fldprotchk                                                   //~5503R~
                                                                //~5103I~
//*******************************************************       //~v020M~
//*get UFLDE addr                                               //~v020M~
//* parm1: client work                                          //~v020M~
//* parm2: client relative row(start from 0)                    //~v020M~
//* parm3: fieldno in row(start from 0)                         //~v020M~
//* return:UFLDE addr                                           //~v020M~
//*******************************************************       //~v020M~
PVOID getuflde(PUCLIENTWE Ppcw,int Prow,int Pfldno)             //~v020R~
{                                                               //~v020M~
    PUPANELC ppc;                                               //~v020M~
    UFLD    *pfl;                                               //~v020M~
//************************                                      //~v020M~
    ppc=Ppcw->UCWppc;                                           //~v020M~
    pfl=ppc->UPCline[Prow].UPLpfld; //ufld                      //~v032R~
    return &pfl->UFLentry[Pfldno];                              //~v020M~
}//getuflde                                                     //~v020I~
                                                                //~v020M~
//*******************************************************          //~v78ZI~
//*get home position                                               //~v78ZI~
//*return cmdline rposx                                            //~v78ZI~
//*******************************************************          //~v78ZI~
int gethomepos(int Popt,PUCLIENTWE Ppcw)                           //~v78ZR~
{                                                                  //~v78ZI~
    UFLDE    *pfle;                                                //~v78ZI~
//************************                                         //~v78ZI~
    pfle=getuflde(Ppcw,CMDLINENO,0);                               //~v78ZI~
    return pfle->UFLstart;                                         //~v78ZI~
}//gethomepos                                                      //~v78ZI~
                                                                   //~v78ZI~
//**************************************************            //~5103I~
//*setdbcssplit                                                 //~5103I~
//*ajust DBCS half cut data(inner left/right boundary data)     //~5503R~
//*Left boudary:Pdata, Right boundary:Pdata+Plen                   //~va1cR~
//*parm 1:data                                                  //~5103I~
//*parm 2:dbcstbl                                               //~5103I~
//*parm 3:len                                                   //~5103I~
//*parm 4:repl data when split detected,if ' ' reple dbcs tbl also//~5103R~
//*return:0:no dbcs change,1:cut at top,2:cut at end,3 both     //~5103I~
//**************************************************            //~5103I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5tI~
int setdbcssplit(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar)//~va5tR~
#else                                                              //~va5tI~
int setdbcssplit(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar)//~5103I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5tI~
{                                                               //~5103I~
    int rc=0;                                                   //~5103I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int opt;                                                       //~va1cR~
#endif                                                             //~va1cR~
//*************                                                 //~5103I~
    if (!Plen)                                                  //~5103I~
        return rc;                                              //~5103I~
#ifdef UTF8SUPPH                                                   //~va1cR~
	opt=XESUBCDSO_LEFT|XESUBCDSO_IFREPBYSPACE;                     //~va1cR~
    rc+=(xesub_cleardbcssplit(opt,Pdata,Pdbcs,Plen,Prepchar)>0);   //~va1cR~
#else                                                              //~va1cR~
    if (*Pdbcs==DBCS2NDCHAR)    //start with second byte        //~5103I~
    {                                                           //~5103I~
        if (Prepchar==' ')                                      //~5103I~
            *Pdbcs=0;                                           //~5103R~
        *Pdata=Prepchar;                                        //~5103I~
        rc=1;                                                   //~5103I~
    }                                                           //~5103I~
#endif                                                             //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
	opt=XESUBCDSO_RIGHT|XESUBCDSO_IFREPBYSPACE;                    //~va1cR~
    if (xesub_cleardbcssplit(opt,Pdata,Pdbcs,Plen,Prepchar))       //~va1cR~
        rc+=2;                                                     //~va1cR~
#else                                                              //~va1cR~
    if (*(Pdbcs+Plen-1)==DBCS1STCHAR)   //end with first byte   //~5103I~
    {                                                           //~5103I~
//      if (Prepchar==' ')                                      //~5103I~//~va0iR~
            *(Pdbcs+Plen-1)=0;                                  //~5103R~
        *(Pdata+Plen-1)=Prepchar;                               //~5103I~
        rc+=2;                                                  //~5103I~
    }                                                           //~5103I~
#endif                                                             //~va1cR~
    return rc;                                                  //~5103I~
}//setdbcssplit                                                 //~5103I~
//**************************************************               //~v40wI~
//*setdbcssplit2                                                   //~v40wI~
//*ajust DBCS half cut data(inner left/right boundary data)        //~v40wI~
//*      by dbcstbl and actual data for screen display             //~v40wI~
//*parm 1:data                                                     //~v40wI~
//*parm 2:dbcstbl                                                  //~v40wI~
//*parm 3:len                                                      //~v40wI~
//*parm 4:repl data when split detected,if ' ' reple dbcs tbl also //~v40wI~
//*return:0:no dbcs change,1:cut at top,2:cut at end,3 both        //~v40wI~
//**************************************************               //~v40wI~
//int setdbcssplit2(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar)//~v40wI~//~vb28R
int setdbcssplit2(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar,UCHAR Prepdbcs)//~v40wI~//~vb28R
{                                                                  //~v40wI~
    int rc=0;                                                      //~v40wI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int opt;                                                       //~va1cR~
#else                                                              //~va1cR~
    int ch;                                                        //~v40wI~
#endif                                                             //~va1cR~
//*************                                                    //~v40wI~
    UTRACEP("%s:Prepch=%x,Prepdbcs=%x\n",UTT,Prepchar,Prepdbcs);   //~vb28I
    if (!Plen)                                                     //~v40wI~
        return rc;                                                 //~v40wI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	opt=XESUBCDSO_LEFT|XESUBCDSO_IFREPBYSPACE;                     //~va1cR~
    opt|=Prepdbcs<<XESUBCDSO_REPDBCSSHIFT;                         //~vb28I
    rc+=(xesub_cleardbcssplit(opt,Pdata,Pdbcs,Plen,Prepchar)>0);   //~va1cR~
#else                                                              //~va1cR~
    if (*Pdbcs==DBCS2NDCHAR)    //start with second byte           //~v40wI~
    {                                                              //~v40wI~
        if (Prepchar==' ')                                         //~v40wI~
            *Pdbcs=0;                                              //~v40wI~
        *Pdata=Prepchar;                                           //~v40wI~
        rc=1;                                                      //~v40wI~
    }                                                              //~v40wI~
#endif                                                             //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
	opt=XESUBCDSO_RIGHT;                                           //~va1cR~
	opt|=XESUBCDSO_IFREPBYSPACE;  //no set dbcs=0 when split       //~vb28I
#endif                                                             //~va1cR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R
#ifdef UTF8UCS416        //FIXME test surrogate  :FIXED                                          //~va3xI~//~vaw1I//~vawdR
    switch (UDBCSCHK_TEMPDBCSID(*(Pdbcs+Plen-1)))                  //~va3xI~
#else                                                              //~va3xI~
    switch (*(Pdbcs+Plen-1))                                       //~v40wI~
#endif                                                             //~va3xI~
	{                                                              //~v40wI~
	case DBCS1STCHAR:   //end with first byte                      //~v40wI~
#ifdef UTF8UCS2                                                    //~va1FI~
	case UDBCSCHK_DBCS1STUCS_CASE():                               //~va1FI~
#endif                                                             //~va1FI~
        rc+=2;                                                     //~v40wI~
        break;                                                     //~v40wI~
	case DBCS2NDCHAR:   //end normal                               //~v40wI~
#ifdef UTF8UCS2                                                    //~va1FI~
	case UDBCSCHK_DBCS2NDUCS_CASE():                               //~va1FI~
#endif                                                             //~va1FI~
        break;                                                     //~v40wI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	case UDBCSCHK_DBCSPAD:   //ss3 or gb4                          //~va1cR~
        rc+=2;                                                     //~va1cR~
        break;                                                     //~va1cR~
#endif                                                             //~va1cR~
    default:                                                       //~v40wI~
#ifdef UTF8SUPPH                                                   //~va1cR~
		opt|=XESUBCDSO_RESETERR;                                   //~va1cR~
        rc+=2;                                                     //~va1cR~
#else                                                              //~va1cR~
		ch=*(Pdata+Plen-1);                                        //~v40wR~
#ifdef UNX                                                         //~v40wI~
	#ifdef AIX                                                     //~v40wI~
      if (UCBITCHK(Gscrstatus,GSCRSDBCS)) //dbcs mode              //~v73xI~
		if (SJIS1(ch))                                             //~v40wI~
        	rc+=2;                                                 //~v40wI~
	#else	//LNX                                                  //~v40wI~
	  #ifdef UTF8SUPPH                                             //~va1cR~
    	if (UDBCSCHK_ISDBCS1ST(ch))	//CJK LeadByte  non the less SJIS/EUC 1st byte//~va1cR~
	  #else                                                        //~va1cR~
    	if ((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON)) //under kon//~v40wI~
        {                                                          //~v79zI~
			if (ISEUC(ch))                                         //~v40wI~
	        	rc+=2;                                             //~v40wI~
        }                                                          //~v79zI~
        else                                                       //~v79zI~
    	if (WCMB1ST(ch))	//CJK LeadByte  non the less SJIS/EUC 1st byte//~v79zI~
	  #endif        	                                           //~va1cR~
        {                                                          //~v79zI~
	        rc+=2;                                                 //~v79zI~
        }                                                          //~v79zI~
    #endif                                                         //~v40wI~
#else                                                              //~v40wI~
//  	if (SJIS1(ch))                                             //~v79zR~
//  	if (WCMB1ST_J(ch))	//CJK LeadByte  or SJIS/EUC 1st byte   //~va1cR~
    	if (SJIS1(ch))                                             //~va1cR~
        	rc+=2;                                                 //~v40wI~
#endif                                                             //~v40wI~
#endif  //!UTF8SUPPH                                               //~va1cR~
    }//switch by dbcstbl                                           //~v40wI~
    if (rc & 2)   //dbcs split                                     //~v40wI~
    {                                                              //~v40wI~
#ifdef UTF8SUPPH                                                   //~va1cR~
        opt|=Prepdbcs<<XESUBCDSO_REPDBCSSHIFT;                     //~vb28I
    	xesub_cleardbcssplit(opt,Pdata,Pdbcs,Plen,Prepchar);       //~va1cR~
#else                                                              //~va1cR~
//      if (Prepchar==' ')                                         //~v40wI~//~va0iR~
            *(Pdbcs+Plen-1)=0;                                     //~v40wI~
        *(Pdata+Plen-1)=Prepchar;                                  //~v40wI~
#endif	//!UTF8SUPPH                                               //~va1cR~
    }                                                              //~v40wI~
    UTRACED("data",Pdata,Plen);                                    //~vb28I
    UTRACED("dbcs",Pdbcs,Plen);                                    //~vb28I
    return rc;                                                     //~v40wI~
}//setdbcssplit2                                                   //~v40wI~
//**************************************************            //~5503I~
//*setobtabdbcs                                                 //~5503I~
//*repl by space of cut TAB/DBCS on left/right outer boundary   //~5503I~
//*parm 1:data                                                  //~5503I~
//*parm 2:dbcstbl                                               //~5503I~
//*parm 3:source len                                            //~5503I~
//*parm 4:start(left) pos of box range                          //~5503I~
//*parm 5:len of box range                                      //~5503I~
//*return:0:no action executed                                     //~va7LR~
//**************************************************            //~5503I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int setobtabdbcs(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen)//~va50R~
#else                                                              //~va50I~
void setobtabdbcs(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,//~5503I~
                    int Prangelen)                              //~5503I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
{                                                               //~5503I~
    int     rightpos;                                           //~5503I~
    UCHAR   *pcd;                                               //~5503I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int opt;                                                       //~va1cR~
#endif                                                             //~va1cR~
	int rc;                                                        //~va7LI~
//*************                                                 //~5503I~
	if ((Popt & SOTDO_EBCMASK)                                     //~va50I~
    ||  (Pplh && PLH_ISEBC(Pplh))                                  //~va50R~
    )                                                              //~va50I~
    {                                                              //~va7LI~
        rc=0;                                                      //~va7LM~
	  	if (Popt & SOTDO_NOSBCSIFEBC)  //dbcs consideration if EBC file//~va8jI~//~va7LM~
        {                                                          //~va7LM~
        	opt=0;                                                 //~va8wI~
            if (Popt & SOTDO_NOSOSIDBCSCONCAT)   //allow DBCS string concatination w/o SOSI//~va8wI~
            	opt|=XEEBCSDSOBO_NOSOSIDBCSCONCAT;   //allow DBCS string concatination w/o SOSI//~va8wI~
//  		xeebc_setdbcssplitsetsosiOB(0,Pdata,Pdbcs,Pdatalen,Ppos,Prangelen,CHAR_EBC_SPACE);//~va7LR~//~va8wR~
    		xeebc_setdbcssplitsetsosiOB(opt,Pdata,Pdbcs,Pdatalen,Ppos,Prangelen,CHAR_EBC_SPACE);//~va8wI~
            rc=1;                                                  //~va7LM~
        }                                                          //~va7LM~
//  	return 0;                                                  //~va50I~//~va7LR~
    	return rc;                                                 //~va7LR~
    }                                                              //~va7LI~
    if (Ppos>0 && Ppos<Pdatalen)    //left boundary on data     //~5506R~
    {                                                           //~5503I~
//*chk dbcs on the left boundary                                //~5503I~
//      if (*(pcd=Pdbcs+Ppos)==DBCS2NDCHAR) //left boundery on the dbcs//~v74WR~
#ifdef UTF8SUPPH                                                   //~va1cR~
        pcd=Pdbcs+Ppos;                //split pos                 //~va1cR~
        if (UDBCSCHK_DBCSNOT1ST(*pcd)  //left boundery on the dbcs //~va1cR~
        ||  UDBCSCHK_DBCSNOTEND(*(pcd-1)))//left boundery on the dbcs//~va1cR~
#else                                                              //~va1cR~
        if (*(pcd=Pdbcs+Ppos)==DBCS2NDCHAR  //left boundery on the dbcs//~v74WI~
        ||  *(pcd-1)==DBCS1STCHAR) //left boundery on the dbcs     //~v74WI~
#endif                                                             //~va1cR~
        {                                                       //~5503I~
#ifdef UTF8SUPPH                                                   //~va1cR~
			opt=XESUBCDSO_RIGHT;                                   //~va1cR~
    		xesub_cleardbcssplit(opt,Pdata,Pdbcs,Ppos,' ');        //~va1cR~
#else                                                              //~va1cR~
            *(Pdata+Ppos-1)=' ';                                //~5503I~
            *(pcd-1)=0;                                         //~5503I~
#endif                                                             //~va1cR~
        }                                                       //~5503I~
        else                                                    //~5503I~
//del tab at left boundary                                      //~5503I~
            if (*pcd==TABPADCHAR)   //tab effect into the range from left//~5503R~
            {                                                   //~5503I~
                for (pcd--;*pcd==TABPADCHAR;pcd--)              //~5503R~
                    *pcd=0; //reset boundary tab                //~5503I~
                *pcd=0;     //tab char                          //~5503I~
            }                                                   //~5503I~
    }//left                                                     //~5503I~
//*                                                             //~5503I~
    if ((rightpos=Ppos+Prangelen)<Pdatalen && rightpos >0)  //data exist on the right//~5506R~
    {                                                           //~5503I~
//*chk dbcs on the right boundary                               //~5503I~
#ifdef UTF8SUPPH                                                   //~va1cR~
        pcd=Pdbcs+rightpos;                                        //~va1cR~
		opt=XESUBCDSO_LEFT;                                        //~va1cR~
    	xesub_cleardbcssplit(opt,Pdata+rightpos,pcd,Pdatalen-rightpos,' ');//~va1cR~
#else                                                              //~va1cR~
        if (*(pcd=Pdbcs+rightpos)==DBCS2NDCHAR)//right boundary on the DBCS//~5503I~
        {                                                       //~5503I~
            *(Pdata+rightpos)=' ';                              //~5503I~
            *(pcd)=0;                                           //~5503I~
        }                                                       //~5503I~
        else                                                    //~5503I~
#endif        	                                                   //~va1cR~
//del tab at right boundary                                     //~5503I~
            for (;*pcd==TABPADCHAR;pcd++)                       //~5503I~
                *pcd=0; //reset boundary tab                    //~5503I~
    }//right data exist                                         //~5503I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    return 1;                                                      //~va50I~
#else                                                              //~va50I~
    return;                                                     //~5503I~
#endif                                                             //~va50I~
}//setobtabdbcs                                                    //~v44aR~
//**************************************************               //~v74WI~
//*setobtabclear                                                   //~v74WI~
//*repl by space of cut TAB on left/right outer boundary           //~v74WI~
//*return:none                                                     //~v74WI~
//**************************************************               //~v74WI~
int setobtabclear(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen)//~v74WI~
{                                                                  //~v74WI~
    int     rightpos,rc=0;                                         //~v74WI~
    UCHAR   *pcd;                                                  //~v74WI~
//*************                                                    //~v74WI~
    if (Ppos>0 && Ppos<Pdatalen)    //left boundary on data        //~v74WI~
    {                                                              //~v74WI~
//del tab at left boundary                                         //~v74WI~
            pcd=Pdbcs+Ppos;                                        //~v74WI~
            if (*pcd==TABPADCHAR)   //tab effect into the range from left//~v74WI~
            {                                                      //~v74WI~
            	rc|=1;                                             //~v74WI~
                for (pcd--;*pcd==TABPADCHAR;pcd--)                 //~v74WI~
                    *pcd=0; //reset boundary tab                   //~v74WI~
                *pcd=0;     //tab char                             //~v74WI~
            }                                                      //~v74WI~
    }//left                                                        //~v74WI~
//*                                                                //~v74WI~
    if ((rightpos=Ppos+Prangelen)<Pdatalen && rightpos >0)  //data exist on the right//~v74WI~
    {                                                              //~v74WI~
//del tab at right boundary                                        //~v74WI~
            pcd=Pdbcs+rightpos;                                    //~v74WI~
            for (;*pcd==TABPADCHAR;pcd++)                          //~v74WI~
                *pcd=0; //reset boundary tab                       //~v74WI~
            rc|=2;                                                 //~v74WI~
    }//right data exist                                            //~v74WI~
    return rc;                                                     //~v74WI~
}//setobtabclear                                                   //~v74WI~
//**************************************************               //~v73hI~
//*update dbcs table by hexmode(optionaly imm only)                //~v73qI~
//*return:length changed value                                     //~v73hI~
//*       rc:1 dbcs2nd splitted                                    //~v73hI~
//**************************************************               //~v73hI~
//int updatedbcstblhex(int Pmode,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Pch,int *Ppaddlen)//~v73qR~
int updatedbcstblhex(int Pmode,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Pch,int *Ppaddlen,int Poomlen)//~v73qI~
{                                                                  //~v73hI~
    int     reslen,addlen,splitsw;                                 //~v73hR~
    UCHAR   *pc,*pcd;                                              //~v73hR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int opt;                                                       //~va1cR~
#endif                                                             //~va1cR~
//*************                                                    //~v73hI~
	if (Ppos>=Pdatalen)                                            //~v73hI~
    	return 0;                                                  //~v73hI~
    pc=Pdata+Ppos;                                                 //~v73hI~
    pcd=Pdbcs+Ppos;                                                //~v73hI~
	reslen=Pdatalen-Ppos;                                          //~v73hI~
  if (Poomlen && reslen>Poomlen)	//need count of new oomlen     //~v73qI~
  {                                                                //~v73qI~
  	reslen-=Poomlen;                                               //~v73qI~
    addlen=-sub_restoretabdroppad(0,pc,pcd,reslen);                //~v73qI~
    if (addlen)                                                    //~v73qI~
        memcpy(pc+reslen+addlen,pc+reslen,(UINT)Poomlen);                //~v73qI~
    reslen+=Poomlen;                                               //~v73qI~
  }                                                                //~v73qI~
  else                                                             //~v73qI~
	addlen=-sub_restoretabdroppad(0,pc,pcd,reslen);                //~v73hR~
	reslen+=addlen;                                                //~v73hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    opt=XESUBCDSO_RIGHT|XESUBCDSO_GETCTR;                          //~va1cR~
    splitsw=xesub_cleardbcssplit(opt,0/*data*/,Pdbcs,Ppos,0/*repdata*/);//~va1cR~
#else                                                              //~va1cR~
    splitsw=(*pcd==DBCS2NDCHAR);	//dbcssplit                    //~v73hI~
#endif                                                             //~va1cR~
    if (Pmode & UDBTH_INS)                                         //~v73hI~
    {                                                              //~v73hI~
    	addlen++;                                                  //~v73hI~
    	memmove(pc+1,pc,(UINT)reslen);                             //~v73hI~
    	*pc=(UCHAR)Pch;                                                   //~v73hR~
    }                                                              //~v73hI~
    else                                                           //~v73hI~
    if (Pmode & UDBTH_DEL)                                         //~v73hI~
    {                                                              //~v73hI~
    	if (reslen)                                                //~v73hI~
        {                                                          //~v73hI~
	    	addlen--;                                              //~v73hI~
    		memcpy(pc,pc+1,(UINT)(reslen-1));                      //~v73hI~
        }                                                          //~v73hI~
    }                                                              //~v73hI~
    else                                                           //~v73hI~
    	*pc=(UCHAR)Pch;                                                   //~v73hR~
    if (splitsw)	//dbcssplit                                    //~v73hR~
    {                                                              //~v73hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	pc-=splitsw;                                               //~va1cR~
    	pcd-=splitsw;                                              //~va1cR~
        reslen+=splitsw;                                           //~va1cR~
#else                                                              //~va1cR~
    	pc--;                                                      //~v73hI~
    	pcd--;                                                     //~v73hI~
        reslen++;                                                  //~v73hI~
#endif                                                             //~va1cR~
    }                                                              //~v73hI~
//*char-->filemarginchk-->filegettabexplenofmargined               //~va20I~
//*--(MERGIN_HEX)-->filegettabexplenhex-->updatedbcstblhex         //~va20I~
//reaches this point only when vhex mode char update               //~va20I~
//vhexmode is not used for utf8 file                               //~va20I~
    filesetdbcstbl(pc,pcd,reslen,0);                               //~v73hR~
    for (;reslen>0;pc++,pcd++,reslen--)                            //~v73hR~
//  	if (*pc==TABCHAR && *pcd!=DBCS2NDCHAR)                     //~v73qR~
//filegettabexplenehx is not called for ebcfile                    //~va50I~
        if (*pc==TABCHAR)                                          //~v73qI~
        	*pcd=TABCHAR,*pc=' ';                                  //~v73hI~
    if (Ppaddlen)                                                  //~v73hI~
    	*Ppaddlen=addlen;                                          //~v73hR~
    return splitsw;                                                //~v73hR~
}//updatedbcstblhex                                                //~v73hI~
//*******************************************************          //~v73hI~
//*restore tab to insert/delete by hexnmode(assume no tab expansion)//~v73hI~
//*opt:nothing                                                     //~v73hI~
//*rc:shrink len                                                   //~va7xR~
//*******************************************************          //~v73hI~
int sub_restoretabdroppad(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen)//~v73hR~
{                                                                  //~v73hI~
    UCHAR *pdbcs,*pdbcs2;                                          //~v73hI~
    int reslen,offs3,pos1=0,pos2,len;                              //~vaf9R~
//***************                                                  //~v73hI~
    offs3=0;                                                       //~v73hI~
    for (reslen=Pdatalen,pdbcs=Pdbcs;reslen>0;)                    //~v73hI~
    {                                                              //~v73hI~
//      pos1=(int)((ULONG)pdbcs-(ULONG)Pdbcs);                            //~v73hI~//~vafkR~
        pos1=(int)((ULPTR)pdbcs-(ULPTR)Pdbcs);                     //~vafkI~
//*never called for ebcfile                                        //~va50I~
    	pdbcs2=memchr(pdbcs,TABCHAR,(UINT)reslen);                       //~v73hI~
        if (!pdbcs2)                                               //~v73hI~
        	break;                                                 //~v73hI~
//      pos2=(int)((ULONG)pdbcs2-(ULONG)Pdbcs);//TAB pos                  //~v73hI~//~vafkR~
        pos2=(int)((ULPTR)pdbcs2-(ULPTR)Pdbcs);//TAB pos           //~vafkI~
        len=pos2-pos1;                                             //~v73hI~
        memcpy(Pdata+offs3,Pdata+pos1,(UINT)len);                  //~v73hI~
#ifdef UTF8UCS2                                                    //~va20I~
        memcpy(Pdbcs+offs3,Pdbcs+pos1,(UINT)len);   //copy also for ddfmt//~va20I~
#endif                                                             //~va20I~
        offs3+=len;                                                //~v73hI~
#ifdef UTF8UCS2                                                    //~va20I~
        *(Pdbcs+offs3)=0;                                          //~va20I~
#endif                                                             //~va20I~
        *(Pdata+offs3++)=TABCHAR;                                  //~v73hI~
        reslen-=len+1;                                             //~v73hI~
        pdbcs2++;                                                  //~v73hI~
        for (pdbcs=pdbcs2;reslen>0;reslen--,pdbcs++)               //~v73hI~
			if (*pdbcs!=TABPADCHAR)                                //~v73hI~
            	break;                                             //~v73hI~
    }                                                              //~v73hI~
    memcpy(Pdata+offs3,Pdata+pos1,(UINT)reslen);                   //~v73hI~
#ifdef UTF8UCS2                                                    //~va20I~
    memcpy(Pdbcs+offs3,Pdbcs+pos1,(UINT)reslen);   //copy also for ddfmt//~va20I~
#endif                                                             //~va20I~
    offs3+=reslen;                                                 //~v73hI~
    return Pdatalen-offs3;                                         //~v73hI~
}//sub_restoretabdroppad                                           //~v73hI~
//**************************************************               //~v73hI~
//*delobtab                                                        //~v73hI~
//*delete boundary tab padding                                     //~v73hI~
//*return:deleted count                                            //~v73hI~
//**************************************************               //~v73hI~
int delobtabpad(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos)   //~v73hI~
{                                                                  //~v73hI~
    int     delcnt=0,len;                                          //~v73hI~
    UCHAR   *pcd;                                                  //~v73hI~
//*************                                                    //~v73hI~
    len=Pdatalen-Ppos;                                             //~v73hI~
    if (len>0)                                                     //~v73hI~
    {                                                              //~v73hI~
    	for (pcd=Pdbcs+Ppos;len>0 && *pcd==TABPADCHAR;pcd++,len--)   //tab effect into the range from left//~v73hI~
        	delcnt++;                                              //~v73hI~
        if (delcnt)                                                //~v73hI~
        {                                                          //~v73hI~
        	memcpy(Pdbcs+Ppos,pcd,(UINT)len);                      //~v73hI~
        	memcpy(Pdata+Ppos,Pdata+Ppos+delcnt,(UINT)len);        //~v73hI~
        }                                                          //~v73hI~
    }//left                                                        //~v73hI~
    return delcnt;                                                 //~v73hI~
}//delobtabpad                                                     //~v73hI~
                                                                //~5503I~
//**************************************************               //~v45xI~
//*btabclear                                                       //~v45xI~
//*clear boundary tab                                              //~v45xI~
//*parm 1:data                                                     //~v45xI~
//*parm 2:dbcstbl                                                  //~v45xI~
//*parm 3:source len                                               //~v45xI~
//*parm 4:offset                                                   //~v45xI~
//*parm 5:obsw(process right out of bound)                         //~v45xI~
//*return:none                                                     //~v45xI~
//**************************************************               //~v45xI~
int btabclear(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Popt)//~v45xR~
{                                                                  //~v45xI~
    UCHAR   *pcd,*pcd0,*pcde;                                      //~v45xR~
//*************                                                    //~v45xI~
    if (Ppos>=Pdatalen)                                            //~v45xR~
    	return 0;                                                  //~v45xI~
    pcd0=pcd=Pdbcs+Ppos;                                           //~v45xR~
    if (*pcd!=TABPADCHAR)   //tab effect into the range from left  //~v45xI~
        return 0;                                                  //~v45xI~
    if (Ppos>0)                                                    //~v45xI~
    {                                                              //~v45xI~
    	for (pcd--;*pcd==TABPADCHAR;pcd--)                         //~v45xR~
        	*pcd=0; //reset boundary tab                           //~v45xR~
    	*pcd=0;     //tab char                                     //~v45xR~
    }                                                              //~v45xI~
    if (Popt)                                                      //~v45xI~
    {                                                              //~v45xI~
        pcde=Pdbcs+Pdatalen;                                       //~v45xR~
        for (pcd=pcd0;pcd<pcde && *pcd==TABPADCHAR;pcd++)          //~v45xR~
            *pcd=0; //reset boundary tab                           //~v45xR~
    }                                                              //~v45xI~
    return 1;                                                      //~v45xI~
}//btabclear                                                       //~v45xI~
//**************************************************               //~v21nI~
//*setobdbcserr                                                    //~v21nI~
//*set dbcs err id of outbound                                     //~v21nI~
//*parm 1:optional data addr(if you want clear boundary data)      //~v49bR~
//*parm 2:dbcs tbl                                                 //~v49bI~
//*parm 3:tbl len                                                  //~v49bR~
//*parm 4:start(left) pos                                          //~v49bR~
//*parm 5:end(right)  pos                                          //~v49bR~
//*return:none                                                     //~v21nI~
//**************************************************               //~v21nI~
void setobdbcserr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2)//~v49bR~
{                                                                  //~v21nI~
    UCHAR   *pcd;                                                  //~v21nI~
#ifdef UTF8SUPH                                                    //~va1cR~
	int opt;                                                       //~va1cR~
    UCHAR *pc;                                                     //~va1cR~
#endif                                                             //~va1cR~
//*************                                                    //~v21nI~
//*chk dbcs on the left boundary                                   //~v21nI~
    if (Ppos1>0 && Ppos1<Plen)    //left boundary on data          //~v21nI~
    {                                                              //~v21nI~
#ifdef UTF8SUPH                                                    //~va1cR~
		opt=XESUBCDSO_RIGHT|XESUBCDSO_SETERR;                      //~va1cR~
    	xesub_cleardbcssplit(opt,Pdata,Pdbcs,Ppos1,' ');           //~va1cR~
#else                                                              //~va1cR~
	    pcd=Pdbcs+Ppos1-1;                                         //~v21nI~
        if (*pcd==DBCS1STCHAR) //left boundery on the dbcs         //~v21nI~
        {                                                          //~v49bI~
            *pcd=UDBCSCHK_HKDBCSERR;                               //~v21nI~
            if (Pdata)                                             //~v49bI~
	    		*(Pdata+Ppos1-1)=' ';                              //~v49bI~
        }                                                          //~v49bI~
#endif                                                             //~va1cR~
    }//left                                                        //~v21nI~
//*chk dbcs on the right boundary                                  //~v21nI~
    if (Ppos2>0 && Ppos2<Plen)                                     //~v21nI~
    {                                                              //~v21nI~
	    pcd=Pdbcs+Ppos2;                                           //~v21nI~
#ifdef UTF8SUPH                                                    //~va1cR~
        if (Pdata)                                                 //~va1cR~
		    pc=Pdata+Ppos2;                                        //~va1cR~
        else                                                       //~va1cR~
        	pc=0;                                                  //~va1cR~
		opt=XESUBCDSO_LEFT|XESUBCDSO_SETERR;                       //~va1cR~
    	xesub_cleardbcssplit(opt,pc,pcd,Plen-Ppos2,' ');           //~va1cR~
#else                                                              //~va1cR~
        if (*pcd==DBCS2NDCHAR)//right boundary on the DBCS         //~v21nR~
        {                                                          //~v49bI~
            *pcd=UDBCSCHK_HKDBCSERR;                               //~v21nI~
            if (Pdata)                                             //~v49bI~
	    		*(Pdata+Ppos2)=' ';                                //~v49bI~
        }                                                          //~v49bI~
#endif                                                             //~va1cR~
    }//right data exist                                            //~v21nI~
    return;                                                        //~v21nI~
}//setobdbcserr                                                    //~v21nI~
//**************************************************               //~v750I~
//*setibdbcserr                                                    //~v750I~
//*set dbcs err id of innerbound                                   //~v750I~
//*parm 1:optional data addr(if you want clear boundary data)      //~v750I~
//*parm 2:dbcs tbl                                                 //~v750I~
//*parm 3:tbl len                                                  //~v750I~
//*parm 4:start(left) pos                                          //~v750I~
//*parm 5:end(right)  pos                                          //~v750I~
//*return:none                                                     //~v750I~
//**************************************************               //~v750I~
int setibdbcserr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2)//~v750I~
{                                                                  //~v750I~
    UCHAR   *pcd;                                                  //~v750I~
    int rc=0;                                                      //~v750I~
#ifdef UTF8SUPH                                                    //~va1cR~
	int opt;                                                       //~va1cR~
    UCHAR *pc;                                                     //~va1cR~
#endif                                                             //~va1cR~
//*************                                                    //~v750I~
//*chk dbcs on the left boundary                                   //~v750I~
    if (Ppos1>=0 && Ppos1<Plen)    //left boundary on data         //~v750I~
    {                                                              //~v750I~
	    pcd=Pdbcs+Ppos1;                                           //~v750I~
#ifdef UTF8SUPH                                                    //~va1cR~
		opt=XESUBCDSO_LEFT|XESUBCDSO_SETERR;                       //~va1cR~
        if (Pdata)                                                 //~va1cR~
		    pc=Pdata+Ppos1;                                        //~va1cR~
        else                                                       //~va1cR~
        	pc=0;                                                  //~va1cR~
    	xesub_cleardbcssplit(opt,pc,pcd,Plen-Ppos1,' ');           //~va1cR~
#else                                                              //~va1cR~
        if (*pcd==DBCS2NDCHAR) //left boundery on the dbcs         //~v750I~
        {                                                          //~v750I~
            *pcd=UDBCSCHK_HKDBCSERR;                               //~v750I~
            if (Pdata)                                             //~v750I~
	    		*(Pdata+Ppos1)=' ';                                //~v750I~
            rc=1;                                                  //~v750I~
        }                                                          //~v750I~
#endif                                                             //~va1cR~
    }//left                                                        //~v750I~
//*chk dbcs on the right boundary                                  //~v750I~
    if (Ppos2>0 && Ppos2<=Plen)                                    //~v750I~
    {                                                              //~v750I~
#ifdef UTF8SUPH                                                    //~va1cR~
		opt=XESUBCDSO_RIGHT|XESUBCDSO_SETERR;                      //~va1cR~
    	xesub_cleardbcssplit(opt,Pdata,Pdbcs,Ppos2,' ');           //~va1cR~
#else                                                              //~va1cR~
	    pcd=Pdbcs+Ppos2-1;                                         //~v750I~
        if (*pcd==DBCS1STCHAR)//right boundary on the DBCS         //~v750I~
        {                                                          //~v750I~
            *pcd=UDBCSCHK_HKDBCSERR;                               //~v750I~
            if (Pdata)                                             //~v750I~
	    		*(Pdata+Ppos2-1)=' ';                              //~v750I~
            rc=1;                                                  //~v750I~
        }                                                          //~v750I~
#endif                                                             //~va1cR~
    }//right data exist                                            //~v750I~
    return rc;                                                     //~v750I~
}//setibdbcserr                                                    //~v750I~
//**************************************************               //~v750I~
//*setsplitdbcserr                                                 //~v750I~
//*set dbcs err id of split pos                                    //~v750I~
//*parm 1:optional data addr(if you want clear boundary data)      //~v750I~
//*parm 2:dbcs tbl                                                 //~v750I~
//*parm 3:tbl len                                                  //~v750I~
//*parm 4:start(left) pos                                          //~v750I~
//*parm 5:end(right)  pos                                          //~v750I~
//*return:none                                                     //~v750I~
//**************************************************               //~v750I~
int setsplitdbcserr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos)   //~v750I~
{                                                                  //~v750I~
    UCHAR   *pcd;                                                  //~v750I~
    int rc=0;                                                      //~v750I~
#ifdef UTF8SUPH                                                    //~va1cR~
	int opt;                                                       //~va1cR~
    UCHAR *pc;                                                     //~va1cR~
#endif                                                             //~va1cR~
//*************                                                    //~v750I~
//*chk dbcs on the left boundary                                   //~v750I~
    if (Ppos>=0 && Ppos<Plen)    //left boundary on data           //~v750I~
    {                                                              //~v750I~
	    pcd=Pdbcs+Ppos;                                            //~v750I~
#ifdef UTF8SUPH                                                    //~va1cR~
        if (Pdata)                                                 //~va1cR~
		    pc=Pdata+Ppos;                                         //~va1cR~
        else                                                       //~va1cR~
        	pc=0;                                                  //~va1cR~
		opt=XESUBCDSO_LEFT|XESUBCDSO_SETERR;                       //~va1cR~
    	xesub_cleardbcssplit(opt,pc,pcd,Plen-Ppos,' ');            //~va1cR~
#else                                                              //~va1cR~
        if (*pcd==DBCS2NDCHAR) //left boundery on the dbcs         //~v750I~
        {                                                          //~v750I~
            *pcd=UDBCSCHK_HKDBCSERR;                               //~v750I~
            if (Pdata)                                             //~v750I~
	    		*(Pdata+Ppos)=' ';                                 //~v750I~
            rc=1;                                                  //~v750I~
        }                                                          //~v750I~
#endif                                                             //~va1cR~
    }//left                                                        //~v750I~
//*chk dbcs on the right boundary                                  //~v750I~
    if (Ppos>0 && Ppos<=Plen)                                      //~v750I~
    {                                                              //~v750I~
#ifdef UTF8SUPH                                                    //~va1cR~
		opt=XESUBCDSO_RIGHT|XESUBCDSO_SETERR;                      //~va1cR~
    	xesub_cleardbcssplit(opt,Pdata,Pdbcs,Ppos,' ');            //~va1cR~
#else                                                              //~va1cR~
	    pcd=Pdbcs+Ppos-1;                                          //~v750I~
        if (*pcd==DBCS1STCHAR)//right boundary on the DBCS         //~v750I~
        {                                                          //~v750I~
            *pcd=UDBCSCHK_HKDBCSERR;                               //~v750I~
            if (Pdata)                                             //~v750I~
	    		*(Pdata+Ppos-1)=' ';                               //~v750I~
            rc=1;                                                  //~v750I~
        }                                                          //~v750I~
#endif                                                             //~va1cR~
    }//right data exist                                            //~v750I~
    return rc;                                                     //~v750I~
}//setsplitdbcserr                                                 //~v750I~
//**************************************************            //~5225I~
//*wordtblisrch                                                 //~5225I~
//* operand word match chk on string tbl(case insensitive)      //~5225I~
//*parm 1:string to be checked                                  //~5225I~
//*parm 2:string tbl(0x00 delemeter last is one more 0x00)      //~5225I~
//*return:string tbl index,0 if not found                       //~5225I~
//**************************************************            //~5225I~
int wordtblisrch(UCHAR *Pword,UCHAR *Pwordtbl)                  //~5225I~
{                                                               //~5225I~
    int ii;                                                     //~5225I~
    UCHAR *pc;                                                  //~5225I~
//********************                                          //~5225I~
    for (pc=Pwordtbl,ii=0;*pc;ii++,pc+=strlen(pc)+1)            //~5225I~
        if (!stricmp(Pword,pc))                                 //~5225I~
            return ii+1;                                        //~5225I~
    return 0;                                                   //~5225I~
}//wordtblisrch                                                 //~5225I~
                                                                //~v03iI~
//**************************************************            //~v03iI~
//*getpathlen                                                   //~v03iI~
//* path length and dir level output from filename              //~v03iI~
//*parm 1:filename                                              //~v03iI~
//*parm 2:output dir level(option)                              //~v03iI~
//*parm 3:dir sw (1:dir or wild card, 0:normal file)            //~v03iI~
//*return:path name length(len to before last \ of fullpath name)//~v03iI~
//**************************************************            //~v03iI~
int getpathlen(UCHAR *Pfilename,UCHAR *Plevel,int Pdirsw)       //~v03iI~
{                                                               //~v03iI~
    int ii,len,len0;                                            //~v03iI~
    int rootsw;                                                    //~v57DI~
#ifdef UTF8SUPPH                                                   //~va00I~
    UCHAR *pc,*pc2;                                                //~va00I~
#else                                                              //~va00I~
    UCHAR *pc,*pc2,*pc3;                                           //~v07kR~
#endif                                                             //~va00I~
    char dirsepc;                                                  //~v540I~
#ifdef FTPSUPP                                                     //~v57DI~
    PUFTPHOST puftph;                                              //~v57DR~
#endif                                                             //~v57DI~
#ifdef UNX                                                         //~vaa0I~
	int dirsw;                                                     //~vaa0I~
#endif                                                             //~vaa0I~
//********************                                          //~v03iI~
#ifdef UNX                                                         //~vaa0I~
	dirsw=Pdirsw;                                                  //~vaa0I~
	Pdirsw &= ~GPL_WILDNAME;                                       //~vaa0I~
#endif                                                             //~vaa0I~
#ifdef FTPSUPP                                                     //~v540I~
//  if (uftpisremote(Pfilename,0))                                 //~v57DR~
    if (uftpisremote(Pfilename,&puftph))                           //~v57DI~
    {                                                              //~v57DI~
        if (UFTPHISTSO(puftph))                                    //~v717I~
			return xetsogetpathlen(Pfilename,Plevel,Pdirsw);       //~v717I~
        pc=Pfilename+puftph->UFTPHhostnmlen+1;                     //~v57DI~
        rootsw=FTP_ROOTDIR(pc);                                    //~v57DI~
    	dirsepc=FTP_DIR_SEPC;                                      //~v540I~
    }                                                              //~v57DI~
    else                                                           //~v540I~
    {                                                              //~v57DI~
#endif                                                             //~v540I~
    	rootsw=ROOTDIR2(Pfilename);                                //~v57DR~
    	dirsepc=DIR_SEPC;                                          //~v540I~
#ifdef FTPSUPP                                                     //~v57DI~
    }                                                              //~v57DI~
#endif                                                             //~v57DI~
    pc=Pfilename;                                               //~v03iI~
    len0=(int)strlen(pc);                                       //~v03iR~
//  if (*(pc+len0-1)=='\\')   //root                               //~v07lR~
//  if (len0==3 && *(pc+2)=='\\')   //root                         //~v194R~
//  if (ROOTDIR2(pc))                                              //~v57DR~
    if (rootsw)                                                    //~v57DI~
    {                                                           //~v03iI~
        ii=0;                       //level                     //~v03iI~
        len=len0;                                               //~v03iI~
    }                                                           //~v03iI~
    else                                                        //~v03iI~
    {                                                           //~v03iI~
        for (ii=0;;ii++)                                        //~v03iI~
        {                                                       //~v03iI~
            pc2=pc;                                                //~v07kR~
//          while(pc=strchr(pc,'\\'),pc)    //search delm          //~v194R~
//          while(pc=strchr(pc,DIR_SEPC),pc)    //search delm      //~v540R~
#ifdef UTF8SUPPH                                                   //~va00I~
            pc=ustrchr2(pc,dirsepc);    //considering dbcs and utf8//~va00I~
#else                                                              //~va00I~
            while(pc=strchr(pc,dirsepc),pc)    //search delm       //~v540I~
            {                                                      //~v07kI~
                if (pc!=pc2)  //not first byte '\'                 //~v07kR~
                    if (udbcschk(*(pc-1)))  //prev is dbcs 1st byte//~v07kR~
                    {                                              //~v07kR~
                        for (pc3=pc2;pc3<pc;pc3++)                 //~v07kR~
                            if (udbcschk(*pc3)) //dbcs 1st byte    //~v07kR~
                                pc3++;                             //~v07kR~
                        if (pc3!=pc)    //pc('\') is dbcs second byte//~v07kR~
                        {                                          //~v07kI~
                            pc=pc3;                                //~v07kR~
                            continue;                              //~v07kI~
                        }                                          //~v07kI~
                    }                                              //~v07kR~
                break;                                             //~v07kI~
            }                                                      //~v07kI~
#endif                                                             //~va00I~
            if (!pc)                                               //~v07kI~
                break;                                             //~v07kI~
            ++pc;       //next of delm                             //~v07kI~
        }                                                       //~v03iI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abM~
        if (WIN_ISREMOTEPATH(Pfilename))                   //~v7abI~//~v7acR~
        {                                                          //~v7abI~
        	ii=max(0,ii-2);                                        //~v7abI~
        }                                                          //~v7abI~
#endif                                                             //~v7abM~
//#ifdef W32                                                         //~vb04I//~vb06R
//        if (IS_RESERVED_NAME(Pfilename))                           //~vb04I//~vb06R
//        {                                                          //~vb04I//~vb06R
//            ii=max(0,ii-3);                                        //~vb04I//~vb06R
//        }                                                          //~vb04I//~vb06R
//#endif                                                             //~vb04I//~vb06R
//      len=(int)((ULONG)pc2-(ULONG)Pfilename-1);               //~v03iR~//~vafkR~
        len=(int)((ULPTR)pc2-(ULPTR)Pfilename-1);                  //~vafkI~
        if (Pdirsw)                                             //~v03iI~
        {                                                          //~vaa0I~
            if (strpbrk(pc2,"*?"))  //wild card                 //~v03iI~
#ifdef UNX                                                         //~vaa0I~
			  if (dirsw & GPL_WILDNAME)                            //~vaa0I~
                len=len0;   //dir                                  //~vaa0I~
              else                                                 //~vaa0I~
#endif                                                             //~vaa0I~
                ii--;       //ignore mask                       //~v03iI~
            else                                                //~v03iI~
                len=len0;   //dir                               //~v03iI~
        }                                                          //~vaa0I~
        else                                                    //~v03iI~
            ii--;       //ignore file name                      //~v03iI~
    }//not root                                                 //~v03iI~
    if (Plevel)                                                 //~v03iI~
        *Plevel=(UCHAR)ii;  //file/dir hierarchical level       //~v03iI~
    return len;                                                 //~v03iI~
}//getpathlen                                                   //~v03iI~
//*******************************************************          //~v730I~
//*set cmdline input field(long cmd is cut by charcount for  buffsz)//~v730I~
//* parm1: client work                                             //~v730I~
//* parm2: data set from addr                                      //~v730I~
//* return:filled data len                                         //~v730I~
//*******************************************************          //~v730I~
int setflddatacmd(PUCLIENTWE Ppcw,UCHAR *Pdata)                    //~v730I~
{                                                                  //~v730I~
    UCHAR *pdata,*pdbcs,*pdata2,*pdbcs2;                           //~v730I~
    int fldwidth,buffsz,fldoffs,copylen,cntr;                      //~v730R~
    PUPANELC ppc;                                                  //~v730I~
    UFLD    *pfl;                                                  //~v730I~
//************************                                         //~v730I~
    ppc=Ppcw->UCWppc;                                              //~v730I~
    pfl=ppc->UPCline[CMDLINENO].UPLpfld;     //UFLD ptr            //~v730I~
    fldoffs=pfl->UFLentry[0].UFLstart; //field addr                //~v730I~
    fldwidth=pfl->UFLentry[0].UFLend-fldoffs;                      //~v730I~
                                                                   //~v730I~
    pdata=ppc->UPCcmddata+fldoffs;                                 //~v730I~
    pdbcs=ppc->UPCcmddbcs+fldoffs;                                 //~v730I~
                                                                   //~v730I~
//save for later get                                               //~v730I~
//  buffsz=MAXCOLUMN;   //leave previous input prohibitted span    //~v730I~//~va04R~
    buffsz=UPCCMDFLDWKSZ-fldoffs-1; //leave previous input prohibitted span//~va04R~
    if (Pdata)	//request to set not only to UPLbuff but also UPCcmddata//~v730I~
    {                                                              //~v730I~
        if (*Pdata)     //data exist                               //~v730I~
        {                                                          //~v730I~
            copylen=(int)strlen(Pdata);                            //~v730R~
            if (copylen>buffsz)                                    //~va03I~
                copylen=buffsz;   //protect malloc hdr             //~va03I~
        	setdbcstbl(Pdata,pdbcs,copylen);             //reset dbcstbl//~v730I~
            memcpy(pdata,Pdata,(UINT)copylen);                     //~v730R~
            cntr=buffsz-copylen;                                   //~v730I~
            if (cntr>0) //data cut                                 //~v730I~
            {                                                      //~v730I~
                memset(pdata+copylen,0,(UINT)cntr);                //~v730R~
                memset(pdbcs+copylen,0,(UINT)cntr);                //~v730R~
            }                                                      //~v730I~
        }                                                          //~v730I~
        else                                                       //~v730I~
        {                                                          //~v730I~
            copylen=0;                                             //~v730I~
            if (*pdata)                                            //~v730I~
            {                                                      //~v730I~
                memset(pdata,0,(UINT)buffsz);        //all clear   //~v730R~
                memset(pdbcs,0,(UINT)buffsz);        //all clear   //~v730R~
            }                                                      //~v730I~
        }                                                          //~v730I~
    }                                                              //~v730I~
    else                                                           //~v730I~
        copylen=(int)strlen(pdata);                                //~v730R~
//setup for display                                                //~v730I~
    pdata2=ppc->UPCline[CMDLINENO].UPLbuff+fldoffs;      //sorce of draw(set sto psd)//~v730R~
    pdbcs2=ppc->UPCline[CMDLINENO].UPLdbcs+fldoffs;      //        //~v730R~
    if (copylen>fldwidth)                                          //~v730I~
    	copylen=fldwidth;                                          //~v730I~
    memcpy(pdata2,pdata,(UINT)copylen);                            //~v730R~
    memcpy(pdbcs2,pdbcs,(UINT)copylen);                            //~v730R~
    if (copylen<fldwidth)                                          //~v730I~
    {                                                              //~v730I~
	    memset(pdata2+copylen,0,(UINT)(fldwidth-copylen));         //~v730R~
	    memset(pdbcs2+copylen,0,(UINT)(fldwidth-copylen));         //~v730R~
    }                                                              //~v730I~
    else                                                           //~v730I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va5tI~
	    xesub_setdbcssplit(0,0/*plh*/,pdata2,pdbcs2,fldwidth,'.'); //~va5tR~
#else                                                              //~va5tI~
	    setdbcssplit(pdata2,pdbcs2,fldwidth,'.');                  //~v730R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va5tI~
//                                                                 //~v730I~
    UCBITON(((PUSCRD)(Ppcw->UCWpsd)+CMDLINENO)->USDflag2,USDF2DRAW);//~v730I~
    return copylen;                                                //~v730R~
}//setflddatacmd                                                   //~v730I~
#ifdef UTF8SUPPH                                                   //~va00I~
//#ifdef DDD                                                         //~va00I~//~vauDR
////*******************************************************          //~v730I~//~va00I~//~vauDR
////*for utf8 version                                                //~va00I~//~vauDR
////*******************************************************          //~v730I~//~va00I~//~vauDR
//int setflddatacmd_byutf8(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdata)                    //~v730I~//~va00I~//~vauDR
//{                                                                  //~v730I~//~va00I~//~vauDR
//    PUPANELC ppc;                                                  //~v730I~//~va00I~//~vauDR
//    UFLD    *pfl;                                                  //~v730I~//~va00I~//~vauDR
//    char wk[UPCCMDFLDWKNETSZ];                                     //~va00I~//~vauDR
//    char *pwk=wk,*pdata,*pct0,*pu8,*pdbcs;                         //~va00R~//~vauDR
//    int inplen,outlen,fldoffs;                                     //~va00R~//~vauDR
//    int rc2,oututf8len,fldwidth;                                   //~va00R~//~vauDR
////************************                                         //~v730I~//~va00I~//~vauDR
//    ppc=Ppcw->UCWppc;                                              //~v730I~//~va00I~//~vauDR
//    pfl=ppc->UPCline[CMDLINENO].UPLpfld;     //UFLD ptr            //~v730I~//~va00M~//~vauDR
//    fldoffs=pfl->UFLentry[0].UFLstart; //field addr                //~v730I~//~va00M~//~vauDR
//    fldwidth=pfl->UFLentry[0].UFLend-fldoffs;                      //~va00I~//~vauDR
//    pdata=ppc->UPCcmddata+fldoffs;                                 //~v730I~//~va0gI~//~vauDR
//    pdbcs=ppc->UPCcmddbcs+fldoffs;                                 //~va0gI~//~vauDR
//    pu8=ppc->UPCcmddatabyutf8/*+fldoffs*/;                         //~va00R~//~vauDR
//    pct0=ppc->UPCcmdcodetb/*+fldoffs*/;                            //~va00R~//~vauDR
//#ifdef CCC                                                         //~va00I~//~vauDR
//    if (!Pdata)    //from charpan,updated locale data              //~va00R~//~vauDR
//    {                                                              //~va00I~//~vauDR
//        inplen=(int)strlen(pdata);                                 //~va00R~//~vauDR
//        opt=XEUTFCVO_SETCT;  //setup utf8/codetype even when no utf8 contains//~va0gI~//~vauDR
//        rc2=xeutf_fldl2f(opt,pdata,pdbcs,pwk,inplen,pct0,pu8,&outlen);//~va00R~//~vauDR
//        if (rc2==XEUTFILRC_UTF8)                                   //~va00I~//~vauDR
//            UCBITON(ppc->UPCflag,UPCFCMDUTF8);                     //~va00R~//~vauDR
//        else                                                       //~va00I~//~vauDR
//            UCBITOFF(ppc->UPCflag,UPCFCMDUTF8);                    //~va00I~//~vauDR
//        rc=setflddatacmd(Ppcw,Pdata);   //Pdata==0                    //~v730I~//~va00R~//~vauDR
//        return rc;                                                 //~va00I~//~vauDR
//    }                                                              //~va00I~//~vauDR
//#endif                                                             //~va00I~//~vauDR
//    if (!*Pdata)    //clear req                                    //~va00I~//~vauDR
//    {                                                              //~va00M~//~vauDR
//        UCBITOFF(ppc->UPCflag,UPCFCMDUTF8);                        //~va00R~//~vauDR
//        *pu8=0;                                                    //~va00R~//~vauDR
//        return setflddatacmd(Ppcw,Pdata);                    //~v730I~//~va00M~//~vauDR
//    }                                                              //~va00M~//~vauDR
//    inplen=(int)strlen(Pdata);                                     //~va00M~//~vauDR
//    opt=XEUTFGLSMO_STRZ|XEUTFGLSMO_KEEPLC;                         //~va00R~//~vauDR
//    rc2=xeutf_getmixedstr(opt,Pdata,inplen,pdata,pdbcs,pct0,UPCCMDFLDWKNETSZ,&outlen,//~va00I~//~vauDR
//                            pu8,UPCCMDFLDWKNETSZ,&oututf8len);     //~va00R~//~vauDR
//    if (outlen>0 && outlen<fldwidth)                               //~va00I~//~vauDR
//    {                                                              //~va00I~//~vauDR
//        memset(pdata+outlen,0,(UINT)(fldwidth-outlen)); //for display at xepan//~va00I~//~vauDR
//        memset(pdbcs+outlen,0,(UINT)(fldwidth-outlen));            //~va00I~//~vauDR
//    }                                                              //~va00I~//~vauDR
//    if (oututf8len>0 && oututf8len<fldwidth)                       //~va00I~//~vauDR
//    {                                                              //~va00I~//~vauDR
//        memset(pu8+oututf8len,0,(UINT)(fldwidth-oututf8len));      //~va00I~//~vauDR
//    }                                                              //~va00I~//~vauDR
//    if (rc2 & XEUTFGU8MRC_UTF8)     //input contains utf8 code     //~va00R~//~vauDR
//    {                                                              //~va00R~//~vauDR
//        UCBITON(ppc->UPCflag,UPCFCMDUTF8);                         //~va00R~//~vauDR
////        memcpy(putf8,Pdata,(UINT)inplen+1);                      //~va0gR~//~vauDR
//    }                                                              //~va00R~//~vauDR
////    else                                                         //~va0gR~//~vauDR
////    {                                                            //~va0gR~//~vauDR
////        pwk=Pdata;                                               //~va0gR~//~vauDR
////    }                                                            //~va0gR~//~vauDR
//    return setflddatacmd(Ppcw,0);   //set locale code                 //~v730I~//~va0gR~//~vauDR
//}//setflddatacmd_byutf8                                                   //~v730I~//~va00I~//~vauDR
//#endif  //DDD                                                      //~va00R~//~vauDR
//*******************************************************          //~va0gI~
//*cmdline update for utf8 version;data+dbcs                       //~va0gI~
//*rc :data len on display fld                                     //~va0gI~
//*******************************************************          //~va0gI~
int setflddatadbcscmd_byutf8(int Popt,PUCLIENTWE Ppcw,int Ppos,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~va0gI~
{                                                                  //~va0gI~
    PUPANELC ppc;                                                  //~va0gI~
    UFLD    *pfl;                                                  //~va0gI~
    char wkutf8[UPCCMDFLDWKNETSZ];                                 //~va0gI~
    char wkdbcs[UPCCMDFLDWKNETSZ];                                 //~va0gI~
    char wkcodetype[UPCCMDFLDWKNETSZ];                             //~va0gI~
    char *pdata,*pct,*pu8,*pdbcs,*psrcdbcs;                        //~va00R~
	int rc,/*rc2,*/fldoffs,opt,inplen,/*utf8len,*/srcutf8len,buffsz;       //~va00R~//~vaa7R~
    int offsu8,ddstrlen,u8pos,paddlen;                             //~vaarI~
//************************                                         //~va0gI~
    UTRACEP("setflddatadbcscmd_byutf8 opt=%x\n",Popt);             //~vauDR
    UTRACED("setflddatadbcscmd_byutf8 data",Pdata,Plen);           //~vauDI
    UTRACED("setflddatadbcscmd_byutf8 dbcs",Pdbcs,Plen);           //~vauDI
    ppc=Ppcw->UCWppc;                                              //~va0gI~
#ifdef FFF                                                         //~va00I~
  	UCBITON(ppc->UPCflag,UPCFCMDUTF8);	//utf8/codetype setuped    //~va00R~
#endif                                                             //~va00I~
    pfl=ppc->UPCline[CMDLINENO].UPLpfld;     //UFLD ptr            //~va0gI~
    fldoffs=pfl->UFLentry[0].UFLstart; //field addr                //~va0gI~
    buffsz=UPCCMDFLDWKSZ-fldoffs-1; //leave previous input prohibitted span//~va00I~
    pdata=ppc->UPCcmddata+fldoffs;                                 //~va0gI~
    pdbcs=ppc->UPCcmddbcs+fldoffs;                                 //~va0gI~
    pu8=ppc->UPCcmddatabyutf8/*+fldoffs*/;                         //~va00R~
    pct=ppc->UPCcmdcodetb/*+fldoffs*/;                             //~va00R~
    UTRACED("setflddatadbcscmd_byutf8 cmdu8data",pu8,(int)strlen(pu8)); //~vaarI~//~vb06R
    UTRACED("setflddatadbcscmd_byutf8 cmddbcs",pdbcs,pfl->UFLentry[0].UFLend-fldoffs);//~vaarI~
    UTRACED("setflddatadbcscmd_byutf8 cmdct  ",pct  ,pfl->UFLentry[0].UFLend-fldoffs);//~vaarI~
	if (Popt & SFDDCUO_CAP)                                        //~vaarI~
    {                                                              //~vaarI~
//  	if (cmdlinepos2offs(0,Ppcw,pu8,pdbcs,pct,fldoffs,Ppos+fldoffs,strlen(pu8),&offsu8,&ddstrlen,&u8pos,&paddlen)>=0)//~vaarR~//~vb06R
    	if (cmdlinepos2offs(0,Ppcw,pu8,pdbcs,pct,fldoffs,Ppos+fldoffs,(int)strlen(pu8),&offsu8,&ddstrlen,&u8pos,&paddlen)>=0)//~vaarR~//~vb06I
        {                                                          //~vaarI~
UTRACEP("cmdlinepos2offs pos=%d-->%d\n",Ppos,u8pos);               //~vaarR~
        	Ppos=u8pos;                                            //~vaarR~
        }                                                          //~vaarI~
    }                                                              //~vaarI~
    inplen=Plen;                                                   //~va0gI~
	if (!*Pdata) 	//clear req                                    //~va0gM~
    {                                                              //~va0gM~
#ifdef FFF                                                         //~va00I~
        UCBITOFF(ppc->UPCflag,UPCFCMDUTF8);                        //~va00R~
#endif                                                             //~va00I~
    	*pu8=0;                                                    //~va00R~
		return setflddatacmd(Ppcw,Pdata);                          //~va0gM~
    }                                                              //~va0gM~
	if (Popt & SFDDCUO_FULLREP)   //fully replace                  //~va00I~
    {                                                              //~va00I~
    	memset(pdata,0,(UINT)buffsz);                              //~va00R~
    	*pu8=0;                                                    //~va00I~
    }                                                              //~va00I~
  if (Popt & SFDDCUO_SETCT) //Gcmdbuffct was setup                 //~va1rI~
  {                                                                //~va1rI~
    UTRACED("setflddatadbcscmd_byutf8 SETCT Gcmdbufflc",Gcmdbufflc,Gcmdbufflclen);//~vawGI
  	UmemcpyZ(pdata,Gcmdbufflc,(UINT)Gcmdbufflclen);                //~va1rR~
  	UmemcpyZ(pu8,Pdata,(UINT)inplen);                              //~va1rR~
  	memcpy(pct,Gcmdbuffct,(UINT)Gcmdbufflclen);                    //~va1rI~
  	memcpy(pdbcs,Gcmdbuffdbcs,(UINT)Gcmdbufflclen);                //~va1rI~
  }                                                                //~va1rI~
  else                                                             //~va1rI~
  {                                                                //~va1rI~
    if (!(psrcdbcs=Pdbcs) )                                        //~va0gM~
    	psrcdbcs=wkdbcs;                                           //~va0gM~
#ifdef AAA  //xeutf_mixedstrupdate do setdbcstbl after xeutf_getmixedstr//~va00I~
	if (!Pdbcs || Popt & SFDDCUO_SETDBCS)   //dbcstbl setup required//~va0gM~
        setdbcstbl(Pdata,psrcdbcs,Plen);             //reset dbcstbl//~va0gM~
#endif                                                             //~va00I~
    opt=XEUTFMSUO_STRZ|XEUTFMSUO_SETUTF8RC;                        //~va00R~
	if (Popt & SFDDCUO_INS)   //insert mode                        //~va0gI~
    	opt|=XEUTFMSUO_INS;                                        //~va00R~
	if (Popt & SFDDCUO_UTF8)   //parm to getmixedword              //~vauDI
    	opt|=XEUTFMSUO_UTF8;   //treate as utf8 if both u8/lc ok   //~vauDI
    else                                                           //~vauDI
	if (Popt & SFDDCUO_LC)   //insert mode                        //~va0gI~//~vauDI
    	opt|=XEUTFMSUO_LC;                                         //~vauDI
#ifdef UTF8UCS2                                                    //~va20I~
   if (Popt & SFDDCUO_SETCT2) //Gcmdbuffct was setup               //~va20I~
   {                                                               //~va20I~
//	/*rc2=*/xeutf_mixedstrupdate(opt,pdata,pu8,pct,pdbcs,strlen(pdata),0/*outlclen*/,0/*oututf8len*/,//~va20I~//~vaa7R~//~vb06R
  	/*rc2=*/xeutf_mixedstrupdate(opt,pdata,pu8,pct,pdbcs,(int)strlen(pdata),0/*outlclen*/,0/*oututf8len*/,//~va20I~//~vaa7R~//~vb06I
							Ppos,UPCCMDFLDWKNETSZ,                 //~va20I~
//  						Gcmdbufflc,Pdata,Gcmdbuffct,psrcdbcs,Gcmdbufflclen,Plen,sizeof(Gcmdbuffu8));//~va20R~//~vb06R
    						Gcmdbufflc,Pdata,Gcmdbuffct,psrcdbcs,Gcmdbufflclen,Plen,(int)sizeof(Gcmdbuffu8));//~va20R~//~vb06I
   }                                                               //~va20I~
   else                                                            //~va20I~
#endif                                                             //~va20I~
   {                                                               //~va20I~
//  utf8len=-1;	//get it by strlen                                 //~va0gI~//~vaa7R~
    *wkutf8=0;		//srcutf8 ,req l2f                             //~va0gR~
    srcutf8len=0;                                                  //~va00I~
//  /*rc2=*/xeutf_mixedstrupdate(opt,pdata,pu8,pct,pdbcs,strlen(pdata),0/*outlclen*/,0/*oututf8len*/,//~va00R~//~vaa7R~//~vb06R
    /*rc2=*/xeutf_mixedstrupdate(opt,pdata,pu8,pct,pdbcs,(int)strlen(pdata),0/*outlclen*/,0/*oututf8len*/,//~va00R~//~vaa7R~//~vb06I
							Ppos,UPCCMDFLDWKNETSZ,                 //~va00R~
//  						Pdata,wkutf8,wkcodetype,psrcdbcs,inplen,srcutf8len,sizeof(wkutf8));//~va0iR~//~vb06R
    						Pdata,wkutf8,wkcodetype,psrcdbcs,inplen,srcutf8len,(int)sizeof(wkutf8));//~va0iR~//~vb06I
   }                                                               //~va20I~
  }                                                                //~va1rI~
#ifdef FFF                                                         //~va00I~
    if (rc2==XEUTFMSURC_UTF8)		//target contains utf8 coed    //~va00R~
        UCBITON(ppc->UPCflag,UPCFCMDUTF8);                         //~va00R~
    else                                                           //~va00R~
        UCBITOFF(ppc->UPCflag,UPCFCMDUTF8);                        //~va00R~
#endif                                                             //~va00I~
	rc=setflddatacmd(Ppcw,0/*plbuff,pldbcs update only*/);   //set to display fld//~va0gI~
    return rc;                                                     //~va0gI~
}//setflddatadbcscmd_byutf8                                        //~va0gI~
//*******************************************************          //~va0gI~
//*enq filename to be deleted at end of session                    //~va0gI~
//*******************************************************          //~va0gI~
int getfldutf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,char **Pputf8,char **Ppcodetype)//~va0gI~
{                                                                  //~va0gI~
	PUPANELC ppc;                                                  //~va0gI~
	PUPANELL pupl;                                                 //~va0gI~
//  UFLDE    *pfle;                                                //~va0gI~//~va00R~
//  int fldoffs;                                                   //~va0gR~//~va00R~
	char *pu8,*pct;                                                //~va0gR~
//************************                                         //~va0gI~
    ppc=Ppcw->UCWppc;                                              //~va0gI~
    pupl=ppc->UPCline+Prow;                                        //~va0gI~
    pct=pupl->UPLcodetype;                                         //~va0gI~
    pu8=pupl->UPLbuffbyutf8;                                       //~va0gI~
    if (!pu8)                                                      //~va0gI~
    	return 4;	                                               //~va0gI~
//  if (Pfldno>=0)                                                 //~va0gI~//~va00R~
//  {                                                              //~va0gI~//~va00R~
//  	pfle=getuflde(Ppcw,Prow,Pfldno);                           //~va0gI~//~va00R~
//  	fldoffs=pfle->UFLstart; //field addr                       //~va0gI~//~va00R~
//      pct+=fldoffs;                                              //~va00R~
//      pu8+=fldoffs;                                              //~va00R~
//  }                                                              //~va0gI~//~va00R~
    if (Pputf8)                                                    //~va0gI~
    	*Pputf8=pu8;                                               //~va0gI~
    if (Ppcodetype)                                                //~va0gI~
    	*Ppcodetype=pct;                                           //~va0gI~
    return 0;                                                      //~va0gI~
}//getfldutf8                                                      //~va0gI~
#endif // UTF8SUPPH                                                //~va00I~
//*******************************************************          //~v76pI~
//*enq filename to be deleted at end of session                    //~v76pI~
//*******************************************************          //~v76pI~
int subsavetempfnm(char *Pfnm,int Plen)                            //~v76pI~
{                                                                  //~v76pI~
	int len;                                                       //~v76pI~
    char *pc;                                                      //~v76pI~
    PUQUEE pqe;                                                    //~v76pI~
//************************                                         //~v76pI~
	if (!(len=Plen))                                               //~v76pI~
    	len=(int)strlen(Pfnm);                                          //~v76pI~
//  pc=(char*)umalloc((UINT)(UQUEESZ+len+1));                      //~v76pR~//~vb06R
    pc=(char*)umalloc((UINT)(UQUEESZ+(UINT)len+1));                      //~v76pR~//~vb06I
	UALLOCCHK(pc,UALLOC_FAILED);	//return if null               //~v76pI~
//  pqe=(PUQUEE)(ULONG)pc;                                         //~v76pI~//~vafkR~
    pqe=(PUQUEE)(ULPTR)pc;                                         //~vafkI~
    memset(pqe,0,UQUEESZ);                                         //~v76pI~
    pc+=UQUEESZ;                                                   //~v76pI~
    memcpy(pc,Pfnm,(UINT)len);                                     //~v76pR~
    *(pc+len)=0;                                                   //~v76pI~
	UENQ(UQUE_END,&Ssubtempfnq,pqe);                               //~v76pI~
    return 0;                                                      //~v76pI~
}//subsavetempfnm                                                  //~v76pI~
//*******************************************************          //~v76pI~
//*del temp filename                                               //~v76pI~
//*******************************************************          //~v76pI~
int subdeletetempfile(void)                                        //~v76pI~
{                                                                  //~v76pI~
    PUQUEE pqe,pqen=0;                                               //~v76pR~
    int ctr=0;                                                     //~v76pI~
    char *pc;                                                      //~v76pI~
//************************                                         //~v76pI~
	for (pqe=UGETQTOP(&Ssubtempfnq);pqe;pqe=pqen)                  //~v76pR~
    {                                                              //~v76pI~
//	    pc=(char *)(ULONG)(pqe+1);                                 //~v76pI~//~vafkR~
	    pc=(char *)(ULPTR)(pqe+1);                                 //~vafkI~
		if (uxdelete(pc,UXDELDIR,UXDELFORCE,&ctr,&ctr,&ctr))       //~v76pI~
        	ubell();                                               //~v76pI~
        pqen=UGETQNEXT(pqe);                                       //~v76pI~
        ufree(pqe);                                                //~v76pI~
    }                                                              //~v76pI~
    return 0;                                                      //~v76pI~
}//subdeletetempfile                                               //~v76pI~
