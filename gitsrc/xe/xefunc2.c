//*CID://+vbrgR~:                             update#=  548;       //+vbrgR~
//************************************************************* //~5428I~
//* xefunc2.c
//*        func_char,quit,term,exit,reset,retrieve,help,key,exe    //~v55nR~
//*************************************************************
//vbrg:200824 (AXE)xehelp is now included in assets folder         //+vbrgI~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vb86:170216 display cmdline ctr excluded(fcmd:x,xx; lcmd x)      //~vb86I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaww:140611 (W32UNICODE:BUG)retrive of 2 opd cmd,2nd displayed as dbcs//~vawwI~
//vawg:140603 exe cmd should use UD string for cmd from cpu8 file  //~vawgI~
//vawb:140601 issue errmsg for abend test by double esc to avoid to be confused//~vawbI~
//vaw8:140531 (W32UNICODE:BUG)invalid name format errmsg is too long//~vaw8I~
//vaw7:140531 (W32UNICODE:BUG)cmd retrieve(F12) fail to recover UTF8 code(UD string)//~vaw7I~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vavk:140425 (BUG)cmd retrieve miss to recovery utf8 encoding     //~vavkI~
//vaum:140313 (BUG)same as vau2,occurs on retrieve cmd over session//~vaumI~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//vais:130607 Axe:xehelp errmsg is not draw justafter menu selected(missing invalidation of xxemain_scrinvalidate)//~vaghI~
//vagh:120824 REDO test on also Linux                              //~vaghI~
//vagc:120824 (BUG)DUMMYPROC use printf;string remains on cmdline if Linux//~vagcI~
//vag2:120811 REDo suupport                                        //~vag2I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  redefine ULONG by ULPTR(unsigned __int64)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va8t:101205 (BUG)hexinput mode change requires another split screen hdr line is re-drawn//~va8tI~
//va70:000701 LP64 option support                                  //~va70I~
//va6U:100725 (BUG) inifile valid char tbl was not effective       //~va6UI~
//va5r:100512 (BUG)cmd stack u8 codetype will be lost              //~va5rI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3T:100322 Hex cmd:add option to zigzag csr move mode HEX [YZ|NZ]//~va3TI~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va3J:100313 hexinput mode;allow odd number hex digit when x key pressed//~va3JI~
//va3H:100313 hexinput mode prefix for ucs,v:ucs4,default wait 2 byte//~va3HI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va2f:091229 (BUG)abend exe cmd for label process err;"exe * .a .b"//~va2fI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            func2.c :hexinput mode is 4byte ucs code input       //~va20I~
//                    :dd2f for exe cmd from utf8 file             //~va20I~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//v7ay:090426*(LNX)add helpdir for rpm bin package                 //~v7ayI~
//v7ar:090320 add ? option(help function) to RESet cmd.            //~v7arI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v78r:080326*profile function                                     //~v78rI~
//v77L:080206 (BUG)EXE cmd ABEND when "END" cmd closed all panel   //~v77LI~
//v77K:080205 EXE cmd support parameter file EXE ___ [< { wildcard[{[p][f]}] | @filename} ]//~v77KI~
//v778:071204*(BUG)after hex input by C+F11,dbcstbl recalc required//~v778I~
//v777:071204*EUC hankana chk(2byte but 1 column)                  //~v777I~
//v76W:071107*add Japanese msg to uerrexit test msg for UTF8 test  //~v76WI~
//v76p:070628 compare remote file support                          //~v76pI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75T:070520 (LNX)refer config.h for helpdir                      //~v75TI~
//v754:070418 (BUG)for invalid ini file(cmd stack write failed status),sta fail by malloc len=0//~v754I~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730I~
//v71C:061101 (LNX)search more directory for linux help            //~v71CI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69X:060720 (XXE)line-draw support also fo gxe when OPT LINECH ON.(v69M)//~v69XI~
//v69W:060720 one more RESet level;to clear label lcmd use "RES L" or 3 times continuous Esc key press.//~v69WI~
//v69M:060713 (LNX)Change line drawing char effectiveness to optional. OPT LINECHAR [on|off]//~v69MI~
//                 (no code in iso8859 but in old IBM-PC Extended Char Set(ECS) only)//~v69MI~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v651:050712 (XXE)xxe support;AT cmd,sleep cmd                    //~v651I~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v63n:050510 (LNX)revese  mouse selected line on dirlist          //~v63nI~
//v63m:050510 (WXE)draw screen between exe cmd file                //~v63mI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v63d:050429 write pid on cmdlog                                  //~v63dI~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v62H:050413 exe cmd label support                                //~v62HI~
//v62G:050412 cmdlog function                                      //~v62GI~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v60y:050202 exe cmd *2 option(use other split screen file)       //~v60yI~
//v60w:050202 skip ubell() for each cmd for performance reason,ubell at last if err//~v60yI~
//v60v:050201 virtual hex display option(/Mx,HEX on/off,prev HEX is XIN)//~v60vI~
//v60p:050129 (W32)kick winhlp32 by help cmd                       //~v60pI~
//v603:041220 multiline errmsg support(for find help msg)          //~v603I~
//v58A:041009 exe cmd:*\,:: support for filename                   //~v58AI~
//v58u:040926 execmd ignore err option;"!" char before cmdname like as "!find a *.c"//~v58uI~
//            or cmdfilename itself to ignore all cmd err          //~v58uI~
//v56u:040410 (BUG:WXE)exe cmd only process 1st cmd of multi-cmd line//~v56uI~
//v563:040325 (WIN)reject sleep and at cmd in exe cmd file         //~v563I~
//v562:040325 (WIN)AT cmd support                                  //~v562I~
//v561:040325 (WIN)break sleep by esc*2                            //~v561I~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Y:040324 (WIN)Sleep cmd for multicmd                          //~v55YI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55D:040307 (WXE)kick wxe.hlp by help cmd                        //~v55DI~
//v55n:040218 EXE cmd(execute xe command file)                     //~v55nI~
//v48i:020505 (BUG)too many opd if short cut string has embedding space.//~v47kI~
//v47k:020309 support cmd repeat key(alt+F11)                      //~v47kI~
//v45C:011227 change func_help;browse *.htx-->"see menu" msg       //~v45CI~
//v424:010920 UNX:change scrclear for dbcs split to option (--c)   //~v424I~
//v40r:010609 (BUG)used freed pcw at quit,caused abend             //~v40rI~
//v21k:010113 LINUX support:dbcs ctl should be under kon even if euc//~v21kI~
//v21i:010113 LINUX support:euc code dbcs support                  //~v21iI~
//v218:001126 LINUX support:protect unprintable char on other thna file data area.//~v218I~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v171:000422 (TEST)console reset to redraw unabalable trouble test//~v171I~
//v161:000409 (BUG)when vsplitted with short cmd line space,       //~v161I~
//            RET cmd from PF4 is destroyed.                       //~v161I~
//            (if cmd space=0,it also destroy 1 byte before).      //~v161I~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v133:990911 no dbcs chk when binary file                         //~v132I~
//v132:990911 accept inhibit char input when hex input mode on binary file//~v132I~
//v11B:990821 no storage cmd stack limit for not DOS(write in limit to !save!)//~v11BI~
//v11u:990813 hidden line reset by reset x cmd                     //~v11uI~
//v117:990612 end hex input mode at inetrmedeate of DBCS by "x" key//~v117I~
//v10H:990417 (BUG)uerrmsg parm count chk by xuerpck               //~v10HI~
//v101:981205 hex input                                            //~v101I~
//v0jn:980723 KEY cmd                                              //~v0inI~
//v0im:980627 pfk cmd support(long cmd ove screenwidth)            //~v0imI~
//v0i5:980511 TRACE for debug NT strip                             //~v0i5I~
//v0hm:980215 pend/err lcmd reset by double Esc or typed RESET     //~v0hmI~
//v0a2:970705:allow 00 input                                       //~v0a2I~
//            inhibit chk at func_char(null is EXT key)            //~v0a2I~
//            null input inhibit other than file data field inpt   //~v0a2I~
//v095:970405:DPMI version                                         //~v095I~
//            -abend when double Esc(test func) like as W32,OS/2   //~v095I~
//v08v:961208:help file name change .doc -->.htx                   //~v08vI~
//v086:961024:it can be share xe!save! file(int size)              //~v086I~
//v085:961024:W95 VC                                               //~v085I~
//            free destroy free area(need UGETQNEXT before ufree),or may pagefree//~v085I~
//v07x:960923:(BUG)one ESC trated as double ESC at first time after kick//~v07xI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06K:960421:(BUG)=xxx cmd duplicated on stack                    //~v06KR~
//v06J:960421:(BUG of v065)cmd stack stack is reverse seq          //~v06JR~
//v065:960217:save also cmd history to XE!SAVE!                 //~v065I~
//v04h:951007:retrive re-design,same as doskey(no wrap around)  //~v04hI~
//v04g:951007:(BUG)retrive cmd;no cut occur when not file screen//~v04gI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v03s:950827:for test,option to abend/uerrexit by double Esc(/DxxA or//~v03sI~
//            /DxxE)                                            //~v03sI~
//*v034:950715:use func_char_pan for dir                        //~v034I~
//*v032:950712:UFLD for each ppc(fld full event for DIR,reset v030)//~v032I~
//*v030:950709:for dir,share func_char_file                     //~v030I~
//*     950709:do not go fieldevent for dir panel               //~v030I~
//*            (getfldpos abend because ppd is defined only 3 line)//~v030I~
//*v020:950611:dir support(field full intercept)                //~5617I~
//*     950616:move getuflde from xepan to xesub                //~v020I~
//*     950625:func addr tbl                                    //~v020I~
//*     950708:del dummy func_dos                               //~v020I~
//*v011:950610:clear reverse when double ESC enter              //~5610I~
//************************************************************* //~5610I~
//* 950503 help ini operand                                     //~5503I~
//* 950428 help                                                 //~5503I~
//* 950423 scroll when screen limit                             //~5423R~
//* 941207 normal return(free area) when also quit              //~5423I~
//*************************************************************
#ifdef HAVE_CONFIG_H                                               //~v75TI~
#  include <config.h>                                              //~v75TI~
#endif                                                             //~v75TI~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
    	#include <dos.h>                                           //~v77KI~
    	#include <windows.h>                                       //~v171R~
	#else                                                          //~v085I~
        #define INCL_BASE                                          //~v171R~
        #include <os2.h>                                           //~v171R~
	#endif                                                         //~v085I~
#endif
//*******************************************************
#include <ulib.h>                                                  //~vafkI~
#include <uque.h>
#include <uerr.h>
//#include <ulib.h>                                                //~vafkR~
#include <ualloc.h>                                             //~5114I~
#include <ufile.h>                                              //~5318I~
#include <ustring.h>                                               //~v0imI~
#include <udbcschk.h>                                              //~v0inI~
#include <uedit.h>                                                 //~v101I~
#include <uvio.h>                                                  //~v171R~
#include <uparse.h>                                                //~v62HI~
#include <uproc2.h>                                                //~v63dI~
#include <uftp.h>                                                  //~v76pI~
#ifdef UNX                                                         //~v47kI~
	#include <uviol.h>                                             //~v47kI~
#endif                                                             //~v47kI~
#include <utrace.h>                                                //~v79zI~
#include <utf22.h>                                                 //~va3HI~
#include <ucvucs.h>                                                //~va3JI~
#include <ukbd.h>                                                  //~va3JI~
#include <ufilew.h>                                                //~vavkI~
                                                                //~5114I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"
#include "xecsr.h"
#include "xefunc.h"
#include "xefunc2.h"                                            //~5114I~
#include "xefunct.h"                                               //~v705I~
#include "xefile.h"                                             //~5318R~
#include "xefile14.h"                                              //~vbi3I~
#include "xefile3.h"                                            //~5423R~
#include "xedir.h"                                                 //~v137I~
#include "xecap.h"                                              //~5318I~
#include "xepan.h"                                              //~5318I~
#include "xepan2.h"                                             //~v020I~
#include "xesub.h"                                              //~5318I~
#include "xeini.h"                                              //~5503I~
#include "xelcmd.h"                                                //~v0hmI~
#include "xelcmd2.h"                                               //~v11uI~
#include "xelcmd4.h"                                               //~v58uI~
#include "xedlcmd.h"                                               //~v0hmI~
#include "xedlcmd6.h"                                              //~v71AI~
#include "xekbd.h"                                                 //~v0inI~
#include "xeerr.h"                                                 //~v0inI~
#include "xegbl.h"                                                 //~v21iI~
#include "xedcmd.h"                                                //~v58AI~
#include "xedcmd2.h"                                               //~v60pI~
#include "xefcmd22.h"                                              //~vbCBI~
#include "xefcmd24.h"                                              //~v62fI~
#include "xefcmd4.h"                                               //~v62HI~
#include "xeopt.h"                                                 //~v62GI~
#include "xefcmd6.h"                                               //~v78rI~
#ifdef XXE                                                         //~v651I~
	#include "xxexei.h"                                            //~v651I~
#endif                                                             //~v651I~
#ifdef W32                                                         //~v60pI~
#ifdef WXE                                                         //~v55DI~
	#include "wxexei.h"                                            //~v55DI~
#else                                                              //~v60pI~
//  #include "..\mfc\wxe\wxehelp.h"                                //~v71AR~
#endif                                                             //~v55DI~
#endif                                                             //~v60pI~
#include "xedir4.h"                                                //~v777I~
#ifdef UTF8SUPPH                                                   //~va1rI~
#include "xeutf.h"                                                 //~va1rI~
#endif                                                             //~va1rI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeundo.h"                                                //~vag2I~
//#ifdef W32          //test on windows at first                   //~vaghR~
    #define REDO    //                                             //~vaghR~
//#endif                                                           //~vaghR~
#include "xefsubw.h"                                               //~vavkI~
//**************************************************
#define EXECMD_IGNORE_ERRID '!'   //ignore rc>=4 for exe cmd       //~v58uI~
#define EXE_MAXREDIRECTCMD  100                                    //~v77KM~
#define EXE_REDIRECTLOG  "::#exe"     //exe cmd log                //~v77KR~
#define EXE_ERRMSGLOG(fhlog) \
           { char *perrmsg;                        \
			 if (perrmsg=ugeterrmsg2(),perrmsg)    \
				 fprintf(fhlog,"%s\n",perrmsg);    \
           }                                                       //~v77KR~
//**************************************************               //~v101I~
static 	FTFUNC *Sfunc_end[UCWMAXTYPE]                           //~v020I~
			={func_end_pan,func_end_file,func_end_dir};         //~v020I~
static PUSCMD Scurstack=0;                                         //~v55nR~
static int    Sprevdest=0;	//repeat retrieve                      //~v55nR~
static int    Sesc2ctr=0;                                          //~v562R~
static int    Sesc3ctr=0;   //Esc repeated 3 times                 //~v69WI~
static int    Sretreivescrsw=0;                                    //~v670I~
static int    Sretreivecmdtype=0;                                  //~v670I~
                                                                //~v020I~
static int    Sstackctsw=0;                                        //~va1rI~
static int    Suscentryno=0;                                       //~vbi3I~
//**************************************************               //~v0hmI~
int funcretrieve(PUCLIENTWE Ppcw,int Pdest);                    //~v04hR~
int  funcinhibitkey2(int Pchar);                                   //~v218R~
//int func_reset2(PUCLIENTWE Ppcw);                                //~v69WR~
int func_reset2(PUCLIENTWE Ppcw,int Popt);                         //~v69WI~
int  funchexerr(void);                                             //~v101I~
//int execmdsub(PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw);//~v58uR~
//int execmdsub(PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw,int *Pignorerc);//~v62JR~
void  	funcexefreeredirect(char **Ppbuff,int Pentno);             //~v77KI~
                                                                   //~v77KI~
#define FERO_IGNORERC         0x01     //whole ignore rc!=0        //~v77KR~
#define FERO_2NDLOOP          0x02     //1sttime sw to screen draw //~v77KR~
#define FERO_DIRONLY          0x04     //select dir only           //~v77KI~
#define FERO_ALSODIR          0x08     //select dir and file       //~v77KI~
int funcexeredirect_cmdcall(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,FILE *Pfhlog);//~v77KR~
int funcexeredirect_parmfile(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,char *Pparmfile,FILE *Pfhlog);//~v77KI~
int funcexeredirect_wildcard(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,char *Pwildcard,FILE *Pfhlog);//~v77KR~
int funcexeredirect_select(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,char *Pwildcard,FILE *Pfhlog);//~v77KI~
int funcexeredirect(int Popt,FILE *Pfhlog,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,//~v77KR~
					char *Ppredirectparm,UPODELMTBL *Ppodt,int Predirectparmno);//~v77KR~
FILE *funcexelogopenclose(int Popt,char *Pcomment);                //~v77KI~
#define FEL_OPEN       0x01                                        //~v77KR~
#define FEL_CLOSE      0x02                                        //~v77KR~
#define FEL_ERR        0x04      //log at close                    //~v77KR~
                                                                   //~va1rI~
#ifdef UTF8SUPPH                                                   //~va1rI~
	int funcsetlongcmdfromstack(PUCLIENTWE Ppcw,int Popt,PUSCMD Ppsc,int *Psetlen);//~va1rI~
#endif                                                             //~va1rI~
//#ifdef UTF8UCS4                                                    //~va3JI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
	#define KEYDATAUPC_ISUCS(upch) ((upch)=='U'||(upch)=='V')      //~va3JI~
#else                                                              //~va3JI~
	#define KEYDATAUPC_ISUCS(upch) ((upch)=='U')                   //~va3JI~
#endif                                                             //~va3JI~
//**************************************************               //~va3JI~
//*odd number hex digit                                            //~va3JI~
//**************************************************               //~va3JI~
int funcxkbdoddxdigit(int Popt,PUCLIENTWE Ppcw,int Phexdlen,ULONG *Ppucs)//~va3JR~
{                                                                  //~va3JI~
	ULONG ucs;                                                     //~va3JI~
//******************                                               //~va3JI~
    Ghexctl[HEXCTL_DATA+Phexdlen]='0';  //last digit               //~va3JI~
    ugethex(Ghexctl+HEXCTL_DATA,Ghexctl+HEXCTL_BIN,Phexdlen+1);    //~va3JI~
//  ucs=UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN); //anyway get 3 byte//~va3JI~//~vb2DR~
    ucs=(ULONG)UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN); //anyway get 3 byte//~vb2DI~
    ucs>>=4;                                                       //~va3JI~
    if (Phexdlen==1)                                               //~va3JI~
    {                                                              //~va3JI~
        ucs>>=16;                                                  //~va3JI~
        Ghexctl[HEXCTL_BIN]=(UCHAR)ucs;                            //~va3JI~
    }                                                              //~va3JI~
    else                                                           //~va3JI~
    if (Phexdlen==3)                                               //~va3JI~
    {                                                              //~va3JI~
        ucs>>=8;                                                   //~va3JI~
        UTF_SETUCSBESTR(ucs,Ghexctl+HEXCTL_BIN);    //2 byte       //~va3JI~
    }                                                              //~va3JI~
    else                                                           //~va3JI~
        UTF_SETUCS4TOBESTR(ucs,Ghexctl+HEXCTL_BIN);//3 byte        //~va3JI~
    *Ppucs=ucs;                                                    //~va3JI~
    return 0;                                                      //~va3JI~
}//funcxkbdoddxdigit                                               //~va3JI~
#ifdef UTF8UCS2                                                    //~va3JI~
//**************************************************               //~va3JI~
//*set utf8 & locale  to pcw                                       //~va3JI~
//**************************************************               //~va3JI~
int funcxkbsetmbstr(int Popt,PUCLIENTWE Ppcw,ULONG Pucs)           //~va3JI~
{                                                                  //~va3JI~
    UCHAR *plc;                                                    //~va3JI~//~va5rR~
	int u8len,opt,lclen,rc;                                        //~va3JI~
//*************************                                        //~va3JI~
//  u8len=uccvucs2utf(Pucs,Ppcw->UCWkeydata_utf8str);              //~va3JI~//~vb2DR~
    u8len=uccvucs2utf((UWUCS)Pucs,Ppcw->UCWkeydata_utf8str);       //~vb2DI~
    Ppcw->UCWkeydata_utf8str[u8len]=0;                             //~va3JI~
    plc=Ppcw->UCWkeydata;                                          //~va3JI~
    opt=XEUTFCVO_OUTPARM|XEUTFCVO_ERRREPQM|XEUTFCVO_CPLC;          //~va3JI~
    rc=xeutf_cvdata(opt,Ppcw->UCWkeydata_utf8str,u8len,&plc,&lclen);//~va3JI~
	Ppcw->UCWkeytype=UCWKTSBCS;		//dbcs                         //~va3JI~
    if (lclen>=2)                                                  //~va3JI~
    {                                                              //~va3JI~
    	Ppcw->UCWkeytype=UCWKTDBCS;                                //~va3JI~
        if (lclen==3)                                              //~va3JI~
    		Ppcw->UCWnls|=KBDNLS_SS3;                              //~va3JI~
        else                                                       //~va3JI~
        if (lclen==4)                                              //~va3JI~
    		Ppcw->UCWnls|=KBDNLS_GB4;                              //~va3JI~
    }                                                              //~va3JI~
    return rc;                                                     //~va3JI~
}//funcxkbsetmbstr                                                 //~va3JI~
//**************************************************               //~va3JI~
//*hex input on not file contents                                  //~va3JI~
//*rc:0:processed return to main,1:send to charfldedit,4:err       //~va3JI~
//*   -1:usual char input process                                  //~va3JI~
//**************************************************               //~va3JI~
int funcpanxkbd(PUCLIENTWE Ppcw,int *Pphexdlen,ULONG *Ppucs)       //~va3JI~
{                                                                  //~va3JI~
static int Skbdinpctr=0;                                           //~va3JI~
    char  keydata;                                                 //~va3JI~
    UINT hexdlen;                                                  //~va3JI~
    ULONG ucs=0;                                                   //~vaf9R~
	int swsendodd,keydataupc,oldmode,rcsry,pfli,swsend=0;          //~va3KR~
	PUFLD    pfl;                                                  //~va3KI~
	PUPANELC ppc;                                                  //~va3KI~
    PUPANELL pupl;                                                 //~va3KI~
//****************************                                     //~va3JI~
	rcsry=Ppcw->UCWrcsry;                                          //~va3KI~
	ppc=Ppcw->UCWppc;                                              //~va3KI~
    pupl=ppc->UPCline+rcsry;                                       //~va3KR~
	if ((rcsry==CMDLINENO)                                         //~va3KI~
    ||  ((Ppcw->UCWtype==UCWTDIR)                                  //~va3KR~
	     && (pfli=fldprotchk(Ppcw,FPC_DBCSCHK,&pfl),pfli==PANL310RENAME)//~va3KI~
        )                                                          //~va3KI~
    ||  (pupl->UPLbuffbyutf8)                                      //~va3KI~
    )                                                              //~va3KI~
    	;                                                          //~va3KI~
    else                                                           //~va3KI~
    	return -1;	//usual char input                             //~va3KI~
    swsendodd=0;                                                   //~va3KI~
    oldmode=Ghexctl[HEXCTL_MODE];   //current hex mode             //~va3KI~
    hexdlen=(UINT)Ghexctl[HEXCTL_LEN];                             //~va3KI~
	keydata=*Ppcw->UCWkeydata;                                     //~va3KI~
	keydataupc=toupper(keydata);                                   //~va3KI~
	scrclearmsg(Ppcw);          //re-draw hdr line                 //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3KI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    if (keydataupc=='V')   //explicitly ucs4                       //~va3KI~
    {                                                              //~va3KI~
        Ghexctl[HEXCTL_MODE]|=HEXCTL_MODE_UCS4; //ucs4(wait 3 byte //~va3KI~
//      Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS2;    //ucs4(wait 3 byte//~va3KI~//~vb2DR~
        Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS2);    //ucs4(wait 3 byte//~vb2DI~
        if (!hexdlen)                                              //~va3KI~
        {                                                          //~va3KI~
	    	if ((Skbdinpctr+1)==Gkbdinpctr                         //~va3KI~
			&&  oldmode & HEXCTL_MODE_UCS4	//dup key press        //~va3KI~
        	)                                                      //~va3KI~
        		return -1;	//accept "v" as char                   //~va3KI~
	        Skbdinpctr=Gkbdinpctr;                                 //~va3KI~
            return 0;                                              //~va3KI~
        }                                                          //~va3KI~
        if (hexdlen & 0x01) //odd number digit                     //~va3KI~
        {                                                          //~va3KI~
//          funcxkbdoddxdigit(0,Ppcw,hexdlen,&ucs);                //~va3KI~//~vb2DR~
            funcxkbdoddxdigit(0,Ppcw,(int)hexdlen,&ucs);           //~vb2DI~
            swsendodd=1;                                           //~va3KI~
        }                                                          //~va3KI~
        else                                                       //~va3KI~
        {                                                          //~va3KI~
        	hexdlen--;                                             //~va3KI~
        	swsend=1;                                              //~va3KI~
        }                                                          //~va3KI~
    }                                                              //~va3KI~
    else                                                           //~va3KI~
#endif                                                             //~va3KI~
    if (keydataupc=='U')   //explicitly ucs2                       //~va3KI~
    {                                                              //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3KI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
//  	Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS4;	//reset,wait 2 byte//~va3KI~//~vb2DR~
    	Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS4);	//reset,wait 2 byte//~vb2DI~
