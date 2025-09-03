//*CID://+vau0R~:                             update#=  642;       //~vau0R~
//***********************************************************
//* xfg     : grep for binary file                                 //~v118R~
//***********************************************************
//vau0:250706 xfg1.21 add option to skip invalid filename warning  //~vau0I~
//vas6:230709 sjis on help is not printable when /n9               //~vas6I~
//vas5:230709 do not beep for help                                 //~vas5I~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//van5:200518 xfg 1.21:(Bug) xfg -exxx "" dir -->search current dir by fullpath of "".//~van5I~
//van2:200420 xfg 1.21:(Win:Bug)redirect filename(c:\xfg2) is protected now//~van2I~
//van1:200420 xfg 1.21:(Bug)err msg:specify word and file when -e parm.//~van1I~
//van0:200419 xfg 1.21:search word by CPU8/CPLC                    //~van0I~
//vak4:180824 xfg 1.20: allow space between "-e" and grep string   //~vak4I~
//vak3:180824 xfg 1.20: grep hung when srchword start with "-"     //~vak3I~
//vad2:170107 xfg v1.19 crash when longfilename                    //~vad2I~
//vab0:161127 xfg1.18:do not apply wild card filemask to ddirname  //~vab0I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va9y:160310 xfg 1.16 support multiple filename mask to include   //~va9yI~
//va9x:160309 xfg 1.16 support filename mask to exclude search     //~va9xI~
//va9w:160227 LNX compiler warning                                 //~va9wI~
//va9v:150725 xfg v1.15 display search directory                   //~va9vI~
//va9r:150529 xfg v1.14 parm count error(by xuerpck)               //~va9rI~
//va76:130622 v1.13 compiler warning and err by ndk-r9             //~va76I~
//va72:130618 (LNX)strerr is LOCALE base,dont use with uerrmsg(SJIS)//~va72I~
//va71:130618 (W32)dirwalk support windows slink/junction/mountpoint//~va71I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va50:110817 xfg:1.11 ARM                                         //~va50I~
//va39:070611 xfg:1.10 accept filename concatinated by seperator (":"-UNX,";"-DOS)  when -c option specified//~va39I~
//va2k:060901 xfg:1.9 (BUG) when case insensitive,serach fail if not both case cahr found//~va2kI~
//va2h:060520 xfg:1.8 unicode string search option                 //~va2hI~
//va2d:051116 xfg:v1.7(BUG)search string setup err when search string end with \Xxx//~va2dI~
//va2b:050609 xfg:v1.6 change main return code from file count to 0 for xe dcmd rc chk//~va2bI~
//va26:050425 xfg:v1.6:use helpmsg for uerrmsg to stop by screen full//~va26I~
//va23:050222 xfg:v1.5:(UNX:BUG)skip slink option dropped by v124  //~va23I~
//va1U 050114 xfg:v1.5 -E and -F is exclusive                      //~va1SI~
//va1T 050114 xfg:v1.5 for the case search string start by "-"(not flag parm)//~va1SI~
//va1S 050114 xfg:v1.5 warning "-" start parm after pos parm       //~va1SI~
//va1R 050114 xfg:v1.5 (BUG)reject flag combined                   //~va1QI~
//va1Q 050114 xfg:v1.5 (BUG)grep word should be enclosed if |/& is contained//~va1PI~
//va1P 050114 xfg:v1.5 (BUG)grepword displayed as null             //~va1NI~
//va1N 050114 xfg:v1.5 display grep system() msg by /v option      //~va1LI~
//va1L 050114 xfg:v1.5 (BUG)grep fail if &/| used (-E parm required)//~va1LI~
//va1K 050112 xfg:v1.5 (BUG)not found if -e parm exist             //~va1KI~
//*va1b:040102 xfg:v1.4:display string parm to stdout              //~va1bI~
//*va13:031027 xfg:add dir depth optin                             //~va13I~
//030510 xfg:v1.3 v129 use system() for grep \|,spawn dose not work//~v129I~
//030510 xfg:v1.3 v128 \x should be 1 byte                         //~v128I~
//030505 xfg:v1.3 v127 (BUG)grep msg is always FLAG_OR             //~v127I~
//030105 xfg:v1.2 v126 (BUG of v124)stoplevel set miss             //~v125I~
//021214 xfg:v1.2 v125 no performance up effect by setting curdir  //~v125I~
//021210 xfg:v1.2 v124 recoding using udirwalk function            //~v124R~
//                wildcard apply also to top level file(same as unx shell expansion)//~v124I~
//021207 xfg:v1.2 v123 performance tuning(for stat call by udirlist)//~v123I~
//020714 xfg:v1.2 v122 memory trace option                         //~v122I~
//020710 xfg:v1.2 v121 slink loop chk                              //~v121I~
//020704 xfg:v1.2 v120 (!UNX) "*:"(all drive) support at up#315    //~v120I~
//011006 xfg:v11k by xuerpck tool(uerrmsg parm chk)                //~v11kI~
//011006 xfg:v11i (BUG)ufstat return not found when root dir for not unix//~v11iI~
//011005 xfg:v11i (BUG)/S is dup for size and slink                //~v11gI~
//011005 xfg:v11h errmsg correct                                   //~v11gI~
//010922 xfg:v11g grep expression is by -e parm                    //~v11fI~
//010917 xfg:v11f (BUG) -r ignored if no wildcard match file on 1st level//~v11fI~
//010914 xfg:v11e stat.h required for S_ISLNK for LINUX            //~v11eI~
//010913 xfg:v11d grep expression support                          //~v11dI~
//010913 xfg:v11c no slink bypass msg when no msgoption            //~v11bI~
//010910 xfg:v11b (BUG)bin file ctr=0                              //~v11bI~
//010910 xfg:v11a UNX:protect symbolic link loop(skip slink entry) //~v11aI~
//010909 xfg:v119 support grep only(no bin serach) by grep word    //~v119I~
//010909 xfg:v118 and/or concatination on search word by \& or \|  //~v118I~
//010909 xfg:v117 not found msg for wildcard filespec              //~v117I~
//010909 xfg:v116 chk all flag is before filename                  //~v116I~
//010909 xfg:v115 (BUG)file count err when wile not found.         //~v115I~
//010720 v114: Not found msg option                                //~v114I~
//010720 v113: (BUG) when no file member found(dir only)           //~v113I~
//010716 v112: wild card for also subdir                           //~v112I~
//010630 v1.1: multiple string                                     //~v1.1I~
//***********************************************************
//**********************************************/
//*parm  : see help()                          */
//*return: 0:normal                            */
//*        else error                          */
//**********************************************/
//***********************************************************
#define VER "V1.22"  //version                                     //~vau0R~
#define PGMID   "xfg"                                              //~v1.1R~
#ifdef DOS                                                         //~v11fI~
	#define RBUFFSZ 16384                                          //~v11fI~
#else                                                              //~v11fI~
#define RBUFFSZ 32760
#endif                                                             //~v11fI~
//*************************************************************
#ifdef UNX                                                         //~v1.1I~
#else                                                              //~v1.1I~
  #ifdef OS2                                                       //~v11fI~
  #else                                                            //~v11fI~
    #include <dos.h>                                               //~v1.1I~
  #endif                                                           //~v11fI~
	#include <process.h>                                           //~v1.1I~
    #ifdef DOS                                                     //~v1.1R~
	    #include <errno.h>                                         //~v11fI~
    #else                                                          //~v1.1R~
        #ifdef W32                                                 //~v1.1R~
        #else                                                      //~v1.1R~
        #endif                                                     //~v1.1R~
    #endif                                                         //~v1.1R~
#endif                                                             //~v1.1I~
//*************************************************************
#include <time.h>     
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    
#include <string.h>   
#ifdef UNX                                                         //~v11eI~
	#include <sys/stat.h>                                          //~v11eI~
#endif                                                             //~v11eI~

#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>                                                //~v1.1I~
#include <ufile.h>
#include <ufile2.h>                                                //~v11dR~
#include <ufile4.h>                                                //~v11dI~
#include <ufile5.h>                                                //~va9xI~
//#include <ukbd.h>                                                //~v11fR~
#include <uproc.h>                                                 //~v1.1I~
#include <uedit.h>                                                 //~v118I~
#ifdef UNX
    #include <ugcclib.h>
#else                                                              //~v120I~
    #include <udos2.h>                                             //~v120I~
#endif
    #include <udbcschk.h>                                          //~va2hI~
    #include <ucvucs.h>                                            //~va2hI~
    #include <utrace.h>                                            //~va2hI~
    #include <uque.h>                                              //~va9xI~
    #include <utf.h>                                               //~van0R~
    #include <ustring.h>                                           //~va9xI~
//*********************************************************************
#define MAXWORDNO       100                                        //~v1.1R~
#define MAXWORDLEN      127                                        //~v1.1I~
#define FLAG_AND   '&'//'*'                                        //~v118R~
#define FLAG_OR    '|'//'+'                                        //~v118R~
#ifndef UNX                                                        //~v120I~
	#define DRIVE_ALL  "*:"                                        //~v120I~
#endif                                                             //~v120I~
#ifdef UNX                                                         //~va39I~
	#define STR_SEPC ':'                                           //~va39I~
#else                                                              //~va39I~
	#define STR_SEPC ';'                                           //~va39I~
#endif                                                             //~va39I~
//*********************************************************************
typedef struct _MASKLIST {                                         //~va9xI~
					   UQUEE MLqh;                                 //~va9xI~
                       char  MLname[1];                            //~va9xI~
                       } MASKLIST,*PMASKLIST;                      //~va9xI~
#define MASKLISTSZ sizeof(MASKLIST)                                //~va9xI~
//******************************************************************//~va9xI~
static char Sbuff[RBUFFSZ+MAXWORDLEN];                             //~v1.1R~
static int  Srecsz=RBUFFSZ;                                        //~0B15R~
static unsigned char *Sword[MAXWORDNO];		   //search string     //~v1.1R~
static unsigned char *Sgrepword;		   //search string         //~v1.1I~
static int            Sgrepwordlen=0;      //search string         //~v127R~
static unsigned char Stempfnm[_MAX_PATH];   	   //search string //~v11dR~
static int Sch1[MAXWORDNO],Sch2[MAXWORDNO];        //for case compare//~v1.1R~
static UCHAR Sboundary[MAXWORDNO][MAXWORDLEN];       //boundary chk//~v1.1I~
static int   Sreslen[MAXWORDNO];       //boundary chk              //~v1.1I~
static int  Swordno=0;	                                           //~v11gR~
static int  Swordlen=0;			//for grep string                  //~v11gR~
static int  Sbinfctr=0;                                            //~v11gR~
static int  Sbinfctrsw=0;                                          //~v11bI~
static int  Scaseisw;		//case insensitive comapre
static int  Srecursw;		//dir recursive sw                     //~v1.1I~
static int  Srecurdepth=0;		//dir recursive depth              //~va13I~
static int  Stextsw;		//text file only                       //~v1.1I~
static int  Snomsgsw=1;		//no notfound msg                      //~v114I~
static int  Sgrepmsgsw=0;                                          //~va1NI~
static int  Ssubdirexistsw=0; //detected subdir without -r         //~v1.1R~
#ifdef UNX                                                         //~v11aI~
static int  Sskipslinksw=0; //skip symbolic link                   //~v11aI~
  #ifdef LNX                                                       //~v124I~
	static int  Scdsw=0;                                           //~v124I~
  #else                                                            //~v124I~
    static int  Scdsw=0;                                           //~v125R~
  #endif                                                           //~v124I~
#endif                                                             //~v11aI~
#ifdef W32                                                         //~va71R~
static int  Sskipslinksw=0; //skip symbolic link                   //~va71R~
#endif                                                             //~va71R~
//static int  Sdispoffs;  	//display matched offset               //~v1.1R~
static int  Sdispall;  		//display not found member also        //~0B15I~
static int  Sgrepsw;  		//display line                         //~v1.1I~
static int  Sgrepflagsw=0;  //grep parm contain flags              //~va1LI~
static char *Sgrepflag=""; //grep parm contain flags               //~vak3R~
static int  Sgreponlysw;	//skip bin search                      //~v119I~
static int Suerrmsgopt=0;                                          //~v1.1R~
static	char Spgmver[18];                                          //~v1.1I~
static int Stempexistsw=0;                                         //~v11dR~
static int Sunicodesw=0;                                           //~va2hI~
static int Stestsw=0;                                              //~v122I~
static int Smatchcnt=0,Sfilectr=0;                                 //~v124I~
static char Sfilemask[_MAX_PATH]="";                               //~v124I~
static UQUEH Sqhxmask; //exclude mask que header                   //~va9xI~
static UQUEH Sqhimask; //include mask que header                   //~va9yI~
static int Sswxmask;                                               //~va9xI~
static int Sswimask;                                               //~va9yI~
static int Sswgrepsub;                                             //~vak3I~
static int langID=0;                                               //~van0I~
    #define LANGID_CPU8  1                                         //~van0M~
    #define LANGID_CPLC  2                                         //~van0I~
    #define LANG_CPU8  "CPU8"                                      //~van0M~
    #define LANG_CPLC  "CPLC"                                      //~van0M~
//************
//int xsssub(char *Pfnm,int *Pfilectr,int *Pmatchctr);             //~v124R~
int xsssub(char *Pfnm);                                            //~v124I~
int  fileproc(char *Pfilename);                                    //~v11aR~
int wordchk(char *Pword);                                          //~v118I~
FILE *openinput(char*);            //wild card file open
int  getinput(FILE *Pfh,char *Pfnm);                               //~v1.1R~
int  listgen(char*,PUDIRLIST*);             //create sorted file list//~v112R~
int grepsub(char *Pfnm);                                           //~v1.1I~
void skipslinkmsg(char *Pfnm);                                     //~v11aI~
int printtemp(void);                                               //~v11dI~
void help(void);
int fileproc0(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,     //~v124I~
                                int Pdepth,void *Pdata,int *Prc);  //~v124I~
char *xfgenclosegrepstring(char *Pword);                           //~va1QI~
void stackMask(UQUEH *Ppqh,char *Pmask);                           //~va9xI~
//int chkMask(int Popt,UQUEH *Ppqh,char *Pmask);                   //~vab0R~
int chkMask(int Popt,UQUEH *Ppqh,PUDIRLIST Ppudl);                 //~vab0I~
#define CMO_NOEXPAND 0x01                                          //~va9xI~
#define CMO_EXCEPTDIR 0x02                                         //~vab0I~
void printxmask();                                                 //~va9xI~
void printimask();                                                 //~va9yI~
int chkLang(void);                                                 //~van0I~
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *cptr,*inpfnm;         //char ptr work                    //~v118R~
	char *pc;                                                      //~v127I~
    int  fnmstart=0;                                               //~va50R~
	char ch;                                                       //~v1.1R~
	int  ii=0,pos;                                                 //~va50R~
    int len;                                                       //~v127I~
	int parmno; //parm count work
	int posparmno=0; //parm count work
	int fnmwarnsw=0;                                               //~v124I~
    int flagendsw=0;                                               //~va1SI~
#ifndef UNX                                                        //~v120I~
    int didctr;                                                    //~v120I~
    char didlist[26];                                              //~v120I~
