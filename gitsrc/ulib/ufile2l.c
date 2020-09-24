//*CID://+v702R~:                             update#=   80;       //+v702R~
//************************************************************* //~5903R~
//*ufile2l.c                                                       //~0827R~
//*  UNIX version of                                               //~0827R~
//      umkdir,urmdir,uattrib,ugetftime,usetftime,ucopypathinfo    //~0827R~
//************************************************************* //~5617I~
//v702:200615 ARM compiler warning                                 //+v702I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6ht:120729 (LNX)display odd number file time stamp              //~v6htI~
//v6b8:111022 (ARM)android-uchmod fail on sdcard(VFAT);chmod is not effective on VFAT but it may cause permission err;it is also for not ARM//~v6b8I~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v5d2:040529 (UNX:BUG)rc of mkdir is ENOENT when path err(adeqaute errmsg issue)//~v5d2I~
//v5as:040111 (FTP:BUG) 2nd of 2 or'ed uftpisremote is not executed.//~v5asI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v59p:031110 ftp support:mkdir etc                                //~v59pI~
//v56j:020711 (UNX:BUG)s-link dir cannot delete by rmdir,use unlink//~v56jI~
//v56i:020711 (UNX:BUG)urmdir;not found msg issued for rc=20(not a dir)//~v56iI~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v55c:020428 (UNX:BUG)ROOTDIR chk for mdos disket                 //~v55cI~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//v519:011227 LINUX support:permission err msg for EPERM not only EACCESS//~v519R~
//                          (and err of apiname)                   //~v519I~
//v396:001105 LINUX support:(BUG)x-bit should be shifted to mode position
//v381:000930 LINUX support(BUG:no nor found msg for uattrib)      //~v381I~
//v380:000930 LINUX support(BUG:mode operation,attr is 2byte mopde+ 2byte attr)//~v380I~
//v375:000929 LINUX support(umkdirmode optionaly returns resulted mode;umask value effest)//~v375I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v365:000927 LINUX support(copy pathinfo time unit=1sec,not 2sec(dos))//~v365I~
//v351:000926 LINUX support(filename on permission err msg)        //~v351I~
//************************************************************* //~5903I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5825I~
#include <sys/time.h>                                              //~0827I~
#include <sys/types.h>                                             //~0827I~
#include <sys/stat.h>                                              //~0827R~
#include <unistd.h>                                                //~0827I~
#include <dirent.h>                                                //~v6b1I~
//*******************************************************
//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v59pI~
#include <ufile.h>
#include <ufile1l.h>                                               //~0901R~
#include <ufile2.h>                                             //~5826I~
#include <ufile2l.h>                                               //~0831I~
#include <ufile2l2.h>                                              //~v519I~
#include <ufemsg.h>                                                //~v036I~
#include <uerr.h>
#include <ualloc.h>                                             //~5913I~
#include <ustring.h>                                               //~v085I~
#include <utrace.h>                                                //~v012I~
#include <uedit.h>                                                 //~v195R~
#include <uunxsub.h>                                               //~0902I~
#ifdef FTPSUPP                                                     //~v59pI~
	#include <uftp.h>                                              //~v59pI~
	#include <ufile1f.h>                                           //~v59pI~
