//*CID://+v6htR~:                             update#=  248;       //~v6htR~
//******************************************************
//*uftp1.h                                                         //~v59dR~
//******************************************************
//v6ht:120729 (LNX)display odd number file time stamp              //~v6htI~
//v6d1:120131 (SMB)share option for SAMBA node(win64  192.168.2.19 usrskt pswd  share=p)//~v6d1I~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61n:080121*Bug report by M.J(LCD fail when LANG is not english) //~v61nI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5fn:050317 (FTP)undel support                                   //~v5fnI~
//v5fd:050101 (FTP)fulction to delete multiple file at once.       //~v5fdI~
//v5c8:040331 (FTP:BUG)uftpfullpath:parm may not contain remoteID(slink not found msg)//~v5c8I~
//v5b6:040124 (FTP)move(copy & del)support                         //~v5b6I~
//v5am:040110 (FTP)del file in a dir at once for performance       //~v5amI~
//v5af:040106 pass PUFTPHOST as parm not but nodename to chk TZ,SJIS option etc//~v5afI~
//v59d:030816 ftp support
//******************************************************
#ifdef FTPSUPP                                                     //~v59dI~
                                                                   //~v5amI~
typedef struct _UFWF2PARM{   //wild func parm                      //~v5amI~
                      int         UFWF2Popt;                       //~v5amR~
                      char       *UFWF2Pfpath;     //dir name      //~v5amI~
#define UFWF2PFPATH_MULTIDEL	  0       //id of multidel         //~v5fdI~
                      ULONG       UFWF2Pattrmask;                  //~v5amI~
                      UINT       *UFWF2Pwildparm;                  //~v5amR~
                      PUDIRLIST   UFWF2Ppudl;      //pudl top      //~v5amM~
                      int         UFWF2Ppudlctr;   //pudl entry    //~v5amM~
                      int         UFWF2Ppathlen;   //output cmd put count//~v5amI~
                      int         UFWF2Pcmdctr;    //output cmd put count//~v5amI~
                      int         UFWF2Pcmdokctr;    //output cmd put count//~v5amI~
//                    long        UFWF2Pfilesize;  //output filesize//~v5k0R~
                      FILESZT     UFWF2Pfilesize;  //output filesize//~v5k0I~
                      PUFTPHOST   UFWF2Ppuftph;    //if ftp        //~v6d1R~
                    } UFWF2PARM,*PUFWF2PARM;                       //~v5amR~
#define UFWF2PARMSZ (sizeof(UFWF2PARM))                            //~v5amR~
                                                                   //~v5fdI~
typedef struct _UFTPMULTIDEL{   //wild func parm                   //~v5fdI~
                      int         UFMDflag; 	//internalctl      //~v5fdI~
#define UFMDFDELREQ   0x01        //ftp delete issued              //~v5fdI~
                      ULONG       UFMDattr; 	//internalctl      //~v5fdI~
                      int         UFMDrc;		//return code      //~v5fdI~
#define UFMDRC_TYPEERR  18  //dir,special,readonly                 //~v5fdI~
                      char       *UFMDpfpath;	//fpathname to be delete//~v5fdI~
                      void       *UFMDparm;  	//other user parm  //~v5fdI~
                      		} UFTPMULTIDEL,*PUFTPMULTIDEL;         //~v5fdI~
#define UFTPMULTIDELSZ (sizeof(UFTPMULTIDEL))                      //~v5fdI~
                                                                   //~v5fnI~
typedef struct _UFTPMULTIRENAME{   //wild func parm                //~v5fnI~
                      int         UFMRflag; 	//internalctl      //~v5fnI~
#define UFMRFRENAMEREQ   0x01      //ftp delete issued             //~v5fnR~
                      ULONG       UFMRattr; 	//internalctl      //~v5fnI~
                      int         UFMRrc;		//return code      //~v5fnI~
#define UFMRRC_TYPEERR  18  //dir,special,readonly                 //~v5fnI~
                      char       *UFMRpfpath;	//fpathname to be delete//~v5fnI~
                      char       *UFMRpnewname;	//rename to        //~v5fnI~
                      void       *UFMRparm;  	//other user parm  //~v5fnI~
                      		} UFTPMULTIRENAME,*PUFTPMULTIRENAME;   //~v5fnI~