#endif                                                             //~v120I~
    char fpath[_MAX_PATH];                                         //~v124I~
    char fnm1[_MAX_PATH],*pfnm,*pfnme;                             //~va39I~
    int fnmlen,concatnamesw=0,concatnamewarnsw=0;                  //~va39R~
    int swexpression=0;                                            //~vak4I~
    int opt;                                                       //~van0I~
//*************************
	sprintf(Spgmver,"%s:%s:",PGMID,VER);                           //~v1.1R~
	UTRACE_INIT("utrace.xfg",1);        //TODO test                //~van0I~
	opt=UDCWCIO_INTERNAL;	//bypass UDBCSCHK_EXPLICIT and utfucsmapinit(0);//~van0I~
//#ifdef LNX                                                       //~vas3R~
//    opt|=UDCWCIO_LOCALICU;  //TODO test to select Pjmsg of uerrmsg//~vas3R~
//#endif                                                           //~vas3R~
    udbcschk_wcinit(opt,0);                                        //~va6//~van0I~
  	uerrmsg_init(Spgmver,stdout,0);//default color                 //~v1.1R~
	uerrexit_init(Spgmver,stdout,0,0,0);//no mapfile,no exit,no exit parm//~v1.1R~

  	if (parmc<2) //no parm
  	{
    	help();
//  	exit(4);                                                   //~vas5R~
    	return 0;                                                  //~vas5I~
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
        if (!*cptr)                                                //~van5I~
        	continue;                                              //~van5I~
#ifdef UNX                                                         //~0B16I~
  		if(*cptr=='-'                                              //~v116R~
#else                                                              //~0B16I~
  		if((*cptr=='/'||*cptr=='-')                                //~v116R~
#endif                                                             //~0B16I~
//      && posparmno<=1)                                           //~va1SR~
        && !flagendsw   //for the case search string start by "-"  //~va1SI~
        && !swexpression                                           //~vak4I~
        && !posparmno)                                             //~va1SR~
  		{//option
            UTRACEP("main parm chk cptr=%s\n",cptr);               //~van0M~
    		ch=*(++cptr);                      //first option byte
            if (!stricmp(cptr,LANG_CPU8))                          //~van0M~
            {                                                      //~van0M~
            	langID=LANGID_CPU8;                                //~van0M~
                continue;                                          //~van0M~
            }                                                      //~van0M~
            if (!stricmp(cptr,LANG_CPLC))                          //~van0M~
            {                                                      //~van0M~
            	langID=LANGID_CPLC;                                //~van0M~
                continue;                                          //~van0M~
            }                                                      //~van0M~
    		if (*(++cptr)==':')               // /o:x format       //~va1NR~
      			cptr++;                         //skip :
            ch=(UCHAR)toupper(ch);                                 //~v11fR~
    		switch(ch)       //option                              //~v1.1R~
    		{
//**************************                                       //~va39I~
//* egrep word    /C*                                              //~va39I~
//**************************                                       //~va39I~
    		case 'C':                                              //~va39I~
    			concatnamesw=1;	//filename concatinated by seperator//~va39I~
      			break;                                             //~va39I~
//**************************                                       //~v11dI~
//* egrep word    /E*                                              //~v11fR~
//**************************                                       //~v11dI~
    		case 'E':                                              //~v11fR~
                if (!*cptr)                                        //~vak4I~
                {                                                  //~vak4I~
                	swexpression=1;                                //~vak4I~
                    break;                                         //~vak4I~
                }                                                  //~vak4I~
	  			Sgrepword=cptr;                                    //~v11dI~
                Sgrepsw=1;                                         //~v11fR~
                if (*cptr)                                         //~v11dI~
                {                                                  //~va1LI~
                	Sgrepsw=2;                                     //~v11dI~
                    Sgrepflagsw=(*cptr=='-');	//contain flag parm//~va1LI~
                    Sgrepword=xfgenclosegrepstring(cptr);          //~va1QI~
                    Sgrepwordlen=(int)strlen(Sgrepword);           //~va1PR~
                }                                                  //~va1LI~
      			break;                                             //~v11dI~
//**************************                                       //~v124I~
//* filename mask  /F      *                                       //~v124I~
//**************************                                       //~v124I~
            case 'F':           //apply to file                    //~v124I~
//              strcpy(Sfilemask,cptr);                            //~v124I~//~va9yR~
      			stackMask(&Sqhimask,cptr);                         //~va9yI~
      			Sswimask=1;                                        //~va9yI~
                break;                                             //~v124I~
//**************************
//* help msg      /H*
//**************************
    		case '?':
    		case 'H':
	  			help();
//    			exit(4);                                           //~vas5R~
      			exit(0);                                           //~vas5I~
      			break;
//**************************                                       //~v114I~
//* not found msg /M                                               //~v114I~
//**************************                                       //~v114I~
    		case 'M':                                              //~v114I~
      			Snomsgsw=0;                                        //~v114I~
      			break;                                             //~v114I~
//**************************                                       //~va1SI~
//* flag endsw       /P                                            //~va1SI~
//**************************                                       //~va1SI~
    		case 'P':                                              //~va1SI~
      			flagendsw=1;                                       //~va1SI~
      			break;                                             //~va1SI~
//**************************                                       //~va1NI~
//* grep string msg  /V                                            //~va1NI~
//**************************                                       //~va1NI~
    		case 'V':                                              //~va1NI~
      			Sgrepmsgsw=1;                                      //~va1NI~
      			break;                                             //~va1NI~
		    case 'X':           //exclude mask                     //~va9xI~
      			stackMask(&Sqhxmask,cptr);                         //~va9xR~
      			Sswxmask=1;                                        //~va9xI~
      			break;                                             //~va9xI~
//**************************
//* buff size for test                                             //~0B15R~
//**************************
//  		case 'S':                                              //~v11gR~
    		case 'Z':                                              //~v11gI~
	  			Srecsz=atoi(cptr);
                if (Srecsz<=0||Srecsz>RBUFFSZ)
					uerrexit("Invalid buffszie(%s)",
								"バッファサイズエラー(%s)",
								parmp[parmno]);
      			break;
//**************************                                       //~v1.1I~
//* additional word                                                //~v1.1I~
//**************************                                       //~v1.1I~
//            case 'W':                                            //~v118R~
//                ch=*cptr++;                                      //~v118R~
//                switch(ch)                                       //~v118R~
//                {                                                //~v118R~
//                case FLAG_AND:                                   //~v118R~
//                case FLAG_OR:                                    //~v118R~
//                    break;                                       //~v118R~
//                default:                                         //~v118R~
//                    uerrexit("Specify \"%c\"(or) or \"%c\"(and) prefix to word on /w",//~v118R~
//                            "追加の文字列(/w)には\"%c\"(or) か \"%c\"(and)を付けてください",//~v118R~
//                            FLAG_OR,FLAG_AND);                   //~v118R~
//                }                                                //~v118R~
//                if (Swordno>=MAXWORDNO)                          //~v118R~
//                    uerrexit("too many search word,max is %d",   //~v118R~
//                            "探索文字列指定は最大 %d です",      //~v118R~
//                            MAXWORDNO);                          //~v118R~
//                len=strlen(cptr);                                //~v118R~
//                if (len>MAXWORDLEN)                              //~v118R~
//                    uerrexit("Max wordlen is %d",                //~v118R~
//                            "探索文字の最大長は %d",             //~v118R~
//                                MAXWORDLEN);                     //~v118R~
//                Sword[Swordno]=word=malloc(len+3);  //and/or+len+sz//~v118R~
//                Swordlen+=len+3;                                 //~v118R~
//                Swordno++;                                       //~v118R~
//                *word=ch;                                        //~v118R~
//                *(word+1)=(UCHAR)len;                            //~v118R~
//                strcpy(word+2,cptr);                             //~v118R~
//                break;                                           //~v118R~
//**************************
//* set option     */Y
//**************************
   	 		case 'Y':
	  			while (*cptr)
	  			{
	      			switch (toupper(*cptr))
    	  			{
//                    case 'O':   //offset disply for test         //~v1.1R~
//                        Sdispoffs=1;                             //~v1.1R~
//                        break;                                   //~v1.1R~
#ifdef UNX                                                         //~v124I~
                    case 'C':   //cd for udirlist performance up   //~v124I~
                      	Scdsw=1;                                   //~v124I~
                        break;                                     //~v124I~
                    case 'I':   //invalid filename                 //~vau0I~
						Gufile_opt&=~GFILEOPT_NOWILDERRMSG ;  //skip filename invalid warning for wildname//~va77I~//~vau0I~
                        break;                                     //~vau0I~
#endif                                                             //~v124I~
	      			case 'T':   //test option                      //~v122I~
						Stestsw=1;                                 //~v122I~
	        			break;                                     //~v122I~
	      			case '9':   //offset disply for test           //~0B15I~
						Suerrmsgopt=(Suerrmsgopt & ~UERR_FORCE_ENGLISH);//~0B15I~
    					uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//msg to stdout//~v1.1R~
	        			break;                                     //~0B15I~
	      			default:
						uerrexit("\nToggle Set parm(%s) err",
								"\nトグル設定(%s)エラー",
								parmp[parmno]);
	      			}//switch by /Nx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* reset option     */N
//**************************
    		case 'N':
	  			while (*cptr)
	  			{
	      			switch (toupper(*cptr))
    	  			{
//                    case 'O':                                    //~v1.1R~
//                        Sdispoffs=0;                             //~v1.1R~
//                        break;                                   //~v1.1R~
#ifdef UNX                                                         //~v124I~
                    case 'C':   //cd for udirlist performance up   //~v124I~
                      	Scdsw=0;                                   //~v124I~
                        break;                                     //~v124I~
                    case 'I':   //invalid filename                 //~vau0I~
						Gufile_opt|=GFILEOPT_NOWILDERRMSG ;  //skip filename invalid warning for wildname//~vau0I~
                        break;                                     //~vau0I~
#endif                                                             //~v124I~
	      			case 'T':   //test option                      //~v122I~
						Stestsw=0;                                 //~v122I~
                        break;                                     //~v125I~
	      			case '9':   //offset disply for test           //~0B15I~
						Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);//~0B15I~
    					uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//msg to stdout//~v1.1R~
	        			break;                                     //~0B15I~
	      			default:
						uerrexit("\nToggle Reset parm(%s) err",
									"\nトグル設定解除(%s)エラー",
									parmp[parmno]);
	      			}//switch by /Nx
			  		cptr++;                                        //~v1.1R~
      			}//until strlen
      			break;
//**************************
//* option err             *
//**************************
    		default:                           //not option
                for (;ch;ch=*cptr++)                               //~v1.1R~
                {                                                  //~v1.1I~
                    switch(toupper(ch))       //option             //~v1.1I~
                    {                                              //~v1.1I~
                    case 'A':   //list also not found member       //~v1.1I~
                        Sdispall=1;                                //~v1.1I~
                        break;                                     //~v1.1I~
                    case 'G':   //recursive grerp only             //~v11fR~
                        if (!Sgrepsw)	//if /e not specified      //~v11fI~
                        	Sgrepsw=1;                             //~v11fR~
                        break;                                     //~v11fR~
//                  case 'L':   //list lines                       //~v11dR~
//                      Sgrepsw=1;                                 //~v11dR~
//                      break;                                     //~v11dR~
                    case 'I':   //case insensitive                 //~v1.1I~
                        Scaseisw=1;                                //~v1.1I~
                        break;                                     //~v1.1I~
		    		case 'M':                                      //~va1QI~
      					Snomsgsw=0;                                //~va1QI~
      					break;                                     //~va1QI~
    				case 'P':                                      //~va1SI~
      					flagendsw=1;                               //~va1SI~
      					break;                                     //~va1SI~
                    case 'R':   //case insensitive                 //~v1.1I~
                        Srecursw=1;                                //~v1.1I~
                        if (*cptr>='0' && *cptr<='9')              //~va13I~
                        {                                          //~va13I~
                        	Srecurdepth=atoi(cptr);                //~va13I~
							cptr+=unumlen(cptr,0,(int)strlen(cptr));//~va13I~
                        }                                          //~va13I~
                        break;                                     //~v1.1I~
//#ifdef UNX                                                         //~v11aI~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71R~
                    case 'S':   //no symbolic link process         //~v11bR~
                        Sskipslinksw=1;                            //~v11aI~
                        break;                                     //~v11aI~
#endif                                                             //~v11aI~
                    case 'T':   //case insensitive                 //~v1.1I~
                        Stextsw=1;                                 //~v1.1I~
                        break;                                     //~v1.1I~
    				case 'U':                                      //~va2hI~
      					Sunicodesw=1;                              //~va2hI~
      					break;                                     //~va2hI~
		    		case 'V':                                      //~va1QI~
      					Sgrepmsgsw=1;                              //~va1QI~
      					break;                                     //~va1QI~
                    default:                                       //~v1.1I~
                        uerrexit("\nundefined option parm(%c),use %cp if this is search string start by \"-\" or \"/\".",//~va1SR~
                                "\n%c は認識できません,探索文字列が\"-\"または\"/\"で始まるときは %cp を使用してください。",//~va1SR~
                                    ch,CMDFLAG_PREFIX);            //~va1SR~
                    }//switch  by first option byte                //~v1.1R~
        		}//for                                             //~v1.1R~
            }//switch                                              //~v1.1I~
  		}
  		else
  		{//positional parmno
        	if (swexpression)                                      //~vak4I~
            {                                                      //~vak4I~
	  			Sgrepword=cptr;                                    //~vak4I~
                Sgrepsw=2;                                         //~vak4I~
                Sgrepflagsw=(*cptr=='-');	//contain flag parm    //~vak4I~
                Sgrepword=xfgenclosegrepstring(cptr);              //~vak4I~
                Sgrepwordlen=(int)strlen(Sgrepword);               //~vak4I~
                swexpression=0;                                    //~vak4I~
                continue;                                          //~vak4I~
            }                                                      //~vak4I~
            if (Sgrepsw==2)                                        //~van1R~
                posparmno++;    //it is 1st pos parm               //~van1R~
    		posparmno++;
    		switch (posparmno)
    		{
//**************************
//* word                   *
//**************************
    		case  1:          //first parm
//                len=strlen(cptr);                                //~v118R~
//                if (len>MAXWORDLEN)                              //~v118R~
//                    uerrexit("Max wordlen is %d",                //~v118R~
//                            "探索文字の最大長は %d",             //~v118R~
//                                MAXWORDLEN);                     //~v118R~
//                Sword[Swordno]=word=malloc(len+3);  //and/or+len+sz//~v118R~
//                Swordlen+=len+3;                                 //~v118R~
//                Swordno++;                                       //~v118R~
//                *word=FLAG_OR;                                   //~v118R~
//                *(word+1)=(UCHAR)len;                            //~v118R~
//                strcpy(word+2,cptr);                             //~v118R~
//              Sgrepword=cptr;	//for the case grep only           //~v11dR~
				wordchk(cptr);                                     //~v118I~
      			break;
//**************************
//* dir/file               *
//**************************
    		case  2:          //first parm
                fnmstart=parmno;                                   //~v1.1I~
      			break;
//************************************
    		}//switch by parmno
  		}//option or posparm
	}//for all parm
  	if (Stestsw)                                                   //~v122I~
    	ualloc_init(UALLOC_TRACE,"xfg.mtr");                       //~v122I~//~vak3R~
//***no pos parm chk
	if (posparmno<2)                                               //~v1.1R~
//  	uerrexit("search-word and dir/file-name parm required.",   //~vak3R~
//  			"探索文字列と入力ファイル或いはディレクトリーを指定して下さい");//~vak3R~
    	uerrexit("search-word and dir/file-name parm required.\n"  //~vak3I~
#ifdef W32                                                         //~vak3I~
    			"   (Use %cp for searchword starting with \"-\" or \"/\".)",//~vak3R~
#else                                                              //~vak3I~
    			"   (Use %cp for searchword starting with \"-\".)",//~vak3R~
#endif                                                             //~vak3I~
    			"探索文字列と入力ファイル或いはディレクトリーを指定して下さい\n"//~vak3R~
#ifdef W32                                                         //~vak3I~
    			"   探索文字列が \"-\" か \"/\" で始まるときは %cp で指定してください",//~vak3R~
#else                                                              //~vak3I~
    			"   探索文字列が \"-\" で始まるときは %cp で指定してください",//~vak3R~
#endif                                                             //~vak3I~
						CMDFLAG_PREFIX);                           //~vak3I~
    if (!Swordno)                                                  //~v11dI~
    {                                                              //~v11dI~
    	if (Sgrepsw!=2)	//no grep word                             //~v11dI~
        	uerrexit("Spevify Search-word(1st parm)  or grep expression(%ce parm)",//~v11fR~
                     "探索文字列(第一）ないしは grep 式(%ce)パラメータを指定する。",//~v11fR~
						CMDFLAG_PREFIX);                           //~v11dI~
        Sgreponlysw=1;                                             //~v11dI~
#ifdef UNX                                                         //~v11dI~
        utempnam("/tmp","xfg",Stempfnm);                           //~v11dI~
#else                                                              //~v11dI~
//      utempnam("c:\\","xfg",Stempfnm);                           //~v11eR~//~van2R~
        utempnam("","xfg",Stempfnm);                               //~van2I~
#endif                                                             //~v11dI~
        UTRACEP("tempfname=%s\n",Stempfnm);                        //~van2I~
    }                                                              //~v11dI~
                                                                   //~v11dI~
	if (Sgrepsw)// grep option                                     //~va2hI~
    {                                                              //~va2hI~
    	if (Sunicodesw)                                            //~va2hI~
        	uerrexit("grep option and unicode option is mutualy exclusive",//~va2hI~
                     "grerp オプションとユニコードオプションは同時指定できません");//~va2hI~
    }                                                              //~va2hI~
    if (chkLang())                                                 //~van0I~
    	return 4;                                                  //~van0I~
//if (!Sgreponlysw)                                                //~v11dR~
//if (Sgrepsw!=2)// /G with no word                                //~va1KR~
  if (!Sgreponlysw)                                                //~va1KI~
  {                                                                //~v119I~
//init for case compare                                            //~v1.1I~
	for (ii=0;ii<Swordno;ii++)	                                   //~v1.1I~
    {                                                              //~v1.1I~
    	Sch1[ii]=*(Sword[ii]+2);                                   //~v1.1R~
    	if (Scaseisw)                                              //~v1.1I~
    	{                                                          //~v1.1I~
    		if ((Sch2[ii]=toupper(Sch1[ii]))==Sch1[ii])            //~v1.1I~
    			Sch2[ii]=tolower(Sch1[ii]);                        //~v1.1I~
    	}                                                          //~v1.1I~
    	else                                                       //~v1.1I~
    		Sch2[ii]=Sch1[ii];                                     //~v1.1I~
    }                                                              //~v1.1I~
  }                                                                //~va1KI~
//string for grep                                                  //~v1.1I~
  if (Sgrepsw!=2)// /G with no word                                //~va1KI~
  {                                                                //~va1KI~
    Sgrepword=malloc((UINT)Swordlen*2);                            //~v11fR~
    if (ii==1)                                                     //~v1.1I~
    {                                                              //~v127I~
    	strcpy(Sgrepword,Sword[0]+2);                              //~v1.1I~
        Sgrepwordlen=(int)(*(Sword[0]+1));                         //~v127I~
    }                                                              //~v127I~
    else                                                           //~v1.1I~
    {                                                              //~v118I~
        for (ii=0,pos=0;ii<Swordno;ii++)                           //~v1.1R~
        {                                                          //~v1.1R~
//            if (ii+1<Swordno && *Sword[ii+1]==FLAG_AND)          //~v11fR~
//            {                                                    //~v11fR~
//                if (ii+2<Swordno && *Sword[ii+2]==FLAG_AND)      //~v11fR~
//                    uerrexit("Only 1 \"AND\" concatination allowed.",//~v11fR~
//                            "AND連結は1つまでです。");           //~v11fR~
//                pos+=sprintf(Sgrepword+pos,"%s.*%s\\|%s.*%s",    //~v11fR~
//                        Sword[ii]+2,Sword[ii+1]+2,Sword[ii+1]+2,Sword[ii]+2);//~v11fR~
//                ii++;   //skip to next of next                   //~v11fR~
//            }                                                    //~v11fR~
//            else                                                 //~v11fR~
//          	pos+=sprintf(Sgrepword+pos,"%s",Sword[ii]+2);      //~v127R~
            len=(int)(*(Sword[ii]+1));                             //~v127I~
            memcpy(Sgrepword+pos,Sword[ii]+2,(UINT)len);           //~v127R~
            pos+=len;                                              //~v127R~
	        Sgrepwordlen+=len;                                     //~v127R~
            if (ii!=Swordno-1)	//not last                         //~v1.1I~
            {                                                      //~v127I~
//              pos+=sprintf(Sgrepword+pos,"\\|");                 //~va1LR~
                pos+=sprintf(Sgrepword+pos,"|");                   //~va1LI~
                Sgrepwordlen+=2;                                   //~v127R~
            }                                                      //~v127I~
            else                                                   //~v127I~
                *(Sgrepword+pos)=0;                                //~v127I~
        }                                                          //~v1.1R~
    }                                                              //~v118I~
  }//not grep only                                                 //~v119I~
//multifile process                                                //~v1.1I~
//******************************************************************//~va9vI~
  {//display parm filename                                         //~va9vI~
  	int fnmstartsave;                                              //~va9vI~
    //*********************                                        //~va9vI~
    fnmstartsave=fnmstart;                                         //~va9vI~
    for (;inpfnm=parmp[fnmstart],inpfnm;fnmstart++)                //~va9vI~
    {                                                              //~va9vI~
#ifndef UNX                                                        //~va9vI~
      if (!memcmp(inpfnm,DRIVE_ALL,sizeof(DRIVE_ALL)-1))           //~va9vI~
      {                                                            //~va9vI~
		didctr=ugetdriveidlist(UDDC_FIXED,didlist);                //~va9vI~
        for (ii=0;ii<didctr;ii++)                                  //~va9vI~
        {                                                          //~va9vI~
            *inpfnm=didlist[ii];                                   //~va9vI~
			ufullpath(fpath,inpfnm,sizeof(fpath));                 //~va9vI~
//      	xsssub(fpath);                                         //~va9vI~
			printf("***** %s\n",fpath);                            //~va9vI~
        }                                                          //~va9vI~
      }                                                            //~va9vI~
      else                                                         //~va9vI~
      {                                                            //~va9vI~
#endif                                                             //~va9vI~
//#ifdef UNX                                                       //~va9vI~
//        if (*inpfnm==CMDFLAG_PREFIX)                             //~va9vI~
//#else                                                            //~va9vI~
//        if (*inpfnm==CMDFLAG_PREFIX                              //~va9vI~
//        ||  *inpfnm==CMDFLAG_PREFIX2)                            //~va9vI~
//#endif                                                           //~va9vI~
//            fnmwarnsw=1;        //isuue warning cmd flag sequence//~va9vI~
      if (concatnamesw)	//filename concatinated by seperator       //~va9vI~
      {                                                            //~va9vI~
      	for (pfnm=inpfnm;pfnm;)                                    //~va9vI~
        {                                                          //~va9vI~
        	pfnm+=strspn(pfnm," ");                                //~va9vI~
			pfnme=strchr(pfnm,STR_SEPC);	//colon or semi-colon  //~va9vI~
			if (pfnme)                                             //~va9vI~
            	fnmlen=(int)((ULPTR)pfnme-(ULPTR)pfnm);            //~va9vI~
            else                                                   //~va9vI~
            	fnmlen=(int)strlen(pfnm);                          //~va9vI~
            memcpy(fnm1,pfnm,(UINT)fnmlen);                        //~va9vI~
            *(fnm1+fnmlen)=0;                                      //~va9vI~
			ufullpath(fpath,fnm1,sizeof(fpath));                   //~va9vI~
//  		xsssub(fpath);                                         //~va9vI~
			printf("***** %s\n",fpath);                            //~va9vI~
            if (!pfnme)                                            //~va9vI~
            	break;                                             //~va9vI~
            pfnm=pfnme+1;                                          //~va9vI~
        }                                                          //~va9vI~
      }                                                            //~va9vI~
      else                                                         //~va9vI~
      {                                                            //~va9vI~
//  	if (strchr(inpfnm,STR_SEPC))	//colon or semi-colon      //~va9vI~
//      	concatnamewarnsw=1;                                    //~va9vI~
		ufullpath(fpath,inpfnm,sizeof(fpath));                     //~va9vI~
//  	xsssub(fpath);                                             //~va9vI~
		printf("***** %s\n",fpath);                                //~va9vI~
      }                                                            //~va9vI~
#ifndef UNX                                                        //~va9vI~
      }                                                            //~va9vI~
#endif                                                             //~va9vI~
    }                                                              //~va9vI~
    fnmstart=fnmstartsave;                                         //~va9vI~
  }//diaplay parm file                                             //~va9vI~
//******************************************************************//~va9vI~
    for (;inpfnm=parmp[fnmstart],inpfnm;fnmstart++)                //~v1.1R~
    {                                                              //~v1.1I~
#ifndef UNX                                                        //~v120I~
      if (!memcmp(inpfnm,DRIVE_ALL,sizeof(DRIVE_ALL)-1))           //~v120R~
      {                                                            //~v120I~
		didctr=ugetdriveidlist(UDDC_FIXED,didlist);                //~v120I~
        for (ii=0;ii<didctr;ii++)                                  //~v120R~
        {                                                          //~v120R~
            *inpfnm=didlist[ii];                                   //~v120R~
//      	xsssub(inpfnm,&filectr,&matchcnt);                     //~v124R~
			ufullpath(fpath,inpfnm,sizeof(fpath));                 //~v124I~
        	xsssub(fpath);                                         //~v124R~
//  	    totfile+=filectr;                                      //~v124R~
//      	totmatch+=matchcnt;                                    //~v124R~
        }                                                          //~v120I~
      }                                                            //~v120I~
      else                                                         //~v120I~
      {                                                            //~v120I~
#endif                                                             //~v120I~
//  	xsssub(inpfnm,&filectr,&matchcnt);                         //~v124R~
#ifdef UNX                                                         //~v124M~
    	if (*inpfnm==CMDFLAG_PREFIX)                               //~v124I~
#else                                                              //~v124M~
    	if (*inpfnm==CMDFLAG_PREFIX                                //~v124I~
    	||  *inpfnm==CMDFLAG_PREFIX2)                              //~v124I~
#endif                                                             //~v124M~
			fnmwarnsw=1;		//isuue warning cmd flag sequence  //~v124I~
      if (concatnamesw)	//filename concatinated by seperator       //~va39I~
      {                                                            //~va39I~
      	for (pfnm=inpfnm;pfnm;)                                    //~va39I~
        {                                                          //~va39I~
        	pfnm+=strspn(pfnm," ");                                //~va39R~
			pfnme=strchr(pfnm,STR_SEPC);	//colon or semi-colon  //~va39R~
			if (pfnme)                                             //~va39R~
//          	fnmlen=(int)((ULONG)pfnme-(ULONG)pfnm);            //~va39I~//~va66R~
            	fnmlen=(int)((ULPTR)pfnme-(ULPTR)pfnm);            //~va66I~
            else                                                   //~va39I~
            	fnmlen=(int)strlen(pfnm);                          //~va39R~
            memcpy(fnm1,pfnm,(UINT)fnmlen);                        //~va39R~
            *(fnm1+fnmlen)=0;                                      //~va39I~
			ufullpath(fpath,fnm1,sizeof(fpath));                   //~va39I~
    		xsssub(fpath);                                         //~va39I~
            if (!pfnme)                                            //~va39I~
            	break;                                             //~va39I~
            pfnm=pfnme+1;                                          //~va39I~
        }                                                          //~va39I~
      }                                                            //~va39I~
      else                                                         //~va39I~
      {                                                            //~va39I~
		if (strchr(inpfnm,STR_SEPC))	//colon or semi-colon      //~va39I~
	    	concatnamewarnsw=1;                                    //~va39I~
		ufullpath(fpath,inpfnm,sizeof(fpath));                     //~v124I~
    	xsssub(fpath);                                             //~v124R~
      }                                                            //~va39I~
//      totfile+=filectr;                                          //~v124R~
//      totmatch+=matchcnt;                                        //~v124R~
#ifndef UNX                                                        //~v120I~
      }                                                            //~v120R~
#endif                                                             //~v120I~
    }                                                              //~v1.1I~

    printf("**********************\n");                            //~v1.1R~
    if (Ssubdirexistsw)                                            //~v1.1I~
    	uerrmsg("  (To search subdir use -r option.)\n",           //~v118R~
        	    "  (サブディレクトリー内も探索するには -r オプションが必要です.)\n");//~v118R~
                                                                   //~v1.1I~
	if (concatnamewarnsw)                                          //~va39I~
    	uerrmsg("  (%cc option required for \"%c\" separated filespec.)",//~va39R~
    	        "  (%cc を \"%c\" 連結のファイル指定の時は指定する必要があります)",//~va39R~
					CMDFLAG_PREFIX,STR_SEPC);                      //~va39I~
	if (fnmwarnsw)		//isuue warning cmd flag sequence          //~v124R~
#ifdef UNX                                                         //~v124I~
//  	uerrmsg("  (Warning:detected file name with starting char is %c)\n",//~v124I~//~vak3R~
//      	    "  (注意: %c で始まるファイル名の指定が有ります。)\n",//~v125R~//~vak3R~
    	uerrmsg("  (Warning:detected file name with starting char is \"%c\",\n and all option parameters have to be before filespec.)\n",//~vak3R~
        	    "  (注意: \"%c\" で始まるファイル名の指定が有ります\nまたすべての Option パラメータはファイル指定の前に指定します)\n",//~vak3R~
					CMDFLAG_PREFIX);                               //~v124I~
#else                                                              //~v124I~
//  	uerrmsg("  (Warning:detected file name with starting char is %c or %c)\n",//~v124I~//~vak3R~
//      	    "  (注意: %c , %c で始まるファイル名の指定が有ります。)\n",//~v125R~//~vak3R~
    	uerrmsg("  (Warning:detected file name with starting char is \"%c\" or \"%c\",\n and all option parameters have to be before filespec.)\n",//~vak3R~
        	    "  (注意: \"%c\" , \"%c\" で始まるファイル名の指定が有ります\nまたすべての Option パラメータはファイル指定の前に指定します)\n",//~vak3R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX2);               //~v124I~
#endif                                                             //~v124I~
//  printf("grep = \"%s\"\n",Sgrepword);                           //~v127R~
  	if (Sgrepsw)                                                   //~v127I~
	if (Sswgrepsub)                                                //~vak3I~
    {                                                              //~v127I~
//  	printf("grep = \"");                                       //~v127I~//~vak3R~
    	printf("grep := %s ",Sgrepflag);                           //~vak3R~
        for (ii=0,pc=Sgrepword;ii<Sgrepwordlen;ii++,pc++)          //~v127I~
        {                                                          //~v127I~
        	if (!*pc)                                              //~v129I~
            	break;                                             //~v129I~
        	if (*pc>=' ')                                          //~v127R~
            	printf("%c",*pc);                                  //~v127I~
            else                                                   //~v127I~
            	printf("\\x%02x",*pc);                             //~v127I~
                                                                   //~v127I~
        }                                                          //~v127M~
//  	printf("\"\n");                                            //~v127I~//~vak3R~
    	printf("\n");                                              //~vak3I~
    }                                                              //~v127I~
//    for (ii=0;ii<Swordno;ii++)                                   //~v1.1R~
//        if (!ii)                                                 //~v1.1R~
//            printf("\"%s\"",Sword[0]+2);                         //~v1.1R~
//        else                                                     //~v1.1R~
//            if (*Sword[ii]==FLAG_OR)                             //~v1.1R~
//                printf(" or \"%s\"",Sword[ii]+2);                //~v1.1R~
//            else                                                 //~v1.1R~
//                printf(" and \"%s\"",Sword[ii]+2);               //~v1.1R~
//    printf("\n");                                                //~v1.1R~
	if (Sgreponlysw)                                               //~v11dI~
    	if (Stempexistsw)                                          //~v11dI~
	  		uremove(Stempfnm);                                     //~v11dR~
  	uerrmsg_init("",stdout,0);//default color                      //~v1.1I~
  if (Sbinfctrsw)                                                  //~v11bI~
    uerrmsg("-- %d / %d ( %d binary) files selected.",             //~v1.1R~
            "-- %d / %d ( %d binary) 個のファイルに含まれています.",//~v1.1R~
//    			totmatch,totfile,Sbinfctr);                        //~v124R~
      			Smatchcnt,Sfilectr,Sbinfctr);                      //~v124I~
  else                                                             //~v11bI~
    uerrmsg("-- %d / %d files selected.",                          //~v11bI~
            "-- %d / %d 個のファイルに含まれています.",            //~v11bI~
//    			totmatch,totfile);                                 //~v124R~
//    			Smatchcnt,Sfilectr,Sbinfctr);                      //~v124I~//~va9rR~
      			Smatchcnt,Sfilectr);                               //~va9rI~
    printimask();                                                  //~va9yI~
    printxmask();                                                  //~va9xI~
  	if (Stestsw)                                                   //~v122I~
	    ualloc_chk(UAC_MSG);                                       //~v122R~
    UTRACEP("%s:return\n",UTT);                                    //~vas3I~
//return matchcnt;                                                 //~v124R~
//return Smatchcnt;                                                //~va2bR~
	ARMXSUB_CLOSE(PGMID);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3I~
  return 0;                                                        //~va2bI~
}//end main
//**********************************************************************//~v118I~
//* analyze search word                                            //~v118I~
//**********************************************************************//~v118I~
int wordchk(char *Pword)                                           //~v118I~
{                                                                  //~v118I~
	char *pc,*pce,*pcs,*pcp,*word,*pcx;                            //~v118R~
//  int  ii,len,concatflag,concatflag_prev=FLAG_OR,escch;	       //~va50R~
    int  ii,len,concatflag=0,concatflag_prev=FLAG_OR,escch=0;      //~va50R~
    char ucsstr[MAXWORDLEN+MAXWORDLEN];                            //~va2hR~
    int opt,chklen,outlen,errctr;                                  //~va2hR~
#ifdef LNX                                                         //~va2hI~
    char sjisstr[MAXWORDLEN];                                      //~va2hI~
    int sjislen;                                                   //~va2hI~
#endif                                                             //~va2hI~
//*********************                                            //~v118I~
	pce=Pword+strlen(Pword);                                       //~v118I~
    for (pc=Pword,pcs=pc;pc<pce;pc++)                              //~va50R~
    {                                                              //~v118I~
    	pc=strchr(pc,'\\');                                        //~v118I~
        if (pc)                                                    //~v118I~
        {                                                          //~v118I~
        	pcp=pc;                                                //~v118I~
            concatflag=*(pc+1);                                    //~v118R~
    		switch(concatflag)                                     //~v118I~
		    {                                                      //~v118I~
    		case FLAG_AND:                                         //~v118I~
    		case FLAG_OR:                                          //~v118I~
            	pc++;       //flag addr                            //~v118R~
        		break;                                             //~v118I~
            default:                                               //~v118I~
                switch(concatflag)                                 //~v118I~
                {                                                  //~v118I~
                case 'a':                                          //~v118I~
                	escch='\a';                                    //~v118I~
                    break;                                         //~v118I~
                case 'b':                                          //~v118I~
                	escch='\b';                                    //~v118I~
                    break;                                         //~v118I~
                case 'f':                                          //~v118I~
                	escch='\f';                                    //~v118I~
                    break;                                         //~v118I~
                case 'n':                                          //~v118I~
                	escch='\n';                                    //~v118I~
                    break;                                         //~v118I~
                case 'r':                                          //~v118I~
                	escch='\r';                                    //~v118I~
                    break;                                         //~v118I~
                case 't':                                          //~v118I~
                	escch='\t';                                    //~v118I~
                    break;                                         //~v118I~
                case 'v':                                          //~v118I~
                	escch='v';                                     //~v118I~
                    break;                                         //~v118I~
                case '\\':                                         //~v118I~
                    escch='\\';                                    //~v118I~
                    break;                                         //~v118I~
                case 'x':                                          //~v118I~
                	pcx=pc;	                                       //~v118R~
                    pc+=2;                                         //~v118I~
//                  len=(int)unumlen(pc,UNUMLEN_HEX,(int)strlen(pc));//~v128R~
                    len=(int)strlen(pc);                           //~v128I~
                    if (len>2)                                     //~v128I~
                        len=2;                                     //~v128I~
                    len=(int)unumlen(pc,UNUMLEN_HEX,len);          //~v128I~
                    for (ii=0;ii<len;ii+=2,pc+=2)                  //~v118I~
                    {                                              //~v118I~
                    	ugethex(pc,pcx,2);                         //~v118R~
                        pcx++;                                     //~v118R~
                    }                                              //~v118I~
                    pcp=pcx;                                       //~v118I~
                    if (*pc)    //not eol                          //~v118I~
                    {                                              //~v118I~
                    	strcpy(pcp,pc);                            //~v118R~
                    	pce=pcp+strlen(pcp);                       //~v118R~
                    	pc=pcp-1;	//for loop pc++                //~v118R~
                    	continue;                                  //~v118R~
                    }                                              //~v118I~
                    else                                           //~va2dI~
                        *pcp=0;                                    //~va2dI~
                    break;                                         //~v118I~
                default:                                           //~v118I~
                	continue;                                      //~v118I~
                }                                                  //~v118I~
                if (concatflag!='x')                               //~v118I~
                {                                                  //~v118I~
                    pcp=pc++;                                      //~v118R~
                    *pcp++=(UCHAR)escch;                           //~v11fR~
                    strcpy(pcp,pc+1);                              //~v118R~
                    if (*pcp)    //not eol                         //~v118R~
                    {                                              //~v118R~
                        pce--;                                     //~v118R~
                        pc=pcp-1;                                  //~v118R~
                        continue;                                  //~v118R~
                    }                                              //~v118R~
                }                                                  //~v118I~
                break;                                             //~v118I~
            }//after \\ //                                         //~v118R~
    	}//\\ found                                                //~v118R~
        else                                                       //~v118I~
        	pcp=pc=pce;                                            //~v118R~
        if (Swordno>=MAXWORDNO)                                    //~v118I~
            uerrexit("too many search word,max is %d",             //~v118I~
                    "探索文字列指定は最大 %d です",                //~v118I~
                    MAXWORDNO);                                    //~v118I~
//      len=(int)((ULONG)pcp-(ULONG)pcs);                          //~v11fR~//~va66R~
        len=(int)((ULPTR)pcp-(ULPTR)pcs);                          //~va66I~
        if (len>MAXWORDLEN)                                        //~v118I~
            uerrexit("Max wordlen is %d for each",                 //~v118I~
                    "探索文字列の最大長はそれぞれ %d",             //~v118I~
                        MAXWORDLEN);                               //~v118I~
        if (Sunicodesw)                                            //~va2hI~
        {                                                          //~va2hI~
        	opt=0;                                                 //~va2hI~
#ifdef LNX                                                         //~va2hI~
			ueuc2shift(pcs,0,len,sjisstr,0,&sjislen,opt);          //~va2hI~
    		opt|=UCVUCS_LE;		//little endian                    //~va2hI~
    		opt|=UCVUCS_CPMS932;	//MS932                        //~va2hI~
//			ucvssjis2ucs(0,opt,sjisstr,sjislen,ucsstr,sizeof(ucsstr),&chklen,&outlen,&errctr);//~va2hR~//~va9wR~
  			ucvssjis2ucs(0,(ULONG)opt,sjisstr,sjislen,ucsstr,sizeof(ucsstr),&chklen,&outlen,&errctr);//~va9wI~
#else                                                              //~va2hI~
	#ifdef AIX                                                     //~va2hI~
    		opt|=UCVUCS_CP943C;		//IBM932C                      //~va2hI~
    #else                                                          //~va2hI~
    		opt|=UCVUCS_CPMS932;	//MS932                        //~va2hI~
    		opt|=UCVUCS_LE;		//little endian                    //~va2hI~
    #endif                                                         //~va2hR~
			ucvssjis2ucs(0,(ULONG)opt,pcs,len,ucsstr,sizeof(ucsstr),&chklen,&outlen,&errctr);//~va2hR~
#endif                                                             //~va2hI~
			pcs=ucsstr;                                            //~va2hI~
			len=outlen;                                            //~va2hI~
        }                                                          //~va2hI~
//UTRACED("Word",pcs,len);                                         //~va2hR~
        Sword[Swordno]=word=malloc((UINT)(len+3));  //and/or+len+sz//~v11fR~
        Swordlen+=len+3;                                           //~v118I~
        Swordno++;                                                 //~v118I~
        *word=(UCHAR)concatflag_prev;                              //~v11fR~
        *(word+1)=(UCHAR)len;                                      //~v118I~
        memcpy(word+2,pcs,(UINT)len);                              //~v118I~
        *(word+2+len)=0;		//sz                               //~v118I~
        pcs=pc+1;	//net word top                                 //~v118R~
        concatflag_prev=concatflag;                                //~v118I~
//printf("%s\n",Sword[Swordno-1]);                                 //~v119R~
    }//all string                                                  //~v118I~
	printf("********** Search parm=%s **********\n",Pword);        //~va1bR~
    return 0;                                                      //~v118I~
}//wordchk                                                         //~v118I~
//**********************************************************************//~va1QI~
//* enclose grep word                                              //~va1QI~
//**********************************************************************//~va1QI~
char *xfgenclosegrepstring(char *Pword)                            //~va1QI~
{                                                                  //~va1QI~
	char *pc,*pce,*pc2,*word,*gword;                               //~va1QR~
    int  len,len2=0,len3;                                          //~va1QR~
//*********************                                            //~va1QI~
	pce=Pword+strlen(Pword);                                       //~va1QI~
	for (pc=Pword;pc<pce;)                                         //~va1QI~
    {                                                              //~va1QI~
    	if (*pc!='-')                                              //~va1QI~
            break;                                                 //~va1QI~
        pc2=strchr(pc,' ');                                        //~va1QI~
        if (!pc2)                                                  //~va1QR~
            break;                                                 //~va1QI~
//  	len2=(int)((ULONG)pc2-(ULONG)Pword);                       //~va1QR~//~va66R~
    	len2=(int)((ULPTR)pc2-(ULPTR)Pword);                       //~va66I~
        pc=pc2+strspn(pc2," ");                                    //~va1QI~
	}                                                              //~va1QI~
    if (pc==Pword)  //no flags                                     //~va1QI~
        return Pword;                                              //~va1QI~
    word=pc;                                                       //~va1QI~
    len3=(int)strlen(word);                                        //~va1QI~
    len=len3+2+len2+4;                                             //~va1QI~
    gword=malloc((UINT)len);                                       //~va1QI~
    memcpy(gword,Pword,(UINT)len2);                                //~va1NR~
    sprintf(gword+len2," \"%s\"",word);                            //~va1QI~
    return gword;                                                  //~va1QI~
}//xfgenclosegrepstring                                            //~va1QI~
//**********************************                               //~v1.1M~
//* xsssub                                                         //~v1.1R~
//**********************************                               //~v1.1M~
//int xsssub(char *Pfnm,int *Pfilectr,int *Pmatchctr)              //~v124R~
int xsssub(char *Pfnm)                                             //~v124I~
{                                                                  //~v1.1I~
	int  dirsw,pathlen;                                            //~v124R~
//  int wildsw;                                                    //~v125R~
    int dwopt,stoplevel,applrc;                                    //~v124R~
    FILEFINDBUF3 fstat3={0};                                           //~v1.1I~//~va64R~
    char fpath[_MAX_PATH+32];                                      //~v124R~
//  char wildspec[_MAX_PATH];                                      //~v11fR~
    char wildspec[_MAX_PATH]="";                                   //~v11gR~
//**********************                                           //~v1.1I~
    UTRACEP("%s:Pfnm=%s\n",UTT,Pfnm);                              //~vas3I~
//  *Pfilectr=0;                                                   //~v124R~
//  *Pmatchctr=0;                                                  //~v124R~
//printf("sssub pfnm=%s\n",Pfnm);                                  //~v124R~
//  ufullpath(fpath,Pfnm,sizeof(fpath));                           //~v124R~
    strcpy(fpath,Pfnm);                                            //~v124I~
    dwopt=   UDIRWALK_FILECALL      //callback by each file        //~v124R~
    		|UDIRWALK_DIRCALL       //callback by each dir         //~v124I~
//  		|UDIRWALK_EMPTYCALL     //callback for empty dir       //~v124I~
//          |UDIRWALK_SORT_NAME     //sort by name                 //~v124R~
//  		|UDIRWALK_EOLCALL       //callback for end of list     //~v124R~
            ;                                                      //~v124I~
                                                                   //~v124I~
#ifdef UNX                                                         //~v124I~
    if (Scdsw)                                                     //~v124I~
		dwopt|=UDIRWALK_TEMPCD;       //change dir for udirlist performance//~v124I~
	if (Sskipslinksw)                                              //~va23I~
        dwopt|=UDIRWALK_SKIPSLINK;                                 //~va23I~
#endif                                                             //~v124I~
#ifdef W32                                                         //~va71R~
	if (Sskipslinksw)                                              //~va71R~
        dwopt|=UDIRWALK_SKIPSLINK;                                 //~va71R~
#endif                                                             //~va71R~
	if (Snomsgsw)		//no notfound msg                          //~v124I~
    {                                                              //~va71R~
	    dwopt|=UDIRWALK_NOMSG;           //no err msg              //~v124R~
        Gufile_opt|= GFILEOPT_NOSLINKERRMSG;                       //~va71R~
    }                                                              //~va71R~
    dirsw=1;                                                       //~v1.1R~
//  wildsw=0;                                                      //~v125R~
//printf("sssub fnm=%s\n",fpath);                                  //~v124R~
    if (WILDCARD(fpath))//not wild card                            //~v1.1R~
    {                                                              //~v112I~
//      wildsw=1;                                                  //~v125R~
        pathlen=PATHLEN(fpath);                                    //~v1.1I~
//      strcpy(wildspec,fpath+pathlen-1);	//save wildcard specification from dir_sepc//~v124R~
        strcpy(wildspec,fpath+pathlen);	//save wildcard specification from dir_sepc//~v124I~
        *(fpath+pathlen)=0;                                        //~v124I~
        if (!ROOTDIR(fpath))                                       //~v124I~
        	*(fpath+pathlen-1)=0;                                  //~v124I~
        dwopt|=UDIRWALK_TOPMASK;      //select dir only for top level//~v124I~
    }                                                              //~v112I~
    else                                                           //~v1.1I~
    {                                                              //~v1.1I~
        pathlen=(int)strlen(fpath);                                //~v11fR~
        if (ROOTDIR(fpath))                                        //~v11iI~
//     		fstat3.attrFile |= FILE_DIRECTORY;                     //~va23R~
       		fstat3.attrFile  = FILE_DIRECTORY;                     //~va23I~
//    	if (ufstat(fpath,&fstat3))                                 //~v11iR~
      	if (!ROOTDIR(fpath) && ufstat(fpath,&fstat3))              //~v11iI~
        {                                                          //~v1.1I~
		  if (!Snomsgsw)		//no notfound msg                  //~v124I~
            uerrmsg("%s not found",0,                              //~v1.1I~
                    fpath);                                        //~v1.1I~
            return 4;                                              //~v1.1I~
        }                                                          //~v1.1I~
        else                                                       //~v1.1I~
        {                                                          //~v11aI~
//     		if ((fstat3.attrFile & FILE_DIRECTORY))                //~va1NR~
//              if (ROOTDIR(fpath))                                //~v124R~
//              	strcpy(fpath+pathlen,DIR_ALLMEMB);             //~v124R~
//              else                                               //~v124R~
//              	strcpy(fpath+pathlen++,DIR_SEPS DIR_ALLMEMB);  //~v124R~
//              ;                                                  //~va1NR~
//          else                                                   //~va1NR~
       		if (!(fstat3.attrFile & FILE_DIRECTORY))               //~va1NI~
            {                                                      //~va23I~
//#ifdef UNX                                                         //~va23I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~//~va71R~
				if (Sskipslinksw)                                  //~va23I~
//                  if (S_ISLNK(FILE_GETMODE(fstat3.attrFile)))    //~va23R~//~va71R~
                    if (FILE_ISSLINK(fstat3.attrFile))             //~va71R~
                    	return 0;	//bypass process               //~va23I~
#endif                                                             //~va23I~
         		dirsw=0;                                           //~v1.1I~
            }                                                      //~va23I~
        }                                                          //~v11aI~
    }                                                              //~v1.1I~
    if (!dirsw)                                                    //~v1.1I~
    {                                                              //~v1.1I~
// 		matchcnt+=fileproc(fpath);                                 //~v124R~
   		Smatchcnt+=fileproc(fpath);                                //~v124I~
//      filectr++;                                                 //~v124R~
    }                                                              //~v1.1I~
    else                                                           //~v1.1I~
    {                                                              //~v1.1I~
//        listctr=listgen(fpath,&pudirlist);//create file list     //~v124R~
//      if (listctr>0)                                             //~v124R~
//      {                                                          //~v124R~
//        pudirlist0=pudirlist;   //save for free                  //~v124R~
//        for (ii=0;ii<listctr;ii++,pudirlist++)                   //~v124R~
//        {                                                        //~v124R~
//            curfnm=pudirlist->name;                              //~v124R~
//            if (!strcmp(curfnm,"."))                             //~v124R~
//                continue;                                        //~v124R~
//            if (!strcmp(curfnm,".."))                            //~v124R~
//                continue;                                        //~v124R~
//            if (strlen(curfnm)+pathlen>=_MAX_PATH)               //~v124R~
//            {                                                    //~v124R~
//                uerrmsg("Too long filename; %.*s%s",0,           //~v124R~
//                        pathlen,fpath,curfnm);                   //~v124R~
//                continue;                                        //~v124R~
//            }                                                    //~v124R~
//            strcpy(fpath+pathlen,curfnm);                        //~v124R~
//#ifdef UNX                                                       //~v124R~
//          if (Sskipslinksw                                       //~v124R~
//          &&  S_ISLNK(FILE_GETMODE(pudirlist->attr)))            //~v124R~
//                skipslinkmsg(fpath);                             //~v124R~
//          else                                                   //~v124R~
//          {                                                      //~v124R~
//#endif                                                           //~v124R~
//            if (pudirlist->attr & FILE_DIRECTORY)                //~v124R~
//            {                                                    //~v124R~
//              if (!wildsw)  //later for wildcard                 //~v124R~
//              {                                                  //~v124R~
//                if (Srecursw)                                    //~v124R~
//                    xsssub(fpath,&fctr,&mctr),filectr+=fctr,matchcnt+=mctr;//~v124R~
//                else                                             //~v124R~
//                    Ssubdirexistsw=1;                            //~v124R~
//              }                                                  //~v124R~
//                continue;                                        //~v124R~
//            }                                                    //~v124R~
//            matchcnt+=fileproc(fpath);                           //~v124R~
//#ifdef UNX                                                       //~v124R~
//          }//slink skip chk                                      //~v124R~
//#endif                                                           //~v124R~
//            filectr++;                                           //~v124R~
//        }//all input file spec                                   //~v124R~
//        ufree(pudirlist0);                                       //~v124R~
//      }//listgen ok                                              //~v124R~
//      else                                                       //~v124R~
//      {                                                          //~v124R~
//        if (!wildsw) //wildcard                                  //~v124R~
//        {                                                        //~v124R~
//            uerrmsg("%s not found",0,                            //~v124R~
//                    fpath);                                      //~v124R~
//            return 4;                                            //~v124R~
//        }                                                        //~v124R~
//      }                                                          //~v124R~
//        if (wildsw) //wildcard                                   //~v124R~
//        {                                                        //~v124R~
//            strcpy(fpath+pathlen,DIR_ALLMEMB);                   //~v124R~
////            if (listctr>0)                                     //~v124R~
////            {                                                  //~v124R~
//                listctr=listgen(fpath,&pudirlist);//create file list//~v124R~
//                if (listctr<=0)                                  //~v124R~
//                {                                                //~v124R~
//                    uerrmsg("%s not found",0,                    //~v124R~
//                            fpath);                              //~v124R~
//                    return 4;                                    //~v124R~
//                }                                                //~v124R~
//                pudirlist0=pudirlist;   //save for free          //~v124R~
//                for (ii=0;ii<listctr;ii++,pudirlist++)           //~v124R~
//                {                                                //~v124R~
//                    curfnm=pudirlist->name;                      //~v124R~
//                    if (!strcmp(curfnm,"."))                     //~v124R~
//                        continue;                                //~v124R~
//                    if (!strcmp(curfnm,".."))                    //~v124R~
//                        continue;                                //~v124R~
//                    if (strlen(curfnm)+pathlen+strlen(wildspec)>=_MAX_PATH)//~v124R~
//                    {                                            //~v124R~
//                        uerrmsg("Too long filename; %.*s%s%s",0, //~v124R~
//                                pathlen,fpath,curfnm,wildspec);  //~v124R~
//                        continue;                                //~v124R~
//                    }                                            //~v124R~
//                    if (pudirlist->attr & FILE_DIRECTORY)        //~v124R~
//                    {                                            //~v124R~
//                        strcpy(fpath+pathlen,curfnm);            //~v124R~
//                        strcat(fpath,wildspec);                  //~v124R~
//                        if (Srecursw)                            //~v124R~
//                            xsssub(fpath,&fctr,&mctr),filectr+=fctr,matchcnt+=mctr;//~v124R~
//                        else                                     //~v124R~
//                            Ssubdirexistsw=1;                    //~v124R~
//                    }                                            //~v124R~
//                }//all input file spec                           //~v124R~
//                ufree(pudirlist0);                               //~v124R~
////            }//listgen ok                                      //~v124R~
//        }//wildcard                                              //~v124R~
//  	if (Srecursw)                                              //~v125R~
    	if (!Srecursw)                                             //~v125I~
        	stoplevel=2;         //to chk subdir                   //~v124I~
        else                                                       //~v124I~
          if (Srecurdepth)                                         //~va13I~
            stoplevel=Srecurdepth;                                 //~va13I~
          else                                                     //~va13I~
        	stoplevel=32767;                                       //~v124I~
        udirwalk(dwopt,                                            //~v124R~
                        fpath,            //top dirname            //~v124I~
                        wildspec,       //dir mask                 //~v124I~
                        Sfilemask,      //file mask                //~v124I~
                        FILE_ALL-FILE_DIRECTORY,        //attr mask//~v124I~
                        stoplevel,          //stop depth,half max  //~v124I~
                        fileproc0,      //callback function        //~v124I~
                        0,              //user data                //~v124I~
                        &applrc);                                  //~v124I~
    }                                                              //~v1.1I~
//  *Pfilectr=filectr;*Pmatchctr=matchcnt;                         //~v124R~
    return 0;                                                      //~v1.1I~
}//xsssub                                                          //~v1.1R~
//**********************************************************************//~v124I~
//* fileproc0                                                      //~v124I~
//*  parm1:dir name                                                //~v124I~
//*  parm2:fullpathname,0 if dir entry,or empty call               //~v124I~
//*  parm3:PUDIRLIST,0 if empty entry                              //~v124I~
//*  parm4:depth                                                   //~v124I~
//*  parm5:appl data                                               //~v124I~
//*  parm6:appl rc area                                            //~v124I~
//*  return:0:continue walk,else stop walk                         //~v124I~
//**********************************************************************//~v124I~
int fileproc0(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,     //~v124I~
                                int Pdepth,void *Pdata,int *Prc)   //~v124I~
{                                                                  //~v124I~
    int rc=0;                                                      //~v124I~
//**************************                                       //~v124I~
//  printf("@@@@ depth=%d:dir=%s,fullpath=%s,dirlist name=%s\n",Pdepth,Pdir,((Pfullpath==(char*)(-1))?0:Pfullpath),Ppudirlist?Ppudirlist->name:"null");//@@@@test//~va9xR~//~va9yR~
    if (Sswxmask                                                   //~va9xI~
    &&  Ppudirlist                                                 //~va9xI~
//  && chkMask(CMO_NOEXPAND,&Sqhxmask,Ppudirlist->name))           //~vab0R~
    && chkMask(CMO_NOEXPAND,&Sqhxmask,Ppudirlist))                 //~vab0I~
    {                                                              //~va9xI~
//      printf("@@@2 bypass by exclude mask %s\n",Ppudirlist->name);//~va9xR~//~va9yR~
		if (!Pfullpath) //dir entry                                //~va9xI~
            rc=UDIRWALK_URC_SKIPDIR;                               //~va9xI~
        return rc;                                                 //~va9xI~
    }                                                              //~va9xI~
    if (Sswimask                                                   //~va9yI~
    &&  Pdepth  //not top level                                    //~va9yI~
    &&  Ppudirlist                                                 //~va9yI~
//  && !chkMask(CMO_NOEXPAND,&Sqhimask,Ppudirlist->name))          //~vab0R~
    && !chkMask(CMO_NOEXPAND|CMO_EXCEPTDIR,&Sqhimask,Ppudirlist))  //~vab0I~
    {                                                              //~va9yI~
//      printf("@@@1 bypass by include mask %s\n",Ppudirlist->name);//~va9yR~
		if (!Pfullpath) //dir entry                                //~va9yI~
            rc=UDIRWALK_URC_SKIPDIR;                               //~va9yI~
        return rc;                                                 //~va9yI~
    }                                                              //~va9yI~
	if (!Pfullpath) //dir entry                                    //~v124I~
    {                                                              //~v124I~
		if (!Srecursw)                                             //~v124I~
        	if (Pdepth)                                            //~v124R~
            {                                                      //~v124I~
            	rc=UDIRWALK_URC_SKIPDIR;                           //~v124I~
				Ssubdirexistsw=1;                                  //~v124I~
            }                                                      //~v124I~
    }                                                              //~v124I~
    else 	//file entry                                           //~v124I~
    {                                                              //~v124I~
		Smatchcnt+=fileproc(Pfullpath);                            //~v124R~
    }                                                              //~v124I~
	return rc;			//continue walk                            //~v124I~
}//fileproc0                                                       //~v124I~//~va9xR~
//**********************************************************************//~v1.1I~
//* main process (1 file print)                                    //~v1.1I~
//* rc:1 found,0:not found                                         //~v1.1I~
//**********************************************************************//~v1.1I~
int fileproc(char *Pfilename)                                      //~v11aR~
{                                                                  //~v1.1I~
	char *pc1,*pc2,*pbuff,*pword;                                  //~v1.1I~
    int  wordlen,reclen,complen,matchsw,reslen,binfsw=0;           //~v1.1R~
    int  ii,jj,ch1,ch2,rec1stsw;                                   //~v1.1R~
    int  matchtb[MAXWORDNO];                                       //~v1.1R~
    FILE *fh;                                                      //~v1.1I~
//*********                                                        //~v1.1I~
//bin search                                                       //~v119I~
  	fh=openinput(Pfilename);                                       //~v1.1I~
    if (!fh)    //open failed                                      //~v1.1I~
        return 0;                                                  //~v1.1I~
    Sfilectr++;                                                    //~v124I~
    matchsw=0;                                                     //~v1.1I~
    memset(matchtb,0,sizeof(matchtb));                             //~v1.1I~
    rec1stsw=0;                                                    //~v1.1I~
	while((reclen=getinput(fh,Pfilename))>0)     //until eof       //~v1.1I~
	{                                                              //~v1.1I~
        if (Stextsw||Sgrepsw)                                      //~v11dR~
            if (!rec1stsw)                                         //~v1.1R~
            {                                                      //~v1.1R~
                Sbinfctrsw=1;                                      //~v11bI~
                rec1stsw=1;                                        //~v1.1R~
                ii=min(reclen,256);                                //~v1.1R~
                for (pc1=Sbuff+MAXWORDLEN;ii>0;ii--,pc1++)         //~v1.1R~
                    if (*pc1<0x20 && *pc1!='\t' && *pc1!='\n' && *pc1!='\r')//~v1.1R~
                        break;                                     //~v1.1R~
                if (ii>0)                                          //~v1.1R~
                {                                                  //~v1.1I~
                    binfsw=1;                                      //~v1.1I~
                    Sbinfctr++;                                    //~v1.1I~
                  if (Stextsw)	//skip for bin file when text option//~v1.1I~
                    break;  //binary file                          //~v1.1R~
                }                                                  //~v1.1I~
            }                                                      //~v1.1R~
  		if (Sgreponlysw)                                           //~v119I~
        	break;                                                 //~v119I~
        for (ii=0;ii<Swordno;ii++)                                 //~v1.1I~
        {                                                          //~v1.1I~
            wordlen=(int)*(Sword[ii]+1);                           //~v1.1I~
            ch1=Sch1[ii];                                          //~v1.1R~
            ch2=Sch2[ii];                                          //~v1.1I~
//UTRACED("srch",Sword[ii]+2,wordlen);                             //~va2hR~
            pbuff=Sbuff+MAXWORDLEN;                                //~v1.1R~
			reslen=reclen;                                         //~v1.1I~
            if (Sreslen[ii])                                       //~v1.1I~
            {                                                      //~v1.1I~
            	pbuff-=Sreslen[ii];                                //~v1.1R~
            	memcpy(pbuff,Sboundary[ii],(UINT)Sreslen[ii]);     //~v11fR~
                reslen+=Sreslen[ii];                               //~v1.1I~
                Sreslen[ii]=0;                                     //~v1.1I~
            }                                                      //~v1.1I~
            for (;reslen>0 && !matchsw;)                           //~v1.1R~
            {                                                      //~v1.1I~
                pc1=memchr(pbuff,ch1,(UINT)reslen);                //~v11fR~
                if (ch2!=ch1)   //case insense and top byte lower!=uper//~v1.1R~
                {                                                  //~v1.1R~
                    pc2=memchr(pbuff,ch2,(UINT)reslen);            //~v11fR~
//                  if (pc2 && pc2<pc1)                            //~va2kR~
                    if (pc2 && (!pc1||pc2<pc1))                    //~va2kI~
                        pc1=pc2;                                   //~v1.1R~
                }                                                  //~v1.1R~
                if (!pc1)   //first char not found                 //~v1.1R~
                    break;  //read next record                     //~v1.1R~
//              reslen-=(int)((ULONG)pc1-(ULONG)pbuff);            //~v1.1I~//~va66R~
                reslen-=(int)((ULPTR)pc1-(ULPTR)pbuff);            //~va66I~
                if (wordlen>reslen)	//rec boundary                 //~v1.1I~
                {                                                  //~v1.1I~
                	Sreslen[ii]=reslen;                            //~v1.1R~
                    memcpy(Sboundary[ii],pc1,(UINT)reslen);        //~v11fR~
                    break;		//comp at next rec                 //~v1.1I~
                }                                                  //~v1.1I~
                pc1++;                                             //~v1.1R~
                reslen--;                                          //~v1.1I~
                pbuff=pc1;                                         //~v1.1R~
                complen=wordlen-1;                                 //~v1.1R~
                pword=Sword[ii]+2+1;                               //~v1.1R~
                if (Scaseisw)                                      //~v1.1I~
                    matchsw=!memicmp(pbuff,pword,(UINT)complen);   //~v11fR~
                else                                               //~v1.1I~
                    matchsw=!memcmp(pbuff,pword,(UINT)complen);    //~v11fR~
            }//in buff                                             //~v1.1I~
            if (Sreslen[ii])                                       //~v1.1I~
            	continue;		//next word                        //~v1.1I~
            if (matchsw)                                           //~v1.1I~
            {                                                      //~v1.1I~
            	matchtb[ii]=1;                                     //~v1.1I~
                if (*Sword[ii]==FLAG_OR)                           //~v1.1I~
                {                                                  //~v1.1I~
                	if (ii==Swordno-1||*Sword[ii+1]==FLAG_OR)		//next is or//~v1.1R~
                    	break;                                     //~v1.1R~
                }                                                  //~v1.1I~
                else  		//and                                  //~v1.1I~
                	if (ii==Swordno-1||*Sword[ii+1]==FLAG_OR)		//next is or//~v1.1I~
                    {                                              //~v1.1I~
                        for (jj=ii-1;jj>=0;jj--)                   //~v1.1I~
                            if (*Sword[jj]==FLAG_OR||!matchtb[jj]) //~v1.1I~
                                break;                             //~v1.1I~
                        if (jj>=0 && matchtb[jj])//all and found   //~v1.1R~
		                    break;                                 //~v1.1I~
                    }                                              //~v1.1I~
                matchsw=0;	//continue search                      //~v1.1I~
            }                                                      //~v1.1I~
        }//wordlist                                                //~v1.1I~
        if (matchsw)                                               //~v1.1I~
            break;                                                 //~v1.1I~
    }//until eof                                                   //~v1.1I~
//  if (matchsw)|Sgreponlysw)                                      //~v11dR~
    if (Sgreponlysw)                                               //~v11dI~
    {                                                              //~va1SI~
        if (binfsw)                                                //~v11dI~
            matchsw=0;                                             //~v11dI~
        else                                                       //~v11dI~
            matchsw=grepsub(Pfilename);                            //~v11dI~
    }                                                              //~va1SI~
    if (matchsw)                                                   //~v11dI~
    {                                                              //~v11dI~
        if (binfsw)                                                //~v1.1I~
            printf("==B==: %s\n",Pfilename);                       //~v1.1I~
        else                                                       //~v1.1I~
            printf("=====: %s\n",Pfilename);                       //~v1.1I~
        if (Sgreponlysw)                                           //~v11dI~
            printtemp();                                           //~v11dI~
    }                                                              //~v11dI~
    else                                                           //~v1.1I~
    	if (Sdispall)                                              //~v1.1R~
        {                                                          //~va1SI~
        	if (binfsw)                                            //~v1.1I~
	            printf("--B--: %s\n",Pfilename);                   //~v1.1R~
            else                                                   //~v1.1R~
	            printf("-----: %s\n",Pfilename);                   //~v1.1I~
        }                                                          //~va1SI~
    fclose(fh);                                                    //~v1.1I~
    if (matchsw)                                                   //~v1.1I~
        if (Sgrepsw && !Sgreponlysw)                               //~v11dR~
//        if (!binfsw)                                             //~v11fR~
            grepsub(Pfilename);                                    //~v1.1I~
	return matchsw;                                                //~v1.1I~
}//fileproc                                                        //~v1.1R~
//**********************************************************************//~v11dI~
// print temp file to stdout                                       //~v11dI~
//**********************************************************************//~v11dI~
int printtemp(void)                                                //~v11dI~
{                                                                  //~v11dI~
  	FILE *fh;                                                      //~v11dI~
//***********************                                          //~v11dI~
    fh=fopen(Stempfnm,"r");                                        //~v11dI~
    if (!fh)                                                       //~v11dI~
    {                                                              //~v11dI~
    	printf("%s open failed\n",Stempfnm);                       //~v11dI~
        return 4;	                                               //~v11dI~
    }                                                              //~v11dI~
	while (fgets(Sbuff,RBUFFSZ,fh))                                //~v11dR~
//    	printf(Sbuff);                                             //~v11dI~//~va76R~
      	printf("%s",Sbuff);                                        //~va76R~
    fclose(fh);                                                    //~v11dI~
  	return 0;                                                      //~v11dI~
}//printtemp                                                       //~v123R~
//**********************************************************************
// create sorted file list			
//**********************************************************************
int listgen(char *Pdirname,PUDIRLIST *Pppudirlist)                 //~v112R~
{
  	int fctrmax;
  	PUDIRLIST pudirlist;
//***********************
#ifdef UNX                                                         //~v123I~
	if (!uchdir(UCHD_NOMSG,Pdirname))                              //~v123I~
    	Gufile_opt|=GFILEOPT_STATCD;//issue stat by not fullpathname//~v123I~
#endif                                                             //~v123I~
    if (Snomsgsw)                                                  //~v114I~
	    fctrmax=udirlistnomsg(Pdirname,FILE_ALL,&pudirlist,'N');   //~v114I~
    else                                                           //~v114I~
		fctrmax=udirlist(Pdirname,FILE_ALL,&pudirlist,'N');        //~v114R~
#ifdef UNX                                                         //~v123I~
    Gufile_opt&=~GFILEOPT_STATCD;//issue stat by not fullpathname  //~v123I~
#endif                                                             //~v123I~
	if (fctrmax<0)                                                 //~v114I~
		return -1;                                                 //~v112R~
	*Pppudirlist=pudirlist;
  	return fctrmax;
}//listgen
//**********************************************************************
// find and open input file
//**********************************************************************
FILE *openinput(char *Ppfile)    
{
	int rc;                                                        //~v1.1I~
	FILE *fh;
//******************                                               //~v1.1I~
  	if (!(fh=fopen(Ppfile,"rb")))  //open input fail
    {                                                              //~v1.1I~
    	rc=errno;                                                  //~v1.1R~
//  	uerrmsg("\n%s open err(errno=%d:%s)",                      //~va72R~
//  				"\n%s オープンエラー(errno=%d:%s)",            //~va72R~
//  					Ppfile,rc,strerror(rc));                   //~va72R~
    	uerrmsg("\n%s open err(errno=%d)",                         //~va72I~
    				"\n%s オープンエラー(errno=%d)",               //~va72I~
    					Ppfile,rc);                                //~va72I~
    }                                                              //~v1.1I~
	return fh;
}//openinput

//**********************************************************************
//* read file
// ret: read len,-1=eof
//**********************************************************************
int getinput(FILE *Pfh,char *Pfnm)                                 //~v1.1R~
{
	int len;
//****************
	if (!(len=(int)fread(Sbuff+MAXWORDLEN,1,(UINT)Srecsz,Pfh)))	//null return if error or eof//~v11fR~
    {                                                              //~va1SI~
		if (ferror(Pfh))
			uerrexit("\n%s read error",0,Pfnm);                    //~v1.1R~
		else
			return -1;
    }                                                              //~va1SI~
	return len;
}//getinput
//**********************************************************************//~v1.1I~
//* line display by grep                                           //~v1.1I~
// ret: rc                                                         //~v1.1I~
//**********************************************************************//~v1.1I~
int grepsub(char *Pfnm)                                            //~v1.1I~
{                                                                  //~v1.1I~
//#define USE_SYS                                                  //~v1.1R~
    char flg[32],*caseid,*fixid;                                   //~va1LR~
    int rc;                                                        //~v1.1I~
//#ifdef USE_SYS                                                   //~v11dR~
//  char cmd[_MAX_PATH+16];                                        //~v1.1R~//~vad2R~
    char cmd[_MAX_PATH2+256];       //grepword   etc               //~vad2R~
//#endif                                                           //~v11dR~
	FILEFINDBUF3 ffb3;                                             //~v11dI~
    static int SswgrepwordP;	//"-" prefixed by "\\"             //~vak3I~
//****************                                                 //~v1.1M~
    Sswgrepsub=1;                                                  //~vak3I~
    fflush(stdout);                                                //~v1.1I~
    fflush(stderr);                                                //~v1.1I~
//if (Sgreponlysw)                                                 //~v11dR~
    caseid="";                                                     //~vak3I~
  if (Sgrepsw==2)                                                  //~v11dI~
        fixid="";                                                  //~v119M~
  else                                                             //~v119M~
  {                                                                //~vak3I~
    if (Swordno==1)                                                //~v1.1I~
    {                                                              //~vak3I~
      if (SswgrepwordP)                                            //~vak3I~
        fixid="";                                                  //~vak3I~
      else                                                         //~vak3I~
      if (*Sgrepword!='-')                                         //~vak3I~
        fixid="F";	//F:fgrep                                      //~v1.1I~
      else                                                         //~vak3I~
      {                                                            //~vak3I~
      	char *newword;                                             //~vak3M~
        fixid="";                                                  //~vak3I~
        newword=malloc((size_t)Sgrepwordlen+8);                    //~vak3R~
        *newword='\\';                                             //~vak3I~
        UmemcpyZ(newword+1,Sgrepword,(size_t)Sgrepwordlen);        //~vak3I~
        Sgrepword=newword;                                         //~vak3I~
        Sgrepwordlen++;                                            //~vak3I~
        SswgrepwordP=1;                                            //~vak3I~
      }                                                            //~vak3I~
    }                                                              //~vak3I~
    else                                                           //~v1.1I~
//      fixid="";                                                  //~va1SR~
        fixid="E";	//E:extended                                   //~va1SI~
    if (Scaseisw)                                                  //~v1.1I~
        caseid="i"; //i:case insensitive                           //~v1.1R~
    else                                                           //~v1.1I~
        caseid="";                                                 //~v1.1R~
    }                                                              //~vak3I~
    sprintf(flg,"-n%s%s",fixid,caseid);                            //~va1SI~
    Sgrepflag=malloc(strlen(flg)+1);                               //~vak3R~
    strcpy(Sgrepflag,flg);                                         //~vak3R~
//  strcat(flg," -E");                                             //~va1SR~
//#ifdef USE_SYS                                                   //~v11dR~
  if (Sgreponlysw)                                                 //~v11dI~
  {                                                                //~v11dI~
#ifdef UNX                                                         //~v11dI~
   if (Sgrepflagsw)                                                //~va1LI~
    sprintf(cmd,"grep %s \"%s\" >%s 2>&1",Sgrepword,Pfnm,Stempfnm);//~va1LI~
   else                                                            //~va1LI~
//  sprintf(cmd,"grep %s \"%s\" %s >%s 2>&1",flg,Sgrepword,Pfnm,Stempfnm);//~va1LR~
    sprintf(cmd,"grep %s \"%s\" \"%s\" >%s 2>&1",flg,Sgrepword,Pfnm,Stempfnm);//~va1LI~
#else                                                              //~v11dM~
   if (Sgrepflagsw)                                                //~va1LI~
    sprintf(cmd,"grep %s \"%s\" >%s",Sgrepword,Pfnm,Stempfnm);     //~va1LI~
   else                                                            //~va1LI~
//  sprintf(cmd,"grep %s \"%s\" %s >%s",flg,Sgrepword,Pfnm,Stempfnm);//~va1LR~
    sprintf(cmd,"grep %s \"%s\" \"%s\" >%s",flg,Sgrepword,Pfnm,Stempfnm);//~va1LI~
#endif                                                             //~v11dI~
	if (Stempexistsw)                                              //~v11dI~
    {                                                              //~v11dI~
	    uremove(Stempfnm);                                         //~v11dR~
        Stempexistsw=0;	                                           //~v11dI~
    }                                                              //~v11dI~
    if (Sgrepmsgsw)                                                //~va1NI~
    {                                                              //~va1NI~
    	puts(cmd);                                                 //~va1NI~
        fflush(stdout);                                            //~va1QR~
    }                                                              //~va1NI~
    rc=usystem2(UPROC_NOMSG,cmd);                                  //~v1.1R~
//printf("system rc=%d,cmd=%s\n",rc,cmd);                          //~v129R~
    Stempexistsw=1;                                                //~v11dI~
    if (!rc                                                        //~v11dI~
    &&  !ufstat(Stempfnm,&ffb3)                                    //~v11dI~
    &&  ffb3.cbFile)                                               //~v11dR~
    	rc=0;                                                      //~v11dI~
    else                                                           //~v11dI~
    	rc=4;                                                      //~v11dI~
  }                                                                //~v11dI~
//#else                                                            //~v11dR~
  else                                                             //~v11dI~
  {                                                                //~v11dI~
//  sprintf(cmd,"grep %s %s %s",flg,Sgrepword,Pfnm);               //~v129R~
//  rc=uspawnlp(P_WAIT|UPROC_NOMSG,"grep","grep",flg,Sgrepword,Pfnm,0);//~v129R~
   if (Sgrepflagsw)                                                //~va1NI~
    sprintf(cmd,"grep %s \"%s\"",Sgrepword,Pfnm);                  //~va1NI~
   else                                                            //~va1NI~
//  sprintf(cmd,"grep %s \"%s\" %s",flg,Sgrepword,Pfnm);           //~va1NR~
    sprintf(cmd,"grep %s \"%s\" \"%s\"",flg,Sgrepword,Pfnm);       //~va1NI~
    if (Sgrepmsgsw)                                                //~va1NI~
    {                                                              //~va1NI~
    	puts(cmd);                                                 //~va1NI~
        fflush(stdout);                                            //~va1QI~
    }                                                              //~va1NI~
    rc=usystem2(UPROC_NOMSG,cmd);                                  //~v129R~
//printf("%s,%s,%s\n",flg,Sgrepword,Pfnm);                         //~v129R~
  }                                                                //~v11dI~
//#endif                                                           //~v11dR~
    fflush(stdout);                                                //~v1.1I~
    fflush(stderr);                                                //~v1.1I~
//printf("flg=%s,cmd=%s,rc=%d,%s\n",flg,Sgrepword,rc,Pfnm);        //~v119R~
    return rc==0;                                                  //~v119R~
}//grepsub                                                         //~v1.1I~
//**********************************************************************//~v11aI~
//* skipslinkmsg                                                   //~v11aI~
//**********************************************************************//~v11aI~
void skipslinkmsg(char *Pfnm)                                      //~v11aI~
{                                                                  //~v11aI~
    if (Snomsgsw)                                                  //~v11cR~
        return;                                                    //~v11cR~
	uerrmsg("%s is symbolic link file,process skipped",            //~v11aI~
		    "シンボリックリンクファイル %s はバイバス",            //~v11aI~
			Pfnm);                                                 //~v11aI~
    return;                                                        //~v11aI~
}//skipslinkmsg                                                    //~v11aI~
//**********************************************************************//~va9xI~
void stackMask(UQUEH *Ppqh,char *Pmask)                            //~va9xI~
{                                                                  //~va9xI~
    int len;                                                       //~va9xI~
    PMASKLIST pfnl;                                                //~va9xI~
//*********************************                                //~va9xI~
//	len=strlen(Pmask);                                             //~va9xI~//~vaa0R~
  	len=(int)strlen(Pmask);                                        //~vaa0I~
//  pfnl=ucalloc(MASKLISTSZ+len,1);                                //~va9xI~//~vaa0R~
    pfnl=ucalloc(MASKLISTSZ+(size_t)len,1);                        //~vaa0I~
//  memcpy(pfnl->MLname,Pmask,len);                                //~va9xI~//~vaa0R~
    memcpy(pfnl->MLname,Pmask,(size_t)len);                        //~vaa0I~
	UENQ(UQUE_END,Ppqh,pfnl);                                      //~va9xI~
}//stackMask                                                       //~va9xI~
//**********************************************************************//~va9xI~
//int chkMask(int Popt,UQUEH *Ppqh,char *Pmask)                    //~vab0R~
int chkMask(int Popt,UQUEH *Ppqh,PUDIRLIST Ppudl)                  //~vab0I~
{                                                                  //~va9xI~
    int rc=0,len;                                                  //~va9xI~
    PMASKLIST pfnl=0;                                              //~va9xI~
    char *pmask,*pfnm;                                             //~va9xI~
    char wkmask[_MAX_PATH];                                        //~va9xI~
//*********************************                                //~va9xI~
//  pfnm=Pmask;                                                    //~vab0R~
    pfnm=Ppudl->name;                                              //~vab0R~
    if (Popt & CMO_NOEXPAND)	//mach with DIR_SEPC was followed case//~va9xI~
    {                                                              //~va9xI~
//      len=strlen(Pmask)-1;                                       //~va9xI~//~vaa0R~
//      len=(int)strlen(Pmask)-1;                                  //~vab0R~
        len=(int)strlen(pfnm)-1;                                   //~vab0I~
//      if (*(Pmask+len)=='/'                                      //~vab0R~
//      ||  *(Pmask+len)=='\\')                                    //~vab0R~
        if (*(pfnm+len)=='/'                                       //~vab0I~
        ||  *(pfnm+len)=='\\')                                     //~vab0I~
        {                                                          //~va9xI~
//          UmemcpyZ(wkmask,Pmask,len);                            //~va9xI~//~vaa0R~
//          UmemcpyZ(wkmask,Pmask,(size_t)len);                    //~vab0R~
            UmemcpyZ(wkmask,pfnm,(size_t)len);                     //~vab0I~
            pfnm=wkmask;                                           //~va9xI~
        }                                                          //~va9xI~
    }                                                              //~va9xI~
	for (pfnl=UGETQTOP(Ppqh);pfnl;pfnl=UGETQNEXT(pfnl))            //~va9xI~
    {                                                              //~va9xI~
    	pmask=pfnl->MLname;                                        //~va9xI~
        if (WILDCARD(pmask))                                       //~va9xI~
        {                                                          //~va9xI~
		  if ((Popt & CMO_EXCEPTDIR) && UCBITCHK(Ppudl->attr,FILE_DIRECTORY))//~vab0R~
          	rc=0;	//select                                       //~vab0I~
          else                                                     //~vab0I~
			rc=ufilewildcomp(UFWC_CASE_DEFAULT|UFWC_DOS_DEFAULT|UFWC_0BYTE,pfnm,pmask,0/*Pdbcsp*/);//~va9xI~//~va9yR~
            UTRACEP("chkMask wildcomp rc=%d %s-%s\n",rc,pfnm,pmask);//~vab0R~
            if (!rc)                                               //~va9xI~
            	break;                                             //~va9xI~
        }                                                          //~va9xI~
        else                                                       //~va9xI~
        {                                                          //~va9xI~
        	rc=LFNM_STRCMP(pmask,pfnm);                            //~va9xI~
//          UTRACEP("chkMask comp rc=%d %s-%s\n",rc,Pmask,pmask);  //~vab0R~
            UTRACEP("chkMask comp rc=%d %s-%s\n",rc,pfnm,pmask);   //~vab0I~
            if (!rc)                                               //~va9xI~
            	break;                                             //~va9xI~
        }                                                          //~va9xI~
    }                                                              //~va9xI~
    rc=pfnl!=0;                                                    //~va9xI~
    UTRACEP("chkMask rc=%d\n",rc);                                 //~va9xI~
    return rc;                                                     //~va9xI~
}//chkMask                                                         //~va9xI~
//**********************************************************************//~va9xI~
void printxmask()                                                  //~va9xI~
{                                                                  //~va9xI~
    PMASKLIST pfnl=0;                                              //~va9xI~
    char *pmask;                                                   //~va9xI~
	UQUEH *pqh;                                                    //~va9xI~
//*********************************                                //~va9xI~
	pqh=&Sqhxmask;                                                 //~va9xI~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9xI~
    {                                                              //~va9xI~
    	pmask=pfnl->MLname;                                        //~va9xI~
        printf("=== Xmask : %s\n",pmask);                          //~va9xI~
    }                                                              //~va9xI~
}//printxmask                                                      //~va9xI~
//**********************************************************************//~va9yI~
void printimask()                                                  //~va9yI~
{                                                                  //~va9yI~
    PMASKLIST pfnl=0;                                              //~va9yI~
    char *pmask;                                                   //~va9yI~
	UQUEH *pqh;                                                    //~va9yI~
//*********************************                                //~va9yI~
	pqh=&Sqhimask;                                                 //~va9yI~
	for (pfnl=UGETQTOP(pqh);pfnl;pfnl=UGETQNEXT(pfnl))             //~va9yI~
    {                                                              //~va9yI~
    	pmask=pfnl->MLname;                                        //~va9yI~
        printf("=== Fmask : %s\n",pmask);                          //~va9yI~
    }                                                              //~va9yI~
}//printxmask                                                      //~va9yI~
//**********************************************************************
//* write help msg  
//**********************************************************************
void help(void)
{
#define HELPMSG uerrhelpmsg(stdout,stderr,                         //~va26I~
//*******************
   	uerrmsg_init("",stdout,Suerrmsgopt);//msg to stdout            //~v11dI~
	HELPMSG "%s (%s)= simple string search tool(%s).\n",           //~va26R~
			"%s (%s)= ファイル中の文字列単純サーチPGM(%s).\n",     //~va26R~
			PGMID,VER,__DATE__);                                   //~v11eR~
	HELPMSG "format: %s [%coptions] srch_word filespec [filespec ...]\n",//~va26R~
			" 形式 : %s [%coptions] 探索文字列 ファイル指定 [ファイル指定...]\n",//~va26R~
			PGMID,CMDFLAG_PREFIX);                                 //~v1.1R~
	HELPMSG "*******************************************************************************\n",//~vak3R~
	        "*******************************************************************************\n");//~vak3R~
	HELPMSG " srch_word   :string to be searched.\n",              //~va26R~
			" 探索文字列   :サーチ文字列.\n");                     //~va26R~
	HELPMSG "              \\& (AND) and/or \\| (OR) (mixed-multiple)concatination is avail.\n",//~va26R~
			"               \\& (AND結合), \\| (OR結合) (混合/複数)使用可。\n");//~va26R~
	HELPMSG "              Esc sequence is avail like as \\t(x09),\\n(x0a),\\x__(x__).\n",//~va26R~
	        "               \\t(x09),\\n(x0a),\\x__(x__)等も使用可。\n");//~va26R~
	HELPMSG "              (but AND file-search is treated as OR for grep line-search.)\n",//~va26R~
	        "               (但し ファイル内AND探索はgrep(行探索)ではOR探索にする。)\n");//~va26R~
	HELPMSG "              use \"\" when applying grep only.\n",   //~vab0R~
	        "               grep の適用のみの時は\"\"を使用する。\n");//~va26R~
	HELPMSG " filespec    :directory or wild card allowed.\n",     //~va26R~
			" ファイル指定 :ディレクトリー,ワイルドカード指定も可.\n");//~va26R~
