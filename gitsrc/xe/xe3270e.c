//*CID://+vb30R~:                              update#= 1167;      //+vb30R~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//v7af:081113 (3270) add "Continue" to logon err action to do not abandon logon//~v79fI~
//                   "_errmsg" :chk after okmsg exist chk          //~v79fI~
//                   "|okmsg"  :is optional                        //~v79fI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v9@c:080718 3270:che row after =6\n                              //~v9@cI~
//v9@a:080718 3270:reject missing passowrd. logon fail by PFn from console when NO TSO session status//~v9@aI~
//            (no chk for tunkey)                                  //~v9@aI~
//v9@0:080715 3270:use Clear after vtam prompt checked on 3270.cfg for the case//~v9@0I~
//                 after disconnected by PF3, field may protected(E) for LON input.//~v9@0I~
//                 Clear may need not wait                         //~v9@0I~
//v8@v:080624 3270:prelogon msg chk required for the case 522 abend logoff//~v8@vI~
//v8@t:080623 3270:curso move to =6 panel home for cmd(ftp,listds,..) input//~v8@tI~
//v8@r:080621 3270:use not prelogon msg but logon flag to chk already logon//~v8@rI~
//                 acsidentaly host down is rare for real host     //~v8@rI~
//                 (confirm connected each time)                   //~v8@rI~
//                 already logon msg is also needed                //~v8@rI~
//v8@n:080620 3270:no paddinfg \n for String cmd                   //~v8@mI~
//v8@m:080620 3270:check READY on last line(linemode or spf changes temporary to line mode for cmd resonse)//~v8@mI~
//v8@d:080616 3270:test                                            //~v8@dI~
//v8@9:080613 3270:cmd,such as tab,movecursor,support for action of logon logoff//~v8@8I~
//v8@8:080613 3270:cmdline row parameter                           //~v8@8I~
//v8@4:080609 for the case tso cmd response start from end of line of current(=6) panel(after logon panel err)//~v8@4I~
//v8@3:080602 receive also hostname on xehosts file to identify logon command//~v8@3I~
//v8@1:080526 (3270)TSOE support                                   //~v8@1I~
//*************************************************************
//*xe3270e.c                                                       //~v8@1R~
//*  TSOE                                                          //~v8@mI~
//*************************************************************

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>      //offsetof
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

//**********
#ifdef LNX
	#define _MT		//multithred notification to UTRACE etc
    #include <unistd.h>
#else
	#include <dos.h>
	#include <errno.h>
#endif
//**********
#include <ulib.h>
#include <ualloc.h>
#include <uque.h>
#include <uerr.h>
#include <ufile.h>
#include <uftp.h>                                                  //~v8@1I~
#include <u3270.h>
#include <utrace.h>
#include <ustring.h>
#include <uedit.h>
#include <uparse.h>
#include <uproc.h>                                                 //~v8@1M~
#include <ucvext.h>                                                //~v79aI~

#include "xe.h"
#include "xe3270.h"
#include "xe3270s.h"

