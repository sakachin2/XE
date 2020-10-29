//*CID://+vaq1R~:                             update#=  243;       //~vaq1R~
//***********************************************************
//* XFS : seperate large file into sub files                       //~v142R~
//***********************************************************
#define VER "V2.8"   //version                                     //~va95R~//~va9sR~
//***********************************************************
//vaq1:201029 Debian10 compiler warning -Wformat-overflow          //~vaq1I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//va9s:150529 xfs v2.8 parm count error(by xuerpck)                //~va9sI~
//va95:150106 xfs v2.7 C:\ may be protected,change open error msg  //~va95I~
//va76:130622 compiler warning and err by ndk-r9                   //~va76I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va58:111217 compiler warning,uninitialized                       //~va58I~
//va4a:090320 xfs v2.5 (BUG)for the case org file is space embedding filename//~va4aI~
//va49:090320 xfs v2.5 restore from subfile in copyed directory if subfile open failed//~va49I~
//va48:081011 ugetdiskfree interface changed for UNC(\\...) filename support//~va48I~
//va30:061227 xfs v2.3:filesize>4GB support                        //~va30I~
//va2a:040919 xfs:v1.9 (OS2:BUG of va1i) 8.3 name for also os/2    //~va2aI~
//va22:050204 xfs:v2.1:continue record seperater search not only 1 buffsz(for huge record over 128K)//~va22R~
//va21:050203 xfs:v2.1:(BUG)record seperator fmt change;/Se"2xyz" format treated as offset=2 of string xyz//~va20I~
//va20:050123 xfs:v2.1:(LNX:BUG)temdir remains at /tmp for MDOSDISK use//~va20I~
//va1Z:050123 xfs:v2.1:(LNX:BUG)conform msg is SJIS;force englist when linux//~va1ZI~
//va1Y:050123 xfs:v2.1:(LNX:BUG)list attr MDOSDISK consideration required//~va1YI~
//va1X:050123 xfs:v2.1:(LNX:BUG)utempnam(mkstemp) cleate tempfile,for mkdir fail by already exist//~va1XI~
//va1F:041120 xfs:v1.9:support /yr (req size by record count)      //~va1FI~
//va1E:041120 xfs:v1.9:record split string support for also lineno parm case//~va1CI~
//va1D:041117 xfs:v1.9:size support K and M postfix                //~va1DI~
//va1C:041117 xfs:v1.9:record split string support for multiline text file//~va1CR~
//va1B:041117 xfs:v1.9:(BUG)text mode max lien is 4096(previous 1s 512)//~va1BI~
//                      it should be same as crlf back search length//~va1BI~
//va1j:040905 xfs:v1.9:(UNX:BUG) NUL is /dev/null for unix         //~va1jI~
//va1i:040905 xfs:v1.9 avoid dup filename for ctl file except dos  //~va1iI~
//020706 xfs v177 v1.8 (GCC)protect drive not ready abend          //~v177I~
//020703 xfs v176 (UNX) chk drive ready(DOS prompt ready,but UNX return i/o err)//~v176I~
//020702 xfs v175 (AIX) skip time stamp chk(AIX fd cannot be set time stamp)//~v175I~
//020702 xfs v174 Readonly confirmation(especialy AIX cannot del RONLY)//~v174I~
//020630 xfs v173 (BUG)open fail at verify if size=0;reject if inpsz=0//~v173I~
//020630 xfs v172 (BUG)if filesize=0,total -1 %  written msg       //~v172I~
//020630 xfs v171 (UNX)disket support                              //~v146I~
//*020202 xfs:v146:for compact flush(win return fixed),            //~v146I~
//            support force removable sw                           //~v146I~
//*020202 xfs:v145:default set to text mode whe /yl                //~v144I~
//*020202 xfs:v144:verify default change /Yv for removable only    //~v144I~
//*020202 xfs:v143(v1.7)force ctl rec write to avoid errexit when retry//~v143I~
//            after cancel(file same name as ctl file exist)       //~v143I~
//*010830 xfs:v142 UNIX support:chk eol by only 0x0a(also for dos) //~v142I~
//*010830 xfs:v141 option to split by lineno                       //~v142I~
//*010823 v140 UNX support:no removable support                    //~v140R~
//*000422 v139 verify open err when filesize just multiple of split size//~v139I~
//*990927 v138 allow output is directory for restore               //~v138I~
//*990925 v137 retry when disket write err(W95 no popup but return with rc 13)//~v137I~
//*981128 v136 option to list disket dir                           //~v136I~
//*980915 v135 verify can be stop by Esc                           //~v135I~
//*980915 v134 overridechk for each disk when removable            //~v134I~
//*980915 v133 deny k125;udirlist return -1 if no file found       //~v132I~
//*980913 v132 accept key input only afrer msg put(peek and get)   //~v132I~
//*980912 v131 restart/retry option /#nn(-)                        //~v131R~
//*980912 v130 confirm reply by Enter,Esc,...                      //~v130I~
//*980905 v129 change /t,/b to /Yt,/Nt                             //~v129I~
//*980905 v128 no confirm delete option                            //~v127I~
//*980905 v127 chksum function                                     //~v127I~
//*980831 v126 ubell when uerrexit by uerrexit_optinit             //~v126I~
//*980830 v125 chk invalid format disket                           //~v125I~
//*980830 v124 change default Binaly mode from chk 100 byte of file//~v123I~
//*980830 v123 arange confirm msg                                  //~v123I~
//*980830 v122 display write percentage                            //~v121I~
//*980830 v121 verify func(default when removable)                 //~v111I~
//*980605 v1.2 release ******************************************* //~v134R~
//*980523 v111 use helpmsg for help pause                          //~v111I~
//*980523 v110 (BUG)disk full by pgm copy when disk if fully empty case//~v1.2R~
//*980605 v1.1 release                                             //~v1.1I~
//*980523 v10v index file open err when first subfile is nul       //~v10vI~
//*980523 v10u setftime err for null file                          //~v10uI~
//*980509 v10t errmsg_init for force english to uerrmsg/uerrexit   //~v10tI~
//*980509 v10s reset chance at disket not emptry                   //~v10sI~
//*980509 v10r index exist warning after disket clear              //~v10rI~
//*980509 v10q pgm copy option                                     //~v10qI~
//*980509 v10p (BUG)short subfile written                          //~v10pI~
//*980509 v10o helpmsg                                             //~v10oI~
//*980509 v10n dirsplay org file inf when overwrite                //~v10mI~
//*980509 v10m search index file name if omitted(drive id only)    //~v10lI~
//*980505 v10l use large buff size                                 //~v10lR~
//*980505 v10k removable device support                            //~v10kI~
//*980504 v10j index file output on 1st outfile directory          //~v10jI~
//*980504 v10i num edit ","                                        //~v10hI~
//*980504 v10h restore time stamp when gather                      //~v10hI~
//*980504 v10g display size for gather                             //~v10gI~
//*980503 v10f copy file timestamp to split file                   //~v10fI~
//*980503 v10e abondon v10d,dup operation may reject(same file override case)//~v10eI~
//*980503 v10d output space pre chk                                //~v10bI~
//*980503 v10c /T option(force text)                               //~v10bI~
//*980503 v10b displayb input size                                 //~v10bI~
//*980503 v10a text file split in the range specified filesize     //~v10aR~
//             search crlf reverse                                 //~v10aI~
//*980502 v109 (BUG)output open failed by too many file(need close)//~v109R~
//*980502 v108 (BUG)tex file is split in the line when size is multiple of buffsz//~v108I~
//             cut before over limit filesize.                     //~v108I~
//*980502 v107 chk 1st 100 byte for binaly file,if ontain over 50 byte <x20,trate it binaly//~v107I~
//*980502 v106 allow wild card for not last file,if file no overflow,sw to next//~v106R~
//*980502 v105 allow % as output filename.(edit ?? then concat to filename)//~v105R~
//*980502 v104 (BUG)hex may be long int                            //~v105I~
//*980205 (BUG)gather end with one sub-file.                       //~v120I~
//*940709 def buff as unsigned char for avoid errornouse eff chk(for char ff)
//*940504 first version
//***********************************************************

#define PGM "xfs"                                                  //~v140R~

//**********************************************/
//*parm1 : input file name
//*parm2 : output file1 name
//*parm3 : output file2 name
//*parm4 : output file1 size
//*r.c   : none
//**********************************************/
//*
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#ifdef UNX                                                         //~v140I~
	#include <unistd.h>                                            //~v140I~
#else                                                              //~v140I~
#include <conio.h>                                                 //~v131I~
#endif                                                             //~v140I~
                                                                   //~6831I~
#if defined(DOS) || defined(W32)                                   //~v10kI~
	#include <dos.h>                                               //~v10kI~
    #ifdef DPMI                                                    //~v1.1I~
    	#include <errno.h>                                         //~v1.1I~
    #endif                                                         //~v1.1I~
#else                                                              //~v1.1I~
    #define INCL_DOSFILEMGR  //DCPY_EXISTING                       //~v130R~
    #include <os2.h>                                               //~v130R~
#endif                                                             //~v10kI~
                                                                   //~6831M~
#include <errno.h>                                                 //~va95I~
//*********************************************************************
#include <ulib.h>                                                  //~6831I~
#include <uerr.h>                                                  //~6831I~
#include <ualloc.h>                                                //~v136I~
#include <udbcschk.h>                                              //~6831I~
#include <ufile.h>                                                 //~6831I~
#include <ufile2.h> 		//usetftime                            //~v10fI~
#include <ufile3.h> 		//uxcopy                               //~v10qI~
#include <ufile4.h> 		//ugetdiskfree                         //~v10bI~
#include <uedit.h>                                                 //~6901I~
#include <uedit2.h>                                                //~v136I~
#include <ufemsg.h>                                                //~va30I~
#ifdef DPMI                 //DPMI version                         //~v177I~
    #include <udos.h>       //uharderr                             //~v177I~
#endif                                                             //~v177I~
#include <udos2.h>          //ugetdrivetype                        //~v10lI~
#include <uproc.h>          //uexecchk                             //~v10qI~
#include <umiscf.h>         //uexecchk                             //~v127I~
#ifdef UNX                                                         //~v140I~
	#include <ugcclib.h>                                           //~v140I~
#endif                                                             //~v140I~
//*********************************************************************//~v10lI~
#define XFS_PRECHK                                                 //~v176R~

#if defined(DOS) && !defined(DPMI)                                 //~v10lI~
	#define BUFFSZ  	((UINT)(32768-512))   //32k                //~v131R~
#else                                                              //~v10lI~
	#define BUFFSZ  	131072	//128k                             //~v10lI~
#endif                                                             //~v10lI~
#define EOLID       0x0a                                           //~v142I~
//#define CRLFCHKSZ   512                                          //~va1BR~
#define CRLFCHKSZ   4096                                           //~va1BI~
#define CRLFBACKSZ  4096                                           //~v10lI~
#define MAXFNT 		100                                            //~6901R~
#define INDEXFID 	"._~!"                                         //~6901R~
#define INDEXRECID 	"\x01\xfe\x02"                                 //~6901R~
#define CHKSUMID   	'\x03'                                         //~v127I~
#define ENDOFSPACEFILENM	"\x04"   //space embeddied file        //~va4aR~
#define CHKSUMIDST 	"start="                                       //~v127I~
#define CHKSUMIDSF 	"subfile="                                     //~v127I~
#define CHKSUMIDOF 	"offset="                                      //~v127I~
#define CHKSUMIDLN 	"len="                                         //~v127I~
#define INDEXRECSZ 	_MAX_PATH+128                                  //~v10jR~
#define INDEXUSE 	'@'                                            //~6901R~
//#define LASTFSIZE   0x7fffffff		//size for size not specified//~va30R~
#define LASTFSIZE   FILESZ_MAX		//size for size not specified  //~va30I~

#define FT_INDEX    0   //file type for open/close to mdos copy    //~v171I~
#define FT_ORG      1   //file type for open/close to mdos copy    //~v171I~
#define FT_SUB      2   //file type for open/close to mdos copy    //~v171I~
//*********************************************************************
static char *Sinpbuff=0;	//with null term                       //~va22R~
static int Ssubfntctr=0;		//outfile name table entry         //~va22R~
static int Ssizetctr=0;		//size tablen entry                    //~va22R~
static int Slinenosw=0;       //size by lineno option              //~va22R~
static int Srecnosw=0;      //size by recordno option              //~va1FI~
//static int Sbinsw;	    	//input file is binary             //~v124R~
//static int Sbintextsw;	    //bin or text is forced by parm    //~v124R~
static int Sbinsw=1;    		//input file is binary             //~v124R~
//static int Swildsw;			//outfile last is wild card        //~v106R~
static int Smsgsw;             	//comment issue at Esc             //~v131I~
static int Srestartdriveno=0;    	//retry driveno                //~va22R~
static int Srestartdrivesw=0;    	//0:no retry,1:retry one drive,2:restart from the drive//~va22R~
//static long Srestartoffset=0,Srestartlen=0;                      //~va30R~
static FILESZT Srestartoffset=0,Srestartlen=0;                     //~va30I~
static ULONG Srestartchksumstart=0,Srestartchksumend=0;            //~va22R~
static int Sremovablesw=0;    //0:fixed,1:removable                //~va22R~
#ifdef XFS_PRECHK                                                  //~v176I~
	static int Sremovabledriveid=0;                                //~v176R~
#endif                                                             //~v176I~
static int Snochksumsw=0;                                          //~va22R~
static int Sverifysw=1;     //1:verify                             //~v123R~
static int Sgathersw=0;		//gather to original file              //~va22R~
static int Sdelysw=0;			//delete no confirm                //~va22R~
static int Sdbcssw;			//dbcs env sw                          //~v1.1R~
static char Spgmnm[_MAX_PATH]; 	//prog copy                        //~v10qR~
static char Ssubfnt[MAXFNT][_MAX_PATH];			//outfile name table//~v10kR~
//static long Ssizet[MAXFNT];			//outfile size table       //~va30R~
static FILESZT_S Ssizet[MAXFNT];			//outfile size table   //~va30I~
//static char Seditfname[_MAX_PATH];		//wild card edit patern//~v105R~
static int  Swildpos[MAXFNT];           //wild card char offset    //~v106R~
static int  Swildlen[MAXFNT];          //wild card filename ctr    //~v106R~
static char Sindexfnm[_MAX_PATH];		//wild card edit patern    //~6831I~
static char Snextsubfnm[_MAX_PATH];                                //~v10lI~
static char *Sindexrecid=INDEXRECID;                               //~6901I~
#ifdef UNX                                                         //~va1jI~
static char *Snullid="/dev/null";                                  //~va1jI~
#else                                                              //~va1jI~
static char *Snullid="NUL";                                        //~6901I~
#endif                                                             //~va1jI~
static char Shdrinf[128];                                          //~v10mI~
static  char Sorgfname[_MAX_PATH];	                               //~v10jR~
static	FILE *Shorgf,*Shsubf,*Shindex=0;                           //~va22R~
static	char Spgmver[16];                                          //~6831I~
static  char Snumeditptn[]="z,zzz,zzz,zz9";                        //~v10hI~
static long Sclustersz;                                            //~v10lI~
//static long Sorgfsz=0;                                           //~va30R~
static FILESZT Sorgfsz=0;                                          //~va30I~
static ULONG Sgatherchksumstart=0,Sgatherchksumsubfile=0;          //~va22R~
//static ULONG Sgatherchksumoffs=0,Sgatherchksumlen;               //~va30R~
static FILESZT Sgatherchksumoffs=0,Sgatherchksumlen;               //~va30I~
static int Smultirecid=0,Smultirecoffsid=0,Smultirecoffs=0,Smultirecstrlen=0;//~va1CR~
static char *Smultirecstr=0;                                       //~va1CR~
#ifdef UNX                                                         //~v171I~
    static char Sunxtempdir[32];                                   //~v171I~
    static char Sunxtempfile[_MAX_PATH][3];//output once to temp   //~v171I~
#endif                                                             //~v171I~
//*********************************
//char *getsubfname(int Pfileno,long *Psize,long Preslen);         //~va30R~
char *getsubfname(int Pfileno,FILESZT_S *Psize,FILESZT_S Preslen); //~va30R~
//FILE *openfile(char *Pfile,char *Popt,int Pmsgsw);               //~v171R~
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw,int Pfiletype);   //~v171I~
void  closefile(FILE *Pfh,char *Pfile,int Pfiletype,FDATE *Ppdate,FTIME *Pptime);//~v171R~
//char *getinput(long Preqsize,int *Poutlen,int *Pbreaksw);        //~va30R~
char *getinput(FILESZT Preqsize,int *Poutlen,FILESZT_S *Pbreaksw); //~va30R~
char confirm(char *Pmsge,char *Pmsgj,char *Preply);                //~6831I~
void putoutput(char *Pfname,FILE* Phfile,char *Paddr,int Plen);    //~6831R~
void parmchk(int,char *[]);
char *getindexrec(char **Pcomm);                                   //~v127R~
//int drivechk(char *Pfullpath,int Pfileno,long *Ppsize);          //~va30R~
int drivechk(char *Pfullpath,int Pfileno,FILESZT_S *Ppsize);       //~va30I~
int drivechksub(char Pdriveletter);                                //~v10kI~
#ifdef UNX                                                         //~v140I~
	long getfreespace(char *Pfnm,long *Pclustersz);                //~v140I~
	char *unxalloctempf(char *Pfile,char *Popt,int Pfiletype);     //~v171I~
	void unxcleartempf(void);                                      //~v171I~
#else                                                              //~v140I~
//long getfreespace(char Pdriveletter,long *Pclustersz);             //~v10kR~//~va48R~
	long getfreespace(char *Pfnm,long *Pclustersz);                //~va48I~
#endif                                                             //~v140I~
//void mountreq(char *Pfullpath,int Pmsgcase,long Preslen,int Pdriveno);//~va30R~
void mountreq(char *Pfullpath,int Pmsgcase,FILESZT Preslen,int Pdriveno);//~va30I~
//int getnextinputdrive(int Popt,char *Porgfname,long Preslen);    //~va30R~
int getnextinputdrive(int Popt,char *Porgfname,FILESZT_S Preslen); //~va30I~
char indexchk(int Premoveble);                                     //~v134R~
void invalidindexrec(int Pexitsw);                                 //~v10lR~
//int readverify(UCHAR *Psubfnm,long Ptotlen);                     //~v127R~
//int readverify(UCHAR *Psubfnm,long Ptotlen,ULONG Poffs,ULONG Pchksum,int Psubfno);//~va30R~
int readverify(UCHAR *Psubfnm,FILESZT Ptotlen,FILESZT Poffs,ULONG Pchksum,int Psubfno);//~va30I~
//SHORT calcpercent(long Plong1,long Plong2);                      //~va30R~
SHORT calcpercent(FILESZT Plong1,FILESZT Plong2);                  //~va30I~
void chksumerr(int Pcase,int Psubfno,ULONG Pchksumi,ULONG Pchksums);//~v127R~
int restartchk1(int Pcurrno);                                      //~v131I~
int restartchk2(int Pfineno,ULONG Pchksumt);                       //~v131I~
//int restartdrvchk(int Pcurrno,long *Ppsize);                     //~va30R~
int restartdrvchk(int Pcurrno,FILESZT *Ppsize);                    //~va30I~
//void restartdrvchksub(int Ppos,int Pdrvno,long *Ppoffset,long *Pplen,//~va30R~
void restartdrvchksub(int Ppos,int Pdrvno,FILESZT *Ppoffset,FILESZT *Pplen,//~va30I~
					ULONG *Ppchksumst,ULONG *Ppchksumsub);         //~v131I~
