//*CID://+v702R~:                             update#=  680;       //~v6H7R~//+v702R~
//*************************************************************
//*ufile3f.c                                                       //~v5azR~
//*  FTP version of uxcopy,uxmove
//*************************************************************
//v702:200615 ARM compiler warning                                 //+v702I~
//v6H7:170108 FTP crush by long name                               //~v6H7I~
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6G3I~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6hc:120613 (ARM)avoid uninitialized variable warning by gcc 4.4.3 on FC12(copile optio -Ox is required also)//~v6hcI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6dk:120323 patherr msg for ftp copy source                      //~v6dkI~
//v6da:120217 (Axe)smb support                                     //~v6daI~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1I~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61n:080121*Bug report by M.J(LCD fail when LANG is not english) //~v61nI~
//v61i:080117*xuerpchk(uerrmsg parameter chk)                      //~v61iI~
//v61b:071123*(FTP)log errmsg to ftplog alos                       //~v61bI~
//v619:071123*(FTP:BUG)delete may returns not 250 but 226          //~v619I~
//v618:071123*(FTP:BUG)CD failed msg issued when save              //~v619I~
//v5jh:061020 (WXE:BUG)FTP upload copy fail when source is wildcard by "case unmatch"//~v5jhI~
//v5fr:050321 (FTP)xcopy /d option support for remote file         //~v5frI~
//v5fi:050212 (BUG of v5fg)file open abend;for safety use dummy udirlist//~v5fiI~
//v5fg:050125 skip override option for copy/move                   //~v5fgI~
//v5ey:041107 ftp text mode support(for cmd temp file)             //~v5eyI~
//v5de:040609 (AIX:BUG)filetime set not done for download file     //~v5daI~
//v5da:040531 (FTP:BUG)win ftp accept filename case-insensitively but//~v5d9I~
//                     target filename is set case sensitively.    //~v5d9I~
//                     So,after sccessfull put,file is not found.  //~v5d9I~
//v5d9:040530 (FTP)skip upload for r2r to bypass not found msg if downloaded no entry//~v5d8I~
//            ufile3f.c                                            //~v5d8I~
//v5d8:040530 (FTP)hide temp filename for dir to file operation err mnsg//~v5d8I~
//v5d6:040529 (FTP)mkdir occur when file download to new or wildcard target//~v5d6I~
//v5d5:040529 (UNX:FTP)"force one by one move for root" is also for upload when UNX//~v5d5I~
//v5d4:040529 (FTP:BUG)not "path err" but "md fail" or "put fail"  //~v5d4I~
//            because ENOTDIR is returned by ufstat(it should be ERROR_PATH_NOT_FOUND) for Win//~v5d4I~
//v5cv:040512 (FTP:BUG)remote to remote                            //~v5cvI~
//v5cu:040511 (FTP:BUG)append created target dir                   //~v5cuI~
//v5cq:040509 reject also wildcard root as delete or move source   //~v5cqI~
//v5cm:040508 (FTP:BUG)subdir is not copyed by /s when soure is wildard//~v5cmI~
//v5ck:040508 (FTP)same remote move spec as loal move              //~v5ckI~
//v5cj:040505 (FTP)target wildcard support                         //~v5cjI~
//v5ci:040504 (FTP)missing ufree when existing err of xcopy        //~v5ciI~
//v5cg:040504 (FTP)same spec as local xcopy/xmove/xappend          //~v5cgI~
//v5cd:040425 xcopy support option to create src dir intarget dir. //~v5cdI~
//v5bk:040209 (FTP:BUG)download append file faile by mkdir samename//~v5bkI~
//v5bf:040204 (FTP:BUG)space containing filename support           //~v5bfI~
//v5b8:040129 (FTP:BUG) remote to remote case;dir is creted in target dirname//~v5b8I~
//v5b6:040124 (FTP)move(copy & del)support                         //~v5b6I~
//v5b1:040115 (FTP)tempdir del option for test                     //~v5b1I~
//v5b0:040115 (LNX:BUG)mkstmp is for file only,mkdtmp is required for temp dir//~v5b0I~
//v5az:040115 (FTP) support remote to remote                       //~v5azI~
//v5au:040112 (FTP)xcopy file2file(rename) support                 //~v5auI~
//v5ar:040111 (FTP)wild card err responce chk specification like as 5**//~v5arI~
//v5aq:040111 (FTP)append support                                  //~v5aqI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v59r:031124 ftp support:copy/move
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
//*******************************************************
#ifdef DOS
#else
    #ifdef W32
        #include <dos.h>
      #ifdef WIN10                                                   //+v6BkI//~v6G3I~
	    #include <winerror.h>                                      //~v6G3I~
      #else                                                        //~v6G3I~
        #include <error.h>                                         //~v5auI~
      #endif                                                       //~v6G3I~
    #else
    #define INCL_BASE
    #define INCL_DOSFILEMGR
    #include <os2.h>
    #endif
#endif
#ifdef UNX                                                         //~v6b1I~
	#include <dirent.h>                                            //~v6b1I~
#endif                                                             //~v6b1I~

//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <ufile.h>
#include <ufile2.h>
#include <ufile3.h>
#include <ufile4.h>                                                //~v5aqI~
#include <ufile5.h>
#include <ufemsg.h>
#include <uerr.h>
#include <ualloc.h>
#include <utrace.h>                                                //~v59rM~
#ifdef UNX
	#include <ufile1l.h>
	#include <ufile2l.h>                                           //~v59rI~
#else  //!UNX
#endif //!UNX
#include <uftp.h>                                                  //~v5afM~
#include <ufile1f.h>
#include <uftp3.h>                                                 //~v61pM~
#ifdef ARMXXE                                                      //~v6daI~
	#include <jnic2ju.h>                                           //~v6daI~
#endif                                                             //~v6daI~
//*******************************************************
#define FTP_CONCAT_PATH(fpath,pathn,fn)   \
					strcpy(fpath,pathn),                         \
                    ROOTDIR(fpath)?                              \
							strcpy(fpath+1,fn):                  \
                            (strcat(fpath,"/"),strcat(fpath,fn))
#define WIN_CONCAT_PATH(fpath,pathn,fn)   \
					strcpy(fpath,pathn),                         \
                    ROOTDIR(fpath)?                              \
							strcpy(fpath+3,fn):                  \
                            (strcat(fpath,DIR_SEPS),strcat(fpath,fn))
typedef struct _UFTPPARM  {
                            int    UFPopt;
                            int    UFPflag;
                            char   UFPtsepc;	//target path seperator//~v59rR~
                            char   UFPssepc;	//target path seperator//~v59rR~
                            ULONG  UFPattrmask;
                            FILEFINDBUF3 *UFPsfstat3;	//source file/dir fstat3//~v59rI~
                            char  *UFPsfpath;  //path name without last "/" even for root
                            char  *UFPtfpath;
                            char  *UFPnewtgt;  //parm to callback  //~v59rI~
                            PUDIRLIST UFPpudl;
                            PUFTPHOST UFPpuftph;                   //~v5afI~
                            int    UFPpudlno;
                            int    UFPspathlen; //with hostnm,w/o last "/" even for root
                            int    UFPtpathlen;
                            int    UFPcmdctr;
                            int    UFPsubdirctr;                   //~v5d9R~
                            int    UFPcmdokctr;
                            int    UFPcopyskipctr;//skip by date option//~v5frI~
                            FILE*  UFPpfh;
//                          char   UFPtwildmask[_MAX_PATH];        //~v5cjI~//~v6H7R~
//                          char   UFPswildpdir[_MAX_PATH];        //~v5cjI~//~v6H7R~
//                          char   UFPlcdpath[_MAX_PATH];          //~v6H7I~
                            char   UFPtwildmask[FTP_MAXPATH];      //~v6H7I~
                            char   UFPswildpdir[FTP_MAXPATH];      //~v6H7I~
                            char   UFPlcdpath[FTP_MAXPATH];          //~v5ckR~//~v6H7R~
                            } UFTPPARM,*PUFTPPARM;
#define UFTPPARMSZ (sizeof(UFTPPARM))

#define UFPF_TFILE              0x01                               //~v5auR~
#define UFPF_TDIR               0x02                               //~v5auR~
#define UFPF_TROOT              0x04                               //~v5auR~
#define UFPF_TNEW               0x08                               //~v5auR~
#define UFPF_SFILE              0x10                               //~v5auR~
#define UFPF_SDIR               0x20                               //~v5auR~
#define UFPF_SROOT              0x40                               //~v5auR~
#define UFPF_SNEW               0x80                               //~v5auR~
#define UFPF_SWILD            0x0100                               //~v5auR~
#define UFPF_TPATHER          0x0200                               //~v5auR~
#define UFPF_SFTER            0x0400                               //~v5auR~
#define UFPF_TFTER            0x0800                               //~v5auR~
#define UFPF_UP               0x1000                               //~v5auR~
#define UFPF_DOWN             0x2000                               //~v5auR~
#define UFPF_RCD              0x4000   //remote  cd cmd issued     //~v5auR~
#define UFPF_LCD              0x8000   //lcd cmd issued            //~v5auR~
#define UFPF_SDIRL          0x010000   //get source dirlist        //~v5auR~
#define UFPF_TDIRL          0x020000   //get target dirlist        //~v5auR~
#define UFPF_DELTGT         0x040000  //delete issued              //~v5auR~
#define UFPF_SUBDIR         0x080000   //subdir                    //~v5auR~
#define UFPF_RENCPY         0x100000  //rename copy                //~v5auR~
#define UFPF_F2FCPY         0x200000  //rename copy                //~v5auR~
#define UFPF_TWILD        0x00800000  //target is wild card        //~v5cjR~
#define UFPF_TTOPDNEW     0x01000000  //source dir not found in target dir//~v5auR~
#define UFPF_TTOPDEXIST   0x02000000  //source dir not found in target dir//~v5auR~
#define UFPF_TTOPDNEWNAME 0x04000000  //rename topdir              //~v5cgI~
#define UFPF_SWILDROOT    0x08000000  //sorce is wildcard root     //~v5cgI~
//*******************************************************
static int  Sr2rflags=0;                                           //~v5cvI~
//static UCHAR Sr2rtmptgt[_MAX_PATH];                                //~v5cvR~//~v6H7R~
static UCHAR Sr2rtmptgt[FTP_MAXPATH];                              //~v6H7R~
//*******************************************************
int uftpxcopyr2r(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,            //~v5azI~
			UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask);//~v5azI~
int uftpupload(char *Psfpath,char *Ptfpath,PUFTPPARM Ppufp);
int uftpdownload(char *Psfpath,char *Ptfpath,PUFTPPARM Ppufp);
//int uftptargetflag(char *Pnode,char *Ptfullpath);                //~v5cgR~
//int uftptargetflag(char *Pnode,char *Ptfullpath,PUFTPPARM Ppufp);//~v5frR~
int uftptargetflag(char *Pnode,char *Ptfullpath,PUFTPPARM Ppufp,FILEFINDBUF3 *Ppfstat3);//~v5frI~
int uftpsourceflag(char *Pnode,char *Psfullpath,FILEFINDBUF3 *Ppfstat3);//~v59rR~
//int uftpcreateparmproc(char *Psfullpath,char *Ptfullpath,int *Ppflag);//~v5cjR~
int uftpcreateparmproc(char *Psfullpath,char *Ptfullpath,int *Ppflag,PUFTPPARM Ppufp);//~v5cjI~
int uftpmoveparmproc(char *Psfullpath,char *Ptfullpath,int *Ppflag,PUFTPPARM Ppufp);//~v5ckI~
int uftpputstmt(PUFTPPARM Ppufp,char *Pcmd,char *Pfnm);
int uftpputstmt2(PUFTPPARM Ppufp,char *Pcmd,char *Pfnm,char *Pfnm2);//~v6H7I~
int uftpupdownctl(PUFTPPARM Ppufp);
int uftperrdir2file(char *Pfnm);
int uftperrtargetisnotdir(char *Pfnm);
int uftperrsourceisroot(void);
FTPCMD_CALLBACK  uftpcopycallback;
int uftpcopyrchk(PUFTPPARM Ppufp,char **Ppstdo,int Pstdoctr);
int uftpexistchk1(PUFTPPARM Ppufp,int *Ppflag);                    //~v59rR~
int uftpexistchkm(PUFTPPARM Ppufp);                                //~v59rR~
int uftpfileanddir(char *Pfnm,char *pdirnm);
int uftpmktdir(PUFTPHOST Ppuftph,int Pflag,char *Ptarget);         //~v5afR~
//int uftpgetdirlist(int Pflag,char *Pdirname,UINT Pattrmask,PUDIRLIST *Pppudl,char Psopt);//~v59rI~//~v6d1R~
int uftpgetdirlist(PUFTPPARM Ppufp,int Pflag,char *Pdirname,UINT Pattrmask,PUDIRLIST *Pppudl,char Psopt);//~v6d1R~
int uftpcopyftime(PUFTPPARM Ppufp);                                //~v59rI~
int uftpappenddir2dir(char *Psdir,char *Ptdir);                    //~v5arI~
//int uftps2tchk(int Popt,int *Ppflag,char *Psource,char *Ptarget);//~v5cjR~
//int uftps2tchk(int Popt,int *Ppflag,char *Psource,char *Ptarget,PUFTPPARM Ppfup);//~v5frR~
int uftps2tchk(int Popt,int *Ppflag,char *Psource,FILEFINDBUF3 *Ppsfstat,char *Ptarget,FILEFINDBUF3 *Pptfstat,PUFTPPARM Ppfup);//~v5frI~
int ufileftpcopytschk(int Popt,char *Psfnm,FDATE Psdate,FTIME Pstime,//~v5frR~
					char *Ptfnm,FDATE Ptdate,FTIME Pttime);        //~v5frI~
