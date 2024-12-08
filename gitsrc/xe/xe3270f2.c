//*CID://+vbzGR~:                              update#= 1549;      //+vbzGR~
//*************************************************************
//vbzG:240401 fc39 compile warning                                 //+vbzGI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va70:000701 LP64 option support. at first chk PTR sz(ini file comaptibility)//~va70I~
//v79x:080914 (LNX:BUG)if euc,3270ftp conv twice when ext converter case//~v79xI~
//v79h:080820 (3270)drop numfld only when expanded by SO/SI insert //~v79hI~
//v79g:080819 (3270)A2E SOSI option(INS/REP/SHIFT)                 //~v79gI~
//v79f:080818 (3270)cp939/cp930 option suppoprt(IBM/NEC/OLD/NEW)   //~v79fI~
//v79d:080815 (3270:BUG)ftp reposnse data(suchas TRANSxx ...) has no screen line herader//~v79dI~
//v79c:080811 (3270)try enter after ftp tp avoid spf panel err 32  //~v79cI~
//v79b:080809 (BUG)fgets terminate by 0x1a,use ufgets              //~v79bI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v8@C:080627 3270:(BUG)append mode not effective by getconfirmation//~v8@zI~
//v8@z:080625 3270:EUC<->EBC conversion                            //~v8@zI~
//v8@x:080625 3270:sometime FTP wait(readresp hung) free line may be required for READY mode//~v8@xI~
//v8@u:080623 3270:could not support recfm=v DBCS conversion because lrh is unknow//~v8@uI~
//v8@t:080623 3270:cursor move to =6 panel home for cmd(ftp,listds,..) input//~v8@sI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v8@q:080620 3270:enter/reenter chk last line only                //~v8@qR~
//v8@p:080620 3270:split xe3270.c =.xe3270.c+xe3270f.c             //~v8@mI~
//*************************************************************
//*xe3270f2.c                                                      //~v8@uR~
//*funcftp                                                         //~v8@uR~
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
#include <ucvebc.h>                                                //~v8@sI~
#include <udbcschk.h>                                              //~v8@zI~
#include <ucvext.h>                                                //~v79aI~

#include "xe.h"
#include "xe3270.h"
#include "xe3270s.h"                                               //~v725I~
//*************************************************************
//*************************************************************
#define FNM_EBC    ".EBCDIC"                                       //~v8@sI~
#define VLRHSZ         4                                           //~v8@sR~
#define SPFNUMFLDLEN   8           //from xefile.h                 //~v8@CI~
#define EBC_SPACE   0x40                                           //~v8@sI~
#define SETVLRH(pc,len)   			/*RECFMV LRH*/         \
               (*pc=(UCHAR)((len)/256),*(pc+1)=(UCHAR)((len)%256),*(pc+2)=0,*(pc+3)=0)//~v8@sI~
//*************************************************************    //~v8@sI~
#define  EBCBUFFSZ   32768                                         //~v8@sI~
static UCHAR Sebcbuffi[EBCBUFFSZ];                                 //~v8@sR~
static UCHAR Sebcbuffo[EBCBUFFSZ];                                 //~v8@sR~
#ifdef LNX                                                         //~v8@zI~
static UCHAR Sebcbuffw[EBCBUFFSZ]; //for EUC work                  //~v8@zI~
#endif                                                             //~v8@zI~
//*************************************************************
//int putconfirm(PTHREADTB Ppthtb,char *Pcmd);                     //~v8@sR~
int putconfirm(int Popt,PTHREADTB Ppthtb,char *Pcmd);              //~v8@sR~
//int getconfirm(PTHREADTB Ppthtb,char *Pcmd);                     //~v8@sR~
int getconfirm(int Popt,PTHREADTB Ppthtb,char *Pcmd);              //~v8@sR~

//int setuptransfercmd(PTHREADTB Ppthtb,char *Pcmd);               //~v71RR~
int setuptransfercmd(int Popt,PTHREADTB Ppthtb,char *Pcmd,int *Pptopt);//~v8@sR~
#define SUTCO_CONFIRM    0x01   //confirm                          //~v8@sI~
#define SUTCO_DBCSCONV   0x02   //binary mdeo by DBCSCONV          //~v8@sI~
#define SUTCO_GETAPPCONF 0x04   //confirmation mode append download//~v8@CR~
#define SUTCO_SBCSA2A    0x10   //text   mode by SBCSCONV          //~v79aI~
#define SUTCO_SBCSCONV   0x20   //binary mode by SBCSCONV          //~v79aR~
                                                                   //~v8@sI~