int kbdchk(char *Pvalid);                                          //~v135R~
int kbdchksub(void);                                               //~v135R~
void pgmcopy(void);                                                //~v10qR~
void help(void);
void listdir(int Pfno,PUDIRLIST Ppudirlist);                       //~v136I~
int chkmultirec(char *Ptol,char *Peol);                            //~va1CR~
char *xffeditfszzx(FILESZT Pfsz,char *Pdecout);                    //~va30R~
char *xffeditfszx(FILESZT Pfsz,char *Pdecout);                     //~va30R~
char *xffeditfszz(FILESZT Pfsz,char *Pdecout);                     //~va30R~
//*********************************************************************
//* return 0:fully equall
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int main(int parmc,char *parmp[])
{
	int fno,len;                                                   //~6831R~
//  long outsize,writelen,readlen;                                 //~va30R~
    FILESZT_S outsize,writelen,readlen;                            //~va30I~
	char *subfname,*pc;                                            //~6831R~
    FILEFINDBUF3 fstat3;                                           //~6831M~
    FILEFINDBUF3 fstat3_1;                                         //~v10hI~
//  char confmsg[256];                                             //+vaq1R~
    char confmsg[_MAX_PATH+256];                                   //+vaq1I~
    char editwk1[12];                                              //~v10hI~
    char editwk2[12];                                              //~v10hI~
//  char editwkn[16];                                              //~va30R~
    char editwkn[32],editwkn2[32],*pcx;                            //~va30I~
    char orgfnm[_MAX_PATH];                                        //~v10lI~
    char fullpath[_MAX_PATH];                                      //~v138I~
//  int breaksw;                                                   //~va30R~
    FILESZT_S breaksw;                                             //~va30I~
//  long inpfsz;                                                   //~va30R~
    FILESZT inpfsz;                                                //~va30I~
//  long reslen;                                                   //~va30R~
    FILESZT_S reslen;                                              //~va30I~
    int eofid;                                                     //~v10lI~
    int rc;                                                        //~v10qI~
    int restid;                                                    //~v131I~
    int nullsw;                                                    //~v10uI~
//  long divider;       //for calc percent                         //~va30R~
    FILESZT_S divider;  //for calc percent                         //~va30I~
    int  pathlen;                                                  //~v138I~
//  int  expandsz;                                                 //~va30R~
    FILESZT_S expandsz;                                            //~va30I~
    SHORT percent,percent2;                                        //~v123R~
//  ULONG chksums,chksumt,subfoffs;                                //~va30R~
    ULONG chksums,chksumt;                                         //~va30I~
    FILESZT subfoffs;                                              //~va30I~
    char *endofspacefilenm;                                        //~va4aI~
//**********************
    subfoffs=0;                                                    //~va58I~
	sprintf(Spgmver,"%s:%s: ",PGM,VER);                            //~6831R~
#ifdef UNX                                                         //~v171R~
    UCBITON(Gufile_opt,GFILEOPT_LNXMTOOL);  //mdos disk support    //~v171R~
#endif                                                             //~v171R~
	uerrmsg_init(Spgmver,stdout,0);//msg to stdout                 //~6831I~
	uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg   //~6831I~
	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit       //~v126I~
#ifdef DPMI                                                        //~v177R~
    uharderr(0);    //fail if drive notready                       //~v177R~
#endif                                                             //~v177R~
    Sdbcssw=udbcschkcp();                                          //~v10jR~
#ifdef LNX                                                         //~va1ZM~
    Sdbcssw=0;      //force english confirm msg                    //~va1ZM~
#endif                                                             //~va1ZM~
	parmchk(parmc,parmp);
    if (!Sdbcssw)                                                  //~v10tI~
		uerrmsg_init(Spgmver,stdout,UERR_FORCE_ENGLISH);           //~v10tR~
    if (Sgathersw)                                                 //~6831I~
//**gather ********************                                    //~6831I~
    {                                                              //~6831I~
        Sbinsw=1;       //read bynaly                              //~v108I~
//      eofid=getnextinputdrive(0,orgfnm,0);	//reslen no meaning//~va30R~
        eofid=getnextinputdrive(0,orgfnm,(FILESZT_S)0);	//reslen no meaning//~va30I~
		if (!*Sorgfname)	//no parm specified                    //~v10jI~
        {                                                          //~v10jI~
            strcpy(Sorgfname,orgfnm);                              //~v10lI~
			uerrmsg("Restore original file %s %s %s",0,            //~v10mR~
            		Sorgfname,Shdrinf,Shdrinf+32);                 //~v10mR~
		}                                                          //~v10jI~
        else                                                       //~v10jI~
        {                                                          //~v10lI~
        	if (!ufullpath(fullpath,Sorgfname,_MAX_PATH))          //~v138I~
	        	uerrexit("ufullpath failed for %s",0,              //~v138I~
							Sorgfname);                            //~v138I~
//  	    if (ROOTDIR(fullpath)                                  //~v171R~
    	    if (ROOTDIR2(fullpath)  //if unix chk mdos also        //~v171I~
    	    ||  ( !ufstat(fullpath,&fstat3)                        //~v138R~
                && (fstat3.attrFile & FILE_DIRECTORY)))            //~v138R~
            {	                                                   //~v138I~
            	pathlen=PATHLEN(orgfnm);                           //~v138I~
                if (pathlen<0)                                     //~v138I~
                	pathlen=0;                                     //~v138I~
//  	        if (!ROOTDIR(fullpath))                            //~v171R~
    	        if (!ROOTDIR2(fullpath))  //chk mdos also if unix  //~v171I~
//              	strcat(fullpath,"\\");                         //~v171R~
                	strcat(fullpath,DIR_SEPS);                     //~v171I~
            	strcat(fullpath,orgfnm+pathlen);                   //~v138I~
            }                                                      //~v138I~
            strcpy(Sorgfname,fullpath);                            //~v138I~
//  		uerrmsg("Restore %s from origial file %s %s %s",0,     //~va30R~
    		uerrmsg("Restore %s from original file %s %s %s",0,    //~va30I~
            		Sorgfname,orgfnm,Shdrinf,Shdrinf+32);          //~v10mR~
		}                                                          //~v10lI~
//confirm replace                                                  //~6831I~
    	if (!ufstat(Sorgfname,&fstat3))                            //~6901R~
        {                                                          //~6901I~
//          unumedit(fstat3.cbFile,Snumeditptn,editwkn);           //~va30R~
			xffeditfszz(fstat3.cbFile,editwkn);                    //~va30R~
            ufdateedit(fstat3.fdateLastWrite,"YY/MM/DD",editwk1);  //~v10mR~
            uftimeedit(fstat3.ftimeLastWrite,"HH:MM:SS",editwk2);  //~v10mR~
        	if (!Sdbcssw)                                          //~v10hR~
        		sprintf(confmsg,"%s is already exist (%s  %s %s),\noverride(Y) or cancel(Esc)?",//~v131R~
						Sorgfname,editwkn,editwk1,editwk2);        //~v10mI~
			else                                                   //~6831I~
        		sprintf(confmsg,"%s (%s  %s %s) は既存です\n上書き(Y)?,取消(Esc)?",//~v131R~
						Sorgfname,editwkn,editwk1,editwk2);        //~v10mI~
//  		confirm(confmsg,confmsg,"YyNn");                       //~v130R~
    		confirm(confmsg,confmsg,"Yy\x1b");                     //~v131R~
        }                                                          //~6901I~
//*                                                                //~6831I~
//  	Shorgf=openfile(Sorgfname,"wb",0,FT_ORG);	//no opened msg//~v171R~//~va49R~
    	Shorgf=openfile(Sorgfname,"wb",-1,FT_ORG);	//-1:returns 0 if open err//~va49I~
        if (!Shorgf)                                               //~va49I~
        {                                                          //~va49I~
        	uerrexit("%s open failed,specify outfile parameter",   //~va49R~
                     "オープン失敗(%s),outfileパラメータで別名を指定してください",//~va49R~
						Sorgfname);                                //~va49I~
        }                                                          //~va49I~
        reslen=Sorgfsz;		//by getnextinputdrive                 //~v10sI~
        chksumt=0;				//org file total chksum            //~v127I~
    	for (fno=0,writelen=0;;)                                   //~6831I~
      	{                                                          //~6831I~
//  		subfname=getsubfname(fno,&outsize,-1);	//get out file name and size//~va30R~
    		subfname=getsubfname(fno,&outsize,(FILESZT_S)(-1));	//get out file name and size//~va30I~
            if (!subfname)                                         //~6831I~
            	break;                                             //~6831I~
    		Shsubf=openfile(subfname,"rb",1,FT_SUB);               //~v171R~
//chk time stamp is all same                                       //~v10hI~
            ufstat(subfname,&fstat3);   //get time stamp           //~v10hR~
//          unumedit(fstat3.cbFile,Snumeditptn,editwkn);           //~va30R~
			pcx=xffeditfszzx(fstat3.cbFile,editwkn);               //~va30R~
//      	printf("--- %s (x%08lX),%s,%s.\n",                     //~va30R~
//  				editwkn,fstat3.cbFile,                         //~va30R~
        	printf("--- %s (x%s),%s,%s.\n",                        //~va30I~
    				editwkn,pcx,                                   //~va30I~
					ufdateedit(fstat3.fdateLastWrite,"YY/MM/DD",editwk1),//~v10hI~
					uftimeedit(fstat3.ftimeLastWrite,"HH:MM:SS",editwk2));//~v10hR~
//  		divider=(long)fstat3.cbFile;	//subfile size         //~va30R~
    		divider=fstat3.cbFile;	//subfile size                 //~va30I~
            if (!fno)		//first file                           //~v10hI~
            	fstat3_1=fstat3;	//save first file              //~v10hI~
#ifndef AIX                                                        //~va22I~
            else                                                   //~v10hI~
            	if (memcmp(&fstat3.fdateLastWrite,&fstat3_1.fdateLastWrite,sizeof(fstat3.fdateLastWrite))//~v10hR~
            	||  memcmp(&fstat3.ftimeLastWrite,&fstat3_1.ftimeLastWrite,sizeof(fstat3.ftimeLastWrite)))//~v10hR~
		        {                                                  //~v10hI~
//#ifndef AIX                                                        //~v175I~   a//~va22R~
        			if (!Sdbcssw)                                  //~v10hR~
        				sprintf(confmsg,"No %d subfile timestamp is not same as first one,\n\
execution continue(Y) or cancel(Esc)?",fno+1);                     //~v131R~
					else                                           //~v10hI~
        				sprintf(confmsg,"No %d サブファイルのタイムスタンプが最初のと異なっています、\n\
続行(Y)?,取消(Esc)?",fno+1);                                       //~v131R~
//  				confirm(confmsg,confmsg,"YyNn");               //~v130R~
		    		confirm(confmsg,confmsg,"Yy\x1b");             //~v131R~
//#endif                                                             //~v175I~  a//~va22R~
		        }                                                  //~v10hI~
#endif                                                             //~va22I~
            fno++;                                                 //~6831I~
            if (!Snochksumsw)                                      //~v127M~
            {                                                      //~v127M~
//printf("start chksum=%08lx,%08lx\n",Sgatherchksumstart,chksumt); //~v129R~
				if (Sgatherchksumstart!=chksumt)                   //~v127M~
                {                                                  //~v127M~
	            	chksumerr(1,fno,Sgatherchksumstart,chksumt);   //~v127I~
                    chksumt=Sgatherchksumstart; //strat from specified by index//~v127M~
                }                                                  //~v127M~
                subfoffs=Sgatherchksumoffs;                        //~v127I~
            }                                                      //~v127M~
	        chksums=0;				//sub file total chksum        //~v127I~
        	for (readlen=0;;)                                      //~v10gR~
          	{                                                      //~6831I~
//  			pc=getinput(BUFFSZ,&len,&breaksw);                 //~va30R~
    			pc=getinput((FILESZT)BUFFSZ,&len,&breaksw);        //~va30I~
                if (!len)		//eof                              //~v10fR~
                	break;                                         //~6831I~
                chksums=uchksum(pc,(ULONG)(subfoffs+readlen),(ULONG)len,chksums);//~v127R~
    			putoutput(subfname,Shorgf,pc,len);	//put 1 byte   //~6831I~
                readlen+=len;                                      //~v10gR~
                percent=calcpercent(readlen,divider);              //~v122I~
                percent2=calcpercent(writelen+readlen,Sorgfsz);    //~v123I~
//              unumedit((ULONG)readlen,Snumeditptn,editwkn);      //~va30R~
//      		printf("\r... %s (x%08lX) byte ( %02d %% ) read. ( %02d %% of total )",//~va30R~
//  					editwkn,readlen,percent,percent2);         //~va30R~
				pcx=xffeditfszzx(readlen,editwkn);                 //~va30I~
        		printf("\r... %s (x%s) byte ( %02d %% ) read. ( %02d %% of total )",//~va30I~
    					editwkn,pcx,percent,percent2);             //~va30I~
                fflush(stdout);                                    //~v122I~
    		}//until subfile eof                                   //~6831I~
//printf("close inprec eofid=%d\n",eofid);                         //~v10mR~
    		fclose(Shsubf);                                        //~v171R~
            writelen+=readlen;                                     //~v10gI~
            reslen-=readlen;                                       //~v10sI~
            percent2=calcpercent(writelen,Sorgfsz);                //~v123I~
//      	printf("\r    %s (x%08lX) byte ( %02d %% ) read. ( %02d %% of total )",//~va30R~
//  				editwkn,readlen,100,percent2);                 //~va30R~
			pcx=xffeditfszzx(readlen,editwkn);                     //~va30I~
        	printf("\r    %s (x%s) byte ( %02d %% ) read. ( %02d %% of total )",//~va30I~
    				editwkn,pcx,100,percent2);                     //~va30I~
//          unumedit((ULONG)writelen,Snumeditptn,editwkn);         //~va30R~
			pcx=xffeditfszzx(writelen,editwkn);                    //~va30I~
            percent=calcpercent(writelen,Sorgfsz);                 //~v122I~
//      	printf("\r    %s (x%08lX) byte written.( %02d %% of total )           \n",//~va30R~
//  				editwkn,writelen,percent);                     //~va30R~
        	printf("\r    %s (x%s) byte written.( %02d %% of total )           \n",//~va30I~
    				editwkn,pcx,percent);                          //~va30I~
            if (!Snochksumsw)                                      //~v127I~
            {                                                      //~v127I~
//printf("subf chksum=%08lx,%08lx\n",Sgatherchksumsubfile,chksums);//~v129R~
				if (Sgatherchksumsubfile!=chksums)                 //~v127R~
    	        	chksumerr(2,fno,Sgatherchksumsubfile,chksums); //~v127R~
            }                                                      //~v127I~
            chksumt=uaddc(chksumt,chksums);	//add with carry       //~v127I~
            if (Sremovablesw)                                      //~v10lI~
            {                                                      //~v10lI~
            	if (eofid)  	//last drive                       //~v10lI~
                	break;	                                       //~v10lI~
                eofid=getnextinputdrive(1,0,reslen);               //~v10sR~
//printf("nct inprec eofid=%d\n",eofid);                           //~v10mR~
			}                                                      //~v10lI~
//          if (!len)		//eof                                  //~v120R~
//          	break;                                             //~v120R~
    	}//until index file eof                                    //~6831I~
//  	fclose(Shorgf);                                            //~v171R~
    	closefile(Shorgf,Sorgfname,FT_ORG,&fstat3_1.fdateLastWrite,&fstat3_1.ftimeLastWrite);//~v171R~
//      if (usetftime(Sorgfname,fstat3_1.fdateLastWrite,fstat3_1.ftimeLastWrite))//~v171R~
//      	uerrexit("usetftime failed",0);                        //~v171R~
        if (writelen!=Sorgfsz)                                     //~v10lM~
        {                                                          //~va30I~
//      	uerrmsg("file size unmatch orginal=%08lX,output=%08lX\n",0,//~va30R~
//  					Sorgfsz,writelen);                         //~va30R~
			xffeditfszx(Sorgfsz,editwkn);                          //~va30I~
			xffeditfszx(writelen,editwkn2);                        //~va30I~
        	uerrmsg("file size unmatch orginal=%s,output=%s\n",0,  //~va30I~
						editwkn,editwkn2);                         //~va30I~
        }                                                          //~va30I~
//      unumedit((ULONG)writelen,Snumeditptn,editwkn);             //~va30R~
		pcx=xffeditfszzx(writelen,editwkn);                        //~va30I~
//  	uerrmsg("===(%c)=== %s %s (x%08lX) byte was restored from %d file.",0,//~va30R~
//      		OSTYPE,                                            //~va30R~
//  			Sorgfname,editwkn,writelen,fno);                   //~va30R~
    	uerrmsg("===(%c)=== %s %s (x%s) byte was restored from %d file.",0,//~va30I~
        		OSTYPE,                                            //~va30I~
    			Sorgfname,editwkn,pcx,fno);                        //~va30I~
    }                                                              //~6831I~
	else                                                           //~6831I~
//**split ********************                                     //~6831I~
    {                                                              //~6831I~
//***                                                              //~6901I~
    	if (rc=(int)ufstat(Sorgfname,&fstat3),rc)                  //~v1.1R~
        {                                                          //~v10qI~
            ufilenotfound(Sorgfname,rc);                           //~v10qR~
			exit(8);                                               //~v10qR~
        }                                                          //~v10qI~
    	Shorgf=openfile(Sorgfname,"rb",0,FT_ORG);                  //~v171R~
//      inpfsz=(long)fstat3.cbFile;                                //~va30R~
        inpfsz=fstat3.cbFile;                                      //~va30I~
        if (!inpfsz)                                               //~v173I~
			uerrexit("input file(%s) size=0.",0,                   //~v173I~
					Sorgfname);                                    //~v173I~
//      unumedit((ULONG)inpfsz,Snumeditptn,editwkn);               //~va30R~
		pcx=xffeditfszzx(inpfsz,editwkn);                          //~va30I~
//  	uerrmsg("%s opened,size=%s (x%08lX).",0,                   //~va30R~
//  			Sorgfname,editwkn,inpfsz);                         //~va30R~
		uerrmsg("%s opened,size=%s (x%s).",0,                      //~va30I~
				Sorgfname,editwkn,pcx);                            //~va30I~
        reslen=inpfsz;                                             //~v10bI~
        chksumt=0;				//org file total chksum            //~v127I~
    	for (fno=1,readlen=0;;fno++)                               //~6901R~
      	{                                                          //~6831R~
        	expandsz=0;                                            //~va1CI~
    		subfname=getsubfname(fno,&outsize,reslen);	//get out file name and size//~v10bR~
			if (!(restid=restartchk1(fno)))	//fno<restno-1         //~v131R~
            	continue;                                          //~v131I~
            nullsw=!stricmp(subfname,Snullid);                     //~v10uI~
		    if (*Spgmnm)    //copy requested                       //~v10qI~
    		{                                                      //~v10qI~
        		pgmcopy();                                         //~v10qR~
        		*Spgmnm=0;           //processed                   //~v10qR~
		    }                                                      //~v10qI~
    		Shsubf=0;		//not opened id                        //~v10bR~
            divider=outsize;                                       //~v122I~
	        chksums=0;				//sub file total chksum        //~v127I~
//          subfoffs=(ULONG)readlen;		//offset at subfile start//~va30R~
            subfoffs=readlen;		//offset at subfile start      //~va30I~
//*                                                                //~6901I~
//      	for (writelen=0;outsize>0;)	                           //~v108R~
        	for (writelen=0;;)                                     //~v108I~
          	{                                                      //~6831R~
    			pc=getinput(outsize,&len,&breaksw);                //~v108R~
//printf("split len=%ld/outsize=%d,breaksw=%ld\n",len,outsize,breaksw);//~v141R~
//              if (!len)		//eof                              //~v108R~
                if (!pc)                                           //~v108I~
                	break;                                         //~6831R~
              if (restid!=1)	//not just before                  //~v132I~
              {                                                    //~v132I~
//*write index file                                                //~v10kM~
                if (!Shsubf)    	                               //~v10bI~
                {                                                  //~v10bI~
		    		Shsubf=openfile(subfname,"wb",1,FT_SUB);       //~v171R~
                    printf("\n");//after opened msg                //~v122R~
            	}//not opened                                      //~v10bI~
              if (!nullsw)                                         //~v132R~
    			putoutput(subfname,Shsubf,pc,len);	//put 1 byte   //~6831R~
              }//not just before                                   //~v132I~
                chksums=uchksum(pc,(ULONG)(subfoffs+writelen),(ULONG)len,chksums);//~v127R~
              if (Slinenosw)    //split by lineno                  //~v141I~
              {                                                    //~v141I~
              	if (breaksw<0)	//breaked before outsize reached by multiline seperater//~va1EI~
                	breaksw=0;                                     //~va1EI~
                outsize=breaksw;  //residual line count            //~v141I~
                breaksw=(breaksw==0); //no residual line count     //~v141R~
              }                                                    //~v141I~
              else                                                 //~v141I~
                outsize-=len;                                      //~6831R~
                writelen+=len;                                     //~6831R~
//printf("writelen=%08lx\n",writelen);                             //~v10mR~
              if (Smultirecid) // //multiline string not found     //~va1CR~
              	if (!breaksw && !outsize)	//no seperater line found//~va1CR~
                {                                                  //~va1CR~
                	outsize=CRLFBACKSZ; //search sprit string more over size parm//~va1CR~
                    expandsz=divider;	//size parm                //~va1CI~
                    divider+=CRLFBACKSZ;                           //~va1CR~
                }                                                  //~va1CR~
              if (Slinenosw)    //split by lineno                  //~v141I~
                percent=calcpercent(divider-outsize,divider);//by line count//~v141I~
              else                                                 //~v141I~
                percent=calcpercent(writelen,divider);             //~v122M~
                percent2=calcpercent(readlen+writelen,inpfsz);     //~v123I~
//	            unumedit((ULONG)writelen ,Snumeditptn,editwkn);    //~va30R~
				pcx=xffeditfszzx(writelen,editwkn);                //~va30R~
              if (restid==1)	//just before                      //~v132R~
//      		printf("\r... Read skip %s (x%08lX) byte ( %02d %% ). ( %02d %% of total )",//~va30R~
//  					editwkn,writelen,percent,percent2);        //~va30R~
        		printf("\r... Read skip %s (x%s) byte ( %02d %% ). ( %02d %% of total )",//~va30I~
    					editwkn,pcx,percent,percent2);             //~va30I~
              else                                                 //~v132I~
//      		printf("\r... %s (x%08lX) byte ( %02d %% ) written. ( %02d %% of total )",//~va30R~
//  					editwkn,writelen,percent,percent2);        //~va30R~
        		printf("\r... %s (x%s) byte ( %02d %% ) written. ( %02d %% of total )",//~va30I~
    					editwkn,pcx,percent,percent2);             //~va30I~
                fflush(stdout);                                    //~v122M~
                                                                   //~v122I~
                if (Sbinsw)     //binaly                           //~v108I~
                {                                                  //~v108I~
                    if (outsize<=0)                                //~v108I~
                        break;                                     //~v108I~
                }                                                  //~v108I~
                else                                               //~v108I~
                    if (breaksw)                                   //~v108I~
                        break;                                     //~v108I~
    		}//until outfile size                                  //~6831R~
			readlen+=writelen;                                     //~6901I~
            reslen=inpfsz-readlen;                                 //~v10bI~
            percent2=calcpercent(readlen,inpfsz);                  //~v123I~
			pcx=xffeditfszzx(writelen,editwkn);                    //~va30I~
          if (restid==1)	//just before                          //~v133I~
//      	printf("\r    Read skip %s (x%08lX) byte ( %02d %% ). ( %02d %% of total )\n",//~va30R~
//  					editwkn,writelen,100,percent2);            //~va30R~
        	printf("\r    Read skip %s (x%s) byte ( %02d %% ). ( %02d %% of total )\n",//~va30I~
    					editwkn,pcx,100,percent2);                 //~va30I~
          else                                                     //~v133I~
//      	printf("\r    %s (x%08lX) byte ( %02d %% ) written. ( %02d %% of total )",//~va30R~
//  					editwkn,writelen,100,percent2);            //~va30R~
        	printf("\r    %s (x%s) byte ( %02d %% ) written. ( %02d %% of total )",//~va30I~
						editwkn,pcx,100,percent2);                 //~va30I~
          if (Shsubf)                                              //~v10bR~
          {                                                        //~v10bI~
//  		fclose(Shsubf);                                        //~v171R~
//      	uerrmsg("... %ld (x%08lX) byte written.",0,            //~v10bR~
//      			writelen,writelen);                            //~v10bR~
//          unumedit((ULONG)readlen ,Snumeditptn,editwkn);         //~va30R~
			pcx=xffeditfszzx(readlen,editwkn);                     //~va30I~
            percent=calcpercent(readlen,inpfsz);                   //~v122I~
           if (nullsw)                                             //~v10uI~
           {                                                       //~v171I~
//      	printf("...%s (x%08lX) byte ignored.\n",editwkn,writelen);//~v122R~
//      	printf("\r    %s (x%08lX) byte written to NUL !!!                         ",//~va30R~
//  				editwkn,writelen);                             //~va30R~
			xffeditfszx(writelen,editwkn2);                        //~va30I~
        	printf("\r    %s (x%s) byte written to NUL !!!                         ",//~va30I~
					editwkn,editwkn2);                             //~va30I~
    		closefile(Shsubf,subfname,FT_SUB,0,0);                 //~v171R~
           }                                                       //~v171I~
           else                                                    //~v10uI~
           {                                                       //~v10uI~
//      	printf("...%s (x%08lX) byte written.\n",editwkn,writelen);//~v122R~
//      	printf("\r    %s (x%08lX) byte written.( %02d %% of total )               \n",//~va30R~
//  				editwkn,readlen,percent);                      //~va30R~
        	printf("\r    %s (x%s) byte written.( %02d %% of total )               \n",//~va30I~
    				editwkn,pcx,percent);                          //~va30I~
    		closefile(Shsubf,subfname,FT_SUB,&fstat3.fdateLastWrite,&fstat3.ftimeLastWrite);//~v171R~
//          if (usetftime(subfname,fstat3.fdateLastWrite,fstat3.ftimeLastWrite))//~v171R~
//          	uerrexit("usetftime failed",0);                    //~v171R~
           }                                                       //~v10uI~
		  }                                                        //~v10bI~
//        else                                                     //~v10uR~
         if (restid!=1)	//not just before                          //~v132I~
         {                                                         //~v132I~
            if (!Shindex)//first time or each for removable        //~v10kI~
            {                                                      //~v10kI~
                Shindex=openfile(Sindexfnm,"w",0,FT_INDEX);        //~v171R~
//              unumedit((ULONG)inpfsz,Snumeditptn,editwkn);       //~va30R~
				pcx=xffeditfszzx(inpfsz,editwkn);                  //~va30I~
//              fprintf(Shindex,"%s%s %s (x%08lx) %04d(%c) %s,%s_split_at_%s\n",//~va30R~
//              fprintf(Shindex,"%s%s %s (x%s) %04d(%c) %s,%s_split_at_%s\n",//~va30I~//~va4aR~
				if (strchr(Sorgfname,' '))                         //~va4aI~
                	endofspacefilenm=ENDOFSPACEFILENM;             //~va4aI~
                else                                               //~va4aI~
                	endofspacefilenm="";                           //~va4aI~
                fprintf(Shindex,"%s%s%s %s (x%s) %04d(%c) %s,%s_split_at_%s\n",//~va4aI~
                                Sindexrecid,Sorgfname,             //~v10kI~
                                endofspacefilenm,                  //~va4aI~
//                              editwkn,inpfsz,                    //~va30R~
                                editwkn,pcx,                       //~va30I~
                                fno,(pc==0)+'0',                   //~v10lR~
                ufdateedit(fstat3.fdateLastWrite,"YY/MM/DD",editwk1),//~v10kI~
                uftimeedit(fstat3.ftimeLastWrite,"HH:MM:SS",editwk2),//~v10kI~
                (char*)utimeedit("YY/MM/DD,HH:MM:SS",0));          //~v1.1R~
              }                                                    //~v132I~
//  		fprintf(Shindex,"%s%s\n",Sindexrecid,subfname);        //~v127R~
//  		fprintf(Shindex,"%s%s %c chksum %s%08lx %s%08lx,%s%08lx,%s%08lx\n",//~va30R~
//  				Sindexrecid,subfname,CHKSUMID,CHKSUMIDST,chksumt,//~va30R~
//  				CHKSUMIDSF,chksums,                            //~va30R~
//  				CHKSUMIDOF,subfoffs,                           //~va30R~
//  				CHKSUMIDLN,writelen);                          //~va30R~
			xffeditfszx(subfoffs,editwkn);                         //~va30I~
			pcx=xffeditfszx(writelen,0);                           //~va30I~
//  		fprintf(Shindex,"%s%s %c chksum %s%08lx %s%08lx,%s%s,%s%s\n",//~va30I~//~va4aR~
            if (strchr(subfname,' '))                              //~va4aI~
                endofspacefilenm=ENDOFSPACEFILENM;                 //~va4aI~
            else                                                   //~va4aI~
                endofspacefilenm="";                               //~va4aI~
    		fprintf(Shindex,"%s%s%s %c chksum %s%08lx %s%08lx,%s%s,%s%s\n",//~va4aI~
//  				Sindexrecid,subfname,CHKSUMID,CHKSUMIDST,chksumt,//~va30I~//~va4aR~
    				Sindexrecid,subfname,                          //~va4aI~
                    endofspacefilenm,                              //~va4aI~
    				CHKSUMID,CHKSUMIDST,chksumt,                   //~va4aI~
					CHKSUMIDSF,chksums,                            //~va30I~
					CHKSUMIDOF,editwkn,                            //~va30I~
					CHKSUMIDLN,pcx);                               //~va30I~
          if (Sremovablesw)                                        //~v10kI~
          {                                                        //~v10kI~
//  		fclose(Shindex);                                       //~v171R~
    		closefile(Shindex,Sindexfnm,FT_INDEX,0,0);             //~v171R~
			Shindex=0;                                             //~v10kI~
          }                                                        //~v10kI~
          else                                                     //~v143I~
			fflush(Shindex);    //force write id of ctl file       //~v143I~
//          if (!len)		//eof                                  //~v109R~
//  		readverify(subfname,writelen);                         //~v127R~
    		readverify(subfname,writelen,subfoffs,chksums,fno);    //~v127R~
         }//not just before                                        //~v132I~
			chksumt=uaddc(chksumt,chksums);		//total chksum     //~v132M~
			restid=restartchk2(fno,chksumt);                       //~v132M~
            if (restid) 	//one drive retry end                  //~v131I~
            	break;                                             //~v131I~
            if (!pc)		//eof                                  //~v108I~
            	break;                                             //~6831R~
            if (reslen<=0)	//input exausted                       //~v139I~
            	break;                                             //~v139I~
            if (expandsz)                                          //~va1CM~
//    	        printf("Output size of No.%d file expanded %ld bytes by multi-line separator search.\n",//~va30R~
      	        printf("Output size of No.%d file expanded %" FILESZ_EDIT "d bytes by multi-line separator search.\n",//~va30I~
							fno,writelen-expandsz);                //~va1CM~
    	}//until eof                                               //~6831R~
  		fclose(Shorgf);                                            //~v171R~
      if (Srestartdrivesw==1)			//one drive retry          //~v131I~
      {                                                            //~v131I~
	    uerrmsg("Split status is written to %s",0,                 //~v131I~
            		Sindexfnm);                                    //~v131I~
//      unumedit((ULONG)Srestartlen,Snumeditptn,editwkn);          //~va30R~
//  	uerrmsg("===(%c)=== %s offset=%08lX len=%s (x%08lX) is written to No %d disk.",0,//~va30R~
//      		OSTYPE,                                            //~va30R~
//  			Sorgfname,Srestartoffset,editwkn,Srestartlen,Srestartdriveno);//~va30R~
		xffeditfszx(Srestartoffset,editwkn2);                      //~va30I~
		pcx=xffeditfszzx(Srestartlen,editwkn);                     //~va30I~
    	uerrmsg("===(%c)=== %s offset=%s len=%s (x%s) is written to No %d disk.",0,//~va30I~
        		OSTYPE,                                            //~va30I~
    			Sorgfname,editwkn2,editwkn,pcx,Srestartdriveno);   //~va30I~
      }                                                            //~v131I~
      else                                                         //~v131I~
      {                                                            //~v131I~
	    uerrmsg("Split status is written to %s",0,                 //~v10vI~
            		Sindexfnm);                                    //~v10vI~
//      unumedit((ULONG)readlen,Snumeditptn,editwkn);              //~va30R~
//  	uerrmsg("===(%c)=== %s %s (x%08lX) byte was cut into %d file.",0,//~va30R~
//      		OSTYPE,                                            //~va30R~
//  			Sorgfname,editwkn,readlen,fno);                    //~va30R~
		pcx=xffeditfszzx(readlen,editwkn);                         //~va30I~
    	uerrmsg("===(%c)=== %s %s (x%s) byte was cut into %d file.",0,//~va30I~
        		OSTYPE,                                            //~va30I~
    			Sorgfname,editwkn,pcx,fno);                        //~va30I~
      }                                                            //~v131I~
    }//split                                                       //~6831I~
  if (Shindex)                                                     //~v10kI~
    fclose(Shindex);                                               //~v171R~
//  fclose(Shorgf);                                                //~v10hR~
//  fclose(Shsubf);                                                //~v109R~
#ifdef UNX                                                         //~v171I~
	unxcleartempf();                                               //~v171I~
#endif                                                             //~v171R~
	ubell();                                                       //~v126I~
	uerrmsg("Process completed",                                   //~v126I~
			"処理完了");                                           //~v126I~
	return 0;                                                      //~6831I~
}   //end maine
//**********************************************************************//~va49I~
//* gather:subfile directory chk(search same dir as index file)    //~va49I~
//*parm1:file name seq no                                          //~va49I~
//*parm2:input subfilename by getindexrec                          //~va49I~
//**********************************************************************//~va49I~
char *gathersubfilechk(int Pfileno,char *Psubfnm)                  //~va49I~
{                                                                  //~va49I~
static char Ssubfnm[_MAX_PATH];                                    //~va49I~
    FILEFINDBUF3 fstat3;                                           //~va49I~
    int pathlen,fnmpos;                                            //~va49I~
//****************                                                 //~va49I~
    if (!Psubfnm)	//subfile exausted                             //~va49I~
        return 0;                                                  //~va49I~
    if (!ufstat(Psubfnm,&fstat3))	//subfile exist                //~va49I~
    	return Psubfnm;                                            //~va49I~
    pathlen=PATHLEN(Sindexfnm);                                    //~va49I~
    fnmpos=PATHLEN(Psubfnm)+1;                                     //~va49R~
	memcpy(Ssubfnm,Sindexfnm,(UINT)pathlen);                       //~va49I~
	strcpy(Ssubfnm+pathlen,Psubfnm+fnmpos);                        //~va49I~
    if (ufstat(Ssubfnm,&fstat3))	//subfile not exist            //~va49I~
    {                                                              //~va49I~
        uerrmsg("File not found; %s and also %s\n",                //~va49R~
                "サブファイルがありません(%s も %s も)",           //~va49I~
        		Psubfnm,Ssubfnm);                                  //~va49I~
    	return Psubfnm;                                            //~va49I~
    }                                                              //~va49I~
    return Ssubfnm;                                                //~va49I~
}//gathersubfilechk                                                //~va49I~
//**********************************************************************//~6831I~
//* get output file name                                           //~6831I~
//*parm1:file name seq no                                          //~v10bI~
//*parm2:output,amx write size specified                           //~v10bI~
//*parm3:residual input size to chk output space                   //~v10bI~
//**********************************************************************//~6831I~
//char *getsubfname(int Pfileno,long *Psize,long Preslen)          //~va30R~
char *getsubfname(int Pfileno,FILESZT_S *Psize,FILESZT_S Preslen)  //~va30R~
{                                                                  //~6831I~
static char Sfnamewk[_MAX_PATH];		//wild card edit patern    //~v10jR~
static int Scurfno=0;     //index in fntbl                         //~va22R~
static int Scursubfno=0;  //subfileno                              //~va22R~
static int Swildused=0;                                            //~v111I~
static int Sdriveno=0;                                             //~va22R~
    int ii,jj;                                                     //~v131I~
	char *fnm;                                                     //~6831I~
    int wildpos,wildlen;                                           //~v106R~
//  long reqsz;                                                    //~va30R~
    FILESZT_S reqsz;                                               //~va30I~
    int restid;                                                    //~v131R~
//****************                                                 //~6831I~
	if (Sgathersw)                                                 //~6831I~
    {                                                              //~v10lI~
        if (!Pfileno)                                              //~v10lR~
        {                                                          //~v10lI~
  		  	fnm=getindexrec(0);                                    //~v10lR~
            Sremovablesw=drivechksub(*fnm);                        //~v10lI~
		}                                                          //~v10lI~
        else                                                       //~v10lI~
        	if (Sremovablesw)                                      //~v10lI~
            	fnm=Snextsubfnm;                                   //~v10lI~
            else                                                   //~v10lI~
	  		  	fnm=getindexrec(0);                                //~v10lI~
        if (!Sremovablesw)                                         //~va49I~
            fnm=gathersubfilechk(Pfileno,fnm);                     //~va49I~
//printf("getsubfname %s\n",fnm);                                  //~v10mR~
//printf("removablesw=%d\n",Sremovablesw);                         //~v10mR~
	}                                                              //~v10lI~
    else                                                           //~6831I~
    {                                                              //~6831I~
//  	if (Pfileno<=Ssizetctr)                                    //~v106R~
    	if (Scurfno<Ssizetctr)                                     //~v106I~
//      	*Psize=Ssizet[Pfileno-1];                              //~v106R~
        	*Psize=Ssizet[Scurfno];                                //~v106I~
    	else                                                       //~6831R~
//          if (Swildsw)                                           //~v106R~
//  	    	*Psize=Ssizet[Ssizetctr-1];	//use last             //~v106R~
//          else                                                   //~v106R~
    	    	*Psize=LASTFSIZE;          //max                   //~v10kR~
//  	if (Pfileno<=Ssubfntctr)                                   //~v106R~
    	if (Scurfno>=Ssubfntctr)                                   //~v106I~
        {                                                          //~va1jI~
          if (Ssubfntctr==1 && !Swildused) //no wildcard and 1 filename//~v111R~
			uerrexit("Output filename exausted,\n\
Use wild card or '+' filename concatination",                      //~v111I~
                     "出力ファイル名の指定が足りません,\n\
ワイルドカード指定するか　'+' でファイル名連結指定して下さい");    //~v111R~
          else                                                     //~v111I~
			uerrexit("File name exausted,input truncated",         //~v111R~
                     "出力ファイル名の指定が足りません");          //~v111I~
        }                                                          //~va1jI~
//      	fnm=Ssubfnt[Pfileno-1];                                //~v106R~
        fnm=Ssubfnt[Scurfno];                                      //~v106I~
        wildpos=Swildpos[Scurfno];                                 //~v106R~
        wildlen=Swildlen[Scurfno];                                 //~v106I~
        if (wildpos)        //wildcard                             //~v106I~
        {                                                          //~v106I~
            Swildused=1;        //for errmsg                       //~v111I~
            Scursubfno++;                                          //~v106I~
            memcpy(Sfnamewk,fnm,(UINT)wildpos);                    //~v106I~
            sprintf(Sfnamewk+wildpos,"%0*d%s",wildlen,Scursubfno,  //~v106R~
                            fnm+wildpos+wildlen);                  //~v106I~
            fnm=Sfnamewk;                                          //~v106I~
//chk next overflow                                                //~v106I~
            for (ii=1,jj=Scursubfno+1;;ii++)                       //~v106I~
                if (!(jj/=10))      //power of 10                  //~v106I~
                    break;                                         //~v106R~
            if (ii>wildlen)     //need more file                   //~v106I~
            {                                                      //~v106I~
                Scurfno++;      //next bfile                       //~v106I~
                Scursubfno=0;       //reset subfileno              //~v106I~
            }                                                      //~v106I~
        }//wildcard                                                //~v106I~
        else        //not wild card                                //~v10kR~
        {                                                          //~v106I~
            Scurfno++;      //next bfile                           //~v106I~
            Scursubfno=0;       //reset subfileno                  //~v106I~
        }                                                          //~v106I~
//          if (Swildsw)                                           //~v106R~
//          	sprintf((fnm=Sfnamewk),Seditfname,Pfileno-Ssubfntctr);//~v105R~
//          else                                                   //~v106R~
//  	    	fnm=Snullid;                                       //~v106R~
        if (stricmp(fnm ,Snullid))                                 //~v10kR~
        {                                                          //~v10kI~
            if (Pfileno!=1)                                        //~v10kI~
//          {                                                      //~v131R~
            	Sdriveno++;                                        //~v123R~
//              mountreq(fnm,1,Preslen,Sdriveno);                  //~v131R~
//  		}                                                      //~v131R~
            else                                                   //~v123I~
            	Sdriveno=1;                                        //~v123I~
                                                                   //~v131R~
          if (restid=restartdrvchk(Sdriveno,Psize),restid)//not retry drive//~v131R~
          {                                                        //~v131I~
            if (Pfileno!=1                                         //~v131R~
            ||  restid==2)	//disk No.1 retry                      //~v131R~
            {                                                      //~va1jI~
            	if (Srestartdrivesw==1)                            //~v131I~
		            mountreq(fnm,6,*Psize,Sdriveno); //also no-1 drive//~v131I~
                else                                               //~v131I~
			    	mountreq(fnm,1,Preslen,Sdriveno); //also no-1 drive//~v131R~
            }                                                      //~va1jI~
            for (;;)                                               //~v10kI~
            {                                                      //~v10kI~
                reqsz=*Psize;                                      //~v10rR~
            	drivechk(fnm,Pfileno,&reqsz);                      //~v132R~
//printf("after drivechk size=%d\n",*Psize);                       //~v10mR~
            	if (reqsz>0)                                       //~v10rR~
                	break;                                         //~v10kI~
                mountreq(fnm,2,Preslen,Sdriveno);    //req change drive//~v123R~
			}                                                      //~v10kI~
            *Psize=reqsz;                                          //~v10rR~
//          if (Pfileno==1)                                        //~v134R~
//          	indexchk();                                        //~v134R~
          }//not just before of restart                            //~v131R~
        }                                                          //~v10kI~
	}//split           	                                           //~6831I~
    return fnm;                                                    //~6831R~
}//getsubfname                                                     //~6831R~
//**********************************************************************//~v131I~
//* restart drive skip chk at start of subfile                     //~v131I~
//*parm1:current driveno                                           //~v131I~
//*ret :0:bypass skip;1:just before drive;2:=restart driveno;3:normal//~v131R~
//**********************************************************************//~v131I~
int restartchk1(int Pcurrno)                                       //~v131R~
{                                                                  //~v131I~
//******************                                               //~v131I~
	if (!Srestartdrivesw)                                          //~v131I~
    	return 3;                        //no restart              //~v131I~
   	if (Pcurrno<Srestartdriveno-1)                                 //~v131R~
    	return 0;						//skip read/write          //~v131I~
    if (Pcurrno==Srestartdriveno-1)    //just before               //~v131R~
    	return 1;						//skip write               //~v131I~
    if (Pcurrno==Srestartdriveno)      //restart drive             //~v131I~
    	if (Srestartdrivesw==1)			//need chk just subfile size//~v132I~
	    	return 2;						//write                //~v132R~
    return 3;						   //after restart drive       //~v131R~
}//restartchk1                                                     //~v131I~
//**********************************************************************//~v131I~
//* restart drive skip chk                                         //~v131I~
//*   set start offset of resart subfile when driveno=restart No-1 //~v131I~
//*parm1:current driveno                                           //~v131I~
//*parm2:total chksum of input after subfile read                  //~v131R~
//*ret :0:continue process;1:one drive retry ended                 //~v131R~
//**********************************************************************//~v131I~
int restartchk2(int Pcurrno,ULONG Pchksumt)                        //~v131R~
{                                                                  //~v131I~
//******************                                               //~v131I~
    if (!Srestartdrivesw)                                          //~v131I~
    	return 0;                                                  //~v131I~
//drive just before                                                //~v131I~
    if (Pcurrno==Srestartdriveno-1)   //just before                //~v131R~
    {                                                              //~v131I~
    	if (Pchksumt!=Srestartchksumstart)                         //~v131R~
//            uerrexit("\nchksum err;input upto offset=%08lx(chksum=%08lx)\n//~va30R~
//and on index file of No %d disk(chksum=%08lx)",0,                //~va30R~
//                Srestartoffset,Pchksumt,Srestartdriveno-1,Srestartchksumstart);//~va30R~
            uerrexit("\nchksum err;input upto offset=%s(chksum=%08lx)\n\
and on index file of No %d disk(chksum=%08lx)",0,                  //~va30I~
                xffeditfszx(Srestartoffset,0),Pchksumt,Srestartdriveno-1,Srestartchksumstart);//~va30R~
		return 0;	//continue process                             //~v131R~
	}                                                              //~v131I~
	if (Pcurrno==Srestartdriveno)   //just the retry subfile       //~v131R~
    {                                                              //~v131I~
        if (Srestartdrivesw!=1)	//restart case(not one drive)      //~v131R~
        	return 0;			//continue process                 //~v131I~
    	if (Pchksumt!=Srestartchksumend)                           //~v131R~
//            uerrexit("\nchksum err;input upto offset=%08lx(chksum=%08lx)\n//~va30R~
//and on index file of No %d  disk(chksum=%08lx)",0,               //~va30R~
//                Srestartoffset+Srestartlen,Pchksumt,Srestartdriveno+1,Srestartchksumend);//~va30R~
            uerrexit("\nchksum err;input upto offset=%s(chksum=%08lx)\n\
and on index file of No %d  disk(chksum=%08lx)",0,                 //~va30I~
                xffeditfszx(Srestartoffset+Srestartlen,0),Pchksumt,Srestartdriveno+1,Srestartchksumend);//~va30R~
        	return 1;			//end process                      //~v131R~
    }                                                              //~v131I~
    return 0;                                                      //~v131R~
}//restartchk2                                                     //~v131I~
//*****************************************************************//~v131R~
//* drive no chk at restart                                        //~v131I~
//*   set start offset of resart subfile when driveno=restart No-1 //~v131I~
//*parm1:current driveno                                           //~v131I~
//*parm2:output size;set when just before and just if retry one drive//~v131R~
//*ret :0:skip mount chk(up to just before),1:nomal process(mount req)//~v131R~
//*     2:1st disk retry                                           //~v131I~
//*****************************************************************//~v131R~
//int restartdrvchk(int Pcurrno,long *Ppsize)                      //~va30R~
int restartdrvchk(int Pcurrno,FILESZT *Ppsize)                     //~va30I~
{                                                                  //~v131I~
//  long offset[2],subflen[2];                                     //~va30R~
    FILESZT offset[2],subflen[2];                                  //~va30I~
    ULONG chksumst[2],chksumsub[2];                                //~v131I~
//******************                                               //~v131I~
	if (!Srestartdrivesw)                                          //~v131I~
    	return 1;				//normal process                   //~v131I~
   	if (Pcurrno<Srestartdriveno-1)       //before just before      //~v131R~
    	return 0;                        //skip mount chk          //~v131R~
   	if (Pcurrno==Srestartdriveno)        //retry subfile           //~v131R~
    {                                                              //~v131I~
        if (Srestartdriveno==1)         //no just before timing    //~v134I~
        {                                                          //~v134I~
		    Srestartoffset=0;                                      //~v134I~
		    Srestartchksumstart=0;                                 //~v134I~
    	    restartdrvchksub(1,Srestartdriveno+1,&offset[1],&subflen[1],&chksumst[1],&chksumsub[1]);//~v134I~
	    	Srestartchksumend=chksumst[1];                         //~v134I~
	    	Srestartlen=offset[1];                                 //~v134I~
        	*Ppsize=Srestartlen;		//confirm same free space as previously written//~v131I~
            return 2;                                              //~v131I~
        }                                                          //~v134I~
    	if (Srestartdrivesw==1)			//one drive                //~v131I~
        	*Ppsize=Srestartlen;		//confirm same free space as previously written//~v131R~
	    return 1;				//normal process                   //~v131I~
	}                                                              //~v131I~
   	if (Pcurrno>Srestartdriveno)       //after restartno           //~v131R~
	    return 1;				//normal process                   //~v131I~
//drive just before                                                //~v131I~
    restartdrvchksub(0,Srestartdriveno-1,&offset[0],&subflen[0],&chksumst[0],&chksumsub[0]);//~v134R~
    Srestartoffset=*Ppsize=offset[0]+subflen[0];		//start offset//~v132M~
    Srestartchksumstart=uaddc(chksumst[0],chksumsub[0]);	//start chksum//~v132M~
//drive just after                                                 //~v132I~
    if (Srestartdrivesw==1) //one drive                            //~v131R~
    {                                                              //~v132M~
        Smsgsw=1;                                                  //~v131I~
        restartdrvchksub(1,Srestartdriveno+1,&offset[1],&subflen[1],&chksumst[1],&chksumsub[1]);//~v131R~
        Smsgsw=0;                                                  //~v131I~
	    Srestartchksumend=chksumst[1];                             //~v131I~
	    Srestartlen=offset[1]-offset[0]-subflen[0];                //~v132R~
	}                                                              //~v131I~
//printf("info from ctl offset=%08lx,len=%08lx,chksum=%08lx,%08lx\n",//~v131R~
//		Srestartoffset,Srestartlen,Srestartchksumstart,Srestartchksumend);//~v131R~
    return 0;		//skip mount chk                               //~v131R~
}//restartdrvchk                                                   //~v131R~
                                                                   //~v131I~
