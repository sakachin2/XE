//*CID://+vbs7R~:                             update#=  315;       //+vbs7R~
//************************************************************* //~5820I~
//*xedlcmd3.c                                                   //~5820I~
//* each dir line cmd process                                   //~5820I~
//* delete(d)/rename(r)/attrib(a)/print(p)/xcopy(c)/xmove(m)    //~v05jR~
//* deleteforcereadonly(/) deletenoundel(z) deletenoundelreadonly(0)//~v05YR~
//************************************************************* //~5820I~
//vbs7:201028 Debian10 compiler warning -Wformat-overflow          //~vbs7I~
//vb7g:170114 (Win)longname support(expand buffsz)                 //~vb7gI~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb7c:170106 longname support; del on root file(xmove to undeldir fails)//~vb7cI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2s:160206 (Win)target err msg if slinkerr(select,medit,browse,view,print)//~vb2sI~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vazi:150113 chk open for dlcmd delete                            //~vaziI~
//            Why vazh? dlcmddelete -->dlcmddelview-->end(save) file chaned to the pdh.//~vaziI~
//            select cmd enq to the pdh.                           //~vaziI~
//            It should be reject if file was enqed(opend).        //~vaziI~
//            And also for open chk for opened by not select but edit cmd.//~vaziI~
//vazh:150112 (BUG)loop when del on dirlist if the file is opened and updated and savefile returns rc(ex,vfmt record overflow)//~vazhI~
//vaw9:140531 (W32UNICODE)recover UTF8 code on also rename fld     //~vaw9I~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//van4:131127 support move of invalid(wildcard) name entry on dir list//~van3I~
//van2:131127 support deletion of invalid(wildcard) name entry on dir list//~van2I~
//vaj9:130724 (BUG)-Rnn parm required for record mode file         //~vaj9R~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vaiu:130614 reject copy/move to ^*\ when screen is not split,accept if enclosed by quotation//~vaiuI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf0:120602 dlcmd "z"/"0" is executed  even when "opt delz off"(Warinig issued but lcmd remains there)//~vaf0I~
//vac2:120204 (SMB)target:windows consideration                    //~vac2I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va57:100429 dlcmd "p" support utf8 file using profile            //~va57I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v72p:061127 3270:upfdate vv.mm by attr cmd                       //~v72pI~
//v728:061119 3270:Attr dcmd/lcmd is not supported for tso         //~v728I~
//v71q:061021 (BUG:3270)undo of SEQ D/S rename. rename field contains last name not membername//~v71qI~
//v71o:061020 3270:wildcard mask support for dlcmd copy            //~v71oI~
//v71j:061017 3270:undel lcmd support                              //~v71jI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71e:061011 3270:Rename/delete support                           //~v71eI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v639:050428 change dlcmd xprint temp file(XE_XPIN_) to use pid for contension inter user//~v639I~
//v62P:050418 (BUG)undel of Move with rename wildcard used faile because//~v62PI~
//v62h:050316 ftp undel support                                    //~v62hI~
//v60q:050130 (BUG)refresh fail after pathdir copy because renam fld contain target dir name//~v60qI~
//            skip targetname save if dir is expanded mask specified//~v60qI~
//v609:050102 (FTP)for performance,multiple file delete at once from dirlist//~v609I~
//v59h:041111 (BUG)dlcmd copy option is not save to rename field   //~v59hI~
//v59f:041107 (BUG)attr change not availe for remotefile           //~v59fI~
//v58N:041017 (BUG)if dlcmd "p" is defined as not xprint,pfh setup err//~v58NI~
//v57B:040605 xpr dir support                                      //~v57BI~
//v57v:040601 wildcard mask support for "p" dlcmd                  //~v57uI~
//v57u:040601 "p" dlcmd support remote file                        //~v57uI~
//v55H:040316 msg change,use xdd cmd to del root-->use xdd tool    //~v55HI~
//v54q:040108 (FTP)del cmd,dlcmd del(no undo) support              //~v54qI~
//v54j:040105 (FTP)use ROOTDIR3(remote root support) for ROOTDIR2  //~v54jI~
//v53Z:031223 (WIN,UNX)ftp support;no vfat alias(always long)      //~v53ZI~
//v53T:031103 root delete by lcmd(hard to create undel dir)        //~v53TR~
//v53R:031103 (UNX:BUG)disket delete skipped when root dir         //~v53RI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v53QI~
//v47C:020323 disket support;mkdir,rmdir,attrib                    //~v47CI~
//v47u:020315 dir copyed by dlcmd copy when target is widcard(DEL v11G)//~v47uI~
//            (XCOPY and native cmd copy contents file)            //~v47uI~
//v20F:001104 (BUG)print dlcmd cause parm err when print cmd specified on ini file.//~v20FI~
//v20A:001029 LINUX support:(BUG)too may operand msg;by flag chk("/") process//~v20AI~
//v20z:001029 LINUX support:filename compare is case sensitive     //~v20zI~
//v19V:000928 LINUX support("*" mean all member,"*.*" require intermediate ".";//~v19VI~
//            under windows those are same effect)                 //~v19VI~
//            udirlist use ufileeditname(of windows logic),so no bad effect but correct//~v19VI~
//v19E:000904 LINUX support(like XE!UNDEL-->XE_UNDEL; ! has mean to bash)//~v19EI~
//v19c:000904 LINUX support(attr size,1-->4)                       //~v19cI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v11M:990828 dcmd xprint;filename=* should be current status(updated).//~v11MI~
//v11G:990822 wild card target support for lcmd copy/move          //~v11GI~
//v11t:990813 rename target wild card support                      //~v11tI~
//v11h:990717 support f10/f11 cut/paste of rename on dirlist       //~v11hI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0g4:971210 lcmd print for space embedding file                  //~v0g4I~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0g0:971207 strstr is ambiguous for xprint cmdf compare          //~v0g0I~
//            default set on gbl(if printcmd!=0 set off)           //~v0g0I~
//            (cmd parm string ignored when xprint is used on print cmd parm)//~v0g0I~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v09b:970510:disk free space display                              //~v09aI~
//            -req update free space info(dlcmd3.c,dlcmd4.c)       //~v09aI~
//v09a:970503:space imbedding filename support(last space is not supported)//~v09aI~
//            -dlcmd "r":parse newname field                       //~v09aI~
//            -dlcmd "c"/"m":enclose source filename for space embedding case//~v09aI~
//                   rigid method over v04c                        //~v09aI~
//v095:970405:DPMI version                                         //~v095I~
//            -fputs rc is -1 if err like as W32,OS/2              //~v095I~
//v085:961024:W95 VC                                               //~v085I~
//v07u:960916:chk printcmd string where xprint is used             //~v07uR~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v07lI~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//            rensmasv for also copy                               //~v07eI~
//v060:960204:add dir lcmd "z","0"(undeletable delete)          //~v05YI~
//v05Y:960203:add /s option as default to dlcmd copy            //~v05YI~
//v05V:960203:.(BUG)reset expand id when undo(entry deleted)    //~v05VR~
//            .del undel entry expanded before del              //~v05VI~
//v05S:960131:force delete r-only from dlcmd("/" cmd)           //~v05SI~
//v05R:960121:rmdir/file del by all xdd for read only chk       //~v05RI~
//v05Q:960121:xdd force option for move inter-drive,delete undel save at term//~v05QI~
//v05O:960120:copy/move cmd *\(same as source) / **\(parent of source) support//~v05SR~
//v05N:960114:add function undo rename/move on dir list         //~v05NI~
//v05G:960105:update time stamp of dir list when edit saved(add to v04j)//~v05GI~
//            change interface of dlcgetfullname(plc-->pdh parm)//~v05GI~
//v05F:960105:rename save field realloc each time(undeleted file may//~v05FI~
//            re-moved to long path name)                       //~v05FI~
//v05E:960105:save move to name on rename fld                   //~v05EI~
//v05u:951202:undelete dlcmd(rename when delete)                //~v05uI~
//v05r:951126:dlcmd cursor                                      //~v05rI~
//v05q:951126:MOVE flag on memver of dir                        //~v05qI~
//v05o:951125:dlcmd dir delete with confirmation support        //~v05oR~
//v05j:951114:move dlcmd                                        //~v05jI~
//v058:951022:print forward sequential                          //~v058I~
//v051:951014:print dlcmd                                       //~v051I~
//v04l:951008:free view/edit screen when delete                 //~v04lI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v04c:950924:space containing filename WP ROOT SF,EA DATA SF etc//~v04cI~
//            copy lcmd fail by too many operand                //~v04cI~
//v042:950916:xcopy  cmd,copy line cmd                          //~v042I~
//*950906 attrib cmd                                            //~5906I~
//*950903 update flag                                           //~5903I~
//************************************************************* //~5820I~
#include <time.h>                                               //~5820I~
#include <stdio.h>                                              //~5820I~
#include <stddef.h>                                             //~5820I~
#include <stdlib.h>                                             //~5820I~
#include <ctype.h>                                              //~5820I~
#include <string.h>                                             //~5820I~
#include <errno.h>                                                 //~vb7cI~
#ifdef DOS                                                      //~5820I~
#else                                                           //~5820I~
	#ifdef W32                                                     //~v085I~
    	#include <dos.h>                                           //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
    #endif                                                         //~v085I~
#endif                                                          //~5820I~
#ifdef UNX                                                         //~vaa0I~
	#include <dirent.h>                                            //~vaa0I~
#endif                                                             //~vaa0I~
//*******************************************************       //~5820I~
#include <ulib.h>                                               //~5820I~
#include <uerr.h>                                               //~5820I~
#include <ualloc.h>                                             //~5820I~
#include <uque.h>                                               //~5820I~
#include <ufile.h>                                              //~5820I~
#ifdef UNX                                                         //~vaa0I~
	#include <ufile1l.h>                                           //~vaa0I~
#endif                                                             //~vaa0I~
#include <ufile2.h>                                             //~v04lI~
#include <ufile3.h>                                                //~v71jI~
#include <ufile5.h>     //ugetvfatalias                            //~v0g1I~
#include <ufemsg.h>                                                //~v09bI~
#include <uparse.h>                                                //~v0b2R~
#include <uftp.h>                                                  //~v54jI~
#include <u3270.h>                                                 //~v717I~
#include <u32702.h>                                                //~v72pI~
#include <uedit.h>                                                 //~v72pR~
#include <utrace.h>                                                //~vaa0I~
#include <ustring.h>                                               //~vaiuI~
                                                                //~5820I~
#include "xe.h"                                                 //~5820I~
#include "xescr.h"                                              //~5820I~
#include "xepan.h"                                              //~5820I~
#include "xefile.h"                                             //~5820I~
#include "xefile2.h"                                            //~v05rI~
#include "xefunc.h"                                             //~5826R~
#include "xedir.h"                                              //~5826R~
#include "xedir2.h"                                             //~5826I~
#include "xedlcmd.h"                                            //~5820I~
#include "xedlcmd2.h"                                           //~5820R~
#include "xedlcmd3.h"                                           //~5820I~
#include "xedlcmd4.h"                                              //~vaa0I~
#include "xedcmd.h"                                             //~5820I~
#include "xedcmd2.h"                                            //~v051I~
#include "xedcmd4.h"                                               //~v639I~
#include "xesub.h"                                              //~v058R~
#include "xeerr.h"                                                 //~v09aI~
#include "xeftp.h"                                                 //~v57uI~
#include "xetso.h"                                                 //~v8@sR~
#include "xefcmd6.h"                                               //~va50R~
#include "xeebc.h"                                                 //~va57I~
#include "xefsub.h"                                                //~vb06I~
//*******************************************************       //~5820I~
//#define XPFLIST	"XE!XPIN!"                                     //~v19ER~
//#define XPFLIST	"XE_XPIN_"                                     //~v639R~
#define XPFTPWD	"::xe_xpwd_"  	//remote file print copy work dir  //~v57uR~
//*******************************************************       //~v058I~
//static UCHAR Sxpflist[]={WORKDIRPATHID XPFLIST};                 //~v54jR~
//static UCHAR Sxpflist[]=WORKDIRPATHID XPFLIST;                   //~v639R~
static UCHAR Sxpflist[]=DCMDDLCMDPINPFNM;                          //~v639R~
#ifdef FTPSUPP                                                     //~v57BI~
static	char Sxptmpdir[_MAX_PATH];                                 //~v57uI~
#endif                                                             //~v57BI~
static PUDLCMD Splcxp=0;                                           //~v54jR~
//**************************************************************** //~v57uI~
#ifdef FTPSUPP                                                     //~v57uI~
	int dlcxpsetremotefname(PUFILEH Ppfh,PUDIRLH Ppdh,char *Ppremotefname,int Ppathlen,//~v57vR~
							char *Plocalfname,int Pbufflen);       //~v57vI~
	int dlcxpdelremotetemp(void);                                  //~v57uI~
	int dlcmdcopymoveeditrenamefld(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUFILEH Ppfh,PUDIRLH Ppdh,char *Psrc,PUFTPHOST Ppuftph,char *Ptgt);//~v717R~
	int dlcmdattribtso(PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfpath,char *Pinpattr);//~v72pR~
