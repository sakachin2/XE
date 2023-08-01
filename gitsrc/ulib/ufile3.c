//*CID://+vc5nR~:                             update#=  361;       //+vc5nR~
//*************************************************************
//*ufile3.c
//*  uxcopy,uxmove                                                 //~v5cdR~
//*************************************************************
//vc5n 2023/07/19 copyDoc needs copy timestamp                     //+vc5nI~
//v77Y:230711 ARM;rename could not move to other folder.(ignore ufilefscomp and do copy + delete if not in same folder)//~v77YI~
//v77h:230424 ARM;copy                                             //~v77hI~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bb:160205 (BUG:W32)slink err(target is not dir) when junction target is root dir//~v6BbI~
//v6yf:150314 (BUG)xmove ignore /y for dir(err already exist for same name dir)//~v6yfI~
//v6uU:140608 support xcopy create option with rename              //~v6uUI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6ks:130706 (LNX)copy symlink timestamp by lutimes(checking HAVE_CONFIG)//~v6ksI~
//            lutime is since glibc2.6 and use utimensat(since kernel 2.6.22)//~v6ksI~
//v6kq:130705 no need to outoflink chk for junction and moutpoint  //~v6kqI~
//v6kp:130704 (BUG)relative slink is outof link err when copy to same dir//~v6kpI~
//v6kk:130704 (LNX)set dir timestamp of dir after member copyed to keep same timestamp as source dir//~v6kkI~
//v6kj:130704 copy directory timestamp(subdir and top when /c)     //~v6kjI~
//v6kf:130627 warning relative link may lose to linkage after copy //~v6kfI~
//v6kd:130625 copy/move warning not by rc but flag to keep rc= for successfull operation//~v6kdI~
//v6kb:130624 copy actual file for also directory copy when target copy option is on//~v6kbI~
//v6k5:130617 (Linux)treate slink like as windows slink            //~v6k5I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ufile3.c copy junction(file/dir) by uwinsub(create junction)//~v6k4I~
//                       copy juncfile to juncdir :copy into       //~v6k4I~
//                       copy juncfile to juncfile:rep             //~v6k4I~
//                       copy juncdir  to juncdir :copy into       //~v6k4R~
//                       copy juncdir  to juncfile:rep             //~v6k4I~
//                        To replace juncdir del then copy         //~v6k4I~
//                     move is same as copy                        //~v6k4I~
//                     option to skip slink copy                   //~v6k4I~
//v6hv:120808 (WIN)FileTimeToDosDateTime round up to next 2sec;it display different timestamp with dir cmd on cmd prompt//~v6hvI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~//~v6hhR~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v62c:090724 (LNX:BUG) mv cmd dose not copy directory when mv source is slink of dir//~v62cI~
//v61i:080117*xuerpchk(uerrmsg parameter chk)                      //~v61iI~
//v5jf:061015 (BUG)xmove clear missing for wildcard target case    //~v5jfI~
//v5je:061013 3270 support:xcopy/xmove                             //~v5jeI~
//v5fu:050322 dispaly filetime when copy bypass by /d option       //~v5fuI~
//v5fg:050125 skip override option for copy/move                   //~v5fgI~
//v5e2:040925 no /d support for os2 because DosCopy API dose not support//~v5e1I~
//v5e1:040920 support new xcopy option:copy override if updated    //~v5e1I~
//v5d3:040529 (BUG)xmove cannot override same name file            //~v5d3I~
//v5cf:040503 (WIN)xmo fail if same dir exist in target dir(MoveFile fail if atrget exist)//~v5cfI~
//            but drive is different MoveFile success.So reject both case//~v5cfI~
//v5cd:040425 xcopy support option to create src dir in target dir.//~v5cdR~
//            abandon default function to crete if target is root and source is dir//~v5cdI~
//v5b6:040124 (FTP)move(copy & del)support                         //~v5b6I~
//v5b2:040120 expand copy buff size(except DOSDOS) for performanceup//~v5awI~
//v5aw:040112 (BUG)append fail when subdir exist                   //~v5awI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v59r:031124 ftp support:copy/move                                //~v59rI~
//v56x:020805 (BUG)editfilename DBCS support                       //~v56xI~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v55g:020429 (UNX)allow root as copy source for mdso disk         //~v55gI~
//v55d:020428 (UNX:BUG)not found msg when diskfull for move(target is not created yet)//~v55cI~
//v55c:020428 (UNX:BUG)ROOTDIR chk for mdos disket                 //~v55cI~
//v559:020427 (UNX)disket support(mcopy) for copy file             //~v539I~
//v535:020315 copy from dir to wild card;copy file or copy dir itself//~v535I~
//            should not be dtermined by attrmask                  //~v535I~
//            if /s is specified xcopy or dlcmd(it is FILE_ALL) copy dir itselef//~v535I~
//v523:011228 (UNX)no copypathinfo option                          //~v523I~
//v522:011228 (Win)MoveFileEx return 120(Not Implemented)          //~v522I~
//v521:011228 (Win)use MoveFileEx for diffreent drive move not by copy and del//~v521I~
//v520:011228 support move override                                //~v520I~
//v379:000930 LINUX support(4 byte attr)                           //~v379I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v364:000927 LINUX support(file system chk for xmove)             //~v364I~
//v352:000926 LINUX support(permission err msg)                    //~v352I~
//v331 000901:(BUG:English mode)errmsg pattern err;%d-->%s         //~v331I~
//v327 000820:LINUX support                                        //~v327I~
//v291:991024 (BUG)append;mkdir for copy when source is dir/wildcard;//~v291I~
//            But for append,target should be file when it is nor exist.//~v291I~
//v280:990822 copy/move wildcard target support                    //~v280I~
//v277:990813 rename:wildcard target support                       //~v277I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -warning if mixed &&,||                              //~v053I~
//            -warning move (ULONG)-1 to byte(attrFile)            //~v053I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v014:960519:(DOS)findfirst may return dir flag depending on file seq in dir//~v014I~
//            copy x* cause  err that x*\*.* is not found          //~v014I~
//v013:960203:(DOS)support inter-dir  dir movement              //~v013I~
//v012:960203:(BUG)(DOS)attr change for dir failed because      //~v012I~
//            subdir mask bit must be dropped evenif for dir.      //~v013R~
//            so I can copy dir path info.                      //~v012I~
//v010:960121:uxdelete,read only chk option,force del  read only option//~v010I~
//960120:set last \\ when target is existing root for set undo name//~6120I~
//951126:inter drive move,chk already exist before copy         //~5B26I~
//951119:top dir del by option                                  //~5B26I~
//951111:add uxmove(inter drive support)
//v052:951014:xcopy file already exist msg for dir,it must be "in dir"
//950930:malloc/calloc rc chk for dos
//*950923 mask(/S option) support
//*950923 dos,protect repl when attr(S/H) down
//*950909 ucopy/umove/umkdir/urmdir
//*950903 uattrib
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5B12I~
#ifdef UNX                                                         //~v6b1I~
	#include <sys/time.h>                                          //~v6ksI~
	#include <unistd.h>                                            //~v6k5I~
	#include <dirent.h>                                            //~v6b1I~
#endif                                                             //~v6b1I~
//*******************************************************
#ifdef DOS
#else
    #ifdef W32                                                     //~v022I~
        #include <dos.h>                                           //~v022I~
//      #include <error.h>                                         //~v5e1R~
        #include <windows.h>                                       //~v5e1I~
    #else                                                          //~v022I~
    #define INCL_BASE
    #define INCL_DOSFILEMGR
    #include <os2.h>
    #endif                                                         //~v022I~
#endif

#ifdef HAVE_CONFIG_H                                               //~v6ksI~
	#include "config.h"	//chk lutimes() defined:HAVE_LUTIME        //~v6ksI~
    #ifdef HAVE_LUTIMES                                            //~v6ksI~
    	#define USE_LUTIMES       //allow define by Makefile for bin pkg//~v6ksI~
    #endif                                                         //~v6ksI~
#endif                                                             //~v6ksI~
//*******************************************************
#include <ulib.h>
#include <ufile.h>
#include <ufile2.h>
#include <ufile2l2.h>                                              //~v559R~
#include <ufile3.h>
#include <ufile4.h>                                                //~v6k5I~
#include <ufile5.h>                                                //~v280I~
#include <ufemsg.h>                                                //~v053I~
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>                                                  //~v59rI~
#include <ucalc2.h>                                                //~v6hvI~
#ifdef UNX                                                         //~v364I~
	#include <ufile1l.h>                                           //~v59rR~
	#include <ufiledoc.h>                                          //~v77hI~
#else  //!UNX                                                      //~v364I~
#endif //!UNX                                                      //~v364I~
#ifdef FTPSUPP                                                     //~v59rI~
	#include <uftp.h>                                              //~v59rI~
	#include <ufile1f.h>                                           //~v59rI~
	#include <u3270.h>                                             //~v5jeI~
	#include <u32702.h>                                            //~v5jeI~
#endif                                                             //~v59rI~
#include <uwinsub.h>                                               //~v6k4I~
#include <utrace.h>                                                //~v6ksM~
//*******************************************************
typedef struct _WCPARMCOPY  {                                   //~5916I~
                            UCHAR *wctfullpath;                 //~5916I~
                            int wcopt;                          //~5916I~
                            int wctpathlen;                     //~5916I~
                            unsigned wcattrmask;                //~5916I~
//                          int wctwild;    //target wild card     //~v291I~
                            int wcflag; //flag                     //~v291R~
#define CPYMV_TWILD    0x01     //target is wild card              //~v291I~
#define CPYMV_TFILE    0x02     //target is file                   //~v291I~
#define CPYMV_TNEW     0x04     //target is not found              //~v291I~
#define CPYMV_TROOT    0x08     //target is root                   //~v291I~
#define CPYMV_TDIR     0x10     //target is dir                    //~v291I~
#define CPYMV_TPATHERR 0x20     //target is path err               //~v5cdR~
                            int wcskipctr;                         //~v5e1I~
                            } WCPARMCOPY;                       //~5916I~
typedef struct _WCPARMMOVE  {
                            UCHAR *wctfullpath;
                            int wcopt;      //option to force override//~v520I~
                            int wcspathlen; //source path len
                            int wctpathlen; //target path len
                            unsigned wctattr;   //source attr     
//                          int wctwild;    //target wild card     //~v291R~
                            int wcflag; //flag                     //~v291I~
                            int wcskipctr;                         //~v5e1I~
                            } WCPARMMOVE;
#define ATTR_NOTFOUND (UINT)-1                                     //~v6k4I~
//*******************************************************
int ucopysub(UCHAR *Psource,UCHAR *Ptarget,                     //~5916R~
//              int Popt,unsigned Pattrmask,UCHAR Psattr);         //~v379R~
//              int Popt,unsigned Pattrmask,ULONG Psattr);         //~v5e1R~
                int Popt,unsigned Pattrmask,ULONG Psattr,          //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
//              time_t Pmodtime);                                  //~v6k5R~
                time_t Pmodtime,char *Pslink);                     //~v6k5I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                FILETIME Pmodtime,char *Pslink);                   //~v5e1R~//~v6k5R~
    #else                                                          //~v5e1R~
                FDATE Pfdate,FTIME Pftime);                        //~v5e1I~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
WILDAPPLYFUNC ufilewildcopy;                                    //~5916R~
//#if defined(DOS) || defined(W32) || defined(UNX)                 //~v559R~
//int udoscopy(UCHAR *Psource,UCHAR *Ptarget,int Popt);            //~v559R~
//#else                                                            //~v559R~
//#endif                                                           //~v559R~
int umovesub(UCHAR *Psource,UCHAR *Ptarget,
            int Popt,                                              //~v520I~
            int Pspathlen,int Ptpathlen,
//          UCHAR Psattr,UCHAR Ptattr);                            //~v5e1R~
//          UCHAR Psattr,UCHAR Ptattr,                             //~v5e1I~//~v6k4R~
            UINT  Psattr,UINT  Ptattr,                             //~v6k4I~
            UCHAR *Psrcslink,                                      //~v6k5I~
            FILEFINDBUF3 *Pptffb3,                                 //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                time_t Pmodtime);                                  //~v5e1I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                FILETIME Pmodtime);                                //~v5e1R~
    #else                                                          //~v5e1R~
                FDATE Pfdate,FTIME Pftime);                        //~v5e1I~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
