//*CID://+v9j1R~:                              update#=  612;      //~v9j1R~//~v9j2R~//~v9j1R~
//***********************************************************      //~v907R~
//* XPRINT : file print utility                                    //~v801R~
//***********************************************************
//v9j2:240629 (Bug)when Yn and WN=n, hedaer1 is set "LIN LINE|..." //~v9j2I~
//v9j1:240629 cairo scaling did not work(line overflow page width) //~v9j1I~
//v9e7:170826 compiler warning                                     //~v9e7I~
//v9e4:170812 print params on trailer                              //~v9e4I~
//v9e3:170810 shorten trailer msg for small /c parm                //~v9e3I~
//v9e1:170809 (BUG)TAB(0x09) was output when utf8 file. No actual damage because 0x09 was not printed.//~v9e1I~
//v9e0:170807 v9.38 tabchar support(tabon:c/x__/u__)               //~v9e0I~
//v9b0:161220 v9.35 warning when NOTRACE                           //~v9b0I~
//v9a1:160418 v9.33 LNX64 Compiler warning                         //~v9a1I~
//v998:160404 v9.32 W64 compiler warning                           //~v998I~
//v997:160309 v9.32 (LNX)compiler warning                          //~v997I~
//v995:160309 v9.32 (BUG)trailer line print uninitialized string   //~v995I~
//v993:160308 v9.32 ucs4 support                                   //~v993I~
//v990:140506 v9.30 (W32UNICODE) filename by UD fmt                //~v990I~
//v97G:131118 (BUG)xpr **;line is cut short by Gdatalinenosz       //~v97GI~
//v97F:131118 (BUG)xpr **; adjust header1 for lineno prefix data   //~v97FI~
//v97D:131118 (BUG)tab should be unprintable when textmode vhex dump to adjust column//~v97DI~
//v97C:131118 (BUG)formfeed should be ignored for ebc file         //~v97CI~
//v97v:131114 (BUG)-nl(no crlf) was ignored(it is default for R/V). it CRLF should be unprintable for R/V.//~v97vI~
//v97u:131113 (BUG)recordmode line fold at col=65(min maxcol)      //~v97uI~
//v97q:131110 (BUG)when utf8 file hhex dump,split utf8 code was printted to next line.//~v97qI~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//v97h:131104 conjunct mode subheader should be monospace          //~v97hI~
//v97g:131104 (BUG)conjunct mode subheader overflow area           //~v97gI~
//v97c:131029 chk pagerange of printdialog                         //~v97cI~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//v96D:130811 (BUG:Linux)TAB(0x09) should be tabctr=1 for record mode or vfmt because if expanded overflow lrecl(eject line)//~v96DI~
//v96C:130811 (BUG:Linux)UTF8 file print err on Linux;WUCS size is 4 for linux//~v96CI~
//v96x:130807 (BUG)xpr **(utf8 file) contline lineno prefix not cleared//~v96xI~
//v96w:130807 lineno field is by ascii from xe(xpr **/***) for english small letter translation//~v96wI~
//v96v:130804 long vhex scr print from xe(xpr **) vhexline split err//~v96vI~
//v96t:130804 (BUG)"mtxu /Rxx /n8" loop                            //~v96tI~
//v96r:130804 (BUG)"xpr **" for ebcfile hhex+vhex; vhexline length is same as hhex line len//~v96rI~
//v96q:130804 (BUG)"xpr **" for ebcfile from xe;nor crlf is controled//~v96qI~
//v96j:130727 v9.25 avoid tabskip when dumpmode                    //~v96jI~
//v96g:130725 v9.25 (LNX:BUG)header0 shrink detect '/' of page number//~v96gI~
//v96f:130725 v9.25 header0 shrink if record mode recordsz is too small//~v96fI~//~v96gR~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//120629 v969 VC2010:printf formt %n is deprecated and cause assetion break//~v969I~
//120629 v968 VC2010:LP64 support                                  //~v968I~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//101004 v960 option of hex dump by ucs/utf8 for utf8 (/Y8,/N8)    //~v960I~
//100923 v956 v9.20 (BUG) "too long line" err msg when from xe(xpr ** for ebc vhex mode. /Me oprion ignored)//~v956I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100908 v953 v9.19 EBC convertername support /CPEB:               //~v953I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//100428 v941 v9.16 ebcdic print support                           //~v941I~
//091215 v940 v9.15 unicode vhex line support by /WNU              //~v940I~
//080215 v92u (BUG)v9.13 ABEND when hex dump not UTF8mode          //~v92uI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//071005 v92c (Win)UTF8 support(v92b text mode vhex dump support)  //~v92cI~
//071006 v92b text mode vhex dump support                          //~v92bI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//050712 v925 (BUG)page overflow;line count is not data line count but print line count fotr vhex mode//~v925I~
//050606 v91x add /Nu option to bypass set 0x0c(form feed) for linux convenience//~v91xI~
//050309 v91r vhex print support for xe(/WN___X);line split and page eject//~v91rI~
//020719 v915 support FORM2P/WIN2P for prntyp OS2                  //~v914I~
//020719 v914 support FORM2P for prntyp WIN                        //~v914I~
//020718 v911 form2p support(ex a42,b4l2). /y2 max col is of a4,b4l2 max col is of b5//~v911I~
//020703 v910 lineno and page continue opt by /I[x]xx-xx/[nn] parm //~v910I~
//011227 v90t (BUG)/K (keisen) is ignored for /Ei                  //~v90tR~
//011227 v90s another english mode keisen                          //~v90sR~
//011209 v90m :support stdout output                               //~v90mI~
//010527 v90k :2 page support for also not unx version             //~v90kI~
//010526 v90j :ScrPrt support(/WN=linenosz /WS=xxx(xxx=org filename))//~v90jI~
//010521 v90g :LINUX support:double pageing                        //~v90gI~
//010519 v907 :LINUX support(CRLF,filename sep)                    //~v907R~
//000115 v898 :y2k:2000 year displayed as 100                      //~v898I~
//991120 v897 :line feed by 0x0a only for UNIX file also when dump mode//~v897I~
//991003 v896 :(BUG)of v890.del v892                               //~v896I~
//             if crlf if just on the line limit,colomn width is changed//~v896I~
//             between phase.so page number differ phase2 and phase1//~v896I~
//             At phase 1 crlf at 80 is line count 1 because maxline is 115,//~v896I~
//             At phase 2 crlf at 80 is line count 2 because maxline is 80.//~v896I~
//             page on header is printed like as 15/14.            //~v896I~
//             Change getinput to chk lf when cr then return lf when text mode.//~v896I~
//990918 v895 :move trt file option to /Kfxxxx from /Mmfxxxx       //~v895I~
//990918 v894 :(BUG)2 set print when last is dbcs 1st byte         //~v894I~
//990918 v893 :supprt TRT by file                                  //~v893I~
//990917 v892 :(bug of v890)need process cr+lf as lf for text mode //~v891I~
//990915 v891 :EBCDIC support /M.e[k/e]                            //~v891I~
//990828 v887 :(BUG)bug of v886;expansion of header1p destroy header0 by memcpy len err//~v887I~
//990626 v886 :(WIN:BUG)coliumn gage too short,MAXCOLMAX=512       //~v886I~
//981116 v882 :(BUG)spip1stff ignored when restart page            //~v882I~
//981114 v871 :(CANON)esccmd jobstart+soft reset cause printer performance down//~v871I~
//             wirte it at top of page of each file                //~v871I~
//981025 v867 :(WIN)same closedoc timing as os2                    //~v867I~
//             (need not chk conjunctmode.loop all input in printfile() whn that mode)//~v867I~
//981024 v866 :despage work data is raw(no jis kanji conv) data    //~v865I~
//             so pagesize is net datalen for pagework buff use chk//~v865I~
//981024 v865 :(OS2)docname set by startdoc api                    //~v865I~
//981023 v859 :(BUG of v844)output should not to be open when _WIN //~v859I~
//981010 v857 :/Yk-->/Kx;x=0(through),g(graphic),k(katakana),any char//~v857I~
//981007 v855 :fistpage formfeed skip option(/Y1)+despage(/Yp) cause 1st page print//~v855I~
//             top of page by x0c miss because 1st page has no x0c //~v855I~
//981006 v851 :write formfeed at exit                              //~v851I~
//981006 v850 :display printed pageno when ESC cancel              //~v850I~
//981005 v849 :esccmd should not be converted                      //~v849I~
//981005 v848 :char set cmd for ESCP(ESCt)                         //~v848I~
//981001 v846 :keisen print for non ibm(x'90'-->x'9b')             //~v846I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)        //~v844I~
//980926 v843 :(BUG)Win version also need shift-jis to jis when ESC cmd//~v843I~
//                  and it may be also for OS/2(see v78a)          //~v843I~
//971124 v834 :GCC version                                         //~v831I~
//971124 v832 :split xpdesp from xprint                            //~v831I~
//971124 v831 :split xppf from xprint                              //~v831I~
//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
#ifdef GTKPRINT                                                    //~v97mI~
	#include <wchar.h>                                             //~v97mI~
#endif                                                             //~v97mI~
//*************************************************************

#ifdef DOS                           //v3.6a                    //~v743I~
  #ifdef DPMI                                                      //~v831I~
  #else                                                            //~v831I~
    #include <jstring.h>                //jmstojis                 //~v831I~
  #endif                                                           //~v831I~
#else                                //v3.6a                    //~v743I~
                                                                //~v743I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
  #endif                                                           //~v826I~
                                                                //~v743I~
#endif                               //v3.6a                    //~v743I~
                                                                //~v743I~
#include <ulib.h>	                                            //~v743M~
#include <ustring.h>                                               //~v768I~
#include <uerr.h>                                                  //~v801I~
#include <ufile.h>                                                 //~v807I~
#include <ufile5.h>                                                //~v96eI~
#ifdef DPMI                 //DPMI version                         //~v834I~
	#include <udbcschk.h>	//usjis2jis                            //~v834I~
#else                       //not DPMI                             //~v834I~
    #ifdef DOS                                                     //~v843I~
    #else                                                          //~v843I~
		#include <udbcschk.h>	//usjis2jis                        //~v843I~
    #endif                                                         //~v843I~
#endif                      //DPMI or not                          //~v834I~
#include <ucvebc.h>                                                //~v953I~
#include <ucvext.h>                                                //~v953R~
#include <ucvebc4.h>                                               //~v953R~
#include <utrace.h>                                                //~v941R~
#include <utf22.h>                                                 //~v993I~
#include <uedit.h>                                                 //~v9e0I~
                                                                //~v743I~
//*********************************************************************
#include  "xp.h"                                                //~v74kI~
#include  "xpesc.h"                                                //~v831I~
#include  "xpinp.h"                                                //~v831I~
#include  "xphex.h"                                                //~v831I~
#include  "xppf.h"                                                 //~v831I~
#include  "xpsub1.h"                                               //~v831I~
#include  "xpdesp.h"                                               //~v831I~
#include  "xpjob.h"                                                //~v865I~
#include  "xputf.h"                                                //~v925I~
#ifdef W32                                                         //~v844I~
	#include  "xpwinp.h"                                           //~v844I~
#endif                                                             //~v844I~
//#ifdef UNX                                                       //~v90kR~
	#include  "xp2p.h"                                             //~v90kR~
//#endif                                                           //~v90kR~
#ifdef GXP                                                         //~v92dI~
	#include  "xplnxp.h"                                           //~v92dI~
#endif                                                             //~v92dI~
#include  "xpebc.h"                                                //~v941I~
//*********************************************************************//~v74kI~
#define XECONTLINEDELM '|'                                         //~v91rR~
       int breakpage=0;    	//input record length      	v6.7a      //~v850I~
       int Gpage2p=0;    	//page count for form2p                //~v911I~
       int Gtrailersw=0;   //parm to putline2p                     //~v911I~
       int hdr0linesw=0;    	//requesting header0 put           //~v855R~
       UCHAR *Gebctrt;      //EBCDIC trt                           //~v891I~
    int Gtabonutf8,Gtabonlocale,GtabonDBCSspace,GtabonTab,GtabonTabskip;//~v9e0R~
#define TABON_DEFAULT_DBCSSPACE_UTF8   DBCSSPACE_UCS               //~v9e0R~
#define DBCSSPACE_SJIS                 0x8140                      //~v9e0R~
#define DBCSSPACE_EBC                  0x4040                      //~v9e0I~
#define TABON_DEFAULT_DBCSSPACE_LOCALE DBCSSPACE_SJIS              //~v9e0I~
#define TABON_DEFAULT_TAB              ' '                         //~v9e0I~
#define TABON_DEFAULT_TABSKIP          ' '                         //~v9e0R~
//*********************************************************************//~v850I~
extern int Gcontpageno;                                            //~v910I~
extern int recordsz;       	//input record length      	v6.7a      //~v831I~
extern char linespwk[];             		//line hdr(line/offset) edit sprintf wk v6.7a//~v831I~
extern int dumpwidth;       	//hexdump 1 line dump width	v6.7a  //~v831I~
extern int Linecharpos;       //char dump colomn in line v6.7a     //~v831I~
extern int Linehexdpos;       //hex dec colomn in line   v6.7a     //~v831I~
extern int dumpmode;         //dump mode default=text v2.8rep v6.7r//~v831I~
extern int maxcol;      //colomn no per line v1.4rep v1.7rep v7.23r//~v831I~
extern int lineprefixsw;		//line prefix output v7.12a        //~v831I~
extern int lineskip;         //print line advancing count v3.5add  //~v831I~
extern int line;                 //v2.1rep v6.7r                   //~v831I~
extern int maxline;    //line   no per page v7.23r                 //~v831I~
extern int printdumpfsw;				//printdump sub first sw v6.7a//~v831I~
extern int puthexfsw;					//puthexline sub first sw v6.7a//~v831I~
extern int tabskip;      //tab skip colomn count v1.5add v2.1rep v7.23r//~v831I~
extern int samechk;	      	//chk same as above      v6.7a         //~v831I~
extern long inputrange1,inputrange2;	//v7.21a                   //~v831I~
extern FILE *output;       //handle v7.11r                         //~v831I~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r  //~v831I~
extern char pgmid[];     //v7.1a v7.23r                            //~v831I~
extern char ver[]; 		    //v7.1a v7.23r                         //~v831I~
extern int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~v831I~
extern char esccmd[];            //v2.9add esc command string v2.9add v5.5r//~v831I~
extern char topcmd[];    //CANON:cmd only at top of page of each file//~v871I~
extern int  topcmdlen;		//CANON:cmd only at top of page of each file//~v871I~
extern char *prn;    // default output                             //~v831I~
extern int onceputsw;    	//once write to output                 //~v851I~
extern int docnamesw;				//document name set functio v7.11a//~v865I~
extern char *Gptrtfnm;     //code page tbl filename                //~v895I~
extern int Gdatalinenosz;			//lineno data width in the file//~v90jI~
extern FILE *Gmsgfile;       //for print start msg                 //~v90mI~
//*********************************************************************//~v831I~
extern int pagesw;            //sw in the print page range v3.2add v3.7r//~v831I~
extern int  skip1stff;		//skip first page formfeed cmd opt     //~v831I~
extern int  skip1stff2;		//skip first page formfeed cmd         //~v831I~
extern int asciimode;        //char set id                     v2.5add//~v831I~
extern int Gebcdictype;      //1:katakana,2:english            v2.5add//~v891I~
extern int keisenconvsw;     //keisen kenkan syori             v2.5add//~v846I~
extern int hexdump;       	//hexdump mode	v6.7a                  //~v831I~
extern int prntyp;	//printer type(default ibm5577/ibm5575 etc) av4.5 v6.7r//~v831I~
extern char *cmdfile; 		//printer cmd file	//v5.5a v6.7r      //~v831I~
extern int  ffrepl;  		//form feed repl char                  //~v831I~
extern int nocrlfsw; 	      	//ignore crlf for dump mode v6.7a  //~v831I~
extern int minprnc;          //min continuous printable        v2.8addv3.1rep//~v831I~
extern int actualmaxc;         //colomn option specified sw  v5.1a //~v831I~
extern long totline;         //v4.6a total page count              //~v831I~
extern int  totfile;         //v4.1a total file count              //~v831I~
extern int swsetarchive;		//sw:set archive attr after print v7.2a//~v831I~
extern int pagestart;        //print page range v3.2add            //~v831I~
extern int pageend;    //print page range v3.2add      v3.6r       //~v831I~
extern char *inputrangep;		//parm for range err msg v7.21a    //~v831I~
extern int header1outsw;		//header1 output v7.12a            //~v831I~
extern int header0outsw;		//header0 output v7.12a            //~v831I~
extern int  despagesw;       //descending page print sw v5.3a      //~v831I~
extern int  realpage;				//real output page count    v5.8a//~v831I~
extern int  totpage;         //v4.1a total page count              //~v831I~
extern int pagerangectr;		//entry no of pagerange            //~v831I~
extern int pagerange[];                                            //~v831I~
extern long pageoutlen;          //output len      v5.8a           //~v831I~
extern char *Gcmdlineparms;      //set at xprint.c                 //~v9e4I~
//*********************************************************************//~v831I~
static int lastpage;          //last pageno                    v4.4a//~v831I~
static int printsw;           //at least 1 page printed sw v3.2add v3.7r//~v831I~
//static int header1len;          //v1.4rep                       v3.6rep//~v831I~//~v970R~
       int header1len;          //v1.4rep                       v3.6rep//~v970I~
static int header0fnw;      //header0 filename field space         //~v831I~
//static int page;               //v3.2rep v6.7r                     //~v831I~//~v97cR~
       int page;                                                   //~v97cI~
static long readline,readlineo;            //input line v6.7r      //~v831I~
static char header0wp[16];     //alignment work v4.7a              //~v831I~
//atic char header0w[MAXLINEWIDTH];     //alignment work v4.7a v6.7r//~v886R~
static char header0w[MAXESCCMD+MAXLINEWIDTH];     //alignment work v4.7a v6.7r//~v886I~
//static char header1[MAXLINEWIDTH];            //v5.1r v6.6rv6.7r   //~v831I~//~v970R~
       char header1[MAXLINEWIDTH];            //access from xplnxp //~v970I~
static UCHAR sprintfwk[16];                                        //~v831I~
static int  *codepage;    //char set ptr,default jdos dbcs v6.5a   //~v831I~
#define UNPC   '.'                                                 //~v846R~
//**japanese mode keisen(katakana)                                 //~v846I~
static unsigned char jisctlcodetbl[32]    //jis control code acceptable if txec mode for non ibm//~v846I~
      ={  0,KEI,KEI,KEI,KEI,KEI,KEI,  7,  8,TAB,CRLF, 11,FORMFEED, 13, 14, 15,//~v846I~
        KEI, 17, 18, 19, 20,KEI,KEI,KEI, 24,KEI,  26, 27,      28, 29, 30, 31};//~v846I~
static unsigned char jisctlcodetbl2[32]   //jis control code acceptable if txet mode for ESCP//~v846R~
      ={0x00,0x98,0x99,0x9a,0x9b,0x96,0x95,0x07,0x08,TAB ,CRLF,0x0b,FORMFEED,0x0d,0x0e,0x0f,//~v846R~
        0x8f,0x11,0x12,0x13,0x14,0x90,0x91,0x92,0x18,0x93,0x1a,0x1b,0x1c    ,0x1d,0x1e,0x1f};//~v846R~
//**english mode keisen(extended graphics)                         //~v846I~
static unsigned char jisctlcodetbl3[32]   //jis control code acceptable if txet mode for ESCP//~v846R~
      ={0x00,'ﾉ' ,'ｻ' ,'ﾈ' ,'ｼ' ,'ｺ' ,'ﾍ' ,0x07,0x08,TAB ,CRLF,0x0b,FORMFEED,0x0d,0x0e,0x0f,//~v846I~
        'ﾎ' ,0x11,0x12,0x13,0x14,'ﾊ' ,'ﾋ' ,'ｹ' ,0x18,'ﾌ' ,0x1a,0x1b,0x1c    ,0x1d,0x1e,0x1f};//~v846I~
static unsigned char jisctlcodetbl4[32]   //jis control code acceptable if txet mode for ESCP//~v90sR~
      ={0x00,'ﾚ' ,'ｿ' ,'ﾀ' ,'ﾙ' ,'ｳ' ,'ﾄ' ,0x07,0x08,TAB ,CRLF,0x0b,FORMFEED,0x0d,0x0e,0x0f,//~v90sR~
        'ﾅ' ,0x11,0x12,0x13,0x14,'ﾁ' ,'ﾂ' ,'ｴ' ,0x18,'ﾃ' ,0x1a,0x1b,0x1c    ,0x1d,0x1e,0x1f};//~v90sR~
//*********************************************************************//~v831I~
void header0edit(void);                                            //~v831R~
void printsubhdr(int Plinewidth);                                  //~v831I~
void datapline(void* area,int unit,int count,FILE* file);          //~v831I~
UCHAR keisenconv(UCHAR Pch);                                       //~v857I~
//void datapline_ucsebc(int Popt,UCHAR *Pmbdata,WUCS *Poutucs,int Plen,FILE* file);//~v955I~//~v995R~
void datapline_ucsebc(int Popt,UCHAR *Pmbdata,WUCS *Poutucs,int Plen,FILE* file,int Pbuffsz);//~v995I~
#ifdef GTKPRINT                                                    //~v97mI~
	void subhdredit_utf8(char *Phdr,int Plen,int Plinewidth);      //~v97mI~
