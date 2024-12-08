//*CID://+v5mQR~:                             update#=  403;       //~v5mQR~
//******************************************************           //~v5j4I~
//*u3270.h                                                         //~v5j4I~
//*****************************************************            //~v5mHR~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mJ:080629 3270:returns cursor pos for rsh req                  //~v5mJI~
//v5mH:080629 3270:num std fld consideration for SJIS->EBC translation//~v5mHI~
//v5mD:080625 3270:issue stow failed msg                           //~v5mDI~
//v5mB:080621 3270:DBCS conversion support                         //~v5mBI~
//v5kg:070530*(3270)accept long line split by fixed lrecl at put confiramtion chk//~v5kgI~
//v5jB:061205 3270:=6 TSO mode support                             //~v5jBI~
//v5jy:061123 3270:SPF information update                          //~v5jyI~
//v5jv:061116 3270:spf info support by xe4s001z                    //~v5jvI~
//v5ju:061116 3270:listds fail by 'sys1.*' because sys1.duplex has no dsorg recfm//~v5juI~
//v5jr:061103 (3270) return D/S info weven when member not found   //~v5jrI~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5jc:061002 3270 support:dsn wildcard support                    //~v5jcI~
//v5jb:061002 3270 support:udirlist support                        //~v5jbI~
//v5j4:060914 ftp:3270 support (xehost TSO=portno operand)         //~v5j4I~
//******************************************************           //~v5j4I~
#ifdef FTPSUPP                                                     //~v5jcI~
                                                                   //~v5jcI~
#define DSN_SEPS             ".("                                  //~v5jbI~
#define DSN_SEPS2            ")'"                                  //~v5jcI~
#define DSN_WILD             '*'                                   //~v5jcR~
#define DSN_SEPCMEMB         '('                                   //~v5jbI~
#define DSN_SEPC             '.'                                   //~v5j4R~
#define DSN_SEPCMEMB         '('                                   //~v5j4R~
#define DSN_SEPCMEMB2        ')'                                   //~v5j4I~
#define DSN_QUOTE            '\''                                  //~v5j4I~
#define DSN_MAXLEN           128     //44 is max                   //~v5jdR~
#define DSN_MAXMEMBERNAMELEN 8                                     //~v5j4R~
#define MEMBOFDSN(dsn)       (strchr((dsn),DSN_SEPCMEMB))          //~v5j4R~
#define DSNWILDCARD(dsn)     (strchr((dsn),DSN_WILD))              //~v5jcI~
#define DSNWILD_MEMB(dsn)     (DSNWILDCARD(dsn)!=0 && MEMBOFDSN(dsn)!=0 && DSNWILDCARD(dsn)>MEMBOFDSN(dsn))//~v5jdI~
#define DSNWILD_DSN(dsn )     (DSNWILDCARD(dsn)!=0 && (MEMBOFDSN(dsn)==0 || DSNWILDCARD(dsn)<MEMBOFDSN(dsn)))//~v5jdI~
#define DSNSIMPLENAME(dsn) (strpbrk(dsn,DSN_SEPS)==0)              //~v5jdR~
#define DUMMYMEMBER "MEMBNAME"  //if membername specified          //~v5j4I~
#define DUMMYMEMBERSZ 8                                            //~v5j4I~
                                                                   //~v5j4I~
#define MAX_CMDSZ        1024                                      //~v5j4M~
#define MAX_RESPSZ       MAX_UERRMSGLL	//uerr.h                   //~v5j4M~
#define CP939            "CP939"    //katakana intos english lowercase letter//~v5mBR~
#define CP930            "CP930"    //english lowercase letter into katakana//~v5mBR~
#define CPCJK            "OTHER"    //mapping defined by xe3270ftp.map//~v5mQR~
#define CPNODBCS         "NO"       //not dbcs                     //+v5mQI~
#define TSOFTP_PARM_RECFMF  "fixed"      //ftp option              //~v5mBI~
#define TSOFTP_PARM_RECFMV  "variable"   //ftp option              //~v5mBI~
#define TSOFTP_PARM_RECFMU  "undefined"  //ftp option              //~v5mBI~
#define TSOFTP_PARM_LRECL   "lrecl="      //ftp option             //~v5mBR~
#define TSOFTP_PARM_DBCS    "DBCS="      //ftp option              //~v5mBI~
#define TSOFTP_PARM_DBCSDEF "DBCS"       //default(CP939)          //~v5mBI~
#define TSOFTP_PARM_NUMSTD  "std"        //num std option          //~v5mHI~
                                                                   //~v5j4I~