#endif                                                             //~v59pI~
//*******************************************************
static int Soddsec=0;                                              //~v6htI~
//*******************************************************
//**************************************************************** //~0831I~
//*umkdir                                                          //~0831I~
//* create dir with default mode 755(rwxr-xr-x)                    //~v351R~
//*parm1:dir name                                                  //~0831I~
//*retrn:rc(=errno)                                                //~0831I~
//**************************************************************** //~0831I~
int umkdir(UCHAR *Pdirname)                                        //~0831R~
{                                                                  //~0831I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~0831I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pdirname,&puftph))	//ftp filename             //~v5afR~
    	return uftpmkdir(puftph,Pdirname,0,0);                     //~v5afR~
#endif                                                             //~v59pI~
    return umkdirmode(Pdirname,0x01ed,0);   //o755                 //~v375R~
}//umkdir                                                          //~0831I~
//****************************************************************//~5909I~
//*umkdir                                                       //~5909I~
//* create dir                                                  //~5909I~
//*parm1:dir name                                               //~5909I~
//*parm2:request modifier                                          //~v375I~
//*parm3:optional resulted modifier                                //~v375I~
//*retrn:rc(=errno)                                             //~5909I~
//****************************************************************//~5909I~
int umkdirmode(UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode)         //~v375R~
{                                                               //~5909I~
    int rc;                                                     //~5909I~
    int mdossw;                                                    //~v538I~
    mode_t mode;                                                   //~0827I~
    FILEFINDBUF3 fstat3;                                           //~v375I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5909I~
    mode=(mode_t)Pmode & 07777;                                    //~v375R~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pdirname,&puftph))	//ftp filename             //~v5afR~
    	return uftpmkdir(puftph,Pdirname,mode,Pprmode);            //~v5afR~
#endif                                                             //~v59pI~
  	mdossw=MDOSDISKOK(Pdirname);	    //contain drive id         //~v538R~
  if (mdossw)	    //contain drive id                             //~v538I~
    rc=umkdir_mdos(Pdirname);                                      //~v538R~
  else                                                             //~v538R~
    rc=mkdir(Pdirname,mode);                                       //~0827R~
    if (!rc)                                                    //~5909I~
    {                                                              //~v375I~
        if (Pprmode)                                               //~v375I~
        {                                                          //~v375I~
            if (ufstat(Pdirname,&fstat3))  //exist as file         //~v375R~
                *Pprmode=0;                                        //~v375I~
            else                                                   //~v375I~
                *Pprmode=FILE_GETMODE(fstat3.attrFile)&07777;      //~v375R~
        }                                                          //~v375I~
        return 0;                                               //~5909I~
    }                                                              //~v375I~
    rc=errno;       //save original errno;                      //~5909I~
    if (Gufile_nomsg)   //nomsg option                          //~5909I~
        return rc;                                              //~5909I~
                                                                //~5909I~
    switch(rc)                                                  //~5909I~
    {                                                           //~5909I~
#ifdef AIX                                                         //~v55nI~
    case ENOSYS:                                                   //~v55nI~
        return rc;                                                 //~v55nR~
#endif                                                             //~v55nI~
    case ENOTDIR:                                                  //~v327I~
    case ENOENT:                                                   //~v5d2I~
        return ufilepatherr(Pdirname,rc);                       //~5909I~
    case EACCES:                                                //~5909I~
        return ufilenopermission("mkdir",Pdirname,rc);             //~v366R~
    case EEXIST:                                                   //~v327I~
        return ufileexist(Pdirname,rc);                            //~v327I~
    }                                                           //~5909I~
    return ufileapierr("mkdir",Pdirname,rc);                    //~5909R~
}//umkdirmode                                                      //~v519R~
                                                                //~5909I~
