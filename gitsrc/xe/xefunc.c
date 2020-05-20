//*CID://+vbi3R~:                             update#=  381;       //~vbi3R~
//*************************************************************
//*xefunc.c
//************************************************************* //~v020I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vbds:171203 (BUG)FTFDUPACMDFUNC=FTFCMDONLY=0x40-->ini file error msg//~vbdsI~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vawt:140609 savelcctforerrmsg for 2nd operand for copy/move/rename//~vawtI~
//vavR:140405 (Bug of Vau7)savelcctforerrmsg from funccmd ddfmt parameter err;errmsg was not trated as utf8.//~vavRI~
//vavQ:140405 set parsed cmdlc(for xprint dcmd u8filename)         //~vavQI~
//vavp:140426 (vaub/vau7 for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//vanf:131209 alias cmd;support addtional parm;%*,%^ for filename,%@ all remaining//~vanfI~
//vana:131202 (BUG)dupkey not effective for char-key(scan+char)    //~vanaI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va90:110520 ANDROID porting                                      //~va90I~
//va6U:100725 (BUG) inifile valid char tbl was not effective       //~va6UI~
//va3Z:100323 (BUG)"not defined key" err msg for not defined on the panel if it is dup key//~va3ZI~
//va1C:091112 (UTF8)reffer pfh for filename codetype on errmsg     //~va1rI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//va04:090606 expand cmdbuff to include edit cmd for the file with _max_path//~va04I~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH;define MAXPARMSZ)//~va03I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v796:080723 (VC8)compiler warning                                //~v796I~
//v793:080715 /Nrr option to reset RCT-newline                     //~v793I~
//v790:080709 RCTLNL cmd line parameter /yn                        //~v790I~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v77n:080106*(BUG of v76i)missing dupkey err chk                  //~v77nI~
//v76i:070622 more(key by key) allowance for duplicated function key assignment//~v76iI~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~v768I~
//v75A:070429 accept ccfunc(std paste) by Ctrl+v if trigger is mouse even ccfunc option is OFF//~v75AI~
//v75z:070429 once issue warning if CCFUNC=OFF at 1st entry of Ctrl+Char//~v75zI~
//v744:070209 (BUG)dupkey intersection chk need(dupnext/dupprev pointer overrided)//~v744I~
//v71P:061107 enable cmd verb change on =0.2 panel                 //~v71PI~
//v70y:060903 (BUG)alias cmd remains %n is no parm is specified for the alias cmd//~v70yI~
//v705:060727 graphic char setup by external file(2 string for opt linech on/off)//~v705I~
//v691:060419 allow function key assign duplication for the case of partial duplication//~v691I~
//v67F:051230 (WXE)display screen between multiple cmds            //~v67FI~
//v67D:051229 (WXE:BUG) bell when " " cmd(not cmd input but by strcmd func)//~v67DI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v651:050712 (XXE)xxe support;AT cmd,sleep cmd                    //~v651I~
//v61j:050228 (LNX:BUG)funct errmsg funcname is sjis.              //~v61jI~
//v60w:050202 skip ubell() for each cmd for performance reason,ubell at last if err//~v60wI~
//v59p:041114 support comment cmd "#" for comment in exe cmd file  //~v59pR~
//v565:040329 nop cmd(";" only) for wxe mdg displey                //~v565I~
//v564:040326 (WIN)at cmd ignore err option "-i"                   //~v564I~
//v563:040325 (WIN)reject sleep and at cmd in exe cmd file         //~v563I~
//v562:040325 (WIN)AT cmd support                                  //~v562I~
//v561:040325 (WIN)break sleep by esc*2                            //~v561I~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55Y:040324 (WIN)Sleep cmd for multicmd                          //~v55YI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55k:040215 (LNX)uerrmsg parm of functbl err should be sjis funcname//~v55kI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//v51y:030704 xbc:option to set result output to cmd input line to continued operation//~v51yI~
//v50m:030102 accept tab cmd on any screen                         //~v50mI~
//v504:021006 accept ren cmd as "num reset" on edit scr            //~v504I~
//v48k:020511 allow dosxxx cmd(nod dos cmd(shell open))            //~v48kI~
//v48g:020505 abend at xe because Gproclastpft=0(after scrdisp call) when kbdproc returned with rc=-1//~v48gI~
//v20i:001009 dupkey list order;on edit screen-->dirlist screen    //~v20iI~
//v162:000409 beep is noisy.no beep for wrap by csr key.           //~v162I~
//v161:000409 (BUG)when vsplitted with short cmd line space,       //~v161I~
//            RET cmd from PF4 is destroyed.                       //~v161I~
//            (if cmd space=0,it also destroy 1 byte before).      //~v161I~
//v13a:991023 (BUG) space before ";" is dropped by v0jo,but it cause err for find "a ; b"//~v13aI~
//v0jr:980723 call scrdisp for mult cmd because active screen may change//~v0jrI~
//v0jq:980723 confirm UCWrcsrx/y is valid for cmd key              //~v0jqI~
//v0jo:980723 UPARSESETCONDELM of uparse2 generate 3 opd for "xx ;"//~v0joI~
//            it may cause too many opd                            //~v0joI~
//v0j3:980720 (BUG)operand no is of concatinated cmd cause too many opd//~v0j3I~
//v0j1:980720 concatinated cmd for opt screen(hsp;6;.. rejected. hsp;=6;.. accepted)//~v0j1I~
//v0ix:980718 key assign by key press                              //~v0ixI~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0iu:980717 cmd compare by strcpy not by memcpy because i and iii is dup//~v0iuI~
//v0it:980717 funckey change option support                        //~v0itI~
//            write to ini when cmd/key assign changed             //~v0itI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0im:980627 pfk cmd support(long cmd ove screenwidth)            //~v0imI~
//v0ih:980621 pfk cmd support(pfk table)                           //~v0ihI~
//v0ia:980530 add APPend cmd(avail by also CAP Alt+l)              //~v0iaI~
//v0br:970727 support RENUM command alias of NUM RESET             //~v0brI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0a2:970705:allow 00 input                                       //~v0a2I~
//            inhibit chk at func_char(null is EXT key)            //~v0a2I~
//v09P:970625:reject inhibit char input by change esc cmd(Gbl ptr) //~v09PI~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//            (duplcate alias support)                             //~v09wI~
//v09m:970518:pre-chk missing dest lcmd for copy/move on edit screen//~v09mI~
//            for rapid csr movement                               //~v09mI~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//v096:970412:(DOS:BUG)under Win95,Enter and Pad-Enter generate 0x000d when IMe mode,//~v096I~
//            cause abend at funccall because invalid match with ckftrt.//~v096I~
//            the code is not on manual so treate as 1c0d.         //~v096I~
//            but xefunc chk also scancode==0 before ckftrt chk.   //~v096I~
//v08l:961123:edit/browse line range parameter                     //~v08lI~
//v085:961024:W95 VC                                               //~v085I~
//v07a:960615:allow dup key assign to differrent function by set of assigned key//~v07aR~
//            color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//v06p:960324:(BUG)find ";;" fail issueing no operand           //~v06pI~
//v06e:960309:for num off case(FUNCTBL size shortening)         //~v06eI~
//v056:951015:general DOS command                               //~v056I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v035:950722:bug of 950527(2) when DEL cmdline string set     //~v035R~
//			   space as first char,leave cmd line preceding space//~v034R~
//		950729:cmd UTRACE                                       //~v035I~
//*v020:950611:dir support                                      //~v020I~
//*v020:950708:change dir support(dos command)                  //~v020I~
//*           :try dos cmd if cmd not found                     //~v020I~
//*************************************************************
//*v012:950617:protect minus set to rcsry when other screen draw case//~5618I~
//************************************************************* //~5618I~
//*950527 reverse "," cmd err                                   //~5527R~
//*    (2)drop preceding space of operand                       //~v035R~
//*950506 ctl char reject option                                //~5506I~
//*950505 assume XE as Edit;                                    //~5505I~
//*950504 UCWparm set (common for all not only each cmd line Find)//~5504R~
//*950501 bug when cmd char strt by ","                         //~5501I~
//*950205 RCTL exec(move KEY_Enter to Next line)                //~5205R~
//*950122 clipboard                                             //~5205I~
//*941212 chk SHIFT key status for key generate same code at SHIFT on/off//~5122I~
//*941209 exec by Enter key
//*941207 normal return also when QUIT
//*941123 no strupr for find
//*941120 cmd compair string len
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32                                                         //~v560I~
	#include <sys\timeb.h>                                         //~v560I~
#endif                                                             //~v560I~
#ifdef XXE                                                         //~v651I~
	#include <sys/timeb.h>                                         //~v651I~
#endif                                                             //~v651I~
//**************************************************************
#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
    	#include <windows.h>                                       //~v55YR~
	#else                                                          //~v085I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v085I~
#endif
//*******************************************************
#include <uque.h>
#include <ulib.h>
#include <uerr.h>
#include <ukbd.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~5506I~
#include <utrace.h>                                             //~v035I~
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v161I~
#include <uedit.h>                                                 //~v55WI~
#include <ucalc2.h>                                                //~v560I~
#include <utf.h>                                                   //~vawtI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xekbd.h"                                                 //~v0iwM~
#include "xefile.h"                                                //~v09mI~
#include "xefile7.h"                                               //~v0ioI~
#include "xefunc.h"
#include "xefunc2.h"                                            //~5114I~
#include "xefunct.h"                                            //~5216I~
#include "xecsr.h"
#include "xepan.h"                                              //~5318I~
#include "xepan2.h"                                                //~v0j1I~
#include "xesub.h"                                              //~5318I~
#include "xeerr.h"                                                 //~v50mI~
#include "xemousel.h"                                              //~v53mR~
#include "xegbl.h"                                                 //~v79zI~
#ifdef WXE                                                         //~v55WI~
	#include "wxexei.h"                                            //~v55WI~
	#include "wxexei3.h"                                           //~v67CI~
#endif                                                             //~v55WI~
#ifdef XXE                                                         //~v651I~
	#include "xxexei.h"                                            //~v651I~
#endif                                                             //~v651I~
#ifdef UTF8SUPPH                                                   //~va1CI~
#include "xepan22.h"                                               //~va1CI~
#include "xeutf.h"                                                 //~va1CI~
#endif                                                             //~va1CI~
//**************************************************
//#define RC2CONSEQERR 2  	//conseqtive err to set csr next line  //~v51yR~
#define SLEEPPEEKINTVL  100  //peek console each 100ms when sleeping//~v561I~
#define SLEEPMSGINTVL   1000 //sleep end/reset msg display interval//~v562R~
#define FUNC_COMMENTID  '#'  //comment prefix for comment in exe cmd file//~v59pI~
//*********************************************************        //~v76iI~
//*********************************************************
int funcduperr(USHORT Pkey,FUNCTBL *Pft1,FUNCTBL *Pft2,int Pindex,int Pshift);
int cmdduperr(FUNCTBL *Pft1,FUNCTBL *Pft2,int Palias);          //~5105I~
int callmenu(PUCLIENTWE Ppcw,UCHAR *Pcmd);                      //~5504I~
int funccmdprechk(PUCLIENTWE Ppcw,FUNCTBL *Ppft);                  //~v09mI~
int  funccmderr0(PUCLIENTWE Ppcw);                                 //~v565I~
int  funccmderr2(PUCLIENTWE Ppcw);                                 //~v09mI~
int funcsleepsettimeup(PUCLIENTWE Ppcw,int Pintvl);                //~v562R~
#ifdef WINCON                                                      //~v562I~
    int funcatcmdinit(char *Pcmd);                                 //~v562I~
    int funcatcmdctl(PUCLIENTWE Ppcw);                             //~v562R~
    int funcsleepwake(PUCLIENTWE Ppcw,int Popt,int Ptime);         //~v562R~
    #define FSW_RESET 1                                            //~v562I~
    #define FSW_COMP  2                                            //~v562R~
#endif                                                             //~v562I~
int  funcaliasset(PUCLIENTWE Ppcw,char *Ppcend,PALCT Ppalct);      //~v67CI~
void  funcaliasreset(void);                                        //~v67CI~
void  funcaliasdeqpending(void);                                   //~v67CI~
#ifdef WXEXXE                                                      //~v67CI~
	int  funcaliassetwxe(PUCLIENTWE Ppcw,char *Pacmdedit,int Plen);//~v67CI~
#endif                                                             //~v67CI~
int funcsaveopd2codetype(int Popt,PUCLIENTWE Ppcw);                //~vawtR~
//************************************                          //~5216M~
                                                                   //~v76iI~
typedef struct _DUPKEYT                                            //~v76iI~
{                                                                  //~v76iI~
    USHORT   DKTkey;                                               //~v76iR~
    int      DKTshift;	//shift key on case(key value is same with and without shift modifier)//~v76iR~
	FUNCTBL *DKTpft[UCWMAXTYPE];                                   //~v76iR~
} DUPKEYT,*PDUPKEYT;                                               //~v76iI~
#define MAXDKT 64   //allow max dupkey                             //~v76iI~
static DUPKEYT Sdupkeyt[MAXDKT];                                   //~v76iI~
static int     Sdupkeytno=0;	//current count                    //~v76iI~
                                                                   //~v76iI~
static UQUEH    Sqhpmc;                                            //~v67CI~
static FUNCTBL *Sfunctbl;                                       //~5216I~
//*funct reference table
//*char key function table
#define CFTMAXCHAR 256
#define CFTMAXSCAN 4
static FUNCTBLC ckftrt[CFTMAXCHAR];                                //~v0ihR~
//*extended key function table
static	FUNCTBL *ekftrt[256]; //extended key func tbl ptr
static	FUNCTBL *sckftrt[256]; //for same code for SHIFT on/off,char key
static	FUNCTBL *sekftrt[256]; //for same code for SHIFT on/off,ext key 
static	FUNCTBL *Sfuncedit; //edit function tbl addr for XE cmd //~5505I~
//static	FUNCTBL *Sfuncnum; 	//num function tbl addr for RENUM cmd//~v504R~
static	FUNCTBL *Sfuncdos ; //DOS cmd function tbl addr for XE cmd//~v020I~
static  WORKFTHDR Sworkfthdr={0,0,ckftrt,sckftrt,ekftrt,sekftrt};; //~v0ioR~
//static	UCHAR   *Svalidchar;//valid char tbl                   //~v09PR~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
    static int Spendatcmd=0,Satcmdintvl,Satcmdctr,Satcmdopt;       //~v564R~
    #define ATCPEND_ACCEPT          1 //at cmd parm saved          //~v562I~
  #ifdef WINCON                                                    //~v562M~
    #define ATCPEND_SUBCMDSTART     2 //1st repeat ended           //~v562I~
    #define ATCPEND_SUBCMDEND       3 //end of interval sleep      //~v562I~
    #define ATCPEND_SLEEP           4 //entered interval sleep     //~v562I~
  #endif                                                           //~v562I~
#endif                                                             //~v55WI~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
	static struct timeb Stmbsleep={0,0,0,0};//dstflag,millitm,time,timezone//~v560I~
#endif                                                             //~v560I~
#ifdef WINCON                                                      //~v562I~
	static char Satcmdstring[MAXCOLUMN+1];                         //~v562I~
	static char Ssleepcmdstring[MAXCOLUMN+1]={0};                  //~v562R~
	static char **Smulticmd2ndptr=0;                               //~v562R~
    static int Satcmdcurrctr=0;                                    //~v562I~
#endif                                                             //~v562I~

