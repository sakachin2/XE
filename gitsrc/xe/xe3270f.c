//*CID://+vv31R~:                              update#= 1471;      //+vv31R~
//*************************************************************
//vb31:160418 (LNX64)Compiler warning                              //+vv31I~
//vb30:160411 (LNX)Compiler warning                                //~vv30I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//v7af:081113 (3270) add "Continue" to logon err action to do not abandon logon//~v7afI~
//                   "&errmsg" :chk after okmsg exist chk          //~v7afI~
//v79d:080815 (3270:BUG)ftp reposnse data(suchas TRANSxx ...) has no screen line herader//~v79dI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v9@b:080718 3270:no echo option for rsh cmd                      //~v9@bI~
//v9@7:080717 3270:reject PFx from RSH when no TSO session exist to avoid field protecion err//~v9@7I~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v8@P:080710 3270:no snap data printed when not FS mode RSH       //~v8@PI~
//v8@H:080629 3270:display cursor position for rsh mode            //~v8@HI~
//v8@E:080627 3270:logon errmsg is not returned to xe if action executed//~v8@EI~
//v8@y:080625 3270:line mode by READY detection on last line at snap3270//~v8@yI~
//v8@x:080625 3270:sometime FTP wait(readresp hung) free line may be required for READY mode//~v8@xI~
//v8@t:080623 3270:cursor move to =6 panel home for cmd(ftp,listds,..) input//~v8@tI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v8@q:080620 3270:enter/reenter chk last line only                //~v8@qR~
//v8@p:080620 3270:split xe3270.c =.xe3270.c+xe3270f.c             //~v8@mI~
//*************************************************************
//*xe3270f.c                                                       //~v8@mR~
//*func___                                                         //~v8@pI~
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
    #include <pthread.h>                                           //~v715R~
    #include <sys/stat.h>                                          //~v715I~
    #include <sys/wait.h>                                          //~v715I~
    #include <signal.h>                                            //~v715I~
#else                                                              //~v715R~
    #include <errno.h>                                             //~v71eM~
#include <io.h>                                                    //~v715R~
#include <process.h>                                               //~v715R~
#include <conio.h>                                                 //~v715R~
                                                                   //~v715R~
#include <windows.h>
#endif                                                             //~v715R~
//**********
#include <ulib.h>
#include <ualloc.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>
#include <uedit.h>
#include <utrace.h>
#include <ufile.h>
#include <ufile3.h>                                                //~v725I~
#include <ufile4.h>                                                //~v71RR~
#include <ufile5.h>                                                //~v71RI~
#include <ustring.h>
#include <uftp.h>
#include <u3270.h>                                                 //~v716I~
#include <ucvext.h>                                                //~v79aI~

#include "xe.h"
#include "xe3270.h"
#include "xe3270s.h"                                               //~v725I~
//*************************************************************
#define RESP_COMPLETE        "complete"
#define RESP_FILENOTFOUND    "File not Open"
//*************************************************************
//*************************************************************
#define STATUS_OK     "ok\n"		//cmd resp line
#define STATUS_ERROR  "error\n"
#define STATUS_POS_CONNECT  6 //(4th char C:connected)   //3270 status line
#define STATUS_CONNECT     'C'
#define STATUS_POS_FORMAT   2 //(2nd char F:formatted)   //3270 status line//~v715I~
#define STATUS_FORMAT      'F'                                     //~v715I~
                                                                   //~v8@3I~
#define LINEHDR    "data: "                                        //~v8@3M~
#define LINEHDRSZ  6                                               //~v8@3M~
//*************************************************************
//*************************************************************
int snap3270printline(char *Pscrdata);                             //~v72BI~

int write3270readresp(int Popt,PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz,int *Pplen);

int funcclear(int Popt,PTHREADTB Ppthtb);                          //~v716R~

