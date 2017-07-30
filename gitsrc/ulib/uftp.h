//*CID://+v6L3R~:                             update#=  356;       //+v6L3R~
//******************************************************
//*uftp.h                                                          //~v5ncR~
//******************************************************
//v6L3:170710 add SP cmd to register shortcut path name and use by  sp:xxx//+v6L3I~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H5:170106 maxpath for ftp 512-->4096(same as linux)            //~v6H5I~
//v6E5:160721 expand ::xehost file ipaddr field for addr by url    //~v6E5I~
//v6qg:131208 xehosts pswd;protect copy line(update line should be decripted pswd)//~v6qgI~
//v6qe:131206 (BUG)ftp "ls" dose not show slinkname,but "l" on attr. display dummy slinkname.//~v6qeI~
//v6h3:120604 (WTL)ELOOP is defined on errno.h of vc2010           //~v6h3I~
//v6da:120217 (Axe)smb support                                     //~v6daI~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d0I~
//v6d0:120131 (SMB)volatile password on UFTPHOST                   //~v6d0I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mG:080627 3270:distigush TSO and TSOE for submit cmd           //~v5mGI~
//v5mB:080621 3270:DBCS conversion support(CP930(290+300)/CP939(1027+300)//~v5mBI~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61n:080121*Bug report by M.J(LCD fail when LANG is not english) //~v61nI~
//v61e:071126*(FTP)use ls -la if avail to get list of "." file     //~v61eI~
//v61d:071126*(FTP)skip modtime if not supported                   //~v61dI~
//v61b:071123*(FTP)log errmsg to ftplog alos                       //~v61bI~
//v5kt:070702 from rh9 to ProFtpd,ls cmd fail by "no route to host". it requires active mod(once issue passive cmd to set off)//~v5ktI~
//            support ICMD parm on xehost                          //~v5ktI~
//v5ks:070702 ProFtpd return filename only for ls -l by rfc from v1.2.10//~v5ksI~
//            "ls" use NLST(fname only),"dir" usr LIST(detail list) cmd. so change to "dir"//~v5ksI~
//v5j4:060914 ftp:3270 support (xehost TSO=portno operand)         //~v5j4I~
//v5ex:041107 tempname support at remote                           //~v5exI~
//v5dz:040823 ftp:specify large windowsize(windows default is 4096)//~v5dzI~
//v5df:040609 (AIX:BUG)AIX responce is by JST for ls,GMT for modtime//~v5dfI~
//                     LNX responce is both by GMT;                //~v5dfI~
//                     ajust ls time by xehosts,mdtime result by ftime tz//~v5dfI~
//v5d7:040529 (FTP)delete process duplicated                       //~v5d7I~
//v5c9:040331 (FTP:BUG)macro should not contain ";" for use under the condition of if-then-else//~v5c9I~
//v5bv:040222 (FTP)use resident ftp client pgm because mdos prompt appear each time under WXE//~v5bvI~
//v5bo:040211 (FTP)password cryptograph                            //~v5boI~
//v5b1:040115 (FTP)tempdir del option for test                     //~v5b1I~
//v5ak:040108 (WIN-FTP:BUG)dir dele fail by wind dirsepc           //~v5akI~
//v5aj:040108 (FTP)allow file for udosfindfirst like as win        //~v5ajI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5aeI~
//v5ae:040105 solaris time stamp fmt is mm月dd日 yyyy年            //~v5aeI~
//v5ad:040105 support TZ=hhmm and DBCS=EUC/SJIS                    //~v5adI~
//v5ab:040104 integrate ROOTDIR2--->ROOTDIR3                       //~v5abI~
//v59d:030816 ftp support
//******************************************************
#ifdef FTPSUPP                                                     //~v59dI~
                                                                   //~v59dI~
#define FTP_CLIENTCMDLEN 128                                       //~v61pI~
#ifdef GBLDEF_FTP                                                  //~v59dI~
	int Gftpopt;                                                   //~v59dI~
    char Gftpclient[FTP_CLIENTCMDLEN];                             //~v61pI~
    int Gftperr;                                                   //~v6d1R~