//**************************************************
//**************************************************
//* key function table init
//**************************************************
//int funcinit(void)                                               //~v705R~
int funcinit(char *Postype)                                        //~v705I~
{
	int i,j;
	FUNCTBL *pft,*pft2;                                         //~5105R~
	KEYTBL  *pkt;
	USHORT key;
	UCHAR scanc,charc,*pc,*pc2;                                 //~5105R~
	int rc=0,dbcssw;                                               //~v0iuR~
    int ftctr;                                                     //~v0ioI~
    int shiftid;                                                   //~v0ixI~
//*********************
#ifdef UNX                                                         //~v61jI~
    functsjis2euc();                                               //~v61jI~
#endif                                                             //~v61jI~
//  Gpodelmt=UALLOCM((UINT)(UPODELMTBLSZ*MAXCOLUMN));//parm to uparse2//~v08lR~//~va03R~
	Gpodelmt=UALLOCM((UINT)(UPODELMTBLSZ*MAXPARMSZ));//parm to uparse2//~va03I~
//	functinit();                                                   //~v705R~
  	functinit(Postype);                                            //~v705I~
	Gvalidchartbl=UALLOCM(256);                                    //~v09PR~
    memcpy(Gvalidchartbl,kbdgetchartbl(0),256);                    //~v09PR~
	if (UCBITCHK(Gopt2,GOPT2REJECTCTLCHAR))	//reject all        //~5506I~
   		memset(Gvalidchartbl,1,32);  //reject all                  //~v09PR~
	Sfunctbl=Gfunctbl;	//functbl addr                          //~5429R~
//  dbcssw=UCBITCHK(Gscrstatus,GSCRSDBCS);                         //~v79zR~
    dbcssw=(int)XE_ISDBCSJ();	//Japanese                         //~v79zR~
	if (Guerropt & GBL_UERR_FORCEENG)      //not english mode test //~v705R~
        dbcssw=0;                                                  //~v705I~
//*move KEY_ENTER from FUNCID_EXECNL to FUNCID_NEXTLINE         //~5205I~
//    if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use right-ctl as execute+nl//~v55cR~
//    {                                                            //~v55cR~
//        for (;;)    //err break                                  //~v55cR~
//        {                                                        //~v55cR~
//            if (Sfunctbl[0].FTfuncid!=FUNCID_EXECNL              //~v55cR~
//            ||  Sfunctbl[1].FTfuncid!=FUNCID_NEXTLINE)           //~v55cR~
//            {                                                    //~v55cR~
//                uerrmsg("Func tbl seq err,it must be 1st ExecNL,2nd Nextline",0);//~v55cR~
//                ubell();                                         //~v55cR~
//                break;                                           //~v55cR~
//            }                                                    //~v55cR~
//            for (i=0;i<FTMAXKEY;i++)                             //~v55cR~
//                if (Sfunctbl[0].FTkey[i]==KEY_ENTER)             //~v55cR~
//                    break;                                       //~v55cR~
//            if (i==FTMAXKEY)    //not defined                    //~v55cR~
//            {                                                    //~v55cR~
//                uerrmsg("Enter key is not assigned to func Execute+Nextline",0);//~v55cR~
//                ubell();                                         //~v55cR~
//                break;                                           //~v55cR~
//            }                                                    //~v55cR~
//            for (j=0;j<FTMAXKEY;j++)        //search idle entry  //~v55cR~
//                if (!Sfunctbl[1].FTkey[j])                       //~v55cR~
//                    break;                                       //~v55cR~
//            if (j==FTMAXKEY)    //not defined                    //~v55cR~
//            {                                                    //~v55cR~
//                uerrmsg("No idle key entry for Next line",0);    //~v55cR~
//                ubell();                                         //~v55cR~
//                break;                                           //~v55cR~
//            }                                                    //~v55cR~
//            Sexecutekeyindex=i;                                  //~v55cR~
//            Snextlinekeyindex=j;                                 //~v55cR~
//            Sfunctbl[1].FTkey[j]=Sfunctbl[0].FTkey[i];           //~v55cR~
//            Sfunctbl[1].FTkflag[j]=Sfunctbl[0].FTkflag[i];       //~v55cR~
//            Sfunctbl[0].FTkey[i]=Sfunctbl[0].FTkflag[i]=0;       //~v55cR~
//        }//err break                                             //~v55cR~
//    }//RCTL use                                                  //~v55cR~
//*create key-func table                                        //~5205I~
	ftctr=0;                                                       //~v0ioI~
	for (pft=Sfunctbl;*(pft->FTnamee);pft++)	//all ft entry
	{
    	ftctr++;                                                   //~v0ioI~
//  	pft->FTcmdlen=(UCHAR)strlen(pft->FTcmd);	//compair len  //~v0iuR~
//  	pft->FTcmdalen=(UCHAR)strlen(pft->FTcmda);	//compair len alias//~v0iuR~
		for (i=0;i<FTMAXKEY;i++)	//all asigned key
		{
			key=pft->FTkey[i];
			if (!key)
				break;
//  		if (kbdsrchkt(key,&pkt),!pkt)	//not found            //~v0ixR~
    		if (shiftid=kbdsrchkt(key,&pkt),!pkt)	//not found    //~v0ixI~
			{
				pft->FTkflag[i]=(UCHAR)(pft->FTkflag[i]|FTKEYER);//~5222R~
				uerrmsg("key %04X cannot be used",
					    "キー %04X は 使用できません",
						key);
				ubell();
				break;
			}
			if (UCBITCHK(pft->FTkflag[i],FTSHIFT))//chk SHIFT key//~5222R~
            {                                                      //~v53mI~
#ifndef KKK                                                        //~vb50I~
			  if (shiftid<=1)	//Not alt nor Ctrl                 //~vb50I~
#endif                                                             //~vb50I~
              {                                                    //~vb50I~
				if (pkt->KTkey[0]!=pkt->KTkey[1])	//not same when shift//~5123I~
				{                                               //~5123I~
					UCBITOFF(pft->FTkflag[i],FTSHIFT);//ignore SHIFT flag//~5222R~
					if (dbcssw)                                 //~5216R~
						pc=pkt->KTnamej;
					else
						pc=pkt->KTnamee;
					uerrmsg("Ignored Shift Specification flag for %s",//~5123I~
						    "キー %s の シフト指定は無視しました",//~5123I~
							pc);                               //~5123I~
					ubell();                                    //~5123I~
				}                                               //~5123I~
                else                                               //~v0ixI~
                	shiftid=1;			//shift                    //~v0ixI~
              }                                                    //~vb50I~
            }//chk shift key                                       //~v53mI~
          	if (UCBITCHK(pft->FTkflag[i],FTFIX))                   //~v0ixI~
            	UCBITON(pkt->KTflag[shiftid],KTFIXED);             //~v0ixI~
			charc=(UCHAR)(key&255);
			scanc=(UCHAR)(key>>8);
			if (scanc==KEY_PENTRID)
			{
				scanc=charc;
				charc=0;			//trate as ext key
			}
			if (charc) 	//char key
			{
				if (UCBITCHK(pft->FTkflag[i],FTSHIFT))//chk SHIFT key//~5222R~
					if (!sckftrt[charc])	//new key
						sckftrt[charc]=pft;
					else
						rc+=funcduperr(key,sckftrt[charc],pft,i,FTSHIFT);
				else
					for (j=0;j<CFTMAXSCAN;j++)
					{
						if (!ckftrt[charc].ckscan[j])	//new key
						{
							ckftrt[charc].ckscan[j]=scanc;
							ckftrt[charc].ckpft[j]=pft;
							ckftrt[charc].ckflag[j]=pft->FTkflag[i];//~v55kI~
							break;
						}
						else
							if (ckftrt[charc].ckscan[j]==scanc)//same key
							{
								rc+=funcduperr(key,ckftrt[charc].ckpft[j],pft,i,0);	
								break;
							}//same key chk
					}//lower,upper,alt,ctrl
			}//char code
			else	//extended key
			{
				if (( dbcssw && UCBITCHK(pft->FTflag,FTFEONLY))    //~v48gR~
				||  (!dbcssw && UCBITCHK(pft->FTflag,FTFJONLY)))   //~v48gR~
					continue;	//japanese only or english only //~5216I~
				if (UCBITCHK(pft->FTkflag[i],FTSHIFT))//chk SHIFT key//~5222R~
					if (!sekftrt[scanc])	//new key           //~5216R~
                    {                                              //~vb50I~
						sekftrt[scanc]=pft;                     //~5216R~
                        UTRACEP("%s:sekftrt:FTSHIFT;scanc=%02x,pft=%s,shiftid=%d,FTflag[]=%02x\n",UTT,scanc,pft->FTnamej,i,pft->FTkflag[i]);//~vb50R~
                    }                                              //~vb50I~
					else                                        //~5216R~
						rc+=funcduperr(key,sekftrt[scanc],pft,i,FTSHIFT);//~5216R~
				else	//SHIFT key change key code             //~5216R~
					if (!ekftrt[scanc])	//new key               //~5216R~
                    {                                              //~vb50I~
						ekftrt[scanc]=pft;                      //~5216R~
                        UTRACEP("%s:ekftrt:noFTSHIFT;scanc=%02x,pft=%s,shiftmodifier=%d,FTflag[]=%02x\n",UTT,scanc,pft->FTnamej,i,pft->FTkflag[i]);//~vb50I~
                    }                                              //~vb50I~
					else                                        //~5216R~
						rc+=funcduperr(key,ekftrt[scanc],pft,i,0);//~5216R~
			}//extended key
		}//i:all key	
	}//all ft entry
    if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use right-ctl as execute+nl//~v55cI~
    	funcchngeenter(1);		//change ENTER key to cr from execute+cr//~v55cR~
    Sworkfthdr.WFTHentno=ftctr;                                    //~v0ioR~
//word duplicate chk		                                    //~5105I~
	for (pft=Sfunctbl;*(pft->FTnamee);pft++)	//all ft entry  //~5105I~
	{                                                           //~5105I~
//  	if (!pft->FTcmdlen)	//has no word                          //~v0iuR~
//  		continue;                                              //~v0iuR~
		pc=pft->FTcmd;                                          //~5105I~
    	if (!*pc)	//has no word                                  //~v0iuI~
    		continue;                                              //~v0iuI~
		pc2=pft->FTcmda;                                        //~5105I~
		for (pft2=Sfunctbl;*(pft2->FTnamee);pft2++)	//all ft entry//~5105I~
		{                                                       //~5105I~
//  		if (pft2<=pft || !pft2->FTcmdlen)//has no word         //~v0iuR~
    		if (pft2<=pft || !*pft2->FTcmd)//has no word           //~v0iuI~
				continue;                                       //~5105I~
//  		cmdlen=min(pft->FTcmdlen,pft2->FTcmdlen);              //~v0iuR~
//  		if (!memicmp(pc,pft2->FTcmd,(UINT)cmdlen))             //~v0iuR~
    		if (!stricmp(pc,pft2->FTcmd))                          //~v0iuI~
				cmdduperr(pft,pft2,0);                          //~5105I~
//  		cmdlen=min(pft->FTcmdalen,pft2->FTcmdalen);            //~v0iuR~
//  		if (cmdlen && !memicmp(pc2,pft2->FTcmda,(UINT)cmdlen)) //~v0iuR~
    		if (*pc2 && !stricmp(pc2,pft2->FTcmda))                //~v0iuI~
            {                                                      //~v09wI~
              if (!UCBITCHK(pft->FTflag,FTFDUPACMD)                //~v09wI~
              ||  !UCBITCHK(pft2->FTflag,FTFDUPACMD))              //~v09wI~
				cmdduperr(pft,pft2,1);                          //~5105I~
			  else	                                               //~v09wI~
              {                                                    //~v09wI~
                for (i=0;i<UCWMAXTYPE;i++)                         //~v09wI~
                	if (pft->FTfunc[i] && pft2->FTfunc[i])         //~v09wI~
                    	break;                                     //~v09wI~
                if (i<UCWMAXTYPE)                                  //~v09wI~
                {                                                  //~vbd7I~
//               if (UCBITCHK(pft->FTflag,FTFDUPACMDFUNC)          //~vbd7I~//~vbdsR~
//               &&  UCBITCHK(pft2->FTflag,FTFDUPACMDFUNC))        //~vbd7I~//~vbdsR~
                 if (UCBITCHK(pft->FTflag2,FTF2DUPACMDFUNC)        //~vbdsI~
                 &&  UCBITCHK(pft2->FTflag2,FTF2DUPACMDFUNC))      //~vbdsI~
                 	;                                              //~vbd7I~
                 else                                              //~vbd7I~
					cmdduperr(pft,pft2,1);                         //~v09wI~
                }                                                  //~vbd7I~
              }                                                    //~v09wI~
            }                                                      //~v09wI~
		}//all ft entry                                         //~5105I~
	}//all ft entry                                             //~5105I~
	if (funcgetwfth(0,0))	//init                                 //~v0ioR~
    	exit(8);                                                   //~v0ioI~
//*save edit pft addr for XE cmd                                //~5505I~
	Sfuncedit=functblsrch(FUNCID_EDIT);                         //~5505I~
//*save num pft addr for RENUM cmd                                 //~v0brI~
//  Sfuncnum=functblsrch(FUNCID_NUM);                              //~v504R~
//*save DOS pft addr for try dos when invalid verb              //~v020I~
	Sfuncdos=functblsrch(FUNCID_DOS);                           //~v020I~
#ifdef UNX                                                         //~v55kI~
    functsjis2euc();                                               //~v55kI~
#endif                                                             //~v55kI~
	return rc;
}//funcinit
//**************************************************               //~v55cI~
//*funcchngeenter                                                  //~v55cR~
//*reassign functbl of enter key                                   //~v55cI~
//**************************************************               //~v55cI~
int funcchngeenter(int Popt)                                       //~v55cR~
{                                                                  //~v55cI~
	int j,charc,scanc;                                             //~v55cR~
    FUNCTBL *pft;                                                  //~v55cI~
//*******************                                              //~v55cI~
//  if (Gotheropt & GOTHERO_RCTLNL) //rctl is used as newline      //~v790R~
//  if (Gotheropt & (GOTHERO_RCTLNL|GOTHERO_CLRCTLNL)) //rctl is used as newline//~v793R~
    if (Gotheropt & GOTHERO_RCTLNL) //rctl is used as newline      //~v793I~
        return 0;   //enter key is used as execute(no assign change)//~v768I~
	charc=KEY_ENTER & 255;                                         //~v55cI~
    scanc=KEY_ENTER>>8;                                            //~v55cI~
    if (Popt)	//rctl use                                         //~v55cI~
    	pft=&Sfunctbl[1];	//ENTER key for cr                     //~v55cR~
    else                                                           //~v55cI~
    	pft=&Sfunctbl[0];	//ENTER key for execute                //~v55cR~
    for (j=0;j<CFTMAXSCAN;j++)                                     //~v55cI~
    {                                                              //~v55cI~
        if (ckftrt[charc].ckscan[j]==scanc)   //new key            //~v55cI~
        {                                                          //~v55cI~
            ckftrt[charc].ckpft[j]=pft;                            //~v55cI~
            break;                                                 //~v55cI~
        }                                                          //~v55cI~
    }//lower,upper,alt,ctrl                                        //~v55cI~
    return 0;                                                      //~v55cI~
}//funcchngeenter                                                  //~v55cR~
//**************************************************               //~v0ioI~
//*workft gen for option save                                      //~v0ioI~
//*parm1 :option;0:init,1:full copy,2:copy fiexed key assign only  //~v0ioR~
//*parm2 :for opt=1,output addr of workfthdr ptr                   //~v0ioR~
//*retrn :rc (ULLOAC_FAILED)                                       //~v0ioI~
//**************************************************               //~v0ioI~
int funcgetwfth(int Popt,PWORKFTHDR Ppwfth)                        //~v0ioR~
{                                                                  //~v0ioI~
	int ii,jj;                                                     //~v0ioR~
    USHORT key;                                                    //~v0ioI~
    PFUNCTBL 	pft;                                               //~v0ioR~
    PWORKFT  	pwft;                                              //~v0ioR~
    PWORKFTHDR  pwfth;                                             //~v0ioI~
//*************                                                    //~v0ioI~
	if (Popt)	//get copy                                         //~v0ioI~
    {                                                              //~v0ioI~
		*Ppwfth=Sworkfthdr;                                        //~v0ioR~
        pwfth=Ppwfth;                                              //~v0ioI~
	}                                                              //~v0ioI~
    else		//init                                             //~v0ioI~
        pwfth=&Sworkfthdr;                                         //~v0ioR~
	if (pwfth->WFTHpwft && Popt!=2)                                //~v0ioR~
    	return 0;                                                  //~v0ioI~
    pwft=UALLOCC((UINT)(Sworkfthdr.WFTHentno),sizeof(WORKFT));     //~v0ioR~
    UALLOCCHK(pwft,UALLOC_FAILED);                                 //~v0ioR~
	pwfth->WFTHpwft=pwft;                                          //~v0ioI~
//                                                                 //~v0ioI~
	for (pft=Gfunctbl,ii=Sworkfthdr.WFTHentno;ii;pft++,pwft++,ii--)	//all ft entry//~v0ioR~
	{                                                              //~v0ioI~
        memcpy(pwft->WFTcmd,pft->FTcmd,sizeof(pwft->WFTcmd));      //~v0iwR~,//~v71PR~
        memcpy(pwft->WFTcmda,pft->FTcmda,sizeof(pwft->WFTcmda));   //~v0iwR~,//~v71PR~
		for (jj=0;jj<FTMAXKEY;jj++)	//all asigned key              //~v0ioI~
		{                                                          //~v0ioI~
			if (!(key=pft->FTkey[jj]))                             //~v0ioI~
            	break;                                             //~v0ioI~
          	if(Popt!=2 || UCBITCHK(pft->FTkflag[jj],FTFIX))        //~v0ioR~
            {                                                      //~v0ioI~
				pwft->WFTkey[jj] =key;                             //~v0ioR~
				pwft->WFTkflag[jj]=pft->FTkflag[jj];               //~v0ioR~
            }                                                      //~v0ioI~
		}//jj:all key                                              //~v0ioI~
	}//all ft entry                                                //~v0ioI~
    return 0;                                                      //~v0ioI~
}//funcgetwfth                                                     //~v0ioI~
                                                                   //~v0ioI~
//**************************************************               //~v0ioI~
//*update save updated work functbl                                //~v0itR~
//*parm1 :workft                                                   //~v0ioI~
//*retrn :rc                                                       //~v0ioI~
//**************************************************               //~v0ioI~
int funcputwfth(PWORKFTHDR Ppwfth,int Popt)                        //~v0ioR~
{                                                                  //~v0ioI~
    PWORKFT pwft1,pwft2;                                           //~v0ioI~
    int ii;                                                        //~v0ioI~
//*************                                                    //~v0ioI~
    pwft1=Sworkfthdr.WFTHpwft;                                     //~v0ioR~
    pwft2=Ppwfth->WFTHpwft;                                        //~v0ioR~
    for (ii=Sworkfthdr.WFTHentno;ii;ii--,pwft1++,pwft2++)          //~v0ioR~
    {                                                              //~v0ioR~
//      if (Popt==FILEFK_OPT05)                                    //~v0iwR~
//  	{                                                          //~v0iwR~
        	memcpy(pwft1->WFTcmd,pwft2->WFTcmd,sizeof(pwft1->WFTcmd));//~v0iwR~,//~v71PR~
        	memcpy(pwft1->WFTcmda,pwft2->WFTcmda,sizeof(pwft1->WFTcmda));//~v0iwR~,//~v71PR~
        	strupr(pwft1->WFTcmd);                                 //~v0iwR~,//~v71PR~
        	strupr(pwft1->WFTcmda);                                //~v0iwR~,//~v71PR~
//      }                                                          //~v0iwR~
//      else        //opt0.4                                       //~v0iwR~
//      {                                                          //~v0iwR~
        	memcpy(pwft1->WFTkey,pwft2->WFTkey,sizeof(pwft1->WFTkey));//~v0ioI~
        	memcpy(pwft1->WFTkflag,pwft2->WFTkflag,sizeof(pwft1->WFTkflag));//~v0ioI~
//      }                                                          //~v0iwR~
    }                                                              //~v0ioI~
  	UCBITON(Gprocstatus,GPROCSINIUPDATE); //ini write by option change//~v0itI~
	uerrmsg2("Update is effective on next session",                //~v0ioI~
			 "次回から有効");                                      //~v0ioI~
    return 0;                                                      //~v0ioI~
}//funcputwfth                                                     //~v0ioI~
                                                                   //~v0itI~
