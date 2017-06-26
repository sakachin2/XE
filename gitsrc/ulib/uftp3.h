//*CID://+v6J4R~:                             update#=  417;       //+v6J4R~
//******************************************************           //~v61pI~
//*uftp3.h                                                         //~v61pI~
//******************************************************           //~v61pI~
//v6J4:170207 (Bug:Lnx)smb err was not checked, edit cmd opens file as new file//+v6J4I~
//v6da:120217 (Axe)smb support                                     //~v6daI~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1I~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//******************************************************           //~v61pI~
#ifdef FTPSUPP                                                     //~v61pI~
//******************************************************           //~v61pI~
#define FTP_HDR_PARMID       '@'                                   //~v61pI~
#define FTP_HDR_PSFTP        "#@PSFTP="    //ctr card to specify client cmd//~v61pR~
#define FTP_HDR_SSH          "#@SSH="      //set default ssh=ALL   //~v61pR~
#define FTP_OPT_SSH          "SSH="        //each destination      //~v61pI~
#define FTP_OPT_SMB          "SHARE="      //each destination      //~v6d1I~
#define FTP_VALUE_ALL        "ALL"         //set default           //~v61pI~
#define FTP_PSFTP_PWPARM     "-pw"                                 //~v61pI~
#define FTP_VALUE_PSFTP      "psftp"                               //~v61pR~
#define FTP_ECHO_PSFTP       "psftp>"                              //~v61pI~
#define FTP_ECHO_PSFTP_ID    ">>> "         //end of cmd respnse(stopper)//~v61pI~
#define FTP_PSFTP_OK_REMOTE  "Remo"		//successfull response msg id//~v61pR~
#define FTP_PSFTP_OK_LIST    "List"		//ls/dir successfull response msg id//~v61pR~
#define FTP_PSFTP_OK_LCD     "New "		//lcd succesfull response msg id//~v61pR~
#define FTP_PSFTP_OK_GET     "remo"		//get     response         //~v61pR~
#define FTP_PSFTP_OK_PUT     "loca"		//put     response         //~v61pI~
#define FTP_PSFTP_OK_CHNG    " -> "		//rename/chmod  response   //~v61pR~
#define FTP_PSFTP_OK_OK      " OK"		//delete  response         //~v61pR~
#define FTP_PSFTP_NG_LIST    "Unable"		//ls/dir open err      //~v61pR~
#define FTP_PSFTP_NG_NOTF    "no such file"	//cd fail              //~v61pI~
#define FTP_PSFTP_NG_UNKNOWN "unknown command"  //not supported cmd//~v61pR~
#define FTP_PSFTP_RESPEND(pc)  (!memcmp(pc,FTP_ECHO_PSFTP_ID,sizeof(FTP_ECHO_PSFTP_ID)-1))//~v61pR~
#define FTP_PSFTP_OPENERR(pc)  (!memcmp(pc,FTP_PSFTP_NG_LIST,sizeof(FTP_PSFTP_NG_LIST)-1))//~v61pR~
                                                                   //~v61pI~
#define FTP_PSFTPCMD "%s -batch -bc -be -b %s -l %s " FTP_PSFTP_PWPARM " %s"//~v61pR~
    	//-l:user                                                  //~v61pI~
    	//-pw:password                                             //~v61pI~
    	//-bc:output cmd on batch file                             //~v61pR~
    	//-be:dont stop even if bacthdetected err                  //~v61pI~
    	//-b:batch file input                                      //~v61pI~
    	//-batch:no interactive                                    //~v61pI~
#define FTP_PSFTP_SSH_ERR "host key is not cached"                 //~v61pI~
//*******                                                          //~v6d1I~
#define SMB_OS                 "OS=["                              //~v6d1I~
#define SMB_OS_WIN             "Windows"                           //~v6d1I~
#define SMB_STAT_FILE          "File:"                             //~v6d1I~
#define SMB_STAT_SIZE          "Size:"                             //~v6d1I~
#define SMB_STAT_MODTIME       "Modify:"                           //~v6d1I~
#define SMB_STAT_ACCESS        "Access:"                           //~v6d1I~
#define SMB_STAT_UID           "Uid:"                              //~v6d1I~
#define SMB_STAT_GID           "Gid:"                              //~v6d1I~
                                                                   //~v6d1I~