#endif                                                             //~va3KI~
		Ghexctl[HEXCTL_MODE]|=HEXCTL_MODE_UCS2;	//reset,wait 2 byte//~va3KI~
        if (!hexdlen)                                              //~va3KI~
        {                                                          //~va3KI~
    		if ((Skbdinpctr+1)==Gkbdinpctr                         //~va3KI~
			&&  Ghexctl[HEXCTL_MODE] & HEXCTL_MODE_UCS2	//dup key press//~va3KI~
        	)                                                      //~va3KI~
        		return -1;	//accept "v" as char                   //~va3KI~
	        Skbdinpctr=Gkbdinpctr;                                 //~va3KI~
	        return 0;                                              //~va3KI~
        }                                                          //~va3KI~
        if (hexdlen & 0x01) //odd number digit                     //~va3KI~
        {                                                          //~va3KI~
//          funcxkbdoddxdigit(0,Ppcw,hexdlen,&ucs);                //~va3KI~//~vb2DR~
            funcxkbdoddxdigit(0,Ppcw,(int)hexdlen,&ucs);           //~vb2DI~
            swsendodd=1;                                           //~va3KI~
        }                                                          //~va3KI~
        else                                                       //~va3KI~
        {                                                          //~va3KI~
        	hexdlen--;                                             //~va3KI~
        	swsend=1;                                              //~va3KI~
        }                                                          //~va3KI~
    }                                                              //~va3KI~
    else                                                           //~va3KI~
    if (keydataupc=='X')                                           //~va3KI~
    {                                                              //~va3KI~
    	if (!hexdlen) //odd number digit                           //~va3KR~
        {                                                          //~va3KI~
			if (oldmode & HEXCTL_MODE_UCS)                         //~va3KR~
            {                                                      //~va3KI~
//  			Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS;	//reset ucs//~va3KI~//~vb2DR~
    			Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS);	//reset ucs//~vb2DI~
                return 0;                                          //~va3KI~
            }                                                      //~va3KI~
    	    return -1;                                             //~va3KR~
        }                                                          //~va3KI~
        if (hexdlen & 0x01) //odd number digit                     //~va3KI~
        {                                                          //~va3KI~
//          funcxkbdoddxdigit(0,Ppcw,hexdlen,&ucs);                //~va3KI~//~vb2DR~
            funcxkbdoddxdigit(0,Ppcw,(int)hexdlen,&ucs);           //~vb2DI~
            swsendodd=1;                                           //~va3KI~
        }                                                          //~va3KI~
        else                                                       //~va3KI~
        {                                                          //~va3KI~
        	hexdlen--;                                             //~va3KI~
        	swsend=1;                                              //~va3KI~
        }                                                          //~va3KI~
    }                                                              //~va3KI~
	if (!(oldmode & HEXCTL_MODE_UCS))	//prefix u or v is mandotory for cmd line//~va3KI~
        return -1;	//usual char input process                     //~va3KI~
    if (!swsendodd)                                                //~va3KI~
    {                                                              //~va3KI~
      	if (keydataupc=='X'||KEYDATAUPC_ISUCS(keydataupc))         //~va3KR~
      	{                                                          //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3KI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
        	if (hexdlen==4) //UCS2 input                           //~va3KI~
            	hexdlen=3;		//pass to switch stmt              //~va3KI~
        	else                                                   //~va3KI~
#endif                                                             //~va3KI~
            	hexdlen=1;		//pass to switch stmt              //~va3KI~
	  	}                                                          //~va3KI~
	  	else                                                       //~va3KI~
      	{                                                          //~va3KI~
        	if (!isxdigit(keydata))                                //~va3KI~
            	return funchexerr();                               //~va3KI~
        	Ghexctl[HEXCTL_LEN]++;                                 //~va3KI~
        	Ghexctl[HEXCTL_DATA+hexdlen]=(UCHAR)keydata;           //~va3KI~
      	}                                                          //~va3KI~
    }//swsendodd                                                   //~va3KI~
    switch (hexdlen)                                               //~va3KI~
    {                                                              //~va3KI~
    case 0:                                                        //~va3KI~
    case 2:                                                        //~va3KI~
        return 0;           //required more hex input              //~va3KI~
    case 1:                                                        //~va3KI~
    	if (swsend)                                                //~va3KI~
        	ucs=Ghexctl[HEXCTL_BIN];                               //~va3KI~
        else                                                       //~va3KI~
      	if (!swsendodd)   //not set force odd number digit         //~va3KI~
      	{                                                          //~va3KI~
        	ugethex(Ghexctl+HEXCTL_DATA,Ghexctl+HEXCTL_BIN,2);     //~va3KI~
            return 0;           //required more hex input          //~va3KI~
        }                                                          //~va3KI~
        break;                                                     //~va3KI~
    case 3:                                                        //~va3KI~
    	if (swsend)                                                //~va3KI~
//      	ucs=UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);               //~va3KI~//~vb2DR~
        	ucs=(ULONG)UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);        //~vb2DI~
        else                                                       //~va3KI~
      	if (!swsendodd)   //not set force odd number digit         //~va3KI~
      	{                                                          //~va3KI~
        	ugethex(Ghexctl+HEXCTL_DATA+2,Ghexctl+HEXCTL_BIN+1,2); //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3KI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
		  	if (oldmode & HEXCTL_MODE_UCS4)	//ucs4(wait 3 byte)    //~va3KR~
            	return 0;                                          //~va3KI~
#endif                                                             //~va3KI~
//      	ucs=UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);               //~va3KI~//~vb2DR~
        	ucs=(ULONG)UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);        //~vb2DI~
        }                                                          //~va3KI~
        break;                                                     //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3KI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
    case 4:                                                        //~va3KI~
        return 0;           //required more hex input              //~va3KI~
    case 5:                 //3rd byte of ucs4                     //~va3KI~
    	if (swsend)                                                //~va3KI~
//      	ucs=UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN);          //~va3KI~//~vb2DR~
        	ucs=(ULONG)UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN);   //~vb2DI~
        else                                                       //~va3KI~
      	if (!swsendodd)   //not set force odd number digit         //~va3KI~
      	{                                                          //~va3KI~
        	ugethex(Ghexctl+HEXCTL_DATA+4,Ghexctl+HEXCTL_BIN+2,2); //~va3KI~
//      	ucs=UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN);          //~va3KI~//~vb2DR~
        	ucs=(ULONG)UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN);   //~vb2DI~
      	}                                                          //~va3KI~
        if (ucs>UCS4_MAX)                                          //~va3KI~
        {                                                          //~va3KI~
            Ghexctl[HEXCTL_LEN]=0;      //reset                    //~va3KI~
            uerrmsg("Too large UCS4 value(max:%06x)",0,            //~va3KI~
                    UCS4_MAX);                                     //~va3KI~
            return 4;   //internal logic err                       //~va3KI~
        }                                                          //~va3KI~
        break;                                                     //~va3KI~
#endif                                                             //~va3KI~
	default:                                                       //~va3KI~
        Ghexctl[HEXCTL_LEN]=0;		//reset                        //~va3KI~
        uerrmsg("Buff full,max 6digit for Hex digit Input mode,Use BackSpace or Exit the mode",0);//~va3KI~
        return 4; 	//internal logic err                           //~va3KI~
    }                                                              //~va3KI~
    Ghexctl[HEXCTL_LEN]=0;      //transfered                       //~va3JI~
    keydata=*Ppcw->UCWkeydata;                                     //~va3JI~
    if (!ucs)     //null input                                     //~va3KR~
	    return  funcinhibitkey2(keydata);                          //~va3JI~
	funcxkbsetmbstr(0,Ppcw,ucs);                                   //~va3KR~
    if (!KEYDATAUPC_ISUCS(keydataupc))                             //~va3KR~
//  	Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS;	//u or v is required each time//~va3JI~//~vb2DR~
    	Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS);	//u or v is required each time//~vb2DI~
    if (UTF8ISASCII(ucs))                                          //~va3KR~
    {                                                              //~va3JI~
		*Ppcw->UCWkeydata=(UCHAR)ucs;                              //~va3KR~
    }                                                              //~va3JI~
    else                                                           //~va3JI~
    {                                                              //~va3JI~
    	UCBITON(Ppcw->UCWflag2,UCWF2UTF8STR);                      //~va3JI~
    	UCBITON(Ppcw->UCWflag3,UCWF3HEXKBD);                       //~va3JI~
//#ifdef UTF8UCS4                                                    //~va3JI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
		if (UTF_ISUCS4(ucs))                                       //~va3KR~
			UCBITON(Ppcw->UCWflag3,UCWF3HEXKBDUCS4);               //~va3JI~
#endif                                                             //~va3JI~
	}                                                              //~va3JI~
//  *Pphexdlen=hexdlen;                                            //~va3JI~//~vb2DR~
    *Pphexdlen=(int)hexdlen;                                       //~vb2DI~
    *Ppucs=ucs;                                                    //~va3KR~
    return 1;         //utf8 string input                          //~va3JI~
}//funcpanxkbd                                                     //~va3JI~
#endif	//UCS2                                                     //~va3JI~
//**************************************************            //~5114I~
//*char input process
//**************************************************
int func_char(PUCLIENTWE Ppcw)
{
static 	FTFUNC *Sfunc_char[UCWMAXTYPE]={func_char_pan,func_char_file,//~v020R~
										func_char_pan};//for dir list//~v034R~
//static UCHAR Snasciitblj[32]=                                 //~5216R~
//			{   0,1,2,3,4,   5,   6,   0,0,   0,0,0,0,   0,   0,   0,//~5216R~
//			 0x10,0,0,0,0,0x15,0x16,0x17,0,0x19,0,0,0,0x1d,0x1e,0x1f};//~5216R~
//static UCHAR Snasciitble[32]=                                 //~5216R~
//			{   0,1,2,3,4,   5,   6,   0,0,   0,0,0,0,   0,   0,   0,//~5216R~
//			 0x10,0,0,0,0,0x15,0x16,0x17,0,0x19,0,0,0,0x1d,0x1e,0x1f};//~5216R~
//static int Swarningsw=0;                                         //~v705R~
    FUNCTBL *pft;	//FUNKTBL ptr                               //~5216I~
    UCHAR keydata;                                                 //~v0a2I~
	int rc;
    int nullsw;                                                    //~v0a2I~
//  UINT hexdlen;                                                  //~va70R~
    int  hexdlen=0;                                                //~vaf9R~
//  int dbcssplitsw;                                               //~va3JR~
    int inhibitnochk;                                              //~v132I~
    int hexkbdsw;                                                  //~v778R~
    PUFILEH  pfh;                                                  //~v132I~
#ifdef UTF8UCS2                                                    //~va1CI~//~va3JR~
    ULONG ucs;                                                     //~va3JR~
#endif                                                             //~va3JR~
	int keydataupc;                                                //~va3HI~
	int swsendodd,oldmode,swsend;                                         //~va3JR~//~va3KR~
//****************************
//  if (Ppcw->UCWkeytype==UCWKTSBCS		//sbcs input            //~5225R~
//  &&  *Ppcw->UCWkeydata<0x20)	//not ascii                     //~5216R~
//  {                                                           //~5216R~
//  	if (UCBITCHK(Gscrstatus,GSCRSDBCS))	//japanese          //~5216R~
//  		rc=(int)Snasciitblj[*Ppcw->UCWkeydata];             //~5216R~
//  	else                                                    //~5216R~
//  		rc=(int)Snasciitble[*Ppcw->UCWkeydata];             //~5216R~
//  	if (!rc)                                                //~5216R~
//  		return 4;	//not accept                            //~5216R~
//  }                                                           //~5216R~
     nullsw=0;                                                      //~v0a2I~
	if (!Ppcw->UCWkeytype)	//pft exist
	{
		pft=Ppcw->UCWpfunct;                                    //~5225R~
		if (pft->FTfuncid>=FUNCID_GRAPHCHAR)                    //~5225R~
		{                                                       //~5225R~
			*Ppcw->UCWkeydata=pft->FTchar;                      //~5225R~
  			*(Ppcw->UCWkeydata+1)=0;                            //~5225R~
			Ppcw->UCWkeytype=UCWKTSBCS;		//sbcs              //~5225R~
			if (pft->FTfuncid==FUNCID_NULLCHAR)                    //~v0a2I~
            	nullsw=1;                                          //~v0a2I~
//#if defined(LNX) && !defined(XXE)                                //~v69XR~
//#ifdef LNX                                                       //~v705R~
            else        //line drawing char                        //~v69MI~
            {                                                      //~v69MI~
//                if (!UCBITCHK(Gopt5,GOPT5ACS)) //no acs mode     //~v705R~
//                {                                                //~v705R~
////                  if (!Swarningsw)                             //~v705R~
//                    if (Swarningsw<3) //3 times warning          //~v705R~
//                    {                                            //~v705R~
////                      Swarningsw=1;                            //~v705R~
//                        uerrmsg("\"OPT LINECH ON\" is required to display Line-Drawing-Character",//~v705R~
//                                "罫線表\示には \"OPT LINECH ON\" と設定する必要があります");//~v705R~
//                    }                                            //~v705R~
//                    Swarningsw++;                                //~v705R~
//                }                                                //~v705R~
                rc=funct2getinputgc(Ppcw,pft);	//UCWkeydata setup //~v705R~
UTRACEP("funct2getinputgc rc=%d,type=%d,data=%x%x\n",rc,Ppcw->UCWkeytype,*Ppcw->UCWkeydata,*(Ppcw->UCWkeydata+1));//~v79RI~//~v79zR~
                if (rc<0)                                          //~v705I~
                	return 0;	//retry from kbdinp for string input//~v705I~
                if (rc)	//err                                      //~v705I~
                	return rc;			//not sbcs nand dbcs;retry from kbd input//~v705R~
            }                                                      //~v69MI~
//#endif                                                           //~v705R~
		}                                                       //~5225R~
	}//pft exist                                               //~5225R~
                                                                   //~v101I~
    ucs=        //init for normal input mode for valid char tbl chk//~va6UI~
	keydata=*Ppcw->UCWkeydata;                                     //~v0a2R~
	keydataupc=toupper(keydata);                                   //~va3JR~
//hex input mode ctl                                               //~v101I~
	hexkbdsw=0;                                                    //~v778R~
    inhibitnochk=0;                                                //~v132I~
    swsendodd=0;                                                   //~va3JR~
    swsend=0;                                                      //~va3KI~
    oldmode=Ghexctl[HEXCTL_MODE];   //current hex mode             //~va3JI~
    pfh=0;			//pansw                                        //~va3KI~
    if (Ghexctl[HEXCTL_MODE]	//hex input mode                   //~v101I~
	&&  Ppcw->UCWtype==UCWTFILE      //file scr                    //~v101R~
    &&  CSRONFILEDATA(Ppcw))    //in data fld                      //~v101I~
    {                                                              //~v101I~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~v132M~
        if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                      //~v132M~
    		inhibitnochk=1;                                        //~v132M~
    	hexdlen=(UINT)Ghexctl[HEXCTL_LEN];                         //~v117M~
	    scrclearmsg(Ppcw);          //re-draw hdr line             //~v117M~
//#ifdef UTF8UCS4                                                    //~va3HI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
      	if (keydataupc=='V')   //explicitly ucs4                   //~va3JR~
      	{                                                          //~va3JR~
			Ghexctl[HEXCTL_MODE]|=HEXCTL_MODE_UCS4;	//ucs4(wait 3 byte//~va3JR~
//  		Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS2;	//ucs4(wait 3 byte//~va3JR~//~vb2DR~
    		Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS2);	//ucs4(wait 3 byte//~vb2DI~
        	if (!hexdlen)                                          //~va3JI~
        		return 0;                                          //~va3JR~
            if (hexdlen & 0x01)	//odd number digit                 //~va3JI~
            {                                                      //~va3JI~
				funcxkbdoddxdigit(0,Ppcw,hexdlen,&ucs);            //~va3JI~
                swsendodd=1;                                       //~va3JI~
            }                                                      //~va3JI~
      	}                                                          //~va3JR~
        else                                                       //~va3KI~
#endif                                                             //~va3JI~
      	if (keydataupc=='U')   //explicitly ucs2                   //~va3JR~
      	{                                                          //~va3JR~
//#ifdef UTF8UCS4                                                    //~va3JI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
//  		Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS4;	//reset,wait 2 byte//~va3JR~//~vb2DR~
    		Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS4);	//reset,wait 2 byte//~vb2DI~
#endif                                                             //~va3JI~
			Ghexctl[HEXCTL_MODE]|=HEXCTL_MODE_UCS2;	//reset,wait 2 byte//~va3JR~
        	if (!hexdlen)                                          //~va3JI~
	        	return 0;                                          //~va3JR~
            if (hexdlen & 0x01)	//odd number digit                 //~va3JI~
            {                                                      //~va3JI~
				funcxkbdoddxdigit(0,Ppcw,hexdlen,&ucs);            //~va3JI~
                swsendodd=1;                                       //~va3JI~
            }                                                      //~va3JI~
      	}                                                          //~va3JR~
        else                                                       //~va3KI~
      	if (keydataupc=='X')                                       //~va3JI~
      	{                                                          //~va3JI~
//          Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS; //reset,wait 2 byte//~va3JI~//~vb2DR~
            Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS); //reset,wait 2 byte//~vb2DI~
        	if (!hexdlen)                                          //~va3JI~
	        	return 0;                                          //~va3JI~
            if (hexdlen & 0x01)	//odd number digit                 //~va3JI~
            {                                                      //~va3JI~
				funcxkbdoddxdigit(0,Ppcw,hexdlen,&ucs);            //~va3JI~
                swsendodd=1;                                       //~va3JI~
            }                                                      //~va3JI~
      	}                                                          //~va3JI~
    if (!swsendodd)                                                //~va3JI~
    {                                                              //~va3JI~
//    if ((keydata=='x' || keydata=='X')                           //~va3JR~
      if ((keydataupc=='X'||KEYDATAUPC_ISUCS(keydataupc))          //~va3JR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
      && (hexdlen==2||hexdlen==4)	//4 for 3byte ucs4 input       //~va3xI~
      )                                                            //~va3xI~
#else                                                              //~va3xI~
      &&  hexdlen==2)                                              //~v117R~
#endif                                                             //~va3xI~
      {                                                            //~v117I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
        if (hexdlen==4) //UCS2 input                               //~va3xI~
        {                                                          //~va3xI~
//      	dbcssplitsw=1;  //breaksw                              //~va3JR~
            hexdlen=3;		//pass to switch stmt                  //~va3xI~
        }                                                          //~va3xI~
        else                                                       //~va3xI~
#endif                                                             //~va3xI~
        {                                                          //~va3xI~
//      	dbcssplitsw=1;                                         //~va3JR~
            hexdlen=1;		//pass to switch stmt                  //~v117R~
        }                                                          //~va3xI~
        swsend=1;                                                  //~va3KI~
	  }	                                                           //~v117I~
	  else	                                                       //~v117I~
      {                                                            //~v117I~
//      	dbcssplitsw=0;                                         //~va3JR~
        if (!isxdigit(keydata))                                    //~v101I~
            return funchexerr();                                   //~v101I~
                                                                   //~v101I~
        Ghexctl[HEXCTL_LEN]++;                                     //~v101I~
        Ghexctl[HEXCTL_DATA+hexdlen]=(UCHAR)keydata;               //~v101R~
      }                                                            //~v117I~
    }//swsendodd                                                   //~va3JR~
    	switch (hexdlen)                                           //~v101R~
        {                                                          //~v101I~
        case 0:                                                    //~v101I~
        case 2:                                                    //~v101I~
			return 0;  			//required more hex input          //~v101R~
        case 1:                                                    //~v101I~
          if (swsend)                                              //~va3KI~
	        ucs=Ghexctl[HEXCTL_BIN];                               //~va3KI~
          else                                                     //~va3KI~
          if (!swsendodd)	//not set force odd number digit       //~va3JR~
          {                                                        //~va3JR~
            ugethex(Ghexctl+HEXCTL_DATA,Ghexctl+HEXCTL_BIN,2);     //~v101R~
#ifdef UTF8UCS2                                                    //~va3JI~
            if (FILEUTF8MODE(pfh))                                 //~va3JI~
                return 0;           //required more hex input      //~va3JI~
#endif                                                             //~va3JI~
			if (oldmode & HEXCTL_MODE_UCS)                         //~va3JR~
				return 0;  			//required more hex input      //~va3JM~
	        ucs=Ghexctl[HEXCTL_BIN];                               //~va3KR~
          }                                                        //~va3JI~
         if (!inhibitnochk)	//not bin file                         //~v133I~
//        if (!dbcssplitsw)                                        //~va3JR~
          if (!swsend)                                             //~va3KI~
          {                                                        //~va20I~
//#ifdef UTF8UCS2                                                  //~va3JR~
//            if (FILEUTF8MODE(pfh))                               //~va3JR~
//                return 0;           //required more hex input    //~va3JR~
//#endif                                                           //~va3JR~
#ifdef UTF8UCS2                                                    //~va3JI~
           if (!(oldmode & HEXCTL_MODE_UCS))                       //~va3JI~
#endif                                                             //~va3JI~
           {                                                       //~va3JI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            if (!PFH_ISEBC(pfh))                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            {                                                      //~va50I~
#ifdef LNX                                                         //~v21iI~
//  		if (UCBITCHK(Gunxflag,GUNX_EUC))                       //~v21kR~
//          if ((Gunxflag & (GUNX_EUC|GUNX_KON))==(GUNX_EUC|GUNX_KON))//~v79zR~
            if (XE_ISDBCSKON())	//CJK DBCS on KON                  //~v79zR~
#else                                                              //~v21iI~
            if (UCBITCHK(Gscrstatus,GSCRSDBCS))                    //~v101I~
#endif                                                             //~v21iI~
//              if (udbcschk(Ghexctl[HEXCTL_BIN]))                 //~v777R~
                if (udbcschk_hk(0,Ghexctl[HEXCTL_BIN]))            //~v777I~
					return 0;  			//required more hex input  //~v101R~
            }//!EBCDIC                                             //~va50I~
           }                                                       //~va3JI~
          }                                                        //~va20I~
            Ppcw->UCWkeydata[0]=Ghexctl[HEXCTL_BIN];               //~v101I~
        	break;                                                 //~v101I~
        case 3:                                                    //~v101I~
          if (swsend)                                              //~va3KI~
//      	ucs=UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);               //~va3KI~//~vb2DR~
        	ucs=(ULONG)UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);        //~vb2DI~
          else                                                     //~va3KI~
          if (!swsendodd)	//not set force odd number digit       //~va3JR~
          {                                                        //~va3JI~
            ugethex(Ghexctl+HEXCTL_DATA+2,Ghexctl+HEXCTL_BIN+1,2); //~v101R~
//#ifdef UTF8UCS4                                                    //~va3xM~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
		  if (oldmode & HEXCTL_MODE_UCS4)	//ucs4(wait 3 byte)        //~va3JR~//~va3KR~
            	return 0;                                          //~va3xM~
#endif                                                             //~va3xM~
//      	ucs=UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);               //~va3JM~//~vb2DR~
        	ucs=(ULONG)UTF_GETUCSBESTR(Ghexctl+HEXCTL_BIN);        //~vb2DI~
          }                                                        //~va3JI~
            Ppcw->UCWkeydata[0]=Ghexctl[HEXCTL_BIN];               //~v101I~
            Ppcw->UCWkeydata[1]=Ghexctl[HEXCTL_BIN+1];             //~v101I~
			Ppcw->UCWkeytype=UCWKTDBCS;		//dbcs                 //~v101I~
            inhibitnochk=2;	//no chk for dbcs 1st byte             //~va3xI~
        	break;                                                 //~v101I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
        case 4:                                                    //~va3xI~
			return 0;  			//required more hex input          //~va3xI~
        case 5:                 //3rd byte of ucs4                 //~va3xI~
          if (!swsendodd)	//not set force odd number digit       //~va3JR~
          {                                                        //~va3JI~
            ugethex(Ghexctl+HEXCTL_DATA+4,Ghexctl+HEXCTL_BIN+2,2); //~va3KI~
//          ucs=UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN);          //~va3JR~//~vb2DR~
            ucs=(ULONG)UTF_GETUCS4FROMBESTR(Ghexctl+HEXCTL_BIN);   //~vb2DI~
          }                                                        //~va3JM~
            if (ucs>UCS4_MAX)                                      //~va3JR~
            {                                                      //~va3HI~
        		Ghexctl[HEXCTL_LEN]=0;		//reset                //~va3JI~
            	uerrmsg("Too large UCS4 value(max:%06x)",0,        //~va3HR~
			            UCS4_MAX);                                 //~va3HR~
	        	return 4; 	//internal logic err                   //~va3HI~
            }                                                      //~va3HI~
            Ppcw->UCWkeydata[0]=Ghexctl[HEXCTL_BIN];               //~va3xI~
            Ppcw->UCWkeydata[1]=Ghexctl[HEXCTL_BIN+1];             //~va3xI~
            Ppcw->UCWkeydata[2]=Ghexctl[HEXCTL_BIN+2];             //~va3xI~
			Ppcw->UCWkeytype=UCWKTDBCS;		//dbcs                 //~va3xI~
            inhibitnochk=3;        //no chk for ucs4               //~va3xI~
        	break;                                                 //~va3xI~
#endif                                                             //~va3xI~
		default:	                                               //~v101I~
        	Ghexctl[HEXCTL_LEN]=0;		//reset                    //~va3JI~
            uerrmsg("Buff full,max 6digit for Hex digit Input mode,Use BackSpace or Exit the mode",0);
        	return 4; 	//internal logic err                       //~v101R~
        }                                                          //~v101I~
        Ghexctl[HEXCTL_LEN]=0;		//transfered                   //~v101I~
		keydata=*Ppcw->UCWkeydata;                                 //~v101I~
        hexkbdsw=1;                                                //~v778R~
        if (!swsend && !swsendodd)                                            //~va3JI~//~va3KR~
