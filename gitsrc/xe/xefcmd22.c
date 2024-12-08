//*CID://+vbzDR~:                             update#=  489;       //~vbzDR~
//*************************************************************
//*xefcmd.c                                                     //~5504R~
//*  find/change sub                                               //~v0ewR~
//****************************************************************//~v013I~
//vbzD:240327 find cmd; change option -next2 to -cont              //~vbzDI~
//vbzx:240307 Find cmd;add option "next2, start pos is same as previous failed next cmd for performance of "exe" cmd by sorted find word.//~vbzxI~
//            ==>if not found , start pos is from top. So pperformance gain is not so large.//~vbzxI~
//vbrm:200918 by xuerpchk(uerr fmt chk)                            //~vbrmI~
//vbq2:200418 to find label pattern such as .a with label, issue warning enclose by parenthesys.//~vbq2R~
//vbky:180711 (Bug)memory corrupted by label overflow by Find cmd width -L option.//~vbkyI~
//vbc3:170822 delete vbc2(it is enough by normal find;reject TS parameter)//~vbc3I~
//vbc2:170821 add TS   option for find cmd on dirlist              //~vbc2I~
//vbc1:170820 add ATTR option for find cmd on dirlist              //~vbc1I~
//vb86:170216 display cmdline ctr excluded(fcmd:x,xx; lcmd x)      //~vb86I~
//vb84:170215 (BUG)line of status ULHFLINECMD on but not on UFHliencmd[], the line cmd input is ignored//~vb84I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vax1:140625 (BUG:Win)find ucs2 failes(searchs ucs4), U4 is not only for change cmd repword but for search word//~vax1I~
//vaw4:140528 (Win:UNICODE)escsrch by 3byte unicode                //~vaw4I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va28:091212 (BUG)help msg for find cmd( add "*ec")               //~va28I~
//va26:091210 (BUG)Info from Dirk                                  //~va26I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va1q:091107 compchkm                                             //~va1qI~
//va1h:091102_Shorten Find help for 80 column                      //~va1hI~
//va0y:090920_add U8(UTF8 code search) to find option(U[B|L|8] (Big/Little Endian/UTF8)//~va0yI~
//va0c:090711 Unicode find option  U[B|L] (Big/Little Endian,default is OS endian)//~va0cI~
//v79L:081020 change cmd support P'..' fmt as target string specification(=(same),<(lower),>(upper) is special char)//~v79LI~
//v78e:080310 supprt find cmd search patern by P'.'                //~v78eI~
//v78d:080308 screen grep support                                  //~v78dI~
//v74F:070322 add NX option for Find/Change as alternative of fnx/cnx//~v74FI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v72P:061214 add ic cmd(case insensitive change)                  //~v72PI~
//v698:060427 (BUG)scrolling dose not occur when hex 3line mode.   //~v698I~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v62d:050312 matching cmd;find *= col1 col2 & ^* col3 col4        //~v62dI~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v62aI~
//v61q:050302 set any lcmd by find -lxxx not only label            //~v61qI~
//v61h:050226 find cmd set label option(-lxxx)                     //~v61hI~
//v603:041220 multiline errmsg support(for find help msg)          //~v603I~
//v59Z:041218 find cmd:csr line position option                    //~v59ZI~
//v58r:040923 find cmd option -je:join to eof(line range2) if 2nd word not found//~v58rI~
//v54Z:040202 find cmd:search "x y" at eol by EOL option("a b"\n is fmt err by parse())//~v54ZI~
//v551:040202 change max-->maxeol(seach at eol on longest record)  //~v551I~
//v54R:040125 find cmd:max record pos search by max pos parm       //~v54RI~
//v54C:040120 (BUG)"find *= 1 1" is rejected because wordlen=2(>1) //~v54CI~
//v54z:040118 support eolsrch with any str;*\n, "*"\n is for srch * at eol//~v54zI~
//v539:030920 join option for find; {i|f}[nx] -j                   //~v539I~
//v538:030920 change v532;2nd column is for 2nd operand only       //~v538I~
//v537:030920 find/change allkx option(keep excluded)              //~v532I~
//v532:030915 2 cols pos parm for & search                         //~v532I~
//v49d:020629 to exclude from 1st same "x *= -b"                   //~v49dI~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find"//~v49bI~
//v496:020617 find *L (search lineserch result;for after == lcmd)  //~v496I~
//v47B:020321 find at eol  xxxx\n Ssrch and Ssrch2(& srearch)      //~v47BI~
//v47t:020315 minus support for -a -b                              //~v47tI~
//v47c:020223 chk duplicated label on lineno column.               //~v47cI~
//v43w:011116 ! for also word2 of & search                         //~v43wI~
//v43v:011112 (BUG)abend when label is on the top/end hdr line     //~v43vI~
//v43u:011112 fgind:change *! --> ! only                           //~v43uI~
//v43t:011112 fgind:change *& --> & only                           //~v43tI~
//v43p:011102 allow *! and *&                                      //~v43pI~
//v43o:011031 *& should between 2 word                             //~v43oI~
//v43m:011101 conflict err msg                                     //~v43mI~
//v43k:011101 reject *! and *& conbination                         //~v43kI~
//v43i:011031 distance option <,>,= (default is =)                 //~v43iI~
//v43e:011026 find cmd option;f *& word1 word2 -dn                 //~v43eI~
//v43d:011026 find cmd option to always set csr to leftmost        //~v43dI~
//v43a:011024 first(find) or second(change) operand is data even if start by "."//~v43aI~
//v437:011024 add unexclude range optio to find cmd                //~v437I~
//v433:011016 (AIX:BUG)find "\" faile(strchar succes for 0x00)     //~v433I~
//v41r:010830 except search "*!" prefix; "i *! word" fmt           //~v41rI~
//            file screen only;no chnage avail.                    //~v41rI~
//v40L:010716 add option to "x *= all" of minimum same lineno      //~v40LI~
//v40J:010714 change fmt "x =all" to "x *= all"                    //~v40JR~
//v40z:010625 column range support for x *=(same as above)         //~v40zI~
//v13p:991106 find consideration for concat line/bin file line     //~v13pI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v11s:990808 (BUG) not allowed \x string search if \x09 is contained.Allow to bin file.//~v11sI~
//v11p:990725 accept "EXClude all" (no search word  case)          //~v11pI~
//v11o:990720 (BUG)compatibility to DOS;find parm save len change int to SHORT//~v11oI~
//v11k:990718 Find/change/Exclude cmd help                         //~v11kI~
//v11g:990717 set found line in the middle of page                 //~v11gI~
//v10q:990327 treate .xxx as data if opdno=1(find) or 2(change)    //~v10qI~
//v0hC:980418 (BUG)on dir list,it cannot be find .ext              //~v0hCI~
//v0hx:980410 label lcmd support for find etc.                     //~v0hxI~
//            alternative of v0hk and  v0hw is not needed anymore. //~v0hxI~
//v0eP:971005 change margin parm for Find/Change.1M,2M-->LM,RM     //~v0ePI~
//v0eH:970926 if err return,it should not to set Srange1/2         //~v0eHI~
//v0eB:970923 find/change range support                            //~v0eBI~
//v0ew:970922 split fcmd2 to fcmd22                                //~v0ewI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>                                             //~5318I~
#include <utrace.h>                                                //~vax1I~

#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <ufile.h>                                              //~5318R~
#include <uedit.h>                                                 //~v09LI~
#ifdef UTF8SUPPH                                                   //~va1GI~
#include <udbcschk.h>                                              //~va1GI~
#endif                                                             //~va1GI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile6.h"                                               //~v0ewI~
#include "xefunc.h"                                                //~v0ewI~
#include "xefunc2.h"                                               //~vbCBI~
#include "xefcmd2.h"                                               //~v0ewI~
#include "xefcmd22.h"                                              //~v0ewI~
#include "xelcmd.h"                                                //~v0hxI~
#include "xefsub.h"                                                //~v0ewR~
#include "xeerr.h"                                                 //~v0eBI~
#include "xefunct.h"                                               //~vbCBI~
//*******************************************************
#define ATTRID           "ATTR"                                    //~vbc3I~
#define MAXLABEL 2                                                 //~v0hxI~
#define NONE_SAVED "None"                                          //~vbCBI~
                                                                   //~vbCBI~
//#define FCMDOPT_NEXT2       "NEXT2"     //split panel specific     //~vbzxI~//~vbzDR~
#define FCMDOPT_NEXT2       "CONT"     //split panel specific      //~vbzDI~
#define FCMDOPT_PS_SPLIT    "PSP"       //split panel specific     //~vbCBM~
#define FCMDOPT_PS_FILE     "PSF"       //file specific            //~vbCBR~
#define FCMDOPT_PS_STD      "STD"                                  //~vbCBI~
#define FCMDOPT_PS_OPT2POS   3  //pos of X/D                       //~vbCBM~
#define FCMDOPT_PS_EXECUTE    "X" //used like as PSGX,restore then execute//~vbCBM~
#define FCMDOPT_PS_EXECUTE_C  'X' //used like as PSGX,restore then execute//~vbCBM~
#define FCMDOPT_PS_DISPLAY    "D" //used like as PSGX,restore then execute//~vbCBM~
#define FCMDOPT_PS_DISPLAY_C  'D' //used like as PSGX,restore then execute//~vbCBM~
#define FCMDOPT_PS_RETRIEVE   "R" //used like as PSGX,restore then execute//~vbCBI~
#define FCMDOPT_PS_RETRIEVE_C 'R' //used like as PSGX,restore then execute//~vbCBR~
                                                                   //~vbCBI~
#define FCMDOPT_PSTYPE_STD     0                                   //~vbCBI~
#define FCMDOPT_PSTYPE_SPLIT   1                                   //~vbCBR~
#define FCMDOPT_PSTYPE_FILE    2                                   //~vbCBR~
#define FCMDOPT_PSTYPE_MAX     3                                   //~vbCBR~
static  char *Spsopd[FCMDOPT_PSTYPE_MAX]={                         //~vbCBR~
                                    FCMDOPT_PS_STD,                //~vbCBR~
									FCMDOPT_PS_SPLIT,              //~vbCBI~
                                    FCMDOPT_PS_FILE,               //~vbCBR~
								};                                 //~vbCBI~
static int ScontrolPS;                                             //~vbCBR~
#define CPS_CALLRFIND             0x0001  //call std find from PS cmd//~vbCBM~
#define CPS_EXECUTE               0x0002  //reenq cmd              //~vbCBM~
static int Sprevpstype=-1;	//STD stack is revered                 //~vbCBR~
                                                                   //~vbCBI~
                                                                   //~vbCBI~
typedef struct _UFCMD {                                            //~vbCBI~
                            int     UFCpstype;                     //~vbCBI~
                            int     UFCcase;	                   //~vbCBM~
                            int     UFCcahngeopt;//0:find,1:change //~vbCBM~
                            int     UFCbackword; //0:dest by cmd,1:force backword//~vbCBM~
                            int     UFCnxopt;	//not excluded line opt//~vbCBM~
                            int     UFCdest;	//1:reverse        //~vbCBR~
                            int     UFCopdpos;	//PSx operand pos  //~vbCBR~
                            int     UFCopdlen;	//PSx operand len  //~vbCBI~
                        	USCMD   UFCuscmd;	//it mustbe last member//~vbCBI~
                      } UFCMD,*PUFCMD;                             //~vbCBR~
