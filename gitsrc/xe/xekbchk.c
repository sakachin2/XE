//*CID://+vbe0R~:                             update#=  520;       //+vbe0R~
//*************************************************************
//*xekbchk.c                                                       //~0924R~//~van6R~
//*	kbd scan/char chk                                              //~van6R~
//*************************************************************
//vbe0:171231 add function to search xml tag pair by A+/           //+vbe0I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb4k:160805 vb4f for LNX(specify ligature on/off,combine on/of line by line)//~vb4kI~
//vb4j:160806 (W32)OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay)//~vb4jI~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavn:140425 (BUG of vavj)setdbcstbl required for cmdline char edit for surrogae pair 4 dbcs//~vavnI~
//vang:131214 NOSCO option(ignore puTTY:SCO Esc string)            //~vangI~
//van6:131129 (LNX)compiler warning;dereferencing type-punned pointer//~van6I~
//vagi:120825 kbchk printed input string is too short              //~vagiI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafg:120616 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafgI~
//vac1:120204 (SMB)smb node support                                //~vac1I~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//va72:100801 LP64 wchar_t is 4byte on LP64                        //~va72I~
//va70:000701 LP64 option support. at first chk PTR sz(ini file comaptibility)//~va70I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va1C:091112 (UTF8)reffer pfh for filename codetype on errmsg     //~va1CI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          locale/utf8 mixed errmsg                               //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//v79R:081027 (BUG)dbcs evaluation required when graphic char input specification is by hex notation//~v79RI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v8@s:080621 3270:dbcs conversion support                         //~v8@sI~
//            pass recfm and lrecl,convert at xe3270 the use binary mode transfer//~v8@sI~
//v78N:080521 (LNXCON)rctl support                                 //~v78NI~
//v777:071204*EUC hankana chk(2byte but 1 column)                  //~v777I~
//v76p:070628 compare remote file support                          //~v76pI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69e:060519 chk scroll-lock on status for up/down arrow key to scroll up/down//~v69eI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v60m:050129 display different id from eolid for contline terminater.//~v60mI~
//v56p:040406 UCWFWAKEUP flag is cleared after filewakeup is called by scrpopup,//~v56pI~
//            so dirdraw cannot chk wakeup/resize flag when called //~v56pI~
//v55Q:040318 (LNX)generate mouse move event for cut & paste by mouse//~v55QI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v53H:031019 set default to vt100 because telnet from aix to aix change $TERM to xterm//~v53HI~
//v53p:030930 (LNX) -x parameter(single -) err chk                 //~v53pI~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//v53k:030927 (LNX)support stdout output                           //~v53kI~
//v53j:030927 (LNX)terminfo mouse string print                     //~v53jI~
//v52e:030826 (BUG)user string is null when terminfo used          //~v52eI~
//v526:030819 no more need to force under X because it is determined by ps cmd//~v526I~
//v525:030819 force TTERM env(kbd and viol) option                 //~v525I~
//v524:030819 integrate UKBDLNXC_-->UKBDL_                         //~v524I~
//v51Z:030817 (BUG)printable char chk,it shoult be by char code not by scan code.//~v51ZI~
//v51Y:030802 (AIX) key option for 7f force to BS/DEL/CHAR for also AIX//~v51YI~
//v51R:030802 (LNX) key option for 7f force to BS/DEL/CHAR         //~v51RI~
//v51C:030713 (LNX)xefunct LKED required for functbl srch to chk pfk used//~v51CI~
//v51B:030712 (LNX)allow multiple string for a key                 //~v51BI~
//v51z:030709 (LNX)no setstring ioption to chk native string on TERM=linux(console)//~v51zI~
//v51b:030419 (LNX)dbcs input                                      //~v51bI~
//v518:030412 reduce exe size                                      //~v518I~
//v515:030405 (LNX)user key string specification file support      //~v515I~
//v483:020423 (AIX)aixterm support                                 //~v483I~
//v47m:020309 screen height parm support(/Hnn)                     //~v47mI~
//v45q:011212 (BUG)last \n prinyerd                                //~v45qI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v40a:010323 LINUX support:terminfo print option                  //~v40aI~
//v403:010306 AIX-X support:terminfo string                        //~v403I~
//v402:010306 AIX support:string print                             //~v402I~
//v400:010205 X support:for cursor key string not by terminfo for xterm/kterm//~v400I~
//*************************************************************    //~v19zI~
#include <stdlib.h>                                                //~0924R~
#include <stdio.h>                                                 //~0924I~
#include <string.h>                                                //~1122I~
#include <time.h>                                                  //~vac1I~
                                                                   //~v40aI~
#ifdef UNX                                                         //~v40aI~
    #ifdef AIX                                                     //~v40bI~
		#include <ucurses.h>                                       //~v40bI~
    #else                                                          //~v51BI~
		#include <linux/keyboard.h>                                //~v51BI~
    #endif                                                         //~v40bI~
	#include <term.h>                                              //~v40aI~
#endif                                                             //~v40aI~
                                                                   //~1212I~
#ifdef OS2                                                         //~1212I~
    #define INCL_BASE                                              //~1212I~
    #include <os2.h>                                               //~1212I~
#endif                                                             //~1212I~
//**********************                                           //~0924I~
#include <ulib.h>                                                  //~v30eI~
#include <uque.h>                                                  //~1122R~
#include <ukbd.h>                                                  //~v30eI~
#include <uvio.h>                                                  //~1128I~
#ifdef UNX                                                         //~1128I~
	#include <uviol.h>                                             //~1128R~
	#include <ukbdl.h>                                             //~v51zI~
        #ifdef LNX                                                 //~1129I~
			#include <ukbdlnxc.h>                                  //~1129I~
			#include <ukbdlnxm.h>                                  //~v53mI~
        #else                                                      //~1129I~
			#include <ukbdlnxc.h>                                  //~v51YI~
			#include <ukbdaixt.h>                                  //~1129R~
        #endif                                                     //~1129I~
#endif                                                             //~1128I~
#include <uerr.h>                                                  //~1122I~
#include <udbcschk.h>                                              //~1122I~
#include <utrace.h>                                                //~1122I~
#include <ufile.h>                                                 //~v518I~
#include <uedit.h>                                                 //~v53mI~
#include <uftp.h>                                                  //~v8@sI~
//#include <ucurses.h>                                             //~1122R~
#ifdef WCSUPP                                                      //~v79zI~
	#include <ucvucs.h>                                            //~v79zI~
	#include <ucvext.h>                                            //~v79zI~
	#include <utf22.h>                                             //~va3xI~
#endif                                                             //~v79zI~
#ifdef W32                                                         //~va3DI~
	#include <ukbdw.h>                                             //~va3xI~
#endif                                                             //~va3DI~
#include <udbcschk.h>                                              //~vb4jI~
#define UVIOMDEFONLY	//for uviom.h                              //~vb4kI~
#include <uviom.h>                                                 //~vb4kI~
//**********************                                           //~v30eI~
//#ifdef UNX                                                       //~v518R~
//#else                                                            //~v518R~
	#define  GLOBAL                                            //~1129R~
//#endif                                                           //~v518R~
#ifdef UNX          //avoid compiler warning                       //~v717I~
    #undef KEY_ENTER                                               //~v717I~
    #undef KEY_LEFT                                                //~v717I~
    #undef KEY_HOME                                                //~v717I~
    #undef KEY_END                                                 //~v717I~
    #undef KEY_DOWN                                                //~v717I~
    #undef KEY_UP                                                  //~v717I~
    #undef KEY_RIGHT                                               //~v717I~
#endif                                                             //~v717I~
#include "xe.h"                                                    //~1128R~
#include "xegbl.h"                                                 //~1128R~
#include "xescr.h"                                                 //~1128R~//~van6M~
#include "xekbd.h"                                                 //~1128R~
#include "xecsr.h"                                                 //~v518I~
#include "xefunc.h"                                                //~1304I~
#include "xefunc2.h"                                               //~v518I~
                                                                   //~v705I~
#define GLOBAL_FUNCT                                               //~v705I~
#include "xefunct.h"                                               //~v518I~
                                                                   //~v705I~
#include "xepan.h"                                                 //~v518I~
#include "xefile.h"                                                //~v518I~
#include "xefile4.h"                                               //~v518I~
#include "xefile7.h"                                               //~v518I~
#ifdef UTF8SUPPH                                                   //~vb4jM~
	#define  GLOBAL_XEUTF                                          //~vb4jM~
	#include "xeutf.h"                                             //~vb4jM~
#endif                                                             //~vb4jM~
#define XEOPT_GLOBAL                                               //~v79zI~
#include "xeopt.h"                                                 //~v518I~
#include "xeini2.h"                                                //~v518I~
#include "xeebc.h"                                                 //~va50I~
//*************************************************************    //~0924I~
#undef VER      //for xegbl.h                                      //~v525I~
#define VER "v1.1"                                                 //~v525I~
#define  LINE_STRING   3                                           //~va1cR~
#define  LINE_KEY      4                                           //~va1cR~
#define  LINE_CODE     5                                           //~va1cR~
#define  MAXESCSEQ    10   //loop stopper                          //~vagiR~
#ifdef UNX                                                         //~v400R~
static char *Sstrfnm;                                              //~v403M~
static char *Sckfnm;                                               //~v40aI~
static char *Spreadbuff;                                           //~1304I~
static int  *Spreadlen;                                            //~1304I~
#ifdef LNX                                                         //~v51YI~
static long Sintvl=-1;  //use default                              //~v53mR~
static int Stermid=0;                                              //~v51BI~
#endif                                                             //~v51YI~
#endif                                                             //~v400I~
#ifdef WCSUPP                                                      //~v79zI~
    static int Sunicodesw=1;                                       //~v79zR~
    static int Sforcewidesw=0;                                     //~v79zR~
  #ifdef LNX                                                       //~v79zI~
  	static int Sutf8len;                                           //~v79zI~
  	static int Simenextlen;                                        //~v79zR~
//  static UCHAR Sutf8str[MAX_MBCSLEN];                            //~vagiR~
    static UCHAR Sutf8str[UTF8_MAXCHARSZMAX+1];                    //~vagiI~
	#define MAX_NEXTSTR  64                                        //~va3DI~
    static UCHAR Sutf8strnext[MAX_NEXTSTR];                        //~va3DI~
    static int Sutf8strnextlen;                                    //~va3DI~
  #endif                                                           //~v79zI~
#endif                                                             //~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	static UCHAR *Sstringlinedbcstbl;                              //~va1cR~
    static UCHAR Sdbcsid4[4]=UDBCSCHK_DBCSIDSTRGB4;                //~va1cR~
    static UCHAR Sdbcsid3[3]=UDBCSCHK_DBCSIDSTRSS3;                //~va1cR~
    static UCHAR Sdbcsid2[2]=UDBCSCHK_DBCSIDSTR   ;                //~va1cR~