#endif                                                             //~v57uI~
int erronsinglescreen(char *Pfnm);                                 //~vaiuI~
int dlcerrwildname(PUDIRLH Ppdh);                                  //~van2I~
int dlcloadchk(int Popt,PUCLIENTWE Ppcw,PUDIRLH Ppdh,char *Pfpath);//~vaziI~
//****************************************************************//~v05SI~
// dlcmddeleter                                                 //~v05YR~
// delete dlcmd force delete for read only                      //~v05YR~
//*ret  :rc                                                     //~v05SI~
//****************************************************************//~v05SI~
int dlcmddeleter(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v05SI~
{                                                               //~v05SI~
//*******************                                           //~v05SI~
    Ppcw->UCWreason=DLCMDDELRONLY;                              //~v05SI~
	return dlcmddelete(Ppcw,Pplc,Pplcdummy);                    //~v05SI~
}//dlcmddeleter                                                 //~v05YR~
//****************************************************************//~v05YI~
// dlcmddeletez                                                 //~v05YI~
// delete dlcmd without undeletability                          //~v05YI~
//*ret  :rc                                                     //~v05YI~
//****************************************************************//~v05YI~
int dlcmddeletez(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v05YI~
{                                                               //~v05YI~
//*******************                                           //~v05YI~
    Ppcw->UCWreason=DLCMDDELNOUNDEL;                            //~v05YI~
	return dlcmddelete(Ppcw,Pplc,Pplcdummy);                    //~v05YI~
}//dlcmddeletez                                                 //~v05YI~
//****************************************************************//~v05YI~
// dlcmddeletez                                                 //~v05YI~
// delete dlcmd without undeletability,force delete for read only//~v05YI~
//*ret  :rc                                                     //~v05YI~
//****************************************************************//~v05YI~
int dlcmddeletezr(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v05YI~
{                                                               //~v05YI~
//*******************                                           //~v05YI~
    Ppcw->UCWreason=DLCMDDELNOUNDEL|DLCMDDELRONLY;              //~v05YI~
	return dlcmddelete(Ppcw,Pplc,Pplcdummy);                    //~v05YI~
}//dlcmddeletezr                                                //~v05YI~
//****************************************************************//~5820I~
// dlcmddelete                                                  //~5826R~
// delete dlcmd                                                 //~5826R~
//*ret  :rc                                                     //~5906R~
//****************************************************************//~5820I~
int dlcmddelete(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~5820I~
{                                                               //~5820I~
//  UCHAR  fullpathname[_MAX_PATH];                             //~v05RR~//~vb7cR~
    UCHAR  fullpathname[_MAX_PATH2];                               //~vb7cI~
    PULINEH plh;                                                //~5903R~
    PUFILEH pfh;                                                   //~v53ZI~
    PUDIRLH pdh;                                                //~5903I~
    PUDIRLIST pudirlist;                                        //~v05oI~
    int rc,len,fctr;                                            //~v05oR~
    int xdelopt,xddopt,xddid;                                   //~v05YR~
    int rootsw;                                                    //~v53RI~
    int pos;                                                       //~v53ZI~
#ifdef FTPSUPP                                                     //~v609I~
    int ftpfiledelsw;                                              //~v609~//~vaa0R~
#endif                                                             //~v609I~
//#ifdef UNX                                                       //~vaa0R~
//    int swwildmultiple=0;                                        //~vaa0R~
//#endif                                                           //~vaa0R~
//*******************                                           //~5820I~
    UTRACEP("%s:reason=%d\n",UTT,Ppcw->UCWreason);                 //~vbs7I~
#ifdef FTPSUPP                                                     //~v609I~
    ftpfiledelsw=UCBITCHK(Pplc->UDLCflag,UDLCFFTPDEL);             //~v609I~
#endif                                                             //~v609I~
    if (UCBITCHK(Ppcw->UCWreason,DLCMDDELRONLY))                //~v05YR~
    	xdelopt=UXDELFORCE;		//force read only delete        //~v05SI~
	else                                                        //~v05SI~
    	xdelopt=0;				//err if read only              //~v05SI~
    if (UCBITCHK(Ppcw->UCWreason,DLCMDDELNOUNDEL))              //~v05YR~
    {                                                              //~vaf0I~
		if (UCBITCHK(Gopt5,GOPT5DLCZOFF))                          //~vaf0I~
            return 4;                                              //~vaf0I~
    	xddid=DCMDXDDIDXDD+DCMDXDDIDNOUNDEL;	//no undeletable//~v05YR~
    }                                                              //~vaf0I~
	else                                                        //~v05YI~
    	xddid=DCMDXDDIDXDD;	//xdd operation                     //~v05YI~
    plh=Pplc->UDLCplh;                                          //~5903R~
    pfh=UGETPFH(plh);                                              //~v53ZI~
//#ifdef FTPSUPP                                                   //~v62hR~
//    if (FILEISREMOTE(pfh))                                       //~v62hR~
//        xddid|=DCMDXDDIDNOUNDEL;    //currently no undel support for remote file//~v62hR~
//#endif                                                           //~v62hR~
    pdh=UGETPDH(plh);                                           //~5903I~
//  if (dlcgetfullname(pdh,fullpathname))                          //~vaa0R~
    if (rc=dlcgetfullname(pdh,fullpathname),rc)                    //~vaa0I~
    {                                                              //~vaa0I~
//#ifdef UNX                                                       //~vaa0R~
//      if (rc==FILE_WILDNAME_MULTIPLE)                            //~vaa0R~
//        swwildmultiple=1;                                        //~vaa0R~
//      else                                                       //~vaa0R~
//#endif                                                           //~vaa0R~
//there is a case that unlink("??") may actualy unlink("?")        //~vaa0I~
    	return 4;                                               //~5820I~
    }                                                              //~vaa0I~
//#ifdef UNX                                                       //~v54jR~
//    rootsw=ROOTDIR2(fullpathname);                               //~v54jR~
//#else                                                            //~v54jR~
//    rootsw=ROOTDIR(fullpathname);                                //~v54jR~
//#endif                                                           //~v54jR~
    rootsw=ROOTDIR3(fullpathname);                                 //~v54jI~
    if (rootsw)                                                    //~v53TI~
    {                                                              //~v53TM~
//      uerrmsg("use XDD command for root delete",                 //~v55HR~
//      		"ルートの削除はXDDコマンドを使用してください");    //~v55HR~
        uerrmsg("use XDD tool for root delete",                    //~v55HI~
        		"ルートの削除はXDDツールを使用してください");      //~v55HI~
    	return 4;                                                  //~v53TM~
    }                                                              //~v53TM~
//*chk read only before close for avoid freed and del error case//~v04lI~
//  if (UCBITCHK(pdh->UDHattr,FILE_READONLY))                   //~v05QR~
//  	return ufilereadonly(fullpathname,4);                   //~v05QR~
//close all opened                                              //~v04lI~
//	if (UCBITCHK(pdh->UDHattr,FILE_DIRECTORY))                     //~v53QR~
  	if (pdh->UDHattr & FILE_DIRECTORY)                             //~v53QI~
    {                                                           //~v05oI~
#ifdef FTPSUPP                                                     //~v71qI~
        if (FILEISTSO(pfh))                                        //~v71eI~
            return errnotsupported("Delete","TSO DataSet");        //~v71eI~
#endif                                                             //~v71qI~
//    	rc=dcmdrmdir(Ppcw,fullpathname);                        //~v05uR~
//      if (rc==2)//may empty                                   //~v05uR~
//      {                                                       //~v05uR~
        	len=(int)strlen(fullpathname);                      //~v05oR~
//      	strcat(fullpathname,"\\*.*");                          //~v19aR~
//      	strcat(fullpathname,DIR_SEPS "*.*");                   //~v19VR~
//      	strcat(fullpathname,DIR_SEPS DIR_ALLMEMB);             //~v53ZR~
        	pos=(int)strlen(fullpathname);                         //~v57BR~
        	*(fullpathname+pos++)=pfh->UFHdirsepc;                 //~v53ZI~
        	strcpy(fullpathname+pos,DIR_ALLMEMB);                  //~v53ZI~
        	fctr=udirlist(fullpathname,FILE_ALL,&pudirlist,0);//get member ctr//~v05oR~
            *(fullpathname+len)=0;	//drop                      //~v05oI~
            if (fctr>=0)     //alloced                          //~v05oI~
//              ufree(pudirlist);                               //~v05oI~//~vandR~
                UDIRLIST_FREE(pudirlist);                          //~vandI~
            if (fctr<0)  //toolongname etc                         //~vb7cR~
                return 4;                                          //~vb7cI~
          	if (fctr>2)	//not empty                             //~v05RR~
            	xddopt=0;                                       //~v05RI~
			else                                                //~v05RI~
              if (rootsw)                                          //~v53RI~
            	xddopt=0;                                          //~v53RI~
              else                                                 //~v53RI~
            	xddopt=UXDDNOCONF;                              //~v05RI~
//          {                                                   //~v05RR~
               	Ppcw->UCWparm=fullpathname;                     //~v05oR~
//             	rc=dcmdxdd(Ppcw,pdh);	//also view process     //~v05RR~
				rc=dcmddelxdd(Ppcw,1,UXDELDIR,xdelopt,xddopt,xddid,pdh);//~v05YR~
                	//opdno/.../from xdd/from dlcmd             //~v05RI~
                if (!rc)                                           //~vb7eI~
					if (FILEISREMOTE(pfh))                         //~vb7eI~
						dlcmdftpclearundelsaveDeletedDir(fullpathname);//~vb7eI~
//			}                                                   //~v05RR~
//          else                                                //~v05RR~
//			   	rc=dcmdrmdir(Ppcw,fullpathname,pdh);//dlcmd id  //~v05RR~
//      }                                                       //~v05uR~
	}                                                           //~v05oI~
  	else                                                        //~v05kR~
//**!dir **                                                        //~vaa0I~
    {                                                           //~v05oI~
//  	dlcmddelview(Ppcw,pdh);//file,drop view,before del         //~vaziR~
		if (dlcloadchk(0,Ppcw,pdh,fullpathname))                   //~vaziR~
        	return 4;                                              //~vaziI~
//  	rc=dcmddelete(Ppcw,fullpathname,pdh);	//              //~v05RR~
       	Ppcw->UCWparm=fullpathname;                             //~v05RI~
#ifdef FTPSUPP                                                     //~v609I~
      if (ftpfiledelsw)                                            //~v609I~
		rc=dlcftpmultdelgetrc(Ppcw,Pplc);                          //~v609I~
      else                                                         //~v609I~
#endif                                                             //~v609I~
      {                                                            //~vaa0I~
//#ifdef UNX                                                       //~vaa0R~
//        if (!FILEISREMOTE(pfh)                                   //~vaa0R~
//        &&  pdh->UDHattr & FILE_WILDNAME)                        //~vaa0R~
//        {                                                        //~vaa0R~
//            xdelopt|=UXDELWILDNAME;                              //~vaa0R~
//            if (swwildmultiple)                                  //~vaa0R~
//                xdelopt|=UXDELWILDMULTIPLE; //for conformation message//~vaa0R~
//        }                                                        //~vaa0R~
//#endif                                                           //~vaa0R~
		rc=dcmddelxdd(Ppcw,1,UXDELDIR,xdelopt,0,xddid,pdh);     //~v05YR~
                	//opdno/.../no confirm/from xdd/from dlcmd  //~v05RI~
      }                                                            //~vaa0I~
	}                                                           //~v05oI~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~v05rM~
	if (rc)                                                     //~5915I~
    	return 4;                                               //~5826I~
    dlcmdresetparentsz(pdh,DLCPSZ_SZ|DLCPSZ_LC,                    //~v10rM~
    					0-pdh->UDHsize,-plh->ULHlinenow);//update parent sz//~v10rM~
    dlcfsiupdate(Ppcw);  //update free space info                  //~v10rM~
	dlcmdlvlclear(Ppcw,pdh,2,1);//all child and me,del flag on  //~v05oR~
	UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //redraw savename       //~v05EI~
//#ifdef UNX                                                       //~vaa0R~
//    if (swwildmultiple)                                          //~vaa0R~
//        dlcmdresetwildmultiple(0,pfh,pdh,fullpathname);          //~vaa0R~
//#endif                                                           //~vaa0R~
    return 0;                                                   //~5826I~
}//dlcmddelete                                                  //~5820I~
#ifdef UNX                                                         //~vaa0I~
//**************************************************************** //~vaa0I~
//*reset wildmultiple by ***************************************** //~vaa0I~
//*rc:1:reset done:2set done                                       //~vaa0R~
//**************************************************************** //~vaa0I~
int dlcmdresetwildmultiple(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfilename)//~vaa0R~
{                                                                  //~vaa0I~
    char *membname;                                                //~vaa0I~
    int rc=0,swmultinew,swmultiold;                                //~vaa0R~
    PULINEH plh;                                                   //~vaa0I~
    PUDIRLH pdh;                                                   //~vaa0I~
    FILEFINDBUF3 ffb3;                                             //~vaa0I~
//*************                                                    //~vaa0I~
//	Ppdh->UDHattr&=~FILE_WILDNAME_MULTIPLE;	//set undo cmd acceptable//~vb06R~
  	Ppdh->UDHattr&=(ULONG)(~FILE_WILDNAME_MULTIPLE);	//set undo cmd acceptable//~vb06I~
	swmultinew=ufilechkwildmultiple(0,Pfilename,NULL,&ffb3)!=0;    //~vaa0R~
	UTRACEP("dlcmdresetwildmultiple new multi=%d\n",swmultinew);   //~vaa0I~
    membname=Ppdh->UDHname;                                        //~vaa0I~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~vaa0I~
	{                                                              //~vaa0I~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~vaa0I~
            continue;                                              //~vaa0I~
    	pdh=UGETPDH(plh);                                          //~vaa0I~
        if (strcmp(membname,pdh->UDHname))                         //~vaa0I~
        	continue;                                              //~vaa0I~
//thre is case new entry appear to dirent                          //~vaa0I~
		swmultiold=(Ppdh->UDHattr & FILE_WILDNAME_MULTIPLE)!=0;    //~vaa0I~
        if (swmultinew!=swmultiold)                                //~vaa0I~
        {                                                          //~vaa0I~
            if (swmultinew)                                        //~vaa0I~
            {                                                      //~vaa0I~
			    pdh->UDHattr|=FILE_WILDNAME_MULTIPLE;	//set undo cmd acceptable//~vaa0I~
                rc|=2;                                             //~vaa0I~
            }                                                      //~vaa0I~
            else                                                   //~vaa0I~
            {                                                      //~vaa0I~
//  	    	pdh->UDHattr&=~FILE_WILDNAME_MULTIPLE;	//set undo cmd acceptable//~vb06R~
    	    	pdh->UDHattr&=(ULONG)(~FILE_WILDNAME_MULTIPLE);	//set undo cmd acceptable//~vb06I~
                rc|=1;                                             //~vaa0I~
            }                                                      //~vaa0I~
			UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //redraw savename  //~vaa0R~
			UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line  //~vaa0R~
		    UTRACEP("dlcmdresetwildmultiple reset done new=%d for %s\n",swmultinew,Pfilename);//~vaa0I~
        }                                                          //~vaa0I~
    }                                                              //~vaa0I~
    return rc;                                                     //~vaa0R~
}//dlcmdresetwildmultiple                                          //~vaa0I~
#endif                                                             //~vaa0I~
//****************************************************************//~v05oI~
// dlcmddelflag                                                 //~v05oI~
// delete flag set(called from dlcmdlvlclear)                   //~v05oR~
//*ret  :rc                                                     //~v05oI~
//****************************************************************//~v05oI~
int dlcmddelflag(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh)     //~v05oI~
{                                                               //~v05oI~
//  PUFILEC pfc;                                                //~v05qR~
//*******************                                           //~v05oI~
//  while (pfc=UGETQTOP(&Ppdh->UDHviewqh),pfc)                  //~v05qR~
//  	dlcmdfreesub(Ppcw,pfc);		//drop view                 //~v05qR~
    UCBITON(Ppdh->UDHupdatetype,UDHUTDELETED);                  //~v05oR~
	UCBITON(Pplh->ULHflag,ULHFDRAW);			//redraw line   //~v05oR~
    dlcmdupctr(Pplh);                                           //~v05oR~
    return 0;                                                   //~v05oI~
}//dlcmddelflag                                                 //~v05oI~
                                                                //~v05oI~
//****************************************************************//~v05oI~
// dlcmddelview                                                 //~v05oI~
// drop vie by del(called from dlcmdlvlclear)                   //~v05oR~
//*parm1:pcw                                                    //~v05oI~
//*parm2:pdh                                                    //~v05oI~
//*ret  :rc                                                     //~v05oI~
//****************************************************************//~v05oI~
int dlcmddelview(PUCLIENTWE Ppcw,PUDIRLH Ppdh)                  //~v05oI~
{                                                               //~v05oI~
    PUFILEC pfc;                                                //~v05oI~
    int rc;                                                        //~vazhI~
//*******************                                           //~v05oI~
    UTRACEP("dlcmddelview dlcmdfreesubrc pdh=%p\n",Ppdh);          //~vazhR~
    while (pfc=UGETQTOP(&Ppdh->UDHviewqh),pfc)                  //~v05oI~
    {                                                              //~vazhI~
        UTRACEP("dlcmddelview dlcmdfreesubrc pfc=%p\n",pfc);       //~vazhI~
      rc=                                                          //~vazhI~
    	dlcmdfreesub(Ppcw,pfc);		//drop view                 //~v05oI~
        UTRACEP("dlcmddelview dlcmdfreesubrc=%d\n",rc);            //~vazhI~
        if (rc)                                                    //~vazhI~
        	return rc;                                             //~vazhI~
    }                                                              //~vazhI~
    return 0;                                                   //~v05oI~
}//dlcmddelview                                                 //~v05oI~
                                                                //~v05oI~
//****************************************************************//~5826I~
// dlcmdrename                                                  //~5826I~
// rename dlcmd                                                 //~5826I~
//*ret  :rc                                                     //~5906R~
//****************************************************************//~5826I~
int dlcmdrename(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~5826I~
{                                                               //~5826I~
//  UCHAR  fullpathname[_MAX_PATH];                                //~v09aR~//~vb7gR~
//  UCHAR  newname[_MAX_PATH];                                     //~v09aR~//~vb7gR~
//  UCHAR  realnew[_MAX_PATH];                                     //~v11tI~//~vb7gR~
    UCHAR  fullpathname[_MAX_PATH_LONG];                           //~vb7gR~
    UCHAR  newname[_MAX_PATH_LONG];                                //~vb7gR~
    UCHAR  realnew[_MAX_PATH_LONG];                                //~vb7gR~
    int pathlen;                                                //~v05NI~
    int opdno;                                                     //~v09aI~
    PULINEH plh;                                                //~5826R~
#ifdef FTPSUPP                                                     //~v71qI~
    PUFILEH pfh;                                                   //~v71jI~
#endif                                                             //~v71qI~
    PUDIRLH pdh;                                                //~5826I~
#ifdef UTF8SUPPH                                                   //~va00R~
	UCHAR  *pnewname=newname;                                      //~va00R~
#endif                                                             //~va00R~
#ifdef UNX                                                         //~vaa0I~
	int swwildname=0;                                              //~vaa0R~
    int swwildmultiple=0;                                          //~vaa0I~
#endif                                                             //~vaa0I~
    int rc;                                                        //~vaa0M~
//*******************                                           //~5826I~
    plh=Pplc->UDLCplh;                                          //~5826I~
//#ifdef FTPSUPP                                                   //~vaa0R~
    pfh=UGETPFH(plh);                                              //~v71jI~
//#endif                                                           //~vaa0R~
    pdh=UGETPDH(plh);                                           //~5826I~
//	if (dlcgetfullname(pdh,fullpathname))                          //~vaa0R~
  	if (rc=dlcgetfullname(pdh,fullpathname),rc)                    //~vaa0I~
    {                                                              //~vaa0I~
#ifdef UNX                                                         //~vaa0I~
      if (rc==FILE_WILDNAME_MULTIPLE)                              //~vaa0I~
      {                                                            //~vaa0I~
    	swwildmultiple=1;                                          //~vaa0I~
        ugeterrmsg();	//clear errmsg                             //~vaa0I~
      }                                                            //~vaa0I~
      else                                                         //~vaa0I~
#endif                                                             //~vaa0I~
    	return 4;                                               //~v05GM~
    }                                                              //~vaa0I~
#ifdef W32                                                         //~van2I~
    if (Pplc->UDLCcmd=='R')	                                       //~van2R~
    {                                                              //~van2R~
        if (UDH_IS_WILDNAMEOK(pdh))                                //~van2R~
        {                                                          //~van2R~
        	if (dcmdwildconf(0,Ppcw,fullpathname,pdh))  //confirmation chk//~van2R~
            	return 4;                                          //~van2R~
        }                                                          //~van2R~
    }                                                              //~van2R~
#endif                                                             //~van2I~
    if (Pplc->UDLCcmd=='U')	//undo rename,called from dlcmdundel//~v05NI~
    {                                                           //~v05NI~
#ifdef FTPSUPP                                                     //~v71jI~
      if (FILEISTSO(pfh))                                          //~v71jI~
      {                                                            //~v71jI~
      	u3270getlastname(0,fullpathname,newname);                  //~v71qR~
//    	u3270concatfilename(U3CF_REPLASTORMEMBER,fullpathname,pdh->UDHrenamesv,fullpathname);//~v71qR~//~va00R~
      	u3270concatfilename(U3CF_REPLASTORMEMBER,fullpathname,PDH_UDHrenamesv(pdh),fullpathname);//~va00M~
      }                                                            //~v71jI~
      else                                                         //~v71jI~
      {                                                            //~v71jI~
#endif                                                             //~v71jI~
    	pathlen=PATHLEN(fullpathname);                          //~v05NI~
        strcpy(newname,fullpathname+pathlen);                   //~v05NI~
//      strcpy(fullpathname+pathlen,pdh->UDHrenamesv);          //~v05NI~//~va00R~
        strcpy(fullpathname+pathlen,PDH_UDHrenamesv(pdh));         //~va00M~
#ifdef UNX                                                         //~vaa0I~
		if (!FILEISREMOTE(pfh))                                    //~vaa0I~
        {                                                          //~vaa0I~
        	swwildname=pdh->UDHattr & FILE_WILDNAME;               //~vaa0R~
            if (swwildname)                                        //~vaa0I~
            {                                                      //~vaa0I~
// 	            ufilerepwildname(0,newname,(int)pdh->UDHinode);    //~vb06R~
  	            ufilerepwildname(0,newname,(ULONG)pdh->UDHinode);  //~vb06I~
            }                                                      //~vaa0I~
        }                                                          //~vaa0I~
#endif                                                             //~vaa0I~
#ifdef FTPSUPP                                                     //~v71jI~
      }                                                            //~v71jI~
#endif                                                             //~v71jI~
    }                                                           //~v05NI~
    else                                                        //~v05NI~
    {                                                              //~v09aI~
//  	if (!dirgetflddata(Ppcw,plh,PANL310RENAME,newname))//len=0//~v05NR~//~va00R~
#ifdef W32UNICODE                                                  //~vaw9I~
    	if (!dirgetflddata_l2f(DGFDL2FO_UD,Ppcw,plh,PANL310RENAME,newname,NULL/*swl2f*/))//len=0//~vaw9R~
#else                                                              //~vaw9I~
    	if (!BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,newname))//len=0//~va00R~//~vaw9R~
#endif                                                             //~vaw9I~
        {                                                       //~v05NR~
            uerrmsg("Specify newname",                          //~v05NR~
                    "新しい名前を指定して下さい");              //~v05NR~
    		dirsetflderr(Ppcw,plh,PANL310RENAME);//reverse err fld//~v05NR~
            return 4;                                           //~v05NR~
        }                                                       //~v05NR~
        UPARSERC(newname,newname,&opdno,0,",");	//return if err    //~v09aI~
        if (opdno>1)                                               //~v09aI~
        	return errtoomany();                                   //~v09aI~
	}                                                              //~v09aI~
                                                                //~5826I~
#ifdef UTF8SUPPH                                                   //~va00R~
  	if (!dcmdrename(Ppcw,fullpathname,pnewname,realnew))           //~va00R~
#else                                                              //~va00R~
  	if (!dcmdrename(Ppcw,fullpathname,newname,realnew))            //~v11tR~
#endif                                                             //~va00R~
    {                                                           //~5826I~
        if (*realnew)                   //wildcard target renamed  //~v11tI~
            strcpy(newname,realnew);                               //~v11tI~
	  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr          //~v05rI~
	    if (Pplc->UDLCcmd=='U')	//undo rename,called from dlcmdundel//~v05NI~
        {                                                       //~v05NI~
#ifdef UNX                                                         //~vaa0I~
          if (!swwildname)	                                       //~vaa0I~
#endif                                                             //~vaa0I~
          {                                                        //~vaa0I~
	    	UCBITOFF(pdh->UDHupdatetype,UDHUTRENAMEO);          //~v05NI~
            *newname=0;	//clear UDHrenamesv by dirsavename      //~v05NI~
          }                                                        //~vaa0I~
        }                                                       //~v05NI~
        else                                                    //~v05NI~
	    	UCBITON(pdh->UDHupdatetype,UDHUTRENAMEO);           //~v05NR~
#ifdef UNX                                                         //~vaa0I~
      if (swwildname)                                              //~vaa0I~
      {                                                            //~vaa0I~
		dlcmdwildrenamemsg(0,newname);                             //~vaa0I~
      	return 0;                                                  //~vaa0R~
      }                                                            //~vaa0I~
      else                                                         //~vaa0I~
#endif                                                             //~vaa0I~
      {                                                            //~vaa0I~
		UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFMASK|UDHFDDSETUP);//~5903I~
	    dlcmdupctr(plh);                                        //~5903I~
//  	return dirsavename(plh,newname);                        //~v05FR~//~va00R~
//  	return BYUTF8_dirsavename(plh,newname);                    //~va0GR~
#ifdef UNX                                                         //~vaa0I~
	    if (Pplc->UDLCcmd!='U')                                    //~vaa0I~
	    	if (swwildmultiple)                                    //~vaa0I~
				dlcmdresetwildmultiple(0,pfh,pdh,fullpathname);    //~vaa0R~
#endif                                                             //~vaa0I~
    	return dirsavename(plh,newname);                           //~va0GR~
      }                                                            //~vaa0I~
	}                                                           //~5826I~
    if (Pplc->UDLCcmd!='U')	//undo rename,called from dlcmdundel//~v05NI~
		dirsetflderr(Ppcw,plh,PANL310RENAME);//reverse err fld  //~v05NR~
    return 4;                                                   //~5826I~
}//dlcmdrename                                                  //~5826I~
                                                                //~5906I~
//****************************************************************//~v042I~
// dlcmdcopymove                                                //~v05jR~
// copy and move                                                //~v05jR~
//*ret  :rc                                                     //~v042I~
//****************************************************************//~v042I~
int dlcmdcopymove(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)//~v05jR~
{                                                               //~v042I~
	UCHAR  *cparm,*pc,*pcn;                                     //~v05OR~
    int rc,pathlen;                                             //~v05OR~
    int opdno;                                                     //~v09aI~
    int alloclen;                                                  //~v09aI~
    int sw_skip_savename=0;                                        //~v60qI~
    int ii;                                                        //~v62PI~
    PULINEH plh;                                                //~v042I~
    PUDIRLH pdh;                                                //~v042I~
    PUFILEH pfh;                                                   //~v53ZR~
	UCHAR  dhname[_MAX_PATH];                                   //~v05OR~
	UCHAR  opname[_MAX_PATH+MAXCOLUMN];                            //~v59hR~
//  UCHAR  copyparm[MAXCOLUMN];                                    //~v62PR~
    UCHAR  copyparm[_MAX_PATH+MAXCOLUMN];                          //~v62PI~
//  UCHAR  parsewk[_MAX_PATH];                                     //~v62PR~
    UCHAR  parsewk[_MAX_PATH+MAXCOLUMN];                           //~v62PI~
#ifdef FTPSUPP                                                     //~v717I~
    PUFTPHOST puftph;                                              //~v717I~
#endif                                                             //~v717I~
#ifdef UNX                                                         //~vaa0I~
    int swwildnameundo=0;                                          //~vaa0I~
#endif                                                             //~vaa0I~
//*******************                                           //~v042I~
//	pc=cparm=UALLOCM((UINT)(_MAX_PATH+Gscrwidth+3));               //~v09aR~
  	alloclen=_MAX_PATH*2+Gscrwidth+3;                              //~v09aR~
  	pc=cparm=UALLOCM((UINT)alloclen);                              //~v09aI~
    UALLOCCHK(cparm,UALLOC_FAILED);                             //~v04dI~
    *copyparm=0;                                                   //~v59hI~
//  *pc++='\"';		//for space containing file                    //~v09aR~
//  pco=pc;                                                     //~v05OR~
    plh=Pplc->UDLCplh;                                          //~v042I~
    pfh=UGETPFH(plh);                                              //~v53ZI~
    pdh=UGETPDH(plh);                                           //~v042I~
	if (dlcgetfullname(pdh,dhname))                             //~v05OR~
    {                                                           //~v05GM~
    	ufree(cparm);                                           //~v05GM~
    	return 4;                                               //~v05GM~
	}                                                           //~v05GM~
//  pathlen=PATHLEN(pc);                                        //~v05OR~
    if (Pplc->UDLCcmd=='U')	//undo rename,called from dlcmdundel//~v05NM~
    {                                                           //~v05NI~
#ifdef UNX                                                         //~vaa0I~
        swwildnameundo=!FILEISREMOTE(pfh) && (pdh->UDHattr & FILE_WILDNAME);//~vaa0I~
        if (swwildnameundo)                                        //~vaa0I~
        {                                                          //~vaa0I~
        	pathlen=PATHLEN(dhname);                               //~vaa0I~
//      	ufilerepwildname(0,dhname+pathlen,pdh->UDHinode);      //~vb06R~
        	ufilerepwildname(0,dhname+pathlen,(ULONG)(pdh->UDHinode));//~vb06I~
        }                                                          //~vaa0I~
#endif                                                             //~vaa0I~
		rc=filefind(dhname,0,0,FFNONFMSG|FFNODIRMSG);           //~v05OR~
		if (!rc || rc==16)// found dir                          //~v05NI~
        {                                                       //~v05NI~
	    	ufree(cparm);                                       //~v05NI~
  			return ufileexist(dhname,4);                        //~v05OR~
		}                                                       //~v05NI~
    	if (*pdh->UDHrenamesv==SAMEDIR)	//same dir move         //~v05OR~
//  		filefullpath2(pc,pdh->UDHrenamesv,_MAX_PATH,dhname);//consider same dir//~v09aR~
//    		filefullpath2(opname,pdh->UDHrenamesv,_MAX_PATH,dhname);//consider same dir//~v09aI~//~va00R~
    		filefullpath2(opname,PDH_UDHrenamesv(pdh),_MAX_PATH,dhname);//consider same dir//~va00M~
    	else                                                    //~v05OR~
//      	strcpy(pc,pdh->UDHrenamesv);                           //~v09aR~
//      	strcpy(opname,pdh->UDHrenamesv);                       //~v09aI~//~va00R~
        	strcpy(opname,PDH_UDHrenamesv(pdh));                   //~va00M~
        uparsein(opname,pc,alloclen,",",'\"');   //enclose by quate//~v09aR~
    }                                                           //~v05NI~
    else                                                           //~v09aR~
    {                                                              //~v71oI~
	    if (pdh->UDHattr & FILE_DIRECTORY)                         //~v71oI~
        {                                                          //~v71oI~
	    	if (Pplc->UDLCcmd=='C')	//undo rename,called from dlcmdundel//~v71oI~
            {                                                      //~vb7cI~
//  			dlcmdappendwildcard(0,pfh,pdh,dhname);             //~v71oR~//~vb7cR~
    			if (dlcmdappendwildcard(0,pfh,pdh,dhname,sizeof(dhname)))//~vb7cI~
                	return 4;                                      //~vb7cI~
            }                                                      //~vb7cI~
        }                                                          //~v71oI~
//      strcpy(pc,dhname);                                         //~v09aR~
        uparsein(dhname,pc,alloclen,",",'\"');   //enclose by quate//~v09aR~
    }                                                              //~v71oI~
    pc+=strlen(pc);                                             //~v042I~
//  *pc++='\"';		//for space containing file                    //~v09aR~
    *pc++=' ';		//cotinue for new name                      //~v04cI~
    if (Pplc->UDLCcmd=='C')	//copy cmd                          //~v05YI~
    {                                                           //~v05YI~
#ifdef UNX                                                         //~v20AI~
	    memcpy(pc,"-s ",3);	//default copy subdir,can be reset -s- //~v20AI~
#else  //!UNX                                                      //~v20AI~
	    memcpy(pc,"/s ",3);	//default copy subdir,can be reset /s-//~v05YI~
#endif //!UNX                                                      //~v20AI~
        pc+=3;                                                  //~v05YI~
    }                                                           //~v05YI~
    pcn=pc;                                                     //~v042I~
    if (Pplc->UDLCcmd=='U')	//undo rename,called from dlcmdundel//~v05NI~
//  	strcpy(pcn,dhname);	//target name by dlcgetfullname        //~v09aR~
//      uparsein(dhname,pcn,alloclen-(cparm-pcn),",",'\"');   //enclose by quate//~v09aI~//~vb06R~
        uparsein(dhname,pcn,alloclen-PTRDIFF(cparm,pcn),",",'\"');   //enclose by quate//~vb06I~
    else                                                        //~v05NI~
    {                                                              //~v07eI~
//  	if (!dirgetflddata(Ppcw,plh,PANL310RENAME,pcn))//len=0  //~v05OR~//~va00R~
#ifdef W32UNICODE                                                  //~vaw9I~
    	if (!dirgetflddata_l2f(DGFDL2FO_UD,Ppcw,plh,PANL310RENAME,pcn,NULL/*swl2f*/))//len=0//~vaw9R~
#else                                                              //~vaw9I~
    	if (!BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,pcn))//len=0//~va00R~
#endif                                                             //~vaw9I~
	    {                                                       //~v05NR~
        	dlcmdnodesterr();                                      //~v07eI~
			dirsetflderr(Ppcw,plh,PANL310RENAME);//reverse err fld//~v05NR~
    		ufree(cparm);                                       //~v05NR~
        	return 4;                                           //~v05NR~
    	}                                                       //~v05NR~
        strncpy(copyparm,pcn,sizeof(copyparm));                    //~v59hI~
        if (uparse(pcn,parsewk,&opdno,0,",")>1)	//drop quate       //~v09aI~
        {                                                          //~v09aI~
       		ufree(cparm);                                          //~v09aI~
   			return 4;                                              //~v09aI~
        }                                                          //~v09aI~
        if (USTRHEADIS(parsewk,FNMOF2NDSCR))                       //~vaiuR~
        	if (*pcn!='\"' && *pcn!='\'')                          //~vaiuR~
				if (!scrgetcw(-1))	//not split                    //~vaiuI~
                {                                                  //~vaiuI~
                	erronsinglescreen(pcn);                        //~vaiuI~
		       		ufree(cparm);                                  //~vaiuI~
   					return 4;                                      //~vaiuI~
                }                                                  //~vaiuI~
// 		if (!filefullpath2(opname,pcn,_MAX_PATH,dhname))	//consider :://~v09aR~
   		if (!filefullpath2(opname,parsewk,_MAX_PATH,dhname))	//consider :://~v09aI~
        {                                                          //~v07eI~
       		ufree(cparm);                                          //~v07eI~
   			return 4;                                              //~v07eI~
   		}                                                          //~v07eI~
//      if (WILDCARD(opname))   //contain * yet after *\ process   //~v47uR~
//          ufileeditname(dhname,opname,opname);    //determin target//~v47uR~
        if (Pplc->UDLCcmd=='M')                                    //~v62PI~
        {                                                          //~v62PI~
#ifdef W32                                                         //~van3I~
        	if (UDH_IS_WILDNAMEOK(pdh))                            //~van3I~
        	{                                                      //~van3I~
        		if (dcmdwildconf(0,Ppcw,dhname,pdh))  //confirmation chk//~van3I~
                {                                                  //~van3I~
  		       		ufree(cparm);                                  //~van3R~
            		return 4;                                      //~van3I~
                }                                                  //~van3I~
        	}                                                      //~van3I~
#endif                                                             //~van3I~
    	    if (WILDCARD(opname))   //contain * yet after *\ process//~v62PI~
            {                                                      //~v62PI~
        	    ufileeditname(DEN_DEFAULT_UNIX|DEN_DEFAULT_CASE,dhname,opname,opname);    //determin target//~v62PR~
//  	        uparsein(opname,pcn,alloclen-(cparm-pcn),",",'\"');   //enclose by quate//~v62PI~//~vb06R~
    	        uparsein(opname,pcn,alloclen-PTRDIFF(cparm,pcn),",",'\"');   //enclose by quate//~vb06I~
                strcpy(copyparm,pcn);                              //~v62PR~
                for (ii=opdno-1,pc=parsewk;ii>0;ii--)              //~v62PR~
                {             //copy option parm to save to renamesv//~v62PR~
                    pc+=strlen(pc)+1;                              //~v62PR~
                    strcat(copyparm," ");                          //~v62PR~
                    strcat(copyparm,pc);                           //~v62PR~
                }                                                  //~v62PR~
                strcpy(pcn,copyparm);	//dcmd parm(after wildcard rename done)//~v62PR~
            }                                                      //~v62PR~
            *copyparm=0;    //dont save optional parm because undo fail//~v62PI~
        }                                                          //~v62PI~
    }//copy or move                                                //~v07eI~
                                                                //~v042I~
	Ppcw->UCWparm=cparm;                                        //~v042I~
//#ifdef AAA                                                       //~v717R~
    if (Pplc->UDLCcmd=='C')                                     //~v05jI~
		rc=dcmd_xcopy(Ppcw);		//exec command proc         //~v05jR~
	else	//move or undo move                                 //~v05NR~
    {                                                           //~v05EI~
//      if (Pplc->UDLCcmd=='M')                                    //~v07eR~
//  		if (!filefullpath2(opname,pcn,_MAX_PATH,dhname))	//consider :://~v07eR~
//          {                                                      //~v07eR~
//      		ufree(cparm);                                      //~v07eR~
//  			return 4;                                          //~v07eR~
//  		}                                                      //~v07eR~
		rc=dcmd_xmove(Ppcw);		//exec command proc         //~v05jI~
    }                                                           //~v05EI~
    dlcfsiupdate(Ppcw);  //update free space info                  //~v09bR~
//#else                                                            //~v717R~
//	Ppcw->UCWreason=1;                                             //~v717R~
//    rc=0;                                                        //~v717R~
//#endif                                                           //~v717R~
	if (!rc)		//exec command proc                         //~v05jI~
    {                                                           //~v042I~
	  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr          //~v05rI~
	    if (Pplc->UDLCcmd=='C')                                 //~v05jI~
        {                                                          //~v60qI~
          if (UCBITCHK(pdh->UDHflag2,UDHF2MASKNAME)                //~v60qI~
          &&  !UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST)          //~v60qI~
          &&  pdh->UDHrenamesv && *pdh->UDHrenamesv)               //~v60qI~
		    sw_skip_savename=1;                                    //~v60qI~
          else                                                     //~v60qI~
    		UCBITON(pdh->UDHupdatetype,UDHUTCOPYO);             //~v05jR~
        }                                                          //~v60qI~
		else                                                    //~v05jI~
        {                                                       //~v05jI~
		    if (Pplc->UDLCcmd=='U')                             //~v05NI~
            {                                                   //~v05NI~
#ifdef UNX                                                         //~vaa0I~
		      if (!swwildnameundo)                                 //~vaa0I~
#endif                                                             //~vaa0I~
              {                                                    //~vaa0I~
				dlcmdlvlclear(Ppcw,pdh,1,0);//clear child,del entry//~v05NI~
			    dlcmdmoveflag(Ppcw,plh,pdh,0);	//upctr etc     //~v05NR~
				UCBITOFF(pdh->UDHupdatetype,UDHUTMOVEO);        //~v05NR~
                if (pdh->UDHtype==UDHTDIREXP)                   //~v05VR~
                {                                                  //~vbs7I~
			        UTRACEP("%s:set UDHTDIR dhname=%s\n",UTT,pdh->UDHname);//~vbs7I~
					pdh->UDHtype=UDHTDIR;                       //~v05VI~
                }                                                  //~vbs7I~
                *opname=0;	//clear rename fld by dirsavename   //~v05OR~
			    dlcmdresetparentsz(pdh,DLCPSZ_SZ|DLCPSZ_LC,        //~v10rI~
						pdh->UDHsize,plh->ULHlinenow);//update parent sz//~v10rI~
              }                                                    //~vaa0I~
			}                                                   //~v05NI~
            else                                                //~v05NI~
            {                                                   //~v05OI~
				dlcmdlvlclear(Ppcw,pdh,2,3);//all child and me,move flag on//~v05NR~
			    dlcmdresetparentsz(pdh,DLCPSZ_SZ|DLCPSZ_LC,        //~v10rI~
						0-pdh->UDHsize,-plh->ULHlinenow);//update parent sz//~v10rR~
//              pathlen=(int)strlen(opname);                       //~v07eR~
//              if (*(opname+pathlen-1)!='\\')	//not root         //~v07eR~
//              	if (Ppcw->UCWreason)//dcmd_xmove set,target is dir//~v07eR~
//                  	*(opname+pathlen++)='\\';		//padd fname//~v07eR~
//  				else                                           //~v07eR~
//                  	pathlen=0;			//target is file       //~v07eR~
//  			if (pathlen)                                       //~v07eR~
//              	strcpy(opname+pathlen,pdh->UDHname);	//pad fname//~v07eR~
//     			pathlen=PATHLEN(dhname);                           //~v07eR~
//              {                                                  //~v07eR~
//              	opname[0]=SAMEDIR;                             //~v07eR~
//  	    		strcpy(opname+1,opname+pathlen-1);	//only member name//~v07eR~
//  			}                                                  //~v07eR~
	        }                                                   //~v05OI~
//  	    rc=dirsavename(plh,opname);	//save newname             //~v07eR~
		}                                                       //~v05jI~
		if (Pplc->UDLCcmd!='U') //copy or move                     //~v07eI~
        {           //  			}                                                  //~v07eR~
                                               //~v07eI~
#ifdef FTPSUPP                                                     //~v717I~
    		uftpisremote(opname,&puftph);                          //~v717I~
  		  if (UFTPHISTSO(puftph)||FILEISTSO(pfh))	//target is TSO//~v717R~
          	dlcmdcopymoveeditrenamefld(Ppcw,Pplc,pfh,pdh,dhname,puftph,opname);//~v717I~
          else                                                     //~v717I~
          {                                                        //~v717I~
#endif                                                             //~v717I~
			if (Pplc->UDLCcmd=='M') //move return UCWreason        //~v07lM~
            {                                                      //~v07lI~
            pathlen=(int)strlen(opname);                           //~v07eI~
            if (PATHLEN(opname)!=pathlen)	//end by '\'           //~v07lR~
            {                                                      //~v53QI~
            	if (Ppcw->UCWreason)//dcmd_xmove set,target is dir //~v07eI~
//              	*(opname+pathlen++)='\\';		//padd fname   //~v19aR~
//              	*(opname+pathlen++)=DIR_SEPC;		//padd fname//~v53ZR~
                	*(opname+pathlen++)=pfh->UFHdirsepc;           //~v53ZI~
				else                                               //~v07eI~
                	pathlen=0;			//target is file           //~v07eI~
            }                                                      //~v53QI~
			if (pathlen)                                           //~v07eI~
            {                                                      //~van3I~
#ifdef W32                                                         //~van3I~
        	  if (UDH_IS_WILDNAMEOK(pdh))                          //~van3I~
            	strcpy(opname+pathlen,pdh->UDHalias);	//pad fname//~van3I~
              else                                                 //~van3I~
#endif                                                             //~van3I~
            	strcpy(opname+pathlen,pdh->UDHname);	//pad fname//~v07eI~
            }                                                      //~van3I~
            }                                                      //~v07lI~
   			pathlen=PATHLEN(dhname);                               //~v07eI~
#ifdef UNX                                                         //~v20zI~
       		if (!memcmp(dhname,opname,(UINT)pathlen)) //same dir   //~v20zI~
#else  //!UNX                                                      //~v20zI~
       		if (!memicmp(dhname,opname,(UINT)pathlen)) //same dir  //~v07eI~
#endif //!UNX                                                      //~v20zI~
            {                                                      //~v07eI~
            	opname[0]=SAMEDIR;                                 //~v07eI~
	    		strcpy(opname+1,opname+pathlen-1);	//only member name//~v07eI~
			}                                                      //~v07eI~
#ifdef FTPSUPP                                                     //~v717I~
          }//trg or src is not TSP                                 //~v717I~
#endif                                                             //~v717I~
        }                                                          //~v07eI~
//!"U"                                                             //~v717I~
#ifdef UNX                                                         //~vaa0I~
	 if (!swwildnameundo)                                          //~vaa0I~
#endif //!UNX                                                      //~vaa0I~
     {                                                             //~vaa0I~
        if (*copyparm)                                             //~v59hI~
	        strcpy(opname,copyparm);                               //~v59hR~
	  if (!sw_skip_savename)	//not copy dir mask specified      //~v60qI~
//  	rc=dirsavename(plh,opname);	//save newname                 //~v07eI~//~va00R~
//  	rc=BYUTF8_dirsavename(plh,opname);	//save by locale code  //~va0GR~
    	rc=dirsavename(plh,opname);	//save newname                 //~va0GR~
		UCBITOFF(pdh->UDHflag,UDHFLCMDIN2|UDHFDDSETUP);         //~v042I~
      }                                                            //~vaa0I~
#ifdef UNX                                                         //~vaa0I~
      else                                                         //~vaa0I~
      {                                                            //~vaa0I~
		dlcmdwildrenamemsg(0,dhname);                              //~vaa0I~
        rc=0;                                                      //~vaa0I~
      }                                                            //~vaa0I~
#endif //!UNX                                                      //~vaa0I~
	}                                                           //~v042I~
    else                                                        //~v042I~
    {                                                           //~v042I~
		dirsetflderr(Ppcw,plh,PANL310RENAME);//reverse err fld  //~v042I~
	}                                                           //~v042I~
    ufree(cparm);                                               //~v042I~
    return rc;                                                  //~v042I~
}//dlcmdcopymove                                                //~v05jR~
#ifdef FTPSUPP                                                     //~v717I~
//**************************************************************** //~v717I~
// dlcmdcopymove edit rename fld filename for TSO file             //~v717I~
//*ret  :rc                                                        //~v717I~
//**************************************************************** //~v717I~
int dlcmdcopymoveeditrenamefld(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUFILEH Ppfh,PUDIRLH Ppdh,char *Psrc,PUFTPHOST Ppuftph,char *Ptgt)//~v717R~
{                                                                  //~v717I~
	UCHAR  *pc;                                                    //~v717I~
    int pathlen,pathlen2;                                          //~v717I~
//*******************                                              //~v717I~
	if (UFTPHISTSO(Ppuftph))	//target is tso                    //~v717R~
    	strupr(Ptgt+Ppuftph->UFTPHhostnmlen+1);                    //~v717I~
	if (Pplc->UDLCcmd=='M') //move return UCWreason                //~v717I~
    {                                                              //~v717I~
//append membername when target is dir                             //~v717I~
        if (UFTPHISTSO(Ppuftph))    //target is tso                //~v71gI~
        {                                                          //~v71gI~
        	if (MEMBOFDSN(Ptgt)==0)                                //~v71gI~
	        	u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,Ptgt,Ppdh->UDHname,Ptgt);//~v71gI~
            strupr(Ptgt+Ppuftph->UFTPHhostnmlen+1);                //~v71gI~
        }                                                          //~v71gI~
        else	//tgt is local                                     //~v71gI~
        {                                                          //~v71gI~
//  		pathlen=strlen(Ptgt);                                  //~vb06R~
    		pathlen=(int)strlen(Ptgt);                             //~vb06I~
            if (PATHLEN(Ptgt)!=pathlen)	//end by '\'               //~v71gI~
            {                                                      //~v71gI~
        		if (Ppcw->UCWreason)//dcmd_xmove set,target is dir //~v71gR~
	                *(Ptgt+pathlen++)=DIR_SEPC;                    //~v71gR~
                else                                               //~v71gI~
                	pathlen=0;                                     //~v71gI~
            }                                                      //~v71gM~
            if (pathlen)                                           //~v71gI~
            	strcpy(Ptgt+pathlen,Ppdh->UDHname);	//pad fname    //~v717I~
        }                                                          //~v717I~
    }                                                              //~v717I~
	if (FILEISTSO(Ppfh))	//src is tso                           //~v717I~
		pathlen=u3270pathlen(U3PL_PARENTORDROPMEMBER,Psrc);        //~v717R~
    else                                                           //~v717I~
		pathlen=0;                                                 //~v71gR~
	if (UFTPHISTSO(Ppuftph))	//src is tso                       //~v717R~
		pathlen2=u3270pathlen(U3PL_PARENTORDROPMEMBER,Ptgt);       //~v717R~
    else                                                           //~v717I~
		pathlen2=0;                                                //~v71gR~
    if (pathlen==pathlen2&&!memicmp(Ptgt,Psrc,(UINT)pathlen)) //same dir//~v71gR~
    {                                                              //~v717I~
        pc=Ptgt;                                                   //~v717I~
        *pc++=SAMEDIR;                                             //~v717I~
        strcpy(pc,Ptgt+pathlen2-1);  //only member name            //~v717R~
        pc+=strlen(pc);                                            //~v717I~
        *(pc-1)=0;	//drop quote                                   //~v717R~
    }                                                              //~v717I~
    return 0;                                                      //~v717I~
}//dlcmdcopymoveeditrenamefld                                      //~v717I~
#endif                                                             //~v717I~
                                                                //~v042I~
