//*CID://+vb33R~:                              update#= 1142;      //~vb33R~
//*************************************************************
//vb33:160424 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~vb33I~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2J:160313 (W32) compier warning                                //~vb2JI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//v8@G:080629 3270:ABEND when no resp data(rc=0)                   //~v8@GI~
//v8@A:080626 3270:TSOE spfinfo has seconds of update timestamp    //~v8@AI~
//v8@w:080625 3270:issue STOW failed msg                           //~v8@wI~
//v8@t:080623 3270:cursor move to =6 panel home for cmd(ftp,listds,..) input//~v8@tI~
//v8@m:080620 3270:check READY on last line(linemode or spf changes temporary to line mode for cmd resonse)//~v8@mI~
//v8@f:080618 no resonse msg when spf mode for rename              //~v8@fI~
//v8@b:080614 3270:use wait output for timing problem              //~v8@bI~
//v8@4:080609 for the case tso cmd response start from end of line of current(=6) panel(after logon panel err)//~v8@4I~
//v8@3:080602 receive also hostname on xehosts file to identify logon command//~v8@3I~
//v763:070530 3270:putconfirm allow line split                     //~v763I~
//v72u:061202 3270:tso spf cmd support                             //~v72uI~
//v72t:061202 (BUG)3270:abend when "FOLLOWING ALIAS NAME EXIST WITHOUT TRUE NAME" if using native LISTDS//~v72tI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v727:061119 3270:optionaly use xe4s001z to list pds member and display spf info//~v727I~
//v725:061117 3270:conf file support                               //~v725I~
//v720:061116 3270:listds fail by 'sys1.*' because sys1.duplex has no dsorg recfm//~v720I~
//v71H:061103 (3270)for RECFM=F,set UFHlrecl(return DS info even when MEMB not found)//~v71HI~
//v71n:061020 3270:add alloc/free cmd                              //~v71nI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71f:061012 (BUG)3270:abend when REenter case                    //~v71fI~
//v71e:061011 3270:Rename/delete support                           //~v71eI~
//v719:061004 dirlist DSN list support                             //~v719I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v715:060221 (LNX)3270 ftp support(hostfile,TSO command)          //~v715I~
//v70z:060904 3270 ftp support(hostfile,TSO command)               //~v716I~
//*************************************************************
//*xe3270s.c                                                       //~v725R~
//*************************************************************

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>      //offsetof                                //~v716I~
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

//**********
#ifdef LNX                                                         //~v715R~
	#define _MT		//multithred notification to UTRACE etc        //~v715R~
    #include <unistd.h>                                            //~v715R~
#else                                                              //~v715R~
#include <errno.h>                                                 //~v71eI~
#include <windows.h>
#endif                                                             //~v715R~
//**********
#include <ulib.h>
#include <ualloc.h>
#include <uque.h>
#include <uerr.h>
#include <ufile.h>                                                 //~v719I~
#include <uftp.h>                                                  //~v719I~
#include <u3270.h>                                                 //~v716I~
#include <utrace.h>                                                //~v719I~
#include <ustring.h>                                               //~v719I~
#include <uedit.h>                                                 //~v719I~
#include <uedit2.h>                                                //~v727I~
#include <ustring.h>                                               //~v8@mI~
#include <ucvext.h>                                                //~v8@GI~

#include "xe.h"
#include "xe3270.h"
#include "xe3270s.h"                                               //~v725I~
                                                                   //~v719I~
//*************************************************************    //~v719I~
int getmember(char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist);     //~v719I~
int getdsorg(char *Pline,int Plen,PDSNDATA Ppdsd);                 //~v719I~
int getpdsinf(char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist);     //~v719R~
//int getdsinf(int Pmembsw,char *Pbuff,int Plen,PDSNLIST *Ppdsnlist);//~v727R~
int getdsinf(char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Ppdsnlist);//~v727I~
int getdsnentry(char *Pbuff,int Plen,PDSNDATA Ppdsnd,char **Pnext);//~v719I~
int setpdsrespdata(PTHREADTB Ppthtb,char *Pdsn,char *Pmembname,int Prc,PPDSMEMBLIST Pppml);//~v719I~
//int setdsrespdata(PTHREADTB Ppthtb,char *Phostfile,int Prc,PDSNLIST Ppdsnl);//~v72uR~
int setdsrespdata(int Popt,PTHREADTB Ppthtb,char *Phostfile,int Prc,PDSNLIST Ppdsnl);//~v72uI~
#define SDRD_NOMSG         0x01     //no dataset msg               //~v72uI~
int tsocmdresponsechk(PTHREADTB Ppthtb,char *Pcmd,int Prow);       //~v71nI~
//int getspfpdsinf(char *Pdsn,char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist);//~v8@3R~
int getspfpdsinf(int Popt,PTHREADTB Ppthtb,char *Pdsn,char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist);//~v8@3I~
//int getspfpdsmembinf(char *Pdsn,char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist);//~v72uR~
//int getspfpdsmembinf(int Popt,char *Pdsn,char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist);//~v8@3R~
int getspfpdsmembinf(int Popt,PTHREADTB Ppthtb,char *Pdsn,char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist);//~v8@3R~
#define GSPFMO_ERRMEMBNF   0x01     //retrurn by err if member not found//~v72uI~
int getspfmemblist(char *Pbuff,PPDSSPFINFO Ppspfi);                //~v727R~
int funclistdsuser(PTHREADTB Ppthtb,char *Phostfile,char *Pdsn,char *Pmemb,char *Prespbuff);//~v727R~
int setspfdate(char *Pyymmdd,FDATE *Ppfdate);                      //~v727I~
int getspfdsinf(char *Pdsn,char *Pbuff,PDSNDATA Ppdsnd);           //~v727R~
//int listuserresphdrchk(char *Pdsn,char *Pbuff,DSNDATA *Ppdnsd,char **Pptopline);//~v8@3R~
int listuserresphdrchk(int Popt,PTHREADTB Ppthtb,char *Pdsn,char *Pbuff,DSNDATA *Ppdnsd,char **Pptopline);//~v8@3I~
int getenum(char *Pdata);                                          //~v72nI~
                                                                   //~v763I~