//**********************************************************************//~v131I~
//* drive no chk at restart                                        //~v131I~
//*   set start offset of resart subfile when driveno=restart No-1 //~v131I~
//*parm1:drive position id; 0:just before,1:just after             //~v131I~
//*parm2:drive no to be chk                                        //~v131I~
//*parm3:output subfile start offset                               //~v131I~
//*parm4:output subfile len                                        //~v131I~
//*parm5:output start chksum                                       //~v131I~
//*parm6:output subfile chksum                                     //~v131I~
//*ret  :none                                                      //~v131I~
//**********************************************************************//~v131I~
//void restartdrvchksub(int Ppos,int Pcurrno,long *Ppoffset,long *Pplen,//~va30R~
void restartdrvchksub(int Ppos,int Pcurrno,FILESZT *Ppoffset,FILESZT *Pplen,//~va30I~
					ULONG *Ppchksumst,ULONG *Ppchksumsub)          //~v131I~
{                                                                  //~v131I~
static char S1stfname[_MAX_PATH];                                  //~v131I~
static int Smntreq=0;	//first time mount requested from parmchk  //~v132I~
	char *pc,*pc2;                                                 //~v131I~
	int seqno;                                                     //~v131I~
	int  eofid,rc;                                                 //~v131R~
    int datano;                                                    //~v131I~
	char hdrinf[128];                                              //~v131I~
	char orgfname[_MAX_PATH];                                      //~v132I~
//  long fsize;                                                    //~va30R~
    FILESZT fsize;                                                 //~va30I~
//******************                                               //~v131I~
	rc=1;                                                          //~v131I~
    while (rc)                                                     //~v131R~
    {                                                              //~v131R~
        if (Shindex)                                               //~v131R~
        {                                                          //~v131R~
            fclose(Shindex);                                       //~v171R~
            Shindex=0;                                             //~v131R~
        }                                                          //~v131R~
        if (Smntreq)                                               //~v132I~
//          mountreq(Sorgfname,3,0,Pcurrno); //mount req just before//~va30R~
            mountreq(Sorgfname,3,(FILESZT)0,Pcurrno); //mount req just before//~va30I~
        else                                                       //~v132I~
        	Smntreq=1;                                             //~v132I~
        Shindex=openfile(Sindexfnm,"r",-1,FT_INDEX); //retur if open err//~v171R~
        if (!Shindex)   //index file open failed                   //~v131R~
        {                                                          //~v131R~
            uerrmsg("Restore control file(%s) open err",           //~v131R~
                    "統合制御ファイル %s のオープンエラー",        //~v131R~
                     Sindexfnm);                                   //~v131R~
            continue;                                              //~v131R~
        }                                                          //~v131R~
        pc=getindexrec(&pc2);   //get first line                   //~v131R~
        if (!pc)                                                   //~v131R~
        {                                                          //~v131I~
            invalidindexrec(0);                                    //~v131I~
            continue;                                              //~v131I~
		}                                                          //~v131I~
#ifdef LFSSUPP                                                     //~va30I~
        datano=sscanf(pc2,"%s (x%" FILESZ_EDIT "x) %d(%d) %s",     //~va30I~
                            hdrinf,&fsize,&seqno,&eofid,hdrinf+32);//~va30I~
#else                                                              //~va30I~
        datano=sscanf(pc2,"%s (x%08lx) %d(%d) %s",                 //~v131R~
                            hdrinf,&fsize,&seqno,&eofid,hdrinf+32);//~v131R~
#endif                                                             //~va30I~
//printf("rec1 %s:fsize=%08lx,seqno=%d,eof=%d,hdrinf=%s\n",        //~v131R~
//					hdrinf,fsize,seqno,eofid,hdrinf+32);           //~v131R~
        if (datano!=5)                                             //~v131I~
        {                                                          //~v131R~
            invalidindexrec(0);                                    //~v131R~
            continue;                                              //~v131I~
        }                                                          //~v131R~
        strncpy(orgfname,pc,sizeof(orgfname));                     //~v132I~
        if (S1stfname[0])  //not first time                        //~v132R~
            if (stricmp(pc,S1stfname))                             //~v132R~
            {                                                      //~v131R~
                uerrmsg("This is for another files(%s)",           //~v131R~
                        "これは別のファイル(%s)のサブファイルです",//~v131R~
                        pc);                                       //~v131R~
	            continue;                                          //~v131I~
            }                                                      //~v131R~
        if (Pcurrno!=seqno)                                        //~v131R~
        {                                                          //~v131R~
            uerrmsg("Seq error,set No. %d disk",                   //~v133R~
                    "順番が違います, Ｎｏ.%d をセットしてください",//~v132R~
                    Pcurrno);                                      //~v131R~
	        continue;                                              //~v131I~
        }                                                          //~v131R~
        if (!Ppos)      //just before                              //~v132M~
            if (eofid)                                             //~v132M~
                uerrexit("No %d is last subfile,check /# parm",    //~v131R~
                        "No %d は最後のサブファイルです,/# パラメータをチェックして下さい",//~v131R~
                         Pcurrno);                                 //~v132M~
        pc=getindexrec(&pc2);   //get first line                   //~v131R~
        if (!pc)                                                   //~v131R~
        {                                                          //~v131R~
            invalidindexrec(0);                                    //~v131R~
	        continue;                                              //~v131I~
        }                                                          //~v131R~
#ifdef LFSSUPP                                                     //~va30I~
        datano=sscanf(pc2,"%s %s " CHKSUMIDST "%08lx " CHKSUMIDSF "%08lx,"//~va30I~
 CHKSUMIDOF "%" FILESZ_EDIT "x," CHKSUMIDLN "%" FILESZ_EDIT "x",   //~va30I~
                 hdrinf,hdrinf+32,Ppchksumst,Ppchksumsub,Ppoffset,Pplen);//~va30I~
#else                                                              //~va30I~
        datano=sscanf(pc2,"%s %s " CHKSUMIDST "%08lx " CHKSUMIDSF "%08lx,"//~v131I~
 CHKSUMIDOF "%08lx," CHKSUMIDLN "%08lx",                           //~v131I~
                 hdrinf,hdrinf+32,Ppchksumst,Ppchksumsub,Ppoffset,Pplen);//~v132R~
#endif                                                             //~va30I~
		if (datano!=6)                                             //~v131I~
        {                                                          //~v131I~
            invalidindexrec(0);                                    //~v131I~
	        continue;                                              //~v131I~
        }                                                          //~v131I~
        if (!S1stfname[0])  //first time                           //~v132I~
        {                                                          //~v132I~
            strncpy(S1stfname,orgfname,sizeof(S1stfname));	//save at first record//~v132R~
            Sorgfsz=fsize;                                         //~v132I~
        }                                                          //~v132I~
        rc=0; //beak                                               //~v131R~
    }//while err                                                   //~v131R~
//printf("rec2 %s:chksun=%08lx,%08lx,offs=%08lx,len=%08lx,hdr=%s\n",//~v131R~
//					hdrinf,*Ppchksumst,*Ppchksumsub,*Ppoffset,*Pplen,hdrinf+32);//~v131R~
    if (Shindex)                                                   //~v131I~
    {                                                              //~v131I~
        fclose(Shindex);                                           //~v171R~
        Shindex=0;                                                 //~v131I~
    }                                                              //~v131I~
	return;                                                        //~v131I~
}//restartdrvchksub                                                //~v131I~
                                                                   //~v131I~
//**********************************************************************//~v10jI~
//* get index record                                               //~v10jI~
//*parm:optional output comment addr ptr                           //~v10lR~
//*ret :filename addr                                              //~v10jI~
//**********************************************************************//~v10jI~
char *getindexrec(char **Ppcomm)                                   //~v10lR~
{                                                                  //~v10jI~
static char Sindexrec[INDEXRECSZ];                                 //~v10jI~
	char *fnm,*pc;                                                 //~v10jR~
	char *pc2;                                                     //~v127I~
    char *endofspacefnm=ENDOFSPACEFILENM;                          //~va4aR~
//******************                                               //~v10jR~
    Snochksumsw=1;          //err                                  //~v127I~
	fnm=fgets(Sindexrec,INDEXRECSZ,Shindex);                       //~v10jI~
//printf("getindexrec fh=%08lx,%s\n",Shindex,fnm);                 //~v10sR~
    if (fnm)	//not eof                                          //~v10jI~
    {                                                              //~v10jI~
        if (*(Sindexrec+strlen(Sindexrec)-1)=='\n')                //~v10jI~
            *(Sindexrec+strlen(Sindexrec)-1)=0;                    //~v10jI~
        if (!memcmp(Sindexrec,Sindexrecid,strlen(Sindexrecid)))    //~v10jI~
        {                                                          //~v10jI~
            fnm=Sindexrec+strlen(Sindexrecid);                     //~v10jI~
            if (pc2=strchr(fnm,CHKSUMID),pc2)	//chksum written   //~v127R~
            {                                                      //~v127I~
            	if (pc2=strstr(pc2,CHKSUMIDST),pc2)                //~v127R~
                {                                                  //~v127I~
                	pc2+=strlen(CHKSUMIDST);                       //~v127I~
                    if (!ux2l(pc2,&Sgatherchksumstart))            //~v127R~
		            	if (pc2=strstr(pc2,CHKSUMIDSF),pc2)        //~v127I~
        		        {                                          //~v127I~
		                	pc2+=strlen(CHKSUMIDSF);               //~v127I~
                    		if (!ux2l(pc2,&Sgatherchksumsubfile))  //~v127R~
				            	if (pc2=strstr(pc2,CHKSUMIDOF),pc2)//~v127I~
        				        {                                  //~v127I~
		        		        	pc2+=strlen(CHKSUMIDOF);       //~v127I~
#ifdef LFSSUPP                                                     //~va30I~
    		                		if (!ux2ll(pc2,&Sgatherchksumoffs))//~va30I~
#else                                                              //~va30I~
    		                		if (!ux2l(pc2,&Sgatherchksumoffs))//~v127I~
#endif                                                             //~va30I~
						            	if (pc2=strstr(pc2,CHKSUMIDLN),pc2)//~v127I~
        						        {                          //~v127I~
		        				        	pc2+=strlen(CHKSUMIDLN);//~v127I~
#ifdef LFSSUPP                                                     //~va30I~
    				                		if (!ux2ll(pc2,&Sgatherchksumlen))//~va30I~
#else                                                              //~va30I~
    				                		if (!ux2l(pc2,&Sgatherchksumlen))//~v127I~
#endif                                                             //~va30I~
								                Snochksumsw=0;    		//ok//~v127I~
        						        }//len found               //~v127I~
		        		        }//offset found                    //~v127I~
        		        }//subfile found                           //~v127R~
                }                                                  //~v127I~
//printf("start=%08lx,subfile=%08lx,offs=%08lx,len=%08lx\n",Sgatherchksumstart,Sgatherchksumsubfile,Sgatherchksumoffs,Sgatherchksumlen);//~v129R~
            	if (Snochksumsw)                                   //~v127R~
    				chksumerr(4,0,0,0);//no subfileno use          //~v127R~
            }//chksum written                                      //~v127R~
            if (pc=strchr(fnm,*endofspacefnm),pc)                  //~va4aI~
            {                                                      //~va4aI~
            	*pc=0;				//cut comment                  //~va4aI~
                if (Ppcomm)                                        //~va4aI~
                	*Ppcomm=pc+1;                                  //~va4aI~
			}                                                      //~va4aI~
            else                                                   //~va4aI~
            if (pc=strchr(fnm,' '),pc)                             //~v10jI~
            {                                                      //~v10lI~
            	*pc=0;				//cut comment                  //~v10jI~
                if (Ppcomm)                                        //~v10lI~
                	*Ppcomm=pc+1;                                  //~v10lI~
			}                                                      //~v10lI~
            if (!stricmp(fnm,Snullid))   //null file               //~v10jR~
                uerrmsg("Warning! NUL file used as split subfile,result may not be complete.",0);//~v10jI~
        }                                                          //~v10jI~
        else                                                       //~v10jI~
            fnm=0;                                                 //~v10jI~
    }                                                              //~v10jI~
    return fnm;                                                    //~v10jI~
}//getindexrec                                                     //~v10jI~
                                                                   //~v10jI~
