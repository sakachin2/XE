//*CID://+v7biR~:                             update#=  453;       //~v7biR~
//************************************************************* //~5825I~
//*uproc2.c                                                        //~v5euR~
//* parse-redirect,rsh                                             //~v5euR~
//*************************************************************    //~v022I~
//v7bi:240403 WINCON:flag ctl for chk is-windows-terminal for performance. under Windows terminal 0x01-06 cause shift display column.//~v7biI~
//v7a6:240226 chktermnal by GetConsoleMode                         //~v7a6I~
//v761:221214 for v760,chk parent to find WindowTerminal           //~v761I~
//v6T7:180220 stack errmsg to errmsg.<pid> and issue notification at initcomp//~v6T7I~
//v6T6:180219 icu loaderr clear errmsg from ini file,stdout from loaderr//~v6T6I~
//v6M3:170824 (Lnx) putenv to LD_LIRARY_PATH is not effective(loader chk it at pgm startup and ignore putenv after startup)//~v6M3I~
//v6M2:170824 (Bug)v6M0 faile if path is multiple devided by ";"/":"//~v6M2I~
//v6M0:170808 err "LoadLibrary failed for icuucxx"-=>loaddll using ICU_DATA param//~v6M0I~
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6g4:120512 ICU api suffix for 4.2 is also 4_2 like as 4.0(4_2)  //~v6g4I~
//v6fi:120428 dlerror msg is localized,corrupted char on console   //~v6fiI~
//v6fh:120428 (Linux:BUG)multiple dll open err msg because errno is 0 after dlopen error//~v6fhI~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v5ku:070705 helpmsg wait should be avoid when redirected         //~v5kuI~
//v5kb:070518 split uproc2.c to uproc22.c for link trouble in LNX(pthread)(move v5iv & v5ja to uproc22)//~v5kbI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5iv:060906 3270server support(2nd cmdserver)                    //~v5ivI~
//v5it:060826 gcc:submit abend by bat file is not .bat by getpid is not done(gcc support getpid)//~v5itI~
//v5is:060826 stdin support for uprocparseredirect                 //~v5isI~
//v5g1:050428 ugetpid function add                                 //~v5g1I~
//v5ew:041031 rsh chmod:cmd string log to ftplog                   //~v5ewI~
//v5ev:041031 ftp chmod:try rsh after setmod failed                //~v5evI~
//v5eu:041031 rsh support                                          //~v5euI~
//v5eb:041011 uproc2:parseredirect function for xedcmd             //~v5ebI~
//************************************************************* //~5825I~
#include <time.h>                                               //~5825I~
#include <stdio.h>                                              //~5825I~
#include <stdlib.h>                                             //~5825I~
#include <string.h>                                             //~5825I~
#include <stdarg.h>                                             //~5A10I~
#include <errno.h>                                              //~5A10I~
#include <fcntl.h>                                                 //~v59jI~
#ifdef UNX                                                         //~v5ewI~
	#include <unistd.h>                                            //~v5ewI~
	#include <termios.h>                                           //~v5kuI~
    #ifdef LNX                                                     //~v5mPI~
		#include <dlfcn.h>                                         //~v5mPI~
    #endif                                                         //~v5mPI~
#else                                                              //~v5g1I~
    #ifdef DOS                                                     //~v5kuR~
        #include <dos.h>                                           //~v5kuI~
    #endif                                                         //~v5kuI~
    #ifdef DPMI                                                    //~v5itR~
		#include <unistd.h>                                        //~v5itI~
		#include <termios.h>                                       //~v5kuI~
    #endif                                                         //~v5itI~
	#include <process.h>                                           //~v5g1I~
    #ifdef W32                                                     //~v5kuI~
		#include <windows.h>	         //v1.3 add                //~v5kuI~
		#include <tlhelp32.h>                                      //~v6T7I~
		#include <Psapi.h>                                         //~v6T7I~
    #endif                                                         //~v5kuI~
#endif                                                             //~v5ewR~
                                                                   //~v022I~
#include <ulib.h>                                               //~5825I~
#include <uque.h>                                                  //~v5euI~
#include <uerr.h>                                               //~5A10I~
#include <uproc.h>                                              //~5A10I~
#include <uproc2.h>                                                //~v5ebI~
#include <uparse.h>                                                //~v5ebI~
#include <ualloc.h>                                                //~v5ebI~
#include <ufile.h>                                                 //~v5euI~
#include <ufile2.h>                                                //~v5euI~
#include <ufile4.h>                                                //~v5euI~
#include <uftp.h>                                                  //~v5euI~
#include <ufemsg.h>                                                //~v5euI~
#include <utrace.h>                                                //~v5mPI~
#include <udos2.h>                                                 //~v6M0I~
#include <ustring.h>                                               //~v761I~
#include <uvio.h>                                                  //~v7a6I~
//*********************************************                    //~v064R~
//*********************************************                    //~v064R~
//**************************************************************** //~v50HI~
#ifdef FTPSUPP                                                     //~v5ewI~
    int uproc_redirectrewrite(ULONG Popt,char **Pprec,char *Pfnm); //~v5ewR~
    int uproc_rshlog(char **Ppstdo,char **Ppstde);                 //~v5ewI~