int ufilecpymvflags(int Ptwild,int Ptrootsw,char *Ptfullpath,FILEFINDBUF3 *Ppfstat3t);//~v291I~
//int ufilecreateparmproc(char *Psfullpath,int Pspathlen,ULONG Psattr,char *Ptfullpath,int *Pptrootsw);//~v6kkR~
//int ufilecreateparmproc(char *Psfullpath,int Pspathlen,ULONG Psattr,char *Ptfullpath,int *Pptrootsw,char *Pcopysrc,char *Pcopytgt);//~v6kkI~//~v6uUR~
int ufilecreateparmproc(int Popt,char *Psfullpath,int Pspathlen,ULONG Psattr,char *Ptfullpath,int *Pptrootsw,char *Pcopysrc,char *Pcopytgt);//~v6uUI~
//int ufileerrdirandfile(char *Psource,char *Ptarget);             //~v59rR~
int ufileerrslinktarget(char *Psource,char *Ptarget,int Prc);      //~v6k4I~
int ufileerrslinkappend(char *Psource,char *Ptarget,int Prc);      //~v6k5I~
#ifdef UNX                                                         //~v6k5I~
int ufilesymlink_copy(int Popt,ULONG Psattr,char *Ptargetfnm,char *Pslinkname,char *Psrcslink);//~v6k5R~
#define UFSLO_COPYOVERRIDE          0x01                           //~v6k5I~
#define UFSLO_CHKTARGET             0x02     //target accessible chk//~v6k5I~
int ufilesymlink(int Popt,char *Ptargetfnm,char *Pslinkname);      //~v6ksI~
#define UFSLNKO_NOMSG               0x01     //no errmsg           //~v6ksI~
#endif                                                             //~v6k5I~
int ufileerrnotargetslink(int Prc,char *Psrc,char *Pslinktarget);  //~v6k5R~
int ufilegetslinkfinaltarget(char *Psrc,char *Pdest,char *Pslink,char *Pslinktarget,FILEFINDBUF3 *Ppffb3);//~v6k5R~
WILDAPPLYFUNC ufilewildmove;
//static int Sslinktargeterr;                                        //~v6k5I~//~v6kdR~
static int Sfinaltarget;	//delayed slink copyed with targeterr msg//~v6k5I~
static char *Ssrctop;	//to chk relative line out of target       //~v6kfI~
//*******************************************************
//*dummy for lib(same name as file)                     *
//*******************************************************
void ufile3(void)
{
    return;
}
//*******************************************************          //~v6b1I~
int invalidtargetfilename(int Popt,char *Ptfullpath)               //~v6b1I~
{                                                                  //~v6b1R~
	uerrmsg("Invalid target name (%s)",0,                          //~v6b1R~
				Ptfullpath);                                       //~v6b1I~
    return -1;                                                     //~v6b1I~
}//invalidtargetfilename                                           //~v6b1I~
#ifdef ARM                                                         //~v77YI~
//*******************************************************          //~v77YI~
int ufileIsSameDir(char *Psource,char *Ptarget)                    //~v77YI~
{                                                                  //~v77YI~
	int pathlen1,pathlen2,rc=0;                                    //~v77YI~
    pathlen1=PATHLEN(Psource);                                     //~v77YI~
    pathlen2=PATHLEN(Ptarget);                                     //~v77YI~
    if (pathlen1==pathlen2 && pathlen1)                            //~v77YI~
        rc=!memcmp(Psource,Ptarget,(UINT)pathlen1);                //~v77YI~
    UTRACEP("%s:rc=%d,pathelen=%d,src=%s,tgt=%s\n",UTT,rc,pathlen1,Psource,Ptarget);//~v77YI~
    return rc;                                                     //~v77YI~
}                                                                  //~v77YI~
#endif                                                             //~v77YI~
//****************************************************************//~5913I~
//uxcopy                                                        //~5913I~
//* file/dir copy                                               //~5B12I~
//*     over command (1)copy time stamp(os/2 only)              //~5B12R~
//                   (2)hidden/system can be copyed             //~5B12I~
//* wildcard target is not supported                            //~5913I~
//* wildcard source supported for over os/2 DosCopy             //~5915I~
//* root dir target support   for over os/2 DosCopy             //~5915I~
//*****                                                         //~5913I~
//*parm1:source filename                                        //~5913I~
//*parm2:target filename                                        //~5913I~
//*parm3:replace(01)/append(02)/fail if ea copy fail(04)        //~5B12R~
//*     :target root support(0x0100)                            //~5913I~
//*parm4:attribute mask for first level                         //~5913I~
//*retrn:rc                                                     //~5913I~
//****************************************************************//~5913I~
int uxcopy(UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask)//~5913I~
{                                                               //~5913I~
    UCHAR sfullpath[_MAX_PATH],tfullpath[_MAX_PATH];            //~5913I~
    FILEFINDBUF3 fstat3s={0};                                       //~5915I~//~v6h7R~
    FILEFINDBUF3 fstat3t;                                          //~v291I~
    int tpathlen,trootsw,spathlen,filectr;                      //~5923R~
    int twild;                                                     //~v280I~
    int flags;                                                     //~v291I~
    int rc;                                                        //~v5e1I~
    WCPARMCOPY wccopy;                                          //~5916R~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftpht,puftphs;                                     //~v5afI~
#endif                                                             //~v5afI~
#ifdef UNX                                                         //~v5cdI~
    int swildcard=0;    //source is wildname file                  //~v6b1R~
#else                                                              //~v5cdI~
    int twildrootsw;                                               //~v5cdM~
    UCHAR wkfpath[_MAX_PATH];                                      //~v5cdM~
#endif                                                             //~v5cdI~
	char copysrc[_MAX_PATH],copytgt[_MAX_PATH];                    //~v6kkI~
//********************                                          //~5913I~
    UTRACEP("%s:src=%s,tgt=%s\n",UTT,Psource,Ptarget);              //~v77hI~
	*copytgt=0;                                                    //~v6kkI~
//  Sslinktargeterr=0;                                             //~v6k5I~//~v6kdR~
	Ssrctop=Psource;	//to chk relative line out of target       //~v6kfI~
	Gufile_opt&=~GFILEOPT_RC_WARNING;                              //~v6kdI~
#ifdef FTPSUPP                                                     //~v59rI~
//	if (uftpisremote(Psource,&puftphs)		//ftp filename         //~v5afR~
//	||  uftpisremote(Ptarget,&puftpht))	//ftp filename             //~v5afR~
  	if ((uftpisremote(Psource,&puftphs)		//ftp filename         //~v5afI~
  	    +uftpisremote(Ptarget,&puftpht))!=0)	//ftp filename     //~v5afI~
    {                                                              //~v5jeI~
      if (UFTPHISTSO(puftphs)||UFTPHISTSO(puftpht))                //~v5jeI~
    	return u3270xcopy(Popt,puftphs,puftpht,Psource,Ptarget,Pattrmask);//~v5jeR~
      else                                                         //~v5jeI~
    	return uftpxcopy(puftphs,puftpht,Psource,Ptarget,Popt,Pattrmask);//~v5afR~
    }                                                              //~v5jeI~
#endif                                                             //~v59rI~
    Pattrmask=Pattrmask & FILE_ALL;     //drop invalid bit      //~5915I~
#ifdef LNX                                                         //~v6b1I~
	tpathlen=PATHLEN(Ptarget);                                     //~v6b1I~
    if (tpathlen>0 && WILDCARD(Ptarget+tpathlen))                  //~v6b1I~
#else                                                              //~v6b1I~
    if (WILDCARD(Ptarget))                                         //~v280R~
#endif                                                             //~v6b1I~
//      return ufilewildtarget(-1);                                //~v280R~
        twild=1;                                                   //~v291R~
    else                                                           //~v280I~
        twild=0;                                                   //~v280I~
                                                                //~v052I~
    if (!ufullpath(sfullpath,Psource,_MAX_PATH))                //~5913I~
        return -1;                                              //~5913I~
    if (!ufullpath(tfullpath,Ptarget,_MAX_PATH))                //~5913I~
        return -1;                                              //~5913I~
//*avoid source root case for successfull dosfindfirst          //~5913I~
//  trootsw=ROOTDIR(tfullpath);                                    //~v55cR~
    trootsw=ROOTDIR2(tfullpath);                                   //~v55cI~
    spathlen=PATHLEN(sfullpath);                                   //~v5cdI~
    if (!ROOTDIR2(sfullpath)) //dosfindfirst faile if root         //~v5cdI~
    {                                                              //~v6b1I~
#ifdef UNX                                                         //~v6b1I~
      swildcard=spathlen>0 && WILDCARD(sfullpath+spathlen);        //~v6b1I~
  	  if (!ufstat_wild(sfullpath,&fstat3s)) //exist                //~v6b1R~
      {                                                            //~v6b1I~
        if (fstat3s.attrFile & FILE_WILDNAME)                      //~v6b1I~
        	swildcard=0;                                           //~v6b1I~
      }                                                            //~v6b1I~
      else                                                         //~v6b1I~
#endif                                                             //~v6b1I~
      {                                                            //~v6b1I~
    	if (udosfindfirst(sfullpath,0,Pattrmask|FILE_DIRECTORY,&fstat3s))//~v5cdI~
     		return -1;                                             //~v5cdI~
      }                                                            //~v6b1I~
    }                                                              //~v6b1I~
    if (Popt & DCPY_CREATE)                                        //~v5cdM~
    {                                                              //~v5cdI~
//     	if (ufilecreateparmproc(sfullpath,spathlen,fstat3s.attrFile,tfullpath,&trootsw))//~v6kkR~
//     	if (ufilecreateparmproc(sfullpath,spathlen,fstat3s.attrFile,tfullpath,&trootsw,copysrc,copytgt))//~v6kkI~//~v6uUR~
       	if (ufilecreateparmproc(Popt,sfullpath,spathlen,fstat3s.attrFile,tfullpath,&trootsw,copysrc,copytgt))//~v6uUI~
        	return -1;                                             //~v5cdI~
    }                                                              //~v5cdI~
//set parm flags                                                   //~v291I~
    flags=ufilecpymvflags(twild,trootsw,tfullpath,&fstat3t);       //~v291I~
    if (flags==CPYMV_TPATHERR)                                     //~v5cdR~
    	return -1;                                                 //~v5cdI~
    tpathlen=(int)strlen(tfullpath);                               //~v5cdR~
//  spathlen=PATHLEN(sfullpath);                                   //~v5cdR~
//  if (ROOTDIR(sfullpath)) //dosfindfirst faile if root           //~v55cR~
    if (ROOTDIR2(sfullpath)) //dosfindfirst faile if root          //~v55cI~
    {                                                           //~5913I~
#ifdef UNX                                                         //~v364M~
	  if (ROOTDIR(sfullpath)) //dosfindfirst faile if root         //~v55gI~
      {                                                            //~v55gI~
        uerrmsg("Root cannot be copy source",                      //~v364I~
                    "ルートはコピーできません");                   //~v364M~
        return -1;                                                 //~v364I~
      }                                                            //~v55gI~
        strcpy(sfullpath+3,DIR_ALLMEMB);                           //~v55gI~
#else  //!UNX                                                      //~v364M~
        if (WILDCARD(tfullpath))   //source not wild card          //~v5cdI~
        {                                                          //~v5cdI~
        	strcpy(wkfpath,tfullpath);                             //~v5cdI~
        	*(wkfpath+PATHLEN(wkfpath))=0;                         //~v5cdI~
    		twildrootsw=ROOTDIR2(wkfpath);                         //~v5cdI~
        }                                                          //~v5cdI~
        else                                                       //~v5cdI~
    		twildrootsw=0;                                         //~v5cdI~
//      if (trootsw)                                               //~v5cdR~
        if (trootsw||twildrootsw)                                  //~v5cdR~
        {                                                       //~5913I~
                                                                   //~v364I~
            if (!(Popt & DCPY_ROOT))                            //~5917R~
            {                                                   //~5913I~
                uerrmsg("Option required when root to root",    //~5913I~
                        "ルート間コピーはオプションが必要です");//~5913I~
                return -1;                                      //~5913I~
            }                                                   //~5913I~
        }                                                       //~5913I~
        strcpy(sfullpath+3,DIR_ALLMEMB);                           //~v327R~
#endif //!UNX                                                      //~v364M~
    }                                                           //~5913I~
    else                                                        //~5915I~
    {                                                           //~5923I~
//*source exist chk for not found err apirc of target           //~5915M~
//      if (udosfindfirst(sfullpath,0,Pattrmask|FILE_DIRECTORY,&fstat3s))//~v5cdR~
//      	return -1;                                             //~v5cdR~
//UTRACEP("uxcopy source not root:%s,sattr=%d\n",sfullpath,fstat3s.attrFile);//~v014R~
//      if (Pattrmask!=FILE_ALL     //mask specified               //~v535R~
//      &&  UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir //~v535R~
        if (UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir //~v535I~
        {                                                       //~5923I~
//            if (trootsw)            //target is root             //~v5cdR~
//            {                                                    //~v5cdR~
//#ifdef UNX                                                       //~v5cdR~
//              if (ROOTDIR(tfullpath))                            //~v5cdR~
//                strcpy(tfullpath+1,sfullpath+spathlen);          //~v5cdR~
//              else                                               //~v5cdR~
//#endif                                                           //~v5cdR~
//                strcpy(tfullpath+3,sfullpath+spathlen);          //~v5cdR~
//                tpathlen=(int)strlen(tfullpath);                 //~v5cdR~
//                trootsw=0;                                       //~v5cdR~
//                flags=ufilecpymvflags(0,0,tfullpath,&fstat3t);   //~v5cdR~
//                if (flags & CPYMV_TNEW)                          //~v5cdR~
//                {                                                //~v5cdR~
//                    if (umkdir(tfullpath))                       //~v5cdR~
//                        return -1;                               //~v5cdR~
//                    flags=CPYMV_TDIR;                            //~v5cdR~
//                }                                                //~v5cdR~
//            }                                                    //~v5cdR~
#ifdef UNX                                                         //~v6b1I~
    		if (!swildcard)         //source wild card             //~v6b1I~
#else                                                              //~v6b1I~
            if (!WILDCARD(sfullpath))   //source not wild card     //~v5cdR~
#endif                                                             //~v6b1I~
            {                                                      //~v5cdR~
#ifdef W32                                                         //~v6k4I~
            	if (!FILE_MODEISNTFS_REPARSE(fstat3s.attrFile))    //~v6k4R~
                {                                                  //~v6k4I~
#endif                                                             //~v6k4I~
#ifdef UNX                                                         //~v6k5I~
            	if (!(fstat3s.attrFile & FILE_SLINK))              //~v6k5I~
                {                                                  //~v6k5I~
#endif                                                             //~v6k5I~
          	if (strlen(sfullpath)+sizeof(DIR_SEPS DIR_ALLMEMB)>=_MAX_PATH)//~v6H1I~
				return ufileTooLongFullpathName2(UWFRC_LONGNAME,sfullpath,DIR_SEPS DIR_ALLMEMB);//~v6H1I~
            strcat(sfullpath,DIR_SEPS DIR_ALLMEMB);                //~v327R~
            spathlen=PATHLEN(sfullpath);                        //~5923I~
#ifdef UNX                                                         //~v6k5I~
                }                                                  //~v6k5I~
#endif                                                             //~v6k5I~
#ifdef W32                                                         //~v6k4I~
                }                                                  //~v6k4I~
#endif                                                             //~v6k4I~
#ifdef UNX                                                         //~v6b1I~
          if (!(fstat3s.attrFile & FILE_SLINK))                    //~v6k5I~
    		swildcard=2;    //"*" is appended for directory        //~v6b1I~
#endif                                                             //~v6b1I~
            }                                                      //~v014R~
        }//src is dir                                              //~v5cdR~
    }                                                           //~5923I~
    Popt=Popt & ~DCPY_ROOT;                                     //~5917R~
                                                                   //~v291I~
    if (!(Popt & DCPY_APPEND))            //not append req         //~v291I~
        if (flags & CPYMV_TFILE)          //target file            //~v291I~
//#ifdef W32                                                       //~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
        if (!(fstat3s.attrFile & FILE_SLINK))//source dir          //~v6k4I~
#endif                                                             //~v6k4I~
#ifdef UNX                                                         //~v6b1I~
            if (swildcard         //source wild card               //~v6b1R~
#else                                                              //~v6b1I~
            if (WILDCARD(sfullpath)         //source wild card     //~v291I~
#endif                                                             //~v6b1I~
            ||  UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source dir//~v291I~
                return ufileerrdirandfile(Psource,Ptarget);        //~v291I~
#ifdef UNX                                                         //~v6b1I~
    if (swildcard)         //source wild card                      //~v6b1I~
#else                                                              //~v6b1I~
    if (WILDCARD(sfullpath))         //source wild card         //~5915I~
#endif                                                             //~v6b1I~
    {                                                           //~5915M~
//    if (!twild)   //make dir if target is not wildcard           //~v5cdR~
//    {                                                            //~v5cdR~
       if (Popt & DCPY_APPEND)            //append req             //~v291R~
       {                                                           //~v291I~
            if (flags & CPYMV_TDIR) //target is root               //~v291R~
                *(tfullpath+tpathlen++)=DIR_SEPC;                  //~v327R~
       }                                                           //~v291I~
       else                                                        //~v291I~
        if (!trootsw)   //target is not root                    //~5916R~
        {                                                       //~5916I~
//          if (ufstat(tfullpath,&fstat3t)) //not found            //~v291R~
            if (flags & CPYMV_TNEW) //not found                    //~v291I~
            {                                                      //~v291I~
                if (umkdir(tfullpath))                          //~5915I~
                    return -1;                                  //~5915M~
                flags=CPYMV_TDIR;                                  //~v291I~
            }                                                      //~v291I~
          if (flags & CPYMV_TDIR) //target is dir                  //~v291I~
            *(tfullpath+tpathlen++)=DIR_SEPC;                      //~v327R~
        }                                                       //~5916I~
        wccopy.wctfullpath  =tfullpath;                         //~5916I~
        wccopy.wcopt        =Popt;                              //~5916I~
        wccopy.wcopt       |=DCPY_WILDCOPYMOVE;                    //~v6k4I~
        wccopy.wcattrmask   =Pattrmask;                         //~5916I~
        wccopy.wctpathlen   =tpathlen;                          //~5916I~
//      wccopy.wctwild      =twild;                                //~v291R~
        wccopy.wcflag       =flags;                                //~v291R~
        wccopy.wcskipctr    =0;     //copy bypass ctr              //~v5e1I~
        filectr=0;  //for compile warning                       //~5916I~
//      return uwildfunc(0,         //bypass ea data               //~v6k5R~
        rc=uwildfunc(0,         //bypass ea data                   //~v6k5I~
                    sfullpath,Pattrmask,ufilewildcopy,&wccopy,&filectr);//~5916I~
//        if (!rc && Sslinktargeterr)                                //~v6k5R~//~v6kdR~
//            rc=DCPY_RC_WARNING;// -2                               //~v6k5R~//~v6kdR~
      if (!rc)                                                     //~v6H1I~
    	if (*copytgt)                                              //~v6kkI~
			ucopypathinfo(copysrc,copytgt);    //copy timestamp, ignore err//~v6kkI~
    	return rc;                                                 //~v6k5I~
//    }//!twild                                                    //~v5cdR~
    }                                                           //~5915M~
//not wild card                                                 //~5915I~
    if (twild)      //target is wild card                          //~v280I~
//      ufileeditname(sfullpath,tfullpath,tfullpath);    //determin target//~v56xR~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,         //~v56xI~
						sfullpath,tfullpath,tfullpath);    //determin target//~v56xI~
                                                                   //~v280M~
    if (trootsw)                                                //~5915M~
#ifdef UNX                                                         //~v55cI~
	  if (ROOTDIR(tfullpath))                                      //~v55cI~
      	strcpy(tfullpath+1,sfullpath+spathlen);                    //~v55cI~
      else                                                         //~v55cI~
#endif                                                             //~v55cI~
        strcpy(tfullpath+3,sfullpath+spathlen);                 //~5917R~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v327I~
    else                    //target is not root                //~5917I~
//      if (!UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY))//source is file//~5923R~//~v6k4R~
        if (!UCBITCHK(fstat3s.attrFile,FILE_DIRECTORY)//source is file//~v6k4I~
//#ifdef W32                                                       //~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
        ||  (fstat3s.attrFile & FILE_SLINK)//junction/slink/mountpoint, copy into target dir//~v6k4I~
#endif                                                             //~v6k4I~
        )                                                          //~v6k4I~
//          if (!ufstat(tfullpath,&fstat3t) //found                //~v291R~
//          &&  UCBITCHK(fstat3t.attrFile,FILE_DIRECTORY))//target dir//~v291R~
            if (flags & CPYMV_TDIR) //target is dir                //~v291I~
            {                                                   //~5917I~
          		if (tpathlen+1+(int)strlen(sfullpath+spathlen)>=_MAX_PATH)//~v6H1R~
                {                                                  //~v6H1I~
	                *(tfullpath+tpathlen)=0;                       //~v6H1I~
					return ufileTooLongFullpathName2(UWFRC_LONGNAME,tfullpath,sfullpath+spathlen);//~v6H1I~
                }                                                  //~v6H1I~
                *(tfullpath+tpathlen++)=DIR_SEPC;                  //~v327R~
                strcpy(tfullpath+tpathlen,sfullpath+spathlen);  //~5917I~
                if (WILDCARD(sfullpath+spathlen))                  //~v6b1I~
                    return invalidtargetfilename(0,tfullpath);     //~v6b1I~
            }                                                   //~5917I~
#else                                                           //~5917I~
#endif                                                          //~5917I~
//  return ucopysub(sfullpath,tfullpath,                           //~v5e1R~
    rc=ucopysub(sfullpath,tfullpath,                               //~v5e1I~
//                  Popt,Pattrmask,(UCHAR)fstat3s.attrFile);       //~v379R~
//                  Popt,Pattrmask,(ULONG)fstat3s.attrFile);       //~v5e1R~
                    Popt,Pattrmask,(ULONG)fstat3s.attrFile,        //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
//              	fstat3s.mtime);                                //~v6k5R~
                	fstat3s.mtime,fstat3s.slink);                  //~v6k5I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
//                  fstat3s.ftLastWriteTime);                      //~v5e1R~//~v6k5R~
                    fstat3s.ftLastWriteTime,fstat3s.slink);        //~v6k5I~
    #else                                                          //~v5e1R~
                	fstat3s.fdateLastWrite,fstat3s.ftimeLastWrite);//~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
//  if (rc==DCPY_RC_NOTCOPY)    //copy bypass by timestamp option  //~v5e1R~
//      rc=0;                                                      //~v5e1R~
//    if (!rc && Sslinktargeterr)                                    //~v6k5R~//~v6kdR~
//        rc=DCPY_RC_WARNING;// -2                                   //~v6k5R~//~v6kdR~
    if (*copytgt)                                                  //~v6kkI~
		ucopypathinfo(copysrc,copytgt);    //copy timestamp, ignore err//~v6kkI~
    return rc;                                                     //~v5e1I~
}//uxcopy                                                       //~5913I~
                                                                //~5913I~
