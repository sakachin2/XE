//*CID://+vb2sR~:                             update#=   92;       //~vb2sR~
//*************************************************************
//*xedlcmd5.c                                                      //~v0fpR~
//* sub of dlcmd2                                                  //~v0fqR~
//*************************************************************
//vb2s:160206 (Win)target err msg if slinkerr                      //~vb2sI~
//vb2o:160203 try to malloc UDHname for performance(#ifndef MMM)   //~vb2oI~
//vb21:160108 (BUG)UFHlinecmd was not cleared if line cmd cleared by "Del" key//~vb21I~
//            by dlcdelentry because ULHlinecmd==0x00.             //~vb21I~
//            So "sor s-" cmd call dlcdelentry but freeed entry remains on UFHcmdline.//~vb21I~
//            "Enter" after "sor s-" is unpredictable.             //~vb21I~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vb03:150312 (BUG)selected new reserved name file was not inserted to the dir list(unmatch by \\.\ prefix)//~vb03I~
//vb02:150312 (BUG)selected new file insert position was alaways top of all member//~vb02I~
//vazt:150114 (BUG)"UCHAR UFHpathlen" is invalid when _MAX_PATH>256//~vaztI~
//vave:140422 (Win;BUG of vava) UDHnameW is malloc area(Not have length of _MAX_PATH)//~vaveI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//            dirlist sortkey is ucs2                              //~vavaI~
//vav2:140401 (BUG)on UNC dirlist,localte cmd fail by invalid path //~vav2I~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//vagq:120910 confirm not to memcmp over allocate string           //~vagqI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          select insert compare by utf8name.(dirlist insert position search)//~va00I~
//v731:061226 filesize>4GB support                                 //~v71bI~
//v71b:061006 (BUG)udircomp required attr setup for both udirlist param to chk remote flag for strcmp not stricmp//~v71bI~
//v71a:061005 3270:dirlist:display filesize if once downloaded from localfile//~v71aI~
//v57h:040522 select new file;isrt new pdh entry according sort type//~v57hI~
//v57g:040522 support locate cmd for dirlist sorted by time/size   //~v57gI~
//v573:040503 dirlist refresh abend when entry count>100(access out of dirlist)//~v573I~
//v56t:040410 (FTP:BUG)It should be casesensitive for loacte/select//~v56tI~
//v54E:040121 (BUG)abend when err dlcmd pending on the plh which is deleted by unexpand cmd//~v54EI~
//v54s:040112 (BUG)abend,to be cleared freed dlcmd entry           //~v54sI~
//v54f:040104 (FTP)DIR_SEPx for ftp                                //~v54fI~
//v54e:040104 (UNX,FTP)dirlist:display slink size/ts when expanded bt f11//~v54eI~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v48f:020501 (BUG)dir refresh cmd delete last 3rd level entry when 3 level displayed//~v48fI~
//v30c:010102 AIX support:vc++ compare by unsigned when unsigned char and int.//~v30cI~
//            for ex. return true for (UCHAR)5<(int)-1.            //~v30cI~
//v20D:001103 LINUX support:filename compare is case sensitive     //~v20DI~
//v19X:000928 LINUX support(save uid/gid on UFILEH/UDIRH)          //~v19XI~
//v19y:000924 LINUX support(skip drive id chk for fullpath)        //~v19yI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v13n:991031 warning to doubled display for dir                   //~v13nI~
//v10t:990404 csr restore after view split end                     //~v10tI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0k1:980919 (BUG)windows allow filename ".aaa" or "..aaa"        //~v0k1I~
//v0fr:971109 dir list sort by fully for longname                  //~v0frI~
//v0fq:971109 new file by select cmd has alias but it is temporary name//~v0fqI~
//            it may duplicated alias name.                        //~v0fqI~
//            dont created new pdh if new,isrt at end file if new file.//~v0fqI~
//v0fp:971108 split dlcmd2-->dlcmd5.c                              //~v0fpI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32                                                         //~v71aI~
	#include <io.h>                                                //~v71aI~
#endif                                                             //~v71aI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>
#include <ufile.h>
#include <uftp.h>                                                  //~v71aI~
#include <u3270.h>                                                 //~v71aI~
#include <utrace.h>                                                //~vb02I~
#include <ufilew.h>                                                //~vb02I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile2.h"    //filesetcsr                               //~v0fpI~
#include "xefsub.h"     //ufilesetfhfilename                       //~v0fnI~
#include "xepan.h"
#include "xedir.h"
#include "xedir2.h"                                                //~v0fpI~
#include "xedlcmd.h"                                            //~v05oM~
#include "xedlcmd2.h"                                              //~v0fpI~
#include "xedlcmd5.h"                                              //~v0fpR~
#include "xecsr.h"                                                 //~v0fpI~
#include "xeerr.h"                                                 //~v0fpI~
#include "xesub.h"                                                 //~v0fpI~
#include "xefunc.h"                                                //~v0fpI~
#include "xetso.h"                                                 //~v71aI~
#include "xeutf2.h"                                                //~vb02I~
//*******************************************************
int  dlclvlmerge2(PUDIRLH Ppdh,PUDIRLIST Ppudirlist,PUDIRLH *Pppdh);//~v09wR~
int dlcfncomp(PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLIST Ppudirlist);     //~v0frR~
//PUDIRLH dlcpdhsrch(PUFILEH Ppfh,char *Pfullpath,PUDIRLH *Pppdhp);  //~v0fpI~//~vb03R~
int dlcisrtpdh(PUDIRLH Ppdhp,PUFILEH Ppfh,PUDIRLH *Pppdh);         //~v0fpI~
#ifdef W32UNICODE                                                  //~vb02I~
void dlcsetnameW(int Popt,PUDIRLIST Ppdl,PUFILEH Ppfh);            //~vb02I~
#endif                                                             //~vb02I~
//****************************************************************//~v04jI~
// dlcmdeditenq                                                 //~v04jR~
// enq to UDHviewqh                                             //~v04jI~
//*rc   :0                                                      //~v04jI~
//****************************************************************//~v04jI~
int dlcmdeditenq(PUCLIENTWE Ppcw,PUDLCMD Pplc)                  //~v04jR~
{                                                               //~v04jI~
	PUFILEC pfc;                                                //~v04jI~
#ifdef FTPSUPP                                                     //~v71aI~
	PUFILEH pfh;                                                   //~v71aI~
#endif                                                             //~v71aI~
	PULINEH plh;                                                //~v04jI~
    PUDIRLH pdh;                                                //~v04jI~
    PUCLIENTWE pcw;                                             //~v04jI~
//*******************                                           //~v04jI~
    pcw=scrgetcw(0);	//get edit screen pcw                   //~v04jI~
	pfc=pcw->UCWpfc;                                            //~v04jI~
	dlcmddeqpfc(pfc);	//once deq from previous dir list       //~v04jI~
    plh=Pplc->UDLCplh;                                          //~v04jI~
    pdh=UGETPDH(plh);                                           //~v04jI~
#ifdef FTPSUPP                                                     //~v71aI~
    pfh=pfc->UFCpfh;                                               //~v71aI~
    if (FILEISTSO(pfh))                                            //~v71aI~
        xetsodlcmdsetlocal(pfc,pdh,pfh);    //set pdh from pfh     //~v71aR~
#endif                                                             //~v71aI~
    UENQ(UQUE_TOP,&pdh->UDHviewqh,pfc); //enq to pdh            //~v04jI~
    UCBITON(pfc->UFCflag,UFCFENQEDIT);	//not view id(no highlite)//~v04jI~
	return 0;                                                   //~v04jI~
}//dlcmdeditenq                                                 //~v04jI~
                                                                //~v04jI~