//**************************************************               //~v0itI~
//*update functbl by work ft,called at func_ini at term            //~v0itI~
//*parm :none                                                      //~v0itI~
//*retrn:none                                                      //~v0itI~
//**************************************************               //~v0itI~
void funcsetft(void)                                               //~v0itI~
{                                                                  //~v0itI~
    PWORKFT pwft;                                                  //~v0itI~
    PFUNCTBL 	pft;                                               //~v0itI~
    int ii;                                                        //~v0itI~
//*************                                                    //~v0itI~
    pwft=Sworkfthdr.WFTHpwft;                                      //~v0itI~
	for (pft=Gfunctbl,ii=Sworkfthdr.WFTHentno;ii;pft++,pwft++,ii--)	//all ft entry//~v0itI~
    {                                                              //~v0itI~
        memcpy(pft->FTcmd,pwft->WFTcmd,sizeof(pft->FTcmd));        //~v0iwR~,//~v71PR~
        memcpy(pft->FTcmda,pwft->WFTcmda,sizeof(pft->FTcmda));     //~v0iwR~,//~v71PR~
        memcpy(pft->FTkey,pwft->WFTkey,sizeof(pft->FTkey));        //~v0itI~
        memcpy(pft->FTkflag,pwft->WFTkflag,sizeof(pft->FTkflag));  //~v0itR~
    }                                                              //~v0itI~
    return;                                                        //~v0itR~
}//funcsetft                                                       //~v0itI~
                                                                   //~v0itI~
//**************************************************
//*chk allowable dup assign and issue err msg                      //~v07aR~
//*dup ok only when screen type is not duplicated                  //~v07aI~
// and key assingnment is whole same                               //~v07aI~
//*parm1 :key
//*parm2 :func tbl addr1(previous entry)                           //~v691R~
//*parm3 :func tbl addr2(new entry)                                //~v691R~
//*parm4 :assigned key index of FTkflag[]                          //~vb50R~
//*parm5 :SHIFT key option
//*retrn :0:dup accepted,1:dup err                                 //~v07aR~
//**************************************************
int funcduperr(USHORT Pkey,FUNCTBL *Pft1,FUNCTBL *Pft2,int Pindex,int Pshift)
{
	UCHAR *pc1,*pc2,*keyname;
//  FUNCTBL *pftnext;                                              //~v76iR~
    int ii;                                                        //~v07aI~
//  int jj;                                                        //~v76iR~
//  int intersecterrsw=0;                                          //~v76iR~
	PDUPKEYT pdupkt;                                               //~v76iI~
    FUNCTBL **ppft,*pft,*pftdup1=0,*pftdup2=0;                     //~vaf9R~
    int duperrsw;                                                  //~v76iI~
//**********************
//    if ((pftnext=Pft1->FTdupnext)==Pft2)//processed previous(multi key assignment case)//~v76iR~
//        return 0;                                                //~v76iR~
//    if (!pftnext)   //allow duplication only once(between two function)//~v76iR~
//    {                                                            //~v76iR~
//        for (ii=0;ii<UCWMAXTYPE;ii++)                            //~v76iR~
//            if (Pft1->FTfunc[ii] && Pft2->FTfunc[ii])//screen type duplicated//~v76iR~
//                break;                                           //~v76iR~
//        if (ii==UCWMAXTYPE) //not duplicated screen type         //~v76iR~
//        {                                                        //~v76iR~
////          if (!memcmp(Pft1->FTkey,Pft2->FTkey,sizeof(Pft1->FTkey))//~v76iR~
////          &&  !memcmp(Pft1->FTkflag,Pft2->FTkflag,sizeof(Pft1->FTkflag)))//~v76iR~
//            for (jj=0;jj<FTMAXKEY;jj++)                          //~v76iR~
//                if (Pft1->FTkey[jj]==Pkey                        //~v76iR~
//                &&  (Pft1->FTkflag[jj]&FTSHIFT)==Pshift)         //~v76iR~
//                    break;                                       //~v76iR~
//            if (jj<FTMAXKEY)    //dupkey shift status is same    //~v76iR~
//            {                                                    //~v76iR~
//              if((Pft1->FTdupnext && Pft1->FTdupnext!=Pft2)      //~v76iR~
//              || (Pft2->FTdupprev && Pft2->FTdupprev!=Pft1))     //~v76iR~
//                intersecterrsw=1;                                //~v76iR~
//              else                                               //~v76iR~
//              {                                                  //~v76iR~
//                Pft1->FTdupnext=Pft2;//accepted dup key assign   //~v76iR~
//                Pft2->FTdupprev=Pft1;//accepted dup key assign   //~v76iR~
//                return 0;   //whole same key assignment          //~v76iR~
//              }                                                  //~v76iR~
//            }                                                    //~v76iR~
//        }//screen type different                                 //~v76iR~
//    }                                                            //~v76iR~
	UCBITON(Pft1->FTflag2,FTF2HASDUPKEY);	//dupkey tbl search required//~v76iI~
	UCBITON(Pft2->FTflag2,FTF2HASDUPKEY);	//dupkey tbl search required//~v76iI~
    for (ii=0,pdupkt=Sdupkeyt;ii<Sdupkeytno;ii++,pdupkt++)         //~v76iI~
    {                                                              //~v76iI~
    	if (pdupkt->DKTkey==Pkey && pdupkt->DKTshift==Pshift)      //~v76iI~
        	break;                                                 //~v76iI~
    }                                                              //~v76iI~
    if (ii==Sdupkeytno)	//not found                                //~v76iR~
    {                                                              //~v76iI~
    	if (Sdupkeytno==MAXDKT)		//overflow                     //~v76iR~
        {                                                          //~v76iI~
			uerrmsg("Duplicated key table overflow(>%d)",          //~v76iI~
		    		"重複割り当てのキーが多すぎます(>%d)",         //~v76iI~
					MAXDKT);                                       //~v76iI~
            return 4;                                              //~v76iI~
        }                                                          //~v76iI~
		pdupkt->DKTkey=Pkey;                                       //~v76iI~
		pdupkt->DKTshift=Pshift;                                   //~v76iI~
        Sdupkeytno++;	//for next addrition                       //~v76iI~
        UTRACEP("%s:Sdupkeyno=%d,Pkey=%04x=%s,Pindex=%d,Pshift=%x,func=%s & %s\n",UTT,Sdupkeytno,Pkey,//~vb50R~
				kbdgetname(Pkey,Pshift),Pindex,Pshift,Pft1->FTnamee,Pft2->FTnamee);//~vb50I~
    }                                                              //~v76iI~
    for (ii=0,ppft=pdupkt->DKTpft,duperrsw=0;ii<UCWMAXTYPE;ii++,ppft++)//~v76iR~
    {                                                              //~v76iI~
        pft=*ppft;                                                 //~v76iI~
		if (Pft1->FTfunc[ii])	//function assigned to this key on the screen type//~v76iI~
        {                                                          //~v76iI~
        	if (!pft)			//not assigned foth the scr type   //~v76iR~
                pft=                                               //~v77nI~
				*ppft=Pft1;                                        //~v76iR~
            else                                                   //~v76iI~
        	if (pft!=Pft1)		//already registered(case of 3 duplication)//~v76iI~
            {                                                      //~v76iI~
            	duperrsw=1;                                        //~v76iI~
                pftdup1=pft;                                       //~v76iI~
                pftdup2=Pft1;                                      //~v76iI~
            }                                                      //~v76iI~
        }                                                          //~v76iI~
		if (Pft2->FTfunc[ii])	//function assigned to this key on the screen type//~v76iI~
        {                                                          //~v76iI~
        	if (!pft)		//other function assigned already      //~v76iR~
				*ppft=Pft2;                                        //~v76iR~
            else                                                   //~v76iI~
        	if (pft!=Pft2)		//already registered(case of 3 duplication)//~v76iI~
            {                                                      //~v76iI~
            	duperrsw=1;                                        //~v76iI~
                pftdup1=pft;                                       //~v76iI~
                pftdup2=Pft2;                                      //~v76iI~
            }                                                      //~v76iI~
        }                                                          //~v76iI~
    }//screen type                                                 //~v76iI~
    if (!duperrsw)                                                 //~v76iI~
        return 0;	//whole same key assignment                    //~v76iI~
	keyname=kbdgetname(Pkey,Pshift);
//  if (UCBITCHK(Gscrstatus,GSCRSDBCS))                            //~v79zR~
    if (XE_ISDBCSKONJ())	//Japanese                             //~v79zR~
	{
//  	pc1=Pft1->FTnamej;                                         //~v76iR~
//  	pc2=Pft2->FTnamej;                                         //~v76iR~
		pc1=pftdup1->FTnamej;                                      //~v76iI~
		pc2=pftdup2->FTnamej;                                      //~v76iI~
	}
	else
	{
//  	pc1=Pft1->FTnamee;                                         //~v76iR~
//  	pc2=Pft2->FTnamee;                                         //~v76iR~
		pc1=pftdup1->FTnamee;                                      //~v76iI~
		pc2=pftdup2->FTnamee;                                      //~v76iI~
	}
//  if (intersecterrsw)                                            //~v76iR~
//    uerrmsg("%s is duplicated for %s and %s(intersected)",       //~v76iR~
//            "キー %s は %s と %s と重複指定されています(３角関係)",//~v76iR~
//            keyname,pc1,pc2);                                    //~v76iR~
//  else                                                           //~v76iR~
	uerrmsg("%s is duplicated for %s and %s",
		    "キー %s は %s と %s と 重複指定されています",
			keyname,pc1,pc2);
	UCBITON(Pft2->FTkflag[Pindex],FTDUPER);                     //~5222R~
	ubell();
	return 1;
}//funcduperr
//**************************************************               //~v76iI~
//*dupkey tbl search                                               //~v76iI~
//*retrn :0 dup count                                              //~v76iI~
//**************************************************               //~v76iI~
int funcdupktsrch(int Popt,/*KEYTBL*/void *Ppkt,int Pmodidx,FUNCTBL **Pppft)//~v76iR~
{                                                                  //~v76iI~
    int ii,entno,kk,shiftid;                                       //~v76iR~
    USHORT key;                                                    //~v76iI~
    KEYTBL *pkt;                                                   //~v76iR~
	PDUPKEYT pdupkt;                                               //~v76iI~
    FUNCTBL *pft,**ppft;                                           //~v76iI~
//**********************                                           //~v76iI~
	memset(Pppft,0,UCWMAXTYPE*sizeof(FUNCTBL*));                   //~v76iR~
	pkt=(KEYTBL*)Ppkt;                                             //~v76iR~
#ifndef KKK                                                        //~vb50I~
    if (Popt & FDKSO_FTSHIFT)   //S+A,S+C                          //~vb50I~
    	shiftid=FTSHIFT;                                           //~vb50I~
    else                                                           //~vb50I~
#endif                                                             //~vb50I~
	if (Pmodidx==1       //Shift+                                  //~v76iI~
    &&  UCBITCHK(pkt->KTflag[1],KTSHIFTDUP))                       //~v76iR~
    	shiftid=FTSHIFT;                                           //~v76iI~
    else                                                           //~v76iI~
        shiftid=0;                                                 //~v76iI~
    key=pkt->KTkey[Pmodidx];                                       //~v76iI~
    for (ii=0,pdupkt=Sdupkeyt;ii<Sdupkeytno;ii++,pdupkt++)         //~v76iI~
    {                                                              //~v76iI~
    	if (pdupkt->DKTkey==key && pdupkt->DKTshift==shiftid)      //~v76iR~
        	break;                                                 //~v76iI~
    }                                                              //~v76iI~
    if (ii==Sdupkeytno)                                            //~v76iI~
    	return 0;                                                  //~v76iI~
    for (ii=0,entno=0;ii<UCWMAXTYPE;ii++)                          //~v76iR~
    {                                                              //~v76iI~
        pft=pdupkt->DKTpft[ii];                                    //~v76iR~
        if (!pft)                                                  //~v76iI~
        	continue;                                              //~v76iI~
        for (kk=0,ppft=Pppft;kk<entno;kk++,ppft++)	//avoid duplicated report//~v76iR~
        	if (*ppft==pft)                                        //~v76iI~
            	break;                                             //~v76iI~
        if (kk==entno)	//new                                      //~v76iR~
        {                                                          //~v76iI~
            *ppft=pft;                                             //~v76iR~
            entno++;                                               //~v76iR~
        }                                                          //~v76iI~
    }//screen type                                                 //~v76iI~
	return entno;                                                  //~v76iR~
}//funcdupktsrch                                                   //~v76iI~
//**************************************************            //~5105I~
//*dup cmd word err msg                                         //~5105I~
//*parm1 :func tbl addr1                                        //~5105I~
//*parm2 :func tbl addr2                                        //~5105I~
//*parm3 :0:command dup,1:abribiate dup                         //~5105I~
//*retrn :1                                                     //~5105I~
//**************************************************            //~5105I~
int cmdduperr(FUNCTBL *Pft1,FUNCTBL *Pft2,int Palias)           //~5105I~
{                                                               //~5105I~
	UCHAR *pc1,*pc2,*word;                                      //~5105I~
//**********************                                        //~5105I~
    if (Palias)         //alias                                 //~5105R~
        word=Pft1->FTcmda;                                      //~5105R~
    else                                                        //~5105I~
        word=Pft1->FTcmd;                                       //~5105R~
//  if (UCBITCHK(Gscrstatus,GSCRSDBCS))                            //~v79zR~
    if (XE_ISDBCSKONJ())	//Japanese                             //~v79zR~
	{                                                           //~5105I~
		pc1=Pft1->FTnamej;                                      //~5105I~
		pc2=Pft2->FTnamej;                                      //~5105I~
	}                                                           //~5105I~
	else                                                        //~5105I~
	{                                                           //~5105I~
		pc1=Pft1->FTnamee;                                      //~5105I~
		pc2=Pft2->FTnamee;                                      //~5105I~
	}                                                           //~5105I~
	uerrmsg("command verb %s is duplicated for %s and %s",      //~5105I~
		    "コマンド %s は %s と %s と 重複しています",        //~5105I~
			word,pc1,pc2);                                      //~5105I~
	ubell();                                                    //~5105I~
	return 1;                                                   //~5105I~
}//cmdduperr                                                       //~v07aR~
                                                                //~5105I~
//**************************************************            //~5114I~
//* functerm                                                    //~5114I~
//**************************************************            //~5114I~
void functerm(void)                                              //~5114I~
{                                                               //~5114I~
//***********************                                       //~5114I~
	funcfreecmdstack();                                         //~5114I~
    functterm();                                                //~5429I~
	funcaliasreset();                                              //~v67CI~
    ufree(Gvalidchartbl);                                          //~v09PR~
    Gvalidchartbl=0;                                               //~v09PI~
    ufree(Gpodelmt);	//uparse2 parm                             //~v08lR~
    ufree(Sworkfthdr.WFTHpwft);                                    //~v0ioI~
	return;
}//functerm                                                     //~5114I~
                                                                //~5114I~
