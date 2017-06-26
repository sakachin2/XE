//*CID://+v79fR~:                                                  //~v79aR~//~v79fR~
//****************************************************************
//xe3270s.h (common to xe3270s and xe3270s2)                       //~v725R~
//****************************************************************
//v7af:081113 (3270) add "Continue" to logon err action to do not abandon logon//~v79fI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v9@b:080718 3270:no echo option for rsh cmd                      //~v9@bI~
//v9@3:080717 3270:expand initchild timeout 3-->10sec for 1st time after boot//~v9@3I~
//v8@U:080711 3270:change timeout value for logoff by string =X\n  //~v8@UI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd(cmd->3270, add TSO/cmd)//~v8@BI~
//v8@A:080626 3270:TSOE spfinfo has seconds of update timestamp    //~v8@AI~
//v8@z:080625 3270:EUC<->EBC conversion                            //~v8@zI~
//v8@y:080625 3270:line mode by READY detection on last line at snap3270//~v8@yI~
//v8@v:080624 3270:prelogon msg chk required for the case 522 abend logoff//~v8@vI~
//v8@r:080621 3270:use not prelogon msg but logon flag to chk already logon//~v8@rI~
//                 acsidentaly host down is rare for real host     //~v8@rI~
//                 (confirm connected each time)                   //~v8@rI~
//                 already logon msg is also needed                //~v8@rI~
//v8@p:080620 3270:split xe3270.c =.xe3270.c+xe3270f.c
//v8@k:080619 3270:ftp timeout change;because invalid dsn wait,-1 ==> 600sec//~v8@kI~
//v8@f:080618 no resonse msg when spf mode for rename              //~v8@bI~
//v8@b:080614 3270:use wait output for timing problem              //~v8@bI~
//v8@9:080613 3270:MoveCursor,Home,Tab support for action of logon logoff//~v8@9I~
//v8@8:080613 3270:cmdline row parameter                           //~v8@8I~
//v8@6:080610 defines s3270 command string for each host           //~v8@6I~
//v8@5:080609 write ftp retry log to another log by append mode    //~v8@5I~
//v8@3:080602 receive also hostname on xehosts file to identify logon command//~v8@1I~
//v8@1:080526 (3270)TSOE support                                   //~v8@1I~
//v763:070530 3270:putconfirm allow line split                     //~v763I~
//v72H:061206 3270:change FTP timeout foy sysincmd to same as req from xe//~v72HI~
//v72F:061206 3270:configuarable emulator name                     //~v72FI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72nI~
//v72i:061124 3270:timeout value is setable by cfg file            //~v72iI~
//v72h:061124 optionaly(cfg setup) allow SEQ dataset update(upload)//~v72hI~
//v727:061119 3270:optionaly use xe4s001z to list pds member       //~v727I~
//v725:061117 3270:conf file support                               //~v725I~
//****************************************************************
#ifdef GBL_XE3270                                                  //~v725I~
  #define EXT3                                                     //~v725R~
  #define INIT3(value) =value                                      //~v725R~
#else                                                              //~v725I~
  #define EXT3 extern                                              //~v725R~
  #define INIT3(value)                                             //~v725R~
#endif                                                             //~v725I~
                                                                   //~v725I~
#define NEXTLINE(pcout,pc) ((pcout=strchr(pc,'\n'))?++pcout:0)     //~v725M~
#define WORDTOP(pc) (pc+=strspn(pc," "))                           //~v725M~
#define WORDEND(pcout,pc) ((pcout=strpbrk(pc," \n"))?pcout:0)      //~v725M~
                                                                   //~v725I~
#define CONFXE3270   "xe3270.cfg"                                  //~v725I~
#define RETRYGETMAX      4                                         //~v725R~
#define RETRYPUTMAX      4                                         //~v725R~
#define RETRYGETMIN      0                                         //~v725R~
#define RETRYPUTMIN      0                                         //~v725R~
#define RETRYGETDEFAULT  2                                         //~v725R~
#define RETRYPUTDEFAULT  2                                         //~v725R~
                                                                   //~v72hI~