static DSNDATA Slastdsnd;   //to chk lrecl for putconfirm          //~v763I~
//**************************************************************** //~v71nI~
//*allocate                                                        //~v71nI~
//**************************************************************** //~v71nI~
int funcalloc(PTHREADTB Ppthtb)                                    //~v71nI~
{                                                                  //~v71nI~
    char **popd,cmd[MAX_CMDSZ],*pfnm,*pc,*tsocmd="ALLOC";          //~v71nR~
    int rc,row;                                                    //~v71nR~
    int opt;                                                       //~v8@bI~
//************************                                         //~v71nI~
UTRACEP("funcallocate entry\n");                                   //~v71nI~
//    rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
//    if (rc)                                                      //~v8@3R~
//    {                                                            //~v8@3R~
//UTRACEP("funcallocate no READY found\n");                        //~v8@3R~
//        return rc;                                               //~v8@3R~
//    }                                                            //~v8@3R~
//  if (rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb),rc)     //~v8@tR~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@tI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@tI~
    	return rc;                                                 //~v8@3I~
    screenclear(2,Ppthtb);	//confirm 1 line input available       //~v8@wR~
    row=Ppthtb->THTcurrow;                                         //~v71nI~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v71nI~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    pfnm=popd[PARM_HOSTFILE];                                      //~v71nI~
	pc=cmd+sprintf(cmd,"String \"%s DA(%s)",tsocmd,pfnm);          //~v71nI~
    for (popd+=PARM_LOCALFILE;*popd;popd++)                        //~v71nI~
    {                                                              //~v71nI~
    	*pc++=' ';                                                 //~v71nI~
    	strcpy(pc,*popd);                                          //~v71nI~
        pc+=strlen(*popd);                                         //~v71nI~
    }                                                              //~v71nI~
    strcpy(pc,"\\n\"");                                            //~v71nI~
//  if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;                                                 //~v71nI~
    rc=tsocmdresponsechk(Ppthtb,tsocmd,row);                       //~v71nR~
    if (!rc)                                                       //~v71nI~
        rc=U3CR_RC_DONE;                                           //~v71nI~
UTRACEP("funcallocate exit rc=%d\n",rc);                           //~v71nI~
    return rc;                                                     //~v71nI~
}//funcalloc                                                       //~v71nI~
//**************************************************************** //~v71nI~
//*response chk                                                    //~v71nI~
//**************************************************************** //~v71nI~
int tsocmdresponsechk(PTHREADTB Ppthtb,char *Pcmd,int Prow)        //~v71nR~
{                                                                  //~v71nI~
    char *pbuff,*pc,*pc2;                                          //~v71nR~
	char buff[MAX_SCREENSZ];                                       //~v71nI~
    int rc,readlen;                                                //~v71nR~
    int opt;                                                       //~v8@3I~
//************************                                         //~v71nI~
UTRACEP("tsocmd responsechk entry\n");                             //~v71nI~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=getfulldata(SENDO_REENTERCHK|SENDO_ENTERCHK|SENDO_BREAKREENTER,Ppthtb,buff,sizeof(buff),Prow,&pbuff,&readlen);//~v8@3R~
    opt=SENDO_REENTERCHK|SENDO_ENTERCHK|SENDO_BREAKREENTER|SENDO_CHKSPF;//~v8@4R~
    rc=getfulldata(opt,Ppthtb,buff,sizeof(buff),Prow,&pbuff,&readlen);//~v8@3I~
//  if (!rc)                                                       //~v8@GR~
    if (!rc && pbuff)                                              //~v8@GI~
    {                                                              //~v71nI~
        pc=pbuff;                                                  //~v71nI~
  	  if (THT_ISSPF(Ppthtb))  //screen is spf panel mode           //~v8@3I~
        pc2=pc;                                                    //~v8@3I~
      else                                                         //~v8@3I~
        for (;;)                                                   //~v71nI~
        {                                                          //~v71nI~
            WORDTOP(pc);                                           //~v71nI~
            NEXTLINE(pc2,pc);                                      //~v71nI~
            if (!pc2)                                              //~v71nI~
                break;                                             //~v71nI~
            if (!memicmp(pc,Pcmd,strlen(Pcmd)))                    //~v71nI~
                break;                                             //~v71nI~
            pc=pc2;                                                //~v71nI~
        }                                                          //~v71nI~
//      if (!pc2)     //hdr line not found                         //~v8@fR~
        if (!pc2 && !THT_ISSPF(Ppthtb))     //hdr line not found   //~v8@fI~
	    	rc=U3CR_RC_OTHER;                                      //~v71nI~
        else                                                       //~v71nI~
        {                                                          //~v71nI~
//  	    if (memcmp(pc2,WORDCHK_READY,WORDCHK_READY_SZ))        //~v8@3R~
  	        if (THT_ISSPF(Ppthtb))  //screen is spf panel mode     //~v8@3I~
             	rc=readlen!=0;      //no repmsg when success       //~v8@3I~
            else                                                   //~v8@3I~
				rc=memcmp(pc2,WORDCHK_READY,WORDCHK_READY_SZ);     //~v8@3I~
            if (rc)                                                //~v8@3I~
		    	rc=U3CR_RC_OTHER;                                  //~v71nI~
            else                                                   //~v71nI~
        		uerrmsgmt(1,"%s successfully processed\n",0,       //~v71nI~
                          Pcmd);                                   //~v71nI~
        }                                                          //~v71nI~
    }                                                              //~v71nI~
    if (pbuff)                                                     //~v71nI~
        ufree(pbuff);                                              //~v71nI~
    return rc;                                                     //~v71nI~
}//tsocmdresponsechk                                               //~v71nI~
//**************************************************************** //~v71nI~
//*allocate                                                        //~v71nI~
//**************************************************************** //~v71nI~
int funcfree(PTHREADTB Ppthtb)                                     //~v71nI~
{                                                                  //~v71nI~
    char **popd,cmd[MAX_CMDSZ],*pfnm,/**pc,*/*tsocmd="FREE";           //~v71nR~//~vaa7R~
    int rc,row;                                                    //~v71nR~
    int opt;                                                       //~v8@bI~
//************************                                         //~v71nI~
UTRACEP("funcfree entry\n");                                       //~v71nI~
//    rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
//    if (rc)                                                      //~v8@3R~
//    {                                                            //~v8@3R~
//UTRACEP("funcfree no READY found\n");                            //~v8@3R~
//        return rc;                                               //~v8@3R~
//    }                                                            //~v8@3R~
//  if (rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb),rc)     //~v8@tR~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@tI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@tI~
    	return rc;                                                 //~v8@3I~
    screenclear(2,Ppthtb);	//confirm 1 line input available       //~v8@wR~
    row=Ppthtb->THTcurrow;                                         //~v71nI~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v71nI~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    pfnm=popd[PARM_HOSTFILE];                                      //~v71nI~
	/*pc=cmd+*/sprintf(cmd,"String \"%s DA(%s)\\n\"",tsocmd,pfnm);     //~v71nR~//~vaa7R~
//  if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;                                                 //~v71nI~
    rc=tsocmdresponsechk(Ppthtb,tsocmd,row);                       //~v71nR~
UTRACEP("funcfree exit rc=%d\n",rc);                               //~v71nI~
    return rc;                                                     //~v71nI~
}//funcfree                                                        //~v71nI~
//**************************************************************** //~v71eI~
//*rename                                                          //~v71eR~
//*  return memblist if DSORG=PO,memblist contains member if 'M' parameter specified//~v71eI~
//**************************************************************** //~v71eI~
int funcrename(PTHREADTB Ppthtb)                                   //~v71eI~
{                                                                  //~v71eI~
    char **popd,cmd[MAX_CMDSZ],*poldname,*pnewname,*tsocmd="RENAME";//~v71nR~
    int rc,row;                                                    //~v71nR~
    int opt;                                                       //~v8@bI~
//************************                                         //~v71eI~
UTRACEP("funcrename entry\n");                                     //~v71eR~
//    rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
//    if (rc)                                                      //~v8@3R~
//    {                                                            //~v8@3R~
//UTRACEP("funcrename no READY found\n");                          //~v8@3R~
//        return rc;                                               //~v8@3R~
//    }                                                            //~v8@3R~
//  if (rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb),rc)     //~v8@tR~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@tI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@tI~
    	return rc;                                                 //~v8@3I~
    screenclear(2,Ppthtb);	//confirm 1 line input available       //~v8@wR~
    row=Ppthtb->THTcurrow;                                         //~v71eI~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v71eI~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    poldname=popd[PARM_HOSTFILE];                                  //~v71eR~
    pnewname=popd[PARM_LOCALFILE];                                 //~v71eR~
    if (!pnewname || !*pnewname)                                   //~v71fR~
    {                                                              //~v71eI~
        uerrmsgmt(1,"Missing NEW NAME specification\n",0);         //~v71eI~
    	return U3CR_RC_OTHER;                                      //~v71eI~
    }                                                              //~v71eI~
	sprintf(cmd,"String \"%s %s %s\\n\"",tsocmd,poldname,pnewname);//~v71nR~
//  if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;                                                 //~v71eI~
    rc=tsocmdresponsechk(Ppthtb,tsocmd,row);                       //~v71nR~
UTRACEP("funcrename exit rc=%d\n",rc);                             //~v71eR~
    return rc;                                                     //~v71eI~
}//funcrename                                                      //~v71eI~
//**************************************************************** //~v71eI~
//*delete (support only PDS member for safety)                     //~v71eI~
//*  return memblist if DSORG=PO,memblist contains member if 'M' parameter specified//~v71eI~
//**************************************************************** //~v71eI~
int funcdelete(PTHREADTB Ppthtb)                                   //~v71eI~
{                                                                  //~v71eI~
    char **popd,cmd[MAX_CMDSZ],*phostfile,*pbuff,*pc,*pc2;         //~v71eR~
	char buff[MAX_SCREENSZ];                                       //~v71eI~
    int rc,readlen,row;                                            //~v71eI~
    int opt;                                                       //~v8@3I~
//************************                                         //~v71eI~
UTRACEP("funcdelete entry\n");                                     //~v71eR~
//    rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
//    if (rc)                                                      //~v8@3R~
//    {                                                            //~v8@3R~
//UTRACEP("funcdeleet no READY found\n");                          //~v8@3R~
//        return rc;                                               //~v8@3R~
//    }                                                            //~v8@3R~
//  if (rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb),rc)     //~v8@tR~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@tI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@tI~
    	return rc;                                                 //~v8@3I~
    screenclear(2,Ppthtb);	//confirm 1 line inpu available        //~v8@wR~
    row=Ppthtb->THTcurrow;                                         //~v71eI~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v71eI~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    phostfile=popd[PARM_HOSTFILE];                                 //~v71eR~
    if (MEMBOFDSN(phostfile)==0)	//no member specified          //~v71eI~
    {                                                              //~v71eI~
        uerrmsgmt(1,"Only PDS member delete is supported\n",0);    //~v71eI~
    	return U3CR_RC_OTHER;                                      //~v71eI~
    }                                                              //~v71eR~
	sprintf(cmd,"String \"DELETE %s\\n\"",phostfile);              //~v71eR~
 // if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bI~
    	return rc;                                                 //~v71eI~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=getfulldata(SENDO_REENTERCHK|SENDO_BREAKREENTER,Ppthtb,buff,sizeof(buff),row,&pbuff,&readlen);//~v8@3R~
    opt=SENDO_REENTERCHK|SENDO_BREAKREENTER|SENDO_CHKSPF;          //~v8@4R~
    rc=getfulldata(opt,Ppthtb,buff,sizeof(buff),row,&pbuff,&readlen);//~v8@3I~
//  if (!rc)                                                       //~v8@GR~
    if (!rc && pbuff)                                              //~v8@GI~
    {                                                              //~v71eI~
        pc=pbuff;                                                  //~v71eI~
  	  if (THT_ISSPF(Ppthtb))  //screen is spf panel mode           //~v8@3I~
        pc2=pc;               //start by "member deleted"          //~v8@3I~
      else                                                         //~v8@3I~
        for (;;)                                                   //~v71eI~
        {                                                          //~v71eI~
            WORDTOP(pc);                                           //~v71eI~
            NEXTLINE(pc2,pc);                                      //~v71eI~
            if (!pc2)                                              //~v71eI~
                break;                                             //~v71eI~
            if (!memicmp(pc,"DELETE",6))                           //~v71eR~
                break;                                             //~v71eI~
            pc=pc2;                                                //~v71eI~
        }                                                          //~v71eI~
        if (!pc2)     //hdr line not found                         //~v71eI~
	    	rc=U3CR_RC_OTHER;                                      //~v71eI~
        else                                                       //~v71eI~
        {                                                          //~v71eI~
		    if (strstr(pc2,"NOT DELETED"))                         //~v71eR~
		    	rc=U3CR_RC_OTHER;                                  //~v71eI~
        }                                                          //~v71eI~
    }                                                              //~v71eI~
    if (pbuff)                                                     //~v71fR~
        ufree(pbuff);                                              //~v71eI~
UTRACEP("funcdelete exit rc=%d\n",rc);                             //~v71eR~
    return rc;                                                     //~v71eI~
}//funcdelete                                                      //~v71eI~
//**************************************************************** //~v8@AI~
//*any other TSO cmd                                               //~v8@AI~
//**************************************************************** //~v8@AI~
int functsocmd(PTHREADTB Ppthtb)                                   //~v8@AI~
{                                                                  //~v8@AI~
    char **popd,cmd[MAX_CMDSZ],*pcmdtext,*pbuff;                   //~v8@AR~
	char buff[MAX_SCREENSZ];                                       //~v8@AI~
    int rc,readlen,row;                                            //~v8@AI~
    int opt;                                                       //~v8@AI~
//************************                                         //~v8@AI~
UTRACEP("functsocmd entry\n");                                     //~v8@AI~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@AI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@AI~
    	return rc;                                                 //~v8@AI~
    screenclear(3,Ppthtb);	//confirm 1 line inpu available        //~v8@AI~
    row=Ppthtb->THTcurrow;                                         //~v8@AI~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v8@AI~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    pcmdtext=popd[PARM_HOSTFILE];                                  //~v8@AR~
	sprintf(cmd,"String \"%s\\n\"",pcmdtext);                      //~v8@AR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@AI~
    if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@AI~
    	return rc;                                                 //~v8@AI~
    opt=SENDO_REENTERCHK|SENDO_BREAKREENTER|SENDO_CHKSPF;          //~v8@AI~
    rc=getfulldata(opt,Ppthtb,buff,sizeof(buff),row,&pbuff,&readlen);//~v8@AI~
    if (!rc && pbuff)                                              //~v8@AI~
    {                                                              //~v8@AI~
      uerrmsgmt(1,"%s\n",0,                                        //~v8@AI~
      				pbuff);                                        //~v8@AI~
    }                                                              //~v8@AI~
    if (pbuff)                                                     //~v8@AI~
        ufree(pbuff);                                              //~v8@AI~
UTRACEP("functsocmd exit rc=%d\n",rc);                             //~v8@AI~
    return rc;                                                     //~v8@AI~
}//functsocmd                                                      //~v8@AI~
//**************************************************************** //~v8@AI~
//*any other TSO cmd                                               //~v8@AI~
//**************************************************************** //~v8@AI~
int funcquery(PTHREADTB Ppthtb)                                    //~v8@AI~
{                                                                  //~v8@AI~
    char **popd;                                                   //~v8@AR~
    int rc;                                                        //~v8@AR~
//************************                                         //~v8@AI~
UTRACEP("funcquery entry\n");                                      //~v8@AI~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v8@AI~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    rc=xe3270squery(0,Ppthtb,popd);                                //~v8@AI~
UTRACEP("funcqueryexit rc=%d\n",rc);                               //~v8@AI~
    return rc;                                                     //~v8@AI~
}//funcquery                                                       //~v8@AI~
//**************************************************************** //~v716I~
//*listds                                                          //~v716R~
//*  return memblist if DSORG=PO,memblist contains member if 'M' parameter specified//~v716I~
//**************************************************************** //~v716I~
int funclistds(PTHREADTB Ppthtb)                                   //~v716I~
{                                                                  //~v716I~
    char **popd,cmd[MAX_CMDSZ],*phostfile,*popt,*pbuff,*pc,*pc2;   //~v719R~
	char buff[MAX_SCREENSZ];                                       //~v716I~
    int rc,readlen,memblsw=0,/*membsw2=0,*/row,len;                //~v727R~
    int opt;                                                       //~v8@3I~
    PPDSMEMBLIST pmemblist=0;                                      //~v716R~
    PDSNLIST pdsnlist=0;                                           //~v719I~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v719I~
    char dsn[DSN_MAXLEN]={0};                                      //~v719I~
//************************                                         //~v716I~
UTRACEP("funclistds entry\n");                                     //~v716I~
//  rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
//  if (rc)                                                        //~v8@3R~
//  {                                                              //~v8@3R~
//UTRACEP("funclistds no READY found\n");                          //~v8@3R~
//  	return rc;                                                 //~v8@3R~
//  }                                                              //~v8@3R~
//  if (rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb),rc)     //~v8@tR~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@tI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@tI~
    	return rc;                                                 //~v763I~
//  screenclear(10,Ppthtb);	//10:up to members                     //~v8@wR~
    screenclear(3,Ppthtb);	//10:up to members                     //~v8@wI~
    row=Ppthtb->THTcurrow;                                         //~v719M~
//	popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v716I~//~vafkR~
	popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    phostfile=popd[PARM_HOSTFILE];                                 //~v716I~
    popt=popd[PARM_HOSTFILE+1];                                    //~v716I~
                                                                   //~v719I~
//  if (u3270getmembname(0,phostfile,membname))	//0:no set dummy member even if not specified//~v727R~
//  {                                                              //~v727R~
//  	pathlen=u3270pathlen(1,phostfile)-1;//dsname len           //~v727R~
//      memcpy(dsn,phostfile,pathlen);                             //~v727R~
//      *(dsn+pathlen)=0;                                          //~v727R~
//  }                                                              //~v727R~
    if (!(u3270parsedsn(0,phostfile,dsn,membname) & U3PD_RC_MEMBER))	//0:no set dummy member even if not specified//~v727I~
    {                                                              //~v727I~
    	strcpy(dsn,phostfile);                                     //~v727I~
        *membname=0;                                               //~v727I~
    }                                                              //~v727I~
//  if (*G3270memblistcmd)                                         //~v72nR~
    if (G3270opt & G3270OPT_SPFLVL1)                               //~v72nR~
		if (*membname						//no membername        //~v727R~
		||  (popt && toupper(*popt)=='M'))    //request memberlist //~v727R~
	        return funclistdsuser(Ppthtb,phostfile,dsn,membname,buff);//~v727R~
    if (strchr(dsn,'*'))                                           //~v719R~
	    sprintf(cmd,"String \"LISTDS %s \\n\"",phostfile);         //~v719I~
    else                                                           //~v719I~
    if (popt && toupper(*popt)=='M')                               //~v716I~
    {                                                              //~v719I~
    	memblsw=1;                                                 //~v719I~
	    sprintf(cmd,"String \"LISTDS %s MEMBERS\\n\"",phostfile);  //~v716I~
    }                                                              //~v719I~
    else                                                           //~v716I~
    {                                                              //~v71fI~
//  	membsw2=MEMBOFDSN(phostfile)!=0;	//membername specified //~v727R~
	    sprintf(cmd,"String \"LISTDS %s\\n\"",phostfile);          //~v716R~
    }                                                              //~v71fI~
//  if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;                                                 //~v716I~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=getfulldata(SENDO_REENTERCHK|SENDO_BREAKREENTER,Ppthtb,buff,sizeof(buff),row,&pbuff,&readlen);//~v8@3R~
    opt=SENDO_REENTERCHK|SENDO_BREAKREENTER|SENDO_CHKSPF;          //~v8@4R~
    rc=getfulldata(opt,Ppthtb,buff,sizeof(buff),row,&pbuff,&readlen);//~v8@3I~
//  if (!rc)                                                       //~v8@GR~
    if (!rc && pbuff)                                              //~v8@GI~
    {                                                              //~v719I~
        pc=pbuff;                                                  //~v719I~
      if (THT_ISSPF(Ppthtb))                                       //~v8@3I~
        pc2=pc;                                                    //~v8@3I~
      else                                                         //~v8@3I~
        for (;;)                                                   //~v719R~
        {                                                          //~v719I~
            WORDTOP(pc);                                           //~v719R~
            NEXTLINE(pc2,pc);                                      //~v719R~
            if (!pc2)                                              //~v719I~
                break;                                             //~v719R~
            if (!memicmp(pc,"LISTDS",6))                           //~v719I~
                break;                                             //~v719I~
            pc=pc2;                                                //~v719R~
        }                                                          //~v719I~
        if (!pc2)     //hdr line not found                         //~v719R~
	    	rc=U3CR_RC_OTHER;                                      //~v719I~
        else                                                       //~v719I~
        {                                                          //~v719I~
            pc=pc2;                                                //~v719R~
//		    len=readlen-((ULONG)pc-(ULONG)pbuff);                  //~v719R~//~vafkR~
//		    len=readlen-((ULPTR)pc-(ULPTR)pbuff);                  //~vafkI~//~vb30R~
  		    len=readlen-PTRDIFF(pc,pbuff);                         //~vb30I~
            if (!memblsw)                                          //~v719R~
            {                                                      //~v719R~
//              rc=getdsinf(membsw2,pc,len,&pdsnlist);             //~v727R~
                rc=getdsinf(membname,pc,len,&pdsnlist);            //~v727I~
                if (rc)                                            //~v8@4I~
    	    		uerrmsgmt(1,"%s",0,                            //~v8@4I~
        	               pc);                                    //~v8@4I~
//  			rc=setdsrespdata(Ppthtb,phostfile,rc,pdsnlist);    //~v72uR~
    			rc=setdsrespdata(0,Ppthtb,phostfile,rc,pdsnlist);  //~v72uI~
            }                                                      //~v719R~
            else                                                   //~v719R~
            {                                                      //~v719R~
                rc=getpdsinf(pc,len,&pmemblist);                   //~v719R~
				rc=setpdsrespdata(Ppthtb,dsn,membname,rc,pmemblist);//~v719R~
            }                                                      //~v719R~
        }                                                          //~v719I~
    }                                                              //~v716I~
    if (pbuff)                                                     //~v71fR~
        ufree(pbuff);                                              //~v719R~
UTRACEP("funclistds exit rc=%d,memblist=%p,dsnlist=%p\n",rc,pmemblist,pdsnlist);//~v719R~
    return rc;                                                     //~v716I~
}//funclistds                                                      //~v716I~
//**************************************************************** //~v727I~
//*listds by xe4s001z                                              //~v727I~
//**************************************************************** //~v727I~
int funclistdsuser(PTHREADTB Ppthtb,char *Phostfile,char *Pdsn,char *Pmemb,char *Preadbuff)//~v727R~
{                                                                  //~v727I~
    char *pbuff,cmd[MAX_CMDSZ];                                    //~v72nR~
    int rc,readlen,row;                                            //~v72nR~
    int opt;                                                       //~v8@3I~
    PPDSMEMBLIST pmemblist=0;                                      //~v727I~
    PDSNLIST pdsnlist=0;                                           //~v727I~
//************************                                         //~v727I~
UTRACEP("funclistdsuser entry\n");                                 //~v727I~
    row=Ppthtb->THTcurrow;                                         //~v727I~
	sprintf(cmd,"String \"%s %s\\n\"",G3270memblistcmd,Phostfile); //~v727R~
//  if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;                                                 //~v727I~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=getfulldata(SENDO_REENTERCHK|SENDO_BREAKREENTER,Ppthtb,Preadbuff,MAX_SCREENSZ,row,&pbuff,&readlen);//~v8@3R~
    opt=SENDO_REENTERCHK|SENDO_BREAKREENTER|SENDO_CHKSPF;          //~v8@4R~
    rc=getfulldata(opt,Ppthtb,Preadbuff,MAX_SCREENSZ,row,&pbuff,&readlen);//~v8@3I~
//  if (!rc)                                                       //~v8@GR~
    if (!rc && pbuff)                                              //~v8@GI~
    {                                                              //~v727I~
            if (*Pmemb)                                            //~v727I~
            {                                                      //~v727I~
//              rc=getspfpdsmembinf(Pdsn,Pmemb,pbuff,readlen,&pdsnlist);//~v72uR~
//              rc=getspfpdsmembinf(0,Pdsn,Pmemb,pbuff,readlen,&pdsnlist);//~v8@3R~
                rc=getspfpdsmembinf(0,Ppthtb,Pdsn,Pmemb,pbuff,readlen,&pdsnlist);//~v8@3I~
//  			rc=setdsrespdata(Ppthtb,Pdsn,rc,pdsnlist);         //~v72uR~
    			rc=setdsrespdata(0,Ppthtb,Pdsn,rc,pdsnlist);       //~v72uI~
            }                                                      //~v727I~
            else                                                   //~v727I~
            {                                                      //~v727I~
//      		rc=getspfpdsinf(Pdsn,pbuff,readlen,&pmemblist);    //~v8@3R~
        		rc=getspfpdsinf(0,Ppthtb,Pdsn,pbuff,readlen,&pmemblist);//~v8@3I~
				rc=setpdsrespdata(Ppthtb,Pdsn,Pmemb,rc,pmemblist); //~v727R~
            }                                                      //~v727I~
    }                                                              //~v727I~
    if (pbuff)                                                     //~v727I~
        ufree(pbuff);                                              //~v727I~
UTRACEP("funclistdsuser exit rc=%d,memblist=%p\n",rc,pmemblist);   //~v727R~
    return rc;                                                     //~v727I~
}//funclistdsuser                                                  //~v727I~
//**************************************************************** //~v727I~
//*listds by xe4s001z                                              //~v727I~
//*ret:0 or NOTFOUND when membername specified                     //~v727I~
//**************************************************************** //~v727I~
//int getspfpdsmembinf(char *Pdsn,char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist)//~v72uR~
//int getspfpdsmembinf(int Popt,char *Pdsn,char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist)//~v8@3R~
int getspfpdsmembinf(int Popt,PTHREADTB Ppthtb,char *Pdsn,char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist)//~v8@3I~
{                                                                  //~v727I~
    PDSSPFINFO  spfi;                                              //~v727R~
    DSNDATA dsnd;                                                  //~v727I~
    PDSNLIST pdsnlist=0;                                           //~v727I~
    int rc,resplen,rc2;                                            //~v72nR~
    char *pc/*,*pc0*/;                                                 //~v727R~//~vaa7R~
    char prevlinemembname[DSN_MAXMEMBERNAMELEN+1]={0};             //~v72nI~
//************************                                         //~v727I~
UTRACEP("getspfpdsmembinf entry\n");                               //~v72nR~
	*Pppdsnlist=0;                                                 //~v727R~
    memset(&spfi,0,sizeof(spfi));                                  //~v727I~
//  rc=listuserresphdrchk(Pdsn,Pbuff,&dsnd,&pc);//chk response hdr //~v8@3R~
    rc=listuserresphdrchk(Popt,Ppthtb,Pdsn,Pbuff,&dsnd,&pc);//chk response hdr//~v8@3I~
    if (rc)                                                        //~v72nI~
    	return rc;                                                 //~v72nI~
//member info                                                      //~v727I~
    rc=U3CR_RC_OTHER;                                              //~v72nI~
//  pc0=pc;                                                        //~v727I~//~vaa7R~
    for (rc2=0;;)                                                  //~v727R~
    {                                                              //~v727I~
		NEXTLINE(pc,pc);                                           //~v727I~
    	if (!pc)                                                   //~v727I~
        	return rc;                                             //~v727I~
        if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))            //~v72nI~
            return rc;                                             //~v72nI~
        if (!memcmp(pc,"-END OF LIST-",13))                        //~v727I~
        {                                                          //~v72uI~
    	    uerrmsgmt(1,"%s",0,                                    //~v72uI~
        	               pc);                                    //~v72uI~
            break;                                                 //~v727I~
        }                                                          //~v72uI~
        if (!memcmp(pc," * MEMBER NOT FOUND",19))                  //~v727I~
        {                                                          //~v72uI~
        	if (Popt & GSPFMO_ERRMEMBNF)    //return by err if member not found//~v72uI~
            {                                                      //~v72uI~
    	    	uerrmsgmt(1,"%s",0,                                //~v72uI~
        	               pc);                                    //~v72uI~
            	return U3CR_RC_NOTFOUND;                           //~v72uI~
            }                                                      //~v72uI~
        	break;                                                 //~v727I~
        }                                                          //~v72uI~
        if (!memcmp(pc," * ",3))    //xe4s001z err                 //~v72nI~
        {                                                          //~v72nI~
        	uerrmsgmt(1,"%s",0,                                    //~v72nI~
                       pc);                                        //~v72nI~
            return rc;                                             //~v72nI~
        }                                                          //~v72nI~
        WORDTOP(pc);                                               //~v72nI~
	    memset(&spfi,0,sizeof(spfi));                              //~v727I~
		getspfmemblist(pc,&spfi);//membername specified and unmatch//~v727R~
        if (!strcmp(spfi.SPFImember,WORDCHK_SPFUPDATEOK))          //~v72nI~
        	strcpy(spfi.SPFImember,prevlinemembname);              //~v72nI~
        if (!stricmp(spfi.SPFImember,Pmemb))	                   //~v727R~
        {                                                          //~v727I~
        	strcpy(prevlinemembname,spfi.SPFImember);              //~v72nR~
        	rc2=1;                                                 //~v727I~
//      	break;                                                 //~v72nR~
        }                                                          //~v727I~
    }                                                              //~v727I~
    dsnd.DSDflag|=DSDFMEMB;                                        //~v727I~
    if (!rc2)                                                      //~v727I~
        dsnd.DSDflag|=DSDFMEMBNOTFOUND;                            //~v727I~
    resplen=DSNLHDRSZ+DSNDATASZ;                                   //~v727I~
