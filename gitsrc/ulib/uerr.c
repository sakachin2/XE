//*CID://+v711R~:                              update#=  324       //~v711R~
//*************************************************************
//*uerrexit/uerrmsg/uerrexit_init/uerrmsg_init/ugeterrmsg**
//*uerrapi1,uerrapi1x,uerrapi0,uerrapi0x                           //~v040R~
//*************************************************************
//v711:201022 ftime deprecated(ftime is obsoleted POSIX2008)       //~v711I~
//v70n:200902 (ARM)uerrexit by locale                              //~v70nI~
//v70k:200802 (ARM:BUG)uerrmsg always english mode                 //~v70kI~
//v702:200615 ARM compiler warning                                 //~v702I~
//v6X4:180818 uerrhelpmsg:breakmag is corrupted by sjis2euc on utf8 env(GBL_UERR_SJIS2EUC is set by uerrmsgedit for currentline)//~v6X4I~
//v6Vw:180622 write exception msg to UTRACE                        //~v6VwI~
//v6U0:180305 debug assertion failed Expression:_format_char != '\0' at errmsgedit sprintf; count argment count//~v6U0I~
//v6T7:180220 stack errmsg to errmsg.<pid> and issue notification at initcomp//~v6T7I~
//v6J1:170206 errmsg loop when UD fmt err(uerrmsg->ufprintf->ufilecvUD2Wnopath->uerrmsg);occued when !UD_MODE()//~v6J1I~
//v6G3:161212 (Win10) missing error.h , use winerror.h             //~v6G3I~
//v6F5:160905 (LNXBUG)write default tab altch to ini file          //~v6F5I~
//v6Dj:160625 (BUG)uconfirmmsg could not display japanese msg      //~v6DjI~
//v6Di:160625 for compiler warning,-Wformat-security(not literal printf format)//~v6DiI~
//v6BD:160306 chng uerrmsg double entry msg                        //~v6BkI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6xq:150116 add uapierr1nt                                       //~v6xqI~
//v6v0:140623 (LNX:BUG)uerrmsg for xsub,utf8 fnm was cv to utf8 twice//~v6v0R~
//vauc:140420 (Win)unicode support by UD fmt string                //~vaucI~
//v6m2:130725 (BUG)EBC2ASC_IBM(x20) and UCVEXTO_TOUTF8 conflict occured//~v6m2I~
//            xprint ucvebc3_b2m translate to utf8 when no cfg found(default IBM option)//~v6m2I~
//            IBM/NEC is for the case of using internal mapp       //~v6m2I~
//v6k0:130524 mkarmnc is compile err(term.h not found) by v6j0     //~v6k0I~
//v6hi:120628 VC10x64 no exception handling                        //~v6hiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h2:120604 (XXE) msgbox for uerrexit by inifile version unmatch //~v6h2I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v694:100803 (BUG)xprint title printed by utf8 when /mtu          //~v694I~
//v690:100701 m64(LP64:: int:32, long,void*:64) support (__LP64_):chk pointer size at 1st.//~v690I~
//v639:091119 xsub exit(20) on ub9 before v638 by te reason of duplicate entry//~v639I~
//            bypass dup entry chk until return from udbcschk()    //~v639I~
//v620:090506 merge UTF8 version                                   //~v620I~
//            utf8 string parm conversion is done at xescr.c       //~v620I~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5nn:081102 (LNX:BUG)/n9 ignored for xsub helpmsg                //~v5nnI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5mK:080709 add errmsg area size option for errmsg_init          //~v5mKR~
//v61j:080117 visual studio 2005 compiler warning                  //~v61jR~
//v60b:071006 (UTF) no errmsg conversion option for xprint on Win  //~v60bI~
//v609:070918 (UTF:LNX)                                            //~v609R~
//v607:070820 (UTF:W32)errmsg by utf8                              //~v607I~
//v5ku:070705 helpmsg wait should be avoid when redirected         //~v5kuI~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5j3:060912 add uerrapi1tx etc(display error description)        //~v5j3I~
//v5iy:060908 (WIN)add ugetlasterrmsg(get msg corresponding to GetLastError())//~v5iyI~
//v5ix:060908 add uconfirmmsg from xfs                             //~v5iwI~
//v5iw:060907 uerrmsg timestamp display option                     //~v5iwI~
//v5i9:060601 (LNX:FC5)support UTF8 for other than japanese        //~v5jdI~
//v5i8:060601 (LNX:FC5)errmsg by utf8(accordingly for gxe "g_locale_to_utf8" do no conversion,//~v5i8I~
//             for xe utf8 msg processed by gnome-terminal)        //~v5i8I~
//v5g8:050620 (XXE)xxe support;no konchk required for xxe,use udbcschkcp() result only//~v5g8I~
//v5fa:041229 (UNX)help quit by 'Q' required linefeed              //~v5faI~
//v5f8:041211 (LNX)dbcs msg conversion is for patern only(no parameter conv)//~v5f8I~
//v5f3:041120 helpmsg stop by "Q"                                  //~v5f3I~
//v5bz:040314 set force_english option to gbl for wxe help msg     //~v5bzI~
//v5bs:040221 (BUG)spawn done errmsg clear not work(clear if parm is 0)//~v5bsI~
//v5bq:040215 (LNX:BUG)euc conv err when uerrmsgcat                //~v5bqI~
//v59w:031230 (BUG:UNX)last null missing for sjis2euc              //~v59wI~
//v591:030927 EUC dbcs support(allow DBCS when gterm,kterm)        //~v591I~
//v57u:030126 (DOS)drop ehdump.c/funcmap.c for memory shortage     //~v57uI~
//v570:021007 (WXE)help msg                                        //~v570I~
//v570:020824 wxe support                                          //~v570I~
//v55a:020427 (UNX:BUG)mdoscmd clear errmsg by ugeterrmsg;save and restore//~v55aI~
//v550:020413 string len change by euc<->sjis conv;consider for tabid on dbcstbl//~v550I~
//v530:020309 reduce bell interval 1sec to 0.5sec                  //~v530R~
//v50V:011011 (BUG)help not wait at scren end(scr size get err)    //~v50VI~
//v50w:010519 v50u for also helpmsg                                //~v50wI~
//v50u:010421 EUC japanese errmsg under kon                        //~v50uI~
//v401:001027 AIX support:ncurses.h should be curses.h             //~v401I~
//v39R:010121 LINUX support:uerrmsg is by SJIS,so use english mode when euc mode//~v39RI~
//v39b:001113 LINUX support:move posix logic(common to linux and aix) to ukbdl from ukbdlnxc//~v39bI~
//v376:000930 LINUX support(BUG of 335:1 space line between when next page scrool up,//~v376I~
//            crlf should be inserted by titlemsg func)            //~v376I~
//v363:000927 LINUX support(term info by setupterm not scrinit/endwin)//~v363I~
//v362:000927 LINUX support(support getch where out of curses)     //~v362I~
//v361:000927 LINUX support(curses required to get scr height)     //~v361I~
//v335 000904:(BUG)title msg scrollup 1 line of helpmsg            //~v335I~
//v334 000904:LINUX support(endwin required for helpmsg(getmode called))//~v334I~
//v324 000813:LINUX support                                        //~v324I~
//v297:000115 it is noisy,no beep only once for same reason(continuous from same pos)//~v297I~
//v293:991031 no beep option support                               //~v293I~
//v250:990626 (BUG):uviogetmode fail if redirected under win.      //~v250I~
//                  (chk rc=1 for redirect;See V252)               //~v250I~
//v200:981025 uerrmsgcat:strcat to previous errmsg if prev is short enough//~v200I~
//v199:981010 helpmsg;msg change                                   //~v199R~
//v191:980831 bell option for uerrexit(uerrexit_optinit)           //~v191I~
//v182:980607 uerrmsg2:msg if no prev msg pending                  //~v182I~
//            ugeterrmsg2:msg get but not clear                    //~v182I~
//v178:980503 (DOS)use putch for dos for printf and flush          //~v178I~
//v177:980503 (Win)Beep dose not work under Windows95              //~v177I~
//                 temporary change console mode to PROCESS_INPUT to bell//~v177I~
//v176:980503 (GCC)bell dose not ring on winNT.use int 10 like as bell on pc_hw\co30\conio.c//~v176I~
//v175:980503 (Win)bell by Beep(not printf 0x07)for the case consolemode is//~v175I~
//            nor PROCESS_INPUT                                    //~v175I~
//v170:980430 (BUG)errmsg over 4096 destroyed area.                //~v170I~
//            Sepatbl was destoyed at abend handling,cuased uerrexit at ueh.//~v170I~
//v168:980430 msg to std out when errexit dup entry                //~v168I~
//v150:980119 need differrentiate codepage and dbcs tbl            //~v150I~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v150I~
//            rightmost column effect on first column of next line //~v150I~
//v101:971009 long filename                                        //~v101I~
//            uerr.c  :mapfilename,up to maxpath                   //~v101I~
//v070:970401:(DOS)print seg reg when dump                         //~v070I~
//v062:970210:external err msg out control                         //~v062I~
//v060:970201:function:uerrhelpmsg:for help,wait key enter to continue//~v060I~
//           :function:uerrscrheight:get max row                   //~v060I~
//           :function:uerrmsgedit:uerrmsg but no output to any    //~v060I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -no need dump when DPMI                              //~v053I~
//v040:961027:uerrapi0,uerrapi0x(errmsg with no parm)              //~v040I~
//v029:960920:uerrexit loop detection                              //~v029I~
//v027:960917:dos dump sub                                         //~v027I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*951111 force english/japanese msg option                     //~5B11I~
//*950902 split popupmsg to avoid large link(uvio/ukbd)         //~5902R~
//*       bell by printf(x'07') and fflush not but vio          //~5902I~
//*950827 printf errexit msg before ufuncpathmsg(may call errmsg//~5827R~
//*       and reset static errmsg by map open err etc)          //~5827I~
//*pathmsg only when mapfile specified                          //~5827I~
//*************************************************************
#include <time.h>
//#include <sys\timeb.h>                                           //~v324R~
#include <sys/timeb.h>                                             //~v324I~
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
                                                                   //~v5j3I~
#include <errno.h>                                                 //~v5j3I~
                                                                   //~v324I~
#ifdef UNX                                                         //~v324M~
//      #include <ncurses.h>                                       //~v401R~
        #include <ucurses.h>                                       //~v401I~
  #if !(defined(ARM) && defined(XXE))                              //~v6a0I~
//#ifndef NOCURSES                                                 //~v6hiR~
  #ifndef NOCURSES                                                 //~v6k0I~
	#include <term.h>                                              //~v39bI~
  #endif //NOCURSES                                                //~v6k0I~
//#endif //NOCURSES                                                //~v6hiR~
  #endif //XXEARM                                                  //~v6a0I~
#else      //!UNX                                                  //~v324M~
                                                                   //~v324I~
#include <conio.h>                                                 //~v060I~
                                                                   //~v324I~
#ifdef DOS
#include <dos.h>        //for uvio.h                               //~v060M~
#else
  #ifdef W32                                                       //~v053I~
   #ifndef MGW32                                                   //~v5ncI~
   #ifdef WIN10                                                   //+v6BkI//~v6G3I~
   #else                                                           //~v6G3I~
    #include <error.h>                                             //~v5iyI~
   #endif //!MGW32                                                 //~v6G3I~
   #endif //!MGW32                                                 //~v5ncI~
#define _WINERROR_      //protect winerror.h(partialy duplicated definie with error.h)//~v5iyR~
    #include <windows.h>                                           //~v175I~
  #else                                                            //~v053I~
    #define INCL_BASE                                              //~v060R~
    #include <os2.h>                                               //~v060R~
  #endif                                                           //~v053I~
#endif
#endif  //!UNX                                                     //~v324I~
//*******************************************************
#include <ulib.h>
                                                                   //~v060I~
#define GBL_UERR			//generate gbl variable at uerr.h      //~v060I~
#include <uerr.h>
                                                                   //~v060I~
#include <udbcschk.h>
                                                                   //~v324I~
#ifdef UNX                                                         //~v324R~
  #ifdef XXE                                                       //~v5g8I~
	#include <xxexei.h>                                            //~v5g8I~
  #else                                                            //~v5g8I~
#include <uviol.h>                                                 //~v324I~
  #endif                                                           //~v5g8I~
#include <ukbdl.h>                                                 //~v39bR~
#include <uunxsub.h>                                               //~v363I~
#else                                                              //~v324I~
#include <ufuncmap.h>
#endif  //!UNX                                                     //~v324I~
                                                                   //~v324I~
#include <upopup.h>                                             //~5902I~
#include <uvio.h>                                                  //~v060I~
#include <utrace.h>                                                //~v170I~
#include <ualloc.h>                                                //~v170I~
#include <uedit.h>                                                 //~v5iwI~
#ifdef LNX                                                         //~v607R~
	#include <ucvucs.h>                                            //~v5i8I~
#else                                                              //~v609R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
	#include <ucvucs.h>                                            //~v609R~
//#endif                                                           //~v5n8R~
#endif                                                             //~v5i8I~
#include <udos.h>       //udosiswinnt                              //~v177R~
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053M~
		#include <ueh.h>                                           //~v053I~
		#include <udpmisub.h>                                      //~v176I~
    #else                       //not DPMI                         //~v053M~
    #endif                      //DPMI or not                      //~v053M~
#include <uehdump.h>                                               //~v027I~
#else                                                              //~v027I~
    #ifdef W32                                                     //~v177I~
		#include <ukbd.h>     //uget/setconsolemode                //~v177R~
		#include <ukbdw.h>     //uget/setconsolemode               //~v177I~
    #endif                                                         //~v177I~
#endif                                                             //~v027I~
#ifdef WXE                                                         //~v570I~
	#include "wxexei.h"                                            //~v570I~
#endif                                                             //~v570I~
#ifdef XXE                                                         //~v6h2I~
	#include "xxexei.h"                                            //~v6h2I~
#endif                                                             //~v6h2I~
#include <uproc2.h>                                                //~v5kuI~
#include <utf.h>                                                   //~v60rI~
#include <ucvext.h>                                                //~v5n8I~
#include <ucvebc.h>                                                //~v6m2I~
#include <ufile.h>                                                 //~vaucI~
#include <ufile2.h>                                                //~v6T7I~
#include <ufilew.h>                                                //~vaucI~
#define UFTIME                                                     //~v711I~
#include <umiscf.h>                                                //~v711I~
//*******************************************************
#define MAXPARM   10
#define MAXTITLE    64
//#define MAXMSGLL  4096                                           //~v5j3R~
#define MAXMSGLL  MAX_UERRMSGLL                                    //~v5j3R~
//#define UERRMSG_MAXPARM   10                                       //~v5nDI~//~v6hhR~
#ifdef W32UNICODE                                                  //~vaucI~
	#define MAX_PRINTFW_MSGSZ  4096                                //~vaucI~
#endif                                                             //~vaucI~
#define ERRFNM_STACK  "xeerrmsg"                                   //~v6T7R~
//*******************************************************
//*errmsg and exit
//*******************************************************
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
    #else                       //not DPMI                         //~v053I~
