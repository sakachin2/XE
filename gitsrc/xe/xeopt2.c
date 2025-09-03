//*CID://+vbDiR~:                             update#=  499;       //~vbDiR~
//*************************************************************
//*xeopt2.c                                                        //~7B24R~
//* Mode                                                           //~v90wR~
//*************************************************************
//vbDi:250710 opt unicomb help msg "]"-->"}"                       //~vbDiI~
//vbBs:241114 del vbB9(process cp931(cp300+cp037)) because m2b from sjis generates 0e0f dbcs word for byte of sjis 1st byte whichi is byte of iso-8859.//~vbBsI~
//vbBi:241012 (BUG)EBC info,when converter=1, display cvnam=CP930+CP930//~vbBiR~
//v7dm:241006 delete EBC2ASC_BASE option, then use the value as SBCS037 for CP037 without DBCS//~v7dmI~
//vbBf:241006 adjust ebc file header line. del "CFG:" when by cmdline /ebc//~vbBfI~
//vbB9:240824 add cp931(cp300+cp037)                               //~vbB9I~
//vbB7:240820 accept converter=0 sjisopt BASE                      //~vbB7I~
//vbB4:240816 EBC cmd;display ebc cfg status                       //~vbB4I~
//vbra:200731 set default for GUM2_KBDUTF8                         //~vbraI~
//vbr9:200729 (BUG)Goptopt2 flag duplicated of GOPT2_ALLFILELOCALE and GOPT2_COMBINE by 0x20//~vbr9I~
//vbmq:180722 set opt unicomb status on dirlist hdrline            //~vbmqI~
//vbkx:180708 (LNX:Bug)opt uncomb;itself/shadow is not notified to ulib when change to comb from UNPR//~vbkxI~
//vbkt:180702 (BUG)"opt unicomb unp" set unpchar 763ba3a4.(UNP is invalid,UNPR is valid, but assumed Uxxxx)//~vbktI~
//vbk2:180605 (LNX:Console)shadow/itself/padding option is effectiv also when OPT2COMBINE when csr is on it(uviom_setcombine1)//~vbk2I~
//vbk1:180605 (LNX:Console:Bug)"combine itself" was not notified to uviom at init//~vbk1I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vbf0:180109 WriteConsoleOutputW(used for cpu8 ligaturemode) shrinks line on Windows10(OK on XP),prohibit ligature on for Windows10//~vbf0I~
//vbCD:160825 for also locale file display ligature mode like as vb4q//~vb4qI~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//vb4p:160809 accept U-xx for UNICOMB UNPR                         //~vb4pI~
//vb4n:160808 (LNX)UNPR char was lost when change to split mode    //~vb4nI~
//vb4m:160808 (LNX)set default combaltch by u-00                   //~vb4mR~
//vb4k:160805 vb4f for LNX(specify ligature on/off,combine on/of line by line)//~vb4kI~
//vb4j:160806 (W32)OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay)//~vb4jI~
//vb2X:160404 display -Ccp value on optcombine help                //~vb2XI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2n:160201 (W32)use FN{LC|U8} option translate input filename u8<-->lc regardless A+u kbd mode(like as (LNX)b2j)//~vb2nI~
//vb2h:160129 display filename encoding type on hdr/trailer linet at ufcleft//~vb2hI~
//vb2e:160122 (LNX)convert filename according IOCHARSET mount option//~vb2eI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW})         //~vaj0I~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va8g:101003 display EBC codepage for also directory              //~va8gI~
//va82:100921 display eol type on hdr line                         //~va82I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7K:100904 add RESET option to cv cmd B2B(change UFHhandle) and CPEB option to RESet cmd.//~va7KI~
//va79:100809 cpeb converter parm support                          //~va79I~
//            .set convertername on top/tail line                  //~va79I~
//va69:100619 HDR ebcdic id;"E" EBC, "e":bin+EBC                   //~va69I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3s:100219 simple split mode like as windows. single write combining char when split mode.//~va3sI~
//            visibility depends to curses. user select split or combine mode.//~va3sI~
//            shadow is another option by opt cmd                  //~va3sI~
//va3j:100208 (LNX)try ligature for console version                //~va3jI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va3e:100207 (LNX)Console version:to display combine char is not stable. add 3rd option to set unprintable. by A+":"//~va3eI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va30:100126 combine mode of diacritical marks by A+/             //~va30I~
//va1N:091122 (UTF8)CPU8 trans err reloading is option by UTF8 cmd //~va1NI~
//va1t:091108_(UTF8:BUG)draw both scr split when A+u               //~va1tI~
//va1p:091104_(UTF8)file/dir default encoding option by UTF cmd    //~va1pI~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va10I~
//                      GUM2_KBDU2L,GUM2_KBDL2U-->GUM2_KBDUTF8 on/off//~va10I~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          dirlist locale id by env for input on rename fld       //~va00I~
//          files encoded by utf8                                  //~va00I~
//          set encoding id on header line                         //~va00I~
//v92p:080802 (UTF:BUG)BUG by v92i;ABEND by Alt+U(SWKBD)           //~v92pI~
//v92i:080505 (UTF:BUG)cplc is not register to path record         //~v92iI~
//v78w:080402*(UTF8)profile function                               //~v78wI~
//v929:080128 (UTF)change cmd verv "opt mode"->"opt utf" "mode"->"utf"//~v929I~
//v922:080107 (UTF)explicitly display locale file id on hdr line even when not uytf8 env//~v922I~
//v91H:071221 (UTF8)common errmsg not supported under no-utf8 mode //~v91HI~
//v91y:071218 (UTF8)display CPFILE mode by hdrline current column field color//~v91yI~
//v91s:071214 (UTF8)integrate opt mode kbd to mode swkbd           //~v91sI~
//v91h:071211 (UTF8)use CPLC/CPU8 for dirlist is for select dlcmd  //~v91hI~
//v91d:071205 (LNX:UTF8)locale support other than EUC              //~v91dI~
//v917:071130 (UTF8)assign A+u to switch kbd conversion mode between asis and conv mode//~v916I~
//v916:071129 (UTF8)kbd asis(conv according to file encoding mode) //~v916I~
//v915:071128 (UTF8)distinguish LOCALE file and asis file          //~v915I~
//v912:071128 (UTF8)display sign of utf8 encoded on header line    //~v912I~
//v90z:071127 (UTF8)OPT MODE {L2U|U2L} cmd for conv kbd input      //~v90zI~
//v90w:071124 (UTF8) MODE command                                  //~v90wI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
#ifdef UTF8UCS2                                                    //~va3eI~
    #if defined(W32)||defined(LNX)                                 //~v5mQR~//~va3eI~
		#include <locale.h>                                        //~v609I~//~va3eI~
	#endif                                                         //~v609I~//~va3eI~
#endif                                                             //~va3eI~
#ifdef W32                                                         //~va3hI~
	#include <windows.h>                                           //~va3hI~
    #include <dos.h>                                               //~vb2hI~
#endif                                                             //~va3hI~
#ifdef LNX                                                         //~va3hI~
#define _XOPEN_SOURCE_EXTENDED		//ncurses define               //~va3hI~
		#include <ucurses.h>	         //v1.3 add                //~va3hI~
#endif                                                             //~va3hI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <uparse.h>                                                //~v0b2R~
#include <utf.h>                                                   //~v90zI~
#include <ustring.h>                                               //~v91dI~
#include <udbcschk.h>                                              //~v91dI~
//#ifdef W32                                                       //~va3hR~
#ifdef UTF8UCS2                                                    //~va3hI~
#include <uviom.h>                                                 //~va3hI~
#endif                                                             //~va3hI~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va79R~
#include <ucvebc4.h>                                               //~va79I~
#include <utrace.h>                                                //~vb4jI~
#include <udos.h>                                                  //~vbf0I~
#include <uedit.h>                                                 //~vbktI~

#include "xe.h"
#include "xescr.h"                                                 //~v90wM~
#include "xefile.h"                                                //~v90wR~
#include "xefile5.h"                                               //~va7KI~
#include "xefunc.h"
#include "xefcmd6.h"                                               //~v78wI~
#include "xesub.h"                                                 //~v90wI~
#include "xeopt.h"                                                 //~v90wI~
#include "xefsub.h"                                                //~va7LI~
#include "xeerr.h"                                                 //~v90wI~
#include "xeundo.h"                                                //~v90wI~
#include "xeutf.h"                                                 //~v90wI~
#ifdef XXE                                                         //~va3dI~//~va3eR~
#include "xxexei.h"                                                //~va3dI~
#endif                                                             //~va3dI~
#ifdef WXE                                                         //~va3gI~
#include "wxexei.h"                                                //~va3gI~
#endif                                                             //~va3gI~
#ifdef UTF8SUPPH                                                   //~va00R~
//****************************************************************
//****************************************************************
#define OPT_FILE         "FILE"                                    //~va1pR~
#define OPT_FILENAME     "FN"                                      //~va1pI~
#define OPT_COMBSPLIT    "SPLIT"                                   //~va3sI~
#define OPT_COMBCOMBINE  "COMB"                                    //~va3sR~
#define OPT_COMBALTCH    "UNPR"                                    //~va3sR~
#define OPT_COMBLIGATURE "LIGATURE"                                //~va3sM~
                                                                   //~va3sI~
#define OPT_COMBSHADOW   "SHADOW"                                  //~va3sI~
#define OPT_COMBITSELF   "ITSELF"                                  //~va3sR~
#define OPT_COMBPADDING  "PADDING"                                 //~va3sI~
//**************************************************************** //~v44qI~
int funcmodehelp(void);                                            //~v90wR~
#ifdef UTF8SUPP                                                    //~va00I~//~va0xM~
int funcmoderesetdbcstbl(PUCLIENTWE Ppcw,PUFILEH Ppfh);            //~v90wR~
#endif                                                             //~va1pI~
#ifdef UTF8SUPPH                                                   //~va1pI~
int opt_modestatus(int Pcase,int Popt);                            //~v90zI~
#endif                                                             //~va0xI~
int opt2sethdrligcomb(int Popt,PUFILEH Ppfh);                      //~vb4qR~
#define O2SHLCO_LIGATUREONLY    0x10    //don't edit combine mode  //~vbCDR~
//**************************************************************** //~v91sI~
//!xeopt2init                                                      //~v91sI~
//* ajust opt2 at read ini file                                    //~v91sI~
//* not called when ini file removed                               //~vb4nI~
//*retrn:rc                                                        //~v91sI~
//**************************************************************** //~v91sI~
void xeopt2init(void)                                              //~v91sI~
{                                                                  //~v91sI~
#ifdef OLDA10                                                      //~va10I~
	if (UTF8MODEENV()) //env is utf8(linux locale=utf8)            //~v91sI~
    {                                                              //~v91sI~
        if (Goptopt2 & GOPT2_MODEINPUTU2L)                         //~v91sI~
        	Gutfmode2|=GUM2_KBDU2L; //ignore MODEINPUTL2U          //~v91sR~
    }                                                              //~v91sI~
    else                                                           //~v91sI~
    {                                                              //~v91sI~
        if (Goptopt2 & GOPT2_MODEINPUTL2U)                         //~v91sI~
        	Gutfmode2|=GUM2_KBDL2U; //ignore MODEINPUTL2U          //~v91sR~
    }                                                              //~v91sI~
#else                                                              //~va10R~
#ifdef AAA                                                         //~vbraI~
    if (Goptopt2 & GOPT2_MODEINPUTL2U)  //KBDUTF8 saved            //~va10I~
        Gutfmode2|=GUM2_KBDUTF8; 		//kbd mode is utf8         //~va10I~
#else                                                              //~vbraI~
#ifdef ARM                                                         //~vbraI~
	if (XEUTF8MODE_ENV_FORCE())                                    //~vbraR~
        Gutfmode2|=GUM2_KBDUTF8; 		//kbd mode is utf8         //~vbraI~
#endif                                                             //~vbraI~
    if (Goptopt3 & GOPT3_KBDUTF8BYCMD)  //KBDUTF8 saved            //~vbraI~
        Gutfmode2|=GUM2_KBDUTF8; 		//kbd mode is utf8         //~vbraI~
    else                                                           //~vbraI~
    if (Goptopt3 & GOPT3_KBDLCBYCMD)    //!KBDUTF8 saved           //~vbraI~
        Gutfmode2&=~GUM2_KBDUTF8; 		//kbd mode is utf8         //~vbraI~
#endif                                                             //~vbraI~
#ifdef UTF8UCS2                                                    //~va30I~
//  if (Goptopt2 & GOPT2_COMBINE)                                  //~va30I~//~vbr9R~
    if (Goptopt3 & GOPT3_COMBINE)                                  //~vbr9I~
    	Gulibutfmode|=GULIBUTFCOMBINE;                             //~va30R~
//#if defined(W32) && !defined(WXE)	//winconsole version           //~va3jR~
    if (Goptopt3 &  GOPT3_LIGATURE)                                //~va3hI~
    {                                                              //~vbf0I~
#if defined(W32) && !defined(WXE)                                  //~vbf0I~
	  if (OS_WINDOWS7(GWinMajVersion,GWinMinVersion))  //>=Widows7 //~vbf0R~
      	;                                                          //~vbf0I~
      else                                                         //~vbf0I~
#endif                                                             //~vbf0I~
      {                                                            //~vbf0I~
//		uviom_setopt2(UVIOMO2_LIGATURE,0/*displaychar*/);	//notify ligature//~va3jR~
        UTF_SET_LIGATUREMODE();                                    //~va3jI~
      }                                                            //~vbf0I~
    }                                                              //~vbf0I~
    if (Goptopt3 &  GOPT3_COMBINENP)                               //~vb4jI~
    	Gulibutfmode|=GULIBUTFCOMBINE_NP;                          //~vb4jR~
#if defined(LNX) && !defined(XXE)                                  //~va3sI~
  if (Goptopt3 &  GOPT3_COMBINENP)                                 //~vb4nI~
	uviom_notify(UVIOMNO_ALTCH,GoptcombaltchNP,0/*2nd parm*/);     //~vb4nI~
  else                                                             //~vb4nI~
	uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);       //~vbk1I~
#else                                                              //~vb4nI~
	uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);       //~vb4jR~