//**************************************************************** //~v5cdI~
//!ufilecreateparmproc                                             //~v5cdI~
//* insert src dirname into target path                            //~v5cdI~
//* and mkdir if the dir is not found                              //~v5cdI~
//*retrn:rc                                                        //~v5cdR~
//**************************************************************** //~v5cdI~
//int ufilecreateparmproc(char *Psfullpath,int Pspathlen,ULONG Psattr,char *Ptfullpath,int *Pptrootsw)//~v6kkR~
//int ufilecreateparmproc(char *Psfullpath,int Pspathlen,ULONG Psattr,char *Ptfullpath,int *Pptrootsw,char *Pcopysrc,char *Pcopytgt)//~v6kkI~//~v6uUR~
int ufilecreateparmproc(int Popt,char *Psfullpath,int Pspathlen,ULONG Psattr,char *Ptfullpath,int *Pptrootsw,char *Pcopysrc,char *Pcopytgt)//~v6uUI~
{                                                                  //~v5cdI~
    FILEFINDBUF3 fstat3t;                                          //~v5cdR~
//  UCHAR srcdir[_MAX_PATH],tgtdir[_MAX_PATH];                     //~v5cdM~//~v6H1R~
    UCHAR srcdir[_MAX_PATH],tgtdir[_MAX_PATH2];                    //~v6H1R~
	int tpathlen,twildsw=0,srootsw=0;                              //~v5cdR~
    int rc;                                                        //~v6H1I~
//*********************                                            //~v5cdI~
#ifdef UNX                                                         //~v6b1I~
    if (!(Psattr & FILE_WILDNAME) && Pspathlen>0 && WILDCARD(Psfullpath+Pspathlen))        //source wild card//~v6b1R~
#else                                                              //~v6b1I~
    if (WILDCARD(Psfullpath))        //source wild card            //~v5cdI~
#endif                                                             //~v6b1I~
    {                                                              //~v5cdI~
        memcpy(srcdir,Psfullpath,(UINT)Pspathlen);//with last dirsepc//~v5cdI~
        *(srcdir+Pspathlen)=0;                                     //~v5cdI~
        if (ROOTDIR2(srcdir))                                      //~v5cdI~
        	srootsw=1;                                             //~v5cdI~
        else                                                       //~v5cdI~
        {                                                          //~v5cdI~
            *(srcdir+Pspathlen-1)=0;  //del last sepc              //~v5cdI~
            strcpy(srcdir,srcdir+PATHLEN(srcdir)-1);    //with dirsepc//~v5cdI~
        }                                                          //~v5cdI~
    }//wild src                                                    //~v5cdI~
    else                                                           //~v5cdI~
    {                                                              //~v5cdI~
        if (ROOTDIR2(Psfullpath))                                  //~v5cdR~
        	srootsw=1;                                             //~v5cdI~
        else                                                       //~v5cdI~
        {                                                          //~v5cdI~
    	    if (!UCBITCHK(Psattr,FILE_DIRECTORY))//source dir      //~v5cdR~
            {                                                      //~v5cdI~
                uerrmsg("Create option specified,but %s is not directrory.",//~v5cdI~
                        "Create オプションが指定されたが %s がディレクトリーでない。",//~v5cdI~
                         Psfullpath);                              //~v5cdI~
                return 4;                                          //~v5cdI~
            }                                                      //~v5cdI~
        	strcpy(srcdir,Psfullpath+Pspathlen-1);//with top dir sepc//~v5cdR~
        }                                                          //~v5cdI~
    }                                                              //~v5cdI~
    if (srootsw)                                                   //~v5cdI~
    {                                                              //~v5cdI~
        uerrmsg("Create option is invalid when source is route,",  //~v5cdI~
                "複写元がルートDirのときCreteオプションは使えません。");//~v5cdI~
        return 4;                                                  //~v5cdI~
    }                                                              //~v5cdI~
    tpathlen=PATHLEN(Ptfullpath);                                  //~v5cdR~
#ifdef UNX                                                         //~v6b1I~
    if (tpathlen>0 && WILDCARD(Ptfullpath+tpathlen))        //target wild card//~v6b1I~
#else                                                              //~v6b1I~
    if (WILDCARD(Ptfullpath))        //target wild card            //~v5cdR~
#endif                                                             //~v6b1I~
    {                                                              //~v5cdR~
        memcpy(tgtdir,Ptfullpath,(UINT)tpathlen-1);                //~v5cdR~
        if (tpathlen-1+(int)strlen(srcdir)>=_MAX_PATH)             //~v6H1I~
			return ufileTooLongFullpathName2(UWFRC_LONGNAME,tgtdir,srcdir);//~v6H1I~
        strcpy(tgtdir+tpathlen-1,srcdir);                          //~v5cdR~
        twildsw=1;                                                 //~v5cdR~
    }                                                              //~v5cdR~
    else                                                           //~v5cdR~
    {                                                              //~v5cdR~
        strcpy(tgtdir,Ptfullpath);                                 //~v5cdR~
      if (!(Popt & DCPY_CREATERENAME))	//create target top dir if not exist//~v6uUR~
      {                                                            //~v6uUI~
        if (*Pptrootsw)                                            //~v5cdR~
            strcat(tgtdir,srcdir+1);                               //~v5cdR~
        else                                                       //~v5cdR~
            strcat(tgtdir,srcdir);                                 //~v5cdR~
      }                                                            //~v6uUI~
    }                                                              //~v5cdR~
//  if (ufstat(tgtdir,&fstat3t)) //not found                       //~v5cdR~//~v6H1R~
    rc=(int)ufstat(tgtdir,&fstat3t);                               //~v6H1R~
    if (rc==ENAMETOOLONG)                                          //~v6H1I~
        return -1;                                                 //~v6H1I~
    if (rc) //not found                                            //~v6H1I~
    {                                                              //~v6kjI~
        if (umkdir(tgtdir))                                        //~v5cdR~
        {                                                          //~v6uUI~
          	if (Popt & DCPY_CREATERENAME)	//create target top dir if not exist//~v6uUR~
          	{                                                      //~v6uUI~
        		if (*Pptrootsw)                                    //~v6uUI~
            		strcat(tgtdir,srcdir+1);                       //~v6uUI~
        		else                                               //~v6uUI~
            		strcat(tgtdir,srcdir);                         //~v6uUI~
		        if (umkdir(tgtdir))                                //~v6uUI~
		            return -1;                                     //~v6uUI~
	      	}                                                      //~v6uUI~
            else                                                   //~v6uUI~
            return -1;                                             //~v5cdR~
        }                                                          //~v6uUI~
//    	ucopypathinfo(Psfullpath,tgtdir);    //ignore err          //~v6kkR~
		strcpy(Pcopysrc,Psfullpath);                               //~v6kkI~
		strcpy(Pcopytgt,tgtdir);                                   //~v6kkI~
    }                                                              //~v6kjI~
    if (twildsw)                                                   //~v5cdR~
        strcat(tgtdir,Ptfullpath+tpathlen-1);                      //~v5cdR~
    UMAXPATHCHK(tgtdir,_MAX_PATH,-1/*rc*/,1/*msgsw*/);             //~v6H1R~
    strcpy(Ptfullpath,tgtdir);                                     //~v5cdR~
    *Pptrootsw=0;   //no more root                                 //~v5cdR~
    return 0;                                                      //~v5cdI~
}//ufilecreateparmproc                                             //~v5cdI~
//**************************************************************** //~v291I~
//!ufilecpymvflags                                                 //~v291I~
//* set copy/move flags                                            //~v291I~
//*parm1:target wild card sw                                       //~v291I~
//*parm2:target rootsw                                             //~v291I~
//*parm3:target pathname                                           //~v291I~
//*retrn:flags                                                     //~v291I~
//**************************************************************** //~v291I~
int ufilecpymvflags(int Ptwild,int Ptrootsw,char *Ptfullpath,FILEFINDBUF3 *Ppfstat3t)//~v291I~
{                                                                  //~v291I~
    int flags;                                                     //~v291I~
    int pathlen,rc;                                                //~v5cdR~
    UCHAR fpath[_MAX_PATH];                                        //~v5cdI~
//*****************                                                //~v291I~
    if (Ptwild)                                                    //~v291I~
    {                                                              //~v5cdI~
        strcpy(fpath,Ptfullpath);                                  //~v5cdI~
        pathlen=PATHLEN(Ptfullpath);                               //~v5cdI~
        *(fpath+pathlen)=0;                                        //~v5cdR~
	 if (ROOTDIR2(fpath))                                          //~v5cdI~
        flags=CPYMV_TWILD;                                         //~v5cdI~
     else                                                          //~v5cdI~
     {                                                             //~v5cdI~
        *(fpath+pathlen-1)=0;                                      //~v5cdI~
	  if (ufstat(fpath,Ppfstat3t)) //not found                     //~v5cdR~
      {                                                            //~v5cdI~
      	ufilepatherr(Ptfullpath,4);                                //~v5cdI~
        flags=CPYMV_TPATHERR;                                      //~v5cdR~
      }                                                            //~v5cdI~
      else                                                         //~v5cdI~
        flags=CPYMV_TWILD;                                         //~v291I~
     }                                                             //~v5cdI~
    }                                                              //~v5cdI~
    else                                                           //~v291I~
    if (Ptrootsw)                                                  //~v291I~
        flags=CPYMV_TROOT;                                         //~v291I~
    else                                                           //~v291I~
//  if (ufstat(Ptfullpath,Ppfstat3t)) //not found                  //~v5cdR~
    if (rc=(int)ufstat(Ptfullpath,Ppfstat3t),rc) //not found       //~v5e1R~
    {                                                              //~v5cdI~
      if (rc==ERROR_PATH_NOT_FOUND)                                //~v5cdI~
      {                                                            //~v5cdI~
      	ufilepatherr(Ptfullpath,4);                                //~v5cdI~
        flags=CPYMV_TPATHERR;                                      //~v5cdI~
      }                                                            //~v5cdI~
      else                                                         //~v5cdI~
        flags=CPYMV_TNEW;                                          //~v291I~
    }                                                              //~v5cdI~
    else                                                           //~v291I~
    if (UCBITCHK(Ppfstat3t->attrFile,FILE_DIRECTORY))//target dir  //~v291I~
        flags=CPYMV_TDIR;                                          //~v291I~
    else                                                           //~v291I~
        flags=CPYMV_TFILE;                                         //~v291I~
    return flags;                                                  //~v291I~
}//ufilecpymvflags                                                 //~v291I~
//****************************************************************//~5910I~
//!uwildcopy                                                    //~5916R~
//* copy by wild card                                           //~5910I~
//*parm1:filename thru wildfunc                                 //~5916I~
//*parm2:dirlist ptr thru wildfunc                              //~5916I~
//*parm3:parm thru uwildfunc(ucopy parameter structure)         //~5916I~
//*retrn:rc                                                     //~5916I~
//****************************************************************//~5910I~
int ufilewildcopy(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~5916R~
{                                                               //~5910I~
    WCPARMCOPY *pwccopy;                                        //~5916R~
    UCHAR      *ptarget,wktarget[_MAX_PATH];                       //~v280I~
    int rc;                                                        //~v5e1I~
//********************                                          //~5910I~
    pwccopy=Pparm;                                              //~5916I~
//  if (pwccopy->wctwild)       //target is wild card              //~v291R~
    if (pwccopy->wcflag & CPYMV_TWILD)      //target is wild card  //~v291I~
    {                                                              //~v280I~
//      ufileeditname(Pfullpath,pwccopy->wctfullpath,wktarget);    //~v56xR~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,         //~v56xI~
						Pfullpath,pwccopy->wctfullpath,wktarget);  //~v56xI~
        ptarget=wktarget;                                          //~v280I~
    }                                                              //~v280I~
    else                                                           //~v280I~
    {                                                              //~v280I~
        if (pwccopy->wcflag & (CPYMV_TROOT|CPYMV_TDIR)) //target is root or dir//~v291R~
        {                                                          //~v6H1I~
          if (pwccopy->wctpathlen+(int)strlen(Ppudirlist->name)>=_MAX_PATH)//~v6H1I~
			return ufileTooLongFullpathName2(UWFRC_LONGNAME,pwccopy->wctfullpath,Ppudirlist->name);//~v6H1R~
    strcpy(pwccopy->wctfullpath+pwccopy->wctpathlen,Ppudirlist->name);//~5916R~
        }                                                          //~v6H1I~
        ptarget=pwccopy->wctfullpath;                              //~v280I~
#ifdef UNX                                                         //~v6b1I~
      	if (Ppudirlist->attr & FILE_WILDNAME)                      //~v6b1I~
      	{                                                          //~v6b1I~
    		if (pwccopy->wcopt & DCPY_REPWILDNAME)                 //~v6b1I~
            {                                                      //~v6b1I~
//				ufilerepwildname(0,ptarget+pwccopy->wctpathlen,Ppudirlist->inode);//~v6yfR~
  				ufilerepwildname(0,ptarget+pwccopy->wctpathlen,(ULONG)Ppudirlist->inode);//~v6yfI~
            	errwildname(EWN_COPYSRC|EWN_RENAME,NULL,ptarget);  //~v6b1R~
            }                                                      //~v6b1I~
            else                                                   //~v6b1I~
            	return errwildname(EWN_COPYSRC,NULL,ptarget);      //~v6b1R~
      	}                                                          //~v6b1I~
#endif                                                             //~v6b1I~
    }                                                              //~v280I~
//  return ucopysub(Pfullpath,                                     //~v5e1R~
    rc=ucopysub(Pfullpath,                                         //~v5e1I~
//                  pwccopy->wctfullpath,                          //~v280R~
                    ptarget,                                       //~v280I~
                    pwccopy->wcopt,                             //~5916R~
                    pwccopy->wcattrmask,                        //~5916R~
//                  Ppudirlist->attr);                             //~v5e1R~
                    Ppudirlist->attr,                              //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
//              	Ppudirlist->mtime);                            //~v6k5R~
//              	Ppudirlist->mtime,Ppudirlist->slink);          //~v6k5R~//~v6qaR~
                	Ppudirlist->mtime,UDIRLIST_GET_SLINKNAME_OR_NULLSTR(Ppudirlist));//~v6qaR~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
//              	Ppudirlist->ftLastWriteTime);                  //~v5e1R~//~v6k5R~
//              	Ppudirlist->ftLastWriteTime,Ppudirlist->slink);//~v6k5R~//~v6qaR~
                	Ppudirlist->ftLastWriteTime,UDIRLIST_GET_SLINKNAME_OR_NULLSTR(Ppudirlist));//~v6qaR~
    #else                                                          //~v5e1R~
                	Ppudirlist->date,Ppudirlist->time);            //~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
    if (rc==DCPY_RC_NOTCOPY)    //copy bypass by timestamp option  //~v5e1I~
    {                                                              //~v5e1I~
        pwccopy->wcskipctr++;                                      //~v5e1I~
        rc=0;                                                      //~v5e1I~
    }                                                              //~v5e1I~
    return rc;                                                     //~v5e1I~
}//ufilewildcopy                                                //~5910I~
//#ifdef W32                                                                //~5910I~//~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
//**************************************************************** //~v6k5I~
//copy slink target if target is file                              //~v6k5I~
//*retrn:1 if target is file,4:target err, 0:target is directory   //~v6kbR~
//**************************************************************** //~v6k5I~
int ucopysub_slinktarget(int *Pprc,int Popt,UCHAR *Psource,UCHAR *Ptarget,ULONG Psattr,//~v6k5R~
    #ifdef UNX                                                     //~v6k5I~
                time_t Pmodtime,                                   //~v6k5R~
    #else                                                          //~v6k5I~
                FILETIME Pmodtime,                                 //~v6k5R~
    #endif                                                         //~v6k5I~
                char *Pslink,                                      //~v6k5I~
                ULONG Pattrmask)                                   //~v6k5I~
{                                                                  //~v6k5I~
	FILEFINDBUF3 ffb3;                                             //~v6k5I~
    char slinktarget[_MAX_PATH];                                   //~v6k5I~
    int finaltarget;                                               //~v6k5I~
//********************                                             //~v6k5I~
    UTRACEP("ucopysub_slinktarget entry\n");                       //~v6k5I~
    Sfinaltarget=1;	//skip target err msg                          //~v6k5I~
	*Pprc=ufilegetslinkfinaltarget(Psource,Ptarget,Pslink,slinktarget,&ffb3);//~v6k5R~
    finaltarget=Sfinaltarget;                                      //~v6k5I~
    Sfinaltarget=0;                                                //~v6k5I~
    if (*Pprc)   //target not found,loop                           //~v6k5R~
    	return 4;  //skip copy                                     //~v6k5R~
    if (ffb3.attrFile & FILE_DIRECTORY)                            //~v6k5R~
    {                                                              //~v6k5I~
        if (finaltarget==2)	//msg later for dir                    //~v6k5I~
	    	ufileerrnotargetslink(-1,Psource,slinktarget);         //~v6k5R~
    	return 0;	//copy slink entry                             //~v6k5I~
    }                                                              //~v6k5I~
	*Pprc=ucopysub(slinktarget,Ptarget,                            //~v6k5I~
//                  Popt,Pattrmask,ffb3.attrFile,                  //~v6k5I~//~v6BxR~
                    Popt,(UINT)Pattrmask,ffb3.attrFile,            //~v6BxI~
//#ifdef UNX                                                       //~v6k5R~
                Pmodtime,ffb3.slink);                              //~v6k5I~
//#else                                                            //~v6k5R~
//                Pmodtime);                                       //~v6k5R~
//#endif                                                           //~v6k5R~
    UTRACEP("ucopysub_slinktarget rc=1,pprc=%d,src=%s,dest=%s\n",*Pprc,slinktarget,Ptarget);//~v6k5R~
    return 1;                                                      //~v6k5I~
}//ucopysub_slinktarget                                            //~v6k5I~//~v6kbR~
//**************************************************************** //~v6k4I~
//ucopysub_slink:copy slink or junction                            //~v6k4I~
//rc: -16: target is directory with actualfile copy option         //~v6kbI~
//**************************************************************** //~v6k4I~
int ucopysub_slink(int Popt,UCHAR *Psource,UCHAR *Ptarget,ULONG Psattr,//~v6k5R~
                ULONG Pattrmask,                                   //~v6k5I~
    #ifdef UNX                                                     //~v6k5R~
                time_t Pmodtime,char *Pslink,                      //~v6k5R~
    #else                                                          //~v6k5I~
                FILETIME Pmodtime,char *Pslink,                    //~v6k5R~
    #endif                                                         //~v6k5I~
		int Pflags,FILEFINDBUF3 *Ppfstat3t)                        //~v6k5I~
{                                                                  //~v6k4I~
    int texistsw;                                                  //~v6k4R~
    int rc;                                                        //~v6k4I~
	int repsw;                                                     //~v6k4I~
    ULONG tattr;                                                   //~v6k4I~
    int opt=0;                                                     //~v6k4I~
    int flags;                                                     //~v6k5I~
    int rc2;                                                       //~v6kbI~
//********************                                             //~v6k4I~
    UTRACEP("ucopysub_slink src=%s,tgt=%s,sattr=%x,attrmask=%x,flags=%x\n",Psource,Ptarget,Psattr,Pattrmask,Pflags);//~v6kpI~
  if (IS_SLINKERR(Psattr))                                         //~v6kbI~
//    Sslinktargeterr=1;                                             //~v6kbI~//~v6kdR~
	Gufile_opt|=GFILEOPT_RC_WARNING;                               //~v6kdI~
  else                                                             //~v6kbI~
  	if (Popt & DCPY_SLINKTGTF)                                     //~v6k5I~
    {                                                              //~v6k5I~
//    	if (ucopysub_slinktarget(&rc,Popt,Psource,Ptarget,Psattr,  //~v6k5I~//~v6kbR~
      	rc2=ucopysub_slinktarget(&rc,Popt,Psource,Ptarget,Psattr,  //~v6kbI~
      						Pmodtime,                              //~v6k5I~
//#ifdef UNX                                                       //~v6k5R~
      						Pslink,                                //~v6k5I~
//#endif                                                           //~v6k5R~
                            Pattrmask);                            //~v6k5I~//~v6kbR~
        if (rc2==1)	//target is file, copyed actual file           //~v6kbI~
        	return rc;	//target is file or target err             //~v6k5R~
        if (rc2==0)	//target is directory                          //~v6kbI~
        	return -FILE_DIRECTORY;                                //~v6kbR~
//      if target err/loop,copy slink entry                        //~v6kbR~
    }                                                              //~v6k5I~
    if (Popt & DCPY_CHKSLINKTGT)//copy/move chk slink target is accessible//~v6kfI~
    {                                                              //~v6kfI~
//    	rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Pslink);   //~v6kpR~
//    	rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Pslink,Ptarget);//~v6kqR~
//     	rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Pslink,Ptarget,Psattr);//~v6kqI~//~v6BxR~
      	rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Pslink,Ptarget,(UINT)Psattr);//~v6BxI~
    	if (rc2==4) //relativelink may be broken                   //~v6kfR~
        	Gufile_opt|=GFILEOPT_RC_WARNING;                       //~v6kfR~
    }                                                              //~v6kfI~
	tattr=Ppfstat3t->attrFile;                                     //~v6k4I~
    flags=Pflags;                                                  //~v6k4I~
    texistsw=!(flags & CPYMV_TNEW); //target existsw               //~v6k4I~
    UTRACEP("ucopysub_slink src=%s,dest=%s,sattr=%x,flag=%x,tattr=%x,texistsw=%d\n",Psource,Ptarget,Psattr,Pflags,tattr,texistsw);//~v6k4R~
    if (Popt & DCPY_SKIPSLINK)                                     //~v6k4I~
