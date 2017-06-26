//*CID://+v6J0R~:                             update#=  268;       //~v6J0R~
//*************************************************************
//*ufile4.c                                                        //~v083R~
//*  utempnam udirwalk ugetdiskfree ufileishpfs ufileisvfat ufileisntfs//~v5i0R~
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1I~
//            and it cause fpath area overflow then 0c4            //~v6H1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6xe:150113 add ufseek and uftell for common to 32 and 64 bit    //~v6xeI~
//v6x0:150105 BUG:offset value is long long for fseek error msg    //~v6x0I~
//v6uV:140608 support isvfat,isntfs for LNX                        //~v6uVI~
//v6uC:140524 (BUG of v6u0)duplicate ufree pslinkW(dirwalk free member,then walk into subdir,the free it)//~v6uCI~
//v6u5:140401 (Win)getdisfree fail when fnm is wildcard,return value is independent to subdir(free space is of target drive)//~v6u5I~
//v6u4:140401 (Win)getdisfree errmsg parameter err for UNC         //~v6u4I~
//v6r5:131224 (WIN:BUG)errmsg print fmt unmatch                    //~v6r5I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6q1:131128 (WIN)for wildname dir,use alias to get dirlist       //~v6q1I~
//v6kr:130705 change outoflink check logic                         //~v6krI~
//v6kp:130704 (BUG)relative slink is outof link err when copy to same dir//~v6kpI~
//v6kf:130627 warning relative link may lose to linkage after copy //~v6kfI~
//v6ke:130626 add work area to udirlist not to use attr field      //~v6keI~
//v6kc:130625 slink err flag by ufstat(0x0200)                     //~v6kcI~
//v6k4:130610 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ufile4.c slink loop chk                              //~v6k4I~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6bo:111214 putenv(dont free)/setenv(copyed, can be free)        //~v6boI~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v5nu:081107 (Win)\\x\y remote filename support(support also driveid \: for CDRIVE/CDIR)//~v5nuI~
//v5nh:081020 lockfile support so SOnn                             //~v5nhI~
//v5kw:070820 support bkup before reopen at save                   //~v5kwI~
//v5i0:060419 add ufileisntfs                                      //~v5i0I~
//v5b5:040124 (LNX)TuboLinux6 dose not support mktempd             //~v5b5I~
//v5b0:040115 (LNX:BUG)mkstmp is for file only,mkdtmp is required for temp dir//~v5b0I~
//v5a6:040104 (UNX,FTP)save slink uid,gid,uname,gname on dirlist for xe dirlist//~v5a6I~
//v5a5:040103 (BUG:UNX)dirlist missing slink size/ts               //~v5a5I~
//v59x:040101 (UNX,FTP)save slink timestamp and size for dirlist for xe//~v59xI~
//v59i:031108 ftp support:add username etc to windows udirlist/ffb3//~v59iI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v59d:030816 ftp support                                          //~v59dI~
//v583:030808 (LNX)by link warning msg "use mkstemp as alternative of tempnam"//~v583I~
//v57a:021210 udirwalk:apply dir top mask also to top level file   //~v57aI~
//v579:021207 performance tuning(get dir entry at once if avail)   //~v578I~
//v578:021207 (UNX)udirlist performance tuning(stat call on the current dir)//~v579R~
//v573:021009 (UNX)slink err msg bypass option(u#48)               //~v573I~
//v572:020929 (WIN)by the reason of v571;del "TMP" env var temporary//~v572I~
//v571:020923 (WIN)tempnam should be _tempnam for prefix use.      //~v571I~
//            (but,dir parm is ignored if env var TMP is specified)//~v571I~
//v56A:020809 (BUG)S-link loop chk;for the case slinked to looped path(over update#33)//~v56AR~
//v56z:020809 (BUG)S-link loop chk;it should be chked fullname.    //~v56zI~
//v56u:020722 topmask apply to top subdir only(for xds)            //~v56uI~
//v56t:020712 (UNX)udirwalk slink skip option                      //~v56tI~
//v56r:020712 (UNX)udirwalk slink err chk by S_ISLNK but no slink name,the skip process//~v56rI~
//v56q:020712 (UNX)slink loop chk(v56k) at udirwalk not ufstat.(allow xe dir list display)//~v56rR~
//v56p:020711 (UNX) udirwalk;chk permission before udirlist to avoid double err msg.//~v56pI~
//v56m:020711 udirwalk;option to skip dir by rc=-5 from user func  //~v56mI~
//v56f:020710 XDS require EOF call even if long name err           //~v56fI~
//v56e:020710 udirwalk;slink loop protection                       //~v56eI~
//v56d:020710 (BUG)udirwalk;process in the dir is stopped when subdir has no member//~v56dI~
//v56b:020710 dirwalk:limit no msg option to not found msg only(use dirlistnomsg)//~v56bI~
//v569:020706 dirwalk missing ufree(causing xff storage shortage)  //~v569I~
//v55c:020428 (UNX:BUG)ROOTDIR chk for mdos disket                 //~v55cI~
//v553:020414 udirwalk missed accesstime etc for dir top;(v545,v547 is required to udirwalk)//~v553I~
//v528:020217 option to apply mask 1st level only for xds          //~v528I~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v377:000930 LINUX support(dir seperater is "/" not "\")          //~v377I~
//v372:000928 LINUX support(keep uid/gid/fsid in dirlist)          //~v372I~
//v369:000927 LINUX support("*" mean all member,"*.*" require intermediate ".";//~v369I~
//            under windows those are same effect)                 //~v369I~
//v350:000926 LINUX support(no drive id)                           //~v350I~
//v348:000926 LINUX support(ugetdiskfree now returns file system id additionaly)//~v348I~
//v327 000820:LINUX support                                        //~v327I~
//v202:981101 udirwalk:end of list call support for uds(dir size calc)//~v201I~
//v201:981101 (BUG)udirwalk:level shoud be down(increment only bug)//~v201I~
//v194:980920 (BUG of WIN)win allow filename ".aaa"                //~v194I~
//v120:971116 (BUG:GCC)when env var LFN changed N to Y,it is needed to force//~v120I~
//                     call _get_volume_info at _use_lfn.          //~v120I~
//                     new option to ufileisvfat                   //~v120I~
//v101:971009 long filename                                        //~v101I~
//            ufile4.c/h:add ufileishpfs(return file system id)    //~v101I~
//                       lfn and alias for W95                     //~v101I~
//            ufilevfat for DOS/W95                                //~v101I~
//v083:970508 add ugetdiskfree                                     //~v083I~
//v063:970210:udirwalk function add                                //~v063I~
//v050:961201:add utempnam                                         //~v050I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5B12I~
                                                                   //~v063I~
//*******************************************************
#ifdef UNX                                                         //~v327I~
	#include <sys/vfs.h>                                           //~v327I~
	#include <sys/stat.h>                                          //~v56rI~
    #include <fcntl.h>  //_USE_LFN macro                           //~v5nhI~
#else                                                              //~v327I~
#ifdef DOS
    #include <dos.h>                                               //~v083I~
    #ifdef DPMI                                                    //~v083I~
        #include <fcntl.h>  //_USE_LFN macro                       //~v101R~
        #include <errno.h>                                         //~v101I~
        #include <sys/stat.h>                                      //~v5nhI~
        #include <unistd.h>                                        //~v5nuI~
    #endif                                                         //~v083I~
#else
    #include <fcntl.h>  //_USE_LFN macro                           //~v5nhI~
    #include <io.h>  //_USE_LFN macro                              //~v5nhI~
    #include <sys/stat.h>                                          //~v5nhI~
    #ifdef W32                                                     //~v022I~
        #include <dos.h>                                           //~v063I~
        #include <windows.h>                                       //~v083I~
    #else                                                          //~v022I~
        #define INCL_DOSFILEMGR                                    //~v083I~
        #define INCL_BASE                                          //~v083I~
        #include <os2.h>                                           //~v083I~
    #endif                                                         //~v022I~
#endif
#endif                                                             //~v327I~
#ifdef LNX                                                         //~v6uVI~
	#include <dirent.h>                                            //~v6uVI~
	#include <mntent.h>                                            //~v6uVI~
#endif                                                             //~v6uVI~

//*******************************************************
#include <ulib.h>
#include <ufile.h>
#ifdef LNX                                                         //~v6uVI~
#include <ufile1l.h>                                               //~v6uVI~
#endif                                                             //~v6uVI~
#include <ufile2.h>                                                //~v5b5I~
#include <ufemsg.h>                                                //~v083I~
#include <ufile4.h>                                                //~v063I~
#include <ufile5.h>                                                //~v6xeI~
#include <uerr.h>
#include <utrace.h>                                                //~v063M~
#include <ualloc.h>                                                //~v063M~
#include <ustring.h>                                               //~v6kfI~
#ifdef UNX                                                         //~v50GI~
    #include <ufile1l2.h>                                          //~v50GI~
    #include <uunxsub.h>                                           //~v5nhI~
#endif                                                             //~v50GI~
//**********************************************************************//~v063I~
#ifdef LNX                                                         //~v5b0I~
	static int Stempnamdsw=0;                                      //~v5b0I~
	static int Stempnamder=0;                                      //~v5b0I~
#endif                                                             //~v5b0I~
static  int  Sopt;                                                 //~v063I~
static  char *Sdirmask;                                            //~v063I~
static  char *Sfilemask;                                           //~v063I~
static  int Sattrmask;                                             //~v063I~
static  int (*Sfunc)(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,//~v063R~
                int Pdepth,void *Pdata,int *Papplrc);              //~v063I~
static  void *Sdata;                                               //~v063I~
static  int  *Sapplrc;                                             //~v063I~
//static  int  Sdirlevel;                                          //~v201R~
static  int  Sstopdepth;                                           //~v063I~
static  int  Scallctr;                                             //~v063I~
static  int  Sapplytopmask=0;                                      //~v528I~
static  int  Sstartdirlen;                                         //~v6k4I~
static  char  Sstartdir[_MAX_PATH];                                //~v6k4I~
//*                                                                //~v063I~
//int udirwalksub(char *Pdir,PUDIRLIST Ppudirlist);                //~v201R~
int udirwalksub(char *Pdir,PUDIRLIST Ppudirlist,int Plevel);       //~v201I~
//*******************************************************
//*dummy for lib(same name as file)                     *
//*******************************************************
void ufile4(void)                                                  //~v050R~
{
    return;
}