#endif                                                             //~vb4jR~
//#endif                                                           //~va3jR~
#endif                                                             //~va30I~
#endif                                                             //~va10I~
    UTRACEP("%s:new Goptopt2=%0x,Goptopt3=%0x,Gulibutfmode=%0x\n",UTT,Goptopt2,Goptopt3,Gulibutfmode);//~vb4jI~//~vbraR~
    return;                                                        //~v91sI~
}//xeopt2init                                                      //~v91sI~
#ifdef UTF8UCS2                                                    //~va30I~
//**************************************************************** //~vb2XI~
int optcombinehelpCP(int Popt,PUCLIENTWE Ppcw)                     //~vb2XI~
{                                                                  //~vb2XI~
#ifdef W32                                                         //~vb2XI~
  #ifndef WXE                                                      //~vb2XI~
    if (Gudbcschk_flag & UDBCSCHK_CONSCP)//ConsoleCP!=SYSTEM Default//~vb2XI~
	    uerrmsgcat(" ; Console CP=%d",0,ugetcp());                 //~vb2XI~
  #endif                                                           //~vb2XI~
#endif                                                             //~vb2XI~
	if (*Gparmlocalecode)                                          //~vb2XI~
	    uerrmsgcat(" with %cC%s",0,                                //~vb2XI~
						CMDFLAG_PREFIX,Gparmlocalecode);           //~vb2XI~
    return 0;                                                      //~vb2XI~
}//optcombinehelpCP                                                //~vb2XI~
//**************************************************************** //~va3sI~
//!optcombinehelp                                                  //~vb4nR~
//**************************************************************** //~va3sI~
//int optcombinehelp(int Popt,PUCLIENTWE Ppcw)                     //~vb4qR~
int optcombinehelpsub(int Popt,char **Ppcombine,char **Ppligature,char *Paltch)//~vb4qR~
{                                                                  //~va3sI~
	char *pmodecombine,*pmodeligature;                             //~va3sR~
	char *paltch;                                                  //~va3sI~
//#if defined(LNX) && !defined(XXE)                                //~vb4qR~
	char altch[12];                                                //~va3sR~
//#endif                                                           //~vb4qR~
//*********************************                                //~va3sI~
//  if (Goptopt2 & GOPT2_COMBINE)                                  //~va3sI~//~vbr9R~
    if (Goptopt3 & GOPT3_COMBINE)                                  //~vbr9I~
    	pmodecombine=OPT_COMBCOMBINE;                              //~va3sI~
    else                                                           //~va3sI~
    {                                                              //~va3sI~
    	if (Goptopt3 & GOPT3_COMBINENP)   //non printable          //~va3sR~
    		pmodecombine=OPT_COMBALTCH;                            //~va3sI~
    	else                                                       //~va3sR~
    		pmodecombine=OPT_COMBSPLIT;                            //~va3sI~
    }                                                              //~va3sI~
    if (OPT_ISLIGATUREON())                                        //~va3sI~
    	pmodeligature="ON";                                        //~va3sR~
    else                                                           //~va3sI~
    	pmodeligature="OFF";                                       //~va3sR~
 	paltch="";                                                     //~vb4nM~
 if (Popt & O2SHLCO_LIGATUREONLY)                                  //~vbCDR~
 {                                                                 //~vbCDR~
 	pmodecombine="";                                               //~vbCDR~
 }                                                                 //~vbCDR~
 else                                                              //~vbCDR~
 {                                                                 //~vbCDR~
//if (!(Goptopt2 & GOPT2_COMBINE))                                 //~vb4nI~//~vbr9R~
  if (!(Goptopt3 & GOPT3_COMBINE))                                 //~vbr9I~
  {                                                                //~vb4nM~
   if (Goptopt3 & GOPT3_COMBINENP)    //UNPR                       //~vb4nI~
   {                                                               //~vb4nI~
#if defined(LNX) && !defined(XXE)                                  //~vb4nI~
   	 sprintf(altch,"U-%04x",GoptcombaltchNP);                      //~vb4nR~
#else                                                              //~vb4nI~
   	 sprintf(altch,"U-%04x",Goptcombaltch);                        //~vb4nI~
#endif                                                             //~vb4nI~
     paltch=altch;                                                 //~vb4nI~
   }                                                               //~vb4nI~
#if defined(LNX) && !defined(XXE)                                  //~va3sI~
   else                                                            //~vb4nI~
   {                                                               //~vb4nI~
    switch(Goptcombaltch)                                          //~va3sI~
    {                                                              //~va3sI~
    case UVIOM_ALTCHPADDING:                                       //~va3sM~
        paltch=OPT_COMBPADDING;                                    //~va3sM~
        break;                                                     //~va3sI~
	case UVIOM_ALTCHSHADOW:                                        //~va3sI~
        paltch=OPT_COMBSHADOW;                                     //~va3sI~
    	break;                                                     //~va3sI~
    case UVIOM_ALTCHITSELF:                                        //~va3sI~
        paltch=OPT_COMBITSELF;                                     //~va3sI~
        break;                                                     //~va3sI~
    default:                                                       //~va3sI~
    	sprintf(altch,"U-%04x",Goptcombaltch);                     //~va3sR~
        paltch=altch;                                              //~va3sI~
    }                                                              //~va3sI~
   }                                                               //~vb4nI~
#endif                                                             //~va3sI~
  }//!combine                                                      //~vb4nI~
#if defined(LNX) && !defined(XXE)                                  //~vbk2I~
  else                                                             //~vbk2I~
  {                                                                //~vbk2I~
    switch(Goptcombaltch)                                          //~vbk2I~
    {                                                              //~vbk2I~
    case UVIOM_ALTCHPADDING:                                       //~vbk2I~
        paltch="(" OPT_COMBPADDING ")";                            //~vbk2I~
        break;                                                     //~vbk2I~
	case UVIOM_ALTCHSHADOW:                                        //~vbk2I~
        paltch="(" OPT_COMBSHADOW ")";                             //~vbk2I~
    	break;                                                     //~vbk2I~
    case UVIOM_ALTCHITSELF:                                        //~vbk2I~
        paltch="(" OPT_COMBITSELF ")";                             //~vbk2I~
        break;                                                     //~vbk2I~
    default:                                                       //~vbk2I~
    	sprintf(altch,"(U-%04x)",Goptcombaltch);                   //~vbk2I~
        paltch=altch;                                              //~vbk2I~
    }                                                              //~vbk2I~
  }                                                                //~vbk2I~
#endif                                                             //~vbk2I~
 }//!O2SHLCO_LIGATUREONLY                                          //~vbCDR~
  	*Ppcombine=pmodecombine;                                       //~vb4qR~
  	*Ppligature=pmodeligature;                                     //~vb4qR~
  	strcpy(Paltch,paltch);                                         //~vb4qR~
    return 0;                                                      //~vb4qR~
}//optcombinehelpsub                                               //~vb4qR~
//**************************************************************** //~vb4qR~
int optcombinehelp(int Popt,PUCLIENTWE Ppcw)                       //~vb4qR~
{                                                                  //~vb4qR~
	char *pmodecombine,*pmodeligature;                             //~vb4qR~
	char *paltch;                                                  //~vb4qR~
//#if defined(LNX) && !defined(XXE)                                //~vb4qR~
	char altch[20];                                                //~vb4qR~
//#endif                                                           //~vb4qR~
//*********************************                                //~vb4qR~
	optcombinehelpsub(Popt,&pmodecombine,&pmodeligature,altch);    //~vb4qR~
    paltch=altch;                                                  //~vb4qR~
    uerrmsgcat(" ; Current status: %s %s, Ligature: %s, Locale: %s",//~va3sI~
			 " ; 現況: %s %s, リガチャー: %s, ロケール: %s",       //~va3sI~
            pmodecombine,paltch,pmodeligature,                     //~va3sR~
            udbcschk_setlocale(UDCSLO_GETENV,LC_ALL,""));          //~va3sI~
	optcombinehelpCP(0,Ppcw);                                      //~vb2XI~
    return 0;                                                      //~va3sI~
}//optcombinehelp                                                  //~va3sI~
//**************************************************************** //~va3sI~
//!opt_contins                                                     //~va3sI~
//**************************************************************** //~va3sI~
int opt_ligature(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)        //~va3sI~
{                                                                  //~va3sI~
    UCHAR *pc;                                                     //~va3sI~
    int rc;                                                        //~va3sI~
//*********************************                                //~va3sI~
	if (!(pc=Ppcw->UCWparm)||*pc=='?')                             //~va3sR~
    {                                                              //~va3sI~
		uerrmsg("opt %s {ON | OFF}",0,                             //~va3sR~
				OPTCMD_LIGATURE);                                  //~va3sR~
		optcombinehelp(0,Ppcw);                                    //~va3sI~
		return 0;                                                  //~va3sI~
    }                                                              //~va3sI~
	rc=optoffonchk(pc,OPTOFC_ERRMSG);                              //~va3sI~
    if (rc>1)                                                      //~va3sI~
    	return rc;                                                 //~va3sI~
    if (rc==(OPT_ISLIGATUREON()!=0))                               //~va3sR~
    	return erralready();                                       //~va3sI~
	rc=func_optligature(Ppcw);                                     //~va3sR~
	return rc;                                                     //~va3sI~
}//opt_ligature                                                    //~va3sI~
//**************************************************************** //~va3sI~
//!opt_eol                                                         //~va3sI~
//* eol char specification                                         //~va3sI~
//*parm1:pcw(UCWparm:operand)                                      //~va3sI~
//*parm2:pot                                                       //~va3sI~
//*parm3:opd no                                                    //~va3sI~
//*retrn:rc                                                        //~va3sI~
//**************************************************************** //~va3sI~
int opt_combine(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)         //~va3sR~
{                                                                  //~va3sI~
static UCHAR *Swordtblcomb=OPT_COMBCOMBINE "\0"                    //~va3sR~
					   OPT_COMBALTCH "\0"                          //~va3sI~
					   OPT_COMBSPLIT "\0"                          //~va3sI~
#if defined(LNX) && !defined(XXE)                                  //~va3sR~
					   OPT_COMBSHADOW "\0"                         //~va3sI~
					   OPT_COMBITSELF "\0"                         //~va3sR~
					   OPT_COMBPADDING "\0"                        //~va3sI~
#endif                                                             //~va3sI~
                       ;                                           //~va3sI~
    UCHAR *pc;                                                     //~va3sR~
    int   opdno,ii,opid;                                           //~va3sR~
    int len;                                                       //~vbktI~
//#if defined(LNX) && !defined(XXE)                                //~vb4qR~
    LONG oldaltch,newaltch;                                        //~va3sR~
#if defined(LNX) && !defined(XXE)                                  //~vb4qR~
    LONG oldaltchNP;                                               //~vb4nI~
#endif                                                             //~va3sI~
//*********************************                                //~va3sI~
	if (!Ppcw->UCWparm||*Ppcw->UCWparm=='?')                       //~va3sR~
    {                                                              //~va3sI~
#if defined(LNX) && !defined(XXE)                                  //~va3sR~
		uerrmsg("opt %s [ %s | %s | %s ] [ %s | %s | %s | U-xxxx ]",0,//~va3sR~
			OPTCMD_COMBINE,                                        //~va3sI~
				OPT_COMBCOMBINE,                                   //~va3sM~
				OPT_COMBALTCH,                                     //~va3sM~
				OPT_COMBSPLIT,                                     //~va3sI~
				OPT_COMBSHADOW,                                    //~va3sR~
				OPT_COMBITSELF,                                    //~va3sR~
				OPT_COMBPADDING);                                  //~va3sR~
//        uerrmsgcat("(U-00 resets to '%c')",                      //~vb4pR~
//                   "(U-00 で '%c' に設定)",                      //~vb4pR~
//                XEOPT_DEFAULT_COMBALTCH);                        //~vb4pR~
#else                                                              //~va3sM~
//  	uerrmsg("opt %s { %s | %s | %s ]",0,                       //~vb4pR~
//    	uerrmsg("opt %s { %s | %s | %s | U-xxxx]",0,               //~vbDiR~
      	uerrmsg("opt %s [ %s | %s | %s | U-xxxx]",0,               //+vbDiR~
			OPTCMD_COMBINE,                                        //~va3sR~
				OPT_COMBCOMBINE,                                   //~va3sI~
				OPT_COMBALTCH,                                     //~va3sI~
				OPT_COMBSPLIT);                                    //~va3sI~
#endif                                                             //~va3sI~
		uerrmsgcat("(U-00 resets to '%c')",                        //~vb4pI~
		           "(U-00 で '%c' に設定)",                        //~vb4pI~
        		XEOPT_DEFAULT_COMBALTCH);                          //~vb4pI~
        optcombinehelp(0,Ppcw);                                    //~va3sR~
		return 0;                                                  //~va3sI~
    }                                                              //~va3sI~
    opdno=Ppcw->UCWopdno-1;           //funccmd created already    //~va3sR~
    pc=Ppcw->UCWopdpot;                                            //~va3sR~
    pc+=strlen(pc)+1;                                              //~va3sR~
#if defined(LNX) && !defined(XXE)                                  //~va3sI~
    oldaltch=Goptcombaltch;                                        //~vb4nI~
    oldaltchNP=GoptcombaltchNP;                                    //~vb4nI~
#else                                                              //~vb4nI~
    oldaltch=Goptcombaltch;                                        //~va3sR~
#endif                                                             //~va3sI~
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)   //next operand addr//~va3sR~
    {                                                              //~va3sR~
        switch(opid=wordtblisrch(pc,Swordtblcomb),opid)            //~va3sR~
        {                                                          //~va3sR~
        case 0: //unicode Xxxxx                                    //~va3sR~
//#if defined(LNX) && !defined(XXE)                                //~vb4nR~
//      	if (toupper(*pc)=='U')                                 //~va3sI~//~vbktR~
            len=(int)strlen(pc+1);                                 //~vbktI~
        	if (toupper(*pc)=='U'                                  //~vbktI~
            &&  unumlen(pc+1,UNUMLEN_HEX,len)==len)                //~vbktR~
            {                                                      //~va3sI~
            	pc++;                                              //~va3sR~
            	if (*pc=='-')                                      //~va3sR~
                	pc++;                                          //~va3sR~
            	sscanf(pc,"%4lx",&newaltch);                       //~va3sR~
                if (utfwcwidth(0,(ULONG)newaltch,0)!=1)            //~vbktR~
                {                                                  //~vbktI~
                    uerrmsg("U%s is not column width==1",0,        //~vbktR~
                        pc);                                       //~vbktI~
	        		return 4;                                      //~vbktR~
                }                                                  //~vbktI~
//          	Goptcombaltch=newaltch;                            //~va3sR~//~vb2ER~
//#ifdef W32                                                       //~vb4nR~
#if defined(LNX) && !defined(XXE)                                  //~vb4nI~
              if (newaltch)                                        //~vb4nM~
            	GoptcombaltchNP=(int)newaltch;                     //~vb4nM~
              else                                                 //~vb4nM~
            	GoptcombaltchNP=XEOPT_DEFAULT_COMBALTCH;           //~vb4nM~
#else                                                              //~vb4nM~
              if (newaltch)                                        //~vb4mI~
            	Goptcombaltch=(int)newaltch;                       //~vb2EI~
              else                                                 //~vb4mI~
            	Goptcombaltch=XEOPT_DEFAULT_COMBALTCH;             //~vb4mI~
#endif                                                             //~vb4nR~
            }                                                      //~va3sI~
            else                                                   //~va3sI~
//#endif                                                           //~vb4nR~
	        return errinvalid(pc);                                 //~va3sI~
            break;                                                 //~va3sR~
        case 1: //combine                                          //~va3sR~
//  	    if (Goptopt2 & GOPT2_COMBINE)                          //~va3sI~//~vbr9R~
    	    if (Goptopt3 & GOPT3_COMBINE)                          //~vbr9I~
                return erralready();                               //~va3sR~
//  		Goptopt2 |= GOPT2_COMBINE;                             //~va3sI~//~vbr9R~
    		Goptopt3 |= GOPT3_COMBINE;                             //~vbr9I~
    		Gulibutfmode|=GULIBUTFCOMBINE;                         //~va3sI~
//    		Goptopt3 &= ~GOPT3_COMBINENP;     //ON and printable   //~va3sI~//~vb2eR~
      		Goptopt3 &= (UCHAR)(~GOPT3_COMBINENP);     //ON and printable//~vb2eI~
    		Gulibutfmode&=~GULIBUTFCOMBINE_NP;                     //~vb4jR~
            break;                                                 //~va3sR~
        case 2: //altchar                                          //~va3sI~
    		if (Goptopt3 & GOPT3_COMBINENP)     //altchar mode     //~va3sI~
                return erralready();                               //~va3sI~
//	    	Goptopt2 &= ~GOPT2_COMBINE;                            //~va3sI~//~vb2eR~
//	    	Goptopt2 &= (UCHAR)(~GOPT2_COMBINE);                   //~vb2eI~//~vbr9R~
  	    	Goptopt3 &= (UCHAR)(~GOPT3_COMBINE);                   //~vbr9I~
    		Gulibutfmode&=~GULIBUTFCOMBINE;                        //~va3sI~
    		Goptopt3 |= GOPT3_COMBINENP;     //ON and printable    //~va3sI~
    		Gulibutfmode|=GULIBUTFCOMBINE_NP;                      //~vb4jR~
            break;                                                 //~va3sI~
        case 3: //split                                            //~va3sI~
    		if (!(Goptopt3 & GOPT3_COMBINENP)     //altchar mode   //~va3sI~
//          &&  !(Goptopt2 & GOPT2_COMBINE))                       //~va3sI~//~vbr9R~
            &&  !(Goptopt3 & GOPT3_COMBINE))                       //~vbr9I~
                return erralready();                               //~va3sI~
//      	Goptopt2 &= ~GOPT2_COMBINE;                            //~va3sI~//~vb2eR~
//      	Goptopt2 &= (UCHAR)(~GOPT2_COMBINE);                   //~vb2eI~//~vbr9R~
        	Goptopt3 &= (UCHAR)(~GOPT3_COMBINE);                   //~vbr9I~
    		Gulibutfmode&=~GULIBUTFCOMBINE;                        //~va3sI~
//  		Goptopt3 &= ~GOPT3_COMBINENP;     //ON and printable   //~va3sI~//~vb2eR~
    		Goptopt3 &= (UCHAR)(~GOPT3_COMBINENP);     //ON and printable//~vb2eI~
    		Gulibutfmode&=~GULIBUTFCOMBINE_NP;                     //~vb4jR~
            break;                                                 //~va3sI~
#if defined(LNX) && !defined(XXE)                                  //~va3sR~
        case 4: //shadow                                           //~va3sR~
            Goptcombaltch=UVIOM_ALTCHSHADOW;                       //~va3sR~
            break;                                                 //~va3sI~
        case 5: //itself                                           //~va3sI~
            Goptcombaltch=UVIOM_ALTCHITSELF;                       //~va3sR~
            break;                                                 //~va3sI~
        case 6: //padding                                          //~va3sI~
            Goptcombaltch=UVIOM_ALTCHPADDING;                      //~va3sR~
            break;                                                 //~va3sI~
#endif                                                             //~va3sI~
        }//opd                                                     //~va3sR~
    }//loop by operand no                                          //~va3sR~