#ifdef ARMXXE                                                      //~v6daI~
int uftpsmbj_updowncmd(int Pftpopt,PUFTPPARM Ppufp,PUFTPHOST Ppuftph);//~v6daI~
#endif                                                             //~v6daI~
//**************************************************************** //~v5b6I~
//uxmove                                                           //~v5b6I~
//* FTP(copy and delete)                                           //~v5b6I~
//*retrn:rc                                                        //~v5b6I~
//**************************************************************** //~v5b6I~
int uftpxmove(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,               //~v5b6I~
			UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask)//~v5b6I~
{                                                                  //~v5b6I~
	int rc,procctr=0,delctr=0,ronlyctr=0;                          //~v5b6I~
    UINT attrmask,deldiropt=0;                                     //~v5ckI~
//  UCHAR tgt[_MAX_PATH],*ptgt;                                    //~v5ckI~//~v6H7R~
    UCHAR tgt[FTP_MAXPATH2],*ptgt;                                 //~v6H7I~
//********************                                             //~v5b6I~
//  rc=uftpxcopy(Ppuftphs,Ppuftpht,Psource,Ptarget,Popt,Pattrmask);//~v5ckR~
	attrmask=Pattrmask;                                            //~v5ckI~
    ptgt=Ptarget;                                                  //~v5ckI~
    if (!WILDCARD(Psource))                                        //~v5ckR~
    {                                                              //~v5ckI~
		attrmask|=FILE_DIRECTORY;     //proess subdir              //~v5ckI~
        if (WILDCARD(Ptarget))                                     //~v5ckR~
        {                                                          //~v5ckI~
            ufileeditname(DEN_DEFAULT_UNIX | DEN_DEFAULT_CASE,     //~v5ckI~
							Psource,Ptarget,tgt);    //determin target//~v5ckI~
            ptgt=tgt;                                              //~v5ckI~
        }                                                          //~v5ckI~
    }                                                              //~v5ckI~
    rc=uftpxcopy(Ppuftphs,Ppuftpht,Psource,ptgt,Popt|DCPY_MOVE,attrmask);//~v5ckR~
    if (rc)                                                        //~v5b6I~
    	return rc;                                                 //~v5b6I~
//  rc=uxdelete(Psource,UXDELDIR,UXDELFORCE,&procctr,&ronlyctr,&delctr);//~v5ckR~
    if (attrmask & FILE_DIRECTORY)     //proess subdir             //~v5ckI~
    	deldiropt=UXDELDIR;                                        //~v5ckI~
    rc=uxdelete(Psource,deldiropt,UXDELFORCE,&procctr,&ronlyctr,&delctr);//~v5ckI~
    return rc;                                                     //~v5b6I~
}//uftpxmove                                                       //~v5b6I~//~v6H7R~
//****************************************************************
//uxcopy
//* FTP(one of sorce/target or both is remote file)
//* wildcard target is not supported
//* wildcard source supported for over os/2 DosCopy
//* root dir target support   for over os/2 DosCopy
//* copy    file-->new,file,dir(into dir),support rename           //~v5auI~
//* copy    dir -->new(dir copy into parent dir),dir(dir copy into the dir if top is not samename)//~v5auR~
//* copy    wild-->new(member copy into parent dir),dir(member copy into the dir)//~v5auI~
//* append  file-->new,file,dir(into dir)                          //~v5arI~
//* append  dir -->new(cat),file(cat),dir(append member into dir)  //~v5arI~
//* append  wild-->new(cat),file(cat),dir(append member into dir)  //~v5arI~
//*****
//*parm1:source filename
//*parm2:target filename
//*parm3:replace(01)/append(02)/fail if ea copy fail(04)
//*     :target root support(0x0100)
//*parm4:attribute mask for first level
//*retrn:rc
//****************************************************************
int uftpxcopy(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,               //~v5afR~
			UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask)//~v5afI~
{
//  UCHAR sfullpath[_MAX_PATH],tfullpath[_MAX_PATH];               //~v6H7R~
    UCHAR sfullpath[FTP_MAXPATH],tfullpath[FTP_MAXPATH];           //~v6H7I~
//  char  *remotefnm;                                              //~v5auR~
	PUFTPHOST puftph=NULL;                                              //~v5afI~//~v6h7R~
    int hostnmlent,rc;                                             //~v5b6R~
	UFTPPARM  ufp;
//********************
	memset(&ufp,0,sizeof(ufp));                                    //~v5d8I~
	if (Ppuftphs && Ppuftpht)                                      //~v5azI~
  		return uftpxcopyr2r(Ppuftphs,Ppuftpht,Psource,Ptarget,Popt,Pattrmask);//~v5azI~
	if (Ppuftphs)                                                  //~v5afI~
    {                                                              //~v5afI~
//  	hostnmlens=Ppuftphs->UFTPHhostnmlen;                       //~v5b6R~
        puftph=Ppuftphs;                                           //~v5afI~
    }                                                              //~v5afI~
//  else                                                           //~v5b6R~
//  	hostnmlens=0;                                              //~v5b6R~
	if (Ppuftpht)                                                  //~v5afI~
    {                                                              //~v5afI~
    	hostnmlent=Ppuftpht->UFTPHhostnmlen;                       //~v5afI~
        puftph=Ppuftpht;                                           //~v5afI~
    }                                                              //~v5afI~
    else                                                           //~v5afI~
    	hostnmlent=0;                                              //~v5afI~
                                                                   //~v5afI~
//  if (hostnmlens)                                                //~v5azR~
//  {                                                              //~v5azR~
//      if (hostnmlent) //both remote                              //~v5azR~
//      {                                                          //~v5azR~
//          uerrmsg("FTP between remote(%s and %s) is not supported",0,//~v5azR~
//                  Ppuftphs->UFTPHhost,Ppuftpht->UFTPHhost);      //~v5azR~
//          return 16;                                             //~v5azR~
//      }                                                          //~v5azR~
//      else                                                       //~v5auR~
//      	remotefnm=Psource;                                     //~v5auR~
//  }                                                              //~v5azR~
//  else                                                           //~v5auR~
//      remotefnm=Ptarget;                                         //~v5auR~
//  if (Popt & DCPY_APPEND)            //not append req            //~v5aqR~
//  	return uftpnotsupported("append",remotefnm);               //~v5aqR~
//  if (!ufullpath(sfullpath,Psource,_MAX_PATH))                   //~v6H7R~
    if (!ufullpath(sfullpath,Psource,sizeof(sfullpath)))           //~v6H7I~
        return -1;
//  if (!ufullpath(tfullpath,Ptarget,_MAX_PATH))                   //~v6H7R~
    if (!ufullpath(tfullpath,Ptarget,sizeof(tfullpath)))           //~v6H7I~
        return -1;
//  if (WILDCARD(tfullpath))                                       //~v5cgR~
//  	return ufilewildtarget(-1);                                //~v5cgR~
    ufp.UFPopt=Popt;
  	if (Popt & DCPY_APPEND)            //not append req            //~v5arR~
	    ufp.UFPopt|=DCPY_EXISTING;	//overridde when append        //~v5arI~
    ufp.UFPattrmask=Pattrmask & FILE_ALL;     //drop invalid bit
    ufp.UFPpuftph=puftph;                                          //~v5afI~
	if (hostnmlent)	//source is local,target is remote
    {
    	ufp.UFPssepc=DIR_SEPC;     //source is Win or Unix
    	ufp.UFPtsepc=FTP_DIR_SEPC; //target is unix
		rc=uftpupload(sfullpath,tfullpath,&ufp);
    }
    else
    {
    	ufp.UFPssepc=FTP_DIR_SEPC; //source is Unix
    	ufp.UFPtsepc=DIR_SEPC; 		//target is Win or Unix
		rc=uftpdownload(sfullpath,tfullpath,&ufp);
    }
    return rc;
}//uftpxcopy
//**************************************************************** //~v5azI~
int uftpxcopyr2r(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,            //~v5azI~
			UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask)//~v5azI~
{                                                                  //~v5azI~
//  char tempfnm[_MAX_PATH];                                       //~v5azI~//~v6H7R~
//  char tempfnm0[_MAX_PATH];                                      //~v5cuI~//~v6H7R~
//  char tgt[_MAX_PATH];                                           //~v5cvI~//~v6H7R~
    char tempfnm[FTP_MAXPATH2];                                    //~v6H7I~
    char tempfnm0[FTP_MAXPATH2];                                   //~v6H7I~
    char tgt[FTP_MAXPATH];                                         //~v6H7I~
    int len,rc,opt,srcfnmsw=0;                                     //~v5cvR~
//*************************                                        //~v5azI~
	if (uftpmktempwd(tempfnm))                                     //~v5b1I~
    	return -1;                                                 //~v5b1I~
    strcpy(tempfnm0,tempfnm);                                      //~v5cuI~
    strcpy(tgt,Ptarget);                                           //~v5cvI~
//  rc=uftpxcopy(Ppuftphs,0,Psource,tempfnm,Popt,Pattrmask);       //~v5cvR~
    opt=Popt & ~DCPY_APPEND;                                       //~v5cvI~
    rc=uftpxcopy(Ppuftphs,0,Psource,tempfnm,opt,Pattrmask);        //~v5cvI~
    if (!rc)                                                       //~v5azI~
    {                                                              //~v5azI~
//  	len=strlen(tempfnm);                                       //~v5azI~//~v6D0R~
    	len=(int)strlen(tempfnm);                                  //~v6D0I~
        if (Sr2rflags & UFPF_SFILE)	//filename should be append; \tempd\fnm//~v5cvI~
        	srcfnmsw=1;                                            //~v5cvI~
        else                                                       //~v5cvI~
        if (Popt & DCPY_MOVE)                                      //~v5cvI~
        	srcfnmsw=1;     //may append wild card                 //~v5cvI~
//    if (WILDCARD(Psource)                                        //~v5cvI~
//  	strcpy(tempfnm+len,FTP_DIR_SEPS FTP_DIR_ALLMEMB);          //~v5cvR~
//    else                                                         //~v5cvR~
	  if (srcfnmsw)                                                //~v5cvI~
      {                                                            //~v5b8I~
//  	*(tempfnm+len++)=FTP_DIR_SEPC;                             //~v5cvR~
    	*(tempfnm+len++)=DIR_SEPC;                                 //~v5cvI~
    	strcpy(tempfnm+len,Psource+PATHLEN(Psource));              //~v5b8I~
      }                                                            //~v5b8I~
      else                                                         //~v5cvI~
      	strcpy(tempfnm,Sr2rtmptgt);//dir name padding when /C option or Move//~v5cvI~
		rc=uftpxcopy(0,Ppuftpht,tempfnm,tgt,Popt,Pattrmask);       //~v5cvR~
    }                                                              //~v5azI~
	rc+=uftpdeltempwd(tempfnm0);                                   //~v5cuR~
    return rc;                                                     //~v5azI~
}//uftpxcopyr2r                                                    //~v5azI~
//****************************************************************
//uftpwinupload
//* p1:source local fullpathname
//* p2:target remote fullpathname(with hostname:)
//*retrn:rc
//****************************************************************
int uftpupload(char *Psfullpath,char *Ptfullpath,PUFTPPARM Ppufp)
{
    int flag,rc,opt;                                               //~v5aqR~
//  int flagi,flagt,flags,tmpdirsw=0,templen;                      //~v5cjR~//~v6h7R~
    int flagi,flagt,flags,tmpdirsw=0,templen=0;                    //~v6h7I~
    FILEFINDBUF3 fstat3;                                           //~v59rI~
    FILEFINDBUF3 fstat3t;                                          //~v5frI~
    PUFTPHOST puftph;                                              //~v5afI~
//  char tempfnm[_MAX_PATH],*psfpath=NULL;                              //~v5cjI~//~v6h7R~//~v6H7R~
//  char orgsrc[_MAX_PATH];                                        //~v5cjI~//~v6H7R~
//  char orgtgt[_MAX_PATH];                                        //~v5cjI~//~v6H7R~
    char tempfnm[_MAX_PATH2],*psfpath=NULL;                        //~v6H7I~
    char orgsrc[_MAX_PATH2];                                       //~v6H7I~
    char orgtgt[FTP_MAXPATH];                                      //~v6H7I~
//********************
	strcpy(orgtgt,Ptfullpath);	//save org target                  //~v5cjI~
    strcpy(orgsrc,Psfullpath);                                     //~v5cjI~
    opt=Ppufp->UFPopt;                                             //~v5aqR~
	puftph=Ppufp->UFPpuftph;                                       //~v5afI~
	flag=UFPF_UP;                                                  //~v5auI~
//  flag|=uftptargetflag(puftph->UFTPHhost,Ptfullpath);//win file  //~v5cgR~
//  flag|=uftptargetflag(puftph->UFTPHhost,Ptfullpath,Ppufp);//win file//~v5cjR~
//  flagt=uftptargetflag(puftph->UFTPHhost,Ptfullpath,Ppufp);//win file//~v5frR~
    flagt=uftptargetflag(puftph->UFTPHhost,Ptfullpath,Ppufp,&fstat3t);//win file//~v5frI~
//  flag|=uftpsourceflag(0,Psfullpath,&fstat3);//win file          //~v5cjR~
//  flagit=flag;                                                   //~v5cjR~
    flags=uftpsourceflag(0,Psfullpath,&fstat3);//win file          //~v5cjI~
#ifdef W32       //windows find case insensitively                 //~v5daR~
    if (!(flags & UFPF_SNEW))	//src found                        //~v5daR~
    {                                                              //~v5daR~
      if (!(flags & UFPF_SWILD))	//src found                    //~v5jhI~
        if (strcmp(fstat3.cFileName,Psfullpath+PATHLEN(Psfullpath)))//~v5daR~
        {                                                          //~v5daR~
//      	uerrmsg("%s NotFound(CaseUnmatch)",0,                  //~v5jhR~
//      			fstat3.cFileName);                             //~v5jhR~
        	uerrmsg("%s found,but %s not found(CaseUnmatch)",0,    //~v5jhI~
        			fstat3.cFileName,Psfullpath+PATHLEN(Psfullpath));//~v5jhI~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
	    	flags|=UFPF_SNEW;	//src not found                    //~v5daR~
        }                                                          //~v5daR~
    }                                                              //~v5daR~
#endif                                                             //~v5daR~
    flagi=flag;                                                    //~v5cjI~
//  flag|=flags;                                                   //~v5cjR~
    flag|=(flags|flagt);                                           //~v5cjI~
#ifdef UNX                                                         //~v5d5I~
    if (flag & UFPF_SWILDROOT)                                     //~v5d5I~
    {                                                              //~v5d5I~
    	if (opt  & DCPY_MOVE)                                      //~v5d5I~
    	{                                                          //~v5d5I~
        	uerrmsg("Move one by one for object on remote root dir",//~v5d5I~
            	    "リモートのルートDirのオブジェクトは一つ一つ移動してください");//~v5d5I~
        	return 4;                                              //~v5d5I~
    	}                                                          //~v5d5I~
    }                                                              //~v5d5I~
#endif                                                             //~v5d5I~
    if (flag & UFPF_SROOT) //dosfindfirst fail if root
    {
        if (opt &  DCPY_MOVE)                                      //~v5ckM~
    	    return ufileroot(Psfullpath,4);                        //~v5ckR~
#ifdef UNX
        return uftperrsourceisroot();
#else
        if (flag & UFPF_TROOT)	//target root
        {

            if (!(Ppufp->UFPopt & DCPY_ROOT))
            {
                uerrmsg("Option required when root to root",
                        "ルート間コピーはオプションが必要です");
                return -1;
            }
        }
        strcpy(Psfullpath+3,DIR_ALLMEMB);
    	flag|=UFPF_SWILD;
    	flag|=UFPF_SWILDROOT;        //source wild card            //~v5ciI~
    	flag&=~UFPF_SROOT;
#endif
    }//source is root
//  if (uftps2tchk(opt,&flag,Psfullpath,Ptfullpath))               //~v5cjR~
//  if (uftps2tchk(opt,&flag,Psfullpath,Ptfullpath,Ppufp))         //~v5frR~
    if (uftps2tchk(opt,&flag,Psfullpath,&fstat3,Ptfullpath,&fstat3t,Ppufp))//~v5frI~
    	return -1;                                                 //~v5auI~
    if (flag & UFPF_TWILD)  //target wildcard is dropped,and saved to twildmask//~v5cjI~
    {                                                              //~v5cjI~
    	tmpdirsw=1;//copy/append later from temp dir               //~v5cjI~
		if (uftpmktempwd(tempfnm))                                 //~v5cjI~
    		return -1;                                             //~v5cjI~
        psfpath=tempfnm;                                           //~v5cjI~
//  	templen=strlen(psfpath);                                   //~v5cjI~//~v6D0R~
    	templen=(int)strlen(psfpath);                              //~v6D0I~
        *(psfpath+templen)=DIR_SEPC;                               //~v5cjI~
        strcpy(psfpath+templen+1,Ppufp->UFPtwildmask);//append target wild card//~v5cjI~
//      rc=uxcopy(Psfullpath,psfpath,opt,Ppufp->UFPattrmask);   //rename by wildcard//~v5cjI~//~v6D1R~
        rc=uxcopy(Psfullpath,psfpath,opt,(unsigned)(Ppufp->UFPattrmask));   //rename by wildcard//~v6D1I~
        if (!rc)                                                   //~v5cjI~
        {                                                          //~v5cjI~
            *(psfpath+templen)=0;   //tempdir name                 //~v5cjR~
            if (opt & DCPY_CREATE) //srcdir is created intempdir   //~v5cjR~
            {                                                      //~v5cjR~
                *(psfpath+templen)=DIR_SEPC;                       //~v5cjR~
                if (flag & UFPF_SWILD)                             //~v5cjR~
                    strcpy(psfpath+templen+1,Ppufp->UFPswildpdir);//wildcard parent dir//~v5cjR~
                else                                               //~v5cjR~
                    strcpy(psfpath+templen+1,Psfullpath+PATHLEN(Psfullpath));//~v5cjR~
            }                                                      //~v5cjR~
            else                                                   //~v5cjR~
            if (opt & DCPY_MOVE) //srcdir is wildcard(if not,already target changed)//~v5ckI~
            {                                                      //~v5ckI~
                *(psfpath+templen)=DIR_SEPC;                       //~v5ckI~
                strcpy(psfpath+templen+1,DIR_ALLMEMB);//avoid tmp dirname craeteion on tgt//~v5ckR~
            }                                                      //~v5ckI~
            else                                                   //~v5ckI~
            if (flag & UFPF_SFILE)  //source is file               //~v5cjR~
            {                                                      //~v5cjR~
                *(psfpath+templen)=DIR_SEPC;                       //~v5cjR~
                strcpy(psfpath+templen+1,DIR_ALLMEMB);             //~v5cjR~
            }                                                      //~v5cjR~
            strcpy(Ptfullpath,orgtgt);  //save org target          //~v5cjR~
//          flagt=uftptargetflag(puftph->UFTPHhost,Ptfullpath,Ppufp);//win file//~v5frR~
            flagt=uftptargetflag(puftph->UFTPHhost,Ptfullpath,Ppufp,&fstat3t);//win file//~v5frI~
            flags=uftpsourceflag(0,psfpath,&fstat3);//win file     //~v5cjR~
            flag=(flagi|flags|flagt);                              //~v5cjR~
//          if (uftps2tchk(opt,&flag,psfpath,Ptfullpath,Ppufp))    //~v5frR~
            if (uftps2tchk(opt,&flag,psfpath,&fstat3,Ptfullpath,&fstat3t,Ppufp))	//date chk by original file timestamp//~v5frI~
                rc=-1;                                             //~v5cjR~
            strcpy(Psfullpath,psfpath);                            //~v5cjR~
        }                                                          //~v5cjI~
    }//target wild                                                 //~v5cjI~
    else                                                           //~v5cjI~
    	rc=0;                                                      //~v5cjI~
 if (!rc)                                                          //~v5cjR~
 {                                                                 //~v5cjI~
    Ppufp->UFPtpathlen=(int)FTP_PATHLEN(Ptfullpath)-1;             //~v59rR~
    Ppufp->UFPspathlen=(int)PATHLEN(Psfullpath)-1;
    Ppufp->UFPsfpath=Psfullpath;
    Ppufp->UFPtfpath=Ptfullpath;
    Ppufp->UFPflag=flag;
    Ppufp->UFPsfstat3=&fstat3;                                     //~v59rI~
    rc=uftpupdownctl(Ppufp);
  }                                                                //~v5cjI~
  	if (tmpdirsw)                                                  //~v5cjR~
  	{                                                              //~v5cjI~
        *(psfpath+templen)=0;	//tempdir name                     //~v5cjI~
		uftpdeltempwd(psfpath);                                    //~v5cjR~
        strcpy(Psfullpath,orgsrc);                                 //~v5cjI~
    }                                                              //~v5cjI~
    return rc;
}//uftpupload
//****************************************************************
//download to wind
//* p1:source remote fullpathname(with hostname:)
//* p2:target local fullpathname
//*retrn:rc
//****************************************************************
int uftpdownload(char *Psfullpath,char *Ptfullpath,PUFTPPARM Ppufp)
{
    int flag,rc,opt,tmpdirsw,templen;                              //~v5bkR~
    int flags,flagt,flagi;                                         //~v5cjI~
    FILEFINDBUF3 fstat3;                                           //~v59rI~
    FILEFINDBUF3 fstat3t;                                          //~v5frI~
    PUFTPHOST puftph;                                              //~v5afI~
//  char tempfnm[_MAX_PATH],*ptfpath;                              //~v5aqI~//~v6H7R~
//  char orgtgt[_MAX_PATH];                                        //~v5cjI~//~v6H7R~
    char tempfnm[FTP_MAXPATH],*ptfpath;                            //~v6H7I~
    char orgtgt[FTP_MAXPATH];                                      //~v6H7I~
//********************
	strcpy(orgtgt,Ptfullpath);	//before drop wildcard             //~v5cjI~
    opt=Ppufp->UFPopt;                                             //~v5aqR~
	puftph=Ppufp->UFPpuftph;                                       //~v5afI~
    flag=UFPF_DOWN;                                                //~v5auI~
    flagi=flag;                                                    //~v5cjI~
//  flag|=uftptargetflag(0,Ptfullpath);//file                      //~v5cgR~
//  flag|=uftptargetflag(0,Ptfullpath,Ppufp);//file                //~v5cjR~
//  flagt=uftptargetflag(0,Ptfullpath,Ppufp);//file                //~v5frR~
    flagt=uftptargetflag(0,Ptfullpath,Ppufp,&fstat3t);//file       //~v5frI~
//  flag|=uftpsourceflag(puftph->UFTPHhost,Psfullpath,&fstat3);//win file//~v5cjR~
    flags=uftpsourceflag(puftph->UFTPHhost,Psfullpath,&fstat3);//win file//~v5cjI~
	Sr2rflags=flags;                                               //~v5cvI~
    flag|=(flags|flagt);                                           //~v5cjI~
    if (flag & UFPF_SROOT)
//  	return uftperrsourceisroot();                              //~v5ckR~
    	return ufileroot(Psfullpath,4);                            //~v5ckI~
    if (flag & UFPF_SWILDROOT)                                     //~v5cqI~
    if (opt  & DCPY_MOVE)                                          //~v5cuI~
    {                                                              //~v5cqI~
        uerrmsg("Move one by one for object on remote root dir",   //~v5cqI~
                "リモートのルートDirのオブジェクトは一つ一つ移動してください");//~v5cqI~
        return 4;                                                  //~v5cqI~
    }                                                              //~v5cqI~
//  if (uftps2tchk(opt,&flag,Psfullpath,Ptfullpath))               //~v5cjR~
//  if (uftps2tchk(opt,&flag,Psfullpath,Ptfullpath,Ppufp))         //~v5frR~
    if (uftps2tchk(opt,&flag,Psfullpath,&fstat3,Ptfullpath,&fstat3t,Ppufp))//~v5frI~
    	return -1;                                                 //~v5auI~
    strcpy(Sr2rtmptgt,Ptfullpath);//src dir may edit               //~v5cvR~
    if (opt & DCPY_FTP2TEMPF)                                      //~v6H7I~
    {                                                              //~v6H7I~
    	tmpdirsw=0;                                                //~v6H7I~
        ptfpath=Ptfullpath;                                        //~v6H7I~
    }                                                              //~v6H7I~
    else	//copy                                                 //~v6H7I~
  	if (opt & DCPY_APPEND            //not append req              //~v5auR~
    ||  flag & UFPF_TWILD                                          //~v5cjI~
    ||  flag & UFPF_RENCPY)                                        //~v5auR~
    {                                                              //~v5aqI~
	    Ppufp->UFPopt&=~DCPY_APPEND;            //copy to temp     //~v5aqI~
    	tmpdirsw=1;//copy/append later from temp dir               //~v5bkR~
//  	if (!(flag & UFPF_RENCPY))                                 //~v5bkR~
//      	flag|=UFPF_TDIR|UFPF_TTOPDNEW;                         //~v5cjR~
//  	flag&=~(UFPF_TNEW|UFPF_RENCPY|UFPF_F2FCPY);                //~v5cjR~
		if (uftpmktempwd(tempfnm))                                 //~v5b1I~
    		return -1;                                             //~v5b1I~
        ptfpath=tempfnm;                                           //~v5aqI~
//  	flagt=uftptargetflag(0,ptfpath,Ppufp);//file               //~v5frR~
    	flagt=uftptargetflag(0,ptfpath,Ppufp,&fstat3t);//file      //~v5frI~
        flag=flagi|flags|flagt;                                    //~v5cjI~
//  	if (uftps2tchk(opt,&flag,Psfullpath,ptfpath))              //~v5cjR~
//  	if (uftps2tchk(opt,&flag,Psfullpath,ptfpath,Ppufp))        //~v5frR~
    	if (uftps2tchk(opt,&flag,Psfullpath,&fstat3,ptfpath,&fstat3t,Ppufp))//~v5frI~
    		return -1;                                             //~v5cjI~
    }                                                              //~v5aqI~
    else	//copy                                                 //~v5aqI~
    {                                                              //~v5aqI~
    	tmpdirsw=0;                                                //~v5bkR~
        ptfpath=Ptfullpath;                                        //~v5aqI~
    }                                                              //~v5aqI~
    Ppufp->UFPspathlen=FTP_PATHLEN(Psfullpath)-1;
//  Ppufp->UFPtpathlen=(int)PATHLEN(Ptfullpath)-1;                 //~v5aqR~
    Ppufp->UFPtpathlen=(int)PATHLEN(ptfpath)-1;                    //~v5aqI~
    Ppufp->UFPsfpath=Psfullpath;
//  Ppufp->UFPtfpath=Ptfullpath;                                   //~v5aqR~
    Ppufp->UFPtfpath=ptfpath;                                      //~v5aqI~
    Ppufp->UFPflag=flag;
    Ppufp->UFPsfstat3=&fstat3;                                     //~v59rI~
    rc=uftpupdownctl(Ppufp);
    if (!rc                                                        //~v5d9I~
    &&  !Ppufp->UFPcmdctr                                          //~v5d9I~
    &&  !Ppufp->UFPsubdirctr)                                      //~v5d9I~
        rc=ufileerrnoentry(Psfullpath,ENOENT);                     //~v5d9R~
    if (!rc && tmpdirsw)                                           //~v5bkR~
    {                                                              //~v5aqI~
//  	templen=strlen(ptfpath);                                   //~v5aqI~//~v6D0R~
    	templen=(int)strlen(ptfpath);                              //~v6D0I~
      if (opt & DCPY_MOVE) //src is wildcard(if not,already nameedit end)//~v5ckI~
      {                                                            //~v5ckI~
        	*(ptfpath+templen)=DIR_SEPC;                           //~v5ckI~
      	if (flag & UFPF_SFILE)	//member copy(sdir->tmpdir->tgtdiir)//~v5d6R~
	        strcpy(ptfpath+templen+1,Psfullpath+Ppufp->UFPspathlen+1);//~v5d6I~
        else                                                       //~v5d6I~
            strcpy(ptfpath+templen+1,DIR_ALLMEMB);//avoid tmp dirname craeteion on tgt//~v5ckR~
      }                                                            //~v5ckI~
      else                                                         //~v5ckI~
      if (!(opt & DCPY_CREATE))	//srcdir is added to taget when create//~v5cjR~
      {                                                            //~v5cjI~
      if (!(flag & UFPF_SDIR))	//member copy(sdir->tmpdir->tgtdiir)//~v5cjI~
      {                                                            //~v5cjI~
        *(ptfpath+templen)=DIR_SEPC;                               //~v5aqR~
        strcpy(ptfpath+templen+1,Psfullpath+Ppufp->UFPspathlen+1); //~v5aqR~
      }                                                            //~v5cjI~
      }                                                            //~v5cjI~
        strcpy(Ptfullpath,orgtgt);                                 //~v5cjM~
//      rc=uxcopy(ptfpath,Ptfullpath,opt,Ppufp->UFPattrmask);      //~v5aqR~//~v6D1R~
        rc=uxcopy(ptfpath,Ptfullpath,opt,(unsigned)(Ppufp->UFPattrmask));//~v6D1I~
        *(ptfpath+templen)=0;	//tempdir name                     //~v5aqI~
//  	uftpdeltempwd(ptfpath);                                    //~v5d9R~
    }//append                                                      //~v5aqI~
    if (tmpdirsw)                                                  //~v5d9I~
    	uftpdeltempwd(ptfpath);                                    //~v5d9I~
    return rc;
}//uftpdownload
//****************************************************************
//!uftptargetflag
//*retrn:flag
//****************************************************************
//int uftptargetflag(char *Pnode,char *Ptfullpath)                 //~v5cgR~
//int uftptargetflag(char *Pnode,char *Ptfullpath,PUFTPPARM Ppufp) //~v5frR~
int uftptargetflag(char *Pnode,char *Ptfullpath,PUFTPPARM Ppufp,FILEFINDBUF3 *Ppfstat3)//~v5frI~
{
	FILEFINDBUF3 fstat3;
//  int flag=0,rc;                                                 //~v6h6R~
    int flag=0,rc=0;                                               //~v6h6I~
    int tpathlen=0;                                                  //~v5cjI~//~v6h6R~
//*****************
	memset(&fstat3,0,sizeof(fstat3));                              //~v6h6R~
    if (WILDCARD(Ptfullpath))                                      //~v5cjR~
    {                                                              //~v5cjI~
    	tpathlen=(int)PATHLEN(Ptfullpath);                         //~v5cjI~
        strcpy(Ppufp->UFPtwildmask,Ptfullpath+tpathlen);           //~v5cjI~
        *(Ptfullpath+tpathlen)=0;	//drop wild card with alst sepc for root chk//~v5cjI~
	    flag|=UFPF_TWILD;                                          //~v5cjR~
    }                                                              //~v5cjI~
	if (Pnode)      //remote(unix)
    {
	    if (FTP_ROOTDIR(Ptfullpath+(strlen(Pnode))+1))
	        flag|=UFPF_TROOT;
        else
        {                                                          //~v5cjI~
	    	if (flag & UFPF_TWILD)                                 //~v5cjR~
		        *(Ptfullpath+tpathlen-1)=0;	//drop seperater       //~v5cjI~
//      	rc=ufstat(Ptfullpath,&fstat3); //not found             //~v6D0R~
        	rc=(int)ufstat(Ptfullpath,&fstat3); //not found        //~v6D0I~
        }                                                          //~v5cjI~
    }
    else            //local
    {
    	if (ROOTDIR_LOCAL(Ptfullpath))                             //~v59rR~
	        flag|=UFPF_TROOT;
        else
        {                                                          //~v5cjI~
	    	if (flag & UFPF_TWILD)                                 //~v5cjR~
		        *(Ptfullpath+tpathlen-1)=0;                        //~v5cjI~
//  	    rc=ufstat(Ptfullpath,&fstat3); //not found             //~v6D0R~
    	    rc=(int)ufstat(Ptfullpath,&fstat3); //not found        //~v6D0I~
        }                                                          //~v5cjI~
    }
	if (!(flag & UFPF_TROOT))
    {
        if (rc)
        {                                                          //~v5arI~
          if (flag & UFPF_TWILD)                                   //~v5cjI~
            flag|=UFPF_TPATHER;                                    //~v5cjI~
          else                                                     //~v5cjI~
          {                                                        //~v5cjI~
#ifdef W32                                                         //~v5auI~
//        if (rc==ERROR_PATH_NOT_FOUND)                            //~v5d4R~
          if (rc==ERROR_PATH_NOT_FOUND	//local                    //~v5d4I~
          ||  rc==ENOTDIR)              //remote                   //~v5d4I~
#else                                                              //~v5auI~
          if (rc==ENOTDIR)                                         //~v5arR~
#endif                                                             //~v5auI~
            flag|=UFPF_TPATHER;                                    //~v5arI~
          else                                                     //~v5arI~
            flag|=UFPF_TNEW;
          }                                                        //~v5cjI~
        }                                                          //~v5arI~
        else
        if (UCBITCHK(fstat3.attrFile,FILE_DIRECTORY))//target dir
            flag|=UFPF_TDIR;
        else
        if (fstat3.attrFile & FILE_SPECIAL)                        //~v5auR~
            flag|=UFPF_TFTER;   //filetype err                     //~v5auI~
        else                                                       //~v5auI~
            flag|=UFPF_TFILE;
    }
    memcpy(Ppfstat3,&fstat3,sizeof(fstat3));                       //~v5frI~
    return flag;
}//uftptargetflag
//****************************************************************
//!uftpsourceflag
//*retrn:flag
//****************************************************************
int uftpsourceflag(char *Pnode,char *Psfullpath,FILEFINDBUF3 *Ppfstat3)//~v59rR~
{
    int flag=0,rc;
    int spathlen;                                                  //~v5cgI~
//  UCHAR srcdir[_MAX_PATH];                                       //~v5cgI~//~v6H7R~
    UCHAR srcdir[FTP_MAXPATH];                                     //~v6H7I~
//*****************
    if (WILDCARD(Psfullpath))         //source wild card
    {                                                              //~v5cgI~
//      if (rc=ufstat(Psfullpath,Ppfstat3),rc)                     //~v5cgM~//~v6D0R~
        if (rc=(int)ufstat(Psfullpath,Ppfstat3),rc)                //~v6D0I~
        {                                                          //~v5cgM~
          if (rc==ERROR_PATH_NOT_FOUND) //local                    //~v6dkR~
	    	ufilepatherr(Psfullpath,rc);                           //~v6dkI~
          else                                                     //~v6dkI~
            ufilenotfound(Psfullpath,rc);                          //~v5cgM~
        	return UFPF_SNEW;                                      //~v5cgM~
        }                                                          //~v5cgM~
        spathlen=PATHLEN(Psfullpath);                              //~v5cgI~
        memcpy(srcdir,Psfullpath,(UINT)spathlen);//with last dirsepc//~v5cgI~
        *(srcdir+spathlen)=0;                                      //~v5cgR~
    	if (Pnode)                                                 //~v5cgI~
        {                                                          //~v5cgI~
	    	if (FTP_ROOTDIR(srcdir+strlen(Pnode)+1))               //~v5cgR~
		    	return UFPF_SWILD|UFPF_SWILDROOT;                  //~v5cgI~
        }                                                          //~v5cgI~
        else                                                       //~v5cgI~
        {                                                          //~v5cgI~
	    	if (ROOTDIR_LOCAL(srcdir))                             //~v5cgI~
		    	return UFPF_SWILD|UFPF_SWILDROOT;                  //~v5cgI~
        }                                                          //~v5cgI~
    	return UFPF_SWILD;
	}                                                              //~v5cgI~

	if (Pnode)
    {
	    if (FTP_ROOTDIR(Psfullpath+strlen(Pnode)+1)) //dosfindfirst fail if root
        	flag|=UFPF_SROOT;
    }
    else                   //local
    {
    	if (ROOTDIR_LOCAL(Psfullpath))                             //~v59rR~
        	flag|=UFPF_SROOT;
    }
    if (!(flag & UFPF_SROOT))
    {
//      if (rc=ufstat(Psfullpath,Ppfstat3),rc)                     //~v59rR~//~v6D0R~
        if (rc=(int)ufstat(Psfullpath,Ppfstat3),rc)                //~v6D0I~
        {
          if (rc==ERROR_PATH_NOT_FOUND) //local                    //~v6dkI~
	    	ufilepatherr(Psfullpath,rc);                           //~v6dkI~
          else                                                     //~v6dkI~
            ufilenotfound(Psfullpath,rc);                          //~v5auR~
        	flag|=UFPF_SNEW;
        }
        else
        if (Ppfstat3->attrFile & FILE_DIRECTORY)                   //~v59rR~
            flag|=UFPF_SDIR;
        else
        if (Ppfstat3->attrFile & FILE_SPECIAL)                     //~v5auI~
            flag|=UFPF_SFTER;   //filetype err                     //~v5auI~
        else                                                       //~v5auI~
            flag|=UFPF_SFILE;
    }//src is not root
    return flag;
}//uftpsourceflag
//**************************************************************** //~v5auI~
//uftps2tchk                                                       //~v5auI~
// source and target combination chk                               //~v5auI~
//*retrn:rc                                                        //~v5auI~
//**************************************************************** //~v5auI~
//int uftps2tchk(int Popt,int *Ppflag,char *Psource,char *Ptarget) //~v5cjR~
//int uftps2tchk(int Popt,int *Ppflag,char *Psource,char *Ptarget,PUFTPPARM Ppufp)//~v5frR~
int uftps2tchk(int Popt,int *Ppflag,char *Psource,FILEFINDBUF3 *Ppfstat3s,char *Ptarget,FILEFINDBUF3 *Ppfstat3t,PUFTPPARM Ppufp)//~v5frR~
{                                                                  //~v5auI~
	int flag,rc2,len,rc;                                           //~v5ckR~
    FILEFINDBUF3 fstat3;                                           //~v5auI~
    char *pfnms,*pfnmt;                                            //~v5auR~
//  char tgt[_MAX_PATH];                                           //~v5auI~//~v6H7R~
    char tgt[FTP_MAXPATH];                                         //~v6H7I~
//********************                                             //~v5auI~
	flag=*Ppflag;                                                  //~v5auI~
    if (flag & UFPF_SNEW)                                          //~v5auM~
    	return -1;                                                 //~v5auM~
    if (flag & UFPF_TPATHER)                                       //~v5auM~
    	return  ufilepatherr(Ptarget,-1);                          //~v5auI~
    if (flag & UFPF_SFTER)                                         //~v5auI~
    	return  ufileerrspecialfile(Psource,-1);                   //~v5auI~
    if (flag & UFPF_TFTER)                                         //~v5auI~
    	return  ufileerrspecialfile(Ptarget,-1);                   //~v5auI~
	if (Popt & DCPY_APPEND)//for append,no exist chk and dir->file is ok//~v5auI~
    	return 0;                                                  //~v5auI~
    if (Popt & DCPY_CREATE)                                        //~v5cgI~
    {                                                              //~v5cgI~
//     	if (uftpcreateparmproc(Psource,Ptarget,&flag))             //~v5cjR~
       	if (uftpcreateparmproc(Psource,Ptarget,&flag,Ppufp))       //~v5cjI~
        	return -1;                                             //~v5cgI~
    }                                                              //~v5cgI~
    if (Popt & DCPY_MOVE)                                          //~v5ckI~
    {                                                              //~v5ckI~
       	if (uftpmoveparmproc(Psource,Ptarget,&flag,Ppufp)>1)       //~v5ckR~
        	return -1;                                             //~v5ckI~
    }                                                              //~v5ckI~
    if (flag & UFPF_SFILE)	//source is file                       //~v5auI~
    {                                                              //~v5auI~
        if (flag & (UFPF_TFILE|UFPF_TNEW))                         //~v5auR~
        {                                                          //~v5auR~
            flag|=UFPF_F2FCPY;  //rename copy                      //~v5auR~
            pfnms=Psource+PATHLEN(Psource);                        //~v5auR~
            pfnmt=Ptarget+PATHLEN(Ptarget);                        //~v5auR~
#ifdef W32                                                         //~v5auI~
            if (flag & UFPF_DOWN)                                  //~v5auR~
                rc2=stricmp(pfnms,pfnmt);                          //~v5auR~
            else                                                   //~v5auR~
#endif                                                             //~v5auI~
                rc2=strcmp(pfnms,pfnmt);                           //~v5auR~
            if (rc2)    //unmatch                                  //~v5auR~
                flag|=UFPF_RENCPY;  //rename copy                  //~v5auR~
            if (flag & UFPF_TFILE)  //existing                     //~v5auR~
            {                                                      //~v5frI~
                if (!(Popt & DCPY_EXISTING))    //copy without replace opt//~v5auR~
                {                                                  //~v5ckI~
                	if (Popt & DCPY_SKIPEXIST)       //skip override//~v5fgR~
    	        		return DCPY_RC_NOTCOPY;                    //~v5fgR~
//                  return ufileexist(Ptarget,-1);                 //~v5cdR~
                    return ufileexistcopy(Ptarget,-1);             //~v5cdI~
                }                                                  //~v5ckI~
                else	//rep option                               //~v5frI~
                {                                                  //~v5frI~
			    	if (Popt & DCPY_REPOLD)	//not force override   //~v5frI~
			            if (ufileftpcopytschk(Popt,Psource,        //~v5frI~
							Ppfstat3s->fdateLastWrite,Ppfstat3s->ftimeLastWrite,//~v5frR~
							Ptarget,Ppfstat3t->fdateLastWrite,Ppfstat3t->ftimeLastWrite)<=0)//~v5frR~
							return DCPY_RC_NOTCOPY;                //~v5frI~
                }                                                  //~v5frI~
            }                                                      //~v5frI~
        }                                                          //~v5auR~
        else    //target is root or dir                            //~v5auI~
        {                                                          //~v5auI~
//          len=strlen(Ptarget);                                   //~v5auI~//~v6D0R~
            len=(int)strlen(Ptarget);                              //~v6D0I~
            memcpy(tgt,Ptarget,(UINT)len);                         //~v5auI~
            if (!(flag & UFPF_TROOT))                              //~v5auI~
            {                                                      //~v5auI~
                if (flag & UFPF_UP)                                //~v5auI~
                    *(tgt+len++)=FTP_DIR_SEPC;                     //~v5auI~
                else                                               //~v5auI~
                    *(tgt+len++)=DIR_SEPC;                         //~v5auI~
            }                                                      //~v5auI~
            strcpy(tgt+len,Psource+PATHLEN(Psource));              //~v5auI~
//          rc=ufstat(tgt,&fstat3); //not found                    //~v5auI~//~v6D0R~
            rc=(int)ufstat(tgt,&fstat3); //not found               //~v6D0I~
            if (!rc)                                               //~v5auI~
            {                                                      //~v5auI~
                if (fstat3.attrFile & FILE_DIRECTORY)              //~v5auI~
                    return uftpfileanddir(Psource,tgt);            //~v5auI~
                if (!(Popt & DCPY_EXISTING))    //copy without replace opt//~v5auI~
                {                                                  //~v5ckI~
                	if (Popt & DCPY_SKIPEXIST)       //skip override//~v5fgR~
    	        		return 0;                                  //~v5fgR~
//                  return ufileexist(tgt,-1);                     //~v5cdR~
                    return ufileexistcopy(tgt,-1);                 //~v5cdI~
                }                                                  //~v5ckI~
                else	//rep option                               //~v5frI~
                {                                                  //~v5frI~
			    	if (Popt & DCPY_REPOLD)	//not force override   //~v5frI~
			            if (ufileftpcopytschk(Popt,Psource,        //~v5frI~
											Ppfstat3s->fdateLastWrite,Ppfstat3s->ftimeLastWrite,//~v5frR~
			        					    tgt,fstat3.fdateLastWrite,fstat3.ftimeLastWrite)<=0)//~v5frR~
							return DCPY_RC_NOTCOPY;                //~v5frI~
                }                                                  //~v5frI~
            }                                                      //~v5auI~
        }// target is root or dir                                  //~v5auI~
    }                                                              //~v5auI~
    else                  //source is dir/wild/root                //~v5auI~
    {                                                              //~v5auI~
        if (flag & UFPF_TFILE)                                     //~v5auR~
//          return uftpfileanddir(Ptarget,Psource);                //~v5d8R~
            return ufileerrdir2file(-1);                           //~v5d8I~
//      if (flag & UFPF_SDIR)	//source is dir                    //~v5cgR~
//      {                                                          //~v5cgR~
//      	if (!(flag & UFPF_TNEW))	//source is dir            //~v5cgR~
//          {                                                      //~v5cgR~
//              if (flag & UFPF_TDIR)   //dir to dir               //~v5cgR~
//              {                                                  //~v5cgR~
//                  pfnms=Psource+PATHLEN(Psource);                //~v5cgR~
//                  pfnmt=Ptarget+PATHLEN(Ptarget);                //~v5cgR~
//#ifdef W32                                                       //~v5cgR~
//                  if (flag & UFPF_DOWN)                          //~v5cgR~
//                      rc2=stricmp(pfnms,pfnmt);                  //~v5cgR~
//                  else                                           //~v5cgR~
//#endif                                                           //~v5cgR~
//                      rc2=strcmp(pfnms,pfnmt);                   //~v5cgR~
//                  if (!rc2)    //same name                       //~v5cgR~
//                  {                                              //~v5cgR~
//                      *(pfnmt-1)=0;          //same name dir to dir//~v5cgR~
//                      flag|=UFPF_TTOPDEXIST; //same name dir to dir//~v5cgR~
//                      samenamesw=1;                              //~v5cgR~
//                  }                                              //~v5cgR~
//              }//target is dir                                   //~v5cgR~
//              if (!samenamesw)                                   //~v5cgR~
//              {                                                  //~v5cgR~
//                    len=strlen(Ptarget);                         //~v5cgR~
//                    memcpy(tgt,Ptarget,(UINT)len);               //~v5cgR~
//                    if (!(flag & UFPF_TROOT))                    //~v5cgR~
//                    {                                            //~v5cgR~
//                        if (flag & UFPF_UP)                      //~v5cgR~
//                            *(tgt+len++)=FTP_DIR_SEPC;           //~v5cgR~
//                        else                                     //~v5cgR~
//                            *(tgt+len++)=DIR_SEPC;               //~v5cgR~
//                    }                                            //~v5cgR~
//                    strcpy(tgt+len,Psource+PATHLEN(Psource));    //~v5cgR~
//                    rc=ufstat(tgt,&fstat3); //not found          //~v5cgR~
//                    if (rc)                                      //~v5cgR~
//                        flag|=UFPF_TTOPDNEW;                     //~v5cgR~
//                    else                                         //~v5cgR~
//                    {                                            //~v5cgR~
//                        if (!(fstat3.attrFile & FILE_DIRECTORY)) //~v5cgR~
//                            return uftpfileanddir(tgt,Psource);  //~v5cgR~
//                        flag|=UFPF_TTOPDEXIST; //same name dir to dir//~v5cgR~
//                    }                                            //~v5cgR~
//              	flag|=UFPF_TTOPDNEWNAME; //top dir rename      //~v5cgR~
//              }//not samename                                    //~v5cgR~
//          }//tnew                                                //~v5cgR~
//      }//src is dir                                              //~v5cgR~
		if ((flag & UFPF_TNEW))	//source is dir                    //~v5cgI~
			flag|=UFPF_TTOPDNEW;                                   //~v5cgI~
        else                                                       //~v5cgI~
		    flag|=UFPF_TTOPDEXIST; //same name dir to dir          //~v5cgI~
    }//source not file                                             //~v5auI~
	*Ppflag=flag;                                                  //~v5auI~
    return 0;                                                      //~v5auI~
}//uftps2tchk                                                      //~v5auI~
//**************************************************************** //~v5cgI~
//!uftpcreateparmproc                                              //~v5cgI~
//* insert src dirname into target path                            //~v5cgI~
//* and mkdir if the dir is not found                              //~v5cgI~
//*retrn:rc                                                        //~v5cgI~
//**************************************************************** //~v5cgI~
//int uftpcreateparmproc(char *Psfullpath,char *Ptfullpath,int *Ppflag)//~v5cjR~
int uftpcreateparmproc(char *Psfullpath,char *Ptfullpath,int *Ppflag,PUFTPPARM Ppufp)//~v5cjI~
{                                                                  //~v5cgI~
    FILEFINDBUF3 fstat3t;                                          //~v5cgI~
//  UCHAR srcdir[_MAX_PATH],tgtdir[_MAX_PATH];                     //~v5cgI~//~v6H7R~
    UCHAR srcdir[FTP_MAXPATH2],tgtdir[FTP_MAXPATH2];               //~v6H7I~
	int tpathlen,srootsw=0,spathlen,flag,rc;                       //~v5ckR~
//*********************                                            //~v5cgI~
	spathlen=PATHLEN(Psfullpath);                                  //~v5cgI~
    flag=*Ppflag;                                                  //~v5cgI~
    if (flag & UFPF_SWILD)        //source wild card               //~v5cgI~
    {                                                              //~v5cgI~
    	if (flag & UFPF_SWILDROOT)        //source wild card       //~v5cgI~
        {                                                          //~v5cjI~
        	srootsw=1;						//err                  //~v5cgI~
	        memcpy(srcdir,Psfullpath,(UINT)spathlen);              //~v5cjI~
	        *(srcdir+spathlen)=0;                                  //~v5cjI~
        }                                                          //~v5cjI~
        else                                                       //~v5cgI~
        {                                                          //~v5cgI~
	        memcpy(srcdir,Psfullpath,(UINT)(spathlen-1));          //~v5cgI~
	        *(srcdir+spathlen-1)=0;                                //~v5ciI~
        	strcpy(srcdir,srcdir+PATHLEN(srcdir));                 //~v5cgI~
        }                                                          //~v5cgI~
        strcpy(Ppufp->UFPswildpdir,srcdir);                        //~v5cjI~
    }//wild src                                                    //~v5cgI~
    else		//not wildcard                                     //~v5cgI~
    {                                                              //~v5cgI~
    	if (flag & UFPF_SROOT)        //source wild card           //~v5cgI~
        	srootsw=1;                                             //~v5cgI~
        else                                                       //~v5cgI~
        {                                                          //~v5cgI~
    	    if (!(flag & UFPF_SDIR))//source dir                   //~v5cgI~
            {                                                      //~v5cgI~
                uerrmsg("Create option specified,but %s is not directrory.",//~v5cgI~
                        "Create オプションが指定されたが %s がディレクトリーでない。",//~v5cgI~
                         Psfullpath);                              //~v5cgI~
                return 4;                                          //~v5cgI~
            }                                                      //~v5cgI~
        	strcpy(srcdir,Psfullpath+spathlen);//with top dir sepc //~v5cgI~
        }                                                          //~v5cgI~
    }                                                              //~v5cgI~
    if (srootsw)                                                   //~v5cgI~
    {                                                              //~v5cgI~
        uerrmsg("Create option is invalid when source is route",   //~v5d6R~
                "複写元がルートDirのときCreteオプションは使えません。");//~v5cgI~
        return 4;                                                  //~v5cgI~
    }                                                              //~v5cgI~
//  tpathlen=strlen(Ptfullpath);                                   //~v5cgI~//~v6D0R~
    tpathlen=(int)strlen(Ptfullpath);                              //~v6D0I~
    memcpy(tgtdir,Ptfullpath,(UINT)tpathlen);                      //~v5cgR~
    if (!(flag & UFPF_TROOT))                                      //~v5cgI~
    {                                                              //~v5cgI~
        if (flag & UFPF_UP)                                        //~v5cgI~
            *(tgtdir+tpathlen++)=FTP_DIR_SEPC;                     //~v5cgI~
        else                                                       //~v5cgI~
            *(tgtdir+tpathlen++)=DIR_SEPC;                         //~v5cgI~
    }                                                              //~v5cgI~
    strcpy(tgtdir+tpathlen,srcdir);                                //~v5cgI~
    if (flag & UFPF_TNEW)        //source wild card                //~v5ciM~
      	return ufilepatherr(tgtdir,4);                             //~v5ciI~
//  rc=ufstat(tgtdir,&fstat3t); //not found                        //~v5cgI~//~v6D0R~
    rc=(int)ufstat(tgtdir,&fstat3t); //not found                   //~v6D0I~
    if (rc)                                                        //~v5cgI~
    {                                                              //~v5cgI~
        flag&=~UFPF_TDIR;                                          //~v5cgR~
        flag|=UFPF_TNEW;                                           //~v5cgI~
    }                                                              //~v5cgI~
    else                                                           //~v5cgI~
    {                                                              //~v5cgI~
        if (!(fstat3t.attrFile & FILE_DIRECTORY))                  //~v5cgR~
            return uftpfileanddir(tgtdir,Psfullpath);              //~v5cgR~
    }                                                              //~v5cgI~
    strcpy(Ptfullpath,tgtdir);                                     //~v5cgI~
    flag &=~UFPF_TROOT;                                            //~v5cgI~
    *Ppflag=flag;                                                  //~v5cgI~
    return 0;                                                      //~v5cgI~
}//ufilecreateparmproc                                             //~v5cgI~
//**************************************************************** //~v5ckI~
//!uftpmoveparmproc                                                //~v5ckI~
//* insert src dirname into target path if target exist            //~v5ckI~
//* else rename to atrget dir                                      //~v5ckI~
//*retrn:rc 1:src dir create requied,4:err,0:normal member copy    //~v5ckR~
//**************************************************************** //~v5ckI~
int uftpmoveparmproc(char *Psfullpath,char *Ptfullpath,int *Ppflag,PUFTPPARM Ppufp)//~v5ckI~
{                                                                  //~v5ckI~
    FILEFINDBUF3 fstat3t;                                          //~v5ckI~
//  UCHAR srcdir[_MAX_PATH],tgtdir[_MAX_PATH];                     //~v5ckI~//~v6H7R~
    UCHAR srcdir[FTP_MAXPATH2],tgtdir[FTP_MAXPATH2];               //~v6H7I~
	int tpathlen,spathlen,flag,rc;                                 //~v5ckI~
//*********************                                            //~v5ckI~
    flag=*Ppflag;                                                  //~v5ckI~
    if (flag & UFPF_TNEW                                           //~v5ckI~
    &&  flag & UFPF_SWILD)    //wildard to new target              //~v5ckI~
    {                                                              //~v5ckI~
        uerrmsg("Move soure is wildcard,but %s is not directrory.",//~v5ckI~
        		"ワイルドカード指定の移動先 %s がディレクトリーでない。",//~v5ckI~
                Ptfullpath);                                       //~v5ckI~
    	return 4;                                                  //~v5ckI~
    }                                                              //~v5ckI~
    rc=0;                                                          //~v5ckI~
	spathlen=PATHLEN(Psfullpath);                                  //~v5ckM~
    if (flag & UFPF_SDIR    //source is dir                        //~v5ckI~
    &&  flag & (UFPF_TDIR|UFPF_TROOT))    //target  dir exist      //~v5ckR~
    {                                                              //~v5ckI~
		spathlen=PATHLEN(Psfullpath);                              //~v5ckI~
        strcpy(srcdir,Psfullpath+spathlen);//with top dir sepc     //~v5ckI~
//  	tpathlen=strlen(Ptfullpath);                               //~v5ckI~//~v6D0R~
    	tpathlen=(int)strlen(Ptfullpath);                          //~v6D0I~
    	memcpy(tgtdir,Ptfullpath,(UINT)tpathlen);                  //~v5ckI~
    	if (!(flag & UFPF_TROOT))                                  //~v5ckI~
    	{                                                          //~v5ckI~
        	if (flag & UFPF_UP)                                    //~v5ckI~
            	*(tgtdir+tpathlen++)=FTP_DIR_SEPC;                 //~v5ckI~
        	else                                                   //~v5ckI~
            	*(tgtdir+tpathlen++)=DIR_SEPC;                     //~v5ckI~
    	}                                                          //~v5ckI~
    	strcpy(tgtdir+tpathlen,srcdir);                            //~v5ckI~
//  	rc=ufstat(tgtdir,&fstat3t); //not found                    //~v5ckI~//~v6D0R~
    	rc=(int)ufstat(tgtdir,&fstat3t); //not found               //~v6D0I~
        if (!rc)                    //found                        //~v5ckR~
			return ufileexist(tgtdir,4);                           //~v5ckR~
	    strcpy(Ptfullpath,tgtdir);                                 //~v5ckI~
        flag&=~(UFPF_TDIR|UFPF_TROOT);                             //~v5ckI~
        flag|=UFPF_TNEW;                                           //~v5ckI~
        rc=1;                                                      //~v5ckI~
    }                                                              //~v5ckI~
    *Ppflag=flag;                                                  //~v5ckI~
    return rc;                                                     //~v5ckI~
}//ufilemoveparmproc                                               //~v5ckI~
//****************************************************************
//uftpupdownctl
//*retrn:rc
//****************************************************************
int uftpupdownctl(PUFTPPARM Ppufp)
{
	PUFTPHOST puftph;                                              //~v5afI~
	UFTPPARM ufp;
    int rc,filectr,ii,spathlen,tpathlen,stdoctr,flag,opt,membchksw;//~v5auR~
    int appendsw,appendtopsw,append2fsw,targetfsw,copyintosw;      //~v5cgR~
    PUDIRLIST pudirlist,pudirlist0;
//  char newsrc[_MAX_PATH],newtgt[_MAX_PATH];                      //~v6H7R~
    char newsrc[FTP_MAXPATH2],newtgt[FTP_MAXPATH2];                //~v6H7I~
    char **pstdo,*psource,*ptarget,*pfnm;                          //~v5a7R~
    int ftpopt=0;                                                  //~v5eyI~
//********************
	puftph=Ppufp->UFPpuftph;                                       //~v5afI~
    psource=Ppufp->UFPsfpath;
    ptarget=Ppufp->UFPtfpath;     //without last /
    spathlen=Ppufp->UFPspathlen;
    tpathlen=Ppufp->UFPtpathlen;
    flag=Ppufp->UFPflag;
    opt=Ppufp->UFPopt;                                             //~v5arI~
  	appendsw=(opt & DCPY_APPEND);                                  //~v5arI~
	appendtopsw=(appendsw && !(flag & UFPF_SUBDIR));  //append in subdir//~v5arI~
	append2fsw=(appendsw && (flag & (UFPF_TFILE|UFPF_TNEW)));  //append to file//~v5arI~
	targetfsw=append2fsw || (flag & UFPF_F2FCPY);  //copy file 2 file//~v5auI~
//  copytopnewsw=(!appendsw && !(flag & (UFPF_SUBDIR|UFPF_SFILE))  //~v5cgR~
//  		   && (flag & UFPF_TNEW));  //top is new and src is not file//~v5cgR~
    copyintosw=(!appendsw && (flag & (UFPF_SUBDIR|UFPF_SFILE)));   //~v5cgR~
    strcpy(newtgt,ptarget);
//if (!appendtopsw && !targetfsw && !copytopnewsw)  //"copy dir"  create dir//~v5cgR~
  if (!appendtopsw && !targetfsw && copyintosw)  //"copy dir"  create dir//~v5cgR~
	if (!(flag & UFPF_SWILD))	//source is file,dir
    {
		if (!(flag & UFPF_TROOT))	//source is file,dir           //~v59rR~
        {                                                          //~v59rI~
//      	tpathlen=strlen(newtgt);                               //~v59rI~//~v6D0R~
        	tpathlen=(int)strlen(newtgt);                          //~v6D0I~
	    	*(newtgt+tpathlen)=Ppufp->UFPtsepc;                    //~v59rR~
        }                                                          //~v59rI~
        strcpy(newtgt+tpathlen+1,psource+spathlen+1);   //new target dir//~v59rI~
		if (flag & UFPF_DOWN)	//copypath is done at jcifs for upload//~v6H7I~
			UMAXPATHCHK(newtgt,_MAX_PATH,4,1/*msgsw*/);            //~v6H7I~
    }
    Ppufp->UFPnewtgt=newtgt;                                       //~v59rR~
    membchksw=0;                                                   //~v5arR~
	if (flag & UFPF_TTOPDNEW)   //src:dir or file and not in newdir//~v5auR~
    	flag |= UFPF_TNEW;                                         //~v5auI~
	if (!(flag & UFPF_TNEW))	//src:dir or file and not in newdir//~v5auI~
    {
  	  if (!targetfsw)  //target is not file                        //~v5auR~
      {                                                            //~v5arI~
        if (flag & (UFPF_SWILD|UFPF_SUBDIR|UFPF_TTOPDEXIST))  //src:dir or file and not in newdir//~v5auR~
            membchksw=1;                                           //~v5arI~
      }//not append to file                                        //~v5arI~
    }
	else                                                           //~v5auR~
    {                                                              //~v5arI~
//    if (!targetfsw)	//source is dir                            //~v5bkR~
//    if (flag & UFPF_SDIR)  //source is dir                       //~v5cgR~
      if (!targetfsw)	//target is not file or new(and append or sfile)//~v5cuI~
      if (flag & (UFPF_SDIR|UFPF_SWILD))  //source is dir          //~v5cgI~
    	if (uftpmktdir(puftph,flag,newtgt))                        //~v5afR~
        	return -1;
    }//tnew                                                        //~v5arI~
	if (flag & UFPF_SFILE)
    {
    	filectr=1;
//      pudirlist0=0;                                              //~v5fiR~
//      pudirlist0=umalloc(sizeof(UDIRLIST));                      //~v5fiR~//~v6qaR~
//      memset(pudirlist0,0,sizeof(UDIRLIST));                     //~v5fiR~//~v6qaR~
        pudirlist0=UDIRLIST_ALLOC1(UDA1O_ALLOC_SLINKNAME);         //~v6qaI~
    }
    else
    {
//  	filectr=uftpgetdirlist(flag|UFPF_SDIRL,psource,Ppufp->UFPattrmask,&pudirlist0,'N');//no sort//~v59rR~//~v6d1R~
//  	filectr=uftpgetdirlist(Ppufp,flag|UFPF_SDIRL,psource,Ppufp->UFPattrmask,&pudirlist0,'N');//no sort//~v6d1R~//~v6D1R~
    	filectr=uftpgetdirlist(Ppufp,flag|UFPF_SDIRL,psource,(UINT)(Ppufp->UFPattrmask),&pudirlist0,'N');//no sort//~v6D1I~
    	if (filectr<0)  //err
    		return 4;
    }
//*
    Ppufp->UFPpudl=pudirlist0;
    Ppufp->UFPpudlno=filectr;
    Ppufp->UFPflag=flag;
//chk existing member
    if (membchksw)   //not requied chk                             //~v5arR~
    {
    	if (uftpexistchkm(Ppufp))                                  //~v59rR~
        {                                                          //~v5ciI~
    		if (pudirlist0)                                        //~v5ciI~
//      		ufree(pudirlist0);                                 //~v5ciI~//~v6qaR~
        		UDIRLIST_FREE(pudirlist0);                         //~v6qaI~
        	return -1;
        }                                                          //~v5ciI~
    }//not repl and not new
	for (;;)	//to ufree
    {
//file process
        Ppufp->UFPcmdctr=-1;	//to chk no file entry to be execute//~v59rI~
//      if (rc=uftpcmd(puftph,FTPCMD_BINARY,0,&pstdo,&stdoctr,uftpcopycallback,Ppufp),rc)//~v5eyR~
        if (!(opt & DCPY_FTPTEXTMODE))                             //~v5eyI~
            ftpopt|=FTPCMD_BINARY;                                 //~v5eyI~
#ifdef ARMXXE                                                      //~v6daI~
      if (UFTPH_ISSMBJ(puftph))                                    //~v6daI~
      {                                                            //~v6daI~
        	if (rc=uftpsmbj_updowncmd(ftpopt,Ppufp,puftph),rc)     //~v6daI~
            {                                                      //~v6daI~
            	if (rc!=ERROR_NO_MORE_FILES)	//need subdir process//~v6daI~
	            	break;	//bypass following files               //~v6daR~
            }                                                      //~v6daI~
          if (!rc)                                                 //~v6daI~
			if (flag & UFPF_DOWN)	//copypath is done at jcifs for upload//~v6daI~
				if (!(Ppufp->UFPopt & DCPY_NOCOPYINFO))            //~v6daI~
		        	if (rc=uftpcopyftime(Ppufp),rc)                //~v6daI~
                		break;                                     //~v6daI~
      }                                                            //~v6daI~
      else                                                         //~v6daI~
      {                                                            //~v6daI~
#endif                                                             //~v6daI~
        if (rc=uftpcmd(puftph,ftpopt,0,&pstdo,&stdoctr,uftpcopycallback,Ppufp),rc)//~v5eyI~
        {                                                          //~v59rI~
	        if (!Ppufp->UFPcmdctr)	//no file entry to be execute  //~v59rI~
            	rc=0;			//ignore callback rc               //~v59rI~
            else                                                   //~v59rI~
            	break;                                             //~v59rR~
        }                                                          //~v59rI~
        else	//cmd executed                                     //~v59rI~
        {                                                          //~v59rI~
        	if (rc=uftpcopyrchk(Ppufp,pstdo,stdoctr),rc)//stdo is freed in the func//~v5a7R~
            	break;                                             //~v59rR~
			if (flag & UFPF_DOWN)                                  //~v59rR~
				if (!(Ppufp->UFPopt & DCPY_NOCOPYINFO))            //~v59rR~
		        	if (rc=uftpcopyftime(Ppufp),rc)                //~v59rR~
                		break;                                     //~v59rR~
        }                                                          //~v59rI~
#ifdef ARMXXE                                                      //~v6daI~
      }//                                                          //~v6daI~
#endif                                                             //~v6daI~
		if (flag & UFPF_SFILE)
        	break;
//dir process
        ufp=*Ppufp;	//for subdir
	    strcpy(newsrc,psource);
		if (!(flag & UFPF_SWILD))	//source is file,dir           //~v59rI~
        {                                                          //~v5auI~
        	flag&=~UFPF_TROOT;                                     //~v5auM~
//      	spathlen=strlen(newsrc);                               //~v59rR~//~v6D0R~
        	spathlen=(int)strlen(newsrc);                          //~v6D0I~
        }                                                          //~v5auI~
        *(newsrc+spathlen)=Ppufp->UFPssepc;
        ufp.UFPsfpath=newsrc;
        ufp.UFPspathlen=spathlen;
        ufp.UFPflag=(flag & ~(UFPF_SWILD|UFPF_TTOPDNEW|UFPF_TTOPDEXIST));//~v5auR~
        ufp.UFPflag|=UFPF_SUBDIR;                                  //~v59rI~
        ufp.UFPflag|=UFPF_SDIR;                                    //~v5cmI~
      if (!targetfsw)                                              //~v5auR~
      {                                                            //~v5arI~
        ufp.UFPtfpath=newtgt;                                      //~v59rR~
        ufp.UFPtpathlen=tpathlen;                                  //~v59rI~
      }//create subdir                                             //~v5arI~
        for (pudirlist=pudirlist0,ii=0;ii<filectr;ii++,pudirlist++)  //until eof/err
        {
            pfnm=pudirlist->name;
            if (!strcmp(pfnm,".")        //curr
            ||  !strcmp(pfnm,".."))      //parent
                continue;
            if (!UCBITCHK(pudirlist->attr,FILE_DIRECTORY)) //file
                continue;
            strcpy(newsrc+spathlen+1,pfnm);
          if (membchksw)                                           //~v5arI~
            if (!(pudirlist->attr & FILE_FTPWKSL))	//target dir not found
		        ufp.UFPflag|=UFPF_TNEW;
            Ppufp->UFPsubdirctr++;                                 //~v5d8I~
			rc=uftpupdownctl(&ufp);
            if (rc)
                break;
        }//dir list
        if (rc)
            break;
		break;
    }//for
    if (pudirlist0)
//	    ufree(pudirlist0);                                         //~v6qaR~
  	    UDIRLIST_FREE(pudirlist0);                                 //~v6qaI~
    return rc;
}//uftpupdownctl
//**************************************************************** //~v59rI~
//make target dir                                                  //~v59rI~
//*retrn:rc                                                        //~v59rI~
//**************************************************************** //~v59rI~
//int uftpgetdirlist(int Pflag,char *Pdirname,UINT Pattrmask,PUDIRLIST *Pppudl,char Psopt)//~v59rI~//~v6d1R~
int uftpgetdirlist(PUFTPPARM Ppufp,int Pflag,char *Pdirname,UINT Pattrmask,PUDIRLIST *Pppudl,char Psopt)//~v6d1R~
{                                                                  //~v59rI~
    char *pdirnm;                                                  //~v59rR~
#ifdef W32                                                         //~v59rI~
	int len;                                                       //~v59rI~
//  char wkfpath[_MAX_PATH];                                       //~v59rI~//~v6H7R~
    char wkfpath[FTP_MAXPATH];                                     //~v6H7I~
#endif                                                             //~v59rI~
	PUFTPHOST puftph;                                              //~v6d1R~
//  char wkfpath2[_MAX_PATH];                                      //~v6d1R~//~v6H7R~
    char wkfpath2[FTP_MAXPATH];                                    //~v6H7R~
//*******************                                              //~v59rI~
	puftph=Ppufp->UFPpuftph;                                       //~v6d1R~
	pdirnm=Pdirname;                                               //~v59rI~
#ifdef W32                                                         //~v59rI~
	if (Pflag & UFPF_UP)                                           //~v59rI~
    {                                                              //~v59rI~
    	if (Pflag & UFPF_SDIRL)	//get source dirlist               //~v59rI~
    		if (!(Pflag & UFPF_SWILD))	//get source dirlist       //~v59rI~
        		pdirnm=0;                                          //~v59rR~
    }                                                              //~v59rI~
    else                   //download                              //~v59rI~
    {                                                              //~v59rI~
    	if (Pflag & UFPF_TDIRL)	//get target dirlist               //~v59rI~
        	pdirnm=0;                                              //~v59rI~
    }                                                              //~v59rI~
    if (!pdirnm)    //win local dirlist                            //~v59rI~
    {                                                              //~v59rR~
		pdirnm=wkfpath;                                            //~v59rI~
        len=strlen(Pdirname);                                      //~v59rR~
		memcpy(pdirnm,Pdirname,(UINT)len);                         //~v59rI~
        if (!ROOTDIR_LOCAL(Pdirname))                              //~v59rR~
	        *(pdirnm+len++)=DIR_SEPC;                              //~v59rR~
        strcpy(pdirnm+len,DIR_ALLMEMB);                            //~v59rR~
    }                                                              //~v59rI~
#endif                                                             //~v59rI~
    if (UFTPH_ISSMB(puftph))	//smb replace existing file;no need to delete//~v6d1R~
    	pdirnm=uftp3smb_dirnameforlist(0,puftph,pdirnm,wkfpath2);  //~v6d1R~
	return udirlist(pdirnm,Pattrmask,Pppudl,Psopt);//no sort       //~v59rR~
}//uftpgetdirlist                                                  //~v59rI~
//****************************************************************
//file/dir exist chk                                               //~v59rR~
//*retrn:rc
//****************************************************************
int uftpexistchk1(PUFTPPARM Ppufp,int *Ppflag)                     //~v59rR~
{
    int flag,opt,flage=0,pudlctrt,rc=0,tpathlen,jj,rc2,dirsw=0;    //~v59rR~
    char *psource,*ptarget,*pnewtgt,*pfnm;                         //~v59rR~
    PUDIRLIST pudlt0,pudlt;                                        //~v59rI~
#ifdef W32                                                         //~v59rI~
//  char ciname[_MAX_PATH];                                        //~v59rI~//~v6H7R~
    char ciname[FTP_MAXPATH2];                                     //~v6H7R~
#endif                                                             //~v59rI~
//***********************************                              //~v59rR~
    flag=Ppufp->UFPflag;                                           //~v59rM~
    opt=Ppufp->UFPopt;                                             //~v59rM~
    psource=Ppufp->UFPsfpath;
    ptarget=Ppufp->UFPtfpath;       //target path                  //~v59rR~
//  tpathlen=strlen(ptarget);                                      //~v59rI~//~v6D0R~
    tpathlen=(int)strlen(ptarget);                                 //~v6D0I~
    if (flag & UFPF_TROOT)                                         //~v59rI~
        tpathlen--;                                                //~v59rI~
    pnewtgt=Ppufp->UFPnewtgt;                                      //~v59rI~
//  pudlctrt=uftpgetdirlist(flag|UFPF_TDIRL,ptarget,FILE_ALL,&pudlt0,'N');//no sort//~v59rI~//~v6d1R~
    pudlctrt=uftpgetdirlist(Ppufp,flag|UFPF_TDIRL,ptarget,FILE_ALL,&pudlt0,'N');//no sort//~v6d1R~
    if (pudlctrt<0)  //err                                         //~v59rI~
    	rc=4;                                                      //~v59rI~
    else                                                           //~v59rI~
    {                                                              //~v59rI~
    	pfnm=pnewtgt+tpathlen+1;                                   //~v59rI~
        for (pudlt=pudlt0,jj=0;jj<pudlctrt;jj++,pudlt++)           //~v59rI~
        {                                                          //~v59rI~
#ifdef W32                                                         //~v59rI~
			if (flag & UFPF_DOWN)                                  //~v5auI~
            	rc2=stricmp(pfnm,pudlt->name);                     //~v5auR~
            else                                                   //~v5auI~
#endif                                                             //~v5auM~
            	rc2=strcmp(pfnm,pudlt->name);                      //~v5auR~
			if (!rc2)	//match                                    //~v59rI~
                break;                                             //~v59rI~
        }                                                          //~v59rI~
        if (jj>=pudlctrt)	//not found                            //~v59rI~
        	rc=4;	//not found                                    //~v59rI~
        else                                                       //~v59rI~
        {                                                          //~v59rI~
        	dirsw=(pudlt->attr & FILE_DIRECTORY);                  //~v59rI~
#ifdef W32                                                         //~v59rM~
        	strcpy(ciname,pnewtgt);                                //~v59rR~
            strcpy(ciname+tpathlen+1,pudlt->name);                 //~v59rI~
            pnewtgt=ciname;                                        //~v59rI~
#endif                                                             //~v59rM~
        }                                                          //~v59rI~
//  	ufree(pudlt0);                                             //~v59rI~//~v6qaR~
    	UDIRLIST_FREE(pudlt0);                                     //~v6qaI~
    }                                                              //~v59rI~
    if (rc)                                                        //~v59rI~
        flage|=UFPF_TNEW;  //not found
    else
    {
        if (dirsw)                                                 //~v59rR~
        {
            if (flag & UFPF_SFILE)
                return uftpfileanddir(psource,pnewtgt);            //~v59rR~
        }
        else
        {
            if (flag & UFPF_SFILE)
            {
                if (!(opt & DCPY_EXISTING))       //repl req
                {                                                  //~v5ckI~
                	if (opt & DCPY_SKIPEXIST)       //skip override//~v5fgR~
    	        		return DCPY_RC_NOTCOPY;                    //~v5fgR~
//                  return ufileexist(pnewtgt,-1);                 //~v5cdR~
                    return ufileexistcopy(pnewtgt,-1);             //~v5cdI~
                }                                                  //~v5ckI~
                                                                   //~v5ckI~
            }
            else
                return uftpfileanddir(pnewtgt,psource);            //~v59rR~
        }
    }
    *Ppflag=flage;
    return 0;
}//uftpexistchk1
//****************************************************************
//dir membername matching
//*retrn:rc
//****************************************************************
int uftpexistchkm(PUFTPPARM Ppufp)                                 //~v59rR~
{
//  char tgtfile[_MAX_PATH],srcfile[_MAX_PATH],*sfnm;              //~v6H7R~
    char tgtfile[FTP_MAXPATH2],srcfile[FTP_MAXPATH2],*sfnm;        //~v6H7I~
	PUDIRLIST pudirlist,pudlt,pudlt0;
    int rc=0,rc2,pudlctr,pudlctrt,ii,jj,spathlen,tpathlen,sdirsw,flag,opt;
    char *psource,*ptarget;
//***********************************
    flag=Ppufp->UFPflag;                                           //~v59rM~
    psource=Ppufp->UFPsfpath;
    ptarget=Ppufp->UFPnewtgt;                                      //~v59rR~
    if (flag & UFPF_SWILD)                                         //~v59rI~
    	spathlen=Ppufp->UFPspathlen;                               //~v59rI~
    else                                                           //~v59rI~
//  	spathlen=strlen(psource);                                  //~v59rR~//~v6D0R~
    	spathlen=(int)strlen(psource);                             //~v6D0I~
    if (flag & UFPF_TROOT)                                         //~v5auR~
    	tpathlen=Ppufp->UFPtpathlen;                               //~v59rI~
    else                                                           //~v59rI~
//  	tpathlen=strlen(ptarget);                                  //~v59rR~//~v6D0R~
    	tpathlen=(int)strlen(ptarget);                             //~v6D0I~
    opt=Ppufp->UFPopt;
    pudirlist=Ppufp->UFPpudl;
    pudlctr=Ppufp->UFPpudlno;
//  pudlctrt=uftpgetdirlist(flag|UFPF_TDIRL,ptarget,FILE_ALL,&pudlt0,'N');//no sort//~v59rR~//~v6d1R~
    pudlctrt=uftpgetdirlist(Ppufp,flag|UFPF_TDIRL,ptarget,FILE_ALL,&pudlt0,'N');//no sort//~v6d1R~
    if (pudlctrt<0)  //err
    	return 0;
//  memcpy(srcfile,psource,spathlen);                              //~v6D0R~
    memcpy(srcfile,psource,(size_t)spathlen);                      //~v6D0I~
    *(srcfile+spathlen)=Ppufp->UFPssepc;
//  memcpy(tgtfile,ptarget,tpathlen);                              //~v6D0R~
    memcpy(tgtfile,ptarget,(size_t)tpathlen);                      //~v6D0I~
    *(tgtfile+tpathlen)=Ppufp->UFPtsepc;
    for (rc=0,ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err
    {
//      pudirlist->attr&=~FILE_FTPWKSL; //target dir not found     //~v5fgR~
//      pudirlist->attr&=~(FILE_FTPWKSL|FILE_FTPWKSL2); //sw for notfound|skip ftp//~v5fgR~//~v6D0R~
        pudirlist->attr&=~(ULONG)(FILE_FTPWKSL|FILE_FTPWKSL2); //sw for notfound|skip ftp//~v6D0I~
        sfnm=pudirlist->name;
        if (!strcmp(sfnm,".")        //curr
        ||  !strcmp(sfnm,".."))      //parent
            continue;
        sdirsw=(pudirlist->attr & FILE_DIRECTORY);
        strcpy(srcfile+spathlen+1,sfnm);
        for (pudlt=pudlt0,jj=0;jj<pudlctrt;jj++,pudlt++)
        {
#ifdef W32
            rc2=stricmp(sfnm,pudlt->name);                         //~v59rR~
#else                                                              //~v59rR~
            rc2=strcmp(sfnm,pudlt->name);                          //~v59rR~
#endif                                                             //~v59rI~
            if (!rc2)   //filename match
            {
        		strcpy(tgtfile+tpathlen+1,sfnm);
                if (pudlt->attr & FILE_DIRECTORY)
                    if (sdirsw)
                        pudirlist->attr|=FILE_FTPWKSL;  //dir->dir
                    else    //file ->dir
                        uftpfileanddir(srcfile,tgtfile);
                else    //target file
                    if (sdirsw)
                        uftpfileanddir(tgtfile,srcfile);
                    else    //file ->file
                        if (!(opt & DCPY_EXISTING))       //repl req
                        {                                          //~v5fgR~
		                  if (opt & DCPY_SKIPEXIST)       //skip override//~v5fgR~
	                        pudirlist->attr|=FILE_FTPWKSL2;  //skip ftp//~v5fgR~
                          else                                     //~v5fgR~
                          {                                        //~v5frI~
//                          ufileexist(tgtfile,-1);                //~v5cdR~
                            ufileexistcopy(tgtfile,-1);            //~v5cdI~
                            Ppufp->UFPcopyskipctr++;               //~v5frR~
                          }                                        //~v5frI~
                        }                                          //~v5fgR~
                        else
                        {                                          //~v5frI~
					      if ((opt & DCPY_REPOLD)	//not force override//~v5frR~
					      &&  ufileftpcopytschk(opt,srcfile,       //~v5frR~
													pudirlist->date,pudirlist->time,//~v5frR~
													tgtfile,       //~v5frR~
													pudlt->date,pudlt->time)<=0)//~v5frR~
	                      	Ppufp->UFPcopyskipctr++;               //~v5frR~
                          else                                     //~v5frR~
                            pudirlist->attr|=FILE_FTPWKSL;  //file->file
                        }                                          //~v5frI~
                break;
            }//name found
        }//for
        if (jj<pudlctrt)//filename match
        {
//          if (!(pudirlist->attr & FILE_FTPWKSL))  //file rep or dir and dir//~v5fgR~
            if (!(pudirlist->attr & (FILE_FTPWKSL|FILE_FTPWKSL2))) //match and ok or skip//~v5fgR~
                rc=1;
        }
    }//src dir list
//  ufree(pudlt0);                                                 //~v6qaR~
    UDIRLIST_FREE(pudlt0);                                         //~v6qaI~
    if (rc)
        return -1;
    return 0;
}//uftpexistchkm
//****************************************************************
//callback func to process file entry
//*retrn:rc
//****************************************************************
int uftpcopycallback(FILE *Ppfh,void *Ppvoid)
{
	PUFTPPARM pufp;
	PUDIRLIST pudirlist;
	PUFTPHOST puftph;                                              //~v5afI~
    int rc=0,pudlctr,ii,flag,spathlen,tpathlen,filectr=0,hostnmlen,pos,opt;//~v5auR~
    int appendsw,append2fsw,targetfsw;                             //~v5auR~
    char *ptfpath,*pfnm,*psfpath,*pnewtgt,*pappendto=NULL;              //~v5aqR~//~v6h7R~
//  char lcdpath[_MAX_PATH],cdpath[_MAX_PATH],appendopd[_MAX_PATH+1+_MAX_PATH];//~v5aqR~//~v6H7R~
    char lcdpath[FTP_MAXPATH],cdpath[FTP_MAXPATH],appendopd[FTP_MAXPATH2+16];//~v6H7R~
//***********************************
	pufp=(PUFTPPARM)Ppvoid;
    opt=pufp->UFPopt;                                              //~v5aqR~
    puftph=pufp->UFPpuftph;                                        //~v5afI~
	pufp->UFPpfh=Ppfh;
    pudirlist=pufp->UFPpudl;
    pudlctr=pufp->UFPpudlno;
    flag=pufp->UFPflag;
    psfpath=pufp->UFPsfpath;                                       //~v59rM~
    spathlen=pufp->UFPspathlen;                                    //~v59rM~
    tpathlen=pufp->UFPtpathlen;                                    //~v5auI~
    ptfpath=pufp->UFPtfpath;                                       //~v59rR~
    pnewtgt=pufp->UFPnewtgt;                                       //~v59rI~
    hostnmlen=puftph->UFTPHhostnmlen;                              //~v5afR~
    appendsw=opt & DCPY_APPEND;                                    //~v5arI~
    append2fsw=(appendsw && (flag & (UFPF_TNEW|UFPF_TFILE)));  //file->file2//~v5arR~
    targetfsw=append2fsw || (flag & UFPF_F2FCPY);  //file->file2   //~v5auI~
    if (flag & UFPF_UP)
    {
        if (appendsw)                                              //~v6d1R~
            if (UFTPH_ISSMB(puftph))                               //~v6d1R~
            {                                                      //~v6d1R~
				return uftpnotsupported("append(Upload)","Samba Server");//~v6d1R~
            }                                                      //~v6d1R~
    	if ((flag & UFPF_RENCPY) && !(flag & UFPF_TNEW)) //repl new name existing//~v5auI~
      	{                                                          //~v5auI~
         if (!UFTPH_ISSMB(puftph))	//smb replace existing file;no need to delete//~v6d1R~
          if (!UFTPHISPSFTP(puftph))	//psftp replace existing file//~v61pI~
          {                                                        //~v61pI~
    		uftpputstmt(pufp,"delete",pnewtgt+hostnmlen+1);        //~v5auR~
	    	flag|=UFPF_DELTGT;                                     //~v5auI~
          }                                                        //~v61pI~
      	}                                                          //~v5auI~
      if (targetfsw)                                               //~v5auR~
      {                                                            //~v5aqI~
        pappendto=ptfpath+hostnmlen+1;                             //~v5aqI~
      }                                                            //~v5aqI~
      else                                                         //~v5aqI~
      {                                                            //~v5aqI~
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v59rI~
        	strcpy(cdpath,ptfpath+hostnmlen+1);                    //~v59rI~
        else                                                       //~v59rI~
        	strcpy(cdpath,pnewtgt+hostnmlen+1);                    //~v59rR~
    	uftpputstmt(pufp,"cd",cdpath);
    	flag|=UFPF_RCD;
      }//!(append target is file)                                  //~v5aqI~
        strcpy(lcdpath,psfpath);
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v59rR~
        {                                                          //~v59rI~
        	pos=spathlen;                                          //~v59rI~
#ifdef W32                                                         //~v59rI~
        	if (pos==2)                                            //~v59rI~
#else                                                              //~v59rI~
        	if (pos==0)                                            //~v59rI~
#endif                                                             //~v59rI~
				pos++;                                             //~v59rI~
            *(lcdpath+pos)=0;                                      //~v59rI~
        }                                                          //~v59rI~
    	uftpputstmt(pufp,"lcd",lcdpath);
    	strcpy(pufp->UFPlcdpath,lcdpath);	                       //~v5ckI~
    	uftpputstmt(pufp,FTP_LOCALCMD_PWD,0);	//for lcd resp msg chk//~v61nI~
    	uftpputstmt(pufp,"pwd",0);	//for lcd resp msg chk
    	flag|=UFPF_LCD;
    }
    else           //download
    {
        strcpy(cdpath,psfpath+hostnmlen+1);
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))
        {
            pos=spathlen-(hostnmlen+1);
            if (!pos)   //root
                pos++;                                             //~v59rR~
            *(cdpath+pos)=0;
        }
        uftpputstmt(pufp,"cd",cdpath);
        flag|=UFPF_RCD;
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v59rI~
        	strcpy(lcdpath,ptfpath);                               //~v59rI~
        else                                                       //~v59rI~
        	strcpy(lcdpath,pnewtgt);                               //~v59rR~
      	if (targetfsw)                                             //~v5auI~
        	*(lcdpath+tpathlen)=0;                                 //~v5auI~
    	uftpputstmt(pufp,"lcd",lcdpath);
    	strcpy(pufp->UFPlcdpath,lcdpath);                          //~v5ckI~
    	uftpputstmt(pufp,FTP_LOCALCMD_PWD,0);	//for lcd resp msg chk//~v61nI~
    	uftpputstmt(pufp,"pwd",0);
    	flag|=UFPF_LCD;
    }
    pufp->UFPflag|=flag;	//tell to rchk