#ifndef UNX                                                        //~v120I~
    HELPMSG "              \"*:\" means all fixed drive.\n",       //~va26R~
            "                \"*:\" で全固定ドライブを意味する。\n");//~va26R~
#endif                                                             //~v120I~
	HELPMSG " options      :\n",                                    //~va26R~//~vak4R~
			" オプション   :\n");                                  //~va26R~
	HELPMSG "  %ca          :display All filename.\n",             //~va26R~
			"  %ca          :文字列を含まないファイル名も\x95\\示\n",//~va26R~
						CMDFLAG_PREFIX);                           //~v1.1I~
	HELPMSG "  %ccplc       :search by the string translated to Local-code.\n",//~van0I~
	        "  %ccplc       :指定された文字列をローカルコードに変換して探索\n",//~van0I~
						CMDFLAG_PREFIX,STR_SEPC);                  //~van0I~
	HELPMSG "  %ccpu8       :search by the string translated to UTF8.\n",//~van2I~
	        "  %ccpu8       :指定された文字列をUTF8に変換して探索\n",//~van2I~
						CMDFLAG_PREFIX,STR_SEPC);                  //~van2I~
	HELPMSG "  %cc          :filespec parm is \"%c\" concatinated string.\n",//~va39R~
	        "  %cc          :ファイル指定パラメータが \"%c\" 連結であることの指定\n",//~va39R~
						CMDFLAG_PREFIX,STR_SEPC);                  //~va39R~
	HELPMSG "  %ce xxxx     :grep Expression,use when grep in the file by other than srch_word.\n",//~va26R~//~vak3R~//~vak4R~
			"  %ce xxxx     :grep 式。ファイル内を探索文字列以外でgrepする時に使用。\n",//~va26R~//~vak3R~//~vak4R~
						CMDFLAG_PREFIX);                           //~v124M~
	HELPMSG "               spacify also flag parm of grep at the top of the string\n",//~va2hR~
			"               省略値のgrepパラメータ\"-nE\"を避けたい時は、\n");//~va2hR~
	HELPMSG "               if default grep parm(-nE) is not to be used.\n",//~va2hR~
			"               先頭にgrepのフラグパラメータを指定する。\n");//~va2hI~
	HELPMSG "  %cFmask      :filename wildcard mask to be selected. Allowed multiple parms.\n",           //~va26R~//~vab0R~
			"  %cFmask      :ファイル名選択ワイルドカード。複数指定可\n",    //~va26R~//~va9yR~
						CMDFLAG_PREFIX);                           //~v124M~
	HELPMSG "               Sub-dir is not excluded.\n",           //~vab0R~
			"               サブディレクトリーはこの指定で除外されません\n");//~vab0I~
	HELPMSG "               Use %cX to exclude sub-dir.\n",        //~vab0I~
			"               サブディレクトリーを除外するには %cX を使用する\n",//~vab0I~
						CMDFLAG_PREFIX);                           //~vab0I~
	HELPMSG "  %cg          :issue Grep for files containing srch_word.\n",//~va26R~
			"  %cg          :探索文字列が見つかったファイルにgrepを適用。\n",//~va26R~
						CMDFLAG_PREFIX);                           //~v11dI~
	HELPMSG "               search lines containing any word even if \"\\&\" on srch_word.\n",//~va26R~
			"               探索文字列指定で\"\\&\"を使用した場合でもいずれかを含む行を\x95\\示。\n");//~va26R~
	HELPMSG "  %ci          :case Insensitive.\n",                 //~va26R~
			"  %ci          :大文字小文字の区別無し\n",            //~va26R~
						CMDFLAG_PREFIX);                           //~v1.1I~