#define SUTC_TOBIN       0x01   //bin option specified             //~v71RI~
#define SUTC_DBCSCONV    0x02   //dbcsconv                         //~v8@sI~
#define SUTC_DBCS930     0x04   //dbcsconv                         //~v8@sI~
#define SUTC_DBCS939     0x08   //dbcsconv                         //~v8@sI~
#define SUTC_FIXED       0x10   //fixed length                     //~v8@sI~
#define SUTC_VARIABLE    0x20   //variable length                  //~v8@sI~
#define SUTC_2EBC        0x40   //local->EBC                       //~v8@sI~
#define SUTC_APPEND      0x80   //append option                    //~v8@CR~
#define SUTC_NUMSTD      0x0100 //8 byte num field on the end of line//~v8@CR~
#define SUTC_DBCSCJK     0x0200 //charset by xe3270ftp.map         //~v79aI~
#define SUTC_SBCSA2A     0x0800 //adjust mapping by A2F/F2A        //~v79aI~
#define SUTC_SBCSCONV    0x4000 //use sbcs converter               //~v79aR~
#define SUTC_LRECLMASK   0xffff0000 //bin option specified         //~v8@sI~
//int getlocaltmp(char *Phostfile,char *Poutfname);                //~v725R~
int getlocaltmp(char *Phostfile,char *Psuffix,char *Poutfname);    //~v725I~
int ftppreproc(int Popt,PTHREADTB Ppthtb);                         //~v8@xI~
int ftppostproc(int Popt,PTHREADTB Ppthtb,int Prc,int Prow);       //~v8@jR~
int chkdbcsoption(int Popt,PTHREADTB Ppthtb,int *Pptopt,char *Ppebcfnm);//~v8@sR~
int convebc2local(int Popt,char *Pplocalfile,char *Ppebcfile);     //~v8@sI~
int convlocal2ebc(int Popt,char *Pplocalfile,char *Ppebcfile);     //~v8@sI~
int chksjisoption(int *Ppopt);                                     //~v79fI~
//****************************************************************
//*issue cmd to 3270 sub process
//****************************************************************
int funcftp(PTHREADTB Ppthtb)
{
    int rc,opt;
    int topt;                                                      //~v71RI~
    int /*dbcssw=0,*/dbcstopt,setupopt=0;                              //~v8@sR~//~vaa7R~
    int appendgetsw=0;                                             //~v8@CI~
    char cmd[MAX_CMDSZ];
    char ebcfnm[_MAX_PATH],**popd,*plocalfile;                     //~v8@sR~
    char appendwork[_MAX_PATH],*phostfile;                         //~v8@CR~
    int row;                                                       //~v8@jI~
    int sbcssw,ebcwksw=0;                                          //~v79aR~
//************************
UTRACEP("funcftp entry\n");
//  screenclear(3,Ppthtb);   //2 line cmd +1                       //~v8@xR~
	if (rc=ftppreproc(0,Ppthtb),rc)                                //~v8@xR~
    	return 4;                                                  //~v8@xI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v8@sI~//~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
	plocalfile=popd[PARM_LOCALFILE];                               //~v8@sI~
	phostfile=popd[PARM_HOSTFILE];                                 //~v8@CI~
  for (;;)                                                         //~v8@sI~
  {                                                                //~v8@sI~
  	if (chkdbcsoption(0,Ppthtb,&dbcstopt,ebcfnm))                  //~v8@sR~
    {                                                              //~v8@sI~
    	rc=4;                                                      //~v8@sR~
        break;                                                     //~v8@sI~
    }                                                              //~v8@sI~
  	sbcssw=(dbcstopt & (SUTC_SBCSCONV|SUTC_SBCSA2A));	//xe3270 sbcs remapping//~v79aR~
//	if (dbcstopt & SUTC_DBCSCONV)  //dbcsconv                      //~v79aR~
  	if ((dbcstopt & SUTC_DBCSCONV)  //dbcsconv                     //~v79aI~
    ||  sbcssw)                                                    //~v79aR~
    {                                                              //~v8@sI~
  	  if (dbcstopt & SUTC_DBCSCONV)  //dbcsconv                    //~v79aR~
    	/*dbcssw=*/setupopt=SUTCO_DBCSCONV;                            //~v8@sR~//~vaa7R~
      else                                                         //~v79aI~
  	  if (dbcstopt & SUTC_SBCSCONV)  //dbcsconv                    //~v79aR~
	    setupopt=SUTCO_SBCSCONV;                                   //~v79aR~
      else                                                         //~v79aR~
	    setupopt=SUTCO_SBCSA2A;                                    //~v79aR~
        ebcwksw=1;                                                 //~v79aI~
		popd[PARM_LOCALFILE]=ebcfnm;                               //~v8@sI~
    	if (Ppthtb->THTreqcode==THTRQ_TRANSFER_PUT)                //~v8@uI~
        {                                                          //~v8@uM~
        	rc=convlocal2ebc(dbcstopt,plocalfile,ebcfnm);          //~v8@uM~
            if (rc)                                                //~v8@uM~
            	break;                                             //~v8@uM~
        }                                                          //~v8@uM~
    }                                                              //~v8@sI~
  	if (dbcstopt & SUTC_APPEND)  //append mode                     //~v8@CR~
    {                                                              //~v8@CR~
    	if ((Ppthtb->THTreqcode==THTRQ_TRANSFER_GET)               //~v8@CR~
    	&&  !(Ppthtb->THTflag2 & THTF2_NOGETCONF))  	//get conform mode download//~v8@CR~
        {                                                          //~v8@CR~
	    	setupopt|=SUTCO_GETAPPCONF;                            //~v8@CR~
            appendgetsw=1;                                         //~v8@CI~
//          if (!dbcssw)	//not localfile changed to EBC         //~v79aR~
            if (!ebcwksw)	//not localfile changed to EBC         //~v79aR~
            {                                                      //~v8@CR~
				popd[PARM_LOCALFILE]=appendwork;                   //~v8@CR~
        		getlocaltmp(phostfile,"APPENDwork",appendwork);    //~v8@CR~
            }                                                      //~v8@CR~
        }                                                          //~v8@CR~
    }                                                              //~v8@CR~
//  if (setuptransfercmd(Ppthtb,cmd))                              //~v71RR~
//  if (setuptransfercmd(0,Ppthtb,cmd,&topt))                      //~v8@sR~
    if (setuptransfercmd(setupopt,Ppthtb,cmd,&topt))               //~v8@sR~
    	rc=4;
    else
    {
//  	screenclear(3,Ppthtb);   //2 line cmd +1                   //~v8@3R~
//  	if (screenclear(0,Ppthtb))   //cler *** if pending         //~v8@sR~
//     {                                                           //~v8@sR~
//  		return U3CR_RC_OTHER;                                  //~v8@sR~
//  		rc=U3CR_RC_OTHER;                                      //~v8@sR~
//          break;                                                 //~v8@sR~
//      }                                                          //~v8@sR~
    	opt=SENDO_RCHK_FTP|SENDO_DROPSTATUS;
    	opt|=SENDO_WAIT_OUTPUT;                                    //~v8@jI~
    	if (Ppthtb->THTreqcode==THTRQ_TRANSFER_GET)
	    	opt|=SENDO_RCHK_FTPGET;
	    row=Ppthtb->THTcurrow;                                     //~v8@jI~
	 	rc=send3270(opt,Ppthtb,cmd);
	    ftppostproc(0,Ppthtb,rc,row);                              //~v8@jR~
UTRACEP("xe3270f2 after postproc rc=%d\n",rc);                     //~v79aR~
        if (!rc                                                    //~v71RI~
    	&&  Ppthtb->THTreqcode==THTRQ_TRANSFER_PUT                 //~v71RI~
    	&&  !(Ppthtb->THTflag2 & THTF2_NOPUTCONF)                  //~v8@5R~
//      &&  Smainopt & XE3270OPT_PUTCONFIRM)      //confirm after put//~v725R~
        )                                                          //~v725I~
//          rc=putconfirm(Ppthtb,cmd);                             //~v8@sR~
            rc=putconfirm(setupopt,Ppthtb,cmd);                    //~v8@sR~
UTRACEP("xe3270f2 after putconf rc=%d\n",rc);                      //~v79aR~
        if (!rc                                                    //~v71TI~
    	&&  Ppthtb->THTreqcode==THTRQ_TRANSFER_GET                 //~v71TI~
    	&&  !(Ppthtb->THTflag2 & THTF2_NOGETCONF)                  //~v8@5R~
//      &&  Smainopt & XE3270OPT_GETCONFIRM)      //confirm after put//~v725R~
        )                                                          //~v725I~
//          rc=getconfirm(Ppthtb,cmd);                             //~v8@sR~
            rc=getconfirm(setupopt,Ppthtb,cmd);                    //~v8@sR~
UTRACEP("xe3270f2 after getconf rc=%d\n",rc);                      //~v79aR~
        if (rc)                                                    //~v8@sI~
        	break;                                                 //~v8@sI~
UTRACEP("ebcwksw=%d\n",ebcwksw);                                   //~v79aR~
//  	if (dbcssw && Ppthtb->THTreqcode==THTRQ_TRANSFER_GET)      //~v79aR~
    	if (ebcwksw && Ppthtb->THTreqcode==THTRQ_TRANSFER_GET)     //~v79aR~
        	rc=convebc2local(dbcstopt,plocalfile,ebcfnm);          //~v8@sR~
        else                                                       //~v8@CI~
        	if (appendgetsw)                                       //~v8@CI~
            {                                                      //~v8@CI~
            	if (!uxcopy(appendwork,plocalfile,DCPY_APPEND,FILE_NORMAL))//~v8@CR~
					unlink(appendwork);                            //~v8@CI~
            }                                                      //~v8@CI~
        break;                                                     //~v8@sI~
    }
    break;                                                         //~v8@uI~
  }//err exit loop                                                 //~v8@sR~
  	if (!rc)                                                       //~v8@uI~
//  	if (dbcssw)                                                //~v79aR~
    	if (ebcwksw)                                               //~v79aR~
			unlink(ebcfnm);                                        //~v8@uI~
	popd[PARM_LOCALFILE]=plocalfile;	//restore                  //~v8@sI~
UTRACEP("funcftp exit rc=%d\n",rc);
    return rc;
}//funcftp
//**************************************************************** //~v8@xI~
//*ftpreproc                                                       //~v79dR~
//screen may display HOST ABEND msg                                //~v8@xI~
//**************************************************************** //~v8@xI~
int ftppreproc(int Popt,PTHREADTB Ppthtb)                          //~v8@xI~
{                                                                  //~v8@xI~
	int rc,opt;                                                    //~v8@xI~
//****************************                                     //~v8@xI~
UTRACEP("funcftp preproc entry\n");                                //~v8@xI~
    opt=SENDO_CASE|SENDO_DROPSTATUS|SENDO_CMDLINE;                 //~v8@xI~
    if (rc=cmdreadychk(opt,Ppthtb),rc)                             //~v8@xI~
    	return rc;                                                 //~v8@xI~
    screenclear(3,Ppthtb);   //2 line cmd +1                       //~v8@xI~
UTRACEP("funcftp preproc return\n");                               //~v8@xI~
    return 0;                                                      //~v8@xI~
}//ftppreproc                                                      //~v8@xI~
//**************************************************************** //~v8@jI~
//*ftpostproc                                                      //~v8@jR~
//screen may display HOST ABEND msg                                //~v8@jI~
//**************************************************************** //~v8@jI~
int ftppostproc(int Popt,PTHREADTB Ppthtb,int Prc,int Prow)        //~v8@jR~
{                                                                  //~v8@jI~
	int rc,readlen,opt;                                            //~v8@jR~
	char buff[MAX_SCREENSZ];                                       //~v8@jR~
//****************************                                     //~v8@jI~
UTRACEP("funcftp postproc entry\n");                               //~v8@qI~
                                                                   //~v8@qI~
	opt=SENDO_CHKSPF|SENDO_NORESPMSG|SENDO_DROPSTATUS|SENDO_CHKREADY;//~v8@qR~
	rc=snap3270(opt,Ppthtb,buff,sizeof(buff),&readlen);            //~v8@jR~
    if (readlen)                                                   //~v8@jI~
    {                                                              //~v79cI~
    	if (!(rc & RECVRC_READY)                                   //~v8@qI~
    	||  !USTRHEADIS(buff,WORDCHK_READY))                       //~v8@qR~
          if (!Prc)	//errmsg not yet issued                        //~v79dR~
	    	uerrmsgmt(1,"FTP failed(%s)",0,                        //~v8@qR~
                        buff);                                     //~v8@jI~
    }   //no resp data                                             //~v79cI~
    else                                                           //~v79cI~
    {                                                              //~v79cI~
        if (!Ppthtb->THTcurrow && !Ppthtb->THTcurcol)              //~v79cR~
			funcenter(SENDO_NORESPMSG,Ppthtb);      //try enter to back to spf panel//~v79cI~
    }                                                              //~v79cI~
UTRACEP("funcftp postproc return readlen=%d\n",readlen);           //~v79cR~
    return 0;                                                      //~v8@jI~
}//ftppostproc                                                     //~v8@jR~
//**************************************************************** //~v71RI~
//*wite validity chk(read after write)                             //~v8@3R~
//*return len; -1:err                                              //~v71RI~
//**************************************************************** //~v71RI~
//int putconfirm(PTHREADTB Ppthtb,char *Pcmd)                      //~v8@sR~
int putconfirm(int Popt,PTHREADTB Ppthtb,char *Pcmd)               //~v8@sR~
{                                                                  //~v71RI~
	char **popd,*preq,*phostfile,*plocalfile;                      //~v71RR~
//  int rc,opt,topt,copt=0;                                        //~v71RR~//~vafdR~
    int rc=0,opt,topt,copt=0;                                      //~vafdI~
    int copt2;                                                     //~v763I~
    char tmplocal[_MAX_PATH];                                      //~v71RR~
    char tmplocal1st[_MAX_PATH];                                   //~v725I~
    char suffix[16];                                               //~v725I~
    int ii;                                                        //~v725I~
    DSNDATA dsnd;                                                  //~v763I~
    int row;                                                       //~v8@jI~
//*****************                                                //~v71RI~
UTRACEP("putconfirm\n");                                           //~v71RI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v71RI~//~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
	preq=popd[PARM_REQ];                                           //~v71RI~
//  popd[PARM_REQ]=Ssysincmdtb[CMDID_GET].CMDTalias;	//change to Receive//~v725R~
	plocalfile=popd[PARM_LOCALFILE];                               //~v71RI~
	phostfile=popd[PARM_HOSTFILE];                                 //~v71RI~
//  getlocaltmp(phostfile,tmplocal);                               //~v725R~
//  strcat(tmplocal,".PUTGET");                                    //~v725R~
	if (!getlatestdsndata(phostfile,&dsnd)	//dsn match to previous listds//~v763I~
    &&   dsnd.DSDflag & DSDFF)	//fixed lrecl	                   //~v763I~
    	copt2=(dsnd.DSDlrecl<<16);                                 //~v763R~
    else                                                           //~v763I~
    	copt2=0;                                                   //~v763I~
                                                                   //~v71RI~
	popd[PARM_LOCALFILE]=tmplocal;                                 //~v71RI~
  for (ii=1;ii<=G3270retryput+1;ii++)                              //~v725R~
  {                                                                //~v725I~
    if (Ppthtb->THTflag & THTF_TIMEOUT)                            //~v72jI~
    {                                                              //~v72jI~
        uerrmsgmt(1,"@@@@ ReadCheck canceled by timeout",0);       //~v8@5R~
        rc=U3CR_RC_OTHER;                                          //~v72jI~
        break;                                                     //~v72jI~
    }                                                              //~v72jI~
//  popd[PARM_REQ]=Ssysincmdtb[CMDID_GET].CMDTalias;	//change to Receive//~v8@pR~
    popd[PARM_REQ]=CMD_RECEIVE;	//change to Receive                //~v8@pI~
	popd[PARM_LOCALFILE]=tmplocal;                                 //~v725I~
    sprintf(suffix,"PUTGET.%d.",ii);                               //~v725R~
    getlocaltmp(phostfile,suffix,tmplocal);                        //~v725I~
//  setuptransfercmd(1,Ppthtb,Pcmd,&topt);                         //~v8@sR~
    setuptransfercmd(Popt|SUTCO_CONFIRM,Ppthtb,Pcmd,&topt);        //~v8@sR~
//  screenclear(3,Ppthtb);   //2 line cmd +1                       //~v8@3R~
	if (rc=ftppreproc(0,Ppthtb),rc)                                //~v8@xR~
    	return 4;                                                  //~v8@xI~
    opt=SENDO_RCHK_FTP|SENDO_DROPSTATUS;                           //~v71RI~
    opt|=SENDO_WAIT_OUTPUT;                                        //~v8@jI~
	opt|=SENDO_RCHK_FTPGET;                                        //~v71RI~
	row=Ppthtb->THTcurrow;                                         //~v8@jI~
	rc=send3270(opt,Ppthtb,Pcmd);                                  //~v71RI~
	ftppostproc(0,Ppthtb,rc,row);                                  //~v8@jI~
    if (!rc)							//get success              //~v71RI~
    {                                                              //~v71RI~
		if (!(topt & SUTC_TOBIN))                                  //~v71RI~
        	copt|=(UFCO_TEXT|UFCO_TSPACE);//text comapre,ignore trailing space unmatch//~v71RI~
        else                                                       //~v71TI~
        	copt|=(UFCO_NULLAPP)         ;//allow null append      //~v71TI~
      if (copt2)	//fixed lrecl                                  //~v763I~
      {                                                            //~v763I~
        rc=ufilecomp(copt|copt2|UFCO_F1FIXED,tmplocal,plocalfile);//1:file1 not exist,2:file2 not exist,3:both not exist,4:unmatch//~v763I~
        if (rc<0)   //line split by fixed lrecl                    //~v763I~
        {                                                          //~v763I~
            uerrmsgmt(1,"@@@@ Upload(%s) long line is split by LRECL=%d(%d line incleased)",0,//~v763R~
                            phostfile,dsnd.DSDlrecl,-rc);          //~v763R~
            rc=U3CR_RC_SPLIT;                                      //~v763R~
        	unlink(tmplocal);                                      //~v763I~
            break;                                                 //~v763I~
        }                                                          //~v763I~
      }                                                            //~v763I~
      else                                                         //~v763I~
        rc=ufilecomp(copt,tmplocal,plocalfile);//1:file1 not exist,2:file2 not exist,3:both not exist,4:unmatch//~v71RR~
//  	if (rc==UFCRC_SIZE && (topt & SUTC_TOBIN))	//bincomp size unmatch//~v71TR~
//      	rc=0;	//ignore err                                   //~v71TR~
    	if (rc==UFCRC_NULLAPP)    	//bincomp null append detected //~v71TI~
        {                                                          //~v71TI~
        	uerrmsgmt(1,"Null line appended by Binaly mode Saved(%s)",0,//~v71TI~
						plocalfile);                               //~v71TI~
            rc=0;                                                  //~v71TI~
        }                                                          //~v71TI~
        if (rc)                                                    //~v71RI~
        {                                                          //~v71RI~
          if (ii<=G3270retryput)                                   //~v725R~
          {                                                        //~v725R~
            if (ii==1)  //1st time get                             //~v725R~
                strcpy(tmplocal1st,tmplocal);                      //~v725R~
            else                                                   //~v725R~
            {                                                      //~v725R~
                if (!ufilecomp(copt,tmplocal,tmplocal1st))//get is same//~v725R~
                {                                  //may cutted by RECFM=F//~v725R~
                    unlink(tmplocal);                              //~v725R~
//                  uerrmsgmt(1,"@@@@ Upload may be transformed,check source(%s) and reloaded(%s)",0,//~v8@5R~
                    uerrmsgmt(UEMO_RESPMSG|UEMO_FTPERR,"@@@@ Upload may be transformed,check source(%s) and reloaded(%s)",0,//~v8@5I~
                            plocalfile,tmplocal1st);               //~v725R~
                    rc=U3CR_RC_OTHER;                              //~v725R~
                    break;                                         //~v725R~
                }                                                  //~v725R~
                unlink(tmplocal);                                  //~v725R~
            }                                                      //~v725R~
//          uerrmsgmt(1,"@@ Upload confirmation err,retry %d of %d for %s <-- %s",0,//~v8@5R~
            uerrmsgmt(UEMO_RESPMSG|UEMO_FTPERR,"@@ Upload confirmation err,retry %d of %d for %s <-- %s",0,//~v8@5I~
                            ii,G3270retryput,phostfile,plocalfile);//~v725M~
        	if (Ppthtb->THTflag & THTF_TIMEOUT)                    //~v72jI~
            {                                                      //~v72jI~
                uerrmsgmt(1,"@@@@ Retry canceled by timeout",0);   //~v8@5R~
	            rc=U3CR_RC_OTHER;                                  //~v72jI~
                break;                                             //~v72jI~
            }                                                      //~v72jI~
            popd[PARM_REQ]=preq;                //restore          //~v725R~
            popd[PARM_LOCALFILE]=plocalfile;                       //~v725R~
//          setuptransfercmd(1,Ppthtb,Pcmd,&topt);                 //~v8@sR~
            setuptransfercmd(Popt|SUTCO_CONFIRM,Ppthtb,Pcmd,&topt);//~v8@sR~
//          screenclear(3,Ppthtb);   //2 line cmd +1               //~v8@3R~
			if (rc=ftppreproc(0,Ppthtb),rc)                        //~v8@xR~
    			return 4;                                          //~v8@xI~
            opt=SENDO_RCHK_FTP|SENDO_DROPSTATUS;                   //~v725R~
		    opt|=SENDO_WAIT_OUTPUT;                                //~v8@jI~
			row=Ppthtb->THTcurrow;                                 //~v8@jI~
            rc=send3270(opt,Ppthtb,Pcmd);       //retry put        //~v725R~
			ftppostproc(0,Ppthtb,rc,row);                          //~v8@jI~
            if (rc)                         //get success          //~v725R~
                break;                                             //~v725R~
          }                                                        //~v725R~
          else                                                     //~v725I~
          {                                                        //~v725I~
//      	uerrmsgmt(1,"@@@@ Upload Confirmation err,check source(%s) and reloaded(%s)",0,//~v8@5R~
        	uerrmsgmt(UEMO_RESPMSG|UEMO_FTPERR,"@@@@ Upload Confirmation err,check source(%s) and reloaded(%s)",0,//~v8@5I~
						plocalfile,tmplocal);                      //~v71RI~
            rc=U3CR_RC_OTHER;                                      //~v71RI~
          }                                                        //~v725I~
        }                                                          //~v71RI~
        else                                                       //~v71RI~
        {                                                          //~v725I~
        	unlink(tmplocal);                                      //~v71RI~
            break;                                                 //~v725I~
        }                                                          //~v725I~
    }                                                              //~v71RI~
    else      //read fail                                          //~v725I~
    	break;                                                     //~v725I~
  }//retry loop                                                    //~v725M~
	popd[PARM_REQ]=preq;                //restore                  //~v725M~
	popd[PARM_LOCALFILE]=plocalfile;                               //~v725M~
UTRACEP("putconfirm exit rc=%d\n",rc);                             //~v71RI~
    return rc;                                                     //~v71RR~
}//                                                                //~v71RI~
//**************************************************************** //~v71TI~
//*read chk(read twice and compare)                                //~v71TI~
//*return len; -1:err                                              //~v71TI~
//**************************************************************** //~v71TI~
//int getconfirm(PTHREADTB Ppthtb,char *Pcmd)                      //~v8@sR~
int getconfirm(int Popt,PTHREADTB Ppthtb,char *Pcmd)               //~v8@sR~
{                                                                  //~v71TI~
	char **popd,*phostfile,*plocalfile;                            //~v71TR~
//  int rc,opt,copt=0;                                             //~vafdR~
    int rc=0,opt,copt=0;                                           //~vafdI~
    char tmplocal[_MAX_PATH];                                      //~v71TI~
    char sufix[16];                                                //~v725I~
    char compfnm[2][_MAX_PATH];                                    //~v725I~
    int ii;                                                        //~v725I~
    int row;                                                       //~v8@jI~
//*****************                                                //~v71TI~
UTRACEP("getconfirm\n");                                           //~v71TI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v71TI~//~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
	plocalfile=popd[PARM_LOCALFILE];                               //~v71TI~
	phostfile=popd[PARM_HOSTFILE];                                 //~v71TI~
#ifdef AAA                                                         //~v725I~
    getlocaltmp(phostfile,tmplocal);                               //~v71TI~
    strcat(tmplocal,".GET2");                                      //~v71TR~
	popd[PARM_LOCALFILE]=tmplocal;                                 //~v71TI~
	setuptransfercmd(1,Ppthtb,Pcmd,0);                             //~v71TI~
//  screenclear(3,Ppthtb);   //2 line cmd +1                       //~v8@3R~
	if (rc=ftppreproc(0,Ppthtb))                                   //~v8@xI~
    	return 4;                                                  //~v8@xI~
    opt=SENDO_RCHK_FTP|SENDO_DROPSTATUS;                           //~v71TI~
	opt|=SENDO_WAIT_OUTPUT;                                        //~v8@jI~
	opt|=SENDO_RCHK_FTPGET;                                        //~v71TI~
		row=Ppthtb->THTcurrow;                                     //~v8@jI~
	rc=send3270(opt,Ppthtb,Pcmd);                                  //~v71TI~
	ftppostproc(0,Ppthtb,rc,row);                                  //~v8@jI~
    if (!rc)							//get success              //~v71TI~
    {                                                              //~v71TI~
        rc=ufilecomp(copt,tmplocal,plocalfile);//1:file1 not exist,2:file2 not exist,3:both not exist,4:unmatch//~v71TI~
        if (rc)                                                    //~v71TI~
        {                                                          //~v71TI~
        	uerrmsgmt(1,"File Receive Confirmation err,check 1st read(%s) and 2nd(%s)",0,//~v721R~
						plocalfile,tmplocal);                      //~v71TI~
            rc=U3CR_RC_OTHER;                                      //~v71TI~
        }                                                          //~v71TI~
        else                                                       //~v71TI~
        	unlink(tmplocal);                                      //~v71TI~
    }                                                              //~v71TI~
#else                                                              //~v725I~
	strcpy(compfnm[0],plocalfile);	//1st filename to be compared  //~v725I~
    opt=SENDO_RCHK_FTP|SENDO_DROPSTATUS|SENDO_RCHK_FTPGET;         //~v725I~
	opt|=SENDO_WAIT_OUTPUT;                                        //~v8@jI~
    popd[PARM_LOCALFILE]=tmplocal;                                 //~v725I~
    for (ii=1;ii<=G3270retryget+1;ii++)                            //~v725R~
    {                                                              //~v725I~
    	sprintf(sufix,"GET.%d.",ii);                               //~v725R~
        getlocaltmp(phostfile,sufix,tmplocal);                     //~v725I~
//      setuptransfercmd(1,Ppthtb,Pcmd,0);                         //~v8@sR~
        setuptransfercmd(Popt|SUTCO_CONFIRM,Ppthtb,Pcmd,0);        //~v8@sR~
//      screenclear(3,Ppthtb);   //2 line cmd +1                   //~v8@3R~
		if (rc=ftppreproc(0,Ppthtb),rc)                            //~v8@xR~
    		return 4;                                              //~v8@xI~
		row=Ppthtb->THTcurrow;                                     //~v8@jI~
        rc=send3270(opt,Ppthtb,Pcmd);                              //~v725I~
		ftppostproc(0,Ppthtb,rc,row);                              //~v8@jI~
        if (rc)                            //get success           //~v725I~
        	break;                                                 //~v725I~
        if (ii==1)	//1st retry                                    //~v725I~
        {                                                          //~v725I~
            rc=ufilecomp(copt,tmplocal,plocalfile);//1:file1 not exist,2:file2 not exist,3:both not exist,4:unmatch//~v725I~
            if (!rc)                                               //~v725I~
            {                                                      //~v725I~
                unlink(tmplocal);                                  //~v725I~
                break;                                             //~v725I~
            }                                                      //~v725I~
            strcpy(compfnm[1],tmplocal);                           //~v725I~
        }                                                          //~v725I~
        else                                                       //~v725I~
        {                                                          //~v725I~
        	rc=ufilecomp(copt,tmplocal,compfnm[0]);                //~v725I~
            if (!rc)	//get1==get3!=get2                         //~v725I~
            {                                                      //~v725I~
                unlink(compfnm[1]);        //get2                  //~v725R~
    			if (!strcmp(plocalfile,compfnm[0]))                //~v725I~
	                unlink(tmplocal);      //get3                  //~v725R~
                else                                               //~v725I~
                {                                                  //~v725I~
	                unlink(compfnm[0]);    //get1                  //~v725I~
	                uxmove(tmplocal,plocalfile,FILE_ALL,DCPY_EXISTING); //get3//~v725R~
                }                                                  //~v725I~
                break;                                             //~v725I~
            }                                                      //~v725I~
        	rc=ufilecomp(copt,tmplocal,compfnm[1]);                //~v725I~
            if (!rc)	//get2==get3!=get1                         //~v725I~
            {                                                      //~v725I~
                unlink(compfnm[0]);   //get1                       //~v725I~
                unlink(compfnm[1]);   //get2                       //~v725I~
                uxmove(tmplocal,plocalfile,FILE_ALL,DCPY_EXISTING); //get3//~v725R~
                break;                                             //~v725I~
            }                                                      //~v725I~
//          get1!=get2!=get3                                       //~v725I~
            unlink(compfnm[0]);   //get1                           //~v725I~
            strcpy(compfnm[0],compfnm[1]);                         //~v725I~
            strcpy(compfnm[1],tmplocal);                           //~v725I~
        }                                                          //~v725I~
        if (ii<=G3270retryget)                                     //~v725R~
//      	uerrmsgmt(1,"@@ Download confirmation err,retry %d of %d for %s --> %s",0,//~v8@5R~
        	uerrmsgmt(UEMO_RESPMSG|UEMO_FTPERR,"@@ Download confirmation err,retry %d of %d for %s --> %s",0,//~v8@5I~
                            ii,G3270retryget,phostfile,plocalfile);//~v725R~
        if (Ppthtb->THTflag & THTF_TIMEOUT)                        //~v72jI~
        {                                                          //~v72jI~
            uerrmsgmt(1,"@@@@ Retry canceled by timeout",0);       //~v72jI~
	        rc=U3CR_RC_OTHER;                                      //~v72jI~
            break;                                                 //~v72jI~
        }                                                          //~v72jI~
    }//retry loop                                                  //~v725I~
    if (ii>G3270retryget+1)                                        //~v725R~
    {                                                              //~v725I~
    	if (!strcmp(plocalfile,compfnm[0]))                        //~v725I~
            unlink(compfnm[0]);   //delete localfile for retry by /y-//~v725R~
        uerrmsgmt(1,"@@@@ %s Download err(retry count(%d) exausted)",0,//~v8@5R~
                    phostfile,G3270retryget);                      //~v725R~
        rc=U3CR_RC_OTHER;                                          //~v725I~
    }                                                              //~v725I~
#endif                                                             //~v725I~
	popd[PARM_LOCALFILE]=plocalfile;    //recover                  //~v725M~
UTRACEP("getconfirm exit rc=%d\n",rc);                             //~v71TI~
    return rc;                                                     //~v71TI~
}//                                                                //~v71TI~
//**************************************************************** //~v71RI~
//get tmpname to put confirm rc=1:ok,0:err                         //~v71RI~
//**************************************************************** //~v71RI~
//int getlocaltmp(char *Phostfile,char *Poutfname)                 //~v725R~
int getlocaltmp(char *Phostfile,char *Psuffix,char *Poutfname)     //~v725I~
{                                                                  //~v71RI~
	char *pc,lastname[DSN_MAXLEN],prefix[DSN_MAXLEN+32];           //~v71RR~
//*****************                                                //~v71RI~
	u3270getlastname(0,Phostfile,lastname);                        //~v71RI~
//  sprintf(prefix,"xe3270pc.%s.",lastname);                       //~v725R~
    sprintf(prefix,"xe3270pc.%s.%s",lastname,Psuffix);             //~v725I~
	pc=utempnam(0,prefix,Poutfname);                               //~v71RR~
    return pc!=0;                                                  //~v71RI~
}//getlocaltmp                                                     //~v71RI~
//****************************************************************
//*setup ftp cmd
//*return len; -1:err
//****************************************************************
//int setuptransfercmd(PTHREADTB Ppthtb,char *Pcmd)                //~v71RR~
int setuptransfercmd(int Popt,PTHREADTB Ppthtb,char *Pcmd,int *Pptopt)//~v8@sR~
{
	char **popd,*pc,*pc2,*phostfile,*preq,*plocalfile;
    int rc,sendsw;
    int saveconfsw;                                                //~v71RI~
	FILEFINDBUF3 ffb3;
    int topt=0;                                                    //~v71RI~
    int repopt=0;                                                  //~v723I~
    int dbcssw;                                                    //~v8@sR~
    int sbcsconvsw;                                                //~v79aR~
//*****************
    saveconfsw=(Popt & 0x01);	//save confirm                     //~v71RI~
	dbcssw=(Popt & SUTCO_DBCSCONV);  //binary mdeo by DBCSCONV     //~v8@sI~
	sbcsconvsw=(Popt & (SUTCO_SBCSCONV));  //binary mdeo by SBCSCONV//~v79aR~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
	preq=popd[PARM_REQ];
	phostfile=popd[PARM_HOSTFILE];
	plocalfile=popd[PARM_LOCALFILE];
                                                                   //~v71RI~
  if (saveconfsw)                                                  //~v71RI~
    sendsw=0;                                                      //~v71RI~
  else                                                             //~v71RI~
  {                                                                //~v71RI~
    sendsw=(Ppthtb->THTreqcode==THTRQ_TRANSFER_PUT);
    if (sendsw)
    	if (!strchr(phostfile,'(') || !strchr(phostfile,')'))	//support pds only to avoid directory destry
    	{
#ifdef AAA                                                         //~v8@7I~
		  if (Ppthtb->THTflag & THTF_CMDTHREAD)        //req frm cmd thread//~v72hI~
          {                                                        //~v72hI~
//      	uerrmsgmt(1,"supported PDS member only for upload target",0);//~v72hR~
        	uerrmsgmt(1,"Console support upload cmd for PDS member only",0);//~v72hR~
            return -1;
          }                                                        //~v72hI~
          else                                                     //~v72hI~
#endif                                                             //~v8@7I~
            if (!(G3270opt & G3270OPT_PSUPLOAD))                   //~v72hR~
            {                                                      //~v72hI~
	        	uerrmsgmt(1,"set cfg file %s parameter to allow upload to DSNAME(without MEMBER specification)",0,//~v72hI~
							CONFIGP_PSUPLOAD);                     //~v72hI~
    	        return -1;                                         //~v72hI~
            }                                                      //~v72hI~
        }
//  rc=ufstat(plocalfile,&ffb3);                                   //~vb30R~
    rc=(int)ufstat(plocalfile,&ffb3);                              //~vb30I~
    if (rc)	//not found
    {
    	if (sendsw)
        {
        	uerrmsgmt(1,"%s not found(upload)",0,
						plocalfile);
            return -1;
        }
    }
    else
    {
    	if (ffb3.attrFile & FILE_DIRECTORY)
        {
        	uerrmsgmt(1,"%s is directory",0,
						plocalfile);
            return -1;
        }
    }
  }                                                                //~v71RI~
	pc=Pcmd;
	pc+=sprintf(Pcmd,"Transfer Direction=%s HostFile=%s LocalFile=%s",
    		preq,phostfile,plocalfile);
    for (popd+=PARM_MINIMUM;*popd;popd++)
    {
    	pc2=*popd;
    	if (!stricmp(pc2,"Bin"))
        {
			topt|=SUTC_TOBIN;                                      //~v71RI~
    		pc+=sprintf(pc," Mode=binary");
            continue;
        }
    	if (!stricmp(pc2,"Rep"))
        {
        	repopt=1;                                              //~v723I~
    		pc+=sprintf(pc," Exist=replace");
            continue;
        }
    	if (!stricmp(pc2,"App"))
        {
          if (!saveconfsw)//not confirmation get(APPEND mode is get only)//~v8@zI~
	       if (!(Popt & SUTCO_GETAPPCONF))  //append mode process by xe3270//~v8@CR~
    		pc+=sprintf(pc," Exist=append");
            continue;
        }
//      if (dbcssw)                                                //~v79aR~
        {                                                          //~v79aR~
        	if (USTRHEADIS_IC(pc2,TSOFTP_PARM_DBCS))               //~v8@sR~
            	continue;                                          //~v8@sR~
    		if (!stricmp(pc2,TSOFTP_PARM_RECFMF))                  //~v8@sR~
            	continue;                                          //~v8@sR~
    		if (!stricmp(pc2,TSOFTP_PARM_NUMSTD))                  //~v8@CI~
            	continue;                                          //~v8@CI~
    		if (!stricmp(pc2,TSOFTP_PARM_RECFMV))                  //~v8@sR~
            	continue;                                          //~v8@sR~
        	if (USTRHEADIS_IC(pc2,TSOFTP_PARM_LRECL))              //~v8@sR~
           	 	continue;                                          //~v8@sR~
        }                                                          //~v79aR~
    	pc+=sprintf(pc," %s",*popd);
    }
//  if (dbcssw)  //binary mdeo by DBCSCONV                         //~v79aR~
    if (dbcssw||sbcsconvsw)  //binary mdeo by DBCSCONV             //~v79aR~
    {                                                              //~v8@uI~
    	pc+=sprintf(pc," Mode=binary");                            //~v8@sI~
		topt|=SUTC_TOBIN;                                          //~v8@uI~
    }                                                              //~v8@uI~
//  if (!repopt && saveconfsw)//no rep option but confirmation get //~v8@CR~
    if (!repopt)                                                   //~v8@CR~
      if (saveconfsw //confirmation get                            //~v8@CR~
//    ||  (Popt & (SUTCO_DBCSCONV|SUTCO_GETAPPCONF))  //another local temp used(EBC or APPEND work)//~v79aR~
	  || (dbcssw||sbcsconvsw)                                      //~v79aR~
      ||  (Popt & SUTCO_GETAPPCONF)  //another local temp used(EBC or APPEND work)//~v79aR~
         )                                                         //~v8@CR~
    	pc+=sprintf(pc," Exist=replace");                          //~v723I~
    if (Pptopt)	                                                   //~v71RI~
	    *Pptopt=topt;                                              //~v71RI~
    return 0;
}//setuptransfercmd                                                //~v71RR~
//**************************************************************** //~v8@sI~
//*check dbcs option                                               //~v8@sR~
//*return len; -1:err                                              //~v8@sI~
//**************************************************************** //~v8@sI~
int chkdbcsoption(int Popt,PTHREADTB Ppthtb,int *Pptopt,char *Ppebcfnm)//~v8@sR~
{                                                                  //~v8@sI~
	char **popd,*pc2,*plocalfile;                                  //~v8@sR~
    int topt=0,dbcssw=0,lrecl=0;                                   //~v8@sI~
    int sbcsa2asw,/*sbcsmapcsw,*/sbcsconvsw,sbcsmapsw;             //~v79aR~
    int binmode=0;                                                 //~v79aI~
//*****************                                                //~v8@sI~
UTRACEP("chkdbcsoption entry\n");                                  //~v8@sI~
//  popd=(char**)(ULONG)Ppthtb->THTparm;                           //~v8@sI~//~vafkR~
    popd=(char**)(ULPTR)Ppthtb->THTparm;                           //~vafkI~
	plocalfile=popd[PARM_LOCALFILE];                               //~v8@sI~
    sbcsmapsw=UCECF_ISAVAIL_SBCSMAP(G3270pmapcfg);//sbcs full mapping//~v79aR~
    sbcsconvsw=UCECF_ISAVAIL_SBCSCV(G3270pmapcfg) //sbcs converter //~v79aR~
             ||sbcsmapsw;                                          //~v79aR~
    sbcsa2asw=UCECF_ISAVAIL_A2A(G3270pmapcfg);                     //~v79aR~
UTRACEP("chkdbcsoption G3270pmapcfg=%p,sbcsmapsw=%d,sbcsconvsw=%d,sbcsa2asw=%d\n",G3270pmapcfg,sbcsmapsw,sbcsconvsw,sbcsa2asw);//~v79aR~
    for (popd+=PARM_MINIMUM;*popd;popd++)                          //~v8@sI~
    {                                                              //~v8@sI~
    	pc2=*popd;                                                 //~v8@sI~
    	if (!stricmp(pc2,"App"))                                   //~v8@CR~
        {                                                          //~v8@CR~
			topt|=SUTC_APPEND;     //append mode                   //~v8@CR~
            continue;                                              //~v8@CR~
        }                                                          //~v8@CR~
    	if (!stricmp(pc2,"Bin"))                                   //~v79aI~
        {                                                          //~v79aI~
            binmode=1;                                             //~v79aI~
            continue;                                              //~v79aI~
        }                                                          //~v79aI~
//      if (USTRHEADIS_IC(pc2,TSOFTP_PARM_DBCSDEF))                //~v79aR~
        if (!stricmp(pc2,TSOFTP_PARM_DBCSDEF)) //DBCS              //~v79aI~
        {                                                          //~v8@sI~
            dbcssw=1;                                              //~v8@sI~
			topt|=SUTC_DBCS939;       //default                    //~v8@sI~
            continue;                                              //~v8@sI~
        }                                                          //~v8@sI~
        if (USTRHEADIS_IC(pc2,TSOFTP_PARM_DBCS))                   //~v8@sI~
//                                             //DBCS=             //~v79aI~
        {                                                          //~v8@sI~
          if (stricmp(pc2+sizeof(TSOFTP_PARM_DBCS)-1,CPNODBCS))	//sbcs//~v79aR~
          {                                                        //~v79aR~
            dbcssw=1;                                              //~v8@sI~
            if (!stricmp(pc2+sizeof(TSOFTP_PARM_DBCS)-1,CP930))    //~v8@sI~
				topt|=SUTC_DBCS930;                                //~v8@sI~
            else                                                   //~v8@sI~
            if (!stricmp(pc2+sizeof(TSOFTP_PARM_DBCS)-1,CP939))    //~v8@sI~
				topt|=SUTC_DBCS939;                                //~v8@sI~
            else                                                   //~v8@sI~
            if (!stricmp(pc2+sizeof(TSOFTP_PARM_DBCS)-1,CPCJK))    //~v79aI~
            {                                                      //~v79aI~
      			if (!UCECF_ISAVAIL_DBCSCV(G3270pmapcfg))           //~v79aR~
                {                                                  //~v79aI~
	        		uerrmsgmt(1,"No valid DBCS converter,chk cfg parm %s",0,//~v79aI~
							CONFIGP_CHARSETCFG);                   //~v79aI~
        	    	return -1;                                     //~v79aI~
                }                                                  //~v79aI~
				topt|=SUTC_DBCSCJK;                                //~v79aI~
            }                                                      //~v79aI~
            else                                                   //~v79aI~
            {                                                      //~v8@sI~
        		uerrmsgmt(1,"DBCS parm(%s) err",0,                 //~v8@sI~
						pc2);                                      //~v8@sI~
            	return -1;                                         //~v8@sI~
            }                                                      //~v8@sI~
          }//nodbcs                                                //~v79aR~
            continue;                                              //~v8@sI~
        }                                                          //~v8@sI~
//    	if (dbcssw && !stricmp(pc2,TSOFTP_PARM_RECFMF))            //~v79aR~
      	if (!stricmp(pc2,TSOFTP_PARM_RECFMF))                      //~v79aR~
        {                                                          //~v8@sI~
			topt|=SUTC_FIXED;                                      //~v8@sI~
            continue;                                              //~v8@sI~
        }                                                          //~v8@sI~
//  	if (dbcssw && !stricmp(pc2,TSOFTP_PARM_NUMSTD))            //~v79aR~
    	if (!stricmp(pc2,TSOFTP_PARM_NUMSTD))                      //~v79aR~
        {                                                          //~v8@CI~
			topt|=SUTC_NUMSTD;                                     //~v8@CI~
            continue;                                              //~v8@CI~
        }                                                          //~v8@CI~
//#ifdef VBSUPP                                                    //~v79aR~
//  	if (dbcssw && !stricmp(pc2,TSOFTP_PARM_RECFMV))            //~v79aR~
    	if (!stricmp(pc2,TSOFTP_PARM_RECFMV))                      //~v79aR~
        {                                                          //~v8@sI~
			topt|=SUTC_VARIABLE;                                   //~v8@sI~
            continue;                                              //~v8@sI~
        }                                                          //~v8@sI~
//#endif                                                           //~v79aR~
//      if (dbcssw && USTRHEADIS_IC(pc2,TSOFTP_PARM_LRECL))        //~v79aR~
        if (USTRHEADIS_IC(pc2,TSOFTP_PARM_LRECL))                  //~v79aR~
        {                                                          //~v8@sI~
            lrecl=atoi(pc2+sizeof(TSOFTP_PARM_LRECL)-1);           //~v8@sI~
            lrecl<<=16;                                            //~v8@sI~
			topt|=lrecl;                                           //~v8@sI~
            continue;                                              //~v8@sI~
        }                                                          //~v8@sI~
    }                                                              //~v8@sI~
  if (binmode)                                                     //~v79aR~
  {                                                                //~v79aI~
	topt&=SUTC_APPEND;     //remains appendsw only                 //~v79aI~
  }                                                                //~v79aI~
  else                                                             //~v79aI~
  {                                                                //~v79aI~
//  if (dbcssw)                                                    //~v79aR~
    if (dbcssw||sbcsconvsw)                                        //~v79aR~
    {                                                              //~v8@sI~
     if (!(topt & SUTC_VARIABLE))                                  //~v79aI~
     {                                                             //~v79aI~
		if (!(topt & (SUTC_VARIABLE|SUTC_FIXED)))                  //~v8@sI~
            topt|=SUTC_FIXED;   //default;                         //~v8@sI~
		if (!lrecl)                                                //~v8@sI~
            lrecl=80;           //default                          //~v8@sI~
      if (dbcssw)	//DBCS trans                                   //~v79aR~
		topt|=(SUTC_TOBIN|SUTC_DBCSCONV);                          //~v8@sI~
      else                                                         //~v79aR~
      {                                                            //~v79aR~
			topt|=(SUTC_TOBIN|SUTC_SBCSCONV);                      //~v79aR~
      }                                                            //~v79aR~
    	sprintf(Ppebcfnm,"%s%s",plocalfile,FNM_EBC);               //~v8@sR~
    	if (Ppthtb->THTreqcode==THTRQ_TRANSFER_PUT)                //~v8@sI~
			topt|=SUTC_2EBC;                                       //~v8@sI~
     }//not valiable                                               //~v79aI~
    }                                                              //~v8@sI~
    else                                                           //~v79aI~
    if (sbcsa2asw)                                                 //~v79aI~
    {                                                              //~v79aI~
		topt|=SUTC_SBCSA2A;                                        //~v79aI~
    	sprintf(Ppebcfnm,"%s%s",plocalfile,FNM_EBC);               //~v79aI~
    	if (Ppthtb->THTreqcode==THTRQ_TRANSFER_PUT)                //~v79aI~
			topt|=SUTC_2EBC;                                       //~v79aI~
    }                                                              //~v79aI~
  }//!binmode                                                      //~v79aI~
    if (Pptopt)                                                    //~v8@sI~
	    *Pptopt=topt;                                              //~v8@sI~
UTRACEP("chkdbcsoption return opt=%x\n",topt);                     //~v8@sI~
    return 0;                                                      //~v8@sI~
}//chkdbcsoption                                                   //~v8@sI~
//**************************************************************** //~v8@sI~
//*local<-ebc(DBCS:cp930/cp939 binary downloaded) conversion       //~v8@sR~
//**************************************************************** //~v8@sI~
int convebc2local(int Popt,char *Pplocalfile,char *Ppebcfile)      //~v8@sR~
{                                                                  //~v8@sI~
	FILE *fhi,*fho;                                                //~v8@sI~
	int rc=0,cvopt,swfixed;                                        //~v8@sR~
    char *pinpfnm,*poutfnm;                                        //~v8@sI~
    UCHAR *pbuffi,*pbuffo;                                         //~v8@sR~
//  int readlen,outlen,lrecl,writelen;                             //~v8@uR~//~va70R~
//  UINT readlen;                                                  //~va70I~//~vb30R~
    int readlen;                                                   //~vb30I~
    int outlen,lrecl,writelen;                                     //~va70I~
    int errch;                                                     //~v8@sI~
    int rc2;                                                       //~v8@zI~
    int opt;                                                       //~v79aI~
#ifdef LNX                                                         //~v8@zI~
    UCHAR *pbuffw=Sebcbuffw;                                       //~v8@zI~
	int eucopt=0,wklen;                                            //~v8@zI~
#endif                                                             //~v8@zI~
#ifdef VBSUPP                                                      //~v8@uI~
    int lreclv;                                                    //~v8@uI~
#endif                                                             //~v8@uI~
//*****************************                                    //~v8@sI~
	pinpfnm=Ppebcfile;                                             //~v8@sI~
	poutfnm=Pplocalfile;                                           //~v8@sI~
    pbuffi=Sebcbuffi;                                              //~v8@sI~
    pbuffo=Sebcbuffo;                                              //~v8@sI~
    lrecl=Popt>>16;                                                //~v8@sI~
    swfixed=(Popt & SUTC_FIXED);                                   //~v8@sI~
    if (Popt & SUTC_DBCS930)                                       //~v8@sI~
    	cvopt=EBC2ASC_CP290;    	//ebc2asc use cp290(not cp1027)//~v8@sI~
    else                                                           //~v8@sI~
    	cvopt=0;                                                   //~v8@sR~
    cvopt|=0                                                       //~v8@sR~
		//EBC2ASC_CRLF   0x01                                      //~v8@sI~
		//EBC2ASC_A2E        	//ascii-->ebc                      //~v8@sI~
		| EBC2ASC_CTL        	//ctl char conv                    //~v8@sI~
		//EBC2ASC_NEC      		//dbcs map to nec area             //~v8@sI~
		| EBC2ASC_IBM      	    //dbcs map to ibm area             //~v8@sI~
		//EBC2ASC_OLD          //oldjis(78) seq                    //~v8@sI~
		| EBC2ASC_NEW      		//newjis(83) seq                   //~v8@sI~
		| EBC2ASC_DBCS   		//DBCS conv                        //~v8@sI~
		| EBC2ASC_SOSI          //rep by space(e2a)                //~v8@uR~
		//EBC2ASC_SOSIAS		  //asume so before the line top(e2a)//~v8@sI~
		//EBC2ASC_SOSID  		  //del sosi(e2a/a2e)              //~v8@sI~
		//EBC2ASC_SOSIOS 		  //override boundary space(a2e)   //~v8@sI~
		//EBC2ASC_BUFTOP 			//previous byte can not be rep by SO for a2e//~v8@sI~
		//EBC2ASC_LNCONT 			//line continued to next       //~v8@sI~
		//EBC2ASC_SOCONT 			//SO status continuing         //~v8@sI~
        ;                                                          //~v8@sI~
	chksjisoption(&cvopt);       //apply sjis option               //~v79fR~
    if (Popt & SUTC_DBCSCJK)   //DBCS other than cp930 cp939       //~v79aR~
    {                                                              //~v79aI~
	    cvopt|=EBC2ASC_EXT;		//use external converter           //~v79aR~
    }                                                              //~v79aI~
    else                                                           //~v79aI~
    if (!(Popt & SUTC_DBCSCONV))                                   //~v79aI~
    {                                                              //~v79aR~
        cvopt&=~EBC2ASC_DBCS;                                      //~v79aR~
    	if (Popt & (SUTC_SBCSCONV))   //SBCS converter             //~v79cI~
        {                                                          //~v79aR~
	    	cvopt|=EBC2ASC_EXT;                                    //~v79aR~
        }                                                          //~v79aR~
        else                                                       //~v79aR~
        if (Popt & SUTC_SBCSA2A)  //complementary mapping (A2F/F2A)//~v79aR~
        {                                                          //~v79aR~
            swfixed=0;      //use textmode transfer                //~v79aR~
            cvopt|=EBC2ASC_EXT|EBC2ASC_SBCSMAPA2A;      //use external converter//~v79aI~
        }                                                          //~v79aR~
    }                                                              //~v79aR~
UTRACEP("ebc2local Popt=%x,cvopt=%x,swfixed=%d\n",Popt,cvopt,swfixed);//~v79aR~
//*file1                                                           //~v8@sI~
	fhi=fopen(pinpfnm,"rb");	//exit when open faile             //~v8@sR~
UTRACEP("OPEN inp=%s,fh=%x\n",pinpfnm,fhi);                        //~v8@zI~
    if (!fhi)                                                      //~v8@sR~
    {                                                              //~v8@sI~
        uerrmsgmt(1,"%s open failed",0,                            //~v8@sR~
           		 pinpfnm);                                         //~v8@sR~
        return 4;                                                  //~v8@sI~
    }                                                              //~v8@sI~
  if (Popt & SUTC_APPEND)   //append option                        //~v8@CI~
	fho=fopen(poutfnm,"ab");                                       //~v8@CI~
  else                                                             //~v8@CI~
	fho=fopen(poutfnm,"wb");                                       //~v8@sR~
UTRACEP("OPEN out=%s,fh=%x\n",poutfnm,fho);                        //~v8@zI~
    if (!fho)                                                      //~v8@sI~
    {                                                              //~v8@sI~
        fclose(fhi);                                               //~v8@zI~
        uerrmsgmt(1,"%s open failed",0,                            //~v8@sR~
           		 poutfnm);                                         //~v8@sI~
        return 4;                                                  //~v8@sI~
    }                                                              //~v8@sI~
    if (!swfixed)//text mode transfer                              //~v79aR~
    {                                                              //~v79aI~
    	opt=UFGETS_PC|UFGETS_UNIX;                                 //~v79aI~
    	ufgetsinit(opt,0/*buffsz:default*/,0/*binrate*/,0/*lrecl of bin file*/);//~v79aI~
    }                                                              //~v79aI~
    for (;;)                                                       //~v8@sI~
    {                                                              //~v8@sI~
//#ifdef VBSUPP                                                    //~v79aR~
        if (swfixed)                                               //~v8@sI~
        {                                                          //~v8@sI~
//#endif                                                           //~v79aR~
//            readlen=fread(pbuffi,1,(UINT)lrecl,fhi);               //~v8@sI~//~vb30R~
              readlen=(int)fread(pbuffi,1,(UINT)lrecl,fhi);        //~vb30I~
            if (!readlen)                                          //~v8@sI~
            	break;                                             //~v8@sI~
//          if (readlen<lrecl)                                     //~va70R~
            if ((int)readlen<lrecl)                                //~va70I~
//          	memset(pbuffi+readlen,' ',(UINT)(lrecl-readlen));  //~v8@sI~//~vb30R~
            	memset(pbuffi+readlen,' ',(size_t)(lrecl-readlen));//~vb30I~
//#ifdef VBSUPP    //not tested                                    //~v79aR~
        }                                                          //~v8@sI~
        else                                                       //~v8@sI~
        {                                                          //~v8@sI~
#ifdef VBSUPP    //not tested                                      //~v79aI~
            readlen=fread(pbuffi,1,VLRHSZ,fhi);                    //~v8@sR~
            if (!readlen)                                          //~v8@sI~
            	break;                                             //~v8@sI~
            lreclv=*pbuffi*256+*(pbuffi+1);                        //~v8@sR~
            if (readlen<VLRHSZ                                     //~v8@sR~
            ||  (readlen=fread(pbuffi,1,lreclv-VLRHSZ,fhi),readlen<lreclv-VLRHSZ)//~v8@sR~
               )                                                   //~v8@sI~
    		{                                                      //~v8@sI~
        		uerrmsgmt(1,"%s variable record length file LRH format err",0,//~v8@sR~
           				 pinpfnm);                                 //~v8@sI~
        		return 4;                                          //~v8@sI~
    		}                                                      //~v8@sI~
#endif                                                             //~v79aI~
			if (ufgets(pbuffi,EBCBUFFSZ,fhi,&readlen,0))           //~v79aI~
        		break;                                             //~v79aI~
        }                                                          //~v8@sI~
//#endif                                                           //~v79aR~
        errch='?';                                                 //~v8@sR~
#ifdef LNX                                                         //~v8@zI~
//    if (G3270opt & G3270OPT_EUC) //locale is euc                 //~v79xR~
      if (!(cvopt & EBC2ASC_EXT) && (G3270opt & G3270OPT_EUC)) //locale is euc//~v79xI~
      {                                                            //~v8@zI~
UTRACED("ebc ",pbuffi,readlen);                                    //~v8@zI~
    	ucvebc2asc(cvopt,pbuffi,0/*pdbcs*/,pbuffw,readlen,errch,&wklen); 	//0:dbcs,0:rep char//~v8@zR~
UTRACED("sjis",pbuffw,wklen);                                      //~v8@zI~
    	ushift2euc(pbuffw,0/*pdbcs*/,wklen,pbuffo,0/*dbcs*/,&outlen,eucopt);//~v8@zR~
UTRACED("euc",pbuffo,outlen);                                      //~v8@zI~
      }                                                            //~v8@zI~
      else                                                         //~v8@zI~
#endif                                                             //~v8@zI~
      {                                                            //~v8@zI~
UTRACED("ebc ",pbuffi,readlen);                                    //~v8@zI~
    	ucvebc2asc(cvopt,pbuffi,0/*pdbcs*/,pbuffo,readlen,errch,&outlen); 	//0:dbcs,0:rep char//~v8@zR~
UTRACED("sjis",pbuffo,outlen);                                     //~v8@zI~
      }                                                            //~v8@zI~
        *(pbuffo+outlen++)='\n';                                   //~v8@sR~
//      writelen=fwrite(pbuffo,1,(UINT)outlen,fho);                //~v8@sI~//~vb30R~
        writelen=(int)fwrite(pbuffo,1,(size_t)outlen,fho);         //~vb30I~
        if (writelen<outlen)                                       //~v8@sI~
        {                                                          //~v8@sI~
            uerrmsgmt(1,"%s write failed",0,                       //~v8@sR~
                     poutfnm);                                     //~v8@sI~
            rc=4;                                                  //~v8@zI~
            break;                                                 //~v8@zR~
        }                                                          //~v8@sI~
  	}                                                              //~v8@sR~
	rc2=fclose(fhi);                                               //~v8@zR~//~vaa7R~
//UTRACEP("CLOSE inp rc=%d,fh=%x\n",rc2,fhi);                      //+vbzGR~
UTRACEP("CLOSE inp rc=%d\n",rc2);   //do not use fhi after closed  //+vbzGI~
    rc2=rc2;//for compiler warning                                 //~vaa7I~
	rc2=fclose(fho);                                               //~v8@zR~//~vaa7R~
//UTRACEP("CLOSE out rc=%d,fh=%x\n",rc2,fho);                      //+vbzGR~
UTRACEP("CLOSE out rc=%d\n",rc2);                                  //+vbzGI~
	return rc;                                                     //~v8@zR~
}//convebc2local                                                   //~v8@sR~
//**************************************************************** //~v8@sI~
//*local->ebc(DBCS:cp930/cp939 binary upload) conversion           //~v8@sI~
//*assumption fixed lrecl ajusted considering SO/SI space          //~v8@sI~
//**************************************************************** //~v8@sI~
int convlocal2ebc(int Popt,char *Pplocalfile,char *Ppebcfile)      //~v8@sI~
{                                                                  //~v8@sI~
	FILE *fhi,*fho;                                                //~v8@sI~
	int rc=0,cvopt,swfixed;                                        //~v8@sR~
    char *pinpfnm,*poutfnm;                                        //~v8@sI~
    UCHAR *pbuffi,*pbuffo,*pc;                                     //~v8@uR~
    UCHAR *psjis,*pc0;                                             //~v8@CI~
//  int readlen,outlen,lrecl;                                      //~v8@uR~//~va70R~
//  UINT readlen;                                                  //~va70I~//~vb30R~
    int  readlen;                                                  //~vb30I~
    int outlen,lrecl;                                              //~va70I~
    int reslen,writelen;                                           //~v8@uR~
    int errch;                                                     //~v8@sI~
    int rc2;                                                       //~v8@zI~
    int sjislen,swnumstd,spacelen,shiftlen;                        //~v8@CR~
    int opt;                                                       //~v79bI~
    int numoksw;                                                   //~v79hR~
#ifdef VBSUPP                                                      //~v8@uI~
    int lreclv;                                                    //~v8@uI~
    UCHAR vlrh[VLRHSZ];                                            //~v8@uM~
#endif                                                             //~v8@uI~
#ifdef LNX                                                         //~v8@zI~
    UCHAR *pbuffw=Sebcbuffw;                                       //~v8@zI~
	int eucopt=0,wklen;                                            //~v8@zI~
#endif                                                             //~v8@zI~
//*****************************                                    //~v8@sI~
	pinpfnm=Pplocalfile;                                           //~v8@sR~
	poutfnm=Ppebcfile;                                             //~v8@sR~
    pbuffi=Sebcbuffi;                                              //~v8@sI~
    pbuffo=Sebcbuffo;                                              //~v8@sI~
    lrecl=Popt>>16;                                                //~v8@sI~
    swfixed=(Popt & SUTC_FIXED);                                   //~v8@sI~
    swnumstd=(Popt & SUTC_NUMSTD);                                 //~v8@CI~
    if (Popt & SUTC_DBCS930)                                       //~v8@sI~
    	cvopt=EBC2ASC_CP290;    	//ebc2asc use cp290(not cp1027)//~v8@sI~
    else                                                           //~v8@sI~
    	cvopt=0;                                                   //~v8@sR~
    cvopt|=0                                                       //~v8@sI~
		//EBC2ASC_CRLF   0x01                                      //~v8@sI~
		//EBC2ASC_A2E        	//ascii-->ebc                      //~v8@sI~
		| EBC2ASC_A2E        	//ascii-->ebc                      //~v79aI~
		| EBC2ASC_CTL        	//ctl char conv                    //~v8@sI~
		//EBC2ASC_NEC      		//dbcs map to nec area             //~v8@sI~
		| EBC2ASC_IBM      	    //dbcs map to ibm area             //~v8@sI~
		//EBC2ASC_OLD          //oldjis(78) seq                    //~v8@sI~
		| EBC2ASC_NEW      		//newjis(83) seq                   //~v8@sI~
		| EBC2ASC_DBCS   		//DBCS conv                        //~v8@sI~
		//EBC2ASC_SOSI          //default;isrt(a2e),rep by space(e2a)//~v8@uR~
		//EBC2ASC_SOSIAS		  //asume so before the line top(e2a)//~v8@sI~
		//EBC2ASC_SOSID  		  //del sosi(e2a/a2e)              //~v8@sI~
		//EBC2ASC_SOSIOS 		  //override boundary space(a2e), insert sosi if no space//~v8@uR~
		//EBC2ASC_BUFTOP 			//previous byte can not be rep by SO for a2e//~v8@sI~
		//EBC2ASC_LNCONT 			//line continued to next       //~v8@sI~
		//EBC2ASC_SOCONT 			//SO status continuing         //~v8@sI~
		| EBC2ASC_SOSISHIFT 	  //override boundary space(a2e), del from follwing if inserted keeping word boundary space//~v8@uI~
        ;                                                          //~v8@sI~
	chksjisoption(&cvopt);       //apply sjis option               //~v79fR~
    if (Popt & SUTC_DBCSCJK)   //DBCS other than cp930 cp939       //~v79aI~
    {                                                              //~v79aR~
	    cvopt|=EBC2ASC_EXT;		//use external converter           //~v79aR~
    }                                                              //~v79aR~
    else                                                           //~v79aI~
    if (!(Popt & SUTC_DBCSCONV)) //no DBCS                         //~v79aR~
    {                                                              //~v79aR~
        cvopt&=~EBC2ASC_DBCS;                                      //~v79aR~
    	if (Popt & (SUTC_SBCSCONV))   //SBCS converter             //~v79cI~
        {                                                          //~v79aR~
	    	cvopt|=EBC2ASC_EXT;                                    //~v79aR~
        }                                                          //~v79aR~
        else                                                       //~v79aR~
        if (Popt & SUTC_SBCSA2A)  //complementary mapping (A2F/F2A)//~v79aR~
        {                                                          //~v79aR~
            swfixed=0;      //use textmode transfer                //~v79aR~
            cvopt|=EBC2ASC_EXT|EBC2ASC_SBCSMAPA2A;      //use external converter//~v79aR~
        }                                                          //~v79aR~
    }                                                              //~v79aR~
    if (cvopt & EBC2ASC_DBCS && lrecl)                             //~v79hI~
    	cvopt |= EBC2ASC_FIXEDLRECL;                               //~v79hI~
//*file1                                                           //~v8@sI~
//  fhi=fopen(pinpfnm,"r");	//exit when open faile                 //~v79bR~
    fhi=fopen(pinpfnm,"rb");	//exit when open faile             //~v79bI~
UTRACEP("OPEN inp=%s,fh=%x\n",pinpfnm,fhi);                        //~v8@zI~
    if (!fhi)                                                      //~v8@sI~
    {                                                              //~v8@sI~
        uerrmsgmt(1,"%s open failed",0,                            //~v8@sR~
           		 pinpfnm);                                         //~v8@sI~
        return 4;                                                  //~v8@sI~
    }                                                              //~v8@sI~
	fho=fopen(poutfnm,"wb");                                       //~v8@sI~
UTRACEP("OPEN out=%s,fh=%x\n",poutfnm,fho);                        //~v8@zI~
    if (!fho)                                                      //~v8@sI~
    {                                                              //~v8@sI~
        uerrmsgmt(1,"%s open failed",0,                            //~v8@sR~
           		 poutfnm);                                         //~v8@sI~
        fclose(fhi);                                               //~v8@zI~
        return 4;                                                  //~v8@sI~
    }                                                              //~v8@sI~
    opt=UFGETS_PC|UFGETS_UNIX;                                     //~v79bI~
    ufgetsinit(opt,0/*buffsz:default*/,0/*binrate*/,0/*lrecl of bin file*/);//~v79bI~
    for (;;)                                                       //~v8@sI~
    {                                                              //~v8@sI~
//      if (!fgets(pbuffi,EBCBUFFSZ,fhi))	//eof                  //~v79bR~
		if (ufgets(pbuffi,EBCBUFFSZ,fhi,&readlen,0))               //~v79bR~
        	break;                                                 //~v8@sI~
//      USTR_DROPEOL_GETLEN(pbuffi,readlen);                       //~v79bR~
        errch='?';                                                 //~v8@sM~
#ifdef LNX                                                         //~v8@zM~
//    if (G3270opt & G3270OPT_EUC) //locale is euc                 //~v79xR~
      if (!(cvopt & EBC2ASC_EXT) && (G3270opt & G3270OPT_EUC)) //locale is euc//~v79xI~
      {                                                            //~v8@zI~
UTRACED("euc",pbuffi,readlen);                                     //~v8@zI~
    	ueuc2shift(pbuffi,0/*pdbcs*/,readlen,pbuffw,0/*dbcs*/,&wklen,eucopt);//~v8@zR~
UTRACED("sjis",pbuffw,wklen);                                      //~v8@zI~
        sjislen=wklen;                                             //~v8@CI~
        psjis=pbuffw;                                              //~v8@CI~
        outlen=lrecl; //effective when EBC2ASC_FIXEDLRECL, insert I at EOL by lrecl//~v79hI~
    	ucvasc2ebc(cvopt,pbuffw,0/*pdbcs*/,pbuffo,wklen,errch,&outlen); 	//0:dbcs,0:rep char//~v8@zR~
UTRACED("ebc ",pbuffo,outlen);                                     //~v8@zI~
      }                                                            //~v8@zI~
      else                                                         //~v8@zI~
#endif                                                             //~v8@zM~
	  {                                                            //~v8@zI~
UTRACED("sjis",pbuffi,readlen);                                    //~v8@zI~
        sjislen=readlen;                                           //~v8@CI~
        psjis=pbuffi;                                              //~v8@CI~
        outlen=lrecl; //effective when EBC2ASC_FIXEDLRECL, insert I at EOL by lrecl//~v79hI~
    	ucvasc2ebc(cvopt,pbuffi,0/*pdbcs*/,pbuffo,readlen,errch,&outlen); 	//0:dbcs,0:rep char//~v8@zR~
UTRACED("ebc ",pbuffo,outlen);                                     //~v8@zI~
      }                                                            //~v8@zI~
//#ifdef VBSUPP                                                    //~v79aR~
        numoksw=0;                                                 //~v79hR~
        if (swfixed)                                               //~v8@sI~
        {                                                          //~v8@sI~
//#endif                                                           //~v79aR~
			if (outlen!=lrecl && swnumstd)   //short/long record with of NUMSTD member//~v8@CR~
            {                                                      //~v8@CI~
            	pc=psjis+sjislen-SPFNUMFLDLEN;                     //~v8@CI~
            	if (unumlen(pc,0/*opt*/,SPFNUMFLDLEN)==SPFNUMFLDLEN)//8 byte valid numeric//~v8@CR~
                {                                                  //~v8@CI~
                	numoksw=1;                                     //~v79hR~
	            	pc=pc0=pbuffo+outlen-SPFNUMFLDLEN;             //~v8@CI~
            		if (outlen>lrecl)	//long record              //~v8@CI~
                	{                                              //~v8@CI~
                    	shiftlen=min(outlen-lrecl,SPFNUMFLDLEN);   //~v8@CI~
                    	for (spacelen=0,pc--;*pc==CHAR_EBC_SPACE && spacelen<shiftlen;pc--)//~v8@CR~
                        	spacelen++;                            //~v8@CR~
                        if (spacelen)                              //~v8@CI~
                        {                                          //~v8@CI~
                        	memcpy(pc0-spacelen,pc0,SPFNUMFLDLEN); //~v8@CR~
                        	outlen-=spacelen;                      //~v8@CR~
                        }                                          //~v8@CI~
                	}                                              //~v8@CI~
                    else                        //short record     //~v8@CI~
                    {                                              //~v8@CI~
                    	spacelen=lrecl-outlen;                     //~v8@CI~
                    	memmove(pc0+spacelen,pc0,SPFNUMFLDLEN);    //~v8@CR~
//                      memset(pc0,CHAR_EBC_SPACE,spacelen);       //~v8@CI~//~vb30R~
                        memset(pc0,CHAR_EBC_SPACE,(size_t)spacelen);//~vb30I~
                        outlen+=spacelen;                          //~v8@CI~
                    }                                              //~v8@CI~
                }                                                  //~v8@CI~
            }                                                      //~v8@CI~
//  		if (readlen<=lrecl && outlen>lrecl)	                   //~v79hR~
            if (numoksw && outlen>lrecl && outlen-SPFNUMFLDLEN<=lrecl)//~v79hR~
            {                                                      //~v8@uI~
                UTRACED("local2ebc EBC expanded",pbuffo,outlen);   //~v8@uR~
                outlen=lrecl;                                      //~v8@uI~
            }                                                      //~v8@uI~
        	for (reslen=outlen,pc=pbuffo;reslen>0;reslen-=lrecl,pc+=lrecl)//~v8@sR~
            {                                                      //~v8@sI~
            	if (reslen<lrecl)                                  //~v8@sI~
                	memset(pc+reslen,EBC_SPACE,(UINT)(lrecl-reslen));//~v8@sI~
//      		writelen=fwrite(pc,1,(UINT)lrecl,fho);             //~v8@uR~//~vb30R~
        		writelen=(int)fwrite(pc,1,(size_t)lrecl,fho);      //~vb30I~
UTRACED("ebc write",pc,lrecl);                                     //~v8@CI~
                if (writelen<lrecl)                                //~v8@sI~
                	break;                                         //~v8@sI~
            }                                                      //~v8@sI~
//#ifdef VBSUPP //not tested                                       //~v79aR~
        }                                                          //~v8@sI~
        else                                                       //~v8@sI~
        {                                                          //~v8@sI~
#ifdef VBSUPP //not tested                                         //~v79aI~
        	lreclv=lrecl-VLRHSZ;                                   //~v8@sR~
        	for (reslen=outlen,pc=pbuffo;reslen>0;reslen-=lreclv,pc+=lreclv)//~v8@sR~
            {                                                      //~v8@sI~
				lreclv=min(reslen,lrecl-VLRHSZ);                   //~v8@sR~
                SETVLRH(vlrh,lreclv+VLRHSZ);                       //~v8@sR~
        		writelen=fwrite(vlrh,1,VLRHSZ,fho);                //~v8@uR~
                if (writelen<VLRHSZ)                               //~v8@sI~
                	break;                                         //~v8@sI~
        		writelen=fwrite(pc,1,(UINT)lreclv,fho);            //~v8@uR~
                if (writelen<lreclv)                               //~v8@sI~
                	break;                                         //~v8@sI~
            }                                                      //~v8@sI~
#endif                                                             //~v79aI~
			*(pbuffo+outlen++)='\n';                               //~v79aI~
//      	writelen=fwrite(pbuffo,1,(UINT)outlen,fho);            //~v79aI~//~vb30R~
        	writelen=(int)fwrite(pbuffo,1,(size_t)outlen,fho);     //~vb30I~
            reslen=outlen-writelen;                                //~v79aI~
        }                                                          //~v8@sI~
//#endif                                                           //~v79aR~
        if (reslen>0)                                              //~v8@sI~
        {                                                          //~v8@sI~
            uerrmsgmt(1,"%s write failed",0,                       //~v8@sR~
                     poutfnm);                                     //~v8@sI~
            rc=4;                                                  //~v8@zI~
            break;                                                 //~v8@zR~
        }                                                          //~v8@sI~
  	}                                                              //~v8@sI~
	rc2=fclose(fhi);                                               //~v8@zR~//~vaa7R~
//UTRACEP("CLOSE inp rc=%d,fh=%x\n",rc2,fhi);                      //+vbzGR~
UTRACEP("CLOSE inp rc=%d\n",rc2);                                  //+vbzGI~
    rc2=rc2;    //for compiler warning                             //~vaa7I~
	rc2=fclose(fho);                                               //~v8@zR~//~vaa7R~
//UTRACEP("CLOSE out rc=%d,fh=%x\n",rc2,fho);                      //+vbzGR~
UTRACEP("CLOSE out rc=%d\n",rc2);                                  //+vbzGI~
	return rc;                                                     //~v8@zR~
}//convlocal2ebc                                                   //~v8@sR~
//*************************************                            //~v79fI~
//*chk sjis option                                                 //~v79fI~
//*************************************                            //~v79fI~
int chksjisoption(int *Ppopt)                                      //~v79fI~
{                                                                  //~v79fI~
//*******************************                                  //~v79fI~
    ucvext_getcvoption(0,G3270pmapcfg,Ppopt);                      //~v79gI~
    return 0;                                                      //~v79gR~
}//chksjisoption                                                   //~v79fI~
