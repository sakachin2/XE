//*CID://+vbvgR~:                              update#= 1504;      //~vbvgR~
//*************************************************************
//vbvg:221130 LNX compiler arning                                  //~vbvgI~
//vb3A:160625 for compiler warning,-Wformat-security(not literal printf format)//~vb3AI~
//vb34:160430 LNX compiler warning for bitmask assignment(FD_SET)  //~vb34I~
//vazy:150117 LNX conversion warning                               //~vazxI~
//vazx:150116 (BUG:LNX)kill parm is not thread_t but pid_t         //~vazxI~
//vazw:150115 pid on Win64 is intptr_t                             //~vazwR~
//vaz7:150109 ULPTR and ULONG (by C4244)                           //~vaz7I~
//vafx:120707 trace off for also xe3270                            //~vafxI~
//vafv:120630 titlemsg                                             //~vafvI~
//vaft:120630 (X64 BUG) 0c4 when logon cmd without opd parm        //~vaftI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafj:120621 (BUG)xe3270:s3270 process terminate                  //~vafjI~
//vafi:120621 (BUG)found on FC12 compiler warning                  //~vafiI~
//vafg:120616 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafgI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vafd:120608 (VC6)Bug found by C4701                              //~vafdI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaa9:111209 change default map to cp37(contains ctl char) from c3270ftp when not xe3270//~vaa9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va32:100129 (BUG)compiler warning                                //~va32I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v79k:080824 ebcdic for linux                                     //~v79kI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v8@N:080709 3270:expand errmsg buffsz                            //~v8@NI~
//v8@D:080627 3270:(BUG)for the case multiple dest defined for same dest/user,set config option each time//~v8@DI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd(cmd->3270, add TSO/cmd)//~v8@BI~
//v8@z:080625 3270:EUC<->EBC conversion                            //~v8@zI~
//v8@v:080624 3270:prelogon msg chk required for the case 522 abend logoff//~v8@rI~
//v8@r:080621 3270:use not prelogon msg but logon flag to chk already logon//~v8@rI~
//                 acsidentaly host down is rare for real host     //~v8@rI~
//                 (confirm connected each time)                   //~v8@rI~
//v8@p:080620 3270:split xe3270.c =.xe3270.c+xe3270f.c             //~v8@pI~
//v8@m:080620 3270:check READY on last line(linemode or spf changes temporary to line mode for cmd resonse)//~v8@mI~
//v8@j:080619 TSO:now \n is required to string input  from remote shell//~v8@jI~
//v8@e:080617 (LNX:BUG)3270:thered termination delay,quit process may wait//~v8@eI~
//v8@c:080615 3270:sysin cmd support multiple for wait test        //~v8@cI~
//v8@b:080614 3270:use wait output for timing problem              //~v8@bI~
//v8@9:080613 3270:MoveCursor,Home,Tab support for action of logon logoff//~v8@9I~
//v8@8:080613 3270:cmdline row parameter                           //~v8@8I~
//v8@7:080610 support snap/ascii as rsh cmd                        //~v8@7I~
//v8@6:080610 defines s3270 command string for each host           //~v8@5I~
//v8@5:080609 write ftp retry log to another log by append mode    //~v8@5I~
//v8@4:080609 for the case tso cmd response start from end of line of current(=6) panel(after logon panel err)//~v8@3I~
//v8@3:080602 receive also hostname on xehosts file to identify logon command//~v8@3I~
//v8@1:080526 (3270)TSOE support                                   //~v8@1I~
//v766:070531 (3270:BUG)dead lock when xe3270.cfg not found err(uerrmsgmt() and UTRCED in uerrmsg())//~v766I~
//v763:070530 3270:putconfirm allow line split                     //~v763I~
//v737:070106 (3270:BUG) if "%" is used xe3270 terminate. % may be used like as "exec %memb":% mean search clist not command//~v737I~
//v72K:061209 3270:issue pipe close readon msg if avail            //~v72KI~
//v72H:061206 3270:change FTP timeout foy sysincmd to same as req from xe//~v72HI~
//v72G:061206 3270:loop at screen clear by send3270 err            //~v72GI~
//v72F:061206 3270:configuarable emulator name                     //~v72FI~
//v72E:061205 3270:add tso subcmd "cmd" to enter Enter/PA1 etc     //~v72CI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//v72C:061205 3270:auto reply to invalid password "ENTER CURRENT PASSWORD"//~v72CI~
//v72A:061204 3270:String cmd may cause screen full(tso cmd input case)//~v72AI~
//v72x:061203 3270:v721 logic is not effective                     //~v72xI~
//v72w:061203 3270:if NamePipe closed,loop reconect and open       //~v72sI~
//v72s:061202 3270:performance:avid each time clear screen         //~v72sI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v72k:061125 3270:logon sometimes fail by null screen             //~v72kI~
//v72j:061124 3270:retry stop when timeout                         //~v72jI~
//v72i:061124 3270:timeout value is setable by cfg file            //~v72iI~
//v72h:061124 allow SEQ dataset update(upload)                     //~v72hI~
//v726:061118 3270:more FTP retry by config file specification     //~v725I~
//v725:061117 3270:conf file support                               //~v725I~
//v723:061117 3270:(BUG)GET2 may dupname,set exist=replace option  //~v723I~
//v721:061117 3270:at first logon logon fail sometimes by getting "no responce data" msg,retry screen chk.//~v721I~
//v71X:061113 3270:binmode compare null append allow supported by ufilecomp//~v71TI~
//v71T:061112 3270:add also get confirmation(once get err(dup record) occured)//~v71TI~
//v71S:061112 3270:add s3270 trace option -F                       //~v71SI~
//v71R:061111 3270:check after save by reloading and keep result in workdir//~v71RI~
//v71G:061103 (BUG:3270)pipe write return if data is longer than pipe size(read fail at xe)//~v71GI~
//v71E:061102 3270:expand tsocmd timeout 5-->20(for pds having many member)//~v71EI~
//v71n:061020 3270:add alloc/free cmd                              //~v71nI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71f:061012 (BUG)3270:abend when REenter case                    //~v71fI~
//v71e:061011 3270:REname support                                  //~v71eI~
//v719:061004 dirlist DSN list support                             //~v719I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v715:060221 (LNX)3270 ftp support(hostfile,TSO command)          //~v715I~
//v70z:060904 3270 ftp support(hostfile,TSO command)               //~v716I~
//*************************************************************
//*xe3270.c                                                        //~v725R~
//*************************************************************
#define PGM  			"xe3270"
#define VER  			"1.1"                                      //~v8@5R~

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>      //offsetof                                //~v716I~
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>                                                //~vafiI~

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
#include <uproc.h>
#include <uproc2.h>
#include <uparse.h>
#include <uedit.h>
#include <utrace.h>
#include <ufile.h>
#include <ufile3.h>                                                //~v725I~
#include <ufile4.h>                                                //~v71RR~
#include <ufile5.h>                                                //~v71RI~
#include <ustring.h>
#include <uvio.h>
#include <uvio2.h>
#include <ukbd.h>
#include <ukbdw.h>
#include <uftp.h>
#include <u3270.h>                                                 //~v716I~
#include <udbcschk.h>                                              //~v8@zI~
#include <ucvext.h>                                                //~v79aI~
#include <ucvebc.h>                                                //~vaa9I~
#include <uproc4.h>                                                //~vb34I~

#include "xe.h"
#include "xe3270.h"
#include "xe3270s.h"                                               //~v725I~
//*************************************************************
#define UERRMSG_MAXPARM   10                                       //~vafiI~
//*************************************************************
typedef struct _CLIENTTB
{
   int        CLTseqno;
#ifdef W32                                                         //~v715R~
   OVERLAPPED CLToverlap;
#else                                                              //~v715R~
   int        CLTpid;                                              //~v715R~
#endif                                                             //~v715R~
// ULONG      CLThpipe;                                            //~vafkR~
   ULPTR      CLThpipe;                                            //~vafkI~
// ULONG      CLThevent;                                           //~vafkR~
   ULPTR      CLThevent;                                           //~vafkI~
   int        CLTstat;
#define		CLTS_INIT         0
#define		CLTS_CONNECTING   1
#define		CLTS_CONNECTED    2
} CLIENTTB,*PCLIENTTB;
#define CLIENTTBSZ sizeof(CLIENTTB)                                //~v715I~

//*************************************************************
typedef int (SYSINCMDPROC)(int Popdno,char **Ppopd,PTHREADTB *Pppthtb);//~v716R~
typedef struct _CMDTB {
						char          CMDTcmd[8];
						char          CMDTalias[8];
                        SYSINCMDPROC *CMDTfunc;
                        char         *CMDThelp;
                      } CMDTB,*PCMDTB;
//*************************************************************

#define MONITOR_SLEEP_TIME    1000 //1000 milisecond wait if no child proccess//~v715R~


//#define LOCK_ENTER()    ucriticalsection(CRITSEC_ENTER,(ULONG)(&Ssemstdout))//~vafkR~
#define LOCK_ENTER()    ucriticalsection(CRITSEC_ENTER,(ULPTR)(&Ssemstdout))//~vafkI~
//#define LOCK_LEAVE()    fflush(stdout);fflush(stderr);ucriticalsection(CRITSEC_LEAVE,(ULONG)(&Ssemstdout))//~vafkR~
#define LOCK_LEAVE()    fflush(stdout);fflush(stderr);ucriticalsection(CRITSEC_LEAVE,(ULPTR)(&Ssemstdout))//~vafkI~
//#define LOCK_ENTER_THREAD()    ucriticalsection(CRITSEC_ENTER,(ULONG)(&Ssemthread))//~vafkR~
#define LOCK_ENTER_THREAD()    ucriticalsection(CRITSEC_ENTER,(ULPTR)(&Ssemthread))//~vafkI~
//#define LOCK_LEAVE_THREAD()    ucriticalsection(CRITSEC_LEAVE,(ULONG)(&Ssemthread))//~vafkR~
#define LOCK_LEAVE_THREAD()    ucriticalsection(CRITSEC_LEAVE,(ULPTR)(&Ssemthread))//~vafkI~

//*************************************************************
        SYSINCMDPROC sysincmdcancel,sysincmdlogoff,sysincmdget,sysincmdput,sysincmdhelp,sysincmdquit,sysincmdstring;
        SYSINCMDPROC sysincmdstat,sysincmdsnap,sysincmdlogon,sysincmdcmd;
        SYSINCMDPROC sysincmdlistds,sysincmdrename,sysincmddelete,sysincmdalloc,sysincmdfree;//~v71nR~
        SYSINCMDPROC sysincmdspf;                                  //~v72nI~
        SYSINCMDPROC sysincmdrsh;                                  //~v72BI~
        SYSINCMDPROC sysincmdtso;                                  //~v8@BI~
        SYSINCMDPROC sysincmdquery;                                //~v8@BI~
#define CMD_STR    XE3270_SUBCMD_STRING
#define CMD_LOGON  XE3270_SUBCMD_LOGON
#define CMD_QUIT   XE3270_SUBCMD_QUIT
#define CMD_RSH    XE3270_SUBCMD_RSH                               //~v72BI~
//                                               "---------1---------2---------3---------4---------5---------6-----" 80byte//~v71eI~
static CMDTB Ssysincmdtb[]=
    {
#define CMDID_HELP    0
		{"Help"    ,"?"        ,sysincmdhelp    ,"                                      # list command help"},//~v71eR~
#define CMDID_QUIT    1
		{CMD_QUIT  ,"Exit"     ,sysincmdquit    ,"                                      # end all session then exit"},//~v71eR~
#define CMDID_LOGON   2
		{CMD_LOGON ,"Login"    ,sysincmdlogon   ,"Host,Userid[/pswd]]                   # (connect then) logon"},//~v71eR~
#define CMDID_LOGOFF  3
		{"Logoff"  ,"Logout"   ,sysincmdlogoff  ,"Host,Userid                           # logoff the disconnect."},//~v71eR~
#define CMDID_CANCEL  4
		{"Cancel"  ,"Can"      ,sysincmdcancel  ,"Host,Userid                           # cancel/disconnect"},//~v71eR~
#define CMDID_GET     5
//  	{"Get"     ,"Receive"  ,sysincmdget     ,"Host,Userid[/pswd],hostF,pcF[,opts]   # download"},//~v8@pR~
    	{"Get"     ,CMD_RECEIVE,sysincmdget     ,"Host,Userid[/pswd],hostF,pcF[,opts]   # download"},//~v8@pI~
#define CMDID_PUT     6
//  	{"Put"     ,"Send"     ,sysincmdput     ,"Host,Userid[/pswd],hostF,pcF[,opts]   # upload"},//~v8@pR~
    	{"Put"     ,CMD_SEND   ,sysincmdput     ,"Host,Userid[/pswd],hostF,pcF[,opts]   # upload"},//~v8@pI~
#define CMDID_CMD     7
//  	{"Cmd"     ,"Action"   ,sysincmdcmd     ,"Host,Userid,\"command\"                 # 3270 command"},//~v8@BR~
    	{CMD_3270CMD,"Action"  ,sysincmdcmd     ,"Host,Userid,\"command\"                 # 3270 command"},//~v8@BI~
#define CMDID_STRING  8
		{CMD_STR   ,"String"   ,sysincmdstring  ,"Host,Userid,\"text\"                    # write text to screen"},//~v8@1R~
#define CMDID_READ    9
//  	{"Snap"    ,"Ascii"    ,sysincmdsnap    ,"Host,Userid                           # display screen snapshot"},//~v8@pR~
    	{CMD_SNAP  ,CMD_ASCII  ,sysincmdsnap    ,"Host,Userid                           # display screen snapshot"},//~v8@pI~
#define CMDID_STATUS 10
		{"Status"  ,"Stat"     ,sysincmdstat    ,"                                      # browse all session status"},//~v71eR~
#define CMDID_LISTDS 11                                            //~v716I~
		{"ListDS"  ,"LDS"      ,sysincmdlistds  ,"Host,Userid,hostF[,M]                 # issue TSO LISTDS command"},//~v71eR~

#define CMDID_RENAME 12                                            //~v71eR~
		{"Rename"  ,"Ren"      ,sysincmdrename  ,"Host,Userid,oldName,newName           # issue TSO RENAME command"},//~v71SR~
                                                                   //~v71eI~
#define CMDID_DELETE 13                                            //~v71eI~
		{"Delete"  ,"Del"      ,sysincmddelete  ,"Host,Userid,hostF                     # issue TSO RENAME command"},//~v71eI~
#define CMDID_ALLOC  14                                            //~v71nI~
		{"Alloc"   ,"Alloc"    ,sysincmdalloc   ,"Host,Userid,hostF[,options]           # issue TSO ALLOC command"},//~v71nR~
#define CMDID_FREE   15                                            //~v71nI~
		{"Free"    ,"Free"     ,sysincmdfree    ,"Host,Userid,hostF                     # issue TSO FREE command"},//~v71nI~
#define CMDID_SPF    16                                            //~v72nR~
		{"Spf"     ,"Spf"      ,sysincmdspf     ,"Host,Userid,hostF,SpfData             # update SPF information\n"//~v72nR~
                                      "   # SpfData: \"VV,MM,CR-DATE,UPD-DATE,TIME,LINE,INIT-LINE,USERID\""},//~v72nR~
#define CMDID_RSH    17                                            //~v72BR~
		{CMD_RSH   ,CMD_RSH    ,sysincmdrsh     ,"Host,Usrtid,\"text\"  (Internal-Use)    # write text to screen"},//~v72BI~
                                                                   //~v72nI~
#define CMDID_TSOCMD 18                                            //~v8@BI~
		{CMD_TSOCMD,CMD_TSOCMD2,sysincmdtso     ,"Host,Usrtid,\"text\"  (any TSO cmd)     # issue TSO any other cmd\n"//~v8@BR~
                                      "   # ex)  TSO,,,\"SUB 'DSN(MEMBER)'\""},//~v8@BI~
#define CMDID_QUERY  19                                            //~v8@BR~
		{CMD_QUERY,""          ,sysincmdquery   ,"Host,Usrtid,parmname(Query cfg parm)  # Internal use"},//~v8@BR~
                                                                   //~v8@BI~
        {"","",0,""}                                               //~v715R~
    };
static char *Srcdtb[]={                                            //~v716I~
		 "NotActive"      //0                                      //~v716I~
		,"Start"          //1                                      //~v716I~
		,"Connect"        //2                                      //~v716I~
		,"Logon"          //3                                      //~v716I~
		,"FTP(get)"       //4                                      //~v716I~
		,"FTP(put)"       //5                                      //~v716I~
		,"Snap"           //6                                      //~v716I~
//  	,"Cmd"            //7                                      //~v8@BR~
    	,CMD_3270CMD      //7                                      //~v8@BI~
		,"String"         //8                                      //~v716I~
		,"Logoff"         //9                                      //~v716I~
		,"Diconnect"      //10                                     //~v716I~
		,"ThreadStop"     //11                                     //~v716I~
		,"Listds"         //12                                     //~v716I~
		,"Rename"         //13                                     //~v71eI~
		,"Delete"         //14                                     //~v71eI~
		,"Allocate"       //15                                     //~v71nI~
		,"Free"           //16                                     //~v71nI~
		,"SPF"            //17   //stat cmd displys funcname       //~v72nI~
		,CMD_RSH          //18   //stat cmd displys funcname       //~v72BI~
		,CMD_TSOCMD       //19   //other TSO cmd                   //~v8@BI~
		};                                                         //~v716I~
static THREADTB Sthtb[MAX_THREADTB],Sthtbcmd,Sthtbmonitor;
static PTHREADTB Slastpthtb;        //for operand missing case     //~v715R~
static ULONG  Spid;
#ifdef LNX                                                         //~v715R~
	static pthread_mutex_t Ssemstdout=PTHREAD_MUTEX_INITIALIZER;   //~v715R~
	static pthread_mutex_t Ssemthread=PTHREAD_MUTEX_INITIALIZER;   //~v715R~
	static pthread_t Stidcmd=0;                                    //~v715R~
#else                                                              //~v715R~
static CRITICAL_SECTION Ssemstdout,Ssemthread;
static ULONG Stidcmd=0;
#endif                                                             //~v715R~
static int S3270port=XE3270_DEFAULT_PORTNO;
static char *Slogfnm=XE3270_DEFAULT_LOGFILE;	//parm fd
static CLIENTTB Scltb[MAX_3270CLIENT];
#ifdef W32                                                         //~v715I~
//static ULONG  Smainecblist[MAX_3270CLIENT+1];                    //~vafkR~
static ULPTR  Smainecblist[MAX_3270CLIENT+1];                      //~vafkI~
#endif                                                             //~v715I~

static int Smainopt;
static int Sotheropt;                                              //~v71SR~
#define  OTHEROPT_TRACE     0x01                                   //~v71SR~
static int Serrmsgmtopt;    //last msg linehdr id
//static int Stimeout_connect=TIMEOUT_CONNECT;                     //~v72iR~
//static int Stimeout_transfer=TIMEOUT_TRANSFER;                   //~v72iR~
#ifdef LNX                                                         //~v715R~
	static int Smsgcnt=0;                                          //~v715R~
	static int Sfdpipemain,Sfdpipenotify,Sfdpipealibi;             //~v715R~
    static char Spipenamealibi[_MAX_PATH];                         //~v715I~
#endif                                                             //~v715R~
static char Serrmsgwk[MAX_UERRMSGLL]; //to avoid response msg written bt uerrmsgmt//~v8@3R~
//*************************************************************
int initmain(void);
int endmain(void);
int endthread(PTHREADTB Ppthtb);
int cancelthread(PTHREADTB Ppthtb);
int snap3270printline(char *Pscrdata);                             //~v72BI~

int srchthread(int Popt,char *Phost,char *Puser);
#define SRCH_MAYNEW     0x01		//serach availabe to start ftp

int awakethread(PTHREADTB Ppthtb,int Preqcode,int Ptimeout);
int callsysincmd(char *Pcmd,PTHREADTB *Pppthtb);                   //~v716R~
int callsysincmd2(int Popdno,char **Ppopd,PTHREADTB *Pppthtb);     //~v716R~
//int clearthtb(PTHREADTB Ppthtb);                                 //~v715R~
int clearthtb(int Pfullclearsw,PTHREADTB Ppthtb);                  //~v715I~
                                                                   //~v715I~
#ifdef W32                                                         //~v715I~
int notifymonitor(void);
#endif                                                             //~v715I~
                                                                   //~v715I~
//int chkendproc(ULONG Ppid);                                      //~v715R~
int chkendproc(PTHREADTB Ppthtb);                                  //~v715I~
int calllogon(PTHREADTB Ppthtb,char **Ppopd);
int calllogoff(PTHREADTB Ppthtb);
int callend3270(PTHREADTB Ppthtb);
int callftp(int Preqcode,PTHREADTB Ppthtb,int Popdno,char **Ppopd);//~v716R~
int calltsocmd(int Preqcode,PTHREADTB Ppthtb,int Popdno,char **Ppopd);//~v716I~
int sysincmdstringsub(int Preqcode,int Popdno,char **Ppopd,PTHREADTB *Pppthtb);//~v72BI~
int killchild(PTHREADTB Ppthtb);
int funcstart3270(PTHREADTB Ppthtb);

int closepipe(PTHREADTB Ppthtb);

int isthreadbusy(int Popt,PTHREADTB Ppthtb);
#define ISBUSY_MSG      0x01
#define ISBUSY_SET      0x02
#define ISBUSY_AVAIL    0x04                                       //~v8@rR~

int cmdopdchk(int Popt,int *Ppopdno,char ***Pppopd,int Pminparm);
#define OPDCHK_NEW      0x01
#define OPDCHK_NOTBUSY  0x02
#define OPDCHK_AVAIL    0x04         //chk thread active           //~v8@rI~
int cmdopdchksetmissing(int *Ppopdno,char ***Pppopd);