//  pdsnlist=umalloc(resplen);                                     //~v727I~//~vb30R~
    pdsnlist=umalloc((size_t)resplen);                             //~vb30I~
    pdsnlist->DSLhdr.PRDlen=resplen;                               //~v727I~
    pdsnlist->DSLhdr.PRDcount=1;                                   //~v727R~
    pdsnlist->DSLhdr.PRDtype=PRDT_DSNL;                            //~v727I~
    strcpy(spfi.SPFImember,Pmemb);                                 //~v727I~
    memcpy(&pdsnlist->DSLspfi,&spfi,sizeof(spfi));                 //~v727I~
    memcpy(pdsnlist->DSLentry,&dsnd,sizeof(dsnd));                 //~v727I~
    *Pppdsnlist=pdsnlist;                                          //~v727R~
    rc=0;                                                          //~v72nI~
UTRACEP("getspfpdsmembinf exit rc=%d\n",rc);                       //~v72nR~
    return rc;                                                     //~v72nR~
}//getspfpdsmembinf                                                //~v727R~
//**************************************************************** //~v727I~
//*listds by xe4s001z                                              //~v727I~
//*ret:0 or NOTFOUND when membername specified                     //~v727I~
//**************************************************************** //~v727I~
//int getspfpdsinf(char *Pdsn,char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist)//~v8@3R~
int getspfpdsinf(int Popt,PTHREADTB Ppthtb,char *Pdsn,char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist)//~v8@3I~
{                                                                  //~v727I~
    PPDSMEMBLIST ppml;                                             //~v727I~
    PPDSSPFINFO  pspfi;                                            //~v727I~
    DSNDATA dsnd;                                                  //~v727I~
    int rc=U3CR_RC_OTHER,membcnt,lenpml,ii;                        //~v727I~
    char *pc,*pc0;                                                 //~v727I~
//************************                                         //~v727I~
UTRACEP("getpdsinfuser entry\n");                                  //~v727I~
	*Pppmemblist=0;                                                //~v727I~
//  rc=listuserresphdrchk(Pdsn,Pbuff,&dsnd,&pc);//chk response hdr //~v8@3R~
    rc=listuserresphdrchk(Popt,Ppthtb,Pdsn,Pbuff,&dsnd,&pc);//chk response hdr//~v8@3I~
    if (rc)                                                        //~v72nI~
    	return rc;                                                 //~v72nI~
//member info                                                      //~v727I~
    pc0=pc;                                                        //~v727I~
    for (membcnt=0;;)                                              //~v727I~
    {                                                              //~v727I~
		NEXTLINE(pc,pc);                                           //~v727I~
    	if (!pc)                                                   //~v727I~
        	return rc;                                             //~v727I~
        if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))            //~v72nI~
            return rc;                                             //~v72nI~
        if (!memcmp(pc,"-END OF LIST-",13))                        //~v727I~
            break;                                                 //~v727I~
        membcnt++;                                                 //~v727I~
    }                                                              //~v727I~