//****************************************************************//~5913I~
//utempnam                                                         //~v050R~
//* return temp file name                                          //~v050R~
//*****                                                         //~5913I~
//*parm1:dir name                                                  //~v050R~
//*parm2:filename prefix                                           //~v050R~
//*parm3:optional output addr,if 0 you must free returned addr     //~v050I~
//*retrn:tem file name ptr                                         //~v050R~
//****************************************************************//~5913I~
char *utempnam(char *Pdir,char *Pprefix,char *Ptempfile)           //~v050R~
{                                                               //~5913I~
    char *temp;                                                    //~v050I~
#ifdef W32                                                         //~v572I~
	int  putenvsw=0;                                               //~v572I~
//  char *pc,envtmpdir[_MAX_PATH+8];                               //~v572I~//~v6boR~
    char *pc;                                                      //~v6boI~
    static char envtmpdir[_MAX_PATH+8];	//putenv requires not freed area//~v6boI~
#endif                                                             //~v572I~
#ifdef LNX                                                         //~v583I~
    #ifdef LNXLC2   //new version                                  //~v583I~
        int rc;                                                    //~v583I~
	    char tempwk[_MAX_PATH];                                    //~v583R~
    #endif                                                         //~v583I~
#else                                                              //~v59dI~
  #ifdef UNX                                                       //~v59xI~
  #else                                                            //~v59xI~
   #ifdef W32                                                      //~v59dI~
    char *temptmp;                                                 //~v59dI~
   #endif                                                          //~v59dI~
  #endif                                                           //~v59xI~
#endif                                                             //~v583I~
//********************                                          //~5913I~
#ifdef UNX                                                         //~v327I~
  #ifdef ARM	//tmp dose not exist                               //~v6b1I~
  	Pdir=gettempnampath(Pdir);	//chk /sdcard,/data                //~v6b1I~
  #else                                                            //~v6b1I~
	if (!(Pdir && *Pdir))                                          //~v59dI~
    	Pdir="/tmp";                                               //~v59dI~
  #endif                                                           //~v6b1I~
  #ifdef LNX                                                       //~v583I~
    #ifdef LNXLC2   //new version                                  //~v583I~
      if (*(Pdir+strlen(Pdir)-1)=='/') //avoid errno=9(invalid filename) when xxx//xxx fmt//~v5kwR~
    	sprintf(tempwk,"%s%sXXXXXX",Pdir,Pprefix);	//mkstemp fmt  //~v5kwI~
      else                                                         //~v5kwI~
    	sprintf(tempwk,"%s/%sXXXXXX",Pdir,Pprefix);	//mkstemp fmt  //~v583R~
      if (Stempnamdsw)                                             //~v5b0I~
      {                                                            //~v5b0I~
#ifdef LNXLC2TL6     //turblinux6 dose no support mkdtemp          //~v5b5I~
    	rc=mkstemp(tempwk); //rc fdno                              //~v5b5R~
        Stempnamder=errno;                                         //~v5b5I~
        if (rc!=-1)                                                //~v5b5R~
        {                                                          //~v5b5I~
        	rc=uremove(tempwk);                                    //~v5b5I~
	        Stempnamder=errno;                                     //~v5b5I~
            if (rc)                                                //~v5b5I~
	        	rc=-1;                                             //~v5b5I~
            else                                                   //~v5b5I~
            {                                                      //~v5b5I~
		     	Stempnamder=rc=umkdir(tempwk);                     //~v5b5I~
                if (rc)                                            //~v5b5I~
                	rc=-1;                                         //~v5b5I~
            }                                                      //~v5b5I~
        }                                                          //~v5b5I~
#else                                                              //~v5b5I~
    	if (mkdtemp(tempwk))                                       //~v5b0R~
        	rc=0;                                                  //~v5b0I~
        else                                                       //~v5b0I~
        	rc=-1;                                                 //~v5b0R~
        Stempnamder=errno;                                         //~v5b0I~
#endif                                                             //~v5b5I~
		if (rc)                                                    //~v5b5I~
        	ufileapierr("mkdtemp",tempwk,Stempnamder);             //~v5b5I~
      }                                                            //~v5b0I~
      else                                                         //~v5b0I~
    	rc=mkstemp(tempwk);                                        //~v583R~
        if (rc==-1)                                                //~v583I~
        	temp=0;       //err id                                 //~v583I~
        else                                                       //~v583I~
        {                                                          //~v583I~
        	temp=malloc(strlen(tempwk)+1);                         //~v583I~
        	strcpy(temp,tempwk);                                   //~v583R~
        }                                                          //~v583I~
    #else                                                          //~v583I~
    	temp=tempnam(Pdir,Pprefix);                                //~v583I~
    #endif                                                         //~v583I~
  #else                                                            //~v583I~
    temp=tempnam(Pdir,Pprefix);                                    //~v327I~
  #endif                                                           //~v583I~
#else                                                              //~v327I~
  #ifdef W32                                                       //~v59dI~
    temptmp=0;                                                     //~v59dI~
	if (!(Pdir && *Pdir))                                          //~v59dI~
    {                                                              //~v59dI~
    	pc=getenv("TMP");                                          //~v59dR~
        if (!pc)                                                   //~v59dI~
        	pc=getenv("TEMP");                                     //~v59dR~
        if (!pc)                                                   //~v59dI~
        	pc="c:\\";                                             //~v59dR~
        Pdir=temptmp=pc;                                           //~v59dI~
    }                                                              //~v59dI~
  #endif //W32                                                     //~v59dI~
#ifdef DOS                                                         //~v050R~
    temp=tempnam(Pdir,Pprefix);                                    //~v050I~
#else                                                           //~5917I~
    #ifdef W32                                                     //~v050I~
//      temp=tempnam(Pdir,Pprefix);                                //~v571R~
      if (!temptmp)	//not null dir parm                            //~v59dI~
        if (Pdir && *Pdir)                                         //~v572I~
            if (pc=getenv("TMP"),pc)                               //~v572R~
            {                                                      //~v572R~
                putenvsw=1;                                        //~v572R~
                sprintf(envtmpdir,"TMP=%s",pc);                    //~v572R~
                putenv("TMP=");                                    //~v572R~
            }                                                      //~v572R~
        temp=_tempnam(Pdir,Pprefix);                               //~v571I~
    	if (putenvsw)                                              //~v572I~
    		putenv(envtmpdir);	//restore                          //~v572I~
    #else                                                          //~v050I~
        temp=_tempnam(Pdir,Pprefix);                               //~v050I~
    #endif                                                         //~v050R~
#endif                                                             //~v050I~
#endif                                                             //~v327I~
    if (temp)                                                      //~v050I~
    {                                                              //~v050I~
        if (Ptempfile)                                             //~v050I~
        {                                                          //~v050I~
            strcpy(Ptempfile,temp);                                //~v050I~
            free(temp);                                            //~v050I~
            temp=Ptempfile;                                        //~v050I~
        }                                                          //~v050I~
    }                                                              //~v050I~
    return temp;                                                   //~v050I~
}//utempnam                                                        //~v050R~
#ifdef LNX                                                         //~v5b0I~
//**************************************************************** //~v5b0I~
//utempnamd                                                        //~v5b0I~
//* return temp dir name(it is already mkdir'ed)                   //~v5b0I~
//**************************************************************** //~v5b0I~
char *utempnamd(char *Pdir,char *Pprefix,char *Ptempfile)          //~v5b0I~
{                                                                  //~v5b0I~
	char *temp;                                                    //~v5b0I~
//********************                                             //~v5b0I~
	Stempnamdsw=1;                                                 //~v5b0I~
	temp=utempnam(Pdir,Pprefix,Ptempfile);                         //~v5b0R~
//  if (!temp)                                                     //~v5b5R~
//      ufileapierr("mkdtemp",Pdir,Stempnamder);                   //~v5b5R~
	Stempnamdsw=0;                                                 //~v5b0I~
    return temp;                                                   //~v5b0I~
}//utempnamd                                                       //~v5b0I~
#endif                                                             //~v5b0R~
//**************************************************************** //~v050I~
//ufgetpos                                                         //~v050I~
//* get current position                                           //~v050I~
//*****                                                            //~v050I~
//*parm1:FILE *                                                    //~v050I~
//*retrn:pos_t,-1 if err                                           //~v050I~
//**************************************************************** //~v050I~
//long ufgetpos(FILE *Pfh)                                         //~v6x0R~
FILESZT ufgetpos(FILE *Pfh)                                        //~v6x0I~
{                                                                  //~v050I~
//********************                                             //~v050I~
#ifdef DOS                                                         //~v050I~
#else                                                              //~v050I~
    #ifdef W32                                                     //~v050I~
    #else                                                          //~v050I~
    #endif                                                         //~v050I~
#endif                                                             //~v050I~
//  return ftell(Pfh);                                             //~v6xeR~
    return uftell(Pfh);                                            //~v6xeI~
}//ufgetpos                                                        //~v050I~
                                                                   //~v050I~