#if defined(LNX) && !defined(XXE)                                  //~va3sI~
    if (oldaltch!=Goptcombaltch||oldaltchNP!=GoptcombaltchNP)      //~vb4nI~
    {                                                              //~vb4nI~
    	if (Goptopt3 & GOPT3_COMBINENP)     //altchar mode         //~vb4nI~
			uviom_notify(UVIOMNO_ALTCH,GoptcombaltchNP,0/*2nd parm*/);//~vb4nI~
        else                                                       //~vb4nI~
			uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);//~vb4nI~
                                                                   //~vb4nI~
	}                                                              //~vb4nI~
#else                                                              //~vb4nI~
    if (oldaltch!=Goptcombaltch)	                               //~va3sI~
		uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);   //~va3sI~
#endif                                                             //~vb4nI~
    uerrmsg("%s Done",0,                                           //~va3sI~
			OPTCMD_COMBINE);                                       //~va3sI~
	optcombinehelp(0,Ppcw);                                        //~va3sR~
    optresethdrligcomb(0,Ppcw);                                    //~vb4qR~
    scrfulldraw(Ppcw);                                             //~va3sR~
	return 0;                                                      //~va3sI~
}//opt_combine                                                     //~va3sR~
//**************************************************************** //~va30I~
//!func_optcombine                                                 //~va30I~
//**************************************************************** //~va30I~
int func_optcombine(PUCLIENTWE Ppcw)                               //~va30I~
{                                                                  //~va30I~
	char wkcombch[24],*pcombtype;                                  //~vb4kR~
//*********************************                                //~va30I~
    UTRACEP("%s:old opt2=%0x,opt3=%0x,Gulibutfmode=%0x\n",UTT,Goptopt2,Goptopt3,Gulibutfmode);//~vb4jI~
//  if (Goptopt2 & GOPT2_COMBINE)                                  //~va30R~//~vbr9R~
    if (Goptopt3 & GOPT3_COMBINE)                                  //~vbr9I~
    {                                                              //~va30I~
//*combine-->split                                                 //~vb4kI~
//  	Goptopt2 &= ~GOPT2_COMBINE;                                //~va30I~//~vb2eR~
//  	Goptopt2 &= (UCHAR)(~GOPT2_COMBINE);                       //~vb2eI~//~vbr9R~
    	Goptopt3 &= (UCHAR)(~GOPT3_COMBINE);                       //~vbr9I~
    	Gulibutfmode&=~GULIBUTFCOMBINE;                            //~va30M~
//  	Goptopt3 &= ~GOPT3_COMBINENP;     //ON and printable //~va3dI~//~va3eM~//~vb2eR~
    	Goptopt3 &= (UCHAR)(~GOPT3_COMBINENP);     //ON and printable//~vb2eI~
    	Gulibutfmode&=~GULIBUTFCOMBINE_NP;                         //~vb4jR~
#if defined(LNX) && !defined(XXE)                                  //~vb4nI~
        if (Goptcombaltch==UVIOM_ALTCHSHADOW)                      //~vb4kM~
            pcombtype=OPT_COMBSHADOW;                              //~vb4kM~
        else                                                       //~vb4kM~
        if (Goptcombaltch==UVIOM_ALTCHITSELF)                      //~vb4kM~
            pcombtype=OPT_COMBITSELF;                              //~vb4kM~
        else                                                       //~vb4kM~
        if (Goptcombaltch==UVIOM_ALTCHPADDING)                     //~vb4kM~
        {                                                          //~vb4kM~
			sprintf(wkcombch,"%s(=u-%02x)",OPT_COMBPADDING,(UINT)Guviomdbcspad);//~vb4kM~
        	pcombtype=wkcombch;                                    //~vb4kM~
        }                                                          //~vb4kM~
        else                                                       //~vb4kI~
        	pcombtype="";                                          //~vb4kI~
#endif                                                             //~vb4kM~
#if defined(LNX) && !defined(XXE)                                  //~vb4pI~
//      uerrmsg("No Combine Mode of UniChar",                      //~vb4kR~
        uerrmsg("Not combine, SPLIT Mode of UniChar(%s)",          //~vb4kI~
//				"分離\x95\\示モード(ユニコード結合文字)");         //~vb4mR~
  				"ユニコード結合文字:分離\x95\\示モード(%s)",       //~vb4kR~
        		pcombtype);                                        //~vb4kI~
#else                                                              //~vb4pI~
        uerrmsg("Not combine, SPLIT Mode of UniChar",              //~vb4pI~
  				"ユニコード結合文字:分離\x95\\示モード");          //~vb4pI~
#endif                                                             //~vb4pI~
//#ifdef WXE                                                       //~va3sR~
//        if (wxe_optligature(WXEIOLO_ISON,0))                     //~va3sR~
//#else                                                            //~va3sR~
//    #ifdef XXE                                                   //~va3sR~
//        if (xxe_optligature(XXEIOLO_ISON,0))                     //~va3sR~
//    #else                                                        //~va3sR~
//        if (UTF_LIGATUREMODE())                                  //~va3sR~
//    #endif                                                       //~va3sR~
//#endif                                                           //~va3sR~
		if (OPT_ISLIGATUREON())                                    //~va3sI~
    	    uerrmsgcat(" under Ligature mode:ON",0);               //~va3jI~
    }                                                              //~va30I~
    else                                                           //~va30I~
    {                                                              //~va30I~
      if (Goptopt3 & GOPT3_COMBINENP)   //non printable            //~va3eM~
      {                                                            //~va3eM~
//*UNPR-->COMBINE                                                  //~vb4kI~
//  	Goptopt2 |= GOPT2_COMBINE;                                 //~va30I~//~vbr9R~
    	Goptopt3 |= GOPT3_COMBINE;                                 //~vbr9I~
    	Gulibutfmode|=GULIBUTFCOMBINE;                             //~va30M~
//  	Goptopt3 &= ~GOPT3_COMBINENP;     //ON and printable       //~va3eI~//~vb2eR~
    	Goptopt3 &= (UCHAR)(~GOPT3_COMBINENP);     //ON and printable//~vb2eI~
    	Gulibutfmode&=~GULIBUTFCOMBINE_NP;                         //~vb4jR~
        uerrmsg("Combine Mode of UniChar",                         //~va3eR~
//  			"結合\x95\\示モード");                             //~vb4mR~
				"ユニコード結合文字:結合\x95\\示モード");          //~vb4mI~
//#ifdef WXE                                                       //~va3sR~
//        if (!wxe_optligature(WXEIOLO_ISON,0))                    //~va3sR~
//#else                                                            //~va3sR~
//    #ifdef XXE                                                   //~va3sR~
//        if (!xxe_optligature(XXEIOLO_ISON,0))                    //~va3sR~
//    #else                                                        //~va3sR~
//        if (!UTF_LIGATUREMODE())                                 //~va3sR~
//    #endif                                                       //~va3sR~
//#endif                                                           //~va3sR~
		if (!OPT_ISLIGATUREON())                                   //~va3sI~
//    	    uerrmsgcat(" under Ligature mode:OFF",0);              //~vb4mR~
      	    uerrmsgcat(" under Ligature mode:OFF",                 //~vb4mI~
      		           ";Ligature モード:OFF");                    //~vb4mR~
      }                                                            //~va3eI~
      else                                                         //~va3eR~
      {                                                            //~va3eR~
//*SPLIT-->UNPR                                                    //~vb4kI~
    	Goptopt3 |= GOPT3_COMBINENP;      //ON but unprintable     //~va3eR~
    	Gulibutfmode|=GULIBUTFCOMBINE_NP;                          //~vb4jR~
//      uerrmsg("Display Combining UniChar as Unprintable(Current CP:%s)",//~vb4jR~
//  			"代替文字\x95\\示モード(ユニコード結合文字); 現在のCP:%s",//~vb4jR~
#if defined(LNX) && !defined(XXE)                                  //~vb4nI~
		sprintf(wkcombch,"u-%02x",GoptcombaltchNP);                //~vb4nI~
#else                                                              //~vb4nI~
		sprintf(wkcombch,"u-%02x",Goptcombaltch);                  //~vb4kR~
#endif                                                             //~vb4nM~
        pcombtype=wkcombch;                                        //~vb4kR~
//      uerrmsg("Display Combining UniChar(u-%02x) as Unprintable(Current CP:%s)",//~vb4jI~//~vb4kR~
//    			"代替文字(u-%02x)\x95\\示モード(ユニコード結合文字); 現在のCP:%s",//~vb4jI~//~vb4kR~
        uerrmsg("Display Combining UniChar(%s) as Unprintable(Current CP:%s)",//~vb4kI~
      			"ユニコード結合文字:代替文字(%s)\x95\\示モード; 現在のCP:%s",//~vb4mI~
//  			Goptcombaltch,                                     //~vb4jI~//~vb4kR~
    			pcombtype,                                         //~vb4kI~
               udbcschk_setlocale(UDCSLO_GETENV,LC_ALL,""));       //~va3eR~
		optcombinehelpCP(0,Ppcw);                                  //~vb2XI~
      }                                                            //~va3eR~
    }                                                              //~va30I~
    if (!(Gulibutfmode & GULIBUTFCOMBINE))                         //~vb4nR~
    {                                                              //~vb4nI~
#if defined(LNX) && !defined(XXE)                                  //~vb4nI~
    	if (Goptopt3 & GOPT3_COMBINENP)     //altchar mode         //~vb4nI~
			uviom_notify(UVIOMNO_ALTCH,GoptcombaltchNP,0/*2nd parm*/);//~vb4nI~
    	else                                                       //~vb4nI~
			uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);//~vb4nI~
                                                                   //~vb4nI~
#else                                                              //~vb4nI~
		uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);   //~vb4nI~