//**************************************************
//*call key function
//*parm :keytype: 0:extended key, 1:SBCS, 2:DBCS
//*      key    : input key
//*					keytype=0: xx00(xx:scancode)
//*					keytype=1: xxyy(xx:charcode,yy:scancode)
//*					keytype=2: xxyy(xx:DBCS first byte,yy:DBCS second byte)
//*					keytype=3: client screen draw
//*rc   :rc from key function(-1 for quit)
//**************************************************
int funccall(int Pkeytype,UCHAR *Pkey,PUCLIENTWE Ppcw)
{
static 	FTFUNC *func_draw[UCWMAXTYPE]={func_draw_pan,func_draw_file,//~v020R~
										func_draw_dir};	//function addr//~v020I~
//**********************
	int i;
	int rc=0;
	int code;
	FTFUNC *pfunc=0;
    FUNCTBL *pft=0;	//FUNKTBL ptr                                  //~vaf9R~
    FUNCTBL *pfto;                                                 //~va3ZI~
//  char wkbuff[MAXCOLUMN+1];                                      //~v0imR~//~va04R~
    char wkbuff[MAXPARMSZ+1];                                      //~va04I~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
    struct timeb tmb;                                              //~v560I~
#endif                                                             //~v560I~
	int shifttblsw=0,jj;                                           //~v691I~
    USHORT uskey=0;                                                //~v691I~
static int Sccfuncmsgctr=0;                                        //~v75zI~
	PDUPKEYT pdupkt;                                               //~v76iI~
#ifdef UTF8SUPPH                                                   //~va1rI~
	int opt;                                                       //~va1rI~
#endif                                                             //~va1rI~
//*********************

    if (Ppcw->UCWsplitid==Gscrcurclient)//not draw other client case//~v012R~
    {			//protect other client rcsr destroy             //~v012R~
	Ppcw->UCWrcsrx	=Gcsrposx-Ppcw->UCWorgx;	//relative pos-x//~5128R~
	Ppcw->UCWrcsry	=Gcsrposy-Ppcw->UCWorgy;	//relative pos-x//~5128R~
    }                                                           //~v012R~
    if (Ppcw->UCWrcsrx<0)                                          //~v0jqI~
    	Ppcw->UCWrcsrx=0;                                          //~v0jqI~
    if (Ppcw->UCWrcsry<0)                                          //~v0jqI~
    	Ppcw->UCWrcsry=0;                                          //~v0jqI~
	if (Ppcw->UCWrcsrx>=Gscrwidth)                                 //~v0jqI~
		Ppcw->UCWrcsrx=Gscrwidth;                                  //~v0jqI~
	if (Ppcw->UCWrcsry>=Gscrheight)                                //~v0jqR~
		Ppcw->UCWrcsry=Gscrheight;                                 //~v0jqR~
	Ppcw->UCWkeytype=(UCHAR)Pkeytype;	//key type
    code=0;                                                        //~v691I~
	if (Pkey)				//parameter exist(not exist for type 3)
    {                                                              //~v691I~
		code=(int)*Pkey;
      if (Pkeytype==UCWKTSBCS)                                     //~vanaI~
        uskey=(USHORT)((code)|(*(Pkey+1)<<8));	//uskey:scan+char  for dupkeychk//~vanaI~
      else                                      //*Pkey:scancode   //~vanaI~
        uskey=(USHORT)((code<<8)|*(Pkey+1));                       //~v691R~
        UTRACEP("funccall uskey=%04x\n",uskey);                    //~vanaR~
    }                                                              //~v691I~
	switch (Pkeytype)
	{
	case UCWKTEXTKEY:                                           //~5225R~
		if (Ppcw->UCWkeyshift&(KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT)
		&&  (pft=sekftrt[code],pft))	//shift key func tbl
        {                                                          //~v691I~
			pfunc=pft->FTfunc[Ppcw->UCWtype];
            shifttblsw=FTSHIFT;                                    //~v691I~
        }                                                          //~v691I~
		else
			if (pft=ekftrt[code],pft)
				pfunc=pft->FTfunc[Ppcw->UCWtype];
		break;
	case UCWKTSBCS:                                             //~5225R~
    	pft=0;							//for the case func_char//~5504I~
		*Ppcw->UCWkeydata=*Pkey;		//key data SBCS
		if (Ppcw->UCWkeyshift&(KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT)
		&&  (pft=sckftrt[code],pft))	//shift key func tbl
        {                                                          //~v691I~
			pfunc=pft->FTfunc[Ppcw->UCWtype];
            shifttblsw=FTSHIFT;                                    //~v691I~
        }                                                          //~v691I~
		else						//not on shift func key tbk
			if (ckftrt[code].ckscan[0])	//func key
			{
				for (i=0;i<CFTMAXSCAN;i++)
				{
					if (*(Pkey+1)==ckftrt[code].ckscan[i])
					{
						pft=ckftrt[code].ckpft[i];
						break;
					}//function asigned
				}//i:scancode
//				if (i<CFTMAXSCAN)                                  //~v096R~
  				if (i<CFTMAXSCAN && pft)    //scan code !=0        //~v096I~
                {                                                  //~v55kI~
                  if (ckftrt[code].ckflag[i] & FTCTLC              //~v55kI~
#ifdef WXEXXE                                                      //~v75AI~
				  &&  !(Gwxestat & GWXES_MOUSECAPPASTE)		//C&P by mouse//~v75AI~
#endif                                                             //~v75AI~
                  &&  UCBITCHK(Gopt5,GOPT5NOCTLCHARFUNC))          //~v55kI~
                  {                                                //~v75zI~
					pfunc=func_char;                               //~v55kI~
                    if (!Sccfuncmsgctr)                            //~v75zI~
                    {                                              //~v75zI~
                    	Sccfuncmsgctr=1;                           //~v75zI~
                        uerrmsg("Warning(only once):Now CCFUNC option is OFF.(Ctrl+x is treated as char input)",//~v75zI~
                                "警告(一度だけ):現在 CCFUNCオプションはOFFです(Ctrl+xは文字入力扱いです)。");//~v75zR~
                    }                                              //~v75zI~
                  }                                                //~v75zI~
                  else                                             //~v55kI~
					pfunc=pft->FTfunc[Ppcw->UCWtype];
                }                                                  //~v55kI~
				else
					pfunc=func_char;
			}
			else
				pfunc=func_char;
//  	if (pfunc==func_char)                                      //~v0a2R~
//      	if (Gvalidchartbl[(int)*Pkey])                         //~v0a2R~
//          {                                                      //~v0a2R~
//             funcinhibitkey(*Pkey);                              //~v0a2R~
//  			uerrmsg("Char(0x%02X) is input prohibitted",       //~v09PR~
//  				    "入力禁止文字(0x%02x)",                    //~v09PR~
//  					(int)*Pkey);                               //~v09PR~
//  			ubell();                                           //~v0a2R~
//          	return 4;                                          //~v0a2R~
//  		}                                                      //~v0a2R~
		break;
	case UCWKTDBCS:                                             //~5225R~
    	pft=0;                                                  //~5228I~
#ifdef UTF8SUPPH                                                   //~va1cR~
		memcpy(Ppcw->UCWkeydata,Pkey,MAX_MBCSLENLC);               //~va1cR~
#else                                                              //~va1cR~
		*Ppcw->UCWkeydata=*Pkey;			//key data DBCS
		*(Ppcw->UCWkeydata+1)=*(Pkey+1);	//key data DBCS
#endif                                                             //~va1cR~
		pfunc=func_char;
		break;
	case UCWKTSCRDRAW:										//client draw//~5225R~
    	pft=0;                                                  //~5228I~
		pfunc=func_draw[Ppcw->UCWtype];
		break;
	case UCWKTCMD:										//client draw//~5225R~
    	pft=0;                                                  //~5228I~
		pfunc=func_cmd;
		break;
#ifdef LNX                                                         //~v53mI~
  #ifndef XXE                                                      //~va90I~
	case UCWKTMOUSE:									//client draw//~v53mI~
    	mousel_funcsrch(Ppcw,Pkey,&pft,&pfunc);                    //~v53mI~
		break;                                                     //~v53mI~
  #endif //XXE                                                     //~va90I~
#endif                                                             //~v53mI~
	case UCWKTFUNCID:									//client draw//~v768I~
		pft=functblsrch((int)Pkey[2]);                             //~v768I~
        if (pft)                                                   //~v768I~
			pfunc=pft->FTfunc[Ppcw->UCWtype];                      //~v768I~
		break;                                                     //~v768I~
#ifdef FTPSUPP                                                     //~v78ZI~
	case UCWKT3270KBD:  								//client draw//~v78ZI~
		*Ppcw->UCWkeydata=Pkey[2];                                 //~v78ZI~
    	pft=0;                                                     //~v78ZI~
		pfunc=func_3270kbd;                                        //~v78ZR~
		break;                                                     //~v78ZI~
#endif                                                             //~v78ZI~
	}
                                                                   //~v53mI~
//dup key assigned                                                 //~v07aI~
	pfto=pft;                                                      //~va3ZI~
    if (pft && !pfunc) 	//not defined on the screen type           //~v07aI~
    {                                                              //~v691I~
//        if (pft->FTdupnext)                                      //~v76iR~
//        {                                                        //~v76iR~
//            if (pfunc=pft->FTdupnext->FTfunc[Ppcw->UCWtype],pfunc)//~v76iR~
//            {                                                    //~v76iR~
//                pft=pft->FTdupnext;                              //~v76iR~
//                for (jj=0;jj<FTMAXKEY;jj++)                      //~v76iR~
//                    if (pft->FTkey[jj]==uskey                    //~v76iR~
//                    &&  (pft->FTkflag[jj]&FTSHIFT)==shifttblsw)  //~v76iR~
//                        break;                                   //~v76iR~
//                if (jj==FTMAXKEY)   //partial duplicated entry,but the key is not duplicated//~v76iR~
//                    pfunc=0;                                     //~v76iR~
//            }                                                    //~v76iR~
//        }                                                        //~v76iR~
        if (UCBITCHK(pft->FTflag2,FTF2HASDUPKEY))   //dupkey tbl search required//~v76iI~
        {                                                          //~v76iI~
            pfunc=0;                                               //~v76iI~
            for (jj=0,pdupkt=Sdupkeyt;jj<Sdupkeytno;jj++,pdupkt++) //~v76iI~
            {                                                      //~v76iI~
                if (pdupkt->DKTkey==uskey && pdupkt->DKTshift==shifttblsw)//~v76iI~
                {                                                  //~v76iI~
                    pft=pdupkt->DKTpft[Ppcw->UCWtype];             //~v76iI~
                    if (pft)                                       //~v76iI~
						pfunc=pft->FTfunc[Ppcw->UCWtype];          //~v76iI~
                    break;                                         //~v76iI~
                }                                                  //~v76iI~
            }                                                      //~v76iI~
        }                                                          //~v76iI~
    }                                                              //~v691I~
    if (pft && !UCBITCHK(pft->FTflag,FTFCSRKEY)) //not char     //~5504I~
    {                                                              //~v53mI~
//  	if (getfldinput(Ppcw,CMDLINENO,0,wkbuff))	//input on cmdline//~v0imR~
#ifdef UTF8SUPPH                                                   //~va00I~
//    	if (BYUTF8_funcgetlongcmd(Ppcw,wkbuff))	//input on cmdline //~va00R~//~va1rR~
        if (pft->FTfuncid==FUNCID_EXECNL)                          //~va1rR~
            opt=FGLC8O_SETCT;	//save lc/ct                       //~va1rI~
        else                                                       //~va1rI~
        	opt=0;                                                 //~va1rI~
      	if (funcgetlongcmd_byutf8(opt,Ppcw,wkbuff))	//input on cmdline//~va1rR~
#else                                                              //~va00I~
    	if (funcgetlongcmd(Ppcw,wkbuff))	//input on cmdline     //~v0imI~
#endif                                                             //~va00I~
        {                                                       //~5527I~
//      	if (pft->FTfuncid!=FUNCID_BS                        //~v035R~
//      	&&  pft->FTfuncid!=FUNCID_DEL)                      //~v035R~
//    			setflddata(Ppcw,CMDLINENO,0,wkbuff);//drop pre space//~v035R~
			Ppcw->UCWparm=wkbuff;				//set operand   //~5504M~
		}                                                       //~5527I~
		else                                                    //~5504M~
			Ppcw->UCWparm=0;                                    //~5504M~
    }//not char                                                    //~v53mI~
//  Ppcw->UCWpfunct=Gproclastpft=pft;                              //~v48gR~
    if (pft)                                                       //~v48gI~
		Gproclastpft=pft;	//chk at xe.c                          //~v48gI~
    Ppcw->UCWpfunct=pft;                                           //~v48gI~
	Ppcw->UCWopdno=0;     	//cmd operand number               //~v08lI~//~v08lI~
	Ppcw->UCWopddelmt=0; 	//cmd operand delm table           //~v08lI~//~v08lI~
	Ppcw->UCWopdpot=0;      //operand parse out tbl            //~v08lI~//~v08lI~
//UTRACEP("kbdctr=%d,sleeptime=%d\n",Gkbdinpctr,Stmbsleep.time);   //~v562R~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
    if (Stmbsleep.time)                                            //~v560I~
    {                                                              //~v560I~
//if (pft)                                                         //~v562R~
//UTRACED("pft",pft,sizeof(FUNCTBL));                              //~v562R~
    	ftime(&tmb);                                               //~v560I~
//UTRACEP("time comp curr:%x-%x,max=%x-%x\n",tmb.time,tmb.millitm,Stmbsleep.time,Stmbsleep.millitm);//~v562R~
        if (DWORD_COMP(tmb.time,tmb.millitm,Stmbsleep.time,Stmbsleep.millitm)<0)//~v560R~
        {                                                          //~v562I~
        	if (!pfunc                                             //~v560I~
            ||  (pfunc!=func_reset && Pkeytype!=UCWKTSCRDRAW))										//client draw//~v560R~
            {                                                      //~v561I~
    #ifdef WINCON                                                  //~v562R~
        		funcsleepsettimeup(Ppcw,0);    //ignore then next kbdpeek//~v562R~
    #endif                                                         //~v561M~
            	return 0;	//ignore input in sleeping time        //~v560I~
            }                                                      //~v561I~
        }                                                          //~v562I~
    #ifdef WINCON   //pass "sleep 0" to func_sleep                 //~v562I~
        else                                                       //~v562I~
        {                                                          //~v562I~
//UTRACEP("timeup\n");                                             //~v562R~
        	funcsleepsettimeup(Ppcw,0);    //timeup process        //~v562I~
           	return 0;	//ignore this input                        //~v562I~
        }                                                          //~v562I~
    #endif                                                         //~v562M~
//UTRACEP("continue\n");                                           //~v562R~
    }                                                              //~v560I~
#endif                                                             //~v560I~
                                                                   //~vbi3I~
	if (pfunc)
    {                                                              //~vbi3I~
		rc=pfunc(Ppcw);
		if (Gotherstatus & GOTHERS_CHLPOPUP)//CommandHistoryList request popup at return//~vbi3R~
        {                                                          //~vbi3I~
			Gotherstatus&=(UINT)(~GOTHERS_CHLPOPUP);//CommandHistoryList request popup at return//~vbi3R~
    		func_end_file(Ppcw);	//do not access Ppcw it is freeed//~vbi3I~
        }                                                          //~vbi3I~
    }                                                              //~vbi3I~
	else
    {                                                           //~5521I~
//      if (pft)	//defined,pannel unmatch                    //~5521I~//~va3ZR~
        if (pfto)	//defined,pannel unmatch                       //~va3ZR~
			funcinvalidkey(Ppcw);                                  //~v07aI~
		else        //not defined                               //~5521I~
			uerrmsg("Undefined key combination",                //~5521I~
				    "未定義キー");                              //~5521I~
		rc=4;
    }                                                           //~5521I~
	if (rc ==-1)
		return -1;
	if (rc)
      if (!pft || !UCBITCHK(pft->FTflag,FTFCSRKEY)) //not csr key  //~v162R~
       if (!UCBITCHK(Gprocstatus,GPROCSEXECMDFILE))                //~v60wI~
		ubell();
	return rc;
}//funccall

//**************************************************               //~v0ihI~
//*search func tbl by key                                          //~v0ihI~
//*parm1 :key type                                                 //~v0ihI~
//*parm2 :key value(USHORT)                                        //~v0ihI~
//*				keytype=0: 00xx(xx:scancode)                       //~v0ihI~
//*				keytype=1: yyxx(xx:charcode,yy:scancode)           //~v0ihI~
//*parm3 :shift table search option for shift value is same as no shift//~v0ihI~
//*rc   :funct addr                                                //~v0ihI~
//**************************************************               //~v0ihI~
FUNCTBL *funcftsrch(int Pkeytype,USHORT Pkey,int Pshift)           //~v0ihI~
{                                                                  //~v0ihI~
    FUNCTBL *pft;	//FUNKTBL ptr                                  //~v0ihI~
    int code,scan,ii;                                              //~v0ihI~
//*********************                                            //~v0ihI~
	code=Pkey&255;	//scan code for ext key,charcode for char key  //~v0ihI~
	if (Pkeytype==UCWKTEXTKEY)                                     //~v0ihI~
		if (Pshift)                                                //~v0ihI~
			pft=sekftrt[code];	//shift key func tbl               //~v0ihI~
        else                                                       //~v0ihI~
			pft=ekftrt[code];                                      //~v0ihI~
	else                                                           //~v0ihI~
		if (Pshift)                                                //~v0ihI~
			pft=sckftrt[code];	//shift key func tbl               //~v0ihI~
        else                                                       //~v0ihI~
		{                                                          //~v0ihI~
        	pft=0;                                                 //~v0ihI~
			scan=Pkey>>8;	//scan code cahr key                   //~v0ihI~
			if (ckftrt[code].ckscan[0])	//func key                 //~v0ihI~
			{                                                      //~v0ihI~
				for (ii=0;ii<CFTMAXSCAN;ii++)                      //~v0ihI~
				{                                                  //~v0ihI~
					if (scan==ckftrt[code].ckscan[ii])             //~v0ihI~
					{                                              //~v0ihI~
						pft=ckftrt[code].ckpft[ii];                //~v0ihI~
						break;                                     //~v0ihI~
					}//function asigned                            //~v0ihI~
				}//ii:scancode                                     //~v0ihI~
			}                                                      //~v0ihI~
		}//char w/o shift                                          //~v0ihI~
	return pft;                                                    //~v0ihI~
}//funcftsrch                                                      //~v0ihI~
#ifdef UTF8SUPPH                                                   //~va1CR~
//**************************************************************** //~va1CR~
// save 1st operand localecode and codetype for errmsg             //~va1CR~
//**************************************************************** //~va1CR~
int funcsaveopdcodetype(int Popt,PUCLIENTWE Ppcw,char *Popd)       //~va1CR~
{                                                                  //~va1CR~
    char *pu8;                                                     //~va1CR~
    int lenu8,lenlc;                                               //~va1CR~
//  char wkfpathlc[_MAX_PATH*UTF8_F2LMAXRATE];                     //~va1CR~//~vav9R~
//  char wkfpathct[_MAX_PATH*UTF8_F2LMAXRATE];                     //~va1CR~//~vav9R~
    char wkfpathlc[_MAX_PATHF2L];                                  //~vav9I~
    char wkfpathct[_MAX_PATHF2L];                                  //~vav9I~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
    int lendd=0;                                                   //~vau7I~
    char wkdddata[_MAX_PATH*2];                                    //~vau7I~
    char wkdddbcs[_MAX_PATH*2];                                    //~vau7I~
    char wkddct[_MAX_PATH*2];                                      //~vau7I~
#endif                                                             //~vau7I~
//*****************                                                //~va1CR~
	funcsaveopd2codetype(0,Ppcw);                                  //~vawtM~
    pu8=Popd;                                                      //~va1CR~
//  lenu8=strlen(pu8);                                             //~va1CR~//~vb30R~
    lenu8=(int)strlen(pu8);                                        //~vb30I~
    if (!pan300stackchkcmdbuff(0,pu8))  //locale name remains on cmd buff//~va1CR~
        return 0;                                                  //~va1CR~
    else                                                           //~va1CR~
    {                                                              //~va1CR~
//      lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc));//~vau7R~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
        lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),wkdddata,wkdddbcs,wkddct,sizeof(wkdddata),&lendd);//~vau7I~
#else                                                              //~vau7I~
        lenlc=pan300stacksetctfromcmdbuffsub(0,pu8,wkfpathlc,wkfpathct,sizeof(wkfpathlc),NULL,NULL,NULL,0,NULL);//~vau7I~
#endif                                                             //~vau7I~
        if (!lenlc)                                                //~va1CR~
            return 0;                                              //~va1CR~
    }                                                              //~va1CR~
//  xeutf_savelcctforerrmsg(Ppcw->UCWsplitid,pu8,lenu8,wkfpathlc,wkfpathct,lenlc);//~vau7R~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
  if (lendd)                                                       //~vau7I~
//  xeutf_savelcctforerrmsg(Ppcw->UCWsplitid|XEUTFSLCFEO_DDFMT,pu8,lenu8,wkfpathlc,wkdddbcs,wkddct,lendd);//~vau7I~//~vavRR~
    xeutf_savelcctforerrmsg(Ppcw->UCWsplitid|XEUTFSLCFEO_DDFMT,pu8,lenu8,wkdddata,wkdddbcs,wkddct,lendd);//~vavRI~
  else                                                             //~vau7I~
