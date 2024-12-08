//*CID://+vb30R~:                             update#=    5;       //~vb30R~
//****************************************************************
//xe3270.h
//****************************************************************
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vazw:150115 pid on Win64 is intptr_t                             //~vazwI~
//v9@9:080717 (BUG)3270:SNAP subcmd is treated as string input     //~v9@9I~
//v8@H:080629 3270:display cursor position for rsh mode            //~v8@HI~
//v8@D:080627 3270:(BUG)for the case multiple dest defined for same dest/user,set config option each time//~v8@DI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd(cmd->3270, add TSO/cmd)//~v8@BI~
//v8@y:080625 3270:line mode by READY detection on last line at snap3270//~v8@yI~
//v8@x:080625 3270:sometime FTP wait(readresp hung) free line may be required for READY mode//~v8@xI~
//v8@t:080623 3270:cursor move to =6 panel home for cmd(ftp,listds,..) input//~v8@tR~
//v8@m:080620 3270:check READY on last line(linemode or spf changes temporary to line mode for cmd resonse)//~v8@mI~
//v8@b:080614 3270:use wait output for timing problem              //~v8@6I~
//v8@6:080610 defines s3270 command string for each host           //~v8@6I~
//v8@5:080609 write ftp retry log to another log by append mode    //~v8@5I~
//v8@4:080609 for the case tso cmd response start from end of line of current(=6) panel(after logon panel err)//~v8@4I~
//v8@3:080602 receive also hostname on xehosts file to identify logon command//~v8@3I~
//v8@1:080526 (3270)TSOE support                                   //~v8@1I~
//v72F:061206 3270:test C3270                                      //~v72FI~
//v72E:061205 3270:add tso subcmd "cmd" to enter Enter/PA1 etc     //~v72EI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//v72u:061202 3270:tso spf cmd support                             //~v72uI~
//v72t:061202 (BUG)3270:abend when "FOLLOWING ALIAS NAME EXIST WITHOUT TRUE NAME" if using native LISTDS//~v72tI~
//v72h:061124 allow SEQ dataset update(upload)                     //~v72hI~
//v726:061118 3270:more FTP retry by config file specification     //~v726I~
//v71T:061112 3270:add also get confirmation(once get err(dup record) occured)//~v71TI~
//v71R:061111 3270:check after save by reloading and keep result in workdir//~v71RI~
//v71n:061020 3270:add alloc/free cmd                              //~v71nI~
//v71g:061014 3270:copy/move support                               //~v71gI~
//v71e:061011 3270:REname support                                  //~v71eI~
//v719:061004 dirlist DSN list support                             //~v719I~
//v715:060221 (LNX)3270 ftp support(hostfile,TSO command)          //~v715I~
//v70z:060904 3270 ftp support
//****************************************************************
//************************************
//#define XE3270_FTPCMDID ':'     //ftp cmd id                     //~v715R~
#ifdef LNX                                                         //~v715M~
	#define EM3270  		"s3270"		//emulator pgm             //~v715R~
	#define XE3270PIPE "/tmp/xe3270FIFO"                           //~v715M~
	#define XE3270_STARTCMD   "gnome-terminal -e \"%s\""           //~v715M~
#else                                                              //~v715M~
#define EM3270  		"s3270"		//emulator pgm
#define XE3270PIPE "\\\\.\\pipe\\xe3270"
	#define XE3270_STARTCMD   "start %s"                           //~v715I~
#endif                                                             //~v715I~
                                                                   //~v715I~
#define XE3270SERVER  "xe3270"
                                                                   //~v715M~

#define XE3270OPT_LOG           0x01
#define XE3270OPT_APPENDLOG     0x02
#define XE3270OPT_UNLINK        0x04                               //~v715R~
#define XE3270OPT_TRACE         0x08                               //~v715I~
#define XE3270OPT_TESTERRRESP   0x10                               //~v715R~
#define XE3270OPT_TESTNOTFOUND  0x20                               //~v715R~
//#define XE3270OPT_PUTCONFIRM    0x40      //confirm after put    //~v726R~
//#define XE3270OPT_GETCONFIRM    0x80      //confirm get(get twice)//~v726R~

#ifdef LNX                                                         //~v715I~
	#define MAX_3270CLIENT  1  //only one servaer pipe             //~v715I~
#else                                                              //~v715I~
#define MAX_3270CLIENT  10  //string pier to client
#endif                                                             //~v715I~
#define MAX_THREADTB    10 	//thread pier to 3270 emulator

