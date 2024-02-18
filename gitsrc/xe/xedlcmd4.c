//*CID://+vb7fR~:                             update#=  228;       //~vb7fR~
//*************************************************************
//*xedlcmd4.c
//* each dir line cmd process
//* undelete(u)
//*************************************************************
//vb7f:170109 FTP:not found msg if deleded undelsavefile           //~vb7fI~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb7c:170106 longname support; del on root file(xmove to undeldir fails)//~vb7cI~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vay4:141108 undelprep for reserved name(\\.\g:\src\... fmt)      //~vay4I~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//van2:131127 support deletion of invalid(wildcard) name entry on dir list//~van2I~
//vaiC:130627 bypass slink err msg for xmove by del lcmd           //~vaiCI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//vaa1:110907 (LNX:BUG)undelterm abend if % dlcmd used(Sdrivelist is allocted only 1 entry)//~vaa1I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v71j:061017 3270:undel lcmd support                              //~v71jI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71e:061011 3270:Rename/delete support                           //~v71eI~
//v71c:061006 3270:not supported msg                               //~v71cI~
//v62k:050321 need not save rename info ween keep mode for remote file because undel file is in same dir//~v62kI~
//v62j:050320 (BUG)undel from undeldir reverse sequence recov(name changed)//~v62jR~
//v62h:050316 ftp undel support                                    //~v62hI~
//v53S:031103 avoid not found msg for undel dir search             //~v43SI~
//v48m:020516 (AIX)mdos disk not supported rmdir                   //~v48mI~
//v45H:011228 allow move on existing file                          //~v45HI~
//v45E:011227 change default undel dir to ~(home)                  //~v45EI~
//v44z:011207 UNX:support undel dir name change  by env-var        //~v44zI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v21a:001209 LINUX support:lower case exe name(xe)                //~v21aI~
//v20E:001103 (BUG)undel from save dir:destroy UDHrenamesv-->not alloced err when free)//~v20EI~
//v20D:001103 LINUX support:filename compare is case sensitive     //~v20DI~
//v19Y:000929 LINUX support(dir tbit means protection of another owners file from rename/unlink)//~v19YI~
//            But it is effective only if the dir owner is not me) //~v19YI~
//v19U:000928 LINUX support(undo dirlist;pre chk owner;only owner can unlink/rename)//~v19UI~
//v19T:000928 LINUX support(Global userid var;from now new grobal is on xegbl.h)//~v19TI~
//v19M:000925 LINUX support(user id by 5 digit for undo dir)       //~v19MI~
//v19K:000925 LINUX support(No drive id for undo of dirlist)       //~v19KI~
//v19G:000925 LINUX support(no driveid:temporary modification until get file system info)//~v19GI~
//v19F:000925 LINUX support(XE_UNDEL_%d:add uid to undo dir name for permition)//~v19FI~
//v19E:000904 LINUX support(XE!UNDEL-->XE_UNDEL; ! has mean to bash)//~v19EI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v10r:990327 display lineno on dir list,accum size/line cnt to dir line//~v10rI~
//v0f0:971010 long filename support                                //~v0f0I~
//            file5.c/dlcmd4.c:ext search from last                //~v0f0I~
//v09b:970510:disk free space display                              //~v09bI~
//            -req update free space info(dlcmd3.c,dlcmd4.c,dlcmd3.h)//~v09bI~
//v085:961024:W95 VC                                               //~v085I~
//v07t:960916:(BUG)rename err when del XE!UNDEL(bug when del root dir)//~v07tI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v07lI~
//v05Z:960203:DOS inter dir move of dir                         //~v05ZI~
//v05V:960203:.(BUG)reset expand id when undo(entry deleted)    //~v05VI~
//            .del undel entry expanded before del              //~v05VI~
//v05Q:960121:xdd force option for move inter-drive,delete undel save at term//~v05QI~
//v05N:960114:add function undo rename/move on dir list         //~v05NI~
//v05u:951202:undelete dlcmd(rename when delete)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v19YI~
	#include <sys/stat.h>                                          //~v19YR~
	#include <dirent.h>                                            //~vaa0I~
#else  //!UNX                                                      //~v19YI~
#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
    	#include <dos.h>                                           //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
    #endif                                                         //~v085I~
#endif
#endif //!UNX                                                      //~v19YI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ufile.h>
#include <ufile2.h>
#include <ufile3.h>                                             //~v05ZI~
#include <uedit.h>
#include <ustring.h>                                               //~v07lI~
#include <uftp.h>                                                  //~v62hI~
#ifdef UNX                                                         //~vaa0I~
#include <ufile1l.h>                                               //~vaa0I~
#endif                                                             //~vaa0I~
#include <ufile1f.h>                                               //~v62hR~
#include <ufilew.h>                                                //~vay4I~
#include <u3270.h>                                                 //~v71eI~
#include <utrace.h>                                                //~vb7fI~
                                                                   //~v19FI~
#ifdef UNX                                                         //~v19FI~
	#include <uunxsub.h>                                           //~v19FI~
#endif                                                             //~v19FI~

#include "xe.h"
#include "xescr.h"
#include "xepan.h"
#include "xefile.h"
#include "xefile2.h"
#include "xedir.h"
#include "xedir2.h"
#include "xefunc.h"
#include "xedlcmd.h"
#include "xedlcmd2.h"
#include "xedlcmd3.h"
#include "xedlcmd4.h"
#include "xedcmd.h"
#include "xesub.h"
#include "xegbl.h"                                                 //~v19TI~
#include "xeftp.h"                                                 //~v62hI~
#include "xeerr.h"                                                 //~v71cI~
//*******************************************************
#define INDEXRECSZ      _MAX_PATH+1+MAXFILENAME+2	//tab and crlf+null
                                                                   //~v19KI~
#ifdef UNX                                                         //~v19KI~
	#define LASTDRIVE   1   //use /tmp only                        //~v19KI~
//  #define LASTDRIVE2  1                                          //~vaa1R~
    #define LASTDRIVE2  2   //for ftp entry                        //~vaa1I~
#else                                                              //~v19KI~
#define LASTDRIVE       26
#define LASTDRIVE2      28     //A-Z,ftp,\(0x5c-0x5a=0x1b=27)      //~v7abI~
#endif                                                             //~v19KI~
                                                                   //~v19KI~
//#define TOPDIRNAME		"\\XE!UNDEL"                           //~v19aR~
//#define TOPDIRNAME		DIR_SEPS "XE!UNDEL"                    //~v19ER~
                                                                   //~v19FI~
#ifdef UNX                                                         //~v19FI~
    #define ENV_UNDELDIR    "xe_undel"                             //~v44zR~
    #define TMPDIR          "/tmp"                                 //~v19KI~
    #define DEFAULT_UDIR    "~"                                    //~v45EI~
//  #define UIDPOS          14                                     //~v44zR~
    #define UIDLEN           5                                     //~v19MR~
    #define UIDPOS          (Stopdirnamesz-UIDLEN)                 //~v44zI~
	#define TOPDIRNAME		TMPDIR DIR_SEPS "xe_undel_12345"       //~v21aR~
//  #define TOPDIRNAMESZ    19                                     //~v44zR~
    #define TOPDIRNAMESZ_DEF 19                                    //~v44zI~
    #define TOPDIRNAMESZ    Stopdirnamesz                          //~v44zR~
#else                                                              //~v19FI~
#define TOPDIRNAME		DIR_SEPS "XE_UNDEL"                        //~v19EI~
#define TOPDIRNAMESZ    9
#endif                                                             //~v19FI~
                                                                   //~v19FI~
#define DATEFMT1        "YY-MM-DD"			//for utimeedit
#define DATEFMT2        "%02d-%02d-%02d%c"	//to chk dir name
#define DATEDIRNAMESZ   8
//#define SEQDIRMASK		"\\\?\?\?\?\?\?!\?"                    //~v19aR~
//#define SEQDIRMASK		DIR_SEPS "\?\?\?\?\?\?!\?"             //~v19ER~
#define SEQDIRMASK		DIR_SEPS "\?\?\?\?\?\?_\?"                 //~v19EI~
//#define SEQDIREDIT		"\\%06d!"                              //~v19aR~
//#define SEQDIREDIT		DIR_SEPS "%06d!"                       //~v19ER~
#define SEQDIREDIT		DIR_SEPS "%06d_"                           //~v19EI~
#define DATAID          "D"
#define INDEXID         "-"
#define SEQDIRNAMESZ    8
#define SEQDIRSEQNOSZ	6
//#define SEQEDITPOS     (2+TOPDIRNAMESZ+1+DATEDIRNAMESZ)          //~v19KR~
#define SEQEDITPOS     (ROOTDIRPOS+TOPDIRNAMESZ+1+DATEDIRNAMESZ)   //~v19KI~
//#define SAVEFNAMEPOS   (2+TOPDIRNAMESZ+1+DATEDIRNAMESZ+1+SEQDIRNAMESZ+1)//~v19KR~
#define SAVEFNAMEPOS   (ROOTDIRPOS+TOPDIRNAMESZ+1+DATEDIRNAMESZ+1+SEQDIRNAMESZ+1)//~v19KI~
                                                                   //~v19KI~
#ifdef UNX                                                         //~v19KI~
//  #define DRIVEID(driveletter) 0	/*always use /tmp */           //~v62kR~
	#define DRIVEID(fpath) (uftpisremote(fpath,0) ? LASTDRIVE : 0)//lastdrive//~v62kI~
#else  //!UNX                                                      //~v19KI~
//#define DRIVEID(driveletter) (toupper(driveletter)-'A')          //~v62hR~
	#ifdef FTPSUPP                                                 //~v62hI~
//  	#define DRIVEID(fpath) (uftpisremote(fpath,0) ? LASTDRIVE : toupper(*fpath)-'A')// c: +v62hR~//~vay4R~
    	#define DRIVEID(fpath) (uftpisremote(fpath,0) ? LASTDRIVE : toupper(*(fpath))-'A')// c: +v62hR~//~vay4I~
    #else                                                          //~v62hI~
//  	#define DRIVEID(fpath) (toupper(*fpath)-'A')               //~vay4R~
    	#define DRIVEID(fpath) (toupper(*(fpath))-'A')             //~vay4I~
    #endif                                                         //~v62hI~
	#define DRIVEID_UNC     0x1b    //for \:(0x5c-0x5a=0x1b=27)    //~v7abI~
#endif //!UNX                                                      //~v19KI~
#ifdef FTPSUPP                                                     //~v62hI~
    #define FTPUNDELPREFIX  "..xe.."                               //~v62hR~
    #define FTPUNDELPOSTFIX ".._~"                                 //~v62hI~
    #define FTPUNDELPREFIXLEN    (sizeof(FTPUNDELPREFIX)-1)        //~v62hI~
    #define FTPUNDELPOSTFIXLEN   21 //.._~yymmdd-hhmmss.mmm        //~v62hR~
#endif                                                             //~v62hI~
                                                                   //~v19KI~
//*******************************************************
typedef struct _UNDELDRIVE           /* undelete drive list */
         {
            int  	UDDindex;
			UQUEH 	UDDqueh;		//undel que
         } UNDELDRIVE;
typedef struct _UNDELENTRY           /* undelete entry list */
         {
			UQUEE 	UDEqelem;		//undel que
            int     UDEflag;                                       //~v62hI~
#define UDEFFTP     0x01            //remote file/dir              //~v62hR~
#define UDEFFTPDIR  0x02            //remote dir                   //~v62hR~
            UCHAR   UDEmembname[MAXFILENAME];    //member name
            UCHAR   UDErsv[1];      //delm
            UCHAR   UDEorgfname[1]; //deleted originaml file name
         } UNDELENTRY;
typedef UNDELENTRY *PUNDELENTRY;
#define UNDELENTRYSZ sizeof(UNDELENTRY)
//*******************************************************
static UCHAR Sundeldate[DATEDIRNAMESZ+1];
                                                                   //~v19FI~
#ifdef UNX                                                         //~v19FI~
//  static UCHAR Stopdirname[TOPDIRNAMESZ+12]=TOPDIRNAME;          //~v44zR~
    static UCHAR Stopdirname[_MAX_PATH]=TOPDIRNAME;                //~v44zI~
#else                                                              //~v19FI~
static UCHAR *Stopdirname=TOPDIRNAME;
#endif                                                             //~v19FI~
                                                                   //~v19FI~
static UCHAR *Sseqdatadiredit=SEQDIREDIT DATAID "%c";
                                                                   //~v19FI~
static UCHAR Sdatadirname[_MAX_PATH];
//static UNDELDRIVE        Sdrivelist[LASTDRIVE];                  //~v62kR~
//static UNDELDRIVE        Sdrivelist[LASTDRIVE+1];                //~v7abR~
static UNDELDRIVE        Sdrivelist[LASTDRIVE2]; //a-z,"/"(ftp),"\"(unc)//~v7abI~
                                                                   //~v19KI~
#ifdef UNX                                                         //~v19KI~
static int   Stopdirnamesz=TOPDIRNAMESZ_DEF;	//default 19 for /tmp//~v44zR~
//static  dev_t Stmpfsid;	//file system id of /tmp               //~v44zR~
#else  //!UNX                                                      //~v19KI~
#endif //!UNX                                                      //~v19KI~
//****************************************************************
int dlcmdundelfromsave(PUCLIENTWE Ppcw,PUDLCMD Pplc,
						UCHAR *Pfullpath,UCHAR *Pwkfname,int Pdriveid);
