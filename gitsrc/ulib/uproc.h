//*CID://+v6M2R~:                             update#=  151;       //~v6M0R~//~v6M2R~
//************************************************************* //~5825I~
//*proc.h                                                       //~5A10R~
//************************************************************* //~5825I~
//v6M2:170824 (Bug)v6M0 faile if path is multiple devided by ";"/":"//~v6M2I~
//v6M0:170808 err "LoadLibrary failed for icuucxx"-=>loaddll using ICU_DATA param//~v6M0I~
//v6H8:170109 (BUG)FTP del dir fail(remains subdir)                //~v6H8I~
//v6xk:150115 (BUG:W32)spwanxx deplicated,use _spawnxx(return intptr_t, Linux returns int pid)//~v6xkI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6g4:120512 ICU api suffix for 4.2 is also 4_2 like as 4.0(4_2)  //~v6g4I~
//v6f8:120423 (Lnx)dll open option to load RTLD_NOW                //~v6f8I~
//v6b7:111015 (ARM)usend2app                                       //~v6b7I~
//v5nd:081009 (SYNH) external process ctl                          //~v5ndI~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5m2I~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v5kk:070531 (LNX)support Konsole as X-terminal                   //~v5kkI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5j6:060914 _pipe support stderr redirect                        //~v5j6I~
//v5j5:060914 named pipe server                                    //~v5j5I~
//v5j2:060911 usystem_cmdserversetup upport intemediate shell for xe3270(need cmd prompt)//~v5j2I~
//v5iv:060906 3270server support(2nd cmdserver)                    //~v5gcI~
//v5gc:050709 (LNX)child shell create function for spawn terminalsim screen//~v5gcI~
//v5g9:050708 (LNX)openwith support                                //~v5g9I~
//v5f5:041121 chk max cmd size for cmd to cmd server               //~v5ezI~
//v5ez:041107 rsh:shell script logging(not only filename)          //~v5ezI~
//v5ev:041031 ftp chmod:try rsh after setmod failed                //~v5evI~
//v5eu:041031 rsh support                                          //~v5ehI~
//v5cw:040516 (WXE)it should be notified to cmd server of cd drive id change//~v5cwI~
//v5cc:040414 (WXE)confirm xesyscmd.exe is alive before write to pipe//~v5ccI~
//v5by:040229 shellexecute(open with application by ext association) support//~v5byI~
//v5bx:040225 cmd server function for 1 dos prompt screen(ftp use this server)//~v5bxI~
//v5bv:040222 (FTP)use resident ftp client pgm because mdos prompt appear each time under WXE//~v5bvI~
//v5br:040219 (FTP)use spawn for alternative of system because cmd prompt screen apear.//~v5brI~
//v5ad:040105 support TZ=hhmm and DBCS=EUC/SJIS                    //~v5adI~
//v59t:031222 execute cmd by LANG=C environment to get english ftp responce msg//~v59tI~
//v59j:031108 ftp support:uspawn_pipe func(not completely tested)  //~v59jI~
//            setlinebuf(to detect child put is not effective because it is not inherited)//~v59jI~
//v59g:031103 keep temp file option for test                       //~v59gI~
//v59d:030816 ftp support                                          //~v59dI~
//v57B:030419 (LNX)no process chain when xe executed by shell      //~v57AI~
//v57A:030413 (LNX)TTY=pts/n under X(ptsn for kon,ttyn for console)//~v57AI~
//v57t:030125 buff size parm support to usystemcsh                 //~v57tI~
//v57q:030118 (WIN)usystemcsh support(create child subshell)       //~v57qI~
//v50H:010618 no msg option for spawn                              //~v50HI~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v50v:010422 konchk performance up                                //~v50vI~
//v428:010218 TLinux:ps operand is not same as SW3.5               //~v428I~
//v327 000820:LINUX support                                        //~v327I~
//v203:981128 func uextchk to hdr                                  //~v203I~
//v127:971207 new func ucmdnmcom(command name compare)             //~v127I~
//v065:970211:add uspawnvp to uproc                                //~v065I~
//v064:970210:uexecchk function add(current and path search for chk executable)//~v064I~
//*951010 new                                                   //~5A10I~
//************************************************************* //~5A10I~
#define UPROC_MAX_CMDSVRCMD  4096                                  //~v5ezR~
#define UPROC_MAX_CMDSVRCMD2 (UPROC_MAX_CMDSVRCMD+32)	//overhead //~v5ezR~
#define UPROC_MAX_CMDSVRBUF  (UPROC_MAX_CMDSVRCMD2+_MAX_PATH+_MAX_PATH)	//redirect specificatione//~v5ezR~
//#define MAX_STDOREC    1024   //stdout max record length           //~v5adI~//~v6H8R~
#define MAX_STDOREC    8448    //0x2100 for FTP_MAXPATH*2          //~v6H8I~
                                                                   //~v5adI~