//**************************************************************** //~v09wI~
// dlcmdeditenq2                                                   //~v09wR~
// enq to UDHviewqh for not from lcmd "e"/"w"/"s"                  //~v09wR~
//*rc   :pdh enqed                                                 //~v09wR~
//**************************************************************** //~v09wI~
PUDIRLH dlcmdeditenq2(PUCLIENTWE Ppcw)                             //~v09wR~
{                                                                  //~v09wI~
	PUFILEC pfc,pfco;                                              //~v09wR~
    PUCLIENTWE pcw;                                                //~v09wI~
  	PUDIRLH pdh,pdhp;                                              //~v09wR~
    PUFILEH pfh,pfho;                                              //~v09wI~
//*******************                                              //~v09wI~
    pcw=scrgetcw(0);	//get edit screen pcw                      //~v09wI~
	pfc=pcw->UCWpfc;                                               //~v09wI~
  	pfh=pfc->UFCpfh;                                               //~v09wI~
	pfco=Ppcw->UCWpfc;                                             //~v09wI~
  	pfho=pfco->UFCpfh;                                             //~v09wI~
	dlcmddeqpfc(pfc);	//once deq from previous dir list          //~v09wI~
    pdh=dlcpdhsrch(pfho,pfh->UFHfilename,&pdhp);                   //~v09wI~
	if (!pdh && pdhp)	//new entry but parent exist               //~v09wI~
    {                                                              //~v0fqI~
	  if (UCBITCHK(pfh->UFHflag,UFHFNEW))			//new now      //~v0fqI~
      {                                                            //~v0fqI~
    	UCBITON(pfc->UFCflag,UFCFENQSELNEW|UFCFENQEDIT);//new file,enq to parent//~v0fqR~
        UENQ(UQUE_TOP,&pdhp->UDHviewqh,pfc); //enq to parent pdh   //~v0fqI~
      }                                                            //~v0fqI~
      else                                                         //~v0fqI~
	    dlcisrtpdh(pdhp,pfh,&pdh);	//insert if direct child       //~v09wR~
    }                                                              //~v0fqI~
	if (pdh)    //matched or direct parent exist                   //~v09wR~
    {                                                              //~v09wI~
#ifdef FTPSUPP                                                     //~v71aI~
    	if (FILEISTSO(pfh))                                        //~v71aI~
        	xetsodlcmdsetlocal(pfc,pdh,pfh);    //set pdh from pfh //~v71aR~
#endif                                                             //~v71aI~
        UENQ(UQUE_TOP,&pdh->UDHviewqh,pfc); //enq to pdh           //~v09wR~
    	UCBITON(pfc->UFCflag,UFCFENQEDIT);	//but,no display "v"/"w" on dlh//~v09wI~
    }                                                              //~v09wI~
	return pdh;                                                    //~v09wR~
}//dlcmdeditenq2                                                   //~v09wI~
                                                                //~5731I~
//**************************************************************** //~v0fqI~
// dlcmdeditenq3                                                   //~v0fqI~
// enq to UDHviewqh at return from new file end(edit by selecet cmd)//~v0fqI~
//*parm1:pfc                                                       //~v0fqR~
//*rc   :pdh enqed                                                 //~v0fqI~
//**************************************************************** //~v0fqI~
PUDIRLH dlcmdeditenq3(PUFILEC Ppfc)                                //~v0fqR~
{                                                                  //~v0fqI~
    PUQUEH  pqh;                                                   //~v0fqI~
  	PUDIRLH pdhp,pdh;                                              //~v0fqR~
    PUFILEH pfh;                                                   //~v0fqI~
//*******************                                              //~v0fqI~
	if (!(pqh=UGETQHDR(Ppfc)))			//qhdr addr on pdh         //~v0fqI~
    	return 0;						//parent already freed     //~v0fqR~
    UDEQ(UQUE_ENT,pqh,Ppfc);        //deq from parent dir pdh      //~v0fqI~
	pfh=Ppfc->UFCpfh;                                              //~v0fqI~
//  pdhp=(PUDIRLH)(PVOID)((ULONG)pqh-offsetof(UDIRLH,UDHviewqh));  //~v0fqI~//~vafkR~
    pdhp=(PUDIRLH)(PVOID)((ULPTR)pqh-offsetof(UDIRLH,UDHviewqh));  //~vafkI~
	dlcisrtpdh(pdhp,pfh,&pdh);	//insert if direct child           //~v0fqI~
    if (pdh)                                                       //~v0fqI~
	    UENQ(UQUE_TOP,&pdh->UDHviewqh,Ppfc); //enq to pdh          //~v0fqI~
	return pdh;                                                    //~v0fqI~
}//dlcmdeditenq3                                                   //~v0fqI~
//**************************************************************** //~v10rI~
// set lineno to plh of dir list for edit from the dirlist         //~v10rI~
//*parm1:pfc                                                       //~v10rI~
//*rc   :0:not updated,1:updated lineno                            //~v10rI~
//**************************************************************** //~v10rI~
int dlcmdseteditlc(PUFILEC Ppfc)                                   //~v10rI~
{                                                                  //~v10rI~
    PUQUEH  pqh;                                                   //~v10rI~
  	PUDIRLH pdh;                                                   //~v10rI~
    PUFILEH pfh;                                                   //~v10rI~
    PULINEH plh;                                                   //~v10rI~
    LONG lineno,addv;                                              //~v10rR~
//*******************                                              //~v10rI~
	pfh=Ppfc->UFCpfh;                                              //~v10rI~
	if (!(pqh=UGETQHDR(Ppfc)))			//qhdr addr on pdh         //~v10rI~
    	return 0;						//parent already freed     //~v10rI~
//  pdh=(PUDIRLH)(PVOID)((ULONG)pqh-offsetof(UDIRLH,UDHviewqh));   //~v10rI~//~vafkR~
    pdh=(PUDIRLH)(PVOID)((ULPTR)pqh-offsetof(UDIRLH,UDHviewqh));   //~vafkI~
	if (plh=UGETQEND(&pfh->UFHlineque),plh)   //end of data edit line//~v10rI~
		plh=UGETQPREV(plh);         //last edit line saved         //~v10rI~
    if (plh)                                                       //~v10rI~
        lineno=plh->ULHlinenow;                                    //~v10rR~
    else                                                           //~v10rI~
        lineno=0;                                                  //~v10rI~
    plh=UGETDIRPLH(pdh);    //dir list plh                         //~v10rR~
	if (UCBITCHK(pdh->UDHflag2,UDHF2LCGOTTEN))                     //~v10rI~
    	addv=lineno-plh->ULHlinenow;                               //~v10rI~
	else                                                           //~v10rI~
    	addv=lineno;                                               //~v10rI~
    plh->ULHlinenow=lineno;                                        //~v10rI~
	UCBITON(pdh->UDHflag2,UDHF2LCGOTTEN);                          //~v10rI~
	dlcmdresetparentsz(pdh,DLCPSZ_LC,0,addv);	//parent lc update //~v10rR~
	return 1;                                                      //~v10rI~
}//dlcmdseteditlc                                                  //~v10rI~
//**************************************************************** //~v09vI~
// dlcpdhsrch                                                      //~v09vI~
// search pdh by fullpath name                                     //~v09wR~
//*parm1:pfh                                                       //~v09vI~
//*parm2:fullpath name                                             //~v09vI~
//*parm3:optional output parent pdh                                //~v09vI~
//*parm4:optional output prev pdh                                  //~v09wI~
//*rc   :pdh or 0 if not found                                     //~v09vI~
//**************************************************************** //~v09vI~
PUDIRLH dlcpdhsrch(PUFILEH Ppfh,char *Pfullpath,PUDIRLH *Pppdhp)   //~v09vR~
{                                                                  //~v09vI~
	PULINEH plh;                                                   //~v09vI~
	PUDIRLH pdh=0,pdhp=0;                                          //~v19yR~
    int level,len=0;                                                 //~v09vR~//~vaf9R~
//#ifdef UNX                                                       //~v71aR~
//#else                                                            //~v71aR~
    int matchsw;                                                   //~v56tI~
//#endif                                                           //~v71aR~
    char *pc;                                                      //~v09vI~
#ifdef FTPSUPP    //w32                                            //~v71aI~
    int tsosw;                                                     //~v71aI~
#endif                                                             //~v71aI~
//****************************                                     //~v09vI~
    level=0;                                                       //~v09vI~
    pc=Pfullpath;                                                  //~v09vI~
//#ifdef W32                                                         //~vb03I~//~vb06R~
//    if (IS_RESERVED_NAME(Pfullpath)) //\\.\ for prn,aux etc        //~vb03R~//~vb06R~
//        pc+=RESERVED_NAMEID_CTR;                                   //~vb03I~//~vb06R~
//#endif                                                             //~vb03I~//~vb06R~
#ifdef FTPSUPP    //w32                                            //~v71aI~
	tsosw=FILEISTSO(Ppfh);                                         //~v71aI~
#endif                                                             //~v71aI~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v09vR~
	{                                                              //~v09vI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v09vI~
            continue;                                              //~v09vI~
    	pdh=UGETPDH(plh);                                          //~v09vI~
        if (pdh->UDHlevel<(UCHAR)level)	//path changed             //~v09vI~
        {                                                          //~v09vI~
        	plh=0;		//not found id                             //~v09vI~
        	break;                                                 //~v09vI~
		}                                                          //~v09vI~
        if (pdh->UDHlevel>(UCHAR)level)	//child of brother         //~v09vI~
        	continue;                                              //~v09vI~
#ifdef UTF8SUPPH                                                   //~v71bI~//~va00R~
        if (pdh->UDHnamef2l)	//by locale code                                    //~v71bI~//~va00R~
        {                                                          //~v71bI~//~va00R~
    		len=(int)strlen(pdh->UDHnamef2l);                             //~v09vI~//~v71bI~//~va00R~
           if (len>(int)strlen(pc))                                //~vagqR~
    		matchsw=0;                                             //~vagqI~
           else                                                    //~vagqI~
    		matchsw=!memcmp(pdh->UDHnamef2l,pc,(UINT)len);	//path match   //~v71aI~//~v71bI~//~va00R~
        }                                                          //~v71bI~//~va00R~
        else                                                       //~v71bI~//~va00R~
    		matchsw=0;                                              //~v71bI~//~va00R~
     if (!matchsw)                                                 //~v71bI~//~va00R~
     {                                                             //~v71bI~//~va00R~
#endif                                                             //~v71bI~//~va00R~
    	len=(int)strlen(pdh->UDHname);                             //~v09vI~
#ifdef UNX                                                         //~v20DI~
//  	if (!memcmp(pdh->UDHname,pc,(UINT)len))	//path match       //~v71aR~
     if (len<=strlen(pc))                                          //~vagqI~
     {                                                             //~vagqI~
      if (tsosw)                                                   //~v71aI~
    	matchsw=!memicmp(pdh->UDHname,pc,(UINT)len);	//path match//~v71aI~
      else                                                         //~v71aI~
    	matchsw=!memcmp(pdh->UDHname,pc,(UINT)len);	//path match   //~v71aI~
     }                                                             //~vagqI~
	#ifndef UTF8SUPPH                                              //~v71bI~//~va00R~
	    if (matchsw)                                               //~v71bI~
	#endif                                                         //~v71bI~//~va00R~
#else  //!UNX                                                      //~v20DI~
	//  if (!memicmp(pdh->UDHname,pc,(UINT)len))	//path match   //~v56tR~
     if (len<=(int)strlen(pc))                                     //~vagqR~
     {                                                             //~vagqI~
  #ifdef FTPSUPP    //w32                                          //~v56tM~
   	  if (FILEISREMOTE(Ppfh))                                      //~v56tM~
       if (tsosw)                                                  //~v71aI~
		matchsw=!memicmp(pdh->UDHname,pc,(UINT)len);	//path match//~v71aI~
       else                                                        //~v71aI~
		matchsw=!memcmp(pdh->UDHname,pc,(UINT)len);	//path match   //~v56tR~
      else                                                         //~v56tM~
  #endif                                                           //~v56tM~
	    matchsw=!memicmp(pdh->UDHname,pc,(UINT)len);	//path match//~v56tI~
     }                                                             //~vagqI~
	#ifndef UTF8SUPPH                                              //~v71bI~//~va00R~
	    if (matchsw)                                               //~v56tR~
	#endif                                                         //~v71bI~//~va00R~
#endif //!UNX                                                      //~v20DI~
	#ifdef UTF8SUPPH                                               //~v71bI~//~va00R~
     }//utf8 unmatch                                               //~v71bI~//~va00R~
	    if (matchsw)                                               //~va00R~
	#endif                                                         //~va00R~
        {                                                          //~v09vI~
#ifdef FTPSUPP                                                     //~v71aI~
		  if (tsosw)                                               //~v71aI~
          {                                                        //~v71aI~
            if ((level && *(pc+len)==DSN_QUOTE) 	//"'":fullpath match//~v71aR~
            ||  *(pc+len)==DSN_SEPCMEMB2) 	//")":fullpath match   //~v71aI~
            	break;                                             //~v71aI~
        	if (!level          	//root match  next is "'"      //~v71aI~
        	||  *(pc+len)==DSN_SEPCMEMB			//"("              //~v71aI~
        	||  *(pc+len)==Ppfh->UFHdirsepc)	//"."              //~v71aI~
            {                                                      //~v71aI~
                pc+=len;                                           //~v71aI~
//              if (level)                                         //~v71aI~
                    pc++;   //path delm                            //~v71aI~
                pdhp=pdh;	//save immediate parent                //~v71aI~
            	level++;	//search next level                    //~v71aI~
            }                                                      //~v71aI~
          }                                                        //~v71aI~
          else                                                     //~v71aI~
          {                                                        //~v71aI~
#endif //FTPSUPP                                                   //~v71aI~
            if (!*(pc+len)) 	//fullpath match                   //~v09vI~
            	break;                                             //~v09vI~
        	if (!level          	//root match                   //~v09vR~
//      	||  *(pc+len)=='\\')	//path match,not dbcs \ because pdh name ended//~v19aR~
//      	||  *(pc+len)==DIR_SEPC)	//path match,not dbcs \ because pdh name ended//~v540R~
        	||  *(pc+len)==Ppfh->UFHdirsepc)	//path match,not dbcs \ because pdh name ended//~v540I~
            {                                                      //~v09vI~
                pc+=len;                                           //~v09vR~
                if (level)                                         //~v09vI~
                    pc++;   //path delm                            //~v09vI~
                pdhp=pdh;	//save immediate parent                //~v09vI~
            	level++;	//search next level                    //~v09vM~
            }                                                      //~v09vI~
#ifdef FTPSUPP                                                     //~v71aI~
          }//not tso                                               //~v71aI~
#endif //FTPSUPP                                                   //~v71aI~
		}                                                          //~v09vI~
	}//all plh	                                                   //~v09vI~
    if (Pppdhp)		//requested parent pdh                         //~v09vI~
    	*Pppdhp=pdhp;                                              //~v09vI~
    if (!plh)                                                      //~v09vI~
    	pdh=0;                                                     //~v09vI~
    return pdh;                                                    //~v09vI~
}//dlcpdhsrch                                                      //~v20DR~
                                                                   //~v09vI~
