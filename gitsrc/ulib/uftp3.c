//*CID://+v771R~:                             update#= 1004;       //+v771R~
//*************************************************************
//*uftp3.c                                                         //~v61pR~
//* psftp support                                                  //~v61pR~
//*************************************************************
//v771:230323 sys/timeb.h is not found on ARM                      //+v771I~
//v6T0:180129 xehosts;Port option support                          //~v6T0I~
//v6J4:170207 (Bug:Lnx)smb err was not checked, edit cmd opens file as new file//~v6J4I~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H7:170108 FTP crush by long name                               //~v6H3I~
//v6Ev:160819 (Win)correct warning "Samba option ignored"          //~v6EvI~
//v6Eu:160819 (LNX)FTP samba,fail to get unicode filename by the reason of "export LANG=C;" prefix//~v6EuI~
//v6Dk:160625 (BUG)ftp may clash when cmd failed                   //~v6DkI~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6BM:160313 (W32) compiler warning                               //~v6BMI~
//v6x7:150109 (warning C4244) additional to v6x5 but avoid warning only//~v6x7I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6n0:130816 compiler warning;set but not used                    //~v6n0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hc:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(copile optio -Ox is required also)//~v6hcI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6di:120323 (BUG of v6d1)smb:xdd fail by no such file            //~v6diI~
//v6da:120217 (Axe)smb support                                     //~v6daI~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v5d1I~
//v5m3:080131 (BUG)ABEND when psftp returns no stdout msg(the case is xehost path defined invalid pgm)//~v5m3I~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>                                                 //~v59dI~
#ifndef ARM                                                        //+v771I~
#include <sys/timeb.h>                                             //~v59dI~
#endif                                                             //~v59dI~//+v771R~
//*******************************************************          //~v59dI~
#ifdef W32                                                         //~v59dI~
	#include <dos.h>                                               //~v59dI~
	#include <process.h>                                           //~v5bvI~
	#include <io.h>                                                //~v5bvI~
	#include <fcntl.h>                                             //~v5bvI~
	#include <windows.h>                                           //~v59dI~
#else                                                              //~v59dR~
    #include <unistd.h>                                            //~v59dM~
#endif                                                             //~v59dR~
                                                                   //~v59dI~
//*******************************************************
#include <ulib.h>
#include <uque.h>                                                  //~v59dI~
#include <ufile.h>
#include <ufile2.h>                                                //~v61pR~
#include <ufile4.h>                                                //~v61pI~
#include <uerr.h>
#include <ustring.h>
#include <ualloc.h>                                                //~v50GI~
#include <uproc.h>                                                 //~v50GI~
#include <uedit.h>                                                 //~v59dI~
#include <udbcschk.h>                                              //~v5afI~
#include <utrace.h>                                                //~v61pI~
#include <uftp.h>                                                  //~v61pI~
#include <ufile1f.h>                                               //~v61pM~
#include <uftp3.h>                                                 //~v61pI~
#include <ufemsg.h>                                                //~v61pI~
#include <uedit2.h>                                                //~v6D2I~
#ifdef ARMXXE                                                      //~v6daR~
#include <jnic2ju.h>                                               //~v6daI~
#endif                                                             //~v59dI~//~v6daR~
//*******************************************************
typedef struct _UFTPPARM  {                                        //~v6d1I~
                            PUFTPHOST UFPpuftph;                   //~v6d1I~
                            PUDIRLIST UFPpudl;                     //~v6d1I~
                            int    UFPpudlno;                      //~v6d1I~
                            char  *UFPsfpath;  //path name without last "/" even for root//~v6d1I~
                            int    UFPspathlen; //with hostnm,w/o last "/" even for root//~v6d1I~
                            int    UFPcmdctr;                      //~v6d1I~
                            } UFTPPARM,*PUFTPPARM;                 //~v6d1I~
