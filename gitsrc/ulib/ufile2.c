//*CID://+v6W4R~:                             update#=  452;
//************************************************************* //~5903R~
//*ufile2.c                                                        //~v5d7R~
//*  uxdelete,uremove,urename,urename2,uattrib,umkdir,urmdir       //~v520R~
//************************************************************* //~5617I~
//v6W4:180702 protect utrace file when opened by xe for browse     //~v6W4I~
//v6J3:170206 change errmsg for longname(move filename at end)     //~v6J3I~
//v6Ht:170122 (Win)reset v6Ho and force delete by /r option because if renamed at RONLYCHK phase,remains if user canceled//~v6HtI~
//v6Hq:170121 umkdir not apierr but exist msg                      //~v6HqI~
//v6Ho:170120 (Win)unconditionally delete too long name file(because prefix \\?\ allow up to 32K)//~v6HoI~
//v6H9:170109 (Win)del longname using \\?\ prefix and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H9I~
//v6H8:170109 (BUG)FTP del dir fail(remains subdir)                //~v6H8I~
//v6H6:170106 (Win)Sinbolic link is to dir and to file; rmdir and del top delete//~v6H6I~
//v6H1:161231 filename >_MAX_PATH occurs when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1R~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6G7:161219 xdd:quiet option(-q[n], one msg for each n deletion) //~v6G7I~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6yg:150314 avoid \\.\ is displayed on errmsg                    //~v6ygI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE"//~v6uaI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6q1:131128 (WIN)for wildname dir,use alias to get dirlist       //~v6q1I~
//v6q0:131126 (WIN)fails to delete wildcard entry;use shortname    //~v6q0I~
//v6kt:130706 (W32:BUG) not CloseHandle but FindClose for FindFirst//~v6ktI~
//v6kj:130704 copy directory timestamp(subdir and top when /c)     //~v6kjI~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ufile2.c dele junction by rmdir                      //~v6k4I~
//v6hu:120807 (WIN)display odd number file time stamp for xdc/xts for also Win//~v6huI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6dj:120323 (BUG of ftp)xdd did not delete subdir                //~v6bjI~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v62b:090724 (FTP:BUG) del dir confirm msg remains when member is file only(no dir member exist)//~v62bI~
//v62a:090723 To delete target of symbolic linc is dengerous(Wine set slink to Winndows drive)//~v62aR~//~v6H6R~
//            Now unlink smbolinc link only.                       //~v62aR~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5ms:080506 avoid delete "System Volume Information"(data for system recovery tool)//~v5msI~
//v5kn:070611 (LNX:BUG)xdd:do not allow "/" as option parm. for multiple file specification case(by wild card etc)//~v5knI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0R~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5fp:050319 (BUG:FTP)of v5fc;uftpwildfunc2 delete file only,so uwildfunc required after uftpwildfunc2//~v5fpI~
//v5fe:050123 (UNX:BUG)disket del rejected by the reason of root(xdd,xfs etc)//~v5feI~
//v5fc:050101 uwildfunc call after uftpwildfunc2 is duplicated for remote file//~v5fcI~
//v5fb:050101 avoid duplicated ronly chk of del for ftp del performance//~v5fbI~
//v5d7:040529 (FTP)delete process duplicated                       //~v5d7I~
//v5cq:040509 reject also wildcard root as delete or move source   //~v5cpI~
//v5cp:040509 (FTP:BUG)del cur dir chk;miss-consider hostname prefix//~v5cpI~
//v5c7:040330 (UNX)always ignore slink err(put on udirlist)        //~v5c7I~
//            (err occurs when edit rc=40:too many,rc=2:not found etc))//~v5c7I~
//v5c4:040330 (UNX:BUG)xdd fail if slink err(no entry on udirlist if slink err)//~v5c4I~
//v5as:040111 (FTP:BUG) 2nd of 2 or'ed uftpisremote is not executed.//~v5asI~
//v5ap:040110 (FTP:BUG)cpath chk get cdir of remote cur dir        //~v5apI~
//v5am:040110 (FTP)del file in a dir at once for performance       //~v5amI~
//v5ak:040108 (WIN-FTP:BUG)dir dele fail by wind dirsepc           //~v5akI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v59q:031124 (UNX)xdd protection for dir/file owned by root group user//~v59qI~
//v59p:031110 ftp support:mkdir etc                                //~v59pI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v56x:020805 (BUG)editfilename DBCS support                       //~v56xI~
//v564:020702 (UNX:BUG) parm msg "/" to "-"                        //~v55rI~
//v55r:020525 (UNX)no fd option for xdd cmd                        //~v55rI~
//v55d:020428 (UNX:BUG)not found msg when diskfull for move(target is not created yet)//~v55dI~
//v55c:020428 (UNX:BUG)ROOTDIR chk for mdos disket                 //~v55cI~
//v557:020427 (UNX)disket support(mren) for rename file            //~v557I~
//v556:020427 (UNX)disket support(mdel) for delete file            //~v556I~
//v520:011228 support move override                                //~v520I~
//v50b:010324 LINUX:ajust after merge                              //~v50bI~
//v40c:001109 AIX support:compiler chk string after #else,#endif   //~v40cI~
//v39U:010204 LINUX support:errmsg when root delete                //~v39UI~
//v393:001103 LINUX support:dirlist sort by case sensitive         //~v393I~
//v379:000930 LINUX support(4 byte attr)                           //~v379I~
//v367:000927 LINUX support(rename/unlink fail if owner is different,and get EPAERM)//~v367I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v352:000926 LINUX support(permission err msg for rename)         //~v352I~
//v351:000926 LINUX support(filename on permission err msg)        //~v351I~
//v350:000926 LINUX support(no drive id)                           //~v350I~
//v346:000925 LINUX support(command flag parm prefix is "-" and "/"(if not 1st opd))//~v346I~
//v327 000820:LINUX support                                        //~v327I~
//v294:991104 display timestamp for confirm xdd each query         //~v294I~
//v282:990911 xdd assume *.* for a:,b:                             //~v282I~
//v281:990911 xdd confirm each support                             //~v281I~
//v278:990813 rename:wildcard source support                       //~v278I~
//v277:990813 rename:wildcard target support                       //~v278I~
//v276:990813 chk wild card before rename                          //~v276I~
//v195:980920 display attr/size on xdd list                        //~v195I~
//v194:980920 (BUG of WIN)win allow filename ".aaa"                //~v194I~
//v160:980201 xdd:standard codepage specification format(/y9,/n9)  //~v160I~
//v135:971227 (GCC)no actual effect but take same spec as dos for open mode//~v135I~
//            to setftime                                          //~v135I~
//v121:971120 (GCC)use _chmod for LFN support of _dos_setfileattr/_dos_getfileattr//~v121I~
//                 use _dos_setftime/_dos_open/_dos_close-->       //~v121I~
//                     setftime/open/close                         //~v121I~
//v085:970518 protect reset read only,rename "ea data. sf" etc.    //~v085I~
//            (on root dir except a: b:)                           //~v085I~
//v057:970125:(BUG)DOS only,ucopypath info forgotten to set rc     //~v057I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -djgpp rename delete new then rename,so chk new name at first//~v053I~
//            -different parm no for mkdir,rc=10(EEXIST) if dup dir(dup file=4)//~v053I~
//            -getcwd,chdir,dup,dup2,rmdir is on unistd.h          //~v053I~
//v036:961016:new member for errmsg of ufile_.c                    //~v036I~
//v035:961016:_dos_open of ugetftime fail for dir,so use ufstat    //~v035I~
//            _dos_open of usetftime fail for dir,so chk it before open//~v035I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v017:960519:(BUG)contain current dir chk bug for wild card case  //~v017I~
//v016:960503:shareing violation err msg for DosSetPathInfo,rename //~v016R~
//v015:960503:get EACCESS when hold by other process               //~v014I~
//v014:960503:EACCESS is redefined as EACCES                       //~v014I~
//v013:960427:(BUG)(OS/2 DOSsession only)_dos_setftime faile(errno=22)//~v012I~
//            success if opened with write permission but need no read only//~v012I~
//            attribute for write open.so need before attr set     //~v012I~
//v012:960203:(BUG)(DOS)attr change for dir failed because      //~v012I~
//            subdir mask bit must be dropped evenif for dir.      //~v012R~
//            so I can also call pathinfo but cannot _dos_open for dir,//~v012I~
//            so copy only attr                                 //~v012I~
//v011:960131:add xdd function(parm chk,call xdelete and issue msg)//~v011I~
//v010:960120:uxdelete,read only chk option,force del  read only option//~v010I~
//951125:dir list sort by Name(process name seq)                //~5B25I~
//951125:root/current dir chk for rmdir                         //~5B25R~
//951123:xdelete:msg also for top dir deleted                   //~5B23R~
//951123:xdelete:chk dir before rmdir evenif deldir sw on       //~5B23I~
//951119:top dir del by option                                  //~5B19I~
//951111:move uxcopy to ufile3.c
//951111:uxdelete(dir/wild card del support)                    //~5B12I~
//951111:urename err msg(dup name for also dir)                 //~5B11R~
//v052:951014:xcopy file already exist msg for dir,it must be "in dir"//~v052I~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950923 mask(/S option) support                               //~5923I~
//*950923 dos,protect repl when attr(S/H) down                  //~5923I~
//*950909 ucopy/umove/umkdir/urmdir                             //~5909R~
//*950903 uattrib                                               //~5903I~
//************************************************************* //~5903I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5825I~
//*******************************************************
#ifdef UNX                                                         //~v327I~
	#include <unistd.h>                                            //~v327I~
	#include <dirent.h>                                            //~v6b1I~
#ifdef UTF8SUPPH                                                   //~v62aM~
	#include <sys/stat.h>                                          //~v62aI~
	#include <sys/file.h>                                          //~v6B1I~
	#include <sys/types.h>                                         //~v6B1I~
	#include <fcntl.h>                                             //~v6B1I~
#endif                                                             //~v62aM~
#else                                                              //~v327I~
	#include <direct.h>                                            //~v327I~
#ifdef DOS
    #include <dos.h>
    #include <fcntl.h>                                          //~5916I~
    #include <conio.h>                                             //~v281I~
    #ifdef DPMI                 //DPMI version                     //~v053I~
        #include <sys/stat.h>                                      //~v053I~
        #include <unistd.h>                                        //~v053I~
        #include <io.h>         //_chmod                           //~v121I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
#else
    #ifdef W32                                                     //~v022I~
        #include <dos.h>                                           //~v022I~
        #include <io.h>                                            //~v022I~
        #include <conio.h>                                         //~v281I~
        #include <windows.h>                                   //~v034I~//~v034R~
    #else                                                          //~v022I~
    #define INCL_BASE
    #define INCL_DOSFILEMGR                                     //~5903I~
        #include <conio.h>                                         //~v281I~
    #include <os2.h>
    #endif                                                         //~v022I~
#endif
#endif                                                             //~v327I~

//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v59pI~
#include <ufile.h>
#include <ufile2.h>                                             //~5826I~
#include <ufile2l2.h>                                              //~v556I~
#include <ufile3.h>                                                //~v6H1I~
#include <ufile4.h>                                                //~v6q0I~
#include <ufile5.h>                                                //~v276I~
#include <ufemsg.h>                                                //~v036I~
#include <uerr.h>
#include <ualloc.h>                                             //~5913I~
#include <ustring.h>                                               //~v085I~
#include <utrace.h>                                                //~v012I~
#include <uedit.h>                                                 //~v195R~
#ifdef AIX                                                         //~v56xI~
	#include <ugcclib.h>                                           //~v56xR~
#endif                                                             //~v56xI~
#ifdef FTPSUPP                                                     //~v59pR~
	#include <uftp.h>                                              //~v59pR~
	#include <ufile1f.h>                                           //~v59pR~
	#include <u3270.h>                                             //~v5jdI~
	#include <u32702.h>                                            //~v5jdI~
	#include <ucalc2.h>                                            //~v6huI~
#endif                                                             //~v59pI~
#ifdef UNX                                                         //~v6b1I~
	#include <ufile1l.h>                                           //~v6b1I~
#endif                                                             //~v6b1I~
#define REDIRECT_FINDFILE                                          //~v6uaI~
#include <ufilew.h>                                                //~v6uaI~
//*******************************************************
#define EADATAID   "EA DATA. SF"                                //~5911I~
#define WINSYSVOLI "System Volume Information"                     //~v5msI~
#define TEMPDIR_FOR_DELETE_LONGNAME          "_"        //~v6H1I~  //~v6H9R~
#define TEMPDIR_FOR_DELETE_LONGNAME_MAXRETRY 10                    //~v6H1I~
//*******************************************************       //~5916I~
#if defined(UNX) || defined(W32)                                   //~v520I~
static int Srenameexisting=0;                                      //~v520I~
#endif                                                             //~v520I~
static int Sxddendsw=0;       //Select cancelend sw                //~v520R~
static int Sxdelopt=0;                                             //~v520R~
static int Sxdelfctr=0;       //process ctr                        //~v520R~
static int Sxdeldctr=0;       //deleted file/dir ctr               //~v520R~
static int Sxdelrctr=0;   //read only file/dir ctr                 //~v520R~
static int Sxdellongnamectr=0;   //too long name file ctr          //~v6H1I~
#ifdef UNX                                                         //~v6b1I~
static int Sxdelwctr=0;   //wildname file ctr,at ronlychk          //~v6b1I~
#endif                                                             //~v6b1I~
//static long Sxdelsize=0;    //total size deleted by xdd          //~v5k0R~
static FILESZT Sxdelsize=0;    //total size deleted by xdd         //~v5k0R~
#ifdef W32                                                         //~v6huI~
static int Soddsec=0;                                              //~v6huI~
#endif                                                             //~v6huI~
static int Squiettotalctr,Squietctr;                               //~v6G7R~
static int Srenamenomsg;                                           //~v6H1I~
//*******************************************************       //~5B14I~
//int uxdelsub(UCHAR *Pfile,UCHAR Pattr,unsigned Pattrmask,int Pdeldirsw,long Psize);//~v379R~
//int uxdelsub(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,long Psize);//~v5k0R~
//int uxdelsub(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,FILESZT Psize);//~v5k0R~//~v6bjR~
                                                                   //~v379I~
//int ufileroot(char *Pfullpath,int Prc);                          //~v39UR~
WILDAPPLYFUNC ufilewildxdel;                                    //~5B12M~
WILDAPPLYFUNC ufilewildrename;                                     //~v278I~
int ufilechkwildname(int Popt,char *Pfnm,int *Ppctr);              //~v6q0R~
#define CWMO_ERRMSG      0x01                                      //~v6q0I~
#define CWMO_RENAME      0x02                                      //~v6q0I~
void ufile2quietmsg(int Popt,char *Pfile);                         //~v6G7R~
int uwildfunc_LongName(int Popt,UCHAR *Psource,ULONG Pattr,unsigned Pattrmask,WILDAPPLYFUNC *Pfunc,void *Pparm,/*int *Pfilectr,*/char *Pfpathrename);//~v6H1R~
#define UWDLO_LONGDIR    0x01                                      //~v6H1I~
//*******************************************************
//*dummy for lib(same name as file)                     *
//*******************************************************
void ufile2(void)                                               //~5826R~
{
    return;
}
                                                                //~5909I~
#ifndef UNX  //!!!!!!!!!!!                                         //~v327I~
//****************************************************************//~5909I~
//*umkdir                                                       //~5909I~
//* create dir                                                  //~5909I~
//*parm1:dir name                                               //~5909I~
//*retrn:rc(=errno)                                             //~5909I~
//****************************************************************//~5909I~
int umkdir(UCHAR *Pdirname)                                     //~5909I~
{                                                               //~5909I~
    int rc;                                                     //~5909I~
    FILEFINDBUF3 fstat3;                                        //~5909I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5909I~
#ifdef FTPSUPP                                                     //~v59qI~
  	if (uftpisremote(Pdirname,&puftph))	//ftp filename             //~v5afR~
    	return uftpmkdir(puftph,Pdirname,0,0);                     //~v5afR~
#endif                                                             //~v59qI~
#if defined(DOS) || defined(W32)                                   //~v022R~
    #ifdef DPMI                 //DPMI version                     //~v053I~
        rc=mkdir(Pdirname,0);                                      //~v053I~
    #else                       //not DPMI                         //~v053I~
    rc=mkdir(Pdirname);                                         //~5909I~
    #endif                      //DPMI or not                      //~v053I~
#else                                                           //~5909I~
    rc=_mkdir(Pdirname);                                        //~5909I~
#endif                                                          //~5909I~
    if (!rc)                                                    //~5909I~
        return 0;                                               //~5909I~
    rc=errno;       //save original errno;                      //~5909I~
    if (Gufile_nomsg)   //nomsg option                          //~5909I~
        return rc;                                              //~5909I~
                                                                //~5909I~
    switch(rc)                                                  //~5909I~
    {                                                           //~5909I~
    case ENOENT:                                                //~5909I~
        return ufilepatherr(Pdirname,rc);                       //~5909I~
//#ifdef DOS                                                       //~v014R~
    case EACCES:                                                //~5909I~
//#else                                                            //~v014R~
//  case EACCESS:                                                  //~v014R~
//#endif                                                           //~v014R~
        if (!ufstat(Pdirname,&fstat3))                          //~5909I~
            return ufileexist(Pdirname,rc);                     //~5909I~
        break;                                                  //~5909I~
//  #ifdef DPMI                 //DPMI version                     //~v053I~//~v6HqR~
    case EEXIST:                                                   //~v053I~
        return ufileexist(Pdirname,rc);                            //~v053I~
//  #else                       //not DPMI                         //~v053I~//~v6HqR~
//  #endif                      //DPMI or not                      //~v053I~//~v6HqR~
    }                                                           //~5909I~
    return ufileapierr("mkdir",Pdirname,rc);                    //~5909R~
}//umkdir                                                       //~5909R~
#ifdef FTPSUPP                                                     //~v59qI~
//**************************************************************** //~v59qI~
//*umkdir                                                          //~v59qI~
//* create dir                                                     //~v59qI~
//*parm1:dir name                                                  //~v59qI~
//*parm2:request modifier                                          //~v59qI~
//*parm3:optional resulted modifier                                //~v59qI~
//*retrn:rc(=errno)                                                //~v59qI~
//**************************************************************** //~v59qI~
int umkdirmode(UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode)         //~v59qI~
{                                                                  //~v59qI~
    ULONG mode;                                                    //~v59qI~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~v59qI~
    mode=Pmode & 07777;                                            //~v59qI~
  	if (uftpisremote(Pdirname,&puftph))	//ftp filename             //~v5afR~
    	return uftpmkdir(puftph,Pdirname,mode,Pprmode);            //~v5afR~
	return uftpnotsupportedforlocal("mkdir with mode",Pdirname);   //~v59qI~
}//umkdirmode                                                      //~v59qI~
//**************************************************************** //~v59qI~
//*retrn:rc                                                        //~v59qI~
//**************************************************************** //~v59qI~
int uattrxon(UCHAR *Pfname)                                        //~v59qI~
{                                                                  //~v59qI~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~v59qI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpattrxon(puftph,Pfname);                         //~v5afR~
	return uftpnotsupportedforlocal("x-bit on",Pfname);            //~v59qI~
}//uattrxon                                                        //~v59qI~
//**************************************************************** //~v59qI~
//uattrxchk                                                        //~v59qI~
//* chk x bit(USER)                                                //~v59qI~
//*parm1:filename                                                  //~v59qI~
//*parm2:opt to issue errmsg                                       //~v59qI~
//*retrn:rc:0 not executable,1:executable                          //~v59qI~
//**************************************************************** //~v59qI~
int uattrxchk(UCHAR *Pfname,int Popt)                              //~v59qI~
{                                                                  //~v59qI~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~v59qI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpattrxchk(puftph,Pfname,Popt);                   //~v5afR~
	return uftpnotsupportedforlocal("x-bit chk",Pfname);           //~v59qI~
}//uattrxchk                                                       //~v59qI~
#endif                                                             //~v59qI~
//****************************************************************//~5909I~
//*urmdir                                                       //~5909I~
//* remove dir                                                  //~5909I~
//* Win longname support by rmdir(urmdirW)                         //~v6H9I~
//* dir must be empty,not root nor current dir                  //~5909I~
//*parm1:dir name                                               //~5909I~
//*retrn:rc(=errno),-2:root dir,-3:current dir                  //~5B25R~
//****************************************************************//~5909I~
int urmdir(UCHAR *Pdirname)                                     //~5909I~
{                                                               //~5909I~
    int rc;                                                     //~5909I~
#ifdef W32                                                         //~v6H9I~
    int lasterr;                                                   //~v6H9I~
#endif                                                             //~v6H9I~
//  UCHAR fullpath[_MAX_PATH];                                  //~5909I~//~v6H9R~
    UCHAR fullpath[_MAX_PATH_LONG];                                //~v6H9I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5909I~
#ifdef FTPSUPP                                                     //~v59qR~
  	if (uftpisremote(Pdirname,&puftph))	//ftp filename             //~v5afR~
		return uftprmdir(puftph,Pdirname);                         //~v5afR~
#endif                                                             //~v59pI~
//  if (!ufullpath(fullpath,Pdirname,_MAX_PATH))                //~5909I~//~v6H9R~
    if (!ufullpath(fullpath,Pdirname,sizeof(fullpath)))            //~v6H9I~
        return -1;                                              //~5909I~
    if (ROOTDIR2(fullpath))  //dosfindfirst faile if root          //~v55cI~
        return ufileroot(fullpath,-2);                             //~v55cI~
#if defined(DOS) || defined(W32)                                   //~v022I~
    rc=rmdir(fullpath);                                         //~5909R~
#else                                                           //~5909I~
    rc=_rmdir(fullpath);                                        //~5909R~
#endif                                                          //~5909I~
    if (!rc)                                                    //~5909I~
        return 0;                                               //~5909I~
    rc=errno;       //save original errno;                      //~5909I~
#ifdef W32                                                         //~v6H9I~
    lasterr=GetLastError();                                        //~v6H9I~
#endif                                                             //~v6H9I~
    if (Gufile_nomsg)   //nomsg option                          //~5909I~
        return rc;                                              //~5909I~
                                                                //~5909I~
    switch(rc)                                                  //~5909I~
    {                                                           //~5909I~
    case ENOENT:                                                //~5909I~
        return ufilenotfound(fullpath,rc);                      //~5909R~
//#ifdef DOS                                                       //~v014R~
    case EACCES:                                                //~5909I~
//#else                                                            //~v014R~
//  case EACCESS:                                                  //~v014R~
//#endif                                                           //~v014R~
//      if (ROOTDIR(fullpath))  //dosfindfirst faile if root       //~v55cR~
//          return ufileroot(fullpath,-2);                         //~v55cR~
        if (ufilecdirchk(fullpath))                             //~5B25I~
            return ufiledelpath(fullpath,-3);                   //~5B25I~
        uerrmsg("%s is not empty or opened",                       //~v015R~
                "%s は 空でないかオープン中",                      //~v015R~
//              fullpath);                                      //~5909R~//~v6ygR~
                STD_FNM(fullpath));                                //~v6ygI~
        return rc;                                              //~5909I~
    case ENOTEMPTY:                                                //~v6H1I~
//      uerrmsg("%s is not empty",                                 //~v6H1I~//~v6J3R~
//              "%s は 空でない",                                  //~v6H1I~//~v6J3R~
        uerrmsg("Not empty dir:%s",                                //~v6J3I~
                "空でないDir:%s",                                  //~v6J3I~
                STD_FNM(fullpath));                                //~v6H1I~
        return rc;                                                 //~v6H1I~
    }                                                           //~5909I~
#ifdef W32                                                         //~v6H9I~
    if (rc==0)                                                     //~v6H9I~
        rc=lasterr;                                                //~v6H9I~
#endif                                                             //~v6H9I~
    return ufileapierr("rmdir",fullpath,rc);                    //~5909R~
}//urmdir                                                       //~5909R~
//#ifdef W32                                                       //~v6H9R~
////****************************************************************//~v6H9R~
////*rmdir by unicode version api for longname                     //~v6H9R~
////****************************************************************//~v6H9R~
//int urmdirWW(int Popt,UCHAR *Pdirname)                           //~v6H9R~
//{                                                                //~v6H9R~
//    int rc;                                                      //~v6H9R~
//    int ucsctr;                                                  //~v6H9R~
////  UCHAR fullpath[_MAX_PATH];                                   //~v6H9R~
//    UCHAR fullpath[_MAX_PATH_LONG];                              //~v6H9R~
//    PUFTPHOST puftph;                                            //~v6H9R~
////********************                                           //~v6H9R~
//    if (uftpisremote(Pdirname,&puftph)) //ftp filename           //~v6H9R~
//        return uftprmdir(puftph,Pdirname);                       //~v6H9R~
////  if (!ufullpath(fullpath,Pdirname,_MAX_PATH))                 //~v6H9R~
//    if (!u_fullpathWLong(0,fullpath,0/*out fullpathw*/,Pdirname,sizeof(fullpath),&ucsctr))//~v6H9R~
//        return -1;                                               //~v6H9R~
//    if (ROOTDIR2(fullpath))  //dosfindfirst faile if root        //~v6H9R~
//        return ufileroot(fullpath,-2);                           //~v6H9R~
//    if (ucsctr<_MAX_PATH)                                        //~v6H9R~
//        return urmdir(fullpath);                                 //~v6H9R~
////  rc=rmdir(fullpath);                                          //~v6H9R~
//    rc=urmdirWLong(0,fullpath);                                  //~v6H9R~
//    if (!rc)                                                     //~v6H9R~
//        return 0;                                                //~v6H9R~
//    rc=errno;       //save original errno;                       //~v6H9R~
//    if (Gufile_nomsg)   //nomsg option                           //~v6H9R~
//        return rc;                                               //~v6H9R~
//                                                                 //~v6H9R~
//    switch(rc)                                                   //~v6H9R~
//    {                                                            //~v6H9R~
//    case ENOENT:                                                 //~v6H9R~
//        return ufilenotfound(fullpath,rc);                       //~v6H9R~
//    case EACCES:                                                 //~v6H9R~
//        if (ufilecdirchk(fullpath))                              //~v6H9R~
//            return ufiledelpath(fullpath,-3);                    //~v6H9R~
//        uerrmsg("%s is not empty or opened",                     //~v6H9R~
//                "%s は 空でないかオープン中",                    //~v6H9R~
//                STD_FNM(fullpath));                              //~v6H9R~
//        return rc;                                               //~v6H9R~
//    case ENOTEMPTY:                                              //~v6H9R~
//        uerrmsg("%s is not empty",                               //~v6H9R~
//                "%s は 空でない",                                //~v6H9R~
//                STD_FNM(fullpath));                              //~v6H9R~
//        return rc;                                               //~v6H9R~
//    }                                                            //~v6H9R~
//    return ufileapierr("rmdir",fullpath,rc);                     //~v6H9R~
//}//urmdirWW                                                      //~v6H9R~
//#endif //W32                                                     //~v6H9R~
#endif //!UNX !!!!!!!!!!!                                          //~v327I~
                                                                //~5909I~