#define UPROC_LANGC    0x8000 //set LANG=C to get english responce msg//~v59tI~
#define UPROC_NOOKMSG  0x4000                                      //~v50HI~
#define UPROC_NOMSG    0x2000                                      //~v50HI~
#define UPROC_KEEPTEMP 0x1000                                      //~v59gI~
#define UPROC_CVE2S    0x0800  //output conv EUC->SJIS required    //~v5adI~
#define UPROC_CVS2E    0x0400  //output conv EUC<-SJIS required    //~v5adI~
#define UPROC_LAZY     0x00010000  //start cmd server st cmd req   //~v5bxI~
#define UPROC_NOSVRUSE 0x00020000  //issue system call not by cmd server//~v5bxI~
#define UPROC_NOTIFY   0x00040000  //cmd to cmd server itself      //~v5cwI~
#define UPROC_APPENDSO 0x00080000  //append to redirect stdout     //~v5ehI~
#define UPROC_APPENDSE 0x00100000  //append to redirect stderr     //~v5ehI~
#define UPROC_PUFTPH   0x00200000  //hostname parm is PUFTPHOST    //~v5evR~
#define UPROC_RSHLOG   0x00400000  //log rsh output to ftplog      //~v5evI~
#define UPROC_STDE2O   0x00800000  //redirect stderr to stdout for psftp//~v61pI~
                                                                   //~v5maR~
#define UPROC_KEEPMODE 0x01000000  //recover stdi/stdo mode foe WINCON//~v5maR~
#define UPROC_NULLSI   0x02000000  //spawn redirect stdin to NULL  //~v5maR~
//*************************************************************    //~v50HI~
typedef struct _UPSINFO          // process info by ps cmd         //~v428I~
         {                                                         //~v428I~
         	struct _UPSINFO *UPSInext;	//next chain               //~v50vR~
            int   UPSIpid; 			//pid                          //~v428R~
            int   UPSIppid;       	//parent pid                   //~v428R~
            int   UPSIttyno;       	//tty no,-1 if pty             //~v428R~
            int   UPSIptyno;       	//pty no,-1 if tty             //~v428R~
            int   UPSIflag;       	//flags                        //~v57AI~
#define     UPSIFPTS    0x01      	//pts/n                        //~v57BR~
#define     UPSIFPTY    0x02      	//ttypn                        //~v57BI~
#define     UPSIFPATH   0x80      	//on parent pid path(once chked)//~v57AI~
            char *UPSIcmd;			//cmd                          //~v428R~
         } UPSINFO,*PUPSINFO;                                      //~v428I~
//****************************************************************//~5A10I~
int usystemcsh(int Popt,ULONG Pbuffsz);                            //~v57tI~
int usystem(char *Pcmd);                                        //~5A10R~
int usystem2(int Popt,char *Pcmd);                                 //~v50HI~
                                                                //~5A10I~
//****************************************************************//~5A10I~
//int uspawnl(int Pmodeflag,char *Ppathname,char *Parg0,...);      //~v6xkR~
LONGHANDLE uspawnl(int Pmodeflag,char *Ppathname,char *Parg0,...); //~v6xkI~
                                                                //~5A10I~
//****************************************************************//~5A10I~
//int uspawnlp(int Pmodeflag,char *Ppathname,char *Parg0,...);     //~v6xkR~
LONGHANDLE uspawnlp(int Pmodeflag,char *Ppathname,char *Parg0,...);//~v6xkI~
                                                                   //~v065R~