#endif                                                             //~va1cR~
int xekbchk_main(void);                                            //~v30eI~
void printline(char *Pstr,int Pposy,int Pposx);                    //~1128I~
char *getshiftid(int);                                             //~v53mM~
int xekbchk_showmouse(KBDKEYINFO *Pkeyinf);                        //~v53mI~
//*************************************************************    //~v19ZI~
//helpmsg                                                          //~v19ZI~
//*********************************************************************//~v19ZI~
void helpmsg(void)                                                 //~v19ZI~
{                                                                  //~v19ZI~
#ifdef UNX                                                         //~v402I~
    #ifdef LNX                                                     //~v51zI~
//  char *optstr="[--n] [--cfilename] [--sfileneme]";              //~v51RR~
//  char *optstr="[--n] [--7{B|D|C}] [--cfilename] [--sfileneme]"; //~v53mR~
//  char *optstr="[--n] [--Mi-j] [--7{B|D|C}] [--cfilename] [--sfileneme]";//~vangR~
    char *optstr="[--n] " OPTSTR_NOSCO " " OPTSTR_Z2 " [--Mi-j] [--7{B|D|C}] [--cfilename] [--sfileneme]";//~vangR~
    #else                                                          //~v51zI~
//  char *optstr="[--cfilename] [--sfileneme]";                    //~v51YR~
//  char *optstr="[--cfilename] [--7{BS|DEL|CHAR}] [--sfileneme]"; //~v525R~
//  char *optstr="[--t] [--7{B|D|C}] [--cfilename] [--sfileneme]"; //~v53HR~
    char *optstr="[--tx] [--7{B|D|C}] [--cfilename] [--sfileneme]";//~v53HI~
    #endif                                                         //~v51zI~
#else                                                              //~v402I~
	char *optstr="";                                               //~v402I~
#endif                                                             //~v402I~
//********************************                                 //~v19ZI~
//#ifdef AIX                                                       //~v515R~
#ifdef UNX                                                         //~v515I~
    printf("%s: xekbchk [--h] %s [--kfilename]\n",VER,optstr);     //~v525R~
#else                                                              //~v30eI~
    printf("%s: xekbchk [--h] %s \n",VER,optstr);                  //~v525R~
#endif                                                             //~v30eI~
//#ifdef LNX                                                       //~v51YR~
#ifdef UNX                                                         //~v51YI~
	printf(" --7  : force assign 0x7f to BackSpace,Delete or Char 0x'7f'.\n");//~v51RR~
#ifdef LNX                                                         //~v51YI~
	printf("        default is by terminfo.\n");                   //~v51RI~
#else                                                              //~v51YI~
	printf("        default is BS for AIX.\n");                    //~v51YI~
#endif                                                             //~v51YI~
#endif                                                             //~v51RI~
	printf(" --h  : Help msg.\n");                                 //~v30eR~
#ifdef UNX                                                         //~1226I~
	printf(" --c  : Output curses-key by terminfo to the filename.\n");//~v40aI~
	printf(" --s  : Output strings assigned to key to the filename.\n");//~1304R~
#endif                                                             //~1226I~
#ifdef LNX                                                         //~v515I~
	printf(" --k  : key string specification file name.\n");       //~v515I~
	printf(" --n  : no set func-key-string to chk native console-string-setting.\n");//~v51zR~
#endif                                                             //~v515I~
#ifdef AIX                                                         //~v30eI~
	printf(" --k  : key string specification file name.\n");       //~v30eI~
    printf(" --t  : force TeraTerm keymap even if TERM!=vt100.(This is default)\n");//~v53HR~
//    printf(" --x  : execution under X.(default for aixterm).\n");//~v526R~
    printf(" --x  : force Not TeraTerm keymap even if TERM==vt100.\n");//~v53HI~
#endif                                                             //~v30eI~
#ifdef LNX                                                         //~v53mI~
	printf(" --M  : mouse click interval and dblclick interval by 0.1 sec.\n");//~v53mR~
	printf("        i:down->up interval for clisk, j:up->down interval for dblclick.\n");//~v53mR~
	printf("        default %d-%d.\n",UKLM_CLICK_INTVL,UKLM_DBLCLICK_INTVL);//~v53mR~
	printf(" --%s: ignore EscString defined for terminal type:SCO of puTTY.\n",OPTSTR_NOSCO);//~vangI~
	printf(" --%s : assign ^[[Z not to S+Tab but S+F2 according to SCO.\n",OPTSTR_Z2);//~vangR~
#endif                                                             //~v53mI~
#ifdef WCSUPP                                                      //~v79zI~
	printf(" --W  : read keyboard using unicode API.\n");          //~v79zI~
#endif                                                             //~v79zI~
	return;                                                        //~v19ZI~
}//helpmsg                                                         //~v19ZI~
//*************************************************************    //~0924I~
//default kbd opt                                                  //~0924I~
//*********************************************************************//~0229I~
int main(int argc,char **argp)
{
    int ii;                                                        //~1128R~
    char *pc;                                                      //~v30eR~
#ifdef UNX                                                         //~1128I~
#ifdef AIX                                                         //~v30eI~
    int opt;                                                       //~v51YI~
//    int   xxtermsw=0;                                            //~v526R~
    char *cnffnm=0;                                                //~v30eI~
#else                                                              //~v402I~
    int opt;                                                       //~v402M~
    int nosetstringsw=0;                                           //~v51zI~
    char *cnffnm=0;                                                //~v515I~
    long intvlclick,intvldblclick;                                 //~v53mI~
    int rc;                                                        //~v53mI~
#endif                                                             //~v30eI~
#endif                                                             //~1128I~
//********************************
#ifdef LNX                                                         //~v402R~
	opt=0                                                          //~0924I~
       +UKBDL_USEALTL  //  0x01      //use altL as ALT func key    //~v524R~
       +UKBDL_USEALTR  //  0x02      //use altR as ALT func key    //~v524R~
       +UKBDL_COMPOSE  //0x0100      //set katakana composer       //~v524R~
       +UKBDL_CURSES   //0x1000      //use curses                  //~v524R~
       +UKBDL_MONO 	//mono color                                   //~v524R~
       +0x00000fc0     //pf7-pf12    //alt+pfn usage               //~0924I~
       ; 		//default option to ukbdlnxc.c                     //~0924I~
#endif                                                             //~1128I~
#ifdef AIX                                                         //~v51YI~
	opt=0;                                                         //~v51YI~
    opt|=UKBDL_TNTT;	//default                                  //~v53HI~
#endif                                                             //~v51YI~
//select parm to xe                                                //~0924I~
    for (ii=1;ii<argc;ii++)                                        //~0807I~
    {                                                              //~0807I~
    	pc=argp[ii];                                               //~0924I~
        if (*pc!='-'||*(pc+1)!='-')                                //~v526I~
        {                                                          //~v53pI~
//          continue;                                              //~v53pR~
            printf("parm err(%s)\n",pc);                           //~v53pI~
            exit(1);                                               //~v53pI~
        }                                                          //~v53pI~
        pc+=2;                                                     //~v30eI~
#ifdef LNX                                                         //~vangI~
        if (!stricmp(pc,OPTSTR_NOSCO))                             //~vangI~
        {                                                          //~vangI~
            opt|=UKBDL_NOSCO;                                      //~vangI~
            continue;                                              //~vangI~
        }                                                          //~vangI~
        if (!stricmp(pc,OPTSTR_Z2))                                //~vangI~
        {                                                          //~vangI~
            opt|=UKBDL_Z2;                                         //~vangI~
            continue;                                              //~vangI~
        }                                                          //~vangI~
#endif                                                             //~vangI~
//#ifdef AIX                                                       //~v515R~
#ifdef UNX		//aix and linux                                    //~v515I~
        if (*pc=='K' || *pc=='k')                                  //~v30eI~
        {                                                          //~v30eI~
            cnffnm=pc+1;                                           //~v30eI~
            continue;                                              //~v30eI~
        }                                                          //~v30eI~
#endif                                                             //~v30eI~
//#ifdef LNX                                                       //~v51YR~
#ifdef UNX                                                         //~v51YI~
        if (*pc=='7')                                              //~v51RI~
        {                                                          //~v51RI~
            switch(*(pc+1))                                        //~v51RI~
            {                                                      //~v51RI~
            case 'B':                                              //~v51RI~
            case 'b':                                              //~v51RI~
                opt|=UKBDL_7fBS;                                   //~v524R~
                break;                                             //~v51RI~
            case 'D':                                              //~v51RI~
            case 'd':                                              //~v51RI~
                opt|=UKBDL_7fDEL;                                  //~v524R~
                break;                                             //~v51RI~
            case 'C':                                              //~v51RI~
            case 'c':                                              //~v51RI~
                opt|=UKBDL_7fCHAR;                                 //~v524R~
                break;                                             //~v51RI~
            default:                                               //~v51RI~
                printf("parm err(%s)\n",pc);                       //~v51RR~
                helpmsg();                                         //~v51RI~
                exit(1);                                           //~v51RI~
            }                                                      //~v51RI~
            continue;                                              //~v51RI~
        }                                                          //~v51RI~
#endif                                                             //~v51RM~
        for (;*pc;pc++)                                            //~v30eR~
        	switch(*pc)                                            //~v19JI~
            {                                                      //~v19JI~
#ifdef UNX                                                         //~v40aI~
            case 'C':                                              //~v40aI~
            case 'c':                                              //~v40aI~
            	Sckfnm=pc+1;                                       //~v40aI~
//                if (!*Sckfnm)                                    //~v53kR~
//                {                                                //~v53kR~
//                    printf("specify output filename for curses-key print\n");//~v53kR~
//                    exit(1);                                     //~v53kR~
//                }                                                //~v53kR~
                pc+=strlen(pc)-1;                                  //~v40aI~
                break;                                             //~v40aI~
#endif                                                             //~v40aI~
            case 'H':                                              //~v19ZI~
            case 'h':                                              //~v19ZI~
            	helpmsg();                                         //~v19ZI~
            	exit(0);                                           //~v19ZI~
                break;                                             //~v19ZI~
#ifdef UNX                                                         //~1226I~
            case 'S':                                              //~1226I~
            case 's':                                              //~1226I~
            	Sstrfnm=pc+1;                                      //~1226R~
//                if (!*Sstrfnm)                                   //~v53kR~
//                {                                                //~v53kR~
//                    printf("specify output filename for string\n");//~v53kR~
//                    exit(1);                                     //~v53kR~
//                }                                                //~v53kR~
                pc+=strlen(pc)-1;                                  //~1226R~
                break;                                             //~1226I~
#ifdef LNX                                                         //~v53mI~
            case 'M':                                              //~v53mI~
                if (!*(pc+1))                                      //~v53mI~
                {                                                  //~v53mI~
                	printf("parm format err(%s)\n",pc);            //~v53mI~
                    exit(1);                                       //~v53mI~
                }                                                  //~v53mI~
                rc=ugetnumrange(pc+1,&intvlclick,&intvldblclick);  //~v53mI~
                switch (rc)                                        //~v53mI~
                {                                                  //~v53mI~
                case 0:                                            //~v53mR~
                	intvldblclick=UKLM_DBLCLICK_INTVL;             //~v53mI~
                    break;                                         //~v53mI~
                case 1:                                            //~v53mR~
                    break;                                         //~v53mI~
                default:                                           //~v53mI~
                	printf("parm format err(%s)\n",pc);            //~v53mI~
                    exit(1);                                       //~v53mR~
                }                                                  //~v53mI~
                Sintvl=(intvlclick<<16)+intvldblclick;             //~v53mR~
                for (;*pc;pc++)                                    //~v53mI~
                	if (*pc==' ')                                  //~v53mI~
                    	break;                                     //~v53mI~
                pc--;                                              //~v53mI~
                break;                                             //~v53mI~
#endif                                                             //~v53mI~
#ifdef AIX                                                         //~v483R~
            case 'T':                                              //~v525I~
            case 't':                                              //~v525I~
                opt|=UKBDL_TNTT;                                   //~v525I~
                opt&=~UKBDL_TNLNX;      //reset linux              //~v53HI~
                break;                                             //~v525I~
//            case 'X':                                            //~v526R~
//            case 'x':                                            //~v526R~
//                xxtermsw=1;                                      //~v526R~
//                break;                                           //~v526R~
            case 'X':                                              //~v53HI~
            case 'x':                                              //~v53HI~
                opt&=~UKBDL_TNTT; //reset teraterm                 //~v53HI~
                opt|=UKBDL_TNLNX; //set linux                      //~v53HI~
                break;                                             //~v53HI~
#else                                                              //~v51zI~
            case 'N':                                              //~v51zI~
            case 'n':                                              //~v51zI~
                nosetstringsw=1;                                   //~v51zI~
                break;                                             //~v51zI~
#endif                                                             //~v483R~
#endif                                                             //~1226I~
#ifdef WCSUPP                                                      //~v79zM~
            case 'W':                                              //~v79zM~
            case 'w':                                              //~v79zM~
                Sforcewidesw=UDCWCIO_FORCEWIDE;                    //~v79zM~
                break;                                             //~v79zM~
#endif                                                             //~v79zM~
            default:                                               //~v19JI~
            	printf("parm err(%c)\n",*pc);                      //~v19ZR~
                helpmsg();                                         //~v19ZR~
                exit(1);                                           //~v19JI~
            }                                                      //~v19JI~
    }                                                              //~0807I~
//**********                                                       //~0924I~
#ifdef UNX                                                         //~v402R~
//  #ifdef LNX                                                     //~v51ZR~
    	xesetkbdopt(opt);//tell to xe                              //~v402R~
//  #endif                                                         //~v51ZR~
#ifdef AIX                                                         //~v30eI~
//    if (xxtermsw)                                                //~v526R~
//        Gkbdaixt_opt|=GKBAIX_XXTERM;                             //~v526R~
    if (cnffnm)                                                    //~v30eI~
//  	ukbdaixt_chngttkey(cnffnm);                                //~v525R~
    	ukbdaixt_chngttkey(opt,cnffnm);                            //~v525I~
#else                                                              //~v515I~
    if (nosetstringsw)                                             //~v51zI~
		Gukbdl_flag|=GUKBDL_NOSETSTR;  //bypass setstring of console//~v51zR~
    Stermid=ukbdl_gettermid();                                     //~v51BI~
    if (cnffnm)                                                    //~v515I~
//    	ukbdlnxc_chngttkey(cnffnm);                                //~v78NR~
      	ukbdlnxc_chngttkey(0,cnffnm);                              //~v78NI~
#endif                                                             //~v515R~
#endif                                                             //~1128I~
    return xekbchk_main();                                         //~v30eR~
}//main
//******************************************************************//~v30eI~
int xekbchk_main(void)                                             //~v30eI~
{                                                                  //~v30eI~
int xekbchk_kbdproc(void);                                         //~1122I~
#ifdef UNX                                                         //~1226I~
    void xekbchk_printstring(void);                                //~v402R~
	void xekbchk_ckprint(char *Poutfnm);                           //~v40aR~
#endif                                                             //~1226I~
    char *pc1st;                                                   //~1128I~
#ifdef WCSUPP                                                      //~v79zI~
    int wciopt;                                                    //~v79zI~
#endif                                                             //~v79zI~
//********************************                                 //~v30eI~
#ifdef WCSUPP                                                      //~v79zI~
	#ifdef UTF8SUPP                                                //~v79zR~
    	wciopt=UDCWCIO_UTF8VERSION;                                //~v79zR~
	#else                                                          //~v79zR~
    	wciopt=0;                                                  //~v79zR~
	#endif                                                         //~v79zR~
#ifdef W32                                                         //~v79zI~
	wciopt|=UDCWCIO_KBDUNICODE|Sforcewidesw;                       //~v79zR~
#else                                                              //~v79zI~
	wciopt|=UDCWCIO_VIOFROMUTF8; //display utf8 string as is if env is UTF8//~v79zR~
	wciopt|=UDCWCIO_KBDNOUTF8; //read byte by byte                 //~v79zR~
#endif                                                             //~v79zI~
    udbcschk_wcinit(wciopt,Gdefaultlocalecode); //utf8 version     //~v79zM~
#endif                                                             //~v79zI~
    gblinit();          //to avoid 0c4 for Gunpdispchartblj clear ar gblkon//~v400I~
//  funcinit();                                                    //~v518R~
//#ifdef LNX                                                       //~v52eR~
#ifdef UNX                                                         //~v52eI~
//  funcinit();                                                    //~v705R~
  #ifdef LNX                                                       //~v705I~
    funcinit("lnx");                                               //~v705I~
  #else                                                            //~v705I~
    funcinit("aix");                                               //~v705I~
  #endif                                                           //~v705I~
#endif                                                             //~v51CI~
    scrinit(0);                                                    //~v47mR~
    kbdinit();                                                     //~1122M~
#ifdef UNX                                                         //~1128M~
	if (Sckfnm)                                                    //~v40aI~
    {                                                              //~v40aI~
        kbdterm() ;                                                //~v53pI~
        scrreset();                                                //~v53pR~
    	xekbchk_ckprint(Sckfnm);                                   //~v40aI~
    }                                                              //~v40aI~
    else                                                           //~v40aI~
	if (Sstrfnm)                                                   //~1226R~
    {                                                              //~1226I~
        kbdterm() ;                                                //~v53pI~
        scrreset();                                                //~v53pR~
    	xekbchk_printstring();                                     //~1226I~
    }                                                              //~1226I~
    else                                                           //~1226I~
    {                                                              //~1226I~
#else                                                              //~1128M~
    scrcls(" \x07");                                               //~1128M~
#endif                                                             //~1128M~
#ifdef UNX                                                         //~v402R~
    #ifdef AIX                                                     //~v402I~
		ukbdaixt_gettbl(0,0,&Spreadbuff,&Spreadlen);               //~v402I~
    #else                                                          //~v402I~
	    ukbdlnxm_mouseopt(Sintvl);                                 //~v53mR~
		ukbdlnxc_gettbl(0,0,&Spreadbuff,&Spreadlen);               //~v402R~
        Gukbdl_flag|=GUKBDL_RCTLUSE;	//request shift report     //~v78NI~
    #endif                                                         //~v402I~
#endif                                                             //~v400I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    Sstringlinedbcstbl=Gscrdbcstbl+LINE_STRING*Gscrwidth;          //~va1cR~
    memset(Sstringlinedbcstbl,0,(UINT)Gscrwidth);                  //~va1cR~
#endif                                                             //~va1cR~
    pc1st="Hit any key; exit when doubled 'q'";                    //~1128I~
    printline(pc1st,1,1);                                          //~1128I~
    for (;;)    //until quit                                       //~v30eI~
    {                                                              //~v30eI~
        if (xekbchk_kbdproc()==-1)  //quit                         //~v30eI~
            break;                                                 //~v30eI~
    }                                                              //~v30eI~
    kbdterm();  //restore kbd rate at entry                        //~v53pI~
    scrterm();                                                     //~v53pI~
#ifdef UNX                                                         //~v400I~
    }//not string print                                            //~1226I~
#endif                                                             //~v400I~
//  kbdterm();  //restore kbd rate at entry                        //~v53pR~
//  scrterm();                                                     //~v53pR~
#ifdef UNX                                                         //~1304I~
	if (Sckfnm)                                                    //~v40aI~
    {                                                              //~v40aI~
    	printf("Curses-key printed to %s.\n",Sckfnm);              //~v51BR~
    }                                                              //~v40aI~
    else                                                           //~v40aI~
	if (Sstrfnm)                                                   //~1304I~
    {                                                              //~1304I~
    	printf("String printed to %s.\n",Sstrfnm);                 //~v51BR~
    }                                                              //~1304I~
#endif                                                             //~1304I~
    return 0;                                                      //~1122I~
}//xekbchk_main                                                    //~v30eI~
#ifdef W32                                                         //~va3DI~
//**************************************************               //~va3DI~
//*read RAW unnicode input switching to ReadConsole                //~va3DI~
//rc readlen                                                       //~va3DI~
//**************************************************               //~va3DI~
int xekbchk_chkrawcode(int Popt,KBDKEYINFO *Pkeyinf,UCHAR *Pinputc,int Pbuffsz)//~va3DR~
{                                                                  //~va3DI~
#define START_RAWUNICODE_INPUT    KEY_A_PPLUS                      //~va3DI~
	int scanch,outctr;                                             //~va3DI~
    char *rawmodewarning1="Unicode hex input mode by Alt+NumPad_Plus key,";//~va3DR~
    char *rawmodewarning2="restart and complete input if you released Alt key";//~va3DR~
//************	                                                   //~va3DI~
    scanch=((Pkeyinf->chScan<<8) | Pkeyinf->chChar);               //~va3DR~
    if (scanch!=START_RAWUNICODE_INPUT)                            //~va3DI~
    	return 0;                                                  //~va3DI~
    if (!uwriteconsoleinput(0,Pkeyinf,1,&outctr))//failed          //~va3DI~
    	return 0;                                                  //~va3DI~
    printline(rawmodewarning1,LINE_STRING,1);                      //~va3DR~
    printline(rawmodewarning2,LINE_KEY,1);                         //~va3DI~
    printline(" ",LINE_CODE,1);//clear warning                     //~va3DI~
    ureadconsole(Pinputc,Pbuffsz,&outctr);                         //~va3DI~
    printline(" ",LINE_STRING,1);//clear warning                   //~va3DI~
    printline(" ",LINE_KEY,1);                                     //~va3DI~
    return outctr;                                                 //~va3DI~
}//xekbchk_chkrawcode                                              //~va3DR~
#endif                                                             //~va3DI~
//**************************************************               //~v30eI~
//*get keyboard input and call key function                        //~v30eI~
//*rc   :rc from key function(-1 for quit)                         //~v30eI~
//**************************************************               //~v30eI~
//scancode/charcode                                                //~v30eI~
//      xx/yy:scan code/char code                                  //~v30eI~
//      00/yy:¶À¶Å,‘SŠp•¶Žš                                        //~v30eI~
//      xx/00:psude scancode                                       //~v30eI~
//      xx/e0:psude scancode                                       //~v30eI~
int xekbchk_kbdproc(void)                                          //~v30eI~
{                                                                  //~v30eI~
int xekbchk_showkey(int Pkeytyep,char *Pscanchar,int Pshift);      //~1122I~
    int rc;                                                        //~v30eI~
    int keytype;                                                   //~v30eI~
    KBDKEYINFO keyinf,keyinf2;                                     //~v30eI~
//  UCHAR inputc[3];                                               //~va3DR~
    UCHAR inputc[MAX_MBCSLEN];                                     //~va3DI~
    int shift;                                                     //~v30eI~
    int len;                                                       //~v78NI~
#ifdef LNX                                                         //~v79zI~
    int utf8len,ii,chklen;                                         //~v79zI~
//  ULONG ulucs;                                                   //~v79zI~//~va72R~
    UWUCS ulucs;                                                   //~va72I~
#endif                                                             //~v79zI~
#ifdef W32                                                         //~va3DR~
	int rawinputlen;                                               //~va3DI~
#endif                                                             //~va3DI~
//**********************                                           //~v30eI~
    inputc[2]=0;                                                   //~v30eI~
    len=                                                           //~v78NI~
    ukbdcharin(&keyinf,IO_WAIT);                                   //~v30eI~
#ifdef W32                                                         //~va3DR~
    rawinputlen=xekbchk_chkrawcode(0,&keyinf,inputc,sizeof(inputc));//~va3DI~
#endif                                                             //~va3xI~
UTRACED("ukbdcharin",&keyinf,sizeof(keyinf));                      //~v30eI~
#ifdef LNX                                                         //~v53mM~
    if (keyinf.chScan==UKLM_MOUSEID)                               //~v53mM~
    {                                                              //~v53mM~
    	xekbchk_showmouse(&keyinf);	                               //~v53mM~
        return 0;                                                  //~v53mM~
    }                                                              //~v53mM~
#endif                                                             //~v53mM~
    if (keyinf.chChar==0x0d && keyinf.chScan==0)    //0x000d       //~v30eI~
    {                                                              //~van6I~
//      *((USHORT*)(PVOID)(&keyinf.chChar))=KEY_ENTER;// 0xe00d force execute//~v30eI~//~van6R~
        keyinf.chChar=KEY_ENTER&0xff;// 0xe00d force execute       //~van6I~
        keyinf.chScan=KEY_ENTER>>8;  // 0xe00d force execute       //~van6I~
    }                                                              //~van6I~
  if (len)                                                         //~v78NI~
    if (!keyinf.chChar && !keyinf.chScan)   //break                //~v30eI~
        uerrexit("Break Key accepted",0);                          //~v30eI~
//    if (keyinf.chScan==KEY_PENTRID)                              //~1128R~
//    {                                                            //~1128R~
//        if (keyinf.chChar!=(KEY_PDIVIDE_CHK&255))//it char       //~1128R~
//        {                                                        //~1128R~
//            keyinf.chScan=keyinf.chChar;                         //~1128R~
//            keyinf.chChar=0;            //trate as ext key       //~1128R~
//        }                                                        //~1128R~
//    }                                                            //~1128R~
#ifdef WCSUPP                                                      //~v79zI~
  if (keyinf.bNlsShift & KBDNLS_UNICODE)                           //~v79zI~
  {                                                                //~v79zI~
    keytype=4;                                                     //~v79zI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    memcpy(inputc,keyinf.mbstr,3);    //3byte of ucs4              //~va3xR~
#else                                                              //~va3xI~
    inputc[0]=keyinf.chScan;    //USHORT low                       //~v79zI~
    inputc[1]=keyinf.chChar;    //USHORT high                      //~v79zI~
#endif                                                             //~va3xI~
  }                                                                //~v79zI~
  else                                                             //~v79zI~
#ifdef W32                                                         //~va3DR~
  if (rawinputlen)                                                 //~va3DI~
  {                                                                //~va3DI~
    keytype=-rawinputlen;                                          //~va3DI~
  }                                                                //~va3DI~
  else                                                             //~va3DI~
#endif                                                             //~va3DI~
  {                                                                //~v79zI~
#endif                                                             //~v79zI~
    if (keyinf.chChar==0x00 || keyinf.chChar==0xe0) //0x00 or 0xE0 //~v30eI~
    {                                                              //~v30eI~
        keytype=0;                                                 //~v30eI~
        inputc[0]=keyinf.chScan;    //psude code                   //~v30eI~
        inputc[1]=0;                                               //~v30eI~
    }                                                              //~v30eI~
    else                                                           //~v30eI~
    {                                                              //~v30eI~
        keytype=1;                                                 //~v30eI~
        inputc[0]=keyinf.chChar;    //char code                    //~v30eI~
        inputc[1]=keyinf.chScan;    //scan code                    //~v30eI~
		if (keyinf.fbStatus & KBDTRF_SHIFT_KEY_IN)//shift report   //~v78NR~
        {                                                          //~v78NI~
        	keytype=3;                                             //~v78NI~
        }                                                          //~v78NI~
        else                                                       //~v78NI~
        if (!keyinf.chScan)                                        //~v30eI~
        {                                                          //~v30eI~
#ifdef LNX                                                         //~v79zI~
			Simenextlen=0;                                         //~v79zR~
			if (UDBCSCHK_ISUTF8()                                  //~v79zI~
        		&&  *Spreadlen>1                                   //~v79zR~
        		&&  (utf8len=UTF8CHARLEN(*Spreadbuff))>1           //~v79zI~
        		&&   *Spreadlen>=utf8len                           //~v79zI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
//*for LNX but for unity                                           //~vaw1I~
				&&  !(uccvutf2ucs(UCVUCS_UCS4,Spreadbuff,utf8len,&ulucs,&chklen))//~va3xI~
#else                                                              //~va3xI~
				&&  !(uccvutf2ucs(0,Spreadbuff,utf8len,&ulucs,&chklen))//~v79zI~
#endif                                                             //~va3xI~
        	)                                                      //~v79zI~
            {                                                      //~v79zI~
                Sutf8len=utf8len;                                  //~v79zI~
            	Simenextlen=*Spreadlen-utf8len;                    //~v79zR~
        		keytype=5;	//utf8 string                          //~v79zI~
                Sutf8str[0]=inputc[0];                             //~v79zI~
                for (ii=1;ii<utf8len;ii++)                         //~v79zI~
                {                                                  //~v79zI~
                	ukbdcharin(&keyinf2,IO_WAIT);                  //~v79zI~
	                Sutf8str[ii]=keyinf2.chChar;       //2ndbyte   //~v79zI~
                }                                                  //~v79zI~
                UTRACED("ukbdcharin UTF8",Sutf8str,Sutf8len);      //~v79zM~
	            inputc[0]=keyinf2.chChar;       //2ndbyte          //~v79zI~
    			Sutf8strnextlen=0;                                 //~va3DI~
                for (ii=0;ii<Simenextlen;ii++) //get last          //~v79zR~
                {                                                  //~v79zI~
                	ukbdcharin(&keyinf2,IO_WAIT);                  //~v79zI~
	                inputc[0]=keyinf2.chChar;       //2ndbyte      //~v79zI~
                    if (Sutf8strnextlen<MAX_NEXTSTR)               //~va3DR~
    					Sutf8strnext[Sutf8strnextlen++]=keyinf2.chChar;//~va3DI~
                }                                                  //~v79zI~
            }                                                      //~v79zI~
            else                                                   //~v79zI~
#endif                                                             //~v79zI~
//          if (udbcschk(keyinf.chChar))            //DBCS         //~v777R~
            if (udbcschk_hk(0,keyinf.chChar))       //DBCS or EUC hankana//~v777I~
            {                                                      //~v30eI~
#ifdef LNX                                                         //~v79zI~
            	Simenextlen=*Spreadlen-2;                          //~v79zM~
#endif                                                             //~v79zI~
                keytype=2;                                         //~v30eI~
                ukbdcharin(&keyinf2,IO_WAIT);                      //~v30eI~
                UTRACED("ukbdcharin DBCS",&keyinf2,sizeof(keyinf2));//~v30eI~
                inputc[1]=keyinf2.chChar;       //2ndbyte          //~v30eI~
#ifdef LNX                                                         //~v79zI~
                for (ii=0;ii<Simenextlen;ii++)	//readout residual //~v79zR~
                {                                                  //~v79zI~
                	ukbdcharin(&keyinf2,IO_WAIT);                  //~v79zI~
	                inputc[2]=keyinf2.chChar;       //2ndbyte      //~v79zR~
                }                                                  //~v79zI~
#endif                                                             //~v79zI~
            }                                                      //~v30eI~
        }                                                          //~v30eI~
    }//char code                                                   //~v30eI~
#ifdef WCSUPP                                                      //~v79zI~
  }                                                                //~v79zI~
#endif                                                             //~v79zI~
    shift=keyinf.fsState;    //shift key status                    //~v30eI~
    rc=xekbchk_showkey(keytype,inputc,shift);                      //~v30eI~
    return rc;                                                     //~v30eI~
}//kbdproc                                                         //~v30eI~
//**************************************************               //~v30eI~
//*show key                                                        //~v30eI~
//*rc   :rc -1:when double 'q' entered                             //~v30eI~
//**************************************************               //~v30eI~
int xekbchk_showkey(int Pkeytype,char *Pscanchar,int Pshift)       //~1122R~
{                                                                  //~v30eI~
#ifdef UNX                                                         //~v400I~
	int ii,pos;                                                    //~v400I~
	char *pc;                                                      //~v400I~
    int utf8len;                                                   //~va3DI~
#endif                                                             //~v400I~
static int Sqctr=0;                                                //~v402R~
	int ch1,ch2,key;                                               //~v400R~
	char *shiftid,*keynm;                                          //~v51YR~
    char printwk[128];                                             //~1128I~
//#define  LINE_STRING   3                                         //~va1cR~
//#define  LINE_KEY      4                                         //~va1cR~
//#define  LINE_CODE     5                                         //~va1cR~
#ifdef WCSUPP                                                      //~v79zR~
	int mblen,jj;                                                  //~v79zI~
    UCHAR mbs[MAX_MBCSLEN],*pco;                                   //~v79zI~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
//  WUCS ucs;                                                      //~va3xI~//~va70R~
//  ULONG ucs;                                                     //~va70I~//~va72R~
    UWUCS ucs;                                                     //~va72I~
#else                                                              //~va3xI~
    USHORT ucs;                                                    //~v79zI~
#endif                                                             //~va1CI~//~va3xI~
#endif                                                             //~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
#ifdef UNX                                                         //~vafgI~
    int ss3sw=0,gb4sw=0;                                           //~va1cR~
#endif                                                             //~vafgI~
#endif                                                             //~va1cR~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw1R~
#ifdef LNX                                                         //~vaw1R~
    int chklen;                                                    //~va3xI~
#endif                                                             //~va1CI~//~va3xI~
//**********************                                           //~v30eI~
#ifdef WCSUPP                                                      //~v79zI~
	Sunicodesw++;                                                  //~v79zI~
#endif                                                             //~v79zI~
	shiftid=getshiftid(Pshift);                                    //~v30eI~
    ch1=*Pscanchar;                                                //~1122I~
    ch2=*(Pscanchar+1);                                            //~1122I~
	if (Pkeytype)                                                  //~1122I~
    	keynm="normal";                                            //~v51YR~
    else                                                           //~1122I~
    {                                                              //~1122I~
    	key=(ch1<<8);                                              //~1122I~
		keynm=kbdgetname((USHORT)key,0);                           //~v51YR~
    }                                                              //~1122I~
#ifdef UNX                                                         //~v400I~
    sprintf(printwk,"Input String(len=%d)=",*Spreadlen);           //~1304R~
    printline(printwk,LINE_STRING,1);                              //~1304R~
//  pos=strlen(printwk)+1;                                         //~1304R~//~vb30R~
    pos=(int)strlen(printwk)+1;                                    //~vb30I~
    for (ii=0,pc=Spreadbuff;ii<*Spreadlen;ii++,pc++)               //~1304R~
    {                                                              //~1304I~
		if (Pkeytype==5||Pkeytype==2)//utf8 or dbcs                //~v79zR~
 		   	sprintf(printwk,".0x%02x.",*pc);                       //~v79zI~
        else                                                       //~v79zI~
    	if (*pc<' ' || *pc>0x7e)                                   //~1304R~
 		   	sprintf(printwk,"0x%02x",*pc);                         //~v79zR~
        else                                                       //~1304I~
 		   	sprintf(printwk,"%c",*pc);                             //~v79zR~
    	printline(printwk,LINE_STRING,pos);                        //~1304R~
//      pos+=strlen(printwk);                                      //~1304I~//~vb30R~
        pos+=(int)strlen(printwk);                                 //~vb30I~
#ifdef UTF8SUPPH                                                   //~va1cR~
      if (Pkeytype==2)	//DBCS                                     //~vagiI~
      {                                                            //~vagiI~
        if (ii>=MAX_MBCSLEN)                                       //~va1cR~
            break;                                                 //~va1cR~
      }                                                            //~vagiI~
      else                                                         //~vagiI~
      if (Pkeytype==5)  //UTF8                                     //~vagiI~
      {                                                            //~vagiI~
        if (ii>UTF8_MAXCHARSZMAX)                                  //~vagiI~
            break;                                                 //~vagiI~
      }                                                            //~vagiI~
      else                                                         //~vagiI~
      {                                                            //~vagiI~
        if (ii>MAXESCSEQ)                                          //~vagiI~
            break;                                                 //~vagiI~
      }                                                            //~vagiI~
#endif                                                             //~va1cR~
    }                                                              //~1304I~
	if (Pkeytype==5)                                               //~v79zR~
    {                                                              //~v79zR~
        sprintf(printwk," ( %*.*s )",Sutf8len,Sutf8len,Sutf8str);  //~v79zR~
//        printline(printwk,LINE_STRING,-pos);  //print as ucs                     //~v79zR~//~va3DR~
          printline(printwk,LINE_STRING,pos);	//print as char    //~va3DI~
//      pos+=strlen(printwk);                                      //~v79zR~//~vb30R~
        pos+=(int)strlen(printwk);                                 //~vb30I~
    }                                                              //~v79zR~
	if (Pkeytype==2)                                               //~v79zI~
    {                                                              //~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
      if (UDBCSCHK_ISGB4STR(Spreadbuff,*Spreadlen)) //gb18030 4byte dbcs//~va1cR~
      {                                                            //~va1cR~
        sprintf(printwk," ( %4.4s )",Spreadbuff);      //1dd2      //~va1cR~
    	memcpy(Sstringlinedbcstbl+pos+3,Sdbcsid4,4);               //~va1cR~
        gb4sw=1;                                                   //~va1cR~
        UTRACED("Gb4 str",Spreadbuff,4);                           //~va1cR~
      }                                                            //~va1cR~
      else                                                         //~va1cR~
      if (ISSS3STR(Spreadbuff,*Spreadlen)) //gb18030 4byte dbcs    //~va1cR~
      {                                                            //~va1cR~
        sprintf(printwk," ( %3.3s )",Spreadbuff);      //1dd2      //~va1cR~
    	memcpy(Sstringlinedbcstbl+pos+3,Sdbcsid3,3);               //~va1cR~
        ss3sw=1;                                                   //~va1cR~
        UTRACED("SS3 str",Spreadbuff,3);                           //~va1cR~
      }                                                            //~va1cR~
      else                                                         //~va1cR~
      {                                                            //~va1cR~
#endif                                                             //~va1cR~
        sprintf(printwk," ( %c%c )",ch1,ch2);                      //~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	memcpy(Sstringlinedbcstbl+pos+3,Sdbcsid2,2);	//12       //~va1cR~
        UTRACED("DBCS2 str",Spreadbuff,2);                         //~va1cR~
      }                                                            //~va1cR~
      UTRACED("DBCS2 dbcstbl before",Sstringlinedbcstbl,Gscrwidth);//~va1cR~
#endif                                                             //~va1cR~
        printline(printwk,LINE_STRING,-pos);                       //~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	memset(Sstringlinedbcstbl+pos+3,0,4);	//used at printline-->uvio//~va1cR~
        UTRACED("DBCS2 dbcstbl",Sstringlinedbcstbl,Gscrwidth);     //~va1cR~
#endif                                                             //~va1cR~
//      pos+=strlen(printwk);                                      //~v79zI~//~vb30R~
        pos+=(int)strlen(printwk);                                 //~vb30I~
    }                                                              //~v79zI~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va3DR~
//    if (Pkeytype==5)                                               //~va1cR~//~va3DR~
//    {                                                              //~va1cR~//~va3DR~
//        sprintf(printwk," ( %*.*s )",Sutf8len,Sutf8len,Sutf8str);  //~va1cR~//~va3DR~
//        printline(printwk,LINE_STRING,pos);                        //~va1cR~//~va3DR~
//        pos+=strlen(printwk);                                      //~va1cR~//~va3DR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~va3DR~
//        uccvutf2ucs(UCVUCS_UCS4,Sutf8str,Sutf8len,&ucs,&chklen);   //~va3xR~//~va3DR~
//        sprintf(printwk," = u-%06X",(int)ucs);                     //~va3xR~//~va3DR~
//        printline(printwk,LINE_STRING,pos);                        //~va3xI~//~va3DR~
//        pos+=strlen(printwk);                                      //~va3xI~//~va3DR~
//#endif                                                             //~va3xI~//~va3DR~
//    }                                                              //~va1cR~//~va3DR~
//#endif                                                             //~va1cR~//~va3DR~
#endif                                                             //~v400M~
    sprintf(printwk,"shift=%04x=%s: key=%s",Pshift,shiftid,keynm); //~v51YR~
    printline(printwk,LINE_KEY,1);                                 //~1304R~
	switch(Pkeytype)                                               //~v30eI~
    {                                                              //~v30eI~
    case 1:	//sbcs                                                 //~v30eI~
//  	if (ch2>=' ' && ch2<=0x7f)                                 //~v51ZR~
    	if (ch1>=' ' && ch1<=0x7f)                                 //~v51ZI~
//      	sprintf(printwk,"sbcs:%s:scan=x%02X/char=%02X=%c\n",shiftid,ch2,ch1,ch1);//~v45qR~
//      	sprintf(printwk,"sbcs:%s:scan=x%02X/char=%02X=%c",shiftid,ch2,ch1,ch1);//~v51bR~
        	sprintf(printwk,"sbcs:%s:scan=x%02X/char=%02X=%c%c",shiftid,ch2,ch1,ch1,0);//~v51bI~
        else                                                       //~v30eI~
//      	sprintf(printwk,"sbcs:%s:scan=x%02X/char=%02X\n",shiftid,ch2,ch1);//~v45qR~
//        	sprintf(printwk,"sbcs:%s:scan=x%02X/char=%02X",shiftid,ch2,ch1);//~v51bR~
          	sprintf(printwk,"sbcs:%s:scan=x%02X/char=%02X,%c",shiftid,ch2,ch1,0);//~v51bI~
	    printline(printwk,LINE_CODE,1);                            //~1304R~
        if (ch1=='q'||ch1=='Q')                                    //~1122R~
        	Sqctr++;                                               //~v30eI~
        if (Sqctr>1)                                               //~v30eI~
        	return -1;                                             //~v30eI~
    	break;                                                     //~v30eI~
    case 2:	//dbcs                                                 //~v30eI~
    	Sqctr=0;                                                   //~v30eI~
//      sprintf(printwk,"dbcs:0x%02X%02X=%c%c\n",ch1,ch2,ch1,ch2); //~v45qR~
//      sprintf(printwk,"dbcs:0x%02X%02X=%c%c",ch1,ch2,ch1,ch2);   //~v51bR~
#ifdef LNX                                                         //~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
      if (gb4sw)                                                   //~va1cR~
      {                                                            //~va1cR~
		if (Simenextlen>2)                                         //~va1cR~
	        sprintf(printwk,"DBCS+:0x%02X%02X%02X%02X+%02X",ch1,ch2,*(Spreadbuff+2),*(Spreadbuff+3),*(Pscanchar+2)); //width last byte residual read//~va1cR~
        else                                                       //~va1cR~
	        sprintf(printwk,"DBCS+:0x%02X%02X%02X%02X",ch1,ch2,*(Spreadbuff+2),*(Spreadbuff+3));//~va1cR~
      }                                                            //~va1cR~
      else                                                         //~va1cR~
      if (ss3sw)                                                   //~va1cR~
      {                                                            //~va1cR~
		if (Simenextlen>1)                                         //~va1cR~
	        sprintf(printwk,"DBCS+:0x%02X%02X%02X+%02X",ch1,ch2,*(Spreadbuff+2),*(Pscanchar+2)); //width last byte residual read//~va1cR~
        else                                                       //~va1cR~
	        sprintf(printwk,"DBCS+:0x%02X%02X%02X",ch1,ch2,*(Spreadbuff+2)); //width last byte residual read//~va1cR~
      }                                                            //~va1cR~
      else                                                         //~va1cR~
#endif                                                             //~va1cR~
		if (Simenextlen)                                           //~v79zI~
	        sprintf(printwk,"DBCS+:0x%02X%02X+%02x",ch1,ch2,*(Pscanchar+2));//~v79zR~
        else                                                       //~v79zI~
	        sprintf(printwk,"DBCS:0x%02X%02X",ch1,ch2);            //~v79zI~
#else                                                              //~v79zI~
        sprintf(printwk,"dbcs:0x%02X%02X=%c%c%c",ch1,ch2,ch1,ch2,0);//~v51bI~
#endif                                                             //~v79zI~
	    printline(printwk,LINE_CODE,1);                            //~1304R~
    	break;                                                     //~v30eI~
    case 3:	//shift report                                         //~v78NI~
    	Sqctr=0;                                                   //~v78NI~
#ifdef BIGENDIAN                                                   //~v78NI~
        sprintf(printwk,"X11 keysym:0x%02X%02X",ch1,ch2);          //~v78NI~
#else                                                              //~v78NI~
        sprintf(printwk,"X11 keysym:0x%02X%02X",ch2,ch1);          //~v78NR~
#endif                                                             //~v78NI~
	    printline(printwk,LINE_CODE,1);                            //~v78NI~
    	break;                                                     //~v78NI~
#ifdef WCSUPP                                                      //~v79zI~
    case 4:	//UNICODE                                              //~v79zI~
    	Sqctr=0;                                                   //~v79zI~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
        ucs=UTF_GETUCS4FROMBESTR(Pscanchar);                       //~va3xI~
#else                                                              //~va3xI~
        ucs=ch1|(((UINT)(UCHAR)ch2)<<8);                           //~v79zR~
#endif                                                             //~va1CI~//~va3xI~
#ifdef W32                                                         //~v79zI~
//      ukbd_u2m(0,ucs,mbs,&mblen);                                //~v79zR~//~vaw1R~
        ukbd_u2m(0,(USHORT)ucs,mbs,&mblen);                        //~vaw1I~
        pco=printwk+sprintf(printwk,"unicode:u-%02X%02X=0x",ch1,ch2);//~v79zR~
        for (jj=0;jj<mblen;jj++)                                   //~v79zI~
        	pco+=sprintf(pco,"%02x",mbs[jj]);                      //~v79zR~
        pco+=sprintf(pco,"=");                                     //~v79zI~
        Sunicodesw=0;                                              //~v79zM~
	    printline(printwk,LINE_CODE,1);                            //~v79zR~
//      printline((UCHAR*)(ULONG)(&ucs),LINE_CODE,-1);             //~v79zR~//~vafkR~
        printline((UCHAR*)(ULPTR)(&ucs),LINE_CODE,-1);             //~vafkI~
//      Sunicodesw=1;     	//parm to printline,avoid next input show to col 40//~va3xR~
#else                                                              //~v79zI~
//      mblen=uccvucs2utf((ULONG)ucs,mbs);                         //~v79zI~//~vb30R~
        mblen=uccvucs2utf((UWUCS)ucs,mbs);                         //~vb30I~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
//*for !W32 but for unity                                          //~vaw1I~
        pco=printwk+sprintf(printwk,"UTF8(u-%06x)=0x",(int)ucs);   //~va3xI~
#else                                                              //~va3xI~
        pco=printwk+sprintf(printwk,"UTF8(u-%04x)=0x",ucs);        //~v79zI~
#endif                                                             //~va1CI~//~va3xI~
        for (jj=0;jj<mblen;jj++)                                   //~v79zI~
        	pco+=sprintf(pco,"%02x",mbs[jj]);                      //~v79zI~
	    printline(printwk,LINE_CODE,1);                            //~v79zI~
#endif                                                             //~v79zI~
    	break;                                                     //~v79zI~
#endif                                                             //~v79zI~
#ifdef LNX                                                         //~v79zI~
    case 5:	//utf8                                                 //~v79zI~
//        if (Simenextlen)                                           //~v79zI~//~va3DR~
//            if (ch1>=' ' && ch1<=0x7f)                             //~v79zI~//~va3DR~
//                sprintf(printwk,"UTF8+:%s:scan=x%02X/char=%02X=%c%c",shiftid,ch2,ch1,ch1,0);//~v79zI~//~va3DR~
//            else                                                   //~v79zI~//~va3DR~
//                sprintf(printwk,"UTF8+:%s:scan=x%02X/char=%02X,%c",shiftid,ch2,ch1,0);//~v79zI~//~va3DR~
//          if (ch1>=' ' && ch1<=0x7f)                             //~v79zR~//~va3DR~
//              sprintf(printwk,"UTF8:%s:scan=x%02X/char=%02X=%c%c",shiftid,ch2,ch1,ch1,0);//~v79zR~//~va3DR~
//          else                                                   //~v79zR~//~va3DR~
//              sprintf(printwk,"UTF8:%s:scan=x%02X/char=%02X,%c",shiftid,ch2,ch1,0);//~v79zR~//~va3DR~
		uccvutf2ucs(UCVUCS_UCS4,Sutf8str,Sutf8len,&ucs,&chklen);   //~va3DR~
        pco=printwk+sprintf(printwk,"UTF8: u-%06X",(int)ucs);      //~va3DR~
    	pco+=sprintf(pco," ( %*.*s ) ",Sutf8len,Sutf8len,Sutf8str);//~va3DI~
        for (jj=0,pc=Sutf8strnext;jj<Sutf8strnextlen;jj+=utf8len,pc+=utf8len)//~va3DR~
        {                                                          //~va3DI~
        	utf8len=UTF8CHARLENERR1(*pc);                          //~va3DR~
            if (utf8len+jj<=Sutf8strnextlen)                       //~va3DR~
				pco+=sprintf(pco,"%*.*s",utf8len,utf8len,pc);      //~va3DR~
        }                                                          //~va3DI~
	    printline(printwk,LINE_CODE,1);                            //~v79zI~
    	break;                                                     //~v79zI~
#endif                                                             //~v79zI~
    default:                                                       //~v30eI~
#ifdef W32                                                         //~va3DR~
	  if (Pkeytype<0)	//rawcode input                            //~va3DI~
      {                                                            //~va3DI~
        pco=printwk+sprintf(printwk,"RawUnicodeMode:0x");          //~va3DI~
        for (jj=0;jj<-Pkeytype;jj++)                               //~va3DR~
        	pco+=sprintf(pco,"%02x",*(Pscanchar+jj));              //~va3DI~
        pco+=sprintf(pco," ( ");                                   //~va3DR~
        for (jj=0;jj<-Pkeytype;jj++)                               //~va3DR~
        	pco+=sprintf(pco,"%c",*(Pscanchar+jj));                //~va3DI~
        pco+=sprintf(pco," )");                                    //~va3DR~
	    printline(printwk,LINE_CODE,1);                            //~va3DI~
      }                                                            //~va3DI~
      else                                                         //~va3DI~
#endif                                                             //~va3DI~
      {                                                            //~va3DI~
    	Sqctr=0;                                                   //~v30eI~
//      sprintf(printwk,"extk:scan=0x%02X/%02X\n",ch1,ch2);        //~v45qR~
//	    sprintf(printwk,"extk:scan=0x%02X/%02X",ch1,ch2);          //~v51bR~
  	    sprintf(printwk,"extk:scan=0x%02X/%02X%c",ch1,ch2,0);      //~v51bI~
	    printline(printwk,LINE_CODE,1);                            //~1304R~
      }                                                            //~va3DI~
    	break;                                                     //~v30eI~
    }                                                              //~v30eI~
    return 0;                                                      //~1122I~
}//xekbchk_showkey                                                 //~v30eI~
#ifdef LNX                                                         //~v53mI~
//**************************************************               //~v53mI~
//*show key                                                        //~v53mI~
//*rc   :rc -1:when double 'q' entered                             //~v53mI~
//**************************************************               //~v53mI~
int xekbchk_showmouse(KBDKEYINFO *Pkeyinf)                         //~v53mI~
{                                                                  //~v53mI~
    char printwk[128],*click,*modx,*pc;                            //~v53mR~
static char Sprintwk[128];                                         //~v53mR~
    int posx,posy,ch,button,pos,ii,upsw;                           //~v53mR~
static int Sdownposx,Sdownposy;                                    //~v55QR~
//**********************                                           //~v53mI~
    sprintf(printwk,"Input String(len=%d)=",*Spreadlen);           //~v53mI~
    printline(printwk,LINE_STRING,1);                              //~v53mI~
//  pos=strlen(printwk)+1;                                         //~v53mI~//~vb30R~
    pos=(int)strlen(printwk)+1;                                    //~vb30I~
    for (ii=0,pc=Spreadbuff;ii<*Spreadlen;ii++,pc++)               //~v53mI~
    {                                                              //~v53mI~
    	if (*pc<' ' || *pc>0x7e)                                   //~v53mI~
 		   	sprintf(printwk,"0x%02x",*pc);                         //~v53mI~
        else                                                       //~v53mI~
 		   	sprintf(printwk,"%c",*pc);                             //~v53mI~
    	printline(printwk,LINE_STRING,pos);                        //~v53mI~
//      pos+=strlen(printwk);                                      //~v53mI~//~vb30R~
        pos+=(int)strlen(printwk);                                 //~vb30I~
    }                                                              //~v53mI~
    posx=Pkeyinf->chMouseposx;                                     //~v53mR~
    posy=Pkeyinf->chMouseposy;                                     //~v53mR~
    ch=Pkeyinf->chChar;                                            //~v53mI~
    button=ch & 0x03;                                              //~v53mI~
//status                                                           //~v53mI~
    upsw=0;                                                        //~v53mR~
    if (ch & UKLM_CLICK)                                           //~v53mI~
        click="Click";                                             //~v53mI~
    else                                                           //~v53mI~
    if (ch & UKLM_DBLCLICK)                                        //~v53mI~
        click="DblClick";                                          //~v53mI~
    else                                                           //~v53mI~
    if (ch & UKLM_TRPCLICK)                                        //~v53mI~
        click="TrplClick";                                         //~v53mI~
    else                                                           //~v53mI~
    if (ch & UKLM_DOWN)                                            //~v53mI~
    {                                                              //~v55QI~
        click="Down";                                              //~v53mI~
        Sdownposx=posx;	//for move chk                             //~v55QI~
        Sdownposy=posy;                                            //~v55QI~
    }                                                              //~v55QI~
    else                                                           //~v53mI~
    {                                                              //~v53mI~
        if (posx!=Sdownposx || posy!=Sdownposy)                    //~v55QR~
        click="Move";                                              //~v55QI~
        else                                                       //~v55QI~
        click="Up";                                                //~v53mI~
        upsw=1;                                                    //~v53mR~
    }                                                              //~v53mI~
//modifier                                                         //~v53mM~
	modx=getshiftid(Pkeyinf->fsState);                             //~v53mI~
                                                                   //~v53mI~
    sprintf(printwk,"mouse:pos=(%2d,%2d),button=%-6s %d,status=%-9s",posx,posy,modx,button+1,click);//~v53mR~
    if (upsw)                                                      //~v53mI~
    {                                                              //~v53mI~
		printline(Sprintwk,LINE_KEY,1);                            //~v53mI~
		printline(printwk,LINE_CODE,1);                            //~v53mR~
    }                                                              //~v53mI~
    else                                                           //~v53mI~
    {                                                              //~v53mI~
		printline(printwk,LINE_KEY,1);                             //~v53mI~
		printline(" ",LINE_CODE,1);                                //~v53mI~
        memcpy(Sprintwk,printwk,sizeof(Sprintwk));                 //~v53mR~
    }                                                              //~v53mI~
    return 0;                                                      //~v53mI~
}//xekbchk_showmouse                                               //~v53mI~
#endif                                                             //~v53mI~
//********************************************************************//~v30eI~
char *getshiftid(int Pshift)                                       //~1122R~
{                                                                  //~v30eI~
static	char Sshiftid[64];                                         //~v30eI~
//******************************	                               //~v30eI~
	Sshiftid[0]=0;                                                 //~1122R~
	if (Pshift & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))             //~v30eI~
    	strcat(Sshiftid,"Shift+");                                 //~v30eI~
	if (Pshift & (KBDSTF_CONTROL|KBDSTF_LEFTCONTROL|KBDSTF_RIGHTCONTROL))//~v30eI~
    	strcat(Sshiftid,"Ctrl+");                                  //~v30eI~
	if (Pshift & (KBDSTF_ALT))                                     //~v30eI~
    	strcat(Sshiftid,"Alt+");                                     //~v30eI~
	if (Pshift & (KBDSTF_LEFTALT))                                 //~v30eI~
    	strcat(Sshiftid,"L-Alt+");                                   //~v30eI~
	if (Pshift & (KBDSTF_RIGHTALT))                                //~v30eI~
    	strcat(Sshiftid,"R-Alt+");                                   //~v30eI~
    return Sshiftid;                                               //~v30eI~
}//getshiftid                                                      //~v30eI~
//*********************************************************************//~v79zI~
//* display line                                                   //~v79zI~
//*********************************************************************//~v79zI~
void printline(char *Pstr,int Pposy,int Pposx)                     //~1128R~
{                                                                  //~1128I~
	char space[80];                                                //~1128I~
#ifdef W32                                                         //~v79zI~
static int Sucspos;                                                //~v79zI~
#endif                                                             //~v79zI~
#ifdef LNX                                                         //~v79zI~
//	UCHAR utf8attr=0x07;     //bg=0,fg=7 white on black            //~v79zI~//~va70R~
   	char utf8attr=0x07;     //bg=0,fg=7 white on black             //~va70I~
#endif                                                             //~v79zI~
//****************************                                     //~1128I~
#ifdef W32                                                         //~v79zI~
  if (Sunicodesw==1 && Pposy==LINE_CODE)                           //~v79zM~
//  uviowrtcharstr(Pstr,(int)strlen(Pstr),Pposy,Pposx+40);         //~vb4fR~
    uviowrtcharstr(0,Pstr,(int)strlen(Pstr),Pposy,Pposx+40);       //~vb4fI~
  else                                                             //~v79zM~
  if (Sunicodesw==0 && Pposx<0) //unicode output                   //~v79zI~
  {                                                                //~v79zI~
//  uviowrtucsstr((USHORT*)(ULONG)Pstr,1,Pposy,Sucspos);           //~v79zR~//~vafkR~
    uviowrtucsstr((USHORT*)(ULPTR)Pstr,1,Pposy,Sucspos);           //~vafkI~
  }                                                                //~v79zI~
  else                                                             //~v79zI~
#endif                                                             //~v79zI~
  {                                                                //~v79zI~
	memset(space,' ',sizeof(space));                               //~1128M~
#ifdef UTF8SUPPH                                                   //~va1cR~
  if (Pposx<0)                                                     //~va1cR~
//  uviowrtcharstr(space,sizeof(space),Pposy,-Pposx);              //~vb4fR~
    uviowrtcharstr(0,space,sizeof(space),Pposy,-Pposx);            //~vb4fI~
  else                                                             //~va1cR~
#endif                                                             //~va1cR~
//  uviowrtcharstr(space,sizeof(space),Pposy,Pposx);               //~vb4fR~
    uviowrtcharstr(0,space,sizeof(space),Pposy,Pposx);             //~vb4fI~
#ifdef LNX                                                         //~v79zI~
  if (Pposx<0)                                                     //~v79zI~
//charstratt writes byte by byte                                   //~va3xI~
//  uviowrtcharstratt(Pstr,(int)strlen(Pstr),Pposy,-Pposx,&utf8attr);//~v79zI~//~va70R~//~vb4kR~
    uviowrtcharstratt(0/*lineopt*/,Pstr,(int)strlen(Pstr),Pposy,-Pposx,&utf8attr);//~vb4kI~
  else                                                             //~v79zI~
#endif                                                             //~v79zI~
//  uviowrtcharstr(Pstr,(int)strlen(Pstr),Pposy,Pposx);            //~vb4fR~
    uviowrtcharstr(0,Pstr,(int)strlen(Pstr),Pposy,Pposx);          //~vb4fI~
#ifdef W32                                                         //~v79zI~
    Sucspos=Pposx+strlen(Pstr);                                    //~v79zR~
#endif                                                             //~v79zI~
  }                                                                //~v79zI~
UTRACED("printline",Pstr,(int)strlen(Pstr));                            //~v79zI~//~vb30R~
#ifdef UNX                                                         //~1128I~
    uviol_refresh();                                               //~1128M~
#endif                                                             //~1128I~
    return;                                                        //~1128I~
}                                                                  //~1128I~
#ifdef UNX                                                         //~1226I~
#ifdef LNX                                                         //~v402I~
//*********************************************************************//~1226I~
//* print string                                                   //~1226I~
//*********************************************************************//~1226I~
void xekbchk_printstring(void)                                     //~1226I~
{                                                                  //~1226I~
	int jj,modx,pfktno,keysym;                                     //~v51BR~
	PFUNCKEYTBL *ppfkt,pfkt;                                       //~1304R~
	PFUNCSTRTBL pfst;                                              //~1226I~
    FILE *fh;                                                      //~1226I~
    char *xestr,*tistr,tistrwk[32],xestrwk[32],*infoid;            //~v51BR~
    char linehdr[80],tistrwk2[48];                                 //~v51BR~
    char *userparm;                                                //~v51BR~
static char *Sshiftid[4]={" ","+Shift","+Ctrl","+Alt"};            //~1304R~
	int ttyconsw,kk;                                               //~v51BR~
    char *envterm;                                                 //~v51BR~
//************************                                         //~1226I~
	ttyconsw=((Stermid & TERM_IDMASK)==TERM_TTYLCONS);             //~v51BI~
  if (*Sstrfnm)                                                    //~v53kI~
  {                                                                //~v53kI~
    fh=fopen(Sstrfnm,"w");                                         //~1226R~
    if (!fh)                                                       //~1226I~
        uerrexit("%s open failed",0,                               //~1226I~
                    Sstrfnm);                                      //~1226R~
  }                                                                //~v53kI~
  else                                                             //~v53kI~
    fh=stdout;                                                     //~v53kI~
    envterm=getenv("TERM");                                        //~v51BI~
    if (ttyconsw)                                                  //~v51BR~
    	fprintf(fh,"\n##### key string table for Console mode (TERM=%s) #####\n",envterm);//~v53pR~
    else                                                           //~v51BI~
    	fprintf(fh,"\n##### key string table for X mode       (TERM=%s) #####\n",envterm);//~v53pR~
//#ifdef AIX                                                       //~v51BR~
//    ukbdaixt_gettbl(&ppfkt,&pfktno,0,0);                         //~v51BR~
//#else                                                            //~v51BR~
	ukbdlnxc_gettbl(&ppfkt,&pfktno,0,0);                           //~1304R~
//#endif                                                           //~v51BR~
    for (jj=0;jj<pfktno;jj++,ppfkt++)        //keycode             //~1304R~
    {                                                              //~1304I~
    	pfkt=*ppfkt;                                               //~1304I~
    	for (modx=0;modx<4;modx++)                                 //~1304I~
        {                                                          //~1304I~
            keysym=pfkt->FKTfkassign[modx];                        //~1304I~
            if (!modx && !keysym)                                  //~1304I~
                keysym=pfkt->FKTsymid;                             //~1304I~
//          userparm=pfkt->FKTttstring[modx];	//by key file      //~v51BR~
            pfst=pfkt->FKTpfst[modx];                              //~1304I~
//          if (userparm)                                          //~v51BR~
//            xestr=userparm;                                      //~v51BR~
//          else                                                   //~v51BR~
//            if (pfst)                                            //~v51BR~
//            {                                                    //~v51BR~
//                xestr=pfst->FSTstrnew;                           //~v51BR~
//                if (!xestr)                                      //~v51BR~
//                    xestr="";                                    //~v51BR~
//            }                                                    //~v51BR~
//            else                                                 //~v51BR~
//                xestr="";                                        //~v51BR~
//            tistr=pfkt->FKTterminfo[modx];                       //~v51BR~
//            *tistrwk=0;                                          //~v51BR~
//            if (pfkt->FKTflag[modx] & FKT_TTREPKEY)              //~v51BR~
//                infoid2="user-parm  ";                           //~v51BR~
//            else                                                 //~v51BR~
//                infoid2="";                                      //~v51BR~
//            if (pfkt->FKTflag[modx] & FKT_USEXTERM)              //~v51BR~
//                infoid="xterm/kterm";                            //~v51BR~
//            else                                                 //~v51BR~
//                infoid="terminfo   ";                            //~v51BR~
//            if (tistr)          //terminfo defined               //~v51BR~
//            {                                                    //~v51BR~
//                if (*xestr)     //xe assigned string             //~v51BR~
//                {                                                //~v51BR~
//                    if (*tistr==0x1b)                            //~v51BR~
////                      sprintf(tistrwk,"(!= %s:^[%s)",infoid,tistr+1);//~v51BR~
//                        sprintf(tistrwk,"(%s!= %s:^[%s)",infoid2,infoid,tistr+1);//~v51BR~
//                    else                                         //~v51BR~
//                    {                                            //~v51BR~
////                      sprintf(tistrwk,"(!= %s:",infoid);       //~v51BR~
//                        sprintf(tistrwk,"(%s!= %s:",infoid2,infoid);//~v51BR~
//                        pc=tistrwk+strlen(tistrwk);              //~v51BR~
//                        for (ii=0;ii<strlen(tistr);ii++)         //~v51BR~
//                            pc+=sprintf(pc,"0x%02x ",*(tistr+ii));//~v51BR~
//                    }                                            //~v51BR~
//                }                                                //~v51BR~
//                else                                             //~v51BR~
//                {                                                //~v51BR~
//                    xestr=tistr;                                 //~v51BR~
//                    sprintf(tistrwk,"(== %s)",infoid);           //~v51BR~
//                }                                                //~v51BR~
//            }                                                    //~v51BR~
//            else                                                 //~v51BR~
//                if (userparm)                                    //~v51BR~
//                    sprintf(tistrwk,"(== %s)",infoid2);          //~v51BR~
//            if (*xestr)                                          //~v51BR~
//            {                                                    //~v51BR~
//                if (*xestr==0x1b)                                //~v51BR~
//                    sprintf(xestrwk,"^[%s",xestr+1);             //~v51BR~
//                else                                             //~v51BR~
//                {                                                //~v51BR~
//                    pc=xestrwk;                                  //~v51BR~
//                    for (ii=0;ii<strlen(xestr);ii++)             //~v51BR~
//                        pc+=sprintf(pc,"0x%02x ",*(xestr+ii));   //~v51BR~
//                }                                                //~v51BR~
//                fprintf(fh,"%-6s(sym=%04x):%-6s(sym=%04x),string=%-12s %s\n",//~v51BR~
//                        pfkt->FKTkeyname,                        //~v51BR~
//                        pfkt->FKTsymid,                          //~v51BR~
//                        Sshiftid[modx],                          //~v51BR~
//                        keysym,                                  //~v51BR~
//                        xestrwk,                                 //~v51BR~
//                        tistrwk);                                //~v51BR~
//            }                                                    //~v51BR~
            tistr=pfkt->FKTterminfo[modx];                         //~v51BM~
            sprintf(linehdr,"%-6s(sym=%04x):%-6s(sym=%04x)",       //~v51BR~
                        pfkt->FKTkeyname,                          //~v51BM~
                        pfkt->FKTsymid,                            //~v51BM~
                        Sshiftid[modx],                            //~v51BM~
                        keysym);                                   //~v51BI~
            if (ttyconsw)                                          //~v51BM~
            {                                                      //~v51BM~
                xestr="";                                          //~v51BM~
                if (keysym==0x08 && pfkt->FKTkeycode)   //backspace defined on keymap//~v51BI~
                {                                                  //~v51BI~
                    xestr="\x08";                                  //~v51BI~
                    tistr=0;    //ignore terminfo,                 //~v51BI~
                 }                                                 //~v51BI~
                else                                               //~v51BI~
                if (keysym==K_REMOVE && pfkt->FKTkeycode)   //del by 7f//~v51BI~
                {                                                  //~v51BI~
                    xestr="\x7f";                                  //~v51BI~
                    tistr=0;                                       //~v51BI~
                }                                                  //~v51BI~
                else                                               //~v51BI~
                if (pfst)                                          //~v51BM~
                {                                                  //~v51BM~
                    if (pfst->FSTstrnew)                           //~v51BM~
                        xestr=pfst->FSTstrnew;                     //~v51BM~
                    else                                           //~v51BM~
                    if (pfst->FSTstrold)                           //~v51BM~
                        xestr=pfst->FSTstrold;                     //~v51BM~
                }                                                  //~v51BM~
                if (*xestr||tistr)                                 //~v51BI~
                {                                                  //~v51BI~
                    ukbdl_editstring(xestr,xestrwk);               //~v51BR~
                    if (tistr)                                     //~v51BI~
                    {                                              //~v51BI~
                        ukbdl_editstring(tistr,tistrwk);           //~v51BR~
                		if (pfkt->FKTflag[modx][0]==FKT_USEORGSTR)	//use terminfo str//~v51BI~
                        {                                          //~v51BI~
                        	strcpy(xestrwk,tistrwk);               //~v51BI~
                            infoid=":terminfo";                    //~v51BR~
                        }                                          //~v51BI~
                        else                                       //~v51BI~
                        {                                          //~v51BI~
                        	sprintf(tistrwk2,":ti=%s",tistrwk);    //~v51BR~
                        	infoid=tistrwk2;                       //~v51BR~
                        }                                          //~v51BI~
                    }                                              //~v51BI~
                    else                                           //~v51BI~
                    {                                              //~v51BI~
                        if (xestr==pfst->FSTstrnew)                //~v51BR~
	                        infoid=":xe";                          //~v51BR~
                        else                                       //~v51BI~
	                        infoid=":loadkeys";                    //~v51BR~
                    }                                              //~v51BI~
                }//not normal char                                 //~v51BI~
                else                                               //~v51BI~
                {                                                  //~v51BI~
                	infoid=0;                                      //~v51BI~
//                    if (!modx)                                   //~v51BR~
//                    {                                            //~v51BR~
//                        ch=pfkt->FKTsymid;                       //~v51BR~
//                        if (ch==0x01||ch==0x08||ch==0x09||ch==0x7f)//~v51BR~
//                        {                                        //~v51BR~
//                            *tistrwk=ch;                         //~v51BR~
//                            *(tistrwk+1)=0;                      //~v51BR~
//                            ukbdl_editstring(tistrwk,xestrwk);   //~v51BR~
//                            infoid=" ";                          //~v51BR~
//                        }                                        //~v51BR~
//                    }//plain                                     //~v51BR~
                }                                                  //~v51BI~
                if (infoid)                                        //~v51BI~
	                fprintf(fh,"%-s,string=%-12s %s\n",linehdr,xestrwk,infoid);//~v51BR~
            }//console                                             //~v51BR~
    		for (kk=0;kk<FKT_MAX_STR;kk++)                         //~v51BI~
            {                                                      //~v51BI~
				userparm=pfkt->FKTttstring[modx][kk];              //~v51BI~
		    	if (!userparm||!*userparm)                         //~v51BI~
        		    continue;                                      //~v51BI~
                switch(pfkt->FKTflag[modx][kk])                    //~v51BI~
                {                                                  //~v51BI~
                case FKT_USEORGSTR:     //by terminfo              //~v51BI~
		            if (ttyconsw)		//printed already          //~v51BI~
                    	continue;                                  //~v51BI~
                    infoid=":terminfo";                            //~v51BR~
                	break;                                         //~v51BI~
                case FKT_XDEFAULT:      //default for X            //~v51BI~
                    infoid=":xe default";                          //~v51BR~
                	break;                                         //~v51BI~
                case FKT_TTREPKEY:      //by key file parm         //~v51BI~
                    infoid=":parm keyfile";                        //~v51BR~
                	break;                                         //~v51BI~
                default:                                           //~v51BR~
                	continue;                                      //~v51BI~
                }                                                  //~v51BI~
                ukbdl_editstring(userparm,xestrwk);                //~v51BR~
                fprintf(fh,"%-s,string=%-12s (%s)\n",linehdr,xestrwk,infoid);//~v51BR~
            }//multiple str                                        //~v51BI~
        }//modx                                                    //~1304I~
    }                                                              //~1304I~
    fclose(fh);                                                    //~1226I~
    return;                                                        //~1226I~
}//xekbchk_printstring                                             //~1226I~
#else		//AIX                                                  //~v402I~
//*********************************************************************//~v402I~
//* print string                                                   //~v402I~
//*********************************************************************//~v402I~
void xekbchk_printstring(void)                                     //~v402I~
{                                                                  //~v402I~
	int jj,modx,pfktno,keycode,strtype;                            //~v51YR~
	PFUNCKEYTBL *ppfkt,pfkt;                                       //~v402I~
    FILE *fh;                                                      //~v402I~
    int kk,aixpfkno;                                               //~v51YR~
    char linehdr[80];                                              //~v51YI~
    char *xestr,*tistr,*ttstr,xestrwk[32],*infoid,ticmp[32];       //~v51YR~
static char *Sshiftid[4]={" ","+Shift","+Ctrl","+Alt"};            //~v402I~
//************************                                         //~v402I~
  if (*Sstrfnm)                                                    //~v53kI~
  {                                                                //~v53kI~
    fh=fopen(Sstrfnm,"w");                                         //~v402I~
    if (!fh)                                                       //~v402I~
        uerrexit("%s open failed",0,                               //~v402I~
                    Sstrfnm);                                      //~v402I~
  }                                                                //~v53kI~
  else                                                             //~v53kI~
    fh=stdout;                                                     //~v53kI~
	ukbdaixt_gettbl(&ppfkt,&pfktno,0,0);                           //~v402I~
    for (jj=0;jj<pfktno;jj++,ppfkt++)        //keycode             //~v402I~
    {                                                              //~v402I~
    	pfkt=*ppfkt;                                               //~v402I~
        keycode=pfkt->FKTkeycode;                                  //~v402R~
    	for (modx=0;modx<4;modx++)                                 //~v402I~
        {                                                          //~v402I~
            *ticmp=0;                                              //~v403I~
            strtype=pfkt->FKTfkassign[modx];                       //~v402I~
            if (!strtype)                                          //~v51YI~
            	continue;                                          //~v51YI~
            xestr=pfkt->FKTuserstring[modx];                       //~v402R~
            tistr=pfkt->FKTtistring[modx];                         //~v403I~
//            switch(strtype)                                      //~v51YR~
//            {                                                    //~v51YR~
//            case FKT_TTORGKEY:                                   //~v51YR~
//                infoid="TeraTerm Org";                           //~v51YR~
//                break;                                           //~v51YR~
//            case FKT_TTREPKEY:                                   //~v51YR~
//                infoid="TeraTerm Mod";                           //~v51YR~
//                break;                                           //~v51YR~
//            default:                                             //~v51YR~
//                infoid="";                                       //~v51YR~
//            }                                                    //~v51YR~
//            ttstr=pfkt->FKTttstring[modx];                       //~v51YR~
//            if (ttstr)                                           //~v51YR~
//            {                                                    //~v51YR~
//                xestr=ttstr;                                     //~v51YR~
//                if (tistr && *tistr)                             //~v51YR~
//                {                                                //~v51YR~
//                    if (strcmp(ttstr,tistr))    //not same       //~v51YR~
//                    {                                            //~v51YR~
//                        if (*tistr==0x1b)                        //~v51YR~
//                            sprintf(ticmp,"(Terminfo=^[%s)",tistr+1);//~v51YR~
//                        else                                     //~v51YR~
//                        {                                        //~v51YR~
//                            strcpy(ticmp,"(Terminfo=");          //~v51YR~
//                            pc=ticmp+strlen(ticmp);              //~v51YR~
//                            for (ii=0;ii<strlen(tistr);ii++)     //~v51YR~
//                                pc+=sprintf(pc,"0x%02x ",*(tistr+ii));//~v51YR~
//                            strcat(ticmp,")");                   //~v51YR~
//                        }                                        //~v51YR~
//                    }                                            //~v51YR~
//                    else                                         //~v51YR~
//                        strcpy(ticmp,"(=Terminfo)");             //~v51YR~
//                }                                                //~v51YR~
//            }                                                    //~v51YR~
//            else                                                 //~v51YR~
//              if (tistr && *tistr)                               //~v51YR~
//              {                                                  //~v51YR~
//                xestr=tistr;                                     //~v51YR~
//                infoid="Terminfo";                               //~v51YR~
//              }                                                  //~v51YR~
//              else                                               //~v51YR~
//                xestr=pfkt->FKTuserstring[modx];                 //~v51YR~
//            if (*xestr)                                          //~v51YR~
//            {                                                    //~v51YR~
//                if (*xestr==0x1b)                                //~v51YR~
//                    sprintf(xestrwk,"^[%s",xestr+1);             //~v51YR~
//                else                                             //~v51YR~
//                {                                                //~v51YR~
//                    pc=xestrwk;                                  //~v51YR~
//                    for (ii=0;ii<strlen(xestr);ii++)             //~v51YR~
//                        pc+=sprintf(pc,"0x%02x ",*(xestr+ii));   //~v51YR~
//                }                                                //~v51YR~
//                fprintf(fh,"%-9s(keycode=%4d):%-6s,string=%-12s %-12s %s\n",//~v51YR~
//                        pfkt->FKTkeyname,                        //~v51YR~
//                        keycode,                                 //~v51YR~
//                        Sshiftid[modx],                          //~v51YR~
//                        xestrwk,                                 //~v51YR~
//                        infoid,ticmp);                           //~v51YR~
//            }                                                    //~v51YR~
            sprintf(linehdr,"%-9s(keycode=%4d):%-6s",              //~v51YR~
                    pfkt->FKTkeyname,                              //~v51YI~
                    keycode,                                       //~v51YI~
                    Sshiftid[modx]);                               //~v51YI~
          if (xestr && *xestr)                                     //~v52eI~
            if (tistr && *tistr)                                   //~v51YI~
            {                                                      //~v51YI~
                ukbdl_editstring(tistr,xestrwk);                   //~v51YI~
                sprintf(ticmp,"(Terminfo=%-9s)",xestrwk);          //~v52eR~
            }                                                      //~v51YI~
            else                                                   //~v51YI~
//          	*ticmp=0;                                          //~v52eR~
                strcpy(ticmp,"(:xe               )");              //~v52eI~
          else                                                     //~v52eI~
            if (tistr && *tistr)                                   //~v52eI~
            {                                                      //~v52eI~
                ukbdl_editstring(tistr,xestrwk);                   //~v52eI~
                xestr=xestrwk;                                     //~v52eI~
                strcpy(ticmp,"(:from Terminfo    )");              //~v52eR~
            }                                                      //~v52eI~
          if (xestr)                                               //~v52eI~
            fprintf(fh,"%-s,string=^[%-10s %s\n",linehdr,xestr+1,ticmp);//~v52eR~
            aixpfkno=pfkt->FKTaixfunckeyno[modx];                  //~v51YR~
            if (aixpfkno)                                          //~v51YI~
            {                                                      //~v51YI~
                sprintf(xestrwk,"^[%03dq",aixpfkno);               //~v51YI~
                fprintf(fh,"%-s,string=%-12s (%-18s)\n",linehdr,xestrwk,":for aixterm");//~v51YR~
            }                                                      //~v51YI~
    		for (kk=0;kk<FKT_MAX_STR;kk++)                         //~v51YI~
            {                                                      //~v51YI~
				ttstr=pfkt->FKTttstring[modx][kk];                 //~v51YR~
		    	if (!ttstr||!*ttstr)                               //~v51YR~
        		    continue;                                      //~v51YI~
                switch(pfkt->FKTflag[modx][kk])                    //~v51YI~
                {                                                  //~v51YI~
                case FKT_TTREPKEY:      //by key file parm         //~v51YI~
                    infoid=":parm keyfile";                        //~v51YI~
                	break;                                         //~v51YI~
                case FKT_TTORGKEY:     //teraterm originary generate key//~v51YI~
                    infoid=":for Vt100";                           //~v51YR~
                	break;                                         //~v51YI~
                case FKT_AIXORGKEY:     //teraterm originary generate key//~v51YI~
                    infoid=":for X-terminal";                      //~v51YR~
                	break;                                         //~v51YI~
                case FKT_LINUX:     //teraterm originary generate key//~v51YI~
                    infoid=":for linux telnet";                    //~v51YR~
                	break;                                         //~v51YI~
                default:                                           //~v51YI~
                	continue;                                      //~v51YI~
                }                                                  //~v51YI~
                ukbdl_editstring(ttstr,xestrwk);                   //~v51YR~
                fprintf(fh,"%-s,string=%-12s (%-18s)\n",linehdr,xestrwk,infoid);//~v51YR~
            }//multiple str                                        //~v51YI~
        }//modx                                                    //~v402I~
    }                                                              //~v402I~
    fclose(fh);                                                    //~v402I~
    return;                                                        //~v402I~
}//xekbchk_printstring                                             //~v402I~
#endif  //AIX                                                      //~v402I~
#endif	//UNX                                                      //~v402R~
                                                                   //~v40aI~