//**************************************************************** //~v0frI~
// dlcpdhsrch2                                                     //~v0frI~
// search pdh by fullpath name(exit reached to next high,iff root unmatch stop at it)//~v0frI~
//*parm1:pfh                                                       //~v0frI~
//*parm2:fullpath name                                             //~v0frI~
//*parm3:optional output matched or next high                      //~v0frI~
//*parm4:optional output parent pdh                                //~v0frI~
//*rc   :8 fullpath err,4 unmatch                                  //~v0frI~
//**************************************************************** //~v0frI~
int dlcpdhsrch2(PUFILEH Ppfh,char *Pfullpath,PUDIRLH *Pppdh,PUDIRLH *Pppdhp)//~v0frR~
{                                                                  //~v0frI~
	PULINEH plh;                                                   //~v0frI~
	PUDIRLH pdh=0,pdhp=0;                                          //~v19yR~
    int level,len,matchlevel;                                      //~v0frR~
    int pathlen,rc,complen;                                        //~v0frI~
    char *pc,*pcn;                                                 //~v0frM~
#ifdef FTPSUPP    //w32                                            //~v71aI~
    int tsosw;                                                     //~v71aI~
#endif                                                             //~v71aI~
//****************************                                     //~v0frI~
	if (Pppdh)                                                     //~v0frR~
    	*Pppdh=0;                                                  //~v0frR~
	if (Pppdhp)                                                    //~v0frI~
    	*Pppdhp=0;                                                 //~v0frR~
    level=0;                                                       //~v0frI~
    pc=Pfullpath;                                                  //~v0frI~
//  pcn=ustrchr2(pc,'\\');                                         //~v19aR~
//  pcn=ustrchr2(pc,DIR_SEPC);                                     //~v540R~
#ifdef FTPSUPP    //w32                                            //~v71aI~
	tsosw=FILEISTSO(Ppfh);                                         //~v71aI~
  if (tsosw)                                                       //~v71aI~
    pcn=strchr(pc,FTP_REMOTEID);    //hostname                     //~v71aI~
  else                                                             //~v71aI~
#endif                                                             //~v71aI~
#ifdef W32                                                         //~vaveI~
 if (FILEISREMOTEUNC(Ppfh))                                        //~vav2I~
    pcn=ustrchr2(pc+2,Ppfh->UFHdirsepc);                           //~vav2I~
 else                                                              //~vav2I~
#endif                                                             //~vaveI~
    pcn=ustrchr2(pc,Ppfh->UFHdirsepc);                             //~v540I~
    if (!pcn)                                                      //~v0frI~
        return 8;                                                  //~v0frI~
//  pathlen=(int)((ULONG)pcn-(ULONG)pc);                           //~v0frR~//~vafkR~
    pathlen=(int)((ULPTR)pcn-(ULPTR)pc);                           //~vafkI~
#ifndef UNX                                                        //~v19yI~
  #ifdef FTPSUPP    //w32                                          //~v54fI~
   if (!FILEISREMOTE(Ppfh))                                        //~v54fI~
  #endif                                                           //~v54fI~
  #ifdef W32                                                       //~vav2I~
   if (!FILEISREMOTEUNC(Ppfh))                                     //~vav2I~
  #endif                                                           //~vav2I~
	if (pathlen!=2 || *(pc+1)!=':')	//no drive id                  //~v0frR~
    	return 8;                                                  //~v0frI~
                                                                   //~v54fI~
#endif //!UNX                                                      //~v19yI~
    pathlen++;                                                     //~v0frI~
    matchlevel=-1;                                                 //~v0frI~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v0frI~
	{                                                              //~v0frI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v0frI~
            continue;                                              //~v0frI~
    	pdh=UGETPDH(plh);                                          //~v0frI~
//      if (pdh->UDHlevel<matchlevel)		//exit from match range//~v30cR~
        if ((int)pdh->UDHlevel<matchlevel)		//exit from match range//~v30cI~
        	break;                                                 //~v0frI~
        if (pdh->UDHlevel!=(UCHAR)level)	//not same path level  //~v0frI~
        	continue;                                              //~v0frI~
    	len=(int)strlen(pdh->UDHname);                             //~v0frI~
        complen=min(len,pathlen);                                  //~v0frI~
#ifdef UNX                                                         //~v20DI~
      if (tsosw)                                                   //~v71aI~
		rc=memicmp(pdh->UDHname,pc,(UINT)complen);                 //~v71aI~
      else                                                         //~v71aI~
		rc=memcmp(pdh->UDHname,pc,(UINT)complen);                  //~v20DI~
#else  //!UNX                                                      //~v20DI~
  #ifdef FTPSUPP    //w32                                          //~v56tI~
   	  if (FILEISREMOTE(Ppfh))                                      //~v56tI~
       if (tsosw)                                                  //~v71aI~
		rc=memicmp(pdh->UDHname,pc,(UINT)complen);                 //~v71aI~
       else                                                        //~v71aI~
		rc=memcmp(pdh->UDHname,pc,(UINT)complen);                  //~v56tI~
      else                                                         //~v56tI~
  #endif                                                           //~v56tI~
		rc=memicmp(pdh->UDHname,pc,(UINT)complen);                 //~v0frI~
#endif //!UNX                                                      //~v20DI~
        if (!pdhp)		//first line                               //~v0frI~
        	if (rc)                                                //~v0frI~
            	break;		//no advance when root unmatch         //~v0frI~
        if (rc<0)		//line<parm                                //~v0frI~
        	continue;                                              //~v0frI~
        if (rc>0) 		//line>parm                                //~v0frI~
        	break;                                                 //~v0frI~
        if (len<pathlen)                                           //~v0frI~
        	continue;                                              //~v0frI~
        if (len>pathlen)                                           //~v0frI~
        	break;                                                 //~v0frI~
//same len match                                                   //~v0frI~
		matchlevel=level;                                          //~v0frI~
        pc+=pathlen;                                               //~v0frI~
#ifdef FTPSUPP                                                     //~v71aI~
      if (tsosw)                                                   //~v71aI~
      {                                                            //~v71aI~
        if ((level && *pc==DSN_QUOTE) 	//"'":fullpath match       //~v71aR~
        ||  *pc==DSN_SEPCMEMB2) 	//")":fullpath match           //~v71aI~
        	break;                                                 //~v71aI~
//      if (level)                                                 //~v71aI~
	        pc++;		//skip "\\"                                //~v71aI~
        level++;                                                   //~v71aI~
        pcn=strpbrk(pc,DSN_SEPS);	//serch "." or "("             //~v71aI~
        if (!pcn)                                                  //~v71aI~
    	    pcn=strpbrk(pc,DSN_SEPS2);	//serch ")" or "'"         //~v71aI~
      }                                                            //~v71aI~
      else                                                         //~v71aI~
      {                                                            //~v71aI~
#endif                                                             //~v71aR~
        if (!*pc)	//full match                                   //~v0frI~
        	break;                                                 //~v0frI~
        if (level)                                                 //~v0frI~
	        pc++;		//skip "\\"                                //~v0frI~
        level++;                                                   //~v0frI~
//      pcn=ustrchr2(pc,'\\');                                     //~v19aR~
//      pcn=ustrchr2(pc,DIR_SEPC);                                 //~v540R~
        pcn=ustrchr2(pc,Ppfh->UFHdirsepc);                         //~v540I~
#ifdef FTPSUPP                                                     //~v71aI~
      }                                                            //~v71aI~
#endif                                                             //~v71aR~
        if (pcn)                                                   //~v0frI~
//        	pathlen=(int)((ULONG)pcn-(ULONG)pc);                   //~v0frR~//~vafkR~
        	pathlen=(int)((ULPTR)pcn-(ULPTR)pc);                   //~vafkI~
        else                                                       //~v0frI~
        	pathlen=(int)strlen(pc);                               //~v0frI~
        pdhp=pdh;	//save immediate parent                        //~v0frI~
	}//all plh                                                     //~v0frI~
    if (Pppdhp)		//requested parent pdh                         //~v0frI~
    	*Pppdhp=pdhp;                                              //~v0frI~
    if (Pppdh)		//requested parent pdh                         //~v0frI~
    	*Pppdh=pdh;                                                //~v0frI~
    if (!*pc)	//full match                                       //~v0frI~
    	rc=0;                                                      //~v0frI~
    else                                                           //~v0frI~
    	rc=4;                                                      //~v0frI~
    return rc;                                                     //~v0frI~
}//dlcpdhsrch2                                                     //~v20DR~
                                                                   //~v0frI~