//  uerrmsg("  %cl          :print Lines containing string.\n",    //~va26R~
//  		"  %cl          :文字列を含む行を\x95\\示\n",          //~va26R~
//  					CMDFLAG_PREFIX);                           //~v11dR~
//#ifdef UNX                                                         //~v11dI~//~va71R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~//~va71R~
	HELPMSG "  %cm          :print file not found err/bypass slink Msg.\n",//~va72R~
			"  %cm          :ファイル無し、シンボリックリンクバイパス MSGを出力する\n",//~va26R~
						CMDFLAG_PREFIX);                           //~v11dI~
	HELPMSG "               For also slink into the dir,loop and no target case.\n",//~va72I~
			"               内部リンク、ループ、Target相手なしも出力される\n",//~va72I~
						CMDFLAG_PREFIX);                           //~va72I~
#else                                                              //~v11dI~
	HELPMSG "  %cm          :print file not found err Msg\n",      //~va26R~
			"  %cm          :ファイル無し MSGを出力する\n",        //~va26R~
						CMDFLAG_PREFIX);                           //~v114I~
#endif                                                             //~v11dI~
//    uerrmsg("  %cr          :Recursive subdir search\n",         //~va26R~
//            "  %cr          :サブDirも探索\n",                   //~va26R~
#ifdef W32                                                         //~vak3I~
	HELPMSG "  %cp          :specify before the search string if it start by \"-\" or \"/\".\n",//~va26R~
			"  %cp          :探索文字列が\"-\"か\"/\"で始まるとき文字列の前に指定する。\n",//~va26R~
						CMDFLAG_PREFIX);                           //~va1SI~
	HELPMSG "               For \"-\", simply \"\\\" is prepended before \"-\" as grep word.\n",//~vak3R~
			"               \"-\" のとき 単純に \"\\\" を \"-\" の前に追加し grep します\n");//~vak3R~
