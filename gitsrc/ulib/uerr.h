//*CID://+vbDcR~:                             update#=   65;       //+vbDcR~
//******************************************************
//*uerr.h
//******************************************************
//vbDd:250704 compiler err c2059(typedef function). missing *      //+vbDcI~
//vbDb:250704 display func description(FTnamee/j) to scrtype err   //~vbDbI~
//vbDa:250703 (gxe)helpmsg was not controled by scr height.        //~vbDaI~
//v6U0:180305 debug assertion failed Expression:_format_char != '\0' at errmsgedit sprintf; count argment count//~v6U0I~
//v6T7:180220 stack errmsg to errmsg.<pid> and issue notification at initcomp//~v6T7I~
//v6H8:170109 (BUG)FTP del dir fail(remains subdir)                //~v6H8I~
//v6xq:150116 add uapierr1nt                                       //~v6xqI~
//v6v0:140623 (LNX:BUG)uerrmsg for xsub,utf8 fnm was cv to utf8 twice//~vav0I~
//vauc:140420 (Win)unicode support by UD fmt string                //~vaucI~
//v6hM:120917 (BUG)abend at uerrmsg by too long msg(max msg ll=4096 and _MAX_PATH=4096)//~v6hMI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v620:090506 merge UTF8 version                                   //~v620I~
//            utf8 string parm conversion is done at xescr.c       //~v620I~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5mK:080709 add errmsg area size option for errmsg_init          //~v5mKI~
//v60r:071026 (UTF)utf8mode for each file                          //~v60rI~
//v60b:071006 (UTF) no errmsg conversion option for xprint on Win  //~v60bI~
//v5jd:061002 3270 support:rename/delete                           //~v5jdI~
//v5j3:060912 add uerrapi1tx etc(display error description)        //~v5j3I~
//v5iy:060908 (WIN)add ugetlasterrmsg                              //~v5iyI~
//v5ix:060908 add uconfirmmsg from xfs                             //~v5ixI~
//v5iw:060907 uerrmsg timestamp display option                     //~v5iwI~
//v5i8:060601 (LNX:FC5)errmsg by utf8(accordingly for gxe "g_locale_to_utf8" do no conversion,//~v5i8I~
//             for xe utf8 msg processed by gnome-terminal)        //~v5i8I~
//v5c2:040322 (WXE)uerr is accessed from WXE                       //~v5c2I~
//v5bz:040314 set force_english option to gbl for wxe help msg     //~v5bzI~
//v570:020824 wxe support                                          //~v570I~
//v55a:020427 (UNX:BUG)mdoscmd clear errmsg by ugeterrmsg;save and restore//~v55aI~
//v50u:010421 EUC japanese errmsg under kon                        //~v50uI~
//v324 000813:LINUX support(CRLF)                                  //~v324I~
//v293:991031 no beep option support                               //~v293I~
//v200:981025 uerrmsgcat:strcat to previous errmsg if prev is short enough//~v200I~
//v191:980831 bell option for uerrexit(uerrexit_optinit)           //~v191R~
//v182:980607 uerrmsg2:msg if no prev msg pending                  //~v182I~
//            ugeterrmsg2:msg get but not clear                    //~v182I~
//v062:970210:external err msg out control                         //~v062I~
//v060:970201:function:uerrhelpmsg:for help,wait key enter to continue//~v060I~
//           :function:uerrscrheight:get max row                   //~v060I~
//           :function:uerrmsgedit:uerrmsg but no output to any    //~v060I~
//           :control dbcs flag by external symbol for test use    //~v060I~
//v040:961027:uerrapi0,uerrapi0x(errmsg with no parm)              //~v040I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//******************************************************           //~v022I~
#define UERRMSG_MAXPARM   10                                       //~v6hhI~
//#define MAX_UERRMSGLL  4096                                      //~v6hMR~
//efine MAX_UERRMSGLL  (4096+_MAX_PATH+_MAX_PATH)                  //~v6hMR~//~v6H8R~
#define MAX_UERRMSGLL  (4096*3)      //4096+FTP_MAXPATH*2          //~v6H8I~
                                                                   //~v5j3I~
#define GBL_UERR_BG			0x01		//*back ground exec        //~v060R~
#define GBL_UERR_DBCSSET  	0x02		//*determined              //~v060I~
#define GBL_UERR_DBCSMODE   0x04		//*DBCS mode               //~v060I~
#define GBL_UERR_NOMSGOUT   0x08		//*uerrmsg:edit only,no output to any//~v062R~
#define GBL_UERR_NOMSGOUTSV 0x80		//*uerrmsg:edit only,no output to any//~v062I~
#define GBL_UERR_SJIS2EUC   0x40        //sjis to euc conversion required//~v50uI~
#define GBL_UERR_FORCEENG   0x20        //force english option     //~v5bzI~
#define GBL_UERR_SJIS2UTF8  0x10        //sjis 2 utf8 conversion   //~v5i8I~
                                                                   //~v60bI~