//**************************************************************** //~v57gI~
// dlcpdhsrchts                                                    //~v57gI~
// search pdh by size or timestamp in the level                    //~v57gI~
//*parm1:parent pdh to start srch                                  //~v57gI~
//*parm2:pdh containing search key                                 //~v57gI~
//*parm3:output mached pdh                                         //~v57gI~
//*rc   :0:match,1;next high,4:eol                                 //~v57gI~
//**************************************************************** //~v57gI~
int dlcpdhsrchts(PULINEH Pplh,PUDIRLH Ppdhkey,PUDIRLH *Pppdhout)   //~v57gI~
{                                                                  //~v57gI~
	PULINEH plh;                                                   //~v57gI~
	PUDIRLH pdh;                                                   //~v57gR~
//  ULONG keysize;                                                 //~v71bR~
    FILESZT keysize;                                               //~v71bI~
    int keyftime,keyfdate,comp,sorttype,reversesw,level,rc,idate,itime;//~v57gR~
//****************************                                     //~v57gI~
    pdh=UGETPDH(Pplh);                                             //~v57gR~
    sorttype=pdh->UDHsortopt;                                      //~v57gR~
    reversesw=sorttype & UDHSOREVERSE;                             //~v57gI~
    sorttype&=~UDHSOREVERSE;                                       //~v57gI~
    level=(int)pdh->UDHlevel+1;	//child                            //~v57gI~
//  keyfdate=(int)(*(USHORT*)(void*)&Ppdhkey->UDHdate);            //~v57gR~//~vagqR~
//  keyftime=(int)(*(USHORT*)(void*)&Ppdhkey->UDHtime);            //~v57gR~//~vagqR~
    keyfdate=(int)FDATE2USHORT(Ppdhkey->UDHdate);                  //~vagqI~
    keyftime=(int)FTIME2USHORT(Ppdhkey->UDHtime);                  //~vagqI~
    keysize=Ppdhkey->UDHsize;                                      //~v57gI~
    rc=4;                                                          //~v57gI~
	for (plh=Pplh;plh;plh=UGETQNEXT(plh))                          //~v57gI~
	{                                                              //~v57gI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v57gI~
        	continue;                                              //~v57gI~
    	pdh=UGETPDH(plh);                                          //~v57gI~
        if ((int)pdh->UDHlevel!=level)		//chk chile level only //~v57gI~
        	continue;                                              //~v57gI~
        if (sorttype==UDHSOSIZE)                                   //~v57gI~
        	comp=(int)(keysize-pdh->UDHsize);                      //~v57hR~
        else                                                       //~v57gI~
        {                                                          //~v57gI~
//          idate=(int)(*(USHORT*)(void*)&pdh->UDHdate);           //~v57gR~//~vagqR~
//          itime=(int)(*(USHORT*)(void*)&pdh->UDHtime);           //~v57gR~//~vagqR~
            idate=(int)FDATE2USHORT(pdh->UDHdate);                 //~vagqI~
            itime=(int)FTIME2USHORT(pdh->UDHtime);                 //~vagqI~
	        if (!(comp=keyfdate-idate))                            //~v57gR~
		        comp=keyftime-itime;                               //~v57gR~
        }                                                          //~v57gI~
        if (!comp)		//match                                    //~v57gI~
        {                                                          //~v57gI~
        	rc=0;                                                  //~v57gI~
        	break;                                                 //~v57gI~
        }                                                          //~v57gI~
        if (reversesw)                                             //~v57gI~
            comp=-comp;                                            //~v57gI~
        if (comp<0)	//next high                                    //~v57gI~
        {                                                          //~v57gI~
        	rc=1;                                                  //~v57gI~
            break;                                                 //~v57gI~
        }                                                          //~v57gI~
	}//all plh                                                     //~v57gI~
    *Pppdhout=pdh;                                                 //~v57gI~
    return rc;                                                     //~v57gI~
}//dlcpdhsrch2                                                     //~v57gI~
                                                                   //~v57gI~