#else                                                              //~v59dI~
	extern int Gftpopt;                                            //~v59dI~
    extern char Gftpclient[FTP_CLIENTCMDLEN];                      //~v61pI~
    extern int Gftperr;                                            //~v6d1R~
#endif                                                             //~v59dI~
#define GFTPO_AVAIL     0x01    //ftp initialized                  //~v59dI~
#define GFTPO_PSFTPALL  0x02    //client is psftp as default       //~v61pR~
//******************************************************           //~v59dI~
typedef int (FTPCMD_CALLBACK)(FILE *,void *Ppvoid);	//uftpcmd callback func//~v59dR~
                                                                   //~v59dI~
#define FTP_WINDOWSZ  65536 	//default ftp windowsize           //~v5dzR~
#define FTP_REMOTEID  ':'		//remote fine name seperater       //~v59dM~
                                                                   //+v6L3I~
#define FTP_SHORTPATH_ID        "SP"                               //+v6L3I~
#define FTP_SHORTPATH_PREFIX    FTP_SHORTPATH_ID ":"               //+v6L3I~
                                                                   //+v6L3I~
#define FTP_ROOTUSER    "root"                                     //~v59dI~
#define FTP_HDIRMASK    0xffffff00 	//hdir chk mask for FTP        //~v59dI~
#define FTP_HDIRIDXMASK 0x000000ff 	//hdir table index mask for FTP//~v59dI~
#define FTP_HDIRID      0xff11ee00 	//hdir id  for FTP             //~v59dI~
                                                                   //~v59dI~
#define FTP_CHMODMASK   07777                                      //~v59dI~
#ifndef UNX                                                        //~v5ncR~
  #ifndef S_IFMT    //windows sys/stat.h has definition            //~v59dI~
    #define S_IFMT 	0170000		/*   mask               0xf000*/   //~v59dR~
  #endif                                                           //~v59dI~
  #ifndef S_IFREG   //windows sys/stat.h has definition            //~v59dI~
    #define S_IFREG	0100000		/*   reguler            0x8000*/   //~v59dR~
  #endif                                                           //~v59dI~
  #ifndef S_IFDIR   //windows sys/stat.h has definition            //~v59dI~
    #define S_IFDIR	0040000		/*   directory          0x4000*/   //~v59dR~
  #endif                                                           //~v59dI~
  #ifndef   S_IFBLK //dup in MINGW                                 //~v5ncI~
    #define S_IFBLK 	0060000		/*   block special      0x6000*///~v59dR~
  #endif                                                           //~v5ncI~
  #ifndef S_IFCHR   //windows sys/stat.h has definition            //~v59dI~
    #define S_IFCHR 	0020000		/*   character special  0x2000*///~v59dR~
  #endif                                                           //~v59dI~
	#define S_IFLNK 	0120000		/* symbolic link        0xa000*///~v59dR~
  #ifndef   S_IFIFO                                                //~v5ncI~
    #define S_IFIFO 	0010000		/*   fifo               0x1000*///~v59dR~
  #endif                                                           //~v5ncI~
	#define S_IFSOCK 	0140000		/* socket               0xc000*///~v59dR~

    #define  __S_ISTYPE(mode,mask)  ((mode & S_IFMT) == (mask))    //~v59dR~
  #if !defined(MGW32)||!defined(_STAT_H_) //dup with sys/stat.h in mingw//~v5ncI~
	#define  S_ISDIR(mode)	__S_ISTYPE((mode),S_IFDIR)             //~v59dR~
	#define  S_ISBLK(mode)	__S_ISTYPE((mode),S_IFBLK)             //~v59dR~
	#define  S_ISCHR(mode)	__S_ISTYPE((mode),S_IFCHR)             //~v59dR~
  #endif //dup with sys/stat.h in mingw                            //~v5ncI~
	#define  S_ISLNK(mode)	__S_ISTYPE((mode),S_IFLNK)             //~v59dR~
  #if !defined(MGW32)||!defined(_STAT_H_) //dup with sys/stat.h in mingw//~v5ncI~
	#define  S_ISFIFO(mode)	__S_ISTYPE((mode),S_IFIFO)             //~v59dR~
  #endif //dup with sys/stat.h in mingw                            //~v5ncI~
	#define  S_ISSOCK(mode) __S_ISTYPE((mode),S_IFSOCK)            //~v59dR~

  #if !defined(MGW32)||!defined(_STAT_H_) //dup with sys/stat.h in mingw//~v5ncI~
	#define S_IRWXU 	0000700		/* 0x01c0 owner mask             */
	#define S_IRUSR 	0000400		/* 0x0100 read permission: owner */
	#define S_IWUSR		0000200		/* 0x0080 write permission: owner */
	#define S_IXUSR		0000100		/* 0x0040 execute/search permission: owner */
  #endif                                                           //~v5ncI~
	#define S_IRWXG 	0000070		/* 0x0038 group mask             */
	#define S_IRGRP 	0000040		/* 0x0020 read permission: owner */
	#define S_IWGRP		0000020		/* 0x0010 write permission: owner */
	#define S_IXGRP		0000010		/* 0x0008 execute/search permission: owner */
	#define S_IRWXO 	0000007		/* 0x0007 other mask             */
	#define S_IROTH 	0000004		/* 0x0004 read permission: owner */
	#define S_IWOTH		0000002		/* 0x0002 write permission: owner */
	#define S_IXOTH		0000001		/* 0x0001 execute/search permission: owner */
	#define S_ISUID     0004000		/* 0x0800 set user id on execution */
	#define S_ISGID     0002000		/* 0x0400 set group id on execution */
	#define S_ISVTX     0001000		/* 0x0200 sticky */