#endif                                                             //~v5ewR~
//***************************************************** ********** //~v5ebI~
//!uprocparseredirect                                              //~v5ebI~
//  drop redirect stdo/stde specification from cmd string          //~v5ebI~
//  flag: 1:stdout is append mode,2:stderr is appendmode,3:both append mode//~v5isR~
//************************************************************ *** //~v5ebI~
//int uprocparseredirect(char *Pcmd,char *Pstdofnm,char *Pstdefnm,int *Ppflag,int *Ppcmdlen)//~v5isR~
int uprocparseredirect(char *Pcmd,char *Pstdifnm,char *Pstdofnm,char *Pstdefnm,int *Ppflag,int *Ppcmdlen)//~v5isI~
{                                                                  //~v5ebI~
	PUPODELMTBL ppodt,ppodt0,ppodto;                               //~v5ebR~
	UCHAR *pc,*pc2,*pco,*pot;                                      //~v5ebR~
    int ii,rc=0,wordno,stdosw=0,stdesw=0,cmdlen,offs,appendsw,flag=0;//~v5ebR~
//***********************                                          //~v5ebI~
    *Pstdofnm=0;                                                   //~v5ebI~
    *Pstdefnm=0;                                                   //~v5ebI~
	if (Pstdifnm) //stdin parse required                           //~v5isI~
		*Pstdifnm=0;                                               //~v5isI~
    *Ppflag=0;                                                     //~v5ebI~
    *Ppcmdlen=cmdlen=(int)strlen(Pcmd);                            //~v5ewR~
    if (!strchr(Pcmd,'>'))                                         //~v5ebI~
    {                                                              //~v5isI~
      if (!Pstdifnm	//stdin parse required                         //~v5isI~
      ||  !strchr(Pcmd,'<'))                                       //~v5isI~
    	return 0;                                                  //~v5ebI~
    }                                                              //~v5isI~
  if (Pstdifnm) //stdin parse required                             //~v5isI~
	uparse2(Pcmd,&ppodt0,&pot,&wordno,UPARSE2SETCONTDLM2,"<>");    //~v5isI~
  else                                                             //~v5isI~
	uparse2(Pcmd,&ppodt0,&pot,&wordno,UPARSE2SETCONTDLM2,">");     //~v5ebR~
    for (ii=0,ppodt=ppodt0,pc=pot;ii<wordno;ii++,ppodt++,pc+=strlen(pc)+1)//~v5ebI~
    {                                                              //~v5ebI~
      if (ppodt->upodelm=='<')	//stdin                            //~v5isR~
      {                                                            //~v5isI~
	    pc2=pc+strlen(pc)+1;	//next opd                         //~v5isI~
	    if (!*pc2)		//no filename                              //~v5isI~
        {                                                          //~v5isI~
            rc=4;                                                  //~v5isI~
            break;                                                 //~v5isI~
        }                                                          //~v5isI~
        strcpy(Pstdifnm,pc2);                                      //~v5isI~
        offs=ppodt->upodelmoffs;                                   //~v5isR~
      }                                                            //~v5isI~
      else //not stdin                                             //~v5isI~
      {                                                            //~v5isI~
    	if (ppodt->upodelm!='>')                                   //~v5ebI~
        	continue;                                              //~v5ebI~
        pco=pc;                                                    //~v5ebM~
        ppodto=ppodt;                                              //~v5ebI~
        pc2=pc+strlen(pc)+1;                                       //~v5ebI~
    	if (ii+1<wordno && (ppodt+1)->upodelm=='>' && !*pc2)// ">>"//~v5ebI~
        {                                                          //~v5ebM~
	        ppodt++;                                               //~v5ebM~
    	    pc+=strlen(pc)+1;                                      //~v5ebR~
        	pc2=pc+1;                                              //~v5ebI~
        	ii++;                                                  //~v5ebM~
        	appendsw=1;                                            //~v5ebM~
        }                                                          //~v5ebM~
        else                                                       //~v5ebM~
        	appendsw=0;                                            //~v5ebM~
        if (!*pc2)		//no filename                              //~v5ebI~
        {                                                          //~v5ebI~
        	rc=4;                                                  //~v5ebI~
            break;                                                 //~v5ebI~
        }                                                          //~v5ebI~
        if (*pco=='2' && !*(pco+1)) // "2>"                        //~v5ebR~
        {                                                          //~v5ebI~
            if (stdesw)                                            //~v5ebI~
            {                                                      //~v5ebI~
                rc=4;                                              //~v5ebI~
                break;                                             //~v5ebI~
            }                                                      //~v5ebI~
            stdesw=1;                                              //~v5ebI~
            if (appendsw)                                          //~v5ebI~
    	        flag|=PRERC_STDEAPPEND;                            //~v5ebR~
            strcpy(Pstdefnm,pc2);                                  //~v5ebR~
            offs=(ppodto-1)->upodelmoffs;                          //~v5ebR~
        }                                                          //~v5ebI~
        else                                                       //~v5ebI~
        {                                                          //~v5ebI~
            if (stdosw)                                            //~v5ebI~
            {                                                      //~v5ebI~
                rc=4;                                              //~v5ebI~
                break;                                             //~v5ebI~
            }                                                      //~v5ebI~
            stdosw=1;                                              //~v5ebI~
            if (appendsw)                                          //~v5ebI~
    	        flag|=PRERC_STDOAPPEND;                            //~v5ebR~
            strcpy(Pstdofnm,pc2);                                  //~v5ebR~
            offs=ppodto->upodelmoffs;                              //~v5ebR~
        }                                                          //~v5ebI~
      }//not stdin                                                 //~v5isI~
        if (offs<cmdlen)                                           //~v5ebI~
        	cmdlen=offs;                                           //~v5ebI~
    }//for                                                         //~v5ebI~
    *Ppcmdlen=cmdlen;                                              //~v5ebI~
    *Ppflag=flag;                                                  //~v5ebI~
    ufree(ppodt0);                                                 //~v5ebR~
    return rc;                                                     //~v5ebI~
}//uprocparseredirect                                              //~v5ebI~
                                                                   //~v5euI~
#ifdef FTPSUPP                                                     //~v5euI~
                                                                   //~v5euI~