#ifdef W32                                                         //~v6k5I~
        if (FILE_MODEISNTFS_SLINK(Psattr))                         //~v6k5R~
#else                                                              //~v6k5I~
        if (FILE_ISSLINK(Psattr))                                  //~v6k5I~
#endif                                                             //~v6k5I~
    		if (Popt & DCPY_WILDCOPYMOVE)                          //~v6k4I~
            	return 0;                                          //~v6k4R~
    if (texistsw)                                                  //~v6k4I~
    {                                                              //~v6k4I~
	    if (!(tattr & FILE_SLINK))	//slink or junction            //~v6k4I~
        {                                                          //~v6k4I~
			return ufileerrslinktarget(Psource,Ptarget,-1);        //~v6k4I~
        }                                                          //~v6k4I~
        if (tattr & FILE_READONLY)                                 //~v6k4I~
            return ufilereadonly(Ptarget,EACCES);                  //~v6k4I~
                                                                   //~v6k4I~
        if (Popt & DCPY_APPEND)            //append req            //~v6k4I~
        {                                                          //~v6k4I~
			return ufileerrslinkappend(Psource,Ptarget,-1);        //~v6k5R~
        }                                                          //~v6k4I~
        if (Popt & DCPY_EXISTING)       //repl req                 //~v6k4I~
        {                                                          //~v6k4I~
            if (Popt & DCPY_REPOLD)       //repl old member only   //~v6k4I~
            {                                                      //~v6k4I~
#ifdef W32                                                         //~v6k5I~
                repsw=ufilecopytschk(Popt,Psource,Pmodtime,Ppfstat3t->ftLastWriteTime);//~v6k4I~
#else                                                              //~v6k5I~
                repsw=ufilecopytschk(Popt,Psource,Pmodtime,Ppfstat3t->mtime);//~v6k5R~
#endif                                                             //~v6k5I~
                if (repsw<=0)   //source<=target                   //~v6k4I~
                    return DCPY_RC_NOTCOPY;                        //~v6k4I~
            }                                                      //~v6k4I~
#ifdef W32                                                         //~v6k5I~
            opt|=UWINGTO_COPYOVERRIDE;                             //~v6k5I~
#else                                                              //~v6k5I~
            opt|=UFSLO_COPYOVERRIDE;                               //~v6k5R~
#endif                                                             //~v6k5I~
        }                                                          //~v6k4I~
        else                                                       //~v6k4I~
        if (Popt & DCPY_SKIPEXIST)       //skip override           //~v6k4I~
            return DCPY_RC_NOTCOPY;                                //~v6k4I~
        else                                                       //~v6k4I~
            return ufileexistcopy(Ptarget,-1);                     //~v6k4I~
    }//target exist                                                //~v6k4I~
#ifdef W32                                                         //~v6k5I~
    if (Popt & DCPY_CHKSLINKTGT)//copy/move chk slink target is accessible//~v6k5I~
    	opt|=UWINGTO_CHKTARGET;                                    //~v6k5I~
//  rc=uwinlnk_copy(opt,Psattr,Psource,Ptarget);                   //~v6k4R~//~v6k5R~
    rc=uwinlnk_copy(opt,Psattr,Psource,Ptarget,Pslink);            //~v6k5I~
#else                                                              //~v6k5I~
    if (Popt & DCPY_CHKSLINKTGT)//copy/move chk slink target is accessible//~v6k5M~
    	opt|=UFSLO_CHKTARGET;                                      //~v6k5M~
    rc=ufilesymlink_copy(opt,Psattr,Psource,Ptarget,Pslink);       //~v6k5R~
#endif                                                             //~v6k5I~
    UTRACEP("ucopysub_slink rc=%d\n",rc);                          //~v6k4I~
    return rc;                                                     //~v6k4I~
}//ucopysub_slink                                                  //~v6k4R~
#endif	//W32                                                      //~v6k4R~
//****************************************************************//~5909I~
//ucopysub                                                      //~5909R~
//* copy file(also time stamp)                                  //~5909I~
//*parm1:source fullpath filename                               //~5909R~
//*parm2:target fullpath filename                               //~5916R~
//*parm3:option append/replace                                  //~5916R~
//*parm4:source selection file attr                             //~5916R~
//*parm5:source attr                                            //~5923R~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ucopysub(UCHAR *Psource,UCHAR *Ptarget,                     //~5916R~
//                  int Popt,unsigned Pattrmask,UCHAR Psattr)      //~v379R~
//                  int Popt,unsigned Pattrmask,ULONG Psattr)      //~v5e1R~
                    int Popt,unsigned Pattrmask,ULONG Psattr,      //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
//              time_t Pmodtime)                                   //~v6k5R~
                time_t Pmodtime,char *Pslink)                      //~v6k5I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                FILETIME Pmodtime,char *Pslink)                    //~v5e1R~//~v6k5R~
    #else                                                          //~v5e1R~
                FDATE Pfdate,FTIME Pftime)                         //~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
{                                                               //~5909I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v327I~
//  FILE *fhs,*fht;                                                //~v022R~
    FILEFINDBUF3 fstat3t;                                          //~v291R~
    int texistsw,tpathlen,spathlen,filectr;                     //~5916R~
    WCPARMCOPY wccopy;                                          //~5916I~
#ifdef W32                                                         //~v6k4I~
    int rc;                                                        //~v6k4I~
#endif                                                             //~v6k4I~
#ifdef UNX                                                         //~v6k5I~
    int rc;                                                        //~v6k5I~
#endif                                                             //~v6k5I~
#else                                                           //~5909I~
    FILEFINDBUF3 fstat3t;                                       //~v052I~
    FILE *fh;                                                   //~5909I~
    int rc;                                                     //~5910R~
#endif                                                             //~v022M~
#ifndef OS2                                                        //~v5e1I~
	int repsw;                                                     //~v5e1I~
#endif                                                             //~v5e1I~
    int flags;                                                     //~v291I~
    char sdir[_MAX_PATH],tdir[_MAX_PATH];                          //~v6kkI~
//********************                                          //~5909I~
    *tdir=0;                                                       //~v6kkI~
    if (!strcmp(Psource,Ptarget))                                  //~v291R~
    {                                                              //~v291I~
        uerrmsg("Target is same as Source(%s)",                    //~v291I~
                "宛先ファイルが元ファイルと同じです(%s)",          //~v291I~
                    Psource);                                      //~v291I~
        return -1;                                                 //~v291I~
    }                                                              //~v291I~
    flags=ufilecpymvflags(0,0,Ptarget,&fstat3t);   //not wild,root //~v291M~
    if (flags==CPYMV_TPATHERR)                                     //~v5cdI~
    	return -1;                                                 //~v5cdI~
//#ifdef W32                                                       //~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
    if (Psattr & FILE_SLINK)	//slink/junction/mountpoint        //~v6k4R~
    {                                                              //~v6k4M~
//    	rc=ucopysub_slink(Popt,Psource,Ptarget,Psattr,Pmodtime,flags,&fstat3t);//~v6k5R~
      	rc=ucopysub_slink(Popt,Psource,Ptarget,Psattr,             //~v6k5I~
                            Pattrmask,                             //~v6k5I~
      						Pmodtime,                              //~v6k5I~
//#ifdef UNX                                                       //~v6k5R~
      						Pslink,                                //~v6k5I~
//#endif                                                           //~v6k5R~
      						flags,&fstat3t);                       //~v6k5I~
      if (rc!=-FILE_DIRECTORY)	//target is not directory(target is file or target err)//~v6kbI~
        return rc;                                                 //~v6k4M~
    }                                                              //~v6k4M~
#endif                                                             //~v6k4M~
    if (!(Popt & DCPY_APPEND))            //not append req         //~v291I~
        if (UCBITCHK(Psattr,FILE_DIRECTORY)) //source dir          //~v291I~
            if (flags & CPYMV_TFILE)    //target is file           //~v291I~
                return ufileerrdirandfile(Psource,Ptarget);        //~v291I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v327I~
//  texistsw=!ufstat(Ptarget,&fstat3t); //target existsw           //~v291R~
    texistsw=!(flags & CPYMV_TNEW); //target existsw               //~v291I~
    if (UCBITCHK(Psattr,FILE_DIRECTORY)) //source dir           //~5923R~
    {                                                           //~5910I~
//        if (texistsw)                                            //~v291R~
//        {                                                        //~v291R~
//            if (!UCBITCHK(fstat3t.attrFile,FILE_DIRECTORY))      //~v291R~
//            {                                                    //~v291R~
//                uerrmsg("%s is directory and %s is file",        //~v291R~
//                        "%s は ディレクトリー,%s はファイル",    //~v291R~
//                        Psource,Ptarget);                        //~v291R~
//                return -1;                                       //~v291R~
//            }                                                    //~v291R~
//        }                                                        //~v291R~
//        else            //target not exist                       //~v291R~
        if (!texistsw && !(Popt & DCPY_APPEND))            //not append req//~v291I~
        {                                                       //~5916I~
            if (umkdir(Ptarget))                                //~5916I~
                return -1;                                      //~5916R~
//          if (ucopypathinfo(Psource,Ptarget))//not avail for dir //~v6kjR~
//              return -1;                                         //~v6kjR~
//          ucopypathinfo(Psource,Ptarget); //ignore err           //~v6kkR~
            strcpy(sdir,Psource);                                  //~v6kkI~
            strcpy(tdir,Ptarget);                                  //~v6kkI~
            flags=CPYMV_TDIR;                                      //~v291I~
        }                                                       //~5916I~
//UTRACEP("ucopysub :%s to %s,sattr=%d\n",Psource,Ptarget,Psattr);   //~v014I~
        tpathlen=(int)strlen(Ptarget);                          //~5916R~
        spathlen=(int)strlen(Psource);                          //~5916R~
      if (!(Popt & DCPY_APPEND))            //not append req       //~v5awI~
        *(Ptarget+tpathlen++)=DIR_SEPC;                            //~v327R~
		if (spathlen+(int)sizeof(DIR_SEPS DIR_ALLMEMB)>_MAX_PATH)  //~v6H1I~
			return ufileTooLongFullpathName2(-1,Psource,"");       //~v6H1I~
        strcpy(Psource+spathlen,DIR_SEPS DIR_ALLMEMB);             //~v327R~
        wccopy.wctfullpath  =Ptarget;                           //~5916R~
        wccopy.wcopt        =Popt;                              //~5916I~
        wccopy.wcattrmask   =Pattrmask;                         //~5916I~
        wccopy.wctpathlen   =tpathlen;                          //~5916I~
        wccopy.wcflag       =flags;                                //~v291R~
        wccopy.wcskipctr    =0;     //copy bypass ctr              //~v5e1I~
        filectr=0;  //for compile warning                       //~5916I~
//      return uwildfunc(0,         //bypass ea data               //~v6kkR~
        rc=uwildfunc(0,         //bypass ea data                   //~v6kkI~
                    Psource,Pattrmask,ufilewildcopy,&wccopy,&filectr);//~5916I~
        if (*tdir)                                                 //~v6kkI~
			ucopypathinfo(sdir,tdir); //ignore err                 //~v6kkR~
        return rc;                                                 //~v6kkI~
    }                                                           //~5910I~
    else                    //source is file                    //~5916I~
    {                                                           //~5916I~
        if (texistsw)                                           //~5916I~
        {                                                       //~5916I~
//          if (UCBITCHK(fstat3t.attrFile,FILE_DIRECTORY))         //~v291R~
            if (flags & CPYMV_TDIR)    //target is dir             //~v291I~
            {                                                   //~5916I~
                uerrmsg("%s is file and %s is directory",       //~5917I~
                        "%s は ファイル, %s はディレクトリー",  //~5917I~
                        Psource,Ptarget);                       //~5917I~
                return -1;                                      //~5917I~
            }                                                   //~5916I~
            if (UCBITCHK(fstat3t.attrFile,FILE_READONLY))       //~5923M~
                return ufilereadonly(Ptarget,EACCES);           //~5923M~
                                                                //~5923I~
            if (Popt & DCPY_APPEND)            //append req     //~5917R~
                return udoscopy(Psource,Ptarget,1); //append    //~5916I~
            else                                                //~5916I~
                if (Popt & DCPY_EXISTING)       //repl req      //~5917R~
                {                                               //~5923I~
                	if (Popt & DCPY_REPOLD)       //repl old member only//~v5e1R~
                    {                                              //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                		repsw=ufilecopytschk(Popt,Psource,Pmodtime,fstat3t.mtime);//~v5e1R~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                		repsw=ufilecopytschk(Popt,Psource,Pmodtime,fstat3t.ftLastWriteTime);//~v5e1R~
    #else                                                          //~v5e1R~
                		repsw=ufilecopytschk(Popt,Psource,Pfdate,Pftime,fstat3t.fdateLastWrite,fstat3t.ftimeLastWrite);//~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
						if (repsw<=0)	//source<=target           //~v5e1R~
    	                    return DCPY_RC_NOTCOPY;                //~v5e1I~
                    }                                              //~v5e1I~
                    if ((UCBITCHK(fstat3t.attrFile,FILE_SYSTEM)    //~v053R~
                        && !UCBITCHK(Psattr,FILE_SYSTEM))          //~v053R~
                    ||  (UCBITCHK(fstat3t.attrFile,FILE_HIDDEN)    //~v053R~
                        && !UCBITCHK(Psattr,FILE_HIDDEN)))         //~v053R~
                    {                                           //~5923I~
                        uerrmsg("Target attribute denied access",//~5923I~
                                "コピー先の属性による拒否");    //~5923I~
                        return EACCES;                          //~5923R~
                    }                                           //~5923I~
#ifdef UNX                                                         //~v523I~
                    return udoscopy(Psource,Ptarget,(Popt & DCPY_NOCOPYINFO)); //append//~v523I~
#else                                                              //~v523I~
                    return udoscopy(Psource,Ptarget,0); //repl  //~5916I~
#endif                                                             //~v523I~
                }                                               //~5923I~
                else                                            //~5916I~
                if (Popt & DCPY_SKIPEXIST)       //skip override   //~v5fgI~
    	        	return DCPY_RC_NOTCOPY;                        //~v5fgI~
                else                                               //~v5fgI~
//                  return ufileexist(Ptarget,-1);                 //~v5cdR~
                    return ufileexistcopy(Ptarget,-1);             //~v5cdI~
        }                                                       //~5916I~
        else            //target not exist                      //~5916I~
#ifdef UNX                                                         //~v523I~
            return udoscopy(Psource,Ptarget,(Popt & DCPY_NOCOPYINFO)); //append//~v523I~
#else                                                              //~v523I~
            return  udoscopy(Psource,Ptarget,0);    //repl      //~5916I~
#endif                                                             //~v523I~
    }                                                           //~5916I~
#else                                                           //~5910M~
//over DosCopy,support target root dir                          //~5910R~
    rc=(int)DosCopy(Psource,Ptarget,(ULONG)Popt);               //~5909R~
    switch(rc)                                                  //~5909I~
    {                                                           //~5909I~
    case ERROR_FILE_NOT_FOUND:                                  //~5909R~
        return ufilenotfound(Ptarget,rc);                       //~5909M~
    case ERROR_PATH_NOT_FOUND:                                  //~5909I~
        return ufilepatherr(Ptarget,rc);                        //~5909I~
    case ERROR_ACCESS_DENIED:                                   //~5909I~
        if (Popt & (DCPY_EXISTING|DCPY_APPEND))                 //~5918R~
            uerrmsg("Target attribute denied access",           //~5918M~
                    "コピー先の属性による拒否");                //~5918M~
        else                                                    //~5918I~
        {                                                       //~v052I~
            if (!ufstat(Ptarget,&fstat3t) //target exist        //~v052R~
            &&  UCBITCHK(fstat3t.attrFile,FILE_DIRECTORY)) //target dir//~v052I~
                return ufileexist2(Psource,Ptarget,rc);         //~v052R~
            else                                                //~v052I~
//              return ufileexist(Ptarget,rc);                     //~v5cdR~
                return ufileexistcopy(Ptarget,rc);                 //~v5cdI~
        }                                                       //~v052I~
        return rc;                                              //~5909I~
    case ERROR_DIRECTORY:                                       //~5909I~
        return ufilenotdir(Ptarget,rc);                         //~5910I~
    case ERROR_DISK_FULL:                                       //~5910I~
        return ufilediskfull(Ptarget,rc);                       //~5910I~
    case ERROR_SHARING_VIOLATION:                               //~5909I~
        if (!(fh=fopen(Psource,"rb")))                          //~5909R~
            return ufileshare(Psource,rc);                      //~5909R~
        fclose(fh);                                             //~5909I~
        if (!(fh=fopen(Ptarget,"wb")))                          //~5909R~
            return ufileshare(Ptarget,rc);                      //~5909R~
        fclose(fh);                                             //~5909I~
        break;                                                  //~5909I~
    case ERROR_EAS_NOT_SUPPORTED:                               //~5909I~
        uerrmsg("cannot copy EAS of %s",                        //~5909I~
                "%s のEASをコピーできません",                   //~5909I~
                Psource);                                       //~5909R~
        return rc;                                              //~5909I~
    case ERROR_NEED_EAS_FOUND:                                  //~5909I~
        uerrmsg("cannot copy need EAS of %s",                   //~5909I~
                "%s のneed EASをコピーできません",              //~5909I~
                Psource);                                       //~5909R~
        return rc;                                              //~5909I~
    }                                                           //~5909I~
    if (rc)                                                     //~5909I~
        return ufileapierr2("DosCopy",Psource,Ptarget,rc);      //~5909R~
#endif                                                          //~5916M~
#ifdef W32  //bcc32 warn,not reachable statement                   //~v022I~
#else                                                              //~v022I~
  #ifdef UNX                                                       //~v59rI~
  #else                                                            //~v59rI~
    return 0;                                                   //~5909I~
  #endif                                                           //~v59rI~
#endif                                                             //~v022I~
}//copysub                                                      //~5909R~
                                                                //~5909I~