#else                                                              //~vak3I~
	HELPMSG "  %cp          :specify before the search string if it start by \"-\".\n",//~vak3I~
			"  %cp          :探索文字列が\"-\"で始まるとき文字列の前に指定する。\n",//~vak3I~
						CMDFLAG_PREFIX);                           //~vak3I~
	HELPMSG "               Simply \"\\\" is prepended before \"-\". as grep word.\n",//~vak3I~
			"               単純に \"\\\" を \"-\" の前に追加し grep します\n");//~vak3I~
#endif                                                             //~vak3I~
	HELPMSG "               Explicitly use %ce option if that is not appropriate.\n",//~vak3I~
			"               それが抵当でない場合は %ce を指定してください\n",//~vak3I~
						CMDFLAG_PREFIX);                           //~vak3I~
    HELPMSG "  %cr[n]       :Recursive subdir search. n:sub-directory depth.\n",//~va26R~
            "  %cr[n]       :サブDirも探索。n:探索サブDirのの深さ。\n",//~va26R~
						CMDFLAG_PREFIX);                           //~v1.1I~
    HELPMSG "               default(0) is unlimited. 1 means the top level.\n",//~va26R~
            "               省略値(0)は最下層まで、１がトップレベル。\n");//~va26R~
//#ifdef UNX                                                         //~v11cM~//~va71R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~//~va71R~
//  HELPMSG "  %cs          :no search in Symbolic link file\n",   //~va26R~//~va72R~
//  		"  %cs          :シンボリックリンクファイルはバイパス\n",//~va26R~//~va72R~
	HELPMSG "  %cs          :no search in Symbolic link except top dir.\n",//~va72I~
			"  %cs          :トップを除きシンボリックリンクはバイパス\n",//~va72I~
						CMDFLAG_PREFIX);                           //~v11cM~
	#ifdef UNX                                                     //~va72I~
	HELPMSG "               Note. shell expands wildcard if not enclosed by \".\n",//~va72I~
			"               \"で囲まない場合ワイルドカードはシェルが展開することに留意\n");//~va72I~
	#endif                                                         //~va72I~