//*******************************************************************//~v5euI~
//*uproc_sh                                                        //~v5euI~
//*  issue rsh and get stdout/stderr output                        //~v5euI~
//*p1:option:append/conversion                                     //~v5euR~
//*p2:hostid on xehosts or hostname on /etc/hosts or ip addr       //~v5euI~
//*p3:optional username                                            //~v5euI~
//*p4:cmd string                                                   //~v5euI~
//*p5:optional stdout local filename                               //~v5euI~
//*p6:optional stderr local filename                               //~v5euI~
//*p7:optional stdout record pointer table                         //~v5euI~
//*p8:optional stdout record ctr                                   //~v5euI~
//*p9:optional stdout record pointer table                         //~v5euI~
//*p10:optional stdout record ctr                                  //~v5euI~
//*******************************************************************//~v5euI~
//int uproc_rsh(ULONG Popt,char *Pphost,char *Ppuser,char *Ppcmd,char *Ppfnmstdo,char *Ppfnmstde,//~v5evR~
int uproc_rsh(ULONG Popt,void *Pphost,char *Ppuser,char *Ppcmd,char *Ppfnmstdo,char *Ppfnmstde,//~v5evI~
			char ***Pppstdo,int *Ppstdoctr,char ***Pppstde,int *Ppstdectr)//~v5euI~
{                                                                  //~v5euI~
#define MAX_RSHCMDLEN 4096                                         //~v5euI~
    char tempfnmstdo[_MAX_PATH],tempfnmstde[_MAX_PATH];            //~v5euR~
    char cmdstr[3+1+16+1+MAX_RSHCMDLEN+3+_MAX_PATH+3+_MAX_PATH+16];//~v5euR~
    char *pfnmstdo,*pfnmstde,*phost=NULL,*puser,*perrmsg,**pstdo,**pstde;//~v5euR~//~v6h6R~
    PUFTPHOST puftph;                                              //~v5euI~
	int rc=0,sysopt,swtempso=0,swtempse=0,swredirect=0,cvopt,cvopt2;//~v5euR~
    int logoutsw;                                                  //~v5ewR~
//************************************                             //~v5euI~
	pfnmstdo=Ppfnmstdo;                                            //~v5euI~
	pfnmstde=Ppfnmstde;                                            //~v5euI~
	if (pfnmstdo && !*pfnmstdo)                                    //~v5euR~
    	pfnmstdo=0;                                                //~v5euR~
	if (pfnmstde && !*pfnmstde)                                    //~v5euR~
    	pfnmstde=0;                                                //~v5euR~
    if (!pfnmstdo)                                                 //~v5euI~
//		Popt &= ~UPROC_APPENDSO;	//append no meaning            //~v5euI~//~v6xiR~
  		Popt = (ULONG)(Popt & (UINT)(~UPROC_APPENDSO));	//append no meaning//~v6xiI~
    if (!pfnmstde)                                                 //~v5euI~
//  	Popt &= ~UPROC_APPENDSE;	//append no meaning            //~v5euI~//~v6xiR~
    	Popt = (ULONG)(Popt & (ULONG)(~UPROC_APPENDSE));	//append no meaning//~v6xiI~
//*edit cmd string                                                 //~v5euI~
    if (strlen(Ppcmd)>MAX_RSHCMDLEN)                               //~v5euI~
    {                                                              //~v5euI~
    	uerrmsg("too long rsh cmd string",0);                      //~v5euI~
    	return 8;                                                  //~v5euI~
    }                                                              //~v5euI~
//  phost=Pphost;                                                  //~v5evI~
  	if (Popt & UPROC_PUFTPH)                                       //~v5evI~
  		puftph=(PUFTPHOST)Pphost;                                  //~v5evI~
  	else                                                           //~v5evI~
    {                                                              //~v5evI~
    	puftph=0;                                                  //~v5evI~
		phost=(char *)Pphost;                                      //~v5evR~
    }                                                              //~v5evI~
    puser=Ppuser;	//may override UFTPH	definition             //~v5euI~
//  if (uftpisremote(Pphost,&puftph))	//hostname on ::xehosts    //~v5evR~
    if (puftph||uftpisremote(phost,&puftph))	//hostname on ::xehosts//~v5evI~
    {                                                              //~v5euI~
    	phost=puftph->UFTPHipad;                                   //~v5euI~
    	if (!Ppuser)                                               //~v5euI~
	        puser=puftph->UFTPHuser;                               //~v5euI~
    }                                                              //~v5euI~
//*chk conversion required                                         //~v5euI~
    cvopt=0;                                                       //~v5euI~
    if (!(cvopt=Popt & (UPROC_CVE2S|UPROC_CVS2E)))	//stdout sjis<-euc conv//~v5euR~
    {                                                              //~v5euI~
#if defined(AIX) || defined(W32)                                   //~v5euM~
	    if (puftph && puftph->UFTPHflag & UFTPHFEUC)               //~v5euI~
    		cvopt|=UPROC_CVE2S;	//stdout sjis<-euc conv            //~v5euI~
#endif                                                             //~v5euM~
#ifdef LNX                                                         //~v5euM~
	    if (puftph && puftph->UFTPHflag & UFTPHFSJIS)              //~v5euI~
    		cvopt|=UPROC_CVS2E;	//stdout sjis->euc conv            //~v5euI~
#endif                                                             //~v5euM~
	}                                                              //~v5euI~
  	logoutsw=(Popt & UPROC_RSHLOG);                                //~v5ewR~
//  if (Pppstdo||Pppstde||pfnmstdo||pfnmstde) //redirect required  //~v5ewR~
    if (Pppstdo||Pppstde||pfnmstdo||pfnmstde  //redirect required  //~v5ewI~
    ||  logoutsw)   //loging requested                             //~v5ewI~
    {                                                              //~v5euI~
    	swredirect=1;                                              //~v5euI~
        if (!pfnmstdo 				//no stdo redirect requested   //~v5euR~
		||  (Popt & UPROC_APPENDSO))//append from buff             //~v5euI~
        {                                                          //~v5euI~
            utempnam("","ursho_",tempfnmstdo);   // TEMP= or /tmp  //~v5euR~
            pfnmstdo=tempfnmstdo;                                  //~v5euI~
            swtempso=1;                                            //~v5euR~
        }                                                          //~v5euI~
        if (Popt & UPROC_APPENDSE) //buff is current output only   //~v5euR~
        {                                                          //~v5euI~
            utempnam("","urshe_",tempfnmstde);   // TEMP= or /tmp  //~v5euI~
            pfnmstde=tempfnmstde;                                  //~v5euI~
            swtempse=1;                                            //~v5euI~
        }                                                          //~v5euI~
        else                                                       //~v5euI~
	        if (!pfnmstde)                                         //~v5euR~
	            pfnmstde="&1";                                     //~v5euR~
      if (puser)                                                   //~v5euI~
		sprintf(cmdstr,"rsh %s -l %s -n %s >%s 2>%s",phost,puser,Ppcmd,pfnmstdo,pfnmstde);//~v5ewR~
      else                                                         //~v5euI~
		sprintf(cmdstr,"rsh %s -n %s >%s 2>%s",phost,Ppcmd,pfnmstdo,pfnmstde);//~v5ewR~
    	if (!strcmp(pfnmstde,"&1"))                                //~v5euI~
    		pfnmstde=0;		//0 for "&1" to skip stderr get        //~v5euI~
    }                                                              //~v5euI~
    else                                                           //~v5euI~
      if (puser)                                                   //~v5euI~
		sprintf(cmdstr,"rsh %s -l %s -n %s",phost,puser,Ppcmd);    //~v5ewR~
      else                                                         //~v5euI~
		sprintf(cmdstr,"rsh %s -n %s",phost,Ppcmd);                //~v5ewR~
//printf("cmdstr=%s\n",cmdstr);                                    //~v5euR~
//*issue cmd                                                       //~v5euI~
//  sysopt=(Popt & ~(UPROC_CVS2E|UPROC_CVE2S));                    //~v5euI~//~v6xiR~
    sysopt=(int)(Popt & (ULONG)(~(UPROC_CVS2E|UPROC_CVE2S)));      //~v6xiI~
    cvopt2=sysopt|cvopt;                                           //~v5euI~
    sysopt|=UPROC_NOOKMSG|UPROC_KEEPTEMP|cvopt;                    //~v5euR~
    IFDEF_WINCON(sysopt|=UPROC_KEEPMODE);	//keep consolemode     //~v5maI~
    perrmsg=ugeterrmsg();	//clear errmsg                         //~v5euI~
    uftplog(FTPLOG_REQ|FTPLOG_ADDLF,cmdstr);                       //~v5ewR~
    rc=usystem2(sysopt,cmdstr);                                    //~v5euI~
    useterrmsg(perrmsg);	//clear errmsg                         //~v5euI~
//*output handling                                                 //~v5euI~
	if (swredirect)                                                //~v5euI~
    {                                                              //~v5euI~
        if ((rc=uproc_redirectoutchk(sysopt,cmdstr,&pstdo,&pstde,Ppstdoctr,Ppstdectr,pfnmstdo,pfnmstde))>1)//~v5ewR~
			return rc;		//rc=1:stderr exist                    //~v5ewI~
        if (Ppfnmstdo && *Ppfnmstdo)                               //~v5euR~
//	        uproc_redirectrewrite(cvopt2 & ~UPROC_APPENDSE,pstdo,Ppfnmstdo);//~v5euR~//~v6xiR~
  	        uproc_redirectrewrite((ULONG)(cvopt2 & ~UPROC_APPENDSE),pstdo,Ppfnmstdo);//~v6xiI~
        if (Ppfnmstde && *Ppfnmstde)                               //~v5euR~
//   	   	uproc_redirectrewrite(cvopt2 & ~UPROC_APPENDSO,pstde,Ppfnmstde);//~v5euR~//~v6xiR~
     	   	uproc_redirectrewrite((ULONG)(cvopt2 & ~UPROC_APPENDSO),pstde,Ppfnmstde);//~v6xiI~
//delete temp file                                                 //~v5euI~
	    if (swtempso)	//                                         //~v5euR~
#ifdef UNX                                                         //~v5euI~
    		unlink(tempfnmstdo);        //del tempfile             //~v5euR~
#else                                                              //~v5euI~
    		uremovenomsg(tempfnmstdo);        //del tempfile       //~v5euR~
#endif                                                             //~v5euI~
	    if (swtempse)	//                                         //~v5euI~
#ifdef UNX                                                         //~v5euI~
    		unlink(tempfnmstde);        //del tempfile             //~v5euR~
#else                                                              //~v5euI~
    		uremovenomsg(tempfnmstde);        //del tempfile       //~v5euR~
#endif                                                             //~v5euI~
    	if (logoutsw)   //loging requested                         //~v5ewI~
        	uproc_rshlog(pstdo,pstde);                             //~v5ewI~
		if (Pppstdo)                                               //~v5euR~
        	*Pppstdo=pstdo;                                        //~v5euI~
        else                                                       //~v5euI~
            ufree(pstdo);                                          //~v5euI~
		if (Pppstde)                                               //~v5euR~
        	*Pppstde=pstde;                                        //~v5euI~
        else                                                       //~v5euI~
            ufree(pstde);                                          //~v5euI~
    }//redirect or buff out parm                                   //~v5euI~
    return rc;                                                     //~v5euI~
}//uproc_rsh                                                       //~v5euI~
//*******************************************************************//~v5euI~
int uproc_redirectrewrite(ULONG Popt,char **Pprec,char *Pfnm)      //~v5euI~
{                                                                  //~v5euI~
	FILE *fh;                                                      //~v5euI~
    int appendsw,cvsw;                                             //~v5euR~
    char *openopt,**pprec;                                         //~v5euR~
//************************************                             //~v5euI~
    if (!*Pprec)                                                   //~v5euI~
    	return 0;                                                  //~v5euI~
    appendsw=(Popt & (UPROC_APPENDSO|UPROC_APPENDSE));             //~v5euI~
    cvsw=(Popt & (UPROC_CVE2S|UPROC_CVS2E));	//rewrite by conversion//~v5euI~
    if (appendsw)                                                  //~v5euI~
    	openopt="a";                                               //~v5euI~
    else                                                           //~v5euI~
    	if (cvsw)                                                  //~v5euI~
	    	openopt="w";                                           //~v5euI~
        else                                                       //~v5euI~
        	return 0;	//no reason to rewrite                     //~v5euI~
    fh=fopen(Pfnm,openopt);                                        //~v5euR~
    if (!fh)                                                       //~v5euI~
		return ufileapierr("open",Pfnm,errno);                     //~v5euI~
    for (pprec=Pprec;*pprec;pprec++)                               //~v5euI~
    	fprintf(fh,"%s\n",*pprec);                                 //~v5euI~
    fclose(fh);                                                    //~v5euI~
    return 1;                                                      //~v5euR~
}//uproc_redirectrewrite                                           //~v5euI~
                                                                   //~v5euI~