#define XE3270_FTPRETRY_LOGFILE "xe3270ftp.errlog"                 //~v8@5I~
#define XE3270_DEFAULT_LOGFILE "xe3270.log"
#define XE3270_DEFAULT_PORTNO   3270
#define XE3270_SUBCMD_STRING    "Reply"
#define XE3270_SUBCMD_LOGON     "Logon"
#define XE3270_SUBCMD_LOGOFF    "Logoff"                           //~v72BI~
#define XE3270_SUBCMD_QUIT      "Quit"
#define XE3270_SUBCMD_ALLOC     "Alloc"                            //~v71nI~
#define XE3270_SUBCMD_FREE      "Free"                             //~v71nI~
#define XE3270_SUBCMD_SPF       "SPF"                              //~v72uI~
//#define XE3270_SUBCMD_CMD       "Cmd"                            //~v8@BR~
#define XE3270_SUBCMD_CMD       "TSO"                              //~v8@BR~
#define XE3270_SUBCMD_ACTION    "Action"                           //~v8@bI~
#define XE3270_SUBCMD_RSH       "RSH"                              //~v72BI~
#define XE3270_SUBCMD_SNAP      "SNAP"                             //~v9@9I~
#define XE3270_SUBCMD_QUERY     "QUERY"                            //~v8@BR~
#define XE3270_SUBMIT_WORK     "'XE3270.TEMP.SUBMIT'"              //~v8@BR~
#define XE3270_QUERY_SUBMITWORK  "SUBMITWORK"                      //~v8@BI~
#define XE3270_SUBCMD_ACTION2   '>'                                //~v8@HI~
                                                                   //~v72BI~
#define XE3270RSHOPT_FSMODE     0x01	//rsh fullscreen mode      //~v72BI~
                                                                   //~v719I~