#define UFCMDSZ ((int)sizeof(UFCMD))                               //~vbCBI~
//*******************************************************          //~v0hxM~
static UCHAR Slab[MAXLABEL][ULHLINENOSZ+1];//label opd from/to     //~v0hxR~
static UCHAR Slabold[MAXLABEL][ULHLINENOSZ+1];//to bell once at changed//~v0hxI~
//static int     Srangeplcindex;                                   //~v0hxR~
static   int   	 Smidsw=0;                                         //~v437R~
//**************************************************************** //~v59ZI~
int fcmdgetcsropt(char *Pparm,ULONG *Ppopt2);                      //~v59ZI~
#ifdef UTF8SUPPH                                                   //~va1qI~
int fcmdchkucsopt(char *Popd,int *Ppopt);                          //~va0cI~
#endif                                                             //~va1qI~
int fcmdgetfindoptionPS(PUCLIENTWE Ppcw,char *Popd,UPODELMTBL* Ppodt);//~vbCBR~
int fcmdgetfindoptionPSstd(PUCLIENTWE Ppcw);                       //~vbCBR~
int fcmdcallrfind(int Popt,PUCLIENTWE Ppcw,int Pdest,int Ppstype); //~vbCBI~
#define FCRFO_NEWOPD       0x01      //A+F5/C+F5 with new operand  //~vbCBI~
int finderr_notdirlist(char *Pvalue);                              //~vbc1I~
//**************************************************************** //~v437I~
//!fcmdgetfindoption                                               //~v437I~
//* parm1 :pcw                                                     //~v437I~
//* parm2 :change opt;1:change,0:find                              //~v437I~
//* parm3 :in/out,operandno after range parm dropped               //~v437I~
//* parm4 :in/out,operand string tbl after range parm dropped      //~v437I~
//* parm5 :in/out,operand delm tbl after range parm dropped        //~v437I~
//* parm6 :output integer option tbl addr;before line,after line   //~v437I~
//* parm7 :output integer option flag                              //~v43dI~
//* return:rc 0 or 4                                               //~v437I~
//**************************************************************** //~v437I~
//int fcmdgetfindoption(PUCLIENTWE Ppcw,int Pchangeopt,int *Popdno,//~v49dR~
int fcmdgetfindoption(PUCLIENTWE Ppcw,int Pexcludesw,int Pchangeopt,int *Popdno,//~v49dI~
//  			char **Popd,UPODELMTBL *Podt,int *Pinttbl,int *Ppopt)//~v59ZR~
    			char **Popd,UPODELMTBL *Podt,int *Pinttbl,int *Ppopt,ULONG *Ppopt2)//~v59ZI~
{                                                                  //~v437I~
	int opdch,ii,len,opdno,opdnon,ip;                              //~v43dR~
    char *opd,*pc;                                                 //~v437I~
	UPODELMTBL odt;                                                //~v437I~
    int rc2;                                                       //~vbCBR~
    int swPS=0;                                                    //~vbCBI~
//*********************************                                //~v437I~
	Gnxsw&=~GNXSW_OPT; //nx option clear                           //~v74FR~
	*Ppopt=0;                                                      //~v43dI~
	*Ppopt2=0;                                                     //~v59ZI~
    *(Pinttbl+FINDIP_DISTANCE)=0;   //init                         //~v58rI~
    opdno=*Popdno;                                                 //~v437I~
	for (ii=0,opdnon=0;ii<opdno;ii++)                              //~v437R~
	{                                                              //~v437I~
    	opd=Popd[ii];                                              //~v437I~
    	odt=Podt[ii];                                              //~v437I~
		if (!odt.upoquate		//not in quatation                 //~vbCBI~
        &&  opdno==1            //1st operand is assumed as find word//~vbCBR~
#ifdef UNX                                                         //~vbCBI~
		&&  *opd=='-'                                              //~vbCBI~
#else                                                              //~vbCBI~
		&&  (*opd=='-'||*opd=='/')                                 //~vbCBI~
#endif                                                             //~vbCBI~
        &&  *(opd+1))     // "-" means "prev"                      //~vbCBI~
		{		//option flag                                      //~vbCBI~
            rc2=fcmdgetfindoptionPS(Ppcw,opd,&odt);                //~vbCBR~
            if (rc2>=4) //invalid PSx cmd                          //~vbCBI~
            	return rc2;                                        //~vbCBI~
            if (rc2==1) //PSx option specified                     //~vbCBI~
            	return rc2;                                        //~vbCBI~
        }                                                          //~vbCBI~
		if (!odt.upoquate		//not in quatation                 //~v437R~
        &&  ii>=1                                                  //~v437R~
#ifdef UNX                                                         //~v437I~
		&&  *opd=='-'                                              //~v43aR~
#else                                                              //~v437I~
		&&  (*opd=='-'||*opd=='/')                                 //~v43aR~
#endif                                                             //~v437I~
        &&  *(opd+1))     // "-" means "prev"                      //~v43aI~
		{		//option flag                                      //~v437I~
            pc=opd+1;                                              //~v437R~
            opdch=toupper(*pc);                                    //~v437I~
            pc++;                                                  //~v437I~
            len=(int)strlen(pc);                                   //~v47BR~
            switch (opdch)                                         //~v437I~
            {                                                      //~v437I~
            case 'A':		//after n line display                 //~v437R~
            case 'B':		//after n line display                 //~v437R~
                if (Ppcw->UCWtype==UCWTDIR                         //~v43dI~
                ||  Pchangeopt)                                    //~v43dI~
                    return errconflict(opd,0);//duplicate          //~v43mR~
            	if (unumlen(pc,0,len)!=len)                        //~v437I~
	    	        return errinvalid(opd);//duplicate             //~v437I~
            	ip=atoi(pc);                                       //~v43dI~
	            if (opdch=='A')                                    //~v437I~
            		*(Pinttbl+FINDIP_AFTER)=ip;                    //~v43dR~
                else                                               //~v43dI~
	            if (opdch=='B')                                    //~v43dI~
                {                                                  //~v49dI~
                  if (ip)                                          //~v49dI~
            		*(Pinttbl+FINDIP_BEFORE)=ip;                   //~v43dR~
                  else                                             //~v49dI~
                    if (Pexcludesw)                                //~v49dI~
						*Ppopt=*Ppopt|FINDOPT_BEFORE0;             //~v49dI~
                    else                                           //~v49dI~
	    	        	return errinvalid(opd);//duplicate         //~v49dI~
                }                                                  //~v49dI~
            	break;                                             //~v437R~
            case 'C':		//csr top option                       //~v43dI~
                if (!stricmp(pc-1,FCMDOPT_NEXT2))                  //~vbzDI~
                {                                                  //~vbzDI~
                  if (!(GfindStat & GFS_EXECMD))                   //~vbzDI~
                  {                                                //~vbzDI~
                  	uerrmsg("%s option is in Exe cmd file only",0, //~vbzDI~
                		FCMDOPT_NEXT2);                            //~vbzDI~
                    return 4;                                      //~vbzDI~
                  }                                                //~vbzDI~
                  else                                             //~vbzDI~
                    *Ppopt=*Ppopt|FINDOPT_NEXT2;                   //~vbzDI~
                    break;                                         //~vbzDI~
                }                                                  //~vbzDI~
                if (Ppcw->UCWtype==UCWTDIR                         //~v43dI~
                ||  Pchangeopt)                                    //~v43dI~
                    return errconflict(opd,0);//duplicate          //~v43mI~
//  			*Ppopt=*Ppopt|FINDOPT_CSRTOP;                      //~v59ZR~
            	if (fcmdgetcsropt(pc,Ppopt2))                      //~v59ZI~
	    	        return errinvalid(opd);//duplicate             //~v59ZI~
            	break;                                             //~v43dI~
            case 'D':		//after n line display                 //~v43iI~
                if (Ppcw->UCWtype==UCWTDIR                         //~v43iI~
                ||  Pchangeopt)                                    //~v43iI~
                    return errconflict(opd,0);//duplicate          //~v43mI~
				*Ppopt=*Ppopt|FINDOPT_DISTOPT;                     //~v58rI~
            	switch(*pc)                                        //~v43iI~
                {                                                  //~v43iI~
                case '=':                                          //~v43iI~
                    pc++;len--;                                    //~v43iI~
                    break;                                         //~v43iI~
                case '<':                                          //~v43iI~
					*Ppopt=*Ppopt|FINDOPT_DISTIN;                  //~v43iI~
                    pc++;len--;                                    //~v43iI~
                    break;                                         //~v43iI~
                case '>':                                          //~v43iI~
					*Ppopt=*Ppopt|FINDOPT_DISTOUT;                 //~v43iI~
                    pc++;len--;                                    //~v43iI~
                    break;                                         //~v43iI~
                }                                                  //~v43iI~
            	if (unumlen(pc,0,len)!=len)                        //~v43iI~
	    	        return errinvalid(opd);//duplicate             //~v43iI~
            	ip=atoi(pc);                                       //~v43iI~
                *(Pinttbl+FINDIP_DISTANCE)=ip;                     //~v43iI~
            	break;                                             //~v43iI~
            case 'G':		//grep pattern                         //~v78dR~
                if (Ppcw->UCWtype==UCWTDIR)                        //~v78dR~
                    return errconflict(opd,"dir-list");            //~v78dI~
				*Ppopt=*Ppopt|FINDOPT_GREP;                        //~v78dI~
            	break;                                             //~v78dI~
            case 'J':		//after n line display                 //~v539I~
                if (Ppcw->UCWtype==UCWTDIR                         //~v539I~
                ||  Pexcludesw                                     //~v539I~
                ||  Pchangeopt)                                    //~v539I~
                    return errconflict(opd,0);//0:conflict with other option//~v539I~
				*Ppopt=*Ppopt|FINDOPT_JOIN;                        //~v539R~
                if (*pc=='E'||*pc=='e')                            //~v58rI~
					*Ppopt=*Ppopt|FINDOPT_JOINEOF;                 //~v58rI~
            	break;                                             //~v539I~
            case 'L':		//after n line display                 //~v61hI~
                if (Ppcw->UCWtype==UCWTDIR                         //~v61hI~
                ||  Pexcludesw                                     //~v61hI~
                ||  Pchangeopt)                                    //~v61hI~
                    return errconflict(opd,0);//0:conflict with other option//~v61hI~
//              if (!len || len+1>=Ppcw->UCWlinenosz)              //~v61qR~
                if (!len || len>=Ppcw->UCWlinenosz)                //~v61qI~
                {                                                  //~v61hI~
                	uerrmsg("-l parm len=0 or overrun lineNo field.",//~v61hR~
                    		"-l パラメータの長さが 0 か行番号欄幅を超える。");//~v61hR~
                    return 4;                                      //~v61hI~
                }                                                  //~v61hI~
				*Ppopt=*Ppopt|FINDOPT_SETLABEL;                    //~v61hI~
                *(Pinttbl+FINDIP_LABELOPDNO)=ii;	//operand relative no//~v61hR~
            	break;                                             //~v61hI~
            case 'M':		//multiple reverse                     //~v62aI~
				*Ppopt=*Ppopt|FINDOPT_MULTIREV;                    //~v62aI~
                if (*pc=='N'||*pc=='n')                            //~v62aI~
					*Ppopt=*Ppopt|FINDOPT_MULTIREVNEXT;            //~v62aI~
            	break;                                             //~v62aI~
            case 'N':		//multiple reverse                     //~v74FI~
                if ((*pc=='X'||*pc=='x') && *(pc+1)==0)            //~v74FI~
					Gnxsw|=GNXSW_OPT; //nx option clear            //~v74FR~
                else                                               //~vbzxR~//~vbzDR~
	    	        return errinvalid(opd);                        //~vbzDI~
//                    if (!stricmp(pc-1,FCMDOPT_NEXT2))              //~vbzxR~//~vbzDR~
//                        *Ppopt=*Ppopt|FINDOPT_NEXT2;               //~vbzxR~//~vbzDR~
            	break;                                             //~v74FI~
            default:                                               //~v437I~
                rc2=fcmdgetfindoptionPS(Ppcw,opd,&odt);            //~vbCBR~
                if (rc2>=4) //invalid PSx cmd                      //~vbCBI~
                    return rc2;                                    //~vbCBI~
                if (rc2==1) //PSx option specified                 //~vbCBI~
                    swPS=1;                                        //~vbCBR~
                else                                               //~vbCBI~
	    		return errinvalid(opd);//duplicate                 //~v437I~
            }                                                      //~v437I~
            continue;                                              //~v437I~
        }//option parm                                             //~v437I~
        Popd[opdnon]=opd;                                          //~v437I~
        Podt[opdnon++]=odt;                                        //~v437I~
        len=(int)strlen(opd);                                      //~v78eR~
	 if (!odt.upoquate)		//not in quatation                     //~v79LI~
     {                                                             //~vbCBI~
        if (len>3                                                  //~v78eR~
        &&  toupper(*opd)=='P'                                     //~v78eR~
        &&  (*(opd+1)=='\''|| *(opd+1)=='\"')                      //~v78eR~
        &&  *(opd+1)==*(opd+len-1)                                 //~v78eR~
        )                                                          //~v78eR~
        {                                                          //~v78eR~
            if (Ppcw->UCWtype==UCWTDIR)                            //~v78eR~
                return errconflict(opd,"dir-list");                //~v78eR~
            if (Pchangeopt && opdnon>1)  //2nd word of change      //~v78eR~
//              return errconflict(opd,"Change-cmd target string");//~v79LR~
            	*Ppopt=*Ppopt|FINDOPT_GREPPTARGET;                 //~v79LR~
            else                                                   //~v79LI~
            *Ppopt=*Ppopt|(FINDOPT_GREP|FINDOPT_GREPP);            //~v78eR~
        }                                                          //~v78eR~
     }//not in quotation                                           //~vbCBI~
	}//opdno loop                                                  //~v437I~
	*Popdno=opdnon;                                                //~v437I~
    if (*Ppopt&FINDOPT_JOINEOF)	//join to eof                      //~v58rI~
    {                                                              //~v58rI~
	    if (!(*Ppopt&FINDOPT_DISTOPT))	//join to eof              //~v58rR~
        {                                                          //~v58rI~
	    	uerrmsg("-je option requre -dn option",                //~v58rI~
                    "-je オプションは -dn 指定が必要です。");      //~v58rI~
            return 4;                                              //~v58rI~
        }                                                          //~v58rI~
    }                                                              //~v58rI~
	if ((*Ppopt & FINDOPT_SETLABEL)                                //~v61hI~
    &&  (*Ppopt & (FINDOPT_JOIN|FINDOPT_JOINEOF)))	//join to eof  //~v61hI~
    	return errconflict("-l","-j");                             //~v61hI~
    if (!swPS)	//std cmd                                          //~vbCBI~
    	fcmdgetfindoptionPSstd(Ppcw);                              //~vbCBR~
    return 0;                                                      //~v437I~
}//fcmdgetfindoption                                               //~v437I~
//**************************************************************** //~v59ZI~
//!fcmdgetcsropt                                                   //~v59ZI~
//* return:rc                                                      //~v59ZI~
//**************************************************************** //~v59ZI~
int fcmdgetcsropt(char *Pparm,ULONG *Ppopt2)                       //~v59ZI~
{                                                                  //~v59ZI~
    ULONG opt2=0;                                                  //~v59ZI~
    char *pc;                                                      //~v59ZI~
    int numlen,linectr,colsctr,ch;                                 //~v59ZR~
//*********************************                                //~v59ZI~
	if (!*Pparm)		//-c (old version type)                    //~v59ZR~
    {                                                              //~v59ZI~
    	*Ppopt2=*Ppopt2|FINDOPT2_CSRRIGHT;                         //~v59ZI~
        return 0;                                                  //~v59ZI~
    }                                                              //~v59ZI~
	for (pc=Pparm;*pc;pc++)                                        //~v59ZI~
    {                                                              //~v59ZI~
		ch=toupper(*pc);                                           //~v59ZR~
		switch(ch)                                                 //~v59ZI~
        {                                                          //~v59ZI~
        case 'R':  //right                                         //~v59ZR~
        case 'L':  //left                                          //~v59ZM~
//        	opt2&=~FINDOPT2_CSRCENTER;                             //~v59ZI~//~vb2DR~
          	opt2&=(ULONG)(~FINDOPT2_CSRCENTER);                    //~vb2DI~
        	if (ch=='R')                                           //~v59ZI~
        		opt2|=FINDOPT2_CSRRIGHT;                           //~v59ZR~
            else                                                   //~v59ZI~
	        	opt2|=FINDOPT2_CSRLEFT ;                           //~v59ZI~
            pc++;                                                  //~v59ZI~
            numlen=(int)strlen(pc);                                //~v603R~
            if (numlen)                                            //~v59ZI~
	            numlen=unumlen(pc,0,numlen);                       //~v59ZI~
            if (numlen)                                            //~v59ZI~
            {                                                      //~v59ZI~
            	colsctr=atoi(pc);                                  //~v59ZR~
                if (colsctr)                                       //~v59ZI~
                    colsctr--;                                     //~v59ZI~
            }                                                      //~v59ZI~
            else                                                   //~v59ZI~
            	colsctr=0;                                         //~v59ZI~
            colsctr<<=8;                                           //~v59ZR~
//          opt2=(opt2&~FINDOPT2_CSRCOLMASK)|(colsctr&FINDOPT2_CSRCOLMASK);//~v59ZI~//~vb2DR~
            opt2=(opt2&(ULONG)(~FINDOPT2_CSRCOLMASK))|(colsctr&FINDOPT2_CSRCOLMASK);//~vb2DI~
            pc+=numlen-1;                                          //~v59ZI~
        	break;                                                 //~v59ZI~
        case 'M':  //middle                                        //~v59ZR~
        	opt2|=FINDOPT2_CSRMIDDLE;                              //~v59ZI~
        	break;                                                 //~v59ZI~
        case 'T':  //top                                           //~v59ZI~
        case 'B':  //bottom                                        //~v59ZI~
//      	opt2&=~FINDOPT2_CSRMIDDLE;                             //~v59ZI~//~vb2DR~
        	opt2&=(ULONG)(~FINDOPT2_CSRMIDDLE);                    //~vb2DI~
        	if (ch=='T')   //minus                                 //~v59ZR~
	        	opt2|=FINDOPT2_CSRTOP;                             //~v59ZI~
            else                                                   //~v59ZI~
	        	opt2|=FINDOPT2_CSRBOTTOM;                          //~v59ZI~
            pc++;                                                  //~v59ZR~
            numlen=(int)strlen(pc);                                //~v603R~
            if (numlen)                                            //~v59ZI~
	            numlen=unumlen(pc,0,numlen);                       //~v59ZI~
            if (numlen)                                            //~v59ZI~
            {                                                      //~v59ZI~
            	linectr=atoi(pc);                                  //~v59ZR~
                if (linectr)                                       //~v59ZI~
                	linectr--;                                     //~v59ZI~
            }                                                      //~v59ZI~
            else                                                   //~v59ZI~
            	linectr=0;                                         //~v59ZI~
//          opt2=(opt2&~FINDOPT2_CSRLINEMASK)|(linectr&FINDOPT2_CSRLINEMASK);//~v59ZI~//~vb2DR~
            opt2=(opt2&(ULONG)(~FINDOPT2_CSRLINEMASK))|(linectr&FINDOPT2_CSRLINEMASK);//~vb2DI~
            pc+=numlen-1;                                          //~v59ZI~
        	break;                                                 //~v59ZI~
        default:                                                   //~v59ZM~
            return 4;                                              //~v59ZI~
        }//sw                                                      //~v59ZI~
    }//loop                                                        //~v59ZI~
    *Ppopt2=opt2;                                                  //~v59ZI~
    return 0;                                                      //~v59ZI~
}//fcmdgetcsropt                                                   //~v59ZI~
//**************************************************************** //~v0eBI~
//!fcmdoperandrearange                                             //~v0eBR~
//* parm1 :pcw                                                     //~v0eBI~
//* parm2 :change opt;1:change,0:find                              //~v0eBI~
//* parm3 :in/out,operandno after range parm dropped               //~v0eBI~
//* parm4 :in/out,operand string tbl after range parm dropped      //~v0eBI~
//* parm5 :in/out,operand delm tbl after range parm dropped        //~v0eBI~
//* parm6 :output from range id                                    //~v0eBR~
//* parm7 :output to range id                                      //~v0eBR~
//* parm8 :output other option                                     //~v41rI~
//* return:rc 0 or 4                                               //~v0eBI~
//**************************************************************** //~v0eBI~
int fcmdoperandrearange(PUCLIENTWE Ppcw,int Pchangeopt,int *Popdno,//~v0eBR~
//				char **Popd,UPODELMTBL *Podt,SHORT *Pposfrom,SHORT *Pposto,//~v58rR~
  				char **Popd,UPODELMTBL *Podt,                      //~v58rI~
                int Pfindopt,int *Pinttbl,                         //~v58rI~
				SHORT *Pposfrom,SHORT *Pposto,                     //~v58rI~
				SHORT *Pposfromand,SHORT *Ppostoand,int *Ppopt)    //~v532R~
{                                                                  //~v0eBI~
static char *S1stmerginid="LM";                                    //~v0ePR~
static char *S2ndmerginid="RM";                                    //~v0ePR~
//static char *Smaxrightid ="MAX";                                 //~v551R~
static char *Smaxrightid ="MAXEOL";                                //~v551R~
static char *Seolid      ="EOL";                                   //~v54ZI~
static char *Sattrid     =ATTRID;                                  //~vbc1I~//~vbc3R~
//static char *Stsid       ="TS";                                    //~vbc2I~//~vbc3R~
    PUFILEH pfh;                                                   //~v0eBI~
	int merginsw,mergin1sw,opdno,ii,len;                           //~v0eBR~
	int rangesw,datasw,subcmdsw;                                   //~v0eBI~
//  int wkflg;                                                     //~v43pR~
    char *opd;                                                     //~v0eBI~
    char *andstr=0;                                                //~v43eI~
    char *op1p=0,*op2p=0,*subcmdp=0,*pos1p=0,*pos2p=0;             //~v0eBI~
//  UPODELMTBL odtii,op1dt,op2dt,subcmddt=0,anddt;                   //~v43eR~//~vaf9R~
    UPODELMTBL odtii,op1dt={0,0,0},op2dt={0,0,0},subcmddt={0,0,0},anddt={0,0,0};//~vaf9R~
    int pos1=RANGENOPARM,pos2=RANGENOPARM,pos;                     //~v0eBR~
//  int pos1sv,pos2sv,andpossw=0,pos1and,pos2and;                  //~v532R~//~vaf9R~
    int pos1sv=0,pos2sv=0,andpossw=0,pos1and,pos2and;              //~vaf9I~
    int labctr=0;                                                  //~v0hxI~
    int labstart;                                                  //~v43aI~
    int nolabsw;                                                   //~v10qI~
//*********************************                                //~v0eBI~
    *Ppopt=0;                   //clear output                     //~v41rI~
	*Slab[0]=0; *Slab[1]=0;		//clear                            //~v0hxI~
	pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v0eBI~
    merginsw=UCBITCHK(pfh->UFHflag2,UFHF2MERGIN);                  //~v0eBI~
    opdno=*Popdno;                                                 //~v0eBI~
    if (Pchangeopt)                                                //~v10qI~
    {                                                              //~v43aI~
    	if (opdno==2)                                              //~v10qI~
        	nolabsw=1;                                             //~v10qI~
        else                                                       //~v10qI~
        	nolabsw=0;                                             //~v10qI~
        labstart=2;                                                //~v43aI~
    }                                                              //~v43aI~
	else                                                           //~v10qI~
    {                                                              //~v43aI~
    	if (opdno==1)                                              //~v10qI~
        	nolabsw=1;                                             //~v10qI~
        else                                                       //~v10qI~
        	nolabsw=0;                                             //~v10qI~
        labstart=1;                                                //~v43aI~
    }                                                              //~v43aI~
	for (ii=0;ii<opdno;ii++)                                       //~v0eBI~
	{                                                              //~v0eBI~
    	opd=Popd[ii];                                              //~v0eBI~
    	odtii=Podt[ii];                                            //~v0eBI~
        rangesw=0;                                                 //~v0eBI~
        datasw=0;                                                  //~v0eBI~
        subcmdsw=0;                                                //~v0eBI~
        if (*opd==ULCCMDLABEL)  //lebel specified                  //~v0hxI~
          if (Ppcw->UCWtype!=UCWTDIR)                              //~v0hCI~
			if (!odtii.upoquate)		//not in quatation         //~v0hxI~
            if (!nolabsw)                                          //~v10qI~
            if (ii>=labstart)                                      //~v43aI~
            {                                                      //~v0hxI~
                if (labctr==MAXLABEL)                              //~v0hxI~
                    return fcmdlabelerr("Too many");               //~v0hxI~
                strncpy(Slab[labctr],opd,ULHLINENOSZ);             //~v0hxI~
                labctr++;                                          //~v0hxI~
                continue;       //skip other process               //~v0hxI~
        	}                                                      //~v0hxI~
		if (odtii.upoquate		//in quatation                     //~v0eBI~
        ||  !srchsubcmd(opd))	//or not subcmd                    //~v0eBI~
        	datasw=1;                                              //~v0eBI~
        else                        //not quat and subcmd          //~v0eBI~
        {                                                          //~v0eBI~
        	subcmdsw=1;                                            //~v0eBI~
        	if (!subcmdp)          //1st subcmd                    //~v0eBI~
            {                                                      //~v0eBI~
            	subcmdp=opd;         //get 1st                     //~v0eBI~
            	subcmddt=odtii;      //get 1st                     //~v0eBI~
			}                                                      //~v0eBI~
            else                    //2nd submcd                   //~v0eBI~
            	if (!op1p || !op2p)                                //~v0eBI~
                {                                                  //~v0eBI~
                    opd=subcmdp;    //shift                        //~v0eBI~
                    odtii=subcmddt; //shift                        //~v0eBI~
                    subcmdp=Popd[ii];                              //~v0eBI~
                    subcmddt=Podt[ii];                             //~v0eBI~
                    datasw=1;                                      //~v0eBI~
				}                                                  //~v0eBI~
                else                                               //~v0eBI~
                	return errinvalid(opd);//need quatation        //~v0eBR~
		}//subcmd                                                  //~v0eBI~
//*get data                                                        //~v0eBI~
        if (datasw)                                                //~v0eBI~
        {                                                          //~v0eBI~
        	if (!op1p)             //first opd                     //~v0eBI~
            {                                                      //~v0eBI~
				if (!odtii.upoquate		//not in quatation         //~v41rI~
                &&  !Pchangeopt         //find                     //~v41rI~
          		&&   Ppcw->UCWtype!=UCWTDIR  //file scr            //~v41rI~
              )                                                    //~v43eI~
              {                                                    //~v43eI~
                if (!strcmp(opd,STR_SEARCH_NOT) && opdno>1) //*!   //~v43uR~
                {                                                  //~v41rI~
					*Ppopt=*Ppopt|SEARCH_NOT; //search line not contains the word "*!"//~v41rI~
                    datasw=0;                                      //~v41rI~
                }                                                  //~v41rI~
                else                                               //~v41rI~
//                if (!strcmp(opd,STR_SEARCH_AND)) //*&            //~v43oR~
//                {                                                //~v43oR~
//                    *Ppopt=*Ppopt|SEARCH_AND; //search line not contains the word "*!"//~v43oR~
//                    datasw=0;                                    //~v43oR~
//                }                                                //~v43oR~
//                else                                             //~v43oR~
                {                                                  //~v41rI~
            	op1p=opd;            //get 1st                     //~v0eBI~
                op1dt=odtii;                                       //~v0eBI~
                }                                                  //~v41rI~
              }                                                    //~v43eI~
              else                                                 //~v43eI~
              {                                                    //~v43eI~
            	op1p=opd;            //get 1st                     //~v43eI~
                op1dt=odtii;                                       //~v43eI~
              }                                                    //~v43eI~
			}                                                      //~v0eBI~
            else                    //second opd                   //~v0eBI~
            	if (!Pchangeopt)	//find                         //~v43eR~
                {                                                  //~v43eI~
					if (*Ppopt & SEARCH_AND)//and option           //~v43eR~
                    	if (!andstr)                               //~v43eI~
                        {                                          //~v43eI~
                			if (!strcmp(opd,STR_SEARCH_NOT) //!    //~v43wI~
							&&  !odtii.upoquate)		//not in quatation//~v43wR~
                			{	                                   //~v43wI~
								*Ppopt=*Ppopt|SEARCH_NOT2; //search line not contains the word "*!"//~v43wI~
                    			datasw=0;                          //~v43wI~
                			}                                      //~v43wI~
                    		else                                   //~v43wI~
                            {                                      //~v43wI~
                        	andstr=opd;                            //~v43eI~
                        	anddt=odtii;                           //~v43eI~
                            }                                      //~v43wI~
                        }                                          //~v43eI~
                        else                                       //~v43eI~
                        	rangesw=1;                             //~v43eI~
                    else                                           //~v43eI~
                		if (!strcmp(opd,STR_SEARCH_AND)) //*&      //~v43oI~
                		{                                          //~v43oI~
							*Ppopt=*Ppopt|SEARCH_AND; //search line not contains the word "*!"//~v43oI~
                    		datasw=0;                              //~v43oI~
//                          if (pos1p)	//already pos parm specified//~v538R~
//                          {                                      //~v538R~
                                andpossw=1;                        //~v532I~
                            	pos1sv=pos1;                       //~v532I~
                            	pos2sv=pos2;                       //~v532I~
                                pos1p=0;			//get 2nd col parm of & srch//~v532I~
                                pos2p=0;			//get 2nd col parm of & srch//~v532I~
    							pos1=RANGENOPARM;	//init for 2nd word col//~v532I~
								pos2=RANGENOPARM;                  //~v532I~
//                          }                                      //~v538R~
                		}                                          //~v43oI~
                    else                                           //~v43oI~
                    rangesw=1;      //chk range parm               //~v0eBI~
                }                                                  //~v43eI~
                else                //chng cmd                     //~v0eBI~
                    if (!op2p)		//2nd opd                      //~v0eBI~
                    {                                              //~v0eBI~
                        op2p=opd;   //get 2nd                      //~v0eBI~
                        op2dt=odtii;//get 2nd                      //~v0eBI~
						*Ppopt=*Ppopt|SEARCH_REPWORD; //parm to fcmdchkucsopt,ucs opt is for repword//~vax1I~
					}                                              //~v0eBI~
                    else            //3rd data opd                 //~v0eBI~
	                	rangesw=1;		//chk range parm           //~v0eBI~
        }//datasw                                                  //~v0eBI~
//*get range                                                       //~v0eBI~
        if (rangesw)                //                             //~v0eBI~
        {                                                          //~v0eBI~
#ifdef UTF8SUPPH                                                   //~va1qI~
        	if (fcmdchkucsopt(opd,Ppopt))	//ucs option chk       //~va0cI~
            	continue;					//accepted             //~va0cI~
#endif                                                             //~va1qI~
        	if (Ppcw->UCWtype==UCWTDIR)//no support for dir        //~v0eBI~
            {                                                      //~vbc2I~
        	  if (stricmp(opd,Sattrid))                            //~vbc1I~
//      	   if (stricmp(opd,Stsid))                             //~vbc2I~//~vbc3R~
                return errconflict(opd,0);//duplicate              //~v43mI~
            }                                                      //~vbc2I~
        	if (subcmdsw)                                          //~v0eBI~
            	return errinvalid(opd);//subcmd data but data filled alre//~v0eBR~
        	if (!(mergin1sw=stricmp(opd,S1stmerginid))             //~v0eBI~
            ||  !stricmp(opd,S2ndmerginid)) 	//mergin specifi   //~v0eBI~
            {                                                      //~v0eBI~
            	if (!merginsw)	                                   //~v0eBI~
	                return errinvalid(opd);//not mergned f         //~v0eBR~
            	if (pos1p)                                         //~v0eBI~
	                return errtoomany();//duplicated               //~v0eBR~
                pos1p=pos2p=opd;                                   //~v0eBI~
                if (!mergin1sw)		//mergin1                      //~v0eBI~
                    pos2=RANGE1M;                                  //~v0eBR~
                else                                               //~v0eBI~
                    pos2=RANGE2M;                                  //~v0eBR~
			}//mergin specified                                    //~v0eBI~
            else					//not mergin                   //~v0eBI~
        	if (!stricmp(opd,Smaxrightid))                         //~v54RI~
            {                                                      //~v54RI~
            	if (pos1p)                                         //~v54RI~
	                return errtoomany();//duplicated               //~v54RI~
                pos1p=pos2p=opd;                                   //~v54RI~
                pos2=RANGEMAX;                                     //~v54RI~
			}//mergin specified                                    //~v54RI~
            else					//not mergin                   //~v54RI~
        	if (!stricmp(opd,Seolid))                              //~v54ZI~
            {                                                      //~v54ZI~
            	if (pos1p)                                         //~v54ZI~
	                return errtoomany();//duplicated               //~v54ZI~
                pos1p=pos2p=opd;                                   //~v54ZI~
                pos2=RANGEEOL;                                     //~v54ZI~
                if (Pfindopt & FINDOPT_GREP)                       //~v78dI~
                    return errconflict(opd,"grep option");//duplicate//~v78dI~
			}//mergin specified                                    //~v54ZI~
            else					//not mergin                   //~vbc1I~
        	if (!stricmp(opd,Sattrid))                             //~vbc1I~
            {                                                      //~vbc1I~
      	  		if (Ppcw->UCWtype!=UCWTDIR)     //on dir list      //~vbc1I~
					return finderr_notdirlist(Sattrid);            //~vbc1I~
            	if (pos1p)                                         //~vbc1I~
	                return errtoomany();//duplicated               //~vbc1I~
                pos1p=pos2p=opd;                                   //~vbc1I~
                pos2=RANGEATTR;                                    //~vbc1I~
			}//mergin specified                                    //~vbc1I~
//            else                    //not mergin                   //~vbc2I~//~vbc3R~
//            if (!stricmp(opd,Stsid))                               //~vbc2I~//~vbc3R~
//            {                                                      //~vbc2I~//~vbc3R~
//                if (Ppcw->UCWtype!=UCWTDIR)     //on dir list      //~vbc2I~//~vbc3R~
//                    return finderr_notdirlist(Stsid);              //~vbc2I~//~vbc3R~
//                if (pos1p)                                         //~vbc2I~//~vbc3R~
//                    return errtoomany();//duplicated               //~vbc2I~//~vbc3R~
//                pos1p=pos2p=opd;                                   //~vbc2I~//~vbc3R~
//                pos2=RANGETS;                                      //~vbc2I~//~vbc3R~
//            }//mergin specified                                    //~vbc2I~//~vbc3R~
            else					//not mergin                   //~v54ZI~
            {                                                      //~v0eBI~
            	len=(int)strlen(opd);                              //~v0eBI~
                if (len!=unumlen(opd,0,len))	//digit len        //~v0eBI~
	                return errinvalid(opd);//duplicate             //~v0eBR~
				pos=atoi(opd)-1;                                   //~v0eBI~
                if (pos<0)                                         //~v0eBI~
	                return errinvalid(opd);//duplica               //~v0eBR~
            	if (!pos1p)                                        //~v0eBI~
                {                                                  //~v0eBI~
                	pos1p=opd;                                     //~v0eBI~
                    pos1=pos;                                      //~v0eBR~
                    pos2=RANGE1ONLY;                               //~v0eBI~
				}                                                  //~v0eBI~
                else                                               //~v0eBI~
                    if (!pos2p)                                    //~v0eBI~
                    {                                              //~v0eBI~
	                	pos2p=opd;                                 //~v0eBI~
                        pos2=pos+1;	//next addr                    //~v0eBR~
                        if (pos1>pos2)	                           //~v0eBI~
			                return errinvalid(opd);                //~v0eBR~
                    }                                              //~v0eBI~
                    else			//3rd pos                      //~v0eBI~
		                return errtoomany();//dup                  //~v0eBR~
			}//not mergin                                          //~v0eBI~
		}//rangesw                                                 //~v0eBI~
	}//opdno loop                                                  //~v0eBI~
                                                                   //~v43kI~
	pos1and=pos1;	//for & case   "pos & -"  and "pos & pos"      //~v532I~
	pos2and=pos2;                                                  //~v532I~
    if (andpossw)	//save pos of before &                         //~v532I~
    {                                                              //~v532I~
		pos1=pos1sv;	//for & case   "pos & -"  and "pos & pos"  //~v532I~
		pos2=pos2sv;                                               //~v532I~
    }                                                              //~v532I~
//    wkflg=(*Ppopt & (SEARCH_AND|SEARCH_NOT));                    //~v43pR~
//    if (wkflg && wkflg==(SEARCH_AND|SEARCH_NOT))                 //~v43pR~
//    {                                                            //~v43pR~
//        uerrmsg("%s and %s is conflict",                         //~v43pR~
//                "%s と %s は両方指定できません。",               //~v43pR~
//                    STR_SEARCH_NOT,STR_SEARCH_AND);              //~v43pR~
//        return 4;                                                //~v43pR~
//    }                                                            //~v43pR~
//*set result                                                      //~v0eBI~
	if (labctr&1)	//odd number                                   //~v0hxI~
//  	return fcmdlabelerr("Need From/To");                       //~v0hxR~//~vbq2R~
    	return fcmdlabelerr("Need From/To, or Enclose search word by parenthesis");//~vbq2R~
	opdno=0;                                                       //~v0eBI~
	if (op1p)                                                      //~v0eBI~
	{                                                              //~v0eBI~
        Popd[0]=op1p;                                              //~v0eBI~
        Podt[0]=op1dt;                                             //~v0eBI~
    	opdno++;                                                   //~v0eBI~
    }                                                              //~v0eBI~
	if (op2p)                                                      //~v0eBI~
	{                                                              //~v0eBI~
        Popd[opdno]=op2p;                                          //~v0eBI~
        Podt[opdno]=op2dt;                                         //~v0eBI~
    	opdno++;                                                   //~v0eBI~
    }                                                              //~v0eBI~
	if (subcmdp)                                                   //~v0eBI~
	{                                                              //~v0eBI~
        Popd[opdno]=subcmdp;                                       //~v0eBI~
        Podt[opdno]=subcmddt;                                      //~v0eBI~
    	opdno++;                                                   //~v0eBI~
    }                                                              //~v0eBI~
	if (*Ppopt & SEARCH_AND)//and option                           //~v43eI~
    {                                                              //~v43eI~
		if (!andstr)                                               //~v43eR~
        	return errmissing();                                   //~v43eM~
        Popd[opdno]=andstr;                                        //~v43eR~
        Podt[opdno]=anddt;                                         //~v43eR~
    }                                                              //~v43eI~
	*Popdno=opdno;                                                 //~v54ZI~
	*Pposfrom=(SHORT)pos1;                                         //~v11oR~
	*Pposto=(SHORT)pos2;                                           //~v11oR~
	*Pposfromand=(SHORT)pos1and;                                   //~v532R~
	*Ppostoand=(SHORT)pos2and;                                     //~v532R~
	if (Pfindopt&FINDOPT_DISTOPT)	//join to eof                  //~v58rR~
    {                                                              //~v58rI~
		if (!(*Ppopt & SEARCH_AND))//no and option                 //~v58rI~
        {                                                          //~v58rI~
        	uerrmsg("-d option is for & search only",              //~v58rI~
            		"-d オプションは & 探索用です。");             //~v58rI~
            return 4;                                              //~v58rI~
        }                                                          //~v58rI~
    }                                                              //~v58rI~
    return 0;                                                      //~v0eBI~
}//fcmdoperandrearange                                             //~v0eBR~
                                                                   //~v0eBI~