//******************************************************           //~v5j4I~
typedef struct _PIPERESPDATA {                                     //~v5jbI~
									int PRDlen;                    //~v5jbM~
									int PRDtype;                   //~v5jbM~
#define PRDT_MEMBL      1          //member list                   //~v5jbM~
#define PRDT_DSNL       2          //dsn list                      //~v5jbM~
#define PRDT_RSHRESP    3          //screen image                  //~v5jBI~
									int PRDcount;                  //~v5jbM~
					} PIPERESPDATA,*PPIPERESPDATA;                 //~v5jbM~
#define PIPERESPDATASZ sizeof(PIPERESPDATA)                        //~v5jbI~
                                                                   //~v5jBI~
typedef struct _DSNDATA {                                          //~v5jbM~
						char DSDdsn[DSN_MAXLEN];  	//dsn          //~v5jbR~
						int  DSDflag;                              //~v5jbM~
#define DSDFPO          0x01   //DSORG=PO                          //~v5jbM~
#define DSDFPS          0x02   //DSORG=PS                          //~v5jbM~
#define DSDFVS          0x04   //DSORG=UNKNOWN(vsam etc)           //~v5juI~
#define DSDFF           0x10   //RECFM=F                           //~v5jbR~
#define DSDFV           0x20   //RECFM=V                           //~v5jbR~
#define DSDFB           0x40   //RECFM=B                           //~v5jbR~
#define DSDFMEMB        0x80   //MEMBER NAME SPECIFIED             //~v5jcI~
#define DSDFMEMBNOTFOUND 0x0100//member not found                  //~v5jrI~
						int  DSDlrecl;                             //~v5jbM~
						int  DSDblksize;                           //~v5jbM~
                    } DSNDATA,*PDSNDATA;                           //~v5jbI~
#define DSNDATASZ  (sizeof(DSNDATA))                               //~v5jbI~
//****                                                             //~v5jvI~
typedef struct _PDSSPFINFO  {                                      //~v5jvM~
                    int    SPFIflag;                               //~v5jvM~
#define SPFIFALIAS         0x01   //alias entry                    //~v5jvM~
#define SPFIFSPF           0x02   //spf information exist          //~v5jvM~
					char   SPFImember[DSN_MAXMEMBERNAMELEN+1];     //~v5jvM~
                    char   SPFIuserid[9];                          //~v5jvM~
					int    SPFIver;       //version                //~v5jvM~
					int    SPFImod;       //modification level     //~v5jvM~
					FDATE  SPFIcdate;     //creation date          //~v5jvM~
					FDATE  SPFIudate;     //last updated           //~v5jvM~
					FTIME  SPFIutime;     //last updated           //~v5jvM~
					int    SPFIlinecnt;   //line count             //~v5jvM~
					int    SPFIinitcnt;   //initial line count     //~v5jvM~
                    } PDSSPFINFO,*PPDSSPFINFO;                     //~v5jvM~
#define PDSSPFINFOSZ sizeof(PDSSPFINFO)                            //~v5jvM~
//***                                                              //~v5jvI~
typedef struct _DSNLIST {                                          //~v5jbM~
					PIPERESPDATA DSLhdr;                           //~v5jbR~
    				PDSSPFINFO DSLspfi; //filled when member specified//~v5jvI~
			        DSNDATA  DSLentry[1];                          //~v5jbR~
                    } DSNLIST,*PDSNLIST;                           //~v5jbM~
#define DSNLHDRSZ  (offsetof(DSNLIST,DSLentry[0]))                 //~v5jbM~
//***                                                              //~v5jvI~
typedef struct _PDSMEMBLIST {                                      //~v5j4M~
					PIPERESPDATA PMLhdr;                           //~v5jbI~
			        DSNDATA      PMLdsnd;     //blksz etc          //~v5jbR~
//#define PMLMEMBNAMEFLDSZ (DSN_MAXMEMBERNAMELEN+1)                //~v5jvR~
//  				char PMLmember[1][PMLMEMBNAMEFLDSZ];           //~v5jvR~
    				PDSSPFINFO PMLmember[1];                       //~v5jvI~
                    } PDSMEMBLIST,*PPDSMEMBLIST;                   //~v5j4M~
//#define PDSMEMBLISTHDRSZ  (offsetof(PDSMEMBLIST,PMLmember[0][0]))//~v5jvR~
#define PDSMEMBLISTHDRSZ  (offsetof(PDSMEMBLIST,PMLmember[0]))     //~v5jvI~
                                                                   //~v5jBI~
typedef struct _SCRDATA {                                          //~v5jBM~
				    		PIPERESPDATA SCRhdr;                   //~v5jBI~
                            int          SCRmaxrow;                //~v5mJR~
                            int          SCRmaxcol;                //~v5mJR~
                            int          SCRcurrow;                //~v5mJR~
                            int          SCRcurcol;                //~v5mJR~
			    			int          SCRlen;                   //~v5jBI~
			    			char         SCRdata[1];               //~v5jBI~
                        } SCRDATA,*PSCRDATA;                       //~v5jBI~