//**********************************************************************//~v063I~
//* udirwalk                                                       //~v063I~
//*  parm1:option(see define value)                                //~v063I~
//*  parm2:starting dir                                            //~v063I~
//*  parm3:sub dir name mask or 0(*.*)                             //~v063I~
//*  parm4:file name mask or 0(*.*)                                //~v063I~
//*  parm5:file attribute mask                                     //~v063I~
//*        if dir bit on,dir passed as file entry regardless parm1 option//~v063I~
//*  parm6:stop depth,0 for starting dir                           //~v194R~
//*  parm7:addr of func:rc func(dir-name,fullpath,UDIRLIST*,dir-nest-level,func-data)//~v063R~
//*         rc       :0 contine walk,else stop with the rc         //~v063I~
//*         dir-name :fullpath name without last \ padded except root//~v063I~
//*         fullpath :0 for dir entry,-1 for end of dir-list entry //~v201R~
//*         udirlist :0 if empty call and file call only req       //~v063I~
//*                   "\" of file name mean root dir               //~v063I~
//*         dir-depth:0 means start dir,1 mean file/dir under that //~v063I~
//*         func-data:pointer passed to func                       //~v063I~
//*         appl rc  :pointer appl rc set area                     //~v063I~
//*  parm8:user data pointer passed to func(option)                //~v063I~
//*  parm9:func rc area(option)                                    //~v063I~
//*  rc   :see define value                                        //~v063I~
//**********************************************************************//~v063I~
int  udirwalk(int Popt,char *Pstartdir,char *Pdirmask,char *Pfilemask,//~v063I~
                int Pattrmask,int Pstopdepth,                      //~v063I~
               int (*Pfunc)(char *Pdir,char *Pfullpath,UDIRLIST *Pudirlist,//~v063R~
                            int Pdepth,void *Pdata,int *Papplrc),  //~v063I~
               void *Pfuncdata,int *Prc)                           //~v063I~
{                                                                  //~v063I~
    FILEFINDBUF3 fstat3;                                           //~v063I~
    char fullpath[_MAX_PATH];                                      //~v063I~
    char curpath[_MAX_PATH];                                       //~v063I~
    int rc=0;                                                      //~v063R~
//  char msgoptand;                                                //~v56bR~
//  UDIRLIST  udirlists;                                           //~v063R~//~v6qaR~
//  UDIRLIST_WK(udirlists,wkslinkname);                            //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udirlists,wkname,wknamew,wkslinkname);             //~v6J0I~
#ifndef UNX                                                        //~v327I~
    char curdrive=0;                                                 //~v063I~//~v6h7R~
#endif                                                             //~v327I~
//*******************************                                  //~v063I~
//*save parm to avoid pass through walk                            //~v063I~
    Sopt=Popt;                                                     //~v063I~
	Sapplytopmask=(Popt & UDIRWALK_TOPMASK);                       //~v528I~
    Sfunc=Pfunc;                                                   //~v063I~
    Sdirmask=Pdirmask;                                             //~v063I~
    if (!Sdirmask || !*Sdirmask)                                   //~v063I~
//      Sdirmask="*.*";                                            //~v369R~
        Sdirmask=DIR_ALLMEMB;                                      //~v369I~
    Sfilemask=Pfilemask;                                           //~v063I~
    if (!Sfilemask || !*Sfilemask)                                 //~v063I~
//      Sfilemask="*.*";                                           //~v369R~
        Sfilemask=DIR_ALLMEMB;                                     //~v369I~
    Sattrmask=Pattrmask;                                           //~v063I~
    Sstopdepth=Pstopdepth;                                         //~v063I~
    Sdata=Pfuncdata;                                               //~v063I~
    Sapplrc=Prc;                                                   //~v063R~
//*                                                                //~v063I~
    if (!ufullpath(fullpath,Pstartdir,sizeof(fullpath)))    //drop last \ except root//~v063I~
        rc=UDIRWALK_RC_NAME;                                       //~v063I~
    else                                                           //~v063I~
    {                                                              //~v063I~
//      memset(&udirlists,0,sizeof(udirlists));                    //~v063R~//~v6qaR~
//      UDIRLIST_WK_INIT(udirlists,wkslinkname);                   //~v6qaI~//~v6J0R~
        UDIRLIST_WK_INIT(udirlists,wkname,wknamew,wkslinkname);    //~v6J0R~
//      if (ROOTDIR(fullpath))                                     //~v55cR~
        if (ROOTDIR2(fullpath))                                    //~v55cI~
        {                                                          //~v063I~
//          strcpy(udirlists.name,fullpath+2);  //"\" root id      //~v350R~
//          strcpy(udirlists.name,fullpath+ROOTDIRPOS);  //"\" root id//~v350I~//~v6J0R~
            udirlist_setname(0,&udirlists,fullpath+ROOTDIRPOS,0);  //"\" root id//~v6J0I~
            udirlists.attr=0xff;    //mean root                    //~v063R~
        }                                                          //~v063I~
        else                                                       //~v063I~
        {                                                          //~v063I~
            if (ufstat(fullpath,&fstat3))                          //~v063I~
            {                                                      //~v063I~
                uerrmsg("%s is not found",                         //~v063I~
                        "%s がみつかりません",                     //~v063I~
                        fullpath);                                 //~v063I~
                rc=UDIRWALK_RC_NOTF;                               //~v063I~
            }                                                      //~v063I~
            else                                                   //~v063I~
                if (!(fstat3.attrFile & FILE_DIRECTORY))           //~v063I~
                {                                                  //~v063I~
                    uerrmsg("%s is not directory",                 //~v063I~
                            "%s はディレクトリーではありません",   //~v063I~
                            fullpath);                             //~v063I~
                    rc=UDIRWALK_RC_NOTDIR;                         //~v063I~
                }                                                  //~v063I~
            if (!rc)                                               //~v063I~
            {                                                      //~v063I~
#ifdef W32                                                         //~v101I~
//              memcpy(udirlists.name,fstat3.cFileName,sizeof(udirlists.name));//~v101R~//~v6J0R~
                udirlist_setname(0,&udirlists,fstat3.cFileName,sizeof(fstat3.cFileName));//~v6J0R~
                memcpy(udirlists.alias,fstat3.achName,sizeof(udirlists.alias));//~v101R~
                udirlists.srcattr=fstat3.srcattr;                  //~v59iR~
                memcpy(udirlists.uname,fstat3.uname,sizeof(udirlists.uname));//~v59iI~
                memcpy(udirlists.gname,fstat3.gname,sizeof(udirlists.gname));//~v59iI~
//              memcpy(udirlists.slink,fstat3.slink,sizeof(udirlists.slink));//~v59iR~//~v6qaR~
                memcpy(wkslinkname,fstat3.slink,sizeof(wkslinkname));//~v6qaR~
                udirlists.slinksize=fstat3.slinksize;              //~v59xI~
                udirlists.slinkfdate=fstat3.slinkfdate;            //~v59xI~
                udirlists.slinkftime=fstat3.slinkftime;            //~v59xI~
            	memcpy(udirlists.slinkuname,fstat3.slinkuname,sizeof(udirlists.slinkuname));//~v5a6I~
            	memcpy(udirlists.slinkgname,fstat3.slinkgname,sizeof(udirlists.slinkgname));//~v5a6I~
#else                                                              //~v101I~
//              strcpy(udirlists.name,fstat3.achName);             //~v063R~//~v6J0R~
                udirlist_setname(0,&udirlists,fstat3.achName,sizeof(fstat3.achName));//~v6J0R~
#endif                                                             //~v101I~
                                                                   //~v372I~
#ifdef UNX                                                         //~v372I~
                udirlists.srcattr=fstat3.srcattr;                  //~v59iI~
//              memcpy(udirlists.slink,fstat3.slink,sizeof(udirlists.slink));//~v59iI~//~v6qaR~
                memcpy(wkslinkname,fstat3.slink,sizeof(wkslinkname));//~v6qaI~
                udirlists.attr=fstat3.attrFile;                    //~v372R~
                udirlists.fsid=fstat3.fsid;                        //~v372R~
                udirlists.inode=fstat3.inode;                      //~v6b1I~
                udirlists.uid =fstat3.uid;                         //~v372R~
                udirlists.gid =fstat3.gid;                         //~v372R~
            	udirlists.atime=fstat3.atime;                      //~v553R~
            	udirlists.mtime=fstat3.mtime;                      //~v553R~
            	udirlists.ctime=fstat3.ctime;                      //~v553R~
            	udirlists.slinkmtime=fstat3.slinkmtime;            //~v5a5I~
            	udirlists.slinkfdate=fstat3.slinkfdate;            //~v5a5I~
            	udirlists.slinkftime=fstat3.slinkftime;            //~v5a5I~
            	udirlists.slinksize =fstat3.slinksize ;            //~v5a5I~
                udirlists.slinkuid  =fstat3.slinkuid;              //~v5a6I~
                udirlists.slinkgid  =fstat3.slinkgid;              //~v5a6I~
#else  //!UNX                                                      //~v372I~
//              udirlists.attr=(char)fstat3.attrFile;              //~v59eR~
                udirlists.attr=(ULONG)fstat3.attrFile;             //~v59eI~
	#ifdef W32                                                     //~v553I~
    			udirlists.ftCreationTime  =fstat3.ftCreationTime;  //~v553R~
    			udirlists.ftLastAccessTime=fstat3.ftLastAccessTime;//~v553R~
    			udirlists.ftLastWriteTime =fstat3.ftLastWriteTime; //~v553R~
    #endif                                                         //~v553I~
    #ifdef OS2                                                     //~v553I~
    			udirlists.ctime =fstat3.ftimeCreation;             //~v553R~
    			udirlists.cdate =fstat3.fdateCreation;             //~v553R~
    			udirlists.atime =fstat3.ftimeLastAccess;           //~v553R~
    			udirlists.adate =fstat3.fdateLastAccess;           //~v553R~
    #endif                                                         //~v553I~
#endif //!UNX                                                      //~v372I~
                                                                   //~v372I~
                udirlists.time=fstat3.ftimeLastWrite;              //~v063R~
                udirlists.date=fstat3.fdateLastWrite;              //~v063R~
                udirlists.size=fstat3.cbFile;                      //~v063R~
            }                                                      //~v063I~
        }//not rootdir                                             //~v063I~
    }//fullpath ok                                                 //~v063I~
    if (!rc)                                                       //~v063I~
    {                                                              //~v063I~
        if (Sopt & UDIRWALK_CD)     //change dir opt               //~v063R~
        {                                                          //~v063I~
#ifndef UNX                                                        //~v327I~
            curdrive=ugetdrive();   //save curr drive              //~v063I~
            uchdrive(*fullpath);    //change                       //~v063I~
#endif                                                             //~v327I~
            ugetcwd(curpath);       //save curr path on the drive  //~v063I~
        }                                                          //~v063I~
//      Sdirlevel=0;    //top is 0                                 //~v201R~
        Scallctr=0;                                                //~v063I~
//msg ignore option                                                //~v063I~
//        msgoptand=0xff;     //at return and mask                 //~v56bR~
//        if (!UCBITCHK(Guerropt,GBL_UERR_NOMSGOUT)  //msgout now  //~v56bR~
//        &&  (Sopt & UDIRWALK_NOMSG))    //no msg out req         //~v56bR~
//        {                                                        //~v56bR~
//            UCBITON(Guerropt,GBL_UERR_NOMSGOUT); //*edit only,no output to any//~v56bR~
//            UCBITOFF(msgoptand,GBL_UERR_NOMSGOUT);  //reset it at return//~v56bR~
//        }                                                        //~v56bR~
                                                                   //~v063M~
//      rc=udirwalksub(fullpath,&udirlists);                       //~v201R~
        rc=udirwalksub(fullpath,&udirlists,0);  //level start from 0//~v201I~
                                                                   //~v063I~
//        Guerropt=(UCHAR)(Guerropt&msgoptand); //recover no msg option//~v56bR~
                                                                   //~v063I~
        if (Prc)                                                   //~v063I~
            *Prc=rc;                                               //~v063I~
        if (Sopt & UDIRWALK_CD)     //change dir opt               //~v063R~
        {                                                          //~v063I~
//          uchdir(curpath);    //restore                          //~v579R~
            uchdir(0,curpath);    //restore                        //~v579I~
#ifndef UNX                                                        //~v327I~
            uchdrive(curdrive); //restore                          //~v063I~
#endif                                                             //~v327I~
        }                                                          //~v063I~
        if (!Scallctr)                                             //~v063I~
        {                                                          //~v063I~
            uerrmsg("%s has no such file/dir (dir-mask=%s,file-mask=%s)\n",//~v063I~
                    "%s には該当がありません(dir-mask=%s,file-mask=%s)\n",//~v063I~
                    Pstartdir,Sdirmask,Sfilemask);                 //~v063I~
            rc=UDIRWALK_RC_EMPTY;                                  //~v063I~
        }                                                          //~v063I~
    }                                                              //~v063I~
    return rc;                                                     //~v063I~
}//udirwalk                                                        //~v063I~
//**********************************************************************//~v063I~
//* udirwalksub                                                    //~v063I~
//*  parm1:fullpath name of dir                                    //~v063I~
//*  parm2:udirlist of dir                                         //~v063I~
//*  parm3:curr dir level                                          //~v201I~
//*  rc   :0 continue walk,else stop walk by appl rc               //~v56fR~
//**********************************************************************//~v063I~
int udirwalksub(char *Pdir,PUDIRLIST Ppudirlist,int Plevel)        //~v201R~
{                                                                  //~v063I~
    int  ii,rc=0;                                                  //~v327R~
//  int  rc2;                                                      //~v56fR~
#if defined(W32)||defined(UNX)                                     //~va71I~//~v6k4I~
    int  rc2;                                                      //~v6k4I~
#endif                                                             //~v6k4I~
    int pathlen;    //len without last "\"                         //~v063I~
    int entryno=0,filectr=0,dirctr,sorttype;                           //~v063R~//~v6h7R~
    int attrmask;                                                  //~v063I~
    int level;                                                     //~v201I~
#ifdef UNX                                                         //~v57aI~
    int cdoksw=0;                                                  //~v579M~
#endif                                                             //~v57aI~
//  char fullpath[_MAX_PATH];                                      //~v56fR~
//  char fullpath[_MAX_PATH+64]; //for mask concat space           //~v56fI~//~v6H1R~
//  char fullpathw[_MAX_PATH];//filemask dir mask chkwk            //~v579R~//~v6H1R~
    char fullpath[_MAX_PATH2]; //for mask concat space _MAX_PATH*2 //~v6H1R~
    char fullpathw[_MAX_PATH2];//filemask dir mask chkwk           //~v6H1R~
    PUDIRLIST pudirlist,pudirlist0,pudirlists;                     //~v063R~
    PUDIRLIST pudirlist0s;                                         //~v579R~
#ifdef UNX                                                         //~v56pI~
//  int len;                                                       //~v56AR~
    int  rcudirlist=0;                                               //~v56pR~//~v6h9R~
    char curdir[_MAX_PATH];//cur dir to be restored                //~v57aM~
#endif                                                             //~v56pI~
//*******************************                                  //~v063I~
	UTRACEP("udirwalksub level=%d,Pdir=%s,dirmask=%s,filemask=%s\n",Plevel,Pdir,Sdirmask,Sfilemask);//~v6k4R~
    level=Plevel+1;                                                //~v201I~
    pathlen=(int)strlen(Pdir);                                     //~v063I~
    if ((level==1 &&  (!Sdirmask||!strcmp(Sdirmask,DIR_ALLMEMB)))	//top is not wildcard//~v6k4R~
    ||  (level==2 &&    Sdirmask&& strcmp(Sdirmask,DIR_ALLMEMB) ))  //top is wildcard//~v6k4R~
    {                                                              //~v6k4I~
    	Sstartdirlen=pathlen;                                      //~v6k4I~
        strcpy(Sstartdir,Pdir);                                    //~v6k4I~
		UTRACEP("udirwalksub startdir len=%d,dir=%s\n",Sstartdirlen,Sstartdir);//~v6k4I~
    }                                                              //~v6k4I~
    memcpy(fullpath,Pdir,(UINT)pathlen);    //with last "\" for root//~v063R~
//  if (*Ppudirlist->name!='\\') //not root dir                    //~v377R~
//      *(fullpath+pathlen++)='\\';                                //~v377R~
    if (*Ppudirlist->name!=DIR_SEPC) //not root dir                //~v377I~
        *(fullpath+pathlen++)=DIR_SEPC;                            //~v377I~
    *(fullpath+pathlen)=0;                                         //~v063I~
    sorttype=(Sopt & UDIRWALK_SORT_MASK);                          //~v063I~
    if (Sopt & UDIRWALK_SORT_REV) //reverse sort sw                //~v063I~
        sorttype=-sorttype;                                        //~v063I~
//for own dir                                                      //~v063I~
#ifdef UNX                                                         //~v57aI~
    if (Sopt & UDIRWALK_TEMPCD)//change dir opt                    //~v57aR~
    {                                                              //~v578I~
		ugetcwd(curdir);	//to be restored before each dirwalk   //~v57aI~
        if (strcmp(curdir,Pdir))  //not of current dir             //~v57aR~
			if (!uchdir(UCHD_NOMSG,Pdir))                          //~v57aR~
    	    	cdoksw=2;   //should be restore                    //~v57aR~
//printf("udirwalk1 curdir=%s,cdoksw=%d,errno=%d,-->%s\n",curdir,cdoksw,errno,Pdir);//~v57aR~
    }                                                              //~v578I~
    else                                                           //~v578I~
#endif                                                             //~v57aI~
    if (Sopt & UDIRWALK_CD)     //change dir opt                   //~v063R~
    {                                                              //~v578I~
//      uchdir(Pdir);   //change to the dir                        //~v579R~
#ifdef UNX                                                         //~v578I~
		if (!uchdir(0,Pdir))                                       //~v578I~
        	cdoksw=1;                                              //~v578I~
#else                                                              //~v578I~
        uchdir(0,Pdir);   //change to the dir                      //~v578R~
#endif                                                             //~v578I~
    }                                                              //~v578I~
    if (Sopt & UDIRWALK_DIRCALL)                                   //~v063I~
    {                                                              //~v063I~
        Scallctr++;                                                //~v063I~
//      if (rc=Sfunc(Pdir,0,Ppudirlist,Sdirlevel,Sdata,Sapplrc),rc)//~v201R~
        if (rc=Sfunc(Pdir,0,Ppudirlist,Plevel,Sdata,Sapplrc),rc)//by curr level//~v201I~
        {                                                          //~v56mI~
			if (rc==UDIRWALK_URC_SKIPDIR) //user requested skip this dir//~v56mI~
            	return 0;                                          //~v56mI~
            return rc;                                             //~v063I~
        }                                                          //~v56mI~
    }                                                              //~v063I~
//  Sdirlevel++;                                                   //~v201R~
//  if (Sdirlevel>Sstopdepth)                                      //~v201R~
    if (level>Sstopdepth)                                          //~v201I~
        return 0;                                                  //~v063I~
//for all file                                                     //~v063I~
	fullpathw[0]=0;                                                //~v579R~
    pudirlist0s=0;                                                 //~v579I~
    attrmask=(Sattrmask | FILE_DIRECTORY);  //also dir at once     //~v579R~
    if (Sopt & UDIRWALK_FILECALL)                                  //~v063I~
    {                                                              //~v063I~
//      attrmask=Sattrmask; //may contain dir                      //~v579R~
//        if (Sapplytopmask)                                       //~v56uR~
//        {                                                        //~v56uR~
//            if (Sapplytopmask & 4)  //dir mask applyed           //~v56uR~
//                strcpy(fullpath+pathlen,DIR_ALLMEMB);            //~v56uR~
//            else        //1st dir mask apply                     //~v56uR~
////              strcpy(fullpath+pathlen,Sdirmask);               //~v56uR~
//                strcpy(fullpath+pathlen,Sfilemask);              //~v56uR~
//            Sapplytopmask |= 4; //dir mask applyed               //~v56uR~
//        }                                                        //~v56uR~
//        else                                                     //~v56uR~
//printf("Sdirmask=%s\n",Sdirmask);                                //~v56uR~
//    if (!Sapplytopmask      //                                   //~v57aR~
//    ||  (Sapplytopmask & 4)  //not top level                     //~v57aR~
//    ||  !Sdirmask)           //no mask on dirname parm           //~v57aR~
//    {                                                            //~v57aR~
	  if ((Sapplytopmask & UDIRWALK_TOPMASK)	//apply dir mask to top level option//~v57aI~
	  &&  !(Sapplytopmask & 4))  //top level                       //~v57aI~
        strcpy(fullpath+pathlen,Sdirmask);                         //~v57aI~
      else                                                         //~v57aI~
        strcpy(fullpath+pathlen,Sfilemask);                        //~v063I~
	    strcpy(fullpathw,fullpath); //to compare with dir mask     //~v579R~
#ifdef UNX                                                         //~v578I~
		if (cdoksw)                                                //~v578I~
        	Gufile_opt|=GFILEOPT_STATCD;//issue stat by not fullpathname//~v578I~
#endif                                                             //~v578I~
      if (Sopt & UDIRWALK_NOMSG)    //no msg out req               //~v56bI~
        entryno=udirlistnomsg(fullpath,(UINT)attrmask,&pudirlist0,sorttype);//~v56bI~
      else                                                         //~v56bI~
        entryno=udirlist(fullpath,(UINT)attrmask,&pudirlist0,sorttype);//~v063R~
#ifdef UNX                                                         //~v578I~
     	Gufile_opt&=~GFILEOPT_STATCD;                              //~v578I~
		if (cdoksw==2)  //tempcd                                   //~v57aI~
			uchdir(UCHD_NOMSG,curdir);                             //~v57aR~
//printf("udirwalk1 back curdir=%s,chngsw=%d,errno=%d\n",curdir,cdoksw,errno);//~v57aR~
#endif                                                             //~v578I~
#ifdef UNX                                                         //~v56pM~
		rcudirlist=errno;	//to avoid double errmsg               //~v56pI~
#endif                                                             //~v56pM~
        if (entryno!=-1)    //list not created                     //~v063R~
        {                                                          //~v063I~
//apply for all file                                               //~v063I~
            for (ii=0,filectr=0,pudirlist=pudirlist0;ii<entryno;ii++,pudirlist++)//~v063R~
            {                                                      //~v063I~
//              pudirlist->srcattr&=~FILE_SLINKERR;                //~v6k4I~//~v6kcR~
//              pudirlist->workflag &= ~UDIRLWF_WALK_SLINKERR;     //~v6keI~//~v6D0R~
                pudirlist->workflag &= ~(ULONG)UDIRLWF_WALK_SLINKERR;//~v6D0I~
//              if (*pudirlist->name=='.')                         //~v194I~
                if (!strcmp(pudirlist->name,".")                   //~v194I~
                ||  !strcmp(pudirlist->name,".."))                 //~v194I~
                    continue;                                      //~v063I~
//#ifdef UNX                                                         //~v56tI~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
              	if (Sopt & UDIRWALK_SKIPSLINK  //skip slink        //~v56tI~
//            	&&  S_ISLNK(FILE_GETMODE(pudirlist->attr)))        //~v56tI~//~v6k4R~
              	&&  FILE_ISSLINK(pudirlist->attr))                 //~v6k4R~
                    continue;                                      //~v56tI~
#endif                                                             //~v56tI~
                if (pudirlist->attr & FILE_DIRECTORY)              //~v579I~
                {                                                  //~v6k4I~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
				  if (pudirlist->attr & FILE_SLINKERR)             //~v6keR~
                  	rc2=4;                                         //~v6keI~
                  else                                             //~v6keI~
//             		rc2=ufileslinkloopchk(0,Pdir,pudirlist->name,pudirlist->slink);//loop/dup chk//~v6k4R~//~v6qaR~
               		rc2=ufileslinkloopchk(0,Pdir,pudirlist->name,UDIRLIST_GET_SLINKNAME_OR_NULLSTR(pudirlist));//loop/dup chk//~v6qaR~
                    if (rc2)                                       //~v6k4I~
                    {                                              //~v6k4I~
//                      FILE_SETSLINKERR(pudirlist->srcattr);      //~v6k4R~
//                      pudirlist->srcattr|=FILE_SLINKERR;         //~v6k4I~//~v6keR~
                        pudirlist->workflag|=UDIRLWF_WALK_SLINKERR;//1 level loop chk//~v6keI~
			   			if (Sopt & UDIRWALK_LISTSLINKERR)     //change dir opt//~v6k4I~
               			{                                          //~v6k4I~
			                filectr++;                             //~v6k4I~
                			strcpy(fullpath+pathlen,pudirlist->name);//~v6k4I~
                			Scallctr++;                            //~v6k4I~
                			if (rc=Sfunc(Pdir,fullpath,pudirlist,level,Sdata,Sapplrc),rc)//by +1 level//~v6k4I~
                    		break;                                 //~v6k4I~
               			}                                          //~v6k4I~
                    }                                              //~v6k4I~
#endif                                                             //~v6k4I~
                    continue;                                      //~v579I~
                }                                                  //~v6k4I~
//            if ((strlen(pudirlist->name)+pathlen)>=_MAX_PATH)    //~v56fI~//~v6D0R~
              if (((int)strlen(pudirlist->name)+pathlen)>=_MAX_PATH)//~v6D0I~
              {                                                    //~v56fI~
                  uerrmsg("too long filename; %.*s%s",0,           //~v56fI~
                          pathlen,fullpath,pudirlist->name);       //~v56fI~
              }                                                    //~v56fI~
              else                                                 //~v56fI~
              {                                                    //~v56fI~
			  if (pudirlist->attr & FILE_SLINKERR)                 //~v6keR~
               	rc2=4;                                             //~v6keI~
              else                                                 //~v6keI~
//             rc2=ufileslinkloopchk(0,Pdir,pudirlist->name,pudirlist->slink);//loop/dup chk//~v6k4R~//~v6qaR~
               rc2=ufileslinkloopchk(0,Pdir,pudirlist->name,UDIRLIST_GET_SLINKNAME_OR_NULLSTR(pudirlist));//loop/dup chk//~v6qaR~
                if (rc2)                                           //~v6k4I~
               	{                                                  //~v6k4I~
//              	FILE_SETSLINKERR(pudirlist->srcattr);          //~v6k4R~
//                  pudirlist->srcattr|=FILE_SLINKERR;             //~v6k4I~//~v6keR~
                    pudirlist->workflag|=UDIRLWF_WALK_SLINKERR;    //~v6keI~
                   	if (Sopt & UDIRWALK_LISTSLINKERR)     //change dir opt//~v6k4R~
                   	{                                              //~v6k4R~
                    	rc2=0;  //call Sfunc by option             //~v6k4R~
                   	}                                              //~v6k4R~
                }                                                  //~v6k4I~
               if (!rc2)                                           //~v6k4I~
               {                                                   //~v6k4I~
                filectr++;                                         //~v063I~
                strcpy(fullpath+pathlen,pudirlist->name);          //~v063I~
                Scallctr++;                                        //~v063I~
//              if (rc=Sfunc(Pdir,fullpath,pudirlist,Sdirlevel,Sdata,Sapplrc),rc)//~v201R~
                if (rc=Sfunc(Pdir,fullpath,pudirlist,level,Sdata,Sapplrc),rc)//by +1 level//~v201I~
                    break;                                         //~v063I~
               }                                                   //~v6k4I~
              }                                                    //~v56fI~
            }//for all file                                        //~v063I~
//          ufree(pudirlist0);                                     //~v579R~
            if (rc)                                                //~v063I~
            {                                                      //~v579I~
//  	        ufree(pudirlist0);                                 //~v579I~//~v6qaR~
    	        UDIRLIST_FREE(pudirlist0);                         //~v6qaI~
                return rc;                                         //~v063I~
            }                                                      //~v579I~
            pudirlist0s=pudirlist0;	//reuse if avail               //~v579I~
        }                                                          //~v063I~
        if (entryno==-1 || !filectr)                               //~v063R~
            if (Sopt & UDIRWALK_EMPTYCALL                          //~v063I~
            &&  !(Sopt & UDIRWALK_DIRCALL)) //not called once      //~v063I~
            {                                                      //~v063I~
                Scallctr++;                                        //~v063I~
//              if (rc=Sfunc(Pdir,0,0,Sdirlevel-1,Sdata,Sapplrc),rc)//~v201R~
                if (rc=Sfunc(Pdir,0,0,Plevel,Sdata,Sapplrc),rc)    //~v201I~
                {                                                  //~v579I~
        			if (entryno!=-1)    //list not created         //~v579I~
//				        ufree(pudirlist0);                         //~v579I~//~v6qaR~
				        UDIRLIST_FREE(pudirlist0);                 //~v6qaI~
                    return rc;                                     //~v063I~
                }                                                  //~v579I~
            }                                                      //~v063I~
//    }//not the case wild card dir name and top level of xds(TOPMASK)//~v57aR~
      Sapplytopmask |= 4; //dir mask applyed                       //~v56uR~
    }//file call                                                   //~v063I~
//create subdir list                                               //~v063I~
//  attrmask=(Sattrmask | FILE_DIRECTORY);                         //~v579R~
//  if (Sapplytopmask)                                             //~v57aR~
    if (Sapplytopmask & UDIRWALK_TOPMASK)	//apply dir mask to top level option//~v57aR~
    {                                                              //~v528I~
		if (Sapplytopmask & 2)	//dir mask applyed                 //~v528I~
	    	strcpy(fullpath+pathlen,DIR_ALLMEMB);                  //~v528I~
        else		//1st dir mask apply                           //~v528I~
		    strcpy(fullpath+pathlen,Sdirmask);                     //~v528I~
		Sapplytopmask |= 2;	//dir mask applyed                     //~v528I~
    }                                                              //~v528I~
    else                                                           //~v528I~
    strcpy(fullpath+pathlen,Sdirmask);                             //~v063I~
#ifdef UNX                                                         //~v56pI~
 if (rcudirlist==EACCES)	//find 1st permission err              //~v56rR~
    	entryno=-1;                                                //~v56pI~
 else                                                              //~v56pI~
 {                                                                 //~v578I~
#endif                                                             //~v56pI~
  if (!strcmp(fullpathw,fullpath))//same as prev udirlist          //~v579I~
  {                                                                //~v579I~
 	pudirlist0=pudirlist0s;                                        //~v579I~
  }                                                                //~v579I~
  else                                                             //~v579I~
  {                                                                //~v579I~
    if (pudirlist0s)                                               //~v579I~
//    	ufree(pudirlist0s);                                        //~v579R~//~v6qaR~
    	UDIRLIST_FREE(pudirlist0s);                                //~v6qaI~
#ifdef UNX                                                         //~v578I~
	if (cdoksw)                                                    //~v578I~
    {                                                              //~v57aI~
        if (cdoksw==2)                                             //~v57aM~
			if (!uchdir(UCHD_NOMSG,Pdir))                          //~v57aM~
        		cdoksw=0;   //should be restore                    //~v57aM~
      if (cdoksw)                                                  //~v57aI~
    	Gufile_opt|=GFILEOPT_STATCD;                               //~v578I~
    }                                                              //~v57aI~
#endif                                                             //~v578I~
  if (Sopt & UDIRWALK_NOMSG)    //no msg out req                   //~v56bI~
    entryno=udirlistnomsg(fullpath,(UINT)attrmask,&pudirlist0,sorttype);//~v56bI~
  else                                                             //~v56bI~
    entryno=udirlist(fullpath,(UINT)attrmask,&pudirlist0,sorttype);//~v063R~
#ifdef UNX                                                         //~v578I~
     	Gufile_opt&=~GFILEOPT_STATCD;                              //~v578I~
        if (cdoksw==2)                                             //~v57aI~
			uchdir(UCHD_NOMSG,curdir);                             //~v57aI~
//printf("udirwalk2 curdir=%s,chngsw=%d,-->%s\n",curdir,cdoksw,Pdir);//~v57aR~
#endif                                                             //~v578I~
  }                                                                //~v579I~
#ifdef UNX                                                         //~v578I~
 }                                                                 //~v578I~
#endif                                                             //~v578I~
//  printf("dir entryno=%d,fullpath=%s\n",entryno,fullpath);       //~v063R~
    if (entryno!=-1)    //list created                             //~v063R~
    {                                                              //~v063I~
        for (ii=0,dirctr=0,pudirlist=pudirlist0;ii<entryno;ii++,pudirlist++)//~v063R~
        {                                                          //~v063I~
//  printf("dir filectr=%d,name=%s\n",ii,pudirlist->name);         //~v063R~
//          if ((*pudirlist->name=='.')                            //~v194I~
            if (!strcmp(pudirlist->name,".")                       //~v194I~
            ||  !strcmp(pudirlist->name,"..")                      //~v194I~
            ||  !(pudirlist->attr & FILE_DIRECTORY))               //~v063I~
                continue;                                          //~v063I~
            dirctr++;                                              //~v063I~
        }//for all subdir                                          //~v063I~
//  printf("dir ctr=%d\n",dirctr);                                 //~v063R~
        rc=0;   //for the case dirctr=0;                           //~v569I~
        if (dirctr)                                                //~v063I~
        {                                                          //~v063I~
//reduce table size for recursive call                             //~v063I~
//          pudirlists=umalloc((UINT)(dirctr*sizeof(UDIRLIST)));   //~v063R~//~v6qaR~
//          pudirlists=UALLOCC(1,(UINT)((dirctr+1)*UDIRLISTSZ));	//clear//~v6qaI~//~v6D0R~
            pudirlists=UALLOCC(1,(((size_t)dirctr+1)*UDIRLISTSZ));	//clear//~v6D0I~
            for (ii=0,dirctr=0,pudirlist=pudirlist0;ii<entryno;ii++,pudirlist++)//~v063R~
            {                                                      //~v063I~
//#ifdef UNX                                                         //~v56tI~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
              	if (Sopt & UDIRWALK_SKIPSLINK  //skip slink        //~v56tI~
//            	&&  S_ISLNK(FILE_GETMODE(pudirlist->attr)))        //~v56tI~//~v6k4R~
              	&&  FILE_ISSLINK(pudirlist->attr))                 //~v6k4R~
                    continue;               //skip slink           //~v56tI~
#endif                                                             //~v56tI~
//              if ((*pudirlist->name=='.')                        //~v194I~
                if (!strcmp(pudirlist->name,".")                   //~v194I~
                ||  !strcmp(pudirlist->name,"..")                  //~v194I~
                ||  !(pudirlist->attr & FILE_DIRECTORY))           //~v063I~
                    continue;                                      //~v063I~
//              if (FILE_ISSLINKERR(pudirlist->srcattr))           //~v6k4R~
//              if (pudirlist->srcattr & FILE_SLINKERR)            //~v6k4I~//~v6keR~
                if (pudirlist->workflag & UDIRLWF_WALK_SLINKERR)   //~v6keI~
                {                                                  //~v6k4I~
//	                pudirlist->srcattr&=~FILE_SLINKERR;            //~v6k4I~//~v6kcR~
                    continue;                                      //~v6k4I~
                }                                                  //~v6k4I~
//              *(pudirlists+dirctr++)=*pudirlist;                 //~v063I~//~v6qaR~
//              UDIRLIST_COPY((pudirlists+dirctr++),pudirlist);	//pslink of from-pudl point to dummy//~v6qaI~//~v6uCR~
//              UDIRLIST_COPY_NEW_SLINKNAME((pudirlists+dirctr++),pudirlist);	//pslink of from-pudl point to dummy//~v6uCR~//+v6J0R~
                UDIRLIST_COPY((pudirlists+dirctr++),pudirlist);	//pslink of from-pudl point to dummy//+v6J0I~
            }//for all subdir                                      //~v063I~
//          ufree(pudirlist0);                                     //~v063I~//~v6qaR~
            UDIRLIST_FREE(pudirlist0);                             //~v6qaI~
            pudirlist0=pudirlists;                                 //~v063I~
//  printf("dir ctr2=%d\n",dirctr);                                //~v063R~
            entryno=dirctr;                                        //~v063R~
//apply to subdir                                                  //~v063I~
            for (ii=0,pudirlist=pudirlist0;ii<entryno;ii++,pudirlist++)//~v063R~
            {                                                      //~v063I~
//            if ((strlen(pudirlist->name)+pathlen)>=_MAX_PATH)    //~v56eR~//~v6D0R~
              if (((int)strlen(pudirlist->name)+pathlen)>=_MAX_PATH)//~v6D0I~
              {                                                    //~v56eI~
                  	uerrmsg("too long filename; %.*s%s",0,         //~v56eR~
                          pathlen,fullpath,pudirlist->name);       //~v56eR~
//#ifdef UNX                                                       //~v56fR~
//                    rc2=ENAMETOOLONG;                            //~v56fR~
//#else                                                            //~v56fR~
//    #ifdef DOS                                                   //~v56fR~
//        #ifdef DPMI                                              //~v56fR~
//                    rc2=ENAMETOOLONG;                            //~v56fR~
//        #else                                                    //~v56fR~
//                    rc2=E2BIG;                                   //~v56fR~
//        #endif                                                   //~v56fR~
//    #else                                                        //~v56fR~
//        #ifdef W32                                               //~v56fR~
//                    rc2=ENAMETOOLONG;                            //~v56fR~
//        #else       //os/2                                       //~v56fR~
//                    rc2=EBADNAME;                                //~v56fR~
//        #endif                                                   //~v56fR~
//    #endif                                                       //~v56fR~
//#endif  //UNX                                                    //~v56fR~
              }                                                    //~v56eI~
              else                                                 //~v56eI~
              {                                                    //~v56eI~
                strcpy(fullpath+pathlen,pudirlist->name);          //~v063I~
//#ifdef UNX                                                         //~v56qI~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
//               if (!strcmp(pudirlist->slink,".")  //             //~v56AR~
//               ||  !strcmp(pudirlist->slink,"..")  //            //~v56AR~
////             ||  (*pudirlist->slink==DIR_SEPC && strstr(fullpath,pudirlist->slink))) //slink loop(source path is upper level of target)//~v56AR~
//               ||  (*pudirlist->slink==DIR_SEPC                  //~v56AR~
//                    && (len=(int)strlen(pudirlist->slink),       //~v56AR~
//                        memcmp(fullpath,pudirlist->slink,(UINT)len)==0)//~v56AR~
//                    && (*(fullpath+len)==DIR_SEPC||!*(fullpath+len))))//~v56AR~
//               {                                                 //~v56AR~
//                  uerrmsg("Skipped by S-Link loop;(%s --> %s)",0,//~v56AR~
//                              fullpath,pudirlist->slink);        //~v56AR~
//               }                                                 //~v56AR~
//               else                                              //~v56AR~
//           if (!ufileslinkchk(Pdir,pudirlist->name,pudirlist->slink))//loop chk//~v56AR~//~v6k4R~
//          	rc2=ufileslinkchk(Pdir,pudirlist->name,pudirlist->slink);//loop,dup chk//~v6k4R~
//           if (!rc2)                                             //~v6k4R~
//           {                                                     //~v59xI~//~v6k4R~
//  		   if (S_ISLNK(FILE_GETMODE(pudirlist->attr))//symbolic link//~v56rI~//~v6k4R~
    		   if (FILE_ISSLINK(pudirlist->attr)//symbolic link    //~v6k4R~
//  		   &&  !*pudirlist->slink)	//readlink failed          //~v56rI~//~v6qaR~
    		   &&  (pudirlist->pslink || !*pudirlist->pslink))	//readlink failed//~v6qaR~
               		;	//skip                                     //~v56rI~
               else                                                //~v56qI~
               {                                                   //~v56qI~
#endif                                                             //~v56qI~
//              if (rc=udirwalksub(fullpath,pudirlist),rc)         //~v201R~
//              if (rc=udirwalksub(fullpath,pudirlist,level),rc)   //~v56dR~
//                  break;                                         //~v56dR~
//              rc2=udirwalksub(fullpath,pudirlist,level);         //~v56fR~
#ifdef W32                                                         //~v6q1I~
				if (FILE_IS_WILDNAME(pudirlist->attr))	//alias for wildname dir//~v6q1I~
                {                                                  //~v6q1I~
	              	if (Sopt & UDIRWALK_DIGBYALIAS)  //skip slink  //~v6q1R~
		                strcpy(fullpath+pathlen,pudirlist->alias); //~v6q1I~
                }                                                  //~v6q1I~
#endif                                                             //~v6q1I~
                if (rc=udirwalksub(fullpath,pudirlist,level),rc)   //~v56fI~
                    break;                                         //~v56fI~
//#ifdef UNX                                                         //~v56qI~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
               }//slink loop chk                                   //~v56qI~
//           }//slinkchk                                           //~v59xM~//~v6k4R~
#endif                                                             //~v56qI~
              }                                                    //~v56eI~
//                if (rc2)                                         //~v56fR~
//                    if (!rc)                                     //~v56fR~
//                        rc=rc2; //continue process               //~v56fR~
            }//for all subdir                                      //~v063I~
//          ufree(pudirlist0);                                     //~v569R~
//          if (rc)                                                //~v569R~
//              return rc;                                         //~v569R~
        }//dir exist                                               //~v063I~
//      ufree(pudirlist0);                                         //~v569I~//~v6qaR~
        UDIRLIST_FREE(pudirlist0);                                 //~v6qaI~
        if (rc)                                                    //~v569I~
            return rc;                                             //~v569I~
    }//list created                                                //~v063I~
    if (Sopt & UDIRWALK_EOLCALL)                                   //~v201R~
//      if (rc=Sfunc(Pdir,(char*)(-1),0,Plevel,Sdata,Sapplrc),rc)//by curr level//~v201R~//~v6h9R~
        if (rc=Sfunc(Pdir,(char*)(ULPTR)(-1),0,Plevel,Sdata,Sapplrc),rc)//by curr level//~v6h9I~
            return rc;                                             //~v201R~
    return 0;                                                      //~v063I~
}//dirwalksub                                                      //~v063I~
                                                                   //~v083I~