//******************************************************************//~v011M~
//*uxddpchk                                                     //~v011R~
//*   xdd parameter chk                                         //~v011M~
//*parm1:pgmname/version(batch only,0:called from xe)           //~v011R~
//*parm2:parameter count                                        //~v011M~
//*parm3:parameter string list(term by double null char)        //~v011M~
//*parm4:output xdelete option addr set by parm                 //~v011M~
//*parm5:output xdd option addr set by parm                     //~v011M~
//*parm6:output positional parm no                              //~v011M~
//*ret  :invalid parm ptr                                       //~v011I~
//******************************************************************//~v011M~
char *uxddpchk(char *Ppgmver,int Pparmc,char *Pparm,            //~v011R~
                int *Pxdelopt,int *Pxddopt,int *Pposparmno)     //~v011M~
{                                                               //~v011M~
    UCHAR ch;                                                   //~v011M~
    int xdelopt=0,xddopt=0,ii;                                  //~v011M~
    char *cptr,*parmp;                                          //~v011M~
    int quietctr=0;                                                //~v6G7I~
//***************                                               //~v011M~
	*Pposparmno=0;		//(BUG)should be init                      //~v346I~
    for (parmp=Pparm,ii=0;ii<Pparmc;ii++,parmp+=(strlen(parmp)+1))//~v011M~
    {                                                           //~v011M~
        cptr=parmp;                                             //~v011M~
#ifdef UNX                                                         //~v346I~
//    	if (!CMDFLAGCHK(*cptr,*Pposparmno))                        //~v5knR~
      	if (!CMDFLAGCHK(*cptr,0))                                  //~v5knI~
#else                                                              //~v346I~
        if(*cptr!='/')                                          //~v011M~
#endif                                                             //~v346I~
        {                                                       //~v011M~
            (*Pposparmno)++;                                    //~v011M~
            continue;                                           //~v011M~
        }                                                       //~v011M~
                                                                //~v011M~
        ch=*(++cptr);                      //first option byte  //~v011M~
        switch(toupper(ch))       //option                      //~v011M~
        {                                                       //~v011M~
        case 'Q':   //quiet                                        //~v6G7I~
            ++cptr;                                                //~v6G7I~
            xdelopt|=UXDELQUIET;                                   //~v6G7R~
            quietctr=atoi(cptr);      //option                     //~v6G7R~
            if (quietctr==0)                                       //~v6G7I~
	            Squietctr=1000;                                    //~v6G7I~
            else                                                   //~v6G7I~
            if (quietctr==1)                                       //~v6G7I~
	            Squietctr=10;                                      //~v6G7R~
            else                                                   //~v6G7I~
            if (quietctr==2)                                       //~v6G7I~
	            Squietctr=100;                                     //~v6G7I~
            else                                                   //~v6G7I~
            if (quietctr==3)                                       //~v6G7I~
	            Squietctr=1000;                                    //~v6G7I~
            else                                                   //~v6G7I~
            if (quietctr==4)                                       //~v6G7I~
	            Squietctr=10000;                                   //~v6G7I~
            else                                                   //~v6G7I~
	            Squietctr=100000;                                  //~v6G7I~
            break;                                                 //~v6G7I~
        case 'R':   //force                                     //~v011M~
            ++cptr;                                             //~v011M~
            switch(toupper(*cptr))      //option                //~v011M~
            {                                                   //~v011M~
            case '-':                                           //~v011M~
                xdelopt|=UXDELSKIPRONLY;                        //~v011M~
                break;                                          //~v011M~
            case 'L':                                           //~v011M~
                xdelopt|=UXDELRONLYCHK;                         //~v011M~
                break;                                          //~v011M~
            case '+':                                           //~v011M~
            case 0:                                             //~v011M~
                xdelopt|=UXDELFORCE;                            //~v011M~
                break;                                          //~v011M~
            default:                                            //~v011M~
#ifdef UNX                                                         //~v59qI~
                if (!stricmp(cptr-1,"root"))                       //~v59qR~
                {                                                  //~v59qI~
	                xdelopt|=UXDELFORCEROOT;                       //~v59qI~
                    break;                                         //~v59qI~
                }                                                  //~v59qI~
#endif                                                             //~v59qI~
                return parmp;                                   //~v011I~
            }                                                   //~v011M~
            break;                                              //~v011M~
        case 'S':   //force                                        //~v281I~
            xdelopt|=UXDELCONFEACH; //confirma each member of top level//~v281M~
            break;                                                 //~v281M~
#ifdef UNX                                                         //~v55rI~
        case 'U':   //UNIX file                                    //~v55rI~
            xdelopt|=UXDELNOTFD   ; //no fd support                //~v55rI~
            break;                                                 //~v55rI~
        case 'W':   //force for wildname entry                     //~v6b1I~
            if (Gufile_opt & GFILEOPT_XDDUTIL)                     //~v6b1I~
            {                                                      //~v6b1I~
            	Gufile_opt|=GFILEOPT_WILDCARDNAMEOK;               //~v6b1R~
            }                                                      //~v6b1I~
            break;                                                 //~v6b1I~
#endif                                                             //~v55rI~
        case 'Y':   //replyed yes                               //~v011M~
            ++cptr;                                                //~v160I~
          if (*cptr=='9')                                          //~v160R~
          {                                                        //~v160R~
            if (!Ppgmver)   //xe online                            //~v160R~
                return parmp;                                      //~v160R~
            uerrmsg_init(Ppgmver,stdout,0);//msg to stdout         //~v160R~
            xddopt&=~UXDDENGLISH;       //by dbcschk               //~v281R~
          }                                                        //~v160R~
          else                                                     //~v160R~
            xddopt|=UXDDNOCONF;                                 //~v011M~
            break;                                              //~v011M~
//      case '4':   //code page 437                                //~v160R~
        case 'N':   //code page 437                                //~v160I~
            ++cptr;                                                //~v160I~
          if (*cptr=='9')                                          //~v160I~
          {                                                        //~v160I~
            if (!Ppgmver)   //xe online                         //~v011R~
                return parmp;                                   //~v011I~
            uerrmsg_init(Ppgmver,stdout,UERR_FORCE_ENGLISH);//msg to stdout//~v011R~
            xddopt|=UXDDENGLISH;        //force english            //~v281R~
          }                                                        //~v160I~
          else                                                     //~v160I~
            return parmp;                                          //~v160I~
            break;                                              //~v011M~
//      case '9':   //code page 932                                //~v160R~
//          if (!Ppgmver)   //xe online                            //~v160R~
//              return parmp;                                      //~v160R~
//          uerrmsg_init(Ppgmver,stdout,0);//msg to stdout         //~v160R~
//          break;                                                 //~v160R~
        case 'H':   //code page 437                                //~v6G7I~
        case '?':   //code page 437                                //~v6G7I~
            *Pposparmno=0;  //issue help                           //~v6G7I~
            return 0;                                              //~v6G7I~
        default:                                                //~v011M~
            return parmp;                                       //~v011I~
        }//kwd parm                                             //~v011M~
    }//for all parm                                             //~v011M~
    *Pxdelopt=xdelopt;                                          //~v011M~
    *Pxddopt=xddopt;                                            //~v011M~
    return 0;                                                   //~v011M~
}//uxddpchk                                                     //~v011R~
                                                                //~v011M~
//******************************************************************//~v011M~
//*uxddsub                                                      //~v011R~
//*   delete one entry                                          //~v011M~
//*parm1:name                                                   //~v011M~
//*parm2:xdelete option parm                                    //~v011M~
//*parm3:xdd option                                             //~v011M~
//*parm4:output fullpath name                                   //~v011M~
//*ret  :rc 0:ok,1:need confirm,2:read only/longname,8:err         //~v6H1R~
//******************************************************************//~v011M~
int uxddsub(char *Pname,int Pxdelopt,int Pxddopt,char *Pfullpath)//~v011R~
{                                                               //~v011M~
    int dirsw,delctr,ronlyctr,filectr;                          //~v011M~
    int msgopt;                                                 //~v011M~
    FILEFINDBUF3 fstat3;                                        //~v011M~
    char editwk[16];                                               //~v195I~
#ifdef FTPSUPP                                                     //~v5jdI~
    PUFTPHOST puftph;                                              //~v5jdR~
#endif                                                             //~v5jdI~
	int rc2;                                                       //~v6H8I~
//***********************                                       //~v011M~
    if (!ufullpath(Pfullpath,Pname,_MAX_PATH))                  //~v011M~
        return 8;                                               //~v011M~
#ifdef FTPSUPP                                                     //~v5jdI~
    if (uftpisremote(Pfullpath,&puftph))                           //~v5jdI~
    	if (UFTPHISTSO(puftph))                                    //~v5jdI~
        	return u3270xddsub(puftph,Pxdelopt,Pxddopt,Pfullpath); //~v5jdI~
#endif                                                             //~v5jdI~
//  if (ROOTDIR(Pfullpath))                                        //~v55cR~
    if (ROOTDIR2(Pfullpath))                                       //~v55cI~
#ifdef UNX                                                         //~v327I~
//      return 8;                                                  //~v39UR~
	{                                                              //~v55cI~
	  if (ROOTDIR(Pfullpath))                                      //~v55cI~
        return ufileroot(Pfullpath,8);                             //~v39UR~
      strcpy(Pfullpath+3,DIR_ALLMEMB);                             //~v55cI~
    }                                                              //~v55cI~
#else                                                              //~v327I~
    {                                                              //~v5ncI~
        if (*Pfullpath=='A' || *Pfullpath=='a'                     //~v282I~
        ||  *Pfullpath=='B' || *Pfullpath=='b') //disket           //~v282I~
	#ifdef FTPSUPP                                                 //~v5akI~
          if (uftpisremote(Pfullpath,0))                           //~v5akI~
        	return ufileroot(Pfullpath,8);                         //~v5akI~
          else                                                     //~v5akI~
    #endif                                                         //~v5akI~
            strcpy(Pfullpath+3,"*.*");                             //~v282I~
        else                                                       //~v55cI~
        {                                                          //~v5msI~
//      	return ufileroot(Pfullpath,8);                         //~v5msR~
            uerrmsg("Use wildcard to delete entry in root directory",0);//~v5msI~
        	return 8;                                              //~v5msI~
        }                                                          //~v5msI~
    }                                                              //~v5ncI~
#endif                                                             //~v327I~
    if (ufstat(Pfullpath,&fstat3)) //not found                  //~v011M~
        return ufilenotfound(Pfullpath,8);                      //~v011M~
    dirsw=UCBITCHK(fstat3.attrFile,FILE_DIRECTORY)              //~v011R~
          ||WILDCARD(Pfullpath);                                //~v011I~
#ifdef UTF8SUPPH                                                   //~v62aM~
  	if (FILE_ISSLINK(fstat3.attrFile))		//slink entry          //~v62aR~
		dirsw=0;                                                   //~v62aI~
#endif                                                             //~v62aM~
    msgopt=Pxdelopt&UXDELMSG;    //msg output option            //~v011M~
    if  (Pxdelopt & UXDELRONLYCHK)  //chk only                  //~v011M~
    {                                                           //~v011M~
        if (uxdelete(Pfullpath,FILE_ALL,msgopt|UXDELRONLYCHK|UXDELFORCE,//~v011M~
//                  &filectr,&ronlyctr,&delctr))    //list read only file//~v6H1R~
                    &filectr,&ronlyctr,&delctr) & ~UWFRC_LONGNAME)    //list read only file//~v6H1I~
            return 8;                                           //~v011M~
#ifdef UNX                                                         //~v6b1M~
        if (Sxdelwctr && (Pxdelopt & UXDELUNDELCOPY))              //~v6b1M~
        {                                                          //~v6b1M~
            uerrmsg("%s contains %d Wildname entries",             //~v6b1M~
                    "%s 中の %d 件が無効(ワイルドカード)ファイル名です",//~v6b1M~
                    Pname,Sxdelwctr);                              //~v6b1M~
        	return FILE_WILDNAME;                                  //~v6b1M~
        }                                                          //~v6b1M~
#endif                                                             //~v6b1M~
//      uerrmsg("%s has %d Read-only out of %d entries",           //~v6H1R~//~v6H9R~
//              "%s の %d 件が読取専用(全 %d 件中)",               //~v6H1R~//~v6H9R~
//              Pname,ronlyctr,filectr);                        //~v011M~//~v6ygR~//~v6H9R~
//              STD_FNM(Pname),ronlyctr,filectr);                  //~v6H1R~//~v6H9R~
//#ifndef W32                                                        //~v6HoI~//~v6HtR~
      if ( Sxdellongnamectr)                                       //~v6H9I~
        uerrmsg("%d:Read-only, %d:Too long pathname out of %d of %s",//~v6H1I~
                "%d:読取専用,%d:長すぎるパス名,全:%d-%s",          //~v6H1I~
                ronlyctr,Sxdellongnamectr,filectr,STD_FNM(Pname)); //~v6H1I~
      else                                                         //~v6H9M~
//#endif                                                             //~v6HoI~//~v6HtR~
        uerrmsg("%d:Read-only out of %d of %s",                    //~v6H9I~
                "%d:読取専用,全:%d-%s",                            //~v6H9I~
                ronlyctr,filectr,STD_FNM(Pname));                  //~v6H9R~
        if (Sxdellongnamectr)                                      //~v6H1I~
        {                                                          //~v6H1I~
	        Sxdellongnamectr=0;                                    //~v6H1I~
#ifndef W32                                                        //~v6HqI~
            return 2;                                              //~v6H1I~
#endif                                                             //~v6HqI~
        }                                                          //~v6H1I~
        if (ronlyctr)                                           //~v011R~
            return 2;                                           //~v011I~
        else                                                    //~v011I~
            return 0;                                           //~v011I~
    }                                                           //~v011M~
//delete req                                                    //~v011M~
    if (dirsw)                                                  //~v011M~
        if (!(Pxddopt & UXDDNOCONF))    //not no confirm        //~v011M~
          if (!(Pxdelopt & UXDELCONFEACH))  //not each conf        //~v281I~
            return 1;                                           //~v011M~
    Squiettotalctr=0;                                              //~v6G7I~
  if  (!(Pxdelopt & UXDELRONLYCHKOK)) //not yet ronly chked        //~v5fbI~
  {                                                                //~v5fbI~
    if  (!(Pxdelopt & (UXDELFORCE|UXDELSKIPRONLY))) //not force //~v011R~
    {                                                           //~v011R~
        if (uxdelete(Pfullpath,FILE_ALL,UXDELNOMSG|UXDELFORCE|UXDELRONLYCHK,//~v011R~
                    &filectr,&ronlyctr,&delctr))    //count read only file//~v011R~
            return 8;                                           //~v011R~
	    Squiettotalctr=filectr;                                    //~v6G7I~
//      if (ronlyctr)                                              //~v6H1R~
//#ifndef W32                                                        //~v6HoI~//~v6HtR~
        if (ronlyctr||Sxdellongnamectr)                            //~v6H1I~
//#else                                                              //~v6HoI~//~v6HtR~
//        if (ronlyctr)                                              //~v6HoI~//~v6HtR~
//#endif                                                             //~v6HoI~//~v6HtR~
        {                                                       //~v011R~
//          uerrmsg("%s contains %d Raed-only entries,Use /r or /r- option",//~v55rR~
//                  "%s 中の %d 件が読取専用です,/r か /r- オプションが必要",//~v55rR~
//                  Pname,ronlyctr);                               //~v55rR~
#ifdef AIX                                                         //~v55rI~
          if (MDOSDISKOK(Pname))                                   //~v55rR~
            uerrmsg("DOS-Disk %s contains %d Read-only entries,%cr- option",//~v6b1R~
                    "DOS-Disk %s 中の %d 件が読取専用です,%cr- オプションが必要",//~v55rI~
                    Pname,ronlyctr,CMDFLAG_PREFIX);                //~v55rI~
          else                                                     //~v55rI~
#endif                                                             //~v55rI~
//          uerrmsg("%s contains %d Read-only entries,Use %cr or %cr- option",//~v6G7R~
//                  "%s 中の %d 件が読取専用です,%cr か %cr- オプションが必要",//~v6G7R~
//        uerrmsg("%s contains %d/%d Read-only entries,Use %cr or %cr- option",//~v6H1R~
//                "%s 中の %d/%d 件が読取専用です,%cr か %cr- オプションが必要",//~v6H1R~
//                  Pname,ronlyctr,CMDFLAG_PREFIX,CMDFLAG_PREFIX); //~v55rR~//~v6ygR~
//                  STD_FNM(Pname),ronlyctr,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v6G7R~
//                  STD_FNM(Pname),ronlyctr,filectr,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v6H1R~
//#ifndef W32                                                        //~v6HoI~//~v6HtR~
        if (Sxdellongnamectr)                                      //~v6H9R~
        	uerrmsg("Use %cr or %cr- option(%d:Read-only, %d:Too long pathname out of %d(except under long name directory) of \"%s\")",//~v6H1R~//~v6HtR~
            	    "%cr か %cr- オプションが必要(%d:読取専用,%d:長すぎるパス名,全:%d 件(長い名前のディレクトリーの下は未調査);\"%s\")",//~v6H1R~//~v6HtR~
                	CMDFLAG_PREFIX,CMDFLAG_PREFIX,ronlyctr,Sxdellongnamectr,filectr,STD_FNM(Pname));//~v6H1I~
        else                                                       //~v6H9I~
//#endif                                                             //~v6HoI~//~v6HtR~
        	uerrmsg("Use %cr or %cr- option(%d:Read-only out of %d of \"%s\")",//~v6H9I~
            	    "%cr か %cr- オプションが必要(%d:読取専用, 全:%d 件;\"%s\")",//~v6H9I~
                	CMDFLAG_PREFIX,CMDFLAG_PREFIX,ronlyctr,filectr,STD_FNM(Pname));//~v6H9I~
	        Sxdellongnamectr=0;                                    //~v6H1I~
            return 2;                                           //~v011R~
        }                                                       //~v011R~
    }                                                           //~v011R~
  }//!ronlychkok                                                   //~v5fbI~
    if (!dirsw)                                                 //~v011I~
        Pxdelopt|=UXDELMSG; //1 line msg for file               //~v011R~
    Sxddendsw=0;        //Select cancelend sw                      //~v281I~
//  if (uxdelete(Pfullpath,UXDELDIR,Pxdelopt,&filectr,&ronlyctr,&delctr))//~v011M~//~v6H8R~
    rc2=uxdelete(Pfullpath,UXDELDIR,Pxdelopt,&filectr,&ronlyctr,&delctr);//~v6H8I~
    if (rc2)                                                       //~v6H8I~
    if (rc2!=UXDELRC_FTP_RMDIR_FAILED)  //4097   //FTP rmdir Failed//~v6H8I~
    {                //deldir,file deleted msg                   //~v011M~//~v6H8R~
      if (!Sxddendsw)       //Select cancelend sw                  //~v281I~
        return 8;                                               //~v011M~
    }                                                              //~v6H8I~
    if (dirsw)                                                  //~v011I~
    {                                                              //~v195I~
//      unumedit((ULONG)Sxdelsize,"z,zzz,zzz,zz9",editwk);         //~v5k0R~
        ufileeditsz(0,Sxdelsize,editwk);                           //~v5k0R~
//      uerrmsg("%s is processed(total %d,deleted %d,Read-only %d;%s byte)",//~v6H1R~
//              "%s, 全 %d 件中 %d 件削除,読取専用は %d 件.(%s byte)",//~v6H1R~
//              Pname,filectr,delctr,ronlyctr,editwk);             //~v195R~//~v6ygR~
//              STD_FNM(Pname),filectr,delctr,ronlyctr,editwk);    //~v6H1R~
//#ifndef W32                                                        //~v6HoI~//~v6HtR~
      if (Sxdellongnamectr)                                        //~v6H9I~
        uerrmsg("%s is processed(total %d, deleted %d, Read-only %d, Longname %d; %s byte)",//~v6H1I~
                "%s, 全 %d 件中 %d 件削除,読取専用 %d, 長すぎるパス名 %d.(%s byte)",//~v6H1I~
                STD_FNM(Pname),filectr,delctr,ronlyctr,Sxdellongnamectr,editwk);//~v6H1I~
      else                                                         //~v6H9I~
//#endif                                                             //~v6HoI~//~v6HtR~
        uerrmsg("%s is processed(total %d, deleted %d, Read-only %d; %s byte)",//~v6H9I~
                "%s, 全 %d 件中 %d 件削除,読取専用 %d.(%s byte)",  //~v6H9I~
                STD_FNM(Pname),filectr,delctr,ronlyctr,editwk);    //~v6H9I~
        Sxdellongnamectr=0;                                        //~v6H1I~
    }                                                              //~v195I~
    if (rc2)                                                       //~v6H8I~
        return rc2;                                                //~v6H8I~
    return 0;                                                   //~v011M~
}//uxddsub                                                      //~v011R~
//****************************************************************//~5B12M~
//uxdelete                                                      //~5B12M~
//* del file/dir,wild card support                              //~5B12M~
//*parm1:filename                                               //~5B12M~
//*parm2:attr mask                                              //~5B12M~
//*parm3:del option   msg/read onlychk/force/conf each             //~v281R~
//*parm4:output total file/dir ctr                              //~v010R~
//*parm5:output readonly  file/dir ctr                          //~v010I~
//*parm6:output deleted file/dir ctr                            //~v010R~
//*retrn:rc                                                     //~5B12M~
//****************************************************************//~5B12M~
int uxdelete(UCHAR *Pfile,unsigned Pattrmask,int Popt,          //~v010R~
            int *Ppprocctr,int *Ppronlyctr,int *Ppdelctr)       //~v010I~