//          Ghexctl[HEXCTL_MODE]&=~HEXCTL_MODE_UCS; //reset to simple HEX//~va3JI~//~vb2DR~
            Ghexctl[HEXCTL_MODE]&=(UCHAR)(~HEXCTL_MODE_UCS); //reset to simple HEX//~vb2DI~
    }                                                              //~v101I~
#ifdef UTF8UCS2                                                    //~va3KI~
    else                                                           //~va3KI~
  	if (oldmode)	//hex input mode not on file contents          //~va3KI~
    {                                                              //~va3KI~
      rc=funcpanxkbd(Ppcw,&hexdlen,&ucs);                          //~va3KI~
      if (!rc)                                                     //~va3KI~
          return 0;                                                //~va3KI~
      if (rc>1)                                                    //~va3KI~
          return 4;                                                //~va3KI~
      if (rc==1)                                                   //~va3KI~
          hexkbdsw=1;                                              //~va3KI~
      rc=0;                                                        //~va3KI~
    }                                                              //~va3KI~
#endif                                                             //~va3KI~
//inhibit chk after GRAPH char set(NULL is also defined as GRAPH(FUNCID>256)//~v101M~
   if (ucs<=0xff)                                                  //~va3KR~
	if (Gvalidchartbl[(int)keydata])                               //~v0a2I~
      if (!inhibitnochk)                                           //~v132I~
    	return  funcinhibitkey(keydata);                           //~v0a2I~
    if (nullsw)     //null input                                   //~v0a2I~
		if (Ppcw->UCWtype!=UCWTFILE     //not file scr             //~v0a2I~
    		||	!CSRONFILEDATA(Ppcw))	//not fidata area          //~v0a2I~
		    	return  funcinhibitkey2(keydata);                  //~v218R~
                                                                   //~v218I~
#ifdef UNX                                                         //~v218I~
   if (inhibitnochk<2)     //accept dbcs,ucs4                      //~va3xI~
    if(Gunpdispchartbl[(int)keydata])    //unprintable             //~v218I~
		if (Ppcw->UCWtype!=UCWTFILE     //not file scr             //~v218I~
    		||	!CSRONFILEDATA(Ppcw))	//not fidata area          //~v218I~
		    	return  funcinhibitkey2(keydata);	//unprintable is on file data only//~v218R~
                                                                   //~v218I~
#endif                                                             //~v218I~
    UCBITOFF(Ppcw->UCWflag,UCWFFIELDFULL);//on by charfldedit   //~v020R~
    if (hexkbdsw)                                                  //~v778M~
    {                                                              //~va3xI~
        UCBITON(Ppcw->UCWflag3,UCWF3HEXKBD);                       //~v778M~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
		if (oldmode & HEXCTL_MODE_UCS4                             //~va3JR~
		&&  hexdlen==5 	//3byte ucs                                //~va3JI~
        &&  UTF_ISUCS4(ucs)                                        //~va3JI~
        )                                                          //~va3KI~
	        UCBITON(Ppcw->UCWflag3,UCWF3HEXKBDUCS4);               //~va3xI~
        else                                                       //~va3JI~
#endif                                                             //~va3xI~
		if (oldmode & HEXCTL_MODE_UCS)                             //~va3JR~
	        UCBITON(Ppcw->UCWflag3,UCWF3HEXKBDUCS2);               //~va3JI~
		if (oldmode & HEXCTL_MODE_UCS                              //~va3JR~
        && pfh                                                     //~va3KI~
        &&  !FILEUTF8MODE(pfh))                                    //~va3JI~
        {                                                          //~va3JI~
			if (funcxkbsetmbstr(0,Ppcw,ucs))                       //~va3JR~
            {                                                      //~va3JI~
		       *(Ghexctl+HEXCTL_DATA+hexdlen+1)=0;                 //~va3JI~
            	uerrmsg("err,trancslation to locale code(%s)",0,   //~va3JI~
		            	Ghexctl+HEXCTL_DATA);                      //~va3JI~
                return 4;                                          //~va3JI~
            }                                                      //~va3JI~
	    	UCBITOFF(Ppcw->UCWflag2,UCWF2UTF8STR);                 //~va3JI~
        }                                                          //~va3JI~
	}                                                              //~va3xI~
//  if (rc=(Sfunc_char[Ppcw->UCWtype])(Ppcw),rc)                   //~v778R~
    rc=(Sfunc_char[Ppcw->UCWtype])(Ppcw);                          //~v778R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3R~
    UCBITOFF(Ppcw->UCWflag3,(UCWF3HEXKBD|UCWF3HEXKBDUCS4));        //~va3xI~
#else                                                              //~va3xI~
    UCBITOFF(Ppcw->UCWflag3,UCWF3HEXKBD);                          //~v778R~
#endif                                                             //~va3xI~
	UTRACEP("%s:after func_char rc=%d,reason=0x%x\n",UTT,rc,Ppcw->UCWreason);//~vbi3R~
    if (rc)                                                        //~v778R~
		return rc;
    if (Ppcw->UCWreason==UCWREASON_CHLNOSPLIT)                     //~vbi3I~
		rc=filecharcsr(Ppcw);                                      //~vbi3I~
    else                                                           //~vbi3I~
	if (Ppcw->UCWtype==UCWTFILE                                 //~5423R~
    &&	CSRONFILEDATA(Ppcw))	//file edit scr                 //~5225I~
		rc=filecharcsr(Ppcw);	//cursor move using UCWkeytype(datalen)//~5423R~
	else                                                           //~v777I~
	if (Ppcw->UCWtype==UCWTDIR                                     //~v777I~
    &&	CSRONFILEDATA(Ppcw))	//file edit scr                    //~v777I~
		rc=dircharcsr(Ppcw);	//cursor move using UCWkeytype(datalen)//~v777I~
	else                                                        //~5423I~
    {                                                           //~v020R~
    	if (UCBITCHK(Ppcw->UCWflag,UCWFFIELDFULL))//just field full//~v020R~
        {                                                       //~v020R~
			if (Ppcw->UCWtype==UCWTFILE)                        //~v032R~
		    	rc=func_nexttab_pan(Ppcw);	//csr set to next field//~v020I~
            else 	//panel                                     //~v020I~
            {                                                   //~v020I~
				UCBITOFF(Gprocstatus,GPROCSCSRSET);//to chk csrset//~v020I~
        		if (!(rc=panfieldevent(Ppcw,PFE_FULL)))	//intercept field full//~v020R~
					if (!UCBITCHK(Gprocstatus,GPROCSCSRSET))//csr set not requested//~v020R~
                    {                                              //~v137I~
						if (Ppcw->UCWtype==UCWTDIR)                //~v137R~
    						rc=dirnexttab(Ppcw);                   //~v137R~
        				else                                       //~v137R~
			        	rc=func_nexttab_pan(Ppcw);	//csr set to next field//~v020R~
                    }                                              //~v137I~
            }                                                   //~v020I~
        }                                                       //~v020R~
        else                                                    //~v020R~
        {                                                          //~v777I~
          if (Ppcw->UCWreason==UCWREASON_CSRBYKEYTYPE)             //~v777I~
          	csronthefld(Ppcw,Ppcw->UCWrcsry,FROMLEFT,Ppcw->UCWrcsrx+Ppcw->UCWkeytype);//~v777R~
          else                                                     //~v777I~
#ifdef FTPSUPP                                                     //~v8@ZI~
      	   if (UCBITCHK(Ppcw->UCWflag3,(UCWF33270KBD|UCWF33270KBD2))!=(UCWF33270KBD|UCWF33270KBD2))//~v8@ZI~
#endif                                                             //~v8@ZI~
			csrcharright(Ppcw);		//cursor move after draw    //~5617R~
        }                                                          //~v777I~
    }                                                           //~v020R~
    return rc;                                                  //~5225I~
}//func_char
//**************************************************               //~v0inI~
//*char input process for cmd key                                  //~v0inI~
//* no clear cmd line because 2 sequential key cmd clear prev effect//~v0inI~
//**************************************************               //~v0inI~
int func_key(PUCLIENTWE Ppcw)                                      //~v0inI~
{                                                                  //~v0inI~
    UCHAR *pc;                                                     //~v0inR~
    UCHAR inputc[3];                                               //~v0inI~
	int rc,keytype;                                                //~v0inR~
	UCHAR savecmd[sizeof(Gcmdbuff)];   //null term and long cmd id on offs=1//~v0inI~
//****************************                                     //~v0inI~
 	if (!(pc=Ppcw->UCWparm))				//parm exist           //~v0inI~
    	return errmissing();                                       //~v0inR~
    if (Ppcw->UCWopdno>1)                                          //~v0inR~
        return errtoomany();                                       //~v0inR~
	memcpy(savecmd,Gcmdbuff,sizeof(savecmd));                                    //to remain data on cmd line//~v0inR~
    *Gcmdbuff=0;			//for kbdproc,bypass UCWKTCMD set      //~v0inI~
    pc=Ppcw->UCWopdpot;	//enclosing qutation drop data             //~v48iR~
    for (rc=0;*pc;pc++)                                            //~v0inR~
    {                                                              //~v0inI~
		inputc[0]=*pc;                                             //~v0inR~
        if (udbcschk(inputc[0]) && *(pc+1))                        //~v0inR~
        {                                                          //~v0inI~
        	pc++;                                                  //~v0inI~
	  		inputc[1]=*pc;                                         //~v0inR~
			keytype=UCWKTDBCS;		//dbcs                         //~v0inR~
		}                                                          //~v0inI~
        else                                                       //~v0inI~
        {                                                          //~v0inI~
	  		inputc[1]=0;                                           //~v0inR~
			keytype=UCWKTSBCS;		//sbcs                         //~v0inR~
        }                                                          //~v0inI~
        Ppcw->UCWkeyshift=0;		//no need shift,bypss search   //~v0inI~
		if (rc=funccall(keytype,inputc,Ppcw),rc)                   //~v0inR~
        	break;                                                 //~v0inR~
        if (UCBITCHK(Gprocstatus,GPROCSCSRRIGHT|GPROCSCSRDOWN))    //~v0inR~
        {                                                          //~v0inI~
            scrdisp();          //update dbcs tbl for csr move     //~v0inI~
            if (rc=kbdproc(),rc)     //csr move                    //~v0inR~
            	break;                                             //~v0inI~
        }                                                          //~v0inI~
	}                                                              //~v0inI~
	memcpy(Gcmdbuff,savecmd,sizeof(savecmd));                                    //to remain data on cmd line//~v0inI~
    return rc;                                                     //~v0inI~
}//func_key                                                        //~v0inI~
                                                                   //~v0inI~