int initthread(PTHREADTB Ppthtb);
int initchild(PTHREADTB Ppthtb);
ULONG initconsole(void);
int apierr(char *Papiname,char *Pparm,int Prcid);                  //~v715I~
int cmdctl(char *Pcmd);
int parmchk(int argc,char **argp);
void mainhelp(void);
char *getstdin(char *Pbuff,int Pbuffsz,int *Pplen);
int settimeoutrespdata(PTHREADTB Ppthtb);                          //~v72BI~
UTHFUNC threadfunc3270,threadfuncstdincmd,threadfuncmonitor;
int parseusername(char *Puserpswd,char *Puser);
int deltempfile(char *Pfilename);
void titlemsg(void);                                               //~vafvI~
//***************************************************************************************
#define PIPESIZE   4096
int initpipe(void);
int connectwait(int *Ppidx);
int msgread(PCLIENTTB Ppcltb,char *Pbuff,int Pbuffsz,int *Pplen);
int msgwrite(PCLIENTTB Ppcltb,char *Pbuff,int Pbufflen,char *Pdata,int Pdatalen);//~v716I~
int respmsgwrite(PCLIENTTB Ppcltb,int rc,PTHREADTB Ppthtb);        //~v716R~
//ULONG pipecreate(void);                                          //~vafkR~
ULPTR pipecreate(void);                                            //~vafkI~
#ifdef W32                                                         //~v715R~
int pipeconnect(PCLIENTTB Ppcltb);
#endif                                                             //~v715R~
//int piperead(ULONG Phpipe,char *Pbuff,int Pbuffsz,int *Pplen);   //~vafkR~
int piperead(ULPTR Phpipe,char *Pbuff,int Pbuffsz,int *Pplen);     //~vafkI~
//int pipewrite(ULONG Phpipe,char *Pbuff,int Plen);                //~vafkR~
int pipewrite(ULPTR Phpipe,char *Pbuff,int Plen);                  //~vafkI~
//int pipeclose(ULONG Phpipe);                                     //~vafkR~
int pipeclose(ULPTR Phpipe);                                       //~vafkI~
int connectwait(int *Ppidx);
int pipereconnect(int Precorrectsw,PCLIENTTB pcltb);
#ifdef LNX                                                         //~v715R~
	int sigblockchild(void);                                       //~v715I~
	PCLIENTTB alloccltb(void);                                     //~v715R~
	int freecltb(PCLIENTTB);                                       //~v715R~
	int pipeconnect2client(PCLIENTTB pcltb);                       //~v715R~
	int notify2main(char *Pcmd);                                   //~v715I~
#endif                                                             //~v715R~
#ifdef LNX                                                         //~v715I~
	pthread_t getcurrenttid();                                     //~v715R~
#else                                                              //~v715R~
	ULONG getcurrenttid();                                         //~v715R~
#endif                                                             //~v715I~

//*************************************************************
//*parm1:option
//*parm2:read pipe fd number
//*parm3:write pipe fd number
//return:write to pipe: at init:pid,at req:rc+errmsg
//*************************************************************
int main(int parmc,char * parmp[])
{
	PCLIENTTB pcltb;
	PTHREADTB pthtb;                                               //~v716I~
    char buff[MAX_CMDSZ];                                          //~v715R~
    char buff2[MAX_CMDSZ];                                         //~v715R~
    char *pc;
    int len,rc,idx,quitsw=0;
    int opt=0;                                                     //~v8@NI~
    int wciopt;                                                    //~v79zI~
#ifdef W32                                                         //~v72xI~
    int rc2;                                                       //~v72sI~
#endif                                                             //~v72xI~
//**********************
    utrace_init(0/*tracefilename*/,0/*notrace*/);                  //~vafxI~
    Gucvebc_stat|=UCVEBCS_3270FTP;	        //on xe3270 process;default map is from s3270 ftp//~vaa9I~
#ifdef UTF8SUPP                                                    //~v79zI~
    wciopt=UDCWCIO_UTF8VERSION;                                    //~v79zI~
#else                                                              //~v79zI~
    wciopt=0;                                                      //~v79zR~
#endif                                                             //~v79zI~
    udbcschk_wcinit(wciopt,0/*output default locale of linux*/); //utf8 version//~v79zR~
#ifdef LNX                                                         //~v715I~
//    printf("setsid rc=%x,err=%d\n",setsid(),errno);              //~v715R~
//  utf_init(0);  	//chk lang is UTF8 for set default locale code at mapinit==>wcinit will set default locale//~v79zR~
    if (udbcschkcp())	//DBCS mode                                //~v8@zI~
    {                                                              //~v8@zI~
    	if (Gudbcschk_flag & UDBCSCHK_EUC)                         //~v8@zI~
        	G3270opt|=G3270OPT_EUC;     //locale is euc code       //~v8@zR~
    	G3270opt|=G3270OPT_DBCSJP;                                 //~v79aR~
    }                                                              //~v8@zI~
#else                                                              //~v79aI~
    if (udbcschkcp())	//DBCS mode                                //~v79aI~
    	G3270opt|=G3270OPT_DBCSJP;                                 //~v79aR~
#endif                                                             //~v715I~
	else                                                           //~v79aI~
//  	if (!Gudbcschk_flag & UDBCSCHK_UTF8)	//except utf8      //~v79zR~
        {                                                          //~v79aI~
//  		udbcschk_wcinit(UDCWCIO_WCDBCSCHK);   //dbcschk for other than japanese//~v79zR~
//          if (Gudbcschk_flag & UDBCSCHK_WCDBCS)                  //~v79zR~
			if (UDBCSCHK_ISWCDBCS())                               //~v79zI~
    			G3270opt|=G3270OPT_DBCSOTHER;                      //~v79aR~
        }                                                          //~v79aI~
//  ualloc_init(UALLOC_TRACE2,"xe3270.mtr");                       //~v719R~
//  ucriticalsection(CRITSEC_INIT,(ULONG)(&Ssemstdout));           //~vafkR~
    ucriticalsection(CRITSEC_INIT,(ULPTR)(&Ssemstdout));           //~vafkI~
//  ucriticalsection(CRITSEC_INIT,(ULONG)(&Ssemthread));           //~vafkR~
    ucriticalsection(CRITSEC_INIT,(ULPTR)(&Ssemthread));           //~vafkI~
//  uerrmsg_init(0,stdout,UERR_TIMESTAMP);//msg to stdout          //~v8@NR~
	opt=UERR_SETSIZEPOWER(3)|UERR_TIMESTAMP;   //2**3*4k=32K errmsg buff sz//~v8@NR~
    uerrmsg_init(0/*title*/,stdout,opt);//msg to stdout            //~v8@NR~
    Spid=ugetpid();     //parm to callback func                    //~v715R~
    uerrmsgmt(1,"%s:started pid=%d(x%08x)",0,
				PGM,Spid,Spid);
    if (parmchk(parmc,parmp))
        return 4;
//  Smainopt|=XE3270OPT_PUTCONFIRM;      //bug investigation       //~v725R~
//  Smainopt|=XE3270OPT_GETCONFIRM;      //bug investigation       //~v725R~
#ifdef TRACE                                                       //~v71SI~
    Sotheropt|=OTHEROPT_TRACE;           //bug investigation       //~v71SI~
#endif                                                             //~v71SI~
    if (Smainopt & XE3270OPT_TRACE)
    {
//  	utrace_initmt(&Ssemstdout);	//share semaphore              //~v766R~
//    	utrace_init("xe3270.trc",UTRACEO_IGNOREOPENERR);           //~v766R~
      	utrace_init("xe3270.trc",UTRACEO_IGNOREOPENERR|UTRACEO_MT);//~v766I~
		printf("trace on pwd=%s\n",ugetcwd(buff));                 //~v71ER~
    }
UTRACEP("curpid=%x,opt=%x\n",Spid,Smainopt);
UTRACEP("gudbcschk_flag=%x\n",Gudbcschk_flag);                     //~v8@zI~
    if (readconf())                                                //~v725M~
        return 4;                                                  //~v725M~
    if (initmain())
    {
    	uerrmsgmt(1,"%s initialize failed",0,PGM);
        exit(99);
    }
    usleepms(100); //wait cmdthread help                           //~v715R~
//    if (independentsw)  //no pipe parameter
//    {
//        uevent(UEVENTO_WAIT,1,&(Sthtbcmd.THThthread),-1,0); //infinite waite,no index output
//    }
//    else
//    {
//        sprintf(buff,"%x",Spid);
//        len=write(fdw,buff,strlen(buff)+1);//tell pid to wxe,write last null
//UTRACEP("main 1st write len=%d\n",len);
//        if (len==-1)
//        {
//            uerrmsgmt(1,"pid write failed,rc=%d",0,
//                    errno);
//            return 8;
//        }
//        if (!Spid)
//            return 8;
        for (*buff2=0;;)
        {
//            if (*buff2)            //for test(when used redirect file input)
//            {
//                strcpy(buff,buff2);
//                len=strlen(buff);
//            }
//            else
//            {
//                len=read(fdr,buff,sizeof(buff));
//            }
			pcltb=Scltb;                                           //~v715I~
        	uerrmsgmt(0,"\n==>",0);
            rc=connectwait(&idx);
UTRACEP("mainconnect rc=%d,idx=%d\n",rc,idx);
			if (rc)
              	break;
#ifdef LNX                                                         //~v715R~
            pcltb=alloccltb();                                     //~v715R~
#else                                                              //~v715R~
            pcltb=Scltb+idx;
#endif                                                             //~v715R~
            rc=msgread(pcltb,buff,sizeof(buff),&len);
            if (rc<0)                                              //~v715R~
            	break;                                             //~v715R~
UTRACEP("msg get rc=%d,len=%d\n",rc,len);
            if (rc)      	//pipe reconnected
                continue;
            *(buff+len)=0;
UTRACED("mainread",buff,len);
            if (pc=strchr(buff,'\n'),pc)    //redirect file used for test
            {
                *pc=0;
                strcpy(buff2,pc+1);
//              len=strlen(buff);                                  //~vazxR~
                len=(int)strlen(buff);                             //~vazxI~
            }
            uerrmsgmt(1,"\n%d:Input:%s",0,
                        pcltb->CLTseqno,buff);
            if ((quitsw=!stricmp(buff,"quit")))
                break;
            if (Smainopt & XE3270OPT_TESTERRRESP)
            {
              	uerrmsgmt(1,"test mode responce",0);
              	rc=4;
	            if (Smainopt & XE3270OPT_TESTNOTFOUND)
                	rc=U3CR_RC_NOTFOUND;                           //~v716R~
                pthtb=NULL;                                        //~vafdI~
            }
            else
            	rc=callsysincmd(buff,&pthtb);                      //~v716R~
#ifdef LNX                                                         //~v715I~
          if (pcltb->CLTpid>0)	//not internal msg                 //~v715R~
          {                                                        //~v715I~
#endif                                                             //~v715I~
//          write(fdw,retdata,len);
            rc=respmsgwrite(pcltb,rc,pthtb);                       //~v716R~
//  		if (rc)         //continue even if pipe write faied    //~v715R~
//          	break;                                             //~v715R~
#ifdef LNX                                                         //~v715I~
          }//not internam notify                                   //~v715I~
			freecltb(pcltb);                                       //~v715R~
#endif                                                             //~v715M~
#ifdef W32                                                         //~v715I~
		  rc2=                                                     //~v72sI~
			pipereconnect(1,pcltb);
          if (rc2)                                                 //~v72sI~
            break;                                                 //~v72sI~
#endif                                                             //~v715R~
        }//msg loop
//    }
    endmain();
    uerrmsgmt(1,"%s:exit",0,
				PGM);
    if (quitsw)
    {
        uerrmsgmt(0,"0:%s terminated\n",0,                         //~v715R~
        			PGM);
#ifdef LNX                                                         //~v715I~
      if (pcltb->CLTpid>0)	//not internal msg                     //~v715I~
      {                                                            //~v715I~
#endif                                                             //~v715I~
		respmsgwrite(pcltb,0,0);	//rc=0,pthtb=0                 //~v716R~
#ifdef LNX                                                         //~v715I~
      }                                                            //~v715I~
#endif                                                             //~v715I~
		pipereconnect(0,pcltb);	//0:no reconnect
    }
#ifdef LNX                                                         //~v715I~
    deltempfile(XE3270PIPE);                                       //~v715R~
    deltempfile(Spipenamealibi);                                   //~v715I~
#endif                                                             //~v715I~
//  ucriticalsection(CRITSEC_DELETE,(ULONG)(&Ssemstdout));         //~vafkR~
    ucriticalsection(CRITSEC_DELETE,(ULPTR)(&Ssemstdout));         //~vafkI~
//  ucriticalsection(CRITSEC_DELETE,(ULONG)(&Ssemthread));         //~vafkR~
    ucriticalsection(CRITSEC_DELETE,(ULPTR)(&Ssemthread));         //~vafkI~
    titlemsg();                                                    //~vafvI~
	return 0;
}//main
//**************************************************************** //~v716I~
//responce write,close pipe server                                 //~v716I~
//**************************************************************** //~v716I~
int respmsgwrite(PCLIENTTB Ppcltb,int Prc,PTHREADTB Ppthtb)        //~v716R~
{                                                                  //~v716I~
    int datalen,msglen,resplen,rc;                                 //~v716R~
    char *pdata,*pmsg;                                             //~v716R~
    PPIPERESPMSG presp;                                            //~v716I~
//***************************************                          //~v716I~
 	pmsg=ugeterrmsg();                                             //~v716I~
    if (pmsg)                                                      //~v716R~
    {                                                              //~v716I~
//  	msglen=strlen(pmsg);                                       //~v716R~//~vazxR~
    	msglen=(int)strlen(pmsg);                                  //~vazxI~
    	if (Serrmsgmtopt && msglen>13)	//uerrmsgmt hdr len        //~v716I~
        {                                                          //~v716I~
        	pmsg+=13;                                              //~v716I~
            msglen-=13;                                            //~v716I~
        }                                                          //~v716I~
    }                                                              //~v716I~
    else                                                           //~v716I~
    	msglen=0;                                                  //~v716R~
    if (Ppthtb && (pdata=Ppthtb->THTrespdata))                     //~v716R~
    {                                                              //~v716I~
    	datalen=Ppthtb->THTrespdatalen;                            //~v716I~
		Ppthtb->THTrespdata=0;                                     //~v716I~
    }                                                              //~v716I~
    else                                                           //~v716I~
    {                                                              //~v716I~
    	pdata=0;                                                   //~v716I~
    	datalen=0;                                                 //~v716I~
    }                                                              //~v716I~
  if (msglen)                                                      //~v72BI~
    msglen++;	//last null                                        //~v719I~
//  resplen=msglen+PIPERESPMSGHDRSZ;                               //~v719R~//~vazxR~
    resplen=msglen+(int)PIPERESPMSGHDRSZ;                          //~vazxI~
//  presp=(PPIPERESPMSG)umalloc(resplen);                          //~v719R~//~vazxR~
    presp=(PPIPERESPMSG)umalloc((size_t)resplen);                  //~vazxI~
    presp->rc=Prc;                                                 //~v716I~
    presp->msglen=msglen;	//errmsg                               //~v716I~
    presp->datalen=datalen;	//errmsg                               //~v716I~
  if (msglen)                                                      //~v72BI~
//  memcpy(presp->respmsg,pmsg,msglen);                            //~v719R~//~vazxR~
    memcpy(presp->respmsg,pmsg,(size_t)msglen);                    //~vazxI~
UTRACED("respmsg",presp,resplen);                                  //~v716R~
UTRACED("respdata",pdata,datalen);                                 //~v716I~
//	rc=msgwrite(Ppcltb,(char*)(ULONG)presp,resplen,pdata,datalen); //~v716R~//~vafkR~
	rc=msgwrite(Ppcltb,(char*)(ULPTR)presp,resplen,pdata,datalen); //~vafkI~
    ufree(presp);                                                  //~v719M~
    if (pdata)                                                     //~v716I~
        ufree(pdata);                                              //~v719R~
	return rc;                                                     //~v716I~
}//respmsgwrite                                                    //~v716I~
//****************************************************************
//*execute ftp
//****************************************************************
int parmchk(int argc,char **argp)
{
    int ii,posparmno=0;
    char *pc,**popd;
    char *pwd=0;                                                   //~v725I~
//********************
    if (argc==1)
    {
        mainhelp();
        exit(0);
    }
    for (ii=1,popd=argp+1;ii<argc;ii++,popd++)
    {
        pc=*popd;
//      printf("parm %d=%s\n",ii,pc);                              //~v725R~
        if (*pc=='-'||*pc=='/') //option
        {
            pc++;
            switch(toupper(*pc))
            {
            case '?':
                mainhelp();
                exit(0);
                break;
            case 'C':   //timeout_connect
                if (atoi(pc+1))
                {                                                  //~v72iI~
//  				Stimeout_connect=atoi(pc+1);                   //~v72iR~
    				G3270to_connect=atoi(pc+1);                    //~v72iR~
    				G3270opt|=G3270OPT_CMDLINEC;                   //~v72iI~
                }                                                  //~v72iI~
                break;
            case 'F':   //s3270 trace                              //~v71SI~
                Sotheropt|=OTHEROPT_TRACE;                         //~v71SI~
                break;                                             //~v71SI~
            case 'L':   //logfilename
				Slogfnm=pc+1;
                break;
            case 'T':   //timeout_transfer                         //~v725M~
                if (atoi(pc+1))                                    //~v725M~
                {                                                  //~v72iI~
//  				Stimeout_transfer=atoi(pc+1);                  //~v72iR~
    				G3270to_ftp=atoi(pc+1);                        //~v72iI~
    				G3270opt|=G3270OPT_CMDLINET;                   //~v72iI~
                }                                                  //~v72iI~
                break;                                             //~v725M~
            case 'W':   //workdir                                  //~v725I~
				pwd=pc+1;                                          //~v725I~
                break;                                             //~v725I~
            case 'N':   //list
                if (*(pc+1)=='9')
				    uerrmsg_init(0,stdout,UERR_FORCE_ENGLISH|UERR_TIMESTAMP);
                break;
            case 'Y':   //list
                break;
            default:
            	uerrexit("option parm err(%s)",0,
                			*popd);
            }
        }
        else
        {
            if (posparmno==0)
                Smainopt=atoi(pc);
            else
            {
	            uerrmsgmt(1,"%s,too many positional parameter",0,
                        pc);
     	       return 4;
            }
            posparmno++;
UTRACEP("posparm=%d=%s\n",posparmno,pc);
        }
    }
    if (pwd)                                                       //~v725I~
    	ufullpath(G3270workdir,pwd,sizeof(G3270workdir));          //~v725R~
    if (*G3270workdir)                                             //~v8@5I~
	    sprintf(G3270ftperrlogfile,"%s%c%s",G3270workdir,DIR_SEPC,XE3270_FTPRETRY_LOGFILE);//~v8@5R~
    else                                                           //~v8@5I~
	    sprintf(G3270ftperrlogfile,"%s",XE3270_FTPRETRY_LOGFILE);  //~v8@5R~
    return 0;
}//parmchk
//****************************************************************
//*execute ftp
//****************************************************************
void mainhelp(void)
{
	uerrmsg("v%s:xe's 3270 interface",0,
    			VER);
//	printf(uerrsprintf("Usage: %s flag [-options] \n",0,           //~vb3AR~
  	printf("%s",uerrsprintf("Usage: %s flag [-options] \n",0,      //~vb3AI~
					PGM));
//  printf(uerrsprintf("     flags  : flags by decimal number. mix of below\n",0));//~vb3AR~
    printf("%s",uerrsprintf("     flags  : flags by decimal number. mix of below\n",0));//~vb3AI~
//  printf(uerrsprintf("             0x01: write logfile.\n",0));  //~vb3AR~
    printf("%s",uerrsprintf("             0x01: write logfile.\n",0));//~vb3AI~
//  printf(uerrsprintf("             0x02: write logfile by append mode.\n",0));//~vb3AR~
    printf("%s",uerrsprintf("             0x02: write logfile by append mode.\n",0));//~vb3AI~
#ifdef LNX                                                         //~v715I~
//  printf(uerrsprintf("             0x04: force delete if pipe exist at start.\n",0));//~vb3AR~
    printf("%s",uerrsprintf("             0x04: force delete if pipe exist at start.\n",0));//~vb3AI~
#endif                                                             //~v715I~
//  printf(uerrsprintf("             \"0\" required even if no options.\n",0));//~vb3AR~
    printf("%s",uerrsprintf("             \"0\" required even if no options.\n",0));//~vb3AI~
//  printf(uerrsprintf("     options: flags by decimal number. mix of below\n",0));//~vb3AR~
    printf("%s",uerrsprintf("     options: flags by decimal number. mix of below\n",0));//~vb3AI~
//  printf(uerrsprintf("         -C : Connect timeout(default:%d seconds)\n",0,//~vb3AR~
    printf("%s",uerrsprintf("         -C : Connect timeout(default:%d seconds)\n",0,//~vb3AI~
							TIMEOUT_CONNECT));
//  printf(uerrsprintf("         -F : use 3270 -trace option\n",0));//~vb3AR~
    printf("%s",uerrsprintf("         -F : use 3270 -trace option\n",0));//~vb3AI~
#ifdef LNX                                                         //~v71SI~
//  printf(uerrsprintf("              tracefile is written to /tmp/x3trc.nnnn\n",0));//~vb3AR~
    printf("%s",uerrsprintf("              tracefile is written to /tmp/x3trc.nnnn\n",0));//~vb3AI~
#else                                                              //~v71SI~
	printf(uerrsprintf("              tracefile is written to %%%%CYGWIN%%%%\\tmp\\x3trc.nnnn\n",0));//~v71SR~
#endif                                                             //~v71SI~
//  printf(uerrsprintf("         -L : logfile name.(default:%s)\n",0,//~vb3AR~
    printf("%s",uerrsprintf("         -L : logfile name.(default:%s)\n",0,//~vb3AI~
							XE3270_DEFAULT_LOGFILE));
//  printf(uerrsprintf("         -T : Send/Receive timeout(default:%d seconds)\n",0,//~vb3AR~
    printf("%s",uerrsprintf("         -T : Send/Receive timeout(default:%d seconds)\n",0,//~vb3AI~
							TIMEOUT_TRANSFER));
//  printf(uerrsprintf("         -W : Work dir. %s is searched in this dir.\n",0,//~vb3AR~
    printf("%s",uerrsprintf("         -W : Work dir. %s is searched in this dir.\n",0,//~vb3AI~
							CONFXE3270));                          //~v725I~
//  printf(uerrsprintf("              You can specify cfg file itself by this option.\n",0));//~vb3AR~
    printf("%s",uerrsprintf("              You can specify cfg file itself by this option.\n",0));//~vb3AI~
    titlemsg();                                                    //~vafvI~
    return;
}//mainhelp
//****************************************************************
//*execute ftp
//****************************************************************
int initmain(void)
{
	PTHREADTB pthtb;
//  ULONG ecblist[2],thid;                                         //~vafkR~
    ULPTR ecblist[2],thid;                                         //~vafkI~
    int ii;
//*******************
	for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)
    {
    	pthtb->THTseqid=ii+1;	//internal threadid
		if (uevent(UEVENTO_INIT,2,ecblist,0,0))				//init ecblist
    		return 4;
	    pthtb->THTecbm2s=ecblist[0];
	    pthtb->THTecbs2m=ecblist[1];
#ifdef LNX                                                         //~v715I~
		if (uevent(UEVENTO_INIT|UEVENTO_MANUALRESET,1,ecblist,0,0))				//init ecblist//~v716I~
    		return 4;                                              //~v716I~
	    pthtb->THTecbkill=ecblist[0];	//kill timeout chk         //~v716R~
#endif                                                             //~v715I~
    }