int dlcmdsrchindexf(UCHAR *Pfullpath,UCHAR *Ptarget);
#ifdef UTF8SUPPH                                                   //~va00I~
PUNDELENTRY dlcmdsrchundel(PUDIRLH Ppdh,int Pdriveid,char *Pmembname);//~va00I~
#else                                                              //~va00I~
PUNDELENTRY dlcmdsrchundel(PUDIRLH Ppdh,int Pdriveid);
#endif                                                             //~va00I~
void dlcmdgetdirname(int Pdriveid,UCHAR *Pdirname);
int dlcmdchngname(void);
int dlcmdgetunddir(UCHAR *Pfullpath);
int dlcmdgetunddirsub(UCHAR *Pfullpath);
int dlcmdgetindex(UCHAR *Pmaskname,int Poffset,int Plen);
UCHAR *getundeldate(void);
int errnodata(void);
int errinvaliddata(void);
#ifdef FTPSUPP                                                     //~v62hI~
	int dlcmdftpundelnamechk(UCHAR *Pfullpath);                    //~v62hI~
	int dlcmdftpundelname(UCHAR *Pmembname,UCHAR *Pnewname);       //~v62hR~
	int dlcmdftpclearundelsave(PUQUEH Ppqh);                       //~v62hR~
	int dlcftpmultidelterm(PUFTPHOST Ppuftph,PUQUEH Ppqh);         //~v62hI~
	int dlcmdftpundelfromsave(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDLCMD Pplc,//~v62hR~
								UCHAR *Pfullpath,int Pdriveid);    //~v62hI~
	int dlcmdtsoundelprepdir(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfullpath);//~v71eI~
#endif                                                             //~v62hI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
	int dlcmdUNCundelprepdir(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfullpath);//~v7abR~
	int dlcmdUNCundelprechk(UCHAR *Pfullpath,char *Pnewname);      //~v7abI~
	int dlcmdUNCundelnamechk(UCHAR *Pfullpath);                    //~v7abI~
	int dlcmdUNCclearundelsave(PUQUEH Ppqh);                       //~v7abI~
#endif                                                             //~v7abI~
#ifdef W32                                                         //~vay4I~
	int getReservedFileDriveid(char *Pfullpath,int *Pdrivid);      //~vay4I~
#endif                                                             //~vay4I~
                                                                   //~v19FI~
#ifdef UNX                                                         //~v19FI~
//**************************************************************** //~v19FI~
// dlcmdundelinit                                                  //~v19FI~
// edit top dir name                                               //~v19FI~
//*ret  :rc                                                        //~v19FI~
//**************************************************************** //~v19FI~
void dlcmdundelinit(void)                                          //~v19FI~
{                                                                  //~v19FI~
    FILEFINDBUF3 fb3;                                              //~v19KI~
    char *pc,*tmpdir;                                              //~v44zI~
    char fnwk[_MAX_PATH];                                          //~v44zR~
	UCHAR  fpathname[_MAX_PATH];                                   //~v45EI~
    int len;                                                       //~v44zI~
//***************                                                  //~v19FI~
//  tmpdir=TMPDIR;		//default top dir                          //~v45ER~
//  if (pc=getenv(ENV_UNDELDIR),pc)                                //~v45ER~
//  {                                                              //~v45ER~
        pc=getenv(ENV_UNDELDIR);                                   //~v45EI~
        if (!pc)                                                   //~v45EI~
            pc=DEFAULT_UDIR;                                       //~v45EI~
        ufullpath(fpathname,pc,_MAX_PATH);                         //~v45ER~
        pc=fpathname;                                              //~v45EI~
        if (ROOTDIR(fpathname))                                    //~v45EI~
			pc=TMPDIR;		//default top dir                      //~v45EI~
    	len=(int)strlen(pc);                                       //~v44zI~
    	Stopdirnamesz=len+TOPDIRNAMESZ_DEF-4;//4:len ofv/tmp       //~v44zI~
        memcpy(fnwk,pc,(UINT)len);                                 //~v44zI~
        memcpy(fnwk+len,Stopdirname+4,TOPDIRNAMESZ_DEF-4);         //~v44zI~
//      memcpy(Stopdirname,fnwk,Stopdirnamesz);                    //~v44zI~//~vb30R~
        memcpy(Stopdirname,fnwk,(size_t)Stopdirnamesz);            //~vb30I~
        *(Stopdirname+Stopdirnamesz)=0;                            //~v44zI~
        *(fnwk+len)=0;      //for env chk                          //~v44zI~
        tmpdir=fnwk;                                               //~v44zR~
//  }//env specified                                               //~v45ER~
    sprintf(Stopdirname+UIDPOS,"%05d",Guserid);                    //~v19TR~
    *(Stopdirname+UIDPOS+UIDLEN)=0;	//drop overflow                //~v19FR~
//  if (ufstat(TMPDIR,&fb3))                                       //~v44zR~
    if (ufstat(tmpdir,&fb3))                                       //~v44zI~
    	uerrmsg("%s not found;Undo on dir-list is not avail",0,    //~v19KI~
//  			TMPDIR);                                           //~v44zR~
    			tmpdir);                                           //~v44zI~
//  Stmpfsid=fb3.fsid;                                             //~v44zR~
    return;                                                        //~v19FR~
}//dlcmdundelinit                                                  //~v19FI~
//**************************************************************** //~v19UI~
// dlcmtbitchk                                                     //~v19YR~
// chk file can be del/rename                                      //~v19UI~
// (root or owner only can do unlink/rename another owners file in //~v19YR~
//  another owners dir with t-bit)                                 //~v19YI~
// parm1:pdh                                                       //~v19YR~
// parm2:msg option                                                //~v19YI~
//*ret  :rc 0:root or your own,EACCES(permission err)              //~v19YR~
//**************************************************************** //~v19UI~
int dlcmdtbitchk(PUDIRLH Ppdh,int Popt)                            //~v19YR~
{                                                                  //~v19UI~
	PUDIRLH pdhp;		//parent pdh                               //~v19YR~
//***************                                                  //~v19UI~
    if (!Guserid || Guserid==(int)Ppdh->UDHuid)                    //~v19YR~
    	return 0;	//root or owner is me                          //~v19YR~
    if (!(pdhp=Ppdh->UDHdirptr))                                   //~v19YI~
    	return 0;				//curr may root                    //~v19YI~
    if (Guserid==(int)pdhp->UDHuid)	                               //~v19YR~
    	return 0;				//parent dir is my own             //~v19YI~
    if (FILE_GETMODE(pdhp->UDHattr) & S_ISVTX)	//sticky bit       //~v19YR~
    {                                                              //~v19UI~
    	if (Popt & DLCTBCMSG)                                      //~v19YR~
        	uerrmsg("%s is not yours and parent dir has sticky bit on.",//~v40bR~
        			"%s のオーナーではなく 親dir の \"t\" ビットオンです",//~v19YR~
                    Ppdh->UDHname);                                //~v19YR~
    	return EACCES;				//permission err               //~v19YI~
    }                                                              //~v19UI~
    return 0;                                                      //~v19UI~
}//dlcmdtbitchk                                                    //~v19YR~
#endif                                                             //~v19FI~
                                                                   //~v19FI~
//****************************************************************
// dlcmdundelterm
// housekeeping at term
//*ret  :rc
//****************************************************************
int dlcmdundelterm(void)
{
	PUQUEH 	pqh;
//  PUQUEE 	pqe;                                                   //~v62hR~
	PUNDELENTRY	pue;
    FILE   *fh;
    int     rc=0,ii,ctr;                                        //~v05QR~
	UCHAR unddirname[_MAX_PATH];
    UCHAR indexrec[INDEXRECSZ];
//*******************
//  if (!*Sundeldate)	//no undel prepare                         //~v62kR~
//  	return 0;                                                  //~v62kR~
    UTRACEP("%s:entry\n",UTT);                                     //+vb7fI~
  if (*Sundeldate)	//no undel prepare                             //~v62kI~
  {                                                                //~v62kI~
//free undel prepare list
	for (ii=0;ii<LASTDRIVE;ii++)
    {
    	if (!Sdrivelist[ii].UDDindex)   //no delete data
        	continue;
	    dlcmdgetdirname(ii,unddirname);	//get saved dir name
        pqh=&Sdrivelist[ii].UDDqueh;

		if (UCBITCHK(Gopt3,GOPT3UNDELLEAVE))	//keep mode
        {
			strcpy(unddirname+SAVEFNAMEPOS-2,INDEXID);//index fname
			if (fh=fileopen(unddirname,"w"),fh)	//open ok
            {
				for (pue=UGETQEND(pqh);pue;pue=UGETQPREV(pue)) 	//fifo
    		    {
                    sprintf(indexrec,"%s%c%s\n",                //~6107R~
		        			pue->UDEorgfname,
							TABCHAR,                            //~6107I~
		        			pue->UDEmembname);
                    fputs(indexrec,fh);
        		}
				fileclose(unddirname,fh);   //file created(index keeped)
            }
            else
    			rc+=4;
        }
//  	while(pqe=UDEQ(UQUE_TOP,pqh,0),pqe)                        //~v62hR~
//  		ufree(pqe);                                            //~v62hR~

//del temp save dir
		if (UCBITCHK(Gopt3,GOPT3UNDELFREE))	//free mode
        {
		    strcpy(unddirname+SAVEFNAMEPOS-2,DATAID);
	        rc+=uxdelete(unddirname,UXDELDIR,UXDELNOMSG|UXDELFORCE,//~v05QR~
						&ctr,&ctr,&ctr);//no need file,ronly,del ctr//~v05QI~
        }
//free undel buff                                                  //~v62hM~
    	uqufree(pqh);                                              //~v62hR~
    }
  }//undeldate                                                     //~v62kI~
#ifdef FTPSUPP                                                     //~v62kM~
    pqh=&Sdrivelist[LASTDRIVE].UDDqueh;                            //~v62kI~
	if (UCBITCHK(Gopt3,GOPT3UNDELFREE))	//free mode                //~v62kI~
    	dlcmdftpclearundelsave(pqh);    //clear alll following entry//~v62kR~
    uqufree(pqh);                                                  //~v62kI~
#endif                                                             //~v62kM~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    pqh=&Sdrivelist['\\'-'A'].UDDqueh;                             //~v7abI~
	if (UCBITCHK(Gopt3,GOPT3UNDELFREE))	//free mode                //~v7abI~
    	dlcmdUNCclearundelsave(pqh);    //clear alll following entry//~v7abI~
    uqufree(pqh);                                                  //~v7abI~
#endif                                                             //~v7abI~
    return rc;
}//dlcmdundelterm

//****************************************************************
// dlcmdgetdirname
// generate dirname
//parm1:driveid
//parm2:output save dirname
//*ret  :none
//****************************************************************
void dlcmdgetdirname(int Pdriveid,UCHAR *Pdirname)
{
    int index;
//*******************
    index=Sdrivelist[Pdriveid].UDDindex;
#ifdef UNX                                                         //~v19GI~
#else                                                              //~v19GI~
	*Pdirname=(UCHAR)('A'+Pdriveid);	//set drive
	*(Pdirname+1)=':';
#endif                                                             //~v19KM~
//  strcpy(Pdirname+2,Stopdirname);                                //~v19KR~
    strcpy(Pdirname+ROOTDIRPOS,Stopdirname);                       //~v19KI~
//  strcat(Pdirname,"\\");                                         //~v19aR~
    strcat(Pdirname,DIR_SEPS);                                     //~v19aI~
    strcat(Pdirname,Sundeldate);	//second dir
	sprintf(Pdirname+SEQEDITPOS,Sseqdatadiredit,index,0);
    return;
}//dlcmdgetdirname