//#ifdef UNX                                                         //~v327I~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
//*******************************************************          //~v6kfR~
//*relative link chk                                               //~v6kfR~
//*ret   :rc: relative in the dir,1:absolute,2:invalid relative name  4:may loose linkage//~v6kfR~
//*******************************************************          //~v6kfR~
//int ufileslinkoutoflinkchk(int Popt,char *Pstartdir,char *Pfnm,char *Pslink)//~v6kpR~
//int ufileslinkoutoflinkchk(int Popt,char *Pstartdir,char *Pfnm,char *Pslink,char *Pdest)//~v6kpR~
int ufileslinkoutoflinkchk(int Popt,char *Pstartdir,char *Pfnm,char *Pslink,char *Pdest,UINT Psattr)//~v6kpI~
{                                                                  //~v6kfR~
    int rc=0,len,len1,len2,pathlen;                                //~v6kfR~
//    int pathlendest,swupward;                                    //~v6krR~
//    char *pc;                                                    //~v6krR~
    int len0;                                                      //~v6krI~
    char fpathwk[_MAX_PATH];                                       //~v6kfR~
    char fpathwkdest[_MAX_PATH];                                   //~v6krI~
//  char fnmwk[_MAX_PATH];                                         //~v6kfR~//~v6H1R~
    char fnmwk[_MAX_PATH2];                                        //~v6H1R~
//*******************                                              //~v6kfR~
    UTRACEP("ufileslinkoutoflinkchk startdir=%s,srcfnm=%s,slink=%s,sattr=%x,dest=%s\n",Pstartdir,Pfnm,Pslink,Psattr,Pdest);//~v6krR~
    if (!*Pslink)                                                  //~v6kfR~
        return 2;                                                  //~v6kfR~
#ifdef W32                                                         //~v6kpI~
    if (!FILE_MODEISNTFS_SLINK(Psattr))                            //~v6kpI~
    {                                                              //~v6kpI~
	    UTRACEP("ufileslinkoutoflinkchk rc=1 by not SLINK\n");     //~v6kpR~
        return 1;                                                  //~v6kpI~
    }                                                              //~v6kpI~
#endif                                                             //~v6kpI~
#ifdef W32                                                         //~v6kfR~
    if (strlen(Pslink)>=3 && *(Pslink+1)==':'&& *(Pslink+2)==DIR_SEPC)  //from drive root//~v6kfR~
#else                                                              //~v6kfR~
    if (*Pslink==DIR_SEPC)                                         //~v6kfR~
#endif                                                             //~v6kfR~
	{                                                              //~v6krI~
	    UTRACEP("ufileslinkoutoflinkchk rc=1 by not fullpath slink\n");//~v6krI~
        return 1;                                                  //~v6kfR~
    }                                                              //~v6krI~
    len=(int)strlen(Pfnm);                                         //~v6kfR~
    UmemcpyZ(fnmwk,Pfnm,(UINT)len);                                //~v6kfR~
    pathlen=PATHLEN(fnmwk);                                        //~v6kfR~
    if (pathlen>0)                                                 //~v6kfR~
        len=pathlen;                                               //~v6kfR~
    if (!(len>1 && *(fnmwk+len-1)==DIR_SEPC))                      //~v6krR~
        *(fnmwk+len++)=DIR_SEPC;                                   //~v6kfR~
#ifdef AAA                                                         //~v6krI~
    pathlendest=PATHLEN(Pdest);                                    //~v6kpI~
    swupward=0;                                                    //~v6kpI~
    for (pc=Pslink;;)                                              //~v6kfI~
    {                                                              //~v6kfI~
    	if (USTRHEADIS(pc,".." DIR_SEPS))                          //~v6kfI~
        {                                                          //~v6kfI~
        	swupward=1;                                            //~v6kpI~
            pc+=3;                                                 //~v6kfI~
            continue;                                              //~v6kfI~
        }                                                          //~v6kfI~
    	if (USTRHEADIS(pc,"." DIR_SEPS))                           //~v6kfI~
        {                                                          //~v6kfI~
            pc+=2;                                                 //~v6kfI~
            continue;                                              //~v6kfI~
        }                                                          //~v6kfI~
        break;                                                     //~v6kfI~
    }                                                              //~v6kfI~
  if (!swupward                                                    //~v6kpI~
  &&   pathlen==pathlendest	//into same dir                        //~v6kpI~
  &&  !LFNM_MEMCMP(fnmwk,Pdest,pathlendest))                       //~v6kpI~
  	UTRACEP("outoflinkchk tgt is same dir pathlen=%d,src=%s,dest=%s\n",pathlendest,fnmwk,Pdest);//~v6kpI~
  else                                                             //~v6kpI~
  {                                                                //~v6kpI~
    len2=PTRDIFF(pc,Pslink);                                       //~v6kfR~
    UmemcpyZ(fnmwk+len,Pslink,len2);                               //~v6kfR~
    UTRACEP("ufileslinkoutoflinkchk relpath=%s\n",fnmwk);          //~v6kfI~
    if (!ufullpath(fpathwk,fnmwk,sizeof(fpathwk)))    //err        //~v6kfR~
        return  2;                                                 //~v6kfR~
    len1=strlen(Pstartdir);                                        //~v6kfR~
    if (*(Pstartdir+len1-1)==DIR_SEPC)                             //~v6kfR~
        len1--;                                                    //~v6kfR~
    len2=strlen(fpathwk);   //slink target up                      //~v6kfR~
    if (len2<len1)     //out of start path                         //~v6kfR~
        rc=4;   //link to out of startdir                          //~v6kfR~
  }                                                                //~v6kpI~
#else                                                              //~v6krI~
//  UstrncpyZ(fnmwk+len,Pslink,_MAX_PATH-len);                     //~v6krI~//~v6D0R~
    UstrncpyZ(fnmwk+len,Pslink,(size_t)(_MAX_PATH-len));           //~v6D0I~
    if (!ufullpath(fpathwk,fnmwk,sizeof(fpathwk)))    //srcfullpath//~v6krI~
        return  2;                                                 //~v6krI~
    for (;;)                                                       //~v6krI~
    {                                                              //~v6krI~
//      len1=strlen(fpathwk);   //src target fpath                 //~v6krI~//~v6D0R~
        len1=(int)strlen(fpathwk);   //src target fpath            //~v6D0I~
//      len0=strlen(Pstartdir);                                    //~v6krI~//~v6D0R~
        len0=(int)strlen(Pstartdir);                               //~v6D0I~
        if (len0<len1                                              //~v6krI~
//      && !LFNM_MEMCMP(fpathwk,Pstartdir,len0)                    //~v6krR~//~v6D0R~
        && !LFNM_MEMCMP(fpathwk,Pstartdir,(size_t)len0)            //~v6D0I~
        && *(fpathwk+len0)==DIR_SEPC)   //slink target is under copy source top dir//~v6krI~
        {                                                          //~v6krI~
            UTRACEP("src slink target will be also copied,srctgt=%s\n",fpathwk);//~v6krR~
            break;                                                 //~v6krI~
        }                                                          //~v6krI~
        len=(int)strlen(Pdest);                                    //~v6krR~
        UmemcpyZ(fnmwk,Pdest,(UINT)len);                           //~v6krR~
        pathlen=PATHLEN(fnmwk);                                    //~v6krR~
        if (pathlen>0)                                             //~v6krR~
            len=pathlen;                                           //~v6krR~
        if (!(len>1 && *(fnmwk+len-1)==DIR_SEPC))                  //~v6krR~
            *(fnmwk+len++)=DIR_SEPC;                               //~v6krR~
//      UstrncpyZ(fnmwk+len,Pslink,_MAX_PATH-len);                 //~v6krR~//~v6D0R~
        UstrncpyZ(fnmwk+len,Pslink,(size_t)(_MAX_PATH-len));       //~v6D0I~
        if (!ufullpath(fpathwkdest,fnmwk,sizeof(fpathwkdest)))    //srcfullpath//~v6krR~
            return  2;                                             //~v6krR~
//      len2=strlen(fpathwkdest);                                  //~v6krR~//~v6D0R~
        len2=(int)strlen(fpathwkdest);                             //~v6D0I~
        if (len1!=len2                                             //~v6krR~
//      ||  LFNM_MEMCMP(fpathwk,fpathwkdest,len1))                 //~v6krR~//~v6D0R~
        ||  LFNM_MEMCMP(fpathwk,fpathwkdest,(size_t)len1))         //~v6D0I~
            rc=4;                                                  //~v6krR~
        UTRACEP("ufileslinkoutoflinkchk rc=%d,srclink=%s,tgtlink=%s\n",rc,fpathwk,fpathwkdest);//~v6krR~
        break;                                                     //~v6krI~
    }                                                              //~v6krI~
#endif                                                             //~v6krI~
    if (rc==4)                                                     //~v6kfR~
        if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))                //~v6kfR~
            uerrmsg("Relative symlink may be invalid after copy(%s-->%s)",//~v6kfR~
                    "相対指定のsymlinkは無効になる可\x94\\性があります(%s-->%s)",//~v6kfR~
                      Pfnm,Pslink);                                //~v6kfR~
    return rc;                                                     //~v6kfR~
}//ufileslinkoutoflinkchk                                          //~v6kfR~
//*******************************************************          //~v56AR~
//*slink loop chk                                                  //~v6k4R~
//*parm 1:dir name                                                 //~v56AR~
//*parm 2:dir member                                               //~v56AR~
//*parm 3:slink to                                                 //~v56AR~
//*ret   :rc: 0(OK)  4:loop detected, 8: target is contained in the start dir                               //~v56AR~//~v6k4R~
//*******************************************************          //~v56AR~
//int ufileslinkchk(char *Pdir,char *Pmember,char *Pslink)           //~v56AR~//~v6k4R~
int ufileslinkloopchk(int Popt,char *Pdir,char *Pmember,char *Pslink)//~v6k4I~
{                                                                  //~v56AR~
	int rc=0,len;                                                  //~v56AR~
    char *path,*pfpathslink,*psep;                                 //~v6k4R~
//  char fpathwk[_MAX_PATH];                                       //~v56AR~//~v6H1R~
    char fpathwk[_MAX_PATH2];                                      //~v6H1R~
//  char dirnm[_MAX_PATH];                                         //~v56AR~//~v6H1R~
    char dirnm[_MAX_PATH2];                                        //~v6H1R~
#ifdef AAA                                                         //~v6k4I~
	FILEFINDBUF3 ffb3;                                             //~v56AR~
#endif  //AAA                                                      //~v6k4I~
//*******************                                              //~v56AR~
    if (!*Pslink)                                                  //~v56AR~
        return 0;                                                  //~v56AR~
#ifdef AAA                                                         //~v6k4I~
    len=(int)strlen(Pdir);                                         //~v56AR~
    memcpy(dirnm,Pdir,(UINT)len);                                  //~v56AR~
    if (len>1 && *(Pdir+len-1)==DIR_SEPC)                          //~v56AR~
    	*(dirnm+len-1)=0;                                          //~v56AR~
    else                                                           //~v56AR~
    	*(dirnm+len)=0;                                            //~v56AR~
	if (!strcmp(Pslink,".")  //                                    //~v56AR~
    ||  !strcmp(Pslink,"..")  //                                   //~v56AR~
    ||  !strcmp(Pslink,DIR_SEPS))  //root                          //~v56AR~
//* ".":repeat myself,"..":repeat from parent,"/" repeat from root //~v6k4I~
    	rc=4;	                                                   //~v56AR~
    else                                                           //~v56AR~
    if (*Pslink==DIR_SEPC)                                         //~v56AR~
    {                                                              //~v56AR~
//*fullpath slink                                                  //~v6k4I~
    	len=strlen(Pmember);                                       //~v56AR~
		for (path=dirnm;path=strstr(path,Pmember),path;path+=len)  //~v56AR~
    	{                                                          //~v56AR~
        	if (*(path-1)!=DIR_SEPC || *(path+len)!=DIR_SEPC)	//full match?//~v56AR~
            	continue;                                          //~v56AR~
            memcpy(fpathwk,dirnm,(ULONG)path-(ULONG)dirnm+len);    //~v56AR~
            *(fpathwk+(ULONG)path-(ULONG)dirnm+len)=0;             //~v56AR~
			if (ufstat(fpathwk,&ffb3))                             //~v56AR~
            	continue;                                          //~v56AR~
            if (*ffb3.slink && !strcmp(ffb3.slink,Pslink))	//match//~v56AR~
            {	                                                   //~v56AR~
//*same dirname may occur but loop if slink is also same           //~v6k4I~
            	rc=4;	//loop                                     //~v56AR~
                break;                                             //~v56AR~
            }                                                      //~v56AR~
        }                                                          //~v56AR~
    }                                                              //~v56AR~
    if (rc)                                                        //~v56AR~
      if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))                  //~v573I~
    	uerrmsg("Skipped by S-Link loop;(%s/%s --> %s)",0,         //~v56AR~
                      dirnm,Pmember,Pslink);                       //~v56AR~