//#ifdef UTF8SUPP                                                  //~v5n8R~
#define GBL_UERR2_NOCONV    0x01        //no conversion            //~v60bI~
#define GBL_UERR2_NOCONV1   0x02        //no conversion in this call only//~v60bI~
#define GBL_UERR2_NOCONV2   0x04        //to stdout,use native locale//~v60rI~
//#define GBL_UERR2_CONVPARM  0x08        //convert each parm from locale to utf8//~vav0R~
//#define GBL_UERR2_CONSWRITE 0x10        //use console write for UD fmt//~vaucR~
#define GBL_UERR2_UTF8STDO  0x10        //for xsub(not xe),printf to stdout of LNX UTF8 env//~vav0I~
#define GBL_UERR2_S2UJMSG   0x20        //SJIS Pjmsg was translated to UTF8//~vav0I~
#define GBL_UERR2_INIT_INPROG           0x0040        //from xe uerrmsg_initstart()//~v6T7R~
#define GBL_UERR2_INIT_MSGSTACK         0x0080        //uerrmsg called before init comp//~v6T7I~
#ifdef W32                                                         //~v6U0I~
#define GBL_UERR2_OUTUTF8               0x0100        //uerrmsg by utf8 encoding//~v6U0I~
#endif                                                             //~v6U0I~
//#endif                                                           //~v5n8R~
#ifdef GBL_UERR                                                    //~v060I~
    unsigned char Guerropt;                                        //~v060I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
    unsigned int  Guerropt2;                                       //~v60bI~
//#endif                                                           //~v5n8R~
#else                                                              //~v060I~
    extern unsigned char Guerropt;                                 //~v060I~
//#ifdef UTF8SUPP                                                  //~v5n8R~
    extern unsigned int  Guerropt2;                                //~v60bR~
//#endif                                                           //~v5n8R~
#endif                                                             //~v060I~
#define UERR_MSG_J() (UCBITCHK(Guerropt,GBL_UERR_DBCSMODE) && !UCBITCHK(Guerropt,GBL_UERR_FORCEENG))//~vbDbI~
#define UERRSETSNOMSG() ( Guerropt=(char)((Guerropt&~GBL_UERR_NOMSGOUTSV) \
           |((Guerropt&GBL_UERR_NOMSGOUT)<<4)|GBL_UERR_NOMSGOUT) ) //~v062I~
#define UERRBACKNOMSG() ( Guerropt=(char)((Guerropt&~GBL_UERR_NOMSGOUT) \
           |((Guerropt&GBL_UERR_NOMSGOUTSV)>>4)) )                 //~v062R~