//  lenpml=PDSMEMBLISTHDRSZ+PDSSPFINFOSZ*membcnt;                  //~v727I~//~vb30R~
    lenpml=(int)PDSMEMBLISTHDRSZ+(int)PDSSPFINFOSZ*membcnt;        //~vb30I~
//  ppml=(PPDSMEMBLIST)umalloc(lenpml);                            //~v727I~//~vb30R~
    ppml=(PPDSMEMBLIST)umalloc((size_t)lenpml);                    //~vb30I~
//  memset(ppml,0,lenpml);                                         //~v727I~//~vb30R~
    memset(ppml,0,(size_t)lenpml);                                 //~vb30I~
    ppml->PMLhdr.PRDcount=membcnt;                                 //~v727I~
    ppml->PMLhdr.PRDlen=lenpml;                                    //~v727I~
    ppml->PMLhdr.PRDtype=PRDT_MEMBL;                               //~v727I~
    pspfi=ppml->PMLmember;                                         //~v727I~
    for (ii=0,pc=pc0;ii<membcnt;ii++,pspfi++)                      //~v727I~
    {                                                              //~v727I~
		NEXTLINE(pc,pc);                                           //~v727I~
    	if (!pc)                                                   //~v727I~
        	return rc;                                             //~v727I~
        if (!memcmp(pc,"-END OF LIST-",13))                        //~v727I~
            break;                                                 //~v727I~
        WORDTOP(pc);                                               //~v72nI~
		getspfmemblist(pc,pspfi);//membername specified and unmatch//~v727R~
    }                                                              //~v727I~
    *Pppmemblist=ppml;                                             //~v727I~
    memcpy(&ppml->PMLdsnd,&dsnd,DSNDATASZ);                        //~v727I~
    *Pppmemblist=ppml;                                             //~v727I~