//**********************************************************************//~v10kI~
//* removable drive chk                                            //~v10kI~
//*parm1:output file fullpath name                                 //~v10kI~
//*parm2:input subfileno                                           //~v132I~
//*parm3:output file size requested                                //~v132R~
//*ret  :0:fixed ,1:removable                                      //~v10kR~
//**********************************************************************//~v10kI~
//int drivechk(char *Pfullpath,int Pfileno,long *Ppsize)           //~va30R~
int drivechk(char *Pfullpath,int Pfileno,FILESZT_S *Ppsize)        //~va30R~
{                                                                  //~v10kI~
    PUDIRLIST pudirlist=0;                                         //~v136R~
	char rdir[8];                                                  //~v10kI~
    char confmsg[256];                                             //~v10mR~
	char reply;                                                    //~v10kI~
    int fno;                                                       //~v10kI~
    int rfno,delopt;                                               //~v174I~
    long freesz;                                                   //~v10lR~
//  long reqsz;                                                    //~va30R~
    FILESZT reqsz;                                                 //~va30I~
//  char editwkn[16];                                              //~va30R~
    char editwkn[32],editwkn2[32];                                 //~va30I~
    int restid;                                                    //~v131I~
//******************                                               //~v10kI~
	restid=(restartchk1(Pfileno)==2);	//retry subfileno          //~v131I~
    reqsz=*Ppsize;                                                 //~v10sI~
	if (!drivechksub(*Pfullpath))	//not removable                //~v10kI~
    {                                                              //~v134I~
        if (Pfileno==1)  			//first time when not removable//~v134I~
        	indexchk(0);            //not removable                //~v134I~
    	return 0;                                                  //~v10kR~
	}                                                              //~v134I~
    if (PATHLEN(Pfullpath)!=3)      //not root                     //~v10kI~
        uerrexit("Output should be on root directory for removable device",0);//~v10kR~
	memcpy(rdir,Pfullpath,3);	//d:\  set                         //~v10kR~
//  strcpy(rdir+3,"*.*");                                          //~v171R~
    strcpy(rdir+3,DIR_ALLMEMB);                                    //~v171I~
 for (;;)                                                          //~v10sI~
 {                                                                 //~v10sI~
  for (;;)                                                         //~v10sI~
  {                                                                //~v10sI~
                                                                   //~v134I~
//    if ((fno=udirlistnomsg(rdir,FILE_ALL,&pudirlist,0))<=0)      //~v134R~
//    {                                                            //~v132R~
////      return 0;                                                //~v132R~
//      if (!fno)  //findfirstop                                   //~v132R~
//        break;                                                   //~v134R~
//        if (!Sdbcssw)                                            //~v132R~
//            sprintf(confmsg,"Drive %c is invalid format,\n\ //   //~va1jR~
//ready another volume(Enter) or cancel(Esc)?",*Pfullpath);        //~v132R~
//        else                                                     //~v132R~
//            sprintf(confmsg,"ディスク %c のフォーマットが正しくありません,\n\ ////~va1jR~
//別のディスク準備ＯＫ(Enter)?,取消(Esc)?",*Pfullpath);            //~v132R~
////      reply=confirm(confmsg,confmsg,"RrNn");                   //~v132R~
//        confirm(confmsg,confmsg,"\r\x1b");                       //~v132R~
//        reply='R';      //retry logic                            //~v132R~
//        continue;                                                //~v132R~
//    }                                                            //~v132R~
    for (;;)    //until ino index or ndex overide                  //~v134I~
    {                                                              //~v134I~
	    if (pudirlist)                                             //~v136I~
		    ufree(pudirlist);                                      //~v136I~
      	if ((fno=udirlistnomsg(rdir,FILE_ALL,&pudirlist,0))<=0)    //~v134I~
        {                                                          //~v131I~
        	pudirlist=0;                                           //~v136I~
            reply='Y';      //go                                   //~v131R~
        	break;                                                 //~v134I~
        }                                                          //~v131I~
		reply=indexchk(1);                                         //~v134R~
        if (reply=='L')                                            //~v136I~
        {                                                          //~v136I~
            listdir(fno,pudirlist);                                //~v136I~
            continue;                                              //~v136I~
        }                                                          //~v136I~
        if (reply!='\r')	//delete or override                   //~v134R~
        	break;                                                 //~v134I~
    }                                                              //~v134I~
//#ifdef UNX                                                         //~v140I~//~va48R~
    freesz=getfreespace(Pfullpath,&Sclustersz);                    //~v140I~
//#else                                                              //~v140I~//~va48R~
//  freesz=getfreespace(*Pfullpath,&Sclustersz);                   //~v10sI~//~va48R~
//#endif                                                             //~v140I~//~va48R~
    if (reply)      //delete or override index                     //~v134R~
        break;                                                     //~v134I~
  if (Sremovablesw==2 && !Sdelysw)  //force by parm,no delete option//~v146R~
  {                                                                //~v146I~
    if (!Sdbcssw)                                                  //~v146I~
        sprintf(confmsg,"Disk(%c:) is not empty(free=%ld=x%08lX),\n\
continue(Y),list dir(L),another disk set OK(Enter) or cancel(Esc)?",//~v146I~
			*Pfullpath,                                            //~v146I~
			freesz,freesz);                                        //~v146I~
	else                                                           //~v146I~
    	sprintf(confmsg,"ディスク(%c:)が空ではありません(現在 %ld=x%08lX 空き),\n\
処理続行(Y)?,内容\x95\\示(L)?,別のディスク準備ＯＫ(Enter)?,取消(Esc)?",//~v146I~
			*Pfullpath,                                            //~v146I~
			freesz,freesz);                                        //~v146I~
    reply=confirm(confmsg,confmsg,"YyLl\r\x1b");                   //~v146I~
  }                                                                //~v146I~
  else                                                             //~v146I~
  {                                                                //~v146I~
   if (Sremovablesw!=2)  //removable,not by parm                   //~v146I~
    if (Sdelysw)	                                               //~v127I~
    {                                                              //~v127I~
    	reply='D';		//delete implicit                          //~v127I~
        break;                                                     //~v127I~
    }                                                              //~v127I~
    if (!Sdbcssw)                                                  //~v10kI~
        sprintf(confmsg,"Disk(%c:) is not empty(free=%ld=x%08lX),\n\
delete all(D),continue(Y),list dir(L),another disk set OK(Enter) or cancel(Esc)?",//~v136I~
			*Pfullpath,                                            //~v146I~
			freesz,freesz);                                        //~v133I~
	else                                                           //~v10kI~
    	sprintf(confmsg,"ディスク(%c:)が空ではありません(現在 %ld=x%08lX 空き),\n\
全削除実行(D)?,処理続行(Y)?,内容\x95\\示(L)?,別のディスク準備ＯＫ(Enter)?,取消(Esc)?",//~v136R~
			*Pfullpath,                                            //~v146I~
			freesz,freesz);                                        //~v133I~
    reply=confirm(confmsg,confmsg,"DdYyLl\r\x1b");                 //~v136R~
  }                                                                //~v146I~
    if (toupper(reply)=='L')                                       //~v136I~
    {                                                              //~v136I~
    	listdir(fno,pudirlist);                                    //~v136I~
    	continue;                                                  //~v136I~
    }                                                              //~v136I~
    if (reply!='\r')    //del or override                          //~v134R~
        break;                                                     //~v10sI~
  }                                                                //~v10sI~
//printf("reply =%c\n",reply);                                     //~v10qR~
  if (fno>0)            //file exist case                          //~v1.1R~
    if (toupper(reply)=='D')                                       //~v10kI~
    {                                                              //~v123I~
      for (;;)  //retry when write err                             //~v137I~
      {                                                            //~v137I~
        printf("Deleting %s...",rdir);                             //~v123I~
        fflush(stdout);                                            //~v123I~
        rfno=0;                                                    //~v174I~
    	uxdelete(rdir,FILE_ALL,UXDELRONLYCHK|UXDELFORCE,&fno,&rfno,&fno);//~v174R~
        delopt=UXDELFORCE;                                         //~v174I~
        if (rfno)                                                  //~v174I~
        {                                                          //~v174I~
#ifdef AIX                                                         //~v174I~
            if (!Sdbcssw)                                          //~v174I~
                sprintf(confmsg,"%d ReadOnly file exist; Skip readonly(S) or cancel(Esc)?",rfno);//~v174R~
            else                                                   //~v174I~
                sprintf(confmsg,"%d 読取専用ファイル有り; 読取専用スキップ(S)?,取消(Esc)?",rfno);//~v174R~
            reply=confirm(confmsg,confmsg,"Ss\x1b");               //~v174I~
#else                                                              //~v174I~
            if (!Sdbcssw)                                          //~v174I~
                sprintf(confmsg,"%d ReadOnly file exist; Force delete(F), Skip readonly(S) or cancel(Esc)?",rfno);//~v174R~
            else                                                   //~v174I~
                sprintf(confmsg,"%d 読取専用ファイル有り; 強制削除(F)?,読取専用スキップ(S)?,取消(Esc)?",rfno);//~v174R~
            reply=confirm(confmsg,confmsg,"FfSs\x1b");             //~v174I~
#endif                                                             //~v174I~
    		if (toupper(reply)=='S')                               //~v174I~
            	delopt=UXDELSKIPRONLY;                             //~v174I~
        }//ronly exist                                             //~v174I~
//  	if (uxdelete(rdir,FILE_ALL,UXDELFORCE,&fno,&fno,&fno))     //~v174R~
    	if (uxdelete(rdir,FILE_ALL,delopt,&fno,&fno,&fno))         //~v174I~
        {                                                          //~v137I~
//      	uerrexit("File deletion failed",0);                    //~v137R~
//          mountreq(0,7,0,0);    //write err                      //~va30R~
            mountreq(0,7,(FILESZT)0,0);    //write err             //~va30I~
            continue;                                              //~v137I~
        }                                                          //~v137I~
        break;                                                     //~v137I~
      }//retry loop                                                //~v137I~
        printf("\n");                                              //~v123I~
    }                                                              //~v123I~
//printf("reply =%c\n",reply);                                     //~v10qR~
    if (*Spgmnm)    //copy requested                               //~v10qI~
    {                                                              //~v10qI~
        pgmcopy();                                                 //~v10qR~
        *Spgmnm=0;           //processed                           //~v10qR~
    }                                                              //~v10qI~
//#ifdef UNX                                                         //~v140I~//~va48R~
    freesz=getfreespace(Pfullpath,&Sclustersz);                    //~v140I~
//#else                                                              //~v140I~//~va48R~
//  freesz=getfreespace(*Pfullpath,&Sclustersz);                   //~v10lR~//~va48R~
//#endif                                                             //~v140I~//~va48R~
//printf("req=%08lx,freesz=%08lx\n",reqsize,freesz);               //~v10sR~
	reply=0;                                                       //~v10sI~
    if (*Ppsize>freesz-Sclustersz)                                 //~v10lR~
    {                                                              //~v10kI~
    	if (freesz>Sclustersz)                                     //~v10lR~
        {                                                          //~va1jI~
//          if (*Ppsize==LASTFSIZE)                                //~va30R~
            if ((FILESZT)(*Ppsize)==LASTFSIZE)                     //~va30I~
            {                                                      //~v123I~
				unumedit((ULONG)(freesz-Sclustersz),Snumeditptn,editwkn);//~v123I~
                uerrmsg("%s(x%08lX) is avail on %c:",0,            //~v123R~
						editwkn,freesz-Sclustersz,*Pfullpath);     //~v123R~
            }                                                      //~v123I~
            else                                                   //~v10kI~
        	{                                                      //~v10kI~
              xffeditfszz(*Ppsize,editwkn);                        //~va30R~
              xffeditfszx(*Ppsize+Sclustersz,editwkn2);            //~va30R~
              if(restid)	//retry subfileno                      //~v131R~
              {                                                    //~v132I~
                if (!Sdbcssw)                                      //~v132I~
//                  sprintf(confmsg,"Req size for %s (%ld+%ld=x%08lX) is not avail(currently free=%ld (x%08lX)),\n//~va30R~
                    sprintf(confmsg,"Req size for %s (%s+%ld=x%s) is not avail(currently free=%ld (x%08lX)),\n\
another disk setup OK(Enter) or cancel(Esc)?",                     //~v134R~
//                      Pfullpath,*Ppsize,Sclustersz,*Ppsize+Sclustersz,freesz,freesz);//~va30R~
                        Pfullpath,editwkn,Sclustersz,editwkn2,freesz,freesz);//~va30I~
                else                                               //~v132I~
//                  sprintf(confmsg,"再出力の場合前回と同じだけの空スペースが必要です.\n//~va30R~
//%sのための空き(%ld+%ld=x%08lX)がありません(現在 %ld=x%08lX),\n   //~va30R~
                    sprintf(confmsg,"再出力の場合前回と同じだけの空スペースが必要です.\n\
%sのための空き(%s+%ld=x%s)がありません(現在 %ld=x%08lX),\n\
別のディスク準備ＯＫ(Enter)?,取消(Esc)?",                          //~v132I~
//                      Pfullpath,*Ppsize,Sclustersz,*Ppsize+Sclustersz,freesz,freesz);//~va30R~
                        Pfullpath,editwkn,Sclustersz,editwkn2,freesz,freesz);//~va30I~
                confirm(confmsg,confmsg,"\r\x1b");                 //~v133R~
                reply='\r';      //enter is Enter                  //~v134R~
              }                                                    //~v132I~
              else                                                 //~v132I~
              {                                                    //~v132I~
                if (!Sdbcssw)                                      //~v10kR~
//                  sprintf(confmsg,"Req size for %s (%ld+%ld=x%08lX) is not avail(currently free=%ld (x%08lX)),\n//~va30R~
                    sprintf(confmsg,"Req size for %s (%s+%ld=x%s) is not avail(currently free=%ld (x%08lX)),\n\
continue within the space(Y),another disk setup OK(Enter) or cancel(Esc)?",//~v131R~
//                      Pfullpath,*Ppsize,Sclustersz,*Ppsize+Sclustersz,freesz,freesz);//~va30R~
                        Pfullpath,editwkn,Sclustersz,editwkn2,freesz,freesz);//~va30I~
                else                                               //~v10kR~
//                  sprintf(confmsg,"%sのための空き(%ld+%ld=x%08lX)がありません(現在 %ld=x%08lX),\n//~va30R~
                    sprintf(confmsg,"%sのための空き(%s+%ld=x%s)がありません(現在 %ld=x%08lX),\n\
その空きの範囲内で出力(Y)?,別のディスク準備ＯＫ(Enter)?,,取消(Esc)?",//~v131R~
                        Pfullpath,editwkn,Sclustersz,editwkn2,freesz,freesz);//~va30R~
                reply=confirm(confmsg,confmsg,"Yy\r\x1b");         //~v131R~
              }                                                    //~v132I~
			}                                                      //~v10kR~
        }//freesz                                                  //~va1jI~
		if (freesz>Sclustersz)                                     //~v10rR~
        {                                                          //~v131I~
          if (!restid)				//not the retry disk           //~v131I~
			reqsz=freesz-Sclustersz;                               //~v10sR~
		}                                                          //~v131I~
		else                                                       //~v10rI~
			reqsz=0;                                               //~v10sR~
	}                                                              //~v10kI~
  	if (reply!='\r')	//Go                                       //~v134R~
  		break;                                                     //~v134R~
 }//retry loop                                                     //~v10sI~
    *Ppsize=reqsz;                                                 //~v10sI~
    if (pudirlist)                                                 //~v136I~
	    ufree(pudirlist);                                          //~v136I~
    return 1;                                                      //~v10kR~
}//drivechk                                                        //~v10kI~
//**********************************************************************//~v10rI~
//* index file exist warning                                       //~v10rI~
//*parm :removable sw                                              //~v134R~
//*ret  :0:no index file found,'Y':override,'\r':retry,'D':delete all//~v131R~
//**********************************************************************//~v10rI~
char indexchk(int Premovablesw)                                    //~v134R~
{                                                                  //~v10rI~
    FILEFINDBUF3 fstat3;                                           //~v10rI~
//  char confmsg[256],*pc;                                         //~vaq1R~
    char confmsg[_MAX_PATH+256],*pc;                               //~vaq1I~
    char reply;                                                    //~v134I~
    char rc=0;	                                                   //~v134R~
//******************                                               //~v10rI~
//*check index file override                                       //~v10rM~
    if (!ufstat(Sindexfnm,&fstat3)) //exist                        //~v10rI~
    {                                                              //~v10rI~
        Shindex=openfile(Sindexfnm,"r",0,FT_INDEX);  //no open msg //~v171R~
        pc=getindexrec(0);                                         //~v10rI~
        fclose(Shindex);                                           //~v171R~
        Shindex=0;//closed                                         //~v10rI~
        if (!pc)                                                   //~v10rI~
            uerrexit("Same filename as restore control file(%s) is exist",//~v10rI~
                     "同名の統合制御ファイルでないファイル(%s)があります",//~v131R~
                        Sindexfnm);                                //~v10rI~
		if (Premovablesw)                                          //~v134I~
        {                                                          //~v134I~
  		  if (Sremovablesw==2 && !Sdelysw)  //force by parm,no dele option//~v146R~
          {                                                        //~v146I~
            if (!Sdbcssw)                                          //~v146I~
                sprintf(confmsg,"Restore control file is exist (%s for %s),\n\
override(Y),list dir(L),another disk set OK(Enetr) or cancel(Esc)?",//~v146I~
					Sindexfnm,pc);                                 //~v146I~
            else                                                   //~v146I~
                sprintf(confmsg,"統合制御ファイルがあります(%s for %s)、\n\
上書実行(Y)?,内容\x95\\示(L),別のディスク準備ＯＫ(Enter)?,取消(Esc)? ",//~v146I~
					Sindexfnm,pc);                                 //~v146I~
            reply=confirm(confmsg,confmsg,"DdYyLl\r\x1b");         //~v146I~
          }                                                        //~v146I~
          else                                                     //~v146I~
  		  {                                                        //~v146I~
            if (!Sdbcssw)                                          //~v134I~
                sprintf(confmsg,"Restore control file is exist (%s for %s),\n\
delete all(D),override(Y),list dir(L),another disk set OK(Enetr) or cancel(Esc)?",//~v136R~
					Sindexfnm,pc);                                 //~v134R~
            else                                                   //~v134I~
                sprintf(confmsg,"統合制御ファイルがあります(%s for %s)、\n\
全削除実行(D)?,上書実行(Y)?,内容\x95\\示(L),別のディスク準備ＯＫ(Enter)?,取消(Esc)? ",//~v136R~
					Sindexfnm,pc);                                 //~v134R~
            reply=confirm(confmsg,confmsg,"DdYyLl\r\x1b");         //~v136R~
  		  }//removable                                             //~v146I~
          if (reply=='L' || reply=='l')                            //~v136I~
          	rc='L'; 		//list dir                             //~v136I~
          else                                                     //~v136I~
            if (reply=='Y' || reply=='y')                          //~v131R~
            	rc='Y'; 		//override                         //~v131R~
            else                                                   //~v134I~
     	    	if (reply=='D' || reply=='d')                      //~v134I~
            		rc='D'; 		//delete                       //~v134R~
            	else                                               //~v134R~
            		rc='\r';		//retry                        //~v134R~
		}                                                          //~v134I~
        else                                                       //~v134I~
        {                                                          //~v134I~
            if (!Sdbcssw)                                          //~v10rI~
                sprintf(confmsg,"Restore control file is already exist (%s for %s),\n\
override(Y) or cancel(Esc)?",                                      //~v131R~
					Sindexfnm,pc);                                 //~v134I~
            else                                                   //~v10rI~
                sprintf(confmsg,"統合制御ファイルがあります(%s for %s)、\n\
上書き(Y)?,取消(Esc)?",                                            //~v131R~
						Sindexfnm,pc);                             //~v134I~
            confirm(confmsg,confmsg,"Yy\x1b");                     //~v131R~
            rc='Y';			//override                             //~v131R~
		}                                                          //~v134I~
    }                                                              //~v10rI~
    return rc;                                                     //~v134R~
}//indexchk                                                        //~v10rI~
//**********************************************************************//~v10lI~
//* get next drive fore restore                                    //~v10lI~
//*parm1:sw 0:first call,1:next call                               //~v10lI~
//*parm2:org fine name                                             //~v10lR~
//*parm3:residual len to be restore                                //~v10sI~
//*ret  :0:not last,1:last drive                                   //~v10lI~
//**********************************************************************//~v10lI~
//int getnextinputdrive(int Popt,char *Porgfname,long Preslen)     //~va30R~
int getnextinputdrive(int Popt,char *Porgfname,FILESZT_S Preslen)  //~va30I~
{                                                                  //~v10lI~
static char S1stfname[_MAX_PATH];                                  //~v10lR~
static int Sseqno=0;                                               //~va22R~
	char *pc=NULL,*pc2;                                                 //~v10lI~//~va64R~
	char *fnm;                                                     //~v10lI~
	int seqno;                                                     //~v10lR~
	int  eofid=0;                                                    //~v10lR~//~va64R~
//  long fsize;                                                    //~va30R~
    FILESZT fsize;                                                 //~va30I~
//  char editwk[32];                                               //~v123R~
    char fnmwk[_MAX_PATH+32];                                      //~v123I~
    int rc;                                                        //~v10lI~
//******************                                               //~v10lI~
    if (Popt)       //not first                                    //~v10lI~
    	Sseqno++;                                                  //~v10lI~
    else                                                           //~v10lI~
    	Sseqno=1;                                                  //~v10lR~
//printf("getnextinputdrive req=%d\n",Sseqno);                     //~v10mR~
	for (;;)                                                       //~v10lR~
    {                                                              //~v10lI~
        rc=1;                                                      //~v10lI~
        do          //break if err                                 //~v10lI~
        {                                                          //~v10lI~
            if (Shindex)                                           //~v10lR~
            {                                                      //~v10lR~
                fclose(Shindex);                                   //~v171R~
                Shindex=0;                                         //~v10lR~
//printf("close index\n");                                         //~v10mR~
            }                                                      //~v10lR~
            if (Popt)       //not first                            //~v10lR~
            {                                                      //~v10lR~
                sprintf(fnmwk,"No %d for %s",Sseqno,Sorgfname);    //~v123R~
                mountreq(fnmwk,1,Preslen,Sseqno);                  //~v123R~
            }                                                      //~v10lR~
            Shindex=openfile(Sindexfnm,"r",-1,FT_INDEX); //retur if open err//~v171R~
            if (!Shindex)   //index file open failed               //~v10lR~
            {                                                      //~v10lR~
                uerrmsg("Restore control file(%s) open err",       //~v10lR~
                        "統合制御ファイル %s のオープンエラー",    //~v131R~
                         Sindexfnm);                               //~v10lR~
                break;                                             //~v10lR~
            }                                                      //~v10lR~
            pc=getindexrec(&pc2);   //get first line               //~v10lR~
            if (!pc                                                //~v10lR~
#ifdef LFSSUPP                                                     //~va30I~
            ||  (sscanf(pc2,"%s (x%" FILESZ_EDIT "x) %d(%d) %s",   //~va30R~
								Shdrinf,&fsize,&seqno,&eofid,Shdrinf+32))!=5)//~va30I~
#else                                                              //~va30I~
            ||  (sscanf(pc2,"%s (x%08lx) %d(%d) %s",               //~v1.1R~
								Shdrinf,&fsize,&seqno,&eofid,Shdrinf+32))!=5)//~v10mR~
#endif                                                             //~va30I~
            {                                                      //~v10lR~
//printf("rec1 %s:%s fldno=%08lx,%d,%d,%d %s %s\n",pc,pc2,fldno,fsize,seqno,eofid,//~v10qR~
//  							Shdrinf,Shdrinf+32);               //~v10qR~
                invalidindexrec(0);                                //~v10lR~
                break;                                             //~v10lR~
            }                                                      //~v10lR~
//printf("rec1 %s:%s fldno=%08lx,%d,%d,%d\n",pc,pc2,fldno,fsize,seqno,eofid);//~v10mR~
            if (!Popt)      //first time                           //~v10lR~
            {                                                      //~v10lR~
                strcpy(S1stfname,pc);                              //~v10lR~
                if (seqno!=1)                                      //~v10lR~
                {                                                  //~v10lI~
    	            uerrmsg("It is not 1st disk",                  //~v133R~
        	                "最初のディスクではありません");       //~v132R~
                    break;                                         //~v10lR~
				}                                                  //~v10lI~
                Sseqno=seqno;                                      //~v10lR~
                if (!Sorgfsz)                                      //~v10lI~
                	Sorgfsz=fsize;                                 //~v10lI~
            }                                                      //~v10lR~
            else                                                   //~v10lR~
            {                                                      //~v10lR~
                if (stricmp(pc,S1stfname))                         //~v132R~
                {                                                  //~v10lI~
    	            uerrmsg("This is for another files(%s)",       //~v10lI~
        	                "これは別のファイル(%s)のサブファイルです",//~v10lI~
							pc);                                   //~v10lI~
                    break;                                         //~v10lI~
				}                                                  //~v10lI~
                if (Sseqno!=seqno)                                 //~v10lI~
                {                                                  //~v10lI~
    	            uerrmsg("Seq error,set No. %d disk",           //~v133R~
        	                "順番が違います, Ｎｏ.%d をセットしてください",//~v132R~
							Sseqno);                               //~v10lI~
                    break;                                         //~v10lI~
				}                                                  //~v10lI~
	  		  	fnm=getindexrec(0);                                //~v10lI~
                if (!fnm)                                          //~v10lI~
                {                                                  //~v10lI~
	                invalidindexrec(0);                            //~v10lR~
                    break;                                         //~v10lI~
                }                                                  //~v10lI~
            	strcpy(Snextsubfnm,fnm);                           //~v10lR~
                if (Sremovablesw!=drivechksub(*fnm))               //~v10lI~
                {                                                  //~v10lM~
                    uerrmsg("Fixed and removable drive is mixed for restore input",0);//~v10lM~
                    break;                                         //~v10lM~
                }                                                  //~v10lM~
            }                                                      //~v10lR~
            rc=0; //beak                                           //~v10lI~
        } while(rc);//err break                                    //~v10lR~
//printf("getnextinputdrive rc%d\n",rc);                           //~v10mR~
		if (!rc)                                                   //~v10lM~
        	break;                                                 //~v10lM~
        if (!Popt)  //1st file                                     //~v10lR~
            exit(8);                                               //~v10lR~
	}//retry loop                                                  //~v10lI~
    if (Porgfname)                                                 //~v10lI~
        strcpy(Porgfname,pc);                                      //~v10lR~