#define SMB_STAT_SLINK         "Symbolic link"                     //~v6d1M~
#define SMB_STAT_DIR           "directory"                         //~v6d1I~
#define SMB_STAT_CHARDEV       "character device" //client.c       //~v6d1I~
#define SMB_STAT_BLKDEV        "block device"                      //~v6d1I~
#define SMB_STAT_FIFO          "fifo"                              //~v6d1I~
#define SMB_STAT_SOCKET        "socket"                            //~v6d1I~
#define SMB_STAT_REGFILE       "regular file"                      //~v6d1R~
#define SMB_STAT_NT_STATUS          "NT_STATUS_"                   //~v6d1I~
#define SMB_STAT_NOT_FOUND    "_NAME_NOT_FOUND "  //NT_STATUS      //~v6d1I~
#define SMB_STAT_NOT_FOUND2   "_NO_SUCH_"         //NT_STATUS_NO_SUCH_FILE//~v6d1I~
#define SMB_STAT_PATH_ERR     "_PATH_NOT_FOUND "  //NT_STATUS      //~v6d1I~
#define SMB_STAT_NO_UNIX_EXT  "UNIX CIFS"  //Server dose'nt support UNIX CIFS call//~v6d1I~
#define SMB_STAT_ACCESS_DENIED "_ACCESS_DENIED "                   //+v6J4I~
                                                                   //~v6d1I~
#define SMB_CMD_VOLUME         "volume"                            //~v6d1R~
#define SMB_RESP_VOLUME        "Volume:"                           //~v6d1I~
#define SMB_CMD_STAT           "stat"                              //~v6d1I~
#define SMB_RESP_STAT          SMB_STAT_FILE  //"File:"            //~v6d1I~
#define SMB_CMD_PWD            "pwd"                               //~v6d1I~
#define SMB_RESP_PWD           "Current directory"                 //~v6d1R~
#define SMB_RESP_GET           "getting"                           //~v6d1I~
#define SMB_RESP_PUT           "putting"                           //~v6d1I~
#define SMB_CMD_MKDIR          "mkdir"                             //~v6d1I~
#define SMB_CMD_MKDIR_POSIX    "posix_mkdir"                       //~v6d1I~
#define SMB_RESP_MKDIR         "posix_mkdir"                       //~v6d1I~
#define SMB_CMD_RENAME         "rename"                            //~v6d1I~
                                                                   //~v6d1I~
#define SMB_CTIMESZ             24  //Mon Feb 12 18:21:13 2012     //~v6d1I~
#define SMB_STATTIMESZ          19  //2012-02-03 07:18:04"         //~v6d1I~
                                                                   //~v6d1I~
#define MAX_SMBCMD             512                                 //~v6d1I~
#define UFTPSMBCMD_DIR          0x01                               //~v6d1R~
#define UFTPSMBCMD_STAT         0x02                               //~v6d1R~
#define UFTPSMBCMD_GET          0x03                               //~v6d1R~
#define UFTPSMBCMD_PUT          0x04                               //~v6d1R~
#define UFTPSMBCMD_DELETE       0x05                               //~v6d1R~
#define UFTPSMBCMD_RENAME       0x06                               //~v6d1R~
#define UFTPSMBCMD_CHMOD        0x07                               //~v6d1R~
#define UFTPSMBCMD_CD           0x08                               //~v6d1R~
#define UFTPSMBCMD_LCD          0x09                               //~v6d1I~
#define UFTPSMBCMD_PUT2         0x0a	//put a b(2 opd rename to) //~v6d1R~
#define UFTPSMBCMD_MKDIR        0x0b                               //~v6d1I~
#define UFTPSMBCMD_RMDIR        0x0c                               //~v6d1I~
#define UFTPSMBCMD_PWD          0x0d                               //~v6d1I~
#define UFTPSMBCMD_STATDIR      0x0e    //stat for the file in the dir all at once//~v6d1I~
#define UFTPSMBCMD_SETMOD       0x0f    //target:window "arsh" attr//~v6d7I~
                                                                   //~v6d1I~