UTRACEP("getpdsinfuser exit rc=%d\n",rc);                          //~v727I~
    return 0;                                                      //~v727I~
}//getspfpdsinf                                                    //~v727R~
//**************************************************************** //~v727I~
//*dataset info line process                                       //~v727I~
//**************************************************************** //~v727I~
int getspfdsinf(char *Pdsn,char *Pbuff,PDSNDATA Ppdsnd)            //~v727R~
{                                                                  //~v727I~
    PDSLINEFMT   pdsfmt;                                           //~v727I~
//************************                                         //~v727I~
UTRACEP("getspfdsinf entry\n");                                    //~v727R~
//data set info                                                    //~v727I~
    memset(Ppdsnd,0,DSNDATASZ);                                    //~v727R~
    strcpy(Ppdsnd->DSDdsn,Pdsn);                                   //~v727I~
//  pdsfmt=(PDSLINEFMT)(ULONG)Pbuff;                               //~v727I~//~vafkR~
    pdsfmt=(PDSLINEFMT)(ULPTR)Pbuff;                               //~vafkI~
    if (!memcmp(pdsfmt->DLFdsorg,"PS",2))                          //~v727I~
    	Ppdsnd->DSDflag|=DSDFPS;                                   //~v727I~
    else                                                           //~v727I~
    if (!memcmp(pdsfmt->DLFdsorg,"PO",2))                          //~v727I~
    	Ppdsnd->DSDflag|=DSDFPO;                                   //~v727I~
    else                                                           //~v727I~
    	Ppdsnd->DSDflag|=DSDFVS;                                   //~v727I~
    if (*pdsfmt->DLFrecfm=='F')                                    //~v727I~
    	Ppdsnd->DSDflag|=DSDFF;                                    //~v727I~
    else                                                           //~v727I~
    if (*pdsfmt->DLFrecfm=='V')                                    //~v727I~
    	Ppdsnd->DSDflag|=DSDFV;                                    //~v727I~
    if (*(pdsfmt->DLFrecfm+1)=='B')                                //~v727I~
    	Ppdsnd->DSDflag|=DSDFB;                                    //~v727I~
    Ppdsnd->DSDlrecl=atoi(pdsfmt->DLFlrecl);                       //~v727R~
    Ppdsnd->DSDblksize=atoi(pdsfmt->DLFblksz);                     //~v727R~
UTRACED("getspfdsinf exit",Ppdsnd,DSNDATASZ);                      //~v727R~
    return 0;                                                      //~v727I~
}//getspfdsinf                                                     //~v727R~
//**************************************************************** //~v727I~
//*member info line process                                        //~v727I~
//*rc 4:member specified but not the member                        //~v727I~
//**************************************************************** //~v727I~
int getspfmemblist(char *Pbuff,PPDSSPFINFO Ppspfi)                 //~v727R~
{                                                                  //~v727I~
    PSPFLINEFMT  pfmt;                                             //~v727R~
    int len;                                                       //~v727R~
    char *pc2,*pc3;                                                //~v727R~
//************************                                         //~v727I~
UTRACEP("getspfmemblist entry\n");                                 //~v727R~
//  pfmt=(PSPFLINEFMT)(ULONG)Pbuff;                                //~v727R~//~vafkR~
    pfmt=(PSPFLINEFMT)(ULPTR)Pbuff;                                //~vafkI~
    pc2=pfmt->SLFmember;                                           //~v727I~
    WORDEND(pc3,pc2);                                              //~v727I~
//  len=(ULONG)pc3-(ULONG)pc2;                                     //~v727I~//~vafkR~
//  len=(ULPTR)pc3-(ULPTR)pc2;                                     //~vafkI~//~vb30R~
    len=PTRDIFF(pc3,pc2);                                          //~vb30I~
//  memcpy(Ppspfi->SPFImember,pc2,len);                            //~v727I~//~vb30R~
    memcpy(Ppspfi->SPFImember,pc2,(size_t)len);                    //~vb30I~
    if (*pfmt->SLFver==SLFVERALIAS) //alias                        //~v727I~
        Ppspfi->SPFIflag|=SPFIFALIAS;                              //~v727I~
    else                                                           //~v727I~
    if (*pfmt->SLFver!=SLFVERNOSPF) //alias                        //~v727R~
    {                                                              //~v727I~
        Ppspfi->SPFIflag|=SPFIFSPF;                                //~v727I~
        Ppspfi->SPFIver=atoi(pfmt->SLFver);                        //~v727I~
        Ppspfi->SPFImod=atoi(pfmt->SLFmod);                        //~v727I~
//      Ppspfi->SPFIcdate.year=atoi(pfmt->SLFcdate);               //~v727I~//~vb2JR~
//      Ppspfi->SPFIcdate.year=(USHORT)atoi(pfmt->SLFcdate);       //~vb2JI~//~vb33R~
        setspfdate(pfmt->SLFcdate,&Ppspfi->SPFIcdate);             //~v727I~
        setspfdate(pfmt->SLFudate,&Ppspfi->SPFIudate);             //~v727I~
//      Ppspfi->SPFIutime.hours=atoi(pfmt->SLFutime);              //~v727I~//~vb2JR~
//      Ppspfi->SPFIutime.hours=(USHORT)atoi(pfmt->SLFutime);      //~vb2JI~//~vb33R~
//      Ppspfi->SPFIutime.minutes=atoi(pfmt->SLFutime+3);          //~v727I~//~vb2JR~
//      Ppspfi->SPFIutime.minutes=(USHORT)atoi(pfmt->SLFutime+3);  //~vb2JI~//~vb33R~
//      Ppspfi->SPFIutime.twosecs=atoi(pfmt->SLFutime+6)/2;//unit is 2 sec//~v8@AI~//~vb2JR~
//      Ppspfi->SPFIutime.twosecs=(USHORT)atoi(pfmt->SLFutime+6)/2;//unit is 2 sec//~vb2JI~//~vb33R~
        ueditsetftimeUSHORT(0,atoi(pfmt->SLFutime),atoi(pfmt->SLFutime+3),atoi(pfmt->SLFutime+6)/2,&Ppspfi->SPFIutime);//~vb33I~
        UTRACED("SPFIutime",&Ppspfi->SPFIutime,(int)sizeof(Ppspfi->SPFIutime));//+vb33I~
        Ppspfi->SPFIlinecnt=getenum(pfmt->SLFlinecnt);             //~v72nR~
        Ppspfi->SPFIinitcnt=getenum(pfmt->SLFinitcnt);             //~v72nR~
        pc2=pfmt->SLFuserid;                                       //~v727I~
        WORDEND(pc3,pc2);                                          //~v727I~
//      len=(ULONG)pc3-(ULONG)pc2;                                 //~v727I~//~vafkR~
//      len=(ULPTR)pc3-(ULPTR)pc2;                                 //~vafkI~//~vb30R~
        len=PTRDIFF(pc3,pc2);                                      //~vb30I~
      if (*pc2!='-')		//not space                            //~v72nI~
//      memcpy(Ppspfi->SPFIuserid,pc2,len);                        //~v727I~//~vb30R~
        memcpy(Ppspfi->SPFIuserid,pc2,(size_t)len);                //~vb30I~
    }                                                              //~v727I~
UTRACED("getspfmemblist exit",Ppspfi,PDSSPFINFOSZ);                //~v727R~
    return 0;                                                      //~v727I~
}//getspfmemblist                                                  //~v727R~
//************************************************************     //~v72nI~
//*getenum get number dropping "," seperator                       //~v72nI~
//************************************************************     //~v72nI~
int getenum(char *Pdata)                                           //~v72nI~
{                                                                  //~v72nI~
    char  numwk[12];                                               //~v72nI~
    char *pc,*pco;                                                 //~v72nI~
    int ii;                                                        //~v72nI~
//****************************************                         //~v72nI~
	pc=Pdata+strspn(Pdata," ");                                    //~v72nI~
	for (pco=numwk,ii=0;ii<10;ii++,pc++)                           //~v72nR~
    {                                                              //~v72nI~
    	if (*pc==',')                                              //~v72nI~
        	continue;                                              //~v72nI~
    	if (*pc==' ')                                              //~v72nI~
        	break;                                                 //~v72nI~
        *pco++=*pc;                                                //~v72nI~
    }                                                              //~v72nI~
    *pco=0;                                                        //~v72nI~
	return atoi(numwk);                                            //~v72nI~
}//getenum                                                         //~v72nI~
//**************************************************************** //~v727I~
//*reform date string to FDATE                                     //~v727I~
//**************************************************************** //~v727I~
int setspfdate(char *Pyymmdd,FDATE *Ppfdate)                       //~v727I~
{                                                                  //~v727I~
    int yy,mm,dd;                                                  //~v727I~
//*******************                                              //~v727I~
   	yy=atoi(Pyymmdd);                                              //~v727R~
   	mm=atoi(Pyymmdd+3);                                            //~v727I~
   	dd=atoi(Pyymmdd+6);                                            //~v727I~
  if (!yy&&!mm&&!dd)                                               //~v72nI~
    memset(Ppfdate,0,sizeof(FDATE));                               //~v72nI~
  else                                                             //~v72nI~
    ueditsetfdate(yy,mm,dd,(void*)Ppfdate);                        //~v727R~
    return 0;                                                      //~v727I~
}//setspfdate                                                      //~v727I~
//**************************************************************** //~v719I~
//*dataset list                                                    //~v719I~
//**************************************************************** //~v719I~
//int getdsinf(int Pmembsw,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist)//~v727R~
int getdsinf(char *Pmemb,char *Pbuff,int Plen,PDSNLIST *Pppdsnlist)//~v727I~
{                                                                  //~v719I~
    PDSNLIST pdsnlist;                                             //~v719R~
    int rc=U3CR_RC_OTHER,len,resplen;                              //~v719R~
    int entno,rc2=0;                                                 //~v719R~//~vafcR~
    char *pc,*pce;                                                 //~v719R~
    DSNDATA dsnd;                                                  //~v719R~
    int membnotfound=0;                                            //~v71HI~
//************************                                         //~v719I~
UTRACEP("getdsinf entry\n");                                       //~v719I~
    *Pppdsnlist=0;                                                 //~v719R~
    for (pc=Pbuff,pce=pc+Plen,entno=0;pc<pce;entno++)              //~v719R~
    {                                                              //~v719I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v719I~//~vafkR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~vafkI~//~vb30R~
        len=PTRDIFF(pce,pc);                                       //~vb30I~
        rc2=getdsnentry(pc,len,&dsnd,&pc);                         //~v719R~
        if (rc2>0)                                                 //~v719I~
        {                                                          //~v71fI~
//      	if (Pmembsw && entno==0)	                           //~v727R~
        	if (*Pmemb && entno==0)                                //~v727I~
            	return U3CR_RC_PATHERR;	                           //~v71fI~
    	  if (entno==1 && rc2==U3CR_RC_NOTFOUND)	//member not found//~v71HR~
          {                                                        //~v71HI~
		    membnotfound=1;                                        //~v71HI~
          	rc2=-3;	//break                                        //~v71HR~
          }                                                        //~v71HI~
          else                                                     //~v71HI~
        	return rc2;                                            //~v719I~
        }                                                          //~v71fI~
        if (rc2<0)	//end of list                                  //~v719R~
        	break;                                                 //~v719I~
    }                                                              //~v719I~
    if (!entno)                                                    //~v719I~
    	return U3CR_RC_NOTFOUND;                                   //~v719I~
//  resplen=DSNLHDRSZ+entno*DSNDATASZ;                             //~v719R~//~vb30R~
    resplen=(int)DSNLHDRSZ+entno*(int)DSNDATASZ;                   //~vb30I~
//  pdsnlist=umalloc(resplen);                                     //~v719R~//~vb30R~
    pdsnlist=umalloc((size_t)resplen);                             //~vb30I~
    pdsnlist->DSLhdr.PRDlen=resplen;                               //~v719R~
    pdsnlist->DSLhdr.PRDcount=entno;                               //~v719R~
    pdsnlist->DSLhdr.PRDtype=PRDT_DSNL;                            //~v719I~
    for (pc=Pbuff,entno=0;pc<pce;entno++)                          //~v719R~
    {                                                              //~v719I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v719I~//~vafkR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~vafkI~//~vb30R~
        len=PTRDIFF(pce,pc);                                       //~vb30I~
        rc2=getdsnentry(pc,len,&dsnd,&pc);                         //~v719R~
        if (rc2)                                                   //~v719I~
        	break;                                                 //~v719I~
        memcpy(pdsnlist->DSLentry+entno,&dsnd,sizeof(dsnd));       //~v719R~
    }                                                              //~v719I~
    if (membnotfound)                                              //~v71HI~
        pdsnlist->DSLentry[0].DSDflag|=DSDFMEMBNOTFOUND;           //~v71HI~
    memset(&pdsnlist->DSLspfi,0,sizeof(pdsnlist->DSLspfi));        //~v727I~
    if (rc2==-2)	//member specified                             //~v719I~
    {                                                              //~v727I~
	    strcpy(pdsnlist->DSLspfi.SPFImember,Pmemb);                //~v727I~
        pdsnlist->DSLentry[0].DSDflag|=DSDFMEMB;                   //~v719R~
    }                                                              //~v727I~
    *Pppdsnlist=pdsnlist;                                          //~v719I~
    rc=0;                                                          //~v719I~
UTRACEP("getdsinf exit rc=%d\n",rc);                               //~v719I~
UTRACED("getdsinf",pdsnlist,resplen);                              //~v719R~
    return rc;                                                     //~v719R~
}//getdsinf                                                        //~v719R~
//**************************************************************** //~v719M~
//*set dnslist resp data                                           //~v719I~
//**************************************************************** //~v719M~
//int setdsrespdata(PTHREADTB Ppthtb,char *Phostfile,int Prc,PDSNLIST Ppdsnl)//~v72uR~
int setdsrespdata(int Popt,PTHREADTB Ppthtb,char *Phostfile,int Prc,PDSNLIST Ppdsnl)//~v72uI~
{                                                                  //~v719M~
    int rc;                                                        //~v719I~
//**************************                                       //~v719M~
UTRACEP("setdsrespdata entry\n");                                  //~v719I~
    Ppthtb->THTrespdata=0;                                         //~v719I~
    Ppthtb->THTrespdatalen=0;                                      //~v719I~
	rc=Prc;                                                        //~v719M~
    if (!rc)	//D/S found                                        //~v719M~
    {                                                              //~v719M~
	    Ppthtb->THTrespdata=Ppdsnl;                                //~v719R~
        Ppthtb->THTrespdatalen=Ppdsnl->DSLhdr.PRDlen;              //~v719R~
	  if (!(Popt & SDRD_NOMSG))                                    //~v72uI~
        uerrmsgmt(1,"%d D/S for %s",0,                             //~v719I~
                       Ppdsnl->DSLhdr.PRDcount,Phostfile);         //~v719R~
		memcpy(&Slastdsnd,&Ppdsnl->DSLentry[0],sizeof(Slastdsnd));   //to chk lrecl for putconfirm//~v763R~
    }                                                              //~v719M~
UTRACEP("setdsrespdata rc=%d\n",rc);                               //~v719I~
    return rc;                                                     //~v719M~
}//setdsrespdata                                                   //~v727R~
//**************************************************************** //~v719M~
//*pds memberlist                                                  //~v719M~
//**************************************************************** //~v719M~
int getpdsinf(char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist)      //~v719M~
{                                                                  //~v719M~
    PPDSMEMBLIST ppml;                                             //~v719R~
    int rc=U3CR_RC_OTHER,len;                                      //~v719R~
    int rc2;                                                       //~v719R~
    char *pc;                                                      //~v719R~
    DSNDATA dsnd;                                                  //~v719I~
//************************                                         //~v719M~
UTRACEP("getpdsinf entry\n");                                      //~v719M~
	*Pppmemblist=0;                                                //~v719I~
    memset(&dsnd,0,sizeof(dsnd));                                  //~v719R~
    rc2=getdsnentry(Pbuff,Plen,&dsnd,&pc);                         //~v719I~
    if (rc2)                                                       //~v719I~
    {                                                              //~v71nI~
    	if (rc2==U3CR_RC_NOTFOUND)                                 //~v71fI~
        	return U3CR_RC_PATHERR;                                //~v71fI~
        else                                                       //~v71fI~
	    	return rc;                                             //~v71fR~
    }                                                              //~v71nI~
    if (!(dsnd.DSDflag & DSDFPO))                                  //~v719I~
    	return 0;	//not PDS                                      //~v719I~
    WORDTOP(pc);                                                   //~v719I~
    if (memcmp(pc,"--MEMBERS",9))                                  //~v719R~
        return rc;                                                 //~v719I~
	NEXTLINE(pc,pc);                                               //~v719R~
//  len=Plen-((ULONG)pc-(ULONG)Pbuff);                             //~v719I~//~vafkR~
//  len=Plen-((ULPTR)pc-(ULPTR)Pbuff);                             //~vafkI~//~vb30R~
    len=Plen-PTRDIFF(pc,Pbuff);                                    //~vb30I~
    if (rc=getmember(pc,len,&ppml),rc)                             //~v719R~
    {                                                              //~v719I~
        uerrmsgmt(1,"Listds command output parse failed",0);       //~v719I~
        return rc;                                                 //~v719I~
    }                                                              //~v719I~
    memcpy(&ppml->PMLdsnd,&dsnd,DSNDATASZ);                        //~v719R~
    *Pppmemblist=ppml;                                             //~v719I~
UTRACEP("getpdsinf exit rc=%d\n",rc);                              //~v719M~
    return rc;                                                     //~v719M~
}//getpdsinf                                                       //~v719M~
//**************************************************************** //~v719I~
//*set memblist resp data                                          //~v719I~
//**************************************************************** //~v719I~
int setpdsrespdata(PTHREADTB Ppthtb,char *Pdsn,char *Pmembname,int Prc,PPDSMEMBLIST Pppml)//~v719I~
{                                                                  //~v719I~
    int rc;                                                        //~v719I~
//**************************                                       //~v719I~
UTRACEP("setpdsrespdata entry\n");                                 //~v719I~
    Ppthtb->THTrespdata=0;                                         //~v719I~
    Ppthtb->THTrespdatalen=0;                                      //~v719I~
	rc=Prc;                                                        //~v719I~
    if (!rc)	//D/S found                                        //~v719I~
    {                                                              //~v719I~
        if (Pppml)	//DSORG=PO                                     //~v719I~
        {                                                          //~v719I~
            uerrmsgmt(1,"%s contains %d Member",0,                 //~v719I~
                                    Pdsn,Pppml->PMLhdr.PRDcount);  //~v719R~
		    Ppthtb->THTrespdata=Pppml;                             //~v719R~
	        Ppthtb->THTrespdatalen=Pppml->PMLhdr.PRDlen;           //~v719R~
			memcpy(&Slastdsnd,&(Pppml->PMLdsnd),sizeof(Slastdsnd));   //to chk lrecl for putconfirm//~v763R~
        }                                                          //~v719I~
        else    //DSORG!=PO                                        //~v719I~
        {                                                          //~v719I~
            uerrmsgmt(1,"%s is not DSORG=PO",0,                    //~v719I~
                                Pdsn);                             //~v719I~
			rc=U3CR_RC_OTHER;	                                   //~v719I~
        }                                                          //~v719I~
    }                                                              //~v719I~
UTRACEP("setpdsrespdata rc=%d\n",rc);                              //~v719I~
    return rc;                                                     //~v719I~
}//setpdsrespdata                                                  //~v719I~
//**************************************************************** //~v719I~
//*pds memberlist                                                  //~v719I~
//*ret -:reached to READY                                          //~v719I~
//*resp data format                                                //~v719I~
//HERC01.TEST1.SRC                                                 //~v719I~
//--RECFM-LRECL-BLKSIZE-DSORG                                      //~v719I~
//   FB    80    3120    PO                                        //~v719I~
//--VOLUMES--                                                      //~v719I~
//  PUB002                                                         //~v719I~
//(followinng 2 line are when member name specified)               //~v719I~
//--MEMBER---TTR----ALIAS-TTRN-CNT-DATA                            //~v719I~
//  A11      004A09 NO    0    00                                  //~v719I~
//**************************************************************** //~v719I~
int getdsnentry(char *Pbuff,int Plen,PDSNDATA Ppdsnd,char **Ppnext)//~v719R~
{                                                                  //~v719I~
    int rc=U3CR_RC_OTHER,len;                                      //~v719R~
    char *pc,*pc2,*pc3;                                            //~v719R~
//***********************************                              //~v719I~
UTRACEP("getdsnentry entry\n");                                    //~v71HR~
	memset(Ppdsnd,0,sizeof(DSNDATA));                              //~v719I~
	pc=Pbuff;                    //DSN line                        //~v719R~
    if (Plen<=0)                                                   //~v8@3I~
    	return -1;		//end of list                              //~v8@3I~
    if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))                //~v71eR~
    	return -1;		//end of list                              //~v719M~
    if (!memcmp(pc,"--MEMBER-",9))                                 //~v719I~
    	return -2;		//member specified                         //~v719I~
    WORDTOP(pc);                                                   //~v719I~
    NEXTLINE(pc2,pc);            //--RECFM line                    //~v719R~
    if (!pc2)                                                      //~v719I~
    	return rc;                                                 //~v719I~
    WORDEND(pc3,pc);                                               //~v719R~