#define SPF6CMDROW         5   //cmdline row of =6 panel           //~v8@6I~
                                                                   //~v8@6I~
#define TIMEOUT_INFINITE     -1 //accept cancel after 1 sec        //~v72hM~
#define TIMEOUT_INITCHILD    10 //child start                      //~v9@3R~
#define TIMEOUT_CONNECT      10                                    //~v72iR~
#define TIMEOUT_TRANSFER   600//  -1 //accept cancel after 1 sec for req by stdincmd//~v8@kR~
//#define TIMEOUT_TRANSFER_STDINCMD  2 //ftp by stdin cmd          //~v72HR~
#define TIMEOUT_NOWAIT        0 //no timeout wait                  //~v72hM~
#define TIMEOUT_LOGON        10                                    //~v8@UR~
#define TIMEOUT_DISCONNECT    3                                    //~v72hM~
#define TIMEOUT_CHKENDPROCESS 5 //chk pid after kill               //~v8@bR~
#define TIMEOUT_UNIT       1000  //milisec                         //~v72hM~
#define TIMEOUT_OVERHEAD    200  //overhead for main, 200ms        //~v72hM~
#define TIMEOUT_ENDTHREAD     3                                    //~v72hM~
#define TIMEOUT_LOGOFF       10                                    //~v8@UR~
#define TIMEOUT_SNAP          3                                    //~v72hM~
#define TIMEOUT_CMD          10                                    //~v72hM~
#define TIMEOUT_STRING       10                                    //~v8@UR~
#define TIMEOUT_TSOCMD       30                                    //~v72iR~
#define TIMEOUT_PIPECONNECT  5000     //5sec                       //~v72hM~
#define TIMEOUT_OUTPUT       5        //5sec wait host update screen after cmd entered//~v8@bI~
#define TIMEOUT_OUTPUTFTP    1        //1sec wait host update screen after ftpcmd  entered//~v8@bI~
                                                                   //~v72hI~
#define CONFIGP_GETRETRY      "RETRY_DOWNLOAD"                     //~v725R~
#define CONFIGP_PUTRETRY      "RETRY_UPLOAD"                       //~v725R~
#define CONFIGP_CMDMEMBLIST   "CMD_MEMBLIST"                       //~v725I~
#define CONFIGP_PSUPLOAD      "PS_UPLOAD"                          //~v72hI~
#define CONFIGP_RSHECHO       "RSH_ECHO"                           //~v9@bI~
#define CONFIGP_TO_CONNECT    "TIMEOUT_CONNECT"                    //~v72iR~
#define CONFIGP_TO_FTP        "TIMEOUT_FTP"                        //~v72hI~
#define CONFIGP_TO_TSOCMD     "TIMEOUT_TSOCMD"                     //~v72hI~
#define CONFIGP_TO_LOGON      "TIMEOUT_LOGON"                      //~v8@1I~
#define CONFIGP_TO_LOGOFF     "TIMEOUT_LOGOFF"                     //~v8@1I~
#define CONFIGP_TO_DISCONN    "TIMEOUT_DISCONN"                    //~v8@9R~
#define CONFIGP_SPFLEVEL      "SPF_LEVEL"                          //~v72nI~
#define CONFIGP_CHARSETCFG    "CHARSET_CFG"                        //~v79aI~
#define CONFIGP_CMD3270       "CMD3270"                            //~v72FI~
#define CONFIGP_CMDLOGON      "LOGON_CMD"                          //~v8@1R~
#define CONFIGP_CMDLOGOFF     "LOGOFF_CMD"                         //~v8@1I~
#define CONFIGP_CMDLOGON_USER "%USER%"                             //~v8@1R~
#define CONFIGP_CMDLOGON_PSWD "%PSWD%"                             //~v8@1R~
#define CONFIGP_CMDLOGON_ERR  "LOGON_ERR"                          //~v8@1R~
#define CONFIGP_CMDLOGON_ALR  "TEXT_READY"                         //~v8@3R~
#define CONFIGP_CMDLOGON_PRE  "TEXT_PRELOGON"                      //~v8@vR~
#define CONFIGP_OPTIONS       "OPTIONS"                            //~v8@yR~
#define CONFIGP_CMDLINEROW    "CMD_ROW"                            //~v8@8I~
#define CONFIGP_CMDCMD        "Action "                            //~v8@9R~
#define CONFIGP_CMDSLEEP      "Sleep "                             //~v8@9R~
#define CONFIGP_CMDCONTINUE   "Continue"                           //~v79fI~
                                                                   //~v72nI~