//#ifdef UNX                                                       //~v5c7R~
//{                                                                //~v5c7R~
//    int rc;                                                      //~v5c7R~
//    int uxdeleteunx(UCHAR *Pfile,unsigned Pattrmask,int Popt,    //~v5c7R~
//            int *Ppprocctr,int *Ppronlyctr,int *Ppdelctr);       //~v5c7R~
////*****************                                              //~v5c7R~
//    Gufile_opt|=GFILEOPT_IGNORESLINKERR; //ignore slink err      //~v5c7R~
//    rc=uxdeleteunx(Pfile,Pattrmask,Popt,Ppprocctr,Ppronlyctr,Ppdelctr);//del also slink err//~v5c7R~
//    Gufile_opt&=~GFILEOPT_IGNORESLINKERR;                        //~v5c7R~
//    return rc;                                                   //~v5c7R~
//}                                                                //~v5c7R~
//int uxdeleteunx(UCHAR *Pfile,unsigned Pattrmask,int Popt,        //~v5c7R~
//            int *Ppprocctr,int *Ppronlyctr,int *Ppdelctr)        //~v5c7R~
//#endif                                                           //~v5c7R~
{                                                               //~5B12M~
//  UCHAR fpath[_MAX_PATH];                                        //~v5d7R~//~v6H1R~
    UCHAR fpath[FTP_MAXPATH+8];                                    //~v6H1R~
    FILEFINDBUF3 fstat3={0};                                        //~5B12M~//~v6h7R~
    int deldirsw;                                               //~5B19I~
    int filectr,rc;                                             //~5B19R~
    UINT parmwildf[2];  //parm to wild func                        //~v281I~
    int wildsw;                                                    //~v281I~
#ifdef FTPSUPP                                                     //~v5amI~
	int ftpfilectr;                                                //~v5amI~
//  long ftpfilesize;                                              //~v5k0R~
    FILESZT ftpfilesize;                                           //~v5k0R~
    int pathlen;                                                   //~v5cpI~
    UCHAR rpath[_MAX_PATH];                                        //~v5cpI~
    PUFTPHOST puftph;                                              //~v5jdR~
#endif                                                             //~v5amI~
#ifdef UTF8SUPPH                                                   //~v62aR~
	int slinksw=0;                                                 //~v62aR~
#endif                                                             //~v62aR~
#ifdef UNX                                                         //~v6b1I~
    FILEFINDBUF3 fstat3_wild;                                      //~v6b1R~
    int swwildname=0;                                              //~v6b1I~
#endif                                                             //~v6b1I~
    UCHAR fpathrename[_MAX_PATH];                                  //~v6H1I~
    int optlongname=0;                                             //~v6H1I~
//********************                                          //~5B12M~
    Sxdelsize=0;                                                   //~v195I~
    Sxdelopt=Popt;                                              //~5B14I~
  	if (Ppprocctr)                                                 //~v5apI~
    	*Ppprocctr=0;       //processed err ctr                    //~v5apI~
  	if (Ppdelctr)                                                  //~v5apI~
    	*Ppdelctr=0;        //deleted ctr                          //~v5apI~
  	if (Ppronlyctr)                                                //~v5apI~
    	*Ppronlyctr=0;  //read only err ctr                        //~v5apI~
    Sxdelfctr=Sxdelrctr=Sxdeldctr=0;                            //~v010I~
    Sxdellongnamectr=0;                                            //~v6H1I~
    ufile3xdeleteinit(Pfile,Pattrmask,Popt,&Sxdelfctr,&Sxdelrctr,&Sxdeldctr,&Sxdellongnamectr,&Sxdelsize);//~v6H8I~
#ifdef UNX                                                         //~v6b1I~
	Sxdelwctr=0;   //wildname file ctr,at ronlychk                 //~v6b1I~
#endif                                                             //~v6b1I~
    deldirsw=((Pattrmask==UXDELDIR) && !(Popt & UXDELRONLYCHK));//~v010R~
    Pattrmask=Pattrmask & FILE_ALL;     //drop invalid bit      //~5B12M~
#ifdef UTF8SUPPH                                                   //~v62aM~
    #ifdef FTPSUPP                                                 //~v62aM~
        Pattrmask|=FILE_SLINK;  //del slink to dir                 //~v62aM~
    #endif                                                         //~v62aM~
#endif                                                             //~v62aM~
    if (uftpisremote(fpath,&puftph))                               //~v6H6I~
    {                                                              //~v6H6I~
    	if (!ufullpath(fpath,Pfile,FTP_MAXPATH))                   //~v6H6R~
        	return -1;                                             //~v6H6I~
    }                                                              //~v6H6I~
    else                                                           //~v6H6I~
    if (!ufullpath(fpath,Pfile,_MAX_PATH))                         //~v5d7R~
        return -1;                                              //~5B12M~
#ifdef FTPSUPP                                                     //~v5jdI~
    if (uftpisremote(fpath,&puftph))                               //~v5jdI~
    	if (UFTPHISTSO(puftph))                                    //~v5jdI~
			return u3270xdelete(puftph,fpath,Popt,Ppprocctr,Ppronlyctr,Ppdelctr);//~v5jdR~
#endif                                                             //~v5jdI~
//  if (ROOTDIR(fullpath))  //dosfindfirst faile if root           //~v55cR~
    if (ROOTDIR2(fpath))  //dosfindfirst faile if root             //~v5d7R~
        return ufileroot(fpath,-1);                                //~v5d7R~
    wildsw=(WILDCARD(fpath)!=0);         //source wild card        //~v5d7R~
#ifdef UNX                                                         //~v6b1I~
    if (wildsw)                                                    //~v6b1I~
    {                                                              //~v6b1I~
      	if (!uftpisremote(fpath,0))                                //~v6b1I~
      		if (!ufstat_wild(fpath,&fstat3_wild))//wildname file/dir exists//~v6b1R~
            {                                                      //~v6b1I~
            	wildsw=0;                                          //~v6b1I~
                swwildname=1;                                      //~v6b1I~
            }                                                      //~v6b1I~
    }                                                              //~v6b1I~
#endif                                                             //~v6b1I~
#ifdef FTPSUPP                                                     //~v5cpI~
    if (wildsw)                                                    //~v5cpI~
    {                                                              //~v5cpI~
#ifdef W32                                                         //~v5cpI~
      if (uftpisremote(fpath,0))                                   //~v5d7R~
      {                                                            //~v5cpI~
#endif                                                             //~v5cpI~
        pathlen=PATHLEN(fpath);                                    //~v5d7R~
        memcpy(rpath,fpath,(UINT)pathlen);                         //~v5d7R~
        *(rpath+pathlen)=0;                                        //~v5cpI~
        if (ROOTDIR3(rpath))//root wildcard                        //~v5cpI~
        {                                                          //~v5cpI~
#ifdef UNX                                                         //~v5feI~
          if (!MDOSDISK(rpath))                                    //~v5feI~
          {                                                        //~v5feI~
#endif                                                             //~v5feI~
		    uerrmsg("Delete one by one for object on unix root dir",//~v5cpI~
        	        "unixのルートDirのオブジェクトは一つ一つ削除してください");//~v5cpI~
        	return 4;                                              //~v5cpI~
#ifdef UNX                                                         //~v5feI~
          }                                                        //~v5feI~
#endif                                                             //~v5feI~
        }                                                          //~v5cpI~
#ifdef W32                                                         //~v5cpI~
      }                                                            //~v5cpI~
#endif                                                             //~v5cpI~
    }                                                              //~v5cpI~
#endif                                                             //~v5cpI~
//*source exist chk for not found err apirc of target           //~5B12M~
#ifdef UTF8SUPPH                                                   //~v62aR~
  #if defined(UNX) || defined(FTPSUPP)	                           //~v62aR~
    if (!wildsw)                                                   //~v62aR~
    {                                                              //~v62aR~
#ifdef UNX                                                         //~v6b1I~
      if (swwildname)                                              //~v6b1I~
        memcpy(&fstat3,&fstat3_wild,sizeof(fstat3));               //~v6b1R~
      else                                                         //~v6b1I~
#endif                                                             //~v6b1I~
        if (ufstat(fpath,&fstat3))                                 //~v62aR~
        {                                                          //~v62aR~
            if (!(Sxdelopt & UXDELNONOTFMSG))//skip not found msg  //~v62aR~
                ufilenotfound(fpath,-1);                           //~v62aR~
        	return -1;                                             //~v62aI~
        }                                                          //~v62aR~
        slinksw=FILE_ISSLINK(fstat3.attrFile);                     //~v62aR~
    }                                                              //~v62aR~
  #endif                                                           //~v62aR~
#ifdef UNX                                                         //~v6b1I~
 if (!swwildname)                                                  //~v6b1I~
#endif                                                             //~v6b1I~
 if (!slinksw)                                                     //~v62aR~
#endif                                                             //~v62aM~
 {                                                                 //~v62aR~
  if (Sxdelopt & UXDELNONOTFMSG)//skip not found msg               //~v55dI~
  {                                                                //~v55dI~
    if (udosfindfirstnomsg(fpath,0,Pattrmask|FILE_DIRECTORY,&fstat3))//~v5d7R~
        return -1;                                                 //~v55dI~
  }                                                                //~v55dI~
  else                                                             //~v55dI~
    if (udosfindfirst(fpath,0,Pattrmask|FILE_DIRECTORY,&fstat3))   //~v5d7R~
        return -1;                                              //~5B12M~
 }//!slink                                                         //~v62aR~
    if (!(Popt & UXDELRONLYCHK))                                //~v010R~
        if (ufilecdirchk(fpath))                                   //~v5d7R~
            return ufiledelpath(fpath,-1);                         //~v5d7R~
//  if (WILDCARD(fullpath))         //source wild card             //~v281R~
//  wildsw=(WILDCARD(fpath)!=0);         //source wild card        //~v5d7R~
    if (!wildsw)                                                   //~v281I~
#ifdef UTF8SUPPH                                                   //~v62aI~
        if (FILE_ISNOSLINKDIR(fstat3.attrFile))   //directory      //~v62aR~
#else                                                              //~v62aI~
        if (fstat3.attrFile & FILE_DIRECTORY)   //directory        //~v281I~
#endif                                                             //~v62aI~
            if (Popt & UXDELCONFEACH)   //each confirm in wildfunc //~v281I~
                if (!ROOTDIR(fpath)) //not root                    //~v5d7R~
                {                                                  //~v281I~
                    wildsw=1;                                      //~v281I~
#ifdef FTPSUPP                                                     //~v5akI~
				  if (fstat3.attrFile & FILE_REMOTE)               //~v5akI~
                    strcat(fpath,FTP_DIR_SEPS FTP_DIR_ALLMEMB); //\*. or *,/*//~v5d7R~
                  else                                             //~v5akI~
#endif                                                             //~v5akI~
                  {                                                //~v6H1I~
                   if (strlen(fpath)+sizeof(DIR_SEPS DIR_ALLMEMB)>=_MAX_PATH)//~v6H1I~
					optlongname=UWFO_LONGWILD;         //ovf when "\*" was appended//~v6H1I~
                   else                                            //~v6H1I~
                    strcat(fpath,DIR_SEPS DIR_ALLMEMB); //\*. or *,/*//~v5d7R~
                  }                                                //~v6H1I~
                }                                                  //~v281I~
    if (wildsw)                     //source wild card             //~v281I~
    {                                                              //~v281I~
        if (Popt & UXDELCONFEACH)   //each confirm in wildfunc     //~v281I~
//          uerrmsg("Reply to each Yes/No/All/End",                //~v281I~//~v6q0R~
//                  "各々 Yes/No/All(以降全て)/End(終了)を入力してください");//~v281I~//~v6q0R~
            uerrmsg("Reply to each Yes/No/All/End, or Esc key to break.",//~v6q0I~
                    "各々 Yes/No/All(以降全て)/End(終了)を入力してください(Escキーで中断) ");//~v6q0R~
        parmwildf[0]=Pattrmask;                                    //~v281I~
        parmwildf[1]=(UINT)(Popt & UXDELCONFEACH);  //each confirm in wildfunc//~v281R~
#ifdef FTPSUPP                                                     //~v5amI~
	  	if (fstat3.attrFile & FILE_REMOTE)                         //~v5amI~
        {                                                          //~v5amI~
        	rc=                                                    //~v5d7I~
        	uftpwildfunc2(Sxdelopt,fpath,Pattrmask,uftpwildxdel,parmwildf,&ftpfilectr,&ftpfilesize);//~v5d7R~
            Sxdelfctr+=ftpfilectr;                                 //~v5amI~
//  printf("uxdelete remotefile delfctr=%d %s\n",Sxdelfctr,fpath); //@@@@test//~v6H9R~
            Sxdeldctr+=ftpfilectr;                                 //~v5amR~
            Sxdelsize+=ftpfilesize;                                //~v5amI~
        }                                                          //~v5amI~
        else                                                       //~v5fcI~
#endif                                                             //~v5amI~
        {                                                          //~v6H1I~
//      rc=uwildfunc(0,         //bypass ea data                //~v010R~//~v6q0R~
      if (optlongname)                                             //~v6H1I~
      {                                                            //~v6H1I~
        rc=UWFRC_LONGNAME;        //over _MAX_PATH                 //~v6H1I~
        Sxdellongnamectr++;                                        //~v6H1I~
      }                                                            //~v6H1I~
      else                                                         //~v6H1I~
        rc=uwildfunc(UWFO_DELETE,//bypass ea data,use alias for wildcard name member//~v6q0I~
//                  fullpath,Pattrmask,ufilewildxdel,&Pattrmask,&filectr);//~v281R~
                    fpath,Pattrmask,ufilewildxdel,parmwildf,&filectr);//~v5d7R~
        if (rc & UWFRC_LONGNAME)        //over _MAX_PATH           //~v6H1I~
        {                                                          //~v6H1I~
//  		if (!(Popt & UXDELRONLYCHK))                           //~v6H1I~//~v6HoR~
 	  		if (!(Popt & UXDELRONLYCHK))                           //~v6HtI~
	    		if (Popt & UXDELFORCE)                             //~v6H1I~
    	    		rc=uwildfunc_LongName(UWFO_DELETE|optlongname,fpath,fstat3.attrFile,Pattrmask,ufilewildxdel,parmwildf,/*&filectr,*/fpathrename);//~v6H1R~
        }                                                          //~v6H1I~
        }                                                          //~v6H1I~
    }                                                              //~v281I~
    else                                                        //~v010I~
//  {                                                           //~v010R~
//      if (!(rc=uxdelsub(fullpath,(UCHAR)fstat3.attrFile,Pattrmask,1)))//~v010R~
//          if (deldirsw)                                       //~v010R~
//              if (UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))   //~v010R~
//                  if (!(rc=urmdir(fullpath)))                 //~v010R~
//                      if (Sxdelopt & UXDELMSG) //msg put option//~v010R~
//                          ufileddmsg(fullpath);               //~v010R~
//  }//not wild card                                            //~v010R~
//      rc=uxdelsub(fullpath,(UCHAR)fstat3.attrFile,Pattrmask,deldirsw);//~v195R~
//      rc=uxdelsub(fullpath,(UCHAR)fstat3.attrFile,Pattrmask,deldirsw,(long)fstat3.cbFile);//~v379R~
//      rc=uxdelsub(fpath,(ULONG)fstat3.attrFile,Pattrmask,deldirsw,(long)fstat3.cbFile);//~v5k0R~
	  if (fstat3.attrFile & FILE_REMOTE)                           //~v6H6I~
        rc=uxdelsubftp(fpath,(ULONG)fstat3.attrFile,Pattrmask,deldirsw,fstat3.cbFile);//~v6H6I~
      else                                                         //~v6H6I~
        rc=uxdelsub(fpath,(ULONG)fstat3.attrFile,Pattrmask,deldirsw,fstat3.cbFile);//~v5k0R~
  if (Ppprocctr)                                                   //~v5apI~
    *Ppprocctr=Sxdelfctr;       //processed err ctr             //~v010R~
//  printf("uxdelete delfctr=%d %s\n",Sxdelfctr,Pfile); //@@@@test //~v6H9R~
  if (Ppdelctr)                                                    //~v5apR~
    *Ppdelctr=Sxdeldctr;        //deleted ctr                   //~v010R~
  if (Ppronlyctr)                                                  //~v5apI~
    *Ppronlyctr=Sxdelrctr;  //read only err ctr                 //~v010R~
    return rc;                                                  //~5B19I~
}//uxdelete                                                     //~5B12M~
                                                                //~5B12M~