#ifdef DOSDUMP                                                     //~v57uI~
extern	PEPATBL Gpepatbl;		//for uerrexit                     //~v027I~
#endif                                                             //~v57uI~
    #endif                      //DPMI or not                      //~v053I~
#endif                                                             //~v027I~
//*******************************************************          //~v027I~
//static int  Sdbcsenv=0;         //1:SBCS,2:DBCS                  //~v060R~
static int  Sbellopt=1;                                            //~v293R~
static int *Spbellctr;                                             //~v297I~
static int  Sbellctr=0;                                            //~v50VR~
//static ULONG Sbellcaller=0;                                      //~v530R~
static struct timeb Sbelltime;                                     //~v297R~
                                                                   //~v297I~
static int  Smsgsetflag=0;
static int 	Smsgcatsw=0;			//msg concat sw                //~v200I~
static int  Suerrexitopt=0;                                        //~v191I~
//static char Smsgsave[MAXMSGLL];                                  //~v5mKR~
static char S_msgsave[MAXMSGLL];                                   //~v5mKR~
static char *Smsgsave=S_msgsave;                                   //~v5mKR~
static int Smaxmsgll=MAXMSGLL;                                     //~v5mKR~

static char  Spopupsw;		//popup msg use sw                  //~5902I~
static int   Suerropt; 		 //uerrmsg option(english forc)     //~5B11I~
static int   Sinit1=0;		//init called sw
static FILE *Shandle1;
static char  Stitle1[MAXTITLE]="";
static int   Sinit2=0;		//init called sw
static FILE *Shandle2;
static char  Stitle2[MAXTITLE]="";
static UEXITFUNC *Sexitfunc;
static UPOPUPMSG *Supopupmsg;	//upopupmsg func addr           //~5902R~
static void *Sexitparm;
static UCHAR Sexitmapfile[_MAX_PATH];                              //~v101R~
#ifndef ARM                                                        //~v702I~
static FILE *Sfhstack;                                             //~v6T7I~
static char *Sworkdir;                                             //~v6T7I~
#endif                                                             //~v702M~
//****************************
static unsigned char Sattr2='\x17';	//default:white char on blue back ground
//******************************************************
//char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,unsigned long *Pparg);//~v570R~
void uerrmsg_initstack(char *Pmsg);                                //~v6T7R~
//*******************************************************
//*dummy for LIB(same name as file)						*
//*******************************************************
void uerr(void)
{
	return;
}
//*******************************************************          //~v293I~
//*alarm option                                                    //~v293I~
//*parm1:beep option 0:off else on                                 //~v293I~
//*retrn:previous option value                                     //~v293I~
//*******************************************************          //~v293I~
int ubell_init(int Popt)                                           //~v293I~
{                                                                  //~v293I~
	int prev;                                                      //~v293I~
//****************	                                               //~v293I~
	prev=Sbellopt;                                                 //~v293I~
    Sbellopt=Popt;                                                 //~v293I~
    return prev;                                                   //~v293R~
}//ubell_init                                                      //~v293I~
//*******************************************************          //~v297I~
//*alarm option                                                    //~v297I~
//*parm1:beep option 0:off else on                                 //~v297I~
//*retrn:previous option value                                     //~v297I~
//*******************************************************          //~v297I~
void ubell_init2(int *Pkbdinpctr)                                  //~v297I~
{                                                                  //~v297I~
//****************                                                 //~v297I~
    Spbellctr=Pkbdinpctr;                                          //~v297I~
    return;                                                        //~v297I~
}//ubell_init                                                      //~v297I~
//*******************************************************
//*alarm 
//*******************************************************
void ubell(void)
{
//  ULONG dummyparm;    //dont move this var;place just after func stmt//~v530R~
#if defined(DOS) && !defined(DPMI)                                 //~v297I~
	#define RET_ADDR_POS    6	//ret addr pos(size of ULONG+BP(2))//~v297I~
#else                                                              //~v297I~
	#define RET_ADDR_POS    8   //return addr pos(size of ULONG+BP(4))//~v297I~
#endif                                                             //~v297I~
                                                                   //~v297I~
#ifdef DPMI                                                        //~v176M~
	union REGS regs;                                               //~v176M~
#else                                                              //~v176I~
    #ifdef W32                                                     //~v177I~
     #ifndef WXE                                                   //~v570I~
        int mode;                                                  //~v177I~
     #endif                                                        //~v570I~
    #endif                                                         //~v177I~
//static char *Sbell="\x07";                                       //~v178R~
#endif                                                             //~v176I~
#define UBELL_LIMIT 500     //ms                                   //~v530R~
	int sec,ms;                                                    //~v530R~
//*****************
//	uviowrttty(Sbell,1);                                        //~5902R~
	UTRACEP("%s:opt=%x\n",UTT,Sbellopt);                           //~v702I~
    if (!Sbellopt)                                                 //~v293I~
        return;                                                    //~v293I~
    if (Spbellctr)		//bellctr chk required                     //~v297I~
    {                                                              //~v297I~
        int   oldctr;                                              //~v297I~
		struct timeb oldtime;                                      //~v297I~
                                                                   //~v297I~
        oldctr=Sbellctr;                                           //~v297R~
    	Sbellctr=*Spbellctr;                                       //~v297I~
//      dummyparm=Sbellcaller;                                     //~v530R~
//      Sbellcaller=(ULONG)*(ULONG*)((ULONG)&dummyparm+RET_ADDR_POS);//~v530R~
        memcpy(&oldtime,&Sbelltime,sizeof(oldtime));               //~v297R~
//      ftime(&Sbelltime);                                         //~v297R~//~v711R~
        uftime(&Sbelltime);                                        //~v711I~
//UTRACEP("ctr=%d,time=%08x.%d\n",Sbellctr,Sbelltime.time,(int)Sbelltime.millitm);//~v5g8R~
    	if (Sbellctr==(oldctr+1)	//cont key down                //~v297R~
//      &&  Sbellcaller==dummyparm      //same caller              //~v530R~
//      &&  ( (Sbelltime.time==oldtime.time)     //in a second     //~v530R~
//          ||(  Sbelltime.time==(oldtime.time+1)  //next second   //~v530R~
//            && Sbelltime.millitm<oldtime.millitm //but in a second//~v530R~
//            )                                                    //~v530R~
//          )                                                      //~v530R~
           )                                                       //~v297I~
        {                                                          //~v530I~
			ms=Sbelltime.millitm-oldtime.millitm; //milisec        //~v530I~
//  		sec=Sbelltime.time-oldtime.time;     //in a second     //~v61jR~
    		sec=(int)(Sbelltime.time-oldtime.time);     //in a second//~v61jI~
            if (ms<0)                                              //~v530I~
            {                                                      //~v530I~
            	sec--;                                             //~v530I~
                ms+=1000;                                          //~v530I~
            }                                                      //~v530I~
//UTRACEP("bell ms=%d,sec=%d,millitm=%d,time=%d\n",                //~v5g8R~
//ms,sec,Sbelltime.millitm,Sbelltime.time);                        //~v5g8R~
            if (!sec && ms<UBELL_LIMIT)                            //~v530R~
            	return;                                            //~v297I~
        }                                                          //~v530I~
//UTRACEP("bell\n");                                               //~v5g8R~
    }                                                              //~v297I~
#ifdef W32                                                         //~v175I~
 #ifdef WXE			//mfc                                          //~v570I~
    Beep(400,100);                                                 //~v570I~
 #else                                                             //~v570I~
  if (udosiswinnt())                                               //~v177I~
    Beep(400,100);  //for NT frequency and duration(ms),for W95 it is ignored//~v175I~
  else                                                             //~v177I~
  {                                                                //~v177I~
    mode=ugetconsolemode(1);     //stdout console mode             //~v177I~
//  UTRACEP("%s:mode=%s\n",UTT,mode);                              //+v711R~
    if (mode & ENABLE_PROCESSED_OUTPUT)//avail bell,cr,lf,bs       //~v177I~
      putch(7);                                                    //~v177I~
    else                                                           //~v177I~
    {                                                              //~v177I~
	    usetconsolemode(1,mode | ENABLE_PROCESSED_OUTPUT);     //stdout console mode//~v177R~
      	putch(7);                                                  //~v177I~
	    usetconsolemode(1,mode);     //stdout console mode         //~v177I~
    }                                                              //~v177I~
  }//win95                                                         //~v177R~
 #endif //!WXE                                                     //~v570I~
#else                                                              //~v175I~
  #ifdef DPMI                                                      //~v176I~
    regs.h.ah = 0x0e;     /* teletype write */                     //~v176I~
    regs.h.al = 0x07;     /* bell,it is not displayed like as CR,LF,BS *///~v176I~
    udpmiint86(0x10,&regs,&regs);                                  //~v176I~
  #else                                                            //~v176I~
//  printf(Sbell);                                                 //~v178R~
//  fflush(stdout);                                                //~v178R~
    #ifdef UNX	                                                   //~v324I~
      #ifdef XXE                                                   //~v5g8I~
    	xxe_beep();		//use gdk                                  //~v5g8I~
      #else                                                        //~v5g8I~
    	uviol_beep();		//use ncurses                          //~v324R~
      #endif                                                       //~v5g8I~
    #else                                                          //~v324I~
    putch(7);                                                      //~v178I~
    #endif                                                         //~v324I~
  #endif                                                           //~v176I~
#endif                                                             //~v175I~
	return;
}
//******************************************************
void uerrexit_init(char *Ptitle,FILE *Poutput,char *Pmapfile,UEXITFUNC *Pexitfunc,void *Pexitparm)
{
//****************************
#ifdef DOS                                                         //~v022R~
    #ifdef DPMI					//DPMI version //@@@@temp          //~v053I~
    #else                       //not DPMI                         //~v053I~
#ifdef DOSDUMP                                                     //~v57uI~
	usetmainebp((ULONG)*(UINT*)((ULONG)&Ptitle-6));//in ufuncmap
#endif                                                             //~v57uI~
    #endif                      //DPMI or not                      //~v053I~
#else
	#ifdef W32                                                     //~v022I~
	  #ifndef WXE                                                  //~v570I~
	   #ifndef MGW32                                               //~v5ncI~
	   #ifndef ULIB64X                                             //~v6hiI~
//  	usetmainebp((ULONG)*(UINT*)((ULONG)&Ptitle-8));//caller ebp s.a//~v022I~//~v6hhR~
    	usetmainebp((ULPTR)*(ULPTR*)((ULPTR)&Ptitle-8));//caller ebp s.a//~v6hhI~
	   #endif //ULIB64X                                            //~v6hiI~
	   #endif //MINGW                                              //~v5ncI~
	  #endif //!WXE                                                //~v570I~
	#else                                                          //~v022I~
	#endif                                                         //~v022I~
#endif
    Sinit1=1;		//init called sw
	if (Ptitle)
		strcpy(Stitle1,Ptitle);
	else
		*Stitle1=0;
	Shandle1=Poutput;
	Sexitfunc=Pexitfunc;
	if (Pmapfile)
//  	strcpy(Sexitmapfile,Pmapfile);                             //~v101R~
    	strncpy(Sexitmapfile,Pmapfile,_MAX_PATH-1);                //~v101R~
	else
		*Sexitmapfile=0;
	Sexitparm=Pexitparm;
	return;
}//errexit_init                                                 //~5826R~