//  len=(ULONG)pc3-(ULONG)pc;                                      //~v719I~//~vafkR~
//  len=(ULPTR)pc3-(ULPTR)pc;                                      //~vafkI~//~vb30R~
    len=PTRDIFF(pc3,pc);                                           //~vb30I~
    if (len>=DSN_MAXLEN)                                           //~v719I~
    	return rc;                                                 //~v719I~
//  memcpy(Ppdsnd->DSDdsn,pc,len);	//DSN                          //~v719R~//~vb30R~
    memcpy(Ppdsnd->DSDdsn,pc,(size_t)len);	//DSN                  //~vb30I~
                                                                   //~v719I~
//  len=(ULONG)pc2-(ULONG)pc;                                      //~v719I~//~vafkR~
//  len=(ULPTR)pc2-(ULPTR)pc;                                      //~vafkI~//~vb30R~
    len=PTRDIFF(pc2,pc);                                           //~vb30I~
    if (!memcmp(pc,WORDCHK_MEMBERNOTFOUND,WORDCHK_MEMBERNOTFOUND_SZ))  //member specified but member not found//~v71fR~
        return U3CR_RC_NOTFOUND;                                   //~v71eR~
//  if (umemstri(pc,WORDCHK_NOTCAT,len))  //for not wildcard case  //~v71fI~//~vb30R~
//  if (umemstri(pc,WORDCHK_NOTCAT,(size_t)len))  //for not wildcard case//~vb30I~//~vb31R~
    if (umemstri(pc,WORDCHK_NOTCAT,(unsigned)len))  //for not wildcard case//~vb31I~
    	return U3CR_RC_NOTFOUND;                                   //~v71fM~
//  if (umemstri(pc,"NO DATA",len))     //wildcard case            //~v719R~//~vb30R~
//  if (umemstri(pc,"NO DATA",(size_t)len))     //wildcard case    //~vb30I~//~vb31R~
    if (umemstri(pc,"NO DATA",(unsigned)len))     //wildcard case  //~vb31I~
    	return U3CR_RC_NOTFOUND;                                   //~v719R~
    NEXTLINE(pc3,pc2);	//RECFM data line                          //~v719I~
    if (!pc3)                                                      //~v719I~
    	return rc;                                                 //~v719I~
//  len=(ULONG)pc3-(ULONG)pc2;                                     //~v719I~//~vafkR~
//  len=(ULPTR)pc3-(ULPTR)pc2;                                     //~vafkI~//~vb30R~
    len=PTRDIFF(pc3,pc2);                                          //~vb30I~
    WORDTOP(pc2);                                                  //~v719I~
//  if (umemstri(pc2,WORDCHK_NOTCAT,len))  //not in cat may appear in 2nd line//~v71fI~//~vb30R~
//  if (umemstri(pc2,WORDCHK_NOTCAT,(size_t)len))  //not in cat may appear in 2nd line//~vb30I~//~vb31R~
    if (umemstri(pc2,WORDCHK_NOTCAT,(unsigned)len))  //not in cat may appear in 2nd line//~vb31I~
    	return U3CR_RC_NOTFOUND;                                   //~v71fI~
    if (*pc2!='-')	//--RECFM line                                 //~v719R~
    {                                                              //~v71nI~
	    NEXTLINE(pc3,pc2); //-VOLUME                               //~v71nI~
//    	if (umemstr(pc2,WORDCHK_DSINUSE,(ULONG)pc3-(ULONG)pc2))      	//ALREADY IN USE(cannot allocat)//~v71nI~//~vafkR~
//  	if (umemstr(pc2,WORDCHK_DSINUSE,(ULPTR)pc3-(ULPTR)pc2))      	//ALREADY IN USE(cannot allocat)//~vafkI~//~vb31R~
    	if (umemstr(pc2,WORDCHK_DSINUSE,(unsigned)PTRDIFF(pc3,pc2)))      	//ALREADY IN USE(cannot allocat)//~vb31I~
    	{                                                          //~v71nI~
            rc=U3CR_RC_INUSE;                                      //~v72nI~
        	*pc3=0;                                                //~v71nI~
        	uerrmsgmt(1,"%s",0,                                    //~v71nI~
            	           pc2);                                   //~v71nI~
    	}                                                          //~v71nI~
    	return rc;                                                 //~v719I~
    }                                                              //~v71nI~
	if (getdsorg(pc3,len,Ppdsnd))                                  //~v719R~
    	return rc;                                                 //~v719I~
    NEXTLINE(pc2,pc3); //-VOLUME                                   //~v719R~
    if (!pc2)                                                      //~v719I~
    	return rc;                                                 //~v719I~
    for (;;)                                                       //~v719I~
    {                                                              //~v719I~
    	NEXTLINE(pc2,pc2); //vol data                              //~v719R~
        if (!pc2)                                                  //~v719I~
        	return rc;                                             //~v719I~
        if (*pc2!=' ')   //not vol data                            //~v719I~
        	break;                                                 //~v719I~
    }                                                              //~v719I~
    *Ppnext=pc2;                                                   //~v719R~
UTRACEP("getdsnentry exit\n");                                     //~v71HR~
UTRACED("getdsnentry exit",Ppdsnd,DSNDATASZ);                      //~v71HR~
    return 0;                                                      //~v719I~
}//getdsnentry                                                     //~v719I~
//**************************************************************** //~v719I~
//*get dsorg                                                       //~v719I~
//**************************************************************** //~v719I~
int getdsorg(char *Pline,int Plen,PDSNDATA Ppdsd)                  //~v719I~
{                                                                  //~v719I~
	int rc,len;                                                    //~v719I~
    char *pc,*pc2;                                                 //~v719I~
//************************                                         //~v719I~
UTRACEP("getdsorg  entry\n");                                      //~v71nI~
	pc=Pline;                                                      //~v719I~
//  if (umemstri(pc," PO ",Plen))                                  //~v719I~//~vb30R~
//  if (umemstri(pc," PO ",(size_t)Plen))                          //~vb30I~//~vb31R~
    if (umemstri(pc," PO ",(unsigned)Plen))                        //~vb31I~
    	Ppdsd->DSDflag|=DSDFPO;     //DSORG=PO                     //~v719I~
    else                                                           //~v719I~
//  if (umemstri(pc," PS ",Plen))                                  //~v719I~//~vb30R~
//  if (umemstri(pc," PS ",(size_t)Plen))                          //~vb30I~//~vb31R~
    if (umemstri(pc," PS ",(unsigned)Plen))                        //~vb31I~
    	Ppdsd->DSDflag|=DSDFPS;     //DSORG=PS                     //~v719I~
    WORDTOP(pc);                                                   //~v719I~
//  for (rc=4;;)                                                   //~v720R~
    for (rc=0;;)                                                   //~v720I~
    {                                                              //~v719I~
        if (*pc=='V')                                              //~v719I~
            Ppdsd->DSDflag|=DSDFV;     //RECFM=V                   //~v719I~
        else                                                       //~v719I~
        if (*pc=='F')                                              //~v719I~
            Ppdsd->DSDflag|=DSDFF;     //RECFM=F                   //~v719I~
        pc++;                                                      //~v719I~
        if (*pc=='B')                                              //~v719I~
            Ppdsd->DSDflag|=DSDFB;     //RECFM=B                   //~v719I~
	    WORDEND(pc,pc);                                            //~v719R~
        if (!pc||*pc=='\n')                                        //~v719R~
            break;                                                 //~v719I~
        WORDTOP(pc);					//LRECL                    //~v719R~
	    WORDEND(pc2,pc);                                           //~v719R~
        if (!pc2||*pc2=='\n')                                      //~v719R~
            break;                                                 //~v719I~
//      len=(ULONG)pc2-(ULONG)pc;                                  //~v719I~//~vafkR~
//      len=(ULPTR)pc2-(ULPTR)pc;                                  //~vafkI~//~vb30R~
        len=PTRDIFF(pc2,pc);                                       //~vb30I~
        if (*pc!='*')		//not defined LRECL                    //~v71nI~
        	if (unumlen(pc,0,len)!=len)     //LRECL                //~v71nR~
            	break;                                             //~v71nR~
        Ppdsd->DSDlrecl=atoi(pc);                                  //~v719I~
        pc=pc2;                                                    //~v719I~
        WORDTOP(pc);                                               //~v719I~
	    WORDEND(pc2,pc);                                           //~v719R~
        if (!pc2)                                                  //~v719I~
            break;                                                 //~v719I~
//       len=(ULONG)pc2-(ULONG)pc;                                  //~v719I~//~vafkR~
//       len=(ULPTR)pc2-(ULPTR)pc;                                 //~vafkI~//~vb30R~
         len=PTRDIFF(pc2,pc);                                      //~vb30I~
        if (*pc!='*')		//not defined LRECL                    //~v71nI~
	        if (unumlen(pc,0,len)!=len)     //BLKSZ                //~v71nR~
    	        break;                                             //~v71nR~
        Ppdsd->DSDblksize=atoi(pc);                                //~v719R~
        return 0;                                                  //~v719R~
    }//for                                                         //~v719I~
    Ppdsd->DSDflag|=DSDFVS;     //unknown fmt(VSAM)                //~v720R~
UTRACEP("getdsorg exit rc=%d\n",rc);                               //~v71nI~
    return rc;                                                     //~v719I~
}//getdsorg                                                        //~v719I~
//**************************************************************** //~v719I~
//*pds member list                                                 //~v719I~
//**************************************************************** //~v719I~
int getmember(char *Pbuff,int Plen,PPDSMEMBLIST *Pppmemblist)      //~v719I~
{                                                                  //~v719I~
    PPDSMEMBLIST ppml;                                             //~v719I~
    PPDSSPFINFO  pspfi;                                            //~v727I~
    int rc=U3CR_RC_OTHER,len,lenpml,membcnt;                       //~v719R~
    char *pc,*pce,*pc2,*pc3,*pmemb;                                //~v719I~
//************************                                         //~v719I~
UTRACEP("getmember entry\n");                                      //~v719I~
//  rc=0;                                                          //~v72tI~
    for (membcnt=0,pc=Pbuff,pce=Pbuff+Plen;pc<pce;)                //~v719I~
    {                                                              //~v719I~
        if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))            //~v71eR~
            break;                                                 //~v719I~
        WORDTOP(pc);                                               //~v719M~
        if (!memcmp(pc,WORDCHK_INVALIDALIAS,WORDCHK_INVALIDALIAS_SZ))  // member "READY" not start at col1//~v72tI~
            break;                                                 //~v72tI~
	    NEXTLINE(pc2,pc);                                          //~v719R~
        if (!pc2)                                                  //~v719I~
            return rc;                                             //~v719R~
	    WORDEND(pc3,pc);                                           //~v719R~
        if (!pc3)                                                  //~v719I~
            return rc;                                             //~v719R~