//*************************************************************
char *srchlogoffecmd(int Popt,PTHREADTB Ppthtb);                   //~v8@1I~
int doactioncmd(int Popt,PTHREADTB Ppthtb,char *Pcmd);             //~v8@8I~
#define DOARC_CONT  -99                                            //~v79fI~
//**************************************************************** //~v8@1I~
//*cfg defined logon process                                       //~v8@1R~
//**************************************************************** //~v8@1I~
int funclogone(int Popt,PTHREADTB Ppthtb,char *Pcmdwk,char *Ppuserpswd)//~v8@1I~
{                                                                  //~v8@1I~
    char *ppswd,*pc,*respchk;                                      //~v8@8R~
    char *wordrep_keyword[3],*wordrep_data[3],*pcmd;               //~v8@8R~
    int rc=0,ii,jj,kk,msgidx,chkmopt;                              //~v8@dR~
    int opt;                                                       //~v8@8R~
    int rc2;                                                       //~v79fI~
    int intsleepsw=0;                                              //~v8@8R~
    int optionalokmsgsw;                                           //~v79fI~
    PCONFDEST pconfd,pconfderrmsg;                                 //~v8@8R~
//************************                                         //~v8@1I~
	pconfd=cfggetlogoncmd(0,Ppthtb);                               //~v8@8I~
	pconfderrmsg=cfggetlogonerr(0,Ppthtb);                         //~v8@8I~
	chkmopt=SENDO_SNAPPRINT|SENDO_DROPSTATUS;//|SENDO_ERRMSGLINE;  //~v8@3R~
	ppswd=strchr(Ppuserpswd,'/');                                  //~v8@1R~
    if (ppswd)                                                     //~v8@1I~
    	*ppswd++=0;                                                //~v8@1R~
    else                                                           //~v8@1I~
    {                                                              //~v9@aI~
//      ppswd="";                                                  //~v9@aR~
        uerrmsgmt(1,"Logon rejected by missing password parm",0);  //~v9@aI~
        return U3CR_RC_OTHER;                                      //~v9@aI~
    }                                                              //~v9@aI~
    wordrep_keyword[0]=CONFIGP_CMDLOGON_USER;                      //~v8@1I~
    wordrep_keyword[1]=CONFIGP_CMDLOGON_PSWD;                      //~v8@1I~
    wordrep_keyword[2]=0;                                          //~v8@1I~
    wordrep_data   [0]=Ppuserpswd;                                 //~v8@1I~
    wordrep_data   [1]=ppswd;                                      //~v8@1I~
    wordrep_data   [2]=0;                                          //~v8@1I~
	for (ii=0;ii<pconfd->CONFDlogoncmdno;ii++)                     //~v8@8R~
    {                                                              //~v8@1I~
        if (intsleepsw)    //not 1st time                          //~v8@8I~
    		usleepms(100); //between cmd                           //~v8@8M~
        intsleepsw=1;                                              //~v8@8I~
    	pcmd=pconfd->CONFDlogoncmd[ii];                            //~v8@8R~
		opt=SENDO_DROPSTATUS;                                      //~v8@8I~
        if (strchr(pcmd,'%'))                                      //~v8@8I~
        {                                                          //~v8@8I~
        	if (ustrstri(pcmd,CONFIGP_CMDLOGON_PSWD))              //~v8@8R~
            	opt|=SENDO_PSWD;                                   //~v8@8I~
            pc=uwordrep(WORDREP_IC,pcmd,wordrep_keyword,wordrep_data,0,0);//~v8@8I~
            strcpy(Pcmdwk,pc);                                     //~v8@dR~
            ufree(pc);                                             //~v8@8I~
            pcmd=Pcmdwk;                                           //~v8@8I~
        }                                                          //~v8@8I~
		rc=doactioncmd(opt,Ppthtb,pcmd);                           //~v8@8I~
//      if (rc)                                                    //~v8@8R~//~v79fR~
        if (rc>0)                                                  //~v79fI~
        	break;                                                 //~v8@8R~
        respchk=pconfd->CONFDlogoncmdrespchk[ii];                  //~v8@8R~
        if (respchk)                                               //~v8@1I~
        {                                                          //~v8@1I~
UTRACEP("respchk okmsg=%s\n",respchk);                             //~v79fI~
            if (*respchk==OKMSG_OPTIONALID)                        //~v79fR~
            {                                                      //~v79fI~
                optionalokmsgsw=1;                                 //~v79fI~
                respchk++;                                         //~v79fI~
            }                                                      //~v79fI~
            else                                                   //~v79fI~
                optionalokmsgsw=0;                                 //~v79fI~
        	rc=0;                                                  //~v8@1I~
            kk=0;                                                  //~v8@3I~
        	for (jj=pconfd->CONFDlogoncmdrespchkretry[ii];jj>0;jj--)//~v8@8R~
            {                                                      //~v8@1I~
UTRACEP("respchk jj=%d resp=%s\n",jj,respchk);                     //~v8@1I~
	    		rc=screenchkm(chkmopt,Ppthtb,respchk,pconfderrmsg->CONFDlogoncmderrmsgno,pconfderrmsg->CONFDlogoncmderrmsgtbl); //snap screen//~v8@8R~
                if (!rc)                                           //~v8@1I~
                {                                                  //~v8@1I~
	         		uerrmsgmt(1,"repchk ok     for '%s'",0,        //~v8@1I~
								respchk);                          //~v8@1I~
                	break;                                         //~v8@1I~
                }                                                  //~v8@1I~
                if (rc<0)	//errmsg detected                      //~v8@1I~
                {                                                  //~v8@1I~
                	msgidx=-rc-1;                                  //~v8@1I~
                    pc=pconfderrmsg->CONFDlogoncmderraction[msgidx];//~v8@8R~
                    rc2=                                           //~v79fI~
					doactioncmd(SENDO_SNAPPRINT|SENDO_NORESPMSG,Ppthtb,pc);//~v8@dI~
                  	if (rc2==DOARC_CONT)                           //~v79fI~
                  		rc=rc2;	                                   //~v79fI~
                	break;                                         //~v8@1I~
                }                                                  //~v8@1I~
                kk++;                                              //~v8@3I~
                if (jj>1) //not last                               //~v8@dI~
                {                                                  //~v8@dI~
    				usleepms(kk*100); //gladualy inclease sleep time//~v8@dR~
		         	uerrmsgmt(0,"repchk retry(%d) for '%s'\n",0,   //~v8@vR~
								kk,respchk);                       //~v8@dM~
                }                                                  //~v8@dI~
//          	if (entersw)                                       //~v8@8R~
//      			funcenter(0,Ppthtb);                           //~v8@8R~
            }                                                      //~v8@1I~
            if (rc==DOARC_CONT)                                    //~v79fI~
            	rc=0;	//ignore errmsg by "CONTINUE" action       //~v79fI~
            if (rc<0) //errmsg match                               //~v8@1I~
            {                                                      //~v8@1I~
            	rc=U3CR_RC_OTHER;                                  //~v8@1I~
            	break;                                             //~v8@1I~
            }                                                      //~v8@1I~
            if (!jj)                                               //~v8@3I~
            {                                                      //~v8@3I~
                uerrmsgmt(1,"Err:%d retry failed for '%s'",0,      //~v8@3I~
			        		pconfd->CONFDlogoncmdrespchkretry[ii],respchk);//~v8@8R~
              if (!optionalokmsgsw)                                //~v79fI~
              {                                                    //~v79fI~
            	rc=U3CR_RC_OTHER;                                  //~v8@3I~
            	break;                                             //~v8@3I~
              }                                                    //~v79fI~
            }                                                      //~v8@3I~
        }                                                          //~v8@1I~
        else                                                       //~v8@1I~
	    	screenchk(SENDO_SNAPPRINT|SENDO_DROPSTATUS,Ppthtb,0); //snap screen//~v8@1R~
  	}                                                              //~v8@1I~
UTRACEP("funclogonE exit rc=%d\n",rc);                             //~v8@1I~
    return rc;                                                     //~v8@1I~
}//funclogone                                                      //~v8@1I~
//**************************************************************** //~v8@1I~
//*cfg defined logoff process                                      //~v8@1I~
//**************************************************************** //~v8@1I~
int funclogoffe(int Popt,PTHREADTB Ppthtb)                         //~v8@1I~
{                                                                  //~v8@1I~
    char *respchk;                                                 //~v8@4I~
    char *pcmd;                                                    //~v8@8R~
    int rc=0,ii,jj,kk,opt,intsleepsw=0;                            //~v8@8R~
    PCONFDEST pconfd;                                              //~v8@8I~
//************************                                         //~v8@1I~
	rc=cmdreadychk(SENDO_CASE|SENDO_DROPSTATUS|SENDO_LOGON,Ppthtb); //pre logon status chk(already logoff)//~v8@8I~
    if (rc)    //already logoff                                    //~v8@8I~
    	return 0;                                                  //~v8@8I~
	pconfd=cfggetlogoffcmd(0,Ppthtb);                              //~v8@8I~
	opt=SENDO_SNAPPRINT|SENDO_DROPSTATUS;                          //~v8@4I~
	for (ii=0;ii<pconfd->CONFDlogoffcmdno;ii++)                    //~v8@8R~
    {                                                              //~v8@1I~
        if (intsleepsw)    //not 1st time                          //~v8@8I~
    		usleepms(100); //between cmd                           //~v8@8I~
        intsleepsw=1;                                              //~v8@8I~
    	pcmd=pconfd->CONFDlogoffcmd[ii];                           //~v8@8R~
		rc=doactioncmd(opt,Ppthtb,pcmd);                           //~v8@8I~
        respchk=pconfd->CONFDlogoffcmdrespchk[ii];                 //~v8@8R~
        if (respchk)                                               //~v8@4I~
        {                                                          //~v8@4I~
        	rc=0;                                                  //~v8@4I~
            kk=0;                                                  //~v8@4I~
        	for (jj=pconfd->CONFDlogoffcmdrespchkretry[ii];jj>0;jj--)//~v8@8R~
            {                                                      //~v8@4I~
UTRACEP("respchk jj=%d resp=%s\n",jj,respchk);                     //~v8@4I~
	    		rc=screenchk(opt,Ppthtb,respchk); //snap screen    //~v8@4R~
                if (!rc)                                           //~v8@4I~
                {                                                  //~v8@4I~
	         		uerrmsgmt(1,"repchk ok     for '%s'",0,        //~v8@4I~
								respchk);                          //~v8@4I~
                	break;                                         //~v8@4I~
                }                                                  //~v8@4I~
                kk++;                                              //~v8@4I~
                if (jj>1) //not last                               //~v8@dI~
                {                                                  //~v8@dI~
    				usleepms(kk*100); //gladualy inclease sleep time//~v8@dR~
		         	uerrmsgmt(0,"repchk retry(%d) for '%s'\n",0,   //~v8@vR~
								kk,respchk);                       //~v8@dI~
                }                                                  //~v8@dI~
//          	if (entersw)                                       //~v8@8R~
//      			funcenter(0,Ppthtb);                           //~v8@8R~
            }                                                      //~v8@4I~
            if (!jj)                                               //~v8@4I~
            {                                                      //~v8@4I~
                uerrmsgmt(1,"Err:%d retry failed for '%s'",0,      //~v8@4I~
			        		pconfd->CONFDlogoffcmdrespchkretry[ii],respchk);//~v8@8R~
            	rc=U3CR_RC_OTHER;                                  //~v8@4I~
            	break;                                             //~v8@4I~
            }                                                      //~v8@4I~
        }                                                          //~v8@4I~
        else                                                       //~v8@4I~
	    	screenchk(SENDO_SNAPPRINT|SENDO_DROPSTATUS,Ppthtb,0); //snap screen//~v8@4I~
  	}                                                              //~v8@1I~
UTRACEP("funclogoffE exit rc=%d\n",rc);                            //~v8@1I~
    return rc;                                                     //~v8@1I~
}//funclogoffe                                                     //~v8@1I~
//**************************************************************** //~v8@8I~
//*do action cmd                                                   //~v8@8I~
//**************************************************************** //~v8@8I~
int doactioncmd(int Popt,PTHREADTB Ppthtb,char *Pcmd)              //~v8@8I~
{                                                                  //~v8@8I~
    int rc=0,msec,len;                                             //~v8@dR~
    char cmdwk[MAX_CMDSZ],cmdwk2[MAX_CMDSZ];                       //~v8@dR~
    char *pcmd,*pc2;                                               //~v8@dR~
    int continuesw=0;                                              //~v79fR~
//************************                                         //~v8@8I~
UTRACEP("doaction cmd=%s\n",Pcmd);                                 //~v8@dR~
    for (pcmd=Pcmd;;)                                              //~v8@dI~
    {                                                              //~v8@dI~
//      len=USTRLENC(pcmd,';',pc2);                                //~v8@dI~//+vb30R~
        len=(int)USTRLENC(pcmd,';',pc2);                           //+vb30I~
//      UmemcpyZ(cmdwk2,pcmd,len);                                 //~v8@dR~//+vb30R~
        UmemcpyZ(cmdwk2,pcmd,(size_t)len);                         //+vb30I~
        uerrmsgmt(0,"Action=%s\n",0,                               //~v8@dI~
                    cmdwk2);                                       //~v8@dR~
        pcmd=cmdwk2;                                               //~v8@dR~
        if (!stricmp(pcmd,WORDCHK_ENTER))  //Enter cmd             //~v8@dI~
        {                                                          //~v8@dI~
            rc+=funcenter(0,Ppthtb);                               //~v8@dI~
        }                                                          //~v8@dI~
        else                                                       //~v8@dI~
        if (USTRHEADIS_IC(pcmd,CONFIGP_CMDSLEEP))                  //~v8@dI~
        {                                                          //~v8@dI~
            msec=atoi(pcmd+sizeof(CONFIGP_CMDSLEEP)-1);            //~v8@dI~
            if (msec)                                              //~v8@dI~
            {                                                      //~v8@dI~
                uerrmsgmt(0,"Enter to Sleep %d msecc",0,           //~v8@dI~
                            msec);                                 //~v8@dI~
                usleepms(msec);                                    //~v8@dI~
            }                                                      //~v8@dI~
        }                                                          //~v8@dI~
        else                                                       //~v8@dI~
        if (USTRHEADIS_IC(pcmd,CONFIGP_CMDCMD))                    //~v8@dI~
        {                                                          //~v8@dI~
            pcmd=pcmd+sizeof(CONFIGP_CMDCMD)-1;                    //~v8@dI~
            pcmd+=strspn(pcmd," ");                                //~v8@dI~
            rc=funccmd2(SENDO_NORESPMSG,Ppthtb,pcmd);              //~v8@dI~
        }                                                          //~v8@dI~
        else                                                       //~v8@dI~
        if (USTRHEADIS_IC(pcmd,CONFIGP_CMDCONTINUE))               //~v79fI~
        {                                                          //~v79fI~
            continuesw=1;                                          //~v79fI~
            rc=0;                                                  //~v79fI~
        }                                                          //~v79fI~
        else                                                       //~v79fI~
        {                                                          //~v8@dI~
            sprintf(cmdwk,"String \"%s\"",pcmd);                   //~v8@mR~
            rc+=send3270(Popt,Ppthtb,cmdwk);                       //~v8@dI~
        }                                                          //~v8@dI~
        if (!pc2)                                                  //~v8@dI~
            break;                                                 //~v8@dI~
        pcmd=pc2+1;                                                //~v8@dI~
    }                                                              //~v8@dI~
UTRACEP("doaction exit rc=%d\n",rc);                               //~v8@8I~
	if (continuesw)                                                //~v79fI~
		rc=DOARC_CONT;                                             //~v79fI~
    return rc;                                                     //~v8@8I~
}//doactioncmd                                                     //~v8@8R~
//**************************************************************** //~v8@3I~
//*check cmd input available chk                                   //~v8@3I~
//*rc=prelogon                                                     //~v8@mR~
//**************************************************************** //~v8@3I~
int cmdreadychk(int Popt,PTHREADTB Ppthtb)                         //~v8@3I~
{                                                                  //~v8@3I~
	int rc;                                                        //~v8@rR~
    int opt;                                                       //~v8@vR~
    PCONFDEST pconfdprelogon;                                      //~v8@vR~
//************************                                         //~v8@3I~
UTRACEP("cmdreadychk entry\n");                                    //~v8@3I~
	if (Popt & SENDO_LOGON)                                        //~v8@vI~
    {                                                              //~v8@vI~
        pconfdprelogon=cfggetprelogon(0,Ppthtb);                   //~v8@vR~
        if (pconfdprelogon->CONFDprelogonno)  //prelogon msg defined//~v8@vR~
        {                                                          //~v8@vR~
            opt=SENDO_CASE|SENDO_DROPSTATUS;                       //~v8@vR~
            rc=screenchkm(opt,Ppthtb,0,pconfdprelogon->CONFDprelogonno,pconfdprelogon->CONFDlogonprelogontbl);//~v8@vR~
            if (rc<=0)     //found index                           //~v8@vR~
                return RECVRC_PRELOGON;     //pre logon status     //~v8@vR~
        }                                                          //~v8@vR~
        return 0;          //ready wait is by each function        //~v8@vI~
    }                                                              //~v8@vI~
	rc=cmdreadywait(Popt,Ppthtb);                                  //~v8@mI~
UTRACEP("cmdreadychk exit rc=%d\n",rc);                            //~v8@3I~
    return rc;                                                     //~v8@3I~
}//cmdreadychk                                                     //~v8@3I~
//**************************************************************** //~v8@3I~
//*wait 100ms for continuous cmd input                             //~v8@3R~
//* until cmd input avail(=6 panel or "READY" line)                //~v8@3R~
//* rc:cmd ready,4:timeout                                         //~v8@3I~
//**************************************************************** //~v8@3I~
int cmdreadywait(int Popt,PTHREADTB Ppthtb)                        //~v8@3I~
{                                                                  //~v8@3I~
	int rc=0;                                                      //~v8@3R~
    int maxwait,ii;                                                //~v8@8R~
//    PCONFDEST pconfdalready;                                     //~v8@rR~
    int opt;                                                       //~v8@dI~
//************************                                         //~v8@3I~
UTRACEP("cmdreadywait entry\n");                                   //~v8@3I~
    maxwait=10;                                                    //~v8@8R~
//    pconfdalready=cfggetalready(0,Ppthtb);                       //~v8@rR~
  	for (ii=0;ii<maxwait;ii++)	//wait 1 sec                       //~v8@3R~
    {                                                              //~v8@3R~
UTRACEP("cmdreadywait loop wait ii=%d\n",ii);                      //~v8@3I~
//        if (pconfdalready->CONFDlogonalreadychkno)               //~v8@rR~
//        {                                                        //~v8@rR~
//            opt=SENDO_CASE|SENDO_DROPSTATUS|Popt;                //~v8@rR~
//            rc=screenchkm(opt,Ppthtb,0,pconfdalready->CONFDlogonalreadychkno,pconfdalready->CONFDlogonalreadychktbl);//~v8@rR~
//            if (rc<=0)     //found index                         //~v8@rR~
//                if (Popt & SENDO_LOGON)       //logon chk        //~v8@rR~
//                    return 0;                                    //~v8@rR~
//        }                                                        //~v8@rR~
        opt=SENDO_CASE|SENDO_DROPSTATUS|Popt;                      //~v8@mI~
		rc=setcmdready(opt,Ppthtb);  //Home success                //~v8@mR~
        if (!rc)                                                   //~v8@mI~
        	break;                                                 //~v8@mR~
        if (rc & RECVRC_REENTER)                                   //~v8@rR~
        	break;                                                 //~v8@mI~
	    usleepms(100); //gladualy inclease sleep time              //~v8@3R~
    }                                                              //~v8@3R~
    if (ii==maxwait)                                               //~v8@3I~
    {                                                              //~v8@3I~
        uerrmsgmt(1,"Waiting screen change to READY to accept input,-->Timeout %d sec",0,//~v8@8R~
                        100*maxwait/1000);                         //~v8@3I~
        rc=RECVRC_TIMEOUT;                                         //~v8@mR~
    }                                                              //~v8@3I~
UTRACEP("cmdreadywait exit rc=%d\n",rc);                           //~v8@3I~
    return rc;                                                     //~v8@3I~
}//cmdreadywait                                                    //~v8@3R~
//**************************************************************** //~v8@4I~
//* move csr to cmd line                                           //~v8@4I~
//* rc:0,no action,else issued "enter"                             //~v8@4I~
//**************************************************************** //~v8@4I~
int setcmdready(int Popt,PTHREADTB Ppthtb)                         //~v8@4I~
{                                                                  //~v8@4I~
	int rc=0,opt,ii,maxloop;                                         //~v8@mR~//~vafcR~
    int opt2;                                                      //~v8@tR~
    int setspf6sw;                                                 //~v9@cI~
//************************                                         //~v8@4I~
UTRACEP("setcmdready entry opt=%x\n",Popt);                        //~v8@tR~
	opt=Popt|SENDO_CHK3AST|SENDO_CHKREADY|SENDO_CHKSPF             //~v8@mR~
	        |SENDO_ENTERCHK|SENDO_REENTERCHK;                      //~v8@mI~
    maxloop=3;      //enter could not break                        //~v8@rR~
    for (ii=0;ii<maxloop;ii++)                                     //~v8@mR~
    {                                                              //~v8@mI~
UTRACEP("setcmdready loop=%d\n",ii+1);                             //~v8@rI~
    	rc=screenchk(opt,Ppthtb,0);                                //~v8@mI~
UTRACEP("setcmdready screenchk rc=%d\n",rc);                       //~v9@aI~
    	if (rc & RECVRC_3ASTERISK) //pending *** at last line      //~v8@mI~
        {                                                          //~v8@mI~
			funcenter(SENDO_NORESPMSG,Ppthtb);      //try enter    //~v8@mI~
            rc=RECVRC_TIMEOUT;                                     //~v8@mI~
            continue;                                              //~v8@mI~
        }                                                          //~v8@mI~
    	if (rc & RECVRC_READY) //READY  last line or SPFNODATA     //~v8@rR~
    	  if (!(rc & RECVRC_SPFNODATA)) //not spf6(READY MODE)     //~v8@tI~
        	return 0;                                              //~v8@mI~
    	if (rc & RECVRC_REENTER) //READY  last line                //~v8@mI~
        	return RECVRC_REENTER;                                 //~v8@mI~
        if (Popt & SENDO_CMDLINE)  //chk cmd input available       //~v8@tI~
        {                                                          //~v8@tI~
            opt2=Popt;                                             //~v8@tI~
            if (!(rc & RECVRC_ONSPF6))  //not on spf6              //~v8@tI~
            {                                                      //~v9@cI~
                SENDO_SET_OPTION2(opt2,Ppthtb,THTO2_SETSPF6);      //~v8@tI~
                setspf6sw=1;                                       //~v9@cI~
            }                                                      //~v9@cI~
            else                                                   //~v9@cI~
                setspf6sw=0;                                       //~v9@cI~
            rc=clearcmdline(opt2,Ppthtb);                          //~v8@tI~
            if (!rc)                                               //~v8@tI~
              if (!setspf6sw)//=6 not issued,else retry screenchk  //~v9@cI~
                return 0;                                          //~v8@tI~
        }                                                          //~v8@tI~
        else                                                       //~v8@tI~
    		if (rc & RECVRC_READY) //ready by SPFNODATA spf6       //~v8@tI~
                return 0;                                          //~v8@tI~
    }                                                              //~v8@4I~
UTRACEP("setcmdready exit rc=%d\n",rc);                            //~v8@mR~
    return rc;                                                     //~v8@4I~
}//setcmdready                                                     //~v8@4I~
//**************************************************************** //~v8@rI~
//* clear cmdline                                                  //~v8@rI~
//**************************************************************** //~v8@rI~
int clearcmdline(int Popt,PTHREADTB Ppthtb)                        //~v8@rI~
{                                                                  //~v8@rI~
	int rc=0;                                                      //~v8@tR~
//************************                                         //~v8@rI~
UTRACEP("clearcmdline entry opt=%x\n",Popt);                       //~v8@tR~
	rc|=send3270(Popt,Ppthtb,"Home");                              //~v8@rR~
UTRACEP("clearcmdline home rc=%d\n",rc);                           //~v9@aI~
	rc|=send3270(Popt,Ppthtb,"EraseEOF");                          //~v8@rI~
UTRACEP("clearcmdline eraseeof rc=%d\n",rc);                       //~v9@aI~
	if (SENDO_CHK_OPTION2(Popt,Ppthtb,THTO2_SETSPF6))              //~v8@tM~
    {                                                              //~v8@tI~
		rc|=send3270(Popt|SENDO_NORESPMSG,Ppthtb,"String =6\\n");  //~v8@tM~
UTRACEP("clearcmdline =6 rc=%d\n",rc);                             //~v9@aI~
    	funcsnap(SENDO_NORESPMSG|SENDO_SNAPPRINT,Ppthtb);          //~v9@cR~
    }                                                              //~v8@tI~
UTRACEP("clearcmdline exit rc=%d\n",rc);                           //~v8@tR~
    return rc;                                                     //~v8@rI~
}//clearfield                                                      //~v8@rI~
//**************************************************************** //~v8@4I~
//*wait 100ms for continuous cmd input                             //~v8@4I~
//* until cmd input avail(=6 panel or "READY" line)                //~v8@4I~
//* rc:cmd ready,4:timeout                                         //~v8@4I~
//**************************************************************** //~v8@4I~
int ftperrlog(int Popt)                                            //~v8@4R~
{                                                                  //~v8@4I~
static int Sstat;                                                  //~v8@4I~
#define FTPELS_INIT       0x01     //init end                      //~v8@4I~
#define FTPELS_ERR        0x02     //file err                      //~v8@4I~
#define FTPELS_OPEN       0x04     //opend                         //~v8@4I~
	FILE *fh;                                                      //~v8@4I~
    char *pmsg;                                                    //~v8@4R~
    char cdate[12];                                                //~v8@4I~
                                                                   //~v8@4I~
//************************                                         //~v8@4I~
UTRACEP("ftperrlog enter");                                        //~v8@4I~
    if (Sstat & FTPELS_ERR)                                        //~v8@4I~
    	return 4;                                                  //~v8@4I~
    pmsg=ugeterrmsg2();	//no clear after get                       //~v8@4I~
    if (!pmsg)                                                     //~v8@4I~
    	return 0;                                                  //~v8@4I~
	if (!(fh=fopen(G3270ftperrlogfile,"a")))	//append mode      //~v8@4R~
    {                                                              //~v8@4I~
	    Sstat|=FTPELS_ERR;                                         //~v8@4R~
    	return 4;                                                  //~v8@4I~
    }                                                              //~v8@4I~
    utimeedit("YYYY/MM/DD",cdate);                                 //~v8@4I~
    *(cdate+10)=0;                                                 //~v8@4I~
	fprintf(fh,"%s %s\n",cdate,pmsg);                              //~v8@4R~
    fclose(fh);                                                    //~v8@4I~
UTRACEP("ftperrlog exit");                                         //~v8@4I~
    return 0;                                                      //~v8@4R~
}//ftperrlog                                                       //~v8@4I~
//**************************************************************** //~v8@8I~
//* init thtb by config parm                                       //~v8@8I~
//* rc:cmd ready,4:timeout                                         //~v8@8I~
//**************************************************************** //~v8@8I~
int getcfgparm(int Popt,PTHREADTB Ppthtb)                          //~v8@8I~
{                                                                  //~v8@8I~
    int idx,idx1,idx2;                                             //~v8@8R~
    PCONFDEST pconfd;                                              //~v8@8I~
//*******************                                              //~v8@8I~
    idx1=srchconfd(Popt,Ppthtb->THThostname);                      //~v8@8R~
    idx2=srchconfd(Popt,Ppthtb->THThostname2);                     //~v8@8I~
    idx=max(idx1,idx2);                                            //~v8@8I~
    Ppthtb->THThosttblidx=idx; //for start3270                     //~v8@8I~
    pconfd=G3270confd+idx;                                         //~v8@8I~
    if (!(pconfd->CONFDoptions & THTF2_OPTIONSET)) //config option parm specified//~v8@8R~
	    pconfd=G3270confd;                                         //~v8@8I~
//  Ppthtb->THTflag2=pconfd->CONFDoptions|THTF2_OPTIONSET;         //~v8@8R~//+vb30R~
    Ppthtb->THTflag2=(int)(pconfd->CONFDoptions|THTF2_OPTIONSET);  //+vb30I~
    Ppthtb->THTcmdrow=G3270cmdrow;//for cmd input ready chk        //~v8@8I~
    return 0;                                                      //~v8@8I~
}//getcfgparm                                                      //~v8@8I~
//**************************************************************** //~v8@dI~
//* chk cmd is wait response type                                  //~v8@dI~
//* rc:1:wait response,0:no host response                          //~v8@dI~
//**************************************************************** //~v8@dI~
int iswaitaction(int Popt,char *Pcmd)                              //~v8@dR~
{                                                                  //~v8@dI~
static char *SwaitAction[]={                                       //~v8@dI~
		WORDCHK_STRING,                                            //~v8@dI~
//  	"Attn","Clear","Connect","CusorSelect","Disconnect","Enter","Interrupt",//~v9@0R~
    	"Attn",/*"Clear",*/ "Connect","CusorSelect","Disconnect","Enter","Interrupt",//~v9@0I~
        "PA","PF","Script","SysReq","Transfer",                    //~v8@dI~
        0};                                                        //~v8@dI~
    char *pc,**ppc;                                                //~v8@dR~
    int len,len2;                                                  //~v8@dI~
//*******************                                              //~v8@dI~
//  len=strlen(Pcmd);                                              //~v8@dI~//+vb30R~
    len=(int)strlen(Pcmd);                                         //+vb30I~
	for (ppc=SwaitAction;pc=*ppc,pc;ppc++)                         //~v8@dI~
    {                                                              //~v8@dI~
//  	len2=strlen(pc);                                           //~v8@dI~//+vb30R~
    	len2=(int)strlen(pc);                                      //+vb30I~
        if (len>=len2                                              //~v8@dI~
//      &&  !memicmp(Pcmd,pc,len2)                                 //~v8@dI~//+vb30R~
        &&  !memicmp(Pcmd,pc,(size_t)len2)                         //+vb30I~
        )                                                          //~v8@dI~
        {                                                          //~v8@dI~
        	if (ppc==SwaitAction) //String cmd                     //~v8@dR~
            {                                                      //~v8@dI~
            	if (strstr(pc,"\\n"))                              //~v8@dI~
                	return 1;                                      //~v8@dR~
                else                                               //~v8@dI~
                	return 0;                                      //~v8@dI~
            }                                                      //~v8@dI~
        	return 1;                                              //~v8@dI~
        }                                                          //~v8@dI~
    }                                                              //~v8@dI~
    return 0;                                                      //~v8@dI~
}//iswaitaction                                                    //~v8@dI~