//*********************************************************************//~v191I~
//*set uerrexit option                                             //~v191I~
//*********************************************************************//~v191I~
void uerrexit_optinit(int Popt)                                    //~v191I~
{                                                                  //~v191I~
//****************************                                     //~v191I~
    Suerrexitopt=Popt;                                             //~v191I~
	return;                                                        //~v191I~
}//uerrexit_optinit                                                //~v191I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//*********************************************************************//~v60bI~
//*set uerrexit option                                             //~v60bI~
//*********************************************************************//~v60bI~
int uerrsetopt2(unsigned int Pon,unsigned int Poff)                //~v60bI~
{                                                                  //~v60bI~
//****************************                                     //~v60bI~
    Guerropt2|=Pon;                                                //~v60bR~
    Guerropt2&=~(Poff);                                            //~v60bR~
	return (int)Guerropt2;                                         //~v5nnR~
}//uerrsetopt2                                                     //~v60bI~
//#endif                                                           //~v5n8R~
//******************************************************
//* msg and exit
//******************************************************
void uerrexit(char *Pemsg ,char *Pjmsg,... )
{
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
#ifdef WXE                                                         //~v570I~
//  unsigned long *parm;                                           //~v570I~//~v5nDR~
	char *pmsg;                                                    //~v570I~
#else                                                              //~v570I~
#ifndef XXE                                                        //~v6h2I~
static char Sentrysw=0;                                            //~v50VR~
#endif	                                                           //~v6h2R~
//  unsigned long *parm;                                           //~v5nDR~
	char *pmsg;                                                    //~v324R~
#ifndef UNX                                                        //~v324I~
  #ifndef MGW32                                                    //~v5ncI~
    #ifndef ULIB64X                                                //~v6hiI~
	char *ppathmsg=0;                                              //~v324I~
    #endif                                                         //~v6hiI~
  #endif                                                           //~v5ncI~
#endif //!UNX                                                      //~v324I~
#ifdef DOS                                                         //~v027I~
    #ifdef DPMI					//DPMI version                     //~v053I~
    #else                       //not DPMI                         //~v053I~
        USHORT segcs,segds,segss;                                  //~v070I~
    char *abinfmsg[2];                                             //~v027M~
	char dumpfnm[_MAX_PATH];                                       //~v027R~
    #endif                      //DPMI or not                      //~v053I~
#endif                                                             //~v027I~
#endif //!WXE                                                      //~v570M~
//****************************
//get parm addr
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v5nDR~
//  UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhR~
#ifdef LNX                                                         //~v6v0R~
	Guerropt2|=GBL_UERR2_UTF8STDO;   //for xsub(not xe),printf to stdout of LNX UTF8 env;cv sjis2utf8 for Pjmsg//~v6v0R~
#endif                                                             //~v6v0R~
//  UTRACEDIFNZ("uerrexit Pjmsg",Pjmsg,strlen(Pjmsg));             //~v70nR~
	pmsg=uerrmsgedit(Stitle1,Pemsg,Pjmsg,parm);                    //~v060R~
//  UTRACEDIFNZ("uerrexit msg",pmsg,strlen(pmsg));                 //~v70nR~
#if defined(WXE)||defined(LNX)  //*W32 console has exception handler, put trace from it//~v6VwR~
    UTRACEPF2("%s:msg=%s\n",UTT,pmsg);                             //~v6VwR~
    utrace_term(0);                                                //~v6VwI~
#endif                                                             //~v6VwI~
#if defined(XXE) && !defined(ARM)                                  //~v6h2I~
   	wxe_uerrexitmsgbox(pmsg);                                      //~v6h2R~
#else                                                              //~v6h2I~
#if defined(XXE) && defined(ARM)                                   //~v6a0I~
   	wxe_uerrexitstdo(pmsg);                                        //~v6a0I~
#else                                                              //~v6a0I~
#ifdef WXE                                                         //~v570I~
   	wxe_uerrexitstdo(pmsg);                                        //~v570I~
#else                                                              //~v570I~
    if (Sentrysw)                                                  //~v029I~
    {                                                              //~v029I~
//  	if (Sentrysw==1)                                           //~v168R~
	    if (Shandle1)  		//init not called                      //~v168I~
#ifdef WCSUPP                                                      //~v5n8I~
			uerrfprintfutf(UERRFPUO_NOEDIT,Shandle1,"%s\n",pmsg);  //~v5n8R~
#else                                                              //~v5n8I~
			fprintf(Shandle1,"%s\n",pmsg);                         //~v029I~
#endif                                                             //~v5n8I~
        else                                                       //~v168I~
#ifdef W32UNICODE                                                  //~vaucI~
			uprintfW("%s\n",pmsg);                                 //~vaucI~
#else                                                              //~vaucI~
			printf("%s\n",pmsg);                                   //~v168I~
#endif                                                             //~vaucI~
		printf("Error in error process,program terminate!!\n");    //~v168I~
	    if (Suerrexitopt & UERREXIT_BELL)                          //~v191I~
        {                                                          //~v293I~
        	Sbellopt=1;     //beep force on                        //~v293I~
    		ubell();                                               //~v191I~
		}                                                          //~v293I~
		exit(16);                                                  //~v029I~
	}                                                              //~v029I~
	Sentrysw++;                                                    //~v029I~
    if (!Sinit1)  		//init not called 
		Shandle1=stdout;
	if (Sexitfunc)                                              //~4C23I~
		Sexitfunc(pmsg,Sexitparm);                                 //~v027R~
	if (Shandle1)
	{	
#ifdef WCSUPP                                                      //~v5n8I~
		uerrfprintfutf(UERRFPUO_NOEDIT,Shandle1,"%s\n",pmsg);      //~v5n8R~
#else                                                              //~v5n8I~
		fprintf(Shandle1,"%s\n",pmsg);                          //~5827M~
#endif                                                             //~v5n8I~
#ifndef UNX                                                        //~v324I~
		if (*Sexitmapfile)
		{
#if defined(DOS) && !defined(DPMI) && !defined(DOSDUMP)            //~v57uI~
#else                                                              //~v57uI~
        #ifndef MGW32                                              //~v5ncI~
        #ifndef ULIB64X                                            //~v6hiI~
//  		ppathmsg=ufuncpathmsg(Sexitmapfile,(unsigned long)0,(unsigned long)0);//~v6hhR~
			ppathmsg=ufuncpathmsg(Sexitmapfile,        (ULPTR)0,        (ULPTR)0);//~v6hhR~
			fprintf(Shandle1,ppathmsg);
        #endif //!ULIB64X                                          //~v6hiI~
        #endif //!MINGW                                            //~v5ncI~
#endif                                                             //~v57uI~
#ifdef DOS                                                         //~v070I~
    #ifdef DPMI					//DPMI version                     //~v070I~
    #else                       //not DPMI                         //~v070I~
            _asm mov segcs,cs                                      //~v070R~
            _asm mov segds,ds                                      //~v070R~
            _asm mov segss,ss                                      //~v070R~
			fprintf(Shandle1,"CS=%04x,DS=%04x,SS=%04x\n",segcs,segds,segss);//~v070I~
    #endif                      //DPMI or not                      //~v070I~
#endif                                                             //~v070I~
			fprintf(Shandle1,"\n");                             //~5827I~
		}
#endif //!UNX                                                      //~v324I~
	}
#ifdef DOS                                                      //~5827I~
    #ifdef DPMI					//DPMI version                     //~v053I~
        fcloseall();                                               //~v053I~
    #else                       //not DPMI                         //~v053I~
	if (Sexitfunc)                                                 //~v027I~
    {                                                              //~v027I~
		*dumpfnm=0;                                                //~v027I~
		Sexitfunc((char *)(ULONG)-1,dumpfnm);	//ger dumpfile name//~v027R~
    	if (*dumpfnm)                                              //~v027R~
        {                                                          //~v027I~
            abinfmsg[0]=pmsg;                                      //~v027R~
            abinfmsg[1]=ppathmsg;                                  //~v027R~
#ifdef DOSDUMP                                                     //~v57uI~
    		uehdump(dumpfnm,abinfmsg,Gpepatbl);	//dos dump         //~v027R~
#endif                                                             //~v57uI~
        }                                                          //~v027I~
	}                                                              //~v027M~
    fcloseall();                                                //~5827I~
    #endif                      //DPMI or not                      //~v053I~
#endif                                                          //~5827R~
    if (Suerrexitopt & UERREXIT_BELL)                              //~v191I~
    {                                                              //~v293I~
        Sbellopt=1;     //beep force on                            //~v293I~
    	ubell();                                                   //~v191I~
    }                                                              //~v293I~
	exit(8);
	return;
#endif 		//!WXE                                                 //~v570I~
#endif 		//XXE & ARM                                            //~v6a0I~
#endif 		//XXE & !ARM                                           //~v6h2I~
}//errexit

//******************************************************
//* uerrmsg static initialize
//* parm1:pre-fix string
//* parm2:output handle(if init not called output to stdout)
//*         0 :no output
//*       or upopupmsg function addr if Pattr!=0                //~5902R~
//* parm3: 2nd last byte:                                       //~5B11R~
//*             option, 01:force english                        //~5B11I~
//*        last byte:                                           //~5B11I~
//* 		 	0 for no upopupmsg function use                 //~5B11I~
//*        		attr byte for popup msg,if ff default is white on blue//~5B11R~
//******************************************************
void uerrmsg_init(char *Ptitle,FILE *Poutput,int Popt)          //~5B11R~
{
	int szpower,sz,ii;                                             //~v5mKR~
    char *pc;                                                      //~v5mKR~
//****************************
    Sinit2=1;		//init called sw
	if (Ptitle)
		strcpy(Stitle2,Ptitle);
	else
		*Stitle2=0;
	Suerropt=(Popt & UERR_OPTION);                              //~5B11R~
	if (Popt & UERR_ATTR)	//upopupmsg use                     //~5B11R~
    {                                                           //~5902I~
    	Spopupsw=1;                                             //~5902I~
//		Supopupmsg=(UPOPUPMSG*)(ULONG)Poutput;	//upopupmsg func addr//~v59wR~//~v6hhR~
		Supopupmsg=(UPOPUPMSG*)(ULPTR)Poutput;	//upopupmsg func addr//~v6hhI~
		if ((Popt&UERR_ATTR)!=UERR_ATTR)		//not default   //~5B11R~
			Sattr2=(UCHAR)(Popt&UERR_ATTR);                     //~5B11R~
	}                                                           //~5902I~
    else                                                        //~5902I~
		Shandle2=Poutput;                                       //~5902I~
    if (Popt & UERR_FORCE_ENGLISH)                                 //~v5bzI~
    	UCBITON(Guerropt,GBL_UERR_FORCEENG);                       //~v5bzI~
    else                                                           //~v5bzI~
    	UCBITOFF(Guerropt,GBL_UERR_FORCEENG);                      //~v5bzI~
    szpower=UERR_GETSIZEPOWER(Popt);                               //~v5mKR~
    if (szpower)                                                   //~v5mKR~
    {                                                              //~v5mKR~
    	for (sz=MAXMSGLL,ii=0;ii<szpower;ii++)                     //~v5mKR~
    		sz*=2;                                                 //~v5mKR~
        if (sz)                                                    //~v5mKR~
        {                                                          //~v5mKR~
        	pc=malloc((UINT)sz);                                   //~v5mKR~
            if (!pc)                                               //~v5mKR~
            	uerrexit("malloc(len=%d) failed for errmsg",0,     //~v5mKR~
                			sz);                                   //~v5mKR~
            Smsgsave=pc;                                           //~v5mKR~
            Smaxmsgll=sz;                                          //~v5mKR~
        }                                                          //~v5mKR~
    }                                                              //~v5mKR~
	return;
}//errmsg_init                                                     //~v61jR~

//******************************************************
//* msg edit and output                                            //~v060R~
//******************************************************
char *uerrmsg(char *Pemsg ,char *Pjmsg,... )
{
//  unsigned long *parm;                                           //~v5nDR~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
	char *pmsg;
#ifdef LNX                                                         //~v6DjI~
     int prevlen=0;                                                //~v6DjI~
#endif                                                             //~v6DjI~
//****************************
//get parm addr
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v5nDR~
//  UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDR~//~v6hhR~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhR~

#ifdef LNX                                                         //~v6DjI~
	if (Smsgcatsw)		//parm to uerrmsgedit                      //~v6DjI~
    	 prevlen=(int)strlen(Smsgsave);                            //~v6DjI~
#endif                                                             //~v6DjI~
	pmsg=uerrmsgedit(Stitle2,Pemsg,Pjmsg,parm);                    //~v060R~

 	UTRACED("errmsg",pmsg,(int)strlen(pmsg));                               //~v5i8R~//~v6BkR~


    if (!Sinit2) 		//init not called 
		Shandle2=stdout;
  if (!(Guerropt & GBL_UERR_NOMSGOUT)) //*edit only,no output to any//~v062I~
  {                                                                //~v062I~
    if (Spopupsw)                                               //~5902I~
		Supopupmsg(pmsg,Sattr2);                                //~5902R~
	else
		if (Shandle2)
        {                                                          //~v570I~
#ifdef WXE                                                         //~v570I~
    		wxe_uerrmsgstdo(pmsg);                                 //~v570I~
#else                                                              //~v570I~
	#ifdef WCSUPP                                                  //~v5n8I~
#ifdef LNX                                                         //~v6v0R~
		    if (Pjmsg     //sis2utf8                               //~v6v0R~
    		&&  UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC))	//conv sjis to euc//~v6v0R~
            {                                                      //~v6v0R~
				if (Smsgcatsw)		//parm to uerrmsgedit          //~v6DjI~
                	*(Smsgsave+prevlen)=0;  //avoid duplicated cat by next uerrmsgedit//~v6DjR~
				Guerropt2|=GBL_UERR2_UTF8STDO;   //for xsub(not xe),printf to stdout of LNX UTF8 env;cv sjis2utf8 for Pjmsg//~v6v0R~
				pmsg=uerrmsgedit(Stitle2,Pemsg,Pjmsg,parm);        //~v6v0R~
            }                                                      //~v6v0R~
#endif                                                             //~v6v0R~
			uerrfprintfutf(UERRFPUO_NOEDIT,Shandle2,"%s\n",pmsg);  //~v5n8R~
	#else                                                          //~v5n8I~
			fprintf(Shandle2,"%s\n",pmsg);                     //~4C18R~
    #endif                                                         //~v5n8I~
#endif                                                             //~v570I~
        }                                                          //~v570I~
  }	                                                               //~v062I~
    if (Guerropt2 & GBL_UERR2_INIT_INPROG) //xe init in progress   //~v6T7M~
		uerrmsg_initstack(pmsg);                                   //~v6T7I~
	return pmsg;
}//uerrmsg                                                         //~v060R~

//******************************************************           //~v182I~
//* msg edit and output                                            //~v182I~
//*  only when previous msg is not pending                         //~v182I~
//*rc :msg text or 0 if already set                                //~v182I~
//******************************************************           //~v182I~
char *uerrmsg2(char *Pemsg ,char *Pjmsg,... )                      //~v182I~
{                                                                  //~v182I~
//  unsigned long *parm;                                           //~v182I~//~v5nDR~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
	char *pmsg;                                                    //~v182I~
//****************************                                     //~v182I~
//get parm addr                                                    //~v182I~
	if (Smsgsetflag)		//already set errmsg                   //~v182I~
    	return 0;                                                  //~v182I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v182I~//~v5nDR~
//  UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhR~
	pmsg=uerrmsgedit(Stitle2,Pemsg,Pjmsg,parm);                    //~v182I~
    if (!Sinit2) 		//init not called                          //~v182I~
		Shandle2=stdout;                                           //~v182I~
  if (!(Guerropt & GBL_UERR_NOMSGOUT)) //*edit only,no output to any//~v182I~
  {                                                                //~v182I~
    if (Spopupsw)                                                  //~v182I~
		Supopupmsg(pmsg,Sattr2);                                   //~v182I~
	else                                                           //~v182I~
		if (Shandle2)                                              //~v182I~
        {                                                          //~v5nnI~
#ifdef WXE                                                         //~v570I~
    		wxe_uerrmsgstdo(pmsg);                                 //~v570I~
#else                                                              //~v570I~
	#ifdef WCSUPP                                                  //~v5n8I~
			uerrfprintfutf(UERRFPUO_NOEDIT,Shandle2,"%s\n",pmsg);  //~v5n8R~
	#else                                                          //~v5n8I~
			fprintf(Shandle2,"%s\n",pmsg);                         //~v182I~
    #endif                                                         //~v5n8I~
#endif                                                             //~v570I~
        }//Shandle2                                                //~v5nnI~
  }                                                                //~v182I~
    if (Guerropt2 & GBL_UERR2_INIT_INPROG) //xe init in progress   //~v6T7I~
		uerrmsg_initstack(pmsg);                                   //~v6T7I~
	return pmsg;                                                   //~v182I~
}//uerrmsg2                                                        //~v182I~
                                                                   //~v182I~
//******************************************************           //~v200I~
//* msg edit and output conatinationg prev msg                     //~v200I~
//*rc :msg top(may be of previous)                                 //~v200I~
//******************************************************           //~v200I~
char *uerrmsgcat(char *Pemsg ,char *Pjmsg,... )                    //~v200I~
{                                                                  //~v200I~
//  unsigned long **parm;                                          //~v200I~//~v5nDR~
//  unsigned long *parm[UERRMSG_MAXPARM];                          //~v5nDI~//~v6hhR~
	ULPTR parm[UERRMSG_MAXPARM];                                   //~v6hhR~
	char *pmsg;                                                    //~v200I~
//****************************                                     //~v200I~
//get parm addr                                                    //~v200I~
	if (Smsgsetflag)		//already set errmsg                   //~v200I~
		Smsgcatsw=1;		//parm yo uerrmsgedit                  //~v200R~
//  parm=(unsigned long**)(ULONG)((&Pjmsg)+1);                     //~v200R~//~v5nDR~
//  UGETSTDARG(unsigned long*,parm,Pjmsg,UERRMSG_MAXPARM);         //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR,         parm,Pjmsg,UERRMSG_MAXPARM);         //~v6hhR~
	pmsg=uerrmsg(Pemsg,Pjmsg,parm[0],parm[1],parm[2],parm[3],parm[4],//~v200I~
	             parm[5],parm[6],parm[7],parm[8],parm[9]);         //~v200I~
	Smsgcatsw=0;                                                   //~v200I~
	return pmsg;                                                   //~v200I~
}//uerrmsgcat                                                      //~v200I~
                                                                   //~v200I~