#endif                                                             //~v11cM~
	HELPMSG "  %ct          :search Text file only\n",             //~va26R~
			"  %ct          :テキストファイルのみ探索\n",          //~va26R~
						CMDFLAG_PREFIX);                           //~v1.1I~
	HELPMSG "  %cu          :search unicode string converted from srch_word parm\n",//~va2hI~
			"  %cu          :探索文字列パラメータをユニコード変換した文字列を探す。\n",//~va2hI~
						CMDFLAG_PREFIX);                           //~va2hI~
	HELPMSG "  %cv          :display grep parameter\n",            //~va26R~
			"  %cv          :grepのパラメータを出力\n",            //~va26R~
						CMDFLAG_PREFIX);                           //~va1NI~
	HELPMSG                                                        //~va9xI~
			"  %cXmask      :file/directory name to be excluded. Allowed any number of parms.\n",//~va9xI~
			"  %cXmask      :比較から除外するファイル/フォルダー名。複数指定可\n",  //~va9xI~//~va9yR~
					CMDFLAG_PREFIX);                               //~va9xI~
	HELPMSG                                                        //~vab0I~
			"               Wilecard can be used.\n",              //~vab0R~
			"               ワイルドカード指定も可\n");            //~vab0R~
                                                                   //~va9xI~