#endif  //AAA                                                      //~v6k4I~
#ifdef W32                                                         //~v6k4I~
    if (strlen(Pslink)>=3 && *(Pslink+1)==':'&& *(Pslink+2)==DIR_SEPC)	//from drive root//~v6k4R~
#else                                                              //~v6k4I~
    if (*Pslink==DIR_SEPC)                                         //~v6k4I~
#endif                                                             //~v6k4I~
	{                                                              //~v6k4I~
        path=Pslink;                                               //~v6k4I~
    }                                                              //~v6k4I~
    else                                                           //~v6k4I~
    {                                                              //~v6k4I~
    	len=(int)strlen(Pdir);                                     //~v6k4I~
    	memcpy(dirnm,Pdir,(UINT)len);                              //~v6k4I~
    	if (!(len>1 && *(Pdir+len-1)==DIR_SEPC))                   //~v6k4I~
    		*(dirnm+len++)=DIR_SEPC;                               //~v6k4I~
	    strcpy(dirnm+len,Pslink);                                  //~v6k4R~
        path=dirnm;                                                //~v6k4R~
    }                                                              //~v6k4I~
    if (!ufullpath(fpathwk,path,sizeof(fpathwk)))    //err         //~v6k4I~
        return  0;  //continue dirwalk                             //~v6k4I~