#ifndef VC10EXP                                                    //~v6h3R~
    #define ELOOP 40        //symbolic link loop                   //~v5akI~
#endif                                                             //~v6h3I~
                                                                   //~v5akI~
#endif //not UNX                                                   //~v59dR~

#ifdef W32                                                         //~v61nI~
	#define FTP_LOCALCMD_PWD     "!cd"		//to chl LCD ok        //~v61nR~
#else                                                              //~v61nI~
	#define FTP_LOCALCMD_PWD     "!pwd" 	//to chl LCD ok        //~v61nR~
#endif                                                             //~v61nI~
                                                                   //~v61pI~
                                                                   //~v61pI~
#define FTP_SLINKNAME_NA  "Unknown"                                //~v6qeR~
#define FTP_DIR_SEPC     '/'                                       //~v59dI~
#define FTP_DIR_SEPS     "/"                                       //~v59dI~
#define FTP_DIR_ALLMEMB  "*"                                       //~v5akI~
#define FTP_ROOTDIR(fname) (*(fname)=='/' && *((fname)+1)==0) //root id//~v59dR~
#define FTP_PATHLEN(fname) (uftppathlen(fname))                    //~v59dR~
#define FTP_HOSTNAMELEN 8   //node id name max length
#define FTP_USERNAMELEN 16  //ftp user name max length
#define FTP_PSWDNAMELEN 16  //ftp pswd max length
//#define FTP_IPADNAMELEN 15  //ftp pswd max length                //~v6E5R~
#define FTP_IPADNAMELEN   127  //not by ip addr but by url         //~v6E5I~
//#define FTP_MAXPATH    512                                         //~v59dI~//~v6H5R~
#define FTP_MAXPATH    (4096+FTP_HOSTNAMELEN+1)                    //~v6H5R~
#define FTP_MAXPATH2   (FTP_MAXPATH*2)                             //~v6H5I~
#define FTP_ROOTDIRPOS   0                                         //~v59dI~
#define FTP_GETHOSTN(pathname,hostnmlen,hostnm) \
    				memcpy(hostnm,pathname,hostnmlen), /*;*/   \
    				*(hostnm+hostnmlen)=0;                         //~v59dI~