//thread for read stdin of myself
	pthtb=&Sthtbcmd;
	if (uevent(UEVENTO_INIT,2,ecblist,0,0))				//init ecblist
    	return 4;
    pthtb->THTecbm2s=ecblist[0];
    pthtb->THTecbs2m=ecblist[1];
#ifdef LNX                                                         //~v715I~
	if (uevent(UEVENTO_INIT|UEVENTO_MANUALRESET,1,ecblist,0,0))				//init ecblist//~v716I~
    	return 4;                                                  //~v716I~
	pthtb->THTecbkill=ecblist[0];	//kill timeout chk             //~v716R~
#endif                                                             //~v715I~
LOCK_ENTER();
    thid=uthread(0,       //oot
				threadfuncstdincmd,   //thread func
				0,        //stacksz
//				(ULONG)pthtb,   //func parm                        //~vafkR~
				(ULPTR)pthtb,   //func parm                        //~vafkI~
				0);			//output threadid
LOCK_LEAVE();
    if (!thid)
        return 4;
    pthtb->THThthread=thid;	//thread handle
//  Stidcmd=thid;                                                  //~v72hR~
UTRACEP("cmd tid by uthread=%x\n",thid);
//thread for process,thread termination monitor
	pthtb=&Sthtbmonitor;
#ifdef W32                                                         //~v715I~
	if (uevent(UEVENTO_INIT,2,ecblist,0,0))				//init ecblist
    	return 4;
    pthtb->THTecbm2s=ecblist[0];
    pthtb->THTecbs2m=ecblist[1];
#endif                                                             //~v715I~
LOCK_ENTER();
    thid=uthread(0,       //oot
				threadfuncmonitor,   //thread func
				0,        //stacksz
//				(ULONG)pthtb,   //func parm                        //~vafkR~
				(ULPTR)pthtb,   //func parm                        //~vafkI~
				0);			//output threadid
LOCK_LEAVE();
    if (!thid)
        return 4;
UTRACEP("monitor tid by uthread=%x\n",thid);
    pthtb->THThthread=thid;	//thread handle
    if (initpipe())
    	return 4;
#ifdef LNX                                                         //~v715I~
	if (sigblockchild())                                           //~v715R~
    	return 4;                                                  //~v715I~