#if defined(DOS) || defined(W32) || defined(UNX)                   //~v327I~
//****************************************************************//~5916I~
//udoscopy                                                      //~5916I~
//* copy file(also time stamp)                                  //~5916I~
//*parm1:source fullpath filename                               //~5916I~
//*parm2:target fullpath filename                               //~5916I~
//*parm3:option append(1)/repl(0)                               //~5916R~
//*retrn:rc                                                     //~5916I~
//****************************************************************//~5916I~
int udoscopy(UCHAR *Psource,UCHAR *Ptarget,int Popt)            //~5916R~
{                                                               //~5916I~
#ifdef DOSDOS                                                      //~v5b2R~
#define COPYBUFFSZ  4096                                           //~v5b2R~
#else                                                              //~v5b2R~
	#define COPYBUFFSZ  32768                                      //~v5b2R~
#endif                                                             //~v5b2R~
    int rc=0;                                                   //~5916R~
    FILE *fhs,*fht;                                             //~5916R~
    char *typet;                                                //~5916R~
    void *buff;                                                 //~5916I~
    size_t lenr,lenw,size=COPYBUFFSZ;                           //~5916R~
#ifdef UNX                                                         //~v523I~
    int nocopyinfosw;                                              //~v523I~
#endif                                                             //~v523I~
//****************************                                  //~5916I~
#ifdef UNX                                                         //~v523I~
  	if (MDOSDISKOK(Psource)||MDOSDISKOK(Ptarget))	    //contain drive id//~v559R~
        return ucopy_mdos(Psource,Ptarget,Popt);                   //~v559R~
    nocopyinfosw=Popt & DCPY_NOCOPYINFO;                           //~v523I~
    Popt &= ~DCPY_NOCOPYINFO;		//drop flag                    //~v523I~
#endif                                                             //~v523I~
UTRACEP("udoscopy :%s to %s,opt=%d\n",Psource,Ptarget,Popt);       //~v6kkR~
    if (Popt)                                                   //~5916I~
        typet="ab";     //append binary(create if new)          //~5916R~
    else                                                        //~5916I~
        typet="wb";     //write binary                          //~5916R~
#ifdef ARMXXE                                                      //~v77hI~
	if (IS_DOCPATH(Psource)||IS_DOCPATH(Ptarget))                  //~v77hI~
    {                                                              //~v77hI~
    	int opt=Popt? UFCDO_APPEND:0;                              //~v77hI~
    	rc=ufile_copyDoc(opt,Psource,Ptarget);                     //~v77hI~
		UTRACEP("%s:copyDoc returnec rc=%d\n",UTT,rc);             //~v77hI~
  		if (!nocopyinfosw)                                         //+vc5nI~
    		if (!Popt)  //repl mode(not append)                    //+vc5nI~
        		ucopypathinfo(Psource,Ptarget);                    //+vc5nI~
		UTRACEP("%s:docpath after ucopypathinfo rc=%d\n",UTT,rc);  //+vc5nI~
        return rc;                                                 //~v77hI~
    }                                                              //~v77hI~
#endif                                                             //~v77hI~
    if ((fhs=fopen(Psource,"rb")),!fhs)                            //~v022R~
    {                                                              //~v59rI~
#ifdef UNX                                                         //~v352I~
      if (errno==EACCES)                                           //~v352R~
        return ufilenopermission("copy fopen",Psource,errno);      //~v366R~
      else                                                         //~v352I~
#endif //UNX                                                       //~v352I~
        return ufileapierr("fopen",Psource,errno);              //~5916R~
    }//open err                                                    //~v59rI~
//UTRACEP("doscopy fopen source=%s,fh=%d\n",Psource,fhs);          //~v013R~
    if ((fht=fopen(Ptarget,typet)),!fht)                           //~v022R~
    {                                                              //~v59rI~
#ifdef UNX                                                         //~v352I~
      if (errno==EACCES)                                           //~v352R~
        return ufilenopermission("copy fopen",Ptarget,errno);      //~v366R~
      else                                                         //~v352I~
#endif //UNX                                                       //~v352I~
        return ufileapierr("fopen",Ptarget,errno);              //~5916I~
    }//open err                                                    //~v59rI~
//UTRACEP("doscopy fopen target=%d,fh=%d\n",Ptarget,fht);          //~v013R~
    buff=UALLOCM(COPYBUFFSZ);                                   //~5930R~
    UALLOCCHK(buff,UALLOC_FAILED);  //return if alloc err       //~5930R~
    for (;;)                                                    //~5916I~
    {                                                           //~5916I~
        lenr=fread(buff,1,size,fhs);                            //~5916R~
        lenw=fwrite(buff,1,lenr,fht);                           //~5916R~
        if (lenw<lenr)                                          //~5916I~
        {                                                       //~5916I~
            uerrmsg("copy failed, %s to %s",                    //~5916I~
                    "%s から %s へのコピー失敗",                //~5916I~
                    Psource,Ptarget);                           //~5916I~
            rc=4;                                               //~5916I~
            break;                                              //~5916I~
        }                                                       //~5916I~
        if (lenr<size)  //read shortage                         //~5916R~
            break;                                              //~5916I~
    }                                                           //~5916I~
    ufree(buff);                                                //~5916I~
    if (fclose(fhs))                                            //~5916I~
        return ufileapierr("fclose",Psource,errno);             //~5916I~
//UTRACEP("doscopy fclose source=%s,fh=%d\n",Psource,fhs);         //~v013R~
    if (fclose(fht))                                            //~5916I~
        return ufileapierr("fclose",Ptarget,errno);             //~5916I~
//UTRACEP("doscopy fclose target=%d,fh=%d\n",Ptarget,fhs);         //~v013R~
#ifdef UNX                                                         //~v523I~
  if (!nocopyinfosw)                                               //~v523I~
#endif                                                             //~v523I~
    if (!Popt)  //repl mode                                     //~5916R~
        if (ucopypathinfo(Psource,Ptarget))                     //~5916R~
            return -1;                                          //~5916I~
    return rc;                                                  //~5916R~
}//udoscopy                                                     //~5916I~
#endif                                                          //~5916I~
                                                                //~5916I~
//****************************************************************//~5B12M~
//uxmove                                                        //~5B12M~
//* rename if same drive,uxcopy and remove if drive changes   //~5B12M~//~vkdsR~
//* over command(1)inter drive support                          //~5B12M~
//*             (2)subdir move support(if wild card,target must be dir)//~5B12M~
//*****                                                         //~5B12M~
//*parm1:source filename                                        //~5B12M~
//*parm2:target filename                                        //~5B12M~
//*     at return \\ is padded at last when target is including dir//~6120I~
//*parm3:attribute mask                                         //~5B12M~
//*parm4:option: force override                                    //~v520I~
//*retrn:rc                                                     //~5B12M~
//****************************************************************//~5B12M~
//int uxmove(UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask)     //~v520R~
int uxmove(UCHAR *Psource,UCHAR *Ptarget,unsigned Pattrmask,int Popt)//~v520I~
{                                                               //~5B12M~
    UCHAR sfullpath[_MAX_PATH],tfullpath[_MAX_PATH];            //~5B12M~
    FILEFINDBUF3 fstat3s;                                       //~5B12M~
    FILEFINDBUF3 fstat3t;                                       //~5B12M~
    int tpathlen,trootsw,spathlen,filectr,rc;                   //~6120R~
    int twild;                                                     //~v280I~
    WCPARMMOVE wcmove;                                          //~5B12M~
#ifdef FTPSUPP                                                     //~v5b6I~
    PUFTPHOST puftpht,puftphs;                                     //~v5b6I~
#endif                                                             //~v5b6I~
#ifdef UNX                                                         //~v6b1I~
    int swildcard;                                                 //~v6b1R~
#endif                                                             //~v6b1I~
//********************                                          //~5B12M~
//    Sslinktargeterr=0;                                             //~v6k5I~//~v6kdI~
    UTRACEP("%s:opt=0x%x,attrMask=0x%x,source=%s,target=%s\n",UTT,Popt,Pattrmask,Psource,Ptarget);//~v77hI~
	Ssrctop=Psource;	//to chk relative line out of target       //~v6kfI~
	Gufile_opt&=~GFILEOPT_RC_WARNING;                              //~v6kdI~
#ifdef FTPSUPP                                                     //~v5b6I~
  	if ((uftpisremote(Psource,&puftphs)		//ftp filename         //~v5b6I~
  	    +uftpisremote(Ptarget,&puftpht))!=0)	//ftp filename     //~v5b6I~
    {                                                              //~v5jeI~
      if (UFTPHISTSO(puftphs)||UFTPHISTSO(puftpht))                //~v5jeI~
    	return u3270xmove(Popt,puftphs,puftpht,Psource,Ptarget,Pattrmask);//~v5jeI~
      else                                                         //~v5jeI~
    	return uftpxmove(puftphs,puftpht,Psource,Ptarget,Popt,Pattrmask);//~v5b6I~
    }                                                              //~v5jeI~
#endif                                                             //~v5b6I~
    Pattrmask=Pattrmask & FILE_ALL;     //drop invalid bit      //~5B12M~
#ifdef UNX                                                         //~v6b1I~
    tpathlen=PATHLEN(Ptarget);                                     //~v6b1R~
    if (tpathlen>0 && WILDCARD(Ptarget+tpathlen))                  //~v6b1I~
#else                                                              //~v6b1I~
    if (WILDCARD(Ptarget))                                      //~5B12M~
#endif                                                             //~v6b1I~
//      return ufilewildtarget(-1);                                //~v280R~
//      twild=1;                                                   //~v291R~
        twild=CPYMV_TWILD;                                         //~v291I~
    else                                                           //~v280I~
        twild=0;                                                   //~v280I~
                                                                //~5B12M~
    if (!ufullpath(sfullpath,Psource,_MAX_PATH))                //~5B12M~
        return -1;                                              //~5B12M~
    if (!ufullpath(tfullpath,Ptarget,_MAX_PATH))                //~5B12M~
        return -1;                                              //~5B12M~
//*avoid source root case for successfull dosfindfirst          //~5B12M~
//  trootsw=ROOTDIR(tfullpath);                                    //~v55cR~
    trootsw=ROOTDIR2(tfullpath);                                   //~v55cI~
    tpathlen=(int)strlen(tfullpath);                            //~5B12M~
    spathlen=PATHLEN(sfullpath);                                //~5B12M~
//  if (ROOTDIR(sfullpath)) //dosfindfirst faile if root           //~v55cR~
    if (ROOTDIR2(sfullpath)) //dosfindfirst faile if root          //~v55cI~
    {                                                           //~5B12M~
        uerrmsg("You cannot move root",                         //~5B12M~
                "ルートは移動できません");                      //~5B12M~
        return -1;                                              //~5B12M~
    }                                                           //~5B12M~
//*source exist chk for not found err apirc of target           //~5B12M~
#ifdef UNX                                                         //~v6b1I~
    swildcard=spathlen>0 && WILDCARD(sfullpath+spathlen);          //~v6b1I~
  if (!ufstat_wild(sfullpath,&fstat3s)) //exist                    //~v6b1R~
  {                                                                //~v6b1I~
    if (fstat3s.attrFile & FILE_WILDNAME)                          //~v6b1I~
    	swildcard=0;                                               //~v6b1I~
  }                                                                //~v6b1I~
  else                                                             //~v6b1I~
#endif                                                             //~v6b1I~
  {                                                                //~v6b1I~
    if (udosfindfirst(sfullpath,0,Pattrmask|FILE_DIRECTORY,&fstat3s))//~5B12M~
        return -1;                                              //~5B12M~
  }                                                                //~v6b1I~
//#ifdef AIX                                                       //~v55nR~
//    if (!(Popt & DCPY_NODELDIRMOVE))       //skip sorce dir itself delete for AIX mdos disk//~v55nR~
//        if (MDOSDISKOK(sfullpath))                               //~v55nR~
//            if (fstat3s.attrFile & FILE_DIRECTORY)//target dir   //~v55nR~
//            {                                                    //~v55nR~
//                uerrmsg("dir on floppy disk cannot be source of move under AIX",0);//~v55nR~
//                return ENOSYS;                                   //~v55nR~
//            }                                                    //~v55nR~
//#endif                                                           //~v55nR~
//cur dir cannot move                                           //~5B12M~
    if (ufilecdirchk(sfullpath))                                //~5B12M~
        return ufiledelpath(sfullpath,-1);                      //~5B12M~
                                                                //~5B12M~
    if (trootsw)    //target is root                            //~5B12M~
    {                                                           //~5B12M~
        memset(&fstat3t,0,sizeof(fstat3t));                     //~5B12M~
        fstat3t.attrFile=FILE_DIRECTORY;//target dir            //~5B12M~
    }                                                           //~5B12M~
    else            //target is not root                        //~5B12M~
    {                                                           //~5B12M~
      if (twild)                                                   //~v280I~
      {                                                            //~v280I~
            tpathlen=PATHLEN(tfullpath);    //len of dir path      //~v280I~
	        memset(&fstat3t,0,sizeof(fstat3t));                    //~v5jfI~
            fstat3t.attrFile=FILE_DIRECTORY;//for errchk           //~v280I~
      }                                                            //~v280I~
      else                                                         //~v280I~
        if (ufstat(tfullpath,&fstat3t)) //not found             //~5B12M~
//          fstat3t.attrFile=(ULONG)-1;     //not exist id         //~v053R~
//          fstat3t.attrFile=0xff;          //not exist id         //~v053I~//~v6k4R~
            fstat3t.attrFile=ATTR_NOTFOUND; //not exist id         //~v6k4I~
    }                                                           //~5B12M~
                                                                //~5B12M~
#ifdef UNX                                                         //~v6b1I~
    if (swildcard)         //source wild card                      //~v6b1I~
#else                                                              //~v6b1I~
    if (WILDCARD(sfullpath))         //source wild card         //~5B12M~
#endif                                                             //~v6b1I~
    {                                                           //~5B12M~
//      if (fstat3t.attrFile==((ULONG)-1)       //not exist id     //~v053R~
//      if (fstat3t.attrFile==0xff              //not exist id     //~v053R~//~v6k4R~
        if (fstat3t.attrFile==ATTR_NOTFOUND     //not exist id     //~v6k4I~
        ||  !UCBITCHK(fstat3t.attrFile,FILE_DIRECTORY))//target dir//~5B12M~
            return ufilenotdir(tfullpath,-1);                   //~5B12M~
        if (twild)                                                 //~v280I~
//          fstat3t.attrFile=0xff;  //not exist id,skip fname edit at movesub//~v280I~//~v6k4R~
            fstat3t.attrFile=ATTR_NOTFOUND;  //not exist id,skip fname edit at movesub//~v6k4I~
        wcmove.wctfullpath  =tfullpath;                         //~5B12M~
        wcmove.wcopt        =Popt;                                 //~v520I~
        wcmove.wcopt       |=DCPY_WILDCOPYMOVE;                    //~v6k4R~
//      wcmove.wctattr      =fstat3t.attrFile;                  //~5B12M~//~v6BxR~
        wcmove.wctattr      =(UINT)fstat3t.attrFile;               //~v6BxI~
        wcmove.wcspathlen   =spathlen;                          //~5B12M~
        wcmove.wctpathlen   =tpathlen;                          //~5B12M~
//      wcmove.wctwild      =twild;                                //~v291R~
        wcmove.wcflag       =twild;                                //~v291I~
        wcmove.wcskipctr    =0;                                    //~v5e1I~
        rc=uwildfunc(0,         //bypass ea data                //~6120R~
                    sfullpath,Pattrmask,ufilewildmove,&wcmove,&filectr);//~6120R~
//        if (!rc && Sslinktargeterr)                                //~v6k5R~//~v6kdR~
//            rc=DCPY_RC_WARNING;// -2                               //~v6k5R~//~v6kdR~
    	return rc;                                                 //~v6k5I~
    }                                                           //~5B12M~
    else                                                        //~6120I~
    {                                                              //~v280I~
        if (twild)      //target is wild card                      //~v280I~
        {                                                          //~v280I~
//          ufileeditname(sfullpath,tfullpath,tfullpath);    //determin target//~v56xR~
            ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,     //~v56xI~
							sfullpath,tfullpath,tfullpath);    //determin target//~v56xI~
//          fstat3t.attrFile=0xff;  //not exist id,skip fname edit at movesub//~v280I~//~v6k4R~
            fstat3t.attrFile=ATTR_NOTFOUND;  //not exist id,skip fname edit at movesub//~v6k4I~
        }                                                          //~v280I~
                                                                   //~v280I~
        rc=umovesub(sfullpath,tfullpath,                        //~6120R~
                    Popt,                                          //~v520I~
                    spathlen,tpathlen,                          //~5B12M~
//                  (UCHAR)fstat3s.attrFile,(UCHAR)fstat3t.attrFile);//~v5e1R~
//                  (UCHAR)fstat3s.attrFile,(UCHAR)fstat3t.attrFile,//~v5e1I~//~v6k4R~
//                  fstat3s.attrFile,fstat3t.attrFile,             //~v6k4I~//~v6BxR~
                    (UINT)fstat3s.attrFile,(UINT)fstat3t.attrFile, //~v6BxI~
                    fstat3s.slink,                                 //~v6k5I~
                    &fstat3t,                                      //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                	fstat3s.mtime);                                //~v5e1R~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                	fstat3s.ftLastAccessTime);                     //~v5e1R~
    #else                                                          //~v5e1R~
                	fstat3s.fdateLastWrite,fstat3s.ftimeLastWrite);//~v5e1I~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
//  	if (rc==DCPY_RC_NOTCOPY)    //copy bypass by timestamp option//~v5e1R~
//      	rc=0;                                                  //~v5e1R~
    }                                                              //~v280I~
                                                                //~6120I~
    if (!trootsw                                                //~6120I~
//  && fstat3t.attrFile!=(ULONG)-1                                 //~v053R~
//  && fstat3t.attrFile!=0xff                                      //~v053I~//~v6k4R~
    && fstat3t.attrFile!=ATTR_NOTFOUND                             //~v6k4I~
    && UCBITCHK(fstat3t.attrFile,FILE_DIRECTORY))               //~6120I~
    {                                                              //~v6H1I~
    	UMAXPATHCHK(Ptarget,_MAX_PATH-1,-1/*rc*/,1/*msgsw*/);      //~v6H1R~
        strcat(Ptarget,DIR_SEPS);   //sign of dir                  //~v327R~
    }                                                              //~v6H1I~