//**************************************************************** //~v065R~
//int uspawnvp(int Pmodeflag,char *Ppathname,char **Pargv);        //~v6xkR~
LONGHANDLE uspawnvp(int Pmodeflag,char *Ppathname,char **Pargv);   //~v6xkI~
                                                                   //~v065R~
//*********************************************************************//~v064I~
int uexecchk(char *Pfile,char *Pfullpath);                         //~v064I~
                                                                   //~v127I~
//*********************************************************************//~v203I~
#ifndef UNX                                                        //~v327I~
int uextchk(char *Pfile);                                          //~v203I~
#endif                                                             //~v327I~
                                                                   //~v203I~
//*********************************************************************//~v127I~
int ucmdnmcomp(char *Pstr1,char *Pstr2);                           //~v127I~
                                                                   //~v203I~
//*********************************************************************//~v203I~
#if defined(W32) || defined(OS2) || defined(UNX)                   //~v327R~
	int ugetexepath(UCHAR *Pfullpath);                             //~v203I~
#endif                                                             //~v203I~
                                                                   //~v428I~
#ifdef UNX                                                         //~v428I~
	int uproc_getpsinfo(char *Pcmd,PUPSINFO *Ppupsinfo);           //~v50vI~
	PUPSINFO uproc_srchpsinfo(int Popt,PUPSINFO Ppupsinfo,int Ppid);//~v57BR~
    #define UPSPSI_PPID     0x01  //search paprent pid             //~v57BI~
    #define UPSPSI_CONID    0x02  //search same tty(pts)           //~v57BR~
	#define UPSPSI_CONTTY   0x04  //ttyn search                    //~v57BI~
	#define UPSPSI_CONPTY   0x08  //ttypn search                   //~v57BI~
	#define UPSPSI_CONPTS   0x10  //pts search                     //~v57BI~
	void uproc_freepsinfo(PUPSINFO Ppupsinfo);                     //~v50vI~
//  int usystem_redirect(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr);//~v59dR~
#endif                                                             //~v428I~
//*********************************************************************//~v59jI~
int usystem_redirect(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr);//~v59dI~
//*********************************************************************//~v5brI~
int uspawn_redirect(int Popt,char *Pcmd,char *Pstdinfnm,           //~v5brR~
				char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr);//~v5brI~
                                                                   //~v5brI~
//*********************************************************************//~v5bvI~
int uproc_redirectoutchk(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr,//~v5bvI~
						char *Pstdofnm,char *Pstdefnm);            //~v5bvI~
#if defined(UNX) || defined(W32)                                   //~v59jI~
//*********************************************************************//~v59jI~
//int uspawnvp_pipe(int Popt,int *Ppids,char *Ppathname,char **Pargv);//~v6xkR~
int uspawnvp_pipe(int Popt,LONGHANDLE *Ppids,char *Ppathname,char **Pargv);//~v6xkI~
#define USP_STDIN     0x01                                         //~v59jI~
#define USP_STDOUT    0x02                                         //~v59jI~
#define USP_STDERR    0x04                                         //~v5j6I~
//*********************************************************************//~v59jI~
#ifdef AAA                                                         //~v6xkI~
int uspawnvp_pipeend(int *Ppids);                                //~v59jR~
#endif                                                             //~v6xkI~
//*********************************************************************//~v5bxI~
typedef int (CMDSVRCALLBACK)(int Popt,void *Pcallbackparm);        //~v5bxR~
#define CMDCB_INIT     0x01                                        //~v5bxI~
#define CMDCB_WRTER    0x02                                        //~v5bxI~
#define CMDCB_READERR  0x04                                        //~v5ndI~
int usystem_cmdserverinit(int Popt,CMDSVRCALLBACK *Ppcmdsvrcallback,char *Pserverpgm,int *Pppid,int *Ppfpipew,int *Ppfdpiper);//~v6xkR~
//*********************************************************************//~v5bxI~
//int usystem_cmdserverterm(int Ppid,int Ppfw,int Pfdr);           //~v5gcR~
int usystem_cmdserverterm(int Popt,int Ppid,int Pfdw,int Pfdr);  //~v5gcR~
//*********************************************************************//~v5bxI~
int usystem_cmdserversetup(int Popt,char *Pserverpgm,int *Pppid,int *Ppfpipew,int *Ppfdpiper);//~v5bxR~
//#define UPROC_SYSCMD_MIN  0x01		//minimize server console window//~v5j2R~
#define UPROC_SYSCMD_MIN    0x00000100  //minimize server console window//~v5j2I~
#define UPROC_SERVER2       0x00000200   //not for xesyscmd but for 3270//~v5j2I~
#define UPROC_NOREADPID     0x00000400   //bypass initial read to get pid//~v5j2I~
#define UPROC_BYSHELL       0x00000800   //through shell           //~v5j2I~
#define UPROC_ARGV          0x00001000   //parm by argv fmt        //~v5ivI~
#define UPROC_CALLBACK      0x00002000   //parm is callback function addr//~v5ivI~
                                                                   //~v5ivI~