#define WORDCHK_SPFUPDATEOK      "=======>"                        //~v72nR~
#define WORDCHK_SPFNEWCMD        "===>"    //cmd shell panel newcmd line text start id//~v8@bI~
#define WORDCHK_SPFOLDCMD        "=>"     //cmd shell panel old cmd text start id//~v8@bI~
#define WORDCHK_STRING           "String"                          //~v8@bI~
#define WORDCHK_ASCII            "Ascii"                           //~v8@bI~
#define WORDCHK_IKJ              "IKJ"                             //~v8@bI~
#define WORDCHK_PENDINGENTER     "***"                             //~v8@bI~
#define MAX_LOGONCMDNO         20   //logon cmd number             //~v8@9R~
#define MAX_LOGOFFCMDNO        20   //logon cmd number             //~v8@9R~
#define MAX_CHKMSGLEN          32   //resonse check msg text len   //~v8@1R~
#define MAX_LOGONERRMSGNO      20   //max logon err msg count      //~v8@9R~
//#define MAX_LOGONALREADYCHKNO   5   //max already logon check msg//~v8@rR~
#define MAX_PRELOGONNO          5   //max prelogon msgno           //~v8@vR~
#define MAX_HOST               20   //max dest                     //~v8@9R~
//#define MAX_OPTIONSNO    MAX_HOST   //max dest                   //~v8@9R~
#define MAX_ACTIONSZ           64   //max action size              //~v8@1R~
#define MAX_LOGONCMDSZ         64   //max action size              //~v8@9R~
#define TOPLINE_SAVEWIDTH  (24*80)  //write3270readresp output to check topline//~v8@1R~
#define   LOGONCMD_DEFAULT_RETRYNO      8  //logon response chk retry count default//~v8@bR~
#define   LOGOFFCMD_DEFAULT_RETRYNO     8  //logoff response chk retry count default//~v8@bR~
#define   ERRMSG_POSTCHKID   '_'           //chk after validmsg chk//+v79fR~
#define   OKMSG_OPTIONALID   '|'           //continue if even if not found//+v79fI~
//**************************************************************** //~v725I~
#define CMD_SEND          "Send"                                   //~v8@pI~
#define CMD_RECEIVE       "Receive"                                //~v8@pI~
#define CMD_SNAP          "Snap"                                   //~v8@pI~
#define CMD_ASCII         "Ascii"                                  //~v8@pI~
#define CMD_3270CMD       "3270"                                   //~v8@BI~
#define CMD_TSOCMD       XE3270_SUBCMD_CMD  //TSO                  //~v8@BR~
#define CMD_TSOCMD2       "Cmd"                                    //~v8@BI~
#define CMD_QUERY        XE3270_SUBCMD_QUERY //QUERY               //~v8@BI~
//**************************************************************** //~v8@pI~
enum THTRQCODE{                                                    //~v716I~
		 THTRQ_NOTACTIVE             // 0                          //~v716I~
		,THTRQ_INITCHILD             // 1                          //~v716I~
		,THTRQ_CONNECT               // 2                          //~v716I~
        ,THTRQ_LOGON                 // 3                          //~v716I~
        ,THTRQ_TRANSFER_GET          // 4                          //~v716I~
        ,THTRQ_TRANSFER_PUT          // 5                          //~v716I~
        ,THTRQ_SNAP                  // 6                          //~v716I~
        ,THTRQ_CMD                   // 7                          //~v716I~
        ,THTRQ_STRING                // 8                          //~v716I~
        ,THTRQ_LOGOFF                // 9                          //~v716I~
        ,THTRQ_DISCONNECT            // 10                         //~v716I~
        ,THTRQ_ENDTHREAD             // 11                         //~v716I~
        ,THTRQ_TSOCMD_LISTDS         // 12                         //~v716I~
        ,THTRQ_TSOCMD_RENAME         // 13                         //~v71eI~
        ,THTRQ_TSOCMD_DELETE         // 14                         //~v71eI~
        ,THTRQ_TSOCMD_ALLOCATE       // 15                         //~v71nI~
        ,THTRQ_TSOCMD_FREE           // 16                         //~v71nI~
        ,THTRQ_TSOCMD_SPF            // 17                         //~v72nI~
        ,THTRQ_RSH                   // 18                         //~v72BI~
//      ,THTRQ_NOTDEFINED            // 19                         //~v8@BR~
        ,THTRQ_TSOCMD_TSO            // 19                         //~v8@BI~
//      ,THTRQ_NOTDEFINED            // 20                         //~v8@BR~
        ,THTRQ_TSOCMD_QUERY          // 20                         //~v8@BI~
        ,THTRQ_NOTDEFINED            // 21                         //~v8@BI~
};                                                                 //~v716R~
//****************************************************************
typedef struct _CONFDEST    {   //config parm for each destination //~v8@9I~
                        		char  CONFDhost[THTHOSTNAMESZ];   //dest name//~v8@9I~
								ULONG CONFDoptions;                //~v8@9I~
								char *CONFDemulator;               //~v8@9R~
    							int   CONFDprelogonno;             //~v8@vR~
    							char *CONFDlogonprelogontbl[MAX_PRELOGONNO];//~v8@vR~
//  							int   CONFDlogonalreadychkno;      //~v8@rR~
//  							char *CONFDlogonalreadychktbl[MAX_LOGONALREADYCHKNO];//~v8@rR~
								int   CONFDlogoncmdno;             //~v8@9I~
								char *CONFDlogoncmd[MAX_LOGONCMDNO];//~v8@9R~
								char *CONFDlogoncmdrespchk[MAX_LOGONCMDNO];//~v8@9I~
								int   CONFDlogoncmdrespchkretry[MAX_LOGONCMDNO];//~v8@9R~
								int   CONFDlogoncmderrmsgno;       //~v8@9I~
								char *CONFDlogoncmderrmsgtbl[MAX_LOGONERRMSGNO];//~v8@9I~
								char  CONFDlogoncmderraction[MAX_LOGONERRMSGNO][MAX_ACTIONSZ+1];//~v8@9I~
								int   CONFDlogoffcmdno;            //~v8@9I~
								char *CONFDlogoffcmd[MAX_LOGOFFCMDNO];//~v8@9R~
								char *CONFDlogoffcmdrespchk[MAX_LOGOFFCMDNO];//~v8@9I~
								int   CONFDlogoffcmdrespchkretry[MAX_LOGOFFCMDNO];//~v8@9I~
								char *CONFDsubmitwork;	//submit work;//~v8@BI~
                    } CONFDEST,*PCONFDEST;                         //~v8@9I~