//*******************************************************************//~v5ewI~
//*rsh output logging                                              //~v5ewI~
//*ret:record count                                                //~v5ewI~
//*******************************************************************//~v5ewI~
int uproc_rshlog(char **Ppstdo,char **Ppstde)                      //~v5ewI~
{                                                                  //~v5ewI~
    char **pprec;                                                  //~v5ewI~
    int logopt,rc=0;                                               //~v5ewR~
//************************************                             //~v5ewI~
	logopt=FTPLOG_RESP|FTPLOG_ADDLF;                               //~v5ewI~
    for (pprec=Ppstdo;*pprec;pprec++)                              //~v5ewI~
    {                                                              //~v5ewI~
        uftplog(logopt,*pprec);                                    //~v5ewI~
	    logopt&=~FTPLOG_RESP;                                      //~v5ewI~
        rc++;                                                      //~v5ewI~
    }                                                              //~v5ewI~
    for (pprec=Ppstde;*pprec;pprec++)                              //~v5ewI~
    {                                                              //~v5ewI~
        uftplog(logopt,*pprec);                                    //~v5ewI~
        rc++;                                                      //~v5ewI~
    }                                                              //~v5ewI~
    return rc;                                                     //~v5ewI~
}//uproc_rshlog                                                    //~v5ewI~
                                                                   //~v5ewI~
