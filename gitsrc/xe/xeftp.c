//*CID://+vb89R~:                             update#=  254;       //~vb89R~
//*************************************************************
//*xeftp.c                                                         //~v53UR~
//**drop,tab clear,func key file edit
//*************************************************************
//vb89:170217 create if not found. ::xehosts ::xesync_.cfg         //~vb89I~
//vb7e:170108 FTP crash by longname                                //~vb7eI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vane:131208 clear crypt pswd for inserted line to avoid copy line(But,effective only for update)//~vaneI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vac6:120217 (Axe)samba share support using jcifs 3.17            //~vac0I~
//vac0:120131 (SMB)node cmd to set volatile password to UFTPHOST   //~vac0R~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v76p:070628 compare remote file support                          //~v76pI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v71R:061111 3270:check after save by reloading and keep result in workdir if save fail//~v71RI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v712:060916 ftp temp filename timestamp expand to milisec to avoid duplicated name//~v712I~
//v710:060916 (BUG)tmp file remains in xeftpwd by save cmd with remotefile operand.//~v710I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v63j:050507 (WXE)dragdrop remote file support                    //~v63jI~
//v62h:050316 ftp undel support                                    //~v62hI~
//v60c:050121 (BUG)abend when xehosts has dup entry                //~v60cI~
//v59d:041107 rsh:log also shell script itself                     //~v59dI~
//v57K:040619 (FTP:BUG)append cmd dose not append but copy only    //~v57KI~
//v57s:040530 (FTP)xpr dcmd support                                //~v57sI~
//v577:040516 (FTP:BUG)file on root dir(/) is not save to root but to /root(home of root)//~v577I~
//v576:040513 (FTP:BUG)if u edit same filename except case,        //~v576I~
//            another file name is  save back to remote.so use tempdir//~v576I~
//v55o:040222 (FTP)use client pgm for avoid dos prompt screen appear//~v55oI~
//v554:040202 (FTP:BUG)uqfree use free not ufree;so not freed err at term//~v554I~
//v54U:040125 move updatechk sub to xefsub(used by OS/2 DOS)       //~v54UI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v54n:040105 (FTP)support hosts filename /f                       //~v54nI~
//v545:040101 (UNX,FTP:BUG)new file cannot be saved by anyone updated err//~v545I~
//v544:040101 (UNX,FTP)timestamp is by slink source if slink       //~v544I~
//v53U:031109 (WIN,UNX)ftp support                                 //~v53UI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32                                                         //~v53UI~
	#include <io.h>    		//for _A_SUBDIR etc                    //~v53UI~
#endif                                                             //~v53UI~
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <uftp.h>                                                  //~v54nM~
#include <ufile1f.h>                                               //~v53UI~
#include <ufile2.h>                                                //~v53UI~
#include <ufile3.h>                                                //~v53UI~
#include <ustring.h>                                               //~v53UI~
#include <uedit.h>                                                 //~v53UI~
#include <uparse.h>                                                //~v53UI~
#include <uproc2.h>                                                //~v63jR~
#include <utrace.h>                                                //~v64aI~
#include <u3270.h>                                                 //~v70zI~
#include <ufemsg.h>                                                //~v76pI~
#ifdef ARMXXE                                                      //~vac6I~
	#include <uftp3.h>                                             //~vac6R~
#endif                                                             //~vac6I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v53UI~
#include "xefile2.h"                                               //~v53UI~
#include "xefile6.h"                                               //~v59dI~
#include "xefcmd22.h"                                              //~v53UI~
#include "xedir.h"                                                 //~v70zI~
#define XEFTP_GLOBAL                                               //~vaneI~
#include "xeftp.h"                                                 //~v53UI~
#include "xefunc.h"                                                //~v53UI~
#include "xesub.h"                                                 //~v53UI~
#include "xefsub.h"                                                //~v54UI~
#include "xetso.h"                                               //~v70zI~
#include "xeerr.h"                                                 //~vac0R~
#include "xepan.h"                                                 //~vb7eI~
#include "xedlcmd.h"                                               //~vb7eR~
#include "xedlcmd4.h"                                              //~vb7eI~
//*******************************************************
//#define FTP_WDSUFFIX "YYMMDD-HHMMSS"                             //~v712R~
#define FTP_WDSUFFIX "YYMMDD-HHMMSS_MIL"                           //~v712I~
#define FTPHOSTS_DUMMY_RECORD  "## " FTPHOSTS " ## xe created this dummy file as it is not found; see xee.txt/xej.txt for detail format ##\n"//~vb89I~
//*******************************************************
static int Sftpinitsw=0;                                           //~v53UR~
static char Sfpathwd[_MAX_PATH];                                   //~v53UI~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
	static char Sfpathdndwd[_MAX_PATH];                            //~v63jI~
