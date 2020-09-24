//*CID://+v702R~:                             update#=  411;       //+v702R~
//************************************************************* //~5903R~
//*ufile2f.c                                                       //~v56jR~
//*  FTP  version of                                               //~v56jR~
//      rename,remove,umkdir,urmdir,uattrib,ugetftime,usetftime,ucopypathinfo//~v56jR~
//************************************************************* //~5617I~
//v702:200615 ARM compiler warning                                 //+v702I~
//v6H7:170108 FTP crush by long name                               //~v6H7I~
//v6Dk:160625 (BUG)ftp may clash when cmd failed                   //~v6DkI~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6uW:140610 (W32UNICODE)support UDfmt for ftp filename           //~v6uWI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6ht:120729 (LNX)display odd number file time stamp              //~v6htI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6dj:120323 (BUG of ftp)xdd did not delete subdir                //~v6djI~
//v6da:120217 (Axe)smb support                                     //~v6daI~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v6d5:120209 (BUG:LNX)psftp chmod err on log(site chmod failed)   //~v6d5I~
//v6d4:120206 (BUG:LNX)ftp mkdir with mode option faile with "new mode=0 chk umask" msg//~v6d4I~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1R~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61b:071123*(FTP)log errmsg to ftplog alos                       //~v61bI~
//v5k1:061227*(LNX/WIN)issue err msg when ftp remote file rename/delete skipped//~v5k1I~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5fq:050321 (BUG:FTP)multidel/multirename err rc set missing     //~v5fqI~
//v5fn:050317 (FTP)undel support                                   //~v5fnI~
//v5fd:050101 (FTP)fulction to delete multiple file at once.       //~v5fdI~
//v5ev:041031 ftp chmod:try rsh after setmod failed                //~v5evI~
//v5d7:040529 (FTP)delete process duplicated                       //~v5d7I~
//v5cn:040508 (FTP:BUG)abend when mkdir faile(551:exist)           //~v5cnI~
//v5bg:040204 (FTP:BUG)rename should have valid pathname for newname//~v5bfI~
//v5bf:040204 (FTP:BUG)space containing filename support           //~v5bfI~
//v5am:040110 (FTP)del file in a dir at once for performance       //~v5amI~
//v5ah:040108 (FTP)ignore new name path on rename                  //~v5ahI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//************************************************************* //~5903I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5825I~
#include <sys/types.h>                                             //~0827I~
#include <sys/stat.h>                                              //~0827R~
#ifdef UNX                                                         //~v56jI~
	#include <unistd.h>                                            //~v56jR~
#else                                                              //~v56jI~
	#include <dos.h>                                               //~v56jI~
//  #include <error.h>                                             //~v5ncR~
#endif                                                             //~v56jI~
//*******************************************************
//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v56jI~
#include <ufile.h>
#include <ufile2.h>                                             //~5826I~
#include <ufile5.h>                                                //~v56jI~
#include <ufemsg.h>                                                //~v036I~
#include <uerr.h>
#include <ualloc.h>                                             //~5913I~
#include <ustring.h>                                               //~v085I~
#include <utrace.h>                                                //~v012I~
#include <uedit.h>                                                 //~v195R~
#ifdef UNX                                                         //~v56jI~
	#include <uunxsub.h>                                           //~v56jR~
#endif                                                             //~v56jI~
#ifdef FTPSUPP                                                     //~v56jI~
#ifdef UNX                                                         //~v56jI~
	#include <ufile2l.h>                                           //~v56jI~
#endif                                                             //~v56jI~
	#include <uftp.h>                                              //~v56jI~
	#include <ufile1f.h>                                           //~v56jI~
	#include <uftp3.h>                                             //~v61pI~
#endif                                                             //~v56jI~
#include <uproc.h>                                                 //~v5evR~
#include <uproc2.h>                                                //~v5evI~
#include <u3270.h>                                                 //~v5jdI~
#include <u32702.h>                                                //~v5jdI~
#ifdef ARMXXE                                                      //~v6daI~
	#include <jnic2ju.h>                                           //~v6daI~