//    if (!rc && Sslinktargeterr)                                    //~v6k5R~//~v6kdR~
//        rc=DCPY_RC_WARNING;// -2                                   //~v6k5R~//~v6kdR~
    UTRACEP("%s:rc=%d,source=%s,target=%s\n",UTT,rc,Psource,Ptarget);//~v77YI~
    return rc;                                                  //~6120I~
}//uxmove                                                       //~5B12M~
                                                                //~5B12M~
//****************************************************************//~5B12M~
//!uwildmove                                                    //~5B12M~
//* copy by wild card                                           //~5B12M~
//*parm1:filename thru wildfunc                                 //~5B12M~
//*parm2:dirlist ptr thru wildfunc                              //~5B12M~
//*parm3:parm thru uwildfunc(ucopy parameter structure)         //~5B12M~
//*retrn:rc                                                     //~5B12M~
//****************************************************************//~5B12M~
int ufilewildmove(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~5B12M~
{                                                               //~5B12M~
    WCPARMMOVE *pwcmove;                                        //~5B12M~
    UCHAR      *ptarget,wktarget[_MAX_PATH];                       //~v280I~
    int rc;                                                        //~v5e1I~
//********************                                          //~5B12M~
    pwcmove=Pparm;                                              //~5B12M~
//  if (pwcmove->wctwild)       //target is wild card              //~v291R~
    if (pwcmove->wcflag & CPYMV_TWILD)      //target is wild card  //~v291I~
    {                                                              //~v280I~
//      ufileeditname(Pfullpath,pwcmove->wctfullpath,wktarget);    //~v56xR~
        ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,         //~v56xI~
						Pfullpath,pwcmove->wctfullpath,wktarget);  //~v56xI~
        ptarget=wktarget;                                          //~v280I~
    }                                                              //~v280I~
    else                                                           //~v280I~
        ptarget=pwcmove->wctfullpath;                              //~v280R~
//  return umovesub(Pfullpath,                                     //~v5e1R~
    rc=umovesub(Pfullpath,                                         //~v5e1I~
//                    pwcmove->wctfullpath,                        //~v280R~
                    ptarget,                                       //~v280I~
                    pwcmove->wcopt,                                //~v520R~
                    pwcmove->wcspathlen,                        //~5B12M~
                    pwcmove->wctpathlen,                        //~5B12M~
//                  (UCHAR)Ppudirlist->attr,    //source attr   //~5B12M~//~v6k4R~
//                  Ppudirlist->attr,    //source attr             //~v6k4I~//~v6BxR~
                    (UINT)Ppudirlist->attr,    //source attr       //~v6BxI~
//                  (UCHAR)pwcmove->wctattr);                      //~v5e1R~
//                  (UCHAR)pwcmove->wctattr,                       //~v5e1I~//~v6k4R~
                    pwcmove->wctattr,                              //~v6k4I~
//                  Ppudirlist->slink,                             //~v6k5R~//~v6qaR~
                    UDIRLIST_GET_SLINKNAME_OR_NULLSTR(Ppudirlist), //~v6qaI~
                    0,                  //no target fstat3         //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                	Ppudirlist->mtime);                            //~v5e1I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                	Ppudirlist->ftLastAccessTime);                 //~v5e1R~
    #else                                                          //~v5e1R~
                	Ppudirlist->date,Ppudirlist->time);            //~v5e1I~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
    if (rc==DCPY_RC_NOTCOPY)    //copy bypass by timestamp option  //~v5e1I~
    {                                                              //~v5e1I~
        pwcmove->wcskipctr++;                                      //~v5e1I~
        rc=0;                                                      //~v5e1I~
    }                                                              //~v5e1I~
	return rc;                                                     //~v5e1I~
}//ufilewildmove                                                   //~v5e1R~
//#ifdef W32                                                      //~5B12M~//~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
//**************************************************************** //~v6k4I~
//move windows junction/slink/mountpoint                           //~v6k4I~
//**************************************************************** //~v6k4I~
int umovesub_slink(UCHAR *Psource,UCHAR *Ptarget,                  //~v6k4I~
            int Popt,int Pspathlen,int Ptpathlen,                  //~v6k4I~
            UINT  Psattr,UINT  Ptattr,UCHAR *Psrcslink,            //~v6k5R~
            FILEFINDBUF3 *Pptffb3,                                 //~v6k5I~
#ifdef UNX                                                         //~v6k5I~
                time_t Pmodtime)                                   //~v6k5I~
#else                                                              //~v6k5I~
                FILETIME Pmodtime)                                 //~v6k4I~
#endif                                                             //~v6k5I~
{                                                                  //~v6k4I~
    FILEFINDBUF3 fstat3t;                                          //~v6k4I~
    int rc;                                                        //~v6k4I~
	UINT  tattr;                                                   //~v6k4R~
    int fctr,delctr,ronlyctr;                                      //~v6k4I~
    int overridesw=0;                                              //~v6k4I~
    int copyopt;                                                   //~v6k4I~
    int repsw;                                                     //~v6k4I~
    int rc2;                                                       //~v6kfI~
//********************                                             //~v6k4I~
    UTRACEP("umovesub_slink opt=%x,src=%s,dest=%s,sattr=%x,tattr=%x\n",Popt,Psource,Ptarget,Psattr,Ptattr);//~v6k4I~
    if (Popt & DCPY_SKIPSLINK)                                     //~v6k4I~
#ifdef W32                                                         //~v6k5I~
        if (FILE_MODEISNTFS_SLINK(Psattr))                         //~v6k4I~
#else                                                              //~v6k5I~
        if (FILE_ISSLINK(Psattr))                                  //~v6k5I~
#endif                                                             //~v6k5I~
    		if (Popt & DCPY_WILDCOPYMOVE)                          //~v6k4I~
	            return 0;                                          //~v6k4R~
  	if (IS_SLINKERR(Psattr))                                       //~v6kbI~
//        Sslinktargeterr=1;  //left errmsg even when rc=0           //~v6kbI~//~v6kdR~
		Gufile_opt|=GFILEOPT_RC_WARNING;                           //~v6kdI~
    if (Pptffb3)    //target fstat3(for fiel only)                 //~v6k4I~
        memcpy(&fstat3t,Pptffb3,sizeof(fstat3t));                  //~v6k4I~
    else                                                           //~v6k4I~
        memset(&fstat3t,0,sizeof(fstat3t));                        //~v6k4I~
	tattr=Ptattr;                                                  //~v6k4I~
    if (Ptattr!=ATTR_NOTFOUND    //target found                    //~v6k4R~
    && UCBITCHK(Ptattr,FILE_DIRECTORY)) //target dir               //~v6k4I~
    {                                                              //~v6k4I~
        if (!ROOTDIR2(Ptarget))   //not root                       //~v6k4I~
            *(Ptarget+Ptpathlen++)=DIR_SEPC;                       //~v6k4I~
		if (Ptpathlen+(int)strlen(Psource+Pspathlen)>_MAX_PATH)    //~v6H1I~
        {                                                          //~v6H1I~
            *(Ptarget+Ptpathlen)=0;                                //~v6H1I~
			return ufileTooLongFullpathName2(UWFRC_LONGNAME,Ptarget,Psource+Pspathlen);//~v6H1R~
        }                                                          //~v6H1I~
        strcpy(Ptarget+Ptpathlen,Psource+Pspathlen);               //~v6k4I~
		if (ufstat(Ptarget,&fstat3t)) //not found                  //~v6k4I~
			tattr=ATTR_NOTFOUND;			//not found id;        //~v6k4R~
        else                                                       //~v6k4I~
        {                                                          //~v6k4I~
//        	tattr=fstat3t.attrFile;                                //~v6k4R~//~v6BxR~
          	tattr=(UINT)fstat3t.attrFile;                          //~v6BxI~
//          if (UCBITCHK(tattr,FILE_DIRECTORY)) //same name target is dir//~v6k4I~
//              return ufileexistdir(Ptarget,8);                   //~v6k4I~
        	overridesw=DCPY_EXISTING;	//same name                //~v6k4I~
        }                                                          //~v6k4I~
    }                                                              //~v6k4I~
    if (tattr!=ATTR_NOTFOUND  //found                              //~v6k4R~
//  && !UCBITCHK(tattr,FILE_DIRECTORY)) //target dir               //~v6k4I~
    )                                                              //~v6k4I~
    {                                                              //~v6k4I~
        if (!ULBITCHK(tattr,FILE_SLINK)) //same name target is dir //~v6k4R~
			return ufileerrslinktarget(Psource,Ptarget,8);         //~v6k4I~
		if (FILE_ISNOSLINKDIR(Psattr)) //dir but not slink         //~v6k4I~
			return ufileerrdirandfile(Psource,Ptarget);            //~v6k4I~
    	if (!(Popt & DCPY_EXISTING))	//not force override       //~v6k4I~
            return ufileexistcopy(Ptarget,8);                      //~v6k4I~
    	if (Popt & DCPY_REPOLD)	//not force override               //~v6k4I~
        {                                                          //~v6k4I~
#ifdef W32                                                         //~v6k5I~
            repsw=ufilecopytschk(Popt,Psource,Pmodtime,fstat3t.ftLastWriteTime);//~v6k4I~
#else                                                              //~v6k5I~
        	repsw=ufilecopytschk(Popt,Psource,Pmodtime,fstat3t.mtime);//~v6k5I~
#endif                                                             //~v6k5I~
			if (repsw<=0)	//source<=target                       //~v6k4I~
				return DCPY_RC_NOTCOPY;                            //~v6k4I~
        }                                                          //~v6k4I~
        else                                                       //~v6k4I~
        if (Popt & DCPY_SKIPEXIST)       //skip override           //~v6k4I~
    		return DCPY_RC_NOTCOPY;                                //~v6k4I~
        overridesw=DCPY_EXISTING;                                  //~v6k4I~
    }                                                              //~v6k4I~
#ifdef W32                                                         //~v6k5I~
    if (!overridesw                                                //~v6k4I~
    &&  toupper(*Ptarget)==toupper(*Psource))   //not same drive   //~v6k4I~
    {                                                              //~v6k5I~
        rc=urename(Psource,Ptarget,0);  //can not override existing//~v6k5R~
        if (!rc)                                                   //~v6k5I~
	    	if (Popt & DCPY_CHKSLINKTGT)//copy/move chk slink target is accessible//~v6k5I~
            {                                                      //~v6kfI~
//              ufilechkslinkpath(Psource,Psrcslink,Ptarget);      //~v6k5R~
                ufilechkslinkpath(Psource,Psrcslink,Ptarget,NULL/*slinktarget*/,NULL/*ffb3*/);//~v6k5I~
//  			rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Psrcslink);//~v6kpR~
//    			rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Psrcslink,Ptarget);//~v6kqR~
      			rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Psrcslink,Ptarget,Psattr);//~v6kqI~
    			if (rc2==4) //relativelink may be broken           //~v6kfI~
        			Gufile_opt|=GFILEOPT_RC_WARNING;               //~v6kfI~
            }                                                      //~v6kfI~
        return rc;                                                 //~v6k5I~
    }                                                              //~v6k5I~
#else                                                              //~v6k5I~
    if (!ufilefscomp(Psource,Ptarget))	//filesystem match         //~v6k5I~
    {                                                              //~v6k5I~
    	if (overridesw)                                            //~v6k5I~
	        rc=urename2(Psource,Ptarget,0);	//can override existing//~v6k5I~
        else                                                       //~v6k5I~
	        rc=urename(Psource,Ptarget,0);	//can override existing//~v6k5I~
        if (!rc)                                                   //~v6k5I~
	    	if (Popt & DCPY_CHKSLINKTGT)//copy/move chk slink target is accessible//~v6k5I~
            {                                                      //~v6kfI~
//            	ufilechkslinkpath(Psource,Psrcslink,Ptarget);      //~v6k5R~
              	ufilechkslinkpath(Psource,Psrcslink,Ptarget,NULL/*slinktarget*/,NULL/*ffb3*/);//~v6k5R~
//  			rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Psrcslink);//~v6kpR~
      			rc2=ufileslinkoutoflinkchk(Popt,Ssrctop,Psource,Psrcslink,Ptarget,Psattr);//~v6kqR~
    			if (rc2==4) //relativelink may be broken           //~v6kfI~
        			Gufile_opt|=GFILEOPT_RC_WARNING;               //~v6kfI~
            }                                                      //~v6kfI~
        return rc;                                                 //~v6k5I~
    }//fscomp                                                      //~v6k5I~