#endif                                                             //~vau7I~
    xeutf_savelcctforerrmsg(Ppcw->UCWsplitid,pu8,lenu8,wkfpathlc,NULL/*dbcs*/,wkfpathct,lenlc);//~vau7I~
    return 1;                                                      //~va1CR~
}//funcsaveopdcodetype                                             //~vau7R~
//**************************************************************** //~vawtI~
// save 2nd operand localecode and codetype for errmsg             //~vawtI~
//**************************************************************** //~vawtI~
int funcsaveopd2codetype(int Popt,PUCLIENTWE Ppcw)                 //~vawtR~
{                                                                  //~vawtI~
    char *pct,*plc,*pu8;                                           //~vawtI~
    int lenu8,lenlc,posopd,opdpos,opt,ii;                          //~vawtR~
//*****************                                                //~vawtI~
    for (pu8=Ppcw->UCWopdpot,ii=0,posopd=0;ii<Ppcw->UCWopdno;pu8+=strlen(pu8)+1,ii++)//~vawtI~
    {                                                              //~vawtI~
        if (*pu8=='/' || *pu8=='-')                                //~vawtI~
			continue;                                              //~vawtI~
        if (++posopd>1)                                            //~vawtI~
        	break;                                                 //~vawtI~
    }                                                              //~vawtI~
    if (posopd!=2)                                                 //~vawtI~
    	return 4;                                                  //~vawtR~
    opdpos=ii; //opdno starts from 0                               //~vawtR~
	if (funcgetOpdLCCT(0,Ppcw,opdpos,&plc,&pct,&lenlc))            //~vawtR~
    	return 4;                                                  //~vawtI~
//  if (!memchr(pct,XEUTFCT_UTF8,lenlc))                           //~vawtR~//~vb30R~
    if (!memchr(pct,XEUTFCT_UTF8,(size_t)lenlc))                   //~vb30I~
    	return 4;                                                  //~vawtI~
//  lenu8=strlen(pu8);                                             //~vawtI~//~vb30R~
    lenu8=(int)strlen(pu8);                                        //~vb30I~
    UTRACED("utf8",pu8,lenu8);                                     //~vawtI~
    UTRACED("lc",plc,lenlc);                                       //~vawtI~
    UTRACED("ct",pct,lenlc);                                       //~vawtI~
	opt=XEUTFSLCFEO_WORD2|Ppcw->UCWsplitid;                        //~vawtI~
    xeutf_savelcctforerrmsg(opt,pu8,lenu8,plc,NULL/*dbcs*/,pct,lenlc);//~vawtR~
    return 0;                                                      //~vawtI~
}//funcsaveopd2codetype                                            //~vawtI~
#endif                                                             //~va1CR~
//**************************************************               //~vavQI~
//*parse cmd by lc, pos is index to codetbl                        //~vavQI~//~vavRR~
//*parm client work element                                        //~vavQI~
//*rc   :ok or err                                                 //~vavQI~
//**************************************************               //~vavQI~
int funcuparse2_LC(int Popt,PUCLIENTWE Ppcw,char *Pcmdu8,int Pwordno,char *Pcmdlc,char *Pcmdct,int Pbuffsz)//~vavQR~
{                                                                  //~vavQI~
	UCHAR *wkppot;                                                 //~vavQI~
    PUPODELMTBL pupod0;                                            //~vavQI~
    int wordno,rc,len;                                             //~vavQR~
//************************************                             //~vavQI~
	UTRACED("u8cmd",Pcmdu8,(int)strlen(Pcmdu8));                        //~vavQI~//~vb30R~
	UTRACED("Gcmdbuffu8",Gcmdbuffu8,(int)strlen(Gcmdbuffu8));           //~vavQR~//~vb30R~
	UTRACED("Gcmdbufflc",Gcmdbufflc,(int)strlen(Gcmdbufflc));           //~vavQI~//~vb30R~
	UTRACED("Gcmdbuffct",Gcmdbuffct,(int)strlen(Gcmdbufflc));           //~vavQI~//~vb30R~
	Ppcw->UCWcmddelmtLC=0;                                         //~vavQR~
    if (strcmp(Pcmdu8,Gcmdbuffu8))                                 //~vavQR~
    	return 4;                                                  //~vavQI~
    pupod0=(PUPODELMTBL)Gpodelmt+(Pwordno+1);	//may be availabe spece(MAXPARMSZ*UPODELMTBSZ)//~vavQI~
	wkppot=Pcmdlc;                                                 //~vavQR~
	if ((rc=uparse2(Gcmdbufflc,&pupod0,&wkppot,&wordno,            //~vavQR~
    		UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,",;"))>=4)       //~vavQI~
        return 4;                                                  //~vavQR~
    if (wordno!=Pwordno)//lc/ct is from cmd verb                   //~vavQR~
        return 4;                                                  //~vavQI~
    len=min(Pbuffsz,(int)strlen(Gcmdbufflc));                      //~vavQR~
//  memcpy(Pcmdlc,Gcmdbufflc,len);                                 //~vavQR~//~vb30R~
    memcpy(Pcmdlc,Gcmdbufflc,(size_t)len);                         //~vb30I~
//  memcpy(Pcmdct,Gcmdbuffct,len);                                 //~vavQI~//~vb30R~
    memcpy(Pcmdct,Gcmdbuffct,(size_t)len);                         //~vb30I~
   	Ppcw->UCWcmddelmtLC=pupod0;	//cmd operand delm table from cmd word//~vavQR~
    Ppcw->UCWcmdLC=Pcmdlc;	//cmd word                             //~vavQR~
    Ppcw->UCWcmdCT=Pcmdct;	    //from cmd word                    //~vavQR~
    Ppcw->UCWcmdLClen=len;                                         //~vavQI~
   return 0;                                                       //~vavQI~
}//funcuparse2_LC                                                  //~vavQI~
//**************************************************               //~vavQI~
//*get oerand lc/ct                                                //~vavQI~
//*opdno start from 0                                              //~vavQI~
//*rc   :ok or err                                                 //~vavQI~
//**************************************************               //~vavQI~
int funcgetOpdLCCT(int Popt,PUCLIENTWE Ppcw,int Popdno,char **Pplc,char **Ppct,int *Pplen)//~vavQR~
{                                                                  //~vavQI~
	UCHAR *plc;                                                    //~vavQR~
    PUPODELMTBL pupod;                                             //~vavQI~
    int delmoffs,delmoffs2,lenlc;                                  //~vavQR~
//************************************                             //~vavQI~
    if (Popdno<0||Popdno>=Ppcw->UCWopdno)                          //~vavQI~
    	return 4;                                                  //~vavQI~
   	pupod=(PUPODELMTBL)(Ppcw->UCWcmddelmtLC);                      //~vawtR~
    if (!pupod) //null when edit by cmdline parm                   //~vawtI~
    	return 4;                                                  //~vawtI~
   	pupod+=Popdno;                                                 //~vawtI~
	delmoffs=pupod->upodelmoffs;	//cmd verb end pos             //~vavQI~
   	plc=Ppcw->UCWcmdLC;                                            //~vavQR~
//  delmoffs+=strspn(plc+delmoffs," ,");                           //~vavQI~//~vb30R~
    delmoffs+=(int)strspn(plc+delmoffs," ,");                      //~vb30I~
	delmoffs2=(pupod+1)->upodelmoffs;	//cmd verb end pos         //~vavQR~
    lenlc=delmoffs2-delmoffs;                                      //~vavQI~
    if (lenlc<=0)                                                  //~vavQI~
    	return 4;                                                  //~vavQI~
   	*Pplc=Ppcw->UCWcmdLC+delmoffs;                                 //~vavQR~
   	*Ppct=Ppcw->UCWcmdCT+delmoffs;                                 //~vavQR~
    *Pplen=lenlc;                                                  //~vavQI~
   return 0;                                                       //~vavQI~
}//funcgetOpdLCCT                                                  //~vavQR~
//**************************************************
//*command string process
//*parm client work element
//*rc   :ok or err
//**************************************************
int func_cmd(PUCLIENTWE Ppcw)
{
static UCHAR Sspecialeditcmd[]=PGMID;                              //~v55cR~
//static UCHAR Sspecialrenumcmd[]={"RENUM"};                       //~v504R~
	UCHAR *pcop,*pcend,*pdelm;                                  //~v020R~
//  UCHAR wkbuff[MAXCOLUMN+1];                                     //~v0imR~//~va04R~
//  UCHAR wkpot[MAXCOLUMN+1];                                      //~v08lI~//~va04R~
    UCHAR wkbuff[MAXPARMSZ+1];                                     //~va04I~
    UCHAR wkpot[MAXPARMSZ+1];                                      //~va04I~
    UCHAR wkbuff_LC[MAXPARMSZ+1];                                  //~vavQI~
    UCHAR wkbuff_CT[MAXPARMSZ+1];                                  //~vavQI~
    UCHAR cmdverb[4];                                              //~v0iuI~
	UCHAR *wkppot;                                                 //~v08lI~
	FUNCTBL *pft;
	FUNCTBL *pftdup;                                               //~v09wI~
	FTFUNC *pfunc;
	int rc,wordno,ii;                                           //~v06pR~
    USHORT usoffs;                                                 //~v08lR~
	UINT cmdlen;
	UINT orgcmdlen;                                                //~v48kI~
	int otherdoscmdsw=0;                                           //~v48kI~
	int leavecmdlinesw;                                            //~v51yI~
    PUPODELMTBL pupod,pupod0;                                      //~v08lR~
    PALCT palct;    //alias cmd tbl                                //~v67CI~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
    int wordno2=0,/*cmdlen0,*/topcmdoffs=0;                                //~v55WR~//~vaa7R~//~vafdR~
    int atcmdopt;                                                  //~v55ZI~
    PUPODELMTBL pupodlast=NULL;                                         //~v55WR~//~vafdR~
#endif                                                             //~v55WI~
//  UCHAR *pcw1,*pcw2;                                             //~v13aR~
//************************************
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
    Spendatcmd=0;                                                  //~v55WI~
#endif                                                             //~v55WI~
	pupod0=Gpodelmt;                                               //~v08lI~
//  setflddata(Ppcw,CMDLINENO,0,Gcmdbuff);	//cmd set to buff      //~v0imR~
//  *Gcmdbuff=0;	//clear for err loop                           //~v0imR~
//  cmdlen=(UINT)getfldinput(Ppcw,CMDLINENO,0,wkbuff);			//re-retrieve//~v0imR~
 rc=             //4:split,8:no space to set splitid               //~v161I~
//  funcsetlongcmd(Ppcw,0,Gcmdbuff,0,0);//set to fld,no strlen,no output data len//~v0imR~//~va1rR~
    funcsetlongcmd(Ppcw,FSLCO_SETCT/*set lc/ct from Gcmdbufflc/ct*/,Gcmdbuff,0,0);//set to fld,no strlen,no output data len//~va1rI~
  if (rc==8)	//no spece set cmd on cmdline field                //~v161I~
  {                                                                //~v161I~
//      cmdlen=ustrnlen(Gcmdbuff,MAXCOLUMN);                       //~v161I~//~va04R~
//      cmdlen=ustrnlen(Gcmdbuff,MAXPARMSZ);                       //~va04I~//~vb31R~
        cmdlen=(UINT)ustrnlen(Gcmdbuff,MAXPARMSZ);                 //~vb31I~
        memcpy(wkbuff,Gcmdbuff,cmdlen);                            //~v161I~
        *(wkbuff+cmdlen)=0;                                        //~v161I~
	    *Gcmdbuff=0;	//clear for err loop                       //~v161I~
  }                                                                //~v161I~
  else                                                             //~v161I~
  {                                                                //~v161I~
    *Gcmdbuff=0;	//clear for err loop                           //~v0imI~
#ifdef UTF8SUPPH                                                   //~va00I~
    cmdlen=(UINT)BYUTF8_funcgetlongcmd(Ppcw,wkbuff);//get concatinated cmd with top space deleted//~va00R~
#else                                                              //~va00I~
    cmdlen=(UINT)funcgetlongcmd(Ppcw,wkbuff);//get concatinated cmd with top space deleted//~v0imR~
#endif                                                             //~va00I~
    if (!cmdlen)                                                   //~v67DI~
    	return 0;                                                  //~v67DI~
  }                                                                //~v161I~
	UTRACEP("func_cmd Ppcw=%p\n",Ppcw);                     //~v035R~//+vbi3R~
	UTRACED("func_cmd",wkbuff,(int)cmdlen);                        //+vbi3I~
                                                                //~v035I~
    if (*wkbuff=='=')           //menu call                     //~5504I~
    	return callmenu(Ppcw,wkbuff+1);                         //~5504I~
    if (*wkbuff=='>')           //dos command                   //~v020I~
    {                                                           //~v020I~
    	if (*(wkbuff+1)!=',' && *(wkbuff+1)!=' ')               //~v020I~
        {                                                       //~v020I~
        	memmove(wkbuff+2,wkbuff+1,cmdlen);                  //~v020I~
            *(wkbuff+1)=' ';	//insert space after '>'        //~v020R~
		}                                                       //~v020I~
    }                                                           //~v020I~
//multiple cmd process(drop text after ";")                     //~v06pI~
//  if (pcend=strpbrk(wkbuff,";"),pcend)	//search ";"        //~v06pR~
//  	*pcend=0;						//cut current cmd       //~v06pR~
//  if ((rc=uparse2(wkbuff,&pupod,&wordno,0,";"))>=4)              //~v08lR~
//    if (pcw1=strpbrk(wkbuff,";"),pcw1)  //search ";"             //~v13aR~
//    {                                                            //~v13aR~
//        for (pcw2=pcw1,pcw1--;pcw1>=wkbuff;pcw1--)              //cut current cmd//~v13aR~
//            if (*pcw1!=' ')                                      //~v13aR~
//                break;                                           //~v13aR~
//        pcw1++;                                                  //~v13aR~
//        if (pcw1!=pcw2)                                          //~v13aR~
//            strcpy(pcw1,pcw2);                                   //~v13aR~
//    }                                                            //~v13aR~
	wkppot=wkpot;                                                  //~v08lI~
    if ((rc=uparse2(wkbuff,&pupod0,&wkppot,&wordno,                //~v08lR~
//  		UPARSE2USEAREAPARM|UPARSE2SETCONTDELM,",;"))>=4)       //~v13aR~
    		UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,",;"))>=4)       //~v13aI~
    	return rc;			//umalloc failed                    //~v06pI~
    funcuparse2_LC(0,Ppcw,wkbuff,wordno,wkbuff_LC,wkbuff_CT,sizeof(wkbuff_LC));//parse lccmd//~vavQR~
//  pupod0=pupod;                                                  //~v08lR~
    pupod=pupod0;                                                  //~v08lR~
	for (ii=0;ii<wordno;ii++,pupod++)                           //~v06pI~
    	if (pupod->upodelm==';')	//delm by ";"	            //~v06pI~
        	break;                                              //~v06pI~
	if (ii==wordno)	//not found ";"                             //~v06pI~
		pcend=0;                                                //~v06pM~
	else                                                        //~v06pI~
    {                                                              //~v0j3I~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651R~
//  	cmdlen0=strlen(wkbuff);                                    //~v55WI~//~vaa7R~
        topcmdoffs=pupod->upodelmoffs+1;                           //~v55WI~
        pupodlast=pupod+1;//next of 1st ";"                        //~v55WR~
        wordno2=wordno-ii-1;                                       //~v55WR~
#endif                                                             //~v55WM~
        *(pcend=wkbuff+pupod->upodelmoffs)=0;                   //~v06pM~
        if (!*(pcend+1))	//last end by ";"                      //~v562I~
        	pcend=0;        //fot atcmd end of multicmd chk        //~v562I~
        else                                                       //~v59pI~
    	if (*(pcend+1)==FUNC_COMMENTID)    //comment id            //~v59pI~
        	pcend=0;        //ignore after comment id              //~v59pI~
        wordno=ii+1;                                               //~v0j3I~
    }                                                              //~v0j3I~
//  ufree(pupod0);                                                 //~v08lR~
//                                                              //~v06pI~
//  cmdlen=pupod0->upodelmoffs;	//verb len                         //~v13aR~
//  pcop=wkbuff+cmdlen;                                            //~v13aI~
//  cmdlen=strlen(wkpot);	//verb len                             //~v13aR~//~vb31R~
    cmdlen=(UINT)strlen(wkpot);	//verb len                         //~vb31I~
    pcop=wkbuff+pupod0->upodelmoffs;	//verb len                 //~v13aI~
//  if (pcop=strpbrk(wkbuff," ,"),pcop)		//search " "           //~v08lR~
    if (wordno>1)                      		//operand exist        //~v08lI~
	{
//  	cmdlen=(UINT)((ULONG)pcop-(ULONG)wkbuff);	//verb len     //~v08lR~
    	pdelm=pcop++;						//for dos cmd reset delm//~v020R~
    	*pdelm=0;							//cut out cmd verb  //~v020I~
		pcop+=strspn(pcop," ");				//search non space
//      usoffs=(USHORT)((ULONG)pcop-(ULONG)wkbuff);			//1st opd offset//~v08lR~//~vafkR~
        usoffs=(USHORT)((ULPTR)pcop-(ULPTR)wkbuff);			//1st opd offset//~vafkI~
    	for (ii=wordno-1,pupod=pupod0+1;ii;ii--,pupod++)           //~v08lR~
        	pupod->upodelmoffs=(USHORT)(pupod->upodelmoffs-usoffs);//~v08lR~
    	Ppcw->UCWopdno=wordno-1;     	//cmd operand number       //~v08lI~
    	Ppcw->UCWopddelmt=pupod0+1; 	//cmd operand delm table   //~v08lR~
    	Ppcw->UCWopdpot=wkpot+strlen(wkpot)+1;	//2nd word         //~v08lR~
#ifdef UTF8SUPPH                                                   //~va1CR~
		funcsaveopdcodetype(0,Ppcw,Ppcw->UCWopdpot);    //save 1stopd lovcale code for uerrmsg//~va1CR~
#endif                                                             //~va1CR~
	}
    else                                                        //~5225I~
	{                                                           //~v020I~
    	pdelm=0;            //avoid *delm=' ';                  //~v020R~
        pcop=0;             //UCWparm=0                            //~v08lI~
    	Ppcw->UCWopdno=0;     	//cmd operand number               //~v0brI~
    	Ppcw->UCWopddelmt=0; 	//cmd operand delm table           //~v0brI~
    	Ppcw->UCWopdpot=0;		//2nd word                         //~v0brI~
//  	cmdlen=strlen(wkbuff);                                     //~v08lR~
	}                                                           //~v020I~
    if (!cmdlen)                                                //~5501I~
//  	return 	funccmderr(Ppcw,4);                                //~v565R~
    	return 	funccmderr0(Ppcw);                                 //~v565I~
                                                                //~5527I~
//*search func table by cmd string ***
    UCBITOFF(Ppcw->UCWflag,UCWFNODOSCMD);   //on if tbl search err//~v056I~
    pftdup=0;                               //dup alias chk        //~v09wI~
    if (*wkbuff==FUNC_COMMENTID)    //comment id                   //~v59pI~
    {                                                              //~v59pI~
                setflddata(Ppcw,CMDLINENO,0,"");    //clear cmd data//~v59pI~
        return 0;                                                  //~v59pI~
    }                                                              //~v59pI~
	if (cmdlen==sizeof(Sspecialeditcmd)-1                       //~5505R~
	&&  !memicmp(wkbuff,Sspecialeditcmd,sizeof(Sspecialeditcmd)-1))//~5505I~
    	pft=Sfuncedit;                                          //~5505I~
    else	//not XE                                            //~5505I~
//  if (cmdlen==sizeof(Sspecialrenumcmd)-1                         //~v504R~
//  &&  !memicmp(wkbuff,Sspecialrenumcmd,sizeof(Sspecialrenumcmd)-1))//~v504R~
//  {                                                              //~v504R~
//  	pft=Sfuncnum;                                              //~v504R~
//  	Ppcw->UCWopdno=wordno;     	//cmd operand number           //~v504R~
//  	Ppcw->UCWopddelmt=pupod0; 	//cmd operand delm table       //~v504R~
//  	Ppcw->UCWopdpot=wkpot;		//2nd word                     //~v504R~
//      pcop=wkpot;        			 //UCWparm                     //~v504R~
//  }                                                              //~v504R~
//  else	//not RENUM                                            //~v504R~
    {                                                              //~v504R~
    	orgcmdlen=cmdlen;	//original cmd len to chk dosxxx       //~v48kI~
    	if (cmdlen>=sizeof(pft->FTcmd))                            //~v0iuI~
			cmdlen=sizeof(pft->FTcmd)-1;                           //~v0iuR~
        memcpy(cmdverb,wkbuff,(UINT)cmdlen);                       //~v0iuI~
        *(cmdverb+cmdlen)=0;                                       //~v0iuI~
        UstrncpyZ(Ppcw->UCWcmdverb,cmdverb,sizeof(Ppcw->UCWcmdverb));//~vbd7I~
		for (pft=Sfunctbl;*pft->FTnamee;pft++)	//all ft entry  //~5505R~
		{                                                       //~5505R~
//  		if (pft->FTcmdlen                                      //~v0iuR~
//  			&& !memicmp(wkbuff,pft->FTcmd,(UINT)pft->FTcmdlen))//~v0iuR~
    		if (*pft->FTcmd                                        //~v0iuI~
    			&& !stricmp(cmdverb,pft->FTcmd))                   //~v0iuR~
				break;                                          //~5505R~
//  		if ((UINT)pft->FTcmdalen==cmdlen	//same len as alias//~v0iuR~
//  			&& !memicmp(wkbuff,pft->FTcmda,(UINT)pft->FTcmdalen))//~v0iuR~
    		if (*pft->FTcmda	//same len as alias                //~v0iuI~
    			&& !stricmp(cmdverb,pft->FTcmda))                  //~v0iuI~
            {                                                      //~v09wI~
              if (!UCBITCHK(pft->FTflag,FTFDUPACMD))//alias not duplicated//~v09wI~
				break;                                          //~5505R~
                if (pft->FTfunc[Ppcw->UCWtype])	//defined to this screen type//~v09wI~
					break;                                         //~v09wI~
              	pftdup=pft;	//set once found id                    //~v09wI~
            }                                                      //~v09wI~
		}//all ft entry                                         //~5505R~
		if (!*pft->FTnamee)		//not found                        //~v09wI~
        {                                                          //~v48kI~
        	if (pftdup)                                            //~v09wI~
            	pft=pftdup;		//issue not valid at ths screen    //~v09wI~
            else                                                   //~v67CI~
            {                                                      //~v67CI~
                palct=filesrchalct(cmdverb,0);  //search alias definition//~v67CI~
                if (palct)                                         //~v67CI~
                {                                                  //~v67CI~
                    Ppcw->UCWparm=pcop; //operand string           //~v67CI~
                    return funcaliasset(Ppcw,pcend,palct);//save muticmd and setup Gcmdbuff//~v67CI~
                }                                                  //~v67CI~
            }                                                      //~v67CI~
    	}                                                          //~v48kI~
        else	//found                                            //~v48kI~
        {                                                          //~v48kI~
        	if (pft==Sfuncdos)                                     //~v48kI~
            	if(orgcmdlen>strlen(Sfuncdos->FTcmd))	//DOSxxx cmd//~v48kR~
		    		otherdoscmdsw=1;                               //~v48kI~
        }                                                          //~v48kI~

//  	if (!*pft->FTnamee)		//not found                        //~v48kR~
    	if (!*pft->FTnamee||otherdoscmdsw)		//not found        //~v48kI~
		{	                                                    //~5505R~
// 		 	scrdisp();			//display pending screen//need? //~5505R~
//  		uerrmsg("\"%s\" is not a valid command verb",       //~v020R~
//  				"\"%s\" は認識できません",                  //~v020R~
//  				wkbuff);                                    //~v020R~
//  		return funccmderr(Ppcw,4);                          //~v020R~
    		UCBITON(Ppcw->UCWflag,UCWFNODOSCMD);//avoid system() call//~v056I~
            pft=Sfuncdos;                                       //~v020R~
            pcop=wkbuff;    //pass parm from first              //~v020I~
            if (pdelm)  //previous nulled                       //~v020I~
    	        *pdelm=' ';		//restrore delm for doscmd      //~v020R~
            if (((PUPANELC)Ppcw->UCWppc)->UPCid==PANTOPMENU)//hsp;opt;cmd format//~v0j1M~
            {                                                      //~v0j1I~
            	if (pcend)                                         //~v0j1I~
                	*pcend=';';		//full string parm to panfunc000optchk//~v0j1I~
                if (panfunc000optchk(Ppcw,wkbuff,&rc))	//option entered//~v0j1I~
                	return rc;					                   //~v0j1M~
            	if (pcend)                                         //~v0j1I~
                	*pcend=0;		//for dos cmd                  //~v0j1I~
            }                                                      //~v0j1I~
		}                                                       //~5505R~
    }//not special cmd                                             //~v504R~
	if (!(pfunc=pft->FTfunc[Ppcw->UCWtype]))
	{
//  	scrdisp();			//display pending screen//need?     //~4C30R~
//  	uerrmsg("\"%s\" is not a valid command for this panel",    //~v50mR~
//  			"\"%s\" はこの画面では使用できません",             //~v50mR~
//  			wkbuff);                                           //~v50mR~
        errscrtype(wkbuff);                                        //~v50mI~
		return funccmderr(Ppcw,4);                              //~5527I~
	}

    Ppcw->UCWpfunct=Gproclastpft=pft;	//reset Execute to cmd processor//~5228R~
	Ppcw->UCWparm=pcop;	//command parm	
  if (!(rc=funccmdprechk(Ppcw,pft)))	//cotinuous err            //~v09mR~
  {                                                                //~v09mI~
    csrsetwait(1);                      //display wait csr         //~v09lI~
//  if (rc=pfunc(Ppcw),rc)                                         //~v09mR~
#ifdef WINCON                                                      //~v562I~
	if (pfunc==func_sleep)                                         //~v562R~
		Smulticmd2ndptr=&pcend;	//parm to sleep,may be cleared     //~v562I~
#endif                                                             //~v562I~
    rc=pfunc(Ppcw);                                                //~v09mI~
  }                                                                //~v09mI~
    if (rc==RC3LEAVECMDLINE)                                       //~v51yI~
    {                                                              //~v51yI~
    	rc=0;                                                      //~v51yI~
    	leavecmdlinesw=1;                                          //~v51yI~
	}                                                              //~v51yI~
    else                                                           //~v51yI~
    	leavecmdlinesw=0;                                          //~v51yI~
#ifdef WINCON                                                      //~v563I~
    if (rc>=4 && Spendatcmd)                                       //~v562R~
		if (Satcmdopt & FAT_IGNOREERR)                             //~v562R~
        {                                                          //~v562I~
			funccmderr(Ppcw,rc);                                   //~v562I~
        	rc=0;                                                  //~v562R~
        }                                                          //~v562I~
#endif                                                             //~v563I~
    if (rc)                                                        //~v09mI~
	{
		if (rc==-1)		//quit
			return -1;	//cannot access Ppcw
        if (rc==RC2CONSEQERR)                                      //~v09mI~
    		funccmderr2(Ppcw);                                     //~v09mI~
        else                                                       //~v09mI~
		funccmderr(Ppcw,rc);                                    //~5122R~
//      if (rc==1)                                                 //~v09mR~
        if (rc<=RC2CONSEQERR)   //1 or 2                           //~v09mI~
            rc=0;   //avoid bell                                //~5122I~
#ifdef WINCON                                                      //~v562I~
    	if (rc && Spendatcmd)                                      //~v562I~
			funcatcmdreset(FAT_CMDER);	//stop at cmd              //~v562I~
#endif                                                             //~v562I~
		funcaliasreset();	//clear multi cmd saved by alias       //~v67CI~
	}
    else                                                        //~5122R~
	{                                                           //~5122I~
        if (!UCBITCHK(pft->FTflag,FTFFREECW)) //pcw avail       
            if (pft->FTfuncid!=FUNCID_PREVCMD                   
            &&  !leavecmdlinesw        //not remain requested      //~v51yI~
            &&  pft->FTfuncid!=FUNCID_NEXTCMD)                  
                setflddata(Ppcw,CMDLINENO,0,"");    //clear cmd data
  		if (pcend)	//multi cmd                                 //~5225R~
        {                                                       //~5225I~
            scrdisp();                                             //~v0jrI~
//test      Sleep(1000);                                           //~v67CR~
//#ifdef WXE                                                       //~v55WR~
//            wxe_scrdraw();    //redraw wxe scr                   //~v55WR~
//#endif                                                           //~v55WR~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
//          if (Spendatcmd)                                        //~v55ZR~
//          {                                                      //~v55ZR~
          if (pfunc==func_at || pfunc==func_sleep)                 //~v565I~
          {                                                        //~v565I~
	    	for (ii=wordno2,pupod=pupodlast;ii;ii--,pupod++)       //~v55WI~
    	    	pupod->upodelmoffs=(USHORT)(pupod->upodelmoffs-topcmdoffs);//~v55WI~
            if (Spendatcmd)                                        //~v55ZI~
            	atcmdopt=WXEAT_INIT;                               //~v55ZI~
            else                                                   //~v55ZI~
            {                                                      //~v564I~
            	atcmdopt=WXEAT_MCMD;                               //~v55ZI~
                Satcmdopt&=~WXEAT_IGNOREERR;                       //~v564I~
            }                                                      //~v564I~
//  	    rc=wxe_atcmd(0,Satcmdintvl,Satcmdctr,pcend+1,pupodlast,wordno2);//~v55ZR~
    	    rc=wxe_atcmd(atcmdopt|Satcmdopt,Satcmdintvl,Satcmdctr,pcend+1,pupodlast,wordno2);//~v564R~
    		memset(Gcmdbuff,0,sizeof(Gcmdbuff));    //mult cmd is controlled by wxe//~v55WI~
          }                                                        //~v565R~
          else                                                     //~v565R~
          {                                                        //~v565R~
            if (*Gcmdbuff)                                         //~v565I~
            {                                                      //~v67FI~
    	    	strcat(Gcmdbuff,";");	//may set EXIT cmd         //~v565I~
			strcat(Gcmdbuff,pcend+1);                              //~v565I~
            }                                                      //~v67FI~
            else                                                   //~v67FI~
            {                                                      //~v67FI~
	    		for (ii=wordno2,pupod=pupodlast;ii;ii--,pupod++)   //~v67FI~
    	    		pupod->upodelmoffs=(USHORT)(pupod->upodelmoffs-topcmdoffs);//~v67FI~
            	atcmdopt=WXEAT_MCMD;                               //~v67FI~
                Satcmdopt&=~WXEAT_IGNOREERR;                       //~v67FI~
    	    	rc=wxe_atcmd(atcmdopt|Satcmdopt,Satcmdintvl,Satcmdctr,pcend+1,pupodlast,wordno2);//~v67FI~
    			memset(Gcmdbuff,0,sizeof(Gcmdbuff));    //mult cmd is controlled by wxe//~v67FI~
            }                                                      //~v67FI~
          }                                                        //~v565I~
//#endif                                                           //~v55ZR~
#else                                                              //~v55ZI~
  	#ifdef WINCON   //WIN console                                  //~v562I~
          	if (Spendatcmd==ATCPEND_ACCEPT)	//at cmd detected at first//~v562R~
            {                                                      //~v562I~
            	Spendatcmd=ATCPEND_SUBCMDSTART;//atcmd repeat      //~v562R~
    	    	rc=funcatcmdinit(pcend+1);                         //~v562I~
                if (rc) //duperr                                   //~v562I~
                {                                                  //~v562I~
                	*Gcmdbuff=0;                                   //~v562I~
                    *(pcend+1)=0;	//ignore at cmd cmds           //~v562I~
                }                                                  //~v562I~
            }                                                      //~v562I~
  	#endif                                                         //~v562I~
            if (*Gcmdbuff)                                      //~5225I~
    	    	strcat(Gcmdbuff,";");	//may set EXIT cmd      //~5225R~
			strcat(Gcmdbuff,pcend+1);                           //~5225R~
#endif                                                             //~v55ZI~
		}                                                       //~5225I~
        else 	//pcend==0(not multi)                              //~v67CI~
        {                                                          //~v67CI~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
//      else                                                       //~v67CR~
    		if (Spendatcmd)                                        //~v55WI~
            {                                                      //~v55WI~
                uerrmsg("AT cmd is not follwed by any command",0); //~v563R~
            	rc=4;                                              //~v55WI~
            }                                                      //~v55WI~
            else                                                   //~v67CI~
#else                                                              //~v562I~
	#ifdef WINCON	//WIN console                                  //~v562I~
//      else                                                       //~v67CR~
    		if (Spendatcmd==ATCPEND_ACCEPT)	//at cmd detected time //~v562R~
            {                                                      //~v562I~
                uerrmsg("AT cmd is not follwed by any command",0); //~v563R~
            	rc=4;                                              //~v562I~
            }                                                      //~v562I~
            else                                                   //~v562I~
            	if (Spendatcmd==ATCPEND_SUBCMDSTART)//atcmd 1st repeat end//~v562R~
                {                                                  //~v562I~
                  if (!*Gcmdbuff	//no sleep backlog string      //~v562R~
    	          &&  !*Ssleepcmdstring)                           //~v562I~
                  {                                                //~v562I~
//UTRACEP("atcmdctl call\n");                                      //~v562R~
            		Spendatcmd=ATCPEND_SUBCMDEND;//atcmd 1st repeat end//~v562R~
                	rc=funcatcmdctl(Ppcw);                         //~v562R~
                  }                                                //~v562I~
                }                                                  //~v562I~
                else                                               //~v67CI~
    #endif                                                         //~v562I~
#endif                                                             //~v55WI~
				{                                                  //~v67CI~
                	funcaliasdeqpending();//set pending multicmd to Gcmdbuff//~v67CI~
                }                                                  //~v67CI~
        }    	//pcend==0(not multi)                              //~v67CI~
                                                                   //~v55WI~
	}                                                           //~5122I~
    csrsetwait(0);                      //reset wait csr           //~v09lI~
	return rc;                                                  //~5122I~
}//func_cmd
                                                                //~5224I~