//******************************************************           //~v060I~
//* msg edit only with no title                                    //~v060I~
//******************************************************           //~v060I~
char *uerrsprintf(char *Pemsg ,char *Pjmsg,... )                   //~v060I~
{                                                                  //~v060I~
//  unsigned long *parm;                                           //~v060I~//~v5nDR~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
	char *pmsg;                                                    //~v060I~
    int timestampsw;                                               //~v5j3I~
//****************************                                     //~v060I~
//get parm addr                                                    //~v060I~
	timestampsw=(Suerropt & UERR_TIMESTAMP);                       //~v5j3I~
    if (timestampsw)                                               //~v5j3I~
		Suerropt &=~UERR_TIMESTAMP;                                //~v5j3I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v060I~//~v5nDR~
//  UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhR~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                         //~v060I~
    if (timestampsw)                                               //~v5j3I~
		Suerropt |=UERR_TIMESTAMP;                                 //~v5j3I~
	return pmsg;                                                   //~v060I~
}//uerrsprint                                                      //~v060I~
#ifdef WCSUPP                                                      //~v5n8R~
//******************************************************           //~v5n8I~
//* msg edit only with no title                                    //~v5n8I~
//* NOEDIT option: uerrfprintfutf(opt,fh,pattern,msg);             //~v5n8I~
//*   EDIT option: uerrfprintfutf(opt,fh,patterne,patternj,parm1,...);//~v5n8I~
//******************************************************           //~v5n8I~
int uerrfprintfutf(int Popt,FILE *Pfh,char *Pemsg ,char *Pjmsg,... )//~v5n8I~
{                                                                  //~v5n8I~
//  unsigned long *parm;                                           //~v5n8I~//~v5nDR~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
	UCHAR *pmsg,*pdbcstbl;                                         //~v5n8R~
    int timestampsw,len,outlen,rc;                                 //~v5n8R~
    FILE *fh;                                                      //~v5n8I~
    char wk[MAXMSGLL*UTF8_MAXCHARSZ+2];                            //~v5n8I~
//  ULONG pl2uconverters;                                          //~v5n8R~//~v6hhR~
    ULPTR pl2uconverters;                                          //~v6hhI~
//  ULONG a2aconverters[3];                                        //~v5n8I~//~v6f3R~
//  ULONG a2aconverters[7];                                        //~v6f3I~//~v6hhR~
    ULPTR a2aconverters[7];                                        //~v6hhI~
//****************************                                     //~v5n8I~
	if (!(fh=Pfh))                                                 //~v5n8I~
    	fh=stdout;                                                 //~v5n8I~
	if (Popt & UERRFPUO_NOEDIT)	//msg by uerrmsgedit               //~v5n8I~
    	pmsg=Pjmsg;                                                //~v5n8R~
    else                                                           //~v5n8I~
    {                                                              //~v5n8I~
#ifdef LNX                                                         //~v6v0R~
		Guerropt2|=GBL_UERR2_UTF8STDO;   //for xsub(not xe),printf to stdout of LNX UTF8 env;cv sjis2utf8 for Pjmsg//~v6v0R~
#endif                                                             //~v6v0R~
        timestampsw=(Suerropt & UERR_TIMESTAMP);                   //~v5n8I~
        if (timestampsw)                                           //~v5n8I~
            Suerropt &=~UERR_TIMESTAMP;                            //~v5n8I~
//      parm=(unsigned long*)(void*)((&Pjmsg)+1);                  //~v5n8I~//~v5nDR~
//  	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);      //~v5nDI~//~v6hhR~
		UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);      //~v6hhR~
        pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                     //~v5n8I~
        if (timestampsw)                                           //~v5n8I~
            Suerropt|=UERR_TIMESTAMP;                              //~v5n8I~
    }                                                              //~v5n8I~
#ifdef LNX                                                         //~v6v0R~
	if (!(Popt & UERRFPUO_CVL2F))	//msg by uerrmsgedit           //~v6v0R~
    	Guerropt2|=GBL_UERR2_NOCONV1;                              //~v6v0R~
#endif                                                             //~v6v0R~
    if (Gudbcschk_flag & UDBCSCHK_UTF8)    //euc or utf8//~v5i8I~, //~v5n8R~
    {                                                              //~v5n8I~
      if (!(Guerropt2 & (GBL_UERR2_NOCONV|GBL_UERR2_NOCONV1)))     //~v694I~
      {                                                            //~v694I~
    	if (!udbcschk_getbaseconverter(0,&pl2uconverters,&pdbcstbl))//~v5n8R~
        {                                                          //~v5n8I~
		  if (UDBCSCHK_IS_LOCALICU())                              //~v6f3I~
          {                                                        //~v6f3I~
        	a2aconverters[0]=*(ULONG*)pl2uconverters;              //~v6f3I~
//        	a2aconverters[1]=(ULONG)pdbcstbl;                      //~v6f3I~//~v6hhR~
        	a2aconverters[1]=(ULPTR)pdbcstbl;                      //~v6hhI~
//  		len=strlen(pmsg);                                      //~v6f3I~//~v6BkR~
    		len=(int)strlen(pmsg);                                 //~v6BkI~
        	len=min(len,MAXMSGLL);                                 //~v6f3I~
			rc=ucvext_icumb2utf(0,a2aconverters,pmsg,len,wk,sizeof(wk),0/*repch*/,0/*chklen*/,&outlen,0/*repctr out*/);//~v6f3R~
          }                                                        //~v6f3I~
          else                                                     //~v6f3I~
          {                                                        //~v6f3I~
        	a2aconverters[HICONV_CPTO]=0; //ucs2locale=0 means to utf8//~v5n8R~
        	a2aconverters[HICONV_CPFROM]=pl2uconverters;           //~v5n8R~
//        	a2aconverters[HICONV_DBCSSTARTER]=(ULONG)pdbcstbl;     //~v5n8R~//~v6hhR~
        	a2aconverters[HICONV_DBCSSTARTER]=(ULPTR)pdbcstbl;     //~v6hhI~
//  		len=strlen(pmsg);                                      //~v5n8I~//~v6BkR~
    		len=(int)strlen(pmsg);                                 //~v6BkI~
        	len=min(len,MAXMSGLL);                                 //~v5n8I~
//  		rc=ucvext_iconva2as(UCVEXTO_TOUTF8,a2aconverters,pmsg,0/*dbcs*/,len,wk,sizeof(wk),0/*chklen*/,&outlen,'?',0/*repctr out*/);//~v5n8R~//~v6m2R~
            UCVEXT_TOUTF8_ON();                                    //~v6m2I~
    		rc=ucvext_iconva2as(0,a2aconverters,pmsg,0/*dbcs*/,len,wk,sizeof(wk),0/*chklen*/,&outlen,'?',0/*repctr out*/);//~v6m2I~
            UCVEXT_TOUTF8_OFF();                                   //~v6m2I~
          }                                                        //~v6f3I~
        	if (!rc)                                               //~v5n8I~
            {                                                      //~v5n8I~
            	wk[outlen]=0;                                      //~v5n8I~
        		pmsg=wk;                                           //~v5n8I~
            }                                                      //~v5n8I~
        }                                                          //~v5n8I~
      }                                                            //~v694I~
	}                                                              //~v5n8I~
#ifdef LNX                                                         //~v6v0R~
//  Guerropt2&=~GBL_UERR2_NOCONV1;                                 //~v6v0R~//~v6BkR~
    Guerropt2&=~(UINT)GBL_UERR2_NOCONV1;                           //~v6BkI~
#endif                                                             //~v6v0R~
	if (Popt & UERRFPUO_NOEDIT)	//msg by uerrmsgedit               //~v5n8I~
#ifdef W32UNICODE                                                  //~vaucI~
		rc=ufprintfW(fh,Pemsg,pmsg);                               //~vaucI~
#else                                                              //~vaucI~
		rc=fprintf(fh,Pemsg,pmsg);                                 //~v5n8I~
#endif                                                             //~vaucI~
    else                                                           //~v5n8I~
#ifdef W32UNICODE                                                  //~vaucI~
		rc=ufprintfW(fh,"%s",pmsg);                                //~vaucI~
#else                                                              //~vaucI~
		rc=fprintf(fh,"%s",pmsg);                                  //~v5n8R~
#endif                                                             //~vaucI~
    return rc;                                                     //~v5n8I~
}//uerrfprintfutf                                                  //~v5n8I~
#endif //WCSUPP                                                    //~v5n8R~
//******************************************************           //~v060I~
//* uerrhelpmsg:write errmsg and wait kbdhit if screen full        //~v060I~
//* no uerrmsg_init required(pgm and version edit is caller resp)  //~v060I~
//*  when emsg=0;for other msg after helpmsg allow scroll chk;     //~v335I~
//*       jmsg is line cnt after helpmsg                           //~v335I~
//* parm1:msg output handle                                        //~v060I~
//* parm2:screen overflow msg output handle                        //~v060I~
//* parm3:SBCS msg text                                            //~v060I~
//* parm4:DBCS msg text                                            //~v060I~
//* parm5...:sprintf parms                                         //~v060I~
//******************************************************           //~v060I~
char *uerrhelpmsg(FILE *Poutf,FILE *Pqueryf,char *Pemsg ,char *Pjmsg,... )//~v060R~
{                                                                  //~v060I~
static int Shlineno=0;                                             //~v060I~
static int Shlinemax;                   //screen maxline size      //~v060I~
static int Slastcrlfsw=0;                 //last written crlf      //~v50VR~
//  unsigned long *parm;                                           //~v060I~//~v5nDR~
//  unsigned long parm[UERRMSG_MAXPARM];                           //~v5nDI~//~v6hhR~
	ULPTR         parm[UERRMSG_MAXPARM];                           //~v6hhR~
	char *pmsg;                                                    //~v060I~
#ifndef WXE                                                        //~v570I~
    int  ch,crlfsw;                                                //~v060R~
#endif                                                             //~v570I~
#ifdef UNX                                                         //~v50wR~
	char breakmsg[128];                                            //~v50wR~
#ifdef LNX                                                         //~v5i8I~
	char breakmsgutf8[128];                                        //~v5i8I~
    int chklen,outlen,errctr;                                      //~v5i8I~
#endif                                                             //~v5i8I~
#endif                                                             //~v50wR~
//****************************                                     //~v060I~
//get parm addr                                                    //~v060I~
  if (Pemsg)                                                       //~v335I~
  {                                                                //~v335I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v060I~//~v5nDR~
//  UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~v5nDI~//~v6hhR~
	UGETSTDARG(ULPTR,        parm,Pjmsg,UERRMSG_MAXPARM);          //~v6hhR~
#ifdef LNX                                                         //~v6v0R~
#ifdef AAA                                                         //~v6X4R~
	if (Pjmsg)     //sis2utf8                                      //~v6v0R~
#endif                                                             //~v6X4R~
		Guerropt2|=GBL_UERR2_UTF8STDO;   //for xsub(not xe),printf to stdout of LNX UTF8 env;cv sjis2utf8 for Pjmsg//~v6v0R~
#endif                                                             //~v6v0R~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);	//no title             //~v060R~
  }                                                                //~v335I~
  else                                                             //~v335I~
  {                                                                //~v335I~
// 	Shlineno+=(int)Pjmsg;	//last helpmsg followes other msg line //~v335I~//~v690R~
//	Shlineno+=(int)(ULONG)Pjmsg;	//last helpmsg followes other msg line//~v690I~//~v6hhR~
  	Shlineno+=(int)(ULPTR)Pjmsg;	//last helpmsg followes other msg line//~v6hhI~
    pmsg="";                                                       //~v335I~
  }                                                                //~v335I~
#ifdef WXE                                                         //~v570I~
    wxe_uerrmsgstdo(pmsg);                                         //~v570I~
#else                                                              //~v570I~
                                                                   //~v335I~
    if (!(Guerropt & GBL_UERR_BG))	//fore ground                  //~v060I~
    {                                                              //~v060I~
    	if (!Shlineno)				//first time                   //~v060R~
        {                                                          //~v5kuI~
          if (uprocredirectchk(fileno(stdout))==1)    //stdout redirected//~v5kuI~
            Shlinemax=0x7fff;//no limit                            //~v5kuI~
          else                                                     //~v5kuI~
    	    Shlinemax=uerrscrheight()-1;	//get screen size(-1 for query msg)//~v060R~
        }                                                          //~v5kuI~
                                                                   //~v060R~
    	if (Poutf==Pqueryf                                         //~v060R~
        ||  (  (Poutf==stdout   || Poutf==stderr  )                //~v060R~
             &&(Pqueryf==stdout || Pqueryf==stderr) ))             //~v060R~
        	crlfsw=1;       //both same or both to screen          //~v060R~
        else                                                       //~v060R~
        	crlfsw=0;                                              //~v060R~
                                                                   //~v335I~
    	if (Shlineno++>=Shlinemax)                                 //~v060R~
    	{                                                          //~v060R~
    		fflush(Poutf);                                         //~v060R~
        	if (crlfsw && !Slastcrlfsw)                            //~v060R~
    			fprintf(Pqueryf,"\n");                             //~v060R~
//    		if (Sdbcsenv==2)	//DBCS mode                        //~v060R~
//			if (UCBITCHK(Guerropt,(GBL_UERR_SJIS2EUC|GBL_UERR_DBCSMODE)) //dbcs mode//~v5n8R~
    		if (UCBITCHK(Guerropt,GBL_UERR_DBCSMODE)               //~v5n8M~
			&&  !(Suerropt & UERR_FORCE_ENGLISH))                  //~v50wR~
            {                                                      //~v50wR~
#ifdef UNX                                                         //~v50wR~
    			strcpy(breakmsg,"--続き-- キーをどれか押して下さい．．．");//~v50wR~
    			if (UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC))	//conv sjis to euc//~v50wR~
//  				ushift2euc(breakmsg,strlen(breakmsg),breakmsg,0,0);	//sjis-->euc//~v550R~
//    				ushift2euc(breakmsg,0,strlen(breakmsg),breakmsg,0,0,0);	//sjis-->euc//~v550I~//~v6BkR~
      				ushift2euc(breakmsg,0,(int)strlen(breakmsg),breakmsg,0,0,0);	//sjis-->euc//~v6BkI~
#ifdef LNX                                                         //~v5i8I~
                else                                               //~v5i8I~
    			if (UCBITCHK(Guerropt,GBL_UERR_SJIS2UTF8))	//conv sjis to euc//~v5i8I~
                {                                                  //~v5i8I~
                    strcat(breakmsg,"\n");                         //~v5i8I~
//  				ucvssjis2utf(0,0,breakmsg,strlen(breakmsg),breakmsgutf8,sizeof(breakmsgutf8),&chklen,&outlen,&errctr);	//sjis-->euc//~v5i8I~//~v6BkR~
    				ucvssjis2utf(0,0,breakmsg,(int)strlen(breakmsg),breakmsgutf8,sizeof(breakmsgutf8),&chklen,&outlen,&errctr);	//sjis-->euc//~v6BkI~
//                  memcpy(breakmsg,breakmsgutf8,outlen);          //~v5i8I~//~v6BkR~
                    memcpy(breakmsg,breakmsgutf8,(size_t)outlen);  //~v6BkI~
                    *(breakmsg+outlen)=0;                          //~v5i8I~
                }                                                  //~v5i8I~
#endif                                                             //~v5i8I~
#ifdef WCSUPP                                                      //~v5n8I~
				uerrfprintfutf(UERRFPUO_NOEDIT,Pqueryf,"%s",breakmsg);//~v5n8R~
#else                                                              //~v5n8I~
    			fprintf(Pqueryf,breakmsg);                         //~v50wR~
#endif                                                             //~v5n8I~
#else                                                              //~v50wR~
//  			fprintf(Pqueryf,"準備ができたらキーをどれか押して下さい．．．");//~v199R~
    			fprintf(Pqueryf,"--続き-- キーをどれか押して下さい．．．");//~v199R~
#endif                                                             //~v50wR~
            }                                                      //~v50uI~
    		else                                                   //~v060R~
    			fprintf(Pqueryf,"continue--   Press Any Key(\"q\" to exit)");     //~v060R~//~v639R~
    		fflush(Pqueryf);                                       //~v060R~
#ifdef UNX                                                         //~v361I~
	#ifdef ARMXXE                                                  //~v6a0I~
    	ch='\n';                                                   //~v6a0I~
	#else                                                          //~v6a0I~
    		ch=ukbdl_getch(UKBDL_GETCH_ONCE);//fd close after get char//~v39bR~
          if (!Pemsg)   //chk for titlemsg space                   //~v376I~
            printf("\n");   //lf                                   //~v376R~
	#endif //ARMXXE                                                //~v6a0I~
#else                                                              //~v361I~
    		ch=getch();                                            //~v060R~
#endif                                                             //~v361I~
    		Shlineno=1;                                            //~v060R~
            if (ch=='q'||ch=='Q')                                  //~v5f3I~
            {                                                      //~v5faI~
#ifdef UNX                                                         //~v5faI~
            	printf("\n");   //lf                               //~v5faI~
#endif                                                             //~v5faI~
                exit(1);                                           //~v5f3I~
            }                                                      //~v5faI~
    	}                                                          //~v060R~
        else                                                       //~v060R~
        	ch='\n';    //skip insert \n                           //~v060R~
                                                                   //~v335I~
  	  if (Pemsg)                                                   //~v335I~
      {                                                            //~v335I~
    	if (crlfsw)                                                //~v060R~
    		if (*pmsg!='\n' && ch!='\n')                           //~v060R~
    			fprintf(Pqueryf,"\n");                             //~v060R~
	#ifdef WCSUPP                                                  //~v5n8I~
		uerrfprintfutf(UERRFPUO_NOEDIT,Poutf,"%s",pmsg);           //~v5n8R~
	#else                                                          //~v5n8I~
    	fprintf(Poutf,"%s",pmsg);                                  //~v060R~
    #endif                                                         //~v5n8I~
    	if (*pmsg)                                                 //~v060R~
    		Slastcrlfsw=(*(pmsg+strlen(pmsg)-1)=='\n');            //~v060R~
      }                                                            //~v335I~
	}//fore ground                                                 //~v060I~
    else                                                           //~v060I~
	#ifdef WCSUPP                                                  //~v5n8I~
		uerrfprintfutf(UERRFPUO_NOEDIT,Poutf,"%s",pmsg);           //~v5n8R~
	#else                                                          //~v5n8I~
    	fprintf(Poutf,"%s",pmsg);                                  //~v060I~
    #endif                                                         //~v5n8I~