//****************************************************************//~5909I~
//*urmdir                                                       //~5909I~
//* remove dir                                                  //~5909I~
//* dir must be empty,not root nor current dir                  //~5909I~
//*parm1:dir name                                               //~5909I~
//*retrn:rc(=errno),-2:root dir,-3:current dir                  //~5B25R~
//****************************************************************//~5909I~
int urmdir(UCHAR *Pdirname)                                     //~5909I~
{                                                               //~5909I~
    int rc;                                                     //~5909I~
    int mdossw;                                                    //~v538I~
    UCHAR fpath[_MAX_PATH];                                        //~v55nR~
    FILEFINDBUF3 ft;                                               //~v56jI~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5909I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pdirname,&puftph))	//ftp filename             //~v5afR~
		return uftprmdir(puftph,Pdirname);                         //~v5afR~
#endif                                                             //~v59pI~
    if (!ufullpath(fpath,Pdirname,_MAX_PATH))                      //~v55nR~
        return -1;                                              //~5909I~
    if (ROOTDIR2(fpath))  //dosfindfirst faile if root             //~v55nR~
        return ufileroot(fpath,-2);                                //~v55nR~
  	mdossw=MDOSDISKOK(Pdirname);	    //contain drive id         //~v538I~
  	if (mdossw)	    //contain drive id                             //~v538R~
    	rc=urmdir_mdos(fpath);                                     //~v55nR~
    else                                                           //~v538R~
        rc=rmdir(fpath);                                           //~v55nR~
    if (!rc)                                                    //~5909I~
        return 0;                                               //~5909I~
    rc=errno;       //save original errno;                      //~5909I~
    if (Gufile_nomsg)   //nomsg option                          //~5909I~
        return rc;                                              //~5909I~
                                                                //~5909I~
    switch(rc)                                                  //~5909I~
    {                                                           //~5909I~
#ifdef AIX                                                         //~v55nI~
    case ENOSYS:                                                   //~v55nI~
        return rc;                                                 //~v55nR~
#endif                                                             //~v55nI~
    case ENOTDIR:                                                  //~v327I~
        if (!ufstat(fpath,&ft))                                    //~v56jI~
        {                                                          //~v56jI~
        	if (*ft.slink && (ft.attrFile & FILE_DIRECTORY))	//slink//~v56jR~
            	if (!uremove(fpath))                               //~v56jI~
                	return 0;                                      //~v56jI~
        }                                                          //~v56jI~
        return ufilenotdir(fpath,rc);                              //~v56iI~
    case ENOENT:                                                //~5909I~
        return ufilenotfound(fpath,rc);                            //~v55nR~
    case EACCES:                                                //~5909I~
        return ufilenopermission("rmdir",fpath,rc);                //~v55nR~
    case ENOTEMPTY:                                                //~v327I~
    case EBUSY:                                                    //~v327I~
        uerrmsg("%s is not empty or opened",                       //~v327I~
                "%s は 空でないかオープン中",                      //~v327I~
                fpath);                                            //~v55nR~
        return rc;                                                 //~v327I~
    }                                                           //~5909I~
    return ufileapierr("rmdir",fpath,rc);                          //~v55nR~
}//urmdir                                                       //~5909R~
//****************************************************************//~5903I~
//uattrib                                                       //~5903I~
//* set file attribute(read/hidden/system/archive)              //~5903R~
//* return file attribute when p2==0 and p3==0                  //~5903I~
//*parm1:filename                                               //~5903I~
//*parm2:attribute to set on   mode+attr                           //~0901R~
//*parm3:attribute to set off  mode+attr   if on=0,off=0:query     //~0901R~
//*parm4:result attribute      mode+attr                           //~0901R~
//*retrn:rc                                                     //~5903R~
//****************************************************************//~5903I~
int uattrib(UCHAR *Pfname,ULONG Pattron,ULONG  Pattroff,ULONG  *Poutattr)//~0827R~
{                                                               //~5903I~
    ULONG   attr;                                                  //~0827R~
    mode_t  mode,modeon,modeoff;                                   //~0827I~
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
    if (rc=(int)ufstat(Pfname,&fstat30),rc)                        //~0827R~
    {                                                              //~v381I~
        if (rc==ENOENT||rc==ENOTDIR)                               //~v381I~
            return ufilenotfound(Pfname,rc);                       //~v381I~
        return rc;                                              //~5905I~
    }                                                              //~v381I~
    attr=fstat30.attrFile & FILE_ATTRMASK;                         //~0901R~
    if ((attr & FILE_READONLY)                                     //~v085R~
    &&  (Pattroff & FILE_READONLY)) //READ_ONLY reset req          //~v085I~
        if (ufilespfnchk(Pfname,2))  //if special file for attrib  //~v085I~
        {                                                          //~v085I~
            uerrmsg("%s is prohibitted to reset RONLY attribute",  //~v085I~
                    "%s は読取専用属性リセット禁止の特殊ファイルです",//~v085I~
                    Pfname);                                       //~v085I~
            return EACCES;                                         //~v085R~
        }                                                          //~v085I~
  if (attr & FILE_MDOSDISK)                                        //~v55nR~
  {                                                                //~v55nR~
    if (Pattron||Pattroff)                                         //~v55nI~
    	if (rc=uattrib_mdos(Pfname,Pattron,Pattroff),rc)          //set//~v55nR~
        	return rc;                                             //~v55nR~
  }                                                                //~v55nR~
  else                                                             //~v55nR~
  {                                                                //~v55nR~
//  mode=FILE_GETMODE(fstat30.attrFile);                           //~v380R~//~v6BxR~
    mode=(mode_t)FILE_GETMODE(fstat30.attrFile);                   //~v6BxI~
//printf("curr  mode=%08x(o%o)\n",mode,mode);                      //~0901R~
//  modeon=FILE_GETMODE(Pattron);                                  //~v380R~//~v6BxR~
    modeon=(mode_t)FILE_GETMODE(Pattron);                          //~v6BxI~
//  modeoff=FILE_GETMODE(Pattroff);                                //~v380R~//~v6BxR~
    modeoff=(mode_t)FILE_GETMODE(Pattroff);                        //~v6BxI~
    if (modeon || modeoff)                                         //~0827R~
    {                                                           //~5903I~
        mode&=~modeoff;                                            //~0827R~
        mode|=modeon;                                              //~0827R~
//printf("chmod mode=%08x(o%o)\n",mode,mode);                      //~0901R~
        if (rc=ufilesetmod(Pfname,mode),rc)          //set         //~v381R~
            return rc;                                             //~v381R~
    }                                                           //~5903I~
  }                                                                //~v55nR~
    if (rc=(int)ufstat(Pfname,&fstat30),rc)//confirm result        //~v380I~
        return rc;                                                 //~v380I~
    *Poutattr=fstat30.attrFile;                                    //~0901I~
    return 0;                                                      //~0827R~
}//uattrib                                                      //~5903I~
//**************************************************************** //~0902I~
//uattrxon                                                         //~0902I~
//* set x bit(USER)                                                //~0902I~
//*parm1:filename                                                  //~0902I~
//*retrn:rc                                                        //~0902I~
//**************************************************************** //~0902I~
int uattrxon(UCHAR *Pfname)                                        //~0902I~
{                                                                  //~0902I~
    ULONG   attr=0,attron;                                    //+v396R~   //~0902I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~0902I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpattrxon(puftph,Pfname);                         //~v5afR~
#endif                                                             //~v59pI~
    attron=FILE_SETMODEATTR(S_IXUSR,0);                            //~v396R~
    return uattrib(Pfname,attron,0,&attr);                        //~0902R~
}//uattrxon                                                        //~0902I~
//**************************************************************** //~0902I~
//uattrxchk                                                        //~0902I~
//* chk x bit(USER)                                                //~0902I~
//*parm1:filename                                                  //~0902I~
//*parm2:opt to issue errmsg                                       //~0902I~
//*retrn:rc:0 not executable,1:executable                          //~0902I~
//**************************************************************** //~0902I~
int uattrxchk(UCHAR *Pfname,int Popt)                              //~0902I~
{                                                                  //~0902I~
    FILEFINDBUF3 fstat30;                                          //~0902I~
    mode_t mode;                                                   //~0902I~
    int rc;                                                        //~0902I~
    uid_t  uid;                                                    //~0902I~
    gid_t  gid;                                                    //~0902I~
#ifdef FTPSUPP                                                     //~v59pI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v59pI~
//********************                                             //~0902I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpattrxchk(puftph,Pfname,Popt);                   //~v5afR~
#endif                                                             //~v59pI~
    if (rc=(int)ufstat(Pfname,&fstat30),rc)                        //~0902I~
        return rc;                                                 //~0902I~
//  mode=FILE_GETMODE(fstat30.attrFile);                           //~0902R~//~v6BxR~
    mode=(mode_t)FILE_GETMODE(fstat30.attrFile);                   //~v6BxI~
    ugetugid(&uid,&gid);                                           //~0902I~
    if (!(mode & S_IXOTH)                                          //~0902I~
    &&   ((gid!=fstat30.gid && uid)||!(mode & S_IXGRP))            //~0902R~
    &&   ((uid!=fstat30.uid && uid)||!(mode & S_IXUSR)))           //~0902R~
    {                                                              //~0902I~
        if (Popt & UAXC_MSG)                                       //~0902I~
            uerrmsg("%s has no x-permissin",                       //~0902I~
                    "%s には実行権限がありません",                 //~0902I~
                    Pfname);                                       //~0902I~
        return 0;                                                  //~0902I~
    }                                                              //~0902I~
    return 1;                                                      //~0902I~
}//uattrxchk                                                       //~0902I~
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
    int  rc;                                                       //~v013R~
    FILEFINDBUF3 ffb3;                                             //~v035I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5910I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpgetftime(puftph,Pfname,Ppdate,Pptime);          //~v5afR~