#define MAX_SCREENSZ    8000   //16384                             //~v726R~
//*parameter operand index                                         //~v719M~
#define PARM_REQ       0                                           //~v719M~
#define PARM_HOST      1                                           //~v719M~
#define PARM_USER      2                                           //~v719M~
#define PARM_HOSTFILE  3                                           //~v719M~
#define PARM_LOCALFILE 4                                           //~v719M~
#define PARM_MINIMUM   5                                           //~v719M~
//******************************************************************//~v719I~
#define WORDCHK_REENTER     "REENTER"                              //~v719R~
#define WORDCHK_ENTER       "ENTER"                                //~v71eI~
#define WORDCHK_INUSE       "ENTER LOGON OR LOGOFF"                //~v719I~
#define WORDCHK_READY       "READY"                                //~v71eI~
#define WORDCHK_READY_SZ    5                                      //~v71eI~
#define WORDCHK_MEMBERNOTFOUND "DIRECTORY INFORMATION NOT"         //~v71eI~
#define WORDCHK_MEMBERNOTFOUND_SZ    25                            //~v71eI~
#define WORDCHK_NOTCAT      "NOT IN CAT"                           //~v71eI~
#define WORDCHK_FILEEXIST   "File exists"                          //~v71eI~
#define WORDCHK_DSINUSE     "ALREADY IN USE"                       //~v71nR~
#define WORDCHK_INVALIDALIAS     "THE FOLLOWING ALIAS"             //~v72tI~
#define WORDCHK_INVALIDALIAS_SZ  19                                //~v72tI~
//******************************************************************//~v71eI~
typedef struct _THREADTB {                                         //~v719M~
#define THTHOSTNAMESZ  32                                          //~v719M~
#define THTUSERNAMESZ  32                                          //~v719M~
							int  THTseqid;		//internal thread id(seqno from 1)//~v719M~
							char THThostname[THTHOSTNAMESZ];       //~v719M~
							char THThostname2[THTHOSTNAMESZ];      //~v8@3I~
//#define THT_HOSTNAME(ptht) (*((ptht)->THThostname2)?  \  //      //~v8@DR~
//                              (ptht)->THThostname2 :  \  //      //~v8@DR~
//                            (ptht)->THThostname  )               //~v8@DR~
#define THT_HOSTNAME(ptht)     (ptht)->THThostname                 //~v8@DI~
							char THTusername[THTUSERNAMESZ];       //~v719M~
                            int  THTport;	//portno               //~v719M~
                            int  THTflag;                          //~v719M~
#define THTF_TIMEOUT   0x01          //clear pending after timeout //~v719M~
#define THTF_NOTAVAIL  0x02          //do not use;ecb cleate failed//~v719M~
#define THTF_CONNECTED 0x04          //do not use;ecb cleate failed//~v719M~
#define THTF_LOGON     0x08          //do not use;ecb cleate failed//~v719M~
#define THTF_CLOSE     0x10          //do not use;ecb cleate failed//~v719M~
#define THTF_CMDTHREAD 0x20          //req frm cmd thread          //~v72hI~
                            int  THTflag2;                         //~v8@3I~
#define THTF2_OPTIONSET 0x0001        //option set from cfg file   //~v8@6R~
#define THTF2_SPF       0x0002        //all in spf panel           //~v8@3R~
#define THT_ISSPF(pthtb) (((pthtb)->THTflag2 & THTF2_SPF)!=0)       //spf panel mode//~v8@3R~
#define THTF2_NOPUTCONF 0x0004        //no put confirmation        //~v8@5I~
#define THTF2_NOGETCONF 0x0008        //no put confirmation        //~v8@5I~
#define THTF2_S3270CMD  0x0010        //s3270 cmd set from config  //~v8@6I~
#define THTF2_3AST      0x0020        //last line is "***"         //~v8@yI~
//                          ULONG THTecbm2s;    //event handle signal from mainthread to subthread//~v9@9R~
//                          ULONG THTecbs2m;    //event handle signal from subthread to mainthread//~v9@9R~
                            ULPTR THTecbm2s;    //event handle signal from mainthread to subthread//~v9@9I~
                            ULPTR THTecbs2m;    //event handle signal from subthread to mainthread//~v9@9I~
#ifdef LNX                                                         //~v719M~
                            ULONG THTecbkill;   //child kill wait SIGCHILD signal//~v719M~
#endif                                                             //~v719M~
//                          ULONG THTchildph;  //child process hProcess//~v719M~//~vazwR~
                       LONGHANDLE THTchildph;  //rc of spawn: LNX=int,Win=LONGHANDLE(intptr_t:32bit/64bit)//~vazwR~
#ifdef LNX                                                         //~vazwI~
                            ULONG THTkillph;   //kill requested pid//~v719M~
//#ifdef LNX                                                         //~v719M~//~vazwR~
                            pthread_t THThthread;  //thread handle //~v719M~
#else                                                              //~v719M~
//                          ULONG THThthread;  //thread handle     //~v9@9R~
                            ULPTR THThthread;  //thread handle     //~v9@9I~
#endif                                                             //~v719M~
#ifdef W32                                                         //~v719M~
                            int   THTchildpid; //child process pid //~v719M~
#endif                                                             //~v719M~
                            int   THTpipep2c;   //pipe parent->child//~v719M~
                            int   THTpipec2p;   //pipe chaild->parent//~v719M~
                            int   THTreqcode;   //request code     //~v719M~
                            void *THTparm; 	//req parm;            //~v719M~
                            int   THTrc; 		//thread rc        //~v719M~
#define THTRC_SUBPENDING -1          //thread pending              //~v719M~
#define THTRC_SUBNORMAL   0          //thread process returned     //~v719M~
#define THTRC_SUBERR      4          //thread process returned err //~v719M~
#define THTRC_SUBEXIT     8          //thread exit                 //~v719M~
#define THTRC_TIMEOUT    16                                        //~v719M~
#define THTRC_BUSY       20                                        //~v719M~
#define THTRC_OTHERERR   32                                        //~v719M~
                            int   THTexitcode;	//thread exitcode  //~v719M~
#define THTEC_NORMAL      1          //thread exit nomaly          //~v719M~
#define THTEC_CHILDEND    4          //thread exit by child process end//~v719M~
#define THTEC_POSTBACKERR 8          //thread exit by postback fail//~v719M~
#define THTEC_ERR        12          //thread exit by child process end//~v719M~
							int   THTrespdatalen;                  //~v719M~
							void *THTrespdata;                     //~v719M~
                            int   THTmaxrow;                       //~v719R~
                            int   THTcurrow;                       //~v719M~
                            int   THTcurcol;                       //~v8@HI~
                            int   THTreadyrow;                     //~v8@xI~
                            int   THTstartrow;//cmd entered row    //~v719I~
                            int   THTmaxcol;                       //~v8@4I~
                            int   THTcmdrow; //ispf cmd input line //~v8@4I~
                            int   THThosttblidx; //config host table index//~v8@6I~
                            ULONG THToption2;  //more option by SENDO_OPTION2//~v8@tI~
#define THTO2_CHKSPF6       0x01               //check panel is spf6//~v8@tI~
#define THTO2_SETSPF6       0x02               //change panel to SPF6//~v8@tR~
                            ULONG THToption2rc;      //return code by option2//~v8@tI~
#define THTO2RC_ONSPF6      0x01               //panel is on spf6  //~v8@tI~
                        } THREADTB,*PTHREADTB;                     //~v719M~
#define SENDO_SET_OPTION2(Popt,pthtb,opt2) \
                 pthtb->THToption2=(opt2),pthtb->THToption2rc=0,Popt|=(int)SENDO_OPTION2//~v8@tR~//+vb30R~
//               pthtb->THToption2=(opt2),pthtb->THToption2rc=0,Popt|=SENDO_OPTION2//+vb30I~
#define SENDO_CHK_OPTION2(Popt,pthtb,opt2) \
                 ((Popt & (int)SENDO_OPTION2) && (pthtb->THToption2 & opt2))//~v8@tR~//+vb30R~