#ifdef UNX                                                         //~v40aI~
//*********************************************************************//~v40aI~
//* print curses key definition                                    //~v40aI~
//*********************************************************************//~v40aI~
void xekbchk_ckprint(char *Poutfnm)                                //~v40aR~
{                                                                  //~v40aI~
#define PTERM(name) ckprintsub(fh,#name,name)                      //~v40aR~
	FILE *fh;                                                      //~v40aI~
void ckprintsub(FILE *Pfh,char *Pkeyname,char *Pstring);           //~v40aR~
    char *envterm;                                                 //~v51BI~
//*************************                                        //~v40aI~
  if (*Poutfnm)                                                    //~v53kI~
  {                                                                //~v53kI~
    fh=fopen(Poutfnm,"w");                                         //~v40aI~
    if (!fh)                                                       //~v40aI~
        uerrexit("%s open failed",0,                               //~v40aI~
                    Poutfnm);                                      //~v53kR~
  }                                                                //~v53kI~
  else                                                             //~v53kI~
    fh=stdout;                                                     //~v53kI~
    envterm=getenv("TERM");                                        //~v51BI~
    fprintf(fh,"\n##### terminfo key for TERM=%s #####\n",envterm);//~v53pR~
PTERM( key_backspace);                                             //~v40aI~
PTERM( key_catab    );                                             //~v40aI~
PTERM( key_clear    );                                             //~v40aI~
PTERM( key_ctab     );                                             //~v40aI~
PTERM( key_dc       );                                             //~v40aI~
PTERM( key_dl       );                                             //~v40aI~
PTERM( key_down     );                                             //~v40aI~
PTERM( key_eic      );                                             //~v40aI~
PTERM( key_eol      );                                             //~v40aI~
PTERM( key_eos      );                                             //~v40aI~
PTERM( key_f0       );                                             //~v40aI~
PTERM( key_f1       );                                             //~v40aI~
PTERM( key_f10      );                                             //~v40aI~
PTERM( key_f2       );                                             //~v40aI~
PTERM( key_f3       );                                             //~v40aI~
PTERM( key_f4       );                                             //~v40aI~
PTERM( key_f5       );                                             //~v40aI~
PTERM( key_f6       );                                             //~v40aI~
PTERM( key_f7       );                                             //~v40aI~
PTERM( key_f8       );                                             //~v40aI~
PTERM( key_f9       );                                             //~v40aI~
PTERM( key_home     );                                             //~v40aI~
PTERM( key_ic       );                                             //~v40aI~
PTERM( key_il       );                                             //~v40aI~
PTERM( key_left     );                                             //~v40aI~
PTERM( key_ll       );                                             //~v40aI~
PTERM( key_npage    );                                             //~v40aI~
PTERM( key_ppage    );                                             //~v40aI~
PTERM( key_right    );                                             //~v40aI~
PTERM( key_sf       );                                             //~v40aI~
PTERM( key_sr       );                                             //~v40aI~
PTERM( key_stab     );                                             //~v40aI~
PTERM( key_up       );                                             //~v40aI~
PTERM( keypad_local );                                             //~v40aI~
PTERM( keypad_xmit  );                                             //~v40aI~
                                                                   //~v40aI~
PTERM( key_a1       );                                             //~v40aI~
PTERM( key_a3       );                                             //~v40aI~
PTERM( key_b2       );                                             //~v40aI~
PTERM( key_c1       );                                             //~v40aI~
PTERM( key_c3       );                                             //~v40aI~
                                                                   //~v40aR~
PTERM( key_btab     );                                             //~v40aI~
                                                                   //~v40aR~
PTERM( key_beg      );                                             //~v40aI~
PTERM( key_cancel   );                                             //~v40aI~
PTERM( key_close    );                                             //~v40aI~
PTERM( key_command  );                                             //~v40aI~
PTERM( key_copy     );                                             //~v40aI~
PTERM( key_create   );                                             //~v40aI~
PTERM( key_end      );                                             //~v40aI~
PTERM( key_enter    );                                             //~v40aI~
PTERM( key_exit     );                                             //~v40aI~
PTERM( key_find     );                                             //~v40aI~
PTERM( key_help     );                                             //~v40aI~
PTERM( key_mark     );                                             //~v40aI~
PTERM( key_message  );                                             //~v40aI~
PTERM( key_move     );                                             //~v40aI~
PTERM( key_next     );                                             //~v40aI~
PTERM( key_open     );                                             //~v40aI~
PTERM( key_options  );                                             //~v40aI~
PTERM( key_previous );                                             //~v40aI~
PTERM( key_print    );                                             //~v40aI~
PTERM( key_redo     );                                             //~v40aI~
PTERM( key_reference);                                             //~v40aI~
PTERM( key_refresh  );                                             //~v40aI~
PTERM( key_replace  );                                             //~v40aI~
PTERM( key_restart  );                                             //~v40aI~
PTERM( key_resume   );                                             //~v40aI~
PTERM( key_save     );                                             //~v40aI~
PTERM( key_suspend  );                                             //~v40aI~
PTERM( key_undo     );                                             //~v40aI~
PTERM( key_sbeg     );                                             //~v40aI~
PTERM( key_scancel  );                                             //~v40aI~
PTERM( key_scommand );                                             //~v40aI~
PTERM( key_scopy    );                                             //~v40aI~
PTERM( key_screate  );                                             //~v40aI~
PTERM( key_sdc      );                                             //~v40aI~
PTERM( key_sdl      );                                             //~v40aI~
PTERM( key_select   );                                             //~v40aI~
PTERM( key_send     );                                             //~v40aI~
PTERM( key_seol     );                                             //~v40aI~
PTERM( key_sexit    );                                             //~v40aI~
PTERM( key_sfind    );                                             //~v40aI~
PTERM( key_shelp    );                                             //~v40aI~
PTERM( key_shome    );                                             //~v40aI~
PTERM( key_sic      );                                             //~v40aI~
PTERM( key_sleft    );                                             //~v40aI~
PTERM( key_smessage );                                             //~v40aI~
PTERM( key_smove    );                                             //~v40aI~
PTERM( key_snext    );                                             //~v40aI~
PTERM( key_soptions );                                             //~v40aI~
PTERM( key_sprevious);                                             //~v40aI~
PTERM( key_sprint   );                                             //~v40aI~
PTERM( key_sredo    );                                             //~v40aI~
PTERM( key_sreplace );                                             //~v40aI~
PTERM( key_sright   );                                             //~v40aI~
PTERM( key_srsume   );                                             //~v40aI~
PTERM( key_ssave    );                                             //~v40aI~
PTERM( key_ssuspend );                                             //~v40aI~
PTERM( key_sundo    );                                             //~v40aI~
PTERM( key_f11      );                                             //~v40aI~
PTERM( key_f12      );                                             //~v40aI~
PTERM( key_f13      );                                             //~v40aI~
PTERM( key_f14      );                                             //~v40aI~
PTERM( key_f15      );                                             //~v40aI~
PTERM( key_f16      );                                             //~v40aI~
PTERM( key_f17      );                                             //~v40aI~
PTERM( key_f18      );                                             //~v40aI~
PTERM( key_f19      );                                             //~v40aI~
PTERM( key_f20      );                                             //~v40aI~
PTERM( key_f21      );                                             //~v40aI~
PTERM( key_f22      );                                             //~v40aI~
PTERM( key_f23      );                                             //~v40aI~
PTERM( key_f24      );                                             //~v40aI~
PTERM( key_f25      );                                             //~v40aI~
PTERM( key_f26      );                                             //~v40aI~
PTERM( key_f27      );                                             //~v40aI~
PTERM( key_f28      );                                             //~v40aI~
PTERM( key_f29      );                                             //~v40aI~
PTERM( key_f30      );                                             //~v40aI~
PTERM( key_f31      );                                             //~v40aI~
PTERM( key_f32      );                                             //~v40aI~
PTERM( key_f33      );                                             //~v40aI~
PTERM( key_f34      );                                             //~v40aI~
PTERM( key_f35      );                                             //~v40aI~
PTERM( key_f36      );                                             //~v40aI~
PTERM( key_f37      );                                             //~v40aI~
PTERM( key_f38      );                                             //~v40aI~
PTERM( key_f39      );                                             //~v40aI~
PTERM( key_f40      );                                             //~v40aI~
PTERM( key_f41      );                                             //~v40aI~
PTERM( key_f42      );                                             //~v40aI~
PTERM( key_f43      );                                             //~v40aI~
PTERM( key_f44      );                                             //~v40aI~
PTERM( key_f45      );                                             //~v40aI~
PTERM( key_f46      );                                             //~v40aI~
PTERM( key_f47      );                                             //~v40aI~
PTERM( key_f48      );                                             //~v40aI~
PTERM( key_f49      );                                             //~v40aI~
PTERM( key_f50      );                                             //~v40aI~
PTERM( key_f51      );                                             //~v40aI~
PTERM( key_f52      );                                             //~v40aI~
PTERM( key_f53      );                                             //~v40aI~
PTERM( key_f54      );                                             //~v40aI~
PTERM( key_f55      );                                             //~v40aI~
PTERM( key_f56      );                                             //~v40aI~
PTERM( key_f57      );                                             //~v40aI~
PTERM( key_f58      );                                             //~v40aI~
PTERM( key_f59      );                                             //~v40aI~
PTERM( key_f60      );                                             //~v40aI~
PTERM( key_f61      );                                             //~v40aI~
PTERM( key_f62      );                                             //~v40aI~
PTERM( key_f63      );                                             //~v40aI~
#ifdef LNX                                                         //~v53jR~
    PTERM(  key_mouse    );                                        //~v53jR~
    PTERM(  mouse_info   );                                        //~v53jR~
    PTERM(  req_mouse_pos);                                        //~v53jR~
    PTERM(  get_mouse    );                                        //~v53jR~
#endif                                                             //~v53jR~
    fclose(fh);                                                    //~v40aI~
	return;                                                        //~v40aR~
}//xekbchk_ckprint                                                 //~v40aR~
//*********************************************************************//~v40aI~
//* print curses key definition                                    //~v40aI~
//*********************************************************************//~v40aI~
void ckprintsub(FILE *Pfh,char *Pkeyname,char *Pstring)            //~v40aR~
{                                                                  //~v40aI~
	char *pc;                                                      //~v40aI~
    int  binsw=0;                                                  //~v40aI~
//*************************                                        //~v40aI~
	fprintf(Pfh,"%-16s=",Pkeyname);                                //~v40aR~
    if (!Pstring)                                                  //~v40aI~
    	Pstring="";                                                //~v40aI~
    if (*Pstring==0x1b)                                            //~v40aI~
    {                                                              //~v40aI~
    	for (pc=Pstring+1;*pc;pc++)                                //~v40aI~
         	if (*pc<' ')                                           //~v40aR~
            {                                                      //~v40aI~
            	binsw=1;                                           //~v40aI~
                break;                                             //~v40aI~
            }                                                      //~v40aI~
    }                                                              //~v40aI~
    else                                                           //~v40aI~
    	binsw=1;                                                   //~v40aI~
                                                                   //~v40aI~
    if (binsw)                                                     //~v40aI~
    {                                                              //~v40aI~
    	for (pc=Pstring;*pc;pc++)                                  //~v40aI~
        	fprintf(Pfh," x%02X",*pc);                             //~v40aI~
        fprintf(Pfh,"\n");                                         //~v40aI~
    }                                                              //~v40aI~
    else                                                           //~v40aI~
    	fprintf(Pfh," x1B%s\n",Pstring+1);                         //~v40aR~
}//ckprintsub                                                      //~v40aI~
#endif	//UNX                                                      //~v40aI~
//**dummy func to avoid link ***************************************//~v518I~
#ifdef UNX                                                         //~v51CR~
    #include "xekbchkl.h"                                          //~v51CR~