#endif                                                             //~v59pI~
//  if (rc=ufstat(Pfname,&ffb3),rc)                                //~v035I~//~v6BkR~
    if (rc=(int)ufstat(Pfname,&ffb3),rc)                           //~v6BkI~
        return ufilenotfound(Pfname,rc);                           //~v035I~
    *Ppdate=ffb3.fdateLastWrite;                                   //~v035I~
    *Pptime=ffb3.ftimeLastWrite;                                   //~v035I~
    return rc;                                                     //~v013R~
}//ugetftime                                                    //~5923R~
//**************************************************************** //~v6htI~
//ugetftime_1sec                                                   //~v6htR~
//* indicate odd number second                                     //~v6htI~
//*retrn:rc                                                        //~v6htI~
//**************************************************************** //~v6htI~
int ugetftime_1sec(UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime,int *Ppoddsec)//~v6htR~
{                                                                  //~v6htI~
    int  rc;                                                       //~v6htI~
    FILEFINDBUF3 ffb3;                                             //~v6htI~
#ifdef FTPSUPP                                                     //~v6htI~
    PUFTPHOST puftph;                                              //~v6htI~
#endif                                                             //~v6htI~
//********************                                             //~v6htI~
#ifdef FTPSUPP                                                     //~v6htI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v6htI~
		return uftpgetftime_1sec(puftph,Pfname,Ppdate,Pptime,Ppoddsec);//~v6htR~
#endif                                                             //~v6htI~
//  if (rc=ufstat(Pfname,&ffb3),rc)                                //~v6htI~//~v6BkR~
    if (rc=(int)ufstat(Pfname,&ffb3),rc)                           //~v6BkI~
        return ufilenotfound(Pfname,rc);                           //~v6htI~
    *Ppdate=ffb3.fdateLastWrite;                                   //~v6htI~
    *Pptime=ffb3.ftimeLastWrite;                                   //~v6htI~
    *Ppoddsec=(ffb3.mtime & 1);	//FTIME's second is by 2sec        //~v6htI~
    return rc;                                                     //~v6htI~
}//ugetftime_1sec                                                  //~v6htR~
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
    struct timeval tv[2];    //access amd modified                 //~0827R~
    int rc;                                                        //~0827I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5910I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpsetftime(puftph,Pfname,Pdate,Ptime);            //~v5afR~