//****************************************************************//~5B12M~
//!ufilewildxdel                                                //~5B12M~
//* delete by wild card                                         //~5B12M~
//*parm1:filename thru wildfunc                                 //~5B12M~
//*parm2:dirlist ptr thru wildfunc                              //~5B12M~
//*parm3:parm thru uwildfunc(Pattrmask parm of xdelete)         //~5B12M~
//*retrn:rc                                                     //~5B12M~
//****************************************************************//~5B12M~
int ufilewildxdel(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~5B12M~
{                                                               //~5B12M~
    unsigned attrmask;                                          //~5B12M~
    int      eachconfsw;                                           //~v281I~
    int      reply;                                                //~v281I~
    char datewk[12];                                               //~v294I~
    char timewk[8];                                                //~v294I~
//#ifdef W32                                                       //~v6H9R~
//  char wkfpath[_MAX_PATH*2];                                     //~v6q0R~//~v6H9R~
    char wkfpath[_MAX_PATH2_LONG];                                 //~v6H9I~
//#endif                                                           //~v6H9R~
    char *pfpath;                                                  //~v6q0I~
//********************                                          //~5B12M~
    UTRACEP("ufilewildxdel fpath=%s,dirlist=%s\n",Pfullpath,Ppudirlist->name);//~v6q0I~
    eachconfsw=*((int*)Pparm+1);    //2nd word=each conf           //~v281I~
#ifndef ARMXXE                                                     //~v62aI~
    if (eachconfsw)                                                //~v281I~
        for (;;)                                                   //~v281I~
        {                                                          //~v281I~
            ufdateedit(Ppudirlist->date,"YY-MM-DD",datewk);        //~v294I~
            uftimeedit(Ppudirlist->time,"HH:MM",timewk);           //~v294I~
//          printf("DEL  %-26s ? ",Pfullpath);                     //~v294R~
#ifdef W32                                                         //~v6q0I~
    	  if (FILE_IS_WILDNAME(Ppudirlist->attr))                  //~v6q0R~
          {                                                        //~v6q0I~
          	sprintf(wkfpath,"%s (alias:%s)",Pfullpath,Ppudirlist->alias);//~v6q0R~
            printf("DEL %s %s %-26s ? ",datewk,timewk,wkfpath);    //~v6q0I~
          }                                                        //~v6q0I~
          else                                                     //~v6q0I~
#endif                                                             //~v6q0I~
#ifdef W32UNICODE                                                  //~v6uaI~
            uerrfprintfutf(0,stdout,"DEL %s %s %-26s ? ",0,        //~v6uaR~
            					datewk,timewk,Pfullpath);          //~v6uaI~
#else                                                              //~v6uaI~
            printf("DEL %s %s %-26s ? ",datewk,timewk,Pfullpath);  //~v294I~
#endif                                                             //~v6uaI~
            fflush(stdout);                                        //~v294I~
#ifdef OS2                                                         //~v281I~
            reply=_getche();                                       //~v281I~
#else                                                              //~v281I~
            reply=getche();                                        //~v281R~
#endif                                                             //~v281I~
            printf("\n");                                          //~v281I~
            if (reply=='Y' || reply=='y')                          //~v281I~
                break;                                             //~v281R~
            if (reply=='N' || reply=='n')                          //~v281I~
            {                                                      //~v281I~
                Sxdelfctr++;        //processed ctr(contain skip ctr)//~v281I~
                return 0;                                          //~v281I~
            }                                                      //~v281I~
            if (reply=='A' || reply=='a')                          //~v281I~
            {                                                      //~v281I~
                *((int*)Pparm+1)=0; //clear each conf req parm     //~v281I~
                break;                                             //~v281I~
            }                                                      //~v281I~
            if (reply=='E' || reply=='e' || reply==0x1b)    //exit //~v281R~
            {                                                      //~v281I~
                Sxddendsw=1;        //Select cancelend sw          //~v281I~
                uerrmsg("Canceled",                                //~v281I~
                        "以降取消");                               //~v281I~
                return 1;                                          //~v281I~
            }                                                      //~v281I~
        }                                                          //~v281I~
#endif //ARMXXE                                                    //~v62aI~
#ifdef W32                                                         //~v6q0I~
    if (FILE_IS_WILDNAME(Ppudirlist->attr))                        //~v6q0I~
    {                                                              //~v6q0I~
    	strcpy(wkfpath,Pfullpath);                                 //~v6q0R~
        strcpy(wkfpath+strlen(Pfullpath)-strlen(Ppudirlist->name),Ppudirlist->alias);//~v6q0R~
        pfpath=wkfpath;                                            //~v6q0I~
    }                                                              //~v6q0I~
    else                                                           //~v6q0I~
#endif                                                             //~v6q0M~
	{                                                              //~v6H9I~
//      pfpath=Pfullpath;                                          //~v6q0I~//~v6H9R~
    	strcpy(wkfpath,Pfullpath);                                 //~v6H9I~
        pfpath=wkfpath;                                            //~v6H9I~
    }                                                              //~v6H9I~
    UTRACEP("ufilewildxdel fpath=%s\n",pfpath);                    //~v6q0I~
    attrmask=*(unsigned*)Pparm;                                 //~5B12M~
//  return uxdelsub(Pfullpath,                                  //~5B12M~//~v6q0R~
    return uxdelsub(pfpath,                                        //~v6q0I~
//                  (UCHAR)Ppudirlist->attr,    //source attr      //~v379R~
                    (ULONG)Ppudirlist->attr,    //source attr      //~v379I~
                    attrmask,                                   //~5B19R~
                    1,                                             //~v195R~
//                  (long)Ppudirlist->size);                            //del dir//~v5k0R~
                    Ppudirlist->size);                            //del dir//~v5k0R~
}//ufilewildxdel                                                //~5B12M~
                                                                //~5B12M~
//****************************************************************//~5B12M~
//uxdelsub                                                      //~5B12M~
//* del file/dir                                                //~5B12M~
//*parm1:fullpath filename                                      //~5B12M~
//*parm2:file attr                                              //~5B12M~
//*parm3:attrmask                                               //~5B12M~
//*parm4:del dir sw                                             //~v010R~
//*parm5:file size                                                 //~v195R~
//*retrn:rc                                                     //~5B12M~
//****************************************************************//~5B12M~
//int uxdelsub(UCHAR *Pfile,UCHAR Pattr,unsigned Pattrmask,int Pdeldirsw,long Psize)//~v379R~
//int uxdelsub(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,long Psize)//~v5k0R~
int uxdelsub(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,FILESZT Psize)//~v5k0R~
{                                                               //~5B12M~
    int rc=0,filectr,ronlysw,skipsw;                              //~v010R~//~v6h7R~
    int dirnamelen;                                             //~5B12M~
//  UCHAR outattr;                                                 //~v327R~
//#ifdef UNX                                                       //~v59eR~
    #define ATTR_TYPE unsigned long                                //~v50bI~
    ULONG outattr;                                                 //~v327I~
//#else  //!UNX                                                    //~v59eR~
//    #define ATTR_TYPE unsigned char                              //~v59eR~
//    UCHAR outattr;                                               //~v59eR~
//#endif //!UNX                                                    //~v59eR~
//  long totsz;                                                    //~v5k0R~
    FILESZT totsz;                                                 //~v5k0R~
    int msgsw;                                                     //~v195I~
    UINT parmwildf[2];  //parm to wild func                        //~v281I~
#ifdef FTPSUPP                                                     //~v5amI~
	int ftpfilectr;                                                //~v5amI~
//  long ftpfilesize;                                              //~v5k0R~
    FILESZT ftpfilesize;                                           //~v5k0R~
#endif                                                             //~v5amI~
#ifdef UTF8SUPPH                                                   //~v62aI~
    int slinksw;                                                   //~v62aR~
#endif                                                             //~v62aI~
	int swrenamedeleted=0;                                         //~v6H1I~
	char fpathrename[_MAX_PATH]={0},*topdir;                       //~v6H1R~
    int swtoolong=0;                                               //~v6H1I~
    int svdelfctr,svdeldctr,deldctrinc;                            //~v6H9R~
#ifdef W32                                                         //~v6H9I~
	char fpathremove[_MAX_PATH_LONG];                              //~v6H9I~
#endif                                                             //~v6H9I~
//********************                                          //~5B12M~
//read only process                                             //~v010I~
    svdelfctr=Sxdelfctr; svdeldctr=Sxdeldctr;                      //~v6H9I~
    Sxdelfctr++;        //processed ctr(contain skip ctr)       //~v010M~
//  printf("uxdelsub delfctr=%d %s\n",Sxdelfctr,Pfile); //@@@@test //~v6H9R~
	UTRACEP("%s delfctr=%d,attr=%x,fnm=%s\n",UTT,Sxdelfctr,Pattr,Pfile);//~v6H1R~
#ifdef UTF8SUPPH                                                   //~v62aI~
    slinksw=FILE_ISSLINK(Pattr);                                   //~v62aR~
#endif                                                             //~v62aI~
    ronlysw=UCBITCHK(Pattr,FILE_READONLY);                      //~v010R~
#ifdef UNX                                                         //~v6b1I~
    if (Pattr & FILE_WILDNAME)                                     //~v6b1R~
        Sxdelwctr++;                                               //~v6b1I~
#endif                                                             //~v6b1I~
    if (ronlysw)                                                //~v010I~
    {                                                           //~v010I~
        Sxdelrctr++;                                            //~v010R~
        if (Sxdelopt & UXDELRONLYCHK) //readonly chk only       //~v010M~
        {                                                       //~v010I~
            if (Sxdelopt & UXDELFORCE) //contine req            //~v010R~
            {                                                   //~v010I~
                if (Sxdelopt & UXDELMSG) //msg put option       //~v010I~
                {                                                  //~v59eI~
#ifdef UTF8SUPPH                                                   //~v62aM~
                    if (slinksw)                                   //~v62aM~
                        ufilereadonly2(Pfile,'L');                 //~v62aM~
                    else                                           //~v62aM~
#endif                                                             //~v62aM~
                    if (UCBITCHK(Pattr,FILE_DIRECTORY)) //normal file//~v010I~
                        ufilereadonly2(Pfile,'D');              //~v010I~
                    else                                        //~v010I~
                        ufilereadonly2(Pfile,'F');              //~v010I~
                }//delmsg                                          //~v59eI~
            }                                                   //~v010I~
            else                                                //~v010I~
                return ufilereadonly(Pfile,-2); //rc=0          //~v010I~
        }                                                       //~v010I~
        else    //not check                                     //~v010I~
        {                                                       //~v010I~
            if (Sxdelopt & UXDELFORCE) //force del req          //~v010I~
            {                                                   //~v010I~
                if (rc=uattrib(Pfile,0,FILE_READONLY,&outattr),rc)  //reset ronly//~v010I~
                    return rc;                                  //~v010I~
                ronlysw=0;  //can be deletable                  //~v010I~
            }                                                   //~v010I~
            else                                                //~v010I~
                if (Sxdelopt & UXDELSKIPRONLY) //ignore read only//~v010R~
                {                                               //~v010I~
                    if (Sxdelopt & UXDELMSG) //msg put option   //~v010I~
                    {                                              //~v59eI~
#ifdef UTF8SUPPH                                                   //~v62aM~
                        if (slinksw)                               //~v62aM~
                            ufilereadonly2(Pfile,'L');             //~v62aM~
                        else                                       //~v62aM~
#endif                                                             //~v62aM~
                        if (UCBITCHK(Pattr,FILE_DIRECTORY)) //normal file//~v010I~
                            ufilereadonly2(Pfile,'D');          //~v010I~
                        else                                    //~v010I~
                            ufilereadonly2(Pfile,'F');          //~v010I~
                    }//delmsg                                      //~v59eI~
                }                                               //~v010I~
                else                                            //~v010I~
                    return ufilereadonly(Pfile,-2); //rc=0      //~v010I~
        }                                                       //~v010I~
    }//read only file/dir                                       //~v010I~
//*******                                                       //~v010R~
    skipsw=ronlysw | (Sxdelopt & UXDELRONLYCHK); //readonly chk only//~v010I~
#ifdef UTF8SUPPH                                                   //~v62aI~
    if (!FILE_ISNOSLINKDIR(Pattr)) //normal or slink file          //~v62aI~
#else                                                              //~v62aI~
    if (!UCBITCHK(Pattr,FILE_DIRECTORY)) //normal file          //~5B12M~
#endif                                                             //~v62aI~
    {                                                              //~v59eI~
        if (skipsw)         //bypass                            //~v010R~
            return 0;                                           //~v010I~
        else                                                    //~v010I~
        {                                                       //~v010I~
            msgsw=(Sxdelopt & UXDELMSG); //msg put option save     //~v195I~
            Sxdelopt&=~UXDELMSG; //msg put option clear            //~v195I~
#ifdef W32                                                         //~v6k4I~
          if (FILE_MODEISNTFS_MOUNTVOL(Pattr))                     //~v6k4R~
	        rc=urmdir(Pfile);                                      //~v6k4I~
          else                                                     //~v6k4I~
          if (FILE_MODEISNTFS_JUNCTION(Pattr))                     //~v6k4I~
	        rc=urmdir(Pfile);                                      //~v6k4I~
          else                                                     //~v6k4I~
    	  if (FILE_ISSLINKDIR(Pattr))                              //~v6H6I~
	        rc=urmdir(Pfile);                                      //~v6H6I~
          else                                                     //~v6H6I~
          {                                                        //~v6H9I~
//          rc=uremoveWLong(0,Pfile);	//support longname         //~v6H9R~
          	strcpy(fpathremove,Pfile);                             //~v6H9R~
            rc=uremove(fpathremove); //support longname            //~v6H9R~
          }                                                        //~v6H9I~
#endif                                                             //~v6k4I~
#ifndef W32                                                        //~v6H9I~
            rc=uremove(Pfile);                                  //~v010R~
#endif                                                             //~v6H9I~
            Sxdelopt|=msgsw; //msg put option restore              //~v195I~
            if (!rc)                                            //~v010I~
            {                                                      //~v195I~
                Sxdelsize+=Psize;                                  //~v195R~
                Sxdeldctr++;    //deleted ctr                   //~v010I~
                if (msgsw) //msg put option                        //~v195I~
                {                                                  //~v62aI~
                 if (Sxdelopt & UXDELQUIET)                        //~v6G7I~
                 {                                                 //~v6G7I~
                 	ufile2quietmsg(0,Pfile);                       //~v6G7I~
                 }                                                 //~v6G7I~
                 else                                              //~v6G7I~
                 {                                                 //~v6G7I~
#ifdef UTF8SUPPH                                                   //~v62aM~
                  if (slinksw)                                     //~v62aI~
                    ufiledeleted(Pfile,'L',Psize,(ATTR_TYPE)Pattr);//size=-1  mean no display size/attr//~v62aI~
                  else                                             //~v62aI~
#endif                                                             //~v62aI~
                    ufiledeleted(Pfile,'F',Psize,(ATTR_TYPE)Pattr);//size=-1  mean no display size/attr//~v50bR~
                 }                                                 //~v6G7I~
                }                                                  //~v62aI~
            }                                                      //~v195I~
            return rc;                                          //~v010I~
        }                                                       //~v010I~
    }//normal file                                                 //~v59eI~
//del dir                                                       //~5B12M~
    dirnamelen=(int)strlen(Pfile);                              //~5B12M~
#ifdef FTPSUPP                                                     //~v5akI~
  if (Pattr & FILE_REMOTE)                                         //~v5akI~
  {                                                                //~v6H1I~
   if (dirnamelen+(int)sizeof(FTP_DIR_SEPS FTP_DIR_ALLMEMB)>=_MAX_PATH)//~v6H1I~
   {                                                               //~v6HtI~
	ufileTooLongFullpathName2(0,Pfile,FTP_DIR_SEPS FTP_DIR_ALLMEMB);//~v6HtI~
    swtoolong=1;                                                   //~v6H1I~
   }                                                               //~v6HtI~
   else                                                            //~v6H1I~
    strcat(Pfile,FTP_DIR_SEPS FTP_DIR_ALLMEMB); //\*. or *,/*      //~v5akR~
  }                                                                //~v6H1I~
  else                                                             //~v5akI~
#endif                                                             //~v5akI~
  {                                                                //~v6H1I~
// if (dirnamelen+(int)sizeof(DIR_SEPS DIR_ALLMEMB)>=_MAX_PATH)//\*.* or /*//~v6H1R~//~v6H9R~
   if (dirnamelen+(int)sizeof(DIR_SEPS DIR_ALLMEMB)>=_MAX_PATH_LONG)//\*.* or /*//~v6H9I~
   {                                                               //~v6HtI~
    swtoolong=1;                                                   //~v6H1I~
	ufileTooLongFullpathName2(0,Pfile,DIR_SEPS DIR_ALLMEMB);       //~v6HtI~
   }                                                               //~v6HtI~
   else                                                            //~v6H1I~
    strcat(Pfile,DIR_SEPS DIR_ALLMEMB);//\*.* or /*                //~v327R~
  }                                                                //~v6H1I~
//  if (rc=uxdelete(Pfile,Pattrmask),rc)                        //~5B12I~
    totsz=Sxdelsize;                                               //~v195R~
    parmwildf[0]=Pattrmask;                                        //~v281I~
    parmwildf[1]=0;  //no confirm for 2nd level                    //~v281I~
#ifdef FTPSUPP                                                     //~v5amI~
  	if (Pattr & FILE_REMOTE)                                       //~v5amI~
    {                                                              //~v5amI~
        if (swtoolong)                                             //~v6H1I~
            return UWFRC_LONGNAME;        //@@@@FIXME not tested   //~v6H1I~
        rc=                                                        //~v5d7I~
    	uftpwildfunc2(Sxdelopt,Pfile,Pattrmask,uftpwildxdel,parmwildf,&ftpfilectr,&ftpfilesize);//~v5apR~
        if (rc)                                                    //~v5d7I~
    	    return rc;                                             //~v5d7I~
        Sxdelfctr+=ftpfilectr;                                     //~v5amI~
        Sxdeldctr+=ftpfilectr;                                     //~v5amR~
        Sxdelsize+=ftpfilesize;                                    //~v5amI~
        UTRACEP("%s:delfctr=%d deldctr=%d,dellctr=%d\n",UTT,Sxdelfctr,Sxdeldctr,Sxdellongnamectr);//~v6H1R~
    }                                                              //~v5amI~
//  else                                    //~v5fcI~   .          //~v5fpR~
#endif //FTPSUPP                                                   //~v62aI~
#ifdef UTF8SUPPH                                                   //~v62bI~
	#ifdef FTPSUPP                                                 //~v62aI~
//if (!(Pattr & FILE_REMOTE) || FILE_ISNOSLINKDIR(Pattrmask))       //~v62aR~//~v6H8R~
 if (!(Pattr & FILE_REMOTE) || FILE_ISNOSLINKDIR(Pattr))           //~v6H8I~
	#endif                                                         //~v62aI~
#endif                                                             //~v62aM~
 {                                                                 //~v62bI~
  if (swtoolong)                                                   //~v6H1I~
  {                                                                //~v6H1I~
    Sxdellongnamectr++;                                            //~v6H1I~
    rc=UWFRC_LONGNAME;        //@@@@FIXME not tested               //~v6H1I~
  }                                                                //~v6H1I~
  else                                                             //~v6H1I~
  {                                                                //~v6H1I~
//  if (rc=uwildfunc(0,         //bypass ea data                //~5B12I~//~v6q0R~
    if (rc=uwildfunc(UWFO_DELETE,         //bypass ea data,use alias for wildcardmember//~v6q0I~
//                  Pfile,Pattrmask,ufilewildxdel,&Pattrmask,&filectr),rc)//~v281R~
                    Pfile,Pattrmask,ufilewildxdel,parmwildf,&filectr),rc)//~v281I~
#ifdef UTF8SUPPH                                                   //~v62bI~
	#ifdef FTPSUPP                                                 //~v62bI~
  	  if (Pattr & FILE_REMOTE)	//file was deleted by uftpwildfunc2//~v62bI~
	#endif                                                         //~v62bR~
#endif                                                             //~v62bI~
        return rc;                                              //~5B12M~
  }                                                                //~v6H1I~
      if (rc & UWFRC_LONGNAME)        //over _MAX_PATH             //~v6H1I~
      {                                                            //~v6H1I~
        if (Sxdelopt & UXDELFORCE)                                 //~v6H1I~
//          if (!(Sxdelopt & UXDELRONLYCHK)) //readonly chk only   //~v6H1I~//~v6HoR~
            if (!(Sxdelopt & UXDELRONLYCHK)) //readonly chk only   //~v6HtI~
    			if (Pdeldirsw)                                     //~v6H1I~
        	    {                                                  //~v6H1I~
//                  printf("%s:before call wildLong Sxdelfctr=%d,Sxdeldctr=%d\n",UTT,Sxdelfctr,Sxdeldctr);//~v6H9I~//~v6HoR~
                	deldctrinc=Sxdeldctr-svdeldctr;                //~v6H9I~
				    Sxdelfctr=svdelfctr+deldctrinc;                //~v6H9I~
//                  printf("%s:reset deletedctr=%d,Sxdelfctr=%d\n",UTT,deldctrinc,Sxdeldctr);//~v6H9R~//~v6HoR~
        			rc=uwildfunc_LongName(UWFO_DELETE,             //~v6H1I~
                	    Pfile,Pattr,Pattrmask,ufilewildxdel,parmwildf,/*&filectr,*/fpathrename);//~v6H1R~
        			UTRACEP("%s:dellfctr=%d\n",UTT,Sxdelfctr);     //~v6H1R~
                	if (!rc)                                       //~v6H1I~
                    {                                              //~v6H1I~
                    	swrenamedeleted=1;                         //~v6H1I~
                    }                                              //~v6H1I~
            	}                                                  //~v6H1I~
      }                                                            //~v6H1I~
 }                                                                 //~v62bI~
    totsz=Sxdelsize-totsz;  //this dir size                        //~v195R~
    *(Pfile+dirnamelen)=0;  //drop \*.*                         //~5B12M~
  if (!swrenamedeleted)                                            //~v6H1R~
  {                                                                //~v6H1R~
		topdir=Pfile;                                              //~v6H1R~
                                                                   //~v6H1I~
    if (Pdeldirsw)                                              //~v010R~
    {                                                           //~v010I~
        if (skipsw)         //bypass                            //~v010I~
            return 0;                                           //~v010I~
//      if (!(rc=urmdir(Pfile)))                                   //~v6H1R~
//#ifdef W32                                                       //~v6H9R~
//        if (!(rc=urmdirWW(0,topdir)))                            //~v6H9R~
//#else                                                            //~v6H9R~
        if (!(rc=urmdir(topdir)))                                  //~v6H1I~
//#endif                                                           //~v6H9R~
        {                                                       //~v010I~
            Sxdeldctr++;    //deleted ctr                       //~v010I~
            if (Sxdelopt & UXDELMSG) //msg put option           //~v010I~
            {                                                      //~v6G7I~
              if (Sxdelopt & UXDELQUIET)                           //~v6G7I~
              {                                                    //~v6G7I~
//            	ufile2quietmsg(0,Pfile);                           //~v6H1R~
              	ufile2quietmsg(0,topdir);                          //~v6H1I~
              }                                                    //~v6G7I~
              else                                                 //~v6G7I~
              {                                                    //~v6G7I~
//              ufiledeleted(Pfile,'D');                           //~v195R~
//              ufiledeleted(Pfile,'D',totsz,(ATTR_TYPE)Pattr);    //~v6H1R~
                ufiledeleted(topdir,'D',totsz,(ATTR_TYPE)Pattr);   //~v6H1I~
              }                                                    //~v6G7I~
            }                                                      //~v6G7I~
        }                                                       //~v010I~
        else                                                    //~v010I~
            if (Sxdelopt & UXDELSKIPRONLY) //ignore read only   //~v010I~
                rc=0;   //contine(may contain read only)        //~v010I~
    }                                                           //~v010I~
  }                                                                //~v6H1I~
    return rc;                                                  //~5B14I~
}//uxdelsub                                                     //~5B12M~
//**************************************************************** //~v5amI~
//*uremovenomsg                                                    //~v5amI~
//* no deleted msg;for the case ftp temp file del for xdd width msg operetion//~v5amI~
//*retrn:rc(=errno)                                                //~v5amI~
//**************************************************************** //~v5amI~
int uremovenomsg(UCHAR *Pfilename)                                 //~v5amI~
{                                                                  //~v5amI~
	int optsv,rc;                                                  //~v5amI~
//*********************                                            //~v5amI~
   	optsv=Sxdelopt;                                                //~v5amI~
    Sxdelopt=0;                                                    //~v5amI~
	rc=uremove(Pfilename);                                         //~v5amI~
   	Sxdelopt=optsv;                                                //~v5amI~
    return rc;                                                     //~v5amI~
}//uremovenomsg                                                    //~v5amI~
//#ifdef W32                                                       //~v6H9R~
////****************************************************************//~v6H9R~
////uremove longname support                                       //~v6H9R~
////****************************************************************//~v6H9R~
//static int Sremovelong;                                          //~v6H9R~
//int uremoveWLong(int Popt,UCHAR *Pfilename)                      //~v6H9R~
//{                                                                //~v6H9R~
//    int optsv,rc;                                                //~v6H9R~
////*********************                                          //~v6H9R~
//    optsv=Sxdelopt;                                              //~v6H9R~
//    if (Popt & URWLO_NOMSG)                                      //~v6H9R~
//    {                                                            //~v6H9R~
//        Sxdelopt&=~UXDELMSG;                                     //~v6H9R~
//    }                                                            //~v6H9R~
//    Sremovelong=1;                                               //~v6H9R~
//    rc=uremove(Pfilename);                                       //~v6H9R~
//    Sremovelong=0;                                               //~v6H9R~
//    Sxdelopt=optsv;                                              //~v6H9R~
//    return rc;                                                   //~v6H9R~
//}//uremoveWLong                                                  //~v6H9R~
//#endif                                                           //~v6H9R~
//****************************************************************//~5825I~
//*uremove                                                      //~5825R~
//* delete file,cannot del dir                                  //~5826R~
//*Win:longname support by remove(uremoveW)                        //~v6H9I~
//* errno of dir del req is ENOENT for dos/v 6.3,EACCE for dos/v on os///~5826I~
//* so return EACCES(both DOS) or EACCESS(os/2)                 //~5826I~
//*parm1:file name                                              //~5825R~
//*retrn:rc(=errno)                                             //~5825R~
//****************************************************************//~5825I~
int uremove(UCHAR *Pfilename)                                   //~5825R~
{                                                               //~5825I~
    int rc;                                                     //~5826R~
#ifdef FTPSUPP                                                     //~v59pI~
    int ftpopt;                                                    //~v59pR~
    PUFTPHOST puftph;                                              //~v5afI~
#endif //FTP                                                       //~v59pI~
#ifdef UNX  //!!!!!!!!!!!                                          //~v327I~
    int mdossw;                                                    //~v556I~
#else //!UNX//!!!!!!!!!!!                                          //~v327I~
	int rc2;                                                       //~v6H9I~
    FILEFINDBUF3 fstat3;                                        //~5825I~
#endif //!UNX//!!!!!!!!!!!                                         //~v327I~
//********************                                          //~5825I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfilename,&puftph))	//ftp filename         //~v5afR~
    {                                                              //~v59pI~
    	ftpopt=Sxdelopt;                                           //~v59pI~
  		return uftpremove(puftph,ftpopt,Pfilename);                //~v5afR~
    }                                                              //~v59pI~
#endif //FTP                                                       //~v59pI~
#ifdef UNX  //!!!!!!!!!!!                                          //~v327I~
//  if (!unlink(Pfilename))                                        //~v556R~
  	mdossw=MDOSDISKOK(Pfilename);	    //contain drive id         //~v556R~
    if (mdossw)                                                    //~v556I~
        rc=uremove_mdos(Pfilename);                                //~v556R~
    else                                                           //~v556I~
		rc=unlink(Pfilename);   //-1 if err                        //~v556R~
//  if (!rc)                //no err                               //~v59pR~
#else //!UNX//!!!!!!!!!!!                                          //~v327I~
//  if (!remove(Pfilename))                                        //~v59pR~
    rc=remove(Pfilename);                                          //~v59pI~
#endif //!UNX//!!!!!!!!!!!                                         //~v327M~
    if (!rc)                //no err                               //~v59pI~
    {                                                           //~5B14I~
        if (Sxdelopt & UXDELMSG) //msg put option               //~v010R~
//          ufiledeleted(Pfilename,'F');                           //~v195R~
//          ufiledeleted(Pfilename,'F',-1,0);//size=-1  mean no display size/attr//~v5k0R~
            ufiledeleted(Pfilename,'F',(FILESZT)(-1),0);//size=-1  mean no display size/attr//~v5k0R~
        return 0;                                               //~5825I~
    }                                                           //~5B14I~
                                                                //~5826I~
    rc=errno;       //save original errno;                      //~5826I~
#ifdef UNX  //!!!!!!!!!!!                                          //~v327I~
#else //!UNX//!!!!!!!!!!!                                          //~v327I~
//  if (!ufstat(Pfilename,&fstat3)                              //~5909R~//~v6H9R~
//  if (Sremovelong)                                               //~v6H9R~
//    rc2=ufstatWLong(0,Pfilename,0/*buffsz=_MAX_PATH_LONG*/,&fstat3);//~v6H9R~
//  else                                                           //~v6H9R~
    rc2=ufstat(Pfilename,&fstat3);                                 //~v6H9I~
    if (!rc2                                                       //~v6H9R~
    && UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))                //~5909R~
    {                                                           //~5826I~
//#ifdef DOS                                                       //~v014R~
        rc=EACCES;                                              //~5826R~
//#else                                                            //~v014R~
//      rc=EACCESS;                                                //~v014R~
//#endif                                                           //~v014R~
    }                                                           //~5826I~
#endif //!UNX//!!!!!!!!!!!                                         //~v327I~
    if (Gufile_nomsg)   //nomsg option                          //~5826I~
        return rc;                                              //~5826I~
                                                                //~5826I~
    switch(rc)                                                  //~5826R~
    {                                                           //~5825I~
#ifdef UNX  //!!!!!!!!!!!                                          //~v327I~
    case EPERM:                                                    //~v367I~
    case EACCES:                                                   //~v327I~
    	return ufilenopermission("unlink",Pfilename,rc);           //~v366R~
    case ENOTDIR:                                                  //~v327I~
    case ENOENT:                                                   //~v327I~
        return ufilenotfound(Pfilename,rc);                        //~v327I~
//    case EPERM:                                                  //~v367R~
//        uerrmsg("%s is Directory",                               //~v367R~
//                    "%s はディレクトリーです",                   //~v367R~
//                    Pfilename);                                  //~v367R~
//        return rc;                                               //~v367R~
    case EROFS:                                                    //~v327I~
        return ufilereadonly(Pfilename,rc);                        //~v327I~
#else //!UNX//!!!!!!!!!!!                                          //~v327I~
#ifdef DOS                                                      //~5825I~
#else                                                           //~5825I~
    #ifdef W32  //EISOPEN is OS2 err code                          //~v022I~
    #else                                                          //~v022I~
    case EISOPEN:                                               //~5825I~
        uerrmsg("%s is Opened",                                 //~5825R~
                "%s はオープン中",                              //~5825I~
//              Pfilename);                                     //~5825R~//~v6ygR~
                STD_FNM(Pfilename));                               //~v6ygI~
        return rc;                                              //~5825I~
    #endif                                                         //~v022I~
#endif                                                          //~5825I~
    case ENOENT:                                                //~5825M~
        return ufilenotfound(Pfilename,rc);                     //~5909I~
//#ifdef DOS                                                       //~v014R~
    case EACCES:                                                //~5825I~
//#else                                                            //~v014R~
//  case EACCESS:                                                  //~v014R~
//#endif                                                           //~v014R~
        if (UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))           //~5826I~
        {                                                       //~5826I~
            uerrmsg("%s is Directory",                             //~v367R~
                    "%s はディレクトリーです",                  //~5826I~
//                  Pfilename);                                 //~5826I~//~v6ygR~
                    STD_FNM(Pfilename));                           //~v6ygI~
            return rc;                                          //~5826I~
        }                                                       //~5826I~
        if (UCBITCHK(fstat3.attrFile,FILE_READONLY))            //~5826R~
            return ufilereadonly(Pfilename,rc);                 //~5909I~
        break;                                                  //~5825I~
#endif //!UNX//!!!!!!!!!!!                                         //~v327I~
    }                                                           //~5825I~
    return ufileapierr("remove",Pfilename,rc);                  //~5909I~
}//uremove                                                      //~5825R~
int urenamenomsg(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec)  //~v6H1I~
{                                                                  //~v6H1I~
	int rc;                                                        //~v6H1I~
//*******************                                              //~v6H1I~
	Srenamenomsg=1;                                                //~v6H1I~
	rc=urename(Poldname,Pnewname,Pnewspec);                        //~v6H1I~
	Srenamenomsg=0;                                                //~v6H1I~
    return rc;                                                     //~v6H1I~
}//urenamenomsg                                                    //~v6H1I~
#if defined(UNX) || defined(W32)                                   //~v520I~
//**************************************************************** //~v520I~
//urename2                                                         //~v520I~
//* rename2                                                        //~v520I~
//*  same as urename except allow override existing                //~v520I~
//*  called by unx/win                                             //~v520I~
//**************************************************************** //~v520I~
int urename2(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec)      //~v520I~
{                                                                  //~v520I~
	int rc;                                                        //~v520I~
//*******************                                              //~v520I~
	Srenameexisting=1;                                             //~v520I~
	rc=urename(Poldname,Pnewname,Pnewspec);                        //~v520R~
	Srenameexisting=0;                                             //~v520I~
    return rc;                                                     //~v520I~
}//urename2                                                        //~v520I~
#endif                                                             //~v520I~
//****************************************************************//~5825I~
//urename                                                       //~5825R~
//* rename                                                      //~5825R~
//*  dir rename avail,cross dir ok,but cross device is not avail//~5826I~
//*  for WIN32(MoveFile) cross drive file move is ok               //~v034I~
//*  but cross drive directory move return rc=5(ERROR_ACCESS_DENIED)//~v034I~
//*  and cross drive file move cannot delete original file when it is opened//~v034I~
//*  and return rc 0,so reject cross drive move also for file.     //~v034I~
//*parm1:old filename                                           //~5825R~
//*parm2:new filename                                           //~5825I~
//*parm3:optional output new name for wild card new name rename    //~v276R~
//*      if no wild card,0 is set                                  //~v276I~
//*retrn:rc(=errno)                                             //~5825R~
//****************************************************************//~5825I~
int urename(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec)       //~v276R~
//#ifdef UNX                                                       //~v5c7R~
//{                                                                //~v5c7R~
//    int rc;                                                      //~v5c7R~
//    int urenameunx(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec);//~v5c7R~
////*****************                                              //~v5c7R~
//    Gufile_opt|=GFILEOPT_IGNORESLINKERR; //ignore slink err      //~v5c7R~
//    rc=urenameunx(Poldname,Pnewname,Pnewspec);//rname also slink err//~v5c7R~
//    Gufile_opt&=~GFILEOPT_IGNORESLINKERR;                        //~v5c7R~
//    return rc;                                                   //~v5c7R~
//}                                                                //~v5c7R~
//int urenameunx(UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec)  //~v5c7R~
//#endif                                                           //~v5c7R~
{                                                               //~5825I~
//#ifndef UNX  //!!!!!!!!!!!                                       //~v557R~
    FILEFINDBUF3 fstat3;                                        //~5825I~
//#endif                                                           //~v557R~
    int rc;                                                     //~5825I~
    int pathlen1,pathlen2;                                         //~v276I~
    int renamectr;                                                 //~v278I~
    UCHAR *pc;                                                     //~v278I~
//  UCHAR realname[_MAX_PATH];                                     //~v278I~//~v6H6R~
//  UCHAR realname[_MAX_PATH2];                                    //~v6H6I~//~v6H9R~
    UCHAR realname[_MAX_PATH2_LONG];                               //~v6H9I~
#ifdef W32                                                         //~v034R~
//  UCHAR fullpath[_MAX_PATH];                                     //~v034I~//~v6H6R~
//  UCHAR fullpath[_MAX_PATH2];                                    //~v6H6I~//~v6H9R~
    UCHAR fullpath[_MAX_PATH2_LONG];                               //~v6H9I~
    int d1,d2;                                                     //~v034I~
#endif                                                             //~v034I~
#ifdef FTPSUPP                                                     //~v59pI~
    int ftpopt;                                                    //~v59pR~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v59pI~
//********************                                          //~5825I~
#ifdef FTPSUPP                                                     //~v59pI~
	ftpopt=Srenameexisting;                                        //~v59pM~
  	if (uftpisremote(Poldname,&puftph))	//ftp filename             //~v5afR~
  		return uftprename(puftph,ftpopt,Poldname,Pnewname,Pnewspec);//~v5afR~
#endif                                                             //~v59pI~
    if ((pathlen1=PATHLEN(Poldname))<0)                            //~v278R~
        pathlen1=0;                                                //~v278I~
    if ((pathlen2=PATHLEN(Pnewname))<0)                            //~v278R~
        pathlen2=0;                                                //~v278I~
    if (pc=WILDCARD(Poldname),pc)   //wild char pos                //~v278R~
    {                                                              //~v278I~
//      return ufilewildcarderr(-1);                               //~v278R~
//      if (pathlen1 && (ULONG)pc-(ULONG)Poldname<(ULONG)pathlen1) //~v278R~//~v6hhR~
        if (pathlen1 && (ULPTR)pc-(ULPTR)Poldname<(ULPTR)pathlen1) //~v6hhI~
            return ufilewildpatherr(-1);                           //~v278I~
#ifdef UNX                                                         //~v6b1I~
      if (ufstat_wild(Poldname,NULL))	//wildname real file dose not exist//~v6b1I~
#endif                                                             //~v6b1I~
      {                                                            //~v6b1I~
//      rc=uwildfunc(0,         //bypass ea data                   //~v278I~//~v6q0R~
        rc=uwildfunc(UWFO_RENAME, //bypass ea data,use alias to rename wildcard member name//~v6q0I~
                    Poldname,FILE_ALL,ufilewildrename,Pnewname,&renamectr);//~v278I~
        if (rc)                                                    //~v278I~
            return rc;                                             //~v278I~
        uerrmsg("%d object renamed",                               //~v278R~
                "%d 件改名",                                       //~v278R~
                renamectr);                                        //~v278I~
        return 0;                                                  //~v278I~
      }                                                            //~v6b1I~
    }                                                              //~v278I~
    if (ufilespfnchk(Poldname,1))  //if special file for rename    //~v085I~
    {                                                              //~v085I~
	  if (!Srenamenomsg)                                           //~v6H1I~
        uerrmsg("%s is prohibitted to rename",                     //~v085I~
                "%s は改名禁止の特殊ファイルです",                 //~v085I~
                Poldname);                                         //~v085I~
        return EACCES;                                             //~v085R~
    }                                                              //~v085I~
    if (WILDCARD(Pnewname))                                        //~v276I~
    {                                                              //~v276I~
        memcpy(realname,Pnewname,(UINT)pathlen2);                  //~v278I~
//      udoseditname(Poldname+pathlen1,Pnewname+pathlen2,realname+pathlen2);//~v56xR~
        udoseditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,          //~v56xR~
					Poldname+pathlen1,Pnewname+pathlen2,realname+pathlen2);//~v56xI~
//        UMAXPATHCHK(realname,_MAX_PATH,-1,1/*msgsw*/);             //~v6H6I~//~v6H9R~
        if (Pnewspec)   //no output  parm                          //~v278I~
            strcpy(Pnewspec,realname);                             //~v278I~
        Pnewname=realname;                                         //~v278R~
        if (WILDCARD(Pnewname))     //path has wild card           //~v276I~
            return ufilewildpatherr(-1);                           //~v276I~
    }                                                              //~v276I~
    else                                                           //~v276I~
        if (Pnewspec)   //no output  parm                          //~v276I~
            *Pnewspec=0;        //return id of no wild card        //~v276I~