//printf("getnextinputdrive pc=%s,eofid=%d\n",pc,eofid);           //~v10mR~
	return eofid==1;                                               //~v10lR~
}//getnextinputdrive                                               //~v10lI~
//**********************************************************************//~v10lI~
//* indexfile err msg                                              //~v10lI~
//*parm1:exit sw                                                   //~v10lI~
//*ret  :none                                                      //~v10lI~
//**********************************************************************//~v10lI~
void invalidindexrec(int Pexitsw)                                  //~v1.1R~
{                                                                  //~v10lI~
	uerrmsg("%s is not valid restore control file",                //~v10lI~
            "%s が正しい統合制御ファイルではありません",           //~v131R~
            Sindexfnm);                                            //~v10lI~
	if (Pexitsw)                                                   //~v10lI~
    	exit(8);                                                   //~v10lI~
	return;                                                        //~v10lI~
}//invalidindexrec                                                 //~v10lI~
//**********************************************************************//~v10kI~
//* mount req msg                                                  //~v10kI~
//*parm1:output file fullpath name                                 //~v10kI~
//*parm2:msg no                                                    //~v10kI~
//*parm3:residual input(split)/output length(gather)               //~v10sI~
//*parm4:drive seqno                                               //~v123I~
//*ret  :none                                                      //~v10kI~
//**********************************************************************//~v10kI~
//void mountreq(char *Pfullpath,int Pmsgcase,long Preslen,int Pdriveno)//~va30R~
void mountreq(char *Pfullpath,int Pmsgcase,FILESZT Preslen,int Pdriveno)//~va30I~
{                                                                  //~v10kI~
#ifdef XFS_PRECHK                                                  //~v176I~
    UDISKINFO udiskinfo;                                           //~v176I~
//#ifdef UNX                                                         //~v176I~//~va48R~
    char      wkdrv[4];                                            //~v176I~
//#endif                                                             //~v176R~//~va48R~
#endif                                                             //~v176I~
    char confmsg[256];                                             //~v10mR~
//  char editwkn[16];                                              //~va30R~
    char editwkn[32],*pcx;                                         //~va30I~
//******************                                               //~v10kI~
//  unumedit((ULONG)Preslen,Snumeditptn,editwkn);                  //~va30R~
	pcx=xffeditfszzx(Preslen,editwkn);                             //~va30I~
	if (!Sremovablesw)                                             //~v10kI~
    	return;                                                    //~v10kI~
	switch (Pmsgcase)                                              //~v10kI~
    {                                                              //~v10kI~
    case 1:                                                        //~v10kI~
        if (!Sdbcssw)                                              //~v10kI~
//          sprintf(confmsg,"Set disk No. %d,%s (x%08lX) byte residual.\n//~va30R~
            sprintf(confmsg,"Set disk No. %d; %s (x%s) byte residual.\n\
%s --- ready(Enter) or cancel(Esc)?",                              //~v130R~
//  						Pdriveno,editwkn,Preslen,Pfullpath);   //~va30R~
    						Pdriveno,editwkn,pcx,Pfullpath);       //~va30I~
        else                                                       //~v10kI~
//          sprintf(confmsg,"No %d のディスクをセットしてください,残り%s (x%08lX)バイト.\n//~va30R~
            sprintf(confmsg,"No %d のディスクをセットしてください,残り%s (x%s)バイト.\n\
%s --- 準備ＯＫ(Enter)?,取消(Esc)?",                               //~v132R~
//  						Pdriveno,editwkn,Preslen,Pfullpath);   //~va30R~
    						Pdriveno,editwkn,pcx,Pfullpath);       //~va30I~
		break;                                                     //~v10kI~
    case 2:                                                        //~v10kI~
        if (!Sdbcssw)                                              //~v10kI~
//          sprintf(confmsg,"More%s (x%08lX) byte,disk has no space.Set next drive.\n//~va30R~
            sprintf(confmsg,"More%s (x%s) byte,disk has no space.Set next drive.\n\
%s --- ready(Enter) or cancel(Esc)?",                              //~v130R~
//  						editwkn,Preslen,Pfullpath);            //~va30R~
    						editwkn,pcx,Pfullpath);                //~va30I~
        else                                                       //~v10kI~
//          sprintf(confmsg,"残り%s (x%08lX)バイト,\n              //~va30R~
            sprintf(confmsg,"残り%s (x%s)バイト,\n\
ディスク に空きがありません,別のディスクをセットしてください.\n\
%s --- 準備ＯＫ(Enter)?,取消(Esc)?",                               //~v132R~
//  						editwkn,Preslen,Pfullpath);            //~va30R~
    						editwkn,pcx,Pfullpath);                //~va30I~
		break;                                                     //~v10kI~
    case 3:                 //restart mount msg                    //~v131I~
    	if (Srestartdrivesw==1)	//retry                            //~v131I~
        	if (!Sdbcssw)                                          //~v131I~
        		strcpy(editwkn,"for Retry Info");                  //~v131R~
            else                                                   //~v131I~
        		strcpy(editwkn,"再試行情報取得");                  //~v131I~
        else                                                       //~v131I~
        	if (!Sdbcssw)                                          //~v131I~
	        	strcpy(editwkn,"for Restart Info ");               //~v131R~
            else                                                   //~v131I~
        		strcpy(editwkn,"再開始情報取得");                  //~v131I~
        if (!Sdbcssw)                                              //~v131I~
            sprintf(confmsg,"Set disk No. %d for %s (%s).\n\
--- ready(Enter) or cancel(Esc)?",                                 //~v133R~
							Pdriveno,Pfullpath,editwkn);           //~v131I~
        else                                                       //~v131I~
            sprintf(confmsg,"Ｎｏ %d のディスクをセットしてください(%s %s).\n\
--- 準備ＯＫ(Enter)?,取消(Esc)?",                                  //~v133R~
							Pdriveno,Pfullpath,editwkn);           //~v132I~
		break;                                                     //~v131I~
    case 4:                 //first drive mount req                //~v131I~
        if (!Sdbcssw)                                              //~v132I~
            sprintf(confmsg,"Set disk No. %d for %s.\n\
--- ready(Enter) or cancel(Esc)?",                                 //~v133R~
							Pdriveno,Pfullpath);                   //~v132I~
        else                                                       //~v132I~
            sprintf(confmsg,"No. %d のディスクをセットしてください(%sの分割).\n\
--- 準備ＯＫ(Enter)?,取消(Esc)?",                                  //~v133R~
							Pdriveno,Pfullpath);                   //~v132I~
		break;                                                     //~v132I~
    case 5:                 //first drive mount req for restore    //~v131I~
        if (!Sdbcssw)                                              //~v131I~
            sprintf(confmsg,"Set disk No. %d on %c:.\n\
--- ready(Enter) or cancel(Esc)?",                                 //~v131I~
							Pdriveno,*Pfullpath);                  //~v131R~
        else                                                       //~v131I~
            sprintf(confmsg,"No. %d のディスクを %c: にセットしてください\n\
--- 準備ＯＫ(Enter)?,取消(Esc)?",                                  //~v131I~
							Pdriveno,*Pfullpath);                  //~v131I~
		break;                                                     //~v131I~
    case 6:                                                        //~v131I~
        if (!Sdbcssw)                                              //~v131I~
//          sprintf(confmsg,"Set retry disk of No. %d,\n           //~va30R~
//%s (x%08lX) byte+space for restore control file is required.\n   //~va30R~
            sprintf(confmsg,"Set retry disk of No. %d,\n\
%s (x%s) byte+space for restore control file is required.\n\
--- ready(Enter) or cancel(Esc)?",                                 //~v131I~
//  						Pdriveno,editwkn,Preslen);             //~va30R~
    						Pdriveno,editwkn,pcx);                 //~va30I~
        else                                                       //~v131I~
//          sprintf(confmsg,"No %d のリトライディスクをセットしてください,\n//~va30R~
//%s (x%08lX)バイト+統合制御ファイル分の空きが必要です.\n          //~va30R~
            sprintf(confmsg,"No %d のリトライディスクをセットしてください,\n\
%s (x%s)バイト+統合制御ファイル分の空きが必要です.\n\
--- 準備ＯＫ(Enter)?,取消(Esc)?",                                  //~v131I~
//  						Pdriveno,editwkn,Preslen);             //~va30R~
    						Pdriveno,editwkn,pcx);                 //~va30I~
		break;                                                     //~v131I~
    case 7:                                                        //~v137I~
        if (!Sdbcssw)                                              //~v137I~
            strcpy(confmsg,"Write protected ? --- ready(Enter) or cancel(Esc)?");//~v137I~
        else                                                       //~v137I~
            strcpy(confmsg,"書き込み保護？ --- 準備ＯＫ(Enter)?,取消(Esc)?");//~v137I~
		break;                                                     //~v137I~
	}                                                              //~v10kI~
#ifdef XFS_PRECHK                                                  //~v176I~
  for (;;)	//until drive ready                                    //~v176I~
  {                                                                //~v176I~
#endif                                                             //~v176R~
//  confirm(confmsg,confmsg,"YyNnDd");                             //~v130R~
    confirm(confmsg,confmsg,"\r\x1b");                             //~v130I~
#ifdef XFS_PRECHK                                                  //~v176M~
	if (!Sremovabledriveid)                                        //~v176I~
    	break;                                                     //~v176I~
//#ifdef UNX                                                         //~v176I~//~va48R~
	*wkdrv=(char)Sremovabledriveid;                                //~va22R~
    *(wkdrv+1)=':';                                                //~v176I~
    *(wkdrv+2)=0;                                                  //~v176R~
    if (!ugetdiskfree(wkdrv,&udiskinfo))	//to chk drive ready   //~v176R~
//#else                                                              //~v176I~//~va48R~
//    if (!ugetdiskfree((char)Sremovabledriveid,&udiskinfo))	//to chk drive ready//~v176R~//~va48R~
//#endif                                                             //~v176I~//~va48R~
    	break;                                                     //~v176I~
  }                                                                //~v176I~
#endif  //PRECHK                                                   //~v176R~
    return;                                                        //~v10kI~
}//mountreq                                                        //~v10kI~
                                                                   //~v10kI~
//**********************************************************************//~v10kI~
//* removable drive chk                                            //~v10kI~
//*parm1:drive letter                                              //~v10kI~
//*ret  :1:removable 0:not removable                               //~v10kI~
//**********************************************************************//~v10kI~
int drivechksub(char Pdriveletter)                                 //~v10kI~
{                                                                  //~v10kI~
	int rc;                                                        //~v176I~
//******************                                               //~v10kI~
#ifdef XFS_PRECHK                                                  //~v176I~
    Sremovabledriveid=Pdriveletter;                                //~v176I~
#endif                                                             //~v176I~
    if (Sremovablesw==2)        //force removable by parm req      //~v146I~
        return 2;                                                  //~v146I~
//#ifdef UNX                                                       //~v171R~
//	return 0;           //no support removable                     //~v171R~
//#else                                                            //~v171R~
//  return (ugetdrivetype(Pdriveletter,0)==0);	//no errmsg        //~v176R~
    rc=(ugetdrivetype(Pdriveletter,0)==0);	//no errmsg            //~v176I~
#ifdef XFS_PRECHK                                                  //~v176I~
    if (!rc)  //not removable                                      //~v176I~
	    Sremovabledriveid=0;                                       //~v176I~
#endif                                                             //~v176I~
    return rc;                                                     //~v176I~
//#endif                                                           //~v171R~
}//drivechksub                                                     //~v10kI~
                                                                   //~v10kI~
//**********************************************************************//~v10bI~
//* get disk free space                                            //~v10kR~
//* parm1:drive letter                                             //~v10kR~
//* parm1:output cluster size                                      //~v10kI~
//**********************************************************************//~v10bI~
//#ifdef UNX                                                         //~v140I~//~va48R~
long getfreespace(char *Pfnm,long *Ppclustersz)                    //~v140I~
//#else                                                              //~v140I~//~va48R~
//long getfreespace(char Pdriveletter,long *Ppclustersz)             //~v10kR~//~va48R~
//#endif                                                             //~v140I~//~va48R~
{                                                                  //~v10bI~
    UDISKINFO udiskinfo;                                           //~v10bR~
    int rc;                                                        //~v10bI~
    long clustersz,diskfreesz;                                     //~v10bI~
//****************                                                 //~v10bI~
//#ifdef UNX                                                         //~v140I~//~va48R~
    if (rc=(int)ugetdiskfree(Pfnm,&udiskinfo),rc)                  //~v140I~
    	uerrexit("ugetdiskfree failed for %s,rc=%d",0,Pfnm,rc);    //~v140I~
//#else                                                              //~v140I~//~va48R~
//  if (rc=(int)ugetdiskfree(Pdriveletter,&udiskinfo),rc)          //~v1.1R~//~va48R~
//  	uerrexit("ugetdiskfree failed for %c,rc=%d",0,Pdriveletter,rc);//~v10kR~//~va48R~
//#endif                                                             //~v140I~//~va48R~
    *Ppclustersz=                                                  //~v10kM~
    clustersz=(long)udiskinfo.bytes_per_sector*(long)udiskinfo.sectors_per_cluster;//~v10bI~
//printf ("clustersz=%08lx\n",clustersz);                          //~v10mR~
    diskfreesz=clustersz*(long)udiskinfo.avail_clusters;           //~v10bI~
//printf("freespace=%ld(%08lx)\n",diskfreesz,diskfreesz);          //~v1.1R~
	return diskfreesz;                                             //~v10kR~
}//getfreespace                                                    //~v10kR~
                                                                   //~v10eI~
//**********************************************************************
//* open file name
//* parm1:open file name                                           //~6831I~
//* parm2:open option                                              //~6831I~
//* parm3:msg sw 0:no opened msg,1:display opened msg,-1:return if open err//~6831I~
//* parm4:file type for mdos disk                                  //~v171I~
//**********************************************************************
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw,int Pfiletype)    //~v171R~
{
	FILE *file;
#ifdef UNX                                                         //~v171I~
    char *orgf=0;                                                  //~v171I~
#endif                                                             //~v171I~
//****************
#ifdef UNX                                                         //~v171I~
    if (MDOSDISKOK(Pfile))                                         //~v171I~
    {                                                              //~v171I~
    	orgf=Pfile;		//save for msg                             //~v171I~
        Pfile=unxalloctempf(Pfile,Popt,Pfiletype);                 //~v171R~
    }                                                              //~v171I~
#endif                                                             //~v171I~
	if (!(file=fopen(Pfile,Popt)))
    {                                                              //~va1jI~
    	if (Pmsgsw==-1)                                            //~6831I~
        {                                                          //~va95I~
            if (errno==EACCES||errno==EPERM)  //permission err     //~va95R~
				uerrexit("%s open failed rc=%d(%s)",0,             //~va95R~
						Pfile,errno,strerror(errno));              //~va95R~
        	return 0;                                              //~6831I~
        }                                                          //~va95I~
        else                                                       //~6831I~
			uerrexit("%s open failed rc=%d",0,                     //~v109R~
					Pfile,errno);                                  //~v109R~
    }                                                              //~va1jI~
	if (Pmsgsw==1)                                                 //~6831I~
    {                                                              //~va1jI~
//  	uerrmsg("%s opened.",0,Pfile);                             //~v10bR~
#ifdef UNX                                                         //~v171I~
	  if (orgf)                                                    //~v171I~
    	printf("%s (%s) opened.",orgf,Pfile);                      //~v171R~
      else                                                         //~v171I~
#endif                                                             //~v171I~
    	printf("%s opened.",Pfile);                                //~v10bI~
    }                                                              //~va1jI~
	return file;
}//openfile	
//**********************************************************************//~v171I~
//* close file for mdos copy required case                         //~v171I~
//* parm1:FILE *                                                   //~v171I~
//* parm2:filename                                                 //~v171I~
//* parm3:file type for mdos disk                                  //~v171I~
//* parm4:FDATE to recover time stamp                              //~v171I~
//* parm5:FTIME to recover time stamp                              //~v171I~
//**********************************************************************//~v171I~
void closefile(FILE *Pfh,char *Pfile,int Pfiletype,FDATE *Ppdate,FTIME *Pptime)//~v171R~
{                                                                  //~v171I~
#ifdef UNX                                                         //~v171I~
	char *pfnm;                                                    //~v171I~
    int rc;                                                        //~v171I~
#endif                                                             //~v171I~
//****************                                                 //~v171I~
    if (Pfiletype==FT_SUB)                                         //~v176I~
        if (!Sgathersw)                                            //~v176R~
            if (Sremovablesw)                                      //~v176R~
                printf("Closing %s ...\n",Pfile);                  //~v176R~
	fclose(Pfh);                                                   //~v171I~
#ifdef UNX                                                         //~v171I~
    if (MDOSDISKOK(Pfile))                                         //~v171M~
    {                                                              //~v171M~
        pfnm=Sunxtempfile[Pfiletype];                              //~v171R~
        if (Ppdate)                                                //~v171R~
        {                                                          //~v171R~
            if (usetftime(pfnm,*Ppdate,*Pptime))                   //~v171R~
                uerrexit("usetftime failed for %s (temp of %s)",0, //~v171R~
                            pfnm,Pfile);                           //~v171R~
        }                                                          //~v171R~
        if (Pfiletype!=FT_INDEX)                                   //~v175I~
        	printf("        Copying %s to %s...\n",pfnm,Pfile);    //~v175R~
    	rc=uxcopy(pfnm,Pfile,DCPY_EXISTING,FILE_NORMAL); //copy source file//~v171R~
        if (rc)                                                    //~v171I~
        	uerrexit("copy failed rc=%d.( %s to %s )",0,           //~v171R~
            	rc,pfnm,Pfile);                                    //~v171I~
        rc=uremove(pfnm);                                          //~v171I~
        if (rc)                                                    //~v171I~
        	uerrexit("temp file remove failed, rc=%d.( %s )",0,    //~v171R~
//          		pfnm);                                         //~v171I~//~va9sR~
            		rc,pfnm);                                      //~va9sI~
        return;                                                    //~v171I~
    }                                                              //~v171I~
#endif                                                             //~v171M~
    if (Ppdate)                                                    //~v171M~
    {                                                              //~v171M~
        if (usetftime(Pfile,*Ppdate,*Pptime))                      //~v171R~
        	uerrexit("usetftime failed for %s",0,                  //~v171M~
						Pfile);                                    //~v171M~
    }                                                              //~v171M~
    return;                                                        //~v171I~
}//closefile                                                       //~v171I~
#ifdef UNX                                                         //~v171I~
//**********************************************************************//~v171I~
//* allocate temp file for MDOS disk file                          //~v171I~
//* parm1:open file name                                           //~v171I~
//* parm2:open option                                              //~v171I~
//* parm3:filetype                                                 //~v171I~
//* ret  :static tempfile name ptr                                 //~v171I~
//**********************************************************************//~v171I~
char *unxalloctempf(char *Pfile,char *Popt,int Pfiletype)          //~v171R~
{                                                                  //~v171I~
static char Stempfile[_MAX_PATH];	//input copyed to temp         //~v171R~
    char tempfnm[_MAX_PATH],*fnm;                                  //~v171R~
	int rc;                                                        //~v171I~
//****************                                                 //~v171I~
	if (!*Sunxtempdir)                                             //~v171I~
    {                                                              //~v171I~
#ifdef LNX                                                         //~va1XI~
        rc=utempnamd("/tmp","xfs_",Sunxtempdir)==0;                //~va1XI~
#else                                                              //~va1XI~
        utempnam("/tmp","xfs_",Sunxtempdir);                       //~v171R~
    	rc=umkdir(Sunxtempdir);                                    //~v171I~
#endif                                                             //~va1XI~
        if (rc)                                                    //~v171I~
        	uerrexit("mkdir temp work dir(%s) failed rc=%d.",0,    //~v171I~
            	Sunxtempdir,rc);                                   //~v171I~
    }                                                              //~v171I~
    strcpy(tempfnm,Sunxtempdir);                                   //~v171R~
    strcat(tempfnm,DIR_SEPS);                                      //~v171R~
    strcat(tempfnm,Pfile+PATHLEN(Pfile));                          //~v171R~
    if (*Popt=='r')		//input	                                   //~v171I~
    {                                                              //~v171I~
        if (Pfiletype!=FT_INDEX)                                   //~v175I~
        	printf("        Copying %s to %s...\n",Pfile,tempfnm); //~v175R~
    	rc=uxcopy(Pfile,tempfnm,DCPY_EXISTING,FILE_NORMAL); //copy source file//~v171R~
        if (rc)                                                    //~v171I~
        	uerrexit("copy failed rc=%d.( %s to %s )",0,           //~v171R~
            	rc,Pfile,tempfnm);                                 //~v171R~
	    fnm=strcpy(Stempfile,tempfnm);//save to restore at close   //~v171R~
    }                                                              //~v171I~
    else                                                           //~v171I~
	    fnm=strcpy(Sunxtempfile[Pfiletype],tempfnm);//save to restore at close//~v171R~
	return fnm;                                                    //~v171R~
}//unxalloctempf(char *Pfile,char *Popt)                           //~v171I~
//**********************************************************************//~v171I~
//* clear tempdir                                                  //~v171I~
//* ret  :none                                                     //~v171I~
//**********************************************************************//~v171I~
void unxcleartempf(void)                                           //~v171I~
{                                                                  //~v171I~
	int procctr;                                                   //~v171I~
//****************                                                 //~v171I~
	if (*Sunxtempdir)                                              //~v171I~
//      uxdelete(Sunxtempdir,FILE_ALL,UXDELNOMSG+UXDELFORCE,&procctr,&procctr,&procctr);//~va20R~
        uxdelete(Sunxtempdir,UXDELDIR,UXDELNOMSG+UXDELFORCE,&procctr,&procctr,&procctr);//~va20I~
	return;                                                        //~v171I~
}//unxcleartempf                                                   //~v171I~
#endif                                                             //~v171I~
//**********************************************************************
//* get input up to the size                                       //~6831R~
//**********************************************************************
//char *getinput(long Preqsize,int *Poutlen,int *Pbreaksw)         //~va30R~
char *getinput(FILESZT Preqsize,int *Poutlen,FILESZT_S *Pbreaksw)  //~va30R~
{
//#define BINCHKSZ    100                                          //~v141R~
static long Sreslen=0;                                             //~va22R~
static int  Snextsw=0;                                             //~va22R~
static char *Saddr;                                                //~6831I~
static int S1stread=0;        //fisrt time sw                      //~va22R~
	char *pc,*pc0;                                                 //~v10lR~
    char *pce;                                                     //~v141I~
    char *pcprev;                                                  //~va1CR~
    char *pcendlinepos;                                            //~va1EI~
//  int  endlinectr,read1stsw=0;                                   //~va30R~
    int  read1stsw=0;                                              //~va30I~
    FILESZT_S  endlinectr;                                         //~va30I~
    int  multirecsw;  //start end line sw 1:start,-1:end,0:not splitter line//~va1CR~
    int  multireclen; //len for multirec search case               //~va1CR~
//  int ii;                                                        //~v123R~
    long len,len2,len0,len00;                                      //~v10lR~
//****************
    multirecsw=0;endlinectr=0;                                     //~va58I~
	if (!Sinpbuff)                                                 //~v10lI~
    {                                                              //~va1FI~
    	if (!(Sinpbuff=malloc(BUFFSZ)))                            //~v10lI~
        	uerrexit("malloc failed for buff,size=%d)",0,BUFFSZ);  //~v10lI~
        read1stsw=1;                                               //~va1FI~
    }                                                              //~va1FI~
                                                                   //~v10lI~
	if (Sgathersw)                                                 //~6831I~
    {                                                              //~6831I~
    	*Poutlen=(int)fread(Sinpbuff,1,BUFFSZ,Shsubf);	//read 1 block//~v10lR~
        pc=Sinpbuff;	//return addr                              //~6831I~
        if (*Poutlen<BUFFSZ)                                       //~v111I~
        	if (ferror(Shsubf))                                    //~v111I~
            	uerrexit("\nRead failed rc=%d",0,errno);           //~v131R~
    }                                                              //~6831I~
    else                                                           //~6831I~
    {                                                              //~6831I~
        if (Srecnosw && Smultirecid=='S')    //record separator is for start line//~va1FI~
        	Preqsize++;		//split by nest record start line      //~va1FI~
    	*Pbreaksw=0;                                               //~v108I~
    	if (!Sreslen)                                              //~6831R~
        {                                                          //~6831R~
       		Sreslen=(long)fread(Sinpbuff,1,BUFFSZ,Shorgf);	//read 1 block//~v10lR~
            if (Sreslen<BUFFSZ)                                    //~v111I~
                if (ferror(Shorgf))                                //~v111I~
                    uerrexit("\nRead failed rc=%d",0,errno);       //~v131R~
            if (!Sreslen)                                          //~6831R~
            {                                                      //~6831R~
            	*Poutlen=0;                                        //~6831R~
            	return 0;	                                       //~6831R~
    		}                                                      //~6831R~
//          *(Sinpbuff+Sreslen)=0;	//null term                    //~v10lR~
            Saddr=Sinpbuff;                                        //~6831R~
            if (!S1stread)	//1st time                             //~v107I~
            {                                                      //~v107I~
            	S1stread=1;                                        //~v107I~
//*chk binaly                                                      //~v107I~
//                if (!Sbintextsw)    //no parm specified          //~v124R~
//                {                                                //~v124R~
//                    if (Sreslen>4096)   //over 4096              //~v124R~
//                    {                                            //~v124R~
//                        for (pc=Sinpbuff,ii=0;pc<Sinpbuff+BINCHKSZ;pc++)//~v124R~
//                            if (*pc<0x20)                        //~v124R~
//                                ii++;                            //~v124R~
//                        if ((ii<<1)>BINCHKSZ)   //over 1/2       //~v124R~
//                            Sbinsw=1;                            //~v124R~
//                    }                                            //~v124R~
//                    if (Sbinsw)                                  //~v124R~
//                        uerrmsg("%s is Binaly file",0,Sorgfname);//~v124R~
//                    else                                         //~v124R~
//                        uerrmsg("%s is Text file",0,Sorgfname);  //~v124R~
//                }//no parm specified                             //~v124R~
            }//1st time                                            //~v107I~
    	}                                                          //~6831R~
//printf("reqlen=%08lx,reslen=%08lx\n",Preqsize,Sreslen);          //~v10sR~
    	if (Sbinsw)			//binaly file                          //~6831R~
    		*Poutlen=(int)min(Sreslen,Preqsize);                   //~6831R~
        else                                                       //~6831R~
        if (Slinenosw)	//split by line count                      //~v141I~
        {                                                          //~v141I~
            pcendlinepos=0; //end of record position               //~va1EI~
            for (pc=Saddr,pce=Saddr+Sreslen;;)                     //~v141R~
            {                                                      //~v141I~
//              len=(int)((ULONG)pce-(ULONG)pc);                   //~v141R~//~va66R~
                len=(int)((ULPTR)pce-(ULPTR)pc);                   //~va66I~
                pcprev=pc;                                         //~va1EI~
        		pc=memchr(pc,EOLID,(UINT)len);                     //~v142R~
                if (!pc)                                           //~v141I~
                {                                                  //~v141I~
//		            *Poutlen=Sreslen;	//assume all write at first//~v141I~//~vaa1R~
  		            *Poutlen=(int)Sreslen;	//assume all write at first//~vaa1I~
                	break;                                         //~v141I~
                }                                                  //~v141I~
                if (Smultirecid)    //multi line record splitter specified//~va1EI~
                {                                                  //~va1EI~
                    multirecsw=chkmultirec(pcprev,pc); //          //~va1EI~
                    if (multirecsw>0)   //start line               //~va1EI~
                    {                                              //~va1EI~
                        pcendlinepos=pcprev;    //next of prev line//~va1EI~
                        endlinectr=Preqsize;	//residual line count//~va1EI~
                    }                                              //~va1EI~
                    else                                           //~va1EI~
                    if (multirecsw<0)   //endof line               //~va1EI~
                    {                                              //~va1EI~
                        pcendlinepos=pc+1;      //next line top    //~va1EI~
                        endlinectr=Preqsize-1;	//residual line count//~va1EI~
                    }                                              //~va1EI~
                }                                                  //~va1EI~
                pc++;                                              //~v141I~
//              if (--Preqsize==0 || pc==pce)                      //~va1FR~
                if (!Srecnosw || multirecsw)                       //~va1FI~
                    Preqsize--;                                    //~va1FI~
                if (Preqsize==0 || pc==pce)                        //~va1FI~
                {                                                  //~v141I~
//                  *Poutlen=(int)((ULONG)pc-(ULONG)Saddr);        //~v141R~//~va66R~
                    *Poutlen=(int)((ULPTR)pc-(ULPTR)Saddr);        //~va66I~
                    break;                                         //~v141I~
                }                                                  //~v141I~
            }                                                      //~v141I~
          if (Smultirecid    //multi line record splitter specified//~va1EI~
          &&  !Preqsize)    //reached to split line count          //~va1EI~
          {                                                        //~va1EI~
                if (!pcendlinepos)  //no spliter found             //~va1EI~
                {                                                  //~va1EI~
                    printf("\n");   //cr for % msg                 //~va1EI~
                    uerrexit("no multiline separator matching line",0);//~va1FR~
                }                                                  //~va1EI~
//              *Poutlen=(int)((ULONG)pcendlinepos-(ULONG)Saddr);  //~va1EI~//~va66R~
                *Poutlen=(int)((ULPTR)pcendlinepos-(ULPTR)Saddr);  //~va66I~
	            *Pbreaksw=-endlinectr;		//minus output residual line count//~va1EI~
          }                                                        //~va1EI~
          else                                                     //~va1EI~
          if (Srecnosw    //split by recordno                      //~va1FI~
          &&  read1stsw   //one record should be in buffsz         //~va1FI~
          &&  !pcendlinepos) //no spliter found                    //~va1FR~
          {                                                        //~va1FI~
          	printf("\n");   //cr for % msg                         //~va1FI~
            uerrexit("no multiline separator matching line(record count mode)",0);//~va1FI~
          }                                                        //~va1FI~
          else                                                     //~va1FI~
            *Pbreaksw=Preqsize;		//output residual line count   //~v141I~
        }//split by line count                                     //~v141I~
        else                                                       //~v141I~
    //for text file,search cr+lf                                   //~6831R~
            if (Snextsw)				//search next crlf         //~6831R~
            {                                                      //~6831R~
//              len=min(Sreslen,Preqsize);                         //~va30R~
                len=(long)min(Sreslen,Preqsize);                   //~va30I~
                len0=len;                                          //~va1DI~
                pcprev=0;                                          //~va1CR~
                multirecsw=0;                                      //~va1CR~
                pcprev=Saddr;                                      //~va1CR~
              for (;;)                                             //~va1CR~
              {                                                    //~va1CR~
//      		pc=memchr(Saddr,0x0d,(UINT)len);                   //~v142R~
//      		pc=memchr(Saddr,EOLID,(UINT)len);                  //~va1CR~
        		pc=memchr(pcprev,EOLID,(UINT)len);                 //~va1CR~
//              if (pc                                             //~v142R~
//              && 	((len2=(int)((ULONG)(pc+2)-(ULONG)Saddr))>=2)  //~v142R~
//  			&& *(pc+1)==0x0a)                                  //~v142R~
//              	*Poutlen=len-len2+2;                           //~v142R~
                if (pc)                                            //~v142I~
//                	*Poutlen=(int)((ULONG)(pc+1)-(ULONG)Saddr);    //~v142R~//~va66R~
                	*Poutlen=(int)((ULPTR)(pc+1)-(ULPTR)Saddr);    //~va66I~
                else                                               //~6831R~
                {                                                  //~v10lI~
                  if (!Smultirecid)                                //~va1CI~
                    uerrmsg("line split occured",0);               //~v123R~
//              	*Poutlen=Sreslen;                              //~6831R~//~vaa1R~
                	*Poutlen=(int)Sreslen;                         //~vaa1I~
                    break;                                         //~va1CR~
                }                                                  //~v10lI~
                if (!Smultirecid)                                  //~va1CR~
                	break;                                         //~va1CR~
                if (pcprev!=Saddr)//not 1st time                   //~va1CR~
                {                                                  //~va1CR~
                    multirecsw=chkmultirec(pcprev,pc); //          //~va1CR~
                    if (multirecsw>0)   //start line               //~va1CR~
                    {                                              //~va1CR~
//                		*Poutlen=(int)((ULONG)pcprev-(ULONG)Saddr);//~va1CR~//~va66R~
                		*Poutlen=(int)((ULPTR)pcprev-(ULPTR)Saddr);//~va66I~
                        break;                                     //~va1CR~
                    }                                              //~va1CR~
                    if (multirecsw<0)   //end line                 //~va1CR~
                    {                                              //~va1CR~
//                		*Poutlen=(int)((ULONG)(pc+1)-(ULONG)Saddr);//~va1CR~//~va66R~
                		*Poutlen=(int)((ULPTR)(pc+1)-(ULPTR)Saddr);//~va66I~
                        break;                                     //~va1CR~
                    }                                              //~va1CR~
                }                                                  //~va1CR~
              	pcprev=pc+1; //line start addr                     //~va1CR~
                len=len0-*Poutlen;                                 //~va1DI~
              }//for multiline terminater                          //~va1CR~
                if (Smultirecid)                                   //~va1DI~
                {                                                  //~va1DI~
                	if (!multirecsw)	//string not found         //~va1DI~
                    {                                              //~va1CI~
                    	printf("\n");	//cr for % msg             //~va1CI~
//                 		uerrexit("no multiline separator matching line",0);//~va22R~
                   		uerrmsg("no multiline separator matching line in read buff size",0);//~va22I~
                    }                                              //~va1CI~
                }                                                  //~va1DI~
                if (Smultirecid && !multirecsw)	//string not found //~va22I~
//                  *Poutlen=len0;                                 //~va22I~//~vaa1R~
                    *Poutlen=(int)len0;                            //~vaa1I~
                else                                               //~va22I~
                {                                                  //~va22I~
                *Pbreaksw=1;    //sw to next output file           //~v10lI~
                Snextsw=0;                                         //~v10lI~
                }                                                  //~va22I~
            }                                                      //~6831R~
            else						//not search last case from prev last rec//~6831R~
//          	if (Sreslen>Preqsize)		//last output for the file//~v10aR~
//          	if (Preqsize<BUFFSZ+CRLFCHKSZ)	//confirm 4k before limit//~v10pR~
            	if (Preqsize<Sreslen+CRLFCHKSZ)	//confirm 4k before limit//~v10pR~
                {                                                  //~6831R~
//*chk reverse for cr+lf                                           //~v10aI~
                  	pc=Saddr;                                      //~v10lI~
//	                len00=len=min(Sreslen,Preqsize);               //~va30R~
  	                len00=len=(long)min(Sreslen,Preqsize);         //~va30I~
                    if (len>CRLFBACKSZ)                            //~v10lI~
                    {                                              //~v10lI~
                        pc+=len-CRLFBACKSZ;                        //~v10lI~
                        len=CRLFBACKSZ;                            //~v10lI~
                    }                                              //~v10lI~
//printf("len00=%08x,len=%08x\n",len00,len);                       //~v10qR~
					pc0=pc;		//start addr                       //~v10lI~
                    len0=len;                                      //~v10lI~
                    pcprev=0;                                      //~va1CR~
                    multirecsw=0;                                  //~va1CR~
                    multireclen=0;                                 //~va1CR~
                  	for (len2=0;len;)                              //~v10lR~
                  	{                                              //~v10aI~
//          			pc=memchr(pc,0x0d,(UINT)len);	//search reverse//~v142R~
            			pc=memchr(pc,EOLID,(UINT)len);	//search reverse//~v142I~
                    	if (!pc)	//not found,search forward     //~v10aI~
                    		break;                                 //~v10aI~
                        if (pcprev && Smultirecid)                 //~va1CR~
                        {                                          //~va1CR~
                            multirecsw=chkmultirec(pcprev,pc); //  //~va1CR~
                            if (multirecsw>0)	//start line       //~va1CR~
//                          	multireclen=len2;                  //~va1CR~//~vaa1R~
                            	multireclen=(int)len2;             //~vaa1I~
                        }                                          //~va1CR~
                        pc++;                                      //~v10aI~
                        pcprev=pc; //line start addr               //~va1CR~
//                    	len=len0-(int)((ULONG)pc-(ULONG)pc0);      //~v10lR~//~va66R~
                    	len=len0-(int)((ULPTR)pc-(ULPTR)pc0);      //~va66I~
//                  	if (len>0 && *pc==0x0a)	//0d+0a            //~v142R~
//                      	len2=len-1;		//next of last crlf    //~v142R~
                        len2=len;		//eol found id             //~v142I~
                        if (multirecsw<0)   //previously endline found//~va1CR~
//                          multireclen=len2;                      //~va1CR~//~vaa1R~
                            multireclen=(int)len2;                 //~vaa1I~
                  	}//search backward                             //~v10aI~
                  if (Smultirecid && !multireclen)    //multiline string not found//~va1CR~
                  {                                                //~va1CR~
                      if (Sreslen>=Preqsize)  //next record is out of range//~va1CR~
//                        *Poutlen=Preqsize;                       //~va30R~
                          *Poutlen=(int)Preqsize;                  //~va30I~
                      else                                         //~va1CR~
                          *Poutlen=(int)Sreslen;                   //~va1CR~
                      Snextsw=1;                                   //~va1CR~
                  }                                                //~va1CR~
                  else                                             //~va1CR~
                  {                                                //~va1CR~
                  	if (Smultirecid)                               //~va1CI~
						len2=multireclen;                          //~va1CI~
                  	if (len2)	//found                            //~v10lR~
                  	{                                              //~v10lR~
//                  	*Poutlen=len00-len2;                       //~v10lR~//~vaa1R~
                    	*Poutlen=(int)(len00-len2);                //~vaa1I~
                    	*Pbreaksw=1;	//sw to next output file   //~v10lR~
				  	}                                              //~v10lR~
				  	else                                           //~v10lR~
                  	{                                              //~v10lR~
                   		if (Sreslen>=Preqsize)	//next record is out of range//~v10lI~
				   		{	                                       //~v10lI~
                        	uerrmsg("line split occued",0);        //~v10lI~
//                  		*Poutlen=Preqsize;                     //~va30R~
                    		*Poutlen=(int)Preqsize;                //~va30I~
                    		*Pbreaksw=1;	//sw to next output file//~v10lI~
                   		}                                          //~v10lI~
                        else                                       //~v10lI~
                        {                                          //~v10lI~
                        	Snextsw=1;                             //~v10lI~
		                    *Poutlen=(int)Sreslen;                 //~v10lI~
						}                                          //~v10lI~
                  	}//no crlf in reverse                          //~v10lR~
//printf("len2=%08x,outlen=%08x\n",len2,*Poutlen);                 //~v10qR~
                  }//multiline,no splitter string found            //~va1CR~
        		}                                                  //~6831R~
        		else					//not last                 //~6831R~
                    *Poutlen=(int)Sreslen;                         //~6901R~
                                                                   //~6831R~
        Sreslen-=*Poutlen;                                         //~6831R~
        pc=Saddr;                                                  //~6831R~
    	Saddr+=*Poutlen;                                           //~6831R~
	}//split                                                       //~6831I~
	return pc;                                                     //~6831R~
}//getinput                                                        //~6831R~
//**********************************************************************//~va1CR~
//* chk line is start/end of multiple line record                  //~va1CR~
//*rc: 1:top of multi-line,-1:end of multi-line,0 none of both     //~va1CR~
//**********************************************************************//~va1CR~
int chkmultirec(char *Ptol,char *Peol)                             //~va1CR~
{                                                                  //~va1CR~
	int len,offs,offse;                                            //~va1CR~
//****************                                                 //~va1CR~
    if (*(Peol-1)==0x0d)   //0d0a                                  //~va1DR~
        Peol--;                                                    //~va1DI~
//	len=(int)((ULONG)Peol-(ULONG)Ptol);                            //~va1CR~//~va66R~
	len=(int)((ULPTR)Peol-(ULPTR)Ptol);                            //~va66I~
    if (Smultirecoffsid=='+')                                      //~va1CR~
    	offs=Smultirecoffs;                                        //~va1CR~
    else                                                           //~va1CR~
    	if (Smultirecoffs)                                         //~va1DI~
	    	offs=len-Smultirecoffs;                                //~va1DI~
        else                                                       //~va1DI~
	    	offs=len-Smultirecstrlen;                              //~va1DI~
    offse=offs+Smultirecstrlen;                                    //~va1CR~
    if (offs<0||offse>len)                                         //~va1DR~
    	return 0;		//str cannot be contained                  //~va1CR~
    if (memcmp(Ptol+offs,Smultirecstr,(UINT)Smultirecstrlen))	//unmatch//~va1CR~
    	return 0;                                                  //~va1CR~
    if (Smultirecid=='S')	//strat line                           //~va1CR~
    	return 1;                                                  //~va1CR~
    return -1;				//end line                             //~va1CR~
}//chkmultirec                                                     //~va1CR~
//**********************************************************************
//* put 1 byte to output 
//**********************************************************************
void putoutput(char *Pfname,FILE *Phfile,char *Paddr,int Plen)     //~6831R~
{
	int len;                                                       //~6831R~
//****************
//printf("putoutput ctr=%d,len=%d(%08x)\n",++ctr,Plen,Plen);       //~v1.1R~
	len=(int)fwrite(Paddr,1,(UINT)Plen,Phfile);                  //~6831R~//~6831R~
//printf("putoutput written=%d(%08x)\n",len,len);                  //~v1.1R~
	if (len!=Plen)                                                 //~6831R~//~6831R~
		uerrexit("\n%s write failed(rc=%d,req=%08lx,written=%08lx)",0,//~v131R~
				Pfname,errno,Plen,len);                            //~v131I~
	return;
}//putoutput                                                       //~v111R~