//*****                                                            //~v8@9I~
EXT3 CONFDEST G3270confd[MAX_HOST];                                //~v8@9I~
EXT3 int      G3270confdno INIT3(1);    //default entry            //~v8@9R~
//**************************************************************** //~v8@1I~
EXT3 char G3270topline[TOPLINE_SAVEWIDTH+1];  //write3270readresp save topline data//~v8@1R~
EXT3 char G3270workdir[_MAX_PATH];                                 //~v725R~
EXT3 char G3270memblistcmd[MAX_CMDSZ];                             //~v725R~
EXT3 int  G3270retryget INIT3(RETRYGETDEFAULT);                    //~v725R~
EXT3 int  G3270retryput INIT3(RETRYPUTDEFAULT);                    //~v725I~
                                                                   //~v72iI~
EXT3 int  G3270opt;                                                //~v72hI~
#define G3270OPT_PSUPLOAD   0x01      //allow ps upload            //~v72iM~
#define G3270OPT_CMDLINET   0x02      //cmd line parm -T (transfer timeout) specified//~v72iR~
#define G3270OPT_CMDLINEC   0x04      //cmd line parm -C (connect  timeout) specified//~v72iR~
#define G3270OPT_SPFLVL1    0x10      //cfg parm (get spf info only)//~v72nR~
#define G3270OPT_SPFLVL2    0x20      //cfg parm (update spf info) //~v72nR~
#define G3270OPT_EUC        0x40      //cfg parm (update spf info) //~v8@zI~
#define G3270OPT_NORSHECHO  0x80      //no rsc cmd echo by performance reason//~v9@bI~
#define G3270OPT_DBCSJP     0x0100      //env is Japanese env      //~v79aR~
#define G3270OPT_DBCSOTHER  0x0200      //env is DBCS other than Japanese//~v79aI~
                                                                   //~v72iI~