#endif                                                             //~v715I~
    return 0;
}//initmain
//****************************************************************
//*execute ftp
//****************************************************************
int endmain(void)
{
	PTHREADTB pthtb;
    int ii;
//*******************
UTRACEP("endmain\n");                                              //~v8@eI~
    uerrmsgmt(0,"xe3270 termination scheduled\n",0);               //~v8@eR~
	for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)
    {
		if (pthtb->THThthread && !pthtb->THTexitcode)
        {                                                          //~v8@eI~
          if (!(pthtb->THTflag & THTF_CLOSE))                      //~v8@eR~
			callend3270(pthtb);
        }                                                          //~v8@eR~
    }
	for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)
    {
		if (pthtb->THThthread && !pthtb->THTexitcode)
            killchild(pthtb);
    }
    return 0;
}//endmain                                                         //~v715R~
//****************************************************************
//*sub thread main
//****************************************************************
#ifdef LNX                                                         //~v715R~
void *threadfunc3270(void *Pparm)                                  //~v715R~
#else                                                              //~v715R~
void threadfunc3270(void *Pparm)
#endif                                                             //~v715R~
{
//  ULONG ecblist[1];                                              //~vafkR~
    ULPTR ecblist[1];                                              //~vafkI~
	PTHREADTB pthtb;
    int rc,endthreadsw=0;
//************************
#ifdef LNX                                                         //~v715I~
  	if (sigblockchild())                                           //~v715R~
    {                                                              //~va32I~
		pthtb=(PTHREADTB)(ULONG)Pparm;                             //~va32I~
  		exitthread(pthtb,THTEC_ERR);                               //~v715R~
    }                                                              //~va32I~
#endif                                                             //~v715I~
//	pthtb=(PTHREADTB)(ULONG)Pparm;                                 //~vafkR~
	pthtb=(PTHREADTB)(ULPTR)Pparm;                                 //~vafkI~
    for (;;)
    {
	    ecblist[0]=pthtb->THTecbm2s;
#ifdef LNX                                                         //~v715I~
UTRACED("thread wait",pthtb->THTecbm2s,UEVENTCBSZ);                //~v715I~
#endif                                                             //~v715I~
    	rc=uevent(UEVENTO_WAIT,1,ecblist,-1,0);    //-1:infinite wait
    	if (rc)
        {
        	postbackmain(pthtb,THTRC_SUBEXIT);
    		break;
        }
UTRACEP("subthread reqcode=%d,tblid=%d\n",pthtb->THTreqcode,pthtb->THTseqid);
        switch(pthtb->THTreqcode)
        {
    	case THTRQ_INITCHILD:
        	rc=funcstart3270(pthtb);
            break;
    	case THTRQ_CONNECT:
        	rc=funcconnect(pthtb);
            break;
    	case THTRQ_LOGON:
        	rc=funclogon(pthtb);
            break;
    	case THTRQ_TRANSFER_GET:
    	case THTRQ_TRANSFER_PUT:
        	rc=funcftp(pthtb);
            break;
    	case THTRQ_TSOCMD_LISTDS:                                  //~v716I~
        	rc=funclistds(pthtb);                                  //~v716I~
            break;                                                 //~v716I~
    	case THTRQ_TSOCMD_RENAME:                                  //~v71eI~
        	rc=funcrename(pthtb);                                  //~v71eI~
            break;                                                 //~v71eI~
    	case THTRQ_TSOCMD_DELETE:                                  //~v71eI~
        	rc=funcdelete(pthtb);                                  //~v71eI~
            break;                                                 //~v71eI~
    	case THTRQ_TSOCMD_ALLOCATE:                                //~v71nI~
        	rc=funcalloc(pthtb);                                   //~v71nI~
            break;                                                 //~v71nI~
    	case THTRQ_TSOCMD_FREE:                                    //~v71nI~
        	rc=funcfree(pthtb);                                    //~v71nI~
            break;                                                 //~v71nI~
    	case THTRQ_TSOCMD_SPF:                                     //~v72nI~
        	rc=funcspf(pthtb);                                     //~v72nI~
            break;                                                 //~v72nI~
    	case THTRQ_TSOCMD_TSO:                                     //~v8@BI~
        	rc=functsocmd(pthtb);                                  //~v8@BI~
            break;                                                 //~v8@BI~
    	case THTRQ_TSOCMD_QUERY:                                   //~v8@BI~
    		rc=funcquery(pthtb);                                   //~v8@BI~
            break;                                                 //~v8@BI~
    	case THTRQ_SNAP:
			rc=funcsnap(SENDO_SNAPPRINT,pthtb);
            break;
    	case THTRQ_CMD:
			rc=funccmd(pthtb);
            break;
    	case THTRQ_STRING:
			rc=funcstring(pthtb);
            break;
    	case THTRQ_RSH:                                            //~v72BM~
			rc=funcrsh(pthtb);                                     //~v72BI~
            break;                                                 //~v72BI~
    	case THTRQ_LOGOFF:
        	rc=funclogoff(pthtb);
            break;
    	case THTRQ_DISCONNECT:
        	rc=funcend3270(pthtb);
            if (!rc)	//succcess	,else wait end thread
	            endthreadsw=1;
            break;
    	case THTRQ_ENDTHREAD:
            endthreadsw=1;
            break;
        default:
            uerrmsgmt(1,"invalid req code(%d)",0,
						pthtb->THTreqcode);
            rc=4;
        }
//      if (rc)
//          rc=THTRC_SUBERR;
        postbackmain(pthtb,rc);
        if (endthreadsw)
        	break;
    }
    close3270(pthtb);
	exitthread(pthtb,THTEC_NORMAL);
#ifdef LNX                                                         //~v715R~
    return 0;                                                      //~v715R~
#else                                                              //~v715R~
    return;
#endif                                                             //~v715R~
}//threadfunc3270
//****************************************************************
//*sub thread main
//****************************************************************
#ifdef LNX                                                         //~v715R~
void *threadfuncstdincmd(void *Pparm)                              //~v715R~
#else                                                              //~v715R~
void threadfuncstdincmd(void *Pparm)
#endif                                                             //~v715R~
{
    char buff[MAX_RESPSZ],*pc;                                     //~v715R~
	PTHREADTB pthtb,pthtbcmd;                                      //~v716R~
    int /*rc,*/len;                                                //~vaa7R~
//************************
#ifdef LNX                                                         //~v715R~
	if (sigblockchild())                                           //~v715I~
    {                                                              //~va32I~
		pthtb=(PTHREADTB)(ULONG)Pparm;                             //~va32I~
		exitthread(pthtb,THTEC_ERR);                               //~v715I~
    }                                                              //~va32I~
#endif                                                             //~v715M~
//  Stidcmd=GetCurrentThreadId();                                  //~v715R~
    Stidcmd=getcurrenttid();                                       //~v72hR~
UTRACEP("cmd start\n");                                            //~v715R~
//	pthtb=(PTHREADTB)(ULONG)Pparm;                                 //~vafkR~
	pthtb=(PTHREADTB)(ULPTR)Pparm;                                 //~vafkI~
	sysincmdhelp(0,0,0);                                           //~v716R~
    for (;;)
    {
        uerrmsgmt(0,"==>",0);
//      pc=fgets(buff,sizeof(buff),stdin);	//EOF fgets return last \n
        pc=getstdin(buff,sizeof(buff),&len);
        if (!pc)
            break;
        if (!len)
        	continue;
        uerrmsgmt(1,"stdin cmd input:%s",0,
                    buff);
        /*rc=*/callsysincmd(buff,&pthtbcmd);		//operation ctl    //~v716R~//~vaa7R~
        if (pthtbcmd && pthtbcmd->THTrespdata)                     //~v716I~
        {                                                          //~v716I~
        	ufree(pthtbcmd->THTrespdata);                          //~v719R~
        	pthtbcmd->THTrespdata=0;                               //~v716I~
        }                                                          //~v716I~
    }
	exitthread(pthtb,THTEC_NORMAL);
#ifdef LNX                                                         //~v715R~
    return 0;                                                      //~v715R~
#else                                                              //~v715R~
    return;
#endif                                                             //~v715R~
}//threadfuncstdincmd
//****************************************************************
//*chk current thread is stdincmd thread
//****************************************************************
int iscmdthread()
{
#ifdef LNX                                                         //~v715R~
    return pthread_equal(Stidcmd,getcurrenttid());                 //~v715R~
#else                                                              //~v715R~
//  return Stidcmd && Stidcmd==GetCurrentThreadId();               //~v715R~
    return Stidcmd && Stidcmd==getcurrenttid();                    //~v715I~
#endif                                                             //~v715R~
}//iscmdthread
//**************************************************************** //~v715I~
//*chk current thread is stdincmd thread                           //~v715I~
//**************************************************************** //~v715I~
#ifdef LNX                                                         //~v715I~
pthread_t getcurrenttid()                                          //~v715I~
#else                                                              //~v715R~
ULONG getcurrenttid()                                              //~v715I~
#endif                                                             //~v715I~
{                                                                  //~v715I~
#ifdef LNX                                                         //~v715I~
    return pthread_self();                                         //~v715I~
#else                                                              //~v715I~
    return (ULONG)GetCurrentThreadId();                            //~v715I~
#endif                                                             //~v715I~
}//getcurrenttid                                                   //~v715I~
//****************************************************************
//*read stdin
//*(W32)fgets locks stdin until post,it protect other thread flush(stdin) which needed when spawn//~v715R~
//****************************************************************
char *getstdin(char *Pbuff,int Pbuffsz,int *Pplen)
{
#ifdef LNX                                                         //~v715R~
	fd_set rfds;                                                   //~v715I~
    int rc;                                                        //~v715I~
#endif                                                             //~v715I~
//  char *pc,*pce;
#define KBDPEEK_TIME1  500     //milisec
#define KBDPEEK_TIME2  100     //milisec
	int waittime,len;
//*********************************
	waittime=KBDPEEK_TIME1;
#ifdef AAA
// this logic force to user to process Backspace etc
	for (pc=Pbuff,pce=pc+Pbuffsz-1;;)
    {
		if (!_kbhit())
    	{
        	Sleep(waittime);
            continue;
        }
		waittime=KBDPEEK_TIME2;
		for (;pc<pce && _kbhit();pc++)
        {
			*pc=_getche();
        }
        if (*(pc-1)=='\r')      //enter
            break;
    }
#endif
#ifdef LNX                                                         //~v715R~
	for (;;)                                                       //~v715I~
    {                                                              //~v715I~
        FD_ZERO(&rfds);                                            //~v715I~
//      FD_SET(0,&rfds);                //stdin                    //~v715I~//~vb34R~
        UFD_SET(0,&rfds);                //stdin                   //~vb34I~
        rc=select(1,                    //maxfd+1                  //~v715I~
                    &rfds,              //read fd                  //~v715I~
                    NULL,               //write fd                 //~v715I~
                    NULL,               //exception fd             //~v715I~
                    NULL);              //timeout:infinite         //~v715I~
        if (rc>0)	//count of fd                                  //~v715I~
        	break;                                                 //~v715I~
        if (rc==-1)                                                //~v715I~
            apierr("select stdin for cmd",0,0);                    //~v715R~
UTRACEP("getstdin sleep\n");                                       //~v716I~
        usleepms(waittime);                                        //~v715I~
    }                                                              //~v715I~
#else                                                              //~v715I~
	for (;!kbhit();)
        usleepms(waittime);                                        //~v715R~
#endif                                                             //~v715I~
    fgets(Pbuff,Pbuffsz,stdin);
    fflush(stdin);
//  len=strlen(Pbuff);                                             //~vazxR~
    len=(int)strlen(Pbuff);                                        //~vazxI~
    *Pplen=len;
    return Pbuff;
}//getstdin
#ifdef AAA
//****************************************************************
//*chk current thread is stdincmd thread
//****************************************************************
char *getstdin(char *Pbuff,int Pbuffsz,int *Pplen)
{
	int readlen;
    ULONG hstdin;
//*********************************
//  if (!Shstdin)                  //handle invalidated after spawn
	hstdin=initconsole();
//  rc=uevent(UEVENTO_WAIT,1,&Shstdin,-1,0);    //-1:infinite wait
//  if (rc)                  //always posted
//  	return 0;
	if (!ReadConsole((HANDLE)hstdin,		//advance read ptr
    				Pbuff,          //receive area
    				Pbuffsz,			//request count
                    &readlen,    		//out ctr
					0))				//reserved
    {
		uerrapi1t(1,"ReadConsole","STD_INPUT",-1);
        return 0;
    }
    if (readlen && *(Pbuff+readlen-1)=='\n')
    {
        readlen--;
	    if (readlen && *(Pbuff+readlen-1)=='\r')
	        readlen--;
    }
    *(Pbuff+readlen)=0;
    *Pplen=readlen;
    return Pbuff;
}//getstdin
//****************************************************************
//*stdin init
//****************************************************************
ULONG initconsole(void)
{
	int mode;
    ULONG hstdin;
//*******************
	hstdin=(ULONG)ugetstdhandle(STD_INPUT_HANDLE);
    mode=ENABLE_ECHO_INPUT
        |ENABLE_LINE_INPUT          //posted by enter key
        |ENABLE_PROCESSED_INPUT;	//Ctl+C is processed by system
	usetconsolemode(0,mode);
    return hstdin;
}//initconsole
#endif
#ifdef LNX                                                         //~v715M~
//**************************************************************** //~v715I~
//*monitor thread main (LNX)                                       //~v715I~
//**************************************************************** //~v715I~
void *threadfuncmonitor(void *Pparm)                               //~v715M~
{                                                                  //~v715I~
	PTHREADTB pthtb/*,pthtb0*/;                                        //~v715R~//~vaa7R~
    int ii;                                                        //~v715R~
    pid_t pid;                                                     //~v715I~
    ULONG pecb;                                                    //~v715I~
//************************                                         //~v715I~
//	pthtb0=(PTHREADTB)(ULONG)Pparm;                                //~v715I~//~vaa7R~
    for (;;)                                                       //~v715I~
    {                                                              //~v715I~
 		pid=wait(NULL);                                            //~v715R~
UTRACEP("monitor child pid end pid=%d,errno=%d\n",pid,errno);      //~v715R~
		if (pid<0 && errno==ECHILD)	//ECHILD immediately returned when no child process//~v715I~
        {                                                          //~v715I~
        	usleepms(MONITOR_SLEEP_TIME);                          //~v715I~
            continue;                                              //~v715I~
        }                                                          //~v715I~
        for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)        //~v715R~
        {                                                          //~v715I~
            if (pid==pthtb->THTkillph)//internaly kill requested   //~v715R~
            {                                                      //~v715I~
	            pthtb->THTkillph=0;                                //~v715R~
				if (pthtb->THTflag & THTF_CLOSE)                   //~v715I~
	    	    	uerrmsgmt(1,"!!! %s(%s) 3270 process(pid=%d) shutdown.",0,//~v715I~
//						pthtb->THThostname,pthtb->THTusername,pid);//~v8@3R~
  						THT_HOSTNAME(pthtb),pthtb->THTusername,pid);//~v8@3I~
                else                                               //~v715I~
	    	    	uerrmsgmt(1,"!!! %s(%s) 3270 process(pid=%d) canceled.",0,//~v715R~
//  					pthtb->THThostname,pthtb->THTusername,pid);//~v8@3R~
    					THT_HOSTNAME(pthtb),pthtb->THTusername,pid);//~v8@3I~
				pecb=pthtb->THTecbkill;                            //~v715R~
UTRACEP("POST killed pid=%d,pecb=%p\n",pid,pecb);                  //~v716R~
				uevent(UEVENTO_POST,1,&pecb,0,0);                  //~v715I~
            }                                                      //~v715I~
            else                                                   //~v715I~
            if (pid==pthtb->THTchildph)                            //~v715R~
            {                                                      //~v715I~
	            pthtb->THTchildph=0;                               //~v715R~
				if (!(pthtb->THTflag & THTF_CLOSE))                //~v715I~
                {                                                  //~v8@eI~
	    	    	uerrmsgmt(1,"!!! %s(%s) 3270 process(pid=%d) terminated",0,//~v715R~
//  					pthtb->THThostname,pthtb->THTusername,pid);//~v8@3R~
    					THT_HOSTNAME(pthtb),pthtb->THTusername,pid);//~v8@3I~
				endthread(pthtb);                                  //~v715I~
            	pthtb->THThthread=0;                               //~v715I~
                }                                                  //~v8@eI~
                else                                               //~v8@eI~
                {                                                  //~v8@eI~
					pecb=pthtb->THTecbkill;                        //~v8@eI~
UTRACEP("POST normal close3270 pid=%d,pecb=%p\n",pid,pecb);        //~v8@eI~
					uevent(UEVENTO_POST,1,&pecb,0,0);              //~v8@eI~
                }                                                  //~v8@eI~
            }                                                      //~v715I~
        }                                                          //~v715I~
    }                                                              //~v715I~
	return 0;                                                      //~v715I~
}//threadfuncmonitor                                               //~v715I~
#else                                                              //~v715M~
//****************************************************************
//*monitor thread main(W32)                                        //~v715R~
//****************************************************************
void threadfuncmonitor(void *Pparm)
{
	PTHREADTB pthtb,pthtb0;
    int rc,ecbctr,ii,idx;
//  ULONG ecblist[MAX_THREADTB+MAX_THREADTB+1],*pecb,myecb;        //~vafkR~
    ULPTR ecblist[MAX_THREADTB+MAX_THREADTB+1],*pecb,myecb;        //~vafkI~
//************************
//	pthtb0=(PTHREADTB)(ULONG)Pparm;                                //~vafkR~
	pthtb0=(PTHREADTB)(ULPTR)Pparm;                                //~vafkI~
	ecbctr=MAX_THREADTB+MAX_THREADTB;
    myecb=pthtb0->THTecbm2s;
UTRACEP("mntr myecb=%x\n",myecb);                                  //~v8@eI~
    for(;;)
    {
        for (ii=0,pthtb=Sthtb,pecb=ecblist;ii<MAX_THREADTB;ii++,pthtb++)
        {
            if (pthtb->THTchildph)
            {
                *pecb=pthtb->THTchildph;    //child process handle
UTRACEP("mntr childph=%x,ecblist=%p\n",*pecb,pecb);
            }
            else
                *pecb=myecb;
UTRACEP("mntrii=%d,exitcode=%x,thread=%x,child=%x,ecb=%x=%x\n",ii,pthtb->THTexitcode,pthtb->THThthread,pthtb->THTchildph,pecb,*pecb);//~vafjR~
            pecb++;
    	  if (pthtb->THTexitcode)	//already exitthread scheduled //~v8@eR~
            *pecb=myecb;                                           //~v8@eI~
          else                                                     //~v8@eI~
            if (pthtb->THThthread)          //thread handle
            {
                *pecb=pthtb->THThthread;
UTRACEP("mntr hthread=%x,ecblist=%p\n",*pecb,pecb);
			}
            else
                *pecb=myecb;
UTRACEP("mntrii=%d,ecb=%x=%x\n",ii,pecb,*pecb);                    //~vafjI~
            pecb++;
        }
        *pecb=pthtb0->THTecbm2s;
UTRACED("mntr ecblist before post",ecblist,sizeof(ecblist));       //~vafjR~
        rc=uevent(UEVENTO_WAIT,ecbctr+1,ecblist,TIMEOUT_INFINITE,&idx);
UTRACED("mntr ecblist after post",ecblist,sizeof(ecblist));        //~vafjR~
UTRACEP("mntr rc=%d,idx=%d,ecb=%x\n",rc,idx,ecblist[idx]);
        if (rc!=UEVENTRC_POSTED)
        {
UTRACED("mntr uevent wait",ecblist,(ecbctr+1)*sizeof(ULPTR));      //~vaftR~
        	uerrmsgmt(1,"monitor wait failed rc=%d",0,
						rc);
            break;	//handle may be invalid
        }
        if (ecblist[idx]==myecb)
            continue;       //reset ecblist
        pthtb=Sthtb+idx/2;
        if (idx%2)	//thread posted
        {
            pthtb->THThthread=0;
			if (!(pthtb->THTflag & THTF_CLOSE))
	        	uerrmsgmt(1,"!!! %s(%s) thread terminated",0,
//  					pthtb->THThostname,pthtb->THTusername);    //~v8@3R~
    					THT_HOSTNAME(pthtb),pthtb->THTusername);   //~v8@3I~
        }
        else        //process stop
        {
            pthtb->THTchildph=0;
			if (!(pthtb->THTflag & THTF_CLOSE))
            {                                                      //~v8@eI~
	        	uerrmsgmt(1,"!!! %s(%s) 3270 process terminated",0,
//  					pthtb->THThostname,pthtb->THTusername);    //~v8@3R~
    					THT_HOSTNAME(pthtb),pthtb->THTusername);   //~v8@3I~
			endthread(pthtb);
            pthtb->THThthread=0;
            }                                                      //~v8@eI~
        }
    }
	postbackmain(pthtb0,THTRC_SUBNORMAL);
UTRACEP("mntr thread exit\n");
	exitthread(pthtb0,THTEC_NORMAL);
	return;
}//threadfuncmonitor
//****************************************************************
//*sub thread main
//****************************************************************
int notifymonitor(void)
{
	PTHREADTB pthtb;
//  ULONG ecblist[1];                                              //~vafkR~
    ULPTR ecblist[1];                                              //~vafkI~
//*******************
	pthtb=&Sthtbmonitor;
    ecblist[0]=pthtb->THTecbm2s;
UTRACEP("notify to monitor ebc=%x\n",ecblist[0]);                  //~vafjI~
	if (uevent(UEVENTO_POST,1,ecblist,0,0))			//rase monitor
    	return 4;
	return 0;
}//notifymonitor
#endif                                                             //~v715M~
//****************************************************************
//*execute ftp
//****************************************************************
int startthread(PTHREADTB Ppthtb)
{
//  ULONG thid;                                                    //~vaz7R~
    ULPTR thid;                                                    //~vaz7I~
//*******************
UTRACEP("startthread thid=%x,exitcode=%d\n",Ppthtb->THThthread,Ppthtb->THTexitcode);//~v716R~
    if (Ppthtb->THTexitcode)                                       //~v716I~
		Ppthtb->THThthread=0;                                      //~v716I~
	thid=Ppthtb->THThthread;
	Ppthtb->THTexitcode=0;
    if (!thid)
    {
UTRACEP("beginthread\n");
	    Ppthtb->THTflag=0;		//clear connected,logon,timeout
LOCK_ENTER();
		thid=uthread(0,       //oot
					threadfunc3270,   //thread func
					0,        //stacksz
//					(ULONG)Ppthtb,   //func parm                   //~vafkR~
					(ULPTR)Ppthtb,   //func parm                   //~vafkI~
					0);			//output threadid
LOCK_LEAVE();
    	Ppthtb->THThthread=thid;	//thread handle
UTRACEP("beginthread return tid=%x\n",thid);
#ifdef W32                                                         //~v715I~
        if (thid)
		    notifymonitor();	//register thread handle to be monitored
//        usleepms(1000);        //@@@@test                        //~vafjR~
#endif                                                             //~v715I~
    }
    if (!thid)
        return 4;
    return 0;
}//startthread
//****************************************************************
//*execute ftp
//****************************************************************
int callstart3270(PTHREADTB Ppthtb)
{
	int rc;
//*******************
    if (Ppthtb->THTchildph)
    {
UTRACEP("initchild child already active\n",0);
    	return 0;
    }
UTRACEP("initchild awake\n",0);
    rc=awakethread(Ppthtb,THTRQ_INITCHILD,TIMEOUT_INITCHILD);
    if (rc)                                                        //~v715I~
    {                                                              //~v715I~
		if (rc==THTRC_TIMEOUT)                                     //~v715R~
	         uerrmsgmt(1,"!!! start3270 for '%s'-'%s' Timeout.",0, //~v715R~
//  				Ppthtb->THThostname,Ppthtb->THTusername);      //~v8@3R~
    				THT_HOSTNAME(Ppthtb),Ppthtb->THTusername);     //~v8@3I~
    }                                                              //~v715I~
    return rc;
}//callstart3270
//****************************************************************
//*execute ftp
//*parm: hostname,user,pwd,hf,lf,...
//****************************************************************
int callconnect(PTHREADTB Ppthtb,char **Ppopd)
{
	int rc;
//*******************
UTRACEP("callconnect entered\n",0);
    Ppthtb->THTparm=Ppopd;
//  rc=awakethread(Ppthtb,THTRQ_CONNECT,Stimeout_connect);         //~v72iR~
    rc=awakethread(Ppthtb,THTRQ_CONNECT,G3270to_connect);          //~v72iI~
    if (rc)
    {
		 Ppthtb->THTflag&=~(THTF_CONNECTED|THTF_LOGON);	//connect flag
		 if (rc==THTRC_TIMEOUT)	//cleanup requred
	         uerrmsgmt(1,"!!! connect '%s' Timeout.",0,
					Ppopd[PARM_HOST]);
    }
    else
    {
	  if (!(Ppthtb->THTflag&THTF_CONNECTED))                       //~v8@bI~
      {                                                            //~v8@bI~
		 Ppthtb->THTflag|=THTF_CONNECTED;	//connect flag
		 Ppthtb->THTflag&=~(THTF_LOGON);	//logon required       //~v8@rI~
         uerrmsgmt(1,"connect '%s' successed.",0,
					Ppopd[PARM_HOST]);
                                                                   //~v8@bI~
	  }                                                            //~v8@bI~
    }
UTRACEP("callconnect rc=%d\n",rc);
    return rc;
}//callconnect
//****************************************************************
//*up to logon
//*opd:from hostname
//****************************************************************
int calllogon(PTHREADTB Ppthtb,char **Ppopd)
{
	int rc;
    char user[THTUSERNAMESZ];
//*******************
UTRACEP("calllogon entry\n");                                      //~v716I~
//  if (!(Ppthtb->THTflag2 & THTF2_OPTIONSET))	//1st time         //~v8@DR~
		getcfgparm(0,Ppthtb);                                      //~v8@8I~
    if (startthread(Ppthtb))
    	return 4;
    if (callstart3270(Ppthtb))
    	return 4;
    if (callconnect(Ppthtb,Ppopd))
    	return 4;
//    if ((Ppthtb->THTflag&THTF_LOGON)) //already logon            //~v8@rR~
//    {                                                            //~v8@rR~
//UTRACEP("calllogon entry:already logon\n");                      //~v8@rR~
//        return 0;                                                //~v8@rR~
//    }                                                            //~v8@rR~
    Ppthtb->THTparm=Ppopd;
//  rc=awakethread(Ppthtb,THTRQ_LOGON,TIMEOUT_LOGON);              //~v8@1R~
    rc=awakethread(Ppthtb,THTRQ_LOGON,G3270to_logon);              //~v8@1I~
    parseusername(Ppopd[PARM_USER],user);
    if (!rc)
    {
      if (!(Ppthtb->THTflag&THTF_LOGON)) //1st time                //~v8@BR~
      {                                                            //~v8@BR~
	    Ppthtb->THTflag|=THTF_LOGON;	//connect flag
        uerrmsgmt(1,"logon '%s'-'%s' successed.",0,
					Ppopd[PARM_HOST],user);
      }                                                            //~v8@BR~
    }
    else
    {
		if (rc==THTRC_TIMEOUT)	//cleanup requred
        	uerrmsgmt(1,"!!! logon '%s'-'%s' Timeout.",0,
					Ppopd[PARM_HOST],user);
    }
UTRACEP("calllogon rc=%d\n",rc);                                   //~v8@rI~
    return rc;
}//calllogon
//****************************************************************
//*up to logon
//*opd:from hostname
//****************************************************************
int calllogoff(PTHREADTB Ppthtb)
{
    int rc;
//**************
UTRACEP("calllogoff entry\n");
//it may be logoned by string cmd but,it is ypur responsibility to logoff by string cmd//~v8@rR~
    if (!(Ppthtb->THTflag & THTF_LOGON))    //not logoned          //~v8@rR~
    {                                                              //~v8@rR~
UTRACEP("calllogoff rc=0 by not logonned\n");                      //~v8@rR~
        return 0;                                                  //~v8@rR~
    }                                                              //~v8@rR~
    getcfgparm(0,Ppthtb);                                          //~v8@DI~
//  rc=awakethread(Ppthtb,THTRQ_LOGOFF,TIMEOUT_LOGOFF);	//infinite wait//~v8@3R~
    rc=awakethread(Ppthtb,THTRQ_LOGOFF,G3270to_logoff);	//infinite wait//~v8@3I~
UTRACEP("calllogoff rc=%d\n",rc);
    return rc;
}//calllogoff
//****************************************************************
//*disconnect and end 3270 process
//*opd:from hostname
//****************************************************************
int callend3270(PTHREADTB Ppthtb)
{
    int rc;
//************
UTRACEP("callend3270 entry\n");
    if ((Ppthtb->THTflag & THTF_CLOSE))                            //~v8@rR~
    {                                                              //~v8@rI~
UTRACEP("callend3270 rc=0 by not already closed\n");               //~v8@rI~
		uerrmsgmt(1,"Already connection closed",0);                //~v8@rI~
        return 0;                                                  //~v8@rI~
    }                                                              //~v8@rI~
   rc=                                                             //~v8@7I~
	calllogoff(Ppthtb);
	if (!(Ppthtb->THTflag & THTF_CONNECTED))	//not logoned
    {
UTRACEP("callend3270 rc=0 by not connected\n");
		return 0;
    }
  if (!rc)                                                         //~v8@7I~
//  rc=awakethread(Ppthtb,THTRQ_DISCONNECT,TIMEOUT_DISCONNECT);	//infinite wait//~v8@9R~
    rc=awakethread(Ppthtb,THTRQ_DISCONNECT,G3270to_disconn);	//infinite wait//~v8@9I~
UTRACEP("callend3270 rc=%d\n",rc);
    return rc;
}//callend3270
//****************************************************************
//*execute ftp
//****************************************************************
//int callftp(int Preqcode,int Popdno,char **Ppopd)                //~v716R~
int callftp(int Preqcode,PTHREADTB Ppthtb,int Popdno,char **Ppopd) //~v716I~
{
	PTHREADTB pthtb;
	int rc,timeout;                                                //~v716R~
//    char user[THTUSERNAMESZ],*phost;                             //~v716R~
//**************************                                       //~v716R~
//    parseusername(Ppopd[PARM_USER],user);                        //~v716R~
//    phost=Ppopd[PARM_HOST];                                      //~v716R~
//    if (Popdno<PARM_MINIMUM)    //hostname userid/pswd {get|put} hostfile localfile [options]//~v716R~
//    {                                                            //~v716R~
//        uerrmsgmt(1,"transfer cmd missing operand",0);           //~v716R~
//        return 4;           //umalloc failed                     //~v716R~
//    }                                                            //~v716R~
//    thidx=srchthread(SRCH_MAYNEW,phost,user);   //search by hostname userid//~v716R~
//    if (thidx==MAX_THREADTB)                                     //~v716R~
//    {                                                            //~v716R~
//        uerrmsgmt(1,"xe3270 thread overflow; host=%s,user=%s;max=%d",0,//~v716R~
//                phost,user,MAX_THREADTB);                        //~v716R~
//        return 4;           //umalloc failed                     //~v716R~
//    }                                                            //~v716R~
//    if (thidx<0)                                                 //~v716R~
//    {                                                            //~v716R~
//        uerrmsgmt(1,"xe3270 waiting thread termination,try later; host=%s,user=%s;",0,//~v716R~
//                phost,user);                                     //~v716R~
//        return 4;           //umalloc failed                     //~v716R~
//    }                                                            //~v716R~
//    pthtb=Sthtb+thidx;                                           //~v716R~
    pthtb=Ppthtb;                                                  //~v716R~
    if (calllogon(pthtb,Ppopd))
//  	return 4;                                                  //~v721R~
        return U3CR_RC_OTHER;                                      //~v721I~
//  if (iscmdthread())   //req by stdin cmd                        //~v72HR~
//      timeout=TIMEOUT_TRANSFER_STDINCMD;                         //~v72HR~
//  else                                                           //~v72HR~
//	    timeout=Stimeout_transfer;	//infinite wait                //~v72iR~
  	    timeout=G3270to_ftp;	//infinite wait                    //~v72iI~
    rc=awakethread(pthtb,Preqcode,timeout);	//infinite wait
    if (rc)
		if (rc==THTRC_TIMEOUT)	//cleanup requred
        {                                                          //~v721I~
    		uerrmsgmt(1,"FTP Timeout host=%s,user=%s",0,
//        				pthtb->THThostname,pthtb->THTusername);    //~v8@3R~
          				THT_HOSTNAME(pthtb),pthtb->THTusername);   //~v8@3I~
            rc=U3CR_RC_OTHER;                                      //~v721I~
        }                                                          //~v721I~
    return rc;
}//callftp
//**************************************************************** //~v716I~
//*execute TSO cmd                                                 //~v716I~
//**************************************************************** //~v716I~
int calltsocmd(int Preqcode,PTHREADTB Ppthtb,int Popdno,char **Ppopd)//~v716I~
{                                                                  //~v716I~
	PTHREADTB pthtb;                                               //~v716I~
	int rc,timeout;                                                //~v716R~
//**************************                                       //~v716I~
    pthtb=Ppthtb;                                                  //~v716R~
    pthtb->THTparm=Ppopd;                                          //~v716I~
    if (calllogon(pthtb,Ppopd))                                    //~v716I~
//  	return 4;                                                  //~v721R~
        return U3CR_RC_OTHER;                                      //~v721I~
//  timeout=TIMEOUT_TSOCMD;                                        //~v72iR~
    timeout=G3270to_tsocmd;                                        //~v72iI~
    rc=awakethread(pthtb,Preqcode,timeout);	//infinite wait        //~v716I~
    if (rc)                                                        //~v716I~
		if (rc==THTRC_TIMEOUT)	//cleanup requred                  //~v716I~
        {                                                          //~v721I~
    		uerrmsgmt(1,"TSO cmd Timeout host=%s,user=%s",0,       //~v716I~
//      				pthtb->THThostname,pthtb->THTusername);    //~v8@3R~
        				THT_HOSTNAME(pthtb),pthtb->THTusername);   //~v8@3I~
            rc=U3CR_RC_OTHER;                                      //~v721I~
        }                                                          //~v721I~
    return rc;                                                     //~v716I~
}//calltsocmd                                                      //~v716I~
//****************************************************************
//*3270 sub process start
//****************************************************************
int funcstart3270(PTHREADTB Ppthtb)
{
//  char *pargv[4];                                                //~v72BR~
//  char *pargv[20];                                               //~v72BI~//~vafjR~
static char *pargv[20];                                            //~vafjR~
    int rc;
//  int pids[3];	//pid,pipe fd(p->c),pipe fd(c->p)              //~vazwR~
    LONGHANDLE pids[3];	//pid,pipe fd(p->c),pipe fd(c->p)          //~vazwR~
#ifdef LNX                                                         //~vaa7I~
	#ifndef NOTRACE                                                //~vaa7I~
    	int pid;                                                   //~vaa7I~
    #endif                                                         //~vaa7I~
#else                                                              //~vaa7I~
    int pid;
#endif                                                             //~vaa7I~
    int ii;                                                        //~v71SI~
#ifdef LNX                                                         //~v716I~
    ULONG pecb;                                                    //~v716I~
#endif                                                             //~v716I~
//  char cmd3270[MAX_CMDSZ],*pc,*pc2;                              //~v72FR~//~vafjR~
static char cmd3270[MAX_CMDSZ];                                    //~vafjI~
    char *pc,*pc2;                                                 //~vafjI~
//************************
UTRACEP("start3270 entry\n");
#ifdef LNX                                                         //~v716I~
	pecb=Ppthtb->THTecbkill;                                       //~v716I~
	rc=uevent(UEVENTO_RESET,1,&pecb,0,0);                          //~v716I~
#endif                                                             //~v716I~
//  pargv[0]=EM3270;                                               //~v72FR~
//  pargv[1]=0;                                                    //~v72FR~
//  ii=1;                                                          //~v72FR~
//  strcpy(cmd3270,G3270emulator);                                 //~v8@5R~
//  strcpy(cmd3270,G3270emulator[Ppthtb->THThosttblidx]);          //~v8@9R~
    strcpy(cmd3270,cfggetemulator(0,Ppthtb));                      //~v8@9I~
    for (ii=0,pc=cmd3270;*pc;)                                     //~v72FR~
    {                                                              //~v72FR~
    	pc2=strchr(pc,' ');                                        //~v72FR~
        if (!pc2)                                                  //~v72FR~
        {                                                          //~v72FR~
        	pargv[ii++]=pc;                                        //~v72FR~
            break;                                                 //~v72FR~
        }                                                          //~v72FR~
        *pc2++=0;                                                  //~v72FR~
        pargv[ii++]=pc;                                            //~v72FR~
        pc=pc2+strspn(pc2," ");                                    //~v72FR~
    }                                                              //~v72FR~
//  if (Sotheropt & OTHEROPT_TRACE)           //bug investigation  //~v72FR~
//  	pargv[ii++]="-trace";      //specify trace optio on cfg    //~v72FR~
    pargv[ii]=0;                                                   //~v71SI~
UTRACED("3270 spawn parm",cmd3270,MAX_CMDSZ);                      //~v72BI~
                                                                   //~v72BI~
LOCK_ENTER();
//  rc=uspawnvp_pipe(USP_STDIN|USP_STDOUT|USP_STDERR,pids,EM3270,pargv);//~v72BR~
    rc=uspawnvp_pipe(USP_STDIN|USP_STDOUT|USP_STDERR,pids,pargv[0],pargv);//~v72BI~
LOCK_LEAVE();
UTRACEP("3270 spawn rc=%d\n",rc);                                  //~v72FI~
    if (pids[0]<=0)	//child pid
    	return postbackmain(Ppthtb,THTRC_SUBERR);
    usleepms(1000);        //wait until s3270 stable,i dont know why but fail if not sleep//~vafjR~
//  Ppthtb->THTchildph=pids[0];                                    //~vafjR~
#ifdef LNX                                                         //~v715R~
  Ppthtb->THTchildph=pids[0];                                      //~vafjI~
  #ifndef NOTRACE                                                  //~vaa7I~
    pid=pids[0];    //no concept of handle and pid in linux        //~v715I~
  #endif                                                           //~vaa7I~
#else                                                              //~v715I~
//  Ppthtb->THTchildpid=pid=ugetpidfromhandle(pids[0]);            //~vafjR~
    pid=ugetpidfromhandle(pids[0]);                                //~vafjI~
    Ppthtb->THTchildph=pids[0];                                    //~vafjI~
    Ppthtb->THTchildpid=pid;                                       //~vafjI~
#endif                                                             //~v715I~
//  Ppthtb->THTpipep2c=pids[1];    //write                         //~vazwR~
    Ppthtb->THTpipep2c=(int)pids[1];    //write                    //~vazwI~
//  Ppthtb->THTpipec2p=pids[2];    //read                          //~vazwR~
    Ppthtb->THTpipec2p=(int)pids[2];    //read                     //~vazwI~
#ifdef W32                                                         //~v715I~
    notifymonitor();	//register process handle to be monitored
#endif                                                             //~v715I~
UTRACEP("spawn child ph=%d(x%x),pid=%d(x%x),fdw=%d,fdr=%d\n",pids[0],pids[0],pid,pid,pids[1],pids[2]);
UTRACEP("start3270 exit rc=%d\n",rc);
    return rc;
}//funcstart3270
//****************************************************************
//*close pipe between child process
//****************************************************************
int close3270(PTHREADTB Ppthtb)
{
//************************
UTRACEP("close3270 entry\n");                                      //~v8@eR~
	if (Ppthtb->THTflag & THTF_CLOSE)                              //~v8@eR~
		return 0;                                                  //~v8@eR~
	Ppthtb->THTflag|=THTF_CLOSE;                                   //~v8@eI~
	write3270(Ppthtb,"quit");//write to pipe                       //~v8@eI~
#ifdef LNX                                                         //~v715I~
UTRACEP("close3270 pid=%d\n",Ppthtb->THTchildph);                  //~v8@eR~
//  if (Ppthtb->THTchildph)	//not yet killed                       //~v8@eR~
//  	Ppthtb->THTkillph=Ppthtb->THTchildph;	//expect monitor detection and post back to avoid zombie//~v8@eR~
#endif                                                             //~v715I~
    if (Ppthtb->THTpipep2c)
    {
	    close(Ppthtb->THTpipep2c);
	    Ppthtb->THTpipep2c=0;
    }
    if (Ppthtb->THTpipec2p)
    {
	    close(Ppthtb->THTpipec2p);
    	Ppthtb->THTpipec2p=0;
    }
#ifdef LNX                                                         //~v715I~
//	if (Ppthtb->THTkillph)	//expect monitor detection and post back to avoid zombie//~v8@eR~
  	if (Ppthtb->THTchildph)	//expect monitor detection and post back to avoid zombie//~v8@eI~
		chkendproc(Ppthtb);				// wait monitor post with timeout//~v715R~
#else                                                              //~v8@eI~
  	if (Ppthtb->THTchildph)	//expect monitor detection and post back to avoid zombie//~v8@eI~
		chkendproc(Ppthtb);				// wait monitor post with timeout//~v8@eI~
#endif                                                             //~v715I~
UTRACEP("close3270 exit\n");
    return 0;
}//closepipe
//****************************************************************
//*execute ftp
//****************************************************************
int callsysincmd(char *Pcmd,PTHREADTB *Pppthtb)                    //~v716R~
{
    int rc,wordno,opt;
    char **ppcmdopd;
//*******************
	*Pppthtb=0;                                                    //~v716I~
    opt=UPARSESEPCONTDELM|UPARSENOSQUOTE;	//treate continued delm as two field,keep "'"
LOCK_ENTER_THREAD();
//  rc=uparsev(Pcmd,(UCHAR***)(ULONG)&ppcmdopd,&wordno,opt,",\n"); //~v715R~//~vafkR~
    rc=uparsev(Pcmd,(UCHAR***)(ULPTR)&ppcmdopd,&wordno,opt,",\n"); //~vafkI~
LOCK_LEAVE_THREAD();
    if (rc)
    {
    	uerrmsgmt(1,"xe3270 sysin cmd parse err for %s",0,
        		Pcmd);
    	return rc;			//umalloc failed
    }
    if (wordno)
    {
	    rc=callsysincmd2(wordno,ppcmdopd,Pppthtb);                 //~v716R~
        if (!rc)
		    ufree(ppcmdopd);
    }
    else
	    ufree(ppcmdopd);
    return rc;
}//callsysincmd
//****************************************************************
//*execute cmd from stdin
//****************************************************************
int callsysincmd2(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)      //~v716R~
{
    PCMDTB pcmdtb;
	int rc;
    char *pcmd;
//**************************
	pcmd=*Ppopd;
    for (pcmdtb=Ssysincmdtb;pcmdtb->CMDTfunc;pcmdtb++)
    {
		if (!stricmp(pcmdtb->CMDTcmd,pcmd)
		||  !stricmp(pcmdtb->CMDTalias,pcmd))
            break;
    }
    if (pcmdtb->CMDTfunc)
        rc=pcmdtb->CMDTfunc(Popdno,Ppopd,Pppthtb);                 //~v716R~
    else
    {
    	uerrmsgmt(1,"Invalid cmd, use \"%s\" or\" %s\" to list cmd",0,
					Ssysincmdtb[CMDID_HELP].CMDTcmd,Ssysincmdtb[CMDID_HELP].CMDTalias);
        rc=8;
    }
    return rc;
}//callsysincmd2
//****************************************************************
//*sysincmd put
//****************************************************************
int sysincmdquit(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)       //~v716R~
{
    PTHREADTB pthtb;
//**************************
#ifdef LNX                                                         //~v715I~
	notify2main("quit");		                                   //~v715I~
    close(Sfdpipenotify);                                          //~v715I~
#endif                                                             //~v715I~
	pthtb=&Sthtbcmd;
    *Pppthtb=pthtb;                                                //~v716I~
	exitthread(pthtb,THTEC_NORMAL);
    return 0;
}//sysincmdquit
//****************************************************************
//*sysincmd help
//****************************************************************
int sysincmdhelp(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)       //~v716R~
{
    PCMDTB pcmdtb;
    char editwk[32];
    int seqno=0;                                                   //~v8@BI~
//**************************
	uerrmsgmt(1,"List of Command -------------",0);
    for (pcmdtb=Ssysincmdtb;pcmdtb->CMDTfunc;pcmdtb++)
    {
      if (seqno!=CMDID_QUERY                                       //~v8@BI~
      )                                                            //~v8@BI~
      {                                                            //~v8@BI~
		sprintf(editwk,"%s/%s",pcmdtb->CMDTcmd,pcmdtb->CMDTalias);
		uerrmsgmt(0,"%-13s %s\n",0,
					editwk,pcmdtb->CMDThelp);
      }                                                            //~v8@BI~
        seqno++;                                                   //~v8@BI~
    }
//	uerrmsgmt(0,"-- \"Cmd\" is for input 3270 cmd.\n",0);          //~v8@BR~
  	uerrmsgmt(0,"-- \"%s\" is for input 3270 cmd.\n",0,            //~v8@BR~
                CMD_3270CMD);                                      //~v8@BI~
    uerrmsgmt(0,"   ex.) \"PA 1\" \"Enter\" \"Clear\".(see manual of \"x3270 -script\")\n",0);//~v72ER~
	uerrmsgmt(0,"-- Host,Userid is omittable if same as previous input.\n",0);//~v719R~
	uerrmsgmt(0,"   ex) \"snap\" , \"get,,,hostfile,localfile\".\n",0);
	uerrmsgmt(0,"-- Option for ftp is xx==yy fmt except supported abridgment \"bin\",\"rep\",\"app\".\n",0);
    return 0;
}//sysincmdhelp
//****************************************************************
//*sysincmd logoff
//****************************************************************
int sysincmdlogon(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)      //~v716R~
{
    PTHREADTB pthtb;
	int rc,idx;
//**************************
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,2))<0)
    	return 4;
    pthtb=Sthtb+idx;
    *Pppthtb=pthtb;                                                //~v716I~
    rc=calllogon(pthtb,Ppopd);
    return rc;
}//sysincmdlogon
//****************************************************************
//*sysincmd logoff
//****************************************************************
int sysincmdlogoff(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)     //~v716R~
{
    PTHREADTB pthtb;
	int rc,idx;
    char *pc;                                                      //~v72CI~
//**************************
	if ((idx=cmdopdchk(OPDCHK_NOTBUSY,&Popdno,&Ppopd,2))<0)
    	return 4;
    pthtb=Sthtb+idx;
    *Pppthtb=pthtb;                                                //~v716I~
//  rc=calllogoff(pthtb);
    rc=callend3270(pthtb);
    if (pc=strchr(Ppopd[PARM_USER],'/'),pc)                        //~v72CI~
    	*pc=0;                                                     //~v72CI~
    if (!rc)
    {
	  if (pthtb->THTflag & THTF_CONNECTED)	//connect flag         //~v8@rR~
      {                                                            //~v8@rI~
	    pthtb->THTflag&=~THTF_CONNECTED;	//connect flag
        uerrmsgmt(1,"'%s'-'%s' disconnected.",0,
					Ppopd[PARM_HOST],Ppopd[PARM_USER]);
      }                                                            //~v8@rI~
    }
    else
    {
		if (rc==THTRC_TIMEOUT)	//cleanup requred
        	uerrmsgmt(1,"!!! disconnect '%s'-'%s' Timeout.",0,
					Ppopd[PARM_HOST],Ppopd[PARM_USER]);
    }
    return rc;
}//sysincmdlogoff
//****************************************************************
//*sysincmd cancel
//****************************************************************
int sysincmdcancel(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)     //~v716R~
{
    PTHREADTB pthtb;
	int rc,idx;
//**************************
	if ((idx=cmdopdchk(0,&Popdno,&Ppopd,2))<0)
    	return 4;
    pthtb=Sthtb+idx;
    *Pppthtb=pthtb;                                                //~v716I~
    if (pthtb->THTexitcode)
    {
//      clearthtb(pthtb);                                          //~v715R~
        uerrmsgmt(1,"Entry for %s-%s is cleared",0,
                    Ppopd[1],Ppopd[2]);
        clearthtb(1,pthtb);   //Ppopd[1] may point when operand abridged//~v715R~
        rc=0;
    }
    else
    {
      rc=                                                          //~vafcI~
		cancelthread(pthtb);
    	uerrmsgmt(1,"Cancel scheduled for %s,%s",0,                //~v715R~
					Ppopd[1],Ppopd[2]);
    }
    return rc;
}//sysincmdcancel
//****************************************************************
//*sysincmd get
//****************************************************************
int sysincmdget(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)        //~v716R~
{
	PTHREADTB pthtb;                                               //~v716I~
	int rc,rc2;
    int idx;                                                       //~v716I~
    char *pc,*pc2,*phostfnm;
    char dsn[_MAX_PATH];
//**************************
//  if (cmdopdchk(OPDCHK_NEW,&Popdno,&Ppopd,4)<0)                  //~v716R~
    if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,4))<0)//~v716I~
    	return 4;
    pthtb=Sthtb+idx;                                               //~v716I~
    *Pppthtb=pthtb;                                                //~v716I~
    Ppopd[0]=Ssysincmdtb[CMDID_GET].CMDTalias;	//force to "Receive"