//****************************************************************//~v05qI~
// dlcmdmoveflag                                                //~v05qI~
// delete flag set(called from dlcmdlvlclear)                   //~v05qI~
//*parm1:pcw                                                    //~v05qI~
//*parm2:plh                                                    //~v05qI~
//*parm3:pdh                                                    //~v05qI~
//*parm4:moved child sw                                         //~v05NI~
//*ret  :rc                                                     //~v05qI~
//****************************************************************//~v05qI~
int dlcmdmoveflag(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,int Pchildsw)//~v05NR~
{                                                               //~v05qI~
//*******************                                           //~v05qI~
	UCBITON(Ppdh->UDHupdatetype,UDHUTMOVEO|Pchildsw);           //~v05NR~
	UCBITON(Pplh->ULHflag,ULHFDRAW);			//redraw line   //~v05qI~
    dlcmdupctr(Pplh);                                           //~v05qI~
    return 0;                                                   //~v05qI~
}//dlcmdmoveflag                                                //~v05qI~
                                                                //~v05qI~
//****************************************************************//~5906I~
// dlcmdattrib                                                  //~5906I~
// attrib dlcmd                                                 //~5906I~
//*rc   :0                                                      //~5906I~
//****************************************************************//~5906I~
int dlcmdattrib(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy) //~5906R~
{                                                               //~5906I~
	UCHAR  fullpathname[_MAX_PATH];                             //~5906R~
//  UCHAR  attrinput[UDDATTRSZ+2+1];                               //~v53QR~
    UCHAR  attrinput[UDDATTRSZMAX+2+1];                            //~v53QI~
//#ifdef UNX                                                       //~v53QR~
    ULONG  attron=0,attroff=0,attrout;                             //~v19cI~
#ifdef UNX                                                         //~v53QI~
    int mdossw;                                                    //~v47CI~
//#else                                                            //~v53QR~
//    UCHAR  attron=0,attroff=0,attrout;                           //~v53QR~
#endif                                                             //~v19cI~
    PULINEH plh;                                                //~5906I~
    PUDIRLH pdh;                                                //~5906I~
    int rc;                                                        //~v59fM~
//#ifndef UNX                                                      //~v728R~
#ifdef FTPSUPP                                                     //~v59fR~
    PUFILEH pfh;                                                   //~v59fI~
#endif                                                             //~v59fI~
//#endif                                                           //~v728R~
//*******************                                           //~5906I~
    plh=Pplc->UDLCplh;                                          //~5906I~
    pdh=UGETPDH(plh);                                           //~5906I~
#ifdef FTPSUPP                                                     //~v728R~
    pfh=UGETPFH(plh);                                              //~v728R~
//  if (FILEISTSO(pfh))                                            //~v72pR~
//  	return errnotsupported("Attrib","TSO DataSet");            //~v72pR~
#endif                                                             //~v728R~
	if (dlcgetfullname(pdh,fullpathname))                       //~v05GI~
    	return 4;                                               //~v05GM~
	if (!dirgetflddata(Ppcw,plh,PANL310ATTR,attrinput))         //~5906R~
    {                                                           //~5906I~
		dlcmdnoattrerr();                                          //~v07eI~
		dirsetflderr(Ppcw,plh,PANL310ATTR);//reverse err fld    //~5906I~
        return 4;                                               //~5906I~
    }                                                           //~5906I~
#ifdef FTPSUPP                                                     //~v72pI~
  if (FILEISTSO(pfh))                                              //~v72pI~
  {                                                                //~v72pI~
  	rc=dlcmdattribtso(pfh,pdh,fullpathname,attrinput);             //~v72pR~
  	attrout=pdh->UDHattr;   //FILE_SPF may be changed to on        //~v72pI~
  }                                                                //~v72pR~
  else                                                             //~v72pI~
  {                                                                //~v72pI~
#endif                                                             //~v72pI~
	if (*attrinput!='+' && *attrinput!='-')                     //~5906R~
//#ifdef UNX                                                       //~v53QR~
    	attroff=0xffffffff;                                        //~v19cI~
//#else  //!UNX                                                    //~v53QR~
//        attroff=0xff;                                            //~v53QR~
//#endif //!UNX                                                    //~v53QR~
#ifdef UNX                                                         //~v47CI~
	mdossw=MDOSDISKOK(fullpathname);                               //~v47CI~
    if (pfh->UFHflag12 & UFHF12RWIN) //remote target is windows    //~vac2I~
	    mdossw|=DCACO_RWIN;	//mdos attr fmt                        //~vac2I~
	if (dcmdattrchk(attrinput,&attron,&attroff,mdossw))            //~v47CI~
#else  //!UNX                                                      //~v47CI~
//  if (dcmdattrchk(attrinput,&attron,&attroff))                   //~v59fI~
  #ifdef FTPSUPP                                                   //~v59fI~
    pfh=UGETPFH(plh);                                              //~v59fI~
   	if (FILEISREMOTE(pfh))                                         //~v59fI~
    {                                                              //~vac2I~
      if (UCBITCHK(pfh->UFHflag12,UFHF12RWIN))     //win->win      //~vac2I~
		rc=dcmdattrchk(attrinput,&attron,&attroff);                //~vac2I~
      else                                                         //~vac2I~
    	rc=dcmdattrchkunix(attrinput,&attron,&attroff);            //~v59fI~
    }                                                              //~vac2I~
    else                                                           //~v59fI~
  #endif                                                           //~v59fM~
		rc=dcmdattrchk(attrinput,&attron,&attroff);                //~v59fR~
    if (rc)                                                        //~v59fM~
#endif //!UNX                                                      //~v47CI~
    {                                                           //~5909I~
		dirsetflderr(Ppcw,plh,PANL310ATTR);//reverse err fld    //~5909I~
    	return 4;                                               //~5906I~
    }                                                           //~5909I~
//  if (!dcmdattrchng(fullpathname,attron,attroff,&attrout))       //~v59fR~
//#if ! defined(UNX) && defined(FTPSUPP)                             //~v59fI~//~vac2R~
   	if (FILEISREMOTE(pfh))                                         //~v59fI~
//		rc=dcmdattrchngunix(fullpathname,attron,attroff,&attrout); //~v59fI~//~vac2R~
		rc=dcmdattrchng_ftp(0,pfh->UFHpuftph,fullpathname,attron,attroff,&attrout);//~vac2I~
    else                                                           //~v59fI~
//#endif                                                             //~v59fI~//~vac2R~
    {                                                              //~vbz2I~
//#ifdef ARMXXE                                                      //~vbz2I~//+vbs7R~
//        if (IS_DOCPATH(fullpathname))                              //~vbz2I~//+vbs7R~
//        {                                                          //~vbz2I~//+vbs7R~
//            UCHAR  realPath[_MAX_PATH];                            //~vbz2I~//+vbs7R~
//            if (getParmRealPath(fullpathname,realPath)==0)         //~vbz2I~//+vbs7R~
//                strcpy(fullpathname,realPath);                     //~vbz2I~//+vbs7R~
//        }                                                          //~vbz2I~//+vbs7R~
//#endif                                                             //~vbz2I~//+vbs7R~
		rc=dcmdattrchng(fullpathname,attron,attroff,&attrout);     //~v59fI~
    }                                                              //~vbz2I~
#ifdef FTPSUPP                                                     //~v72pI~
  }//not TSO                                                       //~v72pI~
#endif                                                             //~v72pI~
    if (!rc)                                                       //~v59fI~
    {                                                           //~5906I~
    	pdh->UDHattr=attrout;                                   //~5906I~
		UCBITOFF(pdh->UDHflag,UDHFLCMDIN1|UDHFDDSETUP);         //~5906I~
	    dlcmdupctr(plh);                                        //~5906I~
	  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr          //~v05rI~
        return 0;                                               //~5906I~
	}                                                           //~5906I~
	dirsetflderr(Ppcw,plh,PANL310ATTR);//reverse err fld        //~5906I~
    return 4;                                                   //~5906I~
}//dlcmdattrib                                                  //~5906I~
#ifdef FTPSUPP                                                     //~v72pI~
//**************************************************************** //~v72pI~
// dlcmdattribtso                                                  //~v72pI~
// attrib dlcmd for tso                                            //~v72pI~
//*rc   :0                                                         //~v72pI~
//**************************************************************** //~v72pI~
int dlcmdattribtso(PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfpath,char *Pinpattr)//~v72pR~
{                                                                  //~v72pI~
    int rc,len,vv,mm,vvmm,opt;                                     //~v72pI~
    PDSSPFINFO spfi,spfinew;                                       //~v72pR~
    char *pc,*pc2;                                                 //~v72pI~
//*******************                                              //~v72pI~
	if (!(Ppdh->UDHattr & FILE_PDSMEMB && (Ppdh->UDHslinkattr>>16)==STDSPFLRECL))//~v72pR~
    {                                                              //~v72pI~
    	uerrmsg("SPF ver/mod change is available only for MEMBER of D/S with RECFM=Fx,LRECL=80",0);//~v72pR~
        return 4;                                                  //~v72pI~
    }                                                              //~v72pI~
    pc=Pinpattr+strspn(Pinpattr," ");                              //~v72pR~
    pc2=strpbrk(pc," -");                                          //~v72pI~
    if (pc2)                                                       //~v72pI~
//    	len=(ULONG)pc2-(ULONG)pc;                                  //~v72pI~//~vafkR~
//  	len=(ULPTR)pc2-(ULPTR)pc;                                  //~vb06R~
    	len=(int)((ULPTR)pc2-(ULPTR)pc);                           //~vb06I~
    else                                                           //~v72pI~
//  	len=strlen(pc);                                            //~vb06R~
    	len=(int)strlen(pc);                                       //~vb06I~
    if (len!=4 || unumlen(pc,0,4)!=4)  //0:decimal                 //~v72pR~
    {                                                              //~v72pI~
    	uerrmsg("SPF version/modification(%s) is not valid 4byte numeric vvmm fotmat",0,//~v72pI~
        			Pinpattr);                                     //~v72pI~
        return 4;                                                  //~v72pI~
    }                                                              //~v72pI~
    vvmm=atoi(pc);                                                 //~v72pR~
    vv=vvmm/100;                                                   //~v72pI~
    mm=vvmm%100;                                                   //~v72pI~
    memset(&spfi,0,PDSSPFINFOSZ);                                  //~v72pI~
    spfi.SPFIver=vv;                                               //~v72pI~
    spfi.SPFImod=mm;                                               //~v72pI~
    opt=U3270SPFO_VER|U3270SPFO_MOD;                               //~v72pR~
    if (rc=u3270spfupdate(opt,Ppfh->UFHpuftph,Pfpath,&spfi,&spfinew),rc)//~v72pR~
    	return rc;                                                 //~v72pI~
    if (spfinew.SPFIflag & SPFIFSPF)	//new info gotten          //~v72pR~
    {                                                              //~v72pI~
    	TSOGN_SETVV(Ppdh->UDHgname,spfinew.SPFIver);      //save to pdh//~v72pR~
    	TSOGN_SETMM(Ppdh->UDHgname,spfinew.SPFImod);               //~v72pR~
    	TSOGN_SETCDATE(Ppdh->UDHgname,spfinew.SPFIcdate);          //~v72pI~
    	TSOGN_SETINITLINE(Ppdh->UDHgname,spfinew.SPFIinitcnt);     //~v72pR~
    	Ppdh->UDHslinksize=spfinew.SPFIlinecnt;                    //~v72pR~
		Ppdh->UDHattr|=FILE_SPF;                                   //~v72pR~
    }                                                              //~v72pI~
    return 0;                                                      //~v72pI~
}//dlcmdattribtso                                                  //~v72pI~
#endif	//FTPSUPP                                                  //~v72pI~
//****************************************************************//~v051I~
// dlcmdprint                                                   //~v051I~
// delete dlcmd                                                 //~v051I~
//*ret  :rc                                                     //~v051I~
//****************************************************************//~v051I~
int dlcmdprint(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)  //~v051I~
{                                                               //~v051I~
//  UCHAR  fullpathname[_MAX_PATH];                                //~v0g0R~
//  UCHAR  xpparm[4+_MAX_PATH];                                    //~v20FR~
    UCHAR  xpparm[8+_MAX_PATH];                                    //~v20FI~
    UINT ulen;                                                     //~v0g4I~
    PULINEH plh;                                                //~v05rI~
    int    qpos=0;                                                 //~v20FI~
    int rc;                                                        //~v57uI~
//#ifdef W32                                                       //~v57uR~
#ifdef FTPSUPP                                                     //~v57uI~
    PUFILEH pfh;                                                   //~v53ZR~
#endif                                                             //~v53ZR~
//*******************                                           //~v051I~
    plh=Pplc->UDLCplh;                                          //~v05rI~
#ifdef FTPSUPP                                                     //~v59hI~
    pfh=UGETPFH(plh);                                              //~v58NI~
#endif                                                             //~v59hI~
//  if (!Gprintcmd)	//xprint req                                   //~v07uR~
    if (UCBITCHK(Gprocstatus,GPROCSXPRINT))//use xprint            //~v07uR~
    {                                                           //~v058I~
#ifdef UNX                                                         //~v20AI~
        strcpy(xpparm,"-Yi ");                                     //~v20AI~
#else  //!UNX                                                      //~v20AI~
        strcpy(xpparm,"/Yi ");                                  //~v058I~
#endif //!UNX                                                      //~v20AI~
        *(xpparm+4)=' ';	//space for set '"'                    //~v20FI~
    	if (Pplc!=Splcxp)	//not last print entry              //~v058I~
        	return 0;		//already printed from stdin        //~v058I~
//  	filefullpath(xpparm+4,Sxpflist,_MAX_PATH);                 //~v20FR~
    	filefullpath(xpparm+5,Sxpflist,_MAX_PATH);                 //~v20FI~
		qpos=4;				//pos to set '"'                       //~v20FI~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
#ifdef W32                                                         //~v53ZR~
//      pfh=UGETPFH(plh);                                          //~v58NR~
      if (!FILEISREMOTE(pfh))                                      //~v53ZR~
#endif                                                             //~v53ZR~
	    if (UCBITCHK(Gopt4,GOPT4W95ALIASP))//use short filename parm//~v0g1I~
			ugetvfatalias(UGVFA_MSG|UGVFA_WILDCARD,xpparm+4,xpparm+4,_MAX_PATH);//~v0g1I~
#else                                                              //~v57uI~
	#ifdef FTPSUPP                                                 //~v57uI~
//      pfh=UGETPFH(plh);                                          //~v59hR~
    #endif                                                         //~v57uI~
#endif                                                             //~v0g1I~
    }                                                              //~v0g0I~
//        Ppcw->UCWparm=xpparm;                                    //~v0g0R~
//        filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr           //~v0g0R~
//        return dcmd_xprint(Ppcw);                                //~v0g0R~
//    }                                                            //~v0g0R~
    else                                                           //~v0g0I~
//    if (dlcgetfullname(UGETPDH(plh),fullpathname))               //~v0g0R~
#if defined(W32) || defined(DPMI) 	                               //~v0g1I~
     if (UCBITCHK(Gopt4,GOPT4W95ALIASP))//use short filename parm  //~v0g1I~
     {                                                             //~v0g1I~
//    if (dlcgetfullnamealias(UGETPDH(plh),xpparm))                //~v0g4R~
      if (dlcgetfullnamealias(UGETPDH(plh),xpparm+1))              //~v0g4I~
    	return 4;                                                  //~v0g1I~
     }                                                             //~v0g1I~
     else                                                          //~v0g1I~
#endif                                                             //~v0g1I~
//    if (dlcgetfullname(UGETPDH(plh),xpparm))                     //~v0g4R~
      if (dlcgetfullname(UGETPDH(plh),xpparm+1))                   //~v0g4I~
    	return 4;                                               //~v051I~
    Ppcw->UCWparm=xpparm;                                          //~v0g0I~
    if (!Gprintcmd)	//xprint req                                   //~v0g0I~
    {                                                              //~v0g0I~
        filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr             //~v0g0I~
	    Ppcw->UCWopdpot=0;	//parm,id of no *\ :: *                //~v11MI~
//      return dcmd_xprint(Ppcw);                                  //~v57uR~
        rc=dcmd_xprint(Ppcw);                                      //~v57uI~
#ifdef FTPSUPP                                                     //~v57uI~
  		if (FILEISREMOTE(pfh))                                     //~v57uI~
    		rc+=dlcxpdelremotetemp();                              //~v57uI~
#endif                                                             //~v57uI~
        return rc;                                                 //~v57uI~
    }                                                              //~v0g0I~
//  *xpparm='"';                                                   //~v20FR~
    *(xpparm+qpos)='"';                                            //~v20FI~
//  ulen=strlen(xpparm);                                           //~v0g4M~//~vb2ER~
    ulen=(UINT)strlen(xpparm);                                     //~vb2EI~
	*(xpparm+ulen++)='"';                                          //~v0g4M~
	*(xpparm+ulen)=0;                                              //~v0g4M~
	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~v05rI~
//  Ppcw->UCWparm=fullpathname;                                    //~v0g0R~
//  return dcmd_print(Ppcw);                                       //~v57uR~
    rc=dcmd_print(Ppcw);                                           //~v57uI~
#ifdef FTPSUPP                                                     //~v57uI~
    if (FILEISREMOTE(pfh))                                         //~v57uI~
        rc+=dlcxpdelremotetemp();                                  //~v57uI~
#endif                                                             //~v57uI~
    return rc;                                                     //~v57uI~
}//dlcmdprint                                                   //~v051I~
//****************************************************************//~v058I~
//!dlcmdxpflist                                                 //~v058R~
// setup xprint indirect file list                              //~v058R~
//*parm1:pcw                                                    //~v058I~
//*parm2:plc                                                    //~v058I~
//*parm3:record seq no(1 start,0 for eof)                       //~v058I~
//*ret  :0:ok,4 io err                                          //~v058I~
//****************************************************************//~v058I~
int dlcmdxpflist(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Precno)       //~v058R~
{                                                               //~v058I~
//  UCHAR  fullpathname[_MAX_PATH+1];                              //~v57uR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va57I~
    UCHAR  fullpathname[1+_MAX_PATH+1+_MAX_PATH+1+_MAX_PATH]; //<  //~va57I~
#else                                                              //~va57I~
    UCHAR  fullpathname[1+_MAX_PATH+1+_MAX_PATH+1]; //<            //~v57uI~
#endif                                                             //~va57I~
	UCHAR  fullxpfl[_MAX_PATH];                                 //~v058R~
	PUDIRLH pdh;                                                   //~v57uI~
    int rc;                                                     //~v058I~
static FILE *Sfh=0;                                                //~v54jR~
    PUFILEH pfh;                                                   //~v71qI~
#ifdef FTPSUPP                                                     //~v57BI~
    int pathlen;                                                   //~v57BM~
//  PUFILEH pfh;                                                   //~v71qR~
#endif                                                             //~v57BI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    UFILEH wkfh;                                                   //~va50I~
    long  profileflag;                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*******************                                           //~v058I~
//#ifdef FTPSUPP                                                   //~v71qR~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v57vM~
//#endif                                                           //~v71qR~
	if (!filefullpath(fullxpfl,Sxpflist,_MAX_PATH))             //~v058R~
        return 4;   //full path err                             //~v058R~
	if (!Precno)	//last call                                 //~v058I~
    {                                                           //~v058I~
    	if (Sfh)                                                //~v058I~
		    fileclose(fullxpfl,Sfh);                            //~v058R~
		Sfh=0;                                                  //~v058I~
        Splcxp=Pplc;	//xprint kick(last 'P' lcmd plc)        //~v058I~
        return 0;	                                            //~v058I~
	}                                                           //~v058I~
	if (Precno==1)	//first call                                //~v058I~
    	if (!(Sfh=fileopen(fullxpfl,"w")))                      //~v058R~
        	return 4;   //open err                              //~v058I~
    Gdcmdtempf|=GDCMDTEMPF_DLCMDP; //del at term                   //~v639I~
	pdh=UGETPDH(Pplc->UDLCplh);                                    //~v57uI~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
  if (UCBITCHK(Gopt4,GOPT4W95ALIASP))//use short filename parm     //~v0g1I~
  {                                                                //~v0g1I~
//  if (dlcgetfullnamealias(UGETPDH(Pplc->UDLCplh),fullpathname))  //~v57uR~
    if (dlcgetfullnamealias(pdh,fullpathname))                     //~v57uI~
    	return 4;                                                  //~v0g1I~
  }                                                                //~v0g1I~
  else                                                             //~v0g1I~
#endif                                                             //~v0g1I~
//  if (dlcgetfullname(UGETPDH(Pplc->UDLCplh),fullpathname))       //~v57uR~
//  if (dlcgetfullname(pdh,fullpathname))                          //~v57uI~//~vb2sR~
    if (dlcgetfullnamefilejunctiontarget(pdh,fullpathname))        //~vb2sI~
    	return 4;                                               //~v058I~
#ifdef FTPSUPP                                                     //~v57BI~
  if (FILEISTSO(pfh))                                              //~v717I~
  {                                                                //~v717I~
    if (pdh->UDHattr & FILE_DSNPATH)                               //~v717I~
        return u3270errdsnpath(fullpathname);                      //~v717I~
    pathlen=u3270pathlen(U3PL_PARENTORDROPMEMBER,fullpathname);//parent path or pds(drop member)//~v717R~
  }                                                                //~v717I~
  else                                                             //~v717I~
    pathlen=PATHLEN(fullpathname);//parent path                    //~v57vI~
#endif                                                             //~v57BI~
    if (pdh->UDHattr & FILE_DIRECTORY)                             //~v57vI~
    {                                                              //~v57vI~
//        if (pdh->UDHlevel)//not root dir                           //~v57vI~
//        {                                                          //~v57vI~
//#ifdef FTPSUPP                                                     //~v57vI~
//            if (FILEISREMOTE(pfh))                                 //~v57vR~
//            {                                                      //~v717I~
//              if (!FILEISTSO(pfh))                                 //~v717I~
//                strcat(fullpathname,FTP_DIR_SEPS);                 //~v57vR~
//            }                                                      //~v717I~
//            else                                                   //~v57vR~
//#endif                                                             //~v57vI~
//            strcat(fullpathname,DIR_SEPS);                         //~v57vR~
//        }                                                          //~v57vI~
//        if (UCBITCHK(pdh->UDHflag2,UDHF2MASKNAME)                  //~v57vR~
//        &&  !UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST)            //~v57vR~
//        &&  pdh->UDHrenamesv && *pdh->UDHrenamesv)                 //~v57vR~
//        {                                                          //~v717I~
//#ifdef FTPSUPP                                                     //~v717I~
//          if (FILEISTSO(pfh))                                      //~v717I~
//            u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,fullpathname,pdh->UDHrenamesv,fullpathname);//~v717R~
//          else                                                     //~v717I~
//#endif                                                             //~v717I~
//            strcat(fullpathname,pdh->UDHrenamesv);                 //~v57vI~
//        }                                                          //~v717I~
//        else                                                       //~v57vI~
//#ifdef FTPSUPP                                                     //~v57vI~
//          if (FILEISREMOTE(pfh))                                   //~v57vI~
//           if (FILEISTSO(pfh))                                     //~v717I~
//            u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,fullpathname,DIR_ALLMEMB,fullpathname);//~v717R~
//           else                                                    //~v717I~
//            strcat(fullpathname,FTP_DIR_ALLMEMB);                  //~v57vI~
//          else                                                     //~v57vI~
//#endif                                                             //~v57vI~
//            strcat(fullpathname,DIR_ALLMEMB);                      //~v57vI~
//  	dlcmdappendwildcard(DLCAW_ALLMEMB,pfh,pdh,fullpathname);   //~v71oR~//~vb7cR~
    	if (dlcmdappendwildcard(DLCAW_ALLMEMB,pfh,pdh,fullpathname,(int)sizeof(fullpathname)))//~vb7cI~
    		return 4;                                              //~vb7cI~
    }                                                              //~v57vI~
#ifdef FTPSUPP                                                     //~v57uI~
  	if (FILEISREMOTE(pfh))                                         //~v57uI~
    	if (dlcxpsetremotefname(pfh,pdh,fullpathname,pathlen,      //~v57vR~
								fullpathname,sizeof(fullpathname)))//~v57uI~
    		return 4;                                              //~v57uI~
#endif                                                             //~v57uI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (!(pdh->UDHattr & FILE_DIRECTORY))                          //~va50I~
    {                                                              //~va50I~
        memset(&wkfh,0,sizeof(wkfh));                              //~va57I~
#ifdef W32                                                         //~vb06I~
  	  	ufilesetfhfilename_reservedname(0,&wkfh,fullpathname);     //~vb06R~
#else                                                              //~vb06I~
		strcpy(wkfh.UFHfilename,fullpathname);                     //~va57I~
#endif                                                             //~vb06M~
		if (!fcmdprofgetprofile(0,&wkfh,&profileflag))             //~va50I~
        {                                                          //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			if (UCBITCHK(wkfh.UFHflag10,UFHF10EBC))                //~va50I~
				dcmdxpsetebcparm(0,&wkfh,fullpathname+strlen(fullpathname));//~va57I~
            else                                                   //~va50I~//~va57R~
            {                                                      //~vaj9I~
	    	if (UCBITCHK(wkfh.UFHflag8,UFHF8UTF8))                 //~va50I~//~va57R~
            	sprintf(fullpathname+strlen(fullpathname)," %c%s",CMDFLAG_PREFIX,XPUTF8OPT);//~va50I~//~va57R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            if (UCBITCHK(wkfh.UFHflag10,UFHF10RECORD) && wkfh.UFHlrecl)//~vaj9I~
            	sprintf(fullpathname+strlen(fullpathname)," %cR%d",CMDFLAG_PREFIX,wkfh.UFHlrecl);//~vaj9R~
            else                                                   //~vaj0I~
            if (UCBITCHK(wkfh.UFHflag13,UFHF13RV) && wkfh.UFHvfmt) //~vaj0I~
            	sprintf(fullpathname+strlen(fullpathname)," %cV%s",CMDFLAG_PREFIX,ufile5getVfmtstr(0,wkfh.UFHvfmt));//~vaj0I~
            }//dcmdxpsetebcparm set -R option                      //~vaj9I~
        }                                                          //~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	strcat(fullpathname,"\n");                                  //~v058I~
  	rc=fputs(fullpathname,Sfh);                                 //~v058R~
#ifdef DOS                                                      //~v058I~
    #ifdef DPMI					//DPMI version                     //~v095I~
    if (rc==-1)                                                    //~v095I~
    #else                       //not DPMI                         //~v095I~
    if (rc)                                                     //~v058I~
    #endif                      //DPMI or not                      //~v095I~
#else                                                           //~v058I~
    if (rc==-1)                                                 //~v058I~
#endif                                                          //~v058I~
    {                                                           //~v058I~
    	ufileapierr("fputs",fullxpfl,rc);                       //~v058R~
        return 4;                                               //~v058I~
	}                                                           //~v058I~
    return 0;                                                   //~v058I~
}//dlcmdxpflist                                                 //~v058R~
//**************************************************************** //~v71oR~
//!dlcmdappendwildcard                                             //~v71oR~
// append wildcard for dirlist                                     //~v71oR~
//**************************************************************** //~v71oR~
//int dlcmdappendwildcard(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfullpathname)//~v71oR~//~vb7cR~
int dlcmdappendwildcard(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfullpathname,int Pbuffsz)//~vb7cI~
{                                                                  //~v71oR~
	int wildsw;                                                    //~v71oI~
    int rc;                                                        //~vb7cI~
    char wkfpath[FTP_MAXPATH2];                                    //~vb7cI~
//*******************************                                  //~v71oR~
    wildsw=(UCBITCHK(Ppdh->UDHflag2,UDHF2MASKNAME)                 //~v71oI~
    &&  !UCBITCHK(Ppdh->UDHupdatetype,UDHUTNOTEXIST)               //~v71oI~
    &&  Ppdh->UDHrenamesv && *Ppdh->UDHrenamesv);                  //~v71oI~
    if (!wildsw && !(Popt & DLCAW_ALLMEMB))	//no wild and not ALLMEMB append req//~v71oR~
    	return 0;                                                  //~v71oI~
    UstrncpyZ(wkfpath,Pfullpathname,FTP_MAXPATH);                  //~vb7cI~
    if (Ppdh->UDHlevel)//not root dir                              //~v71oR~
    {                                                              //~v71oR~
#ifdef FTPSUPP                                                     //~v71oR~
        if (FILEISREMOTE(Ppfh))                                    //~v71oR~
        {                                                          //~v71oR~
            if (!FILEISTSO(Ppfh))                                  //~v71oR~
//              strcat(Pfullpathname,FTP_DIR_SEPS);                //~v71oR~//~vb7cR~
                strcat(wkfpath,FTP_DIR_SEPS);                      //~vb7cI~
        }                                                          //~v71oR~
        else                                                       //~v71oR~
#endif                                                             //~v71oR~
//          strcat(Pfullpathname,DIR_SEPS);                        //~v71oR~//~vb7cR~
            strcat(wkfpath,DIR_SEPS);                              //~vb7cI~
    }                                                              //~v71oR~
    if (wildsw)                                                    //~v71oR~
    {                                                              //~v71oR~
#ifdef FTPSUPP                                                     //~v71oR~
        if (FILEISTSO(Ppfh))                                       //~v71oR~
//          u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,Pfullpathname,Ppdh->UDHrenamesv,Pfullpathname);//~v71oR~//~va00R~
            u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,Pfullpathname,PDH_UDHrenamesv(Ppdh),Pfullpathname);//~va00M~
        else                                                       //~v71oR~
#endif                                                             //~v71oR~
//          strcat(Pfullpathname,Ppdh->UDHrenamesv);               //~v71oR~//~va00R~
//          strcat(Pfullpathname,PDH_UDHrenamesv(Ppdh));           //~va00M~//~vb7cR~
            strcat(wkfpath,PDH_UDHrenamesv(Ppdh));                 //~vb7cI~
    }                                                              //~v71oR~
    else                                                           //~v71oR~
#ifdef FTPSUPP                                                     //~v71oR~
        if (FILEISREMOTE(Ppfh))                                    //~v71oR~
            if (FILEISTSO(Ppfh))                                   //~v71oR~
                u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,Pfullpathname,DIR_ALLMEMB,Pfullpathname);//~v71oR~
            else                                                   //~v71oR~