//**********************************************************************//~v10qI~
//*pgm copy                                                        //~v10qI~
//**********************************************************************//~v10qI~
void pgmcopy(void)                                                 //~v10qR~
{                                                                  //~v10qI~
    char dirnm[_MAX_PATH];                                         //~v10qI~
    int pathlen,rc;                                                //~v10qR~
//**************:                                                  //~v10qI~
    strcpy(dirnm,Sindexfnm);                                       //~v10qI~
    pathlen=PATHLEN(dirnm);                                        //~v10qI~
    strcpy(dirnm+pathlen,Spgmnm+PATHLEN(Spgmnm));                  //~v10qR~
    rc=uxcopy(Spgmnm,dirnm,DCPY_EXISTING,0);                       //~v10qR~
//printf("copy rc=%d,pgm=%s,target dir=%s\n",rc,Spgmnm,dirnm);     //~v10qR~
    if (rc)                                                        //~v10qI~
    	uerrexit("pgm copy failed,%s to %s",0,                     //~v10qR~
                Spgmnm,dirnm);                                     //~v10qR~
	uerrmsg("%s is copyed from %s to %s",                          //~v10qI~
	        "%s を複写しました( %s から %s へ)",                   //~v10qI~
            PGM,Spgmnm,dirnm);	                                   //~v10qI~
//printf("copyed\n");                                              //~v10qR~
	return;                                                        //~v10qI~
}//pgmcopy                                                         //~v10qI~
                                                                   //~v111I~
//**********************************************************************//~v111I~
//*verify read                                                     //~v121R~
//*parm1:subfilename                                               //~v127I~
//*parm2:subfile size                                              //~v127I~
//*parm3:offset in org file                                        //~v127I~
//*parm4:chksum of subfile to be verify                            //~v127I~
//**********************************************************************//~v111I~
//int readverify(UCHAR *Psubfnm,long Ptotlen)                      //~v127R~
//int readverify(UCHAR *Psubfnm,long Ptotlen,ULONG Poffs,ULONG Pchksum,int Psubfno)//~va30R~
int readverify(UCHAR *Psubfnm,FILESZT Ptotlen,FILESZT Poffs,ULONG Pchksum,int Psubfno)//~va30R~
{                                                                  //~v121R~
    FILE *vfh;                                                     //~v121R~
//  long readlen,totlen;                                           //~va30R~
    long readlen;                                                  //~va30I~
    FILESZT totlen;                                                //~va30I~
    int percent;                                                   //~v121R~
    ULONG chksums=0;                                               //~v127R~
static char *Svrfbuff=0;	//with null term                       //~va22R~
	int breaksw;                                                   //~v135I~
    char editwkn[32],editwkn2[32];                                 //~va30R~
//**************:                                                  //~v121R~
	if (!Sverifysw)     	//no parm                              //~v123R~
		return 0;                                                  //~v123R~
	if (!Svrfbuff)                                                 //~v123I~
    	if (!(Svrfbuff=malloc(BUFFSZ)))                            //~v123I~
        	uerrexit("malloc failed for verify read buff,size=%d)",0,BUFFSZ);//~v123I~
                                                                   //~v123I~
//  printf("No %d,verify start...00 %%        (Esc key to break verify)",Psubfno);//~v175R~
//  fflush(stdout);                                                //~v175R~
    printf("No %d,verify process\n",Psubfno);                      //~v175I~
    vfh=openfile(Psubfnm,"rb",0,FT_SUB);  //no open msg            //~v171R~
    printf("No %d,verify start...00 %%        (Esc key to break verify)",Psubfno);//~v175I~
    breaksw=0;                                                     //~v135I~
    for (totlen=0;;)                                               //~v121R~
    {                                                              //~v121R~
    	readlen=(long)fread(Svrfbuff,1,BUFFSZ,vfh);	//read 1 block //~v123R~
        if (readlen<BUFFSZ)                                        //~v121R~
        	if (ferror(vfh))                                       //~v121R~
            	uerrexit("\nRead failed rc=%d",0,errno);           //~v131R~
//  	chksums=uchksum(Svrfbuff,(ULONG)Poffs+totlen,(ULONG)readlen,chksums);//~va30R~
    	chksums=uchksum(Svrfbuff,(ULONG)(Poffs+totlen),(ULONG)readlen,chksums);//~va30I~
		totlen+=readlen;                                           //~v121R~
	    percent=calcpercent(totlen,Ptotlen);                       //~v121R~
	    printf("\rNo %d,verify start...%02d %% read",Psubfno,percent);//~v131R~
        fflush(stdout);                                            //~v121R~
        if (readlen<BUFFSZ)                                        //~v121R~
            break;                                                 //~v121R~
        if (kbdchk("\x1b"))                                        //~v135R~
        {                                                          //~v135I~
        	printf("\nNo %d,veryfy stopped by Esc key,continue to next disk\n",//~v131R~
					Psubfno);                                      //~v135I~
            breaksw=1;        	                                   //~v135I~
            break;                                                 //~v135I~
        }                                                          //~v135I~
    }                                                              //~v121R~
  if (!breaksw)		                                               //~v135I~
  {                                                                //~v135I~
    if (totlen!=Ptotlen)                                           //~v123I~
    {                                                              //~v123I~
//      printf("\nNo %d,veryfy failed readlen=%08ld,writelen=%08ld\n",//~va30R~
//  			Psubfno,totlen,Ptotlen);                           //~va30R~
        xffeditfszz(totlen,editwkn);                               //~va30R~
        xffeditfszz(Ptotlen,editwkn2);                             //~va30R~
        printf("\nNo %d,veryfy failed readlen=%s,writelen=%s\n",   //~va30I~
    			Psubfno,editwkn,editwkn2);                         //~va30I~
        exit(8);                                                   //~v123I~
    }                                                              //~v123I~
    if (chksums!=Pchksum)                                          //~v127R~
    {                                                              //~v127I~
//      printf("\nNo %d,veryfy failed by chksum errr offset=%08lx,len=%08lx\n",//~va30R~
//  			Psubfno,Poffs,Ptotlen);                            //~va30R~
        xffeditfszx(Poffs,editwkn);                                //~va30R~
        xffeditfszx(Ptotlen,editwkn2);                             //~va30R~
        printf("\nNo %d,veryfy failed by chksum errr offset=%s,len=%s\n",//~va30I~
    			Psubfno,editwkn,editwkn2);                         //~va30I~
    	chksumerr(3,Psubfno,Pchksum,chksums);                      //~v127R~
    }                                                              //~v127I~
	printf("\rNo %d,verify end      %02d %% read\n",Psubfno,100);  //~v131R~
    fflush(stdout);                                                //~v123I~
  }//not break by esc                                              //~v135I~
    fclose(vfh);                                                   //~v171R~
	return 0;                                                      //~v121R~
}//readverify                                                      //~v121R~
//**********************************************************************//~v111I~
//*calc percent   p1*100/p2                                        //~v121R~
//ret:-1 if err                                                    //~v121R~
//**********************************************************************//~v111I~
//SHORT calcpercent(long Plong1,long Plong2)                       //~va30R~
SHORT calcpercent(FILESZT Plong1,FILESZT Plong2)                   //~va30I~
{                                                                  //~v121R~
//static long Smaxlong=(0x7fffffff/100);                           //~va30R~
static FILESZT Smaxlong=(FILESZ_MAX/100);                          //~va30R~
//	long tmp;                                                      //~va30R~
  	FILESZT tmp;                                                   //~va30I~
//**************:                                                  //~v121R~
    if (!Plong2)                                                   //~v121R~
    {                                                              //~va1jI~
      if (Plong1)                                                  //~v172I~
    	return -1;                                                 //~v121R~
      else                                                         //~v172I~
    	return 100;                                                //~v172I~
    }                                                              //~va1jI~
	if (Plong1<Smaxlong)                                           //~v121R~
    {                                                              //~v121R~
    	tmp=(Plong1*100)/Plong2;                                   //~v121R~
//printf("percent=%ld= %ld/%ld\n",tmp,Plong1,Plong2);              //~v123R~
//      if ((ULONG)tmp>>16)                                        //~va30R~
        if (tmp>>16)                                               //~va30I~
        	return -1;                                             //~v121R~
		return (SHORT)tmp;                                         //~v121R~
	}                                                              //~v121R~
	if (Plong1<100)		//over max,result is overflow              //~v121R~
		return -1;                                                 //~v121R~
    tmp=Plong1/(Plong2/100);                                       //~v121R~
//printf("percent2=%ld= %ld/%ld\n",tmp,Plong1,Plong2);             //~v123R~
//  if ((ULONG)tmp>>16)                                            //~va30R~
    if (tmp>>16)                                                   //~va30I~
        return -1;                                                 //~v121R~
    return (SHORT)tmp;                                             //~v121R~
}//calcpercent                                                     //~v121R~
//**********************************************************************//~v127I~
//*chksum err at gather                                            //~v127I~
//parm1:1:start chksumerr,2:subfile chksumerr,3:verify err,4:index file get err//~v127R~
//parm2:subfile seqno                                              //~v127R~
//parm3:chksum in index file                                       //~v127I~
//parm4:chksum from subfile                                        //~v127R~
//**********************************************************************//~v127I~
void chksumerr(int Pcase,int Psubfno,ULONG Pchksumi,ULONG Pchksums)//~v127R~
{                                                                  //~v127I~
    char confmsg[256];                                             //~v127I~
//**************:                                                  //~v127I~
	switch(Pcase)                                                  //~v127I~
    {                                                              //~v127I~
    case 1:                                                        //~v127I~
		if (!Sdbcssw)                                              //~v127I~
            sprintf(confmsg,"No %d subfile start chksum err,\
from index file=%08lx,from subfile=%08lx\n\
continue(Y) or cancel(Esc)?",                                      //~v131R~
					Psubfno,Pchksumi,Pchksums);                    //~v127R~
        else                                                       //~v127I~
            sprintf(confmsg,"No %d サブファイルの開始チェックサムエラー,\
indexfile=%08lx,subfile calc=%08lx\n\
処理続行(Y)?,取消(Esc)?",                                          //~v131R~
					Psubfno,Pchksumi,Pchksums);                    //~v127R~
		break;                                                     //~v127I~
    case 2:                                                        //~v127I~
		if (!Sdbcssw)                                              //~v127I~
            sprintf(confmsg,"No %d subfile chksum err,\
from index file=%08lx,from subfile=%08lx\n\
continue(Y) or cancel(Esc)?",                                      //~v131R~
					Psubfno,Pchksumi,Pchksums);                    //~v127R~
        else                                                       //~v127I~
            sprintf(confmsg,"No %d サブファイルのチェックサムエラー,\
indexfile=%08lx,subfile calc=%08lx\n\
処理続行(Y)?,取消(Esc)?",                                          //~v131R~
					Psubfno,Pchksumi,Pchksums);                    //~v127R~
		break;                                                     //~v127I~
    case 3:                                                        //~v127I~
		if (!Sdbcssw)                                              //~v127I~
            sprintf(confmsg,"No %d subfile chksum err at read verify,\
from index file=%08lx,from subfile=%08lx\n\
continue(Y) or cancel(Esc)?",                                      //~v131R~
					Psubfno,Pchksumi,Pchksums);                    //~v127R~
        else                                                       //~v127I~
            sprintf(confmsg,"No %d サブファイルのベリファイチェックサムエラー,\
at write=%08lx,at verify=%08lx\n\
処理続行(Y)?,取消(Esc)?",                                          //~v131R~
					Psubfno,Pchksumi,Pchksums);                    //~v127R~
		break;                                                     //~v127I~
    case 4:                                                        //~v127I~
		if (!Sdbcssw)                                              //~v127I~
            sprintf(confmsg,"checksum on indexfile get failed,\n\
continue(Y) or cancel(Esc)?");                                     //~v131R~
        else                                                       //~v127I~
            sprintf(confmsg,"インデックスファイルからのチェックサム取得失敗,\n\
処理続行(Y)?,取消(Esc)?");                                         //~v131R~
		break;                                                     //~v127I~
	}                                                              //~v127I~
//  confirm(confmsg,confmsg,"YyNn");                               //~v130R~
    confirm(confmsg,confmsg,"Yy\x1b");                             //~v131R~
    return;                                                        //~v127I~
}//chksumerr                                                       //~va30R~
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
	PUDIRLIST pudirlist;                                           //~v10lI~
    FILEFINDBUF3 fstat3;                                           //~v10rI~
  	char ch,*cptr,*pc,*pc2;         //char ptr work                //~6831R~
    char *fnm;                                                     //~v10kI~
  	int parmno; //parm count work                                  //~v105R~
  	int posparmno=0; //parm count work                             //~6831R~
    int ii,jj;                                                     //~v10kR~
    int fno;                                                       //~v10lI~
    int sizepostfix;                                               //~va1DI~
    int pathlen;                                                   //~v10jI~
    int rmvchksw;                                                  //~v10kI~
    int drvno;                                                     //~v132I~
    int parmverifyreq=0;     //implicit verify req                 //~v144I~
    int parmmovable=0;       //implicit verify req                 //~v146I~
#ifdef UNX                                                         //~v171I~
    int rootpathsw;                                                //~v171I~
#endif                                                             //~v171I~
    char fullpath[_MAX_PATH];                                      //~v10kR~