#else                                                              //~v51CI~
int funccall(int Pkeytype,UCHAR *Pkey,PUCLIENTWE Ppcw){return 0;}  //~v518I~
FUNCTBL *funcftsrch(int Pkeytype,USHORT Pkey,int Pshift){return 0;}//~v518I~
FUNCTBL *functblsrch(int Pfuncid)                                  //~v518R~
{                                                                  //~v518I~
	static FUNCTBL Sdummyft={"","",0};                             //~v518R~
//*****************************                                    //~v518I~
	return &Sdummyft;                                              //~v518R~
}                                                                  //~v518I~
#endif                                                             //~v51CI~
int funcsetlongcmd(PUCLIENTWE Ppcw,int Popt,UCHAR *Pcmd,int Plen,int *Psetlen){return 0;}//~v518I~
int funcgetlongcmd(PUCLIENTWE Ppcw,UCHAR *Pcmd){return 0;}         //~v518I~
//void funccmdstack(UCHAR *Pcmd,int Pcmdlen){return;}              //~v670R~
PUSCMD funccmdstack(UCHAR *Pcmd,int Pcmdlen,int Pseqno){return 0;} //~vbCBR~
#ifndef UNX                                                        //~v51CI~
int func_prevtab_file(PUCLIENTWE Ppcw){return 0;}                  //~v518I~
#endif                                                             //~v51CI~
int panwakeup(PUCLIENTWE Ppcw){return 0;}                          //~v518I~
PUCLIENTWE panregist(int Pmenuid){return 0;}                       //~v518I~
int panlinetopfld(PUFLD Ppfl){return 0;}                           //~v518I~
int filewakeup(PUCLIENTWE Ppcw){return 0;}                         //~v518I~
CIDTBL *filegetcidtbl(void){return 0;}                             //~v518I~
int filesetassign(PUCLIENTWE Ppcw,int Pextkeysw,USHORT Pkey,int Pshiftkeysw){return 0;}//~v518R~
void ini2term(void){return;}                                       //~v518I~
void optsetdisplayeolid(void){return;}                             //~v518I~
void optsetdisplayeolcontid(void){return;}                         //~v60mI~
int filepguphalf(PUCLIENTWE Ppcw){return 0;}                       //~v55qM~
int filepgdownhalf(PUCLIENTWE Ppcw){return 0;}                     //~v55qM~
int filepglefthalf(PUCLIENTWE Ppcw){return 0;}                     //~v55qM~
int filepgrighthalf(PUCLIENTWE Ppcw){return 0;}                    //~v55qM~
int filesetupalct(void){return 0;}                                 //~v67CI~
PALCT filesrchalct(char *Pcmd,UQUEH *Ppqhalct){return 0;}          //~v67CI~
void file7term(void){return;}                                      //~v67CI~
int dirwakeup(PUCLIENTWE Ppcw){return 0;}                          //~v56pI~
PULINEH getdisplayline(PULINEH Pplh,int Pstep,int *Ppstep){return 0;}//~v69eR~
#ifndef LNX                                                        //~v705I~
	int funcchngeenter(int Popt){return 0;}                        //~v78NI~