//  rc=callftp(THTRQ_TRANSFER_GET,Popdno,Ppopd);                   //~v716R~
    rc=callftp(THTRQ_TRANSFER_GET,pthtb,Popdno,Ppopd);             //~v716I~
    if (rc==U3CR_RC_NOTFOUND)                                      //~v716R~
    {
        phostfnm=Ppopd[PARM_HOSTFILE];
    	if ((pc=strchr(phostfnm,'(')) && (pc2=strchr(pc,')')))	//member specified
    	{
        	strcpy(dsn,phostfnm);
        	strcpy(pc,pc2+1);	//drop "(membername)"
//  		rc2=callftp(THTRQ_TRANSFER_GET,Popdno,Ppopd);	//try by DSN//~v716R~
    		rc2=callftp(THTRQ_TRANSFER_GET,pthtb,Popdno,Ppopd);	//try by DSN//~v716I~
            if (!rc2)
            {
				deltempfile(Ppopd[PARM_LOCALFILE]);
    			uerrmsgmt(1,"Member Not Found(%s)",0,
								dsn);
            }
            else
		    if (rc2==U3CR_RC_NOTFOUND)                             //~v716R~
            	rc=U3CR_RC_PATHERR;		//DSN not found            //~v71eR~
            else
            	rc=rc2;
        }
    }
    return rc;
}//sysincmdget
//**************************************************************** //~v716I~
//*sysincmd ListDS                                                 //~v716I~
//**************************************************************** //~v716I~
int sysincmdlistds(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)     //~v716R~
{                                                                  //~v716I~
	PTHREADTB pthtb;                                               //~v716I~
	int rc,idx;                                                    //~v719R~
//**************************                                       //~v716I~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,3))<0)//~v716R~
    	return 4;                                                  //~v716I~
    pthtb=Sthtb+idx;                                               //~v716M~
    *Pppthtb=pthtb;                                                //~v716I~
//    phostfile=Ppopd[PARM_HOSTFILE];                              //~v719R~
//    popt=Ppopd[PARM_HOSTFILE+1];                                 //~v719R~
//    len=u3270getmembname(0,phostfile,membname); //0:no set dummy member even if not specified//~v719R~
//    if (popt && toupper(*popt)=='M')                             //~v719R~
//        membopt=1;                                               //~v719R~
//    else                                                         //~v719R~
//        if (len)    //member specified                           //~v719R~
//        {                                                        //~v719R~
//            popt=Ppopd[PARM_HOSTFILE+1]="M";                     //~v719R~
//            membopt=2;                                           //~v719R~
//        }                                                        //~v719R~
	rc=calltsocmd(THTRQ_TSOCMD_LISTDS,pthtb,Popdno,Ppopd);         //~v716R~
UTRACEP("sysincmdlistds rc=%d\n",rc);                              //~v716I~
    return rc;                                                     //~v716I~
}//sysincmdlistds                                                  //~v716I~
//**************************************************************** //~v72nI~
//*sysincmd SPF                                                    //~v72nI~
//**************************************************************** //~v72nI~
int sysincmdspf(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)        //~v72nI~
{                                                                  //~v72nI~
	PTHREADTB pthtb;                                               //~v72nI~
	int rc,idx;                                                    //~v72nI~
//**************************                                       //~v72nI~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,4))<0)   //3:dsn,4:spf inf//~v72nR~
    	return 4;                                                  //~v72nI~
    pthtb=Sthtb+idx;                                               //~v72nI~
    *Pppthtb=pthtb;                                                //~v72nI~
	rc=calltsocmd(THTRQ_TSOCMD_SPF,pthtb,Popdno,Ppopd);            //~v72nI~
UTRACEP("sysincmdspf rc=%d\n",rc);                                 //~v72nI~
    return rc;                                                     //~v72nI~
}//sysincmdlistds                                                  //~v72nI~
//**************************************************************** //~v71eI~
//*sysincmd ListDS                                                 //~v71eI~
//**************************************************************** //~v71eI~
int sysincmdrename(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)     //~v71eI~
{                                                                  //~v71eI~
	PTHREADTB pthtb;                                               //~v71eI~
	int rc,idx;                                                    //~v71eI~
//**************************                                       //~v71eI~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,4))<0)//~v71fR~
    	return 4;                                                  //~v71eI~
    pthtb=Sthtb+idx;                                               //~v71eI~
    *Pppthtb=pthtb;                                                //~v71eI~
	rc=calltsocmd(THTRQ_TSOCMD_RENAME,pthtb,Popdno,Ppopd);         //~v71eR~
UTRACEP("sysincmdrename rc=%d\n",rc);                              //~v71eI~
    return rc;                                                     //~v71eI~
}//sysincmdrename                                                  //~v71eR~
//**************************************************************** //~v71eI~
//*sysincmd ListDS                                                 //~v71eI~
//**************************************************************** //~v71eI~
int sysincmddelete(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)     //~v71eI~
{                                                                  //~v71eI~
	PTHREADTB pthtb;                                               //~v71eI~
	int rc,idx;                                                    //~v71eI~
//**************************                                       //~v71eI~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,3))<0)//~v71eI~
    	return 4;                                                  //~v71eI~
    pthtb=Sthtb+idx;                                               //~v71eI~
    *Pppthtb=pthtb;                                                //~v71eI~
	rc=calltsocmd(THTRQ_TSOCMD_DELETE,pthtb,Popdno,Ppopd);         //~v71eI~
UTRACEP("sysincmddelete rc=%d\n",rc);                              //~v71nR~
    return rc;                                                     //~v71eI~
}//sysincmddelete                                                  //~v71eI~
//**************************************************************** //~v71nI~
//*sysincmd Allocate                                               //~v71nI~
//**************************************************************** //~v71nI~
int sysincmdalloc(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)      //~v71nI~
{                                                                  //~v71nI~
	PTHREADTB pthtb;                                               //~v71nI~
	int rc,idx;                                                    //~v71nI~
//**************************                                       //~v71nI~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,3))<0)//~v71nR~
    	return 4;                                                  //~v71nI~
    pthtb=Sthtb+idx;                                               //~v71nI~
    *Pppthtb=pthtb;                                                //~v71nI~
	rc=calltsocmd(THTRQ_TSOCMD_ALLOCATE,pthtb,Popdno,Ppopd);       //~v71nR~
UTRACEP("sysincmdalloc rc=%d\n",rc);                               //~v71nI~
    return rc;                                                     //~v71nI~
}//sysincmdalloc                                                   //~v71nI~
//**************************************************************** //~v71nI~
//*sysincmd Allocate                                               //~v71nI~
//**************************************************************** //~v71nI~
int sysincmdfree(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)       //~v71nI~
{                                                                  //~v71nI~
	PTHREADTB pthtb;                                               //~v71nI~
	int rc,idx;                                                    //~v71nI~
//**************************                                       //~v71nI~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,3))<0)//~v71nI~
    	return 4;                                                  //~v71nI~
    pthtb=Sthtb+idx;                                               //~v71nI~
    *Pppthtb=pthtb;                                                //~v71nI~
	rc=calltsocmd(THTRQ_TSOCMD_FREE,pthtb,Popdno,Ppopd);           //~v71nI~
UTRACEP("sysincmdfree rc=%d\n",rc);                                //~v71nI~
    return rc;                                                     //~v71nI~
}//sysincmdfree                                                    //~v71nI~
//**************************************************************** //~v8@BI~
//*sysincmd TSO                                                    //~v8@BI~
//**************************************************************** //~v8@BI~
int sysincmdtso(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)        //~v8@BI~
{                                                                  //~v8@BI~
	PTHREADTB pthtb;                                               //~v8@BI~
	int rc,idx;                                                    //~v8@BI~
//**************************                                       //~v8@BI~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,3))<0)//~v8@BI~
    	return 4;                                                  //~v8@BI~
    pthtb=Sthtb+idx;                                               //~v8@BI~
    *Pppthtb=pthtb;                                                //~v8@BI~
	rc=calltsocmd(THTRQ_TSOCMD_TSO,pthtb,Popdno,Ppopd);            //~v8@BI~
UTRACEP("sysincmdfree rc=%d\n",rc);                                //~v8@BI~
    return rc;                                                     //~v8@BI~
}//sysincmdtso                                                     //~v8@BI~
//**************************************************************** //~v8@BI~
//*sysincmd TSO                                                    //~v8@BI~
//**************************************************************** //~v8@BI~
int sysincmdquery(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)      //~v8@BI~
{                                                                  //~v8@BI~
	PTHREADTB pthtb;                                               //~v8@BI~
	int rc,idx;                                                    //~v8@BI~
//**************************                                       //~v8@BI~
UTRACEP("sysincmdquery \n");                                       //~v8@BR~
	if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,3))<0)//~v8@BR~
    	return 4;                                                  //~v8@BI~
    pthtb=Sthtb+idx;                                               //~v8@BI~
    *Pppthtb=pthtb;                                                //~v8@BI~
	rc=calltsocmd(THTRQ_TSOCMD_QUERY,pthtb,Popdno,Ppopd);          //~v8@BI~
