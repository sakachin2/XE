//*CID://+v6J0R~:                             update#=  600;       //~v6J0R~
//*************************************************************
//*uftp2.c                                                         //~v5a8R~
//* get remote file/dir info by ftp                                //~v56nI~
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6D1:160418 LNX64 compiler warning                               //~v6D1I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6BM:160313 (W32) compiler warning                               //~v6BMI~
//v6uX:140612 chan errmsg "ftp-stat" to uerrmsgcat not to override previous errmsg//~v6uXI~
//v6qe:131206 (BUG)ftp "ls" dose not show slinkname,but "l" on attr. display dummy slinkname.//~v6qeI~
//v6qd:131206 (BUG)slink target not found err(uftpgetdl1 set x00 to stdout)//~v6qdI~
//v6qb:131205 chk max filectr to avoid malloc size over uerrexit when 32bit mode(see v6q9)//~v6qbI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1I~
//v690:100701 m64(LP64:: int:32, long,void*:64) support (__LP64_):chk pointer size at 1st.//~v690I~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v61k:080117 Bug report by M.J                                    //~v61kI~
//v61e:071126*(FTP)use ls -la if avail to get list of "." file     //~v61eI~
//v61b:071123*(FTP)log errmsg to ftplog alos                       //~v61bI~
//v61a:071123*(FTP:BUG)226 is also failed case("226 Transfer done (but failed to open irectory)." is returned)//~v61aI~
//v619:071123*(FTP:BUG)delete may returns not 250 but 226          //~v619I~
//v5kt:070702 from rh9 to ProFtpd,ls cmd fail by "no route to host". it requires active mod(once issue passive cmd to set off)//~v5ktI~
//            support ICMD parm on xehost                          //~v5ktI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5ia:060606 (BUG)month calc missing(compiler warning:no effect statement);;updated also utf version//~v5iaI~
//v5dz:040823 ftp:specify large windowsize(windows default is 4096)//~v5dzI~
//v5dg:040609 (FTP:BUG)if file time is before 1980 2007 is displayed.//~v5dgI~
//                     (5bit -1=127,127+1980=2107-->07/mm/dd is displayed)//~v5dgI~
//v5df:040609 (AIX:BUG)AIX responce is by JST for ls,GMT for modtime//~v5dfI~
//                     LNX responce is both by GMT;                //~v5dfI~
//                     ajust ls time by xehosts,mdtime result by ftime tz//~v5dfI~
//v5de:040609 (AIX:BUG)filetime set not done for download file     //~v5deI~
//            uftp.c uftp2.c file3f.c ufile.h                      //~v5deI~
//v5cs:040509 (WIN:BUG)_tempnam  returns prefix itself if prefix length >=8//~v5csI~
//                     and loop when the only one name exist       //~v5csI~
//v5cn:040508 (FTP:BUG)abend when mkdir faile(551:exist)           //~v5cnI~
//v5c5:040330 (UNX:BUG)ftp slink name get err,bug by v5bd;consider space containig name//~v5c5R~
//v5bx:040225 cmd server function for 1 dos prompt screen(ftp use this server)//~v5bxI~
//v5bv:040222 (FTP)use resident ftp client pgm because mdos prompt appear each time under WXE//~v5bvI~
//v5bt:040221 (WXE)dup handle fail  by invalid fd number on W98    //~v5btI~
//                 cmd prompt apear for also spaw;back to system() use.//~v5btI~
//v5br:040219 (FTP)use spawn for alternative of system because cmd prompt screen apear.//~v5bdI~
//v5bd:040202 (FTP:BUG)missing ufree ftpcmd() err                  //~v5bdI~
//v5b7:040129 (FTP:BUG) 5xxx byte .. misread to matching with 5*   //~v5b7I~
//v5b1:040115 (FTP)tempdir del option for test                     //~v5b1I~
//v5ax:040113 (BUG)ftp time fmt has hhmm when up to 6 month before //~v5axI~
//v5ar:040111 (FTP)wild card err responce chk specification like as 5**//~v5arI~
//v5an:040110 (FTP)deleted msg issued for ftp temp file delete at xdd//~v5anI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v5ae:040105 solaris time stamp fmt is mmŒŽdd“ú yyyy”N            //~v5aeI~
//v5a8:040104 ajust dirlist JST if timeis not 00:00                //~v5a8I~
//v59d:030816 ftp support                                          //~v59dI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>                                                 //~v59dI~
#include <sys/timeb.h>                                             //~v59dI~
                                                                   //~v59dI~
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
#include <ufile2.h>                                                //~v59dI~
#include <ufile4.h>                                                //~v59dI~
#include <ufemsg.h>                                                //~v59dI~
#include <uerr.h>
#include <ustring.h>
#include <ualloc.h>                                                //~v50GI~
#include <uproc.h>                                                 //~v50GI~
#include <uedit.h>                                                 //~v59dI~
#include <ucalc2.h>                                                //~v59dM~
#undef NOTRACE                                                     //~v5bvI~
#include <utrace.h>                                                //~v5a8I~
#include <udbcschk.h>                                              //~v5afI~
                                                                   //~v59dI~
#define GBLDEF_FTP	//gbl define                                   //~v59dI~
#include <uftp.h>                                                  //~v59dI~
#include <ufile1f.h>                                               //~v61kI~
#include <uftp3.h>                                                 //~v61kI~
#include <uedit2.h>                                                //~v6D2I~
//*******************************************************
#ifdef UNX                                                         //~v59dI~
//  #define FTPCMD "ftp -nvi < %s"                                 //~v5bdR~
//  #define FTPCMD "ftp -nvi"                                      //~v5btR~
    #define FTPCMD "ftp -nvi < %s"                                 //~v5btI~
    	//-n:suppress auto login                                   //~v59dI~
    	//-i:no prompt for multi file transfer                     //~v59dI~
    	//-v:suppress remote server responce                       //~v59dI~
    #define FTPECHO 	""                                         //~v59dI~
    #define FTPECHOLEN 	0                                          //~v59dI~
#else                                                              //~v59dI~
//  #define FTPCMD "ftp -ni -s:%s"                                 //~v5bdR~
//  #define FTPCMD "ftp.exe -ni -s:%s"                             //~v5dzR~
    #define FTPCMD "ftp.exe -ni -s:%s -w:%d"                       //~v5dzI~
    	//-n:suppress auto login                                   //~v59dI~
    	//-i:no prompt for multi file transfer                     //~v59dI~
    	//-v:suppress remote server responce                       //~v59dI~
    	//-s:ftp subcmd file                                       //~v59dI~
    #define FTPECHO 	"ftp> "                                    //~v59dI~
    #define FTPECHOLEN 	4	                                       //~v59dI~
#endif                                                             //~v59dI~
                                                                   //~v59dI~
#define FTPSCMD_USER    "user"                                     //~v59dI~
#define FTPSCMDLEN_USER 4                                          //~v59dR~
#define FTPERR_OPEN     "failed to open directory"                 //~v61aI~
//*******************************************************          //~v59dI~
static int Sftpopt=0;                                              //~v59dI~
static FILE *Sfhlog=0;                                             //~v59dI~
//#ifdef WXE                                                       //~v5bxR~
//    int Sfdchildoutr,Sfdchildinw;                                //~v5bxR~
//#endif                                                           //~v5bxR~
//*******************************************************          //~v59dI~
                                                                   //~v59dI~