//              strcat(Pfullpathname,FTP_DIR_ALLMEMB);             //~v71oR~//~vb7cR~
                strcat(wkfpath,FTP_DIR_ALLMEMB);                   //~vb7cI~
        else                                                       //~v71oR~
#endif                                                             //~v71oR~
//          strcat(Pfullpathname,DIR_ALLMEMB);                     //~v71oR~//~vb7cR~
            strcat(wkfpath,DIR_ALLMEMB);                           //~vb7cI~
//  return 0;                                                      //~v71oR~//~vb7cR~
    if (FILEISREMOTE(Ppfh) && FILEISTSO(Ppfh))                     //~vb7cI~
        rc=0;	//by u3270concatfilename                           //~vb7cI~
    else                                                           //~vb7cI~
    {                                                              //~vb7cI~
        UstrncpyZ(Pfullpathname,wkfpath,(size_t)Pbuffsz);          //~vb7cR~
        rc=UMAXPATHCHK_RC(wkfpath,(size_t)Pbuffsz,ENAMETOOLONG,1/*msgsw*/);//~vb7cR~
    }                                                              //~vb7cI~
    return rc;                                                     //~vb7cI~
}//dlcmdappendwildcard                                             //~v71oR~
#ifdef FTPSUPP                                                     //~v57uI~
//**************************************************************** //~v57BI~
//!dlcxpgettmpdir                                                  //~v57BI~
//mkdir temp dir for dir xprint                                    //~v57BI~
//**************************************************************** //~v57BI~
int dlcxpgettmpdir(char *Pptmpdir)                                 //~v57BI~
{                                                                  //~v57BI~
static int Smkdirsw=0;                                             //~v57BI~
	FILEFINDBUF3 ffb3;                                             //~v57BI~
//******************                                               //~v57BI~
    if (!Smkdirsw)                                                 //~v57BI~
    {                                                              //~v57BI~
	    filefullpath(Sxptmpdir,XPFTPWD,_MAX_PATH);//return fullpath//~v57BI~
    	if (ufstat(Sxptmpdir,&ffb3))	//workdir chk              //~v57BI~
        {                                                          //~v57BI~
        	if (umkdir(Sxptmpdir))                                 //~v57BI~
            	return 8;                                          //~v57BI~
        }                                                          //~v57BI~
        else                                                       //~v57BI~
        	if (!(ffb3.attrFile & FILE_DIRECTORY))                 //~v57BI~
            {                                                      //~v57BI~
            	uerrmsg("%s is not directory,delete and retry",0,  //~v57BI~
                		Sxptmpdir);                                //~v57BI~
                return 8;                                          //~v57BI~
            }                                                      //~v57BI~
        Smkdirsw=1;                                                //~v57BI~
    }//1st time                                                    //~v57BI~
    strcpy(Pptmpdir,Sxptmpdir);                                    //~v57BI~
    return 0;                                                      //~v57BI~
}//dlcxpgettmpdir                                                  //~v57BI~
//**************************************************************** //~v57uI~
//!dlcxpsetremotefname                                             //~v57uR~
//allocate local copy of remote file and return the xprint parm filename//~v57uI~
//parm3:wildcard concatinated fullpathname                         //~v57vI~
//parm4:pathlen of current pdh                                     //~v57vI~
//parm5:output print record                                        //~v57vI~
//**************************************************************** //~v57uI~
int dlcxpsetremotefname(PUFILEH Ppfh,PUDIRLH Ppdh,char *Ppremotefname,int Ppathlen,//~v57vR~
						char *Pxprecord,int Pbufflen)              //~v57vI~
{                                                                  //~v57uI~
//static int Smkdirsw=0;                                           //~v57BR~
//  FILEFINDBUF3 ffb3;                                             //~v57BR~
    int opt,dirsw,pathlen;                                         //~v57vR~
    int rc;                                                        //~v57BI~
    int rc2;                                                       //~v71jI~
//  UCHAR  wkout[1+_MAX_PATH+1+_MAX_PATH+1],wk[_MAX_PATH]; //<     //~v57vR~//~vbs7R~
    UCHAR  wkout[_MAX_PATH*2+DSN_MAXLEN+32],wk[_MAX_PATH]; //<     //~vbs7R~
    UCHAR  wkdsn[DSN_MAXLEN];                                      //~v71jI~
    UCHAR  xptmpdir[_MAX_PATH];                                    //~v57BI~
//******************                                               //~v57uI~
//    if (!Smkdirsw)                                               //~v57BR~
//    {                                                            //~v57BR~
//        filefullpath(Sxptmpdir,XPFTPWD,_MAX_PATH);//return fullpath//~v57BR~
//        if (ufstat(Sxptmpdir,&ffb3))    //workdir chk            //~v57BR~
//        {                                                        //~v57BR~
//            if (umkdir(Sxptmpdir))                               //~v57BR~
//                return 8;                                        //~v57BR~
//        }                                                        //~v57BR~
//        else                                                     //~v57BR~
//            if (!(ffb3.attrFile & FILE_DIRECTORY))               //~v57BR~
//            {                                                    //~v57BR~
//                uerrmsg("%s is not directory,delete and retry",0,//~v57BR~
//                        Sxptmpdir);                              //~v57BR~
//                return 8;                                        //~v57BR~
//            }                                                    //~v57BR~
//        Smkdirsw=1;                                              //~v57BR~
//    }//1st time                                                  //~v57BR~
	if (rc=dlcxpgettmpdir(xptmpdir),rc)                            //~v57BR~
    	return rc;                                                 //~v57BI~
  	opt=XEFTP_GRC_PARMDIR;                                         //~v57uR~
    dirsw=Ppdh->UDHattr & FILE_DIRECTORY;                          //~v57uR~
    if (dirsw && Ppdh->UDHlevel)//not root dir                     //~v57vR~
    	opt|=XEFTP_GRC_SUBDIR;	//copy dir                         //~v57uR~
//	if (xeftpgetremotecopy(opt,Ppremotefname,Ppfh->UFHpuftph,Sxptmpdir))//~v57BR~
//	if (xeftpgetremotecopy(opt,Ppremotefname,Ppfh->UFHpuftph,xptmpdir))//~v71jR~
//  rc2=xeftpgetremotecopy(opt,Ppremotefname,Ppfh->UFHpuftph,xptmpdir);//~v8@sR~
//  rc2=xeftpgetremotecopy(opt,Ppremotefname,Ppfh->UFHpuftph,xptmpdir,Ppfh);//~v8@sR~//~vb7eR~
    rc2=xeftpgetremotecopy(opt,Ppremotefname,Ppfh->UFHpuftph,xptmpdir,sizeof(xptmpdir),Ppfh);//~vb7eI~
    if (rc2 && (rc2!=DCPY_RC_NOTCOPY||!FILEISTSO(Ppfh)))//ignore invalid membername//~v71jI~
    	return 4;                                                  //~v57uI~
  if (FILEISTSO(Ppfh))                                             //~v717R~
  {                                                                //~v717I~
    if (dirsw)                                                     //~v71jR~
    {                                                              //~v717I~
        u3270parsedsn(U3PD_DROPQUOTE|U3PD_DROPHOSTID,Ppremotefname,wkdsn,wk);		//membername//~v71jR~
    	sprintf(wkout,"<%s>%s%c%s%c%s",Ppremotefname,xptmpdir,DIR_SEPC,wkdsn,DIR_SEPC,wk);//~v71jR~
    }                                                              //~v717I~
    else                                                           //~v717I~
    if (Ppdh->UDHattr & FILE_PDSMEMB)                              //~v71jI~
    {                                                              //~v717I~
		u3270getlastname(0,Ppremotefname,wk);	//get membername or last pathname//~v717I~
    	sprintf(wkout,"<%s>%s%c%s",Ppremotefname,xptmpdir,DIR_SEPC,wk);//~v717I~
    }                                                              //~v717I~
    else                                                           //~v71jI~
    {                                                              //~v71jI~
        u3270parentdsn(U3PD_DROPQUOTE|U3PD_DROPHOSTID|U3PL_DROPMEMBER,Ppremotefname,wkdsn);		//membername//~v71jR~
    	sprintf(wkout,"<%s>%s%c%s",Ppremotefname,xptmpdir,DIR_SEPC,wkdsn);//~v71jI~
    }                                                              //~v71jI~
  }                                                                //~v717I~
  else                                                             //~v717I~
  {                                                                //~v717I~
    if (dirsw && Ppdh->UDHlevel) //dir+wildcard                    //~v57vR~
    {                                                              //~v57vI~
    	strcpy(wk,Ppremotefname+Ppathlen);                         //~v57vR~
        *(wk+FTP_PATHLEN(wk)-1)=DIR_SEPC; //rep remote by local seperator//~v57vR~
//  	sprintf(wkout,"<%s>%s%c%s",Ppremotefname,Sxptmpdir,DIR_SEPC,wk);//~v57BR~
    	sprintf(wkout,"<%s>%s%c%s",Ppremotefname,xptmpdir,DIR_SEPC,wk);//~v57BI~
    }                                                              //~v57vI~
    else                                                           //~v57vI~
    {                                                              //~v57vI~
        pathlen=PATHLEN(Ppremotefname);//curr filename             //~v57vR~
//  	sprintf(wkout,"<%s>%s%c%s",Ppremotefname,Sxptmpdir,DIR_SEPC,Ppremotefname+pathlen);//~v57BR~
    	sprintf(wkout,"<%s>%s%c%s",Ppremotefname,xptmpdir,DIR_SEPC,Ppremotefname+pathlen);//~v57BI~
    }                                                              //~v57vI~
  }//!TSO                                                          //~v717I~
    strcpy(Pxprecord,wkout);                                       //~v57vI~
    return 0;                                                      //~v57uI~
}//dlcxpsetremotefname                                             //~v57uI~
//**************************************************************** //~v57uI~
//!dlcdelremotetemp                                                //~v57uR~
//delete all copyed local temp file                                //~v57uR~
//**************************************************************** //~v57uI~
int dlcxpdelremotetemp(void)                                       //~v57uI~
{                                                                  //~v57uI~
	int ctr=0;                                                     //~v57uI~
//	char fpath[_MAX_PATH];                                         //~v57uI~//~vbs7R~
  	char fpath[_MAX_PATH+32];                                      //~vbs7I~
//******************                                               //~v57uI~
    if (!*Sxptmpdir)	//not created                              //~v57BR~
        return 4;                                                  //~v57BI~
	sprintf(fpath,"%s%c%s",Sxptmpdir,DIR_SEPC,DIR_ALLMEMB);        //~v57uR~
	return uxdelete(fpath,UXDELDIR,UXDELFORCE|UXDELNOMSG,          //~v57uR~
					&ctr,&ctr,&ctr);                               //~v57uI~
}//dlcxpdelremotetemp                                              //~v57uI~
#endif                                                             //~v57uI~
//**************************************************************** //~v09bR~
//!dlcfsiupdate                                                    //~v09bR~
// request disk free space info update                             //~v09bR~
//*parm1:pcw                                                       //~v09bR~
//*ret  :none                                                      //~v09bR~
//**************************************************************** //~v09bR~
void dlcfsiupdate(PUCLIENTWE Ppcw)                                 //~v09bR~
{                                                                  //~v09bR~
	PUFILEH  pfh;                                                  //~v09bR~
	PULINEH plh;                                                   //~v09bR~
	PUDIRLH pdh;                                                   //~v09bR~
//*******************                                              //~v09bR~
	pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v09bR~
	plh=UGETQTOP(&pfh->UFHlineque);                                //~v09bR~
	plh=UGETQNEXT(plh);                                            //~v09bR~
    pdh=UGETPDH(plh);                                              //~v09bR~
	UCBITON(plh->ULHflag,ULHFDRAW);			//redraw line          //~v09bR~
	UCBITOFF(pdh->UDHflag,UDHFDDSETUP);     //update free space info//~v09bR~
    return;                                                        //~v09bR~
}//dlcfsiupdate                                                    //~v09bR~
                                                                   //~v09bR~