#endif                                                             //~v59pI~
    memset(tv,0,sizeof(tv));                                       //~0827I~
    tv[1].tv_sec=ufilemktime(Pdate,Ptime);  //modified time        //~0827R~
    tv[1].tv_sec+=Soddsec;                                         //~v6htI~
    if (!utimes(Pfname,tv))       //set                            //~0827R~
        return 0;                                                  //~0827R~
    rc=errno;                                                      //~0827I~
    switch(rc)                                                     //~0827I~
    {                                                              //~0827I~
    case EACCES:                                                   //~0827I~
    case EPERM:     //operation not permitted                      //~v519I~
        return ufilenopermission("utimes",Pfname,rc);              //~v366R~
    case ENOTDIR:                                                  //~0827I~
    case ENOENT:                                                   //~0827I~
        return ufilenotfound(Pfname,rc);                           //~0827R~
    }                                                              //~0827I~
    return ufileapierr("chmod",Pfname,rc);                         //~0827I~
}//usetftime                                                    //~5910I~
//**************************************************************** //~v6htI~
//usetftime_1sec                                                   //~v6htR~
//*retrn:rc                                                        //~v6htI~
//**************************************************************** //~v6htI~
int usetftime_1sec(UCHAR *Pfname,FDATE Pdate,FTIME Ptime,int Poddsec)//~v6htR~
{                                                                  //~v6htI~
    int rc;                                                        //~v6htI~
//********************                                             //~v6htI~
	Soddsec=Poddsec;                                               //~v6htI~
	rc=usetftime(Pfname,Pdate,Ptime);                              //~v6htI~
    Soddsec=0;                                                     //~v6htI~
    return rc;                                                     //~v6htI~
}//usetftime_1sec                                                  //~v6htR~
//**************************************************************** //~v365I~
//usetftime2                                                       //~v365I~
//* set file time stamp; unit=second                               //~v365I~
//*parm1:filename                                                  //~v365I~
//*parm2:atime (access time)                                       //~v365I~
//*parm3:mtime (modification time)                                 //~v365I~
//*retrn:rc                                                        //~v365I~
//**************************************************************** //~v365I~
int usetftime2(UCHAR *Pfname,time_t Patime,time_t Pmtime)          //~v365I~
{                                                                  //~v365I~
    struct timeval tv[2];    //access amd modified                 //~v365I~
    int rc;                                                        //~v365I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~v365I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpsetftime2(puftph,Pfname,(ULONG)Patime,(ULONG)Pmtime);//~v5afR~
#endif                                                             //~v59pI~
    memset(tv,0,sizeof(tv));                                       //~v365I~
    tv[0].tv_sec=Patime;                                           //~v365I~
    tv[1].tv_sec=Pmtime;                                           //~v365I~
    if (!utimes(Pfname,tv))       //set                            //~v365I~
        return 0;                                                  //~v365I~
    rc=errno;                                                      //~v365I~
    switch(rc)                                                     //~v365I~
    {                                                              //~v365I~
    case EACCES:                                                   //~v365I~
    case EPERM:     //operation not permitted                      //~v519I~
        return ufilenopermission("utime",Pfname,rc);               //~v519R~
    case ENOTDIR:                                                  //~v365I~
    case ENOENT:                                                   //~v365I~
        return ufilenotfound(Pfname,rc);                           //~v365I~
    }                                                              //~v365I~
    return ufileapierr("utime",Pfname,rc);                         //~v519R~
}//usetftime2                                                      //~v365I~
#ifdef ARM                                                         //~v6b8I~
//**************************************************************** //~v6b8I~
int ustatisvfat(char *Pfpath,FILEFINDBUF3 *Ppffb3)                 //~v6b8R~
{                                                                  //~v6b8I~
//  int rc=0,fsid;                                                 //~v6b8R~//+v702R~
    int rc=0     ;                                                 //+v702I~
//**********************                                           //~v6b8I~
//    fsid=Ppffb3->fsid & 0xff;                                    //~v6b8R~
//    rc=(                                                         //~v6b8R~
//        fsid==0x0b      //FAT32                                  //~v6b8R~
//    ||  fsid==0x0c      //FAT32 LBA                              //~v6b8R~
//        );                           //TODO no fsid doc for android//~v6b8R~
//    rc=isonsdpath(Pfpath);                                       //~v6b8R~
  #ifdef XXE                                                       //~v6b8I~
    rc=isonvfat(Pfpath);                                           //~v6b8I~
  #else                                                            //~v6b8I~
    rc=strstr(Pfpath,"/sdcard/")!=0;                               //~v6b8I~
  #endif                                                           //~v6b8I~
    return rc;                                                     //~v6b8I~
}                                                                  //~v6b8I~
#endif                                                             //~v6b8I~
//****************************************************************//~5910I~
//ucopypathinfo                                                 //~5916R~
//* copy file information(attr,timestamp, for os2 created time etc)//~5910I~
//*parm1:source name                                            //~5910I~
//*parm2:target name                                               //~v365R~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int ucopypathinfo(UCHAR *Psource,UCHAR *Ptarget)                //~5910I~
{                                                               //~5910I~
    FILEFINDBUF3 ffb3;                                             //~v365I~
    FILEFINDBUF3 ffb3t;                                            //~v6b8I~
    int rc;                                                        //~v365R~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftphs,puftpht;                                     //~v5afI~
#endif                                                             //~v5afI~
//********************                                          //~5910I~
#ifdef FTPSUPP                                                     //~v59pI~
//  if (uftpisremote(Psource,&puftphs)	//ftp filename             //~v5asR~
//  ||  uftpisremote(Ptarget,&puftpht))	//ftp filename             //~v5asR~
    if ((uftpisremote(Psource,&puftphs)	//ftp filename             //~v5asR~
    ||  +uftpisremote(Ptarget,&puftpht))!=0)	//ftp filename     //~v5asR~
		return uftpcopypathinfo(puftphs,puftpht,Psource,Ptarget);  //~v5afR~
#endif                                                             //~v59pI~
//  if (rc=ufstat(Psource,&ffb3),rc)                               //~v365R~//~v6BkR~
    if (rc=(int)ufstat(Psource,&ffb3),rc)                          //~v6BkI~
        return rc;                                                 //~v365I~
    if (MDOSDISKOK(Psource) && !MDOSDISKOK(Ptarget))    //mdos to unix//~v55nI~
    {                                                              //~v55nI~
    	if (rc=usetftime(Ptarget,ffb3.fdateLastWrite,ffb3.ftimeLastWrite),rc)//~v55nI~
        	return rc;                                             //~v55nI~
        return 0;   //skip rwx mode set                            //~v55nI~
    }                                                              //~v55nI~
    else                                                           //~v55nI~
//#ifdef UNX                                                       //~v59pR~
    if (MDOSDISKOK(Ptarget))  //for mdos no api support            //~v55nR~
        	return 0;                                              //~v55nI~
    else                                                           //~v55nI~
//#endif                                                           //~v59pR~
    if (rc=usetftime2(Ptarget,ffb3.atime,ffb3.mtime),rc)           //~v365R~
        return rc;                                                 //~0827R~
    UTRACEP("ucopypathinfo src=%s,ttgt=%s,atime=%x,mtime=%x\n",Psource,Ptarget,ffb3.atime,ffb3.mtime);//~v6htI~
  if (!ufstat(Ptarget,&ffb3t)                                      //~v6b8R~
  &&   FILE_GETMODE(ffb3.attrFile)!=FILE_GETMODE(ffb3t.attrFile))  //~v6b8R~
  {                                                                //~v6b8I~
#ifdef ARM                                                         //~v6b8I~
   if (!ustatisvfat(Ptarget,&ffb3t))	//avoid for sdcard         //~v6b8R~
#endif                                                             //~v6b8I~
//  rc+=ufilesetmod(Ptarget,FILE_GETMODE(ffb3.attrFile)); //all off then set on//~v365R~//~v6BxR~
    rc+=ufilesetmod(Ptarget,(mode_t)FILE_GETMODE(ffb3.attrFile)); //all off then set on//~v6BxI~
  }                                                                //~v6b8I~
    UTRACEP("ucopypathinfo after usetftime atime=%x,mtime=%x\n",ffb3t.atime,ffb3t.mtime);//~v6htI~
	ufstat(Ptarget,&ffb3t);//test@@@@                              //~v6htI~
    UTRACEP("ucopypathinfo after setmod atime=%x,mtime=%x\n",ffb3t.atime,ffb3t.mtime);//~v6htI~
//  rc+=ufilesetown(Ptarget,ffb3.uid,ffb3.gid);//uid can chmd by root only//~v366R~
    return rc;                                                     //~v365R~
}//ucopypathinfo                                                //~5910I~
//**************************************************************** //~v365I~
//ufilesetown                                                      //~v365R~
//* set uid/gid                                                    //~v365I~
//*parm1:target name                                               //~v365I~
//*parm2:uid                                                       //~v365I~
//*parm3:gid                                                       //~v365I~
//*retrn:rc                                                        //~v365I~
//**************************************************************** //~v365I~
int ufilesetown(UCHAR *Pfname,uid_t Puid,gid_t Pgid)               //~v365R~
{                                                                  //~v365I~
    int rc;                                                        //~v365I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~v365I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpsetown(puftph,Pfname,(ULONG)Puid,(ULONG)Pgid);  //~v5afR~
#endif                                                             //~v59pI~
    if (!chown(Pfname,Puid,Pgid))                                  //~v365R~
        return 0;                                                  //~v365I~
    rc=errno;                                                      //~v365R~
    switch(rc)                                                     //~v365I~
    {                                                              //~v365I~
    case EPERM:                                                    //~v365I~
        return ufilenopermission("chown",Pfname,rc);               //~v366R~
    case ENOTDIR:                                                  //~v365I~
    case ENOENT:                                                   //~v365I~
        return ufilenotfound(Pfname,rc);                           //~v365I~
    }                                                              //~v365I~
    return ufileapierr("chown",Pfname,rc);                         //~v365I~
}//ufilesetown                                                     //~v365I~
//**************************************************************** //~v365I~
//ufilesetmod                                                      //~v365I~
//* set modifier                                                   //~v381R~
//*parm1:target name                                               //~v365I~
//*parm2:mode  or attr fpr MDOS file                               //~v519R~
//*retrn:rc                                                        //~v365I~
//**************************************************************** //~v365I~
int ufilesetmod(UCHAR *Pfname,mode_t Pmode)                        //~v365R~
{                                                                  //~v365I~
    int rc;                                                        //~v365I~
#ifdef FTPSUPP                                                     //~v5afI~
    PUFTPHOST puftph;                                              //~v5afI~
#endif                                                             //~v5afI~
//********************                                             //~v365I~
    Pmode&=FILE_CHMODMASK_UNIX;      //o7777                       //~v538I~
#ifdef FTPSUPP                                                     //~v59pI~
  	if (uftpisremote(Pfname,&puftph))	//ftp filename             //~v5afR~
		return uftpsetmod(puftph,Pfname,(ULONG)Pmode);             //~v5afR~
#endif                                                             //~v59pI~
    if (!chmod(Pfname,Pmode))                                      //~v365R~
        return 0;                                                  //~v365I~
    rc=errno;                                                      //~v365R~
    switch(rc)                                                     //~v365I~
    {                                                              //~v365I~
    case EPERM:                                                    //~v365I~
        return ufilenopermission("chmod",Pfname,rc);               //~v366R~
    case ENOTDIR:                                                  //~v365I~
    case ENOENT:                                                   //~v365I~
        return ufilenotfound(Pfname,rc);                           //~v365I~
    }                                                              //~v365I~
    return ufileapierr("chmod",Pfname,rc);                         //~v365I~
}//ufilesetmod                                                     //~v365I~