#ifdef UNX                                                         //+vau0I~
	HELPMSG                                                        //+vau0I~
			"  %cNi         :No warning msg of \"Invalid filename\"\n",//+vau0I~
			"  %cNi         :警告Msg \"無効なファイル名\"を抑止する。\n",//+vau0I~
					CMDFLAG_PREFIX);                               //+vau0I~
#endif                                                             //+vau0I~
//    uerrmsg("  %cw+string   :additional search string(OR operation)\n",//~va26R~
//            "  %cw+string   :追加の探索文字列(OR結合)\n",        //~va26R~
//                        CMDFLAG_PREFIX);                         //~v118R~
//    uerrmsg("  %cw*string   :additional search string(AND operation)\n",//~va26R~
//            "  %cw*string   :追加の探索文字列(AND結合)\n",       //~va26R~
//                        CMDFLAG_PREFIX);                         //~v118R~
//  HELPMSG " sample. %s -gr word dir1\\x*\n",                     //~va26R~//~va9xR~
//          " 例.     %s -gr word dir1\\x*\n",                     //~va26R~//~va9xR~
    HELPMSG " sample. %s -gr  -X*.jpg -X*.png word dir1\\x*\n",    //~va9xR~
            " 例.     %s -gr  -X*.jpg -X*.png word dir1\\x*\n",    //~va9xR~
							PGMID);                                //~v118I~