//**************************************************************** //~v0eBI~
//!fcmdsetrange                                                    //~v0eBI~
//* parm4 :input pos1 by oerand rearange                           //~v0eBR~
//* parm5 :input pos2 by oerand rearange                           //~v0eBR~
//* parm6 :output pos1                                             //~v0eBR~
//* parm7 :output pos2                                             //~v0eBR~
//* return:rc                                                      //~v0eBR~
//**************************************************************** //~v0eBI~
//int  fcmdsetrange(PUCLIENTWE Ppcw,int Pnorangeopt,int Pwordlen,    //~v0eBR~//~vbc1R~
int  fcmdsetrange(PUCLIENTWE Ppcw,int Pnorangeopt,char *Psrchword,int Pwordlen,//~vbc1R~
				SHORT Ppos1,SHORT Ppos2,SHORT *Prange1,SHORT *Prange2)//~v11oR~
{                                                                  //~v0eBI~
    PUFILEH pfh;                                                   //~v0eBI~
	int mergin,merginsw,rc;                                        //~v0eBR~
    int range1,range2;                                             //~v11oR~
    int bndsoffs1,bndsoffs2;                                       //~v74ER~
//*********************************                                //~v0eBI~
	pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v0eBI~
    merginsw=UCBITCHK(pfh->UFHflag2,UFHF2MERGIN);                  //~v0eBI~
    mergin=pfh->UFHmergin;                                         //~v0eBI~
    range1=0;                                                      //~v0eBI~
    range2=MAXRIGHT;                                               //~v0eBI~
    rc=0;                                                          //~v0eBI~
    switch((int)Ppos2)                                             //~v437R~
    {                                                              //~v0eBI~
    case RANGE1M:                                                  //~v0eBI~
    	if (merginsw)	//                                         //~v0eBI~
    		range2=mergin;	//next of end                          //~v0eBR~
    	break;                                                     //~v0eBI~
    case RANGE2M:                                                  //~v0eBI~
    	if (merginsw)	//                                         //~v0eBI~
    		range1=mergin;                                         //~v0eBR~
    	break;                                                     //~v0eBI~
    case RANGE1ONLY:                                               //~v0eBI~
    	if (Pnorangeopt==LINE_SAMESRCH)                            //~v54CI~
        {                                                          //~v54CI~
//          uerrmsg("specify none or both of from and to for *= search column range",//~v54CI~//~vb86R~
//  	            "*= 探索では桁範囲を指定する時は開始終了の両方を指定する。");//~v54CI~//~vb86R~
            uerrmsg("Specify none or both of From/To colomn for *= search",//~vb86I~
    	            "*= 探索では桁範囲を指定する時は開始/終了の両方を指定する。");//~vb86I~
            return 4;        	                                   //~v54CI~
        }                                                          //~v54CI~
    	range1=Ppos1;                                              //~v0eBI~
    	range2=Ppos1+Pwordlen;  	//next of end                  //~v0eBR~
    	break;                                                     //~v0eBI~
    case RANGENOPARM:                                              //~v0eBI~
        bndsoffs1=pfh->UFHbndscol1;                                //~v74EI~
        bndsoffs2=pfh->UFHbndscol2;                                //~v74EI~
        if (bndsoffs1)                                             //~v74EI~
    		range1=bndsoffs1-1;                                    //~v74EI~
        if (bndsoffs2)                                             //~v74EI~
    		range2=bndsoffs2;                                      //~v74ER~
    	break;                                                     //~v74EI~
    case RANGEEOL:      //no range,search each line at eol by logic//~v54ZI~
    	break;                                                     //~v0eBI~
    case RANGEMAX:                                                 //~v54RI~
	    if (rc=fsubgetmaxlen(FSGML_TABEXP,pfh,&range2,0),rc)//0:no contline len//~v54RR~
	    	return rc;                                             //~v54RI~
    	range1=range2-Pwordlen;  	//next of end                  //~v54RI~
    	break;                                                     //~v54RI~
    case RANGEATTR:                                                //~vbc1I~
    	if (Pwordlen>1 &&  strpbrk(Psrchword,"DdLl"))//other attr with dir/slink//~vbc1R~
        {                                                          //~vbc1I~
        	uerrmsg("Do not mix other ATTR with D(directory) and L(simbolic link).",//~vbc1I~
                    "D(ディレクトリー) と L(シンボリックリンク)はそれぞれ単独で指定してください");//~vbc1R~
        	return 4;                                              //~vbc1I~
        }                                                          //~vbc1I~
    	break;                                                     //~vbc1I~
    case RANGETS:                                                  //~vbc2I~
    	break;                                                     //~vbc2I~
    default:                //from to specified                    //~v0eBR~
    	range1=Ppos1;                                              //~v0eBI~
    	range2=Ppos2;     	//pos2 already +1                      //~v0eBR~
    }//sw by pos2                                                  //~v0eBI~
    if ((int)Ppos2!=RANGENOPARM                                    //~v437R~
    &&  Pnorangeopt!=LINE_SAMESRCH                                 //~v49bI~
    &&  Pnorangeopt!=LINE_SAMEMATCH                                //~v62dI~
    &&  Pnorangeopt)                                               //~v0eBI~
    {                                                              //~v0eBI~
        uerrmsg("range not support for this type search",          //~v0eBI~
                "このタイプでは探索範囲指定出来ません");           //~v0eBI~
        rc=4;                                                      //~v0eBI~
    }                                                              //~v0eBI~
    else                                                           //~v0eBI~
        if (range2<range1+Pwordlen)                                //~v0eBR~
        {                                                          //~v0eBR~
//  	  if (Pnorangeopt!=LINE_SAMESRCH)                          //~v62dR~
    	  if (Pnorangeopt!=LINE_SAMESRCH                           //~v62dI~
		  &&  Pnorangeopt!=LINE_SAMEMATCH)                         //~v62dI~
          {                                                        //~v54CI~
            uerrmsg("range parm too narrow",                       //~v0eBR~
                    "探索範囲指定が狭過ぎる");                     //~v0eBR~
            rc=4;                                                  //~v0eBR~
          }//not same srch                                         //~v54CI~
        }                                                          //~v0eBR~
  if (!rc)                                                         //~v0eHI~
  {                                                                //~v0eHI~
	*Prange1=(SHORT)range1;                                        //~v11oR~
	*Prange2=(SHORT)range2;                                        //~v11oR~
  }                                                                //~v0eHI~
    return rc;                                                     //~v0eBR~
}//fcmdsetrange                                                    //~v0eBI~
                                                                   //~v0eBI~