#define UPROC_PIPE_P2C  -1L    //replace by parent->child pipe fd  //~v5ivI~
#define UPROC_PIPE_C2P  -2L    //                 <-               //~v5ivR~
typedef int/*pid*/(STARTSERVER_FUNC)(int opt,int Pchildread,int Pchildwrite);//~v5ivR~
//*********************************************************************//~v5bxI~
//int usystem_cmdserverreq(int Popt,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr);//~v5ccR~
int usystem_cmdserverreq(int Popt,int Ppid,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr);//~v6xkR~
int usystem_cmdserverreqwithoutbuff(int Popt,int Ppid,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr,char *Ppresbuff,int Prespbuffsz);//~v6xkR~
int usystem_cmdtocmdserver(int Popt,char *Pcmd);                   //~v5cwI~
#endif                                                             //~v59jI~
#ifdef W32                                                         //~v5byI~
//*********************************************************************//~v5byI~
int ushellexec(char *Pfname);                                      //~v5byR~
#endif                                                             //~v5byI~
#ifdef ARM                                                         //~v6b7I~
	int usend2app(int Popt,char *Pfile1,char *Pfile2);             //~v6b7I~
#endif                                                             //~v6b7I~
#ifdef LNX                                                         //~v5g9I~
//*********************************************************************//~v5g9I~
	int uproc_gvfsinit(void);                                      //~v5g9I~
//*********************************************************************//~v5g9I~
	int ushellexec(int Popt,char *Pfnm);                           //~v5g9R~
	#define USHEXE_CHKONLY   0x01                                  //~v5g9R~
	#define USHEXE_FORCETERM 0x02                                  //~v5g9I~
	#define USHEXE_NOMSG     0x04                                  //~v5g9I~
//*********************************************************************//~v5gcI~
	int usystemlnxterm(char *Poptions);                            //~v5gcI~
	int ulnxlgetshellpgm(int Popt,char *Pout);                     //~v5kkI~
    #define XGSP_SETDEFAULT   0x0100 //set default                 //~v5kkI~
	int ulnxxgettermpgmopt(int Popt,char *Pcmd,char *Pout);        //~v5kkI~
    #define XGTP_GETPGMNAME   0x0100 //output terminal emulator    //~v5kkR~
    #define XGTP_GETDEFAULT   0x0200 //get default                 //~v5kkI~
    #define XGTP_SETDEFAULT   0x0400 //set default                 //~v5kkR~
    #define XGTP_GETDEFAULTIX 0x00ff //tbl index to get default    //~v5kkI~
#endif                                                             //~v5g9I~
                                                                   //~v5jaI~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32) || defined(LNX)                                   //~v5jaI~
#ifdef LNX                                                         //~v5jaI~
	#define CLIENTPIPENAME  "%s-%d"                                //~v5jaI~
	#define SERVERPIPELOCK  "%s-DUPCHK"                            //~v5jaI~
	#define MAX_PIPEMSG     4096                                   //~v5jaI~
	typedef struct _PIPEMSG { int pid; char msg[MAX_PIPEMSG];} PIPEMSG,*PPIPEMSG;//~v5jaR~