#ifdef W32                                                         //~v034R~
  if (Srenameexisting)		//from rename2;override existing option or not same drv//~v520I~
  {                                                                //~v520I~
    if (MoveFileEx(Poldname,Pnewname,                              //~v520I~
					MOVEFILE_COPY_ALLOWED		//different vol    //~v520R~
					|MOVEFILE_REPLACE_EXISTING)                    //~v520I~
		==TRUE)//err when different drive                          //~v520I~
    	return 0;                                                  //~v520I~
    rc=GetLastError();                                             //~v520I~
  }                                                                //~v520I~
  else                                                             //~v520I~
  {                                                                //~v520I~
    if (*(Poldname+1)==':')                                        //~v034I~
        d1=toupper(*Poldname);                                     //~v034I~
    else                                                           //~v034I~
//      if (ufullpath(fullpath,Poldname,_MAX_PATH))                //~v034I~//~v6H9R~
        if (ufullpath(fullpath,Poldname,sizeof(fullpath)))         //~v6H9I~
            d1=toupper(*fullpath);                                 //~v034I~
        else                                                       //~v034I~
            d1=0;   //do FileMove                                  //~v034I~
    if (*(Pnewname+1)==':')                                        //~v034I~
        d2=toupper(*Pnewname);                                     //~v034I~
    else                                                           //~v034I~
//      if (ufullpath(fullpath,Pnewname,_MAX_PATH))                //~v034I~//~v6H9R~
        if (ufullpath(fullpath,Pnewname,sizeof(fullpath)))         //~v6H9I~
            d2=toupper(*fullpath);                                 //~v034I~
        else                                                       //~v034I~
            d2=0;   //do FileMove                                  //~v034I~
    if (d1 && d1==d2)   //same drive                               //~v034I~
    {                                                              //~v034I~
        if (MoveFile(Poldname,Pnewname)==TRUE)//err when different drive//~v034R~
            return 0;                                              //~v034R~
        rc=GetLastError();                                         //~v6H9R~
    }                                                              //~v034I~
    else                                                           //~v034I~
        rc=ERROR_NOT_SAME_DEVICE;                                  //~v034R~
  }//not from rename2                                              //~v520I~
#else                                                      //+v034I~//~v034R~
    #ifdef DPMI                 //DPMI version                     //~v053I~
        if (!ufstat(Pnewname,0))    //exist chk                    //~v053R~
            return ufileexist(Pnewname,EEXIST);                    //~v053R~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
    #ifdef UNX                  //DPMI version                     //~v327I~
//rename succes evenif newname exist;                              //~v352I~
	  if (!Srenameexisting)		//not override existing option     //~v520I~
      {                                                            //~v6H1I~
        if (!ufstat(Pnewname,0))    //exist chk                    //~v327I~
        {                                                          //~v6H1I~
	  	  if (!Srenamenomsg)                                       //~v6H1I~
            return ufileexist(Pnewname,EEXIST);                    //~v327I~
          else                                                     //~v6H1I~
            return EEXIST;                                         //~v6H1I~
        }                                                          //~v6H1I~
      }                                                            //~v6H1I~
    #endif                      //DPMI or not                      //~v327I~
  #ifdef UNX  //!!!!!!!!!!!                                        //~v557I~
  	if (MDOSDISKOK(Poldname))	    //contain drive id             //~v557R~
    {                                                              //~v557I~
        if (!urename_mdos(Poldname,Pnewname))                      //~v557I~
	        return 0;                                              //~v557I~
    }                                                              //~v557I~
    else                                                           //~v557I~
  #endif                                                           //~v557I~
    if (!rename(Poldname,Pnewname))                             //~5825R~
        return 0;                                               //~5825I~
    rc=errno;                                                   //~5826M~
#endif                                                     //+v034I~//~v034R~
    if (Gufile_nomsg)   //nomsg option                          //~5826I~
        return rc;                                              //~5826I~
                                                                //~5826I~
    switch(rc)                                                  //~5826R~
    {                                                           //~5825I~
#ifdef UNX  //!!!!!!!!!!!                                          //~v327I~
    case EPERM: //operation not permit                             //~v352I~
    case EACCES:                                                   //~v327I~
//  	return ufilenopermission("rename",Poldname,rc);            //~v366R~
	   if (!Srenamenomsg)                                          //~v6H1I~
       {                                                           //~v6H1I~
    	ufilenopermission("rename",Poldname,rc);                   //~v366R~
        uerrmsgcat(",or %s",0,                                     //~v352I~
                    Pnewname);                                     //~v352I~
       }                                                           //~v6H1I~
        UTRACEP("%s:rc=%d\n",UTT,rc);                              //~v6H1R~
        return rc;                                                 //~v352I~
    case EBUSY:                                                    //~v327R~
        uerrmsg("%s is in Opened",                                 //~v327I~
                "%s はオープン中",                                 //~v327I~
                Poldname);                                         //~v327I~
        return rc;                                                 //~v327I~
    case ENOTDIR:                                                  //~v327I~
    case ENOENT:                                                   //~v327I~
      if (ufstat(Poldname,&fstat3))                                //~v557I~
      {                                                            //~v6H1I~
	   if (!Srenamenomsg)                                          //~v6H1I~
        ufilenotfound(Poldname,rc);                                //~v327R~
      }                                                            //~v6H1I~
      else                                                         //~v557I~
      {                                                            //~v6H1I~
	   if (!Srenamenomsg)                                          //~v6H1I~
        ufilenotfound(Pnewname,rc);                                //~v557I~
      }                                                            //~v6H1I~
        return rc;                                                 //~v327I~
    case EXDEV:                                                    //~v327I~
        uerrmsg("%s and %s is on different file-system",           //~v327I~
                "%s と %s はファイルシステムが異なります",         //~v327I~
                Poldname,Pnewname);                                //~v327I~
        return rc;                                                 //~v327I~
#else  //UNX  //!!!!!!!!!!!                                        //~v40cR~
                                                                   //~v327I~
#ifdef DOS                                                      //~5825M~
#else                                                           //~5825M~
    #ifdef W32  //EISOPEN is OS2 err code                          //~v022I~
    #else                                                          //~v022I~
    case EISOPEN:                                               //~5825M~
        uerrmsg("%s is in Opened",                              //~5825M~
                "%s はオープン中",                              //~5825M~
//              Poldname);                                      //~5825I~//~v6ygR~
                STD_FNM(Poldname));                                //~v6ygI~
        return rc;                                              //~5825I~
    #endif                                                         //~v034M~
#endif                                                          //~5825M~
#ifdef W32                                                         //~v034R~
//  case ENOTSAM:                                                  //~v034R~
    case ERROR_NOT_SAME_DEVICE:                                    //~v034I~
#else                                                              //~v034I~
    case EXDEV:                                                 //~5825I~
#endif                                                             //~v034I~
        uerrmsg("%s and %s is on different drive",              //~5825I~
                "%s と %s はドライブが異なります",              //~5825I~
                Poldname,Pnewname);                             //~5825I~
        return rc;                                              //~5825I~
#ifdef W32                                                         //~v034R~
    case ERROR_FILE_NOT_FOUND:                                 //~v034I~//~v034R~
	   if (!Srenamenomsg)                                          //~v6H1I~
        return ufilenotfound(Poldname,rc);                     //+v034R~//~v034R~
       else                                                        //~v6H1I~
        return rc;                                                 //~v6H1I~
    case ERROR_PATH_NOT_FOUND:                                 //~v034I~//~v034R~
        if (ufstat(Poldname,&fstat3))                          //+v034I~//~v034R~
        {                                                          //~v6H1I~
	   	  if (!Srenamenomsg)                                       //~v6H1I~
            ufilepatherr(Poldname,rc);                  //+v034R~  //~v034R~
        }                                                          //~v6H1I~
        else                                                   //+v034I~//~v034R~
        {                                                          //~v6H1I~
	   	  if (!Srenamenomsg)                                       //~v6H1I~
            ufilepatherr(Pnewname,rc);                  //+v034I~  //~v034R~
        }                                                          //~v6H1I~
#else                                                              //~v034R~
    case ENOENT:                                                //~5825I~
        if (ufstat(Poldname,&fstat3))                           //~5826R~
        {                                                          //~v6H1I~
	   	  if (!Srenamenomsg)                                       //~v6H1I~
            ufilenotfound(Poldname,rc);                         //~5909R~
        }                                                          //~v6H1I~
        else                                                    //~5825I~
        {                                                          //~v6H1I~
	   	  if (!Srenamenomsg)                                       //~v6H1I~
            ufilepatherr(Pnewname,rc);                          //~5909R~
        }                                                          //~v6H1I~
#endif                                                             //~v034R~
        return rc;                                              //~5825I~
#ifdef W32                                                         //~v034R~
    case ERROR_INVALID_NAME:                                       //~v6H9M~
	   if (!Srenamenomsg)                                          //~v6H9M~
        uerrmsg("Invalid FileName Format(%s - %s)",0,              //~v6H9M~
        	Poldname,Pnewname);                                    //~v6H9M~
        return rc;                                                 //~v6H9M~
    case ERROR_ALREADY_EXISTS:                                     //~v034I~
    case ERROR_FILE_EXISTS:                                        //~v034I~
	  if (!Srenamenomsg)                                           //~v6H1I~
        return ufileexist(Pnewname,rc);                            //~v034I~
      else                                                         //~v6H1I~
        return rc;                                                 //~v6H1I~
    case ERROR_ACCESS_DENIED:                                      //~v034I~
	  if (!Srenamenomsg)                                           //~v6H1I~
        return ufileshare(Poldname,rc);                            //~v034I~
      else                                                         //~v6H1I~
        return rc;                                                 //~v6H1I~
#else                                                              //~v034R~
//#ifdef DOS                                                       //~v014R~
    case EACCES:                                                //~5825I~
//#else                                                            //~v014R~
//  case EACCESS:                                                  //~v014R~
//#endif                                                           //~v014R~
        if (!ufstat(Pnewname,&fstat3))                          //~5826R~
        {                                                       //~5826R~
//          if (UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))       //~5B11R~
//              uerrmsg("%s is directry,specify file name also",//~5B11R~
//                      "%s はディレクトリ－です,ファイル名も指定する",//~5B11R~
//                      Pnewname);                              //~5B11R~
//          else                                                //~5B11R~
	  		  if (!Srenamenomsg)                                   //~v6H1I~
                return ufileexist(Pnewname,rc);                 //~5909R~
              else                                                 //~v6H1I~
                return rc;                                         //~v6H1I~
//          return rc;                                          //~5B11R~
        }                                                       //~5826I~
        return ufileshare(Poldname,rc);                            //~v016I~
#endif                                                             //~v034R~
#endif //UNX  //!!!!!!!!!!!                                        //~v40cR~
    }                                                           //~5825I~
//#ifdef W32                                                       //~v6q0R~
//    if (rc=ufilechkwildname(CWMO_ERRMSG|CWMO_RENAME,Poldname,NULL),rc)//~v6q0R~
//        return 4;                                                //~v6q0R~
//#endif                                                           //~v6q0R~
    return ufileapierr2("rename",Poldname,Pnewname,rc);         //~5909I~
}//urename                                                      //~5825R~
                                                                //~5825I~