//**************************************************************** //~v07eI~
//!dlcmdnoattrerr                                                  //~v07eI~
// err msg,no atribute input                                       //~v07eI~
//*ret  :4                                                         //~v07eI~
//**************************************************************** //~v07eI~
int dlcmdnoattrerr(void)                                           //~v07eI~
{                                                                  //~v07eI~
//*******************                                              //~v07eI~
    uerrmsg("Specify attribute",                                   //~v07eI~
            "属性(ASHR)を指定して下さい");                         //~v07eI~
	return 4;                                                      //~v07eI~
}//dlcmdnoattrerr                                                  //~v07eI~
                                                                   //~v07eI~
//**************************************************************** //~v07eI~
//!dlcmdnodesterr                                                  //~v07eI~
// err msg,no destination                                          //~v07eI~
//*ret  :4                                                         //~v07eI~
//**************************************************************** //~v07eI~
int dlcmdnodesterr(void)                                           //~v07eI~
{                                                                  //~v07eI~
//*******************                                              //~v07eI~
	uerrmsg("Specify desitination name",                           //~v07eI~
//          "複写/移動先名を指定して下さい");                      //~v11hR~
            "宛先名を指定して下さい");                             //~v11hI~
	return 4;                                                      //~v07eI~
}//dlcmdnodesterr                                                  //~v07eI~
//**************************************************************** //~vaiuM~
int erronsinglescreen(char *Pfnm)                                  //~vaiuM~
{                                                                  //~vaiuM~
	uerrmsg("%s, %s is for screen split case, enclose by quotation if not",//~vaiuR~
            "%s, %s は画面分割時用です、必要なら引用符で囲んでください",//~vaiuR~
            Pfnm,FNMOF2NDSCR);                                     //~vaiuR~
	return 4;                                                      //~vaiuM~
}                                                                  //~vaiuI~
#ifdef W32                                                         //~van2I~
//**************************************************************** //~van2I~
int dlcerrwildname(PUDIRLH Ppdh)                                   //~van2I~
{                                                                  //~van2I~
	uerrmsg("Wildcard member(%s) could not be processed(No 8.3 alias).",//~van2R~
            "ワイルドカードメンバー (%s) は処理できません(8.3形式の名前が設定されていません)",//~van2R~
            Ppdh->UDHname);                                        //~van2I~
	return 4;                                                      //~van2I~
}                                                                  //~van2I~
#endif                                                             //~van2I~
//**************************************************************** //~vaziI~
int dlcloadchk(int Popt,PUCLIENTWE Ppcw,PUDIRLH Ppdh,char *Pfpath) //~vaziI~
{                                                                  //~vaziI~
	int rc=0;                                                      //~vaziI~
//*******************************                                  //~vaziI~
	if (UGETQTOP(&Ppdh->UDHviewqh))                                //~vaziI~
    	rc=4;                                                      //~vaziI~
    else                                                           //~vaziI~
    {                                                              //~vaziI~
		if (!filesrchpfh(Pfpath,Pfpath,0/*&pfh*/))	//found        //~vaziI~
        	rc=4;                                                  //~vaziI~
    }                                                              //~vaziI~
    if (rc)                                                        //~vaziI~
    {                                                              //~vaziI~
		uerrmsg("%s is opend elsewhere",                           //~vaziI~
        	    "%s は 他でオープン中です",                        //~vaziI~
            	Pfpath);                                           //~vaziI~
    }                                                              //~vaziI~
    return rc;                                                     //~vaziI~
}//dlcloadchk                                                      //~vaziI~