#endif                                                             //~v6k5I~
                                                                   //~v6k4I~
    copyopt=overridesw;                                            //~v6k4I~
    if (rc=uxcopy(Psource,Ptarget,copyopt,FILE_ALL),rc)   //no repl,copy all//~v6k4I~
    {                                                              //~v6k4I~
      if (!overridesw)	//not existed                              //~v6k4I~
      {                                                            //~v6k4I~
        uxdelete(Ptarget,UXDELDIR,UXDELNOMSG|UXDELFORCE|UXDELNONOTFMSG,//~v6k4I~
						&fctr,&ronlyctr,&delctr);                  //~v6k4I~
        if (!rc)                                                   //~v6k4I~
            rc=(int)Psattr; //for compiler warning                 //~v6k4I~
      }                                                            //~v6k4I~
                                                //del failed copy  //~v6k4I~
        return rc;                                                 //~v6k4I~
    }                                                              //~v6k4I~
    return uxdelete(Psource,UXDELDIR,UXDELNOMSG|UXDELFORCE,&fctr,&ronlyctr,&delctr);//~v6k4I~
}//umovesub_slink                                                  //~v6k4I~
#endif	//W32                                                      //~v6k4I~
//****************************************************************//~5B12M~
//umovesub                                                      //~5B12M~
//* move file(also time stamp)                                  //~5B12M~
//*parm1:source fullpath filename                               //~5B12M~
//*parm2:target fullpath filename                               //~5B12M~
//*parm3:option to override existing                               //~v520I~
//*parm4:source path len                                           //~v520R~
//*parm5:target path len                                           //~v520R~
//*parm6:source attr                                               //~v520R~
//*parm7:target attr                                               //~v520R~
//*retrn:rc                                                     //~5B12M~
//****************************************************************//~5B12M~
int umovesub(UCHAR *Psource,UCHAR *Ptarget,                     //~5B12M~
            int Popt,                                              //~v520I~
            int Pspathlen,int Ptpathlen,                        //~5B12M~
//          UCHAR Psattr,UCHAR Ptattr)                             //~v5e1R~
//          UCHAR Psattr,UCHAR Ptattr,                             //~v5e1I~//~v6k4R~
            UINT  Psattr,UINT  Ptattr,                             //~v6k4I~
            UCHAR *Psrcslink,                                      //~v6k5I~
            FILEFINDBUF3 *Pptffb3,                                 //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                time_t Pmodtime)                                   //~v5e1I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                FILETIME Pmodtime)                                 //~v5e1R~
    #else                                                          //~v5e1R~
                FDATE Pfdate,FTIME Pftime)                         //~v5e1I~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
{                                                               //~5B12M~
    FILEFINDBUF3 fstat3t;                                          //~v522R~
    int rc;                                                     //~5B12M~
#ifdef DOS                                                      //~v013I~
    int copysw;                                                 //~v013I~
#else                                                           //~v013I~
#endif                                                          //~v013I~
//  UCHAR tattr;                                                   //~v522I~//~v6k4R~
    UINT  tattr;                                                   //~v6k4I~
    int fctr,delctr,ronlyctr;                                   //~v010R~
    int overridesw=0;                                              //~v520I~
    int copyopt;                                                   //~v6b1I~
    int repsw;                                                     //~v5e1I~
    int swsubdiroverride=0;                                        //~v6yfI~
//********************                                          //~5B12M~
//#ifdef W32                                                       //~v6k5R~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
    if (Psattr & FILE_SLINK) //same name target is dir             //~v6k4I~
		return umovesub_slink(Psource,Ptarget,Popt,Pspathlen,Ptpathlen,Psattr,Ptattr,Psrcslink,Pptffb3,Pmodtime);//~v6k5R~
#endif	                                                           //~v6k4I~
    if (Pptffb3)    //target fstat3(for fiel only)                 //~v5e1I~
        memcpy(&fstat3t,Pptffb3,sizeof(fstat3t));                  //~v5e1R~
    else                                                           //~v5e1I~
        memset(&fstat3t,0,sizeof(fstat3t));                        //~v5e1R~
	tattr=Ptattr;                                                  //~v522I~
//  if (Ptattr!=0xff    //target found                          //~5B12M~//~v6k4R~
    if (Ptattr!=ATTR_NOTFOUND//target found                        //~v6k4I~
#ifdef AIX                                                         //~v55nI~
    && !(Popt & DCPY_NOINTODIRMOVE)     //move member if target is dir for the case aix mdos disk//~v55nI~
#endif                                                             //~v55nI~
    && UCBITCHK(Ptattr,FILE_DIRECTORY)) //target dir            //~5B12M~
    {                                                           //~5B12M~
//      if (Ptpathlen!=3)   //not root                             //~v5d3R~
        if (!ROOTDIR2(Ptarget))   //not root                       //~v5d3I~
            *(Ptarget+Ptpathlen++)=DIR_SEPC;                       //~v327R~
        if (Ptpathlen+(int)strlen(Psource+Pspathlen)>=_MAX_PATH)   //~v6H1I~
        {                                                          //~v6H1I~
            *(Ptarget+Ptpathlen)=0;                                //~v6H1I~
			return ufileTooLongFullpathName2(UWFRC_LONGNAME,Ptarget,Psource+Pspathlen);//~v6H1I~
        }                                                          //~v6H1I~
        strcpy(Ptarget+Ptpathlen,Psource+Pspathlen);            //~5B12M~
        if (WILDCARD(Psource+Pspathlen))                           //~v6b1I~
        	return invalidtargetfilename(0,Ptarget);               //~v6b1I~
		if (ufstat(Ptarget,&fstat3t)) //not found                  //~v522R~
//  		tattr=0xff;			//not found id;                    //~v522I~//~v6k4R~
    		tattr=ATTR_NOTFOUND;			//not found id;        //~v6k4I~
        else                                                       //~v522I~
        {                                                          //~v5d3I~
//      	tattr=(UCHAR)fstat3t.attrFile;                         //~v5cfR~
//      	return ufileexist(Ptarget,8);                          //~v5d3R~
//      	tattr=(UCHAR)fstat3t.attrFile;                         //~v5d3R~//~v6k4R~
//      	tattr=fstat3t.attrFile;                                //~v6k4I~//~v6BxR~
        	tattr=(UINT)fstat3t.attrFile;                          //~v6BxI~
            if (UCBITCHK(tattr,FILE_DIRECTORY)) //same name target is dir//~v5d3I~
            {                                                      //~v6yfI~
        	  if (Popt & DCPY_EXISTING)       //repl req           //~v6yfI~
              {                                                    //~v6yfI~
              	swsubdiroverride=1;                                //~v6yfI~
                overridesw=1;                                      //~v6yfI~
              }                                                    //~v6yfI~
              else                                                 //~v6yfI~
                return ufileexistdir(Ptarget,8);                   //~v5d3R~
            }                                                      //~v6yfI~
        }                                                          //~v5d3I~
    }                                                           //~5B12M~
//  if (tattr!=0xff) //found                                       //~v55nR~
//  if (tattr!=0xff  //found                                       //~v55nI~//~v6k4R~
    if (tattr!=ATTR_NOTFOUND  //found                              //~v6k4I~
    && !UCBITCHK(tattr,FILE_DIRECTORY)) //target dir               //~v55nI~
    {                                                              //~v520I~
#ifdef UTF8SUPPH                                                   //~v62cI~
		if (FILE_ISNOSLINKDIR(Psattr)) //dir but not slink         //~v62cI~
#else                                                              //~v62cI~
		if (UCBITCHK(Psattr,FILE_DIRECTORY)) //target dir          //~v522M~
#endif                                                             //~v62cI~
			return ufileerrdirandfile(Psource,Ptarget);            //~v522M~
    	if (!(Popt & DCPY_EXISTING))	//not force override       //~v520R~
//          return ufileexist(Ptarget,8);                          //~v5cdR~
            return ufileexistcopy(Ptarget,8);                      //~v5cdI~
    	if (Popt & DCPY_REPOLD)	//not force override               //~v5e1R~
        {                                                          //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
        	repsw=ufilecopytschk(Popt,Psource,Pmodtime,fstat3t.mtime);//~v5e1R~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
            repsw=ufilecopytschk(Popt,Psource,Pmodtime,fstat3t.ftLastWriteTime);//~v5e1R~
    #else                                                          //~v5e1R~
            repsw=ufilecopytschk(Popt,Psource,Pfdate,Pftime,fstat3t.fdateLastWrite,fstat3t.ftimeLastWrite);//~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
			if (repsw<=0)	//source<=target                       //~v5e1I~
				return DCPY_RC_NOTCOPY;                            //~v5e1I~
        }                                                          //~v5e1I~
        else                                                       //~v5fgI~
        if (Popt & DCPY_SKIPEXIST)       //skip override           //~v5fgI~
    		return DCPY_RC_NOTCOPY;                                //~v5fgI~
        overridesw=DCPY_EXISTING;                                  //~v520R~
    }                                                              //~v520I~
#ifdef UNX                                                         //~v327I~
//  return urename(Psource,Ptarget,0);                             //~v364R~
  if (!swsubdiroverride)//urename2 suuport only file override      //~v6yfR~
#ifdef ARM                                                         //~v77YI~
    if (ufileIsSameDir(Psource,Ptarget))//filesystem match         //~v77YR~
#else                                                              //~v77YI~
    if (!ufilefscomp(Psource,Ptarget))	//filesystem match         //~v364I~
#endif                                                             //~v77YI~
    {                                                              //~v59rI~
    	if (overridesw)                                            //~v520I~
	        return urename2(Psource,Ptarget,0);	//can override existing//~v520I~
        else                                                       //~v520I~
	        return urename(Psource,Ptarget,0);	//can override existing//~v520I~
    }//fscomp                                                      //~v59rI~
#else  //!UNX !!!!!!!!!!!                                          //~v327I~
#ifdef DOS                                                      //~v013I~
//  UTRACEP("umovesub:spath=%d,tpath=%d,sf=%s,tf=%s\n",            //~v013R~
//          Pspathlen,Ptpathlen,Psource,Ptarget);                  //~v013R~
    if (UCBITCHK(Psattr,FILE_DIRECTORY)) //source dir           //~v013I~
        if (Pspathlen!=Ptpathlen                                //~v013I~
        ||  memicmp(Ptarget,Psource,(UINT)Pspathlen))           //~v013R~
            copysw=1;   //cannot rename                         //~v013I~
        else                                                    //~v013I~
            copysw=0;   //rename                                //~v013I~
    else                                                        //~v013I~
       if (toupper(*Ptarget)==toupper(*Psource))   //same drive //~v013I~
            copysw=0;   //rename                                //~v013I~
        else                                                    //~v013I~
            copysw=1;   //cannot rename                         //~v013I~
//  if (!copysw)    //can use rename                               //~v520R~
    if (!copysw && !overridesw)    //can use rename                //~v520I~
		return urename(Psource,Ptarget,0);                         //~v520I~
#else                                                           //~v013I~
  #ifdef W32      //MoveFileEx support move to different volume    //~v521I~
//    if (overridesw                                               //~v522R~
//    ||  toupper(*Ptarget)!=toupper(*Psource))   //not same drive //~v522R~
//        return urename2(Psource,Ptarget,0); //can override existing//~v522R~
//    else                                                         //~v522R~
    if (!overridesw                                                //~v522I~
    &&  toupper(*Ptarget)==toupper(*Psource))   //not same drive   //~v522I~
        return urename(Psource,Ptarget,0);  //can not override existing//~v520I~
  #else                                        //OS2               //~v520R~
    if (toupper(*Ptarget)==toupper(*Psource))   //same drive    //~5B12M~
	    if (!overridesw)    //can use rename                       //~v520I~
			return urename(Psource,Ptarget,0);                     //~v520I~
  #endif                                                           //~v521I~
#endif                                                          //~v013I~
#endif //!UNX !!!!!!!!!!!                                          //~v364M~
//      return urename(Psource,Ptarget,0);                         //~v520R~
                                                                //~5B12M~
//  if (!ufstat(Ptarget,&fstat3t)) //found                         //~v520R~
//      return ufileexist(Ptarget,8);                              //~v520R~
                                                                //~5B26I~
//  if (rc=uxcopy(Psource,Ptarget,0,FILE_ALL),rc)   //no repl,copy all//~v522R~
//  if (rc=uxcopy(Psource,Ptarget,overridesw,FILE_ALL),rc)   //no repl,copy all//~v6b1R~
    copyopt=overridesw;                                            //~v6b1I~
#ifdef UNX                                                         //~v6b1I~
    	copyopt|=(Popt & DCPY_REPWILDNAME);	//rename wildname option//~v6b1I~
#endif                                                             //~v6b1I~
    if (rc=uxcopy(Psource,Ptarget,copyopt,FILE_ALL),rc)   //no repl,copy all//~v6b1I~
    {                                                           //~5B26I~
      if (!overridesw)	//not existed                              //~v522I~
      {                                                            //~v522I~
//      uxdelete(Ptarget,UXDELDIR,UXDELNOMSG|UXDELFORCE,&fctr,&ronlyctr,&delctr);//~v55dR~
        uxdelete(Ptarget,UXDELDIR,UXDELNOMSG|UXDELFORCE|UXDELNONOTFMSG,//~v55dR~
						&fctr,&ronlyctr,&delctr);                  //~v55dR~
        if (!rc)                                                   //~v022I~
            rc=(int)Psattr; //for compiler warning                 //~v022I~
      }                                                            //~v522I~
                                                //del failed copy//~v010I~
        return rc;                                              //~5B12M~
    }                                                           //~5B26I~
#ifdef AIX                                                         //~v55nI~
    if (Popt & DCPY_NODELDIRMOVE)       //skip sorce dir itself delete for AIX mdos disk//~v55nI~
    return uxdelete(Psource,0       ,UXDELNOMSG|UXDELFORCE,&fctr,&ronlyctr,&delctr);//~v55nI~
#endif                                                             //~v55nI~
    return uxdelete(Psource,UXDELDIR,UXDELNOMSG|UXDELFORCE,&fctr,&ronlyctr,&delctr);//~v010R~
}//umovesub                                                        //~v5e1R~
//**************************************************************** //~v5e1I~
//file timestamp compare                                           //~v5e1I~
//*retrn:1:source is new,-1:source is old,0:source=target          //~v5e1I~
//**************************************************************** //~v5e1I~
int ufilecopytschk(int Popt,char *Pfnm,                            //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
                time_t Psmodtime,time_t Ptmodtime)                 //~v5e1I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
                FILETIME Psmodtime,FILETIME Ptmodtime)             //~v5e1R~
    #else                                                          //~v5e1R~
                FDATE Psfdate,FTIME Psftime,FDATE Ptfdate,FTIME Ptftime)//~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
{                                                                  //~v5e1I~
	int compsw=0;                                                  //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
	    FILETIME lft;                                              //~v5fuI~
    #else                                                          //~v5e1I~
        ULONG dts,dtt;                                             //~v5e1R~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
    FDATE fdate;                                                   //~v5fuI~
    FTIME ftime;                                                   //~v5fuI~
    UCHAR editts[32];                                              //~v5fuI~
//****************************                                     //~v5e1I~
#ifdef UNX                                                         //~v5e1I~
	if (Psmodtime>Ptmodtime)                                       //~v5e1I~
		compsw=1;                                                  //~v5e1I~
    else                                                           //~v5e1I~
    if (Psmodtime<Ptmodtime)                                       //~v5e1I~
		compsw=-1;                                                 //~v5e1I~
#else                                                              //~v5e1I~
    #ifdef W32                                                     //~v5e1R~
        compsw=(int)(Psmodtime.dwHighDateTime-Ptmodtime.dwHighDateTime);//~v5e1I~
        if (!compsw)                                               //~v5e1I~
	        compsw=(int)(Psmodtime.dwLowDateTime-Ptmodtime.dwLowDateTime);//~v5e1I~
//          printf("compsw=%d,src=(%08x-%08x),tgt=(%08x-%08x)\n",  //~v5e1R~
//              compsw,                                            //~v5e1R~
//              Psmodtime.dwHighDateTime,                          //~v5e1R~
//              Psmodtime.dwLowDateTime,                           //~v5e1R~
//              Ptmodtime.dwHighDateTime,                          //~v5e1R~
//              Ptmodtime.dwLowDateTime);                          //~v5e1R~
    #else                                                          //~v5e1R~
    	dts=FDATETIME2ULONG(Psfdate,Psftime);                      //~v5e1R~
    	dtt=FDATETIME2ULONG(Ptfdate,Ptftime);                      //~v5e1R~
        if (dts>dtt)                                               //~v5e1I~
        	compsw=1;                                              //~v5e1I~
        else                                                       //~v5e1I~
        if (dts<dtt)                                               //~v5e1I~
        	compsw=-1;                                             //~v5e1I~
    #endif                                                         //~v5e1R~
#endif                                                             //~v5e1I~
	if (!(Popt & DCPY_NOSKIPMSG))//issue errmsg                    //~v5e1R~
    {                                                              //~v5e1I~
#ifdef UNX                                                         //~v5fuI~
		ufilegetftime(&ftime,&fdate,Ptmodtime);                    //~v5fuI~
#else                                                              //~v5fuI~
    #ifdef W32                                                     //~v5fuI~
    	FileTimeToLocalFileTime(&Ptmodtime,&lft);                  //~v5fuI~
//	    FileTimeToDosDateTime(&lft,(USHORT*)(ULONG)(&fdate),(USHORT*)(ULONG)(&ftime));//~v5fuR~//~v6hhR~
//      FileTimeToDosDateTime(&lft,(USHORT*)(ULPTR)(&fdate),(USHORT*)(ULPTR)(&ftime));//~v6hhI~//~v6hvR~
        filetime2dosdatetime(&lft,(USHORT*)(ULPTR)(&fdate),(USHORT*)(ULPTR)(&ftime),0/*Ppoddsec*/);//~v6hvR~
    #else                                                          //~v5fuI~
        fdate=Ptfdate;                                             //~v5fuI~
        ftime=Ptftime;                                             //~v5fuI~
    #endif                                                         //~v5fuI~
#endif                                                             //~v5fuI~
      	ufdateedit(fdate,"YY-MM-DD",editts);                       //~v5fuI~
        *(editts+8)=' ';                                           //~v5fuI~
        uftimeedit(ftime,"HH:MM:SS",editts+9);                     //~v5fuI~
        if (!compsw)                                               //~v5e1R~
        {                                                          //~v5e1R~
//          uerrmsg("&s copy bypassed(same timestamp).",           //~v5fuR~
//                  "%s コピー回避(同一FileTimeStamp)",            //~v5fuR~
//                  Pfnm);                                         //~v5fuR~
//          uerrmsg("&s copy bypassed(same timestamp:%s).",        //~v61iR~
            uerrmsg("%s copy bypassed(same timestamp:%s).",        //~v61iI~
                    "%s コピー回避(同一FileTimeStamp:%s)",         //~v5fuI~
                    Pfnm,editts);                                  //~v5fuI~
        }                                                          //~v5e1R~
        if (compsw<0)//source is old                               //~v5e1R~
        {                                                          //~v5e1R~
//          uerrmsg("&s copy bypassed(target is new timestamp).",  //~v5fuR~
//                  "%s コピー回避(宛先が新しいFileTimeStamp)",    //~v5fuR~
//                  Pfnm);                                         //~v5fuR~
//          uerrmsg("&s copy bypassed(target is new timestamp:%s).",//~v61iR~
            uerrmsg("%s copy bypassed(target is new timestamp:%s).",//~v61iI~
                    "%s コピー回避(宛先が新しいFileTimeStamp:%s)", //~v5fuI~
                    Pfnm,editts);                                  //~v5fuI~
        }                                                          //~v5e1R~
    }                                                              //~v5e1I~
    return compsw;                                                 //~v5e1I~
}//ufilecopytschk                                                  //~v5e1I~
#ifdef W32                                                         //~v6hvI~
                                                                   //~v6hvI~