//write get/put cmd
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err
    {
//      if (pudirlist->attr & FILE_FTPWKSL2)  //skip existing      //~v5fiR~
//      	continue;                                              //~v5fiR~
    	if (flag & UFPF_SFILE)  //source is file
        	pfnm=psfpath+spathlen+1;
        else
        {
            if (pudirlist->attr & FILE_FTPWKSL2)  //skip existing  //~v5fiR~
            	continue;                                          //~v5fiR~
	        pfnm=pudirlist->name;
            if (!strcmp(pfnm,".")        //curr
            ||  !strcmp(pfnm,".."))      //parent
                continue;
            if (UCBITCHK(pudirlist->attr,(FILE_DIRECTORY|FILE_SPECIAL))) //source dir
                continue;
        }
        if (flag & UFPF_UP)
        {                                                          //~v5aqI~
      	  if (appendsw)                                            //~v5arR~
          {                                                        //~v5aqI~
		    if (append2fsw)  //append to file                      //~v5arR~
            	sprintf(appendopd,"\"%s\" \"%s\"",pfnm,pappendto); //~v5bfR~
            else                                                   //~v5aqI~
            	sprintf(appendopd,"\"%s\" \"%s\"",pfnm,pfnm);      //~v5bfR~
		    uftpputstmt(pufp,"append",appendopd);                  //~v5aqI~
          }                                                        //~v5aqI~
          else                                                     //~v5aqI~
           if (flag & UFPF_RENCPY)  //rename file to file          //~v5auI~
           {                                                       //~v5auI~
             if (UFTPH_ISSMB(puftph))                              //~v6d1R~
				uftp3smb_putstmt(UFTPSMBCMD_PUT2,puftph,pufp->UFPpfh,pfnm,pappendto);//~v6d1R~
             else                                                  //~v6d1R~
             {                                                     //~v6d1R~
            sprintf(appendopd,"\"%s\" \"%s\"",pfnm,pappendto);     //~v5bfR~
            if (UFTPHISPSFTP(puftph))                              //~v61pI~
		    uftpputstmt(pufp,"put",appendopd);  //psftp put support remote filename parameter//~v61pI~
            else                                                   //~v61pI~
		    uftpputstmt(pufp,"append",appendopd);                  //~v5auI~
             }                                                     //~v6d1R~
           }                                                       //~v5auI~
           else                                                    //~v5auI~
		    uftpputstmt(pufp,"put",pfnm);
        }//up                                                      //~v5aqI~
        else
        {                                                          //~v6H7I~
          if (opt & DCPY_FTP2TEMPF)                                //~v6H7M~
    		uftpputstmt2(pufp,"get",pfnm,ptfpath+tpathlen+1);      //~v6H7I~
          else                                                     //~v6H7M~
    		uftpputstmt(pufp,"get",pfnm);
        }                                                          //~v6H7I~
        filectr++;
    }//dir list
    pufp->UFPcmdctr=filectr;
    if (!filectr)                                                  //~v59rI~
    	rc=ENOENT;	//request skip ftp cmd                         //~v59rI~
    return rc;
}//uftpcopycallback
//****************************************************************
//ftp cmd result chk
//*retrn:rc
//****************************************************************
int uftpcopyrchk(PUFTPPARM Ppufp,char **Ppstdo,int Pstdoctr)
{
    PUFTPHOST puftph;                                              //~v61pI~
	PUDIRLIST pudirlist;
    int flag,rc=0,filectr=0,pudlctr,stdoctr,ii,spathlen;
//  char newsrc[_MAX_PATH],*cmd,**stdo;                            //~v6H7R~
    char newsrc[FTP_MAXPATH],*cmd,**stdo;                          //~v6H7I~
    int smbcmd;                                                    //~v6d1R~
//****************************
	puftph=Ppufp->UFPpuftph;                                       //~v61pI~
	stdoctr=Pstdoctr;
    flag=Ppufp->UFPflag;
  if (Ppufp->UFPopt & DCPY_APPEND)                                 //~v5arI~
    if (flag & UFPF_UP)                                            //~v5arI~
    	cmd="put(append)";                                         //~v5arI~
    else                                                           //~v5arI~
    	cmd="get(append)";                                         //~v5arI~
  else                                                             //~v5arI~
    if (flag & UFPF_UP)
    	cmd="put";
    else
    	cmd="get";
    if (flag & UFPF_UP)       //smbclient dose not support "append" mode//~v6d1R~
    	smbcmd=UFTPSMBCMD_PUT;                                     //~v6d1R~
    else                                                           //~v6d1R~
    	smbcmd=UFTPSMBCMD_GET;                                     //~v6d1R~
    stdo=Ppstdo;
    while(!rc)
    {
       if (UFTPH_ISSMB(puftph))                                    //~v6d1R~
       {                                                           //~v6d1R~
//    		if (rc=uftp3smb_respchk(smbcmd|F3SMBO_MULTISTART,puftph,Ppufp->UFPnewtgt,&stdo,&stdoctr,ENOENT),rc)//~v6d1R~
//            if (rc=uftp3smb_respchk(UFTPSMBCMD_PWD,puftph,Ppufp->UFPnewtgt,&stdo,&stdoctr,ENOENT),rc)//~v6d1R~
//                break;                                           //~v6d1R~
            rc=0;                                                  //~v6d1R~
       }                                                           //~v6d1R~
       else                                                        //~v6d1R~
       {                                                           //~v6d1R~
        if (flag & UFPF_DELTGT)   //lcd issued                     //~v5auI~
        {                                                          //~v5auI~
//  		if (rc=uftpsimplerespchk("cd","250 5** ",Ppufp->UFPnewtgt,&stdo,&stdoctr,ENOENT),rc)//~v619R~
//  		if (rc=uftpsimplerespchk("delete","250 5** ",Ppufp->UFPnewtgt,&stdo,&stdoctr,ENOENT),rc)//~v619I~
    		if (rc=uftpsimplerespchk("delete","250|226 5** ",Ppufp->UFPnewtgt,&stdo,&stdoctr,ENOENT),rc)//~v619I~
            	break;                                             //~v5auI~
        }                                                          //~v5auI~
        if (flag & UFPF_RCD)   //cd issued
        {
          if (UFTPHISPSFTP(puftph))                                //~v61pR~
          {                                                        //~v61pI~
			if (rc=uftp3cdrespchk(0,puftph,Ppufp->UFPtfpath,&stdo,&stdoctr),rc)//~v61pR~
            {                                                      //~v61pI~
            	rc=ENOENT;                                         //~v61pI~
            	break;                                             //~v61pI~
            }                                                      //~v61pI~
          }                                                        //~v61pI~
          else                                                     //~v61pI~
			if (rc=uftpsimplerespchk("cd","250 5** ",Ppufp->UFPtfpath,&stdo,&stdoctr,ENOENT),rc)//~v5arR~
            	break;
        }
        if (flag & UFPF_LCD)   //lcd issued
        {
//  	    if (rc=uftplchdirrespchk(&stdo,&stdoctr),rc)           //~v61nR~
//  	    if (rc=uftplchdirrespchk(&stdo,&stdoctr,Ppufp->UFPlcdpath),rc)//~v61pR~
    	    if (rc=uftplchdirrespchk(0,puftph,&stdo,&stdoctr,Ppufp->UFPlcdpath),rc)//~v61pR~
            {                                                      //~v5ckI~
            	uerrmsg("FTP local chdir failed for %s",0,         //~v5ckI~
		    			Ppufp->UFPlcdpath);                        //~v5ckR~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            	break;
            }                                                      //~v5ckI~
        }
      }//!smb                                                      //~v6d1R~
        pudlctr=Ppufp->UFPpudlno;
        pudirlist=Ppufp->UFPpudl;
        spathlen=Ppufp->UFPspathlen;
        strcpy(newsrc,Ppufp->UFPsfpath);
        if (flag & UFPF_SFILE)  //file src
        {
          if (UFTPH_ISSMB(puftph))                                 //~v6d1R~
          {                                                        //~v6d1R~
  			uftp3smb_respchk(smbcmd,puftph,newsrc,&stdo,&stdoctr,ENOENT);//~v6d1R~
            if (!rc)                                               //~v6d1R~
  				uftp3smb_respchk(smbcmd,puftph,Ppufp->UFPnewtgt,&stdo,&stdoctr,ENOENT);//~v6d1R~
            if (rc)                                                //~v6d1R~
            	break;                                             //~v6d1R~
          }                                                        //~v6d1R~
          else                                                     //~v6d1R~
          if (UFTPHISPSFTP(puftph))                                //~v61pI~
          {                                                        //~v61pI~
            if (rc=uftp3getputrespchk(0,puftph,cmd,newsrc,&stdo,&stdoctr,ENOENT),rc)//~v6b1R~
                break;                                             //~v61pI~
          }                                                        //~v61pI~
          else                                                     //~v61pI~
          {                                                        //~v61pI~
            if (rc=uftpsimplerespchk(cmd,"226 5** ",newsrc,&stdo,&stdoctr,ENOENT),rc)//~v5arR~
                break;
          }                                                        //~v61pI~
        	filectr=1;
        }
        else
        {
	        *(newsrc+spathlen++)=Ppufp->UFPssepc;                  //~v59rR~
            for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err
            {
                if (!strcmp(pudirlist->name,".")        //curr
                ||  !strcmp(pudirlist->name,".."))      //parent
                    continue;
                if (UCBITCHK(pudirlist->attr,(FILE_DIRECTORY|FILE_SPECIAL))) //source dir
                    continue;
        		if (pudirlist->attr & FILE_FTPWKSL2)  //skip existing//~v5fgR~
        			continue;                                      //~v5fgR~
                strcpy(newsrc+spathlen,pudirlist->name);      //parent
          	  if (UFTPH_ISSMB(puftph))                             //~v6d1R~
          	  {                                                    //~v6d1R~
    			if (rc=uftp3smb_respchk(smbcmd,puftph,newsrc,&stdo,&stdoctr,ENOENT),rc)//~v6d1R~
            		break;                                         //~v6d1R~
          	  }                                                    //~v6d1R~
          	  else                                                 //~v6d1R~
          	  if (UFTPHISPSFTP(puftph))                            //~v61pI~
              {                                                    //~v61pI~
                if (rc=uftp3getputrespchk(0,puftph,cmd,newsrc,&stdo,&stdoctr,ENOENT),rc)//~v61pI~
                	break;                                         //~v61pI~
              }                                                    //~v61pI~
              else                                                 //~v61pI~
              {                                                    //~v61pI~
                if (rc=uftpsimplerespchk(cmd,"226 5** ",newsrc,&stdo,&stdoctr,ENOENT),rc)//~v5arR~
                    break;
              }                                                    //~v61pI~
                filectr++;
            }//dir list
        }
        break;
    }
    Ppufp->UFPcmdokctr=filectr;
    ufree(Ppstdo);
    return rc;
}//uftpcopyrchk
//**************************************************************** //~v59rM~
//uftpcopystmt                                                     //~v59rM~
//  write get/put statement                                        //~v59rM~
//**************************************************************** //~v59rM~
int uftpputstmt(PUFTPPARM Ppufp,char *Pcmd,char *Pfnm)             //~v59rM~
{                                                                  //~v59rM~
//  char ftpcmd[_MAX_PATH+16];                                     //~v59rM~//~v6H7R~
    char ftpcmd[FTP_MAXPATH2+16];                                  //~v6H7I~
//****************************                                     //~v59rM~
    if (Pfnm)                                                      //~v59rM~
      if (*Pfnm=='\"')	//already enclosed                         //~v5bfI~
		sprintf(ftpcmd,"%s %s\n",Pcmd,Pfnm);                       //~v5bfI~
      else                                                         //~v5bfI~
		sprintf(ftpcmd,"%s \"%s\"\n",Pcmd,Pfnm);                   //~v5bfR~
    else                                                           //~v59rM~
		sprintf(ftpcmd,"%s\n",Pcmd);                               //~v59rM~
//  fprintf(Ppufp->UFPpfh,ftpcmd);                                 //~v59rM~//~v6DiR~
    fprintf(Ppufp->UFPpfh,"%s",ftpcmd);                            //~v6DiI~
    uftplog(0,ftpcmd);                                             //~v59rM~
    return 0;                                                      //~v59rM~
}//uftpputstmt                                                     //~v59rM~
//**************************************************************** //~v6H7I~
//  write get statement with 2 filename                            //~v6H7I~
//**************************************************************** //~v6H7I~
int uftpputstmt2(PUFTPPARM Ppufp,char *Pcmd,char *Pfnm,char *Pfnm2)//~v6H7I~
{                                                                  //~v6H7I~
	char ftpcmd[FTP_MAXPATH2+16];    //remote                      //~v6H7I~
	char ftpcmd2[FTP_MAXPATH];         //local                     //~v6H7I~
//****************************                                     //~v6H7I~
    if (*Pfnm=='\"')  //already enclosed                           //~v6H7I~
      sprintf(ftpcmd,"%s %s",Pcmd,Pfnm);                           //~v6H7I~
    else                                                           //~v6H7I~
      sprintf(ftpcmd,"%s \"%s\"",Pcmd,Pfnm);                       //~v6H7I~
    if (*Pfnm2=='\"')	//already enclosed                         //~v6H7I~
		sprintf(ftpcmd2," %s\n",Pfnm2);                            //~v6H7I~
    else                                                           //~v6H7I~
		sprintf(ftpcmd2," \"%s\"\n",Pfnm2);                        //~v6H7I~
    strcat(ftpcmd,ftpcmd2);                                        //~v6H7I~
    fprintf(Ppufp->UFPpfh,"%s",ftpcmd);                            //~v6H7I~
    uftplog(0,ftpcmd);                                             //~v6H7I~
    return 0;                                                      //~v6H7I~
}//uftpputstmt2                                                    //~v6H7I~
//**************************************************************** //~v59rI~
//file time stamp copy for local file                              //~v59rI~
//*retrn:rc                                                        //~v59rI~
//**************************************************************** //~v59rI~
int uftpcopyftime(PUFTPPARM Ppufp)                                 //~v59rI~
{                                                                  //~v59rI~
	PUDIRLIST pudirlist;                                           //~v59rI~
//  PUFTPHOST puftph;                                              //~v5deR~
    int flag,rc=0,rc2,pudlctr,ii,tpathlen,opt,ftimeasw;            //~v59rR~
//  char newtgt[_MAX_PATH],*ptarget;                               //~v59rI~//~v6H7R~
    char newtgt[FTP_MAXPATH],*ptarget;                             //~v6H7I~
    FDATE fdt;                                                     //~v59rR~
    FTIME ftm;                                                     //~v59rR~
//****************************                                     //~v59rI~
//  puftph=Ppufp->UFPpuftph;                                       //~v5deR~
    opt=Ppufp->UFPopt;                                             //~v59rI~
    if (opt & DCPY_FTPCOPYFTIMEY)                                  //~v59rI~
    	ftimeasw=1;                                                //~v59rI~
    else                                                           //~v59rI~
    if (opt & DCPY_FTPCOPYFTIMEN)                                  //~v59rI~
    	ftimeasw=0;                                                //~v59rI~
    else                                                           //~v59rI~
//#ifdef AIX                                                       //~v5deR~
//    	ftimeasw=0;                                                //~v5deR~
//#else                                                            //~v5deR~
    	ftimeasw=1;                                                //~v59rI~
//#endif                                                           //~v5deR~
    flag=Ppufp->UFPflag;                                           //~v59rM~
    ptarget=Ppufp->UFPnewtgt;                                      //~v59rI~
    if (flag & UFPF_SFILE)                                         //~v59rI~
    {                                                              //~v59rI~
	    fdt=Ppufp->UFPsfstat3->fdateLastWrite;                     //~v59rI~
    	ftm=Ppufp->UFPsfstat3->ftimeLastWrite;                     //~v59rI~
    	if (ftimeasw)                                              //~v59rI~
//      	if (!(Ppufp->UFPsfstat3->attrFile & FILE_FTPJST))      //~v5deR~
//  	    	uftpajustjst(puftph,&fdt,&ftm);                    //~v5deR~
    	return usetftime(ptarget,fdt,ftm);                         //~v59rR~
        return 0;                                                  //~v5deI~
    }                                                              //~v59rI~
//dir member                                                       //~v59rR~
    pudlctr=Ppufp->UFPpudlno;                                      //~v59rI~
    pudirlist=Ppufp->UFPpudl;                                      //~v59rI~
    strcpy(newtgt,ptarget);                                        //~v59rI~
//  tpathlen=strlen(newtgt);                                       //~v59rR~//~v6D0R~
    tpathlen=(int)strlen(newtgt);                                  //~v6D0I~
    if (!ROOTDIR_LOCAL(newtgt))                                    //~v59rR~
		*(newtgt+tpathlen++)=Ppufp->UFPtsepc;                      //~v59rR~
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err        //~v59rI~
    {                                                              //~v59rI~
        if (!strcmp(pudirlist->name,".")        //curr             //~v59rI~
        ||  !strcmp(pudirlist->name,".."))      //parent           //~v59rI~
            continue;                                              //~v59rI~
        if (UCBITCHK(pudirlist->attr,(FILE_DIRECTORY|FILE_SPECIAL))) //source dir//~v59rI~
            continue;                                              //~v59rI~
        strcpy(newtgt+tpathlen,pudirlist->name);      //parent     //~v59rI~
    	fdt=pudirlist->date;                                       //~v59rR~
		ftm=pudirlist->time;                                       //~v59rR~
	    if (ftimeasw)                                              //~v59rI~
        {                                                          //~v5deI~
//      	if (!(pudirlist->attr & FILE_FTPJST))                  //~v5deR~
//  	    	uftpajustjst(puftph,&fdt,&ftm);                    //~v5deR~
    	rc2=usetftime(newtgt,fdt,ftm);                             //~v59rR~
        if (rc2)                                                   //~v59rI~
        	rc=4;                                                  //~v59rI~
        }//timeset req                                             //~v5deI~
    }//dir list                                                    //~v59rI~
    return rc;                                                     //~v59rI~
}//uftpcopyftime                                                   //~v59rR~
//**************************************************************** //~v5frI~
//file timestamp compare                                           //~v5frI~
//*retrn:1:source is new,-1:source is old,0:source=target          //~v5frI~
//**************************************************************** //~v5frI~
int ufileftpcopytschk(int Popt,char *Psfnm,FDATE Psdate,FTIME Pstime,//~v5frR~
						char *Ptfnm,FDATE Ptdate,FTIME Pttime)     //~v5frI~
{                                                                  //~v5frI~
	int compsw;                                                    //~v5frI~
    UCHAR editts[32];                                              //~v5frI~
//****************************                                     //~v5frI~
//  compsw=(LONG)(FDATETIME2ULONG(Psdate,Pstime)-FDATETIME2ULONG(Ptdate,Pttime));//~v5frR~//~v6D1R~
    compsw=(int)(FDATETIME2ULONG(Psdate,Pstime)-FDATETIME2ULONG(Ptdate,Pttime));//~v6D1I~
	if (!(Popt & DCPY_NOSKIPMSG))//issue errmsg                    //~v5frI~
    {                                                              //~v5frI~
      	ufdateedit(Ptdate,"YY-MM-DD",editts);                      //~v5frR~
        *(editts+8)=' ';                                           //~v5frI~
        uftimeedit(Pttime,"HH:MM:SS",editts+9);                    //~v5frR~
        if (!compsw)                                               //~v5frI~
        {                                                          //~v5frI~
//          uerrmsg("&s copy bypassed(same timestamp:%s).",        //~v61iR~
            uerrmsg("%s copy bypassed(same timestamp:%s).",        //~v61iI~
                    "%s コピー回避(同一FileTimeStamp:%s)",         //~v5frR~
                    Psfnm,editts);                                 //~v5frR~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
        }                                                          //~v5frI~
        if (compsw<0)//source is old                               //~v5frI~
        {                                                          //~v5frI~
//          uerrmsg("&s copy bypassed(target is new timestamp:%s).",//~v61iR~
            uerrmsg("%s copy bypassed(target is new timestamp:%s).",//~v61iI~
                    "%s コピー回避(宛先が新しいFileTimeStamp:%s)", //~v5frR~
                    Psfnm,editts);                                 //~v5frR~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
        }                                                          //~v5frI~
    }                                                              //~v5frI~
    return compsw;                                                 //~v5frI~
}//ufileftpcopytschk                                               //~v5frI~
//**************************************************************** //~v59rM~
//make target dir                                                  //~v59rM~
//*retrn:rc                                                        //~v59rM~
//**************************************************************** //~v59rM~
int uftpmktdir(PUFTPHOST Ppuftph,int Pflag,char *Ptarget)          //~v5afR~
{                                                                  //~v59rM~
	int rc;                                                        //~v59rM~
//*******************                                              //~v59rM~
    if (Pflag & UFPF_UP)		//target is remote                 //~v59rM~
        rc=uftpmkdir(Ppuftph,Ptarget,0,0);                         //~v5afR~
    else           //target is local                               //~v59rM~
        rc=umkdir(Ptarget);                                        //~v59rM~
    return rc;                                                     //~v59rM~
}//uftpmktdir                                                      //~v59rM~
//****************************************************************
//uftperrsourceisroot
//  write get/put statement
//****************************************************************
int uftperrsourceisroot(void)
{
	uerrmsg("Root cannot be FTP source",
    		"ルートはFTPコピーできません");
    return -1;
}//uftperrsourceisroot
//****************************************************************
//uftperrtargetisnotdir
//  write get/put statement
//****************************************************************
int uftperrtargetisnotdir(char *Pfnm)
{
    uerrmsg("FTP target(%s) should be directory",0,
                Pfnm);
    return -1;
}//uftperrtargetisnotdir
//****************************************************************
//uftperrtargetisnotdir
//  write get/put statement
//****************************************************************
int uftperrdir2file(char *Pfnm)
{
//  uerrmsg("FTP same name target file exist as source dir name",0,//~v61iR~
    uerrmsg("FTP same name target file exist as source dir name (%s)",0,//~v61iI~
                Pfnm);
	uftplog(FTPLOG_ERRM,0);	//logging errmsg                       //~v61bI~
    return -1;
}//uftperrtargetisnotdir
//****************************************************************
//ufile and dir
//****************************************************************
int uftpfileanddir(char *Pfnm,char *Pdirnm)
{
	uerrmsg("%s is file and %s is directory",
            "%s は ファイル, %s はディレクトリー",
                        Pfnm,Pdirnm);
	uftplog(FTPLOG_ERRM,0);	//logging errmsg                       //~v61bI~
    return -1;
}//uftpfileanddir
//**************************************************************** //~v5arI~
//ufile and dir                                                    //~v5arI~
//**************************************************************** //~v5arI~
int uftpappenddir2dir(char *Psdir,char *Ptdir)                     //~v5arI~
{                                                                  //~v5arI~
    uerrmsg("use wild card for append between dir(%s & %s)",0,     //~v5arI~
				Psdir,Ptdir);                                      //~v5arI~
    return -1;                                                     //~v5arI~
}//uftpappenddir2dir                                               //~v5arI~
#ifdef ARMXXE                                                      //~v6daM~
//**************************************************************** //~v6daM~
//callback func to process file entry                              //~v6daM~
//*retrn:rc                                                        //~v6daM~
//**************************************************************** //~v6daM~
int uftpsmbj_copycallback(PUFTPPARM Ppvoid,PUSMBJCMDPARM Ppusmbjcp)//~v6daR~
{                                                                  //~v6daM~
	PUFTPPARM pufp;                                                //~v6daM~
	PUDIRLIST pudirlist;                                           //~v6daM~
	PUFTPHOST puftph;                                              //~v6daM~
    int rc=0,pudlctr,ii,flag,spathlen,tpathlen,filectr=0,hostnmlen,pos,opt;//~v6daM~
    int appendsw,append2fsw,targetfsw;                             //~v6daM~
    char *ptfpath,*pfnm,*psfpath,*pnewtgt,*pappendto=NULL;         //~v6hcR~
//  char lcdpath[_MAX_PATH],cdpath[_MAX_PATH],appendopd[_MAX_PATH+1+_MAX_PATH];//~v6daM~//~v6H7R~
//  char lcdpath[FTP_MAXPATH],cdpath[FTP_MAXPATH],appendopd[FTP_MAXPATH2+1];//~v6H7I~//+v702R~
    char lcdpath[FTP_MAXPATH],cdpath[FTP_MAXPATH]                          ;//+v702I~
//***********************************                              //~v6daM~
    pufp=(PUFTPPARM)Ppvoid;                                        //~v6daR~
    opt=pufp->UFPopt;                                              //~v6daM~
    puftph=pufp->UFPpuftph;                                        //~v6daM~
//	pufp->UFPpfh=Ppfh;		//no use stdin card                    //~v6daR~
    pudirlist=pufp->UFPpudl;                                       //~v6daM~
    pudlctr=pufp->UFPpudlno;                                       //~v6daM~
    flag=pufp->UFPflag;                                            //~v6daM~
    psfpath=pufp->UFPsfpath;                                       //~v6daM~
    spathlen=pufp->UFPspathlen;                                    //~v6daM~
    tpathlen=pufp->UFPtpathlen;                                    //~v6daM~
    ptfpath=pufp->UFPtfpath;                                       //~v6daM~
    pnewtgt=pufp->UFPnewtgt;                                       //~v6daM~
    hostnmlen=puftph->UFTPHhostnmlen;                              //~v6daM~
    appendsw=opt & DCPY_APPEND;                                    //~v6daM~
    append2fsw=(appendsw && (flag & (UFPF_TNEW|UFPF_TFILE)));  //file->file2//~v6daM~
    targetfsw=append2fsw || (flag & UFPF_F2FCPY);  //file->file2   //~v6daM~
    if (flag & UFPF_UP)                                            //~v6daM~
    {                                                              //~v6daM~
//*SmbOutputStream supports append mode                            //~v6daI~
//      if (appendsw)                                              //~v6daR~
//          if (UFTPH_ISSMB(puftph))                               //~v6daR~
//          {                                                      //~v6daR~
//  			return uftpnotsupported("append(Upload)","Samba Server");//~v6daR~
//          }                                                      //~v6daR~
//*smb replace existing file;no need to delete                     //~v6daI~
//  	if ((flag & UFPF_RENCPY) && !(flag & UFPF_TNEW)) //repl new name existing//~v6daR~
//    	{                                                          //~v6daR~
//       if (!UFTPH_ISSMB(puftph))	//smb replace existing file;no need to delete//~v6daR~
//        if (!UFTPHISPSFTP(puftph))	//psftp replace existing file//~v6daR~
//        {                                                        //~v6daR~
//  		uftpputstmt(pufp,"delete",pnewtgt+hostnmlen+1);        //~v6daR~
//      	flag|=UFPF_DELTGT;                                     //~v6daR~
//        }                                                        //~v6daR~
//    	}                                                          //~v6daR~
      if (targetfsw)                                               //~v6daM~
      {                                                            //~v6daM~
        pappendto=ptfpath+hostnmlen+1;                             //~v6daM~
      }                                                            //~v6daM~
      else                                                         //~v6daM~
      {                                                            //~v6daM~
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v6daM~
        	strcpy(cdpath,ptfpath+hostnmlen+1);                    //~v6daM~
        else                                                       //~v6daM~
        	strcpy(cdpath,pnewtgt+hostnmlen+1);                    //~v6daM~
//  	uftpputstmt(pufp,"cd",cdpath);                             //~v6daR~
    	flag|=UFPF_RCD;                                            //~v6daM~
      }//!(append target is file)                                  //~v6daM~
        strcpy(lcdpath,psfpath);                                   //~v6daM~
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v6daM~
        {                                                          //~v6daM~
        	pos=spathlen;                                          //~v6daM~
//ARM is linux                                                     //~v6daI~
//#ifdef W32                                                       //~v6daR~
//        	if (pos==2)                                            //~v6daR~
//#else                                                            //~v6daR~
        	if (pos==0)                                            //~v6daM~
//#endif                                                           //~v6daR~
				pos++;                                             //~v6daM~
            *(lcdpath+pos)=0;                                      //~v6daM~
        }                                                          //~v6daM~
//  	uftpputstmt(pufp,"lcd",lcdpath);                           //~v6daR~
    	strcpy(pufp->UFPlcdpath,lcdpath);                          //~v6daM~
//  	uftpputstmt(pufp,FTP_LOCALCMD_PWD,0);	//for lcd resp msg chk//~v6daR~
//  	uftpputstmt(pufp,"pwd",0);	//for lcd resp msg chk         //~v6daR~
	  	flag|=UFPF_LCD;                                            //~v6daR~
    }                                                              //~v6daM~
    else           //download                                      //~v6daM~
    {                                                              //~v6daM~
        strcpy(cdpath,psfpath+hostnmlen+1);                        //~v6daM~
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v6daM~
        {                                                          //~v6daM~
            pos=spathlen-(hostnmlen+1);                            //~v6daM~
            if (!pos)   //root                                     //~v6daM~
                pos++;                                             //~v6daM~
            *(cdpath+pos)=0;                                       //~v6daM~
        }                                                          //~v6daM~
//      uftpputstmt(pufp,"cd",cdpath);                             //~v6daR~
        flag|=UFPF_RCD;                                            //~v6daM~
        if ((flag & (UFPF_SFILE|UFPF_SWILD)))                      //~v6daM~
        	strcpy(lcdpath,ptfpath);                               //~v6daM~
        else                                                       //~v6daM~
        	strcpy(lcdpath,pnewtgt);                               //~v6daM~
      	if (targetfsw)                                             //~v6daM~
        	*(lcdpath+tpathlen)=0;                                 //~v6daM~
//  	uftpputstmt(pufp,"lcd",lcdpath);                           //~v6daR~
    	strcpy(pufp->UFPlcdpath,lcdpath);                          //~v6daR~
//  	uftpputstmt(pufp,FTP_LOCALCMD_PWD,0);	//for lcd resp msg chk//~v6daR~
//  	uftpputstmt(pufp,"pwd",0);                                 //~v6daR~
    	flag|=UFPF_LCD;                                            //~v6daR~
    }                                                              //~v6daM~
    pufp->UFPflag|=flag;	//tell to rchk                         //~v6daM~
//*copy required info                                              //~v6daI~
    if (flag & UFPF_RCD)                                           //~v6daR~
	    memcpy(Ppusmbjcp->USJCPcdpath,cdpath,sizeof(Ppusmbjcp->USJCPcdpath));//~v6daM~
    else                                                           //~v6daR~
        *Ppusmbjcp->USJCPcdpath=0;                                 //~v6daM~
    memcpy(Ppusmbjcp->USJCPlcdpath,pufp->UFPlcdpath,sizeof(Ppusmbjcp->USJCPlcdpath));//~v6daI~
//write get/put cmd                                                //~v6daM~
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err        //~v6daM~
    {                                                              //~v6daM~
    	if (flag & UFPF_SFILE)  //source is file                   //~v6daM~
        	pfnm=psfpath+spathlen+1;                               //~v6daM~
        else                                                       //~v6daM~
        {                                                          //~v6daM~
            if (pudirlist->attr & FILE_FTPWKSL2)  //skip existing  //~v6daM~
            	continue;                                          //~v6daM~
	        pfnm=pudirlist->name;                                  //~v6daM~
            if (!strcmp(pfnm,".")        //curr                    //~v6daM~
            ||  !strcmp(pfnm,".."))      //parent                  //~v6daM~
                continue;                                          //~v6daM~
            if (UCBITCHK(pudirlist->attr,(FILE_DIRECTORY|FILE_SPECIAL))) //source dir//~v6daM~
                continue;                                          //~v6daM~
        }                                                          //~v6daM~
        if (flag & UFPF_UP)                                        //~v6daM~
        {                                                          //~v6daM~
      	  if (appendsw)                                            //~v6daM~
          {                                                        //~v6daM~
    	    if (append2fsw)  //append to file                      //~v6daR~
//          	sprintf(appendopd,"\"%s\" \"%s\"",pfnm,pappendto); //~v6daR~
  	    		jnismb_putstmt(0,Ppusmbjcp,"append",pfnm,pappendto);//~v6daR~
            else                                                   //~v6daR~
//          	sprintf(appendopd,"\"%s\" \"%s\"",pfnm,pfnm);      //~v6daR~
  	    		jnismb_putstmt(0,Ppusmbjcp,"append",pfnm,pfnm);    //~v6daR~
//  	    uftpputstmt(pufp,"append",appendopd);                  //~v6daR~
          }                                                        //~v6daM~
          else                                                     //~v6daM~
           if (flag & UFPF_RENCPY)  //rename file to file          //~v6daM~
           {                                                       //~v6daM~
//           if (UFTPH_ISSMB(puftph))                              //~v6daR~
//  			uftp3smb_putstmt(UFTPSMBCMD_PUT2,puftph,pufp->UFPpfh,pfnm,pappendto);//~v6daR~
//           else                                                  //~v6daR~
//           {                                                     //~v6daR~
//          sprintf(appendopd,"\"%s\" \"%s\"",pfnm,pappendto);     //~v6daR~
//          if (UFTPHISPSFTP(puftph))                              //~v6daR~
//  	    uftpputstmt(pufp,"put",appendopd);  //psftp put support remote filename parameter//~v6daR~
//          else                                                   //~v6daR~
//  	    uftpputstmt(pufp,"append",appendopd);                  //~v6daR~
//           }                                                     //~v6daR~
             jnismb_putstmt(0,Ppusmbjcp,"put",pfnm,pappendto);     //~v6daR~
           }                                                       //~v6daM~
           else                                                    //~v6daM~
//		    uftpputstmt(pufp,"put",pfnm);                          //~v6daR~
     		jnismb_putstmt(0,Ppusmbjcp,"put",pfnm,pfnm);           //~v6daR~
        }//up                                                      //~v6daM~
        else                                                       //~v6daM~
//  		uftpputstmt(pufp,"get",pfnm);                          //~v6daR~
    		jnismb_putstmt(0,Ppusmbjcp,"get",pfnm,pfnm);           //~v6daR~
        filectr++;                                                 //~v6daM~
    }//dir list                                                    //~v6daM~
    pufp->UFPcmdctr=filectr;                                       //~v6daM~
    if (!filectr)                                                  //~v6daM~
    {                                                              //~v6daI~
        if (pudlctr)                                               //~v6daI~
    		rc=ERROR_NO_MORE_FILES;	//request skip ftp cmd         //~v6daI~
        else                                                       //~v6daI~
    		rc=ENOENT;	//request skip ftp cmd                     //~v6daR~
    }                                                              //~v6daI~
    return rc;                                                     //~v6daM~
}//uftpsmbj_copycallback                                           //~v6daM~
//**************************************************************** //~v6daM~
//*uload/download by jcifs                                         //~v6daM~
//**************************************************************** //~v6daM~
int uftpsmbj_updowncmd(int Pftpopt,PUFTPPARM Ppufp,PUFTPHOST Ppuftph)//~v6daM~
{                                                                  //~v6daM~
	int rc;                                                        //~v6daM~
    USMBJCMDPARM usmbjcp;                                          //~v6daI~
//******************************                                   //~v6daM~
    memset(&usmbjcp,0,USMBJCMDPARMSZ);                             //~v6daI~
    usmbjcp.USJCPpuftph=Ppuftph;                                   //~v6daI~
	rc=uftpsmbj_copycallback(Ppufp,&usmbjcp);                      //~v6daR~
    if (!rc)                                                       //~v6daI~
    {                                                              //~v6daI~
		rc=jnismb_getput(0,&usmbjcp);                              //~v6daR~
    }                                                              //~v6daI~
    uqfree(&usmbjcp.USJCPcmdq);                                    //~v6daI~
    return rc;                                                     //~v6daM~
}//uftpsmbj_updowncmd                                              //~v6daM~
#endif                                                             //~v6daM~