UTRACEP("sysincmdquery rc=%d\n",rc);                               //~v8@BI~
    return rc;                                                     //~v8@BI~
}//sysincmdtso                                                     //~v8@BI~
//****************************************************************
//*deletefile
//****************************************************************
int deltempfile(char *Pfilename)
{
	int rc;
//*****************
#ifdef UNX
	rc=unlink(Pfilename);   //-1 if err
#else
    rc=remove(Pfilename);
#endif
	return rc;
}//deltempfile
//****************************************************************
//*sysincmd put
//****************************************************************
int sysincmdput(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)        //~v716R~
{
	PTHREADTB pthtb;                                               //~v716I~
	int rc;
    int idx;                                                       //~v716I~
//**************************
//  if (cmdopdchk(OPDCHK_NEW,&Popdno,&Ppopd,4)<0)                  //~v716R~
    if ((idx=cmdopdchk(OPDCHK_NEW|OPDCHK_NOTBUSY,&Popdno,&Ppopd,4))<0)//~v716I~
    	return 4;
    pthtb=Sthtb+idx;                                               //~v716I~
    *Pppthtb=pthtb;                                                //~v716I~
    Ppopd[0]=Ssysincmdtb[CMDID_PUT].CMDTalias;	//change to Send
//  rc=callftp(THTRQ_TRANSFER_PUT,Popdno,Ppopd);                   //~v716R~
    rc=callftp(THTRQ_TRANSFER_PUT,pthtb,Popdno,Ppopd);             //~v716I~
    return rc;
}//sysincmdput
//****************************************************************
//*put string(3270 cmd)
//****************************************************************
int sysincmdcmd(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)        //~v716R~
{
	PTHREADTB pthtb;
	int idx,rc=4;                                                  //~vafdR~
//**************************
	if ((idx=cmdopdchk(0,&Popdno,&Ppopd,3))<0)
    	return 4;
    pthtb=Sthtb+idx;
    *Pppthtb=pthtb;                                                //~v716I~
//    if (isthreadbusy(0,pthtb))                                   //~v8@eR~
//    {                                                            //~v8@eR~
//        uerrmsgmt(1,"%s-%s is busy,so directrly written to the pipe",0,//~v8@eR~
//                        Ppopd[1],Ppopd[2]);                      //~v8@eR~
//        rc=write3270(pthtb,Ppopd[3]);                            //~v8@eR~
//    }                                                            //~v8@eR~
//    else                                                         //~v8@eR~
    if (!isthreadbusy(ISBUSY_MSG,pthtb))                           //~v8@eI~
    {
    	pthtb->THTparm=Ppopd+3;	//string
    	rc=awakethread(pthtb,THTRQ_CMD,TIMEOUT_CMD);
    }
UTRACEP("string rc=%d\n",rc);
	return rc;
}//sysincmdcmd
//**************************************************************** //~v72BI~
//*put string(3270 cmd)                                            //~v72BI~
//**************************************************************** //~v72BI~
int sysincmdrsh(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)        //~v72BI~
{                                                                  //~v72BI~
    int rc;                                                        //~v72BI~
	PTHREADTB pthtb;                                               //~v72BI~
//*****************                                                //~v72BI~
	rc=sysincmdstringsub(THTRQ_RSH,Popdno,Ppopd,Pppthtb);          //~v72BR~
    pthtb=*Pppthtb;                                                //~v72BI~
    if (!pthtb)                                                    //~v72BI~
    {                                                              //~v72BI~
    	uerrmsgmt(1,"No session for %s-%s,try after logon",        //~v72BI~
                    "%s-%sのセッションがありません、まずログオンしてください",//~v72BI~
        				Ppopd[1],Ppopd[2]);                        //~v72BI~
        return rc;                                                 //~v72BI~
    }                                                              //~v72BI~
    if (rc==THTRC_TIMEOUT)                                         //~v72BI~
    	settimeoutrespdata(pthtb);                                 //~v72BR~
    return rc;                                                     //~v72BI~
}                                                                  //~v72BI~
//**************************************************************** //~v72BI~
//*put string(3270 cmd)                                            //~v72BI~
//**************************************************************** //~v72BI~
int settimeoutrespdata(PTHREADTB Ppthtb)                           //~v72BI~
{                                                                  //~v72BI~
    int len,msglen;                                                //~v72BI~
    char tomsg[128];                                               //~v72BI~
    PSCRDATA      prespdata;                                       //~v72BI~
//********************                                             //~v72BI~
	msglen=1+sprintf(tomsg,"Command Timeout(%d sec expired)\n",G3270to_tsocmd);//~v72BR~
//  len=msglen+SCRDATAHDRSZ;                                       //~v72BI~//~vazxR~
    len=msglen+(int)SCRDATAHDRSZ;                                  //~vazxI~
//  prespdata=(PSCRDATA)ucalloc(len,1);                            //~v72BI~//~vazxR~
    prespdata=(PSCRDATA)ucalloc((size_t)len,1);                    //~vazxI~
    prespdata->SCRhdr.PRDlen=len;                                  //~v72BI~
    prespdata->SCRhdr.PRDtype=PRDT_RSHRESP;                        //~v72BI~
    prespdata->SCRlen=msglen;                                      //~v72BI~
//  memcpy(prespdata->SCRdata,tomsg,msglen);                       //~v72BI~//~vazxR~
    memcpy(prespdata->SCRdata,tomsg,(size_t)msglen);               //~vazxI~
	Ppthtb->THTrespdata=prespdata;                                 //~v72BI~
    Ppthtb->THTrespdatalen=len;                                    //~v72BI~
    return 0;                                                      //~v72BI~
}//settimeoutrespdata                                              //~v72BI~
//****************************************************************
//*put string(3270 cmd)
//****************************************************************
int sysincmdstring(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)     //~v716R~
{
	return sysincmdstringsub(THTRQ_STRING,Popdno,Ppopd,Pppthtb);   //~v72BI~
}                                                                  //~v72BI~
//**************************************************************** //~v72BI~
//*put string(3270 cmd)                                            //~v72BI~
//**************************************************************** //~v72BI~
int sysincmdstringsub(int Preqcode,int Popdno,char **Ppopd,PTHREADTB *Pppthtb)//~v72BI~
{                                                                  //~v72BI~
	PTHREADTB pthtb;
	int idx,rc=4;                                                  //~vafdR~
    char cmd[MAX_CMDSZ];
    int timeout;                                                   //~v72BI~
//**************************
	if ((idx=cmdopdchk(0,&Popdno,&Ppopd,3))<0)
    	return 4;
    pthtb=Sthtb+idx;
    *Pppthtb=pthtb;                                                //~v716I~
//  sprintf(cmd,"String \"%s\\n\"",Ppopd[3]);                      //~v8@mR~
  if (Preqcode==THTRQ_RSH)                                         //~v8@ZI~
    strcpy(cmd,Ppopd[3]);    //pass through to avoid d-quataion doubling//~v8@ZI~
  else                                                             //~v8@ZI~
    sprintf(cmd,"String \"%s\"",Ppopd[3]);                         //~v8@mM~
//    if (isthreadbusy(0,pthtb))                                   //~v8@eR~
//    {                                                            //~v8@eR~
//        uerrmsgmt(1,"%s-%s is busy,so directrly written to the pipe",0,//~v8@eR~
//                        Ppopd[1],Ppopd[2]);                      //~v8@eR~
//        rc=write3270(pthtb,cmd);                                 //~v8@eR~
//    }                                                            //~v8@eR~
//    else                                                         //~v8@eR~
    if (!isthreadbusy(ISBUSY_MSG,pthtb))                           //~v8@eI~
    {
    	pthtb->THTparm=Ppopd+3;	//string
    	*(Ppopd+3)=cmd;	//string
//  	rc=awakethread(pthtb,THTRQ_STRING,TIMEOUT_STRING);         //~v72BR~
        if (Preqcode==THTRQ_RSH)                                   //~v72BI~
	        timeout=G3270to_tsocmd;                                //~v72BI~
        else                                                       //~v72BI~
	        timeout=TIMEOUT_STRING;                                //~v72BI~
    	rc=awakethread(pthtb,Preqcode,timeout);                    //~v72BR~
    }
UTRACEP("string rc=%d\n",rc);
	return rc;
}//sysincmdstringsub                                               //~vafdR~
//****************************************************************
//*snap screen
//****************************************************************
int sysincmdsnap(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)       //~v716R~
{
    PTHREADTB pthtb;
	int rc,idx;
    int opt;                                                       //~v8@rI~
//**************************
	opt=OPDCHK_NOTBUSY|OPDCHK_AVAIL;                               //~v8@rR~
	if ((idx=cmdopdchk(opt,&Popdno,&Ppopd,2))<0)                   //~v8@rI~
    	return 4;
    pthtb=Sthtb+idx;
    *Pppthtb=pthtb;                                                //~v716I~
    rc=awakethread(pthtb,THTRQ_SNAP,TIMEOUT_SNAP);	//infinite wait
    return rc;
}//sysincmdsnap
//****************************************************************
//*sysincmd status
//****************************************************************
int sysincmdstat(int Popdno,char **Ppopd,PTHREADTB *Pppthtb)       //~v716R~
{
	int ii,dispctr=0;
    PTHREADTB pthtb;
    char *phost,*puser,*pmsg,*pcmd,msg[128];
//********************
	for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)
    {
//      phost=pthtb->THThostname;                                  //~v8@3R~
        phost=THT_HOSTNAME(pthtb);                                 //~v8@3I~
        puser=pthtb->THTusername;
        if (!*phost)
        	continue;
        if (pthtb->THTreqcode>=0 && pthtb->THTreqcode<THTRQ_NOTDEFINED)//~v716R~
        	pcmd=Srcdtb[pthtb->THTreqcode];                        //~v716R~
        else                                                       //~v716I~
        	pcmd="Unknown";                                        //~v716R~
UTRACEP("ph=%x,th=%x,reqcode=%d,flag=%x,subrc=%d,exitcode=%x\n",
		pthtb->THTchildph,pthtb->THThthread,pthtb->THTreqcode,pthtb->THTflag,pthtb->THTrc,pthtb->THTexitcode);
	    if (pthtb->THTflag & THTF_NOTAVAIL) //ecb create failed
            pmsg="destination not avail by internal reason";
        else
        if (pthtb->THTchildph		//child process started
        &&  !pthtb->THTexitcode     //thread not exit
		&&  pthtb->THTrc==THTRC_SUBPENDING)	//requested process
        	if (pthtb->THTflag & THTF_TIMEOUT)
            {
            	sprintf(msg,"timeout;last req=%s",pcmd);
                pmsg=msg;
            }
            else
            {
            	sprintf(msg,"now waiting %s completion",pcmd);
                pmsg=msg;
            }
        else
        if (pthtb->THTflag & THTF_TIMEOUT)
        {
            sprintf(msg,"cmd %s completed with rc=%d after timeout",pcmd,pthtb->THTrc);
            pmsg=msg;
        }
        else
        if (pthtb->THTexitcode)     //thread not exit
            pmsg="thread terminated,use cancel to reuse the entry if entry full.";
        else
	        if (pthtb->THTflag & THTF_CONNECTED)     //thread not exit
	            pmsg="connected,cmd acceptable";
            else
	            pmsg="not connected";
        if (!dispctr)
        	uerrmsgmt(1,"status list ----------------",0);
        uerrmsgmt(0,"%-8s:%-8s - %s\n",0,
					phost,puser,pmsg);
        dispctr++;
    }
    uerrmsgmt(1,"using %d entry out of %d",0,
    		dispctr,MAX_THREADTB);
    return 0;
}//sysincmdstat
//****************************************************************
//*host and userid operand chk
// return thread tbl index or -1 if err
//****************************************************************
int cmdopdchk(int Popt,int *Ppopdno,char ***Pppopd,int Pminparm)
{
    PTHREADTB pthtb;
	int idx,opt=0;
    char **popd,*puser,*phost;
//**************************
	if (cmdopdchksetmissing(Ppopdno,Pppopd)>=4)
    	return -1;
	if (Pminparm+1>*Ppopdno)
    {
    	uerrmsgmt(1,"too few operand(%d) minimum %d param required for %s",0,
        			*Ppopdno-1,Pminparm,**Pppopd);
        return -1;
	}
    popd=*Pppopd;
    phost=popd[1];
    puser=popd[2];
    if (Popt & OPDCHK_NEW)
    	opt=SRCH_MAYNEW;
	idx=srchthread(opt,phost,puser);	//serach by host/user
    if (idx==MAX_THREADTB)	//no pending
    {
	    if (Popt & OPDCHK_NEW)
		    uerrmsgmt(1,"no available thread remaines,max=%d",0,
						MAX_THREADTB);
        else
		    uerrmsgmt(1,"no thread started for %s-%s",0,
						phost,puser);
		return -1;
    }
    pthtb=Sthtb+idx;
//  if (Popt & OPDCHK_NOTBUSY)                                     //~v8@rR~
    if (Popt & (OPDCHK_NOTBUSY|OPDCHK_AVAIL))	//not busy but active//~v8@rR~
    {                                                              //~v8@rI~
//      if (isthreadbusy(ISBUSY_MSG,pthtb))                        //~v8@rI~
    	opt=ISBUSY_MSG;                                            //~v8@rI~
    	if (Popt & (OPDCHK_AVAIL))	//not busy but active          //~v8@rR~
	    	opt|=ISBUSY_AVAIL;                                     //~v8@rR~
        if (isthreadbusy(opt,pthtb))                               //~v8@rR~
            return -1;
    }                                                              //~v8@rI~
    return idx;
}//cmdopdchk
//****************************************************************
//*host and userid operand chk
// return 1:new popd malloc
//****************************************************************
int cmdopdchksetmissing(int *Ppopdno,char ***Pppopd)
{
	int  parmopdno,opdno,rc;                                       //~v715R~
    char *phost,*puser,**popd,**parmpopd;
//**************************
	parmopdno=*Ppopdno;
	parmpopd=*Pppopd;
    if (parmopdno<3)
    {
    	opdno=3;
//      popd=(char**)ucalloc(1,4*(opdno+1));	//supply           //~vaftR~
//      popd=(char**)ucalloc(1,PTRSZ*(opdno+1));	//supply       //~vaftI~//~vazxR~
        popd=(char**)ucalloc(1,(size_t)(PTRSZ*(opdno+1)));	//supply//~vazxI~
        popd[0]=parmpopd[0];
        rc=1;
    }
    else
    {
    	opdno=parmopdno;
    	popd=parmpopd;
        rc=0;
    }
	phost=popd[1];
    puser=popd[2];
    if (!(phost && *phost))                                        //~v715R~
    {
        if (!Slastpthtb)                                           //~v715R~
        {
	    	uerrmsgmt(1,"hostid parameter missing at first time",0);
    	    return 4;
        }
//  	phost=Slastpthtb->THThostname;                             //~v8@3R~
    	phost=THT_HOSTNAME(Slastpthtb);                            //~v8@3I~
	    popd[1]=phost;
    }
    if (!(puser && *puser))                                        //~v715R~
    {
        if (!Slastpthtb)                                           //~v715R~
        {
	    	uerrmsgmt(1,"userid parameter missing at first time",0);
    	    return 4;
        }
    	puser=Slastpthtb->THTusername;                             //~v715R~
	    popd[2]=puser;
    }
    *Ppopdno=opdno;
    *Pppopd=popd;
    return rc;
}//cmdopdchksetmissing
//****************************************************************
//*search available thread table
//*ret entry index;-1:waiting thread end,max:no free entry
//****************************************************************
int srchthread(int Popt,char *Phost,char *Puser)
{
	int ii,port,len;
    PTHREADTB pthtb;
    char hostname[THTHOSTNAMESZ],*pc,*phost;
    char username[THTUSERNAMESZ],*puser;
    char hostname2[THTHOSTNAMESZ];                                 //~v8@3I~
//********************
//hostname and portno
	if (pc=strchr(Phost,'('),pc)	//hostid on xehost             //~v8@3I~
    {                                                              //~v8@3I~
        *pc++=0;                                                   //~v8@3I~
//  	len=strlen(pc);                                            //~v8@3R~//~vazxR~
    	len=(int)strlen(pc);                                       //~vazxI~
//      UmemcpyZ(hostname2,pc,len-1);                              //~v8@3R~//~vazxR~
        UmemcpyZ(hostname2,pc,(size_t)len-1);                      //~vazxI~
    }                                                              //~v8@3I~
    else                                                           //~v8@3I~
    	*hostname2=0;                                              //~v8@3I~
	if (pc=strchr(Phost,':'),pc)	//port number appended
    {
//    	len=(int)((ULONG)pc-(ULONG)Phost);                         //~vafkR~
    	len=(int)((ULPTR)pc-(ULPTR)Phost);                         //~vafkI~
        if (len>=THTHOSTNAMESZ)
        	len=THTHOSTNAMESZ-1;
//  	memcpy(hostname,Phost,len);                                //~vazxR~
    	memcpy(hostname,Phost,(size_t)len);                        //~vazxI~
        *(hostname+len)=0;
        phost=hostname;
        port=atoi(pc+1);
    }
    else
    {
    	phost=Phost;
        port=0;
    }
    if (!port)
    	port=S3270port;
//username and pswd
	parseusername(Puser,username);
    puser=username;

	for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)
    {
	    if (pthtb->THTflag & THTF_NOTAVAIL) //ecb create failed
            continue;
        if (!stricmp(pthtb->THThostname,phost)
        &&  !stricmp(pthtb->THTusername,puser))
            break;
//        if (!stricmp(pthtb->THTusername,puser))                  //~v8@DR~
//        {                                                        //~v8@DR~
//            if (*hostname2)                                      //~v8@DR~
//            {                                                    //~v8@DR~
//                if (!stricmp(pthtb->THThostname,hostname2))//vs sysincmd input hostid//~v8@DR~
//                    break;                                       //~v8@DR~
//                if (!stricmp(pthtb->THThostname2,hostname2))//xe request msg hostid//~v8@DR~
//                    break;                                       //~v8@DR~
//            }                                                    //~v8@DR~
//            else                                                 //~v8@DR~
//            {                                                    //~v8@DR~
//                if (!stricmp(pthtb->THThostname2,phost))         //~v8@DR~
//                    break;                                       //~v8@DR~
//            }                                                    //~v8@DR~
//        }                                                        //~v8@DR~
    }
    if (ii<MAX_THREADTB)        //set each time for different destid for same dest/user//~v8@DI~
    	if (*hostname2)                                            //~v8@DR~
        	strncpy(pthtb->THThostname2,hostname2,sizeof(pthtb->THThostname2)-1);//~v8@DI~
                                                                   //~v8@DI~
    if (Popt & SRCH_MAYNEW && ii==MAX_THREADTB)
        for (ii=0,pthtb=Sthtb;ii<MAX_THREADTB;ii++,pthtb++)
        {
            if (!*pthtb->THThostname)   //free entry
            {
                strncpy(pthtb->THThostname,phost,sizeof(pthtb->THThostname)-1);
                strncpy(pthtb->THThostname2,hostname2,sizeof(pthtb->THThostname2)-1);//~v8@3I~
                strncpy(pthtb->THTusername,puser,sizeof(pthtb->THTusername)-1);
                pthtb->THTport=port;
                break;
            }
        }
    return ii;
}//srchthread
//****************************************************************
//*get username from user/pswd
//*ret 4:too long username,1:pswd exist
//****************************************************************
int parseusername(char *Puserpswd,char *Puser)
{
	char *pc;
    int len,rc;
//*********************
	if (pc=strchr(Puserpswd,'/'),pc)	//port number appended
    {
    	rc=1;
//    	len=(int)((ULONG)pc-(ULONG)Puserpswd);                     //~vafkR~
    	len=(int)((ULPTR)pc-(ULPTR)Puserpswd);                     //~vafkI~
    }
    else
    {
    	rc=0;
//      len=strlen(Puserpswd);                                     //~vazxR~
        len=(int)strlen(Puserpswd);                                //~vazxI~
    }
    if (len>=THTUSERNAMESZ)
    {
        len=THTUSERNAMESZ-1;
        rc=4;
    }
    memcpy(Puser,Puserpswd,(UINT)len);
    *(Puser+len)=0;
    return rc;
}//parseusername
//****************************************************************
//*execute ftp
//****************************************************************
int killchild(PTHREADTB Ppthtb)
{
#ifdef LNX                                                         //~v715I~
//  pthread_t pid;                                                 //~v715I~//~vazwR~
    ULONG  pid;                                                 //~vazwI~//~vazxR~
#else                                                              //~v715I~
    int pid;                                                       //~v715R~
    LONGHANDLE ph;                                                //~vazwI~
#endif                                                             //~v715I~
    int rc;                                                        //~v715I~
    char *host,*user;
//*******************
UTRACEP("killchild\n");
//  pid=Ppthtb->THTchildph;                                        //~vazyR~
#ifdef LNX                                                         //~vazwI~
    pid=(ULONG)Ppthtb->THTchildph;                                 //~vazyI~
#else                                                              //~vazwI~
//  pid=(LONGHANDLE)Ppthtb->THTchildph;                            //~vazwI~//~vazxR~
    ph=(LONGHANDLE)Ppthtb->THTchildph;                             //~vazxI~
    pid=(LONGHANDLE)Ppthtb->THTchildpid;                           //~vazxI~
#endif                                                             //~vazwI~
    if (pid)
    {
//  	host=Ppthtb->THThostname;                                  //~v8@3R~
    	host=THT_HOSTNAME(Ppthtb);                                 //~v8@3I~
    	user=Ppthtb->THTusername;
#ifdef LNX                                                         //~vazwI~
//  	Ppthtb->THTkillph=Ppthtb->THTchildph;	//for monitor      //~v715I~//~vazyR~
    	Ppthtb->THTkillph=(ULONG)Ppthtb->THTchildph;	//for monitor//~vazyI~
//#ifdef LNX                                                         //~v715I~//~vazwR~
  		Ppthtb->THTchildph=0;                                      //~v715M~
UTRACEP("killchild pid=%d\n",pid);                                 //~v715R~
    	rc=ukillpid(&pid,SIGKILL);                                 //~v715R~
        if (!rc && chkendproc(Ppthtb))                             //~v715I~
	        uerrmsgmt(1,"3270 process(pid=%d) %s:%s kill request timeout",0,//~v715I~
            			pid,host,user);                            //~v715I~
        else                                                       //~v715I~
        if (rc)                                                    //~v715I~
	        uerrmsgmt(1,"3270 process(pid=%d) %s:%s kill request failed,rc=%d",0,//~v715I~
            			pid,host,user,rc);                         //~v715I~
        else                                                       //~v715I~
	        uerrmsgmt(1,"3270 process(pid=%d) %s:%s was killed.",0,//~v715I~
            			pid,host,user);                            //~v715I~
#else                                                              //~v715R~
//  	rc=ukillph(pid,3270);                                      //~v715R~//~vazxR~
    	rc=ukillph(ph,3270);                                       //~vazxI~
//      if (!rc && chkendproc((ULONG)pid))                         //~v715R~
        if (!rc && chkendproc(Ppthtb))                             //~v715R~
//          uerrmsgmt(1,"3270 process(hProcess=%p) %s:%s kill request timeout",0,//~vazwR~//~vazxR~
            uerrmsgmt(1,"3270 process(pid=%d) %s:%s kill request timeout",0,//~vazxI~
            			pid,host,user);
        else
        if (rc)
//          uerrmsgmt(1,"3270 process(hProcess=%p) %s:%s kill request failed,rc=%d",0,//~vazwR~//~vazxR~
            uerrmsgmt(1,"3270 process(pid=%d) %s:%s kill request failed,rc=%d",0,//~vazxI~
            			pid,host,user,rc);
        else
//          uerrmsgmt(1,"3270 process(hProcess=%p) %s:%s was killed.",0,//~vazwR~//~vazxR~
            uerrmsgmt(1,"3270 process(pid=%d) %s:%s was killed.",0,//~vazxI~
            			pid,host,user);
#endif                                                             //~v715I~
//      if (!rc||rc==4)	//killed or not found                      //~v715R~
//  		Ppthtb->THTchildph=0;                                  //~v715R~
    }
    return 0;
}//killchild
//****************************************************************
//*chk killed pid end                                              //~v715R~
//*rc:0:end                                                        //~v715I~
//****************************************************************
//int chkendproc(ULONG Ppid)                                       //~v715R~
int chkendproc(PTHREADTB Ppthtb)                                   //~v715I~
{
	int rc;
#ifdef LNX                                                         //~v715I~
    ULONG pecb;                                                    //~v715I~
#else                                                              //~v715I~
//  int pid;                                                       //~v715I~//~vafgR~
//  ULONG pid;                                                     //~vafgI~//~vafkR~
    ULPTR pid;                                                     //~vafkI~
#endif                                                             //~v715I~
//*******************
#ifdef LNX                                                         //~v715I~
	pecb=Ppthtb->THTecbkill;                                       //~v715R~
UTRACEP("chkendproc wait ecb=%p\n",pecb);                          //~v716I~
	rc=uevent(UEVENTO_WAIT,1,&pecb,TIMEOUT_CHKENDPROCESS*1000,0);  //~v715I~
UTRACEP("chkendproc posted from mntr rc=%d\n",rc);	               //~v715I~
    return rc!=UEVENTRC_POSTED;                                    //~v715I~
#else                                                              //~v715I~
    pid=Ppthtb->THTchildph;                                        //~v715I~
UTRACEP("chkendproc ph=%d\n",pid);                                 //~v715R~
	rc=uevent(UEVENTO_WAIT,1,&pid,TIMEOUT_CHKENDPROCESS*1000,0);   //~v715R~
UTRACEP("chkendproc ph=%d rc=%d,getlasterr=x%x\n",pid,rc,GetLastError());//~v715R~
    rc=WaitForSingleObject((HANDLE)pid,2000);                      //~v715R~
UTRACEP("chkendproc waitforsingleobject rc=%d\n",rc);
    return rc;                                                     //~vafvI~
#endif                                                             //~v715I~
//  return rc;                                                     //~vafvR~
}//chkendproc
//****************************************************************
//*execute ftp
//****************************************************************
int endthread(PTHREADTB Ppthtb)
{
	int rc;
//*******************
UTRACEP("endthread no=%d\n",Ppthtb->THTseqid);
    if (!Ppthtb->THThthread
    ||  Ppthtb->THTexitcode)
    {
UTRACEP("already thread end\n");
		return 0;
    }
    rc=awakethread(Ppthtb,THTRQ_ENDTHREAD,TIMEOUT_ENDTHREAD);
    return rc;
}//endthread
//****************************************************************
//*execute ftp
//****************************************************************
int cancelthread(PTHREADTB Ppthtb)
{
	int rc;
//**************************
UTRACEP("cancelthread no=%d\n",Ppthtb->THTseqid);
	endthread(Ppthtb);		//thread terminate
    rc=killchild(Ppthtb);
    return rc;
}//cancelthread
//****************************************************************
//*thread busy chk
// 1: if busy,2:closing s3270 pipe,3:thread not avail              //~v8@rR~
//****************************************************************
int isthreadbusy(int Popt,PTHREADTB Ppthtb)
{
	int rc;
//**************************
LOCK_ENTER_THREAD();
	rc=(   Ppthtb->THThthread		//thread active
       &&  Ppthtb->THTchildph		//child process active
       && !Ppthtb->THTexitcode     //thread not exit
	   &&  Ppthtb->THTrc==THTRC_SUBPENDING); //in progress
	if (rc)	//busy                                                 //~v8@eR~
		if (Ppthtb->THTflag & THTF_CLOSE) //close requested but s3270 process not yet terminate//~v8@eR~
        	rc=2;     //busy                                       //~v8@eR~
	if (Popt & ISBUSY_AVAIL)                                       //~v8@rR~
		if (!Ppthtb->THThthread		//thread inactive              //~v8@rI~
        ||  !Ppthtb->THTchildph		//child process inactive       //~v8@rI~
        ||   Ppthtb->THTexitcode     //thread exit                 //~v8@rI~
		||   (Ppthtb->THTflag & THTF_CLOSE) //close requested but s3270 process not yet terminate//~v8@rI~
        )                                                          //~v8@rI~
        	rc=3;                                                  //~v8@rI~
	if (!rc)	//free
		if (Popt & ISBUSY_SET)
	    	Ppthtb->THTrc=THTRC_SUBPENDING;	//requested process
LOCK_LEAVE_THREAD();
    if (Popt & ISBUSY_MSG)
	    if (rc)
        {                                                          //~v8@eI~
		  if (rc==3) //close requested but s3270 process not yet terminate//~v8@rI~
    	    uerrmsgmt(1,"%s-%s is not avail,please logon",0,       //~v8@rI~
                    THT_HOSTNAME(Ppthtb),Ppthtb->THTusername);     //~v8@rI~
          else                                                     //~v8@rI~
		  if (rc==2) //close requested but s3270 process not yet terminate//~v8@eR~
    	    uerrmsgmt(1,"%s-%s is busy now waiting s3270 termination",0,//~v8@eI~
                    THT_HOSTNAME(Ppthtb),Ppthtb->THTusername);     //~v8@eI~
          else                                                     //~v8@eI~
    	    uerrmsgmt(1,"%s-%s is busy now,try later or after cancel",0,
//                  Ppthtb->THThostname,Ppthtb->THTusername);      //~v8@3R~
                    THT_HOSTNAME(Ppthtb),Ppthtb->THTusername);     //~v8@3R~
        }                                                          //~v8@eI~
    return rc;
}//isthreadbusy
//****************************************************************
//*search available thread table
//*ret entry index;-1:waiting thread end,max:no free entry
//****************************************************************
//int clearthtb(PTHREADTB Ppthtb)                                  //~v715R~
int clearthtb(int Pfullclearsw,PTHREADTB Ppthtb)                   //~v715R~
{
#ifdef LNX                                                         //~v715M~
    ULONG ecblist[3];                                              //~v715I~
#else                                                              //~v715I~
//  ULONG ecblist[2];                                              //~vafkR~
    ULPTR ecblist[2];                                              //~vafkI~
#endif                                                             //~v715M~
	THREADTB svthtb;                                               //~v715I~
//********************
UTRACEP("clearthreadtb\n");                                        //~v715I~
	if (uevent(UEVENTO_INIT,2,ecblist,0,0))				//init ecblist
    {
    	Ppthtb->THTflag|=THTF_NOTAVAIL;
    	return 4;
    }
//  id=Ppthtb->THTseqid;	//keep seqid                           //~v715R~
    memcpy(&svthtb,Ppthtb,THREADTBSZ);                             //~v715R~
    memset(Ppthtb,0,THREADTBSZ);
//  Ppthtb->THTseqid=id;                                           //~v715R~
    Ppthtb->THTseqid=svthtb.THTseqid;                              //~v715R~
	Ppthtb->THTecbm2s=ecblist[0];
	Ppthtb->THTecbs2m=ecblist[1];
#ifdef LNX                                                         //~v715I~
	if (uevent(UEVENTO_INIT|UEVENTO_MANUALRESET,1,ecblist,0,0))				//init ecblist//~v716I~
    {                                                              //~v716I~
    	Ppthtb->THTflag|=THTF_NOTAVAIL;                            //~v716I~
    	return 4;                                                  //~v716I~
    }                                                              //~v716I~
	Ppthtb->THTecbkill=ecblist[0];                                 //~v716R~
#endif                                                             //~v715I~
    if (!Pfullclearsw)                                             //~v715I~
    {                                                              //~v715I~
	    memcpy(Ppthtb->THThostname,svthtb.THThostname,THTHOSTNAMESZ);//~v715R~
	    memcpy(Ppthtb->THThostname2,svthtb.THThostname2,THTHOSTNAMESZ);//~v8@3I~
	    memcpy(Ppthtb->THTusername,svthtb.THTusername,THTUSERNAMESZ);//~v715R~
    	Ppthtb->THTchildph=svthtb.THTchildph;                      //~v715I~
#ifdef LNX                                                         //~v715I~
    	Ppthtb->THTkillph=svthtb.THTkillph;                        //~v715I~
#endif                                                             //~v715I~
    }                                                              //~v715I~
    return 0;
}//clearthreadtb
//****************************************************************
//*kick sub thread
//*parm:timeout by seconds
//****************************************************************
int awakethread(PTHREADTB Ppthtb,int Preqcode,int Ptimeout)
{
//  ULONG ecblist[1];                                              //~vafkR~
    ULPTR ecblist[1];                                              //~vafkI~
    int rc,timeout;
//*******************
    Ppthtb->THTrespdata=0;                                         //~v716R~
UTRACEP("awke req=%d,timeout=%d seqid=%d\n",Ppthtb->THTreqcode,Ptimeout,Ppthtb->THTseqid);
UTRACEP("awke thread=%p,exitcode=%d\n",Ppthtb->THThthread,Ppthtb->THTexitcode);//~v8@eR~
    if (!Ppthtb->THThthread
    ||  Ppthtb->THTexitcode)
    {
UTRACEP("awke return by thread inactive\n");
    	return 4;
    }
    Slastpthtb=Ppthtb;                                             //~v715R~
	if (isthreadbusy(ISBUSY_MSG|ISBUSY_SET,Ppthtb))
    	return 4;
    ecblist[0]=Ppthtb->THTecbs2m;
	if (uevent(UEVENTO_RESET,1,ecblist,0,0))		//reset posted after timeout
    {
	    Ppthtb->THTrc=THTRC_OTHERERR; 	//reset thread busy
    	return 4;
    }
    Ppthtb->THTreqcode=Preqcode;
    ecblist[0]=Ppthtb->THTecbm2s;
LOCK_ENTER();
LOCK_LEAVE();     //fflush stdout
#ifdef LNX                                                         //~v715I~
UTRACED("awakek post ecb before ",Ppthtb->THTecbm2s,UEVENTCBSZ);   //~v715I~
#endif                                                             //~v715I~
	if (uevent(UEVENTO_POST,1,ecblist,0,0))			//raise subthread
    {
	    Ppthtb->THTrc=THTRC_OTHERERR; 	//reset thread busy
    	return 4;
    }
#ifdef LNX                                                         //~v715I~
UTRACED("awakek post ecb after",Ppthtb->THTecbm2s,UEVENTCBSZ);     //~v715I~
#endif                                                             //~v715I~
//wait
    if (Ptimeout>0)
		timeout=Ptimeout*TIMEOUT_UNIT+TIMEOUT_OVERHEAD;
    else
    	timeout=Ptimeout;	//keep,-1,0
    if (iscmdthread())   //req by stdin cmd                        //~v72hI~
		Ppthtb->THTflag|=THTF_CMDTHREAD;        //req frm cmd thread//~v72hI~
    else                                                           //~v72hI~
		Ppthtb->THTflag&=~THTF_CMDTHREAD;        //req frm cmd thread//~v72hI~
    ecblist[0]=Ppthtb->THTecbs2m;
	Ppthtb->THTflag&=~THTF_TIMEOUT;	//cleanup requred
UTRACEP("awke postback wait timeout=%d\n",timeout);
#ifdef LNX                                                         //~v715I~
UTRACED("awakek wait ecb before",Ppthtb->THTecbs2m,UEVENTCBSZ);    //~v715I~
#endif                                                             //~v715I~
	rc=uevent(UEVENTO_WAIT,1,ecblist,timeout,0);	//o:exc index out
UTRACEP("awake postback rc=0x%x\n",rc);                            //~v715R~
#ifdef LNX                                                         //~v715I~
UTRACED("awakek wait ecb after",Ppthtb->THTecbs2m,UEVENTCBSZ);     //~v715I~
#endif                                                             //~v715I~
    switch (rc)
    {
    case  UEVENTRC_TIMEOUT:
UTRACEP("awke timeout\n");
    	uerrmsgmt(0,"TIMEOUT! Thread req(%d) for host=%s user=%s\n",0,//~v8@3R~
          		Ppthtb->THTreqcode,THT_HOSTNAME(Ppthtb),Ppthtb->THTusername);//~v8@3I~
		Ppthtb->THTflag|=THTF_TIMEOUT;	//cleanup requred
    	return THTRC_TIMEOUT;
    case  UEVENTRC_ABANDONED:	//thread terminated
UTRACEP("awke abandon\n");
    	uerrmsgmt(1,"Thread req(%d) for host=%s user=%s terminated",0,
//        		Ppthtb->THTreqcode,Ppthtb->THThostname,Ppthtb->THTusername);//~v8@3R~
          		Ppthtb->THTreqcode,THT_HOSTNAME(Ppthtb),Ppthtb->THTusername);//~v8@3I~
//      clearthtb(Ppthtb);                                         //~v715R~
        clearthtb(0,Ppthtb);                                       //~v715I~
        return 4;
    }
    rc=Ppthtb->THTrc;
UTRACEP("awke rc=%d\n",rc);
    if (rc==THTRC_SUBEXIT)	//subthread exit                       //~v715R~
        clearthtb(0,Ppthtb);                                       //~v715R~
    return rc;
}//awakethread
//****************************************************************
//*signal to main thread
//****************************************************************
int postbackmain(PTHREADTB Ppthtb,int Prc)
{
//  ULONG ecblist[1];                                              //~vafkR~
    ULPTR ecblist[1];                                              //~vafkI~
//*******************
UTRACEP("postback rc=%d\n",Prc);
    ecblist[0]=Ppthtb->THTecbs2m;
    Ppthtb->THTrc=Prc;
	if (uevent(UEVENTO_POST,1,ecblist,0,0))			//rase subthread
    	exitthread(Ppthtb,THTEC_POSTBACKERR);
UTRACEP("postback exit\n");
    return Prc;
}//postbackmain
//****************************************************************
//*exit sub thread
//****************************************************************
void exitthread(PTHREADTB Ppthtb,int Prc)
{
UTRACEP("exit thread rc=%d,thid=%x\n",Prc,Ppthtb->THThthread);     //~v8@eR~
    uerrmsgmt(0,"Thread terminated rc=%d,thread seqno=%d\n",0,     //~v8@eR~
				Prc,Ppthtb->THTseqid);                             //~v8@eR~
	uerrmsgmt(0,"\n==>",0);                                        //~vafjI~
    Ppthtb->THTexitcode=Prc;
#ifdef LNX                                                         //~v715I~
    pthread_exit(NULL);                                            //~v715I~
#else                                                              //~v715I~
    _endthread();
#endif                                                             //~v715I~
    return;
}//exitthread
//****************************************************************
//*cmdforme
//*excute cmd for myself(cd etc,env setup)
//****************************************************************
int apierr(char *Papiname,char *Pparm,int Prcid)                   //~v715R~
{
	int rc;
    char *preason;
//*****************
	if (Prcid)
    {
    	rc=errno;
        preason=uerrornomsg(rc);
    }
    else
    {
    	rc=-1;	//issue GetLastError
//    	preason=ugetlasterror(&rc);                                //~v715R~
       	preason=ugeterrdescription(1,&rc);	//1:gaetlasterr option ignored for LNX//~v715R~
    }
  if (Pparm)                                                       //~v715I~
	uerrmsgmt(1,"%s for %s failed with rc=%d(%s)",0,               //~v715I~
			Papiname,Pparm,rc,preason);                            //~v715I~
  else                                                             //~v715I~
	uerrmsgmt(1,"%s failed with rc=%d(%s)",0,
			Papiname,rc,preason);
    return 4;
}
//****************************************************************
//*uerrmsg for multithread
//*excute cmd for myself(cd etc,env setup)
//*opt 1:prefix title,2:crlf only
//****************************************************************
char *uerrmsgmt(int Popt,char *Pemsg ,char *Pjmsg,... )
{
static FILE *Sfhlog=0;
//  unsigned long **parm;                                          //~vafiR~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~vafiI~//~vafkR~
    ULPTR         parm[UERRMSG_MAXPARM];                           //~vafkI~
    char *pmsg;
    char *pmsgold=0;                                               //~v8@3I~
    int ftperrsw;                                                  //~v8@5I~
//****************************
	ftperrsw=Popt & UEMO_FTPERR;                                   //~v8@5I~
    Popt &=~UEMO_FTPERR;                                           //~v8@5I~
    LOCK_ENTER();
//  parm=(unsigned long**)(ULONG)((&Pjmsg)+1);                     //~vafiR~
//	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~vafiI~//~vafkR~
	UGETSTDARG(ULPTR        ,parm,Pjmsg,UERRMSG_MAXPARM);          //~vafkI~
    Serrmsgmtopt=Popt;
    if (Popt)
		pmsg=uerrmsg(Pemsg,Pjmsg,parm[0],parm[1],parm[2],parm[3],parm[4],
	             parm[5],parm[6],parm[7],parm[8],parm[9]);
    else
    {                                                              //~v8@3I~
        if (pmsgold=ugeterrmsg2(),pmsgold) //errmsg called         //~v8@3I~
            strncpy(Serrmsgwk,pmsgold,sizeof(Serrmsgwk)-1);        //~v8@3I~
//  	printf((pmsg=uerrsprintf(Pemsg,Pjmsg,parm[0],parm[1],parm[2],parm[3],parm[4],//~v737R~
//               parm[5],parm[6],parm[7],parm[8],parm[9])));       //~v737R~
    	printf("%s",(pmsg=uerrsprintf(Pemsg,Pjmsg,parm[0],parm[1],parm[2],parm[3],parm[4],//~v737R~
                 parm[5],parm[6],parm[7],parm[8],parm[9])));       //~v737R~
    }                                                              //~v8@3I~
	if (Smainopt & XE3270OPT_LOG)	//no pipe parametrr
    {
    	if (!Sfhlog)
        {
            if (Smainopt & XE3270OPT_APPENDLOG)
	        	Sfhlog=fopen(Slogfnm,"a");	//append mode
            else
	        	Sfhlog=fopen(Slogfnm,"w");	//append mode
            if (!Sfhlog)
            {
            	uerrmsg("logfile %s open failed,logging terminated",0,
                		Slogfnm);
				Smainopt &=~ XE3270OPT_LOG;
            }
            else
//	        	fprintf(Sfhlog,">>>>> %s Logging start %s <<<<<\n",PGM,(char*)(ULONG)utimeedit("YYYY/MM/DD",0));//~v715R~//~vafkR~
	        	fprintf(Sfhlog,">>>>> %s Logging start %s <<<<<\n",PGM,(char*)(ULPTR)utimeedit("YYYY/MM/DD",0));//~vafkI~
        }
    	if (Sfhlog)
        {
	        fprintf(Sfhlog,"%s\n",pmsg);
            fflush(Sfhlog);
        }
    }
    if (pmsgold) //errmsg called                                   //~v8@3I~
    	strcpy(pmsgold,Serrmsgwk);                                 //~v8@3I~
    if (ftperrsw)                                                  //~v8@5I~
	    ftperrlog(0);                                              //~v8@5I~
    LOCK_LEAVE();
UTRACEP("uerrmsgmt:opt=%d,%s\n",Popt,pmsg);                        //~v8@3R~
UTRACEP("uerrmsgmt:stat=%s\n",ugeterrmsg2());                      //~v8@3I~
	return pmsg;
}
#ifdef LNX                                                         //~v715R~
//**************************************************************** //~v715I~
//block sigchild                                                   //~v715I~
//**************************************************************** //~v715I~
int sigblockchild(void)                                            //~v715I~
{                                                                  //~v715I~
//  sigset_t new;                                                //~v715R~//~vbvgR~
    sigset_t new={0};                                              //+vbvgR~
//***************************************                          //~v715I~
    if (pthread_sigmask(SIG_BLOCK,&new,NULL))                      //~v715I~
    	return apierr("pthread_sigmask",0,0);                      //~v715R~
	return 0;                                                      //~v715R~
}//sigblockchild                                                   //~v715R~
//**************************************************************** //~v715R~
//allocate client tbl                                              //~v715R~
//**************************************************************** //~v715R~
PCLIENTTB alloccltb(void)                                          //~v715R~
{                                                                  //~v715R~
	PCLIENTTB pcltb;                                               //~v715I~
//***************************************                          //~v715R~
    pcltb=umalloc(CLIENTTBSZ);  //F_OK:existance chk               //~v719R~
    memset(pcltb,0,CLIENTTBSZ);                                    //~v715R~
    pcltb->CLTseqno=++Smsgcnt;                                     //~v715R~
	return pcltb;                                                  //~v715R~
}//alloccltb;                                                      //~v715R~
//**************************************************************** //~v715R~
//free client tbl                                                  //~v715R~
//**************************************************************** //~v715R~
int freecltb(PCLIENTTB Ppcltb)                                     //~v715R~
{                                                                  //~v715R~
//***************************************                          //~v715R~
    ufree(Ppcltb);                                                 //~v719R~
	return 0;                                                      //~v715R~
}//alloccltb;                                                      //~v715R~
//**************************************************************** //~v715R~
//wait client connection(LNX)                                      //~v716R~
//**************************************************************** //~v715R~
int initpipe(void)                                                 //~v715R~
{                                                                  //~v715R~
    int rc;                                                        //~v715R~
//***************************************                          //~v715R~
//duplicated schedule chk                                          //~v715R~
    sprintf(Spipenamealibi,SERVERPIPELOCK,XE3270PIPE);             //~v715R~
    rc=access(Spipenamealibi,F_OK);  //F_OK:existance chk          //~v715R~
    if (rc!=-1)	//pipe exist                                       //~v715R~
    {                                                              //~v715R~
		if (Smainopt & XE3270OPT_UNLINK)                           //~v715I~
        {                                                          //~v715I~
		    deltempfile(Spipenamealibi);                           //~v715R~
	    	uerrmsgmt(1,"Existing pipe(%s) was cleared at start.",0,//~v715I~
    	    			Spipenamealibi);                           //~v715R~
        }                                                          //~v715I~
        else                                                       //~v715I~
        {                                                          //~v715I~
	    	uerrmsgmt(1,"duplicated searver schedule,Retry after delete pipe(%s)",0,//~v715R~
    	    			Spipenamealibi);                           //~v715R~
        	return 4;                                              //~v715R~
        }                                                          //~v715I~
    }                                                              //~v715R~
    deltempfile(XE3270PIPE);                                       //~v715I~
UTRACEP("mainpipe create\n");                                      //~v715I~
	if (!(Sfdpipemain=(int)pipecreate()))                          //~v715I~
        return 4;                                                  //~v715R~
UTRACEP("cmd thread pipe open\n");                                 //~v715I~
    Sfdpipenotify=open(XE3270PIPE,O_WRONLY);	//internal communication pipe//~v715R~
UTRACEP("cmd thread pipe open fd=%d,\n",Sfdpipemain);              //~v715I~
    if (Sfdpipenotify==-1)                                         //~v715R~
    	return apierr("open(cmd use pipe)",XE3270PIPE,0);          //~v715R~
	return 0;                                                      //~v715R~
}//initpipe                                                        //~v715R~
//**************************************************************** //~v715I~
//notify2main                                                      //~v715I~
//**************************************************************** //~v715I~
int notify2main(char *Pcmd)                                        //~v715I~
{                                                                  //~v715I~
    PIPEMSG pipemsg;                                               //~v715I~
    int len,writelen;                                              //~v715R~
//***************************************                          //~v715I~
UTRACEP("notify=%s\n",Pcmd);                                       //~v715I~
    pipemsg.pid=-1;                                                //~v715I~
//  len=strlen(Pcmd);                                              //~v715I~//~vazyR~
    len=(int)strlen(Pcmd);                                         //~vazyI~
//  memcpy(pipemsg.msg,Pcmd,len);                                  //~v715R~//~vazyR~
    memcpy(pipemsg.msg,Pcmd,(size_t)len);                          //~vazyI~
//  len+=sizeof(pipemsg.pid);                                      //~v715I~//~vazyR~
    len+=(int)sizeof(pipemsg.pid);                                 //~vazyI~
// 	writelen=write(Sfdpipenotify,&pipemsg,len);                    //~v715I~//~vazyR~
   	writelen=(int)write(Sfdpipenotify,&pipemsg,(size_t)len);       //~vazyR~
    if (writelen!=len)                                             //~v715I~
    	return apierr("notify write",0,0);                         //~v715R~
	return 0;                                                      //~v715I~
}//notify2main                                                     //~v715I~
//**************************************************************** //~v715R~
//reopen pipe after eof(all client closed) detected(LNX)           //~v716R~
//rc: err>0                                                        //~v715R~
//**************************************************************** //~v715R~
int pipereconnect(int Preconnectsw,PCLIENTTB pcltb)                //~v715R~
{                                                                  //~v715R~
	ULONG hpipe;                                                   //~v715R~
    int fd;                                                        //~v715R~
//*************************************                            //~v715R~
	hpipe=(ULONG)Sfdpipemain;                                      //~v715R~
    pipeclose(hpipe);                                              //~v715R~
    Sfdpipemain=0;                                                 //~v715R~
    if (!Preconnectsw)                                             //~v715R~
    	return 0;                                                  //~v715R~
    fd=open(XE3270PIPE,O_RDONLY|O_NONBLOCK);                       //~v715R~
    if (fd==-1)                                                    //~v715R~
    	return apierr("open(reconnect)",XE3270PIPE,0);             //~v715R~
	Sfdpipemain=fd;                                                //~v715R~
    return 0;                                                      //~v715R~
}//pipereconnect                                                   //~v715R~
//**************************************************************** //~v715R~
//reopen pipe after eof(all client closed) detected                //~v715R~
//rc: err>0                                                        //~v715R~
//**************************************************************** //~v715R~
int pipeconnect2client(PCLIENTTB pcltb)                            //~v715R~
{                                                                  //~v715R~
    int fd;                                                        //~v715R~
    char pipename2client[_MAX_PATH];                               //~v715R~
//*************************************                            //~v715R~
    sprintf(pipename2client,CLIENTPIPENAME,XE3270PIPE,pcltb->CLTpid);//~v715R~
    fd=open(pipename2client,O_WRONLY|O_NONBLOCK);	//dont waite client open//~v715R~
    if (fd==-1)                                                    //~v715R~
    	return apierr("open(write to client)",XE3270PIPE,0);       //~v715R~
	pcltb->CLThpipe=(UINT)fd;                                      //~v715R~
    return 0;                                                      //~v715R~
}//pipeconnect2client                                              //~v715R~
//**************************************************************** //~v715R~
//wait client connection                                           //~v715R~
//rc:err                                                           //~v715R~
//**************************************************************** //~v715R~
int connectwait(int *Ppidx)                                        //~v715R~
{                                                                  //~v715R~
	fd_set rfds;                                                   //~v715R~
    int rc;                                                        //~v715R~
//***************************************                          //~v715R~
UTRACEP("connectwait \n");                                         //~v715R~
	FD_ZERO(&rfds);                                                //~v715R~
//  FD_SET(Sfdpipemain,&rfds);     	//client msg accept            //~v715R~//~vazxR~
//  FD_SET((unsigned)Sfdpipemain,&rfds);     	//client msg accept//~vazxI~//~vb34R~
    UFD_SET(Sfdpipemain,&rfds);     	//client msg accept        //~vb34I~
    rc=select(Sfdpipemain+1,		//maxfd+1                      //~v715R~
				&rfds,              //read fd                      //~v715R~
				NULL,				//write fd                     //~v715R~
				NULL,				//exception fd                 //~v715I~
				NULL);   			//timeout:infinite             //~v715R~
    if (rc==-1)                                                    //~v715R~
    	return apierr("select(connectwait)",0,0);                  //~v715R~
    *Ppidx=0;                                                      //~v715R~
UTRACEP("connectwait exit\n");                                     //~v715I~
	return 0;                                                      //~v715R~
}//connectwait                                                     //~v715R~
//**************************************************************** //~v715R~
//wait client connection                                           //~v715R~
//rc:<0 err,4:reconnect                                            //~v715R~
//**************************************************************** //~v715R~
int msgread(PCLIENTTB Ppcltb,char *Pbuff,int Pbuffsz,int *Pplen)   //~v715R~
{                                                                  //~v715R~
    PPIPEMSG ppipemsg;                                             //~v715R~
    ULONG  hpipe;                                                  //~v715R~
    int readlen,offs,pid;                                          //~v715R~
//***************************************                          //~v715R~
    hpipe=(ULONG)Sfdpipemain;                                      //~v715R~
   	readlen=piperead(hpipe,Pbuff,Pbuffsz,Pplen);                   //~v715R~
UTRACEP("msgread:piperead len=%d\n",readlen);                      //~v71eI~
    if (readlen<0)                                                 //~v715R~
    	return -1;                                                 //~v715R~
    if (readlen==0)		//EOF(all clien closed)                    //~v715R~
    {                                                              //~v715R~
    	if (pipereconnect(1,Ppcltb))                               //~v715R~
	    	return -1;		//exit main                            //~v715R~
        return 4;                                                  //~v715R~
    }                                                              //~v715R~
//* determin client from msg                                       //~v715R~
	ppipemsg=(PPIPEMSG)(ULONG)Pbuff;                               //~v715R~
    pid=ppipemsg->pid;                                             //~v715R~
    offs=sizeof(ppipemsg->pid);                                    //~v715R~
//  memcpy(Pbuff,Pbuff+offs,readlen-offs);                         //~v715R~//~vazyR~
    memcpy(Pbuff,Pbuff+offs,(size_t)(readlen-offs));               //~vazyI~
    *(Pbuff+readlen-offs)=0;                                       //~v715R~
	Ppcltb->CLTstat=CLTS_CONNECTED;                                //~v715R~
    Ppcltb->CLTpid=pid;                                            //~v715R~
    *Pplen=readlen-offs;                                           //~v715R~
	return 0;                                                      //~v715R~
}//msgread                                                         //~v715R~
//**************************************************************** //~v715R~
//responce write,close pipe server to client(LNX)                  //~v715R~
//**************************************************************** //~v715R~
int msgwrite(PCLIENTTB Ppcltb,char *Pbuff,int Pbufflen,char *Pdata,int Pdatalen)//~v716R~
{                                                                  //~v715R~
    ULONG hpipe;                                                   //~v715R~
//***************************************                          //~v715R~
	if (pipeconnect2client(Ppcltb))                                //~v715R~
    	return 4;                                                  //~v715R~
    hpipe=Ppcltb->CLThpipe;                                        //~v715R~
	pipewrite(hpipe,Pbuff,Pbufflen);                               //~v716R~
    if (Pdatalen)                                                  //~v716R~
    {                                                              //~v716I~
UTRACED("respdata",Pdata,Pdatalen);                                //~v716R~
		pipewrite(hpipe,Pdata,Pdatalen);                           //~v716R~
    }                                                              //~v716I~
    pipeclose(hpipe);                                              //~v715R~
	return 0;                                                      //~v715R~
}//msgwrite                                                        //~v715R~
//**************************************************************** //~v715R~
//pipe create(LNX)                                                 //~v715R~
//**************************************************************** //~v715R~
ULONG pipecreate(void)                                             //~v715R~
{                                                                  //~v715R~
    int fd;                                                        //~v715R~
//*********************************                                //~v715R~
    if (mkfifo(Spipenamealibi,0777)==-1)                           //~v715R~
    {                                                              //~v715I~
    	apierr("mkfifo(AlibiPipe)",Spipenamealibi,0);              //~v715R~
        return 0;                                                  //~v715I~
    }                                                              //~v715I~
    if (mkfifo(XE3270PIPE,0777)==-1)                               //~v715R~
    {                                                              //~v715R~
    	apierr("mkfifo(ServerPipe)",XE3270PIPE,0);                 //~v715R~
        return 0;                                                  //~v715R~
    }                                                              //~v715R~
    fd=open(Spipenamealibi,O_RDONLY|O_NONBLOCK);//client open this pipe to chk server is active//~v715R~
    if (fd==-1)                                                    //~v715R~
    {                                                              //~v715R~
    	apierr("open(AlibiPipe)",Spipenamealibi,0);                //~v715R~
        return 0;                                                  //~v715R~
    }                                                              //~v715R~
    Sfdpipealibi=fd;                                               //~v715I~
    fd=open(XE3270PIPE,O_RDONLY|O_NONBLOCK);                       //~v715I~
    if (fd==-1)                                                    //~v715I~
    {                                                              //~v715I~
    	apierr("open(ServerPipe)",XE3270PIPE,0);                   //~v715I~
        return 0;                                                  //~v715I~
    }                                                              //~v715I~
    return (ULONG)fd;                                              //~v715R~
}//pipecreate                                                      //~v715R~
//**************************************************************** //~v715R~
//read from pipe                                                   //~v715R~
//**************************************************************** //~v715R~
int piperead(ULONG Phpipe,char *Pbuff,int Pbuffsz,int *Pplen)      //~v715R~
{                                                                  //~v715R~
    int fd;                                                        //~v715R~
   	int readlen;                                                   //~v715R~
//***************************************                          //~v715R~
	fd=(int)Phpipe;                                                //~v715R~
//  readlen=read(fd,Pbuff,Pbuffsz);                                //~v715R~//~vazyR~
    readlen=(int)read(fd,Pbuff,(size_t)Pbuffsz);                   //~vazyI~
   	if (readlen<0)                                                 //~v715R~
    {                                                              //~v715R~
		apierr("read(ServerPipe)",0,0);	//0:getlast err            //~v715R~
        return readlen;                                            //~v715R~
    }                                                              //~v715R~
    return readlen;                                                //~v715R~
}//piperead                                                        //~v715R~
//**************************************************************** //~v715R~
//write to from pipe                                               //~v715R~
//**************************************************************** //~v715R~
int pipewrite(ULONG Phpipe,char *Pbuff,int Plen)                   //~v715R~
{                                                                  //~v715R~
    int fd;                                                        //~v715R~
   	int writelen;                                                  //~v715R~
    int reslen;                                                    //~v71GI~
    char *pc;                                                      //~v71GI~
//***************************************                          //~v715R~
UTRACED("LNX pipewrite",Pbuff,Plen);                               //~v71GR~
	fd=(int)Phpipe;                                                //~v715R~
  for (reslen=Plen,pc=Pbuff;reslen>0;pc+=writelen,reslen-=writelen)//~v71GI~
  {                                                                //~v71GI~
//  writelen=write(fd,Pbuff,Plen);                                 //~v71GR~
//  writelen=write(fd,pc,reslen);                                  //~v71GI~//~vazyR~
    writelen=(int)write(fd,pc,(size_t)reslen);                     //~vazyI~
UTRACEP("written reqlen=%d written=%d,errno=%d\n",reslen,writelen,errno);//~v71GR~
UTRACED("written",pc,writelen);                                    //~v71GI~
    if (writelen==-1 && errno==EAGAIN)                             //~v71GR~
    {                                                              //~v71GI~
    	usleepms(100); //wait cmdthread help                       //~v71GI~
        writelen=0;                                                //~v71GI~
        continue;                                                  //~v71GI~
    }                                                              //~v71GI~
    if (writelen<=0)                                               //~v71GR~
    	break;                                                     //~v71GI~
  }                                                                //~v71GI~
// 	if (writelen!=Plen)                                            //~v71GR~
UTRACEP("pipewrite reslen=%d\n",reslen);                           //~v71GI~
   	if (reslen)                                                    //~v71GI~
		return apierr("write(ClientPipe)",0,0);	//0:getlast err    //~v715R~
    return 0;                                                      //~v715R~
}//pipewrite                                                       //~v715R~
//**************************************************************** //~v715R~
//pipe close                                                       //~v715R~
//**************************************************************** //~v715R~
int pipeclose(ULONG Phpipe)                                        //~v715R~
{                                                                  //~v715R~
    int fd;                                                        //~v715R~
//***************************************                          //~v715R~
	fd=(int)Phpipe;                                                //~v715R~
   	close(fd);                                                     //~v715R~
    return 0;                                                      //~v715R~
}//pipeclose                                                       //~v715R~
#else	//WIN                                                      //~v715R~
//****************************************************************
//wait client connection
//****************************************************************
int initpipe(void)
{
//  ULONG hpipe;                                                   //~vafkR~
    ULPTR hpipe;                                                   //~vafkI~
//  ULONG ecblist[1];                                              //~vafkR~
    ULPTR ecblist[1];                                              //~vafkI~
    int ii,rc;
    PCLIENTTB pcltb;
//***************************************
//duplicated schedule chk
    if (INVALID_HANDLE_VALUE!=CreateFile(XE3270PIPE,	//  	pipename,   // pipe name
         								GENERIC_READ,  // read and write access
         								0,              // no sharing
         								NULL,           // default security attributes
         								OPEN_EXISTING,  // opens existing pipe
         								0,              // default attributes
         								NULL))          // no template file
    {
    	uerrmsgmt(1,"duplicated searver schedule(%s createion failed)",0,//~v8@7R~
					XE3270PIPE);                                   //~v8@7I~
        return 4;
    }
   	for (ii=0,pcltb=Scltb;ii<MAX_3270CLIENT;ii++,pcltb++)
	{
        pcltb->CLTseqno=ii+1;
		if (uevent(UEVENTO_INIT|UEVENTO_MANUALRESET|UEVENTO_INITSIGNAL,1,ecblist,0,0))				//init ecblist
    		return 4;
        pcltb->CLThevent=(Smainecblist[ii]=ecblist[0]);
    	hpipe=pipecreate();
    	if (!hpipe)
    		return 4;
        pcltb->CLThpipe=hpipe;
   		if ((rc=pipeconnect(pcltb))>2)
	    	return 4;
   		pcltb->CLTstat=rc;
    }
    Smainecblist[MAX_3270CLIENT]=Sthtbcmd.THThthread;	//cmd thread at quit
	return 0;
}//initpipe
//****************************************************************
//one trx processed wait next client connection(WIN)               //~v716R~
//****************************************************************
int pipereconnect(int Preconnectsw,PCLIENTTB pcltb)
{
//  ULONG hpipe;                                                   //~vafkR~
    ULPTR hpipe;                                                   //~vafkI~
    int rc;
//*************************************
	hpipe=pcltb->CLThpipe;
UTRACEP("pipe reconnect hpipe=%x\n",hpipe);                        //~v72sI~
   	FlushFileBuffers((HANDLE)hpipe);                               //~v716I~
   	if (!DisconnectNamedPipe((HANDLE)hpipe))
    {
		apierr("DisconnectNamedPipe",0,0);	//0:getlast err        //~v715R~
//      return 4;                                                  //~v72sR~
    }
    if (!Preconnectsw)
    	return 0;
// Call a subroutine to connect to the new client.
   	if ((rc=pipeconnect(pcltb)>2))
		return 4;
   	pcltb->CLTstat=rc;
    return 0;
}//pipereconnect
//****************************************************************
//wait client connection
//****************************************************************
int connectwait(int *Ppidx)
{
    int rc,idx;
//***************************************
UTRACEP("msgwait event wait\n");
    rc=uevent(UEVENTO_WAIT,MAX_3270CLIENT+1,Smainecblist,TIMEOUT_INFINITE,&idx);
UTRACEP("msgwait event posted rc=%d,idx=%d\n",rc,idx);
    if (rc)
    	return -1;
    if (idx==MAX_3270CLIENT)		//cmd thread exit
    	return -1;	//process term
    *Ppidx=idx;
	return 0;
}//msgwait
//****************************************************************
//wait client connection
//****************************************************************
int msgread(PCLIENTTB Ppcltb,char *Pbuff,int Pbuffsz,int *Pplen)
{
//  ULONG  hpipe;                                                  //~vaz7R~
    ULPTR  hpipe;                                                  //~vaz7I~
//***************************************
    hpipe=Ppcltb->CLThpipe;
   	if (piperead(hpipe,Pbuff,Pbuffsz,Pplen))
    {
    	pipereconnect(1,Ppcltb);
    	return 4;
    }
	return 0;
}//msgread
//**************************************************************** //~v716I~
//wait client connection (WIN)                                     //~v716R~
//**************************************************************** //~v716I~
int msgwrite(PCLIENTTB Ppcltb,char *Pbuff,int Plen,char *Pdata,int Pdatalen)//~v716I~
{                                                                  //~v716I~
//  ULONG hpipe;                                                   //~vaz7R~
    ULPTR hpipe;                                                   //~vaz7I~
//***************************************                          //~v716I~
    hpipe=Ppcltb->CLThpipe;                                        //~v716I~
	if (pipewrite(hpipe,Pbuff,Plen))                               //~v716I~
    {                                                              //~v716I~
    	pipeclose(hpipe);                                          //~v716I~
    	return 4;                                                  //~v716I~
    }                                                              //~v716I~
    if (Pdatalen)                                                  //~v716I~
        if (pipewrite(hpipe,Pdata,Pdatalen))                       //~v716R~
        {                                                          //~v716R~
            pipeclose(hpipe);                                      //~v716R~
            return 4;                                              //~v716R~
        }                                                          //~v716R~
	return 0;                                                      //~v716I~
}//msgwrite                                                        //~v716I~
//****************************************************************
//pipe create
//****************************************************************
//ULONG pipecreate(void)                                           //~vafkR~
ULPTR pipecreate(void)                                             //~vafkI~
{
   	LPTSTR lpszPipename=XE3270PIPE;
    HANDLE hpipe;
//*********************************
   	hpipe=CreateNamedPipe(
          lpszPipename,             // pipe name
          FILE_FLAG_OVERLAPPED |    // async
          PIPE_ACCESS_DUPLEX,       // read/write access
          PIPE_TYPE_MESSAGE |       // message type pipe
          PIPE_READMODE_MESSAGE |   // message-read mode
          PIPE_WAIT,                // blocking mode
          MAX_3270CLIENT,               // max. instances
          PIPESIZE,                 // output buffer size
          PIPESIZE,                 // input buffer size
          TIMEOUT_PIPECONNECT,      // client time-out
          NULL);                    // default security attribute

   	if (hpipe==INVALID_HANDLE_VALUE)
    {
		apierr("CreateNamedPipe",lpszPipename,0);	//0:getlast err//~v715R~
        return 0;
    }
//  return (ULONG)hpipe;                                           //~vafkR~
    return (ULPTR)hpipe;                                           //~vafkI~
}//pipecreate                                                      //~v716R~
//****************************************************************
//wait cliemt connection
//rc=1:waiting,0:connected,4:err
//****************************************************************
int pipeconnect(PCLIENTTB Ppcltb)
{
	OVERLAPPED *pov;
//  ULONG hpipe;                                                   //~vafkR~
    ULPTR hpipe;                                                   //~vafkI~
    int rc;
//***************************************
	hpipe=Ppcltb->CLThpipe;
    pov=&(Ppcltb->CLToverlap);
	memset(pov,0,sizeof(OVERLAPPED));
	pov->hEvent=(HANDLE)(Ppcltb->CLThevent);
	rc=ConnectNamedPipe((HANDLE)hpipe,pov);	// Overlapped ConnectNamedPipe should return zero.
    if (rc)
    {
		apierr("ConnectNamedPipe",0,0);	//0:getlast err            //~v715R~
        CloseHandle((HANDLE)hpipe);
        return 4;
    }
   	switch (GetLastError())
   	{
    case ERROR_IO_PENDING:
		rc=CLTS_CONNECTING;
        break;
    case ERROR_PIPE_CONNECTED:
    	rc=CLTS_CONNECTED;
        uevent(UEVENTO_POST,1,&(Ppcltb->CLThevent),0,0);	//required?
        break;
    default:
		apierr("ConnectNamedPipe",0,0);	//0:getlast err            //~v715R~
        CloseHandle((HANDLE)hpipe);
        rc=4;
   	}
	return rc;
}//pipeconnect
//****************************************************************
//read from pipe
//****************************************************************
//int piperead(ULONG Phpipe,char *Pbuff,int Pbuffsz,int *Pplen)    //~vafkR~
int piperead(ULPTR Phpipe,char *Pbuff,int Pbuffsz,int *Pplen)      //~vafkI~
{
    HANDLE hpipe;
   	int rc;
    DWORD dwlen;                                                   //~vafgI~
//***************************************
	hpipe=(HANDLE)Phpipe;
	rc=ReadFile(
         		hpipe,        	// handle to pipe
         		Pbuff,    		// buffer to receive data
//       		Pbuffsz,	 	// size of buffer                  //~vafgR~
         		(DWORD)Pbuffsz,	 	// size of buffer              //~vafgI~
//       		Pplen, 			// number of bytes read            //~vafgR~
         		&dwlen, 			// number of bytes read        //~vafgI~
         		NULL);        	// not overlapped I/O
    *Pplen=(int)dwlen;                                             //~vafgI~
   	if (!rc)
		return apierr("ReadFile(ServerPipe)",0,0);	//0:getlast err//~v715R~
    return 0;
}//piperead
//****************************************************************
//write to from pipe WIN                                           //~v71GR~
//****************************************************************
//int pipewrite(ULONG Phpipe,char *Pbuff,int Plen)                 //~vafkR~
int pipewrite(ULPTR Phpipe,char *Pbuff,int Plen)                   //~vafkI~
{
    HANDLE hpipe;
   	int rc,writelen;
    DWORD dwlen;                                                   //~vafgI~
//***************************************
	hpipe=(HANDLE)Phpipe;
    rc=WriteFile(
         		hpipe,        	// handle to pipe
         		Pbuff,      	// buffer to write from
//         		Plen, 			// number of bytes to write        //~vafgR~
         		(DWORD)Plen, 			// number of bytes to write//~vafgI~
//       		&writelen,   	// number of bytes written         //~vafgR~
         		&dwlen,   	// number of bytes written             //~vafgI~
         		NULL);        	// not overlapped I/O
    writelen=(int)dwlen;                                           //~vafgI~
UTRACEP("WIN pipe write len=%d,rc=%d,writelen=%d\n",Plen,rc,writelen);//~v71GR~
   	if (!rc||writelen!=Plen)
		return apierr("WriteFile(Pipe)",0,0);	//0:getlast err    //~v715R~
    return 0;
}//pipewrite
//****************************************************************
//pipe close
//****************************************************************
//int pipeclose(ULONG Phpipe)                                      //~vafkR~
int pipeclose(ULPTR Phpipe)                                        //~vafkI~
{
    HANDLE hpipe;
//***************************************
	hpipe=(HANDLE)Phpipe;
   	FlushFileBuffers(hpipe);
   	DisconnectNamedPipe(hpipe);
   	CloseHandle(hpipe);
    return 0;
}//pipeclose
#endif //!LNX                                                      //~v715R~
//**********************************************************************//~vafvI~
//* write help msg                                                 //~vafvI~
//**********************************************************************//~vafvI~
void titlemsg(void)                                                //~vafvI~
{                                                                  //~vafvI~
    char *verdate=__DATE__;                                        //~vafvR~
//***********************                                          //~vafvI~
    uerrmsg_init(PGM ":v" VER,stdout,0);//msg to stdout            //~vafvR~
    uerrmsg("\n(%c%s) === 3270 Connection Process (%s) = by MIZUMAKI-machi ===",//~vafvR~
            "\n(%c%s) === 3270 接続プロセス (%s) ============= by 水巻マチ ==",//~vafvR~
            OSTYPE,                                                //~vafvI~
#ifdef ULIB64                                                      //~vafvI~
			"64",                                                  //~vafvI~
#elif defined(ULIB64X)                                             //~vafvI~
			"64",                                                  //~vafvI~
#else                                                              //~vafvI~
			"",                                                    //~vafvI~
#endif                                                             //~vafvI~
            verdate);                                              //~vafvI~
    return;                                                        //~vafvI~
}//titlemsg                                                        //~vafvI~