#define UFTPMULTIRENAMESZ (sizeof(UFTPMULTIRENAME))                //~v5fnI~
                                                                   //~v5amI~
typedef int (FTP_WILDAPPLYFUNC)(PUFTPHOST,UCHAR *,PUDIRLIST,void*);//~v5afR~
                                                                   //~v5amI~
//*******************************************************          //~v5amI~
FTPCMD_CALLBACK uftpwildxdel;                                      //~v5amI~
FTPCMD_CALLBACK uftpmultidelsub;                                   //~v5fdI~
FTPCMD_CALLBACK uftpmultirenamesub;                                //~v5fnI~
//*******************************************************          //~v59dI~
unsigned int uftpfstat(PUFTPHOST Ppuftph,char *Pfpath,FILEFINDBUF3 *Ppffb3);//~v5afR~
//*******************************************************          //~v59dI~
int uftpfindfirst(PUFTPHOST Ppuftph,int Popt,char *Ppfname,ULONG *Pphdir,unsigned int Pattr,//~v5afR~
                        FILEFINDBUF3 *Ppfstat3);                   //~v59dI~
#define UFTPFF_NOMSG     0x01                                      //~v59dI~
//*******************************************************          //~v59dI~
unsigned uftpfindnext(int Phdir,FILEFINDBUF3 *Ppfstat3);           //~v59dR~
//*******************************************************          //~v59dI~
int uftpdirlistsub(PUFTPHOST Ppuftph,int Popt,int *Ppentno,char *Pfpath,ULONG Pattr,PUDIRLIST *Pppudl);//~v5afR~
#define  FTP_DLSNONFMSG      0x01 	//hdir id  for FTP             //~v59dI~
//*******************************************************          //~v59dI~
int uftpchdir(PUFTPHOST Ppuftph,int Popt,unsigned char *Ppath);    //~v5afR~
//*******************************************************          //~v59dI~
char *uftpgetcwd(char *Phost,unsigned char *Pbuff);                //~v59dI~
//*******************************************************          //~v59dI~
char *uftpfullpath(PUFTPHOST Ppuftph,char *Pfullpath,char *Pfname,size_t Plen);//~v5afR~
//*******************************************************          //~v5c8I~
char *uftpfullpathnorid(PUFTPHOST Ppuftph,char *Pfullpath,char *Pfname,size_t Plen);//~v5c8I~
//*******************************************************          //~v59dI~
int uftpattrib(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pattron,ULONG Pattroff,ULONG *Poutattr);//~v5afR~
//*******************************************************          //~v59dI~
int uftpattrxon(PUFTPHOST Ppuftph,UCHAR *Pfname);                  //~v5afR~
//*******************************************************          //~v59dI~
int uftpgetftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE *Pdate,FTIME *Ptime);//~v5afR~
//*******************************************************          //~v6htI~
int uftpgetftime_1sec(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE *Pdate,FTIME *Ptime,int *Ppoddsec);//+v6htR~
//*******************************************************          //~v59dI~
int uftpsetftime(PUFTPHOST Ppuftph,UCHAR *Pfname,FDATE Pdate,FTIME Ptime);//~v5afR~
//*******************************************************          //~v59dI~
int uftpmkdir(PUFTPHOST Ppuftph,UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode);//~v5afR~
//*******************************************************          //~v59dI~
int uftpmkdirmode(PUFTPHOST Ppuftph,UCHAR *Pdirname,ULONG Pmode,ULONG *Pprmode);//~v5afR~
//*******************************************************          //~v59dI~
int uftprmdir(PUFTPHOST Ppuftph,UCHAR *Pdirname);                  //~v5afR~
//*******************************************************          //~v59dI~
int uftpremove(PUFTPHOST Ppuftph,int Popt,UCHAR *Pfilename);       //~v5afR~
//*******************************************************          //~v59dI~
int uftprename(PUFTPHOST Ppuftph,int Popt,UCHAR *Poldname,UCHAR *Pnewname,UCHAR *Pnewspec);//~v5afR~
//*******************************************************          //~v59dI~
int uftpattrxchk(PUFTPHOST Ppuftph,UCHAR *Pfname,int Popt);        //~v5afR~
#ifdef UNX                                                         //~v59dI~
	#define UFTPAXC_MSG	 UAXC_MSG                                  //~v59dI~