#define FTP_SETPATHN(hostnmlen,hostnm,fname,pathname) \
    				memcpy(pathname,hostnm,hostnmlen), /*;*/  \
    				*(pathname+hostnmlen)=FTP_REMOTEID, /*;*/  \
    				strcpy(pathname+hostnmlen+1,fname);            //~v59dR~
                                                                   //~v59dI~
typedef struct _UFTPHOST{   //ftp node table
					  UQUEE    UFTPHqe;
                      ULONG    UFTPHflag;                          //~v59dR~
#define UFTPHFROOT    0x0001   //root user                         //~v59dI~
#define UFTPHFSJIS    0x0002   //sjis                              //~v5adI~
#define UFTPHFEUC     0x0004   //eus                               //~v5adI~
#define UFTPHFAJUST   0x0008   //tz specified                      //~v5afR~
#define UFTPHFTSO     0x0010   //host is mainframe TSO             //~v5j4I~
#define UFTPHFULSCMD  0x0020   //user specified LSCMD              //~v61eI~
#define UFTPHFCP930   0x0040   //EBCDIC cp290 (katakana+english lower case letter)+cp300//~v5mBR~
#define UFTPHFCP939   0x0080   //EBCDIC cp1027(english lower case letter+katakana)+cp300//~v5mBR~
#define UFTPHFMODTERR 0x0100   //modtime failed                    //~v61dI~
#define UFTPHFINITCHK 0x0200   //initial chk done                  //~v61eR~
#define UFTPHFLSCMDCG 0x0400   //ls cmd default changed            //~v61eI~
#define UFTPHFPSFTP   0x0800   //use psftp                         //~v61pI~
#define UFTPHFREALMF  0x1000   //TSO is REAL MVS(Not on Hercules-TurnketMVS)//~v5mGI~
#define UFTPHFTSOSUBM 0x2000   //use TSO SUBMIT cmd not hercules sub tool//~v5mGI~
#define UFTPHFCPCJK   0x4000   //other DBCS by xe3270.cfg(xe3270ftp.map) definition//~v5mQR~
#define UFTPHFMEMPSWD 0x8000   //volatile password by pass cmd(storage only,not write back to ::xehosts)//~v6d0R~
#define UFTPHFSMB     0x010000 //smbclient connection by SHREA= option//~v6d1R~
#define UFTPHFRWIN    0x020000 //destination is not SAMBA but Windows//~v6d1R~
#define UFTPHFNOUNIX  0x040000 //stat cmd not supported by "UNIX extension=no"//~v6d1R~
#define IS_NOUNIXEXT(puftph) (puftph->UFTPHflag & UFTPHFNOUNIX)    //~v6d1I~
#define SET_NOUNIXEXT(puftph) puftph->UFTPHflag|=UFTPHFNOUNIX      //~v6d1I~
#define UFTPHFNFMSG   0x080000 //err msg when NT_STATUS_OBJECT_NAME_NOT_FOUND//~v6d1I~
#define UFTPHFSMBJ    0x100000 //smbclient by jcifs                //~v6daI~
#define UFTPHFPSWDCLR 0x200000 //pswd was cleared because line was copyed//~v6qgR~
#define UFTPHFPSWDENC 0x400000 //pswd was encrypted at load        //~v6qgI~
                                                                   //~v5mGI~
#define UFTPHISPSFTP(puftph)  (puftph->UFTPHflag & UFTPHFPSFTP)    //~v61pR~
#define UFTPHISTSO(puftph)  (puftph && (puftph->UFTPHflag & UFTPHFTSO))//~v5j4R~
#define UFTPHISTSOSUBM(puftph) (puftph && (puftph->UFTPHflag & (UFTPHFTSOSUBM|UFTPHFREALMF))!=0) //use TSO submit cmd//~v5mGR~
#define UFTPH_ISSMB(puftph)  (puftph && puftph->UFTPHflag & UFTPHFSMB)       //~v6d1R~//~v6daR~
#define UFTPH_ISSMBJ(puftph)  (puftph && puftph->UFTPHflag & UFTPHFSMBJ)//~v6daR~
                      int      UFTPHport;     //port of 3270emulator//~v5j4R~
                      int      UFTPHtz;       //time zone by minute//~v5adI~
                      int      UFTPHhostnmlen;//UFTPhost len       //~v5aeI~
                      UCHAR    UFTPHhost[FTP_HOSTNAMELEN+1];
                      UCHAR    UFTPHuser[FTP_USERNAMELEN+1];
                      UCHAR    UFTPHpswd[FTP_PSWDNAMELEN+1];
                      UCHAR    UFTPHipad[FTP_IPADNAMELEN+1];
                      UCHAR    UFTPHlscmd[13];                     //~v5ksR~
#define UFTPHLSCMD_NEW  "dir"                                      //~v5ksR~
#define UFTPHLSCMD_OLD  "ls -la"                                   //~v5ksI~
                      UCHAR    UFTPHicmd[65];   //initial cmd      //~v5ktI~
                      UCHAR    UFTPHcwd[FTP_MAXPATH];	//current dir//~v59dR~
                      UCHAR    UFTPHhome[FTP_MAXPATH];	//homedir  //~v59dR~
#define MAX_SHARENAME  64                                          //~v6d1I~
                      UCHAR    UFTPHshare[MAX_SHARENAME];	//sharename//~v6d1I~
                      ULONG    UFTPHroot_attr;  //samba            //~v6d1I~
                      FDATE    UFTPHroot_date;                     //~v6d1I~
                      FTIME    UFTPHroot_time;                     //~v6d1I~
                      time_t   UFTPHroot_mtime;                    //~v6d1I~
                    } UFTPHOST, *PUFTPHOST;