#endif                                                             //~v5jaI~
	typedef struct _PIPERESPMSG {                                  //~v5jaR~
									int rc;                        //~v5jaI~
									int msglen;                    //~v5jaI~
									int datalen;                   //~v5jaI~
									char respmsg[1];} PIPERESPMSG,*PPIPERESPMSG;//~v5jaI~
    #define PIPERESPMSGHDRSZ (offsetof(PIPERESPMSG,respmsg))       //~v5jaI~
//int uprocconnect(int Popt,char *Pservercmd,char *Ppipename,ULONG *Pphandle);//~v5j5R~//~v6hhR~
int uprocconnect(int Popt,char *Pservercmd,char *Ppipename,ULPTR *Pphandle);//~v6hhI~
//int uprocpipeio(ULONG Phpipe,char *Psendmsg,char *Precvmsg,int Precvbuffsz,int *Ppreadlen);//~v5jaR~
//int uprocpipeio(ULONG *Phpipe,char *Ppipename,char *Psendmsg,      //~v5jaI~//~v6hhR~
int uprocpipeio(ULPTR *Phpipe,char *Ppipename,char *Psendmsg,      //~v6hhI~
				char *Precvmsg,int Precvbuffsz,int *Ppreadlen,char **Ppdata,int *Ppdatalen);//~v5jaR~
//int uprocdisconnect(ULONG Phpipe);                               //~v5jaR~
//int uprocdisconnect(ULONG *Phpipe,char *Ppipename);                //~v5jaI~//~v6hhR~
int uprocdisconnect(ULPTR *Phpipe,char *Ppipename);                //~v6hhI~
                                                                   //~v5jaI~
#endif                                                             //~v5j5I~
#if defined(W32) || defined(UNX)                                   //~v5jaI~
	void usleepms(int Pmilisec);                                   //~v5jaR~
  	int usystem_pidalivechk(int Ppid);                             //~v5ndR~
#endif                                                             //~v5jaI~
//*************************************************************************//~v5mPI~
//int uproc_loaddll(int Popt,char *Pdllname,char *Pversion,ULONG *Pphandle);//~v5mPI~//~v6hhR~
int uproc_loaddll(int Popt,char *Pdllname,char *Pversion,ULPTR *Pphandle);//~v6hhI~
#define UPLD_NOW      0x02         //RTLD_NOW                      //~v6f8I~
#define UPLD_ALTPATH  0x04         //LoadLibraryEx with LOAD_WITH_ALTERED_SEARCH_PATH//~v6M0I~
#define UPLD_DELEMSG  0x08         //ugeterrmsg to delete previous uerrmsg//~v6M2I~
#define UPLD_SETICUDATAENV 0x10    //Linux:set also ICU_DATA env var//+v6M2R~
int uproc_loaddllpath(int Popt,char *Ppath,char *Pdllname,char *Pversion,ULPTR *Pphandle);//~v6M0I~
//*************************************************************************//~v5mPI~
//int uproc_getdllproc(int Popt,ULONG Phandle,char *Pprocname,char *Pprocver,ULONG *Ppprocaddr);//~v5mPI~//~v6hhR~
int uproc_getdllproc(int Popt,ULPTR Phandle,char *Pprocname,char *Pprocver,ULPTR *Ppprocaddr);//~v6hhI~
//*************************************************************************//~v5mPI~
//int uproc_freedll(int Popt,ULONG Phandle);                         //~v5mPI~//~v6hhR~
int uproc_freedll(int Popt,ULPTR Phandle);                         //~v6hhI~
//*************************************************************************//~v5mPI~
//int uproc_getprocaddr(int Popt,char *Pdllname,char *Pdllversion,char *Pprocname,char *Pprocversion,ULONG *Pphandle,ULONG *Ppprocaddr);//~v5mPI~//~v6hhR~
int uproc_getprocaddr(int Popt,char *Pdllname,char *Pdllversion,char *Pprocname,char *Pprocversion,ULPTR *Pphandle,ULPTR *Ppprocaddr);//~v6hhI~
#define UPGPAO_FREE     0x01         //free handle                 //~v5mPI~
#define UPGPAO_NOW      0x02         //RTLD_NOW                    //~v6f8I~
#define UPGPAO_NOMSG    0x04         //no errmsg                   //~v6g4I~
//*************************************************************************//~v5mPI~