//  len=strlen(fpathwk);	//slink target fpath                   //~v6k4I~//~v6D0R~
    len=(int)strlen(fpathwk);	//slink target fpath               //~v6D0I~
    if (len==Sstartdirlen)	//maybe slink to high level            //~v6k4R~
    {                                                              //~v6k4I~
//  	if (!LFNM_MEMCMP(Sstartdir,fpathwk,len))//slink path is part of startdir//~v6k4R~//~v6D0R~
    	if (!LFNM_MEMCMP(Sstartdir,fpathwk,(size_t)len))//slink path is part of startdir//~v6D0I~
        	rc=4;	//loop detected                                //~v6k4I~
    }                                                              //~v6k4I~
    else      //slink target may be under the startdir             //~v6k4I~
    if (len<Sstartdirlen)	//maybe slink to high level            //~v6k4I~
    {                                                              //~v6k4I~
//  	if (!LFNM_MEMCMP(Sstartdir,fpathwk,len) //slink path is part of startdir//~v6k4I~//~v6D0R~
    	if (!LFNM_MEMCMP(Sstartdir,fpathwk,(size_t)len) //slink path is part of startdir//~v6D0I~
        &&  (ROOTDIR_LOCAL(fpathwk)||*(Sstartdir+len)==DIR_SEPC)         //recursive//~v6k4I~
        )                                                          //~v6k4I~
        	rc=4;	//loop detected                                //~v6k4I~
    }                                                              //~v6k4I~
    else      //slink target may be under the startdir             //~v6k4I~
    {                                                              //~v6k4I~
//  	if (!LFNM_MEMCMP(Sstartdir,fpathwk,Sstartdirlen) //slink target is under the start dir//~v6k4I~//~v6D0R~
    	if (!LFNM_MEMCMP(Sstartdir,fpathwk,(size_t)Sstartdirlen) //slink target is under the start dir//~v6D0I~
        &&   *(fpathwk+Sstartdirlen)==DIR_SEPC)        //duplicated walk//~v6k4I~
        	rc=8;	//no need to walk                              //~v6k4I~
    }                                                              //~v6k4I~
    if (rc)                                                        //~v6k4I~
    {                                                              //~v6k4I~
      	if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))                //~v6k4I~
      	{                                                          //~v6k4I~
            if (strcmp(fpathwk,Pslink))                            //~v6k4I~
            {                                                      //~v6k4I~
                pfpathslink=fpathwk;                               //~v6k4I~
                psep="=";                                          //~v6k4I~
            }                                                      //~v6k4I~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
                pfpathslink="";                                    //~v6k4I~
                psep="";                                           //~v6k4I~
            }                                                      //~v6k4I~
        	if (rc==4)                                             //~v6k4I~