#endif                                                             //~v570I~
	return pmsg;                                                   //~v060I~
}//uerrhelpmsg                                                     //~v060I~
                                                                   //~v060I~
//**********************************************************************//~v060I~
//* retrieve screen height                                         //~v060R~
//**********************************************************************//~v060I~
int uerrscrheight(void)                                            //~v060R~
{                                                                  //~v060I~
#ifdef ARMXXE                                                      //~v6a0I~
    return 32767;		//actualy infinite                         //~v6a0I~
#else                                                              //~v6a0I~
#ifdef NOCURSES                                                    //~v6a0I~
    return 32767;		//actualy infinite                         //~v6a0I~
#else                                                              //~v6a0I~
	VIOMODEINFO modeinfo;                                          //~v060I~
    int rc;                                                        //~v060I~
//***************                                                  //~v060I~
	if ((rc=(int)uviogetmode(&modeinfo),rc))                       //~v060R~
    {                                                              //~v250I~
      	if (rc==1)				//redirected                       //~v250I~
      		return 32767;		//actualy infinite                 //~v250I~
//  	uerrapi0x("uviogetmode",rc);                               //~v250R~
#ifdef UNX                                                         //~v361I~
//uviogetmode failed because uviol_init not called                 //~v361I~
    	if ((rc=LINES)<=0)	//ncurses not called                   //~v362R~
        {                                                          //~v361I~
//		    initscr();                                             //~v363R~
		    unc_setupterm(0);//initscr() is heavy                  //~v363R~
//      	rc=LINES;                                              //~v50VR~
            rc=lines; //cur_term->_c3 defined at term.h            //~v50VI~
//          endwin();                                              //~v363R~
        }                                                          //~v361I~
        if (rc)                                                    //~v361I~
      		return rc;                                             //~v361I~
        else                                                       //~v361I~
      		return 32767;		//actualy infinite                 //~v361I~
#else                                                              //~v361I~
        printf("\nAt uerrscrheight;uviogetmode failed rc=%d\n",rc);//~v250R~
        exit(8);                                                   //~v250I~
#endif //UNX                                                       //~v361I~
    }                                                              //~v250I~
//#ifdef UNX                                                       //~v361R~
//    uviol_term();   //endwin before hlp exit                     //~v361R~
//#endif                                                           //~v361R~
	return (int)modeinfo.row;                                      //~v060I~
#endif //NOCURSES                                                  //~v6a0R~
#endif //ARMXXE                                                    //~v6a0I~
}//uerrscrheight                                                   //~v060R~
//******************************************************           //~v55aI~
//* get previous err msg text & clear it                           //~v55aI~
//******************************************************           //~v55aI~
char *useterrmsg(char *Perrmsg)                                    //~v55aI~
{                                                                  //~v55aI~
                                                                   //~v55aI~
	if (Perrmsg)	//saved msg                                    //~v55aI~
    {	                                                           //~v55aI~
//  	strncpy(Smsgsave,Perrmsg,sizeof(Smsgsave));                //~v5mKR~
    	strncpy(Smsgsave,Perrmsg,(UINT)Smaxmsgll);                 //~v5mKR~
    	Smsgsetflag=1;		//clear gotten msg                     //~v55aI~
    }                                                              //~v55aI~
    else                                                           //~v5bsI~
    	Smsgsetflag=0;		//clear gotten msg                     //~v5bsI~
	return Smsgsave;                                               //~v55aI~
}//useterrmsg                                                      //~v55aI~
//******************************************************
//* get previous err msg text & clear it
//******************************************************
char *ugeterrmsg(void)
{
    if (!Smsgsetflag)	//not set by umsgedit
		return 0;
		
    Smsgsetflag=0;		//clear gotten msg
	return Smsgsave;
}//ugeterrmsg

//******************************************************           //~v182I~
//* get previous err msg text,but dont clear it                    //~v182I~
//******************************************************           //~v182I~
char *ugeterrmsg2(void)                                            //~v182I~
{                                                                  //~v182I~
    if (!Smsgsetflag)	//not set by umsgedit                      //~v182I~
		return 0;                                                  //~v182I~
	return Smsgsave;                                               //~v182I~
}//ugeterrmsg2                                                     //~v182I~
                                                                   //~v182I~
//******************************************************
//* msg edit
//* parm1 :title(PGM,VER etc)                                      //~v060I~
//* parm2 :format by englist                                       //~v060I~
//* parm3 :format by japanese                                      //~v060I~
//* parm4-:parms                                                   //~v060I~
//******************************************************
//char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,unsigned long *Pparg)//~v060R~//~v6hhR~
char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,ULPTR *Pparg)//~v6hhI~
{
	int i,j;
	char *patern;           //eng or jap
    int lenw;                                                      //~v170I~
    char *pc;                                                      //~v170I~
static int Sdoubleentry=0;
#ifdef UNX                                                         //~v50uI~
  #ifndef XXE                                                      //~v5g8I~
	static int Skonsw=0;                                           //~v50uI~
  #endif                                                           //~v5g8I~
//  static int euclen;                                             //~v5f8R~
#endif                                                             //~v607I~
  #ifdef LNX                                                       //~v607R~
    int euclen;                                                    //~v5f8I~
  #endif                                                           //~v607I~
//#if  defined(LNX)||defined(UTF8SUPP)                             //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
    int chklen,outlen,errctr;                                      //~v5i8I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
    char eucmsg[MAXMSGLL*UTF8_MAXCHARSZ+2];                        //~v609M~
#else                                                              //~v609M~
  #ifdef LNX                                                       //~v5nnI~
    char eucmsg[MAXMSGLL+1];                                       //~v5f8I~
  #endif                                                           //~v5nnI~
#endif                                                             //~v609I~
//#endif                                                           //~v5n8R~
//#endif                                                           //~v607R~
	int prevlen=0;                                                 //~v200I~
#ifdef LNX                                                         //~v5nnI~
  #ifndef XXE                                                      //~v6b9I~
	int prevdbcssetsw;                                             //~v5nnI~
  #endif                                                           //~v6b9I~
#endif                                                             //~v5nnI~
//****************************
    UCBITOFF(Guerropt,GBL_UERR_SJIS2UTF8|GBL_UERR_SJIS2EUC);    //required to clear each time//~v6v0R~
//  Guerropt2&=~GBL_UERR2_S2UJMSG;    //clear each time            //~v6v0R~//~v6BkR~
    Guerropt2&=~(UINT)GBL_UERR2_S2UJMSG;    //clear each time      //~v6BkI~
	if(Sdoubleentry)
    {                                                              //~v5g8I~
#ifdef UNX                                                         //~v50uI~
  #ifdef XXE                                                       //~v5g8I~
           printf("uerrmsgedit:double entry\n");    //for debug    //~v5g8I~
  #else                                                            //~v5g8I~
    	if (!(Guviol_flag & UVIOL_KONCHKS) || (Guviol_flag & UVIOL_KONCHKE))//~v50uI~
  #endif                                                           //~v5g8I~
#endif                                                             //~v50uI~
		if (!UCBITCHK(Guerropt,GBL_UERR_DBCSSET))	//not yet chked//~v639I~
        {                                                          //~v639I~
           sprintf(Smsgsave,"Warning:uerrmsgedit double entry by \n\"%s\"\n",Pemsg);//~v639R~//~v6BkR~
           return Smsgsave;                                        //~v639I~
        }                                                          //~v639I~
    		exit(16);                                              //~v50uR~
    }                                                              //~v5g8I~
	Sdoubleentry=1;					//entry sw
//  if (!Sdbcsenv)					//first time                   //~v060R~
//  	Sdbcsenv=udbcschk(0x81)+1;	//0x8140 is dbcs space,if rc==0 then no dbcs e//~v060R~
#ifdef LNX                                                         //~v5nnI~
  #ifndef XXE                                                      //~v6b9I~
	prevdbcssetsw=UCBITCHK(Guerropt,GBL_UERR_DBCSSET);             //~v5nnI~
  #endif                                                           //~v6b9I~
#endif                                                             //~v5nnI~
	if (!UCBITCHK(Guerropt,GBL_UERR_DBCSSET))	//not yet chked    //~v060I~
    {                                                              //~v060I~
//  	if (udbcschk(0x81))		//0x8140 is dbcs space,if rc==0 then no dbcs e//~v150R~
    	if (udbcschkcp())		//dbcstbl or cp!=932               //~v150I~
//#ifdef LNX                                                       //~v591R~
//          if (Gudbcschk_flag & UDBCSCHK_EUC)    //euc            //~v591R~
//            UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);   //reset dbcs mode//~v591R~
//          else                                                   //~v591R~
//#endif                                                           //~v591R~
			UCBITON(Guerropt,GBL_UERR_DBCSMODE);	//not yet chked//~v060I~
		else                                                       //~v060I~
        {                                                          //~v70kI~
		  if (Gudbcschk_flag & UDBCSCHK_FORCEUCJ)    //euc         //~v70kI~
			UCBITON(Guerropt,GBL_UERR_DBCSMODE);	//not yet chked//~v70kR~
          else                                                     //~v70kI~
			UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);	//not yet chked//~v060I~
        }                                                          //~v70kI~
		UCBITON(Guerropt,GBL_UERR_DBCSSET);	//not yet chked        //~v060I~
	}                                                              //~v060I~
#ifdef UNX                                                         //~v50uI~
//  if (Gudbcschk_flag & UDBCSCHK_EUC)    //euc                    //~v5i8R~
//  if (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8))    //euc or utf8//~v5i8I~,//~v5i9R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
    if (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8J))    //euc or utf8//~v5i9R~