//*******************************
//!srchsubcmd *******************
//*******************************
int srchsubcmd(char *Psubcmd)                                   //~5114R~
{
#define SUBCMDSZ 6                                                 //~v0eBM~
static char Ssubcmdtbl[][SUBCMDSZ]=                                //~v0eBM~
//  {"FIRST","LAST","NEXT","PREV","ALL","+","-",""};               //~v537R~
    {"FIRST","LAST","NEXT","PREV","ALL","+","-","ALLKX",""};       //~v537R~
static int  Ssubcmdidtbl[]=                                        //~v0eBM~
	{SUBCMD_FIRST,SUBCMD_LAST,SUBCMD_NEXT,SUBCMD_PREV,SUBCMD_ALL,  //~v537R~
//   SUBCMD_NEXT,SUBCMD_PREV,0};                                   //~v537R~
     SUBCMD_NEXT,SUBCMD_PREV,SUBCMD_ALLKX,0};                      //~v532I~
	int i;
    UCHAR *subcmdtbl;                                           //~5114I~
//********************
	for (i=0,subcmdtbl=(UCHAR*)Ssubcmdtbl;*subcmdtbl;i++,subcmdtbl+=SUBCMDSZ)//~5114R~
		if (!stricmp(Psubcmd,subcmdtbl))                        //~5114R~
			return Ssubcmdidtbl[i];                             //~5114R~
	return 0;
}//srchsubcmd
#ifdef UTF8SUPPH                                                   //~va1qI~
//**************************************************************** //~va0cI~
//!fcmdchkucsopt                                                   //~va0cI~
//check option to search by unicode                                //~va0cI~
//return 0:not ucsopt,1:accept ucs opt                             //~va0cI~
//**************************************************************** //~va0cI~
int fcmdchkucsopt(char *Popd,int *Ppopt)                           //~va0cI~
{                                                                  //~va0cI~
	int ch,opt=0;                                                    //~va0cI~//~vafdR~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~//~vax1R~
    int swucs4=0;                                                  //~va3xI~//~vax1R~
#endif                                                             //~va3xI~//~vax1R~
//********************                                             //~va0cI~
	if (toupper(*Popd)!=FCMDOPT_UCSSTR)                            //~va0cI~
    	return 0;                                                  //~va0cI~
    ch=toupper(*(Popd+1));                                         //~va0cI~
    if (!ch)                                                       //~va0cI~
#ifdef BIGENDIAN                                                   //~va0cI~
//  	opt=SEARCH_UCS|SERACH_UCSBE;                               //~va26R~
    	opt=SEARCH_UCS|SEARCH_UCSBE;                               //~va26I~
#else                                                              //~va0cI~
		opt=SEARCH_UCS;                                            //~va0cI~
#endif                                                             //~va0cI~
    else                                                           //~va0cI~
	if (ch==FCMDOPT_BIG)                                           //~va0cI~
		opt=SEARCH_UCS|SEARCH_UCSBE;                               //~va0cR~
    else                                                           //~va0cI~
	if (ch==FCMDOPT_LITTLE)                                        //~va0cI~
		opt=SEARCH_UCS;                                            //~va0cI~
	else                                                           //~va0cI~
	if (ch==FCMDOPT_UTF8)                                          //~va0yI~
		opt=SEARCH_UCS|SEARCH_UTF8;                                //~va0yR~
    else                                                           //~va0yI~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
	if (ch==FCMDOPT_UCS4)                                          //~va3xI~
    {                                                              //~vax1I~
      if (*Ppopt & SEARCH_REPWORD)                                 //~vax1R~
        swucs4=1;                                                  //~va3xI~//~vax1R~
      else                                                         //~vax1I~
		opt=SEARCH_UCS|SEARCH_UCS4SW;                              //~vax1R~
    }                                                              //~vax1I~
    else                                                           //~va3xI~
#endif                                                             //~va1CI~//~va3xI~
		return 0;		//not ucs opt                              //~va0cI~
    if (*Ppopt & SEARCH_AND)	//after "&" ,2nd word              //~va0cI~//~vax1R~
    {                                                              //~vax1I~
    	opt<<=1;				//2nd word                         //~va0cI~
    }                                                              //~vax1I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~//~vax1R~
    if (swucs4)                                                    //~va3xI~//~vax1R~
        opt|=SEARCH_UCS4;                                           //~va3xI~//~vax1R~
#endif                                                             //~va3xI~//~vax1R~
    *Ppopt=*Ppopt|opt;                                             //~va0cI~
	return 1;                                                      //~va0cI~
}//fcmdchkucsopt                                                   //~va0cI~
#endif                                                             //~va1qI~
//****************************************************************//~5104I~
//!fcmdscrollpage                                               //~5104I~
// page scroll to set spceified line disply on 1st or 2nd line if avail//~5104I~
//* parm1 :pcw                                                  //~5104I~
//* parm2 :plh                                                  //~5104I~
//* rc    :result csr pos y                                     //~5104I~
//****************************************************************//~5104I~
int fcmdscrollpage(PUCLIENTWE Ppcw,PULINEH Pplh)                //~5104I~
{                                                               //~5104I~
	int row;                                                    //~5104I~
	PULINEH plh;                                                //~5104I~
	PUFILEC pfc;                                                //~5104I~
    int rc,plhcount;                                               //~v698I~
//*****************                                             //~5104I~
//search plh on the range current screen height                 //~5104I~
	pfc=Ppcw->UCWpfc;                                           //~5104I~
  if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                           //~v698I~
  {                                                                //~v698I~
	rc=fcmdcountvhexline(Ppcw,pfc,Pplh,&plhcount); //plh found in the current screen//~v698I~
    row=plhcount+Ppcw->UCWfilehdrlineno;	//posy value           //~v698I~
	if ((rc=fcmdcountvhexline(Ppcw,pfc,Pplh,&plhcount))==1) //plh found in the current screen//~v698I~
		return row;     //no need to scroll                        //~v698I~
	pfc->UFCcurtop=Pplh;	//once set to top                      //~v698I~
    if (plhcount>2||(plhcount==2 && rc==0))	//more than 3 plh displayled or fully 2 plh displayed//~v698R~
	{                                                              //~v698I~
      if (Smidsw)                                                  //~v698I~
      {                                                            //~v698I~
      		                                                       //~v698I~
    		plhcount=(int)(((UINT)(plhcount+1)>>1)-1);	//mid point//~v698R~
            if (plhcount)                                          //~v698I~
				if (plh=getdisplayline(Pplh,-plhcount,0),plh)//get prev line//~v698I~
                {                                                  //~v698I~
					pfc->UFCcurtop=plh;                            //~v698I~
        			row=plhcount+Ppcw->UCWfilehdrlineno;           //~v698I~
            	}                                                  //~v698I~
	  }                                                            //~v698I~
      else                                                         //~v698I~
		if (plh=getdisplayline(Pplh,-1,0),plh)//get prev line      //~v698I~
		{                                                          //~v698I~
			row++;                                                 //~v698I~
			pfc->UFCcurtop=plh;                                    //~v698I~
		}                                                          //~v698I~
	}                                                              //~v698I~
  }                                                                //~v698I~
  else      //not 3line hex display                                //~v698I~
  {                                                                //~v698I~
//  for (row=FILEHDRLINENO,plh=pfc->UFCcurtop;                     //~v11NR~
    for (row=Ppcw->UCWfilehdrlineno,plh=pfc->UFCcurtop;            //~v11NI~
		 plh && row<Ppcw->UCWheight;                            //~5104I~
		 plh=UGETQNEXT(plh))                                    //~5104I~
	{                                                           //~5104I~
		if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))              //~5104I~
			continue; 				//do not count line         //~5104I~
		if (plh==Pplh)	//on current screen                     //~5104I~
			break;                                              //~5104I~
		row++;	                                                //~5104I~
	}	                                                        //~5104I~
	if (plh==Pplh && row<Ppcw->UCWheight)//on current page      //~5104I~
		return row;                                             //~5104I~
//  row=FILEHDRLINENO;                                             //~v11NR~
    row=Ppcw->UCWfilehdrlineno;                                    //~v11NI~
	pfc->UFCcurtop=Pplh;                                        //~5104I~