//**************************************************************** //~v09wI~
// dlcisrtpdh                                                      //~v09wR~
// insert pdh under parent                                         //~v09wR~
//parm1:parent pdh                                                 //~v09wR~
//parm2:pfh to be isrt                                             //~v09wR~
//parm3:output isrted pdh or 0 if err                              //~v09wI~
//*rc   :0 isrted 4:err                                            //~v09wR~
//**************************************************************** //~v09wI~
int dlcisrtpdh(PUDIRLH Ppdhp,PUFILEH Ppfh,PUDIRLH *Pppdh)          //~v09wR~
{                                                                  //~v09wI~
//  UDIRLIST dirlist;                                              //~v09wI~//~vandR~
//  UDIRLIST_WK(dirlist,wkslinkname);                              //~vandI~//+vb2sR~
    UDIRLIST_WK(dirlist,wkname,wknamew,wkslinkname);               //+vb2sI~
    int len,rc;                                                    //~v09wR~
    char pfname[_MAX_PATH];                                        //~v09wM~
    ULONG attr;                                                    //~v71aI~
//*******************                                              //~v09wI~
	*Pppdh=0;                                                      //~v09wI~
    if (dlcgetfullname(Ppdhp,pfname))	//get parent fullpath name //~v09wI~
    	return 4;                                                  //~v09wI~
	len=(int)strlen(pfname);                                       //~v09wR~
#ifdef FTPSUPP    //w32                                            //~v71aI~
  if (FILEISTSO(Ppfh))                                             //~v71aI~
  {                                                                //~v71aI~
	if (len!=u3270pathlen(2,Ppfh->UFHfilename))	//new filename pathlen(last is "." or "(")//~v71aI~
    	return 4;                                                  //~v71aI~
//  memset(&dirlist,0,sizeof(dirlist));                            //~v71aI~//~vandR~
//  UDIRLIST_WK_INIT(dirlist,wkslinkname);                         //~vandI~//+vb2sR~
    UDIRLIST_WK_INIT(dirlist,wkname,wknamew,wkslinkname);   //before call u3270getlastname()//+vb2sI~
    u3270getlastname(0,Ppfh->UFHfilename,dirlist.name);            //~v71aR~
    attr=Ppdhp->UDHattr;                                           //~v71aI~
    if (UCBITCHK(Ppfh->UFHflag7,UFHF7PDSMEMBER))                   //~v71aR~
	    attr|=FILE_PDSMEMB;                                        //~v71aI~
//  attr&=~FILE_DIRECTORY;                                         //~vb06R~
    attr&=(ULONG)(~FILE_DIRECTORY);                                //~vb06I~
    dirlist.srcattr=Ppdhp->UDHslinkattr;                           //~v71aI~
  }                                                                //~v71aI~
  else                                                             //~v71aI~
  {                                                                //~v71aI~
#endif                                                             //~v71aI~
    if (len!=3)                                                    //~v09wI~
    	len++;				//until \ of delm                      //~v09wI~
	if (len!=PATHLEN(Ppfh->UFHfilename))//not direct parent        //~v09wR~
    {                                                              //~vb03I~
//#ifdef W32                                                         //~vb03I~//~vb06R~
//      if (IS_RESERVED_NAME(Ppfh->UFHfilename)) //\\.\ for prn,aux etc//~vb03R~//~vb06R~
//      {                                                            //~vb03I~//~vb06R~
//                                                                   //~vb03I~//~vb06R~
//        len+=RESERVED_NAMEID_CTR;                                  //~vb03I~//~vb06R~
//        if (len!=PATHLEN(Ppfh->UFHfilename))//not direct parent    //~vb03I~//~vb06R~
//            return 4;                                              //~vb03I~//~vb06R~
//      }                                                            //~vb03I~//~vb06R~
//      else                                                         //~vb03I~//~vb06R~
//#endif                                                             //~vb03I~//~vb06R~
    	return 4;                                                  //~v09wI~
    }                                                              //~vb03I~
//  memset(&dirlist,0,sizeof(dirlist));                            //~v09wI~//~vandR~
//  UDIRLIST_WK_INIT(dirlist,wkslinkname);                         //~vandI~//+vb2sR~
    UDIRLIST_WK_INIT(dirlist,wkname,wknamew,wkslinkname);          //+vb2sI~
//  strcpy(dirlist.name,Ppfh->UFHfilename+len);                    //~v09wR~//+vb2sR~
    udirlist_setname(0,&dirlist,Ppfh->UFHfilename+len,0);          //+vb2sI~
#ifdef W32UNICODE                                                  //~vb02I~
    dlcsetnameW(0,&dirlist,Ppfh);	//set nameWctr and nameW       //~vb02I~
#endif                                                             //~vb02I~
    attr=Ppfh->UFHattr;                                            //~v71aI~
#ifdef FTPSUPP    //w32                                            //~v71aI~
  }                                                                //~v71aI~
#endif                                                             //~v71aI~
#if defined(DPMI) || defined(W32)                                  //~v0ffI~
    strcpy(dirlist.alias,Ppfh->UFHshortname+PATHLEN(Ppfh->UFHshortname));//~v0ffI~
#endif                                                             //~v0ffI~
    dirlist.time=Ppfh->UFHfiletime;                                //~v09wR~
    dirlist.date=Ppfh->UFHfiledate;                                //~v09wR~
    dirlist.size=Ppfh->UFHsize;                                    //~v09wR~
//  dirlist.attr=Ppfh->UFHattr;                                    //~v71aR~
    dirlist.attr=attr;                                             //~v71aI~
                                                                   //~v19XI~
#ifdef UNX                                                         //~v19XI~
    dirlist.fsid=Ppfh->UFHfsid;                                    //~v19XI~
    dirlist.inode=Ppfh->UFHinode;                                  //~va00I~
    dirlist.uid =Ppfh->UFHuid ;                                    //~v19XI~
    dirlist.gid =Ppfh->UFHgid ;                                    //~v19XI~
#endif //UNX                                                       //~v19XI~
                                                                   //~v19XI~
    rc=dlclvlmerge2(Ppdhp,&dirlist,Pppdh);                         //~v09wR~
    if (rc!=4)	//not added                                        //~v09wI~
    	return 4;                                                  //~v09wI~
	return 0;                                                      //~v09wI~
}//dlcisrtpdh                                                      //~v09wR~
                                                                   //~v09wI~
//****************************************************************//~v046I~
// dlcmdviewscrswap1                                            //~v046I~
// setup view screen                                            //~v046I~
//*rc   :1:split generated,0:already split,4:err                   //~v10tR~
//****************************************************************//~v046I~
int dlcmdviewscrswap1(PUCLIENTWE Ppcw,PUDLCMD Pplc,UCHAR *Pfname,PUCLIENTWE *Pppcw2)//~v046I~
{                                                               //~v046I~
//  PUFILEC pfc;                                                //~v046R~
    int rc=0;                                                      //~v10tI~
//*******************                                           //~v046I~
//  if (dlcgetfullname(UGETPDH(Pplc->UDLCplh),Pfname))          //~v05GR~//~vb2sR~
    if (dlcgetfullnamefilejunctiontarget(UGETPDH(Pplc->UDLCplh),Pfname))//~vb2sI~
    	return 4;                                               //~v046I~
    if (!scrgetcw(2))	//not splitted	                        //~v046I~
    {                                                           //~v046I~
		Gcsrposy=Gscrheight/2;	//half of screen                //~v046I~
//      if (Ppcw->UCWrcsry>Gcsrposy)                            //~v046R~
//      {                                                       //~v046R~
//          pfc=Ppcw->UCWpfc;                                   //~v046R~
//          pfc->UFCcurtop=Pplc->UDLCplh;                       //~v046R~
//          UCBITON(Ppcw->UCWflag,UCWFDRAW);                    //~v046R~
//      }                                                       //~v046R~
        if (func_splith(Ppcw))	//active change                 //~v046I~
        	return 4;                                           //~v046I~
        *Pppcw2=scrgetcw(2);	//split half                    //~v046I~
        rc=1;                                                      //~v10tI~
    }                                                           //~v046I~
    else                                                        //~v046I~
    {                                                           //~v046I~
        *Pppcw2=scrgetcw(-1);	//other half                    //~v046I~
        Gscrcurclient=!Gscrcurclient;	//change active         //~v046I~
        rc=0;                                                      //~v10tI~
    }                                                           //~v046I~
	return rc;                                                     //~v10tR~
}//dlcmdviewscrswap1                                            //~v046I~
                                                                //~v046I~
//****************************************************************//~v046I~
// dlcmdviewscrswap2                                            //~v046I~
// setup view screen                                            //~v046I~
//*rc   :0                                                      //~v046I~
//****************************************************************//~v046I~
int dlcmdviewscrswap2(PUCLIENTWE Ppcw,PUDLCMD Pplc)             //~v046R~
{                                                               //~v046I~
	PUFILEC pfc;                                                //~v046I~
	PULINEH plh;                                                //~v046R~
    PUDIRLH pdh;                                                //~v046I~
    PUCLIENTWE pcw;                                             //~v046I~
//*******************                                           //~v046I~
    pcw=scrgetcw(!Ppcw->UCWsplitid+1);	//not splitted          //~v046I~
	pfc=pcw->UCWpfc;                                            //~v046R~
	dlcmddeqpfc(pfc);	//once deq from previous dir list       //~v046I~
    plh=Pplc->UDLCplh;                                          //~v046R~
    pdh=UGETPDH(plh);                                           //~v046I~
    UENQ(UQUE_TOP,&pdh->UDHviewqh,pfc); //enq to pdh            //~v046R~
    Gscrcurclient=Ppcw->UCWsplitid;                             //~v046R~
  	filesetcsr(Ppcw,plh,PANL310LINENO,0);//set csr              //~v04bR~
	csrrestore(Ppcw);	//restore previous cursor pos           //~v046I~
	return 0;                                                   //~v046I~
}//dlcmdviewscrswap2                                            //~v046I~
                                                                //~v046I~