//#else                                                            //~v5n8R~
//    if (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8))    //euc or utf8//~v5i8I~,//~v5n8R~
//#endif                                                           //~v5n8R~
    {                                                              //~v591I~
#ifdef XXE                                                         //~v5g8I~
      if (Gudbcschk_flag & (UDBCSCHK_UTF8J))    //euc-utf8         //~v5n8I~
      {                                                            //~v6v0I~
//      UCBITON(Guerropt,GBL_UERR_SJIS2EUC|GBL_UERR_DBCSMODE); //conv sjis to euc//~v6v0R~
        UCBITON(Guerropt,GBL_UERR_DBCSMODE); //conv sjis to euc    //~v6v0I~
       	if (Guerropt2 & GBL_UERR2_UTF8STDO)       //for xsub(not xe),printf to stdout of LNX UTF8 env//~v6v0I~
	    	UCBITON(Guerropt,GBL_UERR_SJIS2UTF8);    //conv sjis to utf8//~v6v0I~
       	else                                                       //~v6v0I~
        	UCBITON(Guerropt,GBL_UERR_SJIS2EUC);    //conv sjis to euc//~v6v0I~
      }                                                            //~v6v0I~
      else                                                         //~v5n8I~
#else                                                              //~v5g8I~
		if (!Skonsw)		//not yet kon chked                    //~v50uI~
        {                                                          //~v50uI~
    		if (!(Guviol_flag & (UVIOL_KONCHKS|UVIOL_KONCHKE)))	//no one yet called//~v50uR~
            {                                                      //~v50uI~
                Skonsw=1;		//kon chked	                       //~v50uI~
      			uviol_konchk();                                    //~v5n8R~//~v5nnR~
            }                                                      //~v50uI~
    		else                                                   //~v50uI~
    			if (Guviol_flag & UVIOL_KONCHKE)	//chk ended    //~v50uI~
	                Skonsw=1;		//kon chked                    //~v50uI~
//          if (Guviol_flag & UVIOL_KON)       //under kon         //~v50uR~//~v5nnR~
            if (Guviol_flag & UVIOL_KON        //under kon         //~v5nnI~
      		||  uviol_konchk2())               //dbcs term     //~v5n8R~//~v5nnI~
            {                                                      //~v50uR~
			  if (!prevdbcssetsw)	//xsub not set _UERR_DBCSSET   //~v5nnI~
                UCBITON(Guerropt,GBL_UERR_DBCSMODE);    //conv sjis to euc//~v50uR~
//              UCBITON(Guerropt,GBL_UERR_SJIS2EUC);    //conv sjis to euc//~v591R~
            }                                                      //~v50uR~
        }                                                          //~v50uI~
    #ifdef LNX                                                     //~v5n8I~
      if (Gudbcschk_flag & (UDBCSCHK_UTF8J))    //euc-utf8         //~v5n8I~
      {                                                            //~v6v0R~
       if (Guerropt2 & GBL_UERR2_UTF8STDO)       //for xsub(not xe),printf to stdout of LNX UTF8 env//~v6v0R~
	    UCBITON(Guerropt,GBL_UERR_SJIS2UTF8);    //conv sjis to utf8//~v6v0R~
       else                                                        //~v6v0R~
        UCBITON(Guerropt,GBL_UERR_SJIS2EUC);    //conv sjis to euc //~v5n8I~
      }                                                            //~v6v0R~
      else                                                         //~v5n8I~
    #endif                                                         //~v5n8I~
#endif                                                             //~v5g8I~
		if (UCBITCHK(Guerropt,GBL_UERR_DBCSMODE))	//kon or kterm etc//~v591I~
        {                                                          //~v5i8I~
	      if (Gudbcschk_flag & UDBCSCHK_EUC)   //euc               //~v5i8I~
            UCBITON(Guerropt,GBL_UERR_SJIS2EUC);    //conv sjis to euc//~v591I~
          else                                                     //~v5i8I~
	        UCBITON(Guerropt,GBL_UERR_SJIS2UTF8);    //conv sjis to utf8//~v5i8I~
        }                                                          //~v5i8I~
    }//EUC                                                         //~v591I~
#else     //!UNX                                                   //~v607I~
//  #ifdef UTF8SUPP                                                //~v5n8R~
    #ifdef WCSUPP                                                  //~v5n8I~
      #ifndef WXE                                                  //~v5n8I~
	    if (Gudbcschk_flag & UDBCSCHK_UTF8J)    //utf8             //~v607I~
	        UCBITON(Guerropt,GBL_UERR_SJIS2UTF8);    //conv sjis to utf8//~v607I~
        else                                                       //~v607I~
	    if (Gudbcschk_flag & UDBCSCHK_UTF8)    //utf8              //~v607I~
			Suerropt|=UERR_FORCE_ENGLISH;                          //~v607R~
      #endif //!WXE                                                //~v5n8I~
    #endif                                                         //~v607I~
#endif                                                             //~v50uI~
        	                                                       //~v060I~
//  if (Pjmsg && *Pjmsg	&& Sdbcsenv==2)		//japanese msg and DBCS mode//~v060R~
    if (Pjmsg && *Pjmsg	&& UCBITCHK(Guerropt,GBL_UERR_DBCSMODE))		//japanese msg and DBCS mode//~v060I~
		if (Suerropt & UERR_FORCE_ENGLISH)                      //~5B11R~
			patern=Pemsg;                                       //~5B11I~
		else                                                    //~5B11I~
        {                                                          //~v5f8I~
#ifdef LNX                                                         //~v5f8I~
//        if (UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC))   //conv sjis to euc//~v60bR~
          if (UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC)    //conv sjis to euc//~v60bI~
          &&  !(Guerropt2 & (GBL_UERR2_NOCONV|GBL_UERR2_NOCONV1))  //~v60bR~
             )                                                     //~v60bI~
          {                                                        //~v5f8I~
	    	lenw=(int)strlen(Pjmsg);                               //~v5f8I~
            if (lenw>(sizeof(eucmsg)>>1))                          //~v5f8I~
            	lenw=(sizeof(eucmsg)>>1);                          //~v5f8I~
          	ushift2euc(Pjmsg,0,lenw,eucmsg,0,&euclen,0);  //sjis-->euc//~v5f8I~
            *(eucmsg+euclen)=0;   //strz                           //~v5f8I~
            patern=eucmsg;                                         //~v5f8I~
          }                                                        //~v5f8I~
          else                                                     //~v5f8I~
#endif                                                             //~v607I~
//#if defined(LNX)||defined(UTF8SUPP)                              //~v5n8R~
#ifdef WCSUPP                                                      //~v5n8I~
//        if (UCBITCHK(Guerropt,GBL_UERR_SJIS2UTF8))   //conv sjis to euc//~v60bR~
          if (UCBITCHK(Guerropt,GBL_UERR_SJIS2UTF8)    //conv sjis to euc//~v60bI~
          &&  !(Guerropt2 & (GBL_UERR2_NOCONV|GBL_UERR2_NOCONV1))  //~v60bR~
             )                                                     //~v60bI~
          {                                                        //~v5i8I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WXE                                                         //~v609I~
		   if (Gwxestat & GWXES_NOUTF8ERRMSG)                      //~v609I~
			patern=Pjmsg;                                          //~v609I~
           else                                                    //~v609I~
           {                                                       //~v609I~
#endif                                                             //~v609I~
//#endif                                                           //~v5n8R~
//  		ucvssjis2utf(0,0,Pjmsg,strlen(Pjmsg),eucmsg,sizeof(eucmsg),&chklen,&outlen,&errctr);	//sjis-->utf8//~v5i8I~//~v6BkR~
    		ucvssjis2utf(0,0,Pjmsg,(int)strlen(Pjmsg),eucmsg,sizeof(eucmsg),&chklen,&outlen,&errctr);	//sjis-->utf8//~v6BkI~
	        UCBITON(Guerropt2,GBL_UERR2_S2UJMSG);    //conv sjis to utf8 was done//~v6v0R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WXE                                                         //~v609I~
            *(eucmsg+outlen++)=' ';   //vc++ ASSERT sprintf fail if last is DBCS1ST+0//~v609R~
#endif                                                             //~v609I~
//#endif                                                           //~v5n8R~
            *(eucmsg+outlen)=0;   //strz                           //~v609I~
            patern=eucmsg;                                         //~v5i8I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#ifdef WXE                                                         //~v609I~
           }                                                       //~v609I~
#endif                                                             //~v609I~
//#endif                                                           //~v5n8R~
          }                                                        //~v5i8I~
          else                                                     //~v5i8I~
#endif                                                             //~v5f8I~
			patern=Pjmsg;                                       //~5B11R~
        }                                                          //~v5f8I~
	else
		patern=Pemsg;
//#ifdef UTF8SUPP                                                  //~v5n8R~
//  Guerropt2&=~GBL_UERR2_NOCONV1;	//effective only once          //~v60bR~//~v6BkR~
    Guerropt2&=~(UINT)GBL_UERR2_NOCONV1;	//effective only once  //~v6BkI~
//#endif                                                           //~v5n8R~
//overflow chk                                                     //~v170I~
    lenw=(int)strlen(patern);                                      //~v170I~
//  if (lenw>(MAXMSGLL>>1))		//may overflow                     //~v5mKR~
    if (lenw>(Smaxmsgll>>1))		//may overflow                 //~v5mKR~
    {                                                              //~v170I~
    	if (strchr(patern,'%'))	//may expand                       //~v170I~
        {                                                          //~v170I~
        	lenw<<=1;	//alloc double                             //~v170I~
        	pc=umalloc((UINT)lenw);	//alloc double                 //~v170I~
        }                                                          //~v170I~
        else                                                       //~v170I~
        {                                                          //~v170I~
        	lenw+=(int)strlen(Ptitle)+2;	//total en             //~v170I~
//      	if (lenw>=MAXMSGLL)    //overflow                      //~v5mKR~
        	if (lenw>=Smaxmsgll)    //overflow                     //~v5mKR~
	        	pc=umalloc((UINT)lenw);	//alloc double             //~v170R~
            else                                                   //~v170I~
            	pc=Smsgsave;		//use fiexed                   //~v170R~
		}                                                          //~v170I~
        if (!pc)	//maclloc failed                               //~v170I~
            pc=Smsgsave;		//use fiexed                       //~v170I~
    }                                                              //~v170I~
    else                                                           //~v170I~
    	pc=Smsgsave;                                               //~v170I~
    if (pc==Smsgsave)                                              //~v170I~
    {                                                              //~v200I~
//      lenw=MAXMSGLL;                                             //~v5mKR~
        lenw=Smaxmsgll;                                            //~v5mKR~
        if (Smsgcatsw)                                             //~v200I~
        	prevlen=(int)strlen(Smsgsave);                         //~v200R~
	}                                                              //~v200I~
//edit                                                             //~v170I~
                                                                   //~v170I~
  if (prevlen)		//cat msg                                      //~v200I~
  {                                                                //~v200I~
  	i=prevlen;                                                     //~v200I~
    j=0;                                                           //~v200I~
  }                                                                //~v200I~
  else                                                             //~v200I~
  {                                                                //~v200I~
	for(i=0;;i++)
	{
		if (*(patern+i)!='\n')
			break;
//  	*(Smsgsave+i)='\n';                                        //~v170R~
    	*(pc+i)='\n';                                              //~v170I~
	}
	j=i;
	if (Suerropt & UERR_TIMESTAMP)                                 //~v5iwI~
    {                                                              //~v5iwI~
		memcpy(pc+i,utimeedit("HH:MM:SS.MIL ",0),13);              //~v5iwR~
        i+=13;                                                     //~v5iwR~
    }                                                              //~v5iwI~
//  i+=sprintf(pc+j,"%s",Ptitle);                                  //~v5iwR~
    i+=sprintf(pc+i,"%s",Ptitle);                                  //~v5iwI~
  }	                                                               //~v200I~
//  sprintf(Smsgsave+i,patern+j,                                   //~v170R~
#ifdef W32                                                         //~v6U0I~
    if (Guerropt2 & GBL_UERR2_OUTUTF8    //clear each time         //~v6U0I~
    &&  Pjmsg && *Pjmsg	&& UCBITCHK(Guerropt,GBL_UERR_DBCSMODE)		//japanese msg and DBCS mode//~v6U0I~
	&&  !(Suerropt & UERR_FORCE_ENGLISH)                           //~v6U0I~
    )                                                              //~v6U0I~
    {                                                              //~v6U0I~
    	int lenlocale;                                             //~v6U0I~
    	lenlocale=vsprintf(eucmsg,patern+j,(va_list)(ULPTR)Pparg); //~v6U0I~
    	ucvssjis2utf(0,0,eucmsg,lenlocale,pc+i,MAXMSGLL-i-1,&chklen,&outlen,&errctr);	//sjis-->utf8 after sprintf to avois assertion by utf8 pattern msg//~v6U0R~
	    UCBITON(Guerropt2,GBL_UERR2_S2UJMSG);    //conv sjis to utf8 was done//~v6U0I~
        UTRACED("uerrmsgedit OUTUTF8",pc+i,outlen);                //~v6U0M~
        i+=outlen;                                                 //~v6U0I~
    }                                                              //~v6U0I~
    else                                                           //~v6U0I~
    	i+=vsprintf(pc+i,patern+j,(va_list)(ULPTR)Pparg);          //~v6U0R~
#else                                                              //~v6U0I~
    i+=sprintf(pc+i,patern+j,                                      //~v170I~
	        *(Pparg+0),*(Pparg+1),*(Pparg+2),*(Pparg+3),*(Pparg+4),
            *(Pparg+5),*(Pparg+6),*(Pparg+7),*(Pparg+8),*(Pparg+9));
#endif                                                             //~v6U0I~
//UTRACEP("errmsg len=%d\n",i);                                    //~v170R~
//UTRACED("errmsg ",pc,lenw);                                      //~v170R~
    if (i>=lenw)                                                   //~v170R~
    {                                                              //~v170I~
        ubell();                                                   //~v170I~
		printf("\nToo long errmsg(%d>%d),memory may destroy!! \n",i,lenw);//~v170R~
    }                                                              //~v170I~
	if (pc!=Smsgsave)                                              //~v170I~
    {                                                              //~v170I~
//  	if (i>=MAXMSGLL)                                           //~v5mKR~
    	if (i>=Smaxmsgll)                                          //~v5mKR~
//      	i=MAXMSGLL-1;                                          //~v5mKR~
        	i=Smaxmsgll-1;                                         //~v5mKR~
        memcpy(Smsgsave,pc,(UINT)i);                               //~v170I~
        *(Smsgsave+i)=0;                                           //~v170I~
        ufree(pc);	                                               //~v170I~
    }                                                              //~v170I~
                                                                   //~v50uI~
//#ifdef UNX                                                       //~v5f8R~
//    if (patern==Pjmsg)      //japanese msg                       //~v5f8R~
//        if (UCBITCHK(Guerropt,GBL_UERR_SJIS2EUC))   //conv sjis to euc//~v5f8R~
//        {                                                        //~v5f8R~
////          ushift2euc(Smsgsave,i,Smsgsave,0,0);    //sjis-->euc //~v5f8R~
////          ushift2euc(Smsgsave,0,i,Smsgsave,0,0,0);    //sjis-->euc//~v5f8R~
////          ushift2euc(Smsgsave,0,i,Smsgsave,0,&euclen,0);  //sjis-->euc//~v5f8R~
//            ushift2euc(Smsgsave+prevlen,0,i-prevlen,Smsgsave+prevlen,0,&euclen,0);  //sjis-->euc//~v5f8R~
////          *(Smsgsave+euclen)=0;   //strz                       //~v5f8R~
//            *(Smsgsave+prevlen+euclen)=0;   //strz               //~v5f8R~
//        }                                                        //~v5f8R~
//#endif                                                           //~v5f8R~
        	                                                       //~v50uI~
//  Guerropt2&=~GBL_UERR2_UTF8STDO;   //clear each time            //~v6v0R~//~v6BkR~
    Guerropt2&=~(UINT)GBL_UERR2_UTF8STDO;   //clear each time      //~v6BkI~
    Smsgsetflag=1;	//can get by ugeterrmsg
	Sdoubleentry=0;		//exitsw
	return Smsgsave;
}//uerrmsgedit                                                     //~v50uR~
                                                                //~5A10I~