EXT3 int  G3270to_connect INIT3(TIMEOUT_CONNECT);                  //~v72iR~
EXT3 int  G3270to_ftp     INIT3(TIMEOUT_TRANSFER);                 //~v72iR~
EXT3 int  G3270to_tsocmd  INIT3(TIMEOUT_TSOCMD);                   //~v72iR~
EXT3 int  G3270to_logon   INIT3(TIMEOUT_LOGON);                    //~v8@1I~
EXT3 int  G3270to_logoff  INIT3(TIMEOUT_LOGOFF);                   //~v8@1I~
EXT3 int  G3270to_disconn INIT3(TIMEOUT_DISCONNECT);               //~v8@9I~
EXT3 int  G3270to_output  INIT3(TIMEOUT_OUTPUT);                   //~v8@bI~
EXT3 int  G3270to_outputftp  INIT3(TIMEOUT_OUTPUTFTP);             //~v8@bI~
EXT3 int  G3270cmdrow INIT3(SPF6CMDROW);           //cmdline row of =6 panel//~v8@8I~
                                                                   //~v8@5I~
EXT3 char G3270ftperrlogfile[_MAX_PATH];                           //~v8@5R~
EXT3 PUCVEXTCFG G3270pmapcfg;                                      //~v79aR~
//**************************************************************** //~v725I~
typedef struct _SPFLINEFMT  {   //xe4s001z output member line format//~v727R~
                    char   SLFmember[8];                           //~v727R~
                    char   SLFsep1[2];                             //~v727R~
                    char   SLFver[2];       //version              //~v727R~
#define SLFVERALIAS     'A'                 //alias line           //~v727R~
#define SLFVERNOSPF     '-'                 //no spf data on directory//~v727R~
                    char   SLFsep2[1];                             //~v727R~
                    char   SLFmod[2];       //modification         //~v727R~
                    char   SLFsep3[2];                             //~v727R~
                    char   SLFcdate[8];     //creation date YY/MM/DD//~v727R~
                    char   SLFsep4[2];                             //~v727R~
                    char   SLFudate[8];     //update   date YY/MM/DD//~v727R~
                    char   SLFsep5[1];                             //~v727R~
//                  char   SLFutime[5];     //update   time hh:mm  //~v8@AR~
                    char   SLFutime[8];     //update   time hh:mm:ss//~v8@AI~
                    char   SLFsep6[2];                             //~v727R~
                    char   SLFlinecnt[11];     //current lineno    //~v727R~
                    char   SLFsep7[1];                             //~v727R~
                    char   SLFinitcnt[11]; //initial lineno        //~v727R~
                    char   SLFsep8[2];                             //~v727R~
                    char   SLFuserid[8];    //user id              //~v727R~
//                  char   SLFsep9[3];                             //~v8@AR~
                    } SPFLINEFMT,*PSPFLINEFMT;                     //~v727R~