//**************************************************************** //~vaa0I~
void dlcmdwildrenamemsg(int Popt,char *Pnewname)                   //~vaa0I~
{                                                                  //~vaa0I~
	uerrmsg("restored as %s by the reason of wildcard name",       //~vaa0R~
			"%s に改名してundo(元のファイル名はワイルドカード文字を含むため)",//~vaa0R~
			Pnewname);                                             //~vaa0I~
    return;                                                        //~vaa0I~
}//dlcmdwildrenamemsg                                              //~vaa0I~
//****************************************************************
// dlcmdundelete
// delete dlcmd
//*ret  :rc
//****************************************************************
int dlcmdundelete(PUCLIENTWE Ppcw,PUDLCMD Pplc,PUDLCMD Pplcdummy)
{
	UCHAR  fullpathname[_MAX_PATH];
//  UCHAR  savefname[_MAX_PATH];                                   //~vb7eR~
    UCHAR  savefname[FTP_MAXPATH2];                                //~vb7eI~
#ifdef FTPSUPP                                                     //~v62hI~
    PUFILEH pfh;                                                   //~v62hI~
    int pathlen;                                                   //~v62hI~
#endif                                                             //~v62hI~
    PULINEH plh;
    PUDIRLH pdh;
    int driveid,rc;
    PUNDELENTRY pue;
#ifdef UNX                                                         //~vaa0I~
	int swwildname=0;                                              //~vaa0I~
#endif                                                             //~vaa0I~
//*******************
    UTRACEP("%s:entry\n",UTT);                                     //~vb7fI~
    plh=Pplc->UDLCplh;
    pdh=UGETPDH(plh);
#ifdef FTPSUPP                                                     //~v62hI~
    pfh=UGETPFH(plh);                                              //~v62hI~
#endif                                                             //~v62hI~
	if (dlcgetfullname(pdh,fullpathname))
    	return 4;
//  driveid=(int)DRIVEID(*fullpathname);                           //~v62hR~
#ifdef FTPSUPP                                                     //~v71jI~
  if (FILEISTSO(pfh))                                              //~v71jI~
    driveid=(int)DRIVEID(Gworkdir);                                //~v71jI~
  else                                                             //~v71jI~
#endif                                                             //~v71jI~
    driveid=(int)DRIVEID(fullpathname);                            //~v62hI~
#ifdef W32                                                         //~vay4I~
	getReservedFileDriveid(fullpathname,&driveid);                 //~vay4I~
#endif                                                             //~vay4I~
//chk undel from saved dir/file
#ifdef FTPSUPP                                                     //~v62hI~
  if (pfh->UFHpuftph)       //remote                               //~v62hI~
  {                                                                //~v71cR~
//  if (FILEISTSO(pfh))                                            //~v71jR~
//  {                                                              //~v71jR~
//      return errnotsupported("Undelete","TSO PDS");              //~v71jR~
//  }                                                              //~v71jR~
//  else                                                           //~v71jR~
    rc=dlcmdftpundelfromsave(Ppcw,pfh,Pplc,fullpathname,driveid);  //~v62hR~
  }                                                                //~v71cR~
  else                                                             //~v62hI~
#endif                                                             //~v62hI~
  {                                                                //~vaa0I~
    rc=dlcmdundelfromsave(Ppcw,Pplc,fullpathname,savefname,driveid);
#ifdef UNX                                                         //~vaa0I~
	swwildname=(pdh->UDHattr & FILE_WILDNAME);                     //~vaa0I~
#endif                                                             //~vaa0I~
  }                                                                //~vaa0I~
    if (rc>=0)		//rc=-1:not save dir
        return rc;
                                                                   //~vaa0I~
//*undo Move ***                                                   //~vaa0R~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTMOVEO))                //~v05NI~
    {                                                           //~v05NI~
	    if (UCBITCHK(pdh->UDHupdatetype,UDHUTMOVEOCHILD))       //~v05NR~
	   	{                                                       //~v05NI~
    	   	uerrmsg("partial Undo not avail",                   //~v05NI~
        	   	    "部分的な移動戻しはできません");            //~v05NI~
   			return 4;                                           //~v05NI~
	    }                                                       //~v05NI~
    	return dlcmdcopymove(Ppcw,Pplc,Pplcdummy);	//undo      //~v05NI~
	}                                                           //~v05NI~
//*undo Rename ***                                                 //~vaa0I~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTRENAMEO))//after chk move//~v05NI~
    	return dlcmdrename(Ppcw,Pplc,Pplcdummy);   	//undo      //~v05NM~
                                                                //~v05NI~
    if (!UCBITCHK(pdh->UDHupdatetype,UDHUTDELETED))
   	{
       	uerrmsg("Not deleted line",
           	    "削除行に非ず");
   		return 4;
    }
//*undo Delete ***                                                 //~vaa0I~
#ifdef UTF8SUPPH                                                   //~va00I~
   	pue=dlcmdsrchundel(pdh,driveid,0);	//srch key:PDH_UDHrenamesv //~va00I~
#else                                                              //~va00I~
   	pue=dlcmdsrchundel(pdh,driveid);
#endif                                                             //~va00I~
    if (!pue)
    	return errnodata();
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
  if (driveid==DRIVEID_UNC)                                        //~v7abR~
  {                                                                //~v7abI~
    pfh=UGETPFH(plh);                                              //~v7abI~
    pathlen=PATHLEN(fullpathname);                                 //~v7abI~
    memcpy(savefname,fullpathname,(UINT)pathlen);                  //~v7abI~
//  strcpy(savefname+pathlen,pdh->UDHrenamesv);                    //~v7abI~//~va00R~
    strcpy(savefname+pathlen,PDH_UDHrenamesv(pdh));                //~va00M~
    rc=urename(savefname/*old*/,fullpathname/*new*/,0);            //~v7abR~
  }                                                                //~v7abI~
  else                                                             //~v7abI~
#endif                                                             //~v7abI~
#ifdef FTPSUPP                                                     //~v62hI~
  if (pue->UDEflag & UDEFFTP)		//remote file                  //~v62hI~
  {                                                                //~v62hI~
    pfh=UGETPFH(plh);                                              //~v62hI~
    pathlen=FTP_PATHLEN(fullpathname);                             //~v62hI~
    memcpy(savefname,fullpathname,(UINT)pathlen);                  //~v62hI~
//  strcpy(savefname+pathlen,pdh->UDHrenamesv);                    //~v62hI~//~va00R~
    strcpy(savefname+pathlen,PDH_UDHrenamesv(pdh));                //~va00M~
    rc=xeftprename(pfh->UFHpuftph,savefname,fullpathname+pathlen); //~v62hI~
  }                                                                //~v62hI~
  else                                                             //~v62hI~
  {                                                                //~v62hI~
#endif                                                             //~v62hI~
//copy back and del save data
    dlcmdgetdirname(driveid,savefname);	//get saved dir name
//  *(savefname+SAVEFNAMEPOS-1)='\\';                              //~v19aR~
    *(savefname+SAVEFNAMEPOS-1)=DIR_SEPC;                          //~v19aI~
    strcpy(savefname+SAVEFNAMEPOS,pue->UDEmembname);//apend renamed
//  if (uxmove(savefname,fullpathname,FILE_ALL))                   //~v09bR~
//  rc=uxmove(savefname,fullpathname,FILE_ALL);                    //~v45HR~
#ifdef AIX                                                         //~v48mI~
  if (MDOSDISKOK(fullpathname))	//delete aix mdos disk             //~v48mI~
	rc=uxmove(savefname,fullpathname,FILE_ALL,DCPY_NOINTODIRMOVE); //~v48mI~
  else                                                             //~v48mI~
#endif                                                             //~v48mI~
   {                                                               //~vaa0I~
#ifdef UNX                                                         //~vaa0I~
    pathlen=PATHLEN(fullpathname);                                 //~vaa0I~
   	if (swwildname && pathlen>0)                                   //~vaa0I~
    {                                                              //~vaa0I~
//  	ufilerepwildname(0,fullpathname+pathlen);                  //~vaa0R~
    	strcpy(fullpathname+pathlen,PDH_UDHrenamesv(pdh));//for the case wild_multiple,avoid dupname//~vaa0I~
        swwildname=2;                                              //~vaa0I~
    }                                                              //~vaa0I~
#endif                                                             //~vaa0I~
    Gufile_opt|=GFILEOPT_NOSLINKERRMSG;                            //~vaiCI~
    rc=uxmove(savefname,fullpathname,FILE_ALL,0);	//no existing override//~vaiCR~
    Gufile_opt&=~GFILEOPT_NOSLINKERRMSG;                           //~vaiCI~
   }                                                               //~vaa0I~
#ifdef FTPSUPP                                                     //~v62hM~
  }//local file                                                    //~v62hM~
#endif                                                             //~v62hM~
    dlcfsiupdate(Ppcw);  //update free space info                  //~v09bR~
    if (rc)                                                        //~v09bI~
    	return 4;                                               //~v05ZR~
    UDEQ(UQUE_ENT,&(Sdrivelist[driveid].UDDqueh),pue);
    ufree(pue);
#ifdef UNX                                                         //~vaa0M~
  if (swwildname==2)                                               //~vaa0I~
	dlcmdwildrenamemsg(0,fullpathname);                            //~vaa0I~
  else                                                             //~vaa0I~
#endif                                                             //~vaa0M~
  {                                                                //~vaa0I~
    dirsavename(plh,"");    //free rename save
    dlcmdresetdata(pdh);
	dlcmdlvlclear(Ppcw,pdh,1,0);//clear child,del entry         //~v05VI~
    if (pdh->UDHtype==UDHTDIREXP)                               //~v05VI~
    {                                                              //~vb7fI~
        UTRACEP("%s:set UDHTDIR dhname=%s\n",UTT,pdh->UDHname);    //~vb7fI~
		pdh->UDHtype=UDHTDIR;                                   //~v05VI~
    }                                                              //~vb7fI~
	UCBITOFF(pdh->UDHupdatetype,UDHUTDELETED);
    dlcmdresetparentsz(pdh,DLCPSZ_LC,0,plh->ULHlinenow);//size is by resetdata//~v10rR~
//  UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //redraw savename,rest at resetdata//~v10rR~
  }                                                                //~vaa0I~
    dlcmdupctr(plh);                                            //~v05NI~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr
    return 0;
}//dlcmdundelete

//****************************************************************
// dlcmdundelfromsave
// undelete cmd on saved dir
//*parm1:pcw
//*parm2:plc
//*parm3:line full path name
//*parm4:filename work area
//*parm5:drive id
//*ret  :rc 0: ok, >0: err, <0: not save dir
//****************************************************************
int dlcmdundelfromsave(PUCLIENTWE Ppcw,PUDLCMD Pplc,
						UCHAR *Pfullpath,UCHAR *Pwkfname,int Pdriveid)
{
    UCHAR  *undeldate,*pc,*member,*newname,wkc;
    PULINEH plh;
    PUDIRLH pdh;
    int rc,ii,cursw,index;
    PUNDELENTRY pue;
    char fnmwk[_MAX_PATH];                                         //~v20EI~
#ifdef FTPSUPP                                                     //~v71jI~
	int tsosw=0;                                                   //~v71jI~
    char tsomembname[DSN_MAXMEMBERNAMELEN+1];                      //~v71jI~
    char tsodsn[DSN_MAXLEN];                                       //~v71jI~
#endif                                                             //~v71jI~
//*******************
//  pc=Pfullpath+2;	//first dir pos contain delm                   //~v19KR~
    pc=Pfullpath+ROOTDIRPOS;	//first dir pos contain delm       //~v19KI~
#ifdef UNX                                                         //~v20DI~
//  if (memcmp(pc,Stopdirname,TOPDIRNAMESZ)                        //~v20DI~//~vb30R~
    if (memcmp(pc,Stopdirname,(size_t)TOPDIRNAMESZ)                //~vb30I~
#else  //!UNX                                                      //~v20DI~
    if (memicmp(pc,Stopdirname,TOPDIRNAMESZ)
#endif //!UNX                                                      //~v20DI~
//  ||  *(pc+TOPDIRNAMESZ)!='\\')	//save top dir                 //~v19aR~
    ||  *(pc+TOPDIRNAMESZ)!=DIR_SEPC)	//save top dir             //~v19aI~
    	return -1;		//not save top dir

    plh=Pplc->UDLCplh;
    pdh=UGETPDH(plh);
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTDELETED))              //~6107I~
		return errnodata();                                     //~6107I~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))//renamed or moved//~6107I~
		return -1;		//may undo process                      //~6107I~
	cursw=1;			//once init by current session undel
//date dir chk
	pc+=TOPDIRNAMESZ+1;	//second dir name start pos
	undeldate=getundeldate();