#if !(defined(ARM) && defined(XXE))                                //~v6a0I~
//**********************************************************************//~v5iwI~
//* get confirmation from user                                     //~v5iwI~
//ret replyed char                                                 //~v5iwI~
//**********************************************************************//~v5iwI~
char uconfirmmsg(char *Pmsge,char *Pmsgj,char *Preply)             //~v5iwI~
{                                                                  //~v5iwI~
    char  reply,*pc,*pc2;                                          //~v5iwI~
    char  valid[128];                                              //~v5iwI~
//**********                                                       //~v5iwI~
	if (!UCBITCHK(Guerropt,GBL_UERR_DBCSSET))	//not yet chked    //~v6DjI~
    {                                                              //~v6DjI~
    	if (udbcschkcp())		//dbcstbl or cp!=932               //~v6DjI~
			UCBITON(Guerropt,GBL_UERR_DBCSMODE);	//not yet chked//~v6DjI~
		else                                                       //~v6DjI~
			UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);	//not yet chked//~v6DjI~
		UCBITON(Guerropt,GBL_UERR_DBCSSET);	//not yet chked        //~v6DjI~
	}                                                              //~v6DjI~
	for (pc=Preply,pc2=valid;*pc;pc++)                             //~v5iwI~
    {                                                              //~v5iwI~
        if (*pc=='\r')                                             //~v5iwI~
        {                                                          //~v5iwI~
            memcpy(pc2,"Enter-key",9);                             //~v5iwI~
            pc2+=9;                                                //~v5iwI~
		}                                                          //~v5iwI~
        else                                                       //~v5iwI~
       		if (*pc=='\x1b')                                       //~v5iwI~
            {                                                      //~v5iwI~
	            memcpy(pc2,"Esc-key",7);                           //~v5iwI~
	            pc2+=7;                                            //~v5iwI~
			}                                                      //~v5iwI~
            else                                                   //~v5iwI~
            {                                                      //~v5iwI~
        	    *pc2=*pc;                                          //~v5iwI~
	            pc2++;                                             //~v5iwI~
			}                                                      //~v5iwI~
		*pc2++=',';                                                //~v5iwI~
    }                                                              //~v5iwI~
    if (pc==Preply||pc2>=valid+sizeof(valid))                      //~v5iwI~
    	uerrexit("internal err;no valid confirm char",0);          //~v5iwI~
    *(pc2-1)=0;                                                    //~v5iwI~
	for (;;)                                                       //~v5iwI~
    {                                                              //~v5iwI~
//clear kbd buff                                                   //~v5iwI~
#ifdef UNX                                                         //~v5iwI~
        while(kbhit())                                             //~v5iwI~
	    	getch_nc();  //getch not under curses                  //~v5iwI~
#else                                                              //~v5iwI~
#ifdef DOS                                                         //~v5iwI~
        while(kbhit())                                             //~v5iwI~
	    	getch();                                               //~v5iwI~
#else                                                              //~v5iwI~
	#ifdef W32                                                     //~v5iwI~
        while(_kbhit())                                            //~v5iwI~
	    	_getch();                                              //~v5iwI~
    #else                                                          //~v5iwI~
        while(_kbhit())                                            //~v5iwI~
	    	_getch();                                              //~v5iwI~
    #endif                                                         //~v5iwI~
#endif                                                             //~v5iwI~
#endif                                                             //~v5iwI~
        ubell();                                                   //~v5iwI~
	    if (Pmsgj && *Pmsgj                                        //~v5iwR~
     	&&  UCBITCHK(Guerropt,GBL_UERR_DBCSMODE)		//japanese msg and DBCS mode//~v5iwI~
		&&  !(Suerropt & UERR_FORCE_ENGLISH))                      //~v5iwI~
//		  	printf(Pmsgj);                                         //~v6DiR~
  		  	printf("%s",Pmsgj);                                    //~v6DiR~
        else                                                       //~v5iwI~
//  	  	printf(Pmsge);                                         //~v6DiR~
    	  	printf("%s",Pmsge);                                    //~v6DiR~
        printf("===>");                                            //~v5iwI~
        fflush(stdout);                                            //~v5iwI~
#ifdef UNX                                                         //~v5iwI~
    	reply=(UCHAR)getch_nc();                                   //~v5iwI~
#else                                                              //~v5iwI~
#ifdef DOS                                                         //~v5iwI~
    	reply=(UCHAR)getch();                                      //~v5iwI~
#else                                                              //~v5iwI~
	#ifdef W32                                                     //~v5iwI~
    	reply=(UCHAR)_getch();                                     //~v5iwI~
    #else                                                          //~v5iwI~
    	reply=(UCHAR)_getch();                                     //~v5iwI~
    #endif                                                         //~v5iwI~
#endif                                                             //~v5iwI~
#endif                                                             //~v5iwI~
        if (!reply)         //pf-key etc                           //~v5iwI~
            reply=' ';                                             //~v5iwI~
        if (reply=='\r')                                           //~v5iwI~
            printf("Enter\n");                                     //~v5iwI~
        else                                                       //~v5iwI~
       		if (reply=='\x1b')                                     //~v5iwI~
        	    printf("Esc\n");                                   //~v5iwI~
            else                                                   //~v5iwI~
        	    printf("%c\n",reply);                              //~v5iwI~
    	pc=strchr(Preply,reply);                                   //~v5iwI~
        if (pc)                                                    //~v5iwI~
        	break;                                                 //~v5iwI~
    	uerrmsg("Invalid reply,Enter one of %s.",                  //~v5iwI~
    	    	"無効な入力.%s のいずれかを入力して下さい",        //~v5iwI~
    			valid);                                            //~v5iwI~
	}                                                              //~v5iwI~
    if (reply=='\x1b')                                             //~v5iwI~
    {                                                              //~v5iwI~
    	uerrexit("Process canceled",0);                            //~v5iwI~
    }                                                              //~v5iwI~
    return reply;                                                  //~v5iwI~
}//uconfirmmsg                                                     //~v5iwI~
#endif //ARMXXE                                                    //~v6a0I~
//**************************************************************** //~v5iyI~
//*convert errorno to string                                       //~v5iyI~
//**************************************************************** //~v5iyI~
char *uerrornomsg(int Perrorno)                                    //~v5iyI~
{                                                                  //~v5iyI~
    return strerror(Perrorno);                                     //~v5iyR~
}                                                                  //~v5iyI~
#ifdef W32                                                         //~v5iyI~
//**************************************************************** //~v5iyI~
//*ugetlasterror                                                   //~v5iyI~
//*convert windows errcode to string                               //~v5iyI~
//*if parm==NULL;issue GetLastError                                //~v5iyI~
//*if *parm<0;return also GetLastError value                       //~v5iyI~
//*ret string:call shuld use ufree or null if faied                //~v5iyR~
//**************************************************************** //~v5iyI~
char *ugetlasterror(int *Pprc)                                     //~v5iyI~
{                                                                  //~v5iyI~
	int rc,len,apirc;                                              //~v5iyR~
    ULONG langid;                                                  //~v5iyI~
    void *buff;                                                    //~v5iyI~
	char *ret;                                                     //~v5iyI~
//*******************************                                  //~v5iyI~
	if (Pprc)                                                      //~v5iyI~
    {                                                              //~v5iyI~
        rc=*Pprc;                                                  //~v5iyI~
        if (rc<0)                                                  //~v5iyI~
        {                                                          //~v5iyI~
            rc=GetLastError();                                     //~v5iyI~
            *Pprc=rc;                                              //~v5iyI~
        }                                                          //~v5iyI~
    }                                                              //~v5iyI~
    else                                                           //~v5iyI~
    	rc=GetLastError();                                         //~v5iyI~
	if (Suerropt & UERR_FORCE_ENGLISH)                             //~v5iyI~
    	langid=MAKELANGID(LANG_ENGLISH,SUBLANG_DEFAULT);           //~v5iyI~
    else                                                           //~v5iyI~
    	langid=MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT);           //~v5iyI~
                                                                   //~v5iyI~
	apirc=FormatMessage(  FORMAT_MESSAGE_ALLOCATE_BUFFER	//get output buffsz//~v5iyR~
				  | FORMAT_MESSAGE_FROM_SYSTEM      //search in system msg table//~v5iyI~
				  | FORMAT_MESSAGE_IGNORE_INSERTS,  //ignore insert seq(get raw text),arg parm ignored//~v5iyI~
    				NULL,							//format input //~v5iyI~
				    rc, 							//msgid,       //~v5iyR~
    				langid,                                        //~v5iyI~
    				(LPTSTR)&buff,					//output buff addr//~v5iyR~
				    0,								//buffsz       //~v5iyI~
				    NULL);							//arg to format//~v5iyI~
    if (!apirc)  	//failed                                       //~v5iyI~
    	return 0;                                                  //~v5iyI~
    len=strlen(buff);                                              //~v5iyI~
    ret=umalloc(len+1);                                            //~v5iyM~
    memcpy(ret,buff,(UINT)(len+1));                                //~v5iyM~
	LocalFree(buff);                                               //~v5iyM~
    if (len>1 && *(ret+len-1)=='\n')                               //~v5iyR~
    {                                                              //~v5iyI~
        len--;                                                     //~v5iyI~
        *(ret+len)=0;  //drop last lf                              //~v5iyR~
    	if (len>1 && *(ret+len-1)=='\r')                           //~v5iyR~
    	{                                                          //~v5iyI~
        	len--;                                                 //~v5iyI~
        	*(ret+len)=0;  //drop last cr                          //~v5iyR~
	    }                                                          //~v5iyI~
    }                                                              //~v5iyI~
    return ret;                                                    //~v5iyI~
}//ugetlasterror                                                   //~v5iyI~
#endif	//W32                                                      //~v5iyI~
//**************************************************************** //~v5j3I~
//ugeterrdescription                                               //~v5j3I~
//*conv errno/GetLastError to text                                 //~v5j3I~
//*if parm==NULL;issue GetLastError                                //~v5j3I~
//*if *parm<0;return also GetLastError value                       //~v5j3I~
//**************************************************************** //~v5j3I~
char *ugeterrdescription(int Pgetlasterrsw,int *Pprc)              //~v5j3R~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
#ifdef W32                                                         //~v5j3I~
    char *pdesc;                                                   //~v5j3I~
#endif                                                             //~v5j3I~
//**************************                                       //~v5j3I~
#ifdef W32                                                         //~v5j3M~
	if (Pgetlasterrsw)                                             //~v5j3I~
    {                                                              //~v5j3I~
		pdesc=ugetlasterror(Pprc);	//0:issue GetLastError         //~v5j3R~
        if (!pdesc)                                                //~v5j3I~
        	return "";                                             //~v5j3I~
		return pdesc;                                              //~v5j3I~
//#else                                                            //~v5j3R~
//		return "";		//W32 only                                 //~v5j3R~
	}                                                              //~v5j3I~
#endif                                                             //~v5j3M~
    if (Pprc)                                                      //~v5j3I~
    {                                                              //~v5j3I~
    	if (*Pprc<0)                                               //~v5j3I~
        	*Pprc=errcd=errno;                                     //~v5j3I~
        else                                                       //~v5j3I~
        	errcd=*Pprc;                                           //~v5j3I~
    }                                                              //~v5j3I~
    else                                                           //~v5j3I~
        errcd=*Pprc;                                               //~v5j3I~
    return strerror(errcd);                                        //~v5j3R~
}//ugeterrdescription                                              //~v5j3I~
//****************************************************************//~5A10I~
//uerrapi1                                                      //~5A10I~
//* api err msg with 1 parm                                     //~5A10I~
//*parm1:apiname                                                //~5A10I~
//*parm2:parm 1                                                 //~5A10I~
//*parm3:rc for display                                         //~5A10I~
//*retrn:rc same as input                                       //~5A10I~
//****************************************************************//~5A10I~
int uerrapi1(char  *Papiname,char  *Pparm1,int Papirc)          //~5A10I~
{                                                               //~5A10I~
//********************                                          //~5A10I~
	uerrmsg("%s failed for %s,rc=%d",0,                         //~5A10I~
			Papiname,Pparm1,Papirc);                            //~5A10I~
	return Papirc;                                              //~5A10I~
}//uerrapi1                                                     //~5A10I~
                                                                //~5A10I~
//**************************************************************** //~v022I~
//uerrapi1x                                                        //~v022I~
//* api err msg with 1 parm and exit                               //~v022I~
//*parm1:apiname                                                   //~v022I~
//*parm2:parm 1                                                    //~v022I~
//*parm3:rc for display                                            //~v022I~
//*retrn:exit                                                      //~v022I~
//**************************************************************** //~v022I~
void uerrapi1x(char  *Papiname,char  *Pparm1,int Papirc)           //~v022R~
{                                                                  //~v022I~
//********************                                             //~v022I~
	uerrexit("%s failed for %s,rc=%d",0,                           //~v022I~
			Papiname,Pparm1,Papirc);                               //~v022I~
}//uerrapi1x                                                       //~v022I~
                                                                   //~v022I~
//**************************************************************** //~v040I~
//uerrapi0                                                         //~v040I~
//* api err msg with 0 parm                                        //~v040I~
//*parm1:apiname                                                   //~v040I~
//*parm2:rc for display                                            //~v040I~
//*retrn:rc same as input                                          //~v040I~
//**************************************************************** //~v040I~
int uerrapi0(char  *Papiname,int Papirc)                           //~v040I~
{                                                                  //~v040I~
//********************                                             //~v040I~
	uerrmsg("%s failed,rc=%d",0,Papiname,Papirc);                  //~v040I~
	return Papirc;                                                 //~v040I~
}//uerrapi0                                                        //~v040I~
                                                                   //~v040I~
//**************************************************************** //~v040I~
//uerrapi0x                                                        //~v040I~
//* api err msg with 0 parm and exit                               //~v040I~
//*parm1:apiname                                                   //~v040I~
//*parm2:rc for display                                            //~v040I~
//*retrn:exit                                                      //~v040I~
//**************************************************************** //~v040I~
void uerrapi0x(char  *Papiname,int Papirc)                         //~v040I~
{                                                                  //~v040I~
//********************                                             //~v040I~
	uerrexit("%s failed,rc=%d",0,Papiname,Papirc);                 //~v040I~
}//uerrapi0x                                                       //~v040I~
//**************************************************************** //~v5j3I~
//uerrapi1t                                                        //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
int uerrapi1t(int Pgetlasterrsw,char  *Papiname,char  *Pparm1,int Papirc)//~v5j3R~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrmsg("%s failed for %s,rc=%d(%s)",0,                        //~v5j3I~
			Papiname,Pparm1,errcd,perrdesc);                       //~v5j3R~
#ifdef W32                                                         //~v5j3I~
	if (Pgetlasterrsw && *perrdesc)                                //~v5j3I~
    	ufree(perrdesc);                                           //~v5j3I~
#endif                                                             //~v5j3I~
	return errcd;                                                  //~v5j3R~
}//uerrapi1t                                                       //~v5j3I~
//**************************************************************** //~v6xqI~
//uerrapi1nt                                                       //~v6xqR~
//parm1 is edit ulong to max 256 byte                              //~v6xqR~
//**************************************************************** //~v6xqI~
int uerrapi1nt(int Pgetlasterrsw,char  *Papiname,ULONG Pparm1,char *Peditstr,int Papirc)//~v6xqI~
{                                                                  //~v6xqI~
	char wknum[256];                                               //~v6xqR~
//********************                                             //~v6xqI~
	sprintf(wknum,Peditstr,Pparm1);                                //~v6xqI~
	return uerrapi1t(Pgetlasterrsw,Papiname,wknum,Papirc);         //~v6xqI~
}//uerrapi1nt                                                      //~v6xqI~
//**************************************************************** //~v5j3I~
//uerrapi1x                                                        //~v5j3I~
//* api err msg with 1 parm and exit                               //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
void uerrapi1tx(int Pgetlasterrsw,char  *Papiname,char  *Pparm1,int Papirc)//~v5j3I~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrexit("%s failed for %s,rc=%d(%s)",0,                       //~v5j3I~
			Papiname,Pparm1,errcd,perrdesc);                       //~v5j3R~
}//uerrapi1tx                                                      //~v5j3I~
                                                                   //~v5j3I~