//**************************************************************** //~v6hvI~
//round down odd seclike as command prompt(os roundup)             //~v6hvI~
//**************************************************************** //~v6hvI~
int filetime2dosdatetime(FILETIME *Ppft,USHORT *Ppfdt,USHORT *Ppftm,int *Ppoddsec)//~v6hvR~
{                                                                  //~v6hvI~
	int oddsec,rc;                                                 //~v6hvR~
    LONG bysec[2];                                                 //~v6hvI~
    FILETIME *pft,ft;                                              //~v6hvI~
//**************                                                   //~v6hvI~
	pft=Ppft;                                                      //~v6hvI~
	oddsec=ftime2sec(pft,bysec);                                   //~v6hvI~
    if (oddsec)                                                    //~v6hvI~
    {                                                              //~v6hvI~
    	DWORD_SUB(bysec[0],bysec[1],0,1);	//-1sec                //~v6hvI~
		ucalc_dwmult(bysec,FILETIME1SEC);                          //~v6hvI~
    	ft.dwHighDateTime=bysec[0];                                //~v6hvI~
    	ft.dwLowDateTime=bysec[1];                                 //~v6hvR~
        pft=&ft;                                                   //~v6hvI~
    }                                                              //~v6hvI~
    if (Ppoddsec)                                                  //~v6hvI~
    	*Ppoddsec=oddsec;                                          //~v6hvI~
	rc=FileTimeToDosDateTime(pft,Ppfdt,Ppftm);                     //~v6hvR~
    return rc;                                                     //~v6hvR~
}//filetime2dosdatetime                                            //~v6hvI~
#endif                                                             //~v6hvI~
#if defined(W32)||defined(UNX)                                     //~v6k5I~
//**************************************************************** //~v6k5M~
//*chk  slink target existance                                     //~v6k5I~
//*rc:ufstat rc                                                    //~v6k5I~
//**************************************************************** //~v6k5I~
//int ufilechkslinkpath(char *Psrc,char *Pslink,char *Pdest)       //~v6k5R~
int ufilechkslinkpath(char *Psrc,char *Pslink,char *Pdest,char *Pslinktarget,FILEFINDBUF3 *Ppffb3)//~v6k5I~
{                                                                  //~v6k5M~
	int len,rc;                                                    //~v6k5M~
//  char fpath[_MAX_PATH],*pfpath;                                 //~v6k5M~//~v6H1R~
    char fpath[_MAX_PATH+1],*pfpath;                               //~v6H1I~
//********************************                                 //~v6k5M~
    pfpath=Pslink;                                                 //~v6k5M~
#ifdef W32                                                         //~v6k5I~
    if (!(strlen(Pslink)>=3 && *(Pslink+1)==':' && *(Pslink+2)==DIR_SEPC)//not from drive root//~v6k5R~
    )                                                              //~v6k5I~
#else                                                              //~v6k5I~
	if (*Pslink!=DIR_SEPC) 	//fpath slink                          //~v6k5I~
#endif                                                             //~v6k5I~
    {                                                              //~v6k5M~
//    	len=PATHLEN(Pdest);                                        //~v6k5R~
      	len=PATHLEN(Psrc);                                         //~v6k5I~
        if (len>0)                                                 //~v6k5M~
        {                                                          //~v6k5M~
//  		memcpy(fpath,Pdest,len);                               //~v6k5R~
//   		memcpy(fpath,Psrc,len);                                //~v6yfR~
     		memcpy(fpath,Psrc,(size_t)len);                        //~v6yfI~
        	if (*(fpath+len-1)!=DIR_SEPC)                          //~v6k5I~
        		*(fpath+len++)=DIR_SEPC;                           //~v6k5I~
        	if (len+(int)strlen(Pslink)>=_MAX_PATH)                //~v6H1I~
	        {                                                      //~v6H1I~
    	        *(fpath+len)=0;                                    //~v6H1I~
				return ufileTooLongFullpathName2(UWFRC_LONGNAME,fpath,Pslink);//~v6H1I~
        	}                                                      //~v6H1I~
        	strcpy(fpath+len,Pslink);                              //~v6k5M~
	        pfpath=fpath;                                          //~v6k5M~
        }                                                          //~v6k5M~
    }                                                              //~v6k5M~
#ifdef W32                                                         //~v6k5I~
    if (ROOTDIR_LOCAL(pfpath)) //ufstat return 2(not found) for root dir//~v6k5R~
    {                                                              //~v6BbI~
        memset(Ppffb3,0,sizeof(FILEFINDBUF3));   //new find first  //~v6BbI~
        Ppffb3->attrFile|=FILE_DIRECTORY;                          //~v6BbI~
        rc=0;                                                      //~v6k5I~
    }                                                              //~v6BbI~
    else                                                           //~v6k5I~
#endif                                                             //~v6k5I~
//    if (rc=ufstat(pfpath,NULL/*Ppffb3*/),rc)                     //~v6k5R~
//  if (rc=ufstat(pfpath,Ppffb3),rc)                               //~v6yfR~
    if (rc=(int)ufstat(pfpath,Ppffb3),rc)                          //~v6yfI~
    {                                                              //~v6k5M~
		if (Sfinaltarget)	//no slinkcopyed msg                   //~v6k5I~
        	Sfinaltarget=2;	//msg later for dir                    //~v6k5I~
        else                                                       //~v6k5I~
	    	ufileerrnotargetslink(rc,Psrc,Pslink);                 //~v6k5R~
    }                                                              //~v6k5M~
    if (Pslinktarget)                                              //~v6k5I~
    	strcpy(Pslinktarget,pfpath);                               //~v6k5I~
    UTRACEP("ufilechkslinkpath rc=%d,tgtslinkfpath=%s\n",rc,pfpath);//~v6k5M~
    return rc;                                                     //~v6k5M~
}//ufilechkslinkpath                                               //~v6k5M~
//**************************************************************** //~v6k5I~
//*search final target file of slink chain                         //~v6k5I~
//*rc:8 target err,4:loop                                          //~v6k5R~
//**************************************************************** //~v6k5I~
int ufilegetslinkfinaltarget(char *Psrc,char *Pdest,char *Pslink,char *Pslinktarget,FILEFINDBUF3 *Ppffb3)//~v6k5R~
{                                                                  //~v6k5I~
	int rc=0,rc2,opt;                                              //~v6k5R~
    char *psrc,*pslink;                                            //~v6k5R~
    UINT attr;                                                     //~v6k5I~
    int loop=0,maxloop=10;                                         //~v6k5I~
//********************************                                 //~v6k5I~
	psrc=Psrc;                                                     //~v6k5I~
	pslink=Pslink;                                                 //~v6k5I~
	for (;;)                                                       //~v6k5I~
    {                                                              //~v6k5I~
		rc2=ufilechkslinkpath(psrc,pslink,Pdest,Pslinktarget,Ppffb3);//target exist?//~v6k5R~
//      attr=Ppffb3->attrFile;	                                   //~v6k5I~//~v6BxR~
        attr=(UINT)Ppffb3->attrFile;                               //~v6BxI~
    	UTRACEP("ufilegetslinkfinaltarget after ufileschklinkpath rc=%d,src=%s,slink=%s,slinktgt=%s,attr=%x\n",rc2,Psrc,Pslink,Pslinktarget,attr);//~v6kbI~
        if (rc2)  //ufstat rc                                      //~v6k5R~
        {                                                          //~v6k5I~
#ifdef UNX                                                         //~v6k5I~
            if (rc2==ELOOP) //40                                   //~v6k5I~
            {                                                      //~v6k5I~
                rc=4;                                              //~v6k5I~
    	    	break;                                             //~v6k5I~
            }                                                      //~v6k5I~
#endif                                                             //~v6k5I~
        	rc=8;                                                  //~v6k5I~
        	break;                                                 //~v6k5I~
        }                                                          //~v6k5I~
//        if (!FILE_ISSLINK(attr))                                   //~v6k5I~//~v6kbR~
//            break;                                                 //~v6k5I~//~v6kbR~
        opt=UFSLCO_NODUPMSG; //bypass to issue duplicated err msg  //~v6k5I~
        rc2=ufileslinkloopchk2(opt,Psrc/*startdir*/,psrc/*curdir*/,""/*curdir memb*/,Pslinktarget);//slink loop chk//~v6k5R~
    	UTRACEP("ufilegetslinkfinaltarget after ufileslinkloopchk2 rc=%d,src=%s,slink=%s,slinktgt=%s\n",rc2,Psrc,Pslink,Pslinktarget);//~v6k5R~
        if (rc2==4)  //4 loop,8:dup                                //~v6k5I~
        {                                                          //~v6k5I~
//            Sslinktargeterr=1;                                     //~v6kbI~//~v6kdR~
			Gufile_opt|=GFILEOPT_RC_WARNING;                       //~v6kdI~
        	rc=4;	//loop                                         //~v6k5I~
            break;                                                 //~v6k5I~
        }                                                          //~v6k5I~
        psrc=Pslinktarget;                                         //~v6k5I~
        pslink=Ppffb3->slink;                                      //~v6k5I~
        if (loop++>maxloop)                                        //~v6k5I~
        {                                                          //~v6k5I~
        	uerrmsg("symlink loop? %s and %s",0,                   //~v6k5I~
            		psrc,pslink);                                  //~v6k5I~
			Gufile_opt|=GFILEOPT_RC_WARNING;                       //~v6kfI~
			rc=4;                                                  //~v6k5R~
            break;                                                 //~v6k5I~
        }                                                          //~v6k5I~
        if (!FILE_ISSLINK(attr))                                   //~v6kbI~
            break;                                                 //~v6kbI~
    }                                                              //~v6k5I~
    UTRACEP("ufilegetslinkfinaltarget rc=%d,tgt=%s\n",rc,Pslinktarget);//~v6k5R~
    return rc;                                                     //~v6k5I~
}//ufilegetslinkfinaltarget                                        //~v6k5I~
#endif                                                             //~v6k5I~
#ifdef UNX                                                         //~v6k5I~
//**************************************************************** //~v6k5I~
//*slink                                                           //~v6k5I~
//return errno                                                     //~v6kbI~
//**************************************************************** //~v6k5I~
int ufilesymlink(int Popt,char *Ptargetfnm,char *Pslinkname)       //~v6k5I~
{                                                                  //~v6k5I~
	int rc;                                                        //~v6k5I~
//********************************                                 //~v6k5I~
    rc=symlink(Ptargetfnm,Pslinkname);                             //~v6k5I~
    if (rc)          //fail                                        //~v6k5R~
    {                                                              //~v6k5I~
    	rc=errno; //17:exist if slink exist, //succes even target not exist//~v6k5I~
    }                                                              //~v6k5I~
    if (rc)                                                        //~v6ksI~
		if (!(Popt & UFSLNKO_NOMSG))//               0x01     //no errmsg//~v6ksI~
    		ufileapierr("symlink",Pslinkname,rc);                  //~v6ksI~
    UTRACEP("ufilesymlink %s-->%s rc=%d\n",Ptargetfnm,Pslinkname,rc);      //~2818R~//~2819R~//~v6k5I~
    return rc;                                                     //~v6k5I~
}//ufilesymlink                                                    //~v6k5I~
//**************************************************************** //~v6ksI~
int ufilesymlink_copyfiletime(int Popt,char *Psrc,char *Pdest)     //~v6ksI~
{                                                                  //~v6ksI~
#ifndef USE_LUTIMES                                                //~v6ksI~
	UTRACEP("ufilesymlink_copyfiletime lutimes not available\n");  //~v6ksI~
	return 0;                                                      //~v6ksI~
#else                                                              //~v6ksI~
    int rc=0;                                                      //~v6ksI~
    struct timeval tv[2];    //access amd modified                 //~v6ksI~
    FILEFINDBUF3 ffb3;                                             //~v6ksI~
//****************************************                         //~v6ksI~
	UTRACEP("ufilesymlink_copyfiletime src=%s,dest=%s\n",Psrc,Pdest);//~v6ksI~
    for (;;)                                                       //~v6ksI~
    {                                                              //~v6ksI~
//      if (rc=ufstat(Psrc,&ffb3),rc)                              //~v6yfR~
        if (rc=(int)ufstat(Psrc,&ffb3),rc)                         //~v6yfI~
        	break;                                                 //~v6ksI~
		memset(tv,0,sizeof(tv));                                   //~v6ksI~
    	tv[0].tv_sec=ffb3.atime;                                   //~v6ksI~
    	tv[1].tv_sec=ffb3.mtime;                                   //~v6ksI~
    	if (lutimes(Pdest,tv))       //set                         //~v6ksI~
        {                                                          //~v6ksI~
        	rc=errno;                                              //~v6ksI~
        }                                                          //~v6ksI~
        break;                                                     //~v6ksI~
    }                                                              //~v6ksI~
	UTRACEP("ufilesymlink_copyfiletime rc=%d\n",rc);               //~v6ksI~
    return rc;                                                     //~v6ksI~
#endif //USE_LUTIME                                                //~v6ksI~
}//ufilesymlink_copyfiletime                                       //~v6ksI~
//**************************************************************** //~v6k5I~
//return errno                                                     //~v6kbI~
//**************************************************************** //~v6kbI~
int ufilesymlink_copy(int Popt,ULONG Psattr,char *Psrc,char *Ptarget,char *Psrcslink)//~v6k5R~
{                                                                  //~v6k5I~
	int rc;                                                        //~v6k5I~
    char *pslink;                                                  //~v6k5I~
//********************************                                 //~v6k5I~
    if (Popt & UFSLO_COPYOVERRIDE)   //     0x01                   //~v6k5R~
    {                                                              //~v6k5I~
        rc=uremove(Ptarget);                                       //~v6k5R~
    	UTRACEP("ufilesymlink_copy delete oviridden slink:%s rc=%d\n",Ptarget,rc);//~v6k5R~
    }                                                              //~v6k5I~
    pslink=Psrcslink;                                              //~v6k5I~
//  rc=ufilesymlink(Popt,pslink,Ptarget);                          //~v6ksR~
    rc=ufilesymlink(0/*opt:errmsg*/,pslink,Ptarget);               //~v6ksI~
    if (!rc)                                                       //~v6k5I~
    {                                                              //~v6kkI~
                                                                   //~v6ksI~
		ufilesymlink_copyfiletime(0,Psrc,Ptarget);                 //~v6ksI~
    	if (Popt &UFSLO_CHKTARGET)                                 //~v6k5I~
//  		ufilechkslinkpath(Psrc,pslink,Ptarget);                //~v6k5R~
    		ufilechkslinkpath(Psrc,pslink,Ptarget,NULL/*slinktarget*/,NULL/*ffb3*/);//~v6k5I~
    }                                                              //~v6kkI~
    UTRACEP("ufilesymlink_copy %s-->%s(-->%s=%s) rc=%d\n",Psrc,Ptarget,Psrcslink,pslink,rc);//~v6k5R~
    return rc;                                                     //~v6k5I~
}//ufilesymlink_copy                                               //~v6kkR~
#endif                                                             //~v6k5I~
//**************************************************************** //~v291I~
//errmsg sub                                                       //~v291I~
//*retrn:-1                                                        //~v291I~
//**************************************************************** //~v291I~
int ufileerrdirandfile(char *Psource,char *Ptarget)                //~v291I~
{                                                                  //~v291I~
//  uerrmsg("Cannot Copy Dir(%s) to File(%d)",                     //~v331R~
    uerrmsg("Cannot Copy Dir(%s) to File(%s)",                     //~v331I~
            "ディレクトリー(%s) からファイル(%s)へはCOPYできません",//~v291R~
            Psource,Ptarget);                                      //~v291I~
    return -1;                                                     //~v291I~
}                                                                  //~v291I~
//**************************************************************** //~v6k4I~
int ufileerrslinktarget(char *Psource,char *Ptarget,int Prc)       //~v6k4I~
{                                                                  //~v6k4I~
#ifdef W32                                                         //~v6k5I~
	uerrmsg("Could not override %s(Symlink/Junction/MountPoint) to %s(the other)",//~v6k4I~
    		"%s(シンボリックリンク/ジャンクション/マウントポイント)を %s(それ以外)には上書きできません",//~v6k4I~
            Psource,Ptarget);                                      //~v6k4I~
#else                                                              //~v6k5I~
	uerrmsg("Could not override %s(symlink) to %s(the other)",     //~v6k5I~
    		"%s(シンボリックリンク)を %s(それ以外)には上書きできません",//~v6k5I~
            Psource,Ptarget);                                      //~v6k5I~
#endif                                                             //~v6k5I~
    return Prc;                                                    //~v6k4I~
}                                                                  //~v6k4I~
//**************************************************************** //~v6k5I~
int ufileerrslinkappend(char *Psource,char *Ptarget,int Prc)       //~v6k5I~
{                                                                  //~v6k5I~
#ifdef W32                                                         //~v6k5I~
    uerrmsg("Append is not supported for Symlink/Junction/MountPoint(%s)",//~v6k5I~
          	"シンボリックリンク/ジャンクション/マウントポイント(%s)は Append出来ません",//~v6k5I~
            Psource);                                              //~v6k5I~
#else                                                              //~v6k5I~
    uerrmsg("Append is not supported for symlink(%s)",             //~v6k5I~
          	"シンボリックリンク(%s)は Append出来ません",           //~v6k5I~
            Psource);                                              //~v6k5I~
#endif                                                             //~v6k5I~
    return Prc;                                                    //~v6k5I~
}                                                                  //~v6k5I~
//**************************************************************** //~v6k5I~
int ufileerrnotargetslink(int Prc,char *Psrc,char *Pslinktarget)   //~v6k5R~
{                                                                  //~v6k5I~
//    Sslinktargeterr=1;                                             //~v6k5I~//~v6kdR~
	Gufile_opt|=GFILEOPT_RC_WARNING;                               //~v6kdI~
	uerrmsg("%s(Symbolic Link) is link(%s) err",                   //~v6kdR~
    		"%s(シンボリックリンク)はリンク(%s)エラー",            //~v6kdR~
              Psrc,Pslinktarget);                                  //~v6k5R~
    return Prc;                                                    //~v6k5I~
}                                                                  //~v6k5I~
