//*CID://+v786R~:                             update#=  605;       //~v786R~
//*************************************************************
//*ufile1l.c                                                       //~v59nR~
//*************************************************************
//v786:230724 ARM:try to set env:PWD by cd for file parameter of tools//~v786I~
//v785:230722 ARM:xopy loop when src is wildcard                   //~v785I~
//v784:230721 ARM:xdelete; no entry msg and successefull when 0 member//~v784I~
//v783:230721 (Bug) v781 not fix it. ignore "." entry              //~v783I~
//v782:230720 ARM;delete dir return no entry for also fileAll except //SP dir( internal folder such as myhome returns '.' for readdir)//~v782I~
//v780:230719 ARM;delete dir return no entry(findnext from findfirst returns no entry)//~v780I~
//v77Z:230718 ARM;support CD to shared storage                     //~v7ZAI~
//v77A:230602 ARM;share storage readdir returns no entry of "." or ".." and issue "no entry", the dirlist was not show. set rc=0 to show list by xedir:loaddir//~v77AI~
//v77w:230519 uri-->path is avalable from api30(android11:R) and readdir using fd gotten by openDescriptor returns null//~v77wI~
//v77u:230513 ARM:reject CD cmd with errmsg                        //~v77uI~
//v77r:230507 ARM:issue invalid shortpath name msg                 //~v77rI~
//v77q:230503 ARM:assume device charset as utf8                    //~v77qI~
//v77m:230429 ARM:try stat(fpath) by fstat(fd) for ufstat          //~v77mI~
//v77k:230428 Lnx:wildname warning issued even if not selected by wildcard selection.//~v77kI~
//v77d:230423 ARM;delete                                           //~v77dI~
//v779:230414 update v777,set uri at ulib fro shortpath            //~v779I~
//v777:230403 ARM;udirlistFD                                       //~v777I~
//v70n:200902 (ARM)$tmp as shortcut to /data/local/tmp             //~v70bI~
//v70b:200616 ARM:use /sdcard for /emultate/legacy/..              //~v70bI~
//v703:200615 ARM coding bug                                       //~v703R~
//v6H2:170103 (BUG)uparsefname cut last 1 byte for len=259(_MAX_MATH-1)//~v6H2I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6C9:160407 (LNX:BUG)filegetdevicemntent return 0 even when mntent==NULL for /proc//~v6C9I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6B9:160121 (LNX)new ufullpathCP function to chk optionally filesystem iocharset  convert to utf8 from locale code//~v6B9I~
//v6B8:160121 add function to check iocharset mount option         //~v6B8I~
//v6B6:160119 Lnx compiler warning                                 //~v6B6I~
//v6B5:160119 (Axe)support "get file system type"                  //~v6B5I~
//v6yd:150314 ino_t is not 32 bit                                  //~v6ydI~
//v6uV:140608 support isvfat,isntfs for LNX                        //~v6uVI~
//v6q2:131128 (LNX)no errinvalid msg for xff:search wild           //~v6q2I~
//v6m8:130816 S390x compiler warning(int-->ptr(LONG))              //~v6m8I~
//v6km:130704 notfound msg --> dir exist but no file exist;for xcopy wildcard parm sepcified//~v6kmI~
//v6ka:130624 identify slink err by ftime=fdate=0                  //~v6kaI~
//v6k7:130622 udosfindfirstnomsg is not effectiv for udosfindnext  //~v6k7I~
//v6k4:130610 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ufile1l.c/h change not found msg                     //~v6k4I~
//v6hL:120917 chk and errmsg when too long fullpath                //~v6h9I~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6b1:110705 try list wildcard membername(see V39T,v39Y)          //~v6b1R~
//v6b0:110704 xdd say not empty but dirlist dose not show member if member name contains wildcard char(*?)//~v6b0I~
//            So,display warning                                   //~v6b0I~
//v62j:090907 UTF8SUPP-->UTF8SUPPH for common to xe and wxe        //~v62jI~
//v62b:090724 (FTP:BUG) del dir confirm msg remains when member is file only(no dir member exist)//~v62bI~
//v62a:090723 To delete target of symbolic linc is denagerous(Wine set slink to Winndows drive)//~v62aI~
//v5kx:070820 (LNX:BUG)MDOS disk open fail by "No entry in a:/x1" for cmd "edit a:/x1"//~v5kxI~
//v5kd:070518 (LNX:BUG)intermediate ../ is not resolved(linux understand but xe display ../ as it is)//~v5kdI~
//v5ka:070518 (LNX:BUG)xdd fail by the msg that is dir for dir entry.//~v5kaI~
//            Under FC5 reddir dose not return "." at first,so fstat retuned by findfirst has not attr of dir//~v5kaI~
//            findfirst is used as alternative of ufstat to issue not found msg,So when *hdir=0 at input use fstat//~v5kaI~
//v5fu:050322 dispaly filetime when copy bypass by /d option       //~v5fuI~
//v5d9:040530 (FTP)skip upload for r2r to bypass not found msg if downloaded no entry//~v5d9I~
//v5c7:040330 (UNX)always ignore slink err(put on udirlist)        //~v5c7I~
//            (err occurs when edit rc=40:too many,rc=2:not found etc))//~v5c7I~
//v5c4:040330 (UNX:BUG)xdd fail if slink err(no entry on udirlist if slink err)//~v5c4I~
//v5b9:040202 (BUG) fullpath for ~/../ (home base)                 //~v5b9I~
//v5ai:040108 clear not used slink area clear on ufstat            //~v5aiI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v5a6:040104 (UNX,FTP)save slink uid,gid,uname,gname on dirlist for xe dirlist//~v5a6I~
//v5a4:040103 (BUG:AIX)dummy should be set to 0;filetime compare fail.//~v5a4I~
//v59y:040101 (UNX,FTP)use slink source uname/gname                //~v59yI~
//v59x:040101 (UNX,FTP)save slink timestamp and size for dirlist for xe//~v59xI~
//v59n:031109 ftp support:ufstat,udirlist                          //~v59nI~
//v578:021207 (UNX)udirlist performance tuning(stat call on the current dir)//~v578R~
//v575:021128 (UNX:BUG)wild select fail when dir is also SYSTEM attr;no set hidden/system bit//~v575I~
//v573:021009 (UNX)slink err msg bypass option(u#110)              //~v573I~
//v56y:020807 (BUG)add ufilewildcomp func;wildcomp DBCS support    //~v56yI~
//v56s:020712 (UNX)allow to udirlist select non-reguler file       //~v56sI~
//v56r:020712 (UNX)udirwalk slink err chk by S_ISLNK but no slink name,the skip process//~v56rI~
//v56q:020712 (UNX)slink loop chk(v56k) at udir walk not ufstat.(allow xe dir list display)//~v56qI~
//v56n:020711 (UNX:BUG) xff loop by FIFO file.it is slink,so not chked.//~v56nI~
//v56k:020711 (UNX)own logic for s-link loop detection for performance up//~v56kI~
//v56h:020711 (UNX)not found msg when lstat ok buf fstat err(rc=2) //~v56hI~
//v56g:020711 (UNX)ELOOP msg for lstat                             //~v56gI~
//v56c:020710 (UNX:BUG)attr select;dir is selected when Hidden/System bit on//~v56cI~
//v56a:020710 dirlist:skip readdir when "." is permission err to avoid too many errmsg//~v56aI~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v55f:020429 (UNX)mcd(cd for mdos disk) support                   //~v55fI~
//v533:020313 (BUG)FILE_SYSTEM bit cause unmatch for attrselect    //~v533I~
//v529:020302 api "stat" dose not return ENOTDIR even if path err; //~v529I~
//            check it by myself and issue path not found msg      //~v529I~
//v50N:010908 (BUG:UNX) if "~" is /, "~/" --> "//"                 //~v50NI~
//v50J:010625 dirlist option for socket/Pipe etc                   //~v50JI~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v50E:010616 return symbolic link attr/name for dir list          //~v50EI~
//v50x:010520 (BUG)udosfindfirst fail(not found) for dir but not wildcard//~v50xI~
//v50t:010414 localtime may return 0 when too large seconds        //~v3a2I~
//v3a2:010305 LINUX support:ignore fstat err when dirlist(err when slink)//~v3a2I~
//v39Y:010204 LINUX support:chnage v39T;no need to set FILE_DIRECTORY for wild card.//~v39YI~
//            To avoid file with wildcard char(*,?) is treated as wildcard operation//~v39YI~
//            Such the case "d" dlcmd on filename "*" delete all file.//~v39YI~
//v39V:010204 LINUX support:HIDDEN file attr for .xxx file(start by .)//~v39VI~
//v39T:010204 LINUX support:(BUG) filename containing wild card is treated as dir//~v39TI~
//v39g:001125 LINUX support:linux/ulibent.h is included from dirent.h//~v39gI~
//v397:001111 LINUX support:(BUG)dirname only on notfound errmsg when wildcard findfirst//~v397I~
//v390:001015 LINUX support(BUG:stat fail when wild card;so ufstat use findfirst)//~v390I~
//v387:001009 LINUX support(BUG:dosfindfirst issue apierr when no entry)//~v387I~
//v371:000928 LINUX support(stat may return EACCES for dir with no x-bit)//~v371I~
//            udosfindnext now return err(dont errexit)            //~v371I~
//v370:000928 LINUX support(permission err msg for opendir(EACCES))//~v370I~
//v364:000927 LINUX support(file system chk)                       //~v364I~
//v349:000926 LINUX support(ufstat now returns more info for copy info;fsid,timestamp etc)//~v349I~
//v341:000924 LINUX support(filename may contain "." or ".."; chk "./" or "../"//~v341I~
//v339:000917 LINUX support(home dir(~) support for ufullpath      //~v339I~
//v327 000820:LINUX support;move followings from ufilel.c
//            ufstat,ufullpath,ugetcwd,uchdir
//            udosfindfirst,udosfindnext
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/vfs.h>                                               //~v364I~
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <mntent.h>                                                //~v6uVI~
//#include <linux/dirent.h>                                        //~v39gR~
#include <linux/kdev_t.h>                                          //~v6B8I~
//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v59nI~
#include <ufile.h>
#include <ufile1l.h>                                               //~0901R~
#include <ufile1l2.h>                                              //~v50GI~
#include <ufile4.h>                                                //~v6uVI~
#include <ufile5.h>                                                //~0901I~
#include <uerr.h>
#include <ufemsg.h>
#include <uparse.h>
#include <ustring.h>
#include <utrace.h>
#include <uunxsub.h>
#include <ualloc.h>                                                //~v50GI~
#include <ustring.h>                                               //~v6B5I~
#ifdef FTPSUPP                                                     //~v59nI~
	#include <uftp.h>                                              //~v59nR~
	#include <ufile1f.h>                                           //~v59nR~
#endif                                                             //~v59nI~
#ifdef ARMXXE                                                      //~v779I~
	#include <ufiledoc.h>                                          //~v779I~
#endif                                                             //~v779I~
#include <utf.h>                                                   //~v6B9I~
#include <uedit2.h>                                                //~v6D2I~
#include <ulibarm.h>                                               //~v70bI~
//*******************************************************
#define SPECIAL_DIRID    '.'                                       //~v341I~
#define MAXHDIR 100
                                                                   //~v50GI~
//typedef struct dirent DIRENT,*PDIRENT;                             //~v6b1R~//~v77dR~

static int  Shdirindex=0;	//Shdir searced index                  //~v529R~
                                                                   //~v50GI~
static HDIR Shdirtbl[MAXHDIR];
static UINT Shdirtattr[MAXHDIR];
static int  Shdirpathlen[MAXHDIR];                                 //~0901I~
static PUDIRLIST Shdirpudl[MAXHDIR];	//current mdir line pos    //~v50GI~
static UCHAR Shdirpath[MAXHDIR][_MAX_PATH];                        //~0827I~
static  HDIR Shdirfirst;                                           //~0827R~
static char Snomsgff;   //no err msg version                       //~0827R~
static char Snomsgffnext;//no err msg version                      //~v6k7I~
//static char Swildname;  //filename may contain wildcard char     //~v39YR~
static int  Swildnamechk;  //filename may contain wildcard char    //~v6b1R~
static int  Swildnamemembfstat;  //wildname chk for dirent member  //~v6b1I~
static int SdirlistOtherAttrCtr;                                   //~v6kmI~
static int SswFFopt=0;                                             //~v784I~
//*******************************************************
//void ufilegetftime(FTIME* Pft,FDATE *Pfd,time_t Ptime_t);        //~v5fuR~
int ufilelnxgetmembfstat(FILEFINDBUF3 *Ppffb3,PDIRENT Ppde,UCHAR *Ppath,int Ppathlen);//~v371R~
//int  ufilelnxwildselect(UCHAR *Pfname,UCHAR *Pwildcard,int Pcasesw);//~v55nR~//~v779R~
int ufilelnxsavehdir(HDIR Phdir,ULONG Pattr,UCHAR *Ppath,int Ppathlen);
#define UFLSH_WILDNAME 0x01                                        //~v6b1I~
int ufilelnxsrchhdir(HDIR Phdir,ULONG *Ppattr,UCHAR **Pppath,int *Pppathlen);//~0901R~
int ufilelnxclosehdir(HDIR Phdir);
//*******************************************************          //~v777I~
//*******************************************************
//*get file status(size,time stmp)
//*parm 1:file name
//*parm 2:output file info addr(optional)
//*******************************************************
unsigned int ufstat(char *Ppfile,FILEFINDBUF3 *Ppffb3)
{
    FILEFINDBUF3 ft;
    FILEFINDBUF3 *pft;
#ifdef LFSSUPP                                                     //~v5fuI~
  #if LFSSUPP == 1                                                 //~v5fuI~
    struct stat64 statbuff;   //output file information            //~v5fuI~
    struct stat64 statbuff2;   //for slink file                    //~v5fuI~
  #else                                                            //~v5fuI~
    struct stat statbuff;   //output file information              //~v5fuI~
    struct stat statbuff2;   //for slink file                      //~v5fuI~
  #endif                                                           //~v5fuI~
#else                                                              //~v5fuI~
    struct stat statbuff;   //output file information              //~0827R~
    struct stat statbuff2;   //for slink file                      //~v50EI~
#endif                                                             //~v5fuI~
    int pathlen,rc;                                                //~0901R~
//  int dirsw=0;                                                   //~v56sR~
    int len;                                                       //~v50EI~
    char pathname[_MAX_PATH];                                      //~v529I~
    char *statfnm;                                                 //~v578I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
	FILEFINDBUF3 ffb3_wild;                                        //~v6b1I~
    int rc2;                                                       //~v6b1I~
    int swwildname;                                                //~v6b1I~
    int swslinkerr=0;                                              //~v6kaR~
//*********************************
	UTRACEP("%s:Ppfile=%s\n",UTT,Ppfile);                          //~v777I~
#ifdef ARMXXE                                                      //~v777I~
  if (0)                                                           //~v77mI~
	if (IS_DOCPATH(Ppfile))                                         //~v777I~
    {                                                              //~v777I~
//  	return ufstatDoc(Ppfile,Ppffb3);                           //~v777I~//~v77dR~
    	return ufstatDoc(Ppfile,Ppffb3,(!Swildnamechk && !Swildnamemembfstat)/*findfirst if wildcard*/);  //called from not (ufstat_wild or membfstat)//~v77dI~
    }                                                              //~v777I~
#endif                                                             //~v777I~
#ifdef FTPSUPP                                                     //~v59nM~
  	if (uftpisremote(Ppfile,&puftph))	//ftp filename             //~v5afR~
		return uftpfstat(puftph,Ppfile,Ppffb3);                    //~v5afR~
#endif                                                             //~v59nM~
    if (!(pft=Ppffb3))  //optional parm
        pft=&ft;                        //use internal work
    memset(pft,0,sizeof(FILEFINDBUF3));                            //~v5aiI~
    pathlen=PATHLEN(Ppfile);                                       //~v6b1I~
    if (pathlen<0)    //no / found(not fullpath name)              //~v6b1I~
        pathlen=0;                                                 //~v6b1I~
    swwildname=WILDCARD(Ppfile+pathlen)!=NULL;                     //~v6b1R~
//if (!Swildname)  //filename may not contain wildcard char        //~v39YR~
  if (!Swildnamechk && !Swildnamemembfstat)  //called from not (ufstat_wild or membfstat)//~v6b1R~
//  if (WILDCARD(Ppfile))                                          //~v6b1R~
    if (swwildname)                                                //~v6b1I~
    {                                                              //~v390I~
//  	rc2=ufstat_wild(Ppfile,&ffb3_wild);                        //~v6b1R~//~v6B6R~
    	rc2=(int)ufstat_wild(Ppfile,&ffb3_wild);                   //~v6B6I~
      if (rc2)	//the wildcard filename dose not exist             //~v6b1I~
      {                                                            //~v6b1I~
//  	if (rc=udosfindfirstnomsg(Ppfile,0,FILE_ALL,Ppffb3),rc)    //~v56sR~
//  	if (rc=udosfindfirstnomsg(Ppfile,0,FILE_ALLSP,Ppffb3),rc)  //~v56sI~//~v6B6R~
    	if (rc=(int)udosfindfirstnomsg(Ppfile,0,FILE_ALLSP,Ppffb3),rc)//~v6B6I~
//      	return rc;                                             //~v390I~//~v6B6R~
        	return (unsigned)rc;                                   //~v6B6I~
// 		pft->attrFile|=FILE_DIRECTORY;	//force dir                //~v39YR~
      }                                                            //~v6b1M~
      else                                                         //~v6b1I~
      {                                                            //~v6b1I~
        memcpy(pft,&ffb3_wild,sizeof(ffb3_wild));                  //~v6b1I~
      }                                                            //~v6b1I~
//	    UTRACEP("ufstat_wild inode=%x\n",(int)pft->inode);         //~v6b1I~//~v6q2R~
        return 0;                                                  //~v390I~
    }                                                              //~v390I~
                                                                   //~v50GI~
  	if (MDOSDISK(Ppfile) && Gufile_opt & GFILEOPT_LNXMTOOL)	//use mtool//~v50GR~
		return ufstat_mdos(Ppfile,Ppffb3);                         //~v50GI~
//  pathlen=PATHLEN(Ppfile);                                       //~v6b1R~
//  if (pathlen<0)    //no / found(not fullpath name)              //~v6b1R~
//      pathlen=0;                                                 //~v6b1R~
//*not wild card                                                   //~v390I~
//  if (stat(Ppfile,&statbuff))                                    //~v50ER~
//  if (lstat(Ppfile,&statbuff))                                   //~v578I~
    if (Gufile_opt & GFILEOPT_STATCD)                              //~v578I~
		statfnm=Ppfile+pathlen;                                    //~v578I~
    else                                                           //~v578I~
		statfnm=Ppfile;                                            //~v578I~
#ifdef ARMXXE                                                      //~v77mI~
  if (1                                                            //~v77mI~
  &&  IS_DOCPATH(Ppfile))                                          //~v77mR~
	rc2=ufile_statDoc(Ppfile,&statbuff);                           //~v77mR~
  else                                                             //~v77mI~
    rc2=lstat(statfnm,&statbuff);                                  //~v77mR~
  if (rc2)                                                         //~v77mR~
#else                                                              //~v77mI~
#ifdef LFSSUPP                                                     //~v5fuI~
  #if LFSSUPP == 1                                                 //~v5fuI~
    if (lstat64(statfnm,&statbuff))                                //~v5fuM~
  #else                                                            //~v5fuI~
    if (lstat(statfnm,&statbuff))                                  //~v5fuM~
  #endif                                                           //~v5fuI~
#else                                                              //~v5fuI~
    if (lstat(statfnm,&statbuff))                                  //~v578I~
#endif                                                             //~v5fuI~
#endif	//ARMXXE                                                   //~v77mM~
    {                                                              //~v390R~
        rc=errno;                                                  //~v390R~
        UTRACEP("ufstat errno=%d fnm=%s\n",rc,statfnm);            //~v6hLI~
        if (rc==EACCES)                                            //~v390R~
//          return ufilenopermission("stat",Ppfile,rc);            //~v50ER~
//          return ufilenopermission("lstat",Ppfile,rc);           //~v50EI~//~v6B6R~
            return (unsigned)ufilenopermission("lstat",Ppfile,rc); //~v6B6I~
        if (rc==ENAMETOOLONG)                                      //~v6H1I~
    		return (unsigned)ufileTooLongFullpathName2(rc,Ppfile,"");//~v6H2R~
        if(rc!=ENOENT && rc!=ENOTDIR) //not found or no more file  //~v390R~
        {                                                          //~v77rR~
#ifdef ARMXXE                                                      //~v77rR~
  			if (rc==EINVAL && IS_DOCPATH(Ppfile))                  //~v77rR~
            	return rc;                                         //~v77rR~
#endif                                                             //~v77rR~
//          return ufileapierr("stat",Ppfile,rc);                  //~v50ER~
//          return ufileapierr("lstat",Ppfile,rc);                 //~v50EI~//~v6B6R~
            return (unsigned)ufileapierr("lstat",Ppfile,rc);       //~v6B6I~
        }                                                          //~v77rR~
        if(rc==ENOENT)                                             //~v529I~
            if (pathlen)                                           //~v529I~
	        {                                                      //~v529I~
        	    memcpy(pathname,Ppfile,(UINT)pathlen);             //~v529R~
     	       	*(pathname+pathlen)=0;                             //~v529R~
#ifdef ARMXXE                                                      //~v77mI~
  			  if (1                                                //~v77mI~
  				  &&  IS_DOCPATH(pathname))                        //~v77mI~
              {                                                    //~v77mI~
				if (ufile_statDoc(pathname,&statbuff2))            //~v77mR~
	            	if (errno==ENOENT)                             //~v77mI~
     			    	rc=ENOTDIR;                                //~v77mI~
              }                                                    //~v77mI~
              else                                                 //~v77mI~
#endif	//ARMXXE                                                   //~v77mM~
              {                                                    //~v77mI~
#ifdef LFSSUPP                                                     //~v5fuI~
  #if LFSSUPP == 1                                                 //~v5fuI~
    			if (lstat64(pathname,&statbuff2))                  //~v5fuI~
  #else                                                            //~v5fuI~
    			if (lstat(pathname,&statbuff2))                    //~v5fuI~
  #endif                                                           //~v5fuI~
#else                                                              //~v5fuI~
    			if (lstat(pathname,&statbuff2))                    //~v529R~
#endif                                                             //~v5fuI~
            		if (errno==ENOENT)                             //~v529R~
                		rc=ENOTDIR;                                //~v529R~
              }                                                    //~v77mI~
	        }                                                      //~v529R~
//      return rc;                                                 //~v390R~//~v6B6R~
        return (unsigned)rc;                                       //~v6B6I~
    }                                                              //~v390R~
    UTRACED("ufstat statbuff",&statbuff,sizeof(statbuff));         //~v6hLR~//~v6q2R~//~v77mR~
    *(pft->slink)=0;                                               //~v50ER~
    pft->srcattr=0;   	//slink source file attr                   //~v56nI~
    pft->uid=statbuff.st_uid;                                      //~v59yI~
    pft->gid=statbuff.st_gid;                                      //~v59yI~
    if (S_ISLNK(statbuff.st_mode))//symbolic link                  //~v50EI~
    {                                                              //~v50EI~
//      len=readlink(Ppfile,pft->slink,sizeof(pft->slink)-1);//return string len//~v578R~
//      len=readlink(statfnm,pft->slink,sizeof(pft->slink)-1);//return string len//~v578I~//~v6BxR~
        len=(int)readlink(statfnm,pft->slink,sizeof(pft->slink)-1);//return string len//~v6BxI~
        if (len>0)	//success                                      //~v50EI~
        	*(pft->slink+len)=0;                                   //~v50ER~
//        if (!strcmp(pft->slink,".")  //                          //~v56qR~
//        ||  !strcmp(pft->slink,"..")  //                         //~v56qR~
//        ||  (*pft->slink==DIR_SEPC && strstr(Ppfile,pft->slink))) //slink loop(source path is upper level of target)//~v56qR~
//        {                                                        //~v56qR~
//            uerrmsg("S-Link loop;%s --> %s",0,                   //~v56qR~
//                        Ppfile,pft->slink);                      //~v56qR~
//            rc=ELOOP;                                            //~v56qR~
//            return rc;                                           //~v56qR~
//        }                                                        //~v56qR~
//      if (stat(Ppfile,&statbuff2)) 	//to chk directory         //~v578R~
#ifdef LFSSUPP                                                     //~v5fuI~
  #if LFSSUPP == 1                                                 //~v5fuI~
        if (stat64(statfnm,&statbuff2)) 	//to chk directory     //~v5fuI~
  #else                                                            //~v5fuI~
        if (stat(statfnm,&statbuff2)) 	//to chk directory         //~v5fuI~
  #endif                                                           //~v5fuI~
#else                                                              //~v5fuI~
        if (stat(statfnm,&statbuff2)) 	//to chk directory         //~v578I~
#endif                                                             //~v5fuI~
        {                                                          //~v50EI~
    		swslinkerr=1;                                          //~v6kaI~
        	rc=errno;                                              //~v50EI~
        	UTRACEP("ufstat slink errno=%d fnm=%s\n",rc,statfnm);  //~v6hLI~
        	if (rc==EACCES)                                        //~v50EI~
//          	return ufilenopermission("stat",Ppfile,rc);        //~v50EI~//~v6B6R~
            	return (unsigned)ufilenopermission("stat",Ppfile,rc);//~v6B6I~
            if (rc==ELOOP)                                         //~v56gI~
            {                                                      //~v56kI~
      		  if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))          //~v6kaI~
            	ufileslinkloop("stat",Ppfile);          //~v56gI~  //~v6kaR~
//              return rc;                                         //~v56rR~
            }                                                      //~v56kI~
            else                                                   //~v56gI~
            if (rc==ENOENT)                                        //~v56hI~
            {                                                      //~v573I~
      		  if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))          //~v573I~