#endif                                                             //~vb4nI~
	}                                                              //~vb4nI~
    else                                                           //~vbkxI~
    {                                                              //~vbkxI~
		uviom_notify(UVIOMNO_ALTCH,Goptcombaltch,0/*2nd parm*/);   //~vbkxI~
    }                                                              //~vbkxI~
    UTRACEP("%s:new opt2=%0x,opt3=%0x,Gulibutfmode=%0x\n",UTT,Goptopt2,Goptopt3,Gulibutfmode);//~vb4jI~
    optresethdrligcomb(0,Ppcw);                                    //~vb4qR~
	scrfulldraw(Ppcw);                                             //~va30I~
    return 0;                                                      //~va30I~
}//func_optcombine                                                 //~va30I~
//**************************************************************** //~va3dI~
//!func_optligature                                                //~va3dI~
//**************************************************************** //~va3dI~
int func_optligature(PUCLIENTWE Ppcw)                              //~va3dI~
{                                                                  //~va3dI~
//*********************************                                //~va3dI~
#ifndef XXE                                                        //~va3dI~
//#ifndef W32                                                      //~va3hR~
#ifndef UTF8UCS2                                                   //~va3hI~
	uerrmsg("\"Toggle Ligature\" is not supported for Linux Console version",0);//~va3hR~
    return 4;                                                      //~va3dI~
#else                                                              //~va3gI~
  #ifdef WXE                                                       //~va3hI~
	wxe_optligature(0,0/*value*/);                                 //~va3gR~
  #else                                                            //~va3hI~
//  if (uviom_setopt2(UVIOMO2_LIGATURE,0/*displaychar*/))          //~va3jR~
    if (!UTF_LIGATUREMODE())                                       //~va3jI~
    {                                                              //~va3hI~
#if defined(W32) && !defined(WXE)                                  //~vbf0R~
	    if (OS_WINDOWS7(GWinMajVersion,GWinMinVersion))  //>=Widows7//~vbf0I~
        {                                                          //~vbf0I~
			uerrmsg("Ligature mode is not supported for Console Version from Windows7.",0);//~vbf0R~
    		return 4;                                              //~vbf0I~
        }                                                          //~vbf0I~
#endif                                                             //~vbf0I~
//      Gutfmode2|=GUM2_CONSLIGATURE;                              //~va3jR~
        UTF_SET_LIGATUREMODE();                                    //~va3jI~
    	Goptopt3 |= GOPT3_LIGATURE;                                //~va3hI~
    	uerrmsg("Ligature ON (Current CP:%s)",                     //~va3jR~
        		0,                                                 //~va3jI~
               udbcschk_setlocale(UDCSLO_GETENV,LC_ALL,""));       //~va3jI~
		optcombinehelpCP(0,Ppcw);                                  //~vb2XI~
    }                                                              //~va3hI~
    else                                                           //~va3hI~
    {                                                              //~va3hI~
//      Gutfmode2&=~GUM2_CONSLIGATURE;                             //~va3jR~
        UTF_RESET_LIGATUREMODE();                                  //~va3jI~
//  	Goptopt3 &=~GOPT3_LIGATURE;                                //~va3hI~//~vb2eR~
    	Goptopt3 &=(UCHAR)(~GOPT3_LIGATURE);                       //~vb2eI~
    	uerrmsg("Ligature OFF",0);                                 //~va3hI~
    }                                                              //~va3hI~
  #endif                                                           //~va3hI~
	optresethdrligcomb(0,Ppcw);                                    //~vb4qR~
	scrfulldraw(Ppcw);                                             //~va3gI~
    return 0;                                                      //~va3gI~
#endif                                                             //~va3gI~
#else                                                              //~va3dI~
	xxe_optligature(0/*toogle temporary*/,0/*value*/);	           //~va3hR~
	optresethdrligcomb(0,Ppcw);                                    //~vb4qI~
	scrfulldraw(Ppcw);                                             //~va3dI~
    return 0;                                                      //~va3dI~
#endif                                                             //~va3dI~
}//func_optligature                                                //~va3dR~
#endif                                                             //~va30I~
//#ifdef UTF8SUPP                                                    //~va0xI~//~vbraR~
////****************************************************************//~vbraR~
////!func_opt                                                      //~vbraR~
////* option commnad                                               //~vbraR~
////*parm1:pcw(UCWparm:operand)                                    //~vbraR~
////*retrn:rc                                                      //~vbraR~
////****************************************************************//~vbraR~
//int func_mode(PUCLIENTWE Ppcw)                                     //~v90wR~//~vbraR~
//{                                                                  //~v90wI~//~vbraR~
//static UCHAR *Swordtbl=MODE_UTF8 "\0"                              //~v90wI~//~vbraR~
//                       MODE_LOCALE "\0"                            //~v90wI~//~vbraR~
//                       MODE_ASIS "\0"                              //~v915I~//~vbraR~
//                       MODE_SWKBD "\0"                             //~v917I~//~vbraR~
//                       ;                                           //~v90wI~//~vbraR~
//    int ii,opdno,swcp=0,rc=0,swfile,swdir,oldutf8,newutf8;         //~v91hR~//~vbraR~
//    int swnocpchange=0,oldutf8p,swsetutf8p=0;                      //~v92iR~//~vbraR~
//    PUFILEC pfc=0;                                                 //~v90wI~//~vbraR~
//    PUFILEH pfh=0;                                                 //~v90wI~//~vbraR~
//    char *pc,*pnewcp;                                              //~v90wI~//~vbraR~
////*********************************                                //~v90wI~//~vbraR~
//    if (!XEUTF8MODE())                                             //~v90wI~//~vbraR~
//    {                                                              //~v90wI~//~vbraR~
////      uerrmsg("Mode cmd is not avail when UTF8 mode prohibit by cmdline option",//~v91HR~//~vbraR~
////              "Modeコマンドはコマンドラインオプション指定により使用できません");//~v91HR~//~vbraR~
//        errnotsupported("UTF cmd","Non-UTF8 mode");                //~v929R~//~vbraR~
//        return 4;                                                  //~v90wI~//~vbraR~
//    }                                                              //~v90wI~//~vbraR~
////*operand chk                                                     //~v90wI~//~vbraR~
//  if (Ppcw->UCWkeytype==UCWKTCMD)                                  //~v917I~//~vbraR~
//  {                                                                //~v917I~//~vbraR~
//    opdno=Ppcw->UCWopdno;                                          //~v90wI~//~vbraR~
//    pc=Ppcw->UCWopdpot;                                            //~v90wI~//~vbraR~
//  }                                                                //~v917I~//~vbraR~
//  else                                                             //~v917I~//~vbraR~
//  {                                                                //~v917I~//~vbraR~
//    opdno=1;                                                       //~v917I~//~vbraR~
//    pc=MODE_SWKBD;      //by A+u key                               //~v917I~//~vbraR~
//  }                                                                //~v917I~//~vbraR~
//    swfile=(Ppcw->UCWtype==UCWTFILE);                              //~v91hR~//~vbraR~
//    swdir=(Ppcw->UCWtype==UCWTDIR);                                //~v91hI~//~vbraR~
//    if (swfile                                                     //~v91hR~//~vbraR~
//    ||  swdir)                                                     //~v91hR~//~vbraR~
//    {                                                              //~v90wI~//~vbraR~
//        pfc=Ppcw->UCWpfc;                                          //~v90wI~//~vbraR~
//        pfh=pfc->UFCpfh;                                           //~v90wI~//~vbraR~
//    }                                                              //~v90wI~//~vbraR~
//    oldutf8=((swfile && FILEUTF8MODE(pfh)) || (swdir && UCBITCHK(pfc->UFCflag2,UFCF2UTF8)));//~v91hR~//~vbraR~
//    oldutf8p=((swfile && UCBITCHK(pfh->UFHflag8,UFHF8UTF8P))       //~v92iI~//~vbraR~
//          ||  (swdir  && UCBITCHK(pfc->UFCflag2,UFCF2UTF8P)));     //~v92iI~//~vbraR~
//    if (!opdno)     //operand                                      //~v90wI~//~vbraR~
//    {                                                              //~v90wI~//~vbraR~
//        rc=funcmodehelp();                                         //~v90wI~//~vbraR~
//        if (pfh)                                                   //~v90wI~//~vbraR~
//        {                                                          //~v90wI~//~vbraR~
//            if (oldutf8)                                           //~v91hR~//~vbraR~
//                uerrmsgcat("; This file's mode is %s",0,MODE_UTF8);//~v90wR~//~vbraR~
//            else                                                   //~v90wI~//~vbraR~
//              if (UTF8MODEENV()) //env is utf8(linux locale=utf8)  //~v91hR~//~vbraR~
//                uerrmsgcat("; This file's mode is %s",0,MODE_LOCALE);//~v90wR~//~vbraR~
//              else                                                 //~v915I~//~vbraR~
//                uerrmsgcat("; This file's mode is %s",0,MODE_ASIS);//~v915I~//~vbraR~
//        }                                                          //~v90wI~//~vbraR~
//        return rc;                                                 //~v90wI~//~vbraR~
//    }                                                              //~v90wI~//~vbraR~
//    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)   //next operand addr//~v90wI~//~vbraR~
//    {                                                              //~v90wI~//~vbraR~
//        swcp=wordtblisrch(pc,Swordtbl);                            //~v917R~//~vbraR~
//        if (!swcp)                                                 //~v917R~//~vbraR~
//            return errinvalid(pc);                                 //~v90wI~//~vbraR~
////*process                                                         //~v90wI~//~vbraR~
//      if (swcp==4)                                                 //~v917I~//~vbraR~
//      {                                                            //~v917I~//~vbraR~
//        if (UTF8MODEENV()) //env is utf8(linux locale=utf8)        //~v91hR~//~vbraR~
//        {                                                          //~v917I~//~vbraR~
//            Gutfmode2^=GUM2_KBDU2L;    //sawp u2l<-->utf           //~v91sR~//~vbraR~
//            if (Ppcw->UCWkeytype==UCWKTCMD)                        //~v917I~//~vbraR~
//            {                                                      //~v917I~//~vbraR~
//                if (Gutfmode2 & GUM2_KBDU2L)                       //~v91sR~//~vbraR~
//                    uerrmsg("Kbd switched to U2L conversion mode",0);//~v917R~//~vbraR~
//                else                                               //~v917I~//~vbraR~
//                    uerrmsg("Kbd switched to UTF8 mode",0);        //~v917R~//~vbraR~
//            }                                                      //~v917I~//~vbraR~
//#ifdef LNX                                                         //~v91dI~//~vbraR~
//            else                                                   //~v91dI~//~vbraR~
//            {                                                      //~v91dI~//~vbraR~
//                rc=utfcvlocaleinit(UTFCLIO_NULLCHKONLY,Glocalecode);    //notify to ulib//~v91dI~//~vbraR~
//            }                                                      //~v91dI~//~vbraR~
//#endif                                                             //~v91dI~//~vbraR~
//        }                                                          //~v917I~//~vbraR~
//        else                                                       //~v917I~//~vbraR~
//        {                                                          //~v917I~//~vbraR~
//            Gutfmode2^=GUM2_KBDL2U;    //swap l2u<-->locale        //~v91sR~//~vbraR~
//            if (Ppcw->UCWkeytype==UCWKTCMD)                        //~v917I~//~vbraR~
//            {                                                      //~v917I~//~vbraR~
//                if (Gutfmode2 & GUM2_KBDL2U)                       //~v91sR~//~vbraR~
//                    uerrmsg("Kbd switched to L2U conversion mode",0);//~v917R~//~vbraR~
//                else                                               //~v917I~//~vbraR~
//                    uerrmsg("Kbd switched to Locale mode",0);      //~v917R~//~vbraR~
//            }                                                      //~v917I~//~vbraR~
//        }                                                          //~v917I~//~vbraR~
//        UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);  //redraw for by A+u//~v917I~//~vbraR~
//      }                                                            //~v917I~//~vbraR~
//      else                                                         //~v917I~//~vbraR~
//      {                                                            //~v917I~//~vbraR~
//        if (!pfh)                                                  //~v90wI~//~vbraR~
//        {                                                          //~v90wI~//~vbraR~
//            uerrmsg("Use on File/Dir panel",                       //~v91hR~//~vbraR~
//                    "ファイル/Dir 画面で使用してください");        //~v91hR~//~vbraR~
//            return 4;                                              //~v90wI~//~vbraR~
//        }                                                          //~v90wI~//~vbraR~
//        if (swcp==1)    //to UTF8                                  //~v90wI~//~vbraR~
//        {                                                          //~v90wI~//~vbraR~
//            fcmdprofupdaterecord(FPURO_CP,pfh->UFHfilename,0,1/*utf8*/,0/*intval2*/);//~v78wR~//~vbraR~
//            if (oldutf8)                                           //~v91hR~//~vbraR~
////              return erralready();                               //~v92iR~//~vbraR~
//                swnocpchange=1;                                    //~v92iI~//~vbraR~
//            if (!oldutf8p)                                         //~v92iI~//~vbraR~
//                swsetutf8p=1;   //set UTF8P on                     //~v92iI~//~vbraR~
//            newutf8=1;                                             //~v91hI~//~vbraR~
//            pnewcp=MODE_UTF8;                                      //~v90wR~//~vbraR~
//        }                                                          //~v90wI~//~vbraR~
//        else             //to locale                               //~v90wI~//~vbraR~
//        if (swcp==3)    //ASIS                                     //~v915I~//~vbraR~
//        {                                                          //~v915I~//~vbraR~
//            fcmdprofupdaterecord(FPURO_CP,pfh->UFHfilename,0,0/*asis*/,0/*intval2*/);//~v78wR~//~vbraR~
//            if (UTF8MODEENV()) //env is utf8(linux locale=utf8)    //~v91hR~//~vbraR~
//            {                                                      //~v915I~//~vbraR~
//                if (oldutf8)                                       //~v91hR~//~vbraR~
////                  return erralready();                           //~v92iR~//~vbraR~
//                    swnocpchange=1;                                //~v92iI~//~vbraR~
//                newutf8=1;                                         //~v91hI~//~vbraR~
//            }                                                      //~v915I~//~vbraR~
//            else                                                   //~v915I~//~vbraR~
//            {                                                      //~v915I~//~vbraR~
//                if (!oldutf8)                                      //~v91hR~//~vbraR~
////                  return erralready();                           //~v92iR~//~vbraR~
//                    swnocpchange=1;                                //~v92iI~//~vbraR~
//                newutf8=0;                                         //~v91hI~//~vbraR~
//            }                                                      //~v915I~//~vbraR~
//            if (oldutf8p)                                          //~v92iI~//~vbraR~
//                swsetutf8p=-1;  //set UTF8P off                    //~v92iI~//~vbraR~
//            pnewcp=MODE_ASIS;                                      //~v915I~//~vbraR~
//        }                                                          //~v915I~//~vbraR~
//        else             //to locale                               //~v915I~//~vbraR~
//        {                                                          //~v90wI~//~vbraR~
//            fcmdprofupdaterecord(FPURO_CP,pfh->UFHfilename,0,-1/*locale*/,0/*intval2*/);//~v78wR~//~vbraR~
//            if (!oldutf8)                                          //~v91hR~//~vbraR~
////              return erralready();                               //~v92iR~//~vbraR~
//                swnocpchange=1;                                    //~v92iI~//~vbraR~
//            newutf8=0;                                             //~v91hI~//~vbraR~
//            pnewcp=MODE_LOCALE;                                    //~v90wR~//~vbraR~
//            if (!oldutf8p)                                         //~v92iI~//~vbraR~
//                swsetutf8p=1;   //set UTF8P on;                    //~v92iI~//~vbraR~
//        }                                                          //~v90wI~//~vbraR~
//        if (newutf8)                                               //~v91hR~//~vbraR~
//            if (swfile)                                            //~v91hI~//~vbraR~
//                UCBITON(pfh->UFHflag8,UFHF8UTF8);                  //~v91hI~//~vbraR~
//            else                                                   //~v91hI~//~vbraR~
//                UCBITON(pfc->UFCflag2,UFCF2UTF8);                  //~v91hI~//~vbraR~
//        else                                                       //~v91hI~//~vbraR~
//            if (swfile)                                            //~v91hI~//~vbraR~
//                UCBITOFF(pfh->UFHflag8,UFHF8UTF8);                 //~v91hI~//~vbraR~
//            else                                                   //~v91hI~//~vbraR~
//                UCBITOFF(pfc->UFCflag2,UFCF2UTF8);                 //~v91hR~//~vbraR~
//        if (swsetutf8p>0)                                          //~v92iR~//~vbraR~
//        {                                                          //~v92iI~//~vbraR~
//            if (swfile)                                            //~v92iI~//~vbraR~
//                UCBITON(pfh->UFHflag8,UFHF8UTF8P);                 //~v92iI~//~vbraR~
//            else                                                   //~v92iI~//~vbraR~
//                UCBITON(pfc->UFCflag2,UFCF2UTF8P);                 //~v92iI~//~vbraR~
//        }                                                          //~v92iI~//~vbraR~
//        else             //utf8 or locale                          //~v92iR~//~vbraR~
//        if (swsetutf8p<0)                                          //~v92iI~//~vbraR~
//        {                                                          //~v92iI~//~vbraR~
//            if (swfile)                                            //~v92iI~//~vbraR~
//                UCBITOFF(pfh->UFHflag8,UFHF8UTF8P);  //explicitly specified id//~v92iI~//~vbraR~
//            else                                                   //~v92iI~//~vbraR~
//                UCBITOFF(pfc->UFCflag2,UFCF2UTF8P);                //~v92iI~//~vbraR~
//        }                                                          //~v92iI~//~vbraR~
//                                                                   //~v92iI~//~vbraR~
////  }//loop by operand no                                          //~v92pR~//~vbraR~
//    if (swnocpchange && !swsetutf8p)                               //~v92iR~//~vbraR~
//    {                                                              //~v92iI~//~vbraR~
//        uerrmsg("CodePage is NOT changed, but registered to profile record",//~v92iI~//~vbraR~
//                "コードページの変更はありませんがプロファイルに記録しました");//~v92iR~//~vbraR~
//    }                                                              //~v92iI~//~vbraR~
//    else                                                           //~v92iI~//~vbraR~
//    {                                                              //~v92iI~//~vbraR~
//      if (swfile)                                                  //~v91hR~//~vbraR~
//      {                                                            //~v91hI~//~vbraR~
//        filesetlocaleid(pfh);                                      //~v915I~//~vbraR~
//       if (!swnocpchange)                                          //~v92iI~//~vbraR~
//        funcmoderesetdbcstbl(Ppcw,pfh);                            //~v90wR~//~vbraR~
//      }                                                            //~v91hI~//~vbraR~
//      else                                                         //~v91hM~//~vbraR~
//        dirsetlocaleid(0,pfc,0/*psddata*/);                        //~v91hM~//~vbraR~
//        uerrmsg("CodePage changed to %s",                          //~v90wI~//~vbraR~
//                    "コードページを %s に変更",                    //~v90wI~//~vbraR~
//                pnewcp);                                           //~v90wI~//~vbraR~
////    }//!swkbd                                                    //~v92pR~//~vbraR~
//    }                                                              //~v92iI~//~vbraR~
//    }//!swkbd(swcp==4)                                             //~v92pI~//~vbraR~
////  }//loop by operand no                                          //~v92iR~//~vbraR~
//    }//loop by operand no                                          //~v92pI~//~vbraR~
//    return rc;                                                     //~v91dR~//~vbraR~
//}//func_mode                                                       //~v90wR~//~vbraR~
//#endif  //UTF8SUPP                                                 //~va0xR~//~vbraR~
//**************************************************************** //~va0xI~
//!func_mode                                                       //~va7KR~
//* utf8 mode setting                                              //~va7KR~
//*retrn:rc                                                        //~va0xI~
//**************************************************************** //~va0xI~
int func_mode(PUCLIENTWE Ppcw)                                     //~v90wR~//~va0xI~
{                                                                  //~v90wI~//~va0xI~
static UCHAR *Swordtbl=                                            //~va0xR~
					   MODE_SWKBD "\0"                             //~v917I~//~va0xI~
                       OPT_FILE "\0"                               //~va1pR~
                       OPT_FILENAME "\0"                           //~va1pR~
                       MODE_UTF8 "\0"                              //~va1pI~
					   MODE_LOCALE "\0"                            //~va1pI~
					   MODE_ASIS "\0"                              //~va1pI~
					   MODE_RETRYCPLC "\0"  //7                    //~va1NI~
					   MODE_NORETRYCPLC "\0"  //8                  //~va1NI~
                       ;                                           //~v90wI~//~va0xI~
    int ii,opdno,swcp=0,rc=0;         //~v91hR~                    //~va0xR~
    int cpopt=0,optold=0;                                          //~vaf9R~
    char *pc;                                              //~v90wI~//~va0xR~
//*********************************                                //~v90wI~//~va0xI~
//*operand chk                                                     //~v90wI~//~va0xI~
  if (Ppcw->UCWkeytype==UCWKTCMD)                                  //~v917I~//~va0xI~
  {                                                                //~v917I~//~va0xI~
    opdno=Ppcw->UCWopdno;                                          //~v90wI~//~va0xI~
    pc=Ppcw->UCWopdpot;                                            //~v90wI~//~va0xI~
  }                                                                //~v917I~//~va0xI~
  else                                                             //~v917I~//~va0xI~
  {                                                                //~v917I~//~va0xI~
  	opdno=1;                                                       //~v917I~//~va0xI~
    pc=MODE_SWKBD;		//by A+u key                               //~v917I~//~va0xI~
  }                                                                //~v917I~//~va0xI~
	if (!opdno)		//operand                                      //~v90wI~//~va0xI~
    {                                                              //~v90wI~//~va0xI~
        rc=funcmodehelp();                                         //~v90wI~//~va0xI~
        return rc;                                                 //~v90wI~//~va0xI~
    }                                                              //~v90wI~//~va0xI~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v90wI~//~va0xI~
	{                                                              //~v90wI~//~va0xI~
        swcp=wordtblisrch(pc,Swordtbl);                            //~v917R~//~va0xI~
        if (!swcp)                                                 //~v917R~//~va0xI~
        	return errinvalid(pc);                                 //~v90wI~//~va0xI~
//*process                                                         //~v90wI~//~va0xI~
#ifdef OLDA10                                                      //~va10I~
	    if (XEUTF8MODE_ENV()) //env is utf8(linux locale=utf8)        //~v91hR~//~va0xR~
        {                                                          //~v917I~//~va0xI~
        	Gutfmode2^=GUM2_KBDU2L;    //sawp u2l<-->utf           //~v91sR~//~va0xI~
	    	if (Ppcw->UCWkeytype==UCWKTCMD)                        //~v917I~//~va0xI~
            {                                                      //~v917I~//~va0xI~
            	if (Gutfmode2 & GUM2_KBDU2L)                       //~v91sR~//~va0xI~
                	uerrmsg("Kbd switched to U2L conversion mode",0);//~v917R~//~va0xI~
                else                                               //~v917I~//~va0xI~
                	uerrmsg("Kbd switched to UTF8 mode",0);        //~v917R~//~va0xI~
            }                                                      //~v917I~//~va0xI~
            if (Gutfmode2 & GUM2_KBDU2L)    //sawp u2l<-->utf      //~va0xI~
            	Goptopt2|=GOPT2_MODEINPUTU2L;                      //~va0xI~
            else                                                   //~va0xI~
            	Goptopt2&=~GOPT2_MODEINPUTU2L;                     //~va0xI~
        }                                                          //~v917I~//~va0xI~
        else                                                       //~v917I~//~va0xI~
        {                                                          //~v917I~//~va0xI~
        	Gutfmode2^=GUM2_KBDL2U;    //swap l2u<-->locale        //~v91sR~//~va0xI~
	    	if (Ppcw->UCWkeytype==UCWKTCMD)                        //~v917I~//~va0xI~
            {                                                      //~v917I~//~va0xI~
            	if (Gutfmode2 & GUM2_KBDL2U)                       //~v91sR~//~va0xI~
                	uerrmsg("Kbd switched to L2U conversion mode",0);//~v917R~//~va0xI~
                else                                               //~v917I~//~va0xI~
                	uerrmsg("Kbd switched to Locale mode",0);      //~v917R~//~va0xI~
            }                                                      //~v917I~//~va0xI~
            if (Gutfmode2 & GUM2_KBDL2U)    //sawp u2l<-->utf      //~va0xI~
            	Goptopt2|=GOPT2_MODEINPUTL2U;                      //~va0xI~
            else                                                   //~va0xI~
            	Goptopt2&=~GOPT2_MODEINPUTL2U;                     //~va0xI~
        }                                                          //~v917I~//~va0xI~
#else   //NEWA10                                                   //~va10I~
    	optold=Goptopt2;                                           //~va1pR~
      switch(swcp)                                                 //~va1pI~
      {                                                            //~va1pI~
      case 1:	//SWKBD                                            //~va1pI~
//#ifdef ARM                                                       //~vbraR~
//            uerrmsg("SWKBD is not valid, Axe's kbd is always UTF8 input",//~vbraR~
//                    "SWKBD は Axe では無効です、Axeは入力は UTF8 固定です");//~vbraR~
//            return 4;                                            //~vbraR~
//#else                                                            //~vbraR~
        Gutfmode2^=GUM2_KBDUTF8;    //swap                         //~va10I~
        if (Ppcw->UCWkeytype==UCWKTCMD)                            //~va10I~
        {                                                          //~va10I~
            if (Gutfmode2 & GUM2_KBDUTF8)                          //~va10I~
                uerrmsg("Kbd switched to UTF8 mode",0);            //~va10I~
            else                                                   //~va10I~
                uerrmsg("Kbd switched to Locale mode",0);          //~va10I~
        }                                                          //~va10I~
#ifdef AAA                                                         //~vbraI~
        if (Gutfmode2 & GUM2_KBDUTF8)                              //~va10I~
            Goptopt2|=GOPT2_MODEINPUTL2U;	//save to ini file     //~va10I~
        else                                                       //~va10I~
//          Goptopt2&=~GOPT2_MODEINPUTL2U;                         //~va10I~//~vb2eR~
            Goptopt2&=(UCHAR)(~GOPT2_MODEINPUTL2U);                //~vb2eI~
#else                                                              //~vbraI~
        if (Gutfmode2 & GUM2_KBDUTF8)                              //~vbraI~
        {                                                          //~vbraI~
	    	Goptopt3|=GOPT3_KBDUTF8BYCMD;                          //~vbraI~
	    	Goptopt3&=(UCHAR)(~GOPT3_KBDLCBYCMD);                  //~vbraR~
        }                                                          //~vbraI~
        else                                                       //~vbraI~
        {                                                          //~vbraI~
	    	Goptopt3&=(UCHAR)(~GOPT3_KBDUTF8BYCMD);                //~vbraR~
	    	Goptopt3|=GOPT3_KBDLCBYCMD;                            //~vbraI~
        }                                                          //~vbraI~
#endif                                                             //~vbraI~
		scrfulldraw(Ppcw);                                         //~va1tI~
//#endif //!ARM                                                    //~vbraR~
        break;                                                     //~va1pI~
      case 2:	//FILE                                             //~va1pI~
      	cpopt=1;                                                   //~va1pI~
        break;                                                     //~va1pI~
      case 3:	//FILENAME                                         //~va1pI~
      	cpopt=2;                                                   //~va1pI~
        break;                                                     //~va1pI~
      case 7:	//RETRYCPLC                                        //~va1NI~
        UCBITOFF(Goptopt2,GOPT2_NORETRYCPLC);                      //~va1NI~
        break;                                                     //~va1NI~
      case 8:	//NORETRYCPLC                                      //~va1NI~
        UCBITON(Goptopt2,GOPT2_NORETRYCPLC);                       //~va1NI~
        break;                                                     //~va1NI~
      default:                                                     //~va1pI~
        if (!cpopt)                                                //~va1pI~
        {                                                          //~va1NI~
            uerrmsg("specify %s or %s before this(%s)",0,          //~va1pI~
            		OPT_FILE,OPT_FILENAME,pc);                     //~va1pI~
            return 4;                                              //~va1NI~
        }                                                          //~va1NI~
        if (cpopt==1)	//for file                                 //~va1pR~
        {                                                          //~va1pI~
		    switch(swcp)                                           //~va1pI~
            {                                                      //~va1pI~
        	case 4: //file utf8                                    //~va1pI~
            	UCBITON(Goptopt2,GOPT2_ALLFILEUTF8);               //~va1pI~
            	UCBITOFF(Goptopt2,GOPT2_ALLFILELOCALE);            //~va1pI~
            	break;                                             //~va1pI~
        	case 5: //file local                                   //~va1pI~
            	UCBITOFF(Goptopt2,GOPT2_ALLFILEUTF8);              //~va1pI~
            	UCBITON(Goptopt2,GOPT2_ALLFILELOCALE);             //~va1pI~
	            break;                                             //~va1pI~
            default:                                               //~va1pI~
            	UCBITOFF(Goptopt2,GOPT2_ALLFILELOCALE|GOPT2_ALLFILEUTF8);//~va1pI~
            }                                                      //~va1pI~
        }                                                          //~va1pI~
        else                                                       //~va1pI~
        {                                                          //~va1pI~
		    switch(swcp)                                           //~va1pI~
            {                                                      //~va1pI~
        	case 4: //file utf8                                    //~va1pI~
            	UCBITON(Goptopt2,GOPT2_ALLFNUTF8);                 //~va1pI~
            	UCBITOFF(Goptopt2,GOPT2_ALLFNLOCALE);              //~va1pI~
            	break;                                             //~va1pI~
        	case 5: //file local                                   //~va1pI~
            	UCBITOFF(Goptopt2,GOPT2_ALLFNUTF8);                //~va1pI~
            	UCBITON(Goptopt2,GOPT2_ALLFNLOCALE);               //~va1pI~
	            break;                                             //~va1pI~
            default:                                               //~va1pI~
            	UCBITOFF(Goptopt2,GOPT2_ALLFNLOCALE|GOPT2_ALLFNUTF8);//~va1pI~
            }                                                      //~va1pI~
        }                                                          //~va1pI~
        break;                                                     //~va1pI~
      }                                                            //~va1pI~
#endif  //NEWA10                                                   //~va10I~
//  	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);  //redraw for by A+u//~v917I~//~va0xI~//~va1tR~
    }//loop by operand no                                          //~v92pI~//~va0xI~
    if (swcp!=1)	//not wskbd                                    //~va1pI~
		opt_modestatus(((optold!=Goptopt2)+1),Goptopt2);    //display status//~va1pR~
	return rc;                                                     //~v91dR~//~va0xI~
}//func_mode                                                       //~v90wR~//~va0xI~
//**************************************************************** //~vbB4I~
void displayEbcCfgStatus(PUCLIENTWE Ppcw)                          //~vbB4I~
{                                                                  //~vbB4I~
    char msg[256];                                                 //~vbB4I~//~vbB7R~
    int handle=0;                                                  //~vbB4I~//~vbB7R~
    char *cvtype,*sjisopt=0;                                       //~vbB4R~
    char wkcvn[MAX_CSNAMESZ*2+4];                                  //~vbB7I~
    //**********************                                       //~vbB4I~
//  char *pcvname=ucvebc4_getcvname(0,handle);                     //~vbB4I~//~vbB7R~
    UCVEXTCFG *pcfg=ucvext_getpcfg(0);                             //~vbB4R~
    char *pcvnDbcs=pcfg->UCECcsnamedbcs;                           //~vbB7R~
    char *pcvnSbcs=pcfg->UCECcsnamesbcs;                           //~vbB7R~
    if (*pcvnDbcs)                                                 //~vbB7I~
//    	if (*pcvnSbcs)                                             //~vbB7I~//~v7biR~
      	if (*pcvnSbcs && strcmp(pcvnDbcs,pcvnSbcs))                //~vbBiR~
        	sprintf(wkcvn,"%s+%s",pcvnDbcs,pcvnSbcs);              //~vbB7I~
        else                                                       //~vbB7I~
        	strcpy(wkcvn,pcvnDbcs);                                //~vbB7I~
    else                                                           //~vbB7I~
        strcpy(wkcvn,pcvnSbcs);                                    //~vbB7I~
    if (pcfg->UCECflag & UCECF_OPENERR)                            //~vbB4R~
    {                                                              //~vbB7I~
    	cvtype="No cfg File";  //also swNoName ON                  //~vbB4R~
		char *pcvname=ucvebc4_getcvname(0,handle);                 //~vbB7I~
        strcpy(wkcvn,pcvname);                                     //~vbB7I~
    }                                                              //~vbB7I~
    else                                                           //~vbB4R~
    if (pcfg->UCECflag & UCECF_USE_ICU)                            //~vbB4R~
        cvtype="CONVERTER=1";                                      //~vbB4R~
    else                                                           //~vbB4R~
    if (pcfg->UCECflag & UCECF_USE_ICONV)                          //~vbB4R~
        cvtype="CONVERTER=2";                                      //~vbB4I~
    else                                                           //~vbB4I~
    {                                                              //~vbB4I~
        cvtype="CONVERTER=0";                                      //~vbB4I~
//      strcat(wkcvn,TBLMAPPINGID);	//-Internal                    //~vbB7R~
		char *pcvname=ucvebc4_getcvname(0,handle);                 //~vbB7M~
        strcpy(wkcvn,pcvname);                                     //~vbB7M~
//        if (pcfg->UCECflag2 & UCECF2_BASE)                         //~vbB7I~//~v7dmR~
//            sjisopt=EBCID_BASE;                                    //~vbB7I~//~v7dmR~
//        else                                                       //~vbB7I~//~v7dmR~
//        if (pcfg->UCECflag2 & UCECF2_CP931)                        //~vbB9I~//~vbBsR~
//            sjisopt=EBCID_LATIN;                                   //~vbB9I~//~vbBsR~
//        else                                                       //~vbB9I~//~vbBsR~
    	if (pcfg->UCECflag & UCECF_CP939) //use internal map       //~vbB4I~
        	sjisopt=EBCID_ENGEXT;                                  //~vbB4I~
    	else                                                       //~vbB4I~
    	if (pcfg->UCECflag & UCECF_CP930) //use internal map       //~vbB4I~
        	sjisopt=EBCID_KANAEXT;                                 //~vbB4I~
    }                                                              //~vbB4I~
    if (sjisopt)                                                   //~vbB4I~
    	sprintf(msg,"; (cfg info:%s,sjisopt=%s,default converter=%s)\n",//~vbB4R~
    		cvtype,sjisopt,wkcvn);                               //~vbB4R~//~vbB7R~
    else                                                           //~vbB4I~
    	sprintf(msg,"; (cfg info:%s,default converter=%s)\n",      //~vbB4R~
    		cvtype,wkcvn);                                       //~vbB4I~//~vbB7R~
    uerrmsgcat(msg,msg);                                           //~vbB4I~
    UTRACEP("%s,UCECflag=0x%08x,flag2=0x%04x,sbcs=%s,dbcs=%s,cvname=%s,msg=%s\n",UTT,pcfg->UCECflag,pcfg->UCECflag2,pcvnSbcs,pcvnDbcs,wkcvn,msg);//~vbB4R~//~vbB7R~//~vbB9R~
}                                                                  //~vbB4I~
//**************************************************************** //~va7KI~
//!func_ebc                                                        //~va7KI~
//* ebcdic setting                                                 //~va7KI~
//*retrn:rc                                                        //~va7KI~
//**************************************************************** //~va7KI~
int func_ebc(PUCLIENTWE Ppcw)                                      //~va7KI~
{                                                                  //~va7KI~
    int opdno,rc=0,ii,oldhandle=0;                                               //~va7KR~//~vaf9R~
    char *pc;                                                      //~va7KI~
    PUFILEH pfh;                                                   //~va7LI~
//*********************************                                //~va7KI~
//*operand chk                                                     //~va7KI~
    opdno=Ppcw->UCWopdno;                                          //~va7KI~
    pc=Ppcw->UCWopdpot;                                            //~va7KI~
	if (!opdno)		//operand                                      //~va7KI~
    {                                                              //~va7KI~
    	uerrmsg("EBC %s=codepage",0,                               //~va7KI~
					 EBCCMD_OPT_SETCP);                            //~va7KI~
        displayEbcCfgStatus(Ppcw);                                 //~vbB4I~
        return 0;                                                  //~va7KI~
    }                                                              //~va7KI~
//  for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~va7KI~//~vafhR~
    for (ii=0;ii<opdno;)	//C4702 unreachable code               //~vafhI~
	{                                                              //~va7KI~
    	if (USTRHEADIS_IC(pc,EBCCMD_OPT_SETCP))    //icase CP=     //~va7KI~
        {                                                          //~va7KI~
            pfh=UGETPFHFROMPCW(Ppcw);                              //~va7LI~
            if (pfh)                                               //~va7LI~
            	oldhandle=pfh->UFHhandle;                          //~va7LI~
        	rc=opt2resethandle(OPT2RHO_RESETCMD,Ppcw,0/*pfh*/,0/*handle*/);//~va7KI~
            if (!rc)                                               //~va7LR~
                fsubresetebcdbcstbl(0,oldhandle,Ppcw,pfh);         //~va7LR~
            break;                                                 //~va7KI~
        }                                                          //~va7KI~
        return errinvalid(pc);                                     //~va7KI~
    }//loop by operand no                                          //~va7KI~
	return rc;                                                     //~va7KI~
}//func_ebc                                                        //~va7KI~
//*******************************************************          //~va00I~
//*get encoding for hdr line filename postfix                      //~va50R~
//*******************************************************          //~va00I~
int filegetencoding(PUCLIENTWE Ppcw,PUFILEC Ppfc,PUFILEH Ppfh)     //~va00I~
{                                                                  //~va00I~
	int encodeid=MODE_LOCALEFILEID;                                //~va00R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebc=0;                                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**********************                                           //~va00I~
  	if (Ppfh->UFHtype==UFHTDIR)          //dir                     //~va00R~
    {                                                              //~va00I~
        if (UCBITCHK(Ppfc->UFCflag2,UFCF2UTF8))                    //~va00I~
            encodeid=MODE_UTF8FILEID;                              //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        else                                                       //~va50I~
        if (UCBITCHK(Ppfc->UFCflag3,UFCF3EBC))                     //~va50I~
        {                                                          //~va50I~
        	swebc=1;                                               //~va50I~
	        encodeid=MODE_EBCFILEID;                               //~va50I~
        	if (!UCBITCHK(Ppfc->UFCflag3,UFCF3EBCP))               //~va50I~
		        encodeid=tolower(encodeid);                        //~va50I~
        }                                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		if (PFH_ISEBC(Ppfh))                                       //~va50I~
        {                                                          //~va50I~
        	swebc=1;                                               //~va50I~
    		encodeid=MODE_EBCFILEID;                               //~va50I~
//  		if (!UCBITCHK(Ppfh->UFHflag10,UFHF10EBCP))             //~va50R~//~va69R~
    		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                 //~va69I~
		        encodeid=tolower(encodeid);                        //~va50I~
        }                                                          //~va50I~
        else                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                     //~va00I~
    		encodeid=MODE_BINFILE;                                 //~va00I~
    	else                                                       //~va00I~
    		if (FILEUTF8MODE(Ppfh))                                //~va00I~
		    	encodeid=MODE_UTF8FILEID;                          //~va00I~
    }                                                              //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (!swebc)                                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))                      //~va00I~
        encodeid=tolower(encodeid);                                //~va00I~
    return encodeid;                                               //~va00R~
}//filegetencoding                                                 //~va00I~
//*******************************************************          //~vb2hR~
char opt2getfnmode(int Popt,PUFILEH Ppfh)                          //~vb2hR~
{                                                                  //~vb2hR~
	char fnmode;                                                   //~vb2hR~
    int swdefault=1;                                               //~vb2hR~
//***********************                                          //~vb2hR~
    if (UCBITCHK(Ppfh->UFHflag14,UFHF14FN_ENCODED_UTF8))           //~vb2hI~
	    fnmode=MODE_UTF8FILEID;                                    //~vb2hI~
    else                                                           //~vb2hI~
		fnmode=MODE_LOCALEFILEID;                                  //~vb2hI~
                                                                   //~vb2hI~
    if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNCMD))//FN{U8|LC} parm may be ignored by UDHF3U8UTF/UDHF3U8LC//~vb2hI~
    {                                                              //~vb2hI~
        if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8) && fnmode==MODE_UTF8FILEID)//~vb2hI~
            swdefault=0;                                           //~vb2hI~
        else                                                       //~vb2hI~
        if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC) && fnmode==MODE_LOCALEFILEID)//~vb2hI~
            swdefault=0;                                           //~vb2hI~
    }                                                              //~vb2hI~
    if (swdefault)                                                 //~vb2hR~
		fnmode=(char)tolower(fnmode);                              //~vb2hR~
    return fnmode;                                                 //~vb2hR~
}//opt2getfnmode                                                   //~vb2hR~
//*******************************************************          //~vb2hI~
//*set file encoding id to top plh col2                            //~vb2hI~
//*******************************************************          //~vb2hI~
void filesetlocaleid_filename(int Popt,PUFILEH Ppfh)               //~vb2hR~
{                                                                  //~vb2hI~
	PULINEH plh;                                                   //~vb2hI~
	UQUEH   *pqh;                                                  //~vb2hI~
	char fnmode,dirmode=0,*pc;                                       //~vb2hR~//~vb2nR~
//**********                                                       //~vb2hI~
	fnmode=opt2getfnmode(0,Ppfh);                                  //~vb2hI~
#ifdef LNX                                                         //~vb2nM~
    if (Ppfh->UFHattr & FILE_DIRECTORY)                            //~vb2hI~
    {                                                              //~vb2hI~
        if (UCBITCHK(Ppfh->UFHflag14,UFHF14MOUNTU8))               //~vb2hI~
			dirmode=(char)tolower(MODE_UTF8FILEID);                //~vb2hI~
    }                                                              //~vb2hI~
#endif                                                             //~vb2nM~
	pqh=&Ppfh->UFHlineque;                                         //~vb2hI~
	plh=UGETQTOP(pqh);                                             //~vb2hI~
    pc=plh->ULHdata;                                               //~vb2hI~
//#ifdef LNX                                                         //~vb2hI~//~vb2nR~
    *(pc+6)=fnmode;                                                //~vb2hI~
//#endif                                                             //~vb2hI~//~vb2nR~
    if (dirmode)                                                   //~vb2hI~
	    *(pc+7)=dirmode;                                           //~vb2hI~
    UCBITON(plh->ULHflag,ULHFDRAW); //redraw                       //~vb2hI~
	plh=UGETQEND(pqh);                                             //~vb2hI~
    pc=plh->ULHdata;                                               //~vb2hI~
//#ifdef LNX                                                         //~vb2hI~//~vb2nR~
    *(pc+6)=fnmode;                                                //~vb2hI~
//#endif                                                             //~vb2hI~//~vb2nR~
    if (dirmode)                                                   //~vb2hI~
	    *(pc+7)=dirmode;                                           //~vb2hI~
    UCBITON(plh->ULHflag,ULHFDRAW); //redraw                       //~vb2hI~
    return;                                                        //~vb2hI~
}//filesetlocaleid_filename                                        //~vb2hI~
//*******************************************************          //~v915M~
//*set file encoding id to top plh col2                            //~va50R~
//*******************************************************          //~v915M~
void filesetlocaleid(PUFILEH Ppfh)                                 //~v915M~
{                                                                  //~v915M~
	PULINEH plh;                                                   //~v915M~
	UQUEH   *pqh;                                                  //~v915M~
    char encodeid,*pc;                                             //~v915M~
    char rmode,wmode;                                              //~va82I~
#define CVNAMEPOS 30                                               //~va79I~
//**********                                                       //~v915M~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                                                                   //~va79I~
 if (PFH_ISEBC(Ppfh))	                                           //~va50R~
 {                                                                 //~va50I~
    encodeid=MODE_EBCFILEID;                                       //~va50I~
//  if (!UCBITCHK(Ppfh->UFHflag10,UFHF10EBCP))                     //~va50R~//~va69R~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~va69I~
//  	encodeid=tolower(encodeid);                                //~va50I~//~vb2eR~
    	encodeid=(char)tolower(encodeid);                          //~vb2eI~
//    handle=Ppfh->UFHhandle;                                        //~va79I~//~va7LR~
//    pcvname=ucvebc4_getcvname(0,handle);                           //~va79I~//~va7LR~
//    if (handle>0)                                                  //~va79I~//~va7LR~
//    {                                                              //~va79I~//~va7LR~
//        cvtype=ucvebc4_getcvtype(0,handle);                        //~va79I~//~va7LR~
//        if (cvtype & UCVEBC4CVT_ICU)                               //~va79I~//~va7LR~
//            pcvt="(ICU)";                                          //~va79I~//~va7LR~
//        else                                                       //~va79I~//~va7LR~
////      if (!(cvtype & UCVEBC4CVT_EXT))                            //~va79I~//~va7KR~//~va7LR~
////          pcvt="(InternalMap)";                                  //~va79I~//~va7KR~//~va7LR~
////      else                                                       //~va79I~//~va7KR~//~va7LR~
//            pcvt="";                                               //~va79I~//~va7LR~
//    }                                                              //~va79I~//~va7LR~
//    else                                                           //~va79I~//~va7LR~
//        pcvt="";                                                   //~va79I~//~va7LR~
//    cvlen=sprintf(cvname," cp=%s%s ",pcvname,pcvt);                //~va79R~//~va7LR~
 }                                                                 //~va50I~
 else                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
 {                                                                 //~va50I~
  if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //not opend by bin       //~va00I~
    encodeid=MODE_BINFILE;                                         //~va00I~
  else                                                             //~va00I~
  {                                                                //~va00I~
    if (FILEUTF8MODE(Ppfh))                                        //~v915M~
    	encodeid=MODE_UTF8FILEID;                                  //~v915M~
    else                                                           //~v915M~
//      if (UTF8MODEENV()) //env is utf8(linux locale=utf8)        //~v922R~
	    	encodeid=MODE_LOCALEFILEID;                            //~v915M~
//      else                                                       //~v922R~
//      	encodeid=MODE_ASISFILEID;                              //~v922R~
    if (!UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))                      //~v922I~
	    encodeid=(char)tolower((int)encodeid);                     //~v922I~
  }                                                                //~va00I~
 }//not ebc                                                        //~va50I~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                        //~vaj0I~
    	rmode='v';                                                 //~vaj0I~
    else                                                           //~vaj0I~
    if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                    //~va82M~
    	rmode='r';                                                 //~va82R~
    else                                                           //~va82M~
 	if (UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTPC))                     //~va82R~
    {                                                              //~va82I~
 		if (UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTUNIX))               //~va82R~
    		rmode='t';                                             //~va82R~
        else                                                       //~va82I~
    		rmode='p';                                             //~va82R~
    }                                                              //~va82I~
    else                                                           //~va82I~
 	if (UCBITCHK(Ppfh->UFHflag3,UFHF3RTEXTUNIX))                   //~va82R~
    	rmode='u';                                                 //~va82R~
    else                                                           //~va82I~
	if (UCBITCHK(Ppfh->UFHflag6,UFHF6RTEXTMAC))                    //~va82I~
    	rmode='m';                                                 //~va82R~
    else                                                           //~va82I~
	if (UCBITCHK(Ppfh->UFHflag11,UFHF11RTEXTEBC))                  //~va82I~
    	rmode='e';                                                 //~va82R~
    else                                                           //~va82I~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~va82R~
    	rmode='b';                                                 //~va82R~
    else                                                           //~va82I~
    	rmode='*';                                                 //~va82I~
                                                                   //~va82I~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13WV))                        //~vaj0I~
    	wmode='v';                                                 //~vaj0I~
    else                                                           //~vaj0I~
    if (UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD))                   //~va82M~
    	wmode='r';                                                 //~va82R~
    else                                                           //~va82M~
 	if (UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTPC))                     //~va82R~
    {                                                              //~va82I~
 		if (UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTUNIX))               //~va82R~
    		wmode='t';                                             //~va82R~
        else                                                       //~va82I~
    		wmode='p';                                             //~va82R~
    }                                                              //~va82I~
    else                                                           //~va82I~
 	if (UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTUNIX))                   //~va82R~
    	wmode='u';                                                 //~va82R~
    else                                                           //~va82I~
	if (UCBITCHK(Ppfh->UFHflag6,UFHF6WTEXTMAC))                    //~va82I~
    	wmode='m';                                                 //~va82R~
    else                                                           //~va82I~
	if (UCBITCHK(Ppfh->UFHflag11,UFHF11WTEXTEBC))                  //~va82I~
    	wmode='e';                                                 //~va82R~
    else                                                           //~va82I~
    	wmode='*';                                                 //~va82I~
    if (wmode==rmode)                                              //~va82I~
        wmode='*';                                                 //~va82I~
	pqh=&Ppfh->UFHlineque;                                         //~v915M~
	plh=UGETQTOP(pqh);                                             //~v915M~