//**************************************************************** //~v278I~
//!ufilewildrename                                                 //~v278I~
//* delete by wild card                                            //~v278I~
//*parm1:filename thru wildfunc                                    //~v278I~
//*parm2:dirlist ptr thru wildfunc                                 //~v278I~
//*parm3:parm thru uwildfunc(Pnewname parm of urename)             //~v278I~
//*retrn:rc                                                        //~v278I~
//**************************************************************** //~v278I~
int ufilewildrename(UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v278I~
{                                                                  //~v278I~
//********************                                             //~v278I~
    return urename(Pfullpath,Pparm,0);                             //~v278I~
}//ufilewildrename                                                 //~v5amR~
                                                                   //~v278I~
#ifndef UNX  //!!!!!!!!!!!                                         //~v327I~
//****************************************************************//~5903I~
//uattrib                                                       //~5903I~
//* set file attribute(read/hidden/system/archive)              //~5903R~
//* return file attribute when p2==0 and p3==0                  //~5903I~
//*parm1:filename                                               //~5903I~
//*parm2:attribute to set on                                    //~5903I~
//*parm3:attribute to set off                                   //~5903I~
//*parm4:result attribute                                       //~5903I~
//*retrn:rc                                                     //~5903R~
//****************************************************************//~5903I~
//int uattrib(UCHAR *Pfname,UCHAR Pattron,UCHAR Pattroff,UCHAR *Poutattr)//~v59eR~
int uattrib(UCHAR *Pfname,ULONG Pattron,ULONG Pattroff,ULONG *Poutattr)//~v59eR~
{                                                               //~5903I~
#ifdef DOS                                                      //~5903I~
    USHORT  attr;                                               //~5903I~
#else                                                           //~5903I~
    #ifdef W32                                                     //~v022I~
        UINT    attr;                                              //~v022R~
    #else                                                          //~v022I~
    FILESTATUS3 fstat3;                                         //~5903I~
    ULONG       attr;                                           //~5903R~
    #endif                                                         //~v022I~
#endif                                                          //~5903I~
    FILEFINDBUF3 fstat30;                                       //~5909M~
    int rc;                                                     //~5909R~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5903I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpattrib(puftph,Pfname,Pattron,Pattroff,Poutattr);//~v5afR~
#endif                                                             //~v59pI~
    if (rc=(int)udosfindfirst(Pfname,0,FILE_ALL,&fstat30),rc)   //~5909R~
        return rc;                                              //~5905I~
    attr=fstat30.attrFile;                                      //~5905I~
    if ((attr & FILE_READONLY)                                     //~v085R~
    &&  (Pattroff & FILE_READONLY)) //READ_ONLY reset req          //~v085I~
        if (ufilespfnchk(Pfname,2))  //if special file for attrib  //~v085I~
        {                                                          //~v085I~
            uerrmsg("%s is prohibitted to reset RONLY attribute",  //~v085I~
                    "%s は読取専用属性リセット禁止の特殊ファイルです",//~v085I~
                    Pfname);                                       //~v085I~
            return EACCES;                                         //~v085R~
        }                                                          //~v085I~
#ifdef DOS                                                      //~5903I~
    if (Pattron || Pattroff)                                    //~5903R~
    {                                                           //~5903I~
//      attr&=~((USHORT)Pattroff & FILE_CHMODMASK);             //~v012R~
//      attr|=((USHORT)Pattron & FILE_CHMODMASK);               //~v012R~
        attr&=~((ULONG)Pattroff);                               //~v012R~
        attr|=(ULONG)Pattron;                                   //~v012R~
        attr&=FILE_CHMODMASK;                                   //~v012R~
#ifdef DPMI                                                        //~v121I~
        if (_chmod(Pfname,1,attr)==-1)          //set              //~v121I~
#else                                                              //~v121I~
        if (_dos_setfileattr(Pfname,attr))          //query     //~5903R~
#endif                                                             //~v121I~
            return ufileapierr("_dos_setfileattr",Pfname,errno);//~v012R~
//          return ufileapierr("_dos_setfileattr",Pfname,attr); //~v012R~
    }                                                           //~5903I~
    rc=0;                                                       //~5903I~
#else                                                           //~5903I~
    if (Pattron || Pattroff)                                    //~5903I~
    {                                                           //~5903I~
    #ifdef W32                                                     //~v022I~
    #else                                                          //~v022I~
        if (rc=(int)DosQueryPathInfo(Pfname,                    //~5910I~
                                    FIL_STANDARD,   //level     //~5910I~
                                    &fstat3,                    //~5910I~
                                    sizeof(fstat3)),            //~5910R~
            rc)                                                 //~5910I~
            return ufileapierr("DosQueryPathInfo",Pfname,rc);   //~5910I~
    #endif                                                         //~v022I~
//      attr&=~((ULONG)Pattroff & FILE_CHMODMASK);              //~v012R~
//      attr|=((ULONG)Pattron & FILE_CHMODMASK);                //~v012R~
        attr&=~((ULONG)Pattroff);                               //~v011I~
        attr|=(ULONG)Pattron;                                   //~v011I~
        attr&=FILE_CHMODMASK;                                   //~v011I~
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            if (rc=SetFileAttributes(Pfname,attr),rc==FALSE)    //1:set attr//~v034R~
                return ufileapierr("SetFileAttributes",Pfname,GetLastError());//~v034R~
            else                                                   //~v034I~
                rc=0;                                              //~v034I~
        #else                                                      //~v034I~
        if (rc=_rtl_chmod(Pfname,1,(int)attr),rc==-1)   //1:set attr//~v022I~
            return ufileapierr("_rtl_chmod",Pfname,errno);         //~v022I~
        #endif                                                     //~v034I~
    #else                                                          //~v022I~
        fstat3.attrFile=attr;                                   //~5903R~
        if (rc=(int)DosSetPathInfo(Pfname,                      //~5903R~
                                    FIL_STANDARD,   //level     //~5910R~
                                    &fstat3,                    //~5910R~
                                    sizeof(fstat3),             //~5910R~
                                    DSPI_WRTTHRU),              //~5910R~
            rc)                                                 //~5903R~
        {                                                          //~v016I~
            if (rc==ERROR_SHARING_VIOLATION)                       //~v016I~
                return ufileshare(Pfname,rc);                      //~v016R~
            return ufileapierr("DosSetPathInfo",Pfname,rc);     //~5903R~
        }                                                          //~v016I~
    #endif                                                         //~v022I~
    }                                                           //~5903I~
#endif                                                          //~5903I~
    *Poutattr=(UCHAR)attr;                                      //~5903R~
    return rc;                                                  //~5903I~
}//uattrib                                                      //~5903I~
                                                                //~5903I~
//**************************************************************** //~v6huM~
//*ftime(100ns unit) to second                                     //~v6huM~
//*rc:1:odd sec,0:even                                             //~v6huM~
//**************************************************************** //~v6huM~
int ftime2sec(FILETIME *Pft,LONG *Pout)                            //~v6huM~
{                                                                  //~v6huM~
    LONG dw1[3];                                                   //~v6huM~
//************                                                     //~v6huM~
    dw1[0]=Pft->dwHighDateTime;                                    //~v6huM~
    dw1[1]=Pft->dwLowDateTime;                                     //~v6huM~
	ucalc_dwdiv(dw1,FILETIME1SEC);                                 //~v6huM~
    if (Pout)                                                      //~v6huI~
    {                                                              //~v6huM~
    	Pout[0]=dw1[0];    //sec from 1601/01/01                   //~v6huM~
    	Pout[1]=dw1[1];                                            //~v6huM~
    }                                                              //~v6huM~
    return dw1[1] & 1;	//odd sec                                  //~v6huM~
}//ftime2sec                                                       //~v6huM~
//****************************************************************//~5910I~
//ugetftime                                                     //~5910I~
//* get file time stamp                                         //~5910I~
//*parm1:filename                                               //~5910I~
//*parm2:FDATE                                                  //~5910I~
//*parm3:FTIME                                                  //~5910I~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int ugetftime(UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime)        //~5910I~
{                                                               //~5910I~
#ifdef DOS                                                      //~5910I~
//  int  fh;                                                       //~v035R~
    int  rc;                                                       //~v013R~
//  UINT fdate,ftime;                                              //~v035R~
    FILEFINDBUF3 ffb3;                                             //~v035I~
#else                                                           //~5910I~
    #ifdef W32                                                     //~v022I~
//      #if (_MSC_VER >= 800)                                      //~v034R~
//          HANDLE fh;                                             //~v034R~
//          FILETIME ftw,ftm;                                      //~v034R~
            FILEFINDBUF3 ffb3;                                     //~v034R~
//      #else                                                      //~v034R~
//      FILE *fh;                                                  //~v034R~
//      USHORT ftd[2];                                             //~v034R~
//      #endif                                                     //~v034R~
        int  rc;                                                   //~v022I~
    #else                                                          //~v022I~
    FILESTATUS3 fstat3;                                         //~5910I~
    int rc;                                                     //~5910I~
    #endif                                                         //~v022I~
#endif                                                          //~5910I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5910I~
#ifdef DOS                                                      //~5910I~
//  if (_dos_open(Pfname,O_RDONLY,&fh))                            //~v035R~
//      return ufileapierr("ugetftime:_dos_open",Pfname,errno);    //~v035R~
//  if (rc=_dos_getftime(fh,&fdate,&ftime),rc)          //query    //~v035R~
//      rc=ufileapierr("_dos_getftime",Pfname,errno);              //~v035R~
//  *Ppdate=*(FDATE*)(void*)&fdate;                                //~v035R~
//  *Pptime=*(FTIME*)(void*)&ftime;                                //~v035R~
//  if (_dos_close(fh))                                            //~v035R~
//      return ufileapierr("_dos_close",Pfname,errno);             //~v035R~
    if (rc=ufstat(Pfname,&ffb3),rc)                                //~v035I~
        return ufilenotfound(Pfname,rc);                           //~v035I~
    *Ppdate=ffb3.fdateLastWrite;                                   //~v035I~
    *Pptime=ffb3.ftimeLastWrite;                                   //~v035I~
    return rc;                                                     //~v013R~
#else                                                           //~5910I~
    #ifdef W32                                                     //~v022I~
#ifdef FTPSUPP                                                     //~v59pI~
	  	if (uftpisremote(Pfname,&puftph))	//ftp filename         //~v5afR~
			return uftpgetftime(puftph,Pfname,Ppdate,Pptime);      //~v5afR~
#endif                                                             //~v59pI~
//      #if (_MSC_VER >= 800)                                      //~v034R~
//          fh=CreateFile(Pfname,                                  //~v034R~
//                          GENERIC_READ,       //access           //~v034R~
//                          FILE_SHARE_READ|FILE_SHARE_WRITE,   //share//~v034R~
//                          0,                  //security         //~v034R~
//                          OPEN_EXISTING,      //how to create    //~v034R~
//                          FILE_ALL,           //attr             //~v034R~
//                          0);                 //template handle  //~v034R~
//          if (fh==INVALID_HANDLE_VALUE)                          //~v034R~
//              return ufileapierr("ugetftime:CreateFile",Pfname,GetLastError());//~v034R~
//          if (rc=GetFileTime(fh,&ftw,&ftw,&ftm),rc==FALSE)            //query//~v034R~
//              return ufileapierr("ugetftime:GetFileTime",Pfname,GetLastError());//~v035R~
//          if (rc=FileTimeToLocalFileTime(&ftm,&ftw),rc=FALSE) //ajust to local time//~v034R~
//              return ufileapierr("ugetftime:FileTimeToLocalFileTime",Pfname,GetLastError());//~v035R~
//          if (rc=FileTimeToDosDateTime(&ftw,(USHORT*)(void*)Ppdate,//~v034R~
//                  (USHORT*)(void*)Pptime),rc==FALSE)             //~v034R~
//              return ufileapierr("ugetftime:FileTimeToDosDateTime",Pfname,GetLastError());//~v035R~
//          CloseHandle(fh);                                       //~v034R~
            if (rc=ufstat(Pfname,&ffb3),rc)                        //~v034R~
                return ufilenotfound(Pfname,rc);                   //~v034I~
            *Ppdate=ffb3.fdateLastWrite;                           //~v034R~
            *Pptime=ffb3.ftimeLastWrite;                           //~v034R~
            if (Soddsec==-1)                                       //~v6huI~
            {                                                      //~v6huI~
                Soddsec=ftime2sec(&ffb3.ftLastWriteTime,0);        //~v6huI~
            }                                                      //~v6huI~
//      #else                                                      //~v034R~
//      if (fh=fopen(Pfname,"r"),!fh)                              //~v034R~
//          return ufileapierr("ugetftime:fopen",Pfname,errno);    //~v034R~
//      if (rc=getftime(fileno(fh),(struct ftime*)(PVOID)ftd),rc)           //query//~v034R~
//          rc=ufileapierr("ugetftime:getftime",Pfname,errno);     //~v034R~
//printf("ugetftime %04x,%04x\n",ftd[0],ftd[1]);                   //~v022R~
//      *Ppdate=*(FDATE*)(void*)&ftd[1];                           //~v034R~
//      *Pptime=*(FTIME*)(void*)&ftd[0];                           //~v034R~
//      fclose(fh);                                                //~v034R~
//      #endif                                                     //~v034R~
        return rc;                                                 //~v022I~
    #else                                                          //~v022I~
    if (rc=(int)DosQueryPathInfo(Pfname,                        //~5910I~
                                FIL_STANDARD,   //level         //~5910I~
                                &fstat3,                        //~5910I~
                                sizeof(fstat3)),                //~5910R~
        rc)                                                     //~5910I~
        return ufileapierr("DosQueryPathInfo",Pfname,rc);       //~5910I~
                                                                //~5910I~
    *Ppdate=fstat3.fdateLastWrite;                              //~5910R~
    *Pptime=fstat3.ftimeLastWrite;                              //~5910R~
    return 0;                                                   //~5910I~
    #endif                                                         //~v022I~
#endif                                                             //~v022M~
}//ugetftime                                                    //~5923R~
//**************************************************************** //~v6hhI~
//ugetftime_1sec                                                   //~v6hhI~//~v6huR~
//**************************************************************** //~v6hhI~
int ugetftime_1sec(UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime,int *Ppoddsec)//~v6hhI~//~v6huR~
{                                                                  //~v6hhI~
#ifdef FTPSUPP                                                     //~v6hhI~
    PUFTPHOST puftph;                                              //~v6hhI~
#endif                                                             //~v6hhI~
#ifdef W32                                                         //~v6huI~
    int rc;                                                        //~v6huI~
#endif                                                             //~v6huI~
//********************                                             //~v6hhI~
#ifdef FTPSUPP                                                     //~v6hhI~
	  	if (uftpisremote(Pfname,&puftph))	//ftp filename         //~v6hhI~
			return uftpgetftime_1sec(puftph,Pfname,Ppdate,Pptime,Ppoddsec);//~v6hhI~//~v6huR~
#endif                                                             //~v6hhI~
#ifdef W32                                                         //~v6huI~
	Soddsec=-1;	//req to set oddsec                                //~v6huI~
    rc=ugetftime(Pfname,Ppdate,Pptime);                            //~v6huI~
	*Ppoddsec=Soddsec;                                             //~v6huI~
	Soddsec=0;                                                     //~v6huI~
    return rc;                                                     //~v6huI~
#else                                                              //~v6huI~
	*Ppoddsec=0;                                                   //~v6hhI~
    return ugetftime(Pfname,Ppdate,Pptime);                        //~v6hhI~
#endif                                                             //~v6huI~
}//ugetftime_1sec                                                  //~v6hhI~//~v6huR~
                                                                //~5910I~
//****************************************************************//~5910I~
//usetftime                                                     //~5910I~
//* set file time stamp                                            //~v035R~
//*  for DOS,VC Win fail for directory                             //~v035I~
//*parm1:filename                                               //~5910I~
//*parm2:FDATE                                                  //~5910I~
//*parm3:FTIME                                                  //~5910I~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int usetftime(UCHAR *Pfname,FDATE Pdate,FTIME Ptime)            //~5910I~
{                                                               //~5910I~
    FILEFINDBUF3 ffb3;                                             //~v034I~
#ifdef DOS                                                      //~5910I~
    #ifdef DPMI                 //DPMI version                     //~v121I~
        struct ftime ft;                                           //~v121I~
        ULONG *ulft;                                               //~v121I~
    #else                       //not DPMI                         //~v121I~
    #endif                      //DPMI or not                      //~v121I~
    int  fh;                                                    //~5910I~
    int  rc;                                                       //~v013R~
#else                                                           //~5910I~
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            HANDLE fh;                                             //~v034R~
            FILETIME ftw,ftm,ftl;                                  //~v034R~
            FILETIME fta;	//access time                          //~v6huI~
        #else                                                      //~v034I~
        FILE *fh;                                                  //~v022I~
        USHORT ftd[2];                                             //~v022I~
        #endif                                                     //~v034M~
        int  rc;                                                   //~v022I~
    #else                                                          //~v022I~
    FILESTATUS3 fstat3;                                         //~5910I~
    int rc;                                                     //~5910I~
    #endif                                                         //~v022I~
#endif                                                          //~5910I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5910I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpsetftime(puftph,Pfname,Pdate,Ptime);            //~v5afR~
#endif                                                             //~v59pI~
    if (rc=(int)ufstat(Pfname,&ffb3),rc)                           //~v035R~
        return ufilenotfound(Pfname,rc);                           //~v035R~
#ifdef DOS                                                      //~5910I~
    if (ffb3.attrFile & FILE_DIRECTORY)                            //~v035R~
        return ufiledirna(Pfname,"Set File Time",EACCES);          //~v035R~
  #ifdef DPMI                   //DPMI version                     //~v121I~
//  if ((fh=open(Pfname,O_RDONLY))<0)                              //~v135R~
    if ((fh=open(Pfname,O_RDWR))<0)                                //~v135I~
        return ufileapierr("usetftime:open",Pfname,errno);         //~v121I~
    ulft=(void*)(&ft);                                             //~v121R~
    *ulft=(((UINT)(*(USHORT*)(void*)(&Pdate)))<<16)                //~v121I~
            +(UINT)(*(USHORT*)(void*)(&Ptime));                    //~v121I~
    if (setftime(fh,&ft))       //set                              //~v121I~
        rc=ufileapierr("setftime",Pfname,errno);                   //~v121I~
    if (close(fh))                                                 //~v121I~
        return ufileapierr("usetftime:close",Pfname,errno);        //~v121I~
  #else                       //not DPMI                           //~v121I~
//  if (_dos_open(Pfname,O_RDONLY,&fh))                            //~v013R~
    if (_dos_open(Pfname,O_RDWR,&fh))                              //~v013R~
        return ufileapierr("usetftime:_dos_open",Pfname,errno);    //~v012R~
    if (rc=_dos_setftime(fh,*(UINT*)(void*)&Pdate,*(UINT*)(void*)&Ptime),rc)//query//~v013R~
        rc=ufileapierr("_dos_setftime",Pfname,errno);              //~v013R~
    if (_dos_close(fh))                                         //~5910I~
        return ufileapierr("_dos_close",Pfname,errno);          //~5917I~
  #endif                                                           //~v121I~
    return rc;                                                     //~v013R~
#else                                                           //~5910I~
    #ifdef W32                                                     //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034I~
            if (ffb3.attrFile & FILE_DIRECTORY)                    //~v035R~
                return ufiledirna(Pfname,"Set File Time",ERROR_ACCESS_DENIED);//~v035R~
            fh=CreateFile(Pfname,                                  //~v034I~
                            GENERIC_WRITE,      //access           //~v035R~
                            FILE_SHARE_READ|FILE_SHARE_WRITE,   //share//~v034I~
                            0,                  //security         //~v034I~
                            OPEN_EXISTING,      //how to create    //~v034I~
                            FILE_ALL,           //attr             //~v034I~
                            0);                 //template handle  //~v034I~
            if (fh==INVALID_HANDLE_VALUE)                          //~v034I~
            {                                                      //~v034I~
                rc=GetLastError();                                 //~v034R~
                if (rc==ERROR_SHARING_VIOLATION)                   //~v034R~
                    return ufileshare(Pfname,rc);                  //~v034R~
                else                                               //~v034I~
                    return ufileapierr("usetftime:CreateFile",Pfname,rc);//~v034I~
            }                                                      //~v034I~
//          if (rc=GetFileTime(fh,&ftw,&ftm,&ftm),rc==FALSE)            //query//~v034R~//~v6huR~
            if (rc=GetFileTime(fh,&ftw,&fta,&ftm),rc==FALSE)            //query//~v6huI~
                return ufileapierr("ugetftime:GetFileTime",Pfname,GetLastError());//~v035R~
            if (rc=DosDateTimeToFileTime(*((USHORT*)(void*)&Pdate),//~v034R~
                                         *((USHORT*)(void*)&Ptime),//~v034R~
                                        &ftl),rc==FALSE)           //~v034R~
                return ufileapierr("usetftime:ToDosDateTimeToFileTime",Pfname,GetLastError());//~v035R~//~v6huR~
            if (Soddsec)                                           //~v6huI~
            {                                                      //~v6huI~
                LONG dw1[2];                                       //~v6huR~
                ftime2sec(&ftl,dw1);                               //~v6huI~
                DWORD_ADD(dw1[0],dw1[1],0,1);    //+1              //~v6huR~
				ucalc_dwmult(dw1,FILETIME1SEC);                    //~v6huR~
                ftl.dwHighDateTime=dw1[0];                         //~v6huR~
                ftl.dwLowDateTime=dw1[1];                          //~v6huR~
            }                                                      //~v6huI~
            if (rc=LocalFileTimeToFileTime(&ftl,&ftm),rc=FALSE) //ajust to local time//~v034I~
                return ufileapierr("ugetftime:LocalFileTimeToFileTime",Pfname,GetLastError());//~v035R~
//          if (rc=SetFileTime(fh,&ftw,&ftm,&ftm),rc==FALSE)            //query//~v034R~//~v6huR~
            if (rc=SetFileTime(fh,&ftw,&fta,&ftm),rc==FALSE)            //query//~v6huI~
                return ufileapierr("usetftime:SetFileTime",Pfname,GetLastError());//~v035R~
            CloseHandle(fh);                                       //~v034R~
            rc=0;                                                  //~v034I~
        #else                                                      //~v034I~
        if (fh=fopen(Pfname,"w"),!fh)                              //~v022I~
            return ufileapierr("usetftime:fopen",Pfname,errno);    //~v022I~
        ftd[0]=*(USHORT*)(PVOID)&Ptime;                            //~v022I~
        ftd[1]=*(USHORT*)(PVOID)&Pdate;                            //~v022I~
        if (rc=setftime(fileno(fh),(struct ftime*)(PVOID)ftd),rc)  //~v022I~
            rc=ufileapierr("usetftime:setftime",Pfname,errno);     //~v022I~
        fclose(fh);                                                //~v022I~
        #endif                                                     //~v034I~
        return rc;                                                 //~v022I~
    #else                                                          //~v022I~
    if (rc=(int)DosQueryPathInfo(Pfname,                        //~5910I~
                                FIL_STANDARD,   //level         //~5910I~
                                &fstat3,                        //~5910I~
                                sizeof(fstat3)),                //~5910R~
        rc)                                                     //~5910I~
        return ufileapierr("DosQueryPathInfo",Pfname,rc);       //~5910I~
                                                                //~5910I~
    fstat3.fdateLastWrite=Pdate;                                //~5910I~
    fstat3.ftimeLastWrite=Ptime;                                //~5910I~
    if (rc=(int)DosSetPathInfo(Pfname,                          //~5910I~
                                FIL_STANDARD,   //level         //~5910I~
                                &fstat3,                        //~5910I~
                                sizeof(fstat3),                 //~5910I~
                                DSPI_WRTTHRU),                  //~5910I~
        rc)                                                     //~5910I~
    {                                                              //~v016I~
        if (rc==ERROR_SHARING_VIOLATION)                           //~v016R~
            return ufileshare(Pfname,rc);                          //~v016I~
        return ufileapierr("DosSetPathInfo",Pfname,rc);         //~5910I~
    }                                                              //~v016I~
    return 0;                                                   //~5910I~
    #endif                                                         //~v022I~
#endif                                                             //~v022M~
}//usetftime                                                    //~5910I~
#ifdef W32                                                         //~v6huI~
//**************************************************************** //~v6huI~
//usetftime_1sec                                                   //~v6huR~
//* set file time stamp by unit 1sec                               //~v6huI~
//**************************************************************** //~v6huI~
int usetftime_1sec(UCHAR *Pfname,FDATE Pdate,FTIME Ptime,int Poddsec)//~v6huR~
{                                                                  //~v6huI~
    int rc;                                                        //~v6huI~
//*********                                                        //~v6huI~
	Soddsec=Poddsec;	//req to set oddsec                        //~v6huI~
    rc=usetftime(Pfname,Pdate,Ptime);                              //~v6huR~
	Soddsec=0;                                                     //~v6huI~
    return rc;                                                     //~v6huI~
}//usetftime_1sec                                                  //~v6huR~
#endif                                                             //~v6huI~
#ifdef W32                                                         //~v6kjI~
    #if (_MSC_VER >= 800)                                          //~v6kjI~
//**************************************************************** //~v6kjI~
//*copy filetime for xcopy                                         //~v6kjI~
//**************************************************************** //~v6kjI~
int win_copyfiletime(int Popt,char *Psrc,char *Ptgt)               //~v6kjI~
{                                                                  //~v6kjI~
	WIN32_FIND_DATA w32fd;                                         //~v6kjI~
    HANDLE fh=INVALID_HANDLE_VALUE;                                //~v6ktR~
    int rc=0;                                                      //~v6kjI~
    UINT attrflag;                                                 //~v6kjI~
//****************************                                     //~v6kjI~
    for (;;)                                                       //~v6kjI~
    {                                                              //~v6kjI~
//ugetftime                                                        //~v6kjI~
	    fh=FindFirstFile(Psrc,&w32fd);                             //~v6kjI~
    	if (fh==INVALID_HANDLE_VALUE)                              //~v6kjI~
        {                                                          //~v6kjI~
    		rc=GetLastError();                                     //~v6kjI~
            break;                                                 //~v6kjI~
        }                                                          //~v6kjI~
//  	CloseHandle(fh);                                           //~v6ktR~
    	FindClose(fh);                                             //~v6ktI~
        fh=INVALID_HANDLE_VALUE;                                   //~v6ktR~
//usetftime                                                        //~v6kjI~
		if (w32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)     //~v6kjR~
        	attrflag=FILE_ATTRIBUTE_DIRECTORY|FILE_FLAG_BACKUP_SEMANTICS;//~v6kjR~
        else                                                       //~v6kjI~
    		attrflag=FILE_ALL;                                     //~v6kjR~
        fh=CreateFile(Ptgt,                                        //~v6kjR~
                        GENERIC_WRITE,      //access               //~v6kjI~
                        FILE_SHARE_READ|FILE_SHARE_WRITE,   //share//~v6kjI~
                        0,                  //security             //~v6kjI~
                        OPEN_EXISTING,      //how to create        //~v6kjI~
                        attrflag,           //attr                 //~v6kjI~
                        0);                 //template handle      //~v6kjI~
        if (fh==INVALID_HANDLE_VALUE)                              //~v6kjI~
        {                                                          //~v6kjI~
            rc=GetLastError();                                     //~v6kjI~
            break;                                                 //~v6kjI~
        }                                                          //~v6kjI~
        if (!SetFileTime(fh,NULL/*creationtime*/,&w32fd.ftLastAccessTime,&w32fd.ftLastWriteTime))//~v6kjR~
        {                                                          //~v6kjI~
            rc=GetLastError();                                     //~v6kjI~
            break;                                                 //~v6kjI~
        }                                                          //~v6kjI~
        break;                                                     //~v6kjI~
    }//for                                                         //~v6kjR~
    if (fh!=INVALID_HANDLE_VALUE)                                  //~v6kjI~
    	CloseHandle(fh);                                           //~v6kjI~
    UTRACEP("win_copyfiletime rc=%d src=%s,tgt=%s\n",rc,Psrc,Ptgt);//~v6kjI~
    return rc;                                                     //~v6kjI~
}//win_copyfiletime                                                //~v6kjI~
	#endif   //_MSC_VER>=800                                       //~v6kjI~
#endif	//W32                                                      //~v6kjI~
//****************************************************************//~5910I~
//ucopypathinfo                                                 //~5916R~
//* copy file information(attr,timestamp, for os2 created time etc)//~5910I~
//*parm1:source name                                            //~5910I~
//*parm1:target name                                            //~5910I~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int ucopypathinfo(UCHAR *Psource,UCHAR *Ptarget)                //~5910I~
{                                                               //~5910I~
#ifdef DOS                                                      //~5910I~
    UINT attr;                                                  //~5910I~
    FDATE fdate;                                                //~5910I~
    FTIME ftime;                                                //~5910I~
    int dirsw;                                                  //~v012I~
#else                                                           //~5910I~
    #ifdef W32                                                     //~v022I~
//      UCHAR attr;                                                //~v59eR~
        ULONG attr;                                                //~v59eI~
      #if (_MSC_VER >= 800)                                        //~v6kjI~
      #else                                                        //~v6kjI~
        FDATE fdate;                                               //~v022I~
        FTIME ftime;                                               //~v022I~
      #endif                                                       //~v6kjI~
    #else                                                          //~v022I~
    FILESTATUS3 fstat3;                                         //~5910I~
    #endif                                                         //~v022I~
#endif                                                          //~5910I~
    int rc;                                                     //~5910I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftphs;                                             //~v5afI~
    PUFTPHOST puftpht;                                             //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5910I~
#ifdef DOS                                                      //~5910I~
  #ifdef DPMI                   //DPMI version                     //~v121I~
    attr=_chmod(Psource,0);     //query                            //~v121I~
    if (attr==-1)           //query                                //~v121I~
  #else                       //not DPMI                           //~v121I~
    if (_dos_getfileattr(Psource,&attr))            //query     //~5910I~
  #endif                      //DPMI or not                        //~v121I~
        return ufileapierr("_dos_getfileattr",Psource,errno);   //~5910I~
    dirsw=(attr&FILE_DIRECTORY);    //directory                    //~v013R~
    attr=attr & FILE_CHMODMASK;                                    //~v013R~
//  UTRACEP("copypathinfo:dirsw=%d,attr=%02x\n",dirsw,attr);       //~v012R~
    if (!dirsw)                                                    //~v013R~
    {                                                              //~v013R~
        if (rc=ugetftime(Psource,&fdate,&ftime),rc)                //~v013R~
            return rc;                                             //~v013R~
//UTRACED("getftime date",&fdate,2);                               //~v012M~
//UTRACED("getftime time",&ftime,2);                               //~v012M~
        if (rc=usetftime(Ptarget,fdate,ftime),rc)                  //~v013R~
            return rc;                                             //~v013R~
    }                                                              //~v012I~
  #ifdef DPMI                   //DPMI version                     //~v121I~
    if (_chmod(Ptarget,1,attr)==-1)         //set                  //~v121I~
  #else                       //not DPMI                           //~v121I~
    if (_dos_setfileattr(Ptarget,attr))         //query         //~5916R~
  #endif                      //DPMI or not                        //~v121I~
        return ufileapierr("_dos_setfileattr",Ptarget,errno);   //~5910R~
    return 0;                                                      //~v057I~
#else                                                           //~5910I~
    #ifdef W32                                                     //~v022I~
#ifdef FTPSUPP                                                     //~v59pI~
//    	if (uftpisremote(Psource,&puftphs)	//ftp filename         //~v5asR~
//    	||  uftpisremote(Ptarget,&puftpht))	//ftp filename         //~v5asR~
      	if ((uftpisremote(Psource,&puftphs)	//ftp filename         //~v5asI~
      	    +uftpisremote(Ptarget,&puftpht))!=0)	//ftp filename //~v5asI~
			return uftpcopypathinfo(puftphs,puftpht,Psource,Ptarget);//~v5afR~
#endif                                                             //~v59pI~
        if (rc=uattrib(Psource,0,0,&attr),rc)           //query    //~v022R~
            return rc;                                             //~v022I~
        #if (_MSC_VER >= 800)                                      //~v034R~
//      if (!(attr&FILE_DIRECTORY))    //not directory             //~v6kjR~
//      {                                                          //~v6kjR~
            win_copyfiletime(0,Psource,Ptarget);                   //~v6kjI~
        #else                                                      //~v034R~
//      #endif                                                     //~v6kjR~
        if (rc=ugetftime(Psource,&fdate,&ftime),rc)                //~v022I~
            return rc;                                             //~v022I~
        if (rc=usetftime(Ptarget,fdate,ftime),rc)                  //~v022I~
            return rc;                                             //~v022I~
//      #if (_MSC_VER >= 800)                                      //~v6kjR~
//      }                                                          //~v6kjR~
//      #else                                                      //~v6kjR~
        #endif                                                     //~v034R~
        rc=uattrib(Ptarget,(UCHAR)attr,0xff,&attr); //all off then set on//~v022R~
        return rc;                                                 //~v022R~
    #else                                                          //~v022I~
    if (rc=(int)DosQueryPathInfo(Psource,                       //~5910I~
                                FIL_STANDARD,   //level         //~5910I~
                                &fstat3,                        //~5910I~
                                sizeof(fstat3)),                //~5910R~
        rc)                                                     //~5910I~
        return ufileapierr("DosQueryPathInfo",Psource,rc);      //~5910R~
                                                                //~5910I~
    if (rc=(int)DosSetPathInfo(Ptarget,                         //~5910I~
                                FIL_STANDARD,   //level         //~5910I~
                                &fstat3,                        //~5910I~
                                sizeof(fstat3),                 //~5910I~
                                DSPI_WRTTHRU),                  //~5910I~
        rc)                                                     //~5910I~
    {                                                              //~v016I~
        if (rc==ERROR_SHARING_VIOLATION)                           //~v016R~
            return ufileshare(Ptarget,rc);                         //~v016R~
        return ufileapierr("DosSetPathInfo",Ptarget,rc);        //~5910R~
    }                                                              //~v016I~
    return 0;                                                   //~5910I~
    #endif                                                         //~v022I~
#endif                                                             //~v022M~
}//ucopypathinfo                                                //~5910I~
                                                                   //~v327I~
#endif //!UNX  !!!!!!!!!!!                                         //~v327I~
                                                                   //~v327I~
//****************************************************************//~5916I~
//uwildfunc                                                     //~5916I~
//* apply function for wild card                                //~5916I~
//*parm1:option for apply to ea data(1:apply)                   //~5916I~
//*parm2:wild card filename                                     //~5916R~
//*parm3:file selection attribute mask                          //~5916I~
//*parm4:apply function(int func(char *filename,void *parm))    //~5916I~
//*parm5:apply function parm                                    //~5916I~
//*parm5:output applied count                                   //~5916I~
//*retrn:rc                                                     //~5916I~
//****************************************************************//~5916I~
int uwildfunc(int Popt,UCHAR *Psource,unsigned Pattrmask,       //~5916I~
                WILDAPPLYFUNC *Pfunc,void *Pparm,int *Pfilectr) //~5916R~
{                                                               //~5916I~
    int rc=0,filectr,ii,pathlen;                                //~5916I~
    PUDIRLIST pudirlist,pudirlist0;                             //~5916I~
//  UCHAR fpath[_MAX_PATH];                                        //~v5d7R~//~v6H6R~
//  UCHAR fpath[_MAX_PATH2];                                       //~v6H6R~//~v6H9R~
    UCHAR fpath[_MAX_PATH2_LONG];                                  //~v6H9I~
    int swtoolong=0;                                              //~v6H1I~
//********************                                          //~5916I~
//#ifdef W32                                                       //~v6H9R~
//    filectr=udirlistWLong(0,Psource,fpath,sizeof(fpath),Pattrmask,&pudirlist0,'N');//no sort//~v6H9R~
//#else                                                            //~v6H9R~
//  if (!ufullpath(fpath,Psource,_MAX_PATH))                       //~v5d7R~//~v6H9R~
    if (!ufullpath(fpath,Psource,sizeof(fpath)))                   //~v6H9I~
        return 4;                                               //~5916I~
//*udirlist supports longname                                      //~v6H9I~
    filectr=udirlist(fpath,Pattrmask,&pudirlist0,'N');//no sort    //~v5d7R~
//#endif                                                           //~v6H9R~
    if (filectr<0)  //err                                       //~5916I~
        return 4;                                               //~5916I~
    pathlen=PATHLEN(fpath);                                        //~v5d7R~
    pudirlist=pudirlist0;                                       //~5916I~
    *Pfilectr=0;                                                //~5916I~
    for (ii=0;ii<filectr;ii++,pudirlist++)  //until eof/err     //~5916I~
    {                                                           //~5916I~
//      if (*pudirlist->name=='.')                                 //~v194R~
        if (!strcmp(pudirlist->name,".")        //curr             //~v194M~
        ||  !strcmp(pudirlist->name,".."))      //parent           //~v194M~
            continue;                                           //~5916I~
//      if (!Popt)  //avoid ea data                             //~5916I~//~v6q0R~
        if (!(Popt&UWFO_EADATA))  //avoid ea data                  //~v6q0I~
            if (!stricmp(pudirlist->name,EADATAID))             //~5916I~
                continue;                                       //~5916I~
        if (!stricmp(pudirlist->name,WINSYSVOLI))                  //~v5msI~
        	if (Pfunc==ufilewildxdel)                              //~v5msI~
            {                                                      //~v5msI~
            	uerrmsg("Bypass deletion of \"" WINSYSVOLI "\"",0);//~v5msR~
                continue;                                          //~v5msI~
            }                                                      //~v5msI~
        *Pfilectr=*Pfilectr+1;                                  //~5916I~
//    if (pathlen+(int)strlen(pudirlist->name)>=_MAX_PATH)         //~v6H1I~//~v6H9R~
      if (pathlen+(int)strlen(pudirlist->name)>=_MAX_PATH_LONG)    //~v6H9I~
      {                                                            //~v6H1I~
//#ifndef W32                                                        //~v6HoI~//~v6HtR~
        if (((Popt & UWFO_DELETE) && (Sxdelopt & UXDELMSG))        //~v6H6R~
        ||  ((Popt & UWFO_RENAME) && !Srenamenomsg)                //~v6H6R~
        ||  (Sxdelopt & UXDELRONLYCHK)  //readonly chk only        //~v6HtI~
        )                                                          //~v6H6I~
			ufileTooLongFullpathName2(0,fpath,pudirlist->name);    //~v6H1I~
//#endif                                                             //~v6HoI~//~v6HtR~
        Sxdellongnamectr++;                                        //~v6H1I~
      	swtoolong=1;                                              //~v6H1I~
        continue;                                                  //~v6H1I~
	  }                                                            //~v6H1I~
        strcpy(fpath+pathlen,pudirlist->name);                     //~v5d7R~
        if (FILE_IS_WILDNAME(pudirlist->attr))                     //~v6q0R~
        {                                                          //~v6q0I~
        	if (Popt & (UWFO_DELETE|UWFO_RENAME))                  //~v6q0R~
            {                                                      //~v6q0I~
#ifdef W32                                                         //~v6q0M~
                if (*pudirlist->alias)                             //~v6q0R~
                {                                                  //~v6q0I~
        			if (Popt & UWFO_RENAME)	//for delete,use alias at ufilewildxdel//~v6q0I~
                    	strcpy(fpath+pathlen,pudirlist->alias);    //~v6q0R~
                }                                                  //~v6q0I~
                else                                               //~v6q0R~
                {                                                  //~v6q0R~
                    uerrmsg("Could not process %s by the reason of wildcard name",0,//~v6q0R~
                            fpath);                                //~v6q0R~
                    rc=UWFRC_WILDNAME;                             //~v6q0R~
                    break; //ufree udirlist                        //~v6q0I~
                }                                                  //~v6q0R~
#else                                                              //~v6q0I~
                ;                                                  //~v6q0I~
#endif                                                             //~v6q0M~
            }                                                      //~v6q0I~
            else                                                   //~v6q0I~
            {                                                      //~v6q0I~
            	uerrmsg("Could not process %s by the reason of wildcard name, retry after delete or rename it",0,//~v6q0I~
                            fpath);                                //~v6q0I~
                rc=UWFRC_WILDNAME;                                 //~v6q0R~
                break;                                             //~v6q0I~
            }                                                      //~v6q0I~
        }                                                          //~v6q0I~
        if (rc=Pfunc(fpath,pudirlist,Pparm),rc)                    //~v5d7R~
            break;                                              //~5916I~
    }//dir list                                                 //~5916I~
//  ufree(pudirlist0);                                          //~5916I~//~v6qaR~
    UDIRLIST_FREE(pudirlist0);                                     //~v6qaI~
    if (swtoolong)                                                //~v6H1I~
    	rc|=UWFRC_LONGNAME;                                        //~v6H1I~
    return rc;                                                  //~5916I~
}//uwildfunc                                                    //~5916R~
//****************************************************************//~5B12I~
//ufilecdirchk                                                  //~5B12I~
//* chk cur dir is on delete path                               //~5B12I~
//*parm1:delete file                                            //~5B12I~
//*retrn:rc 1:cur dir is on the path of parm ,0 not on the path //~5B12R~
//****************************************************************//~5B12I~
int ufilecdirchk(UCHAR *Pfullpath)                              //~5B12I~
{                                                               //~5B12I~
    int len1,len2;                                              //~5B12I~
//  UCHAR cpath[_MAX_PATH];                                     //~5B12I~//~v6H1R~
//  UCHAR rpath[_MAX_PATH];                                        //~v5cpI~//~v6H1R~
    UCHAR cpath[FTP_MAXPATH];                                      //~v6H1I~
    UCHAR rpath[FTP_MAXPATH];                                      //~v6H1I~
    int rc;                                                        //~v017R~
    char *wildsw;                                                  //~v017I~
#ifdef FTPSUPP                                                     //~v5akI~
  #ifdef W32                                                       //~v5apI~
	int remotesw;                                                  //~v5akI~
  #endif                                                           //~v5apI~
    PUFTPHOST puftph;                                              //~v5apI~
    int len;                                                       //~v5apI~
#endif                                                             //~v5akI~
//********************                                          //~5B12I~
#ifdef FTPSUPP                                                     //~v5akI~
  if (uftpisremote(Pfullpath,&puftph))                             //~v5apR~
  {                                                                //~v5akI~
  #ifdef W32                                                       //~v5apI~
  	remotesw=1;                                                    //~v5akI~
  #endif                                                           //~v5apI~
//  if (!ufullpath(cpath,"." FTP_DIR_SEPS,_MAX_PATH))              //~v5apR~
//        return -1;                                               //~v5apR~
    len=puftph->UFTPHhostnmlen;                                    //~v5apR~
    memcpy(cpath,puftph->UFTPHhost,(UINT)len);                     //~v5apI~
    *(cpath+len++)=FTP_REMOTEID;                                   //~v5apI~
    strcpy(cpath+len,puftph->UFTPHcwd);                            //~v5apI~
  }                                                                //~v5akI~
  else                                                             //~v5akI~
  {                                                                //~v5akI~
  #ifdef W32                                                       //~v5apI~
  	remotesw=0;                                                    //~v5akI~
  #endif                                                           //~v5apI~
#endif                                                             //~v5akI~
    if (!ufullpath(cpath,"." DIR_SEPS,_MAX_PATH))                  //~v327I~
        return -1;                                              //~5B12I~
#ifdef FTPSUPP                                                     //~v5akI~
  }                                                                //~v5akI~
#endif                                                             //~v5akI~
    len1=(int)strlen(cpath);                                    //~5B12I~
    if (wildsw=WILDCARD(Pfullpath),wildsw)         //source wild card//~v017R~
    {                                                           //~5B12I~
        len2=PATHLEN(Pfullpath);                                //~5B12I~
//      if (len2!=3)    //not root                                 //~v5cpR~
//          len2--;     //drop last \ of PATHLEN                   //~v5cpR~
        memcpy(rpath,Pfullpath,(UINT)len2);                        //~v5cpI~
        *(rpath+len2)=0;                                           //~v5cpI~
        if (!ROOTDIR3(rpath))                                      //~v5cpI~
            len2--;                                                //~v5cpI~
    }                                                           //~5B12I~
    else                                                        //~5B12I~
        len2=(int)strlen(Pfullpath);                            //~5B12I~
    if (len1<len2)      //cdir is upper level                   //~5B12I~
        return 0;                                               //~5B12I~
#ifdef UNX                                                         //~v393I~
    if (rc=!memcmp(cpath,Pfullpath,(UINT)len2),rc)//on if match    //~v393I~
#else  //!UNX                                                      //~v393I~
  #ifdef FTPSUPP    //w32                                          //~v5akI~
  	if (remotesw)                                                  //~v5akI~
    	rc=!memcmp(cpath,Pfullpath,(UINT)len2);                    //~v5akI~
    else                                                           //~v5akI~
    	rc=!memicmp(cpath,Pfullpath,(UINT)len2);                   //~v5akI~
    if (rc)                                                        //~v5akI~
  #else                                                            //~v5akI~
    if (rc=!memicmp(cpath,Pfullpath,(UINT)len2),rc)//on if match//~5B12R~
  #endif                                                           //~v5akI~
#endif //!UNX                                                      //~v393I~
    {                                                              //~v017I~
        if (len1>len2       //cdir may included                 //~5B12I~
#ifdef W32                                                         //~v5akI~
        &&  *(cpath+len2)!=FTP_DIR_SEPC    //remote seperator      //~v5akI~
#endif                                                             //~v5akI~
        &&  *(cpath+len2)!=DIR_SEPC)    //not same path name       //~v327R~
            rc=0;                                               //~5B12I~
        if (len1==len2      //same dir                             //~v017I~
        &&  wildsw)         //but in the cur dir                   //~v017I~
            rc=0;                                                  //~v017I~
    }                                                              //~v017I~
    return rc;                                                  //~5B12I~
}//ufilecdirchk                                                 //~5B12I~
                                                                //~5B12I~
//**************************************************************** //~v085I~
//ufilespfnchk                                                     //~v085I~
//* chk special file name to prevent rename/reset r-only           //~v085I~
//*    "d:\____. SF" is prohibit when d is not A nor B.            //~v085I~
//*    "d:\____. SF\___" is not prohibitted                        //~v085I~
//*parm1:file name,expect fullpath                                 //~v085I~
//*parm2:operation 1:rename,2:attrib                               //~v085I~
//*retrn:rc 1:prohibitted file,0:not prohibitted                   //~v085I~
//**************************************************************** //~v085I~
int ufilespfnchk(UCHAR *Pfname,int Pop)                            //~v085I~
{                                                                  //~v085I~
#ifdef UNX                                                         //~v350I~
#else  //!UNX                                                      //~v350I~
    int drive;                                                     //~v085I~
    char *pc;                                                      //~v085I~
#endif //!UNX                                                      //~v350I~
//********************                                             //~v085I~
#ifdef UNX                                                         //~v350I~
        return 0;                                                  //~v350I~
#else  //!UNX                                                      //~v350I~
#ifdef FTPSUPP                                                     //~v5akI~
	if (uftpisremote(Pfname,0))                                    //~v5akI~
    	return 0;                                                  //~v5akI~
#endif                                                             //~v5akI~
    if (*(Pfname+1)!=':' || *(Pfname+2)!=DIR_SEPC)                 //~v327I~
        return 0;                                                  //~v085I~
    drive=toupper(*Pfname);                                        //~v085R~
    if (drive=='A' || drive=='B')                                  //~v085R~
        return 0;                                                  //~v085R~
    if (!(pc=ustrstri(Pfname+2,". SF")))                           //~v085I~
        return 0;                                                  //~v085I~
    if (*(pc+4))                    //not last name                //~v085I~
        return 0;                                                  //~v085I~
    if (ustrchr2(Pfname+3,DIR_SEPC))    //not root dir             //~v327I~
        return 0;                                                  //~v085I~
    return 1;                                                      //~v085I~
#endif //!UNX                                                      //~v350I~
}//ufilespfnchk                                                    //~v085I~
//**********************************************************************//~v6q0M~
//*  chk wildcard name                                             //~v6q0M~
//*  parm1:dir name                                                //~v6q0M~
//*  parm2:fullpathname,0 if dir entry,or empty call               //~v6q0M~
//*  parm3:PUDIRLIST,0 if empty entry                              //~v6q0M~
//*  parm4:depth                                                   //~v6q0M~
//*  parm5:appl data                                               //~v6q0M~
//*  parm6:appl rc area                                            //~v6q0M~
//*  return:0:continue walk,else stop walk                         //~v6q0M~
//**********************************************************************//~v6q0M~
int wildchk(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,       //~v6q0M~
                                int Pdepth,void *Pdata,int *Prc)   //~v6q0M~
{                                                                  //~v6q0M~
	int rc=0,opt;                                                  //~3B26R~//~v6q0M~
    PWCPARMWC puparm;                                              //~3B26R~//~v6q0M~
#ifdef W32                                                         //~v6q1I~
//  char wkfpath[_MAX_PATH];                                       //~v6q1R~//~v6H6R~
    char wkfpath[_MAX_PATH2];                                      //~v6H6R~
#endif                                                             //~v6q1I~
    char *pfpath;                                                  //~v6q1I~
//**************************                                       //~v6q0M~
#ifdef W32                                                         //~v6q0I~
	UTRACEP("wildchk Pdir=%s,Pfullpath=%s,name=%s,alias=%s\n",Pdir,Pfullpath,Ppudirlist->name,Ppudirlist->alias);//~3B26R~//~v6q0M~
#else                                                              //~v6q0I~
	UTRACEP("wildchk Pdir=%s,Pfullpath=%s,name=%s\n",Pdir,Pfullpath,Ppudirlist->name);//~v6q0I~
#endif                                                             //~v6q0I~
    puparm=(WCPARMWC*)(ULPTR)Pdata;                                //~3B26R~//~v6q0M~
    opt=puparm->wcopt;                                             //~3B26R~//~v6q0M~
    puparm->wcchkctr++;                                            //~v6q0I~
    if (WILDCARD(Ppudirlist->name)) //contains the case of widthout alias set//~v6q1R~
    {                                                              //~3B26I~//~v6q0M~
        puparm->wcctr++;                                           //~3B26R~//~v6q0M~
    	if (!Pfullpath)	//dir entry                                //~3B26I~//~v6q0M~
        {                                                          //~3B26I~//~v6q0M~
            pfpath=Pdir;                                           //~v6q1I~
#ifdef W32                                                         //~v6q1I~
    		if (FILE_IS_WILDNAME(Ppudirlist->attr)	//alias was set//~v6q1I~
            &&  opt & WCWCO_DIGBYALIAS)                            //~v6q1R~
            {                                                      //~v6q1I~
                strcpy(wkfpath,Pdir);                              //~v6q1M~
                strcpy(wkfpath+strlen(wkfpath)-strlen(Ppudirlist->alias),Ppudirlist->name);//recover wildname//~v6q1M~
            	pfpath=wkfpath;                                    //~v6q1I~
            }                                                      //~v6q1I~
            else                                                   //~v6q1I~
			rc=UDIRWALK_URC_SKIPDIR; //user requested skip this dir//~v56mI~//~3B26M~//~v6q0M~
#endif                                                             //~v6q1M~
		    if (opt & WCWCO_XFF)  	 //xff fmt msg                 //~v6q0I~
//          	puparm->wcpfunc(Pdir,Pfullpath,Ppudirlist,puparm); //~v6q0R~//~v6q1R~
            	puparm->wcpfunc(pfpath,Pfullpath,Ppudirlist,puparm);//~v6q1I~
            else                                                   //~v6q0I~
#ifdef W32                                                         //~v6q0I~
		    if (opt & WCWCO_MSG)                                  //~3B26I~//~v6q0R~
	        	uerrmsg("%s\\ (alias:%s)\n",0,                      //~3B26R~//~v6q0R~
//  					Pdir,Ppudirlist->alias);                   //~3B26I~//~v6q0M~//~v6q1R~
    					pfpath,Ppudirlist->alias);                 //~v6q1I~
#else                                                              //~v6q0I~
	        	uerrmsg("%s\\\n",0,                                //~v6q0I~
//  					Pdir);                                     //~v6q0I~//~v6q1R~
    					pfpath);                                   //~v6q1I~
#endif                                                             //~v6q0I~
            if (!*puparm->wcfnm)                                   //~3B26I~//~v6q0M~
//          	strcpy(puparm->wcfnm,Pdir);                        //~3B26I~//~v6q0M~//~v6q1R~
            	strcpy(puparm->wcfnm,pfpath);                      //~v6q1I~
        }                                                          //~3B26I~//~v6q0M~
        else                                                       //~3B26I~//~v6q0M~
        {                                                          //~3B26I~//~v6q0M~
		    if (opt & WCWCO_XFF)  	 //xff fmt msg                 //~v6q0I~
            	puparm->wcpfunc(Pdir,Pfullpath,Ppudirlist,puparm); //~v6q0R~
            else                                                   //~v6q0I~
#ifdef W32                                                         //~v6q0I~
		    if (opt & WCWCO_MSG)                                  //~3B26I~//~v6q0R~
	        	uerrmsg("%s (alias:%s)\n",0,                        //~3B26R~//~v6q0R~
						Pfullpath,Ppudirlist->alias);              //~3B26R~//~v6q0M~
#else                                                              //~v6q0I~
	        	uerrmsg("%s\n",0,                                  //~v6q0I~
						Pfullpath);                                //~v6q0I~
#endif                                                             //~v6q0I~
            if (!*puparm->wcfnm)                                   //~3B26I~//~v6q0M~
            	strcpy(puparm->wcfnm,Pfullpath);                   //~3B26I~//~v6q0M~
        }                                                          //~3B26I~//~v6q0M~
    }                                                              //~3B26I~//~v6q0M~
    *Prc=0;	//applrc                                               //~v6q0M~
	return rc;                                                     //~v6q0M~
}//wildchk                                                         //~v6q0M~
//*********************************************************************//~v6q0M~
//* chk wildname member                                            //~v6q0M~
//* return 0:                                                      //~v6q0M~
//*********************************************************************//~v6q0M~
int ufilechkwildmemb(char *Pfnm,PWCPARMWC Ppuparm)                 //~3B26R~//~v6q0R~
{                                                                  //~v6q0M~
    int dwopt;                                                     //~v100R~//~v6q0M~
    int applrc,rc;                                                 //~3B26R~//~v6q0M~
    UCHAR *dirpath,*dirmask,*filemask;                             //~3B26R~//~v6q0M~
	int    depth=32767;             //serach subdir option         //~v6q0M~
	int    attrmask;                                               //~v6q0R~
//**********************************                               //~v6q0M~
    dwopt=UDIRWALK_NOMSG            //no err msg                   //~v6q0M~
			|UDIRWALK_FILECALL      //callback by each file        //~v6q0M~
    	    |UDIRWALK_DIRCALL                                      //~v6q0M~
    	    |UDIRWALK_SKIPSLINK;                                 //~v116I~//~v6q0M~
    if (Ppuparm->wcopt & WCWCO_DIGBYALIAS)                         //~v6q1R~
    	dwopt|=UDIRWALK_DIGBYALIAS;                                //~v6q1R~
    dirpath=Pfnm;                                                  //~v6q0M~
    dirmask="";                                                    //~3B26R~//~v6q0M~
    if (Ppuparm->wcopt & WCWCO_DEPTH)                              //~v6q0R~
    	depth=Ppuparm->wcdepth;                                    //~v6q0I~
    if (Ppuparm->wcopt & WCWCO_FILEMASK)                           //~v6q0I~
	    filemask=Ppuparm->wcfilemask;                              //~v6q0I~
    else                                                           //~v6q0I~
	    filemask="";                                                   //~3B26R~//~v6q0R~
	attrmask=FILE_ALL;                                             //~v6q0R~
    Ppuparm->wcctr=0;	//wildname ctr                                      //~3B26R~//~v6q0R~
    Ppuparm->wcchkctr=0;	//checked file ctr                     //~v6q0I~
    *Ppuparm->wcfnm=0;	//1st fnm                                  //~3B26R~//~v6q0M~
                                                                   //~v6q0I~
    rc=udirwalk(dwopt,                                             //~3B26R~//~v6q0M~
    				dirpath,                 //top dirname         //~v127I~//~v6q0M~
    				dirmask,		//no dir mask                  //~v127I~//~v6q0M~
    				filemask,				//file mask            //~v128I~//~v6q0M~
					attrmask,		//attr mask                    //~v6q0M~
                    depth, 		//stop depth,default is half max//~v113I~//~v6q0M~
					wildchk,		//callback function            //~v6q0M~
					Ppuparm,  			//user data                //~3B26R~//~v6q0M~
					&applrc);                                      //~v6q0M~
    return rc;                                                     //~3B26R~//~v6q0M~
}//ufilechkwildmem                                                 //~v6q0R~
//*********************************************************************//~v6q0I~
//* chk wildname member                                            //~v6q0I~
//* return 4:wildcard filename err                                 //~v6q0I~
//*********************************************************************//~v6q0I~
int ufilechkwildname(int Popt,char *Pfnm,int *Ppctr)               //~v6q0R~
{                                                                  //~v6q0I~
    FILEFINDBUF3 ffb3;                                             //~v6q0I~
	WCPARMWC uparm;                                                //~v6q0I~
//**********************************                               //~v6q0I~
    if (ufstat(Pfnm,&ffb3))                                        //~v6q0I~
    	return 0;	//other err                                    //~v6q0I~
    if (!UCBITCHK(ffb3.attrFile,FILE_DIRECTORY))                   //~v6q0I~
    	return 0;	//other err                                    //~v6q0I~
    uparm.wcopt=0;	//no entry msg                                 //~v6q0I~
	ufilechkwildmemb(Pfnm,&uparm);                                 //~v6q0I~
    if (Ppctr)                                                     //~v6q0I~
    	*Ppctr=uparm.wcctr;                                        //~v6q0I~
    if (!uparm.wcctr)                                              //~v6q0I~
    	return 0;	//other err                                    //~v6q0I~
    if (Popt & CWMO_ERRMSG)                                        //~v6q0I~
    {                                                              //~v6q0I~
    	if (Popt & CWMO_RENAME)                                    //~v6q0I~
  			uerrmsg("%s contains %d wildcard name member. 1st:%s\n",0,//~v6q0I~
            		Pfnm,uparm.wcctr,uparm.wcfnm);                 //~v6q0I~
    }                                                              //~v6q0I~
    return 4;                                                      //~v6q0I~
}//ufilechkwildname                                                //~v6q0R~
//*********************************************************************//~v6B1I~
//* open with mode exclusive write                                 //~v6B1I~
//* Windows: fopen("w") protect deletion by other process(permission error)//~v6B1I~
//* Linux:flock/fnctl lock is advisory lock,other process can ignore the lock.//~v6B1I~
//*       so simply open(filename has pid extension to avoid mixed write).//~v6B1I~
//*********************************************************************//~v6B1I~
#ifdef W32                                                         //~v6B1I~
FILE *ufileopenexclusivewrite(int Popt,char *Pfnm,PHANDLE *Pphandle)//~v6B1R~
#else                                                              //~v6B1I~
FILE *ufileopenexclusivewrite(int Popt,char *Pfnm,int *Pphandle)   //~v6B1I~
#endif                                                             //~v6B1I~
{                                                                  //~v6B1I~
	FILE *pfh;                                                     //~v6B1I~
    int interrno;                                                  //~v6B1M~
    char *pstrerrno;                                               //~v6B1M~
#ifdef W32                                                         //~v6B1I~
    HANDLE fh=0;                                                   //~v6B1R~
#else //!WIN                                                       //~v6B1I~
	int fh=0;                                                      //~v6B1I~
#endif                                                             //~v6B1I~
//**********************************                               //~v6B1I~
#ifdef W32                                                         //~v6B1I~
//    fh=uCreateFileNative(Pfnm,                                   //~v6B1R~
//                    GENERIC_WRITE,      //access                 //~v6B1R~
//                    FILE_SHARE_READ,    //share                  //~v6B1R~
//                    0,                  //security               //~v6B1R~
//                    OPEN_ALWAYS,        //how to create          //~v6B1R~
//                    FILE_NORMAL,        //attr                   //~v6B1R~
//                    NULL);                 //template handle     //~v6B1R~
//    if (fh==INVALID_HANDLE_VALUE)  //failed                      //~v6B1R~
//    {                                                            //~v6B1R~
//        pstrerr=ugetlasterror(&err);                             //~v6B1R~
//        fprintf(stderr,"CreateFile exclusive write for %s lasterr=%d(%s)\n",Pfnm,err,pstrerr);//~v6B1R~
//    }                                                            //~v6B1R~
    pfh=ufopenNative(Pfnm,"w"); //fopen protect from delete        //~v6B1R~
    if (!pfh)                                                      //~v6B1I~
    {                                                              //~v6B1I~
        interrno=errno;                                            //~v6B1R~
//  	pstrerr=ugetlasterror(&err);                               //~v6B1R~
		pstrerrno=strerror(interrno);                              //~v6B1R~
    	fprintf(stderr,"ufilefopenexclusivewrite:fopen failed for %s errno=%d(%s)\n",Pfnm,interrno,pstrerrno);//~v6B1R~
    }                                                              //~v6B1I~
    if (Pphandle)                                                  //~v6B1R~
    	*Pphandle=fh;                                              //~v6B1I~
#else //!WIN                                                       //~v6B1I~
    pfh=fopen(Pfnm,"w");                                           //~v6B1I~
    if (!pfh)                                                      //~v6B1I~
    {                                                              //~v6B1I~
        interrno=errno;                                            //~v6B1I~
		pstrerrno=strerror(interrno);                              //~v6B1I~
    	fprintf(stderr,"ufilefopenexclusivewrite:fopen failed for %s errno=%d(%s)\n",Pfnm,interrno,pstrerrno);//~v6B1R~
    }                                                              //~v6B1I~
    if (Pphandle)                                                  //~v6B1I~
    	*Pphandle=fh;                                              //~v6B1I~
    uflock(0,Pfnm,0/*Ppfd at close*/);                             //~v6W4R~
#endif                                                             //~v6B1I~
    return pfh;                                                    //~v6B1I~
}//ufileopenexclusivewrite                                         //~v6W4R~
//*********************************************************************//~v6B1I~
//* delete file if writable(not exclusively write open)            //~v6B1I~
//*********************************************************************//~v6B1I~
int ufiledelifnotopened(int Popt,char *Pfnm,int Ppid)              //~v6B1R~
{                                                                  //~v6B1I~
    int rc;                                                        //~v6B1R~
    int interrno;                                                  //~v6B1R~
    char *pstrerrno;                                               //~v6B1R~
#ifdef W32                                                         //~v6B1I~
#else                                                              //~v6B1I~
#ifdef AAA                                                         //~v6W4I~
	char pathproc[32];                                             //~v6B1I~
#endif                                                             //~v6W4I~
    int fd,swlocked;                                               //~v6W4I~
#endif                                                             //~v6B1I~
//**********************************                               //~v6B1I~
#ifdef W32                                                         //~v6B1I~
//    fh=uCreateFileNative(Pfnm,                                   //~v6B1R~
//                    GENERIC_WRITE,      //access                 //~v6B1R~
//                    FILE_SHARE_READ,    //share                  //~v6B1R~
//                    0,                  //security               //~v6B1R~
//                    OPEN_EXISTING,      //how to create          //~v6B1R~
//                    FILE_NORMAL,        //attr                   //~v6B1R~
//                    NULL);                 //template handle     //~v6B1R~
//    if (fh!=INVALID_HANDLE_VALUE)  //success                     //~v6B1R~
//    {                                                            //~v6B1R~
//        CloseHandle(fh);                                         //~v6B1R~
//        rc=GetLastError();                                       //~v6B1R~
//        rc=uremove(Pfnm);                                        //~v6B1R~
//    }                                                            //~v6B1R~
//    else                                                         //~v6B1R~
//    {                                                            //~v6B1R~
//        pstrerr=ugetlasterror(&err);                             //~v6B1R~
//        fprintf(stderr,"CreateFile shared read to delete for %s lasterr=%d(%s)\n",Pfnm,err,pstrerr);//~v6B1R~
//    }                                                            //~v6B1R~
	rc=remove(Pfnm);	//use native to avoid call UTRACE          //~v6B1R~
    if (rc)                //err                                   //~v6B1R~
    {                                                              //~v6B1I~
        interrno=errno;                                            //~v6B1I~
		pstrerrno=strerror(interrno);                              //~v6B1I~
    	fprintf(stderr,"ufiledelifnotopened:remove failed for %s errno=%d(%s)\n",Pfnm,interrno,pstrerrno);//~v6B1I~
    }                                                              //~v6B1I~
#else //!WIN                                                       //~v6B1I~
#ifdef AAA                                                         //~v6W4I~
	sprintf(pathproc,"/proc/%d",Ppid);                             //~v6B1I~
	rc=(int)ufstat(pathproc,0/*no ffb3*/);                         //~v6B1R~
    if (rc==ENOENT)  //not fount                                   //~v6B1I~
#else                                                              //~v6W4I~
	swlocked=uflock(0,Pfnm,&fd)==0;	                               //~v6W4R~
//  UTRACEP("%s:swlocked=%d\n",UTT,swlocked);                      //~v6W4R~
    if (fd>0)                                                      //~v6W4I~
		uflock(UFLO_CLOSE,Pfnm,&fd);                               //~v6W4R~
	if (swlocked)                                                  //~v6W4R~
#endif                                                             //~v6W4I~
    {                                                              //~v6B1I~
        rc=unlink(Pfnm);   //-1 if err,0:ok                        //~v6B1R~
        if (rc<0)             //err                                //~v6B1R~
        {                                                          //~v6B1R~
            interrno=errno;                                        //~v6B1R~
            pstrerrno=strerror(interrno);                          //~v6B1R~
            fprintf(stderr,"ufiledelifnotopened:unlink failed for %s errno=%d(%s)\n",Pfnm,interrno,pstrerrno);//~v6B1R~
        }                                                          //~v6B1R~
    }                                                              //~v6B1I~
#endif                                                             //~v6B1I~
    return rc;                                                     //~v6B1I~
}//ufiledelifnotopened                                             //~v6B1I~
//*********************************************************************//~v6G7I~
//* delete file if writable(not exclusively write open)            //~v6G7I~
//*********************************************************************//~v6G7I~
void ufile2quietmsg(int Popt,char *Pfile)                          //~v6G7R~
{                                                                  //~v6G7I~
	if (Squietctr)                                                 //~v6G7I~
    {                                                              //~v6G7I~
		if (Sxdeldctr && (Sxdeldctr==1 || !(Sxdeldctr%Squietctr)))    //deleted ctr//~v6G7R~
        {                                                          //~v6G7I~
        	if (Squiettotalctr)	//readonly chk done                //~v6G7I~
				uerrmsg("%2d%% (%d/%d) deleted (%s)",              //~v6G7R~
						"%2d%% (%d/%d) 削除 (%s)",                 //~v6G7R~
                        (Sxdeldctr*100)/Squiettotalctr,Sxdeldctr,Squiettotalctr,Pfile);//~v6G7R~
            else                                                   //~v6G7I~
				uerrmsg("%d deleted (%s)",                         //~v6G7I~
						"%d 削除 (%s)",                            //~v6G7I~
                        Sxdeldctr,Pfile);                          //~v6G7I~
        }                                                          //~v6G7I~
    }                                                              //~v6G7I~
}//ufile2quietmsg                                                  //~v6G7I~
//*********************************************************************//~v6H1I~
//* del dir containning too long filename                          //~v6H1I~
//* rc:4 could not rename                                          //~v6H1I~
//*********************************************************************//~v6H1I~
int ugetmoveavailablepath(int Popt,UCHAR *Psource,UINT Pattrmask,char *Ppath,int Pbuffsz)//~v6H1I~
{                                                                  //~v6H1I~
	int rc=4,swfound=0,pathlen,ii,rc2,len;                           //~v6H1R~//~v6H6R~
//  char fpathsrc[_MAX_PATH],*psrc,*pc,*pce,*pcn;                  //~v6H1R~//~v6H9R~
//  char fpath[_MAX_PATH];                                         //~v6H1I~//~v6H9I~
//  char fpathok[_MAX_PATH];                                       //~v6H1I~//~v6H9I~
    char fpathsrc[_MAX_PATH_LONG],*psrc,*pc,*pce,*pcn;             //~v6H9I~
    char fpath[_MAX_PATH_LONG];                                    //~v6H9I~
    char fpathok[_MAX_PATH_LONG];                                  //~v6H9I~
//******************                                               //~v6H1I~
	UTRACEP("%s:source=%s\n",UTT,Psource);                         //~v6H1I~
    psrc=Psource;                                                  //~v6H1I~
	UstrncpyZ(fpath,psrc,sizeof(fpath));                           //~v6H1I~
    pathlen=PATHLEN(fpath);                                        //~v6H1I~
    if (pathlen<0)                                                 //~v6H1I~
        return 4;                                                  //~v6H1I~
    if (WILDCARD(fpath+pathlen))                                   //~v6H1I~
    {                                                              //~v6H1I~
        *(fpath+pathlen-1)=0;                                      //~v6H1I~
		UstrncpyZ(fpathsrc,fpath,sizeof(fpathsrc));                //~v6H1I~
    }                                                              //~v6H1I~
    else                                                           //~v6H1I~
		UstrncpyZ(fpathsrc,fpath,sizeof(fpathsrc));                //~v6H1I~
    psrc=fpathsrc;                                                 //~v6H1R~
    for (pc=fpath,pce=pc+strlen(pc);;)                             //~v6H1R~
    {                                                              //~v6H1I~
		UTRACEP("%s:pc=%s\n",UTT,pc);                              //~v6H1R~
//  	pcn=ustrchr2(pc,DIR_SEPC);                                 //~v6H1R~
    	pcn=ustrnchr2(pc,DIR_SEPC,(size_t)PTRDIFF(pce,pc));        //~v6H1R~
    	if (!pcn)                                                  //~v6H1R~
    		break;                                                 //~v6H1I~
    	if (!*(pcn+1))                                             //~v6H1I~
    		break;                                                 //~v6H1I~
        len=PTRDIFF(pcn,fpath)+1;                                  //~v6H1R~
        memcpy(fpathok,psrc,(size_t)len);                          //~v6H1R~
        strcpy(fpathok+len,TEMPDIR_FOR_DELETE_LONGNAME);           //~v6H1R~
		UTRACEP("%s:tempdir=%s\n",UTT,fpathok);                    //~v6H1R~
        if (strlen(fpathok)>=strlen(psrc))	//rename success when same name//~v6H1R~
        	break;                                                 //~v6H1I~
        if (!ufstat(fpathok,0))                                    //~v6H9R~
        	rc2=EEXIST;                                            //~v6H9I~
        else                                                       //~v6H9I~
    		rc2=urenamenomsg(psrc,fpathok,0);	//with errmsg      //~v6H9R~
        UTRACEP("%s:rename rc=%d for fpath=%s\n",UTT,rc2,fpathok); //~v6H1R~
        if (rc2==EEXIST)                                                   //~v6H1I~//~v6H9R~
        {                                                          //~v6H1I~
        	swfound=0;                                             //~v6H1I~
    		if (rc2!=EPERM //operation not permit                  //~v6H1I~
    		&&  rc2!=EACCES)                                       //~v6H1I~
        	for (ii=0;ii<TEMPDIR_FOR_DELETE_LONGNAME_MAXRETRY;ii++)//~v6H1I~
            {                                                      //~v6H1I~
		        sprintf(fpathok+len,"%s%d",TEMPDIR_FOR_DELETE_LONGNAME,ii);//~v6H1R~
        		UTRACEP("%s:rename try fpath=%s\n",UTT,fpathok);   //~v6H1R~
		        if (strlen(fpathok)>=strlen(psrc))	//rename success when same name//~v6H1I~
        			break;                                         //~v6H1I~
		        if (!ufstat(fpathok,0))                            //~v6H9R~
        			rc2=EEXIST;                                    //~v6H9I~
        		else                                               //~v6H9I~
		    		if (!urenamenomsg(psrc,fpathok,0))	//not found    //~v6H1R~//~v6H9R~
                	{                                                  //~v6H1I~//~v6H9R~
	        			UTRACEP("%s:rename try ok for fpath%d\n",UTT,fpathok);//~v6H1R~//~v6H9R~
                		swfound=1;                                     //~v6H1I~//~v6H9R~
                		break;                                         //~v6H1I~//~v6H9R~
                	}                                                  //~v6H1I~//~v6H9R~
            }                                                      //~v6H1I~
        }                                                          //~v6H1I~
        else                                                       //~v6H9I~
            if (!rc2)                                              //~v6H9I~
            	swfound=1;                                         //~v6H9I~
        if (swfound)                                               //~v6H1I~
        	break;                                                 //~v6H1I~
        *pcn=DIR_SEPC;                                             //~v6H1R~
        pc=pcn+1;                                                  //~v6H1I~
    }                                                              //~v6H1I~
    if (swfound)                                                   //~v6H1R~
    {                                                              //~v6H1I~
    	strcpy(Ppath,fpathok);                  //~v6H1I~          //~v6H9R~
       	if (Sxdelopt & UXDELMSG) //msg put option                  //~v6H1I~
        	uerrmsg("renamed to delete long pathname %s <-- %s",   //~v6H1R~
            	    "削除のため長すぎるパスを改名 %s <- %s",       //~v6H1R~
	                fpathok,fpathsrc);                             //~v6H1R~
        rc=0;                                                      //~v6H1I~
    }                                                              //~v6H1I~
    else                                                           //~v6H1I~
    {                                                              //~v6H1I~
        uerrmsg("renamed to delete long pathname failed.(%s)",     //~v6H1I~
            	    "削除のための長すぎるパスの改名ができません(%s)",//~v6H1I~//~v6H9R~
	                fpathsrc);                                     //~v6H1I~
        rc=4;                                                      //~v6H1I~
    }                                                              //~v6H1I~
	UTRACEP("%s:rc=%d,out=%s\n",UTT,rc,Ppath);                     //~v6H1I~
    return rc;                                                     //~v6H1I~
}//ugetmoveavailablepath                                           //~v6H1I~
//*********************************************************************//~v6H1I~
//* del dir containning too long filename                          //~v6H1I~
//*********************************************************************//~v6H1I~
int uwildfunc_LongName(int Popt,UCHAR *Psource,ULONG Pattr,unsigned Pattrmask,WILDAPPLYFUNC *Pfunc,void *Pparm,/*int *Pfilectr,*/char *Pfpathrename)//~v6H1R~
{                                                                  //~v6H1I~
	int rc=0;                                                      //~v6H1R~
//  char fpath[_MAX_PATH+8];                                       //~v6H1R~//~v6H9R~
    char fpath[_MAX_PATH_LONG+8];                                  //~v6H9I~
#ifdef AAA                                                         //~v6H1I~
    char fpath2[_MAX_PATH+8];                                      //~v6H1M~
    int ii;                                                        //~v6H1I~
	int filectr;                                                   //~v6H1I~
#endif                                                             //~v6H1I~
//******************                                               //~v6H1I~
	if (!ugetmoveavailablepath(0,Psource,Pattrmask,fpath,(int)_MAX_PATH))//~v6H1R~
    {                                                              //~v6H1I~
    	strcpy(Pfpathrename,fpath);                                //~v6H1I~
#ifdef AAA                                                         //~v6H1R~
        if (!ROOTDIR(fpath))                                       //~v6H1R~
            strcat(fpath,DIR_SEPS);                                //~v6H1I~
        strcat(fpath,DIR_ALLMEMB);                                 //~v6H1R~
    	rc=uwildfunc(Popt,fpath,Pattrmask,Pfunc,Pparm,&filectr);   //~v6H1I~
		if (rc & UWFRC_LONGNAME)       //over _MAX_PATH,could not delete//~v6H1I~
        {                                                          //~v6H1I~
        	for (ii=0;ii<10;ii++)                                  //~v6H1I~
            {                                                      //~v6H1I~
			    *Pfilectr+=filectr;                                //~v6H1I~
                filectr=0;                                         //~v6H1I~
				if (ugetmoveavailablepath(0,fpath,Pattrmask,fpath2,(int)_MAX_PATH))//~v6H1I~
                	break;                                         //~v6H1I~
                rc=uwildfunc(Popt,fpath2,Pattrmask,Pfunc,Pparm,&filectr);//~v6H1I~
                if (!(rc & UWFRC_LONGNAME))       //over _MAX_PATH,could not delete//~v6H1I~
                {                                                  //~v6H1I~
                    rc=0;                                          //~v6H1I~
                    break;                                         //~v6H1I~
                }                                                  //~v6H1I~
                strcpy(fpath,fpath2);                              //~v6H1I~
            }                                                      //~v6H1I~
            if (rc)                                                //~v6H1I~
                rc=UWFRC_LONGNAMEERR;       //over _MAX_PATH,could not delete//~v6H1I~
        }                                                          //~v6H1I~
#else                                                              //~v6H1I~
//      Sxdelfctr--;    //dup at uxdelsub top ++                   //~v6H1I~//~v6H9R~
//      printf("uwildfunc_Longname delfctr=%d %s\n",Sxdelfctr,fpath); //@@@@test//~v6H9R~
		rc=uxdelsub(fpath,Pattr,Pattrmask,1,0/*Psize*/);           //~v6H1I~
#endif                                                             //~v6H1R~
    }                                                              //~v6H1I~
    else	//no path avail                                        //~v6H1I~
		rc=UWFRC_LONGNAMEERR;       //over _MAX_PATH,could not delete//~v6H1I~
#ifdef AAA                                                         //~v6H1I~
    *Pfilectr+=filectr;                                            //~v6H1R~
#endif                                                             //~v6H1I~
    return rc;                                                     //~v6H1I~
}//uwildfunc_LongName                                              //~v6H1I~