unsigned int uftpgetmode(char *Pstring);                           //~v59dI~
//int uftpgetmonth(char *Pmonth);                                    //~v59dI~//~v6d1R~
int uftpcmdresphdrchk(char ***Ppstdo,int *Ppstdoctr);              //~v59dR~
int uftpcmdrespchk(char **Ppstdo,int Pstdoctr);                    //~v59dI~
int uftpgetdlftime(char *Pmonth,char *Pday,char *Phhmmoryear,FDATE *Pfdate,FTIME *Pftime);//~v59dR~
//#ifdef WXE                                                       //~v5bxR~
//    int uftpclientsetup(char *Pclientpgm);                       //~v5bxR~
//    int uftpclientpush(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr);//~v5bxR~
//#endif                                                           //~v5bxR~
int uftpnodeinit(PUFTPHOST Ppuftph);                               //~v61eR~
//*******************************************************          //~v59dI~
//*init fto                                                        //~v59dI~
//*parm 1:option                                                   //~v59dI~
//*parm 2:log filename                                             //~v59dI~
//*ret  4:logfile open err                                         //~v59dI~
//*******************************************************          //~v59dI~
//int uftpinit(int Popt,char *Plogfnm,char *Phostsfnm)             //~v5bvR~
int uftpinit(int Popt,char *Plogfnm,char *Phostsfnm,char *Pclientpgm)//~v5bvI~
{                                                                  //~v59dI~
	char *logfnm,*wmode;                                           //~v59dR~
//***********************                                          //~v59dI~
    Sftpopt=Popt;                                                  //~v59dI~
    if (Sftpopt & UFTPO_NOP)                                       //~v59dR~
        return 0;                                                  //~v59dI~
    if (Sftpopt & UFTPO_LOG)                                       //~v59dI~
    {                                                              //~v59dI~
        if (!Plogfnm || !*Plogfnm)                                 //~v59dR~
        	logfnm="uftp.log";                                     //~v59dR~
        else                                                       //~v59dI~
        	logfnm=Plogfnm;                                        //~v59dI~
	    if (Sftpopt & UFTPO_APPEND)                                //~v59dR~
        	wmode="a";                                             //~v59dI~
        else                                                       //~v59dI~
        	wmode="w";                                             //~v59dI~
        Sfhlog=fopen(logfnm,wmode);  //append mode                 //~v59dR~
        if (!Sfhlog)                                               //~v59dI~
        {                                                          //~v59dI~
        	ufileapierr("uftp logfile open",logfnm,errno);         //~v59dI~
            return 4;                                              //~v59dI~
        }                                                          //~v59dI~
    }                                                              //~v59dI~
    if (Phostsfnm)                                                 //~v59dI~
    	uftphoststbinit(Phostsfnm);                                //~v59dI~
//#ifdef WXE                                                       //~v5bxR~
//    if (uftpclientsetup(Pclientpgm))  //setup ftp client(console appl stating ftp.exe)//~v5bxR~
//        return 4;                                                //~v5bxR~
//#endif                                                           //~v5bxR~
//  Gftpopt=GFTPO_AVAIL;                                           //~v61kR~
    Gftpopt|=GFTPO_AVAIL;                                          //~v61kI~
    return 0;                                                      //~v59dI~
}//uftpinit                                                         //~v59dI~//~v6qeR~
//#ifdef WXE                                                       //~v5bxR~
////*******************************************************        //~v5bxR~
////*init fto                                                      //~v5bxR~
////*parm 1:option                                                 //~v5bxR~
////*parm 2:log filename                                           //~v5bxR~
////*ret  4:logfile open err                                       //~v5bxR~
////*******************************************************        //~v5bxR~
//int uftpclientsetup(char *Pclientpgm)                            //~v5bxR~
//{                                                                //~v5bxR~
//    int pipes[4];                                                //~v5bxR~
//    int pid;                                                     //~v5bxR~
//    char sfdr[16],sfdw[16];                                      //~v5bxR~
////***********************                                        //~v5bxR~
//    if (_pipe(pipes,4096,_O_TEXT)<0)   //child stdin             //~v5bxR~
//        return ufileapierr("_popen",Pclientpgm,errno);           //~v5bxR~
//    if (_pipe(pipes+2,4096,_O_TEXT)<0)  //child stdout           //~v5bxR~
//        return ufileapierr("_popen",Pclientpgm,errno);           //~v5bxR~
//    Sfdchildoutr=dup(pipes[2]); //c->p(R)==>stdout;              //~v5bxR~
//    close(pipes[2]);        //avoid inherit                      //~v5bxR~
//    Sfdchildinw=dup(pipes[1]);//p(W)->c==>stdin                  //~v5bxR~
//    close(pipes[1]);        //avoid inherit                      //~v5bxR~
//    sprintf(sfdr,"%d",pipes[0]);                                 //~v5bxR~
//    sprintf(sfdw,"%d",pipes[3]);                                 //~v5bxR~
//UTRACEP("child spawn\n");                                        //~v5bxR~
//    pid=uspawnlp(P_NOWAIT|UPROC_NOOKMSG,Pclientpgm,Pclientpgm,sfdr,sfdw,0);//~v5bxR~
//    if (pid==-1)                                                 //~v5bxR~
////      return ufileapierr("spawan NO_WAIT",Pclientpgm,errno);   //~v5bxR~
//        return 4;                                                //~v5bxR~
//UTRACEP("child spawned\n");                                      //~v5bxR~
//    return 0;                                                    //~v5bxR~
//}//uftpclientsetup                                               //~v5bxR~
////*******************************************************        //~v5bxR~
////*throw request to resident client                              //~v5bxR~
////*parm 1:option                                                 //~v5bxR~
////*parm 2:log filename                                           //~v5bxR~
////*ret  4:logfile open err                                       //~v5bxR~
////*******************************************************        //~v5bxR~
//int uftpclientpush(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr)//~v5bxR~
//{                                                                //~v5bxR~
//    char tempfnm[_MAX_PATH];//,*fnm,*pc,**ppc;                   //~v5bxR~
//    char cmd[32+_MAX_PATH];                                      //~v5bxR~
//    char buff[8];                                                //~v5bxR~
////***********************                                        //~v5bxR~
//    utempnam("","xetmpstdo_",tempfnm);                           //~v5bxR~
//    sprintf(cmd,"%s >%s",Pcmd,tempfnm);                          //~v5bxR~
//    write(Sfdchildinw,cmd,strlen(cmd));                          //~v5bxR~
//UTRACEP("push cmd=%s\n",cmd);                                    //~v5bxR~
//    read(Sfdchildoutr,buff,sizeof(buff));   //wait reply         //~v5bxR~
//UTRACEP("resad resp\n");                                         //~v5bxR~
//    return uproc_redirectoutchk(Popt,Pcmd,Pstdo,Pstde,Pstdoctr,Pstdectr,tempfnm,0);//~v5bxR~
//}//uftpclientpush                                                //~v5bxR~
//#endif                                                           //~v5bxR~
//*******************************************************          //~v59dI~
//*init fto                                                        //~v59dI~
//*parm 1:option                                                   //~v59dI~
//*parm 2:log filename                                             //~v59dI~
//*ret  4:logfile open err                                         //~v59dI~
//*******************************************************          //~v59dI~
int uftpterm(void)                                                 //~v59dI~
{                                                                  //~v59dI~
//***********************                                          //~v59dI~
    uftpnodeclear();                                               //~v5bvI~
    if (Sfhlog)                                                    //~v59dI~
    {                                                              //~v59dI~
        fclose(Sfhlog);                                            //~v59dR~
        Sfhlog=0;                                                  //~v59dI~
    }                                                              //~v59dI~
//#ifdef WXE                                                       //~v5bxR~
//    if (Sfdchildinw)                                             //~v5bxR~
//        write(Sfdchildinw,"quit",4);                             //~v5bxR~
//#endif                                                           //~v5bxR~
//UTRACEP("push quit\n");                                          //~v5bxR~
    return 0;                                                      //~v59dI~
}//uftpterm                                                        //~v59dI~
//*******************************************************          //~v59dI~
//*init fto                                                        //~v59dI~
//*parm 1:option                                                   //~v59dI~
//*parm 2:log filename                                             //~v59dI~
//*ret  4:logfile open err,1:paswd cleared                         //~v59dR~
//*******************************************************          //~v59dI~
int uftplog(int Popt,char *Pline)                                  //~v59dI~
{                                                                  //~v59dI~
//  int len,rc=0,pswdlen;                                          //~v59dR~//~v6h7R~
    int len,rc=0,pswdlen=0;                                        //~v6h7I~
#define PSWDSZ 64                                                  //~v59dI~
	char *pioid,curtime[16],*pc,*pc2,*pc3,*pc4,pswdsv[PSWDSZ],*ppswd=0;//~v59dR~
//***********************                                          //~v59dI~
    if (!Sfhlog)                                                   //~v59dI~
    	return 0;                                                  //~v59dI~
    if (!(Sftpopt & UFTPO_LOG))                                    //~v59dI~
    	return 0;                                                  //~v59dI~
    if (Popt & FTPLOG_REQ)                                         //~v59dR~
    	pioid="==>";                                               //~v59dI~
    else                                                           //~v59dI~
    if (Popt & FTPLOG_RESP)                                        //~v59dR~
    	pioid="<--";                                               //~v59dI~
    else                                                           //~v59dI~
    if (Popt & FTPLOG_INFO)                                        //~v61kI~
    	pioid="!!!";                                               //~v61kI~
    else                                                           //~v61kI~
    	pioid="   ";                                               //~v59dI~
    utimeedit("HH:MM:SS:MIL",curtime);                             //~v59dR~
    *(curtime+12)=0;                                               //~v59dI~
  if (Popt & FTPLOG_ERRM)                                          //~v61bI~
  {                                                                //~v61bI~
	pc=ugeterrmsg2();                                              //~v61bI~
    if (!pc)                                                       //~v61bI~
    	return 4;                                                  //~v61bI~
	fprintf(Sfhlog,"%12s ?? %s\n",curtime,pc);                     //~v61bR~
  }                                                                //~v61bI~
  else                                                             //~v61bI~
  {                                                                //~v61bI~
    for (pc=Pline;;)                                               //~v59dI~
    {                                                              //~v59dI~
        pc2=strchr(pc,'\n');                                       //~v59dR~
        if (pc2)                                                   //~v59dI~
//          len=(ULONG)pc2-(ULONG)pc+1;                            //~v59dR~//~v6hhR~
//          len=(ULPTR)pc2-(ULPTR)pc+1;                            //~v6hhI~//~v6D0R~
            len=PTRDIFF(pc2,pc)+1;                                 //~v6D0I~
        else                                                       //~v59dI~
//          len=strlen(pc);                                        //~v59dR~//~v6D0R~
            len=(int)strlen(pc);                                   //~v6D0I~
                                                                   //~v59dI~
        if (Popt & FTPLOG_PSWD)	//pswd to be deleted               //~v59dR~
        {                                                          //~v59dI~
            pc3=strstr(pc,FTPSCMD_USER);                           //~v59dI~
            if (pc3)                                               //~v59dI~
            {                                                      //~v59dI~
            	rc=1;                                              //~v59dI~
            	pc3+=FTPSCMDLEN_USER;                              //~v59dI~
                pc3+=strspn(pc3," ");                              //~v59dR~
                pc3=strchr(pc3,' '); //over user name              //~v59dR~
                if (pc3)                                           //~v59dI~
                {                                                  //~v59dI~
                	pc3+=strspn(pc3," ");	//pswd fld             //~v59dR~
                    ppswd=pc3;                                     //~v59dI~
                    for (pc4=pc3,pswdlen=0;*pc4;pc4++)             //~v59dR~
                    {                                              //~v59dI~
                		if (*pc4=='\n'||*pc4==' ')                 //~v59dR~
                        	break;                                 //~v59dI~
                        if (pswdlen<PSWDSZ)                        //~v59dI~
                        {                                          //~v59dI~
	                        pswdsv[pswdlen++]=*pc4;                //~v59dI~
                        	*pc4='*';                              //~v59dR~
                        }                                          //~v59dI~
                    }                                              //~v59dI~
                }                                                  //~v59dI~
            }                                                      //~v59dI~
        }                                                          //~v59dI~
        if (pc==Pline                                              //~v59dR~
//  	&&  Popt & (FTPLOG_REQ|FTPLOG_RESP))                       //~v61kR~
    	&&  Popt & (FTPLOG_REQ|FTPLOG_RESP|FTPLOG_INFO))           //~v61kI~
		    fprintf(Sfhlog,"%12s %3s",curtime,pioid);              //~v59dI~
        else                                                       //~v59dI~
		    fwrite("                ",1,16,Sfhlog);                //~v59dR~
                                                                   //~v59dI~
        fwrite(pc,1,(UINT)len,Sfhlog);                             //~v59dI~
        if (ppswd)		//pswd replaced                            //~v59dI~
        {                                                          //~v59dI~
        	memcpy(ppswd,pswdsv,(UINT)pswdlen);                    //~v59dI~
            memset(pswdsv,0,PSWDSZ);                               //~v59dI~
        }                                                          //~v59dI~
        if (!pc2)                                                  //~v59dI~
        {                                                          //~v59dI~
            if (Popt & FTPLOG_ADDLF)                               //~v59dR~
			    fwrite("\n",1,1,Sfhlog);                           //~v59dI~
        	break;                                                 //~v59dI~
        }                                                          //~v59dI~
        pc=pc2+1;                                                  //~v59dI~
        if (!*pc)                                                  //~v59dI~
        	break;                                                 //~v59dI~
    }                                                              //~v59dI~
  }//not errmsg                                                    //~v61bI~
    return rc;                                                     //~v59dR~
}//uftplog                                                         //~v59dI~
//**********************************************************************//~v61eI~
// find first for msdos discket(create udirlist)                   //~v61eI~
// parm filename should be without nodename                        //~v61eI~
// return :r.c                                                     //~v61eI~
//**********************************************************************//~v61eI~
int uftpnodeinit(PUFTPHOST Ppuftph)                                //~v61eR~
{                                                                  //~v61eI~
	PUDIRLIST pudl0;                                               //~v61eI~
//  unsigned rc,rc2;                                               //~v61eI~//~v6D0R~
    int rc,rc2;                                                    //~v6D0I~
    UCHAR ftpcmd[32];                                              //~v61eI~
    char **stdo,**stdo0;                                           //~v61eI~
    int stdoctr,fno=-1;                                            //~v61eI~
//*********************************                                //~v61eI~
    if (!(Ppuftph->UFTPHflag & UFTPHFULSCMD))	//user not specified ls cmd//~v61eR~
    {                                                              //~v61eI~
    	sprintf(ftpcmd,                                            //~v61eI~
            "%s\n",                                                //~v61eR~
            UFTPHLSCMD_OLD);                                       //~v61eI~
        rc=uftpcmd(Ppuftph,0,ftpcmd,&stdo0,&stdoctr,0,0);   //get stdout/stderr//~v61eI~
        if (!rc)                                                   //~v61eI~
        {                                                          //~v61eI~
            stdo=stdo0;                                            //~v61eI~
            for (;;)                                               //~v61eI~
            {                                                      //~v61eI~
                rc=4;                                              //~v61eI~
	  		  if (UFTPHISPSFTP(Ppuftph))                           //~v61kI~
              {                                                    //~v61kI~
    			if (rc2=uftpcmdsrchrespid(&stdo,&stdoctr,FTP_PSFTP_OK_LIST),rc2) //Listing directory ____//~v61kI~
                    break;                                         //~v61kI~
              }                                                    //~v61kI~
              else                                                 //~v61kI~
              {                                                    //~v61kI~
                if (rc2=uftpcmdsrchrespid(&stdo,&stdoctr,"150 "),rc2) //150:open data connection/~v59dR~//~v61eI~
                    break;                                         //~v61eI~
              }                                                    //~v61kI~
                rc=0;                                              //~v61eR~
                break;                                             //~v61eI~
            }//rc chk                                              //~v61eI~
            if (!rc)                                               //~v61eI~
            {                                                      //~v61eI~
                rc=uftpgetdl(Ppuftph,stdo,stdoctr,&pudl0,&fno);//skip top "?"//~v61eI~
                if (rc)                                            //~v61kI~
					ugeterrmsg();	//clear errmsg                 //~v61kI~
              if (pudl0)                                           //~v61kI~
//          	ufree(pudl0);                                      //~v61eM~//~v6qaR~
            	UDIRLIST_FREE(pudl0);                              //~v6qaI~
            }                                                      //~v61eI~
            ufree(stdo0);                                          //~v61eI~
        }                                                          //~v61eI~
        if (fno>=0)                                                //~v61eI~
        {                                                          //~v61eI~
    		Ppuftph->UFTPHflag |= UFTPHFLSCMDCG;	//default changed//~v61eI~
            strcpy(Ppuftph->UFTPHlscmd,UFTPHLSCMD_OLD);            //~v61eI~
    		uerrmsg("\"%s\" will be used as list command,if not preferable specify \"LS=\" option in \"xehosts\" file",0,//~v61eR~
            		Ppuftph->UFTPHlscmd);                          //~v61eI~
		    uftplog(FTPLOG_ERRM,0); //logging errmsg               //~v61eI~
    		ugeterrmsg();   //clear errmsg after loghging          //~v61eI~
        }                                                          //~v61eI~
    }                                                              //~v61eI~
    return 0;                                                      //~v61eI~
}//uftpnodeinit                                                    //~v61eR~
//**********************************************************************//~v56nM~
// interface to usystem_redirect                                   //~v56nM~
// parm1  :file name                                               //~v56nM~
// parm4  :output stdout array(0 if rc!=0)                         //~v5bdI~
// return :4:err,5(IOE),1:stderr freed                             //~v56nM~
// 220:open ok                                                     //~v59dI~
// 230:login ok                                                    //~v59dI~
// 530:login er                                                    //~v59dI~
// 221:good by(<--quit)                                            //~v59dI~
// 250:cd ok                                                       //~v59dI~
// 550:nor such file or dir(<--cd,ls file)                         //~v59dI~
// 257:current dir is .. (<--pwd)                                  //~v59dI~
// ls/get etc 200:port cmd ok                                      //~v59dI~
//            150:open data communication for ..                   //~v59dI~
//            226:transfer complete                                //~v59dI~
// 200:type set to N from A (<--binary,ascii)                      //~v59dI~
//**********************************************************************//~v56nM~
int uftpcmd(PUFTPHOST Ppuftph,int Popt,char *Pcmd,char ***Pstdo,int *Pstdoctr,FTPCMD_CALLBACK *Pfunc,void *Ppvoid)//~v5aeR~
{                                                                  //~v56nM~
static int Ssw1st=1;                                               //~v61kI~
	int rc,stdoctr,sysopt;                                         //~v59dR~
#ifdef UNX                                                         //~v5dzI~
#else                                                              //~v5dzI~
    int windowsz=FTP_WINDOWSZ;                                     //~v5dzI~
#endif                                                             //~v5dzI~
    char **pstdo,*pc,*bora;                                        //~v59dR~
    char tempfnm[_MAX_PATH];                                       //~v59dI~
    FILE *fh;                                                      //~v56nI~
//  char ftpcmd[64];                                               //~v61kR~
//  char ftpcmd[64+_MAX_PATH];                                     //~v61kI~//~v6DiR~
    char ftpcmd[64+FTP_MAXPATH];                                   //~v6DiI~
    char subcmdhdr[256],*subcmdend="close\nquit\n";                //~v59dR~
//  char **pstde=0;                                                //~v61kR~
//  int stdectr=0;                                                 //~v61kR~
//********************                                             //~v56nM~
  	if (UFTPH_ISSMB(Ppuftph))                                      //~v6d1M~
  	{                                                              //~v6d1M~
		return uftp3smbcmd(Popt,Ppuftph,Pcmd,Pstdo,Pstdoctr,Pfunc,Ppvoid);//~v6d1M~
  	}                                                              //~v6d1M~
	if (Pstdo)                                                     //~v59dM~
    	*Pstdo=0;                                                  //~v59dM~
	if (Pstdoctr)                                                  //~v59dM~
    	*Pstdoctr=0;                                               //~v59dM~
//edit hdr subcmd                                                  //~v59dI~
  if (UFTPHISPSFTP(Ppuftph))                                       //~v61kI~
  {                                                                //~v61kI~
	rc=uftp3editpsftpcmd(0,Ppuftph,Popt,Pcmd,ftpcmd,subcmdhdr,tempfnm);//~v61kR~
    if (rc>=4)                                                     //~v61kI~
    	return rc;                                                 //~v61kI~
  }                                                                //~v61kI~
  else                                                             //~v61kI~
  {                                                                //~v61kI~
    if (Popt & FTPCMD_BINARY)                                      //~v59dM~
	    bora="binary";                                             //~v59dM~
    else                                                           //~v59dM~
	    bora="ascii";                                              //~v59dM~
    sprintf(subcmdhdr,                                             //~v59dM~
    		"open %s\n"                    \
    		FTPSCMD_USER " %s %s\n"                 \
	    	"%s\n"        /*binary|ascii*;@@@ required for 530 diff LNX and AIX*///~v59dR~
            "%s\n"                                                 //~v5ktI~
    		"pwd\n", 	//last of  hdr cmd                         //~v59dR~
			Ppuftph->UFTPHipad,                                    //~v5aeR~
			Ppuftph->UFTPHuser,Ppuftph->UFTPHpswd,                 //~v5aeR~
			Ppuftph->UFTPHicmd,                                    //~v5ktR~
            bora);                                                 //~v59dM~
//setup stdin file                                                 //~v59dI~
    utempnam("","uftp_",tempfnm);	// TEMP= or /tmp               //~v59dM~
//#ifdef UNX                                                       //~v5btR~
//    strcpy(ftpcmd,FTPCMD);                                       //~v5btR~
//#else                                                            //~v5btR~
#ifdef UNX                                                         //~v5dzI~
    sprintf(ftpcmd,FTPCMD,tempfnm);                                //~v59dM~
#else                                                              //~v5dzI~
    sprintf(ftpcmd,FTPCMD,tempfnm,windowsz);                       //~v5dzR~
#endif                                                             //~v5dzI~
    if (Ssw1st)	//1st time                                         //~v61kR~
    {                                                              //~v61kI~
    	Ssw1st=0;                                                  //~v61kI~
	    uftplog(FTPLOG_INFO|FTPLOG_ADDLF,ftpcmd);                  //~v61kR~
    }                                                              //~v61kI~
//#endif                                                           //~v5btR~
  }//!psftp                                                        //~v61kI~
    fh=fopen(tempfnm,"w");                                         //~v56nI~
    if (!fh)                                                       //~v56nI~
    {                                                              //~v56nI~
        ufileapierr("ftp stdin temp file fopen",tempfnm,errno);    //~v56nI~
        return 8;                                                  //~v56nI~
    }                                                              //~v56nI~
//  fprintf(fh,subcmdhdr);                                         //~v59dI~//~v6DiR~
    fprintf(fh,"%s",subcmdhdr);                                    //~v6DiI~
    uftplog(FTPLOG_REQ|FTPLOG_PSWD,subcmdhdr);                     //~v59dR~
    if (Pcmd)                                                      //~v59dI~
    {                                                              //~v59dI~
//  	fprintf(fh,Pcmd);                                          //~v59dR~//~v6DiR~
    	fprintf(fh,"%s",Pcmd);                                     //~v6DiI~
    	uftplog(0,Pcmd);                                           //~v59dR~
    }                                                              //~v59dI~
    if (Pfunc)                                                     //~v59dM~
    	rc=Pfunc(fh,Ppvoid);                                       //~v59dR~
    else                                                           //~v59dI~
    	rc=0;                                                      //~v59dI~
//  fprintf(fh,subcmdend);                                         //~v59dR~//~v6DiR~
    fprintf(fh,"%s",subcmdend);                                    //~v6DiI~
    uftplog(0,subcmdend);                                          //~v59dM~
    fclose(fh);                                                    //~v59dR~
    if (rc)                                                        //~v59dR~
    	return rc;		//callback rc                              //~v59dI~
    sysopt=UPROC_NOOKMSG;                                          //~v59dR~
#ifdef UNX                                                         //~v59dI~
    sysopt|=UPROC_LANGC;                                           //~v59dI~
#endif                                                             //~v59dI~
#if defined(AIX) || defined(W32)                                   //~v5afM~
    if (Ppuftph->UFTPHflag & UFTPHFEUC)                            //~v5afR~
    	sysopt|=UPROC_CVE2S;	//stdout sjis<-euc conv            //~v5afI~
#endif                                                             //~v5afM~
#ifdef LNX                                                         //~v5afM~
    if (Ppuftph->UFTPHflag & UFTPHFSJIS)                           //~v5afR~
    	sysopt|=UPROC_CVS2E;	//stdout sjis->euc conv            //~v5afI~
#endif                                                             //~v5afM~
//  rc=usystem_redirect(sysopt,ftpcmd,&pstdo,0,&stdoctr,0);        //~v5bdR~
//#ifdef UNX                                                       //~v5btR~
//    rc=uspawn_redirect(sysopt,ftpcmd,tempfnm,&pstdo,0,&stdoctr,0);//~v5btR~
//#else                                                            //~v5btR~
//    rc=uspawn_redirect(sysopt,ftpcmd,0,&pstdo,0,&stdoctr,0);//s:parm,no stdin use//~v5btR~
//#endif                                                           //~v5btR~
//#ifdef WXE                                                       //~v5bxR~
//    rc=uftpclientpush(sysopt,ftpcmd,&pstdo,0,&stdoctr,0);        //~v5bxR~
//#else                                                            //~v5bxR~
  	if (UFTPHISPSFTP(Ppuftph))                                     //~v61kI~
    	sysopt|=UPROC_STDE2O;	//redirect stderr to stdout        //~v61kR~
    IFDEF_WINCON(sysopt|=UPROC_KEEPMODE);	//keep consolemode     //~v5maR~
    rc=usystem_redirect(sysopt,ftpcmd,&pstdo,0,&stdoctr,0);        //~v5btI~
//#endif                                                           //~v5bxR~
    if (rc>1)                                                      //~v56nI~
    	return rc;                                                 //~v56nI~
    uremovenomsg(tempfnm);        //del tempfile                   //~v5anR~
  if (UFTPHISPSFTP(Ppuftph))                                       //~v61kI~
    rc=uftp3cmdrespchk(0,Ppuftph,pstdo,stdoctr);    //drop prompt  //~v61kI~
  else                                                             //~v61kI~
    rc=uftpcmdrespchk(pstdo,stdoctr);    //drop prompt             //~v59dR~
  if (UFTPHISPSFTP(Ppuftph))                                       //~v61kI~
	rc=uftp3cmdresphdrchk(0,Ppuftph,&pstdo,&stdoctr);              //~v61kI~
  else                                                             //~v61kI~
    rc=uftpcmdresphdrchk(&pstdo,&stdoctr);                         //~v59dR~
    switch(rc)                                                     //~v59dI~
    {                                                              //~v59dI~
    case 0:                                                        //~v59dI~
    	break;                                                     //~v59dI~
    case FTPRC_SSHERR:                                             //~v61kI~
//  	uerrmsg("SSH connection failed:%s,try 1st connection by native psftp cmd",0,//~v61kI~//~v6uXR~
    	uerrmsg("SSH connection failed:%s,try 1st connection by native psftp cmd at out of xe.",0,//~v6uXI~
				Ppuftph->UFTPHipad);                               //~v61kI~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61kI~
    	break;                                                     //~v61kI~
    case FTPRC_OPENERR:                                            //~v59dI~
      	uerrmsg("connection failed:%s",0,                          //~v59dI~//~v6uXR~
				Ppuftph->UFTPHipad);                               //~v5aeR~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61bI~
    	break;                                                     //~v59dI~
    case FTPRC_LOGONERR:                                           //~v59dI~
    	uerrmsg("login failed:%s",0,                               //~v59dR~
    			Ppuftph->UFTPHuser);                               //~v5aeR~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61bI~
    	break;                                                     //~v59dI~
    default:                                                       //~v59dI~
    	if (stdoctr)                                               //~v59dI~
        	pc=*pstdo;                                             //~v59dI~
        else                                                       //~v59dI~
        	pc="";                                                 //~v59dI~
    	uerrmsg("ftp result parse err:%s",0,                       //~v59dI~
				pc);                                               //~v59dI~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61bI~
    }                                                              //~v59dI~
    if (Pstdo)  //return required                                  //~v56nR~
      if (rc)                                                      //~v5bdI~
      {                                                            //~v5bdI~
    	ufree(pstdo);                                              //~v5bdI~
        stdoctr=0;                                                 //~v5bdI~
        *Pstdo=0;                                                  //~v5bdI~
      }                                                            //~v5bdI~
      else                                                         //~v5bdI~
        *Pstdo=pstdo;                                              //~v56nR~
    else                                                           //~v56nR~
        ufree(pstdo);                                              //~v56nR~
    if (Pstdoctr)  //return required                               //~v59dI~
    	*Pstdoctr=stdoctr;                                         //~v59dI~
    return rc;                                                     //~v59dR~
}//uftpcmd                                                         //~v59dR~
//**********************************************************************//~v59dI~
// drop prmpt                                                      //~v59dI~
// return :1 eof                                                   //~v59dI~
//**********************************************************************//~v59dI~
int uftpcmdrespchk(char **Ppstdo,int Pstdoctr)                     //~v59dI~
{                                                                  //~v59dI~
	int  logopt,ii,pswdsw;                                         //~v59dR~
    char **pstdo,*linedata,*pc;                                    //~v59dR~
//********************                                             //~v59dI~
	logopt=FTPLOG_RESP|FTPLOG_ADDLF|FTPLOG_PSWD;                   //~v59dR~
	for (pstdo=Ppstdo,ii=0;ii<Pstdoctr;ii++,pstdo++)               //~v59dI~
    {                                                              //~v59dM~
    	linedata=*pstdo;                                           //~v59dI~
        pswdsw=uftplog(logopt,linedata);                           //~v59dR~
        if (pswdsw)                                                //~v59dI~
			logopt&=~FTPLOG_PSWD;	//no more chk pswd             //~v59dR~
	    logopt&=~FTPLOG_RESP;                                      //~v59dR~
        if (!memcmp(linedata,FTPECHO,FTPECHOLEN))                  //~v59dI~
        {                                                          //~v59dI~
        	pc=linedata+FTPECHOLEN;                                //~v59dI~
            pc+=strspn(pc," ");                                    //~v59dI~
	        if (!memcmp(pc,FTPECHO,FTPECHOLEN))	//twice prompt     //~v59dI~
            {                                                      //~v59dI~
	        	pc=pc+FTPECHOLEN;                                  //~v59dI~
    	        pc+=strspn(pc," ");                                //~v59dI~
            }                                                      //~v59dI~
            memcpy(linedata,pc,strlen(pc)+1);                      //~v59dI~
        }                                                          //~v59dI~
    }                                                              //~v59dM~
    return 0;                                                      //~v59dI~
}//uftpcmdrespchk                                                  //~v59dI~
//**********************************************************************//~v59dI~
// chk responce of fixed cmd, open etc.                            //~v59dR~
// return :1 eof                                                   //~v59dI~
//**********************************************************************//~v59dI~
int uftpcmdresphdrchk(char ***Pppstdo,int *Ppstdoctr)              //~v59dR~
{                                                                  //~v59dI~
	int  stdoctr,rc;                                               //~v59dR~
    char **pstdo,**pstdo0;                                         //~v59dR~
//********************                                             //~v59dI~
	pstdo0=pstdo=*Pppstdo;                                         //~v59dR~
	stdoctr=*Ppstdoctr;                                            //~v59dR~
    for (;;)                                                       //~v59dI~
    {                                                              //~v59dI~
        if (uftpcmdsrchrespid(&pstdo,&stdoctr,"220 "))//search 220:open ok//~v59dR~
        {                                                          //~v59dI~
			rc=FTPRC_OPENERR;                                      //~v59dI~
        	break;                                                 //~v59dI~
    	}                                                          //~v59dI~
        if (uftpcmdsrchrespid(&pstdo,&stdoctr,"230 200 "))//search 230:logn ok/200:type set to A//~v59dR~
                //(LNX)530:plese login (AIX)530:login fail         //~v59dI~
        {                                                          //~v59dR~
            rc=FTPRC_LOGONERR;                                     //~v59dR~
            break;                                                 //~v59dR~
        }                                                          //~v59dI~
        if (uftpcmdsrchrespid(&pstdo,&stdoctr,"257 "))//search 257:pwd resp//~v59dR~
        {    //to skip multiple 230                                //~v59dR~
    		rc=FTPRC_PARSEERR;                                     //~v59dR~
        	break;                                                 //~v59dR~
        }                                                          //~v59dR~
        rc=0;                                                      //~v59dI~
        break;                                                     //~v59dI~
    }                                                              //~v59dI~
    if (pstdo!=pstdo0)                                             //~v59dR~
    {                                                              //~v59dI~
//  	memcpy(pstdo0,pstdo,4*stdoctr);//shift to top              //~v6hhR~
//    	memcpy(pstdo0,pstdo,PTRSZ*stdoctr);//shift to top          //~v6hhI~//~v6D0R~
      	memcpy(pstdo0,pstdo,(size_t)(PTRSZ*stdoctr));//shift to top//~v6D0I~
        pstdo=pstdo0;                                              //~v59dI~
    }                                                              //~v59dI~
	*Pppstdo=pstdo;                                                //~v59dR~
	*Ppstdoctr=stdoctr;                                            //~v59dR~
    return rc;                                                     //~v59dI~
}//uftpcmdresphdrchk                                               //~v59dR~
//**********************************************************************//~v59dI~
// chk cmd resp line                                               //~v59dI~
//  update line ptr to next of found line if found else no update  //~v59dI~
// return :0 okstr found, 1;okstr2 found;              4:reached to end//~v59dR~
//**********************************************************************//~v59dI~
int uftpcmdsrchrespid(char ***Pppstdo,int *Ppstdoctr,char *Pokrespid)//~v59dR~
{                                                                  //~v59dI~
    char **pstdo,*stdo,*pc;                                        //~v59dR~
    int stdoctr,rc=UFCSRRC_EOL,ii;                                 //~v59dR~
    int xcompsw=0;                                                 //~v5b7I~
//********************                                             //~v59dI~
	stdoctr=*Ppstdoctr;                                            //~v59dR~
	pstdo=*Pppstdo;                                                //~v59dR~
    for (;stdoctr>0;stdoctr--,pstdo++)                             //~v59dI~
    {                                                              //~v59dI~
    	stdo=*pstdo;                                               //~v59dI~
        UTRACEP("uftpcmdsrchrespid stdo=%s\n",stdo);               //~v6qbR~
        for (pc=Pokrespid,ii=0;*pc;pc+=4,ii++)                     //~v59dI~
        {                                                          //~v59dI~
        	UTRACEP("uftpcmdsrchrespid req=%s\n",pc);              //~v6qbR~
          if (*(pc+1)=='*')	//1 byte chk                           //~v5arI~
          {                                                        //~v5arI~
        	if (*stdo==*pc)                                        //~v5arI~
            {                                                      //~v5arI~
        		rc=ii;                                             //~v5arI~
        		break;                                             //~v5arI~
            }                                                      //~v5arI~
          }                                                        //~v5arI~
          else                                                     //~v5arI~
        	if (!memcmp(stdo,pc,3))                                //~v59dR~
        	{                                                      //~v59dR~
                if (!memcmp(stdo,FTPRESPID_XCOMP,3))               //~v5b7I~
            	  if (!strstr(*pstdo," deleted "))	//ignore "226 File deleted successfully"//~v619I~
                	xcompsw=1;                                     //~v5b7I~
        		rc=ii;                                             //~v59dR~
        		break;                                             //~v59dR~
        	}                                                      //~v59dR~
          if (*(pc+3)=='|')                                        //~v619I~
          	ii--;           //operand count                        //~v619I~
        }                                                          //~v59dI~
        if (rc!=UFCSRRC_EOL)  	//found                            //~v59dI~
        	break;                                                 //~v59dI~
    }                                                              //~v59dI~
    if (rc!=UFCSRRC_EOL)	//found                                //~v59dR~
    {                                                              //~v59dI~
		--stdoctr;                                                 //~v5b7R~
		++pstdo;                                                   //~v5b7R~
        if (xcompsw && stdoctr)                                    //~v5b7R~
        {                                                          //~v5b7I~
            if (strstr(*pstdo," bytes "))                          //~v5b7R~
            	stdoctr--,++pstdo;                                 //~v5b7I~
        }                                                          //~v5b7I~
		*Ppstdoctr=stdoctr;                                        //~v5b7I~
		*Pppstdo=pstdo;                                            //~v5b7I~
    }                                                              //~v59dI~
    UTRACEP("uftpcmdsrchrespid rc=%d\n",rc);                       //~v6qbR~
    return rc;                                                     //~v59dI~
}//uftpcmdsrchrespid                                               //~v59dI~
//**************************************************************** //~v59dM~
//simple responce chk                                              //~v59dM~
//*retrn:rc                                                        //~v59dM~
//**************************************************************** //~v59dM~
int uftpsimplerespchk(char *Pcmd,char *Prespid,char *Pfname,char ***Ppstdo,int *Ppstdoctr,int Prc)//~v59dM~
{                                                                  //~v59dM~
    int rc;                                                        //~v59dM~
    char **stdo;                                                   //~v59dM~
    char **stdo0;                                                  //~v5cnI~
//********************                                             //~v59dM~
	stdo=*Ppstdo;                                                  //~v59dM~
    stdo0=stdo;                                                    //~v5cnI~
    rc=uftpcmdsrchrespid(&stdo,Ppstdoctr,Prespid);                 //~v59dM~
    if (rc!=0)		//err                                          //~v59dR~
    {                                                              //~v59dM~
       if(stdo==stdo0)               //avoid abend                 //~v5cnI~
        uerrmsg("%s failed for %s.",0,                             //~v5cnI~
        			Pcmd,Pfname); //already exit or path not found //~v5cnI~
       else                                                        //~v5cnI~
        uerrmsg("%s failed for %s. (%s)",0,                        //~v59dM~
        			Pcmd,Pfname,*(stdo-1)); //already exit or path not found//~v59dM~
		uftplog(FTPLOG_ERRM,0);	//logging errmsg                   //~v61bI~
        rc=Prc;                                                    //~v59dM~
    }                                                              //~v59dM~
    *Ppstdo=stdo;                                                  //~v59dM~
    return rc;                                                     //~v59dM~
}//uftpsimplerespchk                                               //~v59dM~
//**********************************************************************//~v59dM~
// advance to next ftp subcmd result part                          //~v59dM~
// return :1 eof                                                   //~v59dR~
//**********************************************************************//~v59dM~
int uftpnextstdo(char ***Ppstdo,int *Ppstdoctr)                    //~v59dM~
{                                                                  //~v59dM~
	int ii,stdoctr;                                                //~v59dR~
    char **pstdo,*stdo;                                            //~v59dR~
//********************                                             //~v59dM~
	pstdo=*Ppstdo;                                                 //~v59dR~
	stdoctr=*Ppstdoctr;                                            //~v59dM~
    for (ii=stdoctr;ii>0;ii--,pstdo++)                             //~v59dR~
    {                                                              //~v59dM~
		stdo=*pstdo;                                               //~v59dI~
    	if (*stdo=='?')	//reached delm                             //~v59dR~
        {                                                          //~v59dM~
        	ii--;                                                  //~v59dM~
        	pstdo++;                                               //~v59dR~
        	break;                                                 //~v59dM~
        }                                                          //~v59dM~
    }                                                              //~v59dM~
	*Ppstdoctr=ii;                                                 //~v59dM~
	*Ppstdo=pstdo;                                                 //~v59dR~
    return (ii==0);                                                //~v59dI~
}//uftpnextstdo                                                    //~v59dM~
//*******************************************************          //~v59dM~
//*serach filename on stdo line by ls cmd,return pudirlist         //~v59dM~
//*parm 1:file name                                                //~v59dM~
//*parm 2:output file info addr(optional)                          //~v59dM~
//*rc :0,ENOENT,EPERM                                              //~v61aI~
//*******************************************************          //~v59dM~
int uftpsrchfname(PUFTPHOST Ppuftph,char **Pstdo,int Pstdoctr,char *Pfname,PUDIRLIST Ppudl)//~v5afR~
{                                                                  //~v59dM~
    int rc,ii;                                                     //~v59dM~
    char **ppc,*pc;                                                //~v59dR~
//*********************************                                //~v59dM~
	rc=ENOENT;                                                     //~v59dM~
    for (ppc=Pstdo,ii=0;ii<Pstdoctr;ppc++,ii++)                    //~v59dM~
    {                                                              //~v59dM~
        pc=*ppc;		//recird ptr                               //~v59dM~
	  if (UFTPHISPSFTP(Ppuftph))                                   //~v61kI~
      {                                                            //~v61kI~
        if (FTP_PSFTP_RESPEND(pc))                                 //~v61kI~
        	break;                                                 //~v61kI~
        if (FTP_PSFTP_OPENERR(pc))                                 //~v61kI~
        {                                                          //~v61kI~
            rc=EPERM;                                              //~v61kI~
        	break;                                                 //~v61kI~
        }                                                          //~v61kI~
      }                                                            //~v61kI~
      else                                                         //~v61kI~
      {                                                            //~v61kI~
        if (!memcmp(pc,FTPRESPID_XCOMP,3))                         //~v59dI~
        {                                                          //~v61aI~
            if (strstr(pc,FTPERR_OPEN))//  "failed to open directory"//~v61aI~
            	rc=EPERM;                                          //~v61aI~
        	break;                                                 //~v59dI~
        }                                                          //~v61aI~
        if (!memcmp(pc,"total",5))                                 //~v59dR~
        	continue;                                              //~v59dR~
      }                                                            //~v61kI~
        if (!strstr(pc,Pfname))	//search fname                     //~v59dM~
        	continue;                                              //~v59dM~
        if (uftpgetdl1(Ppuftph,pc,Ppudl))                          //~v5afR~
        	continue;                                              //~v59dM~
        if (!strcmp(Ppudl->name,Pfname))	//name match           //~v59dR~
        {                                                          //~v59dM~
        	rc=0;                                                  //~v59dM~
        	break;                                                 //~v59dM~
        }                                                          //~v59dM~
    }                                                              //~v59dM~
    return rc;                                                     //~v59dM~
}//uftpsrchfname                                                   //~v59dM~
//*******************************************************          //~v59dI~
//*search filename in dirlist and step to transfer comp     //~v59dR~//~v6qaR~
//*parm 1:file name                                                //~v59dI~
//*parm 2:output file info addr(optional)                          //~v59dI~
//*******************************************************          //~v59dI~
int uftpsrchfnameslink(PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pslink,PUDIRLIST Ppudl)//~v5afR~
{                                                                  //~v59dI~
    int rc,pathlen,stdoctr;                                        //~v59dR~
    char  *pc,*fnm,**stdo;                                         //~v59dI~
//*********************************                                //~v59dI~
	pathlen=FTP_PATHLEN(Pslink);                                   //~v59dI~
    fnm=Pslink+pathlen;                                            //~v59dI~
	rc=ENOENT;                                                     //~v59dI~
    stdo=*Ppstdo;                                                  //~v59dI~
	stdoctr=*Ppstdoctr;                                            //~v59dI~
    for (;stdoctr>0;stdo++,stdoctr--)                              //~v59dI~
    {                                                              //~v59dI~
        pc=*stdo;   	//recird ptr                               //~v59dR~
//UTRACEP("stdoctr=%d pc=%s\n",stdoctr,pc);                        //~v5a8R~
	  if (UFTPHISPSFTP(Ppuftph))                                   //~v61kI~
      {                                                            //~v61kI~
        if (FTP_PSFTP_RESPEND(pc))                                 //~v61kR~
        	break;                                                 //~v61kI~
        if (FTP_PSFTP_OPENERR(pc))                                 //~v61kI~
        {                                                          //~v61kI~
            rc=EPERM;                                              //~v61kI~
        	break;                                                 //~v61kI~
        }                                                          //~v61kI~
      }                                                            //~v61kI~
      else                                                         //~v61kI~
      {                                                            //~v61kI~
        if (!memcmp(pc,FTPRESPID_XCOMP,3))                         //~v59dI~
        {                                                          //~v61aI~
            if (strstr(pc,FTPERR_OPEN))//  "failed to open directory"//~v61aI~
            	rc=EPERM;                                          //~v61aI~
        	break;                                                 //~v59dI~
        }                                                          //~v61aI~
        if (!memcmp(pc,"total",5))                                 //~v59dI~
        	continue;                                              //~v59dI~
      }                                                            //~v61kM~
        if (!rc)                                                   //~v59dI~
        	continue;                                              //~v59dI~
UTRACEP("slink strcmp %s: pc=%s\n",fnm,pc);                      //~v5a8R~//~v6qaR~
        if (!strstr(pc,fnm))	//search fname                     //~v59dR~
        	continue;                                              //~v59dI~
UTRACEP("slink srch %s: pc=%s\n",fnm,pc);                        //~v5a8R~//~v6qaR~
        if (uftpgetdl1(Ppuftph,pc,Ppudl))                          //~v5afR~
        	continue;                                              //~v59dI~
UTRACEP("slink strcmp %s: name=%s\n",fnm,Ppudl->name);           //~v5a8R~//~v6qaR~
        if (!strcmp(Ppudl->name,fnm))	//name match               //~v59dR~
        {                                                          //~v5a8I~
UTRACEP("slink strcmp found %s: name=%s\n",fnm,Ppudl->name);     //~v5a8R~//~v6qaR~
        	rc=0;                                                  //~v5a8I~
        	break;                                                 //~v5a8I~
        }                                                          //~v5a8I~
    }                                                              //~v59dI~
    *Ppstdo=stdo;                                                  //~v59dI~
	*Ppstdoctr=stdoctr;                                            //~v59dI~
UTRACEP("ret rc=%d,ctr=%d\n",rc,stdoctr);                        //~v5a8R~//~v6qaR~
    return rc;                                                     //~v59dI~
}//uftpsrchfnameslink                                              //~v59dR~
//*******************************************************          //~v59dM~
//*get udirlist from stdo                                          //~v59dM~
//*parm 1:file name                                                //~v59dM~
//*parm 2:output file info addr(optional)                          //~v59dM~
//*******************************************************          //~v59dM~
int uftpgetdl(PUFTPHOST Ppuftph,char **Pstdo,int Pstdoctr,PUDIRLIST *Pppudirlist,int *Ppentno)//~v5afR~
{                                                                  //~v59dM~
	int ii,listctr,rc=0,listctr0;                                  //~v59dM~
    char **stdo,*rec=NULL;                                              //~v59dM~//~v6h6R~
    PUDIRLIST pudl,pudl0;                                          //~v59dM~
    int openerrsw=0;                                               //~v61aI~
//*******************                                              //~v59dM~
    *Pppudirlist=0;                                                //~v61kI~
//count line                                                       //~v59dM~
  if (UFTPH_ISSMB(Ppuftph))                                        //~v6d1I~
  	listctr=uftp3smb_getdirlistctr(0,Ppuftph,Pstdo,Pstdoctr);      //~v6d1I~
  else                                                             //~v6d1I~
  {                                                                //~v6d1I~
	for (ii=0,stdo=Pstdo,listctr=0;ii<Pstdoctr;ii++,stdo++)        //~v59dM~
    {                                                              //~v59dM~
    	rec=*stdo;                                                 //~v59dM~
	  if (UFTPHISPSFTP(Ppuftph))                                   //~v61kI~
      {                                                            //~v61kI~
        if (FTP_PSFTP_RESPEND(rec))                                //~v61kR~
        	break;                                                 //~v61kI~
        if (FTP_PSFTP_OPENERR(rec))                                //~v61kI~
        {                                                          //~v61kI~
            openerrsw=1;                                           //~v61kI~
        	break;                                                 //~v61kI~
        }                                                          //~v61kI~
      }                                                            //~v61kI~
      else                                                         //~v61kI~
      {                                                            //~v61kI~
        if (!memcmp(rec,FTPRESPID_XCOMP,3))                        //~v59dM~
        {                                                          //~v61aI~
            if (strstr(rec,FTPERR_OPEN))//  "failed to open directory"//~v61aI~
            	openerrsw=1;                                       //~v61aI~
        	break;                                                 //~v59dM~
        }                                                          //~v61aI~
      }                                                            //~v61kI~
        listctr++;                                                 //~v59dM~
	}                                                              //~v59dM~
  }                                                                //~v6d1I~
    if (!listctr)                                                  //~v59dM~
    {                                                              //~v61aI~
    	if (openerrsw)                                             //~v61aI~
        {                                                          //~v61aI~
  	        uerrmsg("%s failed by \"%s\"",0,                       //~v61aR~
      				Ppuftph->UFTPHlscmd,rec);                      //~v61aR~
			uftplog(FTPLOG_ERRM,0);	//logging errmsg               //~v61bI~
    		return EPERM;                                          //~v61aR~
        }                                                          //~v61aI~
    	return ENOENT;                                             //v59dM~
    }                                                              //~v61aI~
    if (udirlist_chk_max_entry(listctr))                           //~v6qbI~
        return 4;                                                  //~v6qbI~
//  pudl0=umalloc((UINT)((listctr+1)*UDIRLISTSZ)); //1:terminater  //~v59dM~//~v6qaR~
//  pudl0=UALLOCC(1,(UINT)((listctr+1)*UDIRLISTSZ)); //1:terminater//~v6qaI~//~v6D0R~
    pudl0=UALLOCC(1,((size_t)listctr+1)*UDIRLISTSZ); //1:terminater//~v6D0I~
    UALLOCCHK(pudl0,UALLOC_FAILED);                                //~v59dM~
//fill data                                                        //~v59dM~
	pudl=pudl0;                                                    //~v59dM~
    listctr0=listctr;                                              //~v59dM~
	for (ii=0,stdo=Pstdo,listctr=0;ii<listctr0;ii++,stdo++)        //~v59dM~
    {                                                              //~v59dM~
    	rec=*stdo;                                                 //~v59dM~
    	if (uftpgetdl1(Ppuftph,rec,pudl))	//skip err line        //~v5afR~
        	continue;                                              //~v59dM~
        listctr++;                                                 //~v59dM~
        pudl++;                                                    //~v59dM~
	}                                                              //~v59dM~
//  memset(pudl,0,UDIRLISTSZ);//last entery as terminator          //~v59dI~//~v6qaR~
    if (!listctr)                                                  //~v59dM~
    {                                                              //~v59dM~
//  	ufree(pudl0);                                              //~v59dM~//~v6qaR~
    	UDIRLIST_FREE(pudl0);                                      //~v6qaI~
    	rc= ENOENT;                                                //~v59dM~
    }                                                              //~v59dM~
    *Ppentno=listctr;                                              //~v59dM~
    *Pppudirlist=pudl0;                                            //~v59dM~
    return rc;                                                     //~v59dM~
}//uftpgetdl                                                       //~v59dM~
//------------------------------------------------------------------------------//~v59dM~
//------------------------------------------------------------------------------//~v59dM~
//------------------------------------------------------------------------------//~v59dM~
//                                                                 //~v59dM~
//16:28 ===>> ls -lna                                              //~v59dM~
//drwxrwxrwx   3 206      104         5120 Oct 30 16:20 .          //~v59dM~
//drwxrwxrwx  12 206      104         9728 Sep 29 15:16 ..         //~v59dM~
//-rwxrwxrwx   1 206      104            0 Mar 01 2002  MSC-6      //~v59dM~
//-rwxrwxrwx   1 206      104         2174 Aug 25 17:55 xeaixkey.rh9//~v59dM~
//-rwxrwxrwx   1 206      104          137 Aug 25 17:56 xelt       //~v59dM~
//-rwxrwxrwx   1 206      104       659426 Dec 05 2002  xff.mtr    //~v59dM~
//lrwxrwxrwx   1 db2inst1 db2iadm1      30 Oct 30 19:48 x1aa -> /home/usrs/u0004000/ulib/xlink//~v59dM~
//(by ln -s /home/usrs/u0004000/xlink x1aa                         //~v59dM~
//            source                  target                       //~v59dM~
//*******************************************************          //~v59dM~
//*parse a line of ls cmd output                                   //~v59dM~
//*rc :4 not valid ls cmd output line                              //~v59dM~
//*******************************************************          //~v59dM~
int uftpgetdl1(PUFTPHOST Ppuftph,char *Prec,PUDIRLIST Ppudl)       //~v5afR~
{                                                                  //~v59dM~
    char *pc,*ppermission,*plinkno,*pusr,*pgrp,*psize,*pmonth;     //~v59dM~
    char *pday,*phhmmoryear,*pfname,*pslink,*pcw;                  //~v5aeR~
    ULONG mode;                                                    //~v59dM~
#ifdef LFSSUPP                                                     //~v5k0R~
//  ULONG ulhl[2]; 	//long long int                                //~v5k0I~//~v690R~
    LONG ulhl[2]; 	//long long int                                //~v690I~
#endif                                                             //~v5k0I~
	char wkline[512+MAXSLINKNMSZ*2];                               //~v6qdI~
//*********************************                                //~v59dM~
    UTRACEP("%s:rec=%s\n",UTT,Prec);                               //+v6J0I~
  	if (UFTPH_ISSMB(Ppuftph))                                      //~v6d1I~
    	return uftp3smb_getdl1(Ppuftph,Prec,Ppudl);                //~v6d1I~
//  memset(Ppudl,0,UDIRLISTSZ); //cleared by caller            //~v59dM~//~v6qaR~
//  ppermission=Prec;                                              //~v59dM~//~v6qdR~
	strcpy(wkline,Prec);                                           //~v6qdI~
    ppermission=wkline;                                            //~v6qdI~
    pc=strchr(ppermission,' ');                                    //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    plinkno=pc+strspn(pc," ");                                     //~v59dM~
    pc=strchr(plinkno,' ');                                        //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    pusr=pc+strspn(pc," ");                                        //~v59dM~
    pc=strchr(pusr,' ');                                           //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    *pc++=0;                                                       //~v59dM~
    pgrp=pc+strspn(pc," ");                                        //~v59dM~
    pc=strchr(pgrp,' ');                                           //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    *pc++=0;                                                       //~v59dM~
    psize=pc+strspn(pc," ");                                       //~v59dM~
    pc=strchr(psize,' ');                                          //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    pmonth=pc+strspn(pc," ");                                      //~v59dM~
  if (*pmonth>='0' && *pmonth<='9')   //by numeric                 //~v5aeI~
  {                                                                //~v5aeI~
  		for (pcw=pmonth+2;*pcw;pcw++)	                           //~v5aeI~
        	if (*pcw>='0' && *pcw<='9')                            //~v5aeI~
            	break;                                             //~v5aeI~
        if (!*pcw)                                                 //~v5aeI~
        	return 4;                                              //~v5aeI~
  		pday=pcw;                                                  //~v5aeI~
  }                                                                //~v5aeI~
  else                                                             //~v5aeI~
  {                                                                //~v5aeI~
    pc=strchr(pmonth,' ');                                         //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    pday=pc+strspn(pc," ");                                        //~v59dM~
  }                                                                //~v5aeI~
    pc=strchr(pday,' ');                                           //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    phhmmoryear=pc+strspn(pc," ");                                 //~v59dM~
    pc=strchr(phhmmoryear,' ');                                    //~v59dM~
    if (!pc)                                                       //~v59dM~
    	return 4;                                                  //~v59dM~
    pfname=pc+strspn(pc," ");                                      //~v59dM~
//  pc=strchr(pfname,' ');                                         //~v5bdR~
    pc=strstr(pfname," -> ");                                      //~v5bdI~
    if (pc)                                                        //~v59dM~
    {                                                              //~v59dM~
//  	*pc++=0;	//strz of fname                                //~v5bdR~
//  	pslink=pc;                                                 //~v5bdI~
    	*pc=0;  	//strz of fname                                //~v5bdI~
    	pslink=pc+4;                                               //~v5bdR~
    }                                                              //~v59dM~
    else                                                           //~v59dM~
    	pslink=0;                                                  //~v59dM~
//**                                                               //~v59dM~
//  strncpy(Ppudl->name,pfname,MAXFILENAMEZ);                      //~v59dM~//~v6J0R~
    uftp_udirlist_setname(0,Ppuftph,Ppudl,pfname,0);               //~v6J0R~
    mode=uftpgetmode(ppermission);                                 //~v59dM~
    Ppudl->attr=FILE_SETMODEATTR(mode,0);    //permissyon etc      //~v59dR~
//  len=strlen(pusr);                                              //~v59dR~
//  if (unumlen(pusr,0,len)==len)                                  //~v59dR~
//  	Ppudl->uid=atoi(pusr);                                     //~v59dR~
//  else                                                           //~v59dR~
		strncpy(Ppudl->uname,pusr,MAXUNAMESZ);                     //~v59dR~
//  len=strlen(pgrp);                                              //~v59dR~
//  if (unumlen(pgrp,0,len)==len)                                  //~v59dR~
//  	Ppudl->gid=atoi(pgrp);                                     //~v59dR~
//  else                                                           //~v59dR~
		strncpy(Ppudl->gname,pgrp,MAXGNAMESZ);                     //~v59dR~
#ifdef LFSSUPP                                                     //~v5k0R~
    pc=strchr(psize,' ');                                          //~v5k0I~
    if (pc)                                                        //~v5k0I~
        *pc=0;                                                     //~v5k0I~
    ulhl[0]=ulhl[1]=0;                                             //~v5k0R~
	ucalc_ld2dw(psize,ulhl);                                       //~v5k0I~
    if (pc)                                                        //~v5k0I~
        *pc=' ';                                                   //~v5k0I~
	Ppudl->size=((FILESZT)ulhl[0]<<32)|((FILESZT)ulhl[1]);         //~v5k0R~
#else                                                              //~v5k0I~
	Ppudl->size=atol(psize);                                       //~v59dM~
#endif                                                             //~v5k0I~
    if (!uftpgetdlftime(pmonth,pday,phhmmoryear,&Ppudl->date,&Ppudl->time))//time data exist//~v5a8R~
    {                                                              //~v5a8I~
//		uftpajustjst(Ppuftph,&Ppudl->date,&Ppudl->time);           //~v5dfR~
  		uftpajustjst(0,Ppuftph,&Ppudl->date,&Ppudl->time);         //~v5dfI~
//      Ppudl->attr|=FILE_FTPJST;                                  //~v5deR~
    }                                                              //~v5a8I~
//  if (S_ISLNK(mode) && pslink)	//		0120000		/* symbolic link *///~v61kR~
    if (S_ISLNK(mode))          	//		0120000		/* symbolic link *///~v61kI~
    {                                                              //~v59dM~
      if (pslink)	//		0120000		/* symbolic link */        //~v61kI~
      {                                                            //~v61kI~
                                                                   //~v61kI~
        pslink+=strspn(pslink," ");     //search "->"              //~v59dM~
//      pc=strchr(pslink,' ');      //search ln target             //~v5c5R~
//      if (!pc)                                                   //~v5c5R~
//          return 4;                                              //~v5c5R~
//      pslink=pc+strspn(pc," ");                                  //~v5c5R~
//      strncpy(Ppudl->slink,pslink,sizeof(Ppudl->slink));         //~v59dR~//~v6qaR~
        UDIRLIST_SET_SLINKNAME(Ppudl,pslink);                      //~v6qaI~
      }                                                            //~v61kI~
      else		//PSFTP v060 miss linkname on dirlist              //~v61kI~
      {                                                            //~v61kI~
      	uerrmsg("%s is missing linkname on dir-list",0,            //~v61kI~
        		pfname);                                           //~v61kI~
		uftplog(FTPLOG_ERRM,0); //logging errmsg                   //~v61kI~
        ugeterrmsg();       //no display on screen,log only        //~v61kI~
        UDIRLIST_SET_SLINKNAME(Ppudl,FTP_SLINKNAME_NA);            //~v6qeI~
        Ppudl->otherflag|=UDLOF_SLINKNAME_NA; //avoid target search//~v6qeR~
      }                                                            //~v61kI~
    }                                                              //~v59dM~
    UTRACEP("%s:pudl=%p,name=%s,short=%s,pslink=%s\n",UTT,Ppudl,Ppudl->name,Ppudl->nameShortbuff,Ppudl->pslink);//+v6J0R~
    return 0;                                                      //~v59dM~
}//uftpgetdl1                                                      //~v59dM~
//*******************************************************          //~v59dM~
//*get mode from mode string of ls cmd output                      //~v59dM~
//*******************************************************          //~v59dM~
unsigned int uftpgetmode(char *Pstring)                            //~v59dM~
{                                                                  //~v59dM~
	int ch,ftype,gp,op,up;                                         //~v59dR~
    char *pc;                                                      //~v59dR~
    ULONG mode;                                                    //~v59dI~
//*********************************                                //~v59dM~
    pc=Pstring;                                                    //~v59dM~
    ch=*pc++;                                                      //~v59dM~
    ftype=S_IFREG;		//0100000 /*   regular */                  //~v59dR~
    switch(ch)                                                     //~v59dM~
    {                                                              //~v59dM~
    case 'd':   //dir                                              //~v59dM~
		ftype=S_IFDIR;	//	0040000		/*   directory */          //~v59dR~
    	break;                                                     //~v59dM~
    case 'b':   //block                                            //~v59dM~
		ftype=S_IFBLK;	//0060000		/*   block special */      //~v59dR~
    	break;                                                     //~v59dM~
    case 'c':   //char                                             //~v59dM~
		ftype=S_IFCHR;	//0020000		/*   character special */  //~v59dR~
    	break;                                                     //~v59dR~
    case 'l':   //link                                             //~v59dM~
		ftype=S_IFLNK;	//		0120000		/* symbolic link */    //~v59dR~
    	break;                                                     //~v59dM~
    case 'p':   //pipe                                             //~v59dM~
		ftype=S_IFIFO;	//	0010000		/*   fifo */               //~v59dR~
    	break;                                                     //~v59dM~
    case 's':   //socket                                           //~v59dM~
		ftype=S_IFSOCK;	//	0140000		/* socket */               //~v59dR~
    	break;                                                     //~v59dR~
	}                                                              //~v59dM~
//owner                                                            //~v59dM~
    up=0;                                                          //~v59dM~
    if (*pc++=='r')                                                //~v59dM~
		up|=S_IRUSR;//		0000400		/* read permission: owner *///~v59dR~
    if (*pc++=='w')                                                //~v59dM~
		up|=S_IWUSR;//		0000200		/* write permission: owner *///~v59dR~
    ch=*pc++;                                                      //~v59dM~
    switch(ch)                                                     //~v59dM~
    {                                                              //~v59dM~
    case 'x':                                                      //~v59dM~
		up|=S_IXUSR;		//0000100		/* execute/search permission: owner *///~v59dR~
        break;                                                     //~v59dM~
    case 's':                                                      //~v59dM~
		up|=S_IXUSR|S_ISUID;	//	0100+0004000		/* set user id on execution *///~v59dR~
        break;                                                     //~v59dI~
    case 'S':                                                      //~v59dM~
		up|=S_ISUID;			//	0004000		/* set user id on execution *///~v59dM~
        break;                                                     //~v59dM~
    }                                                              //~v59dM~
//group                                                            //~v59dM~
    gp=0;                                                          //~v59dM~
    if (*pc++=='r')                                                //~v59dM~
		gp|=S_IRGRP;//   0000040		/* read permission: group *///~v59dR~
    if (*pc++=='w')                                                //~v59dM~
		gp|=S_IWGRP;	//	0000020		/* write permission: group *///~v59dR~
    ch=*pc++;                                                      //~v59dM~
    switch(ch)                                                     //~v59dM~
    {                                                              //~v59dM~
    case 'x':                                                      //~v59dM~
		gp|=S_IXGRP;//		0000010		/* execute/search permission: group *///~v59dR~
        break;                                                     //~v59dM~
    case 's':                                                      //~v59dM~
		gp|=S_IXGRP|S_ISGID;//		0002000		/* set group id on execution *///~v59dR~
        break;                                                     //~v59dI~
    case 'S':                                                      //~v59dM~
		gp|=S_ISGID;//		0002000		/* set group id on execution *///~v59dM~
        break;                                                     //~v59dM~
    }                                                              //~v59dM~
//other                                                            //~v59dR~
    op=0;                                                          //~v59dM~
    if (*pc++=='r')                                                //~v59dM~
		op|=S_IROTH;//   0000004		/* read permission: other *///~v59dR~
    if (*pc++=='w')                                                //~v59dM~
		op|=S_IWOTH;//		0000002		/* write permission: other *///~v59dR~
    ch=*pc++;                                                      //~v59dM~
    switch(ch)                                                     //~v59dM~
    {                                                              //~v59dM~
    case 'x':                                                      //~v59dM~
		op|=S_IXOTH;//		0000001		/* execute/search permission: other *///~v59dR~
        break;                                                     //~v59dM~
    case 't':                                                      //~v59dM~
		gp|=S_IXOTH|S_ISVTX;                                       //~v59dR~
        break;                                                     //~v59dI~
    case 'T':                                                      //~v59dM~
		gp|=S_ISVTX;//  0001000		/* save text even after use */ //~v59dM~
        break;                                                     //~v59dM~
    }                                                              //~v59dM~
//  mode=ftype|up|gp|op;                                           //~v59dM~//~v6D0R~
    mode=(ULONG)(ftype|up|gp|op);                                  //~v6D0I~
//  return mode;                                                   //~v59dM~//~v6D1R~
    return (unsigned)mode;                                         //~v6D1I~
}//ufilegetmode                                                    //~v59dM~
//*******************************************************          //~v59dM~
//*get file modification time from time string of ls cmd output    //~v59dM~
// rc:1 no time data                                               //~v59dM~
//*******************************************************          //~v59dM~
int uftpgetdlftime(char *Pmonth,char *Pday,char *Phhmmoryear,FDATE *Pfdate,FTIME *Pftime)//~v59dR~
{                                                                  //~v59dM~
    ULONG uldttm[2];                                               //~v59dM~
    int hh,min,yy,mm,dd,rc,mmc;                                    //~v5axR~
    int yy2;                                                       //~v6D2I~
//*********************************                                //~v59dM~
    mm=uftpgetmonth(Pmonth);                                       //~v59dM~
    if (!mm)    //invalid                                          //~v5aeI~
      mm=                                                          //~v5iaI~
        atoi(Pmonth);                                              //~v5aeI~
    dd=atoi(Pday);                                                 //~v59dM~
    if (*(Phhmmoryear+2)==':')                                     //~v59dM~
    {                                                              //~v59dM~
    	hh=atoi(Phhmmoryear);                                      //~v59dM~
    	min=atoi(Phhmmoryear+3);                                   //~v59dM~
//      utimeedit((UCHAR*)UET_ILONG,uldttm);                 //time_t and milisec//~v59dM~//~v6hhR~
        utimeedit((UCHAR*)(ULPTR)UET_ILONG,uldttm);                 //time_t and milisec//~v6hhI~
//  	yy=uldttm[0];                                              //~v59dM~//~v6D0R~
    	yy=(int)uldttm[0];                                         //~v6D0I~
        mmc=((ULONG)yy>>8)&255;                                    //~v5axR~
//      yy=((ULONG)yy>>24)*100+(((ULONG)yy>>16)&255);              //~v59dM~//~v6D0R~
        yy=(int)(((ULONG)yy>>24)*100+(((ULONG)yy>>16)&255));       //~v6D0I~
        if (mmc<mm)	//month is future                              //~v5axI~
        	yy--;                                                  //~v5axI~
        rc=0;                                                      //~v59dM~
    }                                                              //~v59dM~
    else                                                           //~v59dM~
    {                                                              //~v59dM~
    	hh=0;                                                      //~v59dM~
        min=0;                                                     //~v59dM~
    	yy=atoi(Phhmmoryear);                                      //~v59dM~
        rc=1;                                                      //~v59dM~
    }                                                              //~v59dM~
//setup udirlist                                                   //~v59dM~
  if (yy>1980)                                                     //~v5dgI~
//  Pfdate->year=yy-1980;                                          //~v59dM~//~v6BMR~
//  Pfdate->year=(USHORT)(yy-1980);                                //~v6BMI~//~v6D2R~
    yy2=yy-1980;                                                   //~v6D2I~
  else                                                             //~v5dgI~
//  Pfdate->year=0;                                                //~v5dgI~//~v6D2R~
    yy2=0;                                                         //~v6D2I~
//  Pfdate->month=mm;                                              //~v59dM~//~v6BMR~
//  Pfdate->month=(USHORT)mm;                                      //~v6BMI~//~v6D2R~
//  Pfdate->day=dd;                                                //~v59dM~//~v6BMR~
    ueditsetfdateUSHORT(0,yy2,mm,dd,Pfdate);                       //~v6D2I~
//  Pfdate->day=(USHORT)dd;                                        //~v6BMI~//~v6D2R~
//  Pftime->hours=hh;                                              //~v59dM~//~v6BMR~
//  Pftime->hours=(USHORT)hh;                                      //~v6BMI~//~v6D2R~
//  Pftime->minutes=min;                                           //~v59dM~//~v6BMR~
//  Pftime->minutes=(USHORT)min;                                   //~v6BMI~//~v6D2R~
//  Pftime->twosecs=0;                                             //~v59dM~//~v6D2R~
    ueditsetftimeUSHORT(0,hh,min,0,Pftime);                        //~v6D2I~
    return rc;                                                     //~v59dM~
}//uftpgetdlftime                                                  //~v59dR~
//**********************************************************************//~v59dM~
// return :month(01-12)                                            //~v59dM~
//**********************************************************************//~v59dM~
int uftpgetmonth(char *Pmonth)                                     //~v59dM~
{                                                                  //~v59dM~
	int ii;                                                        //~v59dM~
static char *Smonthtb[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",//~v59dM~
                         "Aug","Sep","Oct","Nov","Dec"};           //~v59dM~
//******************                                               //~v59dM~
    for (ii=0;ii<12;ii++)                                          //~v59dM~
        if (!memicmp(Pmonth,Smonthtb[ii],3))                       //~v59dM~
        	return ii+1;                                           //~v59dM~
	return 0;                                                      //~v59dM~
}//uftpgetmonth                                                    //~v59dR~
//**********************************************************************//~v6d1I~
// return :wday(0-->6)                                             //~v6d1I~
//**********************************************************************//~v6d1I~
int uftpgetwday(char *Pwday)                                       //~v6d1I~
{                                                                  //~v6d1I~
	int ii;                                                        //~v6d1I~
static char *Swdaytb[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};//~v6d1I~
//******************                                               //~v6d1I~
    for (ii=0;ii<7;ii++)                                           //~v6d1I~
        if (!memicmp(Pwday,Swdaytb[ii],3))                         //~v6d1I~
        	return ii;                                             //~v6d1I~
	return -1;                                                     //~v6d1R~
}//uftpgetmonth                                                    //~v6d1I~
//**************************************************************** //~v59dM~
//JST ajust                                                        //~v59dM~
//parm:Pdiff:diff from GMT: (jst=gmt-(-9:00,))                     //~v5afI~
//*retrn:rc                                                        //~v59dM~
//**************************************************************** //~v59dM~
//int uftpajustjst(PUFTPHOST Ppuftph,FDATE *Ppfdate,FTIME *Ppftime)//~v5dfR~
int uftpajustjst(int Popt,PUFTPHOST Ppuftph,FDATE *Ppfdate,FTIME *Ppftime)//~v5dfI~
{                                                                  //~v59dM~
	struct timeb tmb;                                              //~v59dM~
	int hh,yy,mm,dd,nextsw=0,tz;                                   //~v59dM~
//*******************                                              //~v59dM~
//if (Ppuftph->UFTPHflag & UFTPHFAJUST)                            //~v5dfR~
  if (Ppuftph->UFTPHflag & UFTPHFAJUST                             //~v5dfI~
  &&  !(Popt & UFAJO_GMT))    //not GMT conv(not xehost tz use)    //~v5dfR~
	tz=-Ppuftph->UFTPHtz;                                          //~v5afI~
  else                                                             //~v5afI~
  {                                                                //~v5afI~
    ftime(&tmb);                                                   //~v59dM~
	tz=tmb.timezone; //(time zone is minus value)                  //~v59dM~
  }                                                                //~v5afI~
	hh=Ppftime->hours-tz/60; //(time zone is minus value)          //~v59dM~
	mm=Ppftime->minutes-tz%60; //(by  min)                         //~v59dM~
    if (mm>=60)                                                    //~v59dM~
    {                                                              //~v59dM~
    	hh++;                                                      //~v59dM~
		mm-=60;                                                    //~v59dM~
    }                                                              //~v59dM~
    else                                                           //~v5afI~
    if (mm<0)                                                      //~v5afI~
    {                                                              //~v5afI~
    	hh--;                                                      //~v5afI~
        mm+=60;                                                    //~v5afI~
    }                                                              //~v5afI~
    if (hh>=24)                                                    //~v59dM~
    {                                                              //~v59dM~
		hh-=24;                                                    //~v59dM~
        nextsw=1;                                                  //~v59dM~
    }                                                              //~v59dM~
    else                                                           //~v5afI~
    if (hh<0)                                                      //~v5afI~
    {                                                              //~v5afI~
		hh+=24;                                                    //~v5afI~
        nextsw=-1;                                                 //~v5afI~
    }                                                              //~v5afI~
//  Ppftime->hours=hh;                                             //~v59dM~//~v6BMR~
//  Ppftime->hours=(USHORT)hh;                                     //~v6BMI~//~v6D2R~
//  Ppftime->minutes=mm;                                           //~v59dM~//~v6BMR~
//  Ppftime->minutes=(USHORT)mm;                                   //~v6BMI~//~v6D2R~
    ueditsetftimeUSHORT(0,hh,mm,Ppftime->twosecs,Ppftime);         //~v6D2R~
    if (nextsw)                                                    //~v59dM~
    {                                                              //~v59dM~
        dd=Ppfdate->day;                                           //~v59dM~
        mm=Ppfdate->month;                                         //~v59dM~
        yy=Ppfdate->year+1980;                                     //~v59dM~
        ucalc_nextday(nextsw,&yy,&mm,&dd);                         //~v5afR~
//      Ppfdate->day=dd;                                           //~v59dM~//~v6BMR~
//      Ppfdate->day=(USHORT)dd;                                   //~v6BMI~//~v6D2R~
//      Ppfdate->month=mm;                                         //~v59dM~//~v6BMR~
//      Ppfdate->month=(USHORT)mm;                                 //~v6BMI~//~v6D2R~
//      Ppfdate->year=yy-1980;                                     //~v59dM~//~v6BMR~
//      Ppfdate->year=(USHORT)(yy-1980);                           //~v6BMI~//~v6D2R~
	    ueditsetfdateUSHORT(0,yy-1980,mm,dd,Ppfdate);              //~v6D2I~
    }                                                              //~v59dM~
    return 0;                                                      //~v59dM~
}//uftpajustjst                                                    //~v59dM~
//**************************************************************** //~v5b1I~
//create temp dir                                                  //~v5b1I~
//*retrn:rc                                                        //~v5b1I~
//**************************************************************** //~v5b1I~
int uftpmktempwd(char *Ptempfnm)                                   //~v5b1I~
{                                                                  //~v5b1I~
#ifdef LNX                                                         //~v5b1I~
    if (!utempnamd("/tmp","xeapptmp_",Ptempfnm))//mkdir'ed         //~v5b1I~
        return -1;                                                 //~v5b1I~
#else                                                              //~v5b1I~
#ifdef UNX                                                         //~v5b1I~
    utempnam("/tmp","xeapptmp_",Ptempfnm);                         //~v5b1I~
#else                                                              //~v5b1I~
//  utempnam("","xeapptmp_",Ptempfnm);                             //~v5csR~
    utempnam("","xetmpd",Ptempfnm);                                //~v5csI~
#endif                                                             //~v5b1I~
    if (umkdir(Ptempfnm))                                          //~v5b1I~
    	return -1;                                                 //~v5b1I~
#endif                                                             //~v5b1I~
	return 0;                                                      //~v5b1I~
}//uftpmktempwd                                                    //~v5b1I~
//**************************************************************** //~v5b1I~
//delete temp dir                                                  //~v5b1I~
//*retrn:rc                                                        //~v5b1I~
//**************************************************************** //~v5b1I~
int uftpdeltempwd(char *Ptempfnm)                                  //~v5b1I~
{                                                                  //~v5b1I~
    if (Sftpopt &  UFTPO_KEEPWD)     //keep work dir for test      //~v5b1I~
    	return 0;                                                  //~v5b1I~
    return uxdelete(Ptempfnm,UXDELDIR,UXDELNOMSG|UXDELFORCE,0,0,0);//~v5b1I~
}//uftpdeltempwd                                                   //~v5b1I~