//  if (Ppcw->UCWheight>FILEHDRLINENO+1)	//more than 2 line height//~v11NR~
    if (Ppcw->UCWheight>row+1)	//more than 2 line height          //~v11NI~
	{                                                           //~5104I~
      if (Smidsw)                                                  //~v11gI~
      {                                                            //~v11gI~
//  		row=((Ppcw->UCWheight-FILEHDRLINENO+1)>>1)-1;	//mid point//~v11NR~
    		row=(int)(((UINT)(Ppcw->UCWheight-row+1)>>1)-1);	//mid point//~v47BR~
            if (row)                                               //~v11gI~
				if (plh=getdisplayline(Pplh,-row,0),plh)//get prev line//~v11gR~
					pfc->UFCcurtop=plh;                            //~v11gR~
//      	row+=FILEHDRLINENO;                                    //~v11NR~
        	row+=Ppcw->UCWfilehdrlineno;                           //~v11NI~
	  }	                                                           //~v11gI~
      else                                                         //~v11gI~
		if (plh=getdisplayline(Pplh,-1,0),plh)//get prev line   //~5204R~
		{                                                       //~5104I~
			row++;                                              //~5104I~
			pfc->UFCcurtop=plh;                                 //~5104I~
		}                                                       //~5104I~
	}                                                           //~5104I~
  }//not 3line hex display                                         //~v698I~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);                            //~5104I~
    return row;                                                 //~5104I~
}//fcmdscrollpage                                               //~5104I~
//**************************************************************** //~v11gI~
//!fcmdscrollpagemid                                               //~v11gI~
// page scroll to set spceified line disply on middle of page      //~v11gI~
//* parm1 :pcw                                                     //~v11gI~
//* parm2 :plh                                                     //~v11gI~
//* rc    :result csr pos y                                        //~v11gI~
//**************************************************************** //~v11gI~
int fcmdscrollpagemid(PUCLIENTWE Ppcw,PULINEH Pplh)                //~v11gI~
{                                                                  //~v11gI~
    int rc;                                                        //~v11gI~
//*****************                                                //~v11gI~
	Smidsw=1;                                                      //~v11gI~
	rc=fcmdscrollpage(Ppcw,Pplh);                                  //~v11gR~
	Smidsw=0;                                                      //~v11gI~
    return rc;                                                     //~v11gI~
}//fcmdscrollpagemid                                               //~v11gI~
//**************************************************************** //~v59ZI~
//!fcmdfindscroll                                                  //~v59ZI~
// page scroll by scroll param                                     //~v59ZI~
//* parm1 :pcw                                                     //~v59ZI~
//* parm2 :plh                                                     //~v59ZI~
//* rc    :result csr pos y                                        //~v59ZI~
//**************************************************************** //~v59ZI~
int fcmdfindscroll(PUCLIENTWE Ppcw,PULINEH Pplh,ULONG Popt2)       //~v59ZI~
{                                                                  //~v59ZI~
    int csrline,scrheight;                                         //~v59ZR~
	PULINEH plhtop=0;                                              //~v59ZI~
	PUFILEC pfc;                                                   //~v59ZI~
    int vhexmode;                                                  //~v698I~
//*****************                                                //~v59ZI~
	if (!(Popt2&FINDOPT2_CSRMIDDLE))	//line position parm not exist//~v59ZI~
		return fcmdscrollpagemid(Ppcw,Pplh);                       //~v59ZI~
    csrline=(int)(Popt2&FINDOPT2_CSRLINEMASK);                     //~v59ZI~
	pfc=Ppcw->UCWpfc;                                              //~v59ZI~
    vhexmode=UCBITCHK(pfc->UFCflag2,UFCF2VHEX);                    //~v698I~
    scrheight=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;              //~v59ZI~
    if (scrheight<=1)                                              //~v59ZI~
    	plhtop=Pplh;                                               //~v59ZI~
    else                                                           //~v59ZI~
	{                                                              //~v59ZI~
		if (Popt2&FINDOPT2_CSRTOP)	//from top                     //~v59ZI~
        {                                                          //~v59ZI~
        	if (!csrline)		//back 0 line                      //~v59ZI~
            	plhtop=Pplh;                                       //~v59ZI~
            else                                                   //~v59ZI~
            {                                                      //~v59ZI~
              if (vhexmode)                                        //~v698I~
              {                                                    //~v698I~
              	plhtop=fcmdfindscrollvhexline(Pplh,scrheight,-csrline);//~v698I~
              }                                                    //~v698I~
              else                                                 //~v698I~
              {                                                    //~v698I~
        		if (scrheight<=csrline) //back line not displayable//~v59ZI~
                	csrline=scrheight-1;                           //~v59ZI~
				plhtop=getdisplayline(Pplh,-csrline,0);//get prev line,no output actual step count//~v59ZR~
              }                                                    //~v698I~
            }                                                      //~v59ZI~
		}//top                                                     //~v59ZI~
        else	//bottom                                           //~v59ZI~
        {                                                          //~v59ZI~
          if (vhexmode)                                            //~v698I~
          {                                                        //~v698I~
            plhtop=fcmdfindscrollvhexline(Pplh,scrheight,csrline); //~v698I~
          }                                                        //~v698I~
          else                                                     //~v698I~
          {                                                        //~v698I~
            if (scrheight<=csrline+1) //bottom is overflow screen height//~v59ZI~
                plhtop=Pplh;                                       //~v59ZR~
            else                                                   //~v59ZR~
            {                                                      //~v59ZI~
                csrline=scrheight-csrline-1;                       //~v59ZR~
            	plhtop=getdisplayline(Pplh,-csrline,0);//get prev line,no output actual step count//~v59ZR~
            }                                                      //~v59ZI~
          }                                                        //~v698I~
		}//bottom                                                  //~v59ZI~
	}                                                              //~v59ZI~
    if (plhtop)	//getdisplayline success                           //~v59ZI~
    {                                                              //~v59ZI~
        if (plhtop!=pfc->UFCcurtop)                                //~v59ZI~
        {                                                          //~v59ZI~
			pfc->UFCcurtop=plhtop;                                 //~v59ZR~
			UCBITON(Ppcw->UCWflag,UCWFDRAW);                       //~v59ZR~
        }                                                          //~v59ZI~
    }                                                              //~v59ZI~
    return 0;                                                      //~v59ZI~
}//fcmdfindscroll                                                  //~v698R~
//*************************************************************************//~v698I~
//*line advance/back by csr position option of find cmd(/c[T|B]n)  //~v698I~
//*************************************************************************//~v698I~
PULINEH fcmdfindscrollvhexline(PULINEH Pplh,int Pscrheight,int Pstep)//~v698I~
{                                                                  //~v698I~
	PULINEH plh,plhold;                                            //~v698I~
    int step=0,ii;                                                 //~v698R~
//****************************                                     //~v698I~
	plhold=Pplh;                                                   //~v698I~
    if (Pstep>0)	//forward down                                 //~v698I~
    {                                                              //~v698I~
    	for (plh=Pplh,ii=Pstep;plh;ii--)                           //~v698R~
        {                                                          //~v698I~
        	if (plh->ULHtype==ULHTDATA)                            //~v698I~
            	step+=3;                                           //~v698I~
            else                                                   //~v698I~
            	step++;                                            //~v698I~
            if (step>Pscrheight)                                   //~v698I~
            	break;                                             //~v698I~
        	plhold=plh;                                            //~v698M~
			plh=getdisplayline(plh,1,0);//get prev line,no output actual step count//~v698R~
            if (!ii)                                               //~v698M~
            	break;                                             //~v698M~
        }                                                          //~v698I~
        if (step<Pscrheight)	//upper part line space remaining  //~v698I~
        	plhold=fcmdfindscrollvhexline(plhold,Pscrheight,-Pscrheight); //back by screenheight//~v698R~
        else                                                       //~v698I~
            plhold=Pplh;    //top is found line                    //~v698I~
    }                                                              //~v698I~
    else	//backword up                                          //~v698I~
    {                                                              //~v698I~
    	for (plh=Pplh,ii=-Pstep;plh;ii--)                          //~v698R~
        {                                                          //~v698I~
        	if (plh->ULHtype==ULHTDATA)                            //~v698I~
            	step+=3;                                           //~v698I~
            else                                                   //~v698I~
            	step++;                                            //~v698I~
            if (step>Pscrheight)                                   //~v698I~
            	break;                                             //~v698I~
        	plhold=plh;                                            //~v698M~
            if (!ii)                                               //~v698M~
            	break;                                             //~v698M~
			plh=getdisplayline(plh,-1,0);//get prev line,no output actual step count//~v698R~
        }                                                          //~v698I~
    }                                                              //~v698I~
	return plhold;                                                 //~v698R~
}//fcmdfindscrollvhexline                                          //~v698I~
//*************************************************************************//~v698I~
//*count displayed plh of vhexmode;if plh!=0 break if plh found    //~v698I~
//*rc  1:plh not found , -1:last line is not fully displayed 3 line//~v698I~
//*************************************************************************//~v698I~
int fcmdcountvhexline(PUCLIENTWE Ppcw,PUFILEC Ppfc,PULINEH Pplh,int *Ppline)//~v698I~
{                                                                  //~v698I~
	PULINEH plh;                                                   //~v698I~
    int row=0,step=0,scrheight;                                    //~v698R~
//****************************                                     //~v698I~
    scrheight=Ppcw->UCWheight-Ppcw->UCWfilehdrlineno;              //~v698I~
    for (plh=Ppfc->UFCcurtop;plh;)                                 //~v698R~
	{                                                              //~v698I~
		if (plh==Pplh)	//on current screen                        //~v698I~
        {                                                          //~v698I~
        	*Ppline=row;                                           //~v698I~
			return 1;                                              //~v698I~
        }                                                          //~v698I~
        if (plh->ULHtype==ULHTDATA)                                //~v698I~
            step+=3;                                               //~v698I~
        else                                                       //~v698I~
            step++;                                                //~v698I~
        if (step>=scrheight)                                       //~v698R~
        	break;                                                 //~v698I~
        row++;                                                     //~v698I~
		plh=getdisplayline(plh,1,0);//get next                     //~v698I~
	}                                                              //~v698I~
    *Ppline=row;                                                   //~v698I~
    if (step<scrheight)                                            //~v698R~
    	return -1;                                                 //~v698I~
	return 0;                                                      //~v698I~
}//fcmdcountvhexline                                               //~v698I~
//**************************************************               //~v09II~
//!fcmdtabsrch                                                     //~v0ewR~
//*for text file esccharlen==1 when 0x09 search                    //~va28I~
//*for bin  file esccharlen>=1 even when 0x09 search               //~va28I~
//*utf8 file is text only,and tab expanded(search on dbcs tbl)     //~va28I~
//*parm1:plh                                                       //~v09II~
//*parm2:direction                                                 //~v09II~
//*parm3:search start pos                                          //~v0eBR~
//*parm4:found position                                            //~v0eBI~
//*parm5:range1                                                    //~v0eBI~
//*parm6:range2                                                    //~v0eBI~
//*parm7:search string containing tab                              //~v11sI~
//*parm8:search string len                                         //~v11sI~
//*ret  :rc 0 no err(*Pppc=0 if not found),else err                //~v09IR~
//**************************************************               //~v09II~
int fcmdtabsrch(PULINEH Pplh,int Pdirection,int Poffset,unsigned char **Pppc,//~v0eBR~
                int Prange1,int Prange2,UCHAR *Pstring,int Plen)   //~v11sR~
{                                                                  //~v09II~
    char *pc;                                                      //~v09IR~
    char *pcd;                                                     //~v0eBI~
    int rc,len,ii;                                                 //~v11sR~
    UCHAR  ch,ch2,*pc1,*pc2,*pstop,*pdata,*pdbcs;                  //~v11sR~
//*********************************                                //~v09II~
    *Pppc=0;                        //not found                    //~v11sI~
    if (!Pplh->ULHdbcs)			//not yet dbcs chked               //~v09IR~
    {                                                              //~v09II~
//*always ULHdbcs!=0 for utf8                                      //~va28I~
//*never called for ebcfile because Stabsrchsw is off for ebcfile  //~va3xI~
    	if (!memchr(Pplh->ULHdata,TABCHAR,(UINT)(len=Pplh->ULHlen)))//search data//~v09IR~
//      {                                                          //~v11sR~
//      	*Pppc=0;						//not found            //~v11sR~
        	return 0;                                              //~v09II~
//  	}                                                          //~v11sR~
        if (rc=filechktabdbcs(Pplh),rc)		//create tab dbcs tbl  //~v09IR~
        	return rc;                      //malloc err           //~v09IR~
        if (Poffset==len					//len before expand    //~v09II~
        &&  Pdirection==SUBCMD_PREV)		//last postion changed //~v09II~
        	Poffset=Pplh->ULHlen;			//new last pos         //~v09II~
	}                                                              //~v09II~
    ch=*Pstring;                                                   //~v11sI~
    pdata=Pplh->ULHdata;                                           //~v11sI~
    pdbcs=Pplh->ULHdbcs;                                           //~v11sI~
    if (ch==TABCHAR)                                               //~v11sI~
        pcd=pdbcs;              //search 1st char on dbcs tbl      //~v11sI~
    else                                                           //~v11sI~
        pcd=pdata;              //search 1st char on data tbl      //~v11sI~
                                                                   //~v11sI~
	if (Pdirection==SUBCMD_PREV)                                   //~v09II~
    {                                                              //~v0eBI~
//  	pc=umemrchr(Pplh->ULHdbcs,TABCHAR,(UINT)Poffset);	       //~v0eBR~
//      if (Poffset>Prange2)                                       //~v11sR~
//          Poffset=Prange2;                                       //~v11sR~
        if (Poffset>Prange2+Plen-1)                                //~v11sI~
            Poffset=Prange2+Plen-1;                                //~v11sI~
        Poffset-=Prange1;                                          //~v0eBI~
        pcd+=Prange1;                                              //~v0eBI~
        if (Poffset<=0)                                            //~v0eBI~
        	pc=0;                                                  //~v0eBI~
        else                                                       //~v0eBI~
//  		pc=umemrchr(pcd,TABCHAR,(UINT)Poffset);                //~v11sR~
//*srch for TAB is on pcd for utf8 file                            //~va28I~
    		pc=umemrchr(pcd,ch,(UINT)Poffset);                     //~v11sI~
        pstop=pcd;                                                 //~v11sI~
    }                                                              //~v0eBI~
    else 	//forward search                                       //~v09II~
    {                                                              //~v0eBI~
//  	pc=memchr(Pplh->ULHdbcs+Poffset,TABCHAR,(UINT)Pplh->ULHlen-Poffset);//~v0eBR~
        if (Poffset<Prange1)                                       //~v0eBI~
            Poffset=Prange1;                                       //~v0eBI~
		len=Pplh->ULHlen;                                          //~v0eBI~
//      if (len>Prange2)                                           //~v11sR~
//      	len=Prange2;                                           //~v11sR~
        if (len>Prange2+Plen-1)                                    //~v11sI~
        	len=Prange2+Plen-1;                                    //~v11sI~
		pcd+=Poffset;                                              //~v0eBI~
		len-=Poffset;                                              //~v0eBI~
        if (len<=0)                                                //~v0eBI~
        	pc=0;                                                  //~v0eBI~
        else                                                       //~v0eBI~
//  		pc=memchr(pcd,TABCHAR,(UINT)len);                      //~v11sR~
//*srch for TAB is on pcd for utf8 file                            //~va28R~
    		pc=memchr(pcd,ch,(UINT)len);                           //~v11sI~
        pstop=pcd+len;                                             //~v11sI~
    }                                                              //~v0eBI~
//  if (pc)                                                        //~v11sI~
//      *Pppc=Pplh->ULHdata+(ULONG)pc-(ULONG)(Pplh->ULHdbcs);      //~v11sI~
//  else                                                           //~v11sI~
//      *Pppc=0;                                                   //~v11sI~
    if (!pc)                                                       //~v11sI~
        return 0;                                                  //~v11sI~
    if (ch==TABCHAR)                                               //~v11sI~
    {                                                              //~v11sI~
//      pstop=pdata+(ULONG)pstop-(ULONG)pdbcs;                     //~v11sI~//~vafkR~
        pstop=pdata+(ULPTR)pstop-(ULPTR)pdbcs;                     //~vafkI~
//      pdata+=(ULONG)pc-(ULONG)pdbcs; //add offset on dbcs        //~v11sR~//~vafkR~
        pdata+=(ULPTR)pc-(ULPTR)pdbcs; //add offset on dbcs        //~vafkI~
        pdbcs=pc;                                                  //~v11sI~
    }                                                              //~v11sI~
    else        //serch on data                                    //~v11sI~
    {                                                              //~v11sI~
//      pdbcs+=(int)((ULONG)pc-(ULONG)pdata); //add offset on data //~v11sR~//~vafkR~
        pdbcs+=(int)((ULPTR)pc-(ULPTR)pdata); //add offset on data //~vafkI~
        pdata=pc;                                                  //~v11sM~
    }                                                              //~v11sI~
    for (;;)                                                       //~v11sI~
    {                                                              //~v11sI~
	    *Pppc=pdata;	//nay matched                              //~v11sI~
        for (pc1=pdata,pc2=pdbcs,pc=Pstring,ii=Plen;ii;ii--,pc1++,pc2++,pc++)//~v11sR~
        {                                                          //~v11sI~
            ch2=*pc;                                               //~v11sI~
            if (ch2==TABCHAR)                                      //~v11sI~
            {                                                      //~v11sI~
                if (TABCHAR!=*pc2)                                 //~v11sR~
                    break;                                         //~v11sI~
            }                                                      //~v11sI~
            else                                                   //~v11sI~
                if (ch2!=*pc1)                                     //~v11sI~
                    break;                                         //~v11sI~
                else                                               //~v11sI~
    	        	if (ch2==' ')                                  //~v11sI~
                    	if (*pc2==TABCHAR || *pc2==TABPADCHAR)     //~v11sI~
                        	break;                                 //~v11sI~
        }                                                          //~v11sI~
        if (!ii)    //all match                                    //~v11sI~
            return 0;     //string matched                         //~v11sI~
    	*Pppc=0;	//nay matched                                  //~v11sI~
//search 1st char next                                             //~v11sI~
		if (Pdirection==SUBCMD_PREV)                               //~v11sI~
        {                                                          //~v11sI~
	        while (pdata--,pdbcs--,pdata>=pstop)                   //~v11sI~
        	{                                                      //~v11sI~
            	if (ch==TABCHAR)                                   //~v11sI~
            	{                                                  //~v11sI~
                	if (TABCHAR==*pdbcs)                           //~v11sR~
                    	break;                                     //~v11sI~
            	}                                                  //~v11sI~
            	else                                               //~v11sI~
                	if (ch==*pdata)                                //~v11sR~
                    	break;                                     //~v11sI~
        	}                                                      //~v11sI~
            if (pdata<pstop)                                       //~v11sI~
            	break;                                             //~v11sI~
		}                                                          //~v11sI~
		else                                                       //~v11sI~
        {                                                          //~v11sI~
	        while (pdata++,pdbcs++,pdata<pstop)                    //~v11sI~
        	{                                                      //~v11sI~
            	if (ch==TABCHAR)                                   //~v11sI~
            	{                                                  //~v11sI~
                	if (TABCHAR==*pdbcs)                           //~v11sR~
                    	break;                                     //~v11sI~
            	}                                                  //~v11sI~
            	else                                               //~v11sI~
                	if (ch==*pdata)                                //~v11sR~
                    	break;                                     //~v11sI~
        	}                                                      //~v11sI~
            if (pdata>=pstop)                                      //~v11sI~
            	break;                                             //~v11sI~
		}                                                          //~v11sI~
    }//next word search loop                                       //~v11sI~
    return 0;                                                      //~v09II~
}//fcmdtabsrch                                                     //~v09II~
//**************************************************               //~va1GI~
//!fcmdutf8echsrch                                                 //~va1GI~
// search utf8 trans err char by UDBCSCHK_F2L err on dbcstbl       //~va1GI~
//*ret  :rc 0 no err(*Pppc=0 if not found),else err                //~va1GI~
//**************************************************               //~va1GI~
int fcmdutf8echsrch(PULINEH Pplh,int Pdirection,int Poffset,unsigned char **Pppc,//~va1GI~
                int Prange1,int Prange2)                           //~va1GI~
{                                                                  //~va1GI~
    char *pc;                                                      //~va1GI~
    char *pcd;                                                     //~va1GI~
    int len,offs;                                                  //~va1GR~
    UCHAR  ch,*pdata,*pdbcs;                                       //~va1GR~
//*********************************                                //~va1GI~
    *Pppc=0;                        //not found                    //~va1GI~
    offs=Poffset;                                                  //~va1GI~
    if (!Pplh->ULHdbcs)			//not yet dbcs chked               //~va1GI~
    	return 0;       //not found,cpu8 file is set dbcs at loading//~va1GI~
    ch=UDBCSCHK_F2LERR;                                            //~va1GI~
    pdata=Pplh->ULHdata;                                           //~va1GI~
    pdbcs=Pplh->ULHdbcs;                                           //~va1GI~
    pcd=pdbcs;              //search 1st char on dbcs tbl          //~va1GI~
	if (Pdirection==SUBCMD_PREV)                                   //~va1GI~
    {                                                              //~va1GI~
        if (offs>Prange2)                                          //~va1GI~
            offs=Prange2;                                          //~va1GI~
        offs-=Prange1;                                             //~va1GI~
        pcd+=Prange1;                                              //~va1GI~
        if (offs<=0)                                               //~va1GI~
        	pc=0;                                                  //~va1GI~
        else                                                       //~va1GI~
    		pc=umemrchr(pcd,ch,(UINT)offs);                        //~va1GI~
    }                                                              //~va1GI~
    else 	//forward search                                       //~va1GI~
    {                                                              //~va1GI~
        if (offs<Prange1)                                          //~va1GI~
            offs=Prange1;                                          //~va1GI~
		len=Pplh->ULHlen;                                          //~va1GI~
        if (len>Prange2)                                           //~va1GI~
        	len=Prange2;                                           //~va1GI~
		pcd+=offs;                                                 //~va1GI~
		len-=offs;                                                 //~va1GI~
        if (len<=0)                                                //~va1GI~
        	pc=0;                                                  //~va1GI~
        else                                                       //~va1GI~
//*srch on pcd                                                     //~va28I~
    		pc=memchr(pcd,ch,(UINT)len);                           //~va1GI~
    }                                                              //~va1GI~
    if (!pc)                                                       //~va1GI~
        return 0;                                                  //~va1GI~
//  *Pppc=pdata+(ULONG)pc-(ULONG)pdbcs; //add offset on dbcs       //~va1GI~//~vafkR~
    *Pppc=pdata+(ULPTR)pc-(ULPTR)pdbcs; //add offset on dbcs       //~vafkI~
    return 0;                                                      //~va1GI~
}//fcmdutf8echsrch                                                 //~va1GI~
//**************************************************               //~v09LI~
//!fcmdchkescseq                                                   //~v0ewR~
//*chk parm specifing esc seq except tab                           //~v0ewI~
//*parm1:parm string                                               //~v09LI~
//*parm2:output bin data                                           //~v0apI~
//*parm3:serach(0) or rep(1)                                       //~v0apI~
//*ret  :ecc char len(0:no esc),-1 if err                          //~v09NR~
//**************************************************               //~v09LI~
int fcmdchkescseq(char *Pin,char *Pout,int Popt)                   //~v0apR~
{                                                                  //~v09LI~
static char Sescseqid[]="XABTNVFR";                                //~v09LR~
static char Sescseqtbl[]  ="x\a\b\t\n\v\f\r";                      //~v09LR~
    char *pc;                                                      //~v09NR~
//  int len;                                                       //~v0apR~
//  USHORT hexv;                                                   //~v0apR~
    int ii;                                                        //~v0apI~
    int rc;                                                        //~v09NI~
//*********************************                                //~v09LI~
 	if (!*Pin)		//null                                         //~v433I~
		return 0;                                                  //~v433I~
 	if (!(pc=strchr(Sescseqid,toupper(*Pin))))                     //~v09LR~
		return 0;                                                  //~v09LI~
//  pc=Sescseqtbl+((ULONG)pc-(ULONG)(Sescseqid));                  //~v09LR~//~vafkR~
    pc=Sescseqtbl+((ULPTR)pc-(ULPTR)(Sescseqid));                  //~vafkI~
    if (*pc=='x')	//x or X                                       //~v09LR~
    {                                                              //~v09LI~
//  	if ((len=(int)strlen(Pin+1))>4)                            //~v0apR~
//      {                                                          //~v0apR~
//  		uerrmsg("Hex notaion allowed max 2 byte(%s)",          //~v0apR~
//  				"ヘキサ指定は最大2バイト(%s)",                 //~v0apR~
//  				Pin);                                          //~v0apR~
//      	return -1;                                             //~v0apR~
//  	}                                                          //~v0apR~
//  	if (ux2s(Pin+1,&hexv))	//err                              //~v0apR~
    	if ((rc=ugethex(Pin+1,Pout,MAXCOLUMN))<0)	//rc is hex len//~v0apI~
        {                                                          //~v09NI~
//  		uerrmsg("Hex notaion error(%s)",                       //~v09NI~//~vbc3R~
    		uerrmsg("Hex notation error(%s)",                      //~vbc3I~
					"ヘキサ指定エラー(%s)",                        //~v09NI~
					Pin);                                          //~v09NI~
        	return -1;                                             //~v09NI~
		}                                                          //~v09NI~
//      if (len>2)	//2 byte                                       //~v0apR~
//  	{                                                          //~v0apR~
//      	if ((hexv>>8)<' ' || (hexv&255)<' ')                   //~v0apR~
//          {                                                      //~v0apR~
//  			uerrmsg("Use Ctl char(<0x20) as single char(%s)",  //~v0apR~
//  					"制御文字(<0x20)は1バイト指定のみ(%s)",    //~v0apR~
//  					Pin);                                      //~v0apR~
//          	return -1;                                         //~v0apR~
//  		}                                                      //~v0apR~
//          *Pout=(char)(hexv>>8);                                 //~v0apR~
//          *(Pout+1)=(char)hexv;                                  //~v0apR~
//          rc=2;                                                  //~v0apR~
//  	}                                                          //~v0apR~
//  	else                                                       //~v0apR~
//      {                                                          //~v0apR~
//  		*Pout=(char)hexv;                                      //~v0apR~
//  		rc=1;                                                  //~v0apR~
//      }                                                          //~v0apR~
                                                                   //~v11sI~
//        if (!Popt)          //serach string                      //~v11sR~
//            for (ii=1,pc=Pout;ii<rc;ii++,pc++)                   //~v11sR~
//                if (*pc==TABCHAR)                                //~v11sR~
//                {                                                //~v11sR~
//                    uerrmsg("Tab(0x09) search avail only as single byte",//~v11sR~
//                            "タブ(0x09)探索は1バイト指定のみ");  //~v11sR~
//                    return -1;                                   //~v11sR~
//                }                                                //~v11sR~
                                                                   //~v11sI~
    }                                                              //~v09LI~
    else                                                           //~v09LI~
    {                                                              //~v09LI~
    	if (*(Pin+1))                                              //~v09LI~
        	return 0;                                              //~v09LI~
		*Pout=*pc;                                                 //~v09NI~
        rc=1;                                                      //~v09NI~
	}                                                              //~v09LI~
    if (Popt)	//rep string                                       //~v0apI~
        for (ii=0,pc=Pout;ii<rc;ii++,pc++)                         //~v0apI~
        	if (Gvalidchartbl[(int)*pc])                           //~v40zR~
            {                                                      //~v0apI~
                funcinhibitkey(*pc);                               //~v0apI~
                return -1;                                         //~v0apI~
            }                                                      //~v0apI~
    return rc;                                                     //~v09NR~
}//fcmdchkescseq                                                   //~v09LI~
////****************************************************************//~v0hxR~
////!fcmdsetabrange                                                //~v0hxR~
////* set line range for 'ALL' filed/change                        //~v0hxR~
////* from 'A' line to 'B' line,search excluded line on 'A'/'B' line.//~v0hxR~
////*parm1 :pcw                                                    //~v0hxR~
////*parm2 :pfh                                                    //~v0hxR~
////*parm3 :first sw                                               //~v0hxR~
////*rc   :0:no range,1:'A' cmd,  2:'B' cmd                        //~v0hxR~
////****************************************************************//~v0hxR~
//int fcmdsetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pfirstsw)    //~v0hxR~
//{                                                                //~v0hxR~
//    int rc;                                                      //~v0hxR~
//    PULINEH plh;                                                 //~v0hxR~
////***************                                                //~v0hxR~
//    if (Pfirstsw)   //first time                                 //~v0hxR~
//    {                                                            //~v0hxR~
//        if (Ssubcmdid!=SUBCMD_ALL                                //~v0hxR~
//        ||  Ppcw->UCWtype==UCWTDIR)   //not on dir list          //~v0hxR~
//            return 0;                                            //~v0hxR~
//        Srangeplcindex=0;                                        //~v0hxR~
//    }                                                            //~v0hxR~
//    rc=lcmdgetabplh(Ppfh,Srangeplcindex++,&plh);//0:no more,1:'A',2:'B'//~v0hxR~
//    switch(rc)                                                   //~v0hxR~
//    {                                                            //~v0hxR~
//    case 0: //no cmd                                             //~v0hxR~
//        rc=0;       //no range set                               //~v0hxR~
//        break;                                                   //~v0hxR~
//    case 1: //'A' cmd                                            //~v0hxR~
//        Srangeplhs=plh;                                          //~v0hxR~
//        if (lcmdgetabplh(Ppfh,Srangeplcindex++,&plh))//get next 'A'/'B' lcmd plh//~v0hxR~
//            Srangeplhe=getdisplayline(plh,1,0);//next display line//~v0hxR~
//        rc=1;       //range set                                  //~v0hxR~
//        break;                                                   //~v0hxR~
//    case 2: //'B' cmd                                            //~v0hxR~
//        Srangeplhe=getdisplayline(plh,1,0);//next display line   //~v0hxR~
//        rc=1;       //range set                                  //~v0hxR~
//        break;                                                   //~v0hxR~
//    default:        //seq err, or mixed                          //~v0hxR~
//        uerrmsg("Search line range specification err",           //~v0hxR~
//                "探索行範囲指定の誤り");                         //~v0hxR~
//    }                                                            //~v0hxR~
//    return rc;                                                   //~v0hxR~
//}//fcmdsetabrange                                                //~v0hxR~
//**************************************************************** //~v0hxI~
//!fcmdsetabrange                                                  //~v0hxI~
//* get line range from label                                      //~v0hxI~
//*parm1 :pcw                                                      //~v0hxI~
//*parm2 :pfh                                                      //~v0hxI~
//*parm3 :dest  0:forward,1:backward                               //~v0hxI~
//*parm4 :current plh	in/out                                     //~v0hxR~
//*parm5 :end plh       out                                        //~v0hxR~
//*rc   :0:ok,1:curr pos is already out 2:lab not found 4:label err//~v0hCR~
//**************************************************************** //~v0hxI~
int fcmdsetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psubcmdid,     //~v0hxR~
					PULINEH *Ppplhs,PULINEH *Ppplhe)               //~v0hxI~
{                                                                  //~v0hxI~
    int swapsw,rc;                                                 //~v0hxR~
    PULINEH plht[MAXLABEL],plh1,plh2,plhc;                         //~v43vR~
    int sortseq[MAXLABEL];                                         //~v0hxI~
    int seq1,seq2,ii;                                              //~v0hxR~
    UCHAR editwk[ULHLINENOSZ+32];                                  //~v0hxI~
//***************                                                  //~v0hxI~
	*Ppplhe=0;			//init                                     //~v0hxR~
    if (!*Slab[0])			//no label                             //~v0hxI~
    {                                                              //~v0hxI~
        Slabold[0][0]=0;                                           //~v0hxR~
    	return 0;                                                  //~v0hxI~
    }                                                              //~v0hxI~
//  if (lcmdgetabplh(Ppfh,MAXLABEL,Slab,plht,sortseq))             //~v47cR~
    if (rc=lcmdgetabplh(Ppfh,MAXLABEL,Slab,plht,sortseq),rc)       //~v47cI~
    {                                                              //~v0hxI~
    	for (ii=0;ii<MAXLABEL;ii++)                                //~v0hxI~
        	if (!sortseq[ii])	//0 if label not found             //~v0hxR~
            	break;                                             //~v0hxI~
        if (ii<MAXLABEL)                                           //~v0hxI~
            strcpy(editwk,Slab[ii]);                               //~v0hxI~
        else                                                       //~v0hxI~
            *editwk=0;                                             //~v0hxI~
      if (rc==5)                                                   //~v47cR~
        strcat(editwk," is duplicated");                           //~v47cI~
      else                                                         //~v47cI~
        strcat(editwk," not found");                               //~v0hxI~
    	fcmdlabelerr(editwk);                                      //~v0hxR~
      if (rc!=5)                                                   //~v47cR~
      {                                                            //~v54zI~
        if (memcmp(Slab,Slabold,sizeof(Slab)))                     //~v0hxI~
        	rc=4;                                                  //~v0hxR~
        else                                                       //~v0hxI~
        	rc=2;          //skip bell                             //~v0hxI~
      }                                                            //~v54zI~
        memcpy(Slabold,Slab,sizeof(Slab));//save err label         //~v0hxR~
        return rc;                                                 //~v0hxI~
    }                                                              //~v0hxI~
    Slabold[0][0]=0;                                               //~v0hxI~
//set which is start and end                                       //~v0hxI~
    plh1=plht[0];                                                  //~v0hxR~
    plh2=plht[1];                                                  //~v0hxR~
    swapsw=0;                                                      //~v0hxM~
    if (sortseq[0]<sortseq[1])                                     //~v0hxR~
    {                                                              //~v0hxI~
    	if (Psubcmdid==SUBCMD_PREV)                                //~v0hxI~
        	swapsw=1;                                              //~v0hxI~
    }                                                              //~v0hxI~
    else                          //plhs>=plhe                     //~v0hxR~
    	if (Psubcmdid!=SUBCMD_PREV)                                //~v0hxI~
        	swapsw=1;                                              //~v0hxI~
	if (swapsw)	//need swap                                        //~v0hxI~
    {                                                              //~v0hxI~
    	plh1=plht[1];	plh2=plht[0];                              //~v0hxR~
	}                                                              //~v0hxI~
//*set end line                                                    //~v0hxR~
    if (Psubcmdid==SUBCMD_PREV)                                    //~v0hxI~
    {                                                              //~v43vI~
		plh2=getdisplayline(plh2,-1,0);//prev display line         //~v0hxI~
        if (!plh2)                                                 //~v43vI~
			plh2=UGETQTOP(&Ppfh->UFHlineque);                      //~v43vI~
    }                                                              //~v43vI~
	else                                                           //~v0hxI~
    {                                                              //~v43vI~
		plh2=getdisplayline(plh2,1,0);//next display line          //~v0hxI~
        if (!plh2)                                                 //~v43vI~
			plh2=UGETQEND(&Ppfh->UFHlineque);                      //~v43vI~
    }                                                              //~v43vI~
//*chk with current pos                                            //~v0hxI~
    plhc=*Ppplhs;		//current pos                              //~v0hxM~
//  seq1=lineseqchk(plhc,plh1);                                    //~v0hxR~//~vb2ER~
    seq1=(int)lineseqchk(plhc,plh1);                               //~vb2EI~
//  seq2=lineseqchk(plhc,plh2);                                    //~v0hxR~//~vb2ER~
    seq2=(int)lineseqchk(plhc,plh2);                               //~vb2EI~
	rc=0;                                                          //~v0hxR~
    if (Psubcmdid==SUBCMD_PREV)                                    //~v0hxI~
    {                                                              //~v0hxI~
    	if (seq2<=0) 	//plhc<=plh2                               //~v0hxR~
        	rc=1;					//out of range                 //~v0hxR~
        else                                                       //~v0hxI~
	    	if (seq1>0)            //plhc>plh1                     //~v0hxR~
        		plhc=plh1;  		//start from label             //~v0hxI~
    }                                                              //~v0hxI~
    else 			//forward search                               //~v0hxI~
    {                                                              //~v0hxI~
    	if (seq2>=0)			//plhc>=plh2                       //~v0hxR~
        	rc=1;					//out of range                 //~v0hxR~
        else                                                       //~v0hxI~
	    	if (seq1<0)			//plhc<plh1                        //~v0hxR~
        		plhc=plh1;  		//start from label             //~v0hxI~
    }                                                              //~v0hxI~
	*Ppplhs=plhc;                                                  //~v0hxI~
	*Ppplhe=plh2;                                                  //~v0hxI~
    return rc;		//has label                                    //~v0hxR~
}//fcmdsetabrange                                                  //~v0hxI~
//**************************************************************** //~v11pI~
//!fcmdxall                                                        //~v11pI~
//* EXClude all                                                    //~v11pI~
//*parm1 :pcw                                                      //~v11pI~
//*parm2 :pfh                                                      //~v11pR~
//*rc    :0:ok,4:err                                               //~v11pI~
//**************************************************************** //~v11pI~
int fcmdxall(PUCLIENTWE Ppcw,PUFILEH Ppfh)                         //~v11pR~
{                                                                  //~v11pI~
    PULINEH plht,plhe;                                             //~v11pR~
    int rc;                                                        //~v11pI~
//***************                                                  //~v11pI~
	if (UGETQCTR(&Ppfh->UFHlineque)<=2)                            //~v11pI~
    	return 0;						//no line to be exclude    //~v11pR~
//  if (Ppfh->UFHcmdlinectr)                //any residual lcmd input//~v11pI~//~vb86R~
//  {                                                              //~v11pI~//~vb86R~
//      uerrmsg("Reset pending line-cmd at first",                 //~v11pI~//~vb86R~
//              "行コマンドが残っています");                       //~v11pI~//~vb86R~
//        return 4;                                                  //~v11pI~//~vb86R~
//  }                                                              //~v11pI~//~vb86R~
	plht=UGETQTOP(&Ppfh->UFHlineque);	//top label line           //~v11pI~
	plhe=UGETQEND(&Ppfh->UFHlineque);   //end label line           //~v11pI~
	strcpy(plht->ULHlinecmd,"XX");                                 //~v11pI~
	strcpy(plhe->ULHlinecmd,"XX");                                 //~v11pI~
//  UCBITON(plht->ULHflag,ULHFDRAW|ULHFLINECMD);		//req redraw//~v11pI~//~vb86R~
//  UCBITON(plhe->ULHflag,ULHFDRAW|ULHFLINECMD);		//req redraw//~v11pI~//~vb86R~
//  Ppfh->UFHcmdline[0]=plht;                                      //~v11pI~//~vb86R~
//  Ppfh->UFHcmdline[1]=plhe;                                      //~v11pI~//~vb86R~
//  Ppfh->UFHcmdlinectr=2;				//sim 2 line cmd input     //~v11pR~//~vb86R~
  	if (!UCBITCHK(plht->ULHflag,ULHFLINECMD))		//req redraw   //~vb86I~
  	{                                                              //~vb86I~
		UCBITON(plht->ULHflag,ULHFDRAW|ULHFLINECMD);		//req redraw//~vb86I~
		Ppfh->UFHcmdline[Ppfh->UFHcmdlinectr++]=plht;              //~vb86R~
  	}                                                              //~vb86I~
  	if (!UCBITCHK(plhe->ULHflag,ULHFLINECMD))		//req redraw   //~vb86R~
  	{                                                              //~vb86I~
		UCBITON(plhe->ULHflag,ULHFDRAW|ULHFLINECMD);		//req redraw//~vb86I~
		Ppfh->UFHcmdline[Ppfh->UFHcmdlinectr++]=plhe;              //~vb86R~
  	}                                                              //~vb86I~
	UCBITOFF(Ppfh->UFHflag2,UFHF2LCMDCOMP);//need command process  //~vb86I~
	UTRACEP("@@@1 %s:add after cmdlinectr=%d\n",UTT,Ppfh->UFHcmdlinectr);//~vax1R~//~vb86R~
	rc=filelinecmd(Ppcw);				//execule line cmd         //~v11pI~
    return rc;		//has label                                    //~v11pI~
}//fcmdxall                                                        //~v11pI~
//**************************************************               //~v61hI~
//!fcmdsetfoundlinelabel                                           //~v61hI~
//*process -l option(set label on found line)                      //~v61hI~
//*ret  :rc                                                        //~v61hI~
//**************************************************               //~v61hI~
int fcmdsetfoundlinelabel(PULINEH Pplh,char *Plabel)               //~v61hR~
{                                                                  //~v61hI~
	PUFILEH pfh;                                                   //~v61hI~
//***************************::	                                   //~v61hI~
	if (UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))                    //~v61hI~
    	return 4;		//found string may be already set display  //~v61hI~
	if (UCBITCHK(Pplh->ULHflag,ULHFLINECMD))                       //~v61hI~
    {                                                              //~v61hI~
	    uerrmsg("previous line cmd protect to set labet",          //~v61hI~
    			"行コマンドが設定されてあるので行ラベルを設定できません。");//~v61hR~
    	return 4;                                                  //~v61hI~
    }                                                              //~v61hI~
    pfh=UGETPFH(Pplh);                                             //~vbkyI~
	if (pfh->UFHcmdlinectr==MAXCMDLINE)//linecmd ctr               //~vbkyI~
	{                                                              //~vbkyI~
		uerrmsg("-L option:Setlabel:Line cmd max line is %d",      //~vbkyI~
						"-L option:行コマンドは最大 %d 行まで入力できます",//~vbkyI~
						MAXCMDLINE);                               //~vbkyI~
		return 4;                                                  //~vbkyI~
	}                                                              //~vbkyI~
    UCBITON(Pplh->ULHflag,ULHFLINECMD|ULHFDRAW);//line cmd input   //~v61hR~
    UCBITON(Pplh->ULHflag3,ULHF3ERRLINE);//reverse                 //~v61hI~