#endif	//FTPSUPP                                                  //~v5euI~
//#ifndef DOS                                                      //~v5itR~
//*********************************************************************//~v5g1I~
//* get current process id                                         //~v5g1I~
//*********************************************************************//~v5g1I~
ULONG ugetpid(void)                                                //~v5g1I~
{                                                                  //~v5g1I~
static ULONG Spid=0;                                               //~v5g1I~
//******************************                                   //~v5g1I~
    if (Spid)                                                      //~v5g1I~
        return Spid;                                               //~v5g1I~
#ifdef W32                                                         //~v5g1R~
	Spid=_getpid();                                                //~v5g1R~
#else                                                              //~v5g1I~
	Spid=(ULONG)getpid();                                          //~v5g1R~
#endif                                                             //~v5g1I~
	return Spid;                                                   //~v5g1R~
}//ugetpid                                                         //~v5g1I~
//#endif                                                           //~v5itR~
//*********************************************************************//~v5kuI~
//* get current process id                                         //~v5kuI~
//*********************************************************************//~v5kuI~
int uprocredirectchk(int Pfileno)                                  //~v5kuI~
{                                                                  //~v5kuI~
	int redirectsw=0;                                              //~v5kuR~
#ifdef W32                                                         //~v5kuI~
    CONSOLE_SCREEN_BUFFER_INFO csbi;                               //~v5kuI~
	void *handle;                                                  //~v5kuI~
#endif                                                             //~v5kuI~
#if defined(UNX)||defined(DPMI)                                    //~v5kuI~
    struct termios otty;                                           //~v5kuI~
#endif                                                             //~v5kuI~
#ifdef OS2                                                         //~v5kuR~
    char *mode;                                                    //~v5kuI~
#endif                                                             //~v5kuI~
#ifdef DOSDOS                                                      //~v5kuI~
	int dx;                                                        //~v5kuI~
    union   REGS    reg;                                           //~v5kuI~
#define ISCIN 0x01                                                 //~v5kuI~
#define ISCOT 0x02                                                 //~v5kuI~
#define ISDEV 0x80                                                 //~v5kuI~
#endif                                                             //~v5kuI~
//******************************                                   //~v5kuI~
#ifdef W32                                                         //~v5kuI~
	switch(Pfileno)                                                //~v5kuI~
    {                                                              //~v5kuI~
    case 0:                                                        //~v5kuI~
    	handle=GetStdHandle(STD_INPUT_HANDLE);                     //~v5kuI~
    	break;                                                     //~v5kuI~
    case 1:                                                        //~v5kuI~
    	handle=GetStdHandle(STD_OUTPUT_HANDLE);                    //~v5kuI~
    	break;                                                     //~v5kuI~
    case 2:                                                        //~v5kuI~
    	handle=GetStdHandle(STD_ERROR_HANDLE);                     //~v5kuI~
    	break;                                                     //~v5kuI~
    default:                                                       //~v5kuI~
    	return -1;                                                 //~v5kuI~
    }                                                              //~v5kuI~
    redirectsw=GetConsoleScreenBufferInfo(handle,&csbi)==0;        //~v5kuR~
#endif                                                             //~v5kuI~
#if defined(UNX)||defined(DPMI)                                    //~v5kuI~
    redirectsw=tcgetattr(Pfileno,&otty)==-1;                       //~v5kuR~
#endif                                                             //~v5kuI~
#ifdef OS2                                                         //~v5kuI~
	switch(Pfileno)                                                //~v5kuI~
    {                                                              //~v5kuI~
    case 0:                                                        //~v5kuI~
    	mode="w";                                                  //~v5kuI~
    	break;                                                     //~v5kuI~
    case 1:                                                        //~v5kuI~
    	mode="r";                                                  //~v5kuI~
    	break;                                                     //~v5kuI~
    case 2:                                                        //~v5kuI~
    	mode="r";                                                  //~v5kuI~
    	break;                                                     //~v5kuI~
    default:                                                       //~v5kuI~
    	return -1;                                                 //~v5kuI~
    }                                                              //~v5kuI~
    redirectsw=fdopen(Pfileno,mode)==0;                            //~v5kuI~
#endif                                                             //~v5kuI~
#ifdef DOSDOS                                                      //~v5kuR~
    reg.h.ah=0x44;                  //ioctl                        //~v5kuI~
    reg.h.al=0x00;                  //get dev info                 //~v5kuI~
    reg.x.bx=Pfileno;               //fileno                       //~v5kuI~
    intdos(&reg,&reg);              //int 21                       //~v5kuI~
    dx=reg.x.dx;                    //dev info                     //~v5kuI~
//  fprintf(stderr,"fileno=%d,dx=%x\n",Pfileno,dx);                //~v5kuR~
	switch(Pfileno)                                                //~v5kuI~
    {                                                              //~v5kuI~
    case 0:                                                        //~v5kuI~
	  	redirectsw=!( (dx & ISDEV) && (dx & ISCIN) );              //~v5kuR~
    	break;                                                     //~v5kuI~
    case 1:                                                        //~v5kuI~
	  	redirectsw=!( (dx & ISDEV) && (dx & ISCOT) );              //~v5kuR~
    	break;                                                     //~v5kuI~
    default:                                                       //~v5kuI~
    	return -1;                                                 //~v5kuI~
    }                                                              //~v5kuI~
#endif                                                             //~v5kuI~
	return redirectsw;                                             //~v5kuI~
}//uprocredirectchk                                                //~v5kuI~
//#ifdef W32                                                       //~v5mPR~
#ifdef WCSUPP                                                      //~v5mPI~
//*********************************************************************//~v6M0I~
//* accept path, dllname is optional                               //~v6M0I~
//*********************************************************************//~v6M0I~
int uproc_loaddllpath(int Popt,char *Ppath,char *Pdllname,char *Pversion,ULPTR *Pphandle)//~v6M0M~
{                                                                  //~v6M0M~
    int rc,opt,rc2=0;                                              //~v6M0R~
    char dllname[_MAX_PATH*2],*pc;                                 //~v6M0M~
//********************                                             //~v6M0M~
	if (Pdllname)                                                  //~v6M0I~
    {                                                              //~v6M0I~
    	rc=uproc_loaddll(Popt,Pdllname,Pversion,Pphandle);         //~v6M0I~
    	if (!rc)                                                   //~v6M0I~
        	return 0;                                              //~v6M0I~
		sprintf(dllname,"%s%c%s",Ppath,DIR_SEPC,Pdllname);         //~v6M0I~
        rc2=rc;                                                    //~v6M0I~
    }                                                              //~v6M0I~
    else                                                           //~v6M0I~
    	strcpy(dllname,Ppath);                                     //~v6M0I~
    pc=strchr(dllname,'.');                                        //~v6M0I~
#ifdef W32                                                         //~v6M0I~
	if (Pversion)                                                  //~v6M0I~
    {                                                              //~v6M0I~
    	if (pc)                                                    //~v6M0I~
        {                                                          //~v6M0I~
			strcpy(pc+strlen(Pversion),pc);                        //~v6M0I~
            memcpy(pc,Pversion,strlen(Pversion));                  //~v6M0I~
        }                                                          //~v6M0I~
        else                                                       //~v6M0I~
        	strcat(dllname,Pversion);                              //~v6M0I~
    }                                                              //~v6M0I~
    if (!pc)                                                       //~v6M0I~
        strcat(dllname,".dll");                                    //~v6M0M~
#else                                                              //~v6M0M~
    if (!pc)                                                       //~v6M0I~
    {                                                              //~v6M0I~
        strcat(dllname,".so");                                     //~v6M0M~
		if (Pversion)                                              //~v6M0I~
			sprintf(dllname+strlen(dllname),".%s",Pversion);       //~v6M0I~
    }                                                              //~v6M0I~
#endif                                                             //~v6M0M~
	opt=Popt|UPLD_ALTPATH;//  0x04         //LoadLibraryEx with LOAD_WITH_ALTERED_SEARCH_PATH//~v6M0I~
#ifdef LNX                                                         //~v6M0I~
//    pc=strrchr(dllname,DIR_SEPC);                                  //~v6M0I~//~v6M3R~
//    if (pc)                                                        //~v6M0I~//~v6M3R~
//    {                                                              //~v6M0I~//~v6M3R~
//        *pc=0;                                                     //~v6M0I~//~v6M3R~
//        udos_setenv(UDSE_PREPEND,"LD_LIBRARY_PATH",dllname);       //~v6M0I~//~v6M3R~
////      if (Popt & UPLD_SETICUDATAENV)                             //~v6M2R~//~v6M3R~
////          udos_setenv(UDSE_PREPEND,"ICU_DATA",newenv);           //~v6M2R~//~v6M3R~
////      strcpy(dllname,pc);                                        //~v6M0I~//~v6M2R~//~v6M3R~
//        strcpy(dllname,pc+1);                                      //~v6M2I~//~v6M3R~
//    }                                                              //~v6M0I~//~v6M3R~
#endif                                                             //~v6M0I~
    rc=uproc_loaddll(opt,dllname,0,Pphandle);                      //~v6M0R~
    if (!rc) //success by path                                     //~v6M0I~
//  	if (rc2)	//1st loaddll failed                           //~v6M0I~//~v6M2R~
    	if (rc2	//1st loaddll failed                               //~v6M2I~
        ||  (Popt & UPLD_DELEMSG))        //ugeterrmsg to delete previous uerrmsg//~v6M2I~
        {                                                          //~v6M0I~
//      	uerrmsg(" retry by %s was scceeded",0,                 //~v6M0I~//~v6T6R~
//      	uerrmsgcat(" retry by %s was scceeded",0,              //~v6T6I~//~v6T7R~
        	uerrmsg(" retry by %s was scceeded",0,   //written to error.pid//~v6T7I~
            		dllname);	//to stdout                        //~v6M0I~
//          ugeterrmsg();	//clear errmsg on hdr line of xe       //~v6M0I~//~v6T6R~
        }                                                          //~v6M0I~
    UTRACEP("%s:rc=%d,path=%s,dll=%s,version=%s,dllname=%s\n",UTT,rc,Ppath,Pdllname,Pversion,dllname);//~v6M0I~
    return rc;                                                     //~v6M0M~
}//uproc_loaddllpath                                               //~v6M0M~
//*************************************************************************//~v5mPM~
//*DLL load                                                        //~v5mPM~
//*omit extension of dllname                                       //~v6M0I~
//*************************************************************************//~v5mPM~
//int uproc_loaddll(int Popt,char *Pdllname,char *Pversion,ULONG *Pphandle)//~v5mPM~//~v6hhR~
int uproc_loaddll(int Popt,char *Pdllname,char *Pversion,ULPTR *Pphandle)//~v6hhI~
{                                                                  //~v5mPM~
#ifdef W32                                                         //~v5mPI~
	HINSTANCE      hInstLib ;                                      //~v5mPM~
    int   flag;                                                    //~v6M0I~
#else                                                              //~v5mPI~
	void *hInstLib;                                                //~v5mPI~
    int   mode;                                                    //~v5mPI~
#endif                                                             //~v5mPI~
    int rc;                                                        //~v5mPM~
//  char dllname[256],*pdllname;                                   //~v5mPM~//~v6M0R~
    char dllname[_MAX_PATH*2],*pdllname,*pc;                       //~v6M0R~
#ifdef W32                                                         //~v6M0I~
    int pos;                                                       //~v6M0I~
#endif                                                             //~v6M0I~
//********************                                             //~v5mPM~
	UTRACEP("%s:opt=0x%x,dllname=%s,version=%s\n",UTT,Popt,Pdllname,Pversion);//~v761I~
	if (Pversion)                                                  //~v5mPM~
    {                                                              //~v5mPM~
    	pc=strchr(Pdllname,'.');                                   //~v6M0I~
#ifdef W32                                                         //~v6M0I~
      if (pc)              //insert version before extension       //~v6M0I~
      {                                                            //~v6M0I~
        pos=PTRDIFF(pc,Pdllname);                                  //~v6M0I~
        strcpy(dllname,Pdllname);                                  //~v6M0I~
		strcpy(dllname+pos,Pversion);                              //~v6M0I~
        strcat(dllname,pc);                                        //~v6M0I~
      }                                                            //~v6M0I~
      else                                                         //~v6M0I~
		sprintf(dllname,"%s%s",Pdllname,Pversion);                 //~v5mPR~
#else                                                              //~v6M0I~
      if (pc)              //insert version before extension       //~v6M0I~
        sprintf(dllname,"%s.%s",Pdllname,Pversion);                //~v6M0I~
      else                                                         //~v6M0I~
        sprintf(dllname,"%s.so.%s",Pdllname,Pversion);             //~v6M0I~
#endif                                                             //~v6M0I~
        pdllname=dllname;                                          //~v5mPM~
    }                                                              //~v5mPM~
    else                                                           //~v5mPM~
    	pdllname=Pdllname;                                         //~v5mPM~
#ifdef W32                                                         //~v5mPI~
//#ifdef WXE                                                       //~v5mPR~
//    hInstLib = AfxLoadLibrary(pdllname) ;                        //~v5mPR~
//#else                                                            //~v5mPR~
  if (Popt & UPLD_ALTPATH)         //LoadLibraryEx with LOAD_WITH_ALTERED_SEARCH_PATH//~v6M0I~
  {                                                                //~v6M0I~
    flag=LOAD_WITH_ALTERED_SEARCH_PATH;                //~7809I~   //~v6M0I~
    hInstLib = LoadLibraryEx(pdllname,NULL,flag) ;                 //~v6M0I~
  }                                                                //~v6M0I~
  else                                                             //~v6M0I~
    hInstLib = LoadLibrary(pdllname) ;                             //~v5mPM~
//#endif                                                           //~v5mPR~
#else       //LNX                                                  //~v5mPI~
  if (Popt & UPLD_NOW)			//         //RTLD_NOW              //~v5mPI~
	mode=RTLD_NOW;                                                 //~v5mPI~
  else                                                             //~v5mPI~
	mode=RTLD_LAZY;                                                //~v5mPI~
    hInstLib=dlopen(pdllname,mode) ;                               //~v5mPI~
    UTRACEP("%s:dlopen hInstLib=%p,mode=%x,dllname=%s,LD_LIBRARY_PATH=%s\n",UTT,hInstLib,mode,pdllname,getenv("LD_LIBRARY_PATH"));//~v6M2I~//~v761R~
#endif                                                             //~v5mPI~
//  *Pphandle=(ULONG)hInstLib;                                     //~v5mPM~//~v6hhR~
    *Pphandle=(ULPTR)hInstLib;                                     //~v6hhI~
	if (hInstLib)                                                  //~v5mPM~
        rc=0;                                                      //~v5mPM~
    else                                                           //~v5mPM~
    {                                                              //~v5mPM~
#ifdef W32                                                         //~v5mPI~
    	rc=GetLastError();                                         //~v5mPM~
//  	uerrmsg("LoadLibrary failed for %s,lasterr=%d",0,          //~v5mPM~//~v6T6R~
//  	uerrmsgcat("LoadLibrary(%s) failed,lasterr=%d, adjust ::xeebc.map if not use ICU.",0,//~v6T6R~//~v6T7R~
//  	uerrmsg("LoadLibrary(%s) failed,lasterr=%d, adjust ::xeebc.map if not use ICU.",0,//~v6T7I~//+v7biR~
    	uerrmsg("LoadLibrary(%s) failed,lasterr=%d, check xeebc.map for using ICU.",0,//+v7biI~
        		pdllname,rc);                                      //~v5mPM~
#else       //LNX                                                  //~v5mPI~
		rc=errno;                                                  //~v5mPI~
//        uerrmsg("LoadLibrary(dlopen) failed for %s by errno=%d(%s)",0,//~v5mPI~//~v6fiR~
//                pdllname,rc,dlerror());                            //~v5mPI~//~v6fiR~
//        uerrmsg("LoadLibrary(dlopen) failed for %s by errno=%d",0,//~v6fiR~
//                pdllname,rc);                                    //~v6fiR~
//      uerrmsg("LoadLibrary(dlopen) failed for %s(check LD_LIBRARY_PATH). ",0,//~v6fiR~//~v6T6R~
//      uerrmsgcat("dlopen(%s) failed(chk LD_LIBRARY_PATH), or adjust xeebc.map if no use ICU.",0,//~v6T6R~//~v6T7R~
//      uerrmsg("dlopen(%s) failed(chk LD_LIBRARY_PATH), or adjust xeebc.map if no use ICU.",0,//~v6T7I~//+v7biR~
        uerrmsg("dlopen(%s) failed(chk LD_LIBRARY_PATH), check xeebc.map for unsing ICU.",0,//+v7biI~
                pdllname);                                         //~v6fiI~
        if (!rc)                                                   //~v6fhI~
        	rc=ENOENT;                                             //~v6fhI~
#endif                                                             //~v5mPI~
    }                                                              //~v5mPM~
    UTRACEP("%s:Popt=%x,rc=%d,dll=%s,version=%s,dllname=%s\n",UTT,Popt,rc,Pdllname,Pversion,pdllname);//~v6M0R~
    return rc;                                                     //~v5mPM~
}//uproc_loaddll                                                   //~v5mPM~
//*************************************************************************//~v5mPM~
//*find DLL proc                                                   //~v5mPM~
//*************************************************************************//~v5mPM~
//int uproc_getdllproc(int Popt,ULONG Phandle,char *Pprocname,char *Pprocver,ULONG *Ppprocaddr)//~v5mPM~//~v6hhR~
int uproc_getdllproc(int Popt,ULPTR Phandle,char *Pprocname,char *Pprocver,ULPTR *Ppprocaddr)//~v6hhI~
{                                                                  //~v5mPM~
#ifdef W32                                                         //~v5mPI~
	HINSTANCE      hInstLib ;                                      //~v5mPM~
#else                                                              //~v5mPI~
	void *hInstLib ;                                               //~v5mPI~
#endif                                                             //~v5mPI~
    void *procaddr;                                                //~v5mPM~
    char procver[256],*pproc;                                      //~v5mPM~
    int rc;                                                        //~v5mPM~
//********************                                             //~v5mPM~
#ifdef W32                                                         //~v5mPI~
	hInstLib=(HINSTANCE)Phandle;                                   //~v5mPM~
#else                                                              //~v5mPI~
	hInstLib=(void*)Phandle;                                       //~v5mPI~
#endif                                                             //~v5mPI~
    if (Pprocver)                                                  //~v5mPM~
    {                                                              //~v5mPM~
    	sprintf(procver,"%s%s",Pprocname,Pprocver);                //~v5mPM~
        pproc=procver;                                             //~v5mPM~
    }                                                              //~v5mPM~
    else                                                           //~v5mPM~
    	pproc=Pprocname;                                           //~v5mPM~
#ifdef W32                                                         //~v5mPI~
    procaddr=GetProcAddress(hInstLib,pproc) ;                      //~v5mPM~
#else                                                              //~v5mPI~
    procaddr=dlsym(hInstLib,pproc);                                //~v5mPI~
#endif                                                             //~v5mPI~
    UTRACEP("uproc_getdllproc proc=%s,add=%p\n",pproc,procaddr);   //~v5mPI~
    if (!procaddr)                                                 //~v5mPM~
    {                                                              //~v5mPM~
#ifdef W32                                                         //~v5mPI~
    	rc=GetLastError();                                         //~v5mPM~
      if (!(Popt & UPGPAO_NOMSG))                                  //~v6g4I~
    	uerrmsg("GetProcAddress failed for %s,lasterr=%d",0,       //~v5mPM~
        		pproc,rc);                                         //~v5mPM~
#else                                                              //~v5mPI~
    	rc=errno;                                                  //~v5mPI~
//        uerrmsg("GetProcAddress(dlsym) failed for %s by errno=%d(%s)",0,//~v5mPI~//~v6fiR~
//                pproc,rc,dlerror());                               //~v5mPI~//~v6fiR~
      if (!(Popt & UPGPAO_NOMSG))                                  //~v6g4I~
        uerrmsg("GetProcAddress(dlsym) failed for %s by errno=%d",0,//~v6fiI~
                pproc,rc);                                         //~v6fiI~
        if (!rc)                                                   //~v6fiI~
        	rc=ENOENT;                                             //~v6fiI~
#endif                                                             //~v5mPI~
    }                                                              //~v5mPM~
    else                                                           //~v5mPM~
    {                                                              //~v5mPM~
    	rc=0;                                                      //~v5mPM~
    }                                                              //~v5mPM~
//  *Ppprocaddr=(ULONG)procaddr;                                   //~v5mPM~//~v6hhR~
    *Ppprocaddr=(ULPTR)procaddr;                                   //~v6hhI~
    return rc;                                                     //~v5mPM~
}//uproc_getdllproc                                                //~v5mPM~
//*************************************************************************//~v5mPM~
//*free DLL handle                                                 //~v5mPM~
//*************************************************************************//~v5mPM~
//int uproc_freedll(int Popt,ULONG Phandle)                          //~v5mPM~//~v6hhR~
int uproc_freedll(int Popt,ULPTR Phandle)                          //~v6hhI~
{                                                                  //~v5mPM~
#ifdef W32                                                         //~v5mPI~
	HINSTANCE      hInstLib ;                                      //~v5mPM~
#else                                                              //~v5mPI~
	void *hInstLib ;                                               //~v5mPI~
#endif                                                             //~v5mPI~
    int rc;                                                        //~v5mPM~
//********************                                             //~v5mPM~
#ifdef W32                                                         //~v5mPI~
	hInstLib=(HINSTANCE)Phandle;                                   //~v5mPM~
#else                                                              //~v5mPI~
	hInstLib=(void*)Phandle;                                       //~v5mPI~
#endif                                                             //~v5mPI~
#ifdef W32                                                         //~v5mPI~
    if(!FreeLibrary( hInstLib ) )                                  //~v5mPR~
    	rc=GetLastError();                                         //~v5mPR~
    else                                                           //~v5mPI~
    	rc=0;                                                      //~v5mPI~
#else                                                              //~v5mPI~
    if (dlclose(hInstLib))                                         //~v5mPR~
    	rc=errno;                                                  //~v5mPI~
    else                                                           //~v5mPI~
    	rc=0;                                                      //~v5mPI~
#endif                                                             //~v5mPI~
    return rc;                                                     //~v5mPM~
}//uproc_freedll                                                   //~v5mPM~
//*************************************************************************//~v5mPM~
//*load dll if handle is null, then get proc addr                  //~v5mPM~
//*Pdllname:not required if handle specified                       //~v5mPM~
//*Pphandle:set 0 if not yet issued loaddll                        //~v5mPM~
//*************************************************************************//~v5mPM~
//int uproc_getprocaddr(int Popt,char *Pdllname,char *Pdllversion,char *Pprocname,char *Pprocversion,ULONG *Pphandle,ULONG *Ppprocaddr)//~v5mPM~//~v6hhR~
int uproc_getprocaddr(int Popt,char *Pdllname,char *Pdllversion,char *Pprocname,char *Pprocversion,ULPTR *Pphandle,ULPTR *Ppprocaddr)//~v6hhI~
{                                                                  //~v5mPM~
//	ULONG handle;                                                  //~v5mPM~//~v6hhR~
	ULPTR handle;                                                  //~v6hhI~
    int rc=0;                                                      //~v5mPM~
    int opt=0;                                                     //~v5mPI~
//********************                                             //~v5mPM~
    UTRACEP("%s:dllname=%s,dllversion=%s,procversion=%s,handle=%p\n",UTT,Pdllname,Pdllversion,Pprocversion,Pphandle);//~v761I~
	if (!Pphandle || !(handle=*Pphandle))	//1st time             //~v5mPM~
    {                                                              //~v5mPI~
//  	rc=uproc_loaddll(0,Pdllname,Pdllversion,&handle);          //~v5mPR~
		if (Popt & UPGPAO_NOW)       //RTLD_NOW                    //~v5mPI~
			opt|=UPLD_NOW;			//         //RTLD_NOW          //~v5mPI~
    	rc=uproc_loaddll(opt,Pdllname,Pdllversion,&handle);        //~v5mPI~
    }                                                              //~v5mPI~
    if (!rc)                                                       //~v5mPM~
    {                                                              //~v5mPM~
//    	rc=uproc_getdllproc(0,handle,Pprocname,Pprocversion,Ppprocaddr);//~v5mPM~//~v6g4R~
      	rc=uproc_getdllproc(Popt,handle,Pprocname,Pprocversion,Ppprocaddr);//~v6g4I~
        if (Popt & UPGPAO_FREE)        //free handle               //~v5mPM~
        {                                                          //~v5mPM~
            rc+=uproc_freedll(0,handle);                           //~v5mPM~
            handle=0;                                              //~v5mPM~
        }                                                          //~v5mPM~
    }                                                              //~v5mPM~
    if (Pphandle)                                                  //~v5mPM~
    	*Pphandle=handle;                                          //~v5mPM~
    UTRACEP("%s:rc=%d,handle=%p\n",UTT,rc,handle);                 //~v761I~
    return rc;                                                     //~v5mPM~
}//uproc_getprocaddr                                               //~v5mPM~
#endif                                                             //~v5mPI~
#ifdef W32                                                         //~v761R~
//*****************************************************************//~v761R~
int getProcessName(int Ppid,char *Pfname,int Psz)                  //~v761R~
{                                                                  //~v761R~
    UTRACEP("%s:Ppid=%d\n",UTT,Ppid);                              //~v761I~
    *Pfname=0;                                                     //~v761I~
    HANDLE h = NULL;                                               //~v761R~
    *Pfname=0;                                                     //~v761R~
    int e = 0;                                                     //~v761R~
    h = OpenProcess                                                //~v761R~
    (                                                              //~v761R~
        PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,               //~v761R~
        FALSE,                                                     //~v761R~
        Ppid                                                       //~v761R~
    );                                                             //~v761R~
    if (h)                                                         //~v761R~
    {                                                              //~v761R~
//      if (GetModuleFileNameEx(h, NULL, fname, sz) == 0)          //~v761R~
		if (GetProcessImageFileName(h,Pfname,Psz)==0)              //~v761R~
            e = GetLastError();                                    //~v761R~
        CloseHandle(h);                                            //~v761R~
    }                                                              //~v761R~
    else                                                           //~v761R~
    {                                                              //~v761R~
        e = GetLastError();                                        //~v761R~
    }                                                              //~v761R~
    UTRACEP("%s:Ppid=%d,error=%d,name=%s\n",UTT,Ppid,e,Pfname);    //~v761I~
    return (e);                                                    //~v761R~
}                                                                  //~v761R~
//*****************************************************************//~v761R~
int getParentPID(int Ppid)                                         //~v761R~
{                                                                  //~v761R~
    HANDLE h = NULL;                                               //~v761R~
    PROCESSENTRY32 pe = { 0 };                                     //~v761R~
    DWORD ppid = 0;                                                //~v761R~
    UTRACEP("%s:Ppid=%d\n",UTT,Ppid);                              //~v761R~
    pe.dwSize = sizeof(PROCESSENTRY32);                            //~v761R~
    h = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);           //~v761R~
    char fnm[MAX_PATH];                                            //~v761R~
    if( Process32First(h, &pe))                                    //~v761R~
    {                                                              //~v761R~
        do                                                         //~v761R~
        {                                                          //~v761R~
        	UTRACEP("%s:Ppid=%d,t32ProcessID=%d,parentPID=%d,name=%s\n",UTT,Ppid,pe.th32ProcessID,pe.th32ParentProcessID,(getProcessName(pe.th32ProcessID,fnm,(int)sizeof(fnm)),fnm));//~v761R~
            if (pe.th32ProcessID == (DWORD)Ppid)                   //~v761R~
            {                                                      //~v761R~
                ppid = pe.th32ParentProcessID;                     //~v761R~
                break;                                             //~v761R~
            }                                                      //~v761R~
        } while( Process32Next(h, &pe));                           //~v761R~
    }                                                              //~v761R~
    CloseHandle(h);                                                //~v761R~
    UTRACEP("%s:return=%d,for %d,name=%s\n",UTT,ppid,Ppid,fnm);                //~v761R~//~v79NR~
    return (ppid);                                                 //~v761R~
}                                                                  //~v761R~
#ifdef WINCON                                                      //~v7biR~
//*****************************************************************//~v761I~
//*chk console is conhost or windowsTermminal                      //~v761I~
//*0:unknown,1:conhost,2:Terminal                                  //~v761I~
//*!! WindowsTerninal not On path for 1st window(rc:0 mean Terminal)//~v761R~
//*****************************************************************//~v761I~
int chkTerminal()                                                  //~v761I~
{                                                                  //~v761I~
	int pid,ppid,rc=0,rc2;                                         //~v761I~
    char fnm[MAX_PATH];                                            //~v761I~
	static char *Sterminal="\\WindowsTerminal.exe";                //~v761R~
	static char *Sconhost="\\conhost.exe";                         //~v761R~
    int modeVT;                                                    //~v7a6I~
//************************                                         //~v761I~
    if (GuprocStat & GUPS_VTCHKDONE)                               //~v7biI~
    {                                                              //~v7biI~
        rc=(GuprocStat & GUPS_CONHOST)!=0 ? 1 : 2;                 //~v7biI~
    	UTRACEP("%s:2nd call return GuprocStat=0x%04x,rc=%d\n",UTT,GuprocStat,rc);//~v7biI~
        return rc;                                                 //~v7biI~
    }                                                              //~v7biI~
    modeVT=isVTmode();                                             //~v7a6I~
    if (modeVT>=0)                                                 //~v7a6I~
    {                                                              //~v7a6I~
        rc=modeVT!=0 ? 2 : 1;                                      //~v7a6I~
        GuprocStat|=GUPS_VTCHKDONE+(rc==1 ? GUPS_CONHOST : 0);     //~v7biI~
    	UTRACEP("%s:1st call return modeVT=%d,rc=%d,GuprocStat=0x%04x\n",UTT,modeVT,rc,GuprocStat);      //~v7a6R~//~v7biR~
        return rc;                                                 //~v7a6R~
    }                                                              //~v7a6I~
	pid=ugetpid();	//current pid                                  //~v761I~
    UTRACEP("%s,currpid=%d\n",UTT,pid);                            //~v761I~
	ppid=getParentPID(pid);                                        //~v761I~
    if (ppid!=0)                                                   //~v761I~
    {                                                              //~v761I~
		rc2=getProcessName(ppid,fnm,(int)sizeof(fnm));             //~v761I~
    	UTRACEP("%s,parent=%d=%s\n",UTT,ppid,fnm);                 //~v761I~
        if (rc2==0)                                                //~v761I~
        {                                                          //~v761I~
        	if (ustrstri(fnm,Sterminal))                           //~v761I~
            	rc=2;	                                           //~v761I~
            else                                                   //~v761I~
        	if (ustrstri(fnm,Sconhost))                            //~v761I~
            	rc=1;                                              //~v761I~
        }                                                          //~v761I~
        if (!rc)                                                   //~v761I~
        {                                                          //~v761I~
			ppid=getParentPID(ppid);                               //~v761I~
            rc2=getProcessName(ppid,fnm,(int)sizeof(fnm));         //~v761I~
	    	UTRACEP("%s,parent of parent=%d=%s\n",UTT,ppid,fnm);   //~v761I~
            if (rc2==0)                                            //~v761I~
            {                                                      //~v761I~
                if (ustrstri(fnm,Sterminal))                       //~v761I~
                    rc=2;                                          //~v761I~
                else                                               //~v761I~
                if (ustrstri(fnm,Sconhost))                        //~v761I~
                    rc=1;                                          //~v761I~
            }                                                      //~v761I~
        }	                                                       //~v761I~
    }                                                              //~v761I~
    GuprocStat|=GUPS_VTCHKDONE+(rc==1 ? GUPS_CONHOST : 0);         //~v7biI~
    UTRACEP("%s:parentchk rc=%d,currpid=%d,GuprocStat=0x%04x\n",UTT,rc,pid,GuprocStat);                   //~v761I~//~v7biR~
    return rc;                                                     //~v761I~
}                                                                  //~v761I~
#endif //WINCON                                                    //~v7biR~
#endif                                                             //~v761R~