//**************************************************
//*QUIT cmdprocess(exit to cmd prompt witout save)              //~5224R~
//**************************************************
int func_quit(PUCLIENTWE Ppcw)
{
static 	FTFUNC *Sfunc_quit[UCWMAXTYPE]                          //~v020I~
			={func_cancel_pan,func_cancel_file,func_cancel_dir};//~v020I~
    UCHAR cmd[sizeof(((FUNCTBL*)0)->FTcmd)];                       //~v40rI~
	int rc;
//**************************************************
//  if (Ppcw->UCWtype==UCWTFILE)                                //~v020R~
//  	rc=func_cancel_file(Ppcw);                              //~v020R~
//  else									//not file          //~v020R~
//  	rc=func_cancel_pan(Ppcw);                               //~v020R~
	strcpy(cmd,((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);//save before pcw free//~v40rI~
	rc=(Sfunc_quit[Ppcw->UCWtype])(Ppcw);                       //~v020I~
	if (!rc)						//end completed
//  	strcpy(Gcmdbuff,((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);	//repeat//~v40rR~
    	strcpy(Gcmdbuff,cmd);	//repeat                           //~v40rI~
	return rc;
}//func_quit
                                                              //~4C18I~
//**************************************************          //~4C18I~
//*Term cmdprocess(Exit to cmd prompt with save)                //~5224R~
//**************************************************          //~4C18I~
int func_term(PUCLIENTWE Ppcw)                                  //~5224R~
{                                                             //~4C18I~
	int rc;                                                      //~4C18I~
    UCHAR cmd[sizeof(((FUNCTBL*)0)->FTcmd)];                       //~v085I~
//**************************************************          //~4C18I~
//  if (Ppcw->UCWtype==UCWTFILE)                                //~v020R~
//  	rc=func_end_file(Ppcw);                                 //~v020R~
//  else									//not file          //~v020R~
//  	rc=func_end_pan(Ppcw);                                  //~v020R~
	strcpy(cmd,((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);//save before pcw free//~v085I~
	rc=(Sfunc_end[Ppcw->UCWtype])(Ppcw);                        //~v020I~
	if (!rc)						//end completed                                //~4C18I~
//  	strcpy(Gcmdbuff,((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);	//repeat//~v085R~
    	strcpy(Gcmdbuff,cmd);                                      //~v085I~
	return rc;                                                   //~4C18I~
}//func_term                                                    //~5224R~
                                                              //~4C18I~
//**************************************************            //~5224I~
//*Exit cmdprocess(terminate current split with save)           //~5224I~
//**************************************************            //~5224I~
int func_exit(PUCLIENTWE Ppcw)                                  //~5224I~
{                                                               //~5224I~
	int rc,splitsw;                                             //~5224I~
    UCHAR cmd[sizeof(((FUNCTBL*)0)->FTcmd)];                       //~v085I~
//**************************************************            //~5224I~
	splitsw=UCBITCHK(Gscrstatus,GSCRSSPLITH|GSCRSSPLITV);//splitted//~5224I~
//  if (Ppcw->UCWtype==UCWTFILE)                                //~v020R~
//  	rc=func_end_file(Ppcw);                                 //~v020R~
//  else									//not file          //~v020R~
//  	rc=func_end_pan(Ppcw);                                  //~v020R~
	strcpy(cmd,((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);//save before pcw free//~v085I~
	rc=(Sfunc_end[Ppcw->UCWtype])(Ppcw);                        //~v020I~
	if (!rc)						//more pcw stacked          //~5224I~
    	if (splitsw==UCBITCHK(Gscrstatus,GSCRSSPLITH|GSCRSSPLITV))//yet splitted//~5224R~
//			strcpy(Gcmdbuff,((FUNCTBL*)(Ppcw->UCWpfunct))->FTcmd);	//repeat//~v085R~
        	strcpy(Gcmdbuff,cmd);                                  //~v085I~
	return rc;                                                  //~5224I~
}//func_exit                                                    //~5224I~
                                                                //~5224I~
//**************************************************
//*Esc key
//**************************************************
int func_reset(PUCLIENTWE Ppcw)
{
static int Skbdinpctr=0;                                           //~v55nR~
	PUFILEH pfh;                                                //~5610I~
    char *pc;                                                      //~v7arI~
//**************************************************
  	if (Ppcw->UCWkeytype==UCWKTCMD) //cmd input                    //~v7arI~
    {                                                              //~v7arI~
		if (pc=Ppcw->UCWparm,pc)                                   //~v7arI~
			if (*pc=='?')                                          //~v7arI~
            {                                                      //~v7arI~
            	uerrmsg("RESet [X] {L};  X:reveal eXcluded lines, L:clear line Labels",//~v7arR~
            	        "RESet [X] {L};  X:非\x95\\示行の\x95\\示, L:行ラベルクリアー");//~v7arR~
                return 0;                                          //~v7arI~
            }                                                      //~v7arI~
    }                                                              //~v7arI~
    if (Gscropt & GSCROPT_MULTILINEPENDING)   //2nd line pending   //~v603I~
    {                                                              //~v603I~
    	Gscropt|=GSCROPT_MULTILINENEXTREQ;    //2nd line display req//~v603I~
        return 0;                                                  //~v603I~
    }                                                              //~v603I~
#ifdef W32                                                         //~v0i5I~
    #ifdef NOTRACE                                                 //~v0i5I~
    #else                                                          //~v0i5I~
//for debug NT screen strip                                        //~v0i5I~
        if (UCBITCHK(Gopt3,GOPT3TESTABEND))//abend by double Esc   //~v0i5I~
        {                                                          //~v0i5I~
//      	#include <uvio.h>                                      //~v171R~
        	int ii,jj;char wkbuff[160];                            //~v0i5R~
        	for (ii=0;ii<Gscrheight;ii++)                          //~v0i5R~
            {                                                      //~v0i5I~
            	jj=160;                                            //~v0i5I~
	            uvioreadcellstr(wkbuff,&jj,ii,0);                  //~v0i5R~
            }                                                      //~v0i5I~
        }                                                          //~v0i5I~
    #endif                                                         //~v0i5I~
#endif                                                             //~v0i5I~
#ifdef UNX                                                         //~v424I~
	scrfulldraw(Ppcw);	//redraw req                               //~v424I~
  #ifndef XXE                                                      //~v64aI~
	uviol_clearok(1);	//clear after refresh write to terminal    //~v424I~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v424I~
	scrclearmsg(Ppcw);
	capreset(1);		//reset cut and paste(reset plh)        //~5220R~
//#ifdef WXE                                                       //~v63nR~
#if defined(WXE)||defined(LNX)                                     //~v63nI~
	if (Ppcw->UCWtype==UCWTDIR)                                    //~v63hR~
  #ifdef WXEXXE                                                    //~v682I~
		wxe_dragreset(Ppcw,DRAG_RESETBYESC);	//call dlcmddndreset through wxe//~v682I~
  #else                                                            //~v682I~
		dlcmddndreset(Ppcw);	//reset draged file sign           //~v63hR~
  #endif                                                           //~v682I~
#endif    	                                                       //~v63hI~
    Ghexctl[HEXCTL_LEN]=0;      //clear input status               //~v101I~
//v011s reset reverse when double ESC                           //~5610R~
  if (Ppcw->UCWkeytype==UCWKTCMD) //cmd input                      //~v0hmI~
//  func_reset2(Ppcw);                                             //~v69WR~
    func_reset2(Ppcw,0);                                           //~v69WI~
  else                                                             //~v0hmI~
    if ((Skbdinpctr+1)==Gkbdinpctr                                 //~v07xR~
	&&   Skbdinpctr)	//not first time and continuous ESC pressed//~v07xI~
    {                                                           //~5610I~
      if (Skbdinpctr!=Sesc2ctr) //prev is funcreset2               //~v562R~
      {                                                            //~v562I~
        Sesc2ctr=Gkbdinpctr;    //esc2 inpctr                      //~v562R~
//@@@@                                                             //~v086I~
//#define TEST                                                     //~v086R~
#ifdef TEST                                                        //~v086I~
    {                                                              //~v086I~
    	#include <ufuncmap.h>                                      //~v086R~
        int rc,nextoff;                                            //~v086I~
        void *heaph,*sheaph;                                       //~v086I~
		ULONG  attr;		//memchk                               //~v086I~
		ULONG  len;                                                //~v086I~
    	if (!(rc=ugettopheap(&heaph,&nextoff)))                    //~v086I~
        {                                                          //~v086I~
    		while(heaph)                                           //~v086I~
            {                                                      //~v086I~
    //  	    printf("created heap addr=%08x,len=%08x\n",heaph,*(ULONG*)heaph);//~v086I~
      			len=*(ULONG*)heaph;                                //~v086I~
				umemchk((ULONG)heaph,&len,&attr); //alocated chk(return commit len)//~v086I~
                sheaph=heaph;                                      //~v086I~
        		while(sheaph=(void*)(*(ULONG*)((ULONG)sheaph+4)),sheaph)//~v086I~
                {                                                  //~v086I~
    //  		    printf("sub heap addr=%08x,len=%08x\n",sheaph,*(ULONG*)sheaph);//~v086I~
    	  			len=*(ULONG*)sheaph;                           //~v086I~
					umemchk((ULONG)sheaph,&len,&attr); //alocated chk(return commit len)//~v086I~
    			}                                                  //~v086I~
        		heaph=(void*)(*(ULONG*)((ULONG)heaph+nextoff));    //~v086I~
        	}                                                      //~v086I~
        }                                                          //~v086I~
    }                                                              //~v086I~
#endif                                                             //~v086I~
//@@@@                                                             //~v086I~
//        if (Ppcw->UCWtype==UCWTFILE)                             //~v0hmR~
//        {                                                        //~v0hmR~
//            pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                 //~v0hmR~
//            pfh->UFHfindctr++;  //cur find,now old               //~v0hmR~
//            UCBITON(pfh->UFHflag2,UFHF2RESETPASTE);              //~v0hmR~
//            UCBITON(Ppcw->UCWflag,UCWFDRAW);//for reset reverse  //~v0hmR~
//        }                                                        //~v0hmR~
	    if (UCBITCHK(Gopt3,GOPT3TESTEXIT))//uerrexit by double Esc//~v03sI~
//      	uerrexit("uerrexit function test",0);                  //~v76WR~
        	uerrexit("uerrexit function test",                     //~v76WI~
						"uerrexit 機\x94\\テスト");                //~v76WI~
	    if (UCBITCHK(Gopt3,GOPT3TESTABEND))//abend by double Esc//~v03sI~
        {                                                       //~v03sI~
#ifdef DOS                                                      //~v03sI~
    #ifdef DPMI					//DPMI version                     //~v095I~
        	pfh=(UFILEH*)(0xffff0000);                             //~v095R~
            pfh->UFHfindctr++;	//access 0                         //~v095I~
    #else                       //not DPMI                         //~v095I~
        	uerrexit("abend function test",0);                  //~v03sI~
    #endif                      //DPMI or not                      //~v095I~
#else                                                           //~v03sI~
	#ifdef W32                                                     //~v171I~
         #ifdef SCREEN_TEST                                        //~v171I~
    		uvio_w95resetconsole();                                //~v171I~
         #else                                                     //~v171I~
         	uerrmsg("Abend test, 0C4 by double ESC",0);            //~vawbR~
        	pfh=0;                                                 //~v171I~
            pfh->UFHfindctr++;	//access 0                         //~v171I~
         #endif                                                    //~v171I~
    #else                                                          //~v171I~
         	uerrmsg("Abend test, 0C4 by double ESC",0);            //~vawbI~
        	pfh=0;                                              //~v03sI~
            pfh->UFHfindctr++;	//access 0                      //~v03sI~
    #endif                                                         //~v171I~
#endif                                                          //~v03sI~
        }                                                       //~v03sI~
//      func_reset2(Ppcw);                                         //~v69WR~
        func_reset2(Ppcw,0);                                       //~v69WI~
      }//prev is not esc*2                                         //~v562I~
      else      //3 times continuous Esc key press                 //~v69WI~
      {                                                            //~v69WI~
	      if (Skbdinpctr!=Sesc3ctr) //not 4 times                  //~v69WI~
    	  {                                                        //~v69WI~
        	Sesc3ctr=Gkbdinpctr;    //esc2 inpctr                  //~v69WI~
	        func_reset2(Ppcw,1);    //label clear                  //~v69WI~
          }                                                        //~v69WI~
      }//3 times                                                   //~v69WI~
    }                                                           //~5610I~
	Skbdinpctr=Gkbdinpctr;	//save for double ESC chk           //~5610I~
//v011e                                                         //~5610I~
	return 0;
}//func_reset
                                                                //~5114I~
//**************************************************               //~v0hmI~
//* reset by double Esc or "Reset" type command                    //~v0hmR~
//**************************************************               //~v0hmI~
//int func_reset2(PUCLIENTWE Ppcw)                                 //~v69WR~
int func_reset2(PUCLIENTWE Ppcw,int Popt)                          //~v69WI~
{                                                                  //~v0hmI~
	PUFILEH pfh;                                                   //~v0hmI~
    UCHAR   *pc;                                                   //~v11uI~
    int resetlcmdno=0;                                             //~v0hmI~
    int rc;                                                        //~v11uI~
    int resetlabelsw,resetxsw=0,opdno,ii;                          //~v69WR~
    int ctrold=0,ctrnew=0;	//excluded cmd ctr                     //~vb86I~
//**************************************************               //~v0hmI~
//#ifdef W32                                                       //~v651R~
#if defined(W32)||defined(XXE)                                     //~v651I~
    if (funcsleepreset(Ppcw))	//sleep is reset                   //~v562R~
    	return 0;	//skip other reset                             //~v560I~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
    if (wxe_timerreset(WXEAT_RESET))	//at cmd reset done        //~v55YR~
    	return 0;	//skip other reset                             //~v55WI~
#else                                                              //~v562I~
    if (funcatcmdreset(FAT_RESET))	//at cmd reset done            //~v562I~
    	return 0;	//skip other reset                             //~v562I~
#endif                                                             //~v561I~
#endif                                                             //~v55WI~
	resetlabelsw=(Popt & 0x01)*LCMDRESETLABEL;                     //~v69WR~
  	if (Ppcw->UCWkeytype==UCWKTCMD) //cmd input                    //~v69WI~
    {                                                              //~v69WI~
    	opdno=Ppcw->UCWopdno;                                      //~v69WI~
	    pc=Ppcw->UCWopdpot;       //parse out operand              //~v69WI~
	    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v69WR~
		{                                                          //~v69WI~
        	if (!stricmp(pc,"X"))                                  //~v69WI~
            	resetxsw=1;                                        //~v69WI~
            else                                                   //~v69WI~
        	if (!stricmp(pc,"L"))                                  //~v69WI~
            	resetlabelsw=LCMDRESETLABEL;                       //~v69WR~
            else                                                   //~v69WI~
                return errinvalid(pc);                             //~v69WI~
        }                                                          //~v69WI~
    }                                                              //~v69WI~
    if (Ppcw->UCWtype==UCWTFILE)                                   //~v0hmI~
    {                                                              //~v0hmI~
        pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                       //~v0hmI~
		ctrold=lcmdexcludedmsg(LCXMO_NOMSG,pfh);                   //~vb86I~
        pfh->UFHfindctr++;  //cur find,now old                     //~v0hmI~
        UCBITON(pfh->UFHflag2,UFHF2RESETPASTE);                    //~v0hmI~
//      resetlcmdno=lcmdreset(Ppcw,pfh);                           //~v69WR~
        resetlcmdno=lcmdreset(Ppcw,pfh,resetlabelsw);              //~v69WI~
		ctrnew=lcmdexcludedmsg(LCXMO_NOMSG,pfh);                   //~vb86I~
    }                                                              //~v0hmI~
    if (Ppcw->UCWtype==UCWTDIR)                                    //~v0hmI~
    {                                                              //~v0hmI~
        pfh=((PUFILEC)Ppcw->UCWpfc)->UFCpfh;                       //~v0hmI~
        pfh->UFHfindctr++;  //cur find,now old                     //~v0hmI~
        resetlcmdno=dlcmdreset(Ppcw,pfh);                          //~v0hmR~
    }                                                              //~v0hmI~
    if (Ppcw->UCWtype==UCWTMENU)    //panel                        //~v76gI~
        panreset(Ppcw);                                            //~v76gR~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);//for reset reverse            //~v0hmI~
    if (resetlcmdno)                                               //~v0hmI~
    {                                                              //~vb86I~
      if (ctrold || ctrnew)                                        //~vb86I~
    	uerrmsg("%d ( %d/%d in excluded part) lines cmd reset.",   //~vb86R~
                "%d (内 非\x95\\示: %d/%d ) 行コマンドをリセット", //~vb86I~
                resetlcmdno,ctrold-ctrnew,ctrold);                 //~vb86I~
      else                                                         //~vb86I~
    	uerrmsg("%d line cmd reset.",                               //~v0hmI~//~vb86R~
                "%d 行コマンドをリセット",                         //~v0hmI~
                resetlcmdno);                                      //~v0hmR~
    }                                                              //~vb86I~
//	if (Ppcw->UCWkeytype==UCWKTCMD) //cmd input                    //~v69WR~
	    if (Ppcw->UCWtype==UCWTFILE)                               //~v11uI~
//  	 	if (pc=Ppcw->UCWparm,pc)                               //~v69WR~
//          {                                                      //~v69WR~
//      		if (!stricmp(pc,"X"))                              //~v69WR~
        		if (resetxsw)                                      //~v69WI~
	        	{                                                  //~v11uI~
            		if (rc=lcmdresetx(Ppcw),rc>2)                  //~v11uR~
                    	return rc;                                 //~v11uI~
                    if (rc)	//no excluded line                     //~v11uI~
//  					uerrmsg("No excluded lines",               //~v11uI~//~vb86R~
    					uerrmsgcat(" No excluded lines",           //~vb86I~
                				" 非\x95\\示行無し");               //~v11uI~//~vb86R~
                    else                                           //~v11uI~
//  					uerrmsg("Reseted excluded line",           //~v11uI~//~vb86R~
    					uerrmsgcat(" Reseted all excluded lines",  //~vb86I~
                				" 全行\x95\\示");                   //~v11uI~//~vb86R~
    	    	}                                                  //~v11uI~
//          	else                                               //~v69WR~
//          		return errinvalid(pc);                         //~v69WR~
//          }                                                      //~v69WR~
    return 0;                                                      //~v0hmI~
}//func_reset2                                                     //~v0hmI~
//**************************************************            //~5428I~
//*help                                                         //~5428I~
//**************************************************            //~5428I~
int func_help(PUCLIENTWE Ppcw)                                  //~5428I~
{                                                               //~5428I~
    int rc=0;                                                      //~v60pI~
//#ifdef W32                                                       //~v71AR~
//    #ifdef WXE                                                   //~v71AR~
//    #else                                                        //~v71AR~
//        int ctxid;                                               //~v71AR~
//        char helpcmd[64];                                        //~v71AR~
//    #endif                                                       //~v71AR~
//#endif                                                           //~v71AR~
#if defined(W32) || defined(LNX)                                   //~v71AM~
    char fpathwk[_MAX_PATH],fpathwk2[_MAX_PATH];                   //~v71AM~
    char *htmlnm,*pc,*tophtml=0;                                   //~v71AM~
  #ifdef LNX                                                       //~v71CI~
  	int ii;                                                        //~v71CI~
//  char *lnxdir[]={"~/" XEHELPDIR,                                //~v75TI~
    char *lnxdir[]={                                               //~v75TR~
#ifdef PACKAGE_HELP_DIR                                            //~v75TI~
					PACKAGE_HELP_DIR "/" XEHELPDIR,                //~v75TR~
#endif                                                             //~v75TI~
                    "~/" XEHELPDIR,                                //~v75TI~
                    "/usr/local/share/gnome/help/xxe",             //~v71CR~
                    "/usr/local/share/doc/xxe",                    //~v71CR~
                    "/usr/share/doc/xxe",                          //~v71CR~
                    "/usr/share/doc/packages/gxe/doc/" XEHELPDIR,  //~v7ayI~
                    0};                                            //~v71CI~
  #endif                                                           //~v71CI~
#endif                                                             //~v71AI~
//**************************************************            //~5428I~
//    if (Ppcw->UCWparm)                                           //~v45CR~
//    {                                                            //~v45CR~
//        if (toupper(*(UCHAR*)Ppcw->UCWparm)!='I')                //~v45CR~
//        {                                                        //~v45CR~
//            uerrmsg("Specify \"I\" to see ini file",             //~v45CR~
//                    "ini ファイルを見る時は \"I\" オペランドを指定して下さい");//~v45CR~
//            return 4;                                            //~v45CR~
//        }                                                        //~v45CR~
//        strcpy(Gcmdbuff,"B ");                                   //~v45CR~
//        inigetfname(Gcmdbuff+2);    //set ini filename           //~v45CR~
//    }                                                            //~v45CR~
//    else                                                         //~v45CR~
//    {                                                            //~v45CR~
//        if (UCBITCHK(Gscrstatus,GSCRSDBCS))                      //~v45CR~
//            strcpy(Gcmdbuff,"B ::xej.htx");                      //~v45CR~
//        else                                                     //~v45CR~
//            strcpy(Gcmdbuff,"B ::xee.htx");                      //~v45CR~
//    }                                                            //~v45CR~
//#ifdef WXE                                                       //~v71AR~
//    wxe_helpreq();                                               //~v71AR~
//#else                                                            //~v71AR~
//  #ifdef W32                                                     //~v71AR~
//    if (UCBITCHK(Guerropt,GBL_UERR_FORCEENG))                    //~v71AR~
//        ctxid=IDH_ENGLISH;                                       //~v71AR~
//    else                                                         //~v71AR~
//        if (Gscrstatus & GSCRSDBCS)                              //~v71AR~
//            ctxid=IDH_JAPANESE;                                  //~v71AR~
//        else                                                     //~v71AR~
//            ctxid=IDH_ENGLISH;                                   //~v71AR~
//    sprintf(helpcmd,"winhlp32 -n%d wxe.hlp",ctxid);              //~v71AR~
//    Ppcw->UCWparm=helpcmd;                                       //~v71AR~
//    rc=dcmd_spawn(Ppcw);    //nowait cmd                         //~v71AR~
//    uerrmsg("Winhlp32 kicked.",                                  //~v71AR~
//            "Winhlp32を起動しました。");                         //~v71AR~
  #if defined(W32) || defined(LNX)                                 //~v71AI~
    if (UCBITCHK(Guerropt,GBL_UERR_FORCEENG))                      //~v71AM~
         htmlnm=XEHELP_TOP_HTML_E;                                 //~v71AR~
    else                                                           //~v71AM~
//      if (Gscrstatus & GSCRSDBCS)                                //~v79zR~
        if (XE_ISDBCSJ())                                          //~v79zR~
            htmlnm=XEHELP_TOP_HTML;                                //~v71AR~
        else                                                       //~v71AM~
            htmlnm=XEHELP_TOP_HTML_E;                              //~v71AR~
    if (*Ghelpdir)                                                 //~v71AM~
    {                                                              //~v71AM~
	    if (dcmdfullpath(Ppcw,fpathwk,Ghelpdir))   //consider ::   //~v71AM~
        {                                                          //~v71AM~
		    sprintf(fpathwk2,"%s%c%s",fpathwk,DIR_SEPC,htmlnm);    //~v71AM~
	        if (ufstat(fpathwk2,0))                                //~v71AM~
            {                                                      //~v71AM~
#ifdef ARM                                                         //~vaghI~
//  	    	uerrmsg("%s not found, did you installed AxeAsset(Settings->Download additional Asset)",//~vaghI~//+vbrgR~
//  	        		"%s が見つかりません、AxeAssetは導入済？(設定-->追加のAssetダウンロード)",//~vaghI~//+vbrgR~
    	    	uerrmsg("%s not found.",                           //+vbrgI~
    	        		"%s が見つかりません",                     //+vbrgI~
        	            	fpathwk2);                             //~vaghI~
#else                                                              //~vaghI~
		    	uerrmsg("%s not found(\"%cHD\" command line parameter err)",//~v71AM~
    	        		"%s が見つかりません。(\"%cHD\"コマンドラインパラメータエラー)",//~v71AM~
        	            	fpathwk2,CMDFLAG_PREFIX);              //~v71AM~
#endif                                                             //~vaghI~
		    	return 4;                                          //~v71AM~
            }                                                      //~v71AM~
	        tophtml=fpathwk2;                                      //~v71AM~
        }                                                          //~v71AM~
        else                                                       //~v71AM~
        {                                                          //~v71AM~
	    	uerrmsg("HelpDir command line parameter(%s) err",      //~v71AM~
            		"ヘルプＤｉｒコマンドラインパラメータ(%s)エラー",//~v71AM~
                    	Ghelpdir);                                 //~v71AM~
	        return 4;                                              //~v71AM~
        }                                                          //~v71AM~
    }                                                              //~v71AM~
    if (!tophtml)                                                  //~v71AM~
    {                                                              //~v71AM~
        if (pc=getenv(XEHELPDIR),pc)                               //~v71AM~
        {                                                          //~v71AM~
            if (dcmdfullpath(Ppcw,fpathwk,pc))   //consider ::     //~v71AM~
            {                                                      //~v71AM~
                sprintf(fpathwk2,"%s%c%s",fpathwk,DIR_SEPC,htmlnm);//~v71AM~
                if (ufstat(fpathwk2,0))                            //~v71AM~
                {                                                  //~v71AM~
                    uerrmsg("%s not found(\"%s\" Environment Variable err)",//~v71AM~
                            "%s が見つかりません。(\"%s\" 環境変数エラー)",//~v71AM~
                                fpathwk2,XEHELPDIR);               //~v71AM~
                    return 4;                                      //~v71AM~
                }                                                  //~v71AM~
		        tophtml=fpathwk2;                                  //~v71AM~
            }                                                      //~v71AM~
            else                                                   //~v71AM~
            {                                                      //~v71AM~
                uerrmsg("%s Environment variable err(%s)",         //~v71AM~
                        "%s 環境編集エラー(%s)",                   //~v71AM~
                            XEHELPDIR,pc);                         //~v71AM~
                return 4;                                          //~v71AM~
            }                                                      //~v71AM~
        }                                                          //~v71AM~
    }                                                              //~v71AM~
    if (!tophtml)                                                  //~v71AM~
    {                                                              //~v71AM~
        sprintf(fpathwk2,"%s%s%c%s",Gworkdir,XEHELPDIR,DIR_SEPC,htmlnm);//~v71AM~
        if (!ufstat(fpathwk2,0))                                   //~v71AM~
	        tophtml=fpathwk2;                                      //~v71AM~
    }                                                              //~v71AM~
#ifdef LNX                                                         //~v71CI~
    if (!tophtml)                                                  //~v71CI~
    {                                                              //~v71CI~
        for (ii=0;;ii++)                                           //~v71CI~
        {                                                          //~v71CI~
            if (!lnxdir[ii])                                       //~v71CI~
            	break;                                             //~v71CI~
            ufullpath(fpathwk,lnxdir[ii],sizeof(fpathwk));	//for "~/"//~v71CI~
            sprintf(fpathwk2,"%s%c%s",fpathwk,DIR_SEPC,htmlnm);    //~v71CR~
            if (!ufstat(fpathwk2,0))                               //~v71CI~
            {                                                      //~v71CI~
	            tophtml=fpathwk2;                                  //~v71CI~
                break;                                             //~v71CI~
            }                                                      //~v71CI~
        }                                                          //~v71CI~
    }                                                              //~v71CI~
#endif                                                             //~v71CI~
    if (!tophtml)                                                  //~v71AM~
    {                                                              //~v71AM~
#ifdef LNX                                                         //~v71CI~
    	uerrmsg("%s not found. \"%cHD\" cmd-line-parm,Env-Var \"%s\",%s%c%s,%s,%s,%s,%s will be searched.",//~v71CR~
                "%s が見つかりません。\"%cHD\"コマンドラインパラメータ,\"%s\" 環境変数, %s%c%s,%s,%s,%s,%sを探します",//~v71CR~
                 htmlnm,CMDFLAG_PREFIX,XEHELPDIR,WORKDIRPATHID,DIR_SEPC,XEHELPDIR,lnxdir[0],lnxdir[1],lnxdir[2],lnxdir[3]);//~v71CR~
#else                                                              //~v71CI~
    	uerrmsg("%s not found. \"%cHD\" cmd-line-parm,Env-Var \"%s\" and %s%c%s will be searched.",//~v71AM~
                "%s が見つかりません。\"%cHD\"コマンドラインパラメータ,\"%s\" 環境変数,%s%c%sを探します",//~v71AM~
                 htmlnm,CMDFLAG_PREFIX,XEHELPDIR,WORKDIRPATHID,DIR_SEPC,XEHELPDIR);//~v71AM~
#endif                                                             //~v71CI~
        return 4;                                                  //~v71AM~
    }                                                              //~v71AM~
    rc=dlcmdopenwithsub(Ppcw,tophtml);                             //~v71AM~
    if (!rc)                                                       //~v71AM~
			uerrmsg("Browser was kicked.(%s)",                     //~v71CR~
                    "ブラウザーを起動しました。(%s)",              //~v71CR~
                    tophtml);                                      //~v71CI~
  #else                                                            //~v60pI~
    uerrmsg("See Menu(enter =0.2 or =0.3).",                       //~v45CI~
            "メニューを見てください(=0.2 或いは =0.3).");          //~v45CI~
  #endif                                                           //~v60pI~
//#endif                                                           //~v71AR~
//  return 0;                                                      //~v60pR~
    return rc;                                                     //~v60pI~
}//func_help                                                    //~5428I~
                                                                //~5428I~
//**************************************************               //~v77KI~
//*redirect parm parse                                             //~v77KI~
//*rc 0:pot changed,1:not changed ,4:err                           //~v77KI~
//**************************************************               //~v77KI~
int funcparseredirect(int Popt,PUCLIENTWE Ppcw,char *Pcmdstr,char *Ppot,char *Ppodt,char *Pdelmt,//~v77KI~
					char **Pppredirectparm,int *Ppredirectparmidx,int *Ppredirectparmctr)//~v77KR~
{                                                                  //~v77KI~
    PUPODELMTBL ppodt,ppodt0;                                      //~v77KI~
    char delmt[8]=",;";                                            //~v77KR~
    UCHAR *ppot,*pc;                                               //~v77KR~
    int ii,wordno;                                                 //~v77KR~
//*********************                                            //~v77KI~
//	ppodt=ppodt0=(PUPODELMTBL)(ULONG)Ppodt;	//delm tbl out area    //~v77KR~//~vafkR~
	ppodt=ppodt0=(PUPODELMTBL)(ULPTR)Ppodt;	//delm tbl out area    //~vafkI~
    ppot=Ppot;       //parseout area                               //~v77KI~
    strcat(delmt,Pdelmt);                                          //~v77KI~
    if ((uparse2(Pcmdstr,&ppodt,&ppot,&wordno,                     //~v77KR~
                UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,Pdelmt))>=4) //~v77KI~
    	return 4;          //umalloc failed                        //~v77KI~
    pc=ppot;                                                       //~v77KR~
    for (ii=0;ii<wordno;ii++,pc+=strlen(pc)+1,ppodt++)  //next operand addr//~v77KR~
    {                                                              //~v77KI~
        if (strchr(Pdelmt,ppodt->upodelm))                         //~v77KR~
        {                                                          //~v77KI~
        	ii++;                                                  //~v77KI~
            pc+=strlen(pc)+1;                                      //~v77KI~
            ppodt++;                                               //~v77KI~
			if (Popt & FPR_UPDATEPCW)                              //~v77KI~
            {                                                      //~v77KI~
        		Ppcw->UCWopdno=ii;                                 //~v77KR~
            	Ppcw->UCWopdpot=Ppot;                              //~v77KR~
            	Ppcw->UCWopddelmt=ppodt0;                          //~v77KR~
            }                                                      //~v77KI~
            if (Pppredirectparm)                                   //~v77KR~
            	*Pppredirectparm=pc;                               //~v77KR~
            if (Ppredirectparmidx)                                 //~v77KR~
            	*Ppredirectparmidx=ii;                             //~v77KI~
            if (Ppredirectparmctr)                                 //~v77KI~
            	*Ppredirectparmctr=wordno-ii;                      //~v77KI~
            return 0;                                              //~v77KI~
        }                                                          //~v77KI~
    }                                                              //~v77KI~
    return 1;	//no redirection parm                              //~v77KI~
}//funcparseredirect(int Popt,Ppcw)                                //~v77KI~
//**************************************************               //~v55nI~
//*exec file cmd                                                   //~v55nI~
//**************************************************               //~v55nI~
int func_execmdfile(PUCLIENTWE Ppcw)                               //~v55nI~
{                                                                  //~v55nI~
#define EXE_MAXPARM  9                                             //~v55nR~
//  PUCLIENTWE pcw2;                                               //~v62fR~
	PUFILEH pfh;                                                   //~v55nI~
	PULINEH plh;                                                   //~v55nI~
	PULINEH plh1=NULL,plh2=NULL;                                             //~v62HI~//~vafcR~
    char *pc,*fnm,*prm[EXE_MAXPARM+1];                             //~v55nR~
//  char buff[MAXCOLUMN+1];                                        //~v55nI~//~v7ayR~
    char buff[MAXPARMSZ+1];                                        //~v7ayI~
    int opdno,ii,len,rc=0,cmd2ndsw=0;                              //~v55nR~
    int ignorercall=0,ignorerc;                                    //~v58uI~
    int errctr=0,cmdctr=0;                                         //~v60yI~
    FILE *fh;                                                      //~v55nI~
    char fpath[_MAX_PATH];                                         //~v58AI~
    UPODELMTBL *podt;                                              //~v62HI~
    UPODELMTBL *podt0;                                             //~v77KI~
    char *redirectparm=0;                                          //~v77KR~
	int prmctr;                                                    //~v77KI~
    int redirectparmno=0,redirectparmidx=0,opt;                        //~v77KR~//~vafcR~
    char *redirectcmd[EXE_MAXREDIRECTCMD+1];                       //~v77KI~
//  UCHAR wkpot[MAXCOLUMN+1];                                      //~v77KI~//~v7ayR~
//  UCHAR wkdelmt[MAXCOLUMN+1];                                    //~v77KI~//~v7ayR~
    UCHAR wkpot[MAXPARMSZ+1];                                      //~v7ayI~
    UCHAR wkdelmt[MAXPARMSZ+1];                                    //~v7ayI~
    FILE *fhlog;                                                   //~v77KI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file=0,u8len;                                        //~va20I~
    UCHAR *pu8;                                                    //~va20R~
#endif                                                             //~va20I~
//**************************************************               //~v55nR~
    if (!Ppcw->UCWparm)                                            //~v55nR~
    {                                                              //~v55nI~
//      uerrmsg("EXE {* | xecmd-file-name} [parm1 parm2 ...]",0);  //~v58uR~
//      uerrmsg("EXE [!]{* | xecmd-file-name} [parm1 parm2 ...]",0);//~v62GR~
//      uerrmsg("EXE [!]{* | %s | xecmd-file-name} [parm1 parm2 ...]",0,//~v77KR~
        uerrmsg("EXE [!]{* | %s | xecmd-file-name} [parm1 parm2 ...] [< { @parmfile | [S] wildcard [D[+]] } ]",0,//~v77KR~
						FNMOF2NDSCR);                              //~v62GI~
        return 4;                                                  //~v55nI~
    }                                                              //~v55nI~
    if (strchr(Ppcw->UCWparm,'<'))   //redirect parm               //~v77KR~
		funcparseredirect(FPR_UPDATEPCW,Ppcw,Ppcw->UCWparm,wkpot,wkdelmt,"<",&redirectparm,&redirectparmidx,&redirectparmno);//~v77KR~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v55nI~
    podt0=                                                         //~v77KI~
    podt=Ppcw->UCWopddelmt;                                        //~v77KI~
    if (opdno>EXE_MAXPARM+1)                                       //~v55nI~
    {                                                              //~v55nI~
        uerrmsg("max %d parm operand supported",0,                 //~v55nI~
				EXE_MAXPARM);                                      //~v55nI~
        return 4;                                                  //~v55nI~
    }                                                              //~v55nI~
    fnm=Ppcw->UCWopdpot;                                           //~v55nI~
    if (*fnm==EXECMD_IGNORE_ERRID)	//ignore rc of all submcmd     //~v58uI~
    {                                                              //~v58uI~
        ignorercall=1;                                             //~v58uI~
        fnm++;                                                     //~v58uI~
        if (!*fnm)	//intermediate space like as "! filenm"        //~v58uI~
        {                                                          //~v77KI~
        	fnm++;                                                 //~v58uI~
            opdno--;    //1st ioperand accepted                    //~v77KI~
        }                                                          //~v77KI~
    }                                                              //~v58uI~
    if (!strcmp(fnm,"*"))                                          //~v55nI~
    {                                                              //~v55nI~
    	if (Ppcw->UCWtype!=UCWTFILE)                               //~v55nI~
        	return errscrtype("*");                                //~v55nI~
        pfh=UGETPFHFROMPCW(Ppcw);                                  //~v55nI~
    }                                                              //~v55nI~
    else                                                           //~v55nI~
    if (!strcmp(fnm,FNMOF2NDSCR))                                  //~v60yI~
    {                                                              //~v60yI~
//        pcw2=scrgetcw(-1);  //another screen                     //~v62fR~
//        if (!pcw2)                                               //~v62fR~
//            return errscrnotsplited();                           //~v62fR~
//        if (pcw2->UCWtype!=UCWTFILE)                             //~v62fR~
//            return err2ndscrisnotfile();                         //~v62fR~
//        pfh=UGETPFHFROMPCW(pcw2);                                //~v62fR~
		pfh=fcmdget2ndpfh(Ppcw,FNMOF2NDSCR);                       //~v62fR~
        if (!pfh)                                                  //~v62fI~
        	return 4;                                              //~v62fI~
    }                                                              //~v60yI~
    else                                                           //~v60yI~
    	pfh=0;                                                     //~v55nI~
    if (pfh)                                                       //~v62HI~
    {                                                              //~v62HI~
#ifdef UTF8UCS2                                                    //~va20I~
    	swutf8file=FILEUTF8MODE(pfh);                              //~va20I~
#endif                                                             //~va20I~
    	rc=fcmdgetlabparm(Ppcw,pfh,&plh1,&plh2,FCGLP_NEXTPLH);	//top and end if no label,next of lab2//~v62HI~
    	if (rc)                                                    //~v62HI~
    		return rc;                                             //~v62HI~
    }                                                              //~v62HI~
    pc=fnm+strlen(fnm)+1;                                          //~v55nR~
    opdno--;                                                       //~v55nI~
    len=0;//for compiler warning                                   //~v603I~
    podt=Ppcw->UCWopddelmt;                                        //~v62HI~
    prmctr=0;                                                      //~va2fI~
    for (ii=0;ii<opdno;ii++,pc+=len+1)	//next operand addr        //~v55nI~
	{                                                              //~v55nI~
	    podt++;                                                    //~v62HI~
      	if ((*pc==ULCCMDLABEL && !podt->upoquate))  //start by . but not in quate//~v62HI~
        {                                                          //~v62HI~
        	if (pfh)	//opened file                              //~v62HR~
            {                                                      //~va2fI~
				len=(int)strlen(pc);                               //~va2fI~
	    		continue;                                          //~v62HR~
            }                                                      //~va2fI~
        }                                                          //~v62HI~
		len=(int)strlen(pc);                                       //~v55nR~
//      prm[ii]=pc;	//save operand parm                            //~v55nI~//~va2fR~
        prm[prmctr++]=pc;	//save operand parm                    //~va2fI~
    }                                                              //~v55nI~
//  prmctr=ii;                                                     //~v77KI~//~va2fR~
//  prm[ii]=0;                                                     //~v55nI~//~va2fR~
    prm[prmctr]=0;                                                 //~va2fI~
//  buff[MAXCOLUMN]=0;                                             //~v55nI~//~v7ayR~
    buff[sizeof(buff)-1]=0;                                        //~v7ayI~
    if (!(fhlog=funcexelogopenclose(FEL_OPEN,Ppcw->UCWparm)))      //~v77KI~
    	return 4;                                                  //~v77KM~
    if (pfh)                                                       //~v55nI~
    {                                                              //~v55nI~
    	if (redirectparm)                                          //~v77KI~
    		return errnotsupported("redirect(\"<\")","opened file");//~v77KR~
//  	plh=UGETQTOP(&pfh->UFHlineque);		//top entry            //~v62HR~
//      for (;plh;plh=UGETQNEXT(plh))                              //~v62HR~
        for (plh=plh1;plh && plh!=plh2;plh=UGETQNEXT(plh))         //~v62HI~
        {                                                          //~v55nI~
            if (plh->ULHtype!=ULHTDATA) //file data                //~v55nI~
            	continue;                                          //~v55nI~
            len=plh->ULHlen;                                       //~v55nI~
#ifdef UTF8UCS2                                                    //~va20I~
	  		if (swutf8file                                         //~va20I~
#ifdef W32UNICODE                                                  //~vawgI~
	  		&&  (!xeutfcvDD2UD(0,plh->ULHdata,plh->ULHdbcs,len,sizeof(buff),&pu8,&u8len))//~vawgR~
#else                                                              //~vawgI~
	  		&&  (xeutfcvdd2f(0,plh->ULHdata,plh->ULHdbcs,len,&pu8,&u8len,0/*outdbcs*/)!=UALLOC_FAILED)//~va20R~
#endif                                                             //~vawgI~
      		)                                                      //~va20I~
                len=u8len;                                         //~va20I~
            else                                                   //~va20I~
            	pu8=0;                                             //~va20I~
#endif                                                             //~va20I~
//          len=min(len,MAXCOLUMN);                                //~v55nI~//~v7ayR~
//          len=min(len,sizeof(buff)-1);                           //~v7ayI~//~vb2DR~
            len=min(len,(int)sizeof(buff)-1);                      //~vb2DI~
#ifdef UTF8UCS2                                                    //~va20I~
		  if (pu8)                                                 //~va20I~
            memcpy(buff,pu8,(UINT)len);	//utf8 string from dd fmt  //~va20I~
          else                                                     //~va20I~
#endif                                                             //~va20I~
            memcpy(buff,plh->ULHdata,(UINT)len);                   //~v55nR~
            *(buff+len)=0;                                         //~v55nI~
            cmdctr++;                                              //~v60yI~
//          rc=execmdsub(Ppcw,buff,prm,&cmd2ndsw);                 //~v58uR~
//          rc=execmdsub(Ppcw,buff,prm,&cmd2ndsw,&ignorerc);       //~v77KR~
            rc=execmdsub(0,Ppcw,buff,prm,&cmd2ndsw,&ignorerc,fhlog);//~v77KR~
//          if (rc)                                                //~v56uR~
    		if (rc>=4)                                             //~v56uI~
            {                                                      //~v58uI~
			  	lcmdshifterr(plh,0,0);//no exclude line highlight,no output 1st err line//~v58uI~
	          if (!ignorercall&&!ignorerc)                         //~v58uR~
                break;                                             //~v55nI~
              else                                                 //~v60yI~
              	errctr++;                                          //~v60yI~
            }                                                      //~v58uI~
            else                                                   //~v58uI~
			  	lcmdresetshifterr(plh,0);//no reset excluded       //~v58uI~
                                                                   //~v58uI~
		}//while plh                                               //~v55nI~
    }                                                              //~v55nI~
    else                                                           //~v55nI~
    {                                                              //~v55nI~
                                                                   //~v58AI~
    	if (fnm=dcmdfullpath(Ppcw,fpath,fnm),!fnm)                 //~v58AI~
        	return 4;                                              //~v58AI~
        fh=fileopen(fnm,"r");                                      //~v55nR~
        if (!fh)                                                   //~v55nR~
            return 4;                                              //~v55nR~
//      while (fgets(buff,MAXCOLUMN,fh))                           //~v55nR~//~v7ayR~
        while (fgets(buff,sizeof(buff)-1,fh))                      //~v7ayI~
        {                                                          //~v55nR~
            len=(int)strlen(buff);                                 //~v55nR~
            if (len && *(buff+len-1)=='\n')                        //~v55nR~
            {                                                      //~v55nR~
                len--;                                             //~v55nR~
                *(buff+len)=0;                                     //~v55nR~
            }                                                      //~v55nR~
            if (len && *(buff+len-1)=='\r')     //0x0d             //~v55nR~
            {                                                      //~v55nR~
                len--;                                             //~v55nR~
                *(buff+len)=0;                                     //~v55nR~
            }                                                      //~v55nR~
            cmdctr++;                                              //~v60yI~
    	  if (redirectparm)                                        //~v77KI~
          {                                                        //~v77KI~
          	if (cmdctr>EXE_MAXREDIRECTCMD)                         //~v77KR~
            {                                                      //~v77KI~
            	uerrmsg("too big exe cmd file(max line=%d) for the case using redirect parm",0,//~v77KR~
          				EXE_MAXREDIRECTCMD);                       //~v77KI~
            	funcexefreeredirect(redirectcmd,cmdctr-1);         //~v77KI~
                return 4;                                          //~v77KI~
            }                                                      //~v77KI~
          	pc=umalloc((UINT)len+1);                               //~v77KR~
            UALLOCCHK(pc,UALLOC_FAILED);                           //~v77KI~
            memcpy(pc,buff,(UINT)(len+1));                         //~v77KR~
            redirectcmd[cmdctr-1]=pc;                              //~v77KI~
          }                                                        //~v77KI~
          else                                                     //~v77KI~
          {                                                        //~v77KI~
//          rc=execmdsub(Ppcw,buff,prm,&cmd2ndsw);                 //~v58uR~
//          rc=execmdsub(Ppcw,buff,prm,&cmd2ndsw,&ignorerc);       //~v77KR~
            rc=execmdsub(0,Ppcw,buff,prm,&cmd2ndsw,&ignorerc,fhlog);//~v77KR~
//          if (rc)                                                //~v58uR~
    		if (rc>=4)                                             //~v58uI~
            {                                                      //~v60yI~
	          if (!ignorercall&&!ignorerc)                         //~v58uI~
                break;                                             //~v55nR~
              else                                                 //~v60yI~
              	errctr++;                                          //~v60yI~
            }                                                      //~v60yI~
          }                                                        //~v77KI~
        }//until eof                                               //~v55nR~
        fclose(fh);                                                //~v55nR~
    	if (redirectparm && cmdctr)                                //~v77KI~
        {                                                          //~v77KI~
            redirectcmd[cmdctr]=0;                                 //~v77KI~
	        if (ignorercall)                                       //~v77KR~
				opt=FERO_IGNORERC;                                 //~v77KR~
            else                                                   //~v77KI~
            	opt=0;                                             //~v77KI~
        	rc=funcexeredirect(opt,fhlog,Ppcw,redirectcmd,prm,prmctr,redirectparm,podt0+redirectparmidx,redirectparmno);//~v77KR~
            if (rc)                                                //~v77KI~
                errctr=1;                                          //~v77KI~
            funcexefreeredirect(redirectcmd,cmdctr);               //~v77KI~
        }                                                          //~v77KI~
    }//file opd                                                    //~v55nI~
    funcexelogopenclose(FEL_CLOSE|(FEL_ERR)*(rc!=0),0);            //~v77KI~
    uerrmsgcat(" ; result is on %s",                               //~v77KR~
                " ; 結果は %s",                                    //~v77KR~
					EXE_REDIRECTLOG);                              //~v77KI~
    if (errctr)                                                    //~v60yI~
    {                                                              //~v60yI~
//  	uerrmsg("error=%d/%d",0,                                   //~v77KR~
//  			errctr,cmdctr);                                    //~v77KR~
        rc=4;                                                      //~v60yI~
    }                                                              //~v60yI~
	return rc;                                                     //~v55nR~
}//func_execmdfile                                                 //~v55nI~
//**************************************************               //~v77KI~
//*free redirect parm cmd                                          //~v77KI~
//**************************************************               //~v77KI~
void  	funcexefreeredirect(char **Ppbuff,int Pentno)              //~v77KI~
{                                                                  //~v77KI~
	char **ppc;                                                    //~v77KI~
    int ii;                                                        //~v77KI~
//*************                                                    //~v77KI~
	for (ii=0,ppc=Ppbuff;ii<Pentno;ii++,ppc++)                     //~v77KR~
    	ufree(*ppc);                                               //~v77KR~
    return;                                                        //~v77KI~
}//funcexefreeredirect(char **Ppbuff,int Pentno)                   //~v77KI~
//**************************************************               //~v77KI~
//*execmd log open                                                 //~v77KI~
//**************************************************               //~v77KI~
FILE *funcexelogopenclose(int Popt,char *Pcomment)                 //~v77KR~
{                                                                  //~v77KI~
static int Slogalloc=0;                                            //~v77KM~
static FILE *Sfhlog;                                               //~v77KI~
static int Sopenctr;                                               //~v77KR~
	UCHAR   fpath[_MAX_PATH];                                      //~v77KI~
    char *errmsg;                                                  //~v77KI~
	char curtime[16];                                              //~v77KI~
//*************                                                    //~v77KI~
	if (Popt & FEL_OPEN)                                           //~v77KI~
    {                                                              //~v77KI~
        if (!filefullpath(fpath,EXE_REDIRECTLOG,_MAX_PATH))        //~v77KR~
            return 0;                                              //~v77KI~
        if (Sopenctr)	//                                         //~v77KI~
        	Sopenctr++;                                            //~v77KI~
        else                                                       //~v77KI~
        {                                                          //~v77KI~
            Sfhlog=fileopen(fpath,"w");                            //~v77KR~
            if (!Sfhlog)                                           //~v77KR~
                return 0;                                          //~v77KR~
            Sopenctr=1;                                            //~v77KR~
            if (!Slogalloc)                                        //~v77KR~
            {                                                      //~v77KR~
                Slogalloc=1;                                       //~v77KR~
                subsavetempfnm(fpath,0/*fnm len*/);//save file name to be deleted at end of session//~v77KR~
            }                                                      //~v77KR~
        }                                                          //~v77KI~
        utimeedit("HH:MM:SS:MIL",curtime);                         //~v77KI~
        *(curtime+12)=0;                                           //~v77KI~
        fprintf(Sfhlog,"%s:-%d:===== %s =====\n",curtime,Sopenctr,Pcomment);//~v77KR~
    }                                                              //~v77KI~
    else                                                           //~v77KI~
    {                                                              //~v77KI~
        if (Sopenctr)                                              //~v77KI~
        {                                                          //~v77KI~
            utimeedit("HH:MM:SS:MIL",curtime);                     //~v77KI~
            *(curtime+12)=0;                                       //~v77KI~
            fprintf(Sfhlog,"%s:-%d:===== Completed Err=%c =====\n",curtime,Sopenctr,(Popt & FEL_ERR?'Y':'N'));//~v77KR~
	    	if (errmsg=ugeterrmsg2(),errmsg)                       //~v77KR~
	        	fprintf(Sfhlog,"LastMsg:%s\n",errmsg);             //~v77KR~
            Sopenctr--;                                            //~v77KI~
            if (!Sopenctr)                                         //~v77KI~
            {                                                      //~v77KI~
                fclose(Sfhlog);                                    //~v77KI~
                Sfhlog=0;                                          //~v77KI~
            }                                                      //~v77KI~
        }                                                          //~v77KI~
    }                                                              //~v77KI~
    return Sfhlog;                                                 //~v77KI~
}//funcexelogopenclose                                             //~v77KI~
//**************************************************               //~v77KI~
//*execmdsub by redirect parm                                      //~v77KI~
//**************************************************               //~v77KI~
int funcexeredirect(int Popt,FILE *Pfhlog,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,//~v77KR~
					char *Ppredirectparm,UPODELMTBL *Ppodt,int Predirectparmno)//~v77KR~
{                                                                  //~v77KI~
	int rc,opdno,selectsw=0,parmfilesw=0;                          //~v77KR~
    char *pc,*pc2;                                                 //~v77KR~
    UPODELMTBL *podt;                                              //~v77KI~
//**********************************                               //~v77KI~
    rc=4;                                                          //~v77KI~
    for (;;)                                                       //~v77KI~
    {                                                              //~v77KI~
        podt=Ppodt;                                                //~v77KR~
        opdno=Predirectparmno;           //funccmd created already //~v77KR~
        pc=Ppredirectparm;                                         //~v77KR~
        if (opdno && !stricmp(pc,"S"))   //select option           //~v77KR~
        {                                                          //~v77KR~
            selectsw=1;                                            //~v77KR~
            pc+=strlen(pc)+1;                                      //~v77KR~
            opdno--;                                               //~v77KR~
            podt++;                                                //~v77KR~
        }                                                          //~v77KR~
        else                                                       //~v77KI~
        if (*pc=='@')   //parmfile                                 //~v77KI~
        	parmfilesw=1;                                          //~v77KI~
        if (opdno<=0)                                              //~v77KR~
        {                                                          //~v77KR~
            uerrmsg("missing redirect parm after \"<\"",0);        //~v77KR~
            break;                                                 //~v77KR~
        }                                                          //~v77KR~
        if (opdno>1)                                               //~v77KR~
        {                                                          //~v77KR~
        	if (!parmfilesw)                                       //~v77KR~
            {                                                      //~v77KI~
	            pc2=pc+strlen(pc)+1;                               //~v77KI~
            	if (!stricmp(pc2,"D"))                             //~v77KR~
                	Popt|=FERO_DIRONLY;                            //~v77KI~
                else                                               //~v77KI~
            	if (!stricmp(pc2,"D+"))                            //~v77KR~
                	Popt|=FERO_ALSODIR;                            //~v77KI~
                else                                               //~v77KI~
                {                                                  //~v77KI~
                	uerrmsg("Invalid parameter(%s)",0,             //~v77KI~
                    		pc2);                                  //~v77KI~
                    break;                                         //~v77KI~
                }                                                  //~v77KI~
                if (opdno>2)                                       //~v77KI~
                {                                                  //~v77KI~
    	        	uerrmsg("excessive redirect parm after(%s)",0, //~v77KI~
        	        	    pc2);                                  //~v77KI~
            		break;                                         //~v77KI~
                }                                                  //~v77KI~
            }                                                      //~v77KI~
            else                                                   //~v77KI~
            {                                                      //~v77KI~
            	uerrmsg("excessive redirect parm after(%s)",0,     //~v77KR~
                	    pc);                                       //~v77KR~
            	break;                                             //~v77KR~
            }                                                      //~v77KI~
        }                                                          //~v77KR~
        if (selectsw)                                              //~v77KR~
            rc=funcexeredirect_select(Popt,Ppcw,Pppredirectcmd,Pppprm,Pprmctr,pc,Pfhlog);//~v77KR~
        else                                                       //~v77KR~
        if (*pc=='@')   //parmfile                                 //~v77KR~
            rc=funcexeredirect_parmfile(Popt,Ppcw,Pppredirectcmd,Pppprm,Pprmctr,pc+1,Pfhlog);//~v77KR~
        else                                                       //~v77KR~
            rc=funcexeredirect_wildcard(Popt,Ppcw,Pppredirectcmd,Pppprm,Pprmctr,pc,Pfhlog);//~v77KR~
        break;                                                     //~v77KI~
    }                                                              //~v77KI~
    return rc;                                                     //~v77KI~
}//funcexeredirect                                                 //~v77KI~
//**************************************************               //~v77KI~
//*execmdsub by redirect parm(select,parm is member name)          //~v77KI~
//**************************************************               //~v77KI~
int funcexeredirect_select(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,char *Pwildcard,FILE *Pfhlog)//~v77KI~
{                                                                  //~v77KI~
	PUFILEH pfh;                                                   //~v77KI~
	int rc=0,filectr,ii,loopctr=0,len,errctr=0,opt;                //~v77KR~
    PUDIRLIST pudirlist,pudirlist0;                                //~v77KI~
	UCHAR   dirname[_MAX_PATH]; //for udirlist                     //~v77KR~
//**********************************                               //~v77KI~
	if (Ppcw->UCWtype!=UCWTDIR)                                    //~v77KI~
    	return errnotsupported("Redirect Input by Select","except DirList Panel");//~v77KI~
    if (!WILDCARD(Pwildcard))                                      //~v77KI~
    {                                                              //~v77KI~
        uerrmsg("specify wildcard for redirect Select parm(%s)",0, //~v77KI~
                   Pwildcard);                                     //~v77KI~
        return 4;                                                  //~v77KI~
    }                                                              //~v77KI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v77KI~
    strcpy(dirname,pfh->UFHfilename);                              //~v77KI~
    if (WILDCARD(dirname))                                         //~v77KI~
    	strcpy(dirname+PATHLEN(dirname),Pwildcard);                //~v77KR~
    else                                                           //~v77KI~
    {                                                              //~v77KI~
    	len=(int)strlen(dirname);                                  //~v77KR~
        if (!ROOTDIR(dirname))                                     //~v77KI~
        {                                                          //~v77KI~
            *(dirname+len++)=pfh->UFHdirsepc;                      //~v77KI~
        }                                                          //~v77KI~
        strcpy(dirname+len,Pwildcard);                             //~v77KR~
    }                                                              //~v77KI~
    if (Popt & FERO_DIRONLY)                                       //~v77KI~
		opt=FILE_DIRECTORY;                                        //~v77KI~
    else                                                           //~v77KI~
    if (Popt & FERO_ALSODIR)                                       //~v77KI~
		opt=FILE_ALL;                                              //~v77KI~
    else                                                           //~v77KI~
		opt=FILE_ALL-FILE_DIRECTORY;                               //~v77KI~
	filectr=dirgetlist(pfh,dirname,(UINT)opt,&pudirlist0);         //~v77KR~
    if (filectr<0)                                                 //~v77KI~
    {                                                              //~v77KI~
    	uerrmsg("No entry for %s",0,                               //~v77KI~
        		dirname);                                          //~v77KI~
        return 4;                                                  //~v77KR~
    }                                                              //~v77KI~
    for (ii=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)    //~v77KI~
    {                                                              //~v77KI~
		if (strcmp(pudirlist->name,".")      //not current         //~v77KR~
	    &&  strcmp(pudirlist->name,"..")  )  //and not parent      //~v77KR~
        {                                                          //~v77KI~
		    if (Popt & FERO_DIRONLY)                               //~v77KI~
            	if (!(pudirlist->attr & FILE_DIRECTORY))	//for ulib bug(Widows case)//~v77KI~
                	continue;	                                   //~v77KI~
			Pppprm[Pprmctr]=pudirlist->name;                       //~v77KI~
            loopctr++;                                             //~v77KI~
	    	fprintf(Pfhlog,"===% 5d === %s ===\n",loopctr,pudirlist->name);//~v77KR~
    		if (rc=funcexeredirect_cmdcall(Popt,Ppcw,Pppredirectcmd,Pppprm,Pprmctr+1,Pfhlog),rc>1)//~v77KR~
            	break;                                             //~v77KI~
        	if (rc)                                                //~v77KI~
        		errctr++;                                          //~v77KI~
	        Popt|=FERO_2NDLOOP;                                    //~v77KR~
        }                                                          //~v77KI~
    }                                                              //~v77KI~
    fprintf(Pfhlog,"!!total %5d times for %s\n",loopctr,dirname);  //~v77KR~
//  ufree(pudirlist0);                                             //~v77KI~//~vandR~
    UDIRLIST_FREE(pudirlist0);                                     //~vandI~
    if (!rc)                                                       //~v77KI~
    	if (errctr)                                                //~v77KI~
    		rc=1;                                                  //~v77KI~
    return rc;                                                     //~v77KI~
}//funcexeredirect_select                                          //~v77KI~
//**************************************************               //~v77KI~
//*execmdsub by redirect parm(wildcard,parm is fullpath)           //~v77KI~
//**************************************************               //~v77KI~
int funcexeredirect_wildcard(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,char *Pwildcard,FILE *Pfhlog)//~v77KR~
{                                                                  //~v77KI~
	int rc=0,filectr,ii,pathlen,loopctr=0,errctr=0,opt;            //~v77KR~
    PUDIRLIST pudirlist,pudirlist0;                                //~v77KI~
	UCHAR   fpath[_MAX_PATH]; //for udirlist                       //~v77KR~
	UCHAR   fpathsv[_MAX_PATH]; //for udirlist                     //~v77KI~
//**********************************                               //~v77KI~
    if (!dcmdfullpath(Ppcw,fpath,Pwildcard))                       //~v77KI~
        return 4;                                                  //~v77KI~
    if (!WILDCARD(fpath))                                          //~v77KI~
    {                                                              //~v77KI~
        uerrmsg("specify wildcard for redirect parm(%s) if it is not @parm file",0,//~v77KI~
                   Pwildcard);                                     //~v77KI~
        return 4;                                                  //~v77KI~
    }                                                              //~v77KI~
    pathlen=PATHLEN(fpath);                                        //~v77KI~
    strcpy(fpathsv,fpath);                                         //~v77KI~
    if (Popt & FERO_DIRONLY)                                       //~v77KI~
		opt=FILE_DIRECTORY;                                        //~v77KI~
    else                                                           //~v77KI~
    if (Popt & FERO_ALSODIR)                                       //~v77KI~
		opt=FILE_ALL;                                              //~v77KI~
    else                                                           //~v77KI~
		opt=FILE_ALL-FILE_DIRECTORY;                               //~v77KI~
	filectr=udirlist(fpath,(UINT)opt,&pudirlist0,0/*sort order*/); //~v77KR~
    if (filectr<0)                                                 //~v77KI~
    {                                                              //~v77KI~
    	uerrmsg("No entry for %s",0,                               //~v77KI~
        		fpath);                                            //~v77KI~
        return 4;                                                  //~v77KR~
    }                                                              //~v77KI~
    Pppprm[Pprmctr]=fpath;                                         //~v77KI~
    for (ii=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)    //~v77KI~
    {                                                              //~v77KI~
		if (strcmp(pudirlist->name,".")      //not current         //~v77KR~
	    &&  strcmp(pudirlist->name,"..")  )  //and not parent      //~v77KR~
        {                                                          //~v77KI~
		    if (Popt & FERO_DIRONLY)                               //~v77KI~
            	if (!(pudirlist->attr & FILE_DIRECTORY))	//for ulib bug(Widows case)//~v77KI~
                	continue;                                      //~v77KI~
        	strcpy(fpath+pathlen,pudirlist->name);                 //~v77KR~
            loopctr++;                                             //~v77KI~
	    	fprintf(Pfhlog,"===% 5d === %s ===\n",loopctr,fpath);  //~v77KR~
    		if (rc=funcexeredirect_cmdcall(Popt,Ppcw,Pppredirectcmd,Pppprm,Pprmctr+1,Pfhlog),rc>1)//~v77KR~
            	break;                                             //~v77KI~
        	if (rc)                                                //~v77KI~
        		errctr++;                                          //~v77KI~
	        Popt|=FERO_2NDLOOP;                                    //~v77KR~
        }                                                          //~v77KI~
    }                                                              //~v77KI~
    fprintf(Pfhlog,"!!total %5d times for %s\n",loopctr,fpathsv);  //~v77KR~
//  ufree(pudirlist0);                                             //~v77KI~//~vandR~
    UDIRLIST_FREE(pudirlist0);                                     //~vandI~
    if (!rc)                                                       //~v77KI~
    	if (errctr)                                                //~v77KR~
    		rc=1;                                                  //~v77KR~
    return rc;                                                     //~v77KR~
}//funcexeredirect_wildcard                                        //~v77KI~
//**************************************************               //~v77KI~
//*execmdsub by redirect parm(@parmfile)                           //~v77KI~
//**************************************************               //~v77KI~
int funcexeredirect_parmfile(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,char *Pparmfile,FILE *Pfhlog)//~v77KI~
{                                                                  //~v77KI~
	int rc=0,len,opdno,availprmctr,lineno=0,errctr=0;              //~v77KR~
	UCHAR   fpath[_MAX_PATH]; //for udirlist                       //~v77KI~
    char *prm[EXE_MAXPARM+1];                                      //~v77KI~
//  char buff[MAXCOLUMN+1];                                        //~v77KI~//~v7ayR~
    char buff[MAXPARMSZ+1];                                        //~v7ayI~
//  UCHAR wkpot[MAXCOLUMN*2];                                      //~v77KI~//~v7ayR~
    UCHAR wkpot[MAXPARMSZ*2];                                      //~v7ayI~
//  char **pprm;                                                   //~v77KR~
    char **ppargv,*ppot;                                           //~v77KI~
    FILE *fh;                                                      //~v77KI~
//**********************************                               //~v77KI~
//  memcpy(prm,Pppprm,(UINT)(Pprmctr*4));                          //~va70R~
  	memcpy(prm,Pppprm,(UINT)(Pprmctr*PTRSZ));                      //~va70I~
//  pprm=prm+Pprmctr;                                              //~v77KR~
    availprmctr=EXE_MAXPARM-Pprmctr;                               //~v77KI~
    if (!dcmdfullpath(Ppcw,fpath,Pparmfile))                       //~v77KI~
        return 4;                                                  //~v77KI~
    if (WILDCARD(fpath))                                           //~v77KI~
    {                                                              //~v77KI~
        uerrmsg("parameter file specification err-wildcard(%s)",0, //~v77KI~
                   Pparmfile);                                     //~v77KI~
        return 4;                                                  //~v77KI~
    }                                                              //~v77KI~
    fh=fileopen(fpath,"r");                                        //~v77KR~
    if (!fh)                                                       //~v77KI~
    	return 4;                                                  //~v77KI~
	ppot=wkpot;                                                    //~v77KI~
//  while (fgets(buff,MAXCOLUMN,fh))                               //~v77KI~//~v7ayR~
    while (fgets(buff,sizeof(buff)-1,fh))                          //~v7ayI~
    {                                                              //~v77KI~
        len=(int)strlen(buff);                                     //~v77KI~
        if (len && *(buff+len-1)=='\n')                            //~v77KI~
        {                                                          //~v77KI~
            len--;                                                 //~v77KI~
            *(buff+len)=0;                                         //~v77KI~
        }                                                          //~v77KI~
        if (len && *(buff+len-1)=='\r')     //0x0d                 //~v77KI~
        {                                                          //~v77KI~
            len--;                                                 //~v77KI~
            *(buff+len)=0;                                         //~v77KI~
        }                                                          //~v77KI~
        lineno++;                                                  //~v77KI~
    	fprintf(Pfhlog,"===% 5d === %s ===\n",lineno,buff);        //~v77KR~
        uparsecmd(UPCMD_ASIS,buff,&opdno,&ppot,&ppargv,0/*out delmt*/);//~v77KI~
        if (opdno)                                                 //~v77KI~
        {                                                          //~v77KI~
	        opdno=min(availprmctr,opdno);                          //~v77KR~
//      	memcpy(prm,ppargv,(UINT)(opdno*4));                    //~va70R~
        	memcpy(prm,ppargv,(UINT)(opdno*PTRSZ));                //~va70I~
        }                                                          //~v77KI~
    	if (rc=funcexeredirect_cmdcall(Popt,Ppcw,Pppredirectcmd,prm,Pprmctr+opdno,Pfhlog),rc>1)//~v77KR~
        	break;                                                 //~v77KI~
        if (rc)                                                    //~v77KI~
        	errctr++;                                              //~v77KI~
	    Popt|=FERO_2NDLOOP;                                        //~v77KR~
    }//until eof                                                   //~v77KI~
    fclose(fh);                                                    //~v77KI~
    fprintf(Pfhlog,"!!total %5d times by %s\n",lineno,Pparmfile);  //~v77KM~
    if (!rc)                                                       //~v77KI~
    	if (errctr)                                                //~v77KI~
    		rc=1;                                                  //~v77KI~
    return 0;                                                      //~v77KR~
}//funcexeredirect_parmfile                                        //~v77KI~
//**************************************************               //~v77KI~
//*execmdsub by redirect parm(@parmfile)                           //~v77KI~
//**************************************************               //~v77KI~
int funcexeredirect_cmdcall(int Popt,PUCLIENTWE Ppcw,char **Pppredirectcmd, char **Pppprm,int Pprmctr,FILE *Pfhlog)//~v77KR~
{                                                                  //~v77KI~
	int rc,rc2=0,ignorerc,ignorercall,cmd2ndsw;                    //~v77KR~
    char **ppc,*pc;                                                //~v77KR~
//**********************************                               //~v77KI~
	ignorercall=Popt & FERO_IGNORERC;                              //~v77KR~
	if (Popt & FERO_2NDLOOP)                                       //~v77KR~
		cmd2ndsw=1;                                                //~v77KI~
    else                                                           //~v77KI~
		cmd2ndsw=0;                                                //~v77KI~
    Pppprm[Pprmctr]=0;	//endoflist id                             //~v77KR~
    for (ppc=Pppredirectcmd;pc=*ppc,pc;ppc++)                      //~v77KI~
    {                                                              //~v77KI~
    	rc=execmdsub(0,Ppcw,pc,Pppprm,&cmd2ndsw,&ignorerc,Pfhlog); //~v77KR~
    	if (rc>=4)                                                 //~v77KI~
        {                                                          //~v77KI~
	    	if (!ignorercall && !ignorerc)                         //~v77KR~
            {                                                      //~v77KI~
            	rc2=4;                                             //~v77KI~
                break;                                             //~v77KI~
            }                                                      //~v77KI~
            rc2=1;                                                 //~v77KI~
        }                                                          //~v77KI~
    }//until eof                                                   //~v77KI~
    return rc2;                                                    //~v77KR~
}//funcexeredirect_cmdcall                                         //~v77KI~
//**************************************************               //~v55nI~
//*exec file cmd                                                   //~v55nI~
//**************************************************               //~v55nI~
//int execmdsub(PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw)//~v58uR~
//int execmdsub(PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw,int *Pignorerc)//~v77KR~
int execmdsub(int Popt,PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw,int *Pignorerc,FILE *Pfhlog)//~v77KR~
{                                                                  //~v55nI~
    char *pcmd;                                                    //~v55nR~
    int rc;                                                        //~v55nI~
//**************************************************               //~v55nI~
//cmd is locale or utf8 string                                     //~va20I~
	pcmd=Pcmdbuff+strspn(Pcmdbuff," \t");                          //~v55nI~
    if (*pcmd=='#')                                                //~v55nI~
    	return 0;                                                  //~v55nI~
    if (*pcmd==EXECMD_IGNORE_ERRID)	//ignore rc of all submcmd     //~v58uI~
    {                                                              //~v58uI~
        *Pignorerc=1;                                              //~v58uI~
//cmd is locale or utf8 string                                     //~va20I~
		pcmd=pcmd+1+strspn(pcmd+1," \t");                          //~v58uI~
    }                                                              //~v58uI~
    else                                                           //~v58uI~
        *Pignorerc=0;                                              //~v58uI~
    if (!strlen(pcmd))                                             //~v55nI~
    	return 0;                                                  //~v55nI~
    ucmdparmedit(0,pcmd,0,Pcmdparm,&pcmd);//0 no padding unused parm//~v55nR~
	funcsetlongcmd(Ppcw,1,pcmd,(int)strlen(pcmd),0);	//1:execute,0:no output cmdlen//~v603R~
    if (Pfhlog)                                                    //~v77KI~
    	fprintf(Pfhlog,"--: %s\n",pcmd);                           //~v77KR~
    ufree(pcmd);                                                   //~v55nI~
    if (*Pcmdsw)	//2nd cmd                                      //~v55nI~
    {                                                              //~v63mI~
    	scrdisp();                                                 //~v55nI~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
        wxe_scrdraw();                                             //~v63mI~
#endif                                                             //~v63mI~
    }                                                              //~v63mI~
  for (;;)                                                         //~v56uI~
  {                                                                //~v56uI~
    UCBITON(Gprocstatus,GPROCSEXECMDFILE);                         //~v563I~
    UCBITON(Ppcw->UCWflag3,UCWF3EXECMD);   //protect free current pcw//~v77LI~
    rc=kbdproc();                                                  //~v55nI~
    UCBITOFF(Ppcw->UCWflag3,UCWF3EXECMD);                          //~v77LI~
    UCBITOFF(Gprocstatus,GPROCSEXECMDFILE);                        //~v563I~
    if (Pfhlog)                                                    //~v77KI~
    {                                                              //~v77KI~
	    EXE_ERRMSGLOG(Pfhlog) 	//errmsg cleared by scrdisp        //~v77KR~
    	fprintf(Pfhlog,"--: rc=%d\n",rc);                          //~v77KR~
    }                                                              //~v77KI~
    if (rc>=4)                                                     //~v56uI~
    	break;                                                     //~v56uI~
    if (!*Gcmdbuff) //all multicmd                                 //~v56uI~
    	break;                                                     //~v56uI~
    scrdisp();                                                     //~v56uI~
//#ifdef WXE                                                       //~v651R~
#ifdef WXEXXE                                                      //~v651I~
        wxe_scrdraw();                                             //~v63mI~
#endif                                                             //~v63mI~
  }                                                                //~v56uI~
    *Pcmdsw=1;                                                     //~v55nI~
	return rc;                                                     //~v55nI~
}//execmdsub                                                       //~v55nI~
//**************************************************            //~5114I~
//*Retrieve                                                     //~5114I~
//**************************************************            //~5114I~
//*previous                                                     //~5114I~
int func_retrieveprev(PUCLIENTWE Ppcw)                          //~5114I~
{                                                               //~5114I~
	return funcretrieve(Ppcw,UQUE_AFT);	//next is prev cmd(LIFO)//~v04hR~
}//func_retrieveprev                                            //~5114I~
                                                                //~5114I~
//*next                                                         //~5114I~
int func_retrievenext(PUCLIENTWE Ppcw)                          //~5114I~
{                                                               //~5114I~
	return funcretrieve(Ppcw,UQUE_BEF);	//prev is forward(LIFO) //~v04hR~
}//func_retrievenext                                            //~5114I~
                                                                //~5114I~
//*previous of the scr                                             //~v670I~
int func_retrieveprevscr(PUCLIENTWE Ppcw)                          //~v670I~
{                                                                  //~v670I~
    int rc;                                                        //~v670I~
    static int Sprevseqno=0;                                       //~v670I~
//*******************                                              //~v670I~
    if (Ppcw->UCWseqno!=Sprevseqno)                                //~v670I~
    {                                                              //~v670I~
        Scurstack=0;	//search from top                          //~v670I~
        Sprevdest=-1;   //force search TOP or END                  //~v670I~
    }                                                              //~v670I~
    Sprevseqno=Ppcw->UCWseqno;                                     //~v670I~
	Sretreivescrsw=1;                                              //~v670I~
	rc=funcretrieve(Ppcw,UQUE_AFT);	//next is prev cmd(LIFO)       //~v670I~
	Sretreivescrsw=0;                                              //~v670I~
    return rc;                                                     //~v670I~
}//func_retrieveprev                                               //~v670I~
                                                                   //~v670I~
//*next of the scr                                                 //~v670I~
int func_retrievenextscr(PUCLIENTWE Ppcw)                          //~v670I~
{                                                                  //~v670I~
    int rc;                                                        //~v670I~
    static int Sprevseqno=0;                                       //~v670I~
//*******************                                              //~v670I~
    if (Ppcw->UCWseqno!=Sprevseqno)                                //~v670I~
    {                                                              //~v670I~
        Scurstack=0;	//search from END                          //~v670I~
        Sprevdest=-1;   //force search TOP or END                  //~v670I~
    }                                                              //~v670I~
    Sprevseqno=Ppcw->UCWseqno;                                     //~v670I~
	Sretreivescrsw=1;                                              //~v670I~
	rc=funcretrieve(Ppcw,UQUE_BEF);	//prev is forward(LIFO)        //~v670I~
	Sretreivescrsw=0;                                              //~v670I~
    return rc;                                                     //~v670I~
}//func_retrievenext                                               //~v670I~
                                                                   //~v670I~
//*common retrieve                                              //~5114I~
int funcretrieve(PUCLIENTWE Ppcw,int Pdest)                     //~v04hR~
{                                                               //~5114I~
	PUSCMD psc;			//stack cmd                             //~5114I~
    int pos,rc=0;                                               //~v04hR~
    int datalen;                                                //~v04gR~
//**************************************************            //~5114I~
	if (Ppcw->UCWmaxline<=CMDLINENO)                            //~5114I~
		return 4;                                               //~5114I~
    if ((pos=((UFLDE*)getuflde(Ppcw,CMDLINENO,0))->UFLstart)>=Ppcw->UCWwidth)//~v020R~
		return 4;	//no display width                          //~5219I~
    if (Sretreivecmdtype!=Sretreivescrsw)                          //~v670I~
    {                                                              //~v670I~
    	Scurstack=0;		//if mixed operation reset to top      //~v670I~
	    Sretreivecmdtype=Sretreivescrsw;     //save previous operation type//~v670I~
        Sprevdest=-1;   //force search TOP or END                  //~v670I~
    }                                                              //~v670I~
    if (Scurstack)	//continuous retrieve                       //~v04hR~
    	if (Pdest==UQUE_AFT)                                    //~v04hI~
        	psc=UGETQNEXT(Scurstack);                           //~v04hI~
        else                                                    //~v04hI~
        	psc=UGETQPREV(Scurstack);                           //~v04hR~
	else                                                        //~v04hI~
        if (Sprevdest==Pdest)	//repeated                      //~v04hI~
        	psc=0;                                              //~v04hI~
		else                                                    //~v04hI~
	    	if (Pdest==UQUE_AFT)                                //~v04hR~
     		   	psc=UGETQTOP(&Gcmdstack);                       //~v04hR~
        	else                                                //~v04hR~
		        if (Sprevdest)	//changed dest                  //~v04hI~
	        		psc=UGETQEND(&Gcmdstack);                   //~v04hI~
				else			//first time                    //~v04hI~
		        	psc=0;                                      //~v04hI~
    if (Sretreivescrsw && psc)	//select of the screen             //~v670I~
    {                                                              //~v670I~
    	while (psc)                                                //~v670R~
        {                                                          //~v670I~
			if (psc->USCseqno==Ppcw->UCWseqno)   //select only of the scr//~v670R~
            	break;                                             //~v670I~
	    	if (Pdest==UQUE_AFT)                                   //~v670I~
	        	psc=UGETQNEXT(psc);                                //~v670I~
    	    else                                                   //~v670I~
        		psc=UGETQPREV(psc);                                //~v670I~
        }                                                          //~v670I~
    }                                                              //~v670I~
	Scurstack=psc;	//for next retrieve                         //~v04hI~
	Sprevdest=Pdest;	//for next retrieve                     //~v04hI~
	if (!psc)	//no entry                                      //~v04hR~
    {                                                           //~v04hI~
		setflddata(Ppcw,CMDLINENO,0,"");//clear fld     //~v04hI~
		uerrmsg("reached to top or bottom",                     //~v04hI~
				"先頭か末尾に達しました");                      //~v04hI~
        rc=4;                                                   //~v04hI~
        datalen=0;                                                 //~v0imI~
	}                                                           //~v04hI~
    else                                                        //~v04hI~
    {
        scrclearmsg(Ppcw);                                      //~v04hI~
//  	datalen=setflddata(Ppcw,CMDLINENO,0,psc->USCcmd);//actual set len//~v0imR~
//  	if (datalen<(srclen=(int)strlen(psc->USCcmd)))             //~v0imR~
//      {                                                          //~v0imR~
//  		uerrmsg("Input truncated by field width",              //~v0imR~
//  				"入力幅以上は切り捨てられました");             //~v0imR~
//          rc=4;                                                  //~v0imR~
//      }                                                          //~v0imR~
#ifdef UTF8SUPPH                                                   //~va1rI~
		funcsetlongcmdfromstack(Ppcw,0,psc,&datalen);	//no execute,le by strlen//~va1rI~
#else                                                              //~va1rI~
		funcsetlongcmd(Ppcw,0,psc->USCcmd,0,&datalen);	//no execute,le by strlen//~v0imR~
#endif                                                             //~va1rI~
    }
    Ppcw->UCWrcsry=CMDLINENO;                                   //~5219I~
    Ppcw->UCWrcsrx=pos+datalen;                                 //~v04gR~
    csrrestore(Ppcw);   //set csr to end of cmd line            //~v04gR~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);      //~5114I~
  	UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err          //~5114I~
	return rc;                                                  //~v04hR~
}//funcretrieve                                                 //~5114I~
//**************************************************************** //~vbi3I~
int funcretrievepsc(int Popt,PUCLIENTWE Ppcw,PUSCMD Ppsc,void *Pplh)//~vbi3R~
{                                                                  //~vbi3I~
    int datalen,pos;                                               //~vbi3R~
//**************************************************               //~vbi3I~
	if (Ppcw->UCWmaxline<=CMDLINENO)                               //~vbi3I~
		return 4;                                                  //~vbi3I~
    if ((pos=((UFLDE*)getuflde(Ppcw,CMDLINENO,0))->UFLstart)>=Ppcw->UCWwidth)//~vbi3R~
		return 4;	//no display width                             //~vbi3I~
    scrclearmsg(Ppcw);                                             //~vbi3I~
	funcsetlongcmdfromstack(Ppcw,0,Ppsc,&datalen);	//no execute,le by strlen//~vbi3I~
    Ppcw->UCWrcsry=CMDLINENO;                                      //~vbi3I~
    Ppcw->UCWrcsrx=pos;                                            //~vbi3R~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);         //~vbi3I~
  	UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err             //~vbi3I~
	return 0;                                                      //~vbi3I~
}//funcretrievepsc                                                 //~vbi3I~
//****************************************************************************//~vbCBI~
int funcrestorePSC(PUCLIENTWE Ppcw,PUSCMD Ppsc)                    //~vbCBR~
{                                                                  //~vbCBI~
    int pos,rc=0;                                                  //~vbCBI~
    int datalen;                                                   //~vbCBI~
//**************************************************               //~vbCBI~
    UTRACEP("%s:psccmd=%s\n",UTT,Ppsc->USCcmd);                    //~vbCBI~
	if (Ppcw->UCWmaxline<=CMDLINENO)                               //~vbCBI~
		return 4;                                                  //~vbCBI~
    if ((pos=((UFLDE*)getuflde(Ppcw,CMDLINENO,0))->UFLstart)>=Ppcw->UCWwidth)//~vbCBI~
		return 4;	//no display width                             //~vbCBI~
	funcsetlongcmdfromstack(Ppcw,0,Ppsc,&datalen);	//no execute,le by strlen//~vbCBI~
    Ppcw->UCWrcsry=CMDLINENO;                                      //~vbCBI~
    Ppcw->UCWrcsrx=pos+datalen;                                    //~vbCBI~
    csrrestore(Ppcw);   //set csr to end of cmd line               //~vbCBI~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);         //~vbCBI~
  	UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err             //~vbCBI~
	return rc;                                                     //~vbCBI~
}//funcretrievePSC                                                 //~vbCBI~
//**************************************************               //~v47kI~
//*func_cmdrepeat                                                  //~v47kI~
//*repaet previous command                                         //~v47kI~
//*parm1:pcw                                                       //~v47kI~
//*ret  :none                                                      //~v47kI~
//**************************************************               //~v47kI~
int func_cmdrepeat(PUCLIENTWE Ppcw)                                //~v47kI~
{                                                                  //~v47kI~
	PUSCMD psc;			//stack cmd                                //~v47kI~
    int rc;                                                        //~v47kR~
//**************************************************               //~v47kI~
//  if (Ppcw->UCWmaxline<=CMDLINENO)                               //~v47kI~
//  	return 4;                                                  //~v47kI~
//  if ((pos=((UFLDE*)getuflde(Ppcw,CMDLINENO,0))->UFLstart)>=Ppcw->UCWwidth)//~v47kI~
//  	return 4;	//no display width                             //~v47kI~
    psc=UGETQTOP(&Gcmdstack);                                      //~v47kI~
	if (!psc)	//no entry                                         //~v47kI~
    {                                                              //~v47kI~
		uerrmsg("no previous cmd",                                 //~v47kI~
				"前にコマンド入力が有りません");                   //~v47kI~
        return 4;                                                  //~v47kI~
	}                                                              //~v47kI~
    scrclearmsg(Ppcw);                                             //~v47kI~
#ifdef UTF8SUPPH                                                   //~va1rI~
    rc=funcsetlongcmdfromstack(Ppcw,FSLCO_EXECUTE,psc,0/*out len*/);  //execute execute,no output cmd len//~va1rI~
#else                                                              //~va1rI~
    rc=funcsetlongcmd(Ppcw,1,psc->USCcmd,psc->USCcmdlen,0);  //execute execute,no output cmd len//~v47kI~
#endif                                                             //~va1rI~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);         //~v47kI~
  	UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err             //~v47kI~
	return rc;                                                     //~v47kI~
}//func_cmdrepeat                                                   //~v47kI~//~va1rR~
//**************************************************               //~vbi3I~
//*func_cmdrepeat                                                  //~vbi3I~
//*repaet previous command                                         //~vbi3I~
//*parm1:pcw                                                       //~vbi3I~
//*ret  :none                                                      //~vbi3I~
//**************************************************               //~vbi3I~
int funccmdrepeatpsc(int Popt,PUCLIENTWE Ppcw,PUSCMD Ppsc)         //~vbi3I~
{                                                                  //~vbi3I~
    int rc;                                                        //~vbi3I~
//**************************************************               //~vbi3I~
    scrclearmsg(Ppcw);                                             //~vbi3I~
    rc=funcsetlongcmdfromstack(Ppcw,FSLCO_EXECUTE,Ppsc,0/*out len*/);  //execute execute,no output cmd len//~vbi3I~
	UCBITON((Ppcw->UCWpsd+CMDLINENO)->USDflag2,USDF2DRAW);         //~vbi3I~
  	UCBITOFF(Ppcw->UCWflag,UCWFCMDERR);//clear cmd err             //~vbi3I~
	return rc;                                                     //~vbi3I~
}//funccmdrepeatpsc                                                //~vbi3I~
                                                                   //~v47kI~
#ifdef UTF8SUPPH                                                   //~va1rI~
//**************************************************               //~va1rI~
//*funccmdstack with locale code                                   //~va1rR~
//**************************************************               //~va1rI~
void funccmdstack_utf8(int Popt,UCHAR *Pcmd,int Pcmdlen,int Pseqno)//~va1rI~
{                                                                  //~va1rI~
                                                                   //~vavkI~
//**************************************************               //~va1rI~
  	if (Popt & FCSO_SETCT  		//check Gcmdbuffct                 //~va1rI~
  	&&  !strcmp(Gcmdbuffu8,Pcmd)	//same as set by funcgetlongcmd called from funccall//~va1rR~
  	)                                                              //~va1rI~
    	if (strcmp(Gcmdbuffu8,Gcmdbufflc))	//contains utf8 code   //~va1rI~
	    	Sstackctsw=1; 	//parm to cmdstack                     //~va1rR~
#ifdef W32UNICODE                                                  //~vavkI~
  if (Sstackctsw                                                   //~vavkR~
  &&  !memchr(Pcmd,UD_NOTLC,Pcmdlen))                              //~vavkR~
  {                                                                //~vavkI~
	int udcmdlen;                                                  //~vavkR~
    char wkudcmd[MAXPARMSZ];                                       //~vavkI~
    //****                                                         //~vavkI~
//  fsubw_U8CT2UD(0,Pcmd,Gcmdbuffct,Pcmdlen,wkudcmd,sizeof(wkudcmd),&udcmdlen);//~vavkR~//~vawwR~
    fsubw_U8CT2UD(0,Pcmd,Gcmdbuffct,Pcmdlen,Gcmdbufflclen,wkudcmd,sizeof(wkudcmd),&udcmdlen);//~vawwI~
	funccmdstack(wkudcmd,udcmdlen,Pseqno);                         //~vavkR~
  }                                                                //~vavkI~
  else                                                             //~vavkI~
#endif                                                             //~vavkI~
	funccmdstack(Pcmd,Pcmdlen,Pseqno);                             //~va1rI~
    Sstackctsw=0;                                                  //~va1rI~
	return;                                                        //~va1rI~
}//funccmdstack_utf8                                               //~va1rI~
#endif                                                          //~5114I~//~va1rI~
//**************************************************            //~5114I~
//*funccmdstack                                                 //~5114I~
//*stack input cmd for retrieve                                 //~5114I~
//*parm1:string addr                                            //~5114I~
//*parm2:string len                                             //~5114I~
//*ret  :none                                                   //~5114I~
//**************************************************            //~5114I~
//void funccmdstack(UCHAR *Pcmd,int Pcmdlen)                       //~v670R~
//void funccmdstack(UCHAR *Pcmd,int Pcmdlen,int Pseqno)            //~vbCBR~
PUSCMD funccmdstack(UCHAR *Pcmd,int Pcmdlen,int Pseqno)            //~vbCBI~
{                                                               //~5114I~
	PUSCMD psc;			//stack cmd                             //~5114I~
    int breaksw;                                                   //~v670I~
#ifdef UTF8SUPPH                                                   //~va1rI~
	int lenlc;                                                     //~va1rI~
#endif                                                             //~va1rI~
//**************************************************            //~5114I~
    funccmdlog(Pcmd,Pcmdlen);                                      //~v62GI~
    Scurstack=0;                                                //~v04hM~
    Sprevdest=0;	//reached to last                           //~v04hM~
    if (!Pcmdlen)   //emptry enter                              //~v04hI~
//      return;                                                    //~vbCBR~
        return 0;                                                  //~vbCBI~
	for (psc=UGETQTOP(&Gcmdstack);psc;psc=UGETQNEXT(psc))//chk same string//~5114I~
    {                                                           //~5225I~
    	breaksw=0;                                                 //~v670R~
        if (*psc->USCcmd=='='  	//dup call if = cmd,first with =   //~v06KR~
        &&  *Pcmd!='=')         //second without =                 //~v06KR~
        {                                                       //~5225I~
			if (Pcmdlen==psc->USCcmdlen-1                       //~5225I~
			&&  !memcmp(Pcmd,psc->USCcmd+1,(UINT)Pcmdlen))	//same text//~5225I~
//  			break;                                             //~v670R~
    			breaksw=1;                                         //~v670I~
        }                                                       //~5225I~
        else                                                    //~5225I~
			if (Pcmdlen==psc->USCcmdlen                         //~5225R~
			&&  !memcmp(Pcmd,psc->USCcmd,(UINT)Pcmdlen))	//same text//~5225R~
//  			break;                                             //~v670R~
    			breaksw=1;                                         //~v670I~
        if (breaksw)                                               //~v670I~
        {                                                          //~v670I~
            if (psc->USCseqno==0        //prev session             //~v670I~
            ||  psc->USCseqno==Pseqno)                             //~v670I~
                break;                                             //~v670I~
        }                                                          //~v670I~
    }                                                           //~5225I~
    if (psc)	//found                                            //~v670R~
		UDEQ(UQUE_ENT,&Gcmdstack,psc);	//deq to re-enq         //~5114I~
	else		//not found                                     //~5114I~
	{                                                           //~5114I~
#ifdef UTF8SUPPH                                                   //~va1rI~
		lenlc=0;                                                   //~va1rI~
	  if (Sstackctsw)                                              //~va1rI~
      {                                                            //~va1rI~
//    	lenlc=strlen(Gcmdbufflc);                                  //~va1rI~//~vb2DR~
      	lenlc=(int)strlen(Gcmdbufflc);                             //~vb2DI~
    	psc=UALLOCM((UINT)(USCMDSZ+Pcmdlen+lenlc+1));              //~va1rR~
      }                                                            //~va1rI~
      else                                                         //~va1rI~
#endif                                                             //~va1rM~
    	psc=UALLOCM((UINT)(USCMDSZ+Pcmdlen));                   //~v04dR~
        if (psc)                                                //~v04dI~
        {                                                       //~v04dI~
        	memset(psc,0,USCMDSZ);                              //~v04dR~
       		memcpy(psc->USCcmd,Pcmd,(UINT)Pcmdlen);             //~v04dR~
        	*(psc->USCcmd+Pcmdlen)=0;//for setflddata strncpy   //~v04dR~
        	psc->USCcmdlen=Pcmdlen;                             //~v04dR~
#ifdef UTF8SUPPH                                                   //~va1rI~
	  		if (Sstackctsw)                                        //~va1rI~
      		{                                                      //~va1rI~
	        	psc->USCcmdlenlc=lenlc;                            //~va1rR~
	        	memcpy(psc->USCcmd+Pcmdlen+1,Gcmdbufflc,(UINT)(lenlc+1));//~va1rR~
      		}                                                      //~va1rI~
#endif                                                             //~va1rR~
	        psc->USCentryno=++Suscentryno;	//search key           //~vbi3I~
        }                                                       //~v04dI~
	}//not found                                                //~5114I~
    if (psc)                                                    //~v04dI~
    {                                                              //~v670I~
		UENQ(UQUE_TOP,&Gcmdstack,psc);	//enq to top            //~v04dR~
        psc->USCseqno=Pseqno;	//instanceID of the screen         //~v670I~
    }                                                              //~v670I~
#if  defined(DOS) && !defined(DPMI)	//native DOS                   //~v11BI~
//*chk max entry                                                //~5114I~
    if (UGETQCTR(&Gcmdstack)>Gcmdmaxstack)                      //~5114I~
    {	                                                        //~5114I~
		psc=UDEQ(UQUE_END,&Gcmdstack,0);	//deq oldest        //~5114I~
        ufree(psc);                                             //~5114I~
        psc=0;                                                     //~vbCBI~
	}                                                           //~5114I~
#endif                                                             //~v11BI~
//  return;                                                        //~vbCBR~
    UTRACEP("%s:cmd=%s\n",UTT,(psc?(UCHAR*)(psc->USCcmd):(UCHAR*)"ovflow freeed"));//~vbCBR~
    return psc;                                                    //~vbCBI~
}//funccmdstack                                                 //~5114I~
#ifdef UTF8SUPPH                                                   //~va1rI~
//**************************************************               //~va1rI~
//*funcrcmdstackmergeutf8                                          //~va1rR~
//*combine utf8 and lc entry after read from ini                   //~va1rI~
//**************************************************               //~va1rI~
void funcrcmdstackmergeutf8(void)                                  //~va1rR~
{                                                                  //~va1rI~
	PUSCMD psc,pscnext,pscnew;			//stack cmd                //~va1rI~
    int lenlc,lenu8;                                               //~va1rI~
    char *plc,*pu8;                                                //~va1rI~
    int opt;                                                       //~va5rI~
//**************************************************               //~va1rI~
	for (psc=UGETQTOP(&Gcmdstack);psc;psc=pscnext)//chk same string//~va1rI~
    {                                                              //~va1rI~
		pscnext=UGETQNEXT(psc);                                    //~va1rI~
        if (!pscnext)                                              //~va1rI~
        	break;                                                 //~va1rI~
        pu8=pscnext->USCcmd;                                       //~va1rR~
        lenu8=pscnext->USCcmdlen;                                  //~va1rR~
        plc=psc->USCcmd;                                           //~va1rR~
        lenlc=psc->USCcmdlen;                                      //~va1rR~
//      if (xeutf_memcmpu8lc(0,pu8,lenu8,plc,lenlc,0/*out lenlc*/))	//pu8!=lc after f2l//~va5rR~
		opt=XEUTFMC8LO_ALLOWREPCH;	//f2l err ok                   //~va5rI~
#ifdef LNX                                                         //~vaumI~
		opt|=XEUTFMC8LO_DDWREPCH;	//f2l err ok                   //~vaumI~
#endif                                                             //~vaumI~
        if (xeutf_memcmpu8lc(opt,pu8,lenu8,plc,lenlc,0/*out lenlc*/))	//pu8!=lc after f2l//~va5rI~
        	continue;                                              //~va1rI~
    	pscnew=UALLOCM((UINT)(USCMDSZ+lenu8+lenlc+1));             //~va1rI~
        if (!pscnew)                                               //~va1rI~
        	continue;                                              //~va1rI~
        memset(pscnew,0,USCMDSZ);                                  //~va1rI~
        memcpy(pscnew->USCcmd,pu8,(UINT)(lenu8+1));                //~va1rI~
        memcpy(pscnew->USCcmd+lenu8+1,plc,(UINT)(lenlc+1));        //~va1rI~
        pscnew->USCcmdlen=lenu8;                                   //~va1rI~
        pscnew->USCcmdlenlc=lenlc;                                 //~va1rR~
        pscnew->USCentryno=++Suscentryno;	//search key           //~vbi3I~
		UENQENT(UQUE_AFT,pscnext,pscnew);	//enq after to be deleted//~va1rI~
		UDEQ(UQUE_ENT,&Gcmdstack,psc);	//deq to re-enq            //~va1rI~
        ufree(psc);                                                //~va1rI~
		UDEQ(UQUE_ENT,&Gcmdstack,pscnext);	//deq to re-enq        //~va1rI~
        ufree(pscnext);                                            //~va1rI~
		pscnext=UGETQNEXT(pscnew);                                 //~va1rI~
    }                                                              //~va1rI~
	return;                                                        //~va1rI~
}//funcrcmdstackmergeutf8                                          //~va1rR~
//**************************************************               //~vbCBI~
//*funcrcmdstackmergeutf8                                          //~vbCBI~
//*combine utf8 and lc entry after read from ini                   //~vbCBI~
//**************************************************               //~vbCBI~
void funcrcmdstackFindStackRecovery(void)                          //~vbCBI~
{                                                                  //~vbCBI~
	PUSCMD psc;			//stack cmd                                //~vbCBI~
    int rc;                                                        //~vbCBI~
//**************************************************               //~vbCBI~
	for (psc=UGETQTOP(&Gcmdstack);psc;psc=UGETQNEXT(psc))//chk same string//~vbCBI~
    {                                                              //~vbCBI~
		rc=fcmdPSinit(0,psc);                                      //~vbCBI~
        if (rc)		//gotten all 3 type                            //~vbCBI~
        	break;                                                 //~vbCBI~
    }                                                              //~vbCBI~
	return;                                                        //~vbCBI~
}//funcrcmdstackmergeutf8                                          //~vbCBI~
#endif                                                             //~va1rI~
//**************************************************            //~5114I~
//*funcfreecmdstack                                             //~5114I~
//*free stack input cmd for retrieve                            //~5114I~
//*parm:none                                                    //~5114I~
//*ret  :none                                                   //~5114I~
//**************************************************            //~5114I~
void funcfreecmdstack(void)                                     //~5114I~
{                                                               //~5114I~
	PUSCMD psc;			//stack cmd                             //~5114I~
	PUSCMD pscw;			//stack cmd                            //~v085I~
//**************************************************            //~5114I~
	for (psc=UGETQTOP(&Gcmdstack);psc;)//all entry                 //~v085R~
    {                                                              //~v085I~
		pscw=UGETQNEXT(psc);	//get next addr before free        //~v085I~
		ufree(psc);                                             //~5114I~
		psc=pscw;                                                  //~v085I~
	}                                                              //~v085I~
	return;                                                     //~5114I~
}//funcfreecmdstack                                             //~5204R~
                                                                //~5114I~
//**************************************************            //~v065I~
//*funcwcmdstack                                                //~v065I~
//*write cmd stack on XE!SAVE!                                  //~v065I~
//*parm:FILE*                                                   //~v065I~
//*ret  :rc                                                     //~v065I~
//**************************************************            //~v065I~
int funcwcmdstack(FILE *Pfh)                                    //~v065I~
{                                                               //~v065I~
	PUSCMD psc;			//stack cmd                             //~v065I~
    int ii=0;                                                   //~v065I~
    int dropcnt;                                                   //~v11BI~
//  long wkint;                                                    //~va70R~
    INT4 wkint;                                                    //~va70I~
#ifdef UTF8SUPPH                                                   //~va1rI~
    int dropcnt2,lenlc,lccnt;                                      //~va1rI~
    char *plc;                                                     //~va1rI~
#endif                                                             //~va1rI~
//**************************************************            //~v065I~
    funccmdlog(0,FCMDLOG_CLOSE);   //close req                     //~v62GR~
//    for (psc=UGETQTOP(&Gcmdstack);psc;psc=UGETQNEXT(psc))//chk same string//~v11BR~
//        ii++;                                                    //~v11BR~
//  ii=UGETQCTR(&Gcmdstack);                                       //~v11BI~//~vb2ER~
    ii=(int)UGETQCTR(&Gcmdstack);                                  //~vb2EI~
	if (dropcnt=ii-Gcmdmaxstack,dropcnt>0)                         //~v11BI~
		ii=Gcmdmaxstack;                                           //~v11BI~
    else                                                           //~v11BI~
        dropcnt=0;                                                 //~v11BI~
#ifdef UTF8SUPPH                                                   //~va1rI~
	dropcnt2=dropcnt;                                              //~va1rR~
    lccnt=0;                                                       //~va1rI~
    for (psc=UGETQEND(&Gcmdstack);psc;psc=UGETQPREV(psc))//chk same string//~va1rI~
    {                                                              //~va1rI~
        if (dropcnt2)                                              //~va1rI~
        {                                                          //~va1rI~
            dropcnt2--;                                            //~va1rI~
            continue;       //skip over maxcnt                     //~va1rI~
        }                                                          //~va1rI~
		if (psc->USCcmdlenlc)	//saved by locale code             //~va1rR~
#ifdef W32UNICODE //no write cmdlc,set it at read                  //~vavkI~
          if (!memchr(psc->USCcmd,UD_NOTLC,psc->USCcmdlen))	//not ud fmt//~vavkI~
#endif                                                             //~vavkI~
        	lccnt++;                                               //~va1rR~
    }                                                              //~va1rI~
    ii+=lccnt;                                                     //~va1rI~
#endif                                                             //~va1rI~
//  wkint=(long)ii;                                                //~va70R~
    wkint=(INT4)ii;                                                //~va70I~
  	if (!fwrite(&wkint,sizeof(wkint),1,Pfh))                       //~v086R~
    	return 8;	//written count                             //~v065I~
//  for (psc=UGETQTOP(&Gcmdstack);psc;psc=UGETQNEXT(psc))//chk same string//~v06JR~
    for (psc=UGETQEND(&Gcmdstack);psc;psc=UGETQPREV(psc))//chk same string//~v06JR~
    {                                                              //~v086R~
        if (dropcnt)                                               //~v11BI~
        {                                                          //~v11BI~
            dropcnt--;                                             //~v11BI~
            continue;       //skip over maxcnt                     //~v11BI~
        }                                                          //~v11BI~
//    	wkint=(long)psc->USCcmdlen;                                //~va70R~
  	  	wkint=(INT4)psc->USCcmdlen;                                //~va70I~
	  	if (!fwrite(&wkint,sizeof(wkint),1,Pfh))                   //~v086R~
	    	return 8;	//written count                            //~v086R~
	  	if (!fwrite(psc->USCcmd,(UINT)psc->USCcmdlen,1,Pfh))       //~v086R~
	    	return 8;	//written count                         //~v065I~
#ifdef UTF8SUPPH                                                   //~va1rI~
		lenlc=psc->USCcmdlenlc;                                    //~va1rR~
        if (lenlc)                                                 //~va1rI~
        {                                                          //~va1rI~
#ifdef W32UNICODE //no write cmdlc,set it at read                  //~vavkM~
          if (!memchr(psc->USCcmd,UD_NOTLC,psc->USCcmdlen))	//not ud fmt//~vavkI~
#endif                                                             //~vavkM~
          {                                                        //~vavkI~
//  	  	wkint=(long)lenlc;                                     //~va70R~
  		  	wkint=(INT4)lenlc;                                     //~va70I~
		  	if (!fwrite(&wkint,sizeof(wkint),1,Pfh))               //~va1rI~
		    	return 8;	//written count                        //~va1rI~
            plc=psc->USCcmd+psc->USCcmdlen+1;                      //~va1rR~
	  		if (!fwrite(plc,(UINT)lenlc,1,Pfh))//by locale code    //~va1rR~
	    		return 8;                                          //~va1rI~
          }                                                        //~vavkI~
        }                                                          //~va1rI~
#endif                                                             //~va1rI~
	}                                                              //~v086R~
	return 0;                                                   //~v065I~
}//funcwcmdstack                                                //~v065I~
                                                                //~v065I~
//**************************************************            //~v065I~
//*funcrcmdstack                                                //~v065I~
//*read  cmd stack on XE!SAVE!                                  //~v065I~
//*parm:FILE*                                                   //~v065I~
//*ret  :rc                                                     //~v065I~
//**************************************************            //~v065I~
int funcrcmdstack(FILE *Pfh)                                    //~v065I~
{                                                               //~v065I~
	char *pc;                                                   //~v065I~
//  long wkint;                                                    //~va70R~
    INT4 wkint;                                                    //~va70I~
    int ii=0;                                                   //~v065I~
    int cmdlen;                                                 //~v065I~
//  int opt,uderr=0;                                               //~vb2ER~
    int uderr=0;                                                   //~vb2EI~
#ifdef W32UNICODE                                                  //~vb2EI~
    int opt;                                                       //~vb2EI~
#endif                                                             //~vb2EI~
//**************************************************            //~v065I~
  	if (!fread(&wkint,sizeof(wkint),1,Pfh))                        //~v086R~
    	return 8;	//written count                             //~v065I~
	ii=(int)wkint;                                                 //~v086R~
    for (;ii;ii--)                                              //~v065I~
    {                                                           //~v065I~
//    	if (!fread(&cmdlen,sizeof(int),1,Pfh))                     //~v086R~
	  	if (!fread(&wkint,sizeof(wkint),1,Pfh))                    //~v086R~
            return 8;                                           //~v065I~
		cmdlen=(int)wkint;                                         //~v086R~
        if (!cmdlen)                                               //~v754I~
            break;                                                 //~v754I~
//  	pc=UALLOCM((UINT)(cmdlen));                             //~v065I~//~vaw8R~
    	pc=UALLOCM((UINT)(cmdlen+1));                              //~vaw8I~
        *(pc+cmdlen)=0;	//strz for uerrmsg                         //~vaw8I~
	    UALLOCCHK(pc,UALLOC_FAILED);                            //~v065I~
	  	if (!fread(pc,(UINT)cmdlen,1,Pfh))                      //~v065R~
        {                                                          //~v086R~
            ufree(pc);                                             //~v086R~
            return 8;                                           //~v065I~
        }                                                          //~v086R~
#ifdef W32UNICODE                                                  //~vavkI~
		if (memchr(pc,UD_NOTLC,cmdlen))                            //~vavkI~
        {                                                          //~vb2EI~
//      	if (fsubw_UD2LC(0,pc,cmdlen,Gcmdbufflc,sizeof(Gcmdbufflc),NULL))  //set Gcmdbufflc from UD str//~vavkR~//~vb2ER~
			opt=FSWUD2LCO_NOMSG;                                   //~vb2EI~
        	if (fsubw_UD2LC(opt,pc,cmdlen,Gcmdbufflc,sizeof(Gcmdbufflc),NULL))  //set Gcmdbufflc from UD str//~vb2EI~
            	Sstackctsw=1;	//set SCcmdlenlc from Gcmdbufflc   //~vavkI~
            else                                                   //~vb2EI~
            	uderr=1;                                           //~vb2EI~
        }                                                          //~vb2EI~
#endif                                                             //~vavkI~
//  	funccmdstack(pc,cmdlen);                                   //~v670R~
      if (!uderr)                                                  //~vb2EI~
      {                                                            //~vbCBI~
    	funccmdstack(pc,cmdlen,0);                                 //~v670I~
      }                                                            //~vbCBI~
#ifdef W32UNICODE                                                  //~vavkI~
        Sstackctsw=0;                                              //~vavkI~
#endif                                                             //~vavkI~
        ufree(pc);                                              //~v065I~
    }                                                           //~v065I~
#ifdef UTF8SUPPH                                                   //~va1rI~
	funcrcmdstackmergeutf8();                                      //~va1rI~
#endif                                                             //~va1rI~
	funcrcmdstackFindStackRecovery();                              //~vbCBI~
    funccmdlog(0,FCMDLOG_START);   //open  req                     //~v62GR~
	return 0;                                                   //~v065I~
}//funcrcmdstack                                                //~v065I~
#ifdef UTF8SUPPH                                                                //~v065I~//~va1rR~
//**************************************************               //~va1rI~
//*set long cmd from stack                                         //~va1rI~
//*ret  :4 if overflow(cmd splitted) 8:no space to set splitid     //~va1rI~
//**************************************************               //~va1rI~
int funcsetlongcmdfromstack(PUCLIENTWE Ppcw,int Popt,PUSCMD Ppsc,int *Psetlen)//~va1rI~
{                                                                  //~va1rI~
    int lenlc,lenu8,rc,opt;                                        //~va1rI~
    UCHAR *pu8,*plc;                                               //~va1rI~
#ifdef W32UNICODE                                                  //~vavkI~
    char wkstripu8[_MAX_PATHU8];                                   //~vavkI~
#endif                                                             //~vavkI~
//**********************                                           //~va1rI~
	lenlc=Ppsc->USCcmdlenlc;                                       //~va1rI~
	lenu8=Ppsc->USCcmdlen;                                         //~va1rI~
    pu8=Ppsc->USCcmd;                                              //~va1rR~
    UTRACED("USCcmd",pu8,lenu8);                                   //~vawgI~
    if (!lenlc)                                                    //~va1rI~
        return funcsetlongcmd(Ppcw,Popt,pu8,lenu8,Psetlen);        //~va1rI~
//recover codetbl and cmdlc                                        //~va1rI~
	plc=pu8+lenu8+1;                                               //~va1rI~
#ifdef W32UNICODE                                                  //~vavkI~
	if (memchr(pu8,UD_NOTLC,lenu8))                                //~vavkI~
    {                                                              //~vavkI~
		fsubw_stripUDCT(0,pu8,lenu8,wkstripu8,sizeof(wkstripu8),NULL/*wkfpathct2*/,0/*sizeof(wkfpathct2)*/,&lenu8);//~vavkI~
        pu8=wkstripu8;                                             //~vavkI~
    }                                                              //~vavkI~
#endif                                                             //~vavkI~
//  rc=xeutf_setctbyu8lc(0,pu8,lenu8,plc,lenlc,Gcmdbuffct,sizeof(Gcmdbuffct));//~va5rR~
	opt=XEUTFSCBULO_ALLOWREPCH; //accept repch "?" as valid for cmd retrieve chk//~va5rI~
    rc=xeutf_setctbyu8lc(opt,pu8,lenu8,plc,lenlc,Gcmdbuffct,sizeof(Gcmdbuffct));//~va5rI~
    UTRACEP("%s:setctbyu8lc rc\n",UTT,rc);                         //~vawgI~
#ifdef LNX                                                         //~vandI~
  if (rc!=1)	//dd2l errrep chk ok                               //~vandI~
#endif                                                             //~vandI~
#ifdef W32UNICODE                                                  //~vaw7I~
  if (rc!=1)	//dd2l errrep chk ok                               //~vaw7I~
#endif                                                             //~vaw7I~
    if (rc) //failed                                               //~va1rI~
        return funcsetlongcmd(Ppcw,Popt,pu8,lenu8,Psetlen);        //~va1rI~
    memcpy(Gcmdbuffu8,pu8,(UINT)(lenu8+1));                        //~va1rI~
    memcpy(Gcmdbufflc,plc,(UINT)(lenlc+1));                        //~va1rR~
    setdbcstbl(Gcmdbufflc,Gcmdbuffdbcs,lenlc);                     //~va1rI~
    Gcmdbufflclen=lenlc;                                           //~va1rI~
    opt=Popt| FSLCO_SETCT | FSLCO_SETCTOK;                         //~va1rR~
    rc=funcsetlongcmd(Ppcw,opt,pu8,lenu8,Psetlen);                 //~va1rI~
    UTRACED("funcsetlongcmdfromstack Gcmdbuffu8",Gcmdbuffu8,lenu8);//~vandI~
    return rc;                                                     //~va1rI~
}//funcsetlongcmdfromstack                                         //~va1rI~
//**************************************************               //~va1rI~
//*set long cmd from stack                                         //~va1rI~
//*ret  :4 if overflow(cmd splitted) 8:no space to set splitid     //~va1rI~
//**************************************************               //~va1rI~
int funcsetlongcmd_utf8(PUCLIENTWE Ppcw,int Popt,char *Pcmdu8,int Pcmdu8len,char *Pcmdlc,int Pcmdlclen,char *Pcodetype,int *Ppdatalen)//~va1rR~
{                                                                  //~va1rI~
    int rc,opt;                                                    //~va1rR~
//**********************                                           //~va1rI~
    memcpy(Gcmdbuffu8,Pcmdu8,(UINT)(Pcmdu8len+1));                 //~va1rI~
    memcpy(Gcmdbufflc,Pcmdlc,(UINT)(Pcmdlclen+1));                 //~va1rI~
    memcpy(Gcmdbuffct,Pcodetype,(UINT)Pcmdlclen);                  //~va1rI~
    setdbcstbl(Gcmdbufflc,Gcmdbuffdbcs,Pcmdlclen);                 //~va1rR~
    Gcmdbufflclen=Pcmdlclen;                                       //~va1rR~
    opt=Popt| FSLCO_SETCT | FSLCO_SETCTOK;                         //~va1rI~
    rc=funcsetlongcmd(Ppcw,opt,Pcmdu8,Pcmdu8len,Ppdatalen);        //~va1rI~
    UTRACED("funcsetlongcmd Gcmdbuffu8",Gcmdbuffu8,Pcmdu8len);     //~vandI~
    UTRACED("funcsetlongcmd Gcmdbufflc",Gcmdbufflc,Pcmdlclen);     //~vandI~
    UTRACED("funcsetlongcmd Gcmdbuffct",Gcmdbuffct,Pcmdlclen);     //~vandI~
    return rc;                                                     //~va1rI~
}//funcsetlongcmd_utf8                                             //~va1rI~
#endif                                                             //~va1rI~
//**************************************************               //~v0imI~
//*set long cmd                                                    //~v0imI~
//*parm1:pcw                                                       //~v0imI~
//*parm2:execute option 0:set to fld,1:set to Gcmdbuff             //~v0imR~
//*parm3:cmd string                                                //~v0imI~
//*parm4:cmd len(optional)                                         //~v0imR~
//*parm5:optional output fldlen for opt=0 only                     //~v0imR~
//*ret  :4 if overflow(cmd splitted) 8:no space to set splitid     //~v161R~
//**************************************************               //~v0imI~
int funcsetlongcmd(PUCLIENTWE Ppcw,int Popt,UCHAR *Pcmd,int Plen,int *Psetlen)//~v0imR~
{                                                                  //~v0imI~
    int datalen,srclen/*,fldlen*/,skiplen;                         //~v730R~
    UCHAR /**pc,*pcd,*/*pcmd;                                      //~v730R~
//**********************                                           //~v0imI~
    if (!(srclen=Plen))                                            //~v0imR~
		srclen=(int)strlen(Pcmd);                                  //~v0imI~
    skiplen=(int)umemspnc(Pcmd,' ',(UINT)srclen);	//top space len//~v0imR~
    pcmd=Pcmd+skiplen;                                             //~v0imI~
    srclen-=skiplen;                                               //~v0imR~
//  if (srclen>MAXCOLUMN)                                          //~v0imI~//~v7ayR~
//      srclen=MAXCOLUMN;                                          //~v0imI~//~v7ayR~
    if (srclen>MAXPARMSZ)                                          //~v7ayI~
        srclen=MAXPARMSZ;                                          //~v7ayI~
//  if (Popt)		//execute                                      //~v0imI~//~va1rR~
    if (Popt & FSLCO_EXECUTE)		//execute                      //~va1rI~
    {                                                              //~v0imI~
	    memcpy(Gcmdbuff,pcmd,(UINT)srclen);                        //~v0imR~
	    *(Gcmdbuff+srclen)=0;                                      //~v0imI~
        return 0;                                                  //~v0imI~
	}                                                              //~v0imI~
  if (Popt & FSLCO_SETCT		//check Gcmdbuffct                 //~va1rI~
  &&  ((Popt & FSLCO_SETCTOK) || !strcmp(Gcmdbuffu8,pcmd))	//same as set by funcgetlongcmd called from funccall//~va1rR~
  )                                                                //~va1rI~
  {                                                                //~va1rI~
  	datalen=setflddatadbcscmd_byutf8(SFDDCUO_SETCT|SFDDCUO_FULLREP,Ppcw,0/*pos*/,Gcmdbuffu8,0/*srcdbcs unknown*/,srclen);//~va1rR~
  }                                                                //~va1rI~
  else                                                             //~va1rI~
  {                                                                //~va1rI~
//  fldlen=getfldpos(Ppcw,CMDLINENO,0,&pc,&pcd);	//available len//~v730R~
    datalen=setflddata(Ppcw,CMDLINENO,0,pcmd);//actual set len     //~v0imR~
  }                                                                //~va1rI~
    if (Psetlen)                                                   //~v0imM~
    	*Psetlen=datalen;                                          //~v0imI~
    return 0;                                                      //~v730I~
//    if (fldlen>=srclen)                                          //~v730R~
//        return 0;                                                //~v730R~
//    if (!fldlen)                                                 //~v730R~
//        return 8;                                                //~v730R~
//    fldlen--;      //for cont id                                 //~v730R~
//    setdbcstbl(pc,pcd,fldlen);                                   //~v730R~
//    *(pc+fldlen)=LONGCMDCONTID;                                  //~v730R~
//    *Gcmdbuff=0;                                                 //~v730R~
////  *(Gcmdbuff+1)=LONGCMDCONTID;                                 //~v730R~
//    memcpy(Gcmdbuff+2,pcmd+fldlen,(UINT)(srclen-fldlen));        //~v730R~
//    *(Gcmdbuff+1)=LONGCMDCONTID;    //func_cmd parm is Gcmdbuff,it should be after copy//~v730R~
//    *(Gcmdbuff+2+srclen-fldlen)=0;                               //~v730R~
//    return 4;                                                    //~v730R~
}//funcsetlongcmd                                                  //~v0imI~
                                                                   //~v0imI~
//**************************************************               //~v0imI~
//*get long cmd                                                    //~v0imI~
//*parm1:pcw                                                       //~v0imI~
//*parm2:cmd string                                                //~v0imI~
//*ret  :data len                                                  //~v0imI~
//**************************************************               //~v0imI~
int funcgetlongcmd(PUCLIENTWE Ppcw,UCHAR *Pcmd)                    //~v0imI~
{                                                                  //~v0imI~
//  int datalen,contlen;                                           //~v730R~
//**********************                                           //~v0imI~
	return getfldinput(Ppcw,CMDLINENO,0,Pcmd);	//input on cmdline //~v730I~
//    if (datalen=getfldinput(Ppcw,CMDLINENO,0,Pcmd),datalen) //input on cmdline//~v730R~
//        if (*(Pcmd+datalen-1)==LONGCMDCONTID                     //~v730R~
//        &&  !*Gcmdbuff                                           //~v730R~
//        &&  *(Gcmdbuff+1)==LONGCMDCONTID)                        //~v730R~
//        {                                                        //~v730R~
//            contlen=(int)strlen(Gcmdbuff+2);                     //~v730R~
//            memcpy(Pcmd+datalen-1,Gcmdbuff+2,(UINT)(contlen+1));//with null term//~v730R~
//            datalen+=(contlen-1);                                //~v730R~
//        }                                                        //~v730R~
//    return datalen;                                              //~v730R~
}//funcgetlongcmd                                                  //~v0imI~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************               //~va00I~
//*get long cmd by utf8                                            //~va00I~
//**************************************************               //~va00I~
int funcgetlongcmd_byutf8(int Popt,PUCLIENTWE Ppcw,UCHAR *Pcmd)    //~va00I~
{                                                                  //~va00I~
	int rc;                                                        //~va00I~
    PUPANELC ppc;                                                  //~va1rI~
    char *plc,*pc,*pct,*pdbcs;                                     //~va1rR~
    int len,headspace,tailspace,fldoffs;                           //~va1rR~
    UFLD    *pfl;                                                  //~va1rI~
//**********************                                           //~va00I~
    UCBITON(Ppcw->UCWflag2,UCWF2CMDGETU8);	//parm to getfldpos    //~va00R~
	rc=getfldinput(Ppcw,CMDLINENO,0,Pcmd);	//input on cmdline     //~va00I~
    UCBITOFF(Ppcw->UCWflag2,UCWF2CMDGETU8);                        //~va00R~
    if (Popt & FGLC8O_SETCT)    //set Gcmdbufflc,Gcmdbuffct        //~va1rI~
    {                                                              //~va1rI~
        if (*Pcmd)                                                 //~va1rI~
        {                                                          //~va1rI~
            strcpy(Gcmdbuffu8,Pcmd);    //to compare when set back at func_cmd//~va1rR~
            UTRACED("funcsetlongcmd_byutf8",Gcmdbuffu8,(int)strlen(Pcmd));//~vandI~//~vb2DR~
            ppc=Ppcw->UCWppc;                                      //~va1rR~
            pfl=ppc->UPCline[CMDLINENO].UPLpfld;     //UFLD ptr    //~va1rR~
            fldoffs=pfl->UFLentry[0].UFLstart; //field offset      //~va1rR~
            plc=ppc->UPCcmddata+fldoffs;                           //~va1rR~
            pdbcs=ppc->UPCcmddbcs+fldoffs;                         //~va1rR~
            pct=ppc->UPCcmdcodetb/*+fldoffs*/;                     //~va1rR~
            pc=plc;                                                //~va1rR~
            len=(int)strlen(pc);                                   //~va1rR~
//          headspace=umemspnc(pc,' ',len);                        //~va1rR~//~vb2DR~
//          headspace=(int)umemspnc(pc,' ',(size_t)len);           //~vb2DI~//~vb2ER~
            headspace=(int)umemspnc(pc,' ',(UINT)len);             //~vb2EI~
//          tailspace=umemrspnc(pc,' ',len);                       //~va1rR~//~vb2DR~
//          tailspace=(int)umemrspnc(pc,' ',(size_t)len);          //~vb2DI~//~vb2ER~
            tailspace=(int)umemrspnc(pc,' ',(UINT)len);            //~vb2EI~
            len-=headspace+tailspace;                              //~va1rR~
            UmemcpyZ(Gcmdbufflc,pc+headspace,(UINT)len);           //~va1rR~
            memcpy(Gcmdbuffct,pct+headspace,(UINT)len);            //~va1rR~
            memcpy(Gcmdbuffdbcs,pdbcs+headspace,(UINT)len);        //~va1rR~
            Gcmdbufflclen=len;                                     //~va1rR~
            UTRACED("funcsetlongcmd_byutf8 lc",Gcmdbufflc,len);    //~vandI~
            UTRACED("funcsetlongcmd_byutf8 ct",Gcmdbuffct,len);    //~vandI~
            UTRACED("funcsetlongcmd_byutf8 db",Gcmdbuffdbcs,len);  //~vandI~
        }                                                          //~va1rI~
        else                                                       //~va1rI~
        {                                                          //~va1rI~
            *Gcmdbuffu8=0;                                         //~va1rI~
            *Gcmdbufflc=0;                                         //~va1rI~
            Gcmdbufflclen=0;                                       //~va1rR~
        }                                                          //~va1rI~
    }                                                              //~va1rI~
    return rc;                                                     //~va00I~
}//funcgetlongcmd_byutf8                                           //~va00R~
#endif                                                             //~va00I~
//**************************************************               //~v101I~
//*hex input mode set/reset                                        //~v101I~
//*parm1:pcw                                                       //~v101I~
//*ret  :rc                                                        //~v101I~
//**************************************************               //~v101I~
int func_hexinput(PUCLIENTWE Ppcw)                                 //~v101I~
{                                                                  //~v101I~
	PUSCRD psd;                                                    //~v101I~
	PUCLIENTWE pcw;                                                //~va8tI~
//**********************                                           //~v101I~
	psd=Ppcw->UCWpsd;                                              //~v101I~
	Ghexctl[HEXCTL_LEN]=0;		//clear previous input             //~v101I~
    scrclearmsg(Ppcw);          //re-draw hdr line                 //~v101I~
	pcw=scrgetcw(-1);	//another split scr                        //~va8tI~
    if (pcw)                                                       //~va8tI~
	    scrclearmsg(pcw);          //re-draw hdr line              //~va8tI~
	if (Ghexctl[HEXCTL_MODE])                                      //~v101I~
    {                                                              //~v101I~
		*psd->USDdata=*(UCHAR*)psd->USDbuffc;	//recover 1st byte //~v101R~
		Ghexctl[HEXCTL_MODE]=0;                                    //~v101I~
        uerrmsg("HEX input mode is reset",                         //~v101I~
                "HEX入力モードのリセット");                        //~v101R~
    }                                                              //~v101I~
    else                                                           //~v101I~
    {                                                              //~v101I~
		Ghexctl[HEXCTL_MODE]=1;                                    //~v101I~
//        uerrmsg("Entered to HEX input mode",                     //~v101R~
//                "HEX入力モード");                                //~v101R~
        uerrmsg("x_",0);                                           //~v101I~
    }                                                              //~v101I~
	return 0;                                                      //~v101I~
}//func_hexinput                                                   //~v101I~
//**************************************************               //~v60vI~
//*vertical he display mode set/reset                              //~va3TR~
//*parm1:pcw                                                       //~v60vI~
//*ret  :rc                                                        //~v60vI~
//**************************************************               //~v60vI~
int func_hex_file(PUCLIENTWE Ppcw)                                 //~v60vR~
{                                                                  //~v60vI~
	PUFILEC pfc;                                                   //~v60vI~
	PUFILEH pfh;                                                   //~v78rR~
	int vnew,vold;                                                 //~v60vI~
    char *pc;                                                      //~v60vI~
//**********************                                           //~v60vI~
	pfc=Ppcw->UCWpfc;                                              //~v60vI~
    pfh=pfc->UFCpfh;                                               //~v78rR~
	vold=(UCBITCHK(pfc->UFCflag2,UFCF2VHEX)!=0);                   //~v60vI~
	if (Ppcw->UCWkeytype==UCWKTCMD	//cmd input                    //~v60vI~
 	&&  (pc=Ppcw->UCWparm,pc))				//parm exist	   	   //~v60vI~
    {                                                              //~v60vI~
		if (!strcmp(strupr(pc),"ON"))                              //~v60vI~
			vnew=1;                                                //~v60vI~
        else                                                       //~v60vI~
			if (!strcmp(strupr(pc),"OFF"))                         //~v60vI~
				vnew=0;                                            //~v60vI~
            else                                                   //~va3TI~
			if (!stricmp(pc,"YZ"))                                 //~va3TI~
            {                                                      //~va3TI~
				Goptopt3|=GOPT3_VHEXCSRZIGZAG;                     //~va3TR~
                vold=0; //avoid alread on err                      //~va3TI~
                vnew=1;                                            //~va3TR~
            }                                                      //~va3TI~
            else                                                   //~v60vI~
			if (!stricmp(pc,"NZ"))                                 //~va3TI~
            {                                                      //~va3TI~
//  			Goptopt3&=~GOPT3_VHEXCSRZIGZAG;                    //~va3TR~//~vb2DR~
    			Goptopt3&=(UCHAR)(~GOPT3_VHEXCSRZIGZAG);           //~vb2DI~
                vold=0; //avoid alread on err                      //~va3TI~
                vnew=1;                                            //~va3TI~
            }                                                      //~va3TI~
            else                                                   //~va3TI~
            {                                                      //~v60vI~
//  			uerrmsg("Specify On/Off operand,toggle if no operand",//~va3TR~
//  					"オペランドに ON/OFF を指定して下さい,無指定は反転");//~va3TR~
    			uerrmsg("HEX [On | Off | YZ | NZ ]; Z:move cursor zigzag",//~va3TI~
    			        "HEX [On | Off | YZ | NZ ]; Z:千鳥足カー\x83\\ル移動");//~va3TR~
				return 4;                                          //~v60vI~
        	}                                                      //~v60vI~
        if (vnew==vold)                                            //~v60vI~
        	return erralready();                                   //~v60vI~
    }                                                              //~v60vI~
    else	//toggle mode                                          //~v60vI~
    	vnew=!vold;                                                //~v60vI~
    if (vnew)                                                      //~v60vI~
    {                                                              //~v60vI~
//  	uerrmsg("Virtical Hex display",                            //~va3TR~
//  			"Hex２段\x95\\示");                                //~va3TR~
    	uerrmsg("Vertical Hex display(%s)",                        //~va3TI~//~va5rR~
    			"Hex２段\x95\\示(%s)",                             //~va3TI~
			((Goptopt3 & GOPT3_VHEXCSRZIGZAG)?"YZ":"NZ"));         //~va3TR~
                                                                   //~va3TI~
		UCBITON(pfc->UFCflag2,UFCF2VHEX);                          //~v60vI~
    }                                                              //~v60vI~
    else                                                           //~v60vI~
    {                                                              //~v60vI~
		uerrmsg("Reset Vertical Hex display",                      //~va3TR~
				"リセットHex２段\x95\\示");                        //~v60vI~
		UCBITOFF(pfc->UFCflag2,UFCF2VHEX);                         //~v60vI~
    }                                                              //~v60vI~
    fcmdprofupdaterecord(FPURO_VHEX,pfh->UFHfilename,0/*strval*/,vnew,0/*intval2*/);//~v78rR~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw                //~v60vI~
	return 0;                                                      //~v60vI~
}//func_hex_file                                                   //~v60vR~
//**************************************************               //~v62GI~
//*cmd log write                                                   //~v62GI~
//*p1:cmd string:0 if open/close                                   //~v62GI~
//*p2:cmd string len:cmd string==0,0:open,1:close                  //~v62GI~
//**************************************************               //~v62GI~
int funccmdlog(UCHAR *Pcmd,int Pcmdlen)                            //~v62GI~
{                                                                  //~v62GI~
static FILE *Sfhcmdlog=0;                                          //~v62GR~
static int   Scmdlogstat=0;                                        //~v62GI~
    char fpath[_MAX_PATH],*wmode;                                  //~v62GI~
	char curtime[32];                                              //~v62GI~
    int rc=0;                                                      //~v62GR~
//**************************                                       //~v62GI~
    if (!Pcmd && Pcmdlen==FCMDLOG_START)	//initial restore end  //~v62GI~
    {                                                              //~v62GI~
		Scmdlogstat=1;	//loging start                             //~v62GI~
        return 0;    	                                           //~v62GI~
    }                                                              //~v62GI~
    if(!UCBITCHK(Goptopt,GOPT_CMDLOG))                             //~v62GI~
    	return 0;                                                  //~v62GI~
	if (Pcmd)	//stack req	                                       //~v62GI~
    {                                                              //~v62GI~
    	if (Scmdlogstat && Pcmdlen>0)                              //~v62GR~
        {                                                          //~v62GI~
        	if (!Sfhcmdlog)                                        //~v62GI~
            {                                                      //~v62GI~
				if (funccmdlog(0,FCMDLOG_OPEN))                    //~v62GI~
                {                                                  //~v62GI~
					UCBITOFF(Goptopt,GOPT_CMDLOG);                 //~v62GI~
                	return 4;                                      //~v62GI~
                }                                                  //~v62GI~
            }                                                      //~v62GI~
        	utimeedit("HH:MM:SS.MIL",curtime);                     //~v62GR~
//          if (fprintf(Sfhcmdlog,"%c %s %c %s\n",                 //~v63dR~
//  			FCMDLOG_TIMESTAMPID,curtime,FCMDLOG_TIMESTAMPID,Pcmd)<0)//~v63dR~
#ifdef DOS                                                         //~v651I~
            if (fprintf(Sfhcmdlog,"%c %s %c %s\n",                 //~v651I~
    			FCMDLOG_TIMESTAMPID,curtime,FCMDLOG_TIMESTAMPID,Pcmd)<0)//~v651I~
#else                                                              //~v651I~
            if (fprintf(Sfhcmdlog,"%c %s (%5lu)%c %s\n",           //~v63hR~
    			FCMDLOG_TIMESTAMPID,curtime,ugetpid(),FCMDLOG_TIMESTAMPID,Pcmd)<0)//~v63dI~
#endif                                                             //~v651I~
            {                                                      //~v62GI~
				filefullpath(fpath,XECMDLOGFNM,_MAX_PATH);         //~v62GR~
            	uerrmsg("cmdlog(%s) write failed.",0,              //~v62GI~
                		fpath);                                    //~v62GI~
	        	fileclose(fpath,Sfhcmdlog);                        //~v62GI~
		    	Sfhcmdlog=0;                                       //~v62GI~
            	rc=4;                                              //~v62GI~
            }                                                      //~v62GI~
            fflush(Sfhcmdlog);                                     //~v62GR~
        }                                                          //~v62GI~
    }                                                              //~v62GI~
    else                                                           //~v62GI~
    {                                                              //~v62GI~
        filefullpath(fpath,XECMDLOGFNM,_MAX_PATH);                 //~v62GR~
        utimeedit("YYYY/MM/DD HH:MM:SS",curtime);                  //~v62GR~
        switch(Pcmdlen)                                            //~v62GI~
        {                                                          //~v62GI~
    	case FCMDLOG_CLOSE:	//close req                            //~v62GR~
        	if (Sfhcmdlog)                                         //~v62GI~
            {                                                      //~v62GI~
//  		    fprintf(Sfhcmdlog,"#=== log closed === : %s\n",curtime);//~v63dR~
#ifdef DOS  //gcc                                                  //~v651I~
    		    fprintf(Sfhcmdlog,"#=== log closed=== : %s\n",curtime);//~v651I~
#else                                                              //~v651I~
    		    fprintf(Sfhcmdlog,"#=== log closed(%5lu)=== : %s\n",ugetpid(),curtime);//~v63hR~
#endif                                                             //~v651I~
	        	rc=fileclose(fpath,Sfhcmdlog);                     //~v62GR~
            }                                                      //~v62GI~
            Sfhcmdlog=0;                                           //~v62GI~
            break;                                                 //~v62GI~
    	case FCMDLOG_OPEN:	//close req                            //~v62GI~
        	wmode="a";                                             //~v62GI~
        	Sfhcmdlog=fileopen(fpath,wmode);                       //~v62GI~
            if (!Sfhcmdlog)                                        //~v62GI~
            	rc=4;                                              //~v62GI~
//  	    fprintf(Sfhcmdlog,"#=== log opened === : %s\n",curtime);//~v63dR~
#ifdef DOS  //gcc                                                  //~v651I~
    	    fprintf(Sfhcmdlog,"#=== log opened=== : %s\n",curtime);//~v651I~
#else                                                              //~v651I~
    	    fprintf(Sfhcmdlog,"#=== log opened(%5lu)=== : %s\n",ugetpid(),curtime);//~v63hR~
#endif                                                             //~v651I~
            fflush(Sfhcmdlog);                                     //~v62GI~
            break;                                                 //~v62GI~
        }                                                          //~v62GI~
    }                                                              //~v62GI~
    return rc;                                                     //~v62GI~
}//funccmdlog                                                      //~v62GI~
//**************************************************
//*key input chk test function, test purpose only
//**************************************************
void pftchk(FUNCPARMS)
{
//	printf("%s\n",((FUNCTBL*)(Ppcw->UCWpfunct))->FTnamee);         //~vagcR~
}
//**************************************************               //~v0a2I~
//*funcinhibitkey2                                                 //~v0a2I~
//*parm: none                                                      //~v0a2I~
//*rc   :4                                                         //~v0a2I~
//**************************************************               //~v0a2I~
int  funcinhibitkey2(int Pchar)                                    //~v218R~
{                                                                  //~v0a2I~
//************************************                             //~v0a2I~
	uerrmsg("Char-0x%02x is input prohibitted on this place",      //~v218R~
  		    "この場所に 文字-0x%02x は入力できません",             //~v218R~
			Pchar);                                                //~v218I~
	return 4;                                                      //~v0a2I~
}//funcinvalidkey2                                                 //~v218R~
//**************************************************               //~v101I~
//*funchexerr                                                      //~v218R~
//*parm: none                                                      //~v101I~
//*rc   :4                                                         //~v101I~
//**************************************************               //~v101I~
int  funchexerr(void)                                              //~v101I~
{                                                                  //~v101I~
//************************************                             //~v101I~
	uerrmsg("Invalid char under HEX input mode",                   //~v101I~
  		    "HEX文字入力エラー");                                  //~v101R~
	return 4;                                                      //~v101I~
}//funchexerr                                                      //~v101I~
//**************************************************               //~v77LI~
//*funcerrexecmdinprog                                             //~v77LI~
//**************************************************               //~v77LI~
int  funcerrexecmdinprog(void)                                     //~v77LI~
{                                                                  //~v77LI~
//************************************                             //~v77LI~
	uerrmsg("End/Cancel rejected by EXE cmd in progress",          //~v77LI~
  		    "End/Cancelは拒否されました(EXEコマンド実行中)");      //~v77LI~
	return 4;                                                      //~v77LI~
}//funcerrexecmdinprog                                             //~v77LI~
//**********************************************
//**function define                           *
//**********************************************
#define DUMMYPROC pftchk(FUNCPARMSPARM);  \
		uerrmsg("Not yet supported","未完,しばし待たれよ"); \
		return 0;                                               //~5502I~
//*********************************
//int func_redo_file(FUNCPARMS){DUMMYPROC}                         //~vag2R~
int func_redo_file(FUNCPARMS)                                      //~vag2I~
{                                                                  //~vag2I~
#ifdef REDO                                                        //~vag2I~
	return undo_redo(Ppcw);                                        //~vag2R~
#else                                                              //~vag2I~
	DUMMYPROC                                                      //~vag2R~
#endif                                                             //~vag2I~
}                                                                  //~vag2I~
//int func_hex_file(FUNCPARMS){DUMMYPROC}                          //~v60vR~
//**************************************************               //~vbi3I~
//*get entry for cmd history list                                  //~vbi3I~
//*Ppfmt:0;u8,1:lc,2:Windows-ud,3:lc by request                    //~vbi3R~
//**************************************************               //~vbi3I~
PUSCMD funcgetcmdstack(int Popt,PUSCMD Ppsc,char **Ppcmdstr,int *Pplen,int *Ppfmt)//~vbi3R~
{                                                                  //~vbi3I~
static PUSCMD Sprevpsc;			//previously treturned             //~vbi3I~
	PUSCMD psc;			//stack cmd                                //~vbi3I~
    char *pu8,*plc;                                                //~vbi3R~
    int lenu8,lenlc;                                               //~vbi3I~
//**************************************************               //~vbi3I~
	*Ppfmt=0;                                                      //~vbi3R~
    psc=UGETQTOP(&Gcmdstack);                                      //~vbi3R~
	if (Ppsc && Ppsc==Sprevpsc)                                    //~vbi3R~
    	psc=UGETQNEXT(Ppsc);                                       //~vbi3I~
    if (!psc)                                                      //~vbi3I~
        return 0;                                                  //~vbi3I~
	Sprevpsc=psc;                                                  //~vbi3I~
	lenlc=psc->USCcmdlenlc;                                        //~vbi3R~
	lenu8=psc->USCcmdlen;                                          //~vbi3R~
    pu8=psc->USCcmd;                                               //~vbi3R~
    if (!lenlc)                                                    //~vbi3I~
    {                                                              //~vbi3I~
    	*Ppcmdstr=pu8;                                             //~vbi3I~
        *Pplen=lenu8;                                              //~vbi3I~
		*Ppfmt=1;                                                  //~vbi3R~
    }                                                              //~vbi3I~
    else                                                           //~vbi3I~
    {                                                              //~vbi3I~
    	if (Popt & CHLO_UTF8) //get utf8                           //~vbi3R~
        {                                                          //~vbi3I~
#ifdef W32UNICODE                                                  //~vbi3I~
			if (memchr(pu8,UD_NOTLC,lenu8))                        //~vbi3R~
				*Ppfmt=2;                                          //~vbi3R~
#endif                                                             //~vbi3M~
	    	*Ppcmdstr=pu8;                                         //~vbi3I~
    	    *Pplen=lenu8;                                          //~vbi3M~
		}                                                          //~vbi3I~
        else                                                       //~vbi3I~
        {                                                          //~vbi3I~
			plc=pu8+lenu8+1;                                       //~vbi3I~
	    	*Ppcmdstr=plc;                                         //~vbi3I~
    	    *Pplen=lenlc;                                          //~vbi3I~
			*Ppfmt=3;                                              //~vbi3I~
        }                                                          //~vbi3I~
    }                                                              //~vbi3I~
	return psc;                                                    //~vbi3R~
}//funcgetcmdstack                                                 //~vbi3I~
//**************************************************               //~vbi3I~
//*search psc for cmd history list                                 //~vbi3I~
//**************************************************               //~vbi3I~
PUSCMD funcsrchpsc(int Popt,int Pentryno)                          //~vbi3R~
{                                                                  //~vbi3I~
	PUSCMD psc;			//stack cmd                                //~vbi3I~
//**************************************************               //~vbi3I~
	for (psc=UGETQTOP(&Gcmdstack);psc;psc=UGETQNEXT(psc))//chk same string//~vbi3I~
    {                                                              //~vbi3I~
    	if (Pentryno==psc->USCentryno)                             //~vbi3R~
        	break;                                                 //~vbi3I~
    }                                                              //~vbi3I~
    if (!psc)                                                      //~vbi3I~
    {                                                              //~vbi3I~
        if (Popt & FSPO_ERRMSG)                                    //~vbi3I~
            uerrmsg("Command stack entry#=%d not found(max save count=%d and latest entry#=%d).",//~vbi3I~
            	"エントリー# %d のコマンドがありません(最大保存数は %d で 直近は %d)",//~vbi3I~
                	Pentryno,Gcmdmaxstack,Suscentryno);            //~vbi3I~
    }                                                              //~vbi3I~
	return psc;                                                    //~vbi3I~
}//funcsrchpsc                                                     //~vbi3I~