//  int funct2getnextinputgc(char *Pinput){return 0;}              //~v705R~//~v79RR~
#ifdef UTF8SUPPH                                                   //~va1cI~
	int funct2getnextinputgc(PUCLIENTWE Ppcw,char *Pinput,void *Ppkeyinf){return 0;}//~va1cR~
#else                                                              //~va1cI~
    int funct2getnextinputgc(PUCLIENTWE Ppcw,char *Pinput){return 0;}//~v79RI~
#endif                                                             //~va1cI~
	int funcdupktsrch(int Popt,/*KEYTBL*/void *Ppkt,int Pmodidx,FUNCTBL **Pppft){return 0;}//~v76gI~
#endif                                                             //~v705I~
#ifdef FTPSUPP                                                     //~v70zI~
	char *xetsofilefullpath2ndedit(char *Pfullpath,PUFILEH Ppfh,char *Pmodifier){return 0;}//~v70zR~
	char *xetsofilefullpath2(char *Pfullpath,char *Ptarget,size_t Plen,char *Psource){return 0;}//~v70zR~
	int xetsogetpathlen(UCHAR *Pfilename,UCHAR *Plevel,int Pdirsw){return 0;}//~v717I~
	int xeftpgetremotecopy(int Popt,char *Ppfile,void *Ppuftph,char *Pouttmpf){return 0;}//~v76pR~
	int xetsosetftpparm(int Popt,PUFTPHOST Ppuftph,/*PUTSOFTPPARM*/ void *Pptsop,FILEFINDBUF3 *Ppfstat3,PUFILEH Ppfh){return 0;}//~v8@sI~
	UCHAR *xetsosetup3270keymap(void){return 0;}                   //~v78ZR~
	int xetsois3270key(PUCLIENTWE Ppcw,int Pkeytype,UCHAR *Pscanchar){return 0;}//~v78ZI~