int read3270(PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz);
int screenstrchk(int Popt,char *Pbuff,char *Pvalidresp);
//int editresp(int Popt,int Pstartrow,char *Pbuff,int Plen);       //~v8@3R~
int editresp(int Popt,PTHREADTB Ppthtb,int Pstartrow,char *Pbuff,int Plen);//~v8@3I~
//***************************************************************************************
//****************************************************************
//*3270 sub process start
//****************************************************************
int funcconnect(PTHREADTB Ppthtb)
{
    char **popd,cmd[MAX_CMDSZ],*phost;
    int rc,port;
//************************
UTRACEP("funcconnect entry\n");
    rc=send3270(0,Ppthtb,"Snap");
    if (!rc)
    {
UTRACEP("funcconnect already connected\n");
		return 0;
    }
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    phost=popd[PARM_HOST];
    if (strchr(phost,':'))	//port specied
	    sprintf(cmd,"Connect %s",phost);
    else
    {
    	port=Ppthtb->THTport;
	    sprintf(cmd,"Connect %s:%d",phost,port);
    }
//  rc=send3270(0,Ppthtb,cmd);                                     //~v715R~
    rc=send3270(SENDO_RCHK_FORMAT,Ppthtb,cmd);	//chk response status line format flag//~v715I~
  if (!(rc & RECVRC_ERR)||!(rc & RECVRC_NOTFORMATTED))   //not errmsg returned or screen formatted//~v715R~
  {                                                                //~v715I~
    if (rc & RECVRC_NOTCONNECT)                                    //~v715I~
    {
    	screenchk(SENDO_SNAPPRINT|SENDO_DROPSTATUS,Ppthtb,0);
        rc=4;
    }
    else
    {
    	wait3270(SENDO_WAIT_INPUTF,Ppthtb,1);
	    funcsnap(SENDO_SNAPPRINT,Ppthtb);                          //~v715I~
        rc=0;
    }
  }                                                                //~v715I~
//  funcsnap(SENDO_SNAPPRINT,Ppthtb);                              //~v715R~
UTRACEP("funcconnect exit rc=%d\n",rc);
    return rc;
}//funcconnect
//****************************************************************
//*logon process
//****************************************************************
int funclogon(PTHREADTB Ppthtb)
{
    char **popd,cmd[MAX_CMDSZ],*verb,*pc,userpswd[THTUSERNAMESZ+FTP_PSWDNAMELEN+1];
	char buff[MAX_SCREENSZ],*pbuff;                                //~v719I~
    int rc,rc2,readlen;                                            //~v71eR~
    int opt;                                                       //~v72CI~
    int pswdsw=0;                                                  //~v8@bI~
//************************
UTRACEP("funclogon entry\n");
//  rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
	if (Ppthtb->THTflag & THTF_LOGON)	//once logoned             //~v8@tI~
    {                                                              //~v8@tI~
	    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_LOGON;               //~v8@tI~
        rc=cmdreadychk(opt,Ppthtb);                                //~v8@tR~
        if (!rc)                                                   //~v8@tR~
        {                                                          //~v8@tR~
            UTRACEP("funclogon READY found,already logon\n");      //~v8@tR~
            return 0;                                              //~v8@tR~
        }                                                          //~v8@tR~
    }                                                              //~v8@tI~
//retry for the case last operation ended by enter for lastline "READY\n***"//~v71nI~
//that leave cleared screen without "READY"                        //~v71nI~
//  funcenter(SENDO_NORESPMSG,Ppthtb); //retry for the case last operation ended by enter for lastline "READY\n***"//~v8@mR~
//  rc=screenchk(SENDO_SNAPPRINT|SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@mR~
//  if (!rc)                                                       //~v8@mR~
//  {                                                              //~v8@mR~
//UTRACEP("funclogon retry READY found,already logon\n");          //~v8@mR~
//  	return 0;                                                  //~v8@mR~
//  }                                                              //~v8@mR~
//  rc=screenchk(0,Ppthtb,"ENTER LOGON"); //logon prompt exist?
//  if (!rc)			//found ENTER LOGON
        verb="logon ";
//  else
//      verb="";
//  screenclear(1,Ppthtb);                                         //~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);	//issue snap before screen chk//~v8@xI~
                                                                   //~v719I~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    strcpy(userpswd,popd[PARM_USER]);
    if ((pc=strchr(userpswd,'/')))
    {                                                              //~v8@bI~
    	uftphostscrypt(0,pc+1,pc+1);
        pswdsw=SENDO_PSWD;                                         //~v8@bI~
    }                                                              //~v8@bI~
  if (cfggetlogoncmdno(0,Ppthtb))  //not default logo procedure    //~v8@mR~
    rc=funclogone(0,Ppthtb,cmd,userpswd);  //user logon procedure  //~v8@1I~
  else //1 line mode                                               //~v8@mR~
  {                                                                //~v8@mR~
    sprintf(cmd,"String \"%s%s\\n\"",verb,userpswd);
//  if (rc=send3270(SENDO_PSWD|SENDO_DROPSTATUS,Ppthtb,cmd),rc)    //~v8@bR~
    opt=pswdsw|SENDO_DROPSTATUS;                                   //~v8@bI~
    if (rc=send3270(opt,Ppthtb,cmd),rc)                            //~v8@bI~
    	return rc;
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=screenchk(SENDO_SNAPPRINT|SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@mR~
    opt=SENDO_SNAPPRINT|SENDO_CASE|SENDO_DROPSTATUS|SENDO_CHKREADY;//~v8@mI~
    rc=screenchk(opt,Ppthtb,0);                                    //~v8@mI~
//  if (rc)	//READY not found                                      //~v8@mR~
    if ((rc & RECVRC_READY))	//READY not found                  //~v8@qR~
        rc=0;                                                      //~v8@qI~
    else                     	//READY not found                  //~v8@qI~
    {                                                              //~v719I~
        if (!(rc & RECVRC_REENTER)) //not reenter                  //~v8@qI~
        {                                                          //~v8@qI~
        	funcenter(SENDO_NORESPMSG,Ppthtb);	//once enter for opening screen woth no READY nor "***"//~v8@qI~
			cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb);       //~v8@qI~
        }                                                          //~v8@qI~
//      rc2=getfulldata(SENDO_UIDINUSECHK,Ppthtb,buff,sizeof(buff),0,&pbuff,&readlen);//~v72CR~
        opt=SENDO_UIDINUSECHK|SENDO_ENTERCHK|SENDO_REENTERCHK;     //~v72CI~
        rc2=getfulldata(opt,Ppthtb,buff,sizeof(buff),0,&pbuff,&readlen);//~v72CI~
        if (rc2)                                                   //~v71eR~
        {                                                          //~v719I~
//          if (rc2==RECVRC_REENTER) //invalid dsname reenter      //~v8@qR~
            if (rc2 & RECVRC_REENTER) //invalid dsname reenter     //~v8@qI~
            {                                                      //~v719I~
                funcbreak(Ppthtb);                                 //~v72CI~
			    send3270(SENDO_SNAPPRINT,Ppthtb,"String logoff\\n");//~v719I~
//              uerrmsgmt(1,"Logon rejected by \"%s\" in use\n",0, //~v72CR~
//                          popd[PARM_USER]);                      //~v72CR~
                uerrmsgmt(1,"Logon rejected by \"%s\"\n",0,        //~v72CM~
                			pbuff);                                //~v72CM~
            }                                                      //~v719I~
//          else                                                   //~v72xR~
//  			rc2=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v72xR~
//        if (rc2)                                                 //~v72xR~
        }                                                          //~v72xI~
//      if (rc2==RECVRC_REENTER) //invalid dsname reenter          //~v8@qR~
        if (rc2 & RECVRC_REENTER) //invalid dsname reenter         //~v8@qI~
        {                                                          //~v72xI~
            rc=U3CR_RC_OTHER;                                      //~v719I~
        }                                                          //~v719I~
//        else //once retry                                        //~v8@mR~
//        {                                                        //~v8@mR~
//UTRACEP("once more read screen\n");                              //~v8@mR~
//            rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@mR~
//          if (rc)                                                //~v8@mR~
//          {                                                      //~v8@mR~
//UTRACEP("once enter retry\n");                                   //~v8@mR~
//            funcenter(0,Ppthtb);                                 //~v8@mR~
//            rc=screenchk(SENDO_SNAPPRINT|SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@mR~
//            if (rc)              //may screen cleared            //~v8@mR~
//            {                                                    //~v8@mR~
//UTRACEP("Last enter retry\n");                                   //~v8@mR~
//                funcenter(0,Ppthtb);                             //~v8@mR~
//                rc=screenchk(SENDO_SNAPPRINT|SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@mR~
//                if (rc)                                          //~v8@mR~
//                    rc=U3CR_RC_OTHER;                            //~v8@mR~
//            }                                                    //~v8@mR~
//          }                                                      //~v8@mR~
//        }                                                        //~v8@mR~
        if (pbuff)                                                 //~v71fR~
            ufree(pbuff);                                          //~v719R~
    }//READY not found                                             //~v719I~
  }//no logon proc                                                 //~v8@mI~
UTRACEP("funclogon exit rc=%d\n",rc);
    return rc;
}//funclogon
//****************************************************************
//*logoff process
//****************************************************************
int funclogoff(PTHREADTB Ppthtb)
{
    int rc;
    int opt;                                                       //~v8@tI~
//************************
UTRACEP("funclogoff entry\n");
 	if (Ppthtb->THTflag & THTF_CLOSE) //disconnected already       //~v8@eR~
    	rc=RECVRC_NOTCONNECT;//not connected                       //~v8@eI~
 	else                                                           //~v8@eI~
    	rc=send3270(0,Ppthtb,"Snap");                              //~v8@eI~
 if (rc & RECVRC_NOTCONNECT)	//not connected                    //~v8@eI~
   rc=0;                                                           //~v8@eI~
 else                                                              //~v8@eI~
 {                                                                 //~v8@eI~
	opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_LOGON;                   //~v8@tI~
    rc=cmdreadychk(opt,Ppthtb);   //prelogon msg chk               //~v8@tI~
    if (rc==RECVRC_PRELOGON)     //pre logon status                //~v8@tI~
    {                                                              //~v8@tI~
        UTRACEP("funclogoff already logoff\n");                    //~v8@tI~
        return 0;                                                  //~v8@tI~
    }                                                              //~v8@tI~
  if (cfggetlogoffcmdno(0,Ppthtb))  //not default logo procedure   //~v8@9R~
  {                                                                //~v8@1I~
    rc=funclogoffe(0,Ppthtb);  //execute cfg defined procedure     //~v8@1I~
  }                                                                //~v8@1I~
  else                                                             //~v8@1I~
  {                                                                //~v8@1I~
//  screenclear(1,Ppthtb);                                         //~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);                             //~v8@xI~
	funcbreak(Ppthtb);       //for the case RPF panel opened       //~v8@qI~
    funcclear(0,Ppthtb);  //clear pending input                    //~v8@qI~
    rc=send3270(0,Ppthtb,"String logoff\\n");
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
	funcsnap(SENDO_SNAPPRINT,Ppthtb);
  }                                                                //~v8@1I~
 }//disconnected                                                   //~v8@eI~
UTRACEP("funclogoff exit rc=%d\n",rc);
    return rc;
}//funclogoff
//****************************************************************
//*3270 end session
//****************************************************************
int funcend3270(PTHREADTB Ppthtb)
{
    int rc;
    char cmd[MAX_CMDSZ];
//************************
UTRACEP("funcend3270 entry\n");
  if (Ppthtb->THTflag & THTF_CLOSE) //disconnected already         //~v8@eR~
    rc=RECVRC_NOTCONNECT;//not connected                           //~v8@eI~
  else                                                             //~v8@eI~
    rc=send3270(0,Ppthtb,"Snap");
    if (!(rc & RECVRC_NOTCONNECT))	//not connected
    {
        rc|=send3270(0,Ppthtb,"Disconnect");
	    if (!(rc & RECVRC_NOTCONNECT))	//not connected
        {
        	sprintf(cmd,"Wait %d Disconnect",G3270to_disconn);     //~v8@9R~
//  		rc|=wait3270(SENDO_WAIT_DISCONN,Ppthtb,TIMEOUT_DISCONNECT);//~v8@9R~
    		rc|=wait3270(SENDO_WAIT_DISCONN,Ppthtb,G3270to_disconn);//~v8@9I~
        }
    }
//  funcsnap(SENDO_SNAPPRINT,Ppthtb);                              //~v716R~
//	Ppthtb->THTflag&=~THTF_CONNECTED;	//connect flag             //~v8@qR~
	close3270(Ppthtb);
UTRACEP("funcend3270 exit reset connect flag\n");
    return 0;
}//funcend3270
//****************************************************************
//*3270 screen snap by ascii cmd                                   //~v8@bR~
//****************************************************************
int funcsnap(int Popt,PTHREADTB Ppthtb)
{
    int readlen,rc;
	char buff[MAX_SCREENSZ];
//************************
	rc=snap3270(Popt,Ppthtb,buff,sizeof(buff),&readlen);
    return rc;
}//funcsnap
//**************************************************************** //~v8@bI~
//*3270 snap cmd(not ascii cmd)                                    //~v8@bI~
//**************************************************************** //~v8@bI~
int funcsnap3270cmd(int Popt,PTHREADTB Ppthtb,char *Psubcmd)       //~v8@bR~
{                                                                  //~v8@bI~
    int rc;                                                        //~v8@bR~
	char snapcmd[MAX_CMDSZ];                                       //~v8@bR~
//************************                                         //~v8@bI~
    sprintf(snapcmd,"Snap %s",Psubcmd);                            //~v8@bI~
    rc=send3270(Popt,Ppthtb,snapcmd);                              //~v8@bR~
    return rc;                                                     //~v8@bI~
}//funcsnap3270cmd                                                 //~v8@bI~
//****************************************************************
//*cmd input                                                       //~v8@bR~
//****************************************************************
int funccmd(PTHREADTB Ppthtb)
{
    int rc;
    int len;                                                       //~v8@cI~
    char **popd,*cmd;
    char *pcmd2,cmd2[MAX_CMDSZ],*pdelm;                            //~v8@cI~
//************************
UTRACEP("funccmd    entry\n");
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    cmd=popd[0];
  for (pcmd2=cmd;;)                                                //~v8@cI~
  {                                                                //~v8@cI~
//  len=USTRLENC(pcmd2,';',pdelm);                                 //~v8@cI~//~vv30R~
    len=(int)USTRLENC(pcmd2,';',pdelm);                            //~vv30I~
//  UmemcpyZ(cmd2,pcmd2,len);                                      //~v8@cI~//~vv30R~
    UmemcpyZ(cmd2,pcmd2,(size_t)len);                              //~vv30I~
    cmd=cmd2;                                                      //~v8@cI~
UTRACEP("funccmd @@@@cmd=\n",cmd);                                 //~v8@cI~
    rc=send3270(SENDO_SNAPPRINT,Ppthtb,cmd);
    if (rc)                                                        //~v8@9I~
        uerrmsgmt(0,"cmd %s failed\n",0,                           //~v8@9I~
          cmd);                                                    //~v8@9I~
    if (!pdelm)                                                    //~v8@cI~
    	break;                                                     //~v8@cI~
    pcmd2=pdelm+1;                                                 //~v8@cI~
  }                                                                //~v8@cI~
UTRACEP("funccmd exit rc=%d\n",rc);
    return rc;
}//funccmd
//**************************************************************** //~v8@9I~
//*3270 end session                                                //~v8@9I~
//**************************************************************** //~v8@9I~
int funccmd2(int Popt,PTHREADTB Ppthtb,char *Pcmd)                 //~v8@9I~
{                                                                  //~v8@9I~
    int rc;                                                        //~v8@9I~
    int opt;                                                       //~v8@bI~
    int len;                                                       //~v8@eI~
    char *pcmd2,*cmd,cmd2[MAX_CMDSZ],*pdelm;                       //~v8@eR~
//************************                                         //~v8@9I~
UTRACEP("funccmd2    entry opt=%x,cmd=%s\n",Popt,Pcmd);            //~v8@ER~
//  if (!USTRHEADIS_IC(Pcmd,WORDCHK_STRING))	//string cmd enter is checked at send3270//~v8@eR~
  for (pcmd2=Pcmd;;)                                               //~v8@eI~
  {                                                                //~v8@eI~
//  len=USTRLENC(pcmd2,';',pdelm);                                 //~v8@eI~//~vv30R~
    len=(int)USTRLENC(pcmd2,';',pdelm);                            //~vv30I~
//  UmemcpyZ(cmd2,pcmd2,len);                                      //~v8@eI~//~vv30R~
    UmemcpyZ(cmd2,pcmd2,(size_t)len);                              //~vv30I~
    cmd=cmd2;                                                      //~v8@eI~
UTRACEP("funccmd2 @@@@cmd=%s\n",cmd);                              //~v8@ER~
    opt=Popt;                                                      //~v8@eM~
    if (iswaitaction(0,cmd))	//string cmd enter is checked at send3270//~v8@eI~
	    opt|=SENDO_WAIT_OUTPUT;		//wait 5 sec until host resonse//~v8@ER~
    rc=send3270(opt,Ppthtb,cmd);                                   //~v8@eR~
    if (rc)                                                        //~v8@9I~
        uerrmsgmt(0,"cmd %s failed\n",0,                           //~v8@9I~
            cmd);                                                  //~v8@eR~
    if (!pdelm)                                                    //~v8@eI~
    	break;                                                     //~v8@eI~
    pcmd2=pdelm+1;                                                 //~v8@eI~
  }                                                                //~v8@eI~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
UTRACEP("funccmd2 exit rc=%d\n",rc);                               //~v8@9I~
    return rc;                                                     //~v8@9I~
}//funccmd2                                                        //~v8@9I~
//**************************************************************** //~v719I~
//*3270 end session                                                //~v719I~
//**************************************************************** //~v719I~
int funcbreak(PTHREADTB Ppthtb)                                    //~v719I~
{                                                                  //~v719I~
    int rc;                                                        //~v719I~
    int opt;                                                       //~v8@bI~
//************************                                         //~v719I~
UTRACEP("funcbreak   entry\n");                                    //~v719I~
//  screenclear(1,Ppthtb);   //"Enter" when screen full            //~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);	//issue snap before screen chk//~v8@xI~
//  rc=send3270(SENDO_SNAPPRINT,Ppthtb,"PA 1");                    //~v8@bR~
    opt=SENDO_SNAPPRINT|SENDO_WAIT_OUTPUT;                         //~v8@bI~
    rc=send3270(opt,Ppthtb,"PA 1");                                //~v8@bI~
    if (!rc)                                                       //~v71eI~
//  	rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
		rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb);        //~v8@3R~