//  HELPMSG "         %s -irgt  -F*.c -F*.h word .\n",             //~vab0R~
//          "         %s -irgt  -F*.c -F*.h word .\n",             //~vab0R~
    HELPMSG "         %s -irgt  -F*.c -F*.h -Xold-subdir word .\n",//~vab0I~
            "         %s -irgt  -F*.c -F*.h -Xold-subdir word .\n",//~vab0I~
							PGMID);                                //~va9yI~
    HELPMSG "         %s -g -p -xxx .\n",                          //~vak3I~
            "         %s -g -p -xxx .\n",                          //~vak3I~
							PGMID);                                //~vak3I~
    HELPMSG "         %s -g -e \"[-]xxx\\.c\" -p -xxx.c .\n",       //~vak3R~//~vak4R~
            "         %s -g -e \"[-]xxx\\.c\" -p -xxx.c .\n",       //~vak3R~//~vak4R~
							PGMID);                                //~vak3I~
	HELPMSG "         %s -t \"word1\\&word2\\|word3\\&word4\" dir1 dir2 dir3\n",//~va26R~
	        "         %s -t \"word1\\&word2\\|word3\\&word4\" dir1 dir2 dir3\n",//~va26R~
							PGMID);                                //~v118I~
#ifndef UNX                                                        //~v120I~
	HELPMSG "         %s -rt -e \"[A-Z]*_\" \"\" *:\n",             //~va26R~//~vak4R~
	        "         %s -rt -e \"[A-Z]*_\" \"\" *:\n",             //~va26R~//~vak4R~
							PGMID);                                //~v120I~
#else                                                              //~v120I~
	HELPMSG "         %s -rt -e \"[A-Z]*_\" \"\" dir1\n",           //~va26R~//~vak4R~
	        "         %s -rt -e \"[A-Z]*_\" \"\" dir1\n",           //~va26R~//~vak4R~
							PGMID);                                //~v11dI~
#endif                                                             //~v120I~
	HELPMSG "         %s -r  -e \"-E word1|word2\" -p \"-word1\\&word2\" dir1\n",//~va26R~//~vak4R~
	        "         %s -r  -e \"-E word1|word2\" -p \"-word1\\&word2\" dir1\n",//~va26R~//~vak4R~
							PGMID);                                //~va1QI~
#ifdef UNX                                                         //~va39I~
	HELPMSG "         %s -c  _MAX_PATH $INCLUDE\n",                //~va39I~
	        "         %s -c  _MAX_PATH $INCLUDE\n",                //~va39I~
							PGMID);                                //~va39I~
#else                                                              //~va39I~
	HELPMSG "         %s -c  _MAX_PATH \"%%INCLUDE%%\"\n",         //~va39R~
	        "         %s -c  _MAX_PATH \"%%INCLUDE%%\"\n",         //~va39R~
							PGMID);                                //~va39I~
#endif                                                             //~va39I~
//  HELPMSG "         %s -cpu8  ｡｢｣､   dir1\n",                    //~van2R~//~vas3R~
#ifdef LNX                                                         //~vas6I~
    HELPMSG "         %s -cpu8  \xe3\x81\x82\xe3\x81\x84\xe3\x81\x86 dir1\n",//~vas6R~
#else                                                              //~vas6I~
    HELPMSG "         %s -cpu8  あいう dir1\n",                    //~vas6I~
#endif                                                             //~vas6I~
	        "         %s -cpu8  あいう dir1\n",                    //~van2R~
							PGMID);                                //~van2I~
	return;
}//help
//**********************************************************************//~van0I~
int chkLang(void)                                                  //~van0R~
{                                                                  //~van0I~
	char *utf8wk,*pc;                                              //~van0R~
    int opt,chklen,rc=0,rc2,ii,len,lenu8,lenlc;                    //~van0R~
//    char localecode[MAXLOCALESZ];                                //~van0R~
//*******************                                              //~van0I~
    UTRACEP("chkLang langID=%d\n",langID);                         //~van0I~
	if (!langID)                                                   //~van0I~
    	return 0;                                                  //~van0R~
//    memset(localecode,0,sizeof(localecode));                     //~van0R~
//    rc2=utfcvlocaleinit(UTFCLIO_DEFAULTCHK,localecode);          //~van0R~
//    UTRACEP("chkLang utfcvlocaleinit rc=%d,localecode=%s\n",rc2,localecode);//~van0R~
//    if (rc2)                                                     //~van0R~
//        uerrexit("failed to get default locale",0);              //~van0R~
    if (langID==LANGID_CPU8)                                       //~van0I~
    {                                                              //~van0I~
#ifdef W32                                                         //~vaj0M~//~van2I~
    	uerrsetopt2(GBL_UERR2_OUTUTF8,0);              //~vaj0R~   //~van2I~
#endif              //Linux ignore,xe may specify                  //~vaj0I~//~van2I~
        if (Sgrepwordlen)                                          //~van0I~
        {                                                          //~van0I~
            UTRACEP("chkLang grepword=%s\n",Sgrepword);            //~van0R~
            lenu8=Sgrepwordlen*UTF8_MAXCHARSZ;                     //~van0R~
            utf8wk=umalloc((size_t)lenu8);                         //~van0R~
            opt=UTFCVO_BUFFSZPARM|UTFCVO_ERRRET; //outbuff size parm specified//~van0I~
            rc2=utfcvl2f(opt,utf8wk,Sgrepword,0/*init offs*/,Sgrepwordlen,0/*out choftbl*/,0/*out dbcstbl*/,&chklen,&lenu8/*outlen*/,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~va00I~//~van0R~
            if (rc2>=UTFCVRC_ERR)                                  //~van0R~
                rc=4;                                              //~van0R~
            else                                                   //~van0R~
            {                                                      //~van0R~
                *(utf8wk+lenu8)=0;                                 //~van0I~
                Sgrepword=utf8wk;                                  //~van0R~
                Sgrepwordlen=(int)strlen(utf8wk);                  //~van0R~
                UTRACED("chkLang grepword UTF8",Sgrepword,Sgrepwordlen);//~van0R~
            }                                                      //~van0R~
        }                                                          //~van0I~
        for (ii=0;ii<Swordno;ii++)                                 //~van0R~
        {                                                          //~van0R~
        	pc=Sword[ii];                                          //~van0I~
            if (pc)                                                //~van0I~
            {                                                      //~van0I~
                len=(int)*(pc+1);                                  //~van0R~
                UTRACED("chkLang searchword=",pc,len+3);           //~van0R~
                if (len)                                           //~van0R~
                {                                                  //~van0R~
                    lenu8=len*UTF8_MAXCHARSZ+3;                    //~van0R~
                    utf8wk=umalloc((size_t)lenu8);                 //~van0R~
            		opt=UTFCVO_BUFFSZPARM|UTFCVO_ERRRET; //outbuff size parm specified//~van0I~
                    rc2=utfcvl2f(opt,utf8wk+2,pc+2,0/*init offs*/,len/*strz*/,0/*out choftbl*/,0/*out dbcstbl*/,&chklen,&lenu8/*outlen*/,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~van0R~
                    if (rc2>=UTFCVRC_ERR)                          //~van0R~
                        rc=4;                                      //~van0R~
                    else                                           //~van0R~
                    {                                              //~van0R~
	                    *utf8wk=*pc;         //and/or              //~van0I~
    	                *(utf8wk+1)=(UCHAR)lenu8; //len            //~van0I~
    	                *(utf8wk+2+lenu8)=0;                       //~van0I~
                        Sword[ii]=utf8wk;                          //~van0R~
                        UTRACED("chkLang searchword UTF8",Sword[ii],2+lenu8+1);//~van0R~
                    }                                              //~van0R~
                }                                                  //~van0R~
            }                                                      //~van0I~
        }                                                          //~van0R~
	}                                                              //~van0M~
    else    //CPLC                                                 //~van0I~
    {                                                              //~van0I~
        if (Sgrepwordlen)                                          //~van0I~
        {                                                          //~van0I~
            UTRACEP("chkLang grepword U8=%s\n",Sgrepword);         //~van0I~
            lenu8=Sgrepwordlen*UTF8_MAXCHARSZ;                     //~van0I~
            utf8wk=umalloc((size_t)lenu8);                         //~van0R~
            opt=UTFCVO_ERRRET; //outbuff size parm specified       //~van0I~
			rc2=utfcvf2l(opt,utf8wk,Sgrepword,Sgrepwordlen,&chklen,&lenlc,NULL/*Ppcharwidth*/);//~vaucR~//~van0I~
            if (rc2>=UTFCVRC_ERR)                                  //~van0I~
                rc=4;                                              //~van0I~
            else                                                   //~van0I~
            {                                                      //~van0I~
                *(utf8wk+lenlc)=0;                                 //~van0I~
                Sgrepword=utf8wk;                                  //~van0I~
                Sgrepwordlen=lenlc;                                //~van0I~
                UTRACED("chkLang grepword LC",Sgrepword,Sgrepwordlen);//~van0I~
            }                                                      //~van0I~
        }                                                          //~van0I~
        for (ii=0;ii<Swordno;ii++)                                 //~van0I~
        {                                                          //~van0I~
        	pc=Sword[ii];                                          //~van0I~
            if (pc)                                                //~van0I~
            {                                                      //~van0I~
                len=(int)*(pc+1);                                  //~van0I~
                UTRACED("chkLang searchword U8=",pc,len+3);        //~van0I~
                if (len)                                           //~van0I~
                {                                                  //~van0I~
                    lenu8=len*UTF8_MAXCHARSZ+3;                    //~van0I~
                    utf8wk=umalloc((size_t)lenu8);                 //~van0R~
            		opt=UTFCVO_ERRRET; //outbuff size parm specified//~van0I~
					rc2=utfcvf2l(opt,utf8wk+2,pc+2,len,&chklen,&lenlc,NULL/*Ppcharwidth*/);//~van0I~
                    if (rc2>=UTFCVRC_ERR)                          //~van0I~
                        rc=4;                                      //~van0I~
                    else                                           //~van0I~
                    {                                              //~van0I~
	                    *utf8wk=*pc;         //and/or              //~van0I~
    	                *(utf8wk+1)=(UCHAR)lenlc; //len            //~van0I~
    	                *(utf8wk+2+lenlc)=0;                       //~van0I~
                        Sword[ii]=utf8wk;                          //~van0I~
                        UTRACED("chkLang searchword LC",Sword[ii],2+lenlc+1);//~van0I~
                    }                                              //~van0I~
                }                                                  //~van0I~
            }                                                      //~van0I~
        }                                                          //~van0I~
	}                                                              //~van0I~
    UTRACEP("chkLang rc=%d\n",rc);                                 //~van0I~
    return rc;                                                     //~van0I~
}//help                                                            //~van0I~