//      len=(ULONG)pc3-(ULONG)pc;                                  //~v719I~//~vafkR~
//      len=(ULPTR)pc3-(ULPTR)pc;                                  //~vafkI~//~vb30R~
        len=PTRDIFF(pc3,pc);                                       //~vb30I~
        if (len>DSN_MAXMEMBERNAMELEN)                              //~v719I~
            return rc;                                             //~v719R~
        membcnt++;                                                 //~v719I~
        pc=pc2;                                                    //~v719R~
    }                                                              //~v719I~
//  lenpml=PDSMEMBLISTHDRSZ+PMLMEMBNAMEFLDSZ*membcnt;              //~v727R~
//  lenpml=PDSMEMBLISTHDRSZ+PDSSPFINFOSZ*membcnt;                  //~v727I~//~vb30R~
    lenpml=(int)PDSMEMBLISTHDRSZ+(int)PDSSPFINFOSZ*membcnt;        //~vb30I~
//  ppml=(PPDSMEMBLIST)umalloc(lenpml);                            //~v719R~//~vb30R~
    ppml=(PPDSMEMBLIST)umalloc((size_t)lenpml);                    //~vb30I~
//  memset(ppml,0,lenpml);                                         //~v719I~//~vb30R~
    memset(ppml,0,(size_t)lenpml);                                 //~vb30I~
    ppml->PMLhdr.PRDlen=lenpml;                                    //~v719R~
    ppml->PMLhdr.PRDcount=membcnt;                                 //~v719R~
    ppml->PMLhdr.PRDtype=PRDT_MEMBL;                               //~v719I~
//  pmemb=ppml->PMLmember[0];                                      //~v727R~
    pspfi=ppml->PMLmember;                                         //~v727I~
    for (pc=Pbuff;pc<pce;)                                         //~v719I~
    {                                                              //~v719I~
        pmemb=pspfi->SPFImember;                                   //~v727R~
        if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))  // member "READY" not start at col1//~v71eR~
            break;                                                 //~v719I~
        WORDTOP(pc);                                               //~v719M~
        if (!memcmp(pc,WORDCHK_INVALIDALIAS,WORDCHK_INVALIDALIAS_SZ))  // member "READY" not start at col1//~v72tI~
            break;                                                 //~v72tI~
	    NEXTLINE(pc2,pc);                                          //~v719R~
	    WORDEND(pc3,pc);                                           //~v719R~
//      len=(ULONG)pc3-(ULONG)pc;                                  //~v719I~//~vafkR~
//      len=(ULPTR)pc3-(ULPTR)pc;                                  //~vafkI~//~vb30R~
        len=PTRDIFF(pc3,pc);                                       //~vb30I~
//      memcpy(pmemb,pc,len);                                      //~v719I~//~vb30R~
        memcpy(pmemb,pc,(size_t)len);                              //~vb30I~
//      pmemb+=PMLMEMBNAMEFLDSZ;                                   //~v727R~
        pspfi++;                                                   //~v727I~
        pc=pc2;                                                    //~v719R~
    }                                                              //~v719I~
    rc=0;                                                          //~v72tR~
    *Pppmemblist=ppml;                                             //~v719I~