#define UFTPHOSTSZ (sizeof(UFTPHOST))
                                                                   //~v59dI~
#define FTPWILDLEN   64                                            //~v59dI~
typedef struct _UFTPDIRH{   //ftp readdir handle                   //~v59dR~
                      PUFTPHOST   UFTPDHpuftph;    //nodetbl       //~v5aeI~
                      PUDIRLIST   UFTPDHpudl;      //pudl top      //~v59dI~
                      int         UFTPDHnpos;      //next readdir pos//~v59dI~
                      ULONG       UFTPDHattr;                      //~v59dI~
                      char        UFTPDHwild[FTP_MAXPATH];         //~v59dI~
                    } UFTPDIRH, *PUFTPDIRH;                        //~v59dI~
#define UFTPDIRHSZ (sizeof(UFTPDIRH))                              //~v59dI~
//*******************************************************
#define FTPRC_OPENERR         101
#define FTPRC_LOGONERR        102
#define FTPRC_PARSEERR        103
#define FTPRC_FULLPATHERR     104
#define FTPRC_NOTDEFNODE      105
#define FTPRC_INTERNALERR     106
#define FTPRC_NOMOREFILE      128                                  //~v5d7I~
#define FTPRC_NOTSUPPORTED    ENOSYS //109                         //~v59dR~
#define FTPRC_SSHERR          107                                  //~v61pI~
//*********************************************************************************//~v59dR~
//110 Restart marker reply. RESTコマンドのためのマーカー返答である //~v59dI~
//120 Service ready in nnn minutes. サービスは停止しているが、nnn分後に準備できる//~v59dI~
//125 Data connection already open; transfer starting. データコネクションはすでに確立されている。このコネクションで転送を開始する//~v59dI~
//150 File status okay; about to open data connection. ファイルステータスは正常である。データコネクションを確立する//~v59dI~
//200 Command okay. コマンドは正常に受け入れられた                 //~v59dI~
//202 Command not implemented, superfluous at this site. コマンドは実装されていない。SITEコマンドでOSコマンドが適切でない場合など//~v59dI~
//211 System status, or system help reply. STATコマンドに対するレスポンス//~v59dI~
//212 Directory status. STATコマンドによるディレクトリ情報を示す   //~v59dI~
//213 File status. STATコマンドによるファイル情報を示す            //~v59dI~
//214 Help message. HELPコマンドに対するレスポンス                 //~v59dI~
//215 NAME system type. SYSTコマンドに対するレスポンス             //~v59dI~
//220 Service ready for new user. 新規ユーザー向けに準備が整った。ログイン時に表示される場合を想定している//~v59dI~
//221 Service closing control connection. コントロールコネクションを切断する。QUITコマンド時のレスポンス//~v59dI~
//225 Data connection open; no transfer in progress. データコネクションを確立した。データの転送は行われていない//~v59dI~
//226 Closing data connection. 要求されたリクエストは成功した。データコネクションをクローズする//~v59dI~
//227 Entering Passive Mode (h1,h2,h3,h4,p1,p2). PASVコマンドへのレスポンス。h1～h4はIPアドレス、p1～p2はポート番号を示す//~v59dI~
//230 User logged in, proceed. ユーザーログインの成功              //~v59dI~
//250 Requested file action okay, completed. 要求されたコマンドによる操作は正常終了した//~v59dI~
//257 "PATHNAME" created. ファイルやディレクトリを作成したというのがRFCでの意味だが、MKDコマンドの結果以外にも、実際にはPWDコマンドの結果にも用いられる//~v59dI~
//331 User name okay, need password. パスワードの入力を求める      //~v59dI~
//332 Need account for login. ACCTコマンドで課金情報を指定する必要がある//~v59dI~
//350 Requested file action pending further information 他の何らかの情報を求めている//~v59dI~
//421 Service not available, closing control connection. サービスを提供できない。コントロールコネクションを終了する。サーバのシャットダウン時など//~v59dI~
//425 Can't open data connection. データコネクションをオープンできない//~v59dI~
//426 Connection closed; transfer aborted. 何らかの原因により、コネクションをクローズし、データ転送も中止した//~v59dI~
//450 Requested file action not taken. 要求されたリクエストはアクセス権限やファイルシステムの理由で実行できない//~v59dI~
//451 Requested action aborted. Local error in processing. ローカルエラーのため処理を中止した//~v59dI~
//452 Requested action not taken. ディスク容量の問題で実行できない //~v59dI~
//500 Syntax error, command unrecognized. コマンドの文法エラー     //~v59dI~
//501 Syntax error in parameters or arguments. 引数やパラメータの文法エラー//~v59dI~
//502 Command not implemented. コマンドは未実装である              //~v59dI~
//503 Bad sequence of commands. コマンドを用いる順番が間違っている //~v59dI~
//504 Command not implemented for that parameter. 引数やパラメータが未実装//~v59dI~
//530 Not logged in. ユーザーはログインできなかった                //~v59dI~
//532 Need account for storing files. ファイル送信には、ACCTコマンドで課金情報を確認しなくてはならない//~v59dI~
//550 Requested action not taken. 要求されたリクエストはアクセス権限やファイルシステムの理由で実行できない//~v59dI~
//551 Requested action aborted. Page type unknown. ページ構造のタイプの問題で実行できない//~v59dI~
//552 Requested file action aborted. ディスク容量の問題で実行できない//~v59dI~
//553 Requested action not taken. ファイル名が間違っているため実行できない//~v59dI~
                                                                   //~v59dI~