#endif                                                             //~v6daI~
#include <ufilew.h>                                                //~v6uWI~
//*******************************************************
static int Srenameopt=0;                                           //~v56jI~
static int Sxdelopt;                                               //~v6H7M~
static int Sxdelwctr;                                              //~v6H7M~
static int *Spdelfctr;       //process ctr                         //~v6H7M~
static int *Spdeldctr;       //deleted file/dir ctr                //~v6H7M~
static int *Spdelrctr;   //read only file/dir ctr                  //~v6H7M~
static int *Spdellongnamectr;   //too long name file ctr           //~v6H7M~
static FILESZT *Spdelsize;    //total size deleted by xdd          //~v6H7M~
//*******************************************************
int uftprenamesub(PUFTPHOST Ppuftph,UCHAR *Poldname,UCHAR *Pnewname);//~v5afR~
int uftpwildrename(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm);//~v5afR~
int ufile2putstmt(FILE *Phfile,char *Pcmd,char *Pfnm);             //~v5amI~
//int uftpxdelrchk(PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr); //~v61pR~
int uftpxdelrchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pI~
//int uftpmultidelrchk(PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pR~
int uftpmultidelrchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pI~
//int uftpmultirenamerchk(PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pR~
int uftpmultirenamerchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pI~
void uftpbypassreason(int Popt,char *Pfnm,ULONG Pattr);            //~v5k1I~
#ifdef ARMXXE                                                      //~v6daI~
int uftpsmbj_multidel(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Pwf2p);//~v6daI~
int uftpsmbj_multirename(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppvoid);//~v6daR~
int uftpsmbj_wildxdel(int Popt,PUFWF2PARM Ppvoid);                 //~v6daI~
int uftpsmbj_wildfunc2(int Popt,PUFTPHOST Ppuftph,FTPCMD_CALLBACK Pfunc,PUFWF2PARM Pwf2p);//~v6daI~
#endif                                                             //~v6daI~
//int uftpdelsubdir(int Popt,PUFWF2PARM Ppwf2p,void *Pparm,int *Ppfilectr,FILESZT *Ppfilesize);//~v6djR~
int uftpdelsubdir(int Popt,PUFWF2PARM Ppwf2p);                     //~v6djI~
int	errtoolongname(int Popt,char *Pdir,char *Pmemb,int Prc);       //~v6H7I~
//**************************************************************** //~v56jM~
//*umkdir                                                          //~v56jM~
//*  257:mkd command success                                       //~v56jR~
//*  550:file exist/not found/permisson denied                     //~v56jR~
//*retrn:rc(=errno)                                                //~v56jM~
//**************************************************************** //~v56jM~
int uftpmkdir(PUFTPHOST Ppuftph,UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode)//~v5afR~
{                                                                  //~v56jM~
	FILEFINDBUF3 ffb3;                                             //~v56jI~
    UCHAR ftpcmd[FTP_MAXPATH];                                     //~v56jM~
    char **stdo,**stdo0,*dirname;                                  //~v56jR~
    int stdoctr,rc,rc2,mode=0;                                       //~v56jR~//~v6h7R~
//*********************************                                //~v56jM~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
        return u3270mkdir(Ppuftph,Pdirname,Pmode,Pprmode);         //~v5jdI~
    dirname=Pdirname+Ppuftph->UFTPHhostnmlen+1;                    //~v5afR~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
    {                                                              //~v6daI~
  		return jnismb_mkdir(0,Ppuftph,dirname,Pmode,Pprmode);      //~v6daR~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
    if (Pmode)                                                     //~v56jR~
    {                                                              //~v56jI~
    	mode=(int)(Pmode & FTP_CHMODMASK);                         //~v56jR~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1R~
      {                                                            //~v6d1R~
  		rc=uftp3smb_setcmd(UFTPSMBCMD_MKDIR,Ppuftph,ftpcmd,dirname,0/*charparm2*/,mode,0/*intpam2*/);//~v6d1R~
        if (rc)                                                    //~v6d1R~
        	return rc;	//posix_mkdir may not supported(Unix Extension)//~v6d1R~
      }                                                            //~v6d1R~
      else                                                         //~v6d1R~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
    	sprintf(ftpcmd,                                            //~v61pI~
            "mkdir \"%s\"\n"              \
            "chmod %o \"%s\"\n",                                   //~v61pI~
             dirname,mode,dirname);                                //~v61pI~
      else                                                         //~v61pI~
    	sprintf(ftpcmd,                                            //~v56jI~
            "mkdir \"%s\"\n"              \
            "site chmod %o \"%s\"\n",                              //~v5bfR~
             dirname,mode,dirname);                                //~v56jR~
    }                                                              //~v56jI~
    else                                                           //~v56jI~
	    sprintf(ftpcmd,                                            //~v56jR~
            "mkdir \"%s\"\n",                                      //~v5bfR~
             dirname);                                             //~v56jM~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    stdo=stdo0;                                                    //~v56jI~
    if (!rc)                                                       //~v56jM~
    {                                                              //~v56jM~
//  	rc=uftpsimplerespchk("mkdir","257 550 ",Pdirname,&stdo,&stdoctr,ENOENT);//~v5cnR~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1R~
		rc=uftp3smb_respchk(UFTPSMBCMD_MKDIR,Ppuftph,Pdirname,&stdo,&stdoctr,ENOENT);//~v6d1R~
      else                                                         //~v6d1R~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkOK(UFTP3SRCO_ERRMSG,Ppuftph,"mkdir","mkdir",&stdo,&stdoctr,ENOENT);//~v61pR~
      else                                                         //~v61pI~
    	rc=uftpsimplerespchk("mkdir","257 5** ",Pdirname,&stdo,&stdoctr,ENOENT);//~v5cnI~
        if (!rc)	//mkdir success                                //~v56jI~
        {                                                          //~v56jI~
    		if (Pmode)                         //site chmod issued //~v56jI~
            {                                                      //~v56jI~
		      if (UFTPH_ISSMB(Ppuftph))                            //~v6d1R~
              	rc2=0;                                             //~v6d1R~
              else                                                 //~v6d1R~
              if (UFTPHISPSFTP(Ppuftph))                           //~v61pI~
//  	        rc2=uftp3simplerespchkCHNG(0,Ppuftph,"chmod",dirname,&stdo,&stdoctr,ENOENT);//~v61pR~//~v6d5R~
    	        rc2=uftp3simplerespchkCHNG(UFTP3SRCC_CHMOD,Ppuftph,"chmod",dirname,&stdo,&stdoctr,ENOENT);//~v6d5I~
              else                                                 //~v61pI~
		        rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"200 ");	//site cmd//~v56jI~
                if (rc2)                                           //~v56jI~
                {                                                  //~v61bI~
              	  if (UFTPHISPSFTP(Ppuftph))                       //~v6d1I~
                	uerrmsg("\"chmod %o %s\" failed",0,            //~v6d1I~
					         mode,dirname);                        //~v6d1I~
                  else                                             //~v6d1I~
                	uerrmsg("\"site chmod %o %s\" failed",0,	   //~v56jI~
					         mode,dirname);                        //~v56jI~
					uftplog(FTPLOG_ERRM,0);	//logging errmsg       //~v61bI~
                }                                                  //~v61bI~
            }                                                      //~v56jI~
            if (Pprmode)                                           //~v56jR~
            {                                                      //~v56jR~
//              if (uftpfstat(Ppuftph,dirname,&ffb3))              //~v5afR~//~v6d4R~
                if (uftpfstat(Ppuftph,Pdirname,&ffb3))             //~v6d4I~
                    *Pprmode=0;                                    //~v56jM~
                else                                               //~v56jI~
                    *Pprmode=FILE_GETMODE(ffb3.attrFile) & FTP_CHMODMASK;//~v56jM~
            }                                                      //~v56jR~
        }                                                          //~v56jI~
	    ufree(stdo0);                                              //~v56jM~
    }                                                              //~v56jM~
    return rc;                                                     //~v56jR~
}//uftpmkdir                                                       //~v56jM~
//**************************************************************** //~v56jM~
//*urmdir                                                          //~v56jM~
//* remove dir                                                     //~v56jM~
//*  250:rmd command success                                       //~v56jI~
//*  550:file exist/not found/permisson denied                     //~v56jI~
//*retrn:rc(=errno),-2:root dir,-3:current dir                     //~v56jM~
//**************************************************************** //~v56jM~
int uftprmdir(PUFTPHOST Ppuftph,UCHAR *Pdirname)                   //~v5afR~
{                                                                  //~v56jM~
    UCHAR ftpcmd[FTP_MAXPATH];                                     //~v56jI~
    char **stdo,**stdo0,*dirname;                                  //~v56jI~
    int stdoctr,rc;                                                //~v56jI~
//********************                                             //~v56jM~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270rmdir(Ppuftph,Pdirname);                       //~v5jdI~
    dirname=Pdirname+Ppuftph->UFTPHhostnmlen+1;                    //~v5afR~
    if (FTP_ROOTDIR(dirname))  //dosfindfirst faile if root        //~v56jR~
        return ufileroot(Pdirname,-2);                             //~v56jM~
//  if (!uftpfullpath(fpath,Pdirname,FTP_MAXPATH))                 //~v56jI~
//      return -1;                                                 //~v56jI~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
    {                                                              //~v6daI~
  		return jnismb_rmdir(0,Ppuftph,dirname);                    //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
   if (UFTPH_ISSMB(Ppuftph))                                       //~v6d1I~
  	uftp3smb_setcmd(UFTPSMBCMD_RMDIR|F3SMBO_NFMSG,Ppuftph,ftpcmd,dirname,0/*charparm2*/,0/*intparm1*/,0/*intpam2*/);//~v6d1R~
   else                                                            //~v6d1I~
    sprintf(ftpcmd,                                                //~v56jI~
            "rmdir \"%s\"\n",                                      //~v5bfR~
             dirname);                                             //~v56jI~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    if (!rc)                                                       //~v56jI~
    {                                                              //~v56jI~
        stdo=stdo0;                                                //~v56jI~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
		rc=uftp3smb_respchk(UFTPSMBCMD_RMDIR,Ppuftph,dirname,&stdo,&stdoctr,1);//~v6d1R~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkOK(0,Ppuftph,"rmdir","rmdir",&stdo,&stdoctr,1);//~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");           //~v56jI~
        switch(rc)                                                 //~v56jI~
        {                                                          //~v56jI~
        case 0:    //250                                           //~v56jR~
        	break;                                                 //~v56jI~
        case 1:    //550                                           //~v56jI~
          if (!UFTPH_ISSMB(Ppuftph))                               //~v6d1I~
		    if (!Gufile_nomsg)   //nomsg option                    //~v56jI~
            {                                                      //~v61bI~
              if (stdo>stdo0)                                      //~v6DkI~
        		uerrmsg("rmdir failed.(%s)",0,                     //~v56jR~
						*(stdo-1));	//already exit or path not found//~v56jR~
              else                                                 //~v6DkI~
        		uerrmsg("rmdir failed.(see ::xeftplog)",0);        //~v6DkR~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            }                                                      //~v61bI~
            rc=ENOENT;                                             //~v56jI~
        	break;                                                 //~v56jI~
        default:                                                   //~v56jI~
            ;                                                      //~v56jI~
        }                                                          //~v56jI~
        ufree(stdo0);                                              //~v56jI~
    }                                                              //~v56jI~
    return rc;                                                     //~v56jR~
}//uftprmdir                                                       //~v56jR~
//**************************************************************** //~v56jI~
//*uremove                                                         //~v56jI~
//* delete file,cannot del dir                                     //~v56jI~
//* 250:command success                                            //~v56jI~
//* 550:no such file                                               //~v56jI~
//*parm1:file name                                                 //~v56jI~
//*retrn:rc(=errno)                                                //~v56jI~
//**************************************************************** //~v56jI~
int uftpremove(PUFTPHOST Ppuftph,int Popt,UCHAR *Pfilename)        //~v5afR~
{                                                                  //~v56jI~
    UCHAR ftpcmd[FTP_MAXPATH];                                     //~v56jI~
    char **stdo,**stdo0,*pfname;                                   //~v56jR~
    int stdoctr,rc;                                                //~v56jR~
//*********************************                                //~v56jI~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270remove(Ppuftph,Popt,Pfilename);                //~v5jdI~
    pfname=Pfilename+Ppuftph->UFTPHhostnmlen+1;                    //~v5afR~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
    {                                                              //~v6daI~
  		return jnismb_delete(0,Ppuftph,pfname);                    //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
  if (UFTPH_ISSMB(Ppuftph))                                        //~v6d1I~
  	uftp3smb_setcmd(UFTPSMBCMD_DELETE|F3SMBO_NFMSG,Ppuftph,ftpcmd,pfname,0/*charparm2*/,0/*intparm1*/,0/*intpam2*/);//~v6d1R~
  else                                                             //~v6d1I~
    sprintf(ftpcmd,                                                //~v56jI~
            "delete \"%s\"\n",                                     //~v5bfR~
             pfname);                                              //~v56jI~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    if (!rc)                                                       //~v56jI~
    {                                                              //~v56jI~
        stdo=stdo0;                                                //~v56jI~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
		rc=uftp3smb_respchk(UFTPSMBCMD_DELETE,Ppuftph,pfname,&stdo,&stdoctr,1);//~v6d1R~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkOK(0,Ppuftph,"delete","rm",&stdo,&stdoctr,1);//~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");           //~v56jI~
        switch(rc)                                                 //~v56jI~
        {                                                          //~v56jI~
        case 0:    //250                                           //~v56jI~
    	    if (Popt & UXDELMSG) //msg put option                  //~v56jI~
//       	   ufiledeleted(Pfilename,'F',-1,0);//size=-1  mean no display size/attr//~v5k0R~
         	   ufiledeleted(Pfilename,'F',(FILESZT)(-1),0);//size=-1  mean no display size/attr//~v5k0R~
        	break;                                                 //~v56jI~
        case 1:    //550                                           //~v56jI~
          if (!UFTPH_ISSMB(Ppuftph))                               //~v6d1I~
		    if (!Gufile_nomsg)   //nomsg option                    //~v56jI~
            {                                                      //~v61bI~
              if (stdo>stdo0)                                      //~v6DkI~
        		uerrmsg("%s remove failed.(%s)",0,                 //~v5amR~
						Pfilename,*(stdo-1));	//already exit or path not found//~v5amR~
              else                                                 //~v6DkI~
        		uerrmsg("%s remove failed.(see ::xeftplog)",0,     //~v6DkI~
						Pfilename);	//already exit or path not found//~v6DkI~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            }                                                      //~v61bI~
            rc=ENOENT;                                             //~v56jI~
        	break;                                                 //~v56jI~
        default:                                                   //~v56jI~
            ;                                                      //~v56jI~
        }                                                          //~v56jI~
        ufree(stdo0);                                              //~v56jI~
    }                                                              //~v56jI~
    return rc;                                                     //~v56jI~
}//uftpremove                                                      //~v56jI~
//**************************************************************** //~v56jI~
//urename                                                          //~v56jI~
//*retrn:rc(=errno)                                                //~v56jI~
//**************************************************************** //~v56jI~
int uftprename(PUFTPHOST Ppuftph,int Popt,UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec)//~v5afR~
{                                                                  //~v56jI~
    int rc;                                                        //~v56jI~
    int pathlen1,pathlen2;                                         //~v56jI~
    int renamectr;                                                 //~v56jR~
    UCHAR *pc;                                                     //~v56jR~
    UCHAR realname[FTP_MAXPATH];                                   //~v56jR~
#ifdef W32UNICODE                                                  //~v6uWI~
    UCHAR stripold[FTP_MAXPATH];                                   //~v6uWI~
    UCHAR stripnew[FTP_MAXPATH];                                   //~v6uWI~
#endif                                                             //~v6uWI~
//********************                                             //~v56jI~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270rename(Ppuftph,Popt,Poldname,Pnewname,Pnewspec);//~v5jdI~
#ifdef W32UNICODE                                                  //~v6uWI~
	if (IS_STR_UDSTR(Poldname))                                    //~v6uWI~
    {                                                              //~v6uWI~
		STRIP_UDSTR(Poldname,strlen(Poldname),stripold,NULL/*outlen*/);//~v6uWI~
        Poldname=stripold;                                         //~v6uWI~
    }                                                              //~v6uWI~
	if (IS_STR_UDSTR(Pnewname))                                    //~v6uWI~
    {                                                              //~v6uWI~
		STRIP_UDSTR(Pnewname,strlen(Pnewname),stripnew,NULL/*outlen*/);//~v6uWI~
        Pnewname=stripnew;                                         //~v6uWI~
    }                                                              //~v6uWI~
#endif                                                             //~v6uWI~
	Srenameopt=Popt;                                               //~v56jI~
    pathlen1=FTP_PATHLEN(Poldname);                                //~v56jR~
    pathlen2=FTP_PATHLEN(Pnewname);                                //~v56jR~
    if (pc=WILDCARD(Poldname),pc)   //wild char pos                //~v56jI~
    {                                                              //~v56jI~
//      if (pathlen1 && (ULONG)pc-(ULONG)Poldname<(ULONG)pathlen1) //~v56jI~//~v6hhR~
        if (pathlen1 && (ULPTR)pc-(ULPTR)Poldname<(ULPTR)pathlen1) //~v6hhI~
            return ufilewildpatherr(-1);                           //~v56jI~
        rc=uftpwildfunc(Ppuftph,Poldname,FILE_ALL,uftpwildrename,Pnewname,&renamectr);//~v5afR~
        if (rc)                                                    //~v56jI~
            return rc;                                             //~v56jI~
        uerrmsg("%d object renamed",                               //~v56jI~
                "%d åèâ¸ñº",                                       //~v56jI~
                renamectr);                                        //~v56jI~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61bI~
        return 0;                                                  //~v56jI~
    }                                                              //~v56jI~
    if (WILDCARD(Pnewname))                                        //~v56jI~
    {                                                              //~v56jI~
        memcpy(realname,Pnewname,(UINT)pathlen2);                  //~v56jI~
        udoseditname(DEN_UNIX | DEN_CASE,                          //~v56jR~
					Poldname+pathlen1,Pnewname+pathlen2,realname+pathlen2);//~v56jI~
        if (Pnewspec)   //no output  parm                          //~v56jI~
            strcpy(Pnewspec,realname);                             //~v56jI~
        Pnewname=realname;                                         //~v56jI~
        if (WILDCARD(Pnewname))     //path has wild card           //~v56jI~
            return ufilewildpatherr(-1);                           //~v56jI~
    }                                                              //~v56jI~
    else                                                           //~v56jI~
        if (Pnewspec)   //no output  parm                          //~v56jI~
            *Pnewspec=0;        //return id of no wild card        //~v56jI~
//rename succes evenif newname exist;                              //~v56jI~
	if (!Popt)		//not override existing option                 //~v56jR~
    {                                                              //~v56jI~
        if (uftpisexist(Ppuftph,Pnewname))    //exist chk          //~v5afR~
            return ufileexist(Pnewname,EEXIST);                    //~v56jR~
    }                                                              //~v56jI~
    return uftprenamesub(Ppuftph,Poldname,Pnewname);               //~v5afR~
}//uftprename                                                      //~v56jI~
//**************************************************************** //~v56jI~
//uftprenamesub                                                    //~v56jI~
//*retrn:rc(=errno)                                                //~v56jI~
//**************************************************************** //~v56jI~
int uftprenamesub(PUFTPHOST Ppuftph,UCHAR *Poldname,UCHAR *Pnewname)//~v5afR~
{                                                                  //~v56jI~
//  UCHAR ftpcmd[FTP_MAXPATH];                                     //~v5fnR~
    UCHAR ftpcmd[FTP_MAXPATH+FTP_MAXPATH+32];                      //~v5fnI~
    char **stdo,**stdo0,*poldname,*pnewname;                       //~v5ahR~
    int stdoctr,rc;                                                //~v56jI~
//*********************************                                //~v56jI~
    poldname=Poldname+Ppuftph->UFTPHhostnmlen+1;                   //~v5afR~
//  pnewname=Pnewname+PATHLEN(Pnewname);                           //~v5bgR~
    pnewname=Pnewname+Ppuftph->UFTPHhostnmlen+1;                   //~v5bgI~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftph))                                     //~v6daI~
    {                                                              //~v6daI~
  		return jnismb_rename(0,Ppuftph,poldname,pnewname);         //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
  if (UFTPH_ISSMB(Ppuftph))                                        //~v6d1I~
  	uftp3smb_setcmd(UFTPSMBCMD_RENAME|F3SMBO_NFMSG,Ppuftph,ftpcmd,poldname,pnewname,0/*intparm1*/,0/*intpam2*/);//~v6d1R~
  else                                                             //~v6d1I~
    sprintf(ftpcmd,                                                //~v56jI~
            "rename \"%s\" \"%s\"\n",   //rename success even if already existing target//~v5bfR~
             poldname,pnewname);                                   //~v5ahR~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    if (!rc)                                                       //~v56jI~
    {                                                              //~v56jI~
        stdo=stdo0;                                                //~v56jI~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
		rc=uftp3smb_respchk(UFTPSMBCMD_RENAME,Ppuftph,poldname,&stdo,&stdoctr,ENOENT);//~v6d1R~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkCHNG(0,Ppuftph,"rename",poldname,&stdo,&stdoctr,1);//~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");           //~v56jR~
        switch(rc)                                                 //~v56jI~
        {                                                          //~v56jI~
        case 0:    //250                                           //~v56jI~
        	break;                                                 //~v56jI~
//      case 1:    //350 	//already exist but done               //~v56jR~
        case 1:    //550                                           //~v56jR~
          if (!UFTPH_ISSMB(Ppuftph))                               //~v6d1I~
		    if (!Gufile_nomsg)   //nomsg option                    //~v56jI~
            {                                                      //~v61bI~
              if (stdo>stdo0)                                      //~v6DkI~
        		uerrmsg("rename %s->%s failed .(%s)",0,            //~v56jI~
						Poldname,Pnewname,*(stdo-1));	//already exit or path not found//~v56jI~
              else                                                 //~v6DkI~
        		uerrmsg("rename %s->%s failed .(see ::xeftplog)",0,//~v6DkI~
						Poldname,Pnewname);	//already exit or path not found//~v6DkI~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            }                                                      //~v61bI~
            rc=ENOENT;                                             //~v56jI~
        	break;                                                 //~v56jI~
        default:                                                   //~v56jI~
            ;                                                      //~v56jI~
        }                                                          //~v56jI~
        ufree(stdo0);                                              //~v56jI~
    }                                                              //~v56jI~
    return rc;                                                     //~v56jI~
}//uftprenamesub                                                   //~v56jI~
//**************************************************************** //~v56jI~
//!ufilewildrename                                                 //~v56jI~
//* delete by wild card                                            //~v56jI~
//*parm1:filename thru wildfunc                                    //~v56jI~
//*parm2:dirlist ptr thru wildfunc                                 //~v56jI~
//*parm3:parm thru uwildfunc(Pnewname parm of urename)             //~v56jI~
//*retrn:rc                                                        //~v56jI~
//**************************************************************** //~v56jI~
int uftpwildrename(PUFTPHOST Ppuftph,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,PVOID Pparm)//~v5afR~
{                                                                  //~v56jI~
    return uftprename(Ppuftph,Srenameopt,Pfullpath,Pparm,0);//no real name//~v5afR~
}//uftpwildrename                                                  //~v56jR~
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
int uftpattrib(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pattron,ULONG  Pattroff,ULONG  *Poutattr)//~v5afR~
{                                                               //~5903I~
#ifdef ARMXXE                                                      //~v6daM~
    int attr;                                                      //~v6daM~
#endif                                                             //~v6daM~
    ULONG   mode,modeon,modeoff;                                   //~v56jR~
    FILEFINDBUF3 fstat30;                                          //~v56jR~
    int rc;                                                     //~5909R~
//********************                                          //~5903I~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270attrib(Ppuftph,Pfname,Pattron,Pattroff,Poutattr);//~v5jdI~
    if (rc=(int)uftpfstat(Ppuftph,Pfname,&fstat30),rc)             //~v5afR~
    {                                                              //~v381I~
        if (rc==ENOENT||rc==ENOTDIR)                               //~v381I~
            return ufilenotfound(Pfname,rc);                       //~v381I~
        return rc;                                              //~5905I~
    }                                                              //~v381I~
  if (Ppuftph->UFTPHflag & UFTPHFRWIN)                             //~v6d7I~
  {                                                                //~v6d7I~
#ifdef ARMXXE                                                      //~v6daM~
   if (UFTPH_ISSMBJ(Ppuftph))                                      //~v6daR~
   {                                                               //~v6daR~
    if (Pattroff||Pattron)  //not query                            //~v6daI~
    {                                                              //~v6daI~
	 	attr=FILE_GETATTR(fstat30.attrFile);                       //~v6daR~
    	if (Pattroff)                                              //~v6daR~
	        attr&=~Pattroff;                                       //~v6daI~
    	if (Pattron)                                               //~v6daI~
	        attr|=Pattron;                                         //~v6daI~
  		rc=jnismb_setattr(0,Ppuftph,Pfname,attr,Poutattr);         //~v6daR~
    }                                                              //~v6daI~
    else                                                           //~v6daI~
    if (Poutattr)                                                  //~v6daI~
    {                                                              //~v6daI~
        *Poutattr=fstat30.attrFile;                                //~v6daI~
        rc=0;                                                      //~v6daI~
    }                                                              //~v6daI~
    return rc;                                                     //~v6daI~
   }                                                               //~v6daR~
   else                                                            //~v6daI~
   {                                                               //~v6daI~
#endif                                                             //~v6daM~
//	if (rc=uftp3smb_setmod_win(0,Ppuftph,Pfname,fstat30.attrFile,Pattron,Pattroff),rc)          //set//~v6d7I~//~v6D0R~
  	if (rc=(int)uftp3smb_setmod_win(0,Ppuftph,Pfname,fstat30.attrFile,Pattron,Pattroff),rc)          //set//~v6D0I~
    	return rc;                                                 //~v6d7I~
#ifdef ARMXXE                                                      //~v6daM~
   }                                                               //~v6daI~
#endif                                                             //~v6daI~
  }                                                                //~v6d7I~
  else                                                             //~v6d7I~
  {                                                                //~v6d7I~
    mode=FILE_GETMODE(fstat30.attrFile);                           //~v380R~
//printf("curr  mode=%08x(o%o)\n",mode,mode);                      //~0901R~
    modeon=FILE_GETMODE(Pattron);                                  //~v380R~
    modeoff=FILE_GETMODE(Pattroff);                                //~v380R~
    if (modeon || modeoff)                                         //~0827R~
    {                                                           //~5903I~
        mode&=~modeoff;                                            //~0827R~
        mode|=modeon;                                              //~0827R~
//printf("chmod mode=%08x(o%o)\n",mode,mode);                      //~0901R~
        if (rc=uftpsetmod(Ppuftph,Pfname,mode),rc)          //set  //~v5afR~
            return rc;                                             //~v381R~
    }                                                           //~5903I~
  }                                                                //~v6d7I~
    if (Poutattr)                                                  //~v56jI~
    {                                                              //~v56jI~
        if (rc=(int)uftpfstat(Ppuftph,Pfname,&fstat30),rc)//confirm result//~v5amR~
            return rc;                                             //~v56jR~
        *Poutattr=fstat30.attrFile;                                //~v56jR~
    }                                                              //~v56jI~
    return 0;                                                      //~0827R~
}//uftpattrib                                                      //~5903I~//~v6d1R~
//**************************************************************** //~0902I~
//uattrxon                                                         //~0902I~
//* set x bit(USER)                                                //~0902I~
//*parm1:filename                                                  //~0902I~
//*retrn:rc                                                        //~0902I~
//**************************************************************** //~0902I~
int uftpattrxon(PUFTPHOST Ppuftph,UCHAR *Pfname)                   //~v5afR~
{                                                                  //~0902I~
    ULONG   attron;                                    //+v396R~   //~v56jR~
//********************                                             //~0902I~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftph)) //target is jcifs(dos attr)         //~v6daR~
    {                                                              //~v6daI~
  		return 4;       	//cannnot set dos attr for executable  //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
    attron=FILE_SETMODEATTR(S_IXUSR,0);                            //~v396R~
    return uftpattrib(Ppuftph,Pfname,attron,0,0);                  //~v5afR~
}//uftpattrxon                                                     //~v56jR~
//**************************************************************** //~0902I~
//uattrxchk                                                        //~0902I~
//* chk x bit(USER)                                                //~0902I~
//*parm1:filename                                                  //~0902I~
//*parm2:opt to issue errmsg                                       //~0902I~
//*retrn:rc:0 not executable,1:executable                          //~0902I~
//**************************************************************** //~0902I~
int uftpattrxchk(PUFTPHOST Ppuftph,UCHAR *Pfname,int Popt)         //~v5afR~
{                                                                  //~0902I~
    FILEFINDBUF3 fstat30;                                          //~0902I~
    ULONG mode;                                                    //~v56jR~
    char *uname;                                                   //~v5afI~
    int rc;                                                        //~0902I~
//********************                                             //~0902I~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270attrxchk(Ppuftph,Pfname,Popt);                 //~v5jdI~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftph)) //target is jcifs(dos attr)         //~v6daR~
    {                                                              //~v6daI~
  		return 0;       	//remote execution is not supported    //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
    if (rc=(int)uftpfstat(Ppuftph,Pfname,&fstat30),rc)             //~v5afR~
        return rc;                                                 //~0902I~
    mode=FILE_GETMODE(fstat30.attrFile);                           //~0902R~
    uname=Ppuftph->UFTPHuser;                                      //~v5afR~
    if (!(mode & S_IXOTH)                                          //~0902I~
//  &&   ((gid!=fstat30.gid && uid)||!(mode & S_IXGRP))            //~v56jR~
    &&   ((strcmp(uname,fstat30.uname) && strcmp(uname,FTP_ROOTUSER))||!(mode & S_IXUSR)))//~v56jR~
    {                                                              //~0902I~
        if (Popt & UFTPAXC_MSG)                                    //~v56jR~
        {                                                          //~v61bI~
            uerrmsg("%s has no x-permissin",                       //~0902I~
                    "%s Ç…ÇÕé¿çså†å¿Ç™Ç†ÇËÇ‹ÇπÇÒ",                 //~0902I~
                    Pfname);                                       //~0902I~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
        }                                                          //~v61bI~
        return 0;                                                  //~0902I~
    }                                                              //~0902I~
    return 1;                                                      //~0902I~
}//uftpattrxchk                                                    //~v56jR~
//**************************************************************** //~v56jI~
//uftpgetftime                                                     //~v56jR~
//* get file time stamp                                            //~v56jI~
//* (W)modtime fail  for dir(not plain file),fmt IS GMT but not JST//~v56jR~
//*retrn:rc                                                        //~v56jI~
//**************************************************************** //~v56jI~
int uftpgetftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime)//~v5afR~
{                                                                  //~v56jI~
    int  rc;                                                       //~v56jI~
    FILEFINDBUF3 ffb3;                                             //~v56jI~
//********************                                             //~v56jI~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270getftime(Ppuftph,Pfname,Ppdate,Pptime);        //~v5jdR~
//  rc=ufstat(Pfname,&ffb3);                                       //~v56jR~//~v6D0R~
    rc=(int)ufstat(Pfname,&ffb3);                                  //~v6D0I~
    if(rc==ENOENT || rc==ENOTDIR) //not found or no more file      //~v56jI~
        return ufilenotfound(Pfname,rc);                           //~v56jI~
    *Ppdate=ffb3.fdateLastWrite;                                   //~v56jI~
    *Pptime=ffb3.ftimeLastWrite;                                   //~v56jI~
    return rc;                                                     //~v56jI~
}//uftpgetftime                                                    //~v56jR~
//**************************************************************** //~v6htI~
//uftpgetftime                                                     //~v6htI~
//* get file time stamp                                            //~v6htI~
//* (W)modtime fail  for dir(not plain file),fmt IS GMT but not JST//~v6htI~
//*retrn:rc                                                        //~v6htI~
//**************************************************************** //~v6htI~
int uftpgetftime_1sec(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE *Ppdate,FTIME *Pptime,int *Ppoddsec)//~v6htR~
{                                                                  //~v6htI~
    int  rc;                                                       //~v6htI~
    FILEFINDBUF3 ffb3;                                             //~v6htI~
//********************                                             //~v6htI~
	*Ppoddsec=0;                                                   //~v6htI~
    if (UFTPHISTSO(Ppuftph))                                       //~v6htI~
		return u3270getftime(Ppuftph,Pfname,Ppdate,Pptime);        //~v6htR~
//  rc=ufstat(Pfname,&ffb3);                                       //~v6htI~//~v6D0R~
    rc=(int)ufstat(Pfname,&ffb3);                                  //~v6D0I~
    if(rc==ENOENT || rc==ENOTDIR) //not found or no more file      //~v6htI~
        return ufilenotfound(Pfname,rc);                           //~v6htI~
    *Ppdate=ffb3.fdateLastWrite;                                   //~v6htI~
    *Pptime=ffb3.ftimeLastWrite;                                   //~v6htI~
#ifdef UNX                                                         //~v6htI~
    *Ppoddsec=ffb3.mtime & 1;                                      //~v6htI~
#else                                                              //~v6htI~
    *Ppoddsec=0;                                                   //~v6htI~
#endif                                                             //~v6htI~
    return rc;                                                     //~v6htI~
}//uftpgetftime_1sec                                               //~v6htR~
//****************************************************************//~5910I~
//uftpsetftime                                                     //~v56jR~
//* no method to set time                                          //~v56jI~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int uftpsetftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE Pdate,FTIME Ptime)//~v5afR~
{                                                               //~5910I~
//********************                                          //~5910I~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270setftime(Ppuftph,Pfname,Pdate,Ptime);          //~v5jdI~
	return uftpnotsupported("setftime",Pfname);                    //~v56jR~
}//uftpsetftime                                                    //~v56jR~
//**************************************************************** //~v365I~
//usetftime2                                                       //~v365I~
//* no method to set time                                          //~v56jI~
//* set file time stamp; unit=second                               //~v365I~
//**************************************************************** //~v365I~
int uftpsetftime2(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Patime,ULONG Pmtime)//~v5afR~
{                                                                  //~v365I~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270setftime2(Ppuftph,Pfname,Patime,Pmtime);       //~v5jdR~
	return uftpnotsupported("setftime2",Pfname);                   //~v56jR~
}//uftpsetftime2                                                   //~v56jR~
//****************************************************************//~5910I~
//uftpcopypathinfo                                                 //~v56jR~
//  called when one of sorce and target is remote                  //~v56jI~
//* local<-->remote,remote<-->remote                               //~v56jR~
//* no method to set time                                          //~v56jI~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
#ifdef W32                                                         //~v56jI~
int uftpcopypathinfo(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget)//~v5afR~
{                                                                  //~v56jI~
    FILEFINDBUF3 ffb3;                                             //~v56jI~
    int rc=0,remoteswt,remotesws;                                  //~v56jI~
//********************                                             //~v56jI~
    if (UFTPHISTSO(Ppuftphs)||UFTPHISTSO(Ppuftpht))                //~v5jdR~
		return u3270copypathinfo(Ppuftphs,Ppuftpht,Psource,Ptarget);//~v5jdI~
	remotesws=(Ppuftphs!=0);                                       //~v5ahR~
	remoteswt=(Ppuftpht!=0);                                       //~v5afR~
    if (!remotesws||!remoteswt) 	//not bote is remote           //~v56jR~
    {//set time only                                               //~v56jI~
    	if (!remoteswt)		//remote-->local                       //~v56jI~
        {                                                          //~v56jI~
    		if (rc=ufstat(Psource,&ffb3),rc)                       //~v56jI~
        		return rc;                                         //~v56jI~
			rc=usetftime(Ptarget,ffb3.fdateLastWrite,ffb3.ftimeLastWrite);//~v56jR~
        }                                                          //~v56jI~
    }                                                              //~v56jI~
    else                                                           //~v56jI~
    {                                                              //~v56jI~
    	if (rc=ufstat(Psource,&ffb3),rc)                           //~v56jI~
        	return rc;                                             //~v56jI~
//  	if (rc=usetftime2(Ptarget,ffb3.atime,ffb3.mtime),rc)//no ftp method to set time//~v56jI~
//      	return rc;                                             //~v56jI~
    	rc+=uftpsetmod(Ppuftpht,Ptarget,FILE_GETMODE(ffb3.attrFile)); //all off then set on//~v5ahR~
    }//both remote                                                 //~v56jI~
    return rc;                                                     //~v56jI~
}//uftpcopypathinfo                                                //~v56jI~
#else                                                              //~v56jI~
int uftpcopypathinfo(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget)//~v5afR~
{                                                               //~5910I~
    FILEFINDBUF3 ffb3;                                             //~v365I~
    int rc;                                                        //~v365R~
//********************                                          //~5910I~
#ifdef ARMXXE                                                      //~v6daI~
  	if (UFTPH_ISSMBJ(Ppuftpht)) //target is jcifs(dos attr)        //~v6daR~
    {                                                              //~v6daI~
  		return 0;                                                  //~v6daI~
    }                                                              //~v6daI~
#endif                                                             //~v6daI~
    if (UFTPHISTSO(Ppuftphs))                                      //~v5jdR~
		return u3270copypathinfo(Ppuftphs,Ppuftpht,Psource,Ptarget);//~v5jdI~
//  if (rc=ufstat(Psource,&ffb3),rc)                               //~v56jR~//~v6D0R~
    if (rc=(int)ufstat(Psource,&ffb3),rc)                          //~v6D0I~
        return rc;                                                 //~v365I~
//  if (rc=usetftime2(Ptarget,ffb3.atime,ffb3.mtime),rc)           //~v56jR~
//      return rc;                                                 //~v56jR~
//  rc+=ufilesetmod(Ptarget,FILE_GETMODE(ffb3.attrFile)); //all off then set on//~v56jR~//~v6D1R~
    rc+=ufilesetmod(Ptarget,(mode_t)FILE_GETMODE(ffb3.attrFile)); //all off then set on//~v6D1I~
    return rc;                                                     //~v365R~
}//uftpcopypathinfo                                                //~v56jR~
#endif //UNX                                                       //~v56jI~
//**************************************************************** //~v365I~
//uftpsetown                                                       //~v56jR~
//* set uid/gid                                                    //~v365I~
//*parm1:target name                                               //~v365I~
//*parm2:uid                                                       //~v365I~
//*parm3:gid                                                       //~v365I~
//*retrn:rc                                                        //~v365I~
//**************************************************************** //~v365I~
int uftpsetown(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Puid,ULONG Pgid)//~v5afR~
{                                                                  //~v365I~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270setown(Ppuftph,Pfname,Puid,Pgid);              //~v5jdI~
	return uftpnotsupported("chown",Pfname);                       //~v56jR~
}//uftpsetown                                                      //~v56jR~
//**************************************************************** //~v365I~
//ufilesetmod                                                      //~v365I~
//* set modifier                                                   //~v381R~
//*parm1:target name                                               //~v365I~
//*parm2:mode  or attr fpr MDOS file                               //~v519R~
//*retrn:rc                                                        //~v365I~
//**************************************************************** //~v365I~
int uftpsetmod(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pmode)        //~v5afR~
{                                                                  //~v365I~
    UCHAR ftpcmd[FTP_MAXPATH];                                     //~v56jI~
    UCHAR rshcmd[FTP_MAXPATH];                                     //~v5evI~
    char **stdo,**stdo0,*pfname;                                   //~v56jR~
    int stdoctr,rc;                                                //~v56jR~
    int rc2;                                                       //~v5evI~
    ULONG mode;                                                    //~v56jI~
//********************                                             //~v56jI~
    if (UFTPHISTSO(Ppuftph))                                       //~v5jdI~
		return u3270setmod(Ppuftph,Pfname,Pmode);                  //~v5jdI~
    mode=Pmode & FTP_CHMODMASK;                                    //~v56jI~
    pfname=Pfname+Ppuftph->UFTPHhostnmlen+1;                       //~v5afR~
  if (UFTPH_ISSMB(Ppuftph))                                        //~v6d1I~
  {                                                                //~v6d1I~
//	rc=uftp3smb_setcmd(UFTPSMBCMD_CHMOD|F3SMBO_NFMSG,Ppuftph,ftpcmd,pfname,0/*chparm2*/,mode,0/*intpam2*/);//~v6d1R~//~v6D0R~
  	rc=uftp3smb_setcmd(UFTPSMBCMD_CHMOD|F3SMBO_NFMSG,Ppuftph,ftpcmd,pfname,0/*chparm2*/,(int)mode,0/*intpam2*/);//~v6D0R~
    if (rc)                                                        //~v6d1I~
    	return rc;                                                 //~v6d1I~
  }                                                                //~v6d1I~
  else                                                             //~v6d1I~
  if (UFTPHISPSFTP(Ppuftph))                                       //~v61pI~
    sprintf(ftpcmd,                                                //~v61pI~
            "chmod %o \"%s\"\n",                                   //~v61pI~
             (int)mode,pfname);                                    //~v61pI~
  else                                                             //~v61pI~
    sprintf(ftpcmd,                                                //~v56jI~
            "site chmod %o \"%s\"\n",                              //~v5bfR~
             (int)mode,pfname);                                    //~v56jR~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);	//get stdout/stderr//~v5afR~
    stdo=stdo0;                                                    //~v56jI~
    if (!rc)                                                       //~v56jI~
    {                                                              //~v56jI~
	  if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
		rc=uftp3smb_respchk(UFTPSMBCMD_CHMOD,Ppuftph,pfname,&stdo,&stdoctr,ENOENT);//~v6d1R~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkCHNG(UFTP3SRCC_CHMOD|UFTP3SRCC_ERRMSG,Ppuftph,"chmod",pfname,&stdo,&stdoctr,ENOENT);//~v61pR~
      else                                                         //~v61pI~
		rc=uftpsimplerespchk("chmod","200 550 ",Pfname,&stdo,&stdoctr,ENOENT);//~v56jI~
      if (!UFTPH_ISSMB(Ppuftph))                                   //~v6d1I~
        if (rc==-1) //no 200,550 found                             //~v56jR~
        {                                                          //~v61bI~
            uerrmsg("\"site chmod %o %s\" failed",0,               //~v56jI~
				        mode,pfname);                              //~v56jI~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
        }                                                          //~v61bI~
	    ufree(stdo0);                                              //~v56jI~
	 if (!UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
      if (!UFTPHISPSFTP(Ppuftph))                                  //~v61pI~
      {                                                            //~v61pI~
    	sprintf(rshcmd,                                            //~v5evI~
            "chmod %o \\\"%s\\\"",                                 //~v5evR~
             (int)mode,pfname);                                    //~v5evI~
		rc2=uproc_rsh(UPROC_PUFTPH|UPROC_RSHLOG,Ppuftph,0,rshcmd,0,0,0,0,0,0);	//no userid,no redirect//~v5evR~
        if (!rc2)                                                  //~v5evI~
        	rc=0;                                                  //~v5evI~
      }                                                            //~v61pI~
    }                                                              //~v56jI~
    return rc;                                                     //~v56jI~
}//uftpsetmod                                                      //~v56jR~
//**************************************************************** //~v56jI~
//uftpwildfunc                                                     //~v56jI~
//* apply function for wild card  rename                           //~v56jI~//~v6daR~
//*parm1:option for apply to ea data(1:apply)                      //~v56jI~
//*parm2:wild card filename                                        //~v56jI~
//*parm3:file selection attribute mask                             //~v56jI~
//*parm4:apply function(int func(char *filename,void *parm))       //~v56jI~
//*parm5:apply function parm                                       //~v56jI~
//*parm5:output applied count                                      //~v56jI~
//*retrn:rc                                                        //~v56jI~
//**************************************************************** //~v56jI~
int uftpwildfunc(PUFTPHOST Ppuftph,UCHAR *Psource,unsigned Pattrmask,//~v5afR~
                FTP_WILDAPPLYFUNC *Pfunc,void *Pparm,int *Pfilectr)//~v56jR~
{                                                                  //~v56jI~
    int rc=0,filectr,ii,pathlen;                                   //~v56jI~
    PUDIRLIST pudirlist,pudirlist0;                                //~v56jI~
    UCHAR fpath[FTP_MAXPATH];                                      //~v56jR~
//********************                                             //~v56jI~
    if (!uftpfullpath(Ppuftph,fpath,Psource,FTP_MAXPATH))          //~v5afR~
        return 4;                                                  //~v56jI~
    filectr=udirlist(fpath,Pattrmask,&pudirlist0,'L');             //~v56jR~
    if (filectr<0)  //err                                          //~v56jI~
        return 4;                                                  //~v56jI~
    pathlen=FTP_PATHLEN(fpath);                                    //~v56jR~
    pudirlist=pudirlist0;                                          //~v56jI~
    *Pfilectr=0;                                                   //~v56jI~
    for (ii=0;ii<filectr;ii++,pudirlist++)  //until eof/err        //~v56jI~
    {                                                              //~v56jI~
        if (!strcmp(pudirlist->name,".")        //curr             //~v56jI~
        ||  !strcmp(pudirlist->name,".."))      //parent           //~v56jI~
            continue;                                              //~v56jI~
        *Pfilectr=*Pfilectr+1;                                     //~v56jI~
        strcpy(fpath+pathlen,pudirlist->name);                     //~v56jR~
        if (rc=Pfunc(Ppuftph,fpath,pudirlist,Pparm),rc)            //~v5afR~
            break;                                                 //~v56jI~
    }//dir list                                                    //~v56jI~
//  ufree(pudirlist0);                                             //~v56jI~//~v6qaR~
    UDIRLIST_FREE(pudirlist0);                                     //~v6qaI~
    return rc;                                                     //~v56jI~
}//uftpwildfunc                                                    //~v5amR~
//**************************************************************** //~v5amI~
//uwildfunc2     for delete                                        //~v5amI~//~v6daR~
//* apply function for wild card for remote file                   //~v5amI~
//*retrn:rc                                                        //~v5amI~
//**************************************************************** //~v5amI~
int uftpwildfunc2(int Popt,UCHAR *Psource,unsigned Pattrmask,      //~v5amR~
//              FTPCMD_CALLBACK *Pfunc,void *Pparm,int *Ppfilectr,long *Ppfilesize)//~v5k0R~
                FTPCMD_CALLBACK *Pfunc,void *Pparm,int *Ppfilectr,FILESZT *Ppfilesize)//~v5k0I~
{                                                                  //~v5amI~
    int rc=0,filectr,stdoctr;                                      //~v5amR~
    PUDIRLIST pudirlist;                                           //~v5amI~
    PUFTPHOST puftph;                                              //~v5amI~
//  UCHAR fpath[_MAX_PATH];                                        //~v5amR~//~v6H7R~
    UCHAR fpath[FTP_MAXPATH];                                      //~v6H7I~
    UFWF2PARM wf2p;                                                //~v5amI~
    char **pstdo;                                                  //~v5amI~
//********************                                             //~v5amI~
	*Ppfilectr=0;                                                  //~v5amI~
	*Ppfilesize=0;                                                 //~v5amI~
    if (Popt & UXDELRONLYCHK)  //readonly chk only                 //~v5amR~
    	return 0;	//bypass process                               //~v5amI~
    wf2p.UFWF2Pcmdokctr=0;	//processed ctr                        //~v5amR~
    wf2p.UFWF2Pfilesize=0;	//deleted size                         //~v5amR~
    if (!uftpisremote(Psource,&puftph))	//local file               //~v5amR~
    	return 4;                                                  //~v5amI~
//  if (!uftpfullpath(puftph,fpath,Psource,_MAX_PATH))             //~v5amR~//~v6H7R~
    if (!uftpfullpath(puftph,fpath,Psource,sizeof(fpath)))         //~v6H7R~
        return 4;                                                  //~v5amI~
    if (uftpdirlistsub(puftph,FTP_DLSNONFMSG,&filectr,fpath,Pattrmask,&pudirlist))//~v5amR~
        return 4;                                                  //~v5amI~
    if (filectr)                                                   //~v5amI~
    {                                                              //~v5amI~
    	wf2p.UFWF2Pfpath=fpath+puftph->UFTPHhostnmlen+1;           //~v5amR~
    	wf2p.UFWF2Ppathlen=PATHLEN(wf2p.UFWF2Pfpath);              //~v5amR~
    	wf2p.UFWF2Ppudl=pudirlist;                                 //~v5amI~
    	wf2p.UFWF2Ppudlctr=filectr;                                //~v5amI~
    	wf2p.UFWF2Pwildparm=Pparm;                                 //~v5amR~
    	wf2p.UFWF2Pattrmask=Pattrmask;                             //~v5amR~
    	wf2p.UFWF2Popt=Popt;                                       //~v5amR~
    	wf2p.UFWF2Ppuftph=puftph;                                  //~v6d1I~
#ifdef ARMXXE                                                      //~v6daI~
      if (UFTPH_ISSMBJ(puftph))                                    //~v6daR~
      {                                                            //~v6daI~
        rc=uftpsmbj_wildfunc2(Popt,puftph,Pfunc,&wf2p);            //~v6daR~
        if (rc==FTPRC_NOMOREFILE)   //request skip ftp cmd         //~v6daI~
            rc=0;                                                  //~v6daI~
      }                                                            //~v6daI~
      else                                                         //~v6daI~
      {                                                            //~v6daI~
#endif                                                             //~v6daI~
//    	if (uftpcmd(puftph,0,0,&pstdo,&stdoctr,Pfunc,&wf2p))//callback Pfunc//~v5d7R~
    	rc=uftpcmd(puftph,0,0,&pstdo,&stdoctr,Pfunc,&wf2p);//callback Pfunc//~v5d7I~
      	if (rc)                                                    //~v5d7I~
        {                                                          //~v5d7I~
	    	if (rc==FTPRC_NOMOREFILE)	//request skip ftp cmd     //~v5d7I~
                rc=0;                                              //~v5d7I~
        }                                                          //~v5d7I~
        else                                                       //~v5amI~
//      	if (uftpxdelrchk(&wf2p,pstdo,stdoctr))//stdo is freed in the func//~v61pR~
        	if (uftpxdelrchk(0,puftph,&wf2p,pstdo,stdoctr))//stdo is freed in the func//~v61pI~
            	rc=4;                                              //~v5amI~
#ifdef ARMXXE                                                      //~v6daI~
      }                                                            //~v6daI~
#endif                                                             //~v6daI~
        if (Pattrmask & FILE_DIRECTORY)                            //~v6djI~
//      	uftpdelsubdir(Popt,&wf2p,Pparm,Ppfilectr,Ppfilesize);  //~v6djR~
      	uftpdelsubdir(Popt,&wf2p);                                 //~v6djI~
    }                                                              //~v5amI~
	if (pudirlist)                                                 //~v5amI~
//  	ufree(pudirlist);                                          //~v5amI~//~v6qaR~
    	UDIRLIST_FREE(pudirlist);                                  //~v6qaI~
    *Ppfilectr=wf2p.UFWF2Pcmdokctr;	//processed ctr                //~v5amR~
    *Ppfilesize=wf2p.UFWF2Pfilesize;	//deleted size             //~v5amR~
    return rc;                                                     //~v5amI~
}//uftpwildfunc2                                                   //~v5amR~
//**************************************************************** //~v5fdI~
//uftpmultidel                                                     //~v5fdI~
//* delete at once multiple file in the remote dir                 //~v5fdI~
//* parm3:dirname with hostname prefix                             //~v5fdI~
//*retrn:rc                                                        //~v5fdI~
//**************************************************************** //~v5fdI~
int uftpmultidel(int Popt,PUFTPHOST Ppuftph,PUFTPMULTIDEL Ppfmd,   //~v5fdR~
                 int Pfilectr,void *Pparm)                         //~v5fdR~
{                                                                  //~v5fdI~
    int rc=0,stdoctr;                                              //~v5fdR~
    UFWF2PARM wf2p;                                                //~v5fdI~
    char **pstdo;                                                  //~v5fdI~
//********************                                             //~v5fdI~
    wf2p.UFWF2Pcmdokctr=0;	//processed ctr                        //~v5fdI~
    wf2p.UFWF2Pfilesize=0;	//deleted size                         //~v5fdI~
    wf2p.UFWF2Pfpath=UFWF2PFPATH_MULTIDEL;	//id of multidel       //~v5fdR~
    wf2p.UFWF2Ppathlen=0;                                          //~v5fdR~
//  wf2p.UFWF2Ppudl=(PUDIRLIST)(ULONG)Ppfmd;                       //~v5fdR~//~v6hhR~
    wf2p.UFWF2Ppudl=(PUDIRLIST)(ULPTR)Ppfmd;                       //~v6hhI~
    wf2p.UFWF2Ppudlctr=Pfilectr;                                   //~v5fdI~
    wf2p.UFWF2Pwildparm=Pparm;                                     //~v5fdI~
    wf2p.UFWF2Pattrmask=0;	//no meaningfull                       //~v5fdI~
    wf2p.UFWF2Popt=Popt;                                           //~v5fdI~
    wf2p.UFWF2Ppuftph=Ppuftph;                                     //~v6d1R~
#ifdef ARMXXE                                                      //~v6daI~
  if (UFTPH_ISSMBJ(Ppuftph))                                       //~v6daR~
  {                                                                //~v6daI~
    rc=uftpsmbj_multidel(Popt,Ppuftph,&wf2p);                      //~v6daI~
  }                                                                //~v6daI~
  else                                                             //~v6daI~
  {                                                                //~v6daI~
#endif                                                             //~v6daI~
    rc=uftpcmd(Ppuftph,0,0,&pstdo,&stdoctr,uftpmultidelsub,&wf2p);//callback Pfunc//~v5fdR~
    if (rc)                                                        //~v5fdI~
    {                                                              //~v5fdI~
        if (rc==FTPRC_NOMOREFILE)   //request skip ftp cmd         //~v5fdI~
            rc=0;                                                  //~v5fdI~
    }                                                              //~v5fdI~
    else                                                           //~v5fdI~
//      if (uftpmultidelrchk(&wf2p,pstdo,stdoctr))//stdo is freed in the func//~v61pR~
        if (uftpmultidelrchk(0,Ppuftph,&wf2p,pstdo,stdoctr))//stdo is freed in the func//~v61pI~
            rc=4;                                                  //~v5fdI~
#ifdef ARMXXE                                                      //~v6daI~
  }                                                                //~v6daI~
#endif                                                             //~v6daI~
    return rc;                                                     //~v5fdI~
}//uftpmultidel                                                    //~v5fdR~
//**************************************************************** //~v5fnI~
//uftpmultirename                                                  //~v5fnI~
//* rename at once multiple file in the remote dir                 //~v5fnI~
//* parm3:dirname with hostname prefix                             //~v5fnI~
//*retrn:rc                                                        //~v5fnI~
//**************************************************************** //~v5fnI~
int uftpmultirename(int Popt,PUFTPHOST Ppuftph,PUFTPMULTIRENAME Ppfmr,//~v5fnI~
                 int Pfilectr,void *Pparm)                         //~v5fnI~
{                                                                  //~v5fnI~
    int rc=0,stdoctr;                                              //~v5fnI~
    UFWF2PARM wf2p;                                                //~v5fnI~
    char **pstdo;                                                  //~v5fnI~
//********************                                             //~v5fnI~
    wf2p.UFWF2Pcmdokctr=0;	//processed ctr                        //~v5fnI~
    wf2p.UFWF2Pfilesize=0;	//deleted size                         //~v5fnI~
    wf2p.UFWF2Pfpath=UFWF2PFPATH_MULTIDEL;	//id of multidel       //~v5fnR~
    wf2p.UFWF2Ppathlen=0;                                          //~v5fnI~
//  wf2p.UFWF2Ppudl=(PUDIRLIST)(ULONG)Ppfmr;                       //~v5fnI~//~v6hhR~
    wf2p.UFWF2Ppudl=(PUDIRLIST)(ULPTR)Ppfmr;                       //~v6hhI~
    wf2p.UFWF2Ppudlctr=Pfilectr;                                   //~v5fnI~
    wf2p.UFWF2Pwildparm=Pparm;                                     //~v5fnI~
    wf2p.UFWF2Pattrmask=0;	//no meaningfull                       //~v5fnI~
    wf2p.UFWF2Popt=Popt;                                           //~v5fnI~
    wf2p.UFWF2Ppuftph=Ppuftph;                                     //~v6d1I~
#ifdef ARMXXE                                                      //~v6daI~
  if (UFTPH_ISSMBJ(Ppuftph))                                       //~v6daI~
  {                                                                //~v6daI~
    rc=uftpsmbj_multirename(Popt,Ppuftph,&wf2p);                   //~v6daI~
  }                                                                //~v6daI~
  else                                                             //~v6daI~
  {                                                                //~v6daI~
#endif                                                             //~v6daI~
    rc=uftpcmd(Ppuftph,0,0,&pstdo,&stdoctr,uftpmultirenamesub,&wf2p);//callback Pfunc//~v5fnI~
    if (rc)                                                        //~v5fnI~
    {                                                              //~v5fnI~
        if (rc==FTPRC_NOMOREFILE)   //request skip ftp cmd         //~v5fnI~
            rc=0;                                                  //~v5fnI~
    }                                                              //~v5fnI~
    else                                                           //~v5fnI~
//      if (uftpmultirenamerchk(&wf2p,pstdo,stdoctr))//stdo is freed in the func//~v61pR~
        if (uftpmultirenamerchk(0,Ppuftph,&wf2p,pstdo,stdoctr))//stdo is freed in the func//~v61pI~
            rc=4;                                                  //~v5fnI~
#ifdef ARMXXE                                                      //~v6daI~
  }                                                                //~v6daI~
#endif                                                             //~v6daI~
    return rc;                                                     //~v5fnI~
}//uftpmultirename                                                 //~v5fnI~
//**************************************************************** //~v5amI~
//!uftpwildxdel(uftpcmd callback)                                  //~v5amR~
//* delete by wild card                                            //~v5amI~
//*parm1:filename thru wildfunc                                    //~v5amI~
//*parm2:dirlist ptr thru wildfunc                                 //~v5amI~
//*parm3:parm thru uwildfunc(Pattrmask parm of xdelete)            //~v5amI~
//*retrn:rc                                                        //~v5amI~
//**************************************************************** //~v5amI~
int uftpwildxdel(FILE *Phfile,void *Ppvoid)                        //~v5amI~
{                                                                  //~v5amI~
    PUFWF2PARM pwf2p;                                              //~v5amI~
	PUDIRLIST pudirlist;                                           //~v5amI~
    int rc=0,pudlctr,ii,filectr=0,pathlen;                         //~v5amI~
//  long filesize=0;                                               //~v5k0R~
//  char fpath[_MAX_PATH];                                         //~v5amI~//~v6H7R~
    char fpath[FTP_MAXPATH2];                                      //~v6H7I~
    PUFTPHOST puftph;                                              //~v6d1I~
//***********************************                              //~v5amI~
	pwf2p=(PUFWF2PARM)Ppvoid;                                      //~v5amI~
    pudirlist=pwf2p->UFWF2Ppudl;                                   //~v5amR~
    pudlctr=pwf2p->UFWF2Ppudlctr;                                  //~v5amR~
    pathlen=pwf2p->UFWF2Ppathlen;                                  //~v5amI~
    puftph=pwf2p->UFWF2Ppuftph;                                    //~v6d1I~
#ifdef ARMXXE                                                      //~v6daM~
  	if (UFTPH_ISSMBJ(puftph))                                      //~v6daI~
  	{                                                              //~v6daM~
    	return uftpsmbj_wildxdel(0,pwf2p);                         //~v6daR~
  	}                                                              //~v6daM~
#endif                                                             //~v6daM~
    memcpy(fpath,pwf2p->UFWF2Pfpath,(UINT)pathlen);                //~v5amR~
    *(fpath+pathlen)=0;                                            //~v6d1I~
    if (UFTPH_ISSMB(puftph))                                       //~v6d1I~
		uftp3smb_putstmt(UFTPSMBCMD_DELETE|F3SMBO_MULTISTART,puftph,Phfile,fpath,0/*chparm2*/);//~v6d1I~
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err        //~v5amI~
    {                                                              //~v5amI~
//  	pudirlist->attr&=~FILE_FTPWKSL;	//id of cmd put for respchk//~v5amI~//~v6D0R~
    	pudirlist->attr&=~(ULONG)FILE_FTPWKSL;	//id of cmd put for respchk//~v6D0I~
#ifdef UTF8SUPPH                                                   //~v5ncI~
      if (!FILE_ISSLINKDIR(pudirlist->attr))                       //~v5ncI~
#endif                                                             //~v5ncI~
    	if (UCBITCHK(pudirlist->attr,(FILE_DIRECTORY|FILE_SPECIAL|FILE_READONLY)))//~v5amR~
        {                                                          //~v6H7I~
            strcpy(fpath+pathlen,pudirlist->name);                 //~v6H7I~
	    	if (pudirlist->attr & FILE_READONLY)                   //~v6H7I~
            {	                                                   //~v6H7I~
            	(*Spdelrctr)++;                                    //~v6H7R~
                ufilereadonly(fpath,0);	                           //~v6H7I~
				uftplog(FTPLOG_ERRM,0/*by ugeterrmsg2()*/);        //~v6H7I~
            }                                                      //~v6H7I~
            else                                                   //~v6H7I~
	    	if (pudirlist->attr & FILE_SPECIAL)                    //~v6H7I~
            {                                                      //~v6H7I~
                ufileerrspecialfile(fpath,0);                      //~v6H7I~
				uftplog(FTPLOG_ERRM,0/*by ugeterrmsg2()*/);        //~v6H7I~
            }                                                      //~v6H7I~
        	continue;                                              //~v5amI~
        }                                                          //~v6H7I~
    	pudirlist->attr|=FILE_FTPWKSL;	//id of cmd put for respchk//~v5amI~
        strcpy(fpath+pathlen,pudirlist->name);                     //~v5amI~
      if (UFTPH_ISSMB(puftph))                                     //~v6d1I~
		uftp3smb_putstmt(UFTPSMBCMD_DELETE,puftph,Phfile,fpath,0/*chparm2*/);//~v6d1I~
      else                                                         //~v6d1I~
    	ufile2putstmt(Phfile,"delete",fpath);                      //~v5amR~
//      filesize+=pudirlist->size;                                 //~v5k0R~
        filectr++;                                                 //~v5amR~
    }//dir list                                                    //~v5amI~
    if (!filectr)                                                  //~v5amI~
//  	rc=ENOENT;	//request skip ftp cmd                         //~v5d7R~
    	rc=FTPRC_NOMOREFILE;	//request skip ftp cmd             //~v5d7I~
    return rc;                                                     //~v5amI~
}//uftpwildxdel                                                    //~v5amI~
//**************************************************************** //~v5fdI~
//!uftpmultidel(uftpcmd callback)                                  //~v5fdI~
//* delete multiple request entry                                  //~v5fdI~
//*retrn:rc                                                        //~v5fdI~
//**************************************************************** //~v5fdI~
int uftpmultidelsub(FILE *Phfile,void *Ppvoid)                     //~v5fdR~
{                                                                  //~v5fdI~
    PUFWF2PARM pwf2p;                                              //~v5fdI~
    int rc=0,reqctr,ii,filectr=0;                                  //~v5fdR~
	PUFTPMULTIDEL pfmd;                                            //~v5fdR~
    PUFTPHOST puftph;                                              //~v6d1I~
//***********************************                              //~v5fdI~
	pwf2p=(PUFWF2PARM)Ppvoid;                                      //~v5fdI~
//  pfmd=(PUFTPMULTIDEL)(ULONG)(pwf2p->UFWF2Ppudl);                //~v5fdR~//~v6hhR~
    pfmd=(PUFTPMULTIDEL)(ULPTR)(pwf2p->UFWF2Ppudl);                //~v6hhI~
    reqctr=pwf2p->UFWF2Ppudlctr;                                   //~v5fdI~
    puftph=pwf2p->UFWF2Ppuftph;                                    //~v6d1I~
    for (ii=0;ii<reqctr;ii++,pfmd++)  //until eof/err              //~v5fdI~
    {                                                              //~v5fdI~
    	pfmd->UFMDflag=0;	//clear ctl                            //~v5fdI~
    	if (UCBITCHK(pfmd->UFMDattr,(FILE_DIRECTORY|FILE_SPECIAL|FILE_READONLY)))//~v5fdR~
        {                                                          //~v5fdI~
            uftpbypassreason(2,pfmd->UFMDpfpath,pfmd->UFMDattr);   //~v5k1I~
    		pfmd->UFMDrc=UFMDRC_TYPEERR;                           //~v5fdI~
        	continue;                                              //~v5fdI~
        }                                                          //~v5fdI~
    	pfmd->UFMDflag|=UFMDFDELREQ;                               //~v5fdR~
    	pfmd->UFMDrc=0;                                            //~v5fdI~
      if (UFTPH_ISSMB(puftph))                                     //~v6d1I~
		uftp3smb_putstmt(UFTPSMBCMD_DELETE|F3SMBO_MULTIENTRY,puftph,Phfile,pfmd->UFMDpfpath,0/*chparm2*/);//~v6d1R~
      else                                                         //~v6d1I~
    	ufile2putstmt(Phfile,"delete",pfmd->UFMDpfpath);           //~v5fdI~
        filectr++;                                                 //~v5fdI~
    }//dir list                                                    //~v5fdI~
    if (!filectr)                                                  //~v5fdI~
    	rc=FTPRC_NOMOREFILE;	//request skip ftp cmd             //~v5fdI~
    return rc;                                                     //~v5fdI~
}//uftpmultidelsub                                                 //~v5fdR~
//**************************************************************** //~v5fnI~
//!uftpmultirename(uftpcmd callback)                               //~v5fnI~
//* rename multiple request entry                                  //~v5fnI~
//*retrn:rc                                                        //~v5fnI~
//**************************************************************** //~v5fnI~
int uftpmultirenamesub(FILE *Phfile,void *Ppvoid)                  //~v5fnI~
{                                                                  //~v5fnI~
    PUFWF2PARM pwf2p;                                              //~v5fnI~
    int rc=0,reqctr,ii,filectr=0;                                  //~v5fnI~
	PUFTPMULTIRENAME pfmr;                                         //~v5fnI~
    UCHAR renameopd[FTP_MAXPATH+FTP_MAXPATH+4];                    //~v5fnI~
    UCHAR newname[FTP_MAXPATH];                                    //~v5fnI~
    PUFTPHOST puftph;                                              //~v6d1I~
//***********************************                              //~v5fnI~
	pwf2p=(PUFWF2PARM)Ppvoid;                                      //~v5fnI~
//  pfmr=(PUFTPMULTIRENAME)(ULONG)(pwf2p->UFWF2Ppudl);             //~v5fnI~//~v6hhR~
    pfmr=(PUFTPMULTIRENAME)(ULPTR)(pwf2p->UFWF2Ppudl);             //~v6hhI~
    reqctr=pwf2p->UFWF2Ppudlctr;                                   //~v5fnI~
    puftph=pwf2p->UFWF2Ppuftph;                                    //~v6d1I~
    for (ii=0;ii<reqctr;ii++,pfmr++)  //until eof/err              //~v5fnI~
    {                                                              //~v5fnI~
    	pfmr->UFMRflag=0;	//clear ctl                            //~v5fnR~
    	if (UCBITCHK(pfmr->UFMRattr,(FILE_DIRECTORY|FILE_SPECIAL|FILE_READONLY)))//~v5fnR~
        {                                                          //~v5fnI~
            uftpbypassreason(3,pfmr->UFMRpfpath,pfmr->UFMRattr);   //~v5k1I~
    		pfmr->UFMRrc=UFMRRC_TYPEERR;                           //~v5fnR~
        	continue;                                              //~v5fnI~
        }                                                          //~v5fnI~
    	pfmr->UFMRflag|=UFMRFRENAMEREQ;                            //~v5fnR~
    	pfmr->UFMRrc=0;                                            //~v5fnR~
    	strcpy(newname,pfmr->UFMRpfpath);                          //~v5fnI~
        strcpy(newname+FTP_PATHLEN(newname),pfmr->UFMRpnewname);   //~v5fnR~
      if (UFTPH_ISSMB(puftph))                                     //~v6d7I~
	  	uftp3smb_putstmt(UFTPSMBCMD_RENAME,puftph,Phfile,pfmr->UFMRpfpath,newname);//~v6d7I~
      else                                                         //~v6d7I~
      {                                                            //~v6d7I~
    	sprintf(renameopd,"\"%s\" \"%s\"",pfmr->UFMRpfpath,newname);//~v5fnR~
    	ufile2putstmt(Phfile,"rename",renameopd);                  //~v5fnI~
      }                                                            //~v6d7I~
        filectr++;                                                 //~v5fnI~
    }//dir list                                                    //~v5fnI~
    if (!filectr)                                                  //~v5fnI~
    	rc=FTPRC_NOMOREFILE;	//request skip ftp cmd             //~v5fnI~
    return rc;                                                     //~v5fnI~
}//uftpmultirenamesub                                              //~v5fnI~
//**************************************************************** //~v5k1I~
//!issue errmsg delete/rename bypassed                             //~v5k1I~
//*retrn:non                                                       //~v5k1I~
//**************************************************************** //~v5k1I~
void uftpbypassreason(int Popt,char *Pfnm,ULONG Pattr)             //~v5k1I~
{                                                                  //~v5k1I~
	if (Pattr & FILE_DIRECTORY)                                    //~v5k1I~
    	uerrmsg("%s is directory",0,	                           //~v5k1I~
        			Pfnm);                                         //~v5k1I~
    else                                                           //~v5k1I~
	if (Pattr & FILE_SPECIAL)                                      //~v5k1I~
    	ufileerrspecialfile(Pfnm,0);                               //~v5k1I~
    else                                                           //~v5k1I~
    	ufilenopermission("Delete/Rename",Pfnm,0);                 //~v5k1I~
	uftplog(FTPLOG_ERRM,0);	//logging errmsg                       //~v61bI~
    return;                                                        //~v5k1I~
}//uftpbypassreason                                                //~v5k1I~
//**************************************************************** //~v5amI~
//ftp delete cmd result chk                                        //~v5amI~
//*retrn:rc                                                        //~v5amI~
//**************************************************************** //~v5amI~
//int uftpxdelrchk(PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)  //~v61pR~
int uftpxdelrchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pI~
{                                                                  //~v5amI~
	PUDIRLIST pudirlist;                                           //~v5amI~
    int rc=0,filectr=0,pudlctr,stdoctr,ii,pathlen,opt;             //~v5amR~
//  char newsrc[_MAX_PATH],**stdo;                                 //~v5amR~//~v6H7R~
    char newsrc[FTP_MAXPATH2],**stdo;                              //~v6H7I~
//  long filesize=0;                                               //~v5k0R~
    FILESZT filesize=0;                                            //~v5k0I~
//****************************                                     //~v5amI~
	stdoctr=Pstdoctr;                                              //~v5amI~
    stdo=Ppstdo;                                                   //~v5amI~
    pudlctr=Ppfwf2p->UFWF2Ppudlctr;                                //~v5amR~
    pudirlist=Ppfwf2p->UFWF2Ppudl;                                 //~v5amI~
    pathlen=Ppfwf2p->UFWF2Ppathlen;                                //~v5amR~
    memcpy(newsrc,Ppfwf2p->UFWF2Pfpath,(UINT)pathlen);             //~v5amI~
    opt=Ppfwf2p->UFWF2Popt;                                        //~v5amR~
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err        //~v5amI~
    {                                                              //~v5amI~
        if (!(pudirlist->attr & FILE_FTPWKSL))                     //~v5amI~
            continue;                                              //~v5amI~
        strcpy(newsrc+pathlen,pudirlist->name);      //parent      //~v5amI~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
      	rc=uftp3smb_respchk(UFTPSMBCMD_DELETE|F3SMBO_MULTIENTRY,Ppuftph,newsrc,&stdo,&stdoctr,1);//~v6d1R~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkOK(0,Ppuftph,"delete","rm",&stdo,&stdoctr,1);//~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");           //~v5amI~
        switch(rc)                                                 //~v5amI~
        {                                                          //~v5amI~
        case 0:    //250                                           //~v5amI~
            filectr++;                                             //~v5amI~
            filesize+=pudirlist->size;                             //~v5amI~
            if (opt & UXDELMSG)                                    //~v5amI~
            	ufiledeleted(newsrc,'F',pudirlist->size,pudirlist->attr);//size=-1  mean no display size/attr//~v5amI~
            break;                                                 //~v5amI~
        case 1:    //550                                           //~v5amI~
          if (!UFTPH_ISSMB(Ppuftph))                               //~v6d1I~
            if (!Gufile_nomsg)   //nomsg option                    //~v5amI~
            {                                                      //~v61bI~
              if (stdo>Ppstdo)                                     //~v6DkI~
        		uerrmsg("%s remove failed.(%s)",0,                 //~v5amI~
						newsrc,*(stdo-1));	//already exit or path not found//~v5amI~
              else                                                 //~v6DkI~
        		uerrmsg("%s remove failed.(see ::xeftplog)",0,     //~v6DkI~
						newsrc);	//already exit or path not found//~v6DkI~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            }                                                      //~v61bI~
            rc=ENOENT;                                             //~v5amI~
            break;                                                 //~v5amI~
        }                                                          //~v5amI~
    }                                                              //~v5amI~
    Ppfwf2p->UFWF2Pcmdokctr=filectr;                               //~v5amR~
    Ppfwf2p->UFWF2Pfilesize=filesize;                              //~v5amR~
    ufree(Ppstdo);                                                 //~v5amI~
    return rc;                                                     //~v5amI~
}//uftpxdelrchk                                                    //~v5fdR~
//**************************************************************** //~v5fdI~
//ftp delete cmd result chk                                        //~v5fdI~
//*retrn:rc                                                        //~v5fdI~
//**************************************************************** //~v5fdI~
//int uftpmultidelrchk(PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pR~
int uftpmultidelrchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pR~
{                                                                  //~v5fdI~
	PUFTPMULTIDEL pfmd;                                            //~v5fdI~
    int rc=0,filectr=0,delctr,stdoctr,ii,opt;                      //~v5fdR~
    char **stdo,*pfpath;                                           //~v5fdR~
//****************************                                     //~v5fdI~
#ifdef AAA                                                         //~v61pI~
    if (UFTPHISPSFTP(Ppuftph))                                     //~v61pI~
        return uftp3multidelrchk(Popt,Ppuftph,Ppfwf2p,Ppstdo,Pstdoctr);//~v61pI~
#endif                                                             //~v61pI~
	stdoctr=Pstdoctr;                                              //~v5fdI~
    stdo=Ppstdo;                                                   //~v5fdI~
//  pfmd=(PUFTPMULTIDEL)(ULONG)(Ppfwf2p->UFWF2Ppudl);              //~v5fdR~//~v6hhR~
    pfmd=(PUFTPMULTIDEL)(ULPTR)(Ppfwf2p->UFWF2Ppudl);              //~v6hhI~
    delctr=Ppfwf2p->UFWF2Ppudlctr;                                 //~v5fdR~
    opt=Ppfwf2p->UFWF2Popt;                                        //~v5fdI~
    for (ii=0;ii<delctr;ii++,pfmd++)  //until eof/err              //~v5fdR~
    {                                                              //~v5fdI~
        if (!(pfmd->UFMDflag & UFMDFDELREQ))                       //~v5fdR~
            continue;                                              //~v5fdI~
        pfpath=pfmd->UFMDpfpath;                                   //~v5fdR~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
      	rc=uftp3smb_respchk(UFTPSMBCMD_DELETE|F3SMBO_MULTIENTRY,Ppuftph,pfpath,&stdo,&stdoctr,1);//~v6d1I~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkOK(0,Ppuftph,"delete","rm",&stdo,&stdoctr,1);//~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");           //~v5fdI~
        switch(rc)                                                 //~v5fdI~
        {                                                          //~v5fdI~
        case 0:    //250                                           //~v5fdI~
            filectr++;                                             //~v5fdI~
            if (opt & UXDELMSG)                                    //~v5fdI~
//          	ufiledeleted(pfpath,'F',-1,0);//size=-1  mean no display size/attr//~v5k0R~
            	ufiledeleted(pfpath,'F',(FILESZT)(-1),0);//size=-1  mean no display size/attr//~v5k0R~
            break;                                                 //~v5fdI~
        case 1:    //550                                           //~v5fdI~
          if (!UFTPH_ISSMB(Ppuftph))                               //~v6d1I~
            if (!Gufile_nomsg)   //nomsg option                    //~v5fdI~
            {                                                      //~v61bI~
              if (stdo>Ppstdo)                                     //~v6DkI~
        		uerrmsg("%s remove failed.(%s)",0,                 //~v5fdI~
						pfpath,*(stdo-1));	//already exit or path not found//~v5fdR~
              else                                                 //~v6DkI~
        		uerrmsg("%s remove failed.(see ::xeftplog)",0,     //~v6DkI~
						pfpath);	//already exit or path not found//~v6DkI~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            }                                                      //~v61bI~
            rc=ENOENT;                                             //~v5fdI~
    		pfmd->UFMDrc=rc;                                       //~v5fqI~
            break;                                                 //~v5fdI~
        }                                                          //~v5fdI~
    }                                                              //~v5fdI~
    Ppfwf2p->UFWF2Pcmdokctr=filectr;                               //~v5fdI~
    ufree(Ppstdo);                                                 //~v5fdI~
    return rc;                                                     //~v5fdI~
}//uftpmultidelrchk                                                //~v5fdI~
//**************************************************************** //~v5fnI~
//ftp rename cmd result chk                                        //~v5fnI~
//*retrn:rc                                                        //~v5fnI~
//**************************************************************** //~v5fnI~
//int uftpmultirenamerchk(PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pR~
int uftpmultirenamerchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pI~
{                                                                  //~v5fnI~
	PUFTPMULTIRENAME pfmr;                                         //~v5fnI~
    int rc=0,filectr=0,renamectr,stdoctr,ii;                       //~v5fqR~
    char **stdo,*pfpath,*pnewname;                                 //~v5fnI~
//****************************                                     //~v5fnI~
#ifdef AAA                                                         //~v61pI~
    if (UFTPHISPSFTP(Ppuftph))                                     //~v61pI~
        return uftp3multirenamerchk(Popt,Ppuftph,Ppfwf2p,Ppstdo,Pstdoctr);//~v61pR~
#endif                                                             //~v61pI~
	stdoctr=Pstdoctr;                                              //~v5fnI~
    stdo=Ppstdo;                                                   //~v5fnI~
//  pfmr=(PUFTPMULTIRENAME)(ULONG)(Ppfwf2p->UFWF2Ppudl);           //~v5fnI~//~v6hhR~
    pfmr=(PUFTPMULTIRENAME)(ULPTR)(Ppfwf2p->UFWF2Ppudl);           //~v6hhI~
    renamectr=Ppfwf2p->UFWF2Ppudlctr;                              //~v5fnI~
    for (ii=0;ii<renamectr;ii++,pfmr++)  //until eof/err           //~v5fnI~
    {                                                              //~v5fnI~
        if (!(pfmr->UFMRflag & UFMDFDELREQ))                       //~v5fnI~
            continue;                                              //~v5fnI~
        pfpath=pfmr->UFMRpfpath;                                   //~v5fnI~
        pnewname=pfmr->UFMRpnewname;                               //~v5fnI~
      if (UFTPH_ISSMB(Ppuftph))                                    //~v6d1I~
      {                                                            //~v6d1I~
      	rc=uftp3smb_respchk(UFTPSMBCMD_RENAME|F3SMBO_MULTIENTRY,Ppuftph,pfpath,&stdo,&stdoctr,1);//~v6d1I~
        if (!rc)	//stdo/stdoctr kept if rc=0                    //~v6d1I~
      		rc=uftp3smb_respchk(UFTPSMBCMD_RENAME|F3SMBO_MULTIENTRY,Ppuftph,pnewname,&stdo,&stdoctr,1);//chk errmsg by also new name//~v6d1I~
      }                                                            //~v6d1I~
      else                                                         //~v6d1I~
      if (UFTPHISPSFTP(Ppuftph))                                   //~v61pI~
		rc=uftp3simplerespchkCHNG(0,Ppuftph,"rename",pfpath,&stdo,&stdoctr,1);//~v61pI~
      else                                                         //~v61pI~
        rc=uftpcmdsrchrespid(&stdo,&stdoctr,"250 550 ");           //~v5fnI~
        switch(rc)                                                 //~v5fnI~
        {                                                          //~v5fnI~
        case 0:    //250                                           //~v5fnI~
            filectr++;                                             //~v5fnI~
            break;                                                 //~v5fnI~
        case 1:    //550                                           //~v5fnI~
          if (!UFTPH_ISSMB(Ppuftph))                               //~v6d1I~
            if (!Gufile_nomsg)   //nomsg option                    //~v5fnI~
            {                                                      //~v61bI~
              if (stdo>Ppstdo)                                     //~v6DkI~
        		uerrmsg("%s %s rename failed.(%s)",0,              //~v5fnI~
						pfpath,pnewname,*(stdo-1));	//already exit or path not found//~v5fnI~
              else                                                 //~v6DkI~
        		uerrmsg("%s %s rename failed.(see ::xeftplog)",0,  //~v6DkR~
						pfpath,pnewname);	//already exit or path not found//~v6DkR~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61bI~
            }                                                      //~v61bI~
            rc=ENOENT;                                             //~v5fnI~
    		pfmr->UFMRrc=rc;                                       //~v5fqR~
            break;                                                 //~v5fnI~
        }                                                          //~v5fnI~
    }                                                              //~v5fnI~
    Ppfwf2p->UFWF2Pcmdokctr=filectr;                               //~v5fnI~
    ufree(Ppstdo);                                                 //~v5fnI~
    return rc;                                                     //~v5fnI~
}//uftpmultirenamerchk                                             //~v5fnI~
//**************************************************************** //~v5amI~
//uftpcopystmt                                                     //~v5amI~
//  write get/put statement                                        //~v5amI~
//**************************************************************** //~v5amI~
int ufile2putstmt(FILE *Phfile,char *Pcmd,char *Pfnm)              //~v5amI~
{                                                                  //~v5amI~
//  char ftpcmd[_MAX_PATH+16];                                     //~v5fnR~
//  char ftpcmd[_MAX_PATH+_MAX_PATH+32];	//may have 2 filename  //~v5fnI~//~v6H7R~
    char ftpcmd[FTP_MAXPATH2+32];	//may have 2 filename          //~v6H7I~
//****************************                                     //~v5amI~
    if (Pfnm)                                                      //~v5amI~
      if (*Pfnm=='\"')	//already enclosed                         //~v5fnI~
	    sprintf(ftpcmd,"%s %s\n",Pcmd,Pfnm);                       //~v5fnI~
      else                                                         //~v5fnI~
	    sprintf(ftpcmd,"%s \"%s\"\n",Pcmd,Pfnm);                   //~v5bfR~
    else                                                           //~v5amI~
		sprintf(ftpcmd,"%s\n",Pcmd);                               //~v5amI~
//  fprintf(Phfile,ftpcmd);                                        //~v5amI~//~v6DiR~
    fprintf(Phfile,"%s",ftpcmd);                                   //~v6DiR~
    uftplog(0,ftpcmd);                                             //~v5amI~
    return 0;                                                      //~v5amI~
}//ufile2putstmt                                                   //~v5amI~
//**************************************************************** //~v56jI~
int uftpnotsupported(char *Pcmd,char *Pfnm)                        //~v56jI~
{                                                                  //~v56jI~
    uerrmsg("%s is not supported for FTP remote (%s).",0,          //~v56jI~
				Pcmd,Pfnm);                                        //~v56jI~
	uftplog(FTPLOG_ERRM,0);	//logging errmsg                       //~v61bI~
    errno=FTPRC_NOTSUPPORTED;                                      //~v56jR~
    return FTPRC_NOTSUPPORTED;	//not implemented                  //~v56jR~
}//uftpnotsupported                                                //~v56jI~
//**************************************************************** //~v56jI~
int uftpnotsupportedforlocal(char *Pcmd,char *Pfnm)                //~v56jI~
{                                                                  //~v56jI~
    uerrmsg("%s (%s) is supported for remote file only.",0,        //~v56jR~
				Pcmd,Pfnm);                                        //~v56jI~
	uftplog(FTPLOG_ERRM,0);	//logging errmsg                       //~v61bI~
    errno=FTPRC_NOTSUPPORTED;                                      //~v56jI~
    return FTPRC_NOTSUPPORTED;	//not implemented                  //~v56jI~
}//uftpnotsupportedforlocal                                        //~v56jI~
#ifdef ARMXXE                                                      //~v6daI~
//**************************************************************** //~v6daI~
//*multidel                                                        //~v6daI~
//**************************************************************** //~v6daI~
int uftpsmbj_multidelsub(int Popt,PUFWF2PARM Ppvoid,UQUEH *Ppqh)   //~v6daR~
{                                                                  //~v6daI~
    PUFWF2PARM pwf2p;                                              //~v6daI~
    int rc=0,reqctr,ii,filectr=0;                                  //~v6daI~
	PUFTPMULTIDEL pfmd;                                            //~v6daI~
    PUFTPHOST puftph;                                              //~v6daI~
//***********************************                              //~v6daI~
	pwf2p=(PUFWF2PARM)Ppvoid;                                      //~v6daI~
    pfmd=(PUFTPMULTIDEL)(ULONG)(pwf2p->UFWF2Ppudl);                //~v6daI~
    reqctr=pwf2p->UFWF2Ppudlctr;                                   //~v6daI~
    puftph=pwf2p->UFWF2Ppuftph;                                    //~v6daI~
    for (ii=0;ii<reqctr;ii++,pfmd++)  //until eof/err              //~v6daI~
    {                                                              //~v6daI~
    	pfmd->UFMDflag=0;	//clear ctl                            //~v6daI~
    	if (UCBITCHK(pfmd->UFMDattr,(FILE_DIRECTORY|FILE_SPECIAL|FILE_READONLY)))//~v6daI~
        {                                                          //~v6daI~
            uftpbypassreason(2,pfmd->UFMDpfpath,pfmd->UFMDattr);   //~v6daI~
    		pfmd->UFMDrc=UFMDRC_TYPEERR;                           //~v6daI~
        	continue;                                              //~v6daI~
        }                                                          //~v6daI~
    	pfmd->UFMDflag|=UFMDFDELREQ;                               //~v6daI~
    	pfmd->UFMDrc=0;                                            //~v6daI~
//    if (UFTPH_ISSMB(puftph))                                     //~v6daR~
//  	uftp3smb_putstmt(UFTPSMBCMD_DELETE|F3SMBO_MULTIENTRY,puftph,Phfile,pfmd->UFMDpfpath,0/*chparm2*/);//~v6daR~
//    else                                                         //~v6daR~
//  	ufile2putstmt(Phfile,"delete",pfmd->UFMDpfpath);           //~v6daR~
        jnismb_putstmtNoCD(0,puftph,pfmd->UFMDpfpath,Ppqh);        //~v6daR~
        filectr++;                                                 //~v6daI~
    }//dir list                                                    //~v6daI~
    if (!filectr)                                                  //~v6daI~
    	rc=FTPRC_NOMOREFILE;	//request skip ftp cmd             //~v6daI~
    return rc;                                                     //~v6daI~
}//uftpsmbj_multidelsub                                            //~v6daI~
//**************************************************************** //~v6daI~
int uftpsmbj_multidel(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Pwf2p) //~v6daI~
{                                                                  //~v6daI~
	int rc;                                                        //~v6daI~
    UQUEH reqqh;                                                   //~v6daI~
//******************************                                   //~v6daI~
    memset(&reqqh,0,sizeof(reqqh));                                //~v6daI~
	rc=uftpsmbj_multidelsub(Popt,Pwf2p,&reqqh);                    //~v6daI~
    if (!rc)                                                       //~v6daI~
		rc=jnismb_multidel(0,Ppuftph,&reqqh);                      //~v6daR~
    return rc;                                                     //~v6daI~
}//uftpsmbj_multidel                                               //~v6daI~
//**************************************************************** //~v6daI~
//!uftpmultirename(uftpcmd callback)                               //~v6daI~
//* rename multiple request entry                                  //~v6daI~
//*retrn:rc                                                        //~v6daI~
//**************************************************************** //~v6daI~
int uftpsmbj_multirenamesub(int Popt,PUFWF2PARM Ppvoid,UQUEH *Ppqh)//~v6daI~
{                                                                  //~v6daI~
    PUFWF2PARM pwf2p;                                              //~v6daI~
    int rc=0,reqctr,ii,filectr=0;                                  //~v6daI~
	PUFTPMULTIRENAME pfmr;                                         //~v6daI~
//  UCHAR renameopd[FTP_MAXPATH+FTP_MAXPATH+4];                    //~v6daI~//+v702R~
    UCHAR newname[FTP_MAXPATH];                                    //~v6daI~
    PUFTPHOST puftph;                                              //~v6daI~
//***********************************                              //~v6daI~
	pwf2p=(PUFWF2PARM)Ppvoid;                                      //~v6daI~
    pfmr=(PUFTPMULTIRENAME)(ULONG)(pwf2p->UFWF2Ppudl);             //~v6daI~
    reqctr=pwf2p->UFWF2Ppudlctr;                                   //~v6daI~
    puftph=pwf2p->UFWF2Ppuftph;                                    //~v6daI~
    for (ii=0;ii<reqctr;ii++,pfmr++)  //until eof/err              //~v6daI~
    {                                                              //~v6daI~
    	pfmr->UFMRflag=0;	//clear ctl                            //~v6daI~
    	if (UCBITCHK(pfmr->UFMRattr,(FILE_DIRECTORY|FILE_SPECIAL|FILE_READONLY)))//~v6daI~
        {                                                          //~v6daI~
            uftpbypassreason(3,pfmr->UFMRpfpath,pfmr->UFMRattr);   //~v6daI~
    		pfmr->UFMRrc=UFMRRC_TYPEERR;                           //~v6daI~
        	continue;                                              //~v6daI~
        }                                                          //~v6daI~
    	pfmr->UFMRflag|=UFMRFRENAMEREQ;                            //~v6daI~
    	pfmr->UFMRrc=0;                                            //~v6daI~
    	strcpy(newname,pfmr->UFMRpfpath);                          //~v6daI~
        strcpy(newname+FTP_PATHLEN(newname),pfmr->UFMRpnewname);   //~v6daI~
//      if (UFTPH_ISSMB(puftph))                                   //~v6daR~
//        uftp3smb_putstmt(UFTPSMBCMD_RENAME,puftph,Phfile,pfmr->UFMRpfpath,newname);//~v6daR~
//      else                                                       //~v6daR~
//      {                                                          //~v6daR~
//        sprintf(renameopd,"\"%s\" \"%s\"",pfmr->UFMRpfpath,newname);//~v6daR~
//        ufile2putstmt(Phfile,"rename",renameopd);                //~v6daR~
//      }                                                          //~v6daR~
        jnismb_putstmtNoCD2(0,puftph,pfmr->UFMRpfpath,newname,Ppqh);//~v6daR~
        filectr++;                                                 //~v6daI~
    }//dir list                                                    //~v6daI~
    if (!filectr)                                                  //~v6daI~
    	rc=FTPRC_NOMOREFILE;	//request skip ftp cmd             //~v6daI~
    return rc;                                                     //~v6daI~
}//uftpsmbj_multirenamesub                                         //~v6daR~
//**************************************************************** //~v6daI~
int uftpsmbj_multirename(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Pwf2p)//~v6daR~
{                                                                  //~v6daI~
	int rc;                                                        //~v6daI~
    UQUEH reqqh;                                                   //~v6daI~
//******************************                                   //~v6daI~
    memset(&reqqh,0,sizeof(reqqh));                                //~v6daI~
	rc=uftpsmbj_multirenamesub(Popt,Pwf2p,&reqqh);                 //~v6daI~
    if (!rc)                                                       //~v6daI~
		rc=jnismb_multirename(0,Ppuftph,&reqqh);                   //~v6daI~
    return rc;                                                     //~v6daI~
}//uftpsmbj_multirename                                            //~v6daR~
//**************************************************************** //~v6daI~
int uftpsmbj_wildfunc2(int Popt,PUFTPHOST Ppuftph,FTPCMD_CALLBACK Pfunc,PUFWF2PARM Pwf2p)//~v6daI~
{                                                                  //~v6daI~
//******************************                                   //~v6daI~
	return Pfunc(NULL/*File*/,Pwf2p);                              //~v6daR~
}//uftpsmbj_wildfunc2                                              //~v6daI~
//**************************************************************** //~v6daI~
//!uftsmbj_wildxdel(uftpsmbj_wildfunc2 callback)                   //~v6daI~
//* delete by wild card                                            //~v6daI~
//**************************************************************** //~v6daI~
int uftpsmbj_wildxdel(int Popt,PUFWF2PARM Ppvoid)                  //~v6daR~
{                                                                  //~v6daI~
    PUFWF2PARM pwf2p;                                              //~v6daI~
	PUDIRLIST pudirlist;                                           //~v6daI~
    int rc=0,pudlctr,ii,filectr=0,pathlen;                         //~v6daI~
//  char fpath[_MAX_PATH];                                         //~v6daI~//~v6H7R~
    char fpath[FTP_MAXPATH2];                                      //~v6H7I~
    PUFTPHOST puftph;                                              //~v6daI~
    UQUEH reqqh;                                                   //~v6daI~
    FILESZT filesize=0;                                            //~v6daI~
//***********************************                              //~v6daI~
    memset(&reqqh,0,sizeof(reqqh));                                //~v6daI~
	pwf2p=(PUFWF2PARM)Ppvoid;                                      //~v6daI~
    pudirlist=pwf2p->UFWF2Ppudl;                                   //~v6daI~
    pudlctr=pwf2p->UFWF2Ppudlctr;                                  //~v6daI~
    pathlen=pwf2p->UFWF2Ppathlen;                                  //~v6daI~
    puftph=pwf2p->UFWF2Ppuftph;                                    //~v6daI~
    memcpy(fpath,pwf2p->UFWF2Pfpath,(UINT)pathlen);                //~v6daI~
    *(fpath+pathlen)=0;                                            //~v6daI~
//  if (UFTPH_ISSMB(puftph))                                       //~v6daR~
//		uftp3smb_putstmt(UFTPSMBCMD_DELETE|F3SMBO_MULTISTART,puftph,Phfile,fpath,0/*chparm2*/);//~v6daR~
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err        //~v6daI~
    {                                                              //~v6daI~
//  	pudirlist->attr&=~FILE_FTPWKSL;	//id of cmd put for respchk//~v6daR~
//#ifdef UTF8SUPPH                                                 //~v6daR~
//      if (!FILE_ISSLINKDIR(pudirlist->attr))                     //~v6daR~
//#endif                                                           //~v6daR~
    	if (UCBITCHK(pudirlist->attr,(FILE_DIRECTORY|FILE_SPECIAL|FILE_READONLY)))//~v6daI~
        	continue;                                              //~v6daI~
//    	pudirlist->attr|=FILE_FTPWKSL;	//id of cmd put for respchk//~v6daR~
        strcpy(fpath+pathlen,pudirlist->name);                     //~v6daI~
//    if (UFTPH_ISSMB(puftph))                                     //~v6daR~
//  	uftp3smb_putstmt(UFTPSMBCMD_DELETE,puftph,Phfile,fpath,0/*chparm2*/);//~v6daR~
//    else                                                         //~v6daR~
//  	ufile2putstmt(Phfile,"delete",fpath);                      //~v6daR~
        jnismb_putstmtNoCD(0,puftph,fpath,&reqqh);                 //~v6daR~
		filesize+=pudirlist->size;                                 //~v6daI~
        filectr++;                                                 //~v6daI~
    }//dir list                                                    //~v6daI~
    pwf2p->UFWF2Pcmdokctr=filectr;	//processed ctr                //~v6daI~
    pwf2p->UFWF2Pfilesize=filesize;                                //~v6daR~
    if (!filectr)                                                  //~v6daI~
    	rc=FTPRC_NOMOREFILE;	//request skip ftp cmd             //~v6daI~
    else                                                           //~v6daI~
		rc=jnismb_multidel(0,puftph,&reqqh);                       //~v6daR~
    return rc;                                                     //~v6daI~
}//uftpsmbj_wildxdel                                               //~v6daI~
#endif                                                             //~v6daI~
//**************************************************************** //~v6djI~
//!uftdelsubdir                                                    //~v6djI~
//**************************************************************** //~v6djI~
//int uftpdelsubdir(int Popt,PUFWF2PARM Ppwf2p,void* Pparm,int *Ppfilectr,FILESZT *Ppfilesize)//~v6djR~
int uftpdelsubdir(int Popt,PUFWF2PARM Ppwf2p)                      //~v6djI~
{                                                                  //~v6djI~
	PUDIRLIST pudirlist;                                           //~v6djI~
    int rc=0,pudlctr,ii,pathlen;                                   //~v6djI~
//  char fpath[_MAX_PATH],*pc,*pcroot;                             //~v6djR~//~v6H7R~
    char fpath[FTP_MAXPATH2],*pc,*pcroot;                          //~v6H7I~
    PUFTPHOST puftph;                                              //~v6djI~
//    int ftpfilectr;                                              //~v6djR~
//    FILESZT ftpfilesize;                                         //~v6djR~
    UINT attrmask;                                                 //~v6djI~
//***********************************                              //~v6djI~
    pudirlist=Ppwf2p->UFWF2Ppudl;                                  //~v6djI~
    pudlctr=Ppwf2p->UFWF2Ppudlctr;                                 //~v6djI~
    pathlen=Ppwf2p->UFWF2Ppathlen;                                 //~v6djI~
    puftph=Ppwf2p->UFWF2Ppuftph;                                   //~v6djI~
//  attrmask=Ppwf2p->UFWF2Pattrmask;                               //~v6djI~//~v6D1R~
    attrmask=(UINT)(Ppwf2p->UFWF2Pattrmask);                       //~v6D1I~
    pc=fpath;                                                      //~v6djI~
//  memcpy(pc,puftph->UFTPHhost,puftph->UFTPHhostnmlen);           //~v6djI~//~v6D0R~
    memcpy(pc,puftph->UFTPHhost,(size_t)(puftph->UFTPHhostnmlen)); //~v6D0I~
    pc+=puftph->UFTPHhostnmlen;                                    //~v6djI~
    *pc++=FTP_REMOTEID;                                            //~v6djI~
    memcpy(pc,Ppwf2p->UFWF2Pfpath,(UINT)pathlen);                  //~v6djR~
    pcroot=pc+pathlen;                                             //~v6djI~
    *(pcroot)=0;                                                   //~v6djR~
    for (ii=0;ii<pudlctr;ii++,pudirlist++)  //until eof/err        //~v6djI~
    {                                                              //~v6djI~
    	if (!UCBITCHK(pudirlist->attr,FILE_DIRECTORY))             //~v6djI~
        	continue;                                              //~v6djI~
        if (!strcmp(pudirlist->name,".")        //curr             //~v6djI~
        ||  !strcmp(pudirlist->name,".."))      //parent           //~v6djI~
            continue;                                              //~v6djI~
        if (strlen(fpath)+strlen(pudirlist->name)>=FTP_MAXPATH)    //~v6H7I~
        {                                                          //~v6H7I~
			errtoolongname(0,fpath,pudirlist->name,0/*rc*/);       //~v6H7R~
            continue;                                              //~v6H7I~
        }                                                          //~v6H7I~
//      if (UFTPH_ISSMB(puftph))	//smb replace existing file;no need to delete//~v6djR~
//      	uftp3smb_dirnameforlist(0,puftph,pudirlist->name,pcroot); //append "/*" for list dir('/' required for smb)//~v6djR~
//      else                                                       //~v6djR~
        	strcpy(pcroot,pudirlist->name);                        //~v6djR~
//        rc=uftpwildfunc2(Popt,fpath,attrmask,uftpwildxdel,Pparm,&ftpfilectr,&ftpfilesize);//~v6djR~
//        *Ppfilectr+=ftpfilectr;                                  //~v6djR~
//        *Ppfilesize+=ftpfilesize;                                //~v6djR~
//      uxdelsub(fpath,pudirlist->attr,attrmask,1/*deldirsw*/,pudirlist->size);//~v6djR~//~v6H7R~
        uxdelsubftp(fpath,pudirlist->attr,attrmask,1/*deldirsw*/,pudirlist->size);//~v6H7I~
    }//dir list                                                    //~v6djI~
    return rc;                                                     //~v6djI~
}//uftpdelsubdir                                                   //~v6H7R~
//**************************************************************** //~v6H7I~
void ufile3xdeleteinit(UCHAR *Pfile,unsigned Pattrmask,int Popt,int *Ppprocctr,int *Ppronlyctr,int *Ppdeldctr,int *Pplongnamectr,FILESZT *Ppdelsize)//~v6H7R~
{                                                                  //~v6H7I~
	Sxdelopt=Popt;                                                 //~v6H7I~
    Spdelfctr=Ppprocctr;                                           //~v6H7R~
    Spdelrctr=Ppronlyctr;                                          //~v6H7I~
    Spdeldctr=Ppdeldctr;                                           //~v6H7I~
    Spdellongnamectr=Pplongnamectr;                                //~v6H7I~
	Spdelsize=Ppdelsize;                                           //~v6H7R~
}                                                                  //~v6H7I~
//**************************************************************** //~v6H7I~
//uxdelsubftp                                                      //~v6H7I~
//* del file/dir                                                   //~v6H7I~
//*parm1:fullpath filename                                         //~v6H7I~
//*parm2:file attr                                                 //~v6H7I~
//*parm3:attrmask                                                  //~v6H7I~
//*parm4:del dir sw                                                //~v6H7I~
//*parm5:file size                                                 //~v6H7I~
//*retrn:rc                                                        //~v6H7I~
//**************************************************************** //~v6H7I~
int uxdelsubftp(UCHAR *Pfile,ULONG Pattr,unsigned Pattrmask,int Pdeldirsw,FILESZT Psize)//~v6H7R~
{                                                                  //~v6H7I~
    int rc=0,/*filectr,*/ronlysw,skipsw;                           //~v6H7R~
    int dirnamelen;                                                //~v6H7I~
    #define ATTR_TYPE unsigned long                                //~v6H7I~
    ULONG outattr;                                                 //~v6H7I~
    FILESZT totsz;                                                 //~v6H7I~
    int msgsw;                                                     //~v6H7R~
    UINT parmwildf[2];  //parm to wild func                        //~v6H7I~
	int ftpfilectr;                                                //~v6H7I~
    FILESZT ftpfilesize;                                           //~v6H7I~
//  int slinksw;                                                   //~v6H7R~
//  int swrenamedeleted=0;                                         //~v6H7R~
//  char fpathrename[_MAX_PATH]={0},*topdir;                       //~v6H7R~
    char /*fpathrename[FTP_MAXPATH]={0},*/*topdir;                 //~v6H7R~
    int swtoolong=0;                                               //~v6H7I~
//********************                                             //~v6H7I~
//read only process                                                //~v6H7I~
    (*Spdelfctr)++;        //processed ctr(contain skip ctr)       //~v6H7R~
	UTRACEP("%s delfctr=%d,attr=%x,fnm=%s\n",UTT,*Spdelfctr,Pattr,Pfile);//~v6H7R~
//  slinksw=FILE_ISSLINK(Pattr);                                   //~v6H7R~
    ronlysw=UCBITCHK(Pattr,FILE_READONLY);                         //~v6H7I~
#ifdef UNX                                                         //~v6H7I~
    if (Pattr & FILE_WILDNAME)                                     //~v6H7I~
        Sxdelwctr++;                                               //~v6H7R~
#endif                                                             //~v6H7I~
    if (ronlysw)                                                   //~v6H7I~
    {                                                              //~v6H7I~
        (*Spdelrctr)++;                                            //~v6H7R~
        if (Sxdelopt & UXDELRONLYCHK) //readonly chk only          //~v6H7I~
        {                                                          //~v6H7I~
            if (Sxdelopt & UXDELFORCE) //contine req               //~v6H7I~
            {                                                      //~v6H7I~
//              if (Sxdelopt & UXDELMSG) //msg put option          //~v6H7R~
//              {                                                  //~v6H7R~
//                  if (slinksw)                                   //~v6H7R~
//                      ufilereadonly2(Pfile,'L');                 //~v6H7R~
//                  else                                           //~v6H7R~
//                  if (UCBITCHK(Pattr,FILE_DIRECTORY)) //normal file//~v6H7R~
//                      ufilereadonly2(Pfile,'D');                 //~v6H7R~
//                  else                                           //~v6H7R~
//                      ufilereadonly2(Pfile,'F');                 //~v6H7R~
//              }//delmsg                                          //~v6H7R~
                UTRACEP("%s:UXDELRONLYCHK & UXDELFORCE:%s\n",Pfile);//~v6H7I~
            }                                                      //~v6H7I~
            else                                                   //~v6H7I~
                return ufilereadonly(Pfile,-2); //rc=0             //~v6H7I~
        }                                                          //~v6H7I~
        else    //not check                                        //~v6H7I~
        {                                                          //~v6H7I~
            if (Sxdelopt & UXDELFORCE) //force del req             //~v6H7I~
            {                                                      //~v6H7I~
                if (rc=uattrib(Pfile,0,FILE_READONLY,&outattr),rc)  //reset ronly//~v6H7I~
                    return rc;                                     //~v6H7I~
                ronlysw=0;  //can be deletable                     //~v6H7I~
            }                                                      //~v6H7I~
            else                                                   //~v6H7I~
                if (Sxdelopt & UXDELSKIPRONLY) //ignore read only  //~v6H7I~
                {                                                  //~v6H7I~
//                  if (Sxdelopt & UXDELMSG) //msg put option      //~v6H7R~
//                  {                                              //~v6H7R~
//                      if (slinksw)                               //~v6H7R~
//                          ufilereadonly2(Pfile,'L');             //~v6H7R~
//                      else                                       //~v6H7R~
//                      if (UCBITCHK(Pattr,FILE_DIRECTORY)) //normal file//~v6H7R~
//                          ufilereadonly2(Pfile,'D');             //~v6H7R~
//                      else                                       //~v6H7R~
//                          ufilereadonly2(Pfile,'F');             //~v6H7R~
//                  }//delmsg                                      //~v6H7R~
	                UTRACEP("%s:UXDELSKIPRONLY:%s\n",Pfile);       //~v6H7I~
                }                                                  //~v6H7I~
                else                                               //~v6H7I~
                    return ufilereadonly(Pfile,-2); //rc=0         //~v6H7I~
        }                                                          //~v6H7I~
    }//read only file/dir                                          //~v6H7I~
//*******                                                          //~v6H7I~
    skipsw=ronlysw | (Sxdelopt & UXDELRONLYCHK); //readonly chk only//~v6H7I~
    if (!FILE_ISNOSLINKDIR(Pattr)) //normal or slink file          //~v6H7I~
    {                                                              //~v6H7I~
        if (skipsw)         //bypass                               //~v6H7I~
            return 0;                                              //~v6H7I~
        else                                                       //~v6H7I~
        {                                                          //~v6H7I~
            msgsw=(Sxdelopt & UXDELMSG); //msg put option save     //~v6H7R~
            Sxdelopt&=~UXDELMSG; //msg put option clear            //~v6H7I~
#ifdef W32                                                         //~v6H7I~
          if (FILE_MODEISNTFS_MOUNTVOL(Pattr))                     //~v6H7I~
	        rc=urmdir(Pfile);                                      //~v6H7I~
          else                                                     //~v6H7I~
          if (FILE_MODEISNTFS_JUNCTION(Pattr))                     //~v6H7I~
	        rc=urmdir(Pfile);                                      //~v6H7I~
          else                                                     //~v6H7I~
    	  if (FILE_ISSLINKDIR(Pattr))                              //~v6H7I~
	        rc=urmdir(Pfile);                                      //~v6H7I~
          else                                                     //~v6H7I~
#endif                                                             //~v6H7I~
            rc=uremove(Pfile);                                     //~v6H7I~
            Sxdelopt|=msgsw; //msg put option restore              //~v6H7R~
            if (!rc)                                               //~v6H7I~
            {                                                      //~v6H7I~
                *Spdelsize+=Psize;                                 //~v6H7R~
                (*Spdeldctr)++;    //deleted ctr                   //~v6H7R~
//              if (msgsw) //msg put option                        //~v6H7R~
//              {                                                  //~v6H7R~
//               if (Sxdelopt & UXDELQUIET)                        //~v6H7R~
//               {                                                 //~v6H7R~
//               	ufile2quietmsg(0,Pfile);                       //~v6H7R~
//               }                                                 //~v6H7R~
//               else                                              //~v6H7R~
//               {                                                 //~v6H7R~
//                if (slinksw)                                     //~v6H7R~
//                  ufiledeleted(Pfile,'L',Psize,(ATTR_TYPE)Pattr);//size=-1  mean no display size/attr//~v6H7R~
//                else                                             //~v6H7R~
//                  ufiledeleted(Pfile,'F',Psize,(ATTR_TYPE)Pattr);//size=-1  mean no display size/attr//~v6H7R~
//               }                                                 //~v6H7R~
//              }                                                  //~v6H7R~
            }                                                      //~v6H7I~
            return rc;                                             //~v6H7I~
        }                                                          //~v6H7I~
    }//normal file                                                 //~v6H7I~
//del dir                                                          //~v6H7I~
    dirnamelen=(int)strlen(Pfile);                                 //~v6H7I~
//if (Pattr & FILE_REMOTE)                                         //~v6H7R~
//{                                                                //~v6H7R~
// if (dirnamelen+(int)sizeof(FTP_DIR_SEPS FTP_DIR_ALLMEMB)>=_MAX_PATH)//~v6H7R~
   if (dirnamelen+(int)sizeof(FTP_DIR_SEPS FTP_DIR_ALLMEMB)>=FTP_MAXPATH)//~v6H7I~
   {                                                               //~v6H7I~
	errtoolongname(0,Pfile,FTP_DIR_SEPS FTP_DIR_ALLMEMB,0/*rc*/);  //~v6H7R~
    swtoolong=1;                                                   //~v6H7I~
   }                                                               //~v6H7I~
   else                                                            //~v6H7I~
    strcat(Pfile,FTP_DIR_SEPS FTP_DIR_ALLMEMB); //\*. or *,/*      //~v6H7I~
//}                                                                //~v6H7R~
//else                                                             //~v6H7R~
//{                                                                //~v6H7R~
// if (dirnamelen+(int)sizeof(DIR_SEPS DIR_ALLMEMB)>=_MAX_PATH)//\*.* or /*//~v6H7R~
// if (dirnamelen+(int)sizeof(DIR_SEPS DIR_ALLMEMB)>=FTP_MAXPATH)//\*.* or /*//~v6H7R~
//  swtoolong=1;                                                   //~v6H7R~
// else                                                            //~v6H7R~
//  strcat(Pfile,DIR_SEPS DIR_ALLMEMB);//\*.* or /*                //~v6H7R~
//}                                                                //~v6H7R~
    totsz=*Spdelsize;                                              //~v6H7R~
    parmwildf[0]=Pattrmask;                                        //~v6H7I~
    parmwildf[1]=0;  //no confirm for 2nd level                    //~v6H7I~
//	if (Pattr & FILE_REMOTE)                                       //~v6H7R~
//  {                                                              //~v6H7R~
        if (swtoolong)                                             //~v6H7I~
        {                                                          //~v6H7I~
			(*Spdellongnamectr)++;                                 //~v6H7R~
            return UWFRC_LONGNAME;        //@@@@FIXME not tested   //~v6H7I~
        }                                                          //~v6H7I~
        rc=                                                        //~v6H7I~
    	uftpwildfunc2(Sxdelopt,Pfile,Pattrmask,uftpwildxdel,parmwildf,&ftpfilectr,&ftpfilesize);//~v6H7I~
        if (rc)                                                    //~v6H7I~
    	    return rc;                                             //~v6H7I~
        *Spdelfctr+=ftpfilectr;                                    //~v6H7R~
        *Spdeldctr+=ftpfilectr;                                    //~v6H7R~
        *Spdelsize+=ftpfilesize;                                   //~v6H7R~
        UTRACEP("%s:delfctr=%d deldctr=%d,dellctr=%d\n",UTT,*Spdelfctr,*Spdeldctr,*Spdellongnamectr);//~v6H7R~
//  }                                                              //~v6H7R~
//if (!(Pattr & FILE_REMOTE) || FILE_ISNOSLINKDIR(Pattrmask))      //~v6H7R~
//{                                                                //~v6H7R~
//if (swtoolong)                                                   //~v6H7R~
//{                                                                //~v6H7R~
//  Sxdellongnamectr++;                                            //~v6H7R~
//  rc=UWFRC_LONGNAME;        //@@@@FIXME not tested               //~v6H7R~
//}                                                                //~v6H7R~
//else                                                             //~v6H7R~
//{                                                                //~v6H7R~
//  if (rc=uwildfunc(UWFO_DELETE,         //bypass ea data,use alias for wildcardmember//~v6H7R~
//                  Pfile,Pattrmask,ufilewildxdel,parmwildf,&filectr),rc)//~v6H7R~
//	  if (Pattr & FILE_REMOTE)	//file was deleted by uftpwildfunc2//~v6H7R~
//      return rc;                                                 //~v6H7R~
//}                                                                //~v6H7R~
//      if (rc & UWFRC_LONGNAME)        //over _MAX_PATH           //~v6H7R~
//      {                                                          //~v6H7R~
//        if (Sxdelopt & UXDELFORCE)                               //~v6H7R~
//            if (!(Sxdelopt & UXDELRONLYCHK)) //readonly chk only //~v6H7R~
//                if (Pdeldirsw)                                   //~v6H7R~
//                {                                                //~v6H7R~
//                    rc=uwildfunc_LongName(UWFO_DELETE,           //~v6H7R~
//                        Pfile,Pattr,Pattrmask,ufilewildxdel,parmwildf,/*&filectr,*/fpathrename);//~v6H7R~
//                    UTRACEP("%s:dellfctr=%d\n",UTT,Sxdelfctr);   //~v6H7R~
//                    if (!rc)                                     //~v6H7R~
//                    {                                            //~v6H7R~
//                        swrenamedeleted=1;                       //~v6H7R~
//                    }                                            //~v6H7R~
//                }                                                //~v6H7R~
//      }                                                          //~v6H7R~
//}                                                                //~v6H7R~
    totsz=*Spdelsize-totsz;  //this dir size                       //~v6H7R~
    *(Pfile+dirnamelen)=0;  //drop \*.*                            //~v6H7I~
//if (!swrenamedeleted)                                            //~v6H7R~
//{                                                                //~v6H7R~
		topdir=Pfile;                                              //~v6H7I~
                                                                   //~v6H7I~
    if (Pdeldirsw)                                                 //~v6H7I~
    {                                                              //~v6H7I~
        if (skipsw)         //bypass                               //~v6H7I~
            return 0;                                              //~v6H7I~
        if (!(rc=urmdir(topdir)))                                  //~v6H7I~
        {                                                          //~v6H7I~
            (*Spdeldctr)++;    //deleted ctr                       //~v6H7R~
//          if (Sxdelopt & UXDELMSG) //msg put option              //~v6H7R~
//          {                                                      //~v6H7R~
//            if (Sxdelopt & UXDELQUIET)                           //~v6H7R~
//            {                                                    //~v6H7R~
//            	ufile2quietmsg(0,topdir);                          //~v6H7R~
//            }                                                    //~v6H7R~
//            else                                                 //~v6H7R~
//            {                                                    //~v6H7R~
//              ufiledeleted(topdir,'D',totsz,(ATTR_TYPE)Pattr);   //~v6H7R~
//            }                                                    //~v6H7R~
//          }                                                      //~v6H7R~
        }                                                          //~v6H7I~
        else                                                       //~v6H7I~
        {                                                          //~v6H7I~
//          if (Sxdelopt & UXDELSKIPRONLY) //ignore read only      //~v6H7R~
//              rc=0;   //contine(may contain read only)           //~v6H7R~
            rc=UXDELRC_FTP_RMDIR_FAILED;  //4097   //FTP rmdir Failed//~v6H7I~
        }                                                          //~v6H7I~
    }                                                              //~v6H7I~
//}//rename //deleted                                              //~v6H7R~
    return rc;                                                     //~v6H7I~
}//uxdelsubftp                                                     //~v6H7I~
//**************************************************************** //~v6H7I~
int	errtoolongname(int Popt,char *Pdir,char *Pmemb,int Prc)        //~v6H7I~
{                                                                  //~v6H7I~
	ufileTooLongFullpathName2(0,Pdir,Pmemb);                       //~v6H7I~
	uftplog(FTPLOG_ERRM,0/*by ugeterrmsg2()*/);                    //~v6H7R~
    return Prc;                                                    //~v6H7I~
}//errtoolongname                                                  //~v6H7I~