typedef struct _DSLINEFMT  {   //xe4s001z output dataset info line format//~v727R~
                    char   DLFsep1[7];                             //~v727R~
                    char   DLFdsorg[2];     //dsorg                //~v727R~
                    char   DLFsep2[7];                             //~v727R~
                    char   DLFrecfm[2];     //recfm                //~v727R~
                    char   DLFsep3[7];                             //~v727R~
                    char   DLFlrecl[5];     //lrecl                //~v727R~
                    char   DLFsep4[9];                             //~v727R~
                    char   DLFblksz[5];     //blksize              //~v727R~
                    } DSLINEFMT,*PDSLINEFMT;                       //~v727R~
//**************************************************************** //~v8@9I~
int screenchkm(int Popt,PTHREADTB Ppthtb,char *Pvalidresp,int Ptextno,char **Ppptext);//~v8@9M~
//**************************************************************** //~v725I~
int funcalloc(PTHREADTB Ppthtb);                                   //~v725I~
//**************************************************************** //~v725I~
int funcfree(PTHREADTB Ppthtb);                                    //~v725M~
//**************************************************************** //~v725I~
int funcrename(PTHREADTB Ppthtb);                                  //~v725M~
//**************************************************************** //~v725I~
int funcdelete(PTHREADTB Ppthtb);                                  //~v725M~
//**************************************************************** //~v725I~
int functsocmd(PTHREADTB Ppthtb);                                  //~v8@BI~
//**************************************************************** //~v8@BI~
int funclistds(PTHREADTB Ppthtb);                                  //~v725M~
//**************************************************************** //~v72nI~
int funcspf(PTHREADTB Ppthtb);                                     //~v72nI~
//**************************************************************** //~v8@BI~
int funcquery(PTHREADTB Ppthtb);                                   //~v8@BI~
//**************************************************************** //~v725I~
int getfulldata(int Popt,PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz,int Prow,char **Poutbuff,int *Ppoutbufflen);//~v725M~
//**************************************************************** //~v725I~
int readconf(void);                                                //~v725I~
//**************************************************************** //~v763I~
int getlatestdsndata(char *Pdsn,PDSNDATA Ppdsnd);                  //~v763I~
//**************************************************************** //~v8@1I~
int funclogone(int Popt,PTHREADTB Ppthtb,char *Pcmdwk,char *Ppuserpswd);//~v8@1I~
//**************************************************************** //~v8@1I~
int funclogoffe(int Popt,PTHREADTB Ppthtb);                        //~v8@1I~
//**************************************************************** //~v8@1I~
int cmdreadychk(int Popt,PTHREADTB Ppthtb);                        //~v8@1I~
//**************************************************************** //~v8@1I~
int cmdreadywait(int Popt,PTHREADTB Ppthtb);                       //~v8@3I~
//**************************************************************** //~v8@6I~
int setcmdready(int Popt,PTHREADTB Ppthtb);                        //~v8@6I~
//**************************************************************** //~v8@5I~
int ftperrlog(int Popt);                                           //~v8@5R~
//**************************************************************** //~v8@8I~
int getcfgparm(int Popt,PTHREADTB Ppthtb);                         //~v8@8I~
//**************************************************************** //~v8@9I~
int funccmd2(int Popt,PTHREADTB Ppthtb,char *Pcmd);                //~v8@9I~
//**************************************************************** //~v8@9I~
char *cfggetemulator(int Popt,PTHREADTB Ppthtb);                   //~v8@9I~
//**************************************************************** //~v8@9I~
int  cfggetlogoncmdno(int Popt,PTHREADTB Ppthtb);                  //~v8@9I~
//**************************************************************** //~v8@9I~
int  cfggetlogoffcmdno(int Popt,PTHREADTB Ppthtb);                 //~v8@9I~
//**************************************************************** //~v8@9I~
PCONFDEST cfggetlogoncmd(int Popt,PTHREADTB Ppthtb);               //~v8@9I~
//**************************************************************** //~v8@9I~
PCONFDEST cfggetlogoffcmd(int Popt,PTHREADTB Ppthtb);              //~v8@9I~
//**************************************************************** //~v8@9I~
PCONFDEST cfggetlogonerr(int Popt,PTHREADTB Ppthtb);               //~v8@9I~
//**************************************************************** //~v8@9I~
//PCONFDEST cfggetalready(int Popt,PTHREADTB Ppthtb);              //~v8@rR~
//**************************************************************** //~v8@9I~
PCONFDEST cfggetprelogon(int Popt,PTHREADTB Ppthtb);               //~v8@vR~
//**************************************************************** //~v8@9I~
int srchconfd(int Popt,char *Phost);                               //~v8@9I~
//**************************************************************** //~v8@bI~
int funcsnap3270cmd(int Popt,PTHREADTB Ppthtb,char *Psubcmd);      //~v8@bI~
//**************************************************************** //~v8@bI~
int iswaitaction(int Popt,char *Pcmd);                             //~v8@bR~
//****************************************************************
int postbackmain(PTHREADTB Ppthtb,int Prc);
//****************************************************************
void exitthread(PTHREADTB Ppthtb,int Prc);
//**************************************************************** //~v8@pI~
int funcconnect(PTHREADTB Ppthtb);                                 //~v8@pM~
//**************************************************************** //~v8@pI~
int funcend3270(PTHREADTB Ppthtb);                                 //~v8@pM~
//**************************************************************** //~v8@pI~
int funccmd(PTHREADTB Ppthtb);                                     //~v8@pM~
//**************************************************************** //~v8@pI~
int write3270(PTHREADTB Ppthtb,char *Pcmd);                        //~v8@pM~
//**************************************************************** //~v8@pI~
int funclogon(PTHREADTB Ppthtb);                                   //~v8@pM~
//**************************************************************** //~v8@pI~
int funclogoff(PTHREADTB Ppthtb);                                  //~v8@pM~
//**************************************************************** //~v8@pI~
int funcstring(PTHREADTB Ppthtb);                                  //~v8@pM~
//**************************************************************** //~v8@pI~
int funcrsh(PTHREADTB Ppthtb);                                     //~v8@pM~
//**************************************************************** //~v8@pI~
int close3270(PTHREADTB Ppthtb);                                   //~v8@pM~
//**************************************************************** //~v8@pI~
int funcftp(PTHREADTB Ppthtb);                                     //~v8@pM~
//**************************************************************** //~v8@rI~
int clearcmdline(int Popt,PTHREADTB Ppthtb);                       //~v8@rI~
//**************************************************************** //~v8@vI~
int screenchk(int Popt,PTHREADTB Ppthtb,char *Pvalidresp);         //~v719M~
//**************************************************************** //~v8@vI~
char *uerrmsgmt(int Popt,char *     ,char *      ,... );           //~v719M~
#define UEMO_RESPMSG      0x01     //msg returned to xe            //~v8@5I~
#define UEMO_FTPERR       0x10     //log to ftperrlog              //~v8@5I~
//**************************************************************** //~v8@vI~
int screenclear(int Pkeepcount,PTHREADTB Ppthtb);                  //~v719M~
#define SCCO_NEWCMD   0x0100   //new cmd,ready chk required        //~v8@3R~
//**************************************************************** //~v8@vI~
int funcenter(int Popt,PTHREADTB Ppthtb);                          //~v719M~
//**************************************************************** //~v8@vI~
int funcsnap(int Popt,PTHREADTB Ppthtb);                           //~v719M~
//**************************************************************** //~v8@vI~
int snap3270(int Popt,PTHREADTB Ppthtb,char *Pbuff,int Pbuffsz,int *Pplen);//~v719M~
//**************************************************************** //~v8@vI~
int send3270(int Popt,PTHREADTB Ppthtb,char *Pcmd);                //~v719M~
//**************************************************************** //~v8@vI~
int wait3270(int Popt,PTHREADTB Ppthtb,int Pwaittime);             //~v719M~
//**************************************************************** //~v8@vI~
int funcbreak(PTHREADTB Ppthtb);                                   //~v719M~
//**************************************************************** //~v8@vI~
int funcbreak2(PTHREADTB Ppthtb);                                  //~v71gI~
//**************************************************************** //~v8@BI~
int xe3270squery(int Popt,PTHREADTB Ppthtb,char **Ppopd);          //~v8@BR~