//****************************************************************//~5806I~
// dlcmdunexsub                                                 //~5806I~
// 1 level unexclude                                            //~5806I~
//*ret    :PULINEH                                              //~5806I~
//****************************************************************//~5806I~
PULINEH dlcunexsub(PUDIRLH Ppdh)                                //~5806I~
{                                                               //~5806I~
	PULINEH plh;                                                //~5806R~
	PUDIRLH pdh;                                                //~5806R~
    int level;                                                  //~5819R~
//****************************                                  //~5806I~
    plh=UGETDIRPLH(Ppdh);       //dir plh                       //~5819R~
	level=Ppdh->UDHlevel+1;		//child dir level               //~5819R~
    plh=UGETQNEXT(plh);         //first child                   //~5819R~
    while (pdh=UGETPDH(plh),(int)pdh->UDHlevel>=level)          //~5819I~
    {                                                           //~5806I~
		if ((int)pdh->UDHlevel==level)//child                   //~5819R~
        {                                                       //~5819I~
			UCBITOFF(plh->ULHflag2,ULHF2EXCLUDED);	//out of display//~5819I~
            if (!UCBITCHK(pdh->UDHflag,UDHFEXCLUDED))//not excluded//~5819R~
            {                                                   //~5819I~
           		plh=dlcunexsub(pdh);                            //~5819R~
                continue;                                       //~5819I~
            }                                                   //~5819I~
		}                                                       //~5819I~
		plh=UGETQNEXT(plh);                                     //~5819I~
	}                                                           //~5806I~
    return plh;                                                 //~5806I~
}//dlcunexsub                                                   //~5806I~
                                                                //~5819I~
//****************************************************************//~5819I~
// dlcmchngfh                                                   //~5819I~
// change fh filename for the case level up/down/mask change    //~5819I~
//parm1:pcw                                                     //~5819I~
//parm2:pfh                                                     //~5819I~
//parm3:pdh                                                     //~5819I~
//parm4:filename                                                //~5819I~
//*ret :none                                                    //~5819I~
//****************************************************************//~5819I~
void dlcchngfh(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfilename)//~5819I~
{                                                               //~5819I~
	PUFILEH pfhp;                                               //~5819R~
	PUCLIENTWE pcw;                                             //~5819I~
//****************************                                  //~5819I~
	if (filesrchpfh(Pfilename,0,&pfhp))	//same dir not found    //~5819R~
    	pfhp=0;                                                 //~5819I~
//	strncpy(Ppfh->UFHfilename,Pfilename,sizeof(Ppfh->UFHfilename));//~v0fmR~
    ufilesetfhfilename(Ppfh,Pfilename);                            //~v0fmI~
	if (pfhp)	//same dir already exist                        //~5819I~
       	if (((pcw=pfhp->UFHbrowsepcw[Ppcw->UCWsplitid])!=0 //same split//~v19yR~
        	&&  pcw!=Ppcw)                                         //~v19yR~
        ||  (pcw=pfhp->UFHbrowsepcw[!Ppcw->UCWsplitid])!=0 //other split//~5819I~
           )                                                       //~v13nI~
//          &&  pcw!=scrgetcw(-1))	//not on other client surface  //~v13nR~
//            uerrmsg("Warning:%s is already under the base",      //~v13nR~
//                    "注意:%s は別途潜伏中です",                  //~v13nR~
            uerrmsg("Warning:%s has another display screen",       //~v13nI~
                    "注意:%s は別\x95\\示有り",                    //~v13nR~
					Ppfh->UFHfilename);                         //~5819I~
//  Ppfh->UFHpathlen=(UCHAR)getpathlen(Ppfh->UFHfilename,0,1);     //~vaztR~
    Ppfh->UFHpathlen=getpathlen(Ppfh->UFHfilename,0,1);            //~vaztI~
	Ppfh->UFHlevel=Ppdh->UDHlevel;   //path up                  //~5819I~
	UCBITON(Ppcw->UCWflag,UCWFWAKEUP);//update hdr line filename//~5819I~
#ifdef FTPSUPP                                                     //~v54eI~
  if (Ppdh->UDHslink)		//slink defined                        //~v54eI~
  {                                                                //~v54eI~
	Ppfh->UFHfiletime=Ppdh->UDHslinktime;                          //~v54eI~
	Ppfh->UFHfiledate=Ppdh->UDHslinkdate;                          //~v54eI~
	Ppfh->UFHsize    =Ppdh->UDHslinksize;                          //~v54eI~
  }                                                                //~v54eI~
  else                                                             //~v54eI~
  {                                                                //~v54eI~
#endif                                                             //~v54eI~
	Ppfh->UFHfiletime=Ppdh->UDHtime;                            //~5819I~
	Ppfh->UFHfiledate=Ppdh->UDHdate;                            //~5819I~
	Ppfh->UFHsize    =Ppdh->UDHsize;                            //~5819I~
#ifdef FTPSUPP                                                     //~v54eI~
  }                                                                //~v54eI~
#endif                                                             //~v54eI~
	Ppfh->UFHattr    =Ppdh->UDHattr;                               //~v09wI~
    return;                                                     //~5819I~
}//dlcchngfh                                                    //~5819I~
                                                                //~5819I~