//                uerrmsg("Invalid S-Link ? %s link defined but not found",0,//~v56hI~//~v6hLR~
//                          Ppfile);                               //~v6hLI~
//              if (!Snomsgff)                                     //~v6k4I~//~v6k7R~
				if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))        //~v6k7I~
                	ufileslinktargeterr(-1,Ppfile,pft->slink); //ufemsg//~v6k4R~//~v6k7R~
            }                                                      //~v573I~
            else                                                   //~v56hI~
        	if(rc!=ENOENT && rc!=ENOTDIR) //not found or no more file//~v50EI~
            	ufileapierr("stat",Ppfile,rc);                     //~v50ER~
//    	  if (!(Gufile_opt & GFILEOPT_IGNORESLINKERR))  //not ignore slinkerr//~v5c7R~
//          if (rc!=ELOOP)                                         //~v5c7R~
//          	return rc;                                         //~v5c7R~
            memset(&statbuff2,0,sizeof(statbuff2));                //~v50JR~
        }                                                          //~v50EI~
//      if (S_ISDIR(statbuff2.st_mode))	//directory                //~v56sR~
//      	dirsw=FILE_DIRECTORY;                                  //~v56sR~
//  	pft->srcattr=FILE_SETMODEATTR(statbuff2.st_mode,dirsw);    //permissyon etc//~v56sR~
    	UTRACED("ufstat slink statbuff",&statbuff2,sizeof(statbuff2));//~v6hLR~
    	pft->srcattr=FILE_SETMODEATTR(statbuff2.st_mode,0);    //permissyon etc//~v56sI~
    	pft->slinksize=statbuff2.st_size;                          //~v59xI~
	    pft->slinkmtime=statbuff2.st_mtime;	//modified             //~v59xI~
    	ufilegetftime(&pft->slinkftime,&pft->slinkfdate,statbuff2.st_mtime);//~v59xI~
    	pft->uid=statbuff2.st_uid;                                 //~v59yI~
    	pft->gid=statbuff2.st_gid;                                 //~v59yI~
        pft->slinkuid=statbuff2.st_uid;                            //~v5a6I~
        pft->slinkgid=statbuff2.st_gid;                            //~v5a6I~
    }                                                              //~v50EI~
//conv stat to findbuf3
//  pft->uid=statbuff.st_uid;                                      //~v59yR~
//  pft->gid=statbuff.st_gid;                                      //~v59yR~
    pft->fsid=statbuff.st_dev;	//file system id                   //~v349I~
    pft->inode=statbuff.st_ino;	//inode                            //~v6b1I~
//  UTRACEP("ufstat inode from statbuff=%x fnm=%s\n",(int)pft->inode,Ppfile);//~v6b1R~
    pft->atime=statbuff.st_atime;	//access                       //~v349I~
    pft->mtime=statbuff.st_mtime;	//modified                     //~v349I~
    pft->ctime=statbuff.st_ctime;	//correct                      //~v349I~
//  pft->attrFile=FILE_SETMODEATTR(statbuff.st_mode,0);    //permissyon etc//~v50ER~
//  pft->attrFile=FILE_SETMODEATTR(statbuff.st_mode,dirsw);    //permissyon etc//~v56sR~
    pft->attrFile=FILE_SETMODEATTR(statbuff.st_mode,0);    //permissyon etc//~v56sI~
    *pft->uname=0;                                                 //~v59nI~
    *pft->gname=0;                                                 //~v59nI~
//  ufilemode2attr(pft);                                           //~v39VR~

    ufilegetftime(&pft->ftimeLastWrite,&pft->fdateLastWrite,       //~0827R~
                    statbuff.st_mtime);                            //~0827R~
    pft->cbFile=statbuff.st_size;
//  pathlen=PATHLEN(Ppfile);                                       //~v529R~
//  if (pathlen<0)    //no / found(not fullpath name)              //~v529R~
//      pathlen=0;                                                 //~v529R~
    strncpy(pft->achName,Ppfile+pathlen,sizeof(pft->achName));
    ufilemode2attr(pft);    //after filename set to chk .xxx(hidden file)//~v39VI~
    if (swwildname)                                                //~v6b1M~
    	pft->attrFile|=FILE_WILDNAME;                              //~v6b1M~
    if (swslinkerr)                                                //~v6kaI~
    	pft->attrFile|=FILE_SLINKERR;                              //~v6kaI~
//    UTRACED("ufstat pft",pft,sizeof(FILEFINDBUF3));                //~v6hLI~//~v6q2R~
    return 0;                                                      //~0827R~
}//ufstat
//*******************************************************          //~v6b1I~
//*chk wildcard name with multiple inode                           //~v6b1I~
//*******************************************************          //~v6b1I~
int ufilechkwildmultiple(int Popt,char *Pfnm,PDIRENT Ppde,FILEFINDBUF3 *Ppffb3)//~v6b1R~
{                                                                  //~v6b1I~
	int rc=0,pathlen,multictr=0,filectr=0,swfound;                 //~v6b1R~
    DIR*  hdir;                                                    //~v6b1I~
    PDIRENT pde;                                                   //~v6b1I~
    char *pc,dirnm[_MAX_PATH];                                     //~v6b1I~
//******************                                               //~v6b1I~
    UTRACEP("%s:fnm=%s\n",UTT,Pfnm);                               //~v6D2I~
    if ((pathlen=PATHLEN(Pfnm))<0)                                 //~v6b1I~
    {                                                              //~v6b1I~
    	pathlen=0;                                                 //~v6b1I~
        strcpy(dirnm,"./"); //curr dir                             //~v6b1I~
    }                                                              //~v6b1I~
    else                                                           //~v6b1I~
    	UmemcpyZ(dirnm,Pfnm,(UINT)pathlen);                        //~v6b1I~
#ifdef ARMXXE                                                      //~v77mI~
  if (IS_DOCPATH(dirnm))                                         //~v77mI~
  {                                                                //~v77mI~
  	void *pvoid;                                                   //~v77mI~
    errno=ufile_opendirDoc(dirnm,&pvoid);                          //~v77mI~
    hdir=(DIR *)pvoid; //existing wildname file                    //~v77mR~
    UTRACEP("%s:fnm=%s,errno=%d\n",UTT,Pfnm,errno);                //~v77mI~
  }                                                                //~v77mI~
  else                                                             //~v77mI~
#endif                                                             //~v77mI~
    hdir=opendir(dirnm);                                           //~v6b1R~
    UTRACEP("%s:opendir dirnm=%s,hdir=%p\n",UTT,dirnm,hdir);                    //~v77dI~//~v77mR~
    if (!hdir)                                                     //~v6b1I~
    {                                                              //~v77mI~
        return -1;                                                 //~v6b1I~
    }                                                              //~v77mI~
    pc=Pfnm+pathlen;                                               //~v6b1M~
    swfound=!Ppde;	//if no ino reset request,break if multiple entry found//~v6b1I~
    for (;;)                                                       //~v6b1I~
    {                                                              //~v6b1I~
        pde=readdir(hdir);                                         //~v6b1I~
        if (!pde)                                                  //~v6b1I~
            break;                                                 //~v6b1I~
	    UTRACEP("%s:readdir d_name=%s\n",UTT,pde->d_name);         //~v77dI~
        UTRACED("chkwildmultiple",pde,pde->d_reclen);              //~v6b1I~
        filectr++;                                                 //~v6b1I~
        if (!strcmp(pc,pde->d_name))                               //~v6b1I~
        {                                                          //~v6b1M~
            multictr++;                                            //~v6b1M~
            if (multictr>1)                                        //~v6b1M~
                rc=1;   //multiple wildname                        //~v6b1M~
            if (Ppde && Ppde->d_off==pde->d_off) //inode may change after fstat//~v6b1R~
            {                                                      //~v6b1I~
            	if (Ppffb3)                                        //~v6b1I~
	                Ppffb3->inode=pde->d_ino;                      //~v6b1I~
                UTRACEP("chkwildmultiple offset match %s inode Ppde=%x,pde=%x\n",pde->d_name,(int)Ppde->d_ino,pde->d_ino);//~v6b1I~
                swfound=1;                                         //~v6b1I~
            }                                                      //~v6b1I~
            if (rc==1       //multiple entry found                 //~v6b1I~
            &&  swfound)	//already reset inode                  //~v6b1I~
            	break;                                             //~v6b1I~
        }                                                          //~v6b1M~
    }                                                              //~v6b1I~
    closedir(hdir);        //relese  handle                        //~v6b1I~
    UTRACEP("chkwildmultiple filectr=%d,rc=%d,file=%s\n",filectr,rc,Pfnm);//~v6b1I~
    if (rc==1)                                                     //~v6b1R~
    {                                                              //~v6b1I~
		if (Ppffb3)                                                //~v6b1I~
			Ppffb3->attrFile|=FILE_WILDNAME_MULTIPLE;              //~v6b1I~
    	UTRACEP("%s:rc=1:FILE_WILDNAME_MULTIPLE,ffb3=%p\n",UTT,Ppffb3);//~v6D2I~
    }                                                              //~v6b1I~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6D2I~
    return rc;                                                     //~v6b1I~
}//chkwildmultiple                                                 //~v6b1I~
//*******************************************************          //~v6b1I~
//*chk wildcard name itself exist or not                           //~v6b1I~
//*******************************************************          //~v6b1I~
unsigned int ufstat_wild(char *Ppfile,FILEFINDBUF3 *Ppffb3)        //~v6b1I~
{                                                                  //~v6b1I~
//  int rc;                                                        //~v6b1I~//~v6B6R~
    unsigned int rc;                                               //~v6B6I~
//******************                                               //~v6b1I~
	Swildnamechk=1;    //test existing                             //~v6b1R~
	rc=ufstat(Ppfile,Ppffb3);                                      //~v6b1I~
    Swildnamechk=0;    //test existing                             //~v6b1R~
    if (!rc && Ppffb3 && Ppffb3->attrFile & FILE_WILDNAME)         //~v6b1R~
    	ufilechkwildmultiple(0,Ppfile,NULL/*Ppde*/,Ppffb3);        //~v6b1R~
    UTRACEP("%s:rc=%d,fnm=%s,Ppffb3=%p,attr=0x%x\n",UTT,rc,Ppfile,Ppffb3,(Ppffb3 ? Ppffb3->attrFile:0));                                  //~v6D2I~//~v783R~//~v785R~
    return rc;                                                     //~v6b1I~
}//ufstat2                                                         //~v6b1I~
//*******************************************************
//*file system compare                                             //~v364R~
//*p1:file 1 to compare                                            //~v364I~
//*p2:file 2 to compare (optional)                                 //~v364I~
//*ret:4:err,1:unmatch,0 match                                     //~v364I~
//*******************************************************
int ufilefscomp(char *Pfile1,char *Pfile2)                         //~v364R~
{
    int fsid1,fsid2;                                               //~v364R~
//*******************
    if ((fsid1=ufilegetfsid(Pfile1))==-1)                          //~v364R~
    	return 4;                                                  //~v364I~
    if ((fsid2=ufilegetfsid(Pfile2))==-1)                          //~v364I~
    	return 4;                                                  //~v364I~
    UTRACEP("%s:rc=%d,f1=%s,f2=%s\n",UTT,(fsid1!=fsid2),Pfile1,Pfile2);//~v77dI~
    return (fsid1!=fsid2);	//1 when unmatch                       //~v364R~
}//ufilefscomp                                                     //~v364I~
//*******************************************************          //~v364I~
//*get file system id from stat buff                               //~v364I~
//*p1:filename                                                     //~v364I~
//*ret:fsid(dev_t),-1:err                                          //~v364I~
//*******************************************************          //~v364I~
int ufilegetfsid(char *Pfile)                                      //~v364I~
{                                                                  //~v364I~
    char fnm[_MAX_PATH];                                           //~v364I~
#ifdef LFSSUPP                                                     //~v5fuI~
  #if LFSSUPP == 1	        //  _LARGEFILE64_SOURCE                //~v5fuI~
    struct stat64 statbuff;   //output file information            //~v5fuI~
  #else                     // _FILE_OFFSET_BITS ==64              //~v5fuI~
    struct stat statbuff;   //output file information              //~v5fuI~
  #endif                                                           //~v5fuI~
#else                                                              //~v5fuI~
    struct stat statbuff;   //output file information              //~v364I~
#endif                                                             //~v5fuI~
    int pathlen;                                                   //~v364I~
//*******************                                              //~v364I~
	ustrncpyz(fnm,Pfile,_MAX_PATH);                                //~v364I~
#ifdef LFSSUPP                                                     //~v5fuI~
  #if LFSSUPP == 1	        //  _LARGEFILE64_SOURCE                //~v5fuI~
    while(stat64(fnm,&statbuff))                                   //~v5fuI~
  #else                                                            //~v5fuI~
    while(stat(fnm,&statbuff))                                     //~v5fuI~
  #endif                                                           //~v5fuI~
#else                                                              //~v5fuI~
    while(stat(fnm,&statbuff))                                     //~v364R~
#endif                                                             //~v5fuI~
    {                                                              //~v364I~
        if ((pathlen=PATHLEN(fnm))<=1)  //reached to root          //~v364I~
            return -1;       //no upper path                       //~v364I~
        *(fnm+pathlen-1)=0;     //up dir level                     //~v364I~
    }                                                              //~v364I~
    UTRACEP("%s:rc=%d,file=%s\n",UTT,statbuff.st_dev,Pfile);       //~v77dI~
    return (int)statbuff.st_dev;	//file system id               //~v364I~
}//ufilegetfsid                                                    //~v364I~
//*******************************************************          //~v364I~
//*conv time_t to file time fmt                                    //~v364I~
//*******************************************************          //~v364I~
void ufilegetftime(FTIME* Pft,FDATE *Pfd,time_t Ptime_t)           //~v364I~
{                                                                  //~v364I~
    struct tm *ptm; //yy,mm,dd,hh,mm,ss,...                        //~v364I~
    int hh,mm,ss,yy,dd;                                            //~v6D2I~
//*******************                                              //~v364I~
  if (Ptime_t)                                                     //~v6kaI~
    ptm=localtime(&Ptime_t);                                       //~0827R~
  else                                                             //~v6kaI~
    ptm=0;                                                         //~v6kaI~
    if (!ptm)                                                      //~v50tR~
    {                                                              //~v50tR~
//    Pft->twosecs=0;                                                //~v50tR~//~v6D2R~
//    Pft->minutes=0;                                                //~v50tR~//~v6D2R~
//    Pft->hours  =0;                                                //~v50tR~//~v6D2R~
        memset(Pft,0,sizeof(FTIME));                               //~v6D2I~
//    Pfd->day    =0;                                                //~v50tR~//~v6D2R~
//    Pfd->month  =0;                                                //~v50tR~//~v6D2R~
//    Pfd->year   =0;                                                //~v50tR~//~v6D2R~
        memset(Pfd,0,sizeof(FDATE));                               //~v6D2I~
    }                                                              //~v50tR~
    else                                                           //~v50tR~
    {                                                              //~v50tR~
//    Pft->twosecs=ptm->tm_sec/2;     //by 2 seconds                 //~0827R~//~v6D2R~
      ss=ptm->tm_sec/2;     //by 2 seconds                         //~v6D2I~
//    Pft->minutes=ptm->tm_min;                                    //~v6D2R~
      mm=ptm->tm_min;                                              //~v6D2I~
//    Pft->hours  =ptm->tm_hour;                                   //~v6D2R~
      hh=ptm->tm_hour;                                             //~v6D2I~
        ueditsetftimeUSHORT(0,hh,mm,ss,Pft);                       //~v6D2R~
//    Pfd->day    =ptm->tm_mday;                                   //~v6D2R~
      dd=ptm->tm_mday;                                             //~v6D2I~
//    Pfd->month  =ptm->tm_mon+1;                                  //~v6D2R~
      mm=ptm->tm_mon+1;                                            //~v6D2I~
//    Pfd->year   =ptm->tm_year-80;   //ajust from 1900(UNX)-->from 1980(DOS)//~0827R~//~v6D2R~
      yy=ptm->tm_year-80;   //ajust from 1900(UNX)-->from 1980(DOS)//~v6D2I~
        ueditsetfdateUSHORT(0,yy,mm,dd,Pfd);                       //~v6D2R~
    };                                                             //~v50tR~
//#ifdef AIX                                                         //~v5a4R~//~v6D2R~
//    Pft->dummy  =0;                                                //~v5a4R~//~v6D2R~
//    Pfd->dummy  =0;                                                //~v5a4R~//~v6D2R~
//#endif                                                             //~v5a4R~//~v6D2R~
    return;
}//ufilegetftime