//  			uerrmsg("Symbolic Link loop;(%s%c%s --> %s%s%s)",  //~v6k4R~//~v6r5R~
    			uerrmsg("Symbolic Link loop;(%s%s%s --> %s%s%s)",  //~v6r5I~
                        "リンクループ(%s%s%s --> %s%s%s)",         //~v6k4R~
                	      Pdir,(*Pmember?DIR_SEPS:""),Pmember,Pslink,psep,pfpathslink);//~v6k4R~
            else                                                   //~v6k4I~
            {                                                      //~v6k4I~
			  if (!(Popt & UFSLCO_NODUPMSG)) //bypass to issue duplicated err msg//~v6k4I~
//  			uerrmsg("Symbolic Link duplicated(%s%c%s --> %s%s%s)",//~v6k4R~//~v6r5R~
    			uerrmsg("Symbolic Link duplicated(%s%s%s --> %s%s%s)",//~v6r5I~
                        "リンク重複(%s%s%s --> %s%s%s)",           //~v6k4R~
                	      Pdir,(*Pmember?DIR_SEPS:""),Pmember,Pslink,psep,pfpathslink);//~v6k4R~
            }                                                      //~v6k4I~
    	}                                                          //~v6k4I~
    }                                                              //~v6k4I~
    UTRACEP("ufileslinkloopchk slink rc=%d,fpath=%s,startdir=%s\n",rc,fpathwk,Sstartdir);//~v6k4R~
    return rc;                                                     //~v56AR~
}//ufileslinkloopchk                                                   //~v56AR~//~v6k4R~
//*******************************************************          //~v6k4I~
//*startdir is parm                                                //~v6k4R~
//*******************************************************          //~v6k4I~
int ufileslinkloopchk2(int Popt,char *Pstartdir,char *Pdir,char *Pmember,char *Pslink)//~v6k4R~
{                                                                  //~v6k4I~
	int savedirlen,rc;                                             //~v6k4R~
    char savedir[_MAX_PATH];                                       //~v6k4R~
//******************************                                   //~v6k4I~
	strcpy(savedir,Sstartdir); savedirlen=Sstartdirlen;            //~v6k4R~
    strcpy(Sstartdir,Pstartdir);                                   //~v6k4R~
//  Sstartdirlen=strlen(Pstartdir);                                //~v6k4I~//~v6D0R~
    Sstartdirlen=(int)strlen(Pstartdir);                           //~v6D0I~
	rc=ufileslinkloopchk(Popt,Pdir,Pmember,Pslink);                //~v6k4R~
    strcpy(Sstartdir,savedir); Sstartdirlen=savedirlen;            //~v6k4R~
    UTRACEP("ufileslinkloopchk2 rc=%d,startdir=%s,curdir=%s,curmemb=%s,curslink=%s\n",rc,Pstartdir,Pdir,Pmember,Pslink);//~v6k4I~
    return rc;                                                     //~v6k4I~
}                                                                  //~v6k4I~
#endif //W32||UNX                                                  //~v6k4I~
#ifdef UNX                                                         //~v6k4I~
//*******************************************************          //~v327I~
//*ugetdiskfree:return file system info of the pathname            //~v327I~
//*parm 1:pathname,0 for curr dir                                  //~v327R~
//*parm 2:output dispspace structure                               //~v327I~
//*ret   :rc: 0(OK)  or else ERR(errno or APIRET)                  //~v327I~
//*******************************************************          //~v327I~
unsigned int ugetdiskfree(char *Pfname,UDISKINFO *Pudiskinfo)      //~v327I~
{                                                                  //~v327I~
    struct statfs sfs;                                             //~v327I~
//  unsigned int rc;                                               //~v327I~//~v6D0R~
    int rc;                                                        //~v6D0I~
    UCHAR *pfn;                                                    //~v327R~
//*******************                                              //~v327I~
    memset(Pudiskinfo,0,sizeof(UDISKINFO)); //clear for err        //~v327I~
    if (!(pfn=Pfname))                                             //~v327I~
    	pfn="./";		//current dir                              //~v327I~
//  if (statfs(pfn,&sfs))                                          //~v50GI~
    if (MDOSDISKOK(pfn))                                           //~v50GI~
    {                                                              //~v50GI~
        rc=ustatfs_mdos(pfn,&sfs);                                 //~v50GI~
        errno=rc;                                                  //~v50GI~
    }                                                              //~v50GI~
    else                                                           //~v50GI~
    	rc=statfs(pfn,&sfs);                                       //~v50GR~
    if (rc)                                                        //~v50GI~
    {                                                              //~v327I~
    	rc=errno;                                                  //~v327I~
        switch(rc)                                                 //~v327I~
        {                                                          //~v327I~
        case ENOENT:                                               //~v327I~
        case ENOTDIR:                                              //~v327I~
//          return ufilenotfound(pfn,rc);                          //~v327R~//~v6D0R~
            return (unsigned)ufilenotfound(pfn,rc);                //~v6D0I~
        }                                                          //~v327I~
//      return rc;                                                 //~v327I~//~v6D0R~
        return (unsigned)rc;                                       //~v6D0I~
    }                                                              //~v327I~
//  Pudiskinfo->total_clusters=sfs.f_blocks;    //total block cnt  //~v327I~//~v6D0R~
    Pudiskinfo->total_clusters=(FILESZT)sfs.f_blocks;    //total block cnt//~v6D0I~
//  Pudiskinfo->avail_clusters=sfs.f_bfree;     //not assigned block cnt//~v327R~
//  Pudiskinfo->avail_clusters=sfs.f_bavail;    //avail block cnt for non prev user//~v327I~//~v6D0R~
    Pudiskinfo->avail_clusters=(FILESZT)sfs.f_bavail;    //avail block cnt for non prev user//~v6D0I~
    Pudiskinfo->sectors_per_cluster=1;          //no cluster       //~v327I~
//  Pudiskinfo->bytes_per_sector=sfs.f_bsize;   //block size       //~v327I~//~v6D0R~
    Pudiskinfo->bytes_per_sector=(unsigned)sfs.f_bsize;   //block size//~v6D0I~
    Pudiskinfo->filesystemid=sfs.f_fsid;  		//filesystemid     //~v348I~
    return 0;                                                      //~v327R~
}//ugetdiskfree                                                    //~v327I~
#else   //!UNX                                                     //~v327I~
//*******************************************************          //~v083I~
//*ugetdiskfree                                                    //~v083I~
//*parm 1:drive letter('A' or 'a' etc,0 for current)               //~v083I~
//*parm 2:output dispspace structure                               //~v083R~
//*ret   :rc: 0(OK)  or else ERR(errno or APIRET)                  //~v083I~
//*******************************************************          //~v083I~
//unsigned int ugetdiskfree(char Pdletter,UDISKINFO *Pudiskinfo)     //~v083I~//~v5nuR~
unsigned int ugetdiskfree(char *Pfilename,UDISKINFO *Pudiskinfo)   //~v5nuR~
{                                                                  //~v083I~
    char drivestr[4];                                              //~v083I~
#ifdef DOS                                                         //~v083I~
    unsigned int driveid;                                          //~v083I~
    struct diskfree_t diskspace;                                   //~v083M~
#else                                                              //~v083I~
    #ifdef W32                                                     //~v083I~
        char *pc;                                                  //~v083I~
        DWORD sectornum,unitnum,unitavail,bytesnum;                //~v083I~
    #else   //os/2                                                 //~v083I~
typedef struct _FSPINFO{                                           //~v083I~
                        ULONG   filesysid;                         //~v083I~
                        ULONG   sectornum;                         //~v083I~
                        ULONG   unitnum;                           //~v083I~
                        ULONG   unitavail;                         //~v083I~
                        USHORT  bytesnum;                          //~v083I~
                      } FSPINFO;                                   //~v083I~
        FSPINFO fspinfo;                                           //~v083I~
        unsigned int driveid;                                      //~v083I~
    #endif                                                         //~v083I~
#endif                                                             //~v083I~
    unsigned int rc;                                               //~v083I~
    char Pdletter;                                                 //~v5nuR~
#ifdef W32                                                         //~v6uCI~
//  char uncpath[_MAX_PATH];                                       //~v6u5R~//~v6H1R~
    char uncpath[_MAX_PATH2];                                      //~v6H1R~
    int pathlen;                                                   //~v6u5I~
#endif                                                             //~v6uCI~
//*******************                                              //~v083I~
	if (Pfilename)                                                 //~v5nuR~
		Pdletter=*Pfilename;                                       //~v5nuR~
    else                                                           //~v5nuR~
    	Pdletter=0;                                                //~v5nuR~
    memset(Pudiskinfo,0,sizeof(UDISKINFO)); //clear for err        //~v083I~
#ifdef W32                                                         //~v083I~
    if (Pdletter)                                                  //~v083I~
    {                                                              //~v083I~
	  if (WIN_ISREMOTEPATH(Pfilename)) //remote dir                //~v5nuR~
      {                                                            //~v6u5I~
//    	pc=Pfilename;                                              //~v6u5R~
        strcpy(uncpath,Pfilename);                                 //~v6u5I~
        pathlen=PATHLEN(uncpath+2)+2;                              //~v6u5I~
        if (pathlen>0 && WILDCARD(uncpath+pathlen))                //~v6u5I~
        	*(uncpath+pathlen-1)=0;                                //~v6u5I~
        pc=uncpath;                                                //~v6u5I~
      }                                                            //~v6u5I~
      else                                                         //~v5nuR~
      {                                                            //~v5nuR~
        drivestr[0]=Pdletter;                                      //~v083I~
        drivestr[1]=':';                                           //~v083I~
        drivestr[2]='\\';                                          //~v083I~
        drivestr[3]=0;                                             //~v083I~
        pc=drivestr;                                               //~v083I~
      }                                                            //~v5nuR~
    }                                                              //~v083I~
    else                                                           //~v083I~
        pc=0;                                                      //~v083I~
#else                                                              //~v083I~
    if ((driveid=(UINT)Pdletter),driveid)                          //~v083I~
        driveid=(unsigned)(toupper(driveid)-'A'+1);                //~v083I~
#endif                                                             //~v083I~
#ifdef DOS                                                         //~v083I~
    rc=_dos_getdiskfree(driveid,&diskspace);                       //~v083I~
    if (rc)                                                        //~v083I~
    {                                                              //~v083I~
        rc=errno;                                                  //~v083I~
        sprintf(drivestr,"%c:",Pdletter);                          //~v083I~
        ufileapierr("_dos_getdiskfree",drivestr,rc);               //~v083I~
    }                                                              //~v083I~
    else                                                           //~v083I~
    {                                                              //~v083I~
        Pudiskinfo->total_clusters=diskspace.total_clusters;       //~v083I~
        Pudiskinfo->avail_clusters=diskspace.avail_clusters;       //~v083I~
        Pudiskinfo->sectors_per_cluster=diskspace.sectors_per_cluster;//~v083I~
        Pudiskinfo->bytes_per_sector=diskspace.bytes_per_sector;   //~v083I~
    }                                                              //~v083I~
#else                                                              //~v083I~
    #ifdef W32                                                     //~v083I~
        rc=GetDiskFreeSpace(pc,&sectornum,&bytesnum,&unitavail,&unitnum);//~v083I~
        if (rc==TRUE)                                              //~v083I~
        {                                                          //~v083I~
            Pudiskinfo->total_clusters=unitnum;                    //~v083R~
            Pudiskinfo->avail_clusters=unitavail;                  //~v083R~
            Pudiskinfo->sectors_per_cluster=sectornum;             //~v083R~
            Pudiskinfo->bytes_per_sector=bytesnum;                 //~v083R~
            rc=0;                                                  //~v083I~
        }                                                          //~v083I~
        else                                                       //~v083I~
        {                                                          //~v083I~
            rc=GetLastError();                                     //~v083I~
	      if (WIN_ISREMOTEPATH(Pfilename)) //remote dir            //~v6u4I~
            ufileapierr("GetDiskFreeSpace",Pfilename,(int)rc);     //~v6u4I~
          else                                                     //~v6u4I~
            ufileapierr("GetDiskFreeSpace",drivestr,(int)rc);      //~v083R~
        }                                                          //~v083I~
    #else                                                          //~v083I~
        rc=DosQueryFSInfo(driveid,(ULONG)FSIL_ALLOC,&fspinfo,sizeof(fspinfo));//~v083I~
        if (!rc)                                                   //~v083I~
        {                                                          //~v083I~
            Pudiskinfo->total_clusters=fspinfo.unitnum;            //~v083R~
            Pudiskinfo->avail_clusters=fspinfo.unitavail;          //~v083R~
            Pudiskinfo->sectors_per_cluster=fspinfo.sectornum;     //~v083R~
            Pudiskinfo->bytes_per_sector=(UINT)fspinfo.bytesnum;   //~v083R~
        }                                                          //~v083I~
        else                                                       //~v083I~
        {                                                          //~v083I~
            sprintf(drivestr,"%c:",Pdletter);                      //~v083I~
            ufileapierr("DosQueryFSInfo",drivestr,(int)rc);        //~v083R~
        }                                                          //~v083I~
    #endif                                                         //~v083I~
#endif                                                             //~v083I~
                                                                   //~v083I~
    return rc;                                                     //~v083I~
}//ugetdiskfree                                                    //~v083I~
#endif //not UNX                                                   //~v327I~
                                                                   //~v327I~