#endif                                                             //~v63jI~
static int  Sfpathwdlen=0;                                         //~v53UI~
//****************************************************************
//**************************************************************** //~v53UI~
//* keep hots data at file save                                    //~v53UI~
//* parm1 :pfh                                                     //~v53UI~
//* retrn:rc UALLOC_FAILED or 4                                    //~v53UI~
//**************************************************************** //~v53UI~
int xeftpinit(int Popt,char *Phostsfnm)                            //~v54nR~
{                                                                  //~v53UI~
	int rc,opt=0;                                                  //~v53UR~
    char fpathhosts[_MAX_PATH],fpathlog[_MAX_PATH];                //~v53UR~
    FILEFINDBUF3 fstat3;                                           //~v53UI~
    char *pclientpgm="xesyscmd";                                   //~v55oR~
//*****************                                                //~v53UI~
	if (Sftpinitsw)                                                //~v53UR~
    	return 0;                                                  //~v53UI~
    if (Popt & XEFTP_NOUSE)                                        //~v53UI~
    {                                                              //~v53UI~
    	UCBITON(Gopt,GOPTNOFTP);                                   //~v53UR~
    	opt=UFTPO_NOP;                                             //~v53UM~
    }                                                              //~v53UI~
    else                                                           //~v53UM~
    {                                                              //~v53UI~
    	if (Popt & XEFTP_LOG)                                      //~v53UI~
        {                                                          //~v53UI~
            opt=UFTPO_LOG;   //write mode                          //~v53UI~
	    	if (Popt & XEFTP_APPEND)                               //~v53UR~
            	opt|=UFTPO_APPEND;  //append mode                  //~v53UR~
	    	if (Popt & XEFTP_TEST)                                 //~v54pI~
            	opt|=UFTPO_KEEPWD;  //keep workdir                 //~v54pI~
        }                                                          //~v53UI~
      if (Phostsfnm)                                               //~v54nI~
    	filefullpath(fpathhosts,Phostsfnm,sizeof(fpathhosts));     //~v54nI~
      else                                                         //~v54nI~
    	filefullpath(fpathhosts,FTPHOSTS,sizeof(fpathhosts));      //~v53UR~
        Gxehostsfnm=umalloc(strlen(fpathhosts)+1);                 //~vaneI~
        strcpy(Gxehostsfnm,fpathhosts);                            //~vaneI~
        UTRACEP("xeftpinit xehosts=%s\n",Gxehostsfnm);             //~vaneI~
                                                                   //~v54nI~
    	fileopencreate(FOCO_CLOSE,fpathhosts,"r",FTPHOSTS_DUMMY_RECORD); //fileopen issue not found err,if not found create dummy//+vb89R~
                                                                   //~vb89I~
    	filefullpath(fpathlog,FTPLOG,sizeof(fpathlog));            //~v53UR~
        filefullpath(Sfpathwd,FTPWKDIR,sizeof(Sfpathwd));          //~v53UR~
//      Sfpathwdlen=strlen(Sfpathwd);                              //~v53UI~//~vb30R~
        Sfpathwdlen=(int)strlen(Sfpathwd);                         //~vb30I~
//      if (rc=ufstat(Sfpathwd,&fstat3),rc)                        //~v53UR~//~vb30R~
        if (rc=(int)ufstat(Sfpathwd,&fstat3),rc)                   //~vb30I~
            rc=umkdir(Sfpathwd);                                   //~v53UR~
        else                                                       //~v53UR~
        {                                                          //~v53UR~
            if (!(fstat3.attrFile & FILE_DIRECTORY))               //~v53UR~
            {                                                      //~v53UR~
                uerrmsg("same name file exist as FTP work dir(%s)",0,//~v53UR~
                        Sfpathwd);                                 //~v53UR~
                rc=4;                                              //~v53UR~
            }                                                      //~v53UR~
        }                                                          //~v53UR~
        if (rc)                                                    //~v53UI~
        {                                                          //~v53UI~
    		opt=UFTPO_NOP;                                         //~v53UI~
            UCBITON(Gopt,GOPTNOFTP);                               //~v53UI~
        }                                                          //~v53UI~
    }//use parm                                                    //~v53UI~
//  if (rc=uftpinit(opt,fpathlog,fpathhosts),rc)                   //~v55oR~
//  if (rc=uftpinit(opt,fpathlog,fpathhosts,pclientpgm),!rc)       //~v70zR~
    rc=uftpinit(opt,fpathlog,fpathhosts,pclientpgm);               //~v70zI~
    if (!(Gftpopt & GFTPO_AVAIL))                                  //~v70zI~
    	UCBITON(Gopt,GOPTNOFTP);                                   //~v53UM~
    xetsoinit(Popt);                                               //~v70zR~
    return rc;                                                     //~v53UI~
}//xeftpinit                                                       //~v53UI~
//**************************************************************** //~v53UI~
//* keep hots data at file save                                    //~v53UI~
//* parm1 :pfh                                                     //~v53UI~
//* retrn:rc UALLOC_FAILED or 4                                    //~v53UI~
//**************************************************************** //~v53UI~
int xeftpterm(void)                                                //~v53UI~
{                                                                  //~v53UI~
//*****************                                                //~v53UI~
//  uftpnodeclear();                                               //~v55oR~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
    if (*Sfpathdndwd)                                              //~v63jI~
		xeftpdelwd(0,Sfpathdndwd);                                 //~v63jI~
#endif                                                             //~v63jI~
    uftpterm();                                                    //~v55oI~
    if (Gxehostsfnm)                                               //~vaneI~
        ufree(Gxehostsfnm);                                        //~vaneI~
    return 0;                                                      //~v53UI~
}//xeftpterm                                                       //~v53UI~
//****************************************************************
//* keep host data at file save                                    //~v70zR~
//* parm1 :pfh
//* retrn:rc UALLOC_FAILED or 4                                    //~v53UR~
//****************************************************************
int xeftphostsget(PUCLIENTWE Ppcw,PUFILEH Ppfh)                    //~v53UR~
{
	PULINEH    	plh,plherr=0;
//  UFTPHOST    ufh,*pufh,*pufhdup=0,*pufho;                       //~v60cR~
    UFTPHOST    ufh,*pufh,*pufho;                                  //~v60cI~
    UQUEH       ufhqh={0,0,0,0},*pqh,qhold;                        //~v53UI~
    int rc=0,rc2,duperr=0;                                         //~v53UR~
    int opt;                                                       //~vaneI~
//*****************
	Sftpinitsw=1;	//once file is loaded                          //~v53UI~
//get host data                                                    //~v53UI~
	plh=UGETQTOP(&Ppfh->UFHlineque);
    for (;plh;plh=UGETQNEXT(plh))
    {
    	if (plh->ULHtype!=ULHTDATA)
        	continue;
//      rc2=uftpgethostsdata(plh->ULHdata,plh->ULHlen,&ufh);       //~v53UR~//~vaneR~
		opt=0;                                                     //~vaneI~
		if (UCBITCHK(plh->ULHflag2,ULHF2INSERT))                   //~vaneI~
	        opt=UFGHDO_CLEAR_ENCPSWD;                              //~vaneR~
        else                                                       //~vaneI~
        if (plh->ULHupctr)                                         //~vaneI~
        {                                                          //~vaneI~
            if (pufho=uftpnodesrch(ufh.UFTPHhost),pufho)           //~vaneI~
                if (pufho->UFTPHflag & UFTPHFPSWDENC) //pswd was encrypted at load//~vaneI~
	        		opt=UFGHDO_CLEAR_ENCPSWD; //need clear if encrypted//~vaneI~
        }                                                          //~vaneI~
                                                                   //~vaneI~
        rc2=uftpgethostsdata(opt,plh->ULHdata,plh->ULHlen,&ufh);   //~vaneI~
        if (rc2==1)  	//comment line                             //~v53UI~
        	continue;                                              //~v53UI~
        if (!rc2)                                                  //~v53UI~
        {                                                          //~v53UI~
    		pufh=umalloc(UFTPHOSTSZ);                              //~v53UI~
        	UALLOCCHK(pufh,UALLOC_FAILED);                         //~v53UI~
        	memcpy(pufh,&ufh,UFTPHOSTSZ);                          //~v53UI~
            if (pufho=uftpnodesrch(ufh.UFTPHhost),pufho)           //~v53UI~
            {                                                      //~vac0R~
            	memcpy(pufh->UFTPHhost,pufho->UFTPHhost,sizeof(pufh->UFTPHhost));//keep cur dir//~v53UI~
                if (pufho->UFTPHflag & UFTPHFMEMPSWD)   //volatile pswd was set//~vac0R~
            		memcpy(pufh->UFTPHpswd,pufho->UFTPHpswd,sizeof(pufh->UFTPHpswd));//keep volatile setting by node cmd//~vac0R~
            }                                                      //~vac0R~
	        UENQ(UQUE_END,&ufhqh,pufh);                            //~v53UI~
            continue;                                              //~v53UI~
        }                                                          //~v53UI~
        rc=4;                                                      //~v53UI~
        filesetlineerr(plh);    //lineno fld reverse hilight       //~v53UI~
        if (!plherr)                                               //~v53UI~
        {                                                          //~v53UI~
            plherr=plh;                                            //~v53UI~
            fcmdscrollpage(Ppcw,plherr);                           //~v53UI~
            filesetcsr(Ppcw,plherr,0,0);    //set csr,fldtop       //~v53UI~
        }                                                          //~v53UI~
	}//no errchk
//enq to hostq                                                     //~v53UI~
    if (rc)                                                        //~v53UI~
    	UQUFREE(&ufhqh);                                           //~v554R~
    else                                                           //~v53UI~
    {                                                              //~v53UI~
    	pqh=uftpgethostqhaddr();                                   //~v53UR~
        memcpy(&qhold,pqh,sizeof(qhold));	//save old qh          //~v53UI~
        memset(pqh,0,sizeof(qhold));		//clear to dup test enq//~v53UI~
        for (pufh=UGETQTOP(&ufhqh);pufh;pufh=UGETQNEXT(pufh))      //~v53UI~
        {                                                          //~v53UI~
            rc2=uftpnodeadd(pufh);                                 //~v54pR~
            if (rc2==UALLOC_FAILED)                                //~v53UI~
            {                                                      //~v53UI~
            	rc=rc2;                                            //~v53UI~
                break;                                             //~v53UI~
            }                                                      //~v53UI~
            if (rc2)                                               //~v53UI~
            {                                                      //~v53UI~
            	if (!duperr)                                       //~v53UI~
                {                                                  //~v53UI~
                	duperr=1;                                      //~v53UI~
        			uerrmsg("hostid %s is duplicated",             //~v53UI~
        	        		"ホスト %s が重複",                    //~v53UI~
//                  		pufhdup->UFTPHhost);                   //~v60cR~
                    		pufh->UFTPHhost);                      //~v60cI~
                    rc=4;                                          //~v53UI~
                }                                                  //~v53UI~
            }                                                      //~v53UI~
        }                                                          //~v53UI~
        if (rc)                                                    //~v53UI~
        {                                                          //~v53UI~
	    	UQUFREE(pqh);						//free new added   //~v60cI~
	        memcpy(pqh,&qhold,sizeof(qhold));	//restore old qh   //~v53UI~
	    	UQUFREE(&ufhqh);						//free new of err//~v554R~
        }                                                          //~v53UI~
        else                                                       //~v53UI~
        {                                                          //~v554I~
	    	UQUFREE(&qhold);						//free old     //~v554R~
    		UQUFREE(&ufhqh);//addnode is enq copy,ufhqh should be cleared//~v554I~
        }                                                          //~v554I~
    }                                                              //~v53UI~
    return rc;                                                     //~v53UR~
}//xeftphostsget                                                   //~v53UR~
//**************************************************************** //~v53UI~
//* download file to ftp workdir                                   //~v53UR~
//* parm1 :pfh                                                     //~v53UI~
//* retrn:rc UALLOC_FAILED or 4                                    //~v53UI~
//**************************************************************** //~v53UI~
//int xeftpget(PUFTPHOST Ppuftph,char *Prfname)                    //~v576R~
//int xeftpget(PUFTPHOST Ppuftph,char *Prfname,char *Ptmplocalfnm) //~v70zR~
//int xeftpget(int Popt,PUFTPHOST Ppuftph,char *Prfname,char *Ptmplocalfnm)//~v8@sR~
int xeftpget(int Popt,PUFTPHOST Ppuftph,char *Prfname,char *Ptmplocalfnm,/*PUTSOFTPPARM*/ void *Pptsop)//~v8@sI~
{                                                                  //~v53UI~
    int opt,rc,pathlen;                                            //~v576R~
//  char *pc,wdfname[_MAX_PATH];                                   //~v576I~//~vb7eR~
    char *pc,wdfname[_MAX_PATH2];                                  //~vb7eI~
//*****************                                                //~v53UI~
	opt=DCPY_FTPCOPYFTIMEY|DCPY_EXISTING;                          //~v53UI~
  	if (UFTPHISTSO(Ppuftph))   //host is tso                       //~v70zR~
//  	return xetsoxcopy(Popt,Ppuftph,0,Prfname,Ptmplocalfnm,opt,FILE_ALL-FILE_DIRECTORY);//~v8@sR~
    	return xetsoxcopy(Popt,Ppuftph,0,Prfname,Ptmplocalfnm,opt,FILE_ALL-FILE_DIRECTORY,Pptsop);//~v8@sI~
  if (Popt & XEFTPO_2TEMPF)            //get to local temp file directory//~vb7eI~
  {                                                                //~vb7eI~
	opt|=DCPY_FTP2TEMPF;                                           //~vb7eI~
	rc=uftpxcopy(Ppuftph,0,Prfname,Ptmplocalfnm,opt,FILE_ALL-FILE_DIRECTORY);//~vb7eI~
  }                                                                //~vb7eI~
  else                                                             //~vb7eI~
	rc=uftpxcopy(Ppuftph,0,Prfname,Sfpathwd,opt,FILE_ALL-FILE_DIRECTORY);//~v54pR~
    if (rc)                                                        //~v53UI~
		return rc;                                                 //~v53UI~
  if (Popt & XEFTPO_2TEMPF)            //get to local temp file directory//~vb7eI~
  	UTRACEP("%s:direct get to remp:%s",UTT,Ptmplocalfnm);          //~vb7eI~
  else                                                             //~vb7eI~
  {                                                                //~vb7eI~
//  memcpy(wdfname,Sfpathwd,Sfpathwdlen);   //allow in,out parm override//~v576I~//~vb30R~
    memcpy(wdfname,Sfpathwd,(size_t)Sfpathwdlen);   //allow in,out parm override//~vb30I~
    pc=wdfname+Sfpathwdlen;                                        //~v576I~
    *pc++=DIR_SEPC;                                                //~v576I~
    pathlen=FTP_PATHLEN(Prfname);                                  //~v576I~
    strcpy(pc,Prfname+pathlen);//source filename                   //~v576R~
    if (urename(wdfname,Ptmplocalfnm,0))//avoid dup name           //~v576R~
    	return 4;                                                  //~v576I~
  }                                                                //~vb7eI~
    return 0;                                                      //~v53UI~
}//xeftpget                                                        //~v53UR~
//**************************************************************** //~v53UI~
//* upload file to remote                                          //~v53UI~
//* parm1 :pfh                                                     //~v53UI~
//* retrn:rc UALLOC_FAILED or 4                                    //~v53UI~
//**************************************************************** //~v53UI~
int xeftpsave(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)               //~v53UI~
{                                                                  //~v53UI~
//  char *sfnm,tfnm[_MAX_PATH];                                    //~v53UR~//~vb7eR~
    char *sfnm,tfnm[FTP_MAXPATH];                                  //~vb7eI~
    int opt,rc;                                                    //~v576R~
    int tsoopt;                                                    //~v72nI~
//  int rootpos;                                                   //~v576R~
//*****************                                                //~v53UI~
	strcpy(tfnm,Ppfh->UFHfilename);                                //~v53UR~
    if (Popt & XEFTPSO_UPDATECHKONLY)//update chk                  //~v53UR~
    {                                                              //~v53UI~
//        rc=ufstat(tfnm,&fstat3);                                 //~v54UR~
//        if (rc)                                                  //~v54UR~
//        {                                                        //~v54UR~
//            if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                 //~v54UR~
//                rc=0;//ok if not exist                           //~v54UR~
//        }                                                        //~v54UR~
//        else    //found                                          //~v54UR~
//        {                                                        //~v54UR~
//            if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                 //~v54UR~
//                rc=1;//someone saved                             //~v54UR~
//            else                                                 //~v54UR~
//            if (*fstat3.slink)                                   //~v54UR~
//                rc=memcmp(&(fstat3.slinkfdate),&(Ppfh->UFHfiledate),sizeof(FDATE))//~v54UR~
//                  |memcmp(&(fstat3.slinkftime),&(Ppfh->UFHfiletime),sizeof(FTIME));//~v54UR~
//            else                                                 //~v54UR~
//                rc=memcmp(&(fstat3.fdateLastWrite),&(Ppfh->UFHfiledate),sizeof(FDATE))//~v54UR~
//                  |memcmp(&(fstat3.ftimeLastWrite),&(Ppfh->UFHfiletime),sizeof(FTIME));//~v54UR~
//        }                                                        //~v54UR~
//        if (rc)                                                  //~v54UR~
//        {                                                        //~v54UR~
//            uerrmsg("%s is changed",0,                           //~v54UR~
//                    tfnm);                                       //~v54UR~
//            return 8;                                            //~v54UR~
//        }                                                        //~v54UR~
//        return 0;                                                //~v54UR~
		return xefsubupdatechk(Ppcw,Ppfh);                         //~v54UI~
    }                                                              //~v53UI~
	sfnm=Ppfh->UFHftpwdfnm;	//get source filename on ftp wkdir     //~v53UR~
//  tpathlen=FTP_PATHLEN(tfnm);                                    //~v576R~
//  *(tfnm+tpathlen)=0;				//target dir                   //~v576R~
//  if (!FTP_ROOTDIR(tfnm))                                        //~v577R~
//  rootpos=((PUFTPHOST)(Ppfh->UFHpuftph))->UFTPHhostnmlen+1;      //~v576R~
//  if (!FTP_ROOTDIR(tfnm+rootpos))                                //~v576R~
//  	*(tfnm+tpathlen-1)=0;                                      //~v576R~
	opt=DCPY_EXISTING;                                             //~v53UI~
    if (Popt & XEFTPSO_APPEND)                                     //~v57KI~
		opt|=DCPY_APPEND;                                          //~v57KI~
  if (UFTPHISTSO( ((PUFTPHOST)(Ppfh->UFHpuftph)) ))   //host is tso//~v70zR~
  {                                                                //~v72nI~
  	tsoopt=0;                                                      //~v72nI~
    if (Popt & XEFTPSO_OUTFILE)                                    //~v72nI~
    	tsoopt|=XETSOSO_OUTFILE;                                   //~v72nR~
    if (Popt & XEFTPSO_OUTPARTIAL)                                 //~v72nI~
    	tsoopt|=XETSOSO_OUTPARTIAL;                                //~v72nI~
//	rc=xetsoxcopy(0,0,(PUFTPHOST)(Ppfh->UFHpuftph),sfnm,tfnm,opt,FILE_ALL-FILE_DIRECTORY);//~v710R~
//  rc=xetsosave(0,Ppfh,(PUFTPHOST)(Ppfh->UFHpuftph),sfnm,tfnm,opt,FILE_ALL-FILE_DIRECTORY);//~v72nR~
    rc=xetsosave(tsoopt,Ppfh,(PUFTPHOST)(Ppfh->UFHpuftph),sfnm,tfnm,opt,FILE_ALL-FILE_DIRECTORY);//~v72nI~
  }                                                                //~v72nI~
  else                                                             //~v70zI~
	rc=uftpxcopy(0,(PUFTPHOST)(Ppfh->UFHpuftph),sfnm,tfnm,opt,FILE_ALL-FILE_DIRECTORY);//~v54pR~
    if (rc)                                                        //~v53UI~
    {                                                              //~v71RI~
        UCBITON(Ppfh->UFHflag,UFHFWRITEERR);    //dont delete at closefree//~v71RI~
		return 4;                                                  //~v57sR~
    }                                                              //~v71RI~
    else                                                           //~v71RI~
        UCBITOFF(Ppfh->UFHflag,UFHFWRITEERR);    //reset save err  //~v71RI~
    if (Popt & XEFTPSO_DELTEMP)                                    //~v710I~
		xeftpdelwd(0,sfnm);                                        //~v710I~
    return 0;                                                      //~v53UI~
}//xeftpsave                                                       //~v53UI~
//**************************************************************** //~v53UI~
//* get filename on ftp work dir                                   //~v53UI~
//* parm1 :in,remote filename                                      //~v53UI~
//* parm2 :out;ptr of char ptr;input ptr=0 if umalloc output       //~v53UR~
//* retrn:pathlen                                                  //~v53UR~
//**************************************************************** //~v53UI~
//int xeftpgetwdfname(char *Pfname,char *Pwdfname)                 //~v70zR~
//int xeftpgetwdfname(PUFTPHOST Ppuftph,char *Pfname,char *Pwdfname) //~v70zR~//~vb7eR~
int xeftpgetwdfname(PUFTPHOST Ppuftph,char *Pfname,char *Pwdfname,size_t Pbuffsz)//~vb7eR~
{                                                                  //~v53UI~
    int pathlen,fnmlen;                                            //~v577R~
//  char wdfname[_MAX_PATH];                                       //~v53UI~//~vb7eR~
    char wdfname[FTP_MAXPATH2];  //longer by FTP prefix            //~vb7eR~
    char *pc;                                                      //~v577R~
    int hostnmlen;                                                 //~vb7eI~
//*****************                                                //~v53UI~
//  memcpy(wdfname,Sfpathwd,Sfpathwdlen);   //allow in,out parm override//~v53UR~//~vb30R~
    memcpy(wdfname,Sfpathwd,(size_t)Sfpathwdlen);   //allow in,out parm override//~vb30I~
//  *(wdfname+Sfpathwdlen)=DIR_SEPC;                               //~v577R~
    pc=wdfname+Sfpathwdlen;                                        //~v577I~
    *pc++=DIR_SEPC;                                                //~v577I~
  if (UFTPHISTSO(Ppuftph))   //host is tso                         //~v70zR~
  {                                                                //~v70zI~
  	fnmlen=u3270getmembname(U3GM_DUMMYREP,Pfname,pc);	//1:supply dummy if member not specified//~v70zR~
  }                                                                //~v70zI~
  else                                                             //~v70zI~
  {                                                                //~v70zI~
    pathlen=FTP_PATHLEN(Pfname);                                   //~v53UI~
//  strcpy(wdfname+Sfpathwdlen+1,Pfname+pathlen);//source filename //~v577R~
//  fnmlen=strlen(Pfname+pathlen);//source filename                //~v577I~//~vb30R~
//  fnmlen=(int)strlen(Pfname+pathlen);//source filename           //~vb30I~//~vb7eR~
//  memcpy(pc,Pfname+pathlen,(UINT)fnmlen);//source filename       //~v577I~//~vb7eR~
    hostnmlen=Ppuftph->UFTPHhostnmlen;                             //~vb7eI~
    memcpy(pc,Pfname,(size_t)hostnmlen);                           //~vb7eI~
    pc+=hostnmlen;                                                 //~vb7eI~
    *pc++='.';                                                     //~vb7eI~
	dlcUndelPrepRenameLongname(DLCYRLO_NOFSTAT,Pfname+pathlen,pc,0/*tgtpos*/,(int)sizeof(wdfname)-PTRDIFF(pc,wdfname));//~vb7eR~
    fnmlen=(int)strlen(pc);                                        //~vb7eR~
  }                                                                //~v70zI~
    pc+=fnmlen;                                                    //~v577I~
    *pc++='.';                                                     //~v577I~
    utimeedit(FTP_WDSUFFIX,pc);                                    //~v576R~
//  *(pc+13)=0;                                                    //~v712R~
    *(pc+sizeof(FTP_WDSUFFIX)-1)=0;                                //~v712R~
//  strcpy(Pwdfname,wdfname);     //in/out may overwrap            //~v53UR~//~vb7eR~
    UstrncpyZ(Pwdfname,wdfname,Pbuffsz);     //in/out may overwrap //~vb7eI~
    UMAXPATHCHK(wdfname,Pbuffsz,-1/*rc*/,1/*msgsw*/);              //~vb7eR~
    return Sfpathwdlen+1;                                          //~v53UR~
}//xeftpgetwdfname                                                 //~v53UI~
//**************************************************************** //~v76pI~
//* get filename on ftp work dir from fullpath name                //~v76pI~
//* parm1 :in,remote filename                                      //~v76pI~
//* parm2 :out;ptr of char ptr;input ptr=0 if umalloc output       //~v76pI~
//* retrn:pathlen                                                  //~v76pI~
//**************************************************************** //~v76pI~
//int xeftpgetwdfname2(int Popt,char *Pfname,char *Pwdfname)         //~v76pI~//~vb7eR~
int xeftpgetwdfname2(int Popt,char *Pfname,char *Pwdfname,size_t Pbuffsz)//~vb7eR~
{                                                                  //~v76pI~
    int len1,len2,len;                                             //~v76pR~
    char wdfname[_MAX_PATH*3];                                     //~v76pI~
    char *pc;                                                      //~v76pI~
//*****************                                                //~v76pI~
//  memcpy(wdfname,Sfpathwd,Sfpathwdlen);   //allow in,out parm override//~v76pI~//~vb30R~
    memcpy(wdfname,Sfpathwd,(size_t)Sfpathwdlen);   //allow in,out parm override//~vb30I~
    pc=wdfname+Sfpathwdlen;                                        //~v76pI~
    *pc++=DIR_SEPC;                                                //~v76pI~
    pc+=ufilefullpathtemp(0,Pfname,pc);                            //~v76pI~
    *pc++='.';                                                     //~v76pI~
    utimeedit(FTP_WDSUFFIX,pc);                                    //~v76pI~
    pc+=sizeof(FTP_WDSUFFIX)-1;                                    //~v76pI~
    *pc++=0;                                                       //~v76pI~
//  len=(int)((ULONG)pc-(ULONG)wdfname);                           //~v76pI~//~vafkR~
    len=(int)((ULPTR)pc-(ULPTR)wdfname);                           //~vafkI~
    if (len>_MAX_PATH)                                             //~v76pI~
    {                                                              //~v76pI~
    	len1=Sfpathwdlen+1;                                        //~v76pI~
    	len2=_MAX_PATH-len1;                                       //~v76pI~
        memcpy(wdfname+len1,wdfname+len-len2,(UINT)len2);          //~v76pI~
    }                                                              //~v76pI~
//  strcpy(Pwdfname,wdfname);     //in/out may overwrap            //~v76pI~//~vb7eR~
    UstrncpyZ(Pwdfname,wdfname,Pbuffsz);     //in/out may overwrap //~vb7eI~
    UMAXPATHCHK(wdfname,Pbuffsz,-1/*rc*/,1/*msgsw*/);              //~vb7eI~
//  return strlen(Pwdfname);                                       //~v76pI~//~vb30R~
    return (int)strlen(Pwdfname);                                  //~vb30I~
}//xeftpgetwdfname2                                                //~v76pI~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
//**************************************************************** //~v63jI~
//* get remote file dragdrop work dir name                         //~v63jI~
//* retrn:rc                                                       //~v63jI~
//**************************************************************** //~v63jI~
int xeftpgetdndwd(char *Pwdfname)                                  //~v63jI~
{                                                                  //~v63jI~
    FILEFINDBUF3 fstat3;                                           //~v63jI~
    int rc=0;                                                      //~v63jR~
//*****************                                                //~v63jI~
	if (!*Sfpathdndwd)	//1st time                                 //~v63jI~
    {                                                              //~v63jI~
		filefullpath(Sfpathdndwd,FTPDNDWKDIR,sizeof(Sfpathwd));    //~v63jI~
        sprintf(Sfpathdndwd+strlen(Sfpathdndwd),".%lu",ugetpid()); //~v63jI~
//      if (rc=ufstat(Sfpathdndwd,&fstat3),rc)                     //~v63jI~//~vb30R~
        if (rc=(int)ufstat(Sfpathdndwd,&fstat3),rc)                //~vb30I~
            rc=umkdir(Sfpathdndwd);                                //~v63jI~
        else                                                       //~v63jI~
        {                                                          //~v63jI~
            if (!(fstat3.attrFile & FILE_DIRECTORY))               //~v63jI~
            {                                                      //~v63jI~
                uerrmsg("same name file exist as FTP work dir(%s)",0,//~v63jI~
                        Sfpathdndwd);                              //~v63jI~
                rc=4;                                              //~v63jI~
            }                                                      //~v63jI~
        }                                                          //~v63jI~
    }                                                              //~v63jI~
    if (rc)                                                        //~v63jI~
    {                                                              //~v63jI~
    	*Sfpathdndwd=0;	//re-init required                         //~v63jR~
    	return rc;                                                 //~v63jR~
    }                                                              //~v63jI~
    strcpy(Pwdfname,Sfpathdndwd);                                  //~v63jI~
    return 0;                                                      //~v63jI~
}//xeftpgetdndwd                                                   //~v63jI~
#endif                                                             //~v63jI~
//**************************************************************** //~v576I~
//* delete temp dir                                                //~v576I~
//* retrn:rc                                                       //~v576I~
//**************************************************************** //~v576I~
int xeftpdelwd(int Popt,char *Pwdfname)                            //~v576I~
{                                                                  //~v576I~
    int procctr=0,ronlyctr=0,delctr=0,rc;                          //~v576R~
    char *pfnm;                                                    //~v577R~
//*****************                                                //~v576I~
    pfnm=Pwdfname;                                                 //~v577R~
UTRACEP("xeftpdelwd %s\n",Pwdfname);                               //~v8@sI~
	rc=uxdelete(pfnm,UXDELDIR,UXDELFORCE,&procctr,&ronlyctr,&delctr);//~v576I~
    return rc;                                                     //~v576I~
}//xeftpdelwd                                                      //~v576I~
//**************************************************************** //~v57sI~
//!xeftpgetremotecopy                                              //~v59dR~
//  remote file download to temp file                              //~v57sI~
//**************************************************************** //~v57sI~
//int xeftpgetremotecopy(int Popt,char *Ppfile,PUFTPHOST Ppuftph,char *Pouttmpf)//~v8@sR~
//int xeftpgetremotecopy(int Popt,char *Ppfile,PUFTPHOST Ppuftph,char *Pouttmpf,void *Pparm)//~v8@sR~//~vb7eR~
int xeftpgetremotecopy(int Popt,char *Ppfile,PUFTPHOST Ppuftph,char *Pouttmpf,size_t Pbuffsz,void *Pparm)//~vb7eI~
{                                                                  //~v57sI~
    int opt;                                                       //~v57sR~
    int attr;                                                      //~v63jI~
    int opt2;                                                      //~v8@sI~
    UTSOFTPPARM tsop;                                              //~v8@sI~
//**********************                                           //~v57sI~
	if (Popt & XEFTP_GRC_DEFDIR2)	//temp filename not specified  //~v76pI~
//  	xeftpgetwdfname2(0,Ppfile,Pouttmpf);                       //~v76pI~//~vb7eR~
    	xeftpgetwdfname2(0,Ppfile,Pouttmpf,Pbuffsz);               //~vb7eI~
    else                                                           //~v76pI~
	if (Popt & XEFTP_GRC_DEFDIR)	//temp filename not specified  //~v57sR~
//  	xeftpgetwdfname(Ppfile,Pouttmpf);                          //~v70zR~
//  	xeftpgetwdfname(Ppuftph,Ppfile,Pouttmpf);                  //~v70zI~//~vb7eR~
    	if (xeftpgetwdfname(Ppuftph,Ppfile,Pouttmpf,Pbuffsz)<0)	//longname//~vb7eI~
            return 4;                                              //~vb7eI~
	if (Popt & XEFTP_GRC_CHKNORMAL)	//chk remote is normal file    //~v76pI~
    {                                                              //~v76pI~
    	if (ufileisnormalfile(FINF_ERRMSGALL,Ppuftph,Ppfile))	//found//~v76pR~
            return 4;                                              //~v76pR~
    }                                                              //~v76pI~
	opt=DCPY_FTPCOPYFTIMEY|DCPY_EXISTING;                          //~v57sI~
    if (Popt & XEFTP_GRC_SUBDIR)                                   //~v57sR~
    	opt|=DCPY_CREATE;		//create dir                       //~v57sI~
    if (Popt & XEFTP_GRC_SUBDIRCOPY)                               //~v63jI~
    	attr=FILE_ALL;                                             //~v63jI~
    else                                                           //~v63jI~
    	attr=FILE_ALL-FILE_DIRECTORY;                              //~v63jI~
    if (UFTPHISTSO(Ppuftph))   //host is tso                       //~v70zI~
    {                                                              //~v8@sI~
    	opt2=XETSOFTPO_DBCSCONV;                                   //~v8@sR~
    	if (Popt & XEFTP_GRC_FFB3)                                 //~v8@sI~
        	opt2|=XETSOFTPO_FFB3;                                  //~v8@sI~
        else                                                       //~v8@sI~
    	if (Popt & XEFTP_GRC_FPATH)                                //~v8@sR~
        	opt2|=XETSOFTPO_FPATH;                                 //~v8@sI~
        xetsosetftpparm(opt2,Ppuftph,&tsop,Pparm);                 //~v8@sR~
//      if (Popt & XEFTP_GRC_PARMFILE)  //support only normal file //~v71gR~
//  		return xetsoxcopy(0,Ppuftph,0,Ppfile,Pouttmpf,opt,attr);//~v71gR~
//  	return xetsoxcopy(Popt,Ppuftph,0,Ppfile,Pouttmpf,opt,attr);//~v8@sR~
//  	return xetsoxcopy(Popt,Ppuftph,0,Ppfile,Pouttmpf,opt,attr,&tsop);//~v8@sR~//~vb30R~
    	return xetsoxcopy(Popt,Ppuftph,0,Ppfile,Pouttmpf,opt,(unsigned)attr,&tsop);//~vb30I~
    }                                                              //~v8@sI~
//UTRACEP("ftpcopy %s\n",Ppfile);                                  //~v64aI~
//  if (uftpxcopy(Ppuftph,0,Ppfile,Pouttmpf,opt,FILE_ALL-FILE_DIRECTORY))//~v63jR~
//  if (uftpxcopy(Ppuftph,0,Ppfile,Pouttmpf,opt,attr))             //~v63jI~//~vb30R~
    if (uftpxcopy(Ppuftph,0,Ppfile,Pouttmpf,opt,(unsigned)attr))   //~vb30I~
    	return 4;	//avoid -1                                     //~v57sI~
    return 0;                                                      //~v57sR~
}//xeftpgetremotecopy                                              //~v57sI~
//**************************************************************** //~v59dI~
//!xeftplog                                                        //~v59dI~
//  log from pfh or local file                                     //~v59dI~
//p3:src filename:0 if write from pufileh,else local filename to be uploaded//~v59dI~
//**************************************************************** //~v59dI~
int xeftplog(int Popt,PUFILEH Ppfh,char *Psrcfnm,char *Ptmpfnm)    //~v59dI~
{                                                                  //~v59dI~
    FILE *fh;                                                      //~v59dI~
    PULINEH plh;                                                   //~v59dI~
	int  len;                                                      //~v59dR~
//  char *psrc,logbuff[_MAX_PATH+_MAX_PATH+80],buff[MAXLINEDATA];  //~v59dI~//~vb7eR~
    char *psrc,logbuff[FTP_MAXPATH2+80],buff[MAXLINEDATA];         //~vb7eR~
//**********************                                           //~v59dI~
	if (!(psrc=Psrcfnm))                                           //~v59dR~
    	psrc=Ppfh->UFHfilename;                                    //~v59dI~
	sprintf(logbuff,"rsh by ftp'ed temp file:src=%s,tmp=%s\n",psrc,Ptmpfnm);//~v59dI~
    uftplog(FTPLOG_REQ,logbuff);                                   //~v59dI~
    *(buff+sizeof(buff)-1)=0;                                      //~v59dI~
    if (Psrcfnm)	//log from localfile                           //~v59dR~
    {                                                              //~v59dI~
    	if (!(fh=fileopen(Psrcfnm,"r")))                           //~v59dR~
        	return 8;                                              //~v59dI~
		while (fgets(buff,sizeof(buff)-1,fh))                      //~v59dI~
        	uftplog(FTPLOG_ADDLF,buff);                            //~v59dI~
        fileclose(Psrcfnm,fh);                                     //~v59dR~
    }                                                              //~v59dI~
    else	//from plh                                             //~v59dI~
    {                                                              //~v59dI~
        for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))//~v59dI~
        {                                                          //~v59dI~
            if (plh->ULHtype!=ULHTDATA) //file data                //~v59dI~
                continue;                                          //~v59dI~
            if (!plh->ULHdbcs)                                     //~v59dI~
            {                                                      //~v59dI~
                if (filechktabdbcs(plh)==UALLOC_FAILED)//expand before compare//~v59dI~
                    return UALLOC_FAILED;                          //~v59dI~
            }                                                      //~v59dI~
//          len=min(sizeof(buff)-1,plh->ULHlen);                   //~v59dI~//~vb30R~
            len=min((int)sizeof(buff)-1,plh->ULHlen);              //~vb30I~
            memcpy(buff,plh->ULHdata,(UINT)len);                   //~v59dI~
            *(buff+len)=0;                                         //~v59dI~
        	uftplog(FTPLOG_ADDLF,buff);                            //~v59dI~
        }//all line                                                //~v59dI~
    }                                                              //~v59dI~
    return 0;                                                      //~v59dI~
}//xeftplog                                                        //~v59dI~
//**************************************************************** //~v62hI~
// fast path rename                                                //~v62hI~
//*parm1:fpath from hostname                                       //~v62hI~
//*parm2:new member name                                           //~v62hI~
//*rc    :1:added,0:not target(dir entry)                          //~v62hI~
//**************************************************************** //~v62hI~
int xeftprename(PUFTPHOST Ppuftph,char *Pfpathold,char *Pnewmemb)  //~v62hI~
{                                                                  //~v62hI~
    UFTPMULTIRENAME fmr;                                           //~v62hI~
    int rc;                                                        //~v62hI~
//*********************                                            //~v62hI~
    fmr.UFMRpfpath=Pfpathold+Ppuftph->UFTPHhostnmlen+1;            //~v62hI~
    fmr.UFMRpnewname=Pnewmemb;                                     //~v62hR~
    fmr.UFMRattr=0;                                                //~v62hI~
    fmr.UFMRparm=0;                                                //~v62hI~
    rc=uftpmultirename(0,Ppuftph,&fmr,1,0);                        //~v62hI~
    if (rc)                                                        //~v62hI~
    	return rc;                                                 //~v62hI~
    rc=fmr.UFMRrc;                                                 //~v62hR~
    return rc;                                                     //~v62hI~
}//xeftprename                                                     //~vac0R~
//**************************************************************** //~vac0R~
int func_node_help(PUCLIENTWE Ppcw)                                //~vac0R~
{                                                                  //~vac0R~
#ifdef ARMXXE                                                      //~vac6I~
	uerrmsg("NODe nodeid [password] (connection test[set volatile password])",0);//~vac6I~
#else                                                              //~vac6I~
	uerrmsg("NODe nodeid password (set volatile password)",0);     //~vac0R~
#endif                                                             //~vac6I~
    return 4;                                                      //~vac0R~
}//func_node_help                                                  //~vac0R~
//**************************************************************** //~vac0R~
// set UFTPHOST volatile pswd                                      //~vac0R~
//**************************************************************** //~vac0R~
int func_node(PUCLIENTWE Ppcw)                                     //~vac0R~
{                                                                  //~vac0R~
    int opdno,ii,posparmctr=0;                                     //~vac0R~
    char *pc,*nodeid=0,*pswd=0;                                    //~vac0R~
    PUFTPHOST pufh;                                                //~vac0R~
    int rc=0;                                                      //~vac6I~
    int len;                                                       //~vac6I~
//*********************************                                //~vac0R~
//*operand chk                                                     //~vac0R~
    opdno=Ppcw->UCWopdno;                                          //~vac0R~
    pc=Ppcw->UCWopdpot;                                            //~vac0R~
	if (!opdno)		//operand                                      //~vac0R~
    	return func_node_help(Ppcw);                               //~vac0R~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~vac0R~
	{                                                              //~vac0R~
    	switch(posparmctr++)                                       //~vac0R~
        {                                                          //~vac0R~
        case 0:                                                    //~vac0R~
            nodeid=pc;                                             //~vac0R~
            break;                                                 //~vac0R~
        case 1:                                                    //~vac0R~
            pswd=pc;                                               //~vac0R~
            break;                                                 //~vac0R~
        default:                                                   //~vac0R~
        	return errinvalid(pc);                                 //~vac0R~
        }                                                          //~vac0R~
    }//loop by operand no                                          //~vac0R~
#ifdef ARMXXE                                                      //~vac6I~
    if (!nodeid)                                                   //~vac6I~
#else                                                              //~vac6I~
    if (!nodeid||!pswd)                                            //~vac0R~
#endif                                                             //~vac6M~
    	return func_node_help(Ppcw);                               //~vac0R~
//  len=strlen(nodeid);                                            //~vac6I~//~vb30R~
    len=(int)strlen(nodeid);                                       //~vb30I~
    if (*(nodeid+len-1)==FTP_REMOTEID)                             //~vac6I~
        *(nodeid+len-1)=0;                                         //~vac6I~
    pufh=uftpnodesrch(nodeid);                                     //~vac0R~
    if (!pufh)                                                     //~vac0R~
    {                                                              //~vac0R~
    	uerrmsg("%s is not defined on xehosts",0,                  //~vac0R~
        		nodeid);                                           //~vac0R~
        return 4;                                                  //~vac0R~
    }                                                              //~vac0R~
  if (pswd)                                                        //~vac6I~
  {                                                                //~vac6I~
	uftp_mempswd(0,"",pufh,pswd);                                  //~vac0R~
	uerrmsg("volatile password:\"%s\" is asccepted for %s",0,      //~vac0R~
        		pswd,nodeid);                                      //~vac0R~
  }                                                                //~vac6I~
#ifdef ARMXXE                                                      //~vac6I~
    if (UFTPH_ISSMBJ(pufh))                                        //~vac6I~
        rc=uftp3smb_nodetest(0,pufh);                              //~vac6R~
#endif                                                             //~vac6I~
	return rc;                                                      //~vac0R~//~vac6R~
}//func_node                                                       //~vac0R~