#define UFTPPARMSZ (sizeof(UFTPPARM))                              //~v6d1I~
int uftp3smb_srchresp(int Popt,char **Pstdo,int Pstdoctr,char *Pkey,char ***Ppstdo,int *Pstdoremainctr,int *Ppoffs);//~v6d1R~
int uftp3smb_stderrlog(int Popt,char **Pstdo,int Pstdoctr);        //~v6d1I~
int uftp3smb_cmd(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char ***Pstdo,int *Pstdoctr,FTPCMD_CALLBACK *Pfunc,void *Ppvoid,char ***Ppstde,int *Ppstdectr);//~v6d1R~
int uftp3smb_chkstatuserr(int Popt,PUFTPHOST Ppuftph,char **Pstde,int Pstdectr,char ***Pfound,int *Ppremainctr,int *Ppoffs);//~v6d1I~
#define CSE_ERRMSG     0x01  //uerrmsg for detected NT_STATUS      //~v6d1I~
int uftp3smb_setdltime(int Popt,struct tm *Pptm,time_t *Pptimet,FDATE *Ppdate,FTIME *Pptime);//~v6d1I~
int uftp3smb_fstatoutchk(int Popt,PUFTPHOST Ppuftph,char *Pfname,PUDIRLIST Ppudl,char **Pstdo,int Pstdoctr);//~v6d1R~
int uftp3smb_enclosefnm(int Popt,PUFTPHOST Ppuftph,char *Pout,char *Pfnm);           //~v6d1I~//~v6d7R~
#define F3SEFO_CMDFILE  0x01                                       //~v6d1I~
unsigned int uftp3smb_fstatudl_byls(int Popt,PUFTPHOST Ppuftph,char *Pfpnm,PUDIRLIST Ppudl);//~v6d1R~
unsigned int uftp3smb_fstatudl_byls_root(int Popt,PUFTPHOST Ppuftph,PUDIRLIST Ppudl);//~v6d1I~
unsigned int uftp3smb_lsoutchk(int Popt,PUFTPHOST Ppuftph,char *Pfname,char **Pstdo,int stdoctr,PUDIRLIST Ppudl);//~v6d1I~
int uftp3smb_editcmdparm(int Popt,PUFTPHOST Ppuftph,char *Pout,char *Pcmd,int Pbuffsz);//~v6d1I~//~v6d7R~
FTPCMD_CALLBACK  uftp3smb_fstatdircallback;                        //~v6d1I~
int uftp3smb_fstatdirrchk(PUFTPPARM Ppufp,char **Ppstdo,int Pstdoctr);//~v6d1I~
//*******************************************************          //~v59dI~
//*get data from xehosts file ctl line                             //~v61pR~
//*******************************************************          //~v59dI~
int uftp3setssh(int Popt,PUFTPHOST Ppuftph,char *Plinedata,char **Ppnextdata)//~v61pR~
{                                                                  //~v59dI~
	char *pc,*pc2;                                                 //~v61pI~
    int len,rc=4;                                                  //~v61pR~
//***********************                                          //~v59dI~
    switch(Popt & 0xff)                                            //~v61pI~
    {                                                              //~v61pI~
    case 0:	//hdr line                                             //~v61pI~
        pc=Plinedata;                                              //~v61pR~
        pc2=strchr(pc+1,'#');                                      //~v61pR~
        if (pc2)                                                   //~v61pR~
            *pc2=0;                                                //~v61pR~
        if (!memcmp(pc,FTP_HDR_PSFTP,sizeof(FTP_HDR_PSFTP)-1))     //~v61pR~
        {                                                          //~v61pR~
            pc+=sizeof(FTP_HDR_PSFTP)-1;                           //~v61pR~
            pc+=strspn(pc,"\t ");                                  //~v61pR~
//          len=strlen(pc);                                        //~v61pR~//~v6D0R~
            len=(int)strlen(pc);                                   //~v6D0I~
            if (len>0                                              //~v61pR~
            &&  len<FTP_CLIENTCMDLEN-1)                            //~v61pR~
            {                                                      //~v61pR~
                memcpy(Gftpclient,pc,(UINT)len);                   //~v61pR~
                *(Gftpclient+len)=0;                               //~v61pR~
                rc=0;                                              //~v61pR~
            }                                                      //~v61pR~
            else                                                   //~v61pR~
                uerrmsg("xehosts file hdr-line format err(%s[%s|psftp-cmd-string])",0,//~v61pR~
                        FTP_HDR_PSFTP,FTP_VALUE_PSFTP);            //~v61pR~
        }                                                          //~v61pR~
        else                                                       //~v61pR~
        if (!memcmp(pc,FTP_HDR_SSH,sizeof(FTP_HDR_SSH)-1))         //~v61pR~
        {                                                          //~v61pR~
            pc+=sizeof(FTP_HDR_SSH)-1;                             //~v61pR~
            pc+=strspn(pc,"\t ");                                  //~v61pR~
            if (!memicmp(pc,FTP_VALUE_ALL,sizeof(FTP_VALUE_ALL)-1))//~v61pR~
            {                                                      //~v61pR~
                Gftpopt|=GFTPO_PSFTPALL;                           //~v61pR~
                rc=0;                                              //~v61pR~
            }                                                      //~v61pR~
            else                                                   //~v61pR~
                uerrmsg("xehosts file hdr-line format err(%s%s)",0,//~v61pR~
                        FTP_HDR_SSH,FTP_VALUE_ALL);                //~v61pR~
        }                                                          //~v61pR~
        else                                                       //~v61pR~
            rc=0;   //assume as comment                            //~v61pR~
        break;                                                     //~v61pR~
    case 1:	//each line SSH=                                       //~v61pI~
        pc=Plinedata;                                              //~v61pI~
        pc+=strspn(pc,"\t ");                                      //~v61pI~
        switch(toupper(*pc))                                       //~v61pI~
        {                                                          //~v61pI~
        case 'Y':                                                  //~v61pI~
        	Ppuftph->UFTPHflag|=UFTPHFPSFTP;                       //~v61pI~
            rc=0;                                                  //~v61pI~
            break;                                                 //~v61pI~
        case 'N':                                                  //~v61pI~
//        	Ppuftph->UFTPHflag&=~UFTPHFPSFTP;                      //~v61pR~//~v6D0R~
          	Ppuftph->UFTPHflag&=~(ULONG)UFTPHFPSFTP;               //~v6D0I~
            rc=0;                                                  //~v61pI~
            break;                                                 //~v61pI~
        default:                                                   //~v61pI~
            uerrmsg("ssh parameter err(%s)",0,                     //~v61pR~
                        pc);                                       //~v61pI~
        }                                                          //~v61pI~
        pc++;                                                      //~v61pI~
        *Ppnextdata=pc;                                            //~v61pI~
    	break;                                                     //~v61pI~
    }//opt sw                                                      //~v61pI~
//UTRACEP("psftpcmd=%s\n",Gftpclient);                             //~v61pR~
    return rc;                                                     //~v61pR~
}//ftp3setssh                                                      //~v6d1R~
//**********************************************************************//~v61pI~
// edit ftp cmd and batch file for psftp cmd                       //~v61pI~
//**********************************************************************//~v61pI~
int uftp3editpsftpcmd(int Popt,PUFTPHOST Ppuftph,int Pftpcmdopt,char *Pcmd,char *Pftpcmd,char *Psubcmdhdr,char *Ptempfnm)//~v61pR~
{                                                                  //~v61pI~
	char *cmdline;                                                 //~v61pR~
static int Ssw1st=1;                                               //~v61pI~
//********************                                             //~v61pI~
//    if (Pftpcmdopt & FTPCMD_BINARY)   //sftp is always binary mode//~v61pR~
//        bora="binary";                                           //~v61pR~
//    else                                                         //~v61pR~
//        bora="ascii";                                            //~v61pR~
  if (Ppuftph->UFTPHport)                                          //~v6T0I~
    sprintf(Psubcmdhdr,                                            //~v6T0I~
    		"open %s %d\n"                    \
	    	"%s\n"        /*binary|ascii*;@@@ required for 530 diff LNX and AIX*///~v6T0I~
    		"pwd\n", 	//last of  hdr cmd                         //~v6T0I~
			Ppuftph->UFTPHipad,                                    //~v6T0I~
			Ppuftph->UFTPHport,                                    //~v6T0I~
			Ppuftph->UFTPHicmd);                                   //~v6T0I~
  else                                                             //~v6T0I~
    sprintf(Psubcmdhdr,                                            //~v61pI~
    		"open %s\n"                    \
	    	"%s\n"        /*binary|ascii*;@@@ required for 530 diff LNX and AIX*///~v61pI~
    		"pwd\n", 	//last of  hdr cmd                         //~v61pI~
			Ppuftph->UFTPHipad,                                    //~v61pI~
			Ppuftph->UFTPHicmd);                                   //~v61pR~
    utempnam("","uftp_",Ptempfnm);	// TEMP= or /tmp               //~v61pI~
    cmdline=Gftpclient;                                            //~v61pR~
    if (Ssw1st)                                                    //~v61pR~
    {                                                              //~v61pI~
    	Ssw1st=0;                                                  //~v61pI~
    	sprintf(Pftpcmd,"PSFTP cmd : " FTP_PSFTPCMD "\n",cmdline,Ptempfnm,Ppuftph->UFTPHuser,"********");//~v61pR~
	    uftplog(FTPLOG_INFO,Pftpcmd);                              //~v61pR~
    }                                                              //~v61pI~
    sprintf(Pftpcmd,FTP_PSFTPCMD,cmdline,Ptempfnm,Ppuftph->UFTPHuser,Ppuftph->UFTPHpswd);//~v61pR~
    return 0;                                                      //~v61pI~
}//uftp3editpsftpcmd                                               //~v61pI~
//**********************************************************************//~v61pI~
// replace prmpt for seach end of cmd response                     //~v61pR~
// return :1 eof                                                   //~v61pI~
//**********************************************************************//~v61pI~
int uftp3cmdrespchk(int Popt,PUFTPHOST Ppuftph,char **Ppstdo,int Pstdoctr)//~v61pI~
{                                                                  //~v61pI~
	int  logopt,ii;                                                //~v61pR~
    char **pstdo,*linedata,*pc;                                    //~v61pI~
//********************                                             //~v61pI~
	logopt=FTPLOG_RESP|FTPLOG_ADDLF;    //no pswd on resp msg      //~v61pR~
	for (pstdo=Ppstdo,ii=0;ii<Pstdoctr;ii++,pstdo++)               //~v61pI~
    {                                                              //~v61pI~
    	linedata=*pstdo;                                           //~v61pI~
        uftplog(logopt,linedata);                                  //~v61pR~
	    logopt&=~FTPLOG_RESP;                                      //~v61pI~
        if (!memicmp(linedata,FTP_ECHO_PSFTP,sizeof(FTP_ECHO_PSFTP)-1))//~v61pR~
        {                                                          //~v61pI~
        	pc=linedata+sizeof(FTP_ECHO_PSFTP)-1;                  //~v61pR~
            pc+=strspn(pc," ");                                    //~v61pI~
            memcpy(linedata,FTP_ECHO_PSFTP_ID,sizeof(FTP_ECHO_PSFTP_ID)-1);//~v61pR~
            memcpy(linedata+sizeof(FTP_ECHO_PSFTP_ID)-1,pc,strlen(pc)+1);//~v61pR~
        }                                                          //~v61pI~
    }                                                              //~v61pI~
    return 0;                                                      //~v61pI~
}//uftp3cmdrespchk                                                 //~v61pI~
//**********************************************************************//~v61pI~
// chk responce of fixed cmd, open etc. for psftp                  //~v61pI~
// return :1 eof                                                   //~v61pI~
//**********************************************************************//~v61pI~
int uftp3cmdresphdrchk(int Popt,PUFTPHOST Ppuftph,char ***Pppstdo,int *Ppstdoctr)//~v61pI~
{                                                                  //~v61pI~
	int  stdoctr,rc;                                               //~v61pI~
    char **pstdo,**pstdo0;                                         //~v61pI~
//********************                                             //~v61pI~
	pstdo0=pstdo=*Pppstdo;                                         //~v61pI~
	stdoctr=*Ppstdoctr;                                            //~v61pI~
    if (!stdoctr)               //no response msg written          //~v5m3R~
		return FTPRC_SSHERR;   	//avoid abend                      //~v5m3R~
    for (;;)                                                       //~v61pI~
    {                                                              //~v61pI~
    	if (strstr(*pstdo,FTP_PSFTP_SSH_ERR))	//host key not cached(1st connection to the host)//~v61pI~
        {                                                          //~v61pI~
			rc=FTPRC_SSHERR;                                       //~v61pI~
        	break;                                                 //~v61pI~
    	}                                                          //~v61pI~
        if (uftpcmdsrchrespid(&pstdo,&stdoctr,FTP_PSFTP_OK_REMOTE))//search Remote:open ok//~v61pR~
        {                                                          //~v61pI~
			rc=FTPRC_OPENERR;                                      //~v61pI~
        	break;                                                 //~v61pI~
    	}                                                          //~v61pI~
        if (uftp3srchcmdecho(0,Ppuftph,&pstdo,&stdoctr,"pwd"))//search 257:pwd resp//~v61pR~
        {                                                          //~v61pR~
    		rc=FTPRC_PARSEERR;                                     //~v61pI~
        	break;                                                 //~v61pI~
        }                                                          //~v61pI~
        rc=0;                                                      //~v61pI~
        break;                                                     //~v61pI~
    }                                                              //~v61pI~
    if (pstdo!=pstdo0)                                             //~v61pI~
    {                                                              //~v61pI~
//  	memcpy(pstdo0,pstdo,4*stdoctr);//shift to top              //~v5m3R~
//    	memcpy(pstdo0,pstdo,4*(stdoctr+1));//shift to top(copy also last null pointer)//~v6hhR~
//   	memcpy(pstdo0,pstdo,PTRSZ*(stdoctr+1));//shift to top(copy also last null pointer)//~v6hhI~//~v6D0R~
     	memcpy(pstdo0,pstdo,(size_t)(PTRSZ*(stdoctr+1)));//shift to top(copy also last null pointer)//~v6D0I~
        pstdo=pstdo0;                                              //~v61pI~
    }                                                              //~v61pI~
	*Pppstdo=pstdo;                                                //~v61pI~
	*Ppstdoctr=stdoctr;                                            //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3cmdresphdrchk                                              //~v61pI~
//**********************************************************************//~v61pI~
// search cmd echoo line                                           //~v61pI~
// return :0 okstr found,4:reached to end                          //~v61pI~
//**********************************************************************//~v61pI~
int uftp3srchcmdecho(int Popt,PUFTPHOST Ppuftph,char ***Pppstdo,int *Ppstdoctr,char *Pcmd)//~v61pI~
{                                                                  //~v61pI~
    char **pstdo,*stdo,*pc;                                        //~v61pI~
    int stdoctr,rc=UFCSRRC_EOL,cmdlen,len,echoidlen;               //~v61pR~
//********************                                             //~v61pI~
	stdoctr=*Ppstdoctr;                                            //~v61pI~
	pstdo=*Pppstdo;                                                //~v61pI~
    echoidlen=sizeof(FTP_ECHO_PSFTP_ID)-1;                         //~v61pR~
//  cmdlen=strlen(Pcmd);                                           //~v61pI~//~v6D0R~
    cmdlen=(int)strlen(Pcmd);                                      //~v6D0I~
    for (;stdoctr>0;stdoctr--,pstdo++)                             //~v61pI~
    {                                                              //~v61pI~
    	stdo=*pstdo;                                               //~v61pI~
        if (!memcmp(stdo,FTP_ECHO_PSFTP_ID,(UINT)echoidlen))       //~v61pI~
        {                                                          //~v61pI~
        	pc=stdo+echoidlen;                                     //~v61pI~
//      	len=strlen(pc);                                        //~v61pI~//~v6D0R~
        	len=(int)strlen(pc);                                   //~v6D0I~
            if (len>=cmdlen && !memcmp(pc,Pcmd,(UINT)cmdlen))      //~v61pR~
            {                                                      //~v61pI~
            	rc=0;                                              //~v61pI~
        		break;                                             //~v61pI~
            }                                                      //~v61pI~
        }                                                          //~v61pI~
    }                                                              //~v61pI~
    if (rc!=UFCSRRC_EOL)	//found                                //~v61pI~
    {                                                              //~v61pI~
		--stdoctr;                                                 //~v61pI~
		++pstdo;                                                   //~v61pI~
		*Ppstdoctr=stdoctr;                                        //~v61pI~
		*Pppstdo=pstdo;                                            //~v61pI~
    }                                                              //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3srchcmdecho                                                //~v61pI~
//*******************************************************          //~v61pI~
//*get home dir from output of pwd cmd                             //~v61pI~
//*******************************************************          //~v61pI~
int uftp3gethomesub(int Popt,PUFTPHOST Ppfh,char **Pstdo,int Pstdoctr)//~v61pI~
{                                                                  //~v61pI~
	int rc,len,stdoctr;                                            //~v61pI~
    char **stdo,*pc0,*pc,*pc2;                                     //~v61pR~
//*********************************                                //~v61pI~
    stdo=Pstdo;                                                    //~v61pR~
    stdoctr=Pstdoctr;                                              //~v61pI~
    if (!(rc=uftpcmdsrchrespid(&stdo,&stdoctr,FTP_PSFTP_OK_REMOTE)))//~v61pI~
    {    //Remote directory is ----                                //~v61pI~
    	pc0=*(stdo-1);	//stdo is next of 257 line                 //~v61pI~
        pc=strchr(pc0,'"');                                        //~v61pI~
        if (pc)                                                    //~v61pI~
        {                                                          //~v61pI~
        	pc++;                                                  //~v61pI~
            pc2=strchr(pc,'"');                                    //~v61pI~
        }                                                          //~v61pI~
        else                                                       //~v61pI~
        {                                                          //~v61pI~
        	pc=strchr(pc0,FTP_DIR_SEPC);                           //~v61pR~
            if (!pc)                                               //~v61pI~
            	return 8;                                          //~v61pI~
            pc2=0;                                                 //~v61pI~
        }                                                          //~v61pI~
        if (pc2)                                                   //~v61pI~
//          len=(int)((ULONG)pc2-(ULONG)pc);                       //~v61pI~//~v6hhR~
            len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~v6hhI~
        else                                                       //~v61pI~
//          len=strlen(pc);                                        //~v61pI~//~v6D0R~
            len=(int)strlen(pc);                                   //~v6D0I~
        if (len<FTP_MAXPATH)                                       //~v61pI~
        {                                                          //~v61pI~
            memcpy(Ppfh->UFTPHhome,pc,(UINT)len);                  //~v61pI~
            *(Ppfh->UFTPHhome+len)=0;                              //~v61pI~
        }                                                          //~v61pI~
        else                                                       //~v61pI~
            rc=8;                                                  //~v61pI~
    }                                                              //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3gethomesub                                                 //~v61pI~
//**************************************************************** //~v61pI~
//cd response chk                                                  //~v61pI~
//*retrn:rc                                                        //~v61pI~
//**************************************************************** //~v61pI~
int uftp3simplerespchk(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pokresp,char *Pparm,char ***Ppstdo,int *Ppstdoctr,int Prc)//~v61pR~
{                                                                  //~v61pI~
    int rc,stdoctr;                                                //~v61pR~
    char **stdo,*pc,*pcreason=0;                                   //~v61pR~
//********************                                             //~v61pI~
	stdo=*Ppstdo;                                                  //~v61pI~
    stdoctr=*Ppstdoctr;                                            //~v61pI~
	rc=uftp3srchcmdecho(0,Ppuftph,&stdo,&stdoctr,Pcmd);            //~v61pR~
    if (!rc)                                                       //~v61pI~
    {                                                              //~v61pI~
        pc=*stdo;                                                  //~v61pI~
        pcreason=pc;                                               //~v61pI~
        if (strstr(pc,FTP_PSFTP_NG_UNKNOWN))                       //~v61pI~
        {                                                          //~v61pI~
        	rc=uftpnotsupported(Pcmd,"using PSFTP");               //~v61pI~
            stdo++;                                                //~v61pI~
            stdoctr--;                                             //~v61pI~
        }                                                          //~v61pI~
        else                                                       //~v61pI~
        	rc=uftpcmdsrchrespid(&stdo,&stdoctr,Pokresp);          //~v61pR~
    }                                                              //~v61pI~
    if (rc)		//err                                              //~v61pI~
    {                                                              //~v61pI~
        if (pcreason)                                              //~v61pI~
	        uerrmsg("%s failed (%s).",0,                           //~v61pR~
        			Pcmd,pcreason); //already exit or path not found//~v61pR~
        else                                                       //~v61pI~
	        uerrmsg("%s failed for %s.",0,                         //~v61pI~
        			Pcmd,Pparm); //already exit or path not found  //~v61pI~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61pI~
        rc=Prc;                                                    //~v61pI~
    }                                                              //~v61pI~
    *Ppstdo=stdo;                                                  //~v61pI~
    *Ppstdoctr=stdoctr;                                            //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3simplerespchk                                              //~v61pI~
//**************************************************************** //~v61pI~
//cd response chk(chek OK at EOL)                                  //~v61pI~
//Pcmd:issued cmd            (ex. delete)                          //~v61pI~
//Pcmd2:response msg cmd     (ex. rm)                              //~v61pI~
//*retrn:rc                                                        //~v61pI~
//**************************************************************** //~v61pI~
int uftp3simplerespchkOK(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pcmd2,char ***Ppstdo,int *Ppstdoctr,int Prc)//~v61pI~
{                                                                  //~v61pI~
    int rc,rc2,stdoctr,linelen,wordlen;                            //~v61pR~
    char **stdo,*pc;                                               //~v61pR~
//********************                                             //~v61pI~
	rc=Prc;                                                        //~v61pI~
	stdo=*Ppstdo;                                                  //~v61pI~
    stdoctr=*Ppstdoctr;                                            //~v61pI~
	rc2=uftp3srchcmdecho(0,Ppuftph,&stdo,&stdoctr,Pcmd);           //~v61pI~
    if (!rc2)                                                      //~v61pI~
    {                                                              //~v61pI~
        for (;;)                                                   //~v61pR~
        {                                                          //~v61pR~
            pc=*stdo;                                              //~v61pR~
//          linelen=strlen(pc);                                    //~v61pR~//~v6D0R~
            linelen=(int)strlen(pc);                               //~v6D0I~
//          wordlen=strlen(Pcmd2);                                 //~v61pR~//~v6D0R~
            wordlen=(int)strlen(Pcmd2);                            //~v6D0I~
//          if (linelen<=wordlen || memcmp(pc,Pcmd2,wordlen))   //top is cmd verb//~v61pR~//~v6D0R~
            if (linelen<=wordlen || memcmp(pc,Pcmd2,(size_t)wordlen))   //top is cmd verb//~v6D0I~
                break;                                             //~v61pR~
            wordlen=sizeof(FTP_PSFTP_OK_OK)-1;  //" OK"            //~v61pR~
//          if (linelen<=wordlen || memcmp(pc+linelen-wordlen,FTP_PSFTP_OK_OK,wordlen))//~v61pR~//~v6D0R~
            if (linelen<=wordlen || memcmp(pc+linelen-wordlen,FTP_PSFTP_OK_OK,(size_t)wordlen))//~v6D0I~
            {                                                      //~v61pR~
                if (Popt & UFTP3SRCO_ERRMSG)       //issue errmsg  //~v61pR~
                {                                                  //~v61pR~
                    uerrmsg("%s failed (%s).",0,                   //~v61pR~
                            Pcmd,pc); //already exit or path not found//~v61pR~
                    uftplog(FTPLOG_ERRM,0); //logging errmsg       //~v61pR~
                }                                                  //~v61pR~
                break;                                             //~v61pR~
            }                                                      //~v61pR~
            rc=0;                                                  //~v61pR~
            break;                                                 //~v61pR~
        }                                                          //~v61pR~
        stdo++;                                                    //~v61pI~
        stdoctr--;                                                 //~v61pI~
    }                                                              //~v61pI~
    *Ppstdo=stdo;                                                  //~v61pI~
    *Ppstdoctr=stdoctr;                                            //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3simplerespchkOK                                            //~v61pR~
//**************************************************************** //~v61pI~
//cd response chk(chek " -> "OK                                    //~v61pI~
//Pcmd:issued cmd                                                  //~v61pI~
//Pfnm:optional to compare 1st word                                //~v61pI~
//*retrn:rc                                                        //~v61pI~
//**************************************************************** //~v61pI~
int uftp3simplerespchkCHNG(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pfnm,char ***Ppstdo,int *Ppstdoctr,int Prc)//~v61pI~
{                                                                  //~v61pI~
    int rc,rc2,stdoctr;                                            //~v61pI~
    char **stdo,*pc,*pc2;                                          //~v61pR~
//********************                                             //~v61pI~
	rc=Prc;                                                        //~v61pI~
	stdo=*Ppstdo;                                                  //~v61pI~
    stdoctr=*Ppstdoctr;                                            //~v61pI~
	rc2=uftp3srchcmdecho(0,Ppuftph,&stdo,&stdoctr,Pcmd);           //~v61pI~
    if (!rc2)                                                      //~v61pI~
    {                                                              //~v61pI~
        for (;;)                                                   //~v61pR~
        {                                                          //~v61pR~
            pc=*stdo;                                              //~v61pR~
            pc2=strstr(pc,FTP_PSFTP_OK_CHNG);   // " -> "          //~v61pR~
            if (!pc2)                                              //~v61pR~
            {                                                      //~v61pR~
                if (Popt & UFTP3SRCC_ERRMSG)       //issue errmsg  //~v61pR~
                {                                                  //~v61pR~
                    uerrmsg("%s failed (%s).",0,                   //~v61pR~
                            Pcmd,pc); //already exit or path not found//~v61pR~
                    uftplog(FTPLOG_ERRM,0); //logging errmsg       //~v61pR~
                }                                                  //~v61pR~
                break;                                             //~v61pR~
            }                                                      //~v61pR~
            if (Pfnm)                                              //~v61pR~
            {                                                      //~v61pR~
                *pc2=0;                                            //~v61pR~
                if (Popt & UFTP3SRCC_CHMOD)                        //~v61pR~
                {                                                  //~v61pR~
                    if (pc2=strchr(pc,':'),pc2)                    //~v61pR~
                        *pc2=0;                                    //~v61pR~
                }                                                  //~v61pR~
                if (strcmp(pc,Pfnm))                               //~v61pR~
                    break;                                         //~v61pR~
            }                                                      //~v61pR~
            rc=0;                                                  //~v61pR~
            break;                                                 //~v61pR~
        }                                                          //~v61pR~
        stdo++;                                                    //~v61pI~
        stdoctr--;                                                 //~v61pI~
    }                                                              //~v61pI~
    *Ppstdo=stdo;                                                  //~v61pI~
    *Ppstdoctr=stdoctr;                                            //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3simplerespchkCHNG                                          //~v61pI~
//*******************************************************          //~v61pI~
//*chang local dir responce msg chk                                //~v61pI~
//*******************************************************          //~v61pI~
int uftp3lchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm)//~v61pI~
{                                                                  //~v61pI~
    int rc;                                                        //~v61pI~
//*********************************                                //~v61pI~
	rc=uftp3simplerespchk(0,Ppuftph,"lcd",FTP_PSFTP_OK_LCD,Pdirnm,Ppstdo,Ppstdoctr,ENOENT);//~v61pR~
    return rc;                                                     //~v61pI~
}//uftp3lchdirrespchk                                              //~v61pI~
//*******************************************************          //~v61pI~
//*chang local dir responce msg chk                                //~v61pI~
//*******************************************************          //~v61pI~
int uftp3getputrespchk(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pparm,char ***Ppstdo,int *Ppstdoctr,int Prc)//~v61pI~
{                                                                  //~v61pI~
    int rc;                                                        //~v61pI~
//*********************************                                //~v61pI~
	if (!strcmp(Pcmd,"get"))                                       //~v61pI~
    	rc=uftp3simplerespchk(0,Ppuftph,Pcmd,FTP_PSFTP_OK_GET,Pparm,Ppstdo,Ppstdoctr,Prc);//~v61pR~
    else    //put or put(append)                                   //~v61pR~
        if (strstr(Pcmd,"append"))                                 //~v61pI~
	    	rc=uftp3simplerespchk(0,Ppuftph,"append",FTP_PSFTP_OK_PUT,Pparm,Ppstdo,Ppstdoctr,Prc);//~v61pI~
        else                                                       //~v61pI~
	    	rc=uftp3simplerespchk(0,Ppuftph,Pcmd,FTP_PSFTP_OK_PUT,Pparm,Ppstdo,Ppstdoctr,Prc);//~v61pR~
    return rc;                                                     //~v61pI~
}//uftp3getputrespchk                                              //~v61pI~
//*******************************************************          //~v61pI~
//*chang remote dir responce msg chk                               //~v61pI~
//*rc:1:not found,4:other err                                      //~v61pI~
//*******************************************************          //~v61pI~
int uftp3cdrespchk(int Popt,PUFTPHOST Ppuftph,char *Pparm,char ***Ppstdo,int *Ppstdoctr)//~v61pI~
{                                                                  //~v61pI~
    int rc=4,rc2,stdoctr,wordlen,linelen;                          //~v61pR~
    char **stdo,*pc;                                               //~v61pR~
//*********************************                                //~v61pI~
	stdo=*Ppstdo;                                                  //~v61pI~
    stdoctr=*Ppstdoctr;                                            //~v61pI~
	rc2=uftp3srchcmdecho(0,Ppuftph,&stdo,&stdoctr,"cd"); //search erco//~v61pI~
    if (!rc2)                                                      //~v61pI~
    {                                                              //~v61pI~
        for (;;)                                                   //~v61pR~
        {                                                          //~v61pR~
            pc=*stdo;                                              //~v61pR~
//          linelen=strlen(pc);                                    //~v61pR~//~v6D0R~
            linelen=(int)strlen(pc);                               //~v6D0I~
            wordlen=sizeof(FTP_PSFTP_OK_REMOTE)-1;                 //~v61pR~
//          if (linelen>wordlen && !memcmp(pc,FTP_PSFTP_OK_REMOTE,wordlen)) //"remote dir is now"//~v61pR~//~v6D0R~
            if (linelen>wordlen && !memcmp(pc,FTP_PSFTP_OK_REMOTE,(size_t)wordlen)) //"remote dir is now"//~v6D0I~
                rc=0;                                              //~v61pR~
            else                                                   //~v61pR~
            if (strstr(pc,FTP_PSFTP_NG_NOTF))                      //~v61pR~
                rc=1;                                              //~v61pR~
            break;                                                 //~v61pR~
        }                                                          //~v61pR~
        stdo++;                                                    //~v61pI~
        stdoctr--;                                                 //~v61pI~
    }                                                              //~v61pI~
    *Ppstdo=stdo;                                                  //~v61pI~
    *Ppstdoctr=stdoctr;                                            //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3cdrespchk                                                  //~v61pI~
#ifdef AAA                                                         //~v61pI~
//**************************************************************** //~v61pI~
//ftp rename cmd result chk for PSFTP                              //~v61pI~
//*retrn:rc                                                        //~v61pI~
//**************************************************************** //~v61pI~
int uftp3multirenamerchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pI~
{                                                                  //~v61pI~
	PUFTPMULTIRENAME pfmr;                                         //~v61pI~
    int rc=0,filectr=0,renamectr,stdoctr,ii;                       //~v61pI~
    char **stdo,*pfpath,*pnewname;                                 //~v61pR~
//****************************                                     //~v61pI~
	stdoctr=Pstdoctr;                                              //~v61pI~
    stdo=Ppstdo;                                                   //~v61pI~
    pfmr=(PUFTPMULTIRENAME)(ULONG)(Ppfwf2p->UFWF2Ppudl);           //~v61pI~
    renamectr=Ppfwf2p->UFWF2Ppudlctr;                              //~v61pI~
    for (ii=0;ii<renamectr;ii++,pfmr++)  //until eof/err           //~v61pI~
    {                                                              //~v61pI~
        if (!(pfmr->UFMRflag & UFMDFDELREQ))                       //~v61pI~
            continue;                                              //~v61pI~
        pfpath=pfmr->UFMRpfpath;                                   //~v61pI~
        pnewname=pfmr->UFMRpnewname;                               //~v61pI~
		rc=uftp3simplerespchkCHNG(0,Ppuftph,"rename",pfpath,&stdo,&stdoctr,ENOENT);//~v61pI~
        if (!rc)                                                   //~v61pR~
        {                                                          //~v61pI~
            filectr++;                                             //~v61pI~
        }                                                          //~v61pI~
        else                                                       //~v61pI~
        {                                                          //~v61pI~
            if (!Gufile_nomsg)   //nomsg option                    //~v61pI~
            {                                                      //~v61pI~
              if (stdo>Ppstdo)                                     //~v6DkI~
        		uerrmsg("%s %s rename failed.(%s)",0,              //~v61pI~
						pfpath,pnewname,*(stdo-1));	//already exit or path not found//~v61pI~
              else                                                 //~v6DkI~
        		uerrmsg("%s %s rename failed.(see ::xeftplog)",0,  //~v6DkI~
						pfpath,pnewname);	//already exit or path not found//~v6DkI~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61pI~
            }                                                      //~v61pI~
            rc=ENOENT;                                             //~v61pI~
    		pfmr->UFMRrc=rc;                                       //~v61pI~
        }                                                          //~v61pI~
    }                                                              //~v61pI~
    Ppfwf2p->UFWF2Pcmdokctr=filectr;                               //~v61pI~
    ufree(Ppstdo);                                                 //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3multirenamerchk                                            //~v61pR~
//**************************************************************** //~v61pI~
//ftp delete cmd result chk                                        //~v61pI~
//*retrn:rc                                                        //~v61pI~
//**************************************************************** //~v61pI~
int uftp3multidelrchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr)//~v61pR~
{                                                                  //~v61pI~
	PUFTPMULTIDEL pfmd;                                            //~v61pI~
    int rc=0,filectr=0,delctr,stdoctr,ii,opt,linelen,wordlen;      //~v61pI~
    char **stdo,*pfpath,*pc;                                       //~v61pI~
//****************************                                     //~v61pI~
	stdoctr=Pstdoctr;                                              //~v61pI~
    stdo=Ppstdo;                                                   //~v61pI~
    pfmd=(PUFTPMULTIDEL)(ULONG)(Ppfwf2p->UFWF2Ppudl);              //~v61pI~
    delctr=Ppfwf2p->UFWF2Ppudlctr;                                 //~v61pI~
    opt=Ppfwf2p->UFWF2Popt;                                        //~v61pI~
    for (ii=0;ii<delctr;ii++,pfmd++)  //until eof/err              //~v61pI~
    {                                                              //~v61pI~
        if (!(pfmd->UFMDflag & UFMDFDELREQ))                       //~v61pI~
            continue;                                              //~v61pI~
        pfpath=pfmd->UFMDpfpath;                                   //~v61pI~
		rc=uftp3simplerespchkOK(0,Ppuftph,"delete","rm",&stdo,&stdoctr,ENOENT);//~v61pR~
        if (!rc)                                                   //~v61pR~
        {                                                          //~v61pI~
        	rc=ENOENT;                                             //~v61pI~
        	pc=*(stdo-1);                                          //~v61pR~
        	linelen=strlen(pc);                                    //~v61pI~
        	pc=strchr(pc,' ');	                                   //~v61pI~
            if (pc)                                                //~v61pI~
            	pc+=strspn(pc," ");                                //~v61pR~
            if (pc)                                                //~v61pI~
            {                                                      //~v61pI~
		        linelen=strlen(pc);                                //~v61pR~
            	wordlen=strlen(pfpath);                            //~v61pI~
                if (linelen>wordlen && !memcmp(pc,pfpath,(UINT)wordlen))//~v61pR~
                	rc=0;                                          //~v61pI~
            }                                                      //~v61pI~
        }                                                          //~v61pI~
        if (!rc)                                                   //~v61pI~
        {                                                          //~v61pI~
            filectr++;                                             //~v61pI~
            if (opt & UXDELMSG)                                    //~v61pI~
            	ufiledeleted(pfpath,'F',(FILESZT)(-1),0);//size=-1  mean no display size/attr//~v61pI~
        }                                                          //~v61pI~
        else                                                       //~v61pI~
        {                                                          //~v61pI~
            if (!Gufile_nomsg)   //nomsg option                    //~v61pI~
            {                                                      //~v61pI~
              if (stdo>Ppstdo)                                     //~v6DkI~
        		uerrmsg("%s remove failed.(%s)",0,                 //~v61pI~
						pfpath,*(stdo-1));	//already exit or path not found//~v61pI~
              else                                                 //~v6DkI~
        		uerrmsg("%s remove failed.(see ::xeftplog)",0,     //~v6DkI~
						pfpath);	//already exit or path not found//~v6DkI~
				uftplog(FTPLOG_ERRM,0);	//logging errmsg           //~v61pI~
            }                                                      //~v61pI~
    		pfmd->UFMDrc=rc;                                       //~v61pI~
        }                                                          //~v61pI~
    }                                                              //~v61pI~
    Ppfwf2p->UFWF2Pcmdokctr=filectr;                               //~v61pI~
    ufree(Ppstdo);                                                 //~v61pI~
    return rc;                                                     //~v61pI~
}//uftp3multidelrchk                                               //~v61pI~
#endif                                                             //~v61pM~
//**************************************************************** //~v6d1R~
//set share option by xehostrecord option                          //~v6d1R~
//**************************************************************** //~v6d1R~
int uftp3setsmb(int Popt,PUFTPHOST Ppuftph,char *Plinedata,char **Ppnextdata)//~v6d1R~
{                                                                  //~v6d1R~
    int rc=0;                                                      //~v6d7I~
#ifdef W32                                                         //~v6d7I~
#else                                                              //~v6d7I~
	char *pc;                                                      //~v6d1R~
//  int len;                                                       //~v6n0R~
#endif                                                             //~v6d7I~
//***********************                                          //~v6d1R~
#ifdef W32                                                         //~v6d7I~
//  uerrmsg("Windows ignored %s",0,                                //~v6EvR~
    uerrmsg("Samba option in xehosts file SHARE=%s for %s is ignored on Windows",//~v6EvR~
    		"Windows では xehosts ファイルの サンバ用オプション SHARE=%s は無視されます(ホスト=%s)",//~v6EvR~
//  		Plinedata);                                            //~v6EvR~
    		Plinedata,Ppuftph->UFTPHhost);                         //~v6EvI~
#else                                                              //~v6d7I~
    Ppuftph->UFTPHflag|=UFTPHFSMB;                                 //~v6d1R~
#ifdef ARM                                                         //~v6daI~
    Ppuftph->UFTPHflag|=UFTPHFSMBJ|UFTPHFRWIN; //jcifs attr is windows format(ASHRD)//~v6daR~
    *Ppuftph->UFTPHhome='/';				//set home:root to avoid ufullpath call uftphomesub from uftpgetcwd/uftpgethome//~v6daR~
#endif                                                             //~v6daI~
//  Ppuftph->UFTPHflag&=~UFTPHFPSFTP;	//it may be set by "#@SSH=all" inxehosts//~v6d1I~//~v6D0R~
    Ppuftph->UFTPHflag&=~(ULONG)UFTPHFPSFTP;	//it may be set by "#@SSH=all" inxehosts//~v6D0I~
    pc=Plinedata;                                                  //~v6d1R~
    pc+=strspn(pc,"\t ");                                          //~v6d1R~
//  len=strlen(pc);                                                //~v6n0R~
    *Ppnextdata=pc;                                                //~v6d1R~
    UstrncpyZ(Ppuftph->UFTPHshare,pc,sizeof(Ppuftph->UFTPHshare)); //~v6d1R~
#endif                                                             //~v6d7M~
    return rc;                                                     //~v6d1R~
}//ftp3setsmb                                                      //~v6d1R~
//**************************************************************** //~v6d1I~
//set share option by xehostrecord option                          //~v6d1I~
//**************************************************************** //~v6d1I~
int uftp3smb_setcmd(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pchp1,char *Pchp2,int Pint1,int Pint2)//~v6d1I~
{                                                                  //~v6d1I~
    int rc=0,cmdid,pathlen;                                        //~v6d1R~
//  char fnmenclose[_MAX_PATH+8],*pfnm;                            //~v6d1R~//~v6H3R~
//  char fnmenclose2[_MAX_PATH+8];                                 //~v6d1I~//~v6H3R~
    char fnmenclose[FTP_MAXPATH+8],*pfnm;                          //~v6H3I~
    char fnmenclose2[FTP_MAXPATH+8];                               //~v6H3I~
//***********************                                          //~v6d1I~
    if (!(Ppuftph->UFTPHflag & UFTPHFINITCHK))                     //~v6d1I~
    	uftp3smb_nodeinit(Ppuftph);                                //~v6d1I~
    if (Popt &  F3SMBO_NFMSG)                                      //~v6d1I~
    	Ppuftph->UFTPHflag|=UFTPHFNFMSG;                           //~v6d1I~
    cmdid=Popt & F3SMBO_CMDMASK;                                   //~v6d1R~
    uftp3smb_enclosefnm(0,Ppuftph,fnmenclose,Pchp1);                       //~v6d1R~//~v6d7R~
    pfnm=fnmenclose;                                               //~v6d1R~
    switch(cmdid)                                                  //~v6d1I~
    {                                                              //~v6d1I~
    case UFTPSMBCMD_DIR:                                           //~v6d1R~
    	sprintf(Pcmd,"%s %s",Ppuftph->UFTPHlscmd,pfnm);            //~v6d1R~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_STAT:                                          //~v6d1I~
    	sprintf(Pcmd,"%s %s",SMB_CMD_STAT,pfnm);                   //~v6d1R~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_MKDIR:                                         //~v6d1I~
    	if (Pint1)                                                 //~v6d1I~
        {                                                          //~v6d1I~
            if (IS_NOUNIXEXT(Ppuftph))                             //~v6d1I~
            {                                                      //~v6d1I~
                uerrmsg("Mode is not supported on this node",0);   //~v6d1I~
                rc=ENOSYS;                                         //~v6d1I~
            }                                                      //~v6d1I~
            else                                                   //~v6d1I~
    			sprintf(Pcmd,"%s %s 0%o",SMB_CMD_MKDIR_POSIX,pfnm,Pint1);//~v6d1R~
        }                                                          //~v6d1I~
        else                                                       //~v6d1I~
    		sprintf(Pcmd,"%s %s",SMB_CMD_MKDIR,pfnm);              //~v6d1R~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_RMDIR:                                         //~v6d1I~
    	sprintf(Pcmd,"rmdir %s",pfnm);                             //~v6d1I~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_DELETE:                                        //~v6d1I~
        if ((pathlen=PATHLEN(Pchp1))>0)    //contains path         //~v6d1R~
        {                                                          //~v6d1I~
//      	UmemcpyZ(fnmenclose2,Pchp1,pathlen);                   //~v6d1I~//~v6D0R~
        	UmemcpyZ(fnmenclose2,Pchp1,(size_t)pathlen);           //~v6D0I~
		    uftp3smb_enclosefnm(0,Ppuftph,fnmenclose,fnmenclose2);         //~v6d1I~//~v6d7R~
		    uftp3smb_enclosefnm(0,Ppuftph,fnmenclose2,Pchp1+pathlen);      //~v6d1I~//~v6d7R~
    		sprintf(Pcmd,"cd %s;del %s",fnmenclose,fnmenclose2);   //~v6d1I~
        }                                                          //~v6d1I~
        else                                                       //~v6d1I~
    		sprintf(Pcmd,"del %s",pfnm);                           //~v6d1R~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_RENAME:                                        //~v6d1I~
	    uftp3smb_enclosefnm(0,Ppuftph,fnmenclose2,Pchp2);                  //~v6d1I~//~v6d7R~
    	sprintf(Pcmd,"rename %s %s",pfnm,fnmenclose2);             //~v6d1I~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_CHMOD:                                         //~v6d1I~
        if (IS_NOUNIXEXT(Ppuftph))                                 //~v6d1I~
        {                                                          //~v6d1I~
            uerrmsg("chmod is not supported on this node",0);      //~v6d1I~
            rc=ENOSYS;                                             //~v6d1I~
        }                                                          //~v6d1I~
        else                                                       //~v6d1I~
            sprintf(Pcmd,"chmod 0%o %s",Pint1,pfnm);               //~v6d1R~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_SETMOD:        //+/-rsha                       //~v6d7I~
        sprintf(Pcmd,"setmod %s %s",pfnm,Pchp2);                   //~v6d7I~
        break;                                                     //~v6d7I~
    default:                                                       //~v6d1R~
    	rc=4;                                                      //~v6d1I~
    }                                                              //~v6d1I~
    return rc;                                                     //~v6d1I~
}//ftp3smb_setcmd                                                  //~v6d1I~
//**********************************************************************//~v6d1M~
// edit smbclient cmdline                                          //~v6d1M~
//**********************************************************************//~v6d1M~
int uftp3smb_editcmdline(int Popt,PUFTPHOST Ppuftph,char *Pftpcmd,char *Psmbcmdline,char *Pcmdstdin)//~v6d1R~
{                                                                  //~v6d1M~
	char *pc,*pc2,*pswd;                                           //~v6d1R~
    char wkpswd[FTP_PSWDNAMELEN+FTP_USERNAMELEN+8];                //~v6d1M~
    char wkcmd[MAX_SMBCMD*2];                                      //~v6d1R~
    int setpswd;                                                   //~v6d1R~
    char *allstderr="-E -d 1";                                     //~v6d1R~
//********************                                             //~v6d1M~
	pswd=Ppuftph->UFTPHpswd;                                       //~v6d1M~
	if (*pswd)                                                     //~v6d1M~
    {                                                              //~v6d1I~
    	sprintf(wkpswd,"-U %s%%%s",Ppuftph->UFTPHuser,pswd);       //~v6d1R~
        setpswd=1;                                                 //~v6d1I~
    }                                                              //~v6d1I~
    else                                                           //~v6d1M~
    {                                                              //~v6d1I~
    	sprintf(wkpswd,"-U %s -N",Ppuftph->UFTPHuser);             //~v6d1R~
        setpswd=1;                                                 //~v6d1I~
    }                                                              //~v6d1I~
    pswd=wkpswd;                                                   //~v6d1M~
    if (Popt & F3SMBO_STDIN)                                       //~v6d1R~
    {                                                              //~v6d1I~
        if (Pftpcmd)	//multi cmd has not cmd                    //~v6d1I~
    		UstrncpyZ(Pcmdstdin,Pftpcmd,MAX_SMBCMD);               //~v6d1R~
        else                                                       //~v6d1I~
    		*Pcmdstdin=0;                                          //~v6d1I~
	    sprintf(wkcmd,                                             //~v6d1I~
    		"smbclient //%s/%s %s %s ",                            //~v6d1R~
			Ppuftph->UFTPHipad,Ppuftph->UFTPHshare,pswd,allstderr);//~v6d1R~
    }                                                              //~v6d1I~
    else                                                           //~v6d1I~
    {                                                              //~v6d1I~
    	memcpy(Pcmdstdin,"-c \"",4);                               //~v6d1I~
        pc=Pcmdstdin+4;                                            //~v6d1I~
        pc+=uftp3smb_editcmdparm(0,Ppuftph,pc,Pftpcmd,MAX_SMBCMD-4-2);     //~v6d1I~//~v6d7R~
    	*pc++='"';                                                 //~v6d1R~
        *pc=0;                                                     //~v6d1I~
	    sprintf(wkcmd,                                             //~v6d1I~
    		"smbclient //%s/%s %s %s %s ",                         //~v6d1R~
			Ppuftph->UFTPHipad,Ppuftph->UFTPHshare,pswd,Pcmdstdin,allstderr);//~v6d1R~
    }                                                              //~v6d1I~
    *(wkcmd+MAX_SMBCMD)=0;                                         //~v6d1R~
    UstrncpyZ(Psmbcmdline,wkcmd,MAX_SMBCMD);                       //~v6d1R~
    if (setpswd)                                                   //~v6d1I~
    {                                                              //~v6d1I~
        pc=strchr(wkcmd,'%');                                      //~v6d1R~
        if (pc)                                                    //~v6d1R~
        {                                                          //~v6d1R~
            pc2=strchr(pc,' ');                                    //~v6d1R~
            if (pc2)                                               //~v6d1R~
//              memset(pc,'*',(ULONG)pc2-(ULONG)pc);               //~v6d1R~//~v6hhR~
                memset(pc,'*',(ULPTR)pc2-(ULPTR)pc);               //~v6hhI~
        }                                                          //~v6d1R~
    }                                                              //~v6d1I~
    UTRACEP("smbcmd=%s,logcmd=%s\n",Psmbcmdline,wkcmd);            //~v6d1R~
    uftplog(FTPLOG_REQ|FTPLOG_ADDLF,wkcmd);                        //~v6d1R~
    return 0;                                                      //~v6d1M~
}//uftp3smb_editcmdline                                            //~v6d1R~
//**********************************************************************//~v6d1I~
// node chk for unix extension support, windows node               //~v6d1I~
//**********************************************************************//~v6d1I~
int uftp3smb_nodeinit(PUFTPHOST Ppuftph)                           //~v6d1I~
{                                                                  //~v6d1I~
    char **stdo0;                                                  //~v6d1R~
    int rc,stdoctr;                                                //~v6d1I~
//*********************************                                //~v6d1I~
    Ppuftph->UFTPHflag|=UFTPHFINITCHK;  //protect recursive loop//~v61eR~//~v6d1I~
    rc=uftp3smbcmd(0,Ppuftph,SMB_CMD_STAT " /",&stdo0,&stdoctr,0,0);   //get stdout/stderr//~v6d1R~//~v6d7R~
    if (Gftperr==ENOSYS)                                           //~v6d1I~//~v6d7R~
        SET_NOUNIXEXT(Ppuftph);                                    //~v6d1I~//~v6d7R~
    if (!rc)                                                       //~v6d1I~//~v6d7R~
    {                                                              //~v6d1I~//~v6d7R~
        ufree(stdo0);                                              //~v6d1I~//~v6d7R~
    }                                                              //~v6d1I~//~v6d7R~
    return rc;                                                     //~v6d1I~
}//uftpnodeinit                                                    //~v6d1I~
#ifdef ARMXXE                                                      //~v6daI~
//**********************************************************************//~v6daI~
// node chk for unix extension support, windows node               //~v6daI~
//**********************************************************************//~v6daI~
int uftp3smb_nodetest(int Popt,PUFTPHOST Ppuftph)                  //~v6daI~
{                                                                  //~v6daI~
	int opt=SMBOPT_ASYNC,rc;                                       //~v6daR~
//********************                                             //~v6daI~
    rc=jnismb_nodetest(opt,Ppuftph);                               //~v6daR~
    if (rc==SMBREQRC_BUSY)                                        //~vac6I~//~v6daR~
    	uerrmsgcat("Wait previous request completion",0);      //~vac6I~//~v6daI~
    else                                                           //~v6daI~
    if (rc==SMBREQRC_ASYNC)                                        //~v6daI~
    {                                                              //~v6daI~
    	uerrmsgcat("requested connection test",0);                 //~v6daI~
        rc=0;                                                      //~v6daI~
    }                                                              //~v6daI~
    return rc;                                                     //~v6daI~
}//uftp3smb_nodetest                                               //~v6daI~
#endif                                                             //~v6daI~
//**********************************************************************//~v6d1I~
// interface to usystem_redirect for smbclient cmd                 //~v6d1I~
// stdo is freeed if rc!=0                                         //~v6d1I~
//**********************************************************************//~v6d1I~
int uftp3smbcmd(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char ***Pstdo,int *Pstdoctr,FTPCMD_CALLBACK *Pfunc,void *Ppvoid)//~v6d1R~
{                                                                  //~v6d1I~
    if (!(Ppuftph->UFTPHflag & UFTPHFINITCHK))                     //~v61eR~//~v6d1M~
    	uftp3smb_nodeinit(Ppuftph);                                     //~v61eI~//~v6d1I~
	return uftp3smb_cmd(Popt,Ppuftph,Pcmd,Pstdo,Pstdoctr,Pfunc,Ppvoid,0,0);//~v6d1R~
}                                                                  //~v6d1I~
//**********************************************************************//~v6d1I~
int uftp3smb_cmd(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char ***Pstdo,int *Pstdoctr,FTPCMD_CALLBACK *Pfunc,void *Ppvoid,char ***Pstde,int *Pstdectr)//~v6d1R~
{                                                                  //~v6d1I~
	int rc,stdoctr,sysopt,opt,offs,stdectr,len,stdoctrerr,msgopt;  //~v6d1R~
    char **pstdo;                                              //~v6d1R~//~v6d7R~
    char **pstde,**pstdoerr=0;                                     //~v6h7R~
//  char smbcmdline[MAX_SMBCMD+_MAX_PATH+4];                       //~v6d1R~//~v6H3R~
    char smbcmdline[MAX_SMBCMD+FTP_MAXPATH+4];                     //~v6H3I~
    char tempfnm[_MAX_PATH];                                       //~v6d1I~
    char ftpcmd[MAX_SMBCMD];                                       //~v6d1I~
    FILE *fh;                                                      //~v6d1I~
//********************                                             //~v6d1I~
	if (Pstdo)                                                     //~v6d1I~
    	*Pstdo=0;                                                  //~v6d1I~
	if (Pstdoctr)                                                  //~v6d1I~
    	*Pstdoctr=0;                                               //~v6d1I~
	if (Pstde)                                                     //~v6d1I~
    	*Pstde=0;                                                  //~v6d1I~
	if (Pstdectr)                                                  //~v6d1I~
    	*Pstdectr=0;                                               //~v6d1I~
    msgopt=(Ppuftph->UFTPHflag & UFTPHFNFMSG)?F3SMBO_NFMSG:0;      //~v6d1I~
//  Ppuftph->UFTPHflag&=~UFTPHFNFMSG;                              //~v6d1I~//~v6D0R~
    Ppuftph->UFTPHflag&=~(ULONG)UFTPHFNFMSG;                       //~v6D0I~
//edit cmdline                                                     //~v6d1I~
	opt=0;                                                         //~v6d1I~
	if (Pfunc)                                                     //~v6d1I~
    	opt|=F3SMBO_STDIN;                                         //~v6d1R~
	uftp3smb_editcmdline(opt,Ppuftph,Pcmd,smbcmdline,ftpcmd);      //~v6d1R~
//setup stdin file                                                 //~v6d1I~
    if (Pfunc)  //multi-cmd,use stdon redirect                     //~v6d1I~
    {                                                              //~v6d1I~
        utempnam("","uftp_",tempfnm);   // TEMP= or /tmp           //~v6d1I~
        fh=fopen(tempfnm,"w");                                     //~v6d1I~
        if (!fh)                                                   //~v6d1I~
        {                                                          //~v6d1I~
            ufileapierr("ftp stdin temp file fopen",tempfnm,errno);//~v6d1I~
            return 8;                                              //~v6d1I~
        }                                                          //~v6d1I~
        if (*ftpcmd)                                               //~v6d1I~
        	fprintf(fh,"%s\n",ftpcmd);                             //~v6d1R~
    	rc=Pfunc(fh,Ppvoid);                                       //~v6d1I~
    	fclose(fh);                                                //~v6d1I~
	    if (rc)                                                    //~v6d1I~
    		return rc;		//callback rc                          //~v6d1I~
//      len=strlen(smbcmdline);                                    //~v6d1I~//~v6D0R~
        len=(int)strlen(smbcmdline);                               //~v6D0I~
        sprintf(smbcmdline+len," < %s",tempfnm);    //input from file//~v6d1R~
    }                                                              //~v6d1I~
    sysopt=UPROC_NOOKMSG;                                          //~v6d1I~
#ifdef UNX                                                         //~v6d1I~
//  sysopt|=UPROC_LANGC;                                           //~v6EuR~
#endif                                                             //~v6d1I~
#if defined(AIX) || defined(W32)                                   //~v6d1I~
    if (Ppuftph->UFTPHflag & UFTPHFEUC)                            //~v6d1I~
    	sysopt|=UPROC_CVE2S;	//stdout sjis<-euc conv            //~v6d1I~
#endif                                                             //~v6d1I~
#ifdef LNX                                                         //~v6d1I~
    if (Ppuftph->UFTPHflag & UFTPHFSJIS)                           //~v6d1I~
    	sysopt|=UPROC_CVS2E;	//stdout sjis->euc conv            //~v6d1I~
#endif                                                             //~v6d1I~
//    if (UFTPHISPSFTP(Ppuftph))                                   //~v6d1I~
//        sysopt|=UPROC_STDE2O;   //redirect stderr to stdout      //~v6d1R~
    IFDEF_WINCON(sysopt|=UPROC_KEEPMODE);	//keep consolemode     //~v6d1I~
    rc=usystem_redirect(sysopt,smbcmdline,&pstdo,&pstde,&stdoctr,&stdectr);//~v6d1R~
    if (rc>1)                                                      //~v6d1I~
    	return rc;                                                 //~v6d1I~
    if (Pfunc)  //multi-cmd,use stdon redirect                     //~v6d1I~
    	uremovenomsg(tempfnm);        //del tempfile               //~v6d1R~
    if (stdectr)                                                   //~v6d1I~
    {                                                              //~v6d1I~
    	opt=0;                                                     //~v6d1I~
        if (Pfunc)                                                 //~v6d1I~
        	opt=CSE_ERRMSG;                                        //~v6d1I~
		rc=uftp3smb_chkstatuserr(opt,Ppuftph,pstde,stdectr,&pstdoerr,&stdoctrerr,&offs);//log stderr//~v6d1R~
    }                                                              //~v6d1I~
//    if (rc<4)                                                    //~v6d1R~
//    {                                                            //~v6d1R~
//        opt=F3SMBO_LOG|F3SMBO_ERRCHK;   //log all response       //~v6d1R~
//        rc=uftp3smb_srchresp(opt,pstdo,stdoctr,0/*key*/,&pstdoerr,&stdoctrerr,&offs);//~v6d1R~
        switch(rc)                                                 //~v6d1R~
        {                                                          //~v6d1R~
        case 0:                                                    //~v6d1R~
            break;                                                 //~v6d1R~
        case 4: //NT_STATUS fund                                   //~v6d1R~
            if (!Pfunc)                                            //~v6d1I~
            {                                                      //~v6d1I~
                if (msgopt||Gftperr!=ERROR_FILE_NOT_FOUND)         //~v6d1R~
                {                                                  //~v6d1I~
            		uerrmsg("smb cmd \"%s\" failed by \"%s\"",0,      //~v6d1R~//~v6d7R~
                	    Pcmd,*pstdoerr);                                 //~v6d1R~//~v6d7R~
            		uftplog(FTPLOG_ERRM|FTPLOG_ADDLF,0); //logging errmsg//~v6d1R~
                }                                                  //~v6d1I~
                if (Gftperr)                                       //~v6d1I~
                    rc=Gftperr;                                    //~v6d1I~
            }                                                      //~v6d1I~
            else                                                   //~v6d1I~
            	rc=0;	//respchk by caller                        //~v6d1I~
            break;                                                 //~v6d1R~
//        }                                                        //~v6d1R~
    }                                                              //~v6d1I~
    if (pstdo)                                                     //~v6d1I~
        ufree(pstdo);                                              //~v6d1I~
    pstdo=pstde;        //by -E option,all msg is written to stderr//~v6d1I~
    stdoctr=stdectr;                                               //~v6d1R~
    if (Pstdo)  //return required                                  //~v6d1I~
      if (rc)                                                      //~v6d1I~
      {                                                            //~v6d1I~
    	ufree(pstdo);                                              //~v6d1I~
        stdoctr=0;                                                 //~v6d1I~
        *Pstdo=0;                                                  //~v6d1I~
      }                                                            //~v6d1I~
      else                                                         //~v6d1I~
        *Pstdo=pstdo;                                              //~v6d1I~
    else                                                           //~v6d1I~
        ufree(pstdo);                                              //~v6d1I~
    if (Pstdoctr)  //return required                               //~v6d1I~
    	*Pstdoctr=stdoctr;                                         //~v6d1I~
//    if (Pstde)  //return required                                //~v6d1R~
//      if (rc)                                                    //~v6d1R~
//      {                                                          //~v6d1R~
//        ufree(pstde);                                            //~v6d1R~
//        stdectr=0;                                               //~v6d1R~
//        *Pstde=0;                                                //~v6d1R~
//      }                                                          //~v6d1R~
//      else                                                       //~v6d1R~
//        *Pstde=pstde;                                            //~v6d1R~
//    else                                                         //~v6d1R~
//        ufree(pstde);                                            //~v6d1R~
//    if (Pstdectr)  //return required                             //~v6d1R~
//        *Pstdectr=stdectr;                                       //~v6d1R~
    return rc;                                                     //~v6d1I~
}//uftp3smb_cmd                                                    //~v6d1R~
//**********************************************************************//~v6d1I~
// initial chk target is window or unix                            //~v6d1I~
//   Domain=[] OS=[] Server=[] on stderr                           //~v6d1I~
//**********************************************************************//~v6d1I~
int uftp3smb_chkstatuserr(int Popt,PUFTPHOST Ppuftph,char **Pstde,int Pstdectr,char ***Ppfound,int *Ppremainctr,int *Ppoffs)//~v6d1R~
{                                                                  //~v6d1I~
	int rc,stdectr,opt;                                            //~v6d1R~
    char **stde,*pline,*pc;                                        //~v6d1R~
//************************                                         //~v6d1I~
    Gftperr=0;                                                     //~v6d1I~
	stde=Pstde;                                                    //~v6d1I~
	stdectr=Pstdectr;                                              //~v6d1R~
    if (stdectr && Ppuftph)                                        //~v6d1I~
    {                                                              //~v6d1I~
    	pline=*stde;                                               //~v6d1I~
    	if (pc=strstr(pline,SMB_OS),pc)                            //~v6d1I~
    		if (strstr(pc,SMB_OS_WIN))                             //~v6d1I~
            {                                                      //~v6d7I~
        		Ppuftph->UFTPHflag|=UFTPHFRWIN;                  //~v6d1I~//~v6d7R~
        		SET_NOUNIXEXT(Ppuftph);                            //~v6d7I~
            }                                                      //~v6d7I~
    }                                                              //~v6d1I~
    opt=F3SMBO_LOG|F3SMBO_ERRCHK;                                  //~v6d1I~
    rc=uftp3smb_srchresp(opt,stde,stdectr,0/*key*/,Ppfound,Ppremainctr,Ppoffs);//~v6d1R~
    if (rc==4)     //NT_STATUS found                               //~v6d1R~
    {                                                              //~v6d1I~
    	pc=**Ppfound;                                              //~v6d1R~
        if (Popt&CSE_ERRMSG)                                       //~v6d1M~
        	uerrmsg("failure by %s",0,                             //~v6d1M~
            		pc);                                           //~v6d1M~
    	pc+=*Ppoffs;                                               //~v6d1I~
        if (strstr(pc,SMB_STAT_NOT_FOUND))                         //~v6d1R~
    		Gftperr=ERROR_FILE_NOT_FOUND;                          //~v6d1I~
        else                                                       //~v6d1I~
        if (strstr(pc,SMB_STAT_NOT_FOUND2))  //no such file        //~v6d1I~
    		Gftperr=ERROR_FILE_NOT_FOUND;                          //~v6d1I~
        else                                                       //~v6d1I~
        if (strstr(pc,SMB_STAT_PATH_ERR))                          //~v6d1R~
        	Gftperr=ERROR_PATH_NOT_FOUND;                          //~v6d1I~
        else                                                       //~v6d1I~
        if (strstr(pc,SMB_STAT_NO_UNIX_EXT))                       //~v6d1I~
        	Gftperr=ENOSYS;      //function not implemented        //~v6d1I~
        else                                                       //~v6J4I~
        if (strstr(pc,SMB_STAT_ACCESS_DENIED))                     //~v6J4I~
        	Gftperr=EACCES;      //13:permission denied            //~v6J4I~
    }                                                              //~v6d1I~
    else                                                           //~v6d1I~
    	rc=0;                                                      //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_chkstatuserr                                           //~v6d1R~
//**********************************************************************//~v6d1I~
// chk cmd resp line                                               //~v6d1I~
//  update line ptr to next of found line if found else no update  //~v6d1I~
// return :0 okstr found, -1:eof, 4: NT_STATUS_errmsg found        //~v6d1R~
//**********************************************************************//~v6d1I~
int uftp3smb_srchresp(int Popt,char **Pstdo,int Pstdoctr,char *Pkey,char ***Ppstdo,int *Ppstdoremainctr,int *Ppoffs)//~v6d1R~
{                                                                  //~v6d1I~
    char **pstdo,*stdo,*pc=0,**stdofound=0,*pc2=0;                 //~v6d1R~
//  int stdoctr,rc,offs=-1,ctrfound,errfound=0;                    //~v6d1R~//~v6diR~
    int stdoctr,rc,offs=-1,ctrfound=0,errfound=0;                  //~v6diI~
//********************                                             //~v6d1I~
	stdoctr=Pstdoctr;                                              //~v6d1I~
	pstdo=Pstdo;                                                   //~v6d1R~
//    if (Pkey)                                                    //~v6d1R~
    	rc=-1;                                                     //~v6d1I~
//    else                                                         //~v6d1R~
//    	rc=0;                                                      //~v6d1R~
    for (;stdoctr>0;stdoctr--,pstdo++)                             //~v6d1I~
    {                                                              //~v6d1I~
    	stdo=*pstdo;                                               //~v6d1I~
        if (Popt & F3SMBO_LOG)                                     //~v6d1I~
        	uftplog(FTPLOG_RESP|FTPLOG_ADDLF,stdo);                //~v6d1R~
        if (Popt & F3SMBO_ERRCHK)                                  //~v6d1I~
        {                                                          //~v6d1I~
	        pc=strstr(stdo,SMB_STAT_NT_STATUS);                    //~v6d1R~
            if (!pc)                                               //~v6d1I~
	        	pc=pc2=strstr(stdo,SMB_STAT_NO_UNIX_EXT);          //~v6d1I~
            if (pc)                                                //~v6d1I~
            {                                                      //~v6d1I~
                if (!errfound)                                     //~v6d1R~
                {                                                  //~v6d1I~
                    errfound=1;                                    //~v6d1R~
                    stdofound=pstdo;                               //~v6d1I~
                    ctrfound=stdoctr;                              //~v6d1I~
                    if (pc2)                                       //~v6d1I~
                    	offs=0;                                    //~v6d1I~
                    else                                           //~v6d1I~
//                  	offs=(ULONG)pc-(ULONG)stdo;                //~v6d1R~//~v6hhR~
//                    	offs=(ULPTR)pc-(ULPTR)stdo;                //~v6hhI~//~v6D0R~
                      	offs=PTRDIFF(pc,stdo);                     //~v6D0I~
	                rc=4;                                          //~v6d1I~
                }                                                  //~v6d1I~
            }                                                      //~v6d1I~
        }                                                          //~v6d1I~
        if (Pkey)	//not NT_STATUS search                         //~v6d1I~
        {                                                          //~v6d1I~
            pc=strstr(stdo,Pkey);                                  //~v6d1R~
            if (pc)                                                //~v6d1R~
            {                                                      //~v6d1R~
                if (!stdofound)                                    //~v6d1R~
                {                                                  //~v6d1R~
                    stdofound=pstdo;                               //~v6d1R~
                    ctrfound=stdoctr;                              //~v6d1R~
//                  offs=(ULONG)pc-(ULONG)stdo+strlen(Pkey);       //~v6d1R~//~v6hhR~
//                  offs=(ULPTR)pc-(ULPTR)stdo+strlen(Pkey);       //~v6hhI~//~v6D0R~
                    offs=PTRDIFF(pc,stdo)+(int)strlen(Pkey);       //~v6D0I~
                    rc=0;                                          //~v6d1R~
                }                                                  //~v6d1R~
            }                                                      //~v6d1R~
        }                                                          //~v6d1I~
        if (stdofound)                                             //~v6d1I~
	        if (!(Popt & (F3SMBO_LOG|F3SMBO_ERRCHK)))              //~v6d1M~
        		break;                                             //~v6d1M~
    }                                                              //~v6d1I~
    *Ppstdo=stdofound;                                             //~v6d1R~
    *Ppstdoremainctr=ctrfound;                                     //~v6d1R~
    *Ppoffs=offs;                                                  //~v6d1I~
//    UTRACEP("uftp3smb_srchresp rc=%d,key=%s,line=%s,offs=%d\n",rc,Pkey,stdo,offs);//~v6d1R~//~v6diR~
    return rc;                                                     //~v6d1I~
}//uftp3smb_srchresp                                               //~v6d1R~
//**********************************************************************//~v6d1I~
//log stderr                                                       //~v6d1I~
//**********************************************************************//~v6d1I~
int uftp3smb_stderrlog(int Popt,char **Pstdo,int Pstdoctr)         //~v6d1I~
{                                                                  //~v6d1I~
    char **pstdo,*stdo;                                            //~v6d1I~
    int stdoctr;                                                   //~v6d1I~
//********************                                             //~v6d1I~
	stdoctr=Pstdoctr;                                              //~v6d1I~
	pstdo=Pstdo;                                                   //~v6d1I~
    for (;stdoctr>0;stdoctr--,pstdo++)                             //~v6d1I~
    {                                                              //~v6d1I~
    	stdo=*pstdo;                                               //~v6d1I~
        uftplog(FTPLOG_RESP|FTPLOG_ADDLF,stdo);                    //~v6d1R~
	    UTRACEP("uftp3smb_logstderr line=%s\n",stdo);              //~v6d1I~
    }                                                              //~v6d1I~
    return 0;                                                      //~v6d1I~
}//uftp3smb_stderrlog                                              //~v6d1I~
//**********************************************************************//~v6d1I~
//*parse ctime                                                     //~v6d1I~
//  "Mon Feb  2 18:21:13 2012"                                     //~v6d1R~
//*rc :4 not valid ls cmd output line                              //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_getdltime(int Popt,char *Pctime,time_t *Pptimet,FDATE *Ppfdate,FTIME *Ppftime)//~v6d1I~
{                                                                  //~v6d1I~
	char *pc;                                                      //~v6d1I~
    int rc=4,len;                                                  //~v6d1R~
    struct tm tm;                                                  //~v6d1I~
//****************************                                     //~v6d1I~
	memset(&tm,0,sizeof(tm));                                      //~v6d1R~
    for(;;)                                                        //~v6d1I~
    {                                                              //~v6d1I~
//    	len=strlen(Pctime);                                        //~v6d1R~//~v6D0R~
      	len=(int)strlen(Pctime);                                   //~v6D0I~
        if (len<SMB_CTIMESZ)                                       //~v6d1R~
        	break;                                                 //~v6d1I~
    	pc=Pctime;                                                 //~v6d1I~
    	pc+=strspn(pc," ");                                        //~v6d1I~
        tm.tm_wday=uftpgetwday(pc);                                //~v6d1R~
        if (tm.tm_wday<0)                                          //~v6d1R~
        	break;                                                 //~v6d1I~
        pc+=4;                                                     //~v6d1R~
		tm.tm_mon=uftpgetmonth(pc);                                //~v6d1R~
        if (!tm.tm_mon)                                            //~v6d1R~
        	break;                                                 //~v6d1I~
        pc+=4;                                                     //~v6d1R~
		tm.tm_mday=atoi(pc);                                       //~v6d1R~
    	pc+=3;                                                     //~v6d1R~
    	tm.tm_hour=atoi(pc);                                       //~v6d1R~
        pc+=3;                                                     //~v6d1I~
    	tm.tm_min=atoi(pc);                                        //~v6d1R~
        pc+=3;                                                     //~v6d1I~
    	tm.tm_sec=atoi(pc);                                        //~v6d1R~
        pc+=3;                                                     //~v6d1I~
        tm.tm_year=atoi(pc);                                       //~v6d1R~
        rc=0;                                                      //~v6d1I~
        break;                                                     //~v6d1I~
    }                                                              //~v6d1I~
    if (!rc)                                                       //~v6d1I~
		uftp3smb_setdltime(Popt,&tm,Pptimet,Ppfdate,Ppftime);      //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_getdltime                                              //~v6d1I~
//**********************************************************************//~v6d1I~
//*parse stat cmd output time                                      //~v6d1I~
//  "2012-02-03 07:18:04                                           //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_getdltimestat(int Popt,char *Pctime,time_t *Pptimet,FDATE *Ppfdate,FTIME *Ppftime)//~v6d1I~
{                                                                  //~v6d1I~
	char *pc;                                                      //~v6d1I~
    int rc=0,len;                                                  //~v6d1R~
    struct tm tm;                                                  //~v6d1I~
#define STATTIMESZ 19                                              //~v6d1I~
//****************************                                     //~v6d1I~
	memset(&tm,0,sizeof(tm));                                      //~v6d1R~
//  len=strlen(Pctime);                                            //~v6d1R~//~v6D0R~
    len=(int)strlen(Pctime);                                       //~v6D0I~
    if (len<SMB_STATTIMESZ)                                        //~v6d1R~
    	rc=4;                                                      //~v6d1I~
    else                                                           //~v6d1I~
    {                                                              //~v6d1I~
        pc=Pctime;                                                 //~v6d1R~
        pc+=strspn(pc," ");                                        //~v6d1R~
        tm.tm_year=atoi(pc);                                       //~v6d1R~
        pc+=5;                                                     //~v6d1R~
        tm.tm_mon=atoi(pc);                                        //~v6d1R~
        pc+=3;                                                     //~v6d1R~
        tm.tm_mday=atoi(pc);                                       //~v6d1R~
        pc+=3;                                                     //~v6d1R~
        tm.tm_hour=atoi(pc);                                       //~v6d1R~
        pc+=3;                                                     //~v6d1R~
        tm.tm_min=atoi(pc);                                        //~v6d1R~
        pc+=3;                                                     //~v6d1R~
        tm.tm_sec=atoi(pc);                                        //~v6d1R~
        uftp3smb_setdltime(Popt,&tm,Pptimet,Ppfdate,Ppftime);      //~v6d1R~
    }                                                              //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_getdltimestat                                          //~v6d1R~
//**********************************************************************//~v6d1I~
//*                                                                //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_setdltime(int Popt,struct tm *Pptm,time_t *Pptimet,FDATE *Ppfdate,FTIME *Ppftime)//~v6d1R~
{                                                                  //~v6d1I~
    struct tm tm;                                                  //~v6d1I~
    time_t tmt;                                                    //~v6d1I~
//****************************                                     //~v6d1I~
	memset(Ppfdate,0,sizeof(FDATE));                               //~v6d1I~
	memset(Ppftime,0,sizeof(FTIME));                               //~v6d1I~
    if (!(Popt & F3SMBO_WIN))                                      //~v6d1I~
    {                                                              //~v6d1I~
    	memcpy(&tm,Pptm,sizeof(tm));                               //~v6d1I~
        tm.tm_year-=1900;                                          //~v6d1I~
        tm.tm_mon-=1;                                              //~v6d1I~
        tm.tm_isdst=-1;                                            //~v6d1I~
        tmt=mktime(&tm);                                           //~v6d1I~
        memcpy(Pptimet,&tmt,sizeof(tmt));                          //~v6d1I~
    }                                                              //~v6d1I~
//  Ppfdate->year=Pptm->tm_year-1980;                              //~v6d1I~//~v6BMR~
//  Ppfdate->year=(USHORT)(Pptm->tm_year-1980);                    //~v6BMI~//~v6D2R~
//  Ppfdate->month=Pptm->tm_mon;                                   //~v6d1I~//~v6BMR~
//  Ppfdate->month=(USHORT)(Pptm->tm_mon);                         //~v6BMI~//~v6D2R~
//  Ppfdate->day=Pptm->tm_mday;                                    //~v6d1I~//~v6BMR~
//  Ppfdate->day=(USHORT)(Pptm->tm_mday);                          //~v6BMI~//~v6D2R~
    ueditsetfdateUSHORT(0,Pptm->tm_year-1980,Pptm->tm_mon,Pptm->tm_mday,Ppfdate);//~v6D2I~
//  Ppftime->hours=Pptm->tm_hour;                                  //~v6d1I~//~v6BMR~
//  Ppftime->hours=(USHORT)(Pptm->tm_hour);                        //~v6BMI~//~v6D2R~
//  Ppftime->minutes=Pptm->tm_min;                                 //~v6d1I~//~v6BMR~
//  Ppftime->minutes=(USHORT)(Pptm->tm_min);                       //~v6BMI~//~v6D2R~
//  Ppftime->twosecs=Pptm->tm_sec/2;                               //~v6d1I~//~v6BMR~
//  Ppftime->twosecs=(USHORT)(Pptm->tm_sec/2);                     //~v6BMI~//~v6D2R~
    ueditsetftimeUSHORT(0,Pptm->tm_hour,Pptm->tm_min,Pptm->tm_sec/2,Ppftime);//~v6D2I~
	return 0;                                                      //~v6d1I~
}//uftp3smb_setdltime                                              //~v6d1I~//~v6D2R~
//**********************************************************************//~v6d1I~
//*parse mode                                                      //~v6d1I~
//* see source4/libcli/raw/rawfile.c                               //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_getmode(int Popt,PUFTPHOST Ppuftph,char *Pattr,ULONG *Ppmode)           //~v6d1R~//~v6d7R~
{                                                                  //~v6d1I~
	int rc=0;                                                      //~v6d1I~
    ULONG mode=0;                                                  //~v6d1I~
    int attr=0;                                                    //~v6d1I~
    char *pc;                                                      //~v6d1I~
    int iswin;                                                     //~v6d7I~
//****************************                                     //~v6d1I~
	iswin=Ppuftph->UFTPHflag & UFTPHFRWIN;                         //~v6d7R~
	for (pc=Pattr;*pc;pc++)                                        //~v6d1I~
    {                                                              //~v6d1I~
    	switch(*pc)                                                //~v6d1I~
        {                                                          //~v6d1I~
        case ' ':                                                  //~v6d1I~
            break;                                                 //~v6d1I~
        case 'D':   //directory                                    //~v6d1I~
            mode=S_IFDIR;                                          //~v6d1I~
            attr|=FILE_DIRECTORY;                                  //~v6d1I~
            break;                                                 //~v6d1I~
        case 'A':   //directory                                    //~v6d7I~
        	if (iswin)                                             //~v6d7I~
            	attr|=FILE_ARCHIVED;                               //~v6d7I~
            break;                                                 //~v6d7I~
        case 'R':                                                  //~v6d7I~
        	if (iswin)                                             //~v6d7I~
            	attr|=FILE_READONLY;                               //~v6d7I~
            break;                                                 //~v6d7I~
        case 'S':                                                  //~v6d7I~
        	if (iswin)                                             //~v6d7I~
            	attr|=FILE_SYSTEM;                                 //~v6d7I~
            break;                                                 //~v6d7I~
        case 'H':                                                  //~v6d7I~
        	if (iswin)                                             //~v6d7I~
            	attr|=FILE_HIDDEN;                                 //~v6d7I~
            break;                                                 //~v6d7I~
        }                                                          //~v6d1I~
    }                                                              //~v6d1I~
    *Ppmode=FILE_SETMODEATTR(mode,attr);    //permission etc       //~v6d1R~
	return rc;                                                     //~v6d1I~
}//uftp3smb_getmode                                                //~v6d1I~
//**********************************************************************//~v6d1I~
//*get dirlist entry count                                         //~v6d1I~
//**********************************************************************//~v6d1I~
int uftp3smb_getdirlistctr(int Popt,PUFTPHOST Ppuftph,char **Pstdo,int Pstdoctr)//~v6d1I~
{                                                                  //~v6d1I~
	int listctr;                                                   //~v6d1I~
//**********************                                           //~v6d1I~
	listctr=max(Pstdoctr-2,0);                                     //~v6d1R~
//*null                                                            //~v6d1I~
//  n blocks of sizze m. l blocks available                        //~v6d1I~
	return listctr;                                                //~v6d1I~
}//uftp3smb_getdirlistctr                                          //~v6d1I~
//**********************************************************************//~v6d1I~
//*parse a line of ls cmd output                                   //~v6d1I~
//samba source3/client/client.c                                    //~v6d1I~
// "  %-30s%7.7s %8.0f  %s"         <-- attr_string asctime()      //~v6d1I~
//  "name     D   size Mon Feb  2 18:21:13 2012"                   //~v6d1I~
//attr string:ENOCrsTNRHSDA (max 13)                               //~v6d1I~
//asctie:"Fri may 11 21:44:53 2011\n"   24+\n                      //~v6d1I~
//*rc :4 not valid ls cmd output line                              //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_getdl1(PUFTPHOST Ppuftph,char *Prec,PUDIRLIST Ppudl)  //~v6d1I~
{                                                                  //~v6d1I~
#define OFFS_TIME (2+SMB_CTIMESZ)                                  //~v6d1R~
    char *pc,*pattr=0,*ptime,*pfname,*pc2;                         //~v6d1R~
    char attr[8];                                                  //~v6d1I~
    int rc=4,len,opt,szlen;                                        //~v6d1R~
    ULONG modeattr;                                                //~v6d1I~
#ifdef W32                                                         //~v6d7I~
    time_t mtime;                                                  //~v6d7R~
#endif                                                             //~v6d7I~
//*********************************                                //~v6d1I~
//  memset(Ppudl,0,UDIRLISTSZ);	//caller init end                                    //~v6d1I~//~v6qaR~
    pfname=Prec+strspn(Prec," ");                                  //~v6d1I~
//  len=strlen(pfname);                                            //~v6d1I~//~v6D0R~
    len=(int)strlen(pfname);                                       //~v6D0I~
    if (!len)                                                      //~v6d1I~
    	return 4;                                                  //~v6d1I~
    ptime=pfname+len-OFFS_TIME;                                    //~v6d1I~
    opt=0;                                                         //~v6d1I~
    if (Ppuftph->UFTPHflag & UFTPHFRWIN)                         //~v6d1R~//~v6d7R~
    	opt|=F3SMBO_WIN;                                           //~v6d1R~
#ifdef W32                                                         //~v6d7I~
    if (uftp3smb_getdltime(opt,ptime,&mtime,&Ppudl->date,&Ppudl->time))//~v6d7I~
#else                                                              //~v6d7I~
    if (uftp3smb_getdltime(opt,ptime,&Ppudl->mtime,&Ppudl->date,&Ppudl->time))//~v6d1R~
#endif                                                             //~v6d7I~
    	return 4;                                                  //~v6d1I~
    *ptime=0;	//for ustrrchr                                     //~v6d1I~
    for(;;)                                                        //~v6d1I~
    {                                                              //~v6d1I~
    	pc=pfname+ustrrspn(pfname," ")+1;                          //~v6d1R~
        *pc=0;                  //endof size                       //~v6d1I~
        pc2=pc;		//end of size                                  //~v6d1I~
    	pc=strrchr(pfname,' ');	//size                             //~v6d1I~
        if (!pc)                                                   //~v6d1R~
        	break;                                                 //~v6d1I~
        pc++;					//size top                         //~v6d1I~
//      szlen=(ULONG)pc2-(ULONG)(pc);                              //~v6d1I~//~v6hhR~
//      szlen=(ULPTR)pc2-(ULPTR)(pc);                              //~v6hhI~//~v6D0R~
        szlen=PTRDIFF(pc2,pc);                                     //~v6D0I~
		Ppudl->size=atol(pc);                                      //~v6d1R~
        szlen=max(8,szlen);                                        //~v6d1I~
        pc=pc2-szlen;	//top of size by sprintf fmt               //~v6d1I~
        pc-=7+1;		//attr top                                 //~v6d1I~
        pattr=attr;                                                //~v6d1I~
        UmemcpyZ(attr,pc,7);                                       //~v6d1I~
        *pc=0;                                                     //~v6d1I~
    	pc=pfname+ustrrspn(pfname," ")+1;                          //~v6d1R~
        *pc=0;                  //end of attr                      //~v6d1I~
        rc=0;                                                      //~v6d1I~
        break;                                                     //~v6d1I~
    }                                                              //~v6d1I~
//**                                                               //~v6d1I~
//  UstrncpyZ(Ppudl->name,pfname,MAXFILENAMEZ);                    //~v6d1I~//~v6J0R~
    uftp_udirlist_setname(0,Ppuftph,Ppudl,pfname,0);               //~v6J0R~
    if (pattr)                                                     //~v6d1I~
    {                                                              //~v6d1I~
    	uftp3smb_getmode(0,Ppuftph,pattr,&modeattr);                       //~v6d1R~//~v6d7R~
    	Ppudl->attr=modeattr;                                      //~v6d1I~
    }                                                              //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_getdl1                                                 //~v6d1I~
//*******************************************************          //~v6d1I~
//*fstat for remote samba shared file                              //~v6d1I~
//* parm Pfpnm should be without nodename                          //~v6d1I~
//* chk path then chk file for path err chk for hidden file(.xxx)  //~v6d1I~
//*******************************************************          //~v6d1I~
unsigned int uftp3smb_fstatudl(int Popt,PUFTPHOST Ppuftph,char *Pfpnm,PUDIRLIST Ppudl)//~v6d1R~
{                                                                  //~v6d1I~
    int rc,pathlen;                                                //~v6d1I~
    int stdoctr;                                                   //~v6d1I~
    char **stdo=0;                                                 //~v6d1R~
    UCHAR ftpcmd[FTP_MAXPATH+128];	//cd then ls -la               //~v6d1I~
    UCHAR pathnm[FTP_MAXPATH];	//cd then ls -la                   //~v6d1I~
//*********************************                                //~v6d1I~
	if (IS_NOUNIXEXT(Ppuftph))                                     //~v6d1R~
		return uftp3smb_fstatudl_byls(Popt,Ppuftph,Pfpnm,Ppudl);   //~v6d1R~
	pathlen=uftpgetpathname(Pfpnm,pathnm,sizeof(pathnm));          //~v6d1I~
//    if (Popt & F3SMBO_PATHOK)                                    //~v6d1R~
//        rc=0;                                                    //~v6d1R~
//    else                                                         //~v6d1R~
//    if (!strcmp(Pfpnm,pathnm))                                   //~v6d1R~
//        rc=0;                                                    //~v6d1R~
//    else                                                         //~v6d1R~
//    {                                                            //~v6d1R~
//        uftp3smb_setcmd(UFTPSMBCMD_STAT,Ppuftph,ftpcmd,pathnm,0/*Pchp2*/,0/*Pint1*/,0/*Pint2*/);//~v6d1R~
//        rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo,&stdoctr,0,0);    //get stdout/stderr//~v6d1R~
//    }                                                            //~v6d1R~
//    if (rc)                                                      //~v6d1R~
//    {                                                            //~v6d1R~
//        rc=ERROR_PATH_NOT_FOUND;                                 //~v6d1R~
//    }                                                            //~v6d1R~
//    else                                                         //~v6d1R~
//    {                                                            //~v6d1R~
//        if (stdo)                                                //~v6d1R~
//            ufree(stdo);                                         //~v6d1R~
		if (IS_NOUNIXEXT(Ppuftph))                                 //~v6d1I~
        {                                                          //~v6d1I~
//        	rc=uftp3smb_fstatudl_byls(Popt,Ppuftph,Pfpnm,Ppudl);   //~v6d1I~//~v6D0R~
          	rc=(int)uftp3smb_fstatudl_byls(Popt,Ppuftph,Pfpnm,Ppudl);//~v6D0I~
        }                                                          //~v6d1I~
        else                                                       //~v6d1I~
        {                                                          //~v6d1I~
            uftp3smb_setcmd(UFTPSMBCMD_STAT|F3SMBO_NFMSG,Ppuftph,ftpcmd,Pfpnm,0/*Pchp2*/,0/*Pint1*/,0/*Pint2*/);//~v6d1R~
            rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo,&stdoctr,0,0);    //get stdout/stderr//~v6d1R~
            if (rc)                                                //~v6d1R~
            {                                                      //~v6d1R~
                if (Gftperr==ERROR_PATH_NOT_FOUND)                 //~v6d1R~
                    rc=ERROR_PATH_NOT_FOUND;                       //~v6d1R~
                else                                               //~v6d1R~
                if (Gftperr==ENOSYS)                               //~v6d1R~
                {                                                  //~v6d1R~
                    rc=ENOSYS;                                     //~v6d1R~
                    SET_NOUNIXEXT(Ppuftph);                        //~v6d1I~
//                  rc=uftp3smb_fstatudl_byls(Popt,Ppuftph,Pfpnm,Ppudl);//~v6d1R~//~v6D0R~
                    rc=(int)uftp3smb_fstatudl_byls(Popt,Ppuftph,Pfpnm,Ppudl);//~v6D0I~
                }                                                  //~v6d1R~
                else                                               //~v6d1R~
                if (Gftperr)                                       //~v6J4I~
                    rc=Gftperr;                                    //~v6J4I~
                else                                               //~v6J4I~
                    rc=ERROR_FILE_NOT_FOUND;                       //~v6d1R~
            }                                                      //~v6d1R~
            else                                                   //~v6d1R~
                rc=uftp3smb_fstatoutchk(0,Ppuftph,Pfpnm+pathlen,Ppudl,stdo,stdoctr);//~v6d1R~
        }                                                          //~v6d1I~
//    }                                                            //~v6d1R~
    if (stdo)                                                      //~v6d1I~
	    ufree(stdo);                                               //~v6d1I~
//    if (!rc)                                                     //~v6d1R~
//        if (!(Popt & FTPSUD_SLINK))     //not recursive call from ufgetslinkattr//~v6d1R~
//            uftpgetslinkattr(Ppuftph,pathnm,Ppudl);              //~v6d1R~
//no inforamation to slink target is gottoen by smbclient cmd      //~v6d1I~
//  return rc;                                                     //~v6d1R~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0I~
}//uftp3smb_fstatudl                                               //~v6d1R~//~v6qaR~
//*******************************************************          //~v6d1I~
//*fstat for remote samba shared file by ls cmd                    //~v6d1I~
//*******************************************************          //~v6d1I~
unsigned int uftp3smb_fstatudl_byls(int Popt,PUFTPHOST Ppuftph,char *Pfpnm,PUDIRLIST Ppudl)//~v6d1R~
{                                                                  //~v6d1I~
    int rc,pathlen;                                                //~v6d1I~
    int stdoctr;                                                   //~v6d1I~
    char **stdo=0;                                                 //~v6d1I~
    UCHAR ftpcmd[FTP_MAXPATH+128];	//cd then ls -la               //~v6d1I~
    UCHAR pathnm[FTP_MAXPATH];	//cd then ls -la                   //~v6d1I~
//*********************************                                //~v6d1I~
    if (ROOTDIR(Pfpnm))	//when root,dir list is gotten widthout "/*" parm//~v6d1I~
		return uftp3smb_fstatudl_byls_root(Popt,Ppuftph,Ppudl);    //~v6d1R~
	pathlen=uftpgetpathname(Pfpnm,pathnm,sizeof(pathnm));          //~v6d1I~
    uftp3smb_setcmd(UFTPSMBCMD_DIR,Ppuftph,ftpcmd,Pfpnm,0/*Pchp2*/,0/*Pint1*/,0/*Pint2*/);//~v6d1R~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo,&stdoctr,0,0);    //get stdout/stderr//~v6d1I~
    if (rc)                                                        //~v6d1I~
    {                                                              //~v6d1I~
        if (Gftperr==ERROR_PATH_NOT_FOUND)                         //~v6d1I~
            rc=ERROR_PATH_NOT_FOUND;                               //~v6d1I~
        else                                                       //~v6d1I~
            rc=ERROR_FILE_NOT_FOUND;                               //~v6d1I~
    }                                                              //~v6d1I~
    else                                                           //~v6d1I~
//      rc=uftp3smb_lsoutchk(0,Ppuftph,Pfpnm+pathlen,stdo,stdoctr,Ppudl);//~v6d1R~//~v6D0R~
        rc=(int)uftp3smb_lsoutchk(0,Ppuftph,Pfpnm+pathlen,stdo,stdoctr,Ppudl);//~v6D0I~
    if (stdo)                                                      //~v6d1I~
	    ufree(stdo);                                               //~v6d1I~
//  return rc;                                                     //~v6d1I~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0I~
}//uftp3sme_fstatudl_byls                                          //~v6d1R~
//*******************************************************          //~v6d1I~
//*fstat for remote samba shared file by ls cmd                    //~v6d1I~
//*******************************************************          //~v6d1I~
unsigned int uftp3smb_fstatudl_byls_root(int Popt,PUFTPHOST Ppuftph,PUDIRLIST Ppudl)//~v6d1I~
{                                                                  //~v6d1I~
    int rc=0;                                                      //~v6d7R~
    int swrootcd=0;                                                //~v6d7M~
#ifdef W32                                                         //~v6d7I~
#else                                                              //~v6d7I~
    int stdoctr,ii;                                                //~v6d1R~
    char **stdo,**stdo0,*pc;                                       //~v6d1R~
    UCHAR ftpcmd[128];                                             //~v6d1I~
#endif                                                             //~v6d7I~
//*********************************                                //~v6d1I~
//  memset(Ppudl,0,sizeof(UDIRLIST));	//already init                              //~v6d1I~//~v6qaR~
#ifdef W32                                                         //~v6d7I~
#else                                                              //~v6d7I~
    if (Ppuftph->UFTPHroot_mtime)                                  //~v6d1I~
    {                                                              //~v6d1I~
//      *Ppudl->name='/';                                          //~v6d1R~//~v6J0R~
        uftp_udirlist_setname(0,Ppuftph,Ppudl,"/",0);              //~v6J0R~
        Ppudl->mtime=Ppuftph->UFTPHroot_mtime;                     //~v6d1I~
        Ppudl->attr=Ppuftph->UFTPHroot_attr;                       //~v6d1R~
        Ppudl->date=Ppuftph->UFTPHroot_date;                       //~v6d1R~
        Ppudl->time=Ppuftph->UFTPHroot_time;                       //~v6d1R~
        return 0;                                                  //~v6d1I~
    }                                                              //~v6d1I~
    uftp3smb_setcmd(UFTPSMBCMD_DIR,Ppuftph,ftpcmd,"/",0/*Pchp2*/,0/*Pint1*/,0/*Pint2*/);//~v6d1I~
    rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);    //get stdout/stderr//~v6d1I~
    if (!rc)                                                       //~v6d1I~
    {                                                              //~v6d1I~
        for (ii=0,stdo=stdo0;ii<stdoctr;stdo++,ii++)               //~v6d1I~
        {                                                          //~v6d1I~
            pc=*stdo;                                              //~v6d1I~
            pc+=strspn(pc," ");                                    //~v6d1I~
            if (*pc=='.' && *(pc+1)==' ')                          //~v6d1R~
            {                                                      //~v6d1I~
				rc=uftp3smb_getdl1(Ppuftph,pc,Ppudl);              //~v6d1I~
    			swrootcd=1;	// "." found(Windows dose not set "."/".." entry//~v6d1I~
                break;                                             //~v6d1I~
            }                                                      //~v6d1I~
        }                                                          //~v6d1I~
    }                                                              //~v6d1I~
    if (stdo0)                                                     //~v6d1I~
	    ufree(stdo0);                                              //~v6d1I~
    if (!rc)                                                       //~v6d1I~
    {                                                              //~v6d1I~
        Ppuftph->UFTPHroot_mtime=Ppudl->mtime;                     //~v6d1R~
        Ppuftph->UFTPHroot_attr=Ppudl->attr;                       //~v6d1R~
        Ppuftph->UFTPHroot_date=Ppudl->date;                       //~v6d1R~
        Ppuftph->UFTPHroot_time=Ppudl->time;                       //~v6d1R~
    }                                                              //~v6d1I~
#endif                                                             //~v6d7I~
    if (!swrootcd)	//Windows dose not set "." entry for root      //~v6d1I~
    {                                                              //~v6d1I~
//      *Ppudl->name='/';                                          //~v6d1I~//~v6J0R~
        uftp_udirlist_setname(0,Ppuftph,Ppudl,"/",0);              //~v6J0R~
        Ppudl->attr=FILE_SETMODEATTR(S_IFDIR,FILE_DIRECTORY);	//minimum required//~v6d1I~
    }                                                              //~v6d1I~
//  return rc;                                                     //~v6d1I~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0I~
}//uftp3sme_fstatudl_byls_root                                     //~v6d1I~
//*******************************************************          //~v6d1I~
//*fill udrilist by dir cmd output                                 //~v6d1I~
//*******************************************************          //~v6d1I~
unsigned int uftp3smb_lsoutchk(int Popt,PUFTPHOST Ppuftph,char *Pfname,char **Pstdo,int Pstdoctr,PUDIRLIST Ppudl)//~v6d1R~
{                                                                  //~v6d1I~
    int rc=ENOENT;                                                 //~v6d1I~
    int ii;                                                        //~v6d1R~
    char **stdo;                                                   //~v6d1I~
//  UDIRLIST udl;                                                  //~v6d1I~//~v6qaR~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //~v6J0I~
//*********************************                                //~v6d1I~
//  UDIRLIST_WK_INIT(udl,wkslinkname);                             //~v6qaI~//~v6J0R~
    UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);              //~v6J0I~
    for (ii=0,stdo=Pstdo;ii<Pstdoctr;stdo++,ii++)                  //~v6d1I~
    {                                                              //~v6d1I~
        if (uftp3smb_getdl1(Ppuftph,*stdo,&udl))                   //~v6d1I~
            continue;                                              //~v6d1I~
		if (uftp3smb_strfname(F3SMBO_MEMBCMP,Ppuftph,udl.name,Pfname))//~v6d1I~
        {                                                          //~v6d1I~
            UTRACED("old Ppudl",Ppudl,UDIRLISTSZ);                 //~v6J4I~
            UTRACEP("%s:Old otherflag=%x,name=%p=%s,short=%s,pslink=%p=%s\n",UTT,Ppudl->otherflag,Ppudl->name,Ppudl->name,Ppudl->nameShortbuff,Ppudl->pslink,Ppudl->pslink);//~v6J4I~
//        	memcpy(Ppudl,&udl,sizeof(udl));                        //~v6d1R~//~v6J4R~
			UDIRLIST_COPY(Ppudl,&udl);		//this is work to work //~v6J4I~
            UTRACEP("%s:New otherflag=%x,name=%p=%s,short=%s,pslink=%p=%s\n",UTT,Ppudl->otherflag,Ppudl->name,Ppudl->name,Ppudl->nameShortbuff,Ppudl->pslink,Ppudl->pslink);//~v6J4R~
            UTRACED("new Ppudl",Ppudl,UDIRLISTSZ);                 //~v6J4I~
        	rc=0;                                                  //~v6d1I~
        	break;                                                 //~v6d1I~
        }                                                          //~v6d1I~
    }                                                              //~v6d1I~
//  return rc;                                                     //~v6d1I~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0I~
}//uftp3smb_lsoutchk                                               //~v6d1I~
#ifdef AAA                                                         //~v6d1I~
//*******************************************************          //~v6d1I~
//*set udilist attr by stat cmd                                    //~v6d1I~
//*fpath name has no node prefix                                   //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_getdlattr(int Popt,PUFTPHOST Ppuftph,char *Pfpath,int Ppathlen,PUDIRLIST Ppudl,int Pfileno)//~v6d1R~
{                                                                  //~v6d1I~
	int ii,rc=0,rc2,pathlen;                                       //~v6d1R~
    char fpath[_MAX_PATH],*fnm;                                    //~v6d1R~
    char fpath2[_MAX_PATH],*fnm2;                                  //~v6d1I~
//  UDIRLIST udl,*pudl;                                            //~v6d1R~//~v6qaR~
    UDIRLIST *pudl;                                                //~v6qaI~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //~v6J0I~
//****************************                                     //~v6d1I~
	if (IS_NOUNIXEXT(Ppuftph))                                     //~v6d1I~
        return ENOSYS;    //stat not supported if "unix extension=no" on smb.conf//~v6d1I~
    pathlen=Ppathlen;                                              //~v6d1I~
	memcpy(fpath,Pfpath,pathlen);                                  //~v6d1I~
	for (ii=0,pudl=Ppudl;ii<Pfileno;ii++,pudl++)                   //~v6d1I~
    {                                                              //~v59dM~//~v6d1I~
    	fnm=pudl->name;                                            //~v6d1I~
    	if (!*fnm)                                                 //~v6d1R~
        	continue;                                              //~v6d1I~
        fnm2=fpath;                                                //~v6d1I~
        if  (*fnm=='.')                                            //~v6d1R~
        {                                                          //~v6d1I~
            if  (!*(fnm+1))   //"stat ./" fail by NT_STATUS_OBJECT_NAME_INVALID//~v6d1I~
            {                                                      //~v6d1I~
            	UmemcpyZ(fpath2,Pfpath,Ppathlen);                  //~v6d1I~
                fnm2=fpath2;                                       //~v6d1R~
            }                                                      //~v6d1I~
            else                                                   //~v6d1I~
            if  (*(fnm+1)=='.' && !*(fnm+2))	//..               //~v6d1I~
            {                                                      //~v6d1I~
                if (Ppathlen==1)    //root                         //~v6d1I~
                    continue;                                      //~v6d1I~
            	UmemcpyZ(fpath2,Pfpath,Ppathlen);                  //~v6d1I~
            	strcat(fpath2,"../");                              //~v6d1R~
                fnm2=fpath2;                                       //~v6d1R~
            }                                                      //~v6d1I~
        }                                                          //~v6d1I~
        if (fnm2!=fpath2)                                          //~v6d1I~
        {                                                          //~v6d1I~
        	strcpy(fpath+Ppathlen,fnm);                            //~v6d1R~
        }                                                          //~v6d1I~
		rc2=uftp3smb_fstatudl(0,Ppuftph,fnm2,&udl);                //~v6d1R~
        if (rc2)                                                   //~v6d1I~
        {                                                          //~v6d1I~
            if (rc2==ENOSYS)    //stat not supported if "unix extension=no" on smb.conf//~v6d1I~
            {                                                      //~v6d1I~
            	rc=rc2;                                            //~v6d1I~
                break;                                             //~v6d1I~
            }                                                      //~v6d1I~
            rc=4;                                                  //~v6d1I~
            continue;                                              //~v6d1I~
        }                                                          //~v6d1I~
        pudl->attr|=udl.attr;                                      //~v6d1R~
        pudl->uid=udl.uid;                                         //~v6d1R~
        pudl->gid=udl.gid;                                         //~v6d1R~
	}                                                              //~v59dM~//~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_getdlattr                                              //~v6d1I~
#endif                                                             //~v6d1I~
//*******************************************************          //~v6d1I~
//*set udilist attr by stat cmd all at once in the dir             //~v6d1I~
//*fpath name has no node prefix                                   //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_getdlattr(int Popt,PUFTPHOST Ppuftph,char *Pfpath,int Ppathlen,PUDIRLIST Ppudl,int Pfileno)//~v6d1I~
{                                                                  //~v6d1I~
	int rc,stdoctr;                                                //~v6d1R~
    char **pstdo;                                                  //~v6d1I~
    UFTPPARM uftpp;                                                //~v6d1I~
//****************************                                     //~v6d1I~
	if (IS_NOUNIXEXT(Ppuftph))                                     //~v6d1I~
        return ENOSYS;    //stat not supported if "unix extension=no" on smb.conf//~v6d1I~
    memset (&uftpp,0,sizeof(uftpp));                               //~v6d1R~
    uftpp.UFPpudl=Ppudl;                                           //~v6d1I~
    uftpp.UFPpudlno=Pfileno;                                       //~v6d1I~
    uftpp.UFPpuftph=Ppuftph;                                       //~v6d1I~
    uftpp.UFPspathlen=Ppathlen;                                    //~v6d1I~
    uftpp.UFPsfpath=Pfpath;                                        //~v6d1I~
    if (rc=uftpcmd(Ppuftph,0/*ftpopt*/,0/*cmd*/,&pstdo,&stdoctr,uftp3smb_fstatdircallback,&uftpp),rc)//~v6d1R~
    {                                                              //~v6d1I~
        if (!uftpp.UFPcmdctr)  //no file entry to be execute       //~v6d1R~
            rc=0;           //ignore callback rc                   //~v6d1I~
    }                                                              //~v6d1I~
    else    //cmd executed                                         //~v6d1I~
    {                                                              //~v6d1I~
        rc=uftp3smb_fstatdirrchk(&uftpp,pstdo,stdoctr);//stdo is freed in the func//~v6d1R~
    }                                                              //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_getdlattr                                              //~v6d1I~
//**************************************************************** //~v6d1I~
//callback func to process file entry                              //~v6d1I~
//*retrn:rc                                                        //~v6d1I~
//**************************************************************** //~v6d1I~
int uftp3smb_fstatdircallback(FILE *Ppfh,void *Ppvoid)             //~v6d1I~
{                                                                  //~v6d1I~
	PUFTPPARM pufp;                                                //~v6d1I~
	PUDIRLIST pudl;                                                //~v6d1R~
	PUFTPHOST puftph;                                              //~v6d1I~
    int rc=0,pudlctr,ii,pathlen,filectr=0;                         //~v6d1R~
//  char fpath[_MAX_PATH],*fnm,*dirfpath;                          //~v6d1R~//~v6H3R~
//  char fpath2[_MAX_PATH],*fnm2;                                  //~v6d1I~//~v6H3R~
    char fpath[FTP_MAXPATH],*fnm,*dirfpath;                        //~v6H3I~
    char fpath2[FTP_MAXPATH],*fnm2;                                //~v6H3R~
//***********************************                              //~v6d1I~
	pufp=(PUFTPPARM)Ppvoid;                                        //~v6d1I~
    puftph=pufp->UFPpuftph;                                        //~v6d1I~
    pudl=pufp->UFPpudl;                                            //~v6d1R~
    pudlctr=pufp->UFPpudlno;                                       //~v6d1I~
    pathlen=pufp->UFPspathlen;                                     //~v6d1I~
    dirfpath=pufp->UFPsfpath;                                      //~v6d1I~
//  memcpy(fpath,dirfpath,pathlen);                                //~v6d1I~//~v6D0R~
    memcpy(fpath,dirfpath,(size_t)pathlen);                        //~v6D0I~
//    uftp3smb_putstmt(UFTPSMBCMD_STATDIR,puftph,Ppfh,0/*parm1*/,0/*parm2*/);//~v6d1R~
	for (ii=0;ii<pudlctr;ii++,pudl++)                              //~v6d1R~
    {                                                              //~v6d1I~
    	fnm=pudl->name;                                            //~v6d1I~
    	if (!*fnm)                                                 //~v6d1I~
        	continue;                                              //~v6d1I~
        fnm2=fpath;	//create fpath                                 //~v6d1I~
        if  (*fnm=='.')                                            //~v6d1I~
        {                                                          //~v6d1I~
            if  (!*(fnm+1))   //"stat ./" fail by NT_STATUS_OBJECT_NAME_INVALID//~v6d1I~
            {                                                      //~v6d1I~
                if (pathlen==1)                                    //~v6d1I~
//          		UmemcpyZ(fpath2,dirfpath,pathlen);             //~v6d1I~//~v6D0R~
            		UmemcpyZ(fpath2,dirfpath,(size_t)pathlen);     //~v6D0I~
                else                                               //~v6d1I~
//          		UmemcpyZ(fpath2,dirfpath,pathlen-1);           //~v6d1R~//~v6D0R~
            		UmemcpyZ(fpath2,dirfpath,(size_t)pathlen-1);   //~v6D0I~
                fnm2=fpath2;                                       //~v6d1I~
            }                                                      //~v6d1I~
            else                                                   //~v6d1I~
            if  (*(fnm+1)=='.' && !*(fnm+2))	//..               //~v6d1I~
            {                                                      //~v6d1I~
                if (pathlen==1)    //root                          //~v6d1R~
                    continue;                                      //~v6d1I~
            }                                                      //~v6d1I~
        }                                                          //~v6d1I~
        if (fnm2!=fpath2)                                          //~v6d1I~
        {                                                          //~v6d1I~
        	strcpy(fpath+pathlen,fnm);                             //~v6d1I~
        }                                                          //~v6d1I~
		uftp3smb_putstmt(UFTPSMBCMD_STAT,puftph,Ppfh,fnm2,0/*2nd opd*/);//~v6d1R~
        filectr++;                                                 //~v6d1I~
    }//dir list                                                    //~v6d1I~
    pufp->UFPcmdctr=filectr;                                       //~v6d1I~
    if (!filectr)                                                  //~v6d1I~
    	rc=ENOENT;	//request skip ftp cmd                         //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_fstatdircallback                                       //~v6d1I~
//**************************************************************** //~v6d1I~
//ftp cmd result chk                                               //~v6d1I~
//*retrn:rc                                                        //~v6d1I~
//**************************************************************** //~v6d1I~
int uftp3smb_fstatdirrchk(PUFTPPARM Ppufp,char **Ppstdo,int Pstdoctr)//~v6d1I~
{                                                                  //~v6d1I~
    PUFTPHOST puftph;                                              //~v6d1I~
//  UDIRLIST udl,*pudl;                                            //~v6d1R~//~v6qaR~
    UDIRLIST *pudl;                                                //~v6qaI~
//  UDIRLIST_WK(udl,wkslinkname);                                  //~v6qaI~//~v6J0R~
    UDIRLIST_WK(udl,wkname,wknamew,wkslinkname);                   //~v6J0I~
    int rc=0,rc2,pudlctr,stdoctr,ii,pathlen;                       //~v6d1R~
    char **stdo;                                                   //~v6d1R~
//  char fpath[_MAX_PATH],*fnm,*dirfpath;                          //~v6d1R~//~v6H3R~
//  char fpath2[_MAX_PATH],*fnm2;                                  //~v6d1I~//~v6H3R~
    char fpath[FTP_MAXPATH],*fnm,*dirfpath;                        //~v6H3I~
    char fpath2[FTP_MAXPATH],*fnm2;                                //~v6H3I~
//****************************                                     //~v6d1I~
	puftph=Ppufp->UFPpuftph;                                       //~v6d1I~
    pudlctr=Ppufp->UFPpudlno;                                      //~v6d1I~
    pudl=Ppufp->UFPpudl;                                           //~v6d1R~
    dirfpath=Ppufp->UFPsfpath;                                     //~v6d1R~
    pathlen=Ppufp->UFPspathlen;                                    //~v6d1R~
//  memcpy(fpath,dirfpath,pathlen);                                //~v6d1I~//~v6D0R~
    memcpy(fpath,dirfpath,(size_t)pathlen);                        //~v6D0I~
    stdo=Ppstdo;                                                   //~v6d1I~
	stdoctr=Pstdoctr;                                              //~v6d1I~
//    if (rc=uftp3smb_respchk(UFTPSMBCMD_STATDIR,puftph,dirfpath,&stdo,&stdoctr,ENOENT),rc)//~v6d1R~
//        return rc;                                               //~v6d1R~
//  UDIRLIST_WK_INIT(udl,wkslinkname);                             //~v6qaI~//~v6J0R~
    UDIRLIST_WK_INIT(udl,wkname,wknamew,wkslinkname);              //~v6J0I~
    for (ii=0;ii<pudlctr && stdoctr>0;ii++,pudl++)  //until eof/err//~v6d1R~
    {                                                              //~v6d1I~
    	fnm=pudl->name;                                            //~v6d1I~
    	if (!*fnm)                                                 //~v6d1I~
        	continue;                                              //~v6d1I~
        fnm2=fpath;	//create fpath                                 //~v6d1I~
        if  (*fnm=='.')                                            //~v6d1I~
        {                                                          //~v6d1I~
            if  (!*(fnm+1))   //"stat ./" fail by NT_STATUS_OBJECT_NAME_INVALID//~v6d1I~
            {                                                      //~v6d1I~
                if (pathlen==1)                                    //~v6d1I~
//          		UmemcpyZ(fpath2,dirfpath,pathlen);             //~v6d1I~//~v6D0R~
            		UmemcpyZ(fpath2,dirfpath,(size_t)pathlen);     //~v6D0I~
                else                                               //~v6d1I~
//          		UmemcpyZ(fpath2,dirfpath,pathlen-1);           //~v6d1I~//~v6D0R~
            		UmemcpyZ(fpath2,dirfpath,(size_t)pathlen-1);   //~v6D0I~
                fnm2=fpath2;                                       //~v6d1I~
            }                                                      //~v6d1I~
            else                                                   //~v6d1I~
            if  (*(fnm+1)=='.' && !*(fnm+2))	//..               //~v6d1I~
            {                                                      //~v6d1I~
                if (pathlen==1)    //root                          //~v6d1I~
                    continue;                                      //~v6d1I~
            }                                                      //~v6d1I~
        }                                                          //~v6d1I~
        if (fnm2!=fpath2)                                          //~v6d1I~
        {                                                          //~v6d1I~
        	strcpy(fpath+pathlen,fnm);                             //~v6d1I~
        }                                                          //~v6d1I~
    	if (uftp3smb_respchk(UFTPSMBCMD_STAT|F3SMBO_NFMSG|F3SMBO_RETFOUND,puftph,fnm2,&stdo,&stdoctr,ENOENT))//~v6d1R~
        {                                                          //~v6d1I~
            rc|=ENOENT;                                            //~v6d1I~
            continue;                                              //~v6d1I~
        }                                                          //~v6d1I~
        rc2=uftp3smb_fstatoutchk(0,puftph,fnm2,&udl,stdo,stdoctr); //~v6d1R~
        if (rc2)                                                   //~v6d1I~
        {                                                          //~v6d1I~
            rc|=ENOENT;                                            //~v6d1I~
            continue;                                              //~v6d1I~
        }                                                          //~v6d1I~
        pudl->attr|=udl.attr;                                      //~v6d1I~
#ifdef W32                                                         //~v6d7I~
#else                                                              //~v6d7I~
        pudl->uid=udl.uid;                                         //~v6d1I~
        pudl->gid=udl.gid;                                         //~v6d1I~
#endif                                                             //~v6d7I~
        stdo++;		//next member                                  //~v6d1I~
        stdoctr--;                                                 //~v6d1I~
    }                                                              //~v6d1I~
//    if (rc)                                                        //~v6d1I~//~v6J4R~
//    {                                                              //~v6d1I~//~v6J4R~
//        uerrmsg("get attrribute by stat cmd failed for %s",0,      //~v6d1I~//~v6J4R~
//            dirfpath);                                             //~v6d1R~//~v6J4R~
//    }                                                              //~v6d1I~//~v6J4R~
    ufree(Ppstdo);                                                 //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_fstatdirrchk                                           //~v6d1I~
//*******************************************************          //~v6d1I~
//*set udirlist from stat cmd output                               //~v6d1R~
//*******************************************************          //~v6d1I~
int uftp3smb_fstatoutchk(int Popt,PUFTPHOST Ppuftph,char *Pfname,PUDIRLIST Ppudl,char **Pstdo,int Pstdoctr)//~v6d1R~
{                                                                  //~v6d1I~
    int rc,rc2,offs,opt,mode=0;                                    //~v6d1R~
//  int stdoctr,attr=0,uid,gid;                                      //~v6d1R~//~v6diR~//~v6hcR~
    int stdoctr,attr=0,uid=0,gid=0;                                //~v6hcI~
    char **stdo,*pc;                                               //~v6d1R~
    ULONG sz=0;                                                      //~v6d1I~//~v6diR~
#ifdef W32                                                         //~v6d7I~
    time_t mtime;                                                  //~v6d7I~
#endif                                                             //~v6d7I~
//*********************************                                //~v6d1I~
//  memset(Ppudl,0,sizeof(UDIRLIST));   //already init by caller   //~v6d1I~//~v6qaR~
	stdo=Pstdo;                                                    //~v6d1I~
    stdoctr=Pstdoctr;                                              //~v6d1I~
    opt=0;	//err chk/log write was done                           //~v6d1I~
    rc=FTPRC_PARSEERR;                                             //~v6d1I~
    for (;;)                                                       //~v6d1I~
    {                                                              //~v6d1I~
//Filename                                                         //~v6d1I~
		rc2=uftp3smb_srchresp(opt,stdo,stdoctr,SMB_STAT_FILE,&stdo,&stdoctr,&offs);//~v6d1I~
        if (rc2)                                                   //~v6d1I~
            break;                                                 //~v6d1I~
//Size                                                             //~v6d1I~
		rc2=uftp3smb_srchresp(opt,stdo,stdoctr,SMB_STAT_SIZE,&stdo,&stdoctr,&offs);//~v6d1I~
        if (rc2)                                                   //~v6d1I~
            break;                                                 //~v6d1I~
        pc=*stdo+offs;                                             //~v6d1I~
//      sz=atol(pc);                                               //~v6d1I~//~v6D0R~
        sz=(ULONG)atol(pc);                                        //~v6D0I~
        if (!strstr(pc,SMB_STAT_REGFILE))                          //~v6d1R~
        {                                                          //~v6d1I~
            if (strstr(pc,SMB_STAT_DIR))                           //~v6d1I~
                mode|=S_IFDIR;                                     //~v6d1I~
            else                                                   //~v6d1I~
            if (strstr(pc,SMB_STAT_SLINK))                         //~v6d1R~
                mode|=S_IFLNK;                                     //~v6d1I~
            else                                                   //~v6d1I~
            if (strstr(pc,SMB_STAT_CHARDEV))                       //~v6d1I~
                mode|=S_IFCHR;                                     //~v6d1I~
            else                                                   //~v6d1I~
            if (strstr(pc,SMB_STAT_BLKDEV))                        //~v6d1I~
                mode|=S_IFBLK;                                     //~v6d1I~
            else                                                   //~v6d1I~
            if (strstr(pc,SMB_STAT_FIFO))                          //~v6d1I~
                mode|=S_IFIFO;                                     //~v6d1R~
            else                                                   //~v6d1I~
            if (strstr(pc,SMB_STAT_SOCKET))                        //~v6d1I~
                mode|=S_IFSOCK;                                    //~v6d1I~
        }                                                          //~v6d1I~
//Access                                                           //~v6d1I~
		rc2=uftp3smb_srchresp(opt,stdo,stdoctr,SMB_STAT_ACCESS,&stdo,&stdoctr,&offs);//~v6d1I~
        if (rc2)                                                   //~v6d1I~
            break;                                                 //~v6d1I~
        pc=*stdo+offs;                                             //~v6d1I~
        pc+=strspn(pc," ")+1;	   //Access: (0744/....Uid:500 Gid:500//~v6d1I~
        sscanf(pc,"%o/",&attr);                                    //~v6d1I~
		rc2=uftp3smb_srchresp(opt,stdo,stdoctr,SMB_STAT_UID,&stdo,&stdoctr,&offs);//~v6d1I~
        if (rc2)                                                   //~v6d1I~
            break;                                                 //~v6d1I~
        pc=*stdo+offs;                                             //~v6d1I~
        pc+=strspn(pc," ");                                        //~v6d1I~
//      uid=atol(pc);                                              //~v6d1I~//~v6D1R~
        uid=(int)atol(pc);                                         //~v6D1I~
		rc2=uftp3smb_srchresp(opt,stdo,stdoctr,SMB_STAT_GID,&stdo,&stdoctr,&offs);//~v6d1I~
        if (rc2)                                                   //~v6d1I~
            break;                                                 //~v6d1I~
        pc=*stdo+offs;                                             //~v6d1I~
        pc+=strspn(pc," ");                                        //~v6d1I~
//      gid=atol(pc);                                              //~v6d1I~//~v6D1R~
        gid=(int)atol(pc);                                         //~v6D1I~
//Modified time (Changed time is time of status changed bu such as chmod)//~v6d1R~
		rc2=uftp3smb_srchresp(opt,stdo,stdoctr,SMB_STAT_MODTIME,&stdo,&stdoctr,&offs);//~v6d1I~
        if (rc2)                                                   //~v6d1I~
            break;                                                 //~v6d1I~
        pc=*stdo+offs;                                             //~v6d1I~
        pc+=strspn(pc," ");                                        //~v6d1I~
#ifdef W32                                                         //~v6d7I~
	    uftp3smb_getdltimestat(opt,pc,&mtime,&Ppudl->date,&Ppudl->time);//~v6d7I~
#else                                                              //~v6d7I~
	    uftp3smb_getdltimestat(opt,pc,&Ppudl->mtime,&Ppudl->date,&Ppudl->time);//~v6d1R~
#endif                                                             //~v6d7I~
        rc=0;                                                      //~v6d1I~
        break;                                                     //~v6d1I~
    }//rc chk                                                      //~v6d1I~
//  strcpy(Ppudl->name,Pfname);                                    //~v6d1R~//~v6J0R~
    uftp_udirlist_setname(0,Ppuftph,Ppudl,Pfname,0);               //~v6J0R~
//  Ppudl->size=sz;                                                //~v6d1R~//~v6D1R~
    Ppudl->size=(FILESZT)sz;                                       //~v6D1I~
#ifdef W32                                                         //~v6d7I~
#else                                                              //~v6d7I~
//  Ppudl->uid=uid;                                                //~v6d1R~//~v6D0R~
    Ppudl->uid=(uid_t)uid;                                         //~v6D0I~
//  Ppudl->gid=gid;                                                //~v6d1R~//~v6D0R~
    Ppudl->gid=(gid_t)gid;                                         //~v6D0I~
#endif                                                             //~v6d7I~
    mode|=attr;       //permission                                 //~v6d1I~
//  Ppudl->attr=FILE_SETMODEATTR(mode,0);  //attr                  //~v6d1R~//~v6D0R~
    Ppudl->attr=FILE_SETMODEATTR((ULONG)mode,0);  //attr           //~v6D0I~
    uftpmode2attr(Ppudl);                                          //~v6d1R~
    return rc;                                                     //~v6d1I~
}//uftp3smb_fstatoutchk                                            //~v6d1R~
//**************************************************************** //~v6d1R~
//add cmd to chk normal completion                                 //~v6d1R~
//after lcd "pwd" is insrted already                               //~v6d1R~
//**************************************************************** //~v6d1R~
int uftp3smb_putstmt(int Popt,PUFTPHOST Ppuftph,FILE *Pfh,char *Popd1,char *Popd2)//~v6d1R~
{                                                                  //~v6d1R~
    char *pc;                                                      //~v6d1R~
//  char ftpcmd[16+_MAX_PATH+_MAX_PATH]={'\n',0};                  //~v6d1R~//~v6H3R~
    char ftpcmd[16+FTP_MAXPATH2]={'\n',0};                         //~v6H3I~
	int opt=F3SEFO_CMDFILE,pathlen;                                //~v6d1R~
//  char enclosewk[_MAX_PATH+4];                                   //~v6d1I~//~v6H3R~
    char enclosewk[FTP_MAXPATH+4];                                 //~v6H3I~
//********************                                             //~v6d1R~
	pc=ftpcmd;                                                     //~v6d1I~
	switch(Popt & F3SMBO_CMDMASK)                                  //~v6d1I~
    {                                                              //~v6d1I~
    case UFTPSMBCMD_PUT2:                                          //~v6d1I~
    	memcpy(pc,"put ",4);                                       //~v6d1I~
        pc+=4;                                                     //~v6d1R~
        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1);                     //~v6d1R~//~v6d7R~
        *pc++=' ';                                                 //~v6d1I~
        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd2);                     //~v6d1R~//~v6d7R~
        *pc++='\n';                                                //~v6d1R~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_RENAME:                                        //~v6d7I~
    	memcpy(pc,SMB_CMD_RENAME " ",sizeof(SMB_CMD_RENAME));      //~v6d7I~
        pc+=sizeof(SMB_CMD_RENAME);                                //~v6d7I~
        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1);             //~v6d7I~
        *pc++=' ';                                                 //~v6d7I~
        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd2);             //~v6d7I~
        *pc++='\n';                                                //~v6d7I~
        break;                                                     //~v6d7I~
//    case UFTPSMBCMD_STATDIR:                                     //~v6d1R~
//        strcpy(pc,SMB_CMD_VOLUME "\n");                          //~v6d1R~
//        break;                                                   //~v6d1R~
    case UFTPSMBCMD_STAT:                                          //~v6d1I~
    	memcpy(pc,SMB_CMD_STAT " ",sizeof(SMB_CMD_STAT));          //~v6d1R~
        pc+=sizeof(SMB_CMD_STAT);                                  //~v6d1R~
        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1);                     //~v6d1I~//~v6d7R~
        *pc++='\n';                                                //~v6d1I~
        break;                                                     //~v6d1I~
    case UFTPSMBCMD_DELETE:                                        //~v6d1I~
    	if (Popt & F3SMBO_MULTISTART)	//delete cmd dose not support path,so "cd" required//~v6d1I~
        {                                                          //~v6d1I~
    		memcpy(pc,"cd ",3);                                    //~v6d1I~
        	pc+=3;                                                 //~v6d1I~
	        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1);                 //~v6d1I~//~v6d7R~
        }                                                          //~v6d1I~
        else                                                       //~v6diI~
    	if (Popt & F3SMBO_MULTIENTRY)	//delete but each entry folder may differ//~v6d1I~
        {                                                          //~v6d1I~
            if ((pathlen=PATHLEN(Popd1))>0)    //contains path     //~v6d1R~
            {                                                      //~v6d1I~
    			memcpy(pc,"cd ",3);                                //~v6d1I~
        		pc+=3;                                             //~v6d1I~
//              UmemcpyZ(enclosewk,Popd1,pathlen);	               //~v6d1I~//~v6D0R~
                UmemcpyZ(enclosewk,Popd1,(size_t)pathlen);         //~v6D0I~
	        	pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,enclosewk);         //~v6d1I~//~v6d7R~
		        *pc++='\n';                                        //~v6d1R~
    			memcpy(pc,"del ",4);                               //~v6d1I~
        		pc+=4;                                             //~v6d1I~
		        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1+pathlen);     //~v6d1I~//~v6d7R~
            }                                                      //~v6d1I~
            else                                                   //~v6d1I~
            {                                                      //~v6d1I~
    			memcpy(pc,"del ",4);                               //~v6d1I~
        		pc+=4;                                             //~v6d1I~
	        	pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1);             //~v6d1I~//~v6d7R~
            }                                                      //~v6d1I~
        }                                                          //~v6d1I~
        else                                                       //~v6d1I~
        {                                                          //~v6d1I~
    		memcpy(pc,"del ",4);                                   //~v6d1R~
        	pc+=4;                                                 //~v6d1R~
	        pc+=uftp3smb_enclosefnm(opt,Ppuftph,pc,Popd1+PATHLEN(Popd1));  //~v6d1R~//~v6d7R~
        }                                                          //~v6d1I~
        *pc++='\n';                                                //~v6d1I~
        break;                                                     //~v6d1I~
    }                                                              //~v6d1I~
//  fprintf(Pfh,ftpcmd);                                           //~v6d1R~//~v6DiR~
    fprintf(Pfh,"%s",ftpcmd);                                      //~v6DiI~
    uftplog(0,ftpcmd);                                             //~v6d1R~
    return 0;                                                      //~v6d1R~
}//uftp3smb_putstmt                                                //~v6d1R~
//**************************************************************** //~v6d1I~
//advance to next cmd response msg                                 //~v6d1I~
//rc:0 found normal respmsg,4:found err msg,8:not msg matching to the filename//~v6d1I~
//**************************************************************** //~v6d1I~
int uftp3smb_respchk_srchnext(int Popt,PUFTPHOST Ppuftph,char *Pkey,char *Pfnm,char **Ppstdo,int Pstdoctr,int *Ppskipctr)//~v6d1R~
{                                                                  //~v6d1I~
    int rc=-1,rc2,linectr=0,stdoctr,stdoctrfound,offs,opt;         //~v6d1R~
    char **pstdo,**stdofound;                                  //~v6d1R~//~v6d7R~
//  char log[_MAX_PATH+32];                                        //~v6d1R~//~v6H3R~
    char log[FTP_MAXPATH+32];                                      //~v6H3I~
//***********************                                          //~v6d1I~
	opt=0;	//no errchk,search delm                                //~v6d1I~
    pstdo=Ppstdo;                                                  //~v6d1I~
    stdoctr=Pstdoctr;                                              //~v6d1I~
    if (Pkey)                                                      //~v6d1I~
        while(stdoctr>0)                                           //~v6d1R~
        {                                                          //~v6d1R~
            rc2=uftp3smb_srchresp(opt,pstdo,stdoctr,Pkey,&stdofound,&stdoctrfound,&offs);//~v6d1R~
            if (rc2)                                               //~v6d1R~
                break;                                             //~v6d1R~
            if (uftp3smb_strfname(F3SMBO_MEMBCHK,Ppuftph,*stdofound,Pfnm))//~v6d1R~
            {                                                      //~v6d1R~
	            if (Popt & F3SMBO_RETFOUND)                        //~v6d1I~
                    linectr=Pstdoctr-stdoctrfound;    //bypass hdr cmd response//~v6d1R~
//                else                                             //~v6d1R~
//                if (Popt & F3SMBO_MULTISTART)                    //~v6d1R~
//                    linectr=Pstdoctr-stdoctrfound;    //bypass hdr cmd response//~v6d1R~
                sprintf(log,"Resp Chk OK for %s\n",Pfnm);          //~v6d1R~
                uftplog(FTPLOG_INFO,log); //logging errmsg         //~v6d1I~
                uftplog(FTPLOG_INFO|FTPLOG_ADDLF,*stdofound); //logging errmsg//~v6d1I~
                rc=0;                                              //~v6d1R~
                break;                                             //~v6d1R~
            }                                                      //~v6d1R~
            pstdo=stdofound+1;       //srch down                   //~v6d1R~
            stdoctr=stdoctrfound-1;                                //~v6d1R~
        }                                                          //~v6d1R~
    if (rc)	//no key data found                                    //~v6d1I~
    {                                                              //~v6d1I~
        opt=F3SMBO_ERRCHK;     //errchk until seperator response msg//~v6d1I~
	    pstdo=Ppstdo;                                              //~v6d1I~
    	stdoctr=Pstdoctr;                                          //~v6d1I~
        rc=8;   //no matching entry found                          //~v6d1I~
	    while(stdoctr>0)                                           //~v6d1I~
    	{                                                          //~v6d1I~
            rc2=uftp3smb_srchresp(opt,pstdo,stdoctr,0/*key*/,&stdofound,&stdoctrfound,&offs);//~v6d1R~
        	if (rc2==-1)	//eof                                  //~v6d1I~
            	break;                                             //~v6d1I~
            if (uftp3smb_strfname(F3SMBO_MEMBCHK,Ppuftph,*stdofound,Pfnm))//~v6d1R~
            {                                                      //~v6d1R~
                if (Popt & F3SMBO_MULTISTART)                      //~v6d1M~
                {                                                  //~v6d1M~
                    linectr=Pstdoctr-stdoctrfound;    //bypass hdr cmd response//~v6d1M~
                    rc=0;		//continue to multiline chk        //~v6d1M~
                    break;                                         //~v6d1I~
                }                                                  //~v6d1M~
                if (Popt & F3SMBO_MULTIENTRY)                      //~v6d1I~
                    linectr=Pstdoctr-stdoctrfound+1;    //bypass hdr cmd response//~v6d1R~
                uerrmsg("smb err for %s by \"%s\"",0,                     //~v6d1R~//~v6d7R~
                        Pfnm,*stdofound);                               //~v6d1R~//~v6d7R~
                uftplog(FTPLOG_ERRM|FTPLOG_ADDLF,0); //logging errmsg//~v6d1R~
                rc=4;                                              //~v6d1R~
                break;                                             //~v6d1R~
            }                                                      //~v6d1R~
            pstdo=stdofound+1;     //srch down                     //~v6d1R~
            stdoctr=stdoctrfound-1;                                //~v6d1R~
        }                                                          //~v6d1I~
    }                                                              //~v6d1R~
    *Ppskipctr=linectr;                                            //~v6d1I~
    return rc;                                                     //~v6d1I~
}//uftp3smb_respchk_srchnext                                       //~v6d1R~
//**************************************************************** //~v6d1I~
//responce chk for each cmd                                        //~v6d1I~
//**************************************************************** //~v6d1I~
int uftp3smb_respchk(int Popt,PUFTPHOST Ppuftph,char *Pfnm,char ***Ppstdo,int *Ppstdoctr,int Prc)//~v6d1R~
{                                                                  //~v6d1I~
    int rc=0,linectr=0,cmdid,stdoctr;                              //~v6d1R~
//  char **pstdo,*pline;                                           //~v6n0R~
    char **pstdo       ;                                           //~v6n0I~
//***********************                                          //~v6d1I~
    cmdid=Popt & F3SMBO_CMDMASK;                                   //~v6d1I~
    pstdo=*Ppstdo;                                                 //~v6d1R~
//  pline=*pstdo;                                                  //~v6n0R~
    stdoctr=*Ppstdoctr;                                            //~v6d1I~
    switch(cmdid)                                                  //~v6d1I~
    {                                                              //~v6d1I~
    case UFTPSMBCMD_PWD:                                           //~v6d1I~
		rc=uftp3smb_respchk_srchnext(Popt,Ppuftph,SMB_RESP_PWD,Pfnm,pstdo,stdoctr,&linectr);//~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_GET:                                           //~v6d1R~
		rc=uftp3smb_respchk_srchnext(Popt,Ppuftph,SMB_RESP_GET,Pfnm,pstdo,stdoctr,&linectr);//~v6d1R~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_PUT:                                           //~v6d1I~
		rc=uftp3smb_respchk_srchnext(Popt,Ppuftph,SMB_RESP_PUT,Pfnm,pstdo,stdoctr,&linectr);//~v6d1R~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_DIR:                                           //~v6d1I~
        if (Popt & F3SMBO_SINGLESTART) //opendir                   //~v6d1R~
        	linectr=1;      //skip "Doamin=[..." header            //~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_CD:                                            //~v6d1I~
        linectr=1;                                                 //~v6d1I~
        if (stdoctr!=1)	//no response if successed                 //~v6d1I~
        	rc=Prc;                                                //~v6d1R~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_MKDIR:                                         //~v6d1I~
        linectr=1;                                                 //~v6d1I~
        if (stdoctr>1)	//no response if successed                 //~v6d1R~
        {                                                          //~v6d1I~
			rc=uftp3smb_respchk_srchnext(Popt,Ppuftph,SMB_RESP_MKDIR,Pfnm,pstdo,stdoctr,&linectr);//~v6d1R~
            if (!rc)      //posix_mkdir created                    //~v6d1I~
            	linectr++;                                         //~v6d1I~
        }                                                          //~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_RMDIR:                                         //~v6d1I~
        linectr=1;                                                 //~v6d1I~
        if (stdoctr!=1)	//no response if successed                 //~v6d1I~
        	rc=Prc;                                                //~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_DELETE:                                        //~v6d1I~
        if (Popt & F3SMBO_MULTIENTRY)                              //~v6b1I~//~v6d1I~
        {                                                          //~v6d1I~
			if (uftp3smb_respchk_srchnext(Popt,Ppuftph,0/*key*/,Pfnm,pstdo,stdoctr,&linectr)==4)//err line found//~v6d1R~
            	rc=Prc;                                            //~v6d1I~
            else                                                   //~v6d1I~
            	linectr=0;	//no advance                           //~v6d1I~
        	break;                                                 //~v6d1I~
        }                                                           //~v6b1I~//~v6d1I~
        linectr=1;                                                 //~v6d1I~
        if (stdoctr!=1)	//no response if successed                 //~v6d1I~
        	rc=Prc;                                                //~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_RENAME:                                        //~v6d1I~
        if (Popt & F3SMBO_MULTIENTRY)                              //~v6d1I~
        {                                                          //~v6d1I~
			if (uftp3smb_respchk_srchnext(Popt,Ppuftph,0/*key*/,Pfnm,pstdo,stdoctr,&linectr)==4)//err line found//~v6d1I~
            	rc=Prc;                                            //~v6d1I~
            else                                                   //~v6d1I~
            	linectr=0;	//no advance                           //~v6d1I~
        	break;                                                 //~v6d1I~
        }                                                          //~v6d1I~
        linectr=1;                                                 //~v6d1I~
        if (stdoctr!=1)	//no response if successed                 //~v6d1I~
        	rc=Prc;                                                //~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_CHMOD:                                         //~v6d1I~
        linectr=1;                                                 //~v6d1I~
        if (stdoctr!=1)	//no response if successed                 //~v6d1I~
        	rc=Prc;                                                //~v6d1I~
    	break;                                                     //~v6d1I~
    case UFTPSMBCMD_SETMOD:                                        //~v6d7I~
        linectr=1;                                                 //~v6d7I~
        if (stdoctr!=1)	//no response if successed                 //~v6d7I~
        	rc=Prc;                                                //~v6d7I~
    	break;                                                     //~v6d7I~
//    case UFTPSMBCMD_STATDIR:                                     //~v6d1R~
//        if (uftp3smb_respchk_srchnext(Popt,Ppuftph,SMB_RESP_VOLUME,Pfnm,pstdo,stdoctr,&linectr)==4)//err line found//~v6d1R~
//            rc=Prc;                                              //~v6d1R~
//        break;                                                   //~v6d1R~
    case UFTPSMBCMD_STAT:     //from dirlist memb fstat at once    //~v6d1I~
        if (uftp3smb_respchk_srchnext(Popt,Ppuftph,SMB_RESP_STAT,Pfnm,pstdo,stdoctr,&linectr)==4)//err line found//~v6d1I~
            rc=Prc;                                                //~v6d1I~
        break;                                                     //~v6d1I~
    default:                                                       //~v6d1I~
    	rc=16;                                                     //~v6d1R~
    }                                                              //~v6d1I~
    if (linectr)                                                   //~v6d1R~
    {                                                              //~v6d1I~
    	*Ppstdo=pstdo+linectr;                                     //~v6d1I~
        *Ppstdoctr=stdoctr-linectr;                                //~v6d1R~
    }                                                              //~v6d1I~
    return rc;                                                     //~v6d1I~
}//ftp3smb_respchk                                                 //~v6d1R~
//*******************************************************          //~v6d1I~
//*change local dir responce msg chk                               //~v6d1R~
//*******************************************************          //~v6d1I~
int uftp3smb_lchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm)//~v6d1I~
{                                                                  //~v6d1I~
	return uftp3smb_respchk(UFTPSMBCMD_LCD,Ppuftph,Pdirnm,Ppstdo,Ppstdoctr,ENOENT);//~v6d1R~
}//uftp3smb_lchdirrespchk                                          //~v6d1R~
////*******************************************************        //~v6d1R~
////*posix_mkdir responce msg chk                                  //~v6d1R~
////*******************************************************        //~v6d1R~
//int uftp3smb_mkdirrespchk(int Popt,PUFTPHOST Ppuftph,char *Pdirnm,int Pmode,char ***Ppstdo,int *Ppstdoctr,int *Presultmode)//~v6d1R~
//{                                                                //~v6d1R~
//    int rc;                                                      //~v6d1R~
//    UDIRLIST udl;                                                //~v6d1R~
////************************                                       //~v6d1R~
//    rc=uftp3smb_respchk(Popt,Ppuftph,Pdirnm,Ppstdo,Ppstdoctr,ENOENT);//~v6d1R~
//    if (!rc)                                                     //~v6d1R~
//        if (!*Ppstdoctr)                                         //~v6d1R~
//            rc=FTPRC_PARSEERR;                                   //~v6d1R~
//        else                                                     //~v6d1R~
//        {                                                        //~v6d1R~
//            rc=uftp3smb_fstatoutchk(0,Ppuftph,Pdirnm,&udl,Ppstdo,Ppstdoctr);//~v6d1R~
//            if (!rc)                                             //~v6d1R~
//                *Presultmode=FILE_GETMODE(udl.attr);             //~v6d1R~
//        }                                                        //~v6d1R~
//    return rc;                                                   //~v6d1R~
//                                                                 //~v6d1R~
//}//uftp3smb_mkdirrespchk                                         //~v6d1R~
//******************************************************           //~v6d1I~
//*return found addr or 0                                          //~v6d1I~
//******************************************************           //~v6d1I~
char *uftp3smb_strfname(int Popt,PUFTPHOST Ppuftph,char *Pline,char *Pfname)//~v6d1R~
{                                                                  //~v6d1I~
	char *pc=0,*pcm,*pc1,*pc2,*pc3;                                //~v6d1R~
//**************                                                   //~v6d1I~
	if (Popt & F3SMBO_MEMBCHK)                                     //~v6d1R~
    {                                                              //~v6d1I~
        pc1=strrchr(Pfname,'/');                                   //~v6d1I~
        pc2=strrchr(Pfname,'\\');                                  //~v6d1I~
        pcm=USTR_MAXPTR(pc1,pc2);                                  //~v6d1I~
        if (pcm)                                                   //~v6d1I~
        	pcm++;                                                 //~v6d1I~
        else                                                       //~v6d1I~
            pcm=Pfname;                                            //~v6d1I~
        pc=Pline;                                                  //~v6d1R~
        for (;;)                                                   //~v6d1R~
        {                                                          //~v6d1R~
            if (Ppuftph->UFTPHflag & UFTPHFRWIN)                 //~v6d1R~//~v6d7R~
                pc=ustrstri(pc,pcm);                               //~v6d1R~
            else                                                   //~v6d1R~
                pc=strstr(pc,pcm);                                 //~v6d1R~
            if (!pc)                                               //~v6d1R~
                break;                                             //~v6d1R~
            pc1=pc-1;                                              //~v6d1R~
            if (*pc1==' '||*pc1=='/'||*pc1=='\\')                  //~v6d1R~
            {                                                      //~v6d1R~
                pc2=pc+strlen(pcm);         //terminator chk       //~v6d1R~
                pc3=pc2+1;                                         //~v6d1R~
                if (*pc2==' '||*pc2=='\n'||*pc2==0                 //~v6d1R~
                ||  (    *pc2=='\\'                                //~v6d1R~
                     &&  (*pc3==0||*pc3==' '||*pc3=='\n')          //~v6d1R~
                    )                                              //~v6d1R~
                )                                                  //~v6d1R~
                    break;                                         //~v6d1R~
            }                                                      //~v6d1R~
            pc++;                                                  //~v6d1R~
        }                                                          //~v6d1R~
    }                                                              //~v6d1I~
    else                                                           //~v6d1I~
	if (Popt & F3SMBO_MEMBCMP)                                     //~v6d1R~
    {                                                              //~v6d1I~
        if (Ppuftph->UFTPHflag & UFTPHFRWIN)                     //~v6d1I~//~v6d7R~
            pc=stricmp(Pline,Pfname)==0?Pline:0;                   //~v6d1R~
        else                                                       //~v6d1I~
            pc=strcmp(Pline,Pfname)==0?Pline:0;                    //~v6d1I~
    }                                                              //~v6d1I~
    else                                                           //~v6d1I~
    {                                                              //~v6d1I~
        if (Ppuftph->UFTPHflag & UFTPHFRWIN)                     //~v6d1R~//~v6d7R~
            pc=ustrstri(Pline,Pfname);                             //~v6d1R~
        else                                                       //~v6d1R~
            pc=strstr(Pline,Pfname);                               //~v6d1R~
    }                                                              //~v6d1I~
    return pc;                                                     //~v6d1I~
}//uftp3smb_strfname                                               //~v6d1I~
//*******************************************************          //~v6d1I~
//*get data from xehosts file ctl line                             //~v6d1I~
//*******************************************************          //~v6d1I~
int uftp3smb_enclosefnm(int Popt,PUFTPHOST Ppuftph,char *Pout,char *Pfnm)            //~v6d1I~//~v6d7R~
{                                                                  //~v6d1I~
	int len,ii;                                                       //~v6d1I~//~v6d7R~
    char *pc;                                                      //~v6d7I~
//*****************                                                //~v6d1I~
    if (strchr(Pfnm,' '))                                          //~v6d1I~
    {                                                              //~v6d1I~
		if (Popt & F3SEFO_CMDFILE)                                 //~v6d7I~
    		len=sprintf(Pout,"\"%s\"",Pfnm);                       //~v6d1I~//~v6d7R~
        else                                                       //~v6d1I~
    		len=sprintf(Pout,"\\\"%s\\\"",Pfnm);                   //~v6d1R~
    }                                                              //~v6d1I~
    else                                                           //~v6d1I~
    {                                                              //~v6d1I~
//  	len=strlen(Pfnm);                                          //~v6d1I~//~v6D0R~
    	len=(int)strlen(Pfnm);                                     //~v6D0I~
//  	UmemcpyZ(Pout,Pfnm,len);                                   //~v6d1I~//~v6D0R~
    	UmemcpyZ(Pout,Pfnm,(size_t)len);                           //~v6D0I~
    }                                                              //~v6d1I~
    if (Ppuftph->UFTPHflag & UFTPHFRWIN)                           //~v6d7R~
		if (Popt & F3SEFO_CMDFILE)                                 //~v6d1I~//~v6d7M~
        {                                                          //~v6d7I~
            for (ii=0,pc=Pout;ii<len;ii++,pc++)                    //~v6d7I~
            	if (*pc=='/')                                      //~v6d7I~
                	*pc='\\';                                      //~v6d7I~
        }                                                          //~v6d7I~
    return len;                                                    //~v6d1I~
}//uftp3smb_enclosefnm                                             //~v6d1I~
//*******************************************************          //~v6d1I~
//*set cmdline -c option text                                      //~v6d1I~
//escape '"' and '$'                                               //~v6d1I~
//*return strlen set                                               //~v6d1I~
//*******************************************************          //~v6d1I~//~v6d7R~
int uftp3smb_editcmdparm(int Popt,PUFTPHOST Ppuftph,char *Pout,char *Pcmd,int Pbuffsz)//~v6d1I~//~v6d7R~
{                                                                  //~v6d1I~
	int len,ch,cho=0;                                              //~v6d1R~
    UCHAR *pci,*pco,*pcoe;                                         //~v6d1R~
    int swwin;                                                     //~v6d7I~
//*****************                                                //~v6d1I~
	swwin=Ppuftph->UFTPHflag & UFTPHFRWIN;                         //~v6d7R~
//  len=strlen(Pcmd);                                              //~v6d1I~//~v6D0R~
    len=(int)strlen(Pcmd);                                         //~v6D0I~
//    if (!memchr(Pcmd,'\"',len))                                  //~v6d1R~
//    {                                                            //~v6d1R~
//        UmemcpyZ(Pout,Pcmd,Pbuffsz);                             //~v6d1R~
//        len=min(len,Pbuffsz-1);                                  //~v6d1R~
//        if (*(Pout+len-1)=='\n')                                 //~v6d1R~
//        {                                                        //~v6d1R~
//            len--;                                               //~v6d1R~
//            *(Pout+len)=0;                                       //~v6d1R~
//        }                                                        //~v6d1R~
//        return len;                                              //~v6d1R~
//    }                                                            //~v6d1R~
    for (pci=Pcmd,pco=Pout,pcoe=pco+Pbuffsz-1;*pci && pco<pcoe;)   //~v6d1R~
    {                                                              //~v6d1I~
        ch=*pci++;                                                 //~v6d1I~
        if (ch=='\n')                                              //~v6d1I~
        	break;                                                 //~v6d1I~
		if (ch=='\"' && cho!='\\')                                 //~v6d1R~
        {                                                          //~v6d1I~
            *pco++='\\';                                           //~v6d1R~
        }                                                          //~v6d1I~
        else                                                       //~v6d1I~
		if (ch=='$' && cho!='\\')                                  //~v6d1I~
        {                                                          //~v6d1I~
            *pco++='\\';                                           //~v6d1I~
        }                                                          //~v6d1I~
        if (swwin && ch=='/')                                      //~v6d7I~
        {                                                          //~v6d7I~
        	*pco++='\\';                                           //~v6d7I~
        	*pco++='\\';                                           //~v6d7I~
        }                                                          //~v6d7I~
        else                                                       //~v6d7I~
//      	*pco++=ch;                                                 //~v6d1R~//~v6d7R~//~v6BMR~
        	*pco++=(UCHAR)ch;                                      //~v6BMI~
        cho=ch;                                                    //~v6d1I~
    }                                                              //~v6d1I~
    *pco=0;                                                        //~v6d1I~
//  len=(ULONG)pco-(ULONG)Pout;                                    //~v6d1I~//~v6hhR~
//  len=(ULPTR)pco-(ULPTR)Pout;                                    //~v6hhI~//~v6D0R~
    len=PTRDIFF(pco,Pout);                                         //~v6D0I~
    return len;                                                    //~v6d1I~
}//uftp3smb_editcmdparm                                            //~v6d1I~
//*******************************************************          //~v6d1I~
//*set cmdline -c option text                                      //~v6d1I~
//*return strlen set                                               //~v6d1I~
//*******************************************************          //~v6d1I~
char *uftp3smb_dirnameforlist(int Popt,PUFTPHOST Ppuftph,char *Pdirname,char *Poutpath)//~v6d1I~
{                                                                  //~v6d1I~
	int len;                                                       //~v6d1I~
    char *pc;                                                      //~v6d1I~
//*****************                                                //~v6d1I~
	if (WILDCARD(Pdirname))                                     //~v6b1I~//~v6d1I~
    	return Pdirname;                                           //~v6d1I~
//  len=strlen(Pdirname);                              //~v6b1I~   //~v6d1I~//~v6D0R~
    len=(int)strlen(Pdirname);                                     //~v6D0I~
	memcpy(Poutpath,Pdirname,(UINT)len);                 //~v6b1I~ //~v6d1I~
    pc=Poutpath+len;                                               //~v6d1I~
    if (*(pc-1)!='/'&&*(pc-1)!='\\')                               //~v6d1R~
    	*pc++=FTP_DIR_SEPC;                                        //~v6d1I~
    strcpy(pc,DIR_ALLMEMB);                    //~v6b1I~           //~v6d1I~
    return Poutpath;                                               //~v6d1I~
}//uftp3smb_dirnameforlist                                         //~v6d7R~
//*******************************************************          //~v6d7I~
ULONG uftp3smb_mode2attr_winsub(int Popt,ULONG Pmodeattr)          //~v6d7I~
{                                                                  //~v6d7I~
    ULONG attr=FILE_REMOTE;                                        //~v6d7I~
    ULONG mode,modeattr;                                           //~v6d7I~
//*************                                                    //~v6d7I~
    attr|=FILE_GETATTR(Pmodeattr);                                 //~v6d7I~
    mode=FILE_GETMODE(Pmodeattr);                                  //~v6d7I~
    if (attr & FILE_DIRECTORY)                                     //~v6d7I~
    	mode|=S_IFDIR;                                             //~v6d7I~
	modeattr=FILE_SETMODEATTR(mode,attr);                          //~v6d7I~
    return modeattr;                                               //~v6d7I~
}//uftp3smb_mode2attr_win                                          //~v6d7I~
//*******************************************************          //~v6d7I~
//*mode2attr for target is window                                  //~v6d7R~
//*return:attr                                                     //~v6d7I~
//*******************************************************          //~v6d7I~
ULONG uftp3smb_mode2attr_win(int Popt,PUFTPHOST Ppuftph,PUDIRLIST Ppudl)//~v6d7I~
{                                                                  //~v6d7I~
    ULONG modeattr;                                           //~v6d7R~//~v6daR~
//*************                                                    //~v6d7I~
	modeattr=Ppudl->attr;                                          //~v6d7I~
	modeattr=uftp3smb_mode2attr_winsub(Popt,modeattr);             //~v6d7I~
	Ppudl->attr=modeattr;                                          //~v6d7I~
    return modeattr;                                               //~v6d7I~
}//uftp3smb_mode2attr_win                                          //~v6d7I~
//*******************************************************          //~v6d7I~
//*set attr for target:window                                      //~v6d7I~
//*return:attr                                                     //~v6d7I~
//*******************************************************          //~v6d7I~
ULONG uftp3smb_strattr(int Popt,ULONG Pattr,char *Pstrattr)        //~v6d7I~
{                                                                  //~v6d7I~
    char *pc;                                                      //~v6d7I~
//*************                                                    //~v6d7I~
	pc=Pstrattr;                                                   //~v6d7I~
    if (UCBITCHK(Pattr,FILE_READONLY))                             //~v6d7I~
       	*pc++='r';                                                 //~v6d7I~
    if (UCBITCHK(Pattr,FILE_SYSTEM))                               //~v6d7I~
       	*pc++='s';                                                 //~v6d7I~
    if (UCBITCHK(Pattr,FILE_HIDDEN))                               //~v6d7I~
       	*pc++='h';                                                 //~v6d7I~
 	if (UCBITCHK(Pattr,FILE_ARCHIVED))                             //~v6d7I~
       	*pc++='a';                                                 //~v6d7I~
    *pc=0;                                                         //~v6d7I~
//  return (ULONG)pc-(ULONG)Pstrattr;                              //~v6d7I~//~v6hhR~
    return (ULONG)((ULPTR)pc-(ULPTR)Pstrattr);                     //~v6x7R~
}//uftp3smb_strattr                                                //~v6d7I~
//*******************************************************          //~v6d7I~
//*set attr for target:window                                      //~v6d7I~
//*return:attr                                                     //~v6d7I~
//*******************************************************          //~v6d7I~
ULONG uftp3smb_setmod_win(int Popt,PUFTPHOST Ppuftph,char *Pfpath,ULONG Poldattr,ULONG Pattron,ULONG Pattroff)//~v6d7R~
{                                                                  //~v6d7I~
    char **stdo,**stdo0,*pc,*pfname;                               //~v6d7R~
    int stdoctr,rc=0;                                              //~v6d7R~
//  ULONG attron,attroff,attr,mode;                                //~v6n0R~
    ULONG attron,attroff          ;                                //~v6n0I~
    char strattr[16];                                              //~v6d7I~
//  char ftpcmd[16+_MAX_PATH+_MAX_PATH];                           //~v6d7I~//~v6H3R~
    char ftpcmd[16+FTP_MAXPATH2];                                  //~v6H3I~
//*************                                                    //~v6d7I~
    pfname=Pfpath+Ppuftph->UFTPHhostnmlen+1;                       //~v6d7I~
//  mode=FILE_GETMODE(Poldattr);                                   //~v6n0R~
//  attr=FILE_GETATTR(Poldattr);                                   //~v6n0R~
    attron=FILE_GETATTR(Pattron);                                  //~v6d7I~
    attroff=FILE_GETATTR(Pattroff);                                //~v6d7I~
    if (attron || attroff)                                         //~v6d7I~
    {                                                              //~v6d7I~
    	pc=strattr;                                                //~v6d7I~
    	if (attroff)                                               //~v6d7R~
        {                                                          //~v6d7I~
        	*pc++='-';                                             //~v6d7I~
        	pc+=uftp3smb_strattr(0,attroff,pc);                    //~v6d7R~
        }                                                          //~v6d7I~
    	if (attron)                                                //~v6d7R~
        {                                                          //~v6d7I~
        	*pc++='+';                                             //~v6d7I~
        	pc+=uftp3smb_strattr(0,attron,pc);                     //~v6d7R~
        }                                                          //~v6d7I~
        *pc=0;                                                     //~v6d7I~
        rc=uftp3smb_setcmd(UFTPSMBCMD_SETMOD|F3SMBO_NFMSG,Ppuftph,ftpcmd,pfname,strattr,0/*intparm1*/,0/*intpam2*/);//~v6d7R~
        if (rc)                                                    //~v6d7I~
//          return rc;                                             //~v6d7I~//~v6D0R~
            return (ULONG)rc;                                      //~v6D0I~
        rc=uftp3smbcmd(0,Ppuftph,ftpcmd,&stdo,&stdoctr,0/*callback*/,0/*callbackparm*/);//~v6d7R~
        if (!rc)                                                   //~v6d7I~
        {                                                          //~v6d7I~
        	stdo0=stdo;                                            //~v6d7I~
            rc=uftp3smb_respchk(UFTPSMBCMD_SETMOD,Ppuftph,pfname,&stdo,&stdoctr,ENOENT);//~v6d7R~
            ufree(stdo0);                                          //~v6d7I~
        }                                                          //~v6d7I~
    }                                                              //~v6d7I~
//  return rc;                                                     //~v6d7R~//~v6D0R~
    return (ULONG)rc;                                              //~v6D0I~
}//uftp3smb_setmod_win                                             //~v6d7R~