#define FTPRESPID_XCOMP "226 "                                     //~v59dI~
//*******************************************************
//int uftpinit(int Popt,char *Plogfnm,char *Phostsfnm);            //~v5bvR~
int uftpinit(int Popt,char *Plogfnm,char *Phostsfnm,char *Pclientpgm);//~v5bvI~
#define  UFTPO_NOP     0x01     //no ftp support                   //~v59dR~
#define  UFTPO_LOG     0x02                                        //~v59dI~
#define  UFTPO_APPEND  0x04     //append mode                      //~v59dR~
#define  UFTPO_KEEPWD  0x08     //keep work dir for test           //~v5b1I~
//*******************************************************          //~v59dI~
int uftpterm(void);                                                //~v59dR~
//*******************************************************          //~v59dI~
unsigned uftpdirlist(PUFTPHOST Ppuftph,char *Pfpath,ULONG Pattr,PUDIRLIST *Pppudl,int *Ppentno);//~v5aeR~
//*******************************************************          //~v59dI~
unsigned int uftpfstatudl(PUFTPHOST Ppuftph,int Popt,char *Pfpnm,PUDIRLIST Ppudl);//~v5aeR~
#define FTPSUD_SLINK     0x01                                      //~v59dI~
//*******************************************************          //~v59dI~
int uftppathlen(char *Pfilename);
//*******************************************************          //~v59dI~
PUFTPHOST uftpnodesrch(char *Pnode);
//*******************************************************          //~v59dI~
int uftpnodeadd(PUFTPHOST Ppuftph);                                //~v5afI~
//*******************************************************          //~v59dI~
int uftpnodedel(char *Pnode);
//*******************************************************          //~v59dI~
void uftpnodeclear(void);                                          //~v59dI~
//*******************************************************          //~v59dI~
UQUEH *uftpgethostqhaddr(void);                                    //~v59dI~
//*******************************************************          //~v59dI~
int uftpcmd(PUFTPHOST Ppuftph,int Popt,char *Pcmd,char ***Pstdo,int *Pstdoctr,FTPCMD_CALLBACK *Pfunc,void *Ppvoid);//~v5aeR~
#define FTPCMD_BINARY  0x01                                        //~v59dM~
#define FTPCMD_NODEINIT  0x02       //first time(log ftp cmd)      //~v61pI~
//*******************************************************          //~v59dM~
int uftpcmdrespchk(char **Pstdo,int Pstdoctr);                     //~v59dM~
//*******************************************************          //~v59dI~
int uftpnextstdo(char ***Ppstdo,int *Ppstdoctr);                   //~v59dM~
//*******************************************************          //~v59dI~
int uftpsrchfname(PUFTPHOST Ppuftph,char **Pstdo,int Pstdoctr,char *Pfname,PUDIRLIST Ppudl);//~v5afR~
//*******************************************************          //~v59dI~
int uftpgetdl(PUFTPHOST Ppuftph,char **Pstdo,int Pstdoctr,PUDIRLIST *Pppudl,int *Pentno);//~v5afR~
//*******************************************************          //~v59dI~
int uftpgetdl1(PUFTPHOST Ppuftph,char *Prec,PUDIRLIST Ppudl);      //~v5afR~
//*******************************************************          //~v59dI~
int uftpcmdsrchrespid(char ***Ppstdo,int *Ppstdoctr,char *Pokrespid);//~v59dR~
#define UFCSRRC_EOL          -1     //not found                    //~v59dR~
//*******************************************************          //~v59dI~
void uftpudl2ffb3(PUDIRLIST Ppudl,FILEFINDBUF3 *Ppffb3);           //~v59dR~
//*******************************************************          //~v59dI~
int uftpopendir(PUFTPHOST Ppuftph,char *Pfpath,ULONG Pattr,ULONG *Phdir,int *Pentno);//~v5aeR~
//*******************************************************          //~v59dI~
int uftpreaddir(int Phdir,PUDIRLIST *Pppudl);                      //~v59dR~
//*******************************************************          //~v59dI~
int uftpclosehdir(int Phdir);                                      //~v59dI~
//*******************************************************          //~v59dI~
int uftpdirlistslink(PUFTPHOST Ppuftph,char *Pfpnm,PUDIRLIST Ppudl,int Pentno);//~v5aeR~
//*******************************************************          //~v59dI~
int uftplog(int Popt,char *Pline);                                 //~v59dM~
#define FTPLOG_REQ 	0x01                                           //~v59dI~
#define FTPLOG_RESP	0x02                                           //~v59dI~
#define FTPLOG_ADDLF   0x04                                        //~v59dI~
#define FTPLOG_PSWD    0x08    //del password on log               //~v59dI~
#define FTPLOG_ERRM	0x10        //log errmsg                       //~v61bI~
#define FTPLOG_INFO	0x20        //other information(prefix=!!)     //~v61pI~
//*******************************************************          //~v59dI~
int uftpsrchfnameslink(PUFTPHOST Ppuftph,char ***Pstdo,int *Ppstdoctr,char *Pfname,PUDIRLIST Ppudl);//~v5afR~
//*******************************************************          //~v59dI~
//int uftpgethostsdata(char *Pdata,int Plen,PUFTPHOST Ppufh);        //~v59dI~//~v6qgR~
int uftpgethostsdata(int Popt,char *Pdata,int Plen,PUFTPHOST Ppufh);//~v6qgI~
#define UFGHDO_CLEAR_ENCPSWD  0x01 //clear pswd on the line if encripted//~v6qgR~
//*******************************************************          //~v59dI~
int uftpipachk(char *Pipa,ULONG *Ppxipa);                          //~v59dI~
//*******************************************************          //~v59dI~
int uftphoststbinit(char *Phostsfnm);                              //~v59dI~
//*******************************************************          //~v59dI~
int uftpsimplerespchk(char *Pcmd,char *Prespid,char *Pfname,char ***Ppstdo,int *Ppstdoctr,int Prc);//~v59dR~
//*******************************************************          //~v59dI~
int uftpisexist(PUFTPHOST Ppuftph,char *Pfpath);                   //~v5aeR~
//******************************************************           //~v59dM~
int uftpisremote(char *Pfpath,PUFTPHOST *Pppuftph);                //~v5aeI~
//******************************************************           //~v59dI~
//int uftpajustjst(PUFTPHOST Ppuftph,FDATE *Ppfdate,FTIME *Ppftime);//~v5dfR~
int uftpajustjst(int Popt,PUFTPHOST Ppuftph,FDATE *Ppfdate,FTIME *Ppftime);//~v5dfI~
#define UFAJO_GMT  0x01                                            //~v5dfI~
//******************************************************           //~v5abI~
int uftpisrootdir(char *Pfpath);                                   //~v5abI~
//******************************************************           //~v5ajI~
int uftpattrselect(ULONG Pfattr,ULONG Pfattrsrc,ULONG Ppattr);     //~v5ajM~
//******************************************************           //~v5b1I~
int uftpmktempwd(char *Ptempfnm);                                  //~v5b1R~
//******************************************************           //~v5b1I~
int uftpdeltempwd(char *Ptempfnm);                                 //~v5b1I~
//******************************************************           //~v5boI~
int uftphostscrypt(int Popt,char *Pipswd,char *Popswd);            //~v5boI~
//******************************************************           //~v5exI~
char *uftptempnam(char *Phost,char *Pprefix,char *Ptempfile);      //~v5exI~
//******************************************************           //~v6d0I~
int uftp_mempswd(int Popt,char *Pnode,PUFTPHOST Ppftph,char *Ppswd);//~v6d0I~
//******************************************************           //~v6d1I~
int uftpgetpathname(char *Pfpath,char *Ppath,int Plen);            //~v6d1I~
//******************************************************           //~v6H5I~
int uftp_udirlist_setname(int Popt,PUFTPHOST Ppuftph,PUDIRLIST Ppudl,char *Pname,size_t Pnamefldsz);//~v6H5R~
//******************************************************           //~v6J0I~
int uftpslinkcomp(const void *ent1,const void *ent2);              //~v6J0I~
#define FTP_SORTTYPE_SLINK 'f'                                     //~v6J0I~
#endif //FTPSUPP                                                   //~v59dI~