//****************************************************************//~5819I~
// dlclvlmerge                                                  //~5819I~
// merge old entry and entry by new mask                        //~5819I~
//*parm1:pcw                                                    //~5819I~
//*parm2:pdh of dir                                             //~5819I~
//*parm3:dirlist                                                //~5819I~
//*parm4:dirlist ctr                                            //~5819I~
//*rc   :none                                                   //~5819I~
//****************************************************************//~5819I~
void dlclvlmerge(PUCLIENTWE Ppcw,PUDIRLH Ppdh,PUDIRLIST Ppudirlist,int Pfilectr)//~5819I~
{                                                               //~5819I~
	PULINEH plh,plhn,plhprev;                                   //~5819I~
	PUDIRLH pdh;                                                //~5819I~
	PUFILEH pfh;                                                   //~v0fdR~
    int level,dirlevel,compsw;                                  //~5819R~
    UCHAR   uch;                                                   //~v07mI~
//****************************                                  //~5819I~
	dirlevel=Ppdh->UDHlevel;           	//dir level             //~5819I~
	level=dirlevel+1;   	        	//child level           //~5819I~
	plhprev=UGETDIRPLH(Ppdh);			//cmd entered plh       //~5819I~
	plh=UGETQNEXT(plhprev)			;	//next of cmd entered plh//~5819I~
	pfh=UGETPFH(plh);                                              //~v0fdR~
	for (;;)                                                    //~5819I~
    {                                                           //~5819I~
//  	if (*Ppudirlist->name=='.')                                //~v0k1I~
      if (Pfilectr)		//not reached end of entry                 //~v573I~
		if (!strcmp(Ppudirlist->name,".")                          //~v0k1I~
		||  !strcmp(Ppudirlist->name,".."))                        //~v0k1I~
        {                                                       //~5819I~
        	Pfilectr--;                                         //~5819I~
            Ppudirlist++;                                       //~5819I~
        	continue;                                           //~5819M~
		}                                                       //~5819I~
        pdh=UGETPDH(plh);                                       //~5819I~
        if (!Pfilectr)		//end of new                        //~5819I~
        {                                                       //~5819I~
        	if ((int)pdh->UDHlevel<level)    //reached to end of old//~5819R~
            	break;                                          //~5819I~
           if ((int)pdh->UDHlevel==level)   //del more brother,but keep chiled//~v48fI~
           {                                                       //~v48fI~
            dlcmdlvlclear(Ppcw,pdh,2,0);	//del child and grand-child//~v05oR~
        	plh=UGETQNEXT(plhprev);                             //~5819I~
        	continue;                                           //~5819I~
           }                                                       //~v48fI~
        }                                                       //~5819I~
		if ((int)pdh->UDHlevel<level)	//eof of old entry      //~5819I~
        {                                                       //~5819I~
			plhn=dirsetdata(dirlevel,Ppudirlist++,pfh);            //~v0fdR~
            if (!plhn)                                          //~v04dI~
            	return;                                         //~v04dI~
            Pfilectr--;                                         //~5819I~
			UGETPDH(plhn)->UDHdirptr=Ppdh;	//parent            //~5819I~
			UENQENT(UQUE_AFT,plhprev,plhn);                     //~5819I~
        	plhprev=plhn;					//next insert after this//~5819I~
        	continue;                                           //~5819I~
        }                                                       //~5819I~
		if ((int)pdh->UDHlevel>level)		//expanded old      //~5819I~
        {                                                       //~5819I~
			plhprev=plh;                                        //~5819I~
            plh=UGETQNEXT(plh);                                 //~5819I~
        	continue;                                           //~5819I~
        }                                                       //~5819I~
//  	compsw=stricmp(pdh->UDHname,Ppudirlist->name);             //~v0ffR~
//  	compsw=stricmp(pdh->UDHALIAS,Ppudirlist->name);            //~v0fnR~
      if (Pfilectr)		//not reached end of entry                 //~v573I~
		compsw=dlcfncomp(pfh,pdh,Ppudirlist);                      //~v0frR~
      else                                                         //~v573I~
        compsw=-1;  //id of old only                               //~v573I~
        if (compsw<0)	//old only                              //~5819I~
        {                                                       //~5819I~
            dlcmdlvlclear(Ppcw,pdh,2,0);	//del child and grand-child//~v05oR~
        	plh=UGETQNEXT(plhprev);                             //~5819I~
        	continue;                                           //~5819I~
		}                                                       //~5819I~
        if (compsw>0)	//new only                              //~5819I~
        {                                                       //~5819I~
			plhn=dirsetdata(dirlevel,Ppudirlist++,pfh);            //~v0fdR~
            if (!plhn)                                          //~v04dI~
            	return;                                         //~v04dI~
            Pfilectr--;                                         //~5819I~
			UGETPDH(plhn)->UDHdirptr=Ppdh;	//parent            //~5819I~
			UENQENT(UQUE_AFT,plhprev,plhn);                     //~5819I~
        	plhprev=plhn;					//next insert after this//~5819I~
        	continue;                                           //~5819I~
		}                                                       //~5819I~
	    if (UCBITCHK(pdh->UDHupdatetype,UDHUTNOTEXIST))//deleted//~v05zI~
        {                                                       //~v05zI~
			plh=dirsetdata(dirlevel,Ppudirlist++,pfh);             //~v0fdR~
            if (!plh)                                           //~v05zI~
            	return;                                         //~v05zI~
			UGETPDH(plh)->UDHdirptr=Ppdh;	//parent            //~v05zI~
			UENQENT(UQUE_AFT,plhprev,plh);                      //~v05zI~
		}                                                       //~v05zI~
        else                                                    //~v05zI~
        {                                                          //~v07mI~
        	uch=pdh->UDHtype;	//save old expand type             //~v07mI~
	        dirsetdatasub(pdh,Ppudirlist++);                    //~v05zR~
            if (uch==UDHTDIREXP)	//expanded before              //~v082R~
	        	pdh->UDHtype=uch;                                  //~v07mR~
            if (uch==UDHTPARENT) 	//path before                  //~v082I~
            {                                                      //~v082I~
                plhn=UGETQNEXT(plh);                               //~v082I~
                if (plhn)                                          //~v082R~
                {                                                  //~v540I~
					if (UGETPDH(plhn)->UDHtype!=UDHTPARENT)//last path//~v082R~
			        	pdh->UDHtype=UDHTDIREXP;	//expanded dir //~v082R~
					else                                           //~v082I~
			        	pdh->UDHtype=UDHTPARENT;	//restore over dirsetdatasub//~v082I~
                }                                                  //~v540I~
            }                                                      //~v082I~
		}                                                          //~v07mI~
        Pfilectr--;                                             //~5819I~
		plhprev=plh;                                            //~5819I~
        plh=UGETQNEXT(plh);                                     //~5819I~
	}//merge loop                                               //~5819I~
    return;                                                     //~5819I~
}//dlclvlmerge                                                  //~5819I~
//**************************************************************** //~v09wI~
// dlclvlmerge2                                                    //~v09wI~
// merge a entry under the parent pdh                              //~v09wI~
//*parm1:pdh of parent                                             //~v09wI~
//*parm2:dirlist                                                   //~v09wI~
//*parm3:output match or insterted pdh                             //~v09wR~
//*rc   :0:exist,4:inserted,8:err                                  //~v09wI~
//**************************************************************** //~v09wI~
int  dlclvlmerge2(PUDIRLH Ppdh,PUDIRLIST Ppudirlist,PUDIRLH *Pppdh)//~v09wR~
{                                                                  //~v09wI~
	PULINEH plh,plhprev;                                           //~v09wR~
	PUDIRLH pdh;                                                   //~v09wI~
	PUFILEH pfh;                                                   //~v0fdR~
    int level,dirlevel,compsw;                                     //~v09wI~
    int sorttype;                                                  //~v57hI~
//  UDIRLIST udl;                                                  //~v57hI~//~vandR~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~vandI~//+vb2sR~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //+vb2sI~
//****************************                                     //~v09wI~
//  UDIRLIST_WK_INIT(udl,wkslinkname);                             //~vandI~//+vb2sR~
    UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);              //+vb2sI~
    *Pppdh=0;                                                      //~v09wR~
    if (Ppdh->UDHtype==UDHTDIR)  //not expanded                    //~v09wI~
    	return 8;                                                  //~v09wI~
	dirlevel=Ppdh->UDHlevel;           	//dir level                //~v09wI~
	level=dirlevel+1;   	        	//child level              //~v09wI~
	plhprev=UGETDIRPLH(Ppdh);			//cmd entered plh          //~v09wI~
	plh=UGETQNEXT(plhprev)			;	//next of cmd entered plh  //~v09wI~
    pdh=UGETPDH(plh);                                              //~v09wI~
    pfh=UGETPFH(plh);                                              //~v0fdR~
    if (pdh->UDHtype==UDHTPARENT)  //on path                       //~v09wI~
    	return 8;                                                  //~v09wM~
    sorttype=Ppdh->UDHsortopt;                                     //~v57hI~
    if (sorttype)                                                  //~v57hI~
    {                                                              //~v57hI~
	    if (sorttype & UDHSOREVERSE)                               //~v57hI~
    	    sorttype=-(sorttype & ~UDHSOREVERSE);                  //~v57hI~
    }                                                              //~v57hI~
	for (;plh;plhprev=plh,plh=UGETQNEXT(plh))                      //~v09wI~
    {                                                              //~v09wI~
        pdh=UGETPDH(plh);                                          //~v09wI~
		if ((int)pdh->UDHlevel<level)	//eof of old entry         //~v09wI~
        	break;						//not found                //~v09wI~
		if ((int)pdh->UDHlevel>level)		//expanded old         //~v09wI~
        	continue;                                              //~v09wI~
//  	compsw=stricmp(pdh->UDHname,Ppudirlist->name);             //~v0ffR~
//  	compsw=stricmp(pdh->UDHALIAS,Ppudirlist->name);            //~v0fnR~
     if (sorttype)                                                 //~v57hI~
     {                                                             //~v57hI~
        udl.date=pdh->UDHdate;        //dirlist scr line data      //~v57hI~
        udl.time=pdh->UDHtime;                                     //~v57hI~
        udl.size=pdh->UDHsize;                                     //~v57hI~
//      strcpy(udl.name,pdh->UDHname);                             //~v57hI~//+vb2sR~
        udirlist_setname(0,&udl,pdh->UDHname,0);                   //+vb2sI~
#ifdef W32UNICODE                                                  //~vavaI~
//  	memcpy(udl.nameW,pdh->UDHnameW,sizeof(udl.nameW));  //compare by UWCH name//~vavaI~//~vaveR~
        if (pdh->UDHnameWctr)  //compare by UWCH name              //~vaveI~
        {                                                          //~vb02I~
//      	UmemcpyZWszctr(udl.nameW,pdh->UDHnameW,sizeof(udl.nameW),pdh->UDHnameWctr);  //compare by UWCH name//~vaveI~//+vb2sR~
        	udirlist_setnameW(0,&udl,pdh->UDHnameW,pdh->UDHnameWctr);  //compare by UWCH name//+vb2sI~
	    	udl.nameWctr=pdh->UDHnameWctr; //not used now, but pair of nameW//~vb02I~
        }                                                          //~vb02I~
#endif                                                             //~vavaI~
        udl.attr=Ppudirlist->attr;   //copy attr                   //~v71bR~
		compsw=udircomp(&udl,Ppudirlist,sorttype);//compare with inserted pdh dirlist data//~v57hR~
     }                                                             //~v57hI~
     else                                                          //~v57hI~
		compsw=dlcfncomp(pfh,pdh,Ppudirlist);                      //~v0frR~
        if (compsw<0)	//old only                                 //~v09wI~
        	continue;                                              //~v09wI~
        if (compsw>0)	//new only                                 //~v09wI~
        	break;                                                 //~v09wI~
        *Pppdh=pdh;		//matched                                  //~v09wR~
        return 0;                                                  //~v09wI~
	}//merge loop                                                  //~v09wI~