UTRACEP("funcbreak exit rc=%d\n",rc);                              //~v719I~
    return rc;                                                     //~v719I~
}//funcbreak                                                       //~v8@9R~
//**************************************************************** //~v71gI~
//*3270 end session                                                //~v71gI~
//**************************************************************** //~v71gI~
int funcbreak2(PTHREADTB Ppthtb)                                   //~v71gI~
{                                                                  //~v71gI~
    int rc;                                                        //~v71gI~
//************************                                         //~v71gI~
UTRACEP("funcbreak2  entry\n");                                    //~v71gI~
//  screenclear(1,Ppthtb);   //"Enter" when screen full            //~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);	//issue snap before screen chk//~v8@xI~
  if (THT_ISSPF(Ppthtb))                                           //~v8@3R~
	rc=funcenter(0,Ppthtb);      //try enter                       //~v8@3I~
  else                                                             //~v8@3I~
    rc=send3270(SENDO_SNAPPRINT,Ppthtb,"String @@@@\\n"); //dummy reply to REENTER//~v71gI~
    if (!rc)                                                       //~v71gI~
//  	rc=screenchk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb,WORDCHK_READY);//~v8@3R~
		rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS,Ppthtb);        //~v8@3R~
UTRACEP("funcbreak2 exit rc=%d\n",rc);                             //~v71gI~
    return rc;                                                     //~v71gI~
}//funcbreak2                                                      //~v8@9R~
//****************************************************************
//*3270 screen input                                               //~v72BR~
//****************************************************************
int funcstring(PTHREADTB Ppthtb)
{
    int rc;
    char **popd,*cmd;
    int startrow;                                                  //~v72AR~
    int readlen;                                                   //~v72AI~
    int opt;                                                       //~v8@mI~
    char *pbuff;                                                   //~v72AI~
	char buff[MAX_SCREENSZ];                                       //~v72AI~
//************************
UTRACEP("funcstring entry\n");
//  screenclear(1,Ppthtb);   //"Enter" when screen full            //~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);	//issue snap before screen chk//~v8@xI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    cmd=popd[0];
    startrow=Ppthtb->THTcurrow;	//read screen from current row     //~v72sM~
    rc=send3270(SENDO_SNAPPRINT,Ppthtb,cmd);
  if (!rc)                                                         //~v72AI~
  {                                                                //~v72AI~
//  funcsnap(SENDO_SNAPPRINT,Ppthtb);                              //~v72sR~
//  Ppthtb->THTstartrow=startrow;                                  //~v72AR~
UTRACEP("funcstring snaprow=%d\n",startrow);                       //~v72sR~
//  opt|=SENDO_SELECTROW|SENDO_SNAPPRINT;                          //~v72AR~
//  funcsnap(opt,Ppthtb);                                          //~v72AR~
//  rc=getfulldata(0,Ppthtb,buff,MAX_SCREENSZ,startrow,&pbuff,&readlen);//~v8@mR~
   if (strstr(cmd,"\\n"))	//with enter key                       //~v8@mI~
   {                                                               //~v8@mI~
	opt=SENDO_CHKSPF;                                              //~v8@mI~
    rc=getfulldata(opt,Ppthtb,buff,MAX_SCREENSZ,startrow,&pbuff,&readlen);//~v8@mI~
    if (readlen)                                                   //~v8@mI~
    	uerrmsgmt(1,"%s",0,                                        //~v8@mI~
        			pbuff);                                        //~v8@mI~
    if (pbuff)                                                     //~v72AI~
        ufree(pbuff);                                              //~v72AI~
   }                                                               //~v8@mI~
   else                                                            //~v8@qI~
    uerrmsgmt(1,"%s was done(missing \\n).",0,                     //~v8@qR~
        		cmd);                                              //~v8@qR~
  }                                                                //~v72AI~
UTRACEP("funcstring exit rc=%d\n",rc);
    return rc;
}//funcstring
//**************************************************************** //~v72BI~
//*3270 screen input and reponse screen image                      //~v72BI~
//* input cmd:"String "opt cmd ....\n"                             //~v72BI~
//**************************************************************** //~v72BI~
int funcrsh(PTHREADTB Ppthtb)                                      //~v72BI~
{                                                                  //~v72BI~
    int rc;                                                        //~v72BI~
    char **popd,*cmd,*pc,*pc2;                                     //~v72BR~
    int startrow;                                                  //~v72BI~
    int readlen,len,rshopt;                                        //~v72BR~
    int opt;                                                       //~v8@5I~
    int opt0;                                                      //~v8@eI~
    char *pbuff;                                                   //~v72BR~
    PSCRDATA      prespdata;                                       //~v72BR~
	char buff[MAX_SCREENSZ];                                       //~v72BI~
    char cmdwk[MAX_CMDSZ];                                         //~v8@eR~
//************************                                         //~v72BI~
UTRACEP("funcRSH entry\n");                                        //~v72BI~
    Ppthtb->THTrespdata=0;                                         //~v72BI~
    Ppthtb->THTrespdatalen=0;                                      //~v72BI~
//  screenclear(1,Ppthtb);   //"Enter" when screen full            //~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);	//issue snap before screen chk//~v8@xI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v72BI~//~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
    cmd=popd[0];                                                   //~v72BI~
UTRACEP("funcRSH cmd=%s\n",cmd);                                   //~v72BI~
//    pc=strchr(cmd,'"');                                          //~v8@ZR~
//    if (!pc)                                                     //~v8@ZR~
//        return 4;                                                //~v8@ZR~
//    pc++;                                                        //~v8@ZR~
    pc=cmd+strspn(cmd," ");                                        //~v8@ZI~
    rshopt=atoi(pc);     	//top is optio parm                    //~v72BI~
    pc2=strchr(pc,' ');                                            //~v72BI~
    if (!pc2)                                                      //~v72BI~
    	return 4;                                                  //~v72BI~
    pc2+=strspn(pc2," ");                                          //~v72BI~
    strcpy(pc,pc2);			//drop option str                      //~v72BI~
    if (rshopt & XE3270RSHOPT_FSMODE)  //fullscreen mode           //~v72BI~
    {                                                              //~v8@eI~
	    startrow=0;					                               //~v72BM~
	    opt0=SENDO_FULLSCR;                                        //~v8@eI~
    }                                                              //~v8@eI~
    else                                                           //~v72BM~
    {                                                              //~v8@eI~
	    startrow=Ppthtb->THTcurrow;	//read screen from current row //~v72BM~
    	opt0=SENDO_CHKSPF;                                         //~v8@HI~
    }                                                              //~v8@eI~
    opt=opt0|SENDO_RSHMODE;                                        //~v8@HI~
UTRACEP("funcRSH cmd=%s\n",cmd);                                   //~v72BI~
UTRACEP("funcRSH startrow=%d rshopt=%x\n",startrow,rshopt);        //~v72BR~
    ustrncpyz(cmdwk,pc,sizeof(cmdwk));                             //~v8@7I~
//  *(cmdwk+strlen(cmdwk)-1)=0; //drop last dquote                 //~v8@ZR~
  if (!stricmp(cmdwk,CMD_SNAP)     //snap                          //~v8@pI~
  ||  !stricmp(cmdwk,CMD_ASCII))  //ascii                          //~v8@pI~
  {                                                                //~v8@7I~
    rc=0;                                                          //~v8@7I~
	startrow=0;                                                    //~v8@7I~
    opt &= ~SENDO_CHKSPF;  //                                      //~v8@PI~
  }                                                                //~v8@7I~
  else                                                             //~v8@eI~
  if (USTRHEADIS_IC(cmdwk,CONFIGP_CMDCMD)) //action cmd            //~v8@eR~
  {                                                                //~v8@eI~
  	pc=cmdwk+sizeof(CONFIGP_CMDCMD)-1;                             //~v8@eI~
   if ((                                                           //~v9@7R~
        (!memicmp(pc,"PF",2))   //reject Pfkey if no TSO session to avoid screen protection//~v9@7R~
       )                                                           //~v9@7I~
       && cmdreadychk(SENDO_LOGON,Ppthtb)     //prelogon status    //~v9@7R~
      )                                                            //~v9@7I~
   {                                                               //~v9@7R~
    uerrmsgmt(1,"No TSO session",0);                               //~v9@7R~
    rc=RECVRC_ERR;                                                 //~v9@7I~
   }                                                               //~v9@7R~
   else                                                            //~v9@7I~
	rc=funccmd2(opt,Ppthtb,pc);                                    //~v8@eR~
  }                                                                //~v8@eI~
  else                                                             //~v8@7I~
  {                                                                //~v8@7I~
//  screenclear(1,Ppthtb);   //"Enter" when screen full for string cmd//~v8@xR~
    screenclear(1|SCCO_NEWCMD,Ppthtb);	//issue snap before screen chk//~v8@xI~
    rc=send3270(0,Ppthtb,cmd);                                     //~v72BR~
  }                                                                //~v8@7I~
  	if (!rc)                                                       //~v8@HR~
  	{                                                              //~v8@HR~
//  	rc=getfulldata(SENDO_RSHMODE,Ppthtb,buff,MAX_SCREENSZ,startrow,&pbuff,&readlen);//~v8@5R~
    	rc=getfulldata(opt,Ppthtb,buff,MAX_SCREENSZ,startrow,&pbuff,&readlen);//~v8@5I~
//        if (!rc && !readlen) //no respdata                       //~v8@HR~
//        {                                                        //~v8@HR~
//            startrow=0;                                          //~v8@HR~
//            opt=opt0|SENDO_RSHMODE;                              //~v8@HR~
//            rc=getfulldata(opt,Ppthtb,buff,MAX_SCREENSZ,startrow,&pbuff,&readlen);//~v8@HR~
//            if (rc)                                              //~v8@HR~
//                pbuff=0;                                         //~v8@HR~
//        }                                                        //~v8@HR~
//  	if (pbuff)                                                 //~v8@HR~
    	if (!rc && readlen && pbuff)                               //~v8@HI~
        {                                                          //~v72BI~
//      	len=readlen+SCRDATAHDRSZ;                              //~v72BR~//~vv30R~
        	len=readlen+(int)SCRDATAHDRSZ;                         //~vv30I~
//      	prespdata=(PSCRDATA)umalloc(len);                      //~v72BR~//~vv30R~
        	prespdata=(PSCRDATA)umalloc((size_t)len);              //~vv30I~
            if (!prespdata)                                        //~v72BI~
        		uerrmsgmt(1,"malloc failed(len=%d)",0,             //~v72BI~
							len);                                  //~v72BI~
            else                                                   //~v72BI~
            {                                                      //~v72BI~
	 			ugeterrmsg();        //clear response msg          //~v72BR~
            	prespdata->SCRhdr.PRDlen=len;                      //~v72BR~
            	prespdata->SCRhdr.PRDtype=PRDT_RSHRESP;            //~v72BR~
            	prespdata->SCRhdr.PRDcount=0;                      //~v72BR~
                prespdata->SCRmaxrow=Ppthtb->THTmaxrow;            //~v8@HI~
                prespdata->SCRmaxcol=Ppthtb->THTmaxcol;            //~v8@HI~
                prespdata->SCRcurrow=Ppthtb->THTcurrow;            //~v8@HI~
                prespdata->SCRcurcol=Ppthtb->THTcurcol;            //~v8@HI~
                prespdata->SCRlen=readlen;                         //~v72BR~
//              memcpy(prespdata->SCRdata,pbuff,readlen);          //~v72BI~//~vv30R~
                memcpy(prespdata->SCRdata,pbuff,(size_t)readlen);  //~vv30I~
	    		Ppthtb->THTrespdata=prespdata;                     //~v72BR~
        		Ppthtb->THTrespdatalen=len;                        //~v72BR~
            }                                                      //~v72BI~
	        ufree(pbuff);                                          //~v72BI~
        }                                                          //~v72BI~
  	}                                                              //~v8@HR~
UTRACEP("funcRSH exit rc=%d\n",rc);                                //~v72BI~
    return rc;                                                     //~v72BI~
}//funcrsh                                                         //~v72BR~
//**************************************************************** //~v716I~
//*Clear AID                                                       //~v716I~
//**************************************************************** //~v716I~
int funcclear(int Popt,PTHREADTB Ppthtb)                           //~v716R~
{                                                                  //~v716I~
    int rc=0,opt;                                                  //~v8@bR~
//************************                                         //~v716I~
UTRACEP("funcclear entry \n");                                     //~v72sI~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=send3270(Popt,Ppthtb,"Clear");                              //~v8@bR~
	opt=Popt|SENDO_WAIT_OUTPUT;                                    //~v8@bI~
    rc=send3270(opt,Ppthtb,"Clear");                               //~v8@bI~
//  wait3270(SENDO_WAIT_OUTPUT,Ppthtb,1);                          //~v716R~
//  rc=send3270(Popt,Ppthtb,"Home");                               //~v716R~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);   //@@@@                 //~v716R~
//  rc=send3270(Popt,Ppthtb,"EraseInput"); //@@@@                  //~v716R~
//  wait3270(SENDO_WAIT_OUTPUT,Ppthtb,1);  //@@@@                  //~v716R~
UTRACEP("funcclear return\n");                                     //~v72sI~
    return rc;                                                     //~v716I~
}//funcclear                                                       //~v716R~
//**************************************************************** //~v716M~
//*Enter AID                                                       //~v716M~
//**************************************************************** //~v716M~
int funcenter(int Popt,PTHREADTB Ppthtb)                           //~v716M~
{                                                                  //~v716M~
    int rc=0,opt;                                                  //~v8@bR~
//************************                                         //~v716M~
UTRACEP("funcEnter\n");                                            //~v71eI~
//  wait3270(SENDO_WAIT_UNLOCK,Ppthtb,1);                          //~v8@bR~
//  rc=send3270(Popt,Ppthtb,"Enter");                              //~v8@bR~
	opt=Popt|SENDO_WAIT_OUTPUT;                                    //~v8@bI~
    rc=send3270(opt,Ppthtb,"Enter");                               //~v8@bI~
//  wait3270(SENDO_WAIT_OUTPUT,Ppthtb,1);                          //~v716R~
UTRACEP("funcEnter rc=%d\n",rc);                                   //~v72GI~
    return rc;                                                     //~v716M~
}//funcenter                                                       //~v716M~
//****************************************************************
//*issue cmd to 3270 sub process
//****************************************************************
int screenclear(int Pkeepcount,PTHREADTB Ppthtb)                   //~v716R~
{
    int rc=0,rowfree;                                              //~v716R~
    int ii;                                                        //~v72GI~
    int rowready,opt;                                              //~v8@xR~
    int newcmdopt;                                                 //~v8@xI~
//************************
UTRACEP("screenclear entry,opt=%x\n",Pkeepcount);                  //~v8@xR~
	newcmdopt=Pkeepcount & SCCO_NEWCMD;                            //~v8@xI~
	Pkeepcount &= ~SCCO_NEWCMD;                                    //~v8@xI~
//  funcsnap(0,Ppthtb);  //get THTcurrow                           //~v8@xR~
//  rowfree=Ppthtb->THTmaxrow-Ppthtb->THTcurrow;//current row is offset cursor exist//~v8@xR~
//  rc=funcclear(0,Ppthtb);                                        //~v8@xR~
	opt=SENDO_NORESPMSG;                                           //~v8@xM~
//  for (;;)  //there is case "Clear" dose not clear screen.       //~v72GR~
    for (ii=0;ii<10;ii++)  //there is case "Clear" dose not clear screen.//~v72GI~
    {                                                              //~v716I~
    	if (ii>0||newcmdopt)                                       //~v8@xI~
    		funcsnap(opt,Ppthtb);  //get THTcurrow                 //~v8@xI~
//  	rowfree=Ppthtb->THTmaxrow-Ppthtb->THTcurrow;//current row is offset cursor exist//~v8@xR~
    	rowready=Ppthtb->THTreadyrow;//current row is offset cursor exist//~v8@xI~
    	rowfree=Ppthtb->THTmaxrow-rowready;//current row is offset cursor exist//~v8@yR~
UTRACEP("screenclear parm=%d,free=%d,ready=%d loop=%d\n",Pkeepcount,rowfree,rowready,ii);//~v8@xR~
//  	if (rowfree>=Pkeepcount)                                   //~v71nR~
    	if (rowfree>Pkeepcount) //1 more free required;if not no "***" nand READY appears//~v71nI~
        	break;                                                 //~v716I~
    	funcclear(opt,Ppthtb);                                     //~v8@xI~
UTRACEP("screenclear Enter keep=%d,free=%d\n",Pkeepcount,rowfree); //~v716I~
        rc=                                                        //~v72GI~
//  	funcenter(0,Ppthtb);                                       //~v8@xR~
    	funcenter(opt,Ppthtb);                                     //~v8@xI~
        if (rc)                                                    //~v72GI~
            break;                                                 //~v72GI~
    }                                                              //~v716I~
//  funcsnap(SENDO_SNAPPRINT,Ppthtb);                              //~v716R~
UTRACEP("screen clear exit rc=%d\n",rc);                           //~v72GI~
    return rc;
}//screenclear
//****************************************************************
//*issue cmd to 3270 sub process
//****************************************************************
int send3270(int Popt,PTHREADTB Ppthtb,char *Pcmd)
{
    int rc,readlen=0;                                              //~vafcR~
	char *pc,buff[MAX_SCREENSZ];
    int waitoutput=0,opt;                                          //~v8@jR~
//************************
UTRACEP("send3270 text=%s\n",Pcmd);
    if (Popt & SENDO_PSWD && strchr(Pcmd,'/'))
    {
    	strcpy(buff,Pcmd);
        pc=strchr(buff,'/');
		strcpy(pc+1,"*\"");
	  if (Popt & SENDO_NORESPMSG)                                  //~v8@3I~
		uerrmsgmt(0,"===> %s\n",0,                                 //~v8@3I~
    			buff);                                             //~v8@3I~
      else                                                         //~v8@3I~
		uerrmsgmt(1,"===> %s",0,
    			buff);
    }
    else
    if (Popt & SENDO_PSWD)	//full screen mode                     //~v8@bI~
    {                                                              //~v8@bI~
	  if (Popt & SENDO_NORESPMSG)                                  //~v8@bI~
		uerrmsgmt(0,"===> %s\n",0,                                 //~v8@bI~
    			CONFIGP_CMDLOGON_PSWD);                            //~v8@bI~
      else                                                         //~v8@bI~
		uerrmsgmt(1,"===> %s",0,                                   //~v8@bI~
    			CONFIGP_CMDLOGON_PSWD);                            //~v8@bI~
    }                                                              //~v8@bI~
    else                                                           //~v8@bI~
	  if (Popt & SENDO_NORESPMSG)                                  //~v8@3I~
    	uerrmsgmt(0,"===> %s\n",0,     //not resp msg to xe        //~v8@3M~
    			Pcmd);                                             //~v8@3M~
      else                                                         //~v8@3I~
    	uerrmsgmt(1,"===> %s",0,                                   //~v8@3R~
    			Pcmd);                                             //~v8@3I~
    if (!(Popt & SENDO_NOWAIT))                                    //~v8@bI~
    {                                                              //~v8@bI~
        if ((Popt & SENDO_WAIT_OUTPUT)                             //~v8@bR~
        ||  (USTRHEADIS_IC(Pcmd,WORDCHK_STRING) && USTRTAILIS(Pcmd,"\\n"))//~v8@bR~
           )                                                       //~v8@bR~
        {                                                          //~v8@jI~
	        if (Popt & SENDO_RCHK_FTP)     //wait 1 sec for ftp    //~v8@jI~
            	waitoutput=G3270to_outputftp;    //1 sec wait      //~v8@jI~
            else                                                   //~v8@jI~
            	waitoutput=G3270to_output;                         //~v8@jR~
        	opt=Popt|SENDO_NOWAIT;                                 //~v8@jR~
            opt&=~SENDO_RCHK_FTP;   //no ftp resp chk              //~v8@jI~
            funcsnap3270cmd(opt,Ppthtb,"Save");    //save screen to wait scren update//~v8@jR~
        }                                                          //~v8@jI~
    }                                                              //~v8@bI~
	rc=write3270(Ppthtb,Pcmd);//write to pipe                      //~v716R~
    if (!rc)
    {                                                              //~v8@bI~
		rc=write3270readresp(Popt,Ppthtb,buff,sizeof(buff),&readlen);//read cmd response
//      if (waitoutput)                                            //~v8@bR~
//      {                                                          //~v8@bR~
//     	wait3270(Popt,Ppthtb,waitoutput);                          //~v8@bR~
//  		rc=write3270readresp(Popt,Ppthtb,buff,sizeof(buff),&readlen);//read cmd response//~v8@bR~
//      }                                                          //~v8@bR~
    }                                                              //~v8@bI~
//  if (rc||!readlen)                                              //~v8@7R~
    if (rc && !readlen)                                            //~v8@HR~
    	strcpy(buff,"(write to 3270 failed)");                     //~v8@HR~
  if (Popt & SENDO_NORESPMSG)                                      //~v8@3I~
	uerrmsgmt(0,"<=== %s\n",0,          //not resp msg to xe       //~v8@3M~
    		buff);                                                 //~v8@3I~
  else                                                             //~v8@3I~
    uerrmsgmt(1,"<=== %s",0,                                       //~v8@3R~
    		buff);
UTRACEP("send3270 wrte3270rc=%d\n",rc);                            //~v79dR~
	if (!rc)
    {
	    if (Popt & SENDO_RCHK_FTP)
        {                                                          //~v8@jI~
			rc=screenstrchk(0,buff,RESP_COMPLETE);
            if (rc)                                                //~v8@jI~
        		if (waitoutput)	//safety chk                       //~v8@jI~
                {                                                  //~v8@jI~
                    opt=Popt|SENDO_WAIT_OUTPUT;                    //~v8@jI~
                    opt&=~SENDO_RCHK_FTP;   //no ftp resp chk      //~v8@jI~
       				wait3270(opt,Ppthtb,waitoutput);               //~v8@jR~
                }                                                  //~v8@jI~
        }                                                          //~v8@jI~
    }                                                              //~v71eI~
    else                                                           //~v71eI~
    if (rc==RECVRC_ERR)                                            //~v71eI~
    {                                                              //~v71eI~
		if (Popt & SENDO_RCHK_FTPGET)
        {                                                          //~v71eI~
			if (!screenstrchk(0,buff,RESP_FILENOTFOUND))//found "not found"
            	rc=U3CR_RC_NOTFOUND;                               //~v716R~
            else                                                   //~v71eI~
			if (!screenstrchk(0,buff,WORDCHK_FILEEXIST))	//exiting file is not replaced//~v71eI~
            	rc=U3CR_RC_DUPNAME;                                //~v71eM~
        }                                                          //~v71eI~
    }
    if (!rc)                                                       //~v8@bI~
        if (waitoutput)                                            //~v8@bI~
        {                                                          //~v8@jI~
            opt=Popt|SENDO_WAIT_OUTPUT;                            //~v8@jI~
            opt&=~SENDO_RCHK_FTP;   //no ftp resp chk              //~v8@jI~
       		wait3270(opt,Ppthtb,waitoutput);                       //~v8@jR~
        }                                                          //~v8@jI~
UTRACEP("send3270 return rc%d\n",rc);                              //~v79aI~
    return rc;
}//send3270
//****************************************************************
//*chk screen data
//*ret:0:word found,1:snap cmd err,2:notconnected,4:string search err//~v8@3R~
//****************************************************************
int screenchk(int Popt,PTHREADTB Ppthtb,char *Pvalidresp)
{
    int rc,buffsz,readlen;
	char buff[MAX_SCREENSZ];
    int rc2;                                                       //~v8@tR~
//************************
UTRACEP("screenchk entry\n");
	buffsz=sizeof(buff);
    if (Popt & SENDO_CMDLINE) //cmdline input avaliable chk        //~v8@tR~
    	SENDO_SET_OPTION2(Popt,Ppthtb,THTO2_CHKSPF6);	//parm to editresp//~v8@tR~
	rc=snap3270(Popt,Ppthtb,buff,buffsz,&readlen); //0:no print
//  if (!rc)	//not error and connected                          //~v8@mR~
    if (!(rc & RECVRC_ERRMASK))	//not error and connected          //~v8@mR~
        if (Pvalidresp && *Pvalidresp) //chk requested             //~v8@mR~
        {                                                          //~v8@mI~
			if (screenstrchk(Popt,buff,Pvalidresp))                //~v8@mR~
            	rc|=RECVRC_NOTFOUND;                               //~v8@mI~
        }                                                          //~v8@mI~
    if (Popt & SENDO_CMDLINE) //cmdline input avaliable chk        //~v8@tR~
    {                                                              //~v8@tR~
//  	rc2=SENDO_GET_OPTION2RC(Ppthtb);                           //~v8@tR~//~vv30R~
    	rc2=(int)SENDO_GET_OPTION2RC(Ppthtb);                      //~vv30I~
    	if (rc2 & THTO2RC_ONSPF6)                                  //~v8@tR~
			rc|=RECVRC_ONSPF6;                                     //~v8@tR~
    }                                                              //~v8@tR~
UTRACEP("screenchk return rc=%d\n",rc);
    return rc;
}//screenchk
//**************************************************************** //~v8@1I~
//*chk screen data multiple string                                 //~v8@1I~
//*ret:1:snap cmd err,2:notconnected,4:string search err,minus found entry number//~v8@1I~
//**************************************************************** //~v8@1I~
int screenchkm(int Popt,PTHREADTB Ppthtb,char *Pvalidresp,int Ptextno,char **Ppptext)//~v8@9R~
{                                                                  //~v8@1I~
    int rc,rc2,ii,buffsz,readlen;                                  //~v8@mR~
	char buff[MAX_SCREENSZ],**ppc;                                 //~v8@9R~
	char *pc;                                                      //~v7afR~
    int postchkidx=0;                                              //~v7afI~
//************************                                         //~v8@1I~
UTRACEP("screenchkm entry\n");                                     //~v8@1I~
	buffsz=sizeof(buff);                                           //~v8@1I~
  if (Popt & SENDO_TOPLINECHK)                                     //~v8@3I~
  	rc=0;                                                          //~v8@3M~
  else                                                             //~v8@3M~
	rc=snap3270(Popt,Ppthtb,buff,buffsz,&readlen); //0:no print    //~v8@1I~
    if (!(rc & RECVRC_ERRMASK))	//not error and connected          //~v8@mR~
    {                                                              //~v8@1I~
        for (ii=0,ppc=Ppptext;ii<Ptextno;ii++,ppc++)               //~v8@9R~
        {                                                          //~v8@1I~
            pc=*ppc;                                               //~v7afI~
            if (*pc==ERRMSG_POSTCHKID)                             //~v7afR~
                pc++;                                              //~v7afI~
          if (Popt & SENDO_TOPLINECHK)                             //~v8@3I~
//  		rc2=ustrstri(G3270topline,*ppc)==0;                    //~v8@mR~//~v7afR~
    		rc2=ustrstri(G3270topline,pc)==0;                      //~v7afI~
          else                                                     //~v8@3I~
//  		rc2=screenstrchk(Popt,buff,*ppc);                      //~v8@mR~//~v7afR~
    		rc2=screenstrchk(Popt,buff,pc);                        //~v7afI~
            if (!rc2)                                              //~v8@mR~
            {                                                      //~v9@7I~
              if (pc!=*ppc)   //postchk                            //~v7afI~
              {                                                    //~v7afI~
                if (!postchkidx)                                   //~v7afI~
                	postchkidx=-(ii+1);                            //~v7afI~
UTRACEP("screenchkm posterrmsg idx=%d for %s\n",-ii-1,*ppc);       //~v7afI~
              }                                                    //~v7afI~
              else                                                 //~v7afI~
              {                                                    //~v7afI~
UTRACEP("screenchkm return rc=%d for %s\n",-ii-1,*ppc);            //~v9@7I~
            	return -(ii+1);                                    //~v8@1R~
              }                                                    //~v7afI~
            }                                                      //~v9@7I~
        }                                                          //~v8@1I~
		if (Pvalidresp && *Pvalidresp && !screenstrchk(Popt,buff,Pvalidresp))//~v8@mR~
        {                                                          //~v7afI~
UTRACEP("screenchkm return rc=0,postchk=%d\n",postchkidx);         //~v7afI~
        	return 0;                                              //~v8@1M~
        }                                                          //~v7afI~
        if (postchkidx)                                            //~v7afI~
            return postchkidx;                                     //~v7afI~
        rc|=RECVRC_NOTFOUND;                                       //~v8@mI~
    }                                                              //~v8@1I~
UTRACEP("screenchkm return rc=%d\n",rc);                           //~v8@1I~
    return rc;                                                     //~v8@1I~
}//screenchkm                                                      //~v8@1I~
//****************************************************************
//*search string in resp buff
//*rc 0:found   4:not found
//****************************************************************
int screenstrchk(int Popt,char *Pbuff,char *Pvalidresp)
{
    int errsw,rc=0;
    int len,len2;                                                  //~v8@1I~
    char *pc,*pc2,msgbuff[256];                                    //~v8@1R~
//******************
	if (Popt & SENDO_CASE)
//  	errsw=strstr(Pbuff,Pvalidresp)==0; //err if not found      //~v8@1R~
    	errsw=(pc=strstr(Pbuff,Pvalidresp))==0; //err if not found //~v8@1I~
    else
//  	errsw=ustrstri(Pbuff,Pvalidresp)==0; //err if not found    //~v8@1R~
    	errsw=(pc=ustrstri(Pbuff,Pvalidresp))==0; //err if not found//~v8@1I~
    if (errsw)
    {
UTRACEP("screen string chk expected %s,but not found\n",Pvalidresp);
    	rc=4;
    }
    else                                                           //~v8@1I~
    {                                                              //~v8@1I~
    	if (Popt & SENDO_ERRMSGLINE)                               //~v8@1I~
        {                                                          //~v8@1I~
//      	len=USTRLENC(pc,'\n',pc2);                             //~v8@1R~//~vv30R~
        	len=(int)USTRLENC(pc,'\n',pc2);                        //~vv30I~
//          len-=umemrspnc(pc,' ',len);                            //~v8@1I~//~vv30R~
//          len-=(int)umemrspnc(pc,' ',(size_t)len);               //~vv30R~//+vv31R~
            len-=(int)umemrspnc(pc,' ',(unsigned)len);             //+vv31I~
//          len2=(int)((ULONG)pc-(ULONG)Pbuff);                    //~v8@1I~//~vafkR~
            len2=(int)((ULPTR)pc-(ULPTR)Pbuff);                    //~vafkI~
//          len2=UMEMLENCR(Pbuff,'\n',len2,pc2);                   //~v8@1I~//~vv30R~
            len2=(int)UMEMLENCR(Pbuff,'\n',(size_t)len2,pc2);      //~vv30R~
            len2+=len;                                             //~v8@1I~
//          len2=min(len2,sizeof(msgbuff)-1);                      //~v8@1I~//~vv30R~
            len2=min(len2,(int)sizeof(msgbuff)-1);                 //~vv30I~
//          UmemcpyZ(msgbuff,pc2,len2);                            //~v8@1I~//~vv30R~
            UmemcpyZ(msgbuff,pc2,(size_t)len2);                    //~vv30I~
	    	uerrmsgmt(1,"Err:%s",0,                                //~v8@1R~
						msgbuff);                                  //~v8@1I~
        }                                                          //~v8@1I~
    }                                                              //~v8@1I~
    return rc;
}//screenstrchk
//****************************************************************
//*chk screen data
//*ret:1:snap cmd err,2:notconnected,4:string search err
//****************************************************************
int wait3270(int Popt,PTHREADTB Ppthtb,int Pwaittime)
{
    int rc;
    char cmd[32],*pcmd;
    int opt;                                                       //~v8@bI~
//************************
UTRACEP("wait3270 entry\n");
	if (Popt & SENDO_WAIT_INPUTF) 	//wait screen formatted after connect
    	pcmd="InputField";
    else
	if (Popt & SENDO_WAIT_OUTPUT)	//wait screen update
    	pcmd="Output";
    else
	if (Popt & SENDO_WAIT_DISCONN)  //wait disconnect
    	pcmd="Disconnect";
    else
	if (Popt & SENDO_WAIT_UNLOCK)   //screen unlock
    	pcmd="Unlock";
    else
    	pcmd="";
  if (Pwaittime<=0)                                                //~v8@bI~
    sprintf(cmd,"Wait %s",pcmd);     //indefinite wait             //~v8@bI~
  else                                                             //~v8@bI~
    sprintf(cmd,"Wait %d %s",Pwaittime,pcmd);
//  rc=send3270(Popt,Ppthtb,cmd);                                  //~v8@3R~
    opt=(Popt|SENDO_NORESPMSG)|SENDO_NOWAIT;                       //~v8@bR~
    rc=send3270(opt,Ppthtb,cmd);                                   //~v8@bI~
UTRACEP("wait3270 return rc=%d\n",rc);
    return rc;
}//wait3270
//****************************************************************
//*get screen snap and drop all space line
//*return error/notconnected
//****************************************************************
int snap3270(int Popt,PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz,int *Pplen)
{
    int rc,readlen;                                                //~v719R~
    int opt;                                                       //~v8@3I~
//************************
UTRACEP("snap3270 entry\n");
UTRACEP("write Ascii\n");
	if (rc=write3270(Ppthtb,"Ascii"),rc)//tell pid to wxe,write last null//~v716R~
    	return rc;
//  rc=write3270readresp(Popt,Ppthtb,Pbuff,Pbuffsz,&readlen);//read cmd response//~v8@3R~
    opt=Popt|SENDO_TOPSNAP;                                        //~v8@3I~
	Ppthtb->THTreadyrow=0;                                         //~v8@yI~
	Ppthtb->THTflag2&=~THTF2_3AST;    //clear "***" pending enter  //~v8@yI~
    rc=write3270readresp(opt,Ppthtb,Pbuff,Pbuffsz,&readlen);//read cmd response//~v8@3I~
	if ((Ppthtb->THTflag & THTF_LOGON))	//after logon              //~v8@yI~
    {                                                              //~v8@HI~
        if ((Ppthtb->THTflag2 & THTF2_3AST))    //not ready pending//~v8@yR~
            Ppthtb->THTflag2&=~THTF2_SPF;                          //~v8@yI~
        else                                                       //~v8@yI~
        {                                                          //~v8@yR~
            if (Ppthtb->THTreadyrow)                               //~v8@yR~
                Ppthtb->THTflag2&=~THTF2_SPF;                      //~v8@yR~
            else                                                   //~v8@yR~
                Ppthtb->THTflag2|=THTF2_SPF;                       //~v8@yR~
        }                                                          //~v8@yR~
    }                                                              //~v8@HI~
    UTRACEP("SPF=%x\n",Ppthtb->THTflag2 & THTF2_SPF);              //~v8@yI~
    if (Pplen)	//output required
	    *Pplen=readlen;                                            //~v719R~
    if (Popt & SENDO_SNAPPRINT)
    {
     if (!(Popt & SENDO_RSHMODE)     //top space not dropped       //~v9@bI~
     ||  !(G3270opt & G3270OPT_NORSHECHO))                         //~v9@bI~
     {                                                             //~v9@bI~
      if (Popt & SENDO_NORESPMSG)                                  //~v8@tI~
	    uerrmsgmt(0,"screen snap print:",0);                       //~v8@tI~
      else                                                         //~v8@tI~
	    uerrmsgmt(1,"screen snap print:",0);
     }                                                             //~v9@bI~
      if (Popt & SENDO_RSHMODE)     //top space not dropped        //~v72BI~
		snap3270printline(Pbuff);                                  //~v72BI~
      else                                                         //~v72BI~
      if (Popt & SENDO_NORESPMSG)                                  //~v8@tI~
	    uerrmsgmt(0,"%s\n",0,                                      //~v8@tI~
					Pbuff);                                        //~v8@tI~
      else                                                         //~v8@tI~
	    uerrmsgmt(1,"%s\n",0,                                      //~v8@3R~
					Pbuff);
    }
UTRACEP("snap3270 end len=%d,rc=%d\n",readlen,rc);                 //~v719R~
UTRACED("snap3270",Pbuff,readlen);                                 //~v719R~
    return rc;
}//snap3270
//**************************************************************** //~v72BI~
//*print line checking last column crlf to avoid disply by 2 line on cmd prompt screen//~v72BI~
//*return error/notconnected                                       //~v72BI~
//**************************************************************** //~v72BI~
int snap3270printline(char *Pscrdata)                              //~v72BI~
{                                                                  //~v72BI~
    char *pc,*pc2,ch;                                              //~v72BR~
    int len;                                                       //~v72BI~
//************************                                         //~v72BI~
UTRACEP("snap3270printline G3270opt=%x\n",G3270opt);               //~v9@bI~
    if (G3270opt & G3270OPT_NORSHECHO)                             //~v9@bI~
        return 0;                                                  //~v9@bI~
	for (pc=Pscrdata;*pc;)                                         //~v72BI~
    {                                                              //~v72BI~
    	pc2=strchr(pc,'\n');                                       //~v72BI~
        if (!pc2)                                                  //~v72BI~
        {                                                          //~v72BI~
		    uerrmsgmt(0,"%s",0,                                    //~v72BI~
					pc);                                           //~v72BI~
            break;                                                 //~v72BI~
        }                                                          //~v72BI~
//      len=(ULONG)pc2-(ULONG)pc;                                  //~v72BI~//~vafkR~
//      len=(ULPTR)pc2-(ULPTR)pc;                                  //~vafkI~//~vv30R~
        len=PTRDIFF(pc2,pc);                                       //~vv30I~
        if (len==80)	//col 80 is cr                             //~v72BR~
        {                                                          //~v72BI~
        	*pc2=0;	//write without col80=\n                       //~v72BI~
		    uerrmsgmt(0,"%s",0,                                    //~v72BI~
					pc);                                           //~v72BI~
            *pc2='\n';                                             //~v72BR~
        }                                                          //~v72BI~
        else                                                       //~v72BI~
        {                                                          //~v72BI~
        	ch=*(pc2+1);                                           //~v72BI~
            *(pc2+1)=0;                                            //~v72BI~
		    uerrmsgmt(0,"%s",0,		//wite with last \n            //~v72BI~
					pc);                                           //~v72BI~
            *(pc2+1)=ch;                                           //~v72BI~
        }                                                          //~v72BI~
        pc=pc2+1;                                                  //~v72BI~
    }                                                              //~v72BI~
    return 0;                                                      //~v72BR~
}//snap3270printline                                               //~v72BI~
//****************************************************************
//*read response data and chk status line for connection status
//*rc:1:response error,2:statusline :not connected,4:buffer overflow
//****************************************************************
int write3270readresp(int Popt,PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz,int *Pplen)
{
    int len,totlen,chklen=0,rc;                                    //~vafcR~
    int rowc=0,rowm,ii,startrow;                                   //~v8@HR~
    char *pc,*pc2;                                                 //~v716R~
    int toplinelen;                                                //~v8@3I~
    int colm=80;                                                   //~v8@4R~
    int colc=0;                                                    //~v8@HI~
//************************
UTRACEP("send3270readresp entry\n");
	*Pplen=0;
    for (pc=Pbuff,totlen=0;;pc+=len)
    {
        if (totlen>=Pbuffsz)
        {
        	uerrmsgmt(1,"cmd response read buffer overflow(max=%d)",0,
            			Pbuffsz);
        	rc=RECVRC_BUFFOVERFLOW;
            break;
        }
        len=read3270(Ppthtb,pc,Pbuffsz-totlen);//tell pid to wxe,write last null
        if (!len)                                                  //~v72KI~
        {                                                          //~v72KI~
            *pc=0;                                                 //~v72KI~
        	if (totlen)                                            //~v72KI~
            	pc2=Pbuff;	                                       //~v72KI~
            else                                                   //~v72KI~
            	pc2="";                                            //~v72KI~
            uerrmsgmt(1,"!!! Pipe(stdout from 3270) was closed.(%s)",0,//~v8@mR~
						pc2);                                      //~v72KI~
UTRACEP("read EOF then thread exit\n");                            //~v72KI~
#ifndef AAA                                                        //~v8@1R~
            close3270(Ppthtb);                                     //~v72KI~
            postbackmain(Ppthtb,THTRC_SUBEXIT);                    //~v72KI~
            exitthread(Ppthtb,THTEC_CHILDEND);                     //~v72KI~
#else                                                              //~v8@1I~
        	rc=RECVRC_ERR;                                         //~v8@1I~
            break;                                                 //~v8@1I~
#endif                                                             //~v8@1I~
        }                                                          //~v72KI~
        totlen+=len;
        chklen=sizeof(STATUS_OK)-1;
//      if (len>=chklen && !memcmp(pc+len-chklen,STATUS_OK,chklen))//~vv30R~
        if (len>=chklen && !memcmp(pc+len-chklen,STATUS_OK,(size_t)chklen))//~vv30I~
        {
        	rc=0;
            break;
        }
        chklen=sizeof(STATUS_ERROR)-1;
//      if (len>=chklen && !memcmp(pc+len-chklen,STATUS_ERROR,chklen))//~vv30R~
        if (len>=chklen && !memcmp(pc+len-chklen,STATUS_ERROR,(size_t)chklen))//~vv30I~
        {
        	rc=RECVRC_ERR;
            break;
        }
    }
    *(Pbuff+totlen)=0;
    rowm=0;                                                        //~v716I~
    rowc=0;                                                        //~v716I~
    if (rc!=RECVRC_BUFFOVERFLOW)
    {
//  	pc=umemrchr(Pbuff,'\n',totlen-chklen-1);//top of status line//~vv30R~
    	pc=umemrchr(Pbuff,'\n',(size_t)(totlen-chklen-1));//top of status line//~vv30I~
        if (!pc)
            pc=Pbuff;
        else
        {
        	pc++;
UTRACEP("status line=%s\n",pc);                                    //~v8@4I~
	        if (Popt & SENDO_DROPSTATUS)
              if (!(Popt & SENDO_FULLSCR))     //rsh mode (display also space line)//~v8@7I~
            	*pc=0;
        }
    	if (*(pc+STATUS_POS_CONNECT)!=STATUS_CONNECT)
    		rc|=RECVRC_NOTCONNECT;	//not connected
	    if (Popt & SENDO_RCHK_FORMAT)                              //~v715I~
	    	if (*(pc+STATUS_POS_FORMAT)!=STATUS_FORMAT)            //~v715I~
    			rc|=RECVRC_NOTFORMATTED;	//not connected        //~v715I~
//get row max and current                                          //~v716I~
//L F U C(FAITH) I 4 24 80 22 12 0 0x0 0.000                       //~v716I~
UTRACEP("status line=%s\n",pc);                                    //~v8@4I~
                                                                   //~v8@4I~
    	pc2=pc+STATUS_POS_CONNECT;  //4th:connect id               //~v716I~
//      for (ii=5;ii<10;ii++)       //                             //~v8@HR~
        for (ii=5;ii<=10;ii++)       //                            //~v8@HI~
        {                                                          //~v716I~
        	pc2=strchr(pc2,' ');	                               //~v716I~
	        if (!pc2)	                                           //~v716I~
            	break;                                             //~v716I~
        	pc2+=strspn(pc2," ");	//5:emulator mode,6:mode,7:max row,8:max col,emulator mode//~v716I~
            if (ii==7)                                             //~v716I~
                rowm=atoi(pc2);    //max row                       //~v716I~
            else                                                   //~v716I~
            if (ii==8)                                             //~v8@4R~
                colm=atoi(pc2);    //max col                       //~v8@4R~
            else                                                   //~v8@4R~
            if (ii==9)                                             //~v716I~
                rowc=atoi(pc2);    //current row                   //~v716I~
            else                                                   //~v8@HI~
            if (ii==10)                                            //~v8@HI~
                colc=atoi(pc2);    //current row                   //~v8@HI~
        }                                                          //~v716I~
UTRACEP("maxrow=%d,currow=%d\n",rowm,rowc);                        //~v716I~
    }
    if (Popt & SENDO_SELECTROW)                                    //~v719R~
    	startrow=Ppthtb->THTstartrow;	//parameter                //~v719R~
    else                                                           //~v719I~
    	startrow=-1;                                               //~v719I~
    Ppthtb->THTmaxrow=rowm;                                        //~v716I~
    Ppthtb->THTcurrow=rowc;                                        //~v716I~
    Ppthtb->THTmaxcol=colm; //screen width                         //~v8@4R~
    Ppthtb->THTcurcol=colc; //current csr pos(left most is 0)      //~v8@HR~
//	rc|=editresp(Popt,startrow,Pbuff,strlen(Pbuff));               //~v8@3R~
//  rc|=editresp(Popt,Ppthtb,startrow,Pbuff,strlen(Pbuff));        //~v8@3I~//~vv30R~
    rc|=editresp(Popt,Ppthtb,startrow,Pbuff,(int)strlen(Pbuff));   //~vv30I~
//  *Pplen=strlen(Pbuff);                                          //~vv30R~
    *Pplen=(int)strlen(Pbuff);                                     //~vv30I~
    if (Popt & SENDO_TOPSNAP)                                      //~v8@3M~
    {                                                              //~v8@3M~
    	toplinelen=min(TOPLINE_SAVEWIDTH,*Pplen);                  //~v8@3I~
//  	UmemcpyZ(G3270topline,Pbuff,toplinelen);  //to chk topline contents//~v8@3I~//~vv30R~
    	UmemcpyZ(G3270topline,Pbuff,(size_t)toplinelen);  //to chk topline contents//~vv30I~
    }                                                              //~v8@3M~
UTRACEP("send3270readresp rc=%d,totlen=%d\n",rc,totlen);
//UTRACED("Precv data",Pbuff,totlen);
    return rc;
}//write3270readresp
//****************************************************************
//*editresp
//*drop line header,optionaly before start row                     //~v719R~
//*ret 0 or REENTER detected by option                             //~v719I~
//****************************************************************
int editresp(int Popt,PTHREADTB Ppthtb,int Pstartrow,char *Pbuff,int Plen)//~v8@3R~
{
    char *pc,*pc2,*pc3;
    char *pclast=0,*pclasto=0;                                     //~v8@qR~
    int row=0,rc=0;                                                //~v719R~
    int cmdshellsw=0,startrow;                                     //~v8@eI~
    int chkspf6sw;                                                 //~v8@tI~
    int lastrow=0;                                                 //~v8@xI~
//****************************************
UTRACEP("editresp:start  startrow=%d,len=%d\n",Pstartrow,Plen);    //~v8@3I~
//UTRACED("editresp:Buff",Pbuff,Plen);                             //~v8@eR~
	startrow=Pstartrow;                                            //~v8@eI~
    chkspf6sw=SENDO_CHK_OPTION2(Popt,Ppthtb,THTO2_CHKSPF6);        //~v8@tI~
    if (Popt & SENDO_CHKSPF)                                       //~v8@eI~
        for (pc=Pbuff;;row++)                                      //~v8@eI~
        {                                                          //~v8@eI~
            pc2=strstr(pc,LINEHDR);                                //~v8@eI~
            if (!pc2)                                              //~v8@eI~
                break;                                             //~v8@eI~
        	pc2+=LINEHDRSZ+strspn(pc2+LINEHDRSZ," ");              //~v8@eI~
            if (row==G3270cmdrow)                                  //~v8@eI~
            {                                                      //~v8@eI~
                if (!memcmp(pc2,WORDCHK_SPFNEWCMD,sizeof(WORDCHK_SPFNEWCMD)-1))//cmd shell cmd prompt ===>//~v8@eI~
                {                                                  //~v8@tI~
                    cmdshellsw=1;                                  //~v8@eI~
                    if (chkspf6sw)                                 //~v8@tI~
						SENDO_SET_OPTION2RC(Ppthtb,THTO2RC_ONSPF6);//~v8@tI~
                }                                                  //~v8@tI~
                else                                               //~v8@eI~
                    break;                                         //~v8@eI~
            }                                                      //~v8@eI~
            else                                                   //~v8@eI~
            if (cmdshellsw==1) //after cmd shell new cmd line      //~v8@eI~
            {                                                      //~v8@eI~
                if (!memcmp(pc2,WORDCHK_SPFOLDCMD,sizeof(WORDCHK_SPFOLDCMD)-1))//cmd shell cmd old cmd line//~v8@eI~
                    cmdshellsw=2;                                  //~v8@eI~
            }                                                      //~v8@eI~
            else                                                   //~v8@eI~
            if (cmdshellsw==2) //after cmd shell old cmd line      //~v8@eI~
            {                                                      //~v8@eI~
                if (memcmp(pc2,WORDCHK_SPFOLDCMD,sizeof(WORDCHK_SPFOLDCMD)-1))//cmd shell cmd old cmd line//~v8@eI~
                {                                                  //~v8@eI~
                    cmdshellsw=3;                                  //~v8@eI~
                    startrow=row;                                  //~v8@eI~
                    break;                                         //~v8@eI~
                }                                                  //~v8@eI~
            }                                                      //~v8@eI~
            pc=pc2;                                                //~v8@eI~
        }                                                          //~v8@eI~
    row=0;                                                         //~v8@eI~
UTRACEP("editresp:SPF startrow=%d\n",startrow);                    //~v8@jI~
    for (pc=Pbuff;;)
    {
    	pc2=strstr(pc,LINEHDR);
        if (!pc2)
        {                                                          //~v79dI~
        	if (!pclast)	//no any header found                  //~v79dI~
            {                                                      //~v79dI~
            	pc2=pc+strspn(pc," ");	                           //~v79dI~
                if (*pc)                                           //~v79dI~
                {                                                  //~v79dI~
                	pclast=pclasto=pc2;                            //~v79dI~
                    lastrow=1;                                     //~v79dI~
                }                                                  //~v79dI~
            }                                                      //~v79dI~
        	break;
        }                                                          //~v79dI~
        row++;                                                     //~v719I~
      	if (row<=startrow)                                         //~v8@eR~
      	{                                                          //~v719I~
	        pc3=strchr(pc2,'\n');                                  //~v719I~
            if (!pc3)                                              //~v719I~
            	break;                                             //~v719I~
            strcpy(pc2,pc3+1);                                     //~v719I~
            pc=pc2;                                                //~v719I~
            continue;                                              //~v719I~
        }                                                          //~v719I~
        pc3=pc2+LINEHDRSZ+strspn(pc2+LINEHDRSZ," ");
        if (!*pc3)
        	break;
//      if (*pc3!='\n') //not all space line                       //~v8@7R~
        if (*pc3!='\n' //not all space line                        //~v8@7I~
        ||   Popt & SENDO_FULLSCR)     //rsh mode (display also space line)//~v8@7R~
        {
//drop hdr column
			if (*(pc2+LINEHDRSZ)==' ')	//7 byte hdr
              if (Popt & SENDO_RSHMODE)     //rsh mode             //~v72BR~
    	    	strcpy(pc2,pc2+LINEHDRSZ);	//same as TSO output,reenter chk not requred//~v72BR~
              else                                                 //~v72BR~
		    	strcpy(pc2,pc2+LINEHDRSZ+1);
            else
		    	strcpy(pc2,pc2+LINEHDRSZ);	//with null
        	if (*pc3!='\n') //not all space line                   //~v8@qR~
            {                                                      //~v8@qI~
            	pclasto=pclast;                                    //~v8@qI~
            	pclast=pc2;           //not(FULLSCR but no data)   //~v8@qR~
                lastrow=row;                                       //~v8@yR~
            }                                                      //~v8@qI~
//          if (Popt & SENDO_REENTERCHK)                           //~v8@qR~
//          {                                                      //~v8@qR~
//          	if (!memcmp(pc2,WORDCHK_REENTER,sizeof(WORDCHK_REENTER)-1))//~v8@qR~
//              	rc=RECVRC_REENTER;                             //~v8@qR~
//          }                                                      //~v8@qR~
//          if (Popt & SENDO_ENTERCHK)                             //~v8@qR~
//          {                                                      //~v8@qR~
//          	if (!memcmp(pc2,WORDCHK_ENTER,sizeof(WORDCHK_ENTER)-1))//~v8@qR~
//              	rc=RECVRC_REENTER;                             //~v8@qR~
//          }                                                      //~v8@qR~
//          if (Popt & SENDO_UIDINUSECHK)                          //~v8@qR~
//          {                                                      //~v8@qR~
//          	if (strstr(pc2,WORDCHK_INUSE))                     //~v8@qR~
//              	rc=RECVRC_REENTER;                             //~v8@qR~
//          }                                                      //~v8@qR~
        }
        else
        {                                                          //~v8@4R~
        	strcpy(pc2,pc3+1);
        }                                                          //~v8@4R~
        pc=pc2;
    }
    if (!pclast)  // fullscr(keep space line) but fully no data    //~v8@qR~
    {                                                              //~v8@mI~
    	*Pbuff=0;                                                  //~v8@eI~
        if (cmdshellsw)                                            //~v8@qI~
        	rc|=RECVRC_SPFNODATA|RECVRC_READY;                     //~v8@qR~
    }                                                              //~v8@mI~
    else                                                           //~v8@qR~
    {                                                              //~v8@qR~
UTRACEP("editresp last line=%s\n",pclast);                         //~v8@qR~
        pc2=pclast;                                                //~v8@qI~
        if (!memcmp(pc2,WORDCHK_PENDINGENTER,sizeof(WORDCHK_PENDINGENTER)-1)) //"***"//~v8@qR~
        {                                                          //~v8@qR~
        	pc3=pc2+sizeof(WORDCHK_PENDINGENTER)-1;                //~v8@qR~
        	pc3+=strspn(pc3," ");                                  //~v8@qI~
            if (!*pc3||*pc3=='\n')                                 //~v8@qR~
            {                                                      //~v8@yI~
        		if (Popt & SENDO_CHK3AST)                          //~v8@qR~
                {                                                  //~v8@qI~
        			rc=RECVRC_3ASTERISK;                           //~v8@qR~
                    pc2=pclasto;//chk prev line                    //~v8@qI~
                }                                                  //~v8@qI~
				Ppthtb->THTflag2|=THTF2_3AST;    //"***" pending enter//~v8@yI~
    		}                                                      //~v8@yI~
        }                                                          //~v8@qR~
        if (pc2)                                                   //~v8@qI~
        {                                                          //~v8@qI~
            if (!memcmp(pc2,WORDCHK_READY,sizeof(WORDCHK_READY)-1))//~v8@qR~
            {                                                      //~v8@qR~
                pc3=pc2+sizeof(WORDCHK_READY)-1;                   //~v8@qR~
                pc3+=strspn(pc3," ");                              //~v8@qR~
                if (!*pc3||*pc3=='\n')                             //~v8@qR~
                {                                                  //~v8@xI~
                    if (Popt & SENDO_CHKREADY)                     //~v8@qR~
                        rc|=RECVRC_READY;                          //~v8@qR~
                    if (lastrow)                                   //~v8@xI~
	    				Ppthtb->THTreadyrow=lastrow;               //~v8@xI~
                }                                                  //~v8@xI~
            }                                                      //~v8@qR~
            else                                                   //~v8@qR~
            {                                                      //~v8@qR~
                if (!memcmp(pc2,WORDCHK_IKJ,sizeof(WORDCHK_IKJ)-1))//~v8@qR~
                    pc2+=sizeof(WORDCHK_IKJ)-1;                    //~v8@qR~
                pc3=pc2+strspn(pc2," ");                           //~v8@qR~
                if (Popt & SENDO_UIDINUSECHK)                      //~v8@qR~
                {                                                  //~v8@qR~
                    if (strstr(pc2,WORDCHK_INUSE))                 //~v8@qR~
                        rc|=RECVRC_REENTER;                        //~v8@qR~
                }                                                  //~v8@qR~
                if (Popt & SENDO_REENTERCHK)                       //~v8@qR~
                {                                                  //~v8@qR~
                    if (!memcmp(pc2,WORDCHK_REENTER,sizeof(WORDCHK_REENTER)-1))//~v8@qR~
                        rc|=RECVRC_REENTER;                        //~v8@qR~
                }                                                  //~v8@qR~
                if (Popt & SENDO_ENTERCHK)                         //~v8@qR~
                {                                                  //~v8@qR~
                    if (!memcmp(pc2,WORDCHK_ENTER,sizeof(WORDCHK_ENTER)-1))//~v8@qR~
                        rc|=RECVRC_REENTER;                        //~v8@qR~
                }                                                  //~v8@qR~
            }                                                      //~v8@qR~
        }                                                          //~v8@qI~
    }//not null line exist                                         //~v8@qR~
UTRACEP("editresp:return rc=%d\n",rc);                             //~v8@3I~
UTRACED("editresp:Buff",Pbuff,Plen);                               //~v8@3I~
    return rc;                                                     //~v719R~
}//editresp
//****************************************************************
//*read pipe from 3270 child process
//*exit thread if EOF detected
//*return readlen
//****************************************************************
int read3270(PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz)
{
    int fdr,len;
//************************
UTRACEP("read3270 entered\n");
    fdr=Ppthtb->THTpipec2p;
// 	len=read(fdr,Pbuff,Pbuffsz);                                   //~vv30R~
// 	len=read(fdr,Pbuff,(size_t)Pbuffsz);                           //~vv30I~//+vv31R~
   	len=(int)read(fdr,Pbuff,(size_t)Pbuffsz);                      //+vv31I~
//    if (!len)                                                    //~v72KR~
//    {                                                            //~v72KR~
//        uerrmsgmt(1,"Pipe(stdout from 3270) was closed.",0);     //~v72KR~
//UTRACEP("read EOF then thread exit\n");                          //~v72KR~
//        close3270(Ppthtb);                                       //~v72KR~
//        postbackmain(Ppthtb,THTRC_SUBEXIT);                      //~v72KR~
//        exitthread(Ppthtb,THTEC_CHILDEND);                       //~v72KR~
//    }                                                            //~v72KR~
UTRACEP("read3270 len=%d\n",len);
UTRACED("read3270",Pbuff,len);                                     //~vafcR~
    return len;
}//read3270
//****************************************************************
//*write to pipe to 3270 child process
//*return rc
//****************************************************************
int write3270(PTHREADTB Ppthtb,char *Pcmd)
{
    int fdw,len,lenw;
	char buff[MAX_CMDSZ];                                          //~v716I~
//************************
	strcpy(buff,Pcmd);                                             //~v716M~
    strcat(buff,"\n");  	 //required!!                          //~v716I~
    fdw=Ppthtb->THTpipep2c;
//  len=strlen(buff);                                              //~v716R~//~vv30R~
    len=(int)strlen(buff);                                         //~vv30I~
UTRACED("write3270",buff,len);                                     //~v716R~
//  lenw=write(fdw,buff,(UINT)len);//tell pid to wxe,write last null//~v716R~//+vv31R~
    lenw=(int)write(fdw,buff,(UINT)len);//tell pid to wxe,write last null//+vv31I~
    if (lenw!=len)
    {
    	uerrmsgmt(1,"sendwrite failed %s,req=%d,written=%d",0,
        		buff,len,lenw);                                    //~v716R~
    	return 4;
    }
//  usleepms(200);	//screen draw  may be delayed to miss chk word "READY"//~v716R~
UTRACEP("write3270 writelen=%d\n",lenw);
    return 0;
}//write3270