//  pfh=UGETPFH(Pplh);                                             //~v61hI~//~vbkyR~
    pfh->UFHcmdline[pfh->UFHcmdlinectr++]=Pplh;  //save cmd line   //~v61hI~
	UCBITOFF(pfh->UFHflag2,UFHF2LCMDCOMP);//need line command re-evaliation//~vb84I~
//  Pplh->ULHlinecmd[0]=ULCCMDLABEL;                               //~v61qR~
//  strncpy(Pplh->ULHlinecmd+1,Plabel,ULHLINENOSZ-2);              //~v61qR~
    strncpy(Pplh->ULHlinecmd,Plabel,ULHLINENOSZ-1);                //~v61qI~
	UTRACEP("@@@1 %s:add %c cmd,cmdlinectr=%d\n",UTT,*Pplh->ULHlinecmd,pfh->UFHcmdlinectr);//~vax1R~
    return 0;                                                      //~v61hI~
}//fcmdsetfoundlinelabel                                           //~v61hR~
//**************************************************               //~v0hxI~
//!fcmdlabelerr                                                    //~v0hxI~
//*label operand err msg                                           //~v0hxI~
//*parm:msg                                                        //~v0hxR~
//*ret  :4                                                         //~v0hxI~
//**************************************************               //~v0hxI~
int fcmdlabelerr(char *Pmsg)                                       //~v0hxR~
{                                                                  //~v0hxI~
//  uerrmsg("Error in line label operand(%s)",                     //~v0hCR~
    uerrmsg2("Error in line label operand(%s)",	//no override prev err msg//~v0hCI~
    		"行ラベル指定のエラー(%s)",                            //~v0hxR~
			Pmsg);                                                 //~v0hxI~
    return 4;                                                      //~v0hxI~
}//fcmdlabelerr                                                    //~v0hxI~
//**************************************************               //~v11kI~
//!fcmdfindhelp                                                    //~v11kI~
//*helpmsg for find/change/exclude                                 //~v11kI~
//*parm:msg                                                        //~v11kI~
//*ret  :4                                                         //~v11kI~
//**************************************************               //~v11kI~
int fcmdfindhelp(int Pchangeopt,int Pexcludesw)                    //~v11kI~
{                                                                  //~v11kI~
#define WORDandCOLS "WORD"                                         //~va1hI~
//    UCHAR *verb,*srcword,*repword;                               //~v539R~
//#ifdef UNX                                                       //~v539R~
//static UCHAR *Saround="[-a[-]n][-b[-]n][-c]";                    //~v59ZR~
static UCHAR *Saround="[-a[-]n][-b[-]n]";                          //~v59ZI~
//static UCHAR *Sandopt="[ & [!] word2[\\n] [-d[[{<|>}]n]]]";      //~v539R~
//static UCHAR *Sandopt="[ & [!] word2[\\n] [c3 [c4]] [-d[[{<|>}]n]]]";//~v54RR~
//static UCHAR *Sandopt="[& [!] word2[\\n][{c3 [c4]}|max][-d[[{<|>}]n]]]";//~v551R~
//static UCHAR *Sandopt="[& [!] word2-and-cols][-d[[{<|>}]n]]]";   //~v59ZR~
//static UCHAR *Sandopt="[& [!] word2-and-cols] [-d[[{<|>}]n]]]";  //~v603R~
//static UCHAR *Sandopt="[& [!] WORDandCOLS_2 [-d[[{<|>}]n]]]";      //~v603R~//~va1hR~
static UCHAR *Sandopt="[& [!] " WORDandCOLS "2 [-d[[{<|>}]n]]]";   //~va1hI~//~vax1R~
//static UCHAR *Swords="   ...Hit Esc Key\n WORDandCOLS: {word[\\n]|*|*u|*e|*L|*=[n]|*\\n|\\x..}[{c1 [c2]}|eol|maxeol]";//~v62aR~
//static UCHAR *Swords=" ...Hit Esc Key\n WORDandCOLS: {word[\\n]|*|*u|*e|*L|*=[n]|*\\n|\\x..}[{c1 [c2]}|eol|maxeol]";//~v62fR~
//static UCHAR *Swords=" ...Hit Esc Key\n WORDandCOLS: {word[\\n]|*|*u|*e|*L|*=[M][n]|*\\n|\\x..}[{c1 [c2]}|eol|maxeol]";//~v78eR~
//static UCHAR *Swords=" ...Hit Esc Key\n WORDandCOLS: {word[\\n]|*|*u|*e|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol]";//~v78eR~//~va0cR~
//static UCHAR *Swords=" ...Hit Esc Key\n WORDandCOLS: {word[\\n] [U[B|L]]|*|*u|*e|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol]";//~va0cI~//~va0yR~
//static UCHAR *Swords=" ...Hit Esc Key\n WORDandCOLS: {word[\\n] [U[B|L|8]]|*|*u|*e|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol]";//~va0yI~//~va1hR~
//static UCHAR *Swords=" ...Hit Esc Key\n " WORDandCOLS ": {word[\\n] [U[B|L|8]]|*|*u|*e|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol]";//~va28R~
//static UCHAR *Swords=" ...Hit Esc Key\n " WORDandCOLS ": {word[\\n] [U[B|L|8]]|*|*u|*e|*ec|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol]";//~va28I~//~vax1R~
static UCHAR *Swords=" ...Hit Esc Key\n " WORDandCOLS ": {word[\\n] [U[B|L|4|8]]|*|*u|*e|*ec|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol]";//~vax1I~
//static UCHAR *Swordsfind=" ...Hit Esc Key\n " WORDandCOLS ": {word[\\n] [U[B|L|4|8]]|*|*u|*e|*ec|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol" ATTRID "]";//~vbc3I~//~vbkyR~
static UCHAR *Swordsfind=" ...Hit Esc Key\n " WORDandCOLS ": {word[\\n] [U[B|L|4|8]]|*|*u|*e|*ec|*L|*=[M][n]|*\\n|\\x..|P'pics'|regex -g}[{c1 [c2]}|eol|maxeol|" ATTRID "]";//~vbkyI~
//#else                                                            //~v539R~
//static UCHAR *Saround="[/a[-]n] [/b[-]n] [/c]";                  //~v539R~
////static UCHAR *Sandopt="[ & [!] word2[\\n] [/d[[{<|>}]n]]]";    //~v539R~
//static UCHAR *Sandopt="[ & [!] word2[\\n] [c3 [c4]] [/d[[{<|>}]n]]]";//~v539R~
//#endif                                                           //~v539R~
//    UCHAR *around,*andopt;                                       //~v539R~
//    UCHAR *allkx="|allkx";                                       //~v539R~
    char *pssopt="[-{" FCMDOPT_PS_SPLIT "|" FCMDOPT_PS_FILE "}"\
			 "[" FCMDOPT_PS_EXECUTE "|" FCMDOPT_PS_RETRIEVE "|" FCMDOPT_PS_DISPLAY "]]";//~vbCBI~
//****************                                                 //~v11kI~
    if (Pchangeopt)                                                //~v11kM~
    {                                                              //~v11kI~
//        verb="C[NX]";                                            //~v539R~
////      srcword="{word[\\n]|*|\\x..}";                           //~v539R~
//        srcword="{word[\\n]|*|*=[n]|\\x..}";                     //~v539R~
////      repword="repword";                                       //~v539R~
//        repword="repword [c1 [c2]]";                             //~v539R~
//        around="";                                               //~v539R~
//        andopt="";                                               //~v539R~
//  	uerrmsg("C[NX] {word[\\n]|*|*=[n]|\\x..} word2 [c1 [c2]] [all|allkx|+|-] [.l1 .l2]",0);//~v54RR~
//    	uerrmsg("C[NX] {word[\\n]|*|*=[n]|\\x..} word2 [{c1 [c2]|max}] [all|allkx|+|-] [.l1 .l2]",0);//~v551R~
//    	uerrmsg("C[NX] {word[\\n]|*|*=[n]|\\x..} word2 [{c1 [c2]|eol|maxeol}] [all|allkx|+|-] [.l1 .l2]",0);//~v62aR~
//    	uerrmsg("C[NX] {word[\\n]|*|*=[n]|\\x..} word2 [{c1 [c2]|eol|maxeol}] [-m[n]] [all|allkx|+|-] [.l1 .l2]",0);//~v72PR~
//    	uerrmsg("{C|CNX|IC|ICN} {word[\\n]|*|*=[n]|\\x..} word2 [{c1 [c2]|eol|maxeol}] [-m[n]] [all|allkx|+|-] [.l1 .l2]",0);//~v74FR~
//      uerrmsg("{C|CNX|IC|ICN} {word[\\n]|*|*=[n]|\\x..} word2 [{c1 [c2]|eol|maxeol}] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2]",0);//~v78dR~
//     	uerrmsg("{C|CNX|IC|ICN} {word[\\n]|*|*=[n]|\\x..} word2 [-g] [{c1 [c2]|eol|maxeol}] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2]",0);//~v78eR~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
       	uerrmsg("{C|CNX|IC|ICN} {word[\\n]|*|*=[n]|\\x..|P'pics'|regex -g} word2 [U4] [{c1 [c2]|eol|maxeol}] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2]",0);//~vbCBR~
#else                                                              //~va3xI~
       	uerrmsg("{C|CNX|IC|ICN} {word[\\n]|*|*=[n]|\\x..|P'pics'|regex -g} word2 [{c1 [c2]|eol|maxeol}] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2]",0);//~vbCBR~
#endif                                                             //~va1CI~//~va3xI~
	}                                                              //~v11kI~
    else                                                           //~v11kM~
    {                                                              //~v11kI~
//      srcword="{word|*|*u|*e|\\x..}";                            //~v40zR~
//      repword="";                                                //~v532R~
//      repword="[c3 [c4]]";                                       //~v538R~
//        repword="[c1 [c2]]";                                     //~v539R~
//        around=Saround;                                          //~v539R~
//        andopt=Sandopt;                                          //~v539R~
        if (Pexcludesw)                                            //~v11kR~
        {                                                          //~v40zI~
//            srcword="[!] {word[\\n]|*|*u|*e|*L|*=[n]|\\x..}";    //~v539R~
//            verb="[I]X";                                         //~v539R~
//            allkx="";                                            //~v539R~
//  		uerrmsg("[I]X [!] {word[\\n]|*|*u|*e|*L|*=[n]|\\x..} %s [all|allkx|+|-] [.l1 .l2] %s",0,//~v54zR~
//  		uerrmsg("[I]X [!] {word[\\n]|*|*u|*e|*L|*=[n]|*\\n|\\x..}[{c1 [c2]}|eol|maxeol] %s %s [all|+|-] [.l1 .l2]",0,//~v603R~
//  				Sandopt,Saround);                              //~v603R~
//  		uerrmsg("[I]X [!] WORDandCOLS %s %s [all|+|-] [.l1 .l2]%s",0,//~v62aR~
//  		uerrmsg("[I]X [!] WORDandCOLS %s %s [-m[n]] [all|+|-] [.l1 .l2]%s",0,//~v78eI~//~va1hR~
//  		uerrmsg("[I]X [!] " WORDandCOLS " %s %s [-m[n]] [all|+|-] [.l1 .l2]%s",0,//~vbCBR~
//  				Sandopt,Saround,Swords);                       //~vbCBR~
    		uerrmsg("[I]X [!] " WORDandCOLS " %s %s [-m[n]] [all|+|-] [.l1 .l2]%s%s",0,//~vbCBI~
    				Sandopt,Saround,pssopt,Swords);                //~vbCBI~
        }                                                          //~v40zI~
        else                                                       //~v11kR~
        {                                                          //~v40zI~
////          srcword="[!] {word[\\n]|*|*u|*e|*L|\\x..}";          //~v539R~
//            srcword="[!] {word[\\n]|*|*u|*e|*L|*=[n]|\\x..}";    //~v539R~
//            verb="{F|I}[NX]";                                    //~v539R~
//  		uerrmsg("{F|I}[NX] [!] {word[\\n]|*|*u|*e|*L|*=[n]|\\x..} [c1 [c2]] %s %s [-j] [all|allkx|+|-] [.l1 .l2]",0,//~v54zR~
//  		uerrmsg("{F|I}[NX] [!] {word[\\n]|*|*u|*e|*L|*=[n]|*\\n|\\x..}[{c1 [c2]}|max] %s %s [-j] [all|allkx|+|-] [.l1 .l2]",0,//~v551R~
//    		uerrmsg("{F|I}[NX] [!] {word[\\n]|*|*u|*e|*L|*=[n]|*\\n|\\x..}[{c1 [c2]}|eol|maxeol] %s %s [-j] [all|allkx|+|-] [.l1 .l2]",0,//~v59ZR~
//  		uerrmsg("{F|I}[NX] [!] {word[\\n]|*|*u|*e|*L|*=[n]|*\\n|\\x..}[{c1 [c2]}|eol|maxeol] %s %s [-c[{R|L}n][{T|B}n] [-j] [all|allkx|+|-] [.l1 .l2]",0,//~v603R~
//  				Sandopt,Saround);                              //~v603I~
//  		uerrmsg("{F|I}[NX] [!] WORDandCOLS %s %s [-c[{R|L}n][{T|B}n] [-j] [all|allkx|+|-] [.l1 .l2]%s",0,//~v61hR~
//  		uerrmsg("{F|I}[NX] [!] WORDandCOLS %s %s [-c[{R|L}n][{T|B}n] [-j] -Llabel [all|allkx|+|-] [.l1 .l2]%s",0,//~v61qR~
//  		uerrmsg("{F|I}[NX] [!] WORDandCOLS %s %s [-c[{R|L}n][{T|B}n] [-j] -Llinecmd [all|allkx|+|-] [.l1 .l2]%s",0,//~v62aR~
//  		uerrmsg("{F|I}[NX] [!] WORDandCOLS %s %s [-c[{R|L}n][{T|B}n] [-j] [-Llcmd] [-m[n]] [all|allkx|+|-] [.l1 .l2]%s",0,//~v74FR~
//    		uerrmsg("{F|I}[NX] [!] WORDandCOLS %s %s [-c[{R|L}n][{T|B}n] [-j] [-Llcmd] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2]%s",0,//~v78eI~//~va1hR~
//    		uerrmsg("{F|I}[NX] [!] " WORDandCOLS " %s %s [-c[{R|L}n][{T|B}n] [-j] [-Llcmd] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2]%s",0,//~vbCBR~
//  				Sandopt,Saround,Swords);                       //~vbCBR~
      		uerrmsg("{F|I}[NX] [!] " WORDandCOLS " %s %s [-c[{R|L}n][{T|B}n] [-j] [-Llcmd] [-m[n]] [all|allkx|+|-] [-nx] [.l1 .l2] %s%s",0,//~vbCBR~
//  				Sandopt,Saround,pssopt,Swords);                //~vbCBR~//~vbc3R~
    				Sandopt,Saround,pssopt,Swordsfind);            //~vbc3I~
        }                                                          //~v40zI~
	}                                                              //~v11kI~
////  uerrmsg("%s %s %s %s [all|+|-] [.l1 .l2] [c1 c2] %s",0,      //~v539R~
////  uerrmsg("%s %s %s %s [all|+|-] [.l1 .l2] [c1 [c2]] %s",0,    //~v539R~
//    uerrmsg("%s %s %s %s [all%s|+|-] [.l1 .l2] %s",0,            //~v539R~
////          verb,srcword,repword,andopt,around);                 //~v539R~
//            verb,srcword,repword,andopt,allkx,around);           //~v539R~
	return 4;                                                      //~v11kI~
}//fcmdfindhelp                                                    //~v11kI~
//**************************************************               //~vbCBI~
char *fcmdrestorePS(int Ppstype,PUCLIENTWE Ppcw,PUFCMD Ppufc)      //~vbCBR~
{                                                                  //~vbCBI~
	char *opd,*pcmd;                                               //~vbCBR~
    PUSCMD psc;                                                    //~vbCBI~
//*************************                                        //~vbCBI~
	opd=Spsopd[Ppstype];                                           //~vbCBR~
    if (Ppufc)                                                     //~vbCBR~
    {                                                              //~vbCBI~
    	psc=&Ppufc->UFCuscmd;                                      //~vbCBI~
    	pcmd=psc->USCcmd;                                          //~vbCBR~
    }                                                              //~vbCBI~
    else                                                           //~vbCBI~
    {                                                              //~vbCBI~
    	pcmd=0;                                                    //~vbCBI~
        uerrmsg("No saved find cmd for %s, set it by cmd with %s/%s option",//~vbCBR~
                        "%s に対するコマンドが保存されていません、事前に %s/%s を使用した設定が必要です",//~vbCBR~
                        opd,FCMDOPT_PS_SPLIT,FCMDOPT_PS_FILE);     //~vbCBR~
    }                                                              //~vbCBM~
    return pcmd;                                                   //~vbCBI~
}//fcmdrestorePS                                                   //~vbCBR~
//**************************************************               //~vbCBI~
int fcmderrPSotheropd(PUCLIENTWE Ppcw,char *Popd)                  //~vbCBI~
{                                                                  //~vbCBI~
	uerrmsg("Use execute option(%s) without other options",        //~vbCBI~
            "実行オプション(%s) は単独で指定してください",         //~vbCBI~
             Popd);                                                //~vbCBI~
    return 4;                                                      //~vbCBI~
}//fcmderrPSotheropd                                               //~vbCBI~
//**************************************************               //~vbCBI~
int fcmderrPSNootheropd(PUCLIENTWE Ppcw,char *Popd)                //~vbCBI~
{                                                                  //~vbCBI~
	uerrmsg("Missing find word for (%s).",                         //~vbCBI~
            "%s のときは探索文字列を指定してください",             //~vbCBI~
             Popd);                                                //~vbCBI~
    return 4;                                                      //~vbCBI~
}//fcmderrPSotheropd                                               //~vbCBI~
//**************************************************               //~vbCBI~
int fcmderrPSnotsaved(PUCLIENTWE Ppcw,int Ppstype)                 //~vbCBI~
{                                                                  //~vbCBI~
	char *popd;                                                    //~vbCBR~
    char wkedit[8];                                                //~vbCBI~
//******************                                               //~vbCBI~
	popd=Spsopd[Ppstype];                                          //~vbCBR~
    if (Ppstype==FCMDOPT_PSTYPE_SPLIT)                             //~vbCBI~
    	sprintf(wkedit,"(%d)",Ppcw->UCWsplitid+1);                 //~vbCBR~
    else                                                           //~vbCBI~
    	wkedit[0]=0;                                               //~vbCBI~
//  uerrmsg("No saved cmd for %s",                                 //~vbCBI~//~vbrmR~
    uerrmsg("No saved cmd for %s%s",                               //~vbrmI~
        	"%s%s で保存されたコマンドはありません",               //~vbCBR~
            popd,wkedit);                                          //~vbCBR~
    return 4;                                                      //~vbCBI~
}//fcmderrPSotheropd                                               //~vbCBI~
//**************************************************               //~vbCBI~
void fcmddisplayPS(int Ppstype,PUCLIENTWE Ppcw,char *Pcmd)         //~vbCBI~
{                                                                  //~vbCBI~
	char *popd;                                                    //~vbCBR~
    char wkedit[8];                                                //~vbCBI~
//*************************                                        //~vbCBI~
	popd=Spsopd[Ppstype];                                          //~vbCBR~
    if (Ppstype==FCMDOPT_PSTYPE_SPLIT)                             //~vbCBI~
    	sprintf(wkedit,"(%d)",Ppcw->UCWsplitid+1);                 //~vbCBI~
    else                                                           //~vbCBI~
    	wkedit[0]=0;                                               //~vbCBI~
    if (!Pcmd)                                                     //~vbCBR~
		fcmderrPSnotsaved(Ppcw,Ppstype);                           //~vbCBR~
    else                                                           //~vbCBI~
    	uerrmsg("%s%s:%s",0,                                       //~vbCBR~
        	    popd,wkedit,Pcmd);                                 //~vbCBR~
}//fcmddisplayPS                                                   //~vbCBI~
//**************************************************               //~vbCBI~
void fcmddisplayPSall(PUCLIENTWE Ppcw)                             //~vbCBI~
{                                                                  //~vbCBI~
    PUFCMD pufc;                                                   //~vbCBR~
    char *pcmdW,*pcmdS1,*pcmdS2,*pcmdS;                            //~vbCBR~
//****************                                                 //~vbCBI~
    pufc=(PUFCMD)GfindcmdSplit[0];            //split              //~vbCBR~
    if (pufc)                                                      //~vbCBI~
    	pcmdS1=pufc->UFCuscmd.USCcmd;                              //~vbCBI~
    else                                                           //~vbCBI~
    	pcmdS1=NONE_SAVED;                                         //~vbCBI~
    pufc=(PUFCMD)GfindcmdSplit[1];            //split              //~vbCBR~
    if (pufc)                                                      //~vbCBI~
    	pcmdS2=pufc->UFCuscmd.USCcmd;                              //~vbCBI~
    else                                                           //~vbCBI~
    	pcmdS2=NONE_SAVED;                                         //~vbCBI~
    pufc=(PUFCMD)GfindcmdSplit[FCMD_SPLIT_INDEX_STD];  //std       //~vbCBR~
    if (pufc)                                                      //~vbCBI~
    	pcmdS=pufc->UFCuscmd.USCcmd;                               //~vbCBI~
    else                                                           //~vbCBI~
    	pcmdS=NONE_SAVED;                                          //~vbCBI~
    pufc=(PUFCMD)Ppcw->UCWfindcmd;                    //pcw        //~vbCBI~
    if (pufc)                                                      //~vbCBI~
    	pcmdW=pufc->UFCuscmd.USCcmd;                               //~vbCBI~
    else                                                           //~vbCBI~
    	pcmdW=NONE_SAVED;                                          //~vbCBI~
    uerrmsg("%s:%s; %s:%s; %s:%s; %s:%s",0,                        //~vbCBR~
				FCMDOPT_PS_FILE,pcmdW,                             //~vbCBR~
				FCMDOPT_PS_SPLIT "(1)",pcmdS1,                     //~vbCBI~
				FCMDOPT_PS_SPLIT "(2)",pcmdS2,                     //~vbCBR~
				FCMDOPT_PS_STD,pcmdS);                             //~vbCBI~
}//fcmddisplayPSall                                                //~vbCBI~
//**************************************************               //~vbCBM~
int fcmdexecutePS(PUCLIENTWE Ppcw,PUFCMD Ppufc)                    //~vbCBR~
{                                                                  //~vbCBM~
	int rc;                                                        //~vbCBI~
    PUSCMD psc;                                                    //~vbCBI~
//******************************                                   //~vbCBI~
    psc=&Ppufc->UFCuscmd;                                          //~vbCBI~
	UTRACEP("%s:pstype=%d,cmd=%s\n",UTT,Ppufc->UFCpstype,psc->USCcmd);//~vbCBR~
    ScontrolPS|=CPS_EXECUTE;                                       //~vbCBI~
	funccmdstack(psc->USCcmd,psc->USCcmdlen,psc->USCseqno);        //~vbCBR~
    rc=func_cmdrepeat(Ppcw);                                       //~vbCBI~
    return rc;                                                     //~vbCBR~
}//fcmdexecutePS                                                   //~vbCBM~
//**************************************************               //~vbCBI~
int fcmdrestorePScmdline(PUCLIENTWE Ppcw,PUFCMD Ppufc)             //~vbCBR~
{                                                                  //~vbCBI~
	int rc;                                                        //~vbCBI~
    PUSCMD psc;                                                    //~vbCBI~
//******************************                                   //~vbCBI~
    psc=&Ppufc->UFCuscmd;                                          //~vbCBI~
	UTRACEP("%s:cmd=%s\n",UTT,psc->USCcmd);                        //~vbCBR~
    rc=funcrestorePSC(Ppcw,psc);                                   //~vbCBR~
    return rc;                                                     //~vbCBI~
}//fcmdrestorePScmdline                                            //~vbCBI~
//***************************************************************************//~vbCBI~
int fcmdsetPSopdpos(PUCLIENTWE Ppcw,PUFCMD Ppufc,char *Pcmd,char *Popd,UPODELMTBL *Ppodt)//~vbCBI~
{                                                                  //~vbCBI~
	int pos=0,delmoffs;                                            //~vbCBI~
    char *pc;                                                      //~vbCBR~
//*******************************                                  //~vbCBI~
   	delmoffs=Ppodt->upodelmoffs;                                   //~vbCBI~
    pc=strchr(Pcmd,' ');                                           //~vbCBI~
    if (pc)                                                        //~vbCBI~
    {                                                              //~vbCBI~
    	pc+=strspn(pc," ");                                        //~vbCBR~
        pc=umemrstr(pc,Popd,(unsigned)delmoffs);                   //~vbCBR~
        if (pc)                                                    //~vbCBI~
        	pos=PTRDIFF(pc,Pcmd);                                  //~vbCBI~
    }                                                              //~vbCBI~
    if (pos)                                                       //~vbCBI~
    {                                                              //~vbCBI~
   		Ppufc->UFCopdpos=pos-1;    // prefix '-' or '/'            //~vbCBR~
   		Ppufc->UFCopdlen=(int)strlen(Popd)+1;                      //~vbCBR~
    }                                                              //~vbCBI~
	UTRACEP("%S:delmoffs=%d,pos=%d,opd=%s\n",UTT,delmoffs,pos,Pcmd+pos);//~vbCBR~
    return pos;                                                    //~vbCBI~
}//fcmdsetPSopdpos                                                 //~vbCBI~
//***************************************************************************//~vbCBI~
//*fcmdgetpufc                                                     //~vbCBI~
//***************************************************************************//~vbCBI~
PUFCMD fcmdcreatepufc(int Ppstype,PUSCMD Ppsc)                     //~vbCBI~
{                                                                  //~vbCBI~
	PUFCMD pufc;                                                   //~vbCBI~
    int len;                                                       //~vbCBI~
//******************                                               //~vbCBI~
    len=UFCMDSZ+Ppsc->USCcmdlenlc+Ppsc->USCcmdlen+1;               //~vbCBI~
    pufc=umalloc((size_t)len);                                     //~vbCBI~
    memset(pufc,0,(size_t)len);                                    //~vbCBI~
    len=USCMDSZ+Ppsc->USCcmdlenlc+Ppsc->USCcmdlen+1;               //~vbCBI~
    memcpy(&pufc->UFCuscmd,Ppsc,(size_t)len);                      //~vbCBI~
    pufc->UFCpstype=Ppstype;                                       //~vbCBI~
    return pufc;                                                   //~vbCBI~
}//fcmdcreatepufc                                                  //~vbCBI~
//***************************************************************************//~vbCBI~
//*save/restore global/local cmd                                   //~vbCBI~
//***************************************************************************//~vbCBI~
char *fcmdgetfindoptionPScmd(PUCLIENTWE Ppcw,int Ppstype,PUFCMD *Pppufc,char *Popd,UPODELMTBL* Ppodt)//~vbCBR~
{                                                                  //~vbCBM~
	PUFCMD *ppufc,pufc;                                            //~vbCBR~
	PUSCMD psc;                                                    //~vbCBI~
    int idx;                                                       //~vbCBR~
    char *pcmd=0;                                                  //~vbCBR~
//********************************                                 //~vbCBM~
	UTRACEP("%s:pstype=%d,ScontrolPS=%02x\n",UTT,Ppstype,ScontrolPS);//~vbCBR~
    if (Ppstype==FCMDOPT_PSTYPE_SPLIT) //1                         //~vbCBR~
    {                                                              //~vbCBI~
	    if (Ppcw->UCWsplitid)                                      //~vbCBI~
    	    idx=1;                                                 //~vbCBI~
    	else                                                       //~vbCBI~
        	idx=0;                                                 //~vbCBI~
        ppufc=(PUFCMD*)(&GfindcmdSplit[idx]);                      //~vbCBR~
    }                                                              //~vbCBI~
    else                                                           //~vbCBM~
    if (Ppstype==FCMDOPT_PSTYPE_FILE) //1                          //~vbCBR~
		ppufc=(PUFCMD*)(&Ppcw->UCWfindcmd);                        //~vbCBR~
    else    //STD                                                  //~vbCBI~
        ppufc=(PUFCMD*)(&GfindcmdSplit[FCMD_SPLIT_INDEX_STD]);     //~vbCBI~
    pufc=*ppufc;                                                   //~vbCBR~
    if (pufc)                                                      //~vbCBI~
    {                                                              //~vbCBI~
        psc=&pufc->UFCuscmd;                                       //~vbCBI~
        pcmd=psc->USCcmd;                                          //~vbCBI~
    }                                                              //~vbCBI~
    Sprevpstype=Ppstype;                                           //~vbCBI~
    if (ScontrolPS & CPS_EXECUTE) //entry by reenq cmd             //~vbCBI~
    {                                                              //~vbCBI~
		UTRACEP("%s:CPSEXECUTE\n",UTT);                            //~vbCBI~
    	ScontrolPS &= ~CPS_EXECUTE;                                //~vbCBI~
	}                                                              //~vbCBI~
    else                                                           //~vbCBI~
    if (Ppcw->UCWopdno>1 || Ppstype==FCMDOPT_PSTYPE_STD)	//save //~vbCBR~
    {                                                              //~vbCBM~
    	if (pufc)                                                  //~vbCBR~
    	{                                                          //~vbCBM~
        	ufree(pufc);                                           //~vbCBR~
    	}                                                          //~vbCBM~
		psc=UGETQTOP(&Gcmdstack);                                  //~vbCBM~
//      psc->USCflags[UFCFLAGS_PSTYPE]=Ppstype; //write to ini file to recover SPLIT and STD cmd//~vbCBR~
		pufc=fcmdcreatepufc(Ppstype,psc);                          //~vbCBI~
        psc=&pufc->UFCuscmd;                                       //~vbCBI~
		pcmd=psc->USCcmd;                                          //~vbCBI~
        *ppufc=pufc;                                               //~vbCBI~
        if (Ppstype!=FCMDOPT_PSTYPE_STD && Ppodt)                  //~vbCBR~
        	fcmdsetPSopdpos(Ppcw,pufc,pcmd,Popd,Ppodt);            //~vbCBR~
    }   	                                                       //~vbCBM~
    if (Pppufc)                                                    //~vbCBR~
    	*Pppufc=pufc;                                              //~vbCBR~
    return pcmd;                                                   //~vbCBI~
}//fcmdgetfindoptionPScmd                                          //~vbCBI~
//**************************************************               //~vbCBI~
//*rc:4 err,1:PSx option,0 not PSx option                          //~vbCBR~
//**************************************************               //~vbCBI~
int fcmdgetfindoptionPS(PUCLIENTWE Ppcw,char *Popd,UPODELMTBL* Ppodt)//~vbCBR~
{                                                                  //~vbCBI~
	int opdno,pstype=0,opt2,opt3;                                  //~vbCBR~
    char *pcmd=0,*popd;                                            //~vbCBR~
    PUFCMD pufc;                                                   //~vbCBR~
    PFUNCTBL pft;                                                  //~vbCBI~
//*************************                                        //~vbCBI~
	popd=Popd+1;                                                   //~vbCBI~
	opdno=Ppcw->UCWopdno;                                          //~vbCBI~
	if (USTRHEADIS_IC(popd,FCMDOPT_PS_SPLIT))                      //~vbCBR~
    	pstype=FCMDOPT_PSTYPE_SPLIT;    //1                        //~vbCBR~
    else                                                           //~vbCBI~
	if (USTRHEADIS_IC(popd,FCMDOPT_PS_FILE))                       //~vbCBR~
    	pstype=FCMDOPT_PSTYPE_FILE;    //2                         //~vbCBR~
    else                                                           //~vbCBI~
    {                                                              //~vbCBI~
    	return 0;	//not PSx operand                              //~vbCBR~
    }                                                              //~vbCBI~
	pft=(FUNCTBL*)(Ppcw->UCWpfunct);                               //~vbCBI~
	if (!(pft && (pft->FTflag2 & FTF2FIND_PSSUPP)))	//PSx operand support//~vbCBR~
		return errinvalid(Popd);                                   //~vbCBI~
    pcmd=fcmdgetfindoptionPScmd(Ppcw,pstype,&pufc,popd,Ppodt);  //restore(opdno=1) or save(opdno>1)//~vbCBR~
    opt2=toupper(*(popd+FCMDOPT_PS_OPT2POS));                      //~vbCBR~
    if (opt2)                                                      //~vbCBR~
    {                                                              //~vbCBI~
    	opt3=toupper(*(popd+FCMDOPT_PS_OPT2POS+1));                //~vbCBI~
        if (opt3)                                                  //~vbCBI~
			return errinvalid(Popd);                               //~vbCBI~
    }                                                              //~vbCBI~
    if (opt2==FCMDOPT_PS_DISPLAY_C) //display                      //~vbCBR~
    {                                                              //~vbCBM~
    	if (opdno>1)                                               //~vbCBM~
			return fcmderrPSotheropd(Ppcw,Popd);                   //~vbCBI~
		fcmddisplayPS(pstype,Ppcw,pcmd);                           //~vbCBI~
        return 4;                                                  //~vbCBI~
    }                                                              //~vbCBM~
                                                                   //~vbCBI~
    if (!pcmd)                                                     //~vbCBI~
		return fcmderrPSnotsaved(Ppcw,pstype);                     //~vbCBI~
    if (opt2==FCMDOPT_PS_EXECUTE_C) //execute now                  //~vbCBR~
    {                                                              //~vbCBI~
    	if (opdno>1)                                               //~vbCBR~
			return fcmderrPSotheropd(Ppcw,Popd);                   //~vbCBI~
        fcmdexecutePS(Ppcw,pufc);                                  //~vbCBR~
    }                                                              //~vbCBI~
    else                                                           //~vbCBI~
    if (opt2==FCMDOPT_PS_RETRIEVE_C) //execute now                 //~vbCBR~
    {                                                              //~vbCBI~
    	if (opdno>1)                                               //~vbCBI~
			return fcmderrPSotheropd(Ppcw,Popd);                   //~vbCBI~
	    fcmdrestorePScmdline(Ppcw,pufc);                           //~vbCBR~
        return 4;                                                  //~vbCBI~
    }                                                              //~vbCBI~
    else                                                           //~vbCBI~
    if (opt2!=0) //restore                                         //~vbCBR~
		return errinvalid(Popd);                                   //~vbCBM~
    if (opdno==1)                                                  //~vbCBI~
		return fcmderrPSNootheropd(Ppcw,Popd);                     //~vbCBI~
    return 1;                                                      //~vbCBM~
}//fcmdgetfindoptionPS                                             //~vbCBI~
//**************************************************               //~vbCBI~
//*save normal cmd                                                 //~vbCBI~
//**************************************************               //~vbCBI~
int fcmdgetfindoptionPSstd(PUCLIENTWE Ppcw)                        //~vbCBR~
{                                                                  //~vbCBI~
	int pstype=0;                                                  //~vbCBI~
//*************************                                        //~vbCBI~
	pstype=FCMDOPT_PSTYPE_STD;                                     //~vbCBR~
    fcmdgetfindoptionPScmd(Ppcw,pstype,0/*ppufc*/,0/*Popd*/,0/*ppodt*/);	//save even opdno==1//~vbCBR~
    return 0;                                                      //~vbCBI~
}//fcmdgetfindoptionPSstd                                          //~vbCBI~
//**************************************************               //~vbCBI~
void fcmd2term(void)                                               //~vbCBI~
{                                                                  //~vbCBI~
	int ii;                                                        //~vbCBI~
//*******************                                              //~vbCBI~
    for (ii=0;ii<(int)(sizeof(GfindcmdSplit)/sizeof(GfindcmdSplit[0]));ii++)//~vbCBI~
    	UFREEIFNZ(GfindcmdSplit[ii]);                              //~vbCBI~
}//fcmd2term                                                       //~vbCBR~
//**************************************************               //~vbCBI~
int fcmdrestoreforfindPS(int Popt,PUCLIENTWE Ppcw,PUFCMD Ppufc)    //~vbCBI~
{                                                                  //~vbCBI~
//*******************                                              //~vbCBI~
	UTRACEP("%S:oufc cmd=%s\n",UTT,Ppufc->UFCuscmd.USCcmd);        //~vbCBI~
    return 0;                                                      //~vbCBI~
}//fcmdrestoreforfindPS                                            //~vbCBI~
//**************************************************               //~vbCBI~
PUFCMD fcmdrgetpufcPStype(int Popt,int Ppstype,PUCLIENTWE Ppcw)    //~vbCBR~
{                                                                  //~vbCBI~
	int idx;                                                       //~vbCBR~
    PUFCMD pufc;                                                   //~vbCBR~
//*******************                                              //~vbCBI~
    if (Ppcw->UCWsplitid)                                          //~vbCBI~
        idx=1;                                                     //~vbCBI~
    else                                                           //~vbCBI~
        idx=0;                                                     //~vbCBI~
	if (Ppstype==FCMDOPT_PSTYPE_SPLIT)                             //~vbCBR~
        pufc=(PUFCMD)GfindcmdSplit[idx];            //split        //~vbCBI~
    else                                                           //~vbCBI~
	if (Ppstype==FCMDOPT_PSTYPE_FILE)                              //~vbCBR~
        pufc=(PUFCMD)Ppcw->UCWfindcmd;                    //pcw    //~vbCBI~
    else                                                           //~vbCBI~
        pufc=(PUFCMD)GfindcmdSplit[FCMD_SPLIT_INDEX_STD];          //~vbCBI~
    UTRACEP("%s:return Popt=%d,Ppstype=%d,cmd=%s\n",UTT,Popt,Ppstype,(pufc?(UCHAR*)(pufc->UFCuscmd.USCcmd):(UCHAR*)NONE_SAVED));//~vbCBR~
    return pufc;                                                   //~vbCBR~
}//fcmdrgetpufcPStype                                              //~vbCBI~
//**********************************************************************************//~vbCBR~
//*from fcmdfind,at before and after call fcmdfindsub              //~vbCBI~
//**********************************************************************************//~vbCBI~
int fcmdchkPS(int Popt,int Prc,PUCLIENTWE Ppcw,int Pcasesw,int Pchangeopt,int Pbackward,int Pnxopt)//~vbCBI~
{                                                                  //~vbCBI~
	int rc=0;                                                      //~vbCBR~
//*******************                                              //~vbCBI~
    UTRACEP("%s:opt=%x\n",UTT,Popt);                               //~vbCBI~
    return rc;                                                     //~vbCBI~
}//fcmdchkPS                                                       //~vbCBR~
//**************************************************               //~vbCBI~
int fcmdcallrfind(int Popt,PUCLIENTWE Ppcw,int Pdest,int Ppstype)  //~vbCBI~
{                                                                  //~vbCBI~
    int rc;                                                        //~vbCBI~
//*******************                                              //~vbCBI~
	UTRACEP("%s:opt=%02x,pstype=%d,dest=%d\n",UTT,Popt,Ppstype,Pdest);//~vbCBR~
    if (!(Popt & FCRFO_NEWOPD))                                    //~vbCBI~
    	Sprevpstype=Ppstype;                                       //~vbCBR~
	ScontrolPS |= CPS_CALLRFIND;                                   //~vbCBR~
	rc=fcmdrfind(Ppcw,Pdest,CMDFIND);                              //~vbCBI~
	ScontrolPS &= ~CPS_CALLRFIND;                                  //~vbCBR~
    return rc;                                                     //~vbCBI~
}//fcmdcallrfind                                                   //~vbCBI~
//**************************************************               //~vbCBI~
int fcmdsrchPSPPSF(int Popt,int Ppstype,PUCLIENTWE Ppcw,int Pdest) //~vbCBI~
{                                                                  //~vbCBI~
	int rc=0;                                                      //~vbCBR~
    PUFCMD pufc;                                                   //~vbCBI~
//*******************                                              //~vbCBI~
    UTRACEP("%s:opt=%x,dest=%d\n",UTT,Popt,Pdest);                 //~vbCBR~
    if (Ppcw->UCWparm) //new operand for C_F5/A_F5(rfind)          //~vbCBI~
    {                                                              //~vbCBI~
        UTRACEP("%s:PSx key with new operand=%s",UTT,Ppcw->UCWparm);//~vbCBI~
        rc=fcmdcallrfind(FCRFO_NEWOPD,Ppcw,Pdest,Ppstype);         //~vbCBI~
    }                                                              //~vbCBI~
    else	//no opd                                               //~vbCBI~
    {                                                              //~vbCBI~
        if (Ppstype==Sprevpstype)                                  //~vbCBR~
        {                                                          //~vbCBR~
            UTRACEP("%s:continued pstype=%d\n",UTT,Ppstype);       //~vbCBI~
        	rc=fcmdcallrfind(0,Ppcw,Pdest,Ppstype);                //~vbCBR~
        }                                                          //~vbCBR~
        else                                                       //~vbCBR~
        {                                                          //~vbCBR~
            pufc=fcmdrgetpufcPStype(0,Ppstype,Ppcw);               //~vbCBR~
            if (!pufc)                                             //~vbCBR~
                return fcmderrPSnotsaved(Ppcw,Ppstype);            //~vbCBR~
            UTRACEP("%s:Switch to pstype %d from %d,cmd=%s\n",UTT,Ppstype,Sprevpstype,pufc->UFCuscmd.USCcmd);               //continue with new opd//~vbCBR~
            pufc->UFCdest=Pdest;                                   //~vbCBR~
            fcmdexecutePS(Ppcw,pufc);                              //~vbCBR~
        }                                                          //~vbCBR~
    }//no operand                                                  //~vbCBI~
    return rc;                                                     //~vbCBI~
}//fcmdsrchPSPPSF                                                  //~vbCBR~
//**************************************************               //~vbCBI~
//*by A_F5                                                         //~vbCBI~
//**************************************************               //~vbCBI~
int fcmdsrchPSP(int Popt,PUCLIENTWE Ppcw,int Pdest,int Pchange)    //~vbCBR~
{                                                                  //~vbCBI~
	int rc;                                                        //~vbCBR~
//*******************                                              //~vbCBI~
    rc=fcmdsrchPSPPSF(Popt,FCMDOPT_PSTYPE_SPLIT,Ppcw,Pdest);       //~vbCBR~
    UTRACEP("%s:opt=%x,rc=%d\n",UTT,Popt,rc);                      //~vbCBI~
    return rc;                                                     //~vbCBI~
}//fcmdsrchPSP                                                     //~vbCBR~
//**************************************************               //~vbCBI~
//*by C_F5                                                         //~vbCBI~
//**************************************************               //~vbCBI~
int fcmdsrchPSF(int Popt,PUCLIENTWE Ppcw,int Pdest,int Pchange)    //~vbCBR~
{                                                                  //~vbCBI~
	int rc;                                                        //~vbCBR~
//*******************                                              //~vbCBI~
    rc=fcmdsrchPSPPSF(Popt,FCMDOPT_PSTYPE_FILE,Ppcw,Pdest);        //~vbCBR~
    UTRACEP("%s:opt=%x,rc=%d\n",UTT,Popt,rc);                      //~vbCBI~
    return rc;                                                     //~vbCBI~
}//fcmdsrchPSP                                                     //~vbCBR~
//******************************************************************************//~vbCBR~
//*from at top of fcmdrfind                                        //~vbCBR~
//*by   F5,rc=1:ENQed prev find cmd,rc=0 continue to process std rfind//~vbCBI~
//******************************************************************************//~vbCBR~
int fcmdsrchSTD(int Popt,PUCLIENTWE Ppcw,int Pdest,int Pchangeopt) //~vbCBI~
{                                                                  //~vbCBI~
    PUFCMD pufc;                                                   //~vbCBI~
    int rc=0;                                                      //~vbCBI~
//*******************                                              //~vbCBI~
    if (!(ScontrolPS & CPS_CALLRFIND))		//processing PS cmd,protect recursive//~vbCBR~
    {                                                              //~vbCBR~
	    if (Sprevpstype!=FCMDOPT_PSTYPE_STD)		//continued STD cmd//~vbCBR~
        {                                                          //~vbCBI~
		    Sprevpstype=FCMDOPT_PSTYPE_STD;		//set std mode     //~vbCBR~
            if (Ppcw->UCWparm) //new operand for F5-rfind          //~vbCBR~
            	UTRACEP("%s:Switch to STD,with new operand\n",UTT);				//continue with new opd//~vbCBI~
            else     //simple F5                                   //~vbCBI~
            {                                                      //~vbCBI~
                pufc=fcmdrgetpufcPStype(0,FCMDOPT_PSTYPE_STD,Ppcw);//~vbCBR~
                if (pufc)                                          //~vbCBR~
                {                                                  //~vbCBR~
	            	UTRACEP("%s:Switch to STD,restored prev STD cmd\n",UTT);				//continue with new opd//~vbCBI~
    				fcmdexecutePS(Ppcw,pufc);                      //~vbCBR~
                    rc=1;                                          //~vbCBR~
                }                                                  //~vbCBR~
            }                                                      //~vbCBI~
        }                                                          //~vbCBI~
    }                                                              //~vbCBI~
    UTRACEP("%s:opt=%x,rc=%d\n",UTT,Popt,rc);                      //~vbCBI~
    return rc;                                                     //~vbCBR~
}//fcmdsrchSTD                                                     //~vbCBR~
//******************************************************************************//~vbCBI~
//*from funcrcmdstackFindStackRecovery                             //~vbCBI~
//*rc 0:requuest next PSC, 1:recovery end                          //~vbCBI~
//******************************************************************************//~vbCBI~
int fcmdPSinit(int Popt,void* /*PUSCMD*/ Ppsc)                     //~vbCBR~
{                                                                  //~vbCBI~
	PFUNCTBL pft;                                                  //~vbCBI~
    PUFCMD pufc;                                                   //~vbCBI~
    PUSCMD psc;                                                    //~vbCBI~
    PUPODELMTBL pupod0;                                            //~vbCBI~
	UPODELMTBL odt;                                                //~vbCBI~
    int opdno,ii,len;                                              //~vbCBR~
    char wkcmd[sizeof(pft->FTcmd)];                                //~vbCBR~
	UCHAR *wkppot,*opd,*pcd,*pcmd;                                 //~vbCBR~
    UCHAR wkpot[MAXPARMSZ+1];                                      //~vbCBI~
	UCHAR wkdelmt[UPODELMTBLSZ*MAXPARMSZ];                         //~vbCBI~
    int swsplit=0,opt2;                                            //~vbCBR~
//*******************                                              //~vbCBI~
	psc=(PUSCMD)Ppsc;                                              //~vbCBI~
    pcmd=psc->USCcmd;                                              //~vbCBR~
	pcd=strpbrk(pcmd," ,");	//first opd delm pos                   //~vbCBI~
    if (pcd)                                                       //~vbCBI~
    	len=PTRDIFF(pcd,pcmd);                                     //~vbCBI~
	else                                                           //~vbCBI~
        len=(int)strlen(pcmd);                                     //~vbCBI~
    len=min(len,(int)sizeof(wkcmd)-1);                             //~vbCBR~
    UmemcpyZ(wkcmd,pcmd,(size_t)len);                              //~vbCBI~
	pft=functblsrchbycmd(wkcmd);                                   //~vbCBI~
    if (!pft)                                                      //~vbCBI~
    	return 0;                                                  //~vbCBI~
    if (!UCBITCHK(pft->FTflag2,FTF2FIND_PSSUPP))	//PSx support cmd,Find,IFind etc//~vbCBR~
    	return 0;                                                  //~vbCBI~
//*                                                                //~vbCBI~
	wkppot=wkpot;	//output is not malloc                         //~vbCBI~
	pupod0=(PUPODELMTBL)wkdelmt;                                   //~vbCBR~
    if (uparse2(pcmd,&pupod0,&wkppot,&opdno,UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,",;")>=4)	//umalloc failed//~vbCBI~
    	return 0;                                                  //~vbCBI~
    if (opdno<=1)      //verb only                                 //~vbCBR~
    	return 0;                                                  //~vbCBI~
	for (ii=0,opd=wkppot;ii<opdno;ii++,opd+=strlen(opd)+1)         //~vbCBR~
	{                                                              //~vbCBI~
    	odt=pupod0[ii];                                            //~vbCBI~
		if (!odt.upoquate		//not in quatation                 //~vbCBI~
#ifdef UNX                                                         //~vbCBI~
		&&  *opd=='-'                                              //~vbCBI~
#else                                                              //~vbCBI~
		&&  (*opd=='-'||*opd=='/')                                 //~vbCBI~
#endif                                                             //~vbCBI~
        &&  *(opd+1))     // "-" means "prev"                      //~vbCBI~
		{	//option flag                                          //~vbCBI~
			opd++;                                                 //~vbCBI~
    		if (USTRHEADIS_IC(opd,FCMDOPT_PS_FILE))                //~vbCBR~
            	return 0;	//recover STD only                     //~vbCBI~
			if (USTRHEADIS_IC(opd,FCMDOPT_PS_SPLIT))               //~vbCBI~
            {                                                      //~vbCBI~
    			if (opdno<=2)      //PSx opd only                  //~vbCBI~
    				return 0;                                      //~vbCBI~
    			opt2=toupper(*(opd+FCMDOPT_PS_OPT2POS));           //~vbCBI~
    			if (opt2)      //PSxD,PSxR,PSxX                    //~vbCBR~
			    	return 0;                                      //~vbCBI~
                swsplit=1;                                         //~vbCBM~
			    if (!GfindcmdSplit[0])                             //~vbCBI~
                {                                                  //~vbCBI~
					pufc=fcmdcreatepufc(FCMDOPT_PSTYPE_SPLIT,psc); //~vbCBR~
				    GfindcmdSplit[0]=pufc;                         //~vbCBR~
				    UTRACEP("%s:split(1) find=%s\n",UTT,psc->USCcmd);//~vbCBR~
                    break;                                         //~vbCBI~
                }                                                  //~vbCBI~
			    if (!GfindcmdSplit[1])                             //~vbCBI~
                {                                                  //~vbCBI~
					pufc=fcmdcreatepufc(FCMDOPT_PSTYPE_SPLIT,psc); //~vbCBR~
				    GfindcmdSplit[1]=pufc;                         //~vbCBR~
				    UTRACEP("%s:split(2) find=%s\n",UTT,psc->USCcmd);//~vbCBR~
                    break;                                         //~vbCBI~
                }                                                  //~vbCBI~
            }                                                      //~vbCBI~
        }                                                          //~vbCBI~
    }                                                              //~vbCBI~
    if (!swsplit)                                                  //~vbCBI~
    {                                                              //~vbCBI~
    	if (!GfindcmdSplit[FCMD_SPLIT_INDEX_STD])                  //~vbCBI~
        {                                                          //~vbCBI~
			pufc=fcmdcreatepufc(FCMDOPT_PSTYPE_STD,psc);           //~vbCBR~
    		GfindcmdSplit[FCMD_SPLIT_INDEX_STD]=pufc;              //~vbCBR~
	    	UTRACEP("%s:std find=%s\n",UTT,psc->USCcmd);           //~vbCBR~
        }                                                          //~vbCBI~
    }                                                              //~vbCBI~
	if (GfindcmdSplit[0]                                           //~vbCBI~
	&&  GfindcmdSplit[1]                                           //~vbCBI~
    &&  GfindcmdSplit[FCMD_SPLIT_INDEX_STD])                       //~vbCBI~
    {                                                              //~vbCBI~
    	UTRACEP("%s:std/split1/spli2 all found\n",UTT);            //~vbCBR~
	    return 1;  	//stop next entry                              //~vbCBI~
    }                                                              //~vbCBI~
    return 0;                                                      //~vbCBI~
}//fcmdPSinit                                                      //~vbCBR~
//************************************************************************//~vbc1I~
int finderr_notdirlist(char *Pvalue)                               //~vbc1I~
{                                                                  //~vbc1I~
	uerrmsg("%s is only for DirList",                              //~vbc1I~
            "%s パラメータはディレクトリーリスト用です",           //~vbc1R~
            Pvalue);                                               //~vbc1I~
    return 4;                                                      //~vbc1I~
}//finderr_notdirlist                                              //~vbc1I~