#ifdef UNX                                                         //~v20DI~
    if (memcmp(pc,undeldate,DATEDIRNAMESZ)                         //~v20DI~
#else  //!UNX                                                      //~v20DI~
    if (memicmp(pc,undeldate,DATEDIRNAMESZ)
#endif //!UNX                                                      //~v20DI~
//  ||  *(pc+DATEDIRNAMESZ)!='\\')	//not today                    //~v19aR~
    ||  *(pc+DATEDIRNAMESZ)!=DIR_SEPC)	//not today                //~v19aI~
    {
    	rc=sscanf(pc,DATEFMT2,&ii,&ii,&ii,&wkc);//date format chk
//  	if (rc!=4 || wkc !='\\')                                   //~v19aR~
    	if (rc!=4 || wkc !=DIR_SEPC)                               //~v19aI~
			return errinvaliddata();
		cursw=0;
	}
//seq dir chk
	pc+=DATEDIRNAMESZ+1;	//third dir name start pos
    rc=sscanf(pc,Sseqdatadiredit+1,&index,&wkc);//seqno format chk
//  if (rc!=2 || !index || wkc !='\\')	//0 not allow              //~v19aR~
    if (rc!=2 || !index || wkc !=DIR_SEPC)	//0 not allow          //~v19aI~
		return errinvaliddata();
    member=pc+SEQDIRNAMESZ+1;	//of line fname
//in the save dir
//  if (strchr(member,'\\'))	//subdir of saved                  //~v07lR~
//  if (ustrchr2(member,'\\'))	//subdir of saved,chk dbcs 2nd byte//~v19aR~
    if (ustrchr2(member,DIR_SEPC))	//subdir of saved,chk dbcs 2nd byte//~v19aI~
		return errinvaliddata();
	if (cursw)		//current path an
	    if (index!=Sdrivelist[Pdriveid].UDDindex)	//not current
			cursw=0;
//chk confirm
//  newname=pdh->UDHrenamesv;	//save cur value                   //~va00R~
    newname=PDH_UDHrenamesv(pdh);	//rename fld by utf8 or locale //~va00M~
	if (cursw)	//current buff
    {
#ifdef UTF8SUPPH                                                   //~va00I~
        pue=dlcmdsrchundel(pdh,Pdriveid,member);                   //~va00I~
#else                                                              //~va00I~
		pdh->UDHrenamesv=member;	//temporary parm
        pue=dlcmdsrchundel(pdh,Pdriveid);
		pdh->UDHrenamesv=newname;	//temporary parm
#endif                                                             //~va00I~
        if (!pue)
		   	return errnodata();
    }
    else
    	pue=0;		//avoid deq/free
	if (!UCBITCHK(pdh->UDHflag,UDHFMASK2)) //not yet confirmed
    {
		if (cursw)	//current buff
	        newname=pue->UDEorgfname;
        else
        {
            if (dlcmdsrchindexf(Pfullpath,Pwkfname))
            	return 4;
            newname=Pwkfname;
		}
//      if (!(pc=strrchr(newname,'\\')))	//target member name   //~v07lR~
//      if (!(pc=ustrrchr2(newname,'\\')))	//target member name pos//~v19aR~
        if (!(pc=ustrrchr2(newname,DIR_SEPC)))	//target member name pos//~v19aI~
        {                                                          //~v71jI~
#ifdef FTPSUPP                                                     //~v71jI~
			tsosw=(u3270fullpathistso(newname)==2);	//dsname with member//~v71jI~
            if (tsosw)	//TSO membername format  "hostid:'xxxx(yyy)'"//~v71jI~
            {                                                      //~v71jI~
            	if (u3270parsedsn(0,newname,tsodsn,tsomembname)!=1)	//not wild member//~v71jR~
                	tsosw=0;                                       //~v71jI~
            }                                                      //~v71jI~
            if (!tsosw)	//not contain valid membname               //~v71jI~
            {                                                      //~v71jI~
#endif                                                             //~v71jI~
	            uerrmsg("invalid undo original filename(%s)",0,    //~v71jR~
    	        		newname);                                  //~v71jR~
        		return 4;                                          //~v71jR~
#ifdef FTPSUPP                                                     //~v71jI~
            }                                                      //~v71jI~
#endif                                                             //~v71jI~
        }                                                          //~v71jI~
#ifdef FTPSUPP                                                     //~v71jI~
	  if (tsosw)                                                   //~v71jI~
      {                                                            //~v71jI~
        	if (!stricmp(tsomembname,member))                      //~v71jI~
            	strcpy(newname,tsodsn);                            //~v71jI~
      }                                                            //~v71jI~
      else                                                         //~v71jI~
      {                                                            //~v71jI~
#endif                                                             //~v71jI~
        pc++;
#ifdef UNX                                                         //~v20DI~
        if (!strcmp(pc,member))                                    //~v20DI~
#else  //!UNX                                                      //~v20DI~
        if (!stricmp(pc,member))
#endif //!UNX                                                      //~v20DI~
        	*pc=0;				//drop name(path only)             //~v07lR~
#ifdef FTPSUPP                                                     //~v71jI~
      }                                                            //~v71jI~
#endif                                                             //~v71jI~
//      if (dirsavename(plh,newname))                              //~va00R~
//      if (BYUTF8_dirsavename(plh,newname))                       //~va0GR~
        if (dirsavename(plh,newname))                              //~va0GI~
        	return 4;
       	uerrmsg("confirm target",
           	    "宛先確認");
		UCBITON(pdh->UDHflag,UDHFMASK2); //undel confirm mask
		UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //redraw savename
	  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr
        return 4;	//bell                                      //~6107R~
    }
    else                                                        //~v05NI~
		UCBITOFF(pdh->UDHflag,UDHFMASK2); //to avoid clear renamesv at//~v05NI~
//copy back and del save data
//  if (dirsetflddata(Ppcw,plh,PANL310RENAME,newname)<=0)	//for dlcmdcopymove//~va00R~
//  if (BYUTF8_dirsetflddata(Ppcw,plh,PANL310RENAME,newname)<=0)	//for dlcmdcopymove//~va00R~//~va0GR~
    if (dirsetflddata(Ppcw,plh,PANL310RENAME,newname)<=0)	//for dlcmdcopymove//~va0GI~
    	return 4;
#ifdef FTPSUPP                                                     //~v71jI~
  if (u3270fullpathistso(newname))	//dsname with member           //~v71jI~
  {                                                                //~v71jI~
    	u3270concatfilename(U3CF_FORCEASMEMBERIFNOTWILD,newname,member,fnmwk);//~v71jR~
//      if (dirsavename(plh,fnmwk))                                //~v71jI~//~va00R~
//      if (BYUTF8_dirsavename(plh,fnmwk))                         //~va0GR~
        if (dirsavename(plh,fnmwk))                                //~va0GI~
        	return 4;                                              //~v71jI~
//    	newname=pdh->UDHrenamesv;	//save cur value               //~v71jI~//~va00R~
    	newname=PDH_UDHrenamesv(pdh);	//save cur value           //~va00M~
  }                                                                //~v71jI~
  else                                                             //~v71jI~
  {                                                                //~v71jI~
#endif                                                             //~v71jI~
    ii=(int)strlen(newname);                                    //~6114I~
//  if (*(newname+ii-1)=='\\')	//same dir                         //~v19aR~
    if (*(newname+ii-1)==DIR_SEPC)	//same dir                     //~v19aI~
    {                                                              //~v20EI~
//  	strcpy(newname+ii,member);                                 //~v20ER~
        memcpy(fnmwk,newname,(UINT)ii);                            //~v20EI~
    	strcpy(fnmwk+ii,member);                                   //~v20EI~
//      if (dirsavename(plh,fnmwk))                                //~v20EI~//~va00R~
//      if (BYUTF8_dirsavename(plh,fnmwk))                         //~va0GR~
        if (dirsavename(plh,fnmwk))                                //~va0GI~
        	return 4;                                              //~v20EI~
//  	newname=pdh->UDHrenamesv;	//save cur value               //~v20EI~//~va00R~
    	newname=PDH_UDHrenamesv(pdh);	//save cur value           //~va00M~
    }                                                              //~v20EI~
#ifdef FTPSUPP                                                     //~v71jI~
  }//not tso                                                       //~v71jI~
#endif                                                             //~v71jI~
	rc=filefind(newname,0,0,FFNONFMSG|FFNODIRMSG);              //~6114R~
	if (!rc || rc==16)// found dir                              //~6114I~
  		return ufileexist(newname,4);                           //~6114M~
	Pplc->UDLCcmd='M';	//move cmd
    rc=dlcmdcopymove(Ppcw,Pplc,0);	//no dummy
	Pplc->UDLCcmd='U';	//restore
	if (rc)
    	return 4;
	if (pue)
    {
    	UDEQ(UQUE_ENT,&(Sdrivelist[Pdriveid].UDDqueh),pue);
    	ufree(pue);
    }
    return 0;
}//dlcmdundelfromsave
#ifdef FTPSUPP                                                     //~v62hR~
//**************************************************************** //~v71gI~
// dlcmdtsoundelfromsave                                           //~v71gI~
// undelete cmd on saved file on same dir(for remote file)         //~v71gI~
//*ret  :rc 0: ok, >0: err, <0: not save dir                       //~v71gI~
//**************************************************************** //~v71gI~
int dlcmdtsoundelfromsave(PUCLIENTWE Ppcw,PUDLCMD Pplc,            //~v71gI~
						UCHAR *Pfullpath,UCHAR *Pwkfname,int Pdriveid)//~v71gI~
{                                                                  //~v71gI~
    UCHAR  *undeldate,*pc,*member,*newname,wkc;                    //~v71gI~
    PULINEH plh;                                                   //~v71gI~
    PUDIRLH pdh;                                                   //~v71gI~
    int rc,ii,cursw,index;                                         //~v71gI~
    PUNDELENTRY pue;                                               //~v71gI~
    char fnmwk[_MAX_PATH];                                         //~v71gI~
//*******************                                              //~v71gI~
    pc=Pfullpath+ROOTDIRPOS;	//first dir pos contain delm       //~v71gI~
#ifdef UNX                                                         //~v71gI~
//  if (memcmp(pc,Stopdirname,TOPDIRNAMESZ)                        //~v71gI~//~vb30R~
    if (memcmp(pc,Stopdirname,(size_t)TOPDIRNAMESZ)                //~vb30I~
#else  //!UNX                                                      //~v71gI~
    if (memicmp(pc,Stopdirname,TOPDIRNAMESZ)                       //~v71gI~
#endif //!UNX                                                      //~v71gI~
    ||  *(pc+TOPDIRNAMESZ)!=DIR_SEPC)	//save top dir             //~v71gI~
    	return -1;		//not save top dir                         //~v71gI~
                                                                   //~v71gI~
    plh=Pplc->UDLCplh;                                             //~v71gI~
    pdh=UGETPDH(plh);                                              //~v71gI~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTDELETED))                 //~v71gI~
		return errnodata();                                        //~v71gI~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))//renamed or moved//~v71gI~
		return -1;		//may undo process                         //~v71gI~
	cursw=1;			//once init by current session undel       //~v71gI~
//date dir chk                                                     //~v71gI~
	pc+=TOPDIRNAMESZ+1;	//second dir name start pos                //~v71gI~
	undeldate=getundeldate();                                      //~v71gI~
#ifdef UNX                                                         //~v71gI~
    if (memcmp(pc,undeldate,DATEDIRNAMESZ)                         //~v71gI~
#else  //!UNX                                                      //~v71gI~
    if (memicmp(pc,undeldate,DATEDIRNAMESZ)                        //~v71gI~
#endif //!UNX                                                      //~v71gI~
    ||  *(pc+DATEDIRNAMESZ)!=DIR_SEPC)	//not today                //~v71gI~
    {                                                              //~v71gI~
    	rc=sscanf(pc,DATEFMT2,&ii,&ii,&ii,&wkc);//date format chk  //~v71gI~
    	if (rc!=4 || wkc !=DIR_SEPC)                               //~v71gI~
			return errinvaliddata();                               //~v71gI~
		cursw=0;                                                   //~v71gI~
	}                                                              //~v71gI~
//seq dir chk                                                      //~v71gI~
	pc+=DATEDIRNAMESZ+1;	//third dir name start pos             //~v71gI~
    rc=sscanf(pc,Sseqdatadiredit+1,&index,&wkc);//seqno format chk //~v71gI~
    if (rc!=2 || !index || wkc !=DIR_SEPC)	//0 not allow          //~v71gI~
		return errinvaliddata();                                   //~v71gI~
    member=pc+SEQDIRNAMESZ+1;	//of line fname                    //~v71gI~
//in the save dir                                                  //~v71gI~
    if (ustrchr2(member,DIR_SEPC))	//subdir of saved,chk dbcs 2nd byte//~v71gI~
		return errinvaliddata();                                   //~v71gI~
	if (cursw)		//current path an                              //~v71gI~
	    if (index!=Sdrivelist[Pdriveid].UDDindex)	//not current  //~v71gI~
			cursw=0;                                               //~v71gI~
//chk confirm                                                      //~v71gI~
//  newname=pdh->UDHrenamesv;	//save cur value                   //~v71gI~//~va00R~
    newname=PDH_UDHrenamesv(pdh);	//save cur value               //~va00M~
	if (cursw)	//current buff                                     //~v71gI~
    {                                                              //~v71gI~
#ifdef UTF8SUPPH                                                   //~va00I~
        pue=dlcmdsrchundel(pdh,Pdriveid,member);                   //~va00I~
#else                                                              //~va00I~
		pdh->UDHrenamesv=member;	//temporary parm               //~v71gI~
        pue=dlcmdsrchundel(pdh,Pdriveid);                          //~v71gI~
		pdh->UDHrenamesv=newname;	//temporary parm               //~v71gI~
#endif                                                             //~va00I~
        if (!pue)                                                  //~v71gI~
		   	return errnodata();                                    //~v71gI~
    }                                                              //~v71gI~
    else                                                           //~v71gI~
    	pue=0;		//avoid deq/free                               //~v71gI~
	if (!UCBITCHK(pdh->UDHflag,UDHFMASK2)) //not yet confirmed     //~v71gI~
    {                                                              //~v71gI~
		if (cursw)	//current buff                                 //~v71gI~
	        newname=pue->UDEorgfname;                              //~v71gI~
        else                                                       //~v71gI~
        {                                                          //~v71gI~
            if (dlcmdsrchindexf(Pfullpath,Pwkfname))               //~v71gI~
            	return 4;                                          //~v71gI~
            newname=Pwkfname;                                      //~v71gI~
		}                                                          //~v71gI~
        if (!(pc=ustrrchr2(newname,DIR_SEPC)))	//target member name pos//~v71gI~
        	return 4;                                              //~v71gI~
        pc++;                                                      //~v71gI~
#ifdef UNX                                                         //~v71gI~
        if (!strcmp(pc,member))                                    //~v71gI~
#else  //!UNX                                                      //~v71gI~
        if (!stricmp(pc,member))                                   //~v71gI~
#endif //!UNX                                                      //~v71gI~
        	*pc=0;				//drop name(path only)             //~v71gI~
//      if (dirsavename(plh,newname))                              //~v71gI~//~va0GR~
//      if (BYUTF8_dirsavename(plh,newname))                       //~va0GR~
        if (dirsavename(plh,newname))                              //~va0GI~
        	return 4;                                              //~v71gI~
       	uerrmsg("confirm target",                                  //~v71gI~
           	    "宛先確認");                                       //~v71gI~
		UCBITON(pdh->UDHflag,UDHFMASK2); //undel confirm mask      //~v71gI~
		UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //redraw savename      //~v71gI~
	  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr             //~v71gI~
        return 4;	//bell                                         //~v71gI~
    }                                                              //~v71gI~
    else                                                           //~v71gI~
		UCBITOFF(pdh->UDHflag,UDHFMASK2); //to avoid clear renamesv at//~v71gI~
//copy back and del save data                                      //~v71gI~
//  if (dirsetflddata(Ppcw,plh,PANL310RENAME,newname)<=0)	//for dlcmdcopymove//~v71gI~//~va00R~
//  if (BYUTF8_dirsetflddata(Ppcw,plh,PANL310RENAME,newname)<=0)	//for dlcmdcopymove//~va0GR~
    if (dirsetflddata(Ppcw,plh,PANL310RENAME,newname)<=0)	//for dlcmdcopymove//~va0GI~
    	return 4;                                                  //~v71gI~
    ii=(int)strlen(newname);                                       //~v71gI~
    if (*(newname+ii-1)==DIR_SEPC)	//same dir                     //~v71gI~
    {                                                              //~v71gI~
        memcpy(fnmwk,newname,(UINT)ii);                            //~v71gI~
    	strcpy(fnmwk+ii,member);                                   //~v71gI~
//      if (dirsavename(plh,fnmwk))                                //~v71gI~//~va00R~
//      if (BYUTF8_dirsavename(plh,fnmwk))                         //~va0GR~
        if (dirsavename(plh,fnmwk))                                //~va0GI~
        	return 4;                                              //~v71gI~
//    	newname=pdh->UDHrenamesv;	//save cur value               //~v71gI~//~va00R~
    	newname=PDH_UDHrenamesv(pdh);	//save cur value           //~va00M~
    }                                                              //~v71gI~
	rc=filefind(newname,0,0,FFNONFMSG|FFNODIRMSG);                 //~v71gI~
	if (!rc || rc==16)// found dir                                 //~v71gI~
  		return ufileexist(newname,4);                              //~v71gI~
	Pplc->UDLCcmd='M';	//move cmd                                 //~v71gI~
    rc=dlcmdcopymove(Ppcw,Pplc,0);	//no dummy                     //~v71gI~
	Pplc->UDLCcmd='U';	//restore                                  //~v71gI~
	if (rc)                                                        //~v71gI~
    	return 4;                                                  //~v71gI~
	if (pue)                                                       //~v71gI~
    {                                                              //~v71gI~
    	UDEQ(UQUE_ENT,&(Sdrivelist[Pdriveid].UDDqueh),pue);        //~v71gI~
    	ufree(pue);                                                //~v71gI~
    }                                                              //~v71gI~
    return 0;                                                      //~v71gI~
}//dlcmdtsoundelfromsave                                           //~v71gI~
//**************************************************************** //~v62hI~
// dlcmdftpundelfromsave                                           //~v62hI~
// undelete cmd on saved file on same dir(for remote file)         //~v62hI~
//*ret  :rc 0: ok, >0: err, <0: not save dir                       //~v62hI~
//**************************************************************** //~v62hI~
int dlcmdftpundelfromsave(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDLCMD Pplc,//~v62hR~
							UCHAR *Pfullpath,int Pdriveid)         //~v62hI~
{                                                                  //~v62hI~
    PULINEH plh;                                                   //~v62hI~
    PUDIRLH pdh;                                                   //~v62hI~
    int rc,pathlen;                                                //~v62hR~
    PUNDELENTRY pue;                                               //~v62hI~
//#ifdef UTF8SUPPH                                                   //~va00I~//~vb7eR~
//  char *membname,newname[_MAX_PATH2];                             //~va00I~//~vb7eR~
    char *membname,newname[FTP_MAXPATH];                           //~vb7eI~
//#else                                                              //~va00I~//~vb7eR~
//    char *svname,*membname,newname[_MAX_PATH];                     //~v62hR~//~vb7eR~
//#endif                                                             //~va00I~//~vb7eR~
//*******************                                              //~v62hI~
	if (!dlcmdftpundelnamechk(Pfullpath))	//not saved filename   //~v62hI~
    	return -1;		//not save top dir                         //~v62hI~
    plh=Pplc->UDLCplh;                                             //~v62hI~
    pdh=UGETPDH(plh);                                              //~v62hI~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTDELETED))                 //~v62hI~
		return errnodata();                                        //~v62hI~
    if (UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))//renamed or moved//~v62hI~
		return -1;		//may undo process                         //~v62hI~
//chk confirm                                                      //~v62hI~
    pathlen=FTP_PATHLEN(Pfullpath);                                //~v62hI~
#ifdef UTF8SUPPH                                                   //~va00I~
    pue=dlcmdsrchundel(pdh,Pdriveid,Pfullpath+pathlen);	//dlcmdsrchundel parm//~va00I~
#else                                                              //~va00I~
    svname=pdh->UDHrenamesv;	//save cur value                   //~v62hR~
	pdh->UDHrenamesv=Pfullpath+pathlen;	//dlcmdsrchundel parm      //~v62hR~
    pue=dlcmdsrchundel(pdh,Pdriveid);                              //~v62hR~
	pdh->UDHrenamesv=svname;	//restore                          //~v62hR~
#endif                                                             //~va00I~
    memcpy(newname,Pfullpath,(UINT)pathlen);                       //~v62hI~
    strcpy(newname+pathlen,Pfullpath+pathlen+sizeof(FTPUNDELPREFIX)-1);//~v62hI~
    *(newname+strlen(newname)-FTPUNDELPOSTFIXLEN)=0;               //~v62hI~
    membname=newname+pathlen;                                      //~v62hI~
	if (!UCBITCHK(pdh->UDHflag,UDHFMASK2)) //not yet confirmed     //~v62hI~
    {                                                              //~v62hI~
//      if (dirsavename(plh,membname))                             //~v62hR~//~va00R~
//      if (BYUTF8_dirsavename(plh,membname))                      //~va0GR~
        if (dirsavename(plh,membname))                             //~va0GI~
        	return 4;                                              //~v62hI~
       	uerrmsg("confirm target",                                  //~v62hI~
           	    "宛先確認");                                       //~v62hI~
		UCBITON(pdh->UDHflag,UDHFMASK2); //undel confirm mask      //~v62hI~
		UCBITOFF(pdh->UDHflag,UDHFDDSETUP); //redraw savename      //~v62hI~
	  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr             //~v62hI~
        return 4;	//bell                                         //~v62hI~
    }                                                              //~v62hI~
    else                                                           //~v62hI~
		UCBITOFF(pdh->UDHflag,UDHFMASK2); //to avoid clear renamesv at//~v62hI~
//copy back and del save data                                      //~v62hI~
//	if (dirsetflddata(Ppcw,plh,PANL310RENAME,membname)<=0)	//for dlcmdcopymove//~v62hR~//~va00R~
//  if (BYUTF8_dirsetflddata(Ppcw,plh,PANL310RENAME,membname)<=0)	//for dlcmdcopymove//~va0GR~
  	if (dirsetflddata(Ppcw,plh,PANL310RENAME,membname)<=0)	//for dlcmdcopymove//~va0GI~
    	return 4;                                                  //~v62hI~
	rc=filefind(newname,0,0,FFNONFMSG|FFNODIRMSG);                 //~v62hI~
	if (!rc || rc==16)// found dir                                 //~v62hI~
  		return ufileexist(newname,4);                              //~v62hI~
    rc=xeftprename(Ppfh->UFHpuftph,Pfullpath,membname);            //~v62hI~
	if (rc)                                                        //~v62hI~
    	return 4;                                                  //~v62hI~
	if (pue)                                                       //~v62hI~
    {                                                              //~v62hI~
    	UDEQ(UQUE_ENT,&(Sdrivelist[Pdriveid].UDDqueh),pue);        //~v62hI~
    	ufree(pue);                                                //~v62hI~
    }                                                              //~v62hI~
    dlcmdmoveflag(Ppcw,plh,pdh,0); //0:no child                    //~v62hI~
    return 0;                                                      //~v62hI~
}//dlcmdftpundelfromsave                                           //~v62hR~
#endif                                                             //~v62hR~
//****************************************************************
// dlcmdsrchindexf
// search undel entry on index file
//parm1:saved filename
//parm2:output org deleted file name
//*ret :rc
//****************************************************************
int dlcmdsrchindexf(UCHAR *Pfullpath,UCHAR *Ptarget)
{
    UCHAR  indexrec[INDEXRECSZ];
    UCHAR       *pc=NULL,*pc2;                                     //~vafcR~
    FILE   *fh;
//*******************
	strcpy(Ptarget,Pfullpath);	//use as work
    strcpy(Ptarget+SAVEFNAMEPOS-2,INDEXID);
	if (!(fh=fileopen(Ptarget,"r")))	//open err
    	return 4;
	while(fgets(indexrec,INDEXRECSZ,fh))	//last is crlf and null
    {
    	if (!(pc=strchr(indexrec,TABCHAR)))                     //~6107R~
        	continue;
        *pc++=0;
    	if (!(pc2=strchr(pc,'\n')))
        	continue;
        *pc2=0;
#ifdef UNX                                                         //~v20DI~
        if (!strcmp(pc,Pfullpath+SAVEFNAMEPOS))                    //~v20DI~
#else  //!UNX                                                      //~v20DI~
        if (!stricmp(pc,Pfullpath+SAVEFNAMEPOS))
#endif //!UNX                                                      //~v20DI~
	       	break;
		pc=0;	//not found id
	}
	fileclose(Ptarget,fh);
    if (!pc)
    {
		uerrmsg("unknown target(not registered on %s)",
    	        "宛先不明 (%s に記録なし)",
				Ptarget);
    	return 4;
    }
    strcpy(Ptarget,indexrec);
  	return 0;
}//dlcmdsrchindexf

//****************************************************************
// dlcmdsrchundel
// search undel entry
//parm1:pdh
//parm2:drive id
//*ret :pue or 0 if no save data
//****************************************************************
#ifdef UTF8SUPPH                                                   //~va00I~
PUNDELENTRY dlcmdsrchundel(PUDIRLH Ppdh,int Pdriveid,char *Pmembname)//~va00I~
#else                                                              //~va00I~
PUNDELENTRY dlcmdsrchundel(PUDIRLH Ppdh,int Pdriveid)
#endif                                                             //~va00I~
{
    PUNDELENTRY pue;
    PUQUEH      pqh;
    UCHAR       *member;
//*******************
#ifndef UTF8SUPPH                                                  //~va00I~
    if (!(member=Ppdh->UDHrenamesv))       //malloc failed
#else                                                              //~va00I~
  if (!(member=Pmembname))                                         //~va00I~
    if (!(member=PDH_UDHrenamesv(Ppdh)))       //malloc failed     //~va00M~
#endif                                                             //~va00I~
    	return 0;
    pqh=&Sdrivelist[Pdriveid].UDDqueh;
//  for (pue=UGETQTOP(pqh);pqh;pqh=UGETQNEXT(pqh))                 //~v62jR~
    for (pue=UGETQTOP(pqh);pue;pue=UGETQNEXT(pue))                 //~v62jR~
#ifdef UNX                                                         //~v20DI~
    	if (!strcmp(member,pue->UDEmembname))                      //~v20DI~
#else  //!UNX                                                      //~v20DI~
    	if (!stricmp(member,pue->UDEmembname))
#endif //!UNX                                                      //~v20DI~
        	break;
  	return pue;
}//dlcmdsrchundel

//****************************************************************
// dlcmdundelprep
// prepare for undelete(move deleted to save dir)
//parm1:pcw
//parm2:fullpath name
//parm3:pdh
//*ret  :rc 0:ok  1:file on the save dir 4:err
//****************************************************************
int dlcmdundelprep(PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh)
{
	int rc,namepos,driveid,len;
    PUNDELENTRY pue;
    PULINEH plh;
#ifdef FTPSUPP                                                     //~v62hI~
    PUFILEH pfh;                                                   //~v62hI~
#endif                                                             //~v62hI~
    char *pfpath;                                                  //~van2R~
//*******************
	UTRACEP("%s:fpath=%s\n",UTT,Pfullpath);                        //~vb7fI~
    plh=UGETDIRPLH(Ppdh);                                          //~v62hI~
#ifdef FTPSUPP                                                     //~v62hI~
    pfh=UGETPFH(plh);                                              //~v62hI~
    if (FILEISREMOTE(pfh))                                         //~v62hI~
    {                                                              //~v71jI~
      if (FILEISTSO(pfh))                                          //~v71eR~
        return dlcmdtsoundelprepdir(Ppcw,pfh,Ppdh,Pfullpath);      //~v71eR~
      else                                                         //~v71eI~
        return dlcmdftpundelprepdir(Ppcw,pfh,Ppdh,Pfullpath);      //~v62hR~
    }                                                              //~v71jI~
#endif                                                             //~v62hI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    if (WIN_ISREMOTEPATH(Pfullpath))                               //~v7abI~
        return dlcmdUNCundelprepdir(Ppcw,pfh,Ppdh,Pfullpath);      //~v7abI~
#endif                                                             //~v7abI~
//  if (!memicmp(Pfullpath+2,Stopdirname,TOPDIRNAMESZ)             //~v19KR~
#ifdef UNX                                                         //~v20DI~
//  if (!memcmp(Pfullpath+ROOTDIRPOS,Stopdirname,TOPDIRNAMESZ)     //~v20DI~//~vb30R~
    if (!memcmp(Pfullpath+ROOTDIRPOS,Stopdirname,(size_t)TOPDIRNAMESZ)//~vb30I~
#else  //!UNX                                                      //~v20DI~
    if (!memicmp(Pfullpath+ROOTDIRPOS,Stopdirname,TOPDIRNAMESZ)    //~v19KI~
#endif //!UNX                                                      //~v20DI~
//  &&   (*(Pfullpath+TOPDIRNAMESZ+2)=='\\'	//del file in save dir //~v19aR~
//  &&   (*(Pfullpath+TOPDIRNAMESZ+2)==DIR_SEPC	//del file in save dir//~v19KR~
    &&   (*(Pfullpath+TOPDIRNAMESZ+ROOTDIRPOS)==DIR_SEPC	//del file in save dir//~v19KI~
//     || *(Pfullpath+TOPDIRNAMESZ+2)==0   ))	//top dir          //~v19KR~
       || *(Pfullpath+TOPDIRNAMESZ+ROOTDIRPOS)==0   ))	//top dir  //~v19KI~
    	return 1;				//not rename but delete
#ifdef UNX                                                         //~v19UI~
    if (dlcmdtbitchk(Ppdh,DLCTBCMSG))//dir t bit chk               //~v19YR~
    	return 4;                                                  //~v19UI~
//chk owner                                                        //~v19UI~
#endif                                                             //~v19UI~
	if (dlcmdgetunddir(Pfullpath))	//set save dir name to Sdatadirname
    	return 4;
	namepos=PATHLEN(Pfullpath);	//offset of file name
    pfpath=Pfullpath;                                              //~van2I~
//  strcpy(Sdatadirname+SAVEFNAMEPOS,Pfullpath+namepos);           //~van2R~
  if ((size_t)SAVEFNAMEPOS+strlen(pfpath+namepos)>=sizeof(Sdatadirname))//~vb7cR~
  {                                                                //~vb7cI~
    if (dlcUndelPrepRenameLongname(0,pfpath+namepos,Sdatadirname,SAVEFNAMEPOS,(int)sizeof(Sdatadirname)))//~vb7cR~
    	return 4;                                                  //~vb7cI~
  }                                                                //~vb7cI~
  else                                                             //~vb7cI~
    strcpy(Sdatadirname+SAVEFNAMEPOS,pfpath+namepos);              //~van2I~
                                                                   //~vaa0I~
#ifdef UNX                                                         //~vaa0I~
	if (Ppdh->UDHattr & FILE_WILDNAME)                             //~vaa0I~
//  	ufilerepwildname(0,Sdatadirname+SAVEFNAMEPOS,Ppdh->UDHinode);//~vaa0R~//~vb30R~
    	ufilerepwildname(0,Sdatadirname+SAVEFNAMEPOS,(ULONG)Ppdh->UDHinode);//~vb30I~
#endif                                                             //~vaa0I~

//  len=(int)(UNDELENTRYSZ+strlen(Pfullpath));                     //~van2R~
    len=(int)(UNDELENTRYSZ+strlen(pfpath));                        //~van2I~
	pue=UALLOCC(1,(UINT)len);		//clear QELEM
    UALLOCCHK(pue,4);    //return 4 if malloc err

	if (!(rc=dlcmdchngname()))	//get save member name          //~v05ZI~
    {                                                              //~v48mR~
//    	rc=uxmove(Pfullpath,Sdatadirname,FILE_ALL);                //~v48mR~
#ifdef AIX                                                         //~v48mR~
      if (MDOSDISKOK(Pfullpath))	//delete aix mdos disk         //~v48mR~
      	rc=uxmove(Pfullpath,Sdatadirname,FILE_ALL,DCPY_NODELDIRMOVE);//~v48mR~
      else                                                         //~v48mR~
#endif                                                             //~v48mR~
      {                                                            //~vaiCI~
	    Gufile_opt|=GFILEOPT_NOSLINKERRMSG;                        //~vaiCI~
//    	rc=uxmove(Pfullpath,Sdatadirname,FILE_ALL,0);              //~vaiCR~//~van2R~
      	rc=uxmove(pfpath,Sdatadirname,FILE_ALL,0);                 //~van2I~
    	Gufile_opt&=~GFILEOPT_NOSLINKERRMSG;                       //~vaiCI~
      }                                                            //~vaiCI~
    }                                                              //~v45HI~
	if (rc)                                                     //~v05ZR~
    {                                                           //~v05ZR~
   		ufree(pue);                                             //~v05ZR~
   		return 4;                                               //~v05ZR~
	}
//save undel info
    pue->UDEflag=0;                                                //~v62hI~
	strcpy(pue->UDEmembname,Sdatadirname+SAVEFNAMEPOS);
//  strcpy(pue->UDEorgfname,Pfullpath);                            //~van2R~
    strcpy(pue->UDEorgfname,pfpath);                               //~van2I~
//  driveid=(int)DRIVEID(*Pfullpath);                              //~v62hR~
    driveid=(int)DRIVEID(Pfullpath);                               //~v62hI~
#ifdef W32                                                         //~vay4I~
	getReservedFileDriveid(Pfullpath,&driveid);                    //~vay4I~
#endif                                                             //~vay4I~
    UENQ(UQUE_TOP,&(Sdrivelist[driveid].UDDqueh),pue);//lifo
//  plh=UGETDIRPLH(Ppdh);                                          //~v62hR~
//  return dirsavename(plh,pue->UDEmembname);                      //~va00R~
//  return BYUTF8_dirsavename(plh,pue->UDEmembname);               //~va0GR~
    return dirsavename(plh,pue->UDEmembname);                      //~va0GI~
}//dlcmdundelprep
                                                                   //~v7abI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
//**************************************************************** //~v7abI~
// dlcmdUNCundelprepdir                                            //~v7abI~
// undo prepare for UNC pathname(\\server\..)                      //~v7abI~
//*ret  :rc 0:renamed skip delete  1:continue delete, 4:err        //~v7abI~
//**************************************************************** //~v7abI~
int dlcmdUNCundelprepdir(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfullpath)//~v7abI~
{                                                                  //~v7abI~
	int rc,pathlen;                                                //~v7abR~
    char savename[_MAX_PATH];                                      //~v7abI~
    char savefpath[_MAX_PATH];                                     //~v7abI~
//*******************                                              //~v7abI~
	rc=dlcmdUNCundelprechk(Pfullpath,savename);                    //~v7abI~
    if (rc)                                                        //~v7abI~
    	return rc;                                                 //~v7abI~
    pathlen=PATHLEN(Pfullpath);                                    //~v7abI~
    memcpy(savefpath,Pfullpath,(UINT)pathlen);                     //~v7abI~
    strcpy(savefpath+pathlen,savename);                            //~v7abI~
    rc=urename(Pfullpath,savefpath,0);                             //~v7abR~
    if (rc)                                                        //~v7abI~
    	return 4;                                                  //~v7abI~
	rc=dlcmdftpundelprep(Ppcw,Ppdh,Pfullpath,savename);            //~v7abR~
    if (rc)                                                        //~v7abI~
    	return 4;                                                  //~v7abI~
    return 0;                                                      //~v7abI~
}//dlcmdUNCundelprepdir                                            //~v7abI~
//**************************************************************** //~v7abI~
// dlcmdUNCundelprechk                                             //~v7abI~
// undo prepare condition chk                                      //~v7abI~
//*ret  :rc 0:ok  1:file on the save dir                           //~v7abI~
//**************************************************************** //~v7abI~
int dlcmdUNCundelprechk(UCHAR *Pfullpath,char *Pnewname)           //~v7abI~
{                                                                  //~v7abI~
    char *membname;                                                //~v7abI~
//*******************                                              //~v7abI~
    if (!(UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE)))         //~v7abI~
    	return 1;		//no save                                  //~v7abI~
    if (dlcmdUNCundelnamechk(Pfullpath))	//renamed deleted file //~v7abI~
    	return 1;                                                  //~v7abI~
	membname=Pfullpath+PATHLEN(Pfullpath);	//offset of file name  //~v7abI~
    if (Pnewname)                                                  //~v7abI~
		dlcmdftpundelname(membname,Pnewname);                      //~v7abI~
    return 0;		//undoable                                     //~v7abI~
}//dlcmdUNCundelprechk                                             //~v7abI~
//**************************************************************** //~v7abI~
int dlcmdUNCundelnamechk(UCHAR *Pfullpath)                         //~v7abI~
{                                                                  //~v7abI~
	int len;                                                       //~v7abI~
    char *membname;                                                //~v7abI~
//********************                                             //~v7abI~
	membname=Pfullpath+PATHLEN(Pfullpath);	//offset of file name  //~v7abI~
    len=strlen(membname);                                          //~v7abI~
    if (len>=sizeof(FTPUNDELPREFIX)                                //~v7abI~
    &&  !memcmp(membname,FTPUNDELPREFIX,sizeof(FTPUNDELPREFIX)-1)) //~v7abI~
    {                                                              //~v7abI~
        if (len>sizeof(FTPUNDELPOSTFIX)                            //~v7abI~
        &&  !memcmp(membname+len-FTPUNDELPOSTFIXLEN,FTPUNDELPOSTFIX,sizeof(FTPUNDELPOSTFIX)-1))//~v7abI~
	    	return 1;		//no save                              //~v7abI~
    }                                                              //~v7abI~
    return 0;                                                      //~v7abI~
}//dlcmdUNCundelnamechk                                            //~v7abI~
//**************************************************************** //~v7abI~
// dlcmdUNCclearundelsave                                          //~v7abI~
// clear temporary save file for remote file delete                //~v7abI~
//*ret  :rc                                                        //~v7abI~
//**************************************************************** //~v7abI~
int dlcmdUNCclearundelsave(PUQUEH Ppqh)                            //~v7abI~
{                                                                  //~v7abI~
	PUNDELENTRY pue,pueprev=0;                                     //~v7abI~
    char *pfnm,fpath[_MAX_PATH];                                   //~v7abI~
    int  ctr,rc=0;                                                 //~v7abI~
//*******************                                              //~v7abI~
    for (pue=UGETQEND(Ppqh);pue;pue=pueprev)  //fifo               //~v7abR~
    {                                                              //~v7abR~
        pueprev=UGETQPREV(pue);  //fifo                            //~v7abR~
        pfnm=pue->UDEorgfname;                                     //~v7abR~
        strcpy(fpath,pfnm);                                        //~v7abR~
        strcpy(fpath+PATHLEN(fpath),pue->UDEmembname);             //~v7abR~
        rc+=uxdelete(fpath,UXDELDIR,UXDELNOMSG|UXDELFORCE,         //~v7abR~
                    &ctr,&ctr,&ctr);//no need file,ronly,del ctr   //~v7abR~
        UDEQ(UQUE_ENT,Ppqh,pue);                                   //~v7abR~
        ufree(pue);                                                //~v7abR~
    }                                                              //~v7abR~
    return rc;                                                     //~v7abI~
}//dlcmdUNCclearundelsave                                          //~v7abI~
#endif //WINREMOTESUPP                                             //~v7abI~
                                                                   //~v7abI~
#ifdef FTPSUPP                                                     //~v62hR~
//**************************************************************** //~v71eI~
// dlcmtsodundelprepdir                                            //~v71eI~
// prepare for undelete(move deleted to save dir)                  //~v71eI~
//parm1:pcw                                                        //~v71eI~
//parm2:fullpath name                                              //~v71eI~
//parm3:pdh                                                        //~v71eI~
//*ret  :rc 0:ok  1:file on the save dir 4:err                     //~v71eI~
//**************************************************************** //~v71eI~
int dlcmdtsoundelprepdir(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfullpath)//~v71eI~
{                                                                  //~v71eI~
	int rc,driveid,len;                                            //~v71eR~
    PUNDELENTRY pue;                                               //~v71eI~
    PULINEH plh;                                                   //~v71eI~
//  PUFILEH pfh;                                                   //~v71eI~//~vaa7R~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v71eI~
//*******************                                              //~v71eI~
    plh=UGETDIRPLH(Ppdh);                                          //~v71eI~
//  pfh=UGETPFH(plh);                                              //~v71eI~//~vaa7R~
#ifdef UNX                                                         //~v71eI~
    if (dlcmdtbitchk(Ppdh,DLCTBCMSG))//dir t bit chk               //~v71eI~
    	return 4;                                                  //~v71eI~
//chk owner                                                        //~v71eI~
#endif                                                             //~v71eI~
	if (dlcmdgetunddir(Pfullpath))	//set save dir name to Sdatadirname//~v71eI~
    	return 4;                                                  //~v71eI~
	if (!u3270getmembname(0,Pfullpath,membname))	//get membername specification//~v71eR~
    	return 4;                                                  //~v71eI~
	strcpy(Sdatadirname+SAVEFNAMEPOS,membname);                    //~v71eR~
                                                                   //~v71eI~
	len=(int)(UNDELENTRYSZ+strlen(Pfullpath));                     //~v71eI~
	pue=UALLOCC(1,(UINT)len);		//clear QELEM                  //~v71eI~
    UALLOCCHK(pue,4);    //return 4 if malloc err                  //~v71eI~
                                                                   //~v71eI~
	if (!(rc=dlcmdchngname()))	//get save member name             //~v71eI~
      	rc=uxmove(Pfullpath,Sdatadirname,FILE_ALL,0);              //~v71eI~
	if (rc)                                                        //~v71eI~
    {                                                              //~v71eI~
   		ufree(pue);                                                //~v71eI~
   		return 4;                                                  //~v71eI~
	}                                                              //~v71eI~
//save undel info                                                  //~v71eI~
    pue->UDEflag=0;                                                //~v71eI~
	strcpy(pue->UDEmembname,Sdatadirname+SAVEFNAMEPOS);            //~v71eI~
	strcpy(pue->UDEorgfname,Pfullpath);                            //~v71eI~
    driveid=(int)DRIVEID(Gworkdir);                                //~v71eI~
    UENQ(UQUE_TOP,&(Sdrivelist[driveid].UDDqueh),pue);//lifo       //~v71eI~
//  return dirsavename(plh,pue->UDEmembname);                      //~v71eI~//~va00R~
//  return BYUTF8_dirsavename(plh,pue->UDEmembname);               //~va0GR~
    return dirsavename(plh,pue->UDEmembname);                      //~va0GI~
}//dlcmdtsoundelprepdir                                            //~v71eI~
//**************************************************************** //~v62hI~
// dlcmdftpundelprepdir                                            //~v62hI~
// undo prepare for remote dir                                     //~v62hI~
//parm1:pcw                                                        //~v62hI~
//parm2:fullpath name                                              //~v62hI~
//parm3:pdh                                                        //~v62hI~
//*ret  :rc 0:renamed skip delete  1:continue delete, 4:err        //~v62hR~
//**************************************************************** //~v62hI~
int dlcmdftpundelprepdir(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfullpath)//~v62hR~
{                                                                  //~v62hI~
	int rc;                                                        //~v62hI~
    char savename[_MAX_PATH];                                      //~v62hR~
//*******************                                              //~v62hI~
	rc=dlcmdftpundelprechk(Pfullpath,savename);                    //~v62hI~
    if (rc)                                                        //~v62hI~
    	return rc;		//1:del sved;continue delete               //~v62hI~
    rc=xeftprename(Ppfh->UFHpuftph,Pfullpath,savename);            //~v62hI~
    if (rc)                                                        //~v62hI~
    	return 4;		//1:del sved;continue delete               //~v62hI~
	rc=dlcmdftpundelprep(Ppcw,Ppdh,Pfullpath,savename);            //~v62hI~
    if (rc)                                                        //~v62hI~
    	return 4;		//1:del sved;continue delete               //~v62hI~
    return 0;		                                               //~v62hR~
}//dlcmdftpundelprepdir                                            //~v62hI~
//**************************************************************** //~v62hI~
// dlcmdftpundelprechk                                             //~v62hR~
// undo prepare condition chk                                      //~v62hI~
//*ret  :rc 0:ok  1:file on the save dir                           //~v62hR~
//**************************************************************** //~v62hI~
int dlcmdftpundelprechk(UCHAR *Pfullpath,char *Pnewname)           //~v62hR~
{                                                                  //~v62hI~
    char *membname;                                                //~v62hI~
//*******************                                              //~v62hI~
//  if (dlcmdgetunddir(Pfullpath))	//set save dir name to Sdatadirname//~v62kR~
//  	return 4;                                                  //~v62kR~
    if (!(UCBITCHK(Gopt3,GOPT3UNDELFREE|GOPT3UNDELLEAVE)))         //~v62hR~
    	return 1;		//no save                                  //~v62hI~
    if (dlcmdftpundelnamechk(Pfullpath))	//renamed deleted file //~v62hI~
    	return 1;                                                  //~v62hI~
	membname=Pfullpath+FTP_PATHLEN(Pfullpath);	//offset of file name//~v62hR~
    if (Pnewname)                                                  //~v62hI~
		dlcmdftpundelname(membname,Pnewname);                      //~v62hR~
    return 0;		//undoable                                     //~v62hI~
}//dlcmdftpundelprechk                                             //~v62hR~
//**************************************************************** //~v62hI~
int dlcmdftpundelnamechk(UCHAR *Pfullpath)                         //~v62hI~
{                                                                  //~v62hI~
	int len;                                                       //~v62hI~
    char *membname;                                                //~v62hI~
//********************                                             //~v62hI~
	membname=Pfullpath+FTP_PATHLEN(Pfullpath);	//offset of file name//~v62hI~
//  len=strlen(membname);                                          //~v62hI~//~vb30R~
    len=(int)strlen(membname);                                     //~vb30I~
    if (len>=sizeof(FTPUNDELPREFIX)                                //~v62hI~
    &&  !memcmp(membname,FTPUNDELPREFIX,sizeof(FTPUNDELPREFIX)-1)) //~v62hI~
    {                                                              //~v62hI~
        if (len>sizeof(FTPUNDELPOSTFIX)                            //~v62hI~
        &&  !memcmp(membname+len-FTPUNDELPOSTFIXLEN,FTPUNDELPOSTFIX,sizeof(FTPUNDELPOSTFIX)-1))//~v62hI~
	    	return 1;		//no save                              //~v62hI~
    }                                                              //~v62hI~
    return 0;                                                      //~v62hI~
}//dlcmdftpundelnamechk                                            //~v62hI~
//**************************************************************** //~v62hI~
int dlcmdftpundelname(UCHAR *Pmembname,UCHAR *Pnewname)            //~v62hR~
{                                                                  //~v62hI~
	char renamememb[FTP_MAXPATH];                                  //~vb7eR~
//*******************                                              //~vb7eI~
	dlcUndelPrepRenameLongname(DLCYRLO_NOFSTAT,Pmembname,renamememb,0/*tgtpos*/,sizeof(renamememb)); //select top/tail ascii only//~vb7eI~
//  sprintf(Pnewname,"%s%s%s%s",FTPUNDELPREFIX,Pmembname,          //~v62hI~//~vb7eR~
    sprintf(Pnewname,"%s%s%s%s",FTPUNDELPREFIX,renamememb,         //~vb7eI~
				FTPUNDELPOSTFIX,(char *)utimeedit("YYMMDD-HHMMSS.MIL",0));//~v62kR~
    return 0;		//undoable                                     //~v62hI~
}//dlcmdftpundelname                                               //~v62hI~
//**************************************************************** //~v62hI~
// dlcmdftpundelprep                                               //~v62hI~
// save undel info                                                 //~v62hI~
//*ret  :rc 0:ok  UALLOC_FAILED                                    //~v62hI~
//**************************************************************** //~v62hI~
int dlcmdftpundelprep(PUCLIENTWE Ppcw,PUDIRLH Ppdh,UCHAR *Pfullpath,UCHAR *Pnewname)//~v62hI~
{                                                                  //~v62hI~
	int len,driveid;                                               //~v62hR~
    PUNDELENTRY pue;                                               //~v62hI~
    PULINEH plh;                                                   //~v62hI~
//  char membname[_MAX_PATH];                                      //~v62hR~
//*******************                                              //~v62hI~
	len=(int)(UNDELENTRYSZ+strlen(Pfullpath));                     //~v62hI~
	pue=UALLOCC(1,(UINT)len);		//clear QELEM                  //~v62hI~
    UALLOCCHK(pue,4);    //return 4 if malloc err                  //~v62hI~
    pue->UDEflag=UDEFFTP;//     0x01            //remote file      //~v62hI~
    if (Ppdh->UDHattr & FILE_DIRECTORY)                            //~v62hI~
	    pue->UDEflag|=UDEFFTPDIR;//dir                             //~v62hR~
	strcpy(pue->UDEmembname,Pnewname);                             //~v62hI~
	strcpy(pue->UDEorgfname,Pfullpath);                            //~v62hI~
//  driveid=(int)DRIVEID(*Pfullpath);                              //~v62hR~
    driveid=(int)DRIVEID(Pfullpath);                               //~v62hI~
    UENQ(UQUE_TOP,&(Sdrivelist[driveid].UDDqueh),pue);//lifo       //~v62hR~
    plh=UGETDIRPLH(Ppdh);                                          //~v62hI~
//  strcpy(membname,pue->UDEmembname+FTPUNDELPREFIXLEN);           //~v62hR~
//  *(membname+strlen(membname)-FTPUNDELPOSTFIXLEN)=0;             //~v62hR~
//  return dirsavename(plh,membname);                              //~v62hR~
//  return dirsavename(plh,pue->UDEmembname);                      //~v62hI~//~va00R~
//  return BYUTF8_dirsavename(plh,pue->UDEmembname);               //~va0GR~
    return dirsavename(plh,pue->UDEmembname);                      //~va0GI~
}//dlcmdftpundelprep                                               //~v62hI~
//**************************************************************** //~v62hI~
// dlcmdftpclearundelsave                                          //~v62hI~
// clear temporary save file for remote file delete                //~v62hI~
//*ret  :rc                                                        //~v62hI~
//**************************************************************** //~v62hI~
int dlcmdftpclearundelsave(PUQUEH Ppqh)                            //~v62hR~
{                                                                  //~v62hI~
	PUNDELENTRY pue,pueprev=0;                                     //~v62hR~
	PUFTPHOST puftph,puftph0=NULL;                                      //~v62hR~//~vafcR~
//  char *pfnm,unddirname[_MAX_PATH];                              //~v62hR~//~vb7eR~
    char *pfnm,unddirname[FTP_MAXPATH2];                           //~vb7eI~
    int  ctr,rc=0;                                                 //~v62hR~
    UQUEH  tmpqh;                                                  //~v62hI~
//*******************                                              //~v62hI~
	memset(&tmpqh,0,sizeof(tmpqh));                                //~v62hR~
	for (;;)                                                       //~v62hI~
    {                                                              //~v62hI~
        for (pue=UGETQEND(Ppqh),puftph=0,ctr=0;pue;pue=pueprev)  //fifo//~v62hR~
        {                                                          //~v62hI~
	        pueprev=UGETQPREV(pue);  //fifo                        //~v62hR~
            if (pue->UDEflag & UDEFFTP)//remote file               //~v62hI~
            {                                                      //~v62hI~
                pfnm=pue->UDEorgfname;                             //~v62hR~
	            if (pue->UDEflag & UDEFFTPDIR)//remote dir         //~v62hI~
                {                                                  //~v62hI~
                	strcpy(unddirname,pfnm);                       //~v62hI~
                    strcpy(unddirname+FTP_PATHLEN(unddirname),pue->UDEmembname);//~v62hR~
	        		rc=uxdelete(unddirname,UXDELDIR,UXDELNOMSG|UXDELFORCE,//~v62hI~
								&ctr,&ctr,&ctr);//no need file,ronly,del ctr//~v62hI~
			    	UDEQ(UQUE_ENT,Ppqh,pue);                       //~v62hI~
                    ufree(pue);                                    //~v62hI~
                    continue;                                      //~v62hI~
                }                                                  //~v62hI~
                if (!uftpisremote(pfnm,&puftph))//local(xehosts may updated)//~v62hR~
                {                                                  //~v62hI~
			    	UDEQ(UQUE_ENT,Ppqh,pue);                       //~v62hM~
                    ufree(pue);                                    //~v62hI~
                    continue;                                      //~v62hI~
                }                                                  //~v62hI~
                if (!ctr)                                          //~v62hI~
                    puftph0=puftph;                                //~v62hI~
                else                                               //~v62hI~
                    if (puftph!=puftph0)                           //~v62hR~
        	            continue;                                  //~v62hI~
                UDEQ(UQUE_ENT,Ppqh,pue);                           //~v62hI~
            	UENQ(UQUE_TOP,&tmpqh,pue);//lifo                   //~v62hI~
                ctr++;                                             //~v62hI~
            }//remote                                              //~v62hI~
        }                                                          //~v62hI~
        if (!ctr)                                                  //~v62hI~
        	break;                                                 //~v62hI~
		rc+=dlcftpmultidelterm(puftph0,&tmpqh);                    //~v62hR~
        uqufree(&tmpqh);                                           //~v62hR~
    }                                                              //~v62hI~
    return rc;                                                     //~v62hR~
}//dlcmdftpclearundelsave                                          //~v62hI~
//**************************************************************** //~v62hI~
// delete temp saved rename entry                                  //~v62hI~
//**************************************************************** //~v62hI~
int dlcftpmultidelterm(PUFTPHOST Ppuftph,PUQUEH Ppqh)              //~v62hR~
{                                                                  //~v62hI~
    PUFTPMULTIDEL pfmd,pfmd0;                                      //~v62hR~
	PUNDELENTRY pue;                                               //~v62hI~
    int delctr,len,ii,rc;                                          //~v62kR~
    char *pfnm;                                                    //~v62hR~
//*********************                                            //~v62hI~
//  delctr=UGETQCTR(Ppqh);                                         //~v62hI~//~vb31R~
    delctr=(int)UGETQCTR(Ppqh);                                    //~vb31I~
    if (!delctr)                                                   //~v62hI~
    	return 0;                                                  //~v62hI~
//  pfmd=pfmd0=umalloc((UINT)(delctr*UFTPMULTIDELSZ));             //~v62hR~//~vb30R~
    pfmd=pfmd0=umalloc((size_t)delctr*UFTPMULTIDELSZ);             //~vb30I~
    UALLOCCHK(pfmd,UALLOC_FAILED);                                 //~v62hI~
	for (pue=(PUNDELENTRY)UGETQTOP(Ppqh);pue;pue=UGETQNEXT(pue))   //~v62hI~
    {                                                              //~v62hI~
//      len=strlen(pue->UDEorgfname)+strlen(pue->UDEmembname)+2;   //~v62hR~//~vb30R~
        len=(int)(strlen(pue->UDEorgfname)+strlen(pue->UDEmembname)+2);//~vb30I~
//      pfnm=umalloc(len);                                         //~v62hI~//~vb30R~
        pfnm=umalloc((size_t)len);                                 //~vb30I~
    	UALLOCCHK(pfnm,UALLOC_FAILED);                             //~v62hI~
        strcpy(pfnm,pue->UDEorgfname+Ppuftph->UFTPHhostnmlen+1);   //~v62hR~
        strcpy(pfnm+FTP_PATHLEN(pfnm),pue->UDEmembname);           //~v62hI~
    	pfmd->UFMDpfpath=pfnm;                                     //~v62hR~
    	pfmd->UFMDattr=0;                                          //~v62hR~
    	pfmd->UFMDparm=pue;	//back chain                           //~v62hR~
        pfmd++;                                                    //~v62hI~
    }                                                              //~v62hI~
    rc=uftpmultidel(0,Ppuftph,pfmd0,delctr,0);                     //~v62hR~
	for (pfmd=pfmd0,ii=0;ii<delctr;ii++,pfmd++)                    //~v62hI~
    {                                                              //~v62hI~
    	ufree(pfmd->UFMDpfpath);                                   //~v62hI~
    }                                                              //~v62hI~
    ufree(pfmd0);                                                  //~v62hI~
    return rc;                                                     //~v62kR~
}//dlcftpmultidelterm                                              //~v62hR~
#endif                                                             //~v62hI~
//****************************************************************
// dlcmdgetunddir
// setup undel save dir
//parm1:fullpath name
//*ret  :rc
//****************************************************************
int dlcmdgetunddir(UCHAR *Pfullpath)
{
	int rc,index;
	UCHAR unddirname[_MAX_PATH];
    int	 driveid;
#ifdef FTPSUPP                                                     //~v71eI~
    int tsosw;                                                     //~v71eI~
#endif                                                             //~v71eI~
#ifdef W32                                                         //~vay4I~
	int reservednameid=0;                                          //~vay4I~
#endif                                                             //~vay4I~
//*******************
//chk top dir for each drive
//  driveid=(int)DRIVEID(*Pfullpath);                              //~v62hR~
#ifdef FTPSUPP                                                     //~v71eI~
  if ((tsosw=u3270fullpathistso(Pfullpath)))	                   //~v71eR~
    driveid=(int)DRIVEID(Gworkdir);                                //~v71eI~
  else                                                             //~v71eI~
#endif                                                             //~v71eI~
    driveid=(int)DRIVEID(Pfullpath);                               //~v62hI~
#ifdef W32                                                         //~vay4I~
	reservednameid=getReservedFileDriveid(Pfullpath,&driveid);     //~vay4I~
#endif                                                             //~vay4I~
	if (Sdrivelist[driveid].UDDindex)	//not first time
    {
#ifdef UNX                                                         //~v19KI~
#else  //!UNX                                                      //~v19KI~
  #ifdef FTPSUPP                                                   //~v71eI~
      if (tsosw)                                                   //~v71eI~
		memcpy(Sdatadirname,Gworkdir,2);	//copy drive           //~v71eI~
      else                                                         //~v71eI~
  #endif                                                           //~v71eI~
  	  {                                                            //~vay4I~
  #ifdef W32                                                       //~vay4I~
	   if (reservednameid)                                         //~vay4I~
		memcpy(Sdatadirname,Pfullpath+RESERVED_NAMEID_CTR,2);	//copy drive//~vay4I~
       else                                                        //~vay4I~
  #endif                                                           //~vay4I~
		memcpy(Sdatadirname,Pfullpath,2);	//copy drive
      }                                                            //~vay4I~
#endif //!UNX                                                      //~v19KI~
		sprintf(Sdatadirname+SEQEDITPOS,Sseqdatadiredit,
//  			Sdrivelist[driveid].UDDindex,'\\');                //~v19aR~
    			Sdrivelist[driveid].UDDindex,DIR_SEPC);            //~v19aI~
    	return 0;
	}
#ifdef UNX                                                         //~v19KI~
#else  //!UNX                                                      //~v19KI~
//  memcpy(unddirname,Pfullpath,2);	//copy drive                   //~v62hR~
    *unddirname=(UCHAR)('A'+driveid);                              //~v62kR~
    *(unddirname+1)=':';                                           //~v62hI~
#endif //!UNX                                                      //~v19KI~
//  strcpy(unddirname+2,Stopdirname);                              //~v19KR~
    strcpy(unddirname+ROOTDIRPOS,Stopdirname);                     //~v19KI~
	if (rc=dlcmdgetunddirsub(unddirname),rc)
    	return rc;
//chk date dir for each drive
//  strcat(unddirname,"\\");                                       //~v19aR~
    strcat(unddirname,DIR_SEPS);                                   //~v19aI~
    strcat(unddirname,getundeldate());	//seconddir
	if (rc=dlcmdgetunddirsub(unddirname),rc)
    	return rc;
//seach last seqno;
	strcpy(unddirname+SEQEDITPOS,SEQDIRMASK);
	if (!(index=dlcmdgetindex(unddirname,0,SEQDIRSEQNOSZ)))	//start from 0,len=6
    	return 4;
	sprintf(unddirname+SEQEDITPOS,Sseqdatadiredit,index,0);	//
	if (umkdir(unddirname))
		 	return 4;
    strcpy(Sdatadirname,unddirname);
//  strcpy(Sdatadirname+SAVEFNAMEPOS-1,"\\");                      //~v19aR~
    strcpy(Sdatadirname+SAVEFNAMEPOS-1,DIR_SEPS);                  //~v19aI~
	Sdrivelist[driveid].UDDindex=index;
    return 0;
}//dlcmdgetunddir

//****************************************************************
// dlcmdgetunddirsub
// setup undel save dir for the level
//parm1:fullpath name
//*ret  :rc
//****************************************************************
int dlcmdgetunddirsub(UCHAR *Pfullpath)
{
	int rc;
    FILEFINDBUF3    fstat3;
//*******************
    switch (rc=filefind(Pfullpath,0,&fstat3,FFNONFMSG|FFNODIRMSG),rc)
    {
    case 0:         //file found(same name)
        uerrmsg("%s (dir for Undelete data save) is not directory",
                "%s がディレクトリーでない,削除データの保存不可",
				Pfullpath);
        return 4;
    case 4:         //not found
	    if (umkdir(Pfullpath))
		 	return 4;
    	break;
    case 16:		//dir
    	break;
    default:
    	return rc;
	}
    return 0;
}//dlcmdgetunddirsub

//****************************************************************
// dlcmdgetindex
// get next save dir index
//parm1:fullpath filename patern
//parm2:patern start
//parm3:patern len
//*ret  :index number
//****************************************************************
int dlcmdgetindex(UCHAR *Pmaskname,int Poffset,int Plen)
{
	int ii,filectr;
    PUDIRLIST       pudirlist,pudirlist0;
//*******************
//  filectr=udirlist(Pmaskname,FILE_ALL,&pudirlist,'N');//name seq //~v43SR~
    filectr=udirlistnomsg(Pmaskname,FILE_ALL,&pudirlist,'N');//name seq//~v43SI~
    if (filectr>0)
    {
		pudirlist0=pudirlist;
		for (ii=filectr-1,pudirlist+=ii;ii>=0;ii--,pudirlist--)
    	{
    		if ((int)strspn(pudirlist->name+Poffset,"0123456789")==Plen)//~v085R~
        		break;
    	}
    	if (ii<0)	//not found
    		filectr=1;
		else
    		filectr=atoi(pudirlist->name+Poffset)+1;
//  	ufree(pudirlist0);                                         //~vandR~
    	UDIRLIST_FREE(pudirlist0);                                 //~vandI~
    }
    else
   		filectr=1;
    return filectr;
}//dlcmdgetindex

//****************************************************************
// dlcmdchngname
// try another name bacause rename failed
//parm1:fullpath name
//*ret  :rc 0:contine process by another name,4:err
//****************************************************************
int dlcmdchngname(void)
{
	int rc,ii;
    FILEFINDBUF3    fstat3;
    UCHAR *pc,*pc2;
//*******************
    rc=filefind(Sdatadirname,0,&fstat3,FFNONFMSG|FFNODIRMSG);   //~v05ZR~
    if (rc==4)				//not found                         //~v05ZI~
    	return 0;                                               //~v05ZI~
    if (rc!=0 && rc!=16)	//other than found or dir           //~v05ZR~
    	return 4;                                               //~v05ZR~
	pc=Sdatadirname+SAVEFNAMEPOS;	//filename fld
//  if (!(pc2=strchr(pc,'.')))				//extention pos        //~v0f0R~
    if (!(pc2=strrchr(pc,'.')))		//last extention pos           //~v0f0I~
    {
    	pc2=pc+strlen(pc);
        *pc2='.';
	}
    pc2++;
    for (ii=1;;ii++)
    {
    	sprintf(pc2,"%03d",ii);
	    rc=filefind(Sdatadirname,0,&fstat3,FFNONFMSG|FFNODIRMSG);
        if (rc==4)		//not found
        	break;
	    if (rc!=0 && rc!=16)	//other than found or dir
    		return 4;
	}
    return 0;
}//dlcmdchngname

//****************************************************************
// getundeldate
// get current date dir name
//parm1:fullpath name
//*ret  :rc 0:contine process by another name,4:err
//****************************************************************
UCHAR *getundeldate(void)
{
//*******************
    if (!*Sundeldate)	//same date over midnight for all drive
    	utimeedit(DATEFMT1,Sundeldate);
	return Sundeldate;
}//getundeldate
//****************************************************************
// errnodata
// no saved data msg
//parm:none
//*ret:rc 4
//****************************************************************
int errnodata(void)
{
//*******************
	uerrmsg("No saved deleted data",                            //~6107R~
            "削除保存データなし");                              //~6107R~
    return 4;
}//errnodata
//****************************************************************
// errinvaliddata
// not saved data
//parm:none
//*ret:rc 4
//****************************************************************
int errinvaliddata(void)
{
//*******************
	uerrmsg("not valid save file",
            "削除保存データに非ず");
    return 4;
}//errinvaliddata
#ifdef W32                                                         //~vay4I~
//**************************************************************** //~vay4I~
//*rc:1 reserved file name(\\.\g:\... fmt)                         //~vay4I~
//**************************************************************** //~vay4I~
int getReservedFileDriveid(char *Pfullpath,int *Pdriveid)          //~vay4R~
{                                                                  //~vay4I~
	int rc=0;                                                      //~vay4I~
//**************************                                       //~vay4I~
    if (strlen(Pfullpath)>RESERVED_NAMEID_CTR                      //~vay4I~
    &&  !memcmp(Pfullpath,RESERVED_NAMEID,RESERVED_NAMEID_CTR))    //~vay4I~
    {                                                              //~vay4I~
		rc=1;                                                      //~vay4I~
	    *Pdriveid=(int)DRIVEID(Pfullpath+RESERVED_NAMEID_CTR);     //~vay4R~
    }                                                              //~vay4I~
    return rc;                                                     //~vay4I~
}//getReservedFileDriveid                                          //~vay4I~
#endif                                                             //~vay4I~
//*********************************************************************************//~vb7cI~
//* too long namne at undel dir, rename to shortname               //~vb7cI~
//* from top and tail select 8 ascii each                          //~vb7eI~
//*********************************************************************************//~vb7cI~
int dlcUndelPrepRenameLongname(int Popt,char *Psrc,char *Ptgt,int Ptgtpos,int Pbuffsz)//~vb7cR~
{                                                                  //~vb7cI~
	int len,rc2,ii;                                                //~vb7cR~
    char *pci,*pco,*pcilast;                                       //~vb7cR~
//**************************                                       //~vb7cI~
	len=(int)strlen(Psrc);                                         //~vb7cI~
	pco=Ptgt+Ptgtpos;                                              //~vb7cI~
    *pco++='R';                                                    //~vb7cI~
    *pco++='_';                                                    //~vb7cI~
	for (pci=Psrc,ii=0;ii<8 && *pci;ii++)                          //~vb7cI~
    	if (*pci<0x80)                                             //~vb7cI~
        	*pco++=*pci++;                                         //~vb7cI~
    *pco++='_';                                                    //~vb7cI~
    pcilast=Psrc+len-8;                                            //~vb7cR~
    if (pci<pcilast)                                               //~vb7cI~
        pci=pcilast;                                               //~vb7cI~
	for (ii=0;ii<8 && *pci;ii++)                                   //~vb7cR~
    	if (*pci<0x80)                                             //~vb7cI~
        	*pco++=*pci++;                                         //~vb7cR~
    *pco++='_';                                                    //~vb7cI~
    *pco++='R';                                                    //~vb7cI~
	if (Popt & DLCYRLO_NOFSTAT)                                    //~vb7cI~
    {                                                              //~vb7cI~
	    *pco++=0;	//strz                                         //~vb7cI~
        return 0;                                                  //~vb7cI~
    }                                                              //~vb7cI~
    *(pco+1)=0;	//strz                                             //~vb7cI~
    for (ii='a';ii<='z';ii++)                                      //~vb7cI~
    {                                                              //~vb7cI~
    	*pco=(char)ii;                                             //~vb7cI~
        rc2=(int)ufstat(Ptgt,0);                                   //~vb7cR~
        if (rc2)                                                   //~vb7cR~
        	break;                                                 //~vb7cI~
    }                                                              //~vb7cI~
    if (ii>'z')                                                    //~vb7cI~
    {                                                              //~vb7cI~
    	uerrmsg("Too many long-name-entry, move to Undel-dir(%s) failed.",//~vb7cI~
        		"長すぎるパス名が多すぎて UNDEL ディレクトリー(%s)に移動できません",//~vb7cI~
                Ptgt);                                             //~vb7cI~
    	return 4;                                                  //~vb7cI~
    }                                                              //~vb7cI~
    return 0;                                                      //~vb7cI~
}//dlcUndelPrepRenameLongname                                      //~vb7cI~
//**************************************************************** //~vb7fI~
// dlcmdftpclearundelsaveDeleted                                   //~vb7fR~
// clear temporary save file for remote file delete                //~vb7fI~
//*ret  :rc                                                        //~vb7fI~
//**************************************************************** //~vb7fI~
int dlcmdftpclearundelsaveDeleted(char *Pfpathrenamesave)          //~vb7fR~
{                                                                  //~vb7fI~
	PUNDELENTRY pue;                                               //~vb7fI~
    int  rc=4,pathlen,pathlen2;                                    //~vb7fR~
	PUQUEH 	pqh;                                                   //~vb7fI~
    char path[FTP_MAXPATH],*pmemb;                                 //~vb7fI~
//*******************                                              //~vb7fI~
	pathlen=FTP_PATHLEN(Pfpathrenamesave);                         //~vb7fR~
    if (pathlen<0)                                                 //~vb7fI~
    	return 4;                                                  //~vb7fI~
    UmemcpyZ(path,Pfpathrenamesave,(size_t)pathlen);               //~vb7fR~
    pmemb=Pfpathrenamesave+pathlen;                                //~vb7fR~
    pqh=&Sdrivelist[LASTDRIVE].UDDqueh;                            //~vb7fI~
    for (pue=UGETQTOP(pqh);pue;pue=UGETQNEXT(pue))                 //~vb7fR~
    {                                                              //~vb7fI~
        pathlen2=FTP_PATHLEN(pue->UDEorgfname);                    //~vb7fI~
        if (pathlen==pathlen2                                      //~vb7fR~
        &&  !memcmp(path,pue->UDEorgfname,(size_t)pathlen)         //~vb7fI~
        &&  !strcmp(pmemb,pue->UDEmembname)                        //~vb7fI~
        )                                                          //~vb7fI~
        {                                                          //~vb7fI~
    		UDEQ(UQUE_ENT,pqh,pue);                                //~vb7fI~
        	ufree(pue);                                            //~vb7fR~
            rc=0;                                                  //~vb7fI~
        	break;                                                 //~vb7fI~
        }                                                          //~vb7fI~
    }                                                              //~vb7fI~
    UTRACEP("%s:rc=%d,Prenamesave=%s\n",UTT,rc,Pfpathrenamesave);  //~vb7fR~
    return rc;                                                     //~vb7fI~
}//dlcmdftpclearundelsaveDeleted                                   //~vb7fI~
//**************************************************************** //~vb7fI~
// dlcmdftpclearundelsave                                          //~vb7fI~
// clear temporary save file for remote file delete                //~vb7fI~
//*ret  :rc                                                        //~vb7fI~
//**************************************************************** //~vb7fI~
int dlcmdftpclearundelsaveDeletedDir(char *Pfpathrenamesave)       //~vb7fI~
{                                                                  //~vb7fI~
    int  rc;                                                       //~vb7fR~
//*******************                                              //~vb7fI~
    if (!strstr(Pfpathrenamesave,FTPUNDELPREFIX))	//"..xe.."     //~vb7fI~
    	return 4;                                                  //~vb7fI~
	rc=dlcmdftpclearundelsaveDeleted(Pfpathrenamesave);            //~vb7fI~
    UTRACEP("%s:rc=%d,Prenamesave=%s\n",UTT,rc,Pfpathrenamesave);  //~vb7fI~
    return rc;                                                     //~vb7fI~
}//dlcmdftpclearundelsaveDeleted                                   //~vb7fI~