//**************************************************************** //~v5j3I~
//uerrapi0                                                         //~v5j3I~
//* api err msg with 0 parm                                        //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
int uerrapi0t(int Pgetlasterrsw,char  *Papiname,int Papirc)        //~v5j3I~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrmsg("%s failed,rc=%d(%s)",0,                               //~v5j3R~
				Papiname,errcd,perrdesc);                          //~v5j3R~
#ifdef W32                                                         //~v5j3I~
	if (Pgetlasterrsw && *perrdesc)                                //~v5j3I~
    	ufree(perrdesc);                                           //~v5j3I~
#endif                                                             //~v5j3I~
	return errcd;                                                  //~v5j3R~
}//uerrapi0t                                                       //~v5j3I~
                                                                   //~v5j3I~
//**************************************************************** //~v5j3I~
//uerrapi0x                                                        //~v5j3I~
//* api err msg with 0 parm and exit                               //~v5j3I~
//display errcode and errdescription(if apirc<0 use current value) //~v5j3I~
//**************************************************************** //~v5j3I~
void uerrapi0tx(int Pgetlasterrsw,char  *Papiname,int Papirc)      //~v5j3I~
{                                                                  //~v5j3I~
	int errcd;                                                     //~v5j3I~
    char *perrdesc;                                                //~v5j3I~
//********************                                             //~v5j3I~
	errcd=Papirc;	//use current value if -1                      //~v5j3I~
	perrdesc=ugeterrdescription(Pgetlasterrsw,&errcd);             //~v5j3I~
	uerrexit("%s failed,rc=%d(%s)",0,                              //~v5j3R~
				Papiname,errcd,perrdesc);                          //~v5j3R~
}//uerrapi0tx                                                      //~v5j3I~
//**************************************************************** //~v5jdI~
// errnotsupported                                                 //~v5jdI~
//*parm1 :cmd string                                               //~v5jdI~
//*rc    :4                                                        //~v5jdI~
//**************************************************************** //~v5jdI~
int uerrnotsupported(char  *Pcmd,char  *Pcond,int Prc)             //~v5jdR~
{                                                                  //~v5jdI~
	uerrmsg("\"%s\" is not supported for %s.",                     //~v5jdI~
			"\"%s\" は %s ではサポ－トされません。",               //~v5jdI~
			Pcmd,Pcond);                                           //~v5jdI~
    return Prc;                                                    //~v5jdR~
}//uerrnotsupported                                                //~v5jdI~
#ifdef W32UNICODE                                                  //~vaucI~
//**************************************************************** //~vaucI~
// printf width UD fmt parm                                        //~vaucI~
//*rc    :ucsctr,-1:redirect env                                   //~vaucR~
//**************************************************************** //~vaucI~
int ufprintfWCONS(FILE *Pfh,char *Ppattern,char *Pmsg)             //~vaucI~
{                                                                  //~vaucI~
	HANDLE hcons;                                                  //~vaucI~
    int ucsctr=0,ucsctr2,wrtctr,sz;                                //~vaucR~
    UWCH wkmsgW[MAX_PRINTFW_MSGSZ],*pw;                            //~vaucR~
    char *pc,*pc2;                                                 //~vaucR~
    CONSOLE_SCREEN_BUFFER_INFO csbi;                               //~vaucI~
static int Swarning;                                               //~vaucI~
	int opt,rc;                                                    //~v6J1R~
//************************                                         //~vaucI~
    UTRACED("inp",Pmsg,strlen(Pmsg));                              //~vaucI~
    UTRACED("pat",Ppattern,strlen(Ppattern));                      //~vaucI~
    if (Pfh==stdout)                                               //~vaucM~
	    hcons=GetStdHandle(STD_OUTPUT_HANDLE);                     //~vaucM~
    else                                                           //~vaucM~
	    hcons=GetStdHandle(STD_ERROR_HANDLE);                      //~vaucM~
    if (!GetConsoleScreenBufferInfo(hcons,&csbi))	//fail         //~vaucI~
    {                                                              //~vaucI~
        if (!Swarning)                                             //~vaucI~
        {                                                          //~vaucI~
        	Swarning=1;                                            //~vaucI~
            fprintf(Pfh,"!!! Warning !!! Screen output was redirected. Some char may be printed using  BestFit char\n");//~vaucR~
        }                                                          //~vaucI~
        return -1;                                                 //~vaucI~
    }                                                              //~vaucI~
    for (pc=Ppattern,pw=wkmsgW,sz=sizeof(wkmsgW);*pc=='\n';pc++)   //~vaucI~
    {                                                              //~vaucI~
       	*pw++=L'\n';                                               //~vaucI~
        sz-=UWCHSZ;                                                //~vaucI~
        ucsctr++;                                                  //~vaucI~
    }                                                              //~vaucI~
//  ufilecvUD2WCnopath(0,Pmsg,pw,sz,&ucsctr2);                     //~vaucR~//~v6J1R~
	opt=UFCVO_NOMSG;                                               //~v6J1I~
  rc=                                                              //~v6J1I~
    ufilecvUD2WCnopath(opt,Pmsg,pw,sz,&ucsctr2);                   //~v6J1I~
    if (rc)	//UD fmt err                                           //~v6J1I~
    	return -1;                                                 //~v6J1I~
    ucsctr+=ucsctr2;                                               //~vaucI~
    pw+=ucsctr2;                                                   //~vaucI~
    sz-=ctr2szW(ucsctr2);                                          //~vaucI~
    for (pc2=Ppattern+strlen(Ppattern)-1;pc2>pc && *pc2=='\n' && sz>0;pc2--)//~vaucR~
    {                                                              //~vaucI~
    	*pw++=L'\n';                                               //~vaucI~
        sz-=UWCHSZ;                                                //~vaucI~
        ucsctr++;                                                  //~vaucI~
    }                                                              //~vaucI~
                                                                   //~vaucI~
    UTRACED("put",wkmsgW,ctr2szW(ucsctr));                         //~vaucI~
    WriteConsoleW(hcons,wkmsgW,ucsctr,&wrtctr,NULL);               //~vaucI~
    return wrtctr;                                                 //~vaucI~
}//ufprintfWCONS                                                   //~v6J1R~
//**************************************************************** //~vaucI~
// printf width UD fmt parm                                        //~vaucI~
//*parm1 :cmd string                                               //~vaucI~
//*rc    :4                                                        //~vaucI~
//**************************************************************** //~vaucI~
int uprintfW(char *Ppattern,char *Pmsg)                            //~vaucI~
{                                                                  //~vaucI~
	return ufprintfW(stdout,Ppattern,Pmsg);                        //~vaucR~
}//uprintfW                                                        //~vaucI~
//**************************************************************** //~vaucI~
// printf width UD fmt parm                                        //~vaucI~
//*rc    :ucsctr                                                   //~vaucR~
//**************************************************************** //~vaucI~
int ufprintfW(FILE *Pfh,char *Ppattern,char *Pmsg)                 //~vaucI~
{                                                                  //~vaucI~
    UWCH wkmsgW[MAX_PRINTFW_MSGSZ];                                //~vaucI~
    UWCH wkpatW[256];                                              //~vaucI~
    int ucsctr;                                                    //~vaucR~
    int opt;                                                       //~v6J1I~
//#ifndef WXE                                                        //~vaucI~//~v6J1R~
    int rc2;                                                       //~vaucI~
//#endif                                                             //~vaucI~//~v6J1R~
//*****************************                                    //~vaucI~
	if (!memchr(Pmsg,UD_NOTLC,strlen(Pmsg)))                       //~vaucR~
    	return fprintf(Pfh,Ppattern,Pmsg);                         //~vaucI~
#ifndef WXE                                                        //~vaucI~
//  if (Guerropt2 & GBL_UERR2_CONSWRITE)      //use console write for UD fmt//~vaucR~
    if (Pfh==stdout||Pfh==stderr)      //use console write for UD fmt//~vaucR~
    {                                                              //~vaucI~
    	rc2=ufprintfWCONS(Pfh,Ppattern,Pmsg);                      //~vaucR~
        if (rc2!=-1)    //not redirect err                         //~vaucI~
            return rc2;                                            //~vaucI~
    }                                                              //~vaucI~
#endif                                                             //~vaucI~
//  ufilecvUD2WCnopath(0,Ppattern,wkpatW,sizeof(wkpatW),NULL/*ucsctr*/);//~vaucR~//~v6J1R~
//  ufilecvUD2WCnopath(0,Pmsg,wkmsgW,sizeof(wkmsgW),NULL/*ucsctr*/);//~vaucI~//~v6J1R~
	opt=UFCVO_NOMSG;                                               //~v6J1I~
  rc2=                                                             //~v6J1I~
    ufilecvUD2WCnopath(opt,Ppattern,wkpatW,sizeof(wkpatW),NULL/*ucsctr*/);//~v6J1I~
    if (rc2)                                                       //~v6J1R~
    	return fprintf(Pfh,Ppattern,Pmsg);                         //~v6J1I~
  rc2=                                                             //~v6J1I~
    ufilecvUD2WCnopath(opt,Pmsg,wkmsgW,sizeof(wkmsgW),NULL/*ucsctr*/);//~v6J1I~
    if (rc2)                                                       //~v6J1R~
    	return fprintf(Pfh,Ppattern,Pmsg);                         //~v6J1I~
	ucsctr=fwprintf(Pfh,wkpatW,wkmsgW);                            //~vaucR~
    return ucsctr;                                                 //~vaucI~
}//ufprintfW                                                       //~vaucI~
//**************************************************************** //~vaucI~
// write to stdout/stderr using fwrite                             //~vaucI~
//*rc    :count                                                    //~vaucI~
//**************************************************************** //~vaucI~
size_t ufwriteWCONS(char *Pmsg,size_t Punit,size_t Pcount,FILE *Pfh)//~vaucI~
{                                                                  //~vaucI~
    UWCH wkmsgW[MAX_PRINTFW_MSGSZ];                                //~vaucI~
    int rc2;                                                       //~vaucR~
    int opt;                                                       //~v6J1I~
//*****************************                                    //~vaucI~
	if (!memchr(Pmsg,UD_NOTLC,strlen(Pmsg)))                       //~vaucI~
    	return fwrite(Pmsg,Punit,Pcount,Pfh);                      //~vaucI~
//  if (Guerropt2 & GBL_UERR2_CONSWRITE)      //use console write for UD fmt//~vaucI~
    {                                                              //~vaucI~
    	rc2=ufprintfWCONS(Pfh,"%s",Pmsg);                          //~vaucI~
        if (rc2!=-1)    //not redirect err                         //~vaucI~
            return Pcount;                                         //~vaucI~
    }                                                              //~vaucI~
//  ufilecvUD2WCnopath(0,Pmsg,wkmsgW,sizeof(wkmsgW),NULL/*ucsctr*/);//~vaucI~//~v6J1R~
	opt=UFCVO_NOMSG;                                               //~v6J1I~
  rc2=                                                             //~v6J1R~
    ufilecvUD2WCnopath(opt,Pmsg,wkmsgW,sizeof(wkmsgW),NULL/*ucsctr*/);//~v6J1I~
  if (!rc2)                                                        //~v6J1R~
	fwprintf(Pfh,L"%s",wkmsgW);                                    //~vaucI~
  else                                                             //~v6J1I~
	fprintf(Pfh,"%s",Pmsg);                                        //~v6J1I~
    return Pcount;                                                 //~vaucI~
}//ufwriteWCONS                                                    //~vaucI~
#endif	//W32UNICODE                                               //~vaucI~
//**************************************************************** //~v6T7I~
void uerrmsg_initstart(char *Pworkdir)                             //~v6T7I~
{                                                                  //~v6T7I~
#ifndef ARM                                                         //~vb26I~//~v6T7I~
	ULONG pid;                                                     //~v6T7I~
    char fpath[_MAX_PATH];                                         //~v6T7I~
//******************                                               //~v6T7I~
    Sworkdir=Pworkdir;                                             //~v6T7I~
    Guerropt2|=GBL_UERR2_INIT_INPROG; //xe init in progress        //~v6T7I~
    pid=ugetpid();                                                 //~vb26I~//~v6T7I~
    sprintf(fpath,"%s%s.%ld",Pworkdir,ERRFNM_STACK,pid);           //~v6T7I~
    Sfhstack=fopen(fpath,"w");                                     //~v6T7I~
#endif                                                             //~v6T7I~
}                                                                  //~v6T7I~
//**************************************************************** //~v6T7I~
void uerrmsg_initstack(char *Pmsg)                                 //~v6T7R~
{                                                                  //~v6T7I~
#ifndef ARM                                                        //~v6T7I~
//******************                                               //~v6T7I~
	if (Sfhstack)                                                  //~v6T7I~
    {                                                              //~v6T7I~
	    Guerropt2|=GBL_UERR2_INIT_MSGSTACK;                        //~v6T7I~
    	fprintf(Sfhstack,"%s\n",Pmsg);                             //~v6T7I~
    }                                                              //~v6T7I~
#endif                                                             //~v6T7I~
}                                                                  //~v6T7I~
//**************************************************************** //~v6T7I~
void uerrmsg_initcomp()                                            //~v6T7I~
{                                                                  //~v6T7I~
#ifndef ARM                                                        //~v6T7I~
	ULONG pid;                                                     //~v6T7I~
    char fpath[_MAX_PATH];                                         //~v6T7I~
//******************                                               //~v6T7I~
    Guerropt2&=(UINT)(~GBL_UERR2_INIT_INPROG); //xe init in progress//~v6T7M~
    fclose(Sfhstack);                                              //~v6T7R~
    ugeterrmsg();	//clear errmsg                                 //~v6T7I~
    pid=ugetpid();                                                 //~v6T7I~
    if (Guerropt2 & GBL_UERR2_INIT_MSGSTACK)                       //~v6T7R~
    {                                                              //~v6T7I~
    	uerrmsg("At initialization, some error message was written to %s.%ld.",//~v6T7I~
        		"初期処理中にエラーを検知しました、%s.%ld をチェックしてください",//~v6T7I~
                	"::" ERRFNM_STACK,pid);                        //~v6T7R~
    }                                                              //~v6T7I~
    else                                                           //~v6T7I~
    {                                                              //~v6T7I~
	    sprintf(fpath,"%s%s.%ld",Sworkdir,ERRFNM_STACK,pid);       //~v6T7R~
    	uremove(fpath);                                            //~v6T7R~
    }                                                              //~v6T7I~
#endif                                                             //~v6T7I~
}                                                                  //~v6T7I~