#endif                                                             //~v70zI~
UCHAR *dcmdfullpath(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm){return 0;}//~v76pR~
#ifdef UTF8SUPPH                                                   //~va00I~
//int xeutf_getmixedstr(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,char *Pdbcs,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,//~va50R~
//                        char *Poututf8,int Poututf8sz,int *Ppoututf8len){return 0;};//~va50R~
//int xeutf_islocalestr(int Popt,char *Pinp,int Pinplen,char **Pputf8,int *Pputflen){return 0;}//~va50R~
int funcgetlongcmd_byutf8(int Popt,PUCLIENTWE Ppcw,UCHAR *Pcmd){return 0;}//~va00I~
UCHAR *pan300getfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata){return 0;}//~va00I~
int pan300setflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata){return 0;}//~va00I~
int pancompsetflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata){return 0;}//~va00I~
int pangrepsetflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata){return 0;}//~va00I~
UCHAR *pancompgetfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata){return 0;}//~va00R~
UCHAR *pangrepgetfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata){return 0;}//~va00I~
//int xeutf_fldl2f(int Popt,char *Pdata,char *Pdbcs,char *Pwk,int Plen,char *Pcodetype,char *Putf8,int *Pputf8len){return 0;}//~va50R~
//int xeutf_mixedstrupdate(int Popt,char *Ptgtlc,char *Ptgtutf8,char *Ptgtcodetype,char *Ptgtdbcs,int Ptgtlclen,int *Pptgtlclen,int *Pptgtutf8len,//~va50R~
//                            int Ptgtpos,int Ptgtwidth,           //~va50R~
//                            char *Psrclc,char *Psrcutf8,char *Psrccodetype,char *Psrcdbcs,int Psrclclen,int Psrcutf8len,int Psrcutf8buffsz){return 0;}//~va50R~
void chartabclear(UCHAR *Pdbcs,int Plen){return;}                  //~va00I~
//int xeutf_seterrmsgct(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdbcs,char *Ppct,int Pbuffsz,int *Pplenlc){return 0;}//~va1CR~//~va50R~
int pan300stackchkcmdbuff(int Popt,char *Pfpath){return 0;}        //~va1CI~
int pan300stacksetctfromcmdbuffsub(int Popt,char *Ppu8,char *Pplc,char *Ppct,int Pbuffsz){return 0;}//~va1CI~
//int xeutf_savelcctforerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Ppct,int Plenlc){return 0;}//~va50R~
//#ifdef UTF8UCS2                                                  //~va50R~
//int xeutf_cvf2lsetdbcs(int Popt,char *Pinp,int Pinplen,char **Ppout,char **Ppdbcs,int *Ppoutlen){return 0;}//~va50R~
//#endif                                                           //~va50R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~
int filechktabdbcs(PULINEH Pplh)                                   //~va50I~
{return 0;}                                                        //~va50I~
int filecharhexinput_v(PUCLIENTWE Ppcw,UCHAR *Pkeyindata,int Pkeyindatalen,int Poldvalue,int Pmode,int Pvhexmode,UCHAR *Ppnewchar)//~va50I~
{return 0;}                                                        //~va50I~
int fcmdsearchoncmdbuff(int Popt,UCHAR *Psrchstr,int Psrchstrlen,char **Pplc,char **Ppct,char **Ppdbcs)//~va50I~
{return 0;}                                                        //~va50I~
int fcmd_savelcctforerrmsg(int Popt,int Ptype,UCHAR *Psrch,int Psrchlen,UCHAR **Pppct,UCHAR **Pppcd,int Plenlc)//~va50I~
{return 0;}                                                        //~va50I~
int cmdlinepos2offs(int Popt,PUCLIENTWE Ppcw,UCHAR *Pputf8,UCHAR *Ppdbcs,UCHAR *Pcodetb,int Pstartcol,int Pcurcol,int Pu8len,//~vaarI~
		int *Ppu8offs,int *Ppddlen,int *Ppwidth,int *Ppaddlen)     //~vaarI~
{return 0;}                                                        //~vaarI~
#endif                                                             //~v70zI~//~va00I~
int fsubw_setdbcstblDD(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,char *Poutbuff,int Pbuffsz)//~vavnI~
{return 0;}                                                        //~vavnI~
void fcmd2term(void)                                               //~vbCBI~
{;}                                                                //~vbCBI~
int func_findPSP(PUCLIENTWE Ppcw){return 0;}                       //~vbCBR~
int func_findPSF(PUCLIENTWE Ppcw){return 0;}                       //~vbCBR~
int func_displayPS(PUCLIENTWE Ppcw){return 0;}                     //~vbCBI~
int func_revfindPSP(PUCLIENTWE Ppcw){return 0;}                    //~vb50I~
int func_revfindPSF(PUCLIENTWE Ppcw){return 0;}                    //~vb50I~
int func_xmlsrch(PUCLIENTWE Ppcw){return 0;}                       //+vbe0I~
char *funcsp_search(int Popt,char *Ppname){return 0;}              //~vba2I~
#endif//UTF8SUPPH                                                  //~va50I~