//*******************************************************
//*get file fullpath name
//*parm 1:output full pth mame
//*parm 2:input partial filename
//*parm 3:output buff len
//*return:output buff addr or NULL if err
//*******************************************************
                                                                   //~v70bI~
char *ufullpath(char *Pfullpath,char *Pfilename,size_t Plen)
#if defined(ARM) && defined(XXE)                                   //~v70bR~
{                                                                  //~v70bI~
	char *pfpath;                                                  //~v70bI~
    char wk[_MAX_PATH];                                            //~v70bI~
    char wk2[_MAX_PATH];                                           //~v70bI~
    int rc;                                                        //~v70bI~
	char *ufullpathARMsub(char *Pfullpath,char *Pfilename,size_t Plen);//~v70bI~
//*************************                                        //~v70bI~
    if (USTRHEADIS(Pfilename,ARM_TMPID) && getenv(ENV_TMPDIR))     //~v70bR~
    {                                                              //~v70bI~
    	strcpy(wk2,getenv(ENV_TMPDIR));                            //~v70bR~
        strcat(wk2,Pfilename+sizeof(ARM_TMPID));                   //~v70bR~
		pfpath=ufullpathARMsub(Pfullpath,wk2,Plen);                //~v70bI~
    }                                                              //~v70bI~
    else                                                           //~v70bI~
	pfpath=ufullpathARMsub(Pfullpath,Pfilename,Plen);              //~v70bI~
    if (pfpath)                                                    //~v70bI~
    {                                                              //~v70bI~
		rc=ufullpathAltSD(UFPASDO_SETRC_CHANGED,Pfullpath,wk);   //jniu//~v70bR~
        if (rc & UFPASDRC_RC_CHANGED)                              //~v70bR~
        {                                                          //~v70bI~
        	UTRACEP("%s:ARM:%s replaced to %s\n",UTT,Pfullpath,wk);//~v70bI~
        	strcpy(Pfullpath,wk);                                  //~v70bI~
        }                                                          //~v70bI~
    }                                                              //~v70bI~
	return pfpath;                                                 //~v70bI~
}                                                                  //~v70bI~
char *ufullpathARMsub(char *Pfullpath,char *Pfilename,size_t Plen) //~v70bI~
#endif                                                             //~v70bI~
{
//  char wk[_MAX_PATH],*pwk,*home;                                 //~v6hLR~
    char wk[_MAX_PATH+8],*pwk,*home;	//8:redundancy for add "/" //~v6hLI~
    int  rootsw;                                                   //~0827R~
    UINT len;                                                      //~v339R~
    char wkdropq[_MAX_PATH];    //drop quataition work
    char *pc;                                                      //~0827R~
    int mdossw,rootpos=ROOTDIRPOS;                                 //~v50GR~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
    int rc2;                                                       //~v6H2I~
//*********************************
//*drp quatation encloser
#ifdef FTPSUPP                                                     //~v59nI~
  	if (uftpisremote(Pfilename,&puftph))	//ftp filename         //~v5afR~
		return uftpfullpath(puftph,Pfullpath,Pfilename,Plen);      //~v5afR~
#endif                                                             //~v59nI~
//  uparsefname(0,Pfilename,wkdropq,0,0);//no opd,no need delmpos,outlen//~v6H2R~
    rc2=uparsefname(0,Pfilename,wkdropq,0,(int)sizeof(wkdropq),0);//no opd,no need delmpos,outlen//~v6H2I~
    if (rc2==8)  //buff overflow                                   //~v6H2I~
    	return 0;                                                  //~v6H2I~
    pc=wkdropq;
//  len=strlen(pc);                                                //~v6BxR~
    len=(UINT)strlen(pc);                                          //~v6BxI~
    mdossw=MDOSDISKOK(pc);                                         //~v50GI~
//*dir path
//    if (*pc=='~') //homedir                                      //~v5b9R~
//    {                                                            //~v5b9R~
//        if (!(home=getenv("HOME")))                              //~v5b9R~
//            return 0;                                            //~v5b9R~
//        strcpy(wk,home);                                         //~v5b9R~
//        if ((*home=='/' && !*(home+1))  //home is root           //~v5b9R~
//        &&  *(pc+1)=='/')               // parm is "~/"          //~v5b9R~
//            strcpy(wk+1,pc+2);                                   //~v5b9R~
//        else                                                     //~v5b9R~
//        strcat(wk,pc+1);                                         //~v5b9R~
//    }                                                            //~v5b9R~
//    else                                                         //~v5b9R~
    if (mdossw)                                                    //~v50GI~
    {                                                              //~v50GI~
    	rootpos=MDOSROOTDIRPOS;                                    //~v50GI~
        memset(wk,0,sizeof(wk));                                   //~v50GI~
	    strcpy(wk,pc);                                             //~v50GI~
        pc +=2;                                                    //~v50GI~
        len -=2;                                                   //~v50GI~
    	if (*pc!='/')                                              //~v50GI~
        {                                                          //~v50GI~
        	if (ugetcwd_mdos(wk)>1)                                //~v50GI~
            {                                                      //~v50GI~
   	        	uerrmsg("ufullpath:get current dir failed for MDOS",//~v50GI~
                	    "ufullpath:MDOS 現行ディレクトリー取得の失敗,");//~v50GI~//~v777I~
	            return 0;                                          //~v50GI~
            }                                                      //~v50GI~
//process "../"                                                    //~v50GI~
            pwk=wk;                                                //~v50GI~
            while ((len>=2 && *pc==SPECIAL_DIRID && *(pc+1)==SPECIAL_DIRID)//~v50GI~
                && (len==2 || *(pc+2)==DIR_SEPC)) //.. or ../      //~v50GI~
            {                                                      //~v50GI~
                pc+=2;                                             //~v50GI~
                len-=2;                                            //~v50GI~
                if (len)                                           //~v50GI~
                {                                                  //~v50GI~
                    pc++;                                          //~v50GI~
                    len--;                                         //~v50GI~
                }                                                  //~v50GI~
                pwk=wk+PATHLEN(wk)-1;                              //~v50GI~
                memset(pwk+1,0,strlen(pwk+1));                     //~v50GI~
                if (pwk!=wk)    //not yet reached to root          //~v50GI~
                    *pwk=0;    //drop parent dir                   //~v50GI~
            }//loop process parent                                 //~v50GI~
//*                                                                //~v50GI~
            if (len)//filename on input                            //~v50GI~
            {                                                      //~v50GI~
                rootsw=(strlen(wk)==3);                            //~v50GI~
                if ((len && *pc==SPECIAL_DIRID)                    //~v50GI~
                &&  (len==1 || *(pc+1)==DIR_SEPC)) //. or ./       //~v50GI~
                {                                                  //~v50GI~
                    pc++;                                          //~v50GI~
                    len--;                                         //~v50GI~
                    if (len)                                       //~v50GI~
                    {                                              //~v50GI~
                        pc++;                                      //~v50GI~
                        len--;                                     //~v50GI~
                    }                                              //~v50GI~
                    if (len)                                       //~v50GI~
                    {                                              //~v50GI~
                        pwk=wk+strlen(wk);                         //~v50GI~
                        if (!rootsw)    //curr is not to root      //~v50GI~
                            *pwk++='/';                            //~v50GI~
                        memcpy(pwk,pc,len);                        //~v50GI~
                    }                                              //~v50GI~
                }//.                                               //~v50GI~
                else    //not special .                            //~v50GI~
                {                                                  //~v50GI~
                    pwk+=strlen(pwk);                              //~v50GI~
                    if (!rootsw)    //curr is not root             //~v50GI~
                        *pwk++='/';     //add intermediate         //~v50GI~
                    memcpy(pwk,pc,len);                            //~v50GI~
                }                                                  //~v50GI~
            }//not all space                                       //~v50GI~
        }//not from root                                           //~v50GI~
    }                                                              //~v50GI~
    else                                                           //~v50GI~
    if ((*pc)=='/')                //from root                     //~v50GR~
//      strcpy(wk,pc);                                             //~v6hLR~
        ustrncpyz(wk,pc,_MAX_PATH+1);	//up to len=_MAX_PATH,err if so//~v6hLR~
    else                        //from cur dir                     //~0827R~
    {                                                              //~0827R~
        memset(wk,0,sizeof(wk));                                   //~0827R~
        if (*pc=='~' //homedir                                     //~v5b9I~
        &&  (*(pc+1)=='/' || *(pc+1)==0)) // ~ or ~/               //~v5b9R~
        {                                                          //~v5b9I~
            if (!(home=getenv("HOME")))                            //~v5b9I~
                return 0;                                          //~v5b9I~
//          strcpy(wk,home);                                       //~v6hLR~
        	ustrncpyz(wk,home,_MAX_PATH+1);	//up to len=_MAX_PATH,err if so//~v6hLI~
            pc++;                                                  //~v5b9I~
            len--;                                                 //~v5b9I~
            if (len)               // parm is "~/"                 //~v5b9I~
                pc++,len--;                                        //~v5b9I~
        }                                                          //~v5b9I~
        else                                                       //~v5b9I~
        if (!ugetcwd(wk))                                          //~v50GI~
        {                                                          //~0827R~
            uerrmsg("ufullpath:get current dir for %s failed,rc=%d",//~v50GR~
                    "ufullpath:%s の現行ディレクトリー取得の失敗,rc=%d",//~v50GR~//~v777I~
                    Pfilename,errno);                              //~0827R~
            return 0;
        }                                                          //~0827R~
//process "../"
        pwk=wk;
        while ((len>=2 && *pc==SPECIAL_DIRID && *(pc+1)==SPECIAL_DIRID)//~v341R~
            && (len==2 || *(pc+2)==DIR_SEPC)) //.. or ../          //~v341I~
        {                                                          //~0827R~
            pc+=2;                                                 //~v341I~
            len-=2;                                                //~v341I~
        	if (len)                                               //~v341R~
            {                                                      //~v341I~
            	pc++;                                              //~v341I~
                len--;                                             //~v341I~
            }                                                      //~v341I~
            pwk=wk+PATHLEN(wk)-1;                                  //~0827R~
            memset(pwk+1,0,strlen(pwk+1));
            if (pwk!=wk)    //not yet reached to root              //~0827R~
                *pwk=0;    //drop parent dir
        }//loop process parent                                     //~0827R~
//*
        if (len)//filename on input                                //~0827R~
        {                                                          //~0827R~
            rootsw=(strlen(wk)==1);                                //~0827R~
            if ((len && *pc==SPECIAL_DIRID)                        //~v341R~
            &&  (len==1 || *(pc+1)==DIR_SEPC)) //. or ./           //~v341R~
            {
                pc++;                                              //~v341I~
                len--;                                             //~v341I~
                if (len)                                           //~v341R~
                {                                                  //~v341I~
                    pc++;                                          //~v341I~
                    len--;                                         //~v341I~
                }                                                  //~v341I~
                if (len)
                {
                    pwk=wk+strlen(wk);                             //~0827R~
                    if (!rootsw)    //curr is not to root          //~0827R~
                        *pwk++='/';                                //~0827R~
//                 	if (PTRDIFF(pwk,wk)+len>=_MAX_PATH)            //~v6hLR~//~v6B6R~
                   	if ((UINT)PTRDIFF(pwk,wk)+len>=_MAX_PATH)      //~v6B6R~
                    {                                              //~v6m8I~
//  					return (char *)ufileTooLongFullpathName(0/*rc*/);//~v6hLR~//~v6m8R~
    					ufileTooLongFullpathName(0/*rc*/);         //~v6m8I~
    					return 0;                                  //~v6m8I~
                    }                                              //~v6m8I~
                    memcpy(pwk,pc,len);                            //~0827R~
                }                                                  //~0827R~
            }//.                                                   //~0827R~
            else    //not special .                                //~0827R~
            {                                                      //~0827R~
                pwk+=strlen(pwk);                                  //~0827R~
                if (!rootsw)    //curr is not root                 //~0827R~
                    *pwk++='/';     //add intermediate             //~0827R~
//            	if (PTRDIFF(pwk,wk)+len>=_MAX_PATH)                //~v6hLR~//~v6B6R~
              	if ((UINT)PTRDIFF(pwk,wk)+len>=_MAX_PATH)          //~v6B6R~
                {                                                  //~v6m8I~
//  				return (char*)ufileTooLongFullpathName(0/*rc*/);//~v6hLR~//~v6m8R~
    				ufileTooLongFullpathName(0/*rc*/);             //~v6m8I~
    				return 0;                                      //~v6m8I~
                }                                                  //~v6m8I~
                memcpy(pwk,pc,len);                                //~0827R~
            }                                                      //~0827R~
        }//not all space                                           //~0827R~
    }//not root dir specified                                      //~0827R~
    ufullpathresolvespecialdirid(wk,DIR_SEPC);   //resolve ./ and ..///~v5kdR~
//  if ((len=strlen(wk))>rootpos+1 		//not root                 //~v50GR~//~v6BxR~
    if ((len=(UINT)strlen(wk))>rootpos+1 		//not root         //~v6BxI~
    &&  PATHLEN(wk)==len)   //last is '/'                          //~0827R~
    {
        *(wk+len-1)=0;                                             //~0827R~
        len--;
    }
    if (Plen<=len)
    {                                                              //~v6m8I~
    //  return 0;                                                  //~v6hLR~
//  	return (char*)ufileTooLongFullpathName(0/*rc*/);           //~v6hLR~//~v6m8R~
    	ufileTooLongFullpathName(0/*rc*/);                         //~v6m8I~
    	return 0;                                                  //~v6m8I~
    }                                                              //~v6m8I~
    strcpy(Pfullpath,wk);                                          //~0827R~
    UTRACEP("%s:rc=%s,pfnm=%s\n",UTT,Pfullpath,Pfilename);         //~v70bR~
    return Pfullpath;                                              //~0827R~
}//ufullpath
//*******************************************************
//*get file path name length(length containing last '/' from top)
//*parm 1:filename
//*return:length, <0 if err
//*******************************************************
int upathlen(char *Pfilename)
{
    char *pc;                                                      //~0827R~
//*********************************
    if (pc=ustrrchr2(Pfilename,'/'),!pc)
        return -16;     //avoid -1                                 //~0827R~
    return (int)((ULONG)pc-(ULONG)Pfilename)+1;                    //~0827R~
}//upathlen
//*******************************************************
//*get current dir fullpath
//*parm  :output buff
//*return:ptr to buff
//*******************************************************
char *ugetcwd(unsigned char *Pbuff)
{
	char *pcwd;                                                    //+v786I~
//*********************************
#ifdef ARMXXE                                                      //~v77ZR~
	if (ufiledoc_cwd(Pbuff))                                       //~v77ZI~
    	return Pbuff;                                              //~v77ZI~
#endif                                                             //~v77ZR~
//  return getcwd(Pbuff,_MAX_PATH);                                //+v786R~
    pcwd=getcwd(Pbuff,_MAX_PATH);                                  //+v786I~
    UTRACEP("%s:rc=%s\n",UTT,pcwd);                                //+v786I~
    return pcwd;                                                   //+v786I~
}//ugetcwd
//*******************************************************
//*change current directory
//*parm 1:path name
//*return:0:ok else err
//*******************************************************
//int uchdir(unsigned char *Ppath)                                 //~v578R~
int uchdir(int Popt,unsigned char *Ppath)                          //~v578I~
{
    int rc;                                                        //~0827R~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//*********************************
	UTRACEP("%s:Ppath=%s,opt=0x%x\n",UTT,Ppath,Popt);              //~v7ZAI~
#ifdef ARMXXE                                                      //~v77ZR~
	if (ufiledoc_chdir(Popt,Ppath,&rc))                            //~v77ZI~
		return rc;                                                 //~v77ZR~
#endif                                                             //~v77ZR~
#ifdef FTPSUPP                                                     //~v59nI~
  	if (uftpisremote(Ppath,&puftph))	//ftp filename             //~v5afR~
 		return uftpchdir(puftph,Popt,Ppath);                       //~v5afR~
#endif                                                             //~v59nI~
  if (MDOSDISKOK(Ppath))                                           //~v55fR~
  {                                                                //~v55nI~
    rc=uchdir_mdos(Ppath);                                         //~v55fR~
#ifdef AIX                                                         //~v55nI~
    if (rc==ENOSYS)                                                //~v55nI~
        return rc;                                                 //~v55nI~
#endif                                                             //~v55nI~
  }                                                                //~v55nI~
  else                                                             //~v55fR~
    rc=chdir(Ppath);
    if (rc)                                                        //~0827R~
    {
        rc=errno;                                                  //~0827R~
      if (!(Popt & UCHD_NOMSG))		//not no errmsg option         //~v578I~
      {                                                            //~v77uI~
//#ifdef ARMXXE                                                      //~v77uI~//~v7ZAR~
//       if (IS_DOCPATH(Ppath))                                       //~v77uI~//~v7ZAR~
//        uerrmsg("\"cd\" is not supported for shared storage(%s)",  //~v77uI~//~v7ZAR~
//                "\"cd\" コマンドは共有ストレージでは無効です(%s)", //~v77uI~//~v7ZAR~
//                Ppath);                                            //~v77uI~//~v7ZAR~
//       else                                                        //~v77uI~//~v7ZAR~
//#endif                                                             //~v77uI~//~v7ZAR~
        uerrmsg("Set current directory failed for %s(rc=%d)",      //~0827R~
                "現行ディレクトリー設定の失敗(%s,rc=%d)",          //~v777I~
                Ppath,rc);
      }                                                            //~v77uI~
    }                                                              //~0827R~
#ifdef ARMXXE                                                      //~v786I~
    else                                                           //~v786I~
		ufiledoc_setArmPWD(Popt,Ppath);                            //~v786I~
#endif                                                             //~v786I~
	UTRACEP("%s:rc=%d,path=%s\n",UTT,rc,Ppath);                    //~v7ZAI~
    return rc;                                                     //~0827R~
}//uchdir
//**********************************************************************
// udosfindfirstnomsg(no notfound err msg)
// parm1  :file name
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0
// parm3  :search file attribute
// parm4  :found file info
// return :r.c
//**********************************************************************
unsigned udosfindfirstnomsg(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,
                        FILEFINDBUF3 *Ppfstat3)                    //~0827R~
{
    unsigned rc;                                                   //~0827R~
//*********************************
    Snomsgff=1;                                                    //~0827R~
    rc=udosfindfirst(Ppfname,Pphdir,Pattr,Ppfstat3);               //~0827R~
    Snomsgff=0;                                                    //~0827R~
    Snomsgffnext=1;                                                //~v6k7I~
    return rc;
}//udosfindfirstnomsg
#ifdef ARMXXE                                                      //~v782I~
//**********************************************************************//~v782I~
//*under !(Pphdir || wildsw)                                       //~v782I~
//*for the case findnext doose not returns "."                     //~v782I~
//**********************************************************************//~v782I~
int isSharedDocMemberFF(char *Ppfname,FILEFINDBUF3 *Ppfstat3)      //~v782R~
{                                                                  //~v782I~
	FILEFINDBUF3 fstat3;                                           //~v782I~
	int rc=0;                                                      //~v782I~
    if (IS_DOCPATH(Ppfname))                                       //~v782I~
    	rc=1;                                                      //~v782I~
    else                                                           //~v782I~
	if (ufile_isGrantedAllFiles())                                      //~v77zI~//~v782I~
    	rc=1;                                                      //~v782I~
    if (rc)                                                        //~v782I~
    {                                                              //~v782I~
	    if (ufstat(Ppfname,&fstat3))  //exist as file              //~v782I~
    		rc=0;                                                  //~v782I~
        else                                                       //~v782I~
			memcpy(Ppfstat3,&fstat3,sizeof(FILEFINDBUF3));  //parent stat when Phdir=0//~v782I~
    }                                                              //~v782I~
	UTRACEP("%s:rc=%d,fnm=%s,member=%s\n",UTT,rc,Ppfname,Ppfstat3->achName);//~v782R~
    return rc;                                                     //~v782I~
}                                                                  //~v782I~
#endif //ARMXXE                                                    //~v782I~
//**********************************************************************
// find first
// parm1  :file name
//         opendir fail if wild card for UNX                       //~0901I~
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0
// parm3  :search file attribute
// parm4  :found file info
// return :r.c
//**********************************************************************
unsigned udosfindfirst(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,
                        FILEFINDBUF3 *Ppfstat3)                    //~0827R~
{
    HDIR   *phdir;
    unsigned rc=0;                                                   //~0827R~//~v6h9R~
    int pathlen,wildsw,mdossw;                                     //~v55nR~
    UCHAR dirnm[_MAX_PATH],*pdirnm;                                //~0901I~
    PUDIRLIST  pudl;                                               //~v50GR~
#ifdef FTPSUPP                                                     //~v59nI~
    int ftpopt;                                                    //~v59nR~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v59nI~
    HDIR   hdir_wild=0;                                            //~v6b1R~
//#ifdef ARMXXE                                                      //~v780I~//~v782R~
//    int swDirDocNotWild=0;                                         //~v780I~//~v782R~
//#endif                                                             //~v780I~//~v782R~
//*********************************
	UTRACEP("%s:fnm=%s,attr=0x%x,Pphdir=%p\n",UTT,Ppfname,Pattr,Pphdir);             //~v77dI~//~v782R~
    Snomsgffnext=0;                                                //~v6k7I~
    SdirlistOtherAttrCtr=0;                                        //~v6kmI~
#ifdef FTPSUPP                                                     //~v59nI~
  	if (uftpisremote(Ppfname,&puftph))	//ftp filename             //~v5afR~
    {                                                              //~v59nI~
        ftpopt=UFTPFF_NOMSG*(Snomsgff!=0);	//no delete ok msg sw  //~v59nI~
//  	return uftpfindfirst(puftph,ftpopt,Ppfname,Pphdir,Pattr,Ppfstat3);//~v5afR~//~v6B6R~
    	return (unsigned)uftpfindfirst(puftph,ftpopt,Ppfname,Pphdir,Pattr,Ppfstat3);//~v6B6I~
    }                                                              //~v59nI~
#endif                                                             //~v59nI~
  	mdossw=MDOSDISKOK(Ppfname);                                    //~v55nI~
    if (!(phdir=Pphdir))
        phdir=&Shdirfirst;
    if (pathlen=PATHLEN(Ppfname),pathlen<0)                        //~v50JM~
    	pathlen=0;                                                 //~v50JM~
//if (MDOSDISK(Ppfname) && Gufile_opt & GFILEOPT_LNXMTOOL)	//use mtool//~v55nR~
//{                                                                //~v55nR~
//  Pattr|=FILE_MDOSDISK;                                          //~v55nR~
//  rc=udosfindfirst_mdos(Ppfname,&pudl,Pattr);                    //~v55nR~
//  *phdir=(HDIR)(ULONG)pudl;                                      //~v55nR~
//  if (!WILDCARD(Ppfname+pathlen))  //opendir fail if wild card   //~v55nR~
//      pathlen=strlen(Ppfname);                                   //~v55nR~
//}                                                                //~v55nR~
//else                                                             //~v55nR~
//{                                                                //~v55nR~
    if (WILDCARD(Ppfname+pathlen))  //opendir fail if wild card    //~0901R~
    {                                                              //~0901I~
    	UTRACEP("%s:opendir wildcard Ppfname=%s\n",UTT,Ppfname);   //~v77dI~
#ifdef ARMXXE                                                      //~v77dM~
        if (IS_DOCPATH(Ppfname))                                   //~v77dR~
        {                                                          //~v77dR~
            void *pvoid;                                           //~v77dR~
            errno=ufile_opendirDoc(Ppfname,&pvoid);                //~v77dR~
            hdir_wild=(ULONG)pvoid; //existing wildname file       //~v77dR~
        }                                                          //~v77dR~
        else                                                       //~v77dR~
            hdir_wild=(ULONG)opendir(Ppfname);  //existing wildname file//~v77dR~
    	UTRACEP("%s:opendir hdir_wild=%p,wildcard Ppfname=%s\n",UTT,hdir_wild,Ppfname);//~v77wI~
      if (hdir_wild)	//existing wildname file                   //~v77dR~
#else                                                              //~v77dI~
  	  if (!mdossw                                                  //~v6b1I~
      && (hdir_wild=(ULONG)opendir(Ppfname)))	//existing wildname file//~v6b1R~
#endif                                                             //~v77dI~
      {                                                            //~v6b1I~
      	wildsw=0;	//real name                                    //~v6b1I~
//      pathlen=strlen(Ppfname);                                   //~v6b1I~//~v6B6R~
        pathlen=(int)strlen(Ppfname);                              //~v6B6I~
        pdirnm=Ppfname;                                            //~v6b1I~
      	UTRACEP("%s:hdir_wild=%p set wildsw=0,pathlen=%d,pdirnm=%s\n",UTT,hdir_wild,pathlen,pdirnm);//~v77dI~
      }                                                            //~v6b1I~
      else                                                         //~v6b1I~
      {                                                            //~v6b1I~
    	wildsw=1;                                                  //~0901I~
    	if (!pathlen)    //no / found(not fullpath name)           //~0901R~
            strcpy(dirnm,"./"); //curr dir                         //~0901I~
        else                                                       //~0901I~
        {                                                          //~0901I~
        	memcpy(dirnm,Ppfname,(UINT)pathlen);                   //~0901R~
//with last "/",permision err when no x-bit                        //~v371R~
//without last "/",permision err when stat of member (".")         //~v371I~
        	*(dirnm+pathlen)=0;                                    //~v371I~
        }                                                          //~0901I~
        pdirnm=dirnm;                                              //~0901I~
      	UTRACEP("%s:hdir_wild=%p,set wildsw=1,pathlen=%d,pdirnm=%s\n",UTT,hdir_wild,pathlen,pdirnm);//~v77dI~
      }                                                            //~v6b1I~
    }                                                              //~0901I~
    else                                                           //~0901I~
    {                                                              //~0901I~
    	wildsw=0;                                                  //~0901I~
//      pathlen=strlen(Ppfname);                                   //~v50xI~//~v6B6R~
        pathlen=(int)strlen(Ppfname);                              //~v6B6I~
        pdirnm=Ppfname;                                            //~0901I~
    }                                                              //~0901I~
  if (mdossw)                                                      //~v55nR~
  {                                                                //~v55nI~
    Pattr|=FILE_MDOSDISK;                                          //~v55nI~
    rc=uopendir_mdos(pdirnm,&pudl);                                //~v55nR~
    *phdir=(HDIR)(ULONG)pudl;                                      //~v55nI~
  }                                                                //~v55nI~
  else                                                             //~v55nI~
  {                                                                //~v55nI~
   if (hdir_wild)                                                  //~v6b1R~
    *phdir=hdir_wild;                                              //~v6b1R~
   else                                                            //~v6b1I~
   {                                                               //~v777I~
//#ifdef ARM                                                         //~v777I~//~v779R~
//    if (SdirFD!=-1)                                                //~v777I~//~v779R~
//    *phdir=(ULONG)fdopendir(SdirFD);                               //~v777I~//~v779R~
//    else                                                           //~v777I~//~v779R~
//#endif                                                             //~v777I~//~v779R~
    UTRACEP("%s:opendir pdirnm=%s\n",UTT,pdirnm);                  //~v77dI~
#ifdef ARMXXE                                                     //~v77dI~
    if (IS_DOCPATH(pdirnm))                                       //~v77dI~
    {                                                              //~v77dI~
    void *pvoid;                                                   //~v77dR~
    errno=ufile_opendirDoc(pdirnm,&pvoid);                         //~v77dI~
    *phdir=(HDIR)pvoid;                                            //~v77dI~
//    if (pvoid)                                                     //~v780I~//~v782R~
//        swDirDocNotWild=1;                                         //~v780I~//~v782R~
    }                                                              //~v77dI~
    else                                                           //~v77dI~
#endif                                                             //~v77dI~
    *phdir=(ULONG)opendir(pdirnm);                                 //~0901R~
   }                                                               //~v777I~
  }//mdos or not                                                   //~v50GI~
    UTRACEP("%s:opendir phdir=%p,pdirnm=%s,errno=%d\n",UTT,*phdir,pdirnm,errno);   //~v77wI~//~v780R~//~v782R~//~v785R~
    if (!*phdir)
    {                                                              //~0901I~
	  if (!(Pattr & FILE_MDOSDISK))                                //~v50GI~
      {                                                            //~v50GI~
//      rc=errno;                                                  //~v6B6R~
        rc=(unsigned)errno;                                        //~v6B6I~
        if (rc==ENOTDIR && !wildsw)    //may be file(not wildcard case)//~0901R~
        {                                                          //~v777I~
//#ifdef ARM                                                         //~v777I~//~v779R~
//            if (SdirFD!=-1)                                        //~v777I~//~v779R~
//            {                                                      //~v777I~//~v779R~
//                return ufilenotdir(Ppfname,ENOTDIR);               //~v777I~//~v779R~
//            }                                                      //~v777I~//~v779R~
//#endif                                                             //~v777I~//~v779R~
            if (!ufstat(Ppfname,Ppfstat3))  //exist as file        //~0901R~
//              if (ufilelnxattrselect(Ppfstat3->attrFile,Pattr))   //attr match//~v56nR~
                if (ufilelnxattrselect(Ppfstat3->attrFile,Ppfstat3->srcattr,Pattr))   //attr match//~v56nR~
                    return 0;                                      //~0901R~
        }                                                          //~v777I~
        if (rc==EACCES)                                            //~v371M~
//        	return ufilenopermission("opendir",pdirnm,rc);         //~v371I~//~v6B6R~
          	return (unsigned)ufilenopermission("opendir",pdirnm,(int)rc);//~v6B6I~
      }//not disket                                                //~v50GI~
    }                                                              //~0901I~
    else
    {
#ifdef ARMXXE                                                      //~v782I~
//   if (!Pphdir && isSharedDocMemberFF(Ppfname,Ppfstat3)) //under !(Pphdir || wildsw)//~v782I~//~v785R~
     if (!Pphdir && isSharedDocMemberFF(pdirnm,Ppfstat3)) //under !(Pphdir || wildsw), parent if wildcard//~v785I~
     {                                                             //~v782I~
    	UTRACED("Phdir=null return parent stat",Ppfstat3,sizeof(FILEFINDBUF3));//~v782I~
        if (*phdir)                                                //~v782I~
//          if (rc=(unsigned)ufilelnxclosehdir(*phdir),rc)//free handle//~v782R~
			if (rc=(unsigned)closedir((DIR *)(*phdir)),rc)        //relese  handle//~v782I~
    	    	return rc;                                         //~v782I~
     }                                                             //~v782I~
     else                                                          //~v782I~
#endif                                                             //~v782I~
     {                                                             //~v782M~
//      if (rc=ufilelnxsavehdir(*phdir,Pattr,Ppfname,pathlen),rc)  //~v6B6R~
        if (rc=(unsigned)ufilelnxsavehdir(*phdir,Pattr,Ppfname,pathlen),rc)//~v6B6I~
            return rc;
      for (;;)                                                     //~v5kaI~
      {                                                            //~v5kaI~
//      rc=udosfindnext(*phdir,Ppfstat3);                          //~v6hLR~
        rc=udosfindnext(Ppfname,*phdir,Ppfstat3);                  //~v6hLI~
        if (rc)                                                    //~v5kaI~
            break;                                                 //~v5kaI~
        if (Pphdir || wildsw)  //request for findnext or wildcard  //~v5kaI~
            break;                                                 //~v5kaI~
//#ifdef ARMXXE                                                      //~v780I~//~v782R~
//        if (swDirDocNotWild)                                       //~v780I~//~v782R~
//        {                                                          //~v780I~//~v782R~
//            if (!*(Ppfname+pathlen))                               //~v780I~//~v782R~
//            {                                                      //~v780I~//~v782R~
//                UTRACEP("%s:notWild opendirDoc,findnext returns %s for %s(pathlen=%d)\n",UTT,Ppfstat3->achName,Ppfname,pathlen);//~v780R~//~v782R~
//                break;                                             //~v780I~//~v782R~
//            }                                                      //~v780I~//~v782R~
//        }                                                          //~v780I~//~v782R~
//#endif                                                             //~v780I~//~v782R~
    	if (!strcmp(Ppfstat3->achName,Ppfname+pathlen))	//from xcopy/xmove;Pphdir=null and readnext returns "."/".." when path is wildname dir//~v6b1I~
	    	break;	//when return at "." fstat indicate dir attribute//~v6b1I~
	  	if (Pattr & FILE_MDOSDISK)                                 //~v5kxR~
            break;                                                 //~v5kxR~
    	if (!strcmp(Ppfstat3->achName,"."))	//search current dir entry to get attr//~v5kaI~
	    	break;                                                 //~v5kaI~
//#ifdef ARMXXE                                                    //~v782R~
//        if (isSharedDocMemberFF(Ppfname,Pphdir,Ppfstat3)) //under !(Pphdir || wildsw)//~v782R~
//            break;                                               //~v782R~
//#endif                                                           //~v782R~
      }                                                            //~v5kaI~
        if (rc==4)                                                 //~v387R~
//          rc=ERROR_FILE_NOT_FOUND;                               //~v5d9R~
            rc=ERROR_NO_MORE_FILES;                                //~v5d9I~
        if (!rc)
            if (!Pphdir)     //handle return not required for find next
//              if (rc=ufilelnxclosehdir(*phdir),rc)//free handle  //~v6B6R~
                if (rc=(unsigned)ufilelnxclosehdir(*phdir),rc)//free handle//~v6B6I~
                    return rc;
     }//isShared                                                   //~v782M~
    }
    if(rc)                                                         //~0827R~
    {                                                              //~0827R~
        if(rc==ERROR_NO_MORE_FILES                                 //~0827R~
        || rc==ERROR_FILE_NOT_FOUND                                //~0827R~
        || rc==ERROR_PATH_NOT_FOUND)                               //~0827R~
        {
          if (!Snomsgff)                                           //~0827R~
          {                                                        //~v5d9I~
//          ufilenotfound(pdirnm,(int)rc);                         //~v397R~
           if(rc==ERROR_NO_MORE_FILES)                             //~v5d9R~
           {                                                       //~v77AI~
//#ifdef UTF8SUPP                                                    //~v62bI~//~v62jR~
#ifdef UTF8SUPPH                                                   //~v62jI~
//          if (!(Pattr & FILE_DIRECTORY))                         //~v6kmR~
//          rc=ufileerrnofileentry(Ppfname,ERROR_FILE_NOT_FOUND);  //~v6kmR~
        	if (SdirlistOtherAttrCtr)                              //~v6kmI~
//  			rc=ufilenotfoundotherexist(Ppfname,ERROR_FILE_NOT_FOUND);//~v6kmI~//~v6B6R~
    			rc=(unsigned)ufilenotfoundotherexist(Ppfname,ERROR_FILE_NOT_FOUND);//~v6B6I~
            else                                                   //~v62bI~
#endif                                                             //~v62bI~
//          rc=ufileerrnoentry(Ppfname,ERROR_FILE_NOT_FOUND);      //~v5d9I~//~v6B6R~
#ifdef ARMXXE                                                      //~v77AI~//~v784R~
	      if (SswFFopt & UDFFOO_ERRNOENTRY)                        //~v784I~
            rc=(unsigned)ufileerrnoentry(Ppfname,ERROR_FILE_NOT_FOUND);//~v784I~
          else                                                     //~v784I~
            rc=(unsigned)ufileerrnoentry(Ppfname,ERROR_NO_MORE_FILES);    //return 0 to process filectr=0 by xedir//~v77AR~//~v784R~
#else                                                              //~v77AI~//~v784R~
            rc=(unsigned)ufileerrnoentry(Ppfname,ERROR_FILE_NOT_FOUND);//~v6B6I~
#endif                                                             //~v77AI~//~v784R~
           }                                                       //~v77AI~
           else                                                    //~v5d9I~
            ufilenotfound(Ppfname,(int)rc);                        //~v397I~
          }//msgsw                                                 //~v5d9I~
        }                                                          //~0827R~
        else                                                       //~0827R~
        	if (rc!=EACCES)	//not yet msg                          //~v371I~
            	ufileapierr("udosfindfirst",Ppfname,(int)rc);      //~v371R~
    }                                                              //~0827R~
    return rc;                                                     //~0827R~
}//udosfindfirst
//**********************************************************************
// find next
// parm1  :HDIR specified at findfirst. for dos specify always 0
// parm2  :found file info
// return :r.c  0:found 4:no more file else errno                  //~v371R~
//**********************************************************************
//unsigned udosfindnext(HDIR Phdir,FILEFINDBUF3 *Ppfstat3)         //~v6hLR~
unsigned udosfindnext(char *Ppfname,HDIR Phdir,FILEFINDBUF3 *Ppfstat3)//~v6hLI~
{                                                                  //~v6k7I~
	int nomsg;                                                     //~v6k7I~
    unsigned rc;                                                   //~v6k7I~
unsigned udosfindnextmsg(char *Ppfname,HDIR Phdir,FILEFINDBUF3 *Ppfstat3);//~v6k7I~
//************************                                         //~v6k7I~
	nomsg=Snomsgff;                                                //~v6k7I~
    Snomsgff=Snomsgffnext;                                         //~v6k7I~
	rc=udosfindnextmsg(Ppfname,Phdir,Ppfstat3);                    //~v6k7I~
//  Snomsgff=nomsg;                                                //~v6k7I~//~v6B6R~
    Snomsgff=(char)nomsg;                                          //~v6B6I~
    return rc;                                                     //~v6k7I~
}                                                                  //~v6k7I~
//**********************************************                   //~v6k7I~
unsigned udosfindnextmsg(char *Ppfname,HDIR Phdir,FILEFINDBUF3 *Ppfstat3)//~v6k7I~
{
    HDIR   hdir;
    PDIRENT pde;
    ULONG attr;
    UCHAR *path;                                                   //~0827I~
    int    rc,pathlen;                                             //~0901R~
    int rc2;                                                       //~v56nR~
    int mdossw;                                                    //~v55nR~
    int swlongname=0;                                              //~v6H1I~
//*********************************
    UTRACEP("%s:fnm=%s\n",UTT,Ppfname);                            //~v77dI~
#ifdef FTPSUPP                                                     //~v59nI~
    if (((ULONG)Phdir & FTP_HDIRMASK)==FTP_HDIRID)	//special hdir for FTP//~v59nI~
//  	return uftpfindnext(Phdir,Ppfstat3);                       //~v59nR~//~v6B6R~
    	return (unsigned)uftpfindnext((int)Phdir,Ppfstat3);        //~v6B6R~
#endif                                                             //~v59nI~
    if (!(hdir=Phdir))
        hdir=Shdirfirst;
//  UTRACEP("%s:ufilelnxsrchhdir call\n",UTT);                     //~v70bR~
    if (rc=ufilelnxsrchhdir(hdir,&attr,&path,&pathlen),rc)         //~0901R~
//      return rc;                                                 //~v6B6R~
        return (unsigned)rc;                                       //~v6B6I~
//if (attr & FILE_MDOSDISK)                                        //~v55nR~
//  	rc=udosfindnext_mdos(&Shdirpudl[Shdirindex],path,pathlen,attr,Ppfstat3);//~v55nR~
    mdossw=(attr & FILE_MDOSDISK);                                 //~v55nI~
//else                                                             //~v55nR~
//{                                                                //~v55nR~
//      UTRACEP("%s:path=%s\n",UTT,path);                          //~v70bR~
    for (;;)
    {
        errno=0;
      if (mdossw)                                                  //~v55nI~
      {                                                            //~v55nI~
//  	rc=ureaddir_mdos(&Shdirpudl[Shdirindex],path,pathlen,attr,Ppfstat3);//~v55nI~//~v6B6R~
    	rc=(int)ureaddir_mdos(&Shdirpudl[Shdirindex],path,pathlen,attr,Ppfstat3);//~v6B6I~
        if (rc)                                                    //~v55nI~
            break;                                                 //~v55nI~
        if (WILDCARD(path+pathlen))	//wildcard                     //~v55nI~
	        if (!ufilelnxwildselect(Ppfstat3->achName,path+pathlen,mdossw))//~v55nR~
            	continue;		//wildcard unmatch                 //~v55nI~
      }                                                            //~v55nI~
      else                                                         //~v55nI~
      {                                                            //~v55nI~
//#ifdef ARMXXE              //ulibarm.h redirect to ufile_readdirDoc thru ufiledoc_readdir//~v77dI~//~v77wR~
//        if (IS_DOCDIRH(hdir))                                      //~v77dI~//~v77wR~
//            pde=ufile_readdirDoc((DIR*)hdir);                      //~v77dR~//~v77wR~
//        else                                                       //~v77dI~//~v77wR~
//#endif                                                             //~v77dI~//~v77wR~
        pde=readdir((DIR*)hdir);
        if (!pde)
        {
            rc=errno;                                              //~0827R~
	    	UTRACEP("%s:readdir return null errno=%d\n",UTT,rc);   //~v77wI~
            if (!rc)    //no err                                   //~0827R~
                rc=ERROR_NO_MORE_FILES;                            //~0827R~
            break;
        }
	    UTRACEP("%s:readdir d_name=%s\n",UTT,pde->d_name);         //~v77dI~
//      UTRACED("udosfindnext pde",pde,pde->d_reclen);             //~v6b1I~//~v6q2R~//~v70bR~
//      UTRACEP("%s:udosfindnext pde->d_name=%s\n",UTT,pde->d_name);//~v70bR~
//      if (WILDCARD(pde->d_name))	//wildcard file/dirname        //~v39YI~//~v77kR~
//      {                                                          //~v6b0I~//~v77kR~
//  		errwildname(0,pde->d_name,path);                       //~v6b1R~//~v77kR~
//        if (!(Gufile_opt & GFILEOPT_WILDCARDNAMEOK))             //~v6b1R~//~v77kR~
//          continue;               //ignore it,it cause segfault by double closedir//~v77kR~
//      }                                                          //~v6b0I~//~v77kR~
        rc=0;
        if (WILDCARD(path+pathlen))	//wildcard                     //~0901R~
        {                                                          //~v6kaI~
//          UTRACEP("findnext wildselect d_name=%s,wild=%s\n",pde->d_name,path+pathlen);//~v6kaI~//~v6q2R~
	        if (!ufilelnxwildselect(pde->d_name,path+pathlen,mdossw))//~v55nR~
            {                                                      //~v70bI~
//            	UTRACEP("%s:ufilelnxwildselect rc=0,unmatch\n",UTT);//~v70bR~
            	continue;		//wildcard unmatch                 //~0901I~
            }                                                      //~v70bI~
//          UTRACEP("findnext wildselect selected\n");               //~v6kaI~//~v6q2R~//~v70bR~
        }                                                          //~v6kaI~
        if (WILDCARD(pde->d_name))	//wildcard file/dirname        //~v77kI~
        {                                                          //~v77kI~
    		errwildname(0,pde->d_name,path);                       //~v77kI~
          if (!(Gufile_opt & GFILEOPT_WILDCARDNAMEOK))             //~v77kI~
            continue;               //ignore it,it cause segfault by double closedir//~v77kI~
        }                                                          //~v77kI~
//      if (rc=ufilelnxgetmembfstat(Ppfstat3,pde,path,pathlen),rc) //~v3a2R~
//      	break;                                                 //~v3a2R~
//      if (ufilelnxgetmembfstat(Ppfstat3,pde,path,pathlen))       //~v56aR~
//          continue;                                              //~v56aR~
        rc2=ufilelnxgetmembfstat(Ppfstat3,pde,path,pathlen);       //~v56aI~
//      UTRACEP("%s:rc2=%d\n",UTT,rc2);                            //~v70bR~
        if (rc2)                                                   //~v56aI~
        {                                                          //~v56aI~
        	if (rc2==EACCES)                                       //~v56rR~
            	if (!strcmp(pde->d_name,"."))	//cur dir	permission err//~v56aI~
                {                                                  //~v56aI~
		        	rc=rc2;		//EACCES                           //~v56aI~
                	break;	//stop readdir                         //~v56aI~
                }                                                  //~v56aI~
        	if (rc2==ENAMETOOLONG)                                 //~v6H1I~
            {                                                      //~v6H1I~
                UTRACEP("%s:TooLongName %s and  %s\n",UTT,path,pde->d_name);//~v6H1M~
                if (strlen(pde->d_name)<(int)sizeof(Ppfstat3->achName))//~v6H1R~
                {                                                  //~v6H1I~
            		swlongname=1;                                  //~v6H1I~
                	strcpy(Ppfstat3->achName,pde->d_name);         //~v6H1R~
//                  Ppfstat3->attrFile=FILE_TOOLONGNM;  //continue but set rc  //TooLongFileName(not FTP)//~v6H1I~
                }                                                  //~v6H1I~
                else                                               //~v6H1I~
                	rc=rc2;                                        //~v6H1I~
                break;	//select this entry                        //~v6H1M~
            }                                                      //~v6H1I~
            continue;                                              //~v56aI~
        }                                                          //~v56aI~
      }//mdos                                                      //~v55nI~
//      if (ufilelnxattrselect(Ppfstat3->attrFile,attr))    //attr match//~v56nR~
        if (ufilelnxattrselect(Ppfstat3->attrFile,Ppfstat3->srcattr,attr))    //attr match//~v56nI~
            break;
        if (swlongname)                                            //~v6H1I~
        	break;                                                 //~v6H1I~
      if ((!strcmp(Ppfstat3->achName,".") || !strcmp(Ppfstat3->achName,".."))//~v783I~
	  &&  !(attr & FILE_DIRECTORY))                                //~v783I~
      {                                                            //~v783I~
    	UTRACEP("%s:skip otherctrUp by . or ..\n",UTT);            //~v783I~
      }                                                            //~v783I~
      else                                                         //~v783I~
        SdirlistOtherAttrCtr++;                                    //~v6kmI~
    	UTRACEP("%s:otherattrctr=%d,member=%s\n",UTT,SdirlistOtherAttrCtr,Ppfstat3->achName);//~v782I~
    }
//}//msdos or else                                                 //~v55nR~

    if (rc==ERROR_NO_MORE_FILES)                                   //~0827R~
    {                                                              //~0827R~
        ufilelnxclosehdir(hdir);
        return 4;  //no more file                                  //~0827R~
    }                                                              //~0827R~
    else                                                           //~0827R~
        if (rc)                                                    //~0827R~
        {                                                          //~v371I~
	        ufilelnxclosehdir(hdir);                               //~v371I~
//          uerrexit("udosfindnext failed,rc=%d",                  //~v371R~
            if (rc!=EACCES) //not yet msg                          //~v371I~
            	uerrmsg("udosfindnext failed,rc=%d",               //~v371I~
                        "udosfindnext の失敗,リターンコード=%d",   //~0827R~//~v777I~
                        rc);                                       //~0827R~
//          return rc;                                             //~v371I~//~v6B6R~
            return (unsigned)rc;                                   //~v6B6I~
        }                                                          //~v371I~
    UTRACEP("%s:return 0 otherattrctr=%d,member=%s\n",UTT,SdirlistOtherAttrCtr,Ppfstat3->achName);//~v782I~
    return 0;                                                      //~0827R~
}//udosfindnext
//*******************************************************          //~0901I~
//*get dir member stat                                             //~0901I~
//*parm 1:filename                                                 //~v55nR~
//*parm 2:wildcard patern                                          //~v55nR~
//*parm 3:mdos sw                                                  //~v55nR~
//*return:1:filename matched to wildcard,0:unmatch                 //~0901I~
//*******************************************************          //~0901I~
int ufilelnxwildselect(UCHAR *Pfname,UCHAR *Pwildcard,int Pmdossw) //~v55nR~
{                                                                  //~0901I~
//  UCHAR targetname[_MAX_PATH];                                   //~v56yR~
    int wcopt;                                                     //~v56yI~
//*************                                                    //~0901I~
//  ufileeditname(Pfname,Pwildcard,targetname);                    //~v56yR~
    wcopt=UFWC_DOS_DEFAULT | UFWC_CASE_DEFAULT | UFWC_0BYTE;       //~v56yI~
    if (Pmdossw)                                                   //~v55nI~
    	wcopt&=~UFWC_CASE;  //case insensitive                     //~v56yI~
//  	return !stricmp(targetname,Pfname);                        //~v56yR~
//  return !strcmp(targetname,Pfname);                             //~v56yR~
    return ufilewildcomp(wcopt,Pfname,Pwildcard,0)==0;             //~v56yR~
}//ufilelnxwildselect                                              //~0901I~
//*******************************************************          //~0901I~
//*select member by attr specified                                 //~0901I~
//*parm 1:file attr                                                //~0901I~
//*parm 2:file attr of slink src                                   //~v56nI~
//*parm 3:parm attr(select req)                                    //~v56nR~
//*return:1:ok,0:ng                                                //~0901I~
//*******************************************************          //~0901I~
//int ufilelnxattrselect(ULONG Pfattr,ULONG Ppattr)                //~v56nR~
int ufilelnxattrselect(ULONG Pfattr,ULONG Pfattrsrc,ULONG Ppattr)  //~v56nI~
{                                                                  //~0901I~
//  unsigned int wattrf,wattrp,modef,modep;                        //~v56cR~
    unsigned int modef,modep;                                      //~v56cI~
//*********************************                                //~0901I~
	UTRACEP("%s:file attr=0x%x,slink attr=0x%x,select attr=0x%x\n",UTT,Pfattr,Pfattrsrc,Ppattr);//~v780I~
  if (!(Pfattr & FILE_MDOSDISK))                                   //~v56nR~
  {                                                                //~v56nI~
//  modef=FILE_GETMODE(Pfattr);                                    //~v50JI~//~v6BxR~
    modef=(UINT)FILE_GETMODE(Pfattr);                              //~v6BxI~
//  modep=FILE_GETMODE(Ppattr);                                    //~v50JI~//~v6BxR~
    modep=(UINT)FILE_GETMODE(Ppattr);                              //~v6BxI~
	UTRACEP("%s:mode file=0x%x,mode select=0x%x\n",UTT,modef,modep);//~v780I~
   if (!(Ppattr & FILE_SPECIAL))  //select reguler file only       //~v56sR~
   {                                                               //~v56sI~
    if (Pfattr & FILE_SPECIAL)  //select reguler file only         //~v56sR~
    	return 0;                                                  //~v56sI~
   }                                                               //~v56sI~
   else                                                            //~v56sI~
   {                                                               //~v56sI~
    if (S_ISLNK(modef))//symbolic link                             //~v56nR~
//  	modef=FILE_GETMODE(Pfattrsrc);                             //~v56nI~//~v6BxR~
    	modef=(UINT)FILE_GETMODE(Pfattrsrc);                       //~v6BxI~
//  if (S_ISCHR(modef) && !S_ISCHR(modep))                         //~v56sR~
    if (S_ISCHR(modep))       //req char only                      //~v56sR~
      if (!S_ISCHR(modef))                                         //~v56sI~
    	return 0;                                                  //~v50JI~
//  if (S_ISBLK(modef) && !S_ISBLK(modep))                         //~v56sR~
    if (S_ISBLK(modep))       //req blk only                       //~v56sI~
	  if (!S_ISBLK(modef))                                         //~v56sI~
    	return 0;                                                  //~v50JI~
//  if (S_ISFIFO(modef) && !S_ISFIFO(modep))                       //~v56sR~
    if (S_ISFIFO(modep))      //req fifo only                      //~v56sI~
      if (!S_ISFIFO(modef))                                        //~v56sI~
    	return 0;                                                  //~v50JI~
//  if (S_ISSOCK(modef) && !S_ISSOCK(modep))                       //~v56sR~
    if (S_ISSOCK(modep))                                           //~v56sI~
      if (!S_ISSOCK(modef))                                        //~v56sI~
    	return 0;                                                  //~v50JI~
   }//non reg                                                      //~v56sI~
  }//not MDOS DISK                                                 //~v56nI~
//  wattrf=(Pfattr & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));    //~v56cR~
//  wattrp=(Ppattr & (FILE_HIDDEN|FILE_SYSTEM|FILE_DIRECTORY));    //~v56cR~
//  if (!wattrf     //select A,R attr file unconditionaly          //~v56cR~
//  ||  (wattrp & wattrf)==wattrf)  //file bit included in parm attr//~v533R~
//  ||  (wattrp & wattrf))  //file bit included in parm attr       //~v56cR~
//      return 1;                                                  //~v56cR~
//  return 0;                                                      //~v56cI~
#ifdef UTF8SUPPH                                                   //~v62aI~
    if (Pfattr & FILE_SLINK)	//file is SLINK                    //~v62aI~
    	if ((Ppattr & FILE_SLINK))		//requested SLINK select   //~v62aI~
       		return 1;					//select even if dir and dir is not requested//~v62aI~
#endif                                                             //~v62aI~
    if (Pfattr & FILE_DIRECTORY)	//file is dir                  //~v56cI~
    	if (!(Ppattr & FILE_DIRECTORY))		//dir not specified    //~v56cI~
       		return 0;					//no select                //~v56cI~
    if (Pfattr & FILE_HIDDEN)	//file is dir                      //~v56cR~
    	if (!(Ppattr & FILE_HIDDEN))		//dir not specified    //~v56cI~
       		return 0;					//no select                //~v56cI~
    if (Pfattr & FILE_SYSTEM)	//file is dir                      //~v56cI~
    	if (!(Ppattr & FILE_SYSTEM))		//dir not specified    //~v56cI~
       		return 0;					//no select                //~v56cI~
	UTRACEP("%s:file exit rc=1 attr=0x%x,slink attr=0x%x,select attr=0x%x\n",UTT,Pfattr,Pfattrsrc,Ppattr);//~v780I~
    return 1;                                                      //~v56cI~
}//ufilelnxattrselect                                              //~0901I~
//*******************************************************
//*get dir member stat                                             //~0901R~
//*parm 1:output ffb3                                              //~0901R~
//*parm 2:result of readdir                                        //~0901R~
//*parm 3:dir name                                                 //~0901I~
//*parm 4:pathlen(0 when not wildcard)                             //~0901I~
//*return:none
//*******************************************************
int ufilelnxgetmembfstat(FILEFINDBUF3 *Ppffb3,PDIRENT Ppde,UCHAR *Ppath,int Ppathlen)//~v371R~
{
    UCHAR pathfnm[_MAX_PATH*2];                                    //~0827R~
    int rc;                                                        //~v39TI~
//*************
    UTRACEP("%s:path=%s,Pathlen=%d,d_name=%s\n",UTT,Ppath,Ppathlen,Ppde->d_name);//~v77dR~
//  memcpy(pathfnm,Ppath,Ppathlen);                                //~0901R~//~v6B6R~
    memcpy(pathfnm,Ppath,(size_t)Ppathlen);                        //~v6B6I~
    if (Ppathlen >0 && *(pathfnm+Ppathlen-1)!='/')                 //~0901R~
        *(pathfnm+Ppathlen++)='/';                                 //~0901R~
    strcpy(pathfnm+Ppathlen,Ppde->d_name);                         //~0901R~
//  return ufstat(pathfnm,Ppffb3);                                 //~v39TR~
//	Swildname=1;  //filename may contain wildcard char             //~v39YR~
  	Swildnamemembfstat=1;  //filename may contain wildcard char    //~v6b1I~
//  rc=ufstat(pathfnm,Ppffb3);                                     //~v39TI~//~v6B6R~
    rc=(int)ufstat(pathfnm,Ppffb3);                                //~v6B6I~
//	Swildname=0;  //filename may not contain wildcard char         //~v39YR~
  	Swildnamemembfstat=0;  //filename may contain wildcard char    //~v6b1I~
	if (!rc)                                                       //~v6b1I~
        if (Ppffb3->attrFile & FILE_WILDNAME)                      //~v6b1I~
        {                                                          //~v6b1I~
            UTRACEP("Wildname member:%s\n",Ppde->d_name);          //~v6b1I~
        	if (Ppde->d_ino!=Ppffb3->inode)                        //~v6b1R~
            {                                                      //~v6b1I~
                UTRACEP("Wildname Multiple member:%s,inode:de=%x,ffb=%x\n",Ppde->d_name,(int)(Ppde->d_ino),(int)(Ppffb3->inode));//~v6b1R~
                UTRACED("Ppde",Ppde,Ppde->d_reclen);               //~v6b1R~
                UTRACED("ffb3",Ppffb3,sizeof(FILEFINDBUF3));       //~v6b1I~
//            	Ppffb3->inode=Ppde->d_ino;                         //~v6b1R~
//	        	Ppffb3->attrFile|=FILE_WILDNAME_MULTIPLE;          //~v6b1R~
//*inode may changes after fstat for wildname entry                //~v6b1I~
            	ufilechkwildmultiple(0,pathfnm,Ppde,Ppffb3);       //~v6b1R~
            }                                                      //~v6b1I~
            else                                                   //~v6b1I~
            {                                                      //~v6b1I~
            	ufilechkwildmultiple(0,pathfnm,Ppde,Ppffb3);       //~v6b1R~
            }                                                      //~v6b1I~
        }                                                          //~v6b1I~
    return rc;                                                     //~v39TI~
}//ufilelnxgetmembfstat                                            //~0901R~
//*******************************************************
//*save hdir and requested attrib for findnext
//*parm 1:HDIR
//*parm 2:attr
//*parm 3:fullpath name(may contain wildcard)                      //~0901I~
//*parm 4:pathlen(0 for not wildcard)                              //~0901I~
//*return:0 or ERROR_TOO_MANY_OPEN_FILES
//*******************************************************
int ufilelnxsavehdir(HDIR Phdir,ULONG Pattr,UCHAR *Ppath,int Ppathlen)
{
    int ii;
//*************
	UTRACEP("%s:path=%s,attr=0x%lx,hdir=%p\n",UTT,Ppath,Pattr,Phdir);//~v780I~
    for (ii=0;ii<MAXHDIR;ii++)                                     //~0827R~
        if (Phdir==Shdirtbl[ii] || !Shdirtbl[ii])                  //~0827R~
        {
            Shdirtbl[ii]=Phdir;                                    //~0827R~
//          Shdirtattr[ii]=Pattr;                                  //~0827R~//~v6BxR~
            Shdirtattr[ii]=(UINT)Pattr;                            //~v6BxI~
            Shdirpathlen[ii]=Ppathlen;                             //~0901R~
            strncpy(Shdirpath[ii],Ppath,_MAX_PATH);                //~0827I~
	        Shdirpudl[ii]=(PUDIRLIST)Phdir;	//top addr for mdir    //~v50GI~
			Shdirindex=ii;	//search index                         //~v50GI~
//  		UTRACEP("%s:Shdirindex=%d,Phdir=%p,path=\n",UTT,ii,Phdir,Ppath);//~v70bR~
            break;
        }                                                          //~0827R~
    if (ii==MAXHDIR)                                               //~0827R~
    {
        uerrmsg("Pending FindFirst HANDLE overflow(max %d)",       //~0827R~
                "仕掛かり中の FindFirst の制限超(最大 %d)",        //~0827R~//~v777I~
                    MAXHDIR);                                      //~0827R~
        return ERROR_TOO_MANY_OPEN_FILES;                          //~0827R~
    }                                                              //~0827R~
    return 0;                                                      //~0827R~
}//ufilelnxsavehdir                                                //~0827R~
//*******************************************************
//*search hdir table when findnext
//*parm 1:HDIR
//*parm 2:attr
//*return:0 or 4(not found)
//*******************************************************
int ufilelnxsrchhdir(HDIR Phdir,ULONG *Ppattr,UCHAR **Pppath,int *Pppathlen)//~0901R~
{
    int ii;
//*************
//  UTRACEP("%s:Phdir=%p\n",UTT,Phdir);                            //~v70bR~
	Shdirindex=0;	//mdos current pos                             //~v50GI~
    if (!Phdir)                                                    //~0827R~
        return ERROR_INVALID_HANDLE;                               //~0827R~
    for (ii=0;ii<MAXHDIR;ii++)                                     //~0827R~
    {                                                              //~v70bI~
//      UTRACEP("%s:ii=%d,Shdirtbl=%p,path=%s\n",UTT,ii,Shdirtbl[ii],Shdirpath[ii]);//~v70bR~
        if (Phdir==Shdirtbl[ii])                                   //~0827R~
            break;
    }                                                              //~v70bI~
    if (ii==MAXHDIR)                                               //~0827R~
        return ERROR_INVALID_HANDLE;                               //~0827R~
    *Ppattr=Shdirtattr[ii];                                        //~0827R~
    *Pppath=Shdirpath[ii];                                         //~0827I~
    *Pppathlen=Shdirpathlen[ii];                                   //~0901R~
	Shdirindex=ii;	//mdos current pos                             //~v50GI~
    UTRACEP("%s:Shdrindex=%d,path=%s,attr=0x%lx\n",UTT,ii,*Pppath,*Ppattr);           //~v70bR~//~v780R~
    return 0;                                                      //~0827R~
}//ufilelnxsrchhdir
//*******************************************************
//*clear hdir table when findclose
//*parm 1:HDIR
//*return:0 or 4(not found)
//*******************************************************
int ufilelnxclosehdir(HDIR Phdir)
{
    int ii,rc;
//*************
    if (!Phdir)                                                    //~0827R~
        return ERROR_INVALID_HANDLE;                               //~0827R~
    for (ii=0;ii<MAXHDIR;ii++)                                     //~v50GM~
        if (Phdir==Shdirtbl[ii])                                   //~v50GM~
            break;                                                 //~v50GM~
  if (ii!=MAXHDIR && (Shdirtattr[ii] & FILE_MDOSDISK))             //~v50GR~
  {                                                                //~v50GI~
  	ufree((void*)Phdir);		//free mdir list,top word is ptr   //~v50GR~
  }                                                                //~v50GI~
  else                                                             //~v50GI~
  {                                                                //~v50GI~
    rc=closedir((DIR *)Phdir);        //relese  handle             //~0827R~
    if (rc)                                                        //~0827R~
    {                                                              //~0827R~
        rc=errno;                                                  //~0827R~
//      uerrexit("FindClose failed,rc=%d",                         //~0827R~//~v782R~
        uerrmsg("FindClose failed,rc=%d",                          //~v782I~
                    "FindClose の失敗,リターンコード=%d",          //~v77dI~
                    rc);                                           //~0827R~
        return rc;                                                 //~v782I~
    }                                                              //~0827R~
  }                                                                //~v50GI~
    if (ii==MAXHDIR)                                               //~0827R~
        return ERROR_INVALID_HANDLE;                               //~0827R~
//  UTRACEP("%s:Shdrindex=%d,path=%s\n",UTT,ii,Shdirpath);         //~v70bR~
    Shdirtattr[ii]=0;                                              //~0827R~
    Shdirtbl[ii]=0;
    Shdirpath[ii][0]=0;                                            //~0827R~
    return 0;                                                      //~0827R~
}//ufilelnxclosehdir
//*******************************************************          //~0827I~
//*get attr from mode                                              //~0827I~
//*parm :findbuff3                                                 //~0827R~
//*return:rc                                                       //~0827R~
//*******************************************************          //~0827I~
ULONG ufilemode2attr(FILEFINDBUF3 *Ppft)                           //~0827R~
{                                                                  //~0827I~
    ULONG attr=0;                                                  //~0827R~
    mode_t mode;                                                   //~0827R~
    mode_t modew;                                                  //~v56sI~
//  uid_t  uid;                                                    //~v59nR~
//  gid_t  gid;                                                    //~v59nR~
//  char *pc;                                                      //~v578R~
//*************                                                    //~0827I~
//  mode=FILE_GETMODE(Ppft->attrFile);                             //~0901R~//~v6BxR~
    mode=(mode_t)FILE_GETMODE(Ppft->attrFile);                     //~v6BxI~
    if (Ppft->attrFile & FILE_WILDNAME)                            //~v6b1I~
    	attr|=FILE_WILDNAME;                                       //~v6b1I~
    if (Ppft->attrFile & FILE_WILDNAME_MULTIPLE)                   //~v6b1I~
    	attr|=FILE_WILDNAME_MULTIPLE;                              //~v6b1I~
//  ugetugid(&uid,&gid);                                           //~v59nR~
//  if (S_ISLNK(mode))                                             //~v56sR~
//      attr=Ppft->attrFile & FILE_DIRECTORY;	//dir mask already set//~v56sR~
    if (S_ISLNK(mode))                                             //~v56sI~
    {                                                              //~v62aI~
//  	modew=FILE_GETMODE(Ppft->srcattr);	//slink attr           //~v56sI~//~v6BxR~
    	modew=(mode_t)FILE_GETMODE(Ppft->srcattr);	//slink attr   //~v6BxI~
#ifdef UTF8SUPPH                                                   //~v62aI~
        attr|=FILE_SLINK;                                          //~v62aI~
#endif                                                             //~v62aI~
    }                                                              //~v62aI~
    else                                                           //~v56sI~
    	modew=mode;                                                //~v56sI~
    if (S_ISDIR(modew))                                            //~v56sR~
        attr|=FILE_DIRECTORY;                                      //~0827I~
    if (S_ISCHR(modew) 	//char device                              //~v56sI~
    ||  S_ISBLK(modew)  //blk device                               //~v56sI~
    ||  S_ISFIFO(modew) //pipe                                     //~v56sI~
    ||  S_ISSOCK(modew)) //socket                                  //~v56sI~
        attr|=FILE_SPECIAL;                                        //~v56sI~
    if (!((mode & S_IWOTH) || (mode & S_IWGRP) || (mode & S_IWUSR))//~0827R~
    &&   ((mode & S_IROTH) || (mode & S_IRGRP) || (mode & S_IRUSR)))//~0827R~
        attr|=FILE_READONLY;                                       //~0827I~
//  if (!(mode & S_IRWXO)                                          //~v39VR~
//  &&   ((gid!=Ppft->gid && uid)||!(mode & S_IRWXG))              //~v39VR~
//  &&   ((uid!=Ppft->uid && uid)||!(mode & S_IRWXU)))             //~v39VR~
//      attr|=FILE_HIDDEN;                                         //~v39VI~
//    if (gid!=Ppft->gid)                                          //~v575R~
//    {                                                            //~v575R~
//        if (!(mode & S_IWOTH))//not root and no write for others //~v575R~
//            attr|=FILE_SYSTEM;                                   //~v575R~
//    }                                                            //~v575R~
//    else                                                         //~v575R~
//        if (uid!=Ppft->uid) //                                   //~v575R~
//            if (!(mode & S_IWGRP))                               //~v575R~
//                attr|=FILE_SYSTEM;                               //~v575R~
//    pc=Ppft->achName;                                            //~v575R~
//    if (*pc++=='.')                                              //~v575R~
//        if (*pc!=0 && *pc!='.') //not cur dir or parent dir      //~v575R~
//            attr|=FILE_HIDDEN;                                   //~v575R~
    Ppft->attrFile=FILE_SETMODEATTR(mode,attr);                    //~0901R~
    UTRACEP("%s:return attr=0x%lx,mode=0x%x\n",UTT,attr,(int)mode);//~v780I~
    return attr;                                                   //~0827R~
}//ufilemode2attr                                                  //~0827I~
//*******************************************************          //~0827I~
//*conv file time to time_t                                        //~0827I~
//*******************************************************          //~0827I~
time_t ufilemktime(FDATE Pfd,FTIME Pft)                            //~0827R~
{                                                                  //~0827I~
    struct tm wktm; //yy,mm,dd,hh,mm,ss,...                        //~0827I~
//*******************                                              //~0827I~
    memset(&wktm,0,sizeof(wktm));                                  //~0901R~
    wktm.tm_sec   =Pft.twosecs*2;                                  //~0827R~
    wktm.tm_min   =Pft.minutes;                                    //~0827R~
    wktm.tm_hour  =Pft.hours;                                      //~0827R~
    wktm.tm_mday  =Pfd.day;                                        //~0827R~
    wktm.tm_mon   =Pfd.month-1;                                    //~0827R~
    wktm.tm_year  =Pfd.year+80;                                    //~0827R~
    return mktime(&wktm);                                          //~0827I~
}//ufilemktime                                                     //~0827I~
//********************************************************************//~v6b1I~
//*replace wildcard char of filename for undelprepare save filename//~v6b1I~
//*rc:1:replaced                                                   //~v6b1I~
//********************************************************************//~v6b1I~
//int ufilerepwildname(int Popt,char *Pwildname,int Pinode)        //~v6ydR~
int ufilerepwildname(int Popt,char *Pwildname,ULONG Pinode)        //~v6ydI~
{                                                                  //~v6b1I~
    int len,ii,rc=0;                                               //~v6b1I~
    char *pc;                                                      //~v6b1I~
//*********************                                            //~v6b1I~
    len=(int)strlen(Pwildname);                                    //~v6b1I~
    pc=Pwildname;                                                  //~v6b1I~
    for (ii=0;ii<len;ii++,pc++)                                    //~v6b1I~
    {                                                              //~v6b1I~
    	if (*pc=='?')                                              //~v6b1I~
        {                                                          //~v6b1I~
        	*pc='_';                                               //~v6b1I~
            rc=1;                                                  //~v6b1I~
        }                                                          //~v6b1I~
        else                                                       //~v6b1I~
    	if (*pc=='*')                                              //~v6b1I~
        {                                                          //~v6b1I~
        	*pc='=';                                               //~v6b1I~
            rc=1;                                                  //~v6b1I~
        }                                                          //~v6b1I~
    }                                                              //~v6b1I~
    if (rc && Pinode)                                              //~v6b1I~
//      sprintf(Pwildname+len,".%04x",Pinode);                     //~v6ydR~
        sprintf(Pwildname+len,".%04lx",Pinode);                    //~v6ydI~
    return rc;                                                     //~v6b1I~
}//ufilerepwildname                                                //~v6b1I~
//********************************************************************//~v6b1I~
int errwildname(int Popt,char *Pmember,char *Ppath)                //~v6b1R~
{                                                                  //~v6b1I~
#ifdef LNX                                                         //~v6uVI~
    int swmdos;                                                    //~v6uVI~
#endif                                                             //~v6uVI~
//************                                                     //~v6uVI~
	if (Popt & EWN_COPYSRC) //xcopy cmd source is wildname         //~v6b1I~
    {                                                              //~v6b1I~
		if (Popt & EWN_RENAME)                                     //~v6b1I~
    		uerrmsg("Wildname renamed copy (%s).",                 //~v6b1I~
       				"無効なファイル名を改名複写(%s).",             //~v6b1R~//~v777I~
       				Ppath);                                        //~v6b1I~
        else                                                       //~v6b1I~
    		uerrmsg("Invalid copy target name(%s). Use \"/w\" option to rename copy.",//~v6b1R~
       				"複写先ファイル名エラー(%s). \"/w\" オプション指定で改名複写",//~v6b1R~//~v777I~
       				Ppath);                                        //~v6b1I~
    }                                                              //~v6b1I~
    else                                                           //~v6b1I~
    if (Gufile_opt & GFILEOPT_XDDUTIL)                             //~v6b1R~
    {                                                              //~v6b1I~
    	if (Gufile_opt & GFILEOPT_WILDCARDNAMEOK)                  //~v6b1I~
    		uerrmsg("Invalid filename(%s of %s).",                 //~v6b1I~
       				"無効なファイル名(%s of %s).",                 //~v6b1I~//~v777I~
       				Pmember,Ppath);                                //~v6b1I~
        else                                                       //~v6b1I~
        {                                                          //~v6uVI~
#ifdef LNX                                                         //~v6uVI~
    		swmdos=ufileisMSMounted(0,Ppath);	//vfat or nyfs     //~v6uVI~
          if (swmdos==1)                                           //~v6uVI~
    		uerrmsg("Invalid filename(%s of %s). (VFAT Mounted). Use -w option to force delete.",//~v6uVI~
       				"無効なファイル名(%s of %s).(VFAT マウント). 強制削除は -w オプション使用",//~v6uVI~//~v777I~
       				Pmember,Ppath);                                //~v6uVI~
          else                                                     //~v6uVI~
          if (swmdos==2)    //NTFS driver support utf16(not cv to "?")v6uVI~//~v6uVR~
    		uerrmsg("Invalid filename(%s of %s). (maybe NTFS mounted). Use -w option to force delete.",//~v6uVI~
       				"無効なファイル名(%s of %s).(NTFS上か？). 強制削除は -w オプション使用",//~v6uVI~//~v777I~
       				Pmember,Ppath);                                //~v6uVI~
          else                                                     //~v6uVI~
#endif                                                             //~v6uVI~
    		uerrmsg("Invalid filename(%s of %s). (maybe valid on the system created it). Use -w option to force delete.",//~v6b1R~
       				"無効なファイル名(%s of %s).(作成したシステムでは尚、有効かも). 強制削除は -w オプション使用",//~v6b1R~//~v777I~
       				Pmember,Ppath);                                //~v6b1R~
        }                                                          //~v6uVI~
    }                                                              //~v6b1I~
    else                                                           //~v6b1I~
    {                                                              //~v6q2I~
       if (!(  (Gufile_opt & GFILEOPT_NOWILDERRMSG) //skip filename invalid warning//~v6q2I~
             && WILDCARD(Pmember)                                  //~v6q2I~
            )                                                      //~v6q2I~
          )                                                        //~v6q2I~
       {                                                           //~v6uVI~
#ifdef LNX                                                         //~v6uVI~
            swmdos=ufileisMSMounted(0,Ppath);   //vfat or nyfs     //~v6uVI~
          if (swmdos==1)                                           //~v6uVI~
            uerrmsg("Invalid filename(%s of %s). (VFAT mounted)",  //~v6uVI~
                    "無効なファイル名(%s of %s).(VFAT マウント). ",//~v6uVI~//~v777I~
                    Pmember,Ppath);                                //~v6uVI~
          else                                                     //~v6uVI~
          if (swmdos==2)    //NTFS driver support utf16(not cv to "?")v6uVI~//~v6uVI~
            uerrmsg("Invalid filename(%s of %s). (maybe NTFS mounted)",//~v6uVI~
                    "無効なファイル名(%s of %s).(NTFS上か？)",     //~v6uVI~//~v777I~
                    Pmember,Ppath);                                //~v6uVI~
          else                                                     //~v6uVI~
//        iocu8=ufilegetiocharset(0,Ppath,0/*unknown dev_t*/,wkcharset,(int)sizeof(wkcharset));//~v6B9I~
//        if (iocu8==2)   //utf8 by default                          //~v6B9I~
//            uerrmsg("Invalid filename(%s of %s). (unknown mount option:iocharset,utf8 will be assumed.)",//~v6B9I~
//                      "無効なファイル名(%s of %s).(マウントオプション:iocharset が不明,utf8を想定)",//~v6B9I~//~v777I~
//                    Pmember,Ppath,wkcharset);                      //~v6B9I~
//        else                                                       //~v6B9I~
//            uerrmsg("Invalid filename(%s of %s). (mount option iocharset=%s)",//~v6B9I~
//                      "無効なファイル名(%s of %s).(マウントオプション iocharset=%s)",//~v6B9I~//~v777I~
//                    Pmember,Ppath,wkcharset);                      //~v6B9I~
#endif                                                             //~v6uVI~
    	uerrmsg("Invalid filename(%s of %s). (maybe valid on the system created it)",//~v6b1R~
       			"無効なファイル名(%s of %s).(作成したシステムでは尚、有効かも)",//~v6b1R~//~v777I~
       			Pmember,Ppath);                                    //~v6b1R~
       }                                                           //~v6uVI~
    }                                                              //~v6q2I~
    return FILE_WILDNAME;                                          //~v6b1R~
}//errwildname                                                     //~v6b1R~
#ifdef ARM                                                         //~v6B5I~
//*****************************************************            //~v6B5I~
//*set system static to user buff for mntent                       //~v6B5I~
//*****************************************************            //~v6B5I~
int usetmntent(struct mntent *Pmnti,struct mntent *Pmnto,char *Pbuff,int Pbuffsz)//~v6B5I~
{                                                                  //~v6B5I~
	char *pc;                                                      //~v6B5I~
    int reslen,len;                                                //~v6B5I~
//****************************                                     //~v6B5I~
	memcpy(Pmnto,Pmnti,sizeof(struct mntent));                     //~v6B5I~
    pc=Pbuff;                                                      //~v6B5I~
    reslen=Pbuffsz;                                                //~v6B5I~
    if (Pmnti->mnt_fsname)                                         //~v6B5I~
    {                                                              //~v6B5I~
        len=strlen(Pmnti->mnt_fsname)+1;                           //~v6B5I~
        if (len<=reslen)                                           //~v6B5I~
        {                                                          //~v6B5I~
            memcpy(pc,Pmnti->mnt_fsname,(size_t)len);              //~v6B5I~
            pc+=len;                                               //~v6B5I~
        }                                                          //~v6B5I~
        reslen-=len;                                               //~v6B5I~
    }                                                              //~v6B5I~
    if (Pmnti->mnt_dir)                                            //~v6B5I~
    {                                                              //~v6B5I~
        len=strlen(Pmnti->mnt_dir)+1;                              //~v6B5I~
        if (len<=reslen)                                           //~v6B5I~
        {                                                          //~v6B5I~
            memcpy(pc,Pmnti->mnt_dir,(size_t)len);                 //~v6B5I~
            pc+=len;                                               //~v6B5I~
        }                                                          //~v6B5I~
        reslen-=len;                                               //~v6B5I~
    }                                                              //~v6B5I~
    if (Pmnti->mnt_type)                                           //~v6B5I~
    {                                                              //~v6B5I~
        len=strlen(Pmnti->mnt_type)+1;                             //~v6B5I~
        if (len<=reslen)                                           //~v6B5I~
        {                                                          //~v6B5I~
            memcpy(pc,Pmnti->mnt_type,(size_t)len);                //~v6B5I~
            pc+=len;                                               //~v6B5I~
        }                                                          //~v6B5I~
        reslen-=len;                                               //~v6B5I~
    }                                                              //~v6B5I~
    if (Pmnti->mnt_opts)                                           //~v6B5I~
    {                                                              //~v6B5I~
        len=strlen(Pmnti->mnt_opts)+1;                             //~v6B5I~
        if (len<=reslen)                                           //~v6B5I~
        {                                                          //~v6B5I~
            memcpy(pc,Pmnti->mnt_opts,(size_t)len);                //~v6B5I~
            pc+=len;                                               //~v6B5I~
        }                                                          //~v6B5I~
        reslen-=len;                                               //~v6B5I~
    }                                                              //~v6B5I~
    return (reslen>=0)?0:4;                                        //~v6B5I~
}//usetmntent                                                      //~v6B5I~
//*****************************************************            //~v6B5I~
//*search on /proc/mounts to chk filesystem type                   //~v6B5I~
//rc:4:err                                                         //~v6B5I~
//*****************************************************            //~v6B5I~
int filesrchmountpointARM(char *Pfilename,struct mntent *Pmnt,char *Pbuff,int Pbuffsz)//~v6B5I~
{                                                                  //~v6B5I~
    struct stat s;                                                 //~v6B5I~
    FILE *      fp;                                                //~v6B5I~
    int rc=0,pathlen,lendir,lentype=0,maxlen=0,lenfs,lenopt;       //~v6B5I~
	struct mntent *pmnt;                                           //~v6B5I~
    char fnm[_MAX_PATH],*pfnm,*pfs;                                //~v6B5I~
    char *pc,*pc2,*pc3,*pc4;                                       //~v6B5I~
    char fsname[256],dir[_MAX_PATH],mnttype[256],mntopt[256];      //~v6B5I~
    char buff[1024];                                               //~v6B5I~
//*****************************************                        //~v6B5I~
//  memset(Pmnt,sizeof(struct mntent),0);                          //~v6B5I~//~v703R~
    memset(Pmnt,0,sizeof(struct mntent));                          //~v703I~
    memset(fsname,0,sizeof(fsname));                               //~v6B5I~
    memset(dir,0,sizeof(dir));                                     //~v6B5I~
    memset(mnttype,0,sizeof(mnttype));                             //~v6B5I~
	pmnt=(struct mntent *)Pmnt;                                    //~v6B5I~
    pmnt->mnt_fsname=fsname;                                       //~v6B5I~
    pmnt->mnt_dir=dir;                                             //~v6B5I~
    pmnt->mnt_type=mnttype;                                        //~v6B5I~
                                                                   //~v6B5I~
    pfnm=Pfilename;                                                //~v6B5I~
    pathlen=PATHLEN(pfnm);                                         //~v6B5I~
    if (pathlen>0 && WILDCARD(pfnm+pathlen))                       //~v6B5I~
    {                                                              //~v6B5I~
    	UmemcpyZ(fnm,pfnm,pathlen);                                //~v6B5I~
        pfnm=fnm;                                                  //~v6B5I~
    }                                                              //~v6B5I~
    pathlen=strlen(pfnm);                                          //~v6B5I~
    if (stat(pfnm,&s) != 0) {                                      //~v6B5I~
        return 4;                                                  //~v6B5I~
    }                                                              //~v6B5I~
//  dev = s.st_dev;                                                //~v6B5I~
//  if ((fp = setmntent("/proc/mounts","r"))==NULL) {              //~v6B5I~
    if (!(fp=fopen("/proc/mounts","r")))                           //~v6B5I~
        return 4;                                                  //~v6B5I~
//  while (getmntent_r(fp,pmnt,Pbuff,Pbuffsz)) {                   //~v6B5I~
    while (fgets(buff,sizeof(buff),fp)) {                          //~v6B5I~
    	UTRACEP("%s:buff=%s\n",UTT,buff);                          //~v6B5I~
//        if (stat(pmnt->mnt_dir,&s) != 0) {                       //~v6B5I~
//            continue;                                            //~v6B5I~
//        }                                                        //~v6B5I~
//        if (s.st_dev == dev) {                                   //~v6B5I~
//            rc=0;                                                //~v6B5I~
//            break;                                               //~v6B5I~
//        }                                                        //~v6B5I~
        pfs=buff+strspn(buff," ");                                 //~v6B5I~
        pc=strchr(pfs,' ');     // /dev/fuse[ ]  file system       //~v6B5I~
        if (!pc)                  // /mnt/fuse     mount point     //~v6B5I~
            continue;                                              //~v6B5I~
        lenfs=PTRDIFF(pc,pfs);                                     //~v6B5I~
        pc+=strspn(pc," ");                                        //~v6B5I~
        pc2=strchr(pc,' ');       // /mnt/sdcard[ ]                //~v6B5I~
        if (!pc2)                 // fuse[ ]       file system type//~v6B5I~
            continue;                                              //~v6B5I~
        lendir=PTRDIFF(pc2,pc);                                    //~v6B5I~
        pc2+=strspn(pc2," ");                                      //~v6B5I~
        pc3=strchr(pc2,' ');      // rw,...       mount option     //~v6B5I~
        if (!pc3)                 //                               //~v6B5I~
            continue;                                              //~v6B5I~
        lentype=PTRDIFF(pc3,pc2);                                  //~v6B5I~
        pc3+=strspn(pc3," ");                                      //~v6B5I~
        pc4=strchr(pc3,' ');      // rw,...       mount option     //~v6B5I~
        lenopt=PTRDIFF(pc4,pc3);                                   //~v6B5I~
        if (lendir<=pathlen && !memcmp(pc,pfnm,lendir))            //~v6B5I~
        {                                                          //~v6B5I~
            if (lendir>maxlen)                                     //~v6B5I~
            {                                                      //~v6B5I~
		    	UmemcpyZ(Pmnt->mnt_fsname,pfs,min(lenfs,sizeof(fsname)-1));//~v6B5I~
		    	UmemcpyZ(Pmnt->mnt_dir,pc,min(lendir,sizeof(dir)-1));//~v6B5I~
		    	UmemcpyZ(Pmnt->mnt_type,pc2,min(lentype,sizeof(mnttype)-1));//~v6B5I~
		    	UmemcpyZ(Pmnt->mnt_opts,pc3,min(lenopt,sizeof(mntopt)-1));//~v6B5I~
                maxlen=lendir;                                     //~v6B5I~
	    		usetmntent(pmnt,Pmnt,Pbuff,Pbuffsz);               //~v6B5I~
            }                                                      //~v6B5I~
        }                                                          //~v6B5I~
    }                                                              //~v6B5I~
//  endmntent(fp);                                                 //~v6B5I~
	fclose(fp);                                                    //~v6B5I~
    rc=maxlen?0:4;                                                 //~v6B5I~
    UTRACEP("%s:rc=%d,fs=%s,dir=%s,type=%s\n",UTT,rc,fsname,dir,mnttype);//~v6B5I~
    UTRACED("out mntent",Pmnt,sizeof(struct mntent));              //~v6B5I~
    return rc;                                                     //~v6B5I~
}                                                                  //~v6B5I~
//*****************************************************            //~v6B5I~
//*search on /proc/mounts to chk filesystem type                   //~v6B5I~
//*using getmntent(set to static variable)                         //~v6B5I~
//rc:4:err                                                         //~v6B5I~
//*****************************************************            //~v6B5I~
int filesrchmountpointARM2(char *Pfilename,void *Pmnt/*ptr to Pbuff*/,char *Pbuff,int Pbuffsz)//~v6B5I~
{                                                                  //~v6B5I~
    struct stat s;                                                 //~v6B5I~
    FILE *      fp;                                                //~v6B5I~
    dev_t       dev;                                               //~v6B5I~
    int rc=4,pathlen;                                              //~v6B5I~
	struct mntent *pmnt;                                           //~v6B5I~
    char fnm[_MAX_PATH],*pfnm;                                     //~v6B5I~
//*****************************************                        //~v6B5I~
	pmnt=(struct mntent *)Pmnt;                                    //~v6B5I~
    pfnm=Pfilename;                                                //~v6B5I~
    pathlen=PATHLEN(pfnm);                                         //~v6B5I~
    UTRACEP("%s:filename=%s\n",UTT,Pfilename);                     //~v6D2I~
    if (pathlen>0 && WILDCARD(pfnm+pathlen))                       //~v6B5I~
    {                                                              //~v6B5I~
    	UmemcpyZ(fnm,pfnm,pathlen);                                //~v6B5I~
        pfnm=fnm;                                                  //~v6B5I~
    }                                                              //~v6B5I~
    if (stat(pfnm,&s) != 0) {                                      //~v6B5I~
	    UTRACEP("%s:%s stat failed\n",UTT,pfnm);                   //~v6D2I~
        return 4;                                                  //~v6B5I~
    }                                                              //~v6B5I~
    dev = s.st_dev;                                                //~v6B5I~
//  if ((fp = setmntent("/proc/mounts","r"))==NULL) {              //~v6B5I~
    if (!(fp=fopen("/proc/mounts","r"))) {                         //~v6B5I~
	    UTRACEP("%s:/proc/mounts fopen err\n",UTT);                //~v6D2I~
        return 4;                                                  //~v6B5I~
    }                                                              //~v6B5I~
//  while (getmntent_r(fp,pmnt,Pbuff,Pbuffsz)) {                   //~v6B5I~
    while ((pmnt=getmntent(fp))!=NULL) {                           //~v6B5I~
    	UTRACEP("%s:fsn=%s,dir=%s,type=%s,opt=%s\n",UTT,pmnt->mnt_fsname,pmnt->mnt_dir,pmnt->mnt_type,pmnt->mnt_opts);//~v6B5I~
    	UTRACEP("%s:mnt=%p,fsn=%p,dir=%s,type=%p,opt=%p\n",UTT,pmnt,pmnt->mnt_fsname,pmnt->mnt_dir,pmnt->mnt_type,pmnt->mnt_opts);//~v6B5I~
        if (stat(pmnt->mnt_dir,&s) != 0) {                         //~v6B5I~
            continue;                                              //~v6B5I~
        }                                                          //~v6B5I~
        if (s.st_dev == dev) {                                     //~v6B5I~
    		usetmntent(pmnt,Pmnt,Pbuff,Pbuffsz);                   //~v6B5I~
            rc=0;                                                  //~v6B5I~
            break;                                                 //~v6B5I~
        }                                                          //~v6B5I~
    }                                                              //~v6B5I~
//  endmntent(fp);                                                 //~v6B5I~
    fclose(fp);                                                    //~v6B5I~
	UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~v6D2I~
    return rc;                                                     //~v6B5I~
}                                                                  //~v6B5I~
#endif	//ARM                                                      //~v6B5I~
//*****************************************************            //~v6uVI~
//*search on /proc/mounts to chk filesystem type                   //~v6uVI~
//rc:4:err                                                         //~v6uVI~
//*****************************************************            //~v6uVI~
int filesrchmountpoint(char *Pfilename,void *Pmnt/*ptr to Pbuff*/,char *Pbuff,int Pbuffsz)//~v6uVR~
{                                                                  //~v6uVI~
#ifdef ARM                                                         //~v6uVR~
//	return 4;	//no api support                                   //~v6uVI~//~v6B5R~
    return filesrchmountpointARM2(Pfilename,(struct mntent *)Pmnt,Pbuff,Pbuffsz);//~v6B5R~
#else                                                              //~v6uVI~
    struct stat s;                                                 //~v6uVI~
    FILE *      fp;                                                //~v6uVI~
    dev_t       dev;                                               //~v6uVI~
    int rc=4,pathlen;                                              //~v6uVR~
	struct mntent *pmnt;                                           //~v6uVI~
    char fnm[_MAX_PATH],*pfnm;                                     //~v6uVR~
//*****************************************                        //~v6uVI~
	pmnt=(struct mntent *)Pmnt;                                    //~v6uVI~
    pfnm=Pfilename;                                                //~v6uVI~
    pathlen=PATHLEN(pfnm);                                         //~v6uVI~
    if (pathlen>0 && WILDCARD(pfnm+pathlen))                       //~v6uVR~
    {                                                              //~v6uVI~
//  	UmemcpyZ(fnm,pfnm,pathlen);                                //~v6uVR~//~v6B6R~
    	UmemcpyZ(fnm,pfnm,(size_t)pathlen);                        //~v6B6I~
        pfnm=fnm;                                                  //~v6uVI~
    }                                                              //~v6uVI~
    if (stat(pfnm,&s) != 0) {                                      //~v6uVR~
        return 4;                                                  //~v6uVI~
    }                                                              //~v6uVI~
    dev = s.st_dev;                                                //~v6uVI~
    if ((fp = setmntent("/proc/mounts","r"))==NULL) {              //~v6uVI~
        return 4;                                                  //~v6uVI~
    }                                                              //~v6uVI~
    while (getmntent_r(fp,pmnt,Pbuff,Pbuffsz)) {                   //~v6uVR~
    	UTRACEP("%s:fsn=%smdir=%s,type=%s,opt=%s\n",UTT,pmnt->mnt_fsname,pmnt->mnt_dir,pmnt->mnt_type,pmnt->mnt_opts);//~v6uVR~
        if (stat(pmnt->mnt_dir,&s) != 0) {                         //~v6uVR~
            continue;                                              //~v6uVI~
        }                                                          //~v6uVI~
        if (s.st_dev == dev) {                                     //~v6uVI~
            rc=0;                                                  //~v6uVI~
            break;                                                 //~v6uVI~
        }                                                          //~v6uVI~
    }                                                              //~v6uVI~
    endmntent(fp);                                                 //~v6uVI~
    return rc;                                                     //~v6uVI~
#endif //!ARM                                                      //~v6uVI~
}                                                                  //~v6uVI~
//*****************************************************            //~v6B8I~
//*get devt using stat                                             //~v6B8I~
//rc:>=:err,1:root                                                 //~v6B8R~
//*****************************************************            //~v6B8I~
int filegetdevt(int Popt,char *Ppfpath,dev_t *Ppdevt)              //~v6B8I~
{                                                                  //~v6B8I~
    int rc=0,rc2,pathlen;                                          //~v6B8I~
    char wkfpath[_MAX_PATH],*pfpath;                                 //~v6B8I~//~v6B9R~
    FILEFINDBUF3 ffb3;                                             //~v6B8R~
//*****************************************                        //~v6B8I~
    UTRACEP("%s:opt=%x,path=%s\n",UTT,Popt,Ppfpath);               //~v6B8R~
    *Ppdevt=0;                                                     //~v6B8I~
    if (Popt & UFGDO_NEWFILE)                                      //~v6B8R~
    {                                                              //~v6B8I~
        pathlen=PATHLEN(Ppfpath);                                  //~v6B8R~
        if (pathlen<=0)                                            //~v6B8I~
        	rc=4;                                                  //~v6B8I~
        UmemcpyZ(wkfpath,Ppfpath,(size_t)(pathlen-1));               //~v6B8R~//~v6B9R~
    }                                                              //~v6B8I~
    else                                                           //~v6B9I~
        strcpy(wkfpath,Ppfpath);                                   //~v6B9R~
    pfpath=wkfpath;                                              //~v6B8I~//~v6B9I~
    if (!rc)                                                       //~v6B8I~
    {                                                              //~v6B8I~
    	for (;;)                                                   //~v6B8I~
        {                                                          //~v6B8I~
        	for (;;)                                               //~v6B8I~
            {                                                      //~v6B8I~
                if (ROOTDIR(pfpath))                               //~v6B8R~
                {                                                  //~v6B8R~
                    rc=1;                                          //~v6B8R~
                    break;                                         //~v6B8R~
                }                                                  //~v6B8R~
                if (!WILDCARD(pfpath))                             //~v6B8R~
                	break;                                         //~v6B8I~
                pathlen=PATHLEN(pfpath);                           //~v6B8R~
                if (pathlen==1)	//root                             //~v6B8I~
                {                                                  //~v6B8I~
                    rc=1;                                          //~v6B8I~
                    break;                                         //~v6B8I~
                }                                                  //~v6B8I~
                if (pathlen<=0)                                    //~v6B8R~
                {                                                  //~v6B8R~
                    rc=4;                                          //~v6B8R~
                    break;                                         //~v6B8R~
                }                                                  //~v6B8R~
                *(pfpath+pathlen-1)=0;                             //~v6B8R~
            }//for to drop wildcard                                                      //~v6B8I~//~v6B9R~
            if (rc)                                                //~v6B8I~
            	break;                                             //~v6B8I~
    		rc2=(int)ufstat(pfpath,&ffb3);                         //~v6B8R~
    		UTRACEP("%s:ufstat rc2=%d,path=%s,devt=%x\n",UTT,rc2,pfpath,ffb3.fsid);//~v6B8I~
    		if (!rc2)                                              //~v6B8I~
            {                                                      //~v6B8I~
            	*Ppdevt=ffb3.fsid;                                 //~v6B8I~
                break;                                             //~v6B8I~
            }                                                      //~v6B8I~
	        pathlen=PATHLEN(pfpath);                               //~v6B8R~
    	    if (pathlen<=0)                                        //~v6B8I~
            {                                                      //~v6B8I~
        		rc=5;                                              //~v6B8I~
                break;                                             //~v6B8I~
            }                                                      //~v6B8I~
        	*(pfpath+pathlen-1)=0;                                 //~v6B8I~
        }//for to parent path                                                          //~v6B8I~//~v6B9R~
    }                                                              //~v6B8I~
    UTRACEP("%s:rc=%d,devt=%x\n",UTT,rc,*Ppdevt);                  //~v6B8I~
    return rc;                                                     //~v6B8I~
}//filegetdevt                                                     //~v6B8I~
//*****************************************************            //~v6B8I~
//*search on /proc/diskstat to get filesystem name for the dev_t   //~v6B8I~
//rc:4:err                                                         //~v6B8I~
//*****************************************************            //~v6B8I~
int filegetdevicename(int Popt,dev_t Pdevt,char *Ppdevname,int Poutbuffsz)//~v6B8I~
{                                                                  //~v6B8I~
    FILE *  fp;                                                    //~v6B8R~
//  int rc=0,major,minor,mj,mn,len;                                //~v6B8R~//~v6C9R~
    int rc,major,minor,mj,mn,len;                                  //~v6C9I~
    char buff[1024];                                               //~v6B8I~
    char devname[1024];                                            //~v6B8I~
//*****************************************                        //~v6B8I~
    *Ppdevname=0;                                                  //~v6B8I~
	major=(int)MAJOR(Pdevt);                                       //~v6B8R~
	minor=(int)MINOR(Pdevt);                                       //~v6B8R~
    UTRACEP("%s:devt=x%x,maj=%d,min=%d\n",UTT,Pdevt,major,minor);  //~v6B8R~
    rc=4;                                                          //~v6C9I~
    if (!(fp=fopen("/proc/diskstats","r")))                        //~v6B8R~
    {                                                              //~v6B8I~
//      rc=4;                                                      //~v6B8I~//~v6C9R~
        ;                                                          //~v6C9I~
    }                                                              //~v6B8I~
    else                                                           //~v6B8I~
    while (fgets(buff,sizeof(buff)-1,fp))                          //~v6B8I~
    {                                                              //~v6B8I~
    	UTRACEP("%s:buff=%s\n",UTT,buff);                          //~v6B8I~
        sscanf(buff," %d %d %s ",&mj,&mn,devname);                 //~v6B8I~
    	UTRACEP("%s:maj=%d,min=%d vs %d-%d,name=%s\n",UTT,major,minor,mj,mn,devname);//~v6B8R~
        if (mj==major && mn==minor)                                //~v6B8R~
        {                                                          //~v6B8I~
        	len=(int)strlen(devname);                              //~v6B8I~
            len=min(len,Poutbuffsz);                               //~v6B8I~
            UmemcpyZ(Ppdevname,devname,(size_t)len);               //~v6B8R~
            rc=0;                                                  //~v6C9I~
            break;                                                 //~v6B8I~
        }                                                          //~v6B8I~
    }                                                              //~v6B8I~
    if (fp)                                                        //~v6B8I~
    	fclose(fp);                                                //~v6B8R~
    UTRACEP("%s:rc=%d,mntent=%p\n",UTT,rc,Ppdevname);              //~v6B8I~
    return rc;                                                     //~v6B8I~
}//filegetdevicename                                               //~v6B8I~
//*****************************************************            //~v6B8I~
//*search on /proc/mounts by filesystem name                       //~v6B8I~
//*using getmntent(set to static variable)                         //~v6B8I~
//rc:4:err                                                         //~v6B8I~
//*****************************************************            //~v6B8I~
int filegetdevicemntent(int Popt,char *Pdevname,struct mntent **Ppmntent)//~v6B8R~
{                                                                  //~v6B8I~
    FILE *      fp;                                                //~v6B8I~
    int rc=0;                                                      //~v6B8I~
	struct mntent *pmnt;                                           //~v6B8I~
//*****************************************                        //~v6B8I~
    UTRACEP("%s:Popt=%x,Pdevname=%s\n",UTT,Popt,Pdevname);         //~v6B8R~
    *Ppmntent=NULL;                                                //~v6B8R~
    if (!(fp=fopen("/proc/mounts","r")))                           //~v6B8I~
    {                                                              //~v6B8I~
        rc=4;                                                      //~v6B8I~
    }                                                              //~v6B8I~
    else                                                           //~v6B8I~
    while ((pmnt=getmntent(fp))!=NULL)                             //~v6B8I~
    {                                                              //~v6B8I~
    	UTRACEP("%s:fsn=%s,dir=%s,type=%s,opt=%s\n",UTT,pmnt->mnt_fsname,pmnt->mnt_dir,pmnt->mnt_type,pmnt->mnt_opts);//~v6B8I~
        if (Popt & UFGDO_ROOT)                                     //~v6B8I~
        {                                                          //~v6B8I~
        	if (ROOTDIR(pmnt->mnt_dir))                            //~v6B8R~
        	{                                                      //~v6B8I~
    			UTRACEP("%s:root dir\n",UTT);                      //~v6B8I~
        		*Ppmntent=pmnt;                                    //~v6B8I~
            	break;                                             //~v6B8I~
            }                                                      //~v6B8I~
        }                                                          //~v6B8I~
        else                                                       //~v6B8I~
        {                                                          //~v6B8I~
            if (!strcmp(Pdevname,pmnt->mnt_fsname))                //~v6B8R~
            {                                                      //~v6B8R~
                UTRACEP("%s:devname=%s,dir=%s,opt=%s\n",UTT,pmnt->mnt_fsname,pmnt->mnt_dir,pmnt->mnt_opts);//~v6B8R~
                *Ppmntent=pmnt;                                    //~v6B8R~
                break;                                             //~v6B8R~
            }                                                      //~v6B8R~
        }                                                          //~v6B8I~
    }                                                              //~v6B8I~
    fclose(fp);                                                    //~v6B8I~
    if (*Ppmntent==NULL) //not found                               //~v6C9I~
    	rc=4;                                                      //~v6C9I~
    UTRACEP("%s:rc=%d,mntent=%p\n",UTT,rc,*Ppmntent);              //~v6B8I~
    return rc;                                                     //~v6B8I~
}                                                                  //~v6B8I~
//*************************************************************************//~v6B8I~
//*check iocharset of file system for the pathname                 //~v6B8I~
//*rc:>=4 err,1:root,0:ok                                          //~v6B8R~
//*************************************************************************//~v6B8I~
int filegetmntent(int Popt,char *Pfpath,dev_t Pdevt,struct mntent **Ppmntent)//~v6B8R~
{                                                                  //~v6B8I~
#define DEVNAME_PREFIX "/dev/"                                     //~v6B8R~
    dev_t devt;                                                    //~v6B8I~
    int rc=0,rc2,len;                                              //~v6B8R~
    char devname[_MAX_PATH]={0};                                   //~v6B8R~
//************************                                         //~v6B8I~
	UTRACEP("%s:opt=%x,path=%s,devt=%x\n",UTT,Popt,Pfpath,Pdevt);  //~v6B8R~
    *Ppmntent=NULL;                                                //~v6B8R~
#ifdef ARMXXE                                                      //~v77qI~
    if (IS_DOCPATH(Pfpath))                                        //~v77qI~
    {                                                              //~v77qI~
		UTRACEP("%s:return 1 by DOC path,path=%s\n",UTT,Pfpath);   //~v77qI~
        return 1;   //utf8 as default                              //~v77qI~
    }                                                              //~v77qI~
#endif                                                             //~v77qI~
    if (!(devt=Pdevt))                                             //~v6B8I~
    {                                                              //~v6B8I~
    	rc2=filegetdevt(Popt,Pfpath,&devt);                        //~v6B8I~
        if (rc2==1)  //parent is root dir                          //~v6B8I~
            rc=1;	//utf8 as default                              //~v6B8R~
        else                                                       //~v6B8I~
    		if (rc2)                                               //~v6B8R~
        		rc=4;                                              //~v6B8R~
    }                                                              //~v6B8I~
    if (!rc)                                                       //~v6B8R~
    {                                                              //~v6B8I~
    	strcpy(devname,DEVNAME_PREFIX);                            //~v6B8I~
        len=(int)strlen(devname);                                  //~v6B8R~
    	rc2=filegetdevicename(Popt,devt,devname+len,(int)sizeof(devname)-len);//~v6B8R~
    	if (rc2)                                                   //~v6B8I~
    		rc=5;                                                  //~v6B8I~
    }                                                              //~v6B8I~
    if (!rc)                                                       //~v6B8R~
    {                                                              //~v6B8I~
    	rc2=filegetdevicemntent(Popt,devname,Ppmntent);            //~v6B8R~
    	if (rc2)                                                   //~v6B8I~
    		rc=6;                                                  //~v6B8I~
    }                                                              //~v6B8I~
	UTRACEP("%s:rc=%d,mntent=%p\n",UTT,rc,*Ppmntent);              //~v6B8I~
    return rc;                                                     //~v6B8I~
}//filegetmntent                                                   //~v6B8I~
//*************************************************************************//~v6B8M~
//*get option string value                                         //~v6B8M~
//*rc>=4:err,1:utf8,0:other than utf8                              //~v6B8R~
//*************************************************************************//~v6B8M~
int filegetmntoption(int Popt,struct mntent *Ppmntent,char *Poption,char *Ppout,int Poutbuffsz)//~v6B8M~
{                                                                  //~v6B8M~
    char *pc,*pc2,*pc3;                                            //~v6B8M~
    int len,rc=0;                                                  //~v6B8M~
//***********************                                          //~v6B8M~
	if (Ppout)                                                     //~v6B9I~
		*Ppout=0;                                                      //~v6B8M~//~v6B9R~
    pc=Ppmntent->mnt_opts;                                         //~v6B8M~
	UTRACEP("%s:opt=%s\n",UTT,pc);                                 //~v6B8M~
    if (!pc)                                                       //~v6B8M~
    	rc=4;                                                      //~v6B8M~
    else                                                           //~v6B8M~
    {                                                              //~v6B8M~
    	pc2=strstr(pc,Poption);                                    //~v6B8M~
    	if (!pc2)                                                  //~v6B8M~
        	rc=5;                                                  //~v6B8R~
        else                                                       //~v6B8M~
        {                                                          //~v6B8M~
        	pc2+=(int)strlen(Poption);                             //~v6B8M~
            pc3=strpbrk(pc2,", ");                                 //~v6B8M~
            if (!pc3)                                              //~v6B8M~
                rc=6;                                              //~v6B8M~
            else                                                   //~v6B8M~
            {                                                      //~v6B8M~
            	len=PTRDIFF(pc3,pc2);                              //~v6B8M~
                len=min(len,Poutbuffsz-1);                           //~v6B8M~//~v6B9R~
                if (Ppout)                                         //~v6B9I~
	                UmemcpyZ(Ppout,pc2,(size_t)len);                   //~v6B8M~//~v6B9R~
                if (!memcmp(pc2,UFGDO_DEFAULT_CS,sizeof(UFGDO_DEFAULT_CS)-1))              //~v6B8M~//~v6B9R~
                	rc=1;                                          //~v6B8M~
            }                                                      //~v6B8M~
        }                                                          //~v6B8M~
    }                                                              //~v6B8M~
    UTRACEP("%s:rc=%d,out=%s\n",UTT,rc,Ppout);                     //~v6B8M~
    return rc;                                                     //~v6B8M~
}//filegetmntoption                                                //~v6B8I~
//*************************************************************************//~v6B8I~
//*check iocharset of file system for the pathname                 //~v6B8I~
//*rc 1:utf8,2:utf8 as default,0:other than utf8                   //~v6B8R~
//*************************************************************************//~v6B8I~
int ufilegetiocharset(int Popt,char *Pfpath,dev_t Pdevt,char *Ppiocharset,int Poutbuffsz)//~v6B8R~
{                                                                  //~v6B8I~
#define MNTOPT_IOCHARSET "iocharset="                              //~v6B8I~
    int rc=0;                                                      //~v6B8I~
	struct mntent *pmnt;                                           //~v6B8I~
//************************                                         //~v6B8I~
	UTRACEP("%s:path=%s,devt=%x\n",UTT,Pfpath,Pdevt);              //~v6B8I~
	if (!(Popt & UFPCPO_NOCONV)                                    //~v6B9I~
	&&  !(Gulibutfmode & GULIBUTF_NOFPATHCONV))                    //~v6B9I~
    {                                                              //~v6B9I~
        rc=filegetmntent(Popt,Pfpath,Pdevt,&pmnt);                     //~v6B8R~//~v6B9R~
        if (rc)     //root or err                                      //~v6B8R~//~v6B9R~
        {                                                              //~v6B8I~//~v6B9R~
        	if (Ppiocharset)                                       //~v6B9I~
	            strcpy(Ppiocharset,UFGDO_DEFAULT_CS);                      //~v6B8R~//~v6B9R~
            rc=2;                                                      //~v6B8I~//~v6B9R~
        }                                                              //~v6B8I~//~v6B9R~
        else                                                           //~v6B8I~//~v6B9R~
        if (!rc) //not err,not root                                    //~v6B8R~//~v6B9R~
        {                                                              //~v6B8I~//~v6B9R~
            rc=filegetmntoption(Popt,pmnt,MNTOPT_IOCHARSET,Ppiocharset,Poutbuffsz);//~v6B8I~//~v6B9R~
            if (rc>1)   //use default                                  //~v6B8R~//~v6B9R~
            {                                                          //~v6B8I~//~v6B9R~
	        	if (Ppiocharset)                                   //~v6B9I~
	                strcpy(Ppiocharset,UFGDO_DEFAULT_CS);                  //~v6B8I~//~v6B9R~
                rc=2;                                                  //~v6B8I~//~v6B9R~
            }                                                          //~v6B8I~//~v6B9R~
        }                                                              //~v6B8I~//~v6B9R~
    }                                                              //~v6B9I~
	UTRACEP("%s:rc=%d,out=%s\n",UTT,rc,Ppiocharset);               //~v6B8I~
    return rc;                                                     //~v6B8I~
}//ufilegetiocharset                                               //~v6B8I~
//*******************************************************          //~v6B9I~
//*translate filename according filesystem iocharset               //~v6B9I~
//*rc:0: converted,else not converted                              //~v6B9I~
//******************************************************           //~v6B9I~
int ufilefnmcvcs(int Popt,char *Pfilename,int Plen,char *Ppout,int Pbuffsz)//~v6B9I~
{                                                                  //~v6B9I~
	int rc=0,rc2,ll,len,opt,lenu8,reslen,swcv=0,chklen;            //~v6B9R~
    char *pci,*pco,*pc;                                            //~v6B9R~
//********************************                                 //~v6B9I~
	UTRACEP("%s:opt=%x,fnm=%s\n",UTT,Popt,Pfilename);              //~v6B9I~
    *Ppout=0;                                                      //~v6B9I~
    pci=Pfilename;                                                 //~v6B9R~
    pco=Ppout;                                                     //~v6B9R~
    reslen=Pbuffsz-1;                                              //~v6B9R~
    for (;reslen>0;)                                               //~v6B9R~
    {                                                              //~v6B9R~
        pc=strchr(pci,DIR_SEPC);                                   //~v6B9R~
        if (!pc)                                                   //~v6B9R~
            len=(int)strlen(pci);                                  //~v6B9R~
        else                                                       //~v6B9R~
            len=PTRDIFF(pc,pci)+1;                                 //~v6B9R~
        opt=0;                                                     //~v6B9R~
        lenu8=utfgetutf8strlen(opt,pci,len,0/*ucsctr*/);           //~v6B9R~
        if (lenu8==len) //all utf8                                 //~v6B9R~
        {                                                          //~v6B9R~
            ll=min(reslen,len);                                    //~v6B9R~
            memcpy(pco,pci,(size_t)ll);                            //~v6B9R~
        }                                                          //~v6B9R~
        else                                                       //~v6B9R~
        {                                                          //~v6B9R~
            opt=UTFCVO_BUFFSZPARM|UTFCVO_ERRRET; //outbuff size parm specified//~v6B9R~
            lenu8=reslen;   //buff size limit                      //~v6B9R~
            rc2=utfcvl2fany(opt,0/*locale*/,pco,pci,0/*init offs*/,len,0/*out choftbl*/,0/*outdbvcs*/,&chklen,&lenu8,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~vagtI~//~v6B9R~
            if (rc2)    //err(1:all ascii)                         //~v6B9R~
            {                                                      //~v6B9R~
                ll=min(reslen,len);                                //~v6B9R~
                memcpy(pco,pci,(size_t)ll);                        //~v6B9R~
            }                                                      //~v6B9R~
            else                                                   //~v6B9R~
            {                                                      //~v6B9R~
                ll=lenu8;                                          //~v6B9R~
                swcv=1;                                            //~v6B9R~
            }                                                      //~v6B9R~
        }                                                          //~v6B9R~
        pco+=ll;                                                   //~v6B9R~
        reslen-=ll;                                                //~v6B9R~
        pci+=len;                                                  //~v6B9R~
        if (!pc)                                                   //~v6B9R~
            break;                                                 //~v6B9R~
    }                                                              //~v6B9R~
    *pco++=0;                                                      //~v6B9R~
    rc=(swcv?0:1);      //0 if converted                           //~v6B9I~
	UTRACEP("%s:return out=%s,rc=%d\n",UTT,Ppout,rc);              //~v6B9I~
    return rc;                                                     //~v6B9I~
}//ufilefnmcvcs                                                    //~v6B9I~
//*******************************************************          //~v6B9I~
//*On Linux,return according filesystem iocharset                  //~v6B9I~
//*rc:0x01: converted,0x02:iocs=u8,0x04:iocs unknown               //~v6B9R~
//******************************************************           //~v6B9I~
char *ufullpathCP(int Popt,char *Pfullpath,char *Pfilename,size_t Plen,int *Pprc)//~v6B9I~
{                                                                  //~v6B9I~
	int rc=0,rc2,rc3,opt;                                          //~v6B9R~
    char *pfpath;                                                  //~v6B9I~
    PUFTPHOST puftph;                                              //~v6B9I~
    char wkcvfnm[_MAX_PATH];                                       //~v6B9R~
//********************************                                 //~v6B9I~
	UTRACEP("%s:opt=%x,fnm=%s\n",UTT,Popt,Pfilename);              //~v6B9I~
    if (Pprc)                                                      //~v6B9I~
		*Pprc=0;                                                   //~v6B9R~
	if (uftpisremote(Pfilename,&puftph))	//ftp filename         //~v6B9I~
    	return uftpfullpath(puftph,Pfullpath,Pfilename,Plen);//0:host name is with filename//~v6B9I~
    pfpath=ufullpath(Pfullpath,Pfilename,Plen);	                   //~v6B9I~
	UTRACEP("%s:ufullpath=%s\n",UTT,Pfullpath);                    //~v6B9R~
    opt=Popt;                                                      //~v6B9R~
    rc2=ufilegetiocharset(opt,Pfullpath,0/*Pdevt*/,0/*iocharset*/,0/*buffsz*/);//~v6B9R~
    if (rc2)    //use utf8 as iocharset                            //~v6B9R~
    {                                                              //~v6B9R~
        if (rc2==1) //explicit utf8 iocharset                      //~v6B9I~
            rc|=UFPCPRC_IOCS_U8;                                   //~v6B9R~
        else                                                       //~v6B9I~
            rc|=UFPCPRC_IOCS_UNKNOWN;                              //~v6B9I~
        rc3=ufilefnmcvcs(Popt,Pfullpath,(int)strlen(Pfullpath),wkcvfnm,(int)sizeof(wkcvfnm));//~v6B9R~
        if (!rc3)  //done lc-->utf8                                //~v6B9R~
        {                                                          //~v6B9R~
            pfpath=ufullpath(Pfullpath,wkcvfnm,Plen);              //~v6B9R~
            rc|=UFPCPRC_CONVU8;                                    //~v6B9R~
        }                                                          //~v6B9R~
    }                                                              //~v6B9R~
    if (Pprc)                                                      //~v6B9I~
	    *Pprc=rc;                                                  //~v6B9R~
	UTRACEP("%s:return fpath=%s,rc=%d\n",UTT,pfpath,rc);           //~v6B9R~
    return pfpath;                                                 //~v6B9I~
}//ufullpathCP                                                     //~v6B9I~
//**********************************************************************//~v784I~
unsigned udosfindfirstOpt(int Popt,char *Ppfname,HDIR *Pphdir,unsigned int Pattr,FILEFINDBUF3 *Ppfstat3)//~v784I~
{                                                                  //~v784I~
	unsigned int rc;                                               //~v784I~
//************************                                         //~v784I~
	UTRACEP("%s:opt=0x%x,attr=0x%x,fnm=%s\n",UTT,Popt,Pattr,Ppfname);//~v784I~
	SswFFopt=Popt & ~UDFFOO_NOMSG;                                 //~v784I~
	if (Popt & UDFFOO_NOMSG)		//no errmsg option             //~v784I~
		rc=udosfindfirstnomsg(Ppfname,Pphdir,Pattr,Ppfstat3);      //~v784I~
    else                                                           //~v784I~
		rc=udosfindfirst(Ppfname,Pphdir,Pattr,Ppfstat3);           //~v784I~
	SswFFopt=0;                                                    //~v784I~
	UTRACEP("%s:rc=%d,hdir=%p,fnm=%s\n",UTT,rc,*Pphdir,Ppfname);   //~v784I~
    return rc;                                                     //~v784I~
}                                                                  //~v784I~