UTRACEP("getmember exit rc=%d\n",rc);                              //~v719I~
UTRACED("memblist",ppml,lenpml);                                   //~v719I~
    return 0;                                                      //~v719I~
}//getmember                                                       //~v719I~
//**************************************************************** //~v719I~
//*accum multiple page output data                                 //~v719I~
//**************************************************************** //~v719I~
int getfulldata(int Popt,PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz,int Prow,char **Ppoutbuff,int *Ppoutbufflen)//~v719R~
{                                                                  //~v719I~
    int rc=0,rc2,readlen,totlen=0,contsw,/*row,*/rowstart,opt;         //~v8@mR~//~vaa7R~
    char *pfulldata=0,*pc,*pc0,*pc2;                               //~v8@mR~
    int reenterresp=0;                                             //~v719R~
    int spfmode=0;                                                 //~v8@3I~
//************************                                         //~v719I~
UTRACEP("getfulldata start row=%d\n",Prow);                        //~v719I~
    *Ppoutbuff=0;                                                  //~v71fI~
    *Ppoutbufflen=0;                                               //~v71fI~
	rowstart=Prow;                                                 //~v719I~
  	if (THT_ISSPF(Ppthtb))   //screen is spf panel mode            //~v8@4I~
    {                                                              //~v8@bI~
    	if (Popt & SENDO_CHKSPF) //tso cmd,chk lastrow at snap3270 //~v8@4I~
  		{                                                          //~v8@4I~
    		rowstart=-1;    //read tso cmd resonse from row=0      //~v8@4I~
    		spfmode=1;                                             //~v8@4I~
  		}                                                          //~v8@4I~
    }                                                              //~v8@bI~
    else                                                           //~v8@fI~
	    Popt &= ~SENDO_CHKSPF; //READY mode                        //~v8@fI~
    for (;;)                                                       //~v719I~
    {                                                              //~v719I~
		opt=SENDO_CHK3AST|SENDO_DROPSTATUS|SENDO_SNAPPRINT|Popt;   //~v8@mR~
    	if (rowstart>=0)                                           //~v719I~
        {                                                          //~v719I~
    		Ppthtb->THTstartrow=rowstart;                          //~v719R~
			opt|=SENDO_SELECTROW;                                  //~v719I~
            rowstart=-1;                                           //~v719I~
        }                                                          //~v719I~
		rc2=snap3270(opt,Ppthtb,Pbuff,Pbuffsz,&readlen);           //~v719R~
        if (rc2 & RECVRC_3ASTERISK)                                //~v8@mR~
        	contsw=1;                                              //~v8@mI~
        else                                                       //~v8@mI~
	        contsw=0;                                              //~v8@mI~
//      if (rc2==RECVRC_REENTER)                                   //~v8@mR~
        if (rc2 & RECVRC_REENTER)                                  //~v8@mI~
        {                                                          //~v719I~
        	reenterresp=RECVRC_REENTER;                            //~v719I~
            rc2=0;                                                 //~v719I~
        }                                                          //~v719I~
        if (rc2 & RECVRC_3ASTERISK)                                //~v8@mR~
            rc2=0;                                                 //~v8@mI~
    	if (rc2)                                                   //~v719I~
        {                                                          //~v719I~
//      	rc=rc2;                                                //~v8@mR~
	    	uerrmsgmt(0,"%s",0,                                    //~v719I~
						Pbuff);                                    //~v719I~
        	if (rc2 & RECVRC_SPFNODATA)                            //~v8@mI~
            	break;                                             //~v8@mI~
        	rc=rc2;                                                //~v8@mI~
        }                                                          //~v719I~
        pc0=Pbuff;                                                 //~v719I~
//      row=Ppthtb->THTcurrow;                                     //~v719I~//~vaa7R~
//        contsw=0;                                                //~v8@mR~
//        if (spfmode || row+1==Ppthtb->THTmaxrow)    //tso mode under spf panel or reached to end of line//~v8@mR~
//        {                                                        //~v8@mR~
//            pc=umemrchr(pc0,'\n',readlen);  //last line "\"      //~v8@mR~
//            if (pc)                                              //~v8@mR~
//            {                                                    //~v8@mR~
//                len=(ULONG)pc-(ULONG)pc0;   //last line "\"      //~v8@mR~
//                pc2=umemrchr(pc0,'\n',len-1);   //last line "\"  //~v8@mR~
//                if (pc2)                                         //~v8@mR~
//                {                                                //~v8@mR~
//                    pc2++;                                       //~v8@mR~
//                    pc=pc2;                                      //~v8@mR~
//                    WORDTOP(pc);                                 //~v8@mR~
//                    if (!memcmp(pc,"***",3))                     //~v8@mR~
//                    {                                            //~v8@mR~
//                        contsw=1;                                //~v8@mR~
//                        readlen=(ULONG)pc2-(ULONG)pc0;           //~v8@mR~
//                    }                                            //~v8@mR~
//                }                                                //~v8@mR~
//            }                                                    //~v8@mR~
        if (contsw)                                                //~v8@mI~
        {                                                          //~v8@mI~
            pc2=ustrrstr(pc0,WORDCHK_PENDINGENTER);   //last "***" //~v8@mR~
            if (pc2)                                               //~v8@mI~
            {                                                      //~v8@mI~
//              readlen-=strlen(pc2);                              //~v8@mI~//~vb30R~
                readlen-=(int)strlen(pc2);                         //~vb30I~
                *pc2=0;                                            //~v8@mI~
            }                                                      //~v8@mI~
        }                                                          //~v8@mI~
		if (!rc)                                                   //~v719R~
        {                                                          //~v719I~
          if (readlen>0)                                           //~v8@mI~
          {                                                        //~v8@mI~
//          pc=umalloc(totlen+readlen+1);                          //~v719R~//~vb30R~
            pc=umalloc((size_t)(totlen+readlen+1));                //~vb30I~
            if (totlen)                                            //~v719I~
            {                                                      //~v719I~
//          	memcpy(pc,pfulldata,totlen);                       //~v719I~//~vb30R~
            	memcpy(pc,pfulldata,(size_t)totlen);               //~vb30I~
        		ufree(pfulldata);                                  //~v719R~
            }                                                      //~v719I~
//          memcpy(pc+totlen,pc0,readlen);                         //~v719R~//~vb30R~
            memcpy(pc+totlen,pc0,(size_t)readlen);                 //~vb30I~
            *(pc+totlen+readlen)=0;                                //~v719R~
            pfulldata=pc;                                          //~v719I~
            totlen+=readlen;                                       //~v719I~
          }                                                        //~v8@mI~
        }                                                          //~v719I~
        if (!contsw)                                               //~v719I~
        	break;                                                 //~v719I~
    	if (rc2=funcenter(SENDO_DROPSTATUS|SENDO_NORESPMSG,Ppthtb),rc2)//~v8@4R~
        	rc=rc2;                                                //~v719I~
    }                                                              //~v719I~
    if (rc||!totlen)                                               //~v719I~
    {                                                              //~v719I~
    	if (pfulldata)                                             //~v719I~
        	ufree(pfulldata);                                      //~v719R~
      if (!rc && spfmode)  //totlen=0 is ok for spfmode            //~v8@fR~
	    uerrmsgmt(1,"No error resonse\n",0);                       //~v8@fI~
      else                                                         //~v8@fI~
      {                                                            //~v8@fI~
	    uerrmsgmt(1,"No command resonse gotten\n",0);              //~v71nI~
	    rc=U3CR_RC_OTHER;                                          //~v71nI~
      }                                                            //~v8@fI~
    }                                                              //~v719I~
    else                                                           //~v719I~
    {                                                              //~v719I~
UTRACED("getfulldata",pfulldata,totlen);                           //~v71eM~
        if (reenterresp && (Popt & SENDO_BREAKREENTER))            //~v71eI~
        {                                                          //~v71eI~
            pc=ustrrstr(pfulldata,WORDCHK_REENTER);                //~v71gI~
            if (pc)                                                //~v71gI~
                *pc=0;                                             //~v71gI~
            rc=funcbreak(Ppthtb);     //break by PA(1)             //~v71gR~
            if (!rc)                                               //~v71fI~
            	uerrmsgmt(1,"Cmd Breaked:%s\n",0,                  //~v71fR~
                            pfulldata);                            //~v71eI~
            else                                                   //~v71gI~
            {                                                      //~v71gI~
        	    rc=funcbreak2(Ppthtb); //break by reply dummy      //~v71gI~
                if (!rc)                                           //~v71gI~
	            	uerrmsgmt(1,"Cmd Breaked2:%s\n",0,             //~v71gI~
    	                        pfulldata);                        //~v71gI~
                else                                               //~v71gI~
	            	uerrmsgmt(1,"%s\n",0,                          //~v71gR~
	                            pfulldata);                        //~v71gR~
            }                                                      //~v71gI~
        	ufree(pfulldata);                                      //~v71eI~
            reenterresp=0;                                         //~v71eI~
	    	rc=U3CR_RC_OTHER;                                      //~v71eI~
        }                                                          //~v71eI~
        else                                                       //~v71eI~
        {                                                          //~v71eI~
    		*Ppoutbuff=pfulldata;                                  //~v71eR~
    		*Ppoutbufflen=totlen;                                  //~v71eR~
        }                                                          //~v71eI~
    }                                                              //~v719I~
    rc|=reenterresp;                                               //~v719I~
UTRACEP("getfulldata exit rc=%d,totlen=%d\n",rc,totlen);           //~v719R~
    return rc;                                                     //~v719I~
}//getfulldata                                                     //~v719I~
//**************************************************************** //~v72nI~
//*update spf info                                                 //~v72nI~
//*  return                                                        //~v72nI~
//**************************************************************** //~v72nI~
int funcspf(PTHREADTB Ppthtb)                                      //~v72nI~
{                                                                  //~v72nI~
    char **popd,cmd[MAX_CMDSZ],*phostfile,*pbuff;                  //~v72nR~
	char buff[MAX_SCREENSZ],*spfparm;                              //~v72nR~
    int rc,readlen,row;                                            //~v72uR~
    PDSNLIST pdsnlist=0;                                           //~v72nI~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v72nI~
    char dsn[DSN_MAXLEN]={0};                                      //~v72nI~
    int opt;                                                       //~v8@4I~
//************************                                         //~v72nI~
    if (!(G3270opt & G3270OPT_SPFLVL2))                            //~v72nR~
    {                                                              //~v72nI~
        uerrmsgmt(1,"SPF update not allowed by configuration parm %s\n",0,//~v72nI~
        			CONFIGP_SPFLEVEL);                             //~v72nI~
	    return U3CR_RC_NOTSUPPORT;                                 //~v72nR~
    }                                                              //~v72nI~
UTRACEP("funcspf entry\n");                                        //~v72nI~
//    rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
//    if (rc)                                                      //~v8@3R~
//    {                                                            //~v8@3R~
//UTRACEP("funclistds no READY found\n");                          //~v8@3R~
//        return rc;                                               //~v8@3R~
//    }                                                            //~v8@3R~
//  if (rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb),rc)     //~v8@tR~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@tI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@tI~
    	return rc;                                                 //~v8@3I~
    screenclear(2,Ppthtb);	//may b2 2 line                        //~v8@wR~
    row=Ppthtb->THTcurrow;                                         //~v72nI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v72nI~//~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    phostfile=popd[PARM_HOSTFILE];                                 //~v72nI~
    spfparm=popd[PARM_HOSTFILE+1];                                 //~v72nR~
                                                                   //~v72nI~
    if (!(u3270parsedsn(U3PD_DROPQUOTE,phostfile,dsn,membname) & U3PD_RC_MEMBER))	//0:no set dummy member even if not specified//~v72nR~
    {                                                              //~v72nI~
        uerrmsgmt(1,"SPF update parm err;Specify member name\n",0);//~v72nI~
	    return U3CR_RC_OTHER;                                      //~v72nI~
    }                                                              //~v72nI~
	sprintf(cmd,"String \"%s '1,%s(%s),%s'\\n\"",G3270memblistcmd,dsn,membname,spfparm);//~v72nR~
//  if (rc=send3270(SENDO_DROPSTATUS,Ppthtb,cmd),rc)               //~v8@bR~
    opt=SENDO_DROPSTATUS|SENDO_WAIT_OUTPUT;                        //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;                                                 //~v72nI~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=getfulldata(SENDO_REENTERCHK|SENDO_BREAKREENTER,Ppthtb,buff,MAX_SCREENSZ,row,&pbuff,&readlen);//~v8@4R~
    opt=SENDO_REENTERCHK|SENDO_BREAKREENTER|SENDO_CHKSPF;          //~v8@4I~
    rc=getfulldata(opt,Ppthtb,buff,MAX_SCREENSZ,row,&pbuff,&readlen);//~v8@4I~
//  if (!rc)                                                       //~v8@GR~
    if (!rc && pbuff)                                              //~v8@GI~
    {                                                              //~v72nI~
//  	rc=getspfpdsmembinf(dsn,membname,pbuff,readlen,&pdsnlist); //~v72uR~
    	rc=getspfpdsmembinf(GSPFMO_ERRMEMBNF,    //return by err if member not found//~v72uI~
                            Ppthtb,                                //~v8@3I~
							dsn,membname,pbuff,readlen,&pdsnlist); //~v72uI~
//      rc=setdsrespdata(Ppthtb,dsn,rc,pdsnlist);                  //~v72uR~
        rc=setdsrespdata(SDRD_NOMSG,Ppthtb,dsn,rc,pdsnlist);       //~v72uI~
    }                                                              //~v72nI~
    if (pbuff)                                                     //~v72nI~
        ufree(pbuff);                                              //~v72nI~
UTRACEP("funcspf exit rc=%d,pdsnlist=%p\n",rc,pdsnlist);           //~v72nR~
    return rc;                                                     //~v72nI~
}//funcspf                                                         //~v72nI~
//**************************************************************** //~v72nI~
//*xe4s001z response msg hdr chk                                   //~v72nI~
//*liseturn                                                        //~v72nI~
//**************************************************************** //~v72nI~
//int listuserresphdrchk(char *Pdsn,char *Pbuff,DSNDATA *Ppdsnd,char **Pptopline)//~v8@3R~
int listuserresphdrchk(int Popt,PTHREADTB Ppthtb,char *Pdsn,char *Pbuff,DSNDATA *Ppdsnd,char **Pptopline)//~v8@3I~
{                                                                  //~v72nI~
    char *pc=NULL,*pc2;                                                 //~v72nI~//~vafdR~
    char *pc3;                                                     //~v8@wI~
    int rc=U3CR_RC_OTHER,hdrsw=0;                                  //~v72nI~
//***************                                                  //~v72nI~
UTRACEP("spfhdrchk %s\n",Pbuff);                                   //~v8@wI~
    for (pc3=Pbuff;pc3;)                                           //~v8@wI~
    {                                                              //~v8@wI~
        pc=pc3;                                                    //~v8@wI~
        NEXTLINE(pc3,pc);                                          //~v8@wI~
        if (!memcmp(pc," * STOW FAILED",14))                       //~v8@wM~
        {                                                          //~v8@wM~
UTRACEP("STOW failed\n");                                          //~v8@wM~
            rc=U3CR_RC_STOWFAILED;                                 //~v8@wM~
            return rc;                                             //~v8@wI~
        }                                                          //~v8@wM~
    }                                                              //~v8@wI~
    pc2=Pbuff;                                                     //~v72nI~
  if (!THT_ISSPF(Ppthtb))  //screen is spf panel mode              //~v8@3I~
    for (;pc2;)                                                    //~v72nI~
    {                                                              //~v72nI~
        pc=pc2;                                                    //~v72nI~
	    if (!pc)                                                   //~v72nI~
    		return rc;                                             //~v72nI~
        WORDTOP(pc);                                               //~v72nI~
        NEXTLINE(pc2,pc);                                          //~v72nI~
        if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))            //~v72nI~
            return rc;                                             //~v72nI~
        if (!memicmp(pc,G3270memblistcmd,strlen(G3270memblistcmd)))//~v72nI~
            break;                                                 //~v72nI~
    }                                                              //~v72nI~
	for (;pc2;)                                                    //~v72nI~
    {                                                              //~v72nI~
        pc=pc2;                                                    //~v72nI~
	    if (!pc)                                                   //~v72nI~
    		return rc;                                             //~v72nI~
        NEXTLINE(pc2,pc);                                          //~v72nI~
        if (!memcmp(pc,WORDCHK_READY,WORDCHK_READY_SZ))            //~v72nI~
            return rc;                                             //~v72nI~
        if (!memcmp(pc," * NOT-CAT",10))                           //~v72nI~
            return U3CR_RC_PATHERR;                                //~v72nI~
        if (!memcmp(pc," * IN-USE",9))                             //~v72nI~
        {                                                          //~v72nI~
            rc=U3CR_RC_INUSE;                                      //~v72nI~
            break;                                                 //~v72nI~
        }                                                          //~v72nI~
        if (!memcmp(pc," * ",3))    //xe4s001z err                 //~v72nI~
        	break;                                                 //~v72nI~
        if (!memcmp(pc,"MEMBER LIST",11))                          //~v72nR~
        {                                                          //~v72nI~
            hdrsw=1;                                               //~v72nI~
            break;                                                 //~v72nI~
        }                                                          //~v72nI~
    }                                                              //~v72nI~
    if (!hdrsw && pc)                                              //~v72nI~
    {                                                              //~v72nI~
        uerrmsgmt(1,"%s",0,                                        //~v72nI~
                       pc);                                        //~v72nI~
        return rc;                                                 //~v72nI~
    }                                                              //~v72nI~
    if (!pc2)                                                      //~v72nI~
        return rc;                                                 //~v72nI~
    pc=pc2;                                                        //~v72nI~
	getspfdsinf(Pdsn,pc,Ppdsnd);                                   //~v72nR~
	NEXTLINE(pc,pc);                                               //~v72nI~
    if (!pc)                                                       //~v72nI~
        return rc;                                                 //~v72nI~
    if (memcmp(pc,"-NAME---",8))                                   //~v72nI~
        return rc;                                                 //~v72nI~
    *Pptopline=pc;			//"-NAME" line                         //~v72nI~
    return 0;                                                      //~v72nI~
}//listuserresphdrchk                                              //~v72nI~
//**************************************************************** //~v763I~
//*get last LISTDS dsndata                                         //~v763I~
//*rc 4:not saved                                                  //~v763I~
//*rc 8:dsn unmatch                                                //~v763I~
//**************************************************************** //~v763I~
int getlatestdsndata(char *Pdsn,PDSNDATA Ppdsnd)                   //~v763I~
{                                                                  //~v763I~
    char dsn[DSN_MAXLEN];                                          //~v763I~
//*************************                                        //~v763I~
	memcpy(Ppdsnd,&Slastdsnd,DSNDATASZ);	//for MT               //~v763I~
	if (!Ppdsnd->DSDdsn[0])	//not saved                            //~v763I~
    	return 4;                                                  //~v763I~
	if (!Pdsn)        		//no dsn chk                           //~v763I~
    	return 0;                                                  //~v763I~
    u3270parentdsn(U3PL_DROPMEMBER,Pdsn,dsn);	//get dsn without QUOTE//~v763R~
//  printf("getlastdsndata saved=%s,chk=%s,parm=%s\n",Ppdsnd->DSDdsn,dsn,Pdsn);//~v763R~
	if (strcmp(dsn,Ppdsnd->DSDdsn))	//dsn unmatch                  //~v763I~
    	return 8;                                                  //~v763I~
    return 0;                                                      //~v763I~
}//getlatestdsndata                                                //~v763I~