//******************************************************           //~v060I~
//typedef void (UEXITFUNC)(char *,void *);    //edit msg and exit parm of uerrexit_init//+vbDcR~
typedef void (*UEXITFUNC)(char *,void *);    //edit msg and exit parm of uerrexit_init//~vbDbI~
#ifdef __cplusplus                                                 //~v5c2I~
	extern "C" {                                                   //~v5c2I~
#endif                                                             //~v5c2I~
//*******************************************************          //~v293I~
int ubell_init(int Popt);                                          //~v293R~
//*******************************************************          //~v297I~
void ubell_init2(int *Pkbdinpctr);                                 //~v297I~
//*******************************************************
void ubell(void);
//******************************************************
//   uerrexit(English msg,Japanese msg,... )
void uerrexit(char *     ,char *      ,... );
//   uerrexit_init(title ,output handle,exit function,exit func parm);
//void uerrexit_init(char *Ptitle,FILE *Poutput,char *Pmapfile,UEXITFUNC *Pexitfunc,void *Pexitparm);//+vbDcR~
void uerrexit_init(char *Ptitle,FILE *Poutput,char *Pmapfile,UEXITFUNC Pexitfunc,void *Pexitparm);//+vbDcI~
//******************************************************           //~v191I~
void uerrexit_optinit(int Popt);                                   //~v191R~
#define UERREXIT_BELL     	0x01                                   //~v191R~
//#ifdef UTF8SUPP                                                  //~v5n8R~
//*********************************************************************//~v60bI~
//*set uerrexit option                                             //~v60bI~
//*********************************************************************//~v60bI~
int uerrsetopt2(unsigned int Pon,unsigned int Poff);               //~v60bR~
//#endif                                                           //~v5n8R~
//******************************************************
//    uerrmsg(English msg,Japanese msg,... )
char *uerrmsg(char *     ,char *      ,... );
//******************************************************           //~v182I~
char *uerrmsg2(char *Pemsg ,char *Pjmsg,... );                     //~v182I~
//******************************************************           //~v570I~
//char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,unsigned long *Pparg);//~v570I~//~v6hhR~
char *uerrmsgedit(char *Ptitle,char *Pemsg ,char *Pjmsg,ULPTR *Pparg);//~v6hhI~
//******************************************************           //~v060I~
char *uerrsprintf(char *Pemsg ,char *Pjmsg,... );                  //~v060I~
//******************************************************           //~v5n8M~
#ifdef WCSUPP                                                      //~v5n8I~
//******************************************************           //~v5n8M~
	int uerrfprintfutf(int Popt,FILE *,char *Pemsg ,char *Pjmsg,... );//~v5n8I~
    #define UERRFPUO_EDIT     0x00     //sjis to euc required      //~v5n8R~
    #define UERRFPUO_NOEDIT   0x01     //already uerrmsgedit end(source is EUC or SJIS)//~v5n8I~
    #define UERRFPUO_CVL2F    0x02     //LNX:from xe,cv euc2utf for last remaining errmsg to stdout//~vav0I~
#endif                                                             //~v5n8I~
//******************************************************           //~v060I~
char *uerrhelpmsg(FILE *Poutf,FILE *Pqueryf,char *Pemsg ,char *Pjmsg,... );//~v060I~
void  uerrhelpmsgSetScrHeight(int PscrH);                          //~vbDaI~
//**********************************************************************//~v060I~
int uerrscrheight(void);                                           //~v060I~
//******************************************************        //~5B11I~
void uerrmsg_init(char *Ptitle,FILE *Poutput,int Popt);         //~5B11R~
#define  UERR_OPTION    		0xff00                          //~5B11R~
#define  UERR_ATTR		    	0x00ff                          //~5B11I~
#define  UERR_FORCE_ENGLISH  	0x0100                          //~5B11I~
#define  UERR_TIMESTAMP      	0x0200                             //~v5iwI~
#define  UERR_SIZEPOWER      	0x7000   //MAX_UERRMSGLL(4k)*max(2**7)=512K//~v5mKI~
#define  UERR_GETSIZEPOWER(opt) ((opt&UERR_SIZEPOWER)>>12)         //~v5mKI~
#define  UERR_SETSIZEPOWER(sz)  ((sz<<12)&UERR_SIZEPOWER)          //~v5mKR~
//******************************************************           //~v55aI~
char *useterrmsg(char *Perrmsg);                                   //~v55aI~
//******************************************************
char *ugeterrmsg(void);
//******************************************************           //~v182I~
char *ugeterrmsg2(void);                                           //~v182I~
//******************************************************           //~v200I~
char *uerrmsgcat(char *Pemsg ,char *Pjmsg,... );                   //~v200R~
//******************************************************           //~v5ixI~
char uconfirmmsg(char *Pmsge,char *Pmsgj,char *Preply);            //~v5ixR~
//******************************************************           //~v5iyM~
char *uerrornomsg(int Perrorno);                                   //~v5iyI~
//******************************************************           //~v5iyI~
#ifdef W32                                                         //~v5iyI~
	char *ugetlasterror(int *Pprc);                                //~v5iyR~
#endif                                                             //~v5iyI~
//**************************************************************** //~v5j3I~
char *ugeterrdescription(int Pgetlasterrsw,int *Pprc);             //~v5j3R~
//****************************************************************//~5A10I~
int uerrapi1(char  *Papiname,char  *Pparm1,int Papirc);         //~5A10R~
//**************************************************************** //~v022R~
void uerrapi1x(char  *Papiname,char  *Pparm1,int Papirc);          //~v022R~
//**************************************************************** //~v040I~
int uerrapi0(char  *Papiname,int Papirc);                          //~v040I~
//**************************************************************** //~v040I~
void uerrapi0x(char  *Papiname,int Papirc);                        //~v040I~
//**************************************************************** //~v5j3I~
int uerrapi1t(int Pgetlasterrsw,char  *Papiname,char  *Pparm1,int Papirc);//~v5j3R~
//**************************************************************** //~v6xqI~
int uerrapi1nt(int Pgetlasterrsw,char  *Papiname,ULONG Pparm1,char *Peditstr,int Papirc);//~v6xqI~
//**************************************************************** //~v5j3I~
void uerrapi1tx(int Pgetlasterrsw,char  *Papiname,char  *Pparm1,int Papirc);//~v5j3I~
//**************************************************************** //~v5j3I~
int uerrapi0t(int Pgetlasterrsw,char  *Papiname,int Papirc);       //~v5j3I~
//**************************************************************** //~v5j3I~
void uerrapi0tx(int Pgetlasterrsw,char  *Papiname,int Papirc);     //~v5j3I~
//**************************************************************** //~v5jdI~
int uerrnotsupported(char *Pcmd,char *Pcond,int Prc);              //~v5jdR~
#ifdef W32UNICODE                                                  //~vaucI~
//**************************************************************** //~v5j3I~
int uprintfW(char *Ppattern,char *Pmsg);                           //~vaucI~
//**************************************************************** //~vaucI~
int ufprintfW(FILE *Pfh,char *Ppattern,char *Pmsg);                //~vaucI~
//**************************************************************** //~vaucI~
size_t ufwriteWCONS(char *Pmsg,size_t Punit,size_t Pcount,FILE *Pfh);//~vaucI~
//**************************************************************** //~vaucI~
#endif                                                             //~vaucI~
void uerrmsg_initstart(char *Pworkdir);                            //~v6T7I~
void uerrmsg_initcomp();                                           //~v6T7I~
#ifdef __cplusplus                                                 //~v5c2I~
	}                                                              //~v5c2I~
#endif                                                             //~v5c2I~