#endif                                                             //~v97mI~
//**********************************************************************
//* main process (1 file print)
//**********************************************************************
void printfile()
{
  static char header1p[]="....+....1....+....2....+....3....+....4\
....+....5....+....6....+....7....+....8\
....+....9....+....0....+....1....+....2\
....+....3....+....4....+....5....+....6....+....7\
....+....8....+....9....+....0....+....1....+....2\
....+....3....+....4....+....5....+....6....+....7\
....+....8....+....9....+....0....+....1....+....2\
....+....3....+....4....+....5....+....6....+....7\
....+....8....+....9....+....0....+....1....+....2\
....+....3....+....4....+....5....+....6....+....7\
....+....8....+....9....+....0....+....1....+....2";//520          //~v886I~
                                                                   //~v886I~
static char header1w[]=" 0 . . .  4 . . .  8 . . .  C . . .   0 . . .  4 . . .  8 . . .  C . . .    \
0...4...8...C...0...4...8...C..."; //v6.7a
static char header1s[]=" 0  .  .  .  4  .  .  .  8  .  .  .  C  .  .  .    \
0...4...8...C...";					//v6.7a
//static char header1v[]="....+....1....+....2....+....3....+....4 //~v907R~
//....+....5....+....6....+....7....+....8....+....9....+....0....+....1....+....2//~v907R~
//....+....3....+....4....+....5";   //v6.7a                       //~v886R~
//*************
//code table  * 0:unprintable 1:printable 2:DBCS first byte
//*************
//DBCS code tbl            0 1 2 3 4 5 6 7 8 9 a b c d e f
  static int codetbl[256]={0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0, //"0x" v6.5r
                           1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,1, //"1x" v6.5r
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"2x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"3x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x"
                           0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"8x"
                           2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"9x"
                           0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ax"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"bx"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"cx"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"dx"
                           2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"ex"
                           2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0};//"fx" //v2.7add
//second byte chk tbl      0 1 2 3 4 5 6 7 8 9 a b c d e f
  static int codetb2[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x"
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x"
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"2x"
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"3x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"8x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"9x"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ax"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"bx"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"cx"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"dx"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ex"
                           1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};//"fx"//v6.3a
 static int codetblj[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x" JIS 1 byte table//~v789I~
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"2x" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"3x" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x" //~v789I~
                           0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"8x" //~v789I~
                           2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"9x" //~v789I~
                           0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ax" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"bx" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"cx" //~v789I~
                           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"dx" //~v789I~
                           2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"ex" //~v789I~
                           2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0};//"fx" //v2.7add//~v789I~
//SBCS code tbl            0 1 2 3 4 5 6 7 8 9 a b c d e f
  static int codetbls[256]={0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0, //"0x"
                            1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,1, //"1x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"2x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"3x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"8x"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"9x"
                            0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ax"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"bx"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"cx"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"dx"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"ex"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//"fx" //v6.5a
//ASCII code tbl          0 1 2 3 4 5 6 7 8 9 a b c d e f
  static int codetbla[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"2x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"3x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x"
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"8x"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"9x"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"ax"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"bx"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"cx"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"dx"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"ex"
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//"fx" //v6.5a

//EBCDIC katakana           0 1 2 3 4 5 6 7 8 9 a b c d e f        //~v891I~
 static int codetblek[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"2x"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"3x"//~v891I~
                            1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1, //"4x"  0x4a=cent//~v891R~
                            1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1, //"5x"//~v891R~
                            1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1, //"6x"  0x6a=splitted |//~v891I~
                            0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1, //"7x"//~v891I~
                            0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1, //"8x"//~v891I~
                            1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1, //"9x"//~v891I~
                            0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1, //"ax"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1, //"bx"//~v891R~
                            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"cx"//~v891I~
                            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"dx"//~v891I~
                            0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"ex" 0xe0=backslash//~v891R~
                            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0};//"fx"  0xfa=| ?//~v891I~
                                                                   //~v891I~
//EBCDIC english            0 1 2 3 4 5 6 7 8 9 a b c d e f        //~v891I~
 static int codetblee[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"2x"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"3x"//~v891I~
                            1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1, //"4x"//~v891I~
                            1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1, //"5x"//~v891I~
                            1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1, //"6x"//~v891I~
                            0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1, //"7x"//~v891I~
                            0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"8x"//~v891I~
                            0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"9x"//~v891I~
                            0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"ax"//~v891I~
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"bx"//~v891I~
                            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"cx"//~v891I~
                            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"dx"//~v891I~
                            0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0, //"ex" 0xe0=backslash//~v891R~
                            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0};//"fx"//~v891I~
                                                                   //~v891I~
//EBCDIC katakana trt       0123456789abcdef                       //~v891R~
//static UCHAR ebctrtk[256]= "................" //0x                 //~v91rR~//~v968R~
static UCHAR ebctrtk[257]= "................" //0x //for C4295 warning//~v968I~
                           "................" //1x                 //~v891I~
                           "................" //2x                 //~v891I~
                           "................" //3x                 //~v891I~
                           " ｡｢｣､･ｦｧｨｩ..<(+|"//"4x"  0x4a=cent(￠) //~v891R~
                           "&ｪｫｬｭｮｯ.ｰ.!$*);^"//"5x"  0x5f=not(￢)  //~v891R~
                           "-/.........,%_>?"//"6x"  0x6a=splitted |//~v891I~
                           ".........`:#@'=\""//"7x"               //~v891I~
                           ".ｱｲｳｴｵｶｷｸｹｺ.ｻｼｽｾ"//"8x"                //~v891I~
                           "ｿﾀﾁﾂﾃﾄﾅﾆﾇﾈﾉ..ﾊﾋﾌ"//"9x"                //~v891I~
                           ".~ﾍﾎﾏﾐﾑﾒﾓﾔﾕ.ﾖﾗﾘﾙ"//"ax"                //~v891I~
                           "..........ﾚﾛﾜﾝﾞﾟ"//"bx"                //~v891R~
                           "{ABCDEFGHI......"//"cx"                //~v891I~
                           "}JKLMNOPQR......"//"dx"                //~v891I~
                           "..STUVWXYZ......"//"ex"  0xe0=backslash//~v891R~
                           "0123456789......" ;//"fx" 0xfa=|?      //~v91rR~
                                                                   //~v891I~
//EBCDIC english  trt       0123456789abcdef                       //~v891R~
//static UCHAR ebctrte[256]= "................" //0x                 //~v91rR~//~v968R~
static UCHAR ebctrte[257]= "................" //0x //for C4295 warning//~v968I~
                           "................" //1x                 //~v891I~
                           "................" //2x                 //~v891I~
                           "................" //3x                 //~v891I~
                           " ...........<(+|"//"4x"  0x4a=cent(￠) //~v891I~
                           "&.........!$*);^"//"5x"  0x5f=not(￢)  //~v891I~
                           "-/.........,%_>?"//"6x"  0x6a=splitted |//~v891I~
                           ".........`:#@'=\""//"7x"               //~v891I~
                           ".abcdefghi......"//"8x"                //~v891I~
                           ".jklmnopqr......"//"9x"                //~v891I~
                           ".~stuvwxyz......"//"ax"                //~v891I~
                           "................"//"bx"                //~v891I~
                           "{ABCDEFGHI......"//"cx"                //~v891I~
                           "}JKLMNOPQR......"//"dx"                //~v891I~
                           "..STUVWXYZ......"//"ex"   0xe0=backslash//~v891R~
                           "0123456789......" ;//"fx" 0xfa=|?      //~v91rR~
                                                                   //~v891I~
                                                                   //~v891I~
//  static unsigned char jisctlcodetbl[32]    //jis control code acceptable if txec mode for non ibm//~v846R~
//      ={  0,KEI,KEI,KEI,KEI,KEI,KEI,  7,  8,TAB,CRLF, 11,FORMFEED, 13, 14, 15,//~v846R~
//        KEI, 17, 18, 19, 20,KEI,KEI,KEI, 24,KEI,  26, 27,      28, 29, 30, 31};//~v846R~
//  static char *textmode[4]={"TEXT","DUMP","SKIM","XDUMP"};//numonic id v2.8addv3.1repv6.5rv7.12r//~v96xR~
//static char *asciiid[4]={"DBCS","ASCII","SBCS","JIS"};//scii option id v3.1add v6.5r//~v891R~
//  static char *asciiid[5]={"DBCS","ASCII","SBCS","JIS","EBCDIC"};//scii option id//~v895R~//~v96xR~
//static int  *charset[4]={codetbl,codetbla,codetbls,codetblj};//codetbl ptr def v6.5a//~v891R~
  static int  *charset[5]={codetbl,codetbla,codetbls,codetblj,codetblek};//codetbl ptr def//~v895R~

  char buff[MAXLINEWIDTH];            //v2.7rep
#ifdef UTF8SUPP                                                    //~v928I~
  UCHAR dumpbuff[MAXLINEWIDTH*UTF8_MAXCHARSZMAX];        //original data buff for hex dump v6.7a//~v928I~
#else                                                              //~v928I~
  UCHAR dumpbuff[MAXLINEWIDTH];        //original data buff for hex dump v6.7a
#endif                                                             //~v928I~
  char trailer[MAXLINEWIDTH*2];       //v3.7a v6.7r
static  char spaceline[16]; //v3.5add       v3.6r(static)	v6.7r
  int intwk;                 //work int v6.7a
  int colomn;                //output line    v1.4rep v1.7rep
  int netcol;             //offset in input record v6.7a           //~v801R~
  int tabspace;           //space count by tab skip       v1.7add  //~v801R~
  int  i,j,ii;             //work v2.8add                       //~v747R~
//int  getcount=0;     //read char count v3.7a v6.7d
  int  readc;         //read char   v1.4add
  unsigned char c=0;    //read char   v1.4rep v4.3r
  unsigned char prevc=0;//previous read char   v4.3a v7.0r
  int contsw;             //multi line sw(line continue)
  int dbcssw;           //dbcs control sw                 v1.8add  //~v801R~
  int dbcssw2;          //dbcs on boundary of max colomn  v2.7add  //~v801R~
  int dumpbypass;         //continuous dump,char skip sw      v2.7del
  int chartype;           //id of printable/dbcs first byte   v2.7add
  long cunpcnt;          //continuous unprintable char count v2.4add v6.7r//~v801R~
  long cunpcnt_old;      //old unp cnt at 1byte before       v2.7add v6.7r//~v801R~
  long cprncnt;          //continuous printable char count   v2.7add v6.7r//~v801R~
  int spacelinelen;       //print line advancing count v3.5add
  long prnoffs;		//first printable chat offset on a line	v6.6a  //~v801R~
  long linemsg;                                                    //~v801I~
  int  prncol;			//first printable char colmn  on a line	v6.6a v7.0r//~v801R~
  struct tm* plocaltime;       //local time  940609a
  time_t stck;                 //stck value del 940609a
  int linewidth;       	//line width for header0 edit	v6.7a
//  int reccolomn;        //offset in the record v6.7a               //~v801R~//~v96fR~
  int dummybytesw;		//dbcs dummy byte char v6.7a	
  long filecolomn;     	//offset of cuurent hex char data v6.7a
  char *pc;				//v7.12a	
  int  openrc;         //open sub r.c                              //~v801I~
  int  vhexdatalinesw,vhexlinelen; //vhex 3 line mode              //~v91rR~
  char *vhexpc,vhexcontdelm=XECONTLINEDELM;                        //~v91rR~
  char *pcvname;                                                   //~v953I~
  int  splitchar2;                                                 //~v92bI~
//#ifdef DOS                                                       //~v78cR~
//unsigned int sjiskanji;			//sift jis kanji code          //~v78cR~
//unsigned int jiskanji;			//jis kanji code               //~v78cR~
//#endif                                                           //~v78cR~
#ifdef UTF8SUPP                                                    //~v925I~
    int ucs,utfopt,rescol,utf8strlen,utferr=0;                       //~v928R~//~v960R~
    char utf8str[8];                                               //~v928I~
#endif                                                             //~v925I~
#ifdef UTF8SUPP                                                    //~v940I~
    int vhexoutlen,vhexmaxlen;                                     //~v940R~
#endif                                                             //~v940I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
	int swebcfile;                                                 //~v941I~
    char editebcmode[32];                                          //~v941I~
    char edittabctr[32];                                           //~v953I~
#endif          //EBCDIC dbcs support                              //~v941I~
    int swforcecr=0;                                               //~v960I~
    int __reccolomnsv;                                             //~v96jM~
    int vhexprintlen;                                              //~v96rI~
    int vhexprintlen0;                                             //~v96vI~
    int swvlen0=0;                                                 //~v96tI~
	int eolprintnetcol=-1;                                         //~v96tI~
//*global variable init ***********************************************************
    UTRACEP("printfile dumpmode=%d,textmodevhexsw=%d,vhexdump=%d\n",dumpmode,textmodevhexsw,vhexdump);//~v97CR~
 if (Gcontpageno)       //input range and restart pageno specified //~v910I~
  page=Gcontpageno-1;                                              //~v910I~
 else                                                              //~v910I~
  page=0;				//v6.7a	
  Gpage2p=page+page;    //2p/form                                  //~v911I~
  pagesw=0;            //sw in the print page range v3.7a
  printsw=0;           //at least 1 page printed sw v3.7a
//printdumpfsw=1;		//printdump sub first sw v6.7a             //~v801R~
//puthexfsw=1;			//puthexline sub first sw v6.7a            //~v801R~
	skip1stff2=skip1stff;	//each stage,skip first page formfeed cmd opt//~v785R~
    if (despagesw)                                                 //~v855I~
    	skip1stff2=0;		//effective when put from desp         //~v855I~
//*********************************************************************
//strcpy(header0wp,"\f%");						// v5.1a v5.3d
//sprintf(header0wp+2,"%ds\n",max(maxcol,COLMAX1+LINENOSZ+1));	// v5.1a v5.3d
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
	swebcfile=UCBITCHK(swsw4,SW4EBCCFG);                           //~v941I~
 if (!xpebc_setupcp(0,charset,&codepage,&Gebctrt))                 //~v941I~
#else                                                              //~v941I~
    codepage=charset[asciimode];                   //v6.5a         //~v941I~
#endif          //EBCDIC dbcs support                              //~v941M~
 {                                                                 //~v941M~
  if (asciimode==4)		//EBCDIC codepage                          //~v895I~
  {                                                                //~v893I~
    Gebctrt=ebctrtk;             //EBCDIC TRT                      //~v891I~
	if (Gebcdictype==2) 	//EBCDIC english                       //~v891R~
  	{                                                              //~v891I~
  		codepage=codetblee;                                        //~v891I~
        Gebctrt=ebctrte;                                           //~v891I~
  	}                                                              //~v891I~
  }                                                                //~v893I~
  	if (Gptrtfnm)      //trt specified                             //~v895I~
		setupcp(codepage,&Gebctrt);	//update codepage,trt tbl setup from file//~v895R~
 }                                                                 //~v941I~
//strcpy(header0wp,"%");						//for %nns v5.3a		//v6.7d
//sprintf(header0wp+1,"%ds\n",max(maxcol,COLMAX1+LINENOSZ+1));//v5.3a 	//v6.7d
  sprintf(sprintfwk,"%%%ds",LINENOSZ);		//v6.6a v6.7r
//******** header1 for hexdump
//  if (hexdump)                                                   //~v96fR~
    if (hexdump||vhexdump>1)                                       //~v96fI~
	{
//		if (recordsz)	//record mode                              //~v96eR~
  		if (vhexdump>1)  //record mode or recfm=V              //~v96eI~//~v96fR~
		{
		  	sprintf(header1,sprintfwk,"LINE");
		  	sprintf(linespwk,"%%%dld",LINENOSZ);
          if (recordsz && recordsz+LINENOSZ+1<maxcol)              //~v96fR~
		    header1len=recordsz;                                   //~v96fR~
          else                                                     //~v96fI~
		    header1len=dumpwidth;
		    Linecharpos=LINENOSZ+1;
		    Linehexdpos=LINENOSZ+1;
//  		memcpy(header1+LINENOSZ+1,header1v,(UINT)header1len);//v7.0r//~v886R~
    		memcpy(header1+LINENOSZ+1,header1p,(UINT)header1len);//v7.0r//~v886I~
//  		linewidth=Linecharpos+dumpwidth;                       //~v96jR~
            linewidth=maxcol;// if fix lrecl<print widh//~v96jI~   //~v96fR~
		}
		else//not record mode
		{
          if (recordsz||vfmt)                                      //~v96rI~
          {                                                        //~v96rI~
		  	sprintf(header1,sprintfwk,"LINE");                     //~v96rI~
		  	sprintf(linespwk,"%%%dld",LINENOSZ);                   //~v96rI~
          }                                                        //~v96rI~
          else                                                     //~v96rI~
          {                                                        //~v96rI~
		  	sprintf(header1,sprintfwk,"OFFS");
		  	sprintf(linespwk,"%%0%dlX",LINENOSZ);
          }                                                        //~v96rI~
			if (dumpwidth==32)
			{
			    header1len=(INT)strlen(header1w);//v7.0r
			    Linecharpos=LINECHARPOSW;
			    Linehexdpos=LINEHEXPOSW;
				memcpy(header1+LINENOSZ+1,header1w,(UINT)header1len); //v7.0r
			}
			else
			{
			    header1len=(INT)strlen(header1s);	//v7.0r
			    Linecharpos=LINECHARPOSS;
			    Linehexdpos=LINEHEXPOSS;
				memcpy(header1+LINENOSZ+1,header1s,(UINT)header1len);//v7.0r
			}
			linewidth=Linecharpos+dumpwidth+1;
			header1[Linecharpos-1]=CHARDELM;
			header1[Linecharpos+dumpwidth]=CHARDELM;
			header1len++;
		}
		header1len+=LINENOSZ+1;
	}
//******** header1 for hexdump;end
	else	//v6.7a
	{	//v6.7a
	  if (dumpmode==2)		//v6.6a
	  {//v6.7a	
		sprintf(header1,sprintfwk,"OFFS");	//v6.6a v6.7r
	  	sprintf(linespwk,"%%0%dlX",LINENOSZ); //v6.7a
	  }//v6.7a
	  else	
	  {//v6.7a	
		sprintf(header1,sprintfwk,"LINE");	//v6.6a v6.7r
	  	sprintf(linespwk,"%%%dld",LINENOSZ);//v6.7a v6.7r
	  }//v6.7a
//    memcpy(header1+LINENOSZ+1,header1p,sizeof(header1p));	//copy patern v5.1av6.6r//~v887R~
      memcpy(header1+LINENOSZ+1,header1p,sizeof(header1)-LINENOSZ-1);	//copy patern v5.1av6.6r//~v887I~
     if (recordsz && recordsz+LINENOSZ+1<maxcol)                   //~v96fI~
	   header1len=recordsz+LINENOSZ+1;                             //~v96fR~
     else                                                          //~v96fI~
//    header1len=maxcol; //v6.7a                                   //~v97GR~
      header1len=maxcol-Gdatalinenosz; //v6.7a                     //~v97GI~
      linewidth=maxcol;   //line width by -cxx or default col by max line width//~v96fI~//~v96jR~//~v96fR~
	}	//v6.7a

	header1[LINENOSZ]=ADDRDELM;    //v6.7a
    if (Gdatalinenosz)                                             //~v97FM~
    {                                                              //~v97FM~
//      memmove(header1+Gdatalinenosz,header1,header1len);         //~v97FM~//~v97GR~//~v997R~
        memmove(header1+Gdatalinenosz,header1,(size_t)header1len); //~v997I~
        memset(header1,' ',(size_t)Gdatalinenosz);                 //~v9j2R~
        header1len+=Gdatalinenosz;                                 //~v97FM~
    }                                                              //~v97FM~
	header1[header1len++]=CRLF;    //v2.7rep v6.7r
    UTRACED("header1",header1,header1len);                         //~v97GR~
//  esccmdsetup(linewidth-LINENOSZ-1,prntyp,cmdfile);	//esccmd setup v6.7a//~v914R~
//  if (lineprefixsw)		//v7.12a                               //~v911R~
//    	sprintf(header0wp,"%%%ds\n",(i=linewidth));//v5.3a 	//v6.7a//~v911R~
//  else					//v7.12a                               //~v911R~
//    	sprintf(header0wp,"%%%ds\n",(i=linewidth-LINENOSZ-1));//v7.12a//~v911R~
    if (lineprefixsw)       //v7.12a                               //~v911R~
        i=linewidth;//v5.3a     //v6.7a                            //~v911R~
    else                    //v7.12a                               //~v911R~
        i=linewidth-LINENOSZ-1;//v7.12a                            //~v911R~
    UTRACEP("%s:lineprefixsw=%d,linewidth=%d,i=%d\n",UTT,lineprefixsw,linewidth,i);//~v9j1I~
//#ifndef SSS                                                      //+v9j1R~
//    ii=i;                                                        //+v9j1R~
//#endif                                                           //+v9j1R~
    if (UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))                        //~v911R~
		i=get2pwidth(i);                                           //~v911I~
	sprintf(header0wp,"%%%ds\n",i);//v7.12a                        //~v911I~
//#ifdef SSS   //lineprefixsw is not considered                    //+v9j1R~
    ii=linewidth-LINENOSZ-1;                                       //~v914I~
//#endif                                                           //+v9j1R~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
    if (prntyp==PRINTER_WIN)                                       //~v914I~
    	if (UCBITCHK(swsw3,SW3FORM2P))                             //~v914R~
        	ii=i;           //2 part width                         //~v914R~
#endif                                                             //~v914I~
    esccmdsetup(ii,prntyp,cmdfile);	//esccmd setup v6.7a           //~v914I~
//**********                                                       //~v801M~
//printf("\nheder0len=%d,header0wp=%s\n,header0=%s",i,header0wp,header0);//~v803R~
//printf("i=%d,strlen=%d\n",i,strlen(header0));                    //~v803R~
	header0fnw=i;		//parm to header0edit                      //~v801I~
    header0edit();  //for long filename over linwidth              //~v801I~
//**********                                                       //~v801I~
  sprintf(sprintfwk,"%%%ds%%c\n",LINENOSZ);		//v6.7a
  sprintf(spaceline,sprintfwk," ",ADDRDELM);	//v6.7a	
  spacelinelen=(int)strlen(spaceline);   //length when single space v3.5add
  for (i=0;i<lineskip;i++) //v3.5add
    spaceline[spacelinelen++]='\n';   //v3.5 add by space parameter

  line=maxline;//v2.9add first page eject
do {                                                               //~v801R~
//until no file in dir(for conjunct mode,read next file)           //~v801I~
  rmax=rcount=RBUFFSZ;		//for hex print                        //~v801I~
  readline=1;
  printdumpfsw=1;		//printdump sub first sw v6.7a  for hexdump//~v801I~
  puthexfsw=1;			//puthexline sub first sw v6.7a for hexdump//~v801I~
  dbcssw=0;           //dbcs control sw                 v1.8add    //~v801I~
  dbcssw2=0;          //dbcs on boundary of max colomn  v2.7add    //~v801I~
  cunpcnt=0;          //continuous unprintable char count v2.4add v6.7r//~v801I~
  cunpcnt_old=0;      //old unp cnt at 1byte before       v2.7add v6.7r//~v801I~
  cprncnt=0;          //continuous printable char count   v2.7add v6.7r//~v801I~
  prnoffs=0;		//first printable chat offset on a line	v6.6a  //~v801I~
  reccolomn=0;		//offset in the record v6.7a	               //~v801I~
  prncol=0;			//first printable char colmn  on a line	v6.6a v7.0r//~v801I~
  prevc=0;			//previous read char   v4.3a v7.0r             //~v801I~
  netcol=0;             //offset in input record v6.7a             //~v801I~
  tabspace=0;           //space count by tab skip       v1.7add    //~v801I~
  contsw=0;
  colomn=LINENOSZ+1;   //data pos                  //v2.1rep
  XPsetEQ_(Gcolumnucs,colomn)        //index on ucs tbl            //~v928R~
  readc=0;                //v1.4add
  if (UCBITCHK(swsw3,SW3CONJUNCT))                                 //~v801R~
  {                                                                //~v801I~
    header0edit();  //for long filename over linwidth              //~v801I~
#ifdef GTKPRINT                                                    //~v97mI~
    if (Gxpotheropt & GOO_HEADERUCS)                               //~v97mI~
//  	subhdredit_utf8(headersutf8,strlen(headersutf8),linewidth);	//prepare ucs line//~v97mI~//~v997R~
    	subhdredit_utf8(headersutf8,(int)strlen(headersutf8),linewidth);	//prepare ucs line//~v997I~
#endif                                                             //~v97mI~
  	printsubhdr(linewidth);                                        //~v801R~
  }                                                                //~v801I~
  while(readc!=EOF)     //until eof v1.4rep
  {
	filecolomn=0; //will reset later by readcount                  //~v965I~
    ucs=readc;                                                     //~v965I~
    utf8strlen=0;                                                  //~v965I~
    splitchar2=readc;                                              //~v965I~
    if (tabspace)         //in previous tab skip range  v1.7add
    {                                                // v1.7add
      chartype=1;         //printable                   v1.7add
      readc=' ';          //padd with space             v1.7add
	  if (UCBITCHK(swsw5,SW5TABONPRM))  //0x10	//tabon parameter specified//~v9e0I~
      	readc=getTabonAltch(TAB,1);                                //~v9e0R~
      ucs=readc;                                                   //~v9e1I~
      tabspace--;                                    // v1.7add
	  dummybytesw=0;                                               //~v965I~
    }                                                // v1.7add
    else//tab not efective                           // v1.7add
    {                                                //v2.7add
//*************************
//* DBCS control          *
//*************************
#ifdef UTF8SUPP                                                    //~v925I~
     if (XPUTF8MODE())                                             //~v925I~
     {                                                             //~v925I~
     	utferr=0;                                                  //~v928I~
	  	dummybytesw=(dbcssw2==4); //dummy byte			//v6.7a    //~v928I~
        if (dummybytesw)	//next line top is '.' when dbcs split at prev line eol//~v928I~
        {	                                                       //~v928I~
        	chartype=1;                                            //~v928I~
            readc='.';                                             //~v928I~
            dbcssw2=0;                                             //~v928I~
        }                                                          //~v928I~
        else                                                       //~v928I~
        {                                                          //~v928I~
//          if (recordsz)  		//v6.7a                            //~v928R~//~v96tR~
//          {                                                      //~v928I~//~v96tR~
//              utfopt=XPUTFO_BIN;// binarymode                    //~v928R~//~v96tR~
//              rescol=recordsz-reccolomn;//cut just by reclen because residual len is not 1 byte as like as DBCS(SJIS)//~v928R~//~v96tR~
//          }                                                      //~v928I~//~v96tR~
//          else                                                   //~v928I~//~v96tR~
            if (hexdump)  		//v6.7a                            //~v928I~
            {                                                      //~v928I~
                utfopt=XPUTFO_BIN;// binarymode                    //~v928I~
                rescol=dumpwidth-netcol;                           //~v928I~
            }                                                      //~v928I~
            else                                                   //~v928I~
            {                                                      //~v928I~
//            if (textmodevhexsw)                                  //~v92cR~//~v96tR~
              if (textmodevhexsw||vhexdump>1)                      //~v96tI~
              {                                                    //~v92cR~
                utfopt=XPUTFO_BIN;//split utf string by the column limit//~v92cR~
                rescol=maxcol-LINENOSZ-1-netcol;                   //~v92cR~
              }                                                    //~v92cR~
              else                                                 //~v92cR~
              {                                                    //~v92cR~
                utfopt=0;                                          //~v928I~
                rescol=maxcol-colomn;                              //~v928R~
              }                                                    //~v92cR~
            }                                                      //~v928I~
            readc=xputf_getinput(utfopt,rescol,utf8str,&utf8strlen,&ucs,&chartype,&dbcssw2,&filecolomn);//all byte of utf str,readc:top byte//~v928R~
                   //chartype: 0:unprintable,1:ascii,2:dbcs,3:sbcs //~v928I~
                   //dbcssw2:4:dbcs split,1:not split dbcs         //~v928I~
            utferr=(chartype==0 && readc!=EOF);	//not sbcs unprintable//~v928I~
            swforcecr=0;    //fold to next line                    //~v960I~
            swvlen0=0;    //null line                              //~v96tI~
            if (recordsz || vfmt)                                  //~v96tI~
            {                                                      //~v96tI~
            	if (!filecolomn)                                   //~v96tI~
                {                                                  //~v96tI~
	                swforcecr=2;    //EOL                          //~v96tR~
                    if (!utf8strlen) //null line                   //~v96tR~
                    	swvlen0=1;                                 //~v96tI~
                }                                                  //~v96tI~
                UTRACEP("filecol=%d,swforcecr=%d,utf8strlen=%d,swvlen0=%d\n",filecolomn,swforcecr,utf8strlen,swvlen0);//~v97vI~
            }                                                      //~v96tI~
            if (chartype==6)       //split by linewidth            //~v96tI~
            {                                                      //~v96tI~
            	chartype=1;       //print space                    //~v96tI~
                swforcecr=1;    //fold to next line                //~v96tI~
            }                                                      //~v96tI~
            else                                                   //~v96tI~
            if (chartype==5)                                       //~v960I~
            {                                                      //~v960I~
            	chartype=1;                                        //~v960I~
                swforcecr=1;    //fold to next line                //~v960I~
            }                                                      //~v960I~
            else                                                   //~v960I~
            if (chartype==7)     //hhex dump split utf8 code       //~v97qI~
            {                                                      //~v97qI~
            	chartype=0;                                        //~v97qI~
                swforcecr=2;    //EOL after set split data         //~v97qR~
            }                                                      //~v97qI~
            else                                                   //~v97qI~
        	if (chartype==1)	//ascii                            //~v928I~
          		chartype=codepage[readc];	//printable chk       //~v928I~//~v941R~
            if (dbcssw2)                                           //~v928I~
            	dbcssw=1;                                          //~v928I~
            else                                                   //~v928I~
            	dbcssw=0;                                          //~v928I~
        }                                                          //~v928I~
     }                                                             //~v925I~
     else                                                          //~v925I~
     {                                                             //~v925I~
#endif                                                             //~v925I~
      chartype=0;                                                  //~v965I~
	  dummybytesw=(dbcssw2==4); //dummy byte			//v6.7a
      if (dbcssw)          //expected dbcs second byte          //v1.8add
      {                                                       //v2.7add
		filecolomn=readcount;		//v6.7a
        if(dbcssw!=EOF)
          readc=dbcssw-1;    //pre-read second byte        //v2.7add
        else                                                       //~v894R~
          readc=EOF;                                               //~v894R~
        switch (dbcssw2)      //v2.7add
        {
        case 1:         //2nd byte err                        //v2.7add
          chartype=0;        //force unprintable              //v2.7add
          dbcssw=0;          //next may start dbcs            //v1.8add
          dbcssw2=5;       //next check                       //v2.7add
          break;                                              //v2.7add
        case 2:         //on the colom limit                  //v2.7add
          chartype=1;        //force printable                //v2.7add
          splitchar2=readc;   //set to dumpbuff when dummybytesw on//~v92bI~
          dbcssw='.'+1;         //next return '.'             //v2.7add
          dbcssw2=4;       //next goto else logic             //v2.7add
          break;                                              //v2.7add
        case 3:         //in the line midpoint                //v2.7add
        case 4:         //in the line midpoint                //v2.7add
          chartype=1;        //force printable                //v2.7add
          dbcssw=0;          //next may start dbcs            //v1.8add
          dbcssw2=0;       //normal colomn limit              //v2.7add
          break;                                              //v2.7add
        }//switch by dbcssw2                                  //v2.7add
      }//dbcssw!=0                                            //v2.7add
      else
        dbcssw2=6;               //fgetc id                   //v2.7add
      
      if (dbcssw2>4)       //not dbcs or dbcs second byte err   //v2.7add
      {                                                         //v2.7add
        if (dbcssw2!=5)//dbcs second byte err                   //v2.7add
        {                      //v3.7a
          readc=getinput();		 //v1.4rep		rv4.2
//        getcount++;         //v3.7a v6.7d
		  filecolomn=readcount;	//v6.7a	
        }                      //v3.7a
        dbcssw2=0;                                              //v2.7add

        if (readc==EOF)                 //v2.7add
          chartype=0;                   //treate as unprintable v2.7add
        else                            //v2.7add
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
		 if (swebcfile)                                            //~v941I~
          chartype=Gebcctype;                                      //~v941I~
         else                                                      //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
          chartype=codepage[readc];      //v2.7add v6.5r

        if (chartype==2)			//record dump v6.7a
        {                                                          //~v96eI~
			if (vfmt && reccolomn>=recordszV0-1)	//last byte of record v6.7a//~v96eR~
				chartype=0;			//unprintable v6.7a            //~v96eI~
            else                                                   //~v96eI~
			if (reccolomn==recordsz-1)	//last byte of record v6.7a
				chartype=0;			//unprintable v6.7a
        }                                                          //~v96eI~
          if (chartype==2)//dbcs first byte             //v2.7add
          {                         //dbcs start                  //v1.8add
            dbcssw=getinput();    //read second byte  //v2.7add rv4.2
//          getcount++;            //v3.7a v6.7d
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
            if (!swebcfile                                         //~v941R~
            &&  (!codetb2[dbcssw]   //invalid second byte v6.3a    //~v941I~
                 ||  dbcssw==EOF)       //invalid second byte//v2.7add//~v941I~
            )                                                      //~v941I~
#else                                                              //~v941I~
            if (!codetb2[dbcssw]   //invalid second byte v6.3a
            ||  dbcssw==EOF)       //invalid second byte//v2.7add
#endif          //EBCDIC dbcs support                              //~v941I~
            {                                                   //v2.7add
              if (dbcssw!=EOF)        //v2.7add
                dbcssw++;             //second byte,next return //v2.7add
              chartype=0;             //force nonprintable      //v2.7add
              dbcssw2=1;           //force 2nd byte chk         //v2.7add
            }//invalid second byte                              //v2.7add
            else                     //valid DBCS second byte   //v2.7add
            {                                                      //~v78aI~
//#ifdef DOS                                                       //~v78cR~
//              if (prntyp==PRINTER_ESCP)	//ESCP                 //~v78cR~
//              {                                                  //~v78cR~
//              printf("readc=%02x,dbcssw=%02x\n",readc,dbcssw);   //~v78aR~
//              	sjiskanji=(((unsigned int)readc<<8)+(unsigned int)dbcssw);//~v78cR~
//              	jiskanji=jmstojis(sjiskanji);                  //~v78cR~
//              	readc=jiskanji>>8;		//jis kanji first byte //~v78cR~
//              	dbcssw=(jiskanji&255);  //jis kanji 2nd byte   //~v78cR~
//              printf("ms=%04x,jis=%04x,readc=%02x,dbcssw=%02x\n",sjiskanji,jiskanji,readc,dbcssw);//~v78aR~
//              }                                                  //~v78cR~
//#endif                                                           //~v78cR~
				if (UCBITCHK(swsw5,SW5TABONPRM))  //0x10	//tabon parameter specified//~v9e0I~
                {                                                  //~v9e0I~
                    if ((!swebcfile||(swebcfile && (swsw5 & SW5NOBYUCS))) //locale file or ebc by /TU(ebc by not ucs)//~v9e0R~
                    && !XPUTF8MODE()                               //~v9e0I~
					)                                              //~v9e0I~
                    {                                              //~v9e0I~
                        if ((readc<<8|dbcssw)==DBCSSPACE_SJIS)     //~v9e0R~
                        {                                          //~v9e0R~
                            int altch;                             //~v9e0R~
                            altch=getTabonAltch(0,0);     //get dbcsspace altch//~v9e0R~
                            readc=altch>>8;               //1st byte//~v9e0R~
                            dbcssw=altch&255;             //2nd byte//~v9e0R~
                        }                                          //~v9e0R~
                    }                                              //~v9e0I~
                }                                                  //~v9e0I~
              if (colomn==(maxcol-1)) //on the line boundary        //v1.8add
              {                       //set complete dbcs char      //v1.8add
                dbcssw++;           //next time return char save //v2.7add
                dbcssw2=2;          //2 time next return '.' id  //v2.7add
              }                   //set complete dbcs char      //v1.8add
              else          //in the line width      //v1.8add
              { //v2.7add
                dbcssw++;      //next time return char          //v2.7add
                dbcssw2=3;     //2nd byte printable         //v2.7add
              }//in the middle //v2.7add
            }//valid dbcs 2nd byte of shift jis                    //~v78aI~
          }//dbcs first byte                       //v1.8add
      }//dbcssw==0                                            //v1.8add
#ifdef UTF8SUPP                                                    //~v925I~
     }  //!utf8                                                    //~v925I~
#endif                                                             //~v925I~
    }//tab not efective                                       //v2.7add

    c=(unsigned char)readc;
//  UTRACEP("readc=%x,colomn=%d\n",readc,colomn);                  //~v97GR~
//  if (Gebcdictype)        //EBCDIC  or file codepage             //~v893R~
    if (Gebctrt)        //EBCDIC  or file codepage                 //~v893R~
        c=Gebctrt[c];      //translate(kill tab/crlf/formfeed etc) //~v891R~
//repl form feed by parm specified                                 //~v765I~
    if (c==FORMFEED)                                               //~v765I~
    {                                                              //~v97vI~
        UTRACEP("formfeed ffrepl=%d\n",ffrepl);                    //~v97vI~
        if (ffrepl!=-1) //repl char specified                      //~v765I~
		    c=(unsigned char)ffrepl;                               //~v765I~
        else                                                       //~v97CI~
        if (swebcfile)                                             //~v97CI~
            c='.';                                                 //~v97CI~
    }                                                              //~v97vI~

    dumpbypass=0;                //skip over 3 byte unprintable v2.7add
    if (dumpmode)                     //dump  mode       v2.0add
    {                                                   //v2.4add
	  if (!nocrlfsw)		//not no chk	v6.7a
	  {//v6.7a	
	      if (c==CRLF 
		  &&  prevc==CR)		//0x0d for binary mode read v4.3r v6.9r
//   	  && (cprncnt>=minprnc                           //v2.8rep v6.6d
//     	  ||!cunpcnt_old))  //\n after minprnc byte printable  //v2.8rep v6.6d
//dv6.9	  && (cunpcnt==1	      //0d after printable v6.6a
//dv6.9   ||dumpmode!=2))	      //or not skimmode v6.6a
	  		{						//v4.3a
#ifdef EEE                                                         //~v928I~
				colomn--;			//drop already printed 0x0a	v4.3a
#else                                                              //~v928I~
             	XPsetDECa(colomn,Gcolumnucs);                      //~v928I~
#endif                                                             //~v928I~
        		chartype=1;         //accept \n 
	  		}						//v4.3a	
	      if (c==CRLF                                              //~v897I~
		  &&  prevc!=CR)		//0x0d for binary mode read v4.3r v6.9r//~v897I~
        		chartype=1;         //accept \n                    //~v897I~
	  		prevc=c;               //v4.3a
//	  }//chk crlf modev6.7a		//v6.9d

	      if (c==TAB && tabskip //tabskip parameter!=0
    	  && (cprncnt>=minprnc                           //v2.8rep
      	  ||!cunpcnt_old))  //\t after minprnc byte printable  //v2.8rep
        	chartype=1;         //accept \t 
  	  }//chtk crlf modev6.7a		//v6.9a
      if (c==TAB)   //chartype=1 by Scodepage,but protext expand if dumpmode//~v96jR~
        chartype=0;                                                //~v96jI~
//*************************
//* unprintable compress  *
//*************************
      if(!chartype)                     //unprintable char   v2.7add
      {                                                      //v2.4add
        c='.';                        //replace by '.'   v2.0add
	    if (dumpmode==2)              //compress mode         v2.7add
    	{                             //v2.7add
          if (cprncnt==2              //2byte printable       
          &&  cunpcnt_old             //printable after unprintable
          &&  minprnc==2              //2 byte minimum string 
          &&  colomn>LINENOSZ+2		 //already 2 byte set v6.7r
          &&  codepage[(int)buff[colomn-2]]==2)//DBCS   //v2.8add v6.5r v6.7r//~v907R~
            i=3;                      //del 1 DBCS(2byte)v2.8add
          else                        //v2.8add
            i=minprnc;                //v2.8add

          if (cprncnt                 //printable before unprintable
          &&  cunpcnt_old             //printable after unprintable
          &&  cprncnt<i)              //under minimum string
          {                             //range under minprnc v2.8add
			if (cprncnt<=colomn-LINENOSZ-1)		//in the same line v6.7a
			{							//v6.7a
				j=(int)cprncnt;			//v6.7a
	            colomn-=j;			   //back to first printable v2.8add v6.7r
				if (colomn==prncol)			//first print char v6.6a
					prnoffs=0;				//no printable char detected id v6.6a
        	    cunpcnt=cunpcnt_old;        //continue from prev unp v2.8add
			}							//v6.7a
			else						//v6.7a
			{							//v6.7a
				j=colomn-LINENOSZ-1;	//del only current line v6.7a
				colomn=LINENOSZ+1;		//v6.7a
				cunpcnt=0;				//new start 3 dot count //v6.7a
				prnoffs=0;				//reset printable start col v6.7a
			}							//v6.7a
            for (i=0;i<j;i++)    //reset minprnc range v2.8add v6.7r
            {                           //v2.8add
              cunpcnt++;                //v2.8add
              if (cunpcnt<=3)         //print only 3 byte '.' v2.8add
              {                       //v2.8add
//              if (colomn>=LINENOSZ+1) //already set in buff //v2.8add v6.7d
                  buff[colomn]='.';     //reset printable v2.8add
	              colomn++;            
              }                       //v2.8add
            }                         //v2.8add
          }//under minprnc            //v2.8add

          if (++cunpcnt>3)               //max continuas print //v2.4add
            dumpbypass=1;                //skip sw             //v2.7add
        }//compress dump              //v2.7add
      }//unprintable char                                   //v2.4add
      else //printable char
      {                                  //v2.7add
        if (cunpcnt)                     //first prn after unp v2.8rep//v2.7add
          cunpcnt_old=cunpcnt;//save for n byte printable //v2.7add
        cunpcnt=0;                      //break cotinuas cnt //v2.4add
		if (!prnoffs)					//not detected first v6.6a
		{//v6.6a
			prnoffs=filecolomn;			//first printable of a line v6.6a
			prncol=colomn;				//that colomn to chk repl by . v6.6a
		}//v6.6a
      }                                  //v2.7add 

      if (cunpcnt) //unprintable                          //v2.7add
        cprncnt=0;             //reset continuous count   //v2.7add
      else                     //count continuous count   //v2.7add
        ++cprncnt;             //count continuous count   //v2.7add
    }//dump mode                     //v2.4add
    else     //!dumpmode                                           //~v78bI~
    {//!dumpmode                                                   //~v97vI~
//  {                                                              //~v896R~
//    {                                                            //~v846R~
//        if (c<0x20)     //control char                           //~v846R~
//            if (prntyp!=PRINTER_IBM)    //not IBM                //~v846R~
//                c=jisctlcodetbl[c];     //change to printable    //~v846R~
//    }//dumpmode or else                                          //~v846R~

//        if (c==CRLF         //current 0x0a                       //~v896R~
//        &&  prevc==CR)      //0x0d for binary mode read          //~v896R~
//        {                                                        //~v896R~
//            colomn--;       //drop already printed 0x0a v4.3a    //~v896R~
//            chartype=1;                                          //~v896R~
//        }                                                        //~v896R~
//        prevc=c;            //for next 0d+0a chk                 //~v896R~
	  	if (nocrlfsw //true when recordmode and vfmt               //~v97vI~
      	&&  (recordsz||vfmt)                                       //~v97vI~
      	)                                                          //~v97vI~
	  	{                                                          //~v97vI~
	    	if (c==CRLF||c==CR)                                    //~v97vR~
            {                                                      //~v97vI~
		        c='.';                                             //~v97vI~
        		chartype=0;         //unprintable                  //~v97vI~
            }                                                      //~v97vI~
  	  	}//chtk crlf mode                                          //~v97vI~
    if (c==TAB)                                       //v1.7add v2.7rep
    {                                                    //v1.7add
     if (textmodevhexsw)                                           //~v97DI~
        c='.';                                                     //~v97DI~
     else                                                          //~v97DI~
     if (recordsz||vfmt)                                           //~v96DR~
        c='.';                                                     //~v96DR~
     else                                                          //~v96DI~
     {                                                             //~v96DI~
      if (!tabskip)  //ignore tab under not dump mode    //v2.7add
        continue;    //read next                         //v2.7add

      tabspace=((colomn-LINENOSZ-1)/tabskip+1)*tabskip+LINENOSZ-colomn;
                                  //v1.7add v2.1rep
                                                                   //~v9e0I~
      c=' ';                                             //v1.7add
	  if (UCBITCHK(swsw5,SW5TABONPRM))  //0x10	//tabon parameter specified//~v9e0I~
      	c=(unsigned char)getTabonAltch(TAB,0);                     //~v9e0I~
     }                                                             //~v96DI~
    }                                                    //v1.7add
    }//!dumpmode                                                   //~v97vI~
//  }//not dump mode                                     //v1.7add //~v896R~
#ifdef UTF8SUPP                                                    //~v92cI~
    if (XPUTF8MODE() && utferr)                                    //~v92cI~
    	c='.';		//print also when textmode                     //~v92cR~
#endif                                                             //~v92cI~

    if (dumpbypass)                //skip dump      //v2.7add
      if (readc!=EOF)              //not eof        //v2.7add
        continue;                    //skip print     //v2.7add     

    buff[colomn]=c;
//  UTRACED("buff",buff,colomn+1);                                 //~v97GR~
#ifdef UTF8SUPP                                                    //~v928I~
	if (XPUTF8MODE())                                              //~v928I~
    {                                                              //~v928I~
	    if (!Geolprintcol)	//start of eolprint part set by utf_getinput()//~v96tI~
        	eolprintnetcol=-1;                                     //~v96tI~
        else                                                       //~v96tI~
	    if (Geolprintcol==1)	//start of eolprint part set by utf_getinput()//~v96tI~
        	eolprintnetcol=netcol;                                 //~v96tI~
//    if (!swforcecr)    //fold to next line                       //~v960R~
      {                                                            //~v960I~
      	if (swvlen0)	//Vlength=0                                //~v96tR~
        	;	                                                   //~v96tI~
        else                                                       //~v96tI~
    	if (c!=readc||dummybytesw)	//tab or unprintable replace print char//~v928R~
		    Gbuffucs[Gcolumnucs++]=c;                              //~v928R~
        else                                                       //~v928I~
        {                                                          //~v928I~
//    	  if ((textmodevhexsw && c==FORMFEED))                     //~v92cI~//~v96tR~
      	  if (((textmodevhexsw||vhexdump>1) && c==FORMFEED))       //~v96tI~
		    Gbuffucs[Gcolumnucs++]='.';                            //~v92cI~
          else                                                     //~v92cI~
          {                                                        //~v9e0I~
           if (ucs==DBCSSPACE_UCS //   0x3000                      //~v9e0R~
		   &&  UCBITCHK(swsw5,SW5TABONPRM)   //0x10	//tabon parameter specified//~v9e0R~
           )                                                       //~v9e0I~
           {                                                       //~v9e0I~
            int altch;                                             //~v9e0M~
            altch=getTabonAltch(0,0);     //get dbcsspace altch    //~v9e0I~
		    Gbuffucs[Gcolumnucs++]=altch;                          //~v9e0I~
           }                                                       //~v9e0I~
           else                                                    //~v9e0I~
		    Gbuffucs[Gcolumnucs++]=ucs;                            //~v928R~
          }                                                        //~v9e0I~
        	if (dbcssw)                                            //~v928I~
			    buff[++colomn]=c;                                  //~v928I~
        }                                                          //~v928I~
      } //force CR                                                 //~v928I~//~v960R~
//    UTRACED("utf8 buff",buff,colomn);                            //~v97vR~//~v97GR~
//    UTRACED("Gbuffucs",Gbuffucs,Gcolumnucs*WUCSSZ);              //~v97GR~
    }                                                              //~v928I~
#endif                                                             //~v928I~
  if (!(vfmt && !recordszV))	//!(recfm=V and lrecl=0)           //~v96eI~
  {                                                                //~v96eI~
    colomn++;
	if (hexdump			//v6.7a
    ||  textmodevhexsw                                             //~v92bI~
    ||  vfmt                                                       //~v96eI~
	||  recordsz)		//v7.21a
	 	if (!dummybytesw)	//dbcs dummy byte char	//v6.7a
		{											//v6.7a
#ifdef UTF8SUPP                                                    //~v928I~
		 if (XPUTF8MODE())                                         //~v928I~
         {                                                         //~v928I~
//        if (!swforcecr)    //fold to next line                   //~v960I~//~v96tR~
          if (swforcecr!=1)    //not fold to nextline or  EOL fold //~v96tR~
          {                                                        //~v960I~
			memcpy(dumpbuff+netcol,utf8str,(UINT)utf8strlen);	//original data for hex dump v6.7a//~v928I~
            netcol+=utf8strlen;                                    //~v928I~
			reccolomn+=utf8strlen;  		//v6.7a offset in the record//~v928I~
            UTRACED("xppf dumpbuff",dumpbuff,netcol);              //~v97qR~
          }                                                        //~v960I~
         }                                                         //~v928I~
         else                                                      //~v928I~
         {                                                         //~v928I~
#endif                                                             //~v928I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
          if (swebcfile)                                           //~v941I~
          {                                                        //~v955I~
			dumpbuff[netcol++]=(UCHAR)Gebcorgcode;	//original data for hex dump//~v941I~
            UTRACED("ebcfile dumpbuff",dumpbuff,netcol);           //~v97vI~
          }                                                        //~v955I~
          else                                                     //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
			dumpbuff[netcol++]=(UCHAR)readc;	//original data for hex dump v6.7a
			reccolomn++;					//v6.7a offset in the record
#ifdef UTF8SUPP                                                    //~v928I~
         }                                                         //~v928I~
#endif                                                             //~v928I~
		}									//v6.7a
	}                                                              //~v96eR~
	i=0;
    __reccolomnsv=reccolomn;  //for vfmt hexdump, before newline clear//~v96jI~
    Greccolomnold=reccolomn;                                       //~v96tI~
    if (readc==EOF 						//v6.7a
//   && ((colomn>LINENOSZ+2)||(hexdump&&samechk)))  //end of record v6.7a//~v96fR~
     && ((colomn>LINENOSZ+2)||((hexdump||vhexdump>1) && samechk)))  //end of record v6.7a//~v96fI~
    {                                                              //~v97vI~
	   i=1;										//line print v6.7a
       UTRACEP("linefeed EOF\n");                                  //~v97vR~
    }                                                              //~v97vI~
	else
//	    if (hexdump||recordsz)								//v6.7a//~v96eR~
  	    if (hexdump||recordsz||vfmt)								//v6.7a//~v96eI~
		{
#ifdef UTF8SUPP                                                    //~v928I~
		   if (XPUTF8MODE())                                       //~v928I~
           {                                                       //~v928I~
//  		if ((recordsz && reccolomn==recordsz)               //record end     v6.7a//~v928R~//~v96tR~
//  		||  (vfmt && reccolomn==recordszVEOL)               //record end     v6.7a//~v96eR~//~v96tR~
//          ||  (hexdump && netcol==dumpwidth))                    //~v928I~//~v96fR~
//          ||  ((hexdump||vhexdump>1) && netcol==dumpwidth))      //~v96fM~//~v96tR~
            if  (hexdump||vhexdump>1)                              //~v96tR~
            {                                                      //~v96tI~
 			  if (netcol==dumpwidth)                               //~v96tI~
              {                                                    //~v97vI~
				i=1;								//print v6.7a  //~v928I~
       			UTRACEP("linefeed utf8 hexdump/vhexdump>1:netcol=%d,dumpwidth=%d\n",netcol,dumpwidth);//~v97vI~
              }                                                    //~v97vI~
            }                                                      //~v96tI~
            else	//text mode                                    //~v96tI~
            {                                                      //~v96tI~
 			  if (colomn>=maxcol)                                  //~v96tI~
              {                                                    //~v97vI~
				i=1;								//print v6.7a  //~v96tI~
       			UTRACEP("linefeed utf8 textmode:colomn=%d,maxcol=%d\n",colomn,maxcol);//~v97vI~
              }                                                    //~v97vI~
            }                                                      //~v96tI~
           }                                                       //~v928I~
           else                                                    //~v928I~
#endif                                                             //~v928I~
    		if ((colomn>=maxcol && dbcssw2!=2)  //just line size   v6.7a
    		||  (vfmt && reccolomn==recordszVEOL)               //record end     v6.7a//~v96eR~
            ||  ((hexdump||vhexdump>1) && netcol==dumpwidth)       //~v96fR~
          	||	(reccolomn==recordsz))               //record end     v6.7a
            {                                                      //~v97vI~
				i=1;								//print v6.7a
       			UTRACEP("linefeed maxcol colomn=%d,maxcol=%d,dbcssw2=%d,reccolomn=%d,recordszVEOL=%d,netcol=%d,dumpwidth=%d,reccordsz=%d\n",//~v97vR~
       				colomn,maxcol,dbcssw2,reccolomn,recordszVEOL,netcol,dumpwidth,recordsz);//~v97vR~
            }                                                      //~v97vI~
		}											//v6.7a	
		else										//not record mode v6.7a	
    		if ( (colomn>maxcol && dbcssw2!=4) //line ovf but not dbcs last v2.7add
//         	|| (readc==EOF && colomn>LINENOSZ+2)   //no CRLF v2.7add v6.7d
#ifdef UTF8SUPP                                                    //~v928I~
//  	    || (XPUTF8MODE() && textmodevhexsw && netcol+LINENOSZ+1>=maxcol)//~v92cR~//~v96tR~
    	    || (XPUTF8MODE() && (textmodevhexsw||vhexdump>1) && netcol+LINENOSZ+1>=maxcol)//~v96tI~
#endif                                                             //~v928I~
         	|| (c==CRLF)           //cr+lf         v1.7add v2.7rep
         	|| (c==FORMFEED))                      //\f  v2.2add
            {                                                      //~v97GI~
				i=1;								//print v6.7r
                UTRACEP("formfeed c=%x,colomn=%d,maxcol=%d\n",c,colomn,maxcol);//~v97GI~
            }                                                      //~v97GI~
    if (swforcecr)    //fold to next line                          //~v960I~
    	i=1;                                                       //~v960I~
	if (i)									//v6.7r
    {
//offset edit for skim dump v6.6a
		if (hexdump)					//v6.7a
			readlineo=readline;			//v6.7a parm to printdump
		else		//not hexdump	v6.7a
		{
			readlineo=readline;			//v7.21a
			if (dumpmode==2)		//skim dump
	  		{
//dv6.7			sprintfwk[0]='%';
//dv6.7			sprintf(sprintfwk+1,"%02dlX",LINENOSZ);
				if (prnoffs)
		        	sprintf(buff,linespwk,prnoffs-1); //v6.7r
				else
					if (readc==EOF && colomn==LINENOSZ+3)//0x1a and ffff				//v6.6a
			        	sprintf(buff,linespwk,filecolomn-3); //offset of 0x1a v6.7r
					else
			        	memset(buff,' ',LINENOSZ); //unprintable only
       			if (!memcmp(buff,"00",2))
       			{
       				memset(buff,' ',2);
//dv6.7				if (!memcmp(buff+2,"00",2))
//dv6.7					memset(buff+2,' ',2);
       			}
				prnoffs=0;
		 	}//dumpmode==2
//offset edit for skim dump v6.6a
		 	else					//v6.6a
       			if (!contsw)
	   			{//v6.6a	
//dv6.7	  			sprintfwk[0]='%';								//v6.6a
//dv6.7				sprintf(sprintfwk+1,"%2du",LINENOSZ);		//v6.6a
		        	sprintf(buff,linespwk,readline); //v2.1rep  LINENOSZ=8 v6.6rv6.7r
	   			}//v6.6a
       			else
                {                                                  //~v96xI~
         			memset(buff,' ',LINENOSZ); //lineno v6.6r
					if (Gdatalinenosz)			//vhexline input   //~v96xI~
            			memset(buff+LINENOSZ+1,' ',(UINT)Gdatalinenosz-1);//~v96xI~
                }                                                  //~v96xI~

			buff[LINENOSZ]=ADDRDELM;       //delm  v2.1rep v6.7d
		}//not hexdump	v6.7a
//endof record of record mode mode v6.7a start
//     if (hexdump||recordsz)                                      //~v96eR~
       if (hexdump||recordsz||vfmt)                                //~v96eI~
       {
 	     if (readc==EOF)
#ifdef EEE                                                         //~v928I~
			colomn--;		//original data for hex dump
#else                                                              //~v928I~
            XPsetDECa(colomn,Gcolumnucs);                          //~v928I~
#endif                                                             //~v928I~
		 if (swforcecr==2)	//utf EOL(R and V)                     //~v96tR~
	 	 {                                                         //~v96tI~
	        readline++;                                            //~v96tI~
            UTRACEP("xppf UTF eol readline=%d,reccolomn=%d\n",readline,reccolomn);//~v96tI~
		    reccolomn=0;                                           //~v96tI~
	        contsw=0;  //next new line                             //~v96tI~
		 }                                                         //~v96tI~
         else                                                      //~v96tI~
    	 if (vfmt && reccolomn==recordszVEOL && colomn<=maxcol)//record end//~v96eI~//~v96fR~//~v96eR~//~v96jM~
	 	 {                                                         //~v96eI~//~v96jM~
	        readline++;                                            //~v96eI~//~v96jM~
            UTRACEP("xppf Vfmt readline=%d,reccolomn=%d,recordszVEOL=%d\n",readline,reccolomn,recordszVEOL);//~v96fI~//~v96eR~//~v96jM~
		    reccolomn=0;                                           //~v96eI~//~v96jM~
	        contsw=0;  //next new line                             //~v96eI~//~v96jM~
		 }                                                         //~v96eI~//~v96jM~
		 else                                                      //~v96eI~//~v96jM~
    	 if (reccolomn==recordsz && colomn<=maxcol)//record end
	 	 {
	        readline++;
		    reccolomn=0;
	        contsw=0;  //next new line
		 }
		 else
		 {
			if (readc==EOF)
			{
				if (colomn>LINENOSZ+1)
					readline++;
			}
			else
//  			if (hexdump&&!recordsz)                            //~v96eR~
    			if (hexdump && !recordsz && !vfmt)                 //~v96eI~
					readline++;
         	contsw=1;
         }
         buff[colomn++]=CRLF;
         XPsetACa_(Gbuffucs,Gcolumnucs,CRLF)                       //~v928R~
       }
	   else
//endof record of record mode mode v6.7a end
	       if (c==CRLF)			//v2.7rep
    	   {
        	 readline++;
        	 contsw=0;  //next new line
       	   }
       	   else
       	   {
#ifdef UTF8SUPP                                                    //~v92cI~
//            if ((XPUTF8MODE() && textmodevhexsw))                //~v92cR~//~v96tR~
              if ((XPUTF8MODE() && (textmodevhexsw||vhexdump>1)))  //~v96tI~
              {                                                    //~v92cI~
         		buff[colomn++]=CRLF; //v1.4add v2.7rep             //~v92cI~
         		XPsetACa_(Gbuffucs,Gcolumnucs,CRLF)                //~v92cI~
              }                                                    //~v92cI~
              else                                                 //~v92cI~
              {                                                    //~v92cI~
#endif                                                             //~v92cI~
         		buff[colomn-1]=CRLF; //v1.4add v2.7rep
         		XPsetAC_(Gbuffucs,Gcolumnucs-1,CRLF)               //~v928R~
#ifdef UTF8SUPP                                                    //~v92cI~
              }                                                    //~v92cI~
#endif                                                             //~v92cI~
         		if (colomn>LINENOSZ+2) //v2.2
           			contsw=1;  //else keep previous value
         		else
           			if (c==FORMFEED)//v3.5add at first colomn
#ifdef EEE                                                         //~v928I~
             			colomn--;     //v3.5add drop it
#else                                                              //~v928I~
             			XPsetDECa(colomn,Gcolumnucs);              //~v928I~
#endif                                                             //~v928I~
         		if (readc==EOF)                 //v2.7add 
           			readline++;                   //v2.7add
       		}

//  	if (hexdump)					//v6.7a                    //~v96fR~
    	if (hexdump||vhexdump>1)		//hhex or vhex(recordmode or recfm=V)//~v96fI~
		{								//v6.7a
//  		if (recordsz)		//record mode                      //~v96eR~
    		if (recordsz||vfmt)		//record mode                  //~v96eI~
			{						//v7.21a	
            	int __hexlen;                                      //~v96jI~
                int __eolpsz;                                  //~v96jI~//~v96tI~
  				__hexlen=netcol-(dbcssw2==2);	//hex print len    //~v96jR~
                UTRACEP("recfm=F/V __hexlen=%d,dbcssw=%d\n",__hexlen,dbcssw);//~v97qI~
//              if (vfmt && readc!=EOF && __reccolomnsv>recordszV0)   //reached eolprint pos//~v96jR~//~v96fR~//~v96tR~
                if (vfmt && readc!=EOF)                            //~v96tI~
                {                                                  //~v96jI~
                  if (eolprintnetcol>=0)  //utf_getinput() detected eolprint//~v96tI~
                  {                                                //~v96tI~
                    __eolpsz=max(0,netcol-eolprintnetcol);         //~v96tI~
                    __hexlen=max(0,netcol-__eolpsz);               //~v96tI~
                  }                                                //~v96tI~
                  else                                             //~v96tI~
				  if (__reccolomnsv>recordszV0)   //reached eolprint pos//~v96tI~
                  {                                                //~v96tI~
                    __eolpsz=__reccolomnsv-recordszV0;             //~v96jR~
                    __hexlen=max(0,netcol-__eolpsz);               //~v96jI~
                  }                                                //~v96tI~
                    UTRACEP("vfmt hexprint eolprint pos reccolomn=%d,recordszV=%d,recordszVEOL=%d,hexlen=%d,netcol=%d,eolprintnetcol=%d\n",reccolomn,recordszV,recordszVEOL,__hexlen,netcol,eolprintnetcol);//~v96jI~//~v96tR~
                }                                                  //~v96jI~
				if (inputrangeopt!=1 						//v7.21
				||  (readlineo>=inputrange1 && readlineo<inputrange2)) //v7.21a//~v907R~
					printdump(dumpbuff,buff+LINENOSZ+1,
    						(ULONG)readlineo,		//v7.0r
//							netcol-(dbcssw2==2),	//hex print len//~v96jR~
  							__hexlen,                              //~v96jI~
							colomn-LINENOSZ-1,		//char print len
							readc);	//v6.7a
				if (inputrangeopt==1 						//v7.21
				&&  samechk									//buffered v7.21a
				&&  readlineo==inputrange2)					 //last line v7.21a
					printdump(dumpbuff,buff+LINENOSZ+1,(ULONG)readlineo,1,1,EOF);//v7.21a
			}						//v7.21a
			else					//v6.7a
				printdump(dumpbuff,buff+LINENOSZ+1,
							(ULONG)(filecolomn-netcol),	//v7.0r
							netcol-(dbcssw2==2),	//hex print len
							colomn-LINENOSZ-1,
							readc);	//v6.7a
//		    if (XPUTF8MODE())                                      //~v96tI~//~v97uR~
	    	if (vhexdump>1)		//vhex(recordmode or recfm=V)      //~v96tI~
            {                                                      //~v96tI~
		 	  if (XPUTF8MODE())                                    //~v97vI~
				actualmaxc=max(actualmaxc,netcol);                 //~v97vI~
              else                                                 //~v97vI~
				actualmaxc=max(actualmaxc,max(colomn-LINENOSZ-1,netcol)); //-1 for crlf//~v96tR~
                UTRACEP("printfile vhex(R/V) utf8 actualmaxc=%d,colomn=%d,netcol=%d\n",actualmaxc,colomn,netcol);//~v96tR~//~v97uR~//~v97vR~
         		UTRACED("vhexdump buff",buff,colomn);              //~v97vI~
				UTRACED("vhexdump dumpbuff",dumpbuff,netcol);      //~v97vR~
                                                                   //~v96tI~
            }                                                      //~v96tI~
            else	//hhex                                         //~v97vI~
				actualmaxc=dumpwidth;                              //~v97vI~
		}//v6.7a
	   	else	//v6.7a
	   	{			//v6.7a
			if (dumpmode==2
			||  inputrangeopt!=1		//not line range     v7.21a
			||  (readlineo>=inputrange1 && readlineo<inputrange2)) //v7.21a//~v907R~
			{		//in the input range v7.21a
			  if (UCBITCHK(swsw4,SW4EBCCFG))                       //~v956R~
//          	vhexdatalinesw=((swsw4 & SW4VHEXMODE) && (*vhexlinech==VHEXDATALINEID_EBC));//~v956R~//~v96wR~
            	vhexdatalinesw=((swsw4 & SW4VHEXMODE) && (*vhexlinech==VHEXDATALINEID_EBC||*vhexlinech==VHEXDATALINEID));//~v96wI~
              else                                                 //~v956R~
            	vhexdatalinesw=((swsw4 & SW4VHEXMODE) && (*vhexlinech==VHEXDATALINEID));//~v91rR~
                if (vhexdatalinesw)                                //~v91rR~
                {                                                  //~v91rR~
	    	        if (line+2>=maxline)           //page overflow //~v91rR~
	    	   			printhdr();				//v6.7r            //~v91rR~
                }                                                  //~v91rR~
                else                                               //~v91rR~
	       		if (line==maxline)           //page overflow 
    	   			printhdr();				//v6.7r

		    	if (XPUTF8MODE())                                  //~v96tI~
            	{                                                  //~v96tI~
					actualmaxc=max(actualmaxc,netcol-1);  //-1 for crlf//~v96tR~
                	UTRACEP("printfile utf8 actualmax=%d,colomn=%d,netcol=%d\n",actualmaxc,colomn,netcol);//~v96tI~
            	}                                                  //~v96tI~
		       	if (colomn>LINENOSZ+1) //after drop \f            v2.2add
    	   		{                                                //v2.2add
			 		actualmaxc=max(actualmaxc,colomn-LINENOSZ-1-1); //v5.1a
	                UTRACEP("printfile text actualmax=%d,colomn=%d\n",actualmaxc,colomn);//~v96tR~
         			line++;
                  if (vhexdatalinesw)	//not 3 line mode          //~v91rR~
                  {                                                //~v91rR~
                      if (Gvhexlineoffs>1)    //2nd of cont line   //~v91rR~
#ifdef UTF8SUPP                                                    //~v928I~
					  {                                            //~v928I~
#endif                                                             //~v928I~
                          *(buff+LINENOSZ+Gdatalinenosz)=vhexcontdelm;//~v91rR~
                          XPsetC_(Gbuffucs,LINENOSZ+Gdatalinenosz,vhexcontdelm)//~v928R~
#ifdef UTF8SUPP                                                    //~v928I~
					  }                                            //~v928I~
#endif                                                             //~v928I~
//                    else                                         //~v91rR~
//                        vhexcontdelm=*(buff+LINENOSZ+Gdatalinenosz);//~v91rR~
                      else                                         //~v96xI~
                          vhexcontdelm=*(buff+LINENOSZ+1+Gdatalinenosz-1);//~v96xI~
                  }                                                //~v91rR~
                  else                                             //~v91rR~
	         		for (i=0;i<lineskip;i++)  //v3.5add
#ifdef UTF8SUPP                                                    //~v928I~
					{                                              //~v928I~
#endif                                                             //~v928I~
    	       			buff[colomn++]='\n';    //v3.5add
    	       			XPsetACa_(Gbuffucs,Gcolumnucs,'\n')    //v3.5add//~v928R~
#ifdef UTF8SUPP                                                    //~v928I~
					  }                                            //~v928I~
#endif                                                             //~v928I~
					XPsetucsON_()	//parm to datapline:utf strlen //~v928R~
        	 		datapline(buff,sizeof(char),colomn,output);//v3.2rep v3.5rv7.12r
                    if (vhexdatalinesw)	//3 line mode              //~v91rR~
                    {                                              //~v91rR~
#ifdef UTF8UCS2                                                    //~v940I~
            	      if (swsw4 & SW4VHEXMODEU)//ucs2 vhex from xe //~v940I~
                      {                                            //~v940I~
                      	for (;Gutf8vhexlen>0;)                     //~v940R~
                        {                                          //~v940I~
                            vhexmaxlen=maxcol-(LINENOSZ+1);        //~v940R~
                            vhexlinelen=min(vhexmaxlen,Gutf8vhexlen);//~v940R~
                            vhexpc=buff+LINENOSZ+1; //noprefix option//~v940R~
                            vhexoutlen=vhexlinelen+LINENOSZ+1;     //~v940I~
                            if (Gvhexlineoffs>1)    //2nd of cont line//~v940I~
                            {                                      //~v940I~
	                            vhexlinelen=min(vhexmaxlen-Gdatalinenosz,vhexlinelen);//~v940R~
                                vhexpc+=Gdatalinenosz;             //~v940I~
                                vhexoutlen+=Gdatalinenosz;         //~v940I~
                            }                                      //~v940I~
                            Gutf8vhexlen-=vhexlinelen;             //~v940M~
                            *(vhexpc-1)=vhexcontdelm;              //~v940I~
                            memcpy(vhexpc,vhexlinex1+Gvhexlineoffs,(UINT)vhexlinelen);//~v940I~
                            XPsetucsOFF_()  //parm to datapline:utf strlen//~v940I~
                            if (Gutf8vhexlen>0) //line split       //~v940I~
    	       					buff[vhexoutlen++]='\n';    //v3.5add//~v940R~
                            datapline(buff,sizeof(char),vhexoutlen,output);//v3.2rep v3.5rv7.12r//~v940I~
                            memcpy(vhexpc,vhexlinex2+Gvhexlineoffs,(UINT)vhexlinelen);//~v940I~
                            if (!contsw)                           //~v940I~
	         					for (i=0;i<lineskip;i++)  //v3.5add//~v940R~
    	       						buff[vhexoutlen++]='\n';    //v3.5add//~v940R~
                            XPsetucsOFF_()  //parm to datapline:utf strlen//~v940I~
                            datapline(buff,sizeof(char),vhexoutlen,output);//v3.2rep v3.5rv7.12r//~v940I~
                            Gvhexlineoffs+=vhexlinelen;            //~v940I~
                            line+=2;                               //~v940I~
                            if (contsw)                            //~v940I~
                            	break;                             //~v940I~
                        }                                          //~v940I~
                      }                                            //~v940I~
                      else                                         //~v940I~
#endif                                                             //~v940I~
                      {                                            //~v940I~
//  	                vhexlinelen=colomn-1-(LINENOSZ+1);	//if cont "\n" is added//~v91rR~//~v96rR~
		                vhexlinelen=Gvhexlinelenhhex-1;	//if cont "\n" is added//~v96rI~
                        vhexpc=buff+LINENOSZ+1;                    //~v91rR~
	                    if (Gvhexlineoffs>1)	//2nd of cont line //~v91rR~
                        {                                          //~v91rR~
//  	                	vhexlinelen-=Gdatalinenosz;	//for contnued line//~v91rR~//~v96vR~
                            vhexpc+=Gdatalinenosz;                 //~v91rR~
                        }                                          //~v91rR~
    	                vhexlinelen-=Gvhexlineoffs;                //~v96vI~
                        *(vhexpc-1)=vhexcontdelm;                  //~v91rR~
//                      memcpy(vhexpc,vhexlinex1+Gvhexlineoffs,(UINT)vhexlinelen);//~v91rR~//~v96vR~
                        vhexprintlen=colomn-LINENOSZ-1-(*(buff+colomn-1)=='\n'?1:0);//~v96vR~
                        vhexprintlen=min(vhexlinelen,vhexprintlen);//~v96vR~
                        memcpy(vhexpc,vhexlinex1+Gvhexlineoffs,(UINT)vhexprintlen);//~v96vI~
                        vhexprintlen0=vhexprintlen;                //~v96vI~
                        *(vhexpc+vhexprintlen++)='\n';             //~v96vR~
	                    if (Gvhexlineoffs>1)	//2nd of cont line //~v96vI~
                            vhexprintlen+=Gdatalinenosz;           //~v96vI~
						XPsetucsOFF_()	//parm to datapline:utf strlen//~v96vI~
//  	        	 	datapline(buff,sizeof(char),colomn,output);//v3.2rep v3.5rv7.12r//~v91rR~//~v96rR~
    	        	 	datapline(buff,sizeof(char),vhexprintlen+LINENOSZ+1,output);//v3.2rep v3.5rv7.12r//~v96rR~//~v96vR~
//                      memcpy(vhexpc,vhexlinex2+Gvhexlineoffs,(UINT)vhexlinelen);//~v91rR~//~v96vR~
                        memcpy(vhexpc,vhexlinex2+Gvhexlineoffs,(UINT)vhexprintlen);//~v96vI~
                        vhexprintlen=vhexprintlen0;                //~v96vI~
                        *(vhexpc+vhexprintlen++)='\n';             //~v96vR~
	         			for (i=0;i<lineskip;i++)  //v3.5add        //~v91rR~
#ifdef UTF8SUPP                                                    //~v928I~
						{                                          //~v928I~
#endif                                                             //~v928I~
//                            buff[colomn++]='\n';    //v3.5add      //~v91rR~//~v96vR~
//                            XPsetACa_(Gbuffucs,Gcolumnucs,'\n')    //v3.5add//~v928R~//~v96vR~
	                        *(vhexpc+vhexprintlen++)='\n';         //~v96vI~
#ifdef UTF8SUPP                                                    //~v928I~
						}                                          //~v928I~
#endif                                                             //~v928I~
#ifdef UTF8UCS2                                                    //~v940I~
						XPsetucsOFF_()	//parm to datapline:utf strlen//~v940I~
#else                                                              //~v940I~
						XPsetucsON_()	//parm to datapline:utf strlen//~v928I~
#endif                                                             //~v940I~
//          	 		datapline(buff,sizeof(char),colomn,output);//v3.2rep v3.5rv7.12r//~v91rR~//~v96rR~
	                    if (Gvhexlineoffs>1)	//2nd of cont line //~v96vI~
                            vhexprintlen+=Gdatalinenosz;           //~v96vI~
            	 		datapline(buff,sizeof(char),vhexprintlen+LINENOSZ+1,output);//v3.2rep v3.5rv7.12r//~v96rR~//~v96vR~
//                      Gvhexlineoffs+=vhexlinelen;                //~v91rR~//~v96rR~
                        Gvhexlineoffs+=vhexprintlen0;               //~v96rI~//~v96vR~
                        line+=2;                                   //~v925I~
                      }//UCS2                                      //~v940I~
                    }                                              //~v91rR~
                    if (textmodevhexsw)	//3 line mode of text mode //~v92bI~
                    {                                              //~v92bI~
						XPsetucsOFF_()	//parm to datapline:utf strlen//~v928I~
#ifdef UTF8SUPP                                                    //~v92cI~
		              if (XPUTF8MODE())                            //~v92uR~
						printdump3(dumpbuff,netcol-(contsw==0)); //drop 0x0a//~v92cR~
                      else                                         //~v92uR~
						printdump3(dumpbuff,netcol-(dbcssw2==2)-1);//~v92uR~
#else                                                              //~v92cI~
						printdump3(dumpbuff,netcol-(dbcssw2==2)-1);//~v92bR~
#endif                                                             //~v92cI~
                    }                                              //~v92bI~
	       		}//v3.5add

    	   		if (c==FORMFEED)                      //v2.2add xxx\f(no \n)
       			{                                    //v2.2add
					XPsetucsOFF_()	//parm to datapline:utf strlen //~v928I~
         			for (;line<maxline;line++)         //v2.2 residual line
           				datapline(spaceline,sizeof(char),spacelinelen,output);//v2.2addv3.5repv7.12r
	       		}                                              //v2.2add up to endpage 
			}		//in the input range v7.21a
            else                                                //~v74fI~
				if (fastpathsw				//no need chk max line//~v74fI~
				&&  readlineo>=inputrange2) //over range        //~v74fI~
                	break;                                      //~v74fI~
		}//v6.7a not hexdump

       	colomn=LINENOSZ+1;                          //v2.1rep
		XPsetEQ_(Gcolumnucs,colomn)         //index on ucs tbl     //~v928R~
	   	netcol=0;				//v6.7a
		if (contsw && Gdatalinenosz)			//lineno data width in the file//~v90jR~
        {                                                          //~v90jI~
        	int __ii;                                              //~v96xI~
//          memset(buff+colomn,' ',(UINT)Gdatalinenosz);           //~v90tR~//~v96xR~
            memset(buff+colomn,' ',(UINT)Gdatalinenosz-1);         //~v96xI~
//      	colomn+=Gdatalinenosz;         //skip lineno data width on the file line//~v90jI~//~v96xR~
         if (XPUTF8MODE())                                         //~v97GI~
         {                                                         //~v97GI~
            for (__ii=0;__ii<Gdatalinenosz-1;__ii++)               //~v96xI~
         		XPsetACa_(Gbuffucs,colomn,' ');  //crear 4 ucs lineno column//~v96xI~
	   		colomn++;                                              //~v97GI~
			XPsetEQ_(Gcolumnucs,colomn)         //index on ucs tbl //~v928R~
         }                                                         //~v97GI~
         else                                                      //~v97GI~
         	colomn+=Gdatalinenosz;                                 //~v97GI~
//          *(buff+colomn-1)=XECONTLINEDELM;                       //~v91rM~//~v96xR~
	   		netcol=Gdatalinenosz;				                   //~v90jI~
            UTRACEP("cont Gdatalinenosz=%d colomn=%d,Gcolumnucs=%d\n",Gdatalinenosz,colomn,Gcolumnucs);//~v97GI~
        }                                                          //~v90jI~

       if ( contsw                                 //v1.4add
       &&   c!=FORMFEED )                          //v3.5add
       { //* line continue                          //v1.4add
//  	 if (hexdump||recordsz)			//v6.7a                    //~v96eR~
    	 if (hexdump||recordsz||vfmt)                              //~v96eI~
		 {						//v6.7a		
#ifdef UTF8SUPP                                                    //~v928I~
	       if (!XPUTF8MODE())                                      //~v928I~
#endif                                                             //~v928I~
		 	if (dbcssw2==4)		//boundary v6.7a
			 	dumpbuff[netcol++]=dumpbuff[dumpwidth];	//v6.7a
		 }												//v6.7a
		 else											//v6.7a
#ifdef UTF8SUPP                                                    //~v92cR~
//       if (!(XPUTF8MODE() && textmodevhexsw))                    //~v92cR~//~v96tR~
         if (!(XPUTF8MODE() && (textmodevhexsw||vhexdump>1)))      //~v96tI~
#endif                                                             //~v92cR~
		 {												//v6.7a
//           buff[LINENOSZ+1]=c;                        //v1.4add v2.1rep//~v90jR~
//  	     colomn=LINENOSZ+2;       //v1.4add            v2.1rep //~v90jR~
             buff[colomn++]=c;                        //v1.4add v2.1rep//~v90jI~
    		if (dummybytesw && textmodevhexsw)                     //~v92bI~
				dumpbuff[netcol++]=(UCHAR)splitchar2;              //~v92bI~
            else                                                   //~v955I~
          	if (swebcfile)                                         //~v955I~
          	{                                                      //~v955I~
				dumpbuff[netcol++]=(UCHAR)Gebcorgcode;	//original data for hex dump//~v955I~
          	}                                                      //~v955I~
            else                                                   //~v955I~
				dumpbuff[netcol++]=(UCHAR)readc;	//original data for hex dump//~v955I~
			 if (chartype&&!dummybytesw)//v6.7a
			 {//v6.7a
				prnoffs=filecolomn;			//first printable of a line v6.7a
//  			prncol=LINENOSZ+1;			//that colomn to chk repl by . v6.7a//~v90jR~
    			prncol=colomn;    			//that colomn to chk repl by . v6.7a//~v90jI~
			 }//v6.7a 	
#ifdef UTF8SUPP                                                    //~v928I~
			if (XPUTF8MODE())                                      //~v928I~
    		{                                                      //~v928I~
    			if (c!=readc||dummybytesw)	//tab or unprintable replace print char//~v928I~
		    		Gbuffucs[Gcolumnucs++]=c;                      //~v928I~
        		else                                               //~v928I~
        		{                                                  //~v928I~
		    		Gbuffucs[Gcolumnucs++]=ucs;                    //~v928I~
        			if (dbcssw)                                    //~v928I~
			    		buff[colomn++]=c;                          //~v928I~
        		}                                                  //~v928I~
		    }                                                      //~v928I~
#endif                                                             //~v928I~
		 }												//v6.7a	
       } //* line continue                          //v1.4add
    }//line overflow
  }//until eof
  if (!UCBITCHK(swsw3,SW3CONJUNCT))				//also listgen mode//~v801I~
  	break;                                                         //~v801I~
//*conjunct mode                                                   //~v803I~
  totline+=readline-1;                                             //~v801I~
  if (phase2sw)	//phase2(print end)                                //~v803I~
  {                                                                //~v801I~
    totfile++;                                                     //~v801M~
	if (pagesw)   //page range started                             //~v801R~
    {                                                              //~v91rI~
#ifdef W32UNICODE                                                  //~v990I~
 		uerrfprintfutf(0,Gmsgfile,"\n%s:%s:print end - \"%s\"; now %d'th page",//~v990I~
    						      "\n%s:%s:プリント終了 - \"%s\"; 現在 %d 頁目",//~v990I~
          	 	pgmid,ver,flistc->name,page);                      //~v990I~
#else                                                              //~v990I~
		if (dbcsenv)	//DBCS mode v4.9a                          //~v801R~
    		printf("\n%s:%s:プリント終了 - \"%s\"; 現在 %d 頁目",  //~v801R~
          	 	pgmid,ver,flistc->name,page);                      //~v801R~
		else                                                       //~v801R~
    		printf("\n%s:%s:print end - \"%s\"; now %d'th page",   //~v801R~
          	 	pgmid,ver,flistc->name,page);                      //~v801R~
#endif                                                             //~v990I~
    }//pagesw                                                      //~v91rI~
  }                                                                //~v801I~
  if (databuffsw && !phase2sw)	//phase1 avail buffer size         //~v803I~
  	flistc->databuffl=databuffc;	//save current eof ptr;        //~v803I~
    fclose(input);                                                 //~v803I~
	if (swsetarchive)		//set archive attribute off v7.2a      //~v801I~
		archoff();			//v7.2a                                //~v801I~
    input=0;                                                       //~v803I~
    readcount=0;        //for hex dump                             //~v801I~
  do                                                               //~v801I~
  {                                                                //~v801I~
  	openrc=openinput(NULL);		//open next file on listgen        //~v801I~
//  printf("next file search rc=%d,input=%08x\n",openrc,input);    //~v803R~
  }while(!openrc && !input);	//file exist and selected file     //~v801R~
}while(!openrc);//until no file in dir(for conjunct mode,read next file)//~v801I~

  if (!printsw)  //v3.2add no page printed
  {             //v3.2add
	if (!phase2sw)  //page chk phase v4.6a
    {                                                              //~v91rI~
	    if (readcount==1)//v3.7a v6.7r
			if (dbcsenv)	//DBCS mode v4.9a
    		  printf(" は空です.\n");//v4.9a                       //~v97mR~
			else			//SBCS mode v4.9a	
    		  printf(" is empty.\n");//v3.7a v4.6r                 //~v97mR~
		else
			if (dbcsenv)	//DBCS mode v4.9a
    		  printf("\n出力頁範囲 (%d-%d,全 %d 頁) 又は入力行範囲 (%s,全 %ld 行) の誤り。\n",//~v74iR~
			  			pagestart,pageend,page,inputrangep,readline-1);//v4.9av7.21r
			else			//SBCS mode v4.9a	
    		  printf("\noutput page range(%d-%d,total %d) err or input line range(%s,total %ld) err.\n",//~v74iR~
			  			pagestart,pageend,page,inputrangep,readline-1);//v4.9av7.21r
    }//phase2sw                                                    //~v91rI~
//    exit(4);    //v3.2add dv4.6
	Gxpotheropt|=GOO_NOPAGEPRINTED;//   0x00000400 //no page oprinted//~v970I~
    return;	//v4.6	
  }             //v3.2add
  else			//av4.6
	  if (!phase2sw)  //page chk phase v4.6a
	  {//v7.26a	
  		if (UCBITCHK(swsw3,SW3CONJUNCT))				//also listgen mode//~v801I~
        {                                                          //~v801I~
        	linemsg=totline;                                       //~v801I~
			totline=0;                                             //~v801I~
        }                                                          //~v801I~
        else                                                       //~v801I~
        	linemsg=readline-1;                                    //~v801I~
#ifdef W32UNICODE                                                  //~v990I~
 		uerrfprintfutf(0,Gmsgfile,"... has %ld line,%d page",      //~v990R~
   							      "... は %ld 行, %d 頁",          //~v990R~
   							linemsg,page);                         //~v990I~
#else                                                              //~v990I~
		if (dbcsenv)	//DBCS mode v4.9a
// 			printf("... は %ld 行, %d 頁",linemsg,page);//v4.9a v6.7rv7.26r//~v90mR~
   			fprintf(Gmsgfile,"... は %ld 行, %d 頁",linemsg,page);//v4.9a v6.7rv7.26r//~v90mI~
		else			//SBCS mode v4.9a	
// 			printf("... has %ld line,%d page",linemsg,page);//v4.6av7.26r//~v90mR~
 			fprintf(Gmsgfile,"... has %ld line,%d page",linemsg,page);//v4.6av7.26r//~v90mI~
#endif                                                             //~v990I~
		fflush(stdout);			//v7.26a
	  }//v7.26a

//  pageend=min(pageend,page);//v3.2addv3.7d

  strncpy(trailer,header1,(UINT)header1len);//to edit FEOF v3.7a v6.7r
  memset(trailer,' ',LINENOSZ);	//v6.6a
  memcpy(trailer+LINENOSZ-4,"FEOF",4);//end of file indicator //v1.9add v2.1repv3.7r v6.6r
  XPsetucsOFF_()	//parm to datapline:utf strlen                 //~v928I~
  if (header1outsw)	//v7.12a	
  {                                                                //~v97mI~
        if (hexdump)                                               //~v97qI~
	        Gxpotheropt|=GOO_HHEXLINE;                             //~v97qI~
		Gxpotheropt|=GOO_MONOSPACELINE;	//parm to lnx_textout      //~v97mI~
		datapline(trailer,sizeof(char),header1len,output); //v2.7addv3.2rep v3.5rv3.7r v6.7rv7.12r
		Gxpotheropt&=~GOO_MONOSPACELINE;	//parm to lnx_textout  //~v97mI~
        if (hexdump)                                               //~v97qR~
	        Gxpotheropt&=~GOO_HHEXLINE;                            //~v97qI~
  }                                                                //~v97mI~

  time(&stck);					//940609a
  plocaltime=localtime(&stck);	//940609a
  pc="";                                                           //~v96jI~
#ifdef UTF8UCS2                                                    //~v940I~
 if (Gxputfstat & GXPUS_UTF8ON)                                    //~v940I~
  pc="UTF8";                                                       //~v940I~
// else                                                              //~v940I~//~v96jR~
#endif                                                             //~v940I~
//  pc=textmode[dumpmode];        //v7.12a                         //~v96jR~
//  if (hexdump)                  //v7.12a                         //~v96jR~
//    pc=textmode[3];         //v7.12a                             //~v96jR~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
    if (swebcfile)                                                 //~v941I~
    {                                                              //~v941I~
//  	sprintf(editebcmode,"EBCDIC-%s",pc);                       //~v941I~//~v953R~
        if (Gebcdictype==3)	//cfg                                  //~v953I~
        	pcvname=ucvebc4_getcvname(0,Gxpebchandle);             //~v953R~
        else                                                       //~v953I~
        	pcvname="IntrernalMap";                                //~v953I~
//  	sprintf(editebcmode,"EBCDIC(%s)-%s",pcvname,pc);           //~v953R~//~v96jR~
//  	sprintf(editebcmode,"EBCDIC(%s)",pcvname);                 //~v96jR~
    	sprintf(editebcmode,"%s=%s",PARM_CPEB,pcvname);            //~v96jI~
        pc=editebcmode;                                            //~v941R~
//      if (recordsz)                                              //~v953R~//~v96qR~
        if (recordszparm)                                          //~v96qI~
//          sprintf(edittabctr,"R-%d",recordsz);               //~v953I~//~v955R~//~v96jR~
//          sprintf(edittabctr,"R%d",recordsz);                    //~v96jI~//~v96qR~
//          sprintf(edittabctr,"R%d",recordszparm);                //~v96qI~//~v96tR~
            sprintf(edittabctr,"%s",recordszparm);                 //~v96tI~
        else                                                       //~v953I~
//      if (vfmt)                                                  //~v96eI~//~v96tR~
        if (vfmtparm)                                              //~v96tI~
//          sprintf(edittabctr,"V-%s",ufile5getVfmtstr(0,vfmt));   //~v96eR~//~v96jR~
//          sprintf(edittabctr,"V%s",ufile5getVfmtstr(0,vfmt));    //~v96jI~//~v96tR~
            sprintf(edittabctr,"%s",vfmtparm);                     //~v96tI~
        else                                                       //~v96eI~
        if (Gxpotheropt & GOO_ASCEOL)                              //~v953I~
            strcpy(edittabctr,"ASCEOL");                           //~v953R~
        else                                                       //~v953I~
            sprintf(edittabctr,"EBCEOL(0x%02x)",EBC_NL);           //~v953R~
    }	                                                           //~v941I~
    else                                                           //~v953I~
    {                                                              //~v96jI~
      int __tabctroffs=0;                                          //~v96fI~
        *edittabctr=0;                                             //~v995I~
//    if (recordsz)                                                //~v96fI~//~v96qR~
      if (recordszparm)                                            //~v96qI~
//      __tabctroffs=sprintf(edittabctr,"R%d",recordsz);           //~v96fI~//~v96qR~
//      __tabctroffs=sprintf(edittabctr,"R%d",recordszparm);       //~v96qI~//~v96tR~
        __tabctroffs=sprintf(edittabctr,"%s",recordszparm);        //~v96tI~
      else                                                         //~v96fI~
//    if (vfmt)                                                    //~v96fI~//~v96tR~
      if (vfmtparm)                                                //~v96tI~
//      __tabctroffs=sprintf(edittabctr,"V%s",ufile5getVfmtstr(0,vfmt));//~v96fI~//~v96tR~
        __tabctroffs=sprintf(edittabctr,"%s",vfmtparm);            //~v96tI~
//    if (hexdump)					//v7.12a                       //~v96jI~//~v96xR~
      if (dumpmode)					//v7.12a                       //~v96xI~
//  	*edittabctr=0;                                             //~v96jR~//~v96fR~//~v96xR~
        ;                                                          //~v96xI~
      else                                                         //~v96jI~
//  	sprintf(edittabctr,"tab=%d",tabskip);                      //~v953I~//~v96fR~
    	sprintf(edittabctr+__tabctroffs," tab=%d",tabskip);        //~v96fI~
    }                                                              //~v96jI~
    	                                                           //~v953I~
#endif          //EBCDIC dbcs support                              //~v941I~
  if (dumpmode==2)			//skim dump mode v7.12a	
//    intwk=sprintf(trailer,"\n%s:%s:end of process at %02d/%02d/%02d %02d:%02d;//~v898R~
//    intwk=sprintf(trailer,"\n%s:%s:(%c)end of process at %04d/%02d/%02d %02d:%02d;//~v955R~
//    intwk=sprintf(trailer,"\n%s:%s:(%c)Printed at %04d/%02d/%02d %02d:%02d;//~v9e0R~
      intwk=sprintf(trailer,"\n%s:%s:(%c) %04d/%02d/%02d %02d:%02d;\
 mode=%s%s%s tab=%d.\n", //v4.6av6.5r v7.1rv7.12r                  //~v96jR~
// mode=%s(%d)-%s,tab=%d.\n", //v4.6av6.5r v7.1rv7.12r             //~v96jR~
	    pgmid,ver,OSTYPE,                                          //~v898R~
//  	plocaltime->tm_year,plocaltime->tm_mon+1,plocaltime->tm_mday,//~v898R~
    	plocaltime->tm_year+1900,plocaltime->tm_mon+1,plocaltime->tm_mday,//~v898I~
		plocaltime->tm_hour,plocaltime->tm_min,
//      pc,minprnc,asciiid[asciimode],//v3.1repv6.5r v7.12r        //~v96jR~
        modeparm,(*pc?"-":""),pc,   //%s-%s                        //~v96jR~
        tabskip);//v4.6a 940609a v6.7r
  else						//v7.12a
  {                                                             //~v747I~
//    intwk=sprintf(trailer,"\n%s:%s:end of process at %02d/%02d/%02d %02d:%02d;//~v898R~
//    intwk=sprintf(trailer,"\n%s:%s:(%c)end of process at %04d/%02d/%02d %02d:%02d;//~v955R~
//    intwk=sprintf(trailer,"\n%s:%s:(%c) Printed at %04d/%02d/%02d %02d:%02d;//~v9e3R~
      intwk=sprintf(trailer,"\n%s:%s:(%c) %04d/%02d/%02d %02d:%02d;\
%s\n", //cmdline parms                                             //~v9e4R~
//mode=%s,%s%s%s%s.\n", //modeparm-pc-edittabctr                     //~v96jR~//~v96xR~//~v9e4R~
// mode=%s-%s%c,%s.\n", //v4.6av6.5r v7.1r                           //~v969M~//~v96jR~
// mode=%s-%s%n,%s.\n", //v4.6av6.5r v7.1r                           //~v953I~//~v969R~
	    pgmid,ver,OSTYPE,                                          //~v898R~
//  	plocaltime->tm_year,plocaltime->tm_mon+1,plocaltime->tm_mday,//~v898R~
    	plocaltime->tm_year+1900,plocaltime->tm_mon+1,plocaltime->tm_mday,//~v898I~
		plocaltime->tm_hour,plocaltime->tm_min,
//      pc,asciiid[asciimode],                                     //~v96jR~
//      modeparm,(*pc?" ":""),pc,(*edittabctr?" ":""),      //%s-%s//~v96jR~//~v9e4R~
//      &ii,	//to set \n for hex mode                        //~v747I~//~v969R~
//      '\t',   //for tabctr pos                                   //~v969R~//~v96jR~
//      tabskip);//v7.12a                                          //~v953R~
//      edittabctr);//v7.12a                                       //~v953I~//~v9e4R~
        Gcmdlineparms);                                            //~v9e4I~
//        ii=(ULPTR)strchr(trailer,'\t')-(ULPTR)trailer;             //~v969I~//~v96jR~
//        if (hexdump)                    //v7.12a                //~v747I~//~v96jR~
//        {                                                       //~v761I~//~v96jR~
//            strcpy(trailer+ii,"\n");        //drop tab          //~v747I~//~v96jR~
//            intwk=ii+1;                                         //~v761I~//~v96jR~
//        }                                                       //~v761I~//~v96jR~
  }                                                             //~v747I~
  if (UCBITCHK(swsw3,SW3FORM2P) 	//form 2p                      //~v911R~
  ||  (UCBITCHK(swsw3,SW3WIN2P) && prntyp!=PRINTER_WIN)) //putline2p call case//~v911I~
  {                                                                //~v911I~
  	Gtrailersw=1;   //parm to putline2p                            //~v911I~
	pline(trailer,sizeof(char),intwk,output);//v2.7add//v3.2repv3.7r v6.7r//~v911I~
    Gtrailersw=0;                                                  //~v911I~
  }                                                                //~v911I~
  else                                                             //~v911I~
  if (line>(maxline-2))	    	//no space on last page v5.3a
  {                                                                //~v91xI~
   if (!UCBITCHK(swsw4,SW4NOFFCMD)) //skip ff insert               //~v91xR~
	trailer[0]=FORMFEED;  		//eject page v5.3a              //~v745R~
  }                                                                //~v91xI~
  else                          //write only when avail space on the page//~v746R~
	if (header0outsw)	//v7.13a	                            //~v745R~
		pline(trailer,sizeof(char),intwk,output);//v2.7add//v3.2repv3.7r v6.7r//~v745R~
  if (printsw)  //v3.2add once printed
    pagesw=1;   //v3.2add force despageout and last \f 
//realpage=min(pageend,page)-pagestart+1;				//v5.8a //~v74hR~
  if (phase2sw)						//print phase v4.4a	
  {		//v4.6a
	if (despagesw)		//page descending order print v5.3a
//    despageout(output); //output from work file v5.3a            //~v859R~
      despageout(1,output); //output from work file v5.3a          //~v859I~
//#ifdef W32                                                       //~v867R~
//    if (prntyp==PRINTER_WIN)    //printer type(default Win for win version)//~v867R~
//        if (!UCBITCHK(swsw3,SW3CONJUNCT))//not conjunct mode     //~v867R~
//            win_closedoc(); //only when PRINTER_WIN              //~v867R~
//#endif                                                           //~v867R~
#ifdef GTKPRINT                                                    //~v97cI~
#else                                                              //~v97cI~
	if (dbcsenv)	//DBCS mode v4.9a
//  	printf("\n%s:%s:プリント終了;出力 = %d 頁 (全 %d 頁中 %d-%d の範囲).\n",//v7.26r//~v90mR~
    	fprintf(Gmsgfile,"\n%s:%s:プリント終了;出力 = %d 頁 (全 %d 頁中 %d-%d の範囲).\n",//v7.26r//~v90mI~
        	 pgmid,ver,realpage,page,pagestart,min(pageend,page)); //v4.9a//~v74hR~
    else			//SBCS mode v4.9a	
//  	printf("\n%s:%s:print end;output= %d pages (from range %d-%d of %d pages).\n",//v7.26r//~v90mR~
    	fprintf(Gmsgfile,"\n%s:%s:print end;output= %d pages (from range %d-%d of %d pages).\n",//v7.26r//~v90mI~
        	 pgmid,ver,realpage,pagestart,min(pageend,page),page); //v4.6a//~v74hR~
#endif                                                             //~v97cI~
  if (!UCBITCHK(swsw3,SW3CONJUNCT))				//also listgen mode//~v801I~
  {                                                                //~v801I~
  	totfile++;		//total file count v4.1a
   	totline+=readline-1;		//v4.6a                            //~v801M~
  }                                                                //~v801I~
#ifdef GTKPRINT                                                    //~v97cI~
#else                                                              //~v97cI~
   	totpage+=realpage;			//total real output page v5.8r
#endif                                                             //~v97cI~
  }		//v4.6a
	lastpage=page;					//for second phase v4.4a
}//printfile    
//**********************************************************************//~v801I~
// print sub header under conjunct mode                            //~v801I~
//**********************************************************************//~v801I~
void printsubhdr(int Plinewidth)                                   //~v801R~
{                                                                  //~v801I~
	int i;                                                         //~v801I~
    char *pc;                                                      //~v801I~
	char headersw[MAXLINEWIDTH];     //sub header edit             //~v801I~
	char subdelm[MAXLINEWIDTH];                                    //~v803I~
//  char headerswp[16];                                            //~v803R~//~v97gR~
    char headerswp[64];                                            //~v97gI~
#ifdef GTKPRINT                                                    //~v97mI~
    int lendelm;                                                   //~v97mI~
#endif                                                             //~v97mI~
//****************                                                 //~v801I~
//*conjunct mode separator                                         //~v801I~
	if (lineprefixsw)		//v7.12a                               //~v801I~
	  	sprintf(headerswp,"*===== %%%ds =\n",(i=Plinewidth-LINENOSZ-1-2));//~v803R~
	else					//v7.12a                               //~v801I~
	  	sprintf(headerswp,"       *===== %%%ds =\n",(i=Plinewidth-(LINENOSZ+1)*2-2));//~v803R~
    if ((int)strlen(headers)>=i)	//line width overflow          //~v801I~
    {                                                              //~v801I~
    	for (pc=headers;;)							//cut from root dir name//~v801I~
		{                                                          //~v801I~
        	pc++;                                                  //~v801I~
//      	if (!(pc=ustrchr2(pc,'\\')))		//search '\' not DBCS 2nd byte//~v907R~
        	if (!(pc=ustrchr2(pc,DIR_SEPC)))		//search '\' not DBCS 2nd byte//~v907I~
            	break;                                             //~v801I~
    		if (pc>=(headers+5) && ((int)strlen(pc)+5)<i)	//space for 'd:...' to be added//~v801I~
            {                                                      //~v801I~
            	memcpy(headers+2,"...",3);                         //~v801I~
                strcpy(headers+5,pc);		//drop preceding pathname//~v801I~
            	break;                                             //~v801I~
			}                                                      //~v801I~
		}                                                          //~v801I~
	}                                                              //~v801I~
  	i=sprintf(headersw,headerswp,headers);//set len                //~v803R~
#ifdef GTKPRINT                                                    //~v97mI~
    lendelm=Plinewidth+1;                                          //~v97mR~
	memset(subdelm,'=',(UINT)lendelm);                             //~v97mI~
    *(subdelm+lendelm-1)='\n';                                     //~v97mI~
    *(subdelm+lendelm)=0;                                          //~v97mI~
#else                                                              //~v97mI~
	memset(subdelm,'=',(UINT)i);                                   //~v803R~
    *(subdelm+i-1)='\n';                                           //~v803I~
    *(subdelm+i)=0;                                                //~v803I~
#endif                                                             //~v97mI~
    if (line+2>=maxline)	//no 3line space                       //~v801I~
    	printhdr();                                                //~v801I~
  	XPsetucsOFF_()	//parm to datapline:utf strlen                 //~v928I~
	Gxpotheropt|=GOO_MONOSPACELINE;	//parm to lnx_textout          //~v97hR~
#ifdef GTKPRINT                                                    //~v97mI~
	datapline(subdelm,1,lendelm,output);                           //~v97mR~
#else                                                              //~v97mI~
	datapline(subdelm,1,i,output);                                 //~v803R~
#endif                                                             //~v97mI~
	Gxpotheropt&=~GOO_MONOSPACELINE;	//parm to lnx_textout      //~v97mI~
	Gxpotheropt|=GOO_FILENAMESUBHDR;	//parm to lnx_textout      //~v97mR~
	datapline(headersw,1,i,output);                                //~v803R~
	Gxpotheropt&=~GOO_FILENAMESUBHDR;	//parm to lnx_textout      //~v97mR~
	Gxpotheropt|=GOO_MONOSPACELINE;	//parm to lnx_textout          //~v97mI~
#ifdef GTKPRINT                                                    //~v97mI~
	datapline(subdelm,1,lendelm,output);                           //~v97mR~
#else                                                              //~v97mI~
	datapline(subdelm,1,i,output);                                 //~v803R~
#endif                                                             //~v97mI~
	Gxpotheropt&=~GOO_MONOSPACELINE;	//parm to lnx_textout      //~v97hR~
    line+=3;                                                       //~v803I~
    return;                                                        //~v801I~
}//printsubhdr                                                     //~v801I~
#ifdef GTKPRINT                                                    //~v97mI~
//**********************************************************************//~v97mI~
// heder0edit_utf8:column chk for utf8 filename                    //~v97mI~
//**********************************************************************//~v97mI~
void chkhdrfnm_utf8(int Popt,char *Phdr,int Plen,int Plinewidth)   //~v97mI~
{                                                                  //~v97mI~
    char *pc2,*pc,*pendfnm,*ppagefld,*pstartfnm,*phdr;             //~v97mR~
	int ucsctr,width,fnmfldwidth,ucsctr2,len,diff,pospage,posstartfnm,posendfnm,lenattr,lenpage;//~v97mR~
	int reduceerrsw=0,lentrailer,fnmwidth,width2,utf8len;          //~v97mR~
    WUCS *pucs0;                                                   //~v97mR~
	char utf8wk[MAXLINEWIDTH];                                     //~v97mI~
	WUCS ucswk[MAXLINEWIDTH];                                      //~v97mI~
//****************                                                 //~v97mI~
    UTRACEP("chkhdrfnm_utf8 opt=%x,phase2sw=%d\n",Popt,phase2sw);  //~v97mR~
    Gxpotheropt&=~GOO_HEADERUCS;                                   //~v97mI~
    if (!phase2sw)                                                 //~v97mI~
    	return;                                                    //~v97mR~
    phdr=Phdr;                                                     //~v97mR~
    utf8len=Plen;                                                  //~v97mR~
    UTRACED("chkhdrfnm_utf8",phdr,utf8len);                        //~v97mI~
    pucs0=header0ucs;                                              //~v97mI~
    if (xputf_f2u(phdr,utf8len,pucs0,&ucsctr,&width))              //~v97mR~
    {                                                              //~v97mI~
        UTRACEP("chkhdrfnm_utf8 all ascii or cv err\n");           //~v97mR~
    	return;	//all ascii or utf8 err                            //~v97mI~
    }                                                              //~v97mI~
    Gxpotheropt|=GOO_HEADERUCS;                                    //~v97mR~
    UTRACEP("chkhdrfnm_utf8 ucshdr\n");                            //~v97mI~
//  ppagefld=umemrstr(phdr," PAGE=",utf8len);                      //~v97mR~//~v997R~
//  ppagefld=umemrstr(phdr," PAGE=",(size_t)utf8len);              //~v997I~//~v9a1R~
    ppagefld=umemrstr(phdr," PAGE=",(unsigned)utf8len);            //~v9a1I~
    pospage=PTRDIFF(ppagefld,phdr);                                //~v97mR~
    lenpage=utf8len-pospage;                                       //~v97mR~
    pageposucs=width-lenpage+6;                                    //~v97mM~
    if (width<Plinewidth)                                          //~v97mI~
    {                                                              //~v97mI~
    	diff=Plinewidth-width;                                     //~v97mR~
//  	memmove(pucs0+diff,pucs0,width*WUCSSZ);                    //~v97mR~//~v997R~
    	memmove(pucs0+diff,pucs0,(size_t)(width*WUCSSZ));          //~v997I~
        header0ucsctr=diff+width;                                  //~v97mI~
	    pageposucs+=diff;                                          //~v97mI~
//      wmemset(pucs0,' ',diff);                                   //~v97mR~//~v997R~
        wmemset(pucs0,' ',(size_t)diff);                           //~v997I~
        UTRACEP("chkhdrfnm_utf8 shrink len,ucsctr=%d \n",header0ucsctr);//~v97mR~
        UTRACED("chkhdrfnm_utf8 ucs",pucs0,header0ucsctr*WUCSSZ);  //~v97mR~
    	return;                                                    //~v97mI~
    }                                                              //~v97mI~
//  pendfnm=umemrchr(phdr,'(',pospage);                            //~v97mR~//~v997R~
    pendfnm=umemrchr(phdr,'(',(size_t)pospage);                    //~v997I~
    posendfnm=PTRDIFF(pendfnm,phdr);                               //~v97mR~
//  len=umemrspnc(phdr,' ',posendfnm);                             //~v97mR~//~v997R~
    len=(int)umemrspnc(phdr,' ',(UINT)posendfnm);                  //~v997R~
    pendfnm-=len;                                                  //~v97mI~
    posendfnm-=len;                                                //~v97mI~
    lenattr=pospage-posendfnm;                                     //~v97mM~
    lentrailer=utf8len-posendfnm;                                  //~v97mR~
    pstartfnm=phdr;                                                //~v97mR~
    posstartfnm=0;                                                 //~v97mR~
    fnmfldwidth=Plinewidth-lentrailer;                             //~v97mI~
    fnmwidth=width-lentrailer;                                     //~v97mR~
    for (pc=pstartfnm+1;;)							//cut from root dir name//~v97mI~
	{                                                              //~v97mI~
    	len=PTRDIFF(pendfnm,pc);                                   //~v97mI~
//  	if (!(pc2=memchr(pc,DIR_SEPC,len)))		//search '/'       //~v97mR~//~v997R~
    	if (!(pc2=memchr(pc,DIR_SEPC,(size_t)len)))		//search '/'//~v997I~
        {                                                          //~v97mI~
            reduceerrsw=1;                                         //~v97mI~
            break;                                                 //~v97mI~
        }                                                          //~v97mI~
        len-=PTRDIFF(pc2,pc);                                      //~v97mI~
        memcpy(utf8wk,"...",3);                                    //~v97mI~
//      memcpy(utf8wk+3,pc2,len);                                  //~v97mI~//~v997R~
        memcpy(utf8wk+3,pc2,(size_t)len);                          //~v997I~
    	xputf_f2u(utf8wk,len+3,ucswk,&ucsctr2,&width2);            //~v97mR~
        diff=fnmfldwidth-width2;                                   //~v97mI~
        if (diff>=0)                                               //~v97mI~
        {                                                          //~v97mI~
//      	memcpy(pucs0+diff,ucswk,ucsctr2*WUCSSZ);               //~v97mR~//~v997R~
        	memcpy(pucs0+diff,ucswk,(size_t)(ucsctr2*WUCSSZ));     //~v997I~
//      	memcpy(pucs0+diff+ucsctr2,pucs0+width-lentrailer,lentrailer*WUCSSZ);//~v97mR~//~v997R~
        	memcpy(pucs0+diff+ucsctr2,pucs0+width-lentrailer,(size_t)(lentrailer*WUCSSZ));//~v997I~
	        header0ucsctr=diff+ucsctr2+lentrailer;                 //~v97mI~
		    pageposucs=header0ucsctr-lenpage+6;                    //~v97mI~
//      	wmemset(pucs0,L' ',diff);                              //~v97mR~//~v997R~
        	wmemset(pucs0,L' ',(size_t)diff);                      //~v997I~
	        UTRACEP("chkhdrfnm_utf8 shorten fnm,ucsctr=%d,pageposucs=%d\n",header0ucsctr,pageposucs);//~v97mR~
	        UTRACED("chkhdrfnm_utf8 ucs",pucs0,header0ucsctr*WUCSSZ);//~v97mR~
            break;                                                 //~v97mI~
        }                                                          //~v97mI~
        pc=pc2+1;                                                  //~v97mI~
	}                                                              //~v97mI~
    if (reduceerrsw)	//cannot reduce long file name             //~v97mI~
    {                                                              //~v97mI~
	    fnmfldwidth+=lenattr;                                      //~v97mI~
	    diff=fnmfldwidth-fnmwidth;	//available space before fnm   //~v97mI~
	    if (diff>=0)                                               //~v97mI~
    	{                                                          //~v97mI~
//  		memmove(pucs0+diff,pucs0+posstartfnm,fnmwidth*WUCSSZ); //~v97mR~//~v997R~
    		memmove(pucs0+diff,pucs0+posstartfnm,(size_t)(fnmwidth*WUCSSZ));//~v997I~
//  		memcpy(pucs0+diff+fnmwidth,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~//~v997R~
    		memcpy(pucs0+diff+fnmwidth,pucs0+width-lenpage,(size_t)(lenpage*WUCSSZ));//~v997I~
	        header0ucsctr=diff+fnmwidth+lenpage;                   //~v97mI~
		    pageposucs=header0ucsctr-lenpage+6;                    //~v97mI~
	        UTRACEP("chkhdrfnm_utf8 dropped attr\n");              //~v97mR~
	        UTRACED("chkhdrfnm_utf8 ucs",pucs0,header0ucsctr*WUCSSZ);//~v97mR~
        	return;                                                //~v97mI~
    	}                                                          //~v97mI~
        memcpy(utf8wk,"...",3);                                    //~v97mI~
//      memcpy(utf8wk+3,pc,len);                                   //~v97mI~//~v997R~
        memcpy(utf8wk+3,pc,(size_t)len);                           //~v997I~
    	xputf_f2u(utf8wk,len+3,ucswk,&ucsctr2,&width2);            //~v97mR~
        diff=fnmfldwidth-width2;                                   //~v97mI~
        UTRACEP("chkhdrfnm reduceerr diff=%d,fnmfldwidth=%d,width2=%d\n",diff,fnmfldwidth,width2);//~v97mI~
        if (diff>=0)                                               //~v97mI~
        {                                                          //~v97mI~
//      	memcpy(pucs0+diff,ucswk,ucsctr2*WUCSSZ);               //~v97mR~//~v997R~
        	memcpy(pucs0+diff,ucswk,(size_t)(ucsctr2*WUCSSZ));     //~v997I~
            UTRACED("page",pucs0+width-lenpage,lenpage*WUCSSZ);    //~v97mR~
//  	    memcpy(pucs0+diff+ucsctr2,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~//~v997R~
    	    memcpy(pucs0+diff+ucsctr2,pucs0+width-lenpage,(size_t)(lenpage*WUCSSZ));//~v997I~
	        header0ucsctr=diff+ucsctr2+lenpage;                    //~v97mI~
		    pageposucs=header0ucsctr-lenpage+6;                    //~v97mI~
            UTRACEP("diff=%d,ucsctr2=%d,lenpage=%d,width=%d,pospage=%d,header0ucsctr=%d,pageposucs=%d\n",diff,ucsctr2,lenpage,width,pospage,header0ucsctr,pageposucs);//~v97mI~
//          wmemset(pucs0,' ',diff);                               //~v97mI~//~v997R~
            wmemset(pucs0,' ',(size_t)diff);                       //~v997I~
	        UTRACEP("chkhdrfnm_utf8 dropped attr & shorten fnm\n");//~v97mR~
	        UTRACED("chkhdrfnm_utf8 ucs",pucs0,header0ucsctr*WUCSSZ);//~v97mR~
        }                                                          //~v97mI~
        else                                                       //~v97mI~
        if (fnmfldwidth>=0)                                        //~v97mI~
        {                                                          //~v97mI~
            diff=-diff;                                            //~v97mI~
//      	memcpy(pucs0,ucswk+diff,(ucsctr2-diff)*WUCSSZ);        //~v97mR~//~v997R~
        	memcpy(pucs0,ucswk+diff,(size_t)((ucsctr2-diff)*WUCSSZ));//~v997I~
//  	    memcpy(pucs0+ucsctr2-diff,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~//~v997R~
    	    memcpy(pucs0+ucsctr2-diff,pucs0+width-lenpage,(size_t)(lenpage*WUCSSZ));//~v997I~
	        header0ucsctr=ucsctr2-diff+lenpage;                    //~v97mI~
		    pageposucs=header0ucsctr-lenpage+6;                    //~v97mI~
            UTRACEP("diff=%d,ucsctr2=%d,lenpage=%d,width=%d,pospage=%d,header0ucsctr=%d,pageposucs=%d\n",diff,ucsctr2,lenpage,width,pospage,header0ucsctr,pageposucs);//~v97mI~
	        UTRACEP("chkhdrfnm_utf8 dropped attr & cut fnm\n");    //~v97mI~
	        UTRACED("chkhdrfnm_utf8 ucs",pucs0,header0ucsctr*WUCSSZ);//~v97mR~
        }                                                          //~v97mI~
        else                                                       //~v97mI~
        {                                                          //~v97mI~
        	if (Plinewidth>lenpage)                                //~v97mI~
            {                                                      //~v97mI~
            	diff=Plinewidth-lenpage;                           //~v97mR~
//  	    	memcpy(pucs0+diff,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~//~v997R~
    	    	memcpy(pucs0+diff,pucs0+width-lenpage,(size_t)(lenpage*WUCSSZ));//~v997I~
//  	        wmemset(pucs0,' ',diff);                           //~v97mI~//~v997R~
    	        wmemset(pucs0,' ',(size_t)diff);                   //~v997I~
	        	header0ucsctr=Plinewidth;                          //~v97mR~
		    	pageposucs=header0ucsctr-lenpage+6;                //~v97mR~
		        UTRACEP("chkhdrfnm_utf8 dropped attr & cut all fnm\n");//~v97mI~
            }                                                      //~v97mI~
            else                                                   //~v97mI~
            {                                                      //~v97mI~
            	diff=lenpage-Plinewidth;                           //~v97mI~
		    	len=lenpage-diff;                                  //~v97mI~
//  	    	memcpy(pucs0,pucs0+width-len,len*WUCSSZ);          //~v97mR~//~v997R~
    	    	memcpy(pucs0,pucs0+width-len,(size_t)(len*WUCSSZ));//~v997I~
	        	header0ucsctr=len;                                 //~v97mI~
		    	pageposucs=header0ucsctr-lenpage+6;                //~v97mI~
		        UTRACEP("chkhdrfnm_utf8 dropped attr & cut page\n");//~v97mI~
            }                                                      //~v97mI~
            UTRACEP("diff=%d,ucsctr2=%d,lenpage=%d,width=%d,pospage=%d,header0ucsctr=%d,pageposucs=%d\n",diff,ucsctr2,lenpage,width,pospage,header0ucsctr,pageposucs);//~v97mI~
	        UTRACED("chkhdrfnm_utf8 ucs",pucs0,header0ucsctr*WUCSSZ);//~v97mR~
        }                                                          //~v97mI~
	}                                                              //~v97mI~
    return;                                                        //~v97mI~
}//chkhdrfnm_utf8                                                  //~v97mI~
//**********************************************************************//~v97mI~
// subhdr ucs line setup                                           //~v97mI~
//**********************************************************************//~v97mI~
void subhdredit_utf8(char *Phdr,int Plen,int Plinewidth)           //~v97mI~
{                                                                  //~v97mI~
    char *pc2,*pc,*pendfnm,*pstartfnm,*phdr;                       //~v97mR~
	int ucsctr,width,fnmfldwidth,ucsctr2,len,diff,posstartfnm,posendfnm;//~v97mR~
	int reduceerrsw=0,lentrailer,fnmwidth,width2,utf8len,linewidth;//~v97mR~
    int lenprefix=7;                                               //~v97mI~
    WUCS *pucs0,*pucs00;                                           //~v97mR~
	char utf8wk[MAXLINEWIDTH];                                     //~v97mI~
	WUCS ucswk[MAXLINEWIDTH];                                      //~v97mI~
//****************                                                 //~v97mI~
    UTRACEP("subhdredit_utf8 phase2sw=%d,linewidth=%d\n",phase2sw,Plinewidth);//~v97mI~
    UTRACED("subhdredit_utf8",Phdr,Plen);                          //~v97mI~
    if (!phase2sw)                                                 //~v97mI~
    	return;                                                    //~v97mI~
    phdr=Phdr;                                                     //~v97mI~
    utf8len=Plen;                                                  //~v97mI~
//  pucs00=pucs0=headersucs;                                       //~v9b0R~
    pucs00=headersucs;                                             //~v9b0I~
    pucs0=pucs00;                                                  //~v9b0I~
    if (lineprefixsw)                                              //~v97mI~
		linewidth=Plinewidth-(LINENOSZ+1)-2;       //2: append " =" at eol//~v97mR~
    else                                                           //~v97mI~
		linewidth=Plinewidth-(LINENOSZ+1)*2-2;       //2: append " =" at eol//~v97mI~
//  wmemcpy(pucs0,L"*===== ",lenprefix);                           //~v97mI~//~v997R~
    wmemcpy(pucs0,L"*===== ",(size_t)lenprefix);                   //~v997I~
    pucs0+=lenprefix;                                              //~v97mI~
//    if (xputf_f2u(phdr,utf8len,pucs0,&ucsctr,&width))            //~v97mI~
//    {                                                            //~v97mI~
//        UTRACEP("subhdredit_utf8 all ascii or cv err\n");        //~v97mR~
//        return; //all ascii or utf8 err                          //~v97mI~
//    }                                                            //~v97mI~
    xputf_f2u(phdr,utf8len,pucs0,&ucsctr,&width);	//contains utf8(Gxpotheropt chked)//~v97mI~
//    Gxpotheropt|=GOO_HEADERUCS;                                  //~v97mI~
//    ppagefld=umemrstr(phdr," PAGE=",utf8len);                    //~v97mI~
//    pospage=PTRDIFF(ppagefld,phdr);                              //~v97mI~
//    lenpage=utf8len-pospage;                                     //~v97mI~
//    pageposucs=width-lenpage+6;                                  //~v97mI~
    if (width<linewidth)                                           //~v97mR~
    {                                                              //~v97mI~
    	diff=linewidth-width;                                      //~v97mR~
//  	wmemmove(pucs0+diff,pucs0,width);                          //~v97mR~//~v997R~
    	wmemmove(pucs0+diff,pucs0,(size_t)width);                  //~v997I~
        headersucsctr=diff+width;                                  //~v97mR~
//        pageposucs+=diff;                                        //~v97mR~
//  	wmemset(pucs0,' ',diff);                                   //~v97mI~//~v997R~
    	wmemset(pucs0,' ',(size_t)diff);                           //~v997I~
        wmemcpy(pucs0+headersucsctr,L" =",2);                      //~v97mI~
        headersucsctr+=lenprefix+2;                                //~v97mI~
        UTRACEP("subhdredit_utf8 shrink len,ucsctr=%d \n",headersucsctr);//~v97mR~
        UTRACED("subhdredit_utf8 ucs",pucs00,headersucsctr*WUCSSZ);//~v97mR~
    	return;                                                    //~v97mI~
    }                                                              //~v97mI~
//  pendfnm=umemrchr(phdr,'(',utf8len);                            //~v97mR~//~v997R~
    pendfnm=umemrchr(phdr,'(',(size_t)utf8len);                    //~v997I~
    posendfnm=PTRDIFF(pendfnm,phdr);                               //~v97mI~
//  len=umemrspnc(phdr,' ',posendfnm);                             //~v97mI~//~v997R~
    len=(int)umemrspnc(phdr,' ',(UINT)posendfnm);                  //~v997R~
    pendfnm-=len;                                                  //~v97mI~
    posendfnm-=len;                                                //~v97mI~
    lentrailer=utf8len-posendfnm;                                  //~v97mI~
    pstartfnm=phdr;                                                //~v97mI~
    posstartfnm=0;                                                 //~v97mI~
    fnmfldwidth=linewidth-lentrailer;                              //~v97mR~
    fnmwidth=width-lentrailer;                                     //~v97mI~
    for (pc=pstartfnm+1;;)							//cut from root dir name//~v97mI~
	{                                                              //~v97mI~
    	len=PTRDIFF(pendfnm,pc);                                   //~v97mI~
//  	if (!(pc2=memchr(pc,DIR_SEPC,len)))		//search '/'       //~v97mI~//~v997R~
    	if (!(pc2=memchr(pc,DIR_SEPC,(size_t)len)))		//search '/'//~v997I~
        {                                                          //~v97mI~
            reduceerrsw=1;                                         //~v97mI~
            break;                                                 //~v97mI~
        }                                                          //~v97mI~
        len-=PTRDIFF(pc2,pc);                                      //~v97mI~
        memcpy(utf8wk,"...",3);                                    //~v97mI~
//      memcpy(utf8wk+3,pc2,len);                                  //~v97mI~//~v997R~
        memcpy(utf8wk+3,pc2,(size_t)len);                          //~v997I~
    	xputf_f2u(utf8wk,len+3,ucswk,&ucsctr2,&width2);            //~v97mI~
        diff=fnmfldwidth-width2;                                   //~v97mI~
        if (diff>=0)                                               //~v97mI~
        {                                                          //~v97mI~
//      	wmemcpy(pucs0+diff,ucswk,ucsctr2);                     //~v97mR~//~v997R~
        	wmemcpy(pucs0+diff,ucswk,(size_t)ucsctr2);             //~v997I~
//      	wmemcpy(pucs0+diff+ucsctr2,pucs0+width-lentrailer,lentrailer);//~v97mR~//~v997R~
         	wmemcpy(pucs0+diff+ucsctr2,pucs0+width-lentrailer,(size_t)lentrailer);//~v997I~
	        headersucsctr=diff+ucsctr2+lentrailer;                 //~v97mR~
//            pageposucs=headersucsctr-lenpage+6;                  //~v97mR~
//  		wmemset(pucs0,' ',diff);                               //~v97mI~//~v997R~
    		wmemset(pucs0,' ',(size_t)diff);                       //~v997I~
	        wmemcpy(pucs0+headersucsctr,L" =",2);                  //~v97mI~
        	headersucsctr+=lenprefix+2;                            //~v97mI~
	        UTRACEP("subhdredit_utf8 shorten fnm,ucsctr=%d\n",headersucsctr);//~v97mR~
	        UTRACED("subhdredit_utf8 ucs",pucs00,headersucsctr*WUCSSZ);//~v97mR~
            break;                                                 //~v97mI~
        }                                                          //~v97mI~
        pc=pc2+1;                                                  //~v97mI~
	}                                                              //~v97mI~
    if (reduceerrsw)	//cannot reduce long file name             //~v97mI~
    {                                                              //~v97mI~
	    fnmfldwidth+=lentrailer;                                   //~v97mR~
	    diff=fnmfldwidth-fnmwidth;	//available space before fnm   //~v97mI~
	    if (diff>=0)                                               //~v97mI~
    	{                                                          //~v97mI~
//  		wmemmove(pucs0+diff,pucs0+posstartfnm,fnmwidth);       //~v97mR~//~v997R~
    		wmemmove(pucs0+diff,pucs0+posstartfnm,(size_t)fnmwidth);//~v997I~
//            memcpy(pucs0+diff+fnmwidth,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~
	        headersucsctr=diff+fnmwidth;                           //~v97mR~
	        wmemcpy(pucs0+headersucsctr,L" =",2);                  //~v97mI~
        	headersucsctr+=lenprefix+2;                            //~v97mI~
//            pageposucs=header0ucsctr-lenpage+6;                  //~v97mR~
	        UTRACEP("subhdredit_utf8 dropped attr\n");             //~v97mR~
	        UTRACED("subhdredit_utf8 ucs",pucs00,headersucsctr*WUCSSZ);//~v97mR~
        	return;                                                //~v97mI~
    	}                                                          //~v97mI~
        memcpy(utf8wk,"...",3);                                    //~v97mI~
//      memcpy(utf8wk+3,pc,len);                                   //~v97mI~//~v997R~
        memcpy(utf8wk+3,pc,(size_t)len);                           //~v997I~
    	xputf_f2u(utf8wk,len+3,ucswk,&ucsctr2,&width2);            //~v97mI~
        diff=fnmfldwidth-width2;                                   //~v97mI~
        UTRACEP("subhdredit reduceerr diff=%d,fnmfldwidth=%d,width2=%d\n",diff,fnmfldwidth,width2);//~v97mR~
        if (diff>=0)                                               //~v97mI~
        {                                                          //~v97mI~
//      	wmemcpy(pucs0+diff,ucswk,ucsctr2);                     //~v97mR~//~v997R~
        	wmemcpy(pucs0+diff,ucswk,(size_t)ucsctr2);             //~v997I~
//            memcpy(pucs0+diff+ucsctr2,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~
	        headersucsctr=diff+ucsctr2;                            //~v97mR~
//            pageposucs=header0ucsctr-lenpage+6;                  //~v97mR~
	        wmemcpy(pucs0+headersucsctr,L" =",2);                  //~v97mI~
        	headersucsctr+=lenprefix+2;                            //~v97mI~
            UTRACEP("diff=%d,ucsctr2=%d,width=%d,headersucsctr=%d\n",diff,ucsctr2,width,headersucsctr);//~v97mR~
//  		wmemset(pucs0,' ',diff);                               //~v97mI~//~v997R~
    		wmemset(pucs0,' ',(size_t)diff);                       //~v997I~
	        UTRACEP("subhdredit_utf8 dropped attr & shorten fnm\n");//~v97mR~
	        UTRACED("subhdredit_utf8 ucs",pucs00,headersucsctr*WUCSSZ);//~v97mR~
        }                                                          //~v97mI~
        else                                                       //~v97mI~
        {                                                          //~v97mI~
            diff=-diff;                                            //~v97mI~
//      	wmemcpy(pucs0,ucswk+diff,(ucsctr2-diff));              //~v97mR~//~v997R~
        	wmemcpy(pucs0,ucswk+diff,(size_t)(ucsctr2-diff));      //~v997I~
//            memcpy(pucs0+ucsctr2-diff,pucs0+width-lenpage,lenpage*WUCSSZ);//~v97mR~
	        headersucsctr=ucsctr2-diff;                            //~v97mR~
//            pageposucs=headersucsctr-lenpage+6;                  //~v97mR~
	        wmemcpy(pucs0+headersucsctr,L" =",2);                  //~v97mI~
        	headersucsctr+=lenprefix+2;                            //~v97mI~
            UTRACEP("diff=%d,ucsctr2=%d,width=%d,headersucsctr=%d\n",diff,ucsctr2,width,headersucsctr);//~v97mR~
	        UTRACEP("subhdredit_utf8 dropped attr & cut fnm\n");   //~v97mR~
	        UTRACED("subhdredit_utf8 ucs",pucs00,headersucsctr*WUCSSZ);//~v97mR~
        }                                                          //~v97mI~
	}                                                              //~v97mI~
    return;                                                        //~v97mI~
}//subhdredit_utf8                                                 //~v97mR~
#endif                                                             //~v97mI~
//**********************************************************************//~v801I~
// heder0edit:for long file name,shorten according to line width   //~v801I~
//**********************************************************************//~v801I~
void header0edit(void)                                             //~v831R~
{                                                                  //~v801I~
	int i;                                                         //~v801I~
    int reduceerrsw=0;	                                           //~v911I~
    char *pc2;                                                     //~v911I~
    char *pc;                                                      //~v801I~
static int Sretrysw=0;                                             //~v91rR~
	int header0len;                                                //~v96fI~
    char *pagefld;                                                 //~v96gR~
//****************                                                 //~v801I~
	i=header0fnw;                                                  //~v801I~
//  if ((int)strlen(header0)>=i)	//line width overflow          //~v801I~//~v96fR~
    header0len=(int)strlen(header0);                               //~v96fI~
    UTRACED("header0edit",header0,header0len);                     //~v97mI~
#if GTKPRINT                                                       //~v97mI~
    if (!Sretrysw)                                                 //~v97mI~
//      chkhdrfnm_utf8(0,header0utf8,strlen(header0utf8),i);       //~v97mR~//~v997R~
        chkhdrfnm_utf8(0,header0utf8,(int)strlen(header0utf8),i);  //~v997I~
#endif                                                             //~v97mI~
    if (header0len>=i)	//line width overflow                      //~v96fI~
    {                                                              //~v801I~
		pagefld=ustrrstr(header0,"PAGE=");                         //~v96gR~
    	for (pc=header0;;)							//cut from root dir name//~v801I~
		{                                                          //~v801I~
        	pc++;                                                  //~v801I~
//      	if (!(pc=ustrchr2(pc,'\\')))		//search '\' not DBCS 2nd byte//~v907R~
        	if (!(pc=ustrchr2(pc,DIR_SEPC)))		//search '\' not DBCS 2nd byte//~v907I~
            {                                                      //~v911I~
            	reduceerrsw=1;                                     //~v911I~
            	break;                                             //~v801I~
            }                                                      //~v911I~
//printf("i=%d,strlen=%d\n",i,strlen(pc));                         //~v801I~
            if (pc>pagefld)     // "/" of PAGE=n/m                 //~v96gR~
            {                                                      //~v96gI~
            	reduceerrsw=1;                                     //~v96gI~
            	break;                                             //~v96gI~
            }                                                      //~v96gI~
    		if (pc>=(header0+5) && ((int)strlen(pc)+5)<i)	//space for 'd:...' to be added//~v801I~
            {                                                      //~v801I~
            	memcpy(header0+2,"...",3);                         //~v801I~
                strcpy(header0+5,pc);		//drop preceding pathname//~v801I~
				pc=strrchr(header0,'='); 	//PAGE=                //~v801I~
                if (pc)                                            //~v801I~
//					pagepos =(INT)((ULONG)pc+1-(ULONG)header0);    //~v801I~//~v968R~
					pagepos =(INT)((ULPTR)pc+1-(ULPTR)header0);    //~v968I~
            	break;                                             //~v801I~
			}                                                      //~v801I~
		}                                                          //~v801I~
        if (reduceerrsw)	//cannot reduce long file name         //~v911I~
        {                                                          //~v911I~
        	if (Sretrysw)                                          //~v911I~
            	return;		//loop protection                      //~v911I~
//drop byte and t/s then retry reduce                              //~v911I~
//  		pc=ustrrstr(header0,"PAGE=");                          //~v911R~//~v96gR~
            pc=pagefld;                                            //~v96gR~
			pc2=strrchr(header0,'(');                              //~v911I~
            if (pc && pc2 && pc2<pc)                               //~v911I~
            {                                                      //~v911I~
            	strcpy(pc2,pc);                                    //~v911I~
//				pagepos-=(int)((ULONG)pc-(ULONG)pc2);	//page pos changed//~v911I~//~v968R~
				pagepos-=(int)((ULPTR)pc-(ULPTR)pc2);	//page pos changed//~v968I~
                Sretrysw=1;                                        //~v911I~
                header0edit();                                     //~v911I~
                Sretrysw=0;                                        //~v911I~
                return;                                            //~v911I~
            }                                                      //~v911I~
        }                                                          //~v911I~
	}                                                              //~v801I~
	header0w[0]=FORMFEED;							//page eject v5.3a//~v801I~
  	memcpy(header0w+1,esccmd,(UINT)esccmdlen);      	//set esc cmd v5.3a v7.0r//~v801I~
    return;                                                        //~v801I~
}//header0edit                                                     //~v801I~
//**********************************************************************
// print header v6.7a
//**********************************************************************
void printhdr(void)
{
    int ii;                                                     //~v74fI~
    int pageupsw=1;                                                //~v911R~
//****************
    Gpage2p++;    	//count 2/form                           //v1.1add//~v911I~
  	if (UCBITCHK(swsw3,SW3FORM2P))                                 //~v911I~
    	pageupsw=Gpage2p%2; 	//1up/form                         //~v911I~
  	XPsetucsOFF_()	//parm to datapline:utf strlen                 //~v928I~
	if (header1outsw)	//v7.12a
		datapline(header1,sizeof(char),header1len,output);//v3.2add v3.5r v6.7av7.12r
  if (pageupsw)                                                    //~v911R~
  {                                                                //~v911I~
#if defined(W32) || defined(UNX)                                   //~v950I~
  	breakchk(0);			//Esc key chk and set sw               //~v950I~
#endif                                                             //~v950I~
  	breakchk(1);			//exit if Esc is already input at page eject timing//~v808R~
    page++;                                 //v1.1add
  }                                                                //~v911I~
    breakpage=page;         //parm to breakmsg,print start page    //~v850I~
    if (page>=pagestart && page <=pageend)  //v3.2add
    {                                                           //~v74hR~
  		if (!pagerangectr || pagefilesw==3)		//restart file specified//~v74iR~
        	pagesw=1; //print bypass sw //v3.2add               //~v74hI~
        else                                                    //~v74hI~
	        for (pagesw=0,ii=0;ii<pagerangectr;ii+=2)           //~v74hR~
    	    {                                                   //~v74hR~
        	    if (page>=pagerange[ii] && page<=pagerange[ii+1])//~v74hR~
           	 	{                                               //~v74hR~
    				pagesw=1;//once page printed //v3.2add      //~v74hR~
                	break;                                      //~v74hR~
            	}                                               //~v74hR~
        	}                                                   //~v74hR~
    }                                                           //~v74hR~
    else //v3.2add
        pagesw=0; //print bypass sw //v3.2add

  if (pageupsw)                                                    //~v911I~
    if (pagesw)                                                 //~v74hI~
        realpage++;             //actual write page count       //~v74hI~
//  if (fastpathsw)				//phase2 only v7.26a               //~v803R~
//      sprintf(header0+pagepos,"%4d.",page);    //v7.26a          //~v803R~
//  else						//2 phase run v7.26a               //~v803R~
//      sprintf(header0+pagepos,"%4d / %d",page,lastpage);    //v1.1add v4.4r v4.6r v4.7r//~v803R~
//  pagenoedit();                                                  //~v803I~//~v97mR~
    pagenoedit(0);                                                 //~v97mI~
  	sprintf(header0w+1+esccmdlen,header0wp,header0);	//right justify v4.7a v5.3a

	hdr0linesw=1;	    	//parm to ufwrte,deswkfwrite,new page timing//~v855R~
	if (header0outsw)	//v7.12a
    {                                                              //~v97mI~
//      pline(header0w+skip1stff2,sizeof(char),(INT)(1+esccmdlen+strlen(header0w+1+esccmdlen)),output);//v5.3av7.0r//~v855R~
		Gxpotheropt|=GOO_FILENAMEHDR;                              //~v97mI~
//      pline(header0w+skip1stff2,sizeof(char),(INT)(1-skip1stff2+esccmdlen+strlen(header0w+1+esccmdlen)),output);//v5.3av7.0r//~v855R~//~v997R~
        pline(header0w+skip1stff2,sizeof(char),(INT)(1-skip1stff2+esccmdlen+(int)strlen(header0w+1+esccmdlen)),output);//v5.3av7.0r//~v997I~
		Gxpotheropt&=~GOO_FILENAMEHDR;                             //~v97mI~
    }                                                              //~v97mI~
	else									//v7.12a		
//      pline(header0w+skip1stff2,sizeof(char),(INT)(1+esccmdlen),output);//v7.12a//~v855R~
        pline(header0w+skip1stff2,sizeof(char),(INT)(1-skip1stff2+esccmdlen),output);//v7.12a//~v855R~
	hdr0linesw=0;	    	//parm to ufwrte,deswkfwrite,new page timing//~v855R~
  if (pagesw)                                                      //~v882I~
	skip1stff2=0;		//skip first page formfeed cmd             //~v785R~

  	XPsetucsOFF_()	//parm to datapline:utf strlen                 //~v928I~
	if (header1outsw)	//v7.12a
		datapline(header1,sizeof(char),header1len,output);//v3.2rep v3.5r v6.7rv7.12r
	else									//v7.12a		
		if (header0outsw)					//v7.29a
		    pline("\n",sizeof(char),1,output);//1 space line v7.12a
    line=0;
}//printhdr
//********************************************************************//~v803I~
//* pagenoedit                                                     //~v803I~
//*   from printhdr and openinput                                  //~v803I~
//********************************************************************//~v803I~
//void pagenoedit(void)                                              //~v803I~//~v97mR~
void pagenoedit(int Popt)                                          //~v97mI~
{                                                                  //~v803I~
#ifdef GTKPRINT                                                    //~v97mI~
	WUCS *pucs;                                                    //~v97mI~
    char *pc;                                                      //~v97mI~
    int len,len1,len2;                                             //~v97mR~
    char wk[32];                                                   //~v97mI~
static char Sheader0utf8pageedit[32];                              //~v97mR~
static int Sheader0utf8pagepos;                                    //~v97mI~
#endif                                                             //~v97mI~
//************************************                             //~v97mI~
	if (fastpathsw)				//phase2 only v7.26a               //~v803I~
	    sprintf(header0+pagepos,"%4d.",page);    //v7.26a          //~v803I~
	else						//2 phase run v7.26a               //~v803I~
	    sprintf(header0+pagepos,"%4d / %d",page,lastpage);    //v1.1add v4.4r v4.6r v4.7r//~v803I~
#ifdef GTKPRINT                                                    //~v97mI~
    UTRACEP("pagenoedit opt=%x,phase2sw=%d,page=%d,lastpage=%d\n",Popt,phase2sw,page,lastpage);//~v97mR~
    UTRACED("pagenoedit header0",header0,(int)strlen(header0));         //~v97mI~//~v997R~
    if (Popt & PNEO_OPENINPUT)  //from openinput                   //~v97mI~
    {                                                              //~v97mI~
        strcpy(header0utf8,header0);                               //~v97mI~
        strcpy(headersutf8,headers);                               //~v97mI~
        Sheader0utf8pagepos=pagepos;                               //~v97mI~
    }                                                              //~v97mI~
    UTRACED("pagenoedit header0utf8",header0utf8,(int)strlen(header0utf8));//~v97mI~//~v997R~
    UTRACED("pagenoedit headersutf8",headersutf8,(int)strlen(headersutf8));//~v97mI~//~v997R~
    if (!phase2sw)                                                 //~v97mI~
    {                                                              //~v97mI~
    	len1=sprintf(wk,"%4d",page);                               //~v97mR~
    	len2=sprintf(wk,"%d",page);                                //~v97mR~
        sprintf(Sheader0utf8pageedit,"%%%dd / %%%dd",max(4,len1),len2);//~v97mR~
        UTRACED("pagenoedit pageno sprintf",Sheader0utf8pageedit,(int)strlen(Sheader0utf8pageedit));//~v97mR~//~v997R~
	    sprintf(header0utf8+Sheader0utf8pagepos,Sheader0utf8pageedit,page,lastpage);    //with last page,longest hdr//~v97mR~
    }                                                              //~v97mI~
    else                                                           //~v97mI~
    if (Gxpotheropt & GOO_HEADERUCS)                               //~v97mI~
    {                                                              //~v97mI~
    	sprintf(wk,Sheader0utf8pageedit,page,lastpage);            //~v97mI~
    	for (pc=wk,pucs=header0ucs+pageposucs;*pc;)                //~v97mR~
	    	*pucs++=*pc++;                                         //~v97mI~
//      len=strlen(wk);                                            //~v97mR~//~v997R~
        len=(int)strlen(wk);                                       //~v997I~
        header0ucsctr=pageposucs+len;                              //~v97mR~
        UTRACED("pagenoedit ucs",header0ucs,header0ucsctr*WUCSSZ); //~v97mR~
    }                                                              //~v97mI~
#endif                                                             //~v97mI~
}//pagenoedit                                                      //~v803I~
#ifdef W32                                                         //~v993M~
//**********************************************************************//~v993M~
//* translate ucs4 to utf16 before call datapline_ucs              //~v993M~
//**********************************************************************//~v993M~
void datapline_ucs4(UCHAR *Pbuff,UWUCS *Ppucs4,int Pcount,FILE* file)//~v993M~
{                                                                  //~v993M~
    int ucs2ctr;                                                   //~v993M~
//*****************                                                //~v993M~
	utfucs42utf16(0,Ppucs4,Pcount,Gbuffucs2,(int)sizeof(Gbuffucs2),&ucs2ctr);//~v993R~
	datapline_ucs(Pbuff,Gbuffucs2,ucs2ctr,file);                   //~v993R~
    return;                                                        //~v993I~
}//datapline_ucs4                                                  //~v993R~
#endif	//W32                                                      //~v993R~
//**********************************************************************
//* 1 data line print v7.12a
//* count:column                                                   //~v928I~
//**********************************************************************
void datapline(void* area,int unit,int count,FILE* file)
{
//**********************                                           //~v90jI~
	UTRACED("datapline",area,unit*count);                          //~v956I~
#ifdef UTF8SUPP                                                    //~v928I~
    if (Gxputfstat & GXPUS_UCSLINE)                                //~v928R~
    {                                                              //~v928I~
#ifdef W32                                                         //~v993I~
		datapline_ucs4(area,Gbuffucs,Gcolumnucs,file);             //~v993I~
#else                                                              //~v993I~
		datapline_ucs(area,Gbuffucs,Gcolumnucs,file);              //~v928R~
#endif                                                             //~v993I~
        return;                                                    //~v928I~
    }                                                              //~v928I~
    if (Gxputfstat & GXPUS_UCSLINE_EBC)                            //~v955R~
    {                                                              //~v955R~
#ifdef W32                                                         //~v993I~
//  	datapline_ucsebc(0,area,Gbuffucs2,unit*count,file);        //~v993I~//~v995R~
    	datapline_ucsebc(0,area,Gbuffucs2,unit*count,file,(int)sizeof(Gbuffucs2));//~v995I~
#else                                                              //~v993I~
//  	datapline_ucsebc(0,area,Gbuffucs,unit*count,file);         //~v955R~//~v995R~
    	datapline_ucsebc(0,area,Gbuffucs,unit*count,file,(int)sizeof(Gbuffucs));//~v995I~
#endif                                                             //~v993I~
        return;                                                    //~v955R~
    }                                                              //~v955R~
#endif                                                             //~v928I~
	if (lineprefixsw)
		pline(area,unit,count,file);
	else
		pline((void*)((char*)area+LINENOSZ+1),unit,count-LINENOSZ-1,file);
}
#ifdef UTF8SUPP                                                    //~v928I~
//**********************************************************************//~v928I~
//* 1 data line print v7.12a                                       //~v928I~
//* count:column                                                   //~v928I~
//**********************************************************************//~v928I~
//void datapline_ucs(UCHAR *Pbuff,USHORT *Ppucs,int Pcount,FILE* file)//~v928R~//~v950R~
void datapline_ucs(UCHAR *Pbuff,WUCS *Ppucs,int Pcount,FILE* file) //~v950I~
{                                                                  //~v928I~
    int ii;                                                        //~v928I~
//  USHORT *pucs;                                                  //~v928I~//~v950R~
    WUCS   *pucs;                                                  //~v950I~
    UCHAR *pc;                                                     //~v928I~
//**********************                                           //~v928I~
    if (lineprefixsw)                                              //~v928I~
    {                                                              //~v928I~
        for (ii=LINENOSZ+1,pucs=Ppucs,pc=Pbuff;ii>0;ii--) //set line hder by ucs//~v928R~
//          *pucs++=(USHORT)(*pc++);                               //~v928I~//~v950R~
            *pucs++=(WUCS)(*pc++);                                 //~v950I~
//      pline(Ppucs,4,Pcount,file);                                //~v92dR~
//      pline(Ppucs,2,Pcount,file);                                //~v92dI~//~v96CR~
        pline(Ppucs,WUCSSZ,Pcount,file);                     //~v96CI~//~v97mR~
    }                                                              //~v928I~
    else                                                           //~v928I~
//      pline(Ppucs+LINENOSZ+1,4,Pcount-LINENOSZ-1,file);          //~v92dR~
//      pline(Ppucs+LINENOSZ+1,2,Pcount-LINENOSZ-1,file);          //~v92dI~//~v96CR~
        pline(Ppucs+LINENOSZ+1,WUCSSZ,Pcount-LINENOSZ-1,file);//~v96CI~//~v97mR~
    return;                                                        //~v928I~
}//datapline_ucs                                                   //~v928I~
//**********************************************************************//~v955R~
//* print ebc line by ucs                                          //~v955R~
//**********************************************************************//~v955R~
//void datapline_ucsebc(int Popt,UCHAR *Pmbdata,WUCS *Poutucs,int Plen,FILE* file)//~v955R~//~v995R~
void datapline_ucsebc(int Popt,UCHAR *Pmbdata,WUCS *Poutucs,int Plen,FILE* file,int Pbuffsz)//~v995I~
{                                                                  //~v955R~
    int ii,ucsctr,len;                                             //~v955R~
    WUCS   *pucs;                                                  //~v955R~
    UCHAR *pmb;                                                    //~v955R~
//**********************                                           //~v955R~
    pmb=Pmbdata;                                                   //~v955I~
    if (lineprefixsw)                                              //~v955R~
    {                                                              //~v955R~
        for (ii=LINENOSZ+1,pucs=Poutucs;ii>0;ii--) //set line hder by ucs//~v955R~
            *pucs++=(WUCS)(*pmb++);                                //~v955R~
        len=Plen-LINENOSZ-1;                                       //~v955R~
    }                                                              //~v955R~
    else                                                           //~v955R~
    {                                                              //~v955R~
        pmb+=LINENOSZ+1;                                           //~v955I~
        len=Plen-LINENOSZ-1;                                       //~v955I~
    	pucs=Poutucs;                                              //~v955R~
    }                                                              //~v955R~
//  xpebc_setucsline(0,pmb,pucs,len,&ucsctr);                      //~v955R~//~v995R~
    xpebc_setucsline(0,pmb,pucs,len,&ucsctr,Pbuffsz-PTRDIFF(pucs,Poutucs));//~v995I~
    if (lineprefixsw)                                              //~v955R~
    	ucsctr+=LINENOSZ+1;                                        //~v955R~
    pline(Poutucs,WUCSSZ,ucsctr,file);                             //~v955R~
    UTRACED("datapline_ucsebc",Poutucs,ucsctr*WUCSSZ);             //~v956I~
    return;                                                        //~v955R~
}//datapline_ucsebc                                                //~v955R~
#endif                                                             //~v928I~
//**********************************************************************
//* 1 line print if in specified page ***
//**********************************************************************
void pline(void* area,int unit,int count,FILE* file) //v3.5r
{
size_t ufwrite(void* Parea,size_t Punit,size_t Pcount,FILE* Pfile,size_t *Pputlen);//~v91rR~
//    size_t putlen;                                               //~v865R~
#ifdef UTF8SUPP                                                    //~v928I~
	int writelen;                                                  //~v928I~
#endif                                                             //~v928I~
//***********************                                          //~v78cI~
	UTRACED("Parea",area,unit*count);                              //~v9e7R~
#if defined(W32) || defined(UNX)                                   //~v950R~
#else                                                              //~v950I~
  breakchk(0);			//Esc key chk and set sw                   //~v808R~
#endif                                                             //~v950I~
  if (pagesw) 
  {
    if (phase2sw)		//second phase v4.4a
	{//v5.8a
		if (despagesw)		//page descending order print v5.3a
			deswkfwrite(area,unit*count); //save to work file v5.3a
	  	else                  //v5.3a
        {                                                          //~v851I~
#ifdef UTF8SUPP                                                    //~v928I~
		  	writelen=(int)ufwrite(area,(unsigned int)unit,(unsigned int)count,file,0); //v3.5rep v5.3r//~v928I~
            if (writelen!=count && writelen!=unit*count)           //~v928I~
#else                                                              //~v928I~
		  	if (count!=(int)ufwrite(area,(unsigned int)unit,(unsigned int)count,file,0)) //v3.5rep v5.3r//~v855R~
#endif                                                             //~v928I~
			{	//v5.3a
			  printf("count=%d\n",count);                                        //~v865I~//~v97GR~
			  if (dbcsenv)	//DBCS mode 
  				printf("\n%s:%s:%s の出力エラー\n",pgmid,ver,prn);//~v744R~
		  	  else			//SBCS mode
  				printf("\n%s:%s:(%s) write failed\n",pgmid,ver,prn);//~v744R~
          	  uexit(8);                                         //~v742R~
			}//v5.3a
		    onceputsw=1;    	//once write to output to chk at uexit//~v851I~
		}                                                          //~v851I~
	}//v5.8a
	else	//phase 1 v5.8a
    {                                                              //~v855I~
//      if (prntyp==PRINTER_ESCP) //ESCP                           //~v866R~
//      {                                                          //~v866R~
//        ufwrite(area,(unsigned int)unit,(unsigned int)count,file,&putlen);//~v866R~
//        pageoutlen+=((long)putlen);     //may expanded by DBCS sjis conv//~v866R~
//      }                                                          //~v866R~
//      else                                                       //~v866R~
		pageoutlen+=unit*count;	//output length v5.8a
    }                                                              //~v855I~
    printsw=1;
  }
  return;
}//end of pline

//**********************************************************************//~v78cI~
//* write to final output                                          //~v78cI~
//*  convert DBCS Shift-JIS to JIS for ESCP                        //~v78cI~
//**********************************************************************//~v78cI~
size_t ufwrite(void* area,size_t unit,size_t count,FILE* file,size_t *Pputlen)//~v855R~
{                                                                  //~v78cI~
//#ifdef DOS                                                       //~v843R~
#define ESCPDBCSSTART "\x1c\x26"		//[FS]& start DBCS         //~v78cI~
#define ESCPDBCSEND   "\x1c\x2e"		//[FS]. end   DBCS         //~v78cI~
	unsigned char escbuff[MAXLINEWIDTH*5];	//1+2(ESCP start cmd)+2(ESCP end cmd)//~v78cI~
    unsigned char *pci,*pcie,*pco;                                 //~v78cR~
    unsigned int  sjiskanji,jiskanji,olen,olen2;                   //~v78cR~
    int dbcssw;                                                    //~v78cI~
//#endif                                                           //~v843R~
    unsigned char  ch;                                             //~v846I~
    UINT hdrcmdlen,totlen;                                         //~v849R~
//**************************                                       //~v78cI~
//#ifdef DOS                                                       //~v843R~
//  if (prntyp==PRINTER_ESCP)	//ESCP                             //~v846R~
//  {                                                              //~v846R~
//  totlen=unit*count;                                             //~v849I~//~v9a1R~
    totlen=(UINT)(unit*count);                                     //~v9a1I~
    hdrcmdlen=(UINT)(esccmdlen+1-skip1stff2);                      //~v855R~
                                                                   //~v90gI~
    if (hdrcmdlen>totlen)                                          //~v849I~
    	hdrcmdlen=totlen;                                          //~v849I~
    switch(prntyp)                                                 //~v846I~
    {                                                              //~v846I~
    case PRINTER_ESCP:	//ESCP                                     //~v846I~
    	pci=area;                                                  //~v78cI~
//      pcie=pci+unit*count;                                       //~v849R~
        pcie=pci+totlen;                                           //~v849I~
        pco=escbuff;                                               //~v78cI~
        dbcssw=0;                                                  //~v78cR~
//      if (*pci==FORMFEED)     //header line                      //~v855R~
        if (hdr0linesw)     //header line                          //~v855I~
        {                                                          //~v849I~
            memcpy(pco,pci,hdrcmdlen);                             //~v849I~
            pci+=hdrcmdlen;                                        //~v849I~
            pco+=hdrcmdlen;                                        //~v849I~
        }                                                          //~v849I~
    	while(pci<pcie)                                            //~v78cI~
        {                                                          //~v78cI~
        	if	(codepage[*pci]==2)	//dbcs first byte              //~v78cI~
            {                                                      //~v78cI~
            	if (!dbcssw)	//after SBCS                       //~v78cI~
                {                                                  //~v78cI~
                	dbcssw=1;                                      //~v78cI~
                	memcpy(pco,ESCPDBCSSTART,2);                   //~v78cR~
                    pco++;                                         //~v78cI~
                    pco++;                                         //~v78cI~
				}                                                  //~v78cI~
//          	printf("readc=%02x,dbcssw=%02x\n",readc,dbcssw);   //~v78cI~
              	sjiskanji=((unsigned int)*pci<<8)+(unsigned int)*(pci+1);//~v78cR~
#ifdef DOS                                                         //~v843I~
    #ifdef DPMI					//DPMI version                     //~v834I~
              	jiskanji=usjis2jis(sjiskanji);                     //~v834I~
    #else                       //not DPMI                         //~v834I~
              	jiskanji=jmstojis(sjiskanji);                      //~v78cI~
    #endif                      //DPMI or not                      //~v834I~
#else                                                              //~v843I~
              	jiskanji=usjis2jis(sjiskanji);                     //~v843I~
#endif                                                             //~v843I~
              	*pco++=(UCHAR)(jiskanji>>8);		//jis kanji first byte//~v843R~
              	*pco++=(UCHAR)(jiskanji&255);  //jis kanji 2nd byte//~v843R~
//              printf("ms=%04x,jis=%04x,readc=%02x,dbcssw=%02x\n",sjiskanji,jiskanji,readc,dbcssw);//~v78cI~
                pci++;                                             //~v78cI~
                pci++;                                             //~v78cI~
			}                                                      //~v78cI~
            else	//SBCS                                         //~v78cI~
            {                                                      //~v78cI~
            	if (dbcssw)	//after DBCS                           //~v78cI~
                {                                                  //~v78cI~
                	dbcssw=0;                                      //~v78cI~
                	memcpy(pco,ESCPDBCSEND,2);                     //~v78cR~
                    pco++;                                         //~v78cI~
                    pco++;                                         //~v78cI~
				}                                                  //~v78cI~
//              *pco++=*pci++;                                     //~v846R~
                ch=*pci++;                                         //~v846I~
        		if (ch<0x20)		//control char                 //~v846I~
                	ch=keisenconv(ch);                             //~v857I~
                *pco++=ch;                                         //~v846I~
            }//DBCS or SBCS                                        //~v78cI~
		}//loop by len                                             //~v78cI~
    	if (dbcssw)	//after DBCS                                   //~v78cI~
        {                                                          //~v78cI~
        	dbcssw=0;                                              //~v78cI~
        	memcpy(pco,ESCPDBCSEND,2);                             //~v78cR~
            pco++;                                                 //~v78cI~
            pco++;                                                 //~v78cI~
		}                                                          //~v78cI~
//      olen=(size_t)((ULONG)pco-(ULONG)escbuff);                  //~v78cI~//~v968R~
//      olen=(size_t)((ULPTR)pco-(ULPTR)escbuff);                  //~v968I~//~v998R~
        olen=(unsigned)((ULPTR)pco-(ULPTR)escbuff);                //~v998I~
      if (Pputlen)			//calc outlen only                     //~v855I~
      {                                                            //~v855I~
      	*Pputlen=olen;	                                           //~v855I~
        return count;                                              //~v855I~
	  }	                                                           //~v855I~
      else                                                         //~v855I~
      {                                                            //~v855I~
#ifdef OS2                                                         //~v865I~
		if (docnamesw)                                             //~v865I~
          if (UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))                  //~v914I~
    	    olen2=(UINT)putline2p(escbuff,(int)hdrcmdlen,olen,0);  //~v914I~
          else                                                     //~v914I~
			olen2=os2_putline(escbuff,olen);                       //~v865I~
        else                                                       //~v865I~
#endif                                                             //~v865I~
//  	olen2=fwrite(escbuff,1,olen,file);                         //~v90kR~
    	olen2=(UINT)putline2p(escbuff,(int)hdrcmdlen,olen,file);   //~v90tR~
        if (olen==olen2)                                           //~v78cR~
        	return count;                                          //~v78cI~
		else                                                       //~v78cI~
        	return 0;                                              //~v78cR~
	  }                                                            //~v855I~
                                                                   //~v855I~
//  }//ESCP printer                                                //~v846R~
//      break;                                                     //~v851R~
//  else                                                           //~v846R~
    case PRINTER_CANNON: //shift jis                               //~v846R~
//cmd at only top of file                                          //~v871I~
    	if (topcmdlen)                                             //~v871I~
        {                                                          //~v871I~
	    	fwrite(topcmd,1,(UINT)topcmdlen,file);                 //~v871R~
        	topcmdlen=0;                                           //~v871I~
        }                                                          //~v871I~
        if (!keisenconvsw) //keisen conv under text mode           //~v846I~
//      	return fwrite(area,unit,count,file);                   //~v90kR~
    		return (UINT)putline2p(area,(int)hdrcmdlen,totlen,file);//~v90tR~
//keisen chk                                                       //~v846I~
    	pci=area;                                                  //~v846I~
        pcie=pci+totlen;                                           //~v846I~
        pco=escbuff;                                               //~v846I~
        if (hdr0linesw)     //header line                          //~v855I~
        {                                                          //~v846I~
            memcpy(pco,pci,hdrcmdlen);                             //~v846I~
            pci+=hdrcmdlen;                                        //~v846I~
            pco+=hdrcmdlen;                                        //~v846I~
        }                                                          //~v846I~
    	while(pci<pcie)                                            //~v846I~
        {                                                          //~v846I~
            ch=*pci++;                                             //~v846I~
            if (ch<0x20)        //control char                     //~v846I~
                ch=keisenconv(ch);                                 //~v857I~
            *pco++=ch;                                             //~v846I~
		}//loop by len                                             //~v846I~
//      olen=(size_t)((ULONG)pco-(ULONG)escbuff);                  //~v846I~//~v968R~
//      olen=(size_t)((ULPTR)pco-(ULPTR)escbuff);                  //~v968I~//~v998R~
        olen=(unsigned)((ULPTR)pco-(ULPTR)escbuff);                //~v998I~
#ifdef OS2                                                         //~v865I~
		if (docnamesw)                                             //~v865I~
          if (UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))                  //~v914I~
    	    olen2=(UINT)putline2p(escbuff,(int)hdrcmdlen,olen,0);  //~v914I~
          else                                                     //~v914I~
			olen2=os2_putline(escbuff,olen);                       //~v865I~
        else                                                       //~v865I~
#endif                                                             //~v865I~
//  	olen2=fwrite(escbuff,1,olen,file);                         //~v90kR~
    	olen2=(UINT)putline2p(escbuff,(int)hdrcmdlen,olen,file);   //~v90tR~
        if (olen==olen2)                                           //~v846I~
        	return count;                                          //~v846I~
		else                                                       //~v846I~
        	return 0;                                              //~v846I~
//  	break;                                                     //~v851R~
//#ifdef W32                                                       //~v92dR~
#if defined(W32)||defined(GXP)                                     //~v92dI~
    case PRINTER_WIN:   //shift jis                                //~v846I~
        if (!keisenconvsw) //keisen conv under text mode           //~v846I~
        {                                                          //~v846I~
  		  if (UCBITCHK(swsw3,SW3FORM2P))                           //~v914I~
    	    putline2p(area,(int)hdrcmdlen,totlen,0); 	//fh=0     //~v914I~
          else                                                     //~v914I~
#ifdef UTF8SUPP                                                    //~v928I~
  		   if (Gxputfstat & GXPUS_UCSLINE)	//data is unicode      //~v928R~
	#ifdef GXP                                                     //~v92dI~
            lnx_putline(area,count);                               //~v92dI~
    #else                                                          //~v92dI~
            win_putline(area,count);                               //~v928I~
    #endif                                                         //~v92dI~
           else                                                    //~v928I~
#endif                                                             //~v928I~
	#ifdef GXP                                                     //~v92dI~
            lnx_putline(area,totlen);                              //~v92dI~
    #else                                                          //~v92dI~
            win_putline(area,totlen);                              //~v846I~
    #endif                                                         //~v92dI~
            return totlen;                                         //~v846I~
        }//keisen henkan                                           //~v846I~
//keisen conversion                                                //~v846I~
    	pci=area;                                                  //~v846I~
        pcie=pci+totlen;                                           //~v846R~
        pco=escbuff;                                               //~v846I~
//      if (*pci==FORMFEED)     //header line                      //~v855R~
        if (hdr0linesw)     //header line                          //~v855I~
        {                                                          //~v849I~
            memcpy(pco,pci,hdrcmdlen);                             //~v849I~
            pci+=hdrcmdlen;                                        //~v849I~
            pco+=hdrcmdlen;                                        //~v849I~
        }                                                          //~v849I~
    	while(pci<pcie)                                            //~v846I~
        {                                                          //~v846I~
            ch=*pci++;                                             //~v846I~
            if (ch<0x20)        //control char                     //~v846I~
                ch=keisenconv(ch);                                 //~v857I~
            *pco++=ch;                                             //~v846I~
		}//loop by len               
//      olen=(size_t)((ULONG)pco-(ULONG)escbuff);                  //~v846I~//~v968R~
//      olen=(size_t)((ULPTR)pco-(ULPTR)escbuff);                  //~v968I~//~v998R~
        olen=(unsigned)((ULPTR)pco-(ULPTR)escbuff);                //~v998I~
  	  if (UCBITCHK(swsw3,SW3FORM2P))                               //~v914I~
    	putline2p(escbuff,(int)hdrcmdlen,olen,0); 	//fh=0         //~v914I~
      else                                                         //~v914I~
	#ifdef GXP                                                     //~v92dI~
        lnx_putline(escbuff,olen);                                 //~v92dI~
    #else                                                          //~v92dI~
        win_putline(escbuff,olen);                                 //~v846R~
	#endif                                                         //~v92dI~
        return olen;                                               //~v846R~
	    break;		                                               //~v846I~
#endif                                                             //~v846I~
//  else                                                           //~v846R~
    default:                                                       //~v846I~
//keisen chk                                                       //~v90tR~
        if (keisenconvsw) //keisen conv under text mode            //~v90tR~
        {                                                          //~v90tR~
            pci=area;                                              //~v90tR~
            pcie=pci+totlen;                                       //~v90tR~
            pco=escbuff;                                           //~v90tR~
            if (hdr0linesw)     //header line                      //~v90tR~
            {                                                      //~v90tR~
                memcpy(pco,pci,hdrcmdlen);                         //~v90tR~
                pci+=hdrcmdlen;                                    //~v90tR~
                pco+=hdrcmdlen;                                    //~v90tR~
            }                                                      //~v90tR~
            while(pci<pcie)                                        //~v90tR~
            {                                                      //~v90tR~
                ch=*pci++;                                         //~v90tR~
                if (ch<0x20)        //control char                 //~v90tR~
                    ch=keisenconv(ch);                             //~v90tR~
                *pco++=ch;                                         //~v90tR~
            }//loop by len                                         //~v90tR~
#ifdef OS2                                                         //~v90tR~
            if (docnamesw)                                         //~v90tR~
	          if (UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))              //~v914I~
    		    olen2=(UINT)putline2p(escbuff,(int)hdrcmdlen,totlen,0);//~v914I~
        	  else                                                 //~v914I~
                return os2_putline(escbuff,totlen);                //~v90tR~
            else                                                   //~v90tR~
#endif                                                             //~v90tR~
            return (UINT)putline2p(escbuff,(int)hdrcmdlen,totlen,file);//~v90tR~
        }//keisen conv                                             //~v90tR~