#else                                                              //~v59dI~
	#define UFTPAXC_MSG	 0x01                                      //~v59dI~
#endif                                                             //~v59dI~
//*******************************************************          //~v59dI~
int uftpcopypathinfo(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,UCHAR *Psource,UCHAR *Ptarget);//~v5afR~
//*******************************************************          //~v59dI~
ULONG uftpmode2attr(PUDIRLIST Ppudl);                              //~v59dM~
//*******************************************************          //~v59dI~
int uftpsetftime2(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Patime,ULONG Pmtime);//~v5afR~
//*******************************************************          //~v59dI~
int uftpsetown(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Puid,ULONG Pgid);//~v5afR~
//*******************************************************          //~v59dI~
int uftpsetmod(PUFTPHOST Ppuftph,UCHAR *Pfname,ULONG Pmode);       //~v5afR~
//*******************************************************          //~v59dM~
int uftpnotsupported(char *Pcmd,char *Pfnm);                       //~v59dM~
//*******************************************************          //~v59dI~
int uftpnotsupportedforlocal(char *Pcmd,char *Pfnm);               //~v59dI~
//*******************************************************          //~v59dI~
int uftpxcopy(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,               //~v5afR~
			UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask);//~v5afI~
//*******************************************************          //~v59dI~
int uftpxmove(PUFTPHOST Ppuftphs,PUFTPHOST Ppuftpht,               //~v5b6I~
			UCHAR *Psource,UCHAR *Ptarget,int Popt,unsigned Pattrmask);//~v5b6I~
//*******************************************************          //~v5b6I~
int uftpwildfunc(PUFTPHOST Ppuftph,UCHAR *Psource,unsigned Pattrmask,//~v5afR~
                FTP_WILDAPPLYFUNC *Pfunc,void *Pparm,int *Pfilectr);//~v59dI~
//*******************************************************          //~v5amI~
int uftpwildfunc2(int Popt,UCHAR *Psource,unsigned Pattrmask,      //~v5amI~
//              FTPCMD_CALLBACK *Pfunc,void *Pparm,int *Ppfilectr,long *Ppfilesize);//~v5k0R~
                FTPCMD_CALLBACK *Pfunc,void *Pparm,int *Ppfilectr,FILESZT *Ppfilesize);//~v5k0I~
//*******************************************************          //~v5fdI~
int uftpmultidel(int Popt,PUFTPHOST Ppuftph,PUFTPMULTIDEL Ppfmd,   //~v5fdR~
                 int Pfilectr,void *Pparm);                        //~v5fdI~
//*******************************************************          //~v5fnI~
int uftpmultirename(int Popt,PUFTPHOST Ppuftph,PUFTPMULTIRENAME Ppfmr,//~v5fnI~
                 int Pfilectr,void *Pparm);                        //~v5fnI~
//*******************************************************          //~v59dI~
int uftplchdir(PUFTPHOST Ppuftph,int Popt,char *Pdirname);         //~v5afR~
//*******************************************************          //~v59dI~
//int uftplchdirrespchk(char ***Ppstdo,int *Ppstdoctr);            //~v61nR~
//int uftplchdirrespchk(char ***Ppstdo,int *Ppstdoctr,char *Pdirnm);//~v61pR~
int uftplchdirrespchk(int Popt,PUFTPHOST Ppuftph,char ***Ppstdo,int *Ppstdoctr,char *Pdirnm);//~v61pI~
#endif //FTPSUPP                                                   //~v59dI~