//*to be added                                                     //~v09wI~
	plh=dirsetdata(dirlevel,Ppudirlist,pfh);                       //~v0fdR~
    if (!plh)                                                      //~v09wI~
    	return 16;	//malloc fail                                  //~v09wI~
	(pdh=UGETPDH(plh))->UDHdirptr=Ppdh;	//parent                   //~v09wR~
	UENQENT(UQUE_AFT,plhprev,plh);                                 //~v09wI~
    dirrenum(plhprev);  //renumber from the plh                    //~v09wR~
    *Pppdh=pdh;                                                    //~v09wR~
    return 4;	//added                                            //~v09wI~
}//dlclvlmerge2                                                    //~v09wI~
//****************************************************************//~5813I~
// dlcdelentry                                                  //~5813I~
// delete plh                                                   //~5813I~
//*parm1 :plh                                                      //~v09AR~
//*parm2 :plh to be set to top if deleted curtop                   //~v09AR~
//*ret   :next line plh                                         //~5813I~
//****************************************************************//~5813I~
PULINEH dlcdelentry(PULINEH Pplh,PULINEH Pplhtop)                  //~v09AR~
{                                                               //~5813I~
	PULINEH plh;                                                //~5813I~
	PUFILEC pfc;                                                //~v05UI~
	PUCLIENTWE pcw;                                                //~v09AI~
	PUFILEH pfh;                                                   //~v09AI~
    int ii;                                                        //~v09AI~
    int swreset=0;                                                 //~vb21I~
//*******************                                           //~5813I~
//  pfc=Ppcw->UCWpfc;                                              //~v09AR~
//  pfh=pfc->UFCpfh;                                               //~v09AR~
//  if (Pplh==pfc->UFCcurtop)                                      //~v09AR~
//     	pfc->UFCcurtop=Pplhtop;                                    //~v09AR~
    pfh=UGETPFH(Pplh);                                             //~v09AI~
	for (ii=0;ii<2;ii++)                                           //~v09AI~
    {                                                              //~v09AI~
		if (!(pcw=pfh->UFHbrowsepcw[ii]))                          //~v09AR~
        	continue;                                              //~v09AI~
    	UCBITON(pcw->UCWflag,UCWFDRAW);	//full redraw              //~v09AI~
		pfc=pcw->UCWpfc;                                           //~v09AR~
    	if (Pplh==pfc->UFCcurtop)                                  //~v09AR~
        	pfc->UFCcurtop=Pplhtop;                                //~v09AR~
	}                                                              //~v09AI~
    plh=UGETQNEXT(Pplh);                                        //~5813I~
    UDEQ(UQUE_ENT,0,Pplh);                                      //~5813I~
//  if (*Pplh->ULHlinecmd)	//pending cmd                          //~v54sI~//~vb21R~
    if (*Pplh->ULHlinecmd)	//pending cmd                          //~vb21I~
        swreset=1;                                                 //~vb21I~
    else                                                           //~vb21I~
        if (UCBITCHK(Pplh->ULHflag,ULHFLINECMD))                   //~vb21R~
    	    swreset=1;                                             //~vb21I~
    if (swreset)                                                   //~vb21I~
    {                                                              //~v54sI~
    	for (ii=0;ii<pfh->UFHcmdlinectr;ii++)                      //~v54sI~
        	if (pfh->UFHcmdline[ii]==Pplh)                         //~v54sI~
            {                                                      //~v54EI~
	        	pfh->UFHcmdline[ii]=0;	//clear pending list       //~v54sI~
                dlcclearplcdeleted(Pplh);   //clear also plh on Slcmd//~v54EI~
            }                                                      //~v54EI~
    }                                                              //~v54sI~
    dirfreeplh(Pplh);                                           //~5813I~
//  UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full redraw              //~v09AR~
    return plh;                                                 //~5813I~
}//dlcdelentry                                                  //~v05UR~
                                                                //~5813I~
//**************************************************************** //~v0fnI~
// dlcfncomp                                                       //~v0fnI~
// compare filename for sort/merge                                 //~v0fnI~
//*parm1:pfh                                                       //~v0frR~
//*parm2:pdh                                                       //~v0frI~
//*parm3:dirlist                                                   //~v0frR~
//*rc   :compare result                                            //~v0fnI~
//**************************************************************** //~v0fnI~
int dlcfncomp(PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLIST Ppudirlist)      //~v0frR~
{                                                                  //~v0fnI~
//  UDIRLIST udirlist0;                                             //~v0fnI~//~vandR~
//  UDIRLIST_WK(udirlist0,wkslinkname);                            //~vandI~//+vb2sR~
    UDIRLIST_WK(udirlist0,wkname,wknamew,wkslinkname);             //+vb2sI~
    int sortorder;                                                 //~v0frI~
//****************************                                     //~v0fnI~
//  UDIRLIST_WK_INIT(udirlist0,wkslinkname);                       //~vandR~//+vb2sR~
    UDIRLIST_WK_INIT(udirlist0,wkname,wknamew,wkslinkname);        //+vb2sI~
#ifdef MMM                                                         //~vb2oI~
	memcpy(udirlist0.name,Ppdh->UDHname,sizeof(udirlist0.name));     //~v0fnI~
#else                                                              //~vb2oI~
//  UstrncpyZ(udirlist0.name,Ppdh->UDHname,sizeof(udirlist0.name));//~vb2oI~//+vb2sR~
    udirlist_setname(0,&udirlist0,Ppdh->UDHname,0);                //+vb2sI~
#endif                                                             //~vb2oI~
#if defined(DPMI) || defined(W32)                                  //~v0fnI~
	memcpy(udirlist0.alias,Ppdh->UDHalias,sizeof(udirlist0.alias));  //~v0fnR~
#endif                                                             //~v0fnI~
#ifdef W32UNICODE                                                  //~vavaI~
	udirlist0.nameWctr=Ppdh->UDHnameWctr;                          //~vavaR~
    if (Ppdh->UDHnameWctr)                                         //~vavaI~
//  	memcpy(udirlist0.nameW,Ppdh->UDHnameW,sizeof(udirlist0.nameW));  //compare by UWCH name//~vavaR~//~vaveR~
//  	UmemcpyZWszctr(udirlist0.nameW,Ppdh->UDHnameW,sizeof(udirlist0.nameW),Ppdh->UDHnameWctr);  //compare by UWCH name//~vaveI~//+vb2sR~
    	udirlist_setnameW(0,&udirlist0,Ppdh->UDHnameW,Ppdh->UDHnameWctr);  //compare by UWCH name//+vb2sI~
#endif                                                             //~vavaI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4LFN))  //lfn                  //~v0frI~
    	sortorder='L';                                             //~v0frI~
	else                                                           //~v0frI~
    	sortorder='N';                                             //~v0frI~
//  return udircomp(&udirlist0,Ppudirlist,'N');                     //~v0frR~
    udirlist0.attr=Ppudirlist->attr;                               //~v71bR~
    return udircomp(&udirlist0,Ppudirlist,sortorder);               //~v0frI~
}//dlcfncomp                                                       //~v0fnI~
                                                                   //~v0fnI~
//****************************************************************//~v05LI~
// errnotdir                                                    //~v05LI~
// not directory                                                //~v05LI~
//parm:none                                                     //~v05LI~
//*ret:rc 4                                                     //~v05LI~
//****************************************************************//~v05LI~
int errnotdir(void)                                             //~v05LR~
{                                                               //~v05LI~
//*******************                                           //~v05LI~
	uerrmsg("not directory",                                    //~v05LI~
            "ディレクトリーに非ず");                            //~v05LI~
    return 4;                                                   //~v05LI~
}//errinvaliddata                                               //~v05LI~
#ifdef W32UNICODE                                                  //~vb02I~
//**************************************************************** //~vb02I~
void dlcsetnameW(int Popt,PUDIRLIST Ppudl,PUFILEH Ppfh)            //~vb02R~
{                                                                  //~vb02I~
	int opt,ddlen,rc,ucssz,ucsctr,pathctr;                         //~vb02R~
	WUCS *pfnmw;                                                   //~vb02R~
    char *pdata,*pdbcs;                                            //~vb02I~
//*******************                                              //~vb02I~
    Ppudl->nameWctr=0;                                             //~vb02R~
	pdata=Ppfh->UFHfilenamedddata;                                 //~vb02I~
	pdbcs=Ppfh->UFHfilenamedddbcs;                                 //~vb02I~
	ddlen=Ppfh->UFHfilenameddlen;                                  //~vb02I~
	if (ddlen)                                                     //~vb02I~
    {                                                              //~vb02I~
    	opt=0;                                                     //~vb02I~
		rc=xeutfcvdd2u(opt,pdata,pdbcs,ddlen,&pfnmw,&ucssz);       //~vb02R~
        if (!rc)                                                   //~vb02I~
        {	                                                       //~vb02I~
            pathctr=PATHCTRW(pfnmw);                               //~vb02I~
        	ucsctr=sz2ctrW(ucssz)-pathctr;                         //~vb02R~
            if (ucsctr>0)                                          //~vb02I~
            {                                                      //~vb02I~
        		Ppudl->nameWctr=ucsctr;                            //~vb02R~
//          	UmemcpyZWszctr(Ppudl->nameW,pfnmw+pathctr,sizeof(Ppudl->nameW),ucsctr);//~vb02R~//+vb2sR~
            	udirlist_setnameW(0,Ppudl,pfnmw+pathctr,ucsctr);   //+vb2sI~
            	UTRACED("nameW",Ppudl->nameW,ucssz);               //~vb02R~
            }                                                      //~vb02I~
        }                                                          //~vb02I~
    }                                                              //~vb02I~
}//dlcsetnameW                                                     //~vb02I~
#endif                                                             //~vb02I~