//**************************************************            //~5224I~
//*call menu process                                            //~5224R~
//*parm1: pcw                                                   //~5224I~
//*parm2: operand addr(next of '=')                             //~v020I~
//*rc   :ok or err                                              //~5224I~
//**************************************************            //~5224I~
int callmenu(PUCLIENTWE Ppcw,UCHAR *Pcmd)                       //~5504R~
{                                                               //~5224I~
	PUCLIENTWE pcw;                                             //~5224I~
//********************************                              //~5224R~
//  csrhomepos(0);	//move csr to 1st fld of current active     //~5527R~
	if (!(pcw=scrsrchcw(0,PANTOPMENU)))		//menu pannel closed//~5224I~
    {                                                           //~5224I~
    	if (!panregist(PANTOPMENU))				//re enq menu   //~v04dR~
        	return 8;				//storage shortage          //~v04dI~
		pcw=scrsrchcw(0,PANTOPMENU);		//get menu pannel pcw//~5224I~
    }                                                           //~5224I~
    else                                                        //~5224I~
    {                                                           //~5224I~
	    scrpopup(pcw,0);	//re call menu pannell              //~5228R~
//      panwakeup(pcw);//update psd,because pcw not yet drawed,for nextline//~5504R~
//      if *cmd not null,no call to func_nextline at func_exec_pan//~5504I~
//      if *cmd null,no call to func_exec_pan,so no need to call panwakeup//~5504I~
    }                                                           //~5224I~
	setflddata(Ppcw,CMDLINENO,0,"");	//clear on original pcw //~5504I~
//  setflddata(pcw,CMDLINENO,0,Pcmd);	//cmd set to buff       //~5504R~
    if (!*Pcmd)                  //no cmd                       //~5504R~
        return 0;                                               //~5504I~
    Ppcw->UCWparm=0;			//for safe                      //~5504I~
    pcw->UCWparm=Pcmd;			//drop "="                      //~5504I~
	return func_exec_pan(pcw);				//menu process      //~5224I~
}//callmenu                                                     //~5224I~
                                                                //~5224I~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