#define SCRDATAHDRSZ  (offsetof(SCRDATA,SCRdata))                  //~v5jBI~
                                                                   //~v5mBI~
typedef struct _UTSOFTPPARM  {                                     //~v5mBR~
				    			int          UTSOFPflag;           //~v5mBI~
#define UTSOFTPF_DBCSCONV    0x01    //DBCS conversion             //~v5mBI~
#define UTSOFTPF_NUMSTD      0x02    //last 8 byte of line is linenumber//~v5mHI~
				    			ULONG        UTSOFPattr;    //fix/variable etc//~v5mBR~
			    				ULONG        UTSOFPsrcattr; //lrecl+blksz//~v5mBR~
                        } UTSOFTPPARM,*PUTSOFTPPARM;               //~v5mBR~
#define UTSOFTPPARMSZ  (sizeof(UTSOFTPPARM))                       //~v5mBR~
                                                                   //~v5jBM~
//******************************************************           //~v5j4I~
int u3270init(void **Poptons);                                     //~v5j4I~
//******************************************************           //~v5j4I~
unsigned int u3270fstat(PUFTPHOST Ppuftph,char *Pfpath,FILEFINDBUF3 *Ppffb3);//~v5j4I~
//******************************************************           //~v5jdI~
int u3270findfile(int Popt,PUFTPHOST Ppuftph,char *Pfpath,FILEFINDBUF3 *Ppffb3,int *Ppentno);//~v5jdI~
#define U3FF_NONOTFOUNDMSG    0x01                                 //~v5jdI~
//******************************************************           //~v5j4I~
char *u3270getcwd(PUFTPHOST Ppuftph,char *Poutbuff);               //~v5jdR~
//******************************************************           //~v5jdI~
int u3270chdir(PUFTPHOST Ppuftph,int Popt,unsigned char *Ppath);   //~v5jdI~
//******************************************************           //~v5jdI~
char *u3270fullpath(PUFTPHOST Ppuftph,char *Pfullpath,char *Pfname,size_t Plen);//~v5j4I~
//******************************************************           //~v5jdI~
int u3270fullpathistso(char *Pfullpath);                           //~v5jdR~
//******************************************************           //~v5j4I~
int u3270getmembname(int Popt,char *Pfilename,char *Pmembname);    //~v5j4I~
#define U3GM_DUMMYREP  0x01   //set dummy member if not membername exist in fullpath//~v5jdI~
#define U3GM_WILDREP   0x02   //replace wildcard member by "@"     //~v5jdR~
#define U3GM_RETLENERR 0x04   //return err when length over        //~v5jdI~
//******************************************************           //~v5jdI~
int u3270chkmembname(int Popt,char *Pmembname);                    //~v5jdR~
#define U3CM_CHKWILD  0x01   //chk "*" as valid(return minus)      //~v5jdI~
//******************************************************           //~v5jcI~
int u3270getlastname(int Popt,char *Pfilename,char *Plastname);    //~v5jcI~
//******************************************************           //~v5jdI~
int u3270getnthname(char *Pfilename,int Plevel,char *Pnthname);    //~v5jdI~
//******************************************************           //~v5jdI~
int u3270parsedsn(int Popt,char *Psrc,char *Pdsn,char *Plastname); //~v5jdI~
#define U3PD_RC_MEMBER   0x01   //lastname ismembername            //~v5jdI~
#define U3PD_RC_WILD     0x02   //lastname wildcard                //~v5jdI~
//******************************************************           //~v5jcI~
int u3270concatfilename(int Popt,char *Psrc,char *Pappendname,char *Pout);//~v5jcI~
#define U3CF_FORCEASMEMBERIFNOTWILD  0x01   //append as membername if target is not wildcard//~v5jcR~
#define U3CF_REPMEMBER               0x02   //replace old meber specification exist//~v5jcI~
#define U3CF_REPLAST                 0x04   //replace old DSN last entry//~v5jdI~
#define U3CF_REPLASTORMEMBER    (U3CF_REPMEMBER|U3CF_REPLAST)      //~v5jdI~
//******************************************************           //~v5jdI~
int u3270editname(PUFTPHOST Ppuftph,int Popt,UCHAR *Psource,UCHAR *Ppatern,UCHAR *Ptarget);//~v5jdR~
#define U3EN_WILDSOURCE    0x01 //src conatain wild card,patern contain source member name//~v5jdI~
#define U3EN_SRCLOCAL      0x02 //src local and patern is TSO      //~v5jdI~
//******************************************************           //~v5j4I~
int u3270parentdsn(int Popt,char *Psrc,char *Pout);                //~v5jcI~
#define U3PD_PATHLENMASK            0xff                           //~v5jdR~
#define U3PD_DROPQUOTE            0x0100                           //~v5jdI~
#define U3PD_DROPHOSTID           0x0200                           //~v5jdI~
//******************************************************           //~v5jdI~
int u3270getsetdsnwild(int Popt,char *Psrc,char *Pout,char *Pwild,int *Pplevel);//~v5jdR~
#define U3DW_GET           0x00                                    //~v5jdI~
#define U3DW_SET           0x01                                    //~v5jdI~
//******************************************************           //~v5jcI~
int u3270pathlen(int Psamedirsw,char *Pdsn);                       //~v5j4I~
#define U3PL_DROPMEMBER              1                             //~v5jcI~
#define U3PL_PARENT                  0                             //~v5jcI~
#define U3PL_PARENTORDROPMEMBER      2                             //~v5jcI~
#define U3PL_DROPWILDORMEMBER        3  //drop member or last wild //~v5jdI~
//******************************************************           //~v5j4I~
int u3270membsrch(PPDSMEMBLIST Pppml,char *Ppmember);              //~v5j4R~
//******************************************************           //~v5j4I~
int u3270sethostuser(PUFTPHOST Ppuftph,char *Ppcmdverb,char *Ppcmdstr);//~v5j4I~
//******************************************************           //~v5j4I~
int u3270cmdrequest(int Popt,char *Pcmd,void **Pppvoid,int *Ppdatalen);//~v5j4R~
#define U3CRO_UERRMSG      0x01   //issue uerrmsg from respmsg     //~v5j4R~
#define U3CRO_UERRMSGIFERR 0x02   //issue uerrmsg from respmsg if rc!=0//~v5j4I~
#define U3CRO_TSOMODE      0x04   //issue uerrmsg from respmsg if rc!=0//~v5jBI~
#define U3CRO_RETWARNING   0x08   //return warning rc,do not set to rc=0//~v5kgR~
                                                                   //~v5j4I~