#ifdef OS2                                                         //~v101I~
//*******************************************************          //~v101I~
//*ufileishpfs                                                     //~v101I~
//*parm 1:drive letter('A' or 'a' etc,0 for current)               //~v101I~
//*ret   :rc: 0:FAT,1(HPFS),4(aoi err)                             //~v101I~
//*******************************************************          //~v101I~
int ufileishpfs(char Pdletter)                                     //~v101I~
{                                                                  //~v101I~
    unsigned int rc;                                               //~v101I~
    FSQBUFFER2 *pfsqb2;                                            //~v101R~
    ULONG buffsz;                                                  //~v101M~
    char buff[256];                                                //~v101R~
    char driveid[3];                                               //~v101I~
//*******************                                              //~v101I~
    driveid[0]=Pdletter;                                           //~v101I~
    driveid[1]=':';                                                //~v101I~
    driveid[2]=0;                                                  //~v101I~
    buffsz=sizeof(buff);                                           //~v101R~
    pfsqb2=(void*)buff;                                            //~v101I~
    rc=DosQueryFSAttach(driveid,1,(ULONG)FSAIL_QUERYNAME,pfsqb2,&buffsz);//~v101R~
    if (rc)                                                        //~v101I~
    {                                                              //~v101I~
        ufileapierr("DosQueryFSAttach",driveid,(int)rc);           //~v101I~
        rc=4;                                                      //~v101I~
    }                                                              //~v101I~
    else                                                           //~v101I~
    {                                                              //~v101I~
        if (stricmp(buff+(8+pfsqb2->cbName+1),"HPFS"))             //~v101R~
            rc=0;                                                  //~v101I~
        else                                                       //~v101I~
            rc=1;                                                  //~v101I~
    }                                                              //~v101I~
    return (int)rc;                                                //~v101R~
}//ufileishpfs                                                     //~v101I~
#else   //not OS2                                                  //~v101I~
//*******************************************************          //~v101I~
//*ufileisvfat                                                     //~v101I~
//*parm  :option                                                   //~v120R~
//*ret   :rc: 0:FAT,1(VFAT)                                        //~v101R~
//*******************************************************          //~v101I~
int ufileisvfat(int Popt)                                          //~v120R~
{                                                                  //~v101I~
#ifdef DPMI                                                        //~v101I~
    int rc;                                                        //~v101I~
#endif                                                             //~v101I~
//*******************                                              //~v101I~
#ifdef W32                                                         //~v101I~
    return 1;                                                      //~v101I~
#else                                                              //~v101I~
    #ifdef DPMI                                                    //~v101I~
      if (Popt & ISVFAT_FORCE)                                     //~v120I~
        rc=_use_lfn("\\");  //force same_drive_as_last_time=0      //~v120I~
      else                                                         //~v120I~
        rc=(_USE_LFN!=0);                                          //~v101R~
        if (!rc && (Popt & ISVFAT_ERRMSG))                         //~v120R~
            ufilenotvfat();                                        //~v101I~
        return rc;                                                 //~v101I~
    #else                                                          //~v101I~
        if (Popt & ISVFAT_ERRMSG)                                  //~v120R~
            ufilenotvfat();                                        //~v101I~
        return 0;                                                  //~v101I~
    #endif                                                         //~v101I~
#endif                                                             //~v101I~
}//ufileisvfat                                                     //~v101I~
#endif //DOS,W32                                                   //~v101R~
                                                                   //~v5i0I~
//*******************************************************          //~v5i0I~
//*ufileisntfs                                                     //~v5i0I~
//*parm  :driveid cahr                                             //~v5i0I~
//*ret   :rc: 0:NOT NTFS, 1:NTFS, -1:err                           //~v5i0I~
//*******************************************************          //~v5i0I~
int ufileisntfs(int Pdriveletter)                                  //~v5i0I~
{                                                                  //~v5i0I~
#ifndef W32                                                        //~v5i0I~
    return 0;                                                      //~v5i0I~
#else                                                              //~v5i0I~
                                                                   //~v5i0I~
static char Sntfsidtbl[26];	//0:not yet chked,1:not ntfs,2:ntfs    //~v5i0I~
    char rootdir[4];                                               //~v5i0I~
    DWORD maxcomplen,systemflag,rc;                                //~v5i0I~
    int driveid,ntfsid;                                            //~v5i0I~
   	char fsname[32];                                               //~v5i0I~
//*******************                                              //~v5i0I~
	driveid=toupper(Pdriveletter)-'A';                             //~v5i0I~
    if (driveid<0||driveid>=sizeof(Sntfsidtbl))                    //~v5i0I~
    	return -1;		//parm err                                 //~v5i0I~
    if (driveid<2)      	//a: b: is floppy                      //~v5i0I~
    	return 0;                                                  //~v5i0I~
    ntfsid=Sntfsidtbl[driveid];                                    //~v5i0I~
    if (!ntfsid)	//not yet chked                                //~v5i0I~
    {                                                              //~v5i0I~
//      rootdir[0]=Pdriveletter;                                   //~v5i0R~//~v6xeR~
        rootdir[0]=(char)Pdriveletter;                             //~v6xeI~
        rootdir[1]=':';                                            //~v5i0I~
        rootdir[2]='\\';                                           //~v5i0I~
        rootdir[3]=0;                                              //~v5i0I~
      	rc=GetVolumeInformation(rootdir,   //c:\  etc              //~v5i0R~
                                NULL,   //volume name buff         //~v5i0I~
                                0,      //volume name buff len     //~v5i0I~
                                NULL,   //volume serial DWORD ptr  //~v5i0I~
                                &maxcomplen,	//pathname component length//~v5i0I~
                                &systemflag,	//system flag      //~v5i0I~
                                fsname,			//file system name "FAT","NTFS" etc//~v5i0I~
                                sizeof(fsname));                   //~v5i0I~
        if (!rc)	//failed                                       //~v5i0R~
        	return -(int)GetLastError();                           //~v5i0R~
        ntfsid=(strcmp(fsname,"NTFS")==0)+1;                       //~v5i0I~
//      Sntfsidtbl[driveid]=ntfsid;                                //~v5i0I~//~v6xeR~
        Sntfsidtbl[driveid]=(char)ntfsid;                          //~v6xeI~
//  	printf("root=%s,fs=%s,rc=%d,stat=%d\n",rootdir,fsname,rc,ntfsid);//~v5i0R~
    }                                                              //~v5i0I~
    return ntfsid-1;                                               //~v5i0I~
#endif                                                             //~v5i0I~
}//ufileisntfs                                                     //~v5i0I~//~v6uCR~
#ifdef LNX                                                         //~v6uVI~
//*******************************************************          //~v6uVI~
//*ufileisvfatMounted                                              //~v6uVI~
//*1:on vfat                                                       //~v6uVI~
//*******************************************************          //~v6uVI~
int ufileisvfatMounted(int Popt,char *Pfnm)                        //~v6uVI~
{                                                                  //~v6uVI~
	struct mntent mnt;	//ptr to Pbuff                             //~v6uVI~
    char buff[1024];	//readbuff of /proc/mounts                 //~v6uVI~
    int rc=0,rc2;                                                  //~v6uVI~
//****************************************                         //~v6uVI~
	rc2=filesrchmountpoint(Pfnm,&mnt,buff,sizeof(buff));           //~v6uVI~
    if (!rc2) //found on /proc/mounts                              //~v6uVI~
    	if (!strcmp(mnt.mnt_type,"vfat"))	                       //~v6uVR~
        	rc=1;	                                               //~v6uVI~
    return rc;                                                     //~v6uVI~
}//ufileisvfatMounted                                              //~v6uVI~
//*******************************************************          //~v6uVI~
//*ufileisntfsMounted                                              //~v6uVI~
//*1:maybe NTFS("fuseblk" is for other than NTFS)                  //~v6uVI~
//*******************************************************          //~v6uVI~
int ufileisntfsMounted(int Popt,char *Pfnm)                        //~v6uVR~
{                                                                  //~v6uVI~
	struct mntent mnt;	//ptr to Pbuff                             //~v6uVI~
    char buff[1024];	//readbuff of /proc/mounts                 //~v6uVI~
    int rc=0,rc2;                                                  //~v6uVI~
//****************************************                         //~v6uVI~
	rc2=filesrchmountpoint(Pfnm,&mnt,buff,sizeof(buff));           //~v6uVI~
    if (!rc2) //found on /proc/mounts                              //~v6uVI~
    	if (!strcmp(mnt.mnt_type,"fuseblk"))                       //~v6uVR~
        	rc=1;                                                  //~v6uVI~
    return rc;                                                     //~v6uVI~
}//ufileisntfsMounted                                              //~v6uVR~
//*******************************************************          //~v6uVI~
//*ufileisMSMounted                                                //~v6uVI~
//*rc:1:vfat,2:ntfs                                                //~v6uVR~
//*******************************************************          //~v6uVI~
int ufileisMSMounted(int Popt,char *Pfnm)                          //~v6uVR~
{                                                                  //~v6uVI~
	struct mntent mnt;	//ptr to Pbuff                             //~v6uVI~
    char buff[1024];	//readbuff of /proc/mounts                 //~v6uVI~
    int rc=0,rc2;                                                  //~v6uVI~
//****************************************                         //~v6uVI~
	rc2=filesrchmountpoint(Pfnm,&mnt,buff,sizeof(buff));           //~v6uVI~
    if (!rc2) //found on /proc/mounts                              //~v6uVI~
    {                                                              //~v6uVI~
    	if (!strcmp(mnt.mnt_type,"vfat"))                          //~v6uVR~
            rc=1;                                                  //~v6uVI~
    	else                                                       //~v6uVR~
    	if (!strcmp(mnt.mnt_type,"fuseblk"))                       //~v6uVI~
        	rc=2;                                                  //~v6uVR~
    }                                                              //~v6uVI~
    return rc;                                                     //~v6uVI~
}//ufileisMSMounted                                                //~v6uVI~
#endif                                                             //~v6uVI~
//*******************************************************          //~v5nhI~
//*ufsetlock                                                       //~v5nhI~
//*r0:success                                                      //~v5nhI~
//*******************************************************          //~v5nhI~
int ufsetlock(int Popt,char *Plockfnm)                             //~v5nhI~
{                                                                  //~v5nhI~
#ifdef DOS                                                         //~v5nuI~
	return 0;                                                      //~v5nuI~
#else                                                              //~v5nuI~
	int rc=0;                                                      //~v5nhR~
#ifdef UNX                                                         //~v5nhI~
#else                                                              //~v5nhI~
    int fd;                                                        //~v5nhI~
#endif                                                             //~v5nhI~
//************************                                         //~v5nhI~
    if (Popt & UFSLO_LOCK)                                         //~v5nhI~
    {                                                              //~v5nhI~
#ifdef UNX                                                         //~v5nhI~
        rc=unx_fsetlock(Plockfnm);                                 //~v5nhI~
#else                                                              //~v5nhI~
        if ((fd=open(Plockfnm,O_WRONLY|O_CREAT|O_EXCL,S_IREAD|S_IWRITE))<=0)//~v5nhR~
        {                                                          //~v5nhI~
            if (errno==EEXIST)                                     //~v5nhI~
                return 4;           //lock failed                  //~v5nhI~
            return 8;                                              //~v5nhI~
        }                                                          //~v5nhI~
        if (close(fd))//force write accessibility                  //~v5nhR~
        {                                                          //~v5nhI~
            return 12;                                             //~v5nhI~
        }                                                          //~v5nhI~
#endif                                                             //~v5nhI~
    }                                                              //~v5nhI~
    else                                                           //~v5nhI~
    if (Popt & UFSLO_UNLOCK)                                       //~v5nhI~
    {                                                              //~v5nhI~
#ifdef UNX                                                         //~v5nhI~
    	rc=unx_fresetlock(Plockfnm);	//free                     //~v5nhI~
#else                                                              //~v5nhI~
		rc=unlink(Plockfnm);	//free                             //~v5nhI~
        if (rc)                                                    //~v5nhI~
            uerrmsg("lockfile(%s) delete failed errno=%d",0,       //~v5nhR~
						Plockfnm,errno);                           //~v5nhI~
#endif                                                             //~v5nhI~
    }                                                              //~v5nhI~
    return rc;                                                     //~v5nhI~
#endif //!DOS                                                      //~v5nuI~
}//ufsetlock                                                       //~v5nhI~