//  pc=PLHUTCDATA(plh);                                            //~v915M~//~va00R~
    pc=plh->ULHdata;                                               //~va00I~
    *(pc+1)=encodeid;                                              //~v915M~
    *(pc+3)=rmode;                                                 //~va82I~
    *(pc+4)=wmode;                                                 //~va82I~
//    if (cvlen)                                                     //~va79I~//~va7LR~
//        memcpy(pc+CVNAMEPOS,cvname,(UINT)cvlen);                   //~va79I~//~va7LR~
    UCBITON(plh->ULHflag,ULHFDRAW); //redraw                       //~v915I~
	plh=UGETQEND(pqh);                                             //~v915M~
//  pc=PLHUTCDATA(plh);                                            //~v915M~//~va00R~
    pc=plh->ULHdata;                                               //~va00I~
    *(pc+1)=encodeid;                                              //~v915M~
    *(pc+3)=rmode;                                                 //~va82I~
    *(pc+4)=wmode;                                                 //~va82I~
//    if (cvlen)                                                     //~va79I~//~va7LR~
//        memcpy(pc+CVNAMEPOS,cvname,(UINT)cvlen);                   //~va79I~//~va7LR~
    UCBITON(plh->ULHflag,ULHFDRAW); //redraw                       //~v915I~
  if (Ppfh->UFHtype!=UFHTCMDHIST)                                  //~vbi3I~
  {                                                                //~vbi3I~
 	if (PFH_ISEBC(Ppfh))                                           //~va7LI~
		opt2setebccvname(0,Ppfh);                                  //~va7LI~
    else                                                           //~vb4qR~
 	if (FILEUTF8MODE(Ppfh))                                        //~vb4qR~
		opt2sethdrligcomb(0,Ppfh);                                 //~vb4qR~
    else                                                           //~vbCDR~
		opt2sethdrligcomb(O2SHLCO_LIGATUREONLY,Ppfh);              //~vbCDR~
  }                                                                //~vbi3I~
    UTRACEP("%s:encodeid=%c,rmode=%c,wmode=%c,FHflag8=0x%x,fnm=%s",UTT,encodeid,rmode,wmode,Ppfh->UFHflag8,Ppfh->UFHfilename);//~vbraI~
    return;                                                        //~v915I~
}//filesetlocaleid                                                 //~v915M~
//*******************************************************          //~va7KI~
//*set file encoding id to top plh col2                            //~va7KI~
//*******************************************************          //~va7KI~
int opt2resethandle(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Phandle)//~va7KI~
{                                                                  //~va7KI~
	PUFILEH pfh;                                                   //~va7KI~
	PULINEH plh;                                                   //~va7KI~
	UQUEH   *pqh;                                                  //~va7KI~
    int oldhandle,newhandle,swebccmd;             //~va7KR~        //~va7LR~
    char *pcvname,*poldcvname;       //~va7KR~                     //~va7LR~
//**********                                                       //~va7KI~
    swebccmd=(Popt & OPT2RHO_RESETCMD);    //by reset cmd,pfh=NULL //~va7KI~
    if (swebccmd)    //by reset cmd,pfh=NULL                       //~va7KR~
    {                                                              //~va7KI~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~va7KI~
        if (!pfh                                                   //~va7KI~
        ||   Ppcw->UCWtype!=UCWTFILE                               //~va7KI~
        ||   !PFH_ISEBC(pfh)                                       //~va7KI~
        )                                                          //~va7KI~
        {                                                          //~va7KI~
//      	uerrmsg("RESet %s is for EBCDIC file",                 //~va7KI~//~va8gR~
//          		"RESet %s は EBCDIC ファイル用です",           //~va7KI~//~va8gR~
//                  	MODE_EBC);                                 //~va7KI~//~va8gI~
        	uerrmsg("\"EBC %s=\" is for EBCDIC file only.(Specify %s= option at open to set directory's default.)",//~va8gR~
            		"\"EBC %s=\" コマンドは EBCDIC ファイル用です。デレクトリーの省略値を設定する場合、開く時に%s=オプションを指定してください",//~va8gR~
    				EBCCMD_OPT_SETCP,MODE_EBC);    //icase SETCP=  //~va8gR~
            return 4;                                              //~va7KI~
        }                                                          //~va7KI~
        pcvname=Ppcw->UCWopdpot;                                   //~va7KI~
        if (fileoptionchkebcconverter(0,pcvname,sizeof(EBCCMD_OPT_SETCP)-1,&newhandle))//~va7KR~
        	return 4;                                              //~va7KI~
    }                                                              //~va7KI~
    else                                                           //~va7KI~
    {                                                              //~va7KI~
    	pfh=Ppfh;                                                  //~va7KI~
        newhandle=Phandle;                                         //~va7KI~
    }                                                              //~va7KI~
    oldhandle=pfh->UFHhandle;                                      //~va7KI~
    if (newhandle==oldhandle)                                      //~va7KR~
    {                                                              //~va7KI~
    	if (swebccmd)    //by reset cmd,pfh=NULL                   //~va7KR~
        {                                                          //~va7KI~
        	uerrmsg("Same EBCDIC codepage was specified",          //~va7KI~
             	   "同じ EBCDICコードページが指定されています");   //~va7KI~
            return 4;                                              //~va7KI~
        }                                                          //~va7KI~
    	return 0;                                                  //~va7KI~
    }                                                              //~va7KI~
	pqh=&pfh->UFHlineque;                                          //~va7KM~
	plh=UGETQTOP(pqh);                                             //~va7KM~
    if (swebccmd)    //by reset cmd,pfh=NULL                       //~va7LR~
    	UPCTRREQ(pfh);         //write at save                     //~va7LR~
    undoprep(Ppcw,UGETQNEXT(plh),UUHTEBCSETCP);                    //~va7LR~
    pfh->UFHhandle=newhandle;                                      //~va7KR~
    if (swebccmd)    //by reset cmd,pfh=NULL                       //~va7LR~
    	UPCTRREQ(pfh);         //write at save                     //~va7LR~
	opt2setebccvname(0,pfh);                                       //~va7LR~
    UCBITON(Ppcw->UCWflag,UCWFDRAW); //redraw                      //~va7KR~
    if (swebccmd)    //by reset cmd,pfh=NULL                       //~va7KR~
    {                                                              //~va7KI~
	    pcvname=ucvebc4_getcvname(0,newhandle);                        //~va7KR~//~va7LI~
    	poldcvname=ucvebc4_getcvname(0,oldhandle);                 //~va7KI~
        uerrmsg("EBCDIC codepage was changed to %s from %s",       //~va7KR~
                "EBCDICコードページの変更 %s <-- %s",              //~va7KI~
                    pcvname,poldcvname);                           //~va7KI~
    }                                                              //~va7KI~
    return 0;                                                      //~va7KI~
}//opt2resethandle                                                 //~va7KI~
//*******************************************************          //~va7LI~
//*set file encoding id to top plh col2                            //~va7LI~
//*******************************************************          //~va7LI~
int opt2setebccvname(int Popt,PUFILEH Ppfh)                        //~va7LR~
{                                                                  //~va7LI~
	PULINEH plh;                                                   //~va7LI~
	UQUEH   *pqh;                                                  //~va7LI~
    char *pc;                                                      //~va7LI~
    int handle,cvlen,cvtype;                                       //~va7LR~
    char cvname[MAX_CSNAMESZ+32],*pcvt,*pcvname,*pcfg;             //~va7LR~
//**********                                                       //~va7LI~
    handle=Ppfh->UFHhandle;                                        //~va7LI~
    pcvname=ucvebc4_getcvname(0,handle);                           //~va7LI~
    cvtype=ucvebc4_getcvtype(0,handle);                            //~va7LI~
    if (cvtype & UCVEBC4CVT_ICU)                                   //~va7LI~
        pcvt="(ICU)";                                              //~va7LI~
    else                                                           //~va7LI~
        pcvt="";                                                   //~va7LI~
    if (handle)                                                    //~va7LI~
        pcfg="";                                                   //~va7LI~
    else                                                           //~va7LI~
    if (cvtype & UCVEBC4CVT_OPENERR)                               //~vbBfI~
        pcfg="";                                                   //~vbBfI~
    else                                                           //~vbBfI~
        pcfg="CFG:";                                               //~va7LI~
    cvlen=sprintf(cvname," cp=%s%s%s ",pcfg,pcvname,pcvt);         //~va7LR~
//  memset(cvname+cvlen,'*',sizeof(cvname)-cvlen);                 //~va7LI~//~vb2eR~
    memset(cvname+cvlen,'*',sizeof(cvname)-(size_t)cvlen);         //~vb2eI~
    cvlen=sizeof(cvname);                                          //~va7LI~
                                                                   //~va7LI~
	pqh=&Ppfh->UFHlineque;                                         //~va7LI~
	plh=UGETQTOP(pqh);                                             //~va7LI~
    pc=plh->ULHdata;                                               //~va7LI~
    memcpy(pc+CVNAMEPOS,cvname,(UINT)cvlen);                       //~va7LI~
	plh=UGETQEND(pqh);                                             //~va7LI~
    pc=plh->ULHdata;                                               //~va7LI~
    memcpy(pc+CVNAMEPOS,cvname,(UINT)cvlen);                       //~va7LI~
    return 0;                                                      //~va7LI~
}//opt2setebccvname                                                //~va7LI~
//*******************************************************          //~v91hI~
//*set file encoding id of dirlist                                 //~v91hI~
//*******************************************************          //~v91hI~
void dirsetlocaleid(int Popt,PUFILEC Ppfc,char *Ppsddata)          //~v91hI~
{                                                                  //~v91hI~
	PUFILEH pfh;                                                   //~v91hI~
	PULINEH plh;                                                   //~v91hI~
	UQUEH   *pqh;                                                  //~v91hI~
    char encodeid;                                                 //~v91hR~
    char *pc;                                                      //~va8gI~
//**********                                                       //~v91hI~
	if (Ppsddata)	//from dir2 at draw dir                        //~v91hI~
    {                                                              //~v91hI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
      if (UCBITCHK(Ppfc->UFCflag3,UFCF3EBC))                       //~va50I~
      {                                                            //~va50I~
        encodeid=MODE_EBCFILEID;                                   //~va50I~
	    if (!UCBITCHK(Ppfc->UFCflag3,UFCF3EBCP))                   //~va50I~
//  		encodeid=tolower(encodeid);                            //~va50I~//~vb2eR~
    		encodeid=(char)tolower(encodeid);                      //~vb2eI~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      {                                                            //~va50I~
        if (UCBITCHK(Ppfc->UFCflag2,UFCF2UTF8))                    //~v91hI~
            encodeid=MODE_UTF8FILEID;                              //~v91hI~
        else                                                       //~v91hI~
//          if (UTF8MODEENV()) //env is utf8(linux locale=utf8)    //~v922R~
                encodeid=MODE_LOCALEFILEID;                        //~v91hI~
//          else                                                   //~v922R~
//              encodeid=MODE_ASISFILEID;                          //~v922R~
        if (!UCBITCHK(Ppfc->UFCflag2,UFCF2UTF8P))                  //~v922I~
	    	encodeid=(char)tolower((int)encodeid);                 //~v922I~
      }                                                            //~va50I~
//      *(Ppsddata+1)=encodeid;                                    //~v91hI~//~va8gR~
    	pfh=Ppfc->UFCpfh;                                          //~va8gM~
		pqh=&pfh->UFHlineque;                                      //~va8gI~
		plh=UGETQTOP(pqh);                                         //~va8gI~
    	pc=plh->ULHdata;                                           //~va8gI~
    	*(pc+1)=encodeid;                                          //~va8gI~
		plh=UGETQEND(pqh);                                         //~va8gI~
    	pc=plh->ULHdata;                                           //~va8gI~
    	*(pc+1)=encodeid;                                          //~va8gI~
      	if (UCBITCHK(Ppfc->UFCflag3,UFCF3EBC))                     //~va8gI~
			opt2setebccvname(0,pfh);                               //~va8gR~
    }                                                              //~v91hI~
    else	//from mode cmd                                        //~v91hI~
    {                                                              //~v91hI~
    	pfh=Ppfc->UFCpfh;                                          //~v91hI~
        pqh=&pfh->UFHlineque;                                      //~v91hR~
        plh=UGETQTOP(pqh);                                         //~v91hI~
        UCBITON(plh->ULHflag,ULHFDRAW); //redraw                   //~v91hI~
        plh=UGETQEND(pqh);                                         //~v91hI~
        UCBITON(plh->ULHflag,ULHFDRAW); //redraw                   //~v91hI~
    }                                                              //~v91hI~
	opt2sethdrligcomb(0,pfh);                                      //~vbmqR~
    return;                                                        //~v91hI~
}//dirsetlocaleid                                                  //~v91hI~
#ifdef UTF8SUPP                                                    //~va00I~
//****************************************************************
//!funcmoderesetdbcstbl                                            //~v90wR~
//* delete option set
//*parm1:pcw(UCWparm:operand)
//*retrn:rc
//****************************************************************
int funcmoderesetdbcstbl(PUCLIENTWE Ppcw,PUFILEH Ppfh)             //~v90wR~
{
	UQUEH   *pqh;                                                  //~v90wI~
	PULINEH plh;                                                   //~v90wI~
    int lenutf;                                                    //~v90wI~
    char *pdbcs;                                                   //~v90wI~
//******************                                               //~v90wI~
	pqh=&Ppfh->UFHlineque;                                         //~v90wI~
	plh=UGETQTOP(pqh);                                             //~v90wR~
	if (Ppfh->UFHupctr)		//once updated                         //~v90wR~
    {                                                              //~v90wI~
    	if (plh)                                                   //~v90wI~
        {                                                          //~v90wI~
    		UPCTRREQ(Ppfh);         //write at save                //~v90wI~
            undoupdate(Ppcw,plh,UUHTMODECHANGE);	//dummy to update upctr//~v90wR~
        }                                                          //~v90wI~
    }                                                              //~v90wI~
	for (;plh;plh=UGETQNEXT(plh))	//dequed                       //~v90wI~
    {                                                              //~v90wI~
    	pdbcs=plh->ULHdbcs;                                        //~v90wI~
        lenutf=plh->ULHlenutf;                                     //~v90wI~
        if (pdbcs)	//tab expanded                                 //~v90wI~
        {                                                          //~v90wI~
			lenutf-=sub_restoretabdroppad(SRTDP_NOUPDATEDBCS,PLHDATAP(plh),pdbcs,plh->ULHlenc,0);////~v90wR~
            ufree(pdbcs);                                          //~v90wR~
            plh->ULHdbcs=0;                                        //~v90wI~
        }                                                          //~v90wI~
        UFREECLEARIFNZ(plh->ULHchof);                              //~v90wI~
        plh->ULHlenc=plh->ULHlenutf=lenutf;                        //~v90wI~
		UCBITOFF(plh->ULHflag2,ULHF2TABCHKED|ULHF2TABFOUND);	//first time//~v90wR~
    }                                                              //~v90wI~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);	//redraw                   //~v90wI~
	return 0;
}//funcmoderesetdbcstbl                                            //~v90wR~
//**************************************************************** //~v44qI~
//!opthelp                                                         //~v44qI~
//* help msg                                                       //~v44qI~
//*parm1:none                                                      //~v44qI~
//*retrn:rc                                                        //~v44qI~
//**************************************************************** //~v44qI~
int funcmodehelp(void)                                             //~v90wR~
{                                                                  //~v44qI~
//********************                                             //~v59XI~
    uerrmsg("UTF {%s|%s|%s|%s}",0,                                 //~v929R~
				MODE_UTF8,MODE_LOCALE,MODE_ASIS,MODE_SWKBD);       //~v917R~
    return 0;                                                      //~v91yR~
}//funcmodehelp                                                    //~v90wR~
#endif  //UTF8SUPP                                                 //~va0xI~
//**************************************************************** //~v44qI~//~va0xI~
//!opthelp                                                         //~v44qI~//~va0xI~
//* help msg                                                       //~v44qI~//~va0xI~
//*parm1:none                                                      //~v44qI~//~va0xI~
//*retrn:rc                                                        //~v44qI~//~va0xI~
//**************************************************************** //~v44qI~//~va0xI~
int funcmodehelp(void)                                             //~v90wR~//~va0xI~
{                                                                  //~v44qI~//~va0xI~
//********************                                             //~v59XI~//~va0xI~
//  uerrmsg("UTF {%s}",0,                                 //~v929R~//~va0xI~//~va1pR~
//  			MODE_SWKBD);       //~v917R~                       //~va0xI~//~va1pR~
//    uerrmsg("UTF { %s | %s | %s } [ %s | %s | %s ]",0,             //~va1pR~//~va1NR~
      uerrmsg("UTF { {%s | %s} | %s | %s | %s } [ %s | %s | %s ]",0,//~va1NR~
    			MODE_RETRYCPLC,MODE_NORETRYCPLC,                   //~va1NI~
    			MODE_SWKBD,OPT_FILE,OPT_FILENAME,                  //~va1pR~
				MODE_UTF8,MODE_LOCALE,MODE_ASIS                    //~va1NR~
                );                                                 //~va1NI~
    opt_modestatus(0,Goptopt2);                                    //~va1pR~
    return 0;                                                      //~v91yR~//~va0xI~
}//funcmodehelp                                                    //~v90wR~//~va0xI~
//#ifdef UTF8SUPP                                                    //~va0xI~//~vbraR~
////**************************************************************** //~v90wI~//~vbraR~
////!opt_mode                                                        //~v90wI~//~vbraR~
////* ut8 kbd input mode                                             //~v90wI~//~vbraR~
////*retrn:rc                                                        //~v90wI~//~vbraR~
////**************************************************************** //~v90wI~//~vbraR~
//int opt_mode(PUCLIENTWE Ppcw,PUOPTWTBL Ppot,int Popdno)            //~v90wI~//~vbraR~
//{                                                                  //~v90wI~//~vbraR~
//    int opid,ii,opto,optn,optm,swfile=0,swkbd=0;                   //~v90zR~//~vbraR~
//    int localechangesw=0;                                          //~v91dI~//~vbraR~
//    int cpfilesw=0;                                                //~v91yI~//~vbraR~
//    int localesetsw=0;                                             //~v91dI~//~vbraR~
//    UCHAR *pc;                                                     //~v90wI~//~vbraR~
//    UCHAR localecode[MAXLOCALESZ]={0};                             //~v91dR~//~vbraR~
//static UCHAR *Swordtbl[]={"KBD","FILE",                            //~v916R~//~vbraR~
//                        MODE_OPTENV,     //#3 kbd env              //~v916I~//~vbraR~
//                        MODE_UTF8,      //#4 file utf8             //~v90zI~//~vbraR~
//                        MODE_LOCALE,      //#5                     //~v90zR~//~vbraR~
//                        MODE_OPTUTF8,   //#6 kbd utf8              //~v90zI~//~vbraR~
//                        MODE_OPTLOCALE, //#7                       //~v90zI~//~vbraR~
//                        MODE_ASIS,      //#8                       //~v916I~//~vbraR~
//                        MODE_OPTCPFILE, //#9 as cp of file for file data//~v916I~//~vbraR~
//                        MODE_OPTNOCPFILE, //#10                    //~v916I~//~vbraR~
//                        "LOCALE",       //#11                      //~v91dR~//~vbraR~
//                        0};                                        //~v90zI~//~vbraR~
////*********************************                                //~v90wI~//~vbraR~
//    if (!XEUTF8MODE())                                             //~v91yI~//~vbraR~
////      return errnotsupported("OPT UTF cmd","Non-UTF8 mode");     //~v929R~//~vbmqR~//~vbraR~
//        return errnotsupported("UTF cmd","Non-UTF8 mode");         //~vbmqI~//~vbraR~
//    optm=GOPT2_MODEINPUTL2U                                        //~v90zI~//~vbraR~
//        |GOPT2_MODEINPUTU2L                                        //~v90zI~//~vbraR~
//        |GOPT2_MODEINPUTCPFILE                                     //~v916I~//~vbraR~
//        |GOPT2_ALLFILEUTF8                                         //~v90zR~//~vbraR~
//        |GOPT2_ALLFILELOCALE                                       //~v916I~//~vbraR~
//        ;                                                          //~v90zI~//~vbraR~
//    opto=Goptopt2 & optm;                                          //~v90zI~//~vbraR~
//    if (!(pc=Ppcw->UCWparm))                                       //~v90wI~//~vbraR~
//    {                                                              //~v90wI~//~vbraR~
//#ifdef LNX                                                         //~v91dI~//~vbraR~
//        uerrmsg("OPT UTF [[FILE] {%s|%s|%s}]  [[KBD] {%s|%s|%s}[%s|%s]] [LOCALE localeid]",0,//~v929R~//~vbraR~
//#else                                                              //~v91dI~//~vbraR~
//        uerrmsg("OPT UTF [[FILE] {%s|%s|%s}]  [[KBD] {%s|%s|%s}[%s|%s]]",0,//~v929R~//~vbraR~
//#endif                                                             //~v91dI~//~vbraR~
//                MODE_UTF8,MODE_LOCALE,MODE_ASIS,MODE_OPTUTF8,MODE_OPTLOCALE,//~v916R~//~vbraR~
//                MODE_OPTENV,MODE_OPTCPFILE,MODE_OPTNOCPFILE);      //~v916R~//~vbraR~
//        opt_modestatus(0,opto);                                    //~v90zI~//~vbraR~
//        return 0;                                                  //~v90wI~//~vbraR~
//    }                                                              //~v90wI~//~vbraR~
//    for (ii=0;ii<Popdno;ii++,pc+=strlen(pc)+1)  //next operand addr//~v90zI~//~vbraR~
//    {                                                              //~v90zI~//~vbraR~
//        switch(opid=wordtbllistisrch(pc,Swordtbl),opid)            //~v90zR~//~vbraR~
//        {                                                          //~v90zI~//~vbraR~
//        case 0: //eol char                                         //~v90zI~//~vbraR~
//            return errinvalid(pc);                                 //~v90zI~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 1: //KBD                                              //~v90zI~//~vbraR~
//            swkbd=1;                                               //~v90zI~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 2: //FILE                                             //~v90zI~//~vbraR~
//            swfile=1;                                              //~v90zI~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 3: //ENV (kbd)                                        //~v916R~//~vbraR~
//            UCBITOFF(Goptopt2,(GOPT2_MODEINPUTL2U|GOPT2_MODEINPUTU2L));//~v916R~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 4: //file utf8                                        //~v90zI~//~vbraR~
//            UCBITON(Goptopt2,GOPT2_ALLFILEUTF8);                   //~v90zI~//~vbraR~
//            UCBITOFF(Goptopt2,GOPT2_ALLFILELOCALE);                //~v916I~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 5: //file local                                       //~v90zI~//~vbraR~
//            UCBITOFF(Goptopt2,GOPT2_ALLFILEUTF8);                  //~v90zI~//~vbraR~
//            UCBITON(Goptopt2,GOPT2_ALLFILELOCALE);                 //~v916I~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 6: //kbd l2u                                          //~v90zI~//~vbraR~
//            if (!UTF8MODEENV())                                    //~v91sI~//~vbraR~
//                Gutfmode2|=GUM2_KBDL2U;                            //~v91sI~//~vbraR~
//            UCBITON(Goptopt2,GOPT2_MODEINPUTL2U);                  //~v90zR~//~vbraR~
//            UCBITOFF(Goptopt2,GOPT2_MODEINPUTU2L);                 //~v90zR~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 7: //kbd u2l                                          //~v90zI~//~vbraR~
//            if (UTF8MODEENV())                                     //~v91sR~//~vbraR~
//                Gutfmode2|=GUM2_KBDU2L;                            //~v91sI~//~vbraR~
//            UCBITON(Goptopt2,GOPT2_MODEINPUTU2L);                  //~v90zR~//~vbraR~
//            UCBITOFF(Goptopt2,GOPT2_MODEINPUTL2U);                 //~v90zR~//~vbraR~
//            break;                                                 //~v90zI~//~vbraR~
//        case 8: //file asis                                        //~v916I~//~vbraR~
//            UCBITOFF(Goptopt2,(GOPT2_ALLFILEUTF8|GOPT2_ALLFILELOCALE));//~v916I~//~vbraR~
//            break;                                                 //~v916I~//~vbraR~
//        case 9: //cpfile                                           //~v916I~//~vbraR~
//            UCBITON(Goptopt2,GOPT2_MODEINPUTCPFILE);               //~v916R~//~vbraR~
//            cpfilesw=1;                                            //~v91yI~//~vbraR~
//            break;                                                 //~v916I~//~vbraR~
//        case 10: //nocpfile                                        //~v916I~//~vbraR~
//            UCBITOFF(Goptopt2,GOPT2_MODEINPUTCPFILE);              //~v916I~//~vbraR~
//            cpfilesw=1;                                            //~v91yI~//~vbraR~
//            break;                                                 //~v916I~//~vbraR~
//        case 11: //locale                                          //~v91dI~//~vbraR~
//#ifdef LNX                                                         //~v91dI~//~vbraR~
//            pc+=strlen(pc)+1;                                      //~v91dR~//~vbraR~
//            ii++;                                                  //~v91dI~//~vbraR~
//          if (ii<Popdno)                                           //~v91dI~//~vbraR~
//          {                                                        //~v91dI~//~vbraR~
//            strncpy(localecode,pc,MAXLOCALESZ-1);                  //~v91dR~//~vbraR~
//            *(localecode+MAXLOCALESZ-1)=0;                         //~v91dR~//~vbraR~
//            if (ustrstri(localecode,"UTF"))                        //~v91dI~//~vbraR~
//            {                                                      //~v91dI~//~vbraR~
//                uerrmsg("\"%s\" is invalid,specify locale code converted to/from UTF-8",0,//~v91dR~//~vbraR~
//                         localecode);                              //~v91dI~//~vbraR~
//                return 4;                                          //~v91dI~//~vbraR~
//            }                                                      //~v91dI~//~vbraR~
//            localesetsw=1;                                         //~v91dI~//~vbraR~
//          }                                                        //~v91dI~//~vbraR~
//            break;                                                 //~v91dI~//~vbraR~
//#else                                                              //~v91dI~//~vbraR~
//            uerrmsg("LOCALE settting is only for Linux version",0);//~v91dI~//~vbraR~
//            return 4;                                              //~v91dI~//~vbraR~
//#endif                                                             //~v91dI~//~vbraR~
//        }//opd                                                     //~v90zI~//~vbraR~
//    }//loop by operand no                                          //~v90zI~//~vbraR~
//#ifdef LNX                                                         //~v91dI~//~vbraR~
//    if (localesetsw)                                               //~v91dM~//~vbraR~
//    {                                                              //~v91dI~//~vbraR~
//        if (utflocalechk(0,localecode))                            //~v91dR~//~vbraR~
//        {                                                          //~v91dI~//~vbraR~
//            uerrmsg("LOCALE %s is invalid. confirm it by \"iconv --list\" cmd",0,//~v91dR~//~vbraR~
//                    localecode);                                   //~v91dI~//~vbraR~
//            return 4;                                              //~v91dI~//~vbraR~
//        }                                                          //~v91dI~//~vbraR~
//        localechangesw=stricmp(localecode,Glocalecode);            //~v91dR~//~vbraR~
//        strncpy(Glocalecode,localecode,MAXLOCALESZ-1);             //~v91dR~//~vbraR~
//        utfcvlocaleinit(0,Glocalecode); //notify to ulib           //~v91dR~//~vbraR~
//    }                                                              //~v91dM~//~vbraR~
//#endif                                                             //~v91dI~//~vbraR~
//                                                                   //~v91dI~//~vbraR~
//    optn=Goptopt2 & optm;                                          //~v90zI~//~vbraR~
////  opt_modestatus((opto!=optn)+1,optn);                             //~v90zI~//~v91dR~//~vbraR~
//    opt_modestatus(((opto!=optn)||localechangesw)+1,optn);         //~v91dI~//~vbraR~
//    if (cpfilesw)                                                  //~v91yI~//~vbraR~
//        UCBITON(Ppcw->UCWflag,UCWFDRAW);    //redraw cpfileID      //~v91yI~//~vbraR~
//    return 0;                                                      //~v90wI~//~vbraR~
//}//opt_mode                                                        //~v90wI~//~vbraR~
////**************************************************************** //~v90zI~//~vbraR~
////!opt_mode                                                        //~v90zI~//~vbraR~
////* utf8mode display                                               //~v90zI~//~vbraR~
////**************************************************************** //~v90zI~//~vbraR~
//int opt_modestatus(int Pcase,int Popt)                             //~v90zI~//~vbraR~
//{                                                                  //~v90zI~//~vbraR~
//    char statusmsg[128],*pc;                                       //~v90zR~//~vbraR~
//    int pos=0;                                                     //~v90zI~//~vbraR~
////*******************                                              //~v90zI~//~vbraR~
//    if (UCBITCHK(Popt,GOPT2_ALLFILEUTF8))                          //~v90zI~//~vbraR~
//        pc=MODE_UTF8;                                              //~v90zI~//~vbraR~
//    else                                                           //~v90zI~//~vbraR~
//    if (UCBITCHK(Popt,GOPT2_ALLFILELOCALE))                        //~v916I~//~vbraR~
//        pc=MODE_LOCALE;                                            //~v90zI~//~vbraR~
//    else                                                           //~v916I~//~vbraR~
//        pc=MODE_ASIS;                                              //~v916I~//~vbraR~
//    pos=sprintf(statusmsg,"%s",pc);                                //~v916R~//~vbraR~
//    if (UCBITCHK(Popt,GOPT2_MODEINPUTL2U))                         //~v90zR~//~vbraR~
//        pc=MODE_OPTUTF8;                                           //~v90zI~//~vbraR~
//    else                                                           //~v90zI~//~vbraR~
//    if (UCBITCHK(Popt,GOPT2_MODEINPUTU2L))                         //~v90zR~//~vbraR~
//        pc=MODE_OPTLOCALE;                                         //~v90zI~//~vbraR~
//    else                                                           //~v90zI~//~vbraR~
//        pc=MODE_OPTENV;                                            //~v916R~//~vbraR~
//    pos+=sprintf(statusmsg+pos,", %s",pc);                         //~v916R~//~vbraR~
//    if (UCBITCHK(Popt,GOPT2_MODEINPUTCPFILE))                      //~v916M~//~vbraR~
//        pc=MODE_OPTCPFILE;                                         //~v916M~//~vbraR~
//    else                                                           //~v916I~//~vbraR~
//        pc=MODE_OPTNOCPFILE;                                       //~v916I~//~vbraR~
//    pos+=sprintf(statusmsg+pos,", %s",pc);                         //~v916I~//~vbraR~
//#ifdef LNX                                                         //~v91dI~//~vbraR~
//    if (*Glocalecode)                                              //~v91dI~//~vbraR~
//        pos+=sprintf(statusmsg+pos,", LOCALE=%s",Glocalecode);     //~v91dR~//~vbraR~
//    else                                                           //~v91dI~//~vbraR~
//        if (UDBCSCHK_ISUTF8J())                                    //~v91dI~//~vbraR~
//            pos+=sprintf(statusmsg+pos,", LOCALE is %s as Japanese default.",//~v91dR~//~vbraR~
//                         LOCALE_EUC);                              //~v91dR~//~vbraR~
//        else                                                       //~v91dI~//~vbraR~
//            pos+=sprintf(statusmsg+pos,", LOCALE is not defined.");//~v91dR~//~vbraR~
//#endif                                                             //~v91dR~//~vbraR~
//    if (!Pcase)                                                     //~v90zI~//~v90zR~//~vbraR~
//        uerrmsgcat("; current: %s",0,                              //~v91dR~//~vbraR~
//                    statusmsg);                                    //~v90zI~//~vbraR~
//    else                                                           //~v90zI~//~vbraR~
//    if (Pcase==1) //opto==optn                                     //~v90zI~//~v90zR~//~vbraR~
//        uerrmsg("Not changed: %s",0,          //~v90zI~            //~v91dR~//~vbraR~
//                    statusmsg);                                    //~v90zI~//~vbraR~
//    else                                                           //~v90zI~//~vbraR~
//        uerrmsg("Changed: %s",0,              //~v90zI~//+v90zR~   //~v91dR~//~vbraR~
//                    statusmsg);                                    //~v90zI~//~vbraR~
//    return 0;                                                      //~v90zI~//~vbraR~
//}//opt_modestatus                                                  //~v90zI~//~vbraR~
//#endif //UTF8SUPP                                                  //~va00I~//~vbraR~
//**************************************************************** //~va1pI~
//!opt_mode                                                        //~va1pI~
//Pcase:0:current status display, 1:not changwed, 2:status changed //~va1pI~
//* utf8mode display                                               //~va1pI~
//**************************************************************** //~va1pI~
int opt_modestatus(int Pcase,int Popt)                             //~va1pI~
{                                                                  //~va1pI~
	char statusmsg[128],*pc;                                       //~va1pI~
    int pos=0;                                                     //~va1pI~
//*******************                                              //~va1pI~
    if (UCBITCHK(Popt,GOPT2_ALLFILEUTF8))                          //~va1pI~
    	pc=MODE_UTF8;                                              //~va1pI~
    else                                                           //~va1pI~
    if (UCBITCHK(Popt,GOPT2_ALLFILELOCALE))                        //~va1pI~
    	pc=MODE_LOCALE;                                            //~va1pI~
    else                                                           //~va1pI~
    	pc=MODE_ASIS;                                              //~va1pI~
    pos=sprintf(statusmsg,"%s:%s",OPT_FILE,pc);                    //~va1pI~
    pos+=sprintf(statusmsg+pos,", %s",((Goptopt2 & GOPT2_NORETRYCPLC)?MODE_NORETRYCPLC:MODE_RETRYCPLC));//~va1NR~
    if (UCBITCHK(Popt,GOPT2_ALLFNUTF8))                            //~va1pI~
    	pc=MODE_UTF8;                                              //~va1pI~
    else                                                           //~va1pI~
    if (UCBITCHK(Popt,GOPT2_ALLFNLOCALE))                          //~va1pI~
    	pc=MODE_LOCALE;                                            //~va1pI~
    else                                                           //~va1pI~
    	pc=MODE_ASIS;                                              //~va1pI~
    pos+=sprintf(statusmsg+pos,", %s:%s",OPT_FILENAME,pc);         //~va1pI~
	if (!Pcase)                                                    //~va1pI~
    	uerrmsgcat("; current: %s",0,                              //~va1pI~
        			statusmsg);                                    //~va1pI~
    else                                                           //~va1pI~
	if (Pcase==1) //opto==optn                                     //~va1pI~
    	uerrmsg("Not changed: %s",0,                               //~va1pI~
        			statusmsg);                                    //~va1pI~
    else                                                           //~va1pI~
    	uerrmsg("Changed: %s",0,                                   //~va1pI~
        			statusmsg);                                    //~va1pI~
    return 0;                                                      //~va1pI~
}//opt_modestatus                                                  //~va1pI~
#endif //UTF8SUPPH                                                 //~va00R~
//**************************************************************** //~vb4qR~
//*display ligature/combine mode to HDR line                       //~vb4qR~
//**************************************************************** //~vb4qR~
int opt2sethdrligcomb(int Popt,PUFILEH Ppfh)                       //~vb4qR~
{                                                                  //~vb4qR~
	char *pmodecombine,*pmodeligature;                             //~vb4qR~
	char altch[20];                                                //~vb4qR~
    int cvlen;                                                     //~vb4qR~
	PULINEH plh;                                                   //~vb4qR~
	UQUEH   *pqh;                                                  //~vb4qR~
    char *pc;                                                      //~vb4qR~
    char optligcomb[256];                                          //~vb4qR~
//*********************************                                //~vb4qR~
    if (Ppfh->UFHtype==UFHTKFI)                                    //~vbCDI~
        return 0;                                                  //~vbCDI~
	optcombinehelpsub(Popt,&pmodecombine,&pmodeligature,altch);    //~vb4qR~
    cvlen=(int)strlen(altch);                                      //~vb4qR~
    memset(altch+cvlen,'*',sizeof(altch)-(size_t)cvlen);           //~vb4qR~
    *(altch+sizeof(altch)-1)=0;                                    //~vb4qR~
  if (Ppfh->UFHtype==UFHTDIR)                                      //~vbmqI~
    cvlen=sprintf(optligcomb,"Unicomb: %s %s",pmodecombine,altch); //~vbmqI~
  else                                                             //~vbmqI~
  if (Popt & O2SHLCO_LIGATUREONLY)                                 //~vbCDR~
    cvlen=sprintf(optligcomb,"Lig:%s ",pmodeligature);             //~vbCDI~
  else                                                             //~vbCDI~
    cvlen=sprintf(optligcomb,"Lig:%s, Unicomb: %s %s",pmodeligature,pmodecombine,altch);//~vb4qI~
                                                                   //~vb4qR~
	pqh=&Ppfh->UFHlineque;                                         //~vb4qR~
	plh=UGETQTOP(pqh);                                             //~vb4qR~
    pc=plh->ULHdata;                                               //~vb4qR~
    memcpy(pc+CVNAMEPOS,optligcomb,(size_t)cvlen);                 //~vb4qR~
	plh=UGETQEND(pqh);                                             //~vb4qR~
    pc=plh->ULHdata;                                               //~vb4qR~
    memcpy(pc+CVNAMEPOS,optligcomb,(size_t)cvlen);                 //~vb4qR~
    return 0;                                                      //~vb4qR~
}//opt2sethdrligcomb                                               //~vb4qR~
//**************************************************************** //~vb4qR~
int optresethdrligcomb(int Popt,PUCLIENTWE Ppcw)                   //~vb4qR~
{                                                                  //~vb4qR~
	PUCLIENTWE pcw;                                                //~vb4qR~
    PUFILEH pfh;                                                   //~vb4qR~
    PUFILEC pfc;                                                   //~vb4qR~
    int ii;                                                        //~vb4qR~
//***************************                                      //~vb4qR~
	pcw=scrgetcw(1);	                                           //~vb4qR~
    for (ii=0;ii<2;ii++,pcw=scrgetcw(2))                           //~vb4qR~
    {                                                              //~vb4qR~
	    if (pcw && pcw->UCWtype==UCWTFILE)                         //~vb4qR~
        {                                                          //~vb4qR~
            pfc=pcw->UCWpfc;                                       //~vb4qR~
            pfh=pfc->UFCpfh;                                       //~vb4qR~
  			if (pfh->UFHtype==UFHTDIR)                             //~vbmqR~
            {                                                      //~vbmqI~
				UCBITON(pcw->UCWflag,UCWFDRAW);//redraw            //~vbmqI~
                opt2sethdrligcomb(0,pfh);                          //~vbmqI~
            }                                                      //~vbmqI~
            else                                                   //~vbmqI~
            if (FILEUTF8MODE(pfh))                                 //~vb4qR~
            {                                                      //~vb4qR~
				UCBITON(pcw->UCWflag,UCWFDRAW);//redraw            //~vb4qR~
                opt2sethdrligcomb(0,pfh);                          //~vb4qR~
            }                                                      //~vb4qR~
            else                                                   //~vbCDI~
 			if (!PFH_ISEBC(pfh))                                   //~vbCDR~
            {                                                      //~vbCDI~
				UCBITON(pcw->UCWflag,UCWFDRAW);//redraw            //~vbCDI~
				opt2sethdrligcomb(O2SHLCO_LIGATUREONLY,pfh);       //~vbCDI~
            }                                                      //~vbCDI~
        }                                                          //~vb4qR~
    }                                                              //~vb4qR~
    return 0;                                                      //~vb4qR~
}//optresethdrligcomb                                              //~vb4qR~