#define U3CR_RC_DONE        1   //successfully done//(Win/Linx:1 operation not permit)//~v5jdI~
#define U3CR_RC_NOTFOUND    ERROR_FILE_NOT_FOUND   //Win=2:(Linx:No such File/Dir)seq ds not found//~v5jdR~
#define U3CR_RC_PATHERR     ERROR_PATH_NOT_FOUND   //Win=3:(Linx 3=No Such Process)member specified but pds not exist//~v5jdR~
#define U3CR_RC_DUPNAME     EEXIST                 //Win=17:d/s or member already exist//~v5jdR~
#define U3CR_RC_OTHER       EINVAL                 //Win=22:errmsg should be kept//~v5jdR~
#define U3CR_RC_NOTSUPPORT  ENOSYS                 //Win=40:Linux=37:ulib dose not supported function//~v5jdR~
#define U3CR_RC_INVALIDNAME ENAMETOOLONG           //Win=38:Linux=36:invalid membername//~v5jdR~
#define U3CR_RC_INUSE       EAGAIN                 //Win=11:Linux=11:resource temporary not avail//~v5jyI~
#define U3CR_RC_STOWFAILED  ENOSPC                 //Win=28(no space on device)//~v5mDI~
#define U3CR_RC_WARNING     0x1000                 //success but request errmsg disply//~v5kgR~
#define U3CR_RC_SPLIT       U3CR_RC_WARNING+1      //put confirm ok as line split//~v5kgR~
                                                                   //~v5j4M~
//******************************************************           //~v5j4I~
int u3270dirlistsub(PUFTPHOST Ppuftph,int Popt,int *Ppentno,char *Pfpath,ULONG Pattr,PUDIRLIST *Pppudl);//~v5jbI~
//******************************************************           //~v5jdI~
PUDIRLIST u3270srchdirlist(int Popt,int Pentno,PUDIRLIST Ppudl,char *Pmember);//~v5jdI~
#define U3SD_WILD    0x01 //compare by wildcard                    //~v5jdI~
//******************************************************           //~v5jcI~
void u3270setattr(int Precfm,ULONG *Ppattr);                       //~v5jcI~
//******************************************************           //~v5jcI~
//void u3270getattrstr(ULONG Pattr,char *Pattrstr);                //~v5jyR~
void u3270getattrstr(ULONG Pattr,char *Pgname,char *Pattrstr);     //~v5jyI~
//******************************************************           //~v5jcI~
int u3270fullpathwildexp(int Popt,PUFTPHOST Ppuftph,char *Pfullpath,char *Pfilename,size_t Plen);//~v5jcI~
//******************************************************           //~v5jcI~
int u3270errdsnpath(char *Pdsn);                                   //~v5jcI~
//******************************************************           //~v5jdI~
#endif                                                             //~v5jcI~