//  char hexedit1[4];                                              //~v10kI~
//  char hexedit2[4];                                              //~v104R~
static char *Sindexfid=INDEXFID;                                   //~6901R~
//*************************
  	if (parmc<2 || *parmp[1]=='?')                                 //~6831R~
  	{                                                              //~6831R~
    	help();                                                    //~6831R~
    	exit(4);                                                   //~6831R~
  	}                                                              //~6831R~
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)                           //~6831R~
	{                                                              //~6831R~
  		cptr=parmp[parmno];                                        //~6831R~
#ifdef UNX                                                         //~v140I~
  		if(*cptr=='-')                                             //~v140I~
#else                                                              //~v140I~
  		if(*cptr=='/'||*cptr=='-')                                 //~6831R~
#endif                                                             //~v140I~
  		{//option                                                  //~6831R~
    		ch=*(++cptr);                      //first option byte //~6831R~
    		switch(toupper(ch))             //option               //~6831R~
    		{                                                      //~6831R~
    		case '?':                                              //~v10oI~
        		help();                                            //~v10oI~
        		exit(8);                                           //~v10oI~
                break;                                             //~v10oI~
    		case '#':      //  /#                                  //~v131R~
                cptr++;                                            //~v131I~
            	jj=0;		//err sw                               //~v131I~
            	ii=(int)strlen(cptr);                              //~v131R~
                if (ii && *(cptr+ii-1)=='-' && !*(cptr+ii))        //~v131R~
                {                                                  //~v131I~
	        		Srestartdrivesw=2;	//all drive after          //~v131R~
                    ii--;                                          //~v131I~
				}                                                  //~v131I~
                else                                               //~v131I~
	        		Srestartdrivesw=1;	//all drive after          //~v131R~
                if (ii!=unumlen(cptr,0,ii))	//numeric err          //~v131I~
                	jj=1;		//err                              //~v131I~
                Srestartdriveno=uatoin(cptr,ii);	               //~v131I~
                if (!Srestartdriveno                               //~v131R~
                ||	(Srestartdriveno==1 && Srestartdrivesw==2))    //~v131R~
                	jj=1;                                          //~v131I~
                if (jj)                                            //~v131R~
	      			uerrexit("restart/retry disk# parm err(%s)",0, //~v133R~
								parmp[parmno]);                    //~v131I~
                break;                                             //~v131I~
//  		case 'B':                                              //~v129R~
//      		Sbinsw=1;                                          //~v129R~
//      		Sbintextsw=1;				//force                //~v124R~
//              break;                                             //~v129R~
    		case 'P':                                              //~v10qR~
                cptr++;                                            //~v10qI~
                if (!*cptr)                                        //~v10qI~
                {                                                  //~v10qI~
                	if (uexecchk(parmp[0],fullpath)!=2)	           //~v10qR~
	    				uerrexit("%s.exe search failed,specify fullpath name",0,//~v10qR~
									PGM);                          //~v10qR~
				}                                                  //~v10qI~
                else                                               //~v10qI~
                {                                                  //~v10qI~
			    	if (!ufullpath(fullpath,cptr,sizeof(fullpath)))//~v10qR~
	    				uerrexit("copy pgm parm err(%s)",0,        //~v10qR~
									cptr-2);                       //~v10qR~
				}                                                  //~v10qI~
            	strcpy(Spgmnm,fullpath);                           //~v10qR~
                break;                                             //~v10qI~
    		case 'R':                                              //~v10jI~
        		Sgathersw=1;                                       //~v10jI~
                break;                                             //~v10jI~
    		case 'S':                                              //~va1CR~
    	    	Sbinsw=0;   //text mode                            //~va1CR~
                cptr++;                                            //~va1CR~
//                Smultirecid=toupper(*cptr);                      //~va21R~
//                switch(Smultirecid)                              //~va21R~
//                {                                                //~va21R~
//                case 'S':                                        //~va21R~
//                case 'E':                                        //~va21R~
//                    break;                                       //~va21R~
//                default:                                         //~va21R~
//                    uerrexit("multiline record split parm err(%s)",0,//~va21R~
//                                cptr-1);                         //~va21R~
//                }                                                //~va21R~
//                cptr++;                                          //~va21R~
                Smultirecoffsid=*cptr;                             //~va1CR~
                switch(Smultirecoffsid)                            //~va1CR~
                {                                                  //~va1CR~
                case '-':                                          //~va1CR~
                case '+':                                          //~va1CR~
                    cptr++;                                        //~va1CR~
                    break;                                         //~va1CR~
                default:                                           //~va1CR~
                    Smultirecoffsid='+';                           //~va1CR~
                }                                                  //~va1CR~
                Smultirecoffs=atoi(cptr);                          //~va1CR~
                cptr+=unumlen(cptr,0,(int)strlen(cptr));           //~va1FR~
                Smultirecid=toupper(*cptr);                        //~va21R~
                switch(Smultirecid)                                //~va21R~
                {                                                  //~va21R~
                case 'S':                                          //~va21R~
                case 'E':                                          //~va21R~
                    break;                                         //~va21R~
                default:                                           //~va21R~
                    uerrexit("multiline record split parm err(%s)",0,//~va21R~
                                cptr-1);                           //~va21R~
                }                                                  //~va21R~
                cptr++;                                            //~va21R~
                Smultirecstr=cptr;                                 //~va1CR~
                Smultirecstrlen=(int)strlen(Smultirecstr);         //~va1FR~
                if (!Smultirecstrlen)                              //~va1CR~
	      			uerrexit("multiline record split parm err(%s)",0,//~va1CR~
								parmp[parmno]);                    //~va1CR~
                if (Smultirecoffs)              //column           //~va1DI~
                    if (Smultirecoffsid=='+')                      //~va1DI~
	                	Smultirecoffs--;	//offset               //~va1DR~
                break;                                             //~va1CR~
//  		case 'T':                                              //~v129R~
//      		Sbinsw=0;                                          //~v129R~
//      		Sbintextsw=1;				//force                //~v124R~
//              break;                                             //~v129R~
    		case 'Y':                                              //~v10jI~
        	  while(ch=*(++cptr),ch)                               //~v127R~
              {                                                    //~v127I~
    			switch(toupper(ch))             //option           //~v10jI~
                {                                                  //~v10jI~
                case '9':                                          //~v10jR~
                	Sdbcssw=1;                                     //~v10jI~
                    UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v111I~
                    UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs     //~v111I~
                	break;                                         //~v10jI~
                case 'D':   //delete no confirm                    //~v127I~
                    Sdelysw=1;                                     //~v127I~
                	break;                                         //~v127I~
                case 'L':   //size by lineno                       //~v141I~
                    Slinenosw=1;                                   //~v141I~
    	    		Sbinsw=0;                                      //~v145R~
                	break;                                         //~v141I~
                case 'M':   //size by lineno                       //~v146I~
                    parmmovable=1;                                 //~v146I~
                	break;                                         //~v146I~
                case 'R':   //size by record                       //~va1FI~
                    Slinenosw=1;                                   //~va1FI~
                    Srecnosw=1;                                    //~va1FI~
    	    		Sbinsw=0;                                      //~va1FI~
                	break;                                         //~va1FI~
                case 'T':   //text option                          //~v129I~
    	    		Sbinsw=0;                                      //~v129I~
                	break;                                         //~v129I~
                case 'V':   //verify                               //~v121R~
                    Sverifysw=1;                                   //~v121R~
            		parmverifyreq=1;     //explicit verify req     //~v144I~
                	break;                                         //~v121R~
 		   		default	:                           //not option   //~v10jI~
	      			uerrexit("undefined option parm(%s)",0,        //~v10jI~
								parmp[parmno]);                    //~v10jI~
                }                                                  //~v10jI~
              }                                                    //~v127I~
                break;                                             //~v10jI~
    		case 'N':                                              //~v10jI~
        	  while(ch=*(++cptr),ch)                               //~v127R~
              {                                                    //~v127I~
    			switch(toupper(ch))             //option           //~v10jI~
                {                                                  //~v10jI~
                case '9':                                          //~v10jR~
                	Sdbcssw=0;                                     //~v10jI~
                    UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v111I~
                    UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs    //~v111I~
                	break;                                         //~v10jI~
                case 'D':   //delete no confirm                    //~v127I~
                    Sdelysw=0;                                     //~v127I~
                	break;                                         //~v127I~
                case 'L':   //size by lineno                       //~v141I~
                    Slinenosw=0;                                   //~v141I~
                	break;                                         //~v141I~
                case 'M':   //size by lineno                       //~v146I~
                    parmmovable=0;                                 //~v146I~
                	break;                                         //~v146I~
                case 'R':   //size by record no                    //~va1FI~
                    Srecnosw=0;                                    //~va1FI~
                	break;                                         //~va1FI~
                case 'T':   //text option                          //~v129I~
    	    		Sbinsw=1;                                      //~v129I~
                	break;                                         //~v129I~
                case 'V':   //verify                               //~v121R~
                    Sverifysw=0;                                   //~v123R~
            		parmverifyreq=1;     //explicit verify req     //~v144I~
                	break;                                         //~v121R~
 		   		default	:                           //not option   //~v10jI~
	      			uerrexit("undefined option parm(%s)",0,        //~v10jI~
								parmp[parmno]);                    //~v10jI~
                }                                                  //~v10jI~
              }                                                    //~v127I~
                break;                                             //~v10jI~
    		default	:                           //not option       //~6831R~
      			uerrexit("undefined option parm(%s)",0,            //~6831R~
							parmp[parmno]);                        //~6831I~
            }//sw                                                  //~6831I~
    	}//flag                                                    //~6831R~
      	else                                                       //~6831R~
      	{//positional parmno                                       //~6831R~
        	posparmno++;                                           //~6831R~
        	switch (posparmno)                                     //~6831R~
        	{                                                      //~6831R~
    //**************************                                   //~6831R~
        	case  1:          //first parm                         //~6831R~
          		strcpy(Sorgfname,cptr);                            //~v10jR~
//                strcpy(Sindexfnm,Sorgfname);                     //~v10jR~
//                pc=strchr(Sindexfnm,'.');                        //~v10jR~
//                if (pc && strlen(pc+1))                          //~v10jR~
//                    strcpy(pc+2,Sindexfid+2);                    //~v10jR~
//                else                                             //~v10jR~
//                    strcat(Sindexfnm,Sindexfid);                 //~v10jR~
          		break;                                             //~6831R~
    //**************************                                   //~6831R~
    		case 2: 			// 2nd parm                        //~6831R~
//                if (*cptr==INDEXUSE)                             //~v10jR~
//                {                                                //~v10jR~
//                    if (*(cptr+1))  //specified                  //~v10jR~
//                    {                                            //~v10jR~
//                        strcpy(Sindexfnm,cptr+1);                //~v10jR~
//                        Sgathersw=2;    //user specified         //~v10jR~
//                    }                                            //~v10jR~
//                    else                                         //~v10jR~
//                        Sgathersw=1;    //default                //~v10jR~
//                }                                                //~v10jR~
//                else                                             //~v10jR~
                  	for (Ssubfntctr=0,pc=cptr;;)                   //~6901R~
                  	{                                              //~6831R~
                    	if (Ssubfntctr>=MAXFNT)                    //~6831R~
            			{                                          //~6831R~
            				uerrexit("too many output filename specified.(max is %d)",0,//~6831R~
            						MAXFNT);                       //~6831R~
            			    exit(4);                               //~6831R~
            			}                                          //~6831R~
                  		pc2=strchr(pc,'+');	                       //~6831R~
                        if (pc2)                                   //~v10kI~
    		                *pc2=0;				//null term        //~v10kR~
                  		strcpy(Ssubfnt[Ssubfntctr],pc);            //~v10kM~
                  		Ssubfntctr++;                              //~v10kM~
                        if (!pc2)                                  //~v10kI~
                             break;                                //~v10kM~
                    	pc=pc2+1;                                  //~6901R~
            		}//search '+'                                  //~6831R~
              	break;                                             //~6831R~
    //**************************                                   //~6831R~
        	case 3:                                                //~6831R~
              	for (Ssizetctr=0,pc=cptr;;)                        //~6901R~
              	{                                                  //~6831I~
                	if (Ssizetctr>=MAXFNT)                         //~6831R~
        			{                                              //~6831I~
        				uerrexit("too many size specified.(max is %d)",0,//~6831R~
        						MAXFNT);                           //~6831R~
        			}                                              //~6831I~
              		pc2=strchr(pc,'+');                            //~6901I~
                    if (pc2)                                       //~6901I~
    	               	*pc2=0;				//null term            //~6901I~
                    if (*pc=='x' || *pc=='X')                      //~6901I~
                    {                                              //~6901I~
//                        len=ugethex(pc+1,hexedit1,sizeof(hexedit1));//~v104R~
//                        if (len<=0 || len >4)                    //~v104R~
//                            Ssizet[Ssizetctr]=0;    //later err msg//~v104R~
//                        else                                     //~v104R~
//                        {                                        //~v104R~
//                            memset(hexedit2,0,sizeof(hexedit2)); //~v104R~
//                            for (ii=0;ii<len;ii++)               //~v104R~
//                                hexedit2[ii]=hexedit1[len-ii-1];    //reverse//~v104R~
//                            Ssizet[Ssizetctr]=*(long*)(void*)hexedit2;//~v104R~
//                        }                                        //~v104R~
#ifdef LFSSUPP                                                     //~va30I~
                        if (ux2ll(pc+1,Ssizet+Ssizetctr))   //hex err//~va30I~
#else                                                              //~va30I~
                        if (ux2l(pc+1,(ULONG*)(void*)(&Ssizet[Ssizetctr])))   //hex err//~v1.1R~
#endif                                                             //~va30I~
	                  		Ssizet[Ssizetctr]=0;	//later err msg//~v104I~
					}                                              //~6901I~
                    else                                           //~6901I~
                    {                                              //~va1DI~
#ifdef LFSSUPP                                                     //~va30I~
                  		Ssizet[Ssizetctr]=ua2ll(pc);               //~va30R~
#else                                                              //~va30I~
                  		Ssizet[Ssizetctr]=atol(pc);                //~6901R~
#endif                                                             //~va30I~
                        sizepostfix=toupper(*(pc+unumlen(pc,0,(int)strlen(pc))));//~va1FR~
                        if (sizepostfix=='K')                      //~va1DI~
	                  		Ssizet[Ssizetctr]*=1024;               //~va1DR~
                        else                                       //~va1DI~
                        if (sizepostfix=='M')                      //~va1DI~
	                  		Ssizet[Ssizetctr]*=(1024*1024);        //~va1DR~
                        else                                       //~va1DI~
#ifdef LFSSUPP                                                     //~va30I~
                        if (sizepostfix=='G')                      //~va30I~
	                  		Ssizet[Ssizetctr]*=(1024*1024*1024);   //~va30I~
                        else                                       //~va30I~
#endif                                                             //~va30I~
                        if (sizepostfix)                           //~va1DI~
	                  		Ssizet[Ssizetctr]=0;                   //~va1DI~
                    }                                              //~va1DI~
              		if (!Ssizet[Ssizetctr])                        //~6901R~
        				uerrexit("invalid size parameter(%s)",0,   //~6831R~
        						pc);                               //~6831R~
					Ssizetctr++;                                   //~6901I~
                    if (!pc2)                                      //~6901I~
                         break;                                    //~6901I~
                	pc=pc2+1;                                      //~6901R~
        		}                                                  //~6831I~
              	break;                                             //~6831R~
    //************************************                         //~6831R~
            default:                                               //~6831R~
              	uerrexit("too many positional parameter(%s)",0,cptr);//~6831R~
            }//switch by parmno                                    //~6831R~
  		}//option or posparm                                       //~6831R~
	}//for all parm                                                //~6831R~
    if (!posparmno)                                                //~v1.1I~
        uerrexit("filename parameter missing",0);                  //~v1.1I~
//get indexfilename for split                                      //~v10jI~
    if (Sgathersw)      //gather                                   //~v10jI~
    {                                                              //~v10jI~
    	if (*Spgmnm)                                               //~v10qR~
        	uerrexit("Pgm copy option is avail only when split case",0);//~v10qR~
    	if (Srestartdrivesw)                                       //~v131R~
			uerrexit("restart/retry disk No. parm(%c#) in valid only when split case",0,//~v141R~
					CMDFLAG_PREFIX);                               //~v141I~
    	if (Smultirecid)                                           //~va1FM~
	        uerrexit("%cS(record separator string) parm is for split only.",0,//~va1FM~
						CMDFLAG_PREFIX);                           //~va1FM~
        if (Slinenosw)                                             //~v141I~
			uerrexit("Line count option(%cYl) is valid only when split case",0,//~v141I~
					CMDFLAG_PREFIX);                               //~v141I~
        if (!Sbinsw)                                               //~v141I~
			uerrexit("Text mode option (%cYt) is valid only when split case",0,//~v141I~
					CMDFLAG_PREFIX);                               //~v141I~
//first disk mount req                                             //~v131I~
        if (Sorgfname[1]==':'                                      //~v131I~
        &&  !Sorgfname[2])		//driveid: format                  //~v131I~
        {                                                          //~v146I~
//      	if (Sremovablesw=drivechksub(Sorgfname[0]),Sremovablesw)	//removable//~v146R~
        	Sremovablesw=drivechksub(Sorgfname[0]);                //~v146I~
            if (!Sremovablesw && parmmovable)                      //~v146I~
                Sremovablesw=2;                                    //~v146I~
        	if (Sremovablesw)	//removable                        //~v146I~
//			    mountreq(Sorgfname,5,0,1);                         //~va30R~
			    mountreq(Sorgfname,5,(FILESZT)0,1);                //~va30I~
        }//d: fmt                                                  //~v146I~
                                                                   //~v131I~
		if (!ufullpath(Sindexfnm,Sorgfname,sizeof(Sindexfnm)))     //~v10lI~
	    	exit(8);                                               //~v10lI~
//  	pathlen=PATHLEN(Sindexfnm);                                //~va1iR~
    	pathlen=(int)strlen(Sindexfnm);	//for the case name is dir //~va1jR~
//printf("pathlen=%d,indexfnm=%s\n",pathlen,Sindexfnm);            //~v10sR~
//search indexfile if driveid only                                 //~v10mM~
#ifdef UNX                                                         //~v171I~
        if (MDOSDISKOK(Sindexfnm))//root dir                       //~v171I~
        	rootpathsw=(pathlen==3);                               //~v171I~
        else                                                       //~v171I~
        	rootpathsw=(pathlen==1);                               //~v171I~
        if (rootpathsw                                             //~v171I~
#else                                                              //~v171I~
        if (pathlen==3 //root dir                                  //~v10rR~
#endif                                                             //~v171I~
        ||  (!ufstat(Sindexfnm,&fstat3)                            //~v10rR~
          && (fstat3.attrFile & FILE_DIRECTORY)))                  //~v10rR~
        {                                                          //~v10mM~
	        strcpy(Sorgfname,Sindexfnm);                           //~v10rI~
#ifdef UNX                                                         //~v171I~
        	if (!rootpathsw)                                       //~v171R~
#else                                                              //~v171I~
            if (pathlen!=3)                                        //~v10rI~
#endif                                                             //~v171I~
            {                                                      //~v10rI~
            	pathlen=(int)strlen(Sorgfname);                    //~v1.1R~
//              *(Sorgfname+pathlen++)='\\';                       //~v171R~
                *(Sorgfname+pathlen++)=DIR_SEPC;                   //~v171I~
			}                                                      //~v10rI~
            *(Sorgfname+pathlen)='*';                              //~v10mM~
            strcpy(Sorgfname+pathlen+1,Sindexfid);                 //~v10mM~
//printf("pathlen=%d,indexfnm=%s\n",pathlen,Sorgfname);            //~v10sR~
            if ((fno=udirlistnomsg(Sorgfname,FILE_ALL-FILE_DIRECTORY,&pudirlist,0))<=0)//~v10mM~
                return;                                            //~v10mM~
            if (fno>1)                                             //~v10mM~
                uerrexit("multiple restore control file exist(%s),specify one of them",0,//~v10mM~
                        Sorgfname);                                //~v10mM~
            strcpy(Sorgfname+pathlen,pudirlist->name);             //~v10mM~
//printf("pathlen=%d,indexfnm=%s\n",pathlen,Sorgfname);            //~v10sR~
	        strcpy(Sindexfnm,Sorgfname);                           //~v10rI~
        }                                                          //~v10mM~
//printf("fattrfile=%08x\n",fstat3.attrFile);                      //~v10sR~
                                                                   //~v10rI~
//#ifdef DOS                                                       //~va2aR~
#if defined(DOS)||defined(OS2)                                     //~va2aI~
    	pathlen=PATHLEN(Sindexfnm);                                //~va1iI~
        pc=strchr(Sindexfnm+pathlen,'.');                          //~v10lR~
        if (pc)                                                    //~v10jI~
            strcpy(pc,Sindexfid);                                  //~v10jI~
        else                                                       //~v10jI~
            strcat(Sindexfnm,Sindexfid);                           //~v10jI~
#else                                                              //~va1iI~
        if (strlen(Sindexfnm)<=strlen(Sindexfid)                   //~va1iI~
        ||  strcmp(Sindexfnm+strlen(Sindexfnm)-strlen(Sindexfid),Sindexfid))//~va1iR~
    	    strcat(Sindexfnm,Sindexfid);                           //~va1iR~
#endif                                                             //~va1iI~
                                                                   //~va1iI~
		if (Ssubfntctr)                                            //~v10jI~
        	strcpy(Sorgfname,Ssubfnt[0]);                          //~v10jI~
		else                                                       //~v10jI~
        	Sorgfname[0]=0;                                        //~v10jR~
	}                                                              //~v10jI~
    else                //split                                    //~v10jI~
    {                                                              //~v10jI~
	    if (posparmno<2)                                           //~v1.1R~
    	    uerrexit("subfilename parameter missing",0);           //~v1.1R~
        if (Sbinsw)                                                //~v141I~
        	if (Slinenosw)                                         //~v141I~
				uerrexit("option to split by line count(%cYl) in valid with Text mode option (%cYt).",0,//~v141I~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX);            //~v141I~
		if (!ufullpath(Sindexfnm,Sorgfname,sizeof(Sindexfnm)))     //~v10jI~
	    	exit(8);                                               //~v10jI~
        strcpy(Sorgfname,Sindexfnm);//fullpath for index write     //~v10jI~
        for (ii=0;ii<Ssubfntctr;ii++)                              //~v10vI~
            if (stricmp(Snullid,Ssubfnt[ii]))   //search not null  //~v10vR~
                break;                                             //~v10vI~
        if (ii==Ssubfntctr)                                        //~v10vR~
        	uerrexit("Output file is all NUL file",0);             //~v10vI~
//		if (!ufullpath(Sindexfnm,Ssubfnt[0],sizeof(Sindexfnm)))    //~v10vR~
//mount needed before ufullpath                                    //~v131I~
        if (Ssubfnt[ii][1]==':'                                    //~v131I~
        &&  !Ssubfnt[ii][2])		//driveid: format              //~v131I~
        {                                                          //~v146I~
//      	if (Sremovablesw=drivechksub(Ssubfnt[ii][0]),Sremovablesw)	//removable//~v146R~
        	Sremovablesw=drivechksub(Ssubfnt[ii][0]);              //~v146I~
            if (!Sremovablesw && parmmovable)                      //~v146I~
        		Sremovablesw=2;                                    //~v146I~
        	if (Sremovablesw)	//removable                        //~v146I~
            {                                                      //~va1jI~
            	if (Srestartdrivesw)                               //~v132I~
                {                                                  //~v132I~
				   	if (Srestartdriveno==1)       //before just before//~v132I~
                    {                                              //~v131I~
                    	drvno=2;                                   //~v132I~
                        Smsgsw=1;   //warning at Esc in confirm func//~v131I~
                    }                                              //~v131I~
					else                                           //~v132I~
    					drvno=Srestartdriveno-1;                   //~v132I~
//  		  	    mountreq(Sorgfname,3,0,drvno); //              //~va30R~
    		  	    mountreq(Sorgfname,3,(FILESZT)0,drvno); //     //~va30I~
                    Smsgsw=0;   //warning at Esc                   //~v131I~
        		}                                                  //~v132I~
                else                                               //~v132I~
//  		  	    mountreq(Sorgfname,4,0,1);                     //~va30R~
    		  	    mountreq(Sorgfname,4,(FILESZT)0,1);            //~va30I~
            }//removablesw                                         //~va1jI~
                                                                   //~v131I~
        }//d: fmt                                                  //~v146I~
  		if (!ufullpath(Sindexfnm,Ssubfnt[ii],sizeof(Sindexfnm)))   //~v10vI~
	    	exit(8);                                               //~v10jI~
		pathlen=PATHLEN(Sindexfnm);                                //~v10jI~
        strcpy(Sindexfnm+pathlen,Sorgfname+PATHLEN(Sorgfname));    //~v10jI~
//#ifdef DOS                                                       //~va2aR~
#if defined(DOS)||defined(OS2)                                     //~va2aI~
        pc=strchr(Sindexfnm+pathlen,'.');                          //~v10jI~
        if (pc)                                                    //~v10jI~
            strcpy(pc,Sindexfid);                                  //~v10jI~
        else                                                       //~v10jI~
            strcat(Sindexfnm+pathlen,Sindexfid);                   //~v10jI~
#else                                                              //~va1iI~
        strcat(Sindexfnm+pathlen,Sindexfid);                       //~va1iI~
#endif                                                             //~va1iI~
        rmvchksw=0;                                                //~v10kI~
        for (ii=0;ii<Ssubfntctr;ii++)                              //~v10kI~
        {                                                          //~v10kI~
//fix/removable mix chk                                            //~v10kI~
        	fnm=Ssubfnt[ii];                                       //~v10kR~
        	if (stricmp(fnm,Snullid))//not NUL                     //~v10kI~
            {                                                      //~v10kI~
                if (!ufullpath(fullpath,fnm,sizeof(fullpath)))     //~v10kR~
                    exit(8);                                       //~v10kI~
                strcpy(fnm,fullpath);                              //~v10kI~
                if (!rmvchksw)	//first sw                         //~v10kR~
                {                                                  //~v10kI~
                    Sremovablesw=drivechksub(*fnm);                //~v10kR~
		            if (!Sremovablesw && parmmovable)              //~v146I~
                        Sremovablesw=2;                            //~v146I~
                    rmvchksw=1;                                    //~v10kR~
					if (!Sremovablesw)                             //~v1.1I~
						if (posparmno<3)                           //~v1.1I~
    	    				uerrexit("size parameter missing",0);  //~v1.1I~
				}                                                  //~v10kI~
                else                                               //~v10kI~
                    if (Sremovablesw!=drivechksub(*fnm))           //~v10kR~
                        uerrexit("Fixed and removable drive is mixed for output",0);//~v10kI~
//default outfilename create                                       //~v10kI~
                if (Sremovablesw)                                  //~v10kI~
#ifdef UNX                                                         //~v171I~
                    if (MDOSROOTDIR(fnm))    //root                //~v171I~
#else                                                              //~v171I~
                    if (ROOTDIR(fnm))    //root                    //~v171R~
#endif                                                             //~v171R~
                    {	                                           //~v10kI~
                    	strcpy(fnm+3,Sindexfnm+3);                 //~v10kR~
				        pc=strchr(fnm+pathlen,'.');                //~v10kR~
                        strcpy(pc+1,"_??");                        //~v10kI~
                    }                                              //~v10kI~
//chk wild card                                                    //~v10kM~
                pc=strchr(fnm,'?');                                //~v10kR~
                if (pc)                                            //~v10kI~
                {                                                  //~v10kI~
//                  Swildpos[ii]=(int)((ULONG)pc-(ULONG)fnm);      //~v10kR~//~va66R~
                    Swildpos[ii]=(int)((ULPTR)pc-(ULPTR)fnm);      //~va66I~
                    for (jj=0;*pc && *pc=='?';pc++)                //~v10kI~
                        jj++;                                      //~v10kI~
                    Swildlen[ii]=jj;                               //~v10kI~
                }//wild card                                       //~v10kI~
			}//not nul                                             //~v10kR~
		}//loop                                                    //~v10kR~
    }//split                                                       //~v10kR~
    if (!Sgathersw)      //split                                   //~v10kM~
    {                                                              //~v10kM~
        if (!Ssubfntctr)                                           //~v10kI~
        	uerrexit("Output filename parm missing",0);            //~v10kI~
        if (!Ssizetctr)	//no parm                                  //~v10kI~
            if (!Sremovablesw)                                     //~v10kI~
	        	uerrexit("Output size parm missing for non-removable device",0);//~v133R~
        if (Srestartdriveno)	//restart                          //~v131I~
            if (!Sremovablesw)                                     //~v131I~
	        	uerrexit("restart/retry No.(%c#) is valid option for removable device case only",0,//~v141R~
							CMDFLAG_PREFIX);                       //~v141I~
        if (!Sremovablesw)  		//fixed disk                   //~v144I~
            if (!parmverifyreq)     //no explicit verify req       //~v144I~
            	Sverifysw=0;        //no verify                    //~v144I~
    }                                                              //~v10kM~
    else                                                           //~v10kM~
    {                                                              //~va1FI~
        if (Ssizetctr)                                             //~v10kM~
	        uerrexit("size parameter is not avail for gather operation",0);//~v10kM~
    }                                                              //~va1FI~
    if (Srecnosw)   //size parm by recno                           //~va1FI~
    {                                                              //~va1FI~
    	if (!Smultirecid)                                          //~va1FI~
	        uerrexit("%cYr(recordno) parm requires %cS(record separator string) parm",0,//~va1FR~
						CMDFLAG_PREFIX,CMDFLAG_PREFIX);            //~va1FI~
    }                                                              //~va1FI~
}//parmchk
//**********************************************************************//~6831I~
//* confirm                                                        //~6831I~
//**********************************************************************//~6831I~
char confirm(char *Pmsge,char *Pmsgj,char *Preply)                 //~6831I~
{                                                                  //~6831I~
    char  reply,*pc,*pc2;                                          //~v131R~
    char  valid[128];                                              //~v131R~
//**********                                                       //~6831I~
	for (pc=Preply,pc2=valid;*pc;pc++)                             //~v130I~
    {                                                              //~v130I~
        if (*pc=='\r')                                             //~v130R~
        {                                                          //~v130I~
            memcpy(pc2,"Enter-key",9);                             //~v134R~
            pc2+=9;                                                //~v134R~
		}                                                          //~v130I~
        else                                                       //~v130I~
       		if (*pc=='\x1b')                                       //~v130R~
            {                                                      //~v130I~
	            memcpy(pc2,"Esc-key",7);                           //~v134R~
	            pc2+=7;                                            //~v134R~
			}                                                      //~v130I~
            else                                                   //~v130I~
            {                                                      //~v130I~
        	    *pc2=*pc;                                          //~v130I~
	            pc2++;                                             //~v130I~
			}                                                      //~v130I~
		*pc2++=',';                                                //~v130I~
    }                                                              //~v130I~
    if (pc==Preply||pc2>=valid+sizeof(valid))                      //~v130I~
    	uerrexit("internal err;no valid confirm char",0);          //~v130I~
    *(pc2-1)=0;                                                    //~v130I~
	for (;;)                                                       //~6831I~
    {                                                              //~6831I~
//clear kbd buff                                                   //~v132I~
#ifdef UNX                                                         //~v140I~
        while(kbhit())                                             //~v140I~
	    	getch_nc();  //getch not under curses                  //~v140I~
#else                                                              //~v140I~
#ifdef DOS                                                         //~v132I~
        while(kbhit())                                             //~v132I~
	    	getch();                                               //~v132I~
#else                                                              //~v132I~
	#ifdef W32                                                     //~v132I~
        while(_kbhit())                                            //~v131R~
	    	_getch();                                              //~v131R~
    #else                                                          //~v132I~
        while(_kbhit())                                            //~v132I~
	    	_getch();                                              //~v132I~
    #endif                                                         //~v132I~
#endif                                                             //~v132I~
#endif                                                             //~v140I~
        ubell();                                                   //~v123I~
//  	uerrmsg(Pmsge,Pmsgj);                                      //~v123R~
        if (!Sdbcssw)                                              //~v123I~
//          printf(Pmsge);                                         //~v123R~//~va76R~
            printf("%s",Pmsge);                                    //~va76I~
        else                                                       //~v123I~
//          printf(Pmsgj);                                         //~v123R~//~va76R~
            printf("%s",Pmsgj);                                    //~va76I~
        printf("===>");                                            //~v123I~
        fflush(stdout);                                            //~v123R~
//  	scanf("%3s",reply);                                        //~v130R~
#ifdef UNX                                                         //~v140I~
    	reply=(UCHAR)getch_nc();                                   //~v140I~
#else                                                              //~v140I~
#ifdef DOS                                                         //~v130I~
    	reply=(UCHAR)getch();                                      //~v130R~
#else                                                              //~v130I~
	#ifdef W32                                                     //~v130I~
    	reply=(UCHAR)_getch();                                     //~v131R~
    #else                                                          //~v130I~
    	reply=(UCHAR)_getch();                                     //~v130R~
    #endif                                                         //~v130I~
#endif                                                             //~v130I~
#endif                                                             //~v140I~
        if (!reply)         //pf-key etc                           //~v134I~
            reply=' ';                                             //~v134I~
        if (reply=='\r')                                           //~v130I~
            printf("Enter\n");                                     //~v130I~
        else                                                       //~v130I~
       		if (reply=='\x1b')                                     //~v130I~
        	    printf("Esc\n");                                   //~v130I~
            else                                                   //~v130I~
        	    printf("%c\n",reply);                              //~v134R~
//printf("\nreply=%c(%02x)\n",reply,(int)reply);                   //~v134R~
    	pc=strchr(Preply,reply);                                   //~v130R~
        if (pc)                                                    //~6831I~
        	break;                                                 //~6831I~
    	uerrmsg("Invalid reply,Enter one of %s.",                  //~v134R~
    	    	"無効な入力.%s のいずれかを入力して下さい",        //~v134R~
    			valid);                                            //~v134R~
	}                                                              //~6831I~
//  if (*reply=='N' || *reply=='n')                                //~v130R~
    if (reply=='\x1b')                                             //~v130R~
    {                                                              //~v131I~
        if (Smsgsw)                                                //~v131I~
        {                                                          //~v131I~
    	    uerrmsg("Next of retry disk requied for offset,length and chksum,\n\
if restart case(retry from the disk) use '-' postfix on /# parm like as /#4-.",//~v131R~
        	         "再試行ディスクの次のディスクが必要です(開始位置,長さ,チェクサム)\n\
再開始(そのディスク以降の出力)の場合は /#4- の様に '-' を使用して下さい。\n");//~v131M~
                                                                   //~v131M~
        }                                                          //~v131I~
    	uerrexit("Process canceled",0);                            //~v10kI~
    }                                                              //~v131I~
    return reply;                                                  //~v130R~
}//confirm                                                         //~6831I~
//**********************************************************************//~v135I~
//* keyboad input chk                                              //~v135I~
//* parm :string of char to be chked                               //~v135I~
//* ret  :key value hit or 0 no match                              //~v135I~
//**********************************************************************//~v135I~
int kbdchk(char *Pvalid)                                           //~v135I~
{                                                                  //~v135I~
	int key;                                                       //~v135I~
//**********                                                       //~v135I~
	while(key=kbdchksub(),key)                                     //~v135I~
    	if (strchr(Pvalid,key))                                    //~v135I~
        	break;                                                 //~v135I~
    return key;                                                    //~v135I~
}//kbdchksub                                                       //~v135I~
//**********************************************************************//~v135I~
//* keyboad input chk                                              //~v135I~
//* ret  :key value hit                                            //~v135I~
//**********************************************************************//~v135I~
int kbdchksub(void)                                                //~v135R~
{                                                                  //~v135I~
	int key=0;                                                     //~v135I~
//**********                                                       //~v135I~
#ifdef UNX                                                         //~v140I~
        if (kbhit())                                               //~v140I~
	    	key=getch_nc();                                        //~v140I~
#else                                                              //~v140I~
#ifdef DOS                                                         //~v135I~
        if (kbhit())                                               //~v135I~
	    	key=getch();                                           //~v135I~
#else                                                              //~v135I~
	#ifdef W32                                                     //~v135I~
        if (_kbhit())                                              //~v131R~
	    	key=_getch();                                          //~v131R~
    #else                                                          //~v135I~
        if (_kbhit())                                              //~v135I~
	    	key=_getch();                                          //~v135I~
    #endif                                                         //~v135I~
#endif                                                             //~v135I~
#endif                                                             //~v140I~
    return key;                                                    //~v135I~
}//kbdchksub                                                       //~v135R~
//**********************************************************************//~v136I~
//* list dir (1 level)                                             //~v136I~
//**********************************************************************//~v136I~
void listdir(int Pfno,PUDIRLIST Ppudirlist)                        //~v136I~
{                                                                  //~v136I~
    int ii;                                                        //~v136I~
    PUDIRLIST pudirlist;                                           //~v136I~
//  char editwk[16];                                               //~va30R~
    char editwk[32];                                               //~va30I~
    char attrwk[8];                                                //~v136I~
#ifdef UNX                                                         //~va1YI~
    int efaopt;                                                    //~va1YI~
#endif                                                             //~va1YI~
//************                                                     //~v136I~
    for (ii=0,pudirlist=Ppudirlist;ii<Pfno;ii++,pudirlist++)       //~v136I~
    {                                                              //~v136I~
//        if (!strcmp(pudirlist->name,"."))                        //~v136I~
//            continue;                                            //~v136I~
//        if (!strcmp(pudirlist->name,".."))                       //~v136I~
//            continue;                                            //~v136I~
//      unumedit((ULONG)pudirlist->size,"z,zzz,zzz,zz9",editwk);   //~va30R~
		xffeditfszz(pudirlist->size,editwk);                       //~va30I~
#ifdef UNX                                                         //~va1YI~
        efaopt=UEFA_DIR|UEFA_SZ;        //set sz at last           //~va1YI~
//      if (MDOSDISKOK(fpath))                                     //~va1YI~
        if (pudirlist->attr & FILE_MDOSDISK)                       //~va1YI~
            efaopt|=UEFA_MDOS;                                     //~va1YI~
        ueditfattr(pudirlist->attr,attrwk,efaopt);      //set sz at last//~va1YI~
#else                                                              //~va1YI~
        ueditfattr(pudirlist->attr,attrwk,UEFA_DIR|UEFA_SZ);      //set sz at last//~v136I~
#endif                                                             //~va1YI~
        uerrhelpmsg(stdout,stderr,"%s%s %s\n",0,                   //~v136I~
					attrwk,editwk,pudirlist->name);                //~v136I~
    }                                                              //~v136I~
    return;                                                        //~v136I~
}//listdir                                                         //~v136I~
//**********************************************************************//~va30I~
//* edit filesize to dec and hex,return hex out addr               //~va30I~
//**********************************************************************//~va30I~
char *xffeditfszzx(FILESZT Pfsz,char *Pdecout)                     //~va30I~
{                                                                  //~va30I~
	xffeditfszz(Pfsz,Pdecout);                                     //~va30I~
	return xffeditfszx(Pfsz,0);	//return static addr               //~va30I~
}//xffeditfszx                                                     //~va30I~
//**********************************************************************//~va30I~
//* edit filesize to minlen=8 hex printf fmt                       //~va30R~
//**********************************************************************//~va30I~
char *xffeditfszx(FILESZT Pfsz,char *Pdecout)                      //~va30R~
{                                                                  //~va30I~
	return ufileeditsz(UFEFSZ_STDFMT+UFEFSZ_HEXUPPER+8,Pfsz,Pdecout);//~va30R~
}//xffeditfszx                                                     //~va30R~
//**********************************************************************//~va30I~
//* edit filesize to comma seperated decimal fmt                   //~va30I~
//**********************************************************************//~va30I~
char *xffeditfszz(FILESZT Pfsz,char *Pdecout)                      //~va30I~
{                                                                  //~va30I~
	return ufileeditsz(UFEFSZ_FULLZ,Pfsz,Pdecout);                 //~va30I~
}//xffeditfszx                                                     //~va30I~
//**********************************************************************
//* write help msg  
//**********************************************************************
void help(void)
{
//**********************                                           //~v111I~
#define HELPMSG uerrhelpmsg(stdout,stderr,                         //~v111I~
//**********************                                           //~v111I~
HELPMSG                                                            //~v111I~
"%s:%s:===(%c)=== file split/restore utility program\n",           //~v111R~
"%s:%s:===(%c)=== ファイル分割統合ユーティリティー\n",PGM,VER,OSTYPE);//~v111R~
HELPMSG                                                            //~v111I~
"format:\n",                                                       //~v111R~
"形式  :\n");                                                      //~v111R~
HELPMSG                                                            //~v111I~
//"  split  : %s  file  subfile  [size]  [%cYx | %cNx] [%cp[pth]]\n",//~va1CR~
//"  分割   : %s  file  subfile  [size]  [%cYx | %cNx] [%cp[path]]\n",//~va1CR~
"  split  : %s file subfile [size] [-S{s|e}[{+|-}n]string] [%cYx|%cNx] [%cp[pth]]\n",//~va1CR~
"  分割   : %s file subfile [size] [-S{s|e}[{+|-}n]string] [%cYx|%cNx] [%cp[path]]\n",//~va1CR~
				PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX); //~v140R~