//               ((Popt & SENDO_OPTION2) && (pthtb->THToption2 & opt2))//~vb30I~
#define SENDO_RESET_OPTION2(Popt) \
                 Popt&=~SENDO_OPTION2                              //~v8@tI~
#define SENDO_GET_OPTION2RC(pthtb) \
                 (pthtb->THToption2rc)                             //~v8@tR~
#define SENDO_SET_OPTION2RC(pthtb,rc2) \
                 pthtb->THToption2rc|=rc2                          //~v8@tR~
#define THREADTBSZ sizeof(THREADTB)                                //~v719M~
//******************************************************************//~v719I~
                                                                   //~v719M~
#define SENDO_SNAPPRINT     0x01                                   //~v719M~
#define SENDO_CASE          0x02                                   //~v719M~
#define SENDO_DROPSTATUS    0x04                                   //~v719M~
#define SENDO_RCHK_FTP      0x08     //chk response "complete"     //~v719M~
#define SENDO_PSWD          0x10     //hide pswd display           //~v719M~
#define SENDO_RCHK_FTPGET   0x20     //chk filenotfound            //~v719M~
#define SENDO_RCHK_FORMAT   0x40     //chk format status flag      //~v719M~
#define SENDO_WAIT_UNLOCK   0x0100    //wait unlock                //~v719M~
#define SENDO_WAIT_OUTPUT   0x0200    //wait unlock                //~v719M~
#define SENDO_WAIT_INPUTF   0x0400    //wait unlock                //~v719M~
#define SENDO_WAIT_DISCONN  0x0800    //wait unlock                //~v719M~
#define SENDO_SELECTROW     0x1000    //select line                //~v719I~
#define SENDO_REENTERCHK    0x2000    //chk REENTER response       //~v719R~
#define SENDO_UIDINUSECHK   0x4000    //chk USERID IN USE response //~v719I~
#define SENDO_BREAKREENTER  0x8000    //break if REENTER response  //~v71eI~
#define SENDO_ENTERCHK    0x010000    //chk ENTER response         //~v71eI~
#define SENDO_RSHMODE     0x020000    //get rsh response msg       //~v72BI~
#define SENDO_ERRMSGLINE  0x040000    //display err detected line by uerrmsgmt//~v8@1I~
#define SENDO_CHKSPF      0x100000    //getfulldata check current is spf panel//~v8@3I~
#define SENDO_TOPLINECHK  0x200000    //chk only screen topline    //~v8@3R~
#define SENDO_TOPSNAP     0x400000    //save topline by snap3270   //~v8@3I~
#define SENDO_NORESPMSG   0x800000    //display err to screen only not return to xe//~v8@3I~
#define SENDO_LOGON     0x01000000    //readychk from funclogon    //~v8@3I~
#define SENDO_FULLSCR   0x02000000    //snap full screen           //~v8@6I~
#define SENDO_NOWAIT    0x04000000    //ignore SENDO_WAIT_xxx      //~v8@6I~
#define SENDO_CHK3AST   0x08000000    //check *** on last line     //~v8@bI~
#define SENDO_CHKREADY  0x10000000    //check READY on last line   //~v8@mI~
#define SENDO_LOGOFF    0x20000000    //logof req                  //~v8@mI~
#define SENDO_CMDLINE   0x40000000    //postion to cmdline and clear//~v8@tR~
#define SENDO_OPTION2   0x80000000    //more option is set to THToption2//~v8@tI~
                                                                   //~v719M~
#define RECVRC_ERR           0x01        //cmd response "error"    //~v719M~
#define RECVRC_NOTCONNECT    0x02		//statrusline connect status//~v719M~
#define RECVRC_BUFFOVERFLOW  0x04		//buffer overflow          //~v719M~
#define RECVRC_NOTFORMATTED  0x08		//response to SENDO_FORMAT //~v719M~
#define RECVRC_NOTFOUND      0x10		//string not found         //~v8@mI~
#define RECVRC_TIMEOUT       0x20		//timeout                  //~v8@mI~
#define RECVRC_ERRMASK       0xff		//string not found         //~v8@mI~
#define RECVRC_REENTER     0x0100		//response to SENDO_FORMAT //~v8@mR~
#define RECVRC_3ASTERISK   0x0200		//response to SENDO_CHK3AST//~v8@mR~
#define RECVRC_READY       0x0400		//response to SENDO_CHKREADY//~v8@mR~
#define RECVRC_PRELOGON    0x0800		//screen is prelogon status//~v8@mR~
#define RECVRC_SPFNODATA   0x1000		//no tso cmd resonse data on spf panel//~v8@mI~
#define RECVRC_ONSPF6      0x2000		//on SPF =6 PANEL          //~v8@tR~
                                                                   //~v719M~
int iscmdthread();                                                 //~v719M~