#define F3SMBO_CMDMASK         0xff                                //~v6d1I~
#define F3SMBO_INITCMD       0x0100                                //~v6d1R~
#define F3SMBO_STDIN         0x0200                                //~v6d1R~
#define F3SMBO_LOG           0x0400                                //~v6d1I~
#define F3SMBO_ERRCHK        0x0800                                //~v6d1I~
#define F3SMBO_WIN           0x1000                                //~v6d1I~
#define F3SMBO_MULTISTART    0x2000 //multiline start              //~v6d1R~
#define F3SMBO_MEMBCHK       0x4000 //chk member on fullpath       //~v6d1I~
#define F3SMBO_SINGLESTART   0x8000 //position to single cmd data start line//~v6d1I~
#define F3SMBO_MEMBCMP     0x010000 //filename compare             //~v6d1R~
#define F3SMBO_NFMSG       0x020000 //uerrmsg when NT_STATUS_OBJECT_NAME_NOT_FOUND for setcmd()//~v6d1R~
#define F3SMBO_MULTIENTRY  0x040000 //multiple delete/rename(no response when successed)//~v6d1I~
#define F3SMBO_RETFOUND    0x080000 //multiple delete/rename(no response when successed)//~v6d1I~
//******************************************************           //~v61pI~
int uftp3setssh(int Popt,PUFTPHOST Ppuftph,char *Plinedata,char **Ppnextdata);//~v61pI~
//******************************************************           //~v61pI~
int uftp3editpsftpcmd(int Popt,PUFTPHOST Ppuftph,int Pftpcmdopt,char *Pcmd,char *Pftpcmd,char *Psubcmdhdr,char *Ptempfnm);//~v61pR~
//******************************************************           //~v61pI~
int uftp3cmdrespchk(int Popt,PUFTPHOST Ppuftph,char **Ppstdo,int Pstdoctr);//~v61pI~
//******************************************************           //~v61pI~
int uftp3cmdresphdrchk(int Popt,PUFTPHOST Ppuftph,char ***Pppstdo,int *Ppstdoctr);//~v61pI~
//******************************************************           //~v61pI~
int uftp3gethomesub(int Popt,PUFTPHOST Ppfh,char **Pstdo,int Pstdoctr);//~v61pI~
//******************************************************           //~v61pI~
int uftp3srchcmdecho(int Popt,PUFTPHOST Ppuftph,char ***Pppstdo,int *Ppstdoctr,char *Pcmd);//~v61pI~
//******************************************************           //~v61pI~
int uftp3simplerespchk(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pokresp,char *Pparm,char ***Ppstdo,int *Ppstdoctr,int Prc);//~v61pI~
//******************************************************           //~v61pI~
int uftp3lchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm);//~v61pI~
//******************************************************           //~v61pI~
int uftp3getputrespchk(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pparm,char ***Ppstdo,int *Ppstdoctr,int Prc);//~v61pI~
//******************************************************           //~v61pI~
int uftp3multirenamerchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pI~
//******************************************************           //~v61pI~
int uftp3multidelrchk(int Popt,PUFTPHOST Ppuftph,PUFWF2PARM Ppfwf2p,char **Ppstdo,int Pstdoctr);//~v61pR~
//******************************************************           //~v61pI~
int uftp3simplerespchkCHNG(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pfnm,char ***Ppstdo,int *Ppstdoctr,int Prc);//~v61pI~
#define UFTP3SRCC_CHMOD      0x01          //chmod file name end if ":"//~v61pI~
#define UFTP3SRCC_ERRMSG     0x0100        //issue errmsg          //~v61pI~
//******************************************************           //~v61pI~
int uftp3simplerespchkOK(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pcmd2,char ***Ppstdo,int *Ppstdoctr,int Prc);//~v61pI~
#define UFTP3SRCO_ERRMSG     0x0100        //issue errmsg          //~v61pI~
//******************************************************           //~v61pI~
int uftp3cdrespchk(int Popt,PUFTPHOST Ppuftph,char *Pparm,char ***Ppstdo,int *Ppstdoctr);//~v61pI~
//******************************************************           //~v61pI~
int uftp3setsmb(int Popt,PUFTPHOST Ppuftph,char *Plinedata,char **Ppnextdata);//~v6d1I~
//******************************************************           //~v6d1I~
int uftp3smb_setcmd(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char *Pchp1,char *Pchp2,int Pint1,int Pint2);//~v6d1I~
//******************************************************           //~v6d1I~
int uftp3smbcmd(int Popt,PUFTPHOST Ppuftph,char *Pcmd,char ***Pstdo,int *Pstdoctr,FTPCMD_CALLBACK *Pfunc,void *Ppvoid);//~v6d1R~
//******************************************************           //~v6d1I~
int uftp3smb_editcmdline(int Popt,PUFTPHOST Ppuftph,char *Pftpcmd,char *Psmbcmdline,char *Pstdincmd);//~v6d1R~
//******************************************************           //~v6d1I~
int uftpgetwday(char *Pwday);                                      //~v6d1I~
//******************************************************           //~v6d1I~
int uftpgetmonth(char *Pmonth);                                    //~v6d1I~
//******************************************************           //~v6d1I~
int uftp3smb_getdl1(PUFTPHOST Ppuftph,char *Prec,PUDIRLIST Ppudl); //~v6d1I~
//******************************************************           //~v6d1I~
unsigned int uftp3smb_fstatudl(int Popt,PUFTPHOST Ppuftph,char *Pfpnm,PUDIRLIST Ppudl);//~v6d1R~
//******************************************************           //~v6d1I~
int uftp3smb_lchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm);//~v6d1I~
//******************************************************           //~v6d1I~
int uftp3smb_respchk(int Popt,PUFTPHOST Ppuftph,char *Pfnm,char ***Ppstdo,int *Ppstdoctr,int Prc);//~v6d1R~
//******************************************************           //~v6d1I~
int uftp3smb_lchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm);//~v6d1I~
//******************************************************           //~v6d1I~
char *uftp3smb_strfname(int Popt,PUFTPHOST Ppuftph,char *Pline,char *Pfname);//~v6d1R~
//******************************************************           //~v6d1I~
int uftp3smb_putstmt(int Popt,PUFTPHOST Ppftph,FILE *Pfh,char *Popd1,char *Popd2);//~v6d1I~
//******************************************************           //~v6d1I~
int uftp3smb_getdirlistctr(int Popt,PUFTPHOST Ppuftph,char **Pstdo,int Pstdoctr);//~v6d1I~
//******************************************************           //~v6d1I~
int uftp3smb_getdlattr(int Popt,PUFTPHOST Ppuftph,char *Pfpath,int Ppathlen,PUDIRLIST Ppudl,int Pfileno);//~v6d1R~
//******************************************************           //~v6d1I~
char *uftp3smb_dirnameforlist(int Popt,PUFTPHOST Ppuftph,char *Pdirname,char *Poutpath);//~v6d1I~
//******************************************************           //~v6d1I~
ULONG uftp3smb_mode2attr_win(int Popt,PUFTPHOST Ppuftph,PUDIRLIST Ppudl);//~v6d7I~
//******************************************************           //~v6d7I~
ULONG uftp3smb_mode2attr_winsub(int Popt,ULONG Pmodeattr);         //~v6d7I~
//******************************************************           //~v6d7I~
ULONG uftp3smb_setmod_win(int Popt,PUFTPHOST Ppuftph,char *Pfpath,ULONG Poldattr,ULONG Pattron,ULONG Pattroff);//~v6d7R~
//******************************************************           //~v6d7I~
int uftp3smb_nodeinit(PUFTPHOST Ppuftph);                          //~v6d1I~//~v6daM~
//******************************************************           //~v6daI~
#ifdef ARMXXE                                                      //~v6daI~
int uftp3smb_nodetest(int Popt,PUFTPHOST Ppuftph);                 //~v6daI~
#endif                                                             //~v6daI~
#endif //FTPSUPP                                                   //~v61pI~