//**************************************************               //~v55WI~
//*timer cmd                                                       //~v55WI~
//*parm1: pcw                                                      //~v55WI~
//*rc   :ok or err                                                 //~v55WI~
//**************************************************               //~v55WI~
int func_at(PUCLIENTWE Ppcw)                                       //~v55WI~
{                                                                  //~v55WI~
    int ii,opdno,value,posparmctr;                                 //~v564R~
    int rc=0,flagopt=0;                                            //~v564R~
    int len;                                                       //~v55WI~
	UCHAR *pc;                                                     //~v55WI~
//*********************************                                //~v55WI~
    if (UCBITCHK(Gprocstatus,GPROCSEXECMDFILE))                    //~v563I~
    {                                                              //~v563I~
    	uerrmsg("AT cmd is not avail in EXE cmd file",0);          //~v563I~
        return 4;                                                  //~v563I~
    }                                                              //~v563I~
	if (!(pc=Ppcw->UCWparm))		//operand                      //~v55WI~
    {                                                              //~v55WI~
        uerrmsg("AT [-i] interval [repeat-count];comand's",0);     //~v562R~
        return 0;                                                  //~v55WI~
    }                                                              //~v55WI~
//*operand chk                                                     //~v55WI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v55WI~
    pc=Ppcw->UCWopdpot;                                            //~v55WI~
    Satcmdctr=0;		//infinit loop(break by esc*2)             //~v55WR~
	for (ii=0,posparmctr=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v564R~
	{                                                              //~v55WI~
    	if (*pc=='-'||*pc=='/')                                    //~v564I~
        {                                                          //~v564I~
        	pc++;                                                  //~v564I~
        	switch(toupper(*pc))                                   //~v564R~
            {                                                      //~v564I~
            case 'I':		//ignore err                           //~v564R~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
            	flagopt=WXEAT_IGNOREERR;                           //~v564I~
#else                                                              //~v564I~
            	flagopt=FAT_IGNOREERR;                             //~v564I~
#endif                                                             //~v564I~
                break;                                             //~v564I~
            default:                                               //~v564I~
        		rc=errinvalid(pc);                                 //~v564I~
            }                                                      //~v564I~
            if (rc)                                                //~v564I~
            	break;                                             //~v564I~
            continue;                                              //~v564I~
        }                                                          //~v564I~
    	posparmctr++;                                              //~v564I~
	    if (posparmctr>2)                                          //~v564R~
	    {                                                          //~v55WI~
    		rc=errtoomany();                                       //~v55WI~
            break;                                                 //~v55WI~
	    }                                                          //~v55WI~
//      len=strlen(pc);                                            //~v55WI~//~vb30R~
        len=(int)strlen(pc);                                       //~vb30I~
	    if (unumlen(pc,0,len)!=len)                                //~v55WI~
        {                                                          //~v55WI~
        	rc=errinvalid(pc);                                     //~v55WI~
            break;                                                 //~v55WI~
        }                                                          //~v55WI~
        value=atoi(pc);                                            //~v55WI~
    	switch(posparmctr)                                         //~v562R~
        {                                                          //~v55WI~
        case 1:		//first opd                                    //~v562R~
        	Satcmdintvl=value;                                     //~v55WI~
            if (!value)                                            //~v55WI~
	        	rc=errinvalid(pc);                                 //~v55WI~
            break;                                                 //~v55WI~
        case 2:		//2nd opd                                      //~v562R~
        	Satcmdctr=value;                                       //~v55WI~
            break;                                                 //~v55WI~
        }                                                          //~v55WI~
	}//loop by operand no                                          //~v55WI~
    if (rc)	//err                                                  //~v55WI~
    	memset(Gcmdbuff,0,sizeof(Gcmdbuff));	//ignore following multicmd//~v55WI~
    else                                                           //~v55WI~
	    Spendatcmd=ATCPEND_ACCEPT;                                 //~v562R~
    Satcmdopt=flagopt;                                             //~v564I~
    return rc;                                                     //~v55WI~
}//func_at                                                         //~v55WI~
#ifdef WINCON                                                      //~v562I~
//**************************************************               //~v562I~
//*timer cmd;repeat cmd string                                     //~v562I~
//*rc   :ok or err                                                 //~v562I~
//**************************************************               //~v562I~
int funcatcmdinit(char *Pcmd)                                      //~v562I~
{                                                                  //~v562I~
//*********************************                                //~v562I~
    if (*Satcmdstring)                                             //~v562I~
    {                                                              //~v562I~
        uerrmsg("AT cmd is already active.(Esc+Esc breakes)",0);   //~v562R~
        return 4;                                                  //~v562I~
    }                                                              //~v562I~
    strcpy(Satcmdstring,Pcmd);                                     //~v562R~
    Satcmdcurrctr=0;		//repeated ctr                         //~v562I~
    return 0;                                                      //~v562I~
}//funcatcmdinit                                                   //~v562I~
//**************************************************               //~v562I~
//*timer cmd;end of each repeat                                    //~v562I~
//*rc   :ok or err                                                 //~v562I~
//**************************************************               //~v562I~
int funcatcmdctl(PUCLIENTWE Ppcw)                                  //~v562R~
{                                                                  //~v562I~
//**************************************                           //~v562I~
    Satcmdcurrctr++; //repeated count                              //~v562I~
    Gkbdinpctr++;       //for alias cmd loop chk                   //~v67CR~
    if (Satcmdctr    //not infinit                                 //~v562I~
    &&  Satcmdcurrctr>=Satcmdctr)//reached to req count            //~v562I~
        funcatcmdreset(FAT_COMP);        //end of last repeat      //~v562I~
    else                                                           //~v562I~
    {                                                              //~v562I~
    	Spendatcmd=ATCPEND_SLEEP;	//entered interval sleep       //~v562R~
        strcpy(Ssleepcmdstring,Satcmdstring);                      //~v562I~
      if (Satcmdctr)                                               //~v562I~
        uerrmsgcat(";AT cmd remains %d times repeat",0,            //~v562R~
                    Satcmdctr-Satcmdcurrctr);                      //~v562I~
      else                                                         //~v562I~
        uerrmsgcat(";infinit AT cmd %d times repeated",0,          //~v562I~
                    Satcmdcurrctr);                                //~v562I~
	    funcsleepsettimeup(Ppcw,Satcmdintvl);                      //~v562I~
    }                                                              //~v562I~
    return 0;                                                      //~v562I~
}//funcatcmdctl                                                    //~v562I~
//*************************************************************    //~v562I~
//*reset timer                                                     //~v562I~
//*ret:rc                                                          //~v562I~
//*************************************************************    //~v562I~
int funcatcmdreset(int Popt)                                       //~v562I~
{                                                                  //~v562I~
    int rc=0;                                                      //~v562R~
//**************************************                           //~v562I~
	if (Popt & FAT_RESET                                           //~v562I~
	||  Popt & FAT_CMDER)                                          //~v562I~
    {                                                              //~v562I~
        if (Spendatcmd)	//at cmd pending                           //~v562R~
        {                                                          //~v562I~
			if (Popt & FAT_CMDER)                                  //~v562R~
            	uerrmsgcat(";AT cmd interrupted by err,%d times repeated",0,//~v562R~
					        Satcmdcurrctr);                        //~v562R~
            else                                                   //~v562I~
		        uerrmsgcat(";AT cmd interrupted by user,%d times repeated",0,//~v562R~
					        Satcmdcurrctr);                        //~v562R~
	        Spendatcmd=0;                                          //~v562I~
			*Satcmdstring=0;                                       //~v562I~
            rc=1;                                                  //~v562I~
        }                                                          //~v562I~
    }                                                              //~v562I~
	if (Popt & FAT_COMP)                                           //~v562I~
    {                                                              //~v562I~
        Spendatcmd=0;	//no at cmd pending                        //~v562I~
        *Satcmdstring=0;                                           //~v562I~
        uerrmsgcat(";AT cmd completed %d times repeat",0,          //~v562R~
				Satcmdctr);                                        //~v562I~
    }                                                              //~v562I~
    return rc;                                                     //~v562I~
}//funcatcmdreset                                                  //~v562I~
#endif	//WINCON                                                   //~v562I~
#endif                                                             //~v55WI~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
//**************************************************               //~v55YI~
//*sleep cmd                                                       //~v55YI~
//*parm1: pcw                                                      //~v55YI~
//*rc   :ok or err                                                 //~v55YI~
//**************************************************               //~v55YI~
int func_sleep(PUCLIENTWE Ppcw)                                    //~v55YI~
{                                                                  //~v55YI~
    int secs;                                                      //~v55YI~
//  int rc=0;                                                      //~v651R~
    int len;                                                       //~v55YI~
	UCHAR *pc;                                                     //~v55YI~
//#ifdef WXE                                                       //~v565R~
//    static int Ssleeptime;                                       //~v565R~
//#endif                                                           //~v565R~
//*********************************                                //~v55YI~
    if (UCBITCHK(Gprocstatus,GPROCSEXECMDFILE))                    //~v563I~
    {                                                              //~v563I~
    	uerrmsg("Sleep cmd is not avail in EXE cmd file",0);       //~v563I~
        return 4;                                                  //~v563I~
    }                                                              //~v563I~
	if (!Ppcw->UCWparm)		//operand                              //~v562R~
    {                                                              //~v55YI~
        uerrmsg("SLEep seconds",0);                                //~v560R~
        return 4;                                                  //~v562R~
    }                                                              //~v55YI~
    pc=Ppcw->UCWopdpot;                                            //~v562I~
//  len=strlen(pc);                                                //~v55YI~//~vb30R~
    len=(int)strlen(pc);                                           //~vb30I~
    if (unumlen(pc,0,len)!=len)                                    //~v55YI~
        return errinvalid(pc);                                     //~v55YI~
    secs=atoi(pc);                                                 //~v55YI~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
    if (!secs)                                                     //~v55YI~
    {                                                              //~v560I~
//      if (Stmbsleep.time)                                        //~v565R~
//      {                                                          //~v565R~
//        uerrmsg("Sleep %d sec(s) expired",0,                     //~v565R~
//                Ssleeptime);                                     //~v565R~
//        Stmbsleep.time=0;                                        //~v565R~
//      }                                                          //~v565R~
//      else                                                       //~v565R~
        return errinvalid(pc);                                     //~v55YI~
    }                                                              //~v560I~
    else                                                           //~v560I~
    {                                                              //~v560I~
//        Ssleeptime=secs;                                         //~v565R~
    	uerrmsg("Sleep %d sec(s) start.(Esc+Esc breaks)",0,        //~v561R~
				secs);                                             //~v560I~
    funcsleepsettimeup(Ppcw,secs);                                 //~v562R~
    }                                                              //~v560I~
#else                                                              //~v560I~
//  Sleep(secs*1000);                                              //~v561R~
//  uerrmsg("Sleep %d sec(s) expired",0,                           //~v561R~
//  			secs);                                             //~v561R~
	if (secs<=0)                                                   //~v561I~
        return errinvalid(pc);                                     //~v561I~
    if (*Smulticmd2ndptr)  //no sleep cmd has follower             //~v562R~
    {                                                              //~v562I~
        strcpy(Ssleepcmdstring,*Smulticmd2ndptr+1);                //~v562R~
    	*Smulticmd2ndptr=0;	//clear pcend                          //~v562R~
    }                                                              //~v562I~
    else                                                           //~v562I~
    	*Ssleepcmdstring=0;	//no follower                          //~v562I~
    setflddata(Ppcw,CMDLINENO,0,"");    //clear cmd data           //~v562I~
    funcsleepsettimeup(Ppcw,secs);                                 //~v562R~
#endif                                                             //~v560I~
    return 0;                                                      //~v55YI~
}//func_sleep                                                      //~v560R~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
//**************************************************               //~v560I~
//*sleep cmd                                                       //~v560I~
//*parm1: pcw                                                      //~v560I~
//*rc   :ok or err                                                 //~v560I~
//**************************************************               //~v560I~
int funcsleepsettimeup(PUCLIENTWE Ppcw,int Pintvl)                 //~v562R~
{                                                                  //~v560I~
//*********************************                                //~v560I~
	funcsetsleepblock(Pintvl);                                     //~v565I~
    wxe_setsleeptime(Pintvl);                                      //~v560I~
    return 0;                                                      //~v560I~
}//funcsleepsettimeup                                              //~v560I~
//**************************************************               //~v565I~
//*block input by sleep                                            //~v565I~
//*parm1: pcw                                                      //~v565I~
//*rc   :ok or err                                                 //~v565I~
//**************************************************               //~v565I~
int funcsetsleepblock(int Pintvl)                                  //~v565I~
{                                                                  //~v565I~
//*********************************                                //~v565I~
    if (Pintvl) //set req                                          //~v565I~
    {                                                              //~v565I~
		ftime(&Stmbsleep);                                         //~v565R~
    	Stmbsleep.time+=Pintvl;	//sleep time up time               //~v565R~
    }                                                              //~v565I~
    else                                                           //~v565I~
    	Stmbsleep.time=0;		//reset input block                //~v565I~
    return 0;                                                      //~v565I~
}//funcsetsleepblock                                               //~v565R~
#else   //!WXE(W32)                                                //~v561I~
//**************************************************               //~v561I~
//*peek kbd in sleeping                                            //~v561I~
//*parm1: sleeptime(init) or 0(kbd inp but,not expired)            //~v561I~
//*rc   :ok or err                                                 //~v561I~
//**************************************************               //~v561I~
int funcsleepsettimeup(PUCLIENTWE Ppcw,int Pintvl)                 //~v562R~
{                                                                  //~v561I~
    static int Ssleepms,Ssleeptime,Ssleepedms;                     //~v561I~
    int peekintvl=SLEEPPEEKINTVL;                                  //~v562I~
//*********************************                                //~v561I~
	if (Pintvl)                                                    //~v561I~
    {                                                              //~v561I~
		ftime(&Stmbsleep);                                         //~v561I~
    	Stmbsleep.time+=Pintvl;	//sleep time up time               //~v561I~
//UTRACEP("sleep set=%d\n",Stmbsleep.time);                        //~v562R~
    	Ssleeptime=Pintvl;                                         //~v561I~
    	Ssleepms=Pintvl*1000;                                      //~v561I~
        Ssleepedms=0;                                              //~v561I~
      if (Spendatcmd!=ATCPEND_SLEEP)    //not at cmd interval sleep//~v562R~
	    uerrmsg("Entered %d sec(s) sleep.(Esc+Esc breaks)",0,      //~v561R~
    			Pintvl);                                           //~v561R~
        scrdisp();	//because,no return to xe.c                    //~v561I~
    }                                                              //~v561I~
	for (;;)                                                       //~v561I~
    {                                                              //~v561I~
        if (kbdchk())                                              //~v562M~
        	break;                                                 //~v562M~
//      peekintvl=5000;                                            //~v562R~
		Sleep(peekintvl);                                          //~v562R~
        Ssleepms-=peekintvl;                                       //~v562R~
        Ssleepedms+=peekintvl;                                     //~v562R~
//UTRACEP("Sleepms=%d\n",Ssleepms);                                //~v562R~
        if (Ssleepms<=0)                                           //~v561I~
        {                                                          //~v561I~
	    	funcsleepwake(Ppcw,FSW_COMP,Ssleeptime);               //~v562R~
            return 0;                                              //~v561I~
        }                                                          //~v561I~
        if (Ssleepedms>=2000)		//msg at each 2sec             //~v561R~
        {                                                          //~v561I~
	        uerrmsg("Sleep more %d sec(s)",0,                      //~v561I~
    	    		Ssleepms/1000);                                //~v561I~
    		Ssleepedms=0;                                          //~v561I~
	        scrdisp();	//because,no return to xe.c                //~v561I~
        }                                                          //~v561I~
    }//kbdchk sleep loop                                           //~v561I~
    return 0;                                                      //~v561I~
}//funcsleepsettimeup                                              //~v561R~
//**************************************************               //~v562I~
//*sleep end or canceled                                           //~v562I~
//* restore following cmds in multicmd                             //~v562I~
//**************************************************               //~v562I~
int funcsleepwake(PUCLIENTWE Ppcw,int Popt,int Ptime)              //~v562R~
{                                                                  //~v562I~
    int cmdfollowedsw;                                             //~v565I~
//******************                                               //~v565I~
    Stmbsleep.time=0;       //release kbd input block              //~v562I~
//UTRACEP("sleepwake pendatcmd=%d,opt=%d,time=%d\n",Spendatcmd,Popt,Ptime);//~v562R~
    if (Spendatcmd==ATCPEND_SLEEP)	//at cmd interval sleep        //~v562R~
    {                                                              //~v562I~
        if (Popt==FSW_RESET)     //sleep completed                 //~v562R~
        {                                                          //~v562I~
			*Ssleepcmdstring=0;                                    //~v562I~
			return funcatcmdreset(FAT_RESET);	//stop at cmd      //~v562I~
        }                                                          //~v562I~
    	Spendatcmd=ATCPEND_SUBCMDSTART;	//sub cmd of 2nd loop      //~v562I~
//UTRACEP("at cmd interval sleep end\n");                          //~v562R~
		strcpy(Gcmdbuff,Satcmdstring);//restore following subcmd of multicmd//~v562R~
		*Ssleepcmdstring=0;                                        //~v562I~
    	return 0;                                                  //~v562I~
    }                                                              //~v562I~
    if (Popt==FSW_COMP)     //sleep completed                      //~v562I~
    {                                                              //~v565I~
		uerrmsg("Sleep %d sec(s) expired",0,                       //~v562I~
  				Ptime);                                            //~v562R~
		strcpy(Gcmdbuff,Ssleepcmdstring);//restore following subcmd of multicmd//~v565I~
    }                                                              //~v565I~
    else                                                           //~v562I~
    {                                                              //~v565I~
        uerrmsg("Sleep interrupted remaining %d sec(s)",0,         //~v562R~
        		Ptime);                                            //~v562R~
		*Gcmdbuff=0;                                               //~v565I~
    }                                                              //~v565I~
    cmdfollowedsw=*Ssleepcmdstring;                                //~v565I~
//  strcpy(Gcmdbuff,Ssleepcmdstring);//restore following subcmd of multicmd//~v565R~
	*Ssleepcmdstring=0;                                            //~v562I~
    if (Popt==FSW_RESET)    //sleep reset                          //~v562I~
    {                                                              //~v565I~
//      if (*Gcmdbuff)  //there is following cmd                   //~v565R~
        if (cmdfollowedsw)                                         //~v565I~
        {                                                          //~v562R~
            scrdisp();                                             //~v562R~
            Sleep(SLEEPMSGINTVL);   //reset msg display interval   //~v562R~
        }                                                          //~v562R~
        if (Spendatcmd==ATCPEND_SUBCMDSTART)//atcmd 1st repeat end //~v565I~
        {                                                          //~v565I~
            Spendatcmd=ATCPEND_SUBCMDEND;//atcmd 1st repeat end    //~v565I~
            funcatcmdctl(Ppcw);         //next vrepeat             //~v565I~
        }                                                          //~v565I~
    }                                                              //~v565I~
    return 0;                                                      //~v562I~
}//funcsleepwake                                                   //~v562I~
#endif  //W32                                                      //~v561I~
//**************************************************               //~v560I~
//*sleep reset                                                     //~v560I~
//*parm1: pcw                                                      //~v560I~
//*rc   :ok or err                                                 //~v560I~
//**************************************************               //~v560I~
int funcsleepreset(PUCLIENTWE Ppcw)                                //~v562R~
{                                                                  //~v560I~
    struct timeb tmb;                                              //~v560I~
    int rc;                                                        //~v560I~
//*********************************                                //~v560I~
    if (Stmbsleep.time)	//sleep time up time                       //~v560I~
    {                                                              //~v560I~
    	ftime(&tmb);                                               //~v560R~
//  #ifdef WXE                                                     //~v651R~
    #ifdef WXEXXE                                                  //~v651I~
        uerrmsg("Sleep is interrupted remaining %d sec(s)",0,      //~v562R~
        		Stmbsleep.time-tmb.time);                          //~v562M~
    	Stmbsleep.time=0;	//sleep time up time                   //~v562M~
        wxe_timerreset(WXEAT_SLEEPRESET);                          //~v560I~
    #else                                                          //~v562I~
//  	funcsleepwake(Ppcw,FSW_RESET,Stmbsleep.time-tmb.time);     //~v796R~
    	funcsleepwake(Ppcw,FSW_RESET,(int)(Stmbsleep.time-tmb.time));//~v796I~
    #endif                                                         //~v561I~
    	rc=1;                                                      //~v560I~
    }                                                              //~v560I~
    else                                                           //~v560I~
    	rc=0;                                                      //~v560I~
    return rc;                                                     //~v560I~
}//funcsleepreset                                                  //~v561R~
#endif                                                             //~v55YI~
//**************************************************               //~v09mI~
//*funccmdprechk                                                   //~v09mI~
//*parm1: pcw                                                      //~v09mI~
//*parm2: pft                                                      //~v09mI~
//*rc   :0:no dup err,execute func; 2:dup err bypass process       //~v09mR~
//**************************************************               //~v09mI~
int funccmdprechk(PUCLIENTWE Ppcw,FUNCTBL *Ppft)                   //~v09mI~
{                                                                  //~v09mI~
static int Sprevinpctr=0;                                          //~v55cR~
    PUFILEH pfh;                                                   //~v09mI~
    int rc=0;                                                      //~v09mI~
//********************************                                 //~v09mI~
	if (Ppcw->UCWtype==UCWTFILE)	//browse/edit                  //~v09mI~
    {                                                              //~v09mI~
    	switch(Ppft->FTfuncid)                                     //~v09mR~
    	{                                                          //~v09mI~
    	case FUNCID_CREATE:                                        //~v09mI~
    	case FUNCID_REPL:                                          //~v09mI~
    	case FUNCID_COPY:                                          //~v09mI~
    	case FUNCID_MOVE:                                          //~v09mI~
    	case FUNCID_APPEND:                                        //~v0iaI~
			if (Ppcw->UCWparm)	//not operand missing err          //~v09mI~
            {                                                      //~v09mI~
    			pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;             //~v09mI~
    			if (!pfh->UFHcmdlinectr)  //dest or sorce missing err//~v09mR~
                {                                                  //~v09mI~
                	if (Gkbdinpctr==Sprevinpctr+1)                 //~v09mI~
                    	rc=RC2CONSEQERR;		//continued err,bypass proces//~v09mR~
					Sprevinpctr=Gkbdinpctr;     //err detected ctr //~v09mI~
				}                                                  //~v09mI~
			}//marm missing err                                    //~v09mI~
            break;                                                 //~v09mI~
    	}//sw by funcid                                            //~v09mI~
    }//browse/edit                                                 //~v09mI~
    return rc;                                                     //~v09mI~
}//funccmdprechk                                                   //~v09mI~
                                                                   //~v09mI~
//**************************************************            //~5504I~
//*operand post process for Func-key not but command process    //~5504I~
//*parm1: client work element                                   //~5504I~
//*parm2: err level                                             //~5504I~
//*return:none                                                  //~5504I~
//**************************************************            //~5504I~
void funcopdpostp(PUCLIENTWE Ppcw,int Prc)                      //~5504I~
{                                                               //~5504I~
//************************************                          //~5504I~
    if (Ppcw->UCWkeytype==UCWKTCMD	//cmd process               //~5504I~
    ||  !Ppcw->UCWparm)				//no operand                //~5504I~
    	return;                                                 //~5504I~
                                                                //~5504I~
	if (Prc)	//func key process found err                    //~5504I~
		funccmderr(Ppcw,Prc);                                   //~5504I~
	else                                                        //~5504I~
		setflddata(Ppcw,CMDLINENO,0,"");	//operand           //~5504I~
    return;                                                     //~5504I~
}//funcopdpostp                                                 //~5504I~
                                                                //~5504I~
//**************************************************               //~v67CI~
//*edit alias cmd and set to Gcmdbuff,if part of multicmd save followed cmd//~v67CI~
//*parm2: addr of ";" of folllowed cmd of multicmd                 //~v67CI~
//*rc 0                                                            //~v67CI~
//**************************************************               //~v67CI~
int  funcaliasset(PUCLIENTWE Ppcw,char *Ppcend,PALCT Ppalct)       //~v67CI~
{                                                                  //~v67CI~
	char *pc,*pcmd;                                                //~v67CI~
    int len,rc;                                                    //~v67CR~
#ifdef WXEXXE                                                      //~v67CI~
    int len2;                                                      //~v67CI~
#else                                                              //~v67CI~
	PPMC ppmc;                                                     //~v67CI~
#endif                                                             //~v67CI~
    char parmfnm[_MAX_PATH*2+2];                                   //~vanfI~
    int opt;                                                       //~vanfI~
//************************************                             //~v67CI~
    if (Ppalct->ALCTkbdctr==Gkbdinpctr)                            //~v67CI~
    {                                                              //~v67CI~
        uerrmsg("Recursive alias cmd(%s) use?",0,                  //~v67CI~
                 Ppalct->ALCTcmdverb);                             //~v67CI~
        return 4;                                                  //~v67CI~
    }                                                              //~v67CI~
    Ppalct->ALCTkbdctr=Gkbdinpctr;                                 //~v67CI~
    pc=strchr(Ppalct->ALCTcmd,' ');                                //~v67CI~
    if (!pc)                                                       //~v67CI~
        return 4;                                                  //~v67CI~
    pc+=strspn(pc," ");                                            //~v67CI~
//  if (Ppcw->UCWparm)  //edit required                            //~v70yR~
//  {                                                              //~v70yR~
        opt=CPEO_APPEND|CPEO_FNMPARM;                              //~vanfI~
		kbdsetmacrocmdfilenameparm(Ppcw,parmfnm);                  //~vanfI~
        pcmd=parmfnm;                                              //~vanfI~
//      ucmdparmedit(1,pc,Ppcw->UCWparm,0,&pcmd);//0 no padding unused parm//~v67CR~//~vanfR~
        ucmdparmedit(opt,pc,Ppcw->UCWparm,0,&pcmd);//0 no padding unused parm//~vanfI~
        strcpy(Gcmdbuff,pcmd);                                     //~v67CR~
        ufree(pcmd);                                               //~v67CR~
//  }                                                              //~v70yR~
//  else                                                           //~v70yR~
//      strcpy(Gcmdbuff,pc);                                       //~v70yR~
#ifdef WXEXXE                                                      //~v67CI~
//  len=strlen(Gcmdbuff);                                          //~v67CI~//~vb30R~
    len=(int)strlen(Gcmdbuff);                                     //~vb30I~
    if (!len)                                                      //~v67CI~
    	return 0;                                                  //~v67CI~
    if (Ppcend)                                                    //~v67CI~
//  	len2=strlen(Ppcend+1);                                     //~v67CI~//~vb30R~
    	len2=(int)strlen(Ppcend+1);                                //~vb30I~
    else                                                           //~v67CI~
    	len2=0;                                                    //~v67CI~
    if (len2)                                                      //~v67CI~
    {                                                              //~v67CI~
    	pc=Gcmdbuff+len;                                           //~v67CI~
	    if (*(pc-1)==';')                                          //~v67CI~
        {                                                          //~v67CI~
    		memcpy(pc,Ppcend+1,(UINT)len2+1); 	//from next of ";" to last null//~v67CI~
            len+=len2;                                             //~v67CI~
        }                                                          //~v67CI~
        else                                                       //~v67CI~
        {                                                          //~v67CI~
    		memcpy(pc,Ppcend,(UINT)len2+2);	//from ";" to last null//~v67CI~
            len+=len2+1;                                           //~v67CI~
        }                                                          //~v67CI~
    }                                                              //~v67CI~
	rc=funcaliassetwxe(Ppcw,Gcmdbuff,len);	//multcmd parse split  //~v67CR~
    *Gcmdbuff=0;                                                   //~v67CI~
#else                                                              //~v67CI~
    rc=0;                                                          //~v67CI~
	if (Ppcend)                                                    //~v67CM~
    {                                                              //~v67CM~
    	pc=Ppcend+1;	//skip ";"                                 //~v67CM~
        len=(int)strlen(pc);                                       //~v691R~
        if (len)                                                   //~v67CM~
        {                                                          //~v67CM~
//          ppmc=ucalloc(1,(UINT)(PMCSZ+len));                     //~v67CM~//~vb30R~
            ppmc=ucalloc(1,PMCSZ+(size_t)len);                     //~vb30I~
            ppmc->PMCcmdlen=len;                                   //~v67CM~
            memcpy(ppmc->PMCcmd,pc,(UINT)len);                     //~v67CM~
            UENQ(UQUE_END,&Sqhpmc,ppmc);                           //~v67CM~
        }                                                          //~v67CM~
    }                                                              //~v67CM~
#endif                                                             //~v67CI~
	return rc;                                                     //~v67CR~
}//funcaliasset                                                    //~v67CI~
#ifdef WXEXXE                                                      //~v67CI~
//**************************************************               //~v67CI~
//*edit alias cmd and set to Gcmdbuff,if part of multicmd save followed cmd//~v67CI~
//*parm2: addr of ";" of folllowed cmd of multicmd                 //~v67CI~
//*rc 0                                                            //~v67CI~
//**************************************************               //~v67CI~
int  funcaliassetwxe(PUCLIENTWE Ppcw,char *Pacmdedit,int Plen)     //~v67CI~
{                                                                  //~v67CI~
    int /*len,*/rc,wordno;                                             //~v67CR~//~vaa7R~
	UCHAR *wkppot;                                                 //~v67CI~
    PUPODELMTBL pupod0;                                            //~v67CR~
//************************************                             //~v67CI~
//  len=Plen;                                                      //~v67CI~//~vaa7R~
    if ((rc=uparse2(Pacmdedit,&pupod0,&wkppot,&wordno,             //~v67CR~
    		UPARSE2SETCONTDLM2,";"))>=4)                           //~v67CI~
    	return rc;			//umalloc failed                       //~v67CI~
	rc=wxe_atcmd(WXEAT_MCMD|WXEAT_ALIAS,0,0,Pacmdedit,pupod0,wordno);//~v67CI~
    ufree(pupod0);                                                 //~v67CR~
	return rc;                                                     //~v67CI~
}//funcaliassetwxe                                                 //~v67CI~
#endif                                                             //~v67CI~
//**************************************************               //~v67CI~
//*crear cmd pending q                                             //~v67CI~
//*rc 0                                                            //~v67CI~
//**************************************************               //~v67CI~
void  funcaliasreset(void)                                         //~v67CI~
{                                                                  //~v67CI~
//************************************                             //~v67CI~
	uqufree(&Sqhpmc);                                              //~v67CR~
	return;                                                        //~v67CI~
}//funcaliasreset                                                  //~v67CI~
//**************************************************               //~v67CI~
//*deq pending multicmd                                            //~v67CI~
//**************************************************               //~v67CI~
void  funcaliasdeqpending(void)                                    //~v67CI~
{                                                                  //~v67CI~
	PPMC ppmc;	                                                   //~v67CI~
//************************************                             //~v67CI~
    if (*Gcmdbuff)                                                 //~v67DI~
        return; //already set (by Sleep cmd etc)                   //~v67DI~
	ppmc=UDEQ(UQUE_END,&Sqhpmc,0);                                 //~v67CR~
    if (ppmc)                                                      //~v67CI~
    {                                                              //~v67CI~
    	strcpy(Gcmdbuff,ppmc->PMCcmd);                             //~v67CI~
        ufree(ppmc);                                               //~v67CR~
    }                                                              //~v67CI~
    else                                                           //~v67CI~
    	*Gcmdbuff=0;                                               //~v67CI~
	return;                                                        //~v67CI~
}//funcaliasdeqpending                                             //~v67CI~
//**************************************************               //~v565I~
//*nop cmd process(clear cmd line)                                 //~v565I~
//*parm1: client work element                                      //~v565I~
//*rc 0                                                            //~v565I~
//**************************************************               //~v565I~
int  funccmderr0(PUCLIENTWE Ppcw)                                  //~v565I~
{                                                                  //~v565I~
//************************************                             //~v565I~
	setflddata(Ppcw,CMDLINENO,0,"");	//operand                  //~v565I~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);//draw   //~v565I~
    csronthefld(Ppcw,CMDLINENO,0,0);    //set cursor to fld top    //~v565I~
	return 0;                                                      //~v565I~
}//funccmderr                                                      //~v565I~
//**************************************************            //~4C30I~
//*set cmd err                                                  //~4C30I~
//*parm1: client work element                                   //~5122R~
//*parm2: err level                                             //~5122I~
//*rc   :same as parm2                                          //~5527R~
//**************************************************            //~4C30I~
int  funccmderr(PUCLIENTWE Ppcw,int Prc)                        //~5527R~
{                                                               //~4C30I~
//************************************                          //~4C30I~
	UCBITON(Ppcw->UCWflag,UCWFCMDERR);                          //~4C30I~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);//draw//~4C30I~
	if (Prc==1)                                                 //~5122I~
		func_nextline(Ppcw);//rc=1(cmd pend)                    //~5122I~
	else                                                        //~5122I~
		csronthefld(Ppcw,CMDLINENO,0,0);	//set cursor to fld top//~5223R~
	return Prc;                                                 //~5527R~
}//funccmderr                                                   //~4C30I~
//**************************************************               //~v09mI~
//*set cmd err without redraw                                      //~v09mI~
//*parm1: client work element                                      //~v09mI~
//*rc   :2                                                         //~v09mI~
//**************************************************               //~v09mI~
int  funccmderr2(PUCLIENTWE Ppcw)                                  //~v09mI~
{                                                                  //~v09mI~
//************************************                             //~v09mI~
//  UCBITON(Ppcw->UCWflag,UCWFCMDERR);	//avoid set draw bit by exec_pan//~v09mR~
	UCBITOFF((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);        //~v09mI~
 //invalidate setflddata set,if on need also UCWFCMDERR to draw reverse//~v09mI~
	func_nextline(Ppcw);                                           //~v09mI~
	return 2;                                                      //~v09mI~
}//funccmderr2                                                     //~v09mI~
//**************************************************               //~v07aI~
//*funcinvalidkey                                                  //~v07aI~
//*parm1: client work element                                      //~v07aI~
//*rc   :4                                                         //~v07aI~
//**************************************************               //~v07aI~
int  funcinvalidkey(PUCLIENTWE Ppcw)                               //~v07aI~
{                                                                  //~v07aI~
//************************************                             //~v07aI~
	uerrmsg("Undefined key on this panel",                         //~v07aR~
		    "この画面ではこのキーは使用できません");               //~v07aI~
	return 4;                                                      //~v07aI~
}//funcinvalidkey                                                  //~v07aR~
//**************************************************               //~v09PI~
//*funcinhibitkey errmsg                                           //~v09PI~
//*parm1:key value                                                 //~v09PI~
//*rc   :4                                                         //~v09PI~
//**************************************************               //~v09PI~
int  funcinhibitkey(UCHAR Pkey)                                    //~v09PR~
{                                                                  //~v09PI~
//************************************                             //~v09PI~
//  uerrmsg("Char(0x%02X) is input prohibitted",                   //~v09PI~//~va6UR~
//		    "入力禁止文字(0x%02x)",                                //~v09PI~//~va6UR~
    uerrmsg("Char(0x%02X) is input prohibitted(Adjustable by ini file)",//~va6UI~
  		    "入力禁止文字(0x%02x)(iniファイルで調整可\x94\\)",     //~va6UR~
  			(int)Pkey);                                            //~v09PR~
  	return 4;                                                      //~v09PI~
}//funcinhibitkey                                                  //~v09PI~