HELPMSG                                                            //~v111I~
"           file   :original file to be split.\n",                 //~v111R~
"           file   :分割対象元ファイル.\n");                       //~v111R~
HELPMSG                                                            //~v111I~
"           subfile:output split filenames.\n",                    //~v111R~
"           subfile:出力分割サブファイル.\n");                     //~v111R~
HELPMSG                                                            //~v111I~
"                   concatinate by '+' or use '?' as wild card.\n",//~v111R~
"                   '+' で結合するか ワイルドカード '?' 指定する.\n");//~v111R~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v111I~
"                   for removable media,drive id only is avail.\n",//~v111R~
"                   移動媒体の場合、ドライブＩＤのみの指定でもよい.\n");//~v111R~
//#endif                                                           //~v171R~
HELPMSG                                                            //~v111I~
//"           size   :size of each output subfiles.(line count if /Yl)\n",//~va1DR~
//"           size   :各サブファイルのサイズ.(/Yl のときは行数)\n");//~va1DR~
#ifdef LFSSUPP                                                     //~va30I~
"           size[K|M|G]:size of each output subfiles.(line count if /Yl)\n",//~va30I~
"           size[K|M|G]:各サブファイルのサイズ.(/Yl のときは行数)\n");//~va30I~
#else                                                              //~va30I~
"           size[K|M]:size of each output subfiles.(line count if /Yl)\n",//~va1DI~
"           size[K|M]:各サブファイルのサイズ.(/Yl のときは行数)\n");//~va1DI~
#endif                                                             //~va30I~
HELPMSG                                                            //~v111I~
"                   concatinate by '+' if output is not wildcard.\n",//~v130R~
"                   出力先ワイルドカードで無い場合は'+'で結合する.\n");//~v130R~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v111I~
"                   it is omittable for removable media,fill all free space.\n",//~v111R~
"                   移動媒体の場合省略可\x94\\で全フリースペースを埋める.\n");//~v111R~
//#endif                                                           //~v171R~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v131I~
"           %c#n[-] :n is restart/retry output disk No.; '-' means restart\n",//~v140R~
"           %c#n[-] :n は 再試行/再開始する出力ディスクＮｏ,'-'は再開始を意味する\n",//~v140R~
					CMDFLAG_PREFIX);                               //~v140I~
HELPMSG                                                            //~v130M~
"           %cp[pth]:option to PGM copy from pth to output dir\n", //~v140R~
"           %cp[pth]:pth にあるこの EXE を出力ディスクに複写するオプション\n",//~v140R~
					CMDFLAG_PREFIX);                               //~v140I~
HELPMSG                                                            //~v130M~
"                   if pth omitted,search EXE by env var\n",       //~v130M~
"                   pth を省略すると環境変数に従って探します\n");  //~v130M~
//#endif                                                           //~v171R~
HELPMSG                                                            //~va1CR~
//"           %cs{s|e}[{+|-}n]string :multiple line record start/end specification.\n",//~va21R~
//"           %cs{s|e}[{+|-}n]string :複数行レコード開始/終了行の識別文字列指定。\n",//~va21R~
"           %cs[{+|-}n]{s|e}string :multiple line record start/end specification.\n",//~va21R~
"           %cs[{+|-}n]{s|e}string :複数行レコード開始/終了行の識別文字列指定。\n",//~va21R~
					CMDFLAG_PREFIX);                               //~va1CR~
//HELPMSG                                                          //~va21R~
//"                   s: start line specification. e: end line specification.\n",//~va21R~
//"                   s:開始行識別指定。e:終了行識別指定。\n");    //~va21R~
HELPMSG                                                            //~va1CR~
"                   n: compare column from linetop(+) or lineend(-).(default:+1)\n",//~va1CR~
"                   n:行頭(+)あるいは行末(-)からの比較桁位置。(省略値:+1)\n");//~va1CR~
HELPMSG                                                            //~va21R~
"                   s: start line specification. e: end line specification.\n",//~va21R~
"                   s:開始行識別指定。e:終了行識別指定。\n");      //~va21R~
HELPMSG                                                            //~va1CR~
"                   string:multiple line starting/ending identification.\n",//~va1CR~
"                   string:複数行レコードの開始/終了行識別指定文字列。\n");//~va1CR~
HELPMSG                                                            //~va1CR~
"                     ex) %cSs\"Frame\". %cSe-**End**.\n",         //~va1CR~
"                     例) %cSs\"Frame\". %cSe-**End**.\n",         //~va1CR~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~va1CR~
HELPMSG                                                            //~v129I~
"           %cYx,%cNx:toggle type switch; x is as following.\n",   //~v140R~
"           %cYx,%cNx:オン/オフ タイプのフラグ; x はつぎのフラグを指定\n",//~v140R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v140R~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v129I~
"              d   :delete file on removable media witout confirmation.\n",//~v146R~
"              d   :空でない移動可\x94\\媒体のファイルを確認なしで全削除する｡\n");//~v146R~
HELPMSG                                                            //~v129I~
"                   Or,delete with confirmation when %cYm.default is %cNd.\n",//~v146R~
"                   或いは%cYmのとき確認をとって全削除する。省略値は %cNd.\n",//~v146R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v140I~
//#endif                                                           //~v171R~
HELPMSG                                                            //~v141I~
"              l   :split by line count. specify line count by size parm(%cNl).\n",//~va1FR~
"              l   :行数で分割,size パラメータは行数指定(%cNl)。\n",//~v141I~
					CMDFLAG_PREFIX);                               //~v141I~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v146I~
"              m   :assume split file on movable disk.(%cNm).\n",  //~v146R~
"              m   :分割ファイルが移動可\x94\\媒体にあるものとする(%cNm)。\n",//~v146R~
					CMDFLAG_PREFIX);                               //~v146I~
//#endif                                                           //~v171R~
HELPMSG                                                            //~va1FI~
"              r   :split by record count, specify rec-no by size parm(%cNr).\n",//~va1FR~
"              r   :レコード数で分割,size パラメータはレコード数指定(%cNr)。\n",//~va1FI~
					CMDFLAG_PREFIX);                               //~va1FI~
HELPMSG                                                            //~va1FI~
"                   record is identified by %cS parameter.\n",     //~va1FI~
"                   レコード識別は %cS パラメータで指定する。\n",  //~va1FI~
					CMDFLAG_PREFIX);                               //~va1FI~
HELPMSG                                                            //~v129I~
"              t   :specify original file is binary file(%cNt) or text file(%cYt).\n",//~v140R~
"              t   :分割対象元ファイルがバイナリー(%cNt)かテキストファイルか(%cYt)\n",//~v140R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v140I~
HELPMSG                                                            //~v129I~
"                   split by exactly specified size for binaly file.\n",//~v129I~
"                   バイナリーのときサイズの値で分割.\n");         //~v129I~
HELPMSG                                                            //~v129I~
"                   split at last end of line near the boundary for text.\n",//~v129I~
"                   テキストのときその近辺の行の境界で分割.\n");   //~v129I~
HELPMSG                                                            //~v129I~
"                   default is %cNt if no %cYl used.\n",           //~v145R~
"                   省略値は %cYlでなければ%cNt.\n",               //~v145R~
	    			CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v145R~
HELPMSG                                                            //~v127I~
"              v   :Do read verify after each subfile written(%cYv) or not(%cNv).\n",//~v140R~
"              v   :分割サブファイル出力の都度読込確認をする(%cYv)か否か(%cNv)\n",//~v140R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v140I~
HELPMSG                                                            //~v121R~
"                   default is %cYv\n",                            //~v140R~
"                   省略値は %cYv\n",                              //~v140R~
					CMDFLAG_PREFIX);                               //~v140I~
HELPMSG                                                            //~v111I~
"  restore: %s  ctlfile  [outfile]  %cr\n",                        //~v140R~
"  統合   : %s  ctlfile  [outfile]  %cr\n",                        //~v140R~
					PGM,CMDFLAG_PREFIX);                           //~v140I~
HELPMSG                                                            //~v111I~
"           ctlfile:specify restore control file created at split\n",//~v111R~
"           ctlfile:分割のときに出力された統合制御ファイル.\n");   //~v131R~
//#ifdef DOS                                                       //~va2aR~
#if defined(DOS)||defined(OS2)                                     //~va2aI~
HELPMSG                                                            //~v111I~
"                   with the same base name as original file and ext name ._~!.\n",//~v111R~
"                   統合制御ファイルは出力分割サブファイルと同じ\n");//~v131R~
HELPMSG                                                            //~v111I~
"                   ext name is omittable.\n",                     //~v111R~
"                   ディレクトリーに元ファイルの基本名+._~! で出力済み\n");//~v111R~
HELPMSG                                                            //~v111I~
"                   path name only is ok if unique.\n",            //~v111R~
"                   拡張子名は省略可\x94\\、唯一ならパス名のみも可.\n");//~v111R~
#else                                                              //~va1iI~
HELPMSG                                                            //~va1iI~
"                   with name \"._~!\" is appended to original filename.\n",//~va1iR~
"                   統合制御ファイルは出力分割サブファイルと同じ\n");//~va1iI~
HELPMSG                                                            //~va1iI~
"                   \"._~!\" is omittable.\n",                     //~va1iI~
"                   ディレクトリーに元ファイル名に\"._~!\"を付けて出力済み\n");//~va1iI~
HELPMSG                                                            //~va1iI~
"                   path name only is ok if unique in the directory.\n",//~va1iI~
"                   \"._~\"は省略可\x94\\.唯一ならパス名のみも可.\n");//~va1iR~
#endif                                                             //~va1iI~
HELPMSG                                                            //~va49I~
"                   place ctlfile with subfiles when copy to the other directory.\n",//~va49I~
"                   他所にコピーする時は制御ファイルとサブファイルは一緒にする。\n");//~va49R~
HELPMSG                                                            //~v111I~
"           outfile:specify when you want change destination from original file.\n",//~v111R~
"           outfile:別名で統合するときに指定する.\n");             //~v111R~
HELPMSG                                                            //~v111I~
"           %cr     :mean retore operation.\n",                    //~v140R~
"           %cr     :統合オペレーションの指示.\n",                 //~v140R~
					CMDFLAG_PREFIX);                               //~v140I~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v111I~
"ex 1. %s abc.def a: %cp\n",0,PGM,CMDFLAG_PREFIX);                 //~v140R~
HELPMSG                                                            //~v111I~
"   ==>backup abc.def and %s.EXE to disket.\n",                    //~v111R~
"   ==>abc.def %s.EXE とをPGMをディスケットにBACKUPする.\n",PGM);  //~v111R~
//#endif                                                           //~v171R~
HELPMSG                                                            //~v111I~
"ex 2. %s abc.def abc.1+abc.2+abc.3 10000+20000\n",0,PGM);         //~v111R~
HELPMSG                                                            //~v111I~
"   ==>cut abc.def into abc.1(10000 byte),abc.2(20000) and abc.3(residual len).\n",//~v111R~
"   ==>abc.def を abc.1(10000 バイト),abc.2(20000) and abc.3(残りの長さ)に分割.\n");//~v111R~
HELPMSG                                                            //~v111I~
"ex 3. %s abc.def abc.d?? x1000 %cb\n",0,PGM,CMDFLAG_PREFIX);      //~v140R~
HELPMSG                                                            //~v111I~
"   ==>cut abc.def into abc.d01,abc.d02 ...(each file is 4096 byte).\n",//~v111R~
"   ==>abc.def を abc.d01,abc.d02 ...(各 4096 バイト)に分割.\n");  //~v111R~
HELPMSG                                                            //~v111I~
"ex 4. %s abc.def abc.000 10000 %cYl\n",0,PGM,CMDFLAG_PREFIX);     //~v144R~
HELPMSG                                                            //~v111I~
"   ==>get first 10000 lines from abc.def into abc.000.\n",        //~v141R~
"   ==>abc.def の最初の 10000 行を abc.000 に出力.\n");            //~v141R~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v111I~
"ex 5. %s a: %cr\n",0,PGM,CMDFLAG_PREFIX);                         //~v140R~
HELPMSG                                                            //~v111I~
"   ==>restore file from backup disket.\n",                        //~v111R~
"   ==>BACKUPディスケットから戻す.\n");                            //~v111R~
HELPMSG                                                            //~v111I~
"ex 6. %s a: xyz %cr\n",0,PGM,CMDFLAG_PREFIX);                     //~v140R~
HELPMSG                                                            //~v111I~
"   ==>restore file from backup disket to file xyz.\n",            //~v111R~
"   ==>BACKUPディスケットから別名 xyz で戻す\n");                  //~v111R~
//#endif                                                           //~v171R~
HELPMSG                                                            //~v111I~
"ex 7. %s abc %cr\n",0,PGM,CMDFLAG_PREFIX);                        //~v140R~
HELPMSG                                                            //~v111I~
"   ==>retore file from subfile described on abc._~!\n",           //~v111R~
"   ==>統合制御ファイル abc._~! の記述に従って戻す\n");            //~v131R~
HELPMSG                                                            //~va49I~
"      %s %cr abc xyz\n",0,PGM,CMDFLAG_PREFIX);                    //~va49I~
HELPMSG                                                            //~va49I~
"   ==>retore file from subfile described on abc._~! to targetfile:xyz\n",//~va49I~
"   ==>統合制御ファイル abc._~! の記述に従って戻す,復元ファイル名はxyzにする\n");//~va49I~
//#ifdef UNX                                                       //~v171R~
//#else                                                            //~v171R~
HELPMSG                                                            //~v131I~
"ex 8. %s abc a: %c#2\n",0,PGM,CMDFLAG_PREFIX);                    //~v140R~
HELPMSG                                                            //~v131I~
"   ==>output retry for drive no 2 only.\n",                       //~v131R~
"   ==>ディスクＮｏ２だけ再出力する\n");                           //~v132R~
HELPMSG                                                            //~v131I~
"ex 9. %s abc a: %c#8-\n",0,PGM,CMDFLAG_PREFIX);                   //~v140R~
HELPMSG                                                            //~v131I~
"   ==>split restart from drive no 8.\n",                          //~v131R~
"   ==>ディスクＮｏ８から出力再開始\n");                           //~v132R~
HELPMSG                                                            //~va1FI~
//"ex 10. %s abc abc.a? 1000 %cyr %cs+5\"Frame start\"\n",0,PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va21R~
"ex 10. %s abc abc.a? 1000 %cyr %cs+5s\"Frame start\"\n",0,PGM,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va21R~
HELPMSG                                                            //~va1FI~
"   ==>split by record count,record start line is identified by col.5-15.\n",//~va1FI~
"   ==>レコード数で分割。レコード開始行は5-15桁目で判定。\n");     //~va1FR~
//#endif                                                           //~v171R~
}//help