#ifdef OS2                                                         //~v865I~
		if (docnamesw)                                             //~v865I~
	      if (UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))                  //~v914I~
    	    return (UINT)putline2p(area,(int)hdrcmdlen,totlen,0);  //~v914I~
          else                                                     //~v914I~
			return os2_putline(area,unit*count);                   //~v867R~
        else                                                       //~v865I~
#endif                                                             //~v865I~
                                                                   //~v90gI~
//  	return fwrite(area,unit,count,file);                       //~v90kR~
    	return (UINT)putline2p(area,(int)hdrcmdlen,totlen,file);   //~v90tR~
    }//switch by prntyp                                            //~v846I~
//#else                                                            //~v843R~
//    return fwrite(area,unit,count,file);                         //~v843R~
//#endif                                                           //~v843R~
}//ufwrite                                                         //~v78cI~
//**********************************************************************//~v857I~
//* keisen conversion                                              //~v857I~
//*  convert DBCS Shift-JIS to JIS for ESCP                        //~v857I~
//**********************************************************************//~v857I~
UCHAR keisenconv(UCHAR Pch)                                        //~v857I~
{                                                                  //~v857I~
    unsigned char  ch;                                             //~v857I~
//**************************                                       //~v857I~
    switch (keisenconvsw)                                          //~v857I~
    {                                                              //~v857I~
    case 0:         //no conv                                      //~v857I~
    	ch=Pch;                                                    //~v857I~
        break;                                                     //~v857I~
    case KEISEN_ESCPASCII:                                         //~v857R~
        ch=jisctlcodetbl3[Pch];//keisen for extended graphics      //~v857I~
        break;                                                     //~v857I~
    case KEISEN_ESCPASCII2:                                        //~v90sR~
        ch=jisctlcodetbl4[Pch];//keisen for extended graphics      //~v90sR~
        break;                                                     //~v90sR~
    case KEISEN_ESCPKATAKANA:                                      //~v857I~
        ch=jisctlcodetbl2[Pch];//keisen for katakana               //~v857I~
        break;                                                     //~v857I~
    default:                                                       //~v857I~
        if (jisctlcodetbl[Pch]==KEI)//keisen for extended graphics //~v857R~
            ch=(UCHAR)keisenconvsw;                                //~v857R~
        else                                                       //~v857I~
        	ch=Pch;                                                //~v857I~
    }                                                              //~v857I~
    return ch;                                                     //~v857I~
}//keisenconv                                                      //~v857I~
//**********************************************************************//~v9e0I~
//*DBCSspace,tab alt char parm                                     //~v9e0I~
//**********************************************************************//~v9e0I~
int getTabon(char *Pparm)                                          //~v9e0I~
{                                                                  //~v9e0I~
    char *pc,*pc2,*pc3;                                            //~v9e0R~
    int parm[3]={0,0,0},parmctr=0,len,rc=4,swutf=0,swlocale=0,val; //~v9e0R~
    char wkbin[8];                                                 //~v9e0I~
//**************************                                       //~v9e0I~
    for (pc=Pparm;*pc;)                                            //~v9e0I~
    {                                                              //~v9e0I~
//    printf("getTabon:ctr=%d,pc=%s\n",parmctr,pc);                //~v9e0R~
        pc2=strchr(pc,':');                                        //~v9e0I~
        if (!pc2)                                                  //~v9e0R~
        {                                                          //~v9e0I~
//        	len=strlen(pc);                                        //~v9e0I~//~v9e7R~
          	len=(int)strlen(pc);                                   //~v9e7I~
            pc3=pc+len;                                            //~v9e0I~
        }                                                          //~v9e0I~
        else                                                       //~v9e0I~
        {                                                          //~v9e0I~
        	len=PTRDIFF(pc2,pc);                                   //~v9e0I~
            pc3=pc2+1;                                             //~v9e0I~
        }                                                          //~v9e0I~
        if (toupper(*pc)=='X'||toupper(*pc)=='U')                  //~v9e0R~
        {                                                          //~v9e0I~
	        if (len>5||len<=1)                                     //~v9e0R~
    	    	break;                                             //~v9e0I~
        	memset(wkbin,0,sizeof(wkbin));                         //~v9e0R~
        	if (ugethex(pc+1,wkbin,len-1)<0)                       //~v9e0R~
	        	break;                                             //~v9e0I~
            if (wkbin[0])                                          //~v9e0R~
	            val=wkbin[0]*256+wkbin[1];                         //~v9e0R~
            else                                                   //~v9e0I~
	            val=wkbin[0];                                      //~v9e0I~
            if (val>0xff)                                          //~v9e0I~
            {                                                      //~v9e7I~
        		if (toupper(*pc)=='X')                             //~v9e0I~
		            swlocale=1;                                    //~v9e0R~
                else                                               //~v9e0I~
		            swutf=1;                                       //~v9e0I~
            }                                                      //~v9e7I~
        }                                                          //~v9e0I~
        else                                                       //~v9e0I~
        {                                                          //~v9e0I~
            if (len==0)                                            //~v9e0I~
            	val=0;                                             //~v9e0I~
            else                                                   //~v9e0I~
            if (len==1)                                            //~v9e0I~
            	val=*pc;                                           //~v9e0I~
            else                                                   //~v9e0I~
            if (len==2)                                            //~v9e0I~
            	val=*pc*256+*(pc+1);                               //~v9e0I~
        	else                                                   //~v9e0I~
        		break;                                             //~v9e0I~
            if (val>0xff)                                          //~v9e0I~
	            swlocale=1;                                        //~v9e0R~
        }                                                          //~v9e0I~
	    if (swutf & swlocale)                                      //~v9e0R~
    	{                                                          //~v9e0I~
        	printf("Tabon parameter is mixed of Unicode and Locale code\n");//~v9e0R~
        	break;                                                 //~v9e0I~
    	}                                                          //~v9e0I~
    	if (parmctr>=3)                                            //~v9e0M~
        	break;                                                 //~v9e0M~
        if (parmctr==0 && val<=0xff)                               //~v9e0I~
        {                                                          //~v9e0I~
        	printf("Tabon parameter:DBCS space is not DBCS code\n");//~v9e0I~
        	break;                                                 //~v9e0I~
        }                                                          //~v9e0I~
        parm[parmctr++]=val;                                       //~v9e0I~
        pc=pc3;                                                    //~v9e0R~
    }                                                              //~v9e0I~
    if (!*pc)                                                      //~v9e0R~
    {                                                              //~v9e0I~
    	Gtabonutf8=swutf;                                          //~v9e0I~
    	Gtabonlocale=swlocale;                                     //~v9e0I~
    	GtabonDBCSspace=parm[0];                                   //~v9e0I~
    	GtabonTab=parm[1];                                         //~v9e0I~
    	GtabonTabskip=parm[2];                                     //~v9e0I~
		UCBITON(swsw5,SW5TABONPRM);  //0x10	//tabon parameter specified//~v9e0I~
    	rc=0;                                                      //~v9e0I~
    }                                                              //~v9e0I~
//    printf("getTabon:ctr=%d,swutf8=%d,space=%x,tab=%x,tabskip=%x\n",parmctr,Gtabonutf8,GtabonDBCSspace,GtabonTab,GtabonTabskip);//~v9e0R~
    return rc;                                                     //~v9e0I~
}//getTabon                                                        //~v9e0I~
//**********************************************************************//~v9e0I~
//*chk utf8 mode and tabon                                         //~v9e0R~
//**********************************************************************//~v9e0I~
int chkTabon()                                                     //~v9e0I~
{                                                                  //~v9e0I~
	int swutf8file,swebcfile,ddlen;                                //~v9e0R~
    UCHAR dddbcs[4]={0,0},dddata[4];                               //~v9e0R~
//**************************                                       //~v9e0I~
	swebcfile=UCBITCHK(swsw4,SW4EBCCFG);                           //~v9e0I~
    if (swebcfile)                                                 //~v9e0I~
    	if (swsw5 & SW5NOBYUCS) //ebc by /TU(ebc by not ucs)       //~v9e0I~
        	swutf8file=0;                                          //~v9e0I~
        else                                                       //~v9e0I~
        	swutf8file=1;                                          //~v9e0I~
    else                                                           //~v9e0I~
	    swutf8file=XPUTF8MODE();                                   //~v9e0I~
    if (( swutf8file &&   Gtabonlocale)                            //~v9e0R~
    ||  (!swutf8file &&   Gtabonutf8)                              //~v9e0I~
    )                                                              //~v9e0I~
    {                                                              //~v9e0I~
        printf("Tabon parameter type(unicode or not) and file type is inconsistent\n");//@@@@test//~v9e0R~
        return 4;                                                  //~v9e0I~
    }                                                              //~v9e0I~
    if (!GtabonDBCSspace)                                          //~v9e0I~
    {                                                              //~v9e0I~
    	if (swutf8file)                                            //~v9e0R~
        	GtabonDBCSspace=TABON_DEFAULT_DBCSSPACE_UTF8;          //~v9e0R~
        else                                                       //~v9e0I~
        	GtabonDBCSspace=TABON_DEFAULT_DBCSSPACE_LOCALE;        //~v9e0R~
    }                                                              //~v9e0I~
    else                                                           //~v9e0I~
    {                                                              //~v9e0I~
        if (swutf8file)                                            //~v9e0I~
        {                                                          //~v9e0I~
            utfcvu2dd1(0,(WUCS)GtabonDBCSspace,dddata,dddbcs,&ddlen);//~v9e0R~
//          printf("dddata=%02x%02x,dddbcs=%02x%02x\n",*dddata,*(dddata+1),*dddbcs,*(dddbcs+1));//~v9e0R~
            if (*dddbcs!=UDBCSCHK_DBCS1STUCS)                      //~v9e0I~
            {                                                      //~v9e0I~
        		printf("Tabon DBCS space param(u%02x%02x) is not colomn width=2\n",GtabonDBCSspace>>8,GtabonDBCSspace&255);//@@@@test//~v9e0R~
        		return 4;                                          //~v9e0I~
            }                                                      //~v9e0I~
        }                                                          //~v9e0I~
        else                                                       //~v9e0I~
        {                                                          //~v9e0I~
	        if (!(GtabonDBCSspace>>8))                             //~v9e0I~
    	    {                                                      //~v9e0I~
        		printf("Tabon DBCS space param(x%02x%02x) is colomn width=1\n",GtabonDBCSspace>>8,GtabonDBCSspace&255);//@@@@test//~v9e0R~
        		return 4;                                          //~v9e0I~
        	}                                                      //~v9e0I~
        }                                                          //~v9e0I~
    }                                                              //~v9e0I~
    if (!GtabonTab)                                                //~v9e0I~
        GtabonTab=TABON_DEFAULT_TAB;                               //~v9e0I~
    if (!GtabonTabskip)                                            //~v9e0I~
        GtabonTabskip=TABON_DEFAULT_TABSKIP;                       //~v9e0I~
//  printf("chkTabon:swebcfile=%d,swutf8file=%d,swutf8=%d,space=%x,tab=%x,tabskip=%x\n",swebcfile,swutf8file,Gtabonutf8,GtabonDBCSspace,GtabonTab,GtabonTabskip);//@@@@test//~v9e0R~
    return 0;                                                      //~v9e0I~
}//chkTabon                                                        //~v9e0I~
//**********************************************************************//~v9e0I~
//*get altch for tab/dbcsspace                                     //~v9e0I~
//**********************************************************************//~v9e0I~
int getTabonAltch(int Ptype,int Ptype2)                            //~v9e0I~
{                                                                  //~v9e0I~
	int rc;                                                        //~v9e0I~
//***************************                                      //~v9e0I~
	if (Ptype==TAB)                                                //~v9e0I~
    {                                                              //~v9e0I~
    	if (Ptype2==0)	//TAB                                      //~v9e0I~
        	rc=GtabonTab;                                          //~v9e0I~
        else            //TABSkip                                  //~v9e0I~
        	rc=GtabonTabskip;                                      //~v9e0I~
    }                                                              //~v9e0I~
    else                                                           //~v9e0I~
    {                                                              //~v9e0I~
    	rc=GtabonDBCSspace;                                        //~v9e0I~
    }                                                              //~v9e0I~
//  printf("parm=%x-%x,rc=%x\n",Ptype,Ptype2,rc);                  //~v9e0R~
    return rc;                                                     //~v9e0I~
}//getTabonAltch                                                   //~v9e0I~
